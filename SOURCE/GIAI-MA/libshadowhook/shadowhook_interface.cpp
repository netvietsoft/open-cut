/**
 * @file shadowhook_interface.cpp
 * @brief ShadowHook 7-Stage Closed-Loop Self-Test Implementation
 *        Triển khai bộ kiểm thử khép kín 7 giai đoạn cho ShadowHook
 *
 * Cleanroom verification test suite reconstructed from ByteDance libshadowhook.so.
 * Bộ kiểm thử xác minh phòng sạch tái cấu trúc từ libshadowhook.so của ByteDance.
 */

#include "shadowhook_interface.h"
#include "sh_types.h"
#include "sh_core.h"
#include "sh_a64.h"
#include "sh_hub.h"
#include "sh_linker.h"
#include "sh_jni.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Mock dummy function for hooking test / Hàm mẫu phục vụ kiểm thử hook
static int dummy_target_function(int a, int b) {
    return a + b;
}

static int dummy_hook_function(int a, int b) {
    return a * b;
}

static void dummy_dl_init_callback(const char* lib_name, void* handle, void* arg) {
    (void)lib_name;
    (void)handle;
    (void)arg;
}

int shadowhook_run_self_test(shadowhook_test_result_t* result) {
    if (!result) return -1;
    memset(result, 0, sizeof(shadowhook_test_result_t));
    result->total_tests = 7;

    // =========================================================================
    // Stage 1: Version Check & Initialization / Giai đoạn 1: Phiên bản & Khởi tạo
    // =========================================================================
    int init_rc = shadowhook_init(SHADOWHOOK_MODE_SHARED, true);
    const char* version = shadowhook_get_version();
    bool s1 = (init_rc == SHADOWHOOK_ERRNO_OK) &&
              (version != NULL) &&
              (strstr(version, "2.0.1") != NULL) &&
              (shadowhook_get_mode() == SHADOWHOOK_MODE_SHARED) &&
              (shadowhook_get_debuggable() == true);
    result->stage1_version_and_init_pass = s1;
    if (s1) result->total_passed++;

    // =========================================================================
    // Stage 2: Instruction Relocation Engine / Giai đoạn 2: Động cơ tái định vị lệnh
    // =========================================================================
    uint32_t mock_target_code[8] = {
        0xd2800020, // mov x0, #1
        0x10000001, // adr x1, #0
        0x14000001, // b #4
        0xd65f03c0, // ret
        0x0, 0x0, 0x0, 0x0
    };
    sh_a64_trampoline_t tramp;
    memset(&tramp, 0, sizeof(tramp));
    int tramp_rc = sh_a64_create_trampoline((void*)mock_target_code, (void*)dummy_hook_function, &tramp);
    uint32_t* stub_u32 = (uint32_t*)tramp.jump_stub;
    bool s2 = (tramp_rc == 0) &&
              (stub_u32[0] == 0x58000050) && // ldr x16, [pc, #8]
              (stub_u32[1] == 0xd61f0200) && // br  x16
              (tramp.target_addr == (void*)mock_target_code) &&
              (tramp.new_addr == (void*)dummy_hook_function);
    result->stage2_instruction_relocation_pass = s2;
    if (s2) result->total_passed++;

    // =========================================================================
    // Stage 3: TLS Hub Call Stack / Giai đoạn 3: Ngăn xếp cuộc gọi TLS Hub
    // =========================================================================
    void* fake_target = (void*)0x1000;
    void* fake_orig = (void*)0x2000;
    void* fake_caller = (void*)0x3000;
    sh_hub_push_frame(fake_target, fake_orig, fake_caller);
    void* prev = shadowhook_get_prev_func(fake_target);
    void* caller = shadowhook_get_return_address();
    shadowhook_allow_reentrant(fake_target);
    shadowhook_disallow_reentrant(fake_target);
    shadowhook_pop_stack(fake_target);
    bool s3 = (prev == fake_orig) && (caller == fake_caller);
    result->stage3_tls_hub_stack_pass = s3;
    if (s3) result->total_passed++;

    // =========================================================================
    // Stage 4: Linker Proxy & Symbol Resolution / Giai đoạn 4: Proxy Linker & Phân giải biểu tượng
    // =========================================================================
    int reg_init = shadowhook_register_dl_init_callback(dummy_dl_init_callback, NULL);
    int unreg_init = shadowhook_unregister_dl_init_callback(dummy_dl_init_callback);
    void* dlsym_res = shadowhook_dlsym(NULL, "malloc");
    bool s4 = (reg_init == SHADOWHOOK_ERRNO_OK) &&
              (unreg_init == SHADOWHOOK_ERRNO_OK) &&
              (dlsym_res != NULL);
    result->stage4_linker_symbol_resolver_pass = s4;
    if (s4) result->total_passed++;

    // =========================================================================
    // Stage 5: Function Hooking & Unhooking / Giai đoạn 5: Cài đặt và gỡ bỏ Hook
    // =========================================================================
    void* orig_dummy = NULL;
    void* stub = shadowhook_hook_func_addr((void*)dummy_target_function,
                                          (void*)dummy_hook_function,
                                          &orig_dummy);
    char* records = shadowhook_get_records(0);
    bool s5_records_ok = (records != NULL) && (strstr(records, "tasks") != NULL);
    if (records) free(records);
    int unhook_rc = shadowhook_unhook(stub);
    bool s5 = (stub != NULL) && (orig_dummy != NULL) && s5_records_ok && (unhook_rc == SHADOWHOOK_ERRNO_OK);
    result->stage5_function_hook_unhook_pass = s5;
    if (s5) result->total_passed++;

    // =========================================================================
    // Stage 6: Interceptor Mechanism / Giai đoạn 6: Cơ chế Interceptor
    // =========================================================================
    void* orig_intercept = NULL;
    void* int_stub = shadowhook_intercept_func_addr((void*)dummy_target_function,
                                                    (void*)dummy_hook_function,
                                                    &orig_intercept);
    int unint_rc = shadowhook_unintercept(int_stub);
    shadowhook_interceptor_caller();
    shadowhook_interceptor_glue();
    bool s6 = (int_stub != NULL) && (orig_intercept != NULL) && (unint_rc == SHADOWHOOK_ERRNO_OK);
    result->stage6_interceptor_mechanism_pass = s6;
    if (s6) result->total_passed++;

    // =========================================================================
    // Stage 7: JNI Registration & Error Mapping / Giai đoạn 7: Đăng ký JNI & Bảng lỗi
    // =========================================================================
    const char* err0 = shadowhook_to_errmsg(SHADOWHOOK_ERRNO_OK);
    const char* err6 = shadowhook_to_errmsg(SHADOWHOOK_ERRNO_MPROTECT);
    const char* err10 = shadowhook_to_errmsg(SHADOWHOOK_ERRNO_INVALID_PARAM);
    bool errs_ok = (err0 && strcmp(err0, "OK") == 0) &&
                   (err6 && strstr(err6, "mprotect") != NULL) &&
                   (err10 && strstr(err10, "Invalid") != NULL);
    bool s7 = errs_ok && (shadowhook_get_errno() == SHADOWHOOK_ERRNO_OK);
    result->stage7_jni_and_error_mapping_pass = s7;
    if (s7) result->total_passed++;

    return (result->total_passed == result->total_tests) ? 0 : -1;
}
