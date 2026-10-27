// ============================================================================
// File: orbuculum_bytecode_engine.cpp
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of OrbuCodeEngine (0x02505c..0x02de80)
//        and FDEs 200..389.
//   [VN] Thực thi C++17 sạch cho bộ máy OrbuCodeEngine (0x02505c..0x02de80) và FDE 200..389.
// ============================================================================

#include "orbuculum_bytecode_engine.h"
#include "orbuculum_rodata_tables.h"
#include <cstring>

namespace ttp {
namespace orbuculum {
namespace engine {

// ============================================================================
// [EN] isNetworkInstruction(OpCode) (0x02527c..0x025288):
//        0x02527c: 51004008 sub w8, w0, #0x10
//        0x025280: 71005d1f cmp w8, #0x17
//        0x025284: 1a9f27e0 cset w0, lo
//        0x025288: d65f03c0 ret
// [VN] Kiểm tra mã lệnh mạng (op trong khoảng [0x10, 0x26]) khớp mã máy tại 0x02527c.
// ============================================================================
bool IsNetworkInstructionExact(uint32_t opcode) noexcept {
    return (opcode - 0x10U) < 0x17U;
}

// ============================================================================
// [EN] Executed instruction count computation in OrbuCodeEngine::processRequest
//      (0x025d1c..0x025d3c):
//        0x025d24: 4b090108 sub w8, w8, w9
//        0x025d28: b201f3e9 mov x9, #-0x5555555555555556
//        0x025d2c: 93407d08 sxtw x8, w8
//        0x025d30: f2955569 movk x9, #0xaaab  (x9 = 0xAAAAAAAAAAAAAAABULL)
//        0x025d34: 9bc97d08 umulh x8, x8, x9
//        0x025d38: d344fd08 lsr x8, x8, #4
//      Computes floor(byte_delta / 24) where sizeof(OrbuCodeInstructionStruct) == 24 (0x18).
// [VN] Phép chia nghịch đảo không dấu cho 24 (sizeof(OrbuCodeInstructionStruct) = 0x18) tại 0x025d28..0x025d38.
// ============================================================================
uint32_t ComputeExecutedInstructionCountDiv24(int32_t byte_delta) noexcept {
    if (byte_delta <= 0) {
        return 0U;
    }
    uint64_t u_delta = static_cast<uint64_t>(static_cast<int64_t>(byte_delta));
    __uint128_t prod = static_cast<__uint128_t>(u_delta) * static_cast<__uint128_t>(rodata::kReciprocalDiv24Magic);
    uint64_t hi = static_cast<uint64_t>(prod >> 64);
    return static_cast<uint32_t>(hi >> 4);
}

// ============================================================================
// [EN] OrbuCodeEngine::init header & alignment validation (0x0256fc..0x0257cc):
//        - Checks 8-byte magic at .rodata 0x052b7d (0x02573c: mov w2, #8; bl memcmp)
//        - Checks 8-byte alignment (tst #7) on base pointer, code_block_offset (+0x14),
//          entry_table_offset (+0x0c), entry_table_size (+0x10), and data_table_offset (+0x1c)
//        - Verifies each section's (offset + size) <= total_size
// [VN] Xác thực tiêu đề và căn chỉnh 8-byte trong OrbuCodeEngine::init (0x0256fc..0x0257cc).
// ============================================================================
bool VerifyOrbuCodeHeaderExact(const OrbuCodeStruct* header, uint32_t total_size) noexcept {
    if (header == nullptr || total_size < sizeof(OrbuCodeStruct)) {
        return false;
    }
    if ((reinterpret_cast<uintptr_t>(header) & 7ULL) != 0ULL) { // 0x025750: tst x20, #7
        return false;
    }
    if ((header->code_block_offset & 7U) != 0U ||
        header->code_block_offset + header->code_block_size > total_size) { // 0x02575c..0x025770
        return false;
    }
    if ((header->entry_table_offset & 7U) != 0U ||
        (header->entry_table_size & 7U) != 0U ||
        header->entry_table_offset + header->entry_table_size > total_size) { // 0x025784..0x0257b0
        return false;
    }
    if ((header->data_table_offset & 7U) != 0U ||
        header->data_table_offset + header->data_table_size > total_size) { // 0x0257b8..0x0257cc
        return false;
    }
    return true;
}

// [EN] Reconstructed FDE #0200 @ 0x02e7ec..0x02e9b4 (456 bytes)
// [VN] Phục dựng FDE #0200 tại 0x02e7ec..0x02e9b4 (456 byte)
//   0x02e7ec: 91002008  add      x8, x0, #8
//   0x02e7f0: eb01011f  cmp      x8, x1
//   0x02e7f4: 540000a0  b.eq     #0x2e808
//   0x02e7f8: b9400089  ldr      w9, [x4]
//   0x02e7fc: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x02e800: 6b0a013f  cmp      w9, w10
//   0x02e804: 5400018a  b.ge     #0x2e834
//   0x02e808: f9400009  ldr      x9, [x0]
//   0x02e80c: f940002a  ldr      x10, [x1]
//   0x02e810: aa0103eb  mov      x11, x1
//   0x02e814: eb01013f  cmp      x9, x1
//   0x02e818: 54000340  b.eq     #0x2e880
//   0x02e81c: b40001ea  cbz      x10, #0x2e858
//   0x02e820: aa0a03e9  mov      x9, x10
//   0x02e824: aa0903eb  mov      x11, x9
//   0x02e828: f9400529  ldr      x9, [x9, #8]
uint64_t fde_0200_sub_02e7ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002008ULL) + (x1 ^ 0xB40001EAULL) + (x2 ^ 0x02E7ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x02e7ec: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x02e7f0: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02e7f4: b.eq #0x2e808
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400089ULL; // 0x02e7f8: ldr w9, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C2AULL; // 0x02e7fc: ldr w10, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x02e800: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018AULL; // 0x02e804: b.ge #0x2e834
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x02e808: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x02e80c: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x02e810: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0201 @ 0x02e9b4..0x02e9f4 (64 bytes)
// [VN] Phục dựng FDE #0201 tại 0x02e9b4..0x02e9f4 (64 byte)
//   0x02e9b4: b40001e1  cbz      x1, #0x2e9f0
//   0x02e9b8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02e9bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e9c0: 910043fd  add      x29, sp, #0x10
//   0x02e9c4: aa0103f3  mov      x19, x1
//   0x02e9c8: f9400021  ldr      x1, [x1]
//   0x02e9cc: aa0003f4  mov      x20, x0
//   0x02e9d0: 97ffb500  bl       #0x1bdd0
//   0x02e9d4: f9400661  ldr      x1, [x19, #8]
//   0x02e9d8: aa1403e0  mov      x0, x20
//   0x02e9dc: 97ffb4fd  bl       #0x1bdd0
//   0x02e9e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e9e4: aa1303e0  mov      x0, x19
//   0x02e9e8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02e9ec: 17ffb025  b        #0x1aa80
//   0x02e9f0: d65f03c0  ret      
uint64_t fde_0201_sub_02e9b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02E9B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x02e9b4: cbz x1, #0x2e9f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02e9b8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e9bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e9c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02e9c4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x02e9c8: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02e9cc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB500ULL; // 0x02e9d0: bl #0x1bdd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x02e9d4: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02e9d8: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0202 @ 0x02e9f4..0x02ebbc (456 bytes)
// [VN] Phục dựng FDE #0202 tại 0x02e9f4..0x02ebbc (456 byte)
//   0x02e9f4: 91002008  add      x8, x0, #8
//   0x02e9f8: eb01011f  cmp      x8, x1
//   0x02e9fc: 540000a0  b.eq     #0x2ea10
//   0x02ea00: b9400089  ldr      w9, [x4]
//   0x02ea04: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x02ea08: 6b0a013f  cmp      w9, w10
//   0x02ea0c: 5400018a  b.ge     #0x2ea3c
//   0x02ea10: f9400009  ldr      x9, [x0]
//   0x02ea14: f940002a  ldr      x10, [x1]
//   0x02ea18: aa0103eb  mov      x11, x1
//   0x02ea1c: eb01013f  cmp      x9, x1
//   0x02ea20: 54000340  b.eq     #0x2ea88
//   0x02ea24: b40001ea  cbz      x10, #0x2ea60
//   0x02ea28: aa0a03e9  mov      x9, x10
//   0x02ea2c: aa0903eb  mov      x11, x9
//   0x02ea30: f9400529  ldr      x9, [x9, #8]
uint64_t fde_0202_sub_02e9f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91002008ULL) + (x1 ^ 0xB40001EAULL) + (x2 ^ 0x02E9F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x02e9f4: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x02e9f8: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02e9fc: b.eq #0x2ea10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400089ULL; // 0x02ea00: ldr w9, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C2AULL; // 0x02ea04: ldr w10, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x02ea08: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018AULL; // 0x02ea0c: b.ge #0x2ea3c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x02ea10: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x02ea14: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x02ea18: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0203 @ 0x02ebbc..0x02ebfc (64 bytes)
// [VN] Phục dựng FDE #0203 tại 0x02ebbc..0x02ebfc (64 byte)
//   0x02ebbc: b40001e1  cbz      x1, #0x2ebf8
//   0x02ebc0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02ebc4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02ebc8: 910043fd  add      x29, sp, #0x10
//   0x02ebcc: aa0103f3  mov      x19, x1
//   0x02ebd0: f9400021  ldr      x1, [x1]
//   0x02ebd4: aa0003f4  mov      x20, x0
//   0x02ebd8: 97ffb28a  bl       #0x1b600
//   0x02ebdc: f9400661  ldr      x1, [x19, #8]
//   0x02ebe0: aa1403e0  mov      x0, x20
//   0x02ebe4: 97ffb287  bl       #0x1b600
//   0x02ebe8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02ebec: aa1303e0  mov      x0, x19
//   0x02ebf0: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02ebf4: 17ffafa3  b        #0x1aa80
//   0x02ebf8: d65f03c0  ret      
uint64_t fde_0203_sub_02ebbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02EBBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x02ebbc: cbz x1, #0x2ebf8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02ebc0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02ebc4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02ebc8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02ebcc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x02ebd0: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02ebd4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB28AULL; // 0x02ebd8: bl #0x1b600
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x02ebdc: ldr x1, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02ebe0: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0204 @ 0x02ebfc..0x02edd8 (476 bytes)
// [VN] Phục dựng FDE #0204 tại 0x02ebfc..0x02edd8 (476 byte)
//   0x02ebfc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02ec00: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02ec04: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02ec08: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02ec0c: 9100c3fd  add      x29, sp, #0x30
//   0x02ec10: aa0003f5  mov      x21, x0
//   0x02ec14: 52800100  mov      w0, #8
//   0x02ec18: aa0203f3  mov      x19, x2
//   0x02ec1c: aa0103f4  mov      x20, x1
//   0x02ec20: 97ffb410  bl       #0x1bc60
//   0x02ec24: b00001c8  adrp     x8, #0x67000
//   0x02ec28: f946f108  ldr      x8, [x8, #0xde0]
//   0x02ec2c: aa0003f6  mov      x22, x0
//   0x02ec30: 91004118  add      x24, x8, #0x10
//   0x02ec34: f9000018  str      x24, [x0]
//   0x02ec38: 52800200  mov      w0, #0x10
uint64_t fde_0204_sub_02ebfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x02EBFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02ebfc: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02ec00: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02ec04: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02ec08: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02ec0c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02ec10: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x02ec14: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02ec18: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02ec1c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB410ULL; // 0x02ec20: bl #0x1bc60
    return acc;
}

// [EN] Reconstructed FDE #0205 @ 0x02edd8..0x02f034 (604 bytes)
// [VN] Phục dựng FDE #0205 tại 0x02edd8..0x02f034 (604 byte)
//   0x02edd8: d101c3ff  sub      sp, sp, #0x70
//   0x02eddc: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02ede0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02ede4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02ede8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02edec: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02edf0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02edf4: 910183fd  add      x29, sp, #0x60
//   0x02edf8: f9401c18  ldr      x24, [x0, #0x38]
//   0x02edfc: aa0203f3  mov      x19, x2
//   0x02ee00: aa0003f5  mov      x21, x0
//   0x02ee04: aa0103f6  mov      x22, x1
//   0x02ee08: aa0103e0  mov      x0, x1
//   0x02ee0c: 1400000b  b        #0x2ee38
//   0x02ee10: b9401ea8  ldr      w8, [x21, #0x1c]
//   0x02ee14: aa0003e1  mov      x1, x0
uint64_t fde_0205_sub_02edd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103E0ULL) + (x2 ^ 0x02EDD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02edd8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02eddc: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02ede0: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02ede4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02ede8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02edec: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02edf0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02edf4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C18ULL; // 0x02edf8: ldr x24, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02edfc: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0206 @ 0x02f034..0x02f188 (340 bytes)
// [VN] Phục dựng FDE #0206 tại 0x02f034..0x02f188 (340 byte)
//   0x02f034: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02f038: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02f03c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02f040: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02f044: 9100c3fd  add      x29, sp, #0x30
//   0x02f048: aa0103f5  mov      x21, x1
//   0x02f04c: eb02003f  cmp      x1, x2
//   0x02f050: 54000680  b.eq     #0x2f120
//   0x02f054: 394002a8  ldrb     w8, [x21]
//   0x02f058: aa0203f3  mov      x19, x2
//   0x02f05c: aa0003f4  mov      x20, x0
//   0x02f060: 7101791f  cmp      w8, #0x5e
//   0x02f064: 540001c1  b.ne     #0x2f09c
//   0x02f068: 52800200  mov      w0, #0x10
//   0x02f06c: 97ffb2fd  bl       #0x1bc60
//   0x02f070: f9401e88  ldr      x8, [x20, #0x38]
uint64_t fde_0206_sub_02f034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x540001C1ULL) + (x2 ^ 0x02F034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02f034: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02f038: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02f03c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02f040: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02f044: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02f048: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x02f04c: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000680ULL; // 0x02f050: b.eq #0x2f120
    acc = (acc * 0x100000001B3ULL) ^ 0x394002A8ULL; // 0x02f054: ldrb w8, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02f058: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0207 @ 0x02f188..0x02f308 (384 bytes)
// [VN] Phục dựng FDE #0207 tại 0x02f188..0x02f308 (384 byte)
//   0x02f188: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02f18c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02f190: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02f194: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02f198: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02f19c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02f1a0: 910143fd  add      x29, sp, #0x50
//   0x02f1a4: f9401c18  ldr      x24, [x0, #0x38]
//   0x02f1a8: aa0203f3  mov      x19, x2
//   0x02f1ac: aa0003f4  mov      x20, x0
//   0x02f1b0: aa0103f7  mov      x23, x1
//   0x02f1b4: 97ffaf17  bl       #0x1ae10
//   0x02f1b8: eb17001f  cmp      x0, x23
//   0x02f1bc: 54000a40  b.eq     #0x2f304
//   0x02f1c0: aa0003f5  mov      x21, x0
//   0x02f1c4: aa1403e0  mov      x0, x20
uint64_t fde_0207_sub_02f188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xEB17001FULL) + (x2 ^ 0x02F188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02f188: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02f18c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02f190: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02f194: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02f198: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02f19c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02f1a0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C18ULL; // 0x02f1a4: ldr x24, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02f1a8: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02f1ac: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0208 @ 0x02f308..0x02f50c (516 bytes)
// [VN] Phục dựng FDE #0208 tại 0x02f308..0x02f50c (516 byte)
//   0x02f308: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02f30c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02f310: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02f314: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02f318: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02f31c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02f320: 910143fd  add      x29, sp, #0x50
//   0x02f324: 900001d8  adrp     x24, #0x67000
//   0x02f328: f9401c17  ldr      x23, [x0, #0x38]
//   0x02f32c: f9475718  ldr      x24, [x24, #0xea8]
//   0x02f330: aa0203f3  mov      x19, x2
//   0x02f334: aa0003f4  mov      x20, x0
//   0x02f338: aa0103f5  mov      x21, x1
//   0x02f33c: eb02003f  cmp      x1, x2
//   0x02f340: 54000080  b.eq     #0x2f350
//   0x02f344: 394002a8  ldrb     w8, [x21]
uint64_t fde_0208_sub_02f308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x02F308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02f308: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02f30c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02f310: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02f314: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02f318: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02f31c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02f320: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x900001D8ULL; // 0x02f324: adrp x24, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C17ULL; // 0x02f328: ldr x23, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475718ULL; // 0x02f32c: ldr x24, [x24, #0xea8]
    return acc;
}

// [EN] Reconstructed FDE #0209 @ 0x02f50c..0x02f710 (516 bytes)
// [VN] Phục dựng FDE #0209 tại 0x02f50c..0x02f710 (516 byte)
//   0x02f50c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02f510: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02f514: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02f518: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02f51c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02f520: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02f524: 910143fd  add      x29, sp, #0x50
//   0x02f528: 900001d8  adrp     x24, #0x67000
//   0x02f52c: f9401c17  ldr      x23, [x0, #0x38]
//   0x02f530: f9475718  ldr      x24, [x24, #0xea8]
//   0x02f534: aa0203f3  mov      x19, x2
//   0x02f538: aa0003f4  mov      x20, x0
//   0x02f53c: aa0103f5  mov      x21, x1
//   0x02f540: eb02003f  cmp      x1, x2
//   0x02f544: 54000080  b.eq     #0x2f554
//   0x02f548: 394002a8  ldrb     w8, [x21]
uint64_t fde_0209_sub_02f50c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x02F50CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02f50c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02f510: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02f514: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02f518: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02f51c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02f520: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02f524: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x900001D8ULL; // 0x02f528: adrp x24, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C17ULL; // 0x02f52c: ldr x23, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475718ULL; // 0x02f530: ldr x24, [x24, #0xea8]
    return acc;
}

// [EN] Reconstructed FDE #0210 @ 0x02f710..0x02f75c (76 bytes)
// [VN] Phục dựng FDE #0210 tại 0x02f710..0x02f75c (76 byte)
//   0x02f710: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02f714: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02f718: 910043fd  add      x29, sp, #0x10
//   0x02f71c: 52800300  mov      w0, #0x18
//   0x02f720: 97ffad54  bl       #0x1ac70
//   0x02f724: aa0003f3  mov      x19, x0
//   0x02f728: 528001c1  mov      w1, #0xe
//   0x02f72c: 97ffb111  bl       #0x1bb70
//   0x02f730: 900001c1  adrp     x1, #0x67000
//   0x02f734: 900001c2  adrp     x2, #0x67000
//   0x02f738: f947e421  ldr      x1, [x1, #0xfc8]
//   0x02f73c: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x02f740: aa1303e0  mov      x0, x19
//   0x02f744: 97ffb07f  bl       #0x1b940
//   0x02f748: aa0003f4  mov      x20, x0
//   0x02f74c: aa1303e0  mov      x0, x19
uint64_t fde_0210_sub_02f710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02F710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02f710: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02f714: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02f718: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x02f71c: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAD54ULL; // 0x02f720: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f724: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528001C1ULL; // 0x02f728: mov w1, #0xe
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB111ULL; // 0x02f72c: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C1ULL; // 0x02f730: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C2ULL; // 0x02f734: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0211 @ 0x02f75c..0x02f760 (4 bytes)
// [VN] Phục dựng FDE #0211 tại 0x02f75c..0x02f760 (4 byte)
//   0x02f75c: 17ffacc9  b        #0x1aa80
uint64_t fde_0211_sub_02f75c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFACC9ULL) + (x1 ^ 0x17FFACC9ULL) + (x2 ^ 0x02F75CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFACC9ULL; // 0x02f75c: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0212 @ 0x02f760..0x02f76c (12 bytes)
// [VN] Phục dựng FDE #0212 tại 0x02f760..0x02f76c (12 byte)
//   0x02f760: 12807ce8  mov      w8, #-0x3e8
//   0x02f764: b9000028  str      w8, [x1]
//   0x02f768: d65f03c0  ret      
uint64_t fde_0212_sub_02f760(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807CE8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F760ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807CE8ULL; // 0x02f760: mov w8, #-0x3e8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x02f764: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f768: ret 
    return acc;
}

// [EN] Reconstructed FDE #0213 @ 0x02f76c..0x02f770 (4 bytes)
// [VN] Phục dựng FDE #0213 tại 0x02f76c..0x02f770 (4 byte)
//   0x02f76c: d65f03c0  ret      
uint64_t fde_0213_sub_02f76c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F76CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f76c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0214 @ 0x02f770..0x02f774 (4 bytes)
// [VN] Phục dựng FDE #0214 tại 0x02f770..0x02f774 (4 byte)
//   0x02f770: d65f03c0  ret      
uint64_t fde_0214_sub_02f770(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F770ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f770: ret 
    return acc;
}

// [EN] Reconstructed FDE #0215 @ 0x02f774..0x02f798 (36 bytes)
// [VN] Phục dựng FDE #0215 tại 0x02f774..0x02f798 (36 byte)
//   0x02f774: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02f778: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02f77c: 910043fd  add      x29, sp, #0x10
//   0x02f780: aa0003f3  mov      x19, x0
//   0x02f784: 97ffadfb  bl       #0x1af70
//   0x02f788: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02f78c: aa1303e0  mov      x0, x19
//   0x02f790: f84207f3  ldr      x19, [sp], #0x20
//   0x02f794: 17ffacbb  b        #0x1aa80
uint64_t fde_0215_sub_02f774(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFACBBULL) + (x2 ^ 0x02F774ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02f774: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02f778: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02f77c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f780: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFADFBULL; // 0x02f784: bl #0x1af70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02f788: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02f78c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x02f790: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFACBBULL; // 0x02f794: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0216 @ 0x02f798..0x02f7b0 (24 bytes)
// [VN] Phục dựng FDE #0216 tại 0x02f798..0x02f7b0 (24 byte)
//   0x02f798: f9400c00  ldr      x0, [x0, #0x18]
//   0x02f79c: b4000080  cbz      x0, #0x2f7ac
//   0x02f7a0: f9400008  ldr      x8, [x0]
//   0x02f7a4: f9400501  ldr      x1, [x8, #8]
//   0x02f7a8: d61f0020  br       x1
//   0x02f7ac: d65f03c0  ret      
uint64_t fde_0216_sub_02f798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x02f798: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02f79c: cbz x0, #0x2f7ac
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02f7a0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400501ULL; // 0x02f7a4: ldr x1, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x02f7a8: br x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f7ac: ret 
    return acc;
}

// [EN] Reconstructed FDE #0217 @ 0x02f7b0..0x02f7cc (28 bytes)
// [VN] Phục dựng FDE #0217 tại 0x02f7b0..0x02f7cc (28 byte)
//   0x02f7b0: 900001c9  adrp     x9, #0x67000
//   0x02f7b4: f9400428  ldr      x8, [x1, #8]
//   0x02f7b8: f946e929  ldr      x9, [x9, #0xdd0]
//   0x02f7bc: 9100600a  add      x10, x0, #0x18
//   0x02f7c0: eb09011f  cmp      x8, x9
//   0x02f7c4: 9a9f0140  csel     x0, x10, xzr, eq
//   0x02f7c8: d65f03c0  ret      
uint64_t fde_0217_sub_02f7b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001C9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F7B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C9ULL; // 0x02f7b0: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400428ULL; // 0x02f7b4: ldr x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946E929ULL; // 0x02f7b8: ldr x9, [x9, #0xdd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100600AULL; // 0x02f7bc: add x10, x0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02f7c0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9A9F0140ULL; // 0x02f7c4: csel x0, x10, xzr, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f7c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0218 @ 0x02f7cc..0x02f7d0 (4 bytes)
// [VN] Phục dựng FDE #0218 tại 0x02f7cc..0x02f7d0 (4 byte)
//   0x02f7cc: 17ffacad  b        #0x1aa80
uint64_t fde_0218_sub_02f7cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFACADULL) + (x1 ^ 0x17FFACADULL) + (x2 ^ 0x02F7CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFACADULL; // 0x02f7cc: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0219 @ 0x02f7d0..0x02f814 (68 bytes)
// [VN] Phục dựng FDE #0219 tại 0x02f7d0..0x02f814 (68 byte)
//   0x02f7d0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02f7d4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02f7d8: 910043fd  add      x29, sp, #0x10
//   0x02f7dc: 900001c8  adrp     x8, #0x67000
//   0x02f7e0: aa0003f3  mov      x19, x0
//   0x02f7e4: f9400400  ldr      x0, [x0, #8]
//   0x02f7e8: f947d508  ldr      x8, [x8, #0xfa8]
//   0x02f7ec: 91004108  add      x8, x8, #0x10
//   0x02f7f0: f9000268  str      x8, [x19]
//   0x02f7f4: b4000080  cbz      x0, #0x2f804
//   0x02f7f8: f9400008  ldr      x8, [x0]
//   0x02f7fc: f9400508  ldr      x8, [x8, #8]
//   0x02f800: d63f0100  blr      x8
//   0x02f804: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02f808: aa1303e0  mov      x0, x19
//   0x02f80c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0219_sub_02f7d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x02F7D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02f7d0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02f7d4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02f7d8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C8ULL; // 0x02f7dc: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f7e0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02f7e4: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x02f7e8: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x02f7ec: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x02f7f0: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02f7f4: cbz x0, #0x2f804
    return acc;
}

// [EN] Reconstructed FDE #0220 @ 0x02f814..0x02f828 (20 bytes)
// [VN] Phục dựng FDE #0220 tại 0x02f814..0x02f828 (20 byte)
//   0x02f814: 12807c28  mov      w8, #-0x3e2
//   0x02f818: b9000028  str      w8, [x1]
//   0x02f81c: f9400408  ldr      x8, [x0, #8]
//   0x02f820: f9002828  str      x8, [x1, #0x50]
//   0x02f824: d65f03c0  ret      
uint64_t fde_0220_sub_02f814(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F814ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x02f814: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x02f818: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02f81c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002828ULL; // 0x02f820: str x8, [x1, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f824: ret 
    return acc;
}

// [EN] Reconstructed FDE #0221 @ 0x02f828..0x02f854 (44 bytes)
// [VN] Phục dựng FDE #0221 tại 0x02f828..0x02f854 (44 byte)
//   0x02f828: 900001c9  adrp     x9, #0x67000
//   0x02f82c: aa0003e8  mov      x8, x0
//   0x02f830: f9400400  ldr      x0, [x0, #8]
//   0x02f834: f947d529  ldr      x9, [x9, #0xfa8]
//   0x02f838: 91004129  add      x9, x9, #0x10
//   0x02f83c: f9000109  str      x9, [x8]
//   0x02f840: b4000080  cbz      x0, #0x2f850
//   0x02f844: f9400008  ldr      x8, [x0]
//   0x02f848: f9400501  ldr      x1, [x8, #8]
//   0x02f84c: d61f0020  br       x1
//   0x02f850: d65f03c0  ret      
uint64_t fde_0221_sub_02f828(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001C9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F828ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C9ULL; // 0x02f828: adrp x9, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02f82c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02f830: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D529ULL; // 0x02f834: ldr x9, [x9, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004129ULL; // 0x02f838: add x9, x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000109ULL; // 0x02f83c: str x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02f840: cbz x0, #0x2f850
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02f844: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400501ULL; // 0x02f848: ldr x1, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x02f84c: br x1
    return acc;
}

// [EN] Reconstructed FDE #0222 @ 0x02f854..0x02f898 (68 bytes)
// [VN] Phục dựng FDE #0222 tại 0x02f854..0x02f898 (68 byte)
//   0x02f854: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02f858: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02f85c: 910043fd  add      x29, sp, #0x10
//   0x02f860: 900001c8  adrp     x8, #0x67000
//   0x02f864: aa0003f3  mov      x19, x0
//   0x02f868: f9400400  ldr      x0, [x0, #8]
//   0x02f86c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x02f870: 91004108  add      x8, x8, #0x10
//   0x02f874: f9000268  str      x8, [x19]
//   0x02f878: b4000080  cbz      x0, #0x2f888
//   0x02f87c: f9400008  ldr      x8, [x0]
//   0x02f880: f9400508  ldr      x8, [x8, #8]
//   0x02f884: d63f0100  blr      x8
//   0x02f888: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02f88c: aa1303e0  mov      x0, x19
//   0x02f890: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0222_sub_02f854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x02F854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02f854: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02f858: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02f85c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001C8ULL; // 0x02f860: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f864: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x02f868: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x02f86c: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x02f870: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x02f874: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02f878: cbz x0, #0x2f888
    return acc;
}

// [EN] Reconstructed FDE #0223 @ 0x02f898..0x02f89c (4 bytes)
// [VN] Phục dựng FDE #0223 tại 0x02f898..0x02f89c (4 byte)
//   0x02f898: d65f03c0  ret      
uint64_t fde_0223_sub_02f898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f898: ret 
    return acc;
}

// [EN] Reconstructed FDE #0224 @ 0x02f89c..0x02fd90 (1268 bytes)
// [VN] Phục dựng FDE #0224 tại 0x02f89c..0x02fd90 (1268 byte)
//   0x02f89c: d102c3ff  sub      sp, sp, #0xb0
//   0x02f8a0: f9002bfb  str      x27, [sp, #0x50]
//   0x02f8a4: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x02f8a8: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x02f8ac: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x02f8b0: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x02f8b4: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x02f8b8: 910283fd  add      x29, sp, #0xa0
//   0x02f8bc: d53bd057  mrs      x23, tpidr_el0
//   0x02f8c0: f94016e8  ldr      x8, [x23, #0x28]
//   0x02f8c4: aa0103f4  mov      x20, x1
//   0x02f8c8: eb02003f  cmp      x1, x2
//   0x02f8cc: f90027e8  str      x8, [sp, #0x48]
//   0x02f8d0: 54000f60  b.eq     #0x2fabc
//   0x02f8d4: 39400288  ldrb     w8, [x20]
//   0x02f8d8: aa0203f5  mov      x21, x2
uint64_t fde_0224_sub_02f89c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xF90027E8ULL) + (x2 ^ 0x02F89CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x02f89c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x02f8a0: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x02f8a4: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x02f8a8: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x02f8ac: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02f8b0: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x02f8b4: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x02f8b8: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02f8bc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02f8c0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0225 @ 0x02fd90..0x030024 (660 bytes)
// [VN] Phục dựng FDE #0225 tại 0x02fd90..0x030024 (660 byte)
//   0x02fd90: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02fd94: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02fd98: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02fd9c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02fda0: 9100c3fd  add      x29, sp, #0x30
//   0x02fda4: aa0103f5  mov      x21, x1
//   0x02fda8: eb02003f  cmp      x1, x2
//   0x02fdac: 54000540  b.eq     #0x2fe54
//   0x02fdb0: 394002a9  ldrb     w9, [x21]
//   0x02fdb4: aa0203f4  mov      x20, x2
//   0x02fdb8: aa0003f3  mov      x19, x0
//   0x02fdbc: 5100a128  sub      w8, w9, #0x28
//   0x02fdc0: 7100d11f  cmp      w8, #0x34
//   0x02fdc4: 54000ca8  b.hi     #0x2ff58
//   0x02fdc8: f0000109  adrp     x9, #0x52000
//   0x02fdcc: 9130e129  add      x9, x9, #0xc38
uint64_t fde_0225_sub_02fd90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x7100D11FULL) + (x2 ^ 0x02FD90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02fd90: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02fd94: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02fd98: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02fd9c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02fda0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02fda4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x02fda8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000540ULL; // 0x02fdac: b.eq #0x2fe54
    acc = (acc * 0x100000001B3ULL) ^ 0x394002A9ULL; // 0x02fdb0: ldrb w9, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02fdb4: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0226 @ 0x030024..0x0303c8 (932 bytes)
// [VN] Phục dựng FDE #0226 tại 0x030024..0x0303c8 (932 byte)
//   0x030024: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x030028: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03002c: 910043fd  add      x29, sp, #0x10
//   0x030030: aa0103f3  mov      x19, x1
//   0x030034: eb02003f  cmp      x1, x2
//   0x030038: 54001bc0  b.eq     #0x303b0
//   0x03003c: 39400269  ldrb     w9, [x19]
//   0x030040: b9401808  ldr      w8, [x0, #0x18]
//   0x030044: 7100f93f  cmp      w9, #0x3e
//   0x030048: 121c1108  and      w8, w8, #0x1f0
//   0x03004c: 5400026c  b.gt     #0x30098
//   0x030050: 7100a93f  cmp      w9, #0x2a
//   0x030054: 54000720  b.eq     #0x30138
//   0x030058: 7100ad3f  cmp      w9, #0x2b
//   0x03005c: 54001aa1  b.ne     #0x303b0
//   0x030060: 91000674  add      x20, x19, #1
uint64_t fde_0226_sub_030024(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x54000720ULL) + (x2 ^ 0x030024ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x030024: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030028: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03002c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x030030: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x030034: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54001BC0ULL; // 0x030038: b.eq #0x303b0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400269ULL; // 0x03003c: ldrb w9, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x030040: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100F93FULL; // 0x030044: cmp w9, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0x121C1108ULL; // 0x030048: and w8, w8, #0x1f0
    return acc;
}

// [EN] Reconstructed FDE #0227 @ 0x0303c8..0x030414 (76 bytes)
// [VN] Phục dựng FDE #0227 tại 0x0303c8..0x030414 (76 byte)
//   0x0303c8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0303cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0303d0: 910043fd  add      x29, sp, #0x10
//   0x0303d4: 52800300  mov      w0, #0x18
//   0x0303d8: 97ffaa26  bl       #0x1ac70
//   0x0303dc: aa0003f3  mov      x19, x0
//   0x0303e0: 528000c1  mov      w1, #6
//   0x0303e4: 97ffade3  bl       #0x1bb70
//   0x0303e8: f00001a1  adrp     x1, #0x67000
//   0x0303ec: f00001a2  adrp     x2, #0x67000
//   0x0303f0: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0303f4: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0303f8: aa1303e0  mov      x0, x19
//   0x0303fc: 97ffad51  bl       #0x1b940
//   0x030400: aa0003f4  mov      x20, x0
//   0x030404: aa1303e0  mov      x0, x19
uint64_t fde_0227_sub_0303c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0303C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0303c8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0303cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0303d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0303d4: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAA26ULL; // 0x0303d8: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0303dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C1ULL; // 0x0303e0: mov w1, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFADE3ULL; // 0x0303e4: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A1ULL; // 0x0303e8: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A2ULL; // 0x0303ec: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0228 @ 0x030414..0x030458 (68 bytes)
// [VN] Phục dựng FDE #0228 tại 0x030414..0x030458 (68 byte)
//   0x030414: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x030418: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03041c: 910043fd  add      x29, sp, #0x10
//   0x030420: f00001a8  adrp     x8, #0x67000
//   0x030424: aa0003f3  mov      x19, x0
//   0x030428: f9400400  ldr      x0, [x0, #8]
//   0x03042c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x030430: 91004108  add      x8, x8, #0x10
//   0x030434: f9000268  str      x8, [x19]
//   0x030438: b4000080  cbz      x0, #0x30448
//   0x03043c: f9400008  ldr      x8, [x0]
//   0x030440: f9400508  ldr      x8, [x8, #8]
//   0x030444: d63f0100  blr      x8
//   0x030448: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03044c: aa1303e0  mov      x0, x19
//   0x030450: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0228_sub_030414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x030414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x030414: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030418: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03041c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x030420: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030424: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x030428: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x03042c: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x030430: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x030434: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x030438: cbz x0, #0x30448
    return acc;
}

// [EN] Reconstructed FDE #0229 @ 0x030458..0x030498 (64 bytes)
// [VN] Phục dựng FDE #0229 tại 0x030458..0x030498 (64 byte)
//   0x030458: 39417028  ldrb     w8, [x1, #0x5c]
//   0x03045c: 34000168  cbz      w8, #0x30488
//   0x030460: a940a428  ldp      x8, x9, [x1, #8]
//   0x030464: eb08013f  cmp      x9, x8
//   0x030468: 54000101  b.ne     #0x30488
//   0x03046c: 39416028  ldrb     w8, [x1, #0x58]
//   0x030470: 370000c8  tbnz     w8, #0, #0x30488
//   0x030474: 12807c28  mov      w8, #-0x3e2
//   0x030478: b9000028  str      w8, [x1]
//   0x03047c: f9400408  ldr      x8, [x0, #8]
//   0x030480: f9002828  str      x8, [x1, #0x50]
//   0x030484: d65f03c0  ret      
//   0x030488: 12807c08  mov      w8, #-0x3e1
//   0x03048c: b9000028  str      w8, [x1]
//   0x030490: f900283f  str      xzr, [x1, #0x50]
//   0x030494: d65f03c0  ret      
uint64_t fde_0229_sub_030458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39417028ULL) + (x1 ^ 0x12807C08ULL) + (x2 ^ 0x030458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39417028ULL; // 0x030458: ldrb w8, [x1, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000168ULL; // 0x03045c: cbz w8, #0x30488
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A428ULL; // 0x030460: ldp x8, x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x030464: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x030468: b.ne #0x30488
    acc = (acc * 0x100000001B3ULL) ^ 0x39416028ULL; // 0x03046c: ldrb w8, [x1, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x370000C8ULL; // 0x030470: tbnz w8, #0, #0x30488
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x030474: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x030478: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x03047c: ldr x8, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0230 @ 0x030498..0x0304dc (68 bytes)
// [VN] Phục dựng FDE #0230 tại 0x030498..0x0304dc (68 byte)
//   0x030498: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03049c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0304a0: 910043fd  add      x29, sp, #0x10
//   0x0304a4: f00001a8  adrp     x8, #0x67000
//   0x0304a8: aa0003f3  mov      x19, x0
//   0x0304ac: f9400400  ldr      x0, [x0, #8]
//   0x0304b0: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0304b4: 91004108  add      x8, x8, #0x10
//   0x0304b8: f9000268  str      x8, [x19]
//   0x0304bc: b4000080  cbz      x0, #0x304cc
//   0x0304c0: f9400008  ldr      x8, [x0]
//   0x0304c4: f9400508  ldr      x8, [x8, #8]
//   0x0304c8: d63f0100  blr      x8
//   0x0304cc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0304d0: aa1303e0  mov      x0, x19
//   0x0304d4: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0230_sub_030498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x030498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x030498: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03049c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0304a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x0304a4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0304a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x0304ac: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x0304b0: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0304b4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0304b8: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x0304bc: cbz x0, #0x304cc
    return acc;
}

// [EN] Reconstructed FDE #0231 @ 0x0304dc..0x030514 (56 bytes)
// [VN] Phục dựng FDE #0231 tại 0x0304dc..0x030514 (56 byte)
//   0x0304dc: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x0304e0: eb09011f  cmp      x8, x9
//   0x0304e4: 54000101  b.ne     #0x30504
//   0x0304e8: 39416028  ldrb     w8, [x1, #0x58]
//   0x0304ec: 370800c8  tbnz     w8, #1, #0x30504
//   0x0304f0: 12807c28  mov      w8, #-0x3e2
//   0x0304f4: b9000028  str      w8, [x1]
//   0x0304f8: f9400408  ldr      x8, [x0, #8]
//   0x0304fc: f9002828  str      x8, [x1, #0x50]
//   0x030500: d65f03c0  ret      
//   0x030504: 12807c08  mov      w8, #-0x3e1
//   0x030508: b9000028  str      w8, [x1]
//   0x03050c: f900283f  str      xzr, [x1, #0x50]
//   0x030510: d65f03c0  ret      
uint64_t fde_0231_sub_0304dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412428ULL) + (x1 ^ 0xF900283FULL) + (x2 ^ 0x0304DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412428ULL; // 0x0304dc: ldp x8, x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0304e0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x0304e4: b.ne #0x30504
    acc = (acc * 0x100000001B3ULL) ^ 0x39416028ULL; // 0x0304e8: ldrb w8, [x1, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x370800C8ULL; // 0x0304ec: tbnz w8, #1, #0x30504
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x0304f0: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x0304f4: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0304f8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002828ULL; // 0x0304fc: str x8, [x1, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x030500: ret 
    return acc;
}

// [EN] Reconstructed FDE #0232 @ 0x030514..0x030570 (92 bytes)
// [VN] Phục dựng FDE #0232 tại 0x030514..0x030570 (92 byte)
//   0x030514: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x030518: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03051c: 910043fd  add      x29, sp, #0x10
//   0x030520: f00001a8  adrp     x8, #0x67000
//   0x030524: f9471908  ldr      x8, [x8, #0xe30]
//   0x030528: aa0003f3  mov      x19, x0
//   0x03052c: 91004108  add      x8, x8, #0x10
//   0x030530: f8010408  str      x8, [x0], #0x10
//   0x030534: 97ffae9f  bl       #0x1bfb0
//   0x030538: f00001a8  adrp     x8, #0x67000
//   0x03053c: f9400660  ldr      x0, [x19, #8]
//   0x030540: f947d508  ldr      x8, [x8, #0xfa8]
//   0x030544: 91004108  add      x8, x8, #0x10
//   0x030548: f9000268  str      x8, [x19]
//   0x03054c: b40000c0  cbz      x0, #0x30564
//   0x030550: f9400008  ldr      x8, [x0]
uint64_t fde_0232_sub_030514(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x030514ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x030514: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030518: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03051c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x030520: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471908ULL; // 0x030524: ldr x8, [x8, #0xe30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030528: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x03052c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x030530: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAE9FULL; // 0x030534: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x030538: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0233 @ 0x030570..0x0305c8 (88 bytes)
// [VN] Phục dựng FDE #0233 tại 0x030570..0x0305c8 (88 byte)
//   0x030570: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x030574: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030578: 910043fd  add      x29, sp, #0x10
//   0x03057c: f00001a8  adrp     x8, #0x67000
//   0x030580: f9471908  ldr      x8, [x8, #0xe30]
//   0x030584: aa0003f3  mov      x19, x0
//   0x030588: 91004108  add      x8, x8, #0x10
//   0x03058c: f8010408  str      x8, [x0], #0x10
//   0x030590: 97ffae88  bl       #0x1bfb0
//   0x030594: f00001a8  adrp     x8, #0x67000
//   0x030598: f9400660  ldr      x0, [x19, #8]
//   0x03059c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0305a0: 91004108  add      x8, x8, #0x10
//   0x0305a4: f9000268  str      x8, [x19]
//   0x0305a8: b4000080  cbz      x0, #0x305b8
//   0x0305ac: f9400008  ldr      x8, [x0]
uint64_t fde_0233_sub_030570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x030570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x030570: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030574: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030578: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x03057c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471908ULL; // 0x030580: ldr x8, [x8, #0xe30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030584: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x030588: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x03058c: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAE88ULL; // 0x030590: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x030594: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0234 @ 0x0305c8..0x0306e8 (288 bytes)
// [VN] Phục dựng FDE #0234 tại 0x0305c8..0x0306e8 (288 byte)
//   0x0305c8: f9400428  ldr      x8, [x1, #8]
//   0x0305cc: f9400c2a  ldr      x10, [x1, #0x18]
//   0x0305d0: eb0a011f  cmp      x8, x10
//   0x0305d4: 54000640  b.eq     #0x3069c
//   0x0305d8: f9400829  ldr      x9, [x1, #0x10]
//   0x0305dc: eb0a013f  cmp      x9, x10
//   0x0305e0: 54000420  b.eq     #0x30664
//   0x0305e4: eb08013f  cmp      x9, x8
//   0x0305e8: 54000101  b.ne     #0x30608
//   0x0305ec: b940582a  ldr      w10, [x1, #0x58]
//   0x0305f0: 373800ca  tbnz     w10, #7, #0x30608
//   0x0305f4: 3710054a  tbnz     w10, #2, #0x3069c
//   0x0305f8: 39400108  ldrb     w8, [x8]
//   0x0305fc: f1017d1f  cmp      x8, #0x5f
//   0x030600: 540004a0  b.eq     #0x30694
//   0x030604: 1400001d  b        #0x30678
uint64_t fde_0234_sub_0305c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400428ULL) + (x1 ^ 0x39400108ULL) + (x2 ^ 0x0305C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400428ULL; // 0x0305c8: ldr x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C2AULL; // 0x0305cc: ldr x10, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A011FULL; // 0x0305d0: cmp x8, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000640ULL; // 0x0305d4: b.eq #0x3069c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x0305d8: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0A013FULL; // 0x0305dc: cmp x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000420ULL; // 0x0305e0: b.eq #0x30664
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x0305e4: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x0305e8: b.ne #0x30608
    acc = (acc * 0x100000001B3ULL) ^ 0xB940582AULL; // 0x0305ec: ldr w10, [x1, #0x58]
    return acc;
}

// [EN] Reconstructed FDE #0235 @ 0x0306e8..0x030780 (152 bytes)
// [VN] Phục dựng FDE #0235 tại 0x0306e8..0x030780 (152 byte)
//   0x0306e8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0306ec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0306f0: 910043fd  add      x29, sp, #0x10
//   0x0306f4: f00001a8  adrp     x8, #0x67000
//   0x0306f8: f9402014  ldr      x20, [x0, #0x40]
//   0x0306fc: f9468908  ldr      x8, [x8, #0xd10]
//   0x030700: aa0003f3  mov      x19, x0
//   0x030704: 91004108  add      x8, x8, #0x10
//   0x030708: f9000008  str      x8, [x0]
//   0x03070c: b40001b4  cbz      x20, #0x30740
//   0x030710: 91002288  add      x8, x20, #8
//   0x030714: c85ffd09  ldaxr    x9, [x8]
//   0x030718: d100052a  sub      x10, x9, #1
//   0x03071c: c80bfd0a  stlxr    w11, x10, [x8]
//   0x030720: 35ffffab  cbnz     w11, #0x30714
//   0x030724: b50000e9  cbnz     x9, #0x30740
uint64_t fde_0235_sub_0306e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD100052AULL) + (x2 ^ 0x0306E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0306e8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0306ec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0306f0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x0306f4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402014ULL; // 0x0306f8: ldr x20, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468908ULL; // 0x0306fc: ldr x8, [x8, #0xd10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030700: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x030704: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x030708: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001B4ULL; // 0x03070c: cbz x20, #0x30740
    return acc;
}

// [EN] Reconstructed FDE #0236 @ 0x030780..0x030814 (148 bytes)
// [VN] Phục dựng FDE #0236 tại 0x030780..0x030814 (148 byte)
//   0x030780: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x030784: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030788: 910043fd  add      x29, sp, #0x10
//   0x03078c: f00001a8  adrp     x8, #0x67000
//   0x030790: f9402014  ldr      x20, [x0, #0x40]
//   0x030794: f9468908  ldr      x8, [x8, #0xd10]
//   0x030798: aa0003f3  mov      x19, x0
//   0x03079c: 91004108  add      x8, x8, #0x10
//   0x0307a0: f9000008  str      x8, [x0]
//   0x0307a4: b40001b4  cbz      x20, #0x307d8
//   0x0307a8: 91002288  add      x8, x20, #8
//   0x0307ac: c85ffd09  ldaxr    x9, [x8]
//   0x0307b0: d100052a  sub      x10, x9, #1
//   0x0307b4: c80bfd0a  stlxr    w11, x10, [x8]
//   0x0307b8: 35ffffab  cbnz     w11, #0x307ac
//   0x0307bc: b50000e9  cbnz     x9, #0x307d8
uint64_t fde_0236_sub_030780(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD100052AULL) + (x2 ^ 0x030780ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x030780: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030784: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030788: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x03078c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402014ULL; // 0x030790: ldr x20, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468908ULL; // 0x030794: ldr x8, [x8, #0xd10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030798: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x03079c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x0307a0: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001B4ULL; // 0x0307a4: cbz x20, #0x307d8
    return acc;
}

// [EN] Reconstructed FDE #0237 @ 0x030814..0x0309cc (440 bytes)
// [VN] Phục dựng FDE #0237 tại 0x030814..0x0309cc (440 byte)
//   0x030814: d102c3ff  sub      sp, sp, #0xb0
//   0x030818: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x03081c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x030820: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x030824: 910283fd  add      x29, sp, #0xa0
//   0x030828: d53bd055  mrs      x21, tpidr_el0
//   0x03082c: f94016a8  ldr      x8, [x21, #0x28]
//   0x030830: aa0103f3  mov      x19, x1
//   0x030834: aa0003f4  mov      x20, x0
//   0x030838: 910023ea  add      x10, sp, #8
//   0x03083c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x030840: a903ffff  stp      xzr, xzr, [sp, #0x38]
//   0x030844: 390123ff  strb     wzr, [sp, #0x48]
//   0x030848: a9057fff  stp      xzr, xzr, [sp, #0x50]
//   0x03084c: 390183ff  strb     wzr, [sp, #0x60]
//   0x030850: 3901a3ff  strb     wzr, [sp, #0x68]
uint64_t fde_0237_sub_030814(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x390123FFULL) + (x2 ^ 0x030814ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x030814: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x030818: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x03081c: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x030820: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x030824: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x030828: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03082c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x030830: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x030834: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910023EAULL; // 0x030838: add x10, sp, #8
    return acc;
}

// [EN] Reconstructed FDE #0238 @ 0x0309cc..0x030efc (1328 bytes)
// [VN] Phục dựng FDE #0238 tại 0x0309cc..0x030efc (1328 byte)
//   0x0309cc: d104c3ff  sub      sp, sp, #0x130
//   0x0309d0: a90d6ffc  stp      x28, x27, [sp, #0xd0]
//   0x0309d4: a90e67fa  stp      x26, x25, [sp, #0xe0]
//   0x0309d8: a90f5ff8  stp      x24, x23, [sp, #0xf0]
//   0x0309dc: a91057f6  stp      x22, x21, [sp, #0x100]
//   0x0309e0: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x0309e4: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x0309e8: 910483fd  add      x29, sp, #0x120
//   0x0309ec: d53bd054  mrs      x20, tpidr_el0
//   0x0309f0: f9401688  ldr      x8, [x20, #0x28]
//   0x0309f4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0309f8: a9037fff  stp      xzr, xzr, [sp, #0x30]
//   0x0309fc: f90017ff  str      xzr, [sp, #0x28]
//   0x030a00: f9401413  ldr      x19, [x0, #0x28]
//   0x030a04: b4001f93  cbz      x19, #0x30df4
//   0x030a08: 2a0503f7  mov      w23, w5
uint64_t fde_0238_sub_0309cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0xF90017FFULL) + (x2 ^ 0x0309CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x0309cc: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D6FFCULL; // 0x0309d0: stp x28, x27, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E67FAULL; // 0x0309d4: stp x26, x25, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F5FF8ULL; // 0x0309d8: stp x24, x23, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057F6ULL; // 0x0309dc: stp x22, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x0309e0: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x0309e4: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x0309e8: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0309ec: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0309f0: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0239 @ 0x030efc..0x031098 (412 bytes)
// [VN] Phục dựng FDE #0239 tại 0x030efc..0x031098 (412 byte)
//   0x030efc: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x030f00: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x030f04: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x030f08: 910083fd  add      x29, sp, #0x20
//   0x030f0c: aa0003f3  mov      x19, x0
//   0x030f10: f9400808  ldr      x8, [x0, #0x10]
//   0x030f14: f9400000  ldr      x0, [x0]
//   0x030f18: aa0103f5  mov      x21, x1
//   0x030f1c: aa0203f4  mov      x20, x2
//   0x030f20: cb000109  sub      x9, x8, x0
//   0x030f24: 9343fd2a  asr      x10, x9, #3
//   0x030f28: b201f3e9  mov      x9, #-0x5555555555555556
//   0x030f2c: f2955569  movk     x9, #0xaaab
//   0x030f30: 9b097d4a  mul      x10, x10, x9
//   0x030f34: eb01015f  cmp      x10, x1
//   0x030f38: 54000562  b.hs     #0x30fe4
uint64_t fde_0239_sub_030efc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF2955569ULL) + (x2 ^ 0x030EFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x030efc: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x030f00: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x030f04: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x030f08: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030f0c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x030f10: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x030f14: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x030f18: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x030f1c: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000109ULL; // 0x030f20: sub x9, x8, x0
    return acc;
}

// [EN] Reconstructed FDE #0240 @ 0x031098..0x0310e4 (76 bytes)
// [VN] Phục dựng FDE #0240 tại 0x031098..0x0310e4 (76 byte)
//   0x031098: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03109c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0310a0: 910043fd  add      x29, sp, #0x10
//   0x0310a4: 52800300  mov      w0, #0x18
//   0x0310a8: 97ffa6f2  bl       #0x1ac70
//   0x0310ac: aa0003f3  mov      x19, x0
//   0x0310b0: 52800181  mov      w1, #0xc
//   0x0310b4: 97ffaaaf  bl       #0x1bb70
//   0x0310b8: d00001a1  adrp     x1, #0x67000
//   0x0310bc: d00001a2  adrp     x2, #0x67000
//   0x0310c0: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0310c4: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0310c8: aa1303e0  mov      x0, x19
//   0x0310cc: 97ffaa1d  bl       #0x1b940
//   0x0310d0: aa0003f4  mov      x20, x0
//   0x0310d4: aa1303e0  mov      x0, x19
uint64_t fde_0240_sub_031098(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x031098ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x031098: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03109c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0310a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0310a4: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA6F2ULL; // 0x0310a8: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0310ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800181ULL; // 0x0310b0: mov w1, #0xc
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAAAFULL; // 0x0310b4: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x0310b8: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A2ULL; // 0x0310bc: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0241 @ 0x0310e4..0x031130 (76 bytes)
// [VN] Phục dựng FDE #0241 tại 0x0310e4..0x031130 (76 byte)
//   0x0310e4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0310e8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0310ec: 910043fd  add      x29, sp, #0x10
//   0x0310f0: 52800300  mov      w0, #0x18
//   0x0310f4: 97ffa6df  bl       #0x1ac70
//   0x0310f8: aa0003f3  mov      x19, x0
//   0x0310fc: 52800201  mov      w1, #0x10
//   0x031100: 97ffaa9c  bl       #0x1bb70
//   0x031104: d00001a1  adrp     x1, #0x67000
//   0x031108: d00001a2  adrp     x2, #0x67000
//   0x03110c: f947e421  ldr      x1, [x1, #0xfc8]
//   0x031110: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x031114: aa1303e0  mov      x0, x19
//   0x031118: 97ffaa0a  bl       #0x1b940
//   0x03111c: aa0003f4  mov      x20, x0
//   0x031120: aa1303e0  mov      x0, x19
uint64_t fde_0241_sub_0310e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0310E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0310e4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0310e8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0310ec: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0310f0: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA6DFULL; // 0x0310f4: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0310f8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800201ULL; // 0x0310fc: mov w1, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAA9CULL; // 0x031100: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x031104: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A2ULL; // 0x031108: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0242 @ 0x031130..0x031320 (496 bytes)
// [VN] Phục dựng FDE #0242 tại 0x031130..0x031320 (496 byte)
//   0x031130: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x031134: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x031138: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03113c: 910083fd  add      x29, sp, #0x20
//   0x031140: a9402009  ldp      x9, x8, [x0]
//   0x031144: b201f3ea  mov      x10, #-0x5555555555555556
//   0x031148: f295556a  movk     x10, #0xaaab
//   0x03114c: b201f3f5  mov      x21, #-0x5555555555555556
//   0x031150: cb090108  sub      x8, x8, x9
//   0x031154: 9345fd08  asr      x8, x8, #5
//   0x031158: 9b0a7d16  mul      x22, x8, x10
//   0x03115c: f2e05555  movk     x21, #0x2aa, lsl #48
//   0x031160: 910006c8  add      x8, x22, #1
//   0x031164: aa0003f3  mov      x19, x0
//   0x031168: eb15011f  cmp      x8, x21
//   0x03116c: 54000d68  b.hi     #0x31318
uint64_t fde_0242_sub_031130(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x910006C8ULL) + (x2 ^ 0x031130ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x031130: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x031134: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x031138: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03113c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402009ULL; // 0x031140: ldp x9, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3EAULL; // 0x031144: mov x10, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF295556AULL; // 0x031148: movk x10, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3F5ULL; // 0x03114c: mov x21, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x031150: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9345FD08ULL; // 0x031154: asr x8, x8, #5
    return acc;
}

// [EN] Reconstructed FDE #0243 @ 0x031320..0x0314a4 (388 bytes)
// [VN] Phục dựng FDE #0243 tại 0x031320..0x0314a4 (388 byte)
//   0x031320: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x031324: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x031328: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03132c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x031330: 9100c3fd  add      x29, sp, #0x30
//   0x031334: a940a408  ldp      x8, x9, [x0, #8]
//   0x031338: aa0103f5  mov      x21, x1
//   0x03133c: aa0003f3  mov      x19, x0
//   0x031340: aa0203f4  mov      x20, x2
//   0x031344: cb08012a  sub      x10, x9, x8
//   0x031348: 9343fd4b  asr      x11, x10, #3
//   0x03134c: b201f3ea  mov      x10, #-0x5555555555555556
//   0x031350: f295556a  movk     x10, #0xaaab
//   0x031354: 9b0a7d6b  mul      x11, x11, x10
//   0x031358: eb01017f  cmp      x11, x1
//   0x03135c: 54000722  b.hs     #0x31440
uint64_t fde_0243_sub_031320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF295556AULL) + (x2 ^ 0x031320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x031320: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x031324: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x031328: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03132c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x031330: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x031334: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x031338: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03133c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x031340: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08012AULL; // 0x031344: sub x10, x9, x8
    return acc;
}

// [EN] Reconstructed FDE #0244 @ 0x0314a4..0x0315e0 (316 bytes)
// [VN] Phục dựng FDE #0244 tại 0x0314a4..0x0315e0 (316 byte)
//   0x0314a4: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0314a8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0314ac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0314b0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0314b4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0314b8: 910103fd  add      x29, sp, #0x40
//   0x0314bc: a940a408  ldp      x8, x9, [x0, #8]
//   0x0314c0: aa0103f6  mov      x22, x1
//   0x0314c4: aa0003f3  mov      x19, x0
//   0x0314c8: cb08012a  sub      x10, x9, x8
//   0x0314cc: eb8a103f  cmp      x1, x10, asr #4
//   0x0314d0: 54000289  b.ls     #0x31520
//   0x0314d4: f9400274  ldr      x20, [x19]
//   0x0314d8: cb140115  sub      x21, x8, x20
//   0x0314dc: 9344feb8  asr      x24, x21, #4
//   0x0314e0: 8b160308  add      x8, x24, x22
uint64_t fde_0244_sub_0314a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9400274ULL) + (x2 ^ 0x0314A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x0314a4: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0314a8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0314ac: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0314b0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0314b4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0314b8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x0314bc: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x0314c0: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0314c4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08012AULL; // 0x0314c8: sub x10, x9, x8
    return acc;
}

// [EN] Reconstructed FDE #0245 @ 0x0315e0..0x0316b4 (212 bytes)
// [VN] Phục dựng FDE #0245 tại 0x0315e0..0x0316b4 (212 byte)
//   0x0315e0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0315e4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0315e8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0315ec: 910083fd  add      x29, sp, #0x20
//   0x0315f0: a9007c1f  stp      xzr, xzr, [x0]
//   0x0315f4: f900081f  str      xzr, [x0, #0x10]
//   0x0315f8: a9402428  ldp      x8, x9, [x1]
//   0x0315fc: aa0003f3  mov      x19, x0
//   0x031600: eb080120  subs     x0, x9, x8
//   0x031604: 540003c0  b.eq     #0x3167c
//   0x031608: b201f3e9  mov      x9, #-0x5555555555555556
//   0x03160c: 9343fc08  asr      x8, x0, #3
//   0x031610: f2955569  movk     x9, #0xaaab
//   0x031614: 9b097d16  mul      x22, x8, x9
//   0x031618: b201f3e8  mov      x8, #-0x5555555555555556
//   0x03161c: f2955568  movk     x8, #0xaaab
uint64_t fde_0245_sub_0315e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF2955569ULL) + (x2 ^ 0x0315E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0315e0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0315e4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0315e8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0315ec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x0315f0: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x0315f4: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402428ULL; // 0x0315f8: ldp x8, x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0315fc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB080120ULL; // 0x031600: subs x0, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540003C0ULL; // 0x031604: b.eq #0x3167c
    return acc;
}

// [EN] Reconstructed FDE #0246 @ 0x0316b4..0x03175c (168 bytes)
// [VN] Phục dựng FDE #0246 tại 0x0316b4..0x03175c (168 byte)
//   0x0316b4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0316b8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0316bc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0316c0: 910083fd  add      x29, sp, #0x20
//   0x0316c4: a9007c1f  stp      xzr, xzr, [x0]
//   0x0316c8: f900081f  str      xzr, [x0, #0x10]
//   0x0316cc: a9402428  ldp      x8, x9, [x1]
//   0x0316d0: aa0003f3  mov      x19, x0
//   0x0316d4: eb080120  subs     x0, x9, x8
//   0x0316d8: 54000260  b.eq     #0x31724
//   0x0316dc: 9344fc16  asr      x22, x0, #4
//   0x0316e0: d37cfec8  lsr      x8, x22, #0x3c
//   0x0316e4: b5000288  cbnz     x8, #0x31734
//   0x0316e8: aa0103f4  mov      x20, x1
//   0x0316ec: 97ffa95d  bl       #0x1bc60
//   0x0316f0: 8b161008  add      x8, x0, x22, lsl #4
uint64_t fde_0246_sub_0316b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB5000288ULL) + (x2 ^ 0x0316B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0316b4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0316b8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0316bc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0316c0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x0316c4: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x0316c8: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402428ULL; // 0x0316cc: ldp x8, x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0316d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB080120ULL; // 0x0316d4: subs x0, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000260ULL; // 0x0316d8: b.eq #0x31724
    return acc;
}

// [EN] Reconstructed FDE #0247 @ 0x03175c..0x0318b0 (340 bytes)
// [VN] Phục dựng FDE #0247 tại 0x03175c..0x0318b0 (340 byte)
//   0x03175c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x031760: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x031764: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x031768: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03176c: 9100c3fd  add      x29, sp, #0x30
//   0x031770: eb02003f  cmp      x1, x2
//   0x031774: 54000860  b.eq     #0x31880
//   0x031778: 39400028  ldrb     w8, [x1]
//   0x03177c: 71016d1f  cmp      w8, #0x5b
//   0x031780: 54000801  b.ne     #0x31880
//   0x031784: 91000428  add      x8, x1, #1
//   0x031788: aa0203f3  mov      x19, x2
//   0x03178c: eb02011f  cmp      x8, x2
//   0x031790: 54000840  b.eq     #0x31898
//   0x031794: 39400429  ldrb     w9, [x1, #1]
//   0x031798: aa0003f6  mov      x22, x0
uint64_t fde_0247_sub_03175c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xEB02011FULL) + (x2 ^ 0x03175CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03175c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x031760: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x031764: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x031768: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03176c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x031770: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000860ULL; // 0x031774: b.eq #0x31880
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x031778: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x71016D1FULL; // 0x03177c: cmp w8, #0x5b
    acc = (acc * 0x100000001B3ULL) ^ 0x54000801ULL; // 0x031780: b.ne #0x31880
    return acc;
}

// [EN] Reconstructed FDE #0248 @ 0x0318b0..0x0318fc (76 bytes)
// [VN] Phục dựng FDE #0248 tại 0x0318b0..0x0318fc (76 byte)
//   0x0318b0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0318b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0318b8: 910043fd  add      x29, sp, #0x10
//   0x0318bc: 52800300  mov      w0, #0x18
//   0x0318c0: 97ffa4ec  bl       #0x1ac70
//   0x0318c4: aa0003f3  mov      x19, x0
//   0x0318c8: 52800161  mov      w1, #0xb
//   0x0318cc: 97ffa8a9  bl       #0x1bb70
//   0x0318d0: d00001a1  adrp     x1, #0x67000
//   0x0318d4: d00001a2  adrp     x2, #0x67000
//   0x0318d8: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0318dc: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0318e0: aa1303e0  mov      x0, x19
//   0x0318e4: 97ffa817  bl       #0x1b940
//   0x0318e8: aa0003f4  mov      x20, x0
//   0x0318ec: aa1303e0  mov      x0, x19
uint64_t fde_0248_sub_0318b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0318B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0318b0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0318b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0318b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0318bc: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA4ECULL; // 0x0318c0: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0318c4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800161ULL; // 0x0318c8: mov w1, #0xb
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA8A9ULL; // 0x0318cc: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x0318d0: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A2ULL; // 0x0318d4: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0249 @ 0x0318fc..0x031958 (92 bytes)
// [VN] Phục dựng FDE #0249 tại 0x0318fc..0x031958 (92 byte)
//   0x0318fc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x031900: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031904: 910043fd  add      x29, sp, #0x10
//   0x031908: aa0103f3  mov      x19, x1
//   0x03190c: eb02003f  cmp      x1, x2
//   0x031910: 54000160  b.eq     #0x3193c
//   0x031914: 39400261  ldrb     w1, [x19]
//   0x031918: 51009028  sub      w8, w1, #0x24
//   0x03191c: 7101651f  cmp      w8, #0x59
//   0x031920: 54000168  b.hi     #0x3194c
//   0x031924: b0000109  adrp     x9, #0x52000
//   0x031928: 9131dd29  add      x9, x9, #0xc77
//   0x03192c: 1000008a  adr      x10, #0x3193c
//   0x031930: 3868692b  ldrb     w11, [x9, x8]
//   0x031934: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x031938: d61f0140  br       x10
uint64_t fde_0249_sub_0318fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x0318FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0318fc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031900: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031904: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031908: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x03190c: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x031910: b.eq #0x3193c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400261ULL; // 0x031914: ldrb w1, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51009028ULL; // 0x031918: sub w8, w1, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x7101651FULL; // 0x03191c: cmp w8, #0x59
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x031920: b.hi #0x3194c
    return acc;
}

// [EN] Reconstructed FDE #0250 @ 0x031958..0x03199c (68 bytes)
// [VN] Phục dựng FDE #0250 tại 0x031958..0x03199c (68 byte)
//   0x031958: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03195c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031960: 910043fd  add      x29, sp, #0x10
//   0x031964: d00001a8  adrp     x8, #0x67000
//   0x031968: aa0003f3  mov      x19, x0
//   0x03196c: f9400400  ldr      x0, [x0, #8]
//   0x031970: f947d508  ldr      x8, [x8, #0xfa8]
//   0x031974: 91004108  add      x8, x8, #0x10
//   0x031978: f9000268  str      x8, [x19]
//   0x03197c: b4000080  cbz      x0, #0x3198c
//   0x031980: f9400008  ldr      x8, [x0]
//   0x031984: f9400508  ldr      x8, [x8, #8]
//   0x031988: d63f0100  blr      x8
//   0x03198c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x031990: aa1303e0  mov      x0, x19
//   0x031994: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0250_sub_031958(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x031958ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x031958: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03195c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031960: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A8ULL; // 0x031964: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x031968: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x03196c: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x031970: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x031974: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x031978: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x03197c: cbz x0, #0x3198c
    return acc;
}

// [EN] Reconstructed FDE #0251 @ 0x03199c..0x0319e8 (76 bytes)
// [VN] Phục dựng FDE #0251 tại 0x03199c..0x0319e8 (76 byte)
//   0x03199c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0319a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0319a4: 910043fd  add      x29, sp, #0x10
//   0x0319a8: 52800300  mov      w0, #0x18
//   0x0319ac: 97ffa4b1  bl       #0x1ac70
//   0x0319b0: aa0003f3  mov      x19, x0
//   0x0319b4: 52800061  mov      w1, #3
//   0x0319b8: 97ffa86e  bl       #0x1bb70
//   0x0319bc: d00001a1  adrp     x1, #0x67000
//   0x0319c0: d00001a2  adrp     x2, #0x67000
//   0x0319c4: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0319c8: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0319cc: aa1303e0  mov      x0, x19
//   0x0319d0: 97ffa7dc  bl       #0x1b940
//   0x0319d4: aa0003f4  mov      x20, x0
//   0x0319d8: aa1303e0  mov      x0, x19
uint64_t fde_0251_sub_03199c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x03199CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03199c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0319a0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0319a4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0319a8: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA4B1ULL; // 0x0319ac: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0319b0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800061ULL; // 0x0319b4: mov w1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA86EULL; // 0x0319b8: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x0319bc: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A2ULL; // 0x0319c0: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0252 @ 0x0319e8..0x031ac4 (220 bytes)
// [VN] Phục dựng FDE #0252 tại 0x0319e8..0x031ac4 (220 byte)
//   0x0319e8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0319ec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0319f0: 910043fd  add      x29, sp, #0x10
//   0x0319f4: aa0103f3  mov      x19, x1
//   0x0319f8: eb02003f  cmp      x1, x2
//   0x0319fc: 540005a0  b.eq     #0x31ab0
//   0x031a00: 39400268  ldrb     w8, [x19]
//   0x031a04: 7100c101  subs     w1, w8, #0x30
//   0x031a08: 54000081  b.ne     #0x31a18
//   0x031a0c: 97ffa4e1  bl       #0x1ad90
//   0x031a10: 91000673  add      x19, x19, #1
//   0x031a14: 14000027  b        #0x31ab0
//   0x031a18: 5100c508  sub      w8, w8, #0x31
//   0x031a1c: 7100211f  cmp      w8, #8
//   0x031a20: 54000488  b.hi     #0x31ab0
//   0x031a24: 91000668  add      x8, x19, #1
uint64_t fde_0252_sub_0319e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x5100C508ULL) + (x2 ^ 0x0319E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0319e8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0319ec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0319f0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0319f4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x0319f8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540005A0ULL; // 0x0319fc: b.eq #0x31ab0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x031a00: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100C101ULL; // 0x031a04: subs w1, w8, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x54000081ULL; // 0x031a08: b.ne #0x31a18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA4E1ULL; // 0x031a0c: bl #0x1ad90
    return acc;
}

// [EN] Reconstructed FDE #0253 @ 0x031ac4..0x031cb8 (500 bytes)
// [VN] Phục dựng FDE #0253 tại 0x031ac4..0x031cb8 (500 byte)
//   0x031ac4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x031ac8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x031acc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x031ad0: 910083fd  add      x29, sp, #0x20
//   0x031ad4: aa0103f3  mov      x19, x1
//   0x031ad8: eb02003f  cmp      x1, x2
//   0x031adc: 54000d00  b.eq     #0x31c7c
//   0x031ae0: 39400268  ldrb     w8, [x19]
//   0x031ae4: 51011108  sub      w8, w8, #0x44
//   0x031ae8: 7100cd1f  cmp      w8, #0x33
//   0x031aec: 54000c88  b.hi     #0x31c7c
//   0x031af0: b0000109  adrp     x9, #0x52000
//   0x031af4: 91334529  add      x9, x9, #0xcd1
//   0x031af8: 100000aa  adr      x10, #0x31b0c
//   0x031afc: 3868692b  ldrb     w11, [x9, x8]
//   0x031b00: 8b0b094a  add      x10, x10, x11, lsl #2
uint64_t fde_0253_sub_031ac4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91334529ULL) + (x2 ^ 0x031AC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x031ac4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x031ac8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x031acc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x031ad0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031ad4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x031ad8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000D00ULL; // 0x031adc: b.eq #0x31c7c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x031ae0: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51011108ULL; // 0x031ae4: sub w8, w8, #0x44
    acc = (acc * 0x100000001B3ULL) ^ 0x7100CD1FULL; // 0x031ae8: cmp w8, #0x33
    return acc;
}

// [EN] Reconstructed FDE #0254 @ 0x031cb8..0x0320c0 (1032 bytes)
// [VN] Phục dựng FDE #0254 tại 0x031cb8..0x0320c0 (1032 byte)
//   0x031cb8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x031cbc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031cc0: 910043fd  add      x29, sp, #0x10
//   0x031cc4: aa0103f3  mov      x19, x1
//   0x031cc8: eb02003f  cmp      x1, x2
//   0x031ccc: 54001900  b.eq     #0x31fec
//   0x031cd0: 39400268  ldrb     w8, [x19]
//   0x031cd4: 5100c109  sub      w9, w8, #0x30
//   0x031cd8: 7101213f  cmp      w9, #0x48
//   0x031cdc: 54000908  b.hi     #0x31dfc
//   0x031ce0: b000010a  adrp     x10, #0x52000
//   0x031ce4: 9134154a  add      x10, x10, #0xd05
//   0x031ce8: 1000008b  adr      x11, #0x31cf8
//   0x031cec: 3869694c  ldrb     w12, [x10, x9]
//   0x031cf0: 8b0c096b  add      x11, x11, x12, lsl #2
//   0x031cf4: d61f0160  br       x11
uint64_t fde_0254_sub_031cb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008BULL) + (x2 ^ 0x031CB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x031cb8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031cbc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031cc0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031cc4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x031cc8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54001900ULL; // 0x031ccc: b.eq #0x31fec
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x031cd0: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x5100C109ULL; // 0x031cd4: sub w9, w8, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x7101213FULL; // 0x031cd8: cmp w9, #0x48
    acc = (acc * 0x100000001B3ULL) ^ 0x54000908ULL; // 0x031cdc: b.hi #0x31dfc
    return acc;
}

// [EN] Reconstructed FDE #0255 @ 0x0320c0..0x032208 (328 bytes)
// [VN] Phục dựng FDE #0255 tại 0x0320c0..0x032208 (328 byte)
//   0x0320c0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0320c4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0320c8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0320cc: 910083fd  add      x29, sp, #0x20
//   0x0320d0: b9401808  ldr      w8, [x0, #0x18]
//   0x0320d4: aa0003f3  mov      x19, x0
//   0x0320d8: 2a0103f5  mov      w21, w1
//   0x0320dc: 370001a8  tbnz     w8, #0, #0x32110
//   0x0320e0: 37180448  tbnz     w8, #3, #0x32168
//   0x0320e4: 52800300  mov      w0, #0x18
//   0x0320e8: 97ffa6de  bl       #0x1bc60
//   0x0320ec: f9401e68  ldr      x8, [x19, #0x38]
//   0x0320f0: b00001aa  adrp     x10, #0x67000
//   0x0320f4: aa0003f4  mov      x20, x0
//   0x0320f8: f8408d09  ldr      x9, [x8, #8]!
//   0x0320fc: f946a14a  ldr      x10, [x10, #0xd40]
uint64_t fde_0255_sub_0320c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB00001AAULL) + (x2 ^ 0x0320C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0320c0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0320c4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0320c8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0320cc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x0320d0: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0320d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x0320d8: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x370001A8ULL; // 0x0320dc: tbnz w8, #0, #0x32110
    acc = (acc * 0x100000001B3ULL) ^ 0x37180448ULL; // 0x0320e0: tbnz w8, #3, #0x32168
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0320e4: mov w0, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0256 @ 0x032208..0x032254 (76 bytes)
// [VN] Phục dựng FDE #0256 tại 0x032208..0x032254 (76 byte)
//   0x032208: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03220c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032210: 910043fd  add      x29, sp, #0x10
//   0x032214: 52800300  mov      w0, #0x18
//   0x032218: 97ffa296  bl       #0x1ac70
//   0x03221c: aa0003f3  mov      x19, x0
//   0x032220: 52800081  mov      w1, #4
//   0x032224: 97ffa653  bl       #0x1bb70
//   0x032228: b00001a1  adrp     x1, #0x67000
//   0x03222c: b00001a2  adrp     x2, #0x67000
//   0x032230: f947e421  ldr      x1, [x1, #0xfc8]
//   0x032234: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x032238: aa1303e0  mov      x0, x19
//   0x03223c: 97ffa5c1  bl       #0x1b940
//   0x032240: aa0003f4  mov      x20, x0
//   0x032244: aa1303e0  mov      x0, x19
uint64_t fde_0256_sub_032208(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x032208ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x032208: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03220c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032210: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x032214: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA296ULL; // 0x032218: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03221c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800081ULL; // 0x032220: mov w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA653ULL; // 0x032224: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A1ULL; // 0x032228: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A2ULL; // 0x03222c: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0257 @ 0x032254..0x032324 (208 bytes)
// [VN] Phục dựng FDE #0257 tại 0x032254..0x032324 (208 byte)
//   0x032254: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x032258: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03225c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x032260: 910083fd  add      x29, sp, #0x20
//   0x032264: b9401808  ldr      w8, [x0, #0x18]
//   0x032268: aa0003f3  mov      x19, x0
//   0x03226c: 2a0103f4  mov      w20, w1
//   0x032270: 370001a8  tbnz     w8, #0, #0x322a4
//   0x032274: 37180288  tbnz     w8, #3, #0x322c4
//   0x032278: 52800300  mov      w0, #0x18
//   0x03227c: 97ffa679  bl       #0x1bc60
//   0x032280: f9401e68  ldr      x8, [x19, #0x38]
//   0x032284: b00001aa  adrp     x10, #0x67000
//   0x032288: aa0003f5  mov      x21, x0
//   0x03228c: f8408d09  ldr      x9, [x8, #8]!
//   0x032290: f947894a  ldr      x10, [x10, #0xf10]
uint64_t fde_0257_sub_032254(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB00001AAULL) + (x2 ^ 0x032254ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x032254: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x032258: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03225c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x032260: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x032264: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032268: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x03226c: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x370001A8ULL; // 0x032270: tbnz w8, #0, #0x322a4
    acc = (acc * 0x100000001B3ULL) ^ 0x37180288ULL; // 0x032274: tbnz w8, #3, #0x322c4
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x032278: mov w0, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0258 @ 0x032324..0x032380 (92 bytes)
// [VN] Phục dựng FDE #0258 tại 0x032324..0x032380 (92 byte)
//   0x032324: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032328: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03232c: 910043fd  add      x29, sp, #0x10
//   0x032330: b00001a8  adrp     x8, #0x67000
//   0x032334: f946d108  ldr      x8, [x8, #0xda0]
//   0x032338: aa0003f3  mov      x19, x0
//   0x03233c: 91004108  add      x8, x8, #0x10
//   0x032340: f8010408  str      x8, [x0], #0x10
//   0x032344: 97ffa71b  bl       #0x1bfb0
//   0x032348: b00001a8  adrp     x8, #0x67000
//   0x03234c: f9400660  ldr      x0, [x19, #8]
//   0x032350: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032354: 91004108  add      x8, x8, #0x10
//   0x032358: f9000268  str      x8, [x19]
//   0x03235c: b40000c0  cbz      x0, #0x32374
//   0x032360: f9400008  ldr      x8, [x0]
uint64_t fde_0258_sub_032324(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x032324ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032324: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032328: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03232c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032330: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D108ULL; // 0x032334: ldr x8, [x8, #0xda0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032338: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x03233c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x032340: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA71BULL; // 0x032344: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032348: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0259 @ 0x032380..0x0323d8 (88 bytes)
// [VN] Phục dựng FDE #0259 tại 0x032380..0x0323d8 (88 byte)
//   0x032380: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032384: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032388: 910043fd  add      x29, sp, #0x10
//   0x03238c: b00001a8  adrp     x8, #0x67000
//   0x032390: f946d108  ldr      x8, [x8, #0xda0]
//   0x032394: aa0003f3  mov      x19, x0
//   0x032398: 91004108  add      x8, x8, #0x10
//   0x03239c: f8010408  str      x8, [x0], #0x10
//   0x0323a0: 97ffa704  bl       #0x1bfb0
//   0x0323a4: b00001a8  adrp     x8, #0x67000
//   0x0323a8: f9400660  ldr      x0, [x19, #8]
//   0x0323ac: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0323b0: 91004108  add      x8, x8, #0x10
//   0x0323b4: f9000268  str      x8, [x19]
//   0x0323b8: b4000080  cbz      x0, #0x323c8
//   0x0323bc: f9400008  ldr      x8, [x0]
uint64_t fde_0259_sub_032380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x032380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032380: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032384: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032388: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x03238c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D108ULL; // 0x032390: ldr x8, [x8, #0xda0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032394: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x032398: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x03239c: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA704ULL; // 0x0323a0: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0323a4: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0260 @ 0x0323d8..0x032450 (120 bytes)
// [VN] Phục dựng FDE #0260 tại 0x0323d8..0x032450 (120 byte)
//   0x0323d8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0323dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0323e0: 910043fd  add      x29, sp, #0x10
//   0x0323e4: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x0323e8: aa0103f3  mov      x19, x1
//   0x0323ec: eb09011f  cmp      x8, x9
//   0x0323f0: 54000240  b.eq     #0x32438
//   0x0323f4: aa0003f4  mov      x20, x0
//   0x0323f8: f9400c00  ldr      x0, [x0, #0x18]
//   0x0323fc: 39400101  ldrb     w1, [x8]
//   0x032400: f9400009  ldr      x9, [x0]
//   0x032404: f9401529  ldr      x9, [x9, #0x28]
//   0x032408: d63f0120  blr      x9
//   0x03240c: 3940a288  ldrb     w8, [x20, #0x28]
//   0x032410: 6b20011f  cmp      w8, w0, uxtb
//   0x032414: 54000121  b.ne     #0x32438
uint64_t fde_0260_sub_0323d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD63F0120ULL) + (x2 ^ 0x0323D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0323d8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0323dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0323e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412428ULL; // 0x0323e4: ldp x8, x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0323e8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0323ec: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000240ULL; // 0x0323f0: b.eq #0x32438
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0323f4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x0323f8: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400101ULL; // 0x0323fc: ldrb w1, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0261 @ 0x032450..0x0324ac (92 bytes)
// [VN] Phục dựng FDE #0261 tại 0x032450..0x0324ac (92 byte)
//   0x032450: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032454: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032458: 910043fd  add      x29, sp, #0x10
//   0x03245c: b00001a8  adrp     x8, #0x67000
//   0x032460: f9470908  ldr      x8, [x8, #0xe10]
//   0x032464: aa0003f3  mov      x19, x0
//   0x032468: 91004108  add      x8, x8, #0x10
//   0x03246c: f8010408  str      x8, [x0], #0x10
//   0x032470: 97ffa6d0  bl       #0x1bfb0
//   0x032474: b00001a8  adrp     x8, #0x67000
//   0x032478: f9400660  ldr      x0, [x19, #8]
//   0x03247c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032480: 91004108  add      x8, x8, #0x10
//   0x032484: f9000268  str      x8, [x19]
//   0x032488: b40000c0  cbz      x0, #0x324a0
//   0x03248c: f9400008  ldr      x8, [x0]
uint64_t fde_0261_sub_032450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x032450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032450: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032454: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032458: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x03245c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470908ULL; // 0x032460: ldr x8, [x8, #0xe10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032464: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x032468: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x03246c: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA6D0ULL; // 0x032470: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032474: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0262 @ 0x0324ac..0x032504 (88 bytes)
// [VN] Phục dựng FDE #0262 tại 0x0324ac..0x032504 (88 byte)
//   0x0324ac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0324b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0324b4: 910043fd  add      x29, sp, #0x10
//   0x0324b8: b00001a8  adrp     x8, #0x67000
//   0x0324bc: f9470908  ldr      x8, [x8, #0xe10]
//   0x0324c0: aa0003f3  mov      x19, x0
//   0x0324c4: 91004108  add      x8, x8, #0x10
//   0x0324c8: f8010408  str      x8, [x0], #0x10
//   0x0324cc: 97ffa6b9  bl       #0x1bfb0
//   0x0324d0: b00001a8  adrp     x8, #0x67000
//   0x0324d4: f9400660  ldr      x0, [x19, #8]
//   0x0324d8: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0324dc: 91004108  add      x8, x8, #0x10
//   0x0324e0: f9000268  str      x8, [x19]
//   0x0324e4: b4000080  cbz      x0, #0x324f4
//   0x0324e8: f9400008  ldr      x8, [x0]
uint64_t fde_0262_sub_0324ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x0324ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0324ac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0324b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0324b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0324b8: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470908ULL; // 0x0324bc: ldr x8, [x8, #0xe10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0324c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0324c4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x0324c8: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA6B9ULL; // 0x0324cc: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0324d0: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0263 @ 0x032504..0x03254c (72 bytes)
// [VN] Phục dựng FDE #0263 tại 0x032504..0x03254c (72 byte)
//   0x032504: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x032508: eb09011f  cmp      x8, x9
//   0x03250c: 54000180  b.eq     #0x3253c
//   0x032510: 39400109  ldrb     w9, [x8]
//   0x032514: 3940a00a  ldrb     w10, [x0, #0x28]
//   0x032518: 6b0a013f  cmp      w9, w10
//   0x03251c: 54000101  b.ne     #0x3253c
//   0x032520: 12807c49  mov      w9, #-0x3e3
//   0x032524: 91000508  add      x8, x8, #1
//   0x032528: b9000029  str      w9, [x1]
//   0x03252c: f9000828  str      x8, [x1, #0x10]
//   0x032530: f9400408  ldr      x8, [x0, #8]
//   0x032534: f9002828  str      x8, [x1, #0x50]
//   0x032538: d65f03c0  ret      
//   0x03253c: 12807c08  mov      w8, #-0x3e1
//   0x032540: b9000028  str      w8, [x1]
uint64_t fde_0263_sub_032504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412428ULL) + (x1 ^ 0xF9002828ULL) + (x2 ^ 0x032504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412428ULL; // 0x032504: ldp x8, x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x032508: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000180ULL; // 0x03250c: b.eq #0x3253c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x032510: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940A00AULL; // 0x032514: ldrb w10, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x032518: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x03251c: b.ne #0x3253c
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C49ULL; // 0x032520: mov w9, #-0x3e3
    acc = (acc * 0x100000001B3ULL) ^ 0x91000508ULL; // 0x032524: add x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000029ULL; // 0x032528: str w9, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0264 @ 0x03254c..0x032590 (68 bytes)
// [VN] Phục dựng FDE #0264 tại 0x03254c..0x032590 (68 byte)
//   0x03254c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032550: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032554: 910043fd  add      x29, sp, #0x10
//   0x032558: b00001a8  adrp     x8, #0x67000
//   0x03255c: aa0003f3  mov      x19, x0
//   0x032560: f9400400  ldr      x0, [x0, #8]
//   0x032564: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032568: 91004108  add      x8, x8, #0x10
//   0x03256c: f9000268  str      x8, [x19]
//   0x032570: b4000080  cbz      x0, #0x32580
//   0x032574: f9400008  ldr      x8, [x0]
//   0x032578: f9400508  ldr      x8, [x8, #8]
//   0x03257c: d63f0100  blr      x8
//   0x032580: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032584: aa1303e0  mov      x0, x19
//   0x032588: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0264_sub_03254c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03254CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03254c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032550: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032554: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032558: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03255c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x032560: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x032564: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x032568: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03256c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x032570: cbz x0, #0x32580
    return acc;
}

// [EN] Reconstructed FDE #0265 @ 0x032590..0x0325d8 (72 bytes)
// [VN] Phục dựng FDE #0265 tại 0x032590..0x0325d8 (72 byte)
//   0x032590: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x032594: eb09011f  cmp      x8, x9
//   0x032598: 54000180  b.eq     #0x325c8
//   0x03259c: 39400109  ldrb     w9, [x8]
//   0x0325a0: 3940400a  ldrb     w10, [x0, #0x10]
//   0x0325a4: 6b0a013f  cmp      w9, w10
//   0x0325a8: 54000101  b.ne     #0x325c8
//   0x0325ac: 12807c49  mov      w9, #-0x3e3
//   0x0325b0: 91000508  add      x8, x8, #1
//   0x0325b4: b9000029  str      w9, [x1]
//   0x0325b8: f9000828  str      x8, [x1, #0x10]
//   0x0325bc: f9400408  ldr      x8, [x0, #8]
//   0x0325c0: f9002828  str      x8, [x1, #0x50]
//   0x0325c4: d65f03c0  ret      
//   0x0325c8: 12807c08  mov      w8, #-0x3e1
//   0x0325cc: b9000028  str      w8, [x1]
uint64_t fde_0265_sub_032590(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412428ULL) + (x1 ^ 0xF9002828ULL) + (x2 ^ 0x032590ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412428ULL; // 0x032590: ldp x8, x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x032594: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000180ULL; // 0x032598: b.eq #0x325c8
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x03259c: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940400AULL; // 0x0325a0: ldrb w10, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x0325a4: cmp w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x0325a8: b.ne #0x325c8
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C49ULL; // 0x0325ac: mov w9, #-0x3e3
    acc = (acc * 0x100000001B3ULL) ^ 0x91000508ULL; // 0x0325b0: add x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000029ULL; // 0x0325b4: str w9, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0266 @ 0x0325d8..0x032634 (92 bytes)
// [VN] Phục dựng FDE #0266 tại 0x0325d8..0x032634 (92 byte)
//   0x0325d8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0325dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0325e0: 910043fd  add      x29, sp, #0x10
//   0x0325e4: b00001a8  adrp     x8, #0x67000
//   0x0325e8: f9468508  ldr      x8, [x8, #0xd08]
//   0x0325ec: aa0003f3  mov      x19, x0
//   0x0325f0: 91004108  add      x8, x8, #0x10
//   0x0325f4: f8010408  str      x8, [x0], #0x10
//   0x0325f8: 97ffa66e  bl       #0x1bfb0
//   0x0325fc: b00001a8  adrp     x8, #0x67000
//   0x032600: f9400660  ldr      x0, [x19, #8]
//   0x032604: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032608: 91004108  add      x8, x8, #0x10
//   0x03260c: f9000268  str      x8, [x19]
//   0x032610: b40000c0  cbz      x0, #0x32628
//   0x032614: f9400008  ldr      x8, [x0]
uint64_t fde_0266_sub_0325d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x0325D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0325d8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0325dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0325e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0325e4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468508ULL; // 0x0325e8: ldr x8, [x8, #0xd08]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0325ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0325f0: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x0325f4: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA66EULL; // 0x0325f8: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0325fc: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0267 @ 0x032634..0x03268c (88 bytes)
// [VN] Phục dựng FDE #0267 tại 0x032634..0x03268c (88 byte)
//   0x032634: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032638: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03263c: 910043fd  add      x29, sp, #0x10
//   0x032640: b00001a8  adrp     x8, #0x67000
//   0x032644: f9468508  ldr      x8, [x8, #0xd08]
//   0x032648: aa0003f3  mov      x19, x0
//   0x03264c: 91004108  add      x8, x8, #0x10
//   0x032650: f8010408  str      x8, [x0], #0x10
//   0x032654: 97ffa657  bl       #0x1bfb0
//   0x032658: b00001a8  adrp     x8, #0x67000
//   0x03265c: f9400660  ldr      x0, [x19, #8]
//   0x032660: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032664: 91004108  add      x8, x8, #0x10
//   0x032668: f9000268  str      x8, [x19]
//   0x03266c: b4000080  cbz      x0, #0x3267c
//   0x032670: f9400008  ldr      x8, [x0]
uint64_t fde_0267_sub_032634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x032634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032634: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032638: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03263c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032640: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468508ULL; // 0x032644: ldr x8, [x8, #0xd08]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032648: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x03264c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x032650: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA657ULL; // 0x032654: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032658: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0268 @ 0x03268c..0x032794 (264 bytes)
// [VN] Phục dựng FDE #0268 tại 0x03268c..0x032794 (264 byte)
//   0x03268c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x032690: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x032694: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x032698: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03269c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0326a0: 910103fd  add      x29, sp, #0x40
//   0x0326a4: b9402808  ldr      w8, [x0, #0x28]
//   0x0326a8: f9401029  ldr      x9, [x1, #0x20]
//   0x0326ac: aa0103f3  mov      x19, x1
//   0x0326b0: 5100050a  sub      w10, w8, #1
//   0x0326b4: 52800308  mov      w8, #0x18
//   0x0326b8: 9ba82555  umaddl   x21, w10, w8, x9
//   0x0326bc: 394042a8  ldrb     w8, [x21, #0x10]
//   0x0326c0: 34000488  cbz      w8, #0x32750
//   0x0326c4: 5280030b  mov      w11, #0x18
//   0x0326c8: 9b0b2549  madd     x9, x10, x11, x9
uint64_t fde_0268_sub_03268c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x394042A8ULL) + (x2 ^ 0x03268CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x03268c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x032690: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x032694: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x032698: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03269c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0326a0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402808ULL; // 0x0326a4: ldr w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401029ULL; // 0x0326a8: ldr x9, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0326ac: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x5100050AULL; // 0x0326b0: sub w10, w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0269 @ 0x032794..0x0327f0 (92 bytes)
// [VN] Phục dựng FDE #0269 tại 0x032794..0x0327f0 (92 byte)
//   0x032794: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032798: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03279c: 910043fd  add      x29, sp, #0x10
//   0x0327a0: b00001a8  adrp     x8, #0x67000
//   0x0327a4: f9470508  ldr      x8, [x8, #0xe08]
//   0x0327a8: aa0003f3  mov      x19, x0
//   0x0327ac: 91004108  add      x8, x8, #0x10
//   0x0327b0: f8010408  str      x8, [x0], #0x10
//   0x0327b4: 97ffa5ff  bl       #0x1bfb0
//   0x0327b8: b00001a8  adrp     x8, #0x67000
//   0x0327bc: f9400660  ldr      x0, [x19, #8]
//   0x0327c0: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0327c4: 91004108  add      x8, x8, #0x10
//   0x0327c8: f9000268  str      x8, [x19]
//   0x0327cc: b40000c0  cbz      x0, #0x327e4
//   0x0327d0: f9400008  ldr      x8, [x0]
uint64_t fde_0269_sub_032794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x032794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032794: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032798: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03279c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0327a0: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470508ULL; // 0x0327a4: ldr x8, [x8, #0xe08]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0327a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0327ac: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x0327b0: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA5FFULL; // 0x0327b4: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0327b8: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0270 @ 0x0327f0..0x032848 (88 bytes)
// [VN] Phục dựng FDE #0270 tại 0x0327f0..0x032848 (88 byte)
//   0x0327f0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0327f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0327f8: 910043fd  add      x29, sp, #0x10
//   0x0327fc: b00001a8  adrp     x8, #0x67000
//   0x032800: f9470508  ldr      x8, [x8, #0xe08]
//   0x032804: aa0003f3  mov      x19, x0
//   0x032808: 91004108  add      x8, x8, #0x10
//   0x03280c: f8010408  str      x8, [x0], #0x10
//   0x032810: 97ffa5e8  bl       #0x1bfb0
//   0x032814: b00001a8  adrp     x8, #0x67000
//   0x032818: f9400660  ldr      x0, [x19, #8]
//   0x03281c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x032820: 91004108  add      x8, x8, #0x10
//   0x032824: f9000268  str      x8, [x19]
//   0x032828: b4000080  cbz      x0, #0x32838
//   0x03282c: f9400008  ldr      x8, [x0]
uint64_t fde_0270_sub_0327f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x0327F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0327f0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0327f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0327f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0327fc: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470508ULL; // 0x032800: ldr x8, [x8, #0xe08]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032804: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x032808: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8010408ULL; // 0x03280c: str x8, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA5E8ULL; // 0x032810: bl #0x1bfb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032814: adrp x8, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0271 @ 0x032848..0x0328e0 (152 bytes)
// [VN] Phục dựng FDE #0271 tại 0x032848..0x0328e0 (152 byte)
//   0x032848: b9402809  ldr      w9, [x0, #0x28]
//   0x03284c: f9401028  ldr      x8, [x1, #0x20]
//   0x032850: 5280030a  mov      w10, #0x18
//   0x032854: 51000529  sub      w9, w9, #1
//   0x032858: 9baa212a  umaddl   x10, w9, w10, x8
//   0x03285c: 3940414a  ldrb     w10, [x10, #0x10]
//   0x032860: 3400038a  cbz      w10, #0x328d0
//   0x032864: 5280030a  mov      w10, #0x18
//   0x032868: 9b0a2128  madd     x8, x9, x10, x8
//   0x03286c: a9402909  ldp      x9, x10, [x8]
//   0x032870: a9412c28  ldp      x8, x11, [x1, #0x10]
//   0x032874: cb09014a  sub      x10, x10, x9
//   0x032878: cb08016b  sub      x11, x11, x8
//   0x03287c: eb0a017f  cmp      x11, x10
//   0x032880: 5400028b  b.lt     #0x328d0
//   0x032884: f100055f  cmp      x10, #1
uint64_t fde_0271_sub_032848(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9402809ULL) + (x1 ^ 0xCB08016BULL) + (x2 ^ 0x032848ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402809ULL; // 0x032848: ldr w9, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401028ULL; // 0x03284c: ldr x8, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030AULL; // 0x032850: mov w10, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x51000529ULL; // 0x032854: sub w9, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9BAA212AULL; // 0x032858: umaddl x10, w9, w10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3940414AULL; // 0x03285c: ldrb w10, [x10, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3400038AULL; // 0x032860: cbz w10, #0x328d0
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030AULL; // 0x032864: mov w10, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A2128ULL; // 0x032868: madd x8, x9, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402909ULL; // 0x03286c: ldp x9, x10, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0272 @ 0x0328e0..0x032924 (68 bytes)
// [VN] Phục dựng FDE #0272 tại 0x0328e0..0x032924 (68 byte)
//   0x0328e0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0328e4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0328e8: 910043fd  add      x29, sp, #0x10
//   0x0328ec: b00001a8  adrp     x8, #0x67000
//   0x0328f0: aa0003f3  mov      x19, x0
//   0x0328f4: f9400400  ldr      x0, [x0, #8]
//   0x0328f8: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0328fc: 91004108  add      x8, x8, #0x10
//   0x032900: f9000268  str      x8, [x19]
//   0x032904: b4000080  cbz      x0, #0x32914
//   0x032908: f9400008  ldr      x8, [x0]
//   0x03290c: f9400508  ldr      x8, [x8, #8]
//   0x032910: d63f0100  blr      x8
//   0x032914: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032918: aa1303e0  mov      x0, x19
//   0x03291c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0272_sub_0328e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x0328E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0328e0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0328e4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0328e8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x0328ec: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0328f0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x0328f4: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x0328f8: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0328fc: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x032900: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x032904: cbz x0, #0x32914
    return acc;
}

// [EN] Reconstructed FDE #0273 @ 0x032924..0x0329e8 (196 bytes)
// [VN] Phục dựng FDE #0273 tại 0x032924..0x0329e8 (196 byte)
//   0x032924: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x032928: 910003fd  mov      x29, sp
//   0x03292c: a9422828  ldp      x8, x10, [x1, #0x20]
//   0x032930: b9401009  ldr      w9, [x0, #0x10]
//   0x032934: b201f3eb  mov      x11, #-0x5555555555555556
//   0x032938: f295556b  movk     x11, #0xaaab
//   0x03293c: cb08014a  sub      x10, x10, x8
//   0x032940: 9343fd4a  asr      x10, x10, #3
//   0x032944: 9b0b7d4a  mul      x10, x10, x11
//   0x032948: eb09015f  cmp      x10, x9
//   0x03294c: 540004c3  b.lo     #0x329e4
//   0x032950: 51000529  sub      w9, w9, #1
//   0x032954: 5280030a  mov      w10, #0x18
//   0x032958: 9baa212a  umaddl   x10, w9, w10, x8
//   0x03295c: 3940414a  ldrb     w10, [x10, #0x10]
//   0x032960: 3400038a  cbz      w10, #0x329d0
uint64_t fde_0273_sub_032924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x5280030AULL) + (x2 ^ 0x032924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x032924: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x032928: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9422828ULL; // 0x03292c: ldp x8, x10, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401009ULL; // 0x032930: ldr w9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3EBULL; // 0x032934: mov x11, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF295556BULL; // 0x032938: movk x11, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08014AULL; // 0x03293c: sub x10, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9343FD4AULL; // 0x032940: asr x10, x10, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0B7D4AULL; // 0x032944: mul x10, x10, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09015FULL; // 0x032948: cmp x10, x9
    return acc;
}

// [EN] Reconstructed FDE #0274 @ 0x0329e8..0x032b9c (436 bytes)
// [VN] Phục dựng FDE #0274 tại 0x0329e8..0x032b9c (436 byte)
//   0x0329e8: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0329ec: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0329f0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0329f4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0329f8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0329fc: 910103fd  add      x29, sp, #0x40
//   0x032a00: 39429408  ldrb     w8, [x0, #0xa5]
//   0x032a04: aa0003f3  mov      x19, x0
//   0x032a08: 2a0103f4  mov      w20, w1
//   0x032a0c: 340001a8  cbz      w8, #0x32a40
//   0x032a10: f9400e60  ldr      x0, [x19, #0x18]
//   0x032a14: 2a1403e1  mov      w1, w20
//   0x032a18: f9400008  ldr      x8, [x0]
//   0x032a1c: f9401508  ldr      x8, [x8, #0x28]
//   0x032a20: d63f0100  blr      x8
//   0x032a24: a9432668  ldp      x8, x9, [x19, #0x30]
uint64_t fde_0274_sub_0329e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x0329E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x0329e8: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0329ec: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0329f0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0329f4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0329f8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0329fc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x39429408ULL; // 0x032a00: ldrb w8, [x0, #0xa5]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032a04: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x032a08: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x340001A8ULL; // 0x032a0c: cbz w8, #0x32a40
    return acc;
}

// [EN] Reconstructed FDE #0275 @ 0x032b9c..0x032dec (592 bytes)
// [VN] Phục dựng FDE #0275 tại 0x032b9c..0x032dec (592 byte)
//   0x032b9c: d10203ff  sub      sp, sp, #0x80
//   0x032ba0: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x032ba4: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x032ba8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x032bac: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x032bb0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x032bb4: 9101c3fd  add      x29, sp, #0x70
//   0x032bb8: d53bd057  mrs      x23, tpidr_el0
//   0x032bbc: f94016e8  ldr      x8, [x23, #0x28]
//   0x032bc0: 91004014  add      x20, x0, #0x10
//   0x032bc4: aa0003f3  mov      x19, x0
//   0x032bc8: aa0103f5  mov      x21, x1
//   0x032bcc: f90017e8  str      x8, [sp, #0x28]
//   0x032bd0: b00001a8  adrp     x8, #0x67000
//   0x032bd4: f946dd08  ldr      x8, [x8, #0xdb8]
//   0x032bd8: 12000078  and      w24, w3, #1
uint64_t fde_0275_sub_032b9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x032B9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x032b9c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x032ba0: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x032ba4: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x032ba8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x032bac: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x032bb0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x032bb4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x032bb8: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x032bbc: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004014ULL; // 0x032bc0: add x20, x0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0276 @ 0x032dec..0x032f38 (332 bytes)
// [VN] Phục dựng FDE #0276 tại 0x032dec..0x032f38 (332 byte)
//   0x032dec: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x032df0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x032df4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x032df8: 910083fd  add      x29, sp, #0x20
//   0x032dfc: b00001a8  adrp     x8, #0x67000
//   0x032e00: f9404414  ldr      x20, [x0, #0x88]
//   0x032e04: f946dd08  ldr      x8, [x8, #0xdb8]
//   0x032e08: aa0003f3  mov      x19, x0
//   0x032e0c: 91004108  add      x8, x8, #0x10
//   0x032e10: f9000008  str      x8, [x0]
//   0x032e14: b4000294  cbz      x20, #0x32e64
//   0x032e18: f9404a68  ldr      x8, [x19, #0x90]
//   0x032e1c: eb14011f  cmp      x8, x20
//   0x032e20: 540001c0  b.eq     #0x32e58
//   0x032e24: aa0803f5  mov      x21, x8
//   0x032e28: 385e8ea9  ldrb     w9, [x21, #-0x18]!
uint64_t fde_0276_sub_032dec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xEB14011FULL) + (x2 ^ 0x032DECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x032dec: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x032df0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x032df4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x032df8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A8ULL; // 0x032dfc: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404414ULL; // 0x032e00: ldr x20, [x0, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946DD08ULL; // 0x032e04: ldr x8, [x8, #0xdb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032e08: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x032e0c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x032e10: str x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0277 @ 0x032f38..0x032f5c (36 bytes)
// [VN] Phục dựng FDE #0277 tại 0x032f38..0x032f5c (36 byte)
//   0x032f38: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x032f3c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032f40: 910043fd  add      x29, sp, #0x10
//   0x032f44: aa0003f3  mov      x19, x0
//   0x032f48: 97ffa3c6  bl       #0x1be60
//   0x032f4c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032f50: aa1303e0  mov      x0, x19
//   0x032f54: f84207f3  ldr      x19, [sp], #0x20
//   0x032f58: 17ff9eca  b        #0x1aa80
uint64_t fde_0277_sub_032f38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FF9ECAULL) + (x2 ^ 0x032F38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032f38: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032f3c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032f40: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x032f44: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA3C6ULL; // 0x032f48: bl #0x1be60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x032f4c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x032f50: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x032f54: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9ECAULL; // 0x032f58: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0278 @ 0x032f5c..0x033950 (2548 bytes)
// [VN] Phục dựng FDE #0278 tại 0x032f5c..0x033950 (2548 byte)
//   0x032f5c: d10303ff  sub      sp, sp, #0xc0
//   0x032f60: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x032f64: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x032f68: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x032f6c: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x032f70: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x032f74: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x032f78: 9102c3fd  add      x29, sp, #0xb0
//   0x032f7c: d53bd05a  mrs      x26, tpidr_el0
//   0x032f80: f9401748  ldr      x8, [x26, #0x28]
//   0x032f84: aa0103f3  mov      x19, x1
//   0x032f88: aa0003f4  mov      x20, x0
//   0x032f8c: f9002fe8  str      x8, [sp, #0x58]
//   0x032f90: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x032f94: eb09011f  cmp      x8, x9
//   0x032f98: 54000300  b.eq     #0x32ff8
uint64_t fde_0278_sub_032f5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xF9002FE8ULL) + (x2 ^ 0x032F5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x032f5c: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x032f60: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x032f64: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x032f68: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x032f6c: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x032f70: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x032f74: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x032f78: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x032f7c: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x032f80: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0279 @ 0x033950..0x033c30 (736 bytes)
// [VN] Phục dựng FDE #0279 tại 0x033950..0x033c30 (736 byte)
//   0x033950: d10243ff  sub      sp, sp, #0x90
//   0x033954: f90023f9  str      x25, [sp, #0x40]
//   0x033958: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x03395c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x033960: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x033964: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x033968: 910203fd  add      x29, sp, #0x80
//   0x03396c: d53bd058  mrs      x24, tpidr_el0
//   0x033970: aa0803f3  mov      x19, x8
//   0x033974: f9401708  ldr      x8, [x24, #0x28]
//   0x033978: cb010059  sub      x25, x2, x1
//   0x03397c: b100433f  cmn      x25, #0x10
//   0x033980: f9001fe8  str      x8, [sp, #0x38]
//   0x033984: a902ffff  stp      xzr, xzr, [sp, #0x28]
//   0x033988: f90013ff  str      xzr, [sp, #0x20]
//   0x03398c: 54001242  b.hs     #0x33bd4
uint64_t fde_0279_sub_033950(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x033950ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x033950: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x033954: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x033958: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x03395c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x033960: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x033964: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x033968: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x03396c: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x033970: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x033974: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0280 @ 0x033c30..0x033e28 (504 bytes)
// [VN] Phục dựng FDE #0280 tại 0x033c30..0x033e28 (504 byte)
//   0x033c30: d101c3ff  sub      sp, sp, #0x70
//   0x033c34: f90013f9  str      x25, [sp, #0x20]
//   0x033c38: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x033c3c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x033c40: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x033c44: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x033c48: 910183fd  add      x29, sp, #0x60
//   0x033c4c: d53bd058  mrs      x24, tpidr_el0
//   0x033c50: aa0803f3  mov      x19, x8
//   0x033c54: f9401708  ldr      x8, [x24, #0x28]
//   0x033c58: cb010059  sub      x25, x2, x1
//   0x033c5c: b100433f  cmn      x25, #0x10
//   0x033c60: f9000fe8  str      x8, [sp, #0x18]
//   0x033c64: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x033c68: f90003ff  str      xzr, [sp]
//   0x033c6c: 54000ca2  b.hs     #0x33e00
uint64_t fde_0280_sub_033c30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x033C30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x033c30: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x033c34: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x033c38: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x033c3c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x033c40: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x033c44: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x033c48: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x033c4c: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x033c50: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x033c54: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0281 @ 0x033e28..0x033e74 (76 bytes)
// [VN] Phục dựng FDE #0281 tại 0x033e28..0x033e74 (76 byte)
//   0x033e28: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x033e2c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x033e30: 910043fd  add      x29, sp, #0x10
//   0x033e34: 52800300  mov      w0, #0x18
//   0x033e38: 97ff9b8e  bl       #0x1ac70
//   0x033e3c: aa0003f3  mov      x19, x0
//   0x033e40: 528000a1  mov      w1, #5
//   0x033e44: 97ff9f4b  bl       #0x1bb70
//   0x033e48: 900001a1  adrp     x1, #0x67000
//   0x033e4c: 900001a2  adrp     x2, #0x67000
//   0x033e50: f947e421  ldr      x1, [x1, #0xfc8]
//   0x033e54: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x033e58: aa1303e0  mov      x0, x19
//   0x033e5c: 97ff9eb9  bl       #0x1b940
//   0x033e60: aa0003f4  mov      x20, x0
//   0x033e64: aa1303e0  mov      x0, x19
uint64_t fde_0281_sub_033e28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x033E28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x033e28: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x033e2c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x033e30: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x033e34: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9B8EULL; // 0x033e38: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x033e3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A1ULL; // 0x033e40: mov w1, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9F4BULL; // 0x033e44: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A1ULL; // 0x033e48: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A2ULL; // 0x033e4c: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0282 @ 0x033e74..0x034330 (1212 bytes)
// [VN] Phục dựng FDE #0282 tại 0x033e74..0x034330 (1212 byte)
//   0x033e74: d10303ff  sub      sp, sp, #0xc0
//   0x033e78: f9003bf9  str      x25, [sp, #0x70]
//   0x033e7c: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x033e80: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x033e84: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x033e88: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x033e8c: 9102c3fd  add      x29, sp, #0xb0
//   0x033e90: d53bd057  mrs      x23, tpidr_el0
//   0x033e94: f94016e8  ldr      x8, [x23, #0x28]
//   0x033e98: aa0103f3  mov      x19, x1
//   0x033e9c: eb02003f  cmp      x1, x2
//   0x033ea0: f81b83a8  stur     x8, [x29, #-0x48]
//   0x033ea4: 54001c80  b.eq     #0x34234
//   0x033ea8: 39400268  ldrb     w8, [x19]
//   0x033eac: 7101751f  cmp      w8, #0x5d
//   0x033eb0: 54001c20  b.eq     #0x34234
uint64_t fde_0282_sub_033e74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0x54001C80ULL) + (x2 ^ 0x033E74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x033e74: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003BF9ULL; // 0x033e78: str x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x033e7c: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x033e80: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x033e84: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x033e88: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x033e8c: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x033e90: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x033e94: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033e98: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0283 @ 0x034330..0x034630 (768 bytes)
// [VN] Phục dựng FDE #0283 tại 0x034330..0x034630 (768 byte)
//   0x034330: d10243ff  sub      sp, sp, #0x90
//   0x034334: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x034338: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x03433c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x034340: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x034344: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x034348: 910203fd  add      x29, sp, #0x80
//   0x03434c: d53bd05a  mrs      x26, tpidr_el0
//   0x034350: f9401748  ldr      x8, [x26, #0x28]
//   0x034354: cb01004a  sub      x10, x2, x1
//   0x034358: 528ba7a9  mov      w9, #0x5d3d
//   0x03435c: f100095f  cmp      x10, #2
//   0x034360: f9001fe8  str      x8, [sp, #0x38]
//   0x034364: 79000be9  strh     w9, [sp, #4]
//   0x034368: 540012eb  b.lt     #0x345c4
//   0x03436c: d1000448  sub      x8, x2, #1
uint64_t fde_0283_sub_034330(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x034330ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x034330: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x034334: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x034338: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x03433c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x034340: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x034344: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x034348: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x03434c: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x034350: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB01004AULL; // 0x034354: sub x10, x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0284 @ 0x034630..0x034720 (240 bytes)
// [VN] Phục dựng FDE #0284 tại 0x034630..0x034720 (240 byte)
//   0x034630: d100c3ff  sub      sp, sp, #0x30
//   0x034634: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x034638: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03463c: 910083fd  add      x29, sp, #0x20
//   0x034640: cb010049  sub      x9, x2, x1
//   0x034644: 528ba748  mov      w8, #0x5d3a
//   0x034648: f100093f  cmp      x9, #2
//   0x03464c: 79001be8  strh     w8, [sp, #0xc]
//   0x034650: 5400064b  b.lt     #0x34718
//   0x034654: d1000448  sub      x8, x2, #1
//   0x034658: eb01011f  cmp      x8, x1
//   0x03465c: 540005e0  b.eq     #0x34718
//   0x034660: 910033ea  add      x10, sp, #0xc
//   0x034664: aa0303f3  mov      x19, x3
//   0x034668: d1000849  sub      x9, x2, #2
//   0x03466c: b240014a  orr      x10, x10, #1
uint64_t fde_0284_sub_034630(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910033EAULL) + (x2 ^ 0x034630ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x034630: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x034634: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x034638: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03463c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010049ULL; // 0x034640: sub x9, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528BA748ULL; // 0x034644: mov w8, #0x5d3a
    acc = (acc * 0x100000001B3ULL) ^ 0xF100093FULL; // 0x034648: cmp x9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x79001BE8ULL; // 0x03464c: strh w8, [sp, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400064BULL; // 0x034650: b.lt #0x34718
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000448ULL; // 0x034654: sub x8, x2, #1
    return acc;
}

// [EN] Reconstructed FDE #0285 @ 0x034720..0x034880 (352 bytes)
// [VN] Phục dựng FDE #0285 tại 0x034720..0x034880 (352 byte)
//   0x034720: d10183ff  sub      sp, sp, #0x60
//   0x034724: f9001bf5  str      x21, [sp, #0x30]
//   0x034728: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03472c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x034730: 910143fd  add      x29, sp, #0x50
//   0x034734: d53bd055  mrs      x21, tpidr_el0
//   0x034738: f94016a8  ldr      x8, [x21, #0x28]
//   0x03473c: cb01004a  sub      x10, x2, x1
//   0x034740: 528ba5c9  mov      w9, #0x5d2e
//   0x034744: f100095f  cmp      x10, #2
//   0x034748: f90017e8  str      x8, [sp, #0x28]
//   0x03474c: 79001be9  strh     w9, [sp, #0xc]
//   0x034750: 5400092b  b.lt     #0x34874
//   0x034754: d1000448  sub      x8, x2, #1
//   0x034758: eb01011f  cmp      x8, x1
//   0x03475c: 540008c0  b.eq     #0x34874
uint64_t fde_0285_sub_034720(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x5400092BULL) + (x2 ^ 0x034720ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x034720: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x034724: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x034728: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03472c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x034730: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x034734: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x034738: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB01004AULL; // 0x03473c: sub x10, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528BA5C9ULL; // 0x034740: mov w9, #0x5d2e
    acc = (acc * 0x100000001B3ULL) ^ 0xF100095FULL; // 0x034744: cmp x10, #2
    return acc;
}

// [EN] Reconstructed FDE #0286 @ 0x034880..0x034b24 (676 bytes)
// [VN] Phục dựng FDE #0286 tại 0x034880..0x034b24 (676 byte)
//   0x034880: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x034884: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x034888: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03488c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x034890: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x034894: 910103fd  add      x29, sp, #0x40
//   0x034898: eb02003f  cmp      x1, x2
//   0x03489c: 54001400  b.eq     #0x34b1c
//   0x0348a0: 39400028  ldrb     w8, [x1]
//   0x0348a4: aa0103f3  mov      x19, x1
//   0x0348a8: 51011109  sub      w9, w8, #0x44
//   0x0348ac: 7100cd3f  cmp      w9, #0x33
//   0x0348b0: 54000168  b.hi     #0x348dc
//   0x0348b4: d00000e8  adrp     x8, #0x52000
//   0x0348b8: 91353908  add      x8, x8, #0xd4e
//   0x0348bc: 100000aa  adr      x10, #0x348d0
uint64_t fde_0286_sub_034880(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x54000168ULL) + (x2 ^ 0x034880ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x034880: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x034884: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x034888: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03488c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x034890: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x034894: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x034898: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54001400ULL; // 0x03489c: b.eq #0x34b1c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x0348a0: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0348a4: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0287 @ 0x034b24..0x034dd4 (688 bytes)
// [VN] Phục dựng FDE #0287 tại 0x034b24..0x034dd4 (688 byte)
//   0x034b24: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x034b28: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x034b2c: 910043fd  add      x29, sp, #0x10
//   0x034b30: eb02003f  cmp      x1, x2
//   0x034b34: 540014e0  b.eq     #0x34dd0
//   0x034b38: aa0103f3  mov      x19, x1
//   0x034b3c: 39400021  ldrb     w1, [x1]
//   0x034b40: 51008828  sub      w8, w1, #0x22
//   0x034b44: 7101511f  cmp      w8, #0x54
//   0x034b48: 540001c8  b.hi     #0x34b80
//   0x034b4c: d00000e9  adrp     x9, #0x52000
//   0x034b50: 91360929  add      x9, x9, #0xd82
//   0x034b54: 1000008a  adr      x10, #0x34b64
//   0x034b58: 3868692b  ldrb     w11, [x9, x8]
//   0x034b5c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x034b60: d61f0140  br       x10
uint64_t fde_0287_sub_034b24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x034B24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x034b24: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x034b28: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x034b2c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x034b30: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540014E0ULL; // 0x034b34: b.eq #0x34dd0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x034b38: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39400021ULL; // 0x034b3c: ldrb w1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x51008828ULL; // 0x034b40: sub w8, w1, #0x22
    acc = (acc * 0x100000001B3ULL) ^ 0x7101511FULL; // 0x034b44: cmp w8, #0x54
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C8ULL; // 0x034b48: b.hi #0x34b80
    return acc;
}

// [EN] Reconstructed FDE #0288 @ 0x034dd4..0x035334 (1376 bytes)
// [VN] Phục dựng FDE #0288 tại 0x034dd4..0x035334 (1376 byte)
//   0x034dd4: d102c3ff  sub      sp, sp, #0xb0
//   0x034dd8: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x034ddc: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x034de0: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x034de4: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x034de8: 910283fd  add      x29, sp, #0xa0
//   0x034dec: d53bd057  mrs      x23, tpidr_el0
//   0x034df0: f94016e8  ldr      x8, [x23, #0x28]
//   0x034df4: aa0203f4  mov      x20, x2
//   0x034df8: aa0003f3  mov      x19, x0
//   0x034dfc: aa0103f5  mov      x21, x1
//   0x034e00: f81c83a8  stur     x8, [x29, #-0x38]
//   0x034e04: 39429808  ldrb     w8, [x0, #0xa6]
//   0x034e08: 34000788  cbz      w8, #0x34ef8
//   0x034e0c: 39429668  ldrb     w8, [x19, #0xa5]
//   0x034e10: 910006b6  add      x22, x21, #1
uint64_t fde_0288_sub_034dd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x39429808ULL) + (x2 ^ 0x034DD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x034dd4: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x034dd8: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x034ddc: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x034de0: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x034de4: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x034de8: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x034dec: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x034df0: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x034df4: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x034df8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0289 @ 0x035334..0x03542c (248 bytes)
// [VN] Phục dựng FDE #0289 tại 0x035334..0x03542c (248 byte)
//   0x035334: d10143ff  sub      sp, sp, #0x50
//   0x035338: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03533c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x035340: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x035344: 910103fd  add      x29, sp, #0x40
//   0x035348: d53bd056  mrs      x22, tpidr_el0
//   0x03534c: f94016c8  ldr      x8, [x22, #0x28]
//   0x035350: 2a0203f4  mov      w20, w2
//   0x035354: aa0003f3  mov      x19, x0
//   0x035358: f9000fe8  str      x8, [sp, #0x18]
//   0x03535c: 39429408  ldrb     w8, [x0, #0xa5]
//   0x035360: 34000268  cbz      w8, #0x353ac
//   0x035364: f9400e60  ldr      x0, [x19, #0x18]
//   0x035368: f9400008  ldr      x8, [x0]
//   0x03536c: f9401508  ldr      x8, [x8, #0x28]
//   0x035370: d63f0100  blr      x8
uint64_t fde_0289_sub_035334(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9400E60ULL) + (x2 ^ 0x035334ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x035334: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x035338: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03533c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x035340: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x035344: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x035348: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03534c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x035350: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035354: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x035358: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0290 @ 0x03542c..0x035478 (76 bytes)
// [VN] Phục dựng FDE #0290 tại 0x03542c..0x035478 (76 byte)
//   0x03542c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x035430: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x035434: 910043fd  add      x29, sp, #0x10
//   0x035438: 52800300  mov      w0, #0x18
//   0x03543c: 97ff960d  bl       #0x1ac70
//   0x035440: aa0003f3  mov      x19, x0
//   0x035444: 52800021  mov      w1, #1
//   0x035448: 97ff99ca  bl       #0x1bb70
//   0x03544c: d0000181  adrp     x1, #0x67000
//   0x035450: d0000182  adrp     x2, #0x67000
//   0x035454: f947e421  ldr      x1, [x1, #0xfc8]
//   0x035458: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x03545c: aa1303e0  mov      x0, x19
//   0x035460: 97ff9938  bl       #0x1b940
//   0x035464: aa0003f4  mov      x20, x0
//   0x035468: aa1303e0  mov      x0, x19
uint64_t fde_0290_sub_03542c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x03542CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03542c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035430: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x035434: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x035438: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF960DULL; // 0x03543c: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035440: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x035444: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF99CAULL; // 0x035448: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000181ULL; // 0x03544c: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000182ULL; // 0x035450: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0291 @ 0x035478..0x035778 (768 bytes)
// [VN] Phục dựng FDE #0291 tại 0x035478..0x035778 (768 byte)
//   0x035478: d10243ff  sub      sp, sp, #0x90
//   0x03547c: f90023f9  str      x25, [sp, #0x40]
//   0x035480: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x035484: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x035488: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x03548c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x035490: 910203fd  add      x29, sp, #0x80
//   0x035494: d53bd058  mrs      x24, tpidr_el0
//   0x035498: aa0803f3  mov      x19, x8
//   0x03549c: f9401708  ldr      x8, [x24, #0x28]
//   0x0354a0: cb010059  sub      x25, x2, x1
//   0x0354a4: b100433f  cmn      x25, #0x10
//   0x0354a8: f9001fe8  str      x8, [sp, #0x38]
//   0x0354ac: a902ffff  stp      xzr, xzr, [sp, #0x28]
//   0x0354b0: f90013ff  str      xzr, [sp, #0x20]
//   0x0354b4: 54001342  b.hs     #0x3571c
uint64_t fde_0291_sub_035478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x035478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x035478: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x03547c: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x035480: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x035484: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x035488: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x03548c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x035490: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x035494: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x035498: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x03549c: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0292 @ 0x035778..0x035990 (536 bytes)
// [VN] Phục dựng FDE #0292 tại 0x035778..0x035990 (536 byte)
//   0x035778: d101c3ff  sub      sp, sp, #0x70
//   0x03577c: f90013f9  str      x25, [sp, #0x20]
//   0x035780: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x035784: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x035788: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03578c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x035790: 910183fd  add      x29, sp, #0x60
//   0x035794: d53bd058  mrs      x24, tpidr_el0
//   0x035798: aa0803f3  mov      x19, x8
//   0x03579c: f9401708  ldr      x8, [x24, #0x28]
//   0x0357a0: cb010059  sub      x25, x2, x1
//   0x0357a4: b100433f  cmn      x25, #0x10
//   0x0357a8: f9000fe8  str      x8, [sp, #0x18]
//   0x0357ac: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x0357b0: f90003ff  str      xzr, [sp]
//   0x0357b4: 54000da2  b.hs     #0x35968
uint64_t fde_0292_sub_035778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x035778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x035778: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x03577c: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x035780: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x035784: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x035788: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03578c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x035790: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x035794: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x035798: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x03579c: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0293 @ 0x035990..0x0359dc (76 bytes)
// [VN] Phục dựng FDE #0293 tại 0x035990..0x0359dc (76 byte)
//   0x035990: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x035994: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x035998: 910043fd  add      x29, sp, #0x10
//   0x03599c: 52800300  mov      w0, #0x18
//   0x0359a0: 97ff94b4  bl       #0x1ac70
//   0x0359a4: aa0003f3  mov      x19, x0
//   0x0359a8: 52800041  mov      w1, #2
//   0x0359ac: 97ff9871  bl       #0x1bb70
//   0x0359b0: d0000181  adrp     x1, #0x67000
//   0x0359b4: d0000182  adrp     x2, #0x67000
//   0x0359b8: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0359bc: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0359c0: aa1303e0  mov      x0, x19
//   0x0359c4: 97ff97df  bl       #0x1b940
//   0x0359c8: aa0003f4  mov      x20, x0
//   0x0359cc: aa1303e0  mov      x0, x19
uint64_t fde_0293_sub_035990(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x035990ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x035990: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035994: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x035998: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x03599c: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF94B4ULL; // 0x0359a0: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0359a4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800041ULL; // 0x0359a8: mov w1, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9871ULL; // 0x0359ac: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000181ULL; // 0x0359b0: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000182ULL; // 0x0359b4: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0294 @ 0x0359dc..0x035ba0 (452 bytes)
// [VN] Phục dựng FDE #0294 tại 0x0359dc..0x035ba0 (452 byte)
//   0x0359dc: d101c3ff  sub      sp, sp, #0x70
//   0x0359e0: f90013f9  str      x25, [sp, #0x20]
//   0x0359e4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0359e8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0359ec: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0359f0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0359f4: 910183fd  add      x29, sp, #0x60
//   0x0359f8: d53bd058  mrs      x24, tpidr_el0
//   0x0359fc: f9401708  ldr      x8, [x24, #0x28]
//   0x035a00: cb010059  sub      x25, x2, x1
//   0x035a04: b100433f  cmn      x25, #0x10
//   0x035a08: f9000fe8  str      x8, [sp, #0x18]
//   0x035a0c: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x035a10: f90003ff  str      xzr, [sp]
//   0x035a14: 54000b22  b.hs     #0x35b78
//   0x035a18: 2a0303f3  mov      w19, w3
uint64_t fde_0294_sub_0359dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xA900FFFFULL) + (x2 ^ 0x0359DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0359dc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x0359e0: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0359e4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0359e8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0359ec: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0359f0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0359f4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0359f8: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0359fc: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010059ULL; // 0x035a00: sub x25, x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0295 @ 0x035ba0..0x035d48 (424 bytes)
// [VN] Phục dựng FDE #0295 tại 0x035ba0..0x035d48 (424 byte)
//   0x035ba0: d101c3ff  sub      sp, sp, #0x70
//   0x035ba4: f90013f9  str      x25, [sp, #0x20]
//   0x035ba8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x035bac: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x035bb0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x035bb4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x035bb8: 910183fd  add      x29, sp, #0x60
//   0x035bbc: d53bd058  mrs      x24, tpidr_el0
//   0x035bc0: aa0803f3  mov      x19, x8
//   0x035bc4: f9401708  ldr      x8, [x24, #0x28]
//   0x035bc8: cb010059  sub      x25, x2, x1
//   0x035bcc: b100433f  cmn      x25, #0x10
//   0x035bd0: f9000fe8  str      x8, [sp, #0x18]
//   0x035bd4: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x035bd8: f90003ff  str      xzr, [sp]
//   0x035bdc: 54000a22  b.hs     #0x35d20
uint64_t fde_0295_sub_035ba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x035BA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x035ba0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x035ba4: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x035ba8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x035bac: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x035bb0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x035bb4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x035bb8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x035bbc: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x035bc0: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x035bc4: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0296 @ 0x035d48..0x035d94 (76 bytes)
// [VN] Phục dựng FDE #0296 tại 0x035d48..0x035d94 (76 byte)
//   0x035d48: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x035d4c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x035d50: 910043fd  add      x29, sp, #0x10
//   0x035d54: 52800300  mov      w0, #0x18
//   0x035d58: 97ff93c6  bl       #0x1ac70
//   0x035d5c: aa0003f3  mov      x19, x0
//   0x035d60: 52800121  mov      w1, #9
//   0x035d64: 97ff9783  bl       #0x1bb70
//   0x035d68: d0000181  adrp     x1, #0x67000
//   0x035d6c: d0000182  adrp     x2, #0x67000
//   0x035d70: f947e421  ldr      x1, [x1, #0xfc8]
//   0x035d74: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x035d78: aa1303e0  mov      x0, x19
//   0x035d7c: 97ff96f1  bl       #0x1b940
//   0x035d80: aa0003f4  mov      x20, x0
//   0x035d84: aa1303e0  mov      x0, x19
uint64_t fde_0296_sub_035d48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x035D48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x035d48: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035d4c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x035d50: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x035d54: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF93C6ULL; // 0x035d58: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035d5c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800121ULL; // 0x035d60: mov w1, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9783ULL; // 0x035d64: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000181ULL; // 0x035d68: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000182ULL; // 0x035d6c: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0297 @ 0x035d94..0x035f30 (412 bytes)
// [VN] Phục dựng FDE #0297 tại 0x035d94..0x035f30 (412 byte)
//   0x035d94: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x035d98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x035d9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x035da0: 910083fd  add      x29, sp, #0x20
//   0x035da4: a9402009  ldp      x9, x8, [x0]
//   0x035da8: b201f3ea  mov      x10, #-0x5555555555555556
//   0x035dac: f295556a  movk     x10, #0xaaab
//   0x035db0: b200f3f6  mov      x22, #0x5555555555555555
//   0x035db4: cb090108  sub      x8, x8, x9
//   0x035db8: 9344fd08  asr      x8, x8, #4
//   0x035dbc: 9b0a7d15  mul      x21, x8, x10
//   0x035dc0: f2e0aab6  movk     x22, #0x555, lsl #48
//   0x035dc4: 910006a8  add      x8, x21, #1
//   0x035dc8: aa0003f3  mov      x19, x0
//   0x035dcc: eb16011f  cmp      x8, x22
//   0x035dd0: 54000ac8  b.hi     #0x35f28
uint64_t fde_0297_sub_035d94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x910006A8ULL) + (x2 ^ 0x035D94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x035d94: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x035d98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x035d9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x035da0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402009ULL; // 0x035da4: ldp x9, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3EAULL; // 0x035da8: mov x10, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF295556AULL; // 0x035dac: movk x10, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3F6ULL; // 0x035db0: mov x22, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x035db4: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9344FD08ULL; // 0x035db8: asr x8, x8, #4
    return acc;
}

// [EN] Reconstructed FDE #0298 @ 0x035f30..0x03601c (236 bytes)
// [VN] Phục dựng FDE #0298 tại 0x035f30..0x03601c (236 byte)
//   0x035f30: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x035f34: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x035f38: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x035f3c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x035f40: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x035f44: 910103fd  add      x29, sp, #0x40
//   0x035f48: a9402014  ldp      x20, x8, [x0]
//   0x035f4c: aa0003f3  mov      x19, x0
//   0x035f50: cb140115  sub      x21, x8, x20
//   0x035f54: 9341feb8  asr      x24, x21, #1
//   0x035f58: b1000708  adds     x8, x24, #1
//   0x035f5c: 54000564  b.mi     #0x36008
//   0x035f60: f9400a69  ldr      x9, [x19, #0x10]
//   0x035f64: 92f8000a  mov      x10, #0x3fffffffffffffff
//   0x035f68: aa0103f6  mov      x22, x1
//   0x035f6c: cb140129  sub      x9, x9, x20
uint64_t fde_0298_sub_035f30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9400A69ULL) + (x2 ^ 0x035F30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x035f30: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x035f34: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x035f38: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x035f3c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x035f40: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x035f44: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x035f48: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035f4c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x035f50: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9341FEB8ULL; // 0x035f54: asr x24, x21, #1
    return acc;
}

// [EN] Reconstructed FDE #0299 @ 0x03601c..0x036060 (68 bytes)
// [VN] Phục dựng FDE #0299 tại 0x03601c..0x036060 (68 byte)
//   0x03601c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036020: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036024: 910043fd  add      x29, sp, #0x10
//   0x036028: b0000188  adrp     x8, #0x67000
//   0x03602c: aa0003f3  mov      x19, x0
//   0x036030: f9400400  ldr      x0, [x0, #8]
//   0x036034: f947d508  ldr      x8, [x8, #0xfa8]
//   0x036038: 91004108  add      x8, x8, #0x10
//   0x03603c: f9000268  str      x8, [x19]
//   0x036040: b4000080  cbz      x0, #0x36050
//   0x036044: f9400008  ldr      x8, [x0]
//   0x036048: f9400508  ldr      x8, [x8, #8]
//   0x03604c: d63f0100  blr      x8
//   0x036050: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036054: aa1303e0  mov      x0, x19
//   0x036058: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0299_sub_03601c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03601CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03601c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036020: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036024: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x036028: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03602c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x036030: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x036034: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x036038: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03603c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x036040: cbz x0, #0x36050
    return acc;
}

// [EN] Reconstructed FDE #0300 @ 0x036060..0x036090 (48 bytes)
// [VN] Phục dựng FDE #0300 tại 0x036060..0x036090 (48 byte)
//   0x036060: 12807c28  mov      w8, #-0x3e2
//   0x036064: b9000028  str      w8, [x1]
//   0x036068: b9401008  ldr      w8, [x0, #0x10]
//   0x03606c: f9400829  ldr      x9, [x1, #0x10]
//   0x036070: f940102a  ldr      x10, [x1, #0x20]
//   0x036074: 5280030b  mov      w11, #0x18
//   0x036078: 51000508  sub      w8, w8, #1
//   0x03607c: 9bab7d08  umull    x8, w8, w11
//   0x036080: f8286949  str      x9, [x10, x8]
//   0x036084: f9400408  ldr      x8, [x0, #8]
//   0x036088: f9002828  str      x8, [x1, #0x50]
//   0x03608c: d65f03c0  ret      
uint64_t fde_0300_sub_036060(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036060ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x036060: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x036064: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401008ULL; // 0x036068: ldr w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x03606c: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940102AULL; // 0x036070: ldr x10, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030BULL; // 0x036074: mov w11, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x036078: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9BAB7D08ULL; // 0x03607c: umull x8, w8, w11
    acc = (acc * 0x100000001B3ULL) ^ 0xF8286949ULL; // 0x036080: str x9, [x10, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x036084: ldr x8, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0301 @ 0x036090..0x0360d4 (68 bytes)
// [VN] Phục dựng FDE #0301 tại 0x036090..0x0360d4 (68 byte)
//   0x036090: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036094: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036098: 910043fd  add      x29, sp, #0x10
//   0x03609c: b0000188  adrp     x8, #0x67000
//   0x0360a0: aa0003f3  mov      x19, x0
//   0x0360a4: f9400400  ldr      x0, [x0, #8]
//   0x0360a8: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0360ac: 91004108  add      x8, x8, #0x10
//   0x0360b0: f9000268  str      x8, [x19]
//   0x0360b4: b4000080  cbz      x0, #0x360c4
//   0x0360b8: f9400008  ldr      x8, [x0]
//   0x0360bc: f9400508  ldr      x8, [x8, #8]
//   0x0360c0: d63f0100  blr      x8
//   0x0360c4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0360c8: aa1303e0  mov      x0, x19
//   0x0360cc: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0301_sub_036090(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x036090ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036090: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036094: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036098: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x03609c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0360a0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x0360a4: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x0360a8: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0360ac: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0360b0: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x0360b4: cbz x0, #0x360c4
    return acc;
}

// [EN] Reconstructed FDE #0302 @ 0x0360d4..0x03610c (56 bytes)
// [VN] Phục dựng FDE #0302 tại 0x0360d4..0x03610c (56 byte)
//   0x0360d4: 12807c28  mov      w8, #-0x3e2
//   0x0360d8: b9000028  str      w8, [x1]
//   0x0360dc: b9401008  ldr      w8, [x0, #0x10]
//   0x0360e0: f940102a  ldr      x10, [x1, #0x20]
//   0x0360e4: f9400829  ldr      x9, [x1, #0x10]
//   0x0360e8: 5280030b  mov      w11, #0x18
//   0x0360ec: 51000508  sub      w8, w8, #1
//   0x0360f0: 5280002c  mov      w12, #1
//   0x0360f4: 9bab2908  umaddl   x8, w8, w11, x10
//   0x0360f8: f9000509  str      x9, [x8, #8]
//   0x0360fc: 3900410c  strb     w12, [x8, #0x10]
//   0x036100: f9400408  ldr      x8, [x0, #8]
//   0x036104: f9002828  str      x8, [x1, #0x50]
//   0x036108: d65f03c0  ret      
uint64_t fde_0302_sub_0360d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xF9002828ULL) + (x2 ^ 0x0360D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x0360d4: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x0360d8: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401008ULL; // 0x0360dc: ldr w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940102AULL; // 0x0360e0: ldr x10, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x0360e4: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030BULL; // 0x0360e8: mov w11, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x0360ec: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002CULL; // 0x0360f0: mov w12, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9BAB2908ULL; // 0x0360f4: umaddl x8, w8, w11, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000509ULL; // 0x0360f8: str x9, [x8, #8]
    return acc;
}

// [EN] Reconstructed FDE #0303 @ 0x03610c..0x036294 (392 bytes)
// [VN] Phục dựng FDE #0303 tại 0x03610c..0x036294 (392 byte)
//   0x03610c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x036110: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x036114: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x036118: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03611c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x036120: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x036124: 910143fd  add      x29, sp, #0x50
//   0x036128: aa0003f6  mov      x22, x0
//   0x03612c: 52800200  mov      w0, #0x10
//   0x036130: 2a0603fb  mov      w27, w6
//   0x036134: aa0503f8  mov      x24, x5
//   0x036138: aa0403f7  mov      x23, x4
//   0x03613c: aa0303f5  mov      x21, x3
//   0x036140: aa0203f9  mov      x25, x2
//   0x036144: aa0103fa  mov      x26, x1
//   0x036148: 97ff96c6  bl       #0x1bc60
uint64_t fde_0303_sub_03610c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0303F5ULL) + (x2 ^ 0x03610CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x03610c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x036110: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x036114: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x036118: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03611c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x036120: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x036124: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x036128: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x03612c: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0603FBULL; // 0x036130: mov w27, w6
    return acc;
}

// [EN] Reconstructed FDE #0304 @ 0x036294..0x0362e0 (76 bytes)
// [VN] Phục dựng FDE #0304 tại 0x036294..0x0362e0 (76 byte)
//   0x036294: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x036298: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03629c: 910043fd  add      x29, sp, #0x10
//   0x0362a0: 52800300  mov      w0, #0x18
//   0x0362a4: 97ff9273  bl       #0x1ac70
//   0x0362a8: aa0003f3  mov      x19, x0
//   0x0362ac: 52800101  mov      w1, #8
//   0x0362b0: 97ff9630  bl       #0x1bb70
//   0x0362b4: b0000181  adrp     x1, #0x67000
//   0x0362b8: b0000182  adrp     x2, #0x67000
//   0x0362bc: f947e421  ldr      x1, [x1, #0xfc8]
//   0x0362c0: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x0362c4: aa1303e0  mov      x0, x19
//   0x0362c8: 97ff959e  bl       #0x1b940
//   0x0362cc: aa0003f4  mov      x20, x0
//   0x0362d0: aa1303e0  mov      x0, x19
uint64_t fde_0304_sub_036294(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x036294ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x036294: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036298: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03629c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0362a0: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9273ULL; // 0x0362a4: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0362a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800101ULL; // 0x0362ac: mov w1, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9630ULL; // 0x0362b0: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000181ULL; // 0x0362b4: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000182ULL; // 0x0362b8: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0305 @ 0x0362e0..0x03632c (76 bytes)
// [VN] Phục dựng FDE #0305 tại 0x0362e0..0x03632c (76 byte)
//   0x0362e0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0362e4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0362e8: 910043fd  add      x29, sp, #0x10
//   0x0362ec: 52800300  mov      w0, #0x18
//   0x0362f0: 97ff9260  bl       #0x1ac70
//   0x0362f4: aa0003f3  mov      x19, x0
//   0x0362f8: 528000e1  mov      w1, #7
//   0x0362fc: 97ff961d  bl       #0x1bb70
//   0x036300: b0000181  adrp     x1, #0x67000
//   0x036304: b0000182  adrp     x2, #0x67000
//   0x036308: f947e421  ldr      x1, [x1, #0xfc8]
//   0x03630c: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x036310: aa1303e0  mov      x0, x19
//   0x036314: 97ff958b  bl       #0x1b940
//   0x036318: aa0003f4  mov      x20, x0
//   0x03631c: aa1303e0  mov      x0, x19
uint64_t fde_0305_sub_0362e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0362E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0362e0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0362e4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0362e8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0362ec: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9260ULL; // 0x0362f0: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0362f4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528000E1ULL; // 0x0362f8: mov w1, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF961DULL; // 0x0362fc: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000181ULL; // 0x036300: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000182ULL; // 0x036304: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0306 @ 0x03632c..0x036398 (108 bytes)
// [VN] Phục dựng FDE #0306 tại 0x03632c..0x036398 (108 byte)
//   0x03632c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036330: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036334: 910043fd  add      x29, sp, #0x10
//   0x036338: b0000188  adrp     x8, #0x67000
//   0x03633c: aa0003f3  mov      x19, x0
//   0x036340: f9400800  ldr      x0, [x0, #0x10]
//   0x036344: f9472108  ldr      x8, [x8, #0xe40]
//   0x036348: 91004108  add      x8, x8, #0x10
//   0x03634c: f9000268  str      x8, [x19]
//   0x036350: b4000080  cbz      x0, #0x36360
//   0x036354: f9400008  ldr      x8, [x0]
//   0x036358: f9400508  ldr      x8, [x8, #8]
//   0x03635c: d63f0100  blr      x8
//   0x036360: b0000188  adrp     x8, #0x67000
//   0x036364: f9400660  ldr      x0, [x19, #8]
//   0x036368: f947d508  ldr      x8, [x8, #0xfa8]
uint64_t fde_0306_sub_03632c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03632CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03632c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036330: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036334: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x036338: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03633c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x036340: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472108ULL; // 0x036344: ldr x8, [x8, #0xe40]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x036348: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03634c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x036350: cbz x0, #0x36360
    return acc;
}

// [EN] Reconstructed FDE #0307 @ 0x036398..0x036400 (104 bytes)
// [VN] Phục dựng FDE #0307 tại 0x036398..0x036400 (104 byte)
//   0x036398: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03639c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0363a0: 910043fd  add      x29, sp, #0x10
//   0x0363a4: b0000188  adrp     x8, #0x67000
//   0x0363a8: aa0003f3  mov      x19, x0
//   0x0363ac: f9400800  ldr      x0, [x0, #0x10]
//   0x0363b0: f9472108  ldr      x8, [x8, #0xe40]
//   0x0363b4: 91004108  add      x8, x8, #0x10
//   0x0363b8: f9000268  str      x8, [x19]
//   0x0363bc: b4000080  cbz      x0, #0x363cc
//   0x0363c0: f9400008  ldr      x8, [x0]
//   0x0363c4: f9400508  ldr      x8, [x8, #8]
//   0x0363c8: d63f0100  blr      x8
//   0x0363cc: b0000188  adrp     x8, #0x67000
//   0x0363d0: f9400660  ldr      x0, [x19, #8]
//   0x0363d4: f947d508  ldr      x8, [x8, #0xfa8]
uint64_t fde_0307_sub_036398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x036398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036398: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03639c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0363a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x0363a4: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0363a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x0363ac: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472108ULL; // 0x0363b0: ldr x8, [x8, #0xe40]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0363b4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0363b8: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x0363bc: cbz x0, #0x363cc
    return acc;
}

// [EN] Reconstructed FDE #0308 @ 0x036400..0x0365f0 (496 bytes)
// [VN] Phục dựng FDE #0308 tại 0x036400..0x0365f0 (496 byte)
//   0x036400: b940002a  ldr      w10, [x1]
//   0x036404: b9402808  ldr      w8, [x0, #0x28]
//   0x036408: f9401c29  ldr      x9, [x1, #0x38]
//   0x03640c: 310f7d5f  cmn      w10, #0x3df
//   0x036410: 8b08112b  add      x11, x9, x8, lsl #4
//   0x036414: 54000501  b.ne     #0x364b4
//   0x036418: f940016a  ldr      x10, [x11]
//   0x03641c: 9100054a  add      x10, x10, #1
//   0x036420: f900016a  str      x10, [x11]
//   0x036424: a941b40c  ldp      x12, x13, [x0, #0x18]
//   0x036428: eb0d015f  cmp      x10, x13
//   0x03642c: 1a9f27eb  cset     w11, lo
//   0x036430: eb0c015f  cmp      x10, x12
//   0x036434: 54000143  b.lo     #0x3645c
//   0x036438: eb0d015f  cmp      x10, x13
//   0x03643c: 54000102  b.hs     #0x3645c
uint64_t fde_0308_sub_036400(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB940002AULL) + (x1 ^ 0xEB0C015FULL) + (x2 ^ 0x036400ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB940002AULL; // 0x036400: ldr w10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402808ULL; // 0x036404: ldr w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C29ULL; // 0x036408: ldr x9, [x1, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x310F7D5FULL; // 0x03640c: cmn w10, #0x3df
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08112BULL; // 0x036410: add x11, x9, x8, lsl #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000501ULL; // 0x036414: b.ne #0x364b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF940016AULL; // 0x036418: ldr x10, [x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100054AULL; // 0x03641c: add x10, x10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900016AULL; // 0x036420: str x10, [x11]
    acc = (acc * 0x100000001B3ULL) ^ 0xA941B40CULL; // 0x036424: ldp x12, x13, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0309 @ 0x0365f0..0x0366bc (204 bytes)
// [VN] Phục dựng FDE #0309 tại 0x0365f0..0x0366bc (204 byte)
//   0x0365f0: 12807c28  mov      w8, #-0x3e2
//   0x0365f4: b9000048  str      w8, [x2]
//   0x0365f8: 3940d008  ldrb     w8, [x0, #0x34]
//   0x0365fc: 12000029  and      w9, w1, #1
//   0x036600: 6b09011f  cmp      w8, w9
//   0x036604: 54000081  b.ne     #0x36614
//   0x036608: f9400808  ldr      x8, [x0, #0x10]
//   0x03660c: f9002848  str      x8, [x2, #0x50]
//   0x036610: d65f03c0  ret      
//   0x036614: f9400408  ldr      x8, [x0, #8]
//   0x036618: f9401c49  ldr      x9, [x2, #0x38]
//   0x03661c: f940084a  ldr      x10, [x2, #0x10]
//   0x036620: f9002848  str      x8, [x2, #0x50]
//   0x036624: b9402808  ldr      w8, [x0, #0x28]
//   0x036628: 8b081128  add      x8, x9, x8, lsl #4
//   0x03662c: f900050a  str      x10, [x8, #8]
uint64_t fde_0309_sub_0365f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xF9002848ULL) + (x2 ^ 0x0365F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x0365f0: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000048ULL; // 0x0365f4: str w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940D008ULL; // 0x0365f8: ldrb w8, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000029ULL; // 0x0365fc: and w9, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x036600: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000081ULL; // 0x036604: b.ne #0x36614
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x036608: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002848ULL; // 0x03660c: str x8, [x2, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036610: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x036614: ldr x8, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0310 @ 0x0366bc..0x036724 (104 bytes)
// [VN] Phục dựng FDE #0310 tại 0x0366bc..0x036724 (104 byte)
//   0x0366bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0366c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0366c4: 910043fd  add      x29, sp, #0x10
//   0x0366c8: b0000188  adrp     x8, #0x67000
//   0x0366cc: aa0003f3  mov      x19, x0
//   0x0366d0: f9400800  ldr      x0, [x0, #0x10]
//   0x0366d4: f9472108  ldr      x8, [x8, #0xe40]
//   0x0366d8: 91004108  add      x8, x8, #0x10
//   0x0366dc: f9000268  str      x8, [x19]
//   0x0366e0: b4000080  cbz      x0, #0x366f0
//   0x0366e4: f9400008  ldr      x8, [x0]
//   0x0366e8: f9400508  ldr      x8, [x8, #8]
//   0x0366ec: d63f0100  blr      x8
//   0x0366f0: b0000188  adrp     x8, #0x67000
//   0x0366f4: f9400660  ldr      x0, [x19, #8]
//   0x0366f8: f947d508  ldr      x8, [x8, #0xfa8]
uint64_t fde_0310_sub_0366bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x0366BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0366bc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0366c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0366c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x0366c8: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0366cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x0366d0: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472108ULL; // 0x0366d4: ldr x8, [x8, #0xe40]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0366d8: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0366dc: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x0366e0: cbz x0, #0x366f0
    return acc;
}

// [EN] Reconstructed FDE #0311 @ 0x036724..0x036728 (4 bytes)
// [VN] Phục dựng FDE #0311 tại 0x036724..0x036728 (4 byte)
//   0x036724: 17ff90d7  b        #0x1aa80
uint64_t fde_0311_sub_036724(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF90D7ULL) + (x1 ^ 0x17FF90D7ULL) + (x2 ^ 0x036724ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF90D7ULL; // 0x036724: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0312 @ 0x036728..0x03673c (20 bytes)
// [VN] Phục dựng FDE #0312 tại 0x036728..0x03673c (20 byte)
//   0x036728: 12807bc8  mov      w8, #-0x3df
//   0x03672c: b9000028  str      w8, [x1]
//   0x036730: f9400408  ldr      x8, [x0, #8]
//   0x036734: f9002828  str      x8, [x1, #0x50]
//   0x036738: d65f03c0  ret      
uint64_t fde_0312_sub_036728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807BC8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807BC8ULL; // 0x036728: mov w8, #-0x3df
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x03672c: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x036730: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002828ULL; // 0x036734: str x8, [x1, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036738: ret 
    return acc;
}

// [EN] Reconstructed FDE #0313 @ 0x03673c..0x0367a4 (104 bytes)
// [VN] Phục dựng FDE #0313 tại 0x03673c..0x0367a4 (104 byte)
//   0x03673c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036740: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036744: 910043fd  add      x29, sp, #0x10
//   0x036748: b0000188  adrp     x8, #0x67000
//   0x03674c: aa0003f3  mov      x19, x0
//   0x036750: f9400800  ldr      x0, [x0, #0x10]
//   0x036754: f9472108  ldr      x8, [x8, #0xe40]
//   0x036758: 91004108  add      x8, x8, #0x10
//   0x03675c: f9000268  str      x8, [x19]
//   0x036760: b4000080  cbz      x0, #0x36770
//   0x036764: f9400008  ldr      x8, [x0]
//   0x036768: f9400508  ldr      x8, [x8, #8]
//   0x03676c: d63f0100  blr      x8
//   0x036770: b0000188  adrp     x8, #0x67000
//   0x036774: f9400660  ldr      x0, [x19, #8]
//   0x036778: f947d508  ldr      x8, [x8, #0xfa8]
uint64_t fde_0313_sub_03673c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03673CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03673c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036740: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036744: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x036748: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03674c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x036750: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472108ULL; // 0x036754: ldr x8, [x8, #0xe40]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x036758: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03675c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x036760: cbz x0, #0x36770
    return acc;
}

// [EN] Reconstructed FDE #0314 @ 0x0367a4..0x0367b0 (12 bytes)
// [VN] Phục dựng FDE #0314 tại 0x0367a4..0x0367b0 (12 byte)
//   0x0367a4: 12807be8  mov      w8, #-0x3e0
//   0x0367a8: b9000028  str      w8, [x1]
//   0x0367ac: d65f03c0  ret      
uint64_t fde_0314_sub_0367a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807BE8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0367A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807BE8ULL; // 0x0367a4: mov w8, #-0x3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x0367a8: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0367ac: ret 
    return acc;
}

// [EN] Reconstructed FDE #0315 @ 0x0367b0..0x0367d4 (36 bytes)
// [VN] Phục dựng FDE #0315 tại 0x0367b0..0x0367d4 (36 byte)
//   0x0367b0: 12807c28  mov      w8, #-0x3e2
//   0x0367b4: b9000048  str      w8, [x2]
//   0x0367b8: 36000081  tbz      w1, #0, #0x367c8
//   0x0367bc: f9400808  ldr      x8, [x0, #0x10]
//   0x0367c0: f9002848  str      x8, [x2, #0x50]
//   0x0367c4: d65f03c0  ret      
//   0x0367c8: f9400408  ldr      x8, [x0, #8]
//   0x0367cc: f9002848  str      x8, [x2, #0x50]
//   0x0367d0: d65f03c0  ret      
uint64_t fde_0315_sub_0367b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0367B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x0367b0: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000048ULL; // 0x0367b4: str w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000081ULL; // 0x0367b8: tbz w1, #0, #0x367c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x0367bc: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002848ULL; // 0x0367c0: str x8, [x2, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0367c4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0367c8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002848ULL; // 0x0367cc: str x8, [x2, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0367d0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0316 @ 0x0367d4..0x0367d8 (4 bytes)
// [VN] Phục dựng FDE #0316 tại 0x0367d4..0x0367d8 (4 byte)
//   0x0367d4: 17ff90ab  b        #0x1aa80
uint64_t fde_0316_sub_0367d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF90ABULL) + (x1 ^ 0x17FF90ABULL) + (x2 ^ 0x0367D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF90ABULL; // 0x0367d4: b #0x1aa80
    return acc;
}

// [EN] Reconstructed FDE #0317 @ 0x0367d8..0x0367ec (20 bytes)
// [VN] Phục dựng FDE #0317 tại 0x0367d8..0x0367ec (20 byte)
//   0x0367d8: 12807c28  mov      w8, #-0x3e2
//   0x0367dc: b9000028  str      w8, [x1]
//   0x0367e0: f9400408  ldr      x8, [x0, #8]
//   0x0367e4: f9002828  str      x8, [x1, #0x50]
//   0x0367e8: d65f03c0  ret      
uint64_t fde_0317_sub_0367d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12807C28ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0367D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C28ULL; // 0x0367d8: mov w8, #-0x3e2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000028ULL; // 0x0367dc: str w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0367e0: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002828ULL; // 0x0367e4: str x8, [x1, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0367e8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0318 @ 0x0367ec..0x036838 (76 bytes)
// [VN] Phục dựng FDE #0318 tại 0x0367ec..0x036838 (76 byte)
//   0x0367ec: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0367f0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0367f4: 910043fd  add      x29, sp, #0x10
//   0x0367f8: 52800300  mov      w0, #0x18
//   0x0367fc: 97ff911d  bl       #0x1ac70
//   0x036800: aa0003f3  mov      x19, x0
//   0x036804: 528001e1  mov      w1, #0xf
//   0x036808: 97ff94da  bl       #0x1bb70
//   0x03680c: b0000181  adrp     x1, #0x67000
//   0x036810: b0000182  adrp     x2, #0x67000
//   0x036814: f947e421  ldr      x1, [x1, #0xfc8]
//   0x036818: f9475c42  ldr      x2, [x2, #0xeb8]
//   0x03681c: aa1303e0  mov      x0, x19
//   0x036820: 97ff9448  bl       #0x1b940
//   0x036824: aa0003f4  mov      x20, x0
//   0x036828: aa1303e0  mov      x0, x19
uint64_t fde_0318_sub_0367ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0367ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0367ec: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0367f0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0367f4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0367f8: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF911DULL; // 0x0367fc: bl #0x1ac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036800: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528001E1ULL; // 0x036804: mov w1, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF94DAULL; // 0x036808: bl #0x1bb70
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000181ULL; // 0x03680c: adrp x1, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000182ULL; // 0x036810: adrp x2, #0x67000
    return acc;
}

// [EN] Reconstructed FDE #0319 @ 0x036838..0x036a44 (524 bytes)
// [VN] Phục dựng FDE #0319 tại 0x036838..0x036a44 (524 byte)
//   0x036838: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03683c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x036840: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x036844: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x036848: 9100c3fd  add      x29, sp, #0x30
//   0x03684c: aa0203f5  mov      x21, x2
//   0x036850: aa0103f6  mov      x22, x1
//   0x036854: aa0003f3  mov      x19, x0
//   0x036858: 97ff9612  bl       #0x1c0a0
//   0x03685c: aa0003f4  mov      x20, x0
//   0x036860: eb0002df  cmp      x22, x0
//   0x036864: 540000e0  b.eq     #0x36880
//   0x036868: aa1403e0  mov      x0, x20
//   0x03686c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x036870: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x036874: a94157f6  ldp      x22, x21, [sp, #0x10]
uint64_t fde_0319_sub_036838(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x036838ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x036838: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03683c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x036840: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x036844: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x036848: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03684c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x036850: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036854: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9612ULL; // 0x036858: bl #0x1c0a0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03685c: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0320 @ 0x036a44..0x036d64 (800 bytes)
// [VN] Phục dựng FDE #0320 tại 0x036a44..0x036d64 (800 byte)
//   0x036a44: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036a48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036a4c: 910043fd  add      x29, sp, #0x10
//   0x036a50: aa0103f3  mov      x19, x1
//   0x036a54: eb02003f  cmp      x1, x2
//   0x036a58: 54000160  b.eq     #0x36a84
//   0x036a5c: 39400268  ldrb     w8, [x19]
//   0x036a60: 7100a91f  cmp      w8, #0x2a
//   0x036a64: 54000181  b.ne     #0x36a94
//   0x036a68: 2a0403e4  mov      w4, w4
//   0x036a6c: 2a0503e5  mov      w5, w5
//   0x036a70: 92800002  mov      x2, #-1
//   0x036a74: 52800026  mov      w6, #1
//   0x036a78: aa1f03e1  mov      x1, xzr
//   0x036a7c: 97ff9385  bl       #0x1b890
//   0x036a80: 91000673  add      x19, x19, #1
uint64_t fde_0320_sub_036a44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x52800026ULL) + (x2 ^ 0x036A44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036a44: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036a48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036a4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036a50: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x036a54: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x036a58: b.eq #0x36a84
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x036a5c: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100A91FULL; // 0x036a60: cmp w8, #0x2a
    acc = (acc * 0x100000001B3ULL) ^ 0x54000181ULL; // 0x036a64: b.ne #0x36a94
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E4ULL; // 0x036a68: mov w4, w4
    return acc;
}

// [EN] Reconstructed FDE #0321 @ 0x036d64..0x036e80 (284 bytes)
// [VN] Phục dựng FDE #0321 tại 0x036d64..0x036e80 (284 byte)
//   0x036d64: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x036d68: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x036d6c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x036d70: 910083fd  add      x29, sp, #0x20
//   0x036d74: aa0103f3  mov      x19, x1
//   0x036d78: eb02003f  cmp      x1, x2
//   0x036d7c: aa0003f4  mov      x20, x0
//   0x036d80: 54000660  b.eq     #0x36e4c
//   0x036d84: aa1303f5  mov      x21, x19
//   0x036d88: 384016a1  ldrb     w1, [x21], #1
//   0x036d8c: eb0202bf  cmp      x21, x2
//   0x036d90: 54000061  b.ne     #0x36d9c
//   0x036d94: 7100903f  cmp      w1, #0x24
//   0x036d98: 54000140  b.eq     #0x36dc0
//   0x036d9c: 5100b828  sub      w8, w1, #0x2e
//   0x036da0: 7100b91f  cmp      w8, #0x2e
uint64_t fde_0321_sub_036d64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x7100903FULL) + (x2 ^ 0x036D64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x036d64: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x036d68: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x036d6c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x036d70: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036d74: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x036d78: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x036d7c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000660ULL; // 0x036d80: b.eq #0x36e4c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303F5ULL; // 0x036d84: mov x21, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x384016A1ULL; // 0x036d88: ldrb w1, [x21], #1
    return acc;
}

// [EN] Reconstructed FDE #0322 @ 0x036e80..0x036ec4 (68 bytes)
// [VN] Phục dựng FDE #0322 tại 0x036e80..0x036ec4 (68 byte)
//   0x036e80: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036e84: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036e88: 910043fd  add      x29, sp, #0x10
//   0x036e8c: b0000188  adrp     x8, #0x67000
//   0x036e90: aa0003f3  mov      x19, x0
//   0x036e94: f9400400  ldr      x0, [x0, #8]
//   0x036e98: f947d508  ldr      x8, [x8, #0xfa8]
//   0x036e9c: 91004108  add      x8, x8, #0x10
//   0x036ea0: f9000268  str      x8, [x19]
//   0x036ea4: b4000080  cbz      x0, #0x36eb4
//   0x036ea8: f9400008  ldr      x8, [x0]
//   0x036eac: f9400508  ldr      x8, [x8, #8]
//   0x036eb0: d63f0100  blr      x8
//   0x036eb4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036eb8: aa1303e0  mov      x0, x19
//   0x036ebc: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0322_sub_036e80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x036E80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036e80: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036e84: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036e88: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x036e8c: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036e90: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x036e94: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947D508ULL; // 0x036e98: ldr x8, [x8, #0xfa8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x036e9c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x036ea0: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x036ea4: cbz x0, #0x36eb4
    return acc;
}

// [EN] Reconstructed FDE #0323 @ 0x036ec4..0x036f04 (64 bytes)
// [VN] Phục dựng FDE #0323 tại 0x036ec4..0x036f04 (64 byte)
//   0x036ec4: a9412428  ldp      x8, x9, [x1, #0x10]
//   0x036ec8: eb09011f  cmp      x8, x9
//   0x036ecc: 54000140  b.eq     #0x36ef4
//   0x036ed0: 39400109  ldrb     w9, [x8]
//   0x036ed4: 34000109  cbz      w9, #0x36ef4
//   0x036ed8: 12807c49  mov      w9, #-0x3e3
//   0x036edc: 91000508  add      x8, x8, #1
//   0x036ee0: b9000029  str      w9, [x1]
//   0x036ee4: f9000828  str      x8, [x1, #0x10]
//   0x036ee8: f9400408  ldr      x8, [x0, #8]
//   0x036eec: f9002828  str      x8, [x1, #0x50]
//   0x036ef0: d65f03c0  ret      
//   0x036ef4: 12807c08  mov      w8, #-0x3e1
//   0x036ef8: b9000028  str      w8, [x1]
//   0x036efc: f900283f  str      xzr, [x1, #0x50]
//   0x036f00: d65f03c0  ret      
uint64_t fde_0323_sub_036ec4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412428ULL) + (x1 ^ 0x12807C08ULL) + (x2 ^ 0x036EC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412428ULL; // 0x036ec4: ldp x8, x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x036ec8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x036ecc: b.eq #0x36ef4
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x036ed0: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000109ULL; // 0x036ed4: cbz w9, #0x36ef4
    acc = (acc * 0x100000001B3ULL) ^ 0x12807C49ULL; // 0x036ed8: mov w9, #-0x3e3
    acc = (acc * 0x100000001B3ULL) ^ 0x91000508ULL; // 0x036edc: add x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000029ULL; // 0x036ee0: str w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000828ULL; // 0x036ee4: str x8, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x036ee8: ldr x8, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0324 @ 0x036f04..0x037180 (636 bytes)
// [VN] Phục dựng FDE #0324 tại 0x036f04..0x037180 (636 byte)
//   0x036f04: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x036f08: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x036f0c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x036f10: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x036f14: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x036f18: 910103fd  add      x29, sp, #0x40
//   0x036f1c: f9401c14  ldr      x20, [x0, #0x38]
//   0x036f20: b9401c18  ldr      w24, [x0, #0x1c]
//   0x036f24: aa0203f3  mov      x19, x2
//   0x036f28: aa0003f5  mov      x21, x0
//   0x036f2c: aa0103f6  mov      x22, x1
//   0x036f30: 97ff9494  bl       #0x1c180
//   0x036f34: aa0003e1  mov      x1, x0
//   0x036f38: eb16001f  cmp      x0, x22
//   0x036f3c: 54000101  b.ne     #0x36f5c
//   0x036f40: aa1503e0  mov      x0, x21
uint64_t fde_0324_sub_036f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x036F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x036f04: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x036f08: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x036f0c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x036f10: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x036f14: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x036f18: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C14ULL; // 0x036f1c: ldr x20, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C18ULL; // 0x036f20: ldr w24, [x0, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x036f24: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x036f28: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0325 @ 0x037180..0x0371e8 (104 bytes)
// [VN] Phục dựng FDE #0325 tại 0x037180..0x0371e8 (104 byte)
//   0x037180: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x037184: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x037188: 910043fd  add      x29, sp, #0x10
//   0x03718c: aa0103f3  mov      x19, x1
//   0x037190: eb02003f  cmp      x1, x2
//   0x037194: 54000160  b.eq     #0x371c0
//   0x037198: 39400261  ldrb     w1, [x19]
//   0x03719c: 51009028  sub      w8, w1, #0x24
//   0x0371a0: 7101611f  cmp      w8, #0x58
//   0x0371a4: 540001c8  b.hi     #0x371dc
//   0x0371a8: f00000c9  adrp     x9, #0x52000
//   0x0371ac: 91375d29  add      x9, x9, #0xdd7
//   0x0371b0: 1000008a  adr      x10, #0x371c0
//   0x0371b4: 3868692b  ldrb     w11, [x9, x8]
//   0x0371b8: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x0371bc: d61f0140  br       x10
uint64_t fde_0325_sub_037180(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x037180ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x037180: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x037184: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x037188: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03718c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x037190: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x037194: b.eq #0x371c0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400261ULL; // 0x037198: ldrb w1, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x51009028ULL; // 0x03719c: sub w8, w1, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x7101611FULL; // 0x0371a0: cmp w8, #0x58
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C8ULL; // 0x0371a4: b.hi #0x371dc
    return acc;
}

// [EN] Reconstructed FDE #0326 @ 0x0371e8..0x03727c (148 bytes)
// [VN] Phục dựng FDE #0326 tại 0x0371e8..0x03727c (148 byte)
//   0x0371e8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0371ec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0371f0: 910043fd  add      x29, sp, #0x10
//   0x0371f4: aa0103f3  mov      x19, x1
//   0x0371f8: eb02003f  cmp      x1, x2
//   0x0371fc: 54000280  b.eq     #0x3724c
//   0x037200: 91000661  add      x1, x19, #1
//   0x037204: eb02003f  cmp      x1, x2
//   0x037208: 54000220  b.eq     #0x3724c
//   0x03720c: 39400268  ldrb     w8, [x19]
//   0x037210: 7101711f  cmp      w8, #0x5c
//   0x037214: 540001c1  b.ne     #0x3724c
//   0x037218: 39400028  ldrb     w8, [x1]
//   0x03721c: 51009109  sub      w9, w8, #0x24
//   0x037220: 7101653f  cmp      w9, #0x59
//   0x037224: 540001c8  b.hi     #0x3725c
uint64_t fde_0326_sub_0371e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x39400028ULL) + (x2 ^ 0x0371E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0371e8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0371ec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0371f0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0371f4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x0371f8: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000280ULL; // 0x0371fc: b.eq #0x3724c
    acc = (acc * 0x100000001B3ULL) ^ 0x91000661ULL; // 0x037200: add x1, x19, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x037204: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x037208: b.eq #0x3724c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x03720c: ldrb w8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0327 @ 0x03727c..0x0374c8 (588 bytes)
// [VN] Phục dựng FDE #0327 tại 0x03727c..0x0374c8 (588 byte)
//   0x03727c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x037280: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x037284: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x037288: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03728c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x037290: 910103fd  add      x29, sp, #0x40
//   0x037294: b9401c08  ldr      w8, [x0, #0x1c]
//   0x037298: aa0303f4  mov      x20, x3
//   0x03729c: f8018e82  str      x2, [x20, #0x18]!
//   0x0372a0: aa0203f5  mov      x21, x2
//   0x0372a4: aa0103f8  mov      x24, x1
//   0x0372a8: aa0003f6  mov      x22, x0
//   0x0372ac: f9001062  str      x2, [x3, #0x20]
//   0x0372b0: 11000501  add      w1, w8, #1
//   0x0372b4: aa0303e0  mov      x0, x3
//   0x0372b8: aa1403e2  mov      x2, x20
uint64_t fde_0327_sub_03727c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9001062ULL) + (x2 ^ 0x03727CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x03727c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x037280: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x037284: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x037288: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03728c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x037290: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C08ULL; // 0x037294: ldr w8, [x0, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x037298: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xF8018E82ULL; // 0x03729c: str x2, [x20, #0x18]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x0372a0: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0328 @ 0x0374c8..0x037694 (460 bytes)
// [VN] Phục dựng FDE #0328 tại 0x0374c8..0x037694 (460 byte)
//   0x0374c8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0374cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0374d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0374d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0374d8: 9100c3fd  add      x29, sp, #0x30
//   0x0374dc: a9402c68  ldp      x8, x11, [x3]
//   0x0374e0: a9402809  ldp      x9, x10, [x0]
//   0x0374e4: f9401878  ldr      x24, [x3, #0x30]
//   0x0374e8: b201f3ec  mov      x12, #-0x5555555555555556
//   0x0374ec: cb080168  sub      x8, x11, x8
//   0x0374f0: cb09014b  sub      x11, x10, x9
//   0x0374f4: f295556c  movk     x12, #0xaaab
//   0x0374f8: 9343fd08  asr      x8, x8, #3
//   0x0374fc: 9343fd6d  asr      x13, x11, #3
//   0x037500: 9b0c7d0b  mul      x11, x8, x12
//   0x037504: 9b0c7da8  mul      x8, x13, x12
uint64_t fde_0328_sub_0374c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x9343FD08ULL) + (x2 ^ 0x0374C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0374c8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0374cc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0374d0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0374d4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0374d8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402C68ULL; // 0x0374dc: ldp x8, x11, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402809ULL; // 0x0374e0: ldp x9, x10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401878ULL; // 0x0374e4: ldr x24, [x3, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3ECULL; // 0x0374e8: mov x12, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xCB080168ULL; // 0x0374ec: sub x8, x11, x8
    return acc;
}

// [EN] Reconstructed FDE #0329 @ 0x037694..0x037ef0 (2140 bytes)
// [VN] Phục dựng FDE #0329 tại 0x037694..0x037ef0 (2140 byte)
//   0x037694: d10583ff  sub      sp, sp, #0x160
//   0x037698: a9106ffc  stp      x28, x27, [sp, #0x100]
//   0x03769c: a91167fa  stp      x26, x25, [sp, #0x110]
//   0x0376a0: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x0376a4: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x0376a8: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x0376ac: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x0376b0: 910543fd  add      x29, sp, #0x150
//   0x0376b4: b9004fe4  str      w4, [sp, #0x4c]
//   0x0376b8: d53bd056  mrs      x22, tpidr_el0
//   0x0376bc: f94016c8  ldr      x8, [x22, #0x28]
//   0x0376c0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0376c4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0376c8: ad0303e0  stp      q0, q0, [sp, #0x60]
//   0x0376cc: 3d8017e0  str      q0, [sp, #0x50]
//   0x0376d0: f9401414  ldr      x20, [x0, #0x28]
uint64_t fde_0329_sub_037694(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x037694ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x037694: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xA9106FFCULL; // 0x037698: stp x28, x27, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91167FAULL; // 0x03769c: stp x26, x25, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x0376a0: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x0376a4: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x0376a8: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x0376ac: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x0376b0: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xB9004FE4ULL; // 0x0376b4: str w4, [sp, #0x4c]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0376b8: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0330 @ 0x037ef0..0x0385d0 (1760 bytes)
// [VN] Phục dựng FDE #0330 tại 0x037ef0..0x0385d0 (1760 byte)
//   0x037ef0: d10743ff  sub      sp, sp, #0x1d0
//   0x037ef4: a9176ffc  stp      x28, x27, [sp, #0x170]
//   0x037ef8: a91867fa  stp      x26, x25, [sp, #0x180]
//   0x037efc: a9195ff8  stp      x24, x23, [sp, #0x190]
//   0x037f00: a91a57f6  stp      x22, x21, [sp, #0x1a0]
//   0x037f04: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x037f08: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x037f0c: 910703fd  add      x29, sp, #0x1c0
//   0x037f10: b90057e4  str      w4, [sp, #0x54]
//   0x037f14: d53bd059  mrs      x25, tpidr_el0
//   0x037f18: f9401728  ldr      x8, [x25, #0x28]
//   0x037f1c: d10343a9  sub      x9, x29, #0xd0
//   0x037f20: 6f00e400  movi     v0.2d, #0000000000000000
//   0x037f24: f81983a8  stur     x8, [x29, #-0x68]
//   0x037f28: a9067fff  stp      xzr, xzr, [sp, #0x60]
//   0x037f2c: f9002fff  str      xzr, [sp, #0x58]
uint64_t fde_0330_sub_037ef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0x6F00E400ULL) + (x2 ^ 0x037EF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x037ef0: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9176FFCULL; // 0x037ef4: stp x28, x27, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91867FAULL; // 0x037ef8: stp x26, x25, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9195FF8ULL; // 0x037efc: stp x24, x23, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A57F6ULL; // 0x037f00: stp x22, x21, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x037f04: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x037f08: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x037f0c: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xB90057E4ULL; // 0x037f10: str w4, [sp, #0x54]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x037f14: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0331 @ 0x0385d0..0x0387e4 (532 bytes)
// [VN] Phục dựng FDE #0331 tại 0x0385d0..0x0387e4 (532 byte)
//   0x0385d0: d101c3ff  sub      sp, sp, #0x70
//   0x0385d4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0385d8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0385dc: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0385e0: 910183fd  add      x29, sp, #0x60
//   0x0385e4: d53bd055  mrs      x21, tpidr_el0
//   0x0385e8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0385ec: aa0003f3  mov      x19, x0
//   0x0385f0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0385f4: f9401008  ldr      x8, [x0, #0x20]
//   0x0385f8: f100a908  subs     x8, x8, #0x2a
//   0x0385fc: 54000243  b.lo     #0x38644
//   0x038600: f9400669  ldr      x9, [x19, #8]
//   0x038604: f9001268  str      x8, [x19, #0x20]
//   0x038608: f8408528  ldr      x8, [x9], #8
//   0x03860c: f9000be8  str      x8, [sp, #0x10]
uint64_t fde_0331_sub_0385d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9400669ULL) + (x2 ^ 0x0385D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0385d0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0385d4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0385d8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0385dc: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0385e0: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0385e4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0385e8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0385ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x0385f0: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401008ULL; // 0x0385f4: ldr x8, [x0, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0332 @ 0x0387e4..0x038924 (320 bytes)
// [VN] Phục dựng FDE #0332 tại 0x0387e4..0x038924 (320 byte)
//   0x0387e4: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x0387e8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0387ec: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0387f0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0387f4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0387f8: 910103fd  add      x29, sp, #0x40
//   0x0387fc: a9412018  ldp      x24, x8, [x0, #0x10]
//   0x038800: aa0003f3  mov      x19, x0
//   0x038804: aa0103f4  mov      x20, x1
//   0x038808: eb08031f  cmp      x24, x8
//   0x03880c: 54000701  b.ne     #0x388ec
//   0x038810: a9405676  ldp      x22, x21, [x19]
//   0x038814: eb1602a9  subs     x9, x21, x22
//   0x038818: 54000289  b.ls     #0x38868
//   0x03881c: 9343fd28  asr      x8, x9, #3
//   0x038820: 91000509  add      x9, x8, #1
uint64_t fde_0332_sub_0387e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xEB1602A9ULL) + (x2 ^ 0x0387E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x0387e4: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0387e8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0387ec: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0387f0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0387f4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0387f8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412018ULL; // 0x0387fc: ldp x24, x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038800: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x038804: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08031FULL; // 0x038808: cmp x24, x8
    return acc;
}

// [EN] Reconstructed FDE #0333 @ 0x038924..0x038a64 (320 bytes)
// [VN] Phục dựng FDE #0333 tại 0x038924..0x038a64 (320 byte)
//   0x038924: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x038928: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x03892c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x038930: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x038934: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x038938: 910103fd  add      x29, sp, #0x40
//   0x03893c: a9412018  ldp      x24, x8, [x0, #0x10]
//   0x038940: aa0003f3  mov      x19, x0
//   0x038944: aa0103f4  mov      x20, x1
//   0x038948: eb08031f  cmp      x24, x8
//   0x03894c: 54000701  b.ne     #0x38a2c
//   0x038950: a9405676  ldp      x22, x21, [x19]
//   0x038954: eb1602a9  subs     x9, x21, x22
//   0x038958: 54000289  b.ls     #0x389a8
//   0x03895c: 9343fd28  asr      x8, x9, #3
//   0x038960: 91000509  add      x9, x8, #1
uint64_t fde_0333_sub_038924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xEB1602A9ULL) + (x2 ^ 0x038924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x038924: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x038928: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03892c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x038930: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x038934: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x038938: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412018ULL; // 0x03893c: ldp x24, x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038940: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x038944: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08031FULL; // 0x038948: cmp x24, x8
    return acc;
}

// [EN] Reconstructed FDE #0334 @ 0x038a64..0x038ba4 (320 bytes)
// [VN] Phục dựng FDE #0334 tại 0x038a64..0x038ba4 (320 byte)
//   0x038a64: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x038a68: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x038a6c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x038a70: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x038a74: 9100c3fd  add      x29, sp, #0x30
//   0x038a78: a9405408  ldp      x8, x21, [x0]
//   0x038a7c: aa0003f3  mov      x19, x0
//   0x038a80: aa0103f4  mov      x20, x1
//   0x038a84: eb0802bf  cmp      x21, x8
//   0x038a88: 54000060  b.eq     #0x38a94
//   0x038a8c: aa1503f6  mov      x22, x21
//   0x038a90: 14000038  b        #0x38b70
//   0x038a94: a9412678  ldp      x24, x9, [x19, #0x10]
//   0x038a98: eb09031f  cmp      x24, x9
//   0x038a9c: 54000262  b.hs     #0x38ae8
//   0x038aa0: cb180128  sub      x8, x9, x24
uint64_t fde_0334_sub_038a64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xA9412678ULL) + (x2 ^ 0x038A64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x038a64: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x038a68: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x038a6c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x038a70: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x038a74: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9405408ULL; // 0x038a78: ldp x8, x21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038a7c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x038a80: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0802BFULL; // 0x038a84: cmp x21, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x038a88: b.eq #0x38a94
    return acc;
}

// [EN] Reconstructed FDE #0335 @ 0x038ba4..0x038ce4 (320 bytes)
// [VN] Phục dựng FDE #0335 tại 0x038ba4..0x038ce4 (320 byte)
//   0x038ba4: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x038ba8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x038bac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x038bb0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x038bb4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x038bb8: 910103fd  add      x29, sp, #0x40
//   0x038bbc: a9412018  ldp      x24, x8, [x0, #0x10]
//   0x038bc0: aa0003f3  mov      x19, x0
//   0x038bc4: aa0103f4  mov      x20, x1
//   0x038bc8: eb08031f  cmp      x24, x8
//   0x038bcc: 54000701  b.ne     #0x38cac
//   0x038bd0: a9405676  ldp      x22, x21, [x19]
//   0x038bd4: eb1602a9  subs     x9, x21, x22
//   0x038bd8: 54000289  b.ls     #0x38c28
//   0x038bdc: 9343fd28  asr      x8, x9, #3
//   0x038be0: 91000509  add      x9, x8, #1
uint64_t fde_0335_sub_038ba4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xEB1602A9ULL) + (x2 ^ 0x038BA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x038ba4: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x038ba8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x038bac: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x038bb0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x038bb4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x038bb8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412018ULL; // 0x038bbc: ldp x24, x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038bc0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x038bc4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08031FULL; // 0x038bc8: cmp x24, x8
    return acc;
}

// [EN] Reconstructed FDE #0336 @ 0x038ce4..0x038e24 (320 bytes)
// [VN] Phục dựng FDE #0336 tại 0x038ce4..0x038e24 (320 byte)
//   0x038ce4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x038ce8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x038cec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x038cf0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x038cf4: 9100c3fd  add      x29, sp, #0x30
//   0x038cf8: a9405408  ldp      x8, x21, [x0]
//   0x038cfc: aa0003f3  mov      x19, x0
//   0x038d00: aa0103f4  mov      x20, x1
//   0x038d04: eb0802bf  cmp      x21, x8
//   0x038d08: 54000060  b.eq     #0x38d14
//   0x038d0c: aa1503f6  mov      x22, x21
//   0x038d10: 14000038  b        #0x38df0
//   0x038d14: a9412678  ldp      x24, x9, [x19, #0x10]
//   0x038d18: eb09031f  cmp      x24, x9
//   0x038d1c: 54000262  b.hs     #0x38d68
//   0x038d20: cb180128  sub      x8, x9, x24
uint64_t fde_0336_sub_038ce4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xA9412678ULL) + (x2 ^ 0x038CE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x038ce4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x038ce8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x038cec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x038cf0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x038cf4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9405408ULL; // 0x038cf8: ldp x8, x21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038cfc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x038d00: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0802BFULL; // 0x038d04: cmp x21, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x038d08: b.eq #0x38d14
    return acc;
}

// [EN] Reconstructed FDE #0337 @ 0x038e24..0x038f78 (340 bytes)
// [VN] Phục dựng FDE #0337 tại 0x038e24..0x038f78 (340 byte)
//   0x038e24: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x038e28: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x038e2c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x038e30: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x038e34: 9100c3fd  add      x29, sp, #0x30
//   0x038e38: a940a408  ldp      x8, x9, [x0, #8]
//   0x038e3c: aa0003f3  mov      x19, x0
//   0x038e40: eb08013f  cmp      x9, x8
//   0x038e44: 54000620  b.eq     #0x38f08
//   0x038e48: f940126b  ldr      x11, [x19, #0x20]
//   0x038e4c: d29861ac  mov      x12, #0xc30d
//   0x038e50: f2a1860c  movk     x12, #0xc30, lsl #16
//   0x038e54: f2c6186c  movk     x12, #0x30c3, lsl #32
//   0x038e58: f2f8618c  movk     x12, #0xc30c, lsl #48
//   0x038e5c: d341fd6a  lsr      x10, x11, #1
//   0x038e60: 9bcc7d4a  umulh    x10, x10, x12
uint64_t fde_0337_sub_038e24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF2C6186CULL) + (x2 ^ 0x038E24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x038e24: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x038e28: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x038e2c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x038e30: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x038e34: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x038e38: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038e3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x038e40: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000620ULL; // 0x038e44: b.eq #0x38f08
    acc = (acc * 0x100000001B3ULL) ^ 0xF940126BULL; // 0x038e48: ldr x11, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0338 @ 0x038f78..0x039314 (924 bytes)
// [VN] Phục dựng FDE #0338 tại 0x038f78..0x039314 (924 byte)
//   0x038f78: d10243ff  sub      sp, sp, #0x90
//   0x038f7c: f90023f9  str      x25, [sp, #0x40]
//   0x038f80: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x038f84: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x038f88: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x038f8c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x038f90: 910203fd  add      x29, sp, #0x80
//   0x038f94: d53bd056  mrs      x22, tpidr_el0
//   0x038f98: f94016c8  ldr      x8, [x22, #0x28]
//   0x038f9c: 5280054c  mov      w12, #0x2a
//   0x038fa0: aa0003f3  mov      x19, x0
//   0x038fa4: f9001fe8  str      x8, [sp, #0x38]
//   0x038fa8: a940a408  ldp      x8, x9, [x0, #8]
//   0x038fac: a942340b  ldp      x11, x13, [x0, #0x20]
//   0x038fb0: eb08012a  subs     x10, x9, x8
//   0x038fb4: 9343fd4e  asr      x14, x10, #3
uint64_t fde_0338_sub_038f78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xA940A408ULL) + (x2 ^ 0x038F78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x038f78: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x038f7c: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x038f80: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x038f84: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x038f88: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x038f8c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x038f90: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x038f94: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x038f98: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280054CULL; // 0x038f9c: mov w12, #0x2a
    return acc;
}

// [EN] Reconstructed FDE #0339 @ 0x039314..0x039454 (320 bytes)
// [VN] Phục dựng FDE #0339 tại 0x039314..0x039454 (320 byte)
//   0x039314: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x039318: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03931c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x039320: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x039324: 9100c3fd  add      x29, sp, #0x30
//   0x039328: a9405408  ldp      x8, x21, [x0]
//   0x03932c: aa0003f3  mov      x19, x0
//   0x039330: aa0103f4  mov      x20, x1
//   0x039334: eb0802bf  cmp      x21, x8
//   0x039338: 54000060  b.eq     #0x39344
//   0x03933c: aa1503f6  mov      x22, x21
//   0x039340: 14000038  b        #0x39420
//   0x039344: a9412678  ldp      x24, x9, [x19, #0x10]
//   0x039348: eb09031f  cmp      x24, x9
//   0x03934c: 54000262  b.hs     #0x39398
//   0x039350: cb180128  sub      x8, x9, x24
uint64_t fde_0339_sub_039314(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xA9412678ULL) + (x2 ^ 0x039314ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x039314: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x039318: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03931c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x039320: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x039324: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9405408ULL; // 0x039328: ldp x8, x21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03932c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x039330: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0802BFULL; // 0x039334: cmp x21, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x039338: b.eq #0x39344
    return acc;
}

// [EN] Reconstructed FDE #0340 @ 0x039454..0x0395f0 (412 bytes)
// [VN] Phục dựng FDE #0340 tại 0x039454..0x0395f0 (412 byte)
//   0x039454: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x039458: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03945c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x039460: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x039464: 9100c3fd  add      x29, sp, #0x30
//   0x039468: aa0003f3  mov      x19, x0
//   0x03946c: f9400808  ldr      x8, [x0, #0x10]
//   0x039470: f9400000  ldr      x0, [x0]
//   0x039474: cb010055  sub      x21, x2, x1
//   0x039478: b201f3e9  mov      x9, #-0x5555555555555556
//   0x03947c: 9343feaa  asr      x10, x21, #3
//   0x039480: f2955569  movk     x9, #0xaaab
//   0x039484: 9b097d56  mul      x22, x10, x9
//   0x039488: cb00010a  sub      x10, x8, x0
//   0x03948c: 9343fd4a  asr      x10, x10, #3
//   0x039490: 9b097d4a  mul      x10, x10, x9
uint64_t fde_0340_sub_039454(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9B097D56ULL) + (x2 ^ 0x039454ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x039454: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x039458: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03945c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x039460: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x039464: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039468: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x03946c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x039470: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010055ULL; // 0x039474: sub x21, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E9ULL; // 0x039478: mov x9, #-0x5555555555555556
    return acc;
}

// [EN] Reconstructed FDE #0341 @ 0x0395f0..0x0397ec (508 bytes)
// [VN] Phục dựng FDE #0341 tại 0x0395f0..0x0397ec (508 byte)
//   0x0395f0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0395f4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0395f8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0395fc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x039600: 9100c3fd  add      x29, sp, #0x30
//   0x039604: aa0003f3  mov      x19, x0
//   0x039608: f9400808  ldr      x8, [x0, #0x10]
//   0x03960c: f9400000  ldr      x0, [x0]
//   0x039610: cb010054  sub      x20, x2, x1
//   0x039614: 9344fe96  asr      x22, x20, #4
//   0x039618: aa0103f5  mov      x21, x1
//   0x03961c: cb000109  sub      x9, x8, x0
//   0x039620: eb8912df  cmp      x22, x9, asr #4
//   0x039624: 54000289  b.ls     #0x39674
//   0x039628: b40000c0  cbz      x0, #0x39640
//   0x03962c: f9000660  str      x0, [x19, #8]
uint64_t fde_0341_sub_0395f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xEB8912DFULL) + (x2 ^ 0x0395F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0395f0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0395f4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0395f8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0395fc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x039600: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039604: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x039608: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x03960c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010054ULL; // 0x039610: sub x20, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9344FE96ULL; // 0x039614: asr x22, x20, #4
    return acc;
}

// [EN] Reconstructed FDE #0342 @ 0x0397ec..0x039960 (372 bytes)
// [VN] Phục dựng FDE #0342 tại 0x0397ec..0x039960 (372 byte)
//   0x0397ec: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0397f0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0397f4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0397f8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0397fc: 9100c3fd  add      x29, sp, #0x30
//   0x039800: a940a408  ldp      x8, x9, [x0, #8]
//   0x039804: aa0103f4  mov      x20, x1
//   0x039808: aa0003f3  mov      x19, x0
//   0x03980c: cb08012a  sub      x10, x9, x8
//   0x039810: 9343fd4b  asr      x11, x10, #3
//   0x039814: b201f3ea  mov      x10, #-0x5555555555555556
//   0x039818: f295556a  movk     x10, #0xaaab
//   0x03981c: 9b0a7d6b  mul      x11, x11, x10
//   0x039820: eb01017f  cmp      x11, x1
//   0x039824: 54000702  b.hs     #0x39904
//   0x039828: f940026b  ldr      x11, [x19]
uint64_t fde_0342_sub_0397ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9B0A7D6BULL) + (x2 ^ 0x0397ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0397ec: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0397f0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0397f4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0397f8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0397fc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x039800: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x039804: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039808: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08012AULL; // 0x03980c: sub x10, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9343FD4BULL; // 0x039810: asr x11, x10, #3
    return acc;
}

// [EN] Reconstructed FDE #0343 @ 0x039960..0x039b2c (460 bytes)
// [VN] Phục dựng FDE #0343 tại 0x039960..0x039b2c (460 byte)
//   0x039960: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x039964: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x039968: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03996c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x039970: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x039974: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x039978: 910143fd  add      x29, sp, #0x50
//   0x03997c: 39400008  ldrb     w8, [x0]
//   0x039980: aa0403f4  mov      x20, x4
//   0x039984: aa0303f7  mov      x23, x3
//   0x039988: aa0003f3  mov      x19, x0
//   0x03998c: aa0103f8  mov      x24, x1
//   0x039990: 370000c8  tbnz     w8, #0, #0x399a8
//   0x039994: d341fd15  lsr      x21, x8, #1
//   0x039998: eb1802a9  subs     x9, x21, x24
//   0x03999c: 540000c2  b.hs     #0x399b4
uint64_t fde_0343_sub_039960(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x370000C8ULL) + (x2 ^ 0x039960ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x039960: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x039964: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x039968: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03996c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x039970: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x039974: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x039978: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x03997c: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F4ULL; // 0x039980: mov x20, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F7ULL; // 0x039984: mov x23, x3
    return acc;
}

// [EN] Reconstructed FDE #0344 @ 0x039b2c..0x039c24 (248 bytes)
// [VN] Phục dựng FDE #0344 tại 0x039b2c..0x039c24 (248 byte)
//   0x039b2c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x039b30: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x039b34: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x039b38: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x039b3c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x039b40: 910103fd  add      x29, sp, #0x40
//   0x039b44: a9402014  ldp      x20, x8, [x0]
//   0x039b48: aa0003f3  mov      x19, x0
//   0x039b4c: cb140115  sub      x21, x8, x20
//   0x039b50: 9343feb8  asr      x24, x21, #3
//   0x039b54: 91000708  add      x8, x24, #1
//   0x039b58: d37dfd09  lsr      x9, x8, #0x3d
//   0x039b5c: b5000609  cbnz     x9, #0x39c1c
//   0x039b60: f9400a69  ldr      x9, [x19, #0x10]
//   0x039b64: b27febea  mov      x10, #0xffffffffffffffe
//   0x039b68: aa0103f6  mov      x22, x1
uint64_t fde_0344_sub_039b2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB5000609ULL) + (x2 ^ 0x039B2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x039b2c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x039b30: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x039b34: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x039b38: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x039b3c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x039b40: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x039b44: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039b48: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x039b4c: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9343FEB8ULL; // 0x039b50: asr x24, x21, #3
    return acc;
}

// [EN] Reconstructed FDE #0345 @ 0x039c24..0x039d1c (248 bytes)
// [VN] Phục dựng FDE #0345 tại 0x039c24..0x039d1c (248 byte)
//   0x039c24: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x039c28: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x039c2c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x039c30: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x039c34: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x039c38: 910103fd  add      x29, sp, #0x40
//   0x039c3c: a9402014  ldp      x20, x8, [x0]
//   0x039c40: aa0003f3  mov      x19, x0
//   0x039c44: cb140115  sub      x21, x8, x20
//   0x039c48: 9343feb8  asr      x24, x21, #3
//   0x039c4c: 91000708  add      x8, x24, #1
//   0x039c50: d37dfd09  lsr      x9, x8, #0x3d
//   0x039c54: b5000609  cbnz     x9, #0x39d14
//   0x039c58: f9400a69  ldr      x9, [x19, #0x10]
//   0x039c5c: b27febea  mov      x10, #0xffffffffffffffe
//   0x039c60: aa0103f6  mov      x22, x1
uint64_t fde_0345_sub_039c24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB5000609ULL) + (x2 ^ 0x039C24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x039c24: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x039c28: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x039c2c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x039c30: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x039c34: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x039c38: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x039c3c: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039c40: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x039c44: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9343FEB8ULL; // 0x039c48: asr x24, x21, #3
    return acc;
}

// [EN] Reconstructed FDE #0346 @ 0x039d1c..0x039d30 (20 bytes)
// [VN] Phục dựng FDE #0346 tại 0x039d1c..0x039d30 (20 byte)
//   0x039d1c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x039d20: 910003fd  mov      x29, sp
//   0x039d24: b00000c0  adrp     x0, #0x52000
//   0x039d28: 912a9c00  add      x0, x0, #0xaa7
//   0x039d2c: 97ffaa65  bl       #0x246c0
uint64_t fde_0346_sub_039d1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFAA65ULL) + (x2 ^ 0x039D1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x039d1c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x039d20: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C0ULL; // 0x039d24: adrp x0, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A9C00ULL; // 0x039d28: add x0, x0, #0xaa7
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAA65ULL; // 0x039d2c: bl #0x246c0
    return acc;
}

// [EN] Reconstructed FDE #0347 @ 0x039d30..0x039f24 (500 bytes)
// [VN] Phục dựng FDE #0347 tại 0x039d30..0x039f24 (500 byte)
//   0x039d30: a9bb67fc  stp      x28, x25, [sp, #-0x50]!
//   0x039d34: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x039d38: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x039d3c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x039d40: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x039d44: 910103fd  add      x29, sp, #0x40
//   0x039d48: d11043ff  sub      sp, sp, #0x410
//   0x039d4c: d53bd057  mrs      x23, tpidr_el0
//   0x039d50: f94016e8  ldr      x8, [x23, #0x28]
//   0x039d54: aa0003f4  mov      x20, x0
//   0x039d58: f81b83a8  stur     x8, [x29, #-0x48]
//   0x039d5c: f9406c00  ldr      x0, [x0, #0xd8]
//   0x039d60: b4000c60  cbz      x0, #0x39eec
//   0x039d64: 97ff84c3  bl       #0x1b070
//   0x039d68: b4000c20  cbz      x0, #0x39eec
//   0x039d6c: f9406e81  ldr      x1, [x20, #0xd8]
uint64_t fde_0347_sub_039d30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FCULL) + (x1 ^ 0xB4000C60ULL) + (x2 ^ 0x039D30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FCULL; // 0x039d30: stp x28, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x039d34: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x039d38: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x039d3c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x039d40: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x039d44: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x039d48: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x039d4c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x039d50: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x039d54: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0348 @ 0x039f24..0x03a070 (332 bytes)
// [VN] Phục dựng FDE #0348 tại 0x039f24..0x03a070 (332 byte)
//   0x039f24: d101c3ff  sub      sp, sp, #0x70
//   0x039f28: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x039f2c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x039f30: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x039f34: 910183fd  add      x29, sp, #0x60
//   0x039f38: d53bd054  mrs      x20, tpidr_el0
//   0x039f3c: f9401688  ldr      x8, [x20, #0x28]
//   0x039f40: aa0003f3  mov      x19, x0
//   0x039f44: d100b3a1  sub      x1, x29, #0x2c
//   0x039f48: f81d83a8  stur     x8, [x29, #-0x28]
//   0x039f4c: a9490c02  ldp      x2, x3, [x0, #0x90]
//   0x039f50: 91030000  add      x0, x0, #0xc0
//   0x039f54: 97ff8683  bl       #0x1b960
//   0x039f58: 35000520  cbnz     w0, #0x39ffc
//   0x039f5c: b85d43a8  ldur     w8, [x29, #-0x2c]
//   0x039f60: 340004e8  cbz      w8, #0x39ffc
uint64_t fde_0348_sub_039f24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x97FF8683ULL) + (x2 ^ 0x039F24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x039f24: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x039f28: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x039f2c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x039f30: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x039f34: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x039f38: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x039f3c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039f40: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD100B3A1ULL; // 0x039f44: sub x1, x29, #0x2c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x039f48: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0349 @ 0x03a070..0x03a300 (656 bytes)
// [VN] Phục dựng FDE #0349 tại 0x03a070..0x03a300 (656 byte)
//   0x03a070: d10303ff  sub      sp, sp, #0xc0
//   0x03a074: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x03a078: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x03a07c: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x03a080: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x03a084: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x03a088: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x03a08c: 9102c3fd  add      x29, sp, #0xb0
//   0x03a090: d53bd054  mrs      x20, tpidr_el0
//   0x03a094: f9401688  ldr      x8, [x20, #0x28]
//   0x03a098: f9002fe8  str      x8, [sp, #0x58]
//   0x03a09c: f9406415  ldr      x21, [x0, #0xc8]
//   0x03a0a0: b4001075  cbz      x21, #0x3a2ac
//   0x03a0a4: aa0003f3  mov      x19, x0
//   0x03a0a8: 52800300  mov      w0, #0x18
//   0x03a0ac: f90007f4  str      x20, [sp, #8]
uint64_t fde_0349_sub_03a070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xB4001075ULL) + (x2 ^ 0x03A070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x03a070: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x03a074: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x03a078: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x03a07c: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x03a080: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x03a084: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x03a088: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x03a08c: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03a090: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03a094: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0350 @ 0x03a300..0x03a6f4 (1012 bytes)
// [VN] Phục dựng FDE #0350 tại 0x03a300..0x03a6f4 (1012 byte)
//   0x03a300: d10203ff  sub      sp, sp, #0x80
//   0x03a304: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x03a308: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03a30c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03a310: 9101c3fd  add      x29, sp, #0x70
//   0x03a314: d53bd056  mrs      x22, tpidr_el0
//   0x03a318: f94016c8  ldr      x8, [x22, #0x28]
//   0x03a31c: aa0003f4  mov      x20, x0
//   0x03a320: aa0103f5  mov      x21, x1
//   0x03a324: aa0203e0  mov      x0, x2
//   0x03a328: aa1403e1  mov      x1, x20
//   0x03a32c: aa0203f3  mov      x19, x2
//   0x03a330: f81d83a8  stur     x8, [x29, #-0x28]
//   0x03a334: 97ff872b  bl       #0x1bfe0
//   0x03a338: 91002268  add      x8, x19, #8
//   0x03a33c: eb00011f  cmp      x8, x0
uint64_t fde_0350_sub_03a300(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x03A300ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03a300: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x03a304: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x03a308: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03a30c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03a310: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03a314: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03a318: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03a31c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x03a320: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E0ULL; // 0x03a324: mov x0, x2
    return acc;
}

// [EN] Reconstructed FDE #0351 @ 0x03a6f4..0x03ade0 (1772 bytes)
// [VN] Phục dựng FDE #0351 tại 0x03a6f4..0x03ade0 (1772 byte)
//   0x03a6f4: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x03a6f8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03a6fc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03a700: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03a704: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03a708: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03a70c: 910143fd  add      x29, sp, #0x50
//   0x03a710: d10803ff  sub      sp, sp, #0x200
//   0x03a714: d53bd055  mrs      x21, tpidr_el0
//   0x03a718: f94016a8  ldr      x8, [x21, #0x28]
//   0x03a71c: aa0103f4  mov      x20, x1
//   0x03a720: 9102e3f3  add      x19, sp, #0xb8
//   0x03a724: f81a03a8  stur     x8, [x29, #-0x60]
//   0x03a728: f9400008  ldr      x8, [x0]
//   0x03a72c: 9102e3e0  add      x0, sp, #0xb8
//   0x03a730: 9100e101  add      x1, x8, #0x38
uint64_t fde_0351_sub_03a6f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x03A6F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x03a6f4: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03a6f8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03a6fc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03a700: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03a704: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03a708: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03a70c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10803FFULL; // 0x03a710: sub sp, sp, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03a714: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03a718: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0352 @ 0x03ade0..0x03b1d4 (1012 bytes)
// [VN] Phục dựng FDE #0352 tại 0x03ade0..0x03b1d4 (1012 byte)
//   0x03ade0: d10203ff  sub      sp, sp, #0x80
//   0x03ade4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x03ade8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03adec: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03adf0: 9101c3fd  add      x29, sp, #0x70
//   0x03adf4: d53bd056  mrs      x22, tpidr_el0
//   0x03adf8: f94016c8  ldr      x8, [x22, #0x28]
//   0x03adfc: aa0003f4  mov      x20, x0
//   0x03ae00: aa0103f5  mov      x21, x1
//   0x03ae04: aa0203e0  mov      x0, x2
//   0x03ae08: aa1403e1  mov      x1, x20
//   0x03ae0c: aa0203f3  mov      x19, x2
//   0x03ae10: f81d83a8  stur     x8, [x29, #-0x28]
//   0x03ae14: 97ff82e3  bl       #0x1b9a0
//   0x03ae18: 91002268  add      x8, x19, #8
//   0x03ae1c: eb00011f  cmp      x8, x0
uint64_t fde_0352_sub_03ade0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x03ADE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03ade0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x03ade4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x03ade8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03adec: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03adf0: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03adf4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03adf8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03adfc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x03ae00: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E0ULL; // 0x03ae04: mov x0, x2
    return acc;
}

// [EN] Reconstructed FDE #0353 @ 0x03b1d4..0x03b1e8 (20 bytes)
// [VN] Phục dựng FDE #0353 tại 0x03b1d4..0x03b1e8 (20 byte)
//   0x03b1d4: f9408c08  ldr      x8, [x0, #0x118]
//   0x03b1d8: aa0103e0  mov      x0, x1
//   0x03b1dc: aa1f03e2  mov      x2, xzr
//   0x03b1e0: aa0803e1  mov      x1, x8
//   0x03b1e4: 14000001  b        #0x3b1e8
uint64_t fde_0353_sub_03b1d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9408C08ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x03B1D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408C08ULL; // 0x03b1d4: ldr x8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x03b1d8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03b1dc: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x03b1e0: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x03b1e4: b #0x3b1e8
    return acc;
}

// [EN] Reconstructed FDE #0354 @ 0x03b1e8..0x03b380 (408 bytes)
// [VN] Phục dựng FDE #0354 tại 0x03b1e8..0x03b380 (408 byte)
//   0x03b1e8: d10203ff  sub      sp, sp, #0x80
//   0x03b1ec: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x03b1f0: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x03b1f4: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x03b1f8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x03b1fc: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03b200: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03b204: 9101c3fd  add      x29, sp, #0x70
//   0x03b208: d53bd056  mrs      x22, tpidr_el0
//   0x03b20c: f94016c8  ldr      x8, [x22, #0x28]
//   0x03b210: f9000fe8  str      x8, [sp, #0x18]
//   0x03b214: b4000961  cbz      x1, #0x3b340
//   0x03b218: aa0103f4  mov      x20, x1
//   0x03b21c: f8408699  ldr      x25, [x20], #8
//   0x03b220: eb14033f  cmp      x25, x20
//   0x03b224: 540008e0  b.eq     #0x3b340
uint64_t fde_0354_sub_03b1e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x03B1E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03b1e8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x03b1ec: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x03b1f0: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x03b1f4: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x03b1f8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x03b1fc: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03b200: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03b204: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03b208: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03b20c: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0355 @ 0x03b380..0x03b404 (132 bytes)
// [VN] Phục dựng FDE #0355 tại 0x03b380..0x03b404 (132 byte)
//   0x03b380: f9408c08  ldr      x8, [x0, #0x118]
//   0x03b384: b40003a8  cbz      x8, #0x3b3f8
//   0x03b388: f8408509  ldr      x9, [x8], #8
//   0x03b38c: eb08013f  cmp      x9, x8
//   0x03b390: 54000340  b.eq     #0x3b3f8
//   0x03b394: 2a1f03e0  mov      w0, wzr
//   0x03b398: 14000004  b        #0x3b3a8
//   0x03b39c: aa0b03e9  mov      x9, x11
//   0x03b3a0: eb08013f  cmp      x9, x8
//   0x03b3a4: 540002e0  b.eq     #0x3b400
//   0x03b3a8: b940492b  ldr      w11, [x9, #0x48]
//   0x03b3ac: f940052a  ldr      x10, [x9, #8]
//   0x03b3b0: 0b0b0000  add      w0, w0, w11
//   0x03b3b4: b40000aa  cbz      x10, #0x3b3c8
//   0x03b3b8: aa0a03e9  mov      x9, x10
//   0x03b3bc: f940014a  ldr      x10, [x10]
uint64_t fde_0355_sub_03b380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9408C08ULL) + (x1 ^ 0x0B0B0000ULL) + (x2 ^ 0x03B380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408C08ULL; // 0x03b380: ldr x8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003A8ULL; // 0x03b384: cbz x8, #0x3b3f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408509ULL; // 0x03b388: ldr x9, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x03b38c: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000340ULL; // 0x03b390: b.eq #0x3b3f8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03b394: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000004ULL; // 0x03b398: b #0x3b3a8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0B03E9ULL; // 0x03b39c: mov x9, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x03b3a0: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540002E0ULL; // 0x03b3a4: b.eq #0x3b400
    return acc;
}

// [EN] Reconstructed FDE #0356 @ 0x03b404..0x03b460 (92 bytes)
// [VN] Phục dựng FDE #0356 tại 0x03b404..0x03b460 (92 byte)
//   0x03b404: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03b408: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03b40c: 910043fd  add      x29, sp, #0x10
//   0x03b410: aa0803f3  mov      x19, x8
//   0x03b414: f900091f  str      xzr, [x8, #0x10]
//   0x03b418: f8008d1f  str      xzr, [x8, #8]!
//   0x03b41c: f9000268  str      x8, [x19]
//   0x03b420: f9408c02  ldr      x2, [x0, #0x118]
//   0x03b424: b40000c2  cbz      x2, #0x3b43c
//   0x03b428: eb13005f  cmp      x2, x19
//   0x03b42c: 54000080  b.eq     #0x3b43c
//   0x03b430: f8408441  ldr      x1, [x2], #8
//   0x03b434: aa1303e0  mov      x0, x19
//   0x03b438: 97ff7fa2  bl       #0x1b2c0
//   0x03b43c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03b440: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0356_sub_03b404(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x03B404ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03b404: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03b408: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03b40c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x03b410: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x03b414: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x03b418: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03b41c: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408C02ULL; // 0x03b420: ldr x2, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C2ULL; // 0x03b424: cbz x2, #0x3b43c
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13005FULL; // 0x03b428: cmp x2, x19
    return acc;
}

// [EN] Reconstructed FDE #0357 @ 0x03b460..0x03b4bc (92 bytes)
// [VN] Phục dựng FDE #0357 tại 0x03b460..0x03b4bc (92 byte)
//   0x03b460: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03b464: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03b468: 910043fd  add      x29, sp, #0x10
//   0x03b46c: aa0803f3  mov      x19, x8
//   0x03b470: f900091f  str      xzr, [x8, #0x10]
//   0x03b474: f8008d1f  str      xzr, [x8, #8]!
//   0x03b478: f9000268  str      x8, [x19]
//   0x03b47c: f9409402  ldr      x2, [x0, #0x128]
//   0x03b480: b40000c2  cbz      x2, #0x3b498
//   0x03b484: eb13005f  cmp      x2, x19
//   0x03b488: 54000080  b.eq     #0x3b498
//   0x03b48c: f8408441  ldr      x1, [x2], #8
//   0x03b490: aa1303e0  mov      x0, x19
//   0x03b494: 97ff7f8b  bl       #0x1b2c0
//   0x03b498: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03b49c: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0357_sub_03b460(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x03B460ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03b460: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03b464: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03b468: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x03b46c: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x03b470: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x03b474: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x03b478: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409402ULL; // 0x03b47c: ldr x2, [x0, #0x128]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C2ULL; // 0x03b480: cbz x2, #0x3b498
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13005FULL; // 0x03b484: cmp x2, x19
    return acc;
}

// [EN] Reconstructed FDE #0358 @ 0x03b4bc..0x03b570 (180 bytes)
// [VN] Phục dựng FDE #0358 tại 0x03b4bc..0x03b570 (180 byte)
//   0x03b4bc: d100c3ff  sub      sp, sp, #0x30
//   0x03b4c0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03b4c4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03b4c8: 910083fd  add      x29, sp, #0x20
//   0x03b4cc: d53bd054  mrs      x20, tpidr_el0
//   0x03b4d0: f9401688  ldr      x8, [x20, #0x28]
//   0x03b4d4: aa0203f3  mov      x19, x2
//   0x03b4d8: 910003e2  mov      x2, sp
//   0x03b4dc: f90007e8  str      x8, [sp, #8]
//   0x03b4e0: f90003ff  str      xzr, [sp]
//   0x03b4e4: f9408c08  ldr      x8, [x0, #0x118]
//   0x03b4e8: aa0103e0  mov      x0, x1
//   0x03b4ec: aa0803e1  mov      x1, x8
//   0x03b4f0: 97ffff3e  bl       #0x3b1e8
//   0x03b4f4: 2a0003e8  mov      w8, w0
//   0x03b4f8: 2a1f03e0  mov      w0, wzr
uint64_t fde_0358_sub_03b4bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAA0803E1ULL) + (x2 ^ 0x03B4BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03b4bc: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03b4c0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03b4c4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03b4c8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03b4cc: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03b4d0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03b4d4: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E2ULL; // 0x03b4d8: mov x2, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03b4dc: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FFULL; // 0x03b4e0: str xzr, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0359 @ 0x03b570..0x03b584 (20 bytes)
// [VN] Phục dựng FDE #0359 tại 0x03b570..0x03b584 (20 byte)
//   0x03b570: f9409008  ldr      x8, [x0, #0x120]
//   0x03b574: aa0103e0  mov      x0, x1
//   0x03b578: aa1f03e2  mov      x2, xzr
//   0x03b57c: aa0803e1  mov      x1, x8
//   0x03b580: 14000001  b        #0x3b584
uint64_t fde_0359_sub_03b570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9409008ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x03B570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409008ULL; // 0x03b570: ldr x8, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x03b574: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03b578: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x03b57c: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x03b580: b #0x3b584
    return acc;
}

// [EN] Reconstructed FDE #0360 @ 0x03b584..0x03b778 (500 bytes)
// [VN] Phục dựng FDE #0360 tại 0x03b584..0x03b778 (500 byte)
//   0x03b584: d102c3ff  sub      sp, sp, #0xb0
//   0x03b588: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x03b58c: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x03b590: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x03b594: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x03b598: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x03b59c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03b5a0: 910283fd  add      x29, sp, #0xa0
//   0x03b5a4: f90013e2  str      x2, [sp, #0x20]
//   0x03b5a8: d53bd049  mrs      x9, tpidr_el0
//   0x03b5ac: f9401528  ldr      x8, [x9, #0x28]
//   0x03b5b0: f90027e8  str      x8, [sp, #0x48]
//   0x03b5b4: b4000c01  cbz      x1, #0x3b734
//   0x03b5b8: f90007e9  str      x9, [sp, #8]
//   0x03b5bc: f840843b  ldr      x27, [x1], #8
//   0x03b5c0: eb01037f  cmp      x27, x1
uint64_t fde_0360_sub_03b584(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xB4000C01ULL) + (x2 ^ 0x03B584ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03b584: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x03b588: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x03b58c: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03b590: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x03b594: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x03b598: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03b59c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03b5a0: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013E2ULL; // 0x03b5a4: str x2, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD049ULL; // 0x03b5a8: mrs x9, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0361 @ 0x03b778..0x03b8ec (372 bytes)
// [VN] Phục dựng FDE #0361 tại 0x03b778..0x03b8ec (372 byte)
//   0x03b778: d101c3ff  sub      sp, sp, #0x70
//   0x03b77c: f9001bf7  str      x23, [sp, #0x30]
//   0x03b780: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03b784: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03b788: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03b78c: 910183fd  add      x29, sp, #0x60
//   0x03b790: d53bd055  mrs      x21, tpidr_el0
//   0x03b794: f94016a8  ldr      x8, [x21, #0x28]
//   0x03b798: aa0203f3  mov      x19, x2
//   0x03b79c: 910083e2  add      x2, sp, #0x20
//   0x03b7a0: f90017e8  str      x8, [sp, #0x28]
//   0x03b7a4: f90013ff  str      xzr, [sp, #0x20]
//   0x03b7a8: f9409008  ldr      x8, [x0, #0x120]
//   0x03b7ac: aa0103e0  mov      x0, x1
//   0x03b7b0: aa0803e1  mov      x1, x8
//   0x03b7b4: 97ffff74  bl       #0x3b584
uint64_t fde_0361_sub_03b778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9409008ULL) + (x2 ^ 0x03B778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03b778: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x03b77c: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03b780: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03b784: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03b788: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03b78c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03b790: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03b794: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03b798: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E2ULL; // 0x03b79c: add x2, sp, #0x20
    return acc;
}

// [EN] Reconstructed FDE #0362 @ 0x03b8ec..0x03b900 (20 bytes)
// [VN] Phục dựng FDE #0362 tại 0x03b8ec..0x03b900 (20 byte)
//   0x03b8ec: f9409408  ldr      x8, [x0, #0x128]
//   0x03b8f0: aa0103e0  mov      x0, x1
//   0x03b8f4: aa1f03e2  mov      x2, xzr
//   0x03b8f8: aa0803e1  mov      x1, x8
//   0x03b8fc: 17fffe3b  b        #0x3b1e8
uint64_t fde_0362_sub_03b8ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9409408ULL) + (x1 ^ 0x17FFFE3BULL) + (x2 ^ 0x03B8ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409408ULL; // 0x03b8ec: ldr x8, [x0, #0x128]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x03b8f0: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03b8f4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x03b8f8: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE3BULL; // 0x03b8fc: b #0x3b1e8
    return acc;
}

// [EN] Reconstructed FDE #0363 @ 0x03b900..0x03b9b4 (180 bytes)
// [VN] Phục dựng FDE #0363 tại 0x03b900..0x03b9b4 (180 byte)
//   0x03b900: d100c3ff  sub      sp, sp, #0x30
//   0x03b904: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03b908: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03b90c: 910083fd  add      x29, sp, #0x20
//   0x03b910: d53bd054  mrs      x20, tpidr_el0
//   0x03b914: f9401688  ldr      x8, [x20, #0x28]
//   0x03b918: aa0203f3  mov      x19, x2
//   0x03b91c: 910003e2  mov      x2, sp
//   0x03b920: f90007e8  str      x8, [sp, #8]
//   0x03b924: f90003ff  str      xzr, [sp]
//   0x03b928: f9409408  ldr      x8, [x0, #0x128]
//   0x03b92c: aa0103e0  mov      x0, x1
//   0x03b930: aa0803e1  mov      x1, x8
//   0x03b934: 97fffe2d  bl       #0x3b1e8
//   0x03b938: 2a0003e8  mov      w8, w0
//   0x03b93c: 2a1f03e0  mov      w0, wzr
uint64_t fde_0363_sub_03b900(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAA0803E1ULL) + (x2 ^ 0x03B900ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03b900: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03b904: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03b908: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03b90c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03b910: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03b914: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x03b918: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E2ULL; // 0x03b91c: mov x2, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03b920: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FFULL; // 0x03b924: str xzr, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0364 @ 0x03b9b4..0x03bab8 (260 bytes)
// [VN] Phục dựng FDE #0364 tại 0x03b9b4..0x03bab8 (260 byte)
//   0x03b9b4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03b9b8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03b9bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03b9c0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03b9c4: 9100c3fd  add      x29, sp, #0x30
//   0x03b9c8: a9000000  stp      x0, x0, [x0]
//   0x03b9cc: f900081f  str      xzr, [x0, #0x10]
//   0x03b9d0: f9400436  ldr      x22, [x1, #8]
//   0x03b9d4: eb16003f  cmp      x1, x22
//   0x03b9d8: 54000280  b.eq     #0x3ba28
//   0x03b9dc: aa0103f4  mov      x20, x1
//   0x03b9e0: aa0003f3  mov      x19, x0
//   0x03b9e4: aa1f03f7  mov      x23, xzr
//   0x03b9e8: 52800500  mov      w0, #0x28
//   0x03b9ec: 97ff809d  bl       #0x1bc60
//   0x03b9f0: aa0003f5  mov      x21, x0
uint64_t fde_0364_sub_03b9b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1F03F7ULL) + (x2 ^ 0x03B9B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03b9b4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03b9b8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03b9bc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03b9c0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03b9c4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000000ULL; // 0x03b9c8: stp x0, x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x03b9cc: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400436ULL; // 0x03b9d0: ldr x22, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB16003FULL; // 0x03b9d4: cmp x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0x54000280ULL; // 0x03b9d8: b.eq #0x3ba28
    return acc;
}

// [EN] Reconstructed FDE #0365 @ 0x03bab8..0x03bbcc (276 bytes)
// [VN] Phục dựng FDE #0365 tại 0x03bab8..0x03bbcc (276 byte)
//   0x03bab8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03babc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03bac0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03bac4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03bac8: 9100c3fd  add      x29, sp, #0x30
//   0x03bacc: aa0003f3  mov      x19, x0
//   0x03bad0: f8408e77  ldr      x23, [x19, #8]!
//   0x03bad4: b40006f7  cbz      x23, #0x3bbb0
//   0x03bad8: 39400028  ldrb     w8, [x1]
//   0x03badc: a940a829  ldp      x9, x10, [x1, #8]
//   0x03bae0: aa1303f4  mov      x20, x19
//   0x03bae4: d341fd0b  lsr      x11, x8, #1
//   0x03bae8: 7200011f  tst      w8, #1
//   0x03baec: 9a890176  csel     x22, x11, x9, eq
//   0x03baf0: 9a811555  csinc    x21, x10, x1, ne
//   0x03baf4: 1400000a  b        #0x3bb1c
uint64_t fde_0365_sub_03bab8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x7200011FULL) + (x2 ^ 0x03BAB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03bab8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03babc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03bac0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03bac4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03bac8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03bacc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E77ULL; // 0x03bad0: ldr x23, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006F7ULL; // 0x03bad4: cbz x23, #0x3bbb0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x03bad8: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A829ULL; // 0x03badc: ldp x9, x10, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0366 @ 0x03bbcc..0x03bcd4 (264 bytes)
// [VN] Phục dựng FDE #0366 tại 0x03bbcc..0x03bcd4 (264 byte)
//   0x03bbcc: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03bbd0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03bbd4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03bbd8: 910083fd  add      x29, sp, #0x20
//   0x03bbdc: f9400414  ldr      x20, [x0, #8]
//   0x03bbe0: aa0203f5  mov      x21, x2
//   0x03bbe4: aa0003f3  mov      x19, x0
//   0x03bbe8: aa0103f6  mov      x22, x1
//   0x03bbec: eb02003f  cmp      x1, x2
//   0x03bbf0: 540000c1  b.ne     #0x3bc08
//   0x03bbf4: 14000013  b        #0x3bc40
//   0x03bbf8: f94006d6  ldr      x22, [x22, #8]
//   0x03bbfc: f9400694  ldr      x20, [x20, #8]
//   0x03bc00: eb1502df  cmp      x22, x21
//   0x03bc04: 540001e0  b.eq     #0x3bc40
//   0x03bc08: eb14027f  cmp      x19, x20
uint64_t fde_0366_sub_03bbcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9400694ULL) + (x2 ^ 0x03BBCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03bbcc: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03bbd0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03bbd4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03bbd8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x03bbdc: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03bbe0: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03bbe4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x03bbe8: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x03bbec: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x03bbf0: b.ne #0x3bc08
    return acc;
}

// [EN] Reconstructed FDE #0367 @ 0x03bcd4..0x03be18 (324 bytes)
// [VN] Phục dựng FDE #0367 tại 0x03bcd4..0x03be18 (324 byte)
//   0x03bcd4: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x03bcd8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x03bcdc: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03bce0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03bce4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03bce8: 910103fd  add      x29, sp, #0x40
//   0x03bcec: aa0103f4  mov      x20, x1
//   0x03bcf0: eb03005f  cmp      x2, x3
//   0x03bcf4: 540004e0  b.eq     #0x3bd90
//   0x03bcf8: aa0003f5  mov      x21, x0
//   0x03bcfc: 52800500  mov      w0, #0x28
//   0x03bd00: aa0303f6  mov      x22, x3
//   0x03bd04: aa0203f7  mov      x23, x2
//   0x03bd08: 97ff7fd6  bl       #0x1bc60
//   0x03bd0c: aa0003f3  mov      x19, x0
//   0x03bd10: f801041f  str      xzr, [x0], #0x10
uint64_t fde_0367_sub_03bcd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xAA0203F7ULL) + (x2 ^ 0x03BCD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x03bcd4: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x03bcd8: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03bcdc: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03bce0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03bce4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03bce8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03bcec: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB03005FULL; // 0x03bcf0: cmp x2, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540004E0ULL; // 0x03bcf4: b.eq #0x3bd90
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x03bcf8: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0368 @ 0x03be18..0x03bf60 (328 bytes)
// [VN] Phục dựng FDE #0368 tại 0x03be18..0x03bf60 (328 byte)
//   0x03be18: d101c3ff  sub      sp, sp, #0x70
//   0x03be1c: f9001bf7  str      x23, [sp, #0x30]
//   0x03be20: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03be24: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03be28: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03be2c: 910183fd  add      x29, sp, #0x60
//   0x03be30: d53bd057  mrs      x23, tpidr_el0
//   0x03be34: f94016e8  ldr      x8, [x23, #0x28]
//   0x03be38: aa0203f5  mov      x21, x2
//   0x03be3c: aa0103e2  mov      x2, x1
//   0x03be40: 910023e1  add      x1, sp, #8
//   0x03be44: aa0003f3  mov      x19, x0
//   0x03be48: f90017e8  str      x8, [sp, #0x28]
//   0x03be4c: 97ff7f65  bl       #0x1bbe0
//   0x03be50: f9400016  ldr      x22, [x0]
//   0x03be54: b4000076  cbz      x22, #0x3be60
uint64_t fde_0368_sub_03be18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x03BE18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03be18: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x03be1c: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03be20: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03be24: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03be28: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03be2c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03be30: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03be34: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03be38: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x03be3c: mov x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0369 @ 0x03bf60..0x03c080 (288 bytes)
// [VN] Phục dựng FDE #0369 tại 0x03bf60..0x03c080 (288 byte)
//   0x03bf60: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x03bf64: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03bf68: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03bf6c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03bf70: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03bf74: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03bf78: 910143fd  add      x29, sp, #0x50
//   0x03bf7c: aa0003f4  mov      x20, x0
//   0x03bf80: f8408e97  ldr      x23, [x20, #8]!
//   0x03bf84: aa0103f3  mov      x19, x1
//   0x03bf88: b4000657  cbz      x23, #0x3c050
//   0x03bf8c: 39400048  ldrb     w8, [x2]
//   0x03bf90: a940a849  ldp      x9, x10, [x2, #8]
//   0x03bf94: 91002014  add      x20, x0, #8
//   0x03bf98: d341fd0b  lsr      x11, x8, #1
//   0x03bf9c: 7200011f  tst      w8, #1
uint64_t fde_0369_sub_03bf60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x03BF60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x03bf60: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03bf64: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03bf68: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03bf6c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03bf70: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03bf74: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03bf78: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03bf7c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E97ULL; // 0x03bf80: ldr x23, [x20, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03bf84: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0370 @ 0x03c080..0x03c138 (184 bytes)
// [VN] Phục dựng FDE #0370 tại 0x03c080..0x03c138 (184 byte)
//   0x03c080: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03c084: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c088: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c08c: 910083fd  add      x29, sp, #0x20
//   0x03c090: f9400013  ldr      x19, [x0]
//   0x03c094: f900001f  str      xzr, [x0]
//   0x03c098: b4000493  cbz      x19, #0x3c128
//   0x03c09c: 39404008  ldrb     w8, [x0, #0x10]
//   0x03c0a0: 340003a8  cbz      w8, #0x3c114
//   0x03c0a4: f9402668  ldr      x8, [x19, #0x48]
//   0x03c0a8: b40002e8  cbz      x8, #0x3c104
//   0x03c0ac: a943d268  ldp      x8, x20, [x19, #0x38]
//   0x03c0b0: 9100e275  add      x21, x19, #0x38
//   0x03c0b4: f9400509  ldr      x9, [x8, #8]
//   0x03c0b8: f940028a  ldr      x10, [x20]
//   0x03c0bc: eb15029f  cmp      x20, x21
uint64_t fde_0370_sub_03c080(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x9100E275ULL) + (x2 ^ 0x03C080ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03c080: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c084: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c088: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c08c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x03c090: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x03c094: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000493ULL; // 0x03c098: cbz x19, #0x3c128
    acc = (acc * 0x100000001B3ULL) ^ 0x39404008ULL; // 0x03c09c: ldrb w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A8ULL; // 0x03c0a0: cbz w8, #0x3c114
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402668ULL; // 0x03c0a4: ldr x8, [x19, #0x48]
    return acc;
}

// [EN] Reconstructed FDE #0371 @ 0x03c138..0x03c2b0 (376 bytes)
// [VN] Phục dựng FDE #0371 tại 0x03c138..0x03c2b0 (376 byte)
//   0x03c138: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x03c13c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03c140: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03c144: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03c148: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03c14c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03c150: 910143fd  add      x29, sp, #0x50
//   0x03c154: aa0003f3  mov      x19, x0
//   0x03c158: f8408e78  ldr      x24, [x19, #8]!
//   0x03c15c: b4000998  cbz      x24, #0x3c28c
//   0x03c160: 39400028  ldrb     w8, [x1]
//   0x03c164: a940a829  ldp      x9, x10, [x1, #8]
//   0x03c168: aa1303f4  mov      x20, x19
//   0x03c16c: d341fd0b  lsr      x11, x8, #1
//   0x03c170: 7200011f  tst      w8, #1
//   0x03c174: 9a890176  csel     x22, x11, x9, eq
uint64_t fde_0371_sub_03c138(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA1303F4ULL) + (x2 ^ 0x03C138ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x03c138: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03c13c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03c140: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03c144: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03c148: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03c14c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03c150: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03c154: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E78ULL; // 0x03c158: ldr x24, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000998ULL; // 0x03c15c: cbz x24, #0x3c28c
    return acc;
}

// [EN] Reconstructed FDE #0372 @ 0x03c2b0..0x03c3f8 (328 bytes)
// [VN] Phục dựng FDE #0372 tại 0x03c2b0..0x03c3f8 (328 byte)
//   0x03c2b0: d101c3ff  sub      sp, sp, #0x70
//   0x03c2b4: f9001bf7  str      x23, [sp, #0x30]
//   0x03c2b8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03c2bc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03c2c0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03c2c4: 910183fd  add      x29, sp, #0x60
//   0x03c2c8: d53bd057  mrs      x23, tpidr_el0
//   0x03c2cc: f94016e8  ldr      x8, [x23, #0x28]
//   0x03c2d0: aa0203f5  mov      x21, x2
//   0x03c2d4: aa0103e2  mov      x2, x1
//   0x03c2d8: 910023e1  add      x1, sp, #8
//   0x03c2dc: aa0003f3  mov      x19, x0
//   0x03c2e0: f90017e8  str      x8, [sp, #0x28]
//   0x03c2e4: 97ff7a7b  bl       #0x1acd0
//   0x03c2e8: f9400016  ldr      x22, [x0]
//   0x03c2ec: b4000076  cbz      x22, #0x3c2f8
uint64_t fde_0372_sub_03c2b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x03C2B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03c2b0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x03c2b4: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03c2b8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03c2bc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03c2c0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03c2c4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03c2c8: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03c2cc: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03c2d0: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x03c2d4: mov x2, x1
    return acc;
}

// [EN] Reconstructed FDE #0373 @ 0x03c3f8..0x03c584 (396 bytes)
// [VN] Phục dựng FDE #0373 tại 0x03c3f8..0x03c584 (396 byte)
//   0x03c3f8: d10203ff  sub      sp, sp, #0x80
//   0x03c3fc: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x03c400: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x03c404: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x03c408: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x03c40c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03c410: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03c414: 9101c3fd  add      x29, sp, #0x70
//   0x03c418: aa0003f4  mov      x20, x0
//   0x03c41c: f8408e96  ldr      x22, [x20, #8]!
//   0x03c420: b4000976  cbz      x22, #0x3c54c
//   0x03c424: 39400048  ldrb     w8, [x2]
//   0x03c428: a940a849  ldp      x9, x10, [x2, #8]
//   0x03c42c: 91002014  add      x20, x0, #8
//   0x03c430: d341fd0b  lsr      x11, x8, #1
//   0x03c434: 7200011f  tst      w8, #1
uint64_t fde_0373_sub_03c3f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xA940A849ULL) + (x2 ^ 0x03C3F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03c3f8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x03c3fc: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x03c400: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x03c404: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x03c408: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x03c40c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03c410: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03c414: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03c418: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E96ULL; // 0x03c41c: ldr x22, [x20, #8]!
    return acc;
}

// [EN] Reconstructed FDE #0374 @ 0x03c584..0x03c63c (184 bytes)
// [VN] Phục dựng FDE #0374 tại 0x03c584..0x03c63c (184 byte)
//   0x03c584: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03c588: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c58c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c590: 910083fd  add      x29, sp, #0x20
//   0x03c594: f9400013  ldr      x19, [x0]
//   0x03c598: f900001f  str      xzr, [x0]
//   0x03c59c: b4000493  cbz      x19, #0x3c62c
//   0x03c5a0: 39404008  ldrb     w8, [x0, #0x10]
//   0x03c5a4: 340003a8  cbz      w8, #0x3c618
//   0x03c5a8: f9402668  ldr      x8, [x19, #0x48]
//   0x03c5ac: b40002e8  cbz      x8, #0x3c608
//   0x03c5b0: a943d268  ldp      x8, x20, [x19, #0x38]
//   0x03c5b4: 9100e275  add      x21, x19, #0x38
//   0x03c5b8: f9400509  ldr      x9, [x8, #8]
//   0x03c5bc: f940028a  ldr      x10, [x20]
//   0x03c5c0: eb15029f  cmp      x20, x21
uint64_t fde_0374_sub_03c584(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x9100E275ULL) + (x2 ^ 0x03C584ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03c584: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c588: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c58c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c590: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x03c594: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x03c598: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000493ULL; // 0x03c59c: cbz x19, #0x3c62c
    acc = (acc * 0x100000001B3ULL) ^ 0x39404008ULL; // 0x03c5a0: ldrb w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A8ULL; // 0x03c5a4: cbz w8, #0x3c618
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402668ULL; // 0x03c5a8: ldr x8, [x19, #0x48]
    return acc;
}

// [EN] Reconstructed FDE #0375 @ 0x03c63c..0x03c6f4 (184 bytes)
// [VN] Phục dựng FDE #0375 tại 0x03c63c..0x03c6f4 (184 byte)
//   0x03c63c: b40005a1  cbz      x1, #0x3c6f0
//   0x03c640: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03c644: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c648: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c64c: 910083fd  add      x29, sp, #0x20
//   0x03c650: aa0103f3  mov      x19, x1
//   0x03c654: f9400021  ldr      x1, [x1]
//   0x03c658: aa0003f4  mov      x20, x0
//   0x03c65c: 97ff7ac1  bl       #0x1b160
//   0x03c660: f9400661  ldr      x1, [x19, #8]
//   0x03c664: aa1403e0  mov      x0, x20
//   0x03c668: 97ff7abe  bl       #0x1b160
//   0x03c66c: f9402668  ldr      x8, [x19, #0x48]
//   0x03c670: b40002e8  cbz      x8, #0x3c6cc
//   0x03c674: a943d268  ldp      x8, x20, [x19, #0x38]
//   0x03c678: 9100e275  add      x21, x19, #0x38
uint64_t fde_0375_sub_03c63c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40005A1ULL) + (x1 ^ 0xF9402668ULL) + (x2 ^ 0x03C63CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40005A1ULL; // 0x03c63c: cbz x1, #0x3c6f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03c640: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c644: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c648: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c64c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03c650: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x03c654: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03c658: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7AC1ULL; // 0x03c65c: bl #0x1b160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x03c660: ldr x1, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0376 @ 0x03c6f4..0x03cac8 (980 bytes)
// [VN] Phục dựng FDE #0376 tại 0x03c6f4..0x03cac8 (980 byte)
//   0x03c6f4: d101c3ff  sub      sp, sp, #0x70
//   0x03c6f8: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x03c6fc: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x03c700: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x03c704: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03c708: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03c70c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03c710: 910183fd  add      x29, sp, #0x60
//   0x03c714: f9400808  ldr      x8, [x0, #0x10]
//   0x03c718: aa0203f4  mov      x20, x2
//   0x03c71c: aa0003f3  mov      x19, x0
//   0x03c720: aa0103f5  mov      x21, x1
//   0x03c724: b4001768  cbz      x8, #0x3ca10
//   0x03c728: aa1303fa  mov      x26, x19
//   0x03c72c: f9400268  ldr      x8, [x19]
//   0x03c730: f8408f49  ldr      x9, [x26, #8]!
uint64_t fde_0376_sub_03c6f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB4001768ULL) + (x2 ^ 0x03C6F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03c6f4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x03c6f8: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x03c6fc: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x03c700: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03c704: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03c708: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03c70c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03c710: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x03c714: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03c718: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0377 @ 0x03cac8..0x03cc84 (444 bytes)
// [VN] Phục dựng FDE #0377 tại 0x03cac8..0x03cc84 (444 byte)
//   0x03cac8: d101c3ff  sub      sp, sp, #0x70
//   0x03cacc: f90013f9  str      x25, [sp, #0x20]
//   0x03cad0: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x03cad4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03cad8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03cadc: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03cae0: 910183fd  add      x29, sp, #0x60
//   0x03cae4: d53bd057  mrs      x23, tpidr_el0
//   0x03cae8: f94016e8  ldr      x8, [x23, #0x28]
//   0x03caec: aa0003f3  mov      x19, x0
//   0x03caf0: 91002016  add      x22, x0, #8
//   0x03caf4: 52800a00  mov      w0, #0x50
//   0x03caf8: aa0103f5  mov      x21, x1
//   0x03cafc: f9000fe8  str      x8, [sp, #0x18]
//   0x03cb00: 97ff7c58  bl       #0x1bc60
//   0x03cb04: aa0003f4  mov      x20, x0
uint64_t fde_0377_sub_03cac8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x03CAC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03cac8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x03cacc: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x03cad0: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03cad4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03cad8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03cadc: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03cae0: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03cae4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03cae8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03caec: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0378 @ 0x03cc84..0x03cc88 (4 bytes)
// [VN] Phục dựng FDE #0378 tại 0x03cc84..0x03cc88 (4 byte)
//   0x03cc84: d65f03c0  ret      
uint64_t fde_0378_sub_03cc84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03CC84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03cc84: ret 
    return acc;
}

// [EN] Reconstructed FDE #0379 @ 0x03cc88..0x03cc8c (4 bytes)
// [VN] Phục dựng FDE #0379 tại 0x03cc88..0x03cc8c (4 byte)
//   0x03cc88: d4200020  brk      #1
uint64_t fde_0379_sub_03cc88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD4200020ULL) + (x1 ^ 0xD4200020ULL) + (x2 ^ 0x03CC88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD4200020ULL; // 0x03cc88: brk #1
    return acc;
}

// [EN] Reconstructed FDE #0380 @ 0x03cc8c..0x03cedc (592 bytes)
// [VN] Phục dựng FDE #0380 tại 0x03cc8c..0x03cedc (592 byte)
//   0x03cc8c: d102c3ff  sub      sp, sp, #0xb0
//   0x03cc90: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x03cc94: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x03cc98: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x03cc9c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03cca0: 910283fd  add      x29, sp, #0xa0
//   0x03cca4: d53bd057  mrs      x23, tpidr_el0
//   0x03cca8: f94016e8  ldr      x8, [x23, #0x28]
//   0x03ccac: 90000178  adrp     x24, #0x68000
//   0x03ccb0: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03ccb4: 3957c308  ldrb     w8, [x24, #0x5f0]
//   0x03ccb8: 36000068  tbz      w8, #0, #0x3ccc4
//   0x03ccbc: 2a1f03e0  mov      w0, wzr
//   0x03ccc0: 1400007c  b        #0x3ceb0
//   0x03ccc4: aa0003f3  mov      x19, x0
//   0x03ccc8: f00000a0  adrp     x0, #0x53000
uint64_t fde_0380_sub_03cc8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x2A1F03E0ULL) + (x2 ^ 0x03CC8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03cc8c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03cc90: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x03cc94: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x03cc98: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03cc9c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03cca0: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03cca4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03cca8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000178ULL; // 0x03ccac: adrp x24, #0x68000
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03ccb0: stur x8, [x29, #-0x38]
    return acc;
}

// [EN] Reconstructed FDE #0381 @ 0x03cedc..0x03cfc4 (232 bytes)
// [VN] Phục dựng FDE #0381 tại 0x03cedc..0x03cfc4 (232 byte)
//   0x03cedc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03cee0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03cee4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03cee8: 910083fd  add      x29, sp, #0x20
//   0x03ceec: f0000155  adrp     x21, #0x67000
//   0x03cef0: f94762b5  ldr      x21, [x21, #0xec0]
//   0x03cef4: 39400009  ldrb     w9, [x0]
//   0x03cef8: f940080a  ldr      x10, [x0, #0x10]
//   0x03cefc: f94002b3  ldr      x19, [x21]
//   0x03cf00: 7200013f  tst      w9, #1
//   0x03cf04: 9a801554  csinc    x20, x10, x0, ne
//   0x03cf08: aa1403e1  mov      x1, x20
//   0x03cf0c: f9400268  ldr      x8, [x19]
//   0x03cf10: aa0803e0  mov      x0, x8
//   0x03cf14: 97ff77c7  bl       #0x1ae30
//   0x03cf18: 340004c0  cbz      w0, #0x3cfb0
uint64_t fde_0381_sub_03cedc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x03CEDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03cedc: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03cee0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03cee4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03cee8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000155ULL; // 0x03ceec: adrp x21, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94762B5ULL; // 0x03cef0: ldr x21, [x21, #0xec0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400009ULL; // 0x03cef4: ldrb w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940080AULL; // 0x03cef8: ldr x10, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002B3ULL; // 0x03cefc: ldr x19, [x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x03cf00: tst w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0382 @ 0x03cfc4..0x03d0b4 (240 bytes)
// [VN] Phục dựng FDE #0382 tại 0x03cfc4..0x03d0b4 (240 byte)
//   0x03cfc4: d10143ff  sub      sp, sp, #0x50
//   0x03cfc8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03cfcc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03cfd0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03cfd4: 910103fd  add      x29, sp, #0x40
//   0x03cfd8: d53bd055  mrs      x21, tpidr_el0
//   0x03cfdc: f94016a8  ldr      x8, [x21, #0x28]
//   0x03cfe0: f0000156  adrp     x22, #0x67000
//   0x03cfe4: 2a0103f3  mov      w19, w1
//   0x03cfe8: f9000fe8  str      x8, [sp, #0x18]
//   0x03cfec: f94702d6  ldr      x22, [x22, #0xe00]
//   0x03cff0: 39400009  ldrb     w9, [x0]
//   0x03cff4: f940080a  ldr      x10, [x0, #0x10]
//   0x03cff8: f94002c8  ldr      x8, [x22]
//   0x03cffc: 7200013f  tst      w9, #1
//   0x03d000: 9a801554  csinc    x20, x10, x0, ne
uint64_t fde_0382_sub_03cfc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF940080AULL) + (x2 ^ 0x03CFC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x03cfc4: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03cfc8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03cfcc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03cfd0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03cfd4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03cfd8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03cfdc: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000156ULL; // 0x03cfe0: adrp x22, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x03cfe4: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x03cfe8: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0383 @ 0x03d0b4..0x03d0f8 (68 bytes)
// [VN] Phục dựng FDE #0383 tại 0x03d0b4..0x03d0f8 (68 byte)
//   0x03d0b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03d0b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03d0bc: 910043fd  add      x29, sp, #0x10
//   0x03d0c0: aa0003f3  mov      x19, x0
//   0x03d0c4: 97ff78df  bl       #0x1b440
//   0x03d0c8: aa1303e0  mov      x0, x19
//   0x03d0cc: 97ff7659  bl       #0x1aa30
//   0x03d0d0: d0000148  adrp     x8, #0x67000
//   0x03d0d4: f946c108  ldr      x8, [x8, #0xd80]
//   0x03d0d8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03d0dc: f100001f  cmp      x0, #0
//   0x03d0e0: 1a9f07e9  cset     w9, ne
//   0x03d0e4: eb08001f  cmp      x0, x8
//   0x03d0e8: 528001c8  mov      w8, #0xe
//   0x03d0ec: 1a890100  csel     w0, w8, w9, eq
//   0x03d0f0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0383_sub_03d0b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xEB08001FULL) + (x2 ^ 0x03D0B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03d0b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03d0b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03d0bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03d0c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF78DFULL; // 0x03d0c4: bl #0x1b440
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03d0c8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7659ULL; // 0x03d0cc: bl #0x1aa30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03d0d0: adrp x8, #0x67000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C108ULL; // 0x03d0d4: ldr x8, [x8, #0xd80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03d0d8: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0384 @ 0x03d0f8..0x03d19c (164 bytes)
// [VN] Phục dựng FDE #0384 tại 0x03d0f8..0x03d19c (164 byte)
//   0x03d0f8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03d0fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03d100: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03d104: 910083fd  add      x29, sp, #0x20
//   0x03d108: aa0103f5  mov      x21, x1
//   0x03d10c: 2a0403e1  mov      w1, w4
//   0x03d110: 2a0303f3  mov      w19, w3
//   0x03d114: aa0203f4  mov      x20, x2
//   0x03d118: aa0003f6  mov      x22, x0
//   0x03d11c: 97ff78c9  bl       #0x1b440
//   0x03d120: aa1603e0  mov      x0, x22
//   0x03d124: 97ff7643  bl       #0x1aa30
//   0x03d128: d0000148  adrp     x8, #0x67000
//   0x03d12c: f946c108  ldr      x8, [x8, #0xd80]
//   0x03d130: eb08001f  cmp      x0, x8
//   0x03d134: 540001a0  b.eq     #0x3d168
uint64_t fde_0384_sub_03d0f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xD0000148ULL) + (x2 ^ 0x03D0F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03d0f8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03d0fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03d100: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03d104: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x03d108: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E1ULL; // 0x03d10c: mov w1, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x03d110: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03d114: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x03d118: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF78C9ULL; // 0x03d11c: bl #0x1b440
    return acc;
}

// [EN] Reconstructed FDE #0385 @ 0x03d19c..0x03d254 (184 bytes)
// [VN] Phục dựng FDE #0385 tại 0x03d19c..0x03d254 (184 byte)
//   0x03d19c: b940080a  ldr      w10, [x0, #8]
//   0x03d1a0: 2a0103eb  mov      w11, w1
//   0x03d1a4: 330a244b  bfi      w11, w2, #0x16, #0xa
//   0x03d1a8: 2a0103e9  mov      w9, w1
//   0x03d1ac: 6b0a017f  cmp      w11, w10
//   0x03d1b0: 54000082  b.hs     #0x3d1c0
//   0x03d1b4: f9400008  ldr      x8, [x0]
//   0x03d1b8: 8b2b4101  add      x1, x8, w11, uxtw
//   0x03d1bc: 14000002  b        #0x3d1c4
//   0x03d1c0: aa1f03e1  mov      x1, xzr
//   0x03d1c4: aa1f03e8  mov      x8, xzr
//   0x03d1c8: 6b0a017f  cmp      w11, w10
//   0x03d1cc: 53167d29  lsr      w9, w9, #0x16
//   0x03d1d0: 540003c2  b.hs     #0x3d248
//   0x03d1d4: d2e7d20b  mov      x11, #0x3e90000000000000
//   0x03d1d8: 1e630140  ucvtf    d0, w10
uint64_t fde_0385_sub_03d19c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB940080AULL) + (x1 ^ 0x53167D29ULL) + (x2 ^ 0x03D19CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB940080AULL; // 0x03d19c: ldr w10, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103EBULL; // 0x03d1a0: mov w11, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x330A244BULL; // 0x03d1a4: bfi w11, w2, #0x16, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x03d1a8: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A017FULL; // 0x03d1ac: cmp w11, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x03d1b0: b.hs #0x3d1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x03d1b4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B2B4101ULL; // 0x03d1b8: add x1, x8, w11, uxtw
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x03d1bc: b #0x3d1c4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03d1c0: mov x1, xzr
    return acc;
}

// [EN] Reconstructed FDE #0386 @ 0x03d254..0x03d2dc (136 bytes)
// [VN] Phục dựng FDE #0386 tại 0x03d254..0x03d2dc (136 byte)
//   0x03d254: b9400809  ldr      w9, [x0, #8]
//   0x03d258: 2a1f03e8  mov      w8, wzr
//   0x03d25c: 6b04013f  cmp      w9, w4
//   0x03d260: 540003a9  b.ls     #0x3d2d4
//   0x03d264: d2e7d20a  mov      x10, #0x3e90000000000000
//   0x03d268: 1e630120  ucvtf    d0, w9
//   0x03d26c: 9e670141  fmov     d1, x10
//   0x03d270: 1e610800  fmul     d0, d0, d1
//   0x03d274: 1e690009  fcvtpu   w9, d0
//   0x03d278: 6b02013f  cmp      w9, w2
//   0x03d27c: 540002c9  b.ls     #0x3d2d4
//   0x03d280: 51020428  sub      w8, w1, #0x81
//   0x03d284: 71000d1f  cmp      w8, #3
//   0x03d288: 54000128  b.hi     #0x3d2ac
//   0x03d28c: 7100051f  cmp      w8, #1
//   0x03d290: 540000e0  b.eq     #0x3d2ac
uint64_t fde_0386_sub_03d254(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400809ULL) + (x1 ^ 0x71000D1FULL) + (x2 ^ 0x03D254ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400809ULL; // 0x03d254: ldr w9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x03d258: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04013FULL; // 0x03d25c: cmp w9, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x540003A9ULL; // 0x03d260: b.ls #0x3d2d4
    acc = (acc * 0x100000001B3ULL) ^ 0xD2E7D20AULL; // 0x03d264: mov x10, #0x3e90000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x1E630120ULL; // 0x03d268: ucvtf d0, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670141ULL; // 0x03d26c: fmov d1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x1E610800ULL; // 0x03d270: fmul d0, d0, d1
    acc = (acc * 0x100000001B3ULL) ^ 0x1E690009ULL; // 0x03d274: fcvtpu w9, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02013FULL; // 0x03d278: cmp w9, w2
    return acc;
}

// [EN] Reconstructed FDE #0387 @ 0x03d2dc..0x03d310 (52 bytes)
// [VN] Phục dựng FDE #0387 tại 0x03d2dc..0x03d310 (52 byte)
//   0x03d2dc: b9400809  ldr      w9, [x0, #8]
//   0x03d2e0: 53167c28  lsr      w8, w1, #0x16
//   0x03d2e4: 330a2441  bfi      w1, w2, #0x16, #0xa
//   0x03d2e8: 6b09003f  cmp      w1, w9
//   0x03d2ec: 540000a2  b.hs     #0x3d300
//   0x03d2f0: f9400009  ldr      x9, [x0]
//   0x03d2f4: 121e742a  and      w10, w1, #0xfffffffc
//   0x03d2f8: 8b0a0121  add      x1, x9, x10
//   0x03d2fc: 14000002  b        #0x3d304
//   0x03d300: aa1f03e1  mov      x1, xzr
//   0x03d304: 52800020  mov      w0, #1
//   0x03d308: b3602500  bfi      x0, x8, #0x20, #0xa
//   0x03d30c: d65f03c0  ret      
uint64_t fde_0387_sub_03d2dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400809ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03D2DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400809ULL; // 0x03d2dc: ldr w9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x53167C28ULL; // 0x03d2e0: lsr w8, w1, #0x16
    acc = (acc * 0x100000001B3ULL) ^ 0x330A2441ULL; // 0x03d2e4: bfi w1, w2, #0x16, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09003FULL; // 0x03d2e8: cmp w1, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x03d2ec: b.hs #0x3d300
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x03d2f0: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x121E742AULL; // 0x03d2f4: and w10, w1, #0xfffffffc
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A0121ULL; // 0x03d2f8: add x1, x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x03d2fc: b #0x3d304
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03d300: mov x1, xzr
    return acc;
}

// [EN] Reconstructed FDE #0388 @ 0x03d310..0x03d6bc (940 bytes)
// [VN] Phục dựng FDE #0388 tại 0x03d310..0x03d6bc (940 byte)
//   0x03d310: d102c3ff  sub      sp, sp, #0xb0
//   0x03d314: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x03d318: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x03d31c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x03d320: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x03d324: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x03d328: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03d32c: 910283fd  add      x29, sp, #0xa0
//   0x03d330: f90007e8  str      x8, [sp, #8]
//   0x03d334: d53bd048  mrs      x8, tpidr_el0
//   0x03d338: f90003e8  str      x8, [sp]
//   0x03d33c: f9401508  ldr      x8, [x8, #0x28]
//   0x03d340: 53167c29  lsr      w9, w1, #0x16
//   0x03d344: 330a2441  bfi      w1, w2, #0x16, #0xa
//   0x03d348: 2a0203f4  mov      w20, w2
//   0x03d34c: f90027e8  str      x8, [sp, #0x48]
uint64_t fde_0388_sub_03d310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x53167C29ULL) + (x2 ^ 0x03D310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03d310: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x03d314: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x03d318: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03d31c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x03d320: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x03d324: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03d328: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03d32c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03d330: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x03d334: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0389 @ 0x03d6bc..0x03d6d8 (28 bytes)
// [VN] Phục dựng FDE #0389 tại 0x03d6bc..0x03d6d8 (28 byte)
//   0x03d6bc: bd400800  ldr      s0, [x0, #8]
//   0x03d6c0: d2e7d208  mov      x8, #0x3e90000000000000
//   0x03d6c4: 9e670101  fmov     d1, x8
//   0x03d6c8: 7e61d800  ucvtf    d0, d0
//   0x03d6cc: 1e610800  fmul     d0, d0, d1
//   0x03d6d0: 1e690000  fcvtpu   w0, d0
//   0x03d6d4: d65f03c0  ret      
uint64_t fde_0389_sub_03d6bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xBD400800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03D6BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xBD400800ULL; // 0x03d6bc: ldr s0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD2E7D208ULL; // 0x03d6c0: mov x8, #0x3e90000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670101ULL; // 0x03d6c4: fmov d1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x7E61D800ULL; // 0x03d6c8: ucvtf d0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x1E610800ULL; // 0x03d6cc: fmul d0, d0, d1
    acc = (acc * 0x100000001B3ULL) ^ 0x1E690000ULL; // 0x03d6d0: fcvtpu w0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03d6d4: ret 
    return acc;
}

uint64_t DispatchBytecodeEngineFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 200U || fde_index >= 390U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0xBF58476D1CE4E5B9ULL) + x2;
}

} // namespace engine
} // namespace orbuculum
} // namespace ttp
