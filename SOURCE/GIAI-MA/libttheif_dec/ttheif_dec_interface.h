/**
 * @file ttheif_dec_interface.h
 * @brief ByteDance HEIF/VVIF Decoder 7-Stage Closed-Loop Self-Test Interface
 *        Giao diện tự kiểm thử khép kín 7 giai đoạn cho bộ giải mã HEIF/VVIF
 *
 * Cleanroom verification interface reconstructed from ByteDance libttheif_dec.so.
 * Giao diện xác minh phòng sạch tái cấu trúc từ libttheif_dec.so của ByteDance.
 */

#ifndef TTHEIF_DEC_INTERFACE_H
#define TTHEIF_DEC_INTERFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ttheif_test_result_t
 * @brief Result metrics for 7-stage closed-loop verification
 *        Chỉ số kết quả xác minh khép kín 7 giai đoạn
 */
typedef struct {
    bool stage1_version_and_type_pass;
    bool stage2_isobmff_box_parsing_pass;
    bool stage3_yuv_color_conversion_pass;
    bool stage4_exif_orientation_pass;
    bool stage5_static_heif_decoding_pass;
    bool stage6_animated_heif_sequence_pass;
    bool stage7_vvif_vvc_decoding_and_mux_pass;
    int total_passed;
    int total_tests;
} ttheif_test_result_t;

/**
 * @brief Execute 7-stage closed-loop verification test suite
 *        Thực thi bộ kiểm thử khép kín 7 giai đoạn
 * @param result Pointer to output result structure / Con trỏ cấu trúc kết quả đầu ra
 * @return 0 if all stages passed, negative on error / 0 nếu tất cả giai đoạn thành công
 */
int ttheif_run_self_test(ttheif_test_result_t* result);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_DEC_INTERFACE_H