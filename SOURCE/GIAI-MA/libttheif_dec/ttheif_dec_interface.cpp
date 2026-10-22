/**
 * @file ttheif_dec_interface.cpp
 * @brief ByteDance HEIF/VVIF Decoder 7-Stage Closed-Loop Self-Test Implementation
 *        Triển khai bộ kiểm thử khép kín 7 giai đoạn cho bộ giải mã HEIF/VVIF
 *
 * Cleanroom verification test suite reconstructed from ByteDance libttheif_dec.so.
 * Bộ kiểm thử xác minh phòng sạch tái cấu trúc từ libttheif_dec.so của ByteDance.
 */

#include "ttheif_dec_interface.h"
#include "ttheif_types.h"
#include "ttheif_isobmff.h"
#include "ttheif_color.h"
#include "ttheif_exif.h"
#include "ttheif_core.h"
#include "ttheif_anim.h"
#include "ttheif_vvif.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ttheif_run_self_test(ttheif_test_result_t* result) {
    if (!result) return -1;
    memset(result, 0, sizeof(ttheif_test_result_t));
    result->total_tests = 7;

    // =========================================================================
    // Stage 1: Version and File Type Identification / Giai đoạn 1: Phiên bản & Kiểu tệp
    // =========================================================================
    const char* ver = heif_get_version();
    uint8_t mock_heic[16] = {
        0x00, 0x00, 0x00, 0x10, 'f', 't', 'y', 'p',
        'h', 'e', 'i', 'c', 0x00, 0x00, 0x00, 0x00
    };
    uint8_t mock_vvif[16] = {
        0x00, 0x00, 0x00, 0x10, 'f', 't', 'y', 'p',
        'v', 'v', 'i', 'f', 0x00, 0x00, 0x00, 0x00
    };
    int t1 = heif_judge_file_type(mock_heic, sizeof(mock_heic));
    int t2 = vvif_judge_file_type(mock_vvif, sizeof(mock_vvif));

    bool s1 = (ver != NULL) && (strstr(ver, "1.2.0") != NULL) &&
              (t1 == HEIF_TYPE_HEIC) && (t2 == HEIF_TYPE_VVIF);
    result->stage1_version_and_type_pass = s1;
    if (s1) result->total_passed++;

    // =========================================================================
    // Stage 2: ISOBMFF Box Parser / Giai đoạn 2: Bộ phân giải hộp ISOBMFF
    // =========================================================================
    // Synthetic ISOBMFF file with ftyp + meta + pitm
    uint8_t mock_isobmff[48] = {
        0x00, 0x00, 0x00, 0x10, 'f', 't', 'y', 'p', 'h', 'e', 'i', 'c', 0, 0, 0, 0,
        0x00, 0x00, 0x00, 0x20, 'm', 'e', 't', 'a', 0, 0, 0, 0, // meta FullBox
        0x00, 0x00, 0x00, 0x0e, 'p', 'i', 't', 'm', 0, 0, 0, 0, 0x00, 0x01, // pitm item_id=1
        0x00, 0x00, 0x00, 0x00, 0, 0
    };
    isobmff_parser_ctx_t ctx;
    int init_rc = isobmff_parser_init(&ctx, mock_isobmff, sizeof(mock_isobmff));
    int parse_rc = isobmff_parse_container(&ctx);
    bool s2 = (init_rc == 0) && (parse_rc == 0) && (ctx.major_brand == BRAND_HEIC) &&
              (ctx.primary_item_id == 1);
    result->stage2_isobmff_box_parsing_pass = s2;
    if (s2) result->total_passed++;

    // =========================================================================
    // Stage 3: YUV to RGB Color Space Engine / Giai đoạn 3: Động cơ chuyển màu YUV
    // =========================================================================
    uint8_t y_data[4] = { 235, 235, 235, 235 }; // White Y in TV range
    uint8_t u_data[1] = { 128 };
    uint8_t v_data[1] = { 128 };
    uint8_t rgba_out[16] = {0};
    uint16_t rgb565_out[4] = {0};

    ttheif_yuv420p_to_rgba(y_data, u_data, v_data, 2, 1, 2, 2, rgba_out, 8);
    ttheif_yuv420p_to_rgb565(y_data, u_data, v_data, 2, 1, 2, 2, rgb565_out, 2);

    // R, G, B should be near 255 (white)
    bool s3 = (rgba_out[0] >= 250) && (rgba_out[1] >= 250) && (rgba_out[2] >= 250) &&
              (rgba_out[3] == 255) && (rgb565_out[0] != 0);
    result->stage3_yuv_color_conversion_pass = s3;
    if (s3) result->total_passed++;

    // =========================================================================
    // Stage 4: EXIF Orientation Metadata / Giai đoạn 4: Hướng xoay EXIF
    // =========================================================================
    // Synthetic TIFF EXIF block with Orientation tag (0x0112) = 6 (Rotate 90 deg CW)
    uint8_t mock_exif[32] = {
        'E', 'x', 'i', 'f', 0x00, 0x00,
        'I', 'I', 42, 0, 8, 0, 0, 0,      // TIFF Header Little Endian, IFD0 offset 8
        1, 0,                             // 1 entry
        0x12, 0x01, 3, 0, 1, 0, 0, 0, 6, 0, 0, 0 // Tag 0x0112 (Orientation), type SHORT, count 1, value 6
    };
    int orientation = heif_get_orientation_from_exif(mock_exif, sizeof(mock_exif));
    bool s4 = (orientation == 6);
    result->stage4_exif_orientation_pass = s4;
    if (s4) result->total_passed++;

    // =========================================================================
    // Stage 5: Static HEIF Image Decoding / Giai đoạn 5: Giải mã ảnh tĩnh HEIF
    // =========================================================================
    heif_output_stream_t* rgba_stream = NULL;
    int dec_rgba_rc = heif_decode_to_rgba(mock_heic, sizeof(mock_heic), &rgba_stream);
    bool s5_rgba = (dec_rgba_rc == HEIF_DEC_OK) && (rgba_stream != NULL) &&
                   (rgba_stream->format == HEIF_COLOR_RGBA8888);

    heif_output_stream_t* rgb_stream = NULL;
    int dec_rgb_rc = heif_decode_to_rgb(mock_heic, sizeof(mock_heic), &rgb_stream);
    bool s5_rgb = (dec_rgb_rc == HEIF_DEC_OK) && (rgb_stream != NULL);

    heif_output_stream_t* thumb_stream = NULL;
    int dec_thumb_rc = heif_decode_thumb_to_rgba(mock_heic, sizeof(mock_heic), &thumb_stream);
    bool s5_thumb = (dec_thumb_rc == HEIF_DEC_OK) && (thumb_stream != NULL);

    heif_release_output_stream(rgba_stream);
    heif_release_output_stream(rgb_stream);
    heif_release_output_stream(thumb_stream);

    bool s5 = s5_rgba && s5_rgb && s5_thumb;
    result->stage5_static_heif_decoding_pass = s5;
    if (s5) result->total_passed++;

    // =========================================================================
    // Stage 6: Animated HEIF Sequence / Giai đoạn 6: Chuỗi ảnh động HEIF
    // =========================================================================
    void* anim_dec = heif_anim_decoder_init();
    heif_anim_context_t* anim_ctx = NULL;
    int ctx_rc = heif_anim_heif_ctx_init(&anim_ctx, mock_heic, sizeof(mock_heic));
    int f0 = heif_anim_get_current_frame_index(anim_ctx);
    heif_anim_decode_one_frame(anim_ctx);
    int f1 = heif_anim_get_current_frame_index(anim_ctx);

    heif_output_stream_t* anim_stream = NULL;
    int anim_dec_rc = heif_anim_decode_to_rgba(anim_ctx, &anim_stream);

    heif_release_output_stream(anim_stream);
    heif_anim_heif_ctx_release(anim_ctx);
    heif_anim_decoder_close(anim_dec);

    bool s6 = (anim_dec != NULL) && (ctx_rc == HEIF_DEC_OK) &&
              (f0 == 0) && (f1 == 1) && (anim_dec_rc == HEIF_DEC_OK);
    result->stage6_animated_heif_sequence_pass = s6;
    if (s6) result->total_passed++;

    // =========================================================================
    // Stage 7: VVIF Decoding and VVC Container Muxing / Giai đoạn 7: Giải mã & Mux VVIF
    // =========================================================================
    uint8_t mock_vvc_nal[32] = { 0x00, 0x00, 0x00, 0x01, 0x40, 0x01, 0x0C };
    uint8_t* muxed_vvif = NULL;
    size_t muxed_len = 0;
    int mux_rc = mux_vvc_to_vvif(mock_vvc_nal, sizeof(mock_vvc_nal), 1920, 1080, &muxed_vvif, &muxed_len);

    heif_output_stream_t* vvif_rgba = NULL;
    int vvif_dec_rc = vvif_decode_to_rgba(mock_vvif, sizeof(mock_vvif), &vvif_rgba);

    bool s7 = (mux_rc == HEIF_DEC_OK) && (muxed_vvif != NULL) && (muxed_len > 0) &&
              (vvif_dec_rc == HEIF_DEC_OK) && (vvif_rgba != NULL);

    if (muxed_vvif) free(muxed_vvif);
    heif_release_output_stream(vvif_rgba);

    result->stage7_vvif_vvc_decoding_and_mux_pass = s7;
    if (s7) result->total_passed++;

    return (result->total_passed == result->total_tests) ? 0 : -1;
}
