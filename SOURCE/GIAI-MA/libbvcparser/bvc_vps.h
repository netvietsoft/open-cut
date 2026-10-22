/**
 * @file bvc_vps.h
 * @brief ByteDance BVC Video Parameter Set (VPS) Decoding Interface.
 *        Giao diện giải mã cấu trúc Video Parameter Set (VPS) của ByteVC1.
 */

#ifndef BYTEDANCE_BVC_VPS_H
#define BYTEDANCE_BVC_VPS_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Decode BVC1 / HEVC Video Parameter Set (VPS) from bitstream.
 *        Giải mã khối cấu hình Video Parameter Set (VPS) từ luồng bit.
 */
int bvc1_decode_vps(GetBitContext* gb, BVC1VPS* vps);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_VPS_H
