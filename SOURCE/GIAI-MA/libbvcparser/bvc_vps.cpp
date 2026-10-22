/**
 * @file bvc_vps.cpp
 * @brief ByteDance BVC Video Parameter Set (VPS) Decoding Implementation.
 *        Hiện thực giải mã cấu trúc Video Parameter Set (VPS) của ByteVC1.
 */

#include "bvc_vps.h"
#include "bvc_golomb.h"
#include "bvc_bitstream.h"
#include <string.h>

static int decode_profile_tier_level(GetBitContext* gb, int max_sub_layers, BVC1PTL* ptl) {
    ptl->general_profile_space = bvc_get_bits(gb, 2);
    ptl->general_tier_flag = (bvc_get_bits1(gb) != 0);
    ptl->general_profile_idc = bvc_get_bits(gb, 5);
    ptl->general_profile_compatibility_flags = bvc_get_bits(gb, 32);

    // Skip general constraint flags (48 bits)
    bvc_skip_bits(gb, 32);
    bvc_skip_bits(gb, 16);

    ptl->general_level_idc = bvc_get_bits(gb, 8);

    bool sub_layer_profile_present[BVC1_MAX_SUB_LAYERS];
    bool sub_layer_level_present[BVC1_MAX_SUB_LAYERS];

    for (int i = 0; i < max_sub_layers - 1; ++i) {
        sub_layer_profile_present[i] = (bvc_get_bits1(gb) != 0);
        sub_layer_level_present[i] = (bvc_get_bits1(gb) != 0);
    }

    if (max_sub_layers > 1) {
        for (int i = max_sub_layers - 1; i < 8; ++i) {
            bvc_skip_bits(gb, 2); // Reserved 2 bits
        }
    }

    for (int i = 0; i < max_sub_layers - 1; ++i) {
        if (sub_layer_profile_present[i]) {
            bvc_skip_bits(gb, 32); // sublayer profile space, tier, idc, compat
            bvc_skip_bits(gb, 32);
            bvc_skip_bits(gb, 24);
        }
        if (sub_layer_level_present[i]) {
            bvc_skip_bits(gb, 8); // sublayer level idc
        }
    }
    return 0;
}

int bvc1_decode_vps(GetBitContext* gb, BVC1VPS* vps) {
    if (!gb || !vps) return -1;
    memset(vps, 0, sizeof(BVC1VPS));

    vps->vps_id = bvc_get_bits(gb, 4);
    if (vps->vps_id >= BVC1_MAX_VPS_COUNT) {
        return -2; // BVC1VPS id out of range
    }

    int reserved_three_2bits = bvc_get_bits(gb, 2);
    if (reserved_three_2bits != 3) {
        // Warning: vps_reserved_three_2bits is not three
    }

    vps->vps_max_layers = bvc_get_bits(gb, 6) + 1;
    vps->vps_max_sub_layers = bvc_get_bits(gb, 3) + 1;
    if (vps->vps_max_sub_layers > BVC1_MAX_SUB_LAYERS) {
        return -3; // BVC1VpsMaxSubLayers out of range
    }

    vps->vps_temporal_id_nesting_flag = (bvc_get_bits1(gb) != 0);
    int reserved_ffff = bvc_get_bits(gb, 16);
    if (reserved_ffff != 0xFFFF) {
        // Warning: vps_reserved_ffff_16bits is not 0xffff
    }

    // Decode Profile Tier Level
    decode_profile_tier_level(gb, vps->vps_max_sub_layers, &vps->ptl);

    bool sub_layer_ordering_info_present = (bvc_get_bits1(gb) != 0);
    int start_i = sub_layer_ordering_info_present ? 0 : (vps->vps_max_sub_layers - 1);

    for (int i = start_i; i < vps->vps_max_sub_layers; ++i) {
        vps->vps_max_dec_pic_buffering[i] = (int)bvc_get_ue_golomb(gb) + 1;
        vps->vps_max_num_reorder_pics[i] = (int)bvc_get_ue_golomb(gb);
        vps->vps_max_latency_increase[i] = (int)bvc_get_ue_golomb(gb);
    }

    return 0;
}
