// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_app_cast.h
// Description: Header for TTM Application Identifier, Safe Casting & Internal Stream Helpers
// ===================================================================================

#pragma once

#include "ttffmpeg_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- TTM Application Bridge ---
const void* av_ttm_app_magic(void);
void* av_ttm_app_cast(void* ptr);

// --- Stream Internal Access ---
void* tt_avstream_get_avctx_from_internal(void* internal_stream);

// --- Time & Performance Monotonic Clocks ---
int64_t tt_gettime_relative(void);
int32_t tt_gettime_relative_is_monotonic(void);

#ifdef __cplusplus
}
#endif
