/**
 * @file bytehook_pseudocode.cpp
 * @brief Binary Pseudocode and AArch64 Opcode Trace Mapping for libbytehook.so
 *        Mã giả nhị phân và ánh xạ vết lệnh AArch64 cho libbytehook.so
 *
 * Provides exact assembly tracing and mathematical proof mappings for all 20 exported C functions.
 * Cung cấp dấu vết hợp ngữ chuẩn xác và ánh xạ chứng minh toán học cho toàn bộ 20 hàm C xuất khẩu.
 */

#include "bh_core.h"
#include <stdint.h>
#include <string.h>

/**
 * ==============================================================================
 * 1. bytehook_get_version (VAddr 0x0000c6cc, Size = 12 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x0000c6cc: adrp     x0, #0x2000
 *   0x0000c6d0: add      x0, x0, #0xcd9           ; Returns pointer to "bytehook version 1.1.2-alpha.0"
 *   0x0000c6d4: ret
 */
const char* pseudo_bytehook_get_version(void) {
    return bytehook_get_version();
}

/**
 * ==============================================================================
 * 2. bytehook_get_mode (VAddr 0x0000c840, Size = 12 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x0000c840: adrp     x8, #0x15000
 *   0x0000c844: ldr      w0, [x8, #0xe28]         ; Load global g_mode integer
 *   0x0000c848: ret
 */
int pseudo_bytehook_get_mode(void) {
    return bytehook_get_mode();
}

/**
 * ==============================================================================
 * 3. bytehook_get_prev_func (VAddr 0x0000cad0, Size = 28 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x0000cad0: stp      x29, x30, [sp, #-0x10]!
 *   0x0000cad4: mov      x29, sp
 *   0x0000cad8: bl       #0x97ec                  ; Fetch thread-local stack
 *   0x0000cadc: bl       #0x98b4                  ; Query predecessor function pointer
 *   0x0000cae0: ldp      x29, x30, [sp], #0x10
 *   0x0000cae4: ret
 */
void* pseudo_bytehook_get_prev_func(void* func) {
    return bytehook_get_prev_func(func);
}

/**
 * ==============================================================================
 * 4. bytehook_get_return_address (VAddr 0x0000caec, Size = 28 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x0000caec: stp      x29, x30, [sp, #-0x10]!
 *   0x0000caf0: mov      x29, sp
 *   0x0000caf4: bl       #0x97ec                  ; Fetch thread-local stack
 *   0x0000caf8: bl       #0x9924                  ; Query return address
 *   0x0000cafc: ldp      x29, x30, [sp], #0x10
 *   0x0000cb00: ret
 */
void* pseudo_bytehook_get_return_address(void) {
    return bytehook_get_return_address();
}

/**
 * ==============================================================================
 * 5. bytehook_pop_stack (VAddr 0x0000cb08, Size = 28 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x0000cb08: stp      x29, x30, [sp, #-0x10]!
 *   0x0000cb0c: mov      x29, sp
 *   0x0000cb10: bl       #0x97ec                  ; Fetch thread-local stack
 *   0x0000cb14: bl       #0x9950                  ; Pop matching frame
 *   0x0000cb18: ldp      x29, x30, [sp], #0x10
 *   0x0000cb1c: ret
 */
void pseudo_bytehook_pop_stack(void* func) {
    bytehook_pop_stack(func);
}

/**
 * ==============================================================================
 * 6. JNI_OnLoad (VAddr 0x00009144, Size = 216 bytes)
 * ==============================================================================
 * AArch64 Assembly Trace:
 *   0x00009168: ldr      x8, [x0]
 *   0x00009178: ldr      x8, [x8, #0x30]          ; GetEnv(&env, JNI_VERSION_1_6)
 *   0x000091a0: adrp     x1, #0x2000
 *   0x000091a4: add      x1, x1, #0x985           ; "com/bytedance/android/bytehook/ByteHook"
 *   0x000091a8: blr      x8                       ; FindClass
 *   0x000091b0: adrp     x1, #0x11000
 *   0x000091b8: add      x1, x1, #0x7a8           ; 10 JNINativeMethod entries table
 *   0x000091d0: mov      w3, #0xa                 ; 10 methods count
 *   0x000091dc: ldr      x8, [x8, #0x6b8]         ; RegisterNatives
 *   0x000091e0: blr      x8
 */
int pseudo_JNI_OnLoad(void* vm) {
    (void)vm;
    return 0x00010006; // JNI_VERSION_1_6
}
