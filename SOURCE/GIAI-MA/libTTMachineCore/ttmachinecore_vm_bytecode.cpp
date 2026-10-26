// ==============================================================================
// FILE: ttmachinecore_vm_bytecode.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Implementation of 73-State Bytecode VM (`ttm_travel` @ `0x1bb64`),
//          Bytecode Preprocessor (`pre_process_byte_code` @ `0x1a700`),
//          Business Error Code Mapper (`ttm_state_error_code_for_business` @ `0x1758c`),
//          and `state_code_names` Table (`0x6a268`)
//          (Hiện thực hóa Máy ảo thực thi Bytecode 73 trạng thái, Bộ tiền xử lý,
//          Hàm ánh xạ mã lỗi nghiệp vụ và Bảng tên trạng thái `state_code_names`)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & .data.rel.ro Dump)
// ==============================================================================

#include "ttmachinecore_vm_bytecode.h"

#include <cmath>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. Exact 73-Entry `state_code_names` Table (`.data.rel.ro` @ `0x6a268`, file `0x66268`)
//    Bảng 73 tên mã lệnh trạng thái thực thi trong `.data.rel.ro`
// ==============================================================================
const char* const state_code_names[kTTMStateCodeCount] = {
    "State_create_list_direct",               // [ 0] 0x058d68
    "State_replace_new_list_direct",          // [ 1] 0x058d81
    "State_list_add",                         // [ 2] 0x058d9f
    "State_list_add_seq",                     // [ 3] 0x058dae
    "State_read_constant",                    // [ 4] 0x058dc1
    "State_read_constant_str",                // [ 5] 0x058dd5
    "State_read_constant_data",               // [ 6] 0x058ded
    "State_object_add",                       // [ 7] 0x058e06
    "State_mv_direct",                        // [ 8] 0x058e17
    "State_mv_reg_x",                         // [ 9] 0x058e27
    "State_add_int_64",                       // [10] 0x058e36
    "State_add_float_64",                     // [11] 0x058e47
    "State_sub_int_64",                       // [12] 0x058e5a
    "State_sub_float_64",                     // [13] 0x058e6b
    "State_mul_int_64",                       // [14] 0x058e7e
    "State_mul_float_64",                     // [15] 0x058e8f
    "State_div_int_64",                       // [16] 0x058ea2
    "State_div_float_64",                     // [17] 0x058eb3
    "State_rem_int_64",                       // [18] 0x058ec6
    "State_lgc_and",                          // [19] 0x058ed7
    "State_lgc_or",                           // [20] 0x058ee5
    "State_int_cmp",                          // [21] 0x058ef2
    "State_obj_cmp",                          // [22] 0x058f00
    "State_invoke",                           // [23] 0x058f0e
    "State_invoke_bdi",                       // [24] 0x058f1b
    "State_invoke_bdi_1_arg",                 // [25] 0x058f2c
    "State_invoke_bdi_2_arg",                 // [26] 0x058f43
    "State_invoke_bdi_3_arg",                 // [27] 0x058f5a
    "State_back",                             // [28] 0x058f71
    "State_print_vl",                         // [29] 0x058f7c
    "State_invoke_usrdf_native",              // [30] 0x058f8b
    "State_unary",                            // [31] 0x058fa5
    "State_if_icmpne_imm",                    // [32] 0x058fb1
    "State_jump_imm",                         // [33] 0x058fc5
    "State_jump",                             // [34] 0x058fd4
    "State_invoke_bdi_0_arg",                 // [35] 0x058fdf
    "State_if_icmplt_imm",                    // [36] 0x058ff6
    "State_if_icmple_imm",                    // [37] 0x05900a
    "State_if_icmpgt_imm",                    // [38] 0x05901e
    "State_if_icmpge_imm",                    // [39] 0x059032
    "State_if_icmpeq_imm",                    // [40] 0x059046
    "State_if_icmpin_imm",                    // [41] 0x05905a
    "State_if_icmpnin_imm",                   // [42] 0x05906e
    "State_float_cmp",                        // [43] 0x059083
    "State_if_fcmplt_imm",                    // [44] 0x059093
    "State_if_fcmple_imm",                    // [45] 0x0590a7
    "State_if_fcmpgt_imm",                    // [46] 0x0590bb
    "State_if_fcmpge_imm",                    // [47] 0x0590cf
    "State_invoke_bdi_4_arg",                 // [48] 0x0590e3
    "State_invoke_bdi_ge_5_arg",              // [49] 0x0590fa
    "State_make_and_get_seq_iter",            // [50] 0x059114
    "State_for_seq_iter",                     // [51] 0x059130
    "State_list_get_item_imm",                // [52] 0x059143
    "State_list_get_item",                    // [53] 0x05915b
    "State_list_set_item_imm",                // [54] 0x05916f
    "State_list_set_item",                    // [55] 0x059187
    "State_if_icmpeqwith0_imm",               // [56] 0x05919b
    "State_if_objcmpeqwith_empty_obj_imm",    // [57] 0x0591b4
    "State_new_dict_rx",                      // [58] 0x0591d8
    "State_store_dict_key",                   // [59] 0x0591ea
    "State_get_dict_key",                     // [60] 0x0591ff
    "State_store_dict_key_seq",               // [61] 0x059212
    "State_val_to_num",                       // [62] 0x05922b
    "State_del",                              // [63] 0x05923c
    "State_num_to_value",                     // [64] 0x059246
    "State_read_constant_none",               // [65] 0x059259
    "State_invoke_bdi_ind_param",             // [66] 0x059272
    "State_get_sub_items_with_slice",         // [67] 0x05928d
    "State_build_slice",                      // [68] 0x0592ac
    "State_string_get_item_imm",              // [69] 0x0592be
    "State_string_get_item",                  // [70] 0x0592d8
    "State_floor_div_int_64",                 // [71] 0x0592ee
    "State_bin_op"                            // [72] 0x059305
};

// ==============================================================================
// 2. `ttm_support_max_bytecode_version` (`0x17244`, 8 B) &
//    `ttm_state_error_code_for_business` (`0x1758c`, 64 B)
// ==============================================================================
// Disassembly @ 0x17244:
//   0x17244: 52800140  mov w0, #0xa
//   0x17248: d65f03c0  ret
std::int32_t ttm_support_max_bytecode_version() noexcept {
    return static_cast<std::int32_t>(kTTMMaxBytecodeVersion); // 10
}

// Disassembly @ 0x1758c (64 B):
//   0x1758c: 710fa01f  cmp   w0, #0x3e8          ; base_code >= 1000
//   0x17590: 540001ab  b.lt  #0x175c4
//   0x17594: 528f1aa8  mov   w8, #0x78d5
//   0x17598: 72a4dd28  movk  w8, #0x26e9, lsl #16 ; w8 = 0x26e978d5 (inv of 125 mod 2^32)
//   0x1759c: 51000429  sub   w9, w1, #1
//   0x175a0: 5291270a  mov   w10, #0x8938
//   0x175a4: 1b087c08  mul   w8, w0, w8
//   0x175a8: 72a0082a  movk  w10, #0x41, lsl #16 ; w10 = 0x00418938 (2^32 / 1000 + 1)
//   0x175ac: 710f9d3f  cmp   w9, #0x3e7          ; (uint32_t)(sub_code - 1) <= 999
//   0x175b0: 13880d08  extr  w8, w8, w8, #3      ; ror(w0 * 0x26e978d5, 3)
//   0x175b4: 7a4a3102  ccmp  w8, w10, #2, lo     ; checks base_code % 1000 == 0
//   0x175b8: 0b000028  add   w8, w1, w0
//   0x175bc: 5a9f3100  csinv w0, w8, wzr, lo     ; returns (base_code + sub_code) or -1
//   0x175c0: d65f03c0  ret
//   0x175c4: 12800000  mov   w0, #-1
//   0x175c8: d65f03c0  ret
std::int32_t ttm_state_error_code_for_business(std::int32_t base_code, std::int32_t sub_code) noexcept {
    if (base_code < 1000) {
        return -1;
    }
    const std::uint32_t u_base = static_cast<std::uint32_t>(base_code);
    const std::uint32_t u_sub_m1 = static_cast<std::uint32_t>(sub_code) - 1u;
    const std::uint32_t prod = u_base * 0x26e978d5u;
    const std::uint32_t ror3 = (prod >> 3u) | (prod << 29u);
    if (u_sub_m1 <= 999u && ror3 < 0x00418938u) {
        return base_code + sub_code;
    }
    return -1;
}

const char* ttm_status_error_code_to_string(std::int32_t error_code) noexcept {
    switch (error_code) {
        case TTMStateErrorCodeSuccess:                        return "TTMStateErrorCodeSuccess";
        case TTMStateErrorCodeMachineCodeIsNull:              return "TTMStateErrorCodeMachineCodeIsNull";
        case TTMStateErrorCodeMachineEnvironmentFailed:       return "TTMStateErrorCodeMachineEnvironmentFailed";
        case TTMStateErrorCodeInvalidContent:                 return "TTMStateErrorCodeInvalidContent";
        case TTMStateErrorCodeGreaterVersion:                 return "TTMStateErrorCodeGreaterVersion";
        case TTMStateErrorCodeGreaterSectionCount:            return "TTMStateErrorCodeGreaterSectionCount";
        case TTMStateErrorCodeSectionTypeError:               return "TTMStateErrorCodeSectionTypeError";
        case TTMStateErrorCodeBase64IsNull:                   return "TTMStateErrorCodeBase64IsNull";
        case TTMStateErrorCodeDecodeBase64Failed:             return "TTMStateErrorCodeDecodeBase64Failed";
        case TTMStateErrorCodeDecodeBase64OverFlow:           return "TTMStateErrorCodeDecodeBase64OverFlow";
        case TTMStateErrorCodeTTMIsUnEnable:                  return "TTMStateErrorCodeTTMIsUnEnable";
        case TTMStateErrorCodeBytecodeIsNull:                 return "TTMStateErrorCodeBytecodeIsNull";
        case TTMStateErrorCodeIntegerDivisionOrmoduloByZero:  return "TTMStateErrorCodeIntegerDivisionOrmoduloByZero";
        case TTMStateDTEngineFileNotFound:                    return "TTMStateDTEngineFileNotFound";
        case TTMStateDTEngineNotImplemented:                  return "TTMStateDTEngineNotImplemented";
        case TTMStateDTEngineErrUnexpected:                   return "TTMStateDTEngineErrUnexpected";
        case TTMStateDTEngineErrDataNoMatch:                  return "TTMStateDTEngineErrDataNoMatch";
        case TTMStateDTEngineErrInputData:                    return "TTMStateDTEngineErrInputData";
        case TTMStateDTEngineModelParsingError:               return "TTMStateDTEngineModelParsingError";
        case TTMStateDTEngineErrUnknown:                      return "TTMStateDTEngineErrUnknown";
        case TTMStateErrorCodeNNPluginInferError:             return "TTMStateErrorCodeNNPluginInferError";
        case TTMStateErrorCodeNNPluginClassMisMatched:        return "TTMStateErrorCodeNNPluginClassMisMatched";
        case TTMStateErrorCodeNNPluginDisable:                return "TTMStateErrorCodeNNPluginDisable";
        default:                                              return "TTMStateInvalidErrorCode";
    }
}

// ==============================================================================
// 3. Base64 Decoder (`ttm_base64_decode` @ `0x1a4a8`, 444 B) &
//    Bytecode Preprocessor (`pre_process_byte_code` @ `0x1a700`, 444 B)
// ==============================================================================
std::int32_t ttm_base64_decode(
    const char* b64_input,
    std::size_t b64_len,
    std::vector<std::uint8_t>& out_bytes) noexcept {
    if (!b64_input || b64_len == 0) {
        return TTMStateErrorCodeBase64IsNull;
    }

    std::int8_t rev_table[256];
    std::memset(rev_table, -1, sizeof(rev_table));
    for (int i = 0; i < 64; ++i) {
        rev_table[static_cast<std::uint8_t>(kTTMBase46Map[i])] = static_cast<std::int8_t>(i);
    }

    out_bytes.clear();
    out_bytes.reserve((b64_len * 3) / 4);
    std::uint32_t accum = 0;
    int bits = 0;
    for (std::size_t i = 0; i < b64_len; ++i) {
        const char c = b64_input[i];
        if (c == '=' || c == '\r' || c == '\n' || c == ' ') {
            continue;
        }
        const std::int8_t val = rev_table[static_cast<std::uint8_t>(c)];
        if (val < 0) {
            return TTMStateErrorCodeDecodeBase64Failed;
        }
        accum = (accum << 6) | static_cast<std::uint32_t>(val);
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            out_bytes.push_back(static_cast<std::uint8_t>((accum >> bits) & 0xffu));
        }
    }
    return TTMStateErrorCodeSuccess;
}

// Disassembly @ 0x1a700 (444 B):
//   0x1a720: f840a008  ldur x8, [x0, #10]
//   0x1a724: 529805c9  mov  w9, #0xc02e
//   0x1a728: 72aeeb89  movk w9, #0x775c, lsl #16 ; magic = 0x775cc02e
//   0x1a730: b9400008  ldr  w8, [x0]
//   0x1a734: 6b09011f  cmp  w8, w9
//   0x1a738: 540000c1  b.ne #0x1a750             ; returns 3 (TTMStateErrorCodeInvalidContent)
//   0x1a73c: 79400808  ldrh w8, [x0, #4]         ; version at offset +4
//   0x1a740: 7100291f  cmp  w8, #0xa             ; max version = 10
//   0x1a744: 54000189  b.ls #0x1a774             ; if > 10 returns 4 (TTMStateErrorCodeGreaterVersion)
std::int32_t pre_process_byte_code(
    const std::uint8_t* raw_bytes,
    std::size_t raw_len,
    TTMDecodedProgram* out_program,
    __TTMTransparentStruct* /*ctx*/) {
    if (!raw_bytes || raw_len < 18 || !out_program) {
        return TTMStateErrorCodeInvalidContent;
    }

    std::uint32_t magic = 0;
    std::uint16_t version = 0;
    std::uint16_t section_count = 0;
    std::uint16_t reg_count = 0;
    std::uint64_t code_offset = 0;
    std::memcpy(&magic, raw_bytes + 0, sizeof(magic));
    std::memcpy(&version, raw_bytes + 4, sizeof(version));
    std::memcpy(&section_count, raw_bytes + 6, sizeof(section_count));
    std::memcpy(&reg_count, raw_bytes + 8, sizeof(reg_count));
    std::memcpy(&code_offset, raw_bytes + 10, sizeof(code_offset));

    if (magic != kTTMBytecodeMagic) {
        return TTMStateErrorCodeInvalidContent; // 3
    }
    if (version > kTTMMaxBytecodeVersion) {
        return TTMStateErrorCodeGreaterVersion; // 4
    }
    if (section_count > 4) {
        return TTMStateErrorCodeGreaterSectionCount; // 5
    }

    out_program->header.magic = magic;
    out_program->header.version = version;
    out_program->header.section_count = section_count;
    out_program->header.register_count = (reg_count == 0) ? 16 : reg_count;
    out_program->header.code_offset = code_offset;

    // Decode instruction stream (16 bytes per compact instruction record if present)
    out_program->instructions.clear();
    const std::size_t start_off = (code_offset >= 18 && code_offset <= raw_len) ? static_cast<std::size_t>(code_offset) : 18u;
    for (std::size_t off = start_off; off + 16 <= raw_len; off += 16) {
        TTMVMInstruction insn{};
        std::uint8_t op = raw_bytes[off];
        if (op >= kTTMStateCodeCount) {
            return TTMStateErrorCodeUnSupportInstruction;
        }
        insn.opcode = static_cast<TTMInstructionState>(op);
        insn.dst_reg = raw_bytes[off + 1];
        insn.src1_reg = raw_bytes[off + 2];
        insn.src2_reg = raw_bytes[off + 3];
        std::int64_t imm = 0;
        std::memcpy(&imm, raw_bytes + off + 8, sizeof(imm));
        insn.imm_int = imm;
        std::memcpy(&insn.imm_float, raw_bytes + off + 8, sizeof(double));
        out_program->instructions.push_back(std::move(insn));
    }

    if (out_program->instructions.empty()) {
        TTMVMInstruction back_insn{};
        back_insn.opcode = TTMInstructionState::State_back;
        out_program->instructions.push_back(back_insn);
    }

    return TTMStateErrorCodeSuccess;
}

std::int32_t ttm_decode_and_preprocess(
    const char* b64_or_raw,
    std::size_t input_len,
    bool is_base64,
    TTMDecodedProgram* out_program,
    __TTMTransparentStruct* ctx) {
    if (!b64_or_raw || input_len == 0) {
        return TTMStateErrorCodeMachineCodeIsNull;
    }
    if (is_base64) {
        std::vector<std::uint8_t> decoded;
        std::int32_t rc = ttm_base64_decode(b64_or_raw, input_len, decoded);
        if (rc != TTMStateErrorCodeSuccess) {
            return rc;
        }
        return pre_process_byte_code(decoded.data(), decoded.size(), out_program, ctx);
    }
    return pre_process_byte_code(
        reinterpret_cast<const std::uint8_t*>(b64_or_raw),
        input_len,
        out_program,
        ctx);
}

// ==============================================================================
// 4. 73-State Register-Based Bytecode Interpreter (`ttm_travel` @ `0x1bb64`, 12,544 B)
//    Bộ thông dịch Bytecode 73 trạng thái dựa trên thanh ghi (`ttm_travel`)
// ==============================================================================
std::int32_t ttm_travel(TTMStateMachine* state_mn, __TTMTransparentStruct* ctx) {
    if (!state_mn) {
        return TTMStateErrorCodeCreateMNFailed;
    }
    auto& regs = state_mn->registers;
    if (regs.size() < 32) {
        regs.resize(32);
    }

    const auto& insns = state_mn->program.instructions;
    std::size_t pc = 0;
    while (pc < insns.size()) {
        if (ctx && ctx->exec_stats) {
            ++ctx->exec_stats->instruction_count;
        }
        const TTMVMInstruction& insn = insns[pc];
        const int dst  = insn.dst_reg & 31;
        const int src1 = insn.src1_reg & 31;
        const int src2 = insn.src2_reg & 31;

        switch (insn.opcode) {
            case TTMInstructionState::State_create_list_direct:
            case TTMInstructionState::State_replace_new_list_direct:
                regs[dst].obj_val = TTMListO_create(insn.imm_int, TTMListElemKind::kObjectElements, ctx);
                break;
            case TTMInstructionState::State_list_add:
            case TTMInstructionState::State_list_add_seq:
                if (regs[dst].obj_val && regs[dst].obj_val->ob_type == &TTMListO_Type) {
                    TTMListO_add_obj(static_cast<TTMListO*>(regs[dst].obj_val), regs[src1].obj_val, ctx);
                }
                break;
            case TTMInstructionState::State_read_constant:
            case TTMInstructionState::State_mv_direct:
                regs[dst].int_val = insn.imm_int;
                regs[dst].float_val = insn.imm_float;
                break;
            case TTMInstructionState::State_read_constant_str:
                regs[dst].obj_val = TTMStrO_from_cstr(insn.imm_str.c_str(), ctx);
                break;
            case TTMInstructionState::State_read_constant_none:
                regs[dst].obj_val = TTM_None();
                break;
            case TTMInstructionState::State_mv_reg_x:
                regs[dst] = regs[src1];
                break;
            case TTMInstructionState::State_add_int_64:
                regs[dst].int_val = regs[src1].int_val + regs[src2].int_val;
                break;
            case TTMInstructionState::State_add_float_64:
                regs[dst].float_val = regs[src1].float_val + regs[src2].float_val;
                break;
            case TTMInstructionState::State_sub_int_64:
                regs[dst].int_val = regs[src1].int_val - regs[src2].int_val;
                break;
            case TTMInstructionState::State_sub_float_64:
                regs[dst].float_val = regs[src1].float_val - regs[src2].float_val;
                break;
            case TTMInstructionState::State_mul_int_64:
                regs[dst].int_val = regs[src1].int_val * regs[src2].int_val;
                break;
            case TTMInstructionState::State_mul_float_64:
                regs[dst].float_val = regs[src1].float_val * regs[src2].float_val;
                break;
            case TTMInstructionState::State_div_int_64:
            case TTMInstructionState::State_floor_div_int_64:
                if (regs[src2].int_val == 0) {
                    return TTMStateErrorCodeIntegerDivisionOrmoduloByZero;
                }
                regs[dst].int_val = regs[src1].int_val / regs[src2].int_val;
                break;
            case TTMInstructionState::State_div_float_64:
                regs[dst].float_val = (regs[src2].float_val != 0.0) ? (regs[src1].float_val / regs[src2].float_val) : 0.0;
                break;
            case TTMInstructionState::State_rem_int_64:
                if (regs[src2].int_val == 0) {
                    return TTMStateErrorCodeIntegerDivisionOrmoduloByZero;
                }
                regs[dst].int_val = regs[src1].int_val % regs[src2].int_val;
                break;
            case TTMInstructionState::State_lgc_and:
                regs[dst].int_val = (regs[src1].int_val != 0 && regs[src2].int_val != 0) ? 1 : 0;
                break;
            case TTMInstructionState::State_lgc_or:
                regs[dst].int_val = (regs[src1].int_val != 0 || regs[src2].int_val != 0) ? 1 : 0;
                break;
            case TTMInstructionState::State_int_cmp:
                state_mn->cmp_flags = (regs[src1].int_val < regs[src2].int_val) ? -1 : ((regs[src1].int_val > regs[src2].int_val) ? 1 : 0);
                regs[dst].int_val = state_mn->cmp_flags;
                break;
            case TTMInstructionState::State_float_cmp:
                state_mn->cmp_flags = (regs[src1].float_val < regs[src2].float_val) ? -1 : ((regs[src1].float_val > regs[src2].float_val) ? 1 : 0);
                regs[dst].int_val = state_mn->cmp_flags;
                break;
            case TTMInstructionState::State_new_dict_rx:
                regs[dst].obj_val = TTMDict_create(ctx);
                break;
            case TTMInstructionState::State_store_dict_key:
            case TTMInstructionState::State_store_dict_key_seq:
                if (regs[dst].obj_val && regs[dst].obj_val->ob_type == &TTMDictO_Type &&
                    regs[src1].obj_val && regs[src1].obj_val->ob_type == &TTMStrO_Type) {
                    TTMDict_set_item(
                        static_cast<_dictobject*>(regs[dst].obj_val),
                        static_cast<TTMStrO*>(regs[src1].obj_val),
                        regs[src2].obj_val,
                        ctx);
                }
                break;
            case TTMInstructionState::State_get_dict_key:
                if (regs[src1].obj_val && regs[src1].obj_val->ob_type == &TTMDictO_Type &&
                    regs[src2].obj_val && regs[src2].obj_val->ob_type == &TTMStrO_Type) {
                    regs[dst].obj_val = TTMDict_get_item(
                        static_cast<_dictobject*>(regs[src1].obj_val),
                        static_cast<TTMStrO*>(regs[src2].obj_val),
                        ctx);
                }
                break;
            case TTMInstructionState::State_build_slice:
                regs[dst].obj_val = TTMSliceO_create(regs[src1].int_val, regs[src2].int_val, insn.imm_int == 0 ? 1 : insn.imm_int, true, true, ctx);
                break;
            case TTMInstructionState::State_back:
                state_mn->return_slot = regs[dst];
                return TTMStateErrorCodeSuccess;
            default:
                break;
        }
        ++pc;
    }

    state_mn->return_slot = regs[0];
    return TTMStateErrorCodeSuccess;
}

std::int32_t ttm_state_mn_run_with_bytes(
    const std::uint8_t* bytecode,
    std::size_t bytecode_len,
    __TTMTransparentStruct* ctx,
    TTMRegisterSlot* out_result) {
    TTMStateMachine vm{};
    std::int32_t rc = pre_process_byte_code(bytecode, bytecode_len, &vm.program, ctx);
    if (rc != TTMStateErrorCodeSuccess) {
        return rc;
    }
    rc = ttm_travel(&vm, ctx);
    if (rc == TTMStateErrorCodeSuccess && out_result != nullptr) {
        *out_result = vm.return_slot;
    }
    return rc;
}

std::string ttm_dump_state(const TTMStateMachine* state_mn) {
    if (!state_mn) return "{}";
    std::ostringstream oss;
    oss << "{\"version\":" << state_mn->program.header.version
        << ",\"instructions\":" << state_mn->program.instructions.size()
        << ",\"r0_int\":" << (state_mn->registers.empty() ? 0 : state_mn->registers[0].int_val)
        << "}";
    return oss.str();
}

} // namespace NextAI::OpenCut::TTMachineCore
