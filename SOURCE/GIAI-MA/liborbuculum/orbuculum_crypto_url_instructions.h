// ============================================================================
// File: orbuculum_crypto_url_instructions.h
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for SHA256 (0x03d82c..0x03dcd0),
//        UrlParser (0x039d30..0x03b900), SampleFrequency subclasses
//        (Discard, All, Random, RandomTimeBased, BurstCount, BurstTime @ 0x043e78..0x04430c),
//        HostCIDRCheckInstruction (0x0495f8..0x04a658), MatchKeySubsetInstruction,
//        and FDEs 390..576.
//   [VN] Khai báo C++17 sạch cho SHA256, UrlParser, các lớp lấy mẫu SampleFrequency,
//        HostCIDRCheckInstruction, MatchKeySubsetInstruction và FDE 390..576.
// ============================================================================

#pragma once

#include "orbuculum_types.h"

namespace ttp {
namespace orbuculum {
namespace crypto {

void Sha256InitExact(Sha256ContextAbi* ctx) noexcept;
int64_t DivideMicrosecondsToMillisecondsSigned(int64_t microseconds) noexcept;
bool BurstTimeShouldSendExact(int64_t current_microseconds, int64_t threshold_milliseconds) noexcept;

uint64_t DispatchCryptoUrlInstructionsFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace crypto
} // namespace orbuculum
} // namespace ttp
