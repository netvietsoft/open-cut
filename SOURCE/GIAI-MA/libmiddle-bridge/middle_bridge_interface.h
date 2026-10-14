// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Library: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_interface.h
// Description: Unified C/C++ Interface for Middle Bridge Video Editing Engine
// Bilingual Documentation: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#pragma once

#include "middle_bridge_types.h"
#include "middle_bridge_velocity.h"
#include "middle_bridge_mask.h"
#include "middle_bridge_composition.h"

#ifdef __cplusplus
extern "C" {
#endif

// ===================================================================================
// 1. ENGINE LIFECYCLE MANAGEMENT
// Khởi tạo và Quản lý Vòng đời Engine Middle Bridge
// ===================================================================================

/**
 * @brief Initializes the VE SDK Middle Bridge engine.
 * Khởi tạo lõi điều phối biên tập video VE SDK Middle Bridge.
 * @return 0 on success, negative error code on failure.
 */
int32_t middle_bridge_engine_init(void);

/**
 * @brief Shuts down the Middle Bridge engine and releases all allocated registries.
 * Đóng và dọn dẹp toàn bộ tài nguyên của engine Middle Bridge.
 */
void middle_bridge_engine_shutdown(void);

// ===================================================================================
// 2. PARITY VERIFICATION ROUTINES (CÁC HÀM KIỂM CHỨNG TỰ ĐỘNG)
// ===================================================================================

/**
 * @brief Verifies that Bezier speed curve calculation satisfies monotonic properties.
 */
bool middle_bridge_verify_velocity_parity(void);

/**
 * @brief Verifies that MaterialMask feathering and SDF distance calculation works accurately.
 */
bool middle_bridge_verify_mask_parity(void);

/**
 * @brief Verifies that CompositionReplace segment ID mapping functions as expected.
 */
bool middle_bridge_verify_composition_parity(void);

#ifdef __cplusplus
}
#endif
