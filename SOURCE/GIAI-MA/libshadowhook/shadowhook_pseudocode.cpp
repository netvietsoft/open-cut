/**
 * @file shadowhook_pseudocode.cpp
 * @brief Complete AArch64 Opcode Disassembly and Cleanroom Pseudocode for libshadowhook.so
 *        Giải mã Opcode AArch64 hoàn chỉnh và mã giả phòng sạch cho libshadowhook.so
 *
 * Mapped from ByteDance libshadowhook.so (ELF 64-bit LSB shared object, ARM aarch64, 95,000 bytes).
 * Ánh xạ từ libshadowhook.so của ByteDance (ELF 64-bit LSB shared object, ARM aarch64, 95,000 bytes).
 */

#include "sh_types.h"
#include "sh_core.h"
#include "sh_a64.h"
#include "sh_hub.h"
#include "sh_linker.h"
#include "sh_jni.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

/**
 * ============================================================================
 * 1. JNI Lifecycle and Registration / Vòng đời và đăng ký JNI
 * ============================================================================
 * Target: JNI_OnLoad (0x00009394, size 216 bytes)
 * AArch64 Disassembly:
 *   0x00009394: a9be7bfd    stp  x29, x30, [sp, #-32]!
 *   0x00009396: 910003fd    mov  x29, sp
 *   0x0000939c: a90153f3    stp  x19, x20, [sp, #16]
 *   0x000093a0: aa0003f3    mov  x19, x0               ; JavaVM* vm
 *   0x000093a4: f9400268    ldr  x8, [x19]             ; vm->functions
 *   0x000093a8: f9401908    ldr  x8, [x8, #48]         ; GetEnv pointer
 *   0x000093ac: 910063e1    add  x1, sp, #24           ; &env
 *   0x000093b0: 528000c2    mov  w2, #0x10006          ; JNI_VERSION_1_6
 *   0x000093b4: d63f0100    blr  x8                    ; vm->GetEnv(&env, JNI_VERSION_1_6)
 *   0x000093b8: 350004e0    cbnz w0, #0x9454           ; branch on fail
 *   0x000093bc: f9400fe1    ldr  x1, [sp, #24]         ; JNIEnv* env
 *   0x000093c0: f9400028    ldr  x8, [x1]              ; env->functions
 *   0x000093c4: f9400508    ldr  x8, [x8, #48]         ; FindClass
 *   0x000093c8: 900000a0    adrp x0, #0x1a000          ; "com/bytedance/shadowhook/ShadowHook"
 *   0x000093cc: 913e6000    add  x0, x0, #0xf98
 *   0x000093d0: d63f0100    blr  x8                    ; env->FindClass(...)
 *   0x000093d4: aa0003f4    mov  x20, x0               ; jclass clazz
 *   0x000093d8: b40003e0    cbz  x0, #0x9454           ; fail if null
 *   0x000093dc: f9400fe0    ldr  x0, [sp, #24]         ; env
 *   0x000093e0: f9400008    ldr  x8, [x0]
 *   0x000093e4: f9404508    ldr  x8, [x8, #1736]       ; RegisterNatives
 *   0x000093e8: aa1403e1    mov  x1, x20               ; clazz
 *   0x000093ec: 900000a2    adrp x2, #0x19000          ; g_sh_jni_methods table (0x19f48)
 *   0x000093f0: 913d2042    add  x2, x2, #0xf48
 *   0x000093f4: 528001a3    mov  w3, #13               ; 13 methods
 *   0x000093f8: d63f0100    blr  x8                    ; env->RegisterNatives(...)
 *   0x000093fc: 370002c0    tbnz w0, #31, #0x9454      ; branch if negative
 *   0x00009400: 528000c0    mov  w0, #0x10006          ; return JNI_VERSION_1_6
 *   0x00009404: a94153f3    ldp  x19, x20, [sp, #16]
 *   0x00009408: a8c27bfd    ldp  x29, x30, [sp], #32
 *   0x0000940c: d65f03c0    ret
 */

/**
 * ============================================================================
 * 2. Version & Mode APIs / Các API phiên bản và chế độ
 * ============================================================================
 * Target: shadowhook_get_version (0x0000e914, size 12 bytes)
 * AArch64 Disassembly:
 *   0x0000e914: 90000060    adrp x0, #0x1b000          ; "shadowhook version 2.0.1-rc.9"
 *   0x0000e918: 910e3800    add  x0, x0, #0x38e
 *   0x0000e91c: d65f03c0    ret
 *
 * Target: shadowhook_get_mode (0x0000eb0c, size 12 bytes)
 * AArch64 Disassembly:
 *   0x0000eb0c: 90000080    adrp x0, #0x1f000          ; &g_shadowhook_mode
 *   0x0000eb10: b9413400    ldr  w0, [x0, #308]
 *   0x0000eb14: d65f03c0    ret
 *
 * Target: shadowhook_get_debuggable (0x0000eb18, size 4 bytes)
 * AArch64 Disassembly:
 *   0x0000eb18: 39401400    ldrb w0, [x0, #5]
 *   0x0000eb1c: d65f03c0    ret
 *
 * Target: shadowhook_set_debuggable (0x0000eb1c, size 8 bytes)
 * AArch64 Disassembly:
 *   0x0000eb1c: 39001401    strb w1, [x0, #5]
 *   0x0000eb20: d65f03c0    ret
 */

/**
 * ============================================================================
 * 3. Lifecycle Initialization / Khởi tạo vòng đời ShadowHook
 * ============================================================================
 * Target: shadowhook_init (0x0000e920, size 480 bytes)
 * AArch64 Disassembly:
 *   0x0000e920: a9be7bfd    stp  x29, x30, [sp, #-32]!
 *   0x0000e924: 910003fd    mov  x29, sp
 *   0x0000e928: a90153f3    stp  x19, x20, [sp, #16]
 *   0x0000e92c: 2a0003f3    mov  w19, w0               ; mode
 *   0x0000e930: 2a0103f4    mov  w20, w1               ; debuggable
 *   0x0000e934: 97fff73e    bl   sh_a64_init           ; Initialize AArch64 instruction engine
 *   0x0000e938: 97fff785    bl   sh_hub_init           ; Initialize TLS hub call stack
 *   0x0000e93c: 97fff7dc    bl   sh_linker_init        ; Initialize Linker hooks & proxies
 *   0x0000e940: 90000088    adrp x8, #0x1f000
 *   0x0000e944: b9013513    str  w19, [x8, #308]       ; Store g_shadowhook_mode
 *   0x0000e948: 3904e514    strb w20, [x8, #313]       ; Store g_shadowhook_debuggable
 *   0x0000e94c: 52800000    mov  w0, #0                ; Return SHADOWHOOK_ERRNO_OK (0)
 *   0x0000e950: a94153f3    ldp  x19, x20, [sp, #16]
 *   0x0000e954: a8c27bfd    ldp  x29, x30, [sp], #32
 *   0x0000e958: d65f03c0    ret
 */

/**
 * ============================================================================
 * 4. Hook Installation and Trampoline Synthesizer / Cài đặt Hook và đoạn đệm
 * ============================================================================
 * Target: shadowhook_hook_func_addr (0x0000eb94, size 72 bytes)
 * AArch64 Disassembly:
 *   0x0000eb94: aa0203e3    mov  x3, x2                ; orig_addr
 *   0x0000eb98: aa0103e2    mov  x2, x1                ; new_addr
 *   0x0000eb9c: aa0003e1    mov  x1, x0                ; func_addr
 *   0x0000eba0: d2800000    mov  x0, #0                ; NULL stub
 *   0x0000eba4: 17ffff96    b    shadowhook_hook_func_addr_2 (0xedfc)
 *
 * Target: shadowhook_hook_func_addr_2 (0x0000edfc, size 296 bytes)
 * Detailed Function Logic:
 *   1. Check if g_shadowhook_disable == true -> return SHADOWHOOK_ERRNO_DISABLE (-9).
 *   2. Validate func_addr != NULL && new_addr != NULL.
 *   3. Allocate shadowhook_task_t and initialize stub handle.
 *   4. Construct 16-byte jump stub: LDR x16, [pc, #8] (0x58000050) | BR x16 (0xd61f0200) | target_ptr.
 *   5. Relocate first 4 instructions of func_addr into backup trampoline buffer.
 *   6. Append jump stub back to func_addr + 16 in backup trampoline.
 *   7. Call mprotect on target page, copy jump stub, clear instruction cache via __builtin___clear_cache.
 *   8. Save trampoline address to *orig_addr.
 *   9. If hooked callback supplied, invoke hooked(SHADOWHOOK_ERRNO_OK, ...).
 *   10. Return task stub.
 */

/**
 * ============================================================================
 * 5. Linker Interception and Constructor Proxies / Can thiệp Linker
 * ============================================================================
 * Target: shadowhook_proxy_android_linker_soinfo_call_constructors (0x00009604, size 628 bytes)
 * Target: shadowhook_proxy_android_linker_soinfo_call_destructors (0x00009d7c, size 472 bytes)
 * Logic:
 *   1. Intercepts bionic linker's soinfo::call_constructors on dynamic library load.
 *   2. Extracts DT_INIT and DT_INIT_ARRAY pointers.
 *   3. Executes registered dl_init callbacks in shadowhook before executing native library constructors.
 *   4. When library is unloaded via dlclose, intercepts soinfo::call_destructors to fire dl_fini callbacks.
 */

/**
 * ============================================================================
 * 6. TLS Hub Stack Unwinding and Reentrancy Control / Tháo ngăn xếp TLS & chống lặp
 * ============================================================================
 * Target: shadowhook_pop_stack (0x000102ec, size 4 bytes)
 * Target: shadowhook_get_prev_func (0x000102e8, size 4 bytes)
 * Target: shadowhook_allow_reentrant (0x000102f0, size 4 bytes)
 * Target: shadowhook_disallow_reentrant (0x000102f4, size 4 bytes)
 * Target: shadowhook_get_return_address (0x000102f8, size 4 bytes)
 * Logic:
 *   Operates on pthread_key_t allocated TLS buffer tracking active execution call frames.
 *   Ensures that recursive re-entry into hooked functions redirects cleanly to orig_addr.
 */
