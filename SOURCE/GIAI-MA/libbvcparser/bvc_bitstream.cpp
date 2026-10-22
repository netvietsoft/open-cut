/**
 * @file bvc_bitstream.cpp
 * @brief ByteDance BVC Bitstream Reader & Emulation Prevention Implementation.
 *        Hiện thực đọc luồng bit và loại bỏ byte chống trùng lặp mã bắt đầu.
 */

#include "bvc_bitstream.h"
#include <string.h>

int bvc_init_get_bits(GetBitContext* gb, const uint8_t* buffer, int bit_size) {
    if (!gb || !buffer || bit_size <= 0) {
        return -1;
    }
    gb->buffer = buffer;
    gb->buffer_end = buffer + ((bit_size + 7) >> 3);
    gb->index = 0;
    gb->size_in_bits = bit_size;
    return 0;
}

uint32_t bvc_get_bits(GetBitContext* gb, int n) {
    if (!gb || n <= 0 || n > 32) return 0;
    if (gb->index + n > gb->size_in_bits) {
        n = gb->size_in_bits - gb->index;
        if (n <= 0) return 0;
    }

    uint32_t val = 0;
    for (int i = 0; i < n; ++i) {
        int byte_idx = gb->index >> 3;
        int bit_idx = 7 - (gb->index & 7);
        gb->index++;
        val = (val << 1) | ((gb->buffer[byte_idx] >> bit_idx) & 1);
    }
    return val;
}

uint32_t bvc_get_bits1(GetBitContext* gb) {
    if (!gb || gb->index >= gb->size_in_bits) return 0;
    int byte_idx = gb->index >> 3;
    int bit_idx = 7 - (gb->index & 7);
    gb->index++;
    return (gb->buffer[byte_idx] >> bit_idx) & 1;
}

uint32_t bvc_show_bits(GetBitContext* gb, int n) {
    if (!gb || n <= 0 || n > 32) return 0;
    int save_index = gb->index;
    uint32_t val = bvc_get_bits(gb, n);
    gb->index = save_index;
    return val;
}

void bvc_skip_bits(GetBitContext* gb, int n) {
    if (!gb || n <= 0) return;
    gb->index += n;
    if (gb->index > gb->size_in_bits) {
        gb->index = gb->size_in_bits;
    }
}

int bvc_get_bits_left(GetBitContext* gb) {
    if (!gb) return 0;
    return (gb->index < gb->size_in_bits) ? (gb->size_in_bits - gb->index) : 0;
}

int bvc_remove_emulation_bytes(const uint8_t* src, size_t src_size,
                               uint8_t* dst, size_t* dst_size,
                               int* skipped_pos, size_t max_skipped_pos) {
    if (!src || !dst || !dst_size || src_size == 0) {
        return -1;
    }

    size_t si = 0;
    size_t di = 0;
    size_t skip_count = 0;

    // Scan for 0x00 0x00 0x03 sequence
    // Quét tìm chuỗi ba byte chống trùng lặp 0x00 0x00 0x03
    while (si < src_size) {
        if (si + 2 < src_size && src[si] == 0x00 && src[si + 1] == 0x00 && src[si + 2] == 0x03) {
            dst[di++] = 0x00;
            dst[di++] = 0x00;
            if (skipped_pos && skip_count < max_skipped_pos) {
                skipped_pos[skip_count++] = (int)di;
            }
            si += 3; // Skip emulation byte 0x03
        } else {
            dst[di++] = src[si++];
        }
    }

    *dst_size = di;
    return (int)skip_count;
}
