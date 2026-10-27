// ============================================================================
// File: vcbasekit_types.h
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit & Embedded JsonCpp)
//
// Description (EN):
// Exact AArch64 ABI types, constants, and data structures reconstructed from
// libvcbasekit.so, covering:
//   1. Json::Value numeric limit constants at .rodata 0x02bec8..0x02bf08
//   2. com::ss::vcbkit synchronization, clock/time, 3-tier COW/SSO String,
//      thread pool, message loop, ALOG wrapper, and JNI UnExpected bridge.
//
// Mô tả (VI):
// Định nghĩa kiểu dữ liệu, hằng số và cấu trúc chuẩn ABI AArch64 phục hồi từ
// libvcbasekit.so, bao gồm:
//   1. 9 hằng số giới hạn số học Json::Value tại .rodata 0x02bec8..0x02bf08
//   2. Các kiểu đồng bộ hóa, đồng hồ thời gian, chuỗi 3 tầng COW/SSO, hồ luồng,
//      vòng lặp thông điệp, cầu nối ALOG và JNI UnExpected của com::ss::vcbkit.
// ============================================================================

#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <vector>

struct _JavaVM;
struct _JNIEnv;
using JavaVM = _JavaVM;
using JNIEnv = _JNIEnv;

namespace Json {

using Int = int32_t;
using UInt = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;
using LargestInt = int64_t;
using LargestUInt = uint64_t;
using ArrayIndex = uint32_t;

// ============================================================================
// 1. Exported STT_OBJECT Numeric Limits in .rodata (0x02bec8..0x02bf08)
// 9 hằng số giới hạn số nguyên xuất khẩu trong .rodata (0x02bec8..0x02bf08).
// ============================================================================
constexpr LargestInt  kJsonMaxLargestInt  =  0x7FFFFFFFFFFFFFFFLL;  // 0x02bec8 (8 B)
constexpr LargestUInt kJsonMaxLargestUInt =  0xFFFFFFFFFFFFFFFFULL; // 0x02bed0 (8 B)
constexpr LargestInt  kJsonMinLargestInt  = -0x7FFFFFFFFFFFFFFFLL - 1LL; // 0x02bed8 (8 B)
constexpr Int         kJsonMaxInt         =  0x7FFFFFFF;            // 0x02bee0 (4 B)
constexpr Int         kJsonMinInt         = -0x7FFFFFFF - 1;        // 0x02bee8 (4 B)
constexpr UInt        kJsonMaxUInt        =  0xFFFFFFFFU;           // 0x02beec (4 B)
constexpr Int64       kJsonMinInt64       = -0x7FFFFFFFFFFFFFFFLL - 1LL; // 0x02bef0 (8 B)
constexpr Int64       kJsonMaxInt64       =  0x7FFFFFFFFFFFFFFFLL;  // 0x02bef8 (8 B)
constexpr UInt64      kJsonMaxUInt64      =  0xFFFFFFFFFFFFFFFFULL; // 0x02bf00 (8 B)

enum ValueType : uint8_t {
    nullValue    = 0,
    intValue     = 1,
    uintValue    = 2,
    realValue    = 3,
    stringValue  = 4,
    booleanValue = 5,
    arrayValue   = 6,
    objectValue  = 7
};

enum CommentPlacement : uint32_t {
    commentBefore          = 0,
    commentAfterOnSameLine = 1,
    commentAfter           = 2,
    numberOfCommentPlacement = 3
};

} // namespace Json

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// 2. Clock, TimeDelta & TimePoint Constants (0x027d98..0x027e10)
// Verified from TimePoint<Clock::Fast1>::now (0x027db8):
//   mov w10, #0xca00 ; movk w10, #0x3b9a, lsl #16 (0x3B9ACA00 = 1,000,000,000)
//   madd x0, x9, x10, x8 (tv_sec * 1,000,000,000 + tv_nsec)
// Hằng số thời gian đối chiếu từ TimePoint<Clock::Fast1>::now (0x027db8).
// ============================================================================
constexpr uint64_t kNanosecondsPerSecond  = 0x3B9ACA00ULL; // 1,000,000,000 (0x027dfc..0x027e00)
constexpr uint64_t kMicrosecondsPerMilli  = 0x3E8ULL;      // 1,000 (0x027da8: mov w8, #0x3e8)

struct TimeDelta {
    int64_t nanoseconds = 0;

    constexpr TimeDelta() noexcept = default;
    constexpr explicit TimeDelta(int64_t ns) noexcept : nanoseconds(ns) {}

    static constexpr TimeDelta fromNanoseconds(int64_t ns) noexcept { return TimeDelta(ns); }
    static constexpr TimeDelta fromMicroseconds(int64_t us) noexcept { return TimeDelta(us * 1000LL); }
    static constexpr TimeDelta fromMilliseconds(int64_t ms) noexcept { return TimeDelta(ms * 1000000LL); }
    static constexpr TimeDelta fromSeconds(int64_t s) noexcept { return TimeDelta(s * 1000000000LL); }

    constexpr int64_t toNanoseconds() const noexcept { return nanoseconds; }
    constexpr int64_t toMilliseconds() const noexcept { return nanoseconds / 1000000LL; }
};

namespace Clock {
struct Steady {};
struct System {};
struct Fast1 {};
} // namespace Clock

template <typename ClockT, typename Enable = void>
class TimePoint {
public:
    static int64_t now() noexcept;
};

template <>
int64_t TimePoint<Clock::Steady, void>::now() noexcept; // 0x027d98

template <>
int64_t TimePoint<Clock::System, void>::now() noexcept; // 0x027d9c

template <>
int64_t TimePoint<Clock::Fast1, void>::now() noexcept;  // 0x027db8

// ============================================================================
// 3. String Constants (0x028ad4..0x029154)
// 24-byte 3-tier string (Small <= 23 B, Medium 24..63 B, Large >= 64 B COW).
// Hằng số cấu trúc chuỗi 24-byte 3 tầng (Small, Medium, Large COW).
// ============================================================================
constexpr size_t   kVcbStringMaxSmallSize  = 0x17U; // 23 bytes (mov w8, #0x17 at 0x028b20)
constexpr size_t   kVcbStringMaxMediumSize = 0x3FU; // 63 bytes (cmp x19, #0x3f at 0x028b90)
constexpr uint8_t  kVcbStringCategoryMask  = 0xC0U; // ands w8, w8, #0xc0 at 0x028ebc
constexpr uint8_t  kVcbStringCategorySmall = 0x00U;
constexpr uint8_t  kVcbStringCategoryLarge = 0x40U; // cmp w8, #0x40 at 0x028f18 (COW refcounted)
constexpr uint8_t  kVcbStringCategoryMed   = 0x80U; // cmp w8, #0x80 at 0x028ec8 (eager heap)
constexpr uint64_t kVcbStringCapacityMask  = 0x3FFFFFFFFFFFFFFFULL; // and x0, x8, #0x3fffffffffffffff at 0x028f40

struct StringView {
    const char* data = nullptr;
    size_t size = 0;

    constexpr StringView() noexcept = default;
    constexpr StringView(const char* s, size_t n) noexcept : data(s), size(n) {}
};

template <typename Sig>
using Function = std::function<Sig>;

// ============================================================================
// 4. ThreadFlags & ThreadAttr (0x0223c8..0x02248f)
// Thuộc tính cấu hình luồng thực thi (ThreadFlags & ThreadAttr).
// ============================================================================
struct ThreadFlags {
    uint32_t flags = 0;
};

struct ThreadAttr {
    int priority = 0;           // +0x00
    std::string name = "vcb";   // +0x08 (.rodata 0x02c110: "vcb")
    ThreadFlags flags{};        // +0x20

    ThreadAttr() noexcept;                                              // 0x0223c8
    ThreadAttr(int prio, const char* thread_name);                      // 0x0223f0
    ThreadAttr(int prio, const char* thread_name, const ThreadFlags& f);// 0x022464
};

} // namespace vcbkit
} // namespace ss
} // namespace com
