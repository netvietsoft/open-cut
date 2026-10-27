// ============================================================================
// File: lynxbase_types.h
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: Core Types, Mathematical Constants, ABI Layouts & MoveOnlyClosure
//            for Lynx Base (`lynx::base`) and Lynx FML (`lynx::fml`)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 header defining the foundational data structures,
//      enumerations, smart pointers (`RefPtr`, `MoveOnlyClosure`, `InlineVector`),
//      and exact AArch64 hardware/mathematical constants extracted from
//      `liblynxbase.so` (Target 84 / 169).
// [VN] File header C++17 tái tạo sạch các cấu trúc dữ liệu nền tảng, kiểu liệt kê,
//      con trỏ thông minh (`RefPtr`, `MoveOnlyClosure`, `InlineVector`), và các
//      hằng số toán học/phần cứng AArch64 trích xuất chính xác từ `liblynxbase.so`
//      (Mục tiêu 84 / 169).
// ============================================================================

#ifndef LYNXBASE_TYPES_H_
#define LYNXBASE_TYPES_H_

#include <atomic>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <functional>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// ============================================================================
// Forward Declarations for Android JNI Opaque Handles
// ============================================================================
struct _JNIEnv;
struct _JavaVM;
class _jobject;
class _jclass;
class _jstring;
class _jbyteArray;
class _jobjectArray;
struct _jmethodID;
struct DIR;

using JNIEnv = _JNIEnv;
using JavaVM = _JavaVM;
using jobject = _jobject*;
using jclass = _jclass*;
using jstring = _jstring*;
using jbyteArray = _jbyteArray*;
using jobjectArray = _jobjectArray*;
using jmethodID = _jmethodID*;
using jint = int32_t;
using jboolean = uint8_t;

namespace lynx {

// ============================================================================
// 1. Hardware & Mathematical Constants Extracted from liblynxbase.so
// ============================================================================
namespace constants {

// [EN] JNI version returned by `JNI_OnLoad` (`0x014060..0x014064`:
//      `mov w0, #6; movk w0, #1, lsl #16` -> `0x00010006`).
// [VN] Phiên bản JNI trả về từ `JNI_OnLoad` (`0x014060..0x014064` -> `0x00010006`).
constexpr jint kLynxBaseJniVersion = 0x00010006;

// [EN] Signed 64-bit reciprocal magic for dividing by 1,000 (`0x02d528..0x02d538`
//      in `CurrentSystemTimeMilliseconds`, `0x02d584` in `CurrentTimeMicroseconds`,
//      `0x02d5c0` in `CurrentThreadCPUTimeMicroseconds`, `0x02d610` in `ToTimeSpecFromNow`):
//      ceil(2^70 / 1000) = 0x20C49BA5E353F7CFULL (shift right by 7).
// [VN] Hằng số nhân nghịch đảo có dấu 64-bit để chia cho 1.000 (`0x02d528..0x02d538`):
//      ceil(2^70 / 1000) = 0x20C49BA5E353F7CFULL (dịch phải số học 7 bit).
constexpr uint64_t kSignedDiv1000Magic = 0x20C49BA5E353F7CFULL;
constexpr int kSignedDiv1000Shift = 7;

// [EN] Signed 64-bit reciprocal magic for dividing by 1,000,000 (`0x02d558..0x02d568`
//      in `CurrentTimeMilliseconds`):
//      ceil(2^82 / 1000000) = 0x431BDE82D7B634DBULL (shift right by 18 = 0x12).
// [VN] Hằng số nhân nghịch đảo có dấu 64-bit để chia cho 1.000.000 (`0x02d558..0x02d568`):
//      ceil(2^82 / 1000000) = 0x431BDE82D7B634DBULL (dịch phải số học 18 bit = 0x12).
constexpr uint64_t kSignedDiv1000000Magic = 0x431BDE82D7B634DBULL;
constexpr int kSignedDiv1000000Shift = 18;

// [EN] Unsigned 64-bit reciprocal magic for dividing by 10 in `js_dtoa`
//      (`0x0295c4..0x0295e0`: `0xCCCCCCCCCCCCCCCDULL`, shift right by 3).
// [VN] Hằng số nhân nghịch đảo không dấu 64-bit để chia cho 10 trong `js_dtoa`
//      (`0x0295c4..0x0295e0`: `0xCCCCCCCCCCCCCCCDULL`, dịch phải 3 bit).
constexpr uint64_t kUnsignedDiv10Magic = 0xCCCCCCCCCCCCCCCDULL;

// [EN] Exact 53-bit integer fast-path bound in `js_dtoa` (`0x02959c..0x0295a8`):
//      `[-0x1FFFFFFFFFFFFF, +0x1FFFFFFFFFFFFF]`.
// [VN] Ngưỡng số nguyên 53-bit chính xác trong nhánh nhanh của `js_dtoa`
//      (`0x02959c..0x0295a8`): `[-0x1FFFFFFFFFFFFF, +0x1FFFFFFFFFFFFF]`.
constexpr int64_t kJsDtoaMaxSafeInt53 = 0x001FFFFFFFFFFFFFLL;
constexpr uint64_t kJsDtoaSafeIntRange = 0x003FFFFFFFFFFFFEULL;

// [EN] IEEE-754 positive infinity bit pattern checked in `js_dtoa` (`0x029574`).
// [VN] Mẫu bit vô cực dương IEEE-754 kiểm tra trong `js_dtoa` (`0x029574`).
constexpr uint64_t kIeee754PosInfinityBits = 0x7FF0000000000000ULL;

// [EN] 8-byte little-endian pattern for `";base64,"` matched in
//      `DataURIUtil::DecodeDataURI` (`0x02946c..0x029480`):
//      `0x623b` (';b'), `0x7361` ('as'), `0x3665` ('e6'), `0x2c34` ('4,').
// [VN] Mẫu 8 byte little-endian của chuỗi `";base64,"` so khớp trong
//      `DataURIUtil::DecodeDataURI` (`0x02946c..0x029480`).
constexpr uint64_t kDataUriBase64MarkerLE = 0x2C3436657361623BULL;

// [EN] CityHash64 constants used at `0x022314` and empty-string hash seed stored
//      in `RefCountedStringImpl` (`0x02d7b8..0x02d7c8`: `0x9AE16A3B2F90404FULL`).
// [VN] Các hằng số CityHash64 tại `0x022314` và hạt giống băm chuỗi rỗng lưu
//      trong `RefCountedStringImpl` (`0x02d7b8..0x02d7c8`: `0x9AE16A3B2F90404FULL`).
constexpr uint64_t kCityHashK0 = 0xC3A5C85C97CB3127ULL;
constexpr uint64_t kCityHashK1 = 0xB492B66FBE98F273ULL;
constexpr uint64_t kCityHashK2 = 0x9AE16A3B2F90404FULL;

// [EN] RFC 1321 MD5 initial state words loaded at `0x01eff0..0x01f004` from
//      `.rodata 0x00d250` (`0x67452301`, `0xEFCDAB89`) and immediate `x8`
//      (`0x1032547698BADCFEULL` -> `0x98BADCFE`, `0x10325476`).
// [VN] 4 từ trạng thái khởi tạo MD5 chuẩn RFC 1321 nạp tại `0x01eff0..0x01f004`.
constexpr uint32_t kMd5InitA = 0x67452301u;
constexpr uint32_t kMd5InitB = 0xEFCDAB89u;
constexpr uint32_t kMd5InitC = 0x98BADCFEu;
constexpr uint32_t kMd5InitD = 0x10325476u;

} // namespace constants

// ============================================================================
// 2. lynx::base Foundational Templates & Enums
// ============================================================================
namespace base {

// [EN] Move-only callable wrapper (`lynx::base::MoveOnlyClosure<R, Args...>`).
// [VN] Lớp bao hàm gọi chỉ cho phép di chuyển (`lynx::base::MoveOnlyClosure<R, Args...>`).
template <typename Signature>
class MoveOnlyClosure;

template <typename R, typename... Args>
class MoveOnlyClosure<R(Args...)> {
public:
    MoveOnlyClosure() noexcept = default;
    MoveOnlyClosure(std::nullptr_t) noexcept {}

    template <typename F,
              typename = std::enable_if_t<!std::is_same_v<std::decay_t<F>, MoveOnlyClosure>>>
    MoveOnlyClosure(F&& fn)
        : m_callable(std::make_unique<Model<std::decay_t<F>>>(std::forward<F>(fn))) {}

    MoveOnlyClosure(MoveOnlyClosure&&) noexcept = default;
    MoveOnlyClosure& operator=(MoveOnlyClosure&&) noexcept = default;

    MoveOnlyClosure(const MoveOnlyClosure&) = delete;
    MoveOnlyClosure& operator=(const MoveOnlyClosure&) = delete;

    explicit operator bool() const noexcept { return m_callable != nullptr; }

    R operator()(Args... args) const {
        return m_callable->Invoke(std::forward<Args>(args)...);
    }

    void Reset() noexcept { m_callable.reset(); }

private:
    struct Concept {
        virtual ~Concept() = default;
        virtual R Invoke(Args&&... args) = 0;
    };

    template <typename F>
    struct Model final : Concept {
        explicit Model(F fn) : m_fn(std::move(fn)) {}
        R Invoke(Args&&... args) override {
            return m_fn(std::forward<Args>(args)...);
        }
        F m_fn;
    };

    std::unique_ptr<Concept> m_callable;
};

// [EN] Small inline-storage vector (`lynx::base::InlineVector<T, N, Flags>`).
// [VN] Vector lưu trữ nội tuyến kích thước nhỏ (`lynx::base::InlineVector<T, N, Flags>`).
template <typename T, size_t InlineCapacity = 4, size_t Flags = 0>
class InlineVector {
public:
    InlineVector() = default;

    void push_back(const T& val) { m_items.push_back(val); }
    void push_back(T&& val) { m_items.push_back(std::move(val)); }
    void clear() noexcept { m_items.clear(); }

    size_t size() const noexcept { return m_items.size(); }
    bool empty() const noexcept { return m_items.empty(); }

    T& operator[](size_t idx) noexcept { return m_items[idx]; }
    const T& operator[](size_t idx) const noexcept { return m_items[idx]; }

    auto begin() noexcept { return m_items.begin(); }
    auto end() noexcept { return m_items.end(); }
    auto begin() const noexcept { return m_items.begin(); }
    auto end() const noexcept { return m_items.end(); }

private:
    std::vector<T> m_items;
};

// [EN] String trim position flags (`lynx::base::TrimPositions` @ 0x02afe8 / 0x02b2f4).
// [VN] Cờ vị trí cắt khoảng trắng chuỗi (`lynx::base::TrimPositions` @ 0x02afe8 / 0x02b2f4).
enum class TrimPositions : uint32_t {
    TRIM_NONE = 0,
    TRIM_LEADING = 1 << 0,
    TRIM_TRAILING = 1 << 1,
    TRIM_ALL = TRIM_LEADING | TRIM_TRAILING,
};

// [EN] Error severity level (`lynx::base::LynxErrorLevel` @ 0x024f7c):
//      0 -> "fatal", 1 -> "error", 2 -> "warn", >=3 -> "fatal".
// [VN] Mức độ nghiêm trọng của lỗi (`lynx::base::LynxErrorLevel` @ 0x024f7c):
//      0 -> "fatal", 1 -> "error", 2 -> "warn", >=3 -> "fatal".
enum class LynxErrorLevel : int32_t {
    FATAL = 0,
    ERROR = 1,
    WARN = 2,
};

namespace trace {

enum class BaseTraceEventType : int32_t {
    TYPE_SLICE_BEGIN = 0,
    TYPE_SLICE_END = 1,
    TYPE_INSTANT = 2,
};

} // namespace trace

namespace android {

enum class MethodType : int32_t {
    INSTANCE_METHOD = 0,
    STATIC_METHOD = 1,
};

} // namespace android
} // namespace base

// ============================================================================
// 3. lynx::fml Foundational Types (`RefPtr`, `TimeDelta`, `TimePoint`, Enums)
// ============================================================================
namespace fml {

// [EN] Intrusive reference-counted pointer (`lynx::fml::RefPtr<T>`).
// [VN] Con trỏ đếm tham chiếu nội tại (`lynx::fml::RefPtr<T>`).
template <typename T>
class RefPtr {
public:
    RefPtr() noexcept = default;
    explicit RefPtr(T* ptr) noexcept : m_ptr(ptr) {}
    explicit RefPtr(std::shared_ptr<T> ptr) noexcept : m_shared(std::move(ptr)), m_ptr(m_shared.get()) {}

    T* get() const noexcept { return m_ptr; }
    T* operator->() const noexcept { return m_ptr; }
    T& operator*() const noexcept { return *m_ptr; }
    explicit operator bool() const noexcept { return m_ptr != nullptr; }

    void reset() noexcept {
        m_shared.reset();
        m_ptr = nullptr;
    }

private:
    std::shared_ptr<T> m_shared;
    T* m_ptr{nullptr};
};

// [EN] Nanosecond duration (`lynx::fml::TimeDelta`).
// [VN] Khoảng thời gian tính bằng nano-giây (`lynx::fml::TimeDelta`).
class TimeDelta {
public:
    constexpr TimeDelta() noexcept = default;
    constexpr explicit TimeDelta(int64_t nanoseconds) noexcept : m_ns(nanoseconds) {}

    static constexpr TimeDelta Zero() noexcept { return TimeDelta(0); }
    static constexpr TimeDelta FromNanoseconds(int64_t ns) noexcept { return TimeDelta(ns); }
    static constexpr TimeDelta FromMicroseconds(int64_t us) noexcept { return TimeDelta(us * 1000LL); }
    static constexpr TimeDelta FromMilliseconds(int64_t ms) noexcept { return TimeDelta(ms * 1000000LL); }
    static constexpr TimeDelta FromSeconds(int64_t s) noexcept { return TimeDelta(s * 1000000000LL); }

    constexpr int64_t ToNanoseconds() const noexcept { return m_ns; }
    constexpr int64_t ToMicroseconds() const noexcept { return m_ns / 1000LL; }
    constexpr int64_t ToMilliseconds() const noexcept { return m_ns / 1000000LL; }

private:
    int64_t m_ns{0};
};

// [EN] Monotonic timestamp (`lynx::fml::TimePoint` @ 0x01de5c..0x01de74).
// [VN] Mốc thời gian đơn điệu (`lynx::fml::TimePoint` @ 0x01de5c..0x01de74).
class TimePoint {
public:
    constexpr TimePoint() noexcept = default;
    constexpr explicit TimePoint(int64_t ticksNs) noexcept : m_ticksNs(ticksNs) {}

    // [EN] `TimePoint::Now()` @ 0x01de5c & `TimePoint::CurrentWallTime()` @ 0x01de60.
    // [VN] `TimePoint::Now()` @ 0x01de5c & `TimePoint::CurrentWallTime()` @ 0x01de60.
    static TimePoint Now() noexcept;
    static TimePoint CurrentWallTime() noexcept;
    static constexpr TimePoint Max() noexcept { return TimePoint(INT64_MAX); }

    constexpr int64_t ToEpochDelta() const noexcept { return m_ticksNs; }

    constexpr TimePoint operator+(TimeDelta delta) const noexcept {
        return TimePoint(m_ticksNs + delta.ToNanoseconds());
    }
    constexpr TimeDelta operator-(TimePoint other) const noexcept {
        return TimeDelta(m_ticksNs - other.m_ticksNs);
    }
    constexpr bool operator<(const TimePoint& other) const noexcept { return m_ticksNs < other.m_ticksNs; }
    constexpr bool operator<=(const TimePoint& other) const noexcept { return m_ticksNs <= other.m_ticksNs; }
    constexpr bool operator>(const TimePoint& other) const noexcept { return m_ticksNs > other.m_ticksNs; }
    constexpr bool operator==(const TimePoint& other) const noexcept { return m_ticksNs == other.m_ticksNs; }

private:
    int64_t m_ticksNs{0};
};

// [EN] Identifier for a task queue (`lynx::fml::TaskQueueId`).
// [VN] Định danh hàng đợi tác vụ (`lynx::fml::TaskQueueId`).
class TaskQueueId {
public:
    static constexpr size_t kUnmerged = static_cast<size_t>(-1);

    constexpr TaskQueueId() noexcept = default;
    constexpr explicit TaskQueueId(size_t value) noexcept : m_value(value) {}

    constexpr size_t Value() const noexcept { return m_value; }
    constexpr bool IsValid() const noexcept { return m_value != kUnmerged; }
    constexpr operator size_t() const noexcept { return m_value; }

    constexpr bool operator==(const TaskQueueId& other) const noexcept { return m_value == other.m_value; }
    constexpr bool operator!=(const TaskQueueId& other) const noexcept { return m_value != other.m_value; }

private:
    size_t m_value{kUnmerged};
};

enum class TaskSourceGrade : int32_t {
    kUnspecified = 0,
    kUserInteraction = 1,
    kEmergency = 2,
    kMicrotask = 3,
    kIdle = 4,
};

enum class FlushType : int32_t {
    kSingle = 0,
    kAll = 1,
};

class Wakeable {
public:
    virtual ~Wakeable() = default;
    virtual void WakeUp(TimePoint time_point) = 0;
};

class TaskRunnerDelegate {
public:
    virtual ~TaskRunnerDelegate() = default;
};

} // namespace fml
} // namespace lynx

#endif // LYNXBASE_TYPES_H_
