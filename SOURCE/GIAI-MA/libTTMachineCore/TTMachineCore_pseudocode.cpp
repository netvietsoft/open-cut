// ==============================================================================
// FILE: TTMachineCore_pseudocode.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Exact AArch64 Disassembly & Mathematical Pseudocode Reference for
//          Agent 13 Adversarial Verification Protocol
//          (Tham chiếu Mã giả Toán học & Hợp ngữ AArch64 chính xác phục vụ
//          Giao thức Xác minh Đối kháng của Agent 13)
// EVIDENCE CLASSIFICATION: OBSERVED (Direct AArch64 Opcode & ELF64 Section Dump)
// ==============================================================================

#include "TTMachineCore_interface.h"

namespace NextAI::OpenCut::TTMachineCore::DisassemblyReference {

// ==============================================================================
// 1. AArch64 Opcode Proof: `ttm_support_max_bytecode_version` (`0x17244`, 8 B)
//      0x017244: 52800140  mov w0, #0xa
//      0x017248: d65f03c0  ret
// ==============================================================================
std::int32_t VerifyMaxBytecodeVersionOpcode() noexcept {
    return 10; // 0x0a
}

// ==============================================================================
// 2. AArch64 Opcode Proof: `ttm_state_error_code_for_business` (`0x1758c`, 64 B)
//      0x01758c: 710fa01f  cmp   w0, #0x3e8          ; base_code >= 1000
//      0x017590: 540001ab  b.lt  #0x175c4
//      0x017594: 528f1aa8  mov   w8, #0x78d5
//      0x017598: 72a4dd28  movk  w8, #0x26e9, lsl #16 ; w8 = 0x26e978d5
//      0x01759c: 51000429  sub   w9, w1, #1
//      0x0175a0: 5291270a  mov   w10, #0x8938
//      0x0175a4: 1b087c08  mul   w8, w0, w8
//      0x0175a8: 72a0082a  movk  w10, #0x41, lsl #16 ; w10 = 0x00418938
//      0x0175ac: 710f9d3f  cmp   w9, #0x3e7          ; 1 <= sub_code <= 1000
//      0x0175b0: 13880d08  extr  w8, w8, w8, #3      ; ror(w0 * 0x26e978d5, 3)
//      0x0175b4: 7a4a3102  ccmp  w8, w10, #2, lo     ; checks base_code % 1000 == 0
//      0x0175b8: 0b000028  add   w8, w1, w0
//      0x0175bc: 5a9f3100  csinv w0, w8, wzr, lo
//      0x0175c0: d65f03c0  ret
//      0x0175c4: 12800000  mov   w0, #-1
//      0x0175c8: d65f03c0  ret
// ==============================================================================
std::int32_t VerifyBusinessErrorCodeOpcode(std::int32_t base_code, std::int32_t sub_code) noexcept {
    return ttm_state_error_code_for_business(base_code, sub_code);
}

// ==============================================================================
// 3. AArch64 Opcode Proof: `pre_process_byte_code` (`0x1a700`, 444 B)
//      0x01a720: f840a008  ldur x8, [x0, #10]
//      0x01a724: 529805c9  mov  w9, #0xc02e
//      0x01a728: 72aeeb89  movk w9, #0x775c, lsl #16 ; magic = 0x775cc02e
//      0x01a730: b9400008  ldr  w8, [x0]
//      0x01a734: 6b09011f  cmp  w8, w9
//      0x01a738: 540000c1  b.ne #0x1a750             ; returns 3
//      0x01a73c: 79400808  ldrh w8, [x0, #4]
//      0x01a740: 7100291f  cmp  w8, #0xa             ; version <= 10
//      0x01a744: 54000189  b.ls #0x1a774             ; else returns 4
// ==============================================================================
bool VerifyBytecodeMagicAndVersion(std::uint32_t magic, std::uint16_t version) noexcept {
    return (magic == kTTMBytecodeMagic) && (version <= kTTMMaxBytecodeVersion);
}

} // namespace NextAI::OpenCut::TTMachineCore::DisassemblyReference
