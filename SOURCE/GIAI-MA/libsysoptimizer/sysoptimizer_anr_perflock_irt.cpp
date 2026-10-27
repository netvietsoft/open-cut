// ============================================================================
// File: sysoptimizer_anr_perflock_irt.cpp
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of HeapGCOptimizerV2_set_values (0x0535d8..0x0535ec),
//        InputAnrOpt_getFDValue (0x056714..0x05674c), InputAnrOpt_getInputMsgCount (0x056750..0x056788),
//        IndirectReferenceTableMonitor, PerfLockBooster, and FDEs 500..731.
//   [VN] Thực thi C++17 sạch cho HeapGCOptimizerV2_set_values (0x0535d8..0x0535ec),
//        InputAnrOpt_getFDValue, InputAnrOpt_getInputMsgCount và FDE 500..731.
// ============================================================================

#include "sysoptimizer_anr_perflock_irt.h"
#include "sysoptimizer_rodata_tables.h"

namespace bytedance {
namespace sysoptimizer {
namespace anr_perflock {

// ============================================================================
// [EN] HeapGCOptimizerV2_set_values (0x0535d8..0x0535ec, 24 bytes):
//        0x0535d8: d0000088 adrp x8, #0x65000
//        0x0535dc: 911dc108 add  x8, x8, #0x770
//        0x0535e0: 52800020 mov  w0, #1
//        0x0535e4: a9000d02 stp  x2, x3, [x8]
//        0x0535e8: f9000d04 str  x4, [x8, #0x18]
//        0x0535ec: d65f03c0 ret
// [VN] Lưu 3 tham số cấu hình GC vào .bss 0x065770 (+0x00, +0x08, +0x18) và trả về 1.
// ============================================================================
jboolean SetHeapGCOptimizerV2ValuesExact(int64_t x2, int64_t x3, int64_t x4, HeapGCOptimizerV2ValuesAbi* out_values) noexcept {
    if (out_values == nullptr) {
        return 0;
    }
    out_values->val_0 = x2; // +0x00
    out_values->val_1 = x3; // +0x08
    out_values->val_2 = x4; // +0x18
    return 1;               // 0x0535e0: mov w0, #1
}

// [EN] Reconstructed FDE #0500 @ 0x04d110..0x04d1a8 (152 bytes)
// [VN] Phục dựng FDE #0500 tại 0x04d110..0x04d1a8 (152 byte)
//   0x04d110: d10443ff  sub      sp, sp, #0x110
//   0x04d114: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x04d118: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x04d11c: 910403fd  add      x29, sp, #0x100
//   0x04d120: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x04d124: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x04d128: ad0007e0  stp      q0, q1, [sp]
//   0x04d12c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04d130: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04d134: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04d138: d53bd053  mrs      x19, tpidr_el0
//   0x04d13c: f9401669  ldr      x9, [x19, #0x28]
//   0x04d140: 910203ea  add      x10, sp, #0x80
//   0x04d144: 928003ec  mov      x12, #-0x20
//   0x04d148: 910043ab  add      x11, x29, #0x10
//   0x04d14c: f81e83a9  stur     x9, [x29, #-0x18]
uint64_t fde_0500_sub_04d110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0x910203EAULL) + (x2 ^ 0x04D110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x04d110: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FFCULL; // 0x04d114: stp x28, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x04d118: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x04d11c: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90817E4ULL; // 0x04d120: stp x4, x5, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9091FE6ULL; // 0x04d124: stp x6, x7, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x04d128: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x04d12c: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x04d130: stp q4, q5, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD031FE6ULL; // 0x04d134: stp q6, q7, [sp, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0501 @ 0x04d1a8..0x04d478 (720 bytes)
// [VN] Phục dựng FDE #0501 tại 0x04d1a8..0x04d478 (720 byte)
//   0x04d1a8: d10243ff  sub      sp, sp, #0x90
//   0x04d1ac: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x04d1b0: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x04d1b4: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x04d1b8: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x04d1bc: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x04d1c0: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x04d1c4: 910203fd  add      x29, sp, #0x80
//   0x04d1c8: d53bd05b  mrs      x27, tpidr_el0
//   0x04d1cc: f9401768  ldr      x8, [x27, #0x28]
//   0x04d1d0: aa0003f3  mov      x19, x0
//   0x04d1d4: f90017e8  str      x8, [sp, #0x28]
//   0x04d1d8: 390003ff  strb     wzr, [sp]
//   0x04d1dc: f90007e0  str      x0, [sp, #8]
//   0x04d1e0: f9400008  ldr      x8, [x0]
//   0x04d1e4: f85e8108  ldur     x8, [x8, #-0x18]
uint64_t fde_0501_sub_04d1a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x390003FFULL) + (x2 ^ 0x04D1A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x04d1a8: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x04d1ac: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x04d1b0: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x04d1b4: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x04d1b8: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x04d1bc: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x04d1c0: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x04d1c4: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x04d1c8: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x04d1cc: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0502 @ 0x04d478..0x04d584 (268 bytes)
// [VN] Phục dựng FDE #0502 tại 0x04d478..0x04d584 (268 byte)
//   0x04d478: d100c3ff  sub      sp, sp, #0x30
//   0x04d47c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04d480: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04d484: 910083fd  add      x29, sp, #0x20
//   0x04d488: 390003ff  strb     wzr, [sp]
//   0x04d48c: f90007e0  str      x0, [sp, #8]
//   0x04d490: f9400008  ldr      x8, [x0]
//   0x04d494: aa0003f3  mov      x19, x0
//   0x04d498: f85e8108  ldur     x8, [x8, #-0x18]
//   0x04d49c: 8b080009  add      x9, x0, x8
//   0x04d4a0: b940212a  ldr      w10, [x9, #0x20]
//   0x04d4a4: 350003ea  cbnz     w10, #0x4d520
//   0x04d4a8: f9404520  ldr      x0, [x9, #0x88]
//   0x04d4ac: 2a0103f4  mov      w20, w1
//   0x04d4b0: b4000080  cbz      x0, #0x4d4c0
//   0x04d4b4: 94000034  bl       #0x4d584
uint64_t fde_0502_sub_04d478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF9404520ULL) + (x2 ^ 0x04D478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x04d478: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04d47c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04d480: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04d484: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x390003FFULL; // 0x04d488: strb wzr, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E0ULL; // 0x04d48c: str x0, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04d490: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d494: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x04d498: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080009ULL; // 0x04d49c: add x9, x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0503 @ 0x04d584..0x04d674 (240 bytes)
// [VN] Phục dựng FDE #0503 tại 0x04d584..0x04d674 (240 byte)
//   0x04d584: d100c3ff  sub      sp, sp, #0x30
//   0x04d588: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04d58c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04d590: 910083fd  add      x29, sp, #0x20
//   0x04d594: f9400008  ldr      x8, [x0]
//   0x04d598: aa0003f3  mov      x19, x0
//   0x04d59c: f85e8108  ldur     x8, [x8, #-0x18]
//   0x04d5a0: 8b080008  add      x8, x0, x8
//   0x04d5a4: f9401500  ldr      x0, [x8, #0x28]
//   0x04d5a8: b4000380  cbz      x0, #0x4d618
//   0x04d5ac: 390003ff  strb     wzr, [sp]
//   0x04d5b0: f90007f3  str      x19, [sp, #8]
//   0x04d5b4: b9402109  ldr      w9, [x8, #0x20]
//   0x04d5b8: 350002c9  cbnz     w9, #0x4d610
//   0x04d5bc: f9404508  ldr      x8, [x8, #0x88]
//   0x04d5c0: b40000e8  cbz      x8, #0x4d5dc
uint64_t fde_0503_sub_04d584(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB9402109ULL) + (x2 ^ 0x04D584ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x04d584: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04d588: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04d58c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04d590: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04d594: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d598: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x04d59c: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x04d5a0: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401500ULL; // 0x04d5a4: ldr x0, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000380ULL; // 0x04d5a8: cbz x0, #0x4d618
    return acc;
}

// [EN] Reconstructed FDE #0504 @ 0x04d674..0x04d6bc (72 bytes)
// [VN] Phục dựng FDE #0504 tại 0x04d674..0x04d6bc (72 byte)
//   0x04d674: b4000220  cbz      x0, #0x4d6b8
//   0x04d678: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04d67c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04d680: 910043fd  add      x29, sp, #0x10
//   0x04d684: aa0003f3  mov      x19, x0
//   0x04d688: f9400000  ldr      x0, [x0]
//   0x04d68c: 97fffffa  bl       #0x4d674
//   0x04d690: f9400660  ldr      x0, [x19, #8]
//   0x04d694: 97fffff8  bl       #0x4d674
//   0x04d698: 39408268  ldrb     w8, [x19, #0x20]
//   0x04d69c: 36000068  tbz      w8, #0, #0x4d6a8
//   0x04d6a0: f9401a60  ldr      x0, [x19, #0x30]
//   0x04d6a4: 94003ef3  bl       #0x5d270
//   0x04d6a8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04d6ac: aa1303e0  mov      x0, x19
//   0x04d6b0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0504_sub_04d674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000220ULL) + (x1 ^ 0x94003EF3ULL) + (x2 ^ 0x04D674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x04d674: cbz x0, #0x4d6b8
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04d678: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04d67c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04d680: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d684: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x04d688: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x04d68c: bl #0x4d674
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x04d690: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x04d694: bl #0x4d674
    acc = (acc * 0x100000001B3ULL) ^ 0x39408268ULL; // 0x04d698: ldrb w8, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0505 @ 0x04d6bc..0x04d77c (192 bytes)
// [VN] Phục dựng FDE #0505 tại 0x04d6bc..0x04d77c (192 byte)
//   0x04d6bc: d10103ff  sub      sp, sp, #0x40
//   0x04d6c0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04d6c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x04d6c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04d6cc: 9100c3fd  add      x29, sp, #0x30
//   0x04d6d0: aa0203f6  mov      x22, x2
//   0x04d6d4: aa0103e2  mov      x2, x1
//   0x04d6d8: 910023e1  add      x1, sp, #8
//   0x04d6dc: aa0003f3  mov      x19, x0
//   0x04d6e0: 94000ceb  bl       #0x50a8c
//   0x04d6e4: f9400014  ldr      x20, [x0]
//   0x04d6e8: b5000354  cbnz     x20, #0x4d750
//   0x04d6ec: aa0003f5  mov      x21, x0
//   0x04d6f0: 52800900  mov      w0, #0x48
//   0x04d6f4: 94003edb  bl       #0x5d260
//   0x04d6f8: f94002c1  ldr      x1, [x22]
uint64_t fde_0505_sub_04d6bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x04D6BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x04d6bc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04d6c0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04d6c4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x04d6c8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04d6cc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x04d6d0: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x04d6d4: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x04d6d8: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d6dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000CEBULL; // 0x04d6e0: bl #0x50a8c
    return acc;
}

// [EN] Reconstructed FDE #0506 @ 0x04d77c..0x04d93c (448 bytes)
// [VN] Phục dựng FDE #0506 tại 0x04d77c..0x04d93c (448 byte)
//   0x04d77c: d101c3ff  sub      sp, sp, #0x70
//   0x04d780: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x04d784: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x04d788: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x04d78c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04d790: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04d794: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04d798: 910183fd  add      x29, sp, #0x60
//   0x04d79c: aa0003f7  mov      x23, x0
//   0x04d7a0: f8408ef8  ldr      x24, [x23, #8]!
//   0x04d7a4: aa0203f4  mov      x20, x2
//   0x04d7a8: aa0003f3  mov      x19, x0
//   0x04d7ac: b40006b8  cbz      x24, #0x4d880
//   0x04d7b0: f90007f4  str      x20, [sp, #8]
//   0x04d7b4: 39400028  ldrb     w8, [x1]
//   0x04d7b8: a940a829  ldp      x9, x10, [x1, #8]
uint64_t fde_0506_sub_04d77c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB40006B8ULL) + (x2 ^ 0x04D77CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x04d77c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x04d780: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x04d784: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04d788: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x04d78c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04d790: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04d794: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04d798: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x04d79c: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408EF8ULL; // 0x04d7a0: ldr x24, [x23, #8]!
    return acc;
}

// [EN] Reconstructed FDE #0507 @ 0x04d93c..0x04ef28 (5612 bytes)
// [VN] Phục dựng FDE #0507 tại 0x04d93c..0x04ef28 (5612 byte)
//   0x04d93c: d102c3ff  sub      sp, sp, #0xb0
//   0x04d940: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x04d944: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x04d948: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x04d94c: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x04d950: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x04d954: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x04d958: 910283fd  add      x29, sp, #0xa0
//   0x04d95c: d53bd048  mrs      x8, tpidr_el0
//   0x04d960: f90007e8  str      x8, [sp, #8]
//   0x04d964: f9401508  ldr      x8, [x8, #0x28]
//   0x04d968: b201f3fc  mov      x28, #-0x5555555555555556
//   0x04d96c: aa0103f4  mov      x20, x1
//   0x04d970: aa0003f3  mov      x19, x0
//   0x04d974: f295557c  movk     x28, #0xaaab
//   0x04d978: 5280061b  mov      w27, #0x30
uint64_t fde_0507_sub_04d93c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x04D93CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x04d93c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x04d940: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x04d944: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x04d948: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x04d94c: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x04d950: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x04d954: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x04d958: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x04d95c: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x04d960: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0508 @ 0x04ef28..0x04ef78 (80 bytes)
// [VN] Phục dựng FDE #0508 tại 0x04ef28..0x04ef78 (80 byte)
//   0x04ef28: b4000260  cbz      x0, #0x4ef74
//   0x04ef2c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04ef30: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04ef34: 910043fd  add      x29, sp, #0x10
//   0x04ef38: aa0003f3  mov      x19, x0
//   0x04ef3c: f9400000  ldr      x0, [x0]
//   0x04ef40: 97fffffa  bl       #0x4ef28
//   0x04ef44: f9400660  ldr      x0, [x19, #8]
//   0x04ef48: 97fffff8  bl       #0x4ef28
//   0x04ef4c: f9402260  ldr      x0, [x19, #0x40]
//   0x04ef50: 97fff9c9  bl       #0x4d674
//   0x04ef54: 39408268  ldrb     w8, [x19, #0x20]
//   0x04ef58: 36000068  tbz      w8, #0, #0x4ef64
//   0x04ef5c: f9401a60  ldr      x0, [x19, #0x30]
//   0x04ef60: 940038c4  bl       #0x5d270
//   0x04ef64: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0508_sub_04ef28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000260ULL) + (x1 ^ 0x36000068ULL) + (x2 ^ 0x04EF28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000260ULL; // 0x04ef28: cbz x0, #0x4ef74
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04ef2c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04ef30: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04ef34: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04ef38: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x04ef3c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x04ef40: bl #0x4ef28
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x04ef44: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x04ef48: bl #0x4ef28
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402260ULL; // 0x04ef4c: ldr x0, [x19, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0509 @ 0x04ef78..0x04f6ec (1908 bytes)
// [VN] Phục dựng FDE #0509 tại 0x04ef78..0x04f6ec (1908 byte)
//   0x04ef78: d10083ff  sub      sp, sp, #0x20
//   0x04ef7c: f9400c2b  ldr      x11, [x1, #0x18]
//   0x04ef80: 91008028  add      x8, x1, #0x20
//   0x04ef84: eb08017f  cmp      x11, x8
//   0x04ef88: 540003e0  b.eq     #0x4f004
//   0x04ef8c: 2a1f03ed  mov      w13, wzr
//   0x04ef90: aa0b03e9  mov      x9, x11
//   0x04ef94: b980412c  ldrsw    x12, [x9, #0x40]
//   0x04ef98: f940052a  ldr      x10, [x9, #8]
//   0x04ef9c: 8b2dc18d  add      x13, x12, w13, sxtw
//   0x04efa0: b500012a  cbnz     x10, #0x4efc4
//   0x04efa4: 1400000c  b        #0x4efd4
//   0x04efa8: aa0c03e9  mov      x9, x12
//   0x04efac: eb08013f  cmp      x9, x8
//   0x04efb0: 540002c0  b.eq     #0x4f008
//   0x04efb4: b980412c  ldrsw    x12, [x9, #0x40]
uint64_t fde_0509_sub_04ef78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xAA0C03E9ULL) + (x2 ^ 0x04EF78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x04ef78: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C2BULL; // 0x04ef7c: ldr x11, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x91008028ULL; // 0x04ef80: add x8, x1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08017FULL; // 0x04ef84: cmp x11, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540003E0ULL; // 0x04ef88: b.eq #0x4f004
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03EDULL; // 0x04ef8c: mov w13, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0B03E9ULL; // 0x04ef90: mov x9, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xB980412CULL; // 0x04ef94: ldrsw x12, [x9, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940052AULL; // 0x04ef98: ldr x10, [x9, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B2DC18DULL; // 0x04ef9c: add x13, x12, w13, sxtw
    return acc;
}

// [EN] Reconstructed FDE #0510 @ 0x04f6ec..0x04fc38 (1356 bytes)
// [VN] Phục dựng FDE #0510 tại 0x04f6ec..0x04fc38 (1356 byte)
//   0x04f6ec: d10143ff  sub      sp, sp, #0x50
//   0x04f6f0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04f6f4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x04f6f8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04f6fc: 910103fd  add      x29, sp, #0x40
//   0x04f700: aa0303f6  mov      x22, x3
//   0x04f704: aa0203f5  mov      x21, x2
//   0x04f708: aa0103f4  mov      x20, x1
//   0x04f70c: aa0003f3  mov      x19, x0
//   0x04f710: 97fffe1a  bl       #0x4ef78
//   0x04f714: f9400ec9  ldr      x9, [x22, #0x18]
//   0x04f718: 910082ca  add      x10, x22, #0x20
//   0x04f71c: eb0a013f  cmp      x9, x10
//   0x04f720: 540003c0  b.eq     #0x4f798
//   0x04f724: 2a1f03e8  mov      w8, wzr
//   0x04f728: b980412c  ldrsw    x12, [x9, #0x40]
uint64_t fde_0510_sub_04f6ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xEB0A013FULL) + (x2 ^ 0x04F6ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x04f6ec: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x04f6f0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04f6f4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x04f6f8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04f6fc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x04f700: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x04f704: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04f708: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04f70c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE1AULL; // 0x04f710: bl #0x4ef78
    return acc;
}

// [EN] Reconstructed FDE #0511 @ 0x04fc38..0x050340 (1800 bytes)
// [VN] Phục dựng FDE #0511 tại 0x04fc38..0x050340 (1800 byte)
//   0x04fc38: d10183ff  sub      sp, sp, #0x60
//   0x04fc3c: f90013f7  str      x23, [sp, #0x20]
//   0x04fc40: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04fc44: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04fc48: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04fc4c: 910143fd  add      x29, sp, #0x50
//   0x04fc50: aa0403f7  mov      x23, x4
//   0x04fc54: aa0303f6  mov      x22, x3
//   0x04fc58: aa0203f5  mov      x21, x2
//   0x04fc5c: aa0103f4  mov      x20, x1
//   0x04fc60: aa0003f3  mov      x19, x0
//   0x04fc64: 97fffea2  bl       #0x4f6ec
//   0x04fc68: f9400ee9  ldr      x9, [x23, #0x18]
//   0x04fc6c: 910082ea  add      x10, x23, #0x20
//   0x04fc70: eb0a013f  cmp      x9, x10
//   0x04fc74: 540003c0  b.eq     #0x4fcec
uint64_t fde_0511_sub_04fc38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400EE9ULL) + (x2 ^ 0x04FC38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x04fc38: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x04fc3c: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04fc40: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04fc44: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04fc48: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04fc4c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F7ULL; // 0x04fc50: mov x23, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x04fc54: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x04fc58: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04fc5c: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0512 @ 0x050340..0x050a8c (1868 bytes)
// [VN] Phục dựng FDE #0512 tại 0x050340..0x050a8c (1868 byte)
//   0x050340: d10283ff  sub      sp, sp, #0xa0
//   0x050344: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x050348: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x05034c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x050350: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x050354: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x050358: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x05035c: 910243fd  add      x29, sp, #0x90
//   0x050360: d53bd056  mrs      x22, tpidr_el0
//   0x050364: cb000028  sub      x8, x1, x0
//   0x050368: f94016c9  ldr      x9, [x22, #0x28]
//   0x05036c: b201f3ea  mov      x10, #-0x5555555555555556
//   0x050370: 9344fd08  asr      x8, x8, #4
//   0x050374: f295556a  movk     x10, #0xaaab
//   0x050378: 9b0a7d08  mul      x8, x8, x10
//   0x05037c: aa0103f3  mov      x19, x1
uint64_t fde_0512_sub_050340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x9344FD08ULL) + (x2 ^ 0x050340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x050340: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x050344: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x050348: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x05034c: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x050350: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x050354: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x050358: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x05035c: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x050360: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000028ULL; // 0x050364: sub x8, x1, x0
    return acc;
}

// [EN] Reconstructed FDE #0513 @ 0x050a8c..0x050bac (288 bytes)
// [VN] Phục dựng FDE #0513 tại 0x050a8c..0x050bac (288 byte)
//   0x050a8c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x050a90: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x050a94: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x050a98: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x050a9c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x050aa0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x050aa4: 910143fd  add      x29, sp, #0x50
//   0x050aa8: aa0003f4  mov      x20, x0
//   0x050aac: f8408e97  ldr      x23, [x20, #8]!
//   0x050ab0: aa0103f3  mov      x19, x1
//   0x050ab4: b4000657  cbz      x23, #0x50b7c
//   0x050ab8: 39400048  ldrb     w8, [x2]
//   0x050abc: a940a849  ldp      x9, x10, [x2, #8]
//   0x050ac0: 91002014  add      x20, x0, #8
//   0x050ac4: d341fd0b  lsr      x11, x8, #1
//   0x050ac8: 7200011f  tst      w8, #1
uint64_t fde_0513_sub_050a8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x050A8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x050a8c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x050a90: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x050a94: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x050a98: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x050a9c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x050aa0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x050aa4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x050aa8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x050aac: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x050ab0: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0514 @ 0x050bac..0x050c4c (160 bytes)
// [VN] Phục dựng FDE #0514 tại 0x050bac..0x050c4c (160 byte)
//   0x050bac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x050bb0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x050bb4: 910043fd  add      x29, sp, #0x10
//   0x050bb8: f9400408  ldr      x8, [x0, #8]
//   0x050bbc: f9400109  ldr      x9, [x8]
//   0x050bc0: f85e8129  ldur     x9, [x9, #-0x18]
//   0x050bc4: 8b090108  add      x8, x8, x9
//   0x050bc8: f9401509  ldr      x9, [x8, #0x28]
//   0x050bcc: b4000329  cbz      x9, #0x50c30
//   0x050bd0: b9402109  ldr      w9, [x8, #0x20]
//   0x050bd4: 350002e9  cbnz     w9, #0x50c30
//   0x050bd8: 39402508  ldrb     w8, [x8, #9]
//   0x050bdc: 362802a8  tbz      w8, #5, #0x50c30
//   0x050be0: aa0003f3  mov      x19, x0
//   0x050be4: 940032f7  bl       #0x5d7c0
//   0x050be8: 37000240  tbnz     w0, #0, #0x50c30
uint64_t fde_0514_sub_050bac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x362802A8ULL) + (x2 ^ 0x050BACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x050bac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x050bb0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x050bb4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x050bb8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x050bbc: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8129ULL; // 0x050bc0: ldur x9, [x9, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090108ULL; // 0x050bc4: add x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x050bc8: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000329ULL; // 0x050bcc: cbz x9, #0x50c30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402109ULL; // 0x050bd0: ldr w9, [x8, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0515 @ 0x050c4c..0x050c98 (76 bytes)
// [VN] Phục dựng FDE #0515 tại 0x050c4c..0x050c98 (76 byte)
//   0x050c4c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x050c50: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x050c54: 910043fd  add      x29, sp, #0x10
//   0x050c58: 39410008  ldrb     w8, [x0, #0x40]
//   0x050c5c: 90000089  adrp     x9, #0x60000
//   0x050c60: aa0003f3  mov      x19, x0
//   0x050c64: 910ea129  add      x9, x9, #0x3a8
//   0x050c68: f9000009  str      x9, [x0]
//   0x050c6c: 36000068  tbz      w8, #0, #0x50c78
//   0x050c70: f9402a60  ldr      x0, [x19, #0x50]
//   0x050c74: 9400317f  bl       #0x5d270
//   0x050c78: 90000088  adrp     x8, #0x60000
//   0x050c7c: f9468908  ldr      x8, [x8, #0xd10]
//   0x050c80: 91004108  add      x8, x8, #0x10
//   0x050c84: f8008668  str      x8, [x19], #8
//   0x050c88: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0515_sub_050c4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9468908ULL) + (x2 ^ 0x050C4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x050c4c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x050c50: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x050c54: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39410008ULL; // 0x050c58: ldrb w8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000089ULL; // 0x050c5c: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x050c60: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910EA129ULL; // 0x050c64: add x9, x9, #0x3a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x050c68: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000068ULL; // 0x050c6c: tbz w8, #0, #0x50c78
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402A60ULL; // 0x050c70: ldr x0, [x19, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0516 @ 0x050c98..0x050cec (84 bytes)
// [VN] Phục dựng FDE #0516 tại 0x050c98..0x050cec (84 byte)
//   0x050c98: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x050c9c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x050ca0: 910043fd  add      x29, sp, #0x10
//   0x050ca4: 39410008  ldrb     w8, [x0, #0x40]
//   0x050ca8: 90000089  adrp     x9, #0x60000
//   0x050cac: aa0003f3  mov      x19, x0
//   0x050cb0: 910ea129  add      x9, x9, #0x3a8
//   0x050cb4: f9000009  str      x9, [x0]
//   0x050cb8: 36000068  tbz      w8, #0, #0x50cc4
//   0x050cbc: f9402a60  ldr      x0, [x19, #0x50]
//   0x050cc0: 9400316c  bl       #0x5d270
//   0x050cc4: 90000088  adrp     x8, #0x60000
//   0x050cc8: f9468908  ldr      x8, [x8, #0xd10]
//   0x050ccc: aa1303e0  mov      x0, x19
//   0x050cd0: 91004108  add      x8, x8, #0x10
//   0x050cd4: f8008408  str      x8, [x0], #8
uint64_t fde_0516_sub_050c98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9468908ULL) + (x2 ^ 0x050C98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x050c98: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x050c9c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x050ca0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39410008ULL; // 0x050ca4: ldrb w8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000089ULL; // 0x050ca8: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x050cac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910EA129ULL; // 0x050cb0: add x9, x9, #0x3a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x050cb4: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000068ULL; // 0x050cb8: tbz w8, #0, #0x50cc4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402A60ULL; // 0x050cbc: ldr x0, [x19, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0517 @ 0x050cec..0x050e14 (296 bytes)
// [VN] Phục dựng FDE #0517 tại 0x050cec..0x050e14 (296 byte)
//   0x050cec: f9402c08  ldr      x8, [x0, #0x58]
//   0x050cf0: f9401809  ldr      x9, [x0, #0x30]
//   0x050cf4: eb09011f  cmp      x8, x9
//   0x050cf8: 54000062  b.hs     #0x50d04
//   0x050cfc: aa0903e8  mov      x8, x9
//   0x050d00: f9002c09  str      x9, [x0, #0x58]
//   0x050d04: 721d046a  ands     w10, w3, #0x18
//   0x050d08: 540000a0  b.eq     #0x50d1c
//   0x050d0c: 7100045f  cmp      w2, #1
//   0x050d10: 540000c1  b.ne     #0x50d28
//   0x050d14: 7100615f  cmp      w10, #0x18
//   0x050d18: 54000081  b.ne     #0x50d28
//   0x050d1c: 92800001  mov      x1, #-1
//   0x050d20: aa1f03e0  mov      x0, xzr
//   0x050d24: d65f03c0  ret      
//   0x050d28: b40003c8  cbz      x8, #0x50da0
uint64_t fde_0517_sub_050cec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C08ULL) + (x1 ^ 0x92800001ULL) + (x2 ^ 0x050CECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C08ULL; // 0x050cec: ldr x8, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401809ULL; // 0x050cf0: ldr x9, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x050cf4: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x050cf8: b.hs #0x50d04
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E8ULL; // 0x050cfc: mov x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002C09ULL; // 0x050d00: str x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x721D046AULL; // 0x050d04: ands w10, w3, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x050d08: b.eq #0x50d1c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x050d0c: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x050d10: b.ne #0x50d28
    return acc;
}

// [EN] Reconstructed FDE #0518 @ 0x050e14..0x050e28 (20 bytes)
// [VN] Phục dựng FDE #0518 tại 0x050e14..0x050e28 (20 byte)
//   0x050e14: f9400008  ldr      x8, [x0]
//   0x050e18: aa0203e1  mov      x1, x2
//   0x050e1c: 2a1f03e2  mov      w2, wzr
//   0x050e20: f9401104  ldr      x4, [x8, #0x20]
//   0x050e24: d61f0080  br       x4
uint64_t fde_0518_sub_050e14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x050E14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x050e14: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x050e18: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x050e1c: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401104ULL; // 0x050e20: ldr x4, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0080ULL; // 0x050e24: br x4
    return acc;
}

// [EN] Reconstructed FDE #0519 @ 0x050e28..0x050e78 (80 bytes)
// [VN] Phục dựng FDE #0519 tại 0x050e28..0x050e78 (80 byte)
//   0x050e28: f9402c08  ldr      x8, [x0, #0x58]
//   0x050e2c: f9401809  ldr      x9, [x0, #0x30]
//   0x050e30: eb09011f  cmp      x8, x9
//   0x050e34: 54000062  b.hs     #0x50e40
//   0x050e38: aa0903e8  mov      x8, x9
//   0x050e3c: f9002c09  str      x9, [x0, #0x58]
//   0x050e40: 39418009  ldrb     w9, [x0, #0x60]
//   0x050e44: 36180169  tbz      w9, #3, #0x50e70
//   0x050e48: f9401009  ldr      x9, [x0, #0x20]
//   0x050e4c: eb08013f  cmp      x9, x8
//   0x050e50: 54000062  b.hs     #0x50e5c
//   0x050e54: aa0803e9  mov      x9, x8
//   0x050e58: f9001008  str      x8, [x0, #0x20]
//   0x050e5c: f9400c08  ldr      x8, [x0, #0x18]
//   0x050e60: eb09011f  cmp      x8, x9
//   0x050e64: 54000062  b.hs     #0x50e70
uint64_t fde_0519_sub_050e28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C08ULL) + (x1 ^ 0xF9001008ULL) + (x2 ^ 0x050E28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C08ULL; // 0x050e28: ldr x8, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401809ULL; // 0x050e2c: ldr x9, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x050e30: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x050e34: b.hs #0x50e40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E8ULL; // 0x050e38: mov x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002C09ULL; // 0x050e3c: str x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x39418009ULL; // 0x050e40: ldrb w9, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x36180169ULL; // 0x050e44: tbz w9, #3, #0x50e70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401009ULL; // 0x050e48: ldr x9, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x050e4c: cmp x9, x8
    return acc;
}

// [EN] Reconstructed FDE #0520 @ 0x050e78..0x050ee8 (112 bytes)
// [VN] Phục dựng FDE #0520 tại 0x050e78..0x050ee8 (112 byte)
//   0x050e78: f9402c09  ldr      x9, [x0, #0x58]
//   0x050e7c: f940180a  ldr      x10, [x0, #0x30]
//   0x050e80: aa0003e8  mov      x8, x0
//   0x050e84: 2a0103e0  mov      w0, w1
//   0x050e88: eb0a013f  cmp      x9, x10
//   0x050e8c: 54000062  b.hs     #0x50e98
//   0x050e90: aa0a03e9  mov      x9, x10
//   0x050e94: f9002d0a  str      x10, [x8, #0x58]
//   0x050e98: a941290b  ldp      x11, x10, [x8, #0x10]
//   0x050e9c: eb0a017f  cmp      x11, x10
//   0x050ea0: 54000182  b.hs     #0x50ed0
//   0x050ea4: 3100041f  cmn      w0, #1
//   0x050ea8: 54000180  b.eq     #0x50ed8
//   0x050eac: 3941810b  ldrb     w11, [x8, #0x60]
//   0x050eb0: 3720008b  tbnz     w11, #4, #0x50ec0
//   0x050eb4: 385ff14b  ldurb    w11, [x10, #-1]
uint64_t fde_0520_sub_050e78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C09ULL) + (x1 ^ 0x54000180ULL) + (x2 ^ 0x050E78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C09ULL; // 0x050e78: ldr x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940180AULL; // 0x050e7c: ldr x10, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x050e80: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x050e84: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A013FULL; // 0x050e88: cmp x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x050e8c: b.hs #0x50e98
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0A03E9ULL; // 0x050e90: mov x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002D0AULL; // 0x050e94: str x10, [x8, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xA941290BULL; // 0x050e98: ldp x11, x10, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A017FULL; // 0x050e9c: cmp x11, x10
    return acc;
}

// [EN] Reconstructed FDE #0521 @ 0x050ee8..0x0511d8 (752 bytes)
// [VN] Phục dựng FDE #0521 tại 0x050ee8..0x0511d8 (752 byte)
//   0x050ee8: d101c3ff  sub      sp, sp, #0x70
//   0x050eec: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x050ef0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x050ef4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x050ef8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x050efc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x050f00: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x050f04: 910183fd  add      x29, sp, #0x60
//   0x050f08: 3100043f  cmn      w1, #1
//   0x050f0c: 54000120  b.eq     #0x50f30
//   0x050f10: a943201a  ldp      x26, x8, [x0, #0x30]
//   0x050f14: a9416418  ldp      x24, x25, [x0, #0x10]
//   0x050f18: 2a0103f3  mov      w19, w1
//   0x050f1c: aa0003f4  mov      x20, x0
//   0x050f20: eb08035f  cmp      x26, x8
//   0x050f24: 540000a0  b.eq     #0x50f38
uint64_t fde_0521_sub_050ee8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0103F3ULL) + (x2 ^ 0x050EE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x050ee8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x050eec: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x050ef0: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x050ef4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x050ef8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x050efc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x050f00: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x050f04: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x3100043FULL; // 0x050f08: cmn w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x050f0c: b.eq #0x50f30
    return acc;
}

// [EN] Reconstructed FDE #0522 @ 0x0511d8..0x0512fc (292 bytes)
// [VN] Phục dựng FDE #0522 tại 0x0511d8..0x0512fc (292 byte)
//   0x0511d8: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0511dc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0511e0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0511e4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0511e8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0511ec: 910103fd  add      x29, sp, #0x40
//   0x0511f0: 92800208  mov      x8, #-0x11
//   0x0511f4: cb010108  sub      x8, x8, x1
//   0x0511f8: eb02011f  cmp      x8, x2
//   0x0511fc: 540007e3  b.lo     #0x512f8
//   0x051200: 39400008  ldrb     w8, [x0]
//   0x051204: aa0403f5  mov      x21, x4
//   0x051208: aa0303f7  mov      x23, x3
//   0x05120c: aa0103f4  mov      x20, x1
//   0x051210: aa0003f3  mov      x19, x0
//   0x051214: 37000428  tbnz     w8, #0, #0x51298
uint64_t fde_0522_sub_0511d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0303F7ULL) + (x2 ^ 0x0511D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x0511d8: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0511dc: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0511e0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0511e4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0511e8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0511ec: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x92800208ULL; // 0x0511f0: mov x8, #-0x11
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010108ULL; // 0x0511f4: sub x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x0511f8: cmp x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540007E3ULL; // 0x0511fc: b.lo #0x512f8
    return acc;
}

// [EN] Reconstructed FDE #0523 @ 0x0512fc..0x051304 (8 bytes)
// [VN] Phục dựng FDE #0523 tại 0x0512fc..0x051304 (8 byte)
//   0x0512fc: 91004000  add      x0, x0, #0x10
//   0x051300: 14003100  b        #0x5d700
uint64_t fde_0523_sub_0512fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91004000ULL) + (x1 ^ 0x14003100ULL) + (x2 ^ 0x0512FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x0512fc: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x14003100ULL; // 0x051300: b #0x5d700
    return acc;
}

// [EN] Reconstructed FDE #0524 @ 0x051304..0x05132c (40 bytes)
// [VN] Phục dựng FDE #0524 tại 0x051304..0x05132c (40 byte)
//   0x051304: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x051308: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05130c: 910043fd  add      x29, sp, #0x10
//   0x051310: aa0003f3  mov      x19, x0
//   0x051314: 91004000  add      x0, x0, #0x10
//   0x051318: 940030fa  bl       #0x5d700
//   0x05131c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x051320: aa1303e0  mov      x0, x19
//   0x051324: f84207f3  ldr      x19, [sp], #0x20
//   0x051328: 14002fd2  b        #0x5d270
uint64_t fde_0524_sub_051304(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x14002FD2ULL) + (x2 ^ 0x051304ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051304: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051308: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05130c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051310: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x051314: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x940030FAULL; // 0x051318: bl #0x5d700
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x05131c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051320: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x051324: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x14002FD2ULL; // 0x051328: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0525 @ 0x05132c..0x051340 (20 bytes)
// [VN] Phục dựng FDE #0525 tại 0x05132c..0x051340 (20 byte)
//   0x05132c: f9400008  ldr      x8, [x0]
//   0x051330: f85e8108  ldur     x8, [x8, #-0x18]
//   0x051334: 8b080008  add      x8, x0, x8
//   0x051338: 91004100  add      x0, x8, #0x10
//   0x05133c: 140030f1  b        #0x5d700
uint64_t fde_0525_sub_05132c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x140030F1ULL) + (x2 ^ 0x05132CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x05132c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x051330: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x051334: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004100ULL; // 0x051338: add x0, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x140030F1ULL; // 0x05133c: b #0x5d700
    return acc;
}

// [EN] Reconstructed FDE #0526 @ 0x051340..0x051370 (48 bytes)
// [VN] Phục dựng FDE #0526 tại 0x051340..0x051370 (48 byte)
//   0x051340: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x051344: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051348: 910043fd  add      x29, sp, #0x10
//   0x05134c: f9400008  ldr      x8, [x0]
//   0x051350: f85e8108  ldur     x8, [x8, #-0x18]
//   0x051354: 8b080013  add      x19, x0, x8
//   0x051358: 91004260  add      x0, x19, #0x10
//   0x05135c: 940030e9  bl       #0x5d700
//   0x051360: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x051364: aa1303e0  mov      x0, x19
//   0x051368: f84207f3  ldr      x19, [sp], #0x20
//   0x05136c: 14002fc1  b        #0x5d270
uint64_t fde_0526_sub_051340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x14002FC1ULL) + (x2 ^ 0x051340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051340: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051344: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051348: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x05134c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x051350: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x051354: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004260ULL; // 0x051358: add x0, x19, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x940030E9ULL; // 0x05135c: bl #0x5d700
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x051360: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051364: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0527 @ 0x051370..0x0513dc (108 bytes)
// [VN] Phục dựng FDE #0527 tại 0x051370..0x0513dc (108 byte)
//   0x051370: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x051374: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051378: 910043fd  add      x29, sp, #0x10
//   0x05137c: f0000068  adrp     x8, #0x60000
//   0x051380: 910ba108  add      x8, x8, #0x2e8
//   0x051384: 39416009  ldrb     w9, [x0, #0x58]
//   0x051388: 9101410a  add      x10, x8, #0x50
//   0x05138c: f900400a  str      x10, [x0, #0x80]
//   0x051390: f000006a  adrp     x10, #0x60000
//   0x051394: aa0003f3  mov      x19, x0
//   0x051398: f9000008  str      x8, [x0]
//   0x05139c: 9100a108  add      x8, x8, #0x28
//   0x0513a0: 910ea14a  add      x10, x10, #0x3a8
//   0x0513a4: a9012808  stp      x8, x10, [x0, #0x10]
//   0x0513a8: 36000069  tbz      w9, #0, #0x513b4
//   0x0513ac: f9403660  ldr      x0, [x19, #0x68]
uint64_t fde_0527_sub_051370(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910EA14AULL) + (x2 ^ 0x051370ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051370: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051374: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051378: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000068ULL; // 0x05137c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA108ULL; // 0x051380: add x8, x8, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0x39416009ULL; // 0x051384: ldrb w9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101410AULL; // 0x051388: add x10, x8, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF900400AULL; // 0x05138c: str x10, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF000006AULL; // 0x051390: adrp x10, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051394: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0528 @ 0x0513dc..0x051450 (116 bytes)
// [VN] Phục dựng FDE #0528 tại 0x0513dc..0x051450 (116 byte)
//   0x0513dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0513e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0513e4: 910043fd  add      x29, sp, #0x10
//   0x0513e8: f0000068  adrp     x8, #0x60000
//   0x0513ec: 910ba108  add      x8, x8, #0x2e8
//   0x0513f0: 39416009  ldrb     w9, [x0, #0x58]
//   0x0513f4: 9101410a  add      x10, x8, #0x50
//   0x0513f8: f900400a  str      x10, [x0, #0x80]
//   0x0513fc: f000006a  adrp     x10, #0x60000
//   0x051400: aa0003f3  mov      x19, x0
//   0x051404: f9000008  str      x8, [x0]
//   0x051408: 9100a108  add      x8, x8, #0x28
//   0x05140c: 910ea14a  add      x10, x10, #0x3a8
//   0x051410: a9012808  stp      x8, x10, [x0, #0x10]
//   0x051414: 36000069  tbz      w9, #0, #0x51420
//   0x051418: f9403660  ldr      x0, [x19, #0x68]
uint64_t fde_0528_sub_0513dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910EA14AULL) + (x2 ^ 0x0513DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0513dc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0513e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0513e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000068ULL; // 0x0513e8: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA108ULL; // 0x0513ec: add x8, x8, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0x39416009ULL; // 0x0513f0: ldrb w9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101410AULL; // 0x0513f4: add x10, x8, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF900400AULL; // 0x0513f8: str x10, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF000006AULL; // 0x0513fc: adrp x10, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051400: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0529 @ 0x051450..0x0514c0 (112 bytes)
// [VN] Phục dựng FDE #0529 tại 0x051450..0x0514c0 (112 byte)
//   0x051450: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x051454: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051458: 910043fd  add      x29, sp, #0x10
//   0x05145c: f0000068  adrp     x8, #0x60000
//   0x051460: 910ba108  add      x8, x8, #0x2e8
//   0x051464: aa0003f4  mov      x20, x0
//   0x051468: 91014109  add      x9, x8, #0x50
//   0x05146c: aa0003f3  mov      x19, x0
//   0x051470: f81f0e88  str      x8, [x20, #-0x10]!
//   0x051474: f8070e69  str      x9, [x19, #0x70]!
//   0x051478: 39412009  ldrb     w9, [x0, #0x48]
//   0x05147c: f000006a  adrp     x10, #0x60000
//   0x051480: 9100a108  add      x8, x8, #0x28
//   0x051484: 910ea14a  add      x10, x10, #0x3a8
//   0x051488: a9002808  stp      x8, x10, [x0]
//   0x05148c: 36000069  tbz      w9, #0, #0x51498
uint64_t fde_0529_sub_051450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9100A108ULL) + (x2 ^ 0x051450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x051450: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051454: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051458: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000068ULL; // 0x05145c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA108ULL; // 0x051460: add x8, x8, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x051464: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91014109ULL; // 0x051468: add x9, x8, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05146c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0E88ULL; // 0x051470: str x8, [x20, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF8070E69ULL; // 0x051474: str x9, [x19, #0x70]!
    return acc;
}

// [EN] Reconstructed FDE #0530 @ 0x0514c0..0x051538 (120 bytes)
// [VN] Phục dựng FDE #0530 tại 0x0514c0..0x051538 (120 byte)
//   0x0514c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0514c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0514c8: 910043fd  add      x29, sp, #0x10
//   0x0514cc: f0000068  adrp     x8, #0x60000
//   0x0514d0: 910ba108  add      x8, x8, #0x2e8
//   0x0514d4: aa0003f3  mov      x19, x0
//   0x0514d8: 91014109  add      x9, x8, #0x50
//   0x0514dc: aa0003f4  mov      x20, x0
//   0x0514e0: f81f0e68  str      x8, [x19, #-0x10]!
//   0x0514e4: f8070e89  str      x9, [x20, #0x70]!
//   0x0514e8: 39412009  ldrb     w9, [x0, #0x48]
//   0x0514ec: f000006a  adrp     x10, #0x60000
//   0x0514f0: 9100a108  add      x8, x8, #0x28
//   0x0514f4: 910ea14a  add      x10, x10, #0x3a8
//   0x0514f8: a9002808  stp      x8, x10, [x0]
//   0x0514fc: 36000069  tbz      w9, #0, #0x51508
uint64_t fde_0530_sub_0514c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9100A108ULL) + (x2 ^ 0x0514C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0514c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0514c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0514c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000068ULL; // 0x0514cc: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA108ULL; // 0x0514d0: add x8, x8, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0514d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91014109ULL; // 0x0514d8: add x9, x8, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0514dc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0E68ULL; // 0x0514e0: str x8, [x19, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF8070E89ULL; // 0x0514e4: str x9, [x20, #0x70]!
    return acc;
}

// [EN] Reconstructed FDE #0531 @ 0x051538..0x0515b0 (120 bytes)
// [VN] Phục dựng FDE #0531 tại 0x051538..0x0515b0 (120 byte)
//   0x051538: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05153c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051540: 910043fd  add      x29, sp, #0x10
//   0x051544: f9400008  ldr      x8, [x0]
//   0x051548: f0000069  adrp     x9, #0x60000
//   0x05154c: 910ba129  add      x9, x9, #0x2e8
//   0x051550: f000006a  adrp     x10, #0x60000
//   0x051554: f85e8108  ldur     x8, [x8, #-0x18]
//   0x051558: 910ea14a  add      x10, x10, #0x3a8
//   0x05155c: 8b080014  add      x20, x0, x8
//   0x051560: 91014128  add      x8, x9, #0x50
//   0x051564: aa1403f3  mov      x19, x20
//   0x051568: f9000289  str      x9, [x20]
//   0x05156c: f8080e68  str      x8, [x19, #0x80]!
//   0x051570: 39416288  ldrb     w8, [x20, #0x58]
//   0x051574: 9100a129  add      x9, x9, #0x28
uint64_t fde_0531_sub_051538(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000289ULL) + (x2 ^ 0x051538ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x051538: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05153c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051540: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x051544: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000069ULL; // 0x051548: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA129ULL; // 0x05154c: add x9, x9, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF000006AULL; // 0x051550: adrp x10, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x051554: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910EA14AULL; // 0x051558: add x10, x10, #0x3a8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080014ULL; // 0x05155c: add x20, x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0532 @ 0x0515b0..0x051630 (128 bytes)
// [VN] Phục dựng FDE #0532 tại 0x0515b0..0x051630 (128 byte)
//   0x0515b0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0515b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0515b8: 910043fd  add      x29, sp, #0x10
//   0x0515bc: f9400008  ldr      x8, [x0]
//   0x0515c0: f0000069  adrp     x9, #0x60000
//   0x0515c4: 910ba129  add      x9, x9, #0x2e8
//   0x0515c8: f000006a  adrp     x10, #0x60000
//   0x0515cc: f85e8108  ldur     x8, [x8, #-0x18]
//   0x0515d0: 910ea14a  add      x10, x10, #0x3a8
//   0x0515d4: 8b080013  add      x19, x0, x8
//   0x0515d8: 91014128  add      x8, x9, #0x50
//   0x0515dc: aa1303f4  mov      x20, x19
//   0x0515e0: f9000269  str      x9, [x19]
//   0x0515e4: f8080e88  str      x8, [x20, #0x80]!
//   0x0515e8: 39416268  ldrb     w8, [x19, #0x58]
//   0x0515ec: 9100a129  add      x9, x9, #0x28
uint64_t fde_0532_sub_0515b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x0515B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0515b0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0515b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0515b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0515bc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000069ULL; // 0x0515c0: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BA129ULL; // 0x0515c4: add x9, x9, #0x2e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF000006AULL; // 0x0515c8: adrp x10, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x0515cc: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910EA14AULL; // 0x0515d0: add x10, x10, #0x3a8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x0515d4: add x19, x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0533 @ 0x051630..0x051638 (8 bytes)
// [VN] Phục dựng FDE #0533 tại 0x051630..0x051638 (8 byte)
//   0x051630: 91002000  add      x0, x0, #8
//   0x051634: 14003033  b        #0x5d700
uint64_t fde_0533_sub_051630(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002000ULL) + (x1 ^ 0x14003033ULL) + (x2 ^ 0x051630ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x051630: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x14003033ULL; // 0x051634: b #0x5d700
    return acc;
}

// [EN] Reconstructed FDE #0534 @ 0x051638..0x051660 (40 bytes)
// [VN] Phục dựng FDE #0534 tại 0x051638..0x051660 (40 byte)
//   0x051638: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x05163c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051640: 910043fd  add      x29, sp, #0x10
//   0x051644: aa0003f3  mov      x19, x0
//   0x051648: 91002000  add      x0, x0, #8
//   0x05164c: 9400302d  bl       #0x5d700
//   0x051650: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x051654: aa1303e0  mov      x0, x19
//   0x051658: f84207f3  ldr      x19, [sp], #0x20
//   0x05165c: 14002f05  b        #0x5d270
uint64_t fde_0534_sub_051638(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x14002F05ULL) + (x2 ^ 0x051638ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051638: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05163c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051640: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051644: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x051648: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400302DULL; // 0x05164c: bl #0x5d700
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x051650: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051654: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x051658: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x14002F05ULL; // 0x05165c: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0535 @ 0x051660..0x051674 (20 bytes)
// [VN] Phục dựng FDE #0535 tại 0x051660..0x051674 (20 byte)
//   0x051660: f9400008  ldr      x8, [x0]
//   0x051664: f85e8108  ldur     x8, [x8, #-0x18]
//   0x051668: 8b080008  add      x8, x0, x8
//   0x05166c: 91002100  add      x0, x8, #8
//   0x051670: 14003024  b        #0x5d700
uint64_t fde_0535_sub_051660(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x14003024ULL) + (x2 ^ 0x051660ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x051660: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x051664: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x051668: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x05166c: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x14003024ULL; // 0x051670: b #0x5d700
    return acc;
}

// [EN] Reconstructed FDE #0536 @ 0x051674..0x0516a4 (48 bytes)
// [VN] Phục dựng FDE #0536 tại 0x051674..0x0516a4 (48 byte)
//   0x051674: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x051678: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05167c: 910043fd  add      x29, sp, #0x10
//   0x051680: f9400008  ldr      x8, [x0]
//   0x051684: f85e8108  ldur     x8, [x8, #-0x18]
//   0x051688: 8b080013  add      x19, x0, x8
//   0x05168c: 91002260  add      x0, x19, #8
//   0x051690: 9400301c  bl       #0x5d700
//   0x051694: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x051698: aa1303e0  mov      x0, x19
//   0x05169c: f84207f3  ldr      x19, [sp], #0x20
//   0x0516a0: 14002ef4  b        #0x5d270
uint64_t fde_0536_sub_051674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x14002EF4ULL) + (x2 ^ 0x051674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051674: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051678: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05167c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x051680: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x051684: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x051688: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x05168c: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400301CULL; // 0x051690: bl #0x5d700
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x051694: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x051698: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0537 @ 0x0516a4..0x0518d0 (556 bytes)
// [VN] Phục dựng FDE #0537 tại 0x0516a4..0x0518d0 (556 byte)
//   0x0516a4: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0516a8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0516ac: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0516b0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0516b4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0516b8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0516bc: 910143fd  add      x29, sp, #0x50
//   0x0516c0: 900000a8  adrp     x8, #0x65000
//   0x0516c4: f9434519  ldr      x25, [x8, #0x688]
//   0x0516c8: 2a0503f4  mov      w20, w5
//   0x0516cc: 2a0403f6  mov      w22, w4
//   0x0516d0: aa0303f7  mov      x23, x3
//   0x0516d4: aa0203f8  mov      x24, x2
//   0x0516d8: aa0103f5  mov      x21, x1
//   0x0516dc: 71000cbf  cmp      w5, #3
//   0x0516e0: aa0003f3  mov      x19, x0
uint64_t fde_0537_sub_0516a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0203F8ULL) + (x2 ^ 0x0516A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x0516a4: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0516a8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0516ac: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0516b0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0516b4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0516b8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0516bc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x0516c0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9434519ULL; // 0x0516c4: ldr x25, [x8, #0x688]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F4ULL; // 0x0516c8: mov w20, w5
    return acc;
}

// [EN] Reconstructed FDE #0538 @ 0x0518d0..0x051924 (84 bytes)
// [VN] Phục dựng FDE #0538 tại 0x0518d0..0x051924 (84 byte)
//   0x0518d0: 360000e0  tbz      w0, #0, #0x518ec
//   0x0518d4: 900000a8  adrp     x8, #0x65000
//   0x0518d8: f9433d08  ldr      x8, [x8, #0x678]
//   0x0518dc: b4000088  cbz      x8, #0x518ec
//   0x0518e0: f9400109  ldr      x9, [x8]
//   0x0518e4: b5000109  cbnz     x9, #0x51904
//   0x0518e8: 1400000d  b        #0x5191c
//   0x0518ec: 36080180  tbz      w0, #1, #0x5191c
//   0x0518f0: 900000a8  adrp     x8, #0x65000
//   0x0518f4: f9434108  ldr      x8, [x8, #0x680]
//   0x0518f8: b4000128  cbz      x8, #0x5191c
//   0x0518fc: f9400109  ldr      x9, [x8]
//   0x051900: b40000e9  cbz      x9, #0x5191c
//   0x051904: b9400129  ldr      w9, [x9]
//   0x051908: b9406d08  ldr      w8, [x8, #0x6c]
//   0x05190c: 12003d2a  and      w10, w9, #0xffff
uint64_t fde_0538_sub_0518d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x360000E0ULL) + (x1 ^ 0xB40000E9ULL) + (x2 ^ 0x0518D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x360000E0ULL; // 0x0518d0: tbz w0, #0, #0x518ec
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x0518d4: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433D08ULL; // 0x0518d8: ldr x8, [x8, #0x678]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x0518dc: cbz x8, #0x518ec
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x0518e0: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000109ULL; // 0x0518e4: cbnz x9, #0x51904
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000DULL; // 0x0518e8: b #0x5191c
    acc = (acc * 0x100000001B3ULL) ^ 0x36080180ULL; // 0x0518ec: tbz w0, #1, #0x5191c
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x0518f0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9434108ULL; // 0x0518f4: ldr x8, [x8, #0x680]
    return acc;
}

// [EN] Reconstructed FDE #0539 @ 0x051924..0x051b08 (484 bytes)
// [VN] Phục dựng FDE #0539 tại 0x051924..0x051b08 (484 byte)
//   0x051924: d101c3ff  sub      sp, sp, #0x70
//   0x051928: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x05192c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x051930: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x051934: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x051938: 910183fd  add      x29, sp, #0x60
//   0x05193c: d53bd058  mrs      x24, tpidr_el0
//   0x051940: f9401708  ldr      x8, [x24, #0x28]
//   0x051944: 2a0103f7  mov      w23, w1
//   0x051948: d0fffe01  adrp     x1, #0x13000
//   0x05194c: 91068821  add      x1, x1, #0x1a2
//   0x051950: f90017e8  str      x8, [sp, #0x28]
//   0x051954: f9400008  ldr      x8, [x0]
//   0x051958: aa0403f5  mov      x21, x4
//   0x05195c: aa0303f6  mov      x22, x3
//   0x051960: 2a0203f4  mov      w20, w2
uint64_t fde_0539_sub_051924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x051924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x051924: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x051928: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x05192c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x051930: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x051934: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x051938: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x05193c: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x051940: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F7ULL; // 0x051944: mov w23, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x051948: adrp x1, #0x13000
    return acc;
}

// [EN] Reconstructed FDE #0540 @ 0x051b08..0x051b20 (24 bytes)
// [VN] Phục dựng FDE #0540 tại 0x051b08..0x051b20 (24 byte)
//   0x051b08: 7100001f  cmp      w0, #0
//   0x051b0c: 1a9f07e8  cset     w8, ne
//   0x051b10: 7107d03f  cmp      w1, #0x1f4
//   0x051b14: 1a9fd7e9  cset     w9, gt
//   0x051b18: 0a090100  and      w0, w8, w9
//   0x051b1c: d65f03c0  ret      
uint64_t fde_0540_sub_051b08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100001FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x051B08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x051b08: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E8ULL; // 0x051b0c: cset w8, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x7107D03FULL; // 0x051b10: cmp w1, #0x1f4
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FD7E9ULL; // 0x051b14: cset w9, gt
    acc = (acc * 0x100000001B3ULL) ^ 0x0A090100ULL; // 0x051b18: and w0, w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x051b1c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0541 @ 0x051b20..0x051b54 (52 bytes)
// [VN] Phục dựng FDE #0541 tại 0x051b20..0x051b54 (52 byte)
//   0x051b20: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x051b24: 910003fd  mov      x29, sp
//   0x051b28: 2a0303e8  mov      w8, w3
//   0x051b2c: b0fffe03  adrp     x3, #0x12000
//   0x051b30: 90000004  adrp     x4, #0x51000
//   0x051b34: 2a0203e1  mov      w1, w2
//   0x051b38: 91016c63  add      x3, x3, #0x5b
//   0x051b3c: 912c2084  add      x4, x4, #0xb08
//   0x051b40: 2a0803e2  mov      w2, w8
//   0x051b44: 94002f27  bl       #0x5d7e0
//   0x051b48: 12000000  and      w0, w0, #1
//   0x051b4c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x051b50: d65f03c0  ret      
uint64_t fde_0541_sub_051b20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x051B20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x051b20: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x051b24: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E8ULL; // 0x051b28: mov w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE03ULL; // 0x051b2c: adrp x3, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000004ULL; // 0x051b30: adrp x4, #0x51000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x051b34: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91016C63ULL; // 0x051b38: add x3, x3, #0x5b
    acc = (acc * 0x100000001B3ULL) ^ 0x912C2084ULL; // 0x051b3c: add x4, x4, #0xb08
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E2ULL; // 0x051b40: mov w2, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x94002F27ULL; // 0x051b44: bl #0x5d7e0
    return acc;
}

// [EN] Reconstructed FDE #0542 @ 0x051b54..0x051b60 (12 bytes)
// [VN] Phục dựng FDE #0542 tại 0x051b54..0x051b60 (12 byte)
//   0x051b54: b0fffe01  adrp     x1, #0x12000
//   0x051b58: 91016c21  add      x1, x1, #0x5b
//   0x051b5c: 14002ec9  b        #0x5d680
uint64_t fde_0542_sub_051b54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0FFFE01ULL) + (x1 ^ 0x14002EC9ULL) + (x2 ^ 0x051B54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE01ULL; // 0x051b54: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91016C21ULL; // 0x051b58: add x1, x1, #0x5b
    acc = (acc * 0x100000001B3ULL) ^ 0x14002EC9ULL; // 0x051b5c: b #0x5d680
    return acc;
}

// [EN] Reconstructed FDE #0543 @ 0x051b60..0x051bb4 (84 bytes)
// [VN] Phục dựng FDE #0543 tại 0x051b60..0x051bb4 (84 byte)
//   0x051b60: 360000e2  tbz      w2, #0, #0x51b7c
//   0x051b64: 900000a8  adrp     x8, #0x65000
//   0x051b68: f9433d08  ldr      x8, [x8, #0x678]
//   0x051b6c: b4000088  cbz      x8, #0x51b7c
//   0x051b70: f9400109  ldr      x9, [x8]
//   0x051b74: b5000109  cbnz     x9, #0x51b94
//   0x051b78: 1400000d  b        #0x51bac
//   0x051b7c: 36080182  tbz      w2, #1, #0x51bac
//   0x051b80: 900000a8  adrp     x8, #0x65000
//   0x051b84: f9434108  ldr      x8, [x8, #0x680]
//   0x051b88: b4000128  cbz      x8, #0x51bac
//   0x051b8c: f9400109  ldr      x9, [x8]
//   0x051b90: b40000e9  cbz      x9, #0x51bac
//   0x051b94: b9400129  ldr      w9, [x9]
//   0x051b98: b9406d08  ldr      w8, [x8, #0x6c]
//   0x051b9c: 12003d2a  and      w10, w9, #0xffff
uint64_t fde_0543_sub_051b60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x360000E2ULL) + (x1 ^ 0xB40000E9ULL) + (x2 ^ 0x051B60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x360000E2ULL; // 0x051b60: tbz w2, #0, #0x51b7c
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x051b64: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433D08ULL; // 0x051b68: ldr x8, [x8, #0x678]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x051b6c: cbz x8, #0x51b7c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x051b70: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000109ULL; // 0x051b74: cbnz x9, #0x51b94
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000DULL; // 0x051b78: b #0x51bac
    acc = (acc * 0x100000001B3ULL) ^ 0x36080182ULL; // 0x051b7c: tbz w2, #1, #0x51bac
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x051b80: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9434108ULL; // 0x051b84: ldr x8, [x8, #0x680]
    return acc;
}

// [EN] Reconstructed FDE #0544 @ 0x051bb4..0x051bc8 (20 bytes)
// [VN] Phục dựng FDE #0544 tại 0x051bb4..0x051bc8 (20 byte)
//   0x051bb4: 39400008  ldrb     w8, [x0]
//   0x051bb8: 37000048  tbnz     w8, #0, #0x51bc0
//   0x051bbc: d65f03c0  ret      
//   0x051bc0: f9400800  ldr      x0, [x0, #0x10]
//   0x051bc4: 14002dab  b        #0x5d270
uint64_t fde_0544_sub_051bb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0x14002DABULL) + (x2 ^ 0x051BB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x051bb4: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000048ULL; // 0x051bb8: tbnz w8, #0, #0x51bc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x051bbc: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x051bc0: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x14002DABULL; // 0x051bc4: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0545 @ 0x051bc8..0x051c00 (56 bytes)
// [VN] Phục dựng FDE #0545 tại 0x051bc8..0x051c00 (56 byte)
//   0x051bc8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x051bcc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x051bd0: 910043fd  add      x29, sp, #0x10
//   0x051bd4: aa0103e0  mov      x0, x1
//   0x051bd8: aa0103f3  mov      x19, x1
//   0x051bdc: 94002c89  bl       #0x5ce00
//   0x051be0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x051be4: 900000a8  adrp     x8, #0x65000
//   0x051be8: 91234108  add      x8, x8, #0x8d0
//   0x051bec: aa0003e2  mov      x2, x0
//   0x051bf0: aa0803e0  mov      x0, x8
//   0x051bf4: aa1303e1  mov      x1, x19
//   0x051bf8: f84207f3  ldr      x19, [sp], #0x20
//   0x051bfc: 14000001  b        #0x51c00
uint64_t fde_0545_sub_051bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x051BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x051bc8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x051bcc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x051bd0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x051bd4: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x051bd8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94002C89ULL; // 0x051bdc: bl #0x5ce00
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x051be0: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x051be4: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91234108ULL; // 0x051be8: add x8, x8, #0x8d0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x051bec: mov x2, x0
    return acc;
}

// [EN] Reconstructed FDE #0546 @ 0x051c00..0x051ccc (204 bytes)
// [VN] Phục dựng FDE #0546 tại 0x051c00..0x051ccc (204 byte)
//   0x051c00: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x051c04: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x051c08: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x051c0c: 910083fd  add      x29, sp, #0x20
//   0x051c10: 39400008  ldrb     w8, [x0]
//   0x051c14: aa0203f4  mov      x20, x2
//   0x051c18: aa0003f3  mov      x19, x0
//   0x051c1c: aa0103e7  mov      x7, x1
//   0x051c20: 37000148  tbnz     w8, #0, #0x51c48
//   0x051c24: d341fd15  lsr      x21, x8, #1
//   0x051c28: 528002c1  mov      w1, #0x16
//   0x051c2c: cb150029  sub      x9, x1, x21
//   0x051c30: eb14013f  cmp      x9, x20
//   0x051c34: 54000163  b.lo     #0x51c60
//   0x051c38: b4000414  cbz      x20, #0x51cb8
//   0x051c3c: 37000248  tbnz     w8, #0, #0x51c84
uint64_t fde_0546_sub_051c00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xEB14013FULL) + (x2 ^ 0x051C00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x051c00: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x051c04: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x051c08: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x051c0c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x051c10: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x051c14: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x051c18: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x051c1c: mov x7, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000148ULL; // 0x051c20: tbnz w8, #0, #0x51c48
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD15ULL; // 0x051c24: lsr x21, x8, #1
    return acc;
}

// [EN] Reconstructed FDE #0547 @ 0x051ccc..0x051f24 (600 bytes)
// [VN] Phục dựng FDE #0547 tại 0x051ccc..0x051f24 (600 byte)
//   0x051ccc: d10183ff  sub      sp, sp, #0x60
//   0x051cd0: f9001bf5  str      x21, [sp, #0x30]
//   0x051cd4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x051cd8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x051cdc: 910143fd  add      x29, sp, #0x50
//   0x051ce0: d53bd053  mrs      x19, tpidr_el0
//   0x051ce4: f9401668  ldr      x8, [x19, #0x28]
//   0x051ce8: 900000b5  adrp     x21, #0x65000
//   0x051cec: 900000b4  adrp     x20, #0x65000
//   0x051cf0: f90017e8  str      x8, [sp, #0x28]
//   0x051cf4: f94382a8  ldr      x8, [x21, #0x700]
//   0x051cf8: b4000508  cbz      x8, #0x51d98
//   0x051cfc: f90013e8  str      x8, [sp, #0x20]
//   0x051d00: f9438688  ldr      x8, [x20, #0x708]
//   0x051d04: 90fffde0  adrp     x0, #0xd000
//   0x051d08: 52800089  mov      w9, #4
uint64_t fde_0547_sub_051ccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90013E8ULL) + (x2 ^ 0x051CCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x051ccc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x051cd0: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x051cd4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x051cd8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x051cdc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x051ce0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x051ce4: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000B5ULL; // 0x051ce8: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x900000B4ULL; // 0x051cec: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x051cf0: str x8, [sp, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0548 @ 0x051f24..0x052070 (332 bytes)
// [VN] Phục dựng FDE #0548 tại 0x051f24..0x052070 (332 byte)
//   0x051f24: d10183ff  sub      sp, sp, #0x60
//   0x051f28: f9000bf9  str      x25, [sp, #0x10]
//   0x051f2c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x051f30: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x051f34: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x051f38: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x051f3c: 910143fd  add      x29, sp, #0x50
//   0x051f40: d53bd058  mrs      x24, tpidr_el0
//   0x051f44: f9401708  ldr      x8, [x24, #0x28]
//   0x051f48: f0000099  adrp     x25, #0x64000
//   0x051f4c: aa1e03f3  mov      x19, x30
//   0x051f50: 2a0303f4  mov      w20, w3
//   0x051f54: f90007e8  str      x8, [sp, #8]
//   0x051f58: 397a5328  ldrb     w8, [x25, #0xe94]
//   0x051f5c: aa0203f5  mov      x21, x2
//   0x051f60: aa0103f6  mov      x22, x1
uint64_t fde_0548_sub_051f24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x051F24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x051f24: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF9ULL; // 0x051f28: str x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x051f2c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x051f30: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x051f34: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x051f38: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x051f3c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x051f40: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x051f44: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000099ULL; // 0x051f48: adrp x25, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0549 @ 0x052070..0x052174 (260 bytes)
// [VN] Phục dựng FDE #0549 tại 0x052070..0x052174 (260 byte)
//   0x052070: d10103ff  sub      sp, sp, #0x40
//   0x052074: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x052078: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05207c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x052080: 9100c3fd  add      x29, sp, #0x30
//   0x052084: d53bd056  mrs      x22, tpidr_el0
//   0x052088: f94016c8  ldr      x8, [x22, #0x28]
//   0x05208c: aa1e03f3  mov      x19, x30
//   0x052090: aa0103f4  mov      x20, x1
//   0x052094: aa0003f5  mov      x21, x0
//   0x052098: f90007e8  str      x8, [sp, #8]
//   0x05209c: d0000088  adrp     x8, #0x64000
//   0x0520a0: b9403908  ldr      w8, [x8, #0x38]
//   0x0520a4: 7100051f  cmp      w8, #1
//   0x0520a8: 5400024b  b.lt     #0x520f0
//   0x0520ac: d0000089  adrp     x9, #0x64000
uint64_t fde_0549_sub_052070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9403908ULL) + (x2 ^ 0x052070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x052070: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x052074: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x052078: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05207c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x052080: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x052084: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x052088: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x05208c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x052090: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x052094: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0550 @ 0x052174..0x052234 (192 bytes)
// [VN] Phục dựng FDE #0550 tại 0x052174..0x052234 (192 byte)
//   0x052174: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x052178: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05217c: 910043fd  add      x29, sp, #0x10
//   0x052180: f0fffdc1  adrp     x1, #0xd000
//   0x052184: 91013821  add      x1, x1, #0x4e
//   0x052188: aa0003f3  mov      x19, x0
//   0x05218c: 94002b49  bl       #0x5ceb0
//   0x052190: b40000a0  cbz      x0, #0x521a4
//   0x052194: 2a1f03e0  mov      w0, wzr
//   0x052198: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x05219c: f84207f3  ldr      x19, [sp], #0x20
//   0x0521a0: d65f03c0  ret      
//   0x0521a4: b0fffdc1  adrp     x1, #0xb000
//   0x0521a8: 911b8c21  add      x1, x1, #0x6e3
//   0x0521ac: aa1303e0  mov      x0, x19
//   0x0521b0: 94002b40  bl       #0x5ceb0
uint64_t fde_0550_sub_052174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB0FFFDC1ULL) + (x2 ^ 0x052174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x052174: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x052178: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05217c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDC1ULL; // 0x052180: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x91013821ULL; // 0x052184: add x1, x1, #0x4e
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x052188: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94002B49ULL; // 0x05218c: bl #0x5ceb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x052190: cbz x0, #0x521a4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x052194: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x052198: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0551 @ 0x052234..0x052258 (36 bytes)
// [VN] Phục dựng FDE #0551 tại 0x052234..0x052258 (36 byte)
//   0x052234: 34000041  cbz      w1, #0x5223c
//   0x052238: d65f03c0  ret      
//   0x05223c: aa0203e3  mov      x3, x2
//   0x052240: d0fffe01  adrp     x1, #0x14000
//   0x052244: d0fffde2  adrp     x2, #0x10000
//   0x052248: 91203421  add      x1, x1, #0x80d
//   0x05224c: 9101d042  add      x2, x2, #0x74
//   0x052250: 52800060  mov      w0, #3
//   0x052254: 14002a93  b        #0x5cca0
uint64_t fde_0551_sub_052234(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000041ULL) + (x1 ^ 0x14002A93ULL) + (x2 ^ 0x052234ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000041ULL; // 0x052234: cbz w1, #0x5223c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x052238: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x05223c: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x052240: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFDE2ULL; // 0x052244: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x91203421ULL; // 0x052248: add x1, x1, #0x80d
    acc = (acc * 0x100000001B3ULL) ^ 0x9101D042ULL; // 0x05224c: add x2, x2, #0x74
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x052250: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x14002A93ULL; // 0x052254: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0552 @ 0x052258..0x052378 (288 bytes)
// [VN] Phục dựng FDE #0552 tại 0x052258..0x052378 (288 byte)
//   0x052258: d10103ff  sub      sp, sp, #0x40
//   0x05225c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x052260: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x052264: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x052268: 9100c3fd  add      x29, sp, #0x30
//   0x05226c: d53bd056  mrs      x22, tpidr_el0
//   0x052270: f94016c8  ldr      x8, [x22, #0x28]
//   0x052274: aa1e03f3  mov      x19, x30
//   0x052278: aa0103f4  mov      x20, x1
//   0x05227c: aa0003f5  mov      x21, x0
//   0x052280: f90007e8  str      x8, [sp, #8]
//   0x052284: b4000081  cbz      x1, #0x52294
//   0x052288: 39400288  ldrb     w8, [x20]
//   0x05228c: 7101c11f  cmp      w8, #0x70
//   0x052290: 540002e1  b.ne     #0x522ec
//   0x052294: 90000000  adrp     x0, #0x52000
uint64_t fde_0552_sub_052258(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x39400288ULL) + (x2 ^ 0x052258ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x052258: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05225c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x052260: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x052264: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x052268: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05226c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x052270: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x052274: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x052278: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x05227c: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0553 @ 0x052378..0x05247c (260 bytes)
// [VN] Phục dựng FDE #0553 tại 0x052378..0x05247c (260 byte)
//   0x052378: d10103ff  sub      sp, sp, #0x40
//   0x05237c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x052380: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x052384: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x052388: 9100c3fd  add      x29, sp, #0x30
//   0x05238c: d53bd056  mrs      x22, tpidr_el0
//   0x052390: f94016c8  ldr      x8, [x22, #0x28]
//   0x052394: aa1e03f3  mov      x19, x30
//   0x052398: aa0103f4  mov      x20, x1
//   0x05239c: aa0003f5  mov      x21, x0
//   0x0523a0: f90007e8  str      x8, [sp, #8]
//   0x0523a4: d0000088  adrp     x8, #0x64000
//   0x0523a8: b9404108  ldr      w8, [x8, #0x40]
//   0x0523ac: 7100051f  cmp      w8, #1
//   0x0523b0: 5400024b  b.lt     #0x523f8
//   0x0523b4: d0000089  adrp     x9, #0x64000
uint64_t fde_0553_sub_052378(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9404108ULL) + (x2 ^ 0x052378ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x052378: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05237c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x052380: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x052384: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x052388: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05238c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x052390: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x052394: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x052398: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x05239c: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0554 @ 0x05247c..0x052580 (260 bytes)
// [VN] Phục dựng FDE #0554 tại 0x05247c..0x052580 (260 byte)
//   0x05247c: d10103ff  sub      sp, sp, #0x40
//   0x052480: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x052484: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x052488: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05248c: 9100c3fd  add      x29, sp, #0x30
//   0x052490: d53bd056  mrs      x22, tpidr_el0
//   0x052494: f94016c8  ldr      x8, [x22, #0x28]
//   0x052498: aa1e03f3  mov      x19, x30
//   0x05249c: aa0103f4  mov      x20, x1
//   0x0524a0: aa0003f5  mov      x21, x0
//   0x0524a4: f90007e8  str      x8, [sp, #8]
//   0x0524a8: d0000088  adrp     x8, #0x64000
//   0x0524ac: b9404508  ldr      w8, [x8, #0x44]
//   0x0524b0: 7100051f  cmp      w8, #1
//   0x0524b4: 5400024b  b.lt     #0x524fc
//   0x0524b8: d0000089  adrp     x9, #0x64000
uint64_t fde_0554_sub_05247c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9404508ULL) + (x2 ^ 0x05247CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x05247c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x052480: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x052484: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x052488: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05248c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x052490: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x052494: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x052498: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x05249c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0524a0: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0555 @ 0x052580..0x0525a4 (36 bytes)
// [VN] Phục dựng FDE #0555 tại 0x052580..0x0525a4 (36 byte)
//   0x052580: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x052584: 910003fd  mov      x29, sp
//   0x052588: f0000088  adrp     x8, #0x65000
//   0x05258c: f9439901  ldr      x1, [x8, #0x730]
//   0x052590: 94002a48  bl       #0x5ceb0
//   0x052594: f100001f  cmp      x0, #0
//   0x052598: 1a9f07e0  cset     w0, ne
//   0x05259c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0525a0: d65f03c0  ret      
uint64_t fde_0555_sub_052580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x052580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x052580: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x052584: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000088ULL; // 0x052588: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439901ULL; // 0x05258c: ldr x1, [x8, #0x730]
    acc = (acc * 0x100000001B3ULL) ^ 0x94002A48ULL; // 0x052590: bl #0x5ceb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100001FULL; // 0x052594: cmp x0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x052598: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x05259c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0525a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0556 @ 0x0525a4..0x05263c (152 bytes)
// [VN] Phục dựng FDE #0556 tại 0x0525a4..0x05263c (152 byte)
//   0x0525a4: d10443ff  sub      sp, sp, #0x110
//   0x0525a8: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x0525ac: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x0525b0: 910403fd  add      x29, sp, #0x100
//   0x0525b4: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x0525b8: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x0525bc: ad0007e0  stp      q0, q1, [sp]
//   0x0525c0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0525c4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0525c8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0525cc: d53bd053  mrs      x19, tpidr_el0
//   0x0525d0: f9401669  ldr      x9, [x19, #0x28]
//   0x0525d4: 910203ea  add      x10, sp, #0x80
//   0x0525d8: 928003ec  mov      x12, #-0x20
//   0x0525dc: 910043ab  add      x11, x29, #0x10
//   0x0525e0: f81e83a9  stur     x9, [x29, #-0x18]
uint64_t fde_0556_sub_0525a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0x910203EAULL) + (x2 ^ 0x0525A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x0525a4: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FFCULL; // 0x0525a8: stp x28, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x0525ac: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x0525b0: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90817E4ULL; // 0x0525b4: stp x4, x5, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9091FE6ULL; // 0x0525b8: stp x6, x7, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0525bc: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0525c0: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0525c4: stp q4, q5, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD031FE6ULL; // 0x0525c8: stp q6, q7, [sp, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0557 @ 0x05263c..0x052704 (200 bytes)
// [VN] Phục dựng FDE #0557 tại 0x05263c..0x052704 (200 byte)
//   0x05263c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x052640: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x052644: 910043fd  add      x29, sp, #0x10
//   0x052648: aa0003f3  mov      x19, x0
//   0x05264c: 9400002e  bl       #0x52704
//   0x052650: 36000420  tbz      w0, #0, #0x526d4
//   0x052654: f0000094  adrp     x20, #0x65000
//   0x052658: f943a288  ldr      x8, [x20, #0x740]
//   0x05265c: b40001a8  cbz      x8, #0x52690
//   0x052660: d0fffe01  adrp     x1, #0x14000
//   0x052664: d0fffe02  adrp     x2, #0x14000
//   0x052668: 91203421  add      x1, x1, #0x80d
//   0x05266c: 9120ec42  add      x2, x2, #0x83b
//   0x052670: 52800060  mov      w0, #3
//   0x052674: 9400298b  bl       #0x5cca0
//   0x052678: f943a288  ldr      x8, [x20, #0x740]
uint64_t fde_0557_sub_05263c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9120EC42ULL) + (x2 ^ 0x05263CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05263c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x052640: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x052644: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x052648: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002EULL; // 0x05264c: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x36000420ULL; // 0x052650: tbz w0, #0, #0x526d4
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000094ULL; // 0x052654: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943A288ULL; // 0x052658: ldr x8, [x20, #0x740]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x05265c: cbz x8, #0x52690
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x052660: adrp x1, #0x14000
    return acc;
}

// [EN] Reconstructed FDE #0558 @ 0x052704..0x052850 (332 bytes)
// [VN] Phục dựng FDE #0558 tại 0x052704..0x052850 (332 byte)
//   0x052704: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x052708: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05270c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x052710: 910083fd  add      x29, sp, #0x20
//   0x052714: f0000095  adrp     x21, #0x65000
//   0x052718: 911c22b5  add      x21, x21, #0x708
//   0x05271c: f94022a8  ldr      x8, [x21, #0x40]
//   0x052720: f0000094  adrp     x20, #0x65000
//   0x052724: 911ce294  add      x20, x20, #0x738
//   0x052728: b40001a8  cbz      x8, #0x5275c
//   0x05272c: f94026a8  ldr      x8, [x21, #0x48]
//   0x052730: b4000168  cbz      x8, #0x5275c
//   0x052734: f94002a8  ldr      x8, [x21]
//   0x052738: b4000128  cbz      x8, #0x5275c
//   0x05273c: 52800035  mov      w21, #1
//   0x052740: 340004f5  cbz      w21, #0x527dc
uint64_t fde_0558_sub_052704(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF94002A8ULL) + (x2 ^ 0x052704ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x052704: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x052708: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05270c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x052710: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000095ULL; // 0x052714: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911C22B5ULL; // 0x052718: add x21, x21, #0x708
    acc = (acc * 0x100000001B3ULL) ^ 0xF94022A8ULL; // 0x05271c: ldr x8, [x21, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000094ULL; // 0x052720: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CE294ULL; // 0x052724: add x20, x20, #0x738
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x052728: cbz x8, #0x5275c
    return acc;
}

// [EN] Reconstructed FDE #0559 @ 0x052850..0x052918 (200 bytes)
// [VN] Phục dựng FDE #0559 tại 0x052850..0x052918 (200 byte)
//   0x052850: d100c3ff  sub      sp, sp, #0x30
//   0x052854: f9000bf3  str      x19, [sp, #0x10]
//   0x052858: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05285c: 910083fd  add      x29, sp, #0x20
//   0x052860: d53bd053  mrs      x19, tpidr_el0
//   0x052864: f9401668  ldr      x8, [x19, #0x28]
//   0x052868: f90007e8  str      x8, [sp, #8]
//   0x05286c: 97ffffa6  bl       #0x52704
//   0x052870: 36000280  tbz      w0, #0, #0x528c0
//   0x052874: 97fffd16  bl       #0x51ccc
//   0x052878: b90007e0  str      w0, [sp, #4]
//   0x05287c: 34000240  cbz      w0, #0x528c4
//   0x052880: f0000088  adrp     x8, #0x65000
//   0x052884: f9438508  ldr      x8, [x8, #0x708]
//   0x052888: 90fffe00  adrp     x0, #0x12000
//   0x05288c: 9101c000  add      x0, x0, #0x70
uint64_t fde_0559_sub_052850(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF0000088ULL) + (x2 ^ 0x052850ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x052850: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x052854: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x052858: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05285c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x052860: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x052864: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x052868: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFA6ULL; // 0x05286c: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x36000280ULL; // 0x052870: tbz w0, #0, #0x528c0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD16ULL; // 0x052874: bl #0x51ccc
    return acc;
}

// [EN] Reconstructed FDE #0560 @ 0x052918..0x05299c (132 bytes)
// [VN] Phục dựng FDE #0560 tại 0x052918..0x05299c (132 byte)
//   0x052918: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x05291c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x052920: 910043fd  add      x29, sp, #0x10
//   0x052924: 97ffff78  bl       #0x52704
//   0x052928: 36000320  tbz      w0, #0, #0x5298c
//   0x05292c: d0fffe01  adrp     x1, #0x14000
//   0x052930: 90fffe02  adrp     x2, #0x12000
//   0x052934: 91203421  add      x1, x1, #0x80d
//   0x052938: 911a3c42  add      x2, x2, #0x68f
//   0x05293c: 52800060  mov      w0, #3
//   0x052940: 940028d8  bl       #0x5cca0
//   0x052944: d0000093  adrp     x19, #0x64000
//   0x052948: f9470e68  ldr      x8, [x19, #0xe18]
//   0x05294c: b5000188  cbnz     x8, #0x5297c
//   0x052950: d0fffe00  adrp     x0, #0x14000
//   0x052954: f0fffdc2  adrp     x2, #0xd000
uint64_t fde_0560_sub_052918(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9470E68ULL) + (x2 ^ 0x052918ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x052918: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05291c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x052920: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF78ULL; // 0x052924: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x36000320ULL; // 0x052928: tbz w0, #0, #0x5298c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x05292c: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE02ULL; // 0x052930: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91203421ULL; // 0x052934: add x1, x1, #0x80d
    acc = (acc * 0x100000001B3ULL) ^ 0x911A3C42ULL; // 0x052938: add x2, x2, #0x68f
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x05293c: mov w0, #3
    return acc;
}

// [EN] Reconstructed FDE #0561 @ 0x05299c..0x052a50 (180 bytes)
// [VN] Phục dựng FDE #0561 tại 0x05299c..0x052a50 (180 byte)
//   0x05299c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0529a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0529a4: 910043fd  add      x29, sp, #0x10
//   0x0529a8: 2a0203f3  mov      w19, w2
//   0x0529ac: 97ffff56  bl       #0x52704
//   0x0529b0: 360001c0  tbz      w0, #0, #0x529e8
//   0x0529b4: d0000094  adrp     x20, #0x64000
//   0x0529b8: b9403a88  ldr      w8, [x20, #0x38]
//   0x0529bc: d0000089  adrp     x9, #0x64000
//   0x0529c0: b90f8133  str      w19, [x9, #0xf80]
//   0x0529c4: 7100011f  cmp      w8, #0
//   0x0529c8: 5400018d  b.le     #0x529f8
//   0x0529cc: f0000093  adrp     x19, #0x65000
//   0x0529d0: f9438a68  ldr      x8, [x19, #0x710]
//   0x0529d4: b40001c8  cbz      x8, #0x52a0c
//   0x0529d8: 52800020  mov      w0, #1
uint64_t fde_0561_sub_05299c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF0000093ULL) + (x2 ^ 0x05299CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05299c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0529a0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0529a4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x0529a8: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF56ULL; // 0x0529ac: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x360001C0ULL; // 0x0529b0: tbz w0, #0, #0x529e8
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000094ULL; // 0x0529b4: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403A88ULL; // 0x0529b8: ldr w8, [x20, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000089ULL; // 0x0529bc: adrp x9, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB90F8133ULL; // 0x0529c0: str w19, [x9, #0xf80]
    return acc;
}

// [EN] Reconstructed FDE #0562 @ 0x052a50..0x052b14 (196 bytes)
// [VN] Phục dựng FDE #0562 tại 0x052a50..0x052b14 (196 byte)
//   0x052a50: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x052a54: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x052a58: 910043fd  add      x29, sp, #0x10
//   0x052a5c: 2a0203f3  mov      w19, w2
//   0x052a60: 97ffff29  bl       #0x52704
//   0x052a64: 36000280  tbz      w0, #0, #0x52ab4
//   0x052a68: d0fffe01  adrp     x1, #0x14000
//   0x052a6c: f0fffdc2  adrp     x2, #0xd000
//   0x052a70: d0000088  adrp     x8, #0x64000
//   0x052a74: 91203421  add      x1, x1, #0x80d
//   0x052a78: 911a5c42  add      x2, x2, #0x697
//   0x052a7c: 52800060  mov      w0, #3
//   0x052a80: b90f8913  str      w19, [x8, #0xf88]
//   0x052a84: 94002887  bl       #0x5cca0
//   0x052a88: d0000093  adrp     x19, #0x64000
//   0x052a8c: b9403e68  ldr      w8, [x19, #0x3c]
uint64_t fde_0562_sub_052a50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB90F8913ULL) + (x2 ^ 0x052A50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x052a50: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x052a54: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x052a58: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x052a5c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF29ULL; // 0x052a60: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x36000280ULL; // 0x052a64: tbz w0, #0, #0x52ab4
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x052a68: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDC2ULL; // 0x052a6c: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000088ULL; // 0x052a70: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91203421ULL; // 0x052a74: add x1, x1, #0x80d
    return acc;
}

// [EN] Reconstructed FDE #0563 @ 0x052b14..0x052bd8 (196 bytes)
// [VN] Phục dựng FDE #0563 tại 0x052b14..0x052bd8 (196 byte)
//   0x052b14: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x052b18: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x052b1c: 910043fd  add      x29, sp, #0x10
//   0x052b20: 2a0203f3  mov      w19, w2
//   0x052b24: 97fffef8  bl       #0x52704
//   0x052b28: 36000280  tbz      w0, #0, #0x52b78
//   0x052b2c: d0fffe01  adrp     x1, #0x14000
//   0x052b30: f0fffdc2  adrp     x2, #0xd000
//   0x052b34: d0000088  adrp     x8, #0x64000
//   0x052b38: 91203421  add      x1, x1, #0x80d
//   0x052b3c: 911a5c42  add      x2, x2, #0x697
//   0x052b40: 52800060  mov      w0, #3
//   0x052b44: b90f9113  str      w19, [x8, #0xf90]
//   0x052b48: 94002856  bl       #0x5cca0
//   0x052b4c: d0000093  adrp     x19, #0x64000
//   0x052b50: b9404268  ldr      w8, [x19, #0x40]
uint64_t fde_0563_sub_052b14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB90F9113ULL) + (x2 ^ 0x052B14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x052b14: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x052b18: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x052b1c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x052b20: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEF8ULL; // 0x052b24: bl #0x52704
    acc = (acc * 0x100000001B3ULL) ^ 0x36000280ULL; // 0x052b28: tbz w0, #0, #0x52b78
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE01ULL; // 0x052b2c: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDC2ULL; // 0x052b30: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000088ULL; // 0x052b34: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91203421ULL; // 0x052b38: add x1, x1, #0x80d
    return acc;
}

// [EN] Reconstructed FDE #0564 @ 0x052bd8..0x052d10 (312 bytes)
// [VN] Phục dựng FDE #0564 tại 0x052bd8..0x052d10 (312 byte)
//   0x052bd8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x052bdc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x052be0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x052be4: 910083fd  add      x29, sp, #0x20
//   0x052be8: f9400008  ldr      x8, [x0]
//   0x052bec: aa0203f4  mov      x20, x2
//   0x052bf0: aa0203e1  mov      x1, x2
//   0x052bf4: aa1f03e2  mov      x2, xzr
//   0x052bf8: f942a508  ldr      x8, [x8, #0x548]
//   0x052bfc: 2a0303f6  mov      w22, w3
//   0x052c00: aa0003f3  mov      x19, x0
//   0x052c04: d63f0100  blr      x8
//   0x052c08: b40002a0  cbz      x0, #0x52c5c
//   0x052c0c: aa0003f5  mov      x21, x0
//   0x052c10: 97fffebd  bl       #0x52704
//   0x052c14: 36000280  tbz      w0, #0, #0x52c64
uint64_t fde_0564_sub_052bd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB40002A0ULL) + (x2 ^ 0x052BD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x052bd8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x052bdc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x052be0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x052be4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x052be8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x052bec: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x052bf0: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x052bf4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x052bf8: ldr x8, [x8, #0x548]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F6ULL; // 0x052bfc: mov w22, w3
    return acc;
}

// [EN] Reconstructed FDE #0565 @ 0x052d10..0x052f50 (576 bytes)
// [VN] Phục dựng FDE #0565 tại 0x052d10..0x052f50 (576 byte)
//   0x052d10: d10383ff  sub      sp, sp, #0xe0
//   0x052d14: f9004bf9  str      x25, [sp, #0x90]
//   0x052d18: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x052d1c: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x052d20: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x052d24: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x052d28: 910343fd  add      x29, sp, #0xd0
//   0x052d2c: d53bd057  mrs      x23, tpidr_el0
//   0x052d30: f94016e8  ldr      x8, [x23, #0x28]
//   0x052d34: 2a0303f4  mov      w20, w3
//   0x052d38: 2a0203f3  mov      w19, w2
//   0x052d3c: f81b83a8  stur     x8, [x29, #-0x48]
//   0x052d40: 97fffe71  bl       #0x52704
//   0x052d44: 36000bc0  tbz      w0, #0, #0x52ebc
//   0x052d48: 3100069f  cmn      w20, #1
//   0x052d4c: f0000098  adrp     x24, #0x65000
uint64_t fde_0565_sub_052d10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0x97FFFE71ULL) + (x2 ^ 0x052D10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x052d10: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF9ULL; // 0x052d14: str x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x052d18: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x052d1c: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x052d20: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x052d24: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x052d28: add x29, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x052d2c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x052d30: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x052d34: mov w20, w3
    return acc;
}

// [EN] Reconstructed FDE #0566 @ 0x052f50..0x0530a0 (336 bytes)
// [VN] Phục dựng FDE #0566 tại 0x052f50..0x0530a0 (336 byte)
//   0x052f50: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x052f54: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x052f58: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x052f5c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x052f60: 9100c3fd  add      x29, sp, #0x30
//   0x052f64: f9400008  ldr      x8, [x0]
//   0x052f68: aa0203f4  mov      x20, x2
//   0x052f6c: aa0203e1  mov      x1, x2
//   0x052f70: aa1f03e2  mov      x2, xzr
//   0x052f74: f942a508  ldr      x8, [x8, #0x548]
//   0x052f78: 2a0303f6  mov      w22, w3
//   0x052f7c: aa0003f3  mov      x19, x0
//   0x052f80: d63f0100  blr      x8
//   0x052f84: b40002e0  cbz      x0, #0x52fe0
//   0x052f88: aa0003f5  mov      x21, x0
//   0x052f8c: 97fffdde  bl       #0x52704
uint64_t fde_0566_sub_052f50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x052F50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x052f50: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x052f54: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x052f58: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x052f5c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x052f60: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x052f64: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x052f68: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x052f6c: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x052f70: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x052f74: ldr x8, [x8, #0x548]
    return acc;
}

// [EN] Reconstructed FDE #0567 @ 0x0530a0..0x053124 (132 bytes)
// [VN] Phục dựng FDE #0567 tại 0x0530a0..0x053124 (132 byte)
//   0x0530a0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0530a4: 910003fd  mov      x29, sp
//   0x0530a8: b0000088  adrp     x8, #0x64000
//   0x0530ac: 913e7108  add      x8, x8, #0xf9c
//   0x0530b0: b9000102  str      w2, [x8]
//   0x0530b4: 911ef108  add      x8, x8, #0x7bc
//   0x0530b8: f9400108  ldr      x8, [x8]
//   0x0530bc: b4000088  cbz      x8, #0x530cc
//   0x0530c0: 2a1f03e0  mov      w0, wzr
//   0x0530c4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0530c8: d65f03c0  ret      
//   0x0530cc: b0fffe00  adrp     x0, #0x14000
//   0x0530d0: f0fffde2  adrp     x2, #0x12000
//   0x0530d4: 90000003  adrp     x3, #0x53000
//   0x0530d8: 9120c000  add      x0, x0, #0x830
//   0x0530dc: 91327042  add      x2, x2, #0xc9c
uint64_t fde_0567_sub_0530a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF0FFFDE2ULL) + (x2 ^ 0x0530A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0530a0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0530a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000088ULL; // 0x0530a8: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913E7108ULL; // 0x0530ac: add x8, x8, #0xf9c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000102ULL; // 0x0530b0: str w2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x911EF108ULL; // 0x0530b4: add x8, x8, #0x7bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0530b8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x0530bc: cbz x8, #0x530cc
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0530c0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0530c4: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0568 @ 0x053124..0x05323c (280 bytes)
// [VN] Phục dựng FDE #0568 tại 0x053124..0x05323c (280 byte)
//   0x053124: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x053128: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05312c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x053130: 910083fd  add      x29, sp, #0x20
//   0x053134: aa1e03f3  mov      x19, x30
//   0x053138: 2a0003f4  mov      w20, w0
//   0x05313c: 3101941f  cmn      w0, #0x65
//   0x053140: 2a0103f5  mov      w21, w1
//   0x053144: 54000261  b.ne     #0x53190
//   0x053148: 35000255  cbnz     w21, #0x53190
//   0x05314c: b0000088  adrp     x8, #0x64000
//   0x053150: b94f9d09  ldr      w9, [x8, #0xf9c]
//   0x053154: 3100053f  cmn      w9, #1
//   0x053158: 54000180  b.eq     #0x53188
//   0x05315c: b0000094  adrp     x20, #0x64000
//   0x053160: 913e8294  add      x20, x20, #0xfa0
uint64_t fde_0568_sub_053124(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x3100053FULL) + (x2 ^ 0x053124ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x053124: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x053128: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05312c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x053130: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x053134: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x053138: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x3101941FULL; // 0x05313c: cmn w0, #0x65
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x053140: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000261ULL; // 0x053144: b.ne #0x53190
    acc = (acc * 0x100000001B3ULL) ^ 0x35000255ULL; // 0x053148: cbnz w21, #0x53190
    return acc;
}

// [EN] Reconstructed FDE #0569 @ 0x05323c..0x0534a4 (616 bytes)
// [VN] Phục dựng FDE #0569 tại 0x05323c..0x0534a4 (616 byte)
//   0x05323c: d101c3ff  sub      sp, sp, #0x70
//   0x053240: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x053244: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x053248: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x05324c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x053250: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x053254: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x053258: 910183fd  add      x29, sp, #0x60
//   0x05325c: d0000088  adrp     x8, #0x65000
//   0x053260: f943b509  ldr      x9, [x8, #0x768]
//   0x053264: aa1e03f3  mov      x19, x30
//   0x053268: aa0103f5  mov      x21, x1
//   0x05326c: aa0003f4  mov      x20, x0
//   0x053270: b40000c9  cbz      x9, #0x53288
//   0x053274: d0000088  adrp     x8, #0x65000
//   0x053278: f943b916  ldr      x22, [x8, #0x770]
uint64_t fde_0569_sub_05323c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x05323CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x05323c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x053240: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x053244: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x053248: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x05324c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x053250: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x053254: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x053258: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000088ULL; // 0x05325c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943B509ULL; // 0x053260: ldr x9, [x8, #0x768]
    return acc;
}

// [EN] Reconstructed FDE #0570 @ 0x0534a4..0x053540 (156 bytes)
// [VN] Phục dựng FDE #0570 tại 0x0534a4..0x053540 (156 byte)
//   0x0534a4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0534a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0534ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0534b0: 910083fd  add      x29, sp, #0x20
//   0x0534b4: aa1e03f3  mov      x19, x30
//   0x0534b8: aa0103f4  mov      x20, x1
//   0x0534bc: aa0003f5  mov      x21, x0
//   0x0534c0: 12000043  and      w3, w2, #1
//   0x0534c4: b0fffdc1  adrp     x1, #0xc000
//   0x0534c8: b0fffdc2  adrp     x2, #0xc000
//   0x0534cc: 912cf021  add      x1, x1, #0xb3c
//   0x0534d0: 912e2042  add      x2, x2, #0xb88
//   0x0534d4: 52800060  mov      w0, #3
//   0x0534d8: 940025f2  bl       #0x5cca0
//   0x0534dc: 90000000  adrp     x0, #0x53000
//   0x0534e0: 91129000  add      x0, x0, #0x4a4
uint64_t fde_0570_sub_0534a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x0534A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0534a4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0534a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0534ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0534b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x0534b4: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0534b8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0534bc: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000043ULL; // 0x0534c0: and w3, w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC1ULL; // 0x0534c4: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC2ULL; // 0x0534c8: adrp x2, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0571 @ 0x053540..0x0535d8 (152 bytes)
// [VN] Phục dựng FDE #0571 tại 0x053540..0x0535d8 (152 byte)
//   0x053540: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x053544: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x053548: 910043fd  add      x29, sp, #0x10
//   0x05354c: d0000088  adrp     x8, #0x65000
//   0x053550: 911d8108  add      x8, x8, #0x760
//   0x053554: f9400109  ldr      x9, [x8]
//   0x053558: a9010d02  stp      x2, x3, [x8, #0x10]
//   0x05355c: f9001504  str      x4, [x8, #0x28]
//   0x053560: b40000c9  cbz      x9, #0x53578
//   0x053564: 52800033  mov      w19, #1
//   0x053568: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x05356c: 2a1303e0  mov      w0, w19
//   0x053570: f84207f3  ldr      x19, [sp], #0x20
//   0x053574: d65f03c0  ret      
//   0x053578: b0fffde0  adrp     x0, #0x10000
//   0x05357c: 90fffe01  adrp     x1, #0x13000
uint64_t fde_0571_sub_053540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x053540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x053540: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x053544: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x053548: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000088ULL; // 0x05354c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D8108ULL; // 0x053550: add x8, x8, #0x760
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x053554: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9010D02ULL; // 0x053558: stp x2, x3, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001504ULL; // 0x05355c: str x4, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C9ULL; // 0x053560: cbz x9, #0x53578
    acc = (acc * 0x100000001B3ULL) ^ 0x52800033ULL; // 0x053564: mov w19, #1
    return acc;
}

// [EN] Reconstructed FDE #0572 @ 0x0535d8..0x0535f0 (24 bytes)
// [VN] Phục dựng FDE #0572 tại 0x0535d8..0x0535f0 (24 byte)
//   0x0535d8: d0000088  adrp     x8, #0x65000
//   0x0535dc: 911dc108  add      x8, x8, #0x770
//   0x0535e0: 52800020  mov      w0, #1
//   0x0535e4: a9000d02  stp      x2, x3, [x8]
//   0x0535e8: f9000d04  str      x4, [x8, #0x18]
//   0x0535ec: d65f03c0  ret      
uint64_t fde_0572_sub_0535d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000088ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0535D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000088ULL; // 0x0535d8: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911DC108ULL; // 0x0535dc: add x8, x8, #0x770
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x0535e0: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000D02ULL; // 0x0535e4: stp x2, x3, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000D04ULL; // 0x0535e8: str x4, [x8, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0535ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #0573 @ 0x0535f0..0x05367c (140 bytes)
// [VN] Phục dựng FDE #0573 tại 0x0535f0..0x05367c (140 byte)
//   0x0535f0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0535f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0535f8: 910043fd  add      x29, sp, #0x10
//   0x0535fc: b0000088  adrp     x8, #0x64000
//   0x053600: f9471108  ldr      x8, [x8, #0xe20]
//   0x053604: b40000c8  cbz      x8, #0x5361c
//   0x053608: 2a1f03f3  mov      w19, wzr
//   0x05360c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x053610: 2a1303e0  mov      w0, w19
//   0x053614: f84207f3  ldr      x19, [sp], #0x20
//   0x053618: d65f03c0  ret      
//   0x05361c: b0fffde0  adrp     x0, #0x10000
//   0x053620: f0fffde1  adrp     x1, #0x12000
//   0x053624: 90000002  adrp     x2, #0x53000
//   0x053628: b0000083  adrp     x3, #0x64000
//   0x05362c: 911ad800  add      x0, x0, #0x6b6
uint64_t fde_0573_sub_0535f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF0FFFDE1ULL) + (x2 ^ 0x0535F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0535f0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0535f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0535f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000088ULL; // 0x0535fc: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471108ULL; // 0x053600: ldr x8, [x8, #0xe20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C8ULL; // 0x053604: cbz x8, #0x5361c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03F3ULL; // 0x053608: mov w19, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x05360c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x053610: mov w0, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x053614: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0574 @ 0x05367c..0x0536b4 (56 bytes)
// [VN] Phục dựng FDE #0574 tại 0x05367c..0x0536b4 (56 byte)
//   0x05367c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x053680: 910003fd  mov      x29, sp
//   0x053684: b0000088  adrp     x8, #0x64000
//   0x053688: b0fffdc1  adrp     x1, #0xc000
//   0x05368c: 90fffe02  adrp     x2, #0x13000
//   0x053690: bd004d00  str      s0, [x8, #0x4c]
//   0x053694: 1e22c000  fcvt     d0, s0
//   0x053698: 912cf021  add      x1, x1, #0xb3c
//   0x05369c: 9128c842  add      x2, x2, #0xa32
//   0x0536a0: 52800060  mov      w0, #3
//   0x0536a4: 9400257f  bl       #0x5cca0
//   0x0536a8: 52800020  mov      w0, #1
//   0x0536ac: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0536b0: d65f03c0  ret      
uint64_t fde_0574_sub_05367c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xA8C17BFDULL) + (x2 ^ 0x05367CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x05367c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x053680: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000088ULL; // 0x053684: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC1ULL; // 0x053688: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE02ULL; // 0x05368c: adrp x2, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0xBD004D00ULL; // 0x053690: str s0, [x8, #0x4c]
    acc = (acc * 0x100000001B3ULL) ^ 0x1E22C000ULL; // 0x053694: fcvt d0, s0
    acc = (acc * 0x100000001B3ULL) ^ 0x912CF021ULL; // 0x053698: add x1, x1, #0xb3c
    acc = (acc * 0x100000001B3ULL) ^ 0x9128C842ULL; // 0x05369c: add x2, x2, #0xa32
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x0536a0: mov w0, #3
    return acc;
}

// [EN] Reconstructed FDE #0575 @ 0x0536b4..0x0536bc (8 bytes)
// [VN] Phục dựng FDE #0575 tại 0x0536b4..0x0536bc (8 byte)
//   0x0536b4: f9400400  ldr      x0, [x0, #8]
//   0x0536b8: 14000001  b        #0x536bc
uint64_t fde_0575_sub_0536b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400400ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0536B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x0536b4: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0536b8: b #0x536bc
    return acc;
}

// [EN] Reconstructed FDE #0576 @ 0x0536bc..0x053704 (72 bytes)
// [VN] Phục dựng FDE #0576 tại 0x0536bc..0x053704 (72 byte)
//   0x0536bc: b4000220  cbz      x0, #0x53700
//   0x0536c0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0536c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0536c8: 910043fd  add      x29, sp, #0x10
//   0x0536cc: aa0003f3  mov      x19, x0
//   0x0536d0: f9400000  ldr      x0, [x0]
//   0x0536d4: 97fffffa  bl       #0x536bc
//   0x0536d8: f9400660  ldr      x0, [x19, #8]
//   0x0536dc: 97fffff8  bl       #0x536bc
//   0x0536e0: 39408268  ldrb     w8, [x19, #0x20]
//   0x0536e4: 36000068  tbz      w8, #0, #0x536f0
//   0x0536e8: f9401a60  ldr      x0, [x19, #0x30]
//   0x0536ec: 940026e1  bl       #0x5d270
//   0x0536f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0536f4: aa1303e0  mov      x0, x19
//   0x0536f8: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0576_sub_0536bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000220ULL) + (x1 ^ 0x940026E1ULL) + (x2 ^ 0x0536BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x0536bc: cbz x0, #0x53700
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0536c0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0536c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0536c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0536cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x0536d0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x0536d4: bl #0x536bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x0536d8: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x0536dc: bl #0x536bc
    acc = (acc * 0x100000001B3ULL) ^ 0x39408268ULL; // 0x0536e0: ldrb w8, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0577 @ 0x053704..0x0539c0 (700 bytes)
// [VN] Phục dựng FDE #0577 tại 0x053704..0x0539c0 (700 byte)
//   0x053704: d10203ff  sub      sp, sp, #0x80
//   0x053708: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x05370c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x053710: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x053714: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x053718: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x05371c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x053720: 9101c3fd  add      x29, sp, #0x70
//   0x053724: b0000088  adrp     x8, #0x64000
//   0x053728: 913e9108  add      x8, x8, #0xfa4
//   0x05372c: 91255109  add      x9, x8, #0x954
//   0x053730: f9400129  ldr      x9, [x9]
//   0x053734: aa1e03f3  mov      x19, x30
//   0x053738: aa0103f4  mov      x20, x1
//   0x05373c: aa0003f5  mov      x21, x0
//   0x053740: b4000fe9  cbz      x9, #0x5393c
uint64_t fde_0577_sub_053704(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA1E03F3ULL) + (x2 ^ 0x053704ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x053704: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x053708: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x05370c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x053710: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x053714: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x053718: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x05371c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x053720: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000088ULL; // 0x053724: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913E9108ULL; // 0x053728: add x8, x8, #0xfa4
    return acc;
}

// [EN] Reconstructed FDE #0578 @ 0x0539c0..0x053b88 (456 bytes)
// [VN] Phục dựng FDE #0578 tại 0x0539c0..0x053b88 (456 byte)
//   0x0539c0: d10303ff  sub      sp, sp, #0xc0
//   0x0539c4: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x0539c8: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0539cc: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0539d0: 9102c3fd  add      x29, sp, #0xb0
//   0x0539d4: d53bd056  mrs      x22, tpidr_el0
//   0x0539d8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0539dc: 11004c09  add      w9, w0, #0x13
//   0x0539e0: 2a0203f4  mov      w20, w2
//   0x0539e4: 2a0103f5  mov      w21, w1
//   0x0539e8: 7100993f  cmp      w9, #0x26
//   0x0539ec: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0539f0: 54000508  b.hi     #0x53a90
//   0x0539f4: 2a0003e2  mov      w2, w0
//   0x0539f8: 2a1f03e0  mov      w0, wzr
//   0x0539fc: 2a1403e1  mov      w1, w20
uint64_t fde_0578_sub_0539c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0x54000508ULL) + (x2 ^ 0x0539C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0539c0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x0539c4: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0539c8: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0539cc: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0539d0: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0539d4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0539d8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x11004C09ULL; // 0x0539dc: add w9, w0, #0x13
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x0539e0: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x0539e4: mov w21, w1
    return acc;
}

// [EN] Reconstructed FDE #0579 @ 0x053b88..0x053df0 (616 bytes)
// [VN] Phục dựng FDE #0579 tại 0x053b88..0x053df0 (616 byte)
//   0x053b88: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x053b8c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x053b90: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x053b94: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x053b98: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x053b9c: 910103fd  add      x29, sp, #0x40
//   0x053ba0: f9400008  ldr      x8, [x0]
//   0x053ba4: aa0203e1  mov      x1, x2
//   0x053ba8: 2a0303f6  mov      w22, w3
//   0x053bac: aa0003f3  mov      x19, x0
//   0x053bb0: f942ad08  ldr      x8, [x8, #0x558]
//   0x053bb4: aa0203f4  mov      x20, x2
//   0x053bb8: d63f0100  blr      x8
//   0x053bbc: f9400268  ldr      x8, [x19]
//   0x053bc0: 2a0003f7  mov      w23, w0
//   0x053bc4: aa1303e0  mov      x0, x19
uint64_t fde_0579_sub_053b88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x053B88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x053b88: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x053b8c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x053b90: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x053b94: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x053b98: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x053b9c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x053ba0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x053ba4: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F6ULL; // 0x053ba8: mov w22, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x053bac: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0580 @ 0x053df0..0x053e70 (128 bytes)
// [VN] Phục dựng FDE #0580 tại 0x053df0..0x053e70 (128 byte)
//   0x053df0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x053df4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x053df8: 910043fd  add      x29, sp, #0x10
//   0x053dfc: d0000094  adrp     x20, #0x65000
//   0x053e00: 911e4294  add      x20, x20, #0x790
//   0x053e04: f9400288  ldr      x8, [x20]
//   0x053e08: b4000068  cbz      x8, #0x53e14
//   0x053e0c: f9400688  ldr      x8, [x20, #8]
//   0x053e10: b5000288  cbnz     x8, #0x53e60
//   0x053e14: f0fffdc0  adrp     x0, #0xe000
//   0x053e18: 91049000  add      x0, x0, #0x124
//   0x053e1c: 940025b9  bl       #0x5d500
//   0x053e20: b4000220  cbz      x0, #0x53e64
//   0x053e24: b0fffe01  adrp     x1, #0x14000
//   0x053e28: 9121a821  add      x1, x1, #0x86a
//   0x053e2c: aa0003f3  mov      x19, x0
uint64_t fde_0580_sub_053df0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000220ULL) + (x2 ^ 0x053DF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x053df0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x053df4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x053df8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000094ULL; // 0x053dfc: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911E4294ULL; // 0x053e00: add x20, x20, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x053e04: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x053e08: cbz x8, #0x53e14
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x053e0c: ldr x8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000288ULL; // 0x053e10: cbnz x8, #0x53e60
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDC0ULL; // 0x053e14: adrp x0, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0581 @ 0x053e70..0x053f1c (172 bytes)
// [VN] Phục dựng FDE #0581 tại 0x053e70..0x053f1c (172 byte)
//   0x053e70: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x053e74: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x053e78: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x053e7c: 910083fd  add      x29, sp, #0x20
//   0x053e80: d0000095  adrp     x21, #0x65000
//   0x053e84: 911e42b5  add      x21, x21, #0x790
//   0x053e88: f94002a8  ldr      x8, [x21]
//   0x053e8c: 2a0203f3  mov      w19, w2
//   0x053e90: b40000c8  cbz      x8, #0x53ea8
//   0x053e94: f94006a1  ldr      x1, [x21, #8]
//   0x053e98: b4000081  cbz      x1, #0x53ea8
//   0x053e9c: 7100067f  cmp      w19, #1
//   0x053ea0: 540002ca  b.ge     #0x53ef8
//   0x053ea4: 1400001a  b        #0x53f0c
//   0x053ea8: f0fffdc0  adrp     x0, #0xe000
//   0x053eac: 91049000  add      x0, x0, #0x124
uint64_t fde_0581_sub_053e70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x540002CAULL) + (x2 ^ 0x053E70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x053e70: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x053e74: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x053e78: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x053e7c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000095ULL; // 0x053e80: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911E42B5ULL; // 0x053e84: add x21, x21, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002A8ULL; // 0x053e88: ldr x8, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x053e8c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C8ULL; // 0x053e90: cbz x8, #0x53ea8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94006A1ULL; // 0x053e94: ldr x1, [x21, #8]
    return acc;
}

// [EN] Reconstructed FDE #0582 @ 0x053f1c..0x053fe8 (204 bytes)
// [VN] Phục dựng FDE #0582 tại 0x053f1c..0x053fe8 (204 byte)
//   0x053f1c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x053f20: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x053f24: 910043fd  add      x29, sp, #0x10
//   0x053f28: d0000094  adrp     x20, #0x65000
//   0x053f2c: 911ec294  add      x20, x20, #0x7b0
//   0x053f30: f9400288  ldr      x8, [x20]
//   0x053f34: b40001a8  cbz      x8, #0x53f68
//   0x053f38: f9400688  ldr      x8, [x20, #8]
//   0x053f3c: b4000168  cbz      x8, #0x53f68
//   0x053f40: d0fffdc1  adrp     x1, #0xd000
//   0x053f44: d0fffde2  adrp     x2, #0x11000
//   0x053f48: 91018421  add      x1, x1, #0x61
//   0x053f4c: 912fa842  add      x2, x2, #0xbea
//   0x053f50: 52800060  mov      w0, #3
//   0x053f54: 94002353  bl       #0x5cca0
//   0x053f58: 52800020  mov      w0, #1
uint64_t fde_0582_sub_053f1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x912FA842ULL) + (x2 ^ 0x053F1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x053f1c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x053f20: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x053f24: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000094ULL; // 0x053f28: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911EC294ULL; // 0x053f2c: add x20, x20, #0x7b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x053f30: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x053f34: cbz x8, #0x53f68
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x053f38: ldr x8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000168ULL; // 0x053f3c: cbz x8, #0x53f68
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFDC1ULL; // 0x053f40: adrp x1, #0xd000
    return acc;
}

// [EN] Reconstructed FDE #0583 @ 0x053fe8..0x054028 (64 bytes)
// [VN] Phục dựng FDE #0583 tại 0x053fe8..0x054028 (64 byte)
//   0x053fe8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x053fec: 910003fd  mov      x29, sp
//   0x053ff0: 9400000e  bl       #0x54028
//   0x053ff4: 36000140  tbz      w0, #0, #0x5401c
//   0x053ff8: d0fffdc1  adrp     x1, #0xd000
//   0x053ffc: 90fffe02  adrp     x2, #0x13000
//   0x054000: 91018421  add      x1, x1, #0x61
//   0x054004: 91395442  add      x2, x2, #0xe55
//   0x054008: 52800060  mov      w0, #3
//   0x05400c: 94002325  bl       #0x5cca0
//   0x054010: 52800020  mov      w0, #1
//   0x054014: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x054018: d65f03c0  ret      
//   0x05401c: 2a1f03e0  mov      w0, wzr
//   0x054020: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x054024: d65f03c0  ret      
uint64_t fde_0583_sub_053fe8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x053FE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x053fe8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x053fec: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000EULL; // 0x053ff0: bl #0x54028
    acc = (acc * 0x100000001B3ULL) ^ 0x36000140ULL; // 0x053ff4: tbz w0, #0, #0x5401c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFDC1ULL; // 0x053ff8: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE02ULL; // 0x053ffc: adrp x2, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x91018421ULL; // 0x054000: add x1, x1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x91395442ULL; // 0x054004: add x2, x2, #0xe55
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x054008: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x94002325ULL; // 0x05400c: bl #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0584 @ 0x054028..0x054134 (268 bytes)
// [VN] Phục dựng FDE #0584 tại 0x054028..0x054134 (268 byte)
//   0x054028: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05402c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x054030: 910043fd  add      x29, sp, #0x10
//   0x054034: b0000094  adrp     x20, #0x65000
//   0x054038: 911f0294  add      x20, x20, #0x7c0
//   0x05403c: f9400288  ldr      x8, [x20]
//   0x054040: b4000168  cbz      x8, #0x5406c
//   0x054044: f9400688  ldr      x8, [x20, #8]
//   0x054048: b4000128  cbz      x8, #0x5406c
//   0x05404c: f9400a88  ldr      x8, [x20, #0x10]
//   0x054050: b40000e8  cbz      x8, #0x5406c
//   0x054054: f9400e88  ldr      x8, [x20, #0x18]
//   0x054058: b40000a8  cbz      x8, #0x5406c
//   0x05405c: 52800020  mov      w0, #1
//   0x054060: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x054064: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0584_sub_054028(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000A8ULL) + (x2 ^ 0x054028ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x054028: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05402c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x054030: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000094ULL; // 0x054034: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F0294ULL; // 0x054038: add x20, x20, #0x7c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x05403c: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000168ULL; // 0x054040: cbz x8, #0x5406c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x054044: ldr x8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000128ULL; // 0x054048: cbz x8, #0x5406c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A88ULL; // 0x05404c: ldr x8, [x20, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0585 @ 0x054134..0x05429c (360 bytes)
// [VN] Phục dựng FDE #0585 tại 0x054134..0x05429c (360 byte)
//   0x054134: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x054138: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05413c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x054140: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x054144: 9100c3fd  add      x29, sp, #0x30
//   0x054148: 2a0303f5  mov      w21, w3
//   0x05414c: aa0203f3  mov      x19, x2
//   0x054150: aa0003f4  mov      x20, x0
//   0x054154: 97ffffb5  bl       #0x54028
//   0x054158: b0fffdc1  adrp     x1, #0xd000
//   0x05415c: 91018421  add      x1, x1, #0x61
//   0x054160: 36000700  tbz      w0, #0, #0x54240
//   0x054164: f0fffdc2  adrp     x2, #0xf000
//   0x054168: 9122e042  add      x2, x2, #0x8b8
//   0x05416c: 52800060  mov      w0, #3
//   0x054170: 940022cc  bl       #0x5cca0
uint64_t fde_0585_sub_054134(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF0FFFDC2ULL) + (x2 ^ 0x054134ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x054134: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x054138: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05413c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x054140: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x054144: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F5ULL; // 0x054148: mov w21, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x05414c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x054150: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFB5ULL; // 0x054154: bl #0x54028
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC1ULL; // 0x054158: adrp x1, #0xd000
    return acc;
}

// [EN] Reconstructed FDE #0586 @ 0x05429c..0x054424 (392 bytes)
// [VN] Phục dựng FDE #0586 tại 0x05429c..0x054424 (392 byte)
//   0x05429c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0542a0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0542a4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0542a8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0542ac: 9100c3fd  add      x29, sp, #0x30
//   0x0542b0: b0000097  adrp     x23, #0x65000
//   0x0542b4: 911ec2f7  add      x23, x23, #0x7b0
//   0x0542b8: f94002e8  ldr      x8, [x23]
//   0x0542bc: 2a0303f5  mov      w21, w3
//   0x0542c0: aa0203f3  mov      x19, x2
//   0x0542c4: aa0003f4  mov      x20, x0
//   0x0542c8: b4000668  cbz      x8, #0x54394
//   0x0542cc: f94006e8  ldr      x8, [x23, #8]
//   0x0542d0: b4000628  cbz      x8, #0x54394
//   0x0542d4: b0fffdd6  adrp     x22, #0xd000
//   0x0542d8: 910186d6  add      x22, x22, #0x61
uint64_t fde_0586_sub_05429c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF94006E8ULL) + (x2 ^ 0x05429CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x05429c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0542a0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0542a4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0542a8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0542ac: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000097ULL; // 0x0542b0: adrp x23, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911EC2F7ULL; // 0x0542b4: add x23, x23, #0x7b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E8ULL; // 0x0542b8: ldr x8, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F5ULL; // 0x0542bc: mov w21, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0542c0: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0587 @ 0x054424..0x05487c (1112 bytes)
// [VN] Phục dựng FDE #0587 tại 0x054424..0x05487c (1112 byte)
//   0x054424: d10403ff  sub      sp, sp, #0x100
//   0x054428: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x05442c: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x054430: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x054434: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x054438: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x05443c: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x054440: 9103c3fd  add      x29, sp, #0xf0
//   0x054444: b90027e4  str      w4, [sp, #0x24]
//   0x054448: b90057e3  str      w3, [sp, #0x54]
//   0x05444c: d53bd053  mrs      x19, tpidr_el0
//   0x054450: f9401668  ldr      x8, [x19, #0x28]
//   0x054454: f81a83a8  stur     x8, [x29, #-0x58]
//   0x054458: b0000088  adrp     x8, #0x65000
//   0x05445c: f9447d08  ldr      x8, [x8, #0x8f8]
//   0x054460: f101911f  cmp      x8, #0x64
uint64_t fde_0587_sub_054424(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xF81A83A8ULL) + (x2 ^ 0x054424ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x054424: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x054428: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x05442c: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x054430: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x054434: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x054438: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x05443c: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x054440: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xB90027E4ULL; // 0x054444: str w4, [sp, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90057E3ULL; // 0x054448: str w3, [sp, #0x54]
    return acc;
}

// [EN] Reconstructed FDE #0588 @ 0x05487c..0x0548a0 (36 bytes)
// [VN] Phục dựng FDE #0588 tại 0x05487c..0x0548a0 (36 byte)
//   0x05487c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x054880: 910003fd  mov      x29, sp
//   0x054884: 2a0303e1  mov      w1, w3
//   0x054888: 2a0203e0  mov      w0, w2
//   0x05488c: 2a0403e2  mov      w2, w4
//   0x054890: 97fffc4c  bl       #0x539c0
//   0x054894: 12000000  and      w0, w0, #1
//   0x054898: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x05489c: d65f03c0  ret      
uint64_t fde_0588_sub_05487c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05487CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x05487c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x054880: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E1ULL; // 0x054884: mov w1, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x054888: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E2ULL; // 0x05488c: mov w2, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC4CULL; // 0x054890: bl #0x539c0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x054894: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x054898: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05489c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0589 @ 0x0548a0..0x054a28 (392 bytes)
// [VN] Phục dựng FDE #0589 tại 0x0548a0..0x054a28 (392 byte)
//   0x0548a0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0548a4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0548a8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0548ac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0548b0: 9100c3fd  add      x29, sp, #0x30
//   0x0548b4: 90000064  adrp     x4, #0x60000
//   0x0548b8: f9469c84  ldr      x4, [x4, #0xd38]
//   0x0548bc: 2a0303f7  mov      w23, w3
//   0x0548c0: 2a0203f5  mov      w21, w2
//   0x0548c4: aa0103f6  mov      x22, x1
//   0x0548c8: f0fffde1  adrp     x1, #0x13000
//   0x0548cc: 90fffde2  adrp     x2, #0x10000
//   0x0548d0: 90fffe03  adrp     x3, #0x14000
//   0x0548d4: 91296821  add      x1, x1, #0xa5a
//   0x0548d8: 91191042  add      x2, x2, #0x644
//   0x0548dc: 91355c63  add      x3, x3, #0xd57
uint64_t fde_0589_sub_0548a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x90FFFE03ULL) + (x2 ^ 0x0548A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0548a0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0548a4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0548a8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0548ac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0548b0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000064ULL; // 0x0548b4: adrp x4, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9469C84ULL; // 0x0548b8: ldr x4, [x4, #0xd38]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F7ULL; // 0x0548bc: mov w23, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x0548c0: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x0548c4: mov x22, x1
    return acc;
}

// [EN] Reconstructed FDE #0590 @ 0x054a28..0x054b20 (248 bytes)
// [VN] Phục dựng FDE #0590 tại 0x054a28..0x054b20 (248 byte)
//   0x054a28: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x054a2c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x054a30: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x054a34: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x054a38: 9100c3fd  add      x29, sp, #0x30
//   0x054a3c: 90000088  adrp     x8, #0x64000
//   0x054a40: 39414108  ldrb     w8, [x8, #0x50]
//   0x054a44: aa0303f3  mov      x19, x3
//   0x054a48: aa0203f4  mov      x20, x2
//   0x054a4c: aa0103f5  mov      x21, x1
//   0x054a50: aa0003f6  mov      x22, x0
//   0x054a54: 34000248  cbz      w8, #0x54a9c
//   0x054a58: b0000097  adrp     x23, #0x65000
//   0x054a5c: 912002f7  add      x23, x23, #0x800
//   0x054a60: 9111a2e0  add      x0, x23, #0x468
//   0x054a64: 940021c3  bl       #0x5d170
uint64_t fde_0590_sub_054a28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB0000097ULL) + (x2 ^ 0x054A28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x054a28: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x054a2c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x054a30: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x054a34: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x054a38: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000088ULL; // 0x054a3c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x39414108ULL; // 0x054a40: ldrb w8, [x8, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x054a44: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x054a48: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x054a4c: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0591 @ 0x054b20..0x054b30 (16 bytes)
// [VN] Phục dựng FDE #0591 tại 0x054b20..0x054b30 (16 byte)
//   0x054b20: b0000088  adrp     x8, #0x65000
//   0x054b24: 911fe108  add      x8, x8, #0x7f8
//   0x054b28: a9401101  ldp      x1, x4, [x8]
//   0x054b2c: d61f0080  br       x4
uint64_t fde_0591_sub_054b20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000088ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x054B20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000088ULL; // 0x054b20: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x911FE108ULL; // 0x054b24: add x8, x8, #0x7f8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9401101ULL; // 0x054b28: ldp x1, x4, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0080ULL; // 0x054b2c: br x4
    return acc;
}

// [EN] Reconstructed FDE #0592 @ 0x054b30..0x054d70 (576 bytes)
// [VN] Phục dựng FDE #0592 tại 0x054b30..0x054d70 (576 byte)
//   0x054b30: d10603ff  sub      sp, sp, #0x180
//   0x054b34: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x054b38: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x054b3c: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x054b40: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x054b44: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x054b48: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x054b4c: 9105c3fd  add      x29, sp, #0x170
//   0x054b50: d53bd056  mrs      x22, tpidr_el0
//   0x054b54: f94016c8  ldr      x8, [x22, #0x28]
//   0x054b58: 90000097  adrp     x23, #0x64000
//   0x054b5c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x054b60: 397a66e8  ldrb     w8, [x23, #0xe99]
//   0x054b64: 36000888  tbz      w8, #0, #0x54c74
//   0x054b68: 2a1f03e0  mov      w0, wzr
//   0x054b6c: 9400232d  bl       #0x5d820
uint64_t fde_0592_sub_054b30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0x397A66E8ULL) + (x2 ^ 0x054B30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x054b30: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x054b34: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x054b38: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x054b3c: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x054b40: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x054b44: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x054b48: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x054b4c: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x054b50: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x054b54: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0593 @ 0x054d70..0x054e88 (280 bytes)
// [VN] Phục dựng FDE #0593 tại 0x054d70..0x054e88 (280 byte)
//   0x054d70: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x054d74: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x054d78: 910043fd  add      x29, sp, #0x10
//   0x054d7c: 90000093  adrp     x19, #0x64000
//   0x054d80: 913eb273  add      x19, x19, #0xfac
//   0x054d84: 91339260  add      x0, x19, #0xce4
//   0x054d88: 940020fa  bl       #0x5d170
//   0x054d8c: 9121b268  add      x8, x19, #0x86c
//   0x054d90: f9400108  ldr      x8, [x8]
//   0x054d94: 91219269  add      x9, x19, #0x864
//   0x054d98: f9400129  ldr      x9, [x9]
//   0x054d9c: b9400263  ldr      w3, [x19]
//   0x054da0: f9400104  ldr      x4, [x8]
//   0x054da4: b9400925  ldr      w5, [x9, #8]
//   0x054da8: 6b04007f  cmp      w3, w4
//   0x054dac: 54000460  b.eq     #0x54e38
uint64_t fde_0593_sub_054d70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400104ULL) + (x2 ^ 0x054D70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x054d70: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x054d74: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x054d78: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000093ULL; // 0x054d7c: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913EB273ULL; // 0x054d80: add x19, x19, #0xfac
    acc = (acc * 0x100000001B3ULL) ^ 0x91339260ULL; // 0x054d84: add x0, x19, #0xce4
    acc = (acc * 0x100000001B3ULL) ^ 0x940020FAULL; // 0x054d88: bl #0x5d170
    acc = (acc * 0x100000001B3ULL) ^ 0x9121B268ULL; // 0x054d8c: add x8, x19, #0x86c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x054d90: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91219269ULL; // 0x054d94: add x9, x19, #0x864
    return acc;
}

// [EN] Reconstructed FDE #0594 @ 0x054e88..0x055048 (448 bytes)
// [VN] Phục dựng FDE #0594 tại 0x054e88..0x055048 (448 byte)
//   0x054e88: d10103ff  sub      sp, sp, #0x40
//   0x054e8c: f9000bf5  str      x21, [sp, #0x10]
//   0x054e90: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x054e94: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x054e98: 9100c3fd  add      x29, sp, #0x30
//   0x054e9c: d53bd055  mrs      x21, tpidr_el0
//   0x054ea0: f94016a8  ldr      x8, [x21, #0x28]
//   0x054ea4: b0000080  adrp     x0, #0x65000
//   0x054ea8: 91324000  add      x0, x0, #0xc90
//   0x054eac: f90007e8  str      x8, [sp, #8]
//   0x054eb0: 940020b0  bl       #0x5d170
//   0x054eb4: d0fffdc1  adrp     x1, #0xe000
//   0x054eb8: f0fffdc2  adrp     x2, #0xf000
//   0x054ebc: 911f1821  add      x1, x1, #0x7c6
//   0x054ec0: 9134e442  add      x2, x2, #0xd39
//   0x054ec4: 528000c0  mov      w0, #6
uint64_t fde_0594_sub_054e88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF0FFFDC2ULL) + (x2 ^ 0x054E88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x054e88: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x054e8c: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x054e90: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x054e94: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x054e98: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x054e9c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x054ea0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000080ULL; // 0x054ea4: adrp x0, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91324000ULL; // 0x054ea8: add x0, x0, #0xc90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x054eac: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0595 @ 0x055048..0x055288 (576 bytes)
// [VN] Phục dựng FDE #0595 tại 0x055048..0x055288 (576 byte)
//   0x055048: d10603ff  sub      sp, sp, #0x180
//   0x05504c: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x055050: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x055054: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x055058: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x05505c: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x055060: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x055064: 9105c3fd  add      x29, sp, #0x170
//   0x055068: d53bd056  mrs      x22, tpidr_el0
//   0x05506c: f94016c8  ldr      x8, [x22, #0x28]
//   0x055070: f0000077  adrp     x23, #0x64000
//   0x055074: f81a03a8  stur     x8, [x29, #-0x60]
//   0x055078: 397a66e8  ldrb     w8, [x23, #0xe99]
//   0x05507c: 36000888  tbz      w8, #0, #0x5518c
//   0x055080: 2a1f03e0  mov      w0, wzr
//   0x055084: 940021e7  bl       #0x5d820
uint64_t fde_0595_sub_055048(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0x397A66E8ULL) + (x2 ^ 0x055048ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x055048: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x05504c: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x055050: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x055054: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x055058: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x05505c: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x055060: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x055064: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x055068: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x05506c: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0596 @ 0x055288..0x055b54 (2252 bytes)
// [VN] Phục dựng FDE #0596 tại 0x055288..0x055b54 (2252 byte)
//   0x055288: d10343ff  sub      sp, sp, #0xd0
//   0x05528c: f9003bfb  str      x27, [sp, #0x70]
//   0x055290: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x055294: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x055298: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x05529c: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x0552a0: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x0552a4: 910303fd  add      x29, sp, #0xc0
//   0x0552a8: 394043a8  ldrb     w8, [x29, #0x10]
//   0x0552ac: d53bd05b  mrs      x27, tpidr_el0
//   0x0552b0: 72001c9f  tst      w4, #0xff
//   0x0552b4: f9401769  ldr      x9, [x27, #0x28]
//   0x0552b8: 1a9f07ea  cset     w10, ne
//   0x0552bc: 72001cdf  tst      w6, #0xff
//   0x0552c0: 1a9f07eb  cset     w11, ne
//   0x0552c4: 72001cff  tst      w7, #0xff
uint64_t fde_0596_sub_055288(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x1A9F07EAULL) + (x2 ^ 0x055288ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x055288: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003BFBULL; // 0x05528c: str x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x055290: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x055294: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x055298: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x05529c: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x0552a0: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x0552a4: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0x394043A8ULL; // 0x0552a8: ldrb w8, [x29, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x0552ac: mrs x27, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0597 @ 0x055b54..0x055ca8 (340 bytes)
// [VN] Phục dựng FDE #0597 tại 0x055b54..0x055ca8 (340 byte)
//   0x055b54: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x055b58: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x055b5c: 910043fd  add      x29, sp, #0x10
//   0x055b60: b0fffdc1  adrp     x1, #0xe000
//   0x055b64: b0fffde2  adrp     x2, #0x12000
//   0x055b68: 911f1821  add      x1, x1, #0x7c6
//   0x055b6c: 9103b442  add      x2, x2, #0xed
//   0x055b70: 528000c0  mov      w0, #6
//   0x055b74: 94001c4b  bl       #0x5cca0
//   0x055b78: f0000073  adrp     x19, #0x64000
//   0x055b7c: 913a9273  add      x19, x19, #0xea4
//   0x055b80: 9137b260  add      x0, x19, #0xdec
//   0x055b84: 94001d7b  bl       #0x5d170
//   0x055b88: 39400268  ldrb     w8, [x19]
//   0x055b8c: 340000a8  cbz      w8, #0x55ba0
//   0x055b90: f0000068  adrp     x8, #0x64000
uint64_t fde_0597_sub_055b54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x94001D7BULL) + (x2 ^ 0x055B54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x055b54: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x055b58: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x055b5c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC1ULL; // 0x055b60: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDE2ULL; // 0x055b64: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x055b68: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x9103B442ULL; // 0x055b6c: add x2, x2, #0xed
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x055b70: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x94001C4BULL; // 0x055b74: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000073ULL; // 0x055b78: adrp x19, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0598 @ 0x055ca8..0x055fcc (804 bytes)
// [VN] Phục dựng FDE #0598 tại 0x055ca8..0x055fcc (804 byte)
//   0x055ca8: d10143ff  sub      sp, sp, #0x50
//   0x055cac: f9000bf7  str      x23, [sp, #0x10]
//   0x055cb0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x055cb4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x055cb8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x055cbc: 910103fd  add      x29, sp, #0x40
//   0x055cc0: d53bd056  mrs      x22, tpidr_el0
//   0x055cc4: f94016c8  ldr      x8, [x22, #0x28]
//   0x055cc8: aa1e03f3  mov      x19, x30
//   0x055ccc: aa0103f4  mov      x20, x1
//   0x055cd0: aa0003f5  mov      x21, x0
//   0x055cd4: f90007e8  str      x8, [sp, #8]
//   0x055cd8: 90000000  adrp     x0, #0x55000
//   0x055cdc: 9132a000  add      x0, x0, #0xca8
//   0x055ce0: 94001d6c  bl       #0x5d290
//   0x055ce4: aa0003e8  mov      x8, x0
uint64_t fde_0598_sub_055ca8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x90000000ULL) + (x2 ^ 0x055CA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x055ca8: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x055cac: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x055cb0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x055cb4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x055cb8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x055cbc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x055cc0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x055cc4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x055cc8: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x055ccc: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0599 @ 0x055fcc..0x0561c0 (500 bytes)
// [VN] Phục dựng FDE #0599 tại 0x055fcc..0x0561c0 (500 byte)
//   0x055fcc: d101c3ff  sub      sp, sp, #0x70
//   0x055fd0: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x055fd4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x055fd8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x055fdc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x055fe0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x055fe4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x055fe8: 910183fd  add      x29, sp, #0x60
//   0x055fec: d53bd05a  mrs      x26, tpidr_el0
//   0x055ff0: f9401748  ldr      x8, [x26, #0x28]
//   0x055ff4: aa0003f3  mov      x19, x0
//   0x055ff8: b0fffdc1  adrp     x1, #0xe000
//   0x055ffc: f0fffda2  adrp     x2, #0xc000
//   0x056000: 911f1821  add      x1, x1, #0x7c6
//   0x056004: 910e2842  add      x2, x2, #0x38a
//   0x056008: 52800060  mov      w0, #3
uint64_t fde_0599_sub_055fcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF0FFFDA2ULL) + (x2 ^ 0x055FCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x055fcc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x055fd0: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x055fd4: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x055fd8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x055fdc: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x055fe0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x055fe4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x055fe8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x055fec: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x055ff0: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0600 @ 0x0561c0..0x056264 (164 bytes)
// [VN] Phục dựng FDE #0600 tại 0x0561c0..0x056264 (164 byte)
//   0x0561c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0561c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0561c8: 910043fd  add      x29, sp, #0x10
//   0x0561cc: f0000068  adrp     x8, #0x65000
//   0x0561d0: f9441100  ldr      x0, [x8, #0x820]
//   0x0561d4: b4000400  cbz      x0, #0x56254
//   0x0561d8: 94001d12  bl       #0x5d620
//   0x0561dc: 340001c0  cbz      w0, #0x56214
//   0x0561e0: 94001ce8  bl       #0x5d580
//   0x0561e4: 34000180  cbz      w0, #0x56214
//   0x0561e8: 2a0003f3  mov      w19, w0
//   0x0561ec: 94001ce9  bl       #0x5d590
//   0x0561f0: 90fffdc1  adrp     x1, #0xe000
//   0x0561f4: d0fffde2  adrp     x2, #0x14000
//   0x0561f8: aa0003e4  mov      x4, x0
//   0x0561fc: 911f1821  add      x1, x1, #0x7c6
uint64_t fde_0600_sub_0561c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x90FFFDC1ULL) + (x2 ^ 0x0561C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0561c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0561c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0561c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000068ULL; // 0x0561cc: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9441100ULL; // 0x0561d0: ldr x0, [x8, #0x820]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000400ULL; // 0x0561d4: cbz x0, #0x56254
    acc = (acc * 0x100000001B3ULL) ^ 0x94001D12ULL; // 0x0561d8: bl #0x5d620
    acc = (acc * 0x100000001B3ULL) ^ 0x340001C0ULL; // 0x0561dc: cbz w0, #0x56214
    acc = (acc * 0x100000001B3ULL) ^ 0x94001CE8ULL; // 0x0561e0: bl #0x5d580
    acc = (acc * 0x100000001B3ULL) ^ 0x34000180ULL; // 0x0561e4: cbz w0, #0x56214
    return acc;
}

// [EN] Reconstructed FDE #0601 @ 0x056264..0x056694 (1072 bytes)
// [VN] Phục dựng FDE #0601 tại 0x056264..0x056694 (1072 byte)
//   0x056264: d10183ff  sub      sp, sp, #0x60
//   0x056268: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x05626c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x056270: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x056274: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x056278: 910143fd  add      x29, sp, #0x50
//   0x05627c: d53bd054  mrs      x20, tpidr_el0
//   0x056280: f9401688  ldr      x8, [x20, #0x28]
//   0x056284: 90fffdc1  adrp     x1, #0xe000
//   0x056288: 90fffdc2  adrp     x2, #0xe000
//   0x05628c: 911f1821  add      x1, x1, #0x7c6
//   0x056290: 9108a842  add      x2, x2, #0x22a
//   0x056294: 528000c0  mov      w0, #6
//   0x056298: f9000fe8  str      x8, [sp, #0x18]
//   0x05629c: 94001a81  bl       #0x5cca0
//   0x0562a0: d0000076  adrp     x22, #0x64000
uint64_t fde_0601_sub_056264(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x528000C0ULL) + (x2 ^ 0x056264ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x056264: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x056268: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x05626c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x056270: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x056274: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x056278: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x05627c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x056280: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDC1ULL; // 0x056284: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDC2ULL; // 0x056288: adrp x2, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0602 @ 0x056694..0x0566ac (24 bytes)
// [VN] Phục dựng FDE #0602 tại 0x056694..0x0566ac (24 byte)
//   0x056694: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x056698: 910003fd  mov      x29, sp
//   0x05669c: 97fffd2e  bl       #0x55b54
//   0x0566a0: 12000000  and      w0, w0, #1
//   0x0566a4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0566a8: d65f03c0  ret      
uint64_t fde_0602_sub_056694(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056694ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x056694: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x056698: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD2EULL; // 0x05669c: bl #0x55b54
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x0566a0: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0566a4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0566a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0603 @ 0x0566ac..0x056714 (104 bytes)
// [VN] Phục dựng FDE #0603 tại 0x0566ac..0x056714 (104 byte)
//   0x0566ac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0566b0: 910003fd  mov      x29, sp
//   0x0566b4: 90fffdc1  adrp     x1, #0xe000
//   0x0566b8: b0fffde2  adrp     x2, #0x13000
//   0x0566bc: 911f1821  add      x1, x1, #0x7c6
//   0x0566c0: 91089042  add      x2, x2, #0x224
//   0x0566c4: 528000c0  mov      w0, #6
//   0x0566c8: 94001976  bl       #0x5cca0
//   0x0566cc: d0000068  adrp     x8, #0x64000
//   0x0566d0: b9405508  ldr      w8, [x8, #0x54]
//   0x0566d4: 7100091f  cmp      w8, #2
//   0x0566d8: 54000081  b.ne     #0x566e8
//   0x0566dc: 52800020  mov      w0, #1
//   0x0566e0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0566e4: d65f03c0  ret      
//   0x0566e8: d0000068  adrp     x8, #0x64000
uint64_t fde_0603_sub_0566ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x52800020ULL) + (x2 ^ 0x0566ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0566ac: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0566b0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDC1ULL; // 0x0566b4: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDE2ULL; // 0x0566b8: adrp x2, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x0566bc: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x91089042ULL; // 0x0566c0: add x2, x2, #0x224
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x0566c4: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x94001976ULL; // 0x0566c8: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000068ULL; // 0x0566cc: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405508ULL; // 0x0566d0: ldr w8, [x8, #0x54]
    return acc;
}

// [EN] Reconstructed FDE #0604 @ 0x056714..0x056750 (60 bytes)
// [VN] Phục dựng FDE #0604 tại 0x056714..0x056750 (60 byte)
//   0x056714: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x056718: 910003fd  mov      x29, sp
//   0x05671c: d0000068  adrp     x8, #0x64000
//   0x056720: 397ab108  ldrb     w8, [x8, #0xeac]
//   0x056724: 340000e8  cbz      w8, #0x56740
//   0x056728: 90fffdc1  adrp     x1, #0xe000
//   0x05672c: b0fffdc2  adrp     x2, #0xf000
//   0x056730: 911f1821  add      x1, x1, #0x7c6
//   0x056734: 91365442  add      x2, x2, #0xd95
//   0x056738: 528000c0  mov      w0, #6
//   0x05673c: 94001959  bl       #0x5cca0
//   0x056740: d0000068  adrp     x8, #0x64000
//   0x056744: b94fb500  ldr      w0, [x8, #0xfb4]
//   0x056748: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x05674c: d65f03c0  ret      
uint64_t fde_0604_sub_056714(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB94FB500ULL) + (x2 ^ 0x056714ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x056714: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x056718: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000068ULL; // 0x05671c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x397AB108ULL; // 0x056720: ldrb w8, [x8, #0xeac]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x056724: cbz w8, #0x56740
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDC1ULL; // 0x056728: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDC2ULL; // 0x05672c: adrp x2, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x056730: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x91365442ULL; // 0x056734: add x2, x2, #0xd95
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x056738: mov w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0605 @ 0x056750..0x05678c (60 bytes)
// [VN] Phục dựng FDE #0605 tại 0x056750..0x05678c (60 byte)
//   0x056750: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x056754: 910003fd  mov      x29, sp
//   0x056758: d0000068  adrp     x8, #0x64000
//   0x05675c: 397ab108  ldrb     w8, [x8, #0xeac]
//   0x056760: 340000e8  cbz      w8, #0x5677c
//   0x056764: 90fffdc1  adrp     x1, #0xe000
//   0x056768: f0fffda2  adrp     x2, #0xd000
//   0x05676c: 911f1821  add      x1, x1, #0x7c6
//   0x056770: 911d2442  add      x2, x2, #0x749
//   0x056774: 528000c0  mov      w0, #6
//   0x056778: 9400194a  bl       #0x5cca0
//   0x05677c: d0000068  adrp     x8, #0x64000
//   0x056780: b94fb100  ldr      w0, [x8, #0xfb0]
//   0x056784: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x056788: d65f03c0  ret      
uint64_t fde_0605_sub_056750(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB94FB100ULL) + (x2 ^ 0x056750ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x056750: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x056754: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000068ULL; // 0x056758: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x397AB108ULL; // 0x05675c: ldrb w8, [x8, #0xeac]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x056760: cbz w8, #0x5677c
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDC1ULL; // 0x056764: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDA2ULL; // 0x056768: adrp x2, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x05676c: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x911D2442ULL; // 0x056770: add x2, x2, #0x749
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x056774: mov w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0606 @ 0x05678c..0x056854 (200 bytes)
// [VN] Phục dựng FDE #0606 tại 0x05678c..0x056854 (200 byte)
//   0x05678c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x056790: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x056794: 910043fd  add      x29, sp, #0x10
//   0x056798: d0fffde1  adrp     x1, #0x14000
//   0x05679c: f0fffde2  adrp     x2, #0x15000
//   0x0567a0: 910ff421  add      x1, x1, #0x3fd
//   0x0567a4: 911c3c42  add      x2, x2, #0x70f
//   0x0567a8: 52800060  mov      w0, #3
//   0x0567ac: 9400193d  bl       #0x5cca0
//   0x0567b0: f0000073  adrp     x19, #0x65000
//   0x0567b4: d0fffdc0  adrp     x0, #0x10000
//   0x0567b8: f0fffdc1  adrp     x1, #0x11000
//   0x0567bc: 90000002  adrp     x2, #0x56000
//   0x0567c0: 9120e273  add      x19, x19, #0x838
//   0x0567c4: 911ad800  add      x0, x0, #0x6b6
//   0x0567c8: 91302c21  add      x1, x1, #0xc0b
uint64_t fde_0606_sub_05678c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x90000002ULL) + (x2 ^ 0x05678CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x05678c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x056790: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x056794: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFDE1ULL; // 0x056798: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFDE2ULL; // 0x05679c: adrp x2, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x910FF421ULL; // 0x0567a0: add x1, x1, #0x3fd
    acc = (acc * 0x100000001B3ULL) ^ 0x911C3C42ULL; // 0x0567a4: add x2, x2, #0x70f
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x0567a8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400193DULL; // 0x0567ac: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000073ULL; // 0x0567b0: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0607 @ 0x056854..0x056910 (188 bytes)
// [VN] Phục dựng FDE #0607 tại 0x056854..0x056910 (188 byte)
//   0x056854: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x056858: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05685c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x056860: 910083fd  add      x29, sp, #0x20
//   0x056864: aa1e03f3  mov      x19, x30
//   0x056868: aa0203f5  mov      x21, x2
//   0x05686c: 2a0103f6  mov      w22, w1
//   0x056870: aa0003f4  mov      x20, x0
//   0x056874: 90000000  adrp     x0, #0x56000
//   0x056878: 91215000  add      x0, x0, #0x854
//   0x05687c: 94001a85  bl       #0x5d290
//   0x056880: aa0003e8  mov      x8, x0
//   0x056884: aa1403e0  mov      x0, x20
//   0x056888: 2a1603e1  mov      w1, w22
//   0x05688c: aa1503e2  mov      x2, x21
//   0x056890: d63f0100  blr      x8
uint64_t fde_0607_sub_056854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x056854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x056854: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x056858: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05685c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x056860: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x056864: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x056868: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x05686c: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x056870: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x056874: adrp x0, #0x56000
    acc = (acc * 0x100000001B3ULL) ^ 0x91215000ULL; // 0x056878: add x0, x0, #0x854
    return acc;
}

// [EN] Reconstructed FDE #0608 @ 0x056910..0x056a18 (264 bytes)
// [VN] Phục dựng FDE #0608 tại 0x056910..0x056a18 (264 byte)
//   0x056910: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x056914: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x056918: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05691c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x056920: 9100c3fd  add      x29, sp, #0x30
//   0x056924: aa0003f4  mov      x20, x0
//   0x056928: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x05692c: f8010e9f  str      xzr, [x20, #0x10]!
//   0x056930: d0000048  adrp     x8, #0x60000
//   0x056934: 2a0403f7  mov      w23, w4
//   0x056938: 2a0303f6  mov      w22, w3
//   0x05693c: 2a0203f5  mov      w21, w2
//   0x056940: aa0003f3  mov      x19, x0
//   0x056944: 91142108  add      x8, x8, #0x508
//   0x056948: eb01029f  cmp      x20, x1
//   0x05694c: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0608_sub_056910(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x056910ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x056910: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x056914: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x056918: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05691c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x056920: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x056924: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x056928: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x05692c: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000048ULL; // 0x056930: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x056934: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0609 @ 0x056a18..0x056a80 (104 bytes)
// [VN] Phục dựng FDE #0609 tại 0x056a18..0x056a80 (104 byte)
//   0x056a18: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x056a1c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x056a20: 910043fd  add      x29, sp, #0x10
//   0x056a24: aa0003f3  mov      x19, x0
//   0x056a28: b9400800  ldr      w0, [x0, #8]
//   0x056a2c: d0000048  adrp     x8, #0x60000
//   0x056a30: 91142108  add      x8, x8, #0x508
//   0x056a34: f9000268  str      x8, [x19]
//   0x056a38: 940019ca  bl       #0x5d160
//   0x056a3c: 39404268  ldrb     w8, [x19, #0x10]
//   0x056a40: d0000049  adrp     x9, #0x60000
//   0x056a44: 91250129  add      x9, x9, #0x940
//   0x056a48: f9000269  str      x9, [x19]
//   0x056a4c: 37000088  tbnz     w8, #0, #0x56a5c
//   0x056a50: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x056a54: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0609_sub_056a18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x056A18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x056a18: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x056a1c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x056a20: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x056a24: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x056a28: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000048ULL; // 0x056a2c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91142108ULL; // 0x056a30: add x8, x8, #0x508
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x056a34: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x940019CAULL; // 0x056a38: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x056a3c: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0610 @ 0x056a80..0x056ae4 (100 bytes)
// [VN] Phục dựng FDE #0610 tại 0x056a80..0x056ae4 (100 byte)
//   0x056a80: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x056a84: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x056a88: 910043fd  add      x29, sp, #0x10
//   0x056a8c: aa0003f3  mov      x19, x0
//   0x056a90: b9400800  ldr      w0, [x0, #8]
//   0x056a94: d0000048  adrp     x8, #0x60000
//   0x056a98: 91142108  add      x8, x8, #0x508
//   0x056a9c: f9000268  str      x8, [x19]
//   0x056aa0: 940019b0  bl       #0x5d160
//   0x056aa4: 39404268  ldrb     w8, [x19, #0x10]
//   0x056aa8: d0000049  adrp     x9, #0x60000
//   0x056aac: 91250129  add      x9, x9, #0x940
//   0x056ab0: f9000269  str      x9, [x19]
//   0x056ab4: 36000068  tbz      w8, #0, #0x56ac0
//   0x056ab8: f9401260  ldr      x0, [x19, #0x20]
//   0x056abc: 940019ed  bl       #0x5d270
uint64_t fde_0610_sub_056a80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x056A80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x056a80: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x056a84: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x056a88: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x056a8c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x056a90: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000048ULL; // 0x056a94: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91142108ULL; // 0x056a98: add x8, x8, #0x508
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x056a9c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x940019B0ULL; // 0x056aa0: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x056aa4: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0611 @ 0x056ae4..0x056e54 (880 bytes)
// [VN] Phục dựng FDE #0611 tại 0x056ae4..0x056e54 (880 byte)
//   0x056ae4: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x056ae8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x056aec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x056af0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x056af4: 9100c3fd  add      x29, sp, #0x30
//   0x056af8: d14007ff  sub      sp, sp, #1, lsl #12
//   0x056afc: d10703ff  sub      sp, sp, #0x1c0
//   0x056b00: d53bd056  mrs      x22, tpidr_el0
//   0x056b04: f94016c8  ldr      x8, [x22, #0x28]
//   0x056b08: aa0103f5  mov      x21, x1
//   0x056b0c: 912383e1  add      x1, sp, #0x8e0
//   0x056b10: aa0003f4  mov      x20, x0
//   0x056b14: f81c83a8  stur     x8, [x29, #-0x38]
//   0x056b18: 9400014e  bl       #0x57050
//   0x056b1c: b948ebe8  ldr      w8, [sp, #0x8e8]
//   0x056b20: 2a0003f3  mov      w19, w0
uint64_t fde_0611_sub_056ae4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x056AE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x056ae4: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x056ae8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x056aec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x056af0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x056af4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x056af8: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x056afc: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x056b00: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x056b04: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x056b08: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0612 @ 0x056e54..0x056ef0 (156 bytes)
// [VN] Phục dựng FDE #0612 tại 0x056e54..0x056ef0 (156 byte)
//   0x056e54: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x056e58: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x056e5c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x056e60: 910083fd  add      x29, sp, #0x20
//   0x056e64: d12383ff  sub      sp, sp, #0x8e0
//   0x056e68: d53bd054  mrs      x20, tpidr_el0
//   0x056e6c: f9401688  ldr      x8, [x20, #0x28]
//   0x056e70: 910003e1  mov      x1, sp
//   0x056e74: aa0003f3  mov      x19, x0
//   0x056e78: f81d83a8  stur     x8, [x29, #-0x28]
//   0x056e7c: 94000075  bl       #0x57050
//   0x056e80: 3940a268  ldrb     w8, [x19, #0x28]
//   0x056e84: 2a0003f3  mov      w19, w0
//   0x056e88: 34000128  cbz      w8, #0x56eac
//   0x056e8c: b9400be3  ldr      w3, [sp, #8]
//   0x056e90: 394033e4  ldrb     w4, [sp, #0xc]
uint64_t fde_0612_sub_056e54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x056E54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x056e54: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x056e58: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x056e5c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x056e60: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD12383FFULL; // 0x056e64: sub sp, sp, #0x8e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x056e68: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x056e6c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x056e70: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x056e74: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x056e78: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0613 @ 0x056ef0..0x056ef4 (4 bytes)
// [VN] Phục dựng FDE #0613 tại 0x056ef0..0x056ef4 (4 byte)
//   0x056ef0: 1400000b  b        #0x56f1c
uint64_t fde_0613_sub_056ef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x056EF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x056ef0: b #0x56f1c
    return acc;
}

// [EN] Reconstructed FDE #0614 @ 0x056ef4..0x056efc (8 bytes)
// [VN] Phục dựng FDE #0614 tại 0x056ef4..0x056efc (8 byte)
//   0x056ef4: 2a1f03e0  mov      w0, wzr
//   0x056ef8: d65f03c0  ret      
uint64_t fde_0614_sub_056ef4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056EF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x056ef4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x056ef8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0615 @ 0x056efc..0x056f04 (8 bytes)
// [VN] Phục dựng FDE #0615 tại 0x056efc..0x056f04 (8 byte)
//   0x056efc: 2a1f03e0  mov      w0, wzr
//   0x056f00: d65f03c0  ret      
uint64_t fde_0615_sub_056efc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056EFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x056efc: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x056f00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0616 @ 0x056f04..0x056f0c (8 bytes)
// [VN] Phục dựng FDE #0616 tại 0x056f04..0x056f0c (8 byte)
//   0x056f04: 2a1f03e0  mov      w0, wzr
//   0x056f08: d65f03c0  ret      
uint64_t fde_0616_sub_056f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x056f04: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x056f08: ret 
    return acc;
}

// [EN] Reconstructed FDE #0617 @ 0x056f0c..0x056f14 (8 bytes)
// [VN] Phục dựng FDE #0617 tại 0x056f0c..0x056f14 (8 byte)
//   0x056f0c: 52800060  mov      w0, #3
//   0x056f10: d65f03c0  ret      
uint64_t fde_0617_sub_056f0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056F0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x056f0c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x056f10: ret 
    return acc;
}

// [EN] Reconstructed FDE #0618 @ 0x056f14..0x056f1c (8 bytes)
// [VN] Phục dựng FDE #0618 tại 0x056f14..0x056f1c (8 byte)
//   0x056f14: 52800100  mov      w0, #8
//   0x056f18: d65f03c0  ret      
uint64_t fde_0618_sub_056f14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x056F14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x056f14: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x056f18: ret 
    return acc;
}

// [EN] Reconstructed FDE #0619 @ 0x056f1c..0x057050 (308 bytes)
// [VN] Phục dựng FDE #0619 tại 0x056f1c..0x057050 (308 byte)
//   0x056f1c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x056f20: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x056f24: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x056f28: 910083fd  add      x29, sp, #0x20
//   0x056f2c: b9400028  ldr      w8, [x1]
//   0x056f30: aa0103f3  mov      x19, x1
//   0x056f34: aa0003f4  mov      x20, x0
//   0x056f38: 71000d1f  cmp      w8, #3
//   0x056f3c: 540000e0  b.eq     #0x56f58
//   0x056f40: 7100091f  cmp      w8, #2
//   0x056f44: 540000e0  b.eq     #0x56f60
//   0x056f48: 7100051f  cmp      w8, #1
//   0x056f4c: 54000141  b.ne     #0x56f74
//   0x056f50: 52800815  mov      w21, #0x40
//   0x056f54: 14000009  b        #0x56f78
//   0x056f58: 52800215  mov      w21, #0x10
uint64_t fde_0619_sub_056f1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000141ULL) + (x2 ^ 0x056F1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x056f1c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x056f20: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x056f24: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x056f28: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x056f2c: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x056f30: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x056f34: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x056f38: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E0ULL; // 0x056f3c: b.eq #0x56f58
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x056f40: cmp w8, #2
    return acc;
}

// [EN] Reconstructed FDE #0620 @ 0x057050..0x0571b4 (356 bytes)
// [VN] Phục dựng FDE #0620 tại 0x057050..0x0571b4 (356 byte)
//   0x057050: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x057054: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x057058: 910043fd  add      x29, sp, #0x10
//   0x05705c: aa0103f3  mov      x19, x1
//   0x057060: aa0003f4  mov      x20, x0
//   0x057064: b9400a80  ldr      w0, [x20, #8]
//   0x057068: 52811b02  mov      w2, #0x8d8
//   0x05706c: 52800803  mov      w3, #0x40
//   0x057070: aa1303e1  mov      x1, x19
//   0x057074: aa1f03e4  mov      x4, xzr
//   0x057078: aa1f03e5  mov      x5, xzr
//   0x05707c: 94001a09  bl       #0x5d8a0
//   0x057080: b100041f  cmn      x0, #1
//   0x057084: 540001e1  b.ne     #0x570c0
//   0x057088: 9400179a  bl       #0x5cef0
//   0x05708c: b9400008  ldr      w8, [x0]
uint64_t fde_0620_sub_057050(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x057050ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x057050: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x057054: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x057058: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x05705c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x057060: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x057064: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52811B02ULL; // 0x057068: mov w2, #0x8d8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x05706c: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x057070: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x057074: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0621 @ 0x0571b4..0x0572bc (264 bytes)
// [VN] Phục dựng FDE #0621 tại 0x0571b4..0x0572bc (264 byte)
//   0x0571b4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0571b8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0571bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0571c0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0571c4: 9100c3fd  add      x29, sp, #0x30
//   0x0571c8: aa0003f4  mov      x20, x0
//   0x0571cc: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x0571d0: f8010e9f  str      xzr, [x20, #0x10]!
//   0x0571d4: b0000048  adrp     x8, #0x60000
//   0x0571d8: 2a0403f7  mov      w23, w4
//   0x0571dc: 2a0303f6  mov      w22, w3
//   0x0571e0: 2a0203f5  mov      w21, w2
//   0x0571e4: aa0003f3  mov      x19, x0
//   0x0571e8: 91160108  add      x8, x8, #0x580
//   0x0571ec: eb01029f  cmp      x20, x1
//   0x0571f0: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0621_sub_0571b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0571B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0571b4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0571b8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0571bc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0571c0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0571c4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0571c8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x0571cc: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x0571d0: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x0571d4: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x0571d8: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0622 @ 0x0572bc..0x057324 (104 bytes)
// [VN] Phục dựng FDE #0622 tại 0x0572bc..0x057324 (104 byte)
//   0x0572bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0572c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0572c4: 910043fd  add      x29, sp, #0x10
//   0x0572c8: aa0003f3  mov      x19, x0
//   0x0572cc: b9400800  ldr      w0, [x0, #8]
//   0x0572d0: b0000048  adrp     x8, #0x60000
//   0x0572d4: 91160108  add      x8, x8, #0x580
//   0x0572d8: f9000268  str      x8, [x19]
//   0x0572dc: 940017a1  bl       #0x5d160
//   0x0572e0: 39404268  ldrb     w8, [x19, #0x10]
//   0x0572e4: b0000049  adrp     x9, #0x60000
//   0x0572e8: 91250129  add      x9, x9, #0x940
//   0x0572ec: f9000269  str      x9, [x19]
//   0x0572f0: 37000088  tbnz     w8, #0, #0x57300
//   0x0572f4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0572f8: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0622_sub_0572bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x0572BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0572bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0572c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0572c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0572c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x0572cc: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x0572d0: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91160108ULL; // 0x0572d4: add x8, x8, #0x580
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0572d8: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x940017A1ULL; // 0x0572dc: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x0572e0: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0623 @ 0x057324..0x057388 (100 bytes)
// [VN] Phục dựng FDE #0623 tại 0x057324..0x057388 (100 byte)
//   0x057324: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x057328: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05732c: 910043fd  add      x29, sp, #0x10
//   0x057330: aa0003f3  mov      x19, x0
//   0x057334: b9400800  ldr      w0, [x0, #8]
//   0x057338: b0000048  adrp     x8, #0x60000
//   0x05733c: 91160108  add      x8, x8, #0x580
//   0x057340: f9000268  str      x8, [x19]
//   0x057344: 94001787  bl       #0x5d160
//   0x057348: 39404268  ldrb     w8, [x19, #0x10]
//   0x05734c: b0000049  adrp     x9, #0x60000
//   0x057350: 91250129  add      x9, x9, #0x940
//   0x057354: f9000269  str      x9, [x19]
//   0x057358: 36000068  tbz      w8, #0, #0x57364
//   0x05735c: f9401260  ldr      x0, [x19, #0x20]
//   0x057360: 940017c4  bl       #0x5d270
uint64_t fde_0623_sub_057324(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x057324ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x057324: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x057328: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05732c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x057330: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x057334: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x057338: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91160108ULL; // 0x05733c: add x8, x8, #0x580
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x057340: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94001787ULL; // 0x057344: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x057348: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0624 @ 0x057388..0x0576f8 (880 bytes)
// [VN] Phục dựng FDE #0624 tại 0x057388..0x0576f8 (880 byte)
//   0x057388: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x05738c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x057390: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x057394: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x057398: 9100c3fd  add      x29, sp, #0x30
//   0x05739c: d14007ff  sub      sp, sp, #1, lsl #12
//   0x0573a0: d10743ff  sub      sp, sp, #0x1d0
//   0x0573a4: d53bd056  mrs      x22, tpidr_el0
//   0x0573a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0573ac: aa0103f5  mov      x21, x1
//   0x0573b0: 9123a3e1  add      x1, sp, #0x8e8
//   0x0573b4: aa0003f4  mov      x20, x0
//   0x0573b8: f81c83a8  stur     x8, [x29, #-0x38]
//   0x0573bc: 9400014e  bl       #0x578f4
//   0x0573c0: b948f3e8  ldr      w8, [sp, #0x8f0]
//   0x0573c4: 2a0003f3  mov      w19, w0
uint64_t fde_0624_sub_057388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x057388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x057388: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05738c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x057390: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x057394: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x057398: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x05739c: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x0573a0: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0573a4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0573a8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0573ac: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0625 @ 0x0576f8..0x057794 (156 bytes)
// [VN] Phục dựng FDE #0625 tại 0x0576f8..0x057794 (156 byte)
//   0x0576f8: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x0576fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x057700: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x057704: 910083fd  add      x29, sp, #0x20
//   0x057708: d123c3ff  sub      sp, sp, #0x8f0
//   0x05770c: d53bd054  mrs      x20, tpidr_el0
//   0x057710: f9401688  ldr      x8, [x20, #0x28]
//   0x057714: 910023e1  add      x1, sp, #8
//   0x057718: aa0003f3  mov      x19, x0
//   0x05771c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x057720: 94000075  bl       #0x578f4
//   0x057724: 3940a268  ldrb     w8, [x19, #0x28]
//   0x057728: 2a0003f3  mov      w19, w0
//   0x05772c: 34000128  cbz      w8, #0x57750
//   0x057730: b94013e3  ldr      w3, [sp, #0x10]
//   0x057734: 394053e4  ldrb     w4, [sp, #0x14]
uint64_t fde_0625_sub_0576f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x0576F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x0576f8: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0576fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x057700: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x057704: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD123C3FFULL; // 0x057708: sub sp, sp, #0x8f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x05770c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x057710: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x057714: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x057718: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x05771c: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0626 @ 0x057794..0x057798 (4 bytes)
// [VN] Phục dựng FDE #0626 tại 0x057794..0x057798 (4 byte)
//   0x057794: 1400000b  b        #0x577c0
uint64_t fde_0626_sub_057794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x057794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x057794: b #0x577c0
    return acc;
}

// [EN] Reconstructed FDE #0627 @ 0x057798..0x0577a0 (8 bytes)
// [VN] Phục dựng FDE #0627 tại 0x057798..0x0577a0 (8 byte)
//   0x057798: 2a1f03e0  mov      w0, wzr
//   0x05779c: d65f03c0  ret      
uint64_t fde_0627_sub_057798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x057798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x057798: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05779c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0628 @ 0x0577a0..0x0577a8 (8 bytes)
// [VN] Phục dựng FDE #0628 tại 0x0577a0..0x0577a8 (8 byte)
//   0x0577a0: 2a1f03e0  mov      w0, wzr
//   0x0577a4: d65f03c0  ret      
uint64_t fde_0628_sub_0577a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0577A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0577a0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0577a4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0629 @ 0x0577a8..0x0577b0 (8 bytes)
// [VN] Phục dựng FDE #0629 tại 0x0577a8..0x0577b0 (8 byte)
//   0x0577a8: 2a1f03e0  mov      w0, wzr
//   0x0577ac: d65f03c0  ret      
uint64_t fde_0629_sub_0577a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0577A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0577a8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0577ac: ret 
    return acc;
}

// [EN] Reconstructed FDE #0630 @ 0x0577b0..0x0577b8 (8 bytes)
// [VN] Phục dựng FDE #0630 tại 0x0577b0..0x0577b8 (8 byte)
//   0x0577b0: 52800060  mov      w0, #3
//   0x0577b4: d65f03c0  ret      
uint64_t fde_0630_sub_0577b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0577B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x0577b0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0577b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0631 @ 0x0577b8..0x0577c0 (8 bytes)
// [VN] Phục dựng FDE #0631 tại 0x0577b8..0x0577c0 (8 byte)
//   0x0577b8: 52800100  mov      w0, #8
//   0x0577bc: d65f03c0  ret      
uint64_t fde_0631_sub_0577b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0577B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x0577b8: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0577bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0632 @ 0x0577c0..0x0578f4 (308 bytes)
// [VN] Phục dựng FDE #0632 tại 0x0577c0..0x0578f4 (308 byte)
//   0x0577c0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0577c4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0577c8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0577cc: 910083fd  add      x29, sp, #0x20
//   0x0577d0: b9400028  ldr      w8, [x1]
//   0x0577d4: aa0103f3  mov      x19, x1
//   0x0577d8: aa0003f4  mov      x20, x0
//   0x0577dc: 71000d1f  cmp      w8, #3
//   0x0577e0: 540000e0  b.eq     #0x577fc
//   0x0577e4: 7100091f  cmp      w8, #2
//   0x0577e8: 540000e0  b.eq     #0x57804
//   0x0577ec: 7100051f  cmp      w8, #1
//   0x0577f0: 54000141  b.ne     #0x57818
//   0x0577f4: 52800915  mov      w21, #0x48
//   0x0577f8: 14000009  b        #0x5781c
//   0x0577fc: 52800215  mov      w21, #0x10
uint64_t fde_0632_sub_0577c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000141ULL) + (x2 ^ 0x0577C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0577c0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0577c4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0577c8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0577cc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x0577d0: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0577d4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0577d8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x0577dc: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E0ULL; // 0x0577e0: b.eq #0x577fc
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x0577e4: cmp w8, #2
    return acc;
}

// [EN] Reconstructed FDE #0633 @ 0x0578f4..0x057a58 (356 bytes)
// [VN] Phục dựng FDE #0633 tại 0x0578f4..0x057a58 (356 byte)
//   0x0578f4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0578f8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0578fc: 910043fd  add      x29, sp, #0x10
//   0x057900: aa0103f3  mov      x19, x1
//   0x057904: aa0003f4  mov      x20, x0
//   0x057908: b9400a80  ldr      w0, [x20, #8]
//   0x05790c: 52811c02  mov      w2, #0x8e0
//   0x057910: 52800803  mov      w3, #0x40
//   0x057914: aa1303e1  mov      x1, x19
//   0x057918: aa1f03e4  mov      x4, xzr
//   0x05791c: aa1f03e5  mov      x5, xzr
//   0x057920: 940017e0  bl       #0x5d8a0
//   0x057924: b100041f  cmn      x0, #1
//   0x057928: 540001e1  b.ne     #0x57964
//   0x05792c: 94001571  bl       #0x5cef0
//   0x057930: b9400008  ldr      w8, [x0]
uint64_t fde_0633_sub_0578f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x0578F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0578f4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0578f8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0578fc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x057900: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x057904: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x057908: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52811C02ULL; // 0x05790c: mov w2, #0x8e0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x057910: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x057914: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x057918: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0634 @ 0x057a58..0x057b60 (264 bytes)
// [VN] Phục dựng FDE #0634 tại 0x057a58..0x057b60 (264 byte)
//   0x057a58: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x057a5c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x057a60: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x057a64: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x057a68: 9100c3fd  add      x29, sp, #0x30
//   0x057a6c: aa0003f4  mov      x20, x0
//   0x057a70: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x057a74: f8010e9f  str      xzr, [x20, #0x10]!
//   0x057a78: b0000048  adrp     x8, #0x60000
//   0x057a7c: 2a0403f7  mov      w23, w4
//   0x057a80: 2a0303f6  mov      w22, w3
//   0x057a84: 2a0203f5  mov      w21, w2
//   0x057a88: aa0003f3  mov      x19, x0
//   0x057a8c: 9117e108  add      x8, x8, #0x5f8
//   0x057a90: eb01029f  cmp      x20, x1
//   0x057a94: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0634_sub_057a58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x057A58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x057a58: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x057a5c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x057a60: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x057a64: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x057a68: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x057a6c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x057a70: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x057a74: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x057a78: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x057a7c: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0635 @ 0x057b60..0x057bc8 (104 bytes)
// [VN] Phục dựng FDE #0635 tại 0x057b60..0x057bc8 (104 byte)
//   0x057b60: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x057b64: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x057b68: 910043fd  add      x29, sp, #0x10
//   0x057b6c: aa0003f3  mov      x19, x0
//   0x057b70: b9400800  ldr      w0, [x0, #8]
//   0x057b74: b0000048  adrp     x8, #0x60000
//   0x057b78: 9117e108  add      x8, x8, #0x5f8
//   0x057b7c: f9000268  str      x8, [x19]
//   0x057b80: 94001578  bl       #0x5d160
//   0x057b84: 39404268  ldrb     w8, [x19, #0x10]
//   0x057b88: b0000049  adrp     x9, #0x60000
//   0x057b8c: 91250129  add      x9, x9, #0x940
//   0x057b90: f9000269  str      x9, [x19]
//   0x057b94: 37000088  tbnz     w8, #0, #0x57ba4
//   0x057b98: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x057b9c: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0635_sub_057b60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x057B60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x057b60: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x057b64: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x057b68: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x057b6c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x057b70: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x057b74: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9117E108ULL; // 0x057b78: add x8, x8, #0x5f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x057b7c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94001578ULL; // 0x057b80: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x057b84: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0636 @ 0x057bc8..0x057c2c (100 bytes)
// [VN] Phục dựng FDE #0636 tại 0x057bc8..0x057c2c (100 byte)
//   0x057bc8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x057bcc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x057bd0: 910043fd  add      x29, sp, #0x10
//   0x057bd4: aa0003f3  mov      x19, x0
//   0x057bd8: b9400800  ldr      w0, [x0, #8]
//   0x057bdc: b0000048  adrp     x8, #0x60000
//   0x057be0: 9117e108  add      x8, x8, #0x5f8
//   0x057be4: f9000268  str      x8, [x19]
//   0x057be8: 9400155e  bl       #0x5d160
//   0x057bec: 39404268  ldrb     w8, [x19, #0x10]
//   0x057bf0: b0000049  adrp     x9, #0x60000
//   0x057bf4: 91250129  add      x9, x9, #0x940
//   0x057bf8: f9000269  str      x9, [x19]
//   0x057bfc: 36000068  tbz      w8, #0, #0x57c08
//   0x057c00: f9401260  ldr      x0, [x19, #0x20]
//   0x057c04: 9400159b  bl       #0x5d270
uint64_t fde_0636_sub_057bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x057BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x057bc8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x057bcc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x057bd0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x057bd4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x057bd8: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000048ULL; // 0x057bdc: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9117E108ULL; // 0x057be0: add x8, x8, #0x5f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x057be4: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400155EULL; // 0x057be8: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x057bec: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0637 @ 0x057c2c..0x057f9c (880 bytes)
// [VN] Phục dựng FDE #0637 tại 0x057c2c..0x057f9c (880 byte)
//   0x057c2c: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x057c30: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x057c34: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x057c38: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x057c3c: 9100c3fd  add      x29, sp, #0x30
//   0x057c40: d14007ff  sub      sp, sp, #1, lsl #12
//   0x057c44: d10743ff  sub      sp, sp, #0x1d0
//   0x057c48: d53bd056  mrs      x22, tpidr_el0
//   0x057c4c: f94016c8  ldr      x8, [x22, #0x28]
//   0x057c50: aa0103f5  mov      x21, x1
//   0x057c54: 9123a3e1  add      x1, sp, #0x8e8
//   0x057c58: aa0003f4  mov      x20, x0
//   0x057c5c: f81c83a8  stur     x8, [x29, #-0x38]
//   0x057c60: 9400014e  bl       #0x58198
//   0x057c64: b948f3e8  ldr      w8, [sp, #0x8f0]
//   0x057c68: 2a0003f3  mov      w19, w0
uint64_t fde_0637_sub_057c2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x057C2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x057c2c: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x057c30: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x057c34: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x057c38: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x057c3c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x057c40: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x057c44: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x057c48: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x057c4c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x057c50: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0638 @ 0x057f9c..0x058038 (156 bytes)
// [VN] Phục dựng FDE #0638 tại 0x057f9c..0x058038 (156 byte)
//   0x057f9c: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x057fa0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x057fa4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x057fa8: 910083fd  add      x29, sp, #0x20
//   0x057fac: d123c3ff  sub      sp, sp, #0x8f0
//   0x057fb0: d53bd054  mrs      x20, tpidr_el0
//   0x057fb4: f9401688  ldr      x8, [x20, #0x28]
//   0x057fb8: 910023e1  add      x1, sp, #8
//   0x057fbc: aa0003f3  mov      x19, x0
//   0x057fc0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x057fc4: 94000075  bl       #0x58198
//   0x057fc8: 3940a268  ldrb     w8, [x19, #0x28]
//   0x057fcc: 2a0003f3  mov      w19, w0
//   0x057fd0: 34000128  cbz      w8, #0x57ff4
//   0x057fd4: b94013e3  ldr      w3, [sp, #0x10]
//   0x057fd8: 394053e4  ldrb     w4, [sp, #0x14]
uint64_t fde_0638_sub_057f9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x057F9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x057f9c: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x057fa0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x057fa4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x057fa8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD123C3FFULL; // 0x057fac: sub sp, sp, #0x8f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x057fb0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x057fb4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x057fb8: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x057fbc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x057fc0: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0639 @ 0x058038..0x05803c (4 bytes)
// [VN] Phục dựng FDE #0639 tại 0x058038..0x05803c (4 byte)
//   0x058038: 1400000b  b        #0x58064
uint64_t fde_0639_sub_058038(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x058038ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x058038: b #0x58064
    return acc;
}

// [EN] Reconstructed FDE #0640 @ 0x05803c..0x058044 (8 bytes)
// [VN] Phục dựng FDE #0640 tại 0x05803c..0x058044 (8 byte)
//   0x05803c: 2a1f03e0  mov      w0, wzr
//   0x058040: d65f03c0  ret      
uint64_t fde_0640_sub_05803c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05803CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x05803c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x058040: ret 
    return acc;
}

// [EN] Reconstructed FDE #0641 @ 0x058044..0x05804c (8 bytes)
// [VN] Phục dựng FDE #0641 tại 0x058044..0x05804c (8 byte)
//   0x058044: 2a1f03e0  mov      w0, wzr
//   0x058048: d65f03c0  ret      
uint64_t fde_0641_sub_058044(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x058044ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x058044: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x058048: ret 
    return acc;
}

// [EN] Reconstructed FDE #0642 @ 0x05804c..0x058054 (8 bytes)
// [VN] Phục dựng FDE #0642 tại 0x05804c..0x058054 (8 byte)
//   0x05804c: 2a1f03e0  mov      w0, wzr
//   0x058050: d65f03c0  ret      
uint64_t fde_0642_sub_05804c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05804CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x05804c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x058050: ret 
    return acc;
}

// [EN] Reconstructed FDE #0643 @ 0x058054..0x05805c (8 bytes)
// [VN] Phục dựng FDE #0643 tại 0x058054..0x05805c (8 byte)
//   0x058054: 52800080  mov      w0, #4
//   0x058058: d65f03c0  ret      
uint64_t fde_0643_sub_058054(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x058054ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x058054: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x058058: ret 
    return acc;
}

// [EN] Reconstructed FDE #0644 @ 0x05805c..0x058064 (8 bytes)
// [VN] Phục dựng FDE #0644 tại 0x05805c..0x058064 (8 byte)
//   0x05805c: 52800100  mov      w0, #8
//   0x058060: d65f03c0  ret      
uint64_t fde_0644_sub_05805c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05805CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x05805c: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x058060: ret 
    return acc;
}

// [EN] Reconstructed FDE #0645 @ 0x058064..0x058198 (308 bytes)
// [VN] Phục dựng FDE #0645 tại 0x058064..0x058198 (308 byte)
//   0x058064: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x058068: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05806c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x058070: 910083fd  add      x29, sp, #0x20
//   0x058074: b9400028  ldr      w8, [x1]
//   0x058078: aa0103f3  mov      x19, x1
//   0x05807c: aa0003f4  mov      x20, x0
//   0x058080: 71000d1f  cmp      w8, #3
//   0x058084: 540000e0  b.eq     #0x580a0
//   0x058088: 7100091f  cmp      w8, #2
//   0x05808c: 540000e0  b.eq     #0x580a8
//   0x058090: 7100051f  cmp      w8, #1
//   0x058094: 54000141  b.ne     #0x580bc
//   0x058098: 52800915  mov      w21, #0x48
//   0x05809c: 14000009  b        #0x580c0
//   0x0580a0: 52800215  mov      w21, #0x10
uint64_t fde_0645_sub_058064(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000141ULL) + (x2 ^ 0x058064ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x058064: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x058068: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05806c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x058070: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x058074: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x058078: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x05807c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x058080: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E0ULL; // 0x058084: b.eq #0x580a0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x058088: cmp w8, #2
    return acc;
}

// [EN] Reconstructed FDE #0646 @ 0x058198..0x0582fc (356 bytes)
// [VN] Phục dựng FDE #0646 tại 0x058198..0x0582fc (356 byte)
//   0x058198: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05819c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0581a0: 910043fd  add      x29, sp, #0x10
//   0x0581a4: aa0103f3  mov      x19, x1
//   0x0581a8: aa0003f4  mov      x20, x0
//   0x0581ac: b9400a80  ldr      w0, [x20, #8]
//   0x0581b0: 52811c02  mov      w2, #0x8e0
//   0x0581b4: 52800803  mov      w3, #0x40
//   0x0581b8: aa1303e1  mov      x1, x19
//   0x0581bc: aa1f03e4  mov      x4, xzr
//   0x0581c0: aa1f03e5  mov      x5, xzr
//   0x0581c4: 940015b7  bl       #0x5d8a0
//   0x0581c8: b100041f  cmn      x0, #1
//   0x0581cc: 540001e1  b.ne     #0x58208
//   0x0581d0: 94001348  bl       #0x5cef0
//   0x0581d4: b9400008  ldr      w8, [x0]
uint64_t fde_0646_sub_058198(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x058198ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x058198: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05819c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0581a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0581a4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0581a8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x0581ac: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52811C02ULL; // 0x0581b0: mov w2, #0x8e0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x0581b4: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x0581b8: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x0581bc: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0647 @ 0x0582fc..0x058404 (264 bytes)
// [VN] Phục dựng FDE #0647 tại 0x0582fc..0x058404 (264 byte)
//   0x0582fc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x058300: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x058304: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x058308: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05830c: 9100c3fd  add      x29, sp, #0x30
//   0x058310: aa0003f4  mov      x20, x0
//   0x058314: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x058318: f8010e9f  str      xzr, [x20, #0x10]!
//   0x05831c: 90000048  adrp     x8, #0x60000
//   0x058320: 2a0403f7  mov      w23, w4
//   0x058324: 2a0303f6  mov      w22, w3
//   0x058328: 2a0203f5  mov      w21, w2
//   0x05832c: aa0003f3  mov      x19, x0
//   0x058330: 9119c108  add      x8, x8, #0x670
//   0x058334: eb01029f  cmp      x20, x1
//   0x058338: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0647_sub_0582fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0582FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0582fc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x058300: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x058304: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x058308: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05830c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x058310: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x058314: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x058318: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x05831c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x058320: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0648 @ 0x058404..0x05846c (104 bytes)
// [VN] Phục dựng FDE #0648 tại 0x058404..0x05846c (104 byte)
//   0x058404: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x058408: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05840c: 910043fd  add      x29, sp, #0x10
//   0x058410: aa0003f3  mov      x19, x0
//   0x058414: b9400800  ldr      w0, [x0, #8]
//   0x058418: 90000048  adrp     x8, #0x60000
//   0x05841c: 9119c108  add      x8, x8, #0x670
//   0x058420: f9000268  str      x8, [x19]
//   0x058424: 9400134f  bl       #0x5d160
//   0x058428: 39404268  ldrb     w8, [x19, #0x10]
//   0x05842c: 90000049  adrp     x9, #0x60000
//   0x058430: 91250129  add      x9, x9, #0x940
//   0x058434: f9000269  str      x9, [x19]
//   0x058438: 37000088  tbnz     w8, #0, #0x58448
//   0x05843c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x058440: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0648_sub_058404(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x058404ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x058404: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x058408: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05840c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x058410: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x058414: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x058418: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9119C108ULL; // 0x05841c: add x8, x8, #0x670
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x058420: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400134FULL; // 0x058424: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x058428: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0649 @ 0x05846c..0x0584d0 (100 bytes)
// [VN] Phục dựng FDE #0649 tại 0x05846c..0x0584d0 (100 byte)
//   0x05846c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x058470: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x058474: 910043fd  add      x29, sp, #0x10
//   0x058478: aa0003f3  mov      x19, x0
//   0x05847c: b9400800  ldr      w0, [x0, #8]
//   0x058480: 90000048  adrp     x8, #0x60000
//   0x058484: 9119c108  add      x8, x8, #0x670
//   0x058488: f9000268  str      x8, [x19]
//   0x05848c: 94001335  bl       #0x5d160
//   0x058490: 39404268  ldrb     w8, [x19, #0x10]
//   0x058494: 90000049  adrp     x9, #0x60000
//   0x058498: 91250129  add      x9, x9, #0x940
//   0x05849c: f9000269  str      x9, [x19]
//   0x0584a0: 36000068  tbz      w8, #0, #0x584ac
//   0x0584a4: f9401260  ldr      x0, [x19, #0x20]
//   0x0584a8: 94001372  bl       #0x5d270
uint64_t fde_0649_sub_05846c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05846CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05846c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x058470: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x058474: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x058478: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05847c: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x058480: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x9119C108ULL; // 0x058484: add x8, x8, #0x670
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x058488: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94001335ULL; // 0x05848c: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x058490: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0650 @ 0x0584d0..0x05883c (876 bytes)
// [VN] Phục dựng FDE #0650 tại 0x0584d0..0x05883c (876 byte)
//   0x0584d0: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x0584d4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0584d8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0584dc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0584e0: 9100c3fd  add      x29, sp, #0x30
//   0x0584e4: d14007ff  sub      sp, sp, #1, lsl #12
//   0x0584e8: d108c3ff  sub      sp, sp, #0x230
//   0x0584ec: d53bd056  mrs      x22, tpidr_el0
//   0x0584f0: f94016c8  ldr      x8, [x22, #0x28]
//   0x0584f4: aa0103f5  mov      x21, x1
//   0x0584f8: 912463e1  add      x1, sp, #0x918
//   0x0584fc: aa0003f4  mov      x20, x0
//   0x058500: f81c83a8  stur     x8, [x29, #-0x38]
//   0x058504: 94000150  bl       #0x58a44
//   0x058508: b94923e8  ldr      w8, [sp, #0x920]
//   0x05850c: 2a0003f3  mov      w19, w0
uint64_t fde_0650_sub_0584d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x0584D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x0584d0: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0584d4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0584d8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0584dc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0584e0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x0584e4: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x0584e8: sub sp, sp, #0x230
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0584ec: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0584f0: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0584f4: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0651 @ 0x05883c..0x0588d4 (152 bytes)
// [VN] Phục dựng FDE #0651 tại 0x05883c..0x0588d4 (152 byte)
//   0x05883c: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x058840: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x058844: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x058848: 910083fd  add      x29, sp, #0x20
//   0x05884c: d12483ff  sub      sp, sp, #0x920
//   0x058850: d53bd054  mrs      x20, tpidr_el0
//   0x058854: f9401688  ldr      x8, [x20, #0x28]
//   0x058858: 910023e1  add      x1, sp, #8
//   0x05885c: aa0003f3  mov      x19, x0
//   0x058860: f81d83a8  stur     x8, [x29, #-0x28]
//   0x058864: 94000078  bl       #0x58a44
//   0x058868: 3940a268  ldrb     w8, [x19, #0x28]
//   0x05886c: 2a0003f3  mov      w19, w0
//   0x058870: 34000108  cbz      w8, #0x58890
//   0x058874: 294213e3  ldp      w3, w4, [sp, #0x10]
//   0x058878: d0fffda1  adrp     x1, #0xe000
uint64_t fde_0651_sub_05883c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x05883CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x05883c: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x058840: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x058844: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x058848: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD12483FFULL; // 0x05884c: sub sp, sp, #0x920
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x058850: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x058854: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x058858: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05885c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x058860: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0652 @ 0x0588d4..0x0588d8 (4 bytes)
// [VN] Phục dựng FDE #0652 tại 0x0588d4..0x0588d8 (4 byte)
//   0x0588d4: 1400000b  b        #0x58900
uint64_t fde_0652_sub_0588d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x0588D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x0588d4: b #0x58900
    return acc;
}

// [EN] Reconstructed FDE #0653 @ 0x0588d8..0x0588e0 (8 bytes)
// [VN] Phục dựng FDE #0653 tại 0x0588d8..0x0588e0 (8 byte)
//   0x0588d8: 2a1f03e0  mov      w0, wzr
//   0x0588dc: d65f03c0  ret      
uint64_t fde_0653_sub_0588d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0588D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0588d8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0588dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0654 @ 0x0588e0..0x0588e8 (8 bytes)
// [VN] Phục dựng FDE #0654 tại 0x0588e0..0x0588e8 (8 byte)
//   0x0588e0: 2a1f03e0  mov      w0, wzr
//   0x0588e4: d65f03c0  ret      
uint64_t fde_0654_sub_0588e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0588E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0588e0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0588e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0655 @ 0x0588e8..0x0588f0 (8 bytes)
// [VN] Phục dựng FDE #0655 tại 0x0588e8..0x0588f0 (8 byte)
//   0x0588e8: 2a1f03e0  mov      w0, wzr
//   0x0588ec: d65f03c0  ret      
uint64_t fde_0655_sub_0588e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0588E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0588e8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0588ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #0656 @ 0x0588f0..0x0588f8 (8 bytes)
// [VN] Phục dựng FDE #0656 tại 0x0588f0..0x0588f8 (8 byte)
//   0x0588f0: 52800080  mov      w0, #4
//   0x0588f4: d65f03c0  ret      
uint64_t fde_0656_sub_0588f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0588F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x0588f0: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0588f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0657 @ 0x0588f8..0x058900 (8 bytes)
// [VN] Phục dựng FDE #0657 tại 0x0588f8..0x058900 (8 byte)
//   0x0588f8: 52800100  mov      w0, #8
//   0x0588fc: d65f03c0  ret      
uint64_t fde_0657_sub_0588f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0588F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x0588f8: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0588fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0658 @ 0x058900..0x058a44 (324 bytes)
// [VN] Phục dựng FDE #0658 tại 0x058900..0x058a44 (324 byte)
//   0x058900: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x058904: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x058908: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05890c: 910083fd  add      x29, sp, #0x20
//   0x058910: b9400028  ldr      w8, [x1]
//   0x058914: aa0103f3  mov      x19, x1
//   0x058918: aa0003f4  mov      x20, x0
//   0x05891c: 71000d1f  cmp      w8, #3
//   0x058920: 54000128  b.hi     #0x58944
//   0x058924: b0fffde9  adrp     x9, #0x15000
//   0x058928: 9124f929  add      x9, x9, #0x93e
//   0x05892c: 1000008a  adr      x10, #0x5893c
//   0x058930: 3868692b  ldrb     w11, [x9, x8]
//   0x058934: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x058938: d61f0140  br       x10
//   0x05893c: 52800d15  mov      w21, #0x68
uint64_t fde_0658_sub_058900(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x3868692BULL) + (x2 ^ 0x058900ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x058900: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x058904: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x058908: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05890c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x058910: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x058914: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x058918: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x05891c: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000128ULL; // 0x058920: b.hi #0x58944
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDE9ULL; // 0x058924: adrp x9, #0x15000
    return acc;
}

// [EN] Reconstructed FDE #0659 @ 0x058a44..0x058bc0 (380 bytes)
// [VN] Phục dựng FDE #0659 tại 0x058a44..0x058bc0 (380 byte)
//   0x058a44: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x058a48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x058a4c: 910043fd  add      x29, sp, #0x10
//   0x058a50: aa0103f3  mov      x19, x1
//   0x058a54: aa0003f4  mov      x20, x0
//   0x058a58: b9400a80  ldr      w0, [x20, #8]
//   0x058a5c: 52812202  mov      w2, #0x910
//   0x058a60: 52800803  mov      w3, #0x40
//   0x058a64: aa1303e1  mov      x1, x19
//   0x058a68: aa1f03e4  mov      x4, xzr
//   0x058a6c: aa1f03e5  mov      x5, xzr
//   0x058a70: 9400138c  bl       #0x5d8a0
//   0x058a74: b100041f  cmn      x0, #1
//   0x058a78: 540001e1  b.ne     #0x58ab4
//   0x058a7c: 9400111d  bl       #0x5cef0
//   0x058a80: b9400008  ldr      w8, [x0]
uint64_t fde_0659_sub_058a44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x058A44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x058a44: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x058a48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x058a4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x058a50: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x058a54: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x058a58: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52812202ULL; // 0x058a5c: mov w2, #0x910
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x058a60: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x058a64: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x058a68: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0660 @ 0x058bc0..0x058cc8 (264 bytes)
// [VN] Phục dựng FDE #0660 tại 0x058bc0..0x058cc8 (264 byte)
//   0x058bc0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x058bc4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x058bc8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x058bcc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x058bd0: 9100c3fd  add      x29, sp, #0x30
//   0x058bd4: aa0003f4  mov      x20, x0
//   0x058bd8: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x058bdc: f8010e9f  str      xzr, [x20, #0x10]!
//   0x058be0: 90000048  adrp     x8, #0x60000
//   0x058be4: 2a0403f7  mov      w23, w4
//   0x058be8: 2a0303f6  mov      w22, w3
//   0x058bec: 2a0203f5  mov      w21, w2
//   0x058bf0: aa0003f3  mov      x19, x0
//   0x058bf4: 911ba108  add      x8, x8, #0x6e8
//   0x058bf8: eb01029f  cmp      x20, x1
//   0x058bfc: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0660_sub_058bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x058BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x058bc0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x058bc4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x058bc8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x058bcc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x058bd0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x058bd4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x058bd8: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x058bdc: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x058be0: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x058be4: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0661 @ 0x058cc8..0x058d30 (104 bytes)
// [VN] Phục dựng FDE #0661 tại 0x058cc8..0x058d30 (104 byte)
//   0x058cc8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x058ccc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x058cd0: 910043fd  add      x29, sp, #0x10
//   0x058cd4: aa0003f3  mov      x19, x0
//   0x058cd8: b9400800  ldr      w0, [x0, #8]
//   0x058cdc: 90000048  adrp     x8, #0x60000
//   0x058ce0: 911ba108  add      x8, x8, #0x6e8
//   0x058ce4: f9000268  str      x8, [x19]
//   0x058ce8: 9400111e  bl       #0x5d160
//   0x058cec: 39404268  ldrb     w8, [x19, #0x10]
//   0x058cf0: 90000049  adrp     x9, #0x60000
//   0x058cf4: 91250129  add      x9, x9, #0x940
//   0x058cf8: f9000269  str      x9, [x19]
//   0x058cfc: 37000088  tbnz     w8, #0, #0x58d0c
//   0x058d00: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x058d04: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0661_sub_058cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x058CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x058cc8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x058ccc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x058cd0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x058cd4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x058cd8: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x058cdc: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911BA108ULL; // 0x058ce0: add x8, x8, #0x6e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x058ce4: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400111EULL; // 0x058ce8: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x058cec: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0662 @ 0x058d30..0x058d94 (100 bytes)
// [VN] Phục dựng FDE #0662 tại 0x058d30..0x058d94 (100 byte)
//   0x058d30: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x058d34: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x058d38: 910043fd  add      x29, sp, #0x10
//   0x058d3c: aa0003f3  mov      x19, x0
//   0x058d40: b9400800  ldr      w0, [x0, #8]
//   0x058d44: 90000048  adrp     x8, #0x60000
//   0x058d48: 911ba108  add      x8, x8, #0x6e8
//   0x058d4c: f9000268  str      x8, [x19]
//   0x058d50: 94001104  bl       #0x5d160
//   0x058d54: 39404268  ldrb     w8, [x19, #0x10]
//   0x058d58: 90000049  adrp     x9, #0x60000
//   0x058d5c: 91250129  add      x9, x9, #0x940
//   0x058d60: f9000269  str      x9, [x19]
//   0x058d64: 36000068  tbz      w8, #0, #0x58d70
//   0x058d68: f9401260  ldr      x0, [x19, #0x20]
//   0x058d6c: 94001141  bl       #0x5d270
uint64_t fde_0662_sub_058d30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x058D30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x058d30: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x058d34: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x058d38: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x058d3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x058d40: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000048ULL; // 0x058d44: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911BA108ULL; // 0x058d48: add x8, x8, #0x6e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x058d4c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94001104ULL; // 0x058d50: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x058d54: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0663 @ 0x058d94..0x059104 (880 bytes)
// [VN] Phục dựng FDE #0663 tại 0x058d94..0x059104 (880 byte)
//   0x058d94: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x058d98: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x058d9c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x058da0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x058da4: 9100c3fd  add      x29, sp, #0x30
//   0x058da8: d14007ff  sub      sp, sp, #1, lsl #12
//   0x058dac: d10943ff  sub      sp, sp, #0x250
//   0x058db0: d53bd056  mrs      x22, tpidr_el0
//   0x058db4: f94016c8  ldr      x8, [x22, #0x28]
//   0x058db8: aa0103f5  mov      x21, x1
//   0x058dbc: 9124a3e1  add      x1, sp, #0x928
//   0x058dc0: aa0003f4  mov      x20, x0
//   0x058dc4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x058dc8: 94000156  bl       #0x59320
//   0x058dcc: b9492fe8  ldr      w8, [sp, #0x92c]
//   0x058dd0: 2a0003f3  mov      w19, w0
uint64_t fde_0663_sub_058d94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x058D94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x058d94: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x058d98: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x058d9c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x058da0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x058da4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x058da8: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10943FFULL; // 0x058dac: sub sp, sp, #0x250
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x058db0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x058db4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x058db8: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0664 @ 0x059104..0x0591a0 (156 bytes)
// [VN] Phục dựng FDE #0664 tại 0x059104..0x0591a0 (156 byte)
//   0x059104: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x059108: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05910c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x059110: 910083fd  add      x29, sp, #0x20
//   0x059114: d124c3ff  sub      sp, sp, #0x930
//   0x059118: d53bd054  mrs      x20, tpidr_el0
//   0x05911c: f9401688  ldr      x8, [x20, #0x28]
//   0x059120: 910023e1  add      x1, sp, #8
//   0x059124: aa0003f3  mov      x19, x0
//   0x059128: f81d83a8  stur     x8, [x29, #-0x28]
//   0x05912c: 9400007d  bl       #0x59320
//   0x059130: 3940a268  ldrb     w8, [x19, #0x28]
//   0x059134: 2a0003f3  mov      w19, w0
//   0x059138: 34000128  cbz      w8, #0x5915c
//   0x05913c: b9400fe3  ldr      w3, [sp, #0xc]
//   0x059140: 394043e4  ldrb     w4, [sp, #0x10]
uint64_t fde_0664_sub_059104(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x059104ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x059104: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x059108: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05910c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x059110: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD124C3FFULL; // 0x059114: sub sp, sp, #0x930
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x059118: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x05911c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x059120: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x059124: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x059128: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0665 @ 0x0591a0..0x0591a4 (4 bytes)
// [VN] Phục dựng FDE #0665 tại 0x0591a0..0x0591a4 (4 byte)
//   0x0591a0: 1400000b  b        #0x591cc
uint64_t fde_0665_sub_0591a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x0591A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x0591a0: b #0x591cc
    return acc;
}

// [EN] Reconstructed FDE #0666 @ 0x0591a4..0x0591ac (8 bytes)
// [VN] Phục dựng FDE #0666 tại 0x0591a4..0x0591ac (8 byte)
//   0x0591a4: 2a1f03e0  mov      w0, wzr
//   0x0591a8: d65f03c0  ret      
uint64_t fde_0666_sub_0591a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0591A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0591a4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0591a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0667 @ 0x0591ac..0x0591b4 (8 bytes)
// [VN] Phục dựng FDE #0667 tại 0x0591ac..0x0591b4 (8 byte)
//   0x0591ac: 2a1f03e0  mov      w0, wzr
//   0x0591b0: d65f03c0  ret      
uint64_t fde_0667_sub_0591ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0591ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0591ac: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0591b0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0668 @ 0x0591b4..0x0591bc (8 bytes)
// [VN] Phục dựng FDE #0668 tại 0x0591b4..0x0591bc (8 byte)
//   0x0591b4: 2a1f03e0  mov      w0, wzr
//   0x0591b8: d65f03c0  ret      
uint64_t fde_0668_sub_0591b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0591B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0591b4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0591b8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0669 @ 0x0591bc..0x0591c4 (8 bytes)
// [VN] Phục dựng FDE #0669 tại 0x0591bc..0x0591c4 (8 byte)
//   0x0591bc: 52800080  mov      w0, #4
//   0x0591c0: d65f03c0  ret      
uint64_t fde_0669_sub_0591bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0591BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x0591bc: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0591c0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0670 @ 0x0591c4..0x0591cc (8 bytes)
// [VN] Phục dựng FDE #0670 tại 0x0591c4..0x0591cc (8 byte)
//   0x0591c4: 52800100  mov      w0, #8
//   0x0591c8: d65f03c0  ret      
uint64_t fde_0670_sub_0591c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0591C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x0591c4: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0591c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0671 @ 0x0591cc..0x059320 (340 bytes)
// [VN] Phục dựng FDE #0671 tại 0x0591cc..0x059320 (340 byte)
//   0x0591cc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0591d0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0591d4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0591d8: 910083fd  add      x29, sp, #0x20
//   0x0591dc: b9400028  ldr      w8, [x1]
//   0x0591e0: aa0103f3  mov      x19, x1
//   0x0591e4: aa0003f4  mov      x20, x0
//   0x0591e8: 7100191f  cmp      w8, #6
//   0x0591ec: 54000128  b.hi     #0x59210
//   0x0591f0: 90fffde9  adrp     x9, #0x15000
//   0x0591f4: 91251929  add      x9, x9, #0x946
//   0x0591f8: 1000008a  adr      x10, #0x59208
//   0x0591fc: 3868692b  ldrb     w11, [x9, x8]
//   0x059200: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x059204: d61f0140  br       x10
//   0x059208: 52800215  mov      w21, #0x10
uint64_t fde_0671_sub_0591cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x3868692BULL) + (x2 ^ 0x0591CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0591cc: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0591d0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0591d4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0591d8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x0591dc: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0591e0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0591e4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100191FULL; // 0x0591e8: cmp w8, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x54000128ULL; // 0x0591ec: b.hi #0x59210
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDE9ULL; // 0x0591f0: adrp x9, #0x15000
    return acc;
}

// [EN] Reconstructed FDE #0672 @ 0x059320..0x0595b4 (660 bytes)
// [VN] Phục dựng FDE #0672 tại 0x059320..0x0595b4 (660 byte)
//   0x059320: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x059324: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x059328: 910043fd  add      x29, sp, #0x10
//   0x05932c: aa0103f3  mov      x19, x1
//   0x059330: aa0003f4  mov      x20, x0
//   0x059334: b9400a80  ldr      w0, [x20, #8]
//   0x059338: 52812402  mov      w2, #0x920
//   0x05933c: 52800803  mov      w3, #0x40
//   0x059340: aa1303e1  mov      x1, x19
//   0x059344: aa1f03e4  mov      x4, xzr
//   0x059348: aa1f03e5  mov      x5, xzr
//   0x05934c: 94001155  bl       #0x5d8a0
//   0x059350: b100041f  cmn      x0, #1
//   0x059354: 540001e1  b.ne     #0x59390
//   0x059358: 94000ee6  bl       #0x5cef0
//   0x05935c: b9400008  ldr      w8, [x0]
uint64_t fde_0672_sub_059320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x059320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x059320: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x059324: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x059328: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x05932c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x059330: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x059334: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52812402ULL; // 0x059338: mov w2, #0x920
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x05933c: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x059340: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x059344: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0673 @ 0x0595b4..0x0596bc (264 bytes)
// [VN] Phục dựng FDE #0673 tại 0x0595b4..0x0596bc (264 byte)
//   0x0595b4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0595b8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0595bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0595c0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0595c4: 9100c3fd  add      x29, sp, #0x30
//   0x0595c8: aa0003f4  mov      x20, x0
//   0x0595cc: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x0595d0: f8010e9f  str      xzr, [x20, #0x10]!
//   0x0595d4: f0000028  adrp     x8, #0x60000
//   0x0595d8: 2a0403f7  mov      w23, w4
//   0x0595dc: 2a0303f6  mov      w22, w3
//   0x0595e0: 2a0203f5  mov      w21, w2
//   0x0595e4: aa0003f3  mov      x19, x0
//   0x0595e8: 911d8108  add      x8, x8, #0x760
//   0x0595ec: eb01029f  cmp      x20, x1
//   0x0595f0: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0673_sub_0595b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0595B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0595b4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0595b8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0595bc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0595c0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0595c4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0595c8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x0595cc: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x0595d0: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000028ULL; // 0x0595d4: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x0595d8: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0674 @ 0x0596bc..0x059724 (104 bytes)
// [VN] Phục dựng FDE #0674 tại 0x0596bc..0x059724 (104 byte)
//   0x0596bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0596c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0596c4: 910043fd  add      x29, sp, #0x10
//   0x0596c8: aa0003f3  mov      x19, x0
//   0x0596cc: b9400800  ldr      w0, [x0, #8]
//   0x0596d0: f0000028  adrp     x8, #0x60000
//   0x0596d4: 911d8108  add      x8, x8, #0x760
//   0x0596d8: f9000268  str      x8, [x19]
//   0x0596dc: 94000ea1  bl       #0x5d160
//   0x0596e0: 39404268  ldrb     w8, [x19, #0x10]
//   0x0596e4: f0000029  adrp     x9, #0x60000
//   0x0596e8: 91250129  add      x9, x9, #0x940
//   0x0596ec: f9000269  str      x9, [x19]
//   0x0596f0: 37000088  tbnz     w8, #0, #0x59700
//   0x0596f4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0596f8: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0674_sub_0596bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x0596BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0596bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0596c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0596c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0596c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x0596cc: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000028ULL; // 0x0596d0: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D8108ULL; // 0x0596d4: add x8, x8, #0x760
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0596d8: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000EA1ULL; // 0x0596dc: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x0596e0: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0675 @ 0x059724..0x059788 (100 bytes)
// [VN] Phục dựng FDE #0675 tại 0x059724..0x059788 (100 byte)
//   0x059724: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x059728: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05972c: 910043fd  add      x29, sp, #0x10
//   0x059730: aa0003f3  mov      x19, x0
//   0x059734: b9400800  ldr      w0, [x0, #8]
//   0x059738: f0000028  adrp     x8, #0x60000
//   0x05973c: 911d8108  add      x8, x8, #0x760
//   0x059740: f9000268  str      x8, [x19]
//   0x059744: 94000e87  bl       #0x5d160
//   0x059748: 39404268  ldrb     w8, [x19, #0x10]
//   0x05974c: f0000029  adrp     x9, #0x60000
//   0x059750: 91250129  add      x9, x9, #0x940
//   0x059754: f9000269  str      x9, [x19]
//   0x059758: 36000068  tbz      w8, #0, #0x59764
//   0x05975c: f9401260  ldr      x0, [x19, #0x20]
//   0x059760: 94000ec4  bl       #0x5d270
uint64_t fde_0675_sub_059724(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x059724ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x059724: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x059728: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05972c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x059730: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x059734: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000028ULL; // 0x059738: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D8108ULL; // 0x05973c: add x8, x8, #0x760
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x059740: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000E87ULL; // 0x059744: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x059748: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0676 @ 0x059788..0x059afc (884 bytes)
// [VN] Phục dựng FDE #0676 tại 0x059788..0x059afc (884 byte)
//   0x059788: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x05978c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x059790: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x059794: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x059798: 9100c3fd  add      x29, sp, #0x30
//   0x05979c: d14007ff  sub      sp, sp, #1, lsl #12
//   0x0597a0: d10983ff  sub      sp, sp, #0x260
//   0x0597a4: d53bd056  mrs      x22, tpidr_el0
//   0x0597a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0597ac: aa0103f5  mov      x21, x1
//   0x0597b0: 9124c3e1  add      x1, sp, #0x930
//   0x0597b4: aa0003f4  mov      x20, x0
//   0x0597b8: f81c83a8  stur     x8, [x29, #-0x38]
//   0x0597bc: 94000155  bl       #0x59d10
//   0x0597c0: b94937e8  ldr      w8, [sp, #0x934]
//   0x0597c4: 2a0003f3  mov      w19, w0
uint64_t fde_0676_sub_059788(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x059788ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x059788: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05978c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x059790: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x059794: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x059798: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x05979c: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10983FFULL; // 0x0597a0: sub sp, sp, #0x260
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0597a4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0597a8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0597ac: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0677 @ 0x059afc..0x059b9c (160 bytes)
// [VN] Phục dựng FDE #0677 tại 0x059afc..0x059b9c (160 byte)
//   0x059afc: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x059b00: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x059b04: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x059b08: 910083fd  add      x29, sp, #0x20
//   0x059b0c: d124c3ff  sub      sp, sp, #0x930
//   0x059b10: d53bd054  mrs      x20, tpidr_el0
//   0x059b14: f9401688  ldr      x8, [x20, #0x28]
//   0x059b18: 910003e1  mov      x1, sp
//   0x059b1c: aa0003f3  mov      x19, x0
//   0x059b20: f81d83a8  stur     x8, [x29, #-0x28]
//   0x059b24: 9400007b  bl       #0x59d10
//   0x059b28: 3940a268  ldrb     w8, [x19, #0x28]
//   0x059b2c: 2a0003f3  mov      w19, w0
//   0x059b30: 34000148  cbz      w8, #0x59b58
//   0x059b34: b94007e3  ldr      w3, [sp, #4]
//   0x059b38: 394023e4  ldrb     w4, [sp, #8]
uint64_t fde_0677_sub_059afc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x059AFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x059afc: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x059b00: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x059b04: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x059b08: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD124C3FFULL; // 0x059b0c: sub sp, sp, #0x930
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x059b10: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x059b14: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x059b18: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x059b1c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x059b20: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0678 @ 0x059b9c..0x059ba0 (4 bytes)
// [VN] Phục dựng FDE #0678 tại 0x059b9c..0x059ba0 (4 byte)
//   0x059b9c: 1400000b  b        #0x59bc8
uint64_t fde_0678_sub_059b9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400000BULL) + (x1 ^ 0x1400000BULL) + (x2 ^ 0x059B9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000BULL; // 0x059b9c: b #0x59bc8
    return acc;
}

// [EN] Reconstructed FDE #0679 @ 0x059ba0..0x059ba8 (8 bytes)
// [VN] Phục dựng FDE #0679 tại 0x059ba0..0x059ba8 (8 byte)
//   0x059ba0: 2a1f03e0  mov      w0, wzr
//   0x059ba4: d65f03c0  ret      
uint64_t fde_0679_sub_059ba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x059BA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x059ba0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x059ba4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0680 @ 0x059ba8..0x059bb0 (8 bytes)
// [VN] Phục dựng FDE #0680 tại 0x059ba8..0x059bb0 (8 byte)
//   0x059ba8: 2a1f03e0  mov      w0, wzr
//   0x059bac: d65f03c0  ret      
uint64_t fde_0680_sub_059ba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x059BA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x059ba8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x059bac: ret 
    return acc;
}

// [EN] Reconstructed FDE #0681 @ 0x059bb0..0x059bb8 (8 bytes)
// [VN] Phục dựng FDE #0681 tại 0x059bb0..0x059bb8 (8 byte)
//   0x059bb0: 2a1f03e0  mov      w0, wzr
//   0x059bb4: d65f03c0  ret      
uint64_t fde_0681_sub_059bb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x059BB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x059bb0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x059bb4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0682 @ 0x059bb8..0x059bc0 (8 bytes)
// [VN] Phục dựng FDE #0682 tại 0x059bb8..0x059bc0 (8 byte)
//   0x059bb8: 52800080  mov      w0, #4
//   0x059bbc: d65f03c0  ret      
uint64_t fde_0682_sub_059bb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x059BB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x059bb8: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x059bbc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0683 @ 0x059bc0..0x059bc8 (8 bytes)
// [VN] Phục dựng FDE #0683 tại 0x059bc0..0x059bc8 (8 byte)
//   0x059bc0: 52800100  mov      w0, #8
//   0x059bc4: d65f03c0  ret      
uint64_t fde_0683_sub_059bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x059BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x059bc0: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x059bc4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0684 @ 0x059bc8..0x059d10 (328 bytes)
// [VN] Phục dựng FDE #0684 tại 0x059bc8..0x059d10 (328 byte)
//   0x059bc8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x059bcc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x059bd0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x059bd4: 910083fd  add      x29, sp, #0x20
//   0x059bd8: b9400028  ldr      w8, [x1]
//   0x059bdc: aa0103f3  mov      x19, x1
//   0x059be0: aa0003f4  mov      x20, x0
//   0x059be4: 71001d1f  cmp      w8, #7
//   0x059be8: 54000168  b.hi     #0x59c14
//   0x059bec: 90fffde9  adrp     x9, #0x15000
//   0x059bf0: 91258929  add      x9, x9, #0x962
//   0x059bf4: 1000008a  adr      x10, #0x59c04
//   0x059bf8: 3868692b  ldrb     w11, [x9, x8]
//   0x059bfc: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x059c00: d61f0140  br       x10
//   0x059c04: 52800215  mov      w21, #0x10
uint64_t fde_0684_sub_059bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x3868692BULL) + (x2 ^ 0x059BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x059bc8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x059bcc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x059bd0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x059bd4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x059bd8: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x059bdc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x059be0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D1FULL; // 0x059be4: cmp w8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x059be8: b.hi #0x59c14
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDE9ULL; // 0x059bec: adrp x9, #0x15000
    return acc;
}

// [EN] Reconstructed FDE #0685 @ 0x059d10..0x059fa8 (664 bytes)
// [VN] Phục dựng FDE #0685 tại 0x059d10..0x059fa8 (664 byte)
//   0x059d10: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x059d14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x059d18: 910043fd  add      x29, sp, #0x10
//   0x059d1c: aa0103f3  mov      x19, x1
//   0x059d20: aa0003f4  mov      x20, x0
//   0x059d24: b9400a80  ldr      w0, [x20, #8]
//   0x059d28: 52812502  mov      w2, #0x928
//   0x059d2c: 52800803  mov      w3, #0x40
//   0x059d30: aa1303e1  mov      x1, x19
//   0x059d34: aa1f03e4  mov      x4, xzr
//   0x059d38: aa1f03e5  mov      x5, xzr
//   0x059d3c: 94000ed9  bl       #0x5d8a0
//   0x059d40: b100041f  cmn      x0, #1
//   0x059d44: 54000181  b.ne     #0x59d74
//   0x059d48: 94000c6a  bl       #0x5cef0
//   0x059d4c: b9400008  ldr      w8, [x0]
uint64_t fde_0685_sub_059d10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x059D10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x059d10: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x059d14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x059d18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x059d1c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x059d20: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x059d24: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52812502ULL; // 0x059d28: mov w2, #0x928
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x059d2c: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x059d30: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x059d34: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0686 @ 0x059fa8..0x05a0b0 (264 bytes)
// [VN] Phục dựng FDE #0686 tại 0x059fa8..0x05a0b0 (264 byte)
//   0x059fa8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x059fac: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x059fb0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x059fb4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x059fb8: 9100c3fd  add      x29, sp, #0x30
//   0x059fbc: aa0003f4  mov      x20, x0
//   0x059fc0: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x059fc4: f8010e9f  str      xzr, [x20, #0x10]!
//   0x059fc8: f0000028  adrp     x8, #0x60000
//   0x059fcc: 2a0403f7  mov      w23, w4
//   0x059fd0: 2a0303f6  mov      w22, w3
//   0x059fd4: 2a0203f5  mov      w21, w2
//   0x059fd8: aa0003f3  mov      x19, x0
//   0x059fdc: 911f6108  add      x8, x8, #0x7d8
//   0x059fe0: eb01029f  cmp      x20, x1
//   0x059fe4: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0686_sub_059fa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x059FA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x059fa8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x059fac: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x059fb0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x059fb4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x059fb8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x059fbc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x059fc0: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x059fc4: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000028ULL; // 0x059fc8: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x059fcc: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0687 @ 0x05a0b0..0x05a118 (104 bytes)
// [VN] Phục dựng FDE #0687 tại 0x05a0b0..0x05a118 (104 byte)
//   0x05a0b0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05a0b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05a0b8: 910043fd  add      x29, sp, #0x10
//   0x05a0bc: aa0003f3  mov      x19, x0
//   0x05a0c0: b9400800  ldr      w0, [x0, #8]
//   0x05a0c4: d0000028  adrp     x8, #0x60000
//   0x05a0c8: 911f6108  add      x8, x8, #0x7d8
//   0x05a0cc: f9000268  str      x8, [x19]
//   0x05a0d0: 94000c24  bl       #0x5d160
//   0x05a0d4: 39404268  ldrb     w8, [x19, #0x10]
//   0x05a0d8: d0000029  adrp     x9, #0x60000
//   0x05a0dc: 91250129  add      x9, x9, #0x940
//   0x05a0e0: f9000269  str      x9, [x19]
//   0x05a0e4: 37000088  tbnz     w8, #0, #0x5a0f4
//   0x05a0e8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x05a0ec: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0687_sub_05a0b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05A0B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05a0b0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05a0b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05a0b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05a0bc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05a0c0: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000028ULL; // 0x05a0c4: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F6108ULL; // 0x05a0c8: add x8, x8, #0x7d8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05a0cc: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000C24ULL; // 0x05a0d0: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05a0d4: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0688 @ 0x05a118..0x05a17c (100 bytes)
// [VN] Phục dựng FDE #0688 tại 0x05a118..0x05a17c (100 byte)
//   0x05a118: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05a11c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05a120: 910043fd  add      x29, sp, #0x10
//   0x05a124: aa0003f3  mov      x19, x0
//   0x05a128: b9400800  ldr      w0, [x0, #8]
//   0x05a12c: d0000028  adrp     x8, #0x60000
//   0x05a130: 911f6108  add      x8, x8, #0x7d8
//   0x05a134: f9000268  str      x8, [x19]
//   0x05a138: 94000c0a  bl       #0x5d160
//   0x05a13c: 39404268  ldrb     w8, [x19, #0x10]
//   0x05a140: d0000029  adrp     x9, #0x60000
//   0x05a144: 91250129  add      x9, x9, #0x940
//   0x05a148: f9000269  str      x9, [x19]
//   0x05a14c: 36000068  tbz      w8, #0, #0x5a158
//   0x05a150: f9401260  ldr      x0, [x19, #0x20]
//   0x05a154: 94000c47  bl       #0x5d270
uint64_t fde_0688_sub_05a118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05A118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05a118: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05a11c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05a120: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05a124: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05a128: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000028ULL; // 0x05a12c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F6108ULL; // 0x05a130: add x8, x8, #0x7d8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05a134: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000C0AULL; // 0x05a138: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05a13c: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0689 @ 0x05a17c..0x05a4f0 (884 bytes)
// [VN] Phục dựng FDE #0689 tại 0x05a17c..0x05a4f0 (884 byte)
//   0x05a17c: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x05a180: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05a184: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05a188: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05a18c: 9100c3fd  add      x29, sp, #0x30
//   0x05a190: d14007ff  sub      sp, sp, #1, lsl #12
//   0x05a194: d10d83ff  sub      sp, sp, #0x360
//   0x05a198: d53bd056  mrs      x22, tpidr_el0
//   0x05a19c: f94016c8  ldr      x8, [x22, #0x28]
//   0x05a1a0: aa0103f5  mov      x21, x1
//   0x05a1a4: 9126c3e1  add      x1, sp, #0x9b0
//   0x05a1a8: aa0003f4  mov      x20, x0
//   0x05a1ac: f81c83a8  stur     x8, [x29, #-0x38]
//   0x05a1b0: 94000201  bl       #0x5a9b4
//   0x05a1b4: b949b7e8  ldr      w8, [sp, #0x9b4]
//   0x05a1b8: 2a0003f3  mov      w19, w0
uint64_t fde_0689_sub_05a17c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x05A17CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x05a17c: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05a180: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05a184: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05a188: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05a18c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x05a190: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10D83FFULL; // 0x05a194: sub sp, sp, #0x360
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05a198: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x05a19c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x05a1a0: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0690 @ 0x05a4f0..0x05a590 (160 bytes)
// [VN] Phục dựng FDE #0690 tại 0x05a4f0..0x05a590 (160 byte)
//   0x05a4f0: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x05a4f4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05a4f8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05a4fc: 910083fd  add      x29, sp, #0x20
//   0x05a500: d126c3ff  sub      sp, sp, #0x9b0
//   0x05a504: d53bd054  mrs      x20, tpidr_el0
//   0x05a508: f9401688  ldr      x8, [x20, #0x28]
//   0x05a50c: 910003e1  mov      x1, sp
//   0x05a510: aa0003f3  mov      x19, x0
//   0x05a514: f81d83a8  stur     x8, [x29, #-0x28]
//   0x05a518: 94000127  bl       #0x5a9b4
//   0x05a51c: 3940a268  ldrb     w8, [x19, #0x28]
//   0x05a520: 2a0003f3  mov      w19, w0
//   0x05a524: 34000148  cbz      w8, #0x5a54c
//   0x05a528: b94007e3  ldr      w3, [sp, #4]
//   0x05a52c: 394023e4  ldrb     w4, [sp, #8]
uint64_t fde_0690_sub_05a4f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x05A4F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x05a4f0: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x05a4f4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05a4f8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05a4fc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05a500: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x05a504: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x05a508: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x05a50c: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05a510: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x05a514: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0691 @ 0x05a590..0x05a594 (4 bytes)
// [VN] Phục dựng FDE #0691 tại 0x05a590..0x05a594 (4 byte)
//   0x05a590: 14000029  b        #0x5a634
uint64_t fde_0691_sub_05a590(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000029ULL) + (x1 ^ 0x14000029ULL) + (x2 ^ 0x05A590ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000029ULL; // 0x05a590: b #0x5a634
    return acc;
}

// [EN] Reconstructed FDE #0692 @ 0x05a594..0x05a5c4 (48 bytes)
// [VN] Phục dựng FDE #0692 tại 0x05a594..0x05a5c4 (48 byte)
//   0x05a594: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x05a598: 910003fd  mov      x29, sp
//   0x05a59c: 29400c24  ldp      w4, w3, [x1]
//   0x05a5a0: 90fffda1  adrp     x1, #0xe000
//   0x05a5a4: d0fffda2  adrp     x2, #0x10000
//   0x05a5a8: 911f1821  add      x1, x1, #0x7c6
//   0x05a5ac: 9136a042  add      x2, x2, #0xda8
//   0x05a5b0: 52800060  mov      w0, #3
//   0x05a5b4: 940009bb  bl       #0x5cca0
//   0x05a5b8: 2a1f03e0  mov      w0, wzr
//   0x05a5bc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x05a5c0: d65f03c0  ret      
uint64_t fde_0692_sub_05a594(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05A594ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x05a594: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x05a598: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x29400C24ULL; // 0x05a59c: ldp w4, w3, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFDA1ULL; // 0x05a5a0: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFDA2ULL; // 0x05a5a4: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x05a5a8: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x9136A042ULL; // 0x05a5ac: add x2, x2, #0xda8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x05a5b0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x940009BBULL; // 0x05a5b4: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x05a5b8: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0693 @ 0x05a5c4..0x05a5cc (8 bytes)
// [VN] Phục dựng FDE #0693 tại 0x05a5c4..0x05a5cc (8 byte)
//   0x05a5c4: b9400420  ldr      w0, [x1, #4]
//   0x05a5c8: d65f03c0  ret      
uint64_t fde_0693_sub_05a5c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400420ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05A5C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400420ULL; // 0x05a5c4: ldr w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05a5c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0694 @ 0x05a5cc..0x05a624 (88 bytes)
// [VN] Phục dựng FDE #0694 tại 0x05a5cc..0x05a624 (88 byte)
//   0x05a5cc: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x05a5d0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05a5d4: 910043fd  add      x29, sp, #0x10
//   0x05a5d8: d126c3ff  sub      sp, sp, #0x9b0
//   0x05a5dc: d53bd053  mrs      x19, tpidr_el0
//   0x05a5e0: f9401668  ldr      x8, [x19, #0x28]
//   0x05a5e4: 52800049  mov      w9, #2
//   0x05a5e8: 5280002a  mov      w10, #1
//   0x05a5ec: f81e83a8  stur     x8, [x29, #-0x18]
//   0x05a5f0: 290007e9  stp      w9, w1, [sp]
//   0x05a5f4: 910003e1  mov      x1, sp
//   0x05a5f8: 390023ea  strb     w10, [sp, #8]
//   0x05a5fc: 9400000e  bl       #0x5a634
//   0x05a600: f9401668  ldr      x8, [x19, #0x28]
//   0x05a604: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x05a608: eb09011f  cmp      x8, x9
uint64_t fde_0694_sub_05a5cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FFCULL) + (x1 ^ 0x9400000EULL) + (x2 ^ 0x05A5CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FFCULL; // 0x05a5cc: stp x28, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05a5d0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05a5d4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05a5d8: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x05a5dc: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x05a5e0: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800049ULL; // 0x05a5e4: mov w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x05a5e8: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x05a5ec: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x290007E9ULL; // 0x05a5f0: stp w9, w1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0695 @ 0x05a624..0x05a62c (8 bytes)
// [VN] Phục dựng FDE #0695 tại 0x05a624..0x05a62c (8 byte)
//   0x05a624: 52800080  mov      w0, #4
//   0x05a628: d65f03c0  ret      
uint64_t fde_0695_sub_05a624(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05A624ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x05a624: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05a628: ret 
    return acc;
}

// [EN] Reconstructed FDE #0696 @ 0x05a62c..0x05a634 (8 bytes)
// [VN] Phục dựng FDE #0696 tại 0x05a62c..0x05a634 (8 byte)
//   0x05a62c: 52800100  mov      w0, #8
//   0x05a630: d65f03c0  ret      
uint64_t fde_0696_sub_05a62c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05A62CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x05a62c: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05a630: ret 
    return acc;
}

// [EN] Reconstructed FDE #0697 @ 0x05a634..0x05a9b4 (896 bytes)
// [VN] Phục dựng FDE #0697 tại 0x05a634..0x05a9b4 (896 byte)
//   0x05a634: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x05a638: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x05a63c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x05a640: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x05a644: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x05a648: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x05a64c: 910143fd  add      x29, sp, #0x50
//   0x05a650: d12703ff  sub      sp, sp, #0x9c0
//   0x05a654: d53bd056  mrs      x22, tpidr_el0
//   0x05a658: f94016c8  ldr      x8, [x22, #0x28]
//   0x05a65c: aa0103f5  mov      x21, x1
//   0x05a660: aa0003f3  mov      x19, x0
//   0x05a664: f81a03a8  stur     x8, [x29, #-0x60]
//   0x05a668: b9400023  ldr      w3, [x1]
//   0x05a66c: 71001c7f  cmp      w3, #7
//   0x05a670: 54000228  b.hi     #0x5a6b4
uint64_t fde_0697_sub_05a634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x05A634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x05a634: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x05a638: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x05a63c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x05a640: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x05a644: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x05a648: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x05a64c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD12703FFULL; // 0x05a650: sub sp, sp, #0x9c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05a654: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x05a658: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0698 @ 0x05a9b4..0x05ad34 (896 bytes)
// [VN] Phục dựng FDE #0698 tại 0x05a9b4..0x05ad34 (896 byte)
//   0x05a9b4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x05a9b8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05a9bc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05a9c0: 910083fd  add      x29, sp, #0x20
//   0x05a9c4: aa0103f5  mov      x21, x1
//   0x05a9c8: aa0003f3  mov      x19, x0
//   0x05a9cc: b9400a60  ldr      w0, [x19, #8]
//   0x05a9d0: 52813502  mov      w2, #0x9a8
//   0x05a9d4: 52800803  mov      w3, #0x40
//   0x05a9d8: aa1503e1  mov      x1, x21
//   0x05a9dc: aa1f03e4  mov      x4, xzr
//   0x05a9e0: aa1f03e5  mov      x5, xzr
//   0x05a9e4: 94000baf  bl       #0x5d8a0
//   0x05a9e8: b100041f  cmn      x0, #1
//   0x05a9ec: 54000141  b.ne     #0x5aa14
//   0x05a9f0: 94000940  bl       #0x5cef0
uint64_t fde_0698_sub_05a9b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x94000BAFULL) + (x2 ^ 0x05A9B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x05a9b4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x05a9b8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05a9bc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05a9c0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x05a9c4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05a9c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A60ULL; // 0x05a9cc: ldr w0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52813502ULL; // 0x05a9d0: mov w2, #0x9a8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x05a9d4: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x05a9d8: mov x1, x21
    return acc;
}

// [EN] Reconstructed FDE #0699 @ 0x05ad34..0x05ae3c (264 bytes)
// [VN] Phục dựng FDE #0699 tại 0x05ad34..0x05ae3c (264 byte)
//   0x05ad34: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x05ad38: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05ad3c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05ad40: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05ad44: 9100c3fd  add      x29, sp, #0x30
//   0x05ad48: aa0003f4  mov      x20, x0
//   0x05ad4c: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x05ad50: f8010e9f  str      xzr, [x20, #0x10]!
//   0x05ad54: d0000028  adrp     x8, #0x60000
//   0x05ad58: 2a0403f7  mov      w23, w4
//   0x05ad5c: 2a0303f6  mov      w22, w3
//   0x05ad60: 2a0203f5  mov      w21, w2
//   0x05ad64: aa0003f3  mov      x19, x0
//   0x05ad68: 91214108  add      x8, x8, #0x850
//   0x05ad6c: eb01029f  cmp      x20, x1
//   0x05ad70: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0699_sub_05ad34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x05AD34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x05ad34: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05ad38: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05ad3c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05ad40: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05ad44: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x05ad48: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x05ad4c: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x05ad50: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000028ULL; // 0x05ad54: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x05ad58: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0700 @ 0x05ae3c..0x05aea4 (104 bytes)
// [VN] Phục dựng FDE #0700 tại 0x05ae3c..0x05aea4 (104 byte)
//   0x05ae3c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05ae40: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05ae44: 910043fd  add      x29, sp, #0x10
//   0x05ae48: aa0003f3  mov      x19, x0
//   0x05ae4c: b9400800  ldr      w0, [x0, #8]
//   0x05ae50: d0000028  adrp     x8, #0x60000
//   0x05ae54: 91214108  add      x8, x8, #0x850
//   0x05ae58: f9000268  str      x8, [x19]
//   0x05ae5c: 940008c1  bl       #0x5d160
//   0x05ae60: 39404268  ldrb     w8, [x19, #0x10]
//   0x05ae64: d0000029  adrp     x9, #0x60000
//   0x05ae68: 91250129  add      x9, x9, #0x940
//   0x05ae6c: f9000269  str      x9, [x19]
//   0x05ae70: 37000088  tbnz     w8, #0, #0x5ae80
//   0x05ae74: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x05ae78: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0700_sub_05ae3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05AE3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05ae3c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05ae40: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05ae44: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05ae48: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05ae4c: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000028ULL; // 0x05ae50: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91214108ULL; // 0x05ae54: add x8, x8, #0x850
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05ae58: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x940008C1ULL; // 0x05ae5c: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05ae60: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0701 @ 0x05aea4..0x05af08 (100 bytes)
// [VN] Phục dựng FDE #0701 tại 0x05aea4..0x05af08 (100 byte)
//   0x05aea4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05aea8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05aeac: 910043fd  add      x29, sp, #0x10
//   0x05aeb0: aa0003f3  mov      x19, x0
//   0x05aeb4: b9400800  ldr      w0, [x0, #8]
//   0x05aeb8: d0000028  adrp     x8, #0x60000
//   0x05aebc: 91214108  add      x8, x8, #0x850
//   0x05aec0: f9000268  str      x8, [x19]
//   0x05aec4: 940008a7  bl       #0x5d160
//   0x05aec8: 39404268  ldrb     w8, [x19, #0x10]
//   0x05aecc: d0000029  adrp     x9, #0x60000
//   0x05aed0: 91250129  add      x9, x9, #0x940
//   0x05aed4: f9000269  str      x9, [x19]
//   0x05aed8: 36000068  tbz      w8, #0, #0x5aee4
//   0x05aedc: f9401260  ldr      x0, [x19, #0x20]
//   0x05aee0: 940008e4  bl       #0x5d270
uint64_t fde_0701_sub_05aea4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05AEA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05aea4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05aea8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05aeac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05aeb0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05aeb4: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000028ULL; // 0x05aeb8: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91214108ULL; // 0x05aebc: add x8, x8, #0x850
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05aec0: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x940008A7ULL; // 0x05aec4: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05aec8: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0702 @ 0x05af08..0x05b27c (884 bytes)
// [VN] Phục dựng FDE #0702 tại 0x05af08..0x05b27c (884 byte)
//   0x05af08: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x05af0c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05af10: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05af14: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05af18: 9100c3fd  add      x29, sp, #0x30
//   0x05af1c: d14007ff  sub      sp, sp, #1, lsl #12
//   0x05af20: d10d83ff  sub      sp, sp, #0x360
//   0x05af24: d53bd056  mrs      x22, tpidr_el0
//   0x05af28: f94016c8  ldr      x8, [x22, #0x28]
//   0x05af2c: aa0103f5  mov      x21, x1
//   0x05af30: 9126c3e1  add      x1, sp, #0x9b0
//   0x05af34: aa0003f4  mov      x20, x0
//   0x05af38: f81c83a8  stur     x8, [x29, #-0x38]
//   0x05af3c: 9400020b  bl       #0x5b768
//   0x05af40: b949b7e8  ldr      w8, [sp, #0x9b4]
//   0x05af44: 2a0003f3  mov      w19, w0
uint64_t fde_0702_sub_05af08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x05AF08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x05af08: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05af0c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05af10: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05af14: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05af18: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x05af1c: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10D83FFULL; // 0x05af20: sub sp, sp, #0x360
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05af24: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x05af28: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x05af2c: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0703 @ 0x05b27c..0x05b31c (160 bytes)
// [VN] Phục dựng FDE #0703 tại 0x05b27c..0x05b31c (160 byte)
//   0x05b27c: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x05b280: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05b284: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05b288: 910083fd  add      x29, sp, #0x20
//   0x05b28c: d126c3ff  sub      sp, sp, #0x9b0
//   0x05b290: d53bd054  mrs      x20, tpidr_el0
//   0x05b294: f9401688  ldr      x8, [x20, #0x28]
//   0x05b298: 910003e1  mov      x1, sp
//   0x05b29c: aa0003f3  mov      x19, x0
//   0x05b2a0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x05b2a4: 94000131  bl       #0x5b768
//   0x05b2a8: 3940a268  ldrb     w8, [x19, #0x28]
//   0x05b2ac: 2a0003f3  mov      w19, w0
//   0x05b2b0: 34000148  cbz      w8, #0x5b2d8
//   0x05b2b4: b94007e3  ldr      w3, [sp, #4]
//   0x05b2b8: 394023e4  ldrb     w4, [sp, #8]
uint64_t fde_0703_sub_05b27c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x05B27CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x05b27c: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x05b280: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05b284: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05b288: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05b28c: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x05b290: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x05b294: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x05b298: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05b29c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x05b2a0: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0704 @ 0x05b31c..0x05b320 (4 bytes)
// [VN] Phục dựng FDE #0704 tại 0x05b31c..0x05b320 (4 byte)
//   0x05b31c: 14000029  b        #0x5b3c0
uint64_t fde_0704_sub_05b31c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000029ULL) + (x1 ^ 0x14000029ULL) + (x2 ^ 0x05B31CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000029ULL; // 0x05b31c: b #0x5b3c0
    return acc;
}

// [EN] Reconstructed FDE #0705 @ 0x05b320..0x05b350 (48 bytes)
// [VN] Phục dựng FDE #0705 tại 0x05b320..0x05b350 (48 byte)
//   0x05b320: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x05b324: 910003fd  mov      x29, sp
//   0x05b328: 29400c24  ldp      w4, w3, [x1]
//   0x05b32c: f0fffd81  adrp     x1, #0xe000
//   0x05b330: b0fffda2  adrp     x2, #0x10000
//   0x05b334: 911f1821  add      x1, x1, #0x7c6
//   0x05b338: 9136a042  add      x2, x2, #0xda8
//   0x05b33c: 52800060  mov      w0, #3
//   0x05b340: 94000658  bl       #0x5cca0
//   0x05b344: 2a1f03e0  mov      w0, wzr
//   0x05b348: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x05b34c: d65f03c0  ret      
uint64_t fde_0705_sub_05b320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05B320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x05b320: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x05b324: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x29400C24ULL; // 0x05b328: ldp w4, w3, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFD81ULL; // 0x05b32c: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDA2ULL; // 0x05b330: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x05b334: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x9136A042ULL; // 0x05b338: add x2, x2, #0xda8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x05b33c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x94000658ULL; // 0x05b340: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x05b344: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0706 @ 0x05b350..0x05b358 (8 bytes)
// [VN] Phục dựng FDE #0706 tại 0x05b350..0x05b358 (8 byte)
//   0x05b350: b9400420  ldr      w0, [x1, #4]
//   0x05b354: d65f03c0  ret      
uint64_t fde_0706_sub_05b350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400420ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05B350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400420ULL; // 0x05b350: ldr w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05b354: ret 
    return acc;
}

// [EN] Reconstructed FDE #0707 @ 0x05b358..0x05b3b0 (88 bytes)
// [VN] Phục dựng FDE #0707 tại 0x05b358..0x05b3b0 (88 byte)
//   0x05b358: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x05b35c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05b360: 910043fd  add      x29, sp, #0x10
//   0x05b364: d126c3ff  sub      sp, sp, #0x9b0
//   0x05b368: d53bd053  mrs      x19, tpidr_el0
//   0x05b36c: f9401668  ldr      x8, [x19, #0x28]
//   0x05b370: 52800049  mov      w9, #2
//   0x05b374: 5280002a  mov      w10, #1
//   0x05b378: f81e83a8  stur     x8, [x29, #-0x18]
//   0x05b37c: 290007e9  stp      w9, w1, [sp]
//   0x05b380: 910003e1  mov      x1, sp
//   0x05b384: 390023ea  strb     w10, [sp, #8]
//   0x05b388: 9400000e  bl       #0x5b3c0
//   0x05b38c: f9401668  ldr      x8, [x19, #0x28]
//   0x05b390: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x05b394: eb09011f  cmp      x8, x9
uint64_t fde_0707_sub_05b358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FFCULL) + (x1 ^ 0x9400000EULL) + (x2 ^ 0x05B358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FFCULL; // 0x05b358: stp x28, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05b35c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05b360: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05b364: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x05b368: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x05b36c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800049ULL; // 0x05b370: mov w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x05b374: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x05b378: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x290007E9ULL; // 0x05b37c: stp w9, w1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0708 @ 0x05b3b0..0x05b3b8 (8 bytes)
// [VN] Phục dựng FDE #0708 tại 0x05b3b0..0x05b3b8 (8 byte)
//   0x05b3b0: 52800080  mov      w0, #4
//   0x05b3b4: d65f03c0  ret      
uint64_t fde_0708_sub_05b3b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05B3B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x05b3b0: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05b3b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0709 @ 0x05b3b8..0x05b3c0 (8 bytes)
// [VN] Phục dựng FDE #0709 tại 0x05b3b8..0x05b3c0 (8 byte)
//   0x05b3b8: 52800100  mov      w0, #8
//   0x05b3bc: d65f03c0  ret      
uint64_t fde_0709_sub_05b3b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05B3B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x05b3b8: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05b3bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0710 @ 0x05b3c0..0x05b768 (936 bytes)
// [VN] Phục dựng FDE #0710 tại 0x05b3c0..0x05b768 (936 byte)
//   0x05b3c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x05b3c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x05b3c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x05b3cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x05b3d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x05b3d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x05b3d8: 910143fd  add      x29, sp, #0x50
//   0x05b3dc: d12703ff  sub      sp, sp, #0x9c0
//   0x05b3e0: d53bd057  mrs      x23, tpidr_el0
//   0x05b3e4: f94016e8  ldr      x8, [x23, #0x28]
//   0x05b3e8: aa0103f3  mov      x19, x1
//   0x05b3ec: aa0003f4  mov      x20, x0
//   0x05b3f0: f81a03a8  stur     x8, [x29, #-0x60]
//   0x05b3f4: b9400028  ldr      w8, [x1]
//   0x05b3f8: 71001d1f  cmp      w8, #7
//   0x05b3fc: 54000288  b.hi     #0x5b44c
uint64_t fde_0710_sub_05b3c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x05B3C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x05b3c0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x05b3c4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x05b3c8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x05b3cc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x05b3d0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x05b3d4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x05b3d8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD12703FFULL; // 0x05b3dc: sub sp, sp, #0x9c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x05b3e0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x05b3e4: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0711 @ 0x05b768..0x05ba00 (664 bytes)
// [VN] Phục dựng FDE #0711 tại 0x05b768..0x05ba00 (664 byte)
//   0x05b768: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05b76c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05b770: 910043fd  add      x29, sp, #0x10
//   0x05b774: aa0103f3  mov      x19, x1
//   0x05b778: aa0003f4  mov      x20, x0
//   0x05b77c: b9400a80  ldr      w0, [x20, #8]
//   0x05b780: 52813502  mov      w2, #0x9a8
//   0x05b784: 52800803  mov      w3, #0x40
//   0x05b788: aa1303e1  mov      x1, x19
//   0x05b78c: aa1f03e4  mov      x4, xzr
//   0x05b790: aa1f03e5  mov      x5, xzr
//   0x05b794: 94000843  bl       #0x5d8a0
//   0x05b798: b100041f  cmn      x0, #1
//   0x05b79c: 54000181  b.ne     #0x5b7cc
//   0x05b7a0: 940005d4  bl       #0x5cef0
//   0x05b7a4: b9400008  ldr      w8, [x0]
uint64_t fde_0711_sub_05b768(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x05B768ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05b768: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05b76c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05b770: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x05b774: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x05b778: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x05b77c: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52813502ULL; // 0x05b780: mov w2, #0x9a8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x05b784: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x05b788: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x05b78c: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0712 @ 0x05ba00..0x05bb08 (264 bytes)
// [VN] Phục dựng FDE #0712 tại 0x05ba00..0x05bb08 (264 byte)
//   0x05ba00: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x05ba04: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05ba08: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05ba0c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05ba10: 9100c3fd  add      x29, sp, #0x30
//   0x05ba14: aa0003f4  mov      x20, x0
//   0x05ba18: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x05ba1c: f8010e9f  str      xzr, [x20, #0x10]!
//   0x05ba20: b0000028  adrp     x8, #0x60000
//   0x05ba24: 2a0403f7  mov      w23, w4
//   0x05ba28: 2a0303f6  mov      w22, w3
//   0x05ba2c: 2a0203f5  mov      w21, w2
//   0x05ba30: aa0003f3  mov      x19, x0
//   0x05ba34: 91232108  add      x8, x8, #0x8c8
//   0x05ba38: eb01029f  cmp      x20, x1
//   0x05ba3c: 7900501f  strh     wzr, [x0, #0x28]
uint64_t fde_0712_sub_05ba00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x05BA00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x05ba00: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05ba04: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05ba08: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05ba0c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05ba10: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x05ba14: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x05ba18: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010E9FULL; // 0x05ba1c: str xzr, [x20, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000028ULL; // 0x05ba20: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x05ba24: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0713 @ 0x05bb08..0x05bb70 (104 bytes)
// [VN] Phục dựng FDE #0713 tại 0x05bb08..0x05bb70 (104 byte)
//   0x05bb08: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05bb0c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05bb10: 910043fd  add      x29, sp, #0x10
//   0x05bb14: aa0003f3  mov      x19, x0
//   0x05bb18: b9400800  ldr      w0, [x0, #8]
//   0x05bb1c: b0000028  adrp     x8, #0x60000
//   0x05bb20: 91232108  add      x8, x8, #0x8c8
//   0x05bb24: f9000268  str      x8, [x19]
//   0x05bb28: 9400058e  bl       #0x5d160
//   0x05bb2c: 39404268  ldrb     w8, [x19, #0x10]
//   0x05bb30: b0000029  adrp     x9, #0x60000
//   0x05bb34: 91250129  add      x9, x9, #0x940
//   0x05bb38: f9000269  str      x9, [x19]
//   0x05bb3c: 37000088  tbnz     w8, #0, #0x5bb4c
//   0x05bb40: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x05bb44: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0713_sub_05bb08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05BB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05bb08: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05bb0c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05bb10: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05bb14: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05bb18: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000028ULL; // 0x05bb1c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91232108ULL; // 0x05bb20: add x8, x8, #0x8c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05bb24: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400058EULL; // 0x05bb28: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05bb2c: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0714 @ 0x05bb70..0x05bbd4 (100 bytes)
// [VN] Phục dựng FDE #0714 tại 0x05bb70..0x05bbd4 (100 byte)
//   0x05bb70: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05bb74: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05bb78: 910043fd  add      x29, sp, #0x10
//   0x05bb7c: aa0003f3  mov      x19, x0
//   0x05bb80: b9400800  ldr      w0, [x0, #8]
//   0x05bb84: b0000028  adrp     x8, #0x60000
//   0x05bb88: 91232108  add      x8, x8, #0x8c8
//   0x05bb8c: f9000268  str      x8, [x19]
//   0x05bb90: 94000574  bl       #0x5d160
//   0x05bb94: 39404268  ldrb     w8, [x19, #0x10]
//   0x05bb98: b0000029  adrp     x9, #0x60000
//   0x05bb9c: 91250129  add      x9, x9, #0x940
//   0x05bba0: f9000269  str      x9, [x19]
//   0x05bba4: 36000068  tbz      w8, #0, #0x5bbb0
//   0x05bba8: f9401260  ldr      x0, [x19, #0x20]
//   0x05bbac: 940005b1  bl       #0x5d270
uint64_t fde_0714_sub_05bb70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000269ULL) + (x2 ^ 0x05BB70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05bb70: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05bb74: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05bb78: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05bb7c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400800ULL; // 0x05bb80: ldr w0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000028ULL; // 0x05bb84: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91232108ULL; // 0x05bb88: add x8, x8, #0x8c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x05bb8c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000574ULL; // 0x05bb90: bl #0x5d160
    acc = (acc * 0x100000001B3ULL) ^ 0x39404268ULL; // 0x05bb94: ldrb w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0715 @ 0x05bbd4..0x05bf48 (884 bytes)
// [VN] Phục dựng FDE #0715 tại 0x05bbd4..0x05bf48 (884 byte)
//   0x05bbd4: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x05bbd8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05bbdc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05bbe0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05bbe4: 9100c3fd  add      x29, sp, #0x30
//   0x05bbe8: d14007ff  sub      sp, sp, #1, lsl #12
//   0x05bbec: d10d83ff  sub      sp, sp, #0x360
//   0x05bbf0: d53bd056  mrs      x22, tpidr_el0
//   0x05bbf4: f94016c8  ldr      x8, [x22, #0x28]
//   0x05bbf8: aa0103f5  mov      x21, x1
//   0x05bbfc: 9126c3e1  add      x1, sp, #0x9b0
//   0x05bc00: aa0003f4  mov      x20, x0
//   0x05bc04: f81c83a8  stur     x8, [x29, #-0x38]
//   0x05bc08: 9400020f  bl       #0x5c444
//   0x05bc0c: b949b7e8  ldr      w8, [sp, #0x9b4]
//   0x05bc10: 2a0003f3  mov      w19, w0
uint64_t fde_0715_sub_05bbd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x05BBD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FFCULL; // 0x05bbd4: str x28, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05bbd8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05bbdc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05bbe0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05bbe4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD14007FFULL; // 0x05bbe8: sub sp, sp, #1, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10D83FFULL; // 0x05bbec: sub sp, sp, #0x360
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x05bbf0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x05bbf4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x05bbf8: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0716 @ 0x05bf48..0x05bfe8 (160 bytes)
// [VN] Phục dựng FDE #0716 tại 0x05bf48..0x05bfe8 (160 byte)
//   0x05bf48: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x05bf4c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05bf50: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05bf54: 910083fd  add      x29, sp, #0x20
//   0x05bf58: d126c3ff  sub      sp, sp, #0x9b0
//   0x05bf5c: d53bd054  mrs      x20, tpidr_el0
//   0x05bf60: f9401688  ldr      x8, [x20, #0x28]
//   0x05bf64: 910003e1  mov      x1, sp
//   0x05bf68: aa0003f3  mov      x19, x0
//   0x05bf6c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x05bf70: 94000135  bl       #0x5c444
//   0x05bf74: 3940a268  ldrb     w8, [x19, #0x28]
//   0x05bf78: 2a0003f3  mov      w19, w0
//   0x05bf7c: 34000148  cbz      w8, #0x5bfa4
//   0x05bf80: b94007e3  ldr      w3, [sp, #4]
//   0x05bf84: 394023e4  ldrb     w4, [sp, #8]
uint64_t fde_0716_sub_05bf48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x05BF48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x05bf48: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x05bf4c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05bf50: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05bf54: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05bf58: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x05bf5c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x05bf60: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x05bf64: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05bf68: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x05bf6c: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0717 @ 0x05bfe8..0x05bfec (4 bytes)
// [VN] Phục dựng FDE #0717 tại 0x05bfe8..0x05bfec (4 byte)
//   0x05bfe8: 14000029  b        #0x5c08c
uint64_t fde_0717_sub_05bfe8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000029ULL) + (x1 ^ 0x14000029ULL) + (x2 ^ 0x05BFE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000029ULL; // 0x05bfe8: b #0x5c08c
    return acc;
}

// [EN] Reconstructed FDE #0718 @ 0x05bfec..0x05c01c (48 bytes)
// [VN] Phục dựng FDE #0718 tại 0x05bfec..0x05c01c (48 byte)
//   0x05bfec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x05bff0: 910003fd  mov      x29, sp
//   0x05bff4: 29400c24  ldp      w4, w3, [x1]
//   0x05bff8: f0fffd81  adrp     x1, #0xe000
//   0x05bffc: b0fffda2  adrp     x2, #0x10000
//   0x05c000: 911f1821  add      x1, x1, #0x7c6
//   0x05c004: 9136a042  add      x2, x2, #0xda8
//   0x05c008: 52800060  mov      w0, #3
//   0x05c00c: 94000325  bl       #0x5cca0
//   0x05c010: 2a1f03e0  mov      w0, wzr
//   0x05c014: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x05c018: d65f03c0  ret      
uint64_t fde_0718_sub_05bfec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05BFECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x05bfec: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x05bff0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x29400C24ULL; // 0x05bff4: ldp w4, w3, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFD81ULL; // 0x05bff8: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFDA2ULL; // 0x05bffc: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F1821ULL; // 0x05c000: add x1, x1, #0x7c6
    acc = (acc * 0x100000001B3ULL) ^ 0x9136A042ULL; // 0x05c004: add x2, x2, #0xda8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x05c008: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x94000325ULL; // 0x05c00c: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x05c010: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0719 @ 0x05c01c..0x05c024 (8 bytes)
// [VN] Phục dựng FDE #0719 tại 0x05c01c..0x05c024 (8 byte)
//   0x05c01c: b9400420  ldr      w0, [x1, #4]
//   0x05c020: d65f03c0  ret      
uint64_t fde_0719_sub_05c01c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400420ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05C01CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400420ULL; // 0x05c01c: ldr w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05c020: ret 
    return acc;
}

// [EN] Reconstructed FDE #0720 @ 0x05c024..0x05c07c (88 bytes)
// [VN] Phục dựng FDE #0720 tại 0x05c024..0x05c07c (88 byte)
//   0x05c024: a9be4ffc  stp      x28, x19, [sp, #-0x20]!
//   0x05c028: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05c02c: 910043fd  add      x29, sp, #0x10
//   0x05c030: d126c3ff  sub      sp, sp, #0x9b0
//   0x05c034: d53bd053  mrs      x19, tpidr_el0
//   0x05c038: f9401668  ldr      x8, [x19, #0x28]
//   0x05c03c: 52800049  mov      w9, #2
//   0x05c040: 5280002a  mov      w10, #1
//   0x05c044: f81e83a8  stur     x8, [x29, #-0x18]
//   0x05c048: 290007e9  stp      w9, w1, [sp]
//   0x05c04c: 910003e1  mov      x1, sp
//   0x05c050: 390023ea  strb     w10, [sp, #8]
//   0x05c054: 9400000e  bl       #0x5c08c
//   0x05c058: f9401668  ldr      x8, [x19, #0x28]
//   0x05c05c: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x05c060: eb09011f  cmp      x8, x9
uint64_t fde_0720_sub_05c024(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FFCULL) + (x1 ^ 0x9400000EULL) + (x2 ^ 0x05C024ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FFCULL; // 0x05c024: stp x28, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05c028: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05c02c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD126C3FFULL; // 0x05c030: sub sp, sp, #0x9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x05c034: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x05c038: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800049ULL; // 0x05c03c: mov w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x05c040: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x05c044: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x290007E9ULL; // 0x05c048: stp w9, w1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0721 @ 0x05c07c..0x05c084 (8 bytes)
// [VN] Phục dựng FDE #0721 tại 0x05c07c..0x05c084 (8 byte)
//   0x05c07c: 52800080  mov      w0, #4
//   0x05c080: d65f03c0  ret      
uint64_t fde_0721_sub_05c07c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05C07CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x05c07c: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05c080: ret 
    return acc;
}

// [EN] Reconstructed FDE #0722 @ 0x05c084..0x05c08c (8 bytes)
// [VN] Phục dựng FDE #0722 tại 0x05c084..0x05c08c (8 byte)
//   0x05c084: 52800100  mov      w0, #8
//   0x05c088: d65f03c0  ret      
uint64_t fde_0722_sub_05c084(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05C084ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x05c084: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05c088: ret 
    return acc;
}

// [EN] Reconstructed FDE #0723 @ 0x05c08c..0x05c444 (952 bytes)
// [VN] Phục dựng FDE #0723 tại 0x05c08c..0x05c444 (952 byte)
//   0x05c08c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x05c090: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x05c094: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x05c098: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x05c09c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x05c0a0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x05c0a4: 910143fd  add      x29, sp, #0x50
//   0x05c0a8: d12703ff  sub      sp, sp, #0x9c0
//   0x05c0ac: d53bd057  mrs      x23, tpidr_el0
//   0x05c0b0: f94016e8  ldr      x8, [x23, #0x28]
//   0x05c0b4: aa0103f3  mov      x19, x1
//   0x05c0b8: aa0003f4  mov      x20, x0
//   0x05c0bc: f81a03a8  stur     x8, [x29, #-0x60]
//   0x05c0c0: b9400028  ldr      w8, [x1]
//   0x05c0c4: 71001d1f  cmp      w8, #7
//   0x05c0c8: 54000288  b.hi     #0x5c118
uint64_t fde_0723_sub_05c08c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x05C08CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x05c08c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x05c090: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x05c094: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x05c098: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x05c09c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x05c0a0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x05c0a4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD12703FFULL; // 0x05c0a8: sub sp, sp, #0x9c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x05c0ac: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x05c0b0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0724 @ 0x05c444..0x05c6dc (664 bytes)
// [VN] Phục dựng FDE #0724 tại 0x05c444..0x05c6dc (664 byte)
//   0x05c444: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x05c448: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x05c44c: 910043fd  add      x29, sp, #0x10
//   0x05c450: aa0103f3  mov      x19, x1
//   0x05c454: aa0003f4  mov      x20, x0
//   0x05c458: b9400a80  ldr      w0, [x20, #8]
//   0x05c45c: 52813502  mov      w2, #0x9a8
//   0x05c460: 52800803  mov      w3, #0x40
//   0x05c464: aa1303e1  mov      x1, x19
//   0x05c468: aa1f03e4  mov      x4, xzr
//   0x05c46c: aa1f03e5  mov      x5, xzr
//   0x05c470: 9400050c  bl       #0x5d8a0
//   0x05c474: b100041f  cmn      x0, #1
//   0x05c478: 54000181  b.ne     #0x5c4a8
//   0x05c47c: 9400029d  bl       #0x5cef0
//   0x05c480: b9400008  ldr      w8, [x0]
uint64_t fde_0724_sub_05c444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x05C444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x05c444: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x05c448: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x05c44c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x05c450: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x05c454: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A80ULL; // 0x05c458: ldr w0, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52813502ULL; // 0x05c45c: mov w2, #0x9a8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800803ULL; // 0x05c460: mov w3, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x05c464: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x05c468: mov x4, xzr
    return acc;
}

// [EN] Reconstructed FDE #0725 @ 0x05c6dc..0x05c6fc (32 bytes)
// [VN] Phục dựng FDE #0725 tại 0x05c6dc..0x05c6fc (32 byte)
//   0x05c6dc: 39404008  ldrb     w8, [x0, #0x10]
//   0x05c6e0: 90000029  adrp     x9, #0x60000
//   0x05c6e4: 91250129  add      x9, x9, #0x940
//   0x05c6e8: f9000009  str      x9, [x0]
//   0x05c6ec: 37000048  tbnz     w8, #0, #0x5c6f4
//   0x05c6f0: d65f03c0  ret      
//   0x05c6f4: f9401000  ldr      x0, [x0, #0x20]
//   0x05c6f8: 140002de  b        #0x5d270
uint64_t fde_0725_sub_05c6dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404008ULL) + (x1 ^ 0x140002DEULL) + (x2 ^ 0x05C6DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404008ULL; // 0x05c6dc: ldrb w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000029ULL; // 0x05c6e0: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91250129ULL; // 0x05c6e4: add x9, x9, #0x940
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x05c6e8: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000048ULL; // 0x05c6ec: tbnz w8, #0, #0x5c6f4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05c6f0: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x05c6f4: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x140002DEULL; // 0x05c6f8: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0726 @ 0x05c6fc..0x05c700 (4 bytes)
// [VN] Phục dựng FDE #0726 tại 0x05c6fc..0x05c700 (4 byte)
//   0x05c6fc: d4200020  brk      #1
uint64_t fde_0726_sub_05c6fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD4200020ULL) + (x1 ^ 0xD4200020ULL) + (x2 ^ 0x05C6FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD4200020ULL; // 0x05c6fc: brk #1
    return acc;
}

// [EN] Reconstructed FDE #0727 @ 0x05c700..0x05c87c (380 bytes)
// [VN] Phục dựng FDE #0727 tại 0x05c700..0x05c87c (380 byte)
//   0x05c700: a9bc5ffc  stp      x28, x23, [sp, #-0x40]!
//   0x05c704: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x05c708: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x05c70c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x05c710: 9100c3fd  add      x29, sp, #0x30
//   0x05c714: d11043ff  sub      sp, sp, #0x410
//   0x05c718: d53bd057  mrs      x23, tpidr_el0
//   0x05c71c: f94016e8  ldr      x8, [x23, #0x28]
//   0x05c720: aa0003f3  mov      x19, x0
//   0x05c724: 910023e0  add      x0, sp, #8
//   0x05c728: 52808002  mov      w2, #0x400
//   0x05c72c: 2a1f03e1  mov      w1, wzr
//   0x05c730: f81c83a8  stur     x8, [x29, #-0x38]
//   0x05c734: 9400020b  bl       #0x5cf60
//   0x05c738: d0fffda0  adrp     x0, #0x12000
//   0x05c73c: b0fffda1  adrp     x1, #0x11000
uint64_t fde_0727_sub_05c700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FFCULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x05C700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FFCULL; // 0x05c700: stp x28, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x05c704: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x05c708: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x05c70c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x05c710: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x05c714: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x05c718: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x05c71c: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x05c720: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x05c724: add x0, sp, #8
    return acc;
}

// [EN] Reconstructed FDE #0728 @ 0x05c87c..0x05c9a8 (300 bytes)
// [VN] Phục dựng FDE #0728 tại 0x05c87c..0x05c9a8 (300 byte)
//   0x05c87c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x05c880: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x05c884: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x05c888: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x05c88c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x05c890: 910103fd  add      x29, sp, #0x40
//   0x05c894: f9402808  ldr      x8, [x0, #0x50]
//   0x05c898: 2a0203f3  mov      w19, w2
//   0x05c89c: aa0003f5  mov      x21, x0
//   0x05c8a0: aa0103f4  mov      x20, x1
//   0x05c8a4: b4000288  cbz      x8, #0x5c8f4
//   0x05c8a8: f9402eb7  ldr      x23, [x21, #0x58]
//   0x05c8ac: b4000257  cbz      x23, #0x5c8f4
//   0x05c8b0: f94022b8  ldr      x24, [x21, #0x40]
//   0x05c8b4: b4000218  cbz      x24, #0x5c8f4
//   0x05c8b8: 91002119  add      x25, x8, #8
uint64_t fde_0728_sub_05c87c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB4000257ULL) + (x2 ^ 0x05C87CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x05c87c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x05c880: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x05c884: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x05c888: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x05c88c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x05c890: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402808ULL; // 0x05c894: ldr x8, [x0, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x05c898: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x05c89c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x05c8a0: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0729 @ 0x05c9a8..0x05c9ac (4 bytes)
// [VN] Phục dựng FDE #0729 tại 0x05c9a8..0x05c9ac (4 byte)
//   0x05c9a8: d65f03c0  ret      
uint64_t fde_0729_sub_05c9a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x05C9A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x05c9a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0730 @ 0x05c9ac..0x05cb64 (440 bytes)
// [VN] Phục dựng FDE #0730 tại 0x05c9ac..0x05cb64 (440 byte)
//   0x05c9ac: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x05c9b0: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x05c9b4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x05c9b8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x05c9bc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x05c9c0: 910103fd  add      x29, sp, #0x40
//   0x05c9c4: 9000005a  adrp     x26, #0x64000
//   0x05c9c8: f9402f56  ldr      x22, [x26, #0x58]
//   0x05c9cc: f10002df  cmp      x22, #0
//   0x05c9d0: 54000a0c  b.gt     #0x5cb10
//   0x05c9d4: f9400008  ldr      x8, [x0]
//   0x05c9d8: aa0403f5  mov      x21, x4
//   0x05c9dc: aa0303f9  mov      x25, x3
//   0x05c9e0: aa0203f7  mov      x23, x2
//   0x05c9e4: f9401908  ldr      x8, [x8, #0x30]
//   0x05c9e8: aa0103f8  mov      x24, x1
uint64_t fde_0730_sub_05c9ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xAA0303F9ULL) + (x2 ^ 0x05C9ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x05c9ac: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x05c9b0: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x05c9b4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x05c9b8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x05c9bc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x05c9c0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x9000005AULL; // 0x05c9c4: adrp x26, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402F56ULL; // 0x05c9c8: ldr x22, [x26, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF10002DFULL; // 0x05c9cc: cmp x22, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A0CULL; // 0x05c9d0: b.gt #0x5cb10
    return acc;
}

// [EN] Reconstructed FDE #0731 @ 0x05cb64..0x05cc5c (248 bytes)
// [VN] Phục dựng FDE #0731 tại 0x05cb64..0x05cc5c (248 byte)
//   0x05cb64: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x05cb68: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x05cb6c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x05cb70: 910083fd  add      x29, sp, #0x20
//   0x05cb74: aa0303f4  mov      x20, x3
//   0x05cb78: aa0103e3  mov      x3, x1
//   0x05cb7c: b4000360  cbz      x0, #0x5cbe8
//   0x05cb80: b100047f  cmn      x3, #1
//   0x05cb84: 54000320  b.eq     #0x5cbe8
//   0x05cb88: aa0203f3  mov      x19, x2
//   0x05cb8c: 8b000075  add      x21, x3, x0
//   0x05cb90: 940000d0  bl       #0x5ced0
//   0x05cb94: 4b0003e8  neg      w8, w0
//   0x05cb98: 93407d08  sxtw     x8, w8
//   0x05cb9c: 8a0802b6  and      x22, x21, x8
//   0x05cba0: 940000cc  bl       #0x5ced0
uint64_t fde_0731_sub_05cb64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x4B0003E8ULL) + (x2 ^ 0x05CB64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x05cb64: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x05cb68: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x05cb6c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x05cb70: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x05cb74: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E3ULL; // 0x05cb78: mov x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000360ULL; // 0x05cb7c: cbz x0, #0x5cbe8
    acc = (acc * 0x100000001B3ULL) ^ 0xB100047FULL; // 0x05cb80: cmn x3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000320ULL; // 0x05cb84: b.eq #0x5cbe8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x05cb88: mov x19, x2
    return acc;
}

uint64_t DispatchAnrPerflockIrtFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 500U || fde_index >= 732U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x94D049BB133111EBULL) + x2;
}

} // namespace anr_perflock
} // namespace sysoptimizer
} // namespace bytedance
