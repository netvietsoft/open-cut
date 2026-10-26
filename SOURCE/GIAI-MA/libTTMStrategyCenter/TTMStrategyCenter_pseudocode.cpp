// ==============================================================================
// FILE: ttmstrategycenter_pseudocode.cpp
// TARGET: libTTMStrategyCenter.so (395,664 bytes, 899 dynamic symbols, 16 JNI methods)
// PURPOSE: Exact AArch64 Disassembly & Mathematical Pseudocode Reference for
//          Agent 13 Adversarial Verification Protocol
//          (Tham chiếu Mã giả Toán học & Hợp ngữ AArch64 chính xác phục vụ
//          Giao thức Xác minh Đối kháng của Agent 13)
// EVIDENCE CLASSIFICATION: OBSERVED (Direct AArch64 Opcode & ELF64 Section Dump)
// ==============================================================================

#include "ttmstrategycenter_interface.h"

namespace NextAI::OpenCut::TTMStrategyCenter::DisassemblyReference {

// ==============================================================================
// 1. ELF64 Segment Layout & Sentinel Constants (`PT_LOAD 0` & `PT_LOAD 1`)
//    - PT_LOAD 0: vaddr `0x000000..0x05d798` -> file `0x000000..0x05d798` (R+X)
//    - PT_LOAD 1: vaddr `0x061b38..0x064590` -> file `0x05db38..0x060138` (R+W, delta = -0x4000)
//    - Sentinel constants in `.data`:
//      * `LONG_MAX_VALUE` (`0x64008`, file `0x60008`)       = `0x7fffffffffffffff` (9223372036854775807)
//      * `INT_MAX_VALUE` (`0x64010`, file `0x60010`)        = `0x7fffffff` (2147483647)
//      * `DOUBLE_MAX_VALUE` (`0x64018`, file `0x60018`)     = `0x7fefffffffffffff` (1.7976931348623157e+308)
//      * `TTM_SC_LONG_MAX_VALUE` (`0x64048`, file `0x60048`)   = `0x7fffffffffffffff`
//      * `TTM_SC_INT_MAX_VALUE` (`0x64050`, file `0x60050`)    = `0x7fffffff`
//      * `TTM_SC_DOUBLE_MAX_VALUE` (`0x64058`, file `0x60058`) = `0x7fefffffffffffff`
// ==============================================================================

// ==============================================================================
// 2. AArch64 Opcode Proof: `transformByteDtErrorToTTMErrorCode(signed char)`
//    Symbol: `_Z34transformByteDtErrorToTTMErrorCodea` @ `0x4d21c` (40 bytes)
//
//    Disassembly:
//      0x4d21c: 12001c08  and  w8, w0, #0xff
//      0x4d220: 7100191f  cmp  w8, #0x6
//      0x4d224: 540000c8  b.hi #0x4d23c
//      0x4d228: b0000029  adrp x9, #0x52000
//      0x4d22c: 93401c08  sxtb x8, w0
//      0x4d230: 910f6129  add  x9, x9, #0x3d8      ; .rodata jump table @ 0x523d8
//      0x4d234: b8687920  ldr  w0, [x9, x8, lsl #2]
//      0x4d238: d65f03c0  ret
//      0x4d23c: 528032e0  mov  w0, #0x197           ; default fallback = 407 (0x197)
//      0x4d240: d65f03c0  ret
//
//    `.rodata` lookup table at `0x523d8` (7 x int32_t):
//      [0] = 0x00000000 (0)
//      [1] = 0x00000191 (401)
//      [2] = 0x00000192 (402)
//      [3] = 0x00000193 (403)
//      [4] = 0x00000194 (404)
//      [5] = 0x00000195 (405)
//      [6] = 0x00000196 (406)
// ==============================================================================
int VerifyTransformByteDtErrorOpcodeModel(std::int8_t err) noexcept {
    static constexpr int kRoDataTable_0x523d8[7] = {0, 401, 402, 403, 404, 405, 406};
    const std::uint32_t u8 = static_cast<std::uint8_t>(err);
    if (u8 > 6u) {
        return 407; // 0x197
    }
    return kRoDataTable_0x523d8[static_cast<std::int64_t>(err)];
}

// ==============================================================================
// 3. AArch64 Opcode Proof: `ttm_sc_list::make_real_index(long)`
//    Symbol: `_ZN11ttm_sc_list15make_real_indexEl` @ `0x41fa0` (648 bytes)
//
//    Disassembly excerpt (`0x41fc8..0x41fec`):
//      0x41fc8: a9412668  ldp  x8, x9, [x19, #0x10] ; x8 = begin, x9 = end of std::vector<std::any>
//      0x41fcc: cb080128  sub  x8, x9, x8           ; byte_delta = end - begin
//      0x41fd0: b202e7e9  mov  x9, #-0x3333333333333334
//      0x41fd4: 9343fd08  asr  x8, x8, #3           ; byte_delta >> 3 (divide by 8)
//      0x41fd8: f29999a9  movk x9, #0xcccd          ; x9 = 0xcccccccccccccccdULL (multiplicative inverse of 5 mod 2^64)
//      0x41fdc: 9b097d08  mul  x8, x8, x9           ; count = (byte_delta / 8) / 5 = byte_delta / 40 (sizeof(std::any) == 40)
//      0x41fe0: f100029f  cmp  x20, #0x0            ; compare index with 0
//      0x41fe4: 8b080289  add  x9, x20, x8          ; negative_adjusted = index + count
//      0x41fe8: 9a89b289  csel x9, x20, x9, lt      ; real_index = (index < 0) ? (index + count) : index
// ==============================================================================
long VerifyMakeRealIndexOpcodeModel(std::size_t byte_delta_40b_elements, long index) noexcept {
    constexpr std::uint64_t kInvFiveMod64 = 0xcccccccccccccccdULL;
    const std::uint64_t count =
        (static_cast<std::uint64_t>(byte_delta_40b_elements) >> 3u) * kInvFiveMod64;
    const long real_idx = (index < 0) ? (index + static_cast<long>(count)) : index;
    if (real_idx < 0 || static_cast<std::uint64_t>(real_idx) >= count) {
        return -1;
    }
    return real_idx;
}

} // namespace NextAI::OpenCut::TTMStrategyCenter::DisassemblyReference
