/**
 * @file bytehook_interface.h
 * @brief Public Interface and Self-Test Suite for ByteDance ByteHook
 *        Giao diện công khai và bộ tự kiểm thử cho ByteDance ByteHook
 *
 * Exposes all 20 native C API exports and closed-loop validation routines.
 * Cung cấp toàn bộ 20 hàm C xuất khẩu gốc và các quy trình tự kiểm chứng khép kín.
 */

#ifndef BYTEHOOK_INTERFACE_H
#define BYTEHOOK_INTERFACE_H

#include "bh_types.h"
#include "bh_elf.h"
#include "bh_trampoline.h"
#include "bh_hub.h"
#include "bh_dl_monitor.h"
#include "bh_core.h"
#include "bh_jni.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ByteHookTestResult
 * @brief Results of the 7-stage closed-loop self-test suite
 *        Kết quả bộ tự kiểm thử khép kín 7 giai đoạn
 */
typedef struct ByteHookTestResult {
    bool stage1_version_parity;        ///< Stage 1: Version string parity / Kiểm tra phiên bản
    bool stage2_mode_lifecycle;        ///< Stage 2: Mode init and config / Khởi tạo chế độ vận hành
    bool stage3_trampoline_opcodes;    ///< Stage 3: AArch64 trampoline opcodes / Lệnh mã máy AArch64
    bool stage4_got_protection_swap;   ///< Stage 4: GOT pointer swap & mprotect / Đổi con trỏ GOT an toàn
    bool stage5_tls_call_stack;        ///< Stage 5: TLS Call Stack & get_prev_func / Ngăn xếp TLS gọi hàm
    bool stage6_dlopen_monitor;        ///< Stage 6: Dynamic Linker monitor / Giám sát nạp thư viện động
    bool stage7_hook_audit_roundtrip;  ///< Stage 7: Full hook & unhook audit / Toàn trình hook và kiểm toán
    int32_t passed_count;              ///< Total tests passed / Tổng số kiểm tra đạt
    int32_t total_count;               ///< Total tests run (7) / Tổng số kiểm tra thực hiện
} ByteHookTestResult;

/**
 * @brief Execute comprehensive 7-stage closed-loop verification test suite
 *        Thực thi bộ tự kiểm thử khép kín toàn diện 7 giai đoạn
 * @return Test results structure / Cấu trúc kết quả kiểm tra
 */
ByteHookTestResult bytehook_run_self_test(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEHOOK_INTERFACE_H
