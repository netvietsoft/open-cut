// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Library: libttffmpeg.so (ByteDance Customized High-Performance FFmpeg Core)
// File: ttffmpeg_interface.h
// Description: Unified C/C++ Interface for ByteDance Customized FFmpeg Engine
// Bilingual Documentation: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#pragma once

#include "ttffmpeg_types.h"
#include "tt_h264_parser.h"
#include "tt_protocol_registry.h"
#include "tt_drm_crypto.h"
#include "tt_app_cast.h"

#ifdef __cplusplus
extern "C" {
#endif

// ===================================================================================
// 1. ENGINE INITIALIZATION & LIFECYCLE
// Khởi tạo và Quản lý Vòng đời Engine
// ===================================================================================

/**
 * @brief Initializes the ByteDance TTFFmpeg engine and registers all proprietary components.
 * Khởi tạo toàn bộ hệ thống TTFFmpeg tùy biến của ByteDance và nạp các thành phần độc quyền.
 * @return 0 on success, negative error code on failure.
 */
int32_t ttffmpeg_engine_init(void);

/**
 * @brief Shuts down the TTFFmpeg engine and cleans up registered memory tables.
 * Đóng và dọn dẹp toàn bộ tài nguyên của engine TTFFmpeg.
 */
void ttffmpeg_engine_shutdown(void);

// ===================================================================================
// 2. SUMMARY OF RECOVERED SUBSYSTEMS (TỔNG HỢP CÁC PHÂN HỆ ĐÃ PHỤC HỒI)
// ===================================================================================
// 1. H.264/H.265 Parameter Sets (SPS, PPS) & POC Context Tracking (44 bytes context)
// 2. High-Speed Bitstream MMCO == 5 Reset Detection for Instantaneous Seeking
// 3. 7 ByteDance Custom Network Protocols (mdl, quic, httpx, mem, live, hlsproxy, memorydatasource)
// 4. TTNet DNS & IO Hook Table (0x7be350) + SSL Certificate Pinning Verification (0x7be348)
// 5. Custom ByteDance DRM Decryption Interface (0x7c57d0) + GF(2^8) S-box Stream Cipher (0x11b)
// 6. TTM Application Bridge & Safe Downcasting (0x584810 magic & version 0x01343f0f)

#ifdef __cplusplus
}
#endif
