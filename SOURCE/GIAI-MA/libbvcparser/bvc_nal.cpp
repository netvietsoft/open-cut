/**
 * @file bvc_nal.cpp
 * @brief ByteDance BVC NAL Unit Parsing & Start Code Extraction Implementation.
 *        Hiện thực bóc tách khối NAL Unit và phát hiện mã bắt đầu của ByteVC1.
 */

#include "bvc_nal.h"
#include "bvc_bitstream.h"
#include <stdlib.h>
#include <string.h>

const uint8_t* bvc_find_start_code(const uint8_t* p, const uint8_t* end, uint32_t* state) {
    uint32_t s = *state;
    while (p < end) {
        s = (s << 8) | *p++;
        if ((s & 0x00FFFFFF) == 0x000001) {
            *state = s;
            return p;
        }
    }
    *state = s;
    return end;
}

int bvc_parse_nal_header(const uint8_t* src, size_t size, int* nal_type, int* layer_id, int* temporal_id) {
    if (!src || size < 2) return -1;

    // HEVC / ByteVC1 NAL header is 2 bytes (16 bits)
    // Tiêu đề NAL Unit của ByteVC1 / HEVC gồm 2 byte (16 bit)
    // forbidden_zero_bit (1 bit) | nal_unit_type (6 bits) | nuh_layer_id (6 bits) | nuh_temporal_id_plus1 (3 bits)
    uint8_t b0 = src[0];
    uint8_t b1 = src[1];

    if ((b0 & 0x80) != 0) {
        return -2; // forbidden_zero_bit must be 0
    }

    int type = (b0 >> 1) & 0x3F;
    int layer = ((b0 & 1) << 5) | (b1 >> 3);
    int tid = (b1 & 0x07) - 1;

    if (nal_type) *nal_type = type;
    if (layer_id) *layer_id = layer;
    if (temporal_id) *temporal_id = tid;

    return 0;
}

int bvc_extract_packet_nals(const uint8_t* buf, size_t size, BVC1PacketNals* out_nals) {
    if (!buf || size == 0 || !out_nals) return -1;

    memset(out_nals, 0, sizeof(BVC1PacketNals));
    out_nals->rbsp_buffer = (uint8_t*)malloc(size + 64);
    if (!out_nals->rbsp_buffer) return -1;
    out_nals->rbsp_buffer_size = size + 64;

    const uint8_t* p = buf;
    const uint8_t* end = buf + size;
    uint32_t state = 0xFFFFFFFF;

    // Find first start code
    p = bvc_find_start_code(p, end, &state);
    if (p >= end) {
        free(out_nals->rbsp_buffer);
        out_nals->rbsp_buffer = NULL;
        return 0; // No start code found
    }

    size_t rbsp_write_offset = 0;

    while (p < end && out_nals->nal_count < BVC_MAX_NALS_IN_PACKET) {
        const uint8_t* nal_start = p;
        state = 0xFFFFFFFF;
        p = bvc_find_start_code(p, end, &state);

        const uint8_t* nal_end = (p < end) ? (p - 3) : end;
        if (nal_end > nal_start && (nal_end - nal_start) >= 2) {
            size_t raw_nal_size = (size_t)(nal_end - nal_start);

            int nal_type = 0, layer_id = 0, temporal_id = 0;
            if (bvc_parse_nal_header(nal_start, raw_nal_size, &nal_type, &layer_id, &temporal_id) == 0) {
                BVC1Nal* nal = &out_nals->nals[out_nals->nal_count];
                nal->type = nal_type;
                nal->temporal_id = temporal_id;

                // Strip emulation prevention bytes from payload into rbsp buffer
                // Loại bỏ byte chống trùng lặp vào bộ đệm RBSP
                uint8_t* dst_ptr = out_nals->rbsp_buffer + rbsp_write_offset;
                size_t dst_len = 0;
                bvc_remove_emulation_bytes(nal_start + 2, raw_nal_size - 2, dst_ptr, &dst_len, NULL, 0);

                nal->data = dst_ptr;
                nal->size = dst_len;
                nal->skipped_bytes = (raw_nal_size - 2) - dst_len;
                nal->Bvc1SkippedBytesPosSize = nal->skipped_bytes + 16;

                rbsp_write_offset += dst_len;
                out_nals->nal_count++;
            }
        }
    }

    return out_nals->nal_count;
}

void bvc_free_packet_nals(BVC1PacketNals* pnals) {
    if (!pnals) return;
    if (pnals->rbsp_buffer) {
        free(pnals->rbsp_buffer);
        pnals->rbsp_buffer = NULL;
    }
    pnals->nal_count = 0;
}
