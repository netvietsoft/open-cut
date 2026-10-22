/**
 * @file bvc_sps.h
 * @brief ByteDance BVC Sequence Parameter Set (SPS) Decoding Interface.
 *        Giao diện giải mã cấu trúc Sequence Parameter Set (SPS) của ByteVC1.
 */

#ifndef BYTEDANCE_BVC_SPS_H
#define BYTEDANCE_BVC_SPS_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Decode BVC1 / HEVC Sequence Parameter Set (SPS) from bitstream.
 *        Giải mã khối cấu hình Sequence Parameter Set (SPS) từ luồng bit.
 */
int bvc1_decode_sps(GetBitContext* gb, BVC1SPS* sps);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_SPS_H
