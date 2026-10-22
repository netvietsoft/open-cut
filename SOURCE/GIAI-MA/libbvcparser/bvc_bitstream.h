/**
 * @file bvc_bitstream.h
 * @brief ByteDance BVC Bitstream Reader & Emulation Prevention Interface.
 *        Giao diện đọc luồng bit và loại bỏ byte chống trùng lặp mã bắt đầu.
 */

#ifndef BYTEDANCE_BVC_BITSTREAM_H
#define BYTEDANCE_BVC_BITSTREAM_H

#include "bvc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize a GetBitContext structure with a byte buffer.
 *        Khởi tạo cấu trúc GetBitContext với bộ đệm mảng byte.
 */
int bvc_init_get_bits(GetBitContext* gb, const uint8_t* buffer, int bit_size);

/**
 * @brief Read up to 32 bits from bitstream and advance read pointer.
 *        Đọc tối đa 32 bit từ luồng và tịnh tiến con trỏ đọc.
 */
uint32_t bvc_get_bits(GetBitContext* gb, int n);

/**
 * @brief Read exactly 1 bit from bitstream.
 *        Đọc chính xác 1 bit từ luồng.
 */
uint32_t bvc_get_bits1(GetBitContext* gb);

/**
 * @brief Show up to 32 bits from bitstream without advancing read pointer.
 *        Xem trước tối đa 32 bit mà không làm thay đổi con trỏ đọc.
 */
uint32_t bvc_show_bits(GetBitContext* gb, int n);

/**
 * @brief Skip n bits in bitstream.
 *        Bỏ qua n bit trong luồng dữ liệu.
 */
void bvc_skip_bits(GetBitContext* gb, int n);

/**
 * @brief Return remaining unread bits in buffer.
 *        Trả về số bit chưa đọc còn lại trong bộ đệm.
 */
int bvc_get_bits_left(GetBitContext* gb);

/**
 * @brief Remove 0x000003 emulation prevention bytes from raw NAL payload.
 *        Loại bỏ các byte chống trùng lặp 0x000003 khỏi luồng NAL thô.
 */
int bvc_remove_emulation_bytes(const uint8_t* src, size_t src_size,
                               uint8_t* dst, size_t* dst_size,
                               int* skipped_pos, size_t max_skipped_pos);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_BVC_BITSTREAM_H
