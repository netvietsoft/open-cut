/**
 * @file animax_napi_hash_stl.cpp
 * @brief Implementation of CityHash64, NEON Popcount Bucket Math, and NDK libc++ Hash Table
 *        Hiện thực CityHash64, Toán học Bucket Popcount NEON, và Bảng băm NDK libc++
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `0x008718..0x008c5c`: `std::__ndk1::__hash_table` copy constructor with inline CityHash64
 *   - `0x009100..0x0093b0`: `__emplace_unique_key_args<uintptr_t>` (40-byte node = `0x28` @ `0x0091c4`)
 *   - `0x009400..0x009564`: `__rehash` for pointer-keyed hash table (`cnt v0.8b` @ `0x009464`)
 *   - `0x009614..0x0096a4`: `operator==(const std::string&, const std::string&)`
 *   - `0x0096b4..0x0096e0`: `Hash128to64` (`0x9ddfea08eb382d69ULL`)
 *   - `0x0096e4..0x009714`: `WeakHashLen32WithSeeds`
 *   - `0x009718..0x009888`: `__rehash` for string-keyed hash table (48-byte node = `0x30` @ `0x008ab0`)
 *   - `0x00c1e8..0x00c1fc`: `__next_power2` (`clz` + `neg` + `lsl`)
 *   - `0x00c3c4..0x00c3cc`: `cnt v0.8b, v0.8b; uaddlv h0, v0.8b; ret`
 */

#include "animax_napi_hash_stl.h"

#include <cstring>

namespace lynx {
namespace animax {
namespace napi_bridge {

namespace {

inline uint64_t LoadUnalignedLe64(const uint8_t* p) noexcept {
    uint64_t val = 0;
    std::memcpy(&val, p, sizeof(uint64_t));
    return val;
}

inline uint32_t LoadUnalignedLe32(const uint8_t* p) noexcept {
    uint32_t val = 0;
    std::memcpy(&val, p, sizeof(uint32_t));
    return val;
}

inline uint64_t RotateRight64(uint64_t val, unsigned int shift) noexcept {
    return (shift == 0) ? val : ((val >> shift) | (val << (64u - shift)));
}

inline uint64_t ShiftMix64(uint64_t val) noexcept {
    return val ^ (val >> 47);
}

}  // namespace

// ============================================================================
// 1. CITYHASH64 IMPLEMENTATION (0x008718..0x008c5c, 0x0096b4..0x009714)
// 1. HIỆN THỰC CITYHASH64 (0x008718..0x008c5c, 0x0096b4..0x009714)
// ============================================================================

/**
 * @brief Exact reconstruction of `sub_96b4` (`0x0096b4..0x0096e0`):
 *        ```asm
 *        0x0096b4: mov  x9, #0x2d69
 *        0x0096b8: movk x9, #0xeb38, lsl #16
 *        0x0096bc: movk x9, #0xea08, lsl #32
 *        0x0096c0: eor  x8, x1, x0
 *        0x0096c4: movk x9, #0x9ddf, lsl #48
 *        0x0096c8: mul  x8, x8, x9
 *        0x0096cc: eor  x10, x8, x1
 *        0x0096d0: eor  x8, x10, x8, lsr #47
 *        0x0096d4: mul  x8, x8, x9
 *        0x0096d8: eor  x8, x8, x8, lsr #47
 *        0x0096dc: mul  x0, x8, x9
 *        0x0096e0: ret
 *        ```
 */
uint64_t Hash128to64(uint64_t u, uint64_t v) noexcept {
    uint64_t a = (u ^ v) * kCityHashMul;
    a ^= (a >> 47);
    uint64_t b = (v ^ a) * kCityHashMul;
    b ^= (b >> 47);
    b *= kCityHashMul;
    return b;
}

/**
 * @brief Exact reconstruction of `sub_96e4` (`0x0096e4..0x009714`):
 *        ```asm
 *        0x0096e4: ldp x8, x11, [x0]
 *        0x0096e8: ldp x9, x10, [x0, #0x10]
 *        0x0096ec: add x8, x8, x1
 *        0x0096f0: add x9, x9, x11
 *        0x0096f4: add x12, x10, x2
 *        0x0096f8: add x9, x9, x8
 *        0x0096fc: add x11, x12, x8
 *        0x009700: ror x12, x9, #0x2c
 *        0x009704: ror x11, x11, #0x15
 *        0x009708: add x8, x12, x8
 *        0x00970c: add x0, x9, x10
 *        0x009710: add x1, x8, x11
 *        0x009714: ret
 *        ```
 */
std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(const uint8_t* s,
                                                     uint64_t a,
                                                     uint64_t b) noexcept {
    const uint64_t w = LoadUnalignedLe64(s);
    const uint64_t x = LoadUnalignedLe64(s + 8);
    const uint64_t y = LoadUnalignedLe64(s + 16);
    const uint64_t z = LoadUnalignedLe64(s + 24);

    a += w;
    b = RotateRight64(b + a + z, 21);
    const uint64_t c = a;
    a += x;
    a += y;
    b += RotateRight64(a, 44);
    return {a + z, b + c};
}

/**
 * @brief Complete CityHash64 reconstructed from `0x008770..0x008a10` and `0x008b54..0x008c5c`.
 *        Hàm CityHash64 hoàn chỉnh tái dựng từ `0x008770..0x008a10` và `0x008b54..0x008c5c`.
 */
uint64_t ComputeCityHash64(const char* buf, size_t len) noexcept {
    const uint8_t* s = reinterpret_cast<const uint8_t*>(buf);

    if (len <= 32) {
        if (len <= 16) {
            // Length 9..16 (`0x008784..0x0087b0`)
            if (len >= 9) {
                uint64_t a = LoadUnalignedLe64(s);
                uint64_t b = LoadUnalignedLe64(s + len - 8);
                uint64_t c = RotateRight64(b + len, static_cast<unsigned int>(len));
                return Hash128to64(a, c) ^ b;
            }
            // Length 4..8 (`0x008b54..0x008b6c`)
            if (len >= 4) {
                uint64_t a = static_cast<uint64_t>(len) +
                             (static_cast<uint64_t>(LoadUnalignedLe32(s)) << 3);
                uint64_t b = LoadUnalignedLe32(s + len - 4);
                return Hash128to64(a, b);
            }
            // Length 1..3 (`0x008bf4..0x008c5c`)
            if (len > 0) {
                uint8_t y = s[0];
                uint8_t z = s[len >> 1];
                uint8_t w = s[len - 1];
                uint64_t combined_lo = static_cast<uint64_t>(y) | (static_cast<uint64_t>(z) << 8);
                uint64_t combined_hi = static_cast<uint64_t>(len) + (static_cast<uint64_t>(w) << 2);
                return ShiftMix64(combined_lo * kCityHashK2 ^ combined_hi * kCityHashK3) * kCityHashK2;
            }
            // Length 0 (`0x008c08`)
            return kCityHashK2;
        }

        // Length 17..32 (`0x008878..0x0088f0`)
        uint64_t a = LoadUnalignedLe64(s) * kCityHashK1;
        uint64_t b = LoadUnalignedLe64(s + 8);
        uint64_t c = LoadUnalignedLe64(s + len - 8) * kCityHashK2;
        uint64_t d = LoadUnalignedLe64(s + len - 16) * kCityHashK0;
        uint64_t u = RotateRight64(a - b, 43) + RotateRight64(c, 30) + d;
        uint64_t v = a + RotateRight64(b ^ kCityHashK3, 20) - c + len;
        return Hash128to64(u, v);
    }

    if (len <= 64) {
        // Length 33..64 (`0x0087b4..0x008874`)
        uint64_t z = LoadUnalignedLe64(s + 24);
        uint64_t a = LoadUnalignedLe64(s) + (len + LoadUnalignedLe64(s + len - 16)) * kCityHashK0;
        uint64_t b = RotateRight64(a + z, 52);
        uint64_t c = RotateRight64(a, 37);
        a += LoadUnalignedLe64(s + 8);
        c += RotateRight64(a, 7);
        a += LoadUnalignedLe64(s + 16);
        uint64_t vf = a + z;
        uint64_t vs = b + RotateRight64(a, 31) + c;
        a = LoadUnalignedLe64(s + 16) + LoadUnalignedLe64(s + len - 32);
        z = LoadUnalignedLe64(s + len - 8);
        b = RotateRight64(a + z, 52);
        c = RotateRight64(a, 37);
        a += LoadUnalignedLe64(s + len - 24);
        c += RotateRight64(a, 7);
        a += LoadUnalignedLe64(s + len - 16);
        uint64_t wf = a + z;
        uint64_t ws = b + RotateRight64(a, 31) + c;
        uint64_t r = ShiftMix64((vf + ws) * kCityHashK2 + (wf + vs) * kCityHashK0);
        return ShiftMix64(r * kCityHashK0 + vs) * kCityHashK2;
    }

    // Length > 64 (`0x0088f4..0x008a0c`)
    uint64_t x = LoadUnalignedLe64(s + len - 40);
    uint64_t y = LoadUnalignedLe64(s + len - 16) + LoadUnalignedLe64(s + len - 56);
    uint64_t z = Hash128to64(LoadUnalignedLe64(s + len - 48) + len,
                             LoadUnalignedLe64(s + len - 24));
    std::pair<uint64_t, uint64_t> v = WeakHashLen32WithSeeds(s + len - 64, len, z);
    std::pair<uint64_t, uint64_t> w = WeakHashLen32WithSeeds(s + len - 32, y + kCityHashK1, x);
    x = x * kCityHashK1 + LoadUnalignedLe64(s);

    size_t remaining = (len - 1) & ~static_cast<size_t>(63);
    do {
        x = RotateRight64(x + y + v.first + LoadUnalignedLe64(s + 8), 37) * kCityHashK1;
        y = RotateRight64(y + v.second + LoadUnalignedLe64(s + 48), 42) * kCityHashK1;
        x ^= w.second;
        y += v.first + LoadUnalignedLe64(s + 40);
        z = RotateRight64(z + w.first, 33) * kCityHashK1;
        v = WeakHashLen32WithSeeds(s, v.second * kCityHashK1, x + w.first);
        w = WeakHashLen32WithSeeds(s + 32, z + w.second, y + LoadUnalignedLe64(s + 16));
        std::swap(z, x);
        s += 64;
        remaining -= 64;
    } while (remaining != 0);

    return Hash128to64(Hash128to64(v.first, w.first) + ShiftMix64(y) * kCityHashK1 + z,
                       Hash128to64(v.second, w.second) + x);
}

// ============================================================================
// 2. NEON POPCOUNT BUCKET MATH & NEXT POWER OF TWO (0x00c1e8..0x00c3cc)
// 2. TOÁN HỌC BUCKET POPCOUNT NEON & LŨY THỪA CỦA 2 TIẾP THEO (0x00c1e8..0x00c3cc)
// ============================================================================

/**
 * @brief Exact reconstruction of `sub_c3c4` (`0x00c3c4..0x00c3cc`):
 *        `cnt v0.8b, v0.8b` (`0x0e205800`), `uaddlv h0, v0.8b` (`0x2e303800`), `ret`.
 */
uint32_t NeonPopcount64(uint64_t val) noexcept {
#if defined(__aarch64__)
    uint64_t d0 = val;
    uint32_t count = 0;
    __asm__ volatile(
        "fmov d0, %1\n\t"
        "cnt v0.8b, v0.8b\n\t"
        "uaddlv h0, v0.8b\n\t"
        "fmov %w0, s0\n\t"
        : "=r"(count)
        : "r"(d0)
        : "v0");
    return count;
#else
    uint32_t count = 0;
    while (val != 0) {
        val &= (val - 1);
        ++count;
    }
    return count;
#endif
}

/**
 * @brief Exact bucket index calculation from `0x008a1c..0x008a50` & `0x008de0..0x008e10`.
 *        Phép tính chỉ số bucket chính xác từ `0x008a1c..0x008a50` & `0x008de0..0x008e10`.
 */
size_t ComputeHashTableBucketIndex(uint64_t hash, size_t bucket_count) noexcept {
    if (bucket_count == 0) {
        return 0;
    }
    const uint32_t popcnt = NeonPopcount64(static_cast<uint64_t>(bucket_count));
    if (popcnt <= 1u) {
        return static_cast<size_t>(hash & (bucket_count - 1u));
    }
    if (hash < bucket_count) {
        return static_cast<size_t>(hash);
    }
    const uint64_t q = hash / bucket_count;
    return static_cast<size_t>(hash - q * bucket_count);
}

/**
 * @brief Exact reconstruction of `sub_c1e8` (`0x00c1e8..0x00c1fc`):
 *        ```asm
 *        0x00c1e8: 080400d1 sub x8, x0, #1
 *        0x00c1ec: 0811c0da clz x8, x8
 *        0x00c1f0: e803084b neg w8, w8
 *        0x00c1f4: 29008052 mov w9, #1
 *        0x00c1f8: 2021c89a lsl x0, x9, x8
 *        0x00c1fc: c0035fd6 ret
 *        ```
 */
uint64_t NextPowerOfTwo64(uint64_t n) noexcept {
    if (n <= 1u) {
        return 1u;
    }
    const uint64_t minus_one = n - 1u;
#if defined(__GNUC__) || defined(__clang__)
    const uint32_t leading_zeros = static_cast<uint32_t>(__builtin_clzll(minus_one));
#else
    uint32_t leading_zeros = 0;
    for (int bit = 63; bit >= 0; --bit) {
        if ((minus_one & (1ULL << bit)) != 0) {
            break;
        }
        ++leading_zeros;
    }
#endif
    const uint32_t shift = (0u - leading_zeros) & 63u;
    return 1ULL << shift;
}

/**
 * @brief String equality helper (`0x009614..0x0096a4`) checking size first and
 *        then byte-by-byte / `memcmp` comparison.
 *        Hàm kiểm tra bằng nhau của chuỗi (`0x009614..0x0096a4`) kiểm tra độ dài trước
 *        rồi so sánh từng byte / `memcmp`.
 */
bool CompareNdkStringsEqual(const std::string& lhs, const std::string& rhs) noexcept {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    if (lhs.empty()) {
        return true;
    }
    return std::memcmp(lhs.data(), rhs.data(), lhs.size()) == 0;
}

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx
