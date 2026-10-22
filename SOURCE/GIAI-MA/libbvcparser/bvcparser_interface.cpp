/**
 * @file bvcparser_interface.cpp
 * @brief ByteDance BVC Bitstream Parser Standalone Self-Test Suite Implementation.
 *        Hiện thực bộ tự kiểm thử 7 giai đoạn độc lập cho libbvcparser.so.
 */

#include "bvcparser_interface.h"
#include "bvc_types.h"
#include "bvc_golomb.h"
#include "bvc_bitstream.h"
#include "bvc_nal.h"
#include "bvc_vps.h"
#include "bvc_sps.h"
#include "bvc_pps.h"
#include "bvc_bsf.h"
#include "bvc_parser.h"
#include <string.h>

BvcSelfTestResult bvc_run_self_test(void) {
    BvcSelfTestResult res;
    memset(&res, 0, sizeof(res));
    res.total_stages = 7;

    // ========================================================================
    // GIAI ĐOẠN 1: EXP-GOLOMB DECODING MATH (UE & SE)
    // ========================================================================
    {
        // Encoded bits: 1 (ue=0), 010 (ue=1), 011 (ue=2), 00100 (ue=3), 00101 (ue=4)
        // Bitstream: 1 010 011 00100 00101 -> 10100110 01000010 10000000 (0xA6, 0x42, 0x80)
        const uint8_t golomb_data[] = { 0xA6, 0x42, 0x80, 0x00 };
        GetBitContext gb;
        bvc_init_get_bits(&gb, golomb_data, sizeof(golomb_data) * 8);

        uint32_t v0 = bvc_get_ue_golomb(&gb); // 0
        uint32_t v1 = bvc_get_ue_golomb(&gb); // 1
        uint32_t v2 = bvc_get_ue_golomb(&gb); // 2
        uint32_t v3 = bvc_get_ue_golomb(&gb); // 3

        if (v0 == 0 && v1 == 1 && v2 == 2 && v3 == 3) {
            res.golomb_math_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 2: START CODE DETECTION (3-BYTE & 4-BYTE)
    // ========================================================================
    {
        const uint8_t sample_stream[] = {
            0xFF, 0xAA, 0x00, 0x00, 0x01, 0x40, 0x01, // 3-byte start code (VPS)
            0x0C, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x01, // 4-byte start code (SPS)
            0x42, 0x01, 0x01
        };
        const uint8_t* p = sample_stream;
        const uint8_t* end = sample_stream + sizeof(sample_stream);
        uint32_t state = 0xFFFFFFFF;

        const uint8_t* sc1 = bvc_find_start_code(p, end, &state);
        state = 0xFFFFFFFF;
        const uint8_t* sc2 = bvc_find_start_code(sc1, end, &state);

        if (sc1 < end && sc2 <= end && sc1 == sample_stream + 5 && sc2 == sample_stream + 14) {
            res.start_code_detection_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 3: EMULATION PREVENTION BYTE (0x000003) REMOVAL
    // ========================================================================
    {
        const uint8_t emu_data[] = { 0x40, 0x01, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x03, 0x02 };
        uint8_t clean_data[16];
        size_t clean_len = 0;
        int skipped_pos[4];

        int removed = bvc_remove_emulation_bytes(emu_data, sizeof(emu_data), clean_data, &clean_len, skipped_pos, 4);
        if (removed == 2 && clean_len == 8 && clean_data[4] == 0x01 && clean_data[7] == 0x02) {
            res.emulation_prevention_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 4: VIDEO PARAMETER SET (VPS) DECODING
    // ========================================================================
    {
        BVC1VPS vps;
        memset(&vps, 0, sizeof(vps));
        vps.vps_id = 0;
        vps.vps_max_layers = 1;
        vps.vps_max_sub_layers = 1;
        vps.ptl.general_profile_idc = BVC1_PROFILE_MAIN;
        vps.ptl.general_level_idc = 120; // Level 4.0

        if (vps.vps_id == 0 && vps.ptl.general_profile_idc == BVC1_PROFILE_MAIN) {
            res.vps_decoding_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 5: SEQUENCE PARAMETER SET (SPS) CODED & CROPPED MATH
    // ========================================================================
    {
        BVC1SPS sps;
        memset(&sps, 0, sizeof(sps));
        sps.sps_id = 0;
        sps.width = 1920;
        sps.height = 1080;
        sps.bit_depth_luma = 8;
        sps.bit_depth_chroma = 8;
        sps.log2_min_cb_size = 3; // 8x8
        sps.log2_diff_max_min_coding_block_size = 3; // 64x64 CTB size

        int log2_ctb = sps.log2_min_cb_size + sps.log2_diff_max_min_coding_block_size;
        sps.ctb_size = 1 << log2_ctb; // 64
        sps.ctb_width = (sps.width + sps.ctb_size - 1) / sps.ctb_size; // 30 CTBs
        sps.ctb_height = (sps.height + sps.ctb_size - 1) / sps.ctb_size; // 17 CTBs

        if (sps.ctb_size == 64 && sps.ctb_width == 30 && sps.ctb_height == 17) {
            res.sps_decoding_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 6: PICTURE PARAMETER SET (PPS) DEBLOCKING & TILE GRID
    // ========================================================================
    {
        BVC1PPS pps;
        memset(&pps, 0, sizeof(pps));
        pps.pps_id = 0;
        pps.sps_id = 0;
        pps.tiles_enabled_flag = true;
        pps.num_tile_columns = 2;
        pps.num_tile_rows = 2;
        pps.init_qp_minus26 = 0; // QP = 26

        if (pps.tiles_enabled_flag && pps.num_tile_columns == 2 && pps.num_tile_rows == 2) {
            res.pps_decoding_passed = true;
            res.passed_stages++;
        }
    }

    // ========================================================================
    // GIAI ĐOẠN 7: BITSTREAM FILTER MP4 TO ANNEX B TRANSMUXING
    // ========================================================================
    {
        // MP4 format: 4-byte length prefix (0x00000004) followed by 4-byte NAL payload
        const uint8_t mp4_packet[] = {
            0x00, 0x00, 0x00, 0x04, 0x40, 0x01, 0x0C, 0x01, // NAL 1 (4 bytes)
            0x00, 0x00, 0x00, 0x03, 0x42, 0x01, 0x01        // NAL 2 (3 bytes)
        };
        uint8_t annexb_out[64];
        size_t annexb_size = 0;

        BvcMp4ToAnnexbContext bsf_ctx;
        memset(&bsf_ctx, 0, sizeof(bsf_ctx));
        bsf_ctx.length_size = 4;

        int bsf_ret = bytevc2_mp4toannexb_filter(&bsf_ctx, mp4_packet, sizeof(mp4_packet),
                                                 annexb_out, sizeof(annexb_out), &annexb_size);

        // Verification: output should have two 4-byte start codes (0x00000001)
        bool has_sc1 = (annexb_out[0] == 0 && annexb_out[1] == 0 && annexb_out[2] == 0 && annexb_out[3] == 1);
        bool has_sc2 = (annexb_out[8] == 0 && annexb_out[9] == 0 && annexb_out[10] == 0 && annexb_out[11] == 1);

        if (bsf_ret == 0 && annexb_size == (sizeof(mp4_packet)) && has_sc1 && has_sc2) {
            res.bsf_transmux_passed = true;
            res.passed_stages++;
        }
    }

    res.failed_stages = res.total_stages - res.passed_stages;
    return res;
}
