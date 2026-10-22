/**
 * @file bvc_parser.h
 * @brief ByteDance BVC Codec Parser Engine & Registration Interface.
 *        Giao diện động cơ phân tích cú pháp codec ByteVC1 và hàm đăng ký vào hệ thống.
 */

#ifndef BYTEDANCE_BVC_PARSER_H
#define BYTEDANCE_BVC_PARSER_H

#include "bvc_types.h"
#include "bvc_vps.h"
#include "bvc_sps.h"
#include "bvc_pps.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BvcParserContext_t {
    BVC1VPS         vps_list[BVC1_MAX_VPS_COUNT];
    BVC1SPS         sps_list[BVC1_MAX_SPS_COUNT];
    BVC1PPS         pps_list[BVC1_MAX_PPS_COUNT];
    bool            vps_valid[BVC1_MAX_VPS_COUNT];
    bool            sps_valid[BVC1_MAX_SPS_COUNT];
    bool            pps_valid[BVC1_MAX_PPS_COUNT];

    int32_t         active_sps_id;
    int32_t         active_pps_id;

    // Extracted video format parameters
    int32_t         width;
    int32_t         height;
    int32_t         cropped_width;
    int32_t         cropped_height;
    int32_t         pix_fmt;        ///< Pixel format (YUV420P, YUV420P10LE, etc.)
    int32_t         profile;
    int32_t         level;
    uint32_t        fps_num;
    uint32_t        fps_den;

    // Frame reordering & POC state
    int32_t         poc;
    int32_t         poc_msb;
    int32_t         prev_poc_lsb;
    int32_t         prev_poc_msb;
} BvcParserContext;

/**
 * @brief Create and initialize a new BVC parser instance.
 *        Khởi tạo thể hiện bộ phân tích cú pháp ByteVC1.
 */
BvcParserContext* bvc_parser_create(void);

/**
 * @brief Parse a raw bitstream buffer, updating parameter sets and slice headers.
 *        Phân tích dòng byte thô, cập nhật bảng tham số và phân đoạn khung hình.
 */
int bvc_parser_parse(BvcParserContext* ctx, const uint8_t* buf, size_t size);

/**
 * @brief Parse a single Slice Header and compute Picture Order Count (POC).
 *        Phân tích tiêu đề một phân đoạn khung hình và tính toán POC.
 */
int bvc_parser_parse_slice_header(BvcParserContext* ctx, GetBitContext* gb, int nal_type, BVC1SliceHeader* sh);

/**
 * @brief Destroy parser context and free allocated parameter set buffers.
 *        Hủy giải phóng ngữ cảnh bộ phân tích cú pháp.
 */
void bvc_parser_destroy(BvcParserContext* ctx);

/**
 * @brief Register BVC parser and bitstream filters into TTFFmpeg core.
 *        Đăng ký bộ phân giải ByteVC1 và các bộ lọc vào lõi TTFFmpeg (Khớp VAddr 0x000076d4).
 */
void register_bvcparser(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_PARSER_H
