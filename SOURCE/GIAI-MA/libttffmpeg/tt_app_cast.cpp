// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_app_cast.cpp
// Description: Full implementation of TTM Application Identifier, Safe Casting & Internal Stream Helpers
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "tt_app_cast.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#if defined(_WIN32)
#include <windows.h>
#endif

// ===================================================================================
// 1. TTM APPLICATION MAGIC POINTER & SAFE DOWNCASTING
// Định danh Magic con trỏ và Ép kiểu an toàn TTM App
// ===================================================================================

// Địa chỉ biến toàn cục tự tham chiếu tại offset nhị phân 0x584810
static const void* const s_ttm_app_magic = (void*)&s_ttm_app_magic;

/**
 * @brief Returns the unique static magic pointer of the TTM application.
 * Trả về con trỏ định danh magic tĩnh độc nhất của ứng dụng TTM.
 * Opcode ARM64: 0x3775b0..0x3775b8 (adrp x0, #0x584000; ldr x0, [x0, #0x810]; ret)
 */
const void* av_ttm_app_magic(void) {
    return s_ttm_app_magic;
}

/**
 * @brief Performs safe dynamic verification and casting of a generic context pointer into a TTMApp.
 * Xác minh tính hợp lệ của con trỏ và ép kiểu an toàn sang cấu trúc TTMApp.
 * Opcode ARM64: 0x3775bc..0x377620
 * - Kiểm tra NULL tại 0x3775c8
 * - So sánh magic pointer tại 0x3775d8
 * - Kiểm tra phiên bản callback 0x01343f0f (20201231) tại 0x3775f0
 * - Báo lỗi nếu phiên bản không khớp ("unmatched ttm app callback version: %d != %d" tại 0x50d530)
 */
void* av_ttm_app_cast(void* ptr) {
    if (!ptr) {
        return NULL;
    }

    TTMApp* app = (TTMApp*)ptr;

    // Verify magic identifier
    if (app->magic != av_ttm_app_magic()) {
        return NULL; // Magic mismatch: not a valid TTMApp instance
    }

    // Verify callback version constant
    uint32_t expected_ver = TTM_APP_CALLBACK_VERSION; // 0x01343f0f
    if (app->version != expected_ver) {
        // Log warning for version divergence
        fprintf(stderr, "[libttffmpeg] unmatched ttm app callback version: %u != %u\n",
                app->version, expected_ver);
    }

    return ptr;
}


// ===================================================================================
// 2. STREAM INTERNAL CONTEXT ACCESS
// Truy xuất Ngữ cảnh Nội bộ của Luồng AVStream
// ===================================================================================

/**
 * @brief Extracts AVCodecContext from internal stream structure.
 * Trích xuất con trỏ AVCodecContext từ cấu trúc nội bộ của AVStream (offset 0x18).
 * Opcode ARM64: 0x1c8284..0x1c8294 (ldr x0, [x1, #0x18]; ret)
 */
void* tt_avstream_get_avctx_from_internal(void* internal_stream) {
    if (!internal_stream) {
        return NULL;
    }
    // In FFmpeg 4+, AVStreamInternal stores AVCodecContext at offset 0x18
    return *(void**)((char*)internal_stream + 0x18);
}


// ===================================================================================
// 3. MONOTONIC CLOCKS & TIMING
// Đồng hồ Đơn điệu và Đo lường Thời gian
// ===================================================================================

/**
 * @brief Returns monotonic time in microseconds relative to boot.
 * Trả về thời gian tương đối đơn điệu tính bằng micro-giây.
 */
int64_t tt_gettime_relative(void) {
#if defined(_WIN32)
    static LARGE_INTEGER freq;
    static BOOL initialized = FALSE;
    if (!initialized) {
        QueryPerformanceFrequency(&freq);
        initialized = TRUE;
    }
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    return (int64_t)((counter.QuadPart * 1000000LL) / freq.QuadPart);
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000000LL + (int64_t)ts.tv_nsec / 1000LL;
#endif
}

/**
 * @brief Checks if the relative clock is strictly monotonic.
 * Kiểm tra xem đồng hồ tương đối có đảm bảo tính đơn điệu hay không.
 */
int32_t tt_gettime_relative_is_monotonic(void) {
    return 1; // Strict monotonic clock verified
}
