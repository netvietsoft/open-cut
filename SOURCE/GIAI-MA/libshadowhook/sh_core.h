/**
 * @file sh_core.h
 * @brief ShadowHook Core Engine Header and Public Hook API Declarations
 *        Tiêu đề động cơ cốt lõi ShadowHook và khai báo các API Hook công khai
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#ifndef SH_CORE_H
#define SH_CORE_H

#include "sh_types.h"
#include "sh_a64.h"
#include "sh_hub.h"
#include "sh_linker.h"

#ifdef __cplusplus
extern "C" {
#endif

// Core Lifecycle APIs / Các API vòng đời cốt lõi
int shadowhook_init(int mode, bool debuggable);
const char* shadowhook_get_version(void);
int shadowhook_get_mode(void);
bool shadowhook_get_debuggable(void);
void shadowhook_set_debuggable(bool debuggable);
bool shadowhook_get_recordable(void);
void shadowhook_set_recordable(bool recordable);
bool shadowhook_get_disable(void);
void shadowhook_set_disable(bool disable);
int shadowhook_get_errno(void);
const char* shadowhook_to_errmsg(int error_number);
char* shadowhook_get_records(uint32_t flags);
void shadowhook_dump_records(const char* pathname);

// Function Hooking APIs / Các API Hook theo địa chỉ hàm
void* shadowhook_hook_func_addr(void* func_addr, void* new_addr, void** orig_addr);
void* shadowhook_hook_func_addr_2(void* func_addr, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg);

// Symbol Address Hooking APIs / Các API Hook theo địa chỉ biểu tượng
void* shadowhook_hook_sym_addr(void* sym_addr, void* new_addr, void** orig_addr);
void* shadowhook_hook_sym_addr_2(void* sym_addr, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg);

// Symbol Name Hooking APIs / Các API Hook theo tên biểu tượng
void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr);
void* shadowhook_hook_sym_name_2(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg);
void* shadowhook_hook_sym_name_callback(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                        shadowhook_dl_callback_t cb, void* cb_arg);
void* shadowhook_hook_sym_name_callback_2(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                          shadowhook_hooked_t hooked, void* hooked_arg,
                                          shadowhook_dl_callback_t cb, void* cb_arg);

// Unhook API / API gỡ bỏ Hook
int shadowhook_unhook(void* stub);

// Interceptor APIs / Các API can thiệp theo chế độ Interceptor
void* shadowhook_intercept_func_addr(void* func_addr, void* new_addr, void** orig_addr);
void* shadowhook_intercept_sym_addr(void* sym_addr, void* new_addr, void** orig_addr);
void* shadowhook_intercept_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr);
void* shadowhook_intercept_sym_name_callback(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                             shadowhook_dl_callback_t cb, void* cb_arg);
void* shadowhook_intercept_instr_addr(void* instr_addr, void* new_addr, void** orig_addr);
int shadowhook_unintercept(void* stub);

// Interceptor Trampoline Dispatchers / Bộ phân phối gọi Interceptor
void shadowhook_interceptor_caller(void);
void shadowhook_interceptor_glue(void);

#ifdef __cplusplus
}
#endif

#endif // SH_CORE_H