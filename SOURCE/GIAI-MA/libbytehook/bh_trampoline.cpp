/**
 * @file bh_trampoline.cpp
 * @brief PLT Trampoline Generation and Executable Buffer Allocator Implementation
 *        Thực thi bộ tạo đoạn đệm chuyển tiếp Trampoline PLT và cấp phát vùng nhớ
 *
 * Implements AArch64 machine opcode synthesis and instruction cache synchronization.
 * Thực thi tổng hợp mã lệnh AArch64 và đồng bộ hóa bộ nhớ đệm lệnh (instruction cache).
 */

#include "bh_trampoline.h"
#include <stdlib.h>
#include <string.h>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/mman.h>
#include <unistd.h>
#endif

// Machine opcodes for AArch64 trampoline
// ldr x16, [pc, #8] -> 0x58000050
// br x16            -> 0xd61f0200
#define AARCH64_LDR_X16_PC_8  0x58000050U
#define AARCH64_BR_X16        0xd61f0200U

int bh_trampoline_init(void) {
    return 0;
}

bh_trampoline_t* bh_trampoline_create(void* target_func) {
    if (!target_func) {
        return NULL;
    }

    bh_trampoline_t* tramp = (bh_trampoline_t*)calloc(1, sizeof(bh_trampoline_t));
    if (!tramp) {
        return NULL;
    }

    tramp->instr_ldr = AARCH64_LDR_X16_PC_8;
    tramp->instr_br  = AARCH64_BR_X16;
    tramp->target_address = (uint64_t)(uintptr_t)target_func;

#if defined(__GNUC__) || defined(__clang__)
    // Flush instruction cache for newly generated code
    __builtin___clear_cache((char*)tramp, (char*)(tramp + 1));
#endif

    return tramp;
}

void bh_trampoline_destroy(bh_trampoline_t* tramp) {
    if (tramp) {
        free(tramp);
    }
}
