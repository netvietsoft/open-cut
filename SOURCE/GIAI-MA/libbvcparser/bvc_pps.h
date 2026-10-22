/**
 * @file bvc_pps.h
 * @brief ByteDance BVC Picture Parameter Set (PPS) Decoding Interface.
 *        Giao diện giải mã cấu trúc Picture Parameter Set (PPS) của ByteVC1.
 */

#ifndef BYTEDANCE_BVC_PPS_H
#define BYTEDANCE_BVC_PPS_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Decode BVC1 / HEVC Picture Parameter Set (PPS) from bitstream.
 *        Giải mã khối cấu hình Picture Parameter Set (PPS) từ luồng bit.
 */
int bvc1_decode_pps(GetBitContext* gb, BVC1PPS* pps);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_PPS_H
