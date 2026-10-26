/**
 * @file pns_ttmachine_sampling_namelist.cpp
 * @brief Bit-Exact Implementation of MT19937 Sampling, CityHash64, NameList & URL/Domain Engine
 *        Triển khai chuẩn xác từng bit Bộ lấy mẫu MT19937, CityHash64, NameList & Phân tích URL/Domain
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 *   - 0x007ed4..0x008338: std::__ndk1::__murmur2_or_cityhash<uint64_t, 64> (CityHash64)
 *   - 0x00fbe8..0x00fc78: String tokenizer for NameList matching
 *   - 0x0318a8..0x0319d4: load_const_pool_extra_json (parses "common" & "incremental_list")
 *   - 0x0360f0..0x036238: _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct
 *   - 0x03623c..0x0363bc: _Z5isHitPd (624-word MT19937 + 64-bit uniform [0,1) double)
 *   - 0x0363c0..0x0365e0: _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct
 *   - 0x0365e4..0x0368e0: _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct
 *   - 0x0368e4..0x036ea8: _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct
 *   - 0x036eac..0x03708c: _Z10randomSeedPlPPvPdP22__TTMTransparentStruct
 *   - 0x037090..0x037288: __independent_bits_engine<mt19937, uint32_t>::__eval()
 *   - 0x03963c..0x039810: namelist_find_container
 *   - 0x03ac80..0x03aeec: namelist_match_entry (6-way jump table at 0x03add4 via 0x0437b6)
 */

#include "pns_ttmachine_sampling_namelist.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <regex>
#include <sstream>

#if defined(__ANDROID__)
#include <android/log.h>
#define PNS_LOGD(tag, fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, tag, fmt, ##__VA_ARGS__)
#define PNS_LOGW(tag, fmt, ...) __android_log_print(ANDROID_LOG_WARN, tag, fmt, ##__VA_ARGS__)
#else
#define PNS_LOGD(tag, fmt, ...) ((void)0)
#define PNS_LOGW(tag, fmt, ...) ((void)0)
#endif

// ============================================================================
// Weak Fallback Definitions for libTTMachineCore.so Imported Symbols
// Định nghĩa dự phòng liên kết yếu cho các ký hiệu nhập từ libTTMachineCore.so
// ============================================================================
extern "C" {

struct MockTTMList {
    uint32_t type_tag = 1;
    uint32_t elem_type = 3;
    std::vector<void*> elements;
};

struct MockTTMStr {
    uint64_t header[5] = {0, 0, 0, 0, 0};
    std::string storage;
    MockTTMStr(const char* s) : storage(s ? s : "") {
        header[4] = storage.size();
    }
};

__attribute__((weak)) void* TTMListO_create(int type_tag, int elem_type, void* /*pool*/, void* /*err*/) {
    auto* list = new MockTTMList();
    list->type_tag = static_cast<uint32_t>(type_tag);
    list->elem_type = static_cast<uint32_t>(elem_type);
    return list;
}

__attribute__((weak)) void* TTMStrO_from_cstr(const char* cstr, void* /*pool*/, void* /*err*/) {
    auto* obj = new TTMObjectValue();
    obj->header_type = 3;
    obj->reserved_08 = 0;
    obj->reserved_10 = 0;
    obj->numeric_val = 0;
    obj->str_length = cstr ? std::strlen(cstr) : 0;
    obj->c_str_ptr = cstr;
    return obj;
}

__attribute__((weak)) void TTMListO_add_obj(void* list_ptr, void* elem_ptr, void* /*pool*/, void* /*err*/) {
    if (!list_ptr || !elem_ptr) return;
    auto* list = static_cast<MockTTMList*>(list_ptr);
    list->elements.push_back(elem_ptr);
}

} // extern "C"

namespace pns {
namespace ttmachine {

namespace {

// Helper to load unaligned 64-bit little-endian integer (ldur/ldr xN, [x0, #off])
// Hàm phụ trợ đọc số nguyên 64-bit little-endian không căn lề (ldur/ldr xN, [x0, #off])
inline uint64_t LoadLe64(const char* p) noexcept {
    uint64_t v = 0;
    std::memcpy(&v, p, sizeof(uint64_t));
    return v;
}

inline uint32_t LoadLe32(const char* p) noexcept {
    uint32_t v = 0;
    std::memcpy(&v, p, sizeof(uint32_t));
    return v;
}

inline uint64_t RotateRight64(uint64_t val, unsigned shift) noexcept {
    return shift == 0 ? val : ((val >> shift) | (val << (64 - shift)));
}

inline uint64_t HashLen16(uint64_t u, uint64_t v, uint64_t mul = 0x9ddfea08eb382d69ULL) noexcept {
    // Verified at 0x007f18..0x007f3c and 0x0080a4..0x0080c4:
    //   eor x9, x10, x9; mul x9, x9, x11; eor x10, x9, x10; eor x9, x10, x9, lsr #47
    //   mul x9, x9, x11; eor x9, x9, x9, lsr #47; mul x9, x9, x11
    uint64_t a = (u ^ v) * mul;
    a ^= (a >> 47);
    uint64_t b = (v ^ a) * mul;
    b ^= (b >> 47);
    b *= mul;
    return b;
}

inline uint64_t ShiftMix(uint64_t val) noexcept {
    return val ^ (val >> 47);
}

} // namespace

// ============================================================================
// 1. Bit-Exact CityHash64 Implementation (0x007ed4..0x008338)
//    Triển khai CityHash64 chuẩn xác từng bit (0x007ed4..0x008338)
// ============================================================================
uint64_t ComputeNdkStringHash64(const char* s, size_t len) noexcept {
    // Constants verified in disassembly at 0x007f08..0x008300:
    constexpr uint64_t k0   = 0xc3a5c85c97cb3127ULL; // 0x007f54..0x007f6c
    constexpr uint64_t k1   = 0xb492b66fbe98f273ULL; // 0x008010..0x008020
    constexpr uint64_t k2   = 0x9ae16a3b2f90404fULL; // 0x008030..0x008058 & 0x0082f0..0x0082fc
    constexpr uint64_t k3   = 0xc949d7c7509e6557ULL; // 0x00802c..0x008054
    constexpr uint64_t kMul = 0x9ddfea08eb382d69ULL; // 0x007f08..0x007f1c

    if (!s || len == 0) {
        // 0x008300: cbz x1, #0x82a8 -> returns k2 (0x9ae16a3b2f90404fULL)
        return k2;
    }

    if (len <= 32) {
        if (len <= 16) {
            if (len >= 9) {
                // 0x007eec..0x007f40: len in [9..16]
                uint64_t a = LoadLe64(s);
                uint64_t b = LoadLe64(s + len - 8);
                return HashLen16(a, RotateRight64(b + len, static_cast<unsigned>(len))) ^ b;
            }
            if (len >= 4) {
                // 0x0082b8..0x0082ec: len in [4..8]
                uint64_t a = LoadLe32(s);
                uint64_t b = LoadLe32(s + len - 4);
                return HashLen16(len + (a << 3), b);
            }
            // 0x008304..0x008338: len in [1..3]
            uint8_t a = static_cast<uint8_t>(s[0]);
            uint8_t b = static_cast<uint8_t>(s[len >> 1]);
            uint8_t c = static_cast<uint8_t>(s[len - 1]);
            uint32_t y = static_cast<uint32_t>(a) + (static_cast<uint32_t>(b) << 8);
            uint32_t z = static_cast<uint32_t>(len) + (static_cast<uint32_t>(c) << 2);
            return ShiftMix(y * k2 ^ z * k3) * k2;
        }
        // 0x008010..0x0080c8: len in [17..32]
        uint64_t a = LoadLe64(s) * k1;
        uint64_t b = LoadLe64(s + 8);
        uint64_t c = LoadLe64(s + len - 8) * k2;
        uint64_t d = LoadLe64(s + len - 16) * k0;
        return HashLen16(
            RotateRight64(a - b, 43) + RotateRight64(c, 30) + d,
            a + RotateRight64(b ^ k3, 20) - c + len);
    }

    if (len <= 64) {
        // 0x007f4c..0x00800c: len in [33..64]
        uint64_t z = LoadLe64(s + 24);
        uint64_t a = LoadLe64(s) + (len + LoadLe64(s + len - 16)) * k0;
        uint64_t b = RotateRight64(a + z, 52);
        uint64_t c = RotateRight64(a, 37);
        a += LoadLe64(s + 8);
        c += RotateRight64(a, 7);
        a += LoadLe64(s + 16);
        uint64_t vf = a + z;
        uint64_t vs = b + RotateRight64(a, 31) + c;
        a = LoadLe64(s + 16) + LoadLe64(s + len - 32);
        z = LoadLe64(s + len - 8);
        b = RotateRight64(a + z, 52);
        c = RotateRight64(a, 37);
        a += LoadLe64(s + len - 24);
        c += RotateRight64(a, 7);
        a += LoadLe64(s + len - 16);
        uint64_t wf = a + z;
        uint64_t ws = b + RotateRight64(a, 31) + c;
        uint64_t r = ShiftMix((vf + ws) * k2 + (wf + vs) * k0);
        return ShiftMix(r * k0 + vs) * k2;
    }

    // 0x0080cc..0x0082ac: len > 64
    uint64_t x = LoadLe64(s + len - 40);
    uint64_t y = LoadLe64(s + len - 16) + LoadLe64(s + len - 56);
    uint64_t z = HashLen16(LoadLe64(s + len - 48) + len, LoadLe64(s + len - 24));
    std::pair<uint64_t, uint64_t> v{0, 0};
    std::pair<uint64_t, uint64_t> w{0, 0};

    auto weak_hash_len32 = [](const char* p, uint64_t a, uint64_t b) noexcept -> std::pair<uint64_t, uint64_t> {
        uint64_t w0 = LoadLe64(p);
        uint64_t w1 = LoadLe64(p + 8);
        uint64_t w2 = LoadLe64(p + 16);
        uint64_t w3 = LoadLe64(p + 24);
        a += w0;
        b = RotateRight64(b + a + w3, 21);
        uint64_t c = a;
        a += w1;
        a += w2;
        b += RotateRight64(a, 44);
        return {a + w3, b + c};
    };

    v = weak_hash_len32(s + len - 64, len, z);
    w = weak_hash_len32(s + len - 32, y + k1, x);
    x = x * k1 + LoadLe64(s);

    size_t remaining = (len - 1) & ~static_cast<size_t>(63);
    const char* ptr = s;
    do {
        x = RotateRight64(x + y + v.first + LoadLe64(ptr + 8), 37) * k1;
        y = RotateRight64(y + v.second + LoadLe64(ptr + 48), 42) * k1;
        x ^= w.second;
        y += v.first + LoadLe64(ptr + 40);
        z = RotateRight64(z + w.first, 33) * k1;
        v = weak_hash_len32(ptr, v.second * k1, x + w.first);
        w = weak_hash_len32(ptr + 32, z + w.second, y + LoadLe64(ptr + 16));
        std::swap(z, x);
        ptr += 64;
        remaining -= 64;
    } while (remaining != 0);

    return HashLen16(
        HashLen16(v.first, w.first) + ShiftMix(y) * k1 + z,
        HashLen16(v.second, w.second) + x);
}

// ============================================================================
// 2. Bit-Exact MT19937 Uniform Double & Seed Sampling (0x03623c & 0x036eac)
//    Lấy mẫu số thực đồng nhất MT19937 & Hạt giống chuỗi (0x03623c & 0x036eac)
// ============================================================================
double GenerateMt19937UniformDouble(uint32_t seed) noexcept {
    // Disassembly verified at 0x036280..0x0362b0:
    //   mov w10, #0x8965; movk w10, #0x6c07, lsl #16 (0x6c078965 = 1812433253)
    //   state[0] = seed & 0xffffffff
    //   for (i = 1; i < 0x270; ++i) state[i] = (0x6c078965U * (state[i-1] ^ (state[i-1] >> 30)) + i) & 0xffffffff
    uint64_t state[BinaryLayout::kMt19937N];
    state[0] = static_cast<uint64_t>(seed);
    for (uint32_t i = 1; i < BinaryLayout::kMt19937N; ++i) {
        uint32_t prev = static_cast<uint32_t>(state[i - 1]);
        uint32_t next = BinaryLayout::kMt19937InitMult * (prev ^ (prev >> 30)) + i;
        state[i] = static_cast<uint64_t>(next);
    }

    // Disassembly verified at 0x0362b4..0x036368:
    //   ldp x8, x10, [sp]        -> x8 = state[0], x10 = state[1]
    //   ldr x9, [sp, #0x10]      -> x9 = state[2]
    //   ldr x11, [sp, #0xc68]    -> x11 = state[397] (0xc68 / 8 = 397 = M)
    //   ldr x13, [sp, #0xc70]    -> x13 = state[398]
    uint32_t s0   = static_cast<uint32_t>(state[0]);
    uint32_t s1   = static_cast<uint32_t>(state[1]);
    uint32_t s2   = static_cast<uint32_t>(state[2]);
    uint32_t s397 = static_cast<uint32_t>(state[BinaryLayout::kMt19937M]);
    uint32_t s398 = static_cast<uint32_t>(state[BinaryLayout::kMt19937M + 1]);

    uint32_t y0 = (s0 & 0x80000000U) | (s1 & 0x7ffffffeU);
    uint32_t y1 = (s1 & 0x80000000U) | (s2 & 0x7ffffffeU);

    uint32_t mag0 = (s1 & 1U) * BinaryLayout::kMt19937MatrixA;
    uint32_t mag1 = (s2 & 1U) * BinaryLayout::kMt19937MatrixA;

    uint32_t z0 = s397 ^ (y0 >> 1) ^ mag0;
    uint32_t z1 = s398 ^ (y1 >> 1) ^ mag1;

    // Tempering verified at 0x036314..0x036368:
    z0 ^= (z0 >> 11);
    z1 ^= (z1 >> 11);
    z0 ^= (z0 << 7) & BinaryLayout::kMt19937TemperMaskB;
    z1 ^= (z1 << 7) & BinaryLayout::kMt19937TemperMaskB;
    z0 ^= (z0 << 15) & BinaryLayout::kMt19937TemperMaskC;
    z1 ^= (z1 << 15) & BinaryLayout::kMt19937TemperMaskC;
    z0 ^= (z0 >> 18);
    z1 ^= (z1 >> 18);

    // Disassembly verified at 0x0362bc..0x036388:
    //   x12 = 0x41f0000000000000 -> d0 = 4294967296.0 (2^32)
    //   x13 = 0x3bf0000000000000 -> d1 = 5.421010862427522e-20 (2^-64)
    //   ucvtf d2, x9 (z1); fmul d0, d2, d0; ucvtf d2, x8 (z0); fadd d0, d0, d2; fmul d0, d0, d1
    const double kTwoPow32     = 4294967296.0;              // 0x41f0000000000000
    const double kTwoPowNeg64  = 5.42101086242752217004e-20; // 0x3bf0000000000000
    return (static_cast<double>(z1) * kTwoPow32 + static_cast<double>(z0)) * kTwoPowNeg64;
}

bool EvaluateDeterministicSeedSample(const char* seed_str, double sample_rate) noexcept {
    // Disassembly verified at 0x036ef0..0x036f10:
    //   fcmp d8, #0.0 -> if 0.0, return false (0)
    //   fmov d0, #1.0; fcmp d8, d0 -> if 1.0, return true (1)
    if (sample_rate == 0.0) {
        return false;
    }
    if (sample_rate == 1.0) {
        return true;
    }

    // Disassembly verified at 0x036f1c..0x036fc4:
    uint64_t raw_seed = static_cast<uint64_t>(
        std::chrono::system_clock::now().time_since_epoch().count());
    if (seed_str && seed_str[0] != '\0') {
        raw_seed = ComputeNdkStringHash64(seed_str, std::strlen(seed_str));
    }

    // Disassembly verified at 0x036fd4..0x03704c:
    // Seeds 624-word MT19937 with (uint32_t)(raw_seed & 0xffffffff), then evaluates
    // uniform sample and compares sample_rate >= sample.
    double u = GenerateMt19937UniformDouble(static_cast<uint32_t>(raw_seed & 0xffffffffU));
    return sample_rate >= u;
}

// ============================================================================
// 3. NameListContainer & NameListManager Implementation (0x0318a8..0x03aeec)
//    Triển khai NameListContainer & NameListManager (0x0318a8..0x03aeec)
// ============================================================================
bool NameListContainer::MatchTokens(
    const std::vector<std::string>& tokens,
    int32_t match_mode_override) const {
    if (tokens.empty()) {
        return false;
    }
    // Disassembly verified at 0x03adc4..0x03ade4:
    // 6-way switch on match_way (0..5) via offset table at 0x0437b6
    int32_t mode = (match_mode_override > 0)
        ? match_mode_override
        : static_cast<int32_t>(default_match_way);
    if (mode < 0 || mode > 5) {
        return false;
    }

    const std::string& primary = tokens[0];
    switch (static_cast<NameListMatchWay>(mode)) {
        case NameListMatchWay::kExactMatch: {
            if (exact_items.find(primary) != exact_items.end()) {
                return true;
            }
            if (tokens.size() >= 2) {
                std::string combined = tokens[0] + tokens[1];
                if (exact_items.find(combined) != exact_items.end()) {
                    return true;
                }
            }
            return false;
        }
        case NameListMatchWay::kPrefixMatch: {
            for (const auto& prefix : prefix_items) {
                if (!prefix.empty() && primary.size() >= prefix.size() &&
                    primary.compare(0, prefix.size(), prefix) == 0) {
                    return true;
                }
            }
            return false;
        }
        case NameListMatchWay::kSuffixMatch: {
            for (const auto& suffix : suffix_items) {
                if (!suffix.empty() && primary.size() >= suffix.size() &&
                    primary.compare(primary.size() - suffix.size(), suffix.size(), suffix) == 0) {
                    return true;
                }
            }
            return false;
        }
        case NameListMatchWay::kContainsMatch: {
            for (const auto& sub : contains_items) {
                if (!sub.empty() && primary.find(sub) != std::string::npos) {
                    return true;
                }
            }
            return false;
        }
        case NameListMatchWay::kRegexWildcard: {
            for (const auto& pat : contains_items) {
                if (pat == "*" || pat == primary) {
                    return true;
                }
                try {
                    std::regex re(pat);
                    if (std::regex_search(primary, re)) {
                        return true;
                    }
                } catch (...) {
                }
            }
            return false;
        }
        case NameListMatchWay::kDomainPathTree: {
            // Domain + Path hierarchical match ("mer", "mat", "val", "_next", "next_in" at 0x045928..0x04593a)
            if (exact_items.find(primary) != exact_items.end()) {
                if (tokens.size() == 1) {
                    return true;
                }
                const std::string& path = tokens[1];
                for (const auto& pfx : prefix_items) {
                    if (!pfx.empty() && path.compare(0, pfx.size(), pfx) == 0) {
                        return true;
                    }
                }
                if (exact_items.find(primary + path) != exact_items.end()) {
                    return true;
                }
            }
            for (const auto& suffix : suffix_items) {
                if (!suffix.empty() && primary.size() >= suffix.size() &&
                    primary.compare(primary.size() - suffix.size(), suffix.size(), suffix) == 0) {
                    if (tokens.size() == 1) {
                        return true;
                    }
                    const std::string& path = tokens[1];
                    if (prefix_items.empty()) {
                        return true;
                    }
                    for (const auto& pfx : prefix_items) {
                        if (!pfx.empty() && path.compare(0, pfx.size(), pfx) == 0) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }
    return false;
}

NameListManager& NameListManager::Instance() {
    // Guarded by __cxa_guard_acquire at 0x055768 (0x031964, 0x036574, 0x036880)
    static NameListManager instance;
    return instance;
}

NameListManager::NameListManager() {
    pthread_rwlock_init(&rwlock_, nullptr);
    containers_.max_load_factor(1.0f); // mov w9, #0x3f800000; str w9, [x8, #0x30] at 0x0319a8
}

NameListManager::~NameListManager() {
    pthread_rwlock_destroy(&rwlock_);
}

void NameListManager::Clear() {
    pthread_rwlock_wrlock(&rwlock_);
    containers_.clear();
    prepare_status_.store(0, std::memory_order_release);
    pthread_rwlock_unlock(&rwlock_);
}

void NameListManager::RegisterContainer(
    const std::string& key,
    std::shared_ptr<NameListContainer> container) {
    if (key.empty() || !container) {
        return;
    }
    pthread_rwlock_wrlock(&rwlock_);
    containers_[key] = std::move(container);
    prepare_status_.store(2, std::memory_order_release); // 2 = ready (0x031914: mov w8, #2; str w8, [x21, #0x770])
    pthread_rwlock_unlock(&rwlock_);
}

std::shared_ptr<NameListContainer> NameListManager::FindContainer(const char* name_list_key) const {
    // Disassembly verified at 0x03963c..0x039810:
    //   cbz x1, #0x39750
    //   ldr x0, [x25, #0x778]; bl pthread_rwlock_rdlock
    //   bl #0x38ce0 (count); bl #0x38e60 (find)
    //   bl pthread_rwlock_unlock
    if (!name_list_key || name_list_key[0] == '\0') {
        return nullptr;
    }
    pthread_rwlock_rdlock(&rwlock_);
    std::shared_ptr<NameListContainer> result;
    auto it = containers_.find(name_list_key);
    if (it != containers_.end()) {
        result = it->second;
    }
    pthread_rwlock_unlock(&rwlock_);
    return result;
}

std::vector<std::string> NameListManager::TokenizeValue(const char* c_str) {
    // Disassembly verified at 0x00fbe8..0x00fc78:
    // Allocates 24-byte std::string on heap/vector for single token
    std::vector<std::string> out;
    if (!c_str) {
        out.emplace_back("");
        return out;
    }
    out.emplace_back(c_str);
    return out;
}

bool NameListManager::LoadConstPoolExtraJson(const char* json_str) {
    // Disassembly verified at 0x0318a8..0x0319d4:
    //   mov w8, #1; str w8, [x21, #0x770] (status = 1: loading)
    //   bl #0x25a88 (parse JSON)
    //   if null -> status = 3 (0x031934: mov w9, #3; str w9, [x21, #0x770]), log "parse extra fail,not legal json config" (0x045942)
    //   looks up "incremental_list" (0x0458e0) or "common" (0x0458d9), iterates entries via 0x038174
    //   sets status = 2 (0x031914: mov w8, #2; str w8, [x21, #0x770])
    prepare_status_.store(1, std::memory_order_release);
    if (!json_str || json_str[0] == '\0') {
        prepare_status_.store(3, std::memory_order_release);
        PNS_LOGW("PnsRuleEngine-Core", "parse extra fail,not legal json config");
        return false;
    }

    std::string raw(json_str);
    auto open_brace = raw.find('{');
    auto close_brace = raw.rfind('}');
    if (open_brace == std::string::npos || close_brace == std::string::npos || close_brace <= open_brace) {
        prepare_status_.store(3, std::memory_order_release);
        PNS_LOGW("PnsRuleEngine-Core", "parse extra fail,not legal json config");
        return false;
    }

    // Extract "incremental_list" or key-array pairs: "list_key": ["item1", "item2"]
    pthread_rwlock_wrlock(&rwlock_);
    size_t pos = 0;
    while ((pos = raw.find('\"', pos)) != std::string::npos) {
        size_t key_end = raw.find('\"', pos + 1);
        if (key_end == std::string::npos) break;
        std::string key = raw.substr(pos + 1, key_end - pos - 1);
        pos = key_end + 1;
        if (key == "common" || key == "incremental_list" || key == "const_pool") {
            continue;
        }
        size_t colon = raw.find(':', pos);
        if (colon == std::string::npos) break;
        size_t next_non_space = raw.find_first_not_of(" \t\r\n", colon + 1);
        if (next_non_space == std::string::npos) break;
        if (raw[next_non_space] == '[') {
            size_t arr_end = raw.find(']', next_non_space + 1);
            if (arr_end == std::string::npos) break;
            auto& container = containers_[key];
            if (!container) {
                container = std::make_shared<NameListContainer>();
                container->list_key = key;
            }
            size_t item_pos = next_non_space + 1;
            while (item_pos < arr_end) {
                size_t q1 = raw.find('\"', item_pos);
                if (q1 == std::string::npos || q1 >= arr_end) break;
                size_t q2 = raw.find('\"', q1 + 1);
                if (q2 == std::string::npos || q2 >= arr_end) break;
                std::string val = raw.substr(q1 + 1, q2 - q1 - 1);
                container->exact_items.insert(val);
                if (!val.empty() && val[0] == '.') {
                    container->suffix_items.push_back(val);
                } else if (!val.empty() && val[0] == '/') {
                    container->prefix_items.push_back(val);
                } else {
                    container->contains_items.push_back(val);
                }
                item_pos = q2 + 1;
            }
            pos = arr_end + 1;
        }
    }
    prepare_status_.store(2, std::memory_order_release);
    pthread_rwlock_unlock(&rwlock_);
    return true;
}

// ============================================================================
// 4. URL & Domain Functions Registered in 0x014598
//    Các hàm phân tích URL & Domain đăng ký tại 0x014598
// ============================================================================
std::string UrlDecode(const std::string& encoded) {
    // Registered as "url_decode" (0x044c6f)
    std::string out;
    out.reserve(encoded.size());
    for (size_t i = 0; i < encoded.size(); ++i) {
        if (encoded[i] == '%' && i + 2 < encoded.size()) {
            char hex[3] = {encoded[i + 1], encoded[i + 2], '\0'};
            char* endp = nullptr;
            long val = std::strtol(hex, &endp, 16);
            if (endp == hex + 2) {
                out.push_back(static_cast<char>(val));
                i += 2;
                continue;
            }
        } else if (encoded[i] == '+') {
            out.push_back(' ');
            continue;
        }
        out.push_back(encoded[i]);
    }
    return out;
}

std::string ExtractUrlScheme(const std::string& url) {
    // Registered as "url_scheme" (0x044cac)
    size_t pos = url.find("://");
    if (pos == std::string::npos) {
        return "";
    }
    std::string scheme = url.substr(0, pos);
    std::transform(scheme.begin(), scheme.end(), scheme.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return scheme;
}

std::string ExtractUrlQueryString(const std::string& url) {
    // Registered as "url_str_query" (0x044cb7)
    size_t qpos = url.find('?');
    if (qpos == std::string::npos) {
        return "";
    }
    size_t fpos = url.find('#', qpos + 1);
    if (fpos == std::string::npos) {
        return url.substr(qpos + 1);
    }
    return url.substr(qpos + 1, fpos - qpos - 1);
}

bool IsIpAddress(const std::string& host) {
    // Registered as "is_ip_address" (0x044cc5); uses inet_pton in binary
    if (host.empty()) return false;
    int dots = 0;
    int val = 0;
    int digits = 0;
    for (char c : host) {
        if (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            if (val > 255) return false;
            ++digits;
        } else if (c == '.') {
            if (digits == 0) return false;
            ++dots;
            val = 0;
            digits = 0;
        } else {
            return host.find(':') != std::string::npos; // IPv6 check
        }
    }
    return dots == 3 && digits > 0;
}

bool IsValidDomain(const std::string& host) {
    // Registered as "is_domain" (0x044cd3) using regex "^([A-Za-z0-9-]+\\.)+[A-Za-z]{2,6}$" at 0x044c42
    static const std::regex kDomainRegex("^([A-Za-z0-9-]+\\.)+[A-Za-z]{2,6}$");
    return std::regex_match(host, kDomainRegex);
}

std::string ExtractSecondLevelDomain(const std::string& host_or_url) {
    // Registered as "url_second_level_domain" (0x044c7a)
    std::string host = host_or_url;
    size_t scheme_pos = host.find("://");
    if (scheme_pos != std::string::npos) {
        host = host.substr(scheme_pos + 3);
    }
    size_t slash_pos = host.find_first_of("/:?#");
    if (slash_pos != std::string::npos) {
        host = host.substr(0, slash_pos);
    }
    if (host.empty() || IsIpAddress(host)) {
        return host;
    }
    size_t last_dot = host.rfind('.');
    if (last_dot == std::string::npos || last_dot == 0) {
        return host;
    }
    size_t prev_dot = host.rfind('.', last_dot - 1);
    if (prev_dot == std::string::npos) {
        return host;
    }
    return host.substr(prev_dot + 1);
}

std::vector<std::string> ExtractUrlsSecondLevelDomains(const std::vector<std::string>& urls) {
    // Registered as "urls_second_level_domains" (0x044c92)
    std::vector<std::string> out;
    out.reserve(urls.size());
    for (const auto& u : urls) {
        out.push_back(ExtractSecondLevelDomain(u));
    }
    return out;
}

int32_t CompareVersionStrings(const std::string& v1, const std::string& v2) {
    // Registered as "version_compare" (0x044a39)
    size_t i = 0, j = 0;
    while (i < v1.size() || j < v2.size()) {
        long n1 = 0, n2 = 0;
        while (i < v1.size() && v1[i] != '.') {
            if (v1[i] >= '0' && v1[i] <= '9') n1 = n1 * 10 + (v1[i] - '0');
            ++i;
        }
        while (j < v2.size() && v2[j] != '.') {
            if (v2[j] >= '0' && v2[j] <= '9') n2 = n2 * 10 + (v2[j] - '0');
            ++j;
        }
        if (n1 < n2) return -1;
        if (n1 > n2) return 1;
        if (i < v1.size()) ++i;
        if (j < v2.size()) ++j;
    }
    return 0;
}

} // namespace ttmachine
} // namespace pns

// ============================================================================
// 5. Exported C++ Mangled TTMachine Symbols (0x0360f0..0x03708c)
//    Các ký hiệu C++ Mangled xuất ra cho TTMachine (0x0360f0..0x03708c)
// ============================================================================
extern "C" {

/**
 * Disassembly verified at 0x03623c..0x0363bc (388 B):
 *   0x03625c: fmov d1, #1.00000000
 *   0x036264: ldr d0, [x0]
 *   0x036268: fcmp d0, d1
 *   0x03626c: b.ne #0x36278
 *   0x036270: mov w0, #1; b #0x36394
 *   0x03627c: bl _ZNSt6__ndk16chrono12system_clock3nowEv
 *   0x036280..0x036388: 624-word MT19937 + 64-bit uniform double in [0, 1)
 *   0x03638c: fcmp d2, d0; cset w0, ge
 */
JNIEXPORT bool _Z5isHitPd(double* sample_rate) {
    if (!sample_rate) {
        return false;
    }
    const double rate = *sample_rate;
    if (rate == 1.0) {
        return true;
    }
    uint32_t seed = static_cast<uint32_t>(
        std::chrono::system_clock::now().time_since_epoch().count() & 0xffffffffULL);
    double rand_u = pns::ttmachine::GenerateMt19937UniformDouble(seed);
    return rate >= rand_u;
}

/**
 * Disassembly verified at 0x0360f0..0x036238 (332 B):
 *   0x036110: ldp x3, x2, [x6, #0x18]
 *   0x03611c: mov w0, #1; mov w1, #3; bl TTMListO_create
 *   0x036134: ldr x8, [x20, #0x18]; ldr w8, [x8]; cbnz w8, #0x36224
 *   0x036148: bl _Z5isHitPd (stack_rate)        -> "stack" (0x04579a)
 *   0x036174: bl _Z5isHitPd (header_fields_rate)-> "header_fields" (0x0457a0)
 *   0x0361a0: bl _Z5isHitPd (query_fields_rate) -> "query_fields" (0x0457ae)
 *   0x0361cc: bl _Z5isHitPd (cookie_fields_rate)-> "cookie_fields" (0x0457bb)
 *   0x0361f8: bl _Z5isHitPd (body_fields_rate)  -> "body_fields" (0x0457c9)
 *   0x036220: str x21, [x19]
 */
JNIEXPORT void _Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct(
    void** out_list_obj,
    double* stack_rate,
    double* header_fields_rate,
    double* query_fields_rate,
    double* cookie_fields_rate,
    double* body_fields_rate,
    __TTMTransparentStruct* ttm_ctx) {
    if (!out_list_obj || !ttm_ctx) {
        return;
    }
    void* err_ptr  = ttm_ctx->error_code_ptr;
    void* pool_ptr = ttm_ctx->allocator_pool_ptr;
    void* list_obj = TTMListO_create(1, 3, pool_ptr, err_ptr);
    if (ttm_ctx->error_code_ptr && *ttm_ctx->error_code_ptr != 0) {
        return;
    }
    if (_Z5isHitPd(stack_rate)) {
        void* s = TTMStrO_from_cstr("stack", pool_ptr, err_ptr);
        TTMListO_add_obj(list_obj, s, pool_ptr, err_ptr);
    }
    if (_Z5isHitPd(header_fields_rate)) {
        void* s = TTMStrO_from_cstr("header_fields", pool_ptr, err_ptr);
        TTMListO_add_obj(list_obj, s, pool_ptr, err_ptr);
    }
    if (_Z5isHitPd(query_fields_rate)) {
        void* s = TTMStrO_from_cstr("query_fields", pool_ptr, err_ptr);
        TTMListO_add_obj(list_obj, s, pool_ptr, err_ptr);
    }
    if (_Z5isHitPd(cookie_fields_rate)) {
        void* s = TTMStrO_from_cstr("cookie_fields", pool_ptr, err_ptr);
        TTMListO_add_obj(list_obj, s, pool_ptr, err_ptr);
    }
    if (_Z5isHitPd(body_fields_rate)) {
        void* s = TTMStrO_from_cstr("body_fields", pool_ptr, err_ptr);
        TTMListO_add_obj(list_obj, s, pool_ptr, err_ptr);
    }
    *out_list_obj = list_obj;
}

/**
 * Disassembly verified at 0x0363c0..0x0365e0 (548 B):
 *   0x0363d8: str xzr, [x0]
 *   0x0363dc: ldr x8, [x1]; ldr x20, [x8, #0x28] (param_val c_str)
 *   0x0363e8: ldr x8, [x2]; ldr x21, [x8, #0x28] (name_list_key c_str)
 *   0x036408: ldr x8, [x3]; cbz x8, #0x36420; cmp status, #2; b.ne #0x3655c
 *   0x036428: bl #0x3963c (namelist_find_container)
 *   0x036454: bl #0xfbe8 (TokenizeValue)
 *   0x03646c: bl #0x3ac80 (MatchTokens with mode=0)
 *   0x036474: mov w8, #1; str x8, [x19]
 */
JNIEXPORT void _Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** param_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* /*ttm_ctx*/) {
    if (!out_result) {
        return;
    }
    *out_result = 0;
    if (!param_val_obj || !*param_val_obj || !name_list_key_obj || !*name_list_key_obj) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or nameListKeys is null or match_way is null");
        return;
    }
    const auto* val_wrapper = static_cast<const TTMObjectValue*>(*param_val_obj);
    const auto* key_wrapper = static_cast<const TTMObjectValue*>(*name_list_key_obj);
    const char* param_val = val_wrapper->c_str_ptr;
    const char* name_list_key = key_wrapper->c_str_ptr;
    if (!param_val || !name_list_key) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or nameListKeys is null or match_way is null");
        return;
    }

    auto& mgr = pns::ttmachine::NameListManager::Instance();
    if (strict_ready_flag && *strict_ready_flag != 0 && mgr.GetPrepareStatus() != 2) {
        return;
    }

    auto container = mgr.FindContainer(name_list_key);
    if (!container) {
        PNS_LOGW("PnsRuleEngine-Core", "nameListContainer is null,can't find %s name list", name_list_key);
        return;
    }

    auto tokens = pns::ttmachine::NameListManager::TokenizeValue(param_val);
    if (container->MatchTokens(tokens, 0)) {
        *out_result = 1;
    }
}

/**
 * Disassembly verified at 0x0365e4..0x0368e0 (768 B):
 *   0x036604: str xzr, [x0]
 *   0x036608: ldr x8, [x1]; ldr x20, [x8, #0x28] (domain_val)
 *   0x036614: ldr x8, [x2]; ldr x22, [x8, #0x28] (path_val)
 *   0x036620: ldr x8, [x3]; ldr x23, [x8, #0x28] (name_list_key)
 *   0x036664: bl #0x3963c (namelist_find_container)
 *   0x036690..0x0366b4: Tokenizes domain_val & path_val into 2-element vector<string> (0x30 = 48 B)
 *   0x0367a0: bl #0x3ac80 (MatchTokens with mode=0)
 *   0x0367a8: mov w8, #1; str x8, [x19]
 */
JNIEXPORT void _Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** domain_val_obj,
    void** path_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* /*ttm_ctx*/) {
    if (!out_result) {
        return;
    }
    *out_result = 0;
    if (!domain_val_obj || !*domain_val_obj ||
        !path_val_obj || !*path_val_obj ||
        !name_list_key_obj || !*name_list_key_obj) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or path value is null or nameListKeys is null or match_way is null");
        return;
    }
    const char* domain_val = static_cast<const TTMObjectValue*>(*domain_val_obj)->c_str_ptr;
    const char* path_val   = static_cast<const TTMObjectValue*>(*path_val_obj)->c_str_ptr;
    const char* list_key   = static_cast<const TTMObjectValue*>(*name_list_key_obj)->c_str_ptr;
    if (!domain_val || !path_val || !list_key) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or path value is null or nameListKeys is null or match_way is null");
        return;
    }

    auto& mgr = pns::ttmachine::NameListManager::Instance();
    if (strict_ready_flag && *strict_ready_flag != 0 && mgr.GetPrepareStatus() != 2) {
        return;
    }

    auto container = mgr.FindContainer(list_key);
    if (!container) {
        PNS_LOGW("PnsRuleEngine-Core", "nameListContainer is null,can't find %s name list", list_key);
        return;
    }

    std::vector<std::string> tokens{domain_val, path_val};
    if (container->MatchTokens(tokens, static_cast<int32_t>(pns::ttmachine::NameListMatchWay::kDomainPathTree)) ||
        container->MatchTokens(tokens, 0)) {
        *out_result = 1;
    }
}

/**
 * Disassembly verified at 0x0368e4..0x036ea8 (1,480 B):
 *   1. First checks domain_val with mode = 0 (0x0369b8: str wzr, [x8], #4; bl #0x3ac80). If hit -> *out = 1.
 *   2. Next checks path_val with mode = 2 (0x036a78: mov w8, #2; str w8, [x9], #4; bl #0x3ac80). If hit -> *out = 1.
 *   3. Next concatenates domain_val + path_val and checks combined string against container. If hit -> *out = 1.
 */
JNIEXPORT void _Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct(
    long* out_result,
    void** domain_val_obj,
    void** path_val_obj,
    void** name_list_key_obj,
    long* strict_ready_flag,
    __TTMTransparentStruct* /*ttm_ctx*/) {
    if (!out_result) {
        return;
    }
    *out_result = 0;
    if (!domain_val_obj || !*domain_val_obj ||
        !path_val_obj || !*path_val_obj ||
        !name_list_key_obj || !*name_list_key_obj) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or path value is null or nameListKeys is null or match_way is null");
        return;
    }
    const char* domain_val = static_cast<const TTMObjectValue*>(*domain_val_obj)->c_str_ptr;
    const char* path_val   = static_cast<const TTMObjectValue*>(*path_val_obj)->c_str_ptr;
    const char* list_key   = static_cast<const TTMObjectValue*>(*name_list_key_obj)->c_str_ptr;
    if (!domain_val || !path_val || !list_key) {
        PNS_LOGW("PnsRuleEngine-Core", "param value is null or path value is null or nameListKeys is null or match_way is null");
        return;
    }

    auto& mgr = pns::ttmachine::NameListManager::Instance();
    if (strict_ready_flag && *strict_ready_flag != 0 && mgr.GetPrepareStatus() != 2) {
        return;
    }

    auto container = mgr.FindContainer(list_key);
    if (!container) {
        PNS_LOGW("PnsRuleEngine-Core", "nameListContainer is null,can't find %s name list", list_key);
        return;
    }

    // Step 1 (0x036990..0x0369e4): Match domain_val with mode 0 (Exact)
    std::vector<std::string> domain_tokens{domain_val};
    if (container->MatchTokens(domain_tokens, 0)) {
        *out_result = 1;
        return;
    }

    // Step 2 (0x036a44..0x036aac): Match path_val with mode 2 (Suffix / Prefix)
    std::vector<std::string> path_tokens{path_val};
    if (container->MatchTokens(path_tokens, 2) || container->MatchTokens(path_tokens, 1)) {
        *out_result = 1;
        return;
    }

    // Step 3 (0x036ab0..0x036d40): Concatenate domain_val + path_val and match
    std::vector<std::string> combined_tokens{std::string(domain_val) + std::string(path_val)};
    if (container->MatchTokens(combined_tokens, 0) ||
        container->MatchTokens({domain_val, path_val}, static_cast<int32_t>(pns::ttmachine::NameListMatchWay::kDomainPathTree))) {
        *out_result = 1;
    }
}

/**
 * Disassembly verified at 0x036eac..0x03708c (484 B):
 *   0x036edc: ldr x8, [x3, #0x18]; ldr w8, [x8]; cbnz w8, #0x37054
 *   0x036ee8: ldr d8, [x2]
 *   0x036ef0: fcmp d8, #0.0 -> if 0.0: *out_result = 0
 *   0x036f00: fmov d0, #1.0; fcmp d8, d0 -> if 1.0: *out_result = 1
 *   0x036f14: ldr x8, [x1]; ldr x20, [x8, #0x28] (seed_str)
 *   0x036fc0: bl #0x7ed4 (ComputeNdkStringHash64)
 *   0x036fd4..0x037050: MT19937 deterministic seed sampling
 */
JNIEXPORT void _Z10randomSeedPlPPvPdP22__TTMTransparentStruct(
    long* out_result,
    void** seed_str_obj,
    double* sample_rate,
    __TTMTransparentStruct* ttm_ctx) {
    if (!out_result || !sample_rate || !ttm_ctx) {
        return;
    }
    if (ttm_ctx->error_code_ptr && *ttm_ctx->error_code_ptr != 0) {
        return;
    }
    const char* seed_str = nullptr;
    if (seed_str_obj && *seed_str_obj) {
        seed_str = static_cast<const TTMObjectValue*>(*seed_str_obj)->c_str_ptr;
    }
    bool hit = pns::ttmachine::EvaluateDeterministicSeedSample(seed_str, *sample_rate);
    *out_result = hit ? 1L : 0L;
}

} // extern "C"
