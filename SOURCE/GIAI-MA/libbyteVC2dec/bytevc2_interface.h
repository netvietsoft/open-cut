/**
 * @file bytevc2_interface.h
 * @brief Public Interface and Self-Test Suite for ByteDance ByteVC2 Decoder
 *        Giao diện công khai và bộ tự kiểm thử cho bộ giải mã ByteDance ByteVC2
 *
 * Exposes all 29 native C API exports and closed-loop validation routines.
 * Cung cấp toàn bộ 29 hàm C xuất khẩu gốc và các quy trình tự kiểm chứng khép kín.
 */

#ifndef BYTEVC2_INTERFACE_H
#define BYTEVC2_INTERFACE_H

#include "bytevc2_types.h"
#include "bytevc2_cpu.h"
#include "bytevc2_param.h"
#include "bytevc2_packet.h"
#include "bytevc2_frame.h"
#include "bytevc2_dpb.h"
#include "bytevc2_hls.h"
#include "bytevc2_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ByteVC2TestResult
 * @brief Results of the 7-stage closed-loop self-test suite
 *        Kết quả bộ tự kiểm thử khép kín 7 giai đoạn
 */
typedef struct ByteVC2TestResult {
    bool stage1_version_parity;        ///< Stage 1: Version constant "0.8.1.3" / Phiên bản
    bool stage2_cpu_simd_caps;         ///< Stage 2: CPU feature detection / Tính năng SIMD CPU
    bool stage3_param_layout_abi;      ///< Stage 3: Param 44-byte layout & keys / Bố cục tham số 44-byte
    bool stage4_packet_layout_abi;     ///< Stage 4: Packet 56-byte layout & setters / Bố cục gói 56-byte
    bool stage5_frame_planar_layout;   ///< Stage 5: Frame 144-byte & 224-byte info / Bố cục khung hình 144-byte
    bool stage6_access_unit_parser;    ///< Stage 6: NAL & Access Unit parser / Phân giải đơn vị truy cập AU
    bool stage7_pipeline_roundtrip;    ///< Stage 7: Full decode pipeline roundtrip / Toàn trình đường ống giải mã
    int32_t passed_count;              ///< Total tests passed / Tổng số kiểm tra đạt
    int32_t total_count;               ///< Total tests run (7) / Tổng số kiểm tra thực hiện
} ByteVC2TestResult;

/**
 * @brief Execute comprehensive 7-stage closed-loop verification test suite
 *        Thực thi bộ tự kiểm thử khép kín toàn diện 7 giai đoạn
 * @return Test results structure / Cấu trúc kết quả kiểm tra
 */
ByteVC2TestResult bytevc2_run_self_test(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_INTERFACE_H
