/**
 * @file bvc_nal.h
 * @brief ByteDance BVC NAL Unit Parsing & Start Code Extraction Interface.
 *        Giao diện bóc tách khối NAL Unit và phát hiện mã bắt đầu của ByteVC1.
 */

#ifndef BYTEDANCE_BVC_NAL_H
#define BYTEDANCE_BVC_NAL_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BVC_MAX_NALS_IN_PACKET 64

typedef struct {
    BVC1Nal  nals[BVC_MAX_NALS_IN_PACKET];
    int      nal_count;
    uint8_t* rbsp_buffer;
    size_t   rbsp_buffer_size;
} BVC1PacketNals;

/**
 * @brief Scan buffer for next start code (0x000001 or 0x00000001).
 *        Quét bộ đệm tìm mã bắt đầu tiếp theo (3-byte hoặc 4-byte).
 */
const uint8_t* bvc_find_start_code(const uint8_t* p, const uint8_t* end, uint32_t* state);

/**
 * @brief Parse NAL header (forbidden_zero_bit, nal_unit_type, nuh_layer_id, nuh_temporal_id_plus1).
 *        Phân tích tiêu đề 2-byte NAL Unit của ByteVC1 / HEVC.
 */
int bvc_parse_nal_header(const uint8_t* src, size_t size, int* nal_type, int* layer_id, int* temporal_id);

/**
 * @brief Extract all NAL units contained within an input packet.
 *        Bóc tách toàn bộ các khối NAL Unit có trong gói tin đầu vào.
 */
int bvc_extract_packet_nals(const uint8_t* buf, size_t size, BVC1PacketNals* out_nals);

/**
 * @brief Free resources associated with parsed packet NALs.
 *        Giải phóng bộ đệm và tài nguyên của gói tin NALs.
 */
void bvc_free_packet_nals(BVC1PacketNals* pnals);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_NAL_H
