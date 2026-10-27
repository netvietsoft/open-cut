// ============================================================================
// File: orbuculum_jni_validator.h
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for .init_array[0..7] (0x01c190..0x01ca94),
//        orbuculumValidateDataFlowId (0x01cb9c), JNI_OnLoad (0x01d6b4),
//        TTPOrbuNetworkCaller JNI methods (0x01d9e4..0x02265c),
//        orbuculumProceedRequest (0x01fbe8), and FDEs 0..199.
//   [VN] Khai báo C++17 sạch cho .init_array[0..7], orbuculumValidateDataFlowId,
//        JNI_OnLoad, 11 hàm JNI TTPOrbuNetworkCaller, orbuculumProceedRequest và FDE 0..199.
// ============================================================================

#pragma once

#include "orbuculum_types.h"

namespace ttp {
namespace orbuculum {
namespace jni {

bool ValidateDataFlowIdHeaderValue(const char* raw_value, int64_t* out_parsed_id) noexcept;
uint64_t DispatchJniValidatorFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace jni
} // namespace orbuculum
} // namespace ttp
