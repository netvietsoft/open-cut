// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_h264_parser.h
// Description: Header for H.264 / H.265 NAL unit, ParamSets, POC and MMCO scanner
// ===================================================================================

#pragma once

#include "ttffmpeg_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- NAL Unit Operations ---
H2645NAL* tt_H2645NAL_malloc(void);
void tt_H2645NAL_freep(H2645NAL** nal);
uint8_t* tt_H2645NAL_get_data(const H2645NAL* nal);
int32_t tt_H2645NAL_get_data_size(const H2645NAL* nal);

// --- ParamSets Operations ---
H264ParamSets* tt_H264ParamSets_malloc(void);
void tt_H264ParamSets_free(H264ParamSets* ps);
int32_t tt_H264ParamSets_get_sps_list_count(const H264ParamSets* ps);
SPS* tt_H264ParamSets_get_sps_list(const H264ParamSets* ps, int32_t index);
int32_t tt_H264ParamSets_get_pps_list_count(const H264ParamSets* ps);
PPS* tt_H264ParamSets_get_pps_list(const H264ParamSets* ps, int32_t index);
SPS* tt_H264ParamSets_get_sps(const H264ParamSets* ps);
PPS* tt_H264ParamSets_get_pps(const H264ParamSets* ps);

// --- PPS Operations ---
PPS* tt_PPS_malloc(void);
void tt_PPS_free(PPS* pps);
void tt_PPS_copy(PPS* dst, const PPS* src);
int32_t tt_PPS_get_pic_order_present(const PPS* pps);
int32_t tt_PPS_get_sps_id(const PPS* pps);

// --- SPS Operations ---
SPS* tt_SPS_malloc(void);
void tt_SPS_free(SPS* sps);
void tt_SPS_copy(SPS* dst, const SPS* src);
void tt_SPS_copy_from_buffer(SPS* dst, const void* buffer_ctx);
uint32_t tt_SPS_get_int_field(const SPS* sps, int32_t field_index);

// --- POC (Picture Order Count) Operations ---
H264POCContext* tt_H264POCContext_malloc(void);
void tt_H264POCContext_free(H264POCContext* ctx);
void tt_H264POCContext_set_delta_poc(H264POCContext* ctx, int32_t index, int32_t val);
void tt_H264POCContext_set_int_field(H264POCContext* ctx, int32_t field_index, int32_t val);
int32_t tt_H264POCContext_get_int_field(const H264POCContext* ctx, int32_t field_index);

// --- Bitstream Fast MMCO Reset Scanner ---
int32_t tt_scan_mmco_reset(const uint8_t* bitstream_buf, int32_t buf_size, int32_t nal_unit_type);

#ifdef __cplusplus
}
#endif
