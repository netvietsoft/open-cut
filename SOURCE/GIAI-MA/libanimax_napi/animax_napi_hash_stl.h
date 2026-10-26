/**
 * @file animax_napi_hash_stl.h
 * @brief CityHash64, NEON Popcount Bucket Math, and NDK libc++ Unordered-Map / String Helpers
 *        Hàm băm CityHash64, Toán học Bucket Popcount NEON, và Bộ hỗ trợ Unordered-Map / String NDK libc++
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `CityHash64` (`0x008718..0x0089fc`, `0x008b54..0x008c5c`):
 *     * `k0 = 0xc3a5c85c97cb3127ULL` (`0x0087c4..0x0087dc`)
 *     * `k1 = 0xb492b66fbe98f273ULL` (`0x008718..0x008738`)
 *     * `k2 = 0x9ae16a3b2f90404fULL` (`0x00882c..0x00885c`)
 *     * `k3 = 0xc949d7c7509e6557ULL` (`0x0088a0..0x0088b0`)
 *   - `Hash128to64` (`0x0096b4..0x0096e0`):
 *     * `kMul = 0x9ddfea08eb382d69ULL`
 *   - `WeakHashLen32WithSeeds` (`0x0096e4..0x009714`)
 *   - NEON Power-of-2 Bucket Count Check (`0x009464..0x009468`, `0x00c214..0x00c218`, `0x00c3c4..0x00c3c8`):
 *     * `cnt v0.8b, v0.8b` (`0x0e205800`)
 *     * `uaddlv h0, v0.8b` (`0x2e303800`)
 *   - Next Power of 2 (`0x00c1e8..0x00c1fc`):
 *     * `sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1; lsl x0, x9, x8`
 */

#ifndef OPENCUT_ANIMAX_NAPI_HASH_STL_H_
#define OPENCUT_ANIMAX_NAPI_HASH_STL_H_

#include "animax_napi_types.h"
#include <cstddef>
#include <cstdint>
#include <string>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. CITYHASH64 CONSTANTS & FUNCTIONS (0x008718..0x009714)
// 1. CÁC HẰNG SỐ & HÀM CITYHASH64 (0x008718..0x009714)
// ============================================================================

static constexpr uint64_t kCityHashK0  = 0xc3a5c85c97cb3127ULL;  // @ 0x0087c4..0x0087dc
static constexpr uint64_t kCityHashK1  = 0xb492b66fbe98f273ULL;  // @ 0x008718..0x008738
static constexpr uint64_t kCityHashK2  = 0x9ae16a3b2f90404fULL;  // @ 0x00882c..0x00885c
static constexpr uint64_t kCityHashK3  = 0xc949d7c7509e6557ULL;  // @ 0x0088a0..0x0088b0
static constexpr uint64_t kCityHashMul = 0x9ddfea08eb382d69ULL;  // @ 0x0096b4..0x0096c4

/**
 * @brief 128-to-64-bit hash combiner (`0x0096b4..0x0096e0`).
 *        Hàm kết hợp băm 128-sang-64-bit (`0x0096b4..0x0096e0`).
 */
uint64_t Hash128to64(uint64_t u, uint64_t v) noexcept;

/**
 * @brief Weak 32-byte hash with seeds (`0x0096e4..0x009714`).
 *        Hàm băm yếu 32-byte có hạt giống (`0x0096e4..0x009714`).
 */
std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(const uint8_t* s,
                                                     uint64_t a,
                                                     uint64_t b) noexcept;

/**
 * @brief Full CityHash64 implementation matching `0x008718..0x0089fc` & `0x008b54..0x008c5c`.
 *        Cài đặt CityHash64 đầy đủ khớp với `0x008718..0x0089fc` & `0x008b54..0x008c5c`.
 */
uint64_t ComputeCityHash64(const char* buf, size_t len) noexcept;

// ============================================================================
// 2. NEON POPCOUNT BUCKET MATH & NEXT POWER OF TWO (0x00c1e8..0x00c3cc)
// 2. TOÁN HỌC BUCKET POPCOUNT NEON & LŨY THỪA CỦA 2 TIẾP THEO (0x00c1e8..0x00c3cc)
// ============================================================================

/**
 * @brief Counts set bits in a 64-bit integer matching `sub_c3c4` (`0x00c3c4..0x00c3cc`):
 *        `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; ret`.
 *        Đếm số bit 1 trong số nguyên 64-bit khớp với `sub_c3c4` (`0x00c3c4..0x00c3cc`):
 *        `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; ret`.
 */
uint32_t NeonPopcount64(uint64_t val) noexcept;

/**
 * @brief Computes bucket index for `std::__ndk1::__hash_table` (`0x008a1c..0x008a50`):
 *        Uses `(hash & (bucket_count - 1))` when `NeonPopcount64(bucket_count) <= 1`,
 *        or `hash - (hash / bucket_count) * bucket_count` (`udiv` + `msub`) when prime.
 *        Tính chỉ số bucket cho `std::__ndk1::__hash_table` (`0x008a1c..0x008a50`).
 */
size_t ComputeHashTableBucketIndex(uint64_t hash, size_t bucket_count) noexcept;

/**
 * @brief Rounds `n` up to the next power of 2 (`0x00c1e8..0x00c1fc`):
 *        `sub x8, x0, #1; clz x8, x8; neg w8, w8; mov w9, #1; lsl x0, x9, x8`.
 *        Làm tròn `n` lên lũy thừa của 2 tiếp theo (`0x00c1e8..0x00c1fc`).
 */
uint64_t NextPowerOfTwo64(uint64_t n) noexcept;

/**
 * @brief Compares two `std::__ndk1::basic_string<char>` instances using the SSO/long
 *        layout verified at `0x009614..0x0096a4`.
 *        So sánh hai thực thể `std::__ndk1::basic_string<char>` theo bố cục SSO/dài
 *        xác minh tại `0x009614..0x0096a4`.
 */
bool CompareNdkStringsEqual(const std::string& lhs, const std::string& rhs) noexcept;

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx

#endif  // OPENCUT_ANIMAX_NAPI_HASH_STL_H_
