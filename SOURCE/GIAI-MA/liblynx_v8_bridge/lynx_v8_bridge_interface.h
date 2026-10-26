// ============================================================================
// File: lynx_v8_bridge_interface.h
// Target: liblynx_v8_bridge.so (117,008 bytes, 26 ELF64 sections, 188 .dynsym)
// SHA-256: a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65
// Task ID: TASK-109-RECONSTRUCTION-LIBLYNX_V8_BRIDGE / TASK_SO_134_liblynx_v8_bridge
// Description:
//   [EN] Master C/C++17 public interface for liblynx_v8_bridge.so exposing all
//        6 exported .dynsym symbols ([179..185]) and all 7 internal V8/JSI/N-API
//        bridge subsystems with exact AArch64 binary offset annotations.
//   [VN] Giao diện công khai C/C++17 tổng thể cho liblynx_v8_bridge.so phơi bày
//        toàn bộ 6 biểu tượng xuất .dynsym ([179..185]) và 7 phân hệ cầu nối
//        V8/JSI/N-API nội bộ kèm chú thích địa chỉ nhị phân AArch64 chính xác.
// ============================================================================

#pragma once

#include "lynx_v8_bridge_types.h"
#include "lynx_v8_profiler_cache.h"
#include "lynx_v8_runtime.h"
#include "lynx_v8_napi_observer_jni.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// [EN] Exported .dynsym Symbol [183] @ 0x013590 (SZ=140): JNI_OnLoad
//      Registers LynxRuntimeHelperV8 (0x01c000) and NapiRuntimeProxyV8Factory
//      (0x01c008), logs "Setting napi factory from external" (0x0063aa),
//      and returns 0x00010006 (JNI_VERSION_1_6).
// [VN] Biểu tượng xuất .dynsym [183] tại 0x013590 (SZ=140): JNI_OnLoad
//      Đăng ký LynxRuntimeHelperV8 (0x01c000) và NapiRuntimeProxyV8Factory
//      (0x01c008), ghi nhật ký "Setting napi factory from external" (0x0063aa),
//      và trả về 0x00010006 (JNI_VERSION_1_6).
// ============================================================================
int32_t lynx_v8_bridge_JNI_OnLoad(void* vm, void* reserved);

// ============================================================================
// [EN] C-ABI Verification Entrypoint for Self-Test & Parity Suite
// [VN] Điểm vào xác minh C-ABI cho bộ kiểm thử tự động & đối sánh
// ============================================================================
int32_t lynx_v8_bridge_run_self_test(void);

#ifdef __cplusplus
} // extern "C"
#endif
