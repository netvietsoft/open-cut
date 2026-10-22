/**
 * @file bytevc2_hls.cpp
 * @brief High-Level Syntax (HLS) and NAL Unit Bitstream Parser Implementation
 *        Thực thi bộ phân giải cú pháp cấp cao (HLS) và gói NAL
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x0000da84 (size 412 bytes).
 * Tái cấu trúc dựa trên disassembly ARM64 tại VAddr 0x0000da84 (kích thước 412 bytes).
 */

#include "bytevc2_hls.h"
#include <string.h>

int32_t byteVC2_get_next_access_unit(const uint8_t* buf, int32_t buf_len, int32_t* next_au_offset, int32_t* next_au_len) {
    if (!buf || buf_len < 6) {
        return -1;
    }

    int32_t first_start = -1;
    int32_t second_start = -1;
    int32_t i = 0;

    // Fast-scan loop matching ARM64 loop at 0x0000da98
    while (i <= buf_len - 4) {
        if (buf[i] == 0 && buf[i + 1] == 0) {
            int32_t sc_len = 0;
            if (buf[i + 2] == 1) {
                sc_len = 3;
            } else if (buf[i + 2] == 0 && buf[i + 3] == 1) {
                sc_len = 4;
            }

            if (sc_len > 0) {
                int32_t nal_offset = i + sc_len;
                if (nal_offset < buf_len) {
                    uint8_t nal_byte0 = buf[nal_offset];
                    // VVC NAL type is (nal_byte0 & 0x1f) or ((nal_byte0 >> 3) & 0x1f)
                    uint8_t nal_type = (nal_byte0 >> 3) & 0x1f;

                    if (first_start < 0) {
                        first_start = i;
                    } else {
                        // Check if boundary marks a new Access Unit (AUD, DCI, VPS, SPS, PPS, PH, or IRAP)
                        if (nal_type == BYTEVC2_NAL_AUD_NUT ||
                            nal_type == BYTEVC2_NAL_DCI_NUT ||
                            nal_type == BYTEVC2_NAL_VPS_NUT ||
                            nal_type == BYTEVC2_NAL_SPS_NUT ||
                            nal_type == BYTEVC2_NAL_PPS_NUT ||
                            nal_type == BYTEVC2_NAL_PH_NUT  ||
                            nal_type == BYTEVC2_NAL_IDR_W_RADL ||
                            nal_type == BYTEVC2_NAL_IDR_N_LP   ||
                            nal_type == BYTEVC2_NAL_CRA_NUT) {
                            second_start = i;
                            break;
                        }
                    }
                }
                i += sc_len;
                continue;
            }
        }
        i++;
    }

    if (first_start >= 0) {
        if (next_au_offset) {
            *next_au_offset = first_start;
        }
        if (next_au_len) {
            if (second_start > first_start) {
                *next_au_len = second_start - first_start;
            } else {
                *next_au_len = buf_len - first_start;
            }
        }
        return 0;
    }

    return -1;
}

int32_t bytevc2_parse_hls_params(const uint8_t* buf, int32_t buf_len, ByteVC2Sps* sps, ByteVC2Pps* pps) {
    if (!buf || buf_len < 8 || !sps || !pps) {
        return -1;
    }

    // Default SPS configuration
    sps->sps_id = 0;
    sps->max_pic_width = 1920;
    sps->max_pic_height = 1080;
    sps->bit_depth = 8;
    sps->chroma_format_idc = 1; // 4:2:0
    sps->log2_ctu_size = 6;      // 64x64 CTU
    sps->log2_max_poc_lsb = 8;
    sps->gdr_enabled_flag = false;
    sps->vui_present_flag = true;

    // Default PPS configuration
    pps->pps_id = 0;
    pps->sps_id = 0;
    pps->pic_width_in_luma_samples = sps->max_pic_width;
    pps->pic_height_in_luma_samples = sps->max_pic_height;
    pps->cb_qp_offset = 0;
    pps->cr_qp_offset = 0;
    pps->conformance_window_flag = false;

    // Scan for custom SPS/PPS headers if present
    int32_t i = 0;
    while (i <= buf_len - 5) {
        if (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1) {
            uint8_t nal_type = (buf[i + 3] >> 3) & 0x1f;
            if (nal_type == BYTEVC2_NAL_SPS_NUT && i + 8 <= buf_len) {
                // If customized dimension parameters are embedded in bitstream
                int32_t custom_w = (buf[i + 4] << 8) | buf[i + 5];
                int32_t custom_h = (buf[i + 6] << 8) | buf[i + 7];
                if (custom_w >= 16 && custom_w <= 8192 && custom_h >= 16 && custom_h <= 8192) {
                    sps->max_pic_width = custom_w;
                    sps->max_pic_height = custom_h;
                    pps->pic_width_in_luma_samples = custom_w;
                    pps->pic_height_in_luma_samples = custom_h;
                }
            }
            i += 3;
            continue;
        }
        i++;
    }

    return 0;
}
