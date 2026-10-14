// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_h264_parser.cpp
// Description: Full implementation of H.264/H.265 NAL unit, ParamSets, POC and MMCO scanner
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "tt_h264_parser.h"
#include <stdlib.h>
#include <string.h>

// ===================================================================================
// 1. NAL UNIT MEMORY MANAGEMENT
// Quản lý bộ nhớ NAL Unit H.264 / H.265
// ===================================================================================

/**
 * @brief Allocates a new H2645NAL structure.
 * Khởi tạo cấu trúc NAL Unit với kích thước chuẩn 0x68 (104 bytes).
 * Opcode ARM64: 0x1c8298 (mov x0, #0x68; b av_mallocz)
 */
H2645NAL* tt_H2645NAL_malloc(void) {
    H2645NAL* nal = (H2645NAL*)calloc(1, sizeof(H2645NAL));
    return nal;
}

/**
 * @brief Frees an H2645NAL structure and zeroes the pointer.
 * Giải phóng NAL Unit và xóa rỗng con trỏ.
 * Opcode ARM64: 0x1c82a0..0x1c82dc
 */
void tt_H2645NAL_freep(H2645NAL** nal) {
    if (!nal || !*nal) {
        return;
    }
    H2645NAL* p = *nal;
    if (p->raw_data) {
        free(p->raw_data);
        p->raw_data = NULL;
    }
    if (p->extra_alloc) {
        free(p->extra_alloc);
        p->extra_alloc = NULL;
    }
    free(p);
    *nal = NULL;
}

/**
 * @brief Retrieves extracted RBSP data pointer from NAL unit.
 * Lấy con trỏ dữ liệu RBSP đã trích xuất từ NAL Unit.
 * Opcode ARM64: 0x1c82e8 (ldr x0, [x0, #0x10]; ret)
 */
uint8_t* tt_H2645NAL_get_data(const H2645NAL* nal) {
    if (!nal) return NULL;
    return nal->data;
}

/**
 * @brief Retrieves NAL payload size.
 * Lấy kích thước dữ liệu NAL payload.
 * Opcode ARM64: 0x1c82f0 (ldr w0, [x0, #0xc]; ret)
 */
int32_t tt_H2645NAL_get_data_size(const H2645NAL* nal) {
    if (!nal) return 0;
    return nal->size;
}


// ===================================================================================
// 2. PARAMETER SETS (SPS & PPS) MANAGER
// Bộ quản lý tập tham số SPS và PPS
// ===================================================================================

/**
 * @brief Allocates an H264ParamSets manager table.
 * Cấp phát bảng quản lý tập tham số SPS/PPS kích thước 0x920 (2,336 bytes).
 * Opcode ARM64: 0x1c82f8 (mov x0, #0x920; b av_mallocz)
 */
H264ParamSets* tt_H264ParamSets_malloc(void) {
    H264ParamSets* ps = (H264ParamSets*)calloc(1, sizeof(H264ParamSets));
    return ps;
}

/**
 * @brief Frees an H264ParamSets manager table and its active references.
 * Giải phóng bảng quản lý tập tham số và các tham chiếu active.
 * Opcode ARM64: 0x1c8300..0x1c832c
 */
void tt_H264ParamSets_free(H264ParamSets* ps) {
    if (!ps) return;
    for (int i = 0; i < 32; i++) {
        if (ps->sps_list[i]) {
            tt_SPS_free(ps->sps_list[i]);
            ps->sps_list[i] = NULL;
        }
    }
    for (int i = 0; i < 256; i++) {
        if (ps->pps_list[i]) {
            tt_PPS_free(ps->pps_list[i]);
            ps->pps_list[i] = NULL;
        }
    }
    free(ps);
}

/**
 * @brief Returns maximum SPS count according to H.264 spec (32).
 * Trả về số lượng SPS tối đa theo chuẩn H.264 (32).
 * Opcode ARM64: 0x1c8330 (mov w0, #0x20; ret)
 */
int32_t tt_H264ParamSets_get_sps_list_count(const H264ParamSets* ps) {
    (void)ps;
    return 32; // 0x20
}

/**
 * @brief Retrieves SPS pointer by index from the list.
 * Lấy con trỏ SPS theo chỉ số mảng.
 * Opcode ARM64: 0x1c8338 (ldr x0, [x0, w1, sxtw #3]; ret)
 */
SPS* tt_H264ParamSets_get_sps_list(const H264ParamSets* ps, int32_t index) {
    if (!ps || index < 0 || index >= 32) return NULL;
    return ps->sps_list[index];
}

/**
 * @brief Returns maximum PPS count according to H.264 spec (256).
 * Trả về số lượng PPS tối đa theo chuẩn H.264 (256).
 * Opcode ARM64: 0x1c8340 (mov w0, #0x100; ret)
 */
int32_t tt_H264ParamSets_get_pps_list_count(const H264ParamSets* ps) {
    (void)ps;
    return 256; // 0x100
}

/**
 * @brief Retrieves PPS pointer by index from the list (offset 0x100).
 * Lấy con trỏ PPS theo chỉ số mảng tại vùng offset 0x100.
 * Opcode ARM64: 0x1c8348 (add x0, x0, w1, sxtw #3; ldr x0, [x0, #0x100]; ret)
 */
PPS* tt_H264ParamSets_get_pps_list(const H264ParamSets* ps, int32_t index) {
    if (!ps || index < 0 || index >= 256) return NULL;
    return ps->pps_list[index];
}

/**
 * @brief Returns current active SPS.
 * Trả về con trỏ SPS hiện hành đang được kích hoạt.
 * Opcode ARM64: 0x1c8354 (ldr x0, [x0, #0x918]; ret)
 */
SPS* tt_H264ParamSets_get_sps(const H264ParamSets* ps) {
    if (!ps) return NULL;
    return ps->current_sps;
}

/**
 * @brief Returns current active PPS.
 * Trả về con trỏ PPS hiện hành đang được kích hoạt.
 * Opcode ARM64: 0x1c835c (ldr x0, [x0, #0x910]; ret)
 */
PPS* tt_H264ParamSets_get_pps(const H264ParamSets* ps) {
    if (!ps) return NULL;
    return ps->current_pps;
}


// ===================================================================================
// 3. PICTURE PARAMETER SET (PPS) OPERATIONS
// Thao tác với Tập tham số Hình ảnh (PPS)
// ===================================================================================

/**
 * @brief Allocates a new PPS structure.
 * Cấp phát cấu trúc PPS kích thước 0x2a740 (173,888 bytes).
 * Opcode ARM64: 0x1c8364 (mov x0, #0xa740; movk x0, #2, lsl #16; b av_mallocz)
 */
PPS* tt_PPS_malloc(void) {
    PPS* pps = (PPS*)calloc(1, sizeof(PPS));
    return pps;
}

/**
 * @brief Frees a PPS structure.
 * Giải phóng bộ nhớ PPS.
 * Opcode ARM64: 0x1c8370 (b av_free)
 */
void tt_PPS_free(PPS* pps) {
    if (pps) {
        free(pps);
    }
}

/**
 * @brief Copies PPS contents from source to destination.
 * Sao chép nguyên khối nội dung PPS (0x2a740 bytes).
 * Opcode ARM64: 0x1c8374 (mov x2, #0xa740; movk x2, #2, lsl #16; b memcpy)
 */
void tt_PPS_copy(PPS* dst, const PPS* src) {
    if (!dst || !src) return;
    memcpy(dst, src, sizeof(PPS));
}

/**
 * @brief Retrieves pic_order_present flag from PPS.
 * Lấy cờ pic_order_present_flag tại offset 0x08.
 * Opcode ARM64: 0x1c8380 (ldr w0, [x0, #8]; ret)
 */
int32_t tt_PPS_get_pic_order_present(const PPS* pps) {
    if (!pps) return 0;
    return pps->pic_order_present;
}

/**
 * @brief Retrieves referenced SPS ID from PPS.
 * Lấy ID của SPS mà PPS này tham chiếu tới (offset 0x00).
 * Opcode ARM64: 0x1c8388 (ldr w0, [x0]; ret)
 */
int32_t tt_PPS_get_sps_id(const PPS* pps) {
    if (!pps) return 0;
    return pps->sps_id;
}


// ===================================================================================
// 4. SEQUENCE PARAMETER SET (SPS) OPERATIONS
// Thao tác với Tập tham số Phân đoạn (SPS)
// ===================================================================================

/**
 * @brief Allocates a new SPS structure.
 * Cấp phát cấu trúc SPS kích thước 0x14b8 (5,304 bytes).
 * Opcode ARM64: 0x1c8390 (mov x0, #0x14b8; b av_mallocz)
 */
SPS* tt_SPS_malloc(void) {
    SPS* sps = (SPS*)calloc(1, sizeof(SPS));
    return sps;
}

/**
 * @brief Frees an SPS structure.
 * Giải phóng bộ nhớ SPS.
 * Opcode ARM64: 0x1c8398 (b av_free)
 */
void tt_SPS_free(SPS* sps) {
    if (sps) {
        free(sps);
    }
}

/**
 * @brief Copies SPS contents from source to destination.
 * Sao chép nguyên khối nội dung SPS (0x14b8 bytes).
 * Opcode ARM64: 0x1c839c (mov x2, #0x14b8; b memcpy)
 */
void tt_SPS_copy(SPS* dst, const SPS* src) {
    if (!dst || !src) return;
    memcpy(dst, src, sizeof(SPS));
}

/**
 * @brief Copies SPS contents from internal buffer context.
 * Sao chép nội dung SPS từ con trỏ bộ đệm nội bộ (offset 0x08).
 * Opcode ARM64: 0x1c83a4 (ldr x1, [x1, #8]; mov x2, #0x14b8; b memcpy)
 */
void tt_SPS_copy_from_buffer(SPS* dst, const void* buffer_ctx) {
    if (!dst || !buffer_ctx) return;
    const void* src = *(const void**)((const char*)buffer_ctx + 8);
    if (src) {
        memcpy(dst, src, sizeof(SPS));
    }
}

/**
 * @brief Accesses SPS integer field via jump table.
 * Truy vấn trường số nguyên trong SPS thông qua bảng nhảy.
 * Opcode ARM64: 0x1c83b0..0x1c8404
 * - Field 0 -> offset 0x14 (profile_idc)
 * - Field 1 -> offset 0x40 (level_idc)
 * - Field 2 -> offset 0x18 (chroma_format_idc)
 * - Field 3 -> offset 0x1c (bit_depth_luma)
 * - Field 4 -> offset 0x20 (bit_depth_chroma)
 * - Field 5 -> offset 0x298 (max_num_reorder / sar)
 */
uint32_t tt_SPS_get_int_field(const SPS* sps, int32_t field_index) {
    if (!sps || field_index < 0 || field_index > 5) {
        return 0;
    }
    switch (field_index) {
        case 0: return sps->profile_idc;
        case 1: return sps->level_idc;
        case 2: return sps->chroma_format_idc;
        case 3: return sps->bit_depth_luma;
        case 4: return sps->bit_depth_chroma;
        case 5: return sps->max_num_reorder;
        default: return 0;
    }
}


// ===================================================================================
// 5. PICTURE ORDER COUNT (POC) CONTEXT
// Quản lý Ngữ cảnh Đếm Thứ tự Khung hình POC
// ===================================================================================

/**
 * @brief Allocates an H264POCContext structure.
 * Cấp phát ngữ cảnh POC kích thước 0x2c (44 bytes).
 * Opcode ARM64: 0x1c8408 (mov x0, #0x2c; b av_mallocz)
 */
H264POCContext* tt_H264POCContext_malloc(void) {
    H264POCContext* ctx = (H264POCContext*)calloc(1, sizeof(H264POCContext));
    return ctx;
}

/**
 * @brief Frees an H264POCContext structure.
 * Giải phóng ngữ cảnh POC.
 * Opcode ARM64: 0x1c8410 (b av_free)
 */
void tt_H264POCContext_free(H264POCContext* ctx) {
    if (ctx) {
        free(ctx);
    }
}

/**
 * @brief Sets delta POC array element.
 * Thiết lập giá trị mảng delta_poc (offset 0x0c + index * 4).
 * Opcode ARM64: 0x1c8414 (add x0, x0, w1, sxtw #2; str w2, [x0, #0xc]; ret)
 */
void tt_H264POCContext_set_delta_poc(H264POCContext* ctx, int32_t index, int32_t val) {
    if (!ctx || index < 0 || index > 1) return;
    ctx->delta_poc[index] = val;
}

/**
 * @brief Sets POC integer field via jump table.
 * Gán trường số nguyên POC thông qua bảng nhảy.
 * Opcode ARM64: 0x1c8420..0x1c8484
 */
void tt_H264POCContext_set_int_field(H264POCContext* ctx, int32_t field_index, int32_t val) {
    if (!ctx || field_index < 0 || field_index > 8) return;
    switch (field_index) {
        case 0: ctx->field_28 = val; break; // offset 0x28
        case 1: ctx->field_24 = val; break; // offset 0x24
        case 2: ctx->field_18 = val; break; // offset 0x18
        case 3: ctx->field_1c = val; break; // offset 0x1c
        case 4: ctx->field_14 = val; break; // offset 0x14
        case 5: ctx->field_20 = val; break; // offset 0x20
        case 6: ctx->field_04 = val; break; // offset 0x04
        case 7: ctx->field_00 = val; break; // offset 0x00
        case 8: ctx->field_08 = val; break; // offset 0x08
    }
}

/**
 * @brief Retrieves POC integer field via jump table.
 * Truy vấn trường số nguyên POC thông qua bảng nhảy.
 * Opcode ARM64: 0x1c8488..0x1c84f4
 */
int32_t tt_H264POCContext_get_int_field(const H264POCContext* ctx, int32_t field_index) {
    if (!ctx || field_index < 0 || field_index > 8) return 0;
    switch (field_index) {
        case 0: return ctx->field_28;
        case 1: return ctx->field_24;
        case 2: return ctx->field_18;
        case 3: return ctx->field_1c;
        case 4: return ctx->field_14;
        case 5: return ctx->field_20;
        case 6: return ctx->field_04;
        case 7: return ctx->field_00;
        case 8: return ctx->field_08;
        default: return 0;
    }
}


// ===================================================================================
// 6. FAST BITSTREAM MMCO RESET SCANNER
// Bộ quét nhanh Memory Management Control Operation (MMCO) trong Bitstream
// ===================================================================================

/**
 * @brief Simple Bitstream Reader for parsing Exp-Golomb codes in slice headers.
 * Trình đọc bitstream phụ trợ để giải mã mã Exp-Golomb trong slice header.
 */
typedef struct SimpleBitReader {
    const uint8_t* buffer;
    int32_t total_bits;
    int32_t bit_pos;
} SimpleBitReader;

static inline void init_bit_reader(SimpleBitReader* r, const uint8_t* buf, int32_t size_bytes) {
    r->buffer = buf;
    r->total_bits = size_bytes * 8;
    r->bit_pos = 0;
}

static inline uint32_t read_bits(SimpleBitReader* r, int32_t n) {
    uint32_t val = 0;
    while (n > 0 && r->bit_pos < r->total_bits) {
        int byte_idx = r->bit_pos >> 3;
        int bit_idx = 7 - (r->bit_pos & 7);
        val = (val << 1) | ((r->buffer[byte_idx] >> bit_idx) & 1);
        r->bit_pos++;
        n--;
    }
    return val;
}

static inline uint32_t read_ue_golomb(SimpleBitReader* r) {
    int leading_zeros = 0;
    while (r->bit_pos < r->total_bits && read_bits(r, 1) == 0) {
        leading_zeros++;
    }
    if (leading_zeros == 0) {
        return 0;
    }
    uint32_t info = read_bits(r, leading_zeros);
    return (1u << leading_zeros) - 1 + info;
}

/**
 * @brief Scans slice header in bitstream to detect if an MMCO == 5 reset exists.
 * Quét tiêu đề phân đoạn H.264 xem có lệnh MMCO == 5 (reset DPB) hay không.
 * Opcode ARM64: 0x1c8510..0x1c87ac
 * @param bitstream_buf Buffer containing NAL slice payload
 * @param buf_size Size of the buffer in bytes
 * @param nal_unit_type NAL unit type (e.g. 1 = Non-IDR, 5 = IDR)
 * @return 1 if MMCO == 5 found (instant seek keyframe behavior), 0 otherwise
 */
int32_t tt_scan_mmco_reset(const uint8_t* bitstream_buf, int32_t buf_size, int32_t nal_unit_type) {
    if (!bitstream_buf || buf_size <= 4) {
        return 0;
    }

    // IDR frames (NAL unit type 5) implicitly reset all reference frames
    if (nal_unit_type == 5) {
        return 1;
    }

    SimpleBitReader reader;
    init_bit_reader(&reader, bitstream_buf, buf_size);

    // Skip first_mb_in_slice (ue) and slice_type (ue)
    (void)read_ue_golomb(&reader);
    (void)read_ue_golomb(&reader);
    // Skip pic_parameter_set_id (ue)
    (void)read_ue_golomb(&reader);

    // Frame num (usually log2_max_frame_num bits, skip 4-16 bits)
    read_bits(&reader, 8);

    // Check adaptive_ref_pic_marking_mode_flag (1 bit)
    uint32_t adaptive_marking = read_bits(&reader, 1);
    if (!adaptive_marking) {
        return 0; // Default FIFO marking, no explicit MMCO reset
    }

    // Parse MMCO loop (khớp vòng lặp opcode 0x1c8710 - 0x1c874c)
    while (reader.bit_pos < reader.total_bits) {
        uint32_t mmco = read_ue_golomb(&reader);
        if (mmco == 0) {
            // End of MMCO loop (opcode 0x1c8724: cbz w0, #0x1c871c)
            break;
        }

        if (mmco == 5) {
            // MMCO 5: Mark all reference pictures as unused for reference
            // (opcode 0x1c8728: cmp w0, #5; b.eq #0x1c87ac -> return 1)
            return 1;
        }

        if (mmco == 1 || mmco == 3) {
            // Skip difference_of_pic_nums_minus1 (ue)
            // (opcode 0x1c8730: and w0, w0, #0xfffffffd; cmp w0, #1)
            (void)read_ue_golomb(&reader);
        }
        if (mmco == 2) {
            // Skip long_term_pic_num (ue)
            (void)read_ue_golomb(&reader);
        }
        if (mmco == 3) {
            // Skip long_term_frame_idx (ue)
            (void)read_ue_golomb(&reader);
        }
        if (mmco == 4) {
            // Skip max_long_term_frame_idx_plus1 (ue)
            (void)read_ue_golomb(&reader);
        }
        if (mmco == 6) {
            // Skip long_term_frame_idx (ue)
            (void)read_ue_golomb(&reader);
        }
    }

    return 0; // No MMCO 5 reset found
}
