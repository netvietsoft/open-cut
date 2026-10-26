/**
 * @file bach_object_converter.cpp
 * @brief Implementation of CityHash64, 30-Way BachObject-to-Java Converter, NEON Widening Loops,
 *        and Pixel Format Converters for libbach-sdk-jni.so.
 *        Cài đặt chi tiết hàm băm CityHash64, bộ chuyển đổi 30 nhánh BachObject sang Java,
 *        vòng lặp mở rộng NEON và bộ chuyển đổi định dạng pixel cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 */

#include "bach_object_converter.h"

#include <algorithm>
#include <cstring>

namespace com {
namespace bytedance {
namespace bach_sdk {

namespace Bach {

// ============================================================================
// 1. Bach::BachObject Lifecycle & Factory Implementations
//    Cài đặt vòng đời và hàm khởi tạo cho Bach::BachObject [OBSERVED]
// ============================================================================

BachObject::BachObject() noexcept = default;

BachObject::BachObject(const BachObject& other) = default;

BachObject::BachObject(BachObject&& other) noexcept = default;

BachObject& BachObject::operator=(const BachObject& other) = default;

BachObject& BachObject::operator=(BachObject&& other) noexcept = default;

BachObject::~BachObject() noexcept = default;

BachObject BachObject::FromInt64(int64_t val) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kInt64;
    obj.int64_val_ = val;
    return obj;
}

BachObject BachObject::FromDouble(double val) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kDouble;
    obj.double_val_ = val;
    return obj;
}

BachObject BachObject::FromString(const std::string& val) {
    BachObject obj;
    obj.type_ = BachObjectType::kString;
    obj.string_val_ = val;
    return obj;
}

BachObject BachObject::FromVec2f(const AmazingEngine::Vector2f& v) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kVec2f;
    obj.vec2f_val_ = v;
    return obj;
}

BachObject BachObject::FromVec3f(const AmazingEngine::Vector3f& v) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kVec3f;
    obj.vec3f_val_ = v;
    return obj;
}

BachObject BachObject::FromVec4f(const AmazingEngine::Vector4f& v) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kVec4f;
    obj.vec4f_val_ = v;
    return obj;
}

BachObject BachObject::FromQuatf(const AmazingEngine::Quaternionf& q) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kQuatf;
    obj.quatf_val_ = q;
    return obj;
}

BachObject BachObject::FromMat3x3f(const AmazingEngine::Matrix3x3f& m) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kMat3x3f;
    obj.mat3x3f_val_ = m;
    return obj;
}

BachObject BachObject::FromMat4x4f(const AmazingEngine::Matrix4x4f& m) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kMat4x4f;
    obj.mat4x4f_val_ = m;
    return obj;
}

BachObject BachObject::FromRect(const AmazingEngine::Rect& r) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kRect;
    obj.rect_val_ = r;
    return obj;
}

BachObject BachObject::FromColor(const AmazingEngine::Color& c) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kColor;
    obj.color_val_ = c;
    return obj;
}

BachObject BachObject::FromImageBuffer(BachImageBuffer* img) noexcept {
    BachObject obj;
    obj.type_ = BachObjectType::kImageBuffer;
    obj.image_buffer_val_ = img;
    return obj;
}

} // namespace Bach

// ============================================================================
// 2. CityHash64 & NEON Popcount Bucket Lookup (0x005cc0..0x007028)
//    Cài đặt CityHash64 và tra cứu thùng băm bằng NEON Popcount [OBSERVED]
// ============================================================================

namespace {

inline uint64_t Fetch64LE(const uint8_t* p) noexcept {
    uint64_t result = 0;
    std::memcpy(&result, p, sizeof(uint64_t));
    return result;
}

inline uint32_t Fetch32LE(const uint8_t* p) noexcept {
    uint32_t result = 0;
    std::memcpy(&result, p, sizeof(uint32_t));
    return result;
}

} // namespace

uint64_t BachCityHash64::RotateRight64(uint64_t val, unsigned shift) noexcept {
    return shift == 0 ? val : ((val >> shift) | (val << (64U - shift)));
}

uint64_t BachCityHash64::ShiftMix(uint64_t val) noexcept {
    // [OBSERVED at 0x006c44: eor x9, x8, x8, lsr #47]
    return val ^ (val >> 47U);
}

uint64_t BachCityHash64::HashLen16(uint64_t u, uint64_t v, uint64_t mul) noexcept {
    // [OBSERVED at 0x006c80..0x006cb0]:
    //   eor x8, x12, x8
    //   mul x8, x8, x9 (mul = 0x9ddfea08eb382d69)
    //   eor x10, x11, x8
    //   eor x8, x10, x8, lsr #47
    //   mul x8, x8, x9
    //   eor x8, x8, x8, lsr #47
    //   mul x0, x8, x9
    uint64_t a = (u ^ v) * mul;
    a ^= (a >> 47U);
    uint64_t b = (v ^ a) * mul;
    b ^= (b >> 47U);
    b *= mul;
    return b;
}

uint64_t BachCityHash64::HashLen0to16(const uint8_t* s, size_t len) noexcept {
    // [OBSERVED at 0x006c08..0x006cb8]:
    //   cmp x2, #8; b.hi 0x006c6c
    //   cmp x2, #4; b.lo 0x006cb4
    if (len > 8U) {
        // 0x006c6c..0x006cb0 (len in 9..16)
        const uint64_t a = Fetch64LE(s);
        const uint64_t b = Fetch64LE(s + len - 8U);
        return HashLen16(a, RotateRight64(b + len, static_cast<unsigned>(len))) ^ b;
    }
    if (len >= 4U) {
        // 0x006c14..0x006c58 (len in 4..8)
        const uint64_t a = Fetch32LE(s);
        const uint64_t b = Fetch32LE(s + len - 4U);
        return HashLen16(len + (a << 3U), b);
    }
    if (len > 0U) {
        // 0x006cb8..0x006d18 (len in 1..3)
        //   ldrb w8, [x1]
        //   ldrb w9, [x1, x9 (len >> 1)]
        //   ldrb w11, [x1, x11 (len - 1)]
        //   add w8, w8, w9, lsl #8
        //   add w9, w2, w11, lsl #2
        //   mul x8, x8, k2; mul x9, x9, k0; eor x8, x9, x8
        //   eor x8, x8, x8, lsr #47; mul x0, x8, k2
        const uint8_t a = s[0];
        const uint8_t b = s[len >> 1U];
        const uint8_t c = s[len - 1U];
        const uint32_t y = static_cast<uint32_t>(a) + (static_cast<uint32_t>(b) << 8U);
        const uint32_t z = static_cast<uint32_t>(len) + (static_cast<uint32_t>(c) << 2U);
        return ShiftMix(static_cast<uint64_t>(y) * k2 ^ static_cast<uint64_t>(z) * k0) * k2;
    }
    // 0x006c5c..0x006c68 (len == 0 -> returns k2 = 0x9ae16a3b2f90404f)
    return k2;
}

uint64_t BachCityHash64::HashLen17to32(const uint8_t* s, size_t len) noexcept {
    // [OBSERVED at 0x006d1c..0x006d94]:
    const uint64_t a = Fetch64LE(s) * k1;
    const uint64_t b = Fetch64LE(s + 8U);
    const uint64_t c = Fetch64LE(s + len - 8U) * k2;
    const uint64_t d = Fetch64LE(s + len - 16U) * k0;
    return HashLen16(
        RotateRight64(a - b, 43U) + RotateRight64(c, 30U) + d,
        a + RotateRight64(b ^ k3, 20U) - c + len);
}

std::pair<uint64_t, uint64_t> BachCityHash64::WeakHashLen32WithSeeds(
    uint64_t w, uint64_t x, uint64_t y, uint64_t z, uint64_t a, uint64_t b) noexcept {
    // [OBSERVED at 0x006eb4..0x006f50]:
    a += w;
    b = RotateRight64(b + a + z, 21U);
    const uint64_t c = a;
    a += x;
    a += y;
    b += RotateRight64(a, 44U);
    return {a + z, b + c};
}

std::pair<uint64_t, uint64_t> BachCityHash64::WeakHashLen32WithSeeds(
    const uint8_t* s, uint64_t a, uint64_t b) noexcept {
    return WeakHashLen32WithSeeds(
        Fetch64LE(s),
        Fetch64LE(s + 8U),
        Fetch64LE(s + 16U),
        Fetch64LE(s + 24U),
        a,
        b);
}

uint64_t BachCityHash64::HashLen33to64(const uint8_t* s, size_t len) noexcept {
    // [OBSERVED at 0x006d98..0x006e64]:
    uint64_t z = Fetch64LE(s + 24U);
    uint64_t a = Fetch64LE(s) + (len + Fetch64LE(s + len - 16U)) * k0;
    uint64_t b = RotateRight64(a + z, 52U);
    uint64_t c = RotateRight64(a, 37U);
    a += Fetch64LE(s + 8U);
    c += RotateRight64(a, 7U);
    a += Fetch64LE(s + 16U);
    uint64_t vf = a + z;
    uint64_t vs = b + RotateRight64(a, 31U) + c;
    a = Fetch64LE(s + 16U) + Fetch64LE(s + len - 32U);
    z = Fetch64LE(s + len - 8U);
    b = RotateRight64(a + z, 52U);
    c = RotateRight64(a, 37U);
    a += Fetch64LE(s + len - 24U);
    c += RotateRight64(a, 7U);
    a += Fetch64LE(s + len - 16U);
    uint64_t wf = a + z;
    uint64_t ws = b + RotateRight64(a, 31U) + c;
    uint64_t r = ShiftMix((vf + ws) * k2 + (wf + vs) * k0);
    return ShiftMix(r * k0 + vs) * k2;
}

uint64_t BachCityHash64::Hash(const void* key, size_t len) noexcept {
    // [OBSERVED at 0x006be0..0x007028]:
    //   0x006be0: cmp x2, #0x20; b.hi 0x006bf0
    //   0x006be8: cmp x2, #0x10; b.hi 0x006d1c (HashLen17to32)
    //   0x006bf0: cmp x2, #0x40; b.ls 0x006d98 (HashLen33to64)
    const auto* s = static_cast<const uint8_t*>(key);
    if (len <= 32U) {
        if (len <= 16U) {
            return HashLen0to16(s, len);
        }
        return HashLen17to32(s, len);
    }
    if (len <= 64U) {
        return HashLen33to64(s, len);
    }

    // 0x006e68..0x007028: Main 64-byte chunk loop for len > 64
    uint64_t x = Fetch64LE(s + len - 40U);
    uint64_t y = Fetch64LE(s + len - 16U) + Fetch64LE(s + len - 56U);
    uint64_t z = HashLen16(Fetch64LE(s + len - 48U) + len, Fetch64LE(s + len - 24U));
    std::pair<uint64_t, uint64_t> v = WeakHashLen32WithSeeds(s + len - 64U, len, z);
    std::pair<uint64_t, uint64_t> w = WeakHashLen32WithSeeds(s + len - 32U, y + k1, x);
    x = x * k1 + Fetch64LE(s);

    len = (len - 1U) & ~static_cast<size_t>(63U);
    do {
        x = RotateRight64(x + y + v.first + Fetch64LE(s + 8U), 37U) * k1;
        y = RotateRight64(y + v.second + Fetch64LE(s + 48U), 42U) * k1;
        x ^= w.second;
        y += v.first + Fetch64LE(s + 40U);
        z = RotateRight64(z + w.first, 33U) * k1;
        v = WeakHashLen32WithSeeds(s, v.second * k1, x + w.first);
        w = WeakHashLen32WithSeeds(s + 32U, z + w.second, y + Fetch64LE(s + 16U));
        std::swap(z, x);
        s += 64U;
        len -= 64U;
    } while (len != 0U);

    return HashLen16(HashLen16(v.first, w.first) + ShiftMix(y) * k1 + z,
                     HashLen16(v.second, w.second) + x);
}

size_t ComputeLibcxxHashBucketIndex(uint64_t hash, size_t bucket_count) noexcept {
    // [OBSERVED at 0x005cc0..0x005cde & 0x0062e0..0x0062fc]:
    //   cbz x8, #0x5d90
    //   sub x9, x8, #1
    //   fmov d0, x8
    //   cnt v0.8b, v0.8b
    //   uaddlv h0, v0.8b
    //   fmov w10, s0
    //   cmp w10, #1
    //   b.hi #0x5cd8 (udiv / msub: hash % bucket_count)
    //   and x9, x9, x24 (hash & (bucket_count - 1))
    if (bucket_count == 0U) {
        return 0U;
    }
    // Count set bits across all 8 bytes (matching `cnt v0.8b, v0.8b; uaddlv h0, v0.8b`)
    uint64_t temp = bucket_count;
    unsigned popcount = 0U;
    while (temp != 0U) {
        popcount += static_cast<unsigned>(temp & 1U);
        temp >>= 1U;
    }
    if (popcount <= 1U) {
        return static_cast<size_t>(hash & (bucket_count - 1U));
    }
    return static_cast<size_t>(hash % bucket_count);
}

// ============================================================================
// 3. 6 NEON SIMD Vector Widening & Copy Routines (0x00a994..0x00b80c)
//    Cài đặt 6 vòng lặp mở rộng kiểu dữ liệu & sao chép vector NEON [OBSERVED]
// ============================================================================

std::vector<int64_t> WidenUint16ToInt64Vector(const uint16_t* begin, const uint16_t* end) {
    // [OBSERVED at 0x00a994..0x00aad0]:
    //   Processes 4 uint16_t elements per vectorized iteration:
    //     ldr d0, [x8]; ushll v0.4s, v0.4h, #0; ushll v1.2d, v0.2s, #0; ushll2 v0.2d, v0.4s, #0; stp q1, q0, [x13, #-0x10]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<int64_t> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 0U]));
        out[i + 1U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 1U]));
        out[i + 2U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 2U]));
        out[i + 3U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 3U]));
    }
    for (; i < count; ++i) {
        out[i] = static_cast<int64_t>(static_cast<uint64_t>(begin[i]));
    }
    return out;
}

std::vector<int64_t> WidenInt16ToInt64Vector(const int16_t* begin, const int16_t* end) {
    // [OBSERVED at 0x00ac64..0x00ada0]:
    //   Processes 4 int16_t elements per vectorized iteration:
    //     ldr d0, [x8]; sshll v0.4s, v0.4h, #0; sshll v1.2d, v0.2s, #0; sshll2 v0.2d, v0.4s, #0; stp q1, q0, [x13, #-0x10]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<int64_t> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = static_cast<int64_t>(begin[i + 0U]);
        out[i + 1U] = static_cast<int64_t>(begin[i + 1U]);
        out[i + 2U] = static_cast<int64_t>(begin[i + 2U]);
        out[i + 3U] = static_cast<int64_t>(begin[i + 3U]);
    }
    for (; i < count; ++i) {
        out[i] = static_cast<int64_t>(begin[i]);
    }
    return out;
}

std::vector<int64_t> WidenUint32ToInt64Vector(const uint32_t* begin, const uint32_t* end) {
    // [OBSERVED at 0x00af34..0x00b05c]:
    //   Processes 4 uint32_t elements per vectorized iteration:
    //     ldr d0, [x8, #-8]; ldr d1, [x8]; ushll v0.2d, v0.2s, #0; ushll v1.2d, v1.2s, #0; stp q0, q1, [x13, #-0x10]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<int64_t> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 0U]));
        out[i + 1U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 1U]));
        out[i + 2U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 2U]));
        out[i + 3U] = static_cast<int64_t>(static_cast<uint64_t>(begin[i + 3U]));
    }
    for (; i < count; ++i) {
        out[i] = static_cast<int64_t>(static_cast<uint64_t>(begin[i]));
    }
    return out;
}

std::vector<int64_t> WidenInt32ToInt64Vector(const int32_t* begin, const int32_t* end) {
    // [OBSERVED at 0x00b1f0..0x00b318]:
    //   Processes 4 int32_t elements per vectorized iteration:
    //     ldr d0, [x8, #-8]; ldr d1, [x8]; sshll v0.2d, v0.2s, #0; sshll v1.2d, v1.2s, #0; stp q0, q1, [x13, #-0x10]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<int64_t> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = static_cast<int64_t>(begin[i + 0U]);
        out[i + 1U] = static_cast<int64_t>(begin[i + 1U]);
        out[i + 2U] = static_cast<int64_t>(begin[i + 2U]);
        out[i + 3U] = static_cast<int64_t>(begin[i + 3U]);
    }
    for (; i < count; ++i) {
        out[i] = static_cast<int64_t>(begin[i]);
    }
    return out;
}

std::vector<double> WidenFloatToDoubleVector(const float* begin, const float* end) {
    // [OBSERVED at 0x00b4ac..0x00b5d4]:
    //   Processes 4 float elements per vectorized iteration:
    //     ldr d0, [x8, #-8]; ldr d1, [x8]; fcvtl v0.2d, v0.2s; fcvtl v1.2d, v1.2s; stp q0, q1, [x13, #-0x10]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<double> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = static_cast<double>(begin[i + 0U]);
        out[i + 1U] = static_cast<double>(begin[i + 1U]);
        out[i + 2U] = static_cast<double>(begin[i + 2U]);
        out[i + 3U] = static_cast<double>(begin[i + 3U]);
    }
    for (; i < count; ++i) {
        out[i] = static_cast<double>(begin[i]);
    }
    return out;
}

template <typename T64>
std::vector<T64> CopyAligned64BitVector(const T64* begin, const T64* end) {
    // [OBSERVED at 0x00b768..0x00b80c]:
    //   Processes 4 64-bit elements (32 bytes) per vectorized iteration:
    //     ldp q0, q1, [x8, #-16]; stp q0, q1, [x13, #-16]
    if (begin == nullptr || end == nullptr || end <= begin) {
        return {};
    }
    const size_t count = static_cast<size_t>(end - begin);
    std::vector<T64> out(count);
    size_t i = 0;
    const size_t vec_limit = count & ~static_cast<size_t>(3U);
    for (; i < vec_limit; i += 4U) {
        out[i + 0U] = begin[i + 0U];
        out[i + 1U] = begin[i + 1U];
        out[i + 2U] = begin[i + 2U];
        out[i + 3U] = begin[i + 3U];
    }
    for (; i < count; ++i) {
        out[i] = begin[i];
    }
    return out;
}

template std::vector<int64_t> CopyAligned64BitVector<int64_t>(const int64_t*, const int64_t*);
template std::vector<double> CopyAligned64BitVector<double>(const double*, const double*);

// ============================================================================
// 4. 30-Way Jump Table & `ConvertBachObjectToJava` (0x00702c..0x00a980)
//    Bảng nhảy 30 nhánh & Hàm `ConvertBachObjectToJava` [OBSERVED]
// ============================================================================

uint64_t ComputeConvertBachObjectBranchTargetVa(Bach::BachObjectType type) noexcept {
    // [OBSERVED at 0x007060..0x00708c]:
    //   0x007060: ldr w8, [x1, #0x80]
    //   0x007064: sub w8, w8, #1
    //   0x007068: cmp w8, #0x1d (29)
    //   0x00706c: b.hi #0x98bc (returns nullptr)
    //   0x007078: adr x10, #0x7090
    //   0x00707c: ldrh w11, [x9, x8, lsl #1] (table at .rodata 0x014f5c)
    //   0x007080: add x10, x10, x11, lsl #2
    //   0x00708c: br x10
    const int32_t raw_type = static_cast<int32_t>(type);
    const uint32_t idx = static_cast<uint32_t>(raw_type - 1);
    if (idx > 29U) {
        return 0x0098bcULL;
    }
    const uint16_t disp = kConvertBachObjectJumpOffsets[idx];
    return 0x007090ULL + static_cast<uint64_t>(disp) * 4ULL;
}

std::shared_ptr<JavaBachObject> ConvertBachObjectToJava(const Bach::BachObject& obj) {
    // [OBSERVED at 0x00702c..0x00a980]:
    //   First calls BachObject::GetType() (0x007058: bl #0x35d0).
    //   Subtracts 1 and checks `idx <= 0x1d` (29). If `idx > 29`, branches to `0x0098bc` returning nullptr.
    const Bach::BachObjectType type = obj.GetType();
    const uint32_t idx = static_cast<uint32_t>(static_cast<int32_t>(type) - 1);
    if (idx > 29U) {
        return nullptr;
    }

    auto j_obj = std::make_shared<JavaBachObject>();
    j_obj->value_type = type;

    switch (type) {
        case Bach::BachObjectType::kInt64: {
            // Case 1 @ 0x007090: GetInt64() -> AlgorithmResultUnion.int64Val (J), enum "Int64"
            j_obj->value_union.int64_val = obj.GetInt64();
            break;
        }
        case Bach::BachObjectType::kInt64Vec: {
            // Case 2 @ 0x0075a0: GetInt64Vec() -> CopyAligned64BitVector (0x00b768) -> [J, enum "Int64Vec"
            auto vec_ptr = obj.GetInt64Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.int64_vec =
                    CopyAligned64BitVector<int64_t>(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kDouble: {
            // Case 3 @ 0x007894: GetDouble() -> AlgorithmResultUnion.doubleVal (D), enum "Double"
            j_obj->value_union.double_val = obj.GetDouble();
            break;
        }
        case Bach::BachObjectType::kDoubleVec: {
            // Case 4 @ 0x009b98: GetDoubleVec() -> CopyAligned64BitVector (0x00b768) -> [D, enum "DoubleVec"
            auto vec_ptr = obj.GetDoubleVec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.double_vec =
                    CopyAligned64BitVector<double>(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kVec2f: {
            // Case 5 @ 0x008730: GetVec2f() -> Vec2f(FF)V, enum "Vec2f"
            j_obj->value_union.vec2f_val = obj.GetVec2f();
            break;
        }
        case Bach::BachObjectType::kVec3f: {
            // Case 6 @ 0x007b84: GetVec3f() -> Vec3f(FFF)V, enum "Vec3f"
            j_obj->value_union.vec3f_val = obj.GetVec3f();
            break;
        }
        case Bach::BachObjectType::kVec4f: {
            // Case 7 @ 0x007c64: GetVec4f() -> Vec4f(FFFF)V, enum "Vec4f"
            j_obj->value_union.vec4f_val = obj.GetVec4f();
            break;
        }
        case Bach::BachObjectType::kQuatf: {
            // Case 8 @ 0x008ecc: GetQuatf() -> Quatf(FFFF)V, enum "Quatf"
            j_obj->value_union.quatf_val = obj.GetQuatf();
            break;
        }
        case Bach::BachObjectType::kMat3x3f: {
            // Case 9 @ 0x0091fc: GetMat3x3f() -> float[3][3] -> Mat3x3f([[F)V, enum "Mat3x3f"
            j_obj->value_union.mat3x3f_val = obj.GetMat3x3f();
            break;
        }
        case Bach::BachObjectType::kMat4x4f: {
            // Case 10 @ 0x008784: GetMat4x4f() -> float[4][4] -> Mat4x4f([[F)V, enum "Mat4x4f"
            j_obj->value_union.mat4x4f_val = obj.GetMat4x4f();
            break;
        }
        case Bach::BachObjectType::kString: {
            // Case 11 @ 0x0081f0: GetString() -> stdStringToJString (0x010338), enum "String"
            j_obj->value_union.string_val = obj.GetString();
            break;
        }
        case Bach::BachObjectType::kImageBuffer: {
            // Case 12 @ 0x0088a0: GetImageBuffer() -> retain() (+0x00) -> BachBitmapHandle.m_pointer, enum "ImageBuffer"
            Bach::BachImageBuffer* img = obj.GetImageBuffer();
            if (img != nullptr) {
                img->retain();
                j_obj->value_union.bitmap_handle_ptr = reinterpret_cast<int64_t>(img);
            }
            break;
        }
        case Bach::BachObjectType::kRect: {
            // Case 13 @ 0x0095f8: GetRect() -> android/graphics/RectF(FFFF)V, enum "Rect"
            j_obj->value_union.rect_val = obj.GetRect();
            break;
        }
        case Bach::BachObjectType::kColor: {
            // Case 14 @ 0x009604: GetColor() -> Color(FFFF)V, enum "Color"
            j_obj->value_union.color_val = obj.GetColor();
            break;
        }
        case Bach::BachObjectType::kInt8Vec: {
            // Case 15 @ 0x008430: GetInt8Vec() -> widens int8_t to int64_t [J (ldrsb x9, [x22]), enum "Int8Vec"
            auto vec_ptr = obj.GetInt8Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                const int8_t* b = vec_ptr->begin_ptr();
                const int8_t* e = vec_ptr->end_ptr();
                j_obj->value_union.int64_vec.reserve(static_cast<size_t>(e - b));
                for (const int8_t* p = b; p != e; ++p) {
                    j_obj->value_union.int64_vec.push_back(static_cast<int64_t>(*p));
                }
            }
            break;
        }
        case Bach::BachObjectType::kUint8Vec: {
            // Case 16 @ 0x0072a0: GetUint8Vec() -> widens uint8_t to int64_t [J (ldrb w9, [x22]), enum "Uint8Vec"
            auto vec_ptr = obj.GetUint8Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                const uint8_t* b = vec_ptr->begin_ptr();
                const uint8_t* e = vec_ptr->end_ptr();
                j_obj->value_union.int64_vec.reserve(static_cast<size_t>(e - b));
                for (const uint8_t* p = b; p != e; ++p) {
                    j_obj->value_union.int64_vec.push_back(static_cast<int64_t>(static_cast<uint64_t>(*p)));
                }
            }
            break;
        }
        case Bach::BachObjectType::kInt16Vec: {
            // Case 17 @ 0x007be4: GetInt16Vec() -> WidenInt16ToInt64Vector (0x00ac64) -> [J, enum "Int16Vec"
            auto vec_ptr = obj.GetInt16Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.int64_vec =
                    WidenInt16ToInt64Vector(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kUint16Vec: {
            // Case 18 @ 0x00782c: GetUint16Vec() -> WidenUint16ToInt64Vector (0x00a994) -> [J, enum "Uint16Vec"
            auto vec_ptr = obj.GetUint16Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.int64_vec =
                    WidenUint16ToInt64Vector(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kInt32Vec: {
            // Case 19 @ 0x00917c: GetInt32Vec() -> WidenInt32ToInt64Vector (0x00b1f0) -> [J, enum "Int32Vec"
            auto vec_ptr = obj.GetInt32Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.int64_vec =
                    WidenInt32ToInt64Vector(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kUint32Vec: {
            // Case 20 @ 0x008ad4: GetUint32Vec() -> WidenUint32ToInt64Vector (0x00af34) -> [J, enum "Uint32Vec"
            auto vec_ptr = obj.GetUint32Vec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.int64_vec =
                    WidenUint32ToInt64Vector(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kFloatVec: {
            // Case 21 @ 0x009578: GetFloatVec() -> WidenFloatToDoubleVector (0x00b4ac) -> [D, enum "FloatVec"
            auto vec_ptr = obj.GetFloatVec();
            if (vec_ptr && vec_ptr->begin_ptr() != vec_ptr->end_ptr()) {
                j_obj->value_union.double_vec =
                    WidenFloatToDoubleVector(vec_ptr->begin_ptr(), vec_ptr->end_ptr());
            }
            break;
        }
        case Bach::BachObjectType::kStringVec: {
            // Case 22 @ 0x008b54: GetStringVec() -> ArrayList<String>, enum "StringVec"
            auto vec_ptr = obj.GetStringVec();
            if (vec_ptr) {
                j_obj->value_union.string_vec = vec_ptr->vector();
            }
            break;
        }
        case Bach::BachObjectType::kVec2fVec: {
            // Case 23 @ 0x008ed8: GetVec2fVec() -> allocates 8-byte Vec2f per element (tag=4 @ +0x80),
            // recursively calls convertBachObjectToJava -> BachObject[], enum "Vec2fVec"
            auto vec_ptr = obj.GetVec2fVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Vector2f(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kVec2f, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kVec3fVec: {
            // Case 24 @ 0x0098c4: GetVec3fVec() -> allocates 12-byte Vec3f per element (tag=5 @ +0x80),
            // stride 0x0c (`madd x9, x8, x9, x11` where `x9 = 0xaaaaaaaaaaaaaaaab`), enum "Vec3fVec"
            auto vec_ptr = obj.GetVec3fVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Vector3f(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kVec3f, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kVec4fVec: {
            // Case 25 @ 0x009ec0: GetVec4fVec() -> allocates 16-byte Vec4f per element (tag=6 @ +0x80), enum "Vec4fVec"
            auto vec_ptr = obj.GetVec4fVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Vector4f(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kVec4f, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kQuatfVec: {
            // Case 26 @ 0x007f44: GetQuatfVec() -> allocates 16-byte Quatf per element (tag=9 @ +0x80), enum "QuatfVec"
            auto vec_ptr = obj.GetQuatfVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Quaternionf(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kQuatf, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kMat3x3fVec: {
            // Case 27 @ 0x007c70: GetMat3x3fVec() -> allocates 36-byte (0x24) Mat3x3f per element (tag=7 @ +0x80),
            // count computed via `0x38e38e38e38e38e3` magic multiplier (div by 9), enum "Mat3x3fVec"
            auto vec_ptr = obj.GetMat3x3fVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Matrix3x3f(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kMat3x3f, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kMat4x4fVec: {
            // Case 28 @ 0x00a6c8: GetMat4x4fVec() -> allocates 64-byte (0x40) Mat4x4f per element (tag=8 @ +0x80), enum "Mat4x4fVec"
            auto vec_ptr = obj.GetMat4x4fVec();
            if (vec_ptr) {
                for (const auto& item : vec_ptr->vector()) {
                    Bach::BachObject elem;
                    auto* raw = new AmazingEngine::Matrix4x4f(item);
                    elem.SetInternalUnionTag(Bach::BachInternalUnionTag::kMat4x4f, raw);
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(elem));
                    delete raw;
                }
            }
            break;
        }
        case Bach::BachObjectType::kBachVec: {
            // Case 29 @ 0x00a418: GetBachVec() -> copies std::vector<BachObject> (stride 0x88, magic 0xf0f0f0f0f0f0f0f1),
            // recursively calls convertBachObjectToJava -> BachObject[], enum "BachVec"
            const Bach::BachVector* bvec = obj.GetBachVec();
            if (bvec != nullptr) {
                for (const auto& child : bvec->items()) {
                    j_obj->value_union.vec_val.push_back(ConvertBachObjectToJava(child));
                }
            }
            break;
        }
        case Bach::BachObjectType::kBachMap: {
            // Case 30 @ 0x00a16c: GetBachMap() -> copies unordered_map<string, BachObject> (0x00c114),
            // recursively calls convertBachObjectToJava -> java/util/HashMap, enum "BachMap"
            const Bach::BachMap* bmap = obj.GetBachMap();
            if (bmap != nullptr) {
                for (const auto& kv : bmap->map()) {
                    j_obj->value_union.map_val[kv.first] = ConvertBachObjectToJava(kv.second);
                }
            }
            break;
        }
        default:
            return nullptr;
    }

    return j_obj;
}

// ============================================================================
// 5. 4 NEON Pixel Format Converters & `BachBitmapHandle_nativeGet`
//    4 hàm chuyển đổi định dạng pixel NEON & `BachBitmapHandle_nativeGet` [OBSERVED]
// ============================================================================

void ConvertGray8ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept {
    // [OBSERVED at 0x00ff4c..0x010008]:
    //   0x00ff4c: cmp w2, #1; b.lt 0x010008
    //   0x00ff68: movi v3.16b, #0xff; movi v7.16b, #0xff
    //   0x00ff7c: ldp q0, q4, [x8, #-0x10] (loads 32 GRAY8 pixels per vector loop)
    //   0x00ff8c: st4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x10], #64 (where v0=v1=v2=Y, v3=0xFF)
    //   0x00ff90: st4 {v4.16b, v5.16b, v6.16b, v7.16b}, [x10]
    if (src == nullptr || dst == nullptr || pixel_count < 1) {
        return;
    }
    int32_t i = 0;
    const int32_t vec32_limit = pixel_count & ~31;
    for (; i < vec32_limit; i += 32) {
        for (int32_t k = 0; k < 32; ++k) {
            const uint8_t y = src[i + k];
            uint8_t* out = dst + (i + k) * 4;
            out[0] = y;
            out[1] = y;
            out[2] = y;
            out[3] = 0xFFU;
        }
    }
    for (; i < pixel_count; ++i) {
        const uint8_t y = src[i];
        uint8_t* out = dst + i * 4;
        out[0] = y;
        out[1] = y;
        out[2] = y;
        out[3] = 0xFFU;
    }
}

void ConvertRGB888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept {
    // [OBSERVED at 0x01000c..0x0100d8]:
    //   0x01000c: cmp w2, #1; b.lt 0x0100d8
    //   0x010030: movi v3.16b, #0xff
    //   0x010040: ld3 {v0.16b, v1.16b, v2.16b}, [x12] (loads 16 RGB888 pixels = 48 bytes)
    //   0x010048: st4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x13] (stores 16 RGBA8888 pixels = 64 bytes)
    if (src == nullptr || dst == nullptr || pixel_count < 1) {
        return;
    }
    int32_t i = 0;
    const int32_t vec16_limit = pixel_count & ~15;
    for (; i < vec16_limit; i += 16) {
        for (int32_t k = 0; k < 16; ++k) {
            const uint8_t* in = src + (i + k) * 3;
            uint8_t* out = dst + (i + k) * 4;
            out[0] = in[0]; // R
            out[1] = in[1]; // G
            out[2] = in[2]; // B
            out[3] = 0xFFU; // A
        }
    }
    for (; i < pixel_count; ++i) {
        const uint8_t* in = src + i * 3;
        uint8_t* out = dst + i * 4;
        out[0] = in[0];
        out[1] = in[1];
        out[2] = in[2];
        out[3] = 0xFFU;
    }
}

void ConvertBGR888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept {
    // [OBSERVED at 0x0100dc..0x0101c4]:
    //   0x0100dc: cmp w2, #1; b.lt 0x0101c4
    //   0x010100: movi v4.16b, #0xff
    //   0x010110: ld3 {v3.16b, v1.16b, v2.16b}, [x12] (v3=B, v1=G, v2=R)
    //   0x010118: mov v0.16b, v2.16b; mov v2.16b, v3.16b; mov v3.16b, v4.16b
    //   0x010124: st4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x13] (v0=R, v1=G, v2=B, v3=0xFF)
    if (src == nullptr || dst == nullptr || pixel_count < 1) {
        return;
    }
    int32_t i = 0;
    const int32_t vec16_limit = pixel_count & ~15;
    for (; i < vec16_limit; i += 16) {
        for (int32_t k = 0; k < 16; ++k) {
            const uint8_t* in = src + (i + k) * 3;
            uint8_t* out = dst + (i + k) * 4;
            out[0] = in[2]; // R (from B,G,R[2])
            out[1] = in[1]; // G (from B,G,R[1])
            out[2] = in[0]; // B (from B,G,R[0])
            out[3] = 0xFFU; // A
        }
    }
    for (; i < pixel_count; ++i) {
        const uint8_t* in = src + i * 3;
        uint8_t* out = dst + i * 4;
        out[0] = in[2];
        out[1] = in[1];
        out[2] = in[0];
        out[3] = 0xFFU;
    }
}

void ConvertBGRA8888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept {
    // [OBSERVED at 0x0101c8..0x0102ac]:
    //   0x0101c8: cmp w2, #1; b.lt 0x0102ac
    //   0x0101ec: ld4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x11] (v0=B, v1=G, v2=R, v3=A)
    //   0x0101f4: mov v4.16b, v0.16b; mov v0.16b, v2.16b; mov v2.16b, v4.16b
    //   0x010200: st4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x12] (v0=R, v1=G, v2=B, v3=A)
    if (src == nullptr || dst == nullptr || pixel_count < 1) {
        return;
    }
    int32_t i = 0;
    const int32_t vec16_limit = pixel_count & ~15;
    for (; i < vec16_limit; i += 16) {
        for (int32_t k = 0; k < 16; ++k) {
            const uint8_t* in = src + (i + k) * 4;
            uint8_t* out = dst + (i + k) * 4;
            const uint8_t b = in[0];
            const uint8_t g = in[1];
            const uint8_t r = in[2];
            const uint8_t a = in[3];
            out[0] = r;
            out[1] = g;
            out[2] = b;
            out[3] = a;
        }
    }
    for (; i < pixel_count; ++i) {
        const uint8_t* in = src + i * 4;
        uint8_t* out = dst + i * 4;
        const uint8_t b = in[0];
        const uint8_t g = in[1];
        const uint8_t r = in[2];
        const uint8_t a = in[3];
        out[0] = r;
        out[1] = g;
        out[2] = b;
        out[3] = a;
    }
}

bool ExtractBachBitmapHandleToRGBA8888(const Bach::BachImageBuffer* handle,
                                       std::vector<uint8_t>* out_rgba_pixels,
                                       int32_t* out_width,
                                       int32_t* out_height) {
    // [OBSERVED at 0x00eb38..0x00edcf]:
    //   1. Checks handle != nullptr (`cbz x21, #0xed18` @ 0x00eb60).
    //   2. Reads width = [handle + 0x14], height = [handle + 0x18] (`ldp w2, w3, [x21, #0x14]` @ 0x00ebfc).
    //   3. Checks format = [handle + 0x68] <= 4 (`ldr w8, [x21, #0x68]; cmp w8, #4; b.hi #0xecfc` @ 0x00ec2c..0x00ec34).
    //   4. Dispatches via `.rodata 0x015a01..0x015a05`:
    //      - Format 0 (kGray8):    ConvertGray8ToRGBA8888(src, dst, width * height)
    //      - Format 1 (kRGB888):   ConvertRGB888ToRGBA8888(src, dst, width * height)
    //      - Format 2 (kBGR888):   ConvertBGR888ToRGBA8888(src, dst, width * height)
    //      - Format 3 (kRGBA8888): memcpy(dst, src, (width * height) << 2)
    //      - Format 4 (kBGRA8888): ConvertBGRA8888ToRGBA8888(src, dst, width * height)
    if (handle == nullptr || out_rgba_pixels == nullptr) {
        return false;
    }
    const int32_t width = handle->width();
    const int32_t height = handle->height();
    if (width <= 0 || height <= 0) {
        return false;
    }
    const auto* out_vec = handle->output_data();
    if (out_vec == nullptr || out_vec->begin_ptr() == nullptr) {
        return false;
    }
    const uint32_t fmt = static_cast<uint32_t>(static_cast<int32_t>(handle->output_format()));
    if (fmt > 4U) {
        return false;
    }

    const int32_t pixel_count = width * height;
    out_rgba_pixels->resize(static_cast<size_t>(pixel_count) * 4U);
    const uint8_t* src = out_vec->begin_ptr();
    uint8_t* dst = out_rgba_pixels->data();

    switch (handle->output_format()) {
        case Bach::BachPixelFormat::kGray8:
            ConvertGray8ToRGBA8888(src, dst, pixel_count);
            break;
        case Bach::BachPixelFormat::kRGB888:
            ConvertRGB888ToRGBA8888(src, dst, pixel_count);
            break;
        case Bach::BachPixelFormat::kBGR888:
            ConvertBGR888ToRGBA8888(src, dst, pixel_count);
            break;
        case Bach::BachPixelFormat::kRGBA8888:
            std::memcpy(dst, src, static_cast<size_t>(pixel_count) << 2U);
            break;
        case Bach::BachPixelFormat::kBGRA8888:
            ConvertBGRA8888ToRGBA8888(src, dst, pixel_count);
            break;
    }

    if (out_width != nullptr) *out_width = width;
    if (out_height != nullptr) *out_height = height;
    return true;
}

} // namespace bach_sdk
} // namespace bytedance
} // namespace com
