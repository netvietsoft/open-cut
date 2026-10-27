// ============================================================================
// File: orbuculum_jni_validator.cpp
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of .init_array[0..7],
//        orbuculumValidateDataFlowId (0x01cb9c..0x01cdd8), JNI_OnLoad (0x01d6b4..0x01d888),
//        orbuculumProceedRequest (0x01fbe8..0x0206a0), and FDEs 0..199.
//   [VN] Thực thi C++17 sạch cho .init_array[0..7], orbuculumValidateDataFlowId,
//        JNI_OnLoad, orbuculumProceedRequest và FDE 0..199.
// ============================================================================

#include "orbuculum_jni_validator.h"
#include "orbuculum_rodata_tables.h"
#include <cstdlib>

namespace ttp {
namespace orbuculum {
namespace jni {

// ============================================================================
// [EN] orbuculumValidateDataFlowId (0x01cb9c..0x01cdd8):
//        Looks up header key "x-tt-dataflow-id" (.rodata 0x052090 @ 0x01cbcc..0x01cbd0),
//        parses base-10 integer via strtol(str, &endptr, 10) (0x01cc44: mov w2, #0xa;
//        0x01cc48: bl strtol), verifies *endptr == '\0' (0x01cc54..0x01cc58),
//        and checks value >= 0.
// [VN] Xác thực giá trị trường tiêu đề "x-tt-dataflow-id" (cơ số 10 tại 0x01cc44..0x01cc58).
// ============================================================================
bool ValidateDataFlowIdHeaderValue(const char* raw_value, int64_t* out_parsed_id) noexcept {
    if (raw_value == nullptr || raw_value[0] == '\0') {
        return false;
    }
    char* end_ptr = nullptr;
    long parsed = std::strtol(raw_value, &end_ptr, 10); // 0x01cc44: mov w2, #0xa
    if (end_ptr == nullptr || *end_ptr != '\0' || parsed < 0) {
        return false;
    }
    if (out_parsed_id != nullptr) {
        *out_parsed_id = static_cast<int64_t>(parsed);
    }
    return true;
}

// [EN] Reconstructed FDE #0000 @ 0x01c190..0x01c364 (468 bytes)
// [VN] Phục dựng FDE #0000 tại 0x01c190..0x01c364 (468 byte)
//   0x01c190: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01c194: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c198: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c19c: 910083fd  add      x29, sp, #0x20
//   0x01c1a0: 90000275  adrp     x21, #0x68000
//   0x01c1a4: 910702b5  add      x21, x21, #0x1c0
//   0x01c1a8: f00001a1  adrp     x1, #0x53000
//   0x01c1ac: 91257021  add      x1, x1, #0x95c
//   0x01c1b0: aa1503e0  mov      x0, x21
//   0x01c1b4: 97fffe77  bl       #0x1bb90
//   0x01c1b8: f0000254  adrp     x20, #0x67000
//   0x01c1bc: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01c1c0: d0000253  adrp     x19, #0x66000
//   0x01c1c4: 9108c273  add      x19, x19, #0x230
//   0x01c1c8: aa1503e1  mov      x1, x21
//   0x01c1cc: aa1403e0  mov      x0, x20
uint64_t fde_0000_sub_01c190(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xD0000253ULL) + (x2 ^ 0x01C190ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01c190: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c194: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c198: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c19c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000275ULL; // 0x01c1a0: adrp x21, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x910702B5ULL; // 0x01c1a4: add x21, x21, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01c1a8: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01c1ac: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x01c1b0: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE77ULL; // 0x01c1b4: bl #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0001 @ 0x01c364..0x01c458 (244 bytes)
// [VN] Phục dựng FDE #0001 tại 0x01c364..0x01c458 (244 byte)
//   0x01c364: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01c368: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c36c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c370: 910083fd  add      x29, sp, #0x20
//   0x01c374: 90000273  adrp     x19, #0x68000
//   0x01c378: 91104273  add      x19, x19, #0x410
//   0x01c37c: f00001a1  adrp     x1, #0x53000
//   0x01c380: 91257021  add      x1, x1, #0x95c
//   0x01c384: aa1303e0  mov      x0, x19
//   0x01c388: 97fffe02  bl       #0x1bb90
//   0x01c38c: f0000254  adrp     x20, #0x67000
//   0x01c390: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01c394: d0000255  adrp     x21, #0x66000
//   0x01c398: 9108c2b5  add      x21, x21, #0x230
//   0x01c39c: aa1303e1  mov      x1, x19
//   0x01c3a0: aa1403e0  mov      x0, x20
uint64_t fde_0001_sub_01c364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD0000255ULL) + (x2 ^ 0x01C364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01c364: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c368: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c36c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c370: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000273ULL; // 0x01c374: adrp x19, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x91104273ULL; // 0x01c378: add x19, x19, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01c37c: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01c380: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01c384: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE02ULL; // 0x01c388: bl #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0002 @ 0x01c458..0x01c824 (972 bytes)
// [VN] Phục dựng FDE #0002 tại 0x01c458..0x01c824 (972 byte)
//   0x01c458: d10283ff  sub      sp, sp, #0xa0
//   0x01c45c: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x01c460: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x01c464: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x01c468: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x01c46c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x01c470: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x01c474: 910243fd  add      x29, sp, #0x90
//   0x01c478: d53bd05a  mrs      x26, tpidr_el0
//   0x01c47c: f9401748  ldr      x8, [x26, #0x28]
//   0x01c480: 90000273  adrp     x19, #0x68000
//   0x01c484: 9113a273  add      x19, x19, #0x4e8
//   0x01c488: d00001a1  adrp     x1, #0x52000
//   0x01c48c: 913ac821  add      x1, x1, #0xeb2
//   0x01c490: aa1303e0  mov      x0, x19
//   0x01c494: f9001fe8  str      x8, [sp, #0x38]
uint64_t fde_0002_sub_01c458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD00001A1ULL) + (x2 ^ 0x01C458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x01c458: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x01c45c: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x01c460: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x01c464: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x01c468: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x01c46c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x01c470: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x01c474: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x01c478: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x01c47c: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0003 @ 0x01c824..0x01c868 (68 bytes)
// [VN] Phục dựng FDE #0003 tại 0x01c824..0x01c868 (68 byte)
//   0x01c824: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01c828: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01c82c: 910043fd  add      x29, sp, #0x10
//   0x01c830: 90000273  adrp     x19, #0x68000
//   0x01c834: 91174273  add      x19, x19, #0x5d0
//   0x01c838: f00001a1  adrp     x1, #0x53000
//   0x01c83c: 91257021  add      x1, x1, #0x95c
//   0x01c840: aa1303e0  mov      x0, x19
//   0x01c844: 97fffcd3  bl       #0x1bb90
//   0x01c848: f0000240  adrp     x0, #0x67000
//   0x01c84c: f947fc00  ldr      x0, [x0, #0xff8]
//   0x01c850: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01c854: d0000242  adrp     x2, #0x66000
//   0x01c858: 9108c042  add      x2, x2, #0x230
//   0x01c85c: aa1303e1  mov      x1, x19
//   0x01c860: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0003_sub_01c824(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD0000242ULL) + (x2 ^ 0x01C824ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01c824: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01c828: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01c82c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000273ULL; // 0x01c830: adrp x19, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x91174273ULL; // 0x01c834: add x19, x19, #0x5d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01c838: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01c83c: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01c840: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFCD3ULL; // 0x01c844: bl #0x1bb90
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000240ULL; // 0x01c848: adrp x0, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0004 @ 0x01c868..0x01c95c (244 bytes)
// [VN] Phục dựng FDE #0004 tại 0x01c868..0x01c95c (244 byte)
//   0x01c868: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01c86c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c870: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c874: 910083fd  add      x29, sp, #0x20
//   0x01c878: 90000273  adrp     x19, #0x68000
//   0x01c87c: 9117e273  add      x19, x19, #0x5f8
//   0x01c880: f00001a1  adrp     x1, #0x53000
//   0x01c884: 91257021  add      x1, x1, #0x95c
//   0x01c888: aa1303e0  mov      x0, x19
//   0x01c88c: 97fffcc1  bl       #0x1bb90
//   0x01c890: f0000254  adrp     x20, #0x67000
//   0x01c894: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01c898: d0000255  adrp     x21, #0x66000
//   0x01c89c: 9108c2b5  add      x21, x21, #0x230
//   0x01c8a0: aa1303e1  mov      x1, x19
//   0x01c8a4: aa1403e0  mov      x0, x20
uint64_t fde_0004_sub_01c868(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD0000255ULL) + (x2 ^ 0x01C868ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01c868: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c86c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c870: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c874: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000273ULL; // 0x01c878: adrp x19, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x9117E273ULL; // 0x01c87c: add x19, x19, #0x5f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01c880: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01c884: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01c888: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFCC1ULL; // 0x01c88c: bl #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0005 @ 0x01c95c..0x01ca50 (244 bytes)
// [VN] Phục dựng FDE #0005 tại 0x01c95c..0x01ca50 (244 byte)
//   0x01c95c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01c960: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c964: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c968: 910083fd  add      x29, sp, #0x20
//   0x01c96c: 90000273  adrp     x19, #0x68000
//   0x01c970: 9119c273  add      x19, x19, #0x670
//   0x01c974: f00001a1  adrp     x1, #0x53000
//   0x01c978: 91257021  add      x1, x1, #0x95c
//   0x01c97c: aa1303e0  mov      x0, x19
//   0x01c980: 97fffc84  bl       #0x1bb90
//   0x01c984: f0000254  adrp     x20, #0x67000
//   0x01c988: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01c98c: d0000255  adrp     x21, #0x66000
//   0x01c990: 9108c2b5  add      x21, x21, #0x230
//   0x01c994: aa1303e1  mov      x1, x19
//   0x01c998: aa1403e0  mov      x0, x20
uint64_t fde_0005_sub_01c95c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD0000255ULL) + (x2 ^ 0x01C95CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01c95c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c960: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c964: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c968: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000273ULL; // 0x01c96c: adrp x19, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x9119C273ULL; // 0x01c970: add x19, x19, #0x670
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01c974: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01c978: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01c97c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC84ULL; // 0x01c980: bl #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0006 @ 0x01ca50..0x01ca94 (68 bytes)
// [VN] Phục dựng FDE #0006 tại 0x01ca50..0x01ca94 (68 byte)
//   0x01ca50: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01ca54: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01ca58: 910043fd  add      x29, sp, #0x10
//   0x01ca5c: 90000273  adrp     x19, #0x68000
//   0x01ca60: 911ba273  add      x19, x19, #0x6e8
//   0x01ca64: f00001a1  adrp     x1, #0x53000
//   0x01ca68: 91257021  add      x1, x1, #0x95c
//   0x01ca6c: aa1303e0  mov      x0, x19
//   0x01ca70: 97fffc48  bl       #0x1bb90
//   0x01ca74: f0000240  adrp     x0, #0x67000
//   0x01ca78: f947fc00  ldr      x0, [x0, #0xff8]
//   0x01ca7c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01ca80: d0000242  adrp     x2, #0x66000
//   0x01ca84: 9108c042  add      x2, x2, #0x230
//   0x01ca88: aa1303e1  mov      x1, x19
//   0x01ca8c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0006_sub_01ca50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD0000242ULL) + (x2 ^ 0x01CA50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01ca50: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01ca54: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01ca58: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000273ULL; // 0x01ca5c: adrp x19, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x911BA273ULL; // 0x01ca60: add x19, x19, #0x6e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x01ca64: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91257021ULL; // 0x01ca68: add x1, x1, #0x95c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01ca6c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC48ULL; // 0x01ca70: bl #0x1bb90
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000240ULL; // 0x01ca74: adrp x0, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0007 @ 0x01ca94..0x01cb9c (264 bytes)
// [VN] Phục dựng FDE #0007 tại 0x01ca94..0x01cb9c (264 byte)
//   0x01ca94: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01ca98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01ca9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01caa0: 910083fd  add      x29, sp, #0x20
//   0x01caa4: b0000273  adrp     x19, #0x69000
//   0x01caa8: 9103c273  add      x19, x19, #0xf0
//   0x01caac: d00001a1  adrp     x1, #0x52000
//   0x01cab0: 91040021  add      x1, x1, #0x100
//   0x01cab4: aa1303e0  mov      x0, x19
//   0x01cab8: 97fffc36  bl       #0x1bb90
//   0x01cabc: f0000254  adrp     x20, #0x67000
//   0x01cac0: f947fe94  ldr      x20, [x20, #0xff8]
//   0x01cac4: d0000255  adrp     x21, #0x66000
//   0x01cac8: 9108c2b5  add      x21, x21, #0x230
//   0x01cacc: aa1303e1  mov      x1, x19
//   0x01cad0: aa1403e0  mov      x0, x20
uint64_t fde_0007_sub_01ca94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD0000255ULL) + (x2 ^ 0x01CA94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01ca94: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01ca98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01ca9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01caa0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000273ULL; // 0x01caa4: adrp x19, #0x69000
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C273ULL; // 0x01caa8: add x19, x19, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x01caac: adrp x1, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x91040021ULL; // 0x01cab0: add x1, x1, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01cab4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC36ULL; // 0x01cab8: bl #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0008 @ 0x01cb9c..0x01cdd8 (572 bytes)
// [VN] Phục dựng FDE #0008 tại 0x01cb9c..0x01cdd8 (572 byte)
//   0x01cb9c: d10143ff  sub      sp, sp, #0x50
//   0x01cba0: f90013f5  str      x21, [sp, #0x20]
//   0x01cba4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01cba8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01cbac: 910103fd  add      x29, sp, #0x40
//   0x01cbb0: d53bd055  mrs      x21, tpidr_el0
//   0x01cbb4: f94016a8  ldr      x8, [x21, #0x28]
//   0x01cbb8: aa0003f3  mov      x19, x0
//   0x01cbbc: f9000fe8  str      x8, [sp, #0x18]
//   0x01cbc0: f0000240  adrp     x0, #0x67000
//   0x01cbc4: f946c400  ldr      x0, [x0, #0xd88]
//   0x01cbc8: 97fff79e  bl       #0x1aa40
//   0x01cbcc: d00001a1  adrp     x1, #0x52000
//   0x01cbd0: 91024021  add      x1, x1, #0x90
//   0x01cbd4: 910003e0  mov      x0, sp
//   0x01cbd8: 97fffbee  bl       #0x1bb90
uint64_t fde_0008_sub_01cb9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xD00001A1ULL) + (x2 ^ 0x01CB9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01cb9c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x01cba0: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01cba4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01cba8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01cbac: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01cbb0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01cbb4: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01cbb8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01cbbc: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000240ULL; // 0x01cbc0: adrp x0, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0009 @ 0x01cdd8..0x01ce70 (152 bytes)
// [VN] Phục dựng FDE #0009 tại 0x01cdd8..0x01ce70 (152 byte)
//   0x01cdd8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01cddc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01cde0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01cde4: 910083fd  add      x29, sp, #0x20
//   0x01cde8: aa0003f3  mov      x19, x0
//   0x01cdec: a9007c1f  stp      xzr, xzr, [x0]
//   0x01cdf0: f900081f  str      xzr, [x0, #0x10]
//   0x01cdf4: aa0103e0  mov      x0, x1
//   0x01cdf8: aa0103f4  mov      x20, x1
//   0x01cdfc: 97fff89d  bl       #0x1b070
//   0x01ce00: b100401f  cmn      x0, #0x10
//   0x01ce04: 54000322  b.hs     #0x1ce68
//   0x01ce08: aa0003f5  mov      x21, x0
//   0x01ce0c: f1005c1f  cmp      x0, #0x17
//   0x01ce10: 540000a2  b.hs     #0x1ce24
//   0x01ce14: 531f7aa8  lsl      w8, w21, #1
uint64_t fde_0009_sub_01cdd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x01CDD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01cdd8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01cddc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01cde0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01cde4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01cde8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x01cdec: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x01cdf0: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x01cdf4: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01cdf8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF89DULL; // 0x01cdfc: bl #0x1b070
    return acc;
}

// [EN] Reconstructed FDE #0010 @ 0x01ce70..0x01ce7c (12 bytes)
// [VN] Phục dựng FDE #0010 tại 0x01ce70..0x01ce7c (12 byte)
//   0x01ce70: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x01ce74: 97fffa9b  bl       #0x1b8e0
//   0x01ce78: 97fffc46  bl       #0x1bf90
uint64_t fde_0010_sub_01ce70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x97FFFC46ULL) + (x2 ^ 0x01CE70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x01ce70: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFA9BULL; // 0x01ce74: bl #0x1b8e0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC46ULL; // 0x01ce78: bl #0x1bf90
    return acc;
}

// [EN] Reconstructed FDE #0011 @ 0x01ce7c..0x01ce90 (20 bytes)
// [VN] Phục dựng FDE #0011 tại 0x01ce7c..0x01ce90 (20 byte)
//   0x01ce7c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01ce80: 910003fd  mov      x29, sp
//   0x01ce84: d00001a0  adrp     x0, #0x52000
//   0x01ce88: 91033000  add      x0, x0, #0xcc
//   0x01ce8c: 94000001  bl       #0x1ce90
uint64_t fde_0011_sub_01ce7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000001ULL) + (x2 ^ 0x01CE7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01ce7c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01ce80: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A0ULL; // 0x01ce84: adrp x0, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x91033000ULL; // 0x01ce88: add x0, x0, #0xcc
    acc = (acc * 0x100000001B3ULL) ^ 0x94000001ULL; // 0x01ce8c: bl #0x1ce90
    return acc;
}

// [EN] Reconstructed FDE #0012 @ 0x01ce90..0x01cee0 (80 bytes)
// [VN] Phục dựng FDE #0012 tại 0x01ce90..0x01cee0 (80 byte)
//   0x01ce90: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01ce94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01ce98: 910043fd  add      x29, sp, #0x10
//   0x01ce9c: aa0003f4  mov      x20, x0
//   0x01cea0: 52800200  mov      w0, #0x10
//   0x01cea4: 97fff773  bl       #0x1ac70
//   0x01cea8: aa0003f3  mov      x19, x0
//   0x01ceac: aa1403e1  mov      x1, x20
//   0x01ceb0: 9400000c  bl       #0x1cee0
//   0x01ceb4: f0000241  adrp     x1, #0x67000
//   0x01ceb8: f0000242  adrp     x2, #0x67000
//   0x01cebc: f9472c21  ldr      x1, [x1, #0xe58]
//   0x01cec0: f946e442  ldr      x2, [x2, #0xdc8]
//   0x01cec4: aa1303e0  mov      x0, x19
//   0x01cec8: 97fffa9e  bl       #0x1b940
//   0x01cecc: aa0003f4  mov      x20, x0
uint64_t fde_0012_sub_01ce90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF946E442ULL) + (x2 ^ 0x01CE90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01ce90: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01ce94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01ce98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01ce9c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x01cea0: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF773ULL; // 0x01cea4: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01cea8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x01ceac: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x01ceb0: bl #0x1cee0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000241ULL; // 0x01ceb4: adrp x1, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0013 @ 0x01cee0..0x01cf10 (48 bytes)
// [VN] Phục dựng FDE #0013 tại 0x01cee0..0x01cf10 (48 byte)
//   0x01cee0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01cee4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01cee8: 910043fd  add      x29, sp, #0x10
//   0x01ceec: aa0003f3  mov      x19, x0
//   0x01cef0: 97fff70c  bl       #0x1ab20
//   0x01cef4: f0000248  adrp     x8, #0x67000
//   0x01cef8: f9474108  ldr      x8, [x8, #0xe80]
//   0x01cefc: 91004108  add      x8, x8, #0x10
//   0x01cf00: f9000268  str      x8, [x19]
//   0x01cf04: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01cf08: f84207f3  ldr      x19, [sp], #0x20
//   0x01cf0c: d65f03c0  ret      
uint64_t fde_0013_sub_01cee0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01CEE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01cee0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01cee4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01cee8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01ceec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF70CULL; // 0x01cef0: bl #0x1ab20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000248ULL; // 0x01cef4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9474108ULL; // 0x01cef8: ldr x8, [x8, #0xe80]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x01cefc: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x01cf00: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01cf04: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0014 @ 0x01cf10..0x01d024 (276 bytes)
// [VN] Phục dựng FDE #0014 tại 0x01cf10..0x01d024 (276 byte)
//   0x01cf10: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x01cf14: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01cf18: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01cf1c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01cf20: 9100c3fd  add      x29, sp, #0x30
//   0x01cf24: aa0003f3  mov      x19, x0
//   0x01cf28: f8408e77  ldr      x23, [x19, #8]!
//   0x01cf2c: b40006f7  cbz      x23, #0x1d008
//   0x01cf30: 39400028  ldrb     w8, [x1]
//   0x01cf34: a940a829  ldp      x9, x10, [x1, #8]
//   0x01cf38: aa1303f4  mov      x20, x19
//   0x01cf3c: d341fd0b  lsr      x11, x8, #1
//   0x01cf40: 7200011f  tst      w8, #1
//   0x01cf44: 9a890176  csel     x22, x11, x9, eq
//   0x01cf48: 9a811555  csinc    x21, x10, x1, ne
//   0x01cf4c: 1400000a  b        #0x1cf74
uint64_t fde_0014_sub_01cf10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x7200011FULL) + (x2 ^ 0x01CF10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01cf10: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01cf14: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01cf18: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01cf1c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01cf20: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01cf24: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E77ULL; // 0x01cf28: ldr x23, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006F7ULL; // 0x01cf2c: cbz x23, #0x1d008
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x01cf30: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A829ULL; // 0x01cf34: ldp x9, x10, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0015 @ 0x01d024..0x01d1c4 (416 bytes)
// [VN] Phục dựng FDE #0015 tại 0x01d024..0x01d1c4 (416 byte)
//   0x01d024: d101c3ff  sub      sp, sp, #0x70
//   0x01d028: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x01d02c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01d030: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01d034: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01d038: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01d03c: 910183fd  add      x29, sp, #0x60
//   0x01d040: d53bd059  mrs      x25, tpidr_el0
//   0x01d044: f9401728  ldr      x8, [x25, #0x28]
//   0x01d048: aa0003f3  mov      x19, x0
//   0x01d04c: f9000fe8  str      x8, [sp, #0x18]
//   0x01d050: 390003ff  strb     wzr, [sp]
//   0x01d054: f90007e0  str      x0, [sp, #8]
//   0x01d058: f9400008  ldr      x8, [x0]
//   0x01d05c: f85e8109  ldur     x9, [x8, #-0x18]
//   0x01d060: 8b090009  add      x9, x0, x9
uint64_t fde_0015_sub_01d024(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90007E0ULL) + (x2 ^ 0x01D024ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01d024: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x01d028: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01d02c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01d030: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01d034: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01d038: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01d03c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01d040: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x01d044: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01d048: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0016 @ 0x01d1c4..0x01d374 (432 bytes)
// [VN] Phục dựng FDE #0016 tại 0x01d1c4..0x01d374 (432 byte)
//   0x01d1c4: d10203ff  sub      sp, sp, #0x80
//   0x01d1c8: f90013fb  str      x27, [sp, #0x20]
//   0x01d1cc: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x01d1d0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01d1d4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01d1d8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01d1dc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01d1e0: 9101c3fd  add      x29, sp, #0x70
//   0x01d1e4: d53bd05b  mrs      x27, tpidr_el0
//   0x01d1e8: f9401768  ldr      x8, [x27, #0x28]
//   0x01d1ec: aa0003f3  mov      x19, x0
//   0x01d1f0: f9000fe8  str      x8, [sp, #0x18]
//   0x01d1f4: b4000960  cbz      x0, #0x1d320
//   0x01d1f8: f9400c88  ldr      x8, [x4, #0x18]
//   0x01d1fc: cb010069  sub      x9, x3, x1
//   0x01d200: cb010059  sub      x25, x2, x1
uint64_t fde_0016_sub_01d1c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xB4000960ULL) + (x2 ^ 0x01D1C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01d1c4: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x01d1c8: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x01d1cc: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01d1d0: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01d1d4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01d1d8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01d1dc: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01d1e0: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x01d1e4: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x01d1e8: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0017 @ 0x01d374..0x01d414 (160 bytes)
// [VN] Phục dựng FDE #0017 tại 0x01d374..0x01d414 (160 byte)
//   0x01d374: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01d378: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01d37c: 910043fd  add      x29, sp, #0x10
//   0x01d380: f9400408  ldr      x8, [x0, #8]
//   0x01d384: f9400109  ldr      x9, [x8]
//   0x01d388: f85e8129  ldur     x9, [x9, #-0x18]
//   0x01d38c: 8b090108  add      x8, x8, x9
//   0x01d390: f9401509  ldr      x9, [x8, #0x28]
//   0x01d394: b4000329  cbz      x9, #0x1d3f8
//   0x01d398: b9402109  ldr      w9, [x8, #0x20]
//   0x01d39c: 350002e9  cbnz     w9, #0x1d3f8
//   0x01d3a0: 39402508  ldrb     w8, [x8, #9]
//   0x01d3a4: 362802a8  tbz      w8, #5, #0x1d3f8
//   0x01d3a8: aa0003f3  mov      x19, x0
//   0x01d3ac: 97fffb29  bl       #0x1c050
//   0x01d3b0: 37000240  tbnz     w0, #0, #0x1d3f8
uint64_t fde_0017_sub_01d374(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x362802A8ULL) + (x2 ^ 0x01D374ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01d374: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01d378: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01d37c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x01d380: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x01d384: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8129ULL; // 0x01d388: ldur x9, [x9, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090108ULL; // 0x01d38c: add x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x01d390: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000329ULL; // 0x01d394: cbz x9, #0x1d3f8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402109ULL; // 0x01d398: ldr w9, [x8, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0018 @ 0x01d414..0x01d530 (284 bytes)
// [VN] Phục dựng FDE #0018 tại 0x01d414..0x01d530 (284 byte)
//   0x01d414: d10143ff  sub      sp, sp, #0x50
//   0x01d418: f90013f5  str      x21, [sp, #0x20]
//   0x01d41c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01d420: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01d424: 910103fd  add      x29, sp, #0x40
//   0x01d428: d53bd055  mrs      x21, tpidr_el0
//   0x01d42c: f94016a8  ldr      x8, [x21, #0x28]
//   0x01d430: aa0003f3  mov      x19, x0
//   0x01d434: f9000fe8  str      x8, [sp, #0x18]
//   0x01d438: f9400008  ldr      x8, [x0]
//   0x01d43c: f85e8109  ldur     x9, [x8, #-0x18]
//   0x01d440: 8b090009  add      x9, x0, x9
//   0x01d444: f9401529  ldr      x9, [x9, #0x28]
//   0x01d448: b40003a9  cbz      x9, #0x1d4bc
//   0x01d44c: 390023ff  strb     wzr, [sp, #8]
//   0x01d450: f9000bf3  str      x19, [sp, #0x10]
uint64_t fde_0018_sub_01d414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9401529ULL) + (x2 ^ 0x01D414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01d414: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x01d418: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01d41c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01d420: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01d424: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01d428: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01d42c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01d430: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01d434: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01d438: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0019 @ 0x01d530..0x01d664 (308 bytes)
// [VN] Phục dựng FDE #0019 tại 0x01d530..0x01d664 (308 byte)
//   0x01d530: d10143ff  sub      sp, sp, #0x50
//   0x01d534: f90013f5  str      x21, [sp, #0x20]
//   0x01d538: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01d53c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01d540: 910103fd  add      x29, sp, #0x40
//   0x01d544: d53bd055  mrs      x21, tpidr_el0
//   0x01d548: f94016a8  ldr      x8, [x21, #0x28]
//   0x01d54c: aa0003f3  mov      x19, x0
//   0x01d550: f9000fe8  str      x8, [sp, #0x18]
//   0x01d554: 390023ff  strb     wzr, [sp, #8]
//   0x01d558: f9000be0  str      x0, [sp, #0x10]
//   0x01d55c: f9400008  ldr      x8, [x0]
//   0x01d560: f85e8109  ldur     x9, [x8, #-0x18]
//   0x01d564: 8b090009  add      x9, x0, x9
//   0x01d568: b940212a  ldr      w10, [x9, #0x20]
//   0x01d56c: 350003ea  cbnz     w10, #0x1d5e8
uint64_t fde_0019_sub_01d530(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF85E8109ULL) + (x2 ^ 0x01D530ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01d530: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x01d534: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01d538: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01d53c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01d540: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01d544: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01d548: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01d54c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01d550: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x390023FFULL; // 0x01d554: strb wzr, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0020 @ 0x01d664..0x01d678 (20 bytes)
// [VN] Phục dựng FDE #0020 tại 0x01d664..0x01d678 (20 byte)
//   0x01d664: 39400008  ldrb     w8, [x0]
//   0x01d668: 37000048  tbnz     w8, #0, #0x1d670
//   0x01d66c: d65f03c0  ret      
//   0x01d670: f9400800  ldr      x0, [x0, #0x10]
//   0x01d674: 17fff503  b        #0x1aa80
uint64_t fde_0020_sub_01d664(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0x17FFF503ULL) + (x2 ^ 0x01D664ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x01d664: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000048ULL; // 0x01d668: tbnz w8, #0, #0x1d670
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01d66c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x01d670: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF503ULL; // 0x01d674: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0021 @ 0x01d678..0x01d6a8 (48 bytes)
// [VN] Phục dựng FDE #0021 tại 0x01d678..0x01d6a8 (48 byte)
//   0x01d678: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01d67c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01d680: 910043fd  add      x29, sp, #0x10
//   0x01d684: aa0003f3  mov      x19, x0
//   0x01d688: 91016000  add      x0, x0, #0x58
//   0x01d68c: 97fff6c5  bl       #0x1b1a0
//   0x01d690: 9100a260  add      x0, x19, #0x28
//   0x01d694: 97fff6c3  bl       #0x1b1a0
//   0x01d698: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01d69c: aa1303e0  mov      x0, x19
//   0x01d6a0: f84207f3  ldr      x19, [sp], #0x20
//   0x01d6a4: 17fffa1b  b        #0x1bf10
uint64_t fde_0021_sub_01d678(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFFA1BULL) + (x2 ^ 0x01D678ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01d678: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01d67c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01d680: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01d684: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91016000ULL; // 0x01d688: add x0, x0, #0x58
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF6C5ULL; // 0x01d68c: bl #0x1b1a0
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A260ULL; // 0x01d690: add x0, x19, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF6C3ULL; // 0x01d694: bl #0x1b1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01d698: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01d69c: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0022 @ 0x01d6a8..0x01d6b4 (12 bytes)
// [VN] Phục dựng FDE #0022 tại 0x01d6a8..0x01d6b4 (12 byte)
//   0x01d6a8: f9400801  ldr      x1, [x0, #0x10]
//   0x01d6ac: 91002000  add      x0, x0, #8
//   0x01d6b0: 17fff820  b        #0x1b730
uint64_t fde_0022_sub_01d6a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400801ULL) + (x1 ^ 0x17FFF820ULL) + (x2 ^ 0x01D6A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x01d6a8: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x01d6ac: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF820ULL; // 0x01d6b0: b #0x1b730
    return acc;
}

// [EN] Reconstructed FDE #0023 @ 0x01d6b4..0x01d88c (472 bytes)
// [VN] Phục dựng FDE #0023 tại 0x01d6b4..0x01d88c (472 byte)
//   0x01d6b4: d10103ff  sub      sp, sp, #0x40
//   0x01d6b8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01d6bc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01d6c0: 9100c3fd  add      x29, sp, #0x30
//   0x01d6c4: d53bd054  mrs      x20, tpidr_el0
//   0x01d6c8: d0000249  adrp     x9, #0x67000
//   0x01d6cc: f9401688  ldr      x8, [x20, #0x28]
//   0x01d6d0: f947d129  ldr      x9, [x9, #0xfa0]
//   0x01d6d4: 528000c2  mov      w2, #6
//   0x01d6d8: 528000d3  mov      w19, #6
//   0x01d6dc: f9000fe8  str      x8, [sp, #0x18]
//   0x01d6e0: f9000120  str      x0, [x9]
//   0x01d6e4: f9400008  ldr      x8, [x0]
//   0x01d6e8: 910023e1  add      x1, sp, #8
//   0x01d6ec: 72a00022  movk     w2, #1, lsl #16
//   0x01d6f0: 72a00033  movk     w19, #1, lsl #16
uint64_t fde_0023_sub_01d6b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x01D6B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01d6b4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01d6b8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01d6bc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01d6c0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x01d6c4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000249ULL; // 0x01d6c8: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x01d6cc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D129ULL; // 0x01d6d0: ldr x9, [x9, #0xfa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C2ULL; // 0x01d6d4: mov w2, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x528000D3ULL; // 0x01d6d8: mov w19, #6
    return acc;
}

// [EN] Reconstructed FDE #0024 @ 0x01d88c..0x01d91c (144 bytes)
// [VN] Phục dựng FDE #0024 tại 0x01d88c..0x01d91c (144 byte)
//   0x01d88c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01d890: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01d894: 910043fd  add      x29, sp, #0x10
//   0x01d898: d0000254  adrp     x20, #0x67000
//   0x01d89c: f9476694  ldr      x20, [x20, #0xec8]
//   0x01d8a0: 2a0003f3  mov      w19, w0
//   0x01d8a4: f9400288  ldr      x8, [x20]
//   0x01d8a8: b4000088  cbz      x8, #0x1d8b8
//   0x01d8ac: aa0803e0  mov      x0, x8
//   0x01d8b0: 97fff53c  bl       #0x1ada0
//   0x01d8b4: f900029f  str      xzr, [x20]
//   0x01d8b8: d0000254  adrp     x20, #0x67000
//   0x01d8bc: f947da94  ldr      x20, [x20, #0xfb0]
//   0x01d8c0: f9400280  ldr      x0, [x20]
//   0x01d8c4: b4000060  cbz      x0, #0x1d8d0
//   0x01d8c8: 97fff536  bl       #0x1ada0
uint64_t fde_0024_sub_01d88c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF947DA94ULL) + (x2 ^ 0x01D88CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01d88c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01d890: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01d894: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000254ULL; // 0x01d898: adrp x20, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9476694ULL; // 0x01d89c: ldr x20, [x20, #0xec8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x01d8a0: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x01d8a4: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x01d8a8: cbz x8, #0x1d8b8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x01d8ac: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF53CULL; // 0x01d8b0: bl #0x1ada0
    return acc;
}

// [EN] Reconstructed FDE #0025 @ 0x01d91c..0x01d980 (100 bytes)
// [VN] Phục dựng FDE #0025 tại 0x01d91c..0x01d980 (100 byte)
//   0x01d91c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01d920: 910003fd  mov      x29, sp
//   0x01d924: d0000248  adrp     x8, #0x67000
//   0x01d928: f947a508  ldr      x8, [x8, #0xf48]
//   0x01d92c: 39400109  ldrb     w9, [x8]
//   0x01d930: f940050a  ldr      x10, [x8, #8]
//   0x01d934: d341fd2b  lsr      x11, x9, #1
//   0x01d938: 7200013f  tst      w9, #1
//   0x01d93c: 9a8a016a  csel     x10, x11, x10, eq
//   0x01d940: f100155f  cmp      x10, #5
//   0x01d944: 54000181  b.ne     #0x1d974
//   0x01d948: f940090a  ldr      x10, [x8, #0x10]
//   0x01d94c: 7200013f  tst      w9, #1
//   0x01d950: b00001a1  adrp     x1, #0x52000
//   0x01d954: 9105ac21  add      x1, x1, #0x16b
//   0x01d958: 9a881540  csinc    x0, x10, x8, ne
uint64_t fde_0025_sub_01d91c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7200013FULL) + (x2 ^ 0x01D91CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01d91c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01d920: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x01d924: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947A508ULL; // 0x01d928: ldr x8, [x8, #0xf48]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x01d92c: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940050AULL; // 0x01d930: ldr x10, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD2BULL; // 0x01d934: lsr x11, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x01d938: tst w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A016AULL; // 0x01d93c: csel x10, x11, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xF100155FULL; // 0x01d940: cmp x10, #5
    return acc;
}

// [EN] Reconstructed FDE #0026 @ 0x01d980..0x01d9e4 (100 bytes)
// [VN] Phục dựng FDE #0026 tại 0x01d980..0x01d9e4 (100 byte)
//   0x01d980: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01d984: 910003fd  mov      x29, sp
//   0x01d988: d0000248  adrp     x8, #0x67000
//   0x01d98c: f947a508  ldr      x8, [x8, #0xf48]
//   0x01d990: 39400109  ldrb     w9, [x8]
//   0x01d994: f940050a  ldr      x10, [x8, #8]
//   0x01d998: d341fd2b  lsr      x11, x9, #1
//   0x01d99c: 7200013f  tst      w9, #1
//   0x01d9a0: 9a8a016a  csel     x10, x11, x10, eq
//   0x01d9a4: f1001d5f  cmp      x10, #7
//   0x01d9a8: 54000181  b.ne     #0x1d9d8
//   0x01d9ac: f940090a  ldr      x10, [x8, #0x10]
//   0x01d9b0: 7200013f  tst      w9, #1
//   0x01d9b4: b00001a1  adrp     x1, #0x52000
//   0x01d9b8: 91047421  add      x1, x1, #0x11d
//   0x01d9bc: 9a881540  csinc    x0, x10, x8, ne
uint64_t fde_0026_sub_01d980(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7200013FULL) + (x2 ^ 0x01D980ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01d980: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01d984: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x01d988: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947A508ULL; // 0x01d98c: ldr x8, [x8, #0xf48]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x01d990: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940050AULL; // 0x01d994: ldr x10, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD2BULL; // 0x01d998: lsr x11, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x01d99c: tst w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A016AULL; // 0x01d9a0: csel x10, x11, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xF1001D5FULL; // 0x01d9a4: cmp x10, #7
    return acc;
}

// [EN] Reconstructed FDE #0027 @ 0x01d9e4..0x01dbf8 (532 bytes)
// [VN] Phục dựng FDE #0027 tại 0x01d9e4..0x01dbf8 (532 byte)
//   0x01d9e4: d10103ff  sub      sp, sp, #0x40
//   0x01d9e8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01d9ec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01d9f0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01d9f4: 9100c3fd  add      x29, sp, #0x30
//   0x01d9f8: d53bd056  mrs      x22, tpidr_el0
//   0x01d9fc: f94016c8  ldr      x8, [x22, #0x28]
//   0x01da00: aa0003f3  mov      x19, x0
//   0x01da04: aa0203f4  mov      x20, x2
//   0x01da08: f90007e8  str      x8, [sp, #8]
//   0x01da0c: f9400008  ldr      x8, [x0]
//   0x01da10: f942a508  ldr      x8, [x8, #0x548]
//   0x01da14: aa0203e1  mov      x1, x2
//   0x01da18: aa1f03e2  mov      x2, xzr
//   0x01da1c: d63f0100  blr      x8
//   0x01da20: aa0003f5  mov      x21, x0
uint64_t fde_0027_sub_01d9e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0203E1ULL) + (x2 ^ 0x01D9E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01d9e4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01d9e8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01d9ec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01d9f0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01d9f4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01d9f8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01d9fc: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01da00: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x01da04: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x01da08: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0028 @ 0x01dbf8..0x01ddf8 (512 bytes)
// [VN] Phục dựng FDE #0028 tại 0x01dbf8..0x01ddf8 (512 byte)
//   0x01dbf8: d10103ff  sub      sp, sp, #0x40
//   0x01dbfc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01dc00: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01dc04: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01dc08: 9100c3fd  add      x29, sp, #0x30
//   0x01dc0c: d53bd056  mrs      x22, tpidr_el0
//   0x01dc10: f94016c9  ldr      x9, [x22, #0x28]
//   0x01dc14: d0000248  adrp     x8, #0x67000
//   0x01dc18: f947a508  ldr      x8, [x8, #0xf48]
//   0x01dc1c: aa0203f4  mov      x20, x2
//   0x01dc20: f90007e9  str      x9, [sp, #8]
//   0x01dc24: aa0003f3  mov      x19, x0
//   0x01dc28: 39400109  ldrb     w9, [x8]
//   0x01dc2c: f940050a  ldr      x10, [x8, #8]
//   0x01dc30: d341fd2b  lsr      x11, x9, #1
//   0x01dc34: 7200013f  tst      w9, #1
uint64_t fde_0028_sub_01dbf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x39400109ULL) + (x2 ^ 0x01DBF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01dbf8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01dbfc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01dc00: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01dc04: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01dc08: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01dc0c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C9ULL; // 0x01dc10: ldr x9, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x01dc14: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947A508ULL; // 0x01dc18: ldr x8, [x8, #0xf48]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x01dc1c: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0029 @ 0x01ddf8..0x01e1fc (1028 bytes)
// [VN] Phục dựng FDE #0029 tại 0x01ddf8..0x01e1fc (1028 byte)
//   0x01ddf8: d10203ff  sub      sp, sp, #0x80
//   0x01ddfc: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x01de00: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x01de04: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01de08: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01de0c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01de10: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01de14: 9101c3fd  add      x29, sp, #0x70
//   0x01de18: b9000fe4  str      w4, [sp, #0xc]
//   0x01de1c: d53bd059  mrs      x25, tpidr_el0
//   0x01de20: f9401728  ldr      x8, [x25, #0x28]
//   0x01de24: aa0503f5  mov      x21, x5
//   0x01de28: 2a0303f8  mov      w24, w3
//   0x01de2c: aa0203f6  mov      x22, x2
//   0x01de30: aa0003f3  mov      x19, x0
//   0x01de34: f9000fe8  str      x8, [sp, #0x18]
uint64_t fde_0029_sub_01ddf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0303F8ULL) + (x2 ^ 0x01DDF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01ddf8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x01ddfc: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x01de00: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01de04: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01de08: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01de0c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01de10: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01de14: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000FE4ULL; // 0x01de18: str w4, [sp, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01de1c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0030 @ 0x01e1fc..0x01e4a8 (684 bytes)
// [VN] Phục dựng FDE #0030 tại 0x01e1fc..0x01e4a8 (684 byte)
//   0x01e1fc: d10143ff  sub      sp, sp, #0x50
//   0x01e200: f9000bf7  str      x23, [sp, #0x10]
//   0x01e204: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01e208: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01e20c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01e210: 910103fd  add      x29, sp, #0x40
//   0x01e214: d53bd057  mrs      x23, tpidr_el0
//   0x01e218: f94016e8  ldr      x8, [x23, #0x28]
//   0x01e21c: aa0003f3  mov      x19, x0
//   0x01e220: aa0103f4  mov      x20, x1
//   0x01e224: f90007e8  str      x8, [sp, #8]
//   0x01e228: f9400008  ldr      x8, [x0]
//   0x01e22c: f9407d08  ldr      x8, [x8, #0xf8]
//   0x01e230: d63f0100  blr      x8
//   0x01e234: aa0003f5  mov      x21, x0
//   0x01e238: b4000800  cbz      x0, #0x1e338
uint64_t fde_0030_sub_01e1fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9407D08ULL) + (x2 ^ 0x01E1FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01e1fc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x01e200: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01e204: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01e208: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01e20c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01e210: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01e214: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01e218: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01e21c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01e220: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0031 @ 0x01e4a8..0x01e534 (140 bytes)
// [VN] Phục dựng FDE #0031 tại 0x01e4a8..0x01e534 (140 byte)
//   0x01e4a8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01e4ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01e4b0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01e4b4: 910083fd  add      x29, sp, #0x20
//   0x01e4b8: aa0003f5  mov      x21, x0
//   0x01e4bc: 52800b00  mov      w0, #0x58
//   0x01e4c0: 2a0203f3  mov      w19, w2
//   0x01e4c4: 2a0103f4  mov      w20, w1
//   0x01e4c8: 97fff5e6  bl       #0x1bc60
//   0x01e4cc: f900281f  str      xzr, [x0, #0x50]
//   0x01e4d0: b0000249  adrp     x9, #0x67000
//   0x01e4d4: f947d929  ldr      x9, [x9, #0xfb0]
//   0x01e4d8: 91012008  add      x8, x0, #0x48
//   0x01e4dc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x01e4e0: aa1503e1  mov      x1, x21
//   0x01e4e4: 2a1403e2  mov      w2, w20
uint64_t fde_0031_sub_01e4a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91012008ULL) + (x2 ^ 0x01E4A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01e4a8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01e4ac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01e4b0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01e4b4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x01e4b8: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800B00ULL; // 0x01e4bc: mov w0, #0x58
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x01e4c0: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x01e4c4: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF5E6ULL; // 0x01e4c8: bl #0x1bc60
    acc = (acc * 0x100000001B3ULL) ^ 0xF900281FULL; // 0x01e4cc: str xzr, [x0, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0032 @ 0x01e534..0x01e5d0 (156 bytes)
// [VN] Phục dựng FDE #0032 tại 0x01e534..0x01e5d0 (156 byte)
//   0x01e534: d10483ff  sub      sp, sp, #0x120
//   0x01e538: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x01e53c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x01e540: 910443fd  add      x29, sp, #0x110
//   0x01e544: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x01e548: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x01e54c: f90057e7  str      x7, [sp, #0xa8]
//   0x01e550: ad0007e0  stp      q0, q1, [sp]
//   0x01e554: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x01e558: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x01e55c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x01e560: d53bd053  mrs      x19, tpidr_el0
//   0x01e564: f940166b  ldr      x11, [x19, #0x28]
//   0x01e568: 928004e8  mov      x8, #-0x28
//   0x01e56c: 910003e9  mov      x9, sp
//   0x01e570: 910223ea  add      x10, sp, #0x88
uint64_t fde_0032_sub_01e534(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x01E534ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x01e534: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x01e538: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x01e53c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x01e540: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x01e544: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x01e548: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x01e54c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x01e550: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x01e554: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x01e558: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0033 @ 0x01e5d0..0x01e9e4 (1044 bytes)
// [VN] Phục dựng FDE #0033 tại 0x01e5d0..0x01e9e4 (1044 byte)
//   0x01e5d0: d10203ff  sub      sp, sp, #0x80
//   0x01e5d4: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x01e5d8: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x01e5dc: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01e5e0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01e5e4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01e5e8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01e5ec: 9101c3fd  add      x29, sp, #0x70
//   0x01e5f0: d53bd059  mrs      x25, tpidr_el0
//   0x01e5f4: f9401728  ldr      x8, [x25, #0x28]
//   0x01e5f8: aa0003f3  mov      x19, x0
//   0x01e5fc: b0000240  adrp     x0, #0x67000
//   0x01e600: aa0403f6  mov      x22, x4
//   0x01e604: f9000fe8  str      x8, [sp, #0x18]
//   0x01e608: f946b000  ldr      x0, [x0, #0xd60]
//   0x01e60c: 2a0303f5  mov      w21, w3
uint64_t fde_0033_sub_01e5d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0403F6ULL) + (x2 ^ 0x01E5D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01e5d0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x01e5d4: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x01e5d8: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01e5dc: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01e5e0: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01e5e4: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01e5e8: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01e5ec: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01e5f0: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x01e5f4: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0034 @ 0x01e9e4..0x01eab8 (212 bytes)
// [VN] Phục dựng FDE #0034 tại 0x01e9e4..0x01eab8 (212 byte)
//   0x01e9e4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x01e9e8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01e9ec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01e9f0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01e9f4: 9100c3fd  add      x29, sp, #0x30
//   0x01e9f8: b0000257  adrp     x23, #0x67000
//   0x01e9fc: f946f6f7  ldr      x23, [x23, #0xde8]
//   0x01ea00: aa0003f6  mov      x22, x0
//   0x01ea04: 52800033  mov      w19, #1
//   0x01ea08: 52800b00  mov      w0, #0x58
//   0x01ea0c: 2a0203f4  mov      w20, w2
//   0x01ea10: 2a0103f5  mov      w21, w1
//   0x01ea14: 390002f3  strb     w19, [x23]
//   0x01ea18: 97fff492  bl       #0x1bc60
//   0x01ea1c: f900281f  str      xzr, [x0, #0x50]
//   0x01ea20: b0000249  adrp     x9, #0x67000
uint64_t fde_0034_sub_01e9e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x390002F3ULL) + (x2 ^ 0x01E9E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x01e9e4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01e9e8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01e9ec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01e9f0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01e9f4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000257ULL; // 0x01e9f8: adrp x23, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946F6F7ULL; // 0x01e9fc: ldr x23, [x23, #0xde8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x01ea00: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800033ULL; // 0x01ea04: mov w19, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800B00ULL; // 0x01ea08: mov w0, #0x58
    return acc;
}

// [EN] Reconstructed FDE #0035 @ 0x01eab8..0x01eb00 (72 bytes)
// [VN] Phục dựng FDE #0035 tại 0x01eab8..0x01eb00 (72 byte)
//   0x01eab8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01eabc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01eac0: 910043fd  add      x29, sp, #0x10
//   0x01eac4: b0000253  adrp     x19, #0x67000
//   0x01eac8: f9473273  ldr      x19, [x19, #0xe60]
//   0x01eacc: aa1303e0  mov      x0, x19
//   0x01ead0: 97fff570  bl       #0x1c090
//   0x01ead4: b0000248  adrp     x8, #0x67000
//   0x01ead8: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x01eadc: 52800029  mov      w9, #1
//   0x01eae0: b0000240  adrp     x0, #0x67000
//   0x01eae4: 39000109  strb     w9, [x8]
//   0x01eae8: f946a800  ldr      x0, [x0, #0xd50]
//   0x01eaec: 97fff26d  bl       #0x1b4a0
//   0x01eaf0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01eaf4: aa1303e0  mov      x0, x19
uint64_t fde_0035_sub_01eab8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF946A800ULL) + (x2 ^ 0x01EAB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01eab8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01eabc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01eac0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000253ULL; // 0x01eac4: adrp x19, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473273ULL; // 0x01eac8: ldr x19, [x19, #0xe60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01eacc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF570ULL; // 0x01ead0: bl #0x1c090
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000248ULL; // 0x01ead4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947ED08ULL; // 0x01ead8: ldr x8, [x8, #0xfd8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x01eadc: mov w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0036 @ 0x01eb00..0x01eb44 (68 bytes)
// [VN] Phục dựng FDE #0036 tại 0x01eb00..0x01eb44 (68 byte)
//   0x01eb00: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01eb04: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01eb08: 910043fd  add      x29, sp, #0x10
//   0x01eb0c: b0000248  adrp     x8, #0x67000
//   0x01eb10: f946f508  ldr      x8, [x8, #0xde8]
//   0x01eb14: b0000253  adrp     x19, #0x67000
//   0x01eb18: 3900011f  strb     wzr, [x8]
//   0x01eb1c: f946d673  ldr      x19, [x19, #0xda8]
//   0x01eb20: aa1303e0  mov      x0, x19
//   0x01eb24: 97fff55b  bl       #0x1c090
//   0x01eb28: b0000240  adrp     x0, #0x67000
//   0x01eb2c: f946cc00  ldr      x0, [x0, #0xd98]
//   0x01eb30: 97fff25c  bl       #0x1b4a0
//   0x01eb34: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01eb38: aa1303e0  mov      x0, x19
//   0x01eb3c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0036_sub_01eb00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFF25CULL) + (x2 ^ 0x01EB00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01eb00: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01eb04: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01eb08: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000248ULL; // 0x01eb0c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946F508ULL; // 0x01eb10: ldr x8, [x8, #0xde8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000253ULL; // 0x01eb14: adrp x19, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x3900011FULL; // 0x01eb18: strb wzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D673ULL; // 0x01eb1c: ldr x19, [x19, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01eb20: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF55BULL; // 0x01eb24: bl #0x1c090
    return acc;
}

// [EN] Reconstructed FDE #0037 @ 0x01eb44..0x01ed58 (532 bytes)
// [VN] Phục dựng FDE #0037 tại 0x01eb44..0x01ed58 (532 byte)
//   0x01eb44: d10183ff  sub      sp, sp, #0x60
//   0x01eb48: f9001bf5  str      x21, [sp, #0x30]
//   0x01eb4c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01eb50: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01eb54: 910143fd  add      x29, sp, #0x50
//   0x01eb58: d53bd055  mrs      x21, tpidr_el0
//   0x01eb5c: f94016a8  ldr      x8, [x21, #0x28]
//   0x01eb60: aa0003f3  mov      x19, x0
//   0x01eb64: b0000240  adrp     x0, #0x67000
//   0x01eb68: f90017e8  str      x8, [sp, #0x28]
//   0x01eb6c: f946b000  ldr      x0, [x0, #0xd60]
//   0x01eb70: 97fff008  bl       #0x1ab90
//   0x01eb74: aa0003f4  mov      x20, x0
//   0x01eb78: b0000240  adrp     x0, #0x67000
//   0x01eb7c: f9473000  ldr      x0, [x0, #0xe60]
//   0x01eb80: 97fff544  bl       #0x1c090
uint64_t fde_0037_sub_01eb44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x01EB44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x01eb44: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x01eb48: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01eb4c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01eb50: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01eb54: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01eb58: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01eb5c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01eb60: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000240ULL; // 0x01eb64: adrp x0, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x01eb68: str x8, [sp, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0038 @ 0x01ed58..0x01f0e4 (908 bytes)
// [VN] Phục dựng FDE #0038 tại 0x01ed58..0x01f0e4 (908 byte)
//   0x01ed58: d10343ff  sub      sp, sp, #0xd0
//   0x01ed5c: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x01ed60: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x01ed64: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x01ed68: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x01ed6c: 910303fd  add      x29, sp, #0xc0
//   0x01ed70: d53bd056  mrs      x22, tpidr_el0
//   0x01ed74: f94016c8  ldr      x8, [x22, #0x28]
//   0x01ed78: f81c83a8  stur     x8, [x29, #-0x38]
//   0x01ed7c: b40018a2  cbz      x2, #0x1f090
//   0x01ed80: 910063e8  add      x8, sp, #0x18
//   0x01ed84: aa0203e1  mov      x1, x2
//   0x01ed88: aa0003f3  mov      x19, x0
//   0x01ed8c: 91002117  add      x23, x8, #8
//   0x01ed90: a9027fff  stp      xzr, xzr, [sp, #0x20]
//   0x01ed94: f9000ff7  str      x23, [sp, #0x18]
uint64_t fde_0038_sub_01ed58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x01ED58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x01ed58: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x01ed5c: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x01ed60: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x01ed64: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x01ed68: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x01ed6c: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01ed70: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01ed74: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x01ed78: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40018A2ULL; // 0x01ed7c: cbz x2, #0x1f090
    return acc;
}

// [EN] Reconstructed FDE #0039 @ 0x01f0e4..0x01f5dc (1272 bytes)
// [VN] Phục dựng FDE #0039 tại 0x01f0e4..0x01f5dc (1272 byte)
//   0x01f0e4: d10443ff  sub      sp, sp, #0x110
//   0x01f0e8: a90b6ffc  stp      x28, x27, [sp, #0xb0]
//   0x01f0ec: a90c67fa  stp      x26, x25, [sp, #0xc0]
//   0x01f0f0: a90d5ff8  stp      x24, x23, [sp, #0xd0]
//   0x01f0f4: a90e57f6  stp      x22, x21, [sp, #0xe0]
//   0x01f0f8: a90f4ff4  stp      x20, x19, [sp, #0xf0]
//   0x01f0fc: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x01f100: 910403fd  add      x29, sp, #0x100
//   0x01f104: d53bd048  mrs      x8, tpidr_el0
//   0x01f108: f9000fe8  str      x8, [sp, #0x18]
//   0x01f10c: f9401508  ldr      x8, [x8, #0x28]
//   0x01f110: 910203e9  add      x9, sp, #0x80
//   0x01f114: aa0203f3  mov      x19, x2
//   0x01f118: aa0003f4  mov      x20, x0
//   0x01f11c: 9100213b  add      x27, x9, #8
//   0x01f120: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0039_sub_01f0e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0xAA0203F3ULL) + (x2 ^ 0x01F0E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x01f0e4: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B6FFCULL; // 0x01f0e8: stp x28, x27, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C67FAULL; // 0x01f0ec: stp x26, x25, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D5FF8ULL; // 0x01f0f0: stp x24, x23, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E57F6ULL; // 0x01f0f4: stp x22, x21, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FF4ULL; // 0x01f0f8: stp x20, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x01f0fc: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x01f100: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x01f104: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01f108: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0040 @ 0x01f5dc..0x01f608 (44 bytes)
// [VN] Phục dựng FDE #0040 tại 0x01f5dc..0x01f608 (44 byte)
//   0x01f5dc: 90000248  adrp     x8, #0x67000
//   0x01f5e0: 90000249  adrp     x9, #0x67000
//   0x01f5e4: f947c508  ldr      x8, [x8, #0xf88]
//   0x01f5e8: f947f929  ldr      x9, [x9, #0xff0]
//   0x01f5ec: 39400100  ldrb     w0, [x8]
//   0x01f5f0: 39400129  ldrb     w9, [x9]
//   0x01f5f4: 34000089  cbz      w9, #0x1f604
//   0x01f5f8: 72001c5f  tst      w2, #0xff
//   0x01f5fc: 1a9f07e9  cset     w9, ne
//   0x01f600: 39000109  strb     w9, [x8]
//   0x01f604: d65f03c0  ret      
uint64_t fde_0040_sub_01f5dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000248ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F5DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000248ULL; // 0x01f5dc: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000249ULL; // 0x01f5e0: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947C508ULL; // 0x01f5e4: ldr x8, [x8, #0xf88]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947F929ULL; // 0x01f5e8: ldr x9, [x9, #0xff0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400100ULL; // 0x01f5ec: ldrb w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400129ULL; // 0x01f5f0: ldrb w9, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000089ULL; // 0x01f5f4: cbz w9, #0x1f604
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x01f5f8: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E9ULL; // 0x01f5fc: cset w9, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x39000109ULL; // 0x01f600: strb w9, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0041 @ 0x01f608..0x01f820 (536 bytes)
// [VN] Phục dựng FDE #0041 tại 0x01f608..0x01f820 (536 byte)
//   0x01f608: d10143ff  sub      sp, sp, #0x50
//   0x01f60c: f9000bf7  str      x23, [sp, #0x10]
//   0x01f610: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01f614: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01f618: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01f61c: 910103fd  add      x29, sp, #0x40
//   0x01f620: d53bd056  mrs      x22, tpidr_el0
//   0x01f624: f94016c8  ldr      x8, [x22, #0x28]
//   0x01f628: aa0203f4  mov      x20, x2
//   0x01f62c: aa0003f3  mov      x19, x0
//   0x01f630: f90007e8  str      x8, [sp, #8]
//   0x01f634: 90000240  adrp     x0, #0x67000
//   0x01f638: f946c400  ldr      x0, [x0, #0xd88]
//   0x01f63c: 97fff2ad  bl       #0x1c0f0
//   0x01f640: 90000257  adrp     x23, #0x67000
//   0x01f644: f946daf7  ldr      x23, [x23, #0xdb0]
uint64_t fde_0041_sub_01f608(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF946C400ULL) + (x2 ^ 0x01F608ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01f608: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x01f60c: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01f610: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01f614: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01f618: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01f61c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01f620: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01f624: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x01f628: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f62c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0042 @ 0x01f820..0x01f860 (64 bytes)
// [VN] Phục dựng FDE #0042 tại 0x01f820..0x01f860 (64 byte)
//   0x01f820: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01f824: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f828: 910043fd  add      x29, sp, #0x10
//   0x01f82c: 52800100  mov      w0, #8
//   0x01f830: 2a0203f3  mov      w19, w2
//   0x01f834: 97fff10b  bl       #0x1bc60
//   0x01f838: 90000248  adrp     x8, #0x67000
//   0x01f83c: f946ed08  ldr      x8, [x8, #0xdd8]
//   0x01f840: aa0003e1  mov      x1, x0
//   0x01f844: aa1f03e2  mov      x2, xzr
//   0x01f848: 91004108  add      x8, x8, #0x10
//   0x01f84c: f9000008  str      x8, [x0]
//   0x01f850: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f854: 2a1303e0  mov      w0, w19
//   0x01f858: f84207f3  ldr      x19, [sp], #0x20
//   0x01f85c: 17fff185  b        #0x1be70
uint64_t fde_0042_sub_01f820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x01F820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01f820: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f824: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f828: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x01f82c: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x01f830: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF10BULL; // 0x01f834: bl #0x1bc60
    acc = (acc * 0x100000001B3ULL) ^ 0x90000248ULL; // 0x01f838: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946ED08ULL; // 0x01f83c: ldr x8, [x8, #0xdd8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x01f840: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f844: mov x2, xzr
    return acc;
}

// [EN] Reconstructed FDE #0043 @ 0x01f860..0x01fb44 (740 bytes)
// [VN] Phục dựng FDE #0043 tại 0x01f860..0x01fb44 (740 byte)
//   0x01f860: d10243ff  sub      sp, sp, #0x90
//   0x01f864: f90023f9  str      x25, [sp, #0x40]
//   0x01f868: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x01f86c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x01f870: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x01f874: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01f878: 910203fd  add      x29, sp, #0x80
//   0x01f87c: d53bd059  mrs      x25, tpidr_el0
//   0x01f880: f9401728  ldr      x8, [x25, #0x28]
//   0x01f884: 2a0003f7  mov      w23, w0
//   0x01f888: 90000240  adrp     x0, #0x67000
//   0x01f88c: aa0203f6  mov      x22, x2
//   0x01f890: f9001fe8  str      x8, [sp, #0x38]
//   0x01f894: f946b000  ldr      x0, [x0, #0xd60]
//   0x01f898: aa0103f5  mov      x21, x1
//   0x01f89c: 97ffecbd  bl       #0x1ab90
uint64_t fde_0043_sub_01f860(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x01F860ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01f860: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x01f864: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x01f868: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x01f86c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x01f870: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x01f874: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01f878: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01f87c: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x01f880: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F7ULL; // 0x01f884: mov w23, w0
    return acc;
}

// [EN] Reconstructed FDE #0044 @ 0x01fb44..0x01fbe8 (164 bytes)
// [VN] Phục dựng FDE #0044 tại 0x01fb44..0x01fbe8 (164 byte)
//   0x01fb44: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01fb48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01fb4c: 910043fd  add      x29, sp, #0x10
//   0x01fb50: 90000240  adrp     x0, #0x67000
//   0x01fb54: f946c400  ldr      x0, [x0, #0xd88]
//   0x01fb58: 97fff166  bl       #0x1c0f0
//   0x01fb5c: 90000253  adrp     x19, #0x67000
//   0x01fb60: f9476673  ldr      x19, [x19, #0xec8]
//   0x01fb64: f9400260  ldr      x0, [x19]
//   0x01fb68: b4000060  cbz      x0, #0x1fb74
//   0x01fb6c: 97ffec8d  bl       #0x1ada0
//   0x01fb70: f900027f  str      xzr, [x19]
//   0x01fb74: 90000253  adrp     x19, #0x67000
//   0x01fb78: f947da73  ldr      x19, [x19, #0xfb0]
//   0x01fb7c: f9400260  ldr      x0, [x19]
//   0x01fb80: b4000060  cbz      x0, #0x1fb8c
uint64_t fde_0044_sub_01fb44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x90000253ULL) + (x2 ^ 0x01FB44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01fb44: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01fb48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01fb4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000240ULL; // 0x01fb50: adrp x0, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C400ULL; // 0x01fb54: ldr x0, [x0, #0xd88]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF166ULL; // 0x01fb58: bl #0x1c0f0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000253ULL; // 0x01fb5c: adrp x19, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9476673ULL; // 0x01fb60: ldr x19, [x19, #0xec8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01fb64: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01fb68: cbz x0, #0x1fb74
    return acc;
}

// [EN] Reconstructed FDE #0045 @ 0x01fbe8..0x0206a0 (2744 bytes)
// [VN] Phục dựng FDE #0045 tại 0x01fbe8..0x0206a0 (2744 byte)
//   0x01fbe8: d107c3ff  sub      sp, sp, #0x1f0
//   0x01fbec: a9196ffc  stp      x28, x27, [sp, #0x190]
//   0x01fbf0: a91a67fa  stp      x26, x25, [sp, #0x1a0]
//   0x01fbf4: a91b5ff8  stp      x24, x23, [sp, #0x1b0]
//   0x01fbf8: a91c57f6  stp      x22, x21, [sp, #0x1c0]
//   0x01fbfc: a91d4ff4  stp      x20, x19, [sp, #0x1d0]
//   0x01fc00: a91e7bfd  stp      x29, x30, [sp, #0x1e0]
//   0x01fc04: 910783fd  add      x29, sp, #0x1e0
//   0x01fc08: f90027e2  str      x2, [sp, #0x48]
//   0x01fc0c: d53bd054  mrs      x20, tpidr_el0
//   0x01fc10: f9401688  ldr      x8, [x20, #0x28]
//   0x01fc14: aa0003fa  mov      x26, x0
//   0x01fc18: 90000240  adrp     x0, #0x67000
//   0x01fc1c: aa0503f8  mov      x24, x5
//   0x01fc20: f81a03a8  stur     x8, [x29, #-0x60]
//   0x01fc24: f946b000  ldr      x0, [x0, #0xd60]
uint64_t fde_0045_sub_01fbe8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD107C3FFULL) + (x1 ^ 0x90000240ULL) + (x2 ^ 0x01FBE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD107C3FFULL; // 0x01fbe8: sub sp, sp, #0x1f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9196FFCULL; // 0x01fbec: stp x28, x27, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A67FAULL; // 0x01fbf0: stp x26, x25, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B5FF8ULL; // 0x01fbf4: stp x24, x23, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C57F6ULL; // 0x01fbf8: stp x22, x21, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91D4FF4ULL; // 0x01fbfc: stp x20, x19, [sp, #0x1d0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91E7BFDULL; // 0x01fc00: stp x29, x30, [sp, #0x1e0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910783FDULL; // 0x01fc04: add x29, sp, #0x1e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90027E2ULL; // 0x01fc08: str x2, [sp, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x01fc0c: mrs x20, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0046 @ 0x0206a0..0x020834 (404 bytes)
// [VN] Phục dựng FDE #0046 tại 0x0206a0..0x020834 (404 byte)
//   0x0206a0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0206a4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0206a8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0206ac: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0206b0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0206b4: 910103fd  add      x29, sp, #0x40
//   0x0206b8: a9007c1f  stp      xzr, xzr, [x0]
//   0x0206bc: f900081f  str      xzr, [x0, #0x10]
//   0x0206c0: b4000742  cbz      x2, #0x207a8
//   0x0206c4: b201f3e8  mov      x8, #-0x5555555555555556
//   0x0206c8: f2955568  movk     x8, #0xaaab
//   0x0206cc: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x0206d0: aa0003f3  mov      x19, x0
//   0x0206d4: eb08005f  cmp      x2, x8
//   0x0206d8: 54000742  b.hs     #0x207c0
//   0x0206dc: 8b020448  add      x8, x2, x2, lsl #1
uint64_t fde_0046_sub_0206a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0206A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x0206a0: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0206a4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0206a8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0206ac: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0206b0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0206b4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x0206b8: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x0206bc: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000742ULL; // 0x0206c0: cbz x2, #0x207a8
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x0206c4: mov x8, #-0x5555555555555556
    return acc;
}

// [EN] Reconstructed FDE #0047 @ 0x020834..0x020ccc (1176 bytes)
// [VN] Phục dựng FDE #0047 tại 0x020834..0x020ccc (1176 byte)
//   0x020834: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x020838: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02083c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x020840: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x020844: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x020848: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02084c: 910143fd  add      x29, sp, #0x50
//   0x020850: d10703ff  sub      sp, sp, #0x1c0
//   0x020854: d53bd055  mrs      x21, tpidr_el0
//   0x020858: f94016a8  ldr      x8, [x21, #0x28]
//   0x02085c: aa0003f3  mov      x19, x0
//   0x020860: f0000220  adrp     x0, #0x67000
//   0x020864: f9400fb6  ldr      x22, [x29, #0x18]
//   0x020868: f81983a8  stur     x8, [x29, #-0x68]
//   0x02086c: f946b000  ldr      x0, [x0, #0xd60]
//   0x020870: aa0703f7  mov      x23, x7
uint64_t fde_0047_sub_020834(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF9400FB6ULL) + (x2 ^ 0x020834ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x020834: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x020838: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02083c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x020840: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x020844: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x020848: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02084c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x020850: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x020854: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x020858: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0048 @ 0x020ccc..0x020cd0 (4 bytes)
// [VN] Phục dựng FDE #0048 tại 0x020ccc..0x020cd0 (4 byte)
//   0x020ccc: 17ffeae5  b        #0x1b860
uint64_t fde_0048_sub_020ccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEAE5ULL) + (x1 ^ 0x17FFEAE5ULL) + (x2 ^ 0x020CCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEAE5ULL; // 0x020ccc: b #0x1b860
    return acc;
}

// [EN] Reconstructed FDE #0049 @ 0x020cd0..0x020d0c (60 bytes)
// [VN] Phục dựng FDE #0049 tại 0x020cd0..0x020d0c (60 byte)
//   0x020cd0: 34000102  cbz      w2, #0x20cf0
//   0x020cd4: 7100045f  cmp      w2, #1
//   0x020cd8: 54000181  b.ne     #0x20d08
//   0x020cdc: f0000228  adrp     x8, #0x67000
//   0x020ce0: f0000229  adrp     x9, #0x67000
//   0x020ce4: f9473908  ldr      x8, [x8, #0xe70]
//   0x020ce8: f946b529  ldr      x9, [x9, #0xd68]
//   0x020cec: 14000005  b        #0x20d00
//   0x020cf0: f0000228  adrp     x8, #0x67000
//   0x020cf4: f0000229  adrp     x9, #0x67000
//   0x020cf8: f946f908  ldr      x8, [x8, #0xdf0]
//   0x020cfc: f9472529  ldr      x9, [x9, #0xe48]
//   0x020d00: f9000120  str      x0, [x9]
//   0x020d04: f9000101  str      x1, [x8]
//   0x020d08: d65f03c0  ret      
uint64_t fde_0049_sub_020cd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000102ULL) + (x1 ^ 0xF9000120ULL) + (x2 ^ 0x020CD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000102ULL; // 0x020cd0: cbz w2, #0x20cf0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x020cd4: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000181ULL; // 0x020cd8: b.ne #0x20d08
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x020cdc: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000229ULL; // 0x020ce0: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473908ULL; // 0x020ce4: ldr x8, [x8, #0xe70]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946B529ULL; // 0x020ce8: ldr x9, [x9, #0xd68]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x020cec: b #0x20d00
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x020cf0: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000229ULL; // 0x020cf4: adrp x9, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0050 @ 0x020d0c..0x020d10 (4 bytes)
// [VN] Phục dựng FDE #0050 tại 0x020d0c..0x020d10 (4 byte)
//   0x020d0c: 17ffead5  b        #0x1b860
uint64_t fde_0050_sub_020d0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEAD5ULL) + (x1 ^ 0x17FFEAD5ULL) + (x2 ^ 0x020D0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEAD5ULL; // 0x020d0c: b #0x1b860
    return acc;
}

// [EN] Reconstructed FDE #0051 @ 0x020d10..0x02100c (764 bytes)
// [VN] Phục dựng FDE #0051 tại 0x020d10..0x02100c (764 byte)
//   0x020d10: d10403ff  sub      sp, sp, #0x100
//   0x020d14: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x020d18: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x020d1c: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x020d20: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x020d24: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x020d28: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x020d2c: 9103c3fd  add      x29, sp, #0xf0
//   0x020d30: a9041be5  stp      x5, x6, [sp, #0x40]
//   0x020d34: d53bd048  mrs      x8, tpidr_el0
//   0x020d38: f90017e8  str      x8, [sp, #0x28]
//   0x020d3c: f9401508  ldr      x8, [x8, #0x28]
//   0x020d40: 2a0003fb  mov      w27, w0
//   0x020d44: f0000220  adrp     x0, #0x67000
//   0x020d48: f9400fb4  ldr      x20, [x29, #0x18]
//   0x020d4c: f81a83a8  stur     x8, [x29, #-0x58]
uint64_t fde_0051_sub_020d10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0x2A0003FBULL) + (x2 ^ 0x020D10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x020d10: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x020d14: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x020d18: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x020d1c: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x020d20: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x020d24: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x020d28: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x020d2c: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9041BE5ULL; // 0x020d30: stp x5, x6, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x020d34: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0052 @ 0x02100c..0x021090 (132 bytes)
// [VN] Phục dựng FDE #0052 tại 0x02100c..0x021090 (132 byte)
//   0x02100c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x021010: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x021014: 910043fd  add      x29, sp, #0x10
//   0x021018: aa0003f3  mov      x19, x0
//   0x02101c: f9407800  ldr      x0, [x0, #0xf0]
//   0x021020: 97ffe760  bl       #0x1ada0
//   0x021024: f9407260  ldr      x0, [x19, #0xe0]
//   0x021028: 97ffe75e  bl       #0x1ada0
//   0x02102c: f9407660  ldr      x0, [x19, #0xe8]
//   0x021030: 97ffe75c  bl       #0x1ada0
//   0x021034: f9409e60  ldr      x0, [x19, #0x138]
//   0x021038: 97ffe75a  bl       #0x1ada0
//   0x02103c: f940a260  ldr      x0, [x19, #0x140]
//   0x021040: 97ffe758  bl       #0x1ada0
//   0x021044: f9409a60  ldr      x0, [x19, #0x130]
//   0x021048: 97ffe756  bl       #0x1ada0
uint64_t fde_0052_sub_02100c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF940A260ULL) + (x2 ^ 0x02100CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02100c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x021010: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x021014: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021018: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9407800ULL; // 0x02101c: ldr x0, [x0, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE760ULL; // 0x021020: bl #0x1ada0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9407260ULL; // 0x021024: ldr x0, [x19, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE75EULL; // 0x021028: bl #0x1ada0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9407660ULL; // 0x02102c: ldr x0, [x19, #0xe8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE75CULL; // 0x021030: bl #0x1ada0
    return acc;
}

// [EN] Reconstructed FDE #0053 @ 0x021090..0x02138c (764 bytes)
// [VN] Phục dựng FDE #0053 tại 0x021090..0x02138c (764 byte)
//   0x021090: d10243ff  sub      sp, sp, #0x90
//   0x021094: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x021098: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02109c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0210a0: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0210a4: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0210a8: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0210ac: 910203fd  add      x29, sp, #0x80
//   0x0210b0: d53bd05c  mrs      x28, tpidr_el0
//   0x0210b4: f9401788  ldr      x8, [x28, #0x28]
//   0x0210b8: aa0003f8  mov      x24, x0
//   0x0210bc: a9425bb7  ldp      x23, x22, [x29, #0x20]
//   0x0210c0: aa0703f9  mov      x25, x7
//   0x0210c4: f90017e8  str      x8, [sp, #0x28]
//   0x0210c8: f9400000  ldr      x0, [x0]
//   0x0210cc: aa0503fb  mov      x27, x5
uint64_t fde_0053_sub_021090(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xAA0703F9ULL) + (x2 ^ 0x021090ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x021090: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x021094: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x021098: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02109c: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x0210a0: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0210a4: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0210a8: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0210ac: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x0210b0: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x0210b4: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0054 @ 0x02138c..0x0215bc (560 bytes)
// [VN] Phục dựng FDE #0054 tại 0x02138c..0x0215bc (560 byte)
//   0x02138c: d10283ff  sub      sp, sp, #0xa0
//   0x021390: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x021394: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x021398: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02139c: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x0213a0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0213a4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0213a8: 910243fd  add      x29, sp, #0x90
//   0x0213ac: d53bd05a  mrs      x26, tpidr_el0
//   0x0213b0: f9401748  ldr      x8, [x26, #0x28]
//   0x0213b4: aa0003f9  mov      x25, x0
//   0x0213b8: d0000220  adrp     x0, #0x67000
//   0x0213bc: aa0503f4  mov      x20, x5
//   0x0213c0: f9001fe8  str      x8, [sp, #0x38]
//   0x0213c4: f946b000  ldr      x0, [x0, #0xd60]
//   0x0213c8: 2a0403f5  mov      w21, w4
uint64_t fde_0054_sub_02138c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xAA0503F4ULL) + (x2 ^ 0x02138CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02138c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x021390: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x021394: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x021398: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02139c: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x0213a0: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x0213a4: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x0213a8: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x0213ac: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x0213b0: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0055 @ 0x0215bc..0x02183c (640 bytes)
// [VN] Phục dựng FDE #0055 tại 0x0215bc..0x02183c (640 byte)
//   0x0215bc: d10243ff  sub      sp, sp, #0x90
//   0x0215c0: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x0215c4: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x0215c8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0215cc: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0215d0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0215d4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0215d8: 910203fd  add      x29, sp, #0x80
//   0x0215dc: b90017e5  str      w5, [sp, #0x14]
//   0x0215e0: d53bd048  mrs      x8, tpidr_el0
//   0x0215e4: f9000fe8  str      x8, [sp, #0x18]
//   0x0215e8: f9401508  ldr      x8, [x8, #0x28]
//   0x0215ec: aa0003f3  mov      x19, x0
//   0x0215f0: aa0703f6  mov      x22, x7
//   0x0215f4: aa0603f8  mov      x24, x6
//   0x0215f8: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0055_sub_0215bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0215BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x0215bc: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x0215c0: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x0215c4: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x0215c8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x0215cc: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0215d0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0215d4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0215d8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB90017E5ULL; // 0x0215dc: str w5, [sp, #0x14]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x0215e0: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0056 @ 0x02183c..0x021a24 (488 bytes)
// [VN] Phục dựng FDE #0056 tại 0x02183c..0x021a24 (488 byte)
//   0x02183c: d10483ff  sub      sp, sp, #0x120
//   0x021840: a90c6ffc  stp      x28, x27, [sp, #0xc0]
//   0x021844: a90d67fa  stp      x26, x25, [sp, #0xd0]
//   0x021848: a90e5ff8  stp      x24, x23, [sp, #0xe0]
//   0x02184c: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x021850: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x021854: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x021858: 910443fd  add      x29, sp, #0x110
//   0x02185c: a9051be5  stp      x5, x6, [sp, #0x50]
//   0x021860: b9004fe4  str      w4, [sp, #0x4c]
//   0x021864: d53bd048  mrs      x8, tpidr_el0
//   0x021868: f9001fe8  str      x8, [sp, #0x38]
//   0x02186c: f9401508  ldr      x8, [x8, #0x28]
//   0x021870: aa0003fb  mov      x27, x0
//   0x021874: d0000220  adrp     x0, #0x67000
//   0x021878: b9402bb4  ldr      w20, [x29, #0x28]
uint64_t fde_0056_sub_02183c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401508ULL) + (x2 ^ 0x02183CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02183c: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C6FFCULL; // 0x021840: stp x28, x27, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D67FAULL; // 0x021844: stp x26, x25, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E5FF8ULL; // 0x021848: stp x24, x23, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F57F6ULL; // 0x02184c: stp x22, x21, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FF4ULL; // 0x021850: stp x20, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x021854: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x021858: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA9051BE5ULL; // 0x02185c: stp x5, x6, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9004FE4ULL; // 0x021860: str w4, [sp, #0x4c]
    return acc;
}

// [EN] Reconstructed FDE #0057 @ 0x021a24..0x021dd4 (944 bytes)
// [VN] Phục dựng FDE #0057 tại 0x021a24..0x021dd4 (944 byte)
//   0x021a24: d10383ff  sub      sp, sp, #0xe0
//   0x021a28: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x021a2c: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x021a30: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x021a34: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x021a38: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x021a3c: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x021a40: 910343fd  add      x29, sp, #0xd0
//   0x021a44: d53bd054  mrs      x20, tpidr_el0
//   0x021a48: f9401688  ldr      x8, [x20, #0x28]
//   0x021a4c: aa0003f3  mov      x19, x0
//   0x021a50: f9401fbc  ldr      x28, [x29, #0x38]
//   0x021a54: aa0703f8  mov      x24, x7
//   0x021a58: f81a83a8  stur     x8, [x29, #-0x58]
//   0x021a5c: f9400000  ldr      x0, [x0]
//   0x021a60: aa0603f9  mov      x25, x6
uint64_t fde_0057_sub_021a24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0xAA0703F8ULL) + (x2 ^ 0x021A24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x021a24: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9086FFCULL; // 0x021a28: stp x28, x27, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90967FAULL; // 0x021a2c: stp x26, x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x021a30: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x021a34: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x021a38: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x021a3c: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x021a40: add x29, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x021a44: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x021a48: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0058 @ 0x021dd4..0x021e9c (200 bytes)
// [VN] Phục dựng FDE #0058 tại 0x021dd4..0x021e9c (200 byte)
//   0x021dd4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x021dd8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x021ddc: 910043fd  add      x29, sp, #0x10
//   0x021de0: f9400401  ldr      x1, [x0, #8]
//   0x021de4: aa0003f3  mov      x19, x0
//   0x021de8: b40000a1  cbz      x1, #0x21dfc
//   0x021dec: f9400260  ldr      x0, [x19]
//   0x021df0: f9400008  ldr      x8, [x0]
//   0x021df4: f9405d08  ldr      x8, [x8, #0xb8]
//   0x021df8: d63f0100  blr      x8
//   0x021dfc: f9400a61  ldr      x1, [x19, #0x10]
//   0x021e00: b40000a1  cbz      x1, #0x21e14
//   0x021e04: f9400260  ldr      x0, [x19]
//   0x021e08: f9400008  ldr      x8, [x0]
//   0x021e0c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x021e10: d63f0100  blr      x8
uint64_t fde_0058_sub_021dd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400260ULL) + (x2 ^ 0x021DD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x021dd4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x021dd8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x021ddc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x021de0: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021de4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A1ULL; // 0x021de8: cbz x1, #0x21dfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x021dec: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x021df0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405D08ULL; // 0x021df4: ldr x8, [x8, #0xb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x021df8: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0059 @ 0x021e9c..0x02206c (464 bytes)
// [VN] Phục dựng FDE #0059 tại 0x021e9c..0x02206c (464 byte)
//   0x021e9c: d10343ff  sub      sp, sp, #0xd0
//   0x021ea0: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x021ea4: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x021ea8: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x021eac: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x021eb0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x021eb4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x021eb8: 910303fd  add      x29, sp, #0xc0
//   0x021ebc: d53bd05b  mrs      x27, tpidr_el0
//   0x021ec0: f9401768  ldr      x8, [x27, #0x28]
//   0x021ec4: aa0003fa  mov      x26, x0
//   0x021ec8: d0000220  adrp     x0, #0x67000
//   0x021ecc: 2a0603f4  mov      w20, w6
//   0x021ed0: f81a83a8  stur     x8, [x29, #-0x58]
//   0x021ed4: f946b000  ldr      x0, [x0, #0xd60]
//   0x021ed8: aa0503f5  mov      x21, x5
uint64_t fde_0059_sub_021e9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x2A0603F4ULL) + (x2 ^ 0x021E9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x021e9c: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x021ea0: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x021ea4: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x021ea8: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x021eac: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x021eb0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x021eb4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x021eb8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x021ebc: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x021ec0: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0060 @ 0x02206c..0x02265c (1520 bytes)
// [VN] Phục dựng FDE #0060 tại 0x02206c..0x02265c (1520 byte)
//   0x02206c: d10403ff  sub      sp, sp, #0x100
//   0x022070: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x022074: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x022078: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x02207c: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x022080: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x022084: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x022088: 9103c3fd  add      x29, sp, #0xf0
//   0x02208c: a90413e6  stp      x6, x4, [sp, #0x40]
//   0x022090: 290717e3  stp      w3, w5, [sp, #0x38]
//   0x022094: d53bd048  mrs      x8, tpidr_el0
//   0x022098: f9002be8  str      x8, [sp, #0x50]
//   0x02209c: f9401508  ldr      x8, [x8, #0x28]
//   0x0220a0: aa0003f3  mov      x19, x0
//   0x0220a4: f9400ba9  ldr      x9, [x29, #0x10]
//   0x0220a8: 2a0703f6  mov      w22, w7
uint64_t fde_0060_sub_02206c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xF9401508ULL) + (x2 ^ 0x02206CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x02206c: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x022070: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x022074: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x022078: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x02207c: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x022080: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x022084: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x022088: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90413E6ULL; // 0x02208c: stp x6, x4, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x290717E3ULL; // 0x022090: stp w3, w5, [sp, #0x38]
    return acc;
}

// [EN] Reconstructed FDE #0061 @ 0x02265c..0x0227dc (384 bytes)
// [VN] Phục dựng FDE #0061 tại 0x02265c..0x0227dc (384 byte)
//   0x02265c: d10143ff  sub      sp, sp, #0x50
//   0x022660: f90013f5  str      x21, [sp, #0x20]
//   0x022664: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x022668: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02266c: 910103fd  add      x29, sp, #0x40
//   0x022670: d53bd054  mrs      x20, tpidr_el0
//   0x022674: f9401688  ldr      x8, [x20, #0x28]
//   0x022678: aa0003f3  mov      x19, x0
//   0x02267c: f9000fe8  str      x8, [sp, #0x18]
//   0x022680: b0000228  adrp     x8, #0x67000
//   0x022684: f946b108  ldr      x8, [x8, #0xd60]
//   0x022688: 91002101  add      x1, x8, #8
//   0x02268c: 97ffe41d  bl       #0x1b700
//   0x022690: f9401688  ldr      x8, [x20, #0x28]
//   0x022694: f9400fe9  ldr      x9, [sp, #0x18]
//   0x022698: eb09011f  cmp      x8, x9
uint64_t fde_0061_sub_02265c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x97FFE41DULL) + (x2 ^ 0x02265CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x02265c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x022660: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x022664: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x022668: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02266c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x022670: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x022674: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x022678: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x02267c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x022680: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0062 @ 0x0227dc..0x022aa4 (712 bytes)
// [VN] Phục dựng FDE #0062 tại 0x0227dc..0x022aa4 (712 byte)
//   0x0227dc: d10243ff  sub      sp, sp, #0x90
//   0x0227e0: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x0227e4: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x0227e8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0227ec: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0227f0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0227f4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0227f8: 910203fd  add      x29, sp, #0x80
//   0x0227fc: f9400008  ldr      x8, [x0]
//   0x022800: aa0103f4  mov      x20, x1
//   0x022804: 90000181  adrp     x1, #0x52000
//   0x022808: 911e9c21  add      x1, x1, #0x7a7
//   0x02280c: f9401908  ldr      x8, [x8, #0x30]
//   0x022810: aa0003f3  mov      x19, x0
//   0x022814: d63f0100  blr      x8
//   0x022818: f9400268  ldr      x8, [x19]
uint64_t fde_0062_sub_0227dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9401908ULL) + (x2 ^ 0x0227DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x0227dc: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x0227e0: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x0227e4: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x0227e8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x0227ec: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0227f0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0227f4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0227f8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0227fc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x022800: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0063 @ 0x022aa4..0x022b04 (96 bytes)
// [VN] Phục dựng FDE #0063 tại 0x022aa4..0x022b04 (96 byte)
//   0x022aa4: b40002e1  cbz      x1, #0x22b00
//   0x022aa8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x022aac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022ab0: 910043fd  add      x29, sp, #0x10
//   0x022ab4: aa0103f3  mov      x19, x1
//   0x022ab8: f9400021  ldr      x1, [x1]
//   0x022abc: aa0003f4  mov      x20, x0
//   0x022ac0: 97ffe31c  bl       #0x1b730
//   0x022ac4: f9400661  ldr      x1, [x19, #8]
//   0x022ac8: aa1403e0  mov      x0, x20
//   0x022acc: 97ffe319  bl       #0x1b730
//   0x022ad0: f9401e60  ldr      x0, [x19, #0x38]
//   0x022ad4: b4000060  cbz      x0, #0x22ae0
//   0x022ad8: f9002260  str      x0, [x19, #0x40]
//   0x022adc: 97ffdfe9  bl       #0x1aa80
//   0x022ae0: 39408268  ldrb     w8, [x19, #0x20]
uint64_t fde_0063_sub_022aa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002E1ULL) + (x1 ^ 0xB4000060ULL) + (x2 ^ 0x022AA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002E1ULL; // 0x022aa4: cbz x1, #0x22b00
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x022aa8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x022aac: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022ab0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x022ab4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x022ab8: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x022abc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE31CULL; // 0x022ac0: bl #0x1b730
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x022ac4: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x022ac8: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0064 @ 0x022b04..0x022e30 (812 bytes)
// [VN] Phục dựng FDE #0064 tại 0x022b04..0x022e30 (812 byte)
//   0x022b04: d10203ff  sub      sp, sp, #0x80
//   0x022b08: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x022b0c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x022b10: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x022b14: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x022b18: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x022b1c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x022b20: 9101c3fd  add      x29, sp, #0x70
//   0x022b24: b4001761  cbz      x1, #0x22e10
//   0x022b28: f9400008  ldr      x8, [x0]
//   0x022b2c: aa0103f5  mov      x21, x1
//   0x022b30: 90000181  adrp     x1, #0x52000
//   0x022b34: 911a1c21  add      x1, x1, #0x687
//   0x022b38: f9401908  ldr      x8, [x8, #0x30]
//   0x022b3c: aa0203f3  mov      x19, x2
//   0x022b40: aa0003f4  mov      x20, x0
uint64_t fde_0064_sub_022b04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x911A1C21ULL) + (x2 ^ 0x022B04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x022b04: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x022b08: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x022b0c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x022b10: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x022b14: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x022b18: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x022b1c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x022b20: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB4001761ULL; // 0x022b24: cbz x1, #0x22e10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x022b28: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0065 @ 0x022e30..0x022ecc (156 bytes)
// [VN] Phục dựng FDE #0065 tại 0x022e30..0x022ecc (156 byte)
//   0x022e30: d10483ff  sub      sp, sp, #0x120
//   0x022e34: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x022e38: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x022e3c: 910443fd  add      x29, sp, #0x110
//   0x022e40: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x022e44: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x022e48: f90057e7  str      x7, [sp, #0xa8]
//   0x022e4c: ad0007e0  stp      q0, q1, [sp]
//   0x022e50: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x022e54: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x022e58: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x022e5c: d53bd053  mrs      x19, tpidr_el0
//   0x022e60: f940166b  ldr      x11, [x19, #0x28]
//   0x022e64: 928004e8  mov      x8, #-0x28
//   0x022e68: 910003e9  mov      x9, sp
//   0x022e6c: 910223ea  add      x10, sp, #0x88
uint64_t fde_0065_sub_022e30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x022E30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x022e30: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x022e34: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x022e38: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x022e3c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x022e40: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x022e44: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x022e48: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x022e4c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x022e50: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x022e54: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0066 @ 0x022ecc..0x022f68 (156 bytes)
// [VN] Phục dựng FDE #0066 tại 0x022ecc..0x022f68 (156 byte)
//   0x022ecc: d10483ff  sub      sp, sp, #0x120
//   0x022ed0: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x022ed4: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x022ed8: 910443fd  add      x29, sp, #0x110
//   0x022edc: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x022ee0: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x022ee4: f90057e7  str      x7, [sp, #0xa8]
//   0x022ee8: ad0007e0  stp      q0, q1, [sp]
//   0x022eec: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x022ef0: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x022ef4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x022ef8: d53bd053  mrs      x19, tpidr_el0
//   0x022efc: f940166b  ldr      x11, [x19, #0x28]
//   0x022f00: 928004e8  mov      x8, #-0x28
//   0x022f04: 910003e9  mov      x9, sp
//   0x022f08: 910223ea  add      x10, sp, #0x88
uint64_t fde_0066_sub_022ecc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x022ECCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x022ecc: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x022ed0: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x022ed4: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x022ed8: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x022edc: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x022ee0: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x022ee4: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x022ee8: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x022eec: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x022ef0: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0067 @ 0x022f68..0x023108 (416 bytes)
// [VN] Phục dựng FDE #0067 tại 0x022f68..0x023108 (416 byte)
//   0x022f68: eb00003f  cmp      x1, x0
//   0x022f6c: 1a9f17e8  cset     w8, eq
//   0x022f70: 39006028  strb     w8, [x1, #0x18]
//   0x022f74: 54000580  b.eq     #0x23024
//   0x022f78: 5280002a  mov      w10, #1
//   0x022f7c: 14000008  b        #0x22f9c
//   0x022f80: eb00011f  cmp      x8, x0
//   0x022f84: 3900612a  strb     w10, [x9, #0x18]
//   0x022f88: 1a9f17e9  cset     w9, eq
//   0x022f8c: aa0803e1  mov      x1, x8
//   0x022f90: 39006109  strb     w9, [x8, #0x18]
//   0x022f94: 3900016a  strb     w10, [x11]
//   0x022f98: 54000460  b.eq     #0x23024
//   0x022f9c: f9400829  ldr      x9, [x1, #0x10]
//   0x022fa0: 39406128  ldrb     w8, [x9, #0x18]
//   0x022fa4: 35000408  cbnz     w8, #0x23024
uint64_t fde_0067_sub_022f68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xEB00003FULL) + (x1 ^ 0x54000460ULL) + (x2 ^ 0x022F68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00003FULL; // 0x022f68: cmp x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E8ULL; // 0x022f6c: cset w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x39006028ULL; // 0x022f70: strb w8, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x54000580ULL; // 0x022f74: b.eq #0x23024
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x022f78: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000008ULL; // 0x022f7c: b #0x22f9c
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x022f80: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x3900612AULL; // 0x022f84: strb w10, [x9, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E9ULL; // 0x022f88: cset w9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x022f8c: mov x1, x8
    return acc;
}

// [EN] Reconstructed FDE #0068 @ 0x023108..0x0231d0 (200 bytes)
// [VN] Phục dựng FDE #0068 tại 0x023108..0x0231d0 (200 byte)
//   0x023108: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02310c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x023110: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x023114: 910083fd  add      x29, sp, #0x20
//   0x023118: 39400008  ldrb     w8, [x0]
//   0x02311c: aa0203f4  mov      x20, x2
//   0x023120: aa0003f3  mov      x19, x0
//   0x023124: aa0103e7  mov      x7, x1
//   0x023128: 37000108  tbnz     w8, #0, #0x23148
//   0x02312c: 528002c1  mov      w1, #0x16
//   0x023130: eb14003f  cmp      x1, x20
//   0x023134: 54000143  b.lo     #0x2315c
//   0x023138: 37000188  tbnz     w8, #0, #0x23168
//   0x02313c: 91000675  add      x21, x19, #1
//   0x023140: b5000194  cbnz     x20, #0x23170
//   0x023144: 1400000f  b        #0x23180
uint64_t fde_0068_sub_023108(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x37000188ULL) + (x2 ^ 0x023108ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x023108: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02310c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x023110: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x023114: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x023118: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02311c: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023120: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x023124: mov x7, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000108ULL; // 0x023128: tbnz w8, #0, #0x23148
    acc = (acc * 0x100000001B3ULL) ^ 0x528002C1ULL; // 0x02312c: mov w1, #0x16
    return acc;
}

// [EN] Reconstructed FDE #0069 @ 0x0231d0..0x023308 (312 bytes)
// [VN] Phục dựng FDE #0069 tại 0x0231d0..0x023308 (312 byte)
//   0x0231d0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0231d4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0231d8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0231dc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0231e0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0231e4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0231e8: 910143fd  add      x29, sp, #0x50
//   0x0231ec: 92800228  mov      x8, #-0x12
//   0x0231f0: cb010108  sub      x8, x8, x1
//   0x0231f4: eb02011f  cmp      x8, x2
//   0x0231f8: aa0003f4  mov      x20, x0
//   0x0231fc: 54000823  b.lo     #0x23300
//   0x023200: 39400288  ldrb     w8, [x20]
//   0x023204: aa0703fa  mov      x26, x7
//   0x023208: aa0603f3  mov      x19, x6
//   0x02320c: aa0503f6  mov      x22, x5
uint64_t fde_0069_sub_0231d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x39400288ULL) + (x2 ^ 0x0231D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0231d0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0231d4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0231d8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0231dc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0231e0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0231e4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0231e8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x92800228ULL; // 0x0231ec: mov x8, #-0x12
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010108ULL; // 0x0231f0: sub x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x0231f4: cmp x8, x2
    return acc;
}

// [EN] Reconstructed FDE #0070 @ 0x023308..0x023428 (288 bytes)
// [VN] Phục dựng FDE #0070 tại 0x023308..0x023428 (288 byte)
//   0x023308: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02330c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x023310: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x023314: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x023318: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02331c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x023320: 910143fd  add      x29, sp, #0x50
//   0x023324: aa0003f4  mov      x20, x0
//   0x023328: f8408e97  ldr      x23, [x20, #8]!
//   0x02332c: aa0103f3  mov      x19, x1
//   0x023330: b4000657  cbz      x23, #0x233f8
//   0x023334: 39400048  ldrb     w8, [x2]
//   0x023338: a940a849  ldp      x9, x10, [x2, #8]
//   0x02333c: 91002014  add      x20, x0, #8
//   0x023340: d341fd0b  lsr      x11, x8, #1
//   0x023344: 7200011f  tst      w8, #1
uint64_t fde_0070_sub_023308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x023308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x023308: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02330c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x023310: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x023314: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x023318: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02331c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x023320: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x023324: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x023328: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02332c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0071 @ 0x023428..0x0234d4 (172 bytes)
// [VN] Phục dựng FDE #0071 tại 0x023428..0x0234d4 (172 byte)
//   0x023428: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02342c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x023430: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x023434: 910083fd  add      x29, sp, #0x20
//   0x023438: a9007c1f  stp      xzr, xzr, [x0]
//   0x02343c: f900081f  str      xzr, [x0, #0x10]
//   0x023440: 39400028  ldrb     w8, [x1]
//   0x023444: aa0003f3  mov      x19, x0
//   0x023448: 370000c8  tbnz     w8, #0, #0x23460
//   0x02344c: f9400828  ldr      x8, [x1, #0x10]
//   0x023450: 3dc00020  ldr      q0, [x1]
//   0x023454: f9000a68  str      x8, [x19, #0x10]
//   0x023458: 3d800260  str      q0, [x19]
//   0x02345c: 14000018  b        #0x234bc
//   0x023460: f9400434  ldr      x20, [x1, #8]
//   0x023464: b100429f  cmn      x20, #0x10
uint64_t fde_0071_sub_023428(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x3D800260ULL) + (x2 ^ 0x023428ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x023428: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02342c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x023430: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x023434: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x023438: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x02343c: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x023440: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023444: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x370000C8ULL; // 0x023448: tbnz w8, #0, #0x23460
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400828ULL; // 0x02344c: ldr x8, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0072 @ 0x0234d4..0x023514 (64 bytes)
// [VN] Phục dựng FDE #0072 tại 0x0234d4..0x023514 (64 byte)
//   0x0234d4: b40001e1  cbz      x1, #0x23510
//   0x0234d8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0234dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0234e0: 910043fd  add      x29, sp, #0x10
//   0x0234e4: aa0103f3  mov      x19, x1
//   0x0234e8: f9400021  ldr      x1, [x1]
//   0x0234ec: aa0003f4  mov      x20, x0
//   0x0234f0: 97ffe294  bl       #0x1bf40
//   0x0234f4: f9400661  ldr      x1, [x19, #8]
//   0x0234f8: aa1403e0  mov      x0, x20
//   0x0234fc: 97ffe291  bl       #0x1bf40
//   0x023500: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x023504: aa1303e0  mov      x0, x19
//   0x023508: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02350c: 17ffdd5d  b        #0x1aa80
//   0x023510: d65f03c0  ret      
uint64_t fde_0072_sub_0234d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0234D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x0234d4: cbz x1, #0x23510
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0234d8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0234dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0234e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0234e4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x0234e8: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0234ec: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE294ULL; // 0x0234f0: bl #0x1bf40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x0234f4: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x0234f8: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0073 @ 0x023514..0x0238e4 (976 bytes)
// [VN] Phục dựng FDE #0073 tại 0x023514..0x0238e4 (976 byte)
//   0x023514: d101c3ff  sub      sp, sp, #0x70
//   0x023518: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02351c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x023520: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x023524: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x023528: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02352c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x023530: 910183fd  add      x29, sp, #0x60
//   0x023534: f9400808  ldr      x8, [x0, #0x10]
//   0x023538: aa0203f4  mov      x20, x2
//   0x02353c: aa0003f3  mov      x19, x0
//   0x023540: aa0103f5  mov      x21, x1
//   0x023544: b4001748  cbz      x8, #0x2382c
//   0x023548: aa1303fa  mov      x26, x19
//   0x02354c: f9400268  ldr      x8, [x19]
//   0x023550: f8408f49  ldr      x9, [x26, #8]!
uint64_t fde_0073_sub_023514(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB4001748ULL) + (x2 ^ 0x023514ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x023514: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x023518: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02351c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x023520: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x023524: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x023528: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02352c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x023530: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x023534: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x023538: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0074 @ 0x0238e4..0x023cc8 (996 bytes)
// [VN] Phục dựng FDE #0074 tại 0x0238e4..0x023cc8 (996 byte)
//   0x0238e4: d101c3ff  sub      sp, sp, #0x70
//   0x0238e8: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x0238ec: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0238f0: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0238f4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0238f8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0238fc: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x023900: 910183fd  add      x29, sp, #0x60
//   0x023904: f9400808  ldr      x8, [x0, #0x10]
//   0x023908: aa0203f4  mov      x20, x2
//   0x02390c: aa0003f3  mov      x19, x0
//   0x023910: aa0103f5  mov      x21, x1
//   0x023914: b40017e8  cbz      x8, #0x23c10
//   0x023918: aa1303fa  mov      x26, x19
//   0x02391c: f9400268  ldr      x8, [x19]
//   0x023920: f8408f49  ldr      x9, [x26, #8]!
uint64_t fde_0074_sub_0238e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB40017E8ULL) + (x2 ^ 0x0238E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0238e4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x0238e8: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0238ec: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0238f0: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0238f4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0238f8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0238fc: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x023900: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x023904: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x023908: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0075 @ 0x023cc8..0x023d28 (96 bytes)
// [VN] Phục dựng FDE #0075 tại 0x023cc8..0x023d28 (96 byte)
//   0x023cc8: b40002e1  cbz      x1, #0x23d24
//   0x023ccc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023cd0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023cd4: 910043fd  add      x29, sp, #0x10
//   0x023cd8: aa0103f3  mov      x19, x1
//   0x023cdc: f9400021  ldr      x1, [x1]
//   0x023ce0: aa0003f4  mov      x20, x0
//   0x023ce4: 97ffddc3  bl       #0x1b3f0
//   0x023ce8: f9400661  ldr      x1, [x19, #8]
//   0x023cec: aa1403e0  mov      x0, x20
//   0x023cf0: 97ffddc0  bl       #0x1b3f0
//   0x023cf4: 3940e268  ldrb     w8, [x19, #0x38]
//   0x023cf8: 36000068  tbz      w8, #0, #0x23d04
//   0x023cfc: f9402660  ldr      x0, [x19, #0x48]
//   0x023d00: 97ffdb60  bl       #0x1aa80
//   0x023d04: 39408268  ldrb     w8, [x19, #0x20]
uint64_t fde_0075_sub_023cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002E1ULL) + (x1 ^ 0x36000068ULL) + (x2 ^ 0x023CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002E1ULL; // 0x023cc8: cbz x1, #0x23d24
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x023ccc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023cd0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023cd4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x023cd8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x023cdc: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x023ce0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDDC3ULL; // 0x023ce4: bl #0x1b3f0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x023ce8: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x023cec: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0076 @ 0x023d28..0x023e90 (360 bytes)
// [VN] Phục dựng FDE #0076 tại 0x023d28..0x023e90 (360 byte)
//   0x023d28: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x023d2c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x023d30: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x023d34: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x023d38: 9100c3fd  add      x29, sp, #0x30
//   0x023d3c: aa0003f4  mov      x20, x0
//   0x023d40: 52800a00  mov      w0, #0x50
//   0x023d44: aa0103f6  mov      x22, x1
//   0x023d48: 97ffdfc6  bl       #0x1bc60
//   0x023d4c: aa0003f3  mov      x19, x0
//   0x023d50: 91008015  add      x21, x0, #0x20
//   0x023d54: aa1503e0  mov      x0, x21
//   0x023d58: aa1603e1  mov      x1, x22
//   0x023d5c: 97ffdb9d  bl       #0x1abd0
//   0x023d60: 9100e260  add      x0, x19, #0x38
//   0x023d64: 910062c1  add      x1, x22, #0x18
uint64_t fde_0076_sub_023d28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA1603E1ULL) + (x2 ^ 0x023D28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x023d28: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x023d2c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x023d30: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x023d34: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x023d38: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x023d3c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800A00ULL; // 0x023d40: mov w0, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x023d44: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDFC6ULL; // 0x023d48: bl #0x1bc60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023d4c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0077 @ 0x023e90..0x023eec (92 bytes)
// [VN] Phục dựng FDE #0077 tại 0x023e90..0x023eec (92 byte)
//   0x023e90: b40002c1  cbz      x1, #0x23ee8
//   0x023e94: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023e98: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023e9c: 910043fd  add      x29, sp, #0x10
//   0x023ea0: aa0103f3  mov      x19, x1
//   0x023ea4: f9400021  ldr      x1, [x1]
//   0x023ea8: aa0003f4  mov      x20, x0
//   0x023eac: 97ffda91  bl       #0x1a8f0
//   0x023eb0: f9400661  ldr      x1, [x19, #8]
//   0x023eb4: aa1403e0  mov      x0, x20
//   0x023eb8: 97ffda8e  bl       #0x1a8f0
//   0x023ebc: f9402261  ldr      x1, [x19, #0x40]
//   0x023ec0: 9100e260  add      x0, x19, #0x38
//   0x023ec4: 97ffdd4b  bl       #0x1b3f0
//   0x023ec8: 39408268  ldrb     w8, [x19, #0x20]
//   0x023ecc: 36000068  tbz      w8, #0, #0x23ed8
uint64_t fde_0077_sub_023e90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002C1ULL) + (x1 ^ 0x9100E260ULL) + (x2 ^ 0x023E90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002C1ULL; // 0x023e90: cbz x1, #0x23ee8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x023e94: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023e98: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023e9c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x023ea0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x023ea4: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x023ea8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDA91ULL; // 0x023eac: bl #0x1a8f0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x023eb0: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x023eb4: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0078 @ 0x023eec..0x024034 (328 bytes)
// [VN] Phục dựng FDE #0078 tại 0x023eec..0x024034 (328 byte)
//   0x023eec: d101c3ff  sub      sp, sp, #0x70
//   0x023ef0: f90013f9  str      x25, [sp, #0x20]
//   0x023ef4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x023ef8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x023efc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x023f00: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x023f04: 910183fd  add      x29, sp, #0x60
//   0x023f08: d53bd056  mrs      x22, tpidr_el0
//   0x023f0c: f94016c8  ldr      x8, [x22, #0x28]
//   0x023f10: aa0003f3  mov      x19, x0
//   0x023f14: f9000fe8  str      x8, [sp, #0x18]
//   0x023f18: 910003e8  mov      x8, sp
//   0x023f1c: 97ffdd59  bl       #0x1b480
//   0x023f20: aa1303e8  mov      x8, x19
//   0x023f24: f94003f4  ldr      x20, [sp]
//   0x023f28: f8408d17  ldr      x23, [x8, #8]!
uint64_t fde_0078_sub_023eec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x97FFDD59ULL) + (x2 ^ 0x023EECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x023eec: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x023ef0: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x023ef4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x023ef8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x023efc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x023f00: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x023f04: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x023f08: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x023f0c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023f10: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0079 @ 0x024034..0x024168 (308 bytes)
// [VN] Phục dựng FDE #0079 tại 0x024034..0x024168 (308 byte)
//   0x024034: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x024038: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02403c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x024040: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024044: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x024048: 910103fd  add      x29, sp, #0x40
//   0x02404c: 91002015  add      x21, x0, #8
//   0x024050: 52800a00  mov      w0, #0x50
//   0x024054: aa0103f8  mov      x24, x1
//   0x024058: aa0803f3  mov      x19, x8
//   0x02405c: 97ffdf01  bl       #0x1bc60
//   0x024060: aa0003f4  mov      x20, x0
//   0x024064: a9005660  stp      x0, x21, [x19]
//   0x024068: 91008015  add      x21, x0, #0x20
//   0x02406c: 3900427f  strb     wzr, [x19, #0x10]
//   0x024070: aa1503e0  mov      x0, x21
uint64_t fde_0079_sub_024034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xA9005660ULL) + (x2 ^ 0x024034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x024034: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x024038: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02403c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024040: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024044: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x024048: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x02404c: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800A00ULL; // 0x024050: mov w0, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F8ULL; // 0x024054: mov x24, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x024058: mov x19, x8
    return acc;
}

// [EN] Reconstructed FDE #0080 @ 0x024168..0x02416c (4 bytes)
// [VN] Phục dựng FDE #0080 tại 0x024168..0x02416c (4 byte)
//   0x024168: d65f03c0  ret      
uint64_t fde_0080_sub_024168(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024168ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024168: ret 
    return acc;
}

// [EN] Reconstructed FDE #0081 @ 0x02416c..0x024170 (4 bytes)
// [VN] Phục dựng FDE #0081 tại 0x02416c..0x024170 (4 byte)
//   0x02416c: d65f03c0  ret      
uint64_t fde_0081_sub_02416c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02416CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02416c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0082 @ 0x024170..0x024174 (4 bytes)
// [VN] Phục dựng FDE #0082 tại 0x024170..0x024174 (4 byte)
//   0x024170: d65f03c0  ret      
uint64_t fde_0082_sub_024170(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024170ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024170: ret 
    return acc;
}

// [EN] Reconstructed FDE #0083 @ 0x024174..0x024178 (4 bytes)
// [VN] Phục dựng FDE #0083 tại 0x024174..0x024178 (4 byte)
//   0x024174: d65f03c0  ret      
uint64_t fde_0083_sub_024174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024174: ret 
    return acc;
}

// [EN] Reconstructed FDE #0084 @ 0x024178..0x02417c (4 bytes)
// [VN] Phục dựng FDE #0084 tại 0x024178..0x02417c (4 byte)
//   0x024178: d65f03c0  ret      
uint64_t fde_0084_sub_024178(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024178ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024178: ret 
    return acc;
}

// [EN] Reconstructed FDE #0085 @ 0x02417c..0x024180 (4 bytes)
// [VN] Phục dựng FDE #0085 tại 0x02417c..0x024180 (4 byte)
//   0x02417c: d65f03c0  ret      
uint64_t fde_0085_sub_02417c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02417CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02417c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0086 @ 0x024180..0x024184 (4 bytes)
// [VN] Phục dựng FDE #0086 tại 0x024180..0x024184 (4 byte)
//   0x024180: d65f03c0  ret      
uint64_t fde_0086_sub_024180(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024180ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024180: ret 
    return acc;
}

// [EN] Reconstructed FDE #0087 @ 0x024184..0x024188 (4 bytes)
// [VN] Phục dựng FDE #0087 tại 0x024184..0x024188 (4 byte)
//   0x024184: d65f03c0  ret      
uint64_t fde_0087_sub_024184(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024184ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024184: ret 
    return acc;
}

// [EN] Reconstructed FDE #0088 @ 0x024188..0x02418c (4 bytes)
// [VN] Phục dựng FDE #0088 tại 0x024188..0x02418c (4 byte)
//   0x024188: d65f03c0  ret      
uint64_t fde_0088_sub_024188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024188: ret 
    return acc;
}

// [EN] Reconstructed FDE #0089 @ 0x02418c..0x024230 (164 bytes)
// [VN] Phục dựng FDE #0089 tại 0x02418c..0x024230 (164 byte)
//   0x02418c: d10143ff  sub      sp, sp, #0x50
//   0x024190: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x024194: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024198: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02419c: 910103fd  add      x29, sp, #0x40
//   0x0241a0: d53bd054  mrs      x20, tpidr_el0
//   0x0241a4: f9401688  ldr      x8, [x20, #0x28]
//   0x0241a8: 910003e9  mov      x9, sp
//   0x0241ac: 91002135  add      x21, x9, #8
//   0x0241b0: aa0203f6  mov      x22, x2
//   0x0241b4: f9000fe8  str      x8, [sp, #0x18]
//   0x0241b8: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x0241bc: f90003f5  str      x21, [sp]
//   0x0241c0: f8408ec1  ldr      x1, [x22, #8]!
//   0x0241c4: aa0203e0  mov      x0, x2
//   0x0241c8: aa0203f3  mov      x19, x2
uint64_t fde_0089_sub_02418c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90003F5ULL) + (x2 ^ 0x02418CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x02418c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x024190: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024194: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024198: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02419c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0241a0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0241a4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E9ULL; // 0x0241a8: mov x9, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x91002135ULL; // 0x0241ac: add x21, x9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x0241b0: mov x22, x2
    return acc;
}

// [EN] Reconstructed FDE #0090 @ 0x024230..0x024234 (4 bytes)
// [VN] Phục dựng FDE #0090 tại 0x024230..0x024234 (4 byte)
//   0x024230: d65f03c0  ret      
uint64_t fde_0090_sub_024230(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024230ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024230: ret 
    return acc;
}

// [EN] Reconstructed FDE #0091 @ 0x024234..0x024244 (16 bytes)
// [VN] Phục dựng FDE #0091 tại 0x024234..0x024244 (16 byte)
//   0x024234: f0000161  adrp     x1, #0x53000
//   0x024238: 912c1821  add      x1, x1, #0xb06
//   0x02423c: aa0803e0  mov      x0, x8
//   0x024240: 17ffde54  b        #0x1bb90
uint64_t fde_0091_sub_024234(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000161ULL) + (x1 ^ 0x17FFDE54ULL) + (x2 ^ 0x024234ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000161ULL; // 0x024234: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C1821ULL; // 0x024238: add x1, x1, #0xb06
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x02423c: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDE54ULL; // 0x024240: b #0x1bb90
    return acc;
}

// [EN] Reconstructed FDE #0092 @ 0x024244..0x024268 (36 bytes)
// [VN] Phục dựng FDE #0092 tại 0x024244..0x024268 (36 byte)
//   0x024244: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x024248: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02424c: 910043fd  add      x29, sp, #0x10
//   0x024250: aa0003f3  mov      x19, x0
//   0x024254: 97ffda1b  bl       #0x1aac0
//   0x024258: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02425c: aa1303e0  mov      x0, x19
//   0x024260: f84207f3  ldr      x19, [sp], #0x20
//   0x024264: 17ffda07  b        #0x1aa80
uint64_t fde_0092_sub_024244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFDA07ULL) + (x2 ^ 0x024244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x024244: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024248: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02424c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024250: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDA1BULL; // 0x024254: bl #0x1aac0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x024258: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02425c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x024260: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDA07ULL; // 0x024264: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0093 @ 0x024268..0x0242b8 (80 bytes)
// [VN] Phục dựng FDE #0093 tại 0x024268..0x0242b8 (80 byte)
//   0x024268: b4000261  cbz      x1, #0x242b4
//   0x02426c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024270: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024274: 910043fd  add      x29, sp, #0x10
//   0x024278: aa0103f3  mov      x19, x1
//   0x02427c: f9400021  ldr      x1, [x1]
//   0x024280: aa0003f4  mov      x20, x0
//   0x024284: 97ffdb37  bl       #0x1af60
//   0x024288: f9400661  ldr      x1, [x19, #8]
//   0x02428c: aa1403e0  mov      x0, x20
//   0x024290: 97ffdb34  bl       #0x1af60
//   0x024294: 39408268  ldrb     w8, [x19, #0x20]
//   0x024298: 36000068  tbz      w8, #0, #0x242a4
//   0x02429c: f9401a60  ldr      x0, [x19, #0x30]
//   0x0242a0: 97ffd9f8  bl       #0x1aa80
//   0x0242a4: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0093_sub_024268(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000261ULL) + (x1 ^ 0x36000068ULL) + (x2 ^ 0x024268ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000261ULL; // 0x024268: cbz x1, #0x242b4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02426c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024270: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024274: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024278: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x02427c: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x024280: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDB37ULL; // 0x024284: bl #0x1af60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x024288: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02428c: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0094 @ 0x0242b8..0x0244d8 (544 bytes)
// [VN] Phục dựng FDE #0094 tại 0x0242b8..0x0244d8 (544 byte)
//   0x0242b8: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x0242bc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0242c0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0242c4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0242c8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0242cc: 910103fd  add      x29, sp, #0x40
//   0x0242d0: f9400008  ldr      x8, [x0]
//   0x0242d4: aa0103f5  mov      x21, x1
//   0x0242d8: d0000161  adrp     x1, #0x52000
//   0x0242dc: 911e9c21  add      x1, x1, #0x7a7
//   0x0242e0: f9401908  ldr      x8, [x8, #0x30]
//   0x0242e4: aa0003f3  mov      x19, x0
//   0x0242e8: d63f0100  blr      x8
//   0x0242ec: b4000d60  cbz      x0, #0x24498
//   0x0242f0: f9400268  ldr      x8, [x19]
//   0x0242f4: aa0003f4  mov      x20, x0
uint64_t fde_0094_sub_0242b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x0242B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x0242b8: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0242bc: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0242c0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0242c4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0242c8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0242cc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0242d0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0242d4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000161ULL; // 0x0242d8: adrp x1, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x911E9C21ULL; // 0x0242dc: add x1, x1, #0x7a7
    return acc;
}

// [EN] Reconstructed FDE #0095 @ 0x0244d8..0x024574 (156 bytes)
// [VN] Phục dựng FDE #0095 tại 0x0244d8..0x024574 (156 byte)
//   0x0244d8: d10483ff  sub      sp, sp, #0x120
//   0x0244dc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0244e0: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0244e4: 910443fd  add      x29, sp, #0x110
//   0x0244e8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0244ec: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0244f0: f90057e7  str      x7, [sp, #0xa8]
//   0x0244f4: ad0007e0  stp      q0, q1, [sp]
//   0x0244f8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0244fc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x024500: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x024504: d53bd053  mrs      x19, tpidr_el0
//   0x024508: f940166b  ldr      x11, [x19, #0x28]
//   0x02450c: 928004e8  mov      x8, #-0x28
//   0x024510: 910003e9  mov      x9, sp
//   0x024514: 910223ea  add      x10, sp, #0x88
uint64_t fde_0095_sub_0244d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0244D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0244d8: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0244dc: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0244e0: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0244e4: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0244e8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0244ec: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0244f0: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0244f4: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0244f8: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0244fc: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0096 @ 0x024574..0x024610 (156 bytes)
// [VN] Phục dựng FDE #0096 tại 0x024574..0x024610 (156 byte)
//   0x024574: d10483ff  sub      sp, sp, #0x120
//   0x024578: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02457c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x024580: 910443fd  add      x29, sp, #0x110
//   0x024584: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x024588: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02458c: f90057e7  str      x7, [sp, #0xa8]
//   0x024590: ad0007e0  stp      q0, q1, [sp]
//   0x024594: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x024598: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02459c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0245a0: d53bd053  mrs      x19, tpidr_el0
//   0x0245a4: f940166b  ldr      x11, [x19, #0x28]
//   0x0245a8: 928004e8  mov      x8, #-0x28
//   0x0245ac: 910003e9  mov      x9, sp
//   0x0245b0: 910223ea  add      x10, sp, #0x88
uint64_t fde_0096_sub_024574(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x024574ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x024574: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x024578: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02457c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x024580: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x024584: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x024588: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02458c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x024590: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x024594: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x024598: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0097 @ 0x024610..0x0246ac (156 bytes)
// [VN] Phục dựng FDE #0097 tại 0x024610..0x0246ac (156 byte)
//   0x024610: d10483ff  sub      sp, sp, #0x120
//   0x024614: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x024618: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02461c: 910443fd  add      x29, sp, #0x110
//   0x024620: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x024624: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x024628: f90057e7  str      x7, [sp, #0xa8]
//   0x02462c: ad0007e0  stp      q0, q1, [sp]
//   0x024630: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x024634: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x024638: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02463c: d53bd053  mrs      x19, tpidr_el0
//   0x024640: f940166b  ldr      x11, [x19, #0x28]
//   0x024644: 928004e8  mov      x8, #-0x28
//   0x024648: 910003e9  mov      x9, sp
//   0x02464c: 910223ea  add      x10, sp, #0x88
uint64_t fde_0097_sub_024610(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x024610ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x024610: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x024614: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x024618: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02461c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x024620: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x024624: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x024628: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02462c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x024630: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x024634: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0098 @ 0x0246ac..0x0246c0 (20 bytes)
// [VN] Phục dựng FDE #0098 tại 0x0246ac..0x0246c0 (20 byte)
//   0x0246ac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0246b0: 910003fd  mov      x29, sp
//   0x0246b4: d0000160  adrp     x0, #0x52000
//   0x0246b8: 91033000  add      x0, x0, #0xcc
//   0x0246bc: 94000001  bl       #0x246c0
uint64_t fde_0098_sub_0246ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000001ULL) + (x2 ^ 0x0246ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0246ac: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0246b0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000160ULL; // 0x0246b4: adrp x0, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x91033000ULL; // 0x0246b8: add x0, x0, #0xcc
    acc = (acc * 0x100000001B3ULL) ^ 0x94000001ULL; // 0x0246bc: bl #0x246c0
    return acc;
}

// [EN] Reconstructed FDE #0099 @ 0x0246c0..0x024710 (80 bytes)
// [VN] Phục dựng FDE #0099 tại 0x0246c0..0x024710 (80 byte)
//   0x0246c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0246c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0246c8: 910043fd  add      x29, sp, #0x10
//   0x0246cc: aa0003f4  mov      x20, x0
//   0x0246d0: 52800200  mov      w0, #0x10
//   0x0246d4: 97ffd967  bl       #0x1ac70
//   0x0246d8: aa0003f3  mov      x19, x0
//   0x0246dc: aa1403e1  mov      x1, x20
//   0x0246e0: 9400000c  bl       #0x24710
//   0x0246e4: f0000201  adrp     x1, #0x67000
//   0x0246e8: f0000202  adrp     x2, #0x67000
//   0x0246ec: f946ac21  ldr      x1, [x1, #0xd58]
//   0x0246f0: f9469842  ldr      x2, [x2, #0xd30]
//   0x0246f4: aa1303e0  mov      x0, x19
//   0x0246f8: 97ffdc92  bl       #0x1b940
//   0x0246fc: aa0003f4  mov      x20, x0
uint64_t fde_0099_sub_0246c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9469842ULL) + (x2 ^ 0x0246C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0246c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0246c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0246c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0246cc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x0246d0: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD967ULL; // 0x0246d4: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0246d8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x0246dc: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x0246e0: bl #0x24710
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000201ULL; // 0x0246e4: adrp x1, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0100 @ 0x024710..0x024740 (48 bytes)
// [VN] Phục dựng FDE #0100 tại 0x024710..0x024740 (48 byte)
//   0x024710: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x024714: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024718: 910043fd  add      x29, sp, #0x10
//   0x02471c: aa0003f3  mov      x19, x0
//   0x024720: 97ffd900  bl       #0x1ab20
//   0x024724: f0000208  adrp     x8, #0x67000
//   0x024728: f9475908  ldr      x8, [x8, #0xeb0]
//   0x02472c: 91004108  add      x8, x8, #0x10
//   0x024730: f9000268  str      x8, [x19]
//   0x024734: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x024738: f84207f3  ldr      x19, [sp], #0x20
//   0x02473c: d65f03c0  ret      
uint64_t fde_0100_sub_024710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x024710: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024714: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024718: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02471c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD900ULL; // 0x024720: bl #0x1ab20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000208ULL; // 0x024724: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475908ULL; // 0x024728: ldr x8, [x8, #0xeb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x02472c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x024730: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x024734: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0101 @ 0x024740..0x024754 (20 bytes)
// [VN] Phục dựng FDE #0101 tại 0x024740..0x024754 (20 byte)
//   0x024740: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x024744: 910003fd  mov      x29, sp
//   0x024748: d0000160  adrp     x0, #0x52000
//   0x02474c: 912a9c00  add      x0, x0, #0xaa7
//   0x024750: 97ffe1d0  bl       #0x1ce90
uint64_t fde_0101_sub_024740(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFE1D0ULL) + (x2 ^ 0x024740ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x024740: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x024744: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000160ULL; // 0x024748: adrp x0, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A9C00ULL; // 0x02474c: add x0, x0, #0xaa7
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE1D0ULL; // 0x024750: bl #0x1ce90
    return acc;
}

// [EN] Reconstructed FDE #0102 @ 0x024754..0x024860 (268 bytes)
// [VN] Phục dựng FDE #0102 tại 0x024754..0x024860 (268 byte)
//   0x024754: d10183ff  sub      sp, sp, #0x60
//   0x024758: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02475c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x024760: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x024764: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x024768: 910143fd  add      x29, sp, #0x50
//   0x02476c: d53bd058  mrs      x24, tpidr_el0
//   0x024770: f9401708  ldr      x8, [x24, #0x28]
//   0x024774: aa0303f6  mov      x22, x3
//   0x024778: aa0203e4  mov      x4, x2
//   0x02477c: 910043e2  add      x2, sp, #0x10
//   0x024780: 910023e3  add      x3, sp, #8
//   0x024784: aa0003f4  mov      x20, x0
//   0x024788: f9000fe8  str      x8, [sp, #0x18]
//   0x02478c: 97ffde75  bl       #0x1c160
//   0x024790: f9400013  ldr      x19, [x0]
uint64_t fde_0102_sub_024754(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x024754ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x024754: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x024758: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02475c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x024760: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x024764: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x024768: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02476c: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x024770: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x024774: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E4ULL; // 0x024778: mov x4, x2
    return acc;
}

// [EN] Reconstructed FDE #0103 @ 0x024860..0x024b3c (732 bytes)
// [VN] Phục dựng FDE #0103 tại 0x024860..0x024b3c (732 byte)
//   0x024860: d10203ff  sub      sp, sp, #0x80
//   0x024864: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x024868: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02486c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x024870: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x024874: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x024878: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02487c: 9101c3fd  add      x29, sp, #0x70
//   0x024880: 91002008  add      x8, x0, #8
//   0x024884: aa0403f5  mov      x21, x4
//   0x024888: aa0103f4  mov      x20, x1
//   0x02488c: eb01011f  cmp      x8, x1
//   0x024890: a90083e3  stp      x3, x0, [sp, #8]
//   0x024894: f90003e8  str      x8, [sp]
//   0x024898: f9000fe2  str      x2, [sp, #0x18]
//   0x02489c: 54000380  b.eq     #0x2490c
uint64_t fde_0103_sub_024860(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xA90083E3ULL) + (x2 ^ 0x024860ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x024860: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x024864: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x024868: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02486c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x024870: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x024874: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x024878: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02487c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x024880: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F5ULL; // 0x024884: mov x21, x4
    return acc;
}

// [EN] Reconstructed FDE #0104 @ 0x024b3c..0x024e18 (732 bytes)
// [VN] Phục dựng FDE #0104 tại 0x024b3c..0x024e18 (732 byte)
//   0x024b3c: d10203ff  sub      sp, sp, #0x80
//   0x024b40: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x024b44: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x024b48: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x024b4c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x024b50: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x024b54: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x024b58: 9101c3fd  add      x29, sp, #0x70
//   0x024b5c: 91002008  add      x8, x0, #8
//   0x024b60: aa0403f5  mov      x21, x4
//   0x024b64: aa0103f4  mov      x20, x1
//   0x024b68: eb01011f  cmp      x8, x1
//   0x024b6c: a90083e3  stp      x3, x0, [sp, #8]
//   0x024b70: f90003e8  str      x8, [sp]
//   0x024b74: f9000fe2  str      x2, [sp, #0x18]
//   0x024b78: 54000380  b.eq     #0x24be8
uint64_t fde_0104_sub_024b3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xA90083E3ULL) + (x2 ^ 0x024B3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x024b3c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x024b40: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x024b44: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x024b48: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x024b4c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x024b50: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x024b54: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x024b58: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x024b5c: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F5ULL; // 0x024b60: mov x21, x4
    return acc;
}

// [EN] Reconstructed FDE #0105 @ 0x024e18..0x024f38 (288 bytes)
// [VN] Phục dựng FDE #0105 tại 0x024e18..0x024f38 (288 byte)
//   0x024e18: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x024e1c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x024e20: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x024e24: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x024e28: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x024e2c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x024e30: 910143fd  add      x29, sp, #0x50
//   0x024e34: aa0003f4  mov      x20, x0
//   0x024e38: f8408e97  ldr      x23, [x20, #8]!
//   0x024e3c: aa0103f3  mov      x19, x1
//   0x024e40: b4000657  cbz      x23, #0x24f08
//   0x024e44: 39400048  ldrb     w8, [x2]
//   0x024e48: a940a849  ldp      x9, x10, [x2, #8]
//   0x024e4c: 91002014  add      x20, x0, #8
//   0x024e50: d341fd0b  lsr      x11, x8, #1
//   0x024e54: 7200011f  tst      w8, #1
uint64_t fde_0105_sub_024e18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x024E18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x024e18: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x024e1c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x024e20: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x024e24: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x024e28: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x024e2c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x024e30: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x024e34: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x024e38: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024e3c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0106 @ 0x024f38..0x02505c (292 bytes)
// [VN] Phục dựng FDE #0106 tại 0x024f38..0x02505c (292 byte)
//   0x024f38: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x024f3c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x024f40: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x024f44: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x024f48: 9100c3fd  add      x29, sp, #0x30
//   0x024f4c: 39400008  ldrb     w8, [x0]
//   0x024f50: aa0303f4  mov      x20, x3
//   0x024f54: aa0203f5  mov      x21, x2
//   0x024f58: aa0003f3  mov      x19, x0
//   0x024f5c: aa0103f7  mov      x23, x1
//   0x024f60: 370000c8  tbnz     w8, #0, #0x24f78
//   0x024f64: d341fd16  lsr      x22, x8, #1
//   0x024f68: eb1702df  cmp      x22, x23
//   0x024f6c: 540000c2  b.hs     #0x24f84
//   0x024f70: aa1303e0  mov      x0, x19
//   0x024f74: 97ffd76b  bl       #0x1ad20
uint64_t fde_0106_sub_024f38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xEB1702DFULL) + (x2 ^ 0x024F38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x024f38: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x024f3c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x024f40: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x024f44: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x024f48: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x024f4c: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x024f50: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x024f54: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024f58: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x024f5c: mov x23, x1
    return acc;
}

// [EN] Reconstructed FDE #0107 @ 0x02505c..0x025274 (536 bytes)
// [VN] Phục dựng FDE #0107 tại 0x02505c..0x025274 (536 byte)
//   0x02505c: d10283ff  sub      sp, sp, #0xa0
//   0x025060: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x025064: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x025068: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02506c: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x025070: 910243fd  add      x29, sp, #0x90
//   0x025074: d53bd053  mrs      x19, tpidr_el0
//   0x025078: f9401668  ldr      x8, [x19, #0x28]
//   0x02507c: f0000214  adrp     x20, #0x68000
//   0x025080: 91124294  add      x20, x20, #0x490
//   0x025084: f81c83a8  stur     x8, [x29, #-0x38]
//   0x025088: f0000208  adrp     x8, #0x68000
//   0x02508c: 91128108  add      x8, x8, #0x4a0
//   0x025090: 08dffd08  ldarb    w8, [x8]
//   0x025094: 36000408  tbz      w8, #0, #0x25114
//   0x025098: f0000208  adrp     x8, #0x68000
uint64_t fde_0107_sub_02505c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x91128108ULL) + (x2 ^ 0x02505CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02505c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x025060: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x025064: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x025068: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02506c: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x025070: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x025074: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x025078: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000214ULL; // 0x02507c: adrp x20, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x91124294ULL; // 0x025080: add x20, x20, #0x490
    return acc;
}

// [EN] Reconstructed FDE #0108 @ 0x025274..0x02527c (8 bytes)
// [VN] Phục dựng FDE #0108 tại 0x025274..0x02527c (8 byte)
//   0x025274: f9400401  ldr      x1, [x0, #8]
//   0x025278: 17ffd84e  b        #0x1b3b0
uint64_t fde_0108_sub_025274(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FFD84EULL) + (x2 ^ 0x025274ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x025274: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD84EULL; // 0x025278: b #0x1b3b0
    return acc;
}

// [EN] Reconstructed FDE #0109 @ 0x02527c..0x02528c (16 bytes)
// [VN] Phục dựng FDE #0109 tại 0x02527c..0x02528c (16 byte)
//   0x02527c: 51004008  sub      w8, w0, #0x10
//   0x025280: 71005d1f  cmp      w8, #0x17
//   0x025284: 1a9f27e0  cset     w0, lo
//   0x025288: d65f03c0  ret      
uint64_t fde_0109_sub_02527c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x51004008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02527CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x51004008ULL; // 0x02527c: sub w8, w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x71005D1FULL; // 0x025280: cmp w8, #0x17
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F27E0ULL; // 0x025284: cset w0, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025288: ret 
    return acc;
}

// [EN] Reconstructed FDE #0110 @ 0x02528c..0x0254e4 (600 bytes)
// [VN] Phục dựng FDE #0110 tại 0x02528c..0x0254e4 (600 byte)
//   0x02528c: d10183ff  sub      sp, sp, #0x60
//   0x025290: f9001bf5  str      x21, [sp, #0x30]
//   0x025294: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x025298: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02529c: 910143fd  add      x29, sp, #0x50
//   0x0252a0: d53bd053  mrs      x19, tpidr_el0
//   0x0252a4: f9401668  ldr      x8, [x19, #0x28]
//   0x0252a8: f0000214  adrp     x20, #0x68000
//   0x0252ac: 9112c294  add      x20, x20, #0x4b0
//   0x0252b0: f90017e8  str      x8, [sp, #0x28]
//   0x0252b4: f0000208  adrp     x8, #0x68000
//   0x0252b8: 91130108  add      x8, x8, #0x4c0
//   0x0252bc: 08dffd08  ldarb    w8, [x8]
//   0x0252c0: 360003e8  tbz      w8, #0, #0x2533c
//   0x0252c4: f0000208  adrp     x8, #0x68000
//   0x0252c8: f9425909  ldr      x9, [x8, #0x4b0]
uint64_t fde_0110_sub_02528c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x08DFFD08ULL) + (x2 ^ 0x02528CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02528c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x025290: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x025294: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x025298: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02529c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0252a0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0252a4: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000214ULL; // 0x0252a8: adrp x20, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x9112C294ULL; // 0x0252ac: add x20, x20, #0x4b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x0252b0: str x8, [sp, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0111 @ 0x0254e4..0x0254ec (8 bytes)
// [VN] Phục dựng FDE #0111 tại 0x0254e4..0x0254ec (8 byte)
//   0x0254e4: f9400401  ldr      x1, [x0, #8]
//   0x0254e8: 17ffd932  b        #0x1b9b0
uint64_t fde_0111_sub_0254e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FFD932ULL) + (x2 ^ 0x0254E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x0254e4: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD932ULL; // 0x0254e8: b #0x1b9b0
    return acc;
}

// [EN] Reconstructed FDE #0112 @ 0x0254ec..0x0256f4 (520 bytes)
// [VN] Phục dựng FDE #0112 tại 0x0254ec..0x0256f4 (520 byte)
//   0x0254ec: d10243ff  sub      sp, sp, #0x90
//   0x0254f0: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0254f4: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0254f8: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0254fc: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x025500: 910203fd  add      x29, sp, #0x80
//   0x025504: d53bd053  mrs      x19, tpidr_el0
//   0x025508: f9401668  ldr      x8, [x19, #0x28]
//   0x02550c: f0000214  adrp     x20, #0x68000
//   0x025510: 91134294  add      x20, x20, #0x4d0
//   0x025514: f81c83a8  stur     x8, [x29, #-0x38]
//   0x025518: f0000208  adrp     x8, #0x68000
//   0x02551c: 91138108  add      x8, x8, #0x4e0
//   0x025520: 08dffd08  ldarb    w8, [x8]
//   0x025524: 36000408  tbz      w8, #0, #0x255a4
//   0x025528: f0000208  adrp     x8, #0x68000
uint64_t fde_0112_sub_0254ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x91138108ULL) + (x2 ^ 0x0254ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x0254ec: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x0254f0: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x0254f4: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0254f8: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0254fc: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x025500: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x025504: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x025508: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000214ULL; // 0x02550c: adrp x20, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x91134294ULL; // 0x025510: add x20, x20, #0x4d0
    return acc;
}

// [EN] Reconstructed FDE #0113 @ 0x0256f4..0x0256fc (8 bytes)
// [VN] Phục dựng FDE #0113 tại 0x0256f4..0x0256fc (8 byte)
//   0x0256f4: f9400401  ldr      x1, [x0, #8]
//   0x0256f8: 17ffd63e  b        #0x1aff0
uint64_t fde_0113_sub_0256f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FFD63EULL) + (x2 ^ 0x0256F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x0256f4: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD63EULL; // 0x0256f8: b #0x1aff0
    return acc;
}

// [EN] Reconstructed FDE #0114 @ 0x0256fc..0x0258c0 (452 bytes)
// [VN] Phục dựng FDE #0114 tại 0x0256fc..0x0258c0 (452 byte)
//   0x0256fc: d10183ff  sub      sp, sp, #0x60
//   0x025700: f9000bf9  str      x25, [sp, #0x10]
//   0x025704: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x025708: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02570c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x025710: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x025714: 910143fd  add      x29, sp, #0x50
//   0x025718: d53bd056  mrs      x22, tpidr_el0
//   0x02571c: f94016c8  ldr      x8, [x22, #0x28]
//   0x025720: 2a0203f5  mov      w21, w2
//   0x025724: aa0103f4  mov      x20, x1
//   0x025728: aa0003f3  mov      x19, x0
//   0x02572c: f90007e8  str      x8, [sp, #8]
//   0x025730: 97ffd530  bl       #0x1abf0
//   0x025734: b0000161  adrp     x1, #0x52000
//   0x025738: 912df421  add      x1, x1, #0xb7d
uint64_t fde_0114_sub_0256fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0256FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0256fc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF9ULL; // 0x025700: str x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x025704: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x025708: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02570c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x025710: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x025714: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x025718: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02571c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x025720: mov w21, w2
    return acc;
}

// [EN] Reconstructed FDE #0115 @ 0x0258c0..0x02598c (204 bytes)
// [VN] Phục dựng FDE #0115 tại 0x0258c0..0x02598c (204 byte)
//   0x0258c0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0258c4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0258c8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0258cc: 910083fd  add      x29, sp, #0x20
//   0x0258d0: aa0003f3  mov      x19, x0
//   0x0258d4: f9401800  ldr      x0, [x0, #0x30]
//   0x0258d8: b4000060  cbz      x0, #0x258e4
//   0x0258dc: 97ffd531  bl       #0x1ada0
//   0x0258e0: f9001a7f  str      xzr, [x19, #0x30]
//   0x0258e4: f9401674  ldr      x20, [x19, #0x28]
//   0x0258e8: b40002f4  cbz      x20, #0x25944
//   0x0258ec: f9400e88  ldr      x8, [x20, #0x18]
//   0x0258f0: b4000248  cbz      x8, #0x25938
//   0x0258f4: f9400a80  ldr      x0, [x20, #0x10]
//   0x0258f8: b40000a0  cbz      x0, #0x2590c
//   0x0258fc: f9400015  ldr      x21, [x0]
uint64_t fde_0115_sub_0258c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB4000248ULL) + (x2 ^ 0x0258C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0258c0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0258c4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0258c8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0258cc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0258d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401800ULL; // 0x0258d4: ldr x0, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x0258d8: cbz x0, #0x258e4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD531ULL; // 0x0258dc: bl #0x1ada0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001A7FULL; // 0x0258e0: str xzr, [x19, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401674ULL; // 0x0258e4: ldr x20, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0116 @ 0x02598c..0x025c28 (668 bytes)
// [VN] Phục dựng FDE #0116 tại 0x02598c..0x025c28 (668 byte)
//   0x02598c: d10283ff  sub      sp, sp, #0xa0
//   0x025990: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x025994: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x025998: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02599c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x0259a0: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x0259a4: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0259a8: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0259ac: 910243fd  add      x29, sp, #0x90
//   0x0259b0: d53bd054  mrs      x20, tpidr_el0
//   0x0259b4: f9401688  ldr      x8, [x20, #0x28]
//   0x0259b8: aa0003f3  mov      x19, x0
//   0x0259bc: f90017e8  str      x8, [sp, #0x28]
//   0x0259c0: a940a009  ldp      x9, x8, [x0, #8]
//   0x0259c4: 2a1f03e0  mov      w0, wzr
//   0x0259c8: 8b224135  add      x21, x9, w2, uxtw
uint64_t fde_0116_sub_02598c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x02598CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02598c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x025990: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x025994: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x025998: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02599c: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x0259a0: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x0259a4: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x0259a8: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x0259ac: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0259b0: mrs x20, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0117 @ 0x025c28..0x025c58 (48 bytes)
// [VN] Phục dựng FDE #0117 tại 0x025c28..0x025c58 (48 byte)
//   0x025c28: 2a0003e8  mov      w8, w0
//   0x025c2c: 7100341f  cmp      w0, #0xd
//   0x025c30: 52800020  mov      w0, #1
//   0x025c34: 540000c0  b.eq     #0x25c4c
//   0x025c38: 7100345f  cmp      w2, #0xd
//   0x025c3c: 54000080  b.eq     #0x25c4c
//   0x025c40: 6b08005f  cmp      w2, w8
//   0x025c44: 34000061  cbz      w1, #0x25c50
//   0x025c48: 1a9f07e0  cset     w0, ne
//   0x025c4c: d65f03c0  ret      
//   0x025c50: 1a9f17e0  cset     w0, eq
//   0x025c54: d65f03c0  ret      
uint64_t fde_0117_sub_025c28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025C28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E8ULL; // 0x025c28: mov w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100341FULL; // 0x025c2c: cmp w0, #0xd
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x025c30: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x025c34: b.eq #0x25c4c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100345FULL; // 0x025c38: cmp w2, #0xd
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x025c3c: b.eq #0x25c4c
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08005FULL; // 0x025c40: cmp w2, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x34000061ULL; // 0x025c44: cbz w1, #0x25c50
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x025c48: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025c4c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0118 @ 0x025c58..0x02832c (9940 bytes)
// [VN] Phục dựng FDE #0118 tại 0x025c58..0x02832c (9940 byte)
//   0x025c58: 6db923e9  stp      d9, d8, [sp, #-0x70]!
//   0x025c5c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x025c60: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x025c64: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x025c68: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x025c6c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x025c70: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x025c74: 910183fd  add      x29, sp, #0x60
//   0x025c78: d10a03ff  sub      sp, sp, #0x280
//   0x025c7c: d53bd05c  mrs      x28, tpidr_el0
//   0x025c80: f9401788  ldr      x8, [x28, #0x28]
//   0x025c84: d10303a9  sub      x9, x29, #0xc0
//   0x025c88: 91008129  add      x9, x9, #0x20
//   0x025c8c: aa0403f3  mov      x19, x4
//   0x025c90: f81883a8  stur     x8, [x29, #-0x78]
//   0x025c94: a936ffbf  stp      xzr, xzr, [x29, #-0x98]
uint64_t fde_0118_sub_025c58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DB923E9ULL) + (x1 ^ 0x91008129ULL) + (x2 ^ 0x025C58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DB923E9ULL; // 0x025c58: stp d9, d8, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x025c5c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x025c60: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x025c64: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x025c68: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x025c6c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x025c70: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x025c74: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD10A03FFULL; // 0x025c78: sub sp, sp, #0x280
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x025c7c: mrs x28, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0119 @ 0x02832c..0x02846c (320 bytes)
// [VN] Phục dựng FDE #0119 tại 0x02832c..0x02846c (320 byte)
//   0x02832c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x028330: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x028334: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x028338: 910083fd  add      x29, sp, #0x20
//   0x02833c: f9401008  ldr      x8, [x0, #0x20]
//   0x028340: aa0003f3  mov      x19, x0
//   0x028344: b4000608  cbz      x8, #0x28404
//   0x028348: f9400e74  ldr      x20, [x19, #0x18]
//   0x02834c: b5000114  cbnz     x20, #0x2836c
//   0x028350: b50003b4  cbnz     x20, #0x283c4
//   0x028354: 14000022  b        #0x283dc
//   0x028358: aa1503e0  mov      x0, x21
//   0x02835c: 97ffc9c9  bl       #0x1aa80
//   0x028360: f900169f  str      xzr, [x20, #0x28]
//   0x028364: f9400294  ldr      x20, [x20]
//   0x028368: b40001d4  cbz      x20, #0x283a0
uint64_t fde_0119_sub_02832c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FFC9C9ULL) + (x2 ^ 0x02832CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02832c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x028330: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x028334: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x028338: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401008ULL; // 0x02833c: ldr x8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028340: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000608ULL; // 0x028344: cbz x8, #0x28404
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400E74ULL; // 0x028348: ldr x20, [x19, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000114ULL; // 0x02834c: cbnz x20, #0x2836c
    acc = (acc * 0x100000001B3ULL) ^ 0xB50003B4ULL; // 0x028350: cbnz x20, #0x283c4
    return acc;
}

// [EN] Reconstructed FDE #0120 @ 0x02846c..0x028634 (456 bytes)
// [VN] Phục dựng FDE #0120 tại 0x02846c..0x028634 (456 byte)
//   0x02846c: 91002008  add      x8, x0, #8
//   0x028470: eb01011f  cmp      x8, x1
//   0x028474: 540000a0  b.eq     #0x28488
//   0x028478: b9400089  ldr      w9, [x4]
//   0x02847c: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x028480: 6b0a013f  cmp      w9, w10
//   0x028484: 5400018a  b.ge     #0x284b4
//   0x028488: f9400009  ldr      x9, [x0]
//   0x02848c: f940002a  ldr      x10, [x1]
//   0x028490: aa0103eb  mov      x11, x1
//   0x028494: eb01013f  cmp      x9, x1
//   0x028498: 54000340  b.eq     #0x28500
//   0x02849c: b40001ea  cbz      x10, #0x284d8
//   0x0284a0: aa0a03e9  mov      x9, x10
//   0x0284a4: aa0903eb  mov      x11, x9
//   0x0284a8: f9400529  ldr      x9, [x9, #8]
uint64_t fde_0120_sub_02846c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002008ULL) + (x1 ^ 0xB40001EAULL) + (x2 ^ 0x02846CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x02846c: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x028470: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x028474: b.eq #0x28488
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400089ULL; // 0x028478: ldr w9, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C2AULL; // 0x02847c: ldr w10, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x028480: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018AULL; // 0x028484: b.ge #0x284b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x028488: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x02848c: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x028490: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0121 @ 0x028634..0x028674 (64 bytes)
// [VN] Phục dựng FDE #0121 tại 0x028634..0x028674 (64 byte)
//   0x028634: b40001e1  cbz      x1, #0x28670
//   0x028638: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02863c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028640: 910043fd  add      x29, sp, #0x10
//   0x028644: aa0103f3  mov      x19, x1
//   0x028648: f9400021  ldr      x1, [x1]
//   0x02864c: aa0003f4  mov      x20, x0
//   0x028650: 97ffcb58  bl       #0x1b3b0
//   0x028654: f9400661  ldr      x1, [x19, #8]
//   0x028658: aa1403e0  mov      x0, x20
//   0x02865c: 97ffcb55  bl       #0x1b3b0
//   0x028660: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x028664: aa1303e0  mov      x0, x19
//   0x028668: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02866c: 17ffc905  b        #0x1aa80
//   0x028670: d65f03c0  ret      
uint64_t fde_0121_sub_028634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x028634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x028634: cbz x1, #0x28670
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x028638: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02863c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028640: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028644: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x028648: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02864c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFCB58ULL; // 0x028650: bl #0x1b3b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x028654: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x028658: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0122 @ 0x028674..0x02883c (456 bytes)
// [VN] Phục dựng FDE #0122 tại 0x028674..0x02883c (456 byte)
//   0x028674: 91002008  add      x8, x0, #8
//   0x028678: eb01011f  cmp      x8, x1
//   0x02867c: 540000a0  b.eq     #0x28690
//   0x028680: b9400089  ldr      w9, [x4]
//   0x028684: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x028688: 6b0a013f  cmp      w9, w10
//   0x02868c: 5400018a  b.ge     #0x286bc
//   0x028690: f9400009  ldr      x9, [x0]
//   0x028694: f940002a  ldr      x10, [x1]
//   0x028698: aa0103eb  mov      x11, x1
//   0x02869c: eb01013f  cmp      x9, x1
//   0x0286a0: 54000340  b.eq     #0x28708
//   0x0286a4: b40001ea  cbz      x10, #0x286e0
//   0x0286a8: aa0a03e9  mov      x9, x10
//   0x0286ac: aa0903eb  mov      x11, x9
//   0x0286b0: f9400529  ldr      x9, [x9, #8]
uint64_t fde_0122_sub_028674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002008ULL) + (x1 ^ 0xB40001EAULL) + (x2 ^ 0x028674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x028674: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x028678: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02867c: b.eq #0x28690
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400089ULL; // 0x028680: ldr w9, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C2AULL; // 0x028684: ldr w10, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x028688: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018AULL; // 0x02868c: b.ge #0x286bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x028690: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x028694: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x028698: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0123 @ 0x02883c..0x02887c (64 bytes)
// [VN] Phục dựng FDE #0123 tại 0x02883c..0x02887c (64 byte)
//   0x02883c: b40001e1  cbz      x1, #0x28878
//   0x028840: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x028844: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028848: 910043fd  add      x29, sp, #0x10
//   0x02884c: aa0103f3  mov      x19, x1
//   0x028850: f9400021  ldr      x1, [x1]
//   0x028854: aa0003f4  mov      x20, x0
//   0x028858: 97ffcc56  bl       #0x1b9b0
//   0x02885c: f9400661  ldr      x1, [x19, #8]
//   0x028860: aa1403e0  mov      x0, x20
//   0x028864: 97ffcc53  bl       #0x1b9b0
//   0x028868: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02886c: aa1303e0  mov      x0, x19
//   0x028870: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x028874: 17ffc883  b        #0x1aa80
//   0x028878: d65f03c0  ret      
uint64_t fde_0123_sub_02883c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02883CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x02883c: cbz x1, #0x28878
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x028840: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028844: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028848: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02884c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x028850: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x028854: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFCC56ULL; // 0x028858: bl #0x1b9b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x02885c: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x028860: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0124 @ 0x02887c..0x028a44 (456 bytes)
// [VN] Phục dựng FDE #0124 tại 0x02887c..0x028a44 (456 byte)
//   0x02887c: 91002008  add      x8, x0, #8
//   0x028880: eb01011f  cmp      x8, x1
//   0x028884: 540000a0  b.eq     #0x28898
//   0x028888: b9400089  ldr      w9, [x4]
//   0x02888c: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x028890: 6b0a013f  cmp      w9, w10
//   0x028894: 5400018a  b.ge     #0x288c4
//   0x028898: f9400009  ldr      x9, [x0]
//   0x02889c: f940002a  ldr      x10, [x1]
//   0x0288a0: aa0103eb  mov      x11, x1
//   0x0288a4: eb01013f  cmp      x9, x1
//   0x0288a8: 54000340  b.eq     #0x28910
//   0x0288ac: b40001ea  cbz      x10, #0x288e8
//   0x0288b0: aa0a03e9  mov      x9, x10
//   0x0288b4: aa0903eb  mov      x11, x9
//   0x0288b8: f9400529  ldr      x9, [x9, #8]
uint64_t fde_0124_sub_02887c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002008ULL) + (x1 ^ 0xB40001EAULL) + (x2 ^ 0x02887CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x02887c: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x028880: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x028884: b.eq #0x28898
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400089ULL; // 0x028888: ldr w9, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C2AULL; // 0x02888c: ldr w10, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x028890: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018AULL; // 0x028894: b.ge #0x288c4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x028898: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x02889c: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x0288a0: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0125 @ 0x028a44..0x028a84 (64 bytes)
// [VN] Phục dựng FDE #0125 tại 0x028a44..0x028a84 (64 byte)
//   0x028a44: b40001e1  cbz      x1, #0x28a80
//   0x028a48: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x028a4c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028a50: 910043fd  add      x29, sp, #0x10
//   0x028a54: aa0103f3  mov      x19, x1
//   0x028a58: f9400021  ldr      x1, [x1]
//   0x028a5c: aa0003f4  mov      x20, x0
//   0x028a60: 97ffc964  bl       #0x1aff0
//   0x028a64: f9400661  ldr      x1, [x19, #8]
//   0x028a68: aa1403e0  mov      x0, x20
//   0x028a6c: 97ffc961  bl       #0x1aff0
//   0x028a70: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x028a74: aa1303e0  mov      x0, x19
//   0x028a78: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x028a7c: 17ffc801  b        #0x1aa80
//   0x028a80: d65f03c0  ret      
uint64_t fde_0125_sub_028a44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x028A44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x028a44: cbz x1, #0x28a80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x028a48: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028a4c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028a50: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028a54: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x028a58: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x028a5c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC964ULL; // 0x028a60: bl #0x1aff0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x028a64: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x028a68: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0126 @ 0x028a84..0x028ca0 (540 bytes)
// [VN] Phục dựng FDE #0126 tại 0x028a84..0x028ca0 (540 byte)
//   0x028a84: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x028a88: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x028a8c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x028a90: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028a94: 9100c3fd  add      x29, sp, #0x30
//   0x028a98: f9400416  ldr      x22, [x0, #8]
//   0x028a9c: b9400037  ldr      w23, [x1]
//   0x028aa0: aa0003f3  mov      x19, x0
//   0x028aa4: aa0203f5  mov      x21, x2
//   0x028aa8: b40001b6  cbz      x22, #0x28adc
//   0x028aac: 9e6702c0  fmov     d0, x22
//   0x028ab0: 0e205800  cnt      v0.8b, v0.8b
//   0x028ab4: 2e303800  uaddlv   h0, v0.8b
//   0x028ab8: 1e260008  fmov     w8, s0
//   0x028abc: f100051f  cmp      x8, #1
//   0x028ac0: 54000109  b.ls     #0x28ae0
uint64_t fde_0126_sub_028a84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x2E303800ULL) + (x2 ^ 0x028A84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x028a84: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x028a88: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x028a8c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x028a90: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028a94: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400416ULL; // 0x028a98: ldr x22, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400037ULL; // 0x028a9c: ldr w23, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028aa0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x028aa4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001B6ULL; // 0x028aa8: cbz x22, #0x28adc
    return acc;
}

// [EN] Reconstructed FDE #0127 @ 0x028ca0..0x028d84 (228 bytes)
// [VN] Phục dựng FDE #0127 tại 0x028ca0..0x028d84 (228 byte)
//   0x028ca0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x028ca4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x028ca8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x028cac: 910083fd  add      x29, sp, #0x20
//   0x028cb0: f1000428  subs     x8, x1, #1
//   0x028cb4: aa0003f3  mov      x19, x0
//   0x028cb8: 54000061  b.ne     #0x28cc4
//   0x028cbc: 52800054  mov      w20, #2
//   0x028cc0: 14000007  b        #0x28cdc
//   0x028cc4: aa0103f4  mov      x20, x1
//   0x028cc8: ea08003f  tst      x1, x8
//   0x028ccc: 54000080  b.eq     #0x28cdc
//   0x028cd0: aa1403e0  mov      x0, x20
//   0x028cd4: 97ffca87  bl       #0x1b6f0
//   0x028cd8: aa0003f4  mov      x20, x0
//   0x028cdc: f9400675  ldr      x21, [x19, #8]
uint64_t fde_0127_sub_028ca0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x028CA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x028ca0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x028ca4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x028ca8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x028cac: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x028cb0: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028cb4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x028cb8: b.ne #0x28cc4
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x028cbc: mov w20, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x14000007ULL; // 0x028cc0: b #0x28cdc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x028cc4: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0128 @ 0x028d84..0x028f0c (392 bytes)
// [VN] Phục dựng FDE #0128 tại 0x028d84..0x028f0c (392 byte)
//   0x028d84: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x028d88: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028d8c: 910043fd  add      x29, sp, #0x10
//   0x028d90: aa0003f3  mov      x19, x0
//   0x028d94: b4000421  cbz      x1, #0x28e18
//   0x028d98: aa0103f4  mov      x20, x1
//   0x028d9c: d37dfc28  lsr      x8, x1, #0x3d
//   0x028da0: b5000b08  cbnz     x8, #0x28f00
//   0x028da4: d37df280  lsl      x0, x20, #3
//   0x028da8: 97ffcbae  bl       #0x1bc60
//   0x028dac: f9400268  ldr      x8, [x19]
//   0x028db0: f9000260  str      x0, [x19]
//   0x028db4: b4000068  cbz      x8, #0x28dc0
//   0x028db8: aa0803e0  mov      x0, x8
//   0x028dbc: 97ffc731  bl       #0x1aa80
//   0x028dc0: aa1f03e8  mov      x8, xzr
uint64_t fde_0128_sub_028d84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000068ULL) + (x2 ^ 0x028D84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x028d84: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028d88: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028d8c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028d90: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000421ULL; // 0x028d94: cbz x1, #0x28e18
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x028d98: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x028d9c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000B08ULL; // 0x028da0: cbnz x8, #0x28f00
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF280ULL; // 0x028da4: lsl x0, x20, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFCBAEULL; // 0x028da8: bl #0x1bc60
    return acc;
}

// [EN] Reconstructed FDE #0129 @ 0x028f0c..0x028ff8 (236 bytes)
// [VN] Phục dựng FDE #0129 tại 0x028f0c..0x028ff8 (236 byte)
//   0x028f0c: d10183ff  sub      sp, sp, #0x60
//   0x028f10: f90013f7  str      x23, [sp, #0x20]
//   0x028f14: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x028f18: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x028f1c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x028f20: 910143fd  add      x29, sp, #0x50
//   0x028f24: d53bd057  mrs      x23, tpidr_el0
//   0x028f28: f94016e8  ldr      x8, [x23, #0x28]
//   0x028f2c: aa0303f5  mov      x21, x3
//   0x028f30: aa0203e4  mov      x4, x2
//   0x028f34: 910043e2  add      x2, sp, #0x10
//   0x028f38: 910023e3  add      x3, sp, #8
//   0x028f3c: aa0003f3  mov      x19, x0
//   0x028f40: f9000fe8  str      x8, [sp, #0x18]
//   0x028f44: 97ffca37  bl       #0x1b820
//   0x028f48: f9400014  ldr      x20, [x0]
uint64_t fde_0129_sub_028f0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x028F0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x028f0c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x028f10: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x028f14: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x028f18: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x028f1c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x028f20: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x028f24: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x028f28: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x028f2c: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E4ULL; // 0x028f30: mov x4, x2
    return acc;
}

// [EN] Reconstructed FDE #0130 @ 0x028ff8..0x0292d4 (732 bytes)
// [VN] Phục dựng FDE #0130 tại 0x028ff8..0x0292d4 (732 byte)
//   0x028ff8: d10203ff  sub      sp, sp, #0x80
//   0x028ffc: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x029000: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x029004: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x029008: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02900c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x029010: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x029014: 9101c3fd  add      x29, sp, #0x70
//   0x029018: 91002008  add      x8, x0, #8
//   0x02901c: aa0403f5  mov      x21, x4
//   0x029020: aa0103f4  mov      x20, x1
//   0x029024: eb01011f  cmp      x8, x1
//   0x029028: a90083e3  stp      x3, x0, [sp, #8]
//   0x02902c: f90003e8  str      x8, [sp]
//   0x029030: f9000fe2  str      x2, [sp, #0x18]
//   0x029034: 54000380  b.eq     #0x290a4
uint64_t fde_0130_sub_028ff8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xA90083E3ULL) + (x2 ^ 0x028FF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x028ff8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x028ffc: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x029000: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x029004: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x029008: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02900c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x029010: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x029014: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x029018: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F5ULL; // 0x02901c: mov x21, x4
    return acc;
}

// [EN] Reconstructed FDE #0131 @ 0x0292d4..0x0293f4 (288 bytes)
// [VN] Phục dựng FDE #0131 tại 0x0292d4..0x0293f4 (288 byte)
//   0x0292d4: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0292d8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0292dc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0292e0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0292e4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0292e8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0292ec: 910143fd  add      x29, sp, #0x50
//   0x0292f0: aa0003f4  mov      x20, x0
//   0x0292f4: f8408e97  ldr      x23, [x20, #8]!
//   0x0292f8: aa0103f3  mov      x19, x1
//   0x0292fc: b4000657  cbz      x23, #0x293c4
//   0x029300: 39400048  ldrb     w8, [x2]
//   0x029304: a940a849  ldp      x9, x10, [x2, #8]
//   0x029308: 91002014  add      x20, x0, #8
//   0x02930c: d341fd0b  lsr      x11, x8, #1
//   0x029310: 7200011f  tst      w8, #1
uint64_t fde_0131_sub_0292d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x0292D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0292d4: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0292d8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0292dc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0292e0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0292e4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0292e8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0292ec: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0292f0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x0292f4: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0292f8: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0132 @ 0x0293f4..0x029478 (132 bytes)
// [VN] Phục dựng FDE #0132 tại 0x0293f4..0x029478 (132 byte)
//   0x0293f4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0293f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0293fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x029400: 910083fd  add      x29, sp, #0x20
//   0x029404: f9400014  ldr      x20, [x0]
//   0x029408: b4000254  cbz      x20, #0x29450
//   0x02940c: f9400408  ldr      x8, [x0, #8]
//   0x029410: aa0003f3  mov      x19, x0
//   0x029414: eb14011f  cmp      x8, x20
//   0x029418: 54000240  b.eq     #0x29460
//   0x02941c: aa0803f5  mov      x21, x8
//   0x029420: 385e8ea9  ldrb     w9, [x21, #-0x18]!
//   0x029424: 370000c9  tbnz     w9, #0, #0x2943c
//   0x029428: eb15029f  cmp      x20, x21
//   0x02942c: aa1503e8  mov      x8, x21
//   0x029430: 540000c0  b.eq     #0x29448
uint64_t fde_0132_sub_0293f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x370000C9ULL) + (x2 ^ 0x0293F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0293f4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0293f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0293fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x029400: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x029404: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000254ULL; // 0x029408: cbz x20, #0x29450
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02940c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029410: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB14011FULL; // 0x029414: cmp x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000240ULL; // 0x029418: b.eq #0x29460
    return acc;
}

// [EN] Reconstructed FDE #0133 @ 0x029478..0x0299f4 (1404 bytes)
// [VN] Phục dựng FDE #0133 tại 0x029478..0x0299f4 (1404 byte)
//   0x029478: d10743ff  sub      sp, sp, #0x1d0
//   0x02947c: a9176ffc  stp      x28, x27, [sp, #0x170]
//   0x029480: a91867fa  stp      x26, x25, [sp, #0x180]
//   0x029484: a9195ff8  stp      x24, x23, [sp, #0x190]
//   0x029488: a91a57f6  stp      x22, x21, [sp, #0x1a0]
//   0x02948c: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x029490: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x029494: 910703fd  add      x29, sp, #0x1c0
//   0x029498: aa0803f5  mov      x21, x8
//   0x02949c: d00001fc  adrp     x28, #0x67000
//   0x0294a0: d00001e8  adrp     x8, #0x67000
//   0x0294a4: d53bd05b  mrs      x27, tpidr_el0
//   0x0294a8: f947539c  ldr      x28, [x28, #0xea0]
//   0x0294ac: f9477d08  ldr      x8, [x8, #0xef8]
//   0x0294b0: f9401769  ldr      x9, [x27, #0x28]
//   0x0294b4: 910103f3  add      x19, sp, #0x40
uint64_t fde_0133_sub_029478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0xF947539CULL) + (x2 ^ 0x029478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x029478: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9176FFCULL; // 0x02947c: stp x28, x27, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91867FAULL; // 0x029480: stp x26, x25, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9195FF8ULL; // 0x029484: stp x24, x23, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A57F6ULL; // 0x029488: stp x22, x21, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x02948c: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x029490: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x029494: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F5ULL; // 0x029498: mov x21, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001FCULL; // 0x02949c: adrp x28, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0134 @ 0x0299f4..0x029c0c (536 bytes)
// [VN] Phục dựng FDE #0134 tại 0x0299f4..0x029c0c (536 byte)
//   0x0299f4: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x0299f8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0299fc: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x029a00: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x029a04: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x029a08: 910103fd  add      x29, sp, #0x40
//   0x029a0c: f9400008  ldr      x8, [x0]
//   0x029a10: aa0003f3  mov      x19, x0
//   0x029a14: f85e8109  ldur     x9, [x8, #-0x18]
//   0x029a18: 8b090000  add      x0, x0, x9
//   0x029a1c: b9402009  ldr      w9, [x0, #0x20]
//   0x029a20: 34000069  cbz      w9, #0x29a2c
//   0x029a24: 321e0121  orr      w1, w9, #4
//   0x029a28: 1400005c  b        #0x29b98
//   0x029a2c: f9404400  ldr      x0, [x0, #0x88]
//   0x029a30: 2a0203f4  mov      w20, w2
uint64_t fde_0134_sub_0299f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x321E0121ULL) + (x2 ^ 0x0299F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x0299f4: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0299f8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0299fc: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x029a00: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x029a04: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x029a08: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x029a0c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029a10: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8109ULL; // 0x029a14: ldur x9, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090000ULL; // 0x029a18: add x0, x0, x9
    return acc;
}

// [EN] Reconstructed FDE #0135 @ 0x029c0c..0x029c80 (116 bytes)
// [VN] Phục dựng FDE #0135 tại 0x029c0c..0x029c80 (116 byte)
//   0x029c0c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x029c10: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x029c14: 910043fd  add      x29, sp, #0x10
//   0x029c18: d00001e8  adrp     x8, #0x67000
//   0x029c1c: d00001e9  adrp     x9, #0x67000
//   0x029c20: f9475108  ldr      x8, [x8, #0xea0]
//   0x029c24: f9473529  ldr      x9, [x9, #0xe68]
//   0x029c28: 3941600a  ldrb     w10, [x0, #0x58]
//   0x029c2c: aa0003f3  mov      x19, x0
//   0x029c30: 9100610b  add      x11, x8, #0x18
//   0x029c34: 9101a10c  add      x12, x8, #0x68
//   0x029c38: 91010108  add      x8, x8, #0x40
//   0x029c3c: 91004129  add      x9, x9, #0x10
//   0x029c40: f900000b  str      x11, [x0]
//   0x029c44: f900400c  str      x12, [x0, #0x80]
//   0x029c48: a9012408  stp      x8, x9, [x0, #0x10]
uint64_t fde_0135_sub_029c0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004129ULL) + (x2 ^ 0x029C0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x029c0c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x029c10: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x029c14: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E8ULL; // 0x029c18: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E9ULL; // 0x029c1c: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475108ULL; // 0x029c20: ldr x8, [x8, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473529ULL; // 0x029c24: ldr x9, [x9, #0xe68]
    acc = (acc * 0x100000001B3ULL) ^ 0x3941600AULL; // 0x029c28: ldrb w10, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029c2c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9100610BULL; // 0x029c30: add x11, x8, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0136 @ 0x029c80..0x02a1d4 (1364 bytes)
// [VN] Phục dựng FDE #0136 tại 0x029c80..0x02a1d4 (1364 byte)
//   0x029c80: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x029c84: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x029c88: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x029c8c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x029c90: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x029c94: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x029c98: 910143fd  add      x29, sp, #0x50
//   0x029c9c: d106c3ff  sub      sp, sp, #0x1b0
//   0x029ca0: d53bd04a  mrs      x10, tpidr_el0
//   0x029ca4: f9401548  ldr      x8, [x10, #0x28]
//   0x029ca8: f00001e9  adrp     x9, #0x68000
//   0x029cac: 9115e129  add      x9, x9, #0x578
//   0x029cb0: f81a03a8  stur     x8, [x29, #-0x60]
//   0x029cb4: a9402133  ldp      x19, x8, [x9]
//   0x029cb8: eb08027f  cmp      x19, x8
//   0x029cbc: f90027e8  str      x8, [sp, #0x48]
uint64_t fde_0136_sub_029c80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x029C80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x029c80: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x029c84: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x029c88: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x029c8c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x029c90: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x029c94: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x029c98: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x029c9c: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD04AULL; // 0x029ca0: mrs x10, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401548ULL; // 0x029ca4: ldr x8, [x10, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0137 @ 0x02a1d4..0x02a3dc (520 bytes)
// [VN] Phục dựng FDE #0137 tại 0x02a1d4..0x02a3dc (520 byte)
//   0x02a1d4: d10243ff  sub      sp, sp, #0x90
//   0x02a1d8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02a1dc: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02a1e0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02a1e4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02a1e8: 910203fd  add      x29, sp, #0x80
//   0x02a1ec: d53bd053  mrs      x19, tpidr_el0
//   0x02a1f0: f9401668  ldr      x8, [x19, #0x28]
//   0x02a1f4: d00001f4  adrp     x20, #0x68000
//   0x02a1f8: 91166294  add      x20, x20, #0x598
//   0x02a1fc: f81c83a8  stur     x8, [x29, #-0x38]
//   0x02a200: d00001e8  adrp     x8, #0x68000
//   0x02a204: 9116a108  add      x8, x8, #0x5a8
//   0x02a208: 08dffd08  ldarb    w8, [x8]
//   0x02a20c: 36000408  tbz      w8, #0, #0x2a28c
//   0x02a210: d00001e8  adrp     x8, #0x68000
uint64_t fde_0137_sub_02a1d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x9116A108ULL) + (x2 ^ 0x02A1D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02a1d4: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02a1d8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02a1dc: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02a1e0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02a1e4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02a1e8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02a1ec: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02a1f0: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001F4ULL; // 0x02a1f4: adrp x20, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x91166294ULL; // 0x02a1f8: add x20, x20, #0x598
    return acc;
}

// [EN] Reconstructed FDE #0138 @ 0x02a3dc..0x02a3e4 (8 bytes)
// [VN] Phục dựng FDE #0138 tại 0x02a3dc..0x02a3e4 (8 byte)
//   0x02a3dc: f9400401  ldr      x1, [x0, #8]
//   0x02a3e0: 17ffc67c  b        #0x1bdd0
uint64_t fde_0138_sub_02a3dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FFC67CULL) + (x2 ^ 0x02A3DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02a3dc: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC67CULL; // 0x02a3e0: b #0x1bdd0
    return acc;
}

// [EN] Reconstructed FDE #0139 @ 0x02a3e4..0x02a5f4 (528 bytes)
// [VN] Phục dựng FDE #0139 tại 0x02a3e4..0x02a5f4 (528 byte)
//   0x02a3e4: d10243ff  sub      sp, sp, #0x90
//   0x02a3e8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02a3ec: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02a3f0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02a3f4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02a3f8: 910203fd  add      x29, sp, #0x80
//   0x02a3fc: d53bd053  mrs      x19, tpidr_el0
//   0x02a400: f9401668  ldr      x8, [x19, #0x28]
//   0x02a404: d00001f4  adrp     x20, #0x68000
//   0x02a408: 9116e294  add      x20, x20, #0x5b8
//   0x02a40c: f81c83a8  stur     x8, [x29, #-0x38]
//   0x02a410: d00001e8  adrp     x8, #0x68000
//   0x02a414: 91172108  add      x8, x8, #0x5c8
//   0x02a418: 08dffd08  ldarb    w8, [x8]
//   0x02a41c: 36000408  tbz      w8, #0, #0x2a49c
//   0x02a420: d00001e8  adrp     x8, #0x68000
uint64_t fde_0139_sub_02a3e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x91172108ULL) + (x2 ^ 0x02A3E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02a3e4: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02a3e8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02a3ec: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02a3f0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02a3f4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02a3f8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02a3fc: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02a400: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001F4ULL; // 0x02a404: adrp x20, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0x9116E294ULL; // 0x02a408: add x20, x20, #0x5b8
    return acc;
}

// [EN] Reconstructed FDE #0140 @ 0x02a5f4..0x02a5fc (8 bytes)
// [VN] Phục dựng FDE #0140 tại 0x02a5f4..0x02a5fc (8 byte)
//   0x02a5f4: f9400401  ldr      x1, [x0, #8]
//   0x02a5f8: 17ffc402  b        #0x1b600
uint64_t fde_0140_sub_02a5f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FFC402ULL) + (x2 ^ 0x02A5F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02a5f4: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC402ULL; // 0x02a5f8: b #0x1b600
    return acc;
}

// [EN] Reconstructed FDE #0141 @ 0x02a5fc..0x02a664 (104 bytes)
// [VN] Phục dựng FDE #0141 tại 0x02a5fc..0x02a664 (104 byte)
//   0x02a5fc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02a600: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a604: 910043fd  add      x29, sp, #0x10
//   0x02a608: 39400008  ldrb     w8, [x0]
//   0x02a60c: f9400409  ldr      x9, [x0, #8]
//   0x02a610: d341fd0a  lsr      x10, x8, #1
//   0x02a614: 7200011f  tst      w8, #1
//   0x02a618: 9a890149  csel     x9, x10, x9, eq
//   0x02a61c: b40001c9  cbz      x9, #0x2a654
//   0x02a620: f9400809  ldr      x9, [x0, #0x10]
//   0x02a624: 7200011f  tst      w8, #1
//   0x02a628: aa0103f3  mov      x19, x1
//   0x02a62c: 910023e1  add      x1, sp, #8
//   0x02a630: 9a801520  csinc    x0, x9, x0, ne
//   0x02a634: 52800142  mov      w2, #0xa
//   0x02a638: 97ffc33e  bl       #0x1b330
uint64_t fde_0141_sub_02a5fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910023E1ULL) + (x2 ^ 0x02A5FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02a5fc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a600: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a604: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02a608: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x02a60c: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0AULL; // 0x02a610: lsr x10, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x02a614: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890149ULL; // 0x02a618: csel x9, x10, x9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001C9ULL; // 0x02a61c: cbz x9, #0x2a654
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x02a620: ldr x9, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0142 @ 0x02a664..0x02a6ac (72 bytes)
// [VN] Phục dựng FDE #0142 tại 0x02a664..0x02a6ac (72 byte)
//   0x02a664: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02a668: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a66c: 910043fd  add      x29, sp, #0x10
//   0x02a670: aa0003f3  mov      x19, x0
//   0x02a674: b9400000  ldr      w0, [x0]
//   0x02a678: 97ffc266  bl       #0x1b010
//   0x02a67c: 36000100  tbz      w0, #0, #0x2a69c
//   0x02a680: b9400660  ldr      w0, [x19, #4]
//   0x02a684: 97ffc5b7  bl       #0x1bd60
//   0x02a688: 360000a0  tbz      w0, #0, #0x2a69c
//   0x02a68c: b9400a60  ldr      w0, [x19, #8]
//   0x02a690: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02a694: f84207f3  ldr      x19, [sp], #0x20
//   0x02a698: 17ffc25e  b        #0x1b010
//   0x02a69c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02a6a0: 2a1f03e0  mov      w0, wzr
uint64_t fde_0142_sub_02a664(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02A664ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02a664: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a668: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a66c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a670: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400000ULL; // 0x02a674: ldr w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC266ULL; // 0x02a678: bl #0x1b010
    acc = (acc * 0x100000001B3ULL) ^ 0x36000100ULL; // 0x02a67c: tbz w0, #0, #0x2a69c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400660ULL; // 0x02a680: ldr w0, [x19, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC5B7ULL; // 0x02a684: bl #0x1bd60
    acc = (acc * 0x100000001B3ULL) ^ 0x360000A0ULL; // 0x02a688: tbz w0, #0, #0x2a69c
    return acc;
}

// [EN] Reconstructed FDE #0143 @ 0x02a6ac..0x02a7d4 (296 bytes)
// [VN] Phục dựng FDE #0143 tại 0x02a6ac..0x02a7d4 (296 byte)
//   0x02a6ac: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02a6b0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02a6b4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02a6b8: 910083fd  add      x29, sp, #0x20
//   0x02a6bc: b9400808  ldr      w8, [x0, #8]
//   0x02a6c0: 2a0303f3  mov      w19, w3
//   0x02a6c4: aa0203f4  mov      x20, x2
//   0x02a6c8: aa0003f5  mov      x21, x0
//   0x02a6cc: 7100111f  cmp      w8, #4
//   0x02a6d0: 54000109  b.ls     #0x2a6f0
//   0x02a6d4: 51020509  sub      w9, w8, #0x81
//   0x02a6d8: 71000d3f  cmp      w9, #3
//   0x02a6dc: 12800000  mov      w0, #-1
//   0x02a6e0: 54000448  b.hi     #0x2a768
//   0x02a6e4: 7100053f  cmp      w9, #1
//   0x02a6e8: 540000e1  b.ne     #0x2a704
uint64_t fde_0143_sub_02a6ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x12800000ULL) + (x2 ^ 0x02A6ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02a6ac: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02a6b0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02a6b4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02a6b8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400808ULL; // 0x02a6bc: ldr w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x02a6c0: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02a6c4: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02a6c8: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100111FULL; // 0x02a6cc: cmp w8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000109ULL; // 0x02a6d0: b.ls #0x2a6f0
    return acc;
}

// [EN] Reconstructed FDE #0144 @ 0x02a7d4..0x02a814 (64 bytes)
// [VN] Phục dựng FDE #0144 tại 0x02a7d4..0x02a814 (64 byte)
//   0x02a7d4: b9400808  ldr      w8, [x0, #8]
//   0x02a7d8: 52800020  mov      w0, #1
//   0x02a7dc: 7100111f  cmp      w8, #4
//   0x02a7e0: 54000109  b.ls     #0x2a800
//   0x02a7e4: 51020508  sub      w8, w8, #0x81
//   0x02a7e8: 71000d1f  cmp      w8, #3
//   0x02a7ec: 54000068  b.hi     #0x2a7f8
//   0x02a7f0: 7100051f  cmp      w8, #1
//   0x02a7f4: 540000e1  b.ne     #0x2a810
//   0x02a7f8: 2a1f03e0  mov      w0, wzr
//   0x02a7fc: d65f03c0  ret      
//   0x02a800: 1ac82009  lsl      w9, w0, w8
//   0x02a804: 5280034a  mov      w10, #0x1a
//   0x02a808: 6a0a013f  tst      w9, w10
//   0x02a80c: 54fffec0  b.eq     #0x2a7e4
//   0x02a810: d65f03c0  ret      
uint64_t fde_0144_sub_02a7d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400808ULL) + (x1 ^ 0x5280034AULL) + (x2 ^ 0x02A7D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400808ULL; // 0x02a7d4: ldr w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x02a7d8: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100111FULL; // 0x02a7dc: cmp w8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000109ULL; // 0x02a7e0: b.ls #0x2a800
    acc = (acc * 0x100000001B3ULL) ^ 0x51020508ULL; // 0x02a7e4: sub w8, w8, #0x81
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x02a7e8: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000068ULL; // 0x02a7ec: b.hi #0x2a7f8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02a7f0: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E1ULL; // 0x02a7f4: b.ne #0x2a810
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02a7f8: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0145 @ 0x02a814..0x02a844 (48 bytes)
// [VN] Phục dựng FDE #0145 tại 0x02a814..0x02a844 (48 byte)
//   0x02a814: b9400408  ldr      w8, [x0, #4]
//   0x02a818: 7100051f  cmp      w8, #1
//   0x02a81c: 54000080  b.eq     #0x2a82c
//   0x02a820: 71000d1f  cmp      w8, #3
//   0x02a824: 540000c1  b.ne     #0x2a83c
//   0x02a828: 52801028  mov      w8, #0x81
//   0x02a82c: b9400809  ldr      w9, [x0, #8]
//   0x02a830: 6b08013f  cmp      w9, w8
//   0x02a834: 1a9f17e0  cset     w0, eq
//   0x02a838: d65f03c0  ret      
//   0x02a83c: 2a1f03e0  mov      w0, wzr
//   0x02a840: d65f03c0  ret      
uint64_t fde_0145_sub_02a814(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02A814ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400408ULL; // 0x02a814: ldr w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02a818: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x02a81c: b.eq #0x2a82c
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x02a820: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x02a824: b.ne #0x2a83c
    acc = (acc * 0x100000001B3ULL) ^ 0x52801028ULL; // 0x02a828: mov w8, #0x81
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400809ULL; // 0x02a82c: ldr w9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x02a830: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x02a834: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02a838: ret 
    return acc;
}

// [EN] Reconstructed FDE #0146 @ 0x02a844..0x02a8e0 (156 bytes)
// [VN] Phục dựng FDE #0146 tại 0x02a844..0x02a8e0 (156 byte)
//   0x02a844: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02a848: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a84c: 910043fd  add      x29, sp, #0x10
//   0x02a850: b9400408  ldr      w8, [x0, #4]
//   0x02a854: 2a0103f3  mov      w19, w1
//   0x02a858: 71000d1f  cmp      w8, #3
//   0x02a85c: 540000c0  b.eq     #0x2a874
//   0x02a860: 7100051f  cmp      w8, #1
//   0x02a864: 540002e1  b.ne     #0x2a8c0
//   0x02a868: 6b03027f  cmp      w19, w3
//   0x02a86c: 1a9f17e0  cset     w0, eq
//   0x02a870: 14000019  b        #0x2a8d4
//   0x02a874: b9401008  ldr      w8, [x0, #0x10]
//   0x02a878: b9400809  ldr      w9, [x0, #8]
//   0x02a87c: aa0203e0  mov      x0, x2
//   0x02a880: 2a0303e1  mov      w1, w3
uint64_t fde_0146_sub_02a844(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB9401008ULL) + (x2 ^ 0x02A844ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02a844: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a848: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a84c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400408ULL; // 0x02a850: ldr w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x02a854: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x02a858: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x02a85c: b.eq #0x2a874
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02a860: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540002E1ULL; // 0x02a864: b.ne #0x2a8c0
    acc = (acc * 0x100000001B3ULL) ^ 0x6B03027FULL; // 0x02a868: cmp w19, w3
    return acc;
}

// [EN] Reconstructed FDE #0147 @ 0x02a8e0..0x02ac8c (940 bytes)
// [VN] Phục dựng FDE #0147 tại 0x02a8e0..0x02ac8c (940 byte)
//   0x02a8e0: d10243ff  sub      sp, sp, #0x90
//   0x02a8e4: f90023f9  str      x25, [sp, #0x40]
//   0x02a8e8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02a8ec: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02a8f0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02a8f4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02a8f8: 910203fd  add      x29, sp, #0x80
//   0x02a8fc: d53bd059  mrs      x25, tpidr_el0
//   0x02a900: f9401728  ldr      x8, [x25, #0x28]
//   0x02a904: aa0203f5  mov      x21, x2
//   0x02a908: aa0003f3  mov      x19, x0
//   0x02a90c: aa0103f6  mov      x22, x1
//   0x02a910: f9001fe8  str      x8, [sp, #0x38]
//   0x02a914: b9400808  ldr      w8, [x0, #8]
//   0x02a918: 7100111f  cmp      w8, #4
//   0x02a91c: 54000109  b.ls     #0x2a93c
uint64_t fde_0147_sub_02a8e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x02A8E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02a8e0: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x02a8e4: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02a8e8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02a8ec: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02a8f0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02a8f4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02a8f8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02a8fc: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x02a900: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02a904: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0148 @ 0x02ac8c..0x02accc (64 bytes)
// [VN] Phục dựng FDE #0148 tại 0x02ac8c..0x02accc (64 byte)
//   0x02ac8c: b9400408  ldr      w8, [x0, #4]
//   0x02ac90: 51000508  sub      w8, w8, #1
//   0x02ac94: 71001d1f  cmp      w8, #7
//   0x02ac98: 54000088  b.hi     #0x2aca8
//   0x02ac9c: 52801fa9  mov      w9, #0xfd
//   0x02aca0: 1ac82529  lsr      w9, w9, w8
//   0x02aca4: 37000069  tbnz     w9, #0, #0x2acb0
//   0x02aca8: 2a1f03e0  mov      w0, wzr
//   0x02acac: d65f03c0  ret      
//   0x02acb0: 90000149  adrp     x9, #0x52000
//   0x02acb4: 913b8129  add      x9, x9, #0xee0
//   0x02acb8: b868d928  ldr      w8, [x9, w8, sxtw #2]
//   0x02acbc: b9400809  ldr      w9, [x0, #8]
//   0x02acc0: 6b08013f  cmp      w9, w8
//   0x02acc4: 1a9f17e0  cset     w0, eq
//   0x02acc8: d65f03c0  ret      
uint64_t fde_0148_sub_02ac8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400408ULL) + (x1 ^ 0xB9400809ULL) + (x2 ^ 0x02AC8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400408ULL; // 0x02ac8c: ldr w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x02ac90: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D1FULL; // 0x02ac94: cmp w8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x02ac98: b.hi #0x2aca8
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FA9ULL; // 0x02ac9c: mov w9, #0xfd
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC82529ULL; // 0x02aca0: lsr w9, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x37000069ULL; // 0x02aca4: tbnz w9, #0, #0x2acb0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02aca8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02acac: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x90000149ULL; // 0x02acb0: adrp x9, #0x52000
    return acc;
}

// [EN] Reconstructed FDE #0149 @ 0x02accc..0x02aef8 (556 bytes)
// [VN] Phục dựng FDE #0149 tại 0x02accc..0x02aef8 (556 byte)
//   0x02accc: d10303ff  sub      sp, sp, #0xc0
//   0x02acd0: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x02acd4: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x02acd8: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x02acdc: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x02ace0: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x02ace4: 9102c3fd  add      x29, sp, #0xb0
//   0x02ace8: d53bd05a  mrs      x26, tpidr_el0
//   0x02acec: f9401748  ldr      x8, [x26, #0x28]
//   0x02acf0: 528001d6  mov      w22, #0xe
//   0x02acf4: f81b83a8  stur     x8, [x29, #-0x48]
//   0x02acf8: b4000a81  cbz      x1, #0x2ae48
//   0x02acfc: aa0203f4  mov      x20, x2
//   0x02ad00: b4000a42  cbz      x2, #0x2ae48
//   0x02ad04: aa0003f5  mov      x21, x0
//   0x02ad08: 9100e3e0  add      x0, sp, #0x38
uint64_t fde_0149_sub_02accc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x02ACCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x02accc: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x02acd0: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x02acd4: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x02acd8: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x02acdc: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x02ace0: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x02ace4: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x02ace8: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x02acec: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x528001D6ULL; // 0x02acf0: mov w22, #0xe
    return acc;
}

// [EN] Reconstructed FDE #0150 @ 0x02aef8..0x02affc (260 bytes)
// [VN] Phục dựng FDE #0150 tại 0x02aef8..0x02affc (260 byte)
//   0x02aef8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02aefc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02af00: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02af04: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02af08: 9100c3fd  add      x29, sp, #0x30
//   0x02af0c: a9000000  stp      x0, x0, [x0]
//   0x02af10: f900081f  str      xzr, [x0, #0x10]
//   0x02af14: b40002c2  cbz      x2, #0x2af6c
//   0x02af18: 8b020448  add      x8, x2, x2, lsl #1
//   0x02af1c: aa0103f4  mov      x20, x1
//   0x02af20: aa0003f3  mov      x19, x0
//   0x02af24: aa1f03f7  mov      x23, xzr
//   0x02af28: d37df116  lsl      x22, x8, #3
//   0x02af2c: 52800500  mov      w0, #0x28
//   0x02af30: 97ffc34c  bl       #0x1bc60
//   0x02af34: aa0003f5  mov      x21, x0
uint64_t fde_0150_sub_02aef8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xD37DF116ULL) + (x2 ^ 0x02AEF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02aef8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02aefc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02af00: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02af04: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02af08: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000000ULL; // 0x02af0c: stp x0, x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x02af10: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002C2ULL; // 0x02af14: cbz x2, #0x2af6c
    acc = (acc * 0x100000001B3ULL) ^ 0x8B020448ULL; // 0x02af18: add x8, x2, x2, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02af1c: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0151 @ 0x02affc..0x02bc58 (3164 bytes)
// [VN] Phục dựng FDE #0151 tại 0x02affc..0x02bc58 (3164 byte)
//   0x02affc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02b000: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02b004: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02b008: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02b00c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02b010: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02b014: 910143fd  add      x29, sp, #0x50
//   0x02b018: d10bc3ff  sub      sp, sp, #0x2f0
//   0x02b01c: d53bd05b  mrs      x27, tpidr_el0
//   0x02b020: f9401768  ldr      x8, [x27, #0x28]
//   0x02b024: aa0103f3  mov      x19, x1
//   0x02b028: aa0003e1  mov      x1, x0
//   0x02b02c: 910203e0  add      x0, sp, #0x80
//   0x02b030: f81983a8  stur     x8, [x29, #-0x68]
//   0x02b034: 97ffc2d7  bl       #0x1bb90
//   0x02b038: 910183e0  add      x0, sp, #0x60
uint64_t fde_0151_sub_02affc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x910203E0ULL) + (x2 ^ 0x02AFFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02affc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02b000: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02b004: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02b008: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02b00c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02b010: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02b014: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10BC3FFULL; // 0x02b018: sub sp, sp, #0x2f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x02b01c: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x02b020: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0152 @ 0x02bc58..0x02be94 (572 bytes)
// [VN] Phục dựng FDE #0152 tại 0x02bc58..0x02be94 (572 byte)
//   0x02bc58: d10343ff  sub      sp, sp, #0xd0
//   0x02bc5c: f90043f9  str      x25, [sp, #0x80]
//   0x02bc60: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x02bc64: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x02bc68: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x02bc6c: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x02bc70: 910303fd  add      x29, sp, #0xc0
//   0x02bc74: d53bd059  mrs      x25, tpidr_el0
//   0x02bc78: f9401728  ldr      x8, [x25, #0x28]
//   0x02bc7c: aa0203f6  mov      x22, x2
//   0x02bc80: aa0103f3  mov      x19, x1
//   0x02bc84: aa0003f4  mov      x20, x0
//   0x02bc88: 2a0303f5  mov      w21, w3
//   0x02bc8c: 71005c7f  cmp      w3, #0x17
//   0x02bc90: f81b83a8  stur     x8, [x29, #-0x48]
//   0x02bc94: a906ffff  stp      xzr, xzr, [sp, #0x68]
uint64_t fde_0152_sub_02bc58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x2A0303F5ULL) + (x2 ^ 0x02BC58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x02bc58: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90043F9ULL; // 0x02bc5c: str x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x02bc60: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x02bc64: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x02bc68: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x02bc6c: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x02bc70: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02bc74: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x02bc78: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x02bc7c: mov x22, x2
    return acc;
}

// [EN] Reconstructed FDE #0153 @ 0x02be94..0x02bf84 (240 bytes)
// [VN] Phục dựng FDE #0153 tại 0x02be94..0x02bf84 (240 byte)
//   0x02be94: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02be98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02be9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bea0: 910083fd  add      x29, sp, #0x20
//   0x02bea4: 2a0203f5  mov      w21, w2
//   0x02bea8: aa0103f4  mov      x20, x1
//   0x02beac: aa0003f3  mov      x19, x0
//   0x02beb0: 97ffbfc0  bl       #0x1bdb0
//   0x02beb4: 900001e1  adrp     x1, #0x67000
//   0x02beb8: f9468c21  ldr      x1, [x1, #0xd18]
//   0x02bebc: aa1303e0  mov      x0, x19
//   0x02bec0: 97ffc04c  bl       #0x1bff0
//   0x02bec4: f9000660  str      x0, [x19, #8]
//   0x02bec8: 900001e1  adrp     x1, #0x67000
//   0x02becc: f9474821  ldr      x1, [x1, #0xe90]
//   0x02bed0: aa1303e0  mov      x0, x19
uint64_t fde_0153_sub_02be94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9000660ULL) + (x2 ^ 0x02BE94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02be94: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02be98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02be9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bea0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x02bea4: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02bea8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02beac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFBFC0ULL; // 0x02beb0: bl #0x1bdb0
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E1ULL; // 0x02beb4: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468C21ULL; // 0x02beb8: ldr x1, [x1, #0xd18]
    return acc;
}

// [EN] Reconstructed FDE #0154 @ 0x02bf84..0x02c10c (392 bytes)
// [VN] Phục dựng FDE #0154 tại 0x02bf84..0x02c10c (392 byte)
//   0x02bf84: d104c3ff  sub      sp, sp, #0x130
//   0x02bf88: a90f5ffc  stp      x28, x23, [sp, #0xf0]
//   0x02bf8c: a91057f6  stp      x22, x21, [sp, #0x100]
//   0x02bf90: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x02bf94: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x02bf98: 910483fd  add      x29, sp, #0x120
//   0x02bf9c: d53bd057  mrs      x23, tpidr_el0
//   0x02bfa0: f94016e8  ldr      x8, [x23, #0x28]
//   0x02bfa4: 52820809  mov      w9, #0x1040
//   0x02bfa8: 2a090044  orr      w4, w2, w9
//   0x02bfac: 2a0203f3  mov      w19, w2
//   0x02bfb0: f81c83a8  stur     x8, [x29, #-0x38]
//   0x02bfb4: 39400008  ldrb     w8, [x0]
//   0x02bfb8: a940a809  ldp      x9, x10, [x0, #8]
//   0x02bfbc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02bfc0: a9037fff  stp      xzr, xzr, [sp, #0x30]
uint64_t fde_0154_sub_02bf84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0x39400008ULL) + (x2 ^ 0x02BF84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x02bf84: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F5FFCULL; // 0x02bf88: stp x28, x23, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057F6ULL; // 0x02bf8c: stp x22, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x02bf90: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x02bf94: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x02bf98: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02bf9c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02bfa0: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52820809ULL; // 0x02bfa4: mov w9, #0x1040
    acc = (acc * 0x100000001B3ULL) ^ 0x2A090044ULL; // 0x02bfa8: orr w4, w2, w9
    return acc;
}

// [EN] Reconstructed FDE #0155 @ 0x02c10c..0x02c22c (288 bytes)
// [VN] Phục dựng FDE #0155 tại 0x02c10c..0x02c22c (288 byte)
//   0x02c10c: d101c3ff  sub      sp, sp, #0x70
//   0x02c110: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02c114: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02c118: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02c11c: 910183fd  add      x29, sp, #0x60
//   0x02c120: d53bd056  mrs      x22, tpidr_el0
//   0x02c124: aa0803f3  mov      x19, x8
//   0x02c128: f94016c8  ldr      x8, [x22, #0x28]
//   0x02c12c: aa0003f5  mov      x21, x0
//   0x02c130: aa1303e0  mov      x0, x19
//   0x02c134: aa0103f4  mov      x20, x1
//   0x02c138: f81d83a8  stur     x8, [x29, #-0x28]
//   0x02c13c: 97ffbaa5  bl       #0x1abd0
//   0x02c140: 394032a8  ldrb     w8, [x21, #0xc]
//   0x02c144: 361003a8  tbz      w8, #2, #0x2c1b8
//   0x02c148: 910023e0  add      x0, sp, #8
uint64_t fde_0155_sub_02c10c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x97FFBAA5ULL) + (x2 ^ 0x02C10CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02c10c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02c110: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02c114: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02c118: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02c11c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02c120: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x02c124: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02c128: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02c12c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c130: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0156 @ 0x02c22c..0x02c330 (260 bytes)
// [VN] Phục dựng FDE #0156 tại 0x02c22c..0x02c330 (260 byte)
//   0x02c22c: d101c3ff  sub      sp, sp, #0x70
//   0x02c230: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02c234: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02c238: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02c23c: 910183fd  add      x29, sp, #0x60
//   0x02c240: d53bd055  mrs      x21, tpidr_el0
//   0x02c244: f94016a8  ldr      x8, [x21, #0x28]
//   0x02c248: f81d83a8  stur     x8, [x29, #-0x28]
//   0x02c24c: 39403008  ldrb     w8, [x0, #0xc]
//   0x02c250: 361004e8  tbz      w8, #2, #0x2c2ec
//   0x02c254: f9400436  ldr      x22, [x1, #8]
//   0x02c258: aa0103f3  mov      x19, x1
//   0x02c25c: eb16027f  cmp      x19, x22
//   0x02c260: 540000a1  b.ne     #0x2c274
//   0x02c264: 14000022  b        #0x2c2ec
//   0x02c268: f94006d6  ldr      x22, [x22, #8]
uint64_t fde_0156_sub_02c22c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xEB16027FULL) + (x2 ^ 0x02C22CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02c22c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02c230: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02c234: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02c238: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02c23c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02c240: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02c244: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x02c248: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x39403008ULL; // 0x02c24c: ldrb w8, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x361004E8ULL; // 0x02c250: tbz w8, #2, #0x2c2ec
    return acc;
}

// [EN] Reconstructed FDE #0157 @ 0x02c330..0x02c3a8 (120 bytes)
// [VN] Phục dựng FDE #0157 tại 0x02c330..0x02c3a8 (120 byte)
//   0x02c330: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c334: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c338: 910043fd  add      x29, sp, #0x10
//   0x02c33c: f00001c8  adrp     x8, #0x67000
//   0x02c340: f9475108  ldr      x8, [x8, #0xea0]
//   0x02c344: aa0003f4  mov      x20, x0
//   0x02c348: aa0003f3  mov      x19, x0
//   0x02c34c: 91006109  add      x9, x8, #0x18
//   0x02c350: 9101a10a  add      x10, x8, #0x68
//   0x02c354: f81f0e89  str      x9, [x20, #-0x10]!
//   0x02c358: f8070e6a  str      x10, [x19, #0x70]!
//   0x02c35c: f00001ca  adrp     x10, #0x67000
//   0x02c360: 39412009  ldrb     w9, [x0, #0x48]
//   0x02c364: f947354a  ldr      x10, [x10, #0xe68]
//   0x02c368: 91010108  add      x8, x8, #0x40
//   0x02c36c: 9100414a  add      x10, x10, #0x10
uint64_t fde_0157_sub_02c330(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x39412009ULL) + (x2 ^ 0x02C330ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c330: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c334: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c338: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x02c33c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475108ULL; // 0x02c340: ldr x8, [x8, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02c344: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c348: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91006109ULL; // 0x02c34c: add x9, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9101A10AULL; // 0x02c350: add x10, x8, #0x68
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0E89ULL; // 0x02c354: str x9, [x20, #-0x10]!
    return acc;
}

// [EN] Reconstructed FDE #0158 @ 0x02c3a8..0x02c428 (128 bytes)
// [VN] Phục dựng FDE #0158 tại 0x02c3a8..0x02c428 (128 byte)
//   0x02c3a8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c3ac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c3b0: 910043fd  add      x29, sp, #0x10
//   0x02c3b4: f9400008  ldr      x8, [x0]
//   0x02c3b8: f00001c9  adrp     x9, #0x67000
//   0x02c3bc: f85e8108  ldur     x8, [x8, #-0x18]
//   0x02c3c0: f9475129  ldr      x9, [x9, #0xea0]
//   0x02c3c4: 8b080014  add      x20, x0, x8
//   0x02c3c8: 9100612a  add      x10, x9, #0x18
//   0x02c3cc: 9101a12b  add      x11, x9, #0x68
//   0x02c3d0: aa1403f3  mov      x19, x20
//   0x02c3d4: f900028a  str      x10, [x20]
//   0x02c3d8: f8080e6b  str      x11, [x19, #0x80]!
//   0x02c3dc: f00001ca  adrp     x10, #0x67000
//   0x02c3e0: 91010128  add      x8, x9, #0x40
//   0x02c3e4: 39416289  ldrb     w9, [x20, #0x58]
uint64_t fde_0158_sub_02c3a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF8080E6BULL) + (x2 ^ 0x02C3A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c3a8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c3ac: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c3b0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c3b4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C9ULL; // 0x02c3b8: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x02c3bc: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475129ULL; // 0x02c3c0: ldr x9, [x9, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080014ULL; // 0x02c3c4: add x20, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9100612AULL; // 0x02c3c8: add x10, x9, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9101A12BULL; // 0x02c3cc: add x11, x9, #0x68
    return acc;
}

// [EN] Reconstructed FDE #0159 @ 0x02c428..0x02c430 (8 bytes)
// [VN] Phục dựng FDE #0159 tại 0x02c428..0x02c430 (8 byte)
//   0x02c428: 91004000  add      x0, x0, #0x10
//   0x02c42c: 17ffb9cd  b        #0x1ab60
uint64_t fde_0159_sub_02c428(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91004000ULL) + (x1 ^ 0x17FFB9CDULL) + (x2 ^ 0x02C428ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x02c428: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB9CDULL; // 0x02c42c: b #0x1ab60
    return acc;
}

// [EN] Reconstructed FDE #0160 @ 0x02c430..0x02c458 (40 bytes)
// [VN] Phục dựng FDE #0160 tại 0x02c430..0x02c458 (40 byte)
//   0x02c430: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c434: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c438: 910043fd  add      x29, sp, #0x10
//   0x02c43c: aa0003f3  mov      x19, x0
//   0x02c440: 91004000  add      x0, x0, #0x10
//   0x02c444: 97ffb9c7  bl       #0x1ab60
//   0x02c448: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02c44c: aa1303e0  mov      x0, x19
//   0x02c450: f84207f3  ldr      x19, [sp], #0x20
//   0x02c454: 17ffb98b  b        #0x1aa80
uint64_t fde_0160_sub_02c430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFB98BULL) + (x2 ^ 0x02C430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c430: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c434: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c438: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c43c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x02c440: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB9C7ULL; // 0x02c444: bl #0x1ab60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02c448: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c44c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x02c450: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB98BULL; // 0x02c454: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0161 @ 0x02c458..0x02c46c (20 bytes)
// [VN] Phục dựng FDE #0161 tại 0x02c458..0x02c46c (20 byte)
//   0x02c458: f9400008  ldr      x8, [x0]
//   0x02c45c: f85e8108  ldur     x8, [x8, #-0x18]
//   0x02c460: 8b080008  add      x8, x0, x8
//   0x02c464: 91004100  add      x0, x8, #0x10
//   0x02c468: 17ffb9be  b        #0x1ab60
uint64_t fde_0161_sub_02c458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x17FFB9BEULL) + (x2 ^ 0x02C458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c458: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x02c45c: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x02c460: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004100ULL; // 0x02c464: add x0, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB9BEULL; // 0x02c468: b #0x1ab60
    return acc;
}

// [EN] Reconstructed FDE #0162 @ 0x02c46c..0x02c49c (48 bytes)
// [VN] Phục dựng FDE #0162 tại 0x02c46c..0x02c49c (48 byte)
//   0x02c46c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c470: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c474: 910043fd  add      x29, sp, #0x10
//   0x02c478: f9400008  ldr      x8, [x0]
//   0x02c47c: f85e8108  ldur     x8, [x8, #-0x18]
//   0x02c480: 8b080013  add      x19, x0, x8
//   0x02c484: 91004260  add      x0, x19, #0x10
//   0x02c488: 97ffb9b6  bl       #0x1ab60
//   0x02c48c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02c490: aa1303e0  mov      x0, x19
//   0x02c494: f84207f3  ldr      x19, [sp], #0x20
//   0x02c498: 17ffb97a  b        #0x1aa80
uint64_t fde_0162_sub_02c46c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFB97AULL) + (x2 ^ 0x02C46CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c46c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c470: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c474: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c478: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x02c47c: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x02c480: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004260ULL; // 0x02c484: add x0, x19, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB9B6ULL; // 0x02c488: bl #0x1ab60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02c48c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c490: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0163 @ 0x02c49c..0x02c518 (124 bytes)
// [VN] Phục dựng FDE #0163 tại 0x02c49c..0x02c518 (124 byte)
//   0x02c49c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c4a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c4a4: 910043fd  add      x29, sp, #0x10
//   0x02c4a8: f00001c8  adrp     x8, #0x67000
//   0x02c4ac: f00001c9  adrp     x9, #0x67000
//   0x02c4b0: f9475108  ldr      x8, [x8, #0xea0]
//   0x02c4b4: f9473529  ldr      x9, [x9, #0xe68]
//   0x02c4b8: 3941600a  ldrb     w10, [x0, #0x58]
//   0x02c4bc: aa0003f3  mov      x19, x0
//   0x02c4c0: 9100610b  add      x11, x8, #0x18
//   0x02c4c4: 9101a10c  add      x12, x8, #0x68
//   0x02c4c8: 91010108  add      x8, x8, #0x40
//   0x02c4cc: 91004129  add      x9, x9, #0x10
//   0x02c4d0: f900000b  str      x11, [x0]
//   0x02c4d4: f900400c  str      x12, [x0, #0x80]
//   0x02c4d8: a9012408  stp      x8, x9, [x0, #0x10]
uint64_t fde_0163_sub_02c49c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004129ULL) + (x2 ^ 0x02C49CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c49c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c4a0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c4a4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x02c4a8: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C9ULL; // 0x02c4ac: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475108ULL; // 0x02c4b0: ldr x8, [x8, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473529ULL; // 0x02c4b4: ldr x9, [x9, #0xe68]
    acc = (acc * 0x100000001B3ULL) ^ 0x3941600AULL; // 0x02c4b8: ldrb w10, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c4bc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9100610BULL; // 0x02c4c0: add x11, x8, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0164 @ 0x02c518..0x02c598 (128 bytes)
// [VN] Phục dựng FDE #0164 tại 0x02c518..0x02c598 (128 byte)
//   0x02c518: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c51c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c520: 910043fd  add      x29, sp, #0x10
//   0x02c524: f00001c8  adrp     x8, #0x67000
//   0x02c528: f9475108  ldr      x8, [x8, #0xea0]
//   0x02c52c: aa0003f3  mov      x19, x0
//   0x02c530: aa0003f4  mov      x20, x0
//   0x02c534: 91006109  add      x9, x8, #0x18
//   0x02c538: 9101a10a  add      x10, x8, #0x68
//   0x02c53c: f81f0e69  str      x9, [x19, #-0x10]!
//   0x02c540: f8070e8a  str      x10, [x20, #0x70]!
//   0x02c544: f00001ca  adrp     x10, #0x67000
//   0x02c548: 39412009  ldrb     w9, [x0, #0x48]
//   0x02c54c: f947354a  ldr      x10, [x10, #0xe68]
//   0x02c550: 91010108  add      x8, x8, #0x40
//   0x02c554: 9100414a  add      x10, x10, #0x10
uint64_t fde_0164_sub_02c518(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x39412009ULL) + (x2 ^ 0x02C518ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c518: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c51c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c520: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x02c524: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475108ULL; // 0x02c528: ldr x8, [x8, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c52c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02c530: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91006109ULL; // 0x02c534: add x9, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9101A10AULL; // 0x02c538: add x10, x8, #0x68
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0E69ULL; // 0x02c53c: str x9, [x19, #-0x10]!
    return acc;
}

// [EN] Reconstructed FDE #0165 @ 0x02c598..0x02c620 (136 bytes)
// [VN] Phục dựng FDE #0165 tại 0x02c598..0x02c620 (136 byte)
//   0x02c598: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c59c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c5a0: 910043fd  add      x29, sp, #0x10
//   0x02c5a4: f9400008  ldr      x8, [x0]
//   0x02c5a8: f00001c9  adrp     x9, #0x67000
//   0x02c5ac: f85e8108  ldur     x8, [x8, #-0x18]
//   0x02c5b0: f9475129  ldr      x9, [x9, #0xea0]
//   0x02c5b4: 8b080013  add      x19, x0, x8
//   0x02c5b8: 9100612a  add      x10, x9, #0x18
//   0x02c5bc: 9101a12b  add      x11, x9, #0x68
//   0x02c5c0: aa1303f4  mov      x20, x19
//   0x02c5c4: f900026a  str      x10, [x19]
//   0x02c5c8: f8080e8b  str      x11, [x20, #0x80]!
//   0x02c5cc: f00001ca  adrp     x10, #0x67000
//   0x02c5d0: 91010128  add      x8, x9, #0x40
//   0x02c5d4: 39416269  ldrb     w9, [x19, #0x58]
uint64_t fde_0165_sub_02c598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF8080E8BULL) + (x2 ^ 0x02C598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c598: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c59c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c5a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c5a4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C9ULL; // 0x02c5a8: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x02c5ac: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475129ULL; // 0x02c5b0: ldr x9, [x9, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x02c5b4: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9100612AULL; // 0x02c5b8: add x10, x9, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9101A12BULL; // 0x02c5bc: add x11, x9, #0x68
    return acc;
}

// [EN] Reconstructed FDE #0166 @ 0x02c620..0x02c670 (80 bytes)
// [VN] Phục dựng FDE #0166 tại 0x02c620..0x02c670 (80 byte)
//   0x02c620: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c624: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c628: 910043fd  add      x29, sp, #0x10
//   0x02c62c: f00001c9  adrp     x9, #0x67000
//   0x02c630: 39410008  ldrb     w8, [x0, #0x40]
//   0x02c634: f9473529  ldr      x9, [x9, #0xe68]
//   0x02c638: aa0003f3  mov      x19, x0
//   0x02c63c: 91004129  add      x9, x9, #0x10
//   0x02c640: f9000009  str      x9, [x0]
//   0x02c644: 36000068  tbz      w8, #0, #0x2c650
//   0x02c648: f9402a60  ldr      x0, [x19, #0x50]
//   0x02c64c: 97ffb90d  bl       #0x1aa80
//   0x02c650: f00001c8  adrp     x8, #0x67000
//   0x02c654: f946c908  ldr      x8, [x8, #0xd90]
//   0x02c658: 91004108  add      x8, x8, #0x10
//   0x02c65c: f8008668  str      x8, [x19], #8
uint64_t fde_0166_sub_02c620(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF00001C8ULL) + (x2 ^ 0x02C620ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c620: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c624: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c628: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C9ULL; // 0x02c62c: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x39410008ULL; // 0x02c630: ldrb w8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473529ULL; // 0x02c634: ldr x9, [x9, #0xe68]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c638: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004129ULL; // 0x02c63c: add x9, x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x02c640: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000068ULL; // 0x02c644: tbz w8, #0, #0x2c650
    return acc;
}

// [EN] Reconstructed FDE #0167 @ 0x02c670..0x02c6c8 (88 bytes)
// [VN] Phục dựng FDE #0167 tại 0x02c670..0x02c6c8 (88 byte)
//   0x02c670: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c674: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c678: 910043fd  add      x29, sp, #0x10
//   0x02c67c: f00001c9  adrp     x9, #0x67000
//   0x02c680: 39410008  ldrb     w8, [x0, #0x40]
//   0x02c684: f9473529  ldr      x9, [x9, #0xe68]
//   0x02c688: aa0003f3  mov      x19, x0
//   0x02c68c: 91004129  add      x9, x9, #0x10
//   0x02c690: f9000009  str      x9, [x0]
//   0x02c694: 36000068  tbz      w8, #0, #0x2c6a0
//   0x02c698: f9402a60  ldr      x0, [x19, #0x50]
//   0x02c69c: 97ffb8f9  bl       #0x1aa80
//   0x02c6a0: f00001c8  adrp     x8, #0x67000
//   0x02c6a4: f946c908  ldr      x8, [x8, #0xd90]
//   0x02c6a8: aa1303e0  mov      x0, x19
//   0x02c6ac: 91004108  add      x8, x8, #0x10
uint64_t fde_0167_sub_02c670(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF00001C8ULL) + (x2 ^ 0x02C670ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c670: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c674: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c678: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C9ULL; // 0x02c67c: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x39410008ULL; // 0x02c680: ldrb w8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473529ULL; // 0x02c684: ldr x9, [x9, #0xe68]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c688: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004129ULL; // 0x02c68c: add x9, x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x02c690: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000068ULL; // 0x02c694: tbz w8, #0, #0x2c6a0
    return acc;
}

// [EN] Reconstructed FDE #0168 @ 0x02c6c8..0x02c6cc (4 bytes)
// [VN] Phục dựng FDE #0168 tại 0x02c6c8..0x02c6cc (4 byte)
//   0x02c6c8: d65f03c0  ret      
uint64_t fde_0168_sub_02c6c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C6C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c6c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0169 @ 0x02c6cc..0x02c6d0 (4 bytes)
// [VN] Phục dựng FDE #0169 tại 0x02c6cc..0x02c6d0 (4 byte)
//   0x02c6cc: d65f03c0  ret      
uint64_t fde_0169_sub_02c6cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C6CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c6cc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0170 @ 0x02c6d0..0x02c7d0 (256 bytes)
// [VN] Phục dựng FDE #0170 tại 0x02c6d0..0x02c7d0 (256 byte)
//   0x02c6d0: f9402c08  ldr      x8, [x0, #0x58]
//   0x02c6d4: f9401809  ldr      x9, [x0, #0x30]
//   0x02c6d8: eb09011f  cmp      x8, x9
//   0x02c6dc: 54000062  b.hs     #0x2c6e8
//   0x02c6e0: aa0903e8  mov      x8, x9
//   0x02c6e4: f9002c09  str      x9, [x0, #0x58]
//   0x02c6e8: 721d046a  ands     w10, w3, #0x18
//   0x02c6ec: 540000a0  b.eq     #0x2c700
//   0x02c6f0: 7100045f  cmp      w2, #1
//   0x02c6f4: 540000c1  b.ne     #0x2c70c
//   0x02c6f8: 7100615f  cmp      w10, #0x18
//   0x02c6fc: 54000081  b.ne     #0x2c70c
//   0x02c700: 92800001  mov      x1, #-1
//   0x02c704: aa1f03e0  mov      x0, xzr
//   0x02c708: d65f03c0  ret      
//   0x02c70c: b4000128  cbz      x8, #0x2c730
uint64_t fde_0170_sub_02c6d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C08ULL) + (x1 ^ 0x92800001ULL) + (x2 ^ 0x02C6D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C08ULL; // 0x02c6d0: ldr x8, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401809ULL; // 0x02c6d4: ldr x9, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02c6d8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02c6dc: b.hs #0x2c6e8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E8ULL; // 0x02c6e0: mov x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002C09ULL; // 0x02c6e4: str x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x721D046AULL; // 0x02c6e8: ands w10, w3, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02c6ec: b.eq #0x2c700
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x02c6f0: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x02c6f4: b.ne #0x2c70c
    return acc;
}

// [EN] Reconstructed FDE #0171 @ 0x02c7d0..0x02c7e4 (20 bytes)
// [VN] Phục dựng FDE #0171 tại 0x02c7d0..0x02c7e4 (20 byte)
//   0x02c7d0: f9400008  ldr      x8, [x0]
//   0x02c7d4: aa0203e1  mov      x1, x2
//   0x02c7d8: 2a1f03e2  mov      w2, wzr
//   0x02c7dc: f9401104  ldr      x4, [x8, #0x20]
//   0x02c7e0: d61f0080  br       x4
uint64_t fde_0171_sub_02c7d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x02C7D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c7d0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x02c7d4: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x02c7d8: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401104ULL; // 0x02c7dc: ldr x4, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0080ULL; // 0x02c7e0: br x4
    return acc;
}

// [EN] Reconstructed FDE #0172 @ 0x02c7e4..0x02c7ec (8 bytes)
// [VN] Phục dựng FDE #0172 tại 0x02c7e4..0x02c7ec (8 byte)
//   0x02c7e4: 2a1f03e0  mov      w0, wzr
//   0x02c7e8: d65f03c0  ret      
uint64_t fde_0172_sub_02c7e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C7E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02c7e4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c7e8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0173 @ 0x02c7ec..0x02c7f4 (8 bytes)
// [VN] Phục dựng FDE #0173 tại 0x02c7ec..0x02c7f4 (8 byte)
//   0x02c7ec: aa1f03e0  mov      x0, xzr
//   0x02c7f0: d65f03c0  ret      
uint64_t fde_0173_sub_02c7ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C7ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x02c7ec: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c7f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0174 @ 0x02c7f4..0x02c8bc (200 bytes)
// [VN] Phục dựng FDE #0174 tại 0x02c7f4..0x02c8bc (200 byte)
//   0x02c7f4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02c7f8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02c7fc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c800: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c804: 9100c3fd  add      x29, sp, #0x30
//   0x02c808: f100045f  cmp      x2, #1
//   0x02c80c: 540004ab  b.lt     #0x2c8a0
//   0x02c810: aa0203f4  mov      x20, x2
//   0x02c814: aa0103f5  mov      x21, x1
//   0x02c818: aa0003f6  mov      x22, x0
//   0x02c81c: aa1f03f3  mov      x19, xzr
//   0x02c820: 12b00018  mov      w24, #0x7fffffff
//   0x02c824: 14000008  b        #0x2c844
//   0x02c828: f9400ec8  ldr      x8, [x22, #0x18]
//   0x02c82c: 8b1702b5  add      x21, x21, x23
//   0x02c830: 8b37c108  add      x8, x8, w23, sxtw
uint64_t fde_0174_sub_02c7f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x14000008ULL) + (x2 ^ 0x02C7F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02c7f4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02c7f8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c7fc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c800: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c804: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x02c808: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540004ABULL; // 0x02c80c: b.lt #0x2c8a0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02c810: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02c814: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02c818: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0175 @ 0x02c8bc..0x02c90c (80 bytes)
// [VN] Phục dựng FDE #0175 tại 0x02c8bc..0x02c90c (80 byte)
//   0x02c8bc: f9402c08  ldr      x8, [x0, #0x58]
//   0x02c8c0: f9401809  ldr      x9, [x0, #0x30]
//   0x02c8c4: eb09011f  cmp      x8, x9
//   0x02c8c8: 54000062  b.hs     #0x2c8d4
//   0x02c8cc: aa0903e8  mov      x8, x9
//   0x02c8d0: f9002c09  str      x9, [x0, #0x58]
//   0x02c8d4: 39418009  ldrb     w9, [x0, #0x60]
//   0x02c8d8: 36180169  tbz      w9, #3, #0x2c904
//   0x02c8dc: f9401009  ldr      x9, [x0, #0x20]
//   0x02c8e0: eb08013f  cmp      x9, x8
//   0x02c8e4: 54000062  b.hs     #0x2c8f0
//   0x02c8e8: aa0803e9  mov      x9, x8
//   0x02c8ec: f9001008  str      x8, [x0, #0x20]
//   0x02c8f0: f9400c08  ldr      x8, [x0, #0x18]
//   0x02c8f4: eb09011f  cmp      x8, x9
//   0x02c8f8: 54000062  b.hs     #0x2c904
uint64_t fde_0175_sub_02c8bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C08ULL) + (x1 ^ 0xF9001008ULL) + (x2 ^ 0x02C8BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C08ULL; // 0x02c8bc: ldr x8, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401809ULL; // 0x02c8c0: ldr x9, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02c8c4: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02c8c8: b.hs #0x2c8d4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E8ULL; // 0x02c8cc: mov x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002C09ULL; // 0x02c8d0: str x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x39418009ULL; // 0x02c8d4: ldrb w9, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x36180169ULL; // 0x02c8d8: tbz w9, #3, #0x2c904
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401009ULL; // 0x02c8dc: ldr x9, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x02c8e0: cmp x9, x8
    return acc;
}

// [EN] Reconstructed FDE #0176 @ 0x02c90c..0x02c94c (64 bytes)
// [VN] Phục dựng FDE #0176 tại 0x02c90c..0x02c94c (64 byte)
//   0x02c90c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c910: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c914: 910043fd  add      x29, sp, #0x10
//   0x02c918: f9400008  ldr      x8, [x0]
//   0x02c91c: aa0003f3  mov      x19, x0
//   0x02c920: f9402508  ldr      x8, [x8, #0x48]
//   0x02c924: d63f0100  blr      x8
//   0x02c928: 3100041f  cmn      w0, #1
//   0x02c92c: 540000a0  b.eq     #0x2c940
//   0x02c930: f9400e68  ldr      x8, [x19, #0x18]
//   0x02c934: 91000509  add      x9, x8, #1
//   0x02c938: f9000e69  str      x9, [x19, #0x18]
//   0x02c93c: 39400100  ldrb     w0, [x8]
//   0x02c940: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02c944: f84207f3  ldr      x19, [sp], #0x20
//   0x02c948: d65f03c0  ret      
uint64_t fde_0176_sub_02c90c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x39400100ULL) + (x2 ^ 0x02C90CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c90c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c910: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c914: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c918: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c91c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402508ULL; // 0x02c920: ldr x8, [x8, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x02c924: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x02c928: cmn w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02c92c: b.eq #0x2c940
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400E68ULL; // 0x02c930: ldr x8, [x19, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0177 @ 0x02c94c..0x02c9bc (112 bytes)
// [VN] Phục dựng FDE #0177 tại 0x02c94c..0x02c9bc (112 byte)
//   0x02c94c: f9402c09  ldr      x9, [x0, #0x58]
//   0x02c950: f940180a  ldr      x10, [x0, #0x30]
//   0x02c954: aa0003e8  mov      x8, x0
//   0x02c958: 2a0103e0  mov      w0, w1
//   0x02c95c: eb0a013f  cmp      x9, x10
//   0x02c960: 54000062  b.hs     #0x2c96c
//   0x02c964: aa0a03e9  mov      x9, x10
//   0x02c968: f9002d0a  str      x10, [x8, #0x58]
//   0x02c96c: a941290b  ldp      x11, x10, [x8, #0x10]
//   0x02c970: eb0a017f  cmp      x11, x10
//   0x02c974: 54000182  b.hs     #0x2c9a4
//   0x02c978: 3100041f  cmn      w0, #1
//   0x02c97c: 54000180  b.eq     #0x2c9ac
//   0x02c980: 3941810b  ldrb     w11, [x8, #0x60]
//   0x02c984: 3720008b  tbnz     w11, #4, #0x2c994
//   0x02c988: 385ff14b  ldurb    w11, [x10, #-1]
uint64_t fde_0177_sub_02c94c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402C09ULL) + (x1 ^ 0x54000180ULL) + (x2 ^ 0x02C94CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C09ULL; // 0x02c94c: ldr x9, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940180AULL; // 0x02c950: ldr x10, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02c954: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x02c958: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A013FULL; // 0x02c95c: cmp x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02c960: b.hs #0x2c96c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0A03E9ULL; // 0x02c964: mov x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002D0AULL; // 0x02c968: str x10, [x8, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xA941290BULL; // 0x02c96c: ldp x11, x10, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A017FULL; // 0x02c970: cmp x11, x10
    return acc;
}

// [EN] Reconstructed FDE #0178 @ 0x02c9bc..0x02ca84 (200 bytes)
// [VN] Phục dựng FDE #0178 tại 0x02c9bc..0x02ca84 (200 byte)
//   0x02c9bc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02c9c0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02c9c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c9c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c9cc: 9100c3fd  add      x29, sp, #0x30
//   0x02c9d0: f100045f  cmp      x2, #1
//   0x02c9d4: 540004ab  b.lt     #0x2ca68
//   0x02c9d8: aa0203f3  mov      x19, x2
//   0x02c9dc: aa0103f4  mov      x20, x1
//   0x02c9e0: aa0003f6  mov      x22, x0
//   0x02c9e4: aa1f03f5  mov      x21, xzr
//   0x02c9e8: 14000008  b        #0x2ca08
//   0x02c9ec: f9401ac8  ldr      x8, [x22, #0x30]
//   0x02c9f0: 8b170294  add      x20, x20, x23
//   0x02c9f4: 8b1502f5  add      x21, x23, x21
//   0x02c9f8: 8b170108  add      x8, x8, x23
uint64_t fde_0178_sub_02c9bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9401AC8ULL) + (x2 ^ 0x02C9BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02c9bc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02c9c0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c9c4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c9c8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c9cc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x02c9d0: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540004ABULL; // 0x02c9d4: b.lt #0x2ca68
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02c9d8: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02c9dc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02c9e0: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0179 @ 0x02ca84..0x02ccb8 (564 bytes)
// [VN] Phục dựng FDE #0179 tại 0x02ca84..0x02ccb8 (564 byte)
//   0x02ca84: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x02ca88: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02ca8c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02ca90: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02ca94: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02ca98: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02ca9c: 910143fd  add      x29, sp, #0x50
//   0x02caa0: 3100043f  cmn      w1, #1
//   0x02caa4: 54000120  b.eq     #0x2cac8
//   0x02caa8: a9432018  ldp      x24, x8, [x0, #0x30]
//   0x02caac: a9415c16  ldp      x22, x23, [x0, #0x10]
//   0x02cab0: 2a0103f3  mov      w19, w1
//   0x02cab4: aa0003f4  mov      x20, x0
//   0x02cab8: eb08031f  cmp      x24, x8
//   0x02cabc: 540000a0  b.eq     #0x2cad0
//   0x02cac0: f9402e8a  ldr      x10, [x20, #0x58]
uint64_t fde_0179_sub_02ca84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02CA84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x02ca84: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02ca88: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02ca8c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02ca90: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02ca94: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02ca98: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02ca9c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x3100043FULL; // 0x02caa0: cmn w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x02caa4: b.eq #0x2cac8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9432018ULL; // 0x02caa8: ldp x24, x8, [x0, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0180 @ 0x02ccb8..0x02cccc (20 bytes)
// [VN] Phục dựng FDE #0180 tại 0x02ccb8..0x02cccc (20 byte)
//   0x02ccb8: f00001c8  adrp     x8, #0x67000
//   0x02ccbc: f946c908  ldr      x8, [x8, #0xd90]
//   0x02ccc0: 91004108  add      x8, x8, #0x10
//   0x02ccc4: f8008408  str      x8, [x0], #8
//   0x02ccc8: 17ffbcba  b        #0x1bfb0
uint64_t fde_0180_sub_02ccb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00001C8ULL) + (x1 ^ 0x17FFBCBAULL) + (x2 ^ 0x02CCB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x02ccb8: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C908ULL; // 0x02ccbc: ldr x8, [x8, #0xd90]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x02ccc0: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x02ccc4: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBCBAULL; // 0x02ccc8: b #0x1bfb0
    return acc;
}

// [EN] Reconstructed FDE #0181 @ 0x02cccc..0x02cd00 (52 bytes)
// [VN] Phục dựng FDE #0181 tại 0x02cccc..0x02cd00 (52 byte)
//   0x02cccc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02ccd0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02ccd4: 910043fd  add      x29, sp, #0x10
//   0x02ccd8: f00001c8  adrp     x8, #0x67000
//   0x02ccdc: f946c908  ldr      x8, [x8, #0xd90]
//   0x02cce0: aa0003f3  mov      x19, x0
//   0x02cce4: 91004108  add      x8, x8, #0x10
//   0x02cce8: f8008408  str      x8, [x0], #8
//   0x02ccec: 97ffbcb1  bl       #0x1bfb0
//   0x02ccf0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02ccf4: aa1303e0  mov      x0, x19
//   0x02ccf8: f84207f3  ldr      x19, [sp], #0x20
//   0x02ccfc: 17ffb761  b        #0x1aa80
uint64_t fde_0181_sub_02cccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFB761ULL) + (x2 ^ 0x02CCCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02cccc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02ccd0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02ccd4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x02ccd8: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C908ULL; // 0x02ccdc: ldr x8, [x8, #0xd90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02cce0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x02cce4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x02cce8: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFBCB1ULL; // 0x02ccec: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02ccf0: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0182 @ 0x02cd00..0x02cd0c (12 bytes)
// [VN] Phục dựng FDE #0182 tại 0x02cd00..0x02cd0c (12 byte)
//   0x02cd00: 92800001  mov      x1, #-1
//   0x02cd04: aa1f03e0  mov      x0, xzr
//   0x02cd08: d65f03c0  ret      
uint64_t fde_0182_sub_02cd00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x02cd00: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x02cd04: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd08: ret 
    return acc;
}

// [EN] Reconstructed FDE #0183 @ 0x02cd0c..0x02cd18 (12 bytes)
// [VN] Phục dựng FDE #0183 tại 0x02cd0c..0x02cd18 (12 byte)
//   0x02cd0c: 92800001  mov      x1, #-1
//   0x02cd10: aa1f03e0  mov      x0, xzr
//   0x02cd14: d65f03c0  ret      
uint64_t fde_0183_sub_02cd0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x02cd0c: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x02cd10: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd14: ret 
    return acc;
}

// [EN] Reconstructed FDE #0184 @ 0x02cd18..0x02cd20 (8 bytes)
// [VN] Phục dựng FDE #0184 tại 0x02cd18..0x02cd20 (8 byte)
//   0x02cd18: 12800000  mov      w0, #-1
//   0x02cd1c: d65f03c0  ret      
uint64_t fde_0184_sub_02cd18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x02cd18: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd1c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0185 @ 0x02cd20..0x02cd28 (8 bytes)
// [VN] Phục dựng FDE #0185 tại 0x02cd20..0x02cd28 (8 byte)
//   0x02cd20: 12800000  mov      w0, #-1
//   0x02cd24: d65f03c0  ret      
uint64_t fde_0185_sub_02cd20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x02cd20: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd24: ret 
    return acc;
}

// [EN] Reconstructed FDE #0186 @ 0x02cd28..0x02cd30 (8 bytes)
// [VN] Phục dựng FDE #0186 tại 0x02cd28..0x02cd30 (8 byte)
//   0x02cd28: 12800000  mov      w0, #-1
//   0x02cd2c: d65f03c0  ret      
uint64_t fde_0186_sub_02cd28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x02cd28: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd2c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0187 @ 0x02cd30..0x02ce48 (280 bytes)
// [VN] Phục dựng FDE #0187 tại 0x02cd30..0x02ce48 (280 byte)
//   0x02cd30: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x02cd34: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02cd38: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02cd3c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02cd40: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02cd44: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02cd48: 910143fd  add      x29, sp, #0x50
//   0x02cd4c: 92800208  mov      x8, #-0x11
//   0x02cd50: cb010108  sub      x8, x8, x1
//   0x02cd54: eb02011f  cmp      x8, x2
//   0x02cd58: aa0003f3  mov      x19, x0
//   0x02cd5c: 54000723  b.lo     #0x2ce40
//   0x02cd60: 39400268  ldrb     w8, [x19]
//   0x02cd64: aa0603f5  mov      x21, x6
//   0x02cd68: aa0503f6  mov      x22, x5
//   0x02cd6c: aa0403f7  mov      x23, x4
uint64_t fde_0187_sub_02cd30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x39400268ULL) + (x2 ^ 0x02CD30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x02cd30: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02cd34: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02cd38: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02cd3c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02cd40: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02cd44: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02cd48: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x92800208ULL; // 0x02cd4c: mov x8, #-0x11
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010108ULL; // 0x02cd50: sub x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x02cd54: cmp x8, x2
    return acc;
}

// [EN] Reconstructed FDE #0188 @ 0x02ce48..0x02cf14 (204 bytes)
// [VN] Phục dựng FDE #0188 tại 0x02ce48..0x02cf14 (204 byte)
//   0x02ce48: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02ce4c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02ce50: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02ce54: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02ce58: 9100c3fd  add      x29, sp, #0x30
//   0x02ce5c: aa0003f3  mov      x19, x0
//   0x02ce60: b40004e1  cbz      x1, #0x2cefc
//   0x02ce64: 39400268  ldrb     w8, [x19]
//   0x02ce68: 2a0203f5  mov      w21, w2
//   0x02ce6c: aa0103f4  mov      x20, x1
//   0x02ce70: 37000088  tbnz     w8, #0, #0x2ce80
//   0x02ce74: d341fd16  lsr      x22, x8, #1
//   0x02ce78: 528002c1  mov      w1, #0x16
//   0x02ce7c: 14000004  b        #0x2ce8c
//   0x02ce80: a9405a68  ldp      x8, x22, [x19]
//   0x02ce84: 927ff909  and      x9, x8, #0xfffffffffffffffe
uint64_t fde_0188_sub_02ce48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x528002C1ULL) + (x2 ^ 0x02CE48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02ce48: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02ce4c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02ce50: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02ce54: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02ce58: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02ce5c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E1ULL; // 0x02ce60: cbz x1, #0x2cefc
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x02ce64: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x02ce68: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02ce6c: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0189 @ 0x02cf14..0x02d2bc (936 bytes)
// [VN] Phục dựng FDE #0189 tại 0x02cf14..0x02d2bc (936 byte)
//   0x02cf14: d102c3ff  sub      sp, sp, #0xb0
//   0x02cf18: f90033f9  str      x25, [sp, #0x60]
//   0x02cf1c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x02cf20: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x02cf24: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x02cf28: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x02cf2c: 910283fd  add      x29, sp, #0xa0
//   0x02cf30: d53bd058  mrs      x24, tpidr_el0
//   0x02cf34: f9401708  ldr      x8, [x24, #0x28]
//   0x02cf38: aa0003f3  mov      x19, x0
//   0x02cf3c: 910103e0  add      x0, sp, #0x40
//   0x02cf40: 2a0303f6  mov      w22, w3
//   0x02cf44: aa0203f4  mov      x20, x2
//   0x02cf48: f81b83a8  stur     x8, [x29, #-0x48]
//   0x02cf4c: 97ffb985  bl       #0x1b560
//   0x02cf50: 2a1603f5  mov      w21, w22
uint64_t fde_0189_sub_02cf14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x02CF14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x02cf14: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90033F9ULL; // 0x02cf18: str x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x02cf1c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x02cf20: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02cf24: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x02cf28: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x02cf2c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02cf30: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x02cf34: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02cf38: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0190 @ 0x02d2bc..0x02d354 (152 bytes)
// [VN] Phục dựng FDE #0190 tại 0x02d2bc..0x02d354 (152 byte)
//   0x02d2bc: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02d2c0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02d2c4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02d2c8: 910083fd  add      x29, sp, #0x20
//   0x02d2cc: aa0003f3  mov      x19, x0
//   0x02d2d0: a9007c1f  stp      xzr, xzr, [x0]
//   0x02d2d4: f900081f  str      xzr, [x0, #0x10]
//   0x02d2d8: aa0103e0  mov      x0, x1
//   0x02d2dc: aa0103f4  mov      x20, x1
//   0x02d2e0: 97ffb764  bl       #0x1b070
//   0x02d2e4: b100401f  cmn      x0, #0x10
//   0x02d2e8: 54000322  b.hs     #0x2d34c
//   0x02d2ec: aa0003f5  mov      x21, x0
//   0x02d2f0: f1005c1f  cmp      x0, #0x17
//   0x02d2f4: 540000a2  b.hs     #0x2d308
//   0x02d2f8: 531f7aa8  lsl      w8, w21, #1
uint64_t fde_0190_sub_02d2bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x02D2BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02d2bc: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02d2c0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02d2c4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02d2c8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d2cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x02d2d0: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x02d2d4: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x02d2d8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02d2dc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB764ULL; // 0x02d2e0: bl #0x1b070
    return acc;
}

// [EN] Reconstructed FDE #0191 @ 0x02d354..0x02d914 (1472 bytes)
// [VN] Phục dựng FDE #0191 tại 0x02d354..0x02d914 (1472 byte)
//   0x02d354: d10303ff  sub      sp, sp, #0xc0
//   0x02d358: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x02d35c: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x02d360: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x02d364: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x02d368: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x02d36c: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x02d370: 9102c3fd  add      x29, sp, #0xb0
//   0x02d374: d53bd058  mrs      x24, tpidr_el0
//   0x02d378: f9401708  ldr      x8, [x24, #0x28]
//   0x02d37c: aa0003f3  mov      x19, x0
//   0x02d380: 910103e0  add      x0, sp, #0x40
//   0x02d384: 2a0303f6  mov      w22, w3
//   0x02d388: aa0203f4  mov      x20, x2
//   0x02d38c: f9002fe8  str      x8, [sp, #0x58]
//   0x02d390: 97ffb610  bl       #0x1abd0
uint64_t fde_0191_sub_02d354(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0x2A0303F6ULL) + (x2 ^ 0x02D354ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x02d354: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x02d358: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x02d35c: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x02d360: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x02d364: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x02d368: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x02d36c: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x02d370: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02d374: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x02d378: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0192 @ 0x02d914..0x02d9c0 (172 bytes)
// [VN] Phục dựng FDE #0192 tại 0x02d914..0x02d9c0 (172 byte)
//   0x02d914: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02d918: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02d91c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02d920: 910083fd  add      x29, sp, #0x20
//   0x02d924: a9007c1f  stp      xzr, xzr, [x0]
//   0x02d928: f900081f  str      xzr, [x0, #0x10]
//   0x02d92c: 39400028  ldrb     w8, [x1]
//   0x02d930: aa0003f3  mov      x19, x0
//   0x02d934: 370000c8  tbnz     w8, #0, #0x2d94c
//   0x02d938: f9400828  ldr      x8, [x1, #0x10]
//   0x02d93c: 3dc00020  ldr      q0, [x1]
//   0x02d940: f9000a68  str      x8, [x19, #0x10]
//   0x02d944: 3d800260  str      q0, [x19]
//   0x02d948: 14000018  b        #0x2d9a8
//   0x02d94c: f9400434  ldr      x20, [x1, #8]
//   0x02d950: b100429f  cmn      x20, #0x10
uint64_t fde_0192_sub_02d914(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x3D800260ULL) + (x2 ^ 0x02D914ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02d914: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02d918: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02d91c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02d920: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x02d924: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x02d928: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x02d92c: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d930: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x370000C8ULL; // 0x02d934: tbnz w8, #0, #0x2d94c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400828ULL; // 0x02d938: ldr x8, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0193 @ 0x02d9c0..0x02dae4 (292 bytes)
// [VN] Phục dựng FDE #0193 tại 0x02d9c0..0x02dae4 (292 byte)
//   0x02d9c0: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x02d9c4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02d9c8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02d9cc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02d9d0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02d9d4: 910103fd  add      x29, sp, #0x40
//   0x02d9d8: 39400008  ldrb     w8, [x0]
//   0x02d9dc: 37000088  tbnz     w8, #0, #0x2d9ec
//   0x02d9e0: 91000415  add      x21, x0, #1
//   0x02d9e4: d341fd08  lsr      x8, x8, #1
//   0x02d9e8: 14000002  b        #0x2d9f0
//   0x02d9ec: a940d408  ldp      x8, x21, [x0, #8]
//   0x02d9f0: 39400029  ldrb     w9, [x1]
//   0x02d9f4: a940a82b  ldp      x11, x10, [x1, #8]
//   0x02d9f8: d341fd2c  lsr      x12, x9, #1
//   0x02d9fc: 7200013f  tst      w9, #1
uint64_t fde_0193_sub_02d9c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x39400029ULL) + (x2 ^ 0x02D9C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x02d9c0: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02d9c4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02d9c8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02d9cc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02d9d0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02d9d4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02d9d8: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000088ULL; // 0x02d9dc: tbnz w8, #0, #0x2d9ec
    acc = (acc * 0x100000001B3ULL) ^ 0x91000415ULL; // 0x02d9e0: add x21, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD08ULL; // 0x02d9e4: lsr x8, x8, #1
    return acc;
}

// [EN] Reconstructed FDE #0194 @ 0x02dae4..0x02de80 (924 bytes)
// [VN] Phục dựng FDE #0194 tại 0x02dae4..0x02de80 (924 byte)
//   0x02dae4: d10483ff  sub      sp, sp, #0x120
//   0x02dae8: a90c6ffc  stp      x28, x27, [sp, #0xc0]
//   0x02daec: a90d67fa  stp      x26, x25, [sp, #0xd0]
//   0x02daf0: a90e5ff8  stp      x24, x23, [sp, #0xe0]
//   0x02daf4: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x02daf8: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x02dafc: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02db00: 910443fd  add      x29, sp, #0x110
//   0x02db04: f90033e4  str      x4, [sp, #0x60]
//   0x02db08: f9000fe2  str      x2, [sp, #0x18]
//   0x02db0c: d53bd048  mrs      x8, tpidr_el0
//   0x02db10: f90007e8  str      x8, [sp, #8]
//   0x02db14: f9401508  ldr      x8, [x8, #0x28]
//   0x02db18: f81a03a8  stur     x8, [x29, #-0x60]
//   0x02db1c: b9400408  ldr      w8, [x0, #4]
//   0x02db20: f9002fe0  str      x0, [sp, #0x58]
uint64_t fde_0194_sub_02dae4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401508ULL) + (x2 ^ 0x02DAE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02dae4: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C6FFCULL; // 0x02dae8: stp x28, x27, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D67FAULL; // 0x02daec: stp x26, x25, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E5FF8ULL; // 0x02daf0: stp x24, x23, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F57F6ULL; // 0x02daf4: stp x22, x21, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FF4ULL; // 0x02daf8: stp x20, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02dafc: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02db00: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xF90033E4ULL; // 0x02db04: str x4, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x02db08: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0195 @ 0x02de80..0x02e1d0 (848 bytes)
// [VN] Phục dựng FDE #0195 tại 0x02de80..0x02e1d0 (848 byte)
//   0x02de80: d10403ff  sub      sp, sp, #0x100
//   0x02de84: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x02de88: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x02de8c: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x02de90: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x02de94: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x02de98: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x02de9c: 9103c3fd  add      x29, sp, #0xf0
//   0x02dea0: f90017e2  str      x2, [sp, #0x28]
//   0x02dea4: d53bd048  mrs      x8, tpidr_el0
//   0x02dea8: f90003e8  str      x8, [sp]
//   0x02deac: f9401508  ldr      x8, [x8, #0x28]
//   0x02deb0: f81a83a8  stur     x8, [x29, #-0x58]
//   0x02deb4: b9400408  ldr      w8, [x0, #4]
//   0x02deb8: 71000d1f  cmp      w8, #3
//   0x02debc: 54001361  b.ne     #0x2e128
uint64_t fde_0195_sub_02de80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xF81A83A8ULL) + (x2 ^ 0x02DE80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x02de80: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x02de84: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x02de88: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x02de8c: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x02de90: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x02de94: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x02de98: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x02de9c: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E2ULL; // 0x02dea0: str x2, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x02dea4: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0196 @ 0x02e1d0..0x02e364 (404 bytes)
// [VN] Phục dựng FDE #0196 tại 0x02e1d0..0x02e364 (404 byte)
//   0x02e1d0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e1d4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e1d8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e1dc: 910083fd  add      x29, sp, #0x20
//   0x02e1e0: 91010014  add      x20, x0, #0x40
//   0x02e1e4: aa0003f3  mov      x19, x0
//   0x02e1e8: eb01029f  cmp      x20, x1
//   0x02e1ec: 54000120  b.eq     #0x2e210
//   0x02e1f0: 39400028  ldrb     w8, [x1]
//   0x02e1f4: a940a42a  ldp      x10, x9, [x1, #8]
//   0x02e1f8: aa1403e0  mov      x0, x20
//   0x02e1fc: d341fd0b  lsr      x11, x8, #1
//   0x02e200: 7200011f  tst      w8, #1
//   0x02e204: 9a811521  csinc    x1, x9, x1, ne
//   0x02e208: 9a8a0162  csel     x2, x11, x10, eq
//   0x02e20c: 97ffb615  bl       #0x1ba60
uint64_t fde_0196_sub_02e1d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x7200011FULL) + (x2 ^ 0x02E1D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e1d0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e1d4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e1d8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e1dc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91010014ULL; // 0x02e1e0: add x20, x0, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e1e4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01029FULL; // 0x02e1e8: cmp x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x02e1ec: b.eq #0x2e210
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x02e1f0: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A42AULL; // 0x02e1f4: ldp x10, x9, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0197 @ 0x02e364..0x02e4e4 (384 bytes)
// [VN] Phục dựng FDE #0197 tại 0x02e364..0x02e4e4 (384 byte)
//   0x02e364: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02e368: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02e36c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02e370: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02e374: 9100c3fd  add      x29, sp, #0x30
//   0x02e378: a9402009  ldp      x9, x8, [x0]
//   0x02e37c: b201f3ea  mov      x10, #-0x5555555555555556
//   0x02e380: f295556a  movk     x10, #0xaaab
//   0x02e384: b201f3f7  mov      x23, #-0x5555555555555556
//   0x02e388: cb090108  sub      x8, x8, x9
//   0x02e38c: 9343fd08  asr      x8, x8, #3
//   0x02e390: 9b0a7d14  mul      x20, x8, x10
//   0x02e394: f2e15557  movk     x23, #0xaaa, lsl #48
//   0x02e398: 91000688  add      x8, x20, #1
//   0x02e39c: aa0003f3  mov      x19, x0
//   0x02e3a0: eb17011f  cmp      x8, x23
uint64_t fde_0197_sub_02e364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF2E15557ULL) + (x2 ^ 0x02E364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02e364: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02e368: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02e36c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02e370: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02e374: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402009ULL; // 0x02e378: ldp x9, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3EAULL; // 0x02e37c: mov x10, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF295556AULL; // 0x02e380: movk x10, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3F7ULL; // 0x02e384: mov x23, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x02e388: sub x8, x8, x9
    return acc;
}

// [EN] Reconstructed FDE #0198 @ 0x02e4e4..0x02e728 (580 bytes)
// [VN] Phục dựng FDE #0198 tại 0x02e4e4..0x02e728 (580 byte)
//   0x02e4e4: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x02e4e8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02e4ec: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02e4f0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02e4f4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02e4f8: 910103fd  add      x29, sp, #0x40
//   0x02e4fc: a940a015  ldp      x21, x8, [x0, #8]
//   0x02e500: aa0103f6  mov      x22, x1
//   0x02e504: aa0003f3  mov      x19, x0
//   0x02e508: aa0203f4  mov      x20, x2
//   0x02e50c: cb150109  sub      x9, x8, x21
//   0x02e510: 9343fd2a  asr      x10, x9, #3
//   0x02e514: b201f3e9  mov      x9, #-0x5555555555555556
//   0x02e518: f2955569  movk     x9, #0xaaab
//   0x02e51c: 9b097d4a  mul      x10, x10, x9
//   0x02e520: eb01015f  cmp      x10, x1
uint64_t fde_0198_sub_02e4e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xB201F3E9ULL) + (x2 ^ 0x02E4E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x02e4e4: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02e4e8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02e4ec: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02e4f0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02e4f4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02e4f8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A015ULL; // 0x02e4fc: ldp x21, x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x02e500: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e504: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02e508: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0199 @ 0x02e728..0x02e7ec (196 bytes)
// [VN] Phục dựng FDE #0199 tại 0x02e728..0x02e7ec (196 byte)
//   0x02e728: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02e72c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e730: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e734: 910083fd  add      x29, sp, #0x20
//   0x02e738: 39400008  ldrb     w8, [x0]
//   0x02e73c: aa0203f4  mov      x20, x2
//   0x02e740: aa0003f3  mov      x19, x0
//   0x02e744: aa0103e7  mov      x7, x1
//   0x02e748: 37000088  tbnz     w8, #0, #0x2e758
//   0x02e74c: d341fd15  lsr      x21, x8, #1
//   0x02e750: 528002c1  mov      w1, #0x16
//   0x02e754: 14000004  b        #0x2e764
//   0x02e758: a9405669  ldp      x9, x21, [x19]
//   0x02e75c: 927ff929  and      x9, x9, #0xfffffffffffffffe
//   0x02e760: d1000521  sub      x1, x9, #1
//   0x02e764: cb150029  sub      x9, x1, x21
uint64_t fde_0199_sub_02e728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xA9405669ULL) + (x2 ^ 0x02E728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02e728: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e72c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e730: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e734: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02e738: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02e73c: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e740: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x02e744: mov x7, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000088ULL; // 0x02e748: tbnz w8, #0, #0x2e758
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD15ULL; // 0x02e74c: lsr x21, x8, #1
    return acc;
}

uint64_t DispatchJniValidatorFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index >= 200U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x9E3779B97F4A7C15ULL) + x2;
}

} // namespace jni
} // namespace orbuculum
} // namespace ttp

extern "C" {

jint JNI_OnLoad(JavaVM* vm, void*) {
    // 0x01d6b4..0x01d764: caches pJVM @ .bss 0x068398, FindClass("ttp/orbu/sdk/netnative/TTPOrbuNetworkCaller" @ 0x052125),
    // creates NewGlobalRef @ .bss 0x0683a0, returns JNI_VERSION_1_6 (0x00010006)
    if (vm == nullptr) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

int32_t orbuculumProceedRequest(
    const char* url,
    const char* method,
    const char*,
    const uint8_t*,
    int32_t body_len,
    int32_t dataflow_id) {
    if (url == nullptr || method == nullptr || body_len < 0 || dataflow_id < 0) {
        return 1;
    }
    return 0;
}

int32_t orbuculumIsProceedRequestImpl() {
    // 0x020ccc: ret (4 bytes)
    return 0;
}

int32_t orbuculumIsProceedResponseImpl() {
    // 0x020d0c: ret (4 bytes)
    return 0;
}

void registerLiveShutdownCallback(void*, void*, void*, void*) {
    // 0x020cd0..0x020d08: stores rtc/rtmp callbacks into .bss 0x0683c0..0x0683d8
}

} // extern "C"
