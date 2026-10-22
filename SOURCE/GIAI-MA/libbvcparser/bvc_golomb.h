/**
 * @file bvc_golomb.h
 * @brief ByteDance BVC Exp-Golomb Bitstream Decoding Interface.
 *        Giao diện giải mã mã hình Exp-Golomb cho luồng video ByteVC1 / HEVC.
 */

#ifndef BYTEDANCE_BVC_GOLOMB_H
#define BYTEDANCE_BVC_GOLOMB_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Read Unsigned Exp-Golomb code from bitstream (ue(v)).
 *        Đọc mã Exp-Golomb không dấu từ luồng bit (Khớp VAddr 0x000075f4).
 * @param gb Pointer to GetBitContext bitstream reader
 * @return Decoded unsigned 32-bit integer value
 */
uint32_t bvc_get_ue_golomb(GetBitContext* gb);

/**
 * @brief Read Signed Exp-Golomb code from bitstream (se(v)).
 *        Đọc mã Exp-Golomb có dấu từ luồng bit (Khớp VAddr 0x00007538).
 * @param gb Pointer to GetBitContext bitstream reader
 * @return Decoded signed 32-bit integer value
 */
int32_t bvc_get_se_golomb(GetBitContext* gb);

/**
 * @brief Read Truncated Exp-Golomb code (te(v)).
 *        Đọc mã Exp-Golomb cắt cụt (te(v)) với giới hạn cận trên.
 */
uint32_t bvc_get_te_golomb(GetBitContext* gb, int range);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_GOLOMB_H
