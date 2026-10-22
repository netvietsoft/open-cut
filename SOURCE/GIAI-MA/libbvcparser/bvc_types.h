/**
 * @file bvc_types.h
 * @brief ByteDance BVC Video Container & Bitstream Parser Types Definition.
 *        Định nghĩa các kiểu dữ liệu và cấu trúc cho bộ phân giải luồng video ByteDance BVC (ByteVC1 / ByteVC2 / VVC).
 *
 * Reconstructed from libbvcparser.so (ByteDance ByteVC1 / HEVC Video Bitstream Parser).
 * Tái cấu trúc sạch từ thư viện nhị phân libbvcparser.so của CapCut / ByteDance.
 */

#ifndef BYTEDANCE_BVC_TYPES_H
#define BYTEDANCE_BVC_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// HẰNG SỐ & PHÂN LOẠI NAL UNIT (CONSTANTS & NAL UNIT ENUMS)
// ============================================================================

/**
 * @brief ByteVC1 / HEVC NAL Unit Types matching ITU-T H.265 specification.
 *        Các loại khối NAL Unit của ByteVC1 / HEVC theo chuẩn ITU-T H.265.
 */
typedef enum {
    BVC1_NAL_TRAIL_N    = 0,
    BVC1_NAL_TRAIL_R    = 1,
    BVC1_NAL_TSA_N      = 2,
    BVC1_NAL_TSA_R      = 3,
    BVC1_NAL_STSA_N     = 4,
    BVC1_NAL_STSA_R     = 5,
    BVC1_NAL_RADL_N     = 6,
    BVC1_NAL_RADL_R     = 7,
    BVC1_NAL_RASL_N     = 8,
    BVC1_NAL_RASL_R     = 9,
    BVC1_NAL_IDR_W_RADL = 19,
    BVC1_NAL_IDR_N_LP   = 20,
    BVC1_NAL_CRA_NUT    = 21,
    BVC1_NAL_VPS_NUT    = 32,
    BVC1_NAL_SPS_NUT    = 33,
    BVC1_NAL_PPS_NUT    = 34,
    BVC1_NAL_AUD_NUT    = 35,
    BVC1_NAL_EOS_NUT    = 36,
    BVC1_NAL_EOB_NUT    = 37,
    BVC1_NAL_FD_NUT     = 38,
    BVC1_NAL_PREFIX_SEI = 39,
    BVC1_NAL_SUFFIX_SEI = 40
} BVC1NalType;

/**
 * @brief Slice Types (I, P, B).
 *        Các loại phân đoạn khung hình (Slice).
 */
typedef enum {
    BVC1_SLICE_B = 0,
    BVC1_SLICE_P = 1,
    BVC1_SLICE_I = 2
} BVC1SliceType;

/**
 * @brief ByteVC1 Profiles.
 *        Các cấu hình chuẩn mã hóa ByteVC1.
 */
typedef enum {
    BVC1_PROFILE_MAIN                = 1,
    BVC1_PROFILE_MAIN_10             = 2,
    BVC1_PROFILE_MAIN_STILL_PICTURE  = 3,
    BVC1_PROFILE_REXT                = 4
} BVC1Profile;

#define BVC1_MAX_VPS_COUNT 16
#define BVC1_MAX_SPS_COUNT 32
#define BVC1_MAX_PPS_COUNT 64
#define BVC1_MAX_SUB_LAYERS 7
#define BVC1_MAX_SHORT_TERM_RPS_COUNT 64
#define BVC1_MAX_LONG_TERM_REF_PICS 32

// ============================================================================
// CẤU TRÚC BITSTREAM GETBITCONTEXT (BITSTREAM PARSER CONTEXT)
// ============================================================================

/**
 * @struct GetBitContext
 * @brief Bitstream reader structure matching binary layout at offset 0x00, 0x10, 0x18.
 *        Cấu trúc đọc luồng bit khớp với bố cục thanh ghi AArch64 (ptr: 0x0, index: 0x10, size: 0x18).
 */
typedef struct {
    const uint8_t* buffer;          ///< Raw bitstream byte buffer pointer (Offset 0x00)
    const uint8_t* buffer_end;      ///< Pointer to end of buffer (Offset 0x08)
    int32_t        index;           ///< Current bit index position (Offset 0x10)
    int32_t        size_in_bits;    ///< Total available bits in buffer (Offset 0x18)
} GetBitContext;

/**
 * @struct BVC1Nal
 * @brief Raw NAL unit envelope.
 *        Cấu trúc đóng gói khối NAL thô đã loại bỏ byte chống trùng lặp.
 */
typedef struct {
    int32_t  type;                  ///< NAL Unit type (BVC1NalType)
    int32_t  temporal_id;           ///< Temporal layer ID
    const uint8_t* data;            ///< Pointer to extracted payload
    size_t   size;                  ///< Payload size in bytes
    size_t   skipped_bytes;         ///< Number of 0x000003 emulation bytes removed
    size_t   skipped_bytes_pos_size;///< Capacity of skipped byte position array
    int*     skipped_bytes_pos;     ///< Array of emulation byte offsets
} BVC1Nal;

// ============================================================================
// PARAMETER SETS (VPS / SPS / PPS)
// ============================================================================

/**
 * @struct BVC1PTL
 * @brief Profile Tier Level structure.
 *        Cấu trúc đặc tả Profile Tier Level.
 */
typedef struct {
    int32_t general_profile_space;
    bool    general_tier_flag;
    int32_t general_profile_idc;
    uint32_t general_profile_compatibility_flags;
    int32_t general_level_idc;
} BVC1PTL;

/**
 * @struct BVC1VPS
 * @brief Video Parameter Set definition.
 *        Đặc tả Video Parameter Set của ByteVC1 / HEVC.
 */
typedef struct {
    int32_t  vps_id;
    int32_t  vps_max_layers;
    int32_t  vps_max_sub_layers;
    bool     vps_temporal_id_nesting_flag;
    BVC1PTL  ptl;
    int32_t  vps_max_dec_pic_buffering[BVC1_MAX_SUB_LAYERS];
    int32_t  vps_max_num_reorder_pics[BVC1_MAX_SUB_LAYERS];
    int32_t  vps_max_latency_increase[BVC1_MAX_SUB_LAYERS];
} BVC1VPS;

/**
 * @struct BVC1Window
 * @brief Cropping and display conformance window.
 *        Cửa sổ cắt cúp và hiển thị đồng bộ khung hình.
 */
typedef struct {
    uint32_t left;
    uint32_t right;
    uint32_t top;
    uint32_t bottom;
} BVC1Window;

/**
 * @struct BVC1SPS
 * @brief Sequence Parameter Set definition.
 *        Đặc tả Sequence Parameter Set của ByteVC1 / HEVC.
 */
typedef struct {
    int32_t  sps_id;
    int32_t  vps_id;
    int32_t  chroma_format_idc;
    bool     separate_colour_plane_flag;
    int32_t  width;                 ///< Coded width in luma samples
    int32_t  height;                ///< Coded height in luma samples
    BVC1Window conformance_window;  ///< Cropped display window
    int32_t  bit_depth_luma;        ///< 8, 10, or 12 bits
    int32_t  bit_depth_chroma;      ///< Must match luma depth
    int32_t  log2_max_pic_order_cnt_lsb;
    int32_t  log2_min_cb_size;
    int32_t  log2_diff_max_min_coding_block_size;
    int32_t  log2_min_tb_size;
    int32_t  log2_diff_max_min_transform_block_size;
    int32_t  max_transform_hierarchy_depth_inter;
    int32_t  max_transform_hierarchy_depth_intra;
    int32_t  ctb_width;             ///< Coding tree block width
    int32_t  ctb_height;            ///< Coding tree block height
    int32_t  ctb_size;              ///< CTB size (typically 16, 32, or 64)
    // VUI parameters
    bool     vui_parameters_present_flag;
    int32_t  sar_num;
    int32_t  sar_den;
    uint32_t time_scale;
    uint32_t num_units_in_tick;
} BVC1SPS;

/**
 * @struct BVC1PPS
 * @brief Picture Parameter Set definition.
 *        Đặc tả Picture Parameter Set của ByteVC1 / HEVC.
 */
typedef struct {
    int32_t  pps_id;
    int32_t  sps_id;
    bool     dependent_slice_segments_enabled_flag;
    bool     output_flag_present_flag;
    int32_t  num_extra_slice_header_bits;
    bool     sign_data_hiding_enabled_flag;
    bool     cabac_init_present_flag;
    int32_t  num_ref_idx_l0_default_active_minus1;
    int32_t  num_ref_idx_l1_default_active_minus1;
    int32_t  init_qp_minus26;
    bool     constrained_intra_pred_flag;
    bool     transform_skip_enabled_flag;
    bool     cu_qp_delta_enabled_flag;
    int32_t  diff_cu_qp_delta_depth;
    int32_t  cb_qp_offset;
    int32_t  cr_qp_offset;
    bool     slice_chroma_qp_offsets_present_flag;
    bool     weighted_pred_flag;
    bool     weighted_bipred_flag;
    bool     transquant_bypass_enabled_flag;
    bool     tiles_enabled_flag;
    bool     entropy_coding_sync_enabled_flag;
    int32_t  num_tile_columns;
    int32_t  num_tile_rows;
    bool     uniform_spacing_flag;
    bool     loop_filter_across_tiles_enabled_flag;
    bool     pps_loop_filter_across_slices_enabled_flag;
    bool     deblocking_filter_control_present_flag;
    bool     deblocking_filter_override_enabled_flag;
    bool     pps_deblocking_filter_disabled_flag;
    int32_t  pps_beta_offset_div2;
    int32_t  pps_tc_offset_div2;
    int32_t  log2_parallel_merge_level;
} BVC1PPS;

/**
 * @struct BVC1SliceHeader
 * @brief Decoded Slice Header parameters.
 *        Thông tin tiêu đề phân đoạn khung hình đã giải mã.
 */
typedef struct {
    int32_t  slice_type;            ///< BVC1_SLICE_B, P, or I
    int32_t  pps_id;
    uint32_t slice_segment_addr;
    int32_t  pic_order_cnt_lsb;
    int32_t  poc;                   ///< Computed Picture Order Count
    int32_t  slice_qp_delta;
    int32_t  slice_cb_qp_offset;
    int32_t  slice_cr_qp_offset;
    bool     slice_temporal_mvp_enabled_flag;
} BVC1SliceHeader;

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_TYPES_H
