/**
 * @file bvc_pps.cpp
 * @brief ByteDance BVC Picture Parameter Set (PPS) Decoding Implementation.
 *        Hiện thực giải mã cấu trúc Picture Parameter Set (PPS) của ByteVC1.
 */

#include "bvc_pps.h"
#include "bvc_golomb.h"
#include "bvc_bitstream.h"
#include <string.h>

int bvc1_decode_pps(GetBitContext* gb, BVC1PPS* pps) {
    if (!gb || !pps) return -1;
    memset(pps, 0, sizeof(BVC1PPS));

    pps->pps_id = (int)bvc_get_ue_golomb(gb);
    if (pps->pps_id >= BVC1_MAX_PPS_COUNT) {
        return -2; // BVC1PPS id out of range
    }

    pps->sps_id = (int)bvc_get_ue_golomb(gb);
    if (pps->sps_id >= BVC1_MAX_SPS_COUNT) {
        return -3; // BVC1SPS does not exist
    }

    pps->dependent_slice_segments_enabled_flag = (bvc_get_bits1(gb) != 0);
    pps->output_flag_present_flag = (bvc_get_bits1(gb) != 0);
    pps->num_extra_slice_header_bits = bvc_get_bits(gb, 3);
    pps->sign_data_hiding_enabled_flag = (bvc_get_bits1(gb) != 0);
    pps->cabac_init_present_flag = (bvc_get_bits1(gb) != 0);

    pps->num_ref_idx_l0_default_active_minus1 = (int)bvc_get_ue_golomb(gb);
    pps->num_ref_idx_l1_default_active_minus1 = (int)bvc_get_ue_golomb(gb);
    pps->init_qp_minus26 = bvc_get_se_golomb(gb);

    pps->constrained_intra_pred_flag = (bvc_get_bits1(gb) != 0);
    pps->transform_skip_enabled_flag = (bvc_get_bits1(gb) != 0);

    pps->cu_qp_delta_enabled_flag = (bvc_get_bits1(gb) != 0);
    if (pps->cu_qp_delta_enabled_flag) {
        pps->diff_cu_qp_delta_depth = (int)bvc_get_ue_golomb(gb);
    }

    pps->cb_qp_offset = bvc_get_se_golomb(gb);
    pps->cr_qp_offset = bvc_get_se_golomb(gb);
    pps->slice_chroma_qp_offsets_present_flag = (bvc_get_bits1(gb) != 0);

    pps->weighted_pred_flag = (bvc_get_bits1(gb) != 0);
    pps->weighted_bipred_flag = (bvc_get_bits1(gb) != 0);
    pps->transquant_bypass_enabled_flag = (bvc_get_bits1(gb) != 0);

    pps->tiles_enabled_flag = (bvc_get_bits1(gb) != 0);
    pps->entropy_coding_sync_enabled_flag = (bvc_get_bits1(gb) != 0);

    if (pps->tiles_enabled_flag) {
        pps->num_tile_columns = (int)bvc_get_ue_golomb(gb) + 1;
        pps->num_tile_rows = (int)bvc_get_ue_golomb(gb) + 1;
        pps->uniform_spacing_flag = (bvc_get_bits1(gb) != 0);

        if (!pps->uniform_spacing_flag) {
            for (int i = 0; i < pps->num_tile_columns - 1; ++i) {
                bvc_get_ue_golomb(gb); // column_width_minus1
            }
            for (int i = 0; i < pps->num_tile_rows - 1; ++i) {
                bvc_get_ue_golomb(gb); // row_height_minus1
            }
        }
        pps->loop_filter_across_tiles_enabled_flag = (bvc_get_bits1(gb) != 0);
    }

    pps->pps_loop_filter_across_slices_enabled_flag = (bvc_get_bits1(gb) != 0);

    pps->deblocking_filter_control_present_flag = (bvc_get_bits1(gb) != 0);
    if (pps->deblocking_filter_control_present_flag) {
        pps->deblocking_filter_override_enabled_flag = (bvc_get_bits1(gb) != 0);
        pps->pps_deblocking_filter_disabled_flag = (bvc_get_bits1(gb) != 0);
        if (!pps->pps_deblocking_filter_disabled_flag) {
            pps->pps_beta_offset_div2 = bvc_get_se_golomb(gb);
            pps->pps_tc_offset_div2 = bvc_get_se_golomb(gb);
        }
    }

    // Scaling list in PPS
    bool pps_scaling_list_data_present_flag = (bvc_get_bits1(gb) != 0);
    if (pps_scaling_list_data_present_flag) {
        // Skip PPS scaling list data
    }

    bool lists_modification_present_flag = (bvc_get_bits1(gb) != 0);
    pps->log2_parallel_merge_level = (int)bvc_get_ue_golomb(gb) + 2;

    return 0;
}
