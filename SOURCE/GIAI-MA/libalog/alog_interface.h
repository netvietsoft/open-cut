/**
 * @file alog_interface.h
 * @brief ByteDance ALog Standalone Self-Test Suite & Interface Header.
 *        Giao diện và bộ tự kiểm thử 7 giai đoạn độc lập cho libalog.so.
 */

#ifndef BYTEDANCE_ALOG_INTERFACE_H
#define BYTEDANCE_ALOG_INTERFACE_H

#include "alog_types.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int total_stages;
    int passed_stages;
    int failed_stages;
    bool buffer_test_passed;
    bool compressor_test_passed;
    bool encryptor_test_passed;
    bool file_manager_test_passed;
    bool async_worker_test_passed;
    bool jni_table_test_passed;
    bool e2e_pipeline_test_passed;
} AlogSelfTestResult;

/**
 * @brief Run full 7-stage closed-loop verification test suite.
 *        Thực thi toàn diện bộ kiểm thử khép kín 7 giai đoạn của hệ thống ALog.
 */
AlogSelfTestResult alog_run_self_test(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_INTERFACE_H
