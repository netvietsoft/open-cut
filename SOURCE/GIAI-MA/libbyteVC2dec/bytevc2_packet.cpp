/**
 * @file bytevc2_packet.cpp
 * @brief Input Compressed Packet Management Implementation
 *        Thực thi quản lý gói nén bitstream đầu vào
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x004c70, 0x004c78, 0x02fa30, 0x02fb4c, 0x02fba4.
 * Tái cấu trúc dựa trên disassembly ARM64 tại VAddr 0x004c70, 0x004c78, 0x02fa30, 0x02fb4c, 0x02fba4.
 */

#include "bytevc2_packet.h"
#include <stdlib.h>
#include <string.h>

ByteVC2Packet* byteVC2dec_alloc_packet(void) {
    // Opcode at 0x004c70: mov w0, #0x38; b malloc
    ByteVC2Packet* pkt = (ByteVC2Packet*)calloc(1, sizeof(ByteVC2Packet));
    return pkt;
}

void byteVC2dec_release_packet(ByteVC2Packet* packet) {
    if (packet) {
        free(packet);
    }
}

int32_t byteVC2dec_set_packet_integer_info(ByteVC2Packet* packet, const char* key, int64_t value) {
    if (!packet || !key) {
        return -1;
    }

    // Offset 0x04: bs_len
    if (strncmp(key, "bs_len", 7) == 0) {
        packet->bs_len = (int32_t)value;
        return 0;
    }

    // Offset 0x00: flag
    if (strncmp(key, "flag", 5) == 0) {
        packet->flag = (int32_t)value;
        return 0;
    }

    // Offset 0x10: drop_frame
    if (strncmp(key, "drop_frame", 11) == 0) {
        packet->drop_frame = (int32_t)value;
        return 0;
    }

    // Offset 0x18: pts
    if (strncmp(key, "pts", 4) == 0) {
        packet->pts = value;
        return 0;
    }

    // Offset 0x20: opt
    if (strncmp(key, "opt", 4) == 0) {
        packet->opt = value;
        return 0;
    }

    // Offset 0x28: simp
    if (strncmp(key, "simp", 5) == 0) {
        packet->simp = value;
        return 0;
    }

    // Offset 0x30: wait_frame
    if (strncmp(key, "wait_frame", 11) == 0) {
        packet->wait_frame = (int32_t)value;
        return 0;
    }

    return -1;
}

int32_t byteVC2dec_set_packet_float_info(ByteVC2Packet* packet, const char* key, float value) {
    if (!packet || !key) {
        return -1;
    }

    // Offset 0x14: drop_rate
    if (strncmp(key, "drop_rate", 10) == 0) {
        packet->drop_rate = value;
        return 0;
    }

    return -1;
}

int32_t byteVC2dec_set_packet_pointer_info(ByteVC2Packet* packet, const char* key, void* ptr) {
    if (!packet || !key) {
        return -1;
    }

    // Offset 0x08: bs
    if (strncmp(key, "bs", 3) == 0) {
        packet->bs = (uint8_t*)ptr;
        return 0;
    }

    return -1;
}
