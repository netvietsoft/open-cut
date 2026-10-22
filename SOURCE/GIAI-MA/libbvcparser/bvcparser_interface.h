/**
 * @file bvcparser_interface.h
 * @brief ByteDance BVC Bitstream Parser Standalone Self-Test Suite Header.
 *        Giao diện và bộ tự kiểm thử 7 giai đoạn độc lập cho libbvcparser.so.
 */

#ifndef BYTEDANCE_BVCPARSER_INTERFACE_H
#define BYTEDANCE_BVCPARSER_INTERFACE_H

#include "bvc_types.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int  total_stages;
    int  passed_stages;
    int  failed_stages;
    bool golomb_math_passed;
    bool start_code_detection_passed;
    bool emulation_prevention_passed;
    bool vps_decoding_passed;
    bool sps_decoding_passed;
    bool pps_decoding_passed;
    bool bsf_transmux_passed;
} BvcSelfTestResult;

/**
 * @brief Run full 7-stage closed-loop verification test suite.
 *        Thực thi toàn diện bộ kiểm thử khép kín 7 giai đoạn của hệ thống BVC Parser.
 */
BvcSelfTestResult bvc_run_self_test(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVCPARSER_INTERFACE_H
