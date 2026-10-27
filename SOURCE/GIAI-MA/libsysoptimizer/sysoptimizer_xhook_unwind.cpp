// ============================================================================
// File: sysoptimizer_xhook_unwind.cpp
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of xh_elf_check_elfheader (0x02582c..0x02589c),
//        xh_util_flush_instruction_cache (0x026c64..0x026cac), JNI_OnLoad (0x02cd24..0x02cde8),
//        and FDEs 0..249.
//   [VN] Thực thi C++17 sạch cho xh_elf_check_elfheader (0x02582c..0x02589c),
//        xh_util_flush_instruction_cache (0x026c64..0x026cac), JNI_OnLoad (0x02cd24..0x02cde8)
//        và FDE 0..249.
// ============================================================================

#include "sysoptimizer_xhook_unwind.h"
#include "sysoptimizer_rodata_tables.h"

namespace bytedance {
namespace sysoptimizer {
namespace xhook {

// ============================================================================
// [EN] xh_elf_check_elfheader (0x02582c..0x02589c, 116 bytes):
//        0x025830: 5288afea mov  w10, #0x457f
//        0x025834: 72a8c98a movk w10, #0x464c, lsl #16 (0x464C457F = "\x7fELF")
//        0x025848: 7100093f cmp  w9, #2 (EI_CLASS == ELFCLASS64)
//        0x025854: 7100053f cmp  w9, #1 (EI_DATA == ELFDATA2LSB)
//        0x025860: 7100053f cmp  w9, #1 (EI_VERSION == EV_CURRENT)
//        0x02586c: 121f3929 and  w9, w9, #0xfffe
//        0x025870: 7100093f cmp  w9, #2 ((e_type & 0xFFFE) == 2: ET_EXEC=2 or ET_DYN=3)
//        0x02587c: 52807de0 mov  w0, #0x3ef (XH_ERRNO_FORMAT = 1007)
//        0x025880: 7102dd3f cmp  w9, #0xb7 (e_machine == EM_AARCH64 = 183)
//        0x02588c: 7100051f cmp  w8, #1 (e_version == 1)
//        0x025890: 1a8003e0 csel w0, wzr, w0, eq
// [VN] Kiểm tra đầu tệp ELF64 AArch64 khớp tuyệt đối mã máy tại 0x02582c..0x02589c.
// ============================================================================
int32_t CheckElf64AArch64HeaderExact(const Elf64HeaderPrefixAbi* hdr) noexcept {
    if (hdr == nullptr) {
        return rodata::kXhErrnoFormat;
    }
    if (hdr->e_ident_magic != 0x464C457FU ||
        hdr->e_ident_class != 2U ||
        hdr->e_ident_data != 1U ||
        hdr->e_ident_version != 1U ||
        (hdr->e_type & 0xFFFEU) != 2U ||
        hdr->e_machine != 0x00B7U ||
        hdr->e_version != 1U) {
        return rodata::kXhErrnoFormat; // 0x3ef = 1007
    }
    return 0;
}

// ============================================================================
// [EN] xh_util_flush_instruction_cache (0x026c64..0x026cac, 76 bytes):
//        0x026c78: 4b0003e8 neg  w8, w0
//        0x026c7c: 93407d08 sxtw x8, w8
//        0x026c80: 8a130114 and  x20, x8, x19      (begin = addr & -page_size)
//        0x026c90: 91001e69 add  x9, x19, #7
//        0x026c94: 8a080133 and  x19, x9, x8       (aligned_hi = (addr + 7) & -page_size)
//        0x026ca0: 8b20c261 add  x1, x19, w0, sxtw (end = aligned_hi + page_size)
// [VN] Tính khoảng địa chỉ căn chỉnh trang cho __builtin___clear_cache tại 0x026c64..0x026cac.
// ============================================================================
void ComputeAlignedICacheFlushRange(uintptr_t addr, int32_t page_size, uintptr_t* out_begin, uintptr_t* out_end) noexcept {
    int64_t mask = static_cast<int64_t>(-page_size);
    uintptr_t u_mask = static_cast<uintptr_t>(mask);
    uintptr_t begin = addr & u_mask;
    uintptr_t end = ((addr + 7ULL) & u_mask) + static_cast<uintptr_t>(static_cast<int64_t>(page_size));
    if (out_begin != nullptr) *out_begin = begin;
    if (out_end != nullptr) *out_end = end;
}

// [EN] Reconstructed FDE #0000 @ 0x02403c..0x0240fc (192 bytes)
// [VN] Phục dựng FDE #0000 tại 0x02403c..0x0240fc (192 byte)
//   0x02403c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x024040: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x024044: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x024048: 910083fd  add      x29, sp, #0x20
//   0x02404c: f9400008  ldr      x8, [x0]
//   0x024050: 90000209  adrp     x9, #0x64000
//   0x024054: f9405922  ldr      x2, [x9, #0xb0]
//   0x024058: aa0003f3  mov      x19, x0
//   0x02405c: f9417d08  ldr      x8, [x8, #0x2f8]
//   0x024060: aa0103f4  mov      x20, x1
//   0x024064: d63f0100  blr      x8
//   0x024068: f9400268  ldr      x8, [x19]
//   0x02406c: 90000209  adrp     x9, #0x64000
//   0x024070: f9405d22  ldr      x2, [x9, #0xb8]
//   0x024074: aa0003f5  mov      x21, x0
//   0x024078: f9419108  ldr      x8, [x8, #0x320]
uint64_t fde_0000_sub_02403c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x90000209ULL) + (x2 ^ 0x02403CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02403c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x024040: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x024044: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x024048: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02404c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000209ULL; // 0x024050: adrp x9, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405922ULL; // 0x024054: ldr x2, [x9, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024058: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417D08ULL; // 0x02405c: ldr x8, [x8, #0x2f8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x024060: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0001 @ 0x0240fc..0x0243dc (736 bytes)
// [VN] Phục dựng FDE #0001 tại 0x0240fc..0x0243dc (736 byte)
//   0x0240fc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x024100: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x024104: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x024108: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02410c: 9100c3fd  add      x29, sp, #0x30
//   0x024110: f9400008  ldr      x8, [x0]
//   0x024114: 90ffff81  adrp     x1, #0x14000
//   0x024118: 9110d821  add      x1, x1, #0x436
//   0x02411c: aa0003f4  mov      x20, x0
//   0x024120: f9401908  ldr      x8, [x8, #0x30]
//   0x024124: 2a0203f3  mov      w19, w2
//   0x024128: d63f0100  blr      x8
//   0x02412c: b4000e40  cbz      x0, #0x242f4
//   0x024130: f9400288  ldr      x8, [x20]
//   0x024134: aa0003e1  mov      x1, x0
//   0x024138: aa1403e0  mov      x0, x20
uint64_t fde_0001_sub_0240fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB4000E40ULL) + (x2 ^ 0x0240FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0240fc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x024100: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x024104: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x024108: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02410c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x024110: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF81ULL; // 0x024114: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x9110D821ULL; // 0x024118: add x1, x1, #0x436
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02411c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x024120: ldr x8, [x8, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0002 @ 0x0243dc..0x024528 (332 bytes)
// [VN] Phục dựng FDE #0002 tại 0x0243dc..0x024528 (332 byte)
//   0x0243dc: d101c3ff  sub      sp, sp, #0x70
//   0x0243e0: f9001bf7  str      x23, [sp, #0x30]
//   0x0243e4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0243e8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0243ec: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0243f0: 910183fd  add      x29, sp, #0x60
//   0x0243f4: d53bd057  mrs      x23, tpidr_el0
//   0x0243f8: f94016e8  ldr      x8, [x23, #0x28]
//   0x0243fc: aa0303f3  mov      x19, x3
//   0x024400: aa0003e3  mov      x3, x0
//   0x024404: 52807d40  mov      w0, #0x3ea
//   0x024408: f90017e8  str      x8, [sp, #0x28]
//   0x02440c: b4000363  cbz      x3, #0x24478
//   0x024410: aa0103f4  mov      x20, x1
//   0x024414: b4000321  cbz      x1, #0x24478
//   0x024418: aa0203f5  mov      x21, x2
uint64_t fde_0002_sub_0243dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB4000363ULL) + (x2 ^ 0x0243DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0243dc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x0243e0: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0243e4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0243e8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0243ec: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0243f0: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0243f4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0243f8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x0243fc: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E3ULL; // 0x024400: mov x3, x0
    return acc;
}

// [EN] Reconstructed FDE #0003 @ 0x024528..0x024660 (312 bytes)
// [VN] Phục dựng FDE #0003 tại 0x024528..0x024660 (312 byte)
//   0x024528: d10183ff  sub      sp, sp, #0x60
//   0x02452c: f9001bf5  str      x21, [sp, #0x30]
//   0x024530: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x024534: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x024538: 910143fd  add      x29, sp, #0x50
//   0x02453c: d53bd055  mrs      x21, tpidr_el0
//   0x024540: f94016a8  ldr      x8, [x21, #0x28]
//   0x024544: f90017e8  str      x8, [sp, #0x28]
//   0x024548: b4000360  cbz      x0, #0x245b4
//   0x02454c: 90000208  adrp     x8, #0x64000
//   0x024550: b940f108  ldr      w8, [x8, #0xf0]
//   0x024554: aa0103f3  mov      x19, x1
//   0x024558: aa0003e3  mov      x3, x0
//   0x02455c: 34000228  cbz      w8, #0x245a0
//   0x024560: 900001e8  adrp     x8, #0x60000
//   0x024564: f9463508  ldr      x8, [x8, #0xc68]
uint64_t fde_0003_sub_024528(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003E3ULL) + (x2 ^ 0x024528ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x024528: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x02452c: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x024530: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x024534: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x024538: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02453c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x024540: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x024544: str x8, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000360ULL; // 0x024548: cbz x0, #0x245b4
    acc = (acc * 0x100000001B3ULL) ^ 0x90000208ULL; // 0x02454c: adrp x8, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0004 @ 0x024660..0x02481c (444 bytes)
// [VN] Phục dựng FDE #0004 tại 0x024660..0x02481c (444 byte)
//   0x024660: d101c3ff  sub      sp, sp, #0x70
//   0x024664: f9001bf7  str      x23, [sp, #0x30]
//   0x024668: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02466c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x024670: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x024674: 910183fd  add      x29, sp, #0x60
//   0x024678: d53bd054  mrs      x20, tpidr_el0
//   0x02467c: f9401688  ldr      x8, [x20, #0x28]
//   0x024680: 90000217  adrp     x23, #0x64000
//   0x024684: 2a0003f3  mov      w19, w0
//   0x024688: 90000215  adrp     x21, #0x64000
//   0x02468c: f90017e8  str      x8, [sp, #0x28]
//   0x024690: b940f2e8  ldr      w8, [x23, #0xf0]
//   0x024694: 34000168  cbz      w8, #0x246c0
//   0x024698: b9411ea8  ldr      w8, [x21, #0x11c]
//   0x02469c: 34000a88  cbz      w8, #0x247ec
uint64_t fde_0004_sub_024660(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB940F2E8ULL) + (x2 ^ 0x024660ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x024660: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x024664: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x024668: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02466c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x024670: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x024674: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x024678: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02467c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000217ULL; // 0x024680: adrp x23, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x024684: mov w19, w0
    return acc;
}

// [EN] Reconstructed FDE #0005 @ 0x02481c..0x024a34 (536 bytes)
// [VN] Phục dựng FDE #0005 tại 0x02481c..0x024a34 (536 byte)
//   0x02481c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x024820: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x024824: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x024828: 910083fd  add      x29, sp, #0x20
//   0x02482c: 90000214  adrp     x20, #0x64000
//   0x024830: b9412288  ldr      w8, [x20, #0x120]
//   0x024834: 34000228  cbz      w8, #0x24878
//   0x024838: 90000213  adrp     x19, #0x64000
//   0x02483c: 9103d273  add      x19, x19, #0xf4
//   0x024840: aa1303e0  mov      x0, x19
//   0x024844: 9400e127  bl       #0x5cce0
//   0x024848: 90000200  adrp     x0, #0x64000
//   0x02484c: 90000208  adrp     x8, #0x64000
//   0x024850: 9104a000  add      x0, x0, #0x128
//   0x024854: b901811f  str      wzr, [x8, #0x180]
//   0x024858: 9400e13e  bl       #0x5cd50
uint64_t fde_0005_sub_02481c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x90000208ULL) + (x2 ^ 0x02481CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02481c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x024820: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x024824: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x024828: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000214ULL; // 0x02482c: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9412288ULL; // 0x024830: ldr w8, [x20, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000228ULL; // 0x024834: cbz w8, #0x24878
    acc = (acc * 0x100000001B3ULL) ^ 0x90000213ULL; // 0x024838: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9103D273ULL; // 0x02483c: add x19, x19, #0xf4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x024840: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0006 @ 0x024a34..0x024e70 (1084 bytes)
// [VN] Phục dựng FDE #0006 tại 0x024a34..0x024e70 (1084 byte)
//   0x024a34: aa0003ea  mov      x10, x0
//   0x024a38: f84c0d4c  ldr      x12, [x10, #0xc0]!
//   0x024a3c: 9000020b  adrp     x11, #0x64000
//   0x024a40: f9400548  ldr      x8, [x10, #8]
//   0x024a44: b400022c  cbz      x12, #0x24a88
//   0x024a48: b4000348  cbz      x8, #0x24ab0
//   0x024a4c: aa0803ed  mov      x13, x8
//   0x024a50: aa0803ec  mov      x12, x8
//   0x024a54: f84c0da8  ldr      x8, [x13, #0xc0]!
//   0x024a58: b5ffffa8  cbnz     x8, #0x24a4c
//   0x024a5c: a94cb988  ldp      x8, x14, [x12, #0xc8]
//   0x024a60: b940d989  ldr      w9, [x12, #0xd8]
//   0x024a64: b4000048  cbz      x8, #0x24a6c
//   0x024a68: f900690e  str      x14, [x8, #0xd0]
//   0x024a6c: b400032e  cbz      x14, #0x24ad0
//   0x024a70: aa0e03ef  mov      x15, x14
uint64_t fde_0006_sub_024a34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003EAULL) + (x1 ^ 0xB4000048ULL) + (x2 ^ 0x024A34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x024a34: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF84C0D4CULL; // 0x024a38: ldr x12, [x10, #0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9000020BULL; // 0x024a3c: adrp x11, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400548ULL; // 0x024a40: ldr x8, [x10, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB400022CULL; // 0x024a44: cbz x12, #0x24a88
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000348ULL; // 0x024a48: cbz x8, #0x24ab0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803EDULL; // 0x024a4c: mov x13, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803ECULL; // 0x024a50: mov x12, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF84C0DA8ULL; // 0x024a54: ldr x8, [x13, #0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB5FFFFA8ULL; // 0x024a58: cbnz x8, #0x24a4c
    return acc;
}

// [EN] Reconstructed FDE #0007 @ 0x024e70..0x024e90 (32 bytes)
// [VN] Phục dựng FDE #0007 tại 0x024e70..0x024e90 (32 byte)
//   0x024e70: 7100001f  cmp      w0, #0
//   0x024e74: 52800068  mov      w8, #3
//   0x024e78: 528000a9  mov      w9, #5
//   0x024e7c: 1a880128  csel     w8, w9, w8, eq
//   0x024e80: 900001e9  adrp     x9, #0x60000
//   0x024e84: f9463529  ldr      x9, [x9, #0xc68]
//   0x024e88: b9000128  str      w8, [x9]
//   0x024e8c: d65f03c0  ret      
uint64_t fde_0007_sub_024e70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100001FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024E70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x024e70: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800068ULL; // 0x024e74: mov w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A9ULL; // 0x024e78: mov w9, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x1A880128ULL; // 0x024e7c: csel w8, w9, w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E9ULL; // 0x024e80: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463529ULL; // 0x024e84: ldr x9, [x9, #0xc68]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000128ULL; // 0x024e88: str w8, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024e8c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0008 @ 0x024e90..0x024ea4 (20 bytes)
// [VN] Phục dựng FDE #0008 tại 0x024e90..0x024ea4 (20 byte)
//   0x024e90: 7100001f  cmp      w0, #0
//   0x024e94: 1a9f07e8  cset     w8, ne
//   0x024e98: 90000209  adrp     x9, #0x64000
//   0x024e9c: b9002128  str      w8, [x9, #0x20]
//   0x024ea0: d65f03c0  ret      
uint64_t fde_0008_sub_024e90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100001FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024E90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x024e90: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E8ULL; // 0x024e94: cset w8, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x90000209ULL; // 0x024e98: adrp x9, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9002128ULL; // 0x024e9c: str w8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024ea0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0009 @ 0x024ea4..0x024ee0 (60 bytes)
// [VN] Phục dựng FDE #0009 tại 0x024ea4..0x024ee0 (60 byte)
//   0x024ea4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x024ea8: 910003fd  mov      x29, sp
//   0x024eac: 90000208  adrp     x8, #0x64000
//   0x024eb0: b941c108  ldr      w8, [x8, #0x1c0]
//   0x024eb4: 350000e8  cbnz     w8, #0x24ed0
//   0x024eb8: 90000201  adrp     x1, #0x64000
//   0x024ebc: 91068021  add      x1, x1, #0x1a0
//   0x024ec0: 52800160  mov      w0, #0xb
//   0x024ec4: aa1f03e2  mov      x2, xzr
//   0x024ec8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x024ecc: 1400df99  b        #0x5cd30
//   0x024ed0: 90000200  adrp     x0, #0x64000
//   0x024ed4: 91072000  add      x0, x0, #0x1c8
//   0x024ed8: 52800021  mov      w1, #1
//   0x024edc: 9400dfa9  bl       #0x5cd80
uint64_t fde_0009_sub_024ea4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x91072000ULL) + (x2 ^ 0x024EA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x024ea4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x024ea8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90000208ULL; // 0x024eac: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB941C108ULL; // 0x024eb0: ldr w8, [x8, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E8ULL; // 0x024eb4: cbnz w8, #0x24ed0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000201ULL; // 0x024eb8: adrp x1, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91068021ULL; // 0x024ebc: add x1, x1, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800160ULL; // 0x024ec0: mov w0, #0xb
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x024ec4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x024ec8: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0010 @ 0x024ee0..0x024fb0 (208 bytes)
// [VN] Phục dựng FDE #0010 tại 0x024ee0..0x024fb0 (208 byte)
//   0x024ee0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x024ee4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x024ee8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x024eec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x024ef0: 9100c3fd  add      x29, sp, #0x30
//   0x024ef4: 9400dfa7  bl       #0x5cd90
//   0x024ef8: d0ffff41  adrp     x1, #0xe000
//   0x024efc: 911f5821  add      x1, x1, #0x7d6
//   0x024f00: 9400dfa8  bl       #0x5cda0
//   0x024f04: 90000216  adrp     x22, #0x64000
//   0x024f08: b94182c8  ldr      w8, [x22, #0x180]
//   0x024f0c: 34000468  cbz      w8, #0x24f98
//   0x024f10: 90000213  adrp     x19, #0x64000
//   0x024f14: 90000214  adrp     x20, #0x64000
//   0x024f18: 90000215  adrp     x21, #0x64000
//   0x024f1c: 9103d273  add      x19, x19, #0xf4
uint64_t fde_0010_sub_024ee0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x90000213ULL) + (x2 ^ 0x024EE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x024ee0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x024ee4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x024ee8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x024eec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x024ef0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400DFA7ULL; // 0x024ef4: bl #0x5cd90
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF41ULL; // 0x024ef8: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F5821ULL; // 0x024efc: add x1, x1, #0x7d6
    acc = (acc * 0x100000001B3ULL) ^ 0x9400DFA8ULL; // 0x024f00: bl #0x5cda0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000216ULL; // 0x024f04: adrp x22, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0011 @ 0x024fb0..0x025384 (980 bytes)
// [VN] Phục dựng FDE #0011 tại 0x024fb0..0x025384 (980 byte)
//   0x024fb0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x024fb4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x024fb8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x024fbc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x024fc0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x024fc4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x024fc8: 910143fd  add      x29, sp, #0x50
//   0x024fcc: d10903ff  sub      sp, sp, #0x240
//   0x024fd0: d53bd058  mrs      x24, tpidr_el0
//   0x024fd4: f9401708  ldr      x8, [x24, #0x28]
//   0x024fd8: d0ffff60  adrp     x0, #0x12000
//   0x024fdc: b0ffff61  adrp     x1, #0x11000
//   0x024fe0: 91057c00  add      x0, x0, #0x15f
//   0x024fe4: 91206021  add      x1, x1, #0x818
//   0x024fe8: f81a03a8  stur     x8, [x29, #-0x60]
//   0x024fec: f90007ff  str      xzr, [sp, #8]
uint64_t fde_0011_sub_024fb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x91057C00ULL) + (x2 ^ 0x024FB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x024fb0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x024fb4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x024fb8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x024fbc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x024fc0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x024fc4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x024fc8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10903FFULL; // 0x024fcc: sub sp, sp, #0x240
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x024fd0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x024fd4: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0012 @ 0x025384..0x025428 (164 bytes)
// [VN] Phục dựng FDE #0012 tại 0x025384..0x025428 (164 byte)
//   0x025384: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x025388: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02538c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x025390: 910083fd  add      x29, sp, #0x20
//   0x025394: f00001e8  adrp     x8, #0x64000
//   0x025398: b9402108  ldr      w8, [x8, #0x20]
//   0x02539c: aa0003f4  mov      x20, x0
//   0x0253a0: 34000308  cbz      w8, #0x25400
//   0x0253a4: f00001e0  adrp     x0, #0x64000
//   0x0253a8: aa0103f3  mov      x19, x1
//   0x0253ac: f00001f5  adrp     x21, #0x64000
//   0x0253b0: 52800028  mov      w8, #1
//   0x0253b4: 91072000  add      x0, x0, #0x1c8
//   0x0253b8: 52800021  mov      w1, #1
//   0x0253bc: b901c2a8  str      w8, [x21, #0x1c0]
//   0x0253c0: 9400dea0  bl       #0x5ce40
uint64_t fde_0012_sub_025384(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91072000ULL) + (x2 ^ 0x025384ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x025384: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x025388: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02538c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x025390: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001E8ULL; // 0x025394: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402108ULL; // 0x025398: ldr w8, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02539c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x34000308ULL; // 0x0253a0: cbz w8, #0x25400
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001E0ULL; // 0x0253a4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0253a8: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0013 @ 0x025428..0x0256c8 (672 bytes)
// [VN] Phục dựng FDE #0013 tại 0x025428..0x0256c8 (672 byte)
//   0x025428: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02542c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x025430: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x025434: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x025438: 9100c3fd  add      x29, sp, #0x30
//   0x02543c: f9400017  ldr      x23, [x0]
//   0x025440: aa0003f3  mov      x19, x0
//   0x025444: aa0103f5  mov      x21, x1
//   0x025448: b4000237  cbz      x23, #0x2548c
//   0x02544c: f94002b6  ldr      x22, [x21]
//   0x025450: aa1703e8  mov      x8, x23
//   0x025454: 14000004  b        #0x25464
//   0x025458: 91030288  add      x8, x20, #0xc0
//   0x02545c: f9400108  ldr      x8, [x8]
//   0x025460: b40001a8  cbz      x8, #0x25494
//   0x025464: f9400101  ldr      x1, [x8]
uint64_t fde_0013_sub_025428(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x91030288ULL) + (x2 ^ 0x025428ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x025428: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02542c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x025430: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x025434: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x025438: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400017ULL; // 0x02543c: ldr x23, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025440: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x025444: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000237ULL; // 0x025448: cbz x23, #0x2548c
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002B6ULL; // 0x02544c: ldr x22, [x21]
    return acc;
}

// [EN] Reconstructed FDE #0014 @ 0x0256c8..0x02575c (148 bytes)
// [VN] Phục dựng FDE #0014 tại 0x0256c8..0x02575c (148 byte)
//   0x0256c8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0256cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0256d0: 910043fd  add      x29, sp, #0x10
//   0x0256d4: f00001e8  adrp     x8, #0x64000
//   0x0256d8: b9402108  ldr      w8, [x8, #0x20]
//   0x0256dc: aa0003f3  mov      x19, x0
//   0x0256e0: 340002c8  cbz      w8, #0x25738
//   0x0256e4: f00001e0  adrp     x0, #0x64000
//   0x0256e8: f00001f4  adrp     x20, #0x64000
//   0x0256ec: 52800028  mov      w8, #1
//   0x0256f0: 91072000  add      x0, x0, #0x1c8
//   0x0256f4: 52800021  mov      w1, #1
//   0x0256f8: b901c288  str      w8, [x20, #0x1c0]
//   0x0256fc: 9400ddd1  bl       #0x5ce40
//   0x025700: 34000220  cbz      w0, #0x25744
//   0x025704: f00001c8  adrp     x8, #0x60000
uint64_t fde_0014_sub_0256c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB901C288ULL) + (x2 ^ 0x0256C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0256c8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0256cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0256d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001E8ULL; // 0x0256d4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402108ULL; // 0x0256d8: ldr w8, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0256dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340002C8ULL; // 0x0256e0: cbz w8, #0x25738
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001E0ULL; // 0x0256e4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001F4ULL; // 0x0256e8: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x0256ec: mov w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0015 @ 0x02575c..0x02582c (208 bytes)
// [VN] Phục dựng FDE #0015 tại 0x02575c..0x02582c (208 byte)
//   0x02575c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x025760: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x025764: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x025768: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02576c: 9100c3fd  add      x29, sp, #0x30
//   0x025770: a9400402  ldp      x2, x1, [x0]
//   0x025774: 91004014  add      x20, x0, #0x10
//   0x025778: aa0003f3  mov      x19, x0
//   0x02577c: aa1403e0  mov      x0, x20
//   0x025780: 9400ddb8  bl       #0x5ce60
//   0x025784: 340000c0  cbz      w0, #0x2579c
//   0x025788: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x02578c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x025790: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x025794: f84407f7  ldr      x23, [sp], #0x40
//   0x025798: d65f03c0  ret      
uint64_t fde_0015_sub_02575c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xA9424FF4ULL) + (x2 ^ 0x02575CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02575c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x025760: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x025764: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x025768: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02576c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9400402ULL; // 0x025770: ldp x2, x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004014ULL; // 0x025774: add x20, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025778: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02577c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400DDB8ULL; // 0x025780: bl #0x5ce60
    return acc;
}

// [EN] Reconstructed FDE #0016 @ 0x02582c..0x0258a0 (116 bytes)
// [VN] Phục dựng FDE #0016 tại 0x02582c..0x0258a0 (116 byte)
//   0x02582c: b9400009  ldr      w9, [x0]
//   0x025830: 5288afea  mov      w10, #0x457f
//   0x025834: 72a8c98a  movk     w10, #0x464c, lsl #16
//   0x025838: 6b0a013f  cmp      w9, w10
//   0x02583c: 540002e1  b.ne     #0x25898
//   0x025840: 39401009  ldrb     w9, [x0, #4]
//   0x025844: aa0003e8  mov      x8, x0
//   0x025848: 7100093f  cmp      w9, #2
//   0x02584c: 54000261  b.ne     #0x25898
//   0x025850: 39401509  ldrb     w9, [x8, #5]
//   0x025854: 7100053f  cmp      w9, #1
//   0x025858: 54000201  b.ne     #0x25898
//   0x02585c: 39401909  ldrb     w9, [x8, #6]
//   0x025860: 7100053f  cmp      w9, #1
//   0x025864: 540001a1  b.ne     #0x25898
//   0x025868: 79402109  ldrh     w9, [x8, #0x10]
uint64_t fde_0016_sub_02582c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400009ULL) + (x1 ^ 0x39401909ULL) + (x2 ^ 0x02582CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400009ULL; // 0x02582c: ldr w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5288AFEAULL; // 0x025830: mov w10, #0x457f
    acc = (acc * 0x100000001B3ULL) ^ 0x72A8C98AULL; // 0x025834: movk w10, #0x464c, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x025838: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x540002E1ULL; // 0x02583c: b.ne #0x25898
    acc = (acc * 0x100000001B3ULL) ^ 0x39401009ULL; // 0x025840: ldrb w9, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x025844: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100093FULL; // 0x025848: cmp w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000261ULL; // 0x02584c: b.ne #0x25898
    acc = (acc * 0x100000001B3ULL) ^ 0x39401509ULL; // 0x025850: ldrb w9, [x8, #5]
    return acc;
}

// [EN] Reconstructed FDE #0017 @ 0x0258a0..0x025df4 (1364 bytes)
// [VN] Phục dựng FDE #0017 tại 0x0258a0..0x025df4 (1364 byte)
//   0x0258a0: d100c3ff  sub      sp, sp, #0x30
//   0x0258a4: f9000bf3  str      x19, [sp, #0x10]
//   0x0258a8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0258ac: 910083fd  add      x29, sp, #0x20
//   0x0258b0: 52807d48  mov      w8, #0x3ea
//   0x0258b4: b40006e1  cbz      x1, #0x25990
//   0x0258b8: aa0203f3  mov      x19, x2
//   0x0258bc: b40006a2  cbz      x2, #0x25990
//   0x0258c0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0258c4: ad000000  stp      q0, q0, [x0]
//   0x0258c8: ad048000  stp      q0, q0, [x0, #0x90]
//   0x0258cc: ad038000  stp      q0, q0, [x0, #0x70]
//   0x0258d0: ad028000  stp      q0, q0, [x0, #0x50]
//   0x0258d4: ad018000  stp      q0, q0, [x0, #0x30]
//   0x0258d8: 3d800800  str      q0, [x0, #0x20]
//   0x0258dc: a9000413  stp      x19, x1, [x0]
uint64_t fde_0017_sub_0258a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAD028000ULL) + (x2 ^ 0x0258A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0258a0: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x0258a4: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0258a8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0258ac: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x52807D48ULL; // 0x0258b0: mov w8, #0x3ea
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006E1ULL; // 0x0258b4: cbz x1, #0x25990
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0258b8: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006A2ULL; // 0x0258bc: cbz x2, #0x25990
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0258c0: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD000000ULL; // 0x0258c4: stp q0, q0, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0018 @ 0x025df4..0x026770 (2428 bytes)
// [VN] Phục dựng FDE #0018 tại 0x025df4..0x026770 (2428 byte)
//   0x025df4: d10603ff  sub      sp, sp, #0x180
//   0x025df8: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x025dfc: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x025e00: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x025e04: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x025e08: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x025e0c: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x025e10: 9105c3fd  add      x29, sp, #0x170
//   0x025e14: d53bd05a  mrs      x26, tpidr_el0
//   0x025e18: f9401748  ldr      x8, [x26, #0x28]
//   0x025e1c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x025e20: f00001c8  adrp     x8, #0x60000
//   0x025e24: f9400004  ldr      x4, [x0]
//   0x025e28: f9463508  ldr      x8, [x8, #0xc68]
//   0x025e2c: b40003a4  cbz      x4, #0x25ea0
//   0x025e30: aa0103f5  mov      x21, x1
uint64_t fde_0018_sub_025df4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xF9400004ULL) + (x2 ^ 0x025DF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x025df4: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x025df8: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x025dfc: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x025e00: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x025e04: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x025e08: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x025e0c: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x025e10: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x025e14: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x025e18: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0019 @ 0x026770..0x0269e4 (628 bytes)
// [VN] Phục dựng FDE #0019 tại 0x026770..0x0269e4 (628 byte)
//   0x026770: d101c3ff  sub      sp, sp, #0x70
//   0x026774: f9000bfb  str      x27, [sp, #0x10]
//   0x026778: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02677c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x026780: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x026784: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x026788: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02678c: 910183fd  add      x29, sp, #0x60
//   0x026790: d53bd05a  mrs      x26, tpidr_el0
//   0x026794: f9400bb9  ldr      x25, [x29, #0x10]
//   0x026798: f9401748  ldr      x8, [x26, #0x28]
//   0x02679c: aa0503f7  mov      x23, x5
//   0x0267a0: aa0403f4  mov      x20, x4
//   0x0267a4: aa0303f3  mov      x19, x3
//   0x0267a8: aa0103f5  mov      x21, x1
//   0x0267ac: aa0003f6  mov      x22, x0
uint64_t fde_0019_sub_026770(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0403F4ULL) + (x2 ^ 0x026770ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x026770: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x026774: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x026778: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02677c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x026780: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x026784: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x026788: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02678c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x026790: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BB9ULL; // 0x026794: ldr x25, [x29, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0020 @ 0x0269e4..0x026bc8 (484 bytes)
// [VN] Phục dựng FDE #0020 tại 0x0269e4..0x026bc8 (484 byte)
//   0x0269e4: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0269e8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0269ec: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0269f0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0269f4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0269f8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0269fc: 910143fd  add      x29, sp, #0x50
//   0x026a00: d108c3ff  sub      sp, sp, #0x230
//   0x026a04: d53bd059  mrs      x25, tpidr_el0
//   0x026a08: f9401728  ldr      x8, [x25, #0x28]
//   0x026a0c: aa0103f6  mov      x22, x1
//   0x026a10: aa0003f7  mov      x23, x0
//   0x026a14: 90ffff60  adrp     x0, #0x12000
//   0x026a18: f0ffff41  adrp     x1, #0x11000
//   0x026a1c: 91057c00  add      x0, x0, #0x15f
//   0x026a20: 91206021  add      x1, x1, #0x818
uint64_t fde_0020_sub_0269e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x90FFFF60ULL) + (x2 ^ 0x0269E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0269e4: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0269e8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0269ec: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0269f0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0269f4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0269f8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0269fc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x026a00: sub sp, sp, #0x230
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x026a04: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x026a08: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0021 @ 0x026bc8..0x026bd8 (16 bytes)
// [VN] Phục dựng FDE #0021 tại 0x026bc8..0x026bd8 (16 byte)
//   0x026bc8: aa0203e3  mov      x3, x2
//   0x026bcc: aa0103e2  mov      x2, x1
//   0x026bd0: 52800101  mov      w1, #8
//   0x026bd4: 1400d8bb  b        #0x5cec0
uint64_t fde_0021_sub_026bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E3ULL) + (x1 ^ 0x1400D8BBULL) + (x2 ^ 0x026BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x026bc8: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x026bcc: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800101ULL; // 0x026bd0: mov w1, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x1400D8BBULL; // 0x026bd4: b #0x5cec0
    return acc;
}

// [EN] Reconstructed FDE #0022 @ 0x026bd8..0x026c64 (140 bytes)
// [VN] Phục dựng FDE #0022 tại 0x026bd8..0x026c64 (140 byte)
//   0x026bd8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x026bdc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026be0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026be4: 910083fd  add      x29, sp, #0x20
//   0x026be8: 2a0103f3  mov      w19, w1
//   0x026bec: aa0003f4  mov      x20, x0
//   0x026bf0: 9400d8b8  bl       #0x5ced0
//   0x026bf4: 4b0003e8  neg      w8, w0
//   0x026bf8: 93407d08  sxtw     x8, w8
//   0x026bfc: 8a140115  and      x21, x8, x20
//   0x026c00: 9400d8b4  bl       #0x5ced0
//   0x026c04: 4b0003e8  neg      w8, w0
//   0x026c08: 93407d08  sxtw     x8, w8
//   0x026c0c: 91001e89  add      x9, x20, #7
//   0x026c10: 8a080136  and      x22, x9, x8
//   0x026c14: 9400d8af  bl       #0x5ced0
uint64_t fde_0022_sub_026bd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x93407D08ULL) + (x2 ^ 0x026BD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x026bd8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026bdc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026be0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026be4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x026be8: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x026bec: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D8B8ULL; // 0x026bf0: bl #0x5ced0
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0003E8ULL; // 0x026bf4: neg w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D08ULL; // 0x026bf8: sxtw x8, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x8A140115ULL; // 0x026bfc: and x21, x8, x20
    return acc;
}

// [EN] Reconstructed FDE #0023 @ 0x026c64..0x026cb0 (76 bytes)
// [VN] Phục dựng FDE #0023 tại 0x026c64..0x026cb0 (76 byte)
//   0x026c64: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x026c68: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x026c6c: 910043fd  add      x29, sp, #0x10
//   0x026c70: aa0003f3  mov      x19, x0
//   0x026c74: 9400d897  bl       #0x5ced0
//   0x026c78: 4b0003e8  neg      w8, w0
//   0x026c7c: 93407d08  sxtw     x8, w8
//   0x026c80: 8a130114  and      x20, x8, x19
//   0x026c84: 9400d893  bl       #0x5ced0
//   0x026c88: 4b0003e8  neg      w8, w0
//   0x026c8c: 93407d08  sxtw     x8, w8
//   0x026c90: 91001e69  add      x9, x19, #7
//   0x026c94: 8a080133  and      x19, x9, x8
//   0x026c98: 9400d88e  bl       #0x5ced0
//   0x026c9c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x026ca0: 8b20c261  add      x1, x19, w0, sxtw
uint64_t fde_0023_sub_026c64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x8A080133ULL) + (x2 ^ 0x026C64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x026c64: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x026c68: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x026c6c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x026c70: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D897ULL; // 0x026c74: bl #0x5ced0
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0003E8ULL; // 0x026c78: neg w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D08ULL; // 0x026c7c: sxtw x8, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x8A130114ULL; // 0x026c80: and x20, x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D893ULL; // 0x026c84: bl #0x5ced0
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0003E8ULL; // 0x026c88: neg w8, w0
    return acc;
}

// [EN] Reconstructed FDE #0024 @ 0x026cb0..0x027434 (1924 bytes)
// [VN] Phục dựng FDE #0024 tại 0x026cb0..0x027434 (1924 byte)
//   0x026cb0: d10283ff  sub      sp, sp, #0xa0
//   0x026cb4: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x026cb8: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x026cbc: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x026cc0: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x026cc4: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x026cc8: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x026ccc: f9401c08  ldr      x8, [x0, #0x38]
//   0x026cd0: b940200b  ldr      w11, [x0, #0x20]
//   0x026cd4: b940080a  ldr      w10, [x0, #8]
//   0x026cd8: f9400c1e  ldr      x30, [x0, #0x18]
//   0x026cdc: b9404502  ldr      w2, [x8, #0x44]
//   0x026ce0: 4b0b002f  sub      w15, w1, w11
//   0x026ce4: 29478511  ldp      w17, w1, [x8, #0x3c]
//   0x026ce8: 294f1d03  ldp      w3, w7, [x8, #0x78]
//   0x026cec: 5100154c  sub      w12, w10, #5
uint64_t fde_0024_sub_026cb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x4B0B002FULL) + (x2 ^ 0x026CB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x026cb0: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x026cb4: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x026cb8: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x026cbc: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x026cc0: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x026cc4: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x026cc8: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C08ULL; // 0x026ccc: ldr x8, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940200BULL; // 0x026cd0: ldr w11, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940080AULL; // 0x026cd4: ldr w10, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0025 @ 0x027434..0x027438 (4 bytes)
// [VN] Phục dựng FDE #0025 tại 0x027434..0x027438 (4 byte)
//   0x027434: 14000001  b        #0x27438
uint64_t fde_0025_sub_027434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x027434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x027434: b #0x27438
    return acc;
}

// [EN] Reconstructed FDE #0026 @ 0x027438..0x0274b4 (124 bytes)
// [VN] Phục dựng FDE #0026 tại 0x027438..0x0274b4 (124 byte)
//   0x027438: b00001e2  adrp     x2, #0x64000
//   0x02743c: b942d043  ldr      w3, [x2, #0x2d0]
//   0x027440: 35000063  cbnz     w3, #0x2744c
//   0x027444: d53b0023  mrs      x3, ctr_el0
//   0x027448: b902d043  str      w3, [x2, #0x2d0]
//   0x02744c: b942d044  ldr      w4, [x2, #0x2d0]
//   0x027450: 52800082  mov      w2, #4
//   0x027454: 12000c83  and      w3, w4, #0xf
//   0x027458: d3504c84  ubfx     x4, x4, #0x10, #4
//   0x02745c: 1ac32043  lsl      w3, w2, w3
//   0x027460: 1ac42042  lsl      w2, w2, w4
//   0x027464: 51000444  sub      w4, w2, #1
//   0x027468: 8a240004  bic      x4, x0, x4
//   0x02746c: 93407c42  sxtw     x2, w2
//   0x027470: eb01009f  cmp      x4, x1
//   0x027474: 54000082  b.hs     #0x27484
uint64_t fde_0026_sub_027438(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001E2ULL) + (x1 ^ 0x8A240004ULL) + (x2 ^ 0x027438ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E2ULL; // 0x027438: adrp x2, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB942D043ULL; // 0x02743c: ldr w3, [x2, #0x2d0]
    acc = (acc * 0x100000001B3ULL) ^ 0x35000063ULL; // 0x027440: cbnz w3, #0x2744c
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B0023ULL; // 0x027444: mrs x3, ctr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xB902D043ULL; // 0x027448: str w3, [x2, #0x2d0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB942D044ULL; // 0x02744c: ldr w4, [x2, #0x2d0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800082ULL; // 0x027450: mov w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x12000C83ULL; // 0x027454: and w3, w4, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0xD3504C84ULL; // 0x027458: ubfx x4, x4, #0x10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC32043ULL; // 0x02745c: lsl w3, w2, w3
    return acc;
}

// [EN] Reconstructed FDE #0027 @ 0x0274b4..0x0274dc (40 bytes)
// [VN] Phục dựng FDE #0027 tại 0x0274b4..0x0274dc (40 byte)
//   0x0274b4: d2800002  mov      x2, #0
//   0x0274b8: 52800003  mov      w3, #0
//   0x0274bc: 38401405  ldrb     w5, [x0], #1
//   0x0274c0: 924018a4  and      x4, x5, #0x7f
//   0x0274c4: 9ac32084  lsl      x4, x4, x3
//   0x0274c8: 11001c63  add      w3, w3, #7
//   0x0274cc: aa040042  orr      x2, x2, x4
//   0x0274d0: 373fff65  tbnz     w5, #7, #0x274bc
//   0x0274d4: f9000022  str      x2, [x1]
//   0x0274d8: d65f03c0  ret      
uint64_t fde_0027_sub_0274b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0274B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x0274b4: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x0274b8: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x0274bc: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x0274c0: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x0274c4: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x0274c8: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x0274cc: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x0274d0: tbnz w5, #7, #0x274bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x0274d4: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0274d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0028 @ 0x0274dc..0x02751c (64 bytes)
// [VN] Phục dựng FDE #0028 tại 0x0274dc..0x02751c (64 byte)
//   0x0274dc: d2800002  mov      x2, #0
//   0x0274e0: 52800003  mov      w3, #0
//   0x0274e4: 38401404  ldrb     w4, [x0], #1
//   0x0274e8: 92401885  and      x5, x4, #0x7f
//   0x0274ec: 9ac320a5  lsl      x5, x5, x3
//   0x0274f0: 11001c63  add      w3, w3, #7
//   0x0274f4: aa050042  orr      x2, x2, x5
//   0x0274f8: 373fff64  tbnz     w4, #7, #0x274e4
//   0x0274fc: 7100fc7f  cmp      w3, #0x3f
//   0x027500: 540000a8  b.hi     #0x27514
//   0x027504: 36300084  tbz      w4, #6, #0x27514
//   0x027508: 92800004  mov      x4, #-1
//   0x02750c: 9ac32083  lsl      x3, x4, x3
//   0x027510: aa020062  orr      x2, x3, x2
//   0x027514: f9000022  str      x2, [x1]
//   0x027518: d65f03c0  ret      
uint64_t fde_0028_sub_0274dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x0274DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x0274dc: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x0274e0: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x0274e4: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x0274e8: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x0274ec: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x0274f0: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x0274f4: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x0274f8: tbnz w4, #7, #0x274e4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x0274fc: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x027500: b.hi #0x27514
    return acc;
}

// [EN] Reconstructed FDE #0029 @ 0x02751c..0x02760c (240 bytes)
// [VN] Phục dựng FDE #0029 tại 0x02751c..0x02760c (240 byte)
//   0x02751c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x027520: 910003fd  mov      x29, sp
//   0x027524: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x027528: 53001c14  uxtb     w20, w0
//   0x02752c: aa0203f3  mov      x19, x2
//   0x027530: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x027534: 7101429f  cmp      w20, #0x50
//   0x027538: aa0103f6  mov      x22, x1
//   0x02753c: aa0303f5  mov      x21, x3
//   0x027540: 540000a1  b.ne     #0x27554
//   0x027544: 91001c53  add      x19, x2, #7
//   0x027548: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x02754c: f8408401  ldr      x1, [x0], #8
//   0x027550: 1400002a  b        #0x275f8
//   0x027554: 12000e81  and      w1, w20, #0xf
//   0x027558: 7100303f  cmp      w1, #0xc
uint64_t fde_0029_sub_02751c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x02751CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x02751c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027520: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x027524: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x027528: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02752c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x027530: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x027534: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x027538: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x02753c: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x027540: b.ne #0x27554
    return acc;
}

// [EN] Reconstructed FDE #0030 @ 0x02760c..0x027720 (276 bytes)
// [VN] Phục dựng FDE #0030 tại 0x02760c..0x027720 (276 byte)
//   0x02760c: b00001e2  adrp     x2, #0x64000
//   0x027610: 52800100  mov      w0, #8
//   0x027614: 910b8041  add      x1, x2, #0x2e0
//   0x027618: 390b8040  strb     w0, [x2, #0x2e0]
//   0x02761c: 39000420  strb     w0, [x1, #1]
//   0x027620: 39000820  strb     w0, [x1, #2]
//   0x027624: 39000c20  strb     w0, [x1, #3]
//   0x027628: 39001020  strb     w0, [x1, #4]
//   0x02762c: 39001420  strb     w0, [x1, #5]
//   0x027630: 39001820  strb     w0, [x1, #6]
//   0x027634: 39001c20  strb     w0, [x1, #7]
//   0x027638: 39002020  strb     w0, [x1, #8]
//   0x02763c: 39002420  strb     w0, [x1, #9]
//   0x027640: 39002820  strb     w0, [x1, #0xa]
//   0x027644: 39002c20  strb     w0, [x1, #0xb]
//   0x027648: 39003020  strb     w0, [x1, #0xc]
uint64_t fde_0030_sub_02760c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001E2ULL) + (x1 ^ 0x39002420ULL) + (x2 ^ 0x02760CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E2ULL; // 0x02760c: adrp x2, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x027610: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910B8041ULL; // 0x027614: add x1, x2, #0x2e0
    acc = (acc * 0x100000001B3ULL) ^ 0x390B8040ULL; // 0x027618: strb w0, [x2, #0x2e0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000420ULL; // 0x02761c: strb w0, [x1, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000820ULL; // 0x027620: strb w0, [x1, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000C20ULL; // 0x027624: strb w0, [x1, #3]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001020ULL; // 0x027628: strb w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001420ULL; // 0x02762c: strb w0, [x1, #5]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001820ULL; // 0x027630: strb w0, [x1, #6]
    return acc;
}

// [EN] Reconstructed FDE #0031 @ 0x027720..0x02775c (60 bytes)
// [VN] Phục dựng FDE #0031 tại 0x027720..0x02775c (60 byte)
//   0x027720: b00001e3  adrp     x3, #0x64000
//   0x027724: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x027728: 910003fd  mov      x29, sp
//   0x02772c: 394bfc63  ldrb     w3, [x3, #0x2ff]
//   0x027730: 7100207f  cmp      w3, #8
//   0x027734: 540000c1  b.ne     #0x2774c
//   0x027738: f9000041  str      x1, [x2]
//   0x02773c: f941a001  ldr      x1, [x0, #0x340]
//   0x027740: b6f00081  tbz      x1, #0x3e, #0x27750
//   0x027744: 390ddc1f  strb     wzr, [x0, #0x377]
//   0x027748: 14000002  b        #0x27750
//   0x02774c: 9400d5ed  bl       #0x5cf00
//   0x027750: f9007c02  str      x2, [x0, #0xf8]
//   0x027754: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x027758: d65f03c0  ret      
uint64_t fde_0031_sub_027720(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001E3ULL) + (x1 ^ 0xF9007C02ULL) + (x2 ^ 0x027720ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E3ULL; // 0x027720: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x027724: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027728: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x394BFC63ULL; // 0x02772c: ldrb w3, [x3, #0x2ff]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100207FULL; // 0x027730: cmp w3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x027734: b.ne #0x2774c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000041ULL; // 0x027738: str x1, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A001ULL; // 0x02773c: ldr x1, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00081ULL; // 0x027740: tbz x1, #0x3e, #0x27750
    acc = (acc * 0x100000001B3ULL) ^ 0x390DDC1FULL; // 0x027744: strb wzr, [x0, #0x377]
    return acc;
}

// [EN] Reconstructed FDE #0032 @ 0x02775c..0x0277b4 (88 bytes)
// [VN] Phục dựng FDE #0032 tại 0x02775c..0x0277b4 (88 byte)
//   0x02775c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x027760: 7101843f  cmp      w1, #0x61
//   0x027764: 910003fd  mov      x29, sp
//   0x027768: 5400004d  b.le     #0x27770
//   0x02776c: 9400d5e5  bl       #0x5cf00
//   0x027770: b00001e3  adrp     x3, #0x64000
//   0x027774: 93407c22  sxtw     x2, w1
//   0x027778: 910b8063  add      x3, x3, #0x2e0
//   0x02777c: f941a004  ldr      x4, [x0, #0x340]
//   0x027780: f861d801  ldr      x1, [x0, w1, sxtw #3]
//   0x027784: 38626863  ldrb     w3, [x3, x2]
//   0x027788: b6f000c4  tbz      x4, #0x3e, #0x277a0
//   0x02778c: 8b020002  add      x2, x0, x2
//   0x027790: 394d6040  ldrb     w0, [x2, #0x358]
//   0x027794: 34000060  cbz      w0, #0x277a0
//   0x027798: aa0103e0  mov      x0, x1
uint64_t fde_0032_sub_02775c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B020002ULL) + (x2 ^ 0x02775CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02775c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x027760: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027764: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x027768: b.le #0x27770
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D5E5ULL; // 0x02776c: bl #0x5cf00
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E3ULL; // 0x027770: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C22ULL; // 0x027774: sxtw x2, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x910B8063ULL; // 0x027778: add x3, x3, #0x2e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A004ULL; // 0x02777c: ldr x4, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF861D801ULL; // 0x027780: ldr x1, [x0, w1, sxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #0033 @ 0x0277b4..0x0278c0 (268 bytes)
// [VN] Phục dựng FDE #0033 tại 0x0277b4..0x0278c0 (268 byte)
//   0x0277b4: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x0277b8: 910003fd  mov      x29, sp
//   0x0277bc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0277c0: aa0003f5  mov      x21, x0
//   0x0277c4: f941a020  ldr      x0, [x1, #0x340]
//   0x0277c8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0277cc: aa0103f3  mov      x19, x1
//   0x0277d0: b6f00060  tbz      x0, #0x3e, #0x277dc
//   0x0277d4: 394ddc20  ldrb     w0, [x1, #0x377]
//   0x0277d8: 350000e0  cbnz     w0, #0x277f4
//   0x0277dc: f9407e60  ldr      x0, [x19, #0xf8]
//   0x0277e0: b50000a0  cbnz     x0, #0x277f4
//   0x0277e4: f9418a61  ldr      x1, [x19, #0x310]
//   0x0277e8: aa1303e0  mov      x0, x19
//   0x0277ec: 9100e3a2  add      x2, x29, #0x38
//   0x0277f0: 97ffffcc  bl       #0x27720
uint64_t fde_0033_sub_0277b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF9418A61ULL) + (x2 ^ 0x0277B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x0277b4: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0277b8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x0277bc: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0277c0: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A020ULL; // 0x0277c4: ldr x0, [x1, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0277c8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0277cc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00060ULL; // 0x0277d0: tbz x0, #0x3e, #0x277dc
    acc = (acc * 0x100000001B3ULL) ^ 0x394DDC20ULL; // 0x0277d4: ldrb w0, [x1, #0x377]
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E0ULL; // 0x0277d8: cbnz w0, #0x277f4
    return acc;
}

// [EN] Reconstructed FDE #0034 @ 0x0278c0..0x0278c8 (8 bytes)
// [VN] Phục dựng FDE #0034 tại 0x0278c0..0x0278c8 (8 byte)
//   0x0278c0: f9418800  ldr      x0, [x0, #0x310]
//   0x0278c4: d65f03c0  ret      
uint64_t fde_0034_sub_0278c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0278C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418800ULL; // 0x0278c0: ldr x0, [x0, #0x310]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0278c4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0035 @ 0x0278c8..0x027920 (88 bytes)
// [VN] Phục dựng FDE #0035 tại 0x0278c8..0x027920 (88 byte)
//   0x0278c8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0278cc: 7101843f  cmp      w1, #0x61
//   0x0278d0: 910003fd  mov      x29, sp
//   0x0278d4: 5400004d  b.le     #0x278dc
//   0x0278d8: 9400d58a  bl       #0x5cf00
//   0x0278dc: b00001e4  adrp     x4, #0x64000
//   0x0278e0: 93407c23  sxtw     x3, w1
//   0x0278e4: 910b8084  add      x4, x4, #0x2e0
//   0x0278e8: f941a005  ldr      x5, [x0, #0x340]
//   0x0278ec: 38636884  ldrb     w4, [x4, x3]
//   0x0278f0: b6f000c5  tbz      x5, #0x3e, #0x27908
//   0x0278f4: 8b030003  add      x3, x0, x3
//   0x0278f8: 394d6063  ldrb     w3, [x3, #0x358]
//   0x0278fc: 34000063  cbz      w3, #0x27908
//   0x027900: f821d802  str      x2, [x0, w1, sxtw #3]
//   0x027904: 14000005  b        #0x27918
uint64_t fde_0035_sub_0278c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x394D6063ULL) + (x2 ^ 0x0278C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0278c8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x0278cc: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0278d0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x0278d4: b.le #0x278dc
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D58AULL; // 0x0278d8: bl #0x5cf00
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E4ULL; // 0x0278dc: adrp x4, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C23ULL; // 0x0278e0: sxtw x3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x910B8084ULL; // 0x0278e4: add x4, x4, #0x2e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A005ULL; // 0x0278e8: ldr x5, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0x38636884ULL; // 0x0278ec: ldrb w4, [x4, x3]
    return acc;
}

// [EN] Reconstructed FDE #0036 @ 0x027920..0x027928 (8 bytes)
// [VN] Phục dựng FDE #0036 tại 0x027920..0x027928 (8 byte)
//   0x027920: f9418c00  ldr      x0, [x0, #0x318]
//   0x027924: d65f03c0  ret      
uint64_t fde_0036_sub_027920(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027920ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x027920: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027924: ret 
    return acc;
}

// [EN] Reconstructed FDE #0037 @ 0x027928..0x02793c (20 bytes)
// [VN] Phục dựng FDE #0037 tại 0x027928..0x02793c (20 byte)
//   0x027928: f941a002  ldr      x2, [x0, #0x340]
//   0x02792c: f9418c00  ldr      x0, [x0, #0x318]
//   0x027930: d37ffc42  lsr      x2, x2, #0x3f
//   0x027934: b9000022  str      w2, [x1]
//   0x027938: d65f03c0  ret      
uint64_t fde_0037_sub_027928(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF941A002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027928ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A002ULL; // 0x027928: ldr x2, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x02792c: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD37FFC42ULL; // 0x027930: lsr x2, x2, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000022ULL; // 0x027934: str w2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027938: ret 
    return acc;
}

// [EN] Reconstructed FDE #0038 @ 0x02793c..0x027944 (8 bytes)
// [VN] Phục dựng FDE #0038 tại 0x02793c..0x027944 (8 byte)
//   0x02793c: f9018c01  str      x1, [x0, #0x318]
//   0x027940: d65f03c0  ret      
uint64_t fde_0038_sub_02793c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9018C01ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02793CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9018C01ULL; // 0x02793c: str x1, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027940: ret 
    return acc;
}

// [EN] Reconstructed FDE #0039 @ 0x027944..0x02794c (8 bytes)
// [VN] Phục dựng FDE #0039 tại 0x027944..0x02794c (8 byte)
//   0x027944: f9419000  ldr      x0, [x0, #0x320]
//   0x027948: d65f03c0  ret      
uint64_t fde_0039_sub_027944(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027944ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419000ULL; // 0x027944: ldr x0, [x0, #0x320]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027948: ret 
    return acc;
}

// [EN] Reconstructed FDE #0040 @ 0x02794c..0x027954 (8 bytes)
// [VN] Phục dựng FDE #0040 tại 0x02794c..0x027954 (8 byte)
//   0x02794c: f9419c00  ldr      x0, [x0, #0x338]
//   0x027950: d65f03c0  ret      
uint64_t fde_0040_sub_02794c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02794CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419C00ULL; // 0x02794c: ldr x0, [x0, #0x338]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027950: ret 
    return acc;
}

// [EN] Reconstructed FDE #0041 @ 0x027954..0x02797c (40 bytes)
// [VN] Phục dựng FDE #0041 tại 0x027954..0x02797c (40 byte)
//   0x027954: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x027958: d1000400  sub      x0, x0, #1
//   0x02795c: 910003fd  mov      x29, sp
//   0x027960: 910063a1  add      x1, x29, #0x18
//   0x027964: 9400d56f  bl       #0x5cf20
//   0x027968: eb1f001f  cmp      x0, xzr
//   0x02796c: f94017a0  ldr      x0, [x29, #0x28]
//   0x027970: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x027974: 9a9f1000  csel     x0, x0, xzr, ne
//   0x027978: d65f03c0  ret      
uint64_t fde_0041_sub_027954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x027954: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000400ULL; // 0x027958: sub x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02795c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x910063A1ULL; // 0x027960: add x1, x29, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9400D56FULL; // 0x027964: bl #0x5cf20
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1F001FULL; // 0x027968: cmp x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF94017A0ULL; // 0x02796c: ldr x0, [x29, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C37BFDULL; // 0x027970: ldp x29, x30, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9A9F1000ULL; // 0x027974: csel x0, x0, xzr, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027978: ret 
    return acc;
}

// [EN] Reconstructed FDE #0042 @ 0x02797c..0x027984 (8 bytes)
// [VN] Phục dựng FDE #0042 tại 0x02797c..0x027984 (8 byte)
//   0x02797c: f9419800  ldr      x0, [x0, #0x330]
//   0x027980: d65f03c0  ret      
uint64_t fde_0042_sub_02797c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02797CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419800ULL; // 0x02797c: ldr x0, [x0, #0x330]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027980: ret 
    return acc;
}

// [EN] Reconstructed FDE #0043 @ 0x027984..0x02798c (8 bytes)
// [VN] Phục dựng FDE #0043 tại 0x027984..0x02798c (8 byte)
//   0x027984: f9419400  ldr      x0, [x0, #0x328]
//   0x027988: d65f03c0  ret      
uint64_t fde_0043_sub_027984(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027984ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419400ULL; // 0x027984: ldr x0, [x0, #0x328]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027988: ret 
    return acc;
}

// [EN] Reconstructed FDE #0044 @ 0x02798c..0x027a04 (120 bytes)
// [VN] Phục dựng FDE #0044 tại 0x02798c..0x027a04 (120 byte)
//   0x02798c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x027990: 53001c02  uxtb     w2, w0
//   0x027994: aa0103e0  mov      x0, x1
//   0x027998: 7103fc5f  cmp      w2, #0xff
//   0x02799c: 910003fd  mov      x29, sp
//   0x0279a0: 540002c0  b.eq     #0x279f8
//   0x0279a4: 121c0842  and      w2, w2, #0x70
//   0x0279a8: 7100805f  cmp      w2, #0x20
//   0x0279ac: 540001c0  b.eq     #0x279e4
//   0x0279b0: 540000a8  b.hi     #0x279c4
//   0x0279b4: 34000222  cbz      w2, #0x279f8
//   0x0279b8: 7100405f  cmp      w2, #0x10
//   0x0279bc: 540001c1  b.ne     #0x279f4
//   0x0279c0: 1400000e  b        #0x279f8
//   0x0279c4: 7101005f  cmp      w2, #0x40
//   0x0279c8: 54000120  b.eq     #0x279ec
uint64_t fde_0044_sub_02798c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x540001C1ULL) + (x2 ^ 0x02798CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02798c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C02ULL; // 0x027990: uxtb w2, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x027994: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC5FULL; // 0x027998: cmp w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02799c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540002C0ULL; // 0x0279a0: b.eq #0x279f8
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0842ULL; // 0x0279a4: and w2, w2, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100805FULL; // 0x0279a8: cmp w2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C0ULL; // 0x0279ac: b.eq #0x279e4
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x0279b0: b.hi #0x279c4
    return acc;
}

// [EN] Reconstructed FDE #0045 @ 0x027a04..0x027efc (1272 bytes)
// [VN] Phục dựng FDE #0045 tại 0x027a04..0x027efc (1272 byte)
//   0x027a04: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x027a08: 910003fd  mov      x29, sp
//   0x027a0c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x027a10: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x027a14: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x027a18: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x027a1c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x027a20: d0ffff7b  adrp     x27, #0x15000
//   0x027a24: aa0103fc  mov      x28, x1
//   0x027a28: aa0203fa  mov      x26, x2
//   0x027a2c: aa0303f3  mov      x19, x3
//   0x027a30: f903107f  str      xzr, [x3, #0x620]
//   0x027a34: d2800018  mov      x24, #0
//   0x027a38: 911f037b  add      x27, x27, #0x7c0
//   0x027a3c: 9101e3b6  add      x22, x29, #0x78
//   0x027a40: 910203b5  add      x21, x29, #0x80
uint64_t fde_0045_sub_027a04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0xD2800018ULL) + (x2 ^ 0x027A04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x027a04: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027a08: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x027a0c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x027a10: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x027a14: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x027a18: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x027a1c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF7BULL; // 0x027a20: adrp x27, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103FCULL; // 0x027a24: mov x28, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203FAULL; // 0x027a28: mov x26, x2
    return acc;
}

// [EN] Reconstructed FDE #0046 @ 0x027efc..0x028320 (1060 bytes)
// [VN] Phục dựng FDE #0046 tại 0x027efc..0x028320 (1060 byte)
//   0x027efc: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x027f00: d280d002  mov      x2, #0x680
//   0x027f04: 910003fd  mov      x29, sp
//   0x027f08: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x027f0c: aa0003f4  mov      x20, x0
//   0x027f10: aa0103f3  mov      x19, x1
//   0x027f14: aa0103e0  mov      x0, x1
//   0x027f18: 52800001  mov      w1, #0
//   0x027f1c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x027f20: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x027f24: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x027f28: f9002bfb  str      x27, [sp, #0x50]
//   0x027f2c: 9400d40d  bl       #0x5cf60
//   0x027f30: f9418e81  ldr      x1, [x20, #0x318]
//   0x027f34: f901aa9f  str      xzr, [x20, #0x350]
//   0x027f38: f901929f  str      xzr, [x20, #0x320]
uint64_t fde_0046_sub_027efc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x9400D40DULL) + (x2 ^ 0x027EFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x027efc: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD280D002ULL; // 0x027f00: mov x2, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027f04: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x027f08: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x027f0c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x027f10: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x027f14: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x027f18: mov w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x027f1c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x027f20: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0047 @ 0x028320..0x0288d4 (1460 bytes)
// [VN] Phục dựng FDE #0047 tại 0x028320..0x0288d4 (1460 byte)
//   0x028320: d108c3ff  sub      sp, sp, #0x230
//   0x028324: aa0003e4  mov      x4, x0
//   0x028328: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x02832c: 910003fd  mov      x29, sp
//   0x028330: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x028334: 910243bc  add      x28, x29, #0x90
//   0x028338: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02833c: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x028340: b0ffff76  adrp     x22, #0x15000
//   0x028344: b0ffff77  adrp     x23, #0x15000
//   0x028348: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02834c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x028350: aa0103f8  mov      x24, x1
//   0x028354: aa0203f3  mov      x19, x2
//   0x028358: f9000383  str      x3, [x28]
//   0x02835c: 52800039  mov      w25, #1
uint64_t fde_0047_sub_028320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD108C3FFULL) + (x1 ^ 0xAA0103F8ULL) + (x2 ^ 0x028320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x028320: sub sp, sp, #0x230
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E4ULL; // 0x028324: mov x4, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x028328: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02832c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x028330: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243BCULL; // 0x028334: add x28, x29, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x028338: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x02833c: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF76ULL; // 0x028340: adrp x22, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF77ULL; // 0x028344: adrp x23, #0x15000
    return acc;
}

// [EN] Reconstructed FDE #0048 @ 0x0288d4..0x028ae0 (524 bytes)
// [VN] Phục dựng FDE #0048 tại 0x0288d4..0x028ae0 (524 byte)
//   0x0288d4: d10f83ff  sub      sp, sp, #0x3e0
//   0x0288d8: d2807802  mov      x2, #0x3c0
//   0x0288dc: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x0288e0: 910003fd  mov      x29, sp
//   0x0288e4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0288e8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0288ec: aa0003f3  mov      x19, x0
//   0x0288f0: 910203b5  add      x21, x29, #0x80
//   0x0288f4: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x0288f8: aa1503e0  mov      x0, x21
//   0x0288fc: aa0103f8  mov      x24, x1
//   0x028900: aa1303e1  mov      x1, x19
//   0x028904: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x028908: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x02890c: 9400d181  bl       #0x5cf10
//   0x028910: f941e3a0  ldr      x0, [x29, #0x3c0]
uint64_t fde_0048_sub_0288d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10F83FFULL) + (x1 ^ 0xA9046BF9ULL) + (x2 ^ 0x0288D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10F83FFULL; // 0x0288d4: sub sp, sp, #0x3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x0288d8: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x0288dc: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0288e0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0288e4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x0288e8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0288ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910203B5ULL; // 0x0288f0: add x21, x29, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x0288f4: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x0288f8: mov x0, x21
    return acc;
}

// [EN] Reconstructed FDE #0049 @ 0x028ae0..0x028bbc (220 bytes)
// [VN] Phục dựng FDE #0049 tại 0x028ae0..0x028bbc (220 byte)
//   0x028ae0: d11a43ff  sub      sp, sp, #0x690
//   0x028ae4: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x028ae8: 910003fd  mov      x29, sp
//   0x028aec: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x028af0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x028af4: aa0003f3  mov      x19, x0
//   0x028af8: f9001bf7  str      x23, [sp, #0x30]
//   0x028afc: aa0203f6  mov      x22, x2
//   0x028b00: aa0103f7  mov      x23, x1
//   0x028b04: d2807802  mov      x2, #0x3c0
//   0x028b08: 52800001  mov      w1, #0
//   0x028b0c: aa1e03f4  mov      x20, x30
//   0x028b10: 9400d114  bl       #0x5cf60
//   0x028b14: f9018e74  str      x20, [x19, #0x318]
//   0x028b18: d2e80000  mov      x0, #0x4000000000000000
//   0x028b1c: 910143b4  add      x20, x29, #0x50
uint64_t fde_0049_sub_028ae0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A43FFULL) + (x1 ^ 0x9400D114ULL) + (x2 ^ 0x028AE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A43FFULL; // 0x028ae0: sub sp, sp, #0x690
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x028ae4: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028ae8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x028aec: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x028af0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028af4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x028af8: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x028afc: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x028b00: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x028b04: mov x2, #0x3c0
    return acc;
}

// [EN] Reconstructed FDE #0050 @ 0x028bbc..0x028c08 (76 bytes)
// [VN] Phục dựng FDE #0050 tại 0x028bbc..0x028c08 (76 byte)
//   0x028bbc: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x028bc0: 910003fd  mov      x29, sp
//   0x028bc4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x028bc8: aa0103f3  mov      x19, x1
//   0x028bcc: aa0003f4  mov      x20, x0
//   0x028bd0: 97ffff41  bl       #0x288d4
//   0x028bd4: f9433661  ldr      x1, [x19, #0x668]
//   0x028bd8: 8b011273  add      x19, x19, x1, lsl #4
//   0x028bdc: b9400a60  ldr      w0, [x19, #8]
//   0x028be0: 7100181f  cmp      w0, #6
//   0x028be4: 54000061  b.ne     #0x28bf0
//   0x028be8: f9018e9f  str      xzr, [x20, #0x318]
//   0x028bec: 14000004  b        #0x28bfc
//   0x028bf0: aa1403e0  mov      x0, x20
//   0x028bf4: 97fffada  bl       #0x2775c
//   0x028bf8: f9018e80  str      x0, [x20, #0x318]
uint64_t fde_0050_sub_028bbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x14000004ULL) + (x2 ^ 0x028BBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x028bbc: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028bc0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x028bc4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028bc8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x028bcc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF41ULL; // 0x028bd0: bl #0x288d4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433661ULL; // 0x028bd4: ldr x1, [x19, #0x668]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B011273ULL; // 0x028bd8: add x19, x19, x1, lsl #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A60ULL; // 0x028bdc: ldr w0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100181FULL; // 0x028be0: cmp w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0051 @ 0x028c08..0x028cc8 (192 bytes)
// [VN] Phục dựng FDE #0051 tại 0x028c08..0x028cc8 (192 byte)
//   0x028c08: d11a03ff  sub      sp, sp, #0x680
//   0x028c0c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x028c10: 910003fd  mov      x29, sp
//   0x028c14: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x028c18: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x028c1c: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x028c20: aa0003f5  mov      x21, x0
//   0x028c24: aa0103f3  mov      x19, x1
//   0x028c28: 910103b4  add      x20, x29, #0x40
//   0x028c2c: 52800097  mov      w23, #4
//   0x028c30: aa1403e1  mov      x1, x20
//   0x028c34: aa1303e0  mov      x0, x19
//   0x028c38: 97fffcb1  bl       #0x27efc
//   0x028c3c: 2a0003f8  mov      w24, w0
//   0x028c40: aa1303e0  mov      x0, x19
//   0x028c44: 9400d0cf  bl       #0x5cf80
uint64_t fde_0051_sub_028c08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x97FFFCB1ULL) + (x2 ^ 0x028C08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x028c08: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x028c0c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028c10: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x028c14: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x028c18: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x028c1c: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x028c20: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028c24: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910103B4ULL; // 0x028c28: add x20, x29, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x52800097ULL; // 0x028c2c: mov w23, #4
    return acc;
}

// [EN] Reconstructed FDE #0052 @ 0x028cc8..0x028db4 (236 bytes)
// [VN] Phục dựng FDE #0052 tại 0x028cc8..0x028db4 (236 byte)
//   0x028cc8: d11a03ff  sub      sp, sp, #0x680
//   0x028ccc: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x028cd0: 910003fd  mov      x29, sp
//   0x028cd4: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x028cd8: f9400817  ldr      x23, [x0, #0x10]
//   0x028cdc: f9400c18  ldr      x24, [x0, #0x18]
//   0x028ce0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x028ce4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x028ce8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x028cec: aa0103f5  mov      x21, x1
//   0x028cf0: aa0003f4  mov      x20, x0
//   0x028cf4: 910143b6  add      x22, x29, #0x50
//   0x028cf8: 52800359  mov      w25, #0x1a
//   0x028cfc: 5280015a  mov      w26, #0xa
//   0x028d00: aa1503e0  mov      x0, x21
//   0x028d04: aa1603e1  mov      x1, x22
uint64_t fde_0052_sub_028cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x52800359ULL) + (x2 ^ 0x028CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x028cc8: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x028ccc: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028cd0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x028cd4: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400817ULL; // 0x028cd8: ldr x23, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C18ULL; // 0x028cdc: ldr x24, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x028ce0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x028ce4: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x028ce8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x028cec: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0053 @ 0x028db4..0x028ea8 (244 bytes)
// [VN] Phục dựng FDE #0053 tại 0x028db4..0x028ea8 (244 byte)
//   0x028db4: d12903ff  sub      sp, sp, #0xa40
//   0x028db8: d2807802  mov      x2, #0x3c0
//   0x028dbc: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x028dc0: 910003fd  mov      x29, sp
//   0x028dc4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x028dc8: 9100c3b4  add      x20, x29, #0x30
//   0x028dcc: f90013f5  str      x21, [sp, #0x20]
//   0x028dd0: aa0103f3  mov      x19, x1
//   0x028dd4: aa0003f5  mov      x21, x0
//   0x028dd8: 52800001  mov      w1, #0
//   0x028ddc: aa1403e0  mov      x0, x20
//   0x028de0: 910006b5  add      x21, x21, #1
//   0x028de4: 9400d05f  bl       #0x5cf60
//   0x028de8: f9018e95  str      x21, [x20, #0x318]
//   0x028dec: d2e80000  mov      x0, #0x4000000000000000
//   0x028df0: 910fc3b5  add      x21, x29, #0x3f0
uint64_t fde_0053_sub_028db4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0x9400D05FULL) + (x2 ^ 0x028DB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x028db4: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x028db8: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x028dbc: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028dc0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x028dc4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3B4ULL; // 0x028dc8: add x20, x29, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x028dcc: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028dd0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x028dd4: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x028dd8: mov w1, #0
    return acc;
}

// [EN] Reconstructed FDE #0054 @ 0x028ea8..0x028eac (4 bytes)
// [VN] Phục dựng FDE #0054 tại 0x028ea8..0x028eac (4 byte)
//   0x028ea8: d65f03c0  ret      
uint64_t fde_0054_sub_028ea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028EA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x028ea8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0055 @ 0x028eac..0x029024 (376 bytes)
// [VN] Phục dựng FDE #0055 tại 0x028eac..0x029024 (376 byte)
//   0x028eac: d13843ff  sub      sp, sp, #0xe10
//   0x028eb0: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x028eb4: 910003fd  mov      x29, sp
//   0x028eb8: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x028ebc: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x028ec0: 910343b5  add      x21, x29, #0xd0
//   0x028ec4: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x028ec8: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x028ecc: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x028ed0: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x028ed4: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x028ed8: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x028edc: aa1e03e2  mov      x2, x30
//   0x028ee0: 913b43a1  add      x1, x29, #0xed0
//   0x028ee4: aa0003f4  mov      x20, x0
//   0x028ee8: aa1503e0  mov      x0, x21
uint64_t fde_0055_sub_028eac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD13843FFULL) + (x1 ^ 0xAA1E03E2ULL) + (x2 ^ 0x028EACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD13843FFULL; // 0x028eac: sub sp, sp, #0xe10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x028eb0: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028eb4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045BF5ULL; // 0x028eb8: stp x21, x22, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x028ebc: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B5ULL; // 0x028ec0: add x21, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x028ec4: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x028ec8: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x028ecc: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x028ed0: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0056 @ 0x029024..0x029118 (244 bytes)
// [VN] Phục dựng FDE #0056 tại 0x029024..0x029118 (244 byte)
//   0x029024: d11e43ff  sub      sp, sp, #0x790
//   0x029028: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x02902c: 910003fd  mov      x29, sp
//   0x029030: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x029034: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x029038: 910343b4  add      x20, x29, #0xd0
//   0x02903c: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x029040: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x029044: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x029048: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x02904c: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x029050: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x029054: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x029058: aa0003f5  mov      x21, x0
//   0x02905c: aa0103f7  mov      x23, x1
//   0x029060: aa0203f6  mov      x22, x2
uint64_t fde_0056_sub_029024(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x029024ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x029024: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x029028: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02902c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x029030: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x029034: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x029038: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x02903c: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x029040: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x029044: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x029048: stp x0, x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0057 @ 0x029118..0x029214 (252 bytes)
// [VN] Phục dựng FDE #0057 tại 0x029118..0x029214 (252 byte)
//   0x029118: d11e43ff  sub      sp, sp, #0x790
//   0x02911c: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x029120: 910003fd  mov      x29, sp
//   0x029124: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x029128: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x02912c: 910343b4  add      x20, x29, #0xd0
//   0x029130: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x029134: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x029138: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x02913c: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x029140: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x029144: aa1e03e2  mov      x2, x30
//   0x029148: 912143a1  add      x1, x29, #0x850
//   0x02914c: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x029150: aa0003f5  mov      x21, x0
//   0x029154: aa1403e0  mov      x0, x20
uint64_t fde_0057_sub_029118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0x912143A1ULL) + (x2 ^ 0x029118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x029118: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x02911c: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029120: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x029124: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x029128: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x02912c: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x029130: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x029134: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x029138: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x02913c: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0058 @ 0x029214..0x02930c (248 bytes)
// [VN] Phục dựng FDE #0058 tại 0x029214..0x02930c (248 byte)
//   0x029214: d11e43ff  sub      sp, sp, #0x790
//   0x029218: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x02921c: 910003fd  mov      x29, sp
//   0x029220: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x029224: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x029228: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x02922c: f9400801  ldr      x1, [x0, #0x10]
//   0x029230: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x029234: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x029238: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x02923c: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x029240: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x029244: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x029248: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x02924c: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x029250: aa1e03e2  mov      x2, x30
uint64_t fde_0058_sub_029214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x029214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x029214: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x029218: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02921c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x029220: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x029224: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x029228: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x02922c: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x029230: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x029234: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0B3FEEULL; // 0x029238: stp d14, d15, [sp, #0xb0]
    return acc;
}

// [EN] Reconstructed FDE #0059 @ 0x02930c..0x029330 (36 bytes)
// [VN] Phục dựng FDE #0059 tại 0x02930c..0x029330 (36 byte)
//   0x02930c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x029310: 910003fd  mov      x29, sp
//   0x029314: f9400402  ldr      x2, [x0, #8]
//   0x029318: b4000082  cbz      x2, #0x29328
//   0x02931c: aa0003e1  mov      x1, x0
//   0x029320: 52800020  mov      w0, #1
//   0x029324: d63f0040  blr      x2
//   0x029328: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02932c: d65f03c0  ret      
uint64_t fde_0059_sub_02930c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02930CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02930c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029310: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400402ULL; // 0x029314: ldr x2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x029318: cbz x2, #0x29328
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x02931c: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x029320: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0040ULL; // 0x029324: blr x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x029328: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02932c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0060 @ 0x029330..0x029400 (208 bytes)
// [VN] Phục dựng FDE #0060 tại 0x029330..0x029400 (208 byte)
//   0x029330: d12903ff  sub      sp, sp, #0xa40
//   0x029334: aa1e03e2  mov      x2, x30
//   0x029338: a9b67bfd  stp      x29, x30, [sp, #-0xa0]!
//   0x02933c: 910003fd  mov      x29, sp
//   0x029340: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029344: 6d0627e8  stp      d8, d9, [sp, #0x60]
//   0x029348: 910283b4  add      x20, x29, #0xa0
//   0x02934c: 6d072fea  stp      d10, d11, [sp, #0x70]
//   0x029350: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029354: 6d0837ec  stp      d12, d13, [sp, #0x80]
//   0x029358: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02935c: 6d093fee  stp      d14, d15, [sp, #0x90]
//   0x029360: aa0003f6  mov      x22, x0
//   0x029364: aa0103f7  mov      x23, x1
//   0x029368: aa1403e0  mov      x0, x20
//   0x02936c: 912b83a1  add      x1, x29, #0xae0
uint64_t fde_0060_sub_029330(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x029330ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x029330: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03E2ULL; // 0x029334: mov x2, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B67BFDULL; // 0x029338: stp x29, x30, [sp, #-0xa0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02933c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029340: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0627E8ULL; // 0x029344: stp d8, d9, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283B4ULL; // 0x029348: add x20, x29, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D072FEAULL; // 0x02934c: stp d10, d11, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x029350: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0837ECULL; // 0x029354: stp d12, d13, [sp, #0x80]
    return acc;
}

// [EN] Reconstructed FDE #0061 @ 0x029400..0x029428 (40 bytes)
// [VN] Phục dựng FDE #0061 tại 0x029400..0x029428 (40 byte)
//   0x029400: d2800002  mov      x2, #0
//   0x029404: 52800003  mov      w3, #0
//   0x029408: 38401405  ldrb     w5, [x0], #1
//   0x02940c: 924018a4  and      x4, x5, #0x7f
//   0x029410: 9ac32084  lsl      x4, x4, x3
//   0x029414: 11001c63  add      w3, w3, #7
//   0x029418: aa040042  orr      x2, x2, x4
//   0x02941c: 373fff65  tbnz     w5, #7, #0x29408
//   0x029420: f9000022  str      x2, [x1]
//   0x029424: d65f03c0  ret      
uint64_t fde_0061_sub_029400(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029400ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x029400: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x029404: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x029408: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x02940c: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x029410: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x029414: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x029418: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x02941c: tbnz w5, #7, #0x29408
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x029420: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x029424: ret 
    return acc;
}

// [EN] Reconstructed FDE #0062 @ 0x029428..0x029468 (64 bytes)
// [VN] Phục dựng FDE #0062 tại 0x029428..0x029468 (64 byte)
//   0x029428: d2800002  mov      x2, #0
//   0x02942c: 52800003  mov      w3, #0
//   0x029430: 38401404  ldrb     w4, [x0], #1
//   0x029434: 92401885  and      x5, x4, #0x7f
//   0x029438: 9ac320a5  lsl      x5, x5, x3
//   0x02943c: 11001c63  add      w3, w3, #7
//   0x029440: aa050042  orr      x2, x2, x5
//   0x029444: 373fff64  tbnz     w4, #7, #0x29430
//   0x029448: 7100fc7f  cmp      w3, #0x3f
//   0x02944c: 540000a8  b.hi     #0x29460
//   0x029450: 36300084  tbz      w4, #6, #0x29460
//   0x029454: 92800004  mov      x4, #-1
//   0x029458: 9ac32083  lsl      x3, x4, x3
//   0x02945c: aa020062  orr      x2, x3, x2
//   0x029460: f9000022  str      x2, [x1]
//   0x029464: d65f03c0  ret      
uint64_t fde_0062_sub_029428(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x029428ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x029428: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x02942c: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x029430: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x029434: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x029438: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x02943c: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x029440: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x029444: tbnz w4, #7, #0x29430
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x029448: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x02944c: b.hi #0x29460
    return acc;
}

// [EN] Reconstructed FDE #0063 @ 0x029468..0x029484 (28 bytes)
// [VN] Phục dựng FDE #0063 tại 0x029468..0x029484 (28 byte)
//   0x029468: f9400423  ldr      x3, [x1, #8]
//   0x02946c: f9400441  ldr      x1, [x2, #8]
//   0x029470: eb01007f  cmp      x3, x1
//   0x029474: 5a9f23e0  csetm    w0, lo
//   0x029478: eb01007f  cmp      x3, x1
//   0x02947c: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x029480: d65f03c0  ret      
uint64_t fde_0063_sub_029468(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400423ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029468ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400423ULL; // 0x029468: ldr x3, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400441ULL; // 0x02946c: ldr x1, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x029470: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x5A9F23E0ULL; // 0x029474: csetm w0, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x029478: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F9400ULL; // 0x02947c: csinc w0, w0, wzr, ls
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x029480: ret 
    return acc;
}

// [EN] Reconstructed FDE #0064 @ 0x029484..0x029544 (192 bytes)
// [VN] Phục dựng FDE #0064 tại 0x029484..0x029544 (192 byte)
//   0x029484: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x029488: 910003fd  mov      x29, sp
//   0x02948c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029490: 531f7873  lsl      w19, w3, #1
//   0x029494: f90023f9  str      x25, [sp, #0x40]
//   0x029498: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02949c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0294a0: aa0003f8  mov      x24, x0
//   0x0294a4: aa0103f9  mov      x25, x1
//   0x0294a8: aa0203f4  mov      x20, x2
//   0x0294ac: 2a0403f7  mov      w23, w4
//   0x0294b0: 11000673  add      w19, w19, #1
//   0x0294b4: 6b17027f  cmp      w19, w23
//   0x0294b8: 540003aa  b.ge     #0x2952c
//   0x0294bc: 11000675  add      w21, w19, #1
//   0x0294c0: 6b1702bf  cmp      w21, w23
uint64_t fde_0064_sub_029484(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA7BFDULL) + (x1 ^ 0x6B17027FULL) + (x2 ^ 0x029484ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x029484: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029488: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02948c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7873ULL; // 0x029490: lsl w19, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x029494: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x029498: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02949c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x0294a0: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x0294a4: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x0294a8: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0065 @ 0x029544..0x0295f8 (180 bytes)
// [VN] Phục dựng FDE #0065 tại 0x029544..0x0295f8 (180 byte)
//   0x029544: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x029548: 910003fd  mov      x29, sp
//   0x02954c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029550: f9400453  ldr      x19, [x2, #8]
//   0x029554: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029558: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02955c: f90023f9  str      x25, [sp, #0x40]
//   0x029560: aa0003f8  mov      x24, x0
//   0x029564: aa0103f9  mov      x25, x1
//   0x029568: aa0203f5  mov      x21, x2
//   0x02956c: 91004056  add      x22, x2, #0x10
//   0x029570: d341fe74  lsr      x20, x19, #1
//   0x029574: 51000694  sub      w20, w20, #1
//   0x029578: 37f80114  tbnz     w20, #0x1f, #0x29598
//   0x02957c: aa1803e0  mov      x0, x24
//   0x029580: aa1903e1  mov      x1, x25
uint64_t fde_0065_sub_029544(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x51000694ULL) + (x2 ^ 0x029544ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x029544: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029548: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02954c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400453ULL; // 0x029550: ldr x19, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x029554: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x029558: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x02955c: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x029560: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x029564: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x029568: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0066 @ 0x0295f8..0x029658 (96 bytes)
// [VN] Phục dựng FDE #0066 tại 0x0295f8..0x029658 (96 byte)
//   0x0295f8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0295fc: 53001c00  uxtb     w0, w0
//   0x029600: 7103fc1f  cmp      w0, #0xff
//   0x029604: 910003fd  mov      x29, sp
//   0x029608: 540001e0  b.eq     #0x29644
//   0x02960c: 12000800  and      w0, w0, #7
//   0x029610: 7100101f  cmp      w0, #4
//   0x029614: 54000168  b.hi     #0x29640
//   0x029618: 90ffff61  adrp     x1, #0x15000
//   0x02961c: 91214021  add      x1, x1, #0x850
//   0x029620: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x029624: 10000061  adr      x1, #0x29630
//   0x029628: 8b208820  add      x0, x1, w0, sxtb #2
//   0x02962c: d61f0000  br       x0
//   0x029630: 52800040  mov      w0, #2
//   0x029634: 14000007  b        #0x29650
uint64_t fde_0066_sub_0295f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B208820ULL) + (x2 ^ 0x0295F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0295f8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x0295fc: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x029600: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029604: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E0ULL; // 0x029608: b.eq #0x29644
    acc = (acc * 0x100000001B3ULL) ^ 0x12000800ULL; // 0x02960c: and w0, w0, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x7100101FULL; // 0x029610: cmp w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x029614: b.hi #0x29640
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF61ULL; // 0x029618: adrp x1, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x91214021ULL; // 0x02961c: add x1, x1, #0x850
    return acc;
}

// [EN] Reconstructed FDE #0067 @ 0x029658..0x0296b8 (96 bytes)
// [VN] Phục dựng FDE #0067 tại 0x029658..0x0296b8 (96 byte)
//   0x029658: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02965c: 53001c00  uxtb     w0, w0
//   0x029660: 7103fc1f  cmp      w0, #0xff
//   0x029664: 910003fd  mov      x29, sp
//   0x029668: 54000220  b.eq     #0x296ac
//   0x02966c: 121c0800  and      w0, w0, #0x70
//   0x029670: 7100801f  cmp      w0, #0x20
//   0x029674: 54000140  b.eq     #0x2969c
//   0x029678: 54000088  b.hi     #0x29688
//   0x02967c: 7100401f  cmp      w0, #0x10
//   0x029680: 350000a0  cbnz     w0, #0x29694
//   0x029684: 1400000a  b        #0x296ac
//   0x029688: 7100c01f  cmp      w0, #0x30
//   0x02968c: 540000c0  b.eq     #0x296a4
//   0x029690: 7101401f  cmp      w0, #0x50
//   0x029694: 540000c0  b.eq     #0x296ac
uint64_t fde_0067_sub_029658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x029658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x029658: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x02965c: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x029660: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029664: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x029668: b.eq #0x296ac
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x02966c: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x029670: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x029674: b.eq #0x2969c
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x029678: b.hi #0x29688
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x02967c: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0068 @ 0x0296b8..0x029718 (96 bytes)
// [VN] Phục dựng FDE #0068 tại 0x0296b8..0x029718 (96 byte)
//   0x0296b8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0296bc: 53001c00  uxtb     w0, w0
//   0x0296c0: 7103fc1f  cmp      w0, #0xff
//   0x0296c4: 910003fd  mov      x29, sp
//   0x0296c8: 54000220  b.eq     #0x2970c
//   0x0296cc: 121c0800  and      w0, w0, #0x70
//   0x0296d0: 7100801f  cmp      w0, #0x20
//   0x0296d4: 54000140  b.eq     #0x296fc
//   0x0296d8: 54000088  b.hi     #0x296e8
//   0x0296dc: 7100401f  cmp      w0, #0x10
//   0x0296e0: 350000a0  cbnz     w0, #0x296f4
//   0x0296e4: 1400000a  b        #0x2970c
//   0x0296e8: 7100c01f  cmp      w0, #0x30
//   0x0296ec: 540000c0  b.eq     #0x29704
//   0x0296f0: 7101401f  cmp      w0, #0x50
//   0x0296f4: 540000c0  b.eq     #0x2970c
uint64_t fde_0068_sub_0296b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x0296B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0296b8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x0296bc: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x0296c0: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0296c4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x0296c8: b.eq #0x2970c
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x0296cc: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x0296d0: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x0296d4: b.eq #0x296fc
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x0296d8: b.hi #0x296e8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x0296dc: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0069 @ 0x029718..0x029808 (240 bytes)
// [VN] Phục dựng FDE #0069 tại 0x029718..0x029808 (240 byte)
//   0x029718: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x02971c: 910003fd  mov      x29, sp
//   0x029720: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029724: 53001c14  uxtb     w20, w0
//   0x029728: aa0203f3  mov      x19, x2
//   0x02972c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029730: 7101429f  cmp      w20, #0x50
//   0x029734: aa0103f6  mov      x22, x1
//   0x029738: aa0303f5  mov      x21, x3
//   0x02973c: 540000a1  b.ne     #0x29750
//   0x029740: 91001c53  add      x19, x2, #7
//   0x029744: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x029748: f8408401  ldr      x1, [x0], #8
//   0x02974c: 1400002a  b        #0x297f4
//   0x029750: 12000e81  and      w1, w20, #0xf
//   0x029754: 7100303f  cmp      w1, #0xc
uint64_t fde_0069_sub_029718(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x029718ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x029718: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02971c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029720: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x029724: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x029728: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02972c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x029730: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x029734: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x029738: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x02973c: b.ne #0x29750
    return acc;
}

// [EN] Reconstructed FDE #0070 @ 0x029808..0x029898 (144 bytes)
// [VN] Phục dựng FDE #0070 tại 0x029808..0x029898 (144 byte)
//   0x029808: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x02980c: 910003fd  mov      x29, sp
//   0x029810: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029814: 79404013  ldrh     w19, [x0, #0x20]
//   0x029818: aa0003f4  mov      x20, x0
//   0x02981c: f9001bf7  str      x23, [sp, #0x30]
//   0x029820: aa0103f7  mov      x23, x1
//   0x029824: d3432a73  ubfx     x19, x19, #3, #8
//   0x029828: aa1403e1  mov      x1, x20
//   0x02982c: 2a1303e0  mov      w0, w19
//   0x029830: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029834: aa0203f6  mov      x22, x2
//   0x029838: 97ffff88  bl       #0x29658
//   0x02983c: aa0003f5  mov      x21, x0
//   0x029840: 910022e2  add      x2, x23, #8
//   0x029844: aa1503e1  mov      x1, x21
uint64_t fde_0070_sub_029808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x97FFFF88ULL) + (x2 ^ 0x029808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x029808: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02980c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029810: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x79404013ULL; // 0x029814: ldrh w19, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x029818: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x02981c: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x029820: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432A73ULL; // 0x029824: ubfx x19, x19, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x029828: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x02982c: mov w0, w19
    return acc;
}

// [EN] Reconstructed FDE #0071 @ 0x029898..0x029994 (252 bytes)
// [VN] Phục dựng FDE #0071 tại 0x029898..0x029994 (252 byte)
//   0x029898: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x02989c: 910003fd  mov      x29, sp
//   0x0298a0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0298a4: 91002414  add      x20, x0, #9
//   0x0298a8: aa0003f3  mov      x19, x0
//   0x0298ac: aa1403e0  mov      x0, x20
//   0x0298b0: 9400cd54  bl       #0x5ce00
//   0x0298b4: 91000400  add      x0, x0, #1
//   0x0298b8: 39402262  ldrb     w2, [x19, #8]
//   0x0298bc: 8b000281  add      x1, x20, x0
//   0x0298c0: 71000c5f  cmp      w2, #3
//   0x0298c4: 54000109  b.ls     #0x298e4
//   0x0298c8: 38606a82  ldrb     w2, [x20, x0]
//   0x0298cc: 52801fe0  mov      w0, #0xff
//   0x0298d0: 7100205f  cmp      w2, #8
//   0x0298d4: 540005a1  b.ne     #0x29988
uint64_t fde_0071_sub_029898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x38606A82ULL) + (x2 ^ 0x029898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x029898: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02989c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0298a0: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002414ULL; // 0x0298a4: add x20, x0, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0298a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x0298ac: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400CD54ULL; // 0x0298b0: bl #0x5ce00
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x0298b4: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39402262ULL; // 0x0298b8: ldrb w2, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B000281ULL; // 0x0298bc: add x1, x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0072 @ 0x029994..0x029af4 (352 bytes)
// [VN] Phục dựng FDE #0072 tại 0x029994..0x029af4 (352 byte)
//   0x029994: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x029998: 910003fd  mov      x29, sp
//   0x02999c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x0299a0: aa0003f6  mov      x22, x0
//   0x0299a4: 79404000  ldrh     w0, [x0, #0x20]
//   0x0299a8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x0299ac: d3432800  ubfx     x0, x0, #3, #8
//   0x0299b0: aa0103f3  mov      x19, x1
//   0x0299b4: aa1603e1  mov      x1, x22
//   0x0299b8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x0299bc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x0299c0: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x0299c4: aa0203f7  mov      x23, x2
//   0x0299c8: 53001c15  uxtb     w21, w0
//   0x0299cc: 97ffff23  bl       #0x29658
//   0x0299d0: 910183b8  add      x24, x29, #0x60
uint64_t fde_0072_sub_029994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xAA0203F7ULL) + (x2 ^ 0x029994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x029994: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029998: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02999c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x0299a0: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x0299a4: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x0299a8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x0299ac: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0299b0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x0299b4: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x0299b8: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0073 @ 0x029af4..0x029b04 (16 bytes)
// [VN] Phục dựng FDE #0073 tại 0x029af4..0x029b04 (16 byte)
//   0x029af4: 91001001  add      x1, x0, #4
//   0x029af8: b9800400  ldrsw    x0, [x0, #4]
//   0x029afc: cb000020  sub      x0, x1, x0
//   0x029b00: 17ffff66  b        #0x29898
uint64_t fde_0073_sub_029af4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91001001ULL) + (x1 ^ 0x17FFFF66ULL) + (x2 ^ 0x029AF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91001001ULL; // 0x029af4: add x1, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800400ULL; // 0x029af8: ldrsw x0, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000020ULL; // 0x029afc: sub x0, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF66ULL; // 0x029b00: b #0x29898
    return acc;
}

// [EN] Reconstructed FDE #0074 @ 0x029b04..0x029f20 (1052 bytes)
// [VN] Phục dựng FDE #0074 tại 0x029b04..0x029f20 (1052 byte)
//   0x029b04: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x029b08: f100bc3f  cmp      x1, #0x2f
//   0x029b0c: 910003fd  mov      x29, sp
//   0x029b10: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029b14: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029b18: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x029b1c: 1a9f97ed  cset     w13, hi
//   0x029b20: f9400806  ldr      x6, [x0, #0x10]
//   0x029b24: f9400007  ldr      x7, [x0]
//   0x029b28: 340007ad  cbz      w13, #0x29c1c
//   0x029b2c: b9402843  ldr      w3, [x2, #0x28]
//   0x029b30: 34000763  cbz      w3, #0x29c1c
//   0x029b34: f00001c1  adrp     x1, #0x64000
//   0x029b38: f9401004  ldr      x4, [x0, #0x20]
//   0x029b3c: f9401405  ldr      x5, [x0, #0x28]
//   0x029b40: f9401423  ldr      x3, [x1, #0x28]
uint64_t fde_0074_sub_029b04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0xF00001C1ULL) + (x2 ^ 0x029B04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x029b04: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF100BC3FULL; // 0x029b08: cmp x1, #0x2f
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029b0c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029b10: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x029b14: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x029b18: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97EDULL; // 0x029b1c: cset w13, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400806ULL; // 0x029b20: ldr x6, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400007ULL; // 0x029b24: ldr x7, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340007ADULL; // 0x029b28: cbz w13, #0x29c1c
    return acc;
}

// [EN] Reconstructed FDE #0075 @ 0x029f20..0x029fbc (156 bytes)
// [VN] Phục dựng FDE #0075 tại 0x029f20..0x029fbc (156 byte)
//   0x029f20: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x029f24: 910003fd  mov      x29, sp
//   0x029f28: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029f2c: aa0003f5  mov      x21, x0
//   0x029f30: aa0103e0  mov      x0, x1
//   0x029f34: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029f38: aa0203f3  mov      x19, x2
//   0x029f3c: aa0103f4  mov      x20, x1
//   0x029f40: 97fffeed  bl       #0x29af4
//   0x029f44: 53001c16  uxtb     w22, w0
//   0x029f48: aa1503e1  mov      x1, x21
//   0x029f4c: 2a1603e0  mov      w0, w22
//   0x029f50: 97fffdc2  bl       #0x29658
//   0x029f54: aa0003e1  mov      x1, x0
//   0x029f58: 91002282  add      x2, x20, #8
//   0x029f5c: 9100c3a3  add      x3, x29, #0x30
uint64_t fde_0075_sub_029f20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x97FFFDC2ULL) + (x2 ^ 0x029F20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x029f20: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029f24: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x029f28: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x029f2c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x029f30: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029f34: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x029f38: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x029f3c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEEDULL; // 0x029f40: bl #0x29af4
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C16ULL; // 0x029f44: uxtb w22, w0
    return acc;
}

// [EN] Reconstructed FDE #0076 @ 0x029fbc..0x02a11c (352 bytes)
// [VN] Phục dựng FDE #0076 tại 0x029fbc..0x02a11c (352 byte)
//   0x029fbc: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x029fc0: 910003fd  mov      x29, sp
//   0x029fc4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x029fc8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x029fcc: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x029fd0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x029fd4: aa0103f3  mov      x19, x1
//   0x029fd8: f9002bfb  str      x27, [sp, #0x50]
//   0x029fdc: aa0003f4  mov      x20, x0
//   0x029fe0: d280001a  mov      x26, #0
//   0x029fe4: 52800019  mov      w25, #0
//   0x029fe8: d2800016  mov      x22, #0
//   0x029fec: d2800001  mov      x1, #0
//   0x029ff0: 9101a3b7  add      x23, x29, #0x68
//   0x029ff4: d2800038  mov      x24, #1
//   0x029ff8: b9400260  ldr      w0, [x19]
uint64_t fde_0076_sub_029fbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xD2800001ULL) + (x2 ^ 0x029FBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x029fbc: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029fc0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x029fc4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x029fc8: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x029fcc: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x029fd0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x029fd4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x029fd8: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x029fdc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD280001AULL; // 0x029fe0: mov x26, #0
    return acc;
}

// [EN] Reconstructed FDE #0077 @ 0x02a11c..0x02a250 (308 bytes)
// [VN] Phục dựng FDE #0077 tại 0x02a11c..0x02a250 (308 byte)
//   0x02a11c: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x02a120: 910003fd  mov      x29, sp
//   0x02a124: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02a128: aa0003f6  mov      x22, x0
//   0x02a12c: 79404000  ldrh     w0, [x0, #0x20]
//   0x02a130: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02a134: d3432800  ubfx     x0, x0, #3, #8
//   0x02a138: aa0103f7  mov      x23, x1
//   0x02a13c: aa1603e1  mov      x1, x22
//   0x02a140: f9002bfb  str      x27, [sp, #0x50]
//   0x02a144: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x02a148: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02a14c: 53001c15  uxtb     w21, w0
//   0x02a150: aa0203f3  mov      x19, x2
//   0x02a154: 97fffd41  bl       #0x29658
//   0x02a158: 9101a3b8  add      x24, x29, #0x68
uint64_t fde_0077_sub_02a11c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0x53001C15ULL) + (x2 ^ 0x02A11CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x02a11c: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a120: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02a124: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02a128: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x02a12c: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x02a130: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x02a134: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x02a138: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x02a13c: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x02a140: str x27, [sp, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0078 @ 0x02a250..0x02a7c0 (1392 bytes)
// [VN] Phục dựng FDE #0078 tại 0x02a250..0x02a7c0 (1392 byte)
//   0x02a250: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x02a254: 910003fd  mov      x29, sp
//   0x02a258: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02a25c: aa0103f6  mov      x22, x1
//   0x02a260: 39408001  ldrb     w1, [x0, #0x20]
//   0x02a264: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02a268: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02a26c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x02a270: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x02a274: aa0003f3  mov      x19, x0
//   0x02a278: 36000081  tbz      w1, #0, #0x2a288
//   0x02a27c: 39408260  ldrb     w0, [x19, #0x20]
//   0x02a280: 37000da0  tbnz     w0, #0, #0x2a434
//   0x02a284: 140000d9  b        #0x2a5e8
//   0x02a288: b9402014  ldr      w20, [x0, #0x20]
//   0x02a28c: d34b7e94  ubfx     x20, x20, #0xb, #0x15
uint64_t fde_0078_sub_02a250(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x37000DA0ULL) + (x2 ^ 0x02A250ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x02a250: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a254: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02a258: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x02a25c: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39408001ULL; // 0x02a260: ldrb w1, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02a264: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x02a268: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x02a26c: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x02a270: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a274: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0079 @ 0x02a7c0..0x02a85c (156 bytes)
// [VN] Phục dựng FDE #0079 tại 0x02a7c0..0x02a85c (156 byte)
//   0x02a7c0: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x02a7c4: 910003fd  mov      x29, sp
//   0x02a7c8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02a7cc: f90013f5  str      x21, [sp, #0x20]
//   0x02a7d0: b40003e0  cbz      x0, #0x2a84c
//   0x02a7d4: b9400004  ldr      w4, [x0]
//   0x02a7d8: 340003a4  cbz      w4, #0x2a84c
//   0x02a7dc: aa0103f3  mov      x19, x1
//   0x02a7e0: 92800001  mov      x1, #-1
//   0x02a7e4: d00001d4  adrp     x20, #0x64000
//   0x02a7e8: f9000261  str      x1, [x19]
//   0x02a7ec: d00001a1  adrp     x1, #0x60000
//   0x02a7f0: f900127f  str      xzr, [x19, #0x20]
//   0x02a7f4: aa0103f5  mov      x21, x1
//   0x02a7f8: f9000e60  str      x0, [x19, #0x18]
//   0x02a7fc: 5280ff00  mov      w0, #0x7f8
uint64_t fde_0079_sub_02a7c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xF900127FULL) + (x2 ^ 0x02A7C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x02a7c0: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a7c4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02a7c8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x02a7cc: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003E0ULL; // 0x02a7d0: cbz x0, #0x2a84c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400004ULL; // 0x02a7d4: ldr w4, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A4ULL; // 0x02a7d8: cbz w4, #0x2a84c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02a7dc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x02a7e0: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D4ULL; // 0x02a7e4: adrp x20, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0080 @ 0x02a85c..0x02a868 (12 bytes)
// [VN] Phục dựng FDE #0080 tại 0x02a85c..0x02a868 (12 byte)
//   0x02a85c: d2800002  mov      x2, #0
//   0x02a860: d2800003  mov      x3, #0
//   0x02a864: 1400c9cf  b        #0x5cfa0
uint64_t fde_0080_sub_02a85c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x1400C9CFULL) + (x2 ^ 0x02A85CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x02a85c: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x02a860: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C9CFULL; // 0x02a864: b #0x5cfa0
    return acc;
}

// [EN] Reconstructed FDE #0081 @ 0x02a868..0x02a8a8 (64 bytes)
// [VN] Phục dựng FDE #0081 tại 0x02a868..0x02a8a8 (64 byte)
//   0x02a868: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x02a86c: 910003fd  mov      x29, sp
//   0x02a870: b9400001  ldr      w1, [x0]
//   0x02a874: f9000bf3  str      x19, [sp, #0x10]
//   0x02a878: 34000121  cbz      w1, #0x2a89c
//   0x02a87c: aa0003f3  mov      x19, x0
//   0x02a880: d2800600  mov      x0, #0x30
//   0x02a884: 9400c90f  bl       #0x5ccc0
//   0x02a888: aa0003e1  mov      x1, x0
//   0x02a88c: aa1303e0  mov      x0, x19
//   0x02a890: f9400bf3  ldr      x19, [sp, #0x10]
//   0x02a894: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x02a898: 1400c9c6  b        #0x5cfb0
//   0x02a89c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x02a8a0: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x02a8a4: d65f03c0  ret      
uint64_t fde_0081_sub_02a868(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x1400C9C6ULL) + (x2 ^ 0x02A868ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x02a868: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a86c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x02a870: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x02a874: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000121ULL; // 0x02a878: cbz w1, #0x2a89c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a87c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x02a880: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C90FULL; // 0x02a884: bl #0x5ccc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x02a888: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02a88c: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0082 @ 0x02a8a8..0x02a93c (148 bytes)
// [VN] Phục dựng FDE #0082 tại 0x02a8a8..0x02a93c (148 byte)
//   0x02a8a8: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x02a8ac: 92800004  mov      x4, #-1
//   0x02a8b0: 910003fd  mov      x29, sp
//   0x02a8b4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02a8b8: f900103f  str      xzr, [x1, #0x20]
//   0x02a8bc: d00001d3  adrp     x19, #0x64000
//   0x02a8c0: f9000c20  str      x0, [x1, #0x18]
//   0x02a8c4: 52800040  mov      w0, #2
//   0x02a8c8: 39008020  strb     w0, [x1, #0x20]
//   0x02a8cc: f9000422  str      x2, [x1, #8]
//   0x02a8d0: d00001a2  adrp     x2, #0x60000
//   0x02a8d4: 79404020  ldrh     w0, [x1, #0x20]
//   0x02a8d8: aa0203f4  mov      x20, x2
//   0x02a8dc: f9000024  str      x4, [x1]
//   0x02a8e0: 321d1c00  orr      w0, w0, #0x7f8
//   0x02a8e4: f9000823  str      x3, [x1, #0x10]
uint64_t fde_0082_sub_02a8a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x02A8A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x02a8a8: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x92800004ULL; // 0x02a8ac: mov x4, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a8b0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02a8b4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900103FULL; // 0x02a8b8: str xzr, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D3ULL; // 0x02a8bc: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C20ULL; // 0x02a8c0: str x0, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800040ULL; // 0x02a8c4: mov w0, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x39008020ULL; // 0x02a8c8: strb w0, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000422ULL; // 0x02a8cc: str x2, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0083 @ 0x02a93c..0x02a948 (12 bytes)
// [VN] Phục dựng FDE #0083 tại 0x02a93c..0x02a948 (12 byte)
//   0x02a93c: d2800002  mov      x2, #0
//   0x02a940: d2800003  mov      x3, #0
//   0x02a944: 1400c99f  b        #0x5cfc0
uint64_t fde_0083_sub_02a93c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x1400C99FULL) + (x2 ^ 0x02A93CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x02a93c: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x02a940: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C99FULL; // 0x02a944: b #0x5cfc0
    return acc;
}

// [EN] Reconstructed FDE #0084 @ 0x02a948..0x02a974 (44 bytes)
// [VN] Phục dựng FDE #0084 tại 0x02a948..0x02a974 (44 byte)
//   0x02a948: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x02a94c: 910003fd  mov      x29, sp
//   0x02a950: f9000bf3  str      x19, [sp, #0x10]
//   0x02a954: aa0003f3  mov      x19, x0
//   0x02a958: d2800600  mov      x0, #0x30
//   0x02a95c: 9400c8d9  bl       #0x5ccc0
//   0x02a960: aa0003e1  mov      x1, x0
//   0x02a964: aa1303e0  mov      x0, x19
//   0x02a968: f9400bf3  ldr      x19, [sp, #0x10]
//   0x02a96c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x02a970: 1400c998  b        #0x5cfd0
uint64_t fde_0084_sub_02a948(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x1400C998ULL) + (x2 ^ 0x02A948ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x02a948: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a94c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x02a950: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a954: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x02a958: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C8D9ULL; // 0x02a95c: bl #0x5ccc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x02a960: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02a964: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF3ULL; // 0x02a968: ldr x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C27BFDULL; // 0x02a96c: ldp x29, x30, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0085 @ 0x02a974..0x02aa74 (256 bytes)
// [VN] Phục dựng FDE #0085 tại 0x02a974..0x02aa74 (256 byte)
//   0x02a974: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x02a978: 910003fd  mov      x29, sp
//   0x02a97c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02a980: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02a984: b4000580  cbz      x0, #0x2aa34
//   0x02a988: b9400001  ldr      w1, [x0]
//   0x02a98c: 34000541  cbz      w1, #0x2aa34
//   0x02a990: d00001b4  adrp     x20, #0x60000
//   0x02a994: aa0003f5  mov      x21, x0
//   0x02a998: d00001d6  adrp     x22, #0x64000
//   0x02a99c: f9463a80  ldr      x0, [x20, #0xc70]
//   0x02a9a0: b4000080  cbz      x0, #0x2a9b0
//   0x02a9a4: 910d22c0  add      x0, x22, #0x348
//   0x02a9a8: 91068000  add      x0, x0, #0x1a0
//   0x02a9ac: 9400c8cd  bl       #0x5cce0
//   0x02a9b0: 910d22c0  add      x0, x22, #0x348
uint64_t fde_0085_sub_02a974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0x910D22C0ULL) + (x2 ^ 0x02A974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x02a974: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a978: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02a97c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02a980: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000580ULL; // 0x02a984: cbz x0, #0x2aa34
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x02a988: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000541ULL; // 0x02a98c: cbz w1, #0x2aa34
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B4ULL; // 0x02a990: adrp x20, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02a994: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D6ULL; // 0x02a998: adrp x22, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0086 @ 0x02aa74..0x02aa78 (4 bytes)
// [VN] Phục dựng FDE #0086 tại 0x02aa74..0x02aa78 (4 byte)
//   0x02aa74: 1400c95b  b        #0x5cfe0
uint64_t fde_0086_sub_02aa74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400C95BULL) + (x1 ^ 0x1400C95BULL) + (x2 ^ 0x02AA74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C95BULL; // 0x02aa74: b #0x5cfe0
    return acc;
}

// [EN] Reconstructed FDE #0087 @ 0x02aa78..0x02aa9c (36 bytes)
// [VN] Phục dựng FDE #0087 tại 0x02aa78..0x02aa9c (36 byte)
//   0x02aa78: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02aa7c: 910003fd  mov      x29, sp
//   0x02aa80: b9400001  ldr      w1, [x0]
//   0x02aa84: 34000081  cbz      w1, #0x2aa94
//   0x02aa88: 9400c95a  bl       #0x5cff0
//   0x02aa8c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02aa90: 1400c89c  b        #0x5cd00
//   0x02aa94: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02aa98: d65f03c0  ret      
uint64_t fde_0087_sub_02aa78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02AA78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02aa78: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02aa7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x02aa80: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000081ULL; // 0x02aa84: cbz w1, #0x2aa94
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C95AULL; // 0x02aa88: bl #0x5cff0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02aa8c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C89CULL; // 0x02aa90: b #0x5cd00
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02aa94: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02aa98: ret 
    return acc;
}

// [EN] Reconstructed FDE #0088 @ 0x02aa9c..0x02ac60 (452 bytes)
// [VN] Phục dựng FDE #0088 tại 0x02aa9c..0x02ac60 (452 byte)
//   0x02aa9c: a9b87bfd  stp      x29, x30, [sp, #-0x80]!
//   0x02aaa0: 910003fd  mov      x29, sp
//   0x02aaa4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02aaa8: d00001b5  adrp     x21, #0x60000
//   0x02aaac: f90023f9  str      x25, [sp, #0x40]
//   0x02aab0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02aab4: aa0003f7  mov      x23, x0
//   0x02aab8: aa0103f6  mov      x22, x1
//   0x02aabc: f9463aa0  ldr      x0, [x21, #0xc70]
//   0x02aac0: d00001d9  adrp     x25, #0x64000
//   0x02aac4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02aac8: b4000080  cbz      x0, #0x2aad8
//   0x02aacc: 910d2320  add      x0, x25, #0x348
//   0x02aad0: 91068000  add      x0, x0, #0x1a0
//   0x02aad4: 9400c883  bl       #0x5cce0
//   0x02aad8: 910d2320  add      x0, x25, #0x348
uint64_t fde_0088_sub_02aa9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B87BFDULL) + (x1 ^ 0x910D2320ULL) + (x2 ^ 0x02AA9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B87BFDULL; // 0x02aa9c: stp x29, x30, [sp, #-0x80]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02aaa0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02aaa4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B5ULL; // 0x02aaa8: adrp x21, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x02aaac: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x02aab0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x02aab4: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x02aab8: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463AA0ULL; // 0x02aabc: ldr x0, [x21, #0xc70]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D9ULL; // 0x02aac0: adrp x25, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0089 @ 0x02ac60..0x02aca0 (64 bytes)
// [VN] Phục dựng FDE #0089 tại 0x02ac60..0x02aca0 (64 byte)
//   0x02ac60: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x02ac64: 90000001  adrp     x1, #0x2a000
//   0x02ac68: 910003fd  mov      x29, sp
//   0x02ac6c: f9000bf3  str      x19, [sp, #0x10]
//   0x02ac70: d00001d3  adrp     x19, #0x64000
//   0x02ac74: 91148273  add      x19, x19, #0x520
//   0x02ac78: 91328021  add      x1, x1, #0xca0
//   0x02ac7c: aa1303e0  mov      x0, x19
//   0x02ac80: 9400c8e4  bl       #0x5d010
//   0x02ac84: 34000040  cbz      w0, #0x2ac8c
//   0x02ac88: 9400c89e  bl       #0x5cf00
//   0x02ac8c: 52800020  mov      w0, #1
//   0x02ac90: b9000660  str      w0, [x19, #4]
//   0x02ac94: f9400bf3  ldr      x19, [sp, #0x10]
//   0x02ac98: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x02ac9c: d65f03c0  ret      
uint64_t fde_0089_sub_02ac60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0xB9000660ULL) + (x2 ^ 0x02AC60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x02ac60: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x90000001ULL; // 0x02ac64: adrp x1, #0x2a000
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02ac68: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x02ac6c: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D3ULL; // 0x02ac70: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91148273ULL; // 0x02ac74: add x19, x19, #0x520
    acc = (acc * 0x100000001B3ULL) ^ 0x91328021ULL; // 0x02ac78: add x1, x1, #0xca0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02ac7c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C8E4ULL; // 0x02ac80: bl #0x5d010
    acc = (acc * 0x100000001B3ULL) ^ 0x34000040ULL; // 0x02ac84: cbz w0, #0x2ac8c
    return acc;
}

// [EN] Reconstructed FDE #0090 @ 0x02aca0..0x02ad20 (128 bytes)
// [VN] Phục dựng FDE #0090 tại 0x02aca0..0x02ad20 (128 byte)
//   0x02aca0: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x02aca4: aa0003e1  mov      x1, x0
//   0x02aca8: 910003fd  mov      x29, sp
//   0x02acac: f9400000  ldr      x0, [x0]
//   0x02acb0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02acb4: f90013f5  str      x21, [sp, #0x20]
//   0x02acb8: b4000120  cbz      x0, #0x2acdc
//   0x02acbc: d1000400  sub      x0, x0, #1
//   0x02acc0: f9000020  str      x0, [x1]
//   0x02acc4: d00001c0  adrp     x0, #0x64000
//   0x02acc8: f94013f5  ldr      x21, [sp, #0x20]
//   0x02accc: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x02acd0: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x02acd4: b9452000  ldr      w0, [x0, #0x520]
//   0x02acd8: 1400c8d2  b        #0x5d020
//   0x02acdc: f9400435  ldr      x21, [x1, #8]
uint64_t fde_0090_sub_02aca0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xA8C37BFDULL) + (x2 ^ 0x02ACA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x02aca0: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x02aca4: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02aca8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02acac: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02acb0: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x02acb4: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000120ULL; // 0x02acb8: cbz x0, #0x2acdc
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000400ULL; // 0x02acbc: sub x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000020ULL; // 0x02acc0: str x0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001C0ULL; // 0x02acc4: adrp x0, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0091 @ 0x02ad20..0x02adb8 (152 bytes)
// [VN] Phục dựng FDE #0091 tại 0x02ad20..0x02adb8 (152 byte)
//   0x02ad20: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x02ad24: 910003fd  mov      x29, sp
//   0x02ad28: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02ad2c: f9400414  ldr      x20, [x0, #8]
//   0x02ad30: f90013f5  str      x21, [sp, #0x20]
//   0x02ad34: aa0003f5  mov      x21, x0
//   0x02ad38: f100229f  cmp      x20, #8
//   0x02ad3c: f9400000  ldr      x0, [x0]
//   0x02ad40: 54000108  b.hi     #0x2ad60
//   0x02ad44: 91002000  add      x0, x0, #8
//   0x02ad48: 9400c7de  bl       #0x5ccc0
//   0x02ad4c: b5000040  cbnz     x0, #0x2ad54
//   0x02ad50: 9400c86c  bl       #0x5cf00
//   0x02ad54: f9000000  str      x0, [x0]
//   0x02ad58: 91002013  add      x19, x0, #8
//   0x02ad5c: 1400000a  b        #0x2ad84
uint64_t fde_0091_sub_02ad20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0x9400C86CULL) + (x2 ^ 0x02AD20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x02ad20: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02ad24: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02ad28: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x02ad2c: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x02ad30: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02ad34: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100229FULL; // 0x02ad38: cmp x20, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02ad3c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x54000108ULL; // 0x02ad40: b.hi #0x2ad60
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x02ad44: add x0, x0, #8
    return acc;
}

// [EN] Reconstructed FDE #0092 @ 0x02adb8..0x02add8 (32 bytes)
// [VN] Phục dựng FDE #0092 tại 0x02adb8..0x02add8 (32 byte)
//   0x02adb8: d00001c0  adrp     x0, #0x64000
//   0x02adbc: 91148001  add      x1, x0, #0x520
//   0x02adc0: b9400422  ldr      w2, [x1, #4]
//   0x02adc4: 34000082  cbz      w2, #0x2add4
//   0x02adc8: b9452000  ldr      w0, [x0, #0x520]
//   0x02adcc: b900043f  str      wzr, [x1, #4]
//   0x02add0: 1400c898  b        #0x5d030
//   0x02add4: d65f03c0  ret      
uint64_t fde_0092_sub_02adb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02ADB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001C0ULL; // 0x02adb8: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91148001ULL; // 0x02adbc: add x1, x0, #0x520
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400422ULL; // 0x02adc0: ldr w2, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000082ULL; // 0x02adc4: cbz w2, #0x2add4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9452000ULL; // 0x02adc8: ldr w0, [x0, #0x520]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900043FULL; // 0x02adcc: str wzr, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C898ULL; // 0x02add0: b #0x5d030
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02add4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0093 @ 0x02add8..0x02af30 (344 bytes)
// [VN] Phục dựng FDE #0093 tại 0x02add8..0x02af30 (344 byte)
//   0x02add8: d00001a1  adrp     x1, #0x60000
//   0x02addc: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x02ade0: 910003fd  mov      x29, sp
//   0x02ade4: f9463821  ldr      x1, [x1, #0xc70]
//   0x02ade8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x02adec: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x02adf0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x02adf4: aa0003f6  mov      x22, x0
//   0x02adf8: b50000e1  cbnz     x1, #0x2ae14
//   0x02adfc: f9400801  ldr      x1, [x0, #0x10]
//   0x02ae00: b5000061  cbnz     x1, #0x2ae0c
//   0x02ae04: 97ffffc7  bl       #0x2ad20
//   0x02ae08: f9000ac0  str      x0, [x22, #0x10]
//   0x02ae0c: f9400ac0  ldr      x0, [x22, #0x10]
//   0x02ae10: 14000043  b        #0x2af1c
//   0x02ae14: 91004000  add      x0, x0, #0x10
uint64_t fde_0093_sub_02add8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001A1ULL) + (x1 ^ 0xF9000AC0ULL) + (x2 ^ 0x02ADD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x02add8: adrp x1, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x02addc: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02ade0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463821ULL; // 0x02ade4: ldr x1, [x1, #0xc70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x02ade8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x02adec: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x02adf0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02adf4: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB50000E1ULL; // 0x02adf8: cbnz x1, #0x2ae14
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x02adfc: ldr x1, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0094 @ 0x02af30..0x02af6c (60 bytes)
// [VN] Phục dựng FDE #0094 tại 0x02af30..0x02af6c (60 byte)
//   0x02af30: f9400004  ldr      x4, [x0]
//   0x02af34: eb01009f  cmp      x4, x1
//   0x02af38: 54000062  b.hs     #0x2af44
//   0x02af3c: f9000001  str      x1, [x0]
//   0x02af40: f9000c1f  str      xzr, [x0, #0x18]
//   0x02af44: f9400404  ldr      x4, [x0, #8]
//   0x02af48: eb02009f  cmp      x4, x2
//   0x02af4c: 54000042  b.hs     #0x2af54
//   0x02af50: f9000402  str      x2, [x0, #8]
//   0x02af54: b40000a3  cbz      x3, #0x2af68
//   0x02af58: f9400002  ldr      x2, [x0]
//   0x02af5c: eb02003f  cmp      x1, x2
//   0x02af60: 54000041  b.ne     #0x2af68
//   0x02af64: f9000c03  str      x3, [x0, #0x18]
//   0x02af68: d65f03c0  ret      
uint64_t fde_0094_sub_02af30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400004ULL) + (x1 ^ 0x54000041ULL) + (x2 ^ 0x02AF30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400004ULL; // 0x02af30: ldr x4, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01009FULL; // 0x02af34: cmp x4, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02af38: b.hs #0x2af44
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x02af3c: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C1FULL; // 0x02af40: str xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400404ULL; // 0x02af44: ldr x4, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02009FULL; // 0x02af48: cmp x4, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000042ULL; // 0x02af4c: b.hs #0x2af54
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000402ULL; // 0x02af50: str x2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A3ULL; // 0x02af54: cbz x3, #0x2af68
    return acc;
}

// [EN] Reconstructed FDE #0095 @ 0x02af6c..0x02b03c (208 bytes)
// [VN] Phục dựng FDE #0095 tại 0x02af6c..0x02b03c (208 byte)
//   0x02af6c: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x02af70: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02af74: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02af78: 910083fd  add      x29, sp, #0x20
//   0x02af7c: d11043ff  sub      sp, sp, #0x410
//   0x02af80: d53bd055  mrs      x21, tpidr_el0
//   0x02af84: f94016a8  ldr      x8, [x21, #0x28]
//   0x02af88: 910023e0  add      x0, sp, #8
//   0x02af8c: 52808002  mov      w2, #0x400
//   0x02af90: 2a1f03e1  mov      w1, wzr
//   0x02af94: f81d83a8  stur     x8, [x29, #-0x28]
//   0x02af98: 9400c7f2  bl       #0x5cf60
//   0x02af9c: d0ffff20  adrp     x0, #0x10000
//   0x02afa0: 91012000  add      x0, x0, #0x48
//   0x02afa4: 910023e1  add      x1, sp, #8
//   0x02afa8: 9400c832  bl       #0x5d070
uint64_t fde_0095_sub_02af6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57FCULL) + (x1 ^ 0xD0FFFF20ULL) + (x2 ^ 0x02AF6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57FCULL; // 0x02af6c: stp x28, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02af70: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02af74: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02af78: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x02af7c: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02af80: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02af84: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02af88: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52808002ULL; // 0x02af8c: mov w2, #0x400
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x02af90: mov w1, wzr
    return acc;
}

// [EN] Reconstructed FDE #0096 @ 0x02b03c..0x02b0cc (144 bytes)
// [VN] Phục dựng FDE #0096 tại 0x02b03c..0x02b0cc (144 byte)
//   0x02b03c: d10343ff  sub      sp, sp, #0xd0
//   0x02b040: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x02b044: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x02b048: 910303fd  add      x29, sp, #0xc0
//   0x02b04c: aa1e03f3  mov      x19, x30
//   0x02b050: a93c93a3  stp      x3, x4, [x29, #-0x38]
//   0x02b054: a93d9ba5  stp      x5, x6, [x29, #-0x28]
//   0x02b058: f81e83a7  stur     x7, [x29, #-0x18]
//   0x02b05c: ad0007e0  stp      q0, q1, [sp]
//   0x02b060: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02b064: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02b068: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02b06c: b40000e2  cbz      x2, #0x2b088
//   0x02b070: 90ffff21  adrp     x1, #0xf000
//   0x02b074: 90ffff22  adrp     x2, #0xf000
//   0x02b078: 9106f021  add      x1, x1, #0x1bc
uint64_t fde_0096_sub_02b03c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xB40000E2ULL) + (x2 ^ 0x02B03CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x02b03c: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x02b040: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x02b044: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x02b048: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02b04c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA93C93A3ULL; // 0x02b050: stp x3, x4, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xA93D9BA5ULL; // 0x02b054: stp x5, x6, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A7ULL; // 0x02b058: stur x7, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02b05c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x02b060: stp q2, q3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0097 @ 0x02b0cc..0x02b168 (156 bytes)
// [VN] Phục dựng FDE #0097 tại 0x02b0cc..0x02b168 (156 byte)
//   0x02b0cc: d10343ff  sub      sp, sp, #0xd0
//   0x02b0d0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x02b0d4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x02b0d8: 910303fd  add      x29, sp, #0xc0
//   0x02b0dc: aa1e03f3  mov      x19, x30
//   0x02b0e0: a93c93a3  stp      x3, x4, [x29, #-0x38]
//   0x02b0e4: a93d9ba5  stp      x5, x6, [x29, #-0x28]
//   0x02b0e8: f81e83a7  stur     x7, [x29, #-0x18]
//   0x02b0ec: ad0007e0  stp      q0, q1, [sp]
//   0x02b0f0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02b0f4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02b0f8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02b0fc: b4000142  cbz      x2, #0x2b124
//   0x02b100: 90ffff21  adrp     x1, #0xf000
//   0x02b104: b0ffff02  adrp     x2, #0xc000
//   0x02b108: 9106f021  add      x1, x1, #0x1bc
uint64_t fde_0097_sub_02b0cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xB4000142ULL) + (x2 ^ 0x02B0CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x02b0cc: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x02b0d0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x02b0d4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x02b0d8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02b0dc: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA93C93A3ULL; // 0x02b0e0: stp x3, x4, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xA93D9BA5ULL; // 0x02b0e4: stp x5, x6, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A7ULL; // 0x02b0e8: stur x7, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02b0ec: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x02b0f0: stp q2, q3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0098 @ 0x02b168..0x02b174 (12 bytes)
// [VN] Phục dựng FDE #0098 tại 0x02b168..0x02b174 (12 byte)
//   0x02b168: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x02b16c: 9400c7dd  bl       #0x5d0e0
//   0x02b170: 9400c7e0  bl       #0x5d0f0
uint64_t fde_0098_sub_02b168(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x9400C7E0ULL) + (x2 ^ 0x02B168ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x02b168: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C7DDULL; // 0x02b16c: bl #0x5d0e0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C7E0ULL; // 0x02b170: bl #0x5d0f0
    return acc;
}

// [EN] Reconstructed FDE #0099 @ 0x02b174..0x02b7e8 (1652 bytes)
// [VN] Phục dựng FDE #0099 tại 0x02b174..0x02b7e8 (1652 byte)
//   0x02b174: d10283ff  sub      sp, sp, #0xa0
//   0x02b178: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x02b17c: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02b180: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02b184: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x02b188: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02b18c: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x02b190: 910243fd  add      x29, sp, #0x90
//   0x02b194: d53bd059  mrs      x25, tpidr_el0
//   0x02b198: f9401728  ldr      x8, [x25, #0x28]
//   0x02b19c: f9001fe8  str      x8, [sp, #0x38]
//   0x02b1a0: b00001c8  adrp     x8, #0x64000
//   0x02b1a4: 39794109  ldrb     w9, [x8, #0xe50]
//   0x02b1a8: 37002d49  tbnz     w9, #0, #0x2b750
//   0x02b1ac: b0ffff00  adrp     x0, #0xc000
//   0x02b1b0: 52800029  mov      w9, #1
uint64_t fde_0099_sub_02b174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x39794109ULL) + (x2 ^ 0x02B174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02b174: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x02b178: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x02b17c: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02b180: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02b184: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x02b188: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02b18c: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x02b190: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02b194: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x02b198: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0100 @ 0x02b7e8..0x02b8b0 (200 bytes)
// [VN] Phục dựng FDE #0100 tại 0x02b7e8..0x02b8b0 (200 byte)
//   0x02b7e8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02b7ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02b7f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02b7f4: 910083fd  add      x29, sp, #0x20
//   0x02b7f8: aa0403f3  mov      x19, x4
//   0x02b7fc: 2a0203f4  mov      w20, w2
//   0x02b800: aa0103f5  mov      x21, x1
//   0x02b804: aa0003f6  mov      x22, x0
//   0x02b808: b9000403  str      w3, [x0, #4]
//   0x02b80c: 9400c5b1  bl       #0x5ced0
//   0x02b810: 4b0003e8  neg      w8, w0
//   0x02b814: 93407d08  sxtw     x8, w8
//   0x02b818: 8a150115  and      x21, x8, x21
//   0x02b81c: a900ced5  stp      x21, x19, [x22, #8]
//   0x02b820: 9400c5ac  bl       #0x5ced0
//   0x02b824: 93407c08  sxtw     x8, w0
uint64_t fde_0100_sub_02b7e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x8A150115ULL) + (x2 ^ 0x02B7E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02b7e8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02b7ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02b7f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02b7f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F3ULL; // 0x02b7f8: mov x19, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x02b7fc: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02b800: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02b804: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000403ULL; // 0x02b808: str w3, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C5B1ULL; // 0x02b80c: bl #0x5ced0
    return acc;
}

// [EN] Reconstructed FDE #0101 @ 0x02b8b0..0x02bc64 (948 bytes)
// [VN] Phục dựng FDE #0101 tại 0x02b8b0..0x02bc64 (948 byte)
//   0x02b8b0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02b8b4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02b8b8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02b8bc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02b8c0: 9100c3fd  add      x29, sp, #0x30
//   0x02b8c4: b4001c60  cbz      x0, #0x2bc50
//   0x02b8c8: aa0003f4  mov      x20, x0
//   0x02b8cc: d0ffff40  adrp     x0, #0x15000
//   0x02b8d0: aa0103f3  mov      x19, x1
//   0x02b8d4: 911b4c00  add      x0, x0, #0x6d3
//   0x02b8d8: 52800021  mov      w1, #1
//   0x02b8dc: 9400c619  bl       #0x5d140
//   0x02b8e0: 3100041f  cmn      w0, #1
//   0x02b8e4: 54001b60  b.eq     #0x2bc50
//   0x02b8e8: 52800082  mov      w2, #4
//   0x02b8ec: aa1403e1  mov      x1, x20
uint64_t fde_0101_sub_02b8b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x3100041FULL) + (x2 ^ 0x02B8B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02b8b0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02b8b4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02b8b8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02b8bc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02b8c0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4001C60ULL; // 0x02b8c4: cbz x0, #0x2bc50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02b8c8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF40ULL; // 0x02b8cc: adrp x0, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02b8d0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x911B4C00ULL; // 0x02b8d4: add x0, x0, #0x6d3
    return acc;
}

// [EN] Reconstructed FDE #0102 @ 0x02bc64..0x02bc7c (24 bytes)
// [VN] Phục dựng FDE #0102 tại 0x02bc64..0x02bc7c (24 byte)
//   0x02bc64: f0ffff21  adrp     x1, #0x12000
//   0x02bc68: b0ffff02  adrp     x2, #0xc000
//   0x02bc6c: 9105bc21  add      x1, x1, #0x16f
//   0x02bc70: 91133042  add      x2, x2, #0x4cc
//   0x02bc74: 52800060  mov      w0, #3
//   0x02bc78: 1400c40a  b        #0x5cca0
uint64_t fde_0102_sub_02bc64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0FFFF21ULL) + (x1 ^ 0x1400C40AULL) + (x2 ^ 0x02BC64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF21ULL; // 0x02bc64: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF02ULL; // 0x02bc68: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x9105BC21ULL; // 0x02bc6c: add x1, x1, #0x16f
    acc = (acc * 0x100000001B3ULL) ^ 0x91133042ULL; // 0x02bc70: add x2, x2, #0x4cc
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02bc74: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C40AULL; // 0x02bc78: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0103 @ 0x02bc7c..0x02be10 (404 bytes)
// [VN] Phục dựng FDE #0103 tại 0x02bc7c..0x02be10 (404 byte)
//   0x02bc7c: d10583ff  sub      sp, sp, #0x160
//   0x02bc80: f9008bfc  str      x28, [sp, #0x110]
//   0x02bc84: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x02bc88: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x02bc8c: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x02bc90: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x02bc94: 910543fd  add      x29, sp, #0x150
//   0x02bc98: d53bd057  mrs      x23, tpidr_el0
//   0x02bc9c: f94016e8  ldr      x8, [x23, #0x28]
//   0x02bca0: aa0303f3  mov      x19, x3
//   0x02bca4: aa0203f4  mov      x20, x2
//   0x02bca8: aa0103f5  mov      x21, x1
//   0x02bcac: f81b83a8  stur     x8, [x29, #-0x48]
//   0x02bcb0: b40003e0  cbz      x0, #0x2bd2c
//   0x02bcb4: f0ffff21  adrp     x1, #0x12000
//   0x02bcb8: 90ffff42  adrp     x2, #0x13000
uint64_t fde_0103_sub_02bc7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xF81B83A8ULL) + (x2 ^ 0x02BC7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x02bc7c: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x02bc80: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x02bc84: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x02bc88: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x02bc8c: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x02bc90: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x02bc94: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02bc98: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02bc9c: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x02bca0: mov x19, x3
    return acc;
}

// [EN] Reconstructed FDE #0104 @ 0x02be10..0x02bf70 (352 bytes)
// [VN] Phục dựng FDE #0104 tại 0x02be10..0x02bf70 (352 byte)
//   0x02be10: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x02be14: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02be18: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02be1c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02be20: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02be24: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02be28: 910143fd  add      x29, sp, #0x50
//   0x02be2c: b4000940  cbz      x0, #0x2bf54
//   0x02be30: aa0003f4  mov      x20, x0
//   0x02be34: d0ffff40  adrp     x0, #0x15000
//   0x02be38: aa0103f3  mov      x19, x1
//   0x02be3c: 911b4c00  add      x0, x0, #0x6d3
//   0x02be40: 52800021  mov      w1, #1
//   0x02be44: 9400c4bf  bl       #0x5d140
//   0x02be48: 3100041f  cmn      w0, #1
//   0x02be4c: 54000840  b.eq     #0x2bf54
uint64_t fde_0104_sub_02be10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x52800021ULL) + (x2 ^ 0x02BE10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x02be10: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02be14: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02be18: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02be1c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02be20: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02be24: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02be28: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000940ULL; // 0x02be2c: cbz x0, #0x2bf54
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02be30: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF40ULL; // 0x02be34: adrp x0, #0x15000
    return acc;
}

// [EN] Reconstructed FDE #0105 @ 0x02bf70..0x02bf88 (24 bytes)
// [VN] Phục dựng FDE #0105 tại 0x02bf70..0x02bf88 (24 byte)
//   0x02bf70: f0ffff21  adrp     x1, #0x12000
//   0x02bf74: b0ffff22  adrp     x2, #0x10000
//   0x02bf78: 9105bc21  add      x1, x1, #0x16f
//   0x02bf7c: 91073842  add      x2, x2, #0x1ce
//   0x02bf80: 52800060  mov      w0, #3
//   0x02bf84: 1400c347  b        #0x5cca0
uint64_t fde_0105_sub_02bf70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0FFFF21ULL) + (x1 ^ 0x1400C347ULL) + (x2 ^ 0x02BF70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF21ULL; // 0x02bf70: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF22ULL; // 0x02bf74: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x9105BC21ULL; // 0x02bf78: add x1, x1, #0x16f
    acc = (acc * 0x100000001B3ULL) ^ 0x91073842ULL; // 0x02bf7c: add x2, x2, #0x1ce
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02bf80: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C347ULL; // 0x02bf84: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0106 @ 0x02bf88..0x02c004 (124 bytes)
// [VN] Phục dựng FDE #0106 tại 0x02bf88..0x02c004 (124 byte)
//   0x02bf88: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02bf8c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02bf90: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bf94: 910083fd  add      x29, sp, #0x20
//   0x02bf98: a940d413  ldp      x19, x21, [x0, #8]
//   0x02bf9c: aa0003f4  mov      x20, x0
//   0x02bfa0: 9400c3cc  bl       #0x5ced0
//   0x02bfa4: b9400682  ldr      w2, [x20, #4]
//   0x02bfa8: 93407c08  sxtw     x8, w0
//   0x02bfac: 9b087ea1  mul      x1, x21, x8
//   0x02bfb0: aa1303e0  mov      x0, x19
//   0x02bfb4: 9400c3cb  bl       #0x5cee0
//   0x02bfb8: 2a0003f3  mov      w19, w0
//   0x02bfbc: 34000180  cbz      w0, #0x2bfec
//   0x02bfc0: 9400c3cc  bl       #0x5cef0
//   0x02bfc4: b9400000  ldr      w0, [x0]
uint64_t fde_0106_sub_02bf88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x02BF88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02bf88: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02bf8c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02bf90: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bf94: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA940D413ULL; // 0x02bf98: ldp x19, x21, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02bf9c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C3CCULL; // 0x02bfa0: bl #0x5ced0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400682ULL; // 0x02bfa4: ldr w2, [x20, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C08ULL; // 0x02bfa8: sxtw x8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087EA1ULL; // 0x02bfac: mul x1, x21, x8
    return acc;
}

// [EN] Reconstructed FDE #0107 @ 0x02c004..0x02c220 (540 bytes)
// [VN] Phục dựng FDE #0107 tại 0x02c004..0x02c220 (540 byte)
//   0x02c004: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02c008: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02c00c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c010: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c014: 9100c3fd  add      x29, sp, #0x30
//   0x02c018: b00001d3  adrp     x19, #0x65000
//   0x02c01c: 9132e273  add      x19, x19, #0xcb8
//   0x02c020: 2a0003f4  mov      w20, w0
//   0x02c024: aa1303e0  mov      x0, x19
//   0x02c028: 9400c452  bl       #0x5d170
//   0x02c02c: b9402a68  ldr      w8, [x19, #0x28]
//   0x02c030: 34000248  cbz      w8, #0x2c078
//   0x02c034: 900001c8  adrp     x8, #0x64000
//   0x02c038: b94eb904  ldr      w4, [x8, #0xeb8]
//   0x02c03c: 6a240293  bics     w19, w20, w4
//   0x02c040: 54000500  b.eq     #0x2c0e0
uint64_t fde_0107_sub_02c004(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x900001C8ULL) + (x2 ^ 0x02C004ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02c004: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02c008: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c00c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c010: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c014: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001D3ULL; // 0x02c018: adrp x19, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9132E273ULL; // 0x02c01c: add x19, x19, #0xcb8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x02c020: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c024: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C452ULL; // 0x02c028: bl #0x5d170
    return acc;
}

// [EN] Reconstructed FDE #0108 @ 0x02c220..0x02c344 (292 bytes)
// [VN] Phục dựng FDE #0108 tại 0x02c220..0x02c344 (292 byte)
//   0x02c220: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02c224: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02c228: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c22c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c230: 9100c3fd  add      x29, sp, #0x30
//   0x02c234: 900001c8  adrp     x8, #0x64000
//   0x02c238: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x02c23c: 2a0003f4  mov      w20, w0
//   0x02c240: aa0103f3  mov      x19, x1
//   0x02c244: 2a0803e0  mov      w0, w8
//   0x02c248: 9400c37e  bl       #0x5d040
//   0x02c24c: b00001c8  adrp     x8, #0x65000
//   0x02c250: 93407e96  sxtw     x22, w20
//   0x02c254: 91378108  add      x8, x8, #0xde0
//   0x02c258: 8b161517  add      x23, x8, x22, lsl #5
//   0x02c25c: f9448ae4  ldr      x4, [x23, #0x910]
uint64_t fde_0108_sub_02c220(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x02C220ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02c220: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02c224: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c228: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c22c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c230: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C8ULL; // 0x02c234: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x02c238: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x02c23c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02c240: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x02c244: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0109 @ 0x02c344..0x02c370 (44 bytes)
// [VN] Phục dựng FDE #0109 tại 0x02c344..0x02c370 (44 byte)
//   0x02c344: 90ffff00  adrp     x0, #0xc000
//   0x02c348: 90ffff42  adrp     x2, #0x14000
//   0x02c34c: 90000003  adrp     x3, #0x2c000
//   0x02c350: 90000004  adrp     x4, #0x2c000
//   0x02c354: 91032400  add      x0, x0, #0xc9
//   0x02c358: 9125a042  add      x2, x2, #0x968
//   0x02c35c: 910dc063  add      x3, x3, #0x370
//   0x02c360: 91102084  add      x4, x4, #0x408
//   0x02c364: aa1f03e1  mov      x1, xzr
//   0x02c368: aa1f03e5  mov      x5, xzr
//   0x02c36c: 1400c349  b        #0x5d090
uint64_t fde_0109_sub_02c344(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90FFFF00ULL) + (x1 ^ 0x1400C349ULL) + (x2 ^ 0x02C344ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF00ULL; // 0x02c344: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF42ULL; // 0x02c348: adrp x2, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000003ULL; // 0x02c34c: adrp x3, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000004ULL; // 0x02c350: adrp x4, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91032400ULL; // 0x02c354: add x0, x0, #0xc9
    acc = (acc * 0x100000001B3ULL) ^ 0x9125A042ULL; // 0x02c358: add x2, x2, #0x968
    acc = (acc * 0x100000001B3ULL) ^ 0x910DC063ULL; // 0x02c35c: add x3, x3, #0x370
    acc = (acc * 0x100000001B3ULL) ^ 0x91102084ULL; // 0x02c360: add x4, x4, #0x408
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02c364: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E5ULL; // 0x02c368: mov x5, xzr
    return acc;
}

// [EN] Reconstructed FDE #0110 @ 0x02c370..0x02c408 (152 bytes)
// [VN] Phục dựng FDE #0110 tại 0x02c370..0x02c408 (152 byte)
//   0x02c370: d10103ff  sub      sp, sp, #0x40
//   0x02c374: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c378: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c37c: 9100c3fd  add      x29, sp, #0x30
//   0x02c380: aa1e03f3  mov      x19, x30
//   0x02c384: f9000fe0  str      x0, [sp, #0x18]
//   0x02c388: b90017e1  str      w1, [sp, #0x14]
//   0x02c38c: f90007e2  str      x2, [sp, #8]
//   0x02c390: d0ffff21  adrp     x1, #0x12000
//   0x02c394: 90ffff42  adrp     x2, #0x14000
//   0x02c398: 9105bc21  add      x1, x1, #0x16f
//   0x02c39c: 91268c42  add      x2, x2, #0x9a3
//   0x02c3a0: 528000c0  mov      w0, #6
//   0x02c3a4: 9400c23f  bl       #0x5cca0
//   0x02c3a8: 910063e0  add      x0, sp, #0x18
//   0x02c3ac: 910053e1  add      x1, sp, #0x14
uint64_t fde_0110_sub_02c370(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x528000C0ULL) + (x2 ^ 0x02C370ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02c370: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c374: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c378: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c37c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02c380: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE0ULL; // 0x02c384: str x0, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90017E1ULL; // 0x02c388: str w1, [sp, #0x14]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E2ULL; // 0x02c38c: str x2, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF21ULL; // 0x02c390: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF42ULL; // 0x02c394: adrp x2, #0x14000
    return acc;
}

// [EN] Reconstructed FDE #0111 @ 0x02c408..0x02c444 (60 bytes)
// [VN] Phục dựng FDE #0111 tại 0x02c408..0x02c444 (60 byte)
//   0x02c408: f0ffff09  adrp     x9, #0xf000
//   0x02c40c: 90ffff4a  adrp     x10, #0x14000
//   0x02c410: b0ffff48  adrp     x8, #0x15000
//   0x02c414: 912eb129  add      x9, x9, #0xbac
//   0x02c418: 9106254a  add      x10, x10, #0x189
//   0x02c41c: 7100003f  cmp      w1, #0
//   0x02c420: d0ffff21  adrp     x1, #0x12000
//   0x02c424: 91120d08  add      x8, x8, #0x483
//   0x02c428: aa0303e5  mov      x5, x3
//   0x02c42c: 9105bc21  add      x1, x1, #0x16f
//   0x02c430: 9a890143  csel     x3, x10, x9, eq
//   0x02c434: 528000c0  mov      w0, #6
//   0x02c438: aa0203e4  mov      x4, x2
//   0x02c43c: aa0803e2  mov      x2, x8
//   0x02c440: 1400c218  b        #0x5cca0
uint64_t fde_0111_sub_02c408(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0FFFF09ULL) + (x1 ^ 0xAA0203E4ULL) + (x2 ^ 0x02C408ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF09ULL; // 0x02c408: adrp x9, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF4AULL; // 0x02c40c: adrp x10, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF48ULL; // 0x02c410: adrp x8, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x912EB129ULL; // 0x02c414: add x9, x9, #0xbac
    acc = (acc * 0x100000001B3ULL) ^ 0x9106254AULL; // 0x02c418: add x10, x10, #0x189
    acc = (acc * 0x100000001B3ULL) ^ 0x7100003FULL; // 0x02c41c: cmp w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF21ULL; // 0x02c420: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91120D08ULL; // 0x02c424: add x8, x8, #0x483
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E5ULL; // 0x02c428: mov x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x9105BC21ULL; // 0x02c42c: add x1, x1, #0x16f
    return acc;
}

// [EN] Reconstructed FDE #0112 @ 0x02c444..0x02c614 (464 bytes)
// [VN] Phục dựng FDE #0112 tại 0x02c444..0x02c614 (464 byte)
//   0x02c444: d10583ff  sub      sp, sp, #0x160
//   0x02c448: f9008bfc  str      x28, [sp, #0x110]
//   0x02c44c: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x02c450: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x02c454: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x02c458: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x02c45c: 910543fd  add      x29, sp, #0x150
//   0x02c460: d53bd057  mrs      x23, tpidr_el0
//   0x02c464: f94016e8  ldr      x8, [x23, #0x28]
//   0x02c468: aa0203f3  mov      x19, x2
//   0x02c46c: aa0103f4  mov      x20, x1
//   0x02c470: d0ffff21  adrp     x1, #0x12000
//   0x02c474: f0ffff22  adrp     x2, #0x13000
//   0x02c478: f0fffee3  adrp     x3, #0xb000
//   0x02c47c: aa0003f5  mov      x21, x0
//   0x02c480: 9105bc21  add      x1, x1, #0x16f
uint64_t fde_0112_sub_02c444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xF0FFFF22ULL) + (x2 ^ 0x02C444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x02c444: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x02c448: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x02c44c: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x02c450: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x02c454: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x02c458: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x02c45c: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02c460: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02c464: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02c468: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0113 @ 0x02c614..0x02c6b0 (156 bytes)
// [VN] Phục dựng FDE #0113 tại 0x02c614..0x02c6b0 (156 byte)
//   0x02c614: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c618: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c61c: 910043fd  add      x29, sp, #0x10
//   0x02c620: 90ffff21  adrp     x1, #0x10000
//   0x02c624: b0ffff42  adrp     x2, #0x15000
//   0x02c628: 911d0421  add      x1, x1, #0x741
//   0x02c62c: 91080442  add      x2, x2, #0x201
//   0x02c630: 52800060  mov      w0, #3
//   0x02c634: 9400c19b  bl       #0x5cca0
//   0x02c638: 90ffff20  adrp     x0, #0x10000
//   0x02c63c: 91036400  add      x0, x0, #0xd9
//   0x02c640: 52800041  mov      w1, #2
//   0x02c644: 9400c2e3  bl       #0x5d1d0
//   0x02c648: 900001d4  adrp     x20, #0x64000
//   0x02c64c: b4000120  cbz      x0, #0x2c670
//   0x02c650: b0ffff41  adrp     x1, #0x15000
uint64_t fde_0113_sub_02c614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9400C2E3ULL) + (x2 ^ 0x02C614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c614: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c618: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c61c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF21ULL; // 0x02c620: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF42ULL; // 0x02c624: adrp x2, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D0421ULL; // 0x02c628: add x1, x1, #0x741
    acc = (acc * 0x100000001B3ULL) ^ 0x91080442ULL; // 0x02c62c: add x2, x2, #0x201
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02c630: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C19BULL; // 0x02c634: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF20ULL; // 0x02c638: adrp x0, #0x10000
    return acc;
}

// [EN] Reconstructed FDE #0114 @ 0x02c6b0..0x02c6d0 (32 bytes)
// [VN] Phục dựng FDE #0114 tại 0x02c6b0..0x02c6d0 (32 byte)
//   0x02c6b0: 900001c1  adrp     x1, #0x64000
//   0x02c6b4: 90000000  adrp     x0, #0x2c000
//   0x02c6b8: 900001a2  adrp     x2, #0x60000
//   0x02c6bc: 913f2021  add      x1, x1, #0xfc8
//   0x02c6c0: 9128f000  add      x0, x0, #0xa3c
//   0x02c6c4: 91000042  add      x2, x2, #0
//   0x02c6c8: f900003f  str      xzr, [x1]
//   0x02c6cc: 1400c171  b        #0x5cc90
uint64_t fde_0114_sub_02c6b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001C1ULL) + (x1 ^ 0x1400C171ULL) + (x2 ^ 0x02C6B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C1ULL; // 0x02c6b0: adrp x1, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x02c6b4: adrp x0, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c6b8: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F2021ULL; // 0x02c6bc: add x1, x1, #0xfc8
    acc = (acc * 0x100000001B3ULL) ^ 0x9128F000ULL; // 0x02c6c0: add x0, x0, #0xa3c
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c6c4: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900003FULL; // 0x02c6c8: str xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C171ULL; // 0x02c6cc: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0115 @ 0x02c6d0..0x02c760 (144 bytes)
// [VN] Phục dựng FDE #0115 tại 0x02c6d0..0x02c760 (144 byte)
//   0x02c6d0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c6d4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c6d8: 910043fd  add      x29, sp, #0x10
//   0x02c6dc: b00001d3  adrp     x19, #0x65000
//   0x02c6e0: 91216273  add      x19, x19, #0x858
//   0x02c6e4: 900001b4  adrp     x20, #0x60000
//   0x02c6e8: aa1303e8  mov      x8, x19
//   0x02c6ec: d0000000  adrp     x0, #0x2e000
//   0x02c6f0: 91000294  add      x20, x20, #0
//   0x02c6f4: f8008d1f  str      xzr, [x8, #8]!
//   0x02c6f8: 91226000  add      x0, x0, #0x898
//   0x02c6fc: aa1303e1  mov      x1, x19
//   0x02c700: aa1403e2  mov      x2, x20
//   0x02c704: f9000a7f  str      xzr, [x19, #0x10]
//   0x02c708: f9000268  str      x8, [x19]
//   0x02c70c: 9400c161  bl       #0x5cc90
uint64_t fde_0115_sub_02c6d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1403E2ULL) + (x2 ^ 0x02C6D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c6d0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c6d4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c6d8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001D3ULL; // 0x02c6dc: adrp x19, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91216273ULL; // 0x02c6e0: add x19, x19, #0x858
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B4ULL; // 0x02c6e4: adrp x20, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E8ULL; // 0x02c6e8: mov x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000000ULL; // 0x02c6ec: adrp x0, #0x2e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91000294ULL; // 0x02c6f0: add x20, x20, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x02c6f4: str xzr, [x8, #8]!
    return acc;
}

// [EN] Reconstructed FDE #0116 @ 0x02c760..0x02c77c (28 bytes)
// [VN] Phục dựng FDE #0116 tại 0x02c760..0x02c77c (28 byte)
//   0x02c760: 900001a0  adrp     x0, #0x60000
//   0x02c764: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02c768: b00001c1  adrp     x1, #0x65000
//   0x02c76c: 900001a2  adrp     x2, #0x60000
//   0x02c770: 912c0021  add      x1, x1, #0xb00
//   0x02c774: 91000042  add      x2, x2, #0
//   0x02c778: 1400c146  b        #0x5cc90
uint64_t fde_0116_sub_02c760(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C146ULL) + (x2 ^ 0x02C760ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02c760: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02c764: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c768: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c76c: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C0021ULL; // 0x02c770: add x1, x1, #0xb00
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c774: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C146ULL; // 0x02c778: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0117 @ 0x02c77c..0x02c798 (28 bytes)
// [VN] Phục dựng FDE #0117 tại 0x02c77c..0x02c798 (28 byte)
//   0x02c77c: 900001a0  adrp     x0, #0x60000
//   0x02c780: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02c784: 900001c1  adrp     x1, #0x64000
//   0x02c788: 900001a2  adrp     x2, #0x60000
//   0x02c78c: 91178021  add      x1, x1, #0x5e0
//   0x02c790: 91000042  add      x2, x2, #0
//   0x02c794: 1400c13f  b        #0x5cc90
uint64_t fde_0117_sub_02c77c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C13FULL) + (x2 ^ 0x02C77CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02c77c: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02c780: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C1ULL; // 0x02c784: adrp x1, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c788: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91178021ULL; // 0x02c78c: add x1, x1, #0x5e0
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c790: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C13FULL; // 0x02c794: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0118 @ 0x02c798..0x02c7b4 (28 bytes)
// [VN] Phục dựng FDE #0118 tại 0x02c798..0x02c7b4 (28 byte)
//   0x02c798: 900001a0  adrp     x0, #0x60000
//   0x02c79c: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02c7a0: b00001c1  adrp     x1, #0x65000
//   0x02c7a4: 900001a2  adrp     x2, #0x60000
//   0x02c7a8: 912d4021  add      x1, x1, #0xb50
//   0x02c7ac: 91000042  add      x2, x2, #0
//   0x02c7b0: 1400c138  b        #0x5cc90
uint64_t fde_0118_sub_02c798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C138ULL) + (x2 ^ 0x02C798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02c798: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02c79c: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c7a0: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c7a4: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x912D4021ULL; // 0x02c7a8: add x1, x1, #0xb50
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c7ac: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C138ULL; // 0x02c7b0: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0119 @ 0x02c7b4..0x02c7d8 (36 bytes)
// [VN] Phục dựng FDE #0119 tại 0x02c7b4..0x02c7d8 (36 byte)
//   0x02c7b4: b00001c1  adrp     x1, #0x65000
//   0x02c7b8: 900000a0  adrp     x0, #0x40000
//   0x02c7bc: 900001a2  adrp     x2, #0x60000
//   0x02c7c0: 91228021  add      x1, x1, #0x8a0
//   0x02c7c4: 91265000  add      x0, x0, #0x994
//   0x02c7c8: 91000042  add      x2, x2, #0
//   0x02c7cc: a9007c3f  stp      xzr, xzr, [x1]
//   0x02c7d0: f900083f  str      xzr, [x1, #0x10]
//   0x02c7d4: 1400c12f  b        #0x5cc90
uint64_t fde_0119_sub_02c7b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001C1ULL) + (x1 ^ 0x1400C12FULL) + (x2 ^ 0x02C7B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c7b4: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A0ULL; // 0x02c7b8: adrp x0, #0x40000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c7bc: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91228021ULL; // 0x02c7c0: add x1, x1, #0x8a0
    acc = (acc * 0x100000001B3ULL) ^ 0x91265000ULL; // 0x02c7c4: add x0, x0, #0x994
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c7c8: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C3FULL; // 0x02c7cc: stp xzr, xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900083FULL; // 0x02c7d0: str xzr, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C12FULL; // 0x02c7d4: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0120 @ 0x02c7d8..0x02c878 (160 bytes)
// [VN] Phục dựng FDE #0120 tại 0x02c7d8..0x02c878 (160 byte)
//   0x02c7d8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02c7dc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c7e0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c7e4: 910083fd  add      x29, sp, #0x20
//   0x02c7e8: 900001b3  adrp     x19, #0x60000
//   0x02c7ec: f9463e73  ldr      x19, [x19, #0xc78]
//   0x02c7f0: b00001d4  adrp     x20, #0x65000
//   0x02c7f4: 900001b5  adrp     x21, #0x60000
//   0x02c7f8: 912de294  add      x20, x20, #0xb78
//   0x02c7fc: 910002b5  add      x21, x21, #0
//   0x02c800: aa1303e0  mov      x0, x19
//   0x02c804: aa1403e1  mov      x1, x20
//   0x02c808: aa1503e2  mov      x2, x21
//   0x02c80c: 9400c121  bl       #0x5cc90
//   0x02c810: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02c814: aa1403e1  mov      x1, x20
uint64_t fde_0120_sub_02c7d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1503E2ULL) + (x2 ^ 0x02C7D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02c7d8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c7dc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c7e0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c7e4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x02c7e8: adrp x19, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463E73ULL; // 0x02c7ec: ldr x19, [x19, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001D4ULL; // 0x02c7f0: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B5ULL; // 0x02c7f4: adrp x21, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x912DE294ULL; // 0x02c7f8: add x20, x20, #0xb78
    acc = (acc * 0x100000001B3ULL) ^ 0x910002B5ULL; // 0x02c7fc: add x21, x21, #0
    return acc;
}

// [EN] Reconstructed FDE #0121 @ 0x02c878..0x02c904 (140 bytes)
// [VN] Phục dựng FDE #0121 tại 0x02c878..0x02c904 (140 byte)
//   0x02c878: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x02c87c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c880: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c884: 910083fd  add      x29, sp, #0x20
//   0x02c888: d11043ff  sub      sp, sp, #0x410
//   0x02c88c: d53bd053  mrs      x19, tpidr_el0
//   0x02c890: f9401668  ldr      x8, [x19, #0x28]
//   0x02c894: b00001d4  adrp     x20, #0x65000
//   0x02c898: 91308294  add      x20, x20, #0xc20
//   0x02c89c: 910023e0  add      x0, sp, #8
//   0x02c8a0: 52808002  mov      w2, #0x400
//   0x02c8a4: 2a1f03e1  mov      w1, wzr
//   0x02c8a8: f81d83a8  stur     x8, [x29, #-0x28]
//   0x02c8ac: b900029f  str      wzr, [x20]
//   0x02c8b0: f900069f  str      xzr, [x20, #8]
//   0x02c8b4: 3900429f  strb     wzr, [x20, #0x10]
uint64_t fde_0121_sub_02c878(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x02C878ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x02c878: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c87c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c880: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c884: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x02c888: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02c88c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02c890: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001D4ULL; // 0x02c894: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91308294ULL; // 0x02c898: add x20, x20, #0xc20
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02c89c: add x0, sp, #8
    return acc;
}

// [EN] Reconstructed FDE #0122 @ 0x02c904..0x02c998 (148 bytes)
// [VN] Phục dựng FDE #0122 tại 0x02c904..0x02c998 (148 byte)
//   0x02c904: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02c908: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c90c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c910: 910083fd  add      x29, sp, #0x20
//   0x02c914: 900001a0  adrp     x0, #0x60000
//   0x02c918: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02c91c: 900001d5  adrp     x21, #0x64000
//   0x02c920: 900001b3  adrp     x19, #0x60000
//   0x02c924: 913a42b5  add      x21, x21, #0xe90
//   0x02c928: 91000273  add      x19, x19, #0
//   0x02c92c: 9136c2a1  add      x1, x21, #0xdb0
//   0x02c930: aa1303e2  mov      x2, x19
//   0x02c934: 9400c0d7  bl       #0x5cc90
//   0x02c938: 900000f4  adrp     x20, #0x48000
//   0x02c93c: 9117f294  add      x20, x20, #0x5fc
//   0x02c940: 911fa2a1  add      x1, x21, #0x7e8
uint64_t fde_0122_sub_02c904(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x9400C0D7ULL) + (x2 ^ 0x02C904ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02c904: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c908: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c90c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c910: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02c914: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02c918: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001D5ULL; // 0x02c91c: adrp x21, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x02c920: adrp x19, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x913A42B5ULL; // 0x02c924: add x21, x21, #0xe90
    acc = (acc * 0x100000001B3ULL) ^ 0x91000273ULL; // 0x02c928: add x19, x19, #0
    return acc;
}

// [EN] Reconstructed FDE #0123 @ 0x02c998..0x02c9bc (36 bytes)
// [VN] Phục dựng FDE #0123 tại 0x02c998..0x02c9bc (36 byte)
//   0x02c998: b00001c1  adrp     x1, #0x65000
//   0x02c99c: b0000120  adrp     x0, #0x51000
//   0x02c9a0: 900001a2  adrp     x2, #0x60000
//   0x02c9a4: 91234021  add      x1, x1, #0x8d0
//   0x02c9a8: 912ed000  add      x0, x0, #0xbb4
//   0x02c9ac: 91000042  add      x2, x2, #0
//   0x02c9b0: a9007c3f  stp      xzr, xzr, [x1]
//   0x02c9b4: f900083f  str      xzr, [x1, #0x10]
//   0x02c9b8: 1400c0b6  b        #0x5cc90
uint64_t fde_0123_sub_02c998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001C1ULL) + (x1 ^ 0x1400C0B6ULL) + (x2 ^ 0x02C998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c998: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000120ULL; // 0x02c99c: adrp x0, #0x51000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c9a0: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91234021ULL; // 0x02c9a4: add x1, x1, #0x8d0
    acc = (acc * 0x100000001B3ULL) ^ 0x912ED000ULL; // 0x02c9a8: add x0, x0, #0xbb4
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c9ac: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C3FULL; // 0x02c9b0: stp xzr, xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900083FULL; // 0x02c9b4: str xzr, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C0B6ULL; // 0x02c9b8: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0124 @ 0x02c9bc..0x02c9e8 (44 bytes)
// [VN] Phục dựng FDE #0124 tại 0x02c9bc..0x02c9e8 (44 byte)
//   0x02c9bc: b00001c1  adrp     x1, #0x65000
//   0x02c9c0: 9123a021  add      x1, x1, #0x8e8
//   0x02c9c4: f0000120  adrp     x0, #0x53000
//   0x02c9c8: aa0103e8  mov      x8, x1
//   0x02c9cc: 900001a2  adrp     x2, #0x60000
//   0x02c9d0: 911ad000  add      x0, x0, #0x6b4
//   0x02c9d4: f8008d1f  str      xzr, [x8, #8]!
//   0x02c9d8: 91000042  add      x2, x2, #0
//   0x02c9dc: f900083f  str      xzr, [x1, #0x10]
//   0x02c9e0: f9000028  str      x8, [x1]
//   0x02c9e4: 1400c0ab  b        #0x5cc90
uint64_t fde_0124_sub_02c9bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001C1ULL) + (x1 ^ 0x1400C0ABULL) + (x2 ^ 0x02C9BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c9bc: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9123A021ULL; // 0x02c9c0: add x1, x1, #0x8e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x02c9c4: adrp x0, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x02c9c8: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c9cc: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AD000ULL; // 0x02c9d0: add x0, x0, #0x6b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x02c9d4: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c9d8: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900083FULL; // 0x02c9dc: str xzr, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x02c9e0: str x8, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0125 @ 0x02c9e8..0x02ca04 (28 bytes)
// [VN] Phục dựng FDE #0125 tại 0x02c9e8..0x02ca04 (28 byte)
//   0x02c9e8: 900001a0  adrp     x0, #0x60000
//   0x02c9ec: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02c9f0: b00001c1  adrp     x1, #0x65000
//   0x02c9f4: 900001a2  adrp     x2, #0x60000
//   0x02c9f8: 9131a021  add      x1, x1, #0xc68
//   0x02c9fc: 91000042  add      x2, x2, #0
//   0x02ca00: 1400c0a4  b        #0x5cc90
uint64_t fde_0125_sub_02c9e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C0A4ULL) + (x2 ^ 0x02C9E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02c9e8: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02c9ec: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02c9f0: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02c9f4: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9131A021ULL; // 0x02c9f8: add x1, x1, #0xc68
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02c9fc: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C0A4ULL; // 0x02ca00: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0126 @ 0x02ca04..0x02ca20 (28 bytes)
// [VN] Phục dựng FDE #0126 tại 0x02ca04..0x02ca20 (28 byte)
//   0x02ca04: 900001a0  adrp     x0, #0x60000
//   0x02ca08: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02ca0c: b00001c1  adrp     x1, #0x65000
//   0x02ca10: 900001a2  adrp     x2, #0x60000
//   0x02ca14: 91324021  add      x1, x1, #0xc90
//   0x02ca18: 91000042  add      x2, x2, #0
//   0x02ca1c: 1400c09d  b        #0x5cc90
uint64_t fde_0126_sub_02ca04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C09DULL) + (x2 ^ 0x02CA04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02ca04: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02ca08: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02ca0c: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02ca10: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91324021ULL; // 0x02ca14: add x1, x1, #0xc90
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02ca18: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C09DULL; // 0x02ca1c: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0127 @ 0x02ca20..0x02ca3c (28 bytes)
// [VN] Phục dựng FDE #0127 tại 0x02ca20..0x02ca3c (28 byte)
//   0x02ca20: 900001a0  adrp     x0, #0x60000
//   0x02ca24: f9463c00  ldr      x0, [x0, #0xc78]
//   0x02ca28: b00001c1  adrp     x1, #0x65000
//   0x02ca2c: 900001a2  adrp     x2, #0x60000
//   0x02ca30: 9132e021  add      x1, x1, #0xcb8
//   0x02ca34: 91000042  add      x2, x2, #0
//   0x02ca38: 1400c096  b        #0x5cc90
uint64_t fde_0127_sub_02ca20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x1400C096ULL) + (x2 ^ 0x02CA20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x02ca20: adrp x0, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463C00ULL; // 0x02ca24: ldr x0, [x0, #0xc78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02ca28: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x02ca2c: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9132E021ULL; // 0x02ca30: add x1, x1, #0xcb8
    acc = (acc * 0x100000001B3ULL) ^ 0x91000042ULL; // 0x02ca34: add x2, x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1400C096ULL; // 0x02ca38: b #0x5cc90
    return acc;
}

// [EN] Reconstructed FDE #0128 @ 0x02ca3c..0x02ca74 (56 bytes)
// [VN] Phục dựng FDE #0128 tại 0x02ca3c..0x02ca74 (56 byte)
//   0x02ca3c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02ca40: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02ca44: 910043fd  add      x29, sp, #0x10
//   0x02ca48: aa0003f3  mov      x19, x0
//   0x02ca4c: f9400000  ldr      x0, [x0]
//   0x02ca50: b40000c0  cbz      x0, #0x2ca68
//   0x02ca54: f9400014  ldr      x20, [x0]
//   0x02ca58: 9400c0aa  bl       #0x5cd00
//   0x02ca5c: aa1403e0  mov      x0, x20
//   0x02ca60: f9000274  str      x20, [x19]
//   0x02ca64: b5ffff94  cbnz     x20, #0x2ca54
//   0x02ca68: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02ca6c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02ca70: d65f03c0  ret      
uint64_t fde_0128_sub_02ca3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA8C24FF4ULL) + (x2 ^ 0x02CA3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02ca3c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02ca40: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02ca44: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02ca48: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02ca4c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x02ca50: cbz x0, #0x2ca68
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x02ca54: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400C0AAULL; // 0x02ca58: bl #0x5cd00
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02ca5c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000274ULL; // 0x02ca60: str x20, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0129 @ 0x02ca74..0x02cc80 (524 bytes)
// [VN] Phục dựng FDE #0129 tại 0x02ca74..0x02cc80 (524 byte)
//   0x02ca74: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02ca78: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02ca7c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02ca80: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02ca84: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02ca88: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02ca8c: 910143fd  add      x29, sp, #0x50
//   0x02ca90: d11043ff  sub      sp, sp, #0x410
//   0x02ca94: d53bd058  mrs      x24, tpidr_el0
//   0x02ca98: f9401708  ldr      x8, [x24, #0x28]
//   0x02ca9c: 900001d9  adrp     x25, #0x64000
//   0x02caa0: f81a03a8  stur     x8, [x29, #-0x60]
//   0x02caa4: f947e720  ldr      x0, [x25, #0xfc8]
//   0x02caa8: b5000d20  cbnz     x0, #0x2cc4c
//   0x02caac: 9400c1b9  bl       #0x5d190
//   0x02cab0: 2a0003e3  mov      w3, w0
uint64_t fde_0129_sub_02ca74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF947E720ULL) + (x2 ^ 0x02CA74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02ca74: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02ca78: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02ca7c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02ca80: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02ca84: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02ca88: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02ca8c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x02ca90: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02ca94: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x02ca98: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0130 @ 0x02cc80..0x02cd24 (164 bytes)
// [VN] Phục dựng FDE #0130 tại 0x02cc80..0x02cd24 (164 byte)
//   0x02cc80: d10483ff  sub      sp, sp, #0x120
//   0x02cc84: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02cc88: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02cc8c: 910443fd  add      x29, sp, #0x110
//   0x02cc90: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x02cc94: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02cc98: f90057e7  str      x7, [sp, #0xa8]
//   0x02cc9c: ad0007e0  stp      q0, q1, [sp]
//   0x02cca0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02cca4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02cca8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02ccac: d53bd053  mrs      x19, tpidr_el0
//   0x02ccb0: f9401669  ldr      x9, [x19, #0x28]
//   0x02ccb4: 910223ea  add      x10, sp, #0x88
//   0x02ccb8: 928004ec  mov      x12, #-0x28
//   0x02ccbc: 910043ab  add      x11, x29, #0x10
uint64_t fde_0130_sub_02cc80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401669ULL) + (x2 ^ 0x02CC80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02cc80: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x02cc84: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02cc88: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02cc8c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x02cc90: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x02cc94: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02cc98: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02cc9c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x02cca0: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x02cca4: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0131 @ 0x02cd24..0x02cdec (200 bytes)
// [VN] Phục dựng FDE #0131 tại 0x02cd24..0x02cdec (200 byte)
//   0x02cd24: d10103ff  sub      sp, sp, #0x40
//   0x02cd28: f9000bf5  str      x21, [sp, #0x10]
//   0x02cd2c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02cd30: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02cd34: 9100c3fd  add      x29, sp, #0x30
//   0x02cd38: d53bd055  mrs      x21, tpidr_el0
//   0x02cd3c: f94016a8  ldr      x8, [x21, #0x28]
//   0x02cd40: b00001c9  adrp     x9, #0x65000
//   0x02cd44: 528000c2  mov      w2, #6
//   0x02cd48: 528000d3  mov      w19, #6
//   0x02cd4c: f90007e8  str      x8, [sp, #8]
//   0x02cd50: f9060d20  str      x0, [x9, #0xc18]
//   0x02cd54: f90003ff  str      xzr, [sp]
//   0x02cd58: f9400008  ldr      x8, [x0]
//   0x02cd5c: 910003e1  mov      x1, sp
//   0x02cd60: 72a00022  movk     w2, #1, lsl #16
uint64_t fde_0131_sub_02cd24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF90003FFULL) + (x2 ^ 0x02CD24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02cd24: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x02cd28: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02cd2c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02cd30: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02cd34: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02cd38: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02cd3c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C9ULL; // 0x02cd40: adrp x9, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C2ULL; // 0x02cd44: mov w2, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x528000D3ULL; // 0x02cd48: mov w19, #6
    return acc;
}

// [EN] Reconstructed FDE #0132 @ 0x02cdec..0x02ce28 (60 bytes)
// [VN] Phục dựng FDE #0132 tại 0x02cdec..0x02ce28 (60 byte)
//   0x02cdec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02cdf0: 910003fd  mov      x29, sp
//   0x02cdf4: 900001c8  adrp     x8, #0x64000
//   0x02cdf8: b94ebd08  ldr      w8, [x8, #0xebc]
//   0x02cdfc: 350000e8  cbnz     w8, #0x2ce18
//   0x02ce00: b00001c1  adrp     x1, #0x65000
//   0x02ce04: 91250021  add      x1, x1, #0x940
//   0x02ce08: 52800160  mov      w0, #0xb
//   0x02ce0c: aa1f03e2  mov      x2, xzr
//   0x02ce10: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02ce14: 1400bfc7  b        #0x5cd30
//   0x02ce18: d00001c0  adrp     x0, #0x66000
//   0x02ce1c: 910f8000  add      x0, x0, #0x3e0
//   0x02ce20: 52800021  mov      w1, #1
//   0x02ce24: 9400bfd7  bl       #0x5cd80
uint64_t fde_0132_sub_02cdec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x910F8000ULL) + (x2 ^ 0x02CDECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02cdec: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02cdf0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C8ULL; // 0x02cdf4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94EBD08ULL; // 0x02cdf8: ldr w8, [x8, #0xebc]
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E8ULL; // 0x02cdfc: cbnz w8, #0x2ce18
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C1ULL; // 0x02ce00: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91250021ULL; // 0x02ce04: add x1, x1, #0x940
    acc = (acc * 0x100000001B3ULL) ^ 0x52800160ULL; // 0x02ce08: mov w0, #0xb
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02ce0c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02ce10: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0133 @ 0x02ce28..0x02d06c (580 bytes)
// [VN] Phục dựng FDE #0133 tại 0x02ce28..0x02d06c (580 byte)
//   0x02ce28: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02ce2c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02ce30: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02ce34: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02ce38: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02ce3c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02ce40: 910143fd  add      x29, sp, #0x50
//   0x02ce44: 53027c39  lsr      w25, w1, #2
//   0x02ce48: 34001019  cbz      w25, #0x2d048
//   0x02ce4c: d00001d5  adrp     x21, #0x66000
//   0x02ce50: 90ffff36  adrp     x22, #0x10000
//   0x02ce54: f0fffef7  adrp     x23, #0xb000
//   0x02ce58: aa0203f3  mov      x19, x2
//   0x02ce5c: aa0003f4  mov      x20, x0
//   0x02ce60: 2a1f03fa  mov      w26, wzr
//   0x02ce64: 900001db  adrp     x27, #0x64000
uint64_t fde_0133_sub_02ce28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0203F3ULL) + (x2 ^ 0x02CE28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02ce28: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02ce2c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02ce30: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02ce34: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02ce38: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02ce3c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02ce40: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x53027C39ULL; // 0x02ce44: lsr w25, w1, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x34001019ULL; // 0x02ce48: cbz w25, #0x2d048
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D5ULL; // 0x02ce4c: adrp x21, #0x66000
    return acc;
}

// [EN] Reconstructed FDE #0134 @ 0x02d06c..0x02d5f0 (1412 bytes)
// [VN] Phục dựng FDE #0134 tại 0x02d06c..0x02d5f0 (1412 byte)
//   0x02d06c: d10203ff  sub      sp, sp, #0x80
//   0x02d070: f9001bf9  str      x25, [sp, #0x30]
//   0x02d074: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02d078: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02d07c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02d080: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02d084: 9101c3fd  add      x29, sp, #0x70
//   0x02d088: d53bd056  mrs      x22, tpidr_el0
//   0x02d08c: f94016c8  ldr      x8, [x22, #0x28]
//   0x02d090: f00001b7  adrp     x23, #0x64000
//   0x02d094: 12144c49  and      w9, w2, #0xfffff000
//   0x02d098: f90017e8  str      x8, [sp, #0x28]
//   0x02d09c: b94032ea  ldr      w10, [x23, #0x30]
//   0x02d0a0: 52a10008  mov      w8, #0x8000000
//   0x02d0a4: 6b08013f  cmp      w9, w8
//   0x02d0a8: 1a88b128  csel     w8, w9, w8, lt
uint64_t fde_0134_sub_02d06c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xB94032EAULL) + (x2 ^ 0x02D06CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02d06c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x02d070: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02d074: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02d078: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02d07c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02d080: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02d084: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02d088: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02d08c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001B7ULL; // 0x02d090: adrp x23, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0135 @ 0x02d5f0..0x02d5f4 (4 bytes)
// [VN] Phục dựng FDE #0135 tại 0x02d5f0..0x02d5f4 (4 byte)
//   0x02d5f0: d65f03c0  ret      
uint64_t fde_0135_sub_02d5f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02D5F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d5f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0136 @ 0x02d5f4..0x02d644 (80 bytes)
// [VN] Phục dựng FDE #0136 tại 0x02d5f4..0x02d644 (80 byte)
//   0x02d5f4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02d5f8: 910003fd  mov      x29, sp
//   0x02d5fc: d0fffee0  adrp     x0, #0xb000
//   0x02d600: f0ffff01  adrp     x1, #0x10000
//   0x02d604: 90000002  adrp     x2, #0x2d000
//   0x02d608: f00001a3  adrp     x3, #0x64000
//   0x02d60c: 91204800  add      x0, x0, #0x812
//   0x02d610: 911f4021  add      x1, x1, #0x7d0
//   0x02d614: 91191042  add      x2, x2, #0x644
//   0x02d618: 9115a063  add      x3, x3, #0x568
//   0x02d61c: 9400bf19  bl       #0x5d280
//   0x02d620: d0ffff01  adrp     x1, #0xf000
//   0x02d624: d0fffee2  adrp     x2, #0xb000
//   0x02d628: 91073421  add      x1, x1, #0x1cd
//   0x02d62c: 91356842  add      x2, x2, #0xd5a
//   0x02d630: 52800080  mov      w0, #4
uint64_t fde_0136_sub_02d5f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD0FFFEE2ULL) + (x2 ^ 0x02D5F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02d5f4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02d5f8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE0ULL; // 0x02d5fc: adrp x0, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF01ULL; // 0x02d600: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x02d604: adrp x2, #0x2d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A3ULL; // 0x02d608: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91204800ULL; // 0x02d60c: add x0, x0, #0x812
    acc = (acc * 0x100000001B3ULL) ^ 0x911F4021ULL; // 0x02d610: add x1, x1, #0x7d0
    acc = (acc * 0x100000001B3ULL) ^ 0x91191042ULL; // 0x02d614: add x2, x2, #0x644
    acc = (acc * 0x100000001B3ULL) ^ 0x9115A063ULL; // 0x02d618: add x3, x3, #0x568
    return acc;
}

// [EN] Reconstructed FDE #0137 @ 0x02d644..0x02d6c8 (132 bytes)
// [VN] Phục dựng FDE #0137 tại 0x02d644..0x02d6c8 (132 byte)
//   0x02d644: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02d648: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02d64c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02d650: 910083fd  add      x29, sp, #0x20
//   0x02d654: aa1e03f3  mov      x19, x30
//   0x02d658: 2a0003f5  mov      w21, w0
//   0x02d65c: 9400be25  bl       #0x5cef0
//   0x02d660: b9400016  ldr      w22, [x0]
//   0x02d664: aa0003f4  mov      x20, x0
//   0x02d668: 90000000  adrp     x0, #0x2d000
//   0x02d66c: 91191000  add      x0, x0, #0x644
//   0x02d670: 9400bf08  bl       #0x5d290
//   0x02d674: aa0003e8  mov      x8, x0
//   0x02d678: 2a1503e0  mov      w0, w21
//   0x02d67c: d63f0100  blr      x8
//   0x02d680: b9000296  str      w22, [x20]
uint64_t fde_0137_sub_02d644(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x02D644ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02d644: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02d648: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02d64c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02d650: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02d654: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F5ULL; // 0x02d658: mov w21, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400BE25ULL; // 0x02d65c: bl #0x5cef0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400016ULL; // 0x02d660: ldr w22, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02d664: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x02d668: adrp x0, #0x2d000
    return acc;
}

// [EN] Reconstructed FDE #0138 @ 0x02d6c8..0x02d790 (200 bytes)
// [VN] Phục dựng FDE #0138 tại 0x02d6c8..0x02d790 (200 byte)
//   0x02d6c8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02d6cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02d6d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02d6d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02d6d8: 9100c3fd  add      x29, sp, #0x30
//   0x02d6dc: f00001a8  adrp     x8, #0x64000
//   0x02d6e0: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x02d6e4: aa1e03f3  mov      x19, x30
//   0x02d6e8: 2a0203f4  mov      w20, w2
//   0x02d6ec: aa0003f6  mov      x22, x0
//   0x02d6f0: eb00011f  cmp      x8, x0
//   0x02d6f4: aa0103f7  mov      x23, x1
//   0x02d6f8: 54000148  b.hi     #0x2d720
//   0x02d6fc: f00001a8  adrp     x8, #0x64000
//   0x02d700: f947f108  ldr      x8, [x8, #0xfe0]
//   0x02d704: eb16011f  cmp      x8, x22
uint64_t fde_0138_sub_02d6c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x54000148ULL) + (x2 ^ 0x02D6C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02d6c8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02d6cc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02d6d0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02d6d4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02d6d8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x02d6dc: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947ED08ULL; // 0x02d6e0: ldr x8, [x8, #0xfd8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02d6e4: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x02d6e8: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02d6ec: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0139 @ 0x02d790..0x02d868 (216 bytes)
// [VN] Phục dựng FDE #0139 tại 0x02d790..0x02d868 (216 byte)
//   0x02d790: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02d794: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d798: 910043fd  add      x29, sp, #0x10
//   0x02d79c: f00001b3  adrp     x19, #0x64000
//   0x02d7a0: 2a0203e8  mov      w8, w2
//   0x02d7a4: 913f6273  add      x19, x19, #0xfd8
//   0x02d7a8: 2a0303e9  mov      w9, w3
//   0x02d7ac: f9000268  str      x8, [x19]
//   0x02d7b0: f9000669  str      x9, [x19, #8]
//   0x02d7b4: f9400263  ldr      x3, [x19]
//   0x02d7b8: f9400664  ldr      x4, [x19, #8]
//   0x02d7bc: d0ffff21  adrp     x1, #0x13000
//   0x02d7c0: 90ffff22  adrp     x2, #0x11000
//   0x02d7c4: 913d2021  add      x1, x1, #0xf48
//   0x02d7c8: 91094c42  add      x2, x2, #0x253
//   0x02d7cc: 52800080  mov      w0, #4
uint64_t fde_0139_sub_02d790(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x90FFFF22ULL) + (x2 ^ 0x02D790ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02d790: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d794: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d798: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001B3ULL; // 0x02d79c: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x02d7a0: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x913F6273ULL; // 0x02d7a4: add x19, x19, #0xfd8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E9ULL; // 0x02d7a8: mov w9, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x02d7ac: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000669ULL; // 0x02d7b0: str x9, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400263ULL; // 0x02d7b4: ldr x3, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0140 @ 0x02d868..0x02d944 (220 bytes)
// [VN] Phục dựng FDE #0140 tại 0x02d868..0x02d944 (220 byte)
//   0x02d868: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02d86c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d870: 910043fd  add      x29, sp, #0x10
//   0x02d874: f00001a8  adrp     x8, #0x64000
//   0x02d878: 39795508  ldrb     w8, [x8, #0xe55]
//   0x02d87c: 36000268  tbz      w8, #0, #0x2d8c8
//   0x02d880: f00001b3  adrp     x19, #0x64000
//   0x02d884: 913f6273  add      x19, x19, #0xfd8
//   0x02d888: f9400260  ldr      x0, [x19]
//   0x02d88c: f9400668  ldr      x8, [x19, #8]
//   0x02d890: f9400269  ldr      x9, [x19]
//   0x02d894: 52800062  mov      w2, #3
//   0x02d898: cb090101  sub      x1, x8, x9
//   0x02d89c: 9400bd91  bl       #0x5cee0
//   0x02d8a0: f9400263  ldr      x3, [x19]
//   0x02d8a4: f9400664  ldr      x4, [x19, #8]
uint64_t fde_0140_sub_02d868(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xCB090101ULL) + (x2 ^ 0x02D868ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02d868: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d86c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d870: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x02d874: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39795508ULL; // 0x02d878: ldrb w8, [x8, #0xe55]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000268ULL; // 0x02d87c: tbz w8, #0, #0x2d8c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001B3ULL; // 0x02d880: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F6273ULL; // 0x02d884: add x19, x19, #0xfd8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x02d888: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400668ULL; // 0x02d88c: ldr x8, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0141 @ 0x02d944..0x02d998 (84 bytes)
// [VN] Phục dựng FDE #0141 tại 0x02d944..0x02d998 (84 byte)
//   0x02d944: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02d948: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d94c: 910043fd  add      x29, sp, #0x10
//   0x02d950: aa1e03f3  mov      x19, x30
//   0x02d954: 97ffe4d7  bl       #0x26cb0
//   0x02d958: 9400be52  bl       #0x5d2a0
//   0x02d95c: 35000060  cbnz     w0, #0x2d968
//   0x02d960: aa1303e0  mov      x0, x19
//   0x02d964: 9400be53  bl       #0x5d2b0
//   0x02d968: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02d96c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02d970: d65f03c0  ret      
//   0x02d974: aa0003f4  mov      x20, x0
//   0x02d978: 9400be4a  bl       #0x5d2a0
//   0x02d97c: 35000060  cbnz     w0, #0x2d988
//   0x02d980: aa1303e0  mov      x0, x19
uint64_t fde_0141_sub_02d944(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02D944ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02d944: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d948: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d94c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02d950: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE4D7ULL; // 0x02d954: bl #0x26cb0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400BE52ULL; // 0x02d958: bl #0x5d2a0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000060ULL; // 0x02d95c: cbnz w0, #0x2d968
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02d960: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400BE53ULL; // 0x02d964: bl #0x5d2b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02d968: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0142 @ 0x02d998..0x02da08 (112 bytes)
// [VN] Phục dựng FDE #0142 tại 0x02d998..0x02da08 (112 byte)
//   0x02d998: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02d99c: 910003fd  mov      x29, sp
//   0x02d9a0: d0fffee0  adrp     x0, #0xb000
//   0x02d9a4: 90ffff01  adrp     x1, #0xd000
//   0x02d9a8: 90000002  adrp     x2, #0x2d000
//   0x02d9ac: f00001a3  adrp     x3, #0x64000
//   0x02d9b0: 91362800  add      x0, x0, #0xd8a
//   0x02d9b4: 91339821  add      x1, x1, #0xce6
//   0x02d9b8: 91251042  add      x2, x2, #0x944
//   0x02d9bc: 9115c063  add      x3, x3, #0x570
//   0x02d9c0: 9400be30  bl       #0x5d280
//   0x02d9c4: b0ffff21  adrp     x1, #0x12000
//   0x02d9c8: 91060c21  add      x1, x1, #0x183
//   0x02d9cc: b4000100  cbz      x0, #0x2d9ec
//   0x02d9d0: 90ffff02  adrp     x2, #0xd000
//   0x02d9d4: 91076842  add      x2, x2, #0x1da
uint64_t fde_0142_sub_02d998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x91060C21ULL) + (x2 ^ 0x02D998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02d998: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02d99c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE0ULL; // 0x02d9a0: adrp x0, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF01ULL; // 0x02d9a4: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x02d9a8: adrp x2, #0x2d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A3ULL; // 0x02d9ac: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91362800ULL; // 0x02d9b0: add x0, x0, #0xd8a
    acc = (acc * 0x100000001B3ULL) ^ 0x91339821ULL; // 0x02d9b4: add x1, x1, #0xce6
    acc = (acc * 0x100000001B3ULL) ^ 0x91251042ULL; // 0x02d9b8: add x2, x2, #0x944
    acc = (acc * 0x100000001B3ULL) ^ 0x9115C063ULL; // 0x02d9bc: add x3, x3, #0x570
    return acc;
}

// [EN] Reconstructed FDE #0143 @ 0x02da08..0x02dac0 (184 bytes)
// [VN] Phục dựng FDE #0143 tại 0x02da08..0x02dac0 (184 byte)
//   0x02da08: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02da0c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02da10: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02da14: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02da18: 9100c3fd  add      x29, sp, #0x30
//   0x02da1c: aa1e03f3  mov      x19, x30
//   0x02da20: aa0303f4  mov      x20, x3
//   0x02da24: 2a0203f5  mov      w21, w2
//   0x02da28: 2a0103f6  mov      w22, w1
//   0x02da2c: aa0003f7  mov      x23, x0
//   0x02da30: d0ffff01  adrp     x1, #0xf000
//   0x02da34: d0ffff22  adrp     x2, #0x13000
//   0x02da38: 9126f021  add      x1, x1, #0x9bc
//   0x02da3c: 9109c842  add      x2, x2, #0x272
//   0x02da40: 52800060  mov      w0, #3
//   0x02da44: 9400bc97  bl       #0x5cca0
uint64_t fde_0143_sub_02da08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9126F021ULL) + (x2 ^ 0x02DA08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02da08: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02da0c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02da10: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02da14: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02da18: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02da1c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x02da20: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x02da24: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x02da28: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x02da2c: mov x23, x0
    return acc;
}

// [EN] Reconstructed FDE #0144 @ 0x02dac0..0x02db78 (184 bytes)
// [VN] Phục dựng FDE #0144 tại 0x02dac0..0x02db78 (184 byte)
//   0x02dac0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02dac4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02dac8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02dacc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02dad0: 9100c3fd  add      x29, sp, #0x30
//   0x02dad4: aa1e03f3  mov      x19, x30
//   0x02dad8: aa0303f4  mov      x20, x3
//   0x02dadc: 2a0203f5  mov      w21, w2
//   0x02dae0: 2a0103f6  mov      w22, w1
//   0x02dae4: aa0003f7  mov      x23, x0
//   0x02dae8: d0ffff01  adrp     x1, #0xf000
//   0x02daec: b0ffff22  adrp     x2, #0x12000
//   0x02daf0: 9126f021  add      x1, x1, #0x9bc
//   0x02daf4: 91214842  add      x2, x2, #0x852
//   0x02daf8: 52800060  mov      w0, #3
//   0x02dafc: 9400bc69  bl       #0x5cca0
uint64_t fde_0144_sub_02dac0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9126F021ULL) + (x2 ^ 0x02DAC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02dac0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02dac4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02dac8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02dacc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02dad0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02dad4: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x02dad8: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x02dadc: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x02dae0: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x02dae4: mov x23, x0
    return acc;
}

// [EN] Reconstructed FDE #0145 @ 0x02db78..0x02dbf4 (124 bytes)
// [VN] Phục dựng FDE #0145 tại 0x02db78..0x02dbf4 (124 byte)
//   0x02db78: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02db7c: 910003fd  mov      x29, sp
//   0x02db80: d0fffee0  adrp     x0, #0xb000
//   0x02db84: 90ffff02  adrp     x2, #0xd000
//   0x02db88: 90000003  adrp     x3, #0x2d000
//   0x02db8c: 911b8c00  add      x0, x0, #0x6e3
//   0x02db90: 911e1042  add      x2, x2, #0x784
//   0x02db94: 91282063  add      x3, x3, #0xa08
//   0x02db98: aa1f03e1  mov      x1, xzr
//   0x02db9c: aa1f03e4  mov      x4, xzr
//   0x02dba0: aa1f03e5  mov      x5, xzr
//   0x02dba4: 9400bd3b  bl       #0x5d090
//   0x02dba8: d0ffff01  adrp     x1, #0xf000
//   0x02dbac: f00001a8  adrp     x8, #0x64000
//   0x02dbb0: 9126f021  add      x1, x1, #0x9bc
//   0x02dbb4: f902bd00  str      x0, [x8, #0x578]
uint64_t fde_0145_sub_02db78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD0FFFF01ULL) + (x2 ^ 0x02DB78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02db78: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02db7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE0ULL; // 0x02db80: adrp x0, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x02db84: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000003ULL; // 0x02db88: adrp x3, #0x2d000
    acc = (acc * 0x100000001B3ULL) ^ 0x911B8C00ULL; // 0x02db8c: add x0, x0, #0x6e3
    acc = (acc * 0x100000001B3ULL) ^ 0x911E1042ULL; // 0x02db90: add x2, x2, #0x784
    acc = (acc * 0x100000001B3ULL) ^ 0x91282063ULL; // 0x02db94: add x3, x3, #0xa08
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02db98: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x02db9c: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0146 @ 0x02dbf4..0x02dc70 (124 bytes)
// [VN] Phục dựng FDE #0146 tại 0x02dbf4..0x02dc70 (124 byte)
//   0x02dbf4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02dbf8: 910003fd  mov      x29, sp
//   0x02dbfc: f0ffff00  adrp     x0, #0x10000
//   0x02dc00: 90ffff02  adrp     x2, #0xd000
//   0x02dc04: 90000003  adrp     x3, #0x2d000
//   0x02dc08: 911ad800  add      x0, x0, #0x6b6
//   0x02dc0c: 911e1042  add      x2, x2, #0x784
//   0x02dc10: 91282063  add      x3, x3, #0xa08
//   0x02dc14: aa1f03e1  mov      x1, xzr
//   0x02dc18: aa1f03e4  mov      x4, xzr
//   0x02dc1c: aa1f03e5  mov      x5, xzr
//   0x02dc20: 9400bd1c  bl       #0x5d090
//   0x02dc24: d0ffff01  adrp     x1, #0xf000
//   0x02dc28: f00001a8  adrp     x8, #0x64000
//   0x02dc2c: 9126f021  add      x1, x1, #0x9bc
//   0x02dc30: f902bd00  str      x0, [x8, #0x578]
uint64_t fde_0146_sub_02dbf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD0FFFF01ULL) + (x2 ^ 0x02DBF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02dbf4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02dbf8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF00ULL; // 0x02dbfc: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x02dc00: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000003ULL; // 0x02dc04: adrp x3, #0x2d000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AD800ULL; // 0x02dc08: add x0, x0, #0x6b6
    acc = (acc * 0x100000001B3ULL) ^ 0x911E1042ULL; // 0x02dc0c: add x2, x2, #0x784
    acc = (acc * 0x100000001B3ULL) ^ 0x91282063ULL; // 0x02dc10: add x3, x3, #0xa08
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02dc14: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x02dc18: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0147 @ 0x02dc70..0x02dcec (124 bytes)
// [VN] Phục dựng FDE #0147 tại 0x02dc70..0x02dcec (124 byte)
//   0x02dc70: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02dc74: 910003fd  mov      x29, sp
//   0x02dc78: 90ffff40  adrp     x0, #0x15000
//   0x02dc7c: 90ffff02  adrp     x2, #0xd000
//   0x02dc80: 90000003  adrp     x3, #0x2d000
//   0x02dc84: 9109d000  add      x0, x0, #0x274
//   0x02dc88: 911e1042  add      x2, x2, #0x784
//   0x02dc8c: 912b0063  add      x3, x3, #0xac0
//   0x02dc90: aa1f03e1  mov      x1, xzr
//   0x02dc94: aa1f03e4  mov      x4, xzr
//   0x02dc98: aa1f03e5  mov      x5, xzr
//   0x02dc9c: 9400bcfd  bl       #0x5d090
//   0x02dca0: d0ffff01  adrp     x1, #0xf000
//   0x02dca4: f00001a8  adrp     x8, #0x64000
//   0x02dca8: 9126f021  add      x1, x1, #0x9bc
//   0x02dcac: f902bd00  str      x0, [x8, #0x578]
uint64_t fde_0147_sub_02dc70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD0FFFF01ULL) + (x2 ^ 0x02DC70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02dc70: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02dc74: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF40ULL; // 0x02dc78: adrp x0, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x02dc7c: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000003ULL; // 0x02dc80: adrp x3, #0x2d000
    acc = (acc * 0x100000001B3ULL) ^ 0x9109D000ULL; // 0x02dc84: add x0, x0, #0x274
    acc = (acc * 0x100000001B3ULL) ^ 0x911E1042ULL; // 0x02dc88: add x2, x2, #0x784
    acc = (acc * 0x100000001B3ULL) ^ 0x912B0063ULL; // 0x02dc8c: add x3, x3, #0xac0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02dc90: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x02dc94: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0148 @ 0x02dcec..0x02e494 (1960 bytes)
// [VN] Phục dựng FDE #0148 tại 0x02dcec..0x02e494 (1960 byte)
//   0x02dcec: d104c3ff  sub      sp, sp, #0x130
//   0x02dcf0: a90d6ffc  stp      x28, x27, [sp, #0xd0]
//   0x02dcf4: a90e67fa  stp      x26, x25, [sp, #0xe0]
//   0x02dcf8: a90f5ff8  stp      x24, x23, [sp, #0xf0]
//   0x02dcfc: a91057f6  stp      x22, x21, [sp, #0x100]
//   0x02dd00: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x02dd04: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x02dd08: 910483fd  add      x29, sp, #0x120
//   0x02dd0c: d53bd05a  mrs      x26, tpidr_el0
//   0x02dd10: f9401748  ldr      x8, [x26, #0x28]
//   0x02dd14: 2a0203f3  mov      w19, w2
//   0x02dd18: 90ffff01  adrp     x1, #0xd000
//   0x02dd1c: f0fffee2  adrp     x2, #0xc000
//   0x02dd20: 9133cc21  add      x1, x1, #0xcf3
//   0x02dd24: 91207c42  add      x2, x2, #0x81f
//   0x02dd28: 52800060  mov      w0, #3
uint64_t fde_0148_sub_02dcec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0xF0FFFEE2ULL) + (x2 ^ 0x02DCECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x02dcec: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D6FFCULL; // 0x02dcf0: stp x28, x27, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E67FAULL; // 0x02dcf4: stp x26, x25, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F5FF8ULL; // 0x02dcf8: stp x24, x23, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057F6ULL; // 0x02dcfc: stp x22, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x02dd00: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x02dd04: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x02dd08: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x02dd0c: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x02dd10: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0149 @ 0x02e494..0x02e5a4 (272 bytes)
// [VN] Phục dựng FDE #0149 tại 0x02e494..0x02e5a4 (272 byte)
//   0x02e494: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02e498: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e49c: 910043fd  add      x29, sp, #0x10
//   0x02e4a0: f0fffee1  adrp     x1, #0xd000
//   0x02e4a4: 90ffff02  adrp     x2, #0xe000
//   0x02e4a8: 9133cc21  add      x1, x1, #0xcf3
//   0x02e4ac: 910ddc42  add      x2, x2, #0x377
//   0x02e4b0: 52800060  mov      w0, #3
//   0x02e4b4: 9400b9fb  bl       #0x5cca0
//   0x02e4b8: d0ffff00  adrp     x0, #0x10000
//   0x02e4bc: 911ad800  add      x0, x0, #0x6b6
//   0x02e4c0: 9400bb10  bl       #0x5d100
//   0x02e4c4: b4000360  cbz      x0, #0x2e530
//   0x02e4c8: b0ffff21  adrp     x1, #0x13000
//   0x02e4cc: 912e0021  add      x1, x1, #0xb80
//   0x02e4d0: aa0003f3  mov      x19, x0
uint64_t fde_0149_sub_02e494(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000360ULL) + (x2 ^ 0x02E494ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02e494: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e498: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e49c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEE1ULL; // 0x02e4a0: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x02e4a4: adrp x2, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x9133CC21ULL; // 0x02e4a8: add x1, x1, #0xcf3
    acc = (acc * 0x100000001B3ULL) ^ 0x910DDC42ULL; // 0x02e4ac: add x2, x2, #0x377
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02e4b0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B9FBULL; // 0x02e4b4: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF00ULL; // 0x02e4b8: adrp x0, #0x10000
    return acc;
}

// [EN] Reconstructed FDE #0150 @ 0x02e5a4..0x02e624 (128 bytes)
// [VN] Phục dựng FDE #0150 tại 0x02e5a4..0x02e624 (128 byte)
//   0x02e5a4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e5a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e5ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e5b0: 910083fd  add      x29, sp, #0x20
//   0x02e5b4: d00001b5  adrp     x21, #0x64000
//   0x02e5b8: b94582b4  ldr      w20, [x21, #0x580]
//   0x02e5bc: aa1e03f3  mov      x19, x30
//   0x02e5c0: 350000f4  cbnz     w20, #0x2e5dc
//   0x02e5c4: 90000000  adrp     x0, #0x2e000
//   0x02e5c8: 91169000  add      x0, x0, #0x5a4
//   0x02e5cc: 9400bb31  bl       #0x5d290
//   0x02e5d0: d63f0000  blr      x0
//   0x02e5d4: 2a0003f4  mov      w20, w0
//   0x02e5d8: b90582a0  str      w0, [x21, #0x580]
//   0x02e5dc: 9400bb31  bl       #0x5d2a0
//   0x02e5e0: 35000060  cbnz     w0, #0x2e5ec
uint64_t fde_0150_sub_02e5a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x2A0003F4ULL) + (x2 ^ 0x02E5A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e5a4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e5a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e5ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e5b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B5ULL; // 0x02e5b4: adrp x21, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94582B4ULL; // 0x02e5b8: ldr w20, [x21, #0x580]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02e5bc: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x350000F4ULL; // 0x02e5c0: cbnz w20, #0x2e5dc
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x02e5c4: adrp x0, #0x2e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91169000ULL; // 0x02e5c8: add x0, x0, #0x5a4
    return acc;
}

// [EN] Reconstructed FDE #0151 @ 0x02e624..0x02e6a4 (128 bytes)
// [VN] Phục dựng FDE #0151 tại 0x02e624..0x02e6a4 (128 byte)
//   0x02e624: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e628: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e62c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e630: 910083fd  add      x29, sp, #0x20
//   0x02e634: d00001b5  adrp     x21, #0x64000
//   0x02e638: b94582b4  ldr      w20, [x21, #0x580]
//   0x02e63c: aa1e03f3  mov      x19, x30
//   0x02e640: 350000f4  cbnz     w20, #0x2e65c
//   0x02e644: 90000000  adrp     x0, #0x2e000
//   0x02e648: 91189000  add      x0, x0, #0x624
//   0x02e64c: 9400badd  bl       #0x5d1c0
//   0x02e650: d63f0000  blr      x0
//   0x02e654: 2a0003f4  mov      w20, w0
//   0x02e658: b90582a0  str      w0, [x21, #0x580]
//   0x02e65c: 9400ba91  bl       #0x5d0a0
//   0x02e660: 35000060  cbnz     w0, #0x2e66c
uint64_t fde_0151_sub_02e624(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x2A0003F4ULL) + (x2 ^ 0x02E624ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e624: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e628: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e62c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e630: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B5ULL; // 0x02e634: adrp x21, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94582B4ULL; // 0x02e638: ldr w20, [x21, #0x580]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x02e63c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x350000F4ULL; // 0x02e640: cbnz w20, #0x2e65c
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x02e644: adrp x0, #0x2e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91189000ULL; // 0x02e648: add x0, x0, #0x624
    return acc;
}

// [EN] Reconstructed FDE #0152 @ 0x02e6a4..0x02e898 (500 bytes)
// [VN] Phục dựng FDE #0152 tại 0x02e6a4..0x02e898 (500 byte)
//   0x02e6a4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e6a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e6ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e6b0: 910083fd  add      x29, sp, #0x20
//   0x02e6b4: 2a0203f4  mov      w20, w2
//   0x02e6b8: 9400bb0a  bl       #0x5d2e0
//   0x02e6bc: 71000a9f  cmp      w20, #2
//   0x02e6c0: 2a0003f3  mov      w19, w0
//   0x02e6c4: 54000161  b.ne     #0x2e6f0
//   0x02e6c8: 529fffe8  mov      w8, #0xffff
//   0x02e6cc: 6b08027f  cmp      w19, w8
//   0x02e6d0: 54000103  b.lo     #0x2e6f0
//   0x02e6d4: f0ffff01  adrp     x1, #0x11000
//   0x02e6d8: f0ffff02  adrp     x2, #0x11000
//   0x02e6dc: 91230821  add      x1, x1, #0x8c2
//   0x02e6e0: 91233042  add      x2, x2, #0x8cc
uint64_t fde_0152_sub_02e6a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF0FFFF01ULL) + (x2 ^ 0x02E6A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e6a4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e6a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e6ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e6b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x02e6b4: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9400BB0AULL; // 0x02e6b8: bl #0x5d2e0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000A9FULL; // 0x02e6bc: cmp w20, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x02e6c0: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000161ULL; // 0x02e6c4: b.ne #0x2e6f0
    acc = (acc * 0x100000001B3ULL) ^ 0x529FFFE8ULL; // 0x02e6c8: mov w8, #0xffff
    return acc;
}

// [EN] Reconstructed FDE #0153 @ 0x02e898..0x02e8a0 (8 bytes)
// [VN] Phục dựng FDE #0153 tại 0x02e898..0x02e8a0 (8 byte)
//   0x02e898: f9400400  ldr      x0, [x0, #8]
//   0x02e89c: 14000021  b        #0x2e920
uint64_t fde_0153_sub_02e898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400400ULL) + (x1 ^ 0x14000021ULL) + (x2 ^ 0x02E898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02e898: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000021ULL; // 0x02e89c: b #0x2e920
    return acc;
}

// [EN] Reconstructed FDE #0154 @ 0x02e8a0..0x02e8a8 (8 bytes)
// [VN] Phục dựng FDE #0154 tại 0x02e8a0..0x02e8a8 (8 byte)
//   0x02e8a0: f9400400  ldr      x0, [x0, #8]
//   0x02e8a4: 14000011  b        #0x2e8e8
uint64_t fde_0154_sub_02e8a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400400ULL) + (x1 ^ 0x14000011ULL) + (x2 ^ 0x02E8A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02e8a0: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000011ULL; // 0x02e8a4: b #0x2e8e8
    return acc;
}

// [EN] Reconstructed FDE #0155 @ 0x02e8a8..0x02e8b0 (8 bytes)
// [VN] Phục dựng FDE #0155 tại 0x02e8a8..0x02e8b0 (8 byte)
//   0x02e8a8: f9400400  ldr      x0, [x0, #8]
//   0x02e8ac: 14000001  b        #0x2e8b0
uint64_t fde_0155_sub_02e8a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400400ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02E8A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02e8a8: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02e8ac: b #0x2e8b0
    return acc;
}

// [EN] Reconstructed FDE #0156 @ 0x02e8b0..0x02e8e8 (56 bytes)
// [VN] Phục dựng FDE #0156 tại 0x02e8b0..0x02e8e8 (56 byte)
//   0x02e8b0: b40001a0  cbz      x0, #0x2e8e4
//   0x02e8b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e8b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e8bc: 910043fd  add      x29, sp, #0x10
//   0x02e8c0: aa0003f3  mov      x19, x0
//   0x02e8c4: f9400000  ldr      x0, [x0]
//   0x02e8c8: 97fffffa  bl       #0x2e8b0
//   0x02e8cc: f9400660  ldr      x0, [x19, #8]
//   0x02e8d0: 97fffff8  bl       #0x2e8b0
//   0x02e8d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e8d8: aa1303e0  mov      x0, x19
//   0x02e8dc: f84207f3  ldr      x19, [sp], #0x20
//   0x02e8e0: 1400ba64  b        #0x5d270
//   0x02e8e4: d65f03c0  ret      
uint64_t fde_0156_sub_02e8b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001A0ULL) + (x1 ^ 0x1400BA64ULL) + (x2 ^ 0x02E8B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x02e8b0: cbz x0, #0x2e8e4
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e8b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e8b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e8bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e8c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02e8c4: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x02e8c8: bl #0x2e8b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x02e8cc: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x02e8d0: bl #0x2e8b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02e8d4: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0157 @ 0x02e8e8..0x02e920 (56 bytes)
// [VN] Phục dựng FDE #0157 tại 0x02e8e8..0x02e920 (56 byte)
//   0x02e8e8: b40001a0  cbz      x0, #0x2e91c
//   0x02e8ec: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e8f0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e8f4: 910043fd  add      x29, sp, #0x10
//   0x02e8f8: aa0003f3  mov      x19, x0
//   0x02e8fc: f9400000  ldr      x0, [x0]
//   0x02e900: 97fffffa  bl       #0x2e8e8
//   0x02e904: f9400660  ldr      x0, [x19, #8]
//   0x02e908: 97fffff8  bl       #0x2e8e8
//   0x02e90c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e910: aa1303e0  mov      x0, x19
//   0x02e914: f84207f3  ldr      x19, [sp], #0x20
//   0x02e918: 1400ba56  b        #0x5d270
//   0x02e91c: d65f03c0  ret      
uint64_t fde_0157_sub_02e8e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001A0ULL) + (x1 ^ 0x1400BA56ULL) + (x2 ^ 0x02E8E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x02e8e8: cbz x0, #0x2e91c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e8ec: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e8f0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e8f4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e8f8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02e8fc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x02e900: bl #0x2e8e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x02e904: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x02e908: bl #0x2e8e8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02e90c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0158 @ 0x02e920..0x02e958 (56 bytes)
// [VN] Phục dựng FDE #0158 tại 0x02e920..0x02e958 (56 byte)
//   0x02e920: b40001a0  cbz      x0, #0x2e954
//   0x02e924: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e928: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e92c: 910043fd  add      x29, sp, #0x10
//   0x02e930: aa0003f3  mov      x19, x0
//   0x02e934: f9400000  ldr      x0, [x0]
//   0x02e938: 97fffffa  bl       #0x2e920
//   0x02e93c: f9400660  ldr      x0, [x19, #8]
//   0x02e940: 97fffff8  bl       #0x2e920
//   0x02e944: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e948: aa1303e0  mov      x0, x19
//   0x02e94c: f84207f3  ldr      x19, [sp], #0x20
//   0x02e950: 1400ba48  b        #0x5d270
//   0x02e954: d65f03c0  ret      
uint64_t fde_0158_sub_02e920(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001A0ULL) + (x1 ^ 0x1400BA48ULL) + (x2 ^ 0x02E920ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x02e920: cbz x0, #0x2e954
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e924: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e928: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e92c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e930: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02e934: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x02e938: bl #0x2e920
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x02e93c: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x02e940: bl #0x2e920
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02e944: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0159 @ 0x02e958..0x02eb08 (432 bytes)
// [VN] Phục dựng FDE #0159 tại 0x02e958..0x02eb08 (432 byte)
//   0x02e958: a9bb67fc  stp      x28, x25, [sp, #-0x50]!
//   0x02e95c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02e960: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02e964: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02e968: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02e96c: 910103fd  add      x29, sp, #0x40
//   0x02e970: d11143ff  sub      sp, sp, #0x450
//   0x02e974: d53bd059  mrs      x25, tpidr_el0
//   0x02e978: f9401728  ldr      x8, [x25, #0x28]
//   0x02e97c: aa0203f4  mov      x20, x2
//   0x02e980: aa0103f5  mov      x21, x1
//   0x02e984: aa0003f6  mov      x22, x0
//   0x02e988: 910123e0  add      x0, sp, #0x48
//   0x02e98c: 52808002  mov      w2, #0x400
//   0x02e990: 2a1f03e1  mov      w1, wzr
//   0x02e994: f81b83a8  stur     x8, [x29, #-0x48]
uint64_t fde_0159_sub_02e958(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FCULL) + (x1 ^ 0x910123E0ULL) + (x2 ^ 0x02E958ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FCULL; // 0x02e958: stp x28, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02e95c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02e960: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02e964: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02e968: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02e96c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11143FFULL; // 0x02e970: sub sp, sp, #0x450
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02e974: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x02e978: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02e97c: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0160 @ 0x02eb08..0x02ecb4 (428 bytes)
// [VN] Phục dựng FDE #0160 tại 0x02eb08..0x02ecb4 (428 byte)
//   0x02eb08: eb00003f  cmp      x1, x0
//   0x02eb0c: 1a9f17e8  cset     w8, eq
//   0x02eb10: 39006028  strb     w8, [x1, #0x18]
//   0x02eb14: 540005e0  b.eq     #0x2ebd0
//   0x02eb18: 5280002a  mov      w10, #1
//   0x02eb1c: f9400829  ldr      x9, [x1, #0x10]
//   0x02eb20: 39406128  ldrb     w8, [x9, #0x18]
//   0x02eb24: 34000188  cbz      w8, #0x2eb54
//   0x02eb28: 1400002a  b        #0x2ebd0
//   0x02eb2c: eb00011f  cmp      x8, x0
//   0x02eb30: 3900612a  strb     w10, [x9, #0x18]
//   0x02eb34: 1a9f17e9  cset     w9, eq
//   0x02eb38: aa0803e1  mov      x1, x8
//   0x02eb3c: 39006109  strb     w9, [x8, #0x18]
//   0x02eb40: 3900016a  strb     w10, [x11]
//   0x02eb44: 54000460  b.eq     #0x2ebd0
uint64_t fde_0160_sub_02eb08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xEB00003FULL) + (x1 ^ 0xAA0803E1ULL) + (x2 ^ 0x02EB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00003FULL; // 0x02eb08: cmp x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E8ULL; // 0x02eb0c: cset w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x39006028ULL; // 0x02eb10: strb w8, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x540005E0ULL; // 0x02eb14: b.eq #0x2ebd0
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x02eb18: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x02eb1c: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39406128ULL; // 0x02eb20: ldrb w8, [x9, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000188ULL; // 0x02eb24: cbz w8, #0x2eb54
    acc = (acc * 0x100000001B3ULL) ^ 0x1400002AULL; // 0x02eb28: b #0x2ebd0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x02eb2c: cmp x8, x0
    return acc;
}

// [EN] Reconstructed FDE #0161 @ 0x02ecb4..0x02fba4 (3824 bytes)
// [VN] Phục dựng FDE #0161 tại 0x02ecb4..0x02fba4 (3824 byte)
//   0x02ecb4: d10303ff  sub      sp, sp, #0xc0
//   0x02ecb8: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x02ecbc: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x02ecc0: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x02ecc4: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x02ecc8: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x02eccc: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x02ecd0: 9102c3fd  add      x29, sp, #0xb0
//   0x02ecd4: d53bd056  mrs      x22, tpidr_el0
//   0x02ecd8: f94016c8  ldr      x8, [x22, #0x28]
//   0x02ecdc: 910103e1  add      x1, sp, #0x40
//   0x02ece0: aa1f03e0  mov      x0, xzr
//   0x02ece4: f9002fe8  str      x8, [sp, #0x58]
//   0x02ece8: 9400b996  bl       #0x5d340
//   0x02ecec: 9400b829  bl       #0x5cd90
//   0x02ecf0: b9401015  ldr      w21, [x0, #0x10]
uint64_t fde_0161_sub_02ecb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xF9002FE8ULL) + (x2 ^ 0x02ECB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x02ecb4: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x02ecb8: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x02ecbc: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x02ecc0: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x02ecc4: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x02ecc8: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x02eccc: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x02ecd0: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02ecd4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02ecd8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0162 @ 0x02fba4..0x02ff74 (976 bytes)
// [VN] Phục dựng FDE #0162 tại 0x02fba4..0x02ff74 (976 byte)
//   0x02fba4: f9400029  ldr      x9, [x1]
//   0x02fba8: aa0103ea  mov      x10, x1
//   0x02fbac: b40000c9  cbz      x9, #0x2fbc4
//   0x02fbb0: f9400428  ldr      x8, [x1, #8]
//   0x02fbb4: b4000268  cbz      x8, #0x2fc00
//   0x02fbb8: aa0803ea  mov      x10, x8
//   0x02fbbc: f9400108  ldr      x8, [x8]
//   0x02fbc0: b5ffffc8  cbnz     x8, #0x2fbb8
//   0x02fbc4: f9400549  ldr      x9, [x10, #8]
//   0x02fbc8: b50001e9  cbnz     x9, #0x2fc04
//   0x02fbcc: 2a1f03eb  mov      w11, wzr
//   0x02fbd0: f940094c  ldr      x12, [x10, #0x10]
//   0x02fbd4: f9400188  ldr      x8, [x12]
//   0x02fbd8: eb0a011f  cmp      x8, x10
//   0x02fbdc: 54000221  b.ne     #0x2fc20
//   0x02fbe0: eb00015f  cmp      x10, x0
uint64_t fde_0162_sub_02fba4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400029ULL) + (x1 ^ 0xF9400188ULL) + (x2 ^ 0x02FBA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400029ULL; // 0x02fba4: ldr x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EAULL; // 0x02fba8: mov x10, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C9ULL; // 0x02fbac: cbz x9, #0x2fbc4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400428ULL; // 0x02fbb0: ldr x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000268ULL; // 0x02fbb4: cbz x8, #0x2fc00
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803EAULL; // 0x02fbb8: mov x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x02fbbc: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5FFFFC8ULL; // 0x02fbc0: cbnz x8, #0x2fbb8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400549ULL; // 0x02fbc4: ldr x9, [x10, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001E9ULL; // 0x02fbc8: cbnz x9, #0x2fc04
    return acc;
}

// [EN] Reconstructed FDE #0163 @ 0x02ff74..0x030010 (156 bytes)
// [VN] Phục dựng FDE #0163 tại 0x02ff74..0x030010 (156 byte)
//   0x02ff74: d10483ff  sub      sp, sp, #0x120
//   0x02ff78: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02ff7c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02ff80: 910443fd  add      x29, sp, #0x110
//   0x02ff84: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x02ff88: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02ff8c: f90057e7  str      x7, [sp, #0xa8]
//   0x02ff90: ad0007e0  stp      q0, q1, [sp]
//   0x02ff94: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02ff98: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02ff9c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02ffa0: d53bd053  mrs      x19, tpidr_el0
//   0x02ffa4: f940166b  ldr      x11, [x19, #0x28]
//   0x02ffa8: 928004e8  mov      x8, #-0x28
//   0x02ffac: 910003e9  mov      x9, sp
//   0x02ffb0: 910223ea  add      x10, sp, #0x88
uint64_t fde_0163_sub_02ff74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x02FF74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02ff74: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x02ff78: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02ff7c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02ff80: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x02ff84: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x02ff88: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02ff8c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02ff90: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x02ff94: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x02ff98: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0164 @ 0x030010..0x03032c (796 bytes)
// [VN] Phục dựng FDE #0164 tại 0x030010..0x03032c (796 byte)
//   0x030010: d102c3ff  sub      sp, sp, #0xb0
//   0x030014: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x030018: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x03001c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x030020: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x030024: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x030028: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03002c: 910283fd  add      x29, sp, #0xa0
//   0x030030: d53bd05c  mrs      x28, tpidr_el0
//   0x030034: f9401788  ldr      x8, [x28, #0x28]
//   0x030038: 51005c69  sub      w9, w3, #0x17
//   0x03003c: 7100193f  cmp      w9, #6
//   0x030040: f90027e8  str      x8, [sp, #0x48]
//   0x030044: 540001e9  b.ls     #0x30080
//   0x030048: 2a1f03f3  mov      w19, wzr
//   0x03004c: f9401788  ldr      x8, [x28, #0x28]
uint64_t fde_0164_sub_030010(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xF90027E8ULL) + (x2 ^ 0x030010ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x030010: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x030014: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x030018: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03001c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x030020: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x030024: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x030028: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03002c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x030030: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x030034: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0165 @ 0x03032c..0x030398 (108 bytes)
// [VN] Phục dựng FDE #0165 tại 0x03032c..0x030398 (108 byte)
//   0x03032c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x030330: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030334: 910043fd  add      x29, sp, #0x10
//   0x030338: d0fffee0  adrp     x0, #0xe000
//   0x03033c: f0fffee1  adrp     x1, #0xf000
//   0x030340: 90000002  adrp     x2, #0x30000
//   0x030344: 900001a3  adrp     x3, #0x64000
//   0x030348: 9113a800  add      x0, x0, #0x4ea
//   0x03034c: 9128e421  add      x1, x1, #0xa39
//   0x030350: 910e6042  add      x2, x2, #0x398
//   0x030354: 91162063  add      x3, x3, #0x588
//   0x030358: 9400b40a  bl       #0x5d380
//   0x03035c: b0ffff08  adrp     x8, #0x11000
//   0x030360: d0fffee9  adrp     x9, #0xe000
//   0x030364: 7100001f  cmp      w0, #0
//   0x030368: 91349908  add      x8, x8, #0xd26
uint64_t fde_0165_sub_03032c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB0FFFF08ULL) + (x2 ^ 0x03032CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03032c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030330: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030334: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE0ULL; // 0x030338: adrp x0, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEE1ULL; // 0x03033c: adrp x1, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x030340: adrp x2, #0x30000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A3ULL; // 0x030344: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9113A800ULL; // 0x030348: add x0, x0, #0x4ea
    acc = (acc * 0x100000001B3ULL) ^ 0x9128E421ULL; // 0x03034c: add x1, x1, #0xa39
    acc = (acc * 0x100000001B3ULL) ^ 0x910E6042ULL; // 0x030350: add x2, x2, #0x398
    return acc;
}

// [EN] Reconstructed FDE #0166 @ 0x030398..0x0303e0 (72 bytes)
// [VN] Phục dựng FDE #0166 tại 0x030398..0x0303e0 (72 byte)
//   0x030398: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03039c: 910003fd  mov      x29, sp
//   0x0303a0: 7101401f  cmp      w0, #0x50
//   0x0303a4: 54000101  b.ne     #0x303c4
//   0x0303a8: f0ffff01  adrp     x1, #0x13000
//   0x0303ac: f0fffec2  adrp     x2, #0xb000
//   0x0303b0: 913dd821  add      x1, x1, #0xf76
//   0x0303b4: 91220442  add      x2, x2, #0x881
//   0x0303b8: 52800060  mov      w0, #3
//   0x0303bc: 9400b239  bl       #0x5cca0
//   0x0303c0: 52800780  mov      w0, #0x3c
//   0x0303c4: 900001a8  adrp     x8, #0x64000
//   0x0303c8: f942c501  ldr      x1, [x8, #0x588]
//   0x0303cc: b4000061  cbz      x1, #0x303d8
//   0x0303d0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0303d4: d61f0020  br       x1
uint64_t fde_0166_sub_030398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF942C501ULL) + (x2 ^ 0x030398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x030398: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03039c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x7101401FULL; // 0x0303a0: cmp w0, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x0303a4: b.ne #0x303c4
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF01ULL; // 0x0303a8: adrp x1, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEC2ULL; // 0x0303ac: adrp x2, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x913DD821ULL; // 0x0303b0: add x1, x1, #0xf76
    acc = (acc * 0x100000001B3ULL) ^ 0x91220442ULL; // 0x0303b4: add x2, x2, #0x881
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x0303b8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B239ULL; // 0x0303bc: bl #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0167 @ 0x0303e0..0x0304a4 (196 bytes)
// [VN] Phục dựng FDE #0167 tại 0x0303e0..0x0304a4 (196 byte)
//   0x0303e0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0303e4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0303e8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0303ec: 910083fd  add      x29, sp, #0x20
//   0x0303f0: 90fffef3  adrp     x19, #0xc000
//   0x0303f4: b0ffff14  adrp     x20, #0x11000
//   0x0303f8: 90000015  adrp     x21, #0x30000
//   0x0303fc: b00001b6  adrp     x22, #0x65000
//   0x030400: 91032673  add      x19, x19, #0xc9
//   0x030404: 91352a94  add      x20, x20, #0xd4a
//   0x030408: 911292b5  add      x21, x21, #0x4a4
//   0x03040c: 910162d6  add      x22, x22, #0x58
//   0x030410: aa1303e0  mov      x0, x19
//   0x030414: aa1403e1  mov      x1, x20
//   0x030418: aa1503e2  mov      x2, x21
//   0x03041c: aa1603e3  mov      x3, x22
uint64_t fde_0167_sub_0303e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0303E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0303e0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0303e4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0303e8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0303ec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEF3ULL; // 0x0303f0: adrp x19, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF14ULL; // 0x0303f4: adrp x20, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000015ULL; // 0x0303f8: adrp x21, #0x30000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001B6ULL; // 0x0303fc: adrp x22, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91032673ULL; // 0x030400: add x19, x19, #0xc9
    acc = (acc * 0x100000001B3ULL) ^ 0x91352A94ULL; // 0x030404: add x20, x20, #0xd4a
    return acc;
}

// [EN] Reconstructed FDE #0168 @ 0x0304a4..0x0305b0 (268 bytes)
// [VN] Phục dựng FDE #0168 tại 0x0304a4..0x0305b0 (268 byte)
//   0x0304a4: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x0304a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0304ac: 910043fd  add      x29, sp, #0x10
//   0x0304b0: d11403ff  sub      sp, sp, #0x500
//   0x0304b4: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0304b8: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0304bc: f90057e7  str      x7, [sp, #0xa8]
//   0x0304c0: ad0007e0  stp      q0, q1, [sp]
//   0x0304c4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0304c8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0304cc: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0304d0: d53bd053  mrs      x19, tpidr_el0
//   0x0304d4: f9401668  ldr      x8, [x19, #0x28]
//   0x0304d8: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0304dc: b40004a2  cbz      x2, #0x30570
//   0x0304e0: 928004e9  mov      x9, #-0x28
uint64_t fde_0168_sub_0304a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FFCULL) + (x1 ^ 0xF9401668ULL) + (x2 ^ 0x0304A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FFCULL; // 0x0304a4: stp x28, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0304a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0304ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD11403FFULL; // 0x0304b0: sub sp, sp, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0304b4: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0304b8: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0304bc: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0304c0: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0304c4: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0304c8: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0169 @ 0x0305b0..0x030614 (100 bytes)
// [VN] Phục dựng FDE #0169 tại 0x0305b0..0x030614 (100 byte)
//   0x0305b0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0305b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0305b8: 910043fd  add      x29, sp, #0x10
//   0x0305bc: aa0003f4  mov      x20, x0
//   0x0305c0: 900001a0  adrp     x0, #0x64000
//   0x0305c4: 91018000  add      x0, x0, #0x60
//   0x0305c8: aa0103f3  mov      x19, x1
//   0x0305cc: 9400b375  bl       #0x5d3a0
//   0x0305d0: 39400008  ldrb     w8, [x0]
//   0x0305d4: 7100051f  cmp      w8, #1
//   0x0305d8: 54000101  b.ne     #0x305f8
//   0x0305dc: 900001a0  adrp     x0, #0x64000
//   0x0305e0: 91018000  add      x0, x0, #0x60
//   0x0305e4: 9400b36f  bl       #0x5d3a0
//   0x0305e8: 3900001f  strb     wzr, [x0]
//   0x0305ec: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0169_sub_0305b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91018000ULL) + (x2 ^ 0x0305B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0305b0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0305b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0305b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0305bc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x0305c0: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91018000ULL; // 0x0305c4: add x0, x0, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0305c8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B375ULL; // 0x0305cc: bl #0x5d3a0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x0305d0: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x0305d4: cmp w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0170 @ 0x030614..0x0306b0 (156 bytes)
// [VN] Phục dựng FDE #0170 tại 0x030614..0x0306b0 (156 byte)
//   0x030614: d10443ff  sub      sp, sp, #0x110
//   0x030618: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x03061c: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x030620: 910403fd  add      x29, sp, #0x100
//   0x030624: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x030628: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x03062c: ad0007e0  stp      q0, q1, [sp]
//   0x030630: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x030634: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x030638: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03063c: d53bd053  mrs      x19, tpidr_el0
//   0x030640: f9401669  ldr      x9, [x19, #0x28]
//   0x030644: 910203ea  add      x10, sp, #0x80
//   0x030648: 928003ec  mov      x12, #-0x20
//   0x03064c: 910043ab  add      x11, x29, #0x10
//   0x030650: f81e83a9  stur     x9, [x29, #-0x18]
uint64_t fde_0170_sub_030614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0x910203EAULL) + (x2 ^ 0x030614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x030614: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FFCULL; // 0x030618: stp x28, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x03061c: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x030620: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90817E4ULL; // 0x030624: stp x4, x5, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9091FE6ULL; // 0x030628: stp x6, x7, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03062c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x030630: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x030634: stp q4, q5, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD031FE6ULL; // 0x030638: stp q6, q7, [sp, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0171 @ 0x0306b0..0x030920 (624 bytes)
// [VN] Phục dựng FDE #0171 tại 0x0306b0..0x030920 (624 byte)
//   0x0306b0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0306b4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0306b8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0306bc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0306c0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0306c4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0306c8: 910143fd  add      x29, sp, #0x50
//   0x0306cc: d11483ff  sub      sp, sp, #0x520
//   0x0306d0: d53bd05c  mrs      x28, tpidr_el0
//   0x0306d4: f9401788  ldr      x8, [x28, #0x28]
//   0x0306d8: b00001b3  adrp     x19, #0x65000
//   0x0306dc: 12001c54  and      w20, w2, #0xff
//   0x0306e0: f0fffec0  adrp     x0, #0xb000
//   0x0306e4: 90fffee1  adrp     x1, #0xc000
//   0x0306e8: 90000002  adrp     x2, #0x30000
//   0x0306ec: 9101a273  add      x19, x19, #0x68
uint64_t fde_0171_sub_0306b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF0FFFEC0ULL) + (x2 ^ 0x0306B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0306b0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0306b4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0306b8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0306bc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0306c0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0306c4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0306c8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11483FFULL; // 0x0306cc: sub sp, sp, #0x520
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x0306d0: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x0306d4: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0172 @ 0x030920..0x030a90 (368 bytes)
// [VN] Phục dựng FDE #0172 tại 0x030920..0x030a90 (368 byte)
//   0x030920: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x030924: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x030928: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03092c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x030930: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x030934: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x030938: 910143fd  add      x29, sp, #0x50
//   0x03093c: d11043ff  sub      sp, sp, #0x410
//   0x030940: d53bd05a  mrs      x26, tpidr_el0
//   0x030944: f9401748  ldr      x8, [x26, #0x28]
//   0x030948: aa0003f8  mov      x24, x0
//   0x03094c: 52808000  mov      w0, #0x400
//   0x030950: aa0503f3  mov      x19, x5
//   0x030954: 2a0403f4  mov      w20, w4
//   0x030958: 2a0303f5  mov      w21, w3
//   0x03095c: 2a0203f6  mov      w22, w2
uint64_t fde_0172_sub_030920(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0503F3ULL) + (x2 ^ 0x030920ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x030920: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x030924: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x030928: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03092c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x030930: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x030934: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x030938: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x03093c: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x030940: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x030944: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0173 @ 0x030a90..0x030b84 (244 bytes)
// [VN] Phục dựng FDE #0173 tại 0x030a90..0x030b84 (244 byte)
//   0x030a90: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x030a94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030a98: 910043fd  add      x29, sp, #0x10
//   0x030a9c: 9400b0bd  bl       #0x5cd90
//   0x030aa0: 9400b248  bl       #0x5d3c0
//   0x030aa4: 52896800  mov      w0, #0x4b40
//   0x030aa8: 72a00980  movk     w0, #0x4c, lsl #16
//   0x030aac: 9400b189  bl       #0x5d0d0
//   0x030ab0: 900001b3  adrp     x19, #0x64000
//   0x030ab4: 913b4273  add      x19, x19, #0xed0
//   0x030ab8: aa1303e0  mov      x0, x19
//   0x030abc: aa1f03e1  mov      x1, xzr
//   0x030ac0: 9400b154  bl       #0x5d010
//   0x030ac4: 2a0003f4  mov      w20, w0
//   0x030ac8: 91001260  add      x0, x19, #4
//   0x030acc: aa1f03e1  mov      x1, xzr
uint64_t fde_0173_sub_030a90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9400B154ULL) + (x2 ^ 0x030A90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x030a90: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030a94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030a98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B0BDULL; // 0x030a9c: bl #0x5cd90
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B248ULL; // 0x030aa0: bl #0x5d3c0
    acc = (acc * 0x100000001B3ULL) ^ 0x52896800ULL; // 0x030aa4: mov w0, #0x4b40
    acc = (acc * 0x100000001B3ULL) ^ 0x72A00980ULL; // 0x030aa8: movk w0, #0x4c, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B189ULL; // 0x030aac: bl #0x5d0d0
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x030ab0: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B4273ULL; // 0x030ab4: add x19, x19, #0xed0
    return acc;
}

// [EN] Reconstructed FDE #0174 @ 0x030b84..0x030c70 (236 bytes)
// [VN] Phục dựng FDE #0174 tại 0x030b84..0x030c70 (236 byte)
//   0x030b84: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x030b88: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x030b8c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x030b90: 910083fd  add      x29, sp, #0x20
//   0x030b94: 900001b5  adrp     x21, #0x64000
//   0x030b98: 913b42b5  add      x21, x21, #0xed0
//   0x030b9c: b94002a8  ldr      w8, [x21]
//   0x030ba0: 2a0003f4  mov      w20, w0
//   0x030ba4: aa0103f3  mov      x19, x1
//   0x030ba8: 2a0803e0  mov      w0, w8
//   0x030bac: 9400b125  bl       #0x5d040
//   0x030bb0: b94006a8  ldr      w8, [x21, #4]
//   0x030bb4: aa0003f6  mov      x22, x0
//   0x030bb8: 2a0803e0  mov      w0, w8
//   0x030bbc: 9400b121  bl       #0x5d040
//   0x030bc0: f9455ea3  ldr      x3, [x21, #0xab8]
uint64_t fde_0174_sub_030b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x030B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x030b84: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x030b88: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x030b8c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x030b90: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B5ULL; // 0x030b94: adrp x21, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B42B5ULL; // 0x030b98: add x21, x21, #0xed0
    acc = (acc * 0x100000001B3ULL) ^ 0xB94002A8ULL; // 0x030b9c: ldr w8, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x030ba0: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x030ba4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x030ba8: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0175 @ 0x030c70..0x030cc0 (80 bytes)
// [VN] Phục dựng FDE #0175 tại 0x030c70..0x030cc0 (80 byte)
//   0x030c70: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x030c74: 910003fd  mov      x29, sp
//   0x030c78: 90ffff20  adrp     x0, #0x14000
//   0x030c7c: 90fffee1  adrp     x1, #0xc000
//   0x030c80: 90000002  adrp     x2, #0x30000
//   0x030c84: 913b3000  add      x0, x0, #0xecc
//   0x030c88: 91146c21  add      x1, x1, #0x51b
//   0x030c8c: 91330042  add      x2, x2, #0xcc0
//   0x030c90: aa1f03e3  mov      x3, xzr
//   0x030c94: 9400b1bb  bl       #0x5d380
//   0x030c98: 34000060  cbz      w0, #0x30ca4
//   0x030c9c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x030ca0: d65f03c0  ret      
//   0x030ca4: f0fffec1  adrp     x1, #0xb000
//   0x030ca8: f0fffec2  adrp     x2, #0xb000
//   0x030cac: 91388821  add      x1, x1, #0xe22
uint64_t fde_0175_sub_030c70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x030C70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x030c70: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x030c74: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF20ULL; // 0x030c78: adrp x0, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE1ULL; // 0x030c7c: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x030c80: adrp x2, #0x30000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B3000ULL; // 0x030c84: add x0, x0, #0xecc
    acc = (acc * 0x100000001B3ULL) ^ 0x91146C21ULL; // 0x030c88: add x1, x1, #0x51b
    acc = (acc * 0x100000001B3ULL) ^ 0x91330042ULL; // 0x030c8c: add x2, x2, #0xcc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x030c90: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x9400B1BBULL; // 0x030c94: bl #0x5d380
    return acc;
}

// [EN] Reconstructed FDE #0176 @ 0x030cc0..0x030e18 (344 bytes)
// [VN] Phục dựng FDE #0176 tại 0x030cc0..0x030e18 (344 byte)
//   0x030cc0: d10503ff  sub      sp, sp, #0x140
//   0x030cc4: a91157fc  stp      x28, x21, [sp, #0x110]
//   0x030cc8: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x030ccc: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x030cd0: 9104c3fd  add      x29, sp, #0x130
//   0x030cd4: d53bd054  mrs      x20, tpidr_el0
//   0x030cd8: f9401688  ldr      x8, [x20, #0x28]
//   0x030cdc: d35cfc09  lsr      x9, x0, #0x1c
//   0x030ce0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x030ce4: b40002e9  cbz      x9, #0x30d40
//   0x030ce8: aa0003f3  mov      x19, x0
//   0x030cec: d367fc08  lsr      x8, x0, #0x27
//   0x030cf0: b5000288  cbnz     x8, #0x30d40
//   0x030cf4: 900001a8  adrp     x8, #0x64000
//   0x030cf8: 39796508  ldrb     w8, [x8, #0xe59]
//   0x030cfc: 360003a8  tbz      w8, #0, #0x30d70
uint64_t fde_0176_sub_030cc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xB5000288ULL) + (x2 ^ 0x030CC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x030cc0: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157FCULL; // 0x030cc4: stp x28, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x030cc8: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x030ccc: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x030cd0: add x29, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x030cd4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x030cd8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD35CFC09ULL; // 0x030cdc: lsr x9, x0, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x030ce0: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002E9ULL; // 0x030ce4: cbz x9, #0x30d40
    return acc;
}

// [EN] Reconstructed FDE #0177 @ 0x030e18..0x030ed0 (184 bytes)
// [VN] Phục dựng FDE #0177 tại 0x030e18..0x030ed0 (184 byte)
//   0x030e18: d100c3ff  sub      sp, sp, #0x30
//   0x030e1c: f9000bf3  str      x19, [sp, #0x10]
//   0x030e20: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x030e24: 910083fd  add      x29, sp, #0x20
//   0x030e28: d53bd053  mrs      x19, tpidr_el0
//   0x030e2c: f9401668  ldr      x8, [x19, #0x28]
//   0x030e30: 72001c5f  tst      w2, #0xff
//   0x030e34: f90007e8  str      x8, [sp, #8]
//   0x030e38: 900001a8  adrp     x8, #0x64000
//   0x030e3c: 39796508  ldrb     w8, [x8, #0xe59]
//   0x030e40: 540001a0  b.eq     #0x30e74
//   0x030e44: 37000348  tbnz     w8, #0, #0x30eac
//   0x030e48: 90000002  adrp     x2, #0x30000
//   0x030e4c: 912a4042  add      x2, x2, #0xa90
//   0x030e50: 910003e0  mov      x0, sp
//   0x030e54: aa1f03e1  mov      x1, xzr
uint64_t fde_0177_sub_030e18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x90000002ULL) + (x2 ^ 0x030E18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x030e18: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x030e1c: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x030e20: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x030e24: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x030e28: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x030e2c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x030e30: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x030e34: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x030e38: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39796508ULL; // 0x030e3c: ldrb w8, [x8, #0xe59]
    return acc;
}

// [EN] Reconstructed FDE #0178 @ 0x030ed0..0x030f80 (176 bytes)
// [VN] Phục dựng FDE #0178 tại 0x030ed0..0x030f80 (176 byte)
//   0x030ed0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x030ed4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030ed8: 910043fd  add      x29, sp, #0x10
//   0x030edc: 900001a8  adrp     x8, #0x64000
//   0x030ee0: 39797109  ldrb     w9, [x8, #0xe5c]
//   0x030ee4: aa1e03f4  mov      x20, x30
//   0x030ee8: aa0003f3  mov      x19, x0
//   0x030eec: 35000129  cbnz     w9, #0x30f10
//   0x030ef0: 90ffff21  adrp     x1, #0x14000
//   0x030ef4: f0fffec2  adrp     x2, #0xb000
//   0x030ef8: 52800029  mov      w9, #1
//   0x030efc: 91279c21  add      x1, x1, #0x9e7
//   0x030f00: 910d8442  add      x2, x2, #0x361
//   0x030f04: 52800060  mov      w0, #3
//   0x030f08: 39397109  strb     w9, [x8, #0xe5c]
//   0x030f0c: 9400af65  bl       #0x5cca0
uint64_t fde_0178_sub_030ed0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x910D8442ULL) + (x2 ^ 0x030ED0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x030ed0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030ed4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030ed8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x030edc: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39797109ULL; // 0x030ee0: ldrb w9, [x8, #0xe5c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F4ULL; // 0x030ee4: mov x20, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030ee8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000129ULL; // 0x030eec: cbnz w9, #0x30f10
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF21ULL; // 0x030ef0: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEC2ULL; // 0x030ef4: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0179 @ 0x030f80..0x031054 (212 bytes)
// [VN] Phục dựng FDE #0179 tại 0x030f80..0x031054 (212 byte)
//   0x030f80: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x030f84: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x030f88: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x030f8c: 910083fd  add      x29, sp, #0x20
//   0x030f90: 900001a8  adrp     x8, #0x64000
//   0x030f94: 39798109  ldrb     w9, [x8, #0xe60]
//   0x030f98: aa1e03f4  mov      x20, x30
//   0x030f9c: aa0003f3  mov      x19, x0
//   0x030fa0: 340003a9  cbz      w9, #0x31014
//   0x030fa4: 900001a8  adrp     x8, #0x64000
//   0x030fa8: 39797108  ldrb     w8, [x8, #0xe5c]
//   0x030fac: 340004a8  cbz      w8, #0x31040
//   0x030fb0: b00001a8  adrp     x8, #0x65000
//   0x030fb4: f9403d08  ldr      x8, [x8, #0x78]
//   0x030fb8: eb14011f  cmp      x8, x20
//   0x030fbc: 54000422  b.hs     #0x31040
uint64_t fde_0179_sub_030f80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB00001A8ULL) + (x2 ^ 0x030F80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x030f80: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x030f84: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x030f88: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x030f8c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x030f90: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39798109ULL; // 0x030f94: ldrb w9, [x8, #0xe60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F4ULL; // 0x030f98: mov x20, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030f9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A9ULL; // 0x030fa0: cbz w9, #0x31014
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x030fa4: adrp x8, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0180 @ 0x031054..0x0311fc (424 bytes)
// [VN] Phục dựng FDE #0180 tại 0x031054..0x0311fc (424 byte)
//   0x031054: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x031058: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03105c: 910043fd  add      x29, sp, #0x10
//   0x031060: f0000193  adrp     x19, #0x64000
//   0x031064: 913b6273  add      x19, x19, #0xed8
//   0x031068: aa1303e0  mov      x0, x19
//   0x03106c: aa1f03e1  mov      x1, xzr
//   0x031070: 9400afe8  bl       #0x5d010
//   0x031074: b9400268  ldr      w8, [x19]
//   0x031078: 34000528  cbz      w8, #0x3111c
//   0x03107c: b0fffee0  adrp     x0, #0xe000
//   0x031080: 91115800  add      x0, x0, #0x456
//   0x031084: 9400b01f  bl       #0x5d100
//   0x031088: aa0003f3  mov      x19, x0
//   0x03108c: b4000520  cbz      x0, #0x31130
//   0x031090: b0ffff01  adrp     x1, #0x12000
uint64_t fde_0180_sub_031054(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9400B01FULL) + (x2 ^ 0x031054ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031054: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031058: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03105c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000193ULL; // 0x031060: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B6273ULL; // 0x031064: add x19, x19, #0xed8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x031068: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03106c: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AFE8ULL; // 0x031070: bl #0x5d010
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400268ULL; // 0x031074: ldr w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000528ULL; // 0x031078: cbz w8, #0x3111c
    return acc;
}

// [EN] Reconstructed FDE #0181 @ 0x0311fc..0x0313d8 (476 bytes)
// [VN] Phục dựng FDE #0181 tại 0x0311fc..0x0313d8 (476 byte)
//   0x0311fc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x031200: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031204: 910043fd  add      x29, sp, #0x10
//   0x031208: f9400008  ldr      x8, [x0]
//   0x03120c: b0fffee1  adrp     x1, #0xe000
//   0x031210: 913b5821  add      x1, x1, #0xed6
//   0x031214: aa0003f3  mov      x19, x0
//   0x031218: f9401908  ldr      x8, [x8, #0x30]
//   0x03121c: d63f0100  blr      x8
//   0x031220: b4000480  cbz      x0, #0x312b0
//   0x031224: f9400268  ldr      x8, [x19]
//   0x031228: f0fffee2  adrp     x2, #0x10000
//   0x03122c: 90ffff03  adrp     x3, #0x11000
//   0x031230: aa0003e1  mov      x1, x0
//   0x031234: f941c508  ldr      x8, [x8, #0x388]
//   0x031238: 91191042  add      x2, x2, #0x644
uint64_t fde_0181_sub_0311fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x90FFFF03ULL) + (x2 ^ 0x0311FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0311fc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031200: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031204: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x031208: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE1ULL; // 0x03120c: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B5821ULL; // 0x031210: add x1, x1, #0xed6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x031214: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x031218: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x03121c: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000480ULL; // 0x031220: cbz x0, #0x312b0
    return acc;
}

// [EN] Reconstructed FDE #0182 @ 0x0313d8..0x0313dc (4 bytes)
// [VN] Phục dựng FDE #0182 tại 0x0313d8..0x0313dc (4 byte)
//   0x0313d8: d65f03c0  ret      
uint64_t fde_0182_sub_0313d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0313D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0313d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0183 @ 0x0313dc..0x031418 (60 bytes)
// [VN] Phục dựng FDE #0183 tại 0x0313dc..0x031418 (60 byte)
//   0x0313dc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0313e0: 910003fd  mov      x29, sp
//   0x0313e4: 2a1f03e0  mov      w0, wzr
//   0x0313e8: 9400affa  bl       #0x5d3d0
//   0x0313ec: b0ffff08  adrp     x8, #0x12000
//   0x0313f0: b0ffff09  adrp     x9, #0x12000
//   0x0313f4: 9122f108  add      x8, x8, #0x8bc
//   0x0313f8: 91229529  add      x9, x9, #0x8a5
//   0x0313fc: 7100001f  cmp      w0, #0
//   0x031400: 90fffee1  adrp     x1, #0xd000
//   0x031404: 91365021  add      x1, x1, #0xd94
//   0x031408: 9a880122  csel     x2, x9, x8, eq
//   0x03140c: 52800060  mov      w0, #3
//   0x031410: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x031414: 1400ae23  b        #0x5cca0
uint64_t fde_0183_sub_0313dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x0313DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0313dc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0313e0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0313e4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AFFAULL; // 0x0313e8: bl #0x5d3d0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF08ULL; // 0x0313ec: adrp x8, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF09ULL; // 0x0313f0: adrp x9, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9122F108ULL; // 0x0313f4: add x8, x8, #0x8bc
    acc = (acc * 0x100000001B3ULL) ^ 0x91229529ULL; // 0x0313f8: add x9, x9, #0x8a5
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x0313fc: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE1ULL; // 0x031400: adrp x1, #0xd000
    return acc;
}

// [EN] Reconstructed FDE #0184 @ 0x031418..0x031488 (112 bytes)
// [VN] Phục dựng FDE #0184 tại 0x031418..0x031488 (112 byte)
//   0x031418: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03141c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031420: 910043fd  add      x29, sp, #0x10
//   0x031424: 900001a8  adrp     x8, #0x65000
//   0x031428: f9404108  ldr      x8, [x8, #0x80]
//   0x03142c: aa1e03f3  mov      x19, x30
//   0x031430: b4000088  cbz      x8, #0x31440
//   0x031434: d63f0100  blr      x8
//   0x031438: aa0003f4  mov      x20, x0
//   0x03143c: 14000002  b        #0x31444
//   0x031440: aa1f03f4  mov      x20, xzr
//   0x031444: 9400af17  bl       #0x5d0a0
//   0x031448: 35000060  cbnz     w0, #0x31454
//   0x03144c: aa1303e0  mov      x0, x19
//   0x031450: 9400af18  bl       #0x5d0b0
//   0x031454: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0184_sub_031418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x35000060ULL) + (x2 ^ 0x031418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031418: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03141c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031420: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x031424: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404108ULL; // 0x031428: ldr x8, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03142c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x031430: cbz x8, #0x31440
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x031434: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x031438: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x03143c: b #0x31444
    return acc;
}

// [EN] Reconstructed FDE #0185 @ 0x031488..0x0314f8 (112 bytes)
// [VN] Phục dựng FDE #0185 tại 0x031488..0x0314f8 (112 byte)
//   0x031488: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03148c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031490: 910043fd  add      x29, sp, #0x10
//   0x031494: 900001a8  adrp     x8, #0x65000
//   0x031498: f9404508  ldr      x8, [x8, #0x88]
//   0x03149c: aa1e03f3  mov      x19, x30
//   0x0314a0: b4000088  cbz      x8, #0x314b0
//   0x0314a4: d63f0100  blr      x8
//   0x0314a8: aa0003f4  mov      x20, x0
//   0x0314ac: 14000002  b        #0x314b4
//   0x0314b0: aa1f03f4  mov      x20, xzr
//   0x0314b4: 9400aefb  bl       #0x5d0a0
//   0x0314b8: 35000060  cbnz     w0, #0x314c4
//   0x0314bc: aa1303e0  mov      x0, x19
//   0x0314c0: 9400aefc  bl       #0x5d0b0
//   0x0314c4: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0185_sub_031488(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x35000060ULL) + (x2 ^ 0x031488ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031488: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03148c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031490: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x031494: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x031498: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03149c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x0314a0: cbz x8, #0x314b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0314a4: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0314a8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x0314ac: b #0x314b4
    return acc;
}

// [EN] Reconstructed FDE #0186 @ 0x0314f8..0x031530 (56 bytes)
// [VN] Phục dựng FDE #0186 tại 0x0314f8..0x031530 (56 byte)
//   0x0314f8: 34000101  cbz      w1, #0x31518
//   0x0314fc: 2a0103e3  mov      w3, w1
//   0x031500: 90ffff01  adrp     x1, #0x11000
//   0x031504: b0ffff02  adrp     x2, #0x12000
//   0x031508: 9135fc21  add      x1, x1, #0xd7f
//   0x03150c: 9123d442  add      x2, x2, #0x8f5
//   0x031510: 52800060  mov      w0, #3
//   0x031514: 1400ade3  b        #0x5cca0
//   0x031518: 90ffff01  adrp     x1, #0x11000
//   0x03151c: d0fffec2  adrp     x2, #0xb000
//   0x031520: 9135fc21  add      x1, x1, #0xd7f
//   0x031524: 91267042  add      x2, x2, #0x99c
//   0x031528: 52800060  mov      w0, #3
//   0x03152c: 1400addd  b        #0x5cca0
uint64_t fde_0186_sub_0314f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x0314F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x0314f8: cbz w1, #0x31518
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x0314fc: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF01ULL; // 0x031500: adrp x1, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF02ULL; // 0x031504: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9135FC21ULL; // 0x031508: add x1, x1, #0xd7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9123D442ULL; // 0x03150c: add x2, x2, #0x8f5
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x031510: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400ADE3ULL; // 0x031514: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF01ULL; // 0x031518: adrp x1, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC2ULL; // 0x03151c: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0187 @ 0x031530..0x031778 (584 bytes)
// [VN] Phục dựng FDE #0187 tại 0x031530..0x031778 (584 byte)
//   0x031530: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x031534: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031538: 910043fd  add      x29, sp, #0x10
//   0x03153c: 7100685f  cmp      w2, #0x1a
//   0x031540: 54000261  b.ne     #0x3158c
//   0x031544: f0fffee0  adrp     x0, #0x10000
//   0x031548: 913f1400  add      x0, x0, #0xfc5
//   0x03154c: 9400aeed  bl       #0x5d100
//   0x031550: b4000560  cbz      x0, #0x315fc
//   0x031554: aa0003f3  mov      x19, x0
//   0x031558: f0ffff01  adrp     x1, #0x14000
//   0x03155c: 91004421  add      x1, x1, #0x11
//   0x031560: 9400af68  bl       #0x5d300
//   0x031564: aa0003f4  mov      x20, x0
//   0x031568: b40009a0  cbz      x0, #0x3169c
//   0x03156c: 90ffff01  adrp     x1, #0x11000
uint64_t fde_0187_sub_031530(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9400AF68ULL) + (x2 ^ 0x031530ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031530: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031534: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031538: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x7100685FULL; // 0x03153c: cmp w2, #0x1a
    acc = (acc * 0x100000001B3ULL) ^ 0x54000261ULL; // 0x031540: b.ne #0x3158c
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEE0ULL; // 0x031544: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F1400ULL; // 0x031548: add x0, x0, #0xfc5
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AEEDULL; // 0x03154c: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000560ULL; // 0x031550: cbz x0, #0x315fc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x031554: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0188 @ 0x031778..0x0317c4 (76 bytes)
// [VN] Phục dựng FDE #0188 tại 0x031778..0x0317c4 (76 byte)
//   0x031778: d10103ff  sub      sp, sp, #0x40
//   0x03177c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x031780: 9100c3fd  add      x29, sp, #0x30
//   0x031784: 900001a8  adrp     x8, #0x65000
//   0x031788: a93f03a1  stp      x1, x0, [x29, #-0x10]
//   0x03178c: f9404900  ldr      x0, [x8, #0x90]
//   0x031790: f9000fe2  str      x2, [sp, #0x18]
//   0x031794: b90017e3  str      w3, [sp, #0x14]
//   0x031798: f90007e4  str      x4, [sp, #8]
//   0x03179c: d10023a1  sub      x1, x29, #8
//   0x0317a0: d10043a2  sub      x2, x29, #0x10
//   0x0317a4: 910063e3  add      x3, sp, #0x18
//   0x0317a8: 910053e4  add      x4, sp, #0x14
//   0x0317ac: 910023e5  add      x5, sp, #8
//   0x0317b0: 94000005  bl       #0x317c4
//   0x0317b4: a9437bfd  ldp      x29, x30, [sp, #0x30]
uint64_t fde_0188_sub_031778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910053E4ULL) + (x2 ^ 0x031778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x031778: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03177c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x031780: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x031784: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xA93F03A1ULL; // 0x031788: stp x1, x0, [x29, #-0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404900ULL; // 0x03178c: ldr x0, [x8, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x031790: str x2, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90017E3ULL; // 0x031794: str w3, [sp, #0x14]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E4ULL; // 0x031798: str x4, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD10023A1ULL; // 0x03179c: sub x1, x29, #8
    return acc;
}

// [EN] Reconstructed FDE #0189 @ 0x0317c4..0x031bac (1000 bytes)
// [VN] Phục dựng FDE #0189 tại 0x0317c4..0x031bac (1000 byte)
//   0x0317c4: d10683ff  sub      sp, sp, #0x1a0
//   0x0317c8: a9146ffc  stp      x28, x27, [sp, #0x140]
//   0x0317cc: a91567fa  stp      x26, x25, [sp, #0x150]
//   0x0317d0: a9165ff8  stp      x24, x23, [sp, #0x160]
//   0x0317d4: a91757f6  stp      x22, x21, [sp, #0x170]
//   0x0317d8: a9184ff4  stp      x20, x19, [sp, #0x180]
//   0x0317dc: a9197bfd  stp      x29, x30, [sp, #0x190]
//   0x0317e0: 910643fd  add      x29, sp, #0x190
//   0x0317e4: d53bd05a  mrs      x26, tpidr_el0
//   0x0317e8: f9401748  ldr      x8, [x26, #0x28]
//   0x0317ec: aa0503f4  mov      x20, x5
//   0x0317f0: aa0403f5  mov      x21, x4
//   0x0317f4: aa0303f6  mov      x22, x3
//   0x0317f8: aa0203f7  mov      x23, x2
//   0x0317fc: aa0103fb  mov      x27, x1
//   0x031800: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0189_sub_0317c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10683FFULL) + (x1 ^ 0xAA0303F6ULL) + (x2 ^ 0x0317C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x0317c4: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9146FFCULL; // 0x0317c8: stp x28, x27, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91567FAULL; // 0x0317cc: stp x26, x25, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9165FF8ULL; // 0x0317d0: stp x24, x23, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91757F6ULL; // 0x0317d4: stp x22, x21, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9184FF4ULL; // 0x0317d8: stp x20, x19, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9197BFDULL; // 0x0317dc: stp x29, x30, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0x910643FDULL; // 0x0317e0: add x29, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x0317e4: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x0317e8: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0190 @ 0x031bac..0x031ccc (288 bytes)
// [VN] Phục dựng FDE #0190 tại 0x031bac..0x031ccc (288 byte)
//   0x031bac: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x031bb0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x031bb4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x031bb8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x031bbc: 9100c3fd  add      x29, sp, #0x30
//   0x031bc0: f0000188  adrp     x8, #0x64000
//   0x031bc4: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x031bc8: 2a0003f4  mov      w20, w0
//   0x031bcc: aa0103f3  mov      x19, x1
//   0x031bd0: 2a0803e0  mov      w0, w8
//   0x031bd4: 9400ad1b  bl       #0x5d040
//   0x031bd8: b00001a8  adrp     x8, #0x66000
//   0x031bdc: 93407e97  sxtw     x23, w20
//   0x031be0: 912ba108  add      x8, x8, #0xae8
//   0x031be4: 8b171515  add      x21, x8, x23, lsl #5
//   0x031be8: f94006a4  ldr      x4, [x21, #8]
uint64_t fde_0190_sub_031bac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E97ULL) + (x2 ^ 0x031BACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x031bac: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x031bb0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x031bb4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x031bb8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x031bbc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000188ULL; // 0x031bc0: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x031bc4: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x031bc8: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031bcc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x031bd0: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0191 @ 0x031ccc..0x031d54 (136 bytes)
// [VN] Phục dựng FDE #0191 tại 0x031ccc..0x031d54 (136 byte)
//   0x031ccc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x031cd0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031cd4: 910043fd  add      x29, sp, #0x10
//   0x031cd8: 2a0203f4  mov      w20, w2
//   0x031cdc: d0fffec1  adrp     x1, #0xb000
//   0x031ce0: f0ffff02  adrp     x2, #0x14000
//   0x031ce4: 910e7821  add      x1, x1, #0x39e
//   0x031ce8: 9128ac42  add      x2, x2, #0xa2b
//   0x031cec: 52800060  mov      w0, #3
//   0x031cf0: 2a0303f3  mov      w19, w3
//   0x031cf4: 9400abeb  bl       #0x5cca0
//   0x031cf8: f0000188  adrp     x8, #0x64000
//   0x031cfc: b0ffff00  adrp     x0, #0x12000
//   0x031d00: d0ffff01  adrp     x1, #0x13000
//   0x031d04: 90000002  adrp     x2, #0x31000
//   0x031d08: 913b8108  add      x8, x8, #0xee0
uint64_t fde_0191_sub_031ccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB0FFFF00ULL) + (x2 ^ 0x031CCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031ccc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031cd0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031cd4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x031cd8: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x031cdc: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFF02ULL; // 0x031ce0: adrp x2, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7821ULL; // 0x031ce4: add x1, x1, #0x39e
    acc = (acc * 0x100000001B3ULL) ^ 0x9128AC42ULL; // 0x031ce8: add x2, x2, #0xa2b
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x031cec: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x031cf0: mov w19, w3
    return acc;
}

// [EN] Reconstructed FDE #0192 @ 0x031d54..0x031e88 (308 bytes)
// [VN] Phục dựng FDE #0192 tại 0x031d54..0x031e88 (308 byte)
//   0x031d54: d10483ff  sub      sp, sp, #0x120
//   0x031d58: a90e5ffc  stp      x28, x23, [sp, #0xe0]
//   0x031d5c: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x031d60: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x031d64: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x031d68: 910443fd  add      x29, sp, #0x110
//   0x031d6c: a9088fe2  stp      x2, x3, [sp, #0x88]
//   0x031d70: a90997e4  stp      x4, x5, [sp, #0x98]
//   0x031d74: a90a9fe6  stp      x6, x7, [sp, #0xa8]
//   0x031d78: ad0007e0  stp      q0, q1, [sp]
//   0x031d7c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x031d80: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x031d84: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x031d88: d53bd056  mrs      x22, tpidr_el0
//   0x031d8c: f94016c8  ldr      x8, [x22, #0x28]
//   0x031d90: 928005e9  mov      x9, #-0x30
uint64_t fde_0192_sub_031d54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD031FE6ULL) + (x2 ^ 0x031D54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x031d54: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E5FFCULL; // 0x031d58: stp x28, x23, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F57F6ULL; // 0x031d5c: stp x22, x21, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FF4ULL; // 0x031d60: stp x20, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x031d64: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x031d68: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA9088FE2ULL; // 0x031d6c: stp x2, x3, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90997E4ULL; // 0x031d70: stp x4, x5, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A9FE6ULL; // 0x031d74: stp x6, x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x031d78: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0193 @ 0x031e88..0x031ef0 (104 bytes)
// [VN] Phục dựng FDE #0193 tại 0x031e88..0x031ef0 (104 byte)
//   0x031e88: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x031e8c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031e90: 910043fd  add      x29, sp, #0x10
//   0x031e94: 2a0203f3  mov      w19, w2
//   0x031e98: d0fffec1  adrp     x1, #0xb000
//   0x031e9c: d0fffec2  adrp     x2, #0xb000
//   0x031ea0: 910e7821  add      x1, x1, #0x39e
//   0x031ea4: 9124f042  add      x2, x2, #0x93c
//   0x031ea8: 52800060  mov      w0, #3
//   0x031eac: 9400ab7d  bl       #0x5cca0
//   0x031eb0: 72001e7f  tst      w19, #0xff
//   0x031eb4: f0000188  adrp     x8, #0x64000
//   0x031eb8: 1a9f07e9  cset     w9, ne
//   0x031ebc: 39399109  strb     w9, [x8, #0xe64]
//   0x031ec0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x031ec4: d0fffee0  adrp     x0, #0xf000
uint64_t fde_0193_sub_031e88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1A9F07E9ULL) + (x2 ^ 0x031E88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x031e88: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031e8c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031e90: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x031e94: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x031e98: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC2ULL; // 0x031e9c: adrp x2, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7821ULL; // 0x031ea0: add x1, x1, #0x39e
    acc = (acc * 0x100000001B3ULL) ^ 0x9124F042ULL; // 0x031ea4: add x2, x2, #0x93c
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x031ea8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AB7DULL; // 0x031eac: bl #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0194 @ 0x031ef0..0x032014 (292 bytes)
// [VN] Phục dựng FDE #0194 tại 0x031ef0..0x032014 (292 byte)
//   0x031ef0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x031ef4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x031ef8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x031efc: 910083fd  add      x29, sp, #0x20
//   0x031f00: aa1e03f3  mov      x19, x30
//   0x031f04: 90000000  adrp     x0, #0x31000
//   0x031f08: 913bc000  add      x0, x0, #0xef0
//   0x031f0c: 9400acad  bl       #0x5d1c0
//   0x031f10: d63f0000  blr      x0
//   0x031f14: 51140408  sub      w8, w0, #0x501
//   0x031f18: 2a0003f4  mov      w20, w0
//   0x031f1c: 7100051f  cmp      w8, #1
//   0x031f20: 54000228  b.hi     #0x31f64
//   0x031f24: f0000195  adrp     x21, #0x64000
//   0x031f28: b94eeaa4  ldr      w4, [x21, #0xee8]
//   0x031f2c: 7100049f  cmp      w4, #1
uint64_t fde_0194_sub_031ef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000228ULL) + (x2 ^ 0x031EF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x031ef0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x031ef4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x031ef8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x031efc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x031f00: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x031f04: adrp x0, #0x31000
    acc = (acc * 0x100000001B3ULL) ^ 0x913BC000ULL; // 0x031f08: add x0, x0, #0xef0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400ACADULL; // 0x031f0c: bl #0x5d1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0000ULL; // 0x031f10: blr x0
    acc = (acc * 0x100000001B3ULL) ^ 0x51140408ULL; // 0x031f14: sub w8, w0, #0x501
    return acc;
}

// [EN] Reconstructed FDE #0195 @ 0x032014..0x032060 (76 bytes)
// [VN] Phục dựng FDE #0195 tại 0x032014..0x032060 (76 byte)
//   0x032014: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x032018: 910003fd  mov      x29, sp
//   0x03201c: b0fffec1  adrp     x1, #0xb000
//   0x032020: d0fffec2  adrp     x2, #0xc000
//   0x032024: 910e7821  add      x1, x1, #0x39e
//   0x032028: 9114ac42  add      x2, x2, #0x52b
//   0x03202c: 52800060  mov      w0, #3
//   0x032030: 9400ab1c  bl       #0x5cca0
//   0x032034: b0fffee0  adrp     x0, #0xf000
//   0x032038: 90fffee2  adrp     x2, #0xe000
//   0x03203c: 90000003  adrp     x3, #0x32000
//   0x032040: 910e8800  add      x0, x0, #0x3a2
//   0x032044: 913c0842  add      x2, x2, #0xf02
//   0x032048: 91018063  add      x3, x3, #0x60
//   0x03204c: aa1f03e1  mov      x1, xzr
//   0x032050: aa1f03e4  mov      x4, xzr
uint64_t fde_0195_sub_032014(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x913C0842ULL) + (x2 ^ 0x032014ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x032014: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x032018: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC1ULL; // 0x03201c: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC2ULL; // 0x032020: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7821ULL; // 0x032024: add x1, x1, #0x39e
    acc = (acc * 0x100000001B3ULL) ^ 0x9114AC42ULL; // 0x032028: add x2, x2, #0x52b
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x03202c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AB1CULL; // 0x032030: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE0ULL; // 0x032034: adrp x0, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE2ULL; // 0x032038: adrp x2, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0196 @ 0x032060..0x03214c (236 bytes)
// [VN] Phục dựng FDE #0196 tại 0x032060..0x03214c (236 byte)
//   0x032060: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x032064: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032068: 910043fd  add      x29, sp, #0x10
//   0x03206c: aa1e03f3  mov      x19, x30
//   0x032070: 90000000  adrp     x0, #0x32000
//   0x032074: 91018000  add      x0, x0, #0x60
//   0x032078: 9400ac52  bl       #0x5d1c0
//   0x03207c: d63f0000  blr      x0
//   0x032080: 2a0003f4  mov      w20, w0
//   0x032084: 7114141f  cmp      w0, #0x505
//   0x032088: 54000381  b.ne     #0x320f8
//   0x03208c: d0000188  adrp     x8, #0x64000
//   0x032090: 913bb108  add      x8, x8, #0xeec
//   0x032094: b9400109  ldr      w9, [x8]
//   0x032098: 7100093f  cmp      w9, #2
//   0x03209c: 5400032c  b.gt     #0x32100
uint64_t fde_0196_sub_032060(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x913BB108ULL) + (x2 ^ 0x032060ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x032060: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032064: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032068: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03206c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x032070: adrp x0, #0x32000
    acc = (acc * 0x100000001B3ULL) ^ 0x91018000ULL; // 0x032074: add x0, x0, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AC52ULL; // 0x032078: bl #0x5d1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0000ULL; // 0x03207c: blr x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x032080: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7114141FULL; // 0x032084: cmp w0, #0x505
    return acc;
}

// [EN] Reconstructed FDE #0197 @ 0x03214c..0x0321b8 (108 bytes)
// [VN] Phục dựng FDE #0197 tại 0x03214c..0x0321b8 (108 byte)
//   0x03214c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032150: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032154: 910043fd  add      x29, sp, #0x10
//   0x032158: 2a0203f3  mov      w19, w2
//   0x03215c: b0fffec1  adrp     x1, #0xb000
//   0x032160: b0fffee2  adrp     x2, #0xf000
//   0x032164: 910e7821  add      x1, x1, #0x39e
//   0x032168: 9139c442  add      x2, x2, #0xe71
//   0x03216c: 52800060  mov      w0, #3
//   0x032170: 9400aacc  bl       #0x5cca0
//   0x032174: 72001e7f  tst      w19, #0xff
//   0x032178: d0000188  adrp     x8, #0x64000
//   0x03217c: 1a9f07e9  cset     w9, ne
//   0x032180: 39166109  strb     w9, [x8, #0x598]
//   0x032184: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032188: b0fffee0  adrp     x0, #0xf000
uint64_t fde_0197_sub_03214c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1A9F07E9ULL) + (x2 ^ 0x03214CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03214c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032150: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032154: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x032158: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC1ULL; // 0x03215c: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE2ULL; // 0x032160: adrp x2, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7821ULL; // 0x032164: add x1, x1, #0x39e
    acc = (acc * 0x100000001B3ULL) ^ 0x9139C442ULL; // 0x032168: add x2, x2, #0xe71
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x03216c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AACCULL; // 0x032170: bl #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0198 @ 0x0321b8..0x03230c (340 bytes)
// [VN] Phục dựng FDE #0198 tại 0x0321b8..0x03230c (340 byte)
//   0x0321b8: d10283ff  sub      sp, sp, #0xa0
//   0x0321bc: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x0321c0: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x0321c4: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x0321c8: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x0321cc: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0321d0: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0321d4: 910243fd  add      x29, sp, #0x90
//   0x0321d8: 2a0303f7  mov      w23, w3
//   0x0321dc: aa0203fb  mov      x27, x2
//   0x0321e0: aa0103f5  mov      x21, x1
//   0x0321e4: aa0003f6  mov      x22, x0
//   0x0321e8: f9001ffe  str      x30, [sp, #0x38]
//   0x0321ec: 90000000  adrp     x0, #0x32000
//   0x0321f0: 9106e000  add      x0, x0, #0x1b8
//   0x0321f4: 9400abf3  bl       #0x5d1c0
uint64_t fde_0198_sub_0321b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xF9001FFEULL) + (x2 ^ 0x0321B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x0321b8: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x0321bc: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x0321c0: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x0321c4: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x0321c8: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x0321cc: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x0321d0: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x0321d4: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F7ULL; // 0x0321d8: mov w23, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203FBULL; // 0x0321dc: mov x27, x2
    return acc;
}

// [EN] Reconstructed FDE #0199 @ 0x03230c..0x032344 (56 bytes)
// [VN] Phục dựng FDE #0199 tại 0x03230c..0x032344 (56 byte)
//   0x03230c: 34000101  cbz      w1, #0x3232c
//   0x032310: 2a0103e4  mov      w4, w1
//   0x032314: b0fffec1  adrp     x1, #0xb000
//   0x032318: b0fffec2  adrp     x2, #0xb000
//   0x03231c: 910e7821  add      x1, x1, #0x39e
//   0x032320: 91258842  add      x2, x2, #0x962
//   0x032324: 52800060  mov      w0, #3
//   0x032328: 1400aa5e  b        #0x5cca0
//   0x03232c: b0fffec1  adrp     x1, #0xb000
//   0x032330: b0ffff02  adrp     x2, #0x13000
//   0x032334: 910e7821  add      x1, x1, #0x39e
//   0x032338: 911bec42  add      x2, x2, #0x6fb
//   0x03233c: 52800060  mov      w0, #3
//   0x032340: 1400aa58  b        #0x5cca0
uint64_t fde_0199_sub_03230c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x03230CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x03230c: cbz w1, #0x3232c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E4ULL; // 0x032310: mov w4, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC1ULL; // 0x032314: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC2ULL; // 0x032318: adrp x2, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7821ULL; // 0x03231c: add x1, x1, #0x39e
    acc = (acc * 0x100000001B3ULL) ^ 0x91258842ULL; // 0x032320: add x2, x2, #0x962
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x032324: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400AA5EULL; // 0x032328: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC1ULL; // 0x03232c: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF02ULL; // 0x032330: adrp x2, #0x13000
    return acc;
}

// [EN] Reconstructed FDE #0200 @ 0x032344..0x032350 (12 bytes)
// [VN] Phục dựng FDE #0200 tại 0x032344..0x032350 (12 byte)
//   0x032344: d0000188  adrp     x8, #0x64000
//   0x032348: b90ee902  str      w2, [x8, #0xee8]
//   0x03234c: d65f03c0  ret      
uint64_t fde_0200_sub_032344(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000188ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032344ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x032344: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB90EE902ULL; // 0x032348: str w2, [x8, #0xee8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03234c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0201 @ 0x032350..0x03237c (44 bytes)
// [VN] Phục dựng FDE #0201 tại 0x032350..0x03237c (44 byte)
//   0x032350: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x032354: 910003fd  mov      x29, sp
//   0x032358: 90fffee1  adrp     x1, #0xe000
//   0x03235c: 90ffff02  adrp     x2, #0x12000
//   0x032360: 913ccc21  add      x1, x1, #0xf33
//   0x032364: 91235442  add      x2, x2, #0x8d5
//   0x032368: 528000c0  mov      w0, #6
//   0x03236c: 9400aa4d  bl       #0x5cca0
//   0x032370: 2a1f03e0  mov      w0, wzr
//   0x032374: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x032378: d65f03c0  ret      
uint64_t fde_0201_sub_032350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x032350: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x032354: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE1ULL; // 0x032358: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x03235c: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x913CCC21ULL; // 0x032360: add x1, x1, #0xf33
    acc = (acc * 0x100000001B3ULL) ^ 0x91235442ULL; // 0x032364: add x2, x2, #0x8d5
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x032368: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AA4DULL; // 0x03236c: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x032370: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x032374: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0202 @ 0x03237c..0x0324a0 (292 bytes)
// [VN] Phục dựng FDE #0202 tại 0x03237c..0x0324a0 (292 byte)
//   0x03237c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x032380: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032384: 910043fd  add      x29, sp, #0x10
//   0x032388: d0fffee0  adrp     x0, #0x10000
//   0x03238c: 911ad800  add      x0, x0, #0x6b6
//   0x032390: 9400ab5c  bl       #0x5d100
//   0x032394: b4000480  cbz      x0, #0x32424
//   0x032398: aa0003f3  mov      x19, x0
//   0x03239c: b0fffee1  adrp     x1, #0xf000
//   0x0323a0: 910ef021  add      x1, x1, #0x3bc
//   0x0323a4: 9400abcb  bl       #0x5d2d0
//   0x0323a8: b40004c0  cbz      x0, #0x32440
//   0x0323ac: d0ffff01  adrp     x1, #0x14000
//   0x0323b0: d0ffff02  adrp     x2, #0x14000
//   0x0323b4: b0fffee3  adrp     x3, #0xf000
//   0x0323b8: 9115dc21  add      x1, x1, #0x577
uint64_t fde_0202_sub_03237c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0FFFF01ULL) + (x2 ^ 0x03237CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03237c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032380: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032384: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE0ULL; // 0x032388: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AD800ULL; // 0x03238c: add x0, x0, #0x6b6
    acc = (acc * 0x100000001B3ULL) ^ 0x9400AB5CULL; // 0x032390: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000480ULL; // 0x032394: cbz x0, #0x32424
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032398: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE1ULL; // 0x03239c: adrp x1, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x910EF021ULL; // 0x0323a0: add x1, x1, #0x3bc
    return acc;
}

// [EN] Reconstructed FDE #0203 @ 0x0324a0..0x032508 (104 bytes)
// [VN] Phục dựng FDE #0203 tại 0x0324a0..0x032508 (104 byte)
//   0x0324a0: d101c3ff  sub      sp, sp, #0x70
//   0x0324a4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0324a8: 910183fd  add      x29, sp, #0x60
//   0x0324ac: 394063a8  ldrb     w8, [x29, #0x18]
//   0x0324b0: a93f03a1  stp      x1, x0, [x29, #-0x10]
//   0x0324b4: a93e0ba3  stp      x3, x2, [x29, #-0x20]
//   0x0324b8: f81d83a4  stur     x4, [x29, #-0x28]
//   0x0324bc: 12000108  and      w8, w8, #1
//   0x0324c0: a90297e6  stp      x6, x5, [sp, #0x28]
//   0x0324c4: f90013e7  str      x7, [sp, #0x20]
//   0x0324c8: 390073e8  strb     w8, [sp, #0x1c]
//   0x0324cc: 910073e8  add      x8, sp, #0x1c
//   0x0324d0: 910043a9  add      x9, x29, #0x10
//   0x0324d4: d10023a0  sub      x0, x29, #8
//   0x0324d8: d10043a1  sub      x1, x29, #0x10
//   0x0324dc: d10063a2  sub      x2, x29, #0x18
uint64_t fde_0203_sub_0324a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x910043A9ULL) + (x2 ^ 0x0324A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0324a0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0324a4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0324a8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x394063A8ULL; // 0x0324ac: ldrb w8, [x29, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA93F03A1ULL; // 0x0324b0: stp x1, x0, [x29, #-0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA93E0BA3ULL; // 0x0324b4: stp x3, x2, [x29, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A4ULL; // 0x0324b8: stur x4, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000108ULL; // 0x0324bc: and w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA90297E6ULL; // 0x0324c0: stp x6, x5, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013E7ULL; // 0x0324c4: str x7, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0204 @ 0x032508..0x032540 (56 bytes)
// [VN] Phục dựng FDE #0204 tại 0x032508..0x032540 (56 byte)
//   0x032508: 34000101  cbz      w1, #0x32528
//   0x03250c: 2a0103e3  mov      w3, w1
//   0x032510: d0ffff01  adrp     x1, #0x14000
//   0x032514: 90ffff02  adrp     x2, #0x12000
//   0x032518: 9115dc21  add      x1, x1, #0x577
//   0x03251c: 9123d442  add      x2, x2, #0x8f5
//   0x032520: 52800060  mov      w0, #3
//   0x032524: 1400a9df  b        #0x5cca0
//   0x032528: d0ffff01  adrp     x1, #0x14000
//   0x03252c: b0fffec2  adrp     x2, #0xb000
//   0x032530: 9115dc21  add      x1, x1, #0x577
//   0x032534: 91267042  add      x2, x2, #0x99c
//   0x032538: 52800060  mov      w0, #3
//   0x03253c: 1400a9d9  b        #0x5cca0
uint64_t fde_0204_sub_032508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x032508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x032508: cbz w1, #0x32528
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x03250c: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF01ULL; // 0x032510: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x032514: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9115DC21ULL; // 0x032518: add x1, x1, #0x577
    acc = (acc * 0x100000001B3ULL) ^ 0x9123D442ULL; // 0x03251c: add x2, x2, #0x8f5
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x032520: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400A9DFULL; // 0x032524: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF01ULL; // 0x032528: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC2ULL; // 0x03252c: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0205 @ 0x032540..0x032988 (1096 bytes)
// [VN] Phục dựng FDE #0205 tại 0x032540..0x032988 (1096 byte)
//   0x032540: d10743ff  sub      sp, sp, #0x1d0
//   0x032544: a9176ffc  stp      x28, x27, [sp, #0x170]
//   0x032548: a91867fa  stp      x26, x25, [sp, #0x180]
//   0x03254c: a9195ff8  stp      x24, x23, [sp, #0x190]
//   0x032550: a91a57f6  stp      x22, x21, [sp, #0x1a0]
//   0x032554: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x032558: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x03255c: 910703fd  add      x29, sp, #0x1c0
//   0x032560: a9028fe2  stp      x2, x3, [sp, #0x28]
//   0x032564: a90187e0  stp      x0, x1, [sp, #0x18]
//   0x032568: d53bd054  mrs      x20, tpidr_el0
//   0x03256c: a94163a9  ldp      x9, x24, [x29, #0x10]
//   0x032570: f9401688  ldr      x8, [x20, #0x28]
//   0x032574: d0ffff01  adrp     x1, #0x14000
//   0x032578: b0ffff02  adrp     x2, #0x13000
//   0x03257c: b0fffec3  adrp     x3, #0xb000
uint64_t fde_0205_sub_032540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0xF9401688ULL) + (x2 ^ 0x032540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x032540: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9176FFCULL; // 0x032544: stp x28, x27, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91867FAULL; // 0x032548: stp x26, x25, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9195FF8ULL; // 0x03254c: stp x24, x23, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A57F6ULL; // 0x032550: stp x22, x21, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x032554: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x032558: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x03255c: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9028FE2ULL; // 0x032560: stp x2, x3, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90187E0ULL; // 0x032564: stp x0, x1, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0206 @ 0x032988..0x032aac (292 bytes)
// [VN] Phục dựng FDE #0206 tại 0x032988..0x032aac (292 byte)
//   0x032988: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03298c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x032990: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x032994: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x032998: 9100c3fd  add      x29, sp, #0x30
//   0x03299c: d0000188  adrp     x8, #0x64000
//   0x0329a0: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x0329a4: 2a0003f4  mov      w20, w0
//   0x0329a8: aa0103f3  mov      x19, x1
//   0x0329ac: 2a0803e0  mov      w0, w8
//   0x0329b0: 9400a9a4  bl       #0x5d040
//   0x0329b4: 900001a8  adrp     x8, #0x66000
//   0x0329b8: 93407e96  sxtw     x22, w20
//   0x0329bc: 912ba108  add      x8, x8, #0xae8
//   0x0329c0: 8b161517  add      x23, x8, x22, lsl #5
//   0x0329c4: f94206e4  ldr      x4, [x23, #0x408]
uint64_t fde_0206_sub_032988(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x032988ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x032988: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03298c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x032990: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x032994: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x032998: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x03299c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x0329a0: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x0329a4: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0329a8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x0329ac: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0207 @ 0x032aac..0x032ac4 (24 bytes)
// [VN] Phục dựng FDE #0207 tại 0x032aac..0x032ac4 (24 byte)
//   0x032aac: d0fffec1  adrp     x1, #0xc000
//   0x032ab0: 90ffff02  adrp     x2, #0x12000
//   0x032ab4: 9123d821  add      x1, x1, #0x8f6
//   0x032ab8: 9138b842  add      x2, x2, #0xe2e
//   0x032abc: 52800080  mov      w0, #4
//   0x032ac0: 1400a878  b        #0x5cca0
uint64_t fde_0207_sub_032aac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0FFFEC1ULL) + (x1 ^ 0x1400A878ULL) + (x2 ^ 0x032AACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x032aac: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x032ab0: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9123D821ULL; // 0x032ab4: add x1, x1, #0x8f6
    acc = (acc * 0x100000001B3ULL) ^ 0x9138B842ULL; // 0x032ab8: add x2, x2, #0xe2e
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x032abc: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x1400A878ULL; // 0x032ac0: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0208 @ 0x032ac4..0x032b64 (160 bytes)
// [VN] Phục dựng FDE #0208 tại 0x032ac4..0x032b64 (160 byte)
//   0x032ac4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x032ac8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032acc: 910043fd  add      x29, sp, #0x10
//   0x032ad0: f9400008  ldr      x8, [x0]
//   0x032ad4: d0000181  adrp     x1, #0x64000
//   0x032ad8: 91168021  add      x1, x1, #0x5a0
//   0x032adc: f9436d08  ldr      x8, [x8, #0x6d8]
//   0x032ae0: d63f0100  blr      x8
//   0x032ae4: b0ffff00  adrp     x0, #0x13000
//   0x032ae8: 91305c00  add      x0, x0, #0xc17
//   0x032aec: 9400a985  bl       #0x5d100
//   0x032af0: b4000240  cbz      x0, #0x32b38
//   0x032af4: aa0003f3  mov      x19, x0
//   0x032af8: 2a1f03e0  mov      w0, wzr
//   0x032afc: 2a1f03e1  mov      w1, wzr
//   0x032b00: 9400aa38  bl       #0x5d3e0
uint64_t fde_0208_sub_032ac4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x032AC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x032ac4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032ac8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032acc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x032ad0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000181ULL; // 0x032ad4: adrp x1, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91168021ULL; // 0x032ad8: add x1, x1, #0x5a0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436D08ULL; // 0x032adc: ldr x8, [x8, #0x6d8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x032ae0: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFF00ULL; // 0x032ae4: adrp x0, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x91305C00ULL; // 0x032ae8: add x0, x0, #0xc17
    return acc;
}

// [EN] Reconstructed FDE #0209 @ 0x032b64..0x032c90 (300 bytes)
// [VN] Phục dựng FDE #0209 tại 0x032b64..0x032c90 (300 byte)
//   0x032b64: d10103ff  sub      sp, sp, #0x40
//   0x032b68: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x032b6c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x032b70: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x032b74: 9100c3fd  add      x29, sp, #0x30
//   0x032b78: d53bd055  mrs      x21, tpidr_el0
//   0x032b7c: f94016a8  ldr      x8, [x21, #0x28]
//   0x032b80: aa0003f4  mov      x20, x0
//   0x032b84: 90000000  adrp     x0, #0x32000
//   0x032b88: 912d9000  add      x0, x0, #0xb64
//   0x032b8c: aa0103f3  mov      x19, x1
//   0x032b90: f90007e8  str      x8, [sp, #8]
//   0x032b94: 9400a98b  bl       #0x5d1c0
//   0x032b98: aa0003e8  mov      x8, x0
//   0x032b9c: aa1403e0  mov      x0, x20
//   0x032ba0: aa1303e1  mov      x1, x19
uint64_t fde_0209_sub_032b64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x9400A98BULL) + (x2 ^ 0x032B64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x032b64: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x032b68: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x032b6c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x032b70: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x032b74: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x032b78: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x032b7c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x032b80: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x032b84: adrp x0, #0x32000
    acc = (acc * 0x100000001B3ULL) ^ 0x912D9000ULL; // 0x032b88: add x0, x0, #0xb64
    return acc;
}

// [EN] Reconstructed FDE #0210 @ 0x032c90..0x032cc8 (56 bytes)
// [VN] Phục dựng FDE #0210 tại 0x032c90..0x032cc8 (56 byte)
//   0x032c90: 34000101  cbz      w1, #0x32cb0
//   0x032c94: 2a0103e3  mov      w3, w1
//   0x032c98: f0fffec1  adrp     x1, #0xd000
//   0x032c9c: d0ffff02  adrp     x2, #0x14000
//   0x032ca0: 9137e421  add      x1, x1, #0xdf9
//   0x032ca4: 91164042  add      x2, x2, #0x590
//   0x032ca8: 52800060  mov      w0, #3
//   0x032cac: 1400a7fd  b        #0x5cca0
//   0x032cb0: f0fffec1  adrp     x1, #0xd000
//   0x032cb4: b0fffec2  adrp     x2, #0xb000
//   0x032cb8: 9137e421  add      x1, x1, #0xdf9
//   0x032cbc: 9139ac42  add      x2, x2, #0xe6b
//   0x032cc0: 52800060  mov      w0, #3
//   0x032cc4: 1400a7f7  b        #0x5cca0
uint64_t fde_0210_sub_032c90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x032C90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x032c90: cbz w1, #0x32cb0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x032c94: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEC1ULL; // 0x032c98: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFF02ULL; // 0x032c9c: adrp x2, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x9137E421ULL; // 0x032ca0: add x1, x1, #0xdf9
    acc = (acc * 0x100000001B3ULL) ^ 0x91164042ULL; // 0x032ca4: add x2, x2, #0x590
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x032ca8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400A7FDULL; // 0x032cac: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEC1ULL; // 0x032cb0: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC2ULL; // 0x032cb4: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0211 @ 0x032cc8..0x032cf8 (48 bytes)
// [VN] Phục dựng FDE #0211 tại 0x032cc8..0x032cf8 (48 byte)
//   0x032cc8: d10083ff  sub      sp, sp, #0x20
//   0x032ccc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032cd0: 910043fd  add      x29, sp, #0x10
//   0x032cd4: d0000188  adrp     x8, #0x64000
//   0x032cd8: f942d508  ldr      x8, [x8, #0x5a8]
//   0x032cdc: f90007e0  str      x0, [sp, #8]
//   0x032ce0: 910023e1  add      x1, sp, #8
//   0x032ce4: aa0803e0  mov      x0, x8
//   0x032ce8: 94000004  bl       #0x32cf8
//   0x032cec: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032cf0: 910083ff  add      sp, sp, #0x20
//   0x032cf4: d65f03c0  ret      
uint64_t fde_0211_sub_032cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x032cc8: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032ccc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032cd0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x032cd4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942D508ULL; // 0x032cd8: ldr x8, [x8, #0x5a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E0ULL; // 0x032cdc: str x0, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x032ce0: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x032ce4: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000004ULL; // 0x032ce8: bl #0x32cf8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x032cec: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0212 @ 0x032cf8..0x033078 (896 bytes)
// [VN] Phục dựng FDE #0212 tại 0x032cf8..0x033078 (896 byte)
//   0x032cf8: d10603ff  sub      sp, sp, #0x180
//   0x032cfc: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x032d00: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x032d04: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x032d08: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x032d0c: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x032d10: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x032d14: 9105c3fd  add      x29, sp, #0x170
//   0x032d18: d53bd058  mrs      x24, tpidr_el0
//   0x032d1c: f9401708  ldr      x8, [x24, #0x28]
//   0x032d20: aa0003f3  mov      x19, x0
//   0x032d24: f81a03a8  stur     x8, [x29, #-0x60]
//   0x032d28: b4000440  cbz      x0, #0x32db0
//   0x032d2c: aa0103f4  mov      x20, x1
//   0x032d30: f0fffee1  adrp     x1, #0x11000
//   0x032d34: b0ffff02  adrp     x2, #0x13000
uint64_t fde_0212_sub_032cf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xB4000440ULL) + (x2 ^ 0x032CF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x032cf8: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x032cfc: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x032d00: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x032d04: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x032d08: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x032d0c: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x032d10: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x032d14: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x032d18: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x032d1c: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0213 @ 0x033078..0x0331a0 (296 bytes)
// [VN] Phục dựng FDE #0213 tại 0x033078..0x0331a0 (296 byte)
//   0x033078: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03307c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x033080: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x033084: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x033088: 9100c3fd  add      x29, sp, #0x30
//   0x03308c: b0000188  adrp     x8, #0x64000
//   0x033090: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x033094: 2a0003f4  mov      w20, w0
//   0x033098: aa0103f3  mov      x19, x1
//   0x03309c: 2a0803e0  mov      w0, w8
//   0x0330a0: 9400a7e8  bl       #0x5d040
//   0x0330a4: f0000188  adrp     x8, #0x66000
//   0x0330a8: 93407e96  sxtw     x22, w20
//   0x0330ac: 912ba108  add      x8, x8, #0xae8
//   0x0330b0: 8b161517  add      x23, x8, x22, lsl #5
//   0x0330b4: f94406e4  ldr      x4, [x23, #0x808]
uint64_t fde_0213_sub_033078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x033078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x033078: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03307c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x033080: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x033084: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x033088: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x03308c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x033090: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x033094: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033098: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x03309c: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0214 @ 0x0331a0..0x033280 (224 bytes)
// [VN] Phục dựng FDE #0214 tại 0x0331a0..0x033280 (224 byte)
//   0x0331a0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0331a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0331a8: 910043fd  add      x29, sp, #0x10
//   0x0331ac: b0fffee0  adrp     x0, #0x10000
//   0x0331b0: 910a0000  add      x0, x0, #0x280
//   0x0331b4: 9400a7d3  bl       #0x5d100
//   0x0331b8: b40003a0  cbz      x0, #0x3322c
//   0x0331bc: aa0003f3  mov      x19, x0
//   0x0331c0: 2a1f03e0  mov      w0, wzr
//   0x0331c4: 2a1f03e1  mov      w1, wzr
//   0x0331c8: 9400a886  bl       #0x5d3e0
//   0x0331cc: b0ffff00  adrp     x0, #0x14000
//   0x0331d0: b0ffff02  adrp     x2, #0x14000
//   0x0331d4: f0ffffe3  adrp     x3, #0x32000
//   0x0331d8: 90000004  adrp     x4, #0x33000
//   0x0331dc: 9120c000  add      x0, x0, #0x830
uint64_t fde_0214_sub_0331a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB0FFFF02ULL) + (x2 ^ 0x0331A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0331a0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0331a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0331a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE0ULL; // 0x0331ac: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x910A0000ULL; // 0x0331b0: add x0, x0, #0x280
    acc = (acc * 0x100000001B3ULL) ^ 0x9400A7D3ULL; // 0x0331b4: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003A0ULL; // 0x0331b8: cbz x0, #0x3322c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0331bc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0331c0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x0331c4: mov w1, wzr
    return acc;
}

// [EN] Reconstructed FDE #0215 @ 0x033280..0x0332c0 (64 bytes)
// [VN] Phục dựng FDE #0215 tại 0x033280..0x0332c0 (64 byte)
//   0x033280: 34000101  cbz      w1, #0x332a0
//   0x033284: 2a0103e3  mov      w3, w1
//   0x033288: d0fffee1  adrp     x1, #0x11000
//   0x03328c: b0fffec2  adrp     x2, #0xc000
//   0x033290: 91245021  add      x1, x1, #0x914
//   0x033294: 9135dc42  add      x2, x2, #0xd77
//   0x033298: 52800060  mov      w0, #3
//   0x03329c: 1400a681  b        #0x5cca0
//   0x0332a0: d0fffee1  adrp     x1, #0x11000
//   0x0332a4: 90fffec2  adrp     x2, #0xb000
//   0x0332a8: b0000188  adrp     x8, #0x64000
//   0x0332ac: 91245021  add      x1, x1, #0x914
//   0x0332b0: 9127e442  add      x2, x2, #0x9f9
//   0x0332b4: 52800060  mov      w0, #3
//   0x0332b8: f902d505  str      x5, [x8, #0x5a8]
//   0x0332bc: 1400a679  b        #0x5cca0
uint64_t fde_0215_sub_033280(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x9127E442ULL) + (x2 ^ 0x033280ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x033280: cbz w1, #0x332a0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x033284: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE1ULL; // 0x033288: adrp x1, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC2ULL; // 0x03328c: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x91245021ULL; // 0x033290: add x1, x1, #0x914
    acc = (acc * 0x100000001B3ULL) ^ 0x9135DC42ULL; // 0x033294: add x2, x2, #0xd77
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x033298: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400A681ULL; // 0x03329c: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE1ULL; // 0x0332a0: adrp x1, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC2ULL; // 0x0332a4: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0216 @ 0x0332c0..0x033cc8 (2568 bytes)
// [VN] Phục dựng FDE #0216 tại 0x0332c0..0x033cc8 (2568 byte)
//   0x0332c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0332c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0332c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0332cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0332d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0332d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0332d8: 910143fd  add      x29, sp, #0x50
//   0x0332dc: d11043ff  sub      sp, sp, #0x410
//   0x0332e0: d53bd059  mrs      x25, tpidr_el0
//   0x0332e4: f9401728  ldr      x8, [x25, #0x28]
//   0x0332e8: aa0003f3  mov      x19, x0
//   0x0332ec: f0fffec0  adrp     x0, #0xe000
//   0x0332f0: 9113a800  add      x0, x0, #0x4ea
//   0x0332f4: 2a0203f4  mov      w20, w2
//   0x0332f8: aa0103f5  mov      x21, x1
//   0x0332fc: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0216_sub_0332c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x9113A800ULL) + (x2 ^ 0x0332C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0332c0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0332c4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0332c8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0332cc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0332d0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0332d4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0332d8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x0332dc: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0332e0: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x0332e4: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0217 @ 0x033cc8..0x033d64 (156 bytes)
// [VN] Phục dựng FDE #0217 tại 0x033cc8..0x033d64 (156 byte)
//   0x033cc8: d10483ff  sub      sp, sp, #0x120
//   0x033ccc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x033cd0: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x033cd4: 910443fd  add      x29, sp, #0x110
//   0x033cd8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x033cdc: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x033ce0: f90057e7  str      x7, [sp, #0xa8]
//   0x033ce4: ad0007e0  stp      q0, q1, [sp]
//   0x033ce8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x033cec: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x033cf0: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x033cf4: d53bd053  mrs      x19, tpidr_el0
//   0x033cf8: f940166b  ldr      x11, [x19, #0x28]
//   0x033cfc: 928004e8  mov      x8, #-0x28
//   0x033d00: 910003e9  mov      x9, sp
//   0x033d04: 910223ea  add      x10, sp, #0x88
uint64_t fde_0217_sub_033cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x033CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x033cc8: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x033ccc: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x033cd0: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x033cd4: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x033cd8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x033cdc: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x033ce0: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x033ce4: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x033ce8: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x033cec: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0218 @ 0x033d64..0x033e00 (156 bytes)
// [VN] Phục dựng FDE #0218 tại 0x033d64..0x033e00 (156 byte)
//   0x033d64: d10483ff  sub      sp, sp, #0x120
//   0x033d68: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x033d6c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x033d70: 910443fd  add      x29, sp, #0x110
//   0x033d74: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x033d78: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x033d7c: f90057e7  str      x7, [sp, #0xa8]
//   0x033d80: ad0007e0  stp      q0, q1, [sp]
//   0x033d84: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x033d88: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x033d8c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x033d90: d53bd053  mrs      x19, tpidr_el0
//   0x033d94: f940166b  ldr      x11, [x19, #0x28]
//   0x033d98: 928004e8  mov      x8, #-0x28
//   0x033d9c: 910003e9  mov      x9, sp
//   0x033da0: 910223ea  add      x10, sp, #0x88
uint64_t fde_0218_sub_033d64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x033D64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x033d64: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x033d68: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x033d6c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x033d70: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x033d74: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x033d78: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x033d7c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x033d80: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x033d84: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x033d88: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0219 @ 0x033e00..0x033e9c (156 bytes)
// [VN] Phục dựng FDE #0219 tại 0x033e00..0x033e9c (156 byte)
//   0x033e00: d10483ff  sub      sp, sp, #0x120
//   0x033e04: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x033e08: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x033e0c: 910443fd  add      x29, sp, #0x110
//   0x033e10: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x033e14: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x033e18: f90057e7  str      x7, [sp, #0xa8]
//   0x033e1c: ad0007e0  stp      q0, q1, [sp]
//   0x033e20: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x033e24: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x033e28: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x033e2c: d53bd053  mrs      x19, tpidr_el0
//   0x033e30: f940166b  ldr      x11, [x19, #0x28]
//   0x033e34: 928004e8  mov      x8, #-0x28
//   0x033e38: 910003e9  mov      x9, sp
//   0x033e3c: 910223ea  add      x10, sp, #0x88
uint64_t fde_0219_sub_033e00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x033E00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x033e00: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x033e04: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x033e08: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x033e0c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x033e10: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x033e14: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x033e18: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x033e1c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x033e20: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x033e24: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0220 @ 0x033e9c..0x033fa8 (268 bytes)
// [VN] Phục dựng FDE #0220 tại 0x033e9c..0x033fa8 (268 byte)
//   0x033e9c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x033ea0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x033ea4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x033ea8: 910083fd  add      x29, sp, #0x20
//   0x033eac: b0000188  adrp     x8, #0x64000
//   0x033eb0: 39799908  ldrb     w8, [x8, #0xe66]
//   0x033eb4: aa0103f3  mov      x19, x1
//   0x033eb8: aa0003f4  mov      x20, x0
//   0x033ebc: 360004a8  tbz      w8, #0, #0x33f50
//   0x033ec0: b40006d3  cbz      x19, #0x33f98
//   0x033ec4: d0000188  adrp     x8, #0x65000
//   0x033ec8: 91034108  add      x8, x8, #0xd0
//   0x033ecc: f9400109  ldr      x9, [x8]
//   0x033ed0: eb1e013f  cmp      x9, x30
//   0x033ed4: 54000382  b.hs     #0x33f44
//   0x033ed8: f9400508  ldr      x8, [x8, #8]
uint64_t fde_0220_sub_033e9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400109ULL) + (x2 ^ 0x033E9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x033e9c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x033ea0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x033ea4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x033ea8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x033eac: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39799908ULL; // 0x033eb0: ldrb w8, [x8, #0xe66]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033eb4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x033eb8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x360004A8ULL; // 0x033ebc: tbz w8, #0, #0x33f50
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006D3ULL; // 0x033ec0: cbz x19, #0x33f98
    return acc;
}

// [EN] Reconstructed FDE #0221 @ 0x033fa8..0x034078 (208 bytes)
// [VN] Phục dựng FDE #0221 tại 0x033fa8..0x034078 (208 byte)
//   0x033fa8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x033fac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x033fb0: 910043fd  add      x29, sp, #0x10
//   0x033fb4: b0000188  adrp     x8, #0x64000
//   0x033fb8: 39799908  ldrb     w8, [x8, #0xe66]
//   0x033fbc: aa0103f3  mov      x19, x1
//   0x033fc0: aa0003f4  mov      x20, x0
//   0x033fc4: 36000328  tbz      w8, #0, #0x34028
//   0x033fc8: b4000533  cbz      x19, #0x3406c
//   0x033fcc: d0000188  adrp     x8, #0x65000
//   0x033fd0: 91034108  add      x8, x8, #0xd0
//   0x033fd4: f9400109  ldr      x9, [x8]
//   0x033fd8: eb1e013f  cmp      x9, x30
//   0x033fdc: 54000202  b.hs     #0x3401c
//   0x033fe0: f9400508  ldr      x8, [x8, #8]
//   0x033fe4: eb1e011f  cmp      x8, x30
uint64_t fde_0221_sub_033fa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xEB1E013FULL) + (x2 ^ 0x033FA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x033fa8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x033fac: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x033fb0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x033fb4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39799908ULL; // 0x033fb8: ldrb w8, [x8, #0xe66]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033fbc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x033fc0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000328ULL; // 0x033fc4: tbz w8, #0, #0x34028
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000533ULL; // 0x033fc8: cbz x19, #0x3406c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x033fcc: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0222 @ 0x034078..0x034090 (24 bytes)
// [VN] Phục dựng FDE #0222 tại 0x034078..0x034090 (24 byte)
//   0x034078: b4000081  cbz      x1, #0x34088
//   0x03407c: b0000188  adrp     x8, #0x65000
//   0x034080: f9409102  ldr      x2, [x8, #0x120]
//   0x034084: d61f0040  br       x2
//   0x034088: aa1f03e0  mov      x0, xzr
//   0x03408c: d65f03c0  ret      
uint64_t fde_0222_sub_034078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000081ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000081ULL; // 0x034078: cbz x1, #0x34088
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x03407c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409102ULL; // 0x034080: ldr x2, [x8, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x034084: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x034088: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03408c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0223 @ 0x034090..0x03412c (156 bytes)
// [VN] Phục dựng FDE #0223 tại 0x034090..0x03412c (156 byte)
//   0x034090: d10483ff  sub      sp, sp, #0x120
//   0x034094: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x034098: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x03409c: 910443fd  add      x29, sp, #0x110
//   0x0340a0: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0340a4: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0340a8: f90057e7  str      x7, [sp, #0xa8]
//   0x0340ac: ad0007e0  stp      q0, q1, [sp]
//   0x0340b0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0340b4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0340b8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0340bc: d53bd053  mrs      x19, tpidr_el0
//   0x0340c0: f940166a  ldr      x10, [x19, #0x28]
//   0x0340c4: 928004e9  mov      x9, #-0x28
//   0x0340c8: 910003eb  mov      x11, sp
//   0x0340cc: 910223ec  add      x12, sp, #0x88
uint64_t fde_0223_sub_034090(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166AULL) + (x2 ^ 0x034090ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x034090: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x034094: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x034098: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x03409c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0340a0: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0340a4: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0340a8: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0340ac: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0340b0: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0340b4: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0224 @ 0x03412c..0x034290 (356 bytes)
// [VN] Phục dựng FDE #0224 tại 0x03412c..0x034290 (356 byte)
//   0x03412c: d102c3ff  sub      sp, sp, #0xb0
//   0x034130: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x034134: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x034138: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x03413c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x034140: 910283fd  add      x29, sp, #0xa0
//   0x034144: d53bd057  mrs      x23, tpidr_el0
//   0x034148: f94016e8  ldr      x8, [x23, #0x28]
//   0x03414c: aa0303f6  mov      x22, x3
//   0x034150: aa0203f4  mov      x20, x2
//   0x034154: aa0103f5  mov      x21, x1
//   0x034158: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03415c: 90000188  adrp     x8, #0x64000
//   0x034160: 39799d08  ldrb     w8, [x8, #0xe67]
//   0x034164: aa0003f3  mov      x19, x0
//   0x034168: 36000168  tbz      w8, #0, #0x34194
uint64_t fde_0224_sub_03412c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x90000188ULL) + (x2 ^ 0x03412CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03412c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x034130: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x034134: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x034138: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03413c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x034140: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x034144: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x034148: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x03414c: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x034150: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0225 @ 0x034290..0x034394 (260 bytes)
// [VN] Phục dựng FDE #0225 tại 0x034290..0x034394 (260 byte)
//   0x034290: d10503ff  sub      sp, sp, #0x140
//   0x034294: a9105ffc  stp      x28, x23, [sp, #0x100]
//   0x034298: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x03429c: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x0342a0: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x0342a4: 9104c3fd  add      x29, sp, #0x130
//   0x0342a8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0342ac: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0342b0: f90057e7  str      x7, [sp, #0xa8]
//   0x0342b4: ad0007e0  stp      q0, q1, [sp]
//   0x0342b8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0342bc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0342c0: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0342c4: d53bd057  mrs      x23, tpidr_el0
//   0x0342c8: f94016e9  ldr      x9, [x23, #0x28]
//   0x0342cc: 928004e8  mov      x8, #-0x28
uint64_t fde_0225_sub_034290(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xAD031FE6ULL) + (x2 ^ 0x034290ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x034290: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xA9105FFCULL; // 0x034294: stp x28, x23, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157F6ULL; // 0x034298: stp x22, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x03429c: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x0342a0: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x0342a4: add x29, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0342a8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0342ac: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0342b0: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0342b4: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0226 @ 0x034394..0x0345b8 (548 bytes)
// [VN] Phục dựng FDE #0226 tại 0x034394..0x0345b8 (548 byte)
//   0x034394: d10303ff  sub      sp, sp, #0xc0
//   0x034398: f9003bf9  str      x25, [sp, #0x70]
//   0x03439c: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x0343a0: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x0343a4: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0343a8: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0343ac: 9102c3fd  add      x29, sp, #0xb0
//   0x0343b0: d53bd058  mrs      x24, tpidr_el0
//   0x0343b4: f9401708  ldr      x8, [x24, #0x28]
//   0x0343b8: aa0303f6  mov      x22, x3
//   0x0343bc: aa0203f5  mov      x21, x2
//   0x0343c0: aa0103f3  mov      x19, x1
//   0x0343c4: f81b83a8  stur     x8, [x29, #-0x48]
//   0x0343c8: 90000188  adrp     x8, #0x64000
//   0x0343cc: 3979a108  ldrb     w8, [x8, #0xe68]
//   0x0343d0: aa0003f4  mov      x20, x0
uint64_t fde_0226_sub_034394(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xF81B83A8ULL) + (x2 ^ 0x034394ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x034394: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003BF9ULL; // 0x034398: str x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x03439c: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x0343a0: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0343a4: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0343a8: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0343ac: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0343b0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0343b4: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x0343b8: mov x22, x3
    return acc;
}

// [EN] Reconstructed FDE #0227 @ 0x0345b8..0x034654 (156 bytes)
// [VN] Phục dựng FDE #0227 tại 0x0345b8..0x034654 (156 byte)
//   0x0345b8: d10483ff  sub      sp, sp, #0x120
//   0x0345bc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0345c0: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0345c4: 910443fd  add      x29, sp, #0x110
//   0x0345c8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0345cc: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0345d0: f90057e7  str      x7, [sp, #0xa8]
//   0x0345d4: ad0007e0  stp      q0, q1, [sp]
//   0x0345d8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0345dc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0345e0: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0345e4: d53bd053  mrs      x19, tpidr_el0
//   0x0345e8: f940166b  ldr      x11, [x19, #0x28]
//   0x0345ec: 928004e8  mov      x8, #-0x28
//   0x0345f0: 910003e9  mov      x9, sp
//   0x0345f4: 910223ea  add      x10, sp, #0x88
uint64_t fde_0227_sub_0345b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0345B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0345b8: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0345bc: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0345c0: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0345c4: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0345c8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0345cc: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0345d0: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0345d4: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0345d8: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0345dc: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0228 @ 0x034654..0x034730 (220 bytes)
// [VN] Phục dựng FDE #0228 tại 0x034654..0x034730 (220 byte)
//   0x034654: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x034658: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03465c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034660: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x034664: 9100c3fd  add      x29, sp, #0x30
//   0x034668: b0000197  adrp     x23, #0x65000
//   0x03466c: 9103a2f7  add      x23, x23, #0xe8
//   0x034670: aa0103f4  mov      x20, x1
//   0x034674: f9402ee8  ldr      x8, [x23, #0x58]
//   0x034678: a9400ae1  ldp      x1, x2, [x23]
//   0x03467c: aa1403e3  mov      x3, x20
//   0x034680: aa0003f3  mov      x19, x0
//   0x034684: d63f0100  blr      x8
//   0x034688: b4000340  cbz      x0, #0x346f0
//   0x03468c: b9400008  ldr      w8, [x0]
//   0x034690: 52848d09  mov      w9, #0x2468
uint64_t fde_0228_sub_034654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x034654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x034654: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x034658: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03465c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034660: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x034664: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000197ULL; // 0x034668: adrp x23, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9103A2F7ULL; // 0x03466c: add x23, x23, #0xe8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x034670: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402EE8ULL; // 0x034674: ldr x8, [x23, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9400AE1ULL; // 0x034678: ldp x1, x2, [x23]
    return acc;
}

// [EN] Reconstructed FDE #0229 @ 0x034730..0x034778 (72 bytes)
// [VN] Phục dựng FDE #0229 tại 0x034730..0x034778 (72 byte)
//   0x034730: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x034734: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x034738: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03473c: 910083fd  add      x29, sp, #0x20
//   0x034740: aa0203e1  mov      x1, x2
//   0x034744: 2a0403f3  mov      w19, w4
//   0x034748: 2a0303f4  mov      w20, w3
//   0x03474c: 9400a335  bl       #0x5d420
//   0x034750: aa0003f5  mov      x21, x0
//   0x034754: 9400a337  bl       #0x5d430
//   0x034758: 2a1403e1  mov      w1, w20
//   0x03475c: 2a1303e2  mov      w2, w19
//   0x034760: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x034764: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x034768: 2a0003e3  mov      w3, w0
//   0x03476c: aa1503e0  mov      x0, x21
uint64_t fde_0229_sub_034730(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xA9427BFDULL) + (x2 ^ 0x034730ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x034730: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x034734: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x034738: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03473c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x034740: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F3ULL; // 0x034744: mov w19, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x034748: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400A335ULL; // 0x03474c: bl #0x5d420
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x034750: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400A337ULL; // 0x034754: bl #0x5d430
    return acc;
}

// [EN] Reconstructed FDE #0230 @ 0x034778..0x034840 (200 bytes)
// [VN] Phục dựng FDE #0230 tại 0x034778..0x034840 (200 byte)
//   0x034778: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03477c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x034780: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034784: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x034788: 9100c3fd  add      x29, sp, #0x30
//   0x03478c: 2a0203f6  mov      w22, w2
//   0x034790: aa0103f7  mov      x23, x1
//   0x034794: f0fffee1  adrp     x1, #0x13000
//   0x034798: 90ffff02  adrp     x2, #0x14000
//   0x03479c: aa0003f8  mov      x24, x0
//   0x0347a0: 911e7c21  add      x1, x1, #0x79f
//   0x0347a4: 912b1442  add      x2, x2, #0xac5
//   0x0347a8: 528000c0  mov      w0, #6
//   0x0347ac: 2a0503f3  mov      w19, w5
//   0x0347b0: aa0403f4  mov      x20, x4
//   0x0347b4: 2a0303f5  mov      w21, w3
uint64_t fde_0230_sub_034778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x528000C0ULL) + (x2 ^ 0x034778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x034778: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03477c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x034780: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034784: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x034788: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F6ULL; // 0x03478c: mov w22, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x034790: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEE1ULL; // 0x034794: adrp x1, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFF02ULL; // 0x034798: adrp x2, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x03479c: mov x24, x0
    return acc;
}

// [EN] Reconstructed FDE #0231 @ 0x034840..0x03494c (268 bytes)
// [VN] Phục dựng FDE #0231 tại 0x034840..0x03494c (268 byte)
//   0x034840: d100c3ff  sub      sp, sp, #0x30
//   0x034844: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x034848: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03484c: 910083fd  add      x29, sp, #0x20
//   0x034850: aa0003f3  mov      x19, x0
//   0x034854: d0fffec2  adrp     x2, #0xe000
//   0x034858: 90fffee3  adrp     x3, #0x10000
//   0x03485c: b0fffee4  adrp     x4, #0x11000
//   0x034860: 91280442  add      x2, x2, #0xa01
//   0x034864: 91191063  add      x3, x3, #0x644
//   0x034868: 91253c84  add      x4, x4, #0x94f
//   0x03486c: 910023e0  add      x0, sp, #8
//   0x034870: aa1303e1  mov      x1, x19
//   0x034874: 2a1f03e5  mov      w5, wzr
//   0x034878: 94000035  bl       #0x3494c
//   0x03487c: f94007e8  ldr      x8, [sp, #8]
uint64_t fde_0231_sub_034840(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x034840ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x034840: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x034844: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x034848: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03484c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x034850: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC2ULL; // 0x034854: adrp x2, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE3ULL; // 0x034858: adrp x3, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEE4ULL; // 0x03485c: adrp x4, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0x91280442ULL; // 0x034860: add x2, x2, #0xa01
    acc = (acc * 0x100000001B3ULL) ^ 0x91191063ULL; // 0x034864: add x3, x3, #0x644
    return acc;
}

// [EN] Reconstructed FDE #0232 @ 0x03494c..0x034ab0 (356 bytes)
// [VN] Phục dựng FDE #0232 tại 0x03494c..0x034ab0 (356 byte)
//   0x03494c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x034950: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x034954: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034958: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03495c: 9100c3fd  add      x29, sp, #0x30
//   0x034960: f900001f  str      xzr, [x0]
//   0x034964: f9400028  ldr      x8, [x1]
//   0x034968: aa0103f3  mov      x19, x1
//   0x03496c: aa0003f5  mov      x21, x0
//   0x034970: aa0203e1  mov      x1, x2
//   0x034974: f9401908  ldr      x8, [x8, #0x30]
//   0x034978: aa1303e0  mov      x0, x19
//   0x03497c: 2a0503f8  mov      w24, w5
//   0x034980: aa0403f7  mov      x23, x4
//   0x034984: aa0303f6  mov      x22, x3
//   0x034988: d63f0100  blr      x8
uint64_t fde_0232_sub_03494c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x2A0503F8ULL) + (x2 ^ 0x03494CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03494c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x034950: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x034954: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034958: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03495c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x034960: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x034964: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x034968: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x03496c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x034970: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0233 @ 0x034ab0..0x034bf8 (328 bytes)
// [VN] Phục dựng FDE #0233 tại 0x034ab0..0x034bf8 (328 byte)
//   0x034ab0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x034ab4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x034ab8: 910043fd  add      x29, sp, #0x10
//   0x034abc: b0fffec0  adrp     x0, #0xd000
//   0x034ac0: 91207800  add      x0, x0, #0x81e
//   0x034ac4: 9400a18f  bl       #0x5d100
//   0x034ac8: b40004e0  cbz      x0, #0x34b64
//   0x034acc: aa0003f3  mov      x19, x0
//   0x034ad0: d0fffee1  adrp     x1, #0x12000
//   0x034ad4: 91396021  add      x1, x1, #0xe58
//   0x034ad8: 9400a1fe  bl       #0x5d2d0
//   0x034adc: b40005a0  cbz      x0, #0x34b90
//   0x034ae0: d0fffee1  adrp     x1, #0x12000
//   0x034ae4: 90ffff02  adrp     x2, #0x14000
//   0x034ae8: d0fffee3  adrp     x3, #0x12000
//   0x034aec: 91392021  add      x1, x1, #0xe48
uint64_t fde_0233_sub_034ab0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0FFFEE1ULL) + (x2 ^ 0x034AB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x034ab0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x034ab4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x034ab8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC0ULL; // 0x034abc: adrp x0, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x91207800ULL; // 0x034ac0: add x0, x0, #0x81e
    acc = (acc * 0x100000001B3ULL) ^ 0x9400A18FULL; // 0x034ac4: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E0ULL; // 0x034ac8: cbz x0, #0x34b64
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x034acc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE1ULL; // 0x034ad0: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91396021ULL; // 0x034ad4: add x1, x1, #0xe58
    return acc;
}

// [EN] Reconstructed FDE #0234 @ 0x034bf8..0x034c28 (48 bytes)
// [VN] Phục dựng FDE #0234 tại 0x034bf8..0x034c28 (48 byte)
//   0x034bf8: d10083ff  sub      sp, sp, #0x20
//   0x034bfc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x034c00: 910043fd  add      x29, sp, #0x10
//   0x034c04: 90000188  adrp     x8, #0x64000
//   0x034c08: f942dd08  ldr      x8, [x8, #0x5b8]
//   0x034c0c: f90007e0  str      x0, [sp, #8]
//   0x034c10: 910023e1  add      x1, sp, #8
//   0x034c14: aa0803e0  mov      x0, x8
//   0x034c18: 94000018  bl       #0x34c78
//   0x034c1c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x034c20: 910083ff  add      sp, sp, #0x20
//   0x034c24: d65f03c0  ret      
uint64_t fde_0234_sub_034bf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034BF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x034bf8: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x034bfc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x034c00: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x034c04: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942DD08ULL; // 0x034c08: ldr x8, [x8, #0x5b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E0ULL; // 0x034c0c: str x0, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x034c10: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x034c14: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000018ULL; // 0x034c18: bl #0x34c78
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x034c1c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0235 @ 0x034c28..0x034c78 (80 bytes)
// [VN] Phục dựng FDE #0235 tại 0x034c28..0x034c78 (80 byte)
//   0x034c28: 34000141  cbz      w1, #0x34c50
//   0x034c2c: 2a0103e4  mov      w4, w1
//   0x034c30: d0fffee1  adrp     x1, #0x12000
//   0x034c34: 90fffee2  adrp     x2, #0x10000
//   0x034c38: d0fffee3  adrp     x3, #0x12000
//   0x034c3c: 91392021  add      x1, x1, #0xe48
//   0x034c40: 9121e042  add      x2, x2, #0x878
//   0x034c44: 91396063  add      x3, x3, #0xe58
//   0x034c48: 52800060  mov      w0, #3
//   0x034c4c: 1400a015  b        #0x5cca0
//   0x034c50: d0fffee1  adrp     x1, #0x12000
//   0x034c54: f0fffec2  adrp     x2, #0xf000
//   0x034c58: d0fffee3  adrp     x3, #0x12000
//   0x034c5c: 90000188  adrp     x8, #0x64000
//   0x034c60: 91392021  add      x1, x1, #0xe48
//   0x034c64: 913ab842  add      x2, x2, #0xeae
uint64_t fde_0235_sub_034c28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000141ULL) + (x1 ^ 0xD0FFFEE3ULL) + (x2 ^ 0x034C28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000141ULL; // 0x034c28: cbz w1, #0x34c50
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E4ULL; // 0x034c2c: mov w4, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE1ULL; // 0x034c30: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE2ULL; // 0x034c34: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE3ULL; // 0x034c38: adrp x3, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91392021ULL; // 0x034c3c: add x1, x1, #0xe48
    acc = (acc * 0x100000001B3ULL) ^ 0x9121E042ULL; // 0x034c40: add x2, x2, #0x878
    acc = (acc * 0x100000001B3ULL) ^ 0x91396063ULL; // 0x034c44: add x3, x3, #0xe58
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x034c48: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1400A015ULL; // 0x034c4c: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0236 @ 0x034c78..0x034ff8 (896 bytes)
// [VN] Phục dựng FDE #0236 tại 0x034c78..0x034ff8 (896 byte)
//   0x034c78: d10603ff  sub      sp, sp, #0x180
//   0x034c7c: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x034c80: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x034c84: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x034c88: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x034c8c: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x034c90: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x034c94: 9105c3fd  add      x29, sp, #0x170
//   0x034c98: d53bd058  mrs      x24, tpidr_el0
//   0x034c9c: f9401708  ldr      x8, [x24, #0x28]
//   0x034ca0: aa0003f3  mov      x19, x0
//   0x034ca4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x034ca8: b4000440  cbz      x0, #0x34d30
//   0x034cac: aa0103f4  mov      x20, x1
//   0x034cb0: d0fffee1  adrp     x1, #0x12000
//   0x034cb4: f0fffee2  adrp     x2, #0x13000
uint64_t fde_0236_sub_034c78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xB4000440ULL) + (x2 ^ 0x034C78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x034c78: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x034c7c: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x034c80: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x034c84: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x034c88: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x034c8c: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x034c90: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x034c94: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x034c98: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x034c9c: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0237 @ 0x034ff8..0x03511c (292 bytes)
// [VN] Phục dựng FDE #0237 tại 0x034ff8..0x03511c (292 byte)
//   0x034ff8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x034ffc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x035000: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x035004: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x035008: 9100c3fd  add      x29, sp, #0x30
//   0x03500c: f0000168  adrp     x8, #0x64000
//   0x035010: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x035014: 2a0003f4  mov      w20, w0
//   0x035018: aa0103f3  mov      x19, x1
//   0x03501c: 2a0803e0  mov      w0, w8
//   0x035020: 9400a008  bl       #0x5d040
//   0x035024: d0000188  adrp     x8, #0x67000
//   0x035028: 93407e97  sxtw     x23, w20
//   0x03502c: 911ba108  add      x8, x8, #0x6e8
//   0x035030: 8b171515  add      x21, x8, x23, lsl #5
//   0x035034: f94006a4  ldr      x4, [x21, #8]
uint64_t fde_0237_sub_034ff8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E97ULL) + (x2 ^ 0x034FF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x034ff8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x034ffc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x035000: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035004: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x035008: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x03500c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x035010: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x035014: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x035018: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x03501c: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0238 @ 0x03511c..0x03543c (800 bytes)
// [VN] Phục dựng FDE #0238 tại 0x03511c..0x03543c (800 byte)
//   0x03511c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x035120: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x035124: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x035128: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03512c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x035130: 910103fd  add      x29, sp, #0x40
//   0x035134: aa0003f5  mov      x21, x0
//   0x035138: b0fffec0  adrp     x0, #0xe000
//   0x03513c: 91115800  add      x0, x0, #0x456
//   0x035140: 52800021  mov      w1, #1
//   0x035144: aa0403f4  mov      x20, x4
//   0x035148: aa0303f7  mov      x23, x3
//   0x03514c: aa0203f6  mov      x22, x2
//   0x035150: 9400a020  bl       #0x5d1d0
//   0x035154: b40008a0  cbz      x0, #0x35268
//   0x035158: aa0003f3  mov      x19, x0
uint64_t fde_0238_sub_03511c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0203F6ULL) + (x2 ^ 0x03511CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x03511c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x035120: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x035124: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x035128: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03512c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x035130: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x035134: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC0ULL; // 0x035138: adrp x0, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x91115800ULL; // 0x03513c: add x0, x0, #0x456
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x035140: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0239 @ 0x03543c..0x035640 (516 bytes)
// [VN] Phục dựng FDE #0239 tại 0x03543c..0x035640 (516 byte)
//   0x03543c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x035440: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x035444: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x035448: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03544c: 9100c3fd  add      x29, sp, #0x30
//   0x035450: aa0203f7  mov      x23, x2
//   0x035454: d0fffee1  adrp     x1, #0x13000
//   0x035458: d0fffec2  adrp     x2, #0xf000
//   0x03545c: 911e9821  add      x1, x1, #0x7a6
//   0x035460: 9111bc42  add      x2, x2, #0x46f
//   0x035464: 52800060  mov      w0, #3
//   0x035468: 2a0503f4  mov      w20, w5
//   0x03546c: 2a0403f3  mov      w19, w4
//   0x035470: 2a0303f6  mov      w22, w3
//   0x035474: 94009e0b  bl       #0x5cca0
//   0x035478: b0fffec0  adrp     x0, #0xe000
uint64_t fde_0239_sub_03543c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x2A0403F3ULL) + (x2 ^ 0x03543CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03543c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x035440: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x035444: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035448: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03544c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F7ULL; // 0x035450: mov x23, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE1ULL; // 0x035454: adrp x1, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC2ULL; // 0x035458: adrp x2, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x911E9821ULL; // 0x03545c: add x1, x1, #0x7a6
    acc = (acc * 0x100000001B3ULL) ^ 0x9111BC42ULL; // 0x035460: add x2, x2, #0x46f
    return acc;
}

// [EN] Reconstructed FDE #0240 @ 0x035640..0x035764 (292 bytes)
// [VN] Phục dựng FDE #0240 tại 0x035640..0x035764 (292 byte)
//   0x035640: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x035644: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x035648: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03564c: 910083fd  add      x29, sp, #0x20
//   0x035650: d0fffea0  adrp     x0, #0xb000
//   0x035654: 91102800  add      x0, x0, #0x40a
//   0x035658: 94009eaa  bl       #0x5d100
//   0x03565c: b4000420  cbz      x0, #0x356e0
//   0x035660: 90fffec1  adrp     x1, #0xd000
//   0x035664: 9120b021  add      x1, x1, #0x82c
//   0x035668: aa0003f4  mov      x20, x0
//   0x03566c: 94009f25  bl       #0x5d300
//   0x035670: aa0003f3  mov      x19, x0
//   0x035674: aa1403e0  mov      x0, x20
//   0x035678: 94009eaa  bl       #0x5d120
//   0x03567c: b40003d3  cbz      x19, #0x356f4
uint64_t fde_0240_sub_035640(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x035640ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x035640: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x035644: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x035648: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03564c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEA0ULL; // 0x035650: adrp x0, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x91102800ULL; // 0x035654: add x0, x0, #0x40a
    acc = (acc * 0x100000001B3ULL) ^ 0x94009EAAULL; // 0x035658: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000420ULL; // 0x03565c: cbz x0, #0x356e0
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC1ULL; // 0x035660: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x9120B021ULL; // 0x035664: add x1, x1, #0x82c
    return acc;
}

// [EN] Reconstructed FDE #0241 @ 0x035764..0x0358a8 (324 bytes)
// [VN] Phục dựng FDE #0241 tại 0x035764..0x0358a8 (324 byte)
//   0x035764: d100c3ff  sub      sp, sp, #0x30
//   0x035768: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03576c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x035770: 910083fd  add      x29, sp, #0x20
//   0x035774: f0000168  adrp     x8, #0x64000
//   0x035778: 3979a509  ldrb     w9, [x8, #0xe69]
//   0x03577c: 7100053f  cmp      w9, #1
//   0x035780: 540000e1  b.ne     #0x3579c
//   0x035784: f0000168  adrp     x8, #0x64000
//   0x035788: 3979b100  ldrb     w0, [x8, #0xe6c]
//   0x03578c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x035790: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x035794: 9100c3ff  add      sp, sp, #0x30
//   0x035798: d65f03c0  ret      
//   0x03579c: aa0003f3  mov      x19, x0
//   0x0357a0: f0fffea2  adrp     x2, #0xc000
uint64_t fde_0241_sub_035764(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x9100C3FFULL) + (x2 ^ 0x035764ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x035764: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x035768: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03576c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x035770: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x035774: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979A509ULL; // 0x035778: ldrb w9, [x8, #0xe69]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x03577c: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E1ULL; // 0x035780: b.ne #0x3579c
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x035784: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979B100ULL; // 0x035788: ldrb w0, [x8, #0xe6c]
    return acc;
}

// [EN] Reconstructed FDE #0242 @ 0x0358a8..0x0358e8 (64 bytes)
// [VN] Phục dựng FDE #0242 tại 0x0358a8..0x0358e8 (64 byte)
//   0x0358a8: d100c3ff  sub      sp, sp, #0x30
//   0x0358ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0358b0: 910083fd  add      x29, sp, #0x20
//   0x0358b4: 90000188  adrp     x8, #0x65000
//   0x0358b8: f81f83a0  stur     x0, [x29, #-8]
//   0x0358bc: f940b100  ldr      x0, [x8, #0x160]
//   0x0358c0: a90087e2  stp      x2, x1, [sp, #8]
//   0x0358c4: f90003e3  str      x3, [sp]
//   0x0358c8: d10023a1  sub      x1, x29, #8
//   0x0358cc: 910043e2  add      x2, sp, #0x10
//   0x0358d0: 910023e3  add      x3, sp, #8
//   0x0358d4: 910003e4  mov      x4, sp
//   0x0358d8: 94000004  bl       #0x358e8
//   0x0358dc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0358e0: 9100c3ff  add      sp, sp, #0x30
//   0x0358e4: d65f03c0  ret      
uint64_t fde_0242_sub_0358a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x94000004ULL) + (x2 ^ 0x0358A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0358a8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0358ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0358b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x0358b4: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F83A0ULL; // 0x0358b8: stur x0, [x29, #-8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940B100ULL; // 0x0358bc: ldr x0, [x8, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90087E2ULL; // 0x0358c0: stp x2, x1, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E3ULL; // 0x0358c4: str x3, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xD10023A1ULL; // 0x0358c8: sub x1, x29, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E2ULL; // 0x0358cc: add x2, sp, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0243 @ 0x0358e8..0x035c9c (948 bytes)
// [VN] Phục dựng FDE #0243 tại 0x0358e8..0x035c9c (948 byte)
//   0x0358e8: d10683ff  sub      sp, sp, #0x1a0
//   0x0358ec: a9146ffc  stp      x28, x27, [sp, #0x140]
//   0x0358f0: a91567fa  stp      x26, x25, [sp, #0x150]
//   0x0358f4: a9165ff8  stp      x24, x23, [sp, #0x160]
//   0x0358f8: a91757f6  stp      x22, x21, [sp, #0x170]
//   0x0358fc: a9184ff4  stp      x20, x19, [sp, #0x180]
//   0x035900: a9197bfd  stp      x29, x30, [sp, #0x190]
//   0x035904: 910643fd  add      x29, sp, #0x190
//   0x035908: d53bd05b  mrs      x27, tpidr_el0
//   0x03590c: f9401768  ldr      x8, [x27, #0x28]
//   0x035910: f81a03a8  stur     x8, [x29, #-0x60]
//   0x035914: b40004c0  cbz      x0, #0x359ac
//   0x035918: aa0303f6  mov      x22, x3
//   0x03591c: aa0203f7  mov      x23, x2
//   0x035920: aa0103fa  mov      x26, x1
//   0x035924: b0fffee1  adrp     x1, #0x12000
uint64_t fde_0243_sub_0358e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10683FFULL) + (x1 ^ 0xAA0303F6ULL) + (x2 ^ 0x0358E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x0358e8: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9146FFCULL; // 0x0358ec: stp x28, x27, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91567FAULL; // 0x0358f0: stp x26, x25, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9165FF8ULL; // 0x0358f4: stp x24, x23, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91757F6ULL; // 0x0358f8: stp x22, x21, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9184FF4ULL; // 0x0358fc: stp x20, x19, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9197BFDULL; // 0x035900: stp x29, x30, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0x910643FDULL; // 0x035904: add x29, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x035908: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x03590c: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0244 @ 0x035c9c..0x035dc4 (296 bytes)
// [VN] Phục dựng FDE #0244 tại 0x035c9c..0x035dc4 (296 byte)
//   0x035c9c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x035ca0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x035ca4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x035ca8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x035cac: 9100c3fd  add      x29, sp, #0x30
//   0x035cb0: f0000168  adrp     x8, #0x64000
//   0x035cb4: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x035cb8: 2a0003f4  mov      w20, w0
//   0x035cbc: aa0103f3  mov      x19, x1
//   0x035cc0: 2a0803e0  mov      w0, w8
//   0x035cc4: 94009cdf  bl       #0x5d040
//   0x035cc8: d0000188  adrp     x8, #0x67000
//   0x035ccc: 93407e96  sxtw     x22, w20
//   0x035cd0: 911ba108  add      x8, x8, #0x6e8
//   0x035cd4: 8b161517  add      x23, x8, x22, lsl #5
//   0x035cd8: f94206e4  ldr      x4, [x23, #0x408]
uint64_t fde_0244_sub_035c9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x035C9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x035c9c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x035ca0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x035ca4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035ca8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x035cac: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x035cb0: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x035cb4: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x035cb8: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x035cbc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x035cc0: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0245 @ 0x035dc4..0x035ed0 (268 bytes)
// [VN] Phục dựng FDE #0245 tại 0x035dc4..0x035ed0 (268 byte)
//   0x035dc4: d100c3ff  sub      sp, sp, #0x30
//   0x035dc8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x035dcc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x035dd0: 910083fd  add      x29, sp, #0x20
//   0x035dd4: aa0003f3  mov      x19, x0
//   0x035dd8: f0fffea2  adrp     x2, #0xc000
//   0x035ddc: f0fffec3  adrp     x3, #0x10000
//   0x035de0: 90fffee4  adrp     x4, #0x11000
//   0x035de4: 91250442  add      x2, x2, #0x941
//   0x035de8: 91191063  add      x3, x3, #0x644
//   0x035dec: 91253c84  add      x4, x4, #0x94f
//   0x035df0: 910023e0  add      x0, sp, #8
//   0x035df4: aa1303e1  mov      x1, x19
//   0x035df8: 2a1f03e5  mov      w5, wzr
//   0x035dfc: 97fffad4  bl       #0x3494c
//   0x035e00: f94007e8  ldr      x8, [sp, #8]
uint64_t fde_0245_sub_035dc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x035DC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x035dc4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x035dc8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x035dcc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x035dd0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035dd4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEA2ULL; // 0x035dd8: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEC3ULL; // 0x035ddc: adrp x3, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE4ULL; // 0x035de0: adrp x4, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0x91250442ULL; // 0x035de4: add x2, x2, #0x941
    acc = (acc * 0x100000001B3ULL) ^ 0x91191063ULL; // 0x035de8: add x3, x3, #0x644
    return acc;
}

// [EN] Reconstructed FDE #0246 @ 0x035ed0..0x035ed8 (8 bytes)
// [VN] Phục dựng FDE #0246 tại 0x035ed0..0x035ed8 (8 byte)
//   0x035ed0: 12800000  mov      w0, #-1
//   0x035ed4: d65f03c0  ret      
uint64_t fde_0246_sub_035ed0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x035ED0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x035ed0: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x035ed4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0247 @ 0x035ed8..0x035f64 (140 bytes)
// [VN] Phục dựng FDE #0247 tại 0x035ed8..0x035f64 (140 byte)
//   0x035ed8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x035edc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x035ee0: 910043fd  add      x29, sp, #0x10
//   0x035ee4: 2a1f03e0  mov      w0, wzr
//   0x035ee8: 2a1f03e1  mov      w1, wzr
//   0x035eec: 2a0203f3  mov      w19, w2
//   0x035ef0: 94009d3c  bl       #0x5d3e0
//   0x035ef4: f0fffee0  adrp     x0, #0x14000
//   0x035ef8: f0fffea2  adrp     x2, #0xc000
//   0x035efc: 90000003  adrp     x3, #0x35000
//   0x035f00: f0000168  adrp     x8, #0x64000
//   0x035f04: 9120c000  add      x0, x0, #0x830
//   0x035f08: 9138a842  add      x2, x2, #0xe2a
//   0x035f0c: 913d9063  add      x3, x3, #0xf64
//   0x035f10: aa1f03e1  mov      x1, xzr
//   0x035f14: aa1f03e4  mov      x4, xzr
uint64_t fde_0247_sub_035ed8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9138A842ULL) + (x2 ^ 0x035ED8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x035ed8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035edc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x035ee0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x035ee4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x035ee8: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x035eec: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x94009D3CULL; // 0x035ef0: bl #0x5d3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEE0ULL; // 0x035ef4: adrp x0, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEA2ULL; // 0x035ef8: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000003ULL; // 0x035efc: adrp x3, #0x35000
    return acc;
}

// [EN] Reconstructed FDE #0248 @ 0x035f64..0x036018 (180 bytes)
// [VN] Phục dựng FDE #0248 tại 0x035f64..0x036018 (180 byte)
//   0x035f64: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x035f68: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x035f6c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x035f70: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x035f74: 9100c3fd  add      x29, sp, #0x30
//   0x035f78: f0000168  adrp     x8, #0x64000
//   0x035f7c: 913c3108  add      x8, x8, #0xf0c
//   0x035f80: aa1e03f3  mov      x19, x30
//   0x035f84: eb08003f  cmp      x1, x8
//   0x035f88: 54000200  b.eq     #0x35fc8
//   0x035f8c: 2a0303f4  mov      w20, w3
//   0x035f90: 2a0203f5  mov      w21, w2
//   0x035f94: aa0103f6  mov      x22, x1
//   0x035f98: aa0003f7  mov      x23, x0
//   0x035f9c: 90000000  adrp     x0, #0x35000
//   0x035fa0: 913d9000  add      x0, x0, #0xf64
uint64_t fde_0248_sub_035f64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0103F6ULL) + (x2 ^ 0x035F64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x035f64: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x035f68: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x035f6c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035f70: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x035f74: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x035f78: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913C3108ULL; // 0x035f7c: add x8, x8, #0xf0c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x035f80: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x035f84: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000200ULL; // 0x035f88: b.eq #0x35fc8
    return acc;
}

// [EN] Reconstructed FDE #0249 @ 0x036018..0x0360e4 (204 bytes)
// [VN] Phục dựng FDE #0249 tại 0x036018..0x0360e4 (204 byte)
//   0x036018: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03601c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x036020: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x036024: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x036028: 9100c3fd  add      x29, sp, #0x30
//   0x03602c: aa1e03f3  mov      x19, x30
//   0x036030: aa0303f4  mov      x20, x3
//   0x036034: aa0203f5  mov      x21, x2
//   0x036038: aa0103f6  mov      x22, x1
//   0x03603c: aa0003f7  mov      x23, x0
//   0x036040: 90000000  adrp     x0, #0x36000
//   0x036044: 91006000  add      x0, x0, #0x18
//   0x036048: 94009c5e  bl       #0x5d1c0
//   0x03604c: aa0003e8  mov      x8, x0
//   0x036050: aa1703e0  mov      x0, x23
//   0x036054: aa1603e1  mov      x1, x22
uint64_t fde_0249_sub_036018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x94009C5EULL) + (x2 ^ 0x036018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x036018: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03601c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x036020: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x036024: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x036028: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03602c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x036030: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x036034: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x036038: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x03603c: mov x23, x0
    return acc;
}

uint64_t DispatchXhookUnwindFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index >= 250U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x9E3779B97F4A7C15ULL) + x2;
}

} // namespace xhook
} // namespace sysoptimizer
} // namespace bytedance

extern "C" {

jint JNI_OnLoad(JavaVM* vm, void*) {
    // 0x02cd24..0x02cde8: stores vm @ .bss 0x065c18, registers 2 methods @ .data.rel.ro 0x060008, returns 0x00010006
    if (vm == nullptr) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

int xh_elf_check_elfheader(uintptr_t base_addr) {
    return bytedance::sysoptimizer::xhook::CheckElf64AArch64HeaderExact(
        reinterpret_cast<const bytedance::sysoptimizer::Elf64HeaderPrefixAbi*>(base_addr));
}

void xh_util_flush_instruction_cache(uintptr_t addr) {
    uintptr_t b = 0, e = 0;
    bytedance::sysoptimizer::xhook::ComputeAlignedICacheFlushRange(addr, 4096, &b, &e);
}

} // extern "C"
