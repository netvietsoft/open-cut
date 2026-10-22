/**
 * @file sh_a64.cpp
 * @brief AArch64 Machine Instruction Relocation and Inline Trampoline Implementation
 *        Triển khai tái định vị lệnh mã máy AArch64 và tạo đoạn đệm Inline Trampoline
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#include "sh_a64.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

#define PAGE_START(addr) ((uintptr_t)(addr) & ~((uintptr_t)getpagesize() - 1))
#define PAGE_END(addr, len) (((uintptr_t)(addr) + (len) + getpagesize() - 1) & ~((uintptr_t)getpagesize() - 1))

// AArch64 Opcode Masks and Encodings / Mặt nạ và mã hóa Opcode AArch64
#define A64_LDR_LIT_MASK        0xBF000000
#define A64_LDR_LIT_VAL         0x18000000

#define A64_ADR_MASK            0x9F000000
#define A64_ADR_VAL             0x10000000

#define A64_ADRP_MASK           0x9F000000
#define A64_ADRP_VAL            0x90000000

#define A64_B_MASK              0xFC000000
#define A64_B_VAL               0x14000000

#define A64_BL_MASK             0xFC000000
#define A64_BL_VAL              0x94000000

#define A64_B_COND_MASK         0xFF000010
#define A64_B_COND_VAL          0x54000000

#define A64_CBZ_MASK            0x7F000000
#define A64_CBZ_VAL             0x34000000

#define A64_CBNZ_MASK           0x7F000000
#define A64_CBNZ_VAL            0x35000000

#define A64_TBZ_MASK            0x7F000000
#define A64_TBZ_VAL             0x36000000

#define A64_TBNZ_MASK           0x7F000000
#define A64_TBNZ_VAL            0x37000000

static bool g_a64_initialized = false;

int sh_a64_init(void) {
    g_a64_initialized = true;
    return 0;
}

/**
 * @brief Decode instruction type and check if PC-relative
 *        Giải mã kiểu lệnh và kiểm tra xem có phụ thuộc vào thanh ghi PC không
 */
static bool sh_a64_is_pc_relative(uint32_t instr) {
    if ((instr & A64_ADR_MASK) == A64_ADR_VAL) return true;
    if ((instr & A64_ADRP_MASK) == A64_ADRP_VAL) return true;
    if ((instr & A64_B_MASK) == A64_B_VAL) return true;
    if ((instr & A64_BL_MASK) == A64_BL_VAL) return true;
    if ((instr & A64_B_COND_MASK) == A64_B_COND_VAL) return true;
    if ((instr & A64_CBZ_MASK) == A64_CBZ_VAL) return true;
    if ((instr & A64_CBNZ_MASK) == A64_CBNZ_VAL) return true;
    if ((instr & A64_TBZ_MASK) == A64_TBZ_VAL) return true;
    if ((instr & A64_TBNZ_MASK) == A64_TBNZ_VAL) return true;
    if ((instr & A64_LDR_LIT_MASK) == A64_LDR_LIT_VAL) return true;
    return false;
}

/**
 * @brief Relocate a single PC-relative instruction into backup trampoline buffer
 *        Tái định vị một lệnh phụ thuộc PC vào bộ đệm đoạn đệm sao lưu
 */
static int sh_a64_relocate_instruction(uint32_t instr, uintptr_t old_pc, uintptr_t new_pc, uint32_t* out_buf, size_t* out_count) {
    if (!sh_a64_is_pc_relative(instr)) {
        // Non-PC-relative instruction: copy directly / Lệnh không phụ thuộc PC: sao chép trực tiếp
        out_buf[0] = instr;
        *out_count = 1;
        return 0;
    }

    // ADR / ADRP handling / Xử lý lệnh ADR / ADRP
    if ((instr & A64_ADR_MASK) == A64_ADR_VAL || (instr & A64_ADRP_MASK) == A64_ADRP_VAL) {
        uint32_t rd = instr & 0x1F;
        int64_t imm;
        uint32_t immlo = (instr >> 29) & 0x3;
        uint32_t immhi = (instr >> 5) & 0x7FFFF;
        int64_t raw_imm = (int64_t)((immhi << 2) | immlo);
        if (raw_imm & (1LL << 20)) {
            raw_imm |= ~((1LL << 21) - 1); // Sign extension / Mở rộng dấu
        }

        uintptr_t target_calc_addr;
        if ((instr & A64_ADRP_MASK) == A64_ADRP_VAL) {
            imm = raw_imm << 12;
            target_calc_addr = (old_pc & ~0xFFFULL) + imm;
        } else {
            imm = raw_imm;
            target_calc_addr = old_pc + imm;
        }

        // Synthesize absolute 64-bit load for Rd: LDR Rd, [PC, #8]; B #12; target_calc_addr
        // Tổng hợp lệnh nạp tuyệt đối 64-bit cho Rd: LDR Rd, [PC, #8]; B #12; target_calc_addr
        out_buf[0] = 0x58000040 | rd; // LDR Rd, [PC, #8]
        out_buf[1] = 0x14000003;      // B #12 (skip 8-byte pointer)
        memcpy(&out_buf[2], &target_calc_addr, sizeof(uintptr_t));
        *out_count = 4;
        return 0;
    }

    // Direct B / BL branch handling / Xử lý lệnh rẽ nhánh trực tiếp B / BL
    if ((instr & A64_B_MASK) == A64_B_VAL || (instr & A64_BL_MASK) == A64_BL_VAL) {
        int64_t imm26 = instr & 0x03FFFFFF;
        if (imm26 & (1 << 25)) {
            imm26 |= ~((1 << 26) - 1);
        }
        uintptr_t target = old_pc + (imm26 << 2);
        bool is_bl = ((instr & A64_BL_MASK) == A64_BL_VAL);

        if (is_bl) {
            // Synthesize: LDR x16, [PC, #8]; BLR x16; B #8; target
            out_buf[0] = 0x58000050; // LDR x16, [PC, #8]
            out_buf[1] = 0xd63f0200; // BLR x16
            out_buf[2] = 0x14000003; // B #12
            memcpy(&out_buf[3], &target, sizeof(uintptr_t));
            *out_count = 5;
        } else {
            // Synthesize: LDR x16, [PC, #8]; BR x16; target
            out_buf[0] = 0x58000050; // LDR x16, [PC, #8]
            out_buf[1] = 0xd61f0200; // BR x16
            memcpy(&out_buf[2], &target, sizeof(uintptr_t));
            *out_count = 4;
        }
        return 0;
    }

    // Default copy / Mặc định sao chép nguyên bản
    out_buf[0] = instr;
    *out_count = 1;
    return 0;
}

int sh_a64_create_trampoline(void* target_func, void* new_func, sh_a64_trampoline_t* tramp) {
    if (!target_func || !new_func || !tramp) {
        return SHADOWHOOK_ERRNO_INVALID_PARAM;
    }

    tramp->target_addr = target_func;
    tramp->new_addr = new_func;

    // Backup original 16 bytes / Sao lưu 16 byte lệnh gốc
    memcpy(tramp->original_backup, target_func, SH_A64_HOOK_SIZE);

    // Build jump stub to new_func / Xây dựng jump stub nhảy tới new_func
    // Stub consists of:
    // 0x00: ldr x16, [pc, #8] (0x58000050)
    // 0x04: br  x16          (0xd61f0200)
    // 0x08: [64-bit absolute target address]
    uint32_t* stub_u32 = (uint32_t*)tramp->jump_stub;
    stub_u32[0] = 0x58000050; // ldr x16, [pc, #8]
    stub_u32[1] = 0xd61f0200; // br  x16
    memcpy(&stub_u32[2], &new_func, sizeof(void*));

    // Relocate original instructions into backup trampoline buffer
    // Tái định vị các lệnh gốc vào bộ đệm đoạn đệm sao lưu
    uint32_t* orig_instrs = (uint32_t*)target_func;
    uint32_t* tramp_instrs = (uint32_t*)tramp->backup_trampoline;
    size_t tramp_idx = 0;

    for (size_t i = 0; i < 4; ++i) { // 4 instructions = 16 bytes
        uintptr_t old_pc = (uintptr_t)target_func + (i * 4);
        uintptr_t new_pc = (uintptr_t)&tramp->backup_trampoline[tramp_idx * 4];
        size_t count = 0;
        sh_a64_relocate_instruction(orig_instrs[i], old_pc, new_pc, &tramp_instrs[tramp_idx], &count);
        tramp_idx += count;
    }

    // Append jump back to target_func + 16
    // Nối thêm lệnh nhảy trở lại vị trí target_func + 16
    uintptr_t return_addr = (uintptr_t)target_func + SH_A64_HOOK_SIZE;
    tramp_instrs[tramp_idx++] = 0x58000050; // ldr x16, [pc, #8]
    tramp_instrs[tramp_idx++] = 0xd61f0200; // br  x16
    memcpy(&tramp_instrs[tramp_idx], &return_addr, sizeof(void*));

    return 0;
}

int sh_a64_install_hook(sh_a64_trampoline_t* tramp) {
    if (!tramp || !tramp->target_addr) {
        return SHADOWHOOK_ERRNO_INVALID_PARAM;
    }

    uintptr_t page_start = PAGE_START(tramp->target_addr);
    size_t page_len = PAGE_END(tramp->target_addr, SH_A64_HOOK_SIZE) - page_start;

    // Toggle memory protection to PROT_READ | PROT_WRITE | PROT_EXEC
    // Bật quyền đọc/ghi/thực thi trên trang bộ nhớ
    if (mprotect((void*)page_start, page_len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        return SHADOWHOOK_ERRNO_MPROTECT;
    }

    // Atomic or synchronized copy of jump stub
    // Sao chép đồng bộ jump stub vào điểm nhập của hàm
    memcpy(tramp->target_addr, tramp->jump_stub, SH_A64_HOOK_SIZE);

    // Flush instruction cache / Làm sạch bộ nhớ đệm lệnh (I-Cache)
#if defined(__GNUC__) || defined(__clang__)
    __builtin___clear_cache((char*)tramp->target_addr, (char*)tramp->target_addr + SH_A64_HOOK_SIZE);
    __builtin___clear_cache((char*)tramp->backup_trampoline, (char*)tramp->backup_trampoline + SH_A64_BACKUP_SIZE);
#endif

    // Restore read/exec protection / Khôi phục bảo vệ trang đọc/thực thi
    mprotect((void*)page_start, page_len, PROT_READ | PROT_EXEC);

    return 0;
}

int sh_a64_uninstall_hook(sh_a64_trampoline_t* tramp) {
    if (!tramp || !tramp->target_addr) {
        return SHADOWHOOK_ERRNO_INVALID_PARAM;
    }

    uintptr_t page_start = PAGE_START(tramp->target_addr);
    size_t page_len = PAGE_END(tramp->target_addr, SH_A64_HOOK_SIZE) - page_start;

    if (mprotect((void*)page_start, page_len, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        return SHADOWHOOK_ERRNO_MPROTECT;
    }

    // Restore original instructions / Khôi phục lệnh nguyên bản
    memcpy(tramp->target_addr, tramp->original_backup, SH_A64_HOOK_SIZE);

#if defined(__GNUC__) || defined(__clang__)
    __builtin___clear_cache((char*)tramp->target_addr, (char*)tramp->target_addr + SH_A64_HOOK_SIZE);
#endif

    mprotect((void*)page_start, page_len, PROT_READ | PROT_EXEC);

    return 0;
}
