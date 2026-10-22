/**
 * @file bvc_bsf.cpp
 * @brief ByteDance BVC Bitstream Filters Implementation.
 *        Hiện thực các bộ lọc luồng bit chuyển đổi container MP4 sang Annex B của ByteVC2/VVC.
 */

#include "bvc_bsf.h"
#include <string.h>

int bytevc2_mp4toannexb_filter(BvcMp4ToAnnexbContext* ctx,
                               const uint8_t* in_data, size_t in_size,
                               uint8_t* out_data, size_t out_capacity,
                               size_t* out_size) {
    if (!in_data || in_size == 0 || !out_data || !out_size) {
        return -1;
    }

    // Check if input is already in Annex B format (starts with 0x000001 or 0x00000001)
    // Kiểm tra xem dòng vào đã có sẵn định dạng Annex B hay chưa
    if (in_size >= 4 && in_data[0] == 0 && in_data[1] == 0 &&
        (in_data[2] == 1 || (in_data[2] == 0 && in_data[3] == 1))) {
        // "The input looks like it is Annex B already"
        if (in_size > out_capacity) return -2;
        memcpy(out_data, in_data, in_size);
        *out_size = in_size;
        return 0;
    }

    int length_size = (ctx && ctx->length_size > 0) ? ctx->length_size : 4;
    size_t in_pos = 0;
    size_t out_pos = 0;

    while (in_pos + length_size <= in_size) {
        // Read big-endian NAL unit length
        // Đọc chiều dài NAL unit theo định dạng big-endian
        uint32_t nal_len = 0;
        for (int i = 0; i < length_size; ++i) {
            nal_len = (nal_len << 8) | in_data[in_pos++];
        }

        if (in_pos + nal_len > in_size) {
            break; // Truncated or invalid NAL unit size
        }

        // Check output space for 4-byte start code (0x00 0x00 0x00 0x01) + NAL payload
        // Kiểm tra không gian đầu ra cho 4 byte mã bắt đầu và thân NAL
        if (out_pos + 4 + nal_len > out_capacity) {
            return -3; // Output buffer too small
        }

        // Write 4-byte Annex B start code
        out_data[out_pos++] = 0x00;
        out_data[out_pos++] = 0x00;
        out_data[out_pos++] = 0x00;
        out_data[out_pos++] = 0x01;

        // Copy NAL payload
        memcpy(out_data + out_pos, in_data + in_pos, nal_len);
        out_pos += nal_len;
        in_pos += nal_len;
    }

    *out_size = out_pos;
    return 0;
}

int vvc_mp4toannexb_filter(BvcMp4ToAnnexbContext* ctx,
                           const uint8_t* in_data, size_t in_size,
                           uint8_t* out_data, size_t out_capacity,
                           size_t* out_size) {
    // VVC MP4 to Annex B filter shares identical length prefix conversion logic
    // Bộ lọc VVC chia sẻ giải thuật chuyển đổi tiền tố độ dài tương đương với ByteVC2
    return bytevc2_mp4toannexb_filter(ctx, in_data, in_size, out_data, out_capacity, out_size);
}
