// ==============================================================================
// FILE: ttmachinecore_vm_bytecode.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Bytecode Preprocessor (`pre_process_byte_code` @ `0x1a700`), Base64
//          Decoder (`ttm_base64_decode` @ `0x1a4a8`), Business Error Code Mapper
//          (`ttm_state_error_code_for_business` @ `0x1758c`), and 73-State
//          Register-Based Bytecode Virtual Machine (`ttm_travel` @ `0x1bb64`)
//          (Bộ tiền xử lý Bytecode, Giải mã Base64, Ánh xạ mã lỗi nghiệp vụ và
//          Máy ảo thực thi Bytecode 73 trạng thái thanh ghi)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly `0x16ea4..0x24bc0`)
// ==============================================================================

#pragma once

#include "ttmachinecore_types.h"
#include "ttmachinecore_objects_hashmap.h"

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. VM Bytecode Header & Instruction Representation (`0x1a700..0x1bb64`)
//    Cấu trúc Header Bytecode (Magic `0x775cc02e`, Version `<= 10`) & Lệnh VM
// ==============================================================================
struct TTMBytecodeHeader {
    std::uint32_t magic{kTTMBytecodeMagic};        // +0x00: 0x775cc02e
    std::uint16_t version{kTTMMaxBytecodeVersion}; // +0x04: <= 10 (0x0a)
    std::uint16_t section_count{1};                // +0x06
    std::uint16_t register_count{16};              // +0x08
    std::uint64_t code_offset{18};                 // +0x0a (unaligned 8-byte read `ldur x8, [x0, #10]` @ 0x1a720)
};

struct TTMVMInstruction {
    TTMInstructionState opcode{TTMInstructionState::State_back};
    std::int32_t        dst_reg{0};
    std::int32_t        src1_reg{0};
    std::int32_t        src2_reg{0};
    std::int64_t        imm_int{0};
    double              imm_float{0.0};
    std::string         imm_str{};
};

struct TTMDecodedProgram {
    TTMBytecodeHeader               header{};
    std::vector<TTMVMInstruction>   instructions{};
    std::vector<std::string>        const_str_pool{};
    std::vector<std::int64_t>       const_int_pool{};
    std::vector<double>             const_float_pool{};
};

struct TTMRegisterSlot {
    std::int64_t int_val{0};
    double       float_val{0.0};
    _object*     obj_val{nullptr};
};

struct TTMStateMachine {
    std::vector<TTMRegisterSlot> registers{32};
    std::int32_t                 cmp_flags{0};
    TTMDecodedProgram            program{};
    TTMRegisterSlot              return_slot{};
    bool                         initialized{false};
};

// ==============================================================================
// 2. Exported VM & Preprocessor Functions (`0x16ea4..0x24bc0`)
// ==============================================================================
std::int32_t ttm_support_max_bytecode_version() noexcept;
std::int32_t ttm_state_error_code_for_business(std::int32_t base_code, std::int32_t sub_code) noexcept;
const char*  ttm_status_error_code_to_string(std::int32_t error_code) noexcept;

std::int32_t ttm_base64_decode(
    const char* b64_input,
    std::size_t b64_len,
    std::vector<std::uint8_t>& out_bytes) noexcept;

std::int32_t pre_process_byte_code(
    const std::uint8_t* raw_bytes,
    std::size_t raw_len,
    TTMDecodedProgram* out_program,
    __TTMTransparentStruct* ctx);

std::int32_t ttm_decode_and_preprocess(
    const char* b64_or_raw,
    std::size_t input_len,
    bool is_base64,
    TTMDecodedProgram* out_program,
    __TTMTransparentStruct* ctx);

std::int32_t ttm_travel(
    TTMStateMachine* state_mn,
    __TTMTransparentStruct* ctx);

std::int32_t ttm_state_mn_run_with_bytes(
    const std::uint8_t* bytecode,
    std::size_t bytecode_len,
    __TTMTransparentStruct* ctx,
    TTMRegisterSlot* out_result);

std::string ttm_dump_state(const TTMStateMachine* state_mn);

} // namespace NextAI::OpenCut::TTMachineCore
