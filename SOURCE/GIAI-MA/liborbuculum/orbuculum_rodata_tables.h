// ============================================================================
// File: orbuculum_rodata_tables.h
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Read-only constants (.rodata 0x052090..0x053c61), SHA-256 K[64] & H0[8]
//        tables (0x0535e0..0x0536ff), .data constants (0x068010..0x068028), and 577 FDEs.
//   [VN] Bảng hằng số chỉ đọc (.rodata 0x052090..0x053c61), bảng hằng số SHA-256 K[64]
//        và H0[8] (0x0535e0..0x0536ff), các biến .data (0x068010..0x068028) và 577 FDE.
// ============================================================================

#pragma once

#include "orbuculum_types.h"

namespace ttp {
namespace orbuculum {
namespace rodata {

// [EN] .data constants (0x068010..0x068028, file offset 0x064010..0x064028)
// [VN] Các hằng số khởi tạo sẵn trong .data (0x068010..0x068028)
constexpr uint32_t kLockTimeOutSeconds = 2U;        // 0x068010: LOCK_TIME_OUT = 2
constexpr uint32_t kJUnhandledReturnedResult = 1U;  // 0x068014: jUnhandledReturnedResult = 1
constexpr uint32_t kOrbuCodeApiLevel = 2U;          // 0x068028: OrbuCodeAPILevel = 2

// [EN] Magic multipliers verified in OrbuCodeEngine::processRequest (0x025d28) & BurstTime::shouldSend (0x0442d4)
// [VN] Hằng số nhân nghịch đảo tại OrbuCodeEngine::processRequest (0x025d28) và BurstTime::shouldSend (0x0442d4)
constexpr uint64_t kReciprocalDiv24Magic = 0xAAAAAAAAAAAAAAABULL; // 0x025d28..0x025d30 (umulh >> 4)
constexpr uint64_t kReciprocalDiv1000Magic = 0x20C49BA5E353F7CFULL; // 0x0442d4..0x0442e0 (smulh >> 7)

struct RodataStringEntry {
    uint32_t va;
    const char* text;
};

extern const uint32_t kSha256InitialStateH0_0535e0[8];
extern const uint32_t kSha256RoundConstantsK_053600[64];
extern const uint64_t kInitArrayConstructors_0661e0[8];
extern const RodataStringEntry kRodataStringTable[];
extern const size_t kRodataStringTableCount;
extern const uint32_t kFdeFunctionStartTable[577];

const char* LookupRodataString(uint32_t va) noexcept;

} // namespace rodata
} // namespace orbuculum
} // namespace ttp
