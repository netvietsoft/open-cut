/**
 * @file bytevc2_frame.cpp
 * @brief Decoded Picture Frame Buffer Management Implementation
 *        Thực thi quản lý đệm khung hình đã giải mã
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x004b4c, 0x004bac, 0x02f704, 0x004be0, 0x004be8.
 * Tái cấu trúc dựa trên disassembly ARM64 tại VAddr 0x004b4c, 0x004bac, 0x02f704, 0x004be0, 0x004be8.
 */

#include "bytevc2_frame.h"
#include <stdlib.h>
#include <string.h>

ByteVC2Frame* byteVC2dec_alloc_frame(void) {
    // Opcode at 0x004b4c:
    // mov w0, #0x90; bl malloc (allocates 144-byte frame container)
    ByteVC2Frame* frame = (ByteVC2Frame*)calloc(1, sizeof(ByteVC2Frame));
    if (!frame) {
        return NULL;
    }

    // mov w0, #0xe0; bl malloc (allocates 224-byte internal metadata)
    frame->internal_info = (ByteVC2FrameInfoInternal*)calloc(1, sizeof(ByteVC2FrameInfoInternal));
    if (!frame->internal_info) {
        free(frame);
        return NULL;
    }

    // Initialize defaults: bit_depth=8, YUV420P
    frame->bit_depth = 8;
    frame->pix_fmt = (uint8_t)BYTEVC2_PIX_FMT_YUV420P;
    frame->got_frame = 0;

    return frame;
}

void byteVC2dec_release_frame(ByteVC2Frame* frame) {
    if (!frame) {
        return;
    }

    // Release allocated planar pixel buffers
    for (int i = 0; i < 3; i++) {
        if (frame->data[i]) {
            free(frame->data[i]);
            frame->data[i] = NULL;
        }
    }

    if (frame->internal_info) {
        free(frame->internal_info);
        frame->internal_info = NULL;
    }

    free(frame);
}

int32_t bytevc2_frame_alloc_buffers(ByteVC2Frame* frame, int32_t width, int32_t height, ByteVC2PixelFormat pix_fmt) {
    if (!frame || width <= 0 || height <= 0) {
        return -1;
    }

    frame->width = width;
    frame->height = height;
    frame->pix_fmt = (uint8_t)pix_fmt;

    // Align stride to 64 bytes for SIMD operations
    int32_t y_stride = (width + 63) & ~63;
    int32_t c_stride = ((width / 2) + 63) & ~63;

    frame->stride[0] = y_stride;
    frame->stride[1] = c_stride;
    frame->stride[2] = c_stride;

    frame->linesize[0] = width;
    frame->linesize[1] = width / 2;
    frame->linesize[2] = width / 2;

    size_t y_size = (size_t)y_stride * height;
    size_t c_size = (size_t)c_stride * (height / 2);

    for (int i = 0; i < 3; i++) {
        if (frame->data[i]) {
            free(frame->data[i]);
            frame->data[i] = NULL;
        }
    }

    frame->data[0] = (uint8_t*)calloc(1, y_size);
    frame->data[1] = (uint8_t*)calloc(1, c_size);
    frame->data[2] = (uint8_t*)calloc(1, c_size);

    if (!frame->data[0] || !frame->data[1] || !frame->data[2]) {
        for (int i = 0; i < 3; i++) {
            if (frame->data[i]) {
                free(frame->data[i]);
                frame->data[i] = NULL;
            }
        }
        return -1;
    }

    return 0;
}

int64_t byteVC2dec_get_frame_integer_info(const ByteVC2Frame* frame, const char* key, int32_t plane_index) {
    if (!frame || !key) {
        return 0;
    }

    // Key: "stride"
    if (strncmp(key, "stride", 7) == 0) {
        if (plane_index >= 0 && plane_index < 3) {
            return frame->stride[plane_index];
        }
        return 0;
    }

    // Key: "linesize"
    if (strncmp(key, "linesize", 9) == 0) {
        if (plane_index >= 0 && plane_index < 3) {
            return frame->linesize[plane_index];
        }
        return 0;
    }

    // Key: "width"
    if (strncmp(key, "width", 6) == 0) {
        return frame->width;
    }

    // Key: "height"
    if (strncmp(key, "height", 7) == 0) {
        return frame->height;
    }

    // Key: "pts"
    if (strncmp(key, "pts", 4) == 0) {
        return frame->pts;
    }

    // Key: "opt"
    if (strncmp(key, "opt", 4) == 0) {
        return frame->opt;
    }

    // Key: "simp"
    if (strncmp(key, "simp", 5) == 0) {
        return frame->simp;
    }

    // Key: "bit_depth"
    if (strncmp(key, "bit_depth", 10) == 0) {
        return frame->bit_depth;
    }

    // Key: "color_info_present_flag"
    if (strncmp(key, "color_info_present_flag", 24) == 0) {
        return frame->color_info_present_flag;
    }

    // Key: "video_full_range_flag"
    if (strncmp(key, "video_full_range_flag", 22) == 0) {
        return frame->video_full_range_flag;
    }

    // Key: "color_primaries"
    if (strncmp(key, "color_primaries", 16) == 0) {
        return frame->color_primaries;
    }

    // Key: "color_trc"
    if (strncmp(key, "color_trc", 10) == 0) {
        return frame->color_trc;
    }

    // Key: "color_space"
    if (strncmp(key, "color_space", 12) == 0) {
        return frame->color_space;
    }

    // Key: "key_frame"
    if (strncmp(key, "key_frame", 10) == 0) {
        return frame->key_frame;
    }

    // Key: "pix_fmt"
    if (strncmp(key, "pix_fmt", 8) == 0) {
        return frame->pix_fmt;
    }

    // Key: "got_frame"
    if (strncmp(key, "got_frame", 10) == 0) {
        return frame->got_frame;
    }

    // Key: "poc"
    if (strncmp(key, "poc", 4) == 0) {
        return frame->poc;
    }

    // Key: "finished_frame_num"
    if (strncmp(key, "finished_frame_num", 19) == 0) {
        return frame->finished_frame_num;
    }

    // Key: "decodable_frame_num"
    if (strncmp(key, "decodable_frame_num", 20) == 0) {
        return frame->decodable_frame_num;
    }

    return 0;
}

float byteVC2dec_get_frame_float_info(const ByteVC2Frame* frame, const char* key) {
    (void)frame;
    (void)key;
    // Opcode at 0x004be0: fmov d0, xzr; ret
    return 0.0f;
}

void* byteVC2dec_get_frame_pointer_info(const ByteVC2Frame* frame, const char* key, int32_t plane_index) {
    if (!frame || !key) {
        return NULL;
    }

    // Key: "data" -> returns plane buffer pointer
    if (strncmp(key, "data", 5) == 0) {
        if (plane_index >= 0 && plane_index < 3) {
            return frame->data[plane_index];
        }
        return NULL;
    }

    // Key: "hardware_buffer" -> returns AHardwareBuffer*
    if (strncmp(key, "hardware_buffer", 16) == 0) {
        return frame->hardware_buffer;
    }

    return NULL;
}
