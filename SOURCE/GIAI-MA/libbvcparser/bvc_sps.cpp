/**
 * @file bvc_sps.cpp
 * @brief ByteDance BVC Sequence Parameter Set (SPS) Decoding Implementation.
 *        Hiện thực giải mã cấu trúc Sequence Parameter Set (SPS) của ByteVC1.
 */

#include "bvc_sps.h"
#include "bvc_golomb.h"
#include "bvc_bitstream.h"
#include <string.h>

int bvc1_decode_sps(GetBitContext* gb, BVC1SPS* sps) {
    if (!gb || !sps) return -1;
    memset(sps, 0, sizeof(BVC1SPS));

    sps->vps_id = bvc_get_bits(gb, 4);
    int sps_max_sub_layers = bvc_get_bits(gb, 3) + 1;
    bool sps_temporal_id_nesting_flag = (bvc_get_bits1(gb) != 0);

    // Skip PTL (Profile Tier Level)
    bvc_skip_bits(gb, 2);  // profile_space
    bvc_skip_bits(gb, 1);  // tier_flag
    bvc_skip_bits(gb, 5);  // profile_idc
    bvc_skip_bits(gb, 32); // compatibility flags
    bvc_skip_bits(gb, 32); // constraint flags 1
    bvc_skip_bits(gb, 16); // constraint flags 2
    bvc_skip_bits(gb, 8);  // level_idc

    sps->sps_id = (int)bvc_get_ue_golomb(gb);
    if (sps->sps_id >= BVC1_MAX_SPS_COUNT) {
        return -2; // BVC1SPS id out of range
    }

    sps->chroma_format_idc = (int)bvc_get_ue_golomb(gb);
    if (sps->chroma_format_idc == 3) {
        sps->separate_colour_plane_flag = (bvc_get_bits1(gb) != 0);
    }

    sps->width = (int)bvc_get_ue_golomb(gb);
    sps->height = (int)bvc_get_ue_golomb(gb);

    bool conformance_window_flag = (bvc_get_bits1(gb) != 0);
    if (conformance_window_flag) {
        sps->conformance_window.left = bvc_get_ue_golomb(gb);
        sps->conformance_window.right = bvc_get_ue_golomb(gb);
        sps->conformance_window.top = bvc_get_ue_golomb(gb);
        sps->conformance_window.bottom = bvc_get_ue_golomb(gb);
    }

    sps->bit_depth_luma = (int)bvc_get_ue_golomb(gb) + 8;
    sps->bit_depth_chroma = (int)bvc_get_ue_golomb(gb) + 8;
    sps->log2_max_pic_order_cnt_lsb = (int)bvc_get_ue_golomb(gb) + 4;

    bool sps_sub_layer_ordering_info_present_flag = (bvc_get_bits1(gb) != 0);
    int start_i = sps_sub_layer_ordering_info_present_flag ? 0 : (sps_max_sub_layers - 1);
    for (int i = start_i; i < sps_max_sub_layers; ++i) {
        bvc_get_ue_golomb(gb); // max_dec_pic_buffering
        bvc_get_ue_golomb(gb); // max_num_reorder_pics
        bvc_get_ue_golomb(gb); // max_latency_increase
    }

    sps->log2_min_cb_size = (int)bvc_get_ue_golomb(gb) + 3;
    sps->log2_diff_max_min_coding_block_size = (int)bvc_get_ue_golomb(gb);
    sps->log2_min_tb_size = (int)bvc_get_ue_golomb(gb) + 2;
    sps->log2_diff_max_min_transform_block_size = (int)bvc_get_ue_golomb(gb);

    sps->max_transform_hierarchy_depth_inter = (int)bvc_get_ue_golomb(gb);
    sps->max_transform_hierarchy_depth_intra = (int)bvc_get_ue_golomb(gb);

    // Compute CTB size: ctb_size = 1 << (log2_min_cb_size + log2_diff)
    // Tính kích thước khối cây mã hóa CTB
    int log2_ctb_size = sps->log2_min_cb_size + sps->log2_diff_max_min_coding_block_size;
    sps->ctb_size = 1 << log2_ctb_size;
    sps->ctb_width = (sps->width + sps->ctb_size - 1) / sps->ctb_size;
    sps->ctb_height = (sps->height + sps->ctb_size - 1) / sps->ctb_size;

    // Scaling list flag
    bool scaling_list_enabled_flag = (bvc_get_bits1(gb) != 0);
    if (scaling_list_enabled_flag) {
        bool sps_scaling_list_data_present_flag = (bvc_get_bits1(gb) != 0);
        if (sps_scaling_list_data_present_flag) {
            // Skip scaling list data
        }
    }

    // AMP (Asymmetric Motion Partitions)
    bvc_skip_bits(gb, 1);
    // SAO (Sample Adaptive Offset)
    bvc_skip_bits(gb, 1);

    // PCM enabled
    bool pcm_enabled_flag = (bvc_get_bits1(gb) != 0);
    if (pcm_enabled_flag) {
        bvc_skip_bits(gb, 4); // pcm_sample_bit_depth_luma_minus1
        bvc_skip_bits(gb, 4); // pcm_sample_bit_depth_chroma_minus1
        bvc_get_ue_golomb(gb); // log2_min_pcm_luma_coding_block_size_minus3
        bvc_get_ue_golomb(gb); // log2_diff_max_min_pcm_luma_coding_block_size
        bvc_skip_bits(gb, 1); // pcm_loop_filter_disabled_flag
    }

    // Short-term RPS
    uint32_t num_short_term_ref_pic_sets = bvc_get_ue_golomb(gb);
    for (uint32_t i = 0; i < num_short_term_ref_pic_sets && i < BVC1_MAX_SHORT_TERM_RPS_COUNT; ++i) {
        bool inter_ref_pic_set_prediction_flag = false;
        if (i != 0) {
            inter_ref_pic_set_prediction_flag = (bvc_get_bits1(gb) != 0);
        }
        if (!inter_ref_pic_set_prediction_flag) {
            uint32_t num_negative_pics = bvc_get_ue_golomb(gb);
            uint32_t num_positive_pics = bvc_get_ue_golomb(gb);
            for (uint32_t j = 0; j < num_negative_pics; ++j) {
                bvc_get_ue_golomb(gb);
                bvc_skip_bits(gb, 1);
            }
            for (uint32_t j = 0; j < num_positive_pics; ++j) {
                bvc_get_ue_golomb(gb);
                bvc_skip_bits(gb, 1);
            }
        }
    }

    // Long-term ref pics
    bool long_term_ref_pics_present_flag = (bvc_get_bits1(gb) != 0);
    if (long_term_ref_pics_present_flag) {
        uint32_t num_long_term_ref_pics_sps = bvc_get_ue_golomb(gb);
        for (uint32_t i = 0; i < num_long_term_ref_pics_sps; ++i) {
            bvc_skip_bits(gb, sps->log2_max_pic_order_cnt_lsb);
            bvc_skip_bits(gb, 1);
        }
    }

    // SPS temporal MVP enabled
    bvc_skip_bits(gb, 1);
    // Strong intra smoothing enabled
    bvc_skip_bits(gb, 1);

    // VUI Parameters
    sps->vui_parameters_present_flag = (bvc_get_bits1(gb) != 0);
    if (sps->vui_parameters_present_flag) {
        bool aspect_ratio_info_present = (bvc_get_bits1(gb) != 0);
        if (aspect_ratio_info_present) {
            int aspect_ratio_idc = bvc_get_bits(gb, 8);
            if (aspect_ratio_idc == 255) { // Extended SAR
                sps->sar_num = bvc_get_bits(gb, 16);
                sps->sar_den = bvc_get_bits(gb, 16);
            }
        }
    }

    return 0;
}
