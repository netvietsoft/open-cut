/**
 * @file bvc_bsf.h
 * @brief ByteDance BVC Bitstream Filters (bytevc2_mp4toannexb / vvc_mp4toannexb) Interface.
 *        Giao diện các bộ lọc luồng bit chuyển đổi container MP4 sang Annex B của ByteVC2/VVC.
 */

#ifndef BYTEDANCE_BVC_BSF_H
#define BYTEDANCE_BVC_BSF_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int   length_size;              ///< Length field size in MP4 container (typically 4 bytes)
    bool  extradata_parsed;         ///< True if VPS/SPS/PPS parameter sets were extracted
    uint8_t* extradata;             ///< Copy of codec extradata (HVCC / BVCC)
    int   extradata_size;
} BvcMp4ToAnnexbContext;

/**
 * @brief Filter a single packet from MP4 4-byte length prefix to Annex B 0x00000001 start codes.
 *        Chuyển đổi định dạng gói tin MP4 sang định dạng dòng byte Annex B (Khớp bytevc2_mp4toannexb).
 */
int bytevc2_mp4toannexb_filter(BvcMp4ToAnnexbContext* ctx,
                               const uint8_t* in_data, size_t in_size,
                               uint8_t* out_data, size_t out_capacity,
                               size_t* out_size);

/**
 * @brief Filter for VVC bitstream conversion.
 *        Bộ lọc chuyển đổi dòng bit chuẩn VVC (Khớp vvc_mp4toannexb).
 */
int vvc_mp4toannexb_filter(BvcMp4ToAnnexbContext* ctx,
                           const uint8_t* in_data, size_t in_size,
                           uint8_t* out_data, size_t out_capacity,
                           size_t* out_size);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_BSF_H
