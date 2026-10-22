/**
 * @file bytevc2_param.cpp
 * @brief Decoder Parameter Configuration and Management Implementation
 *        Thực thi quản lý và cấu hình tham số giải mã
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x004c84, 0x004cc0, 0x02fbf0.
 * Tái cấu trúc dựa trên disassembly ARM64 tại VAddr 0x004c84, 0x004cc0, 0x02fbf0.
 */

#include "bytevc2_param.h"
#include "bytevc2_cpu.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ByteVC2Param* byteVC2dec_get_default_param(void) {
    ByteVC2Param* param = (ByteVC2Param*)calloc(1, sizeof(ByteVC2Param));
    if (!param) {
        return NULL;
    }

    // Default configuration matching ARM64 table at VAddr 0x73730
    param->max_pic_width       = 0;
    param->max_pic_height      = 1;
    param->max_parallel_frames = 0;
    param->threads             = 2;
    param->output_time         = -1;
    param->output_method       = -1;
    param->md5_check           = 8;
    param->wpp_mode            = 1;
    param->parallel_frames     = 8;
    
    // Auto-detect SIMD
    const ByteVC2CpuCaps* caps = bytevc2_get_cpu_caps();
    param->advanced_simd       = (caps->features & BYTEVC2_CPU_NEON) ? 1 : 0;
    param->hardware_buffer     = 0;

    return param;
}

void byteVC2dec_release_param(ByteVC2Param* param) {
    if (param) {
        free(param);
    }
}

void byteVC2dec_print_param(const ByteVC2Param* param) {
    if (!param) {
        return;
    }

    printf("BVC2 decoder param: max_pic_width %d, max_pic_height %d, max_parallel_frames %d, "
           "threads %d, parallel_frames %d, wpp_mode %d, output_method %d, md5_check %d, "
           "advanced_simd %d, hardware_buffer %d\n",
           param->max_pic_width,
           param->max_pic_height,
           param->max_parallel_frames,
           param->threads,
           param->parallel_frames,
           param->wpp_mode,
           param->output_method,
           param->md5_check,
           param->advanced_simd,
           param->hardware_buffer);
}

int32_t byteVC2dec_set_param_integer_info(ByteVC2Param* param, const char* key, int32_t value) {
    if (!param || !key) {
        return -1;
    }

    if (strncmp(key, "max_pic_width", 14) == 0) {
        param->max_pic_width = value;
        return 0;
    }
    if (strncmp(key, "max_pic_height", 15) == 0) {
        param->max_pic_height = value;
        return 0;
    }
    if (strncmp(key, "max_parallel_frames", 20) == 0) {
        param->max_parallel_frames = value;
        return 0;
    }
    if (strncmp(key, "threads", 8) == 0) {
        param->threads = (value > 0) ? value : 1;
        return 0;
    }
    if (strncmp(key, "parallel_frames", 16) == 0) {
        param->parallel_frames = value;
        return 0;
    }
    if (strncmp(key, "wpp_mode", 9) == 0) {
        param->wpp_mode = value;
        return 0;
    }
    if (strncmp(key, "output_method", 14) == 0) {
        param->output_method = value;
        return 0;
    }
    if (strncmp(key, "output_time", 12) == 0) {
        param->output_time = value;
        return 0;
    }
    if (strncmp(key, "md5_check", 10) == 0) {
        param->md5_check = value;
        return 0;
    }
    if (strncmp(key, "advanced_simd", 14) == 0) {
        param->advanced_simd = value;
        return 0;
    }
    if (strncmp(key, "hardware_buffer", 16) == 0) {
        param->hardware_buffer = value;
        return 0;
    }

    return -1; // Unrecognized parameter key / Khóa không xác định
}

int32_t byteVC2dec_set_param_float_info(ByteVC2Param* param, const char* key, float value) {
    (void)param;
    (void)key;
    (void)value;
    // Disassembly at 0x004d28: mov w0, #-1; ret
    return -1;
}

int32_t byteVC2dec_set_param_pointer_info(ByteVC2Param* param, const char* key, void* ptr) {
    (void)param;
    (void)key;
    (void)ptr;
    // Disassembly at 0x004d30: mov w0, #-1; ret
    return -1;
}
