/**
 * @file shadowhook_interface.h
 * @brief ShadowHook 7-Stage Closed-Loop Self-Test Interface
 *        Giao diện kiểm thử khép kín 7 giai đoạn cho ShadowHook
 *
 * Cleanroom verification interface reconstructed from ByteDance libshadowhook.so.
 * Giao diện xác minh phòng sạch tái cấu trúc từ libshadowhook.so của ByteDance.
 */

#ifndef SHADOWHOOK_INTERFACE_H
#define SHADOWHOOK_INTERFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct shadowhook_test_result_t
 * @brief Result metrics for 7-stage closed-loop verification
 *        Chỉ số kết quả xác minh khép kín 7 giai đoạn
 */
typedef struct {
    bool stage1_version_and_init_pass;
    bool stage2_instruction_relocation_pass;
    bool stage3_tls_hub_stack_pass;
    bool stage4_linker_symbol_resolver_pass;
    bool stage5_function_hook_unhook_pass;
    bool stage6_interceptor_mechanism_pass;
    bool stage7_jni_and_error_mapping_pass;
    int total_passed;
    int total_tests;
} shadowhook_test_result_t;

/**
 * @brief Execute 7-stage closed-loop verification test suite
 *        Thực thi bộ kiểm thử khép kín 7 giai đoạn
 * @param result Pointer to output result structure / Con trỏ cấu trúc kết quả đầu ra
 * @return 0 if all stages passed, negative on error / 0 nếu tất cả giai đoạn thành công
 */
int shadowhook_run_self_test(shadowhook_test_result_t* result);

#ifdef __cplusplus
}
#endif

#endif // SHADOWHOOK_INTERFACE_H