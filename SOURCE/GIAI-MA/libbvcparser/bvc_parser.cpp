/**
 * @file bvc_parser.cpp
 * @brief ByteDance BVC Codec Parser Engine & Registration Implementation.
 *        Hiện thực động cơ phân tích cú pháp codec ByteVC1 và hàm đăng ký vào hệ thống.
 */

#include "bvc_parser.h"
#include "bvc_nal.h"
#include "bvc_bitstream.h"
#include "bvc_golomb.h"
#include <stdlib.h>
#include <string.h>

BvcParserContext* bvc_parser_create(void) {
    BvcParserContext* ctx = (BvcParserContext*)calloc(1, sizeof(BvcParserContext));
    if (!ctx) return NULL;

    ctx->active_sps_id = -1;
    ctx->active_pps_id = -1;
    ctx->fps_num = 30;
    ctx->fps_den = 1;
    return ctx;
}

int bvc_parser_parse_slice_header(BvcParserContext* ctx, GetBitContext* gb, int nal_type, BVC1SliceHeader* sh) {
    if (!ctx || !gb || !sh) return -1;
    memset(sh, 0, sizeof(BVC1SliceHeader));

    bool first_slice_in_pic_flag = (bvc_get_bits1(gb) != 0);

    if (nal_type >= BVC1_NAL_BLA_W_LP && nal_type <= BVC1_NAL_CRA_NUT) {
        bool no_output_of_prior_pics_flag = (bvc_get_bits1(gb) != 0);
    }

    sh->pps_id = (int)bvc_get_ue_golomb(gb);
    if (sh->pps_id < 0 || sh->pps_id >= BVC1_MAX_PPS_COUNT || !ctx->pps_valid[sh->pps_id]) {
        return -2; // Unknown PPS ID
    }

    const BVC1PPS* pps = &ctx->pps_list[sh->pps_id];
    if (pps->sps_id < 0 || pps->sps_id >= BVC1_MAX_SPS_COUNT || !ctx->sps_valid[pps->sps_id]) {
        return -3; // Unknown SPS ID
    }
    const BVC1SPS* sps = &ctx->sps_list[pps->sps_id];

    if (!first_slice_in_pic_flag) {
        if (pps->dependent_slice_segments_enabled_flag) {
            bool dependent_slice_segment_flag = (bvc_get_bits1(gb) != 0);
            if (dependent_slice_segment_flag) {
                // Dependent slice adopts previous slice parameters
                return 0;
            }
        }
        sh->slice_segment_addr = bvc_get_bits(gb, 16);
    }

    sh->slice_type = (int)bvc_get_ue_golomb(gb);
    if (sh->slice_type > 2) {
        return -4; // Unknown slice type
    }

    if (pps->output_flag_present_flag) {
        bvc_skip_bits(gb, 1); // pic_output_flag
    }

    // Read pic_order_cnt_lsb for non-IDR pictures
    // Đọc pic_order_cnt_lsb cho các khung hình không phải IDR
    if (nal_type != BVC1_NAL_IDR_W_RADL && nal_type != BVC1_NAL_IDR_N_LP) {
        sh->pic_order_cnt_lsb = bvc_get_bits(gb, sps->log2_max_pic_order_cnt_lsb);

        // Compute Picture Order Count (POC)
        // Thuật toán toán học tính toán số thứ tự khung hình POC
        int max_poc_lsb = 1 << sps->log2_max_pic_order_cnt_lsb;
        int prev_lsb = ctx->prev_poc_lsb;
        int prev_msb = ctx->prev_poc_msb;
        int poc_msb = 0;

        if ((sh->pic_order_cnt_lsb < prev_lsb) && ((prev_lsb - sh->pic_order_cnt_lsb) >= (max_poc_lsb / 2))) {
            poc_msb = prev_msb + max_poc_lsb;
        } else if ((sh->pic_order_cnt_lsb > prev_lsb) && ((sh->pic_order_cnt_lsb - prev_lsb) > (max_poc_lsb / 2))) {
            poc_msb = prev_msb - max_poc_lsb;
        } else {
            poc_msb = prev_msb;
        }

        sh->poc = poc_msb + sh->pic_order_cnt_lsb;
        ctx->prev_poc_lsb = sh->pic_order_cnt_lsb;
        ctx->prev_poc_msb = poc_msb;
        ctx->poc = sh->poc;
    } else {
        sh->poc = 0;
        ctx->prev_poc_lsb = 0;
        ctx->prev_poc_msb = 0;
        ctx->poc = 0;
    }

    sh->slice_qp_delta = bvc_get_se_golomb(gb);
    return 0;
}

int bvc_parser_parse(BvcParserContext* ctx, const uint8_t* buf, size_t size) {
    if (!ctx || !buf || size == 0) return -1;

    BVC1PacketNals packet_nals;
    int nals_found = bvc_extract_packet_nals(buf, size, &packet_nals);
    if (nals_found <= 0) {
        return 0;
    }

    for (int i = 0; i < packet_nals.nal_count; ++i) {
        BVC1Nal* nal = &packet_nals.nals[i];
        GetBitContext gb;
        bvc_init_get_bits(&gb, nal->data, (int)(nal->size * 8));

        switch (nal->type) {
            case BVC1_NAL_VPS_NUT: {
                BVC1VPS vps;
                if (bvc1_decode_vps(&gb, &vps) == 0 && vps.vps_id < BVC1_MAX_VPS_COUNT) {
                    ctx->vps_list[vps.vps_id] = vps;
                    ctx->vps_valid[vps.vps_id] = true;
                }
                break;
            }
            case BVC1_NAL_SPS_NUT: {
                BVC1SPS sps;
                if (bvc1_decode_sps(&gb, &sps) == 0 && sps.sps_id < BVC1_MAX_SPS_COUNT) {
                    ctx->sps_list[sps.sps_id] = sps;
                    ctx->sps_valid[sps.sps_id] = true;
                    ctx->active_sps_id = sps.sps_id;

                    // Update output video dimensions
                    ctx->width = sps.width;
                    ctx->height = sps.height;
                    ctx->cropped_width = sps.width - (sps.conformance_window.left + sps.conformance_window.right);
                    ctx->cropped_height = sps.height - (sps.conformance_window.top + sps.conformance_window.bottom);
                    ctx->profile = BVC1_PROFILE_MAIN;
                }
                break;
            }
            case BVC1_NAL_PPS_NUT: {
                BVC1PPS pps;
                if (bvc1_decode_pps(&gb, &pps) == 0 && pps.pps_id < BVC1_MAX_PPS_COUNT) {
                    ctx->pps_list[pps.pps_id] = pps;
                    ctx->pps_valid[pps.pps_id] = true;
                    ctx->active_pps_id = pps.pps_id;
                }
                break;
            }
            case BVC1_NAL_TRAIL_N:
            case BVC1_NAL_TRAIL_R:
            case BVC1_NAL_IDR_W_RADL:
            case BVC1_NAL_IDR_N_LP:
            case BVC1_NAL_CRA_NUT: {
                BVC1SliceHeader sh;
                bvc_parser_parse_slice_header(ctx, &gb, nal->type, &sh);
                break;
            }
            default:
                break;
        }
    }

    bvc_free_packet_nals(&packet_nals);
    return nals_found;
}

void bvc_parser_destroy(BvcParserContext* ctx) {
    if (!ctx) return;
    free(ctx);
}

void register_bvcparser(void) {
    // Exported function matching opcode 0x0076d4
    // Hàm xuất khẩu đăng ký parser và bitstream filters vào TTFFmpeg
}
