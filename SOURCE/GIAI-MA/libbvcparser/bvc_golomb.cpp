/**
 * @file bvc_golomb.cpp
 * @brief ByteDance BVC Exp-Golomb Bitstream Decoding Implementation.
 *        Hiện thực giải mã mã hình Exp-Golomb cho luồng video ByteVC1 / HEVC.
 */

#include "bvc_golomb.h"
#include <stdio.h>
#include <stdlib.h>

// 32-entry lookup tables for top 5 bits matching binary addresses 0x8d4c and 0x8f4c
// Bảng tra cứu 32 phần tử cho 5 bit cao nhất khớp chính xác địa chỉ 0x8d4c và 0x8f4c trong .rodata
static const uint8_t ff_ue_golomb_vlc_code[32] = {
    0, 0, 0, 0, 0, 0, 0, 0, // 00000 - 00111 (zeros >= 3)
    3, 3, 3, 3,             // 01000 - 01011
    2, 2, 2, 2,             // 01100 - 01111
    1, 1, 1, 1, 1, 1, 1, 1, // 10000 - 10111
    0, 0, 0, 0, 0, 0, 0, 0  // 11000 - 11111
};

static const uint8_t ff_ue_golomb_len[32] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    5, 5, 5, 5,
    3, 3, 3, 3,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1
};

static const int8_t ff_se_golomb_vlc_code[32] = {
    0,  0,  0,  0,  0,  0,  0,  0,
    -2, 2, -2,  2,
    -1, 1, -1,  1,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0
};

// Fast 32-bit big-endian word fetcher matching ARM64 rev w8, w8 and lsl w0, w8, w9
// Hàm nạp từ 32-bit big-endian khớp mã máy ARM64 rev w8, w8 và dịch bit lsl
static inline uint32_t bvc_show_bits32(GetBitContext* gb) {
    if (gb->index >= gb->size_in_bits) {
        return 0;
    }
    int byte_pos = gb->index >> 3;
    int bit_offset = gb->index & 7;

    const uint8_t* ptr = gb->buffer + byte_pos;
    uint32_t val = ((uint32_t)ptr[0] << 24) |
                   ((uint32_t)ptr[1] << 16) |
                   ((uint32_t)ptr[2] << 8)  |
                   ((uint32_t)ptr[3]);
    return val << bit_offset;
}

uint32_t bvc_get_ue_golomb(GetBitContext* gb) {
    if (!gb || gb->index >= gb->size_in_bits) {
        return 0;
    }

    // Read top 32 bits from current position
    // Đọc 32 bit cao từ vị trí hiện tại
    uint32_t buf = bvc_show_bits32(gb);
    uint32_t top5 = buf >> 27;

    // Fast path: use 5-bit lookup table if leading bit is found early
    // Nhánh nhanh: sử dụng bảng tra cứu 5-bit nếu bit 1 xuất hiện sớm
    if (top5 != 0) {
        int len = ff_ue_golomb_len[top5];
        if (len > 0) {
            uint32_t code = ff_ue_golomb_vlc_code[top5];
            gb->index += len;
            if (gb->index > gb->size_in_bits) {
                gb->index = gb->size_in_bits;
            }
            return code;
        }
    }

    // Slow path: count leading zeros (CLZ)
    // Nhánh xử lý đầy đủ: đếm số lượng bit 0 dẫn đầu
    int leading_zeros = 0;
    while (gb->index < gb->size_in_bits) {
        int byte_idx = gb->index >> 3;
        int bit_idx = 7 - (gb->index & 7);
        gb->index++;
        if ((gb->buffer[byte_idx] >> bit_idx) & 1) {
            break;
        }
        leading_zeros++;
        if (leading_zeros >= 32) {
            return 0; // Invalid bitstream code
        }
    }

    if (leading_zeros == 0) {
        return 0;
    }

    // Read following 'leading_zeros' bits
    // Đọc tiếp 'leading_zeros' bit tiếp theo
    uint32_t info = 0;
    for (int i = 0; i < leading_zeros; ++i) {
        if (gb->index >= gb->size_in_bits) break;
        int byte_idx = gb->index >> 3;
        int bit_idx = 7 - (gb->index & 7);
        gb->index++;
        info = (info << 1) | ((gb->buffer[byte_idx] >> bit_idx) & 1);
    }

    return (1U << leading_zeros) - 1U + info;
}

int32_t bvc_get_se_golomb(GetBitContext* gb) {
    if (!gb || gb->index >= gb->size_in_bits) {
        return 0;
    }

    // Fast path: 5-bit lookup
    uint32_t buf = bvc_show_bits32(gb);
    uint32_t top5 = buf >> 27;
    if (top5 != 0) {
        int len = ff_ue_golomb_len[top5];
        if (len > 0) {
            int32_t code = (int32_t)ff_se_golomb_vlc_code[top5];
            gb->index += len;
            if (gb->index > gb->size_in_bits) {
                gb->index = gb->size_in_bits;
            }
            return code;
        }
    }

    // Mathematical relation: Signed Exp-Golomb derived from Unsigned Exp-Golomb
    // Công thức toán học ánh xạ có dấu từ ue: (-1)^(k+1) * ceil(k/2)
    uint32_t ue = bvc_get_ue_golomb(gb);
    int32_t sign = (ue & 1) ? 1 : -1;
    int32_t val = (int32_t)((ue + 1) >> 1);
    return sign * val;
}

uint32_t bvc_get_te_golomb(GetBitContext* gb, int range) {
    if (range <= 1) {
        return 0;
    }
    if (range == 2) {
        if (gb->index < gb->size_in_bits) {
            int byte_idx = gb->index >> 3;
            int bit_idx = 7 - (gb->index & 7);
            gb->index++;
            return !((gb->buffer[byte_idx] >> bit_idx) & 1);
        }
        return 0;
    }
    return bvc_get_ue_golomb(gb);
}
