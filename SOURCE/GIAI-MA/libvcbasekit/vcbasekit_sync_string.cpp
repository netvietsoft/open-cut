// ============================================================================
// File: vcbasekit_sync_string.cpp
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit)
//
// Description (EN):
// Clean-room C++17 implementation of com::ss::vcbkit synchronization, clock,
// reference counting, and 24-byte 3-tier COW/SSO String primitives from
// libvcbasekit.so (.text 0x021728..0x029a80).
//
// Mô tả (VI):
// Cài đặt C++17 tái tạo sạch các nguyên hàm đồng bộ hóa, đồng hồ thời gian,
// đếm tham chiếu và chuỗi 24-byte 3 tầng COW/SSO của com::ss::vcbkit từ
// libvcbasekit.so (.text 0x021728..0x029a80).
// ============================================================================

#include "vcbasekit_sync_string.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// 1. BaseRef Intrusive Atomic Reference Counting (0x021728..0x0217b4)
// Exact AArch64 disassembly:
//   0x021728 <BaseRef::BaseRef()>:
//     adrp x8, 0x3b000 ; add x8, x8, #0x4f0 ; str x8, [x0] ; str wzr, [x0, #8] ; ret
//   0x021740 <BaseRef::addRef()>:
//     add x8, x0, #8
//     ldaxr w9, [x8] ; add w10, w9, #1 ; stlxr w11, w10, [x8] ; cbnz w11, 0x21744 ; ret
//   0x021760 <BaseRef::decRef()>:
//     add x8, x0, #8
//     ldaxr w9, [x8] ; sub w10, w9, #1 ; stlxr w11, w10, [x8] ; cbnz w11, 0x21764
//     cmp w9, #1 ; b.ne 0x21790 ; dmb ishld ; ldr x8, [x0] ; ldr x8, [x8, #8] ; br x8
// Đếm tham chiếu nguyên tử nội tại BaseRef (0x021728..0x0217b4).
// ============================================================================
BaseRef::BaseRef() noexcept : ref_count_(0) {}

BaseRef::~BaseRef() noexcept = default;

void BaseRef::addRef() noexcept {
    ref_count_.fetch_add(1, std::memory_order_acq_rel);
}

void BaseRef::decRef() noexcept {
    int32_t prev = ref_count_.fetch_sub(1, std::memory_order_acq_rel);
    if (prev == 1) {
        std::atomic_thread_fence(std::memory_order_acquire);
        delete this;
    }
}

int BaseRef::refCount() const noexcept {
    return ref_count_.load(std::memory_order_acquire);
}

// ============================================================================
// 2. WeakBox, WeakPtr<BaseRef> & WeakHolder<BaseRef> (0x0221b8..0x0223c8)
// Hộp giữ tham chiếu yếu WeakBox, WeakPtr và WeakHolder (0x0221b8..0x0223c8).
// ============================================================================
WeakBox::WeakBox(BaseRef* target) noexcept : target_(target) {}

WeakBox::~WeakBox() noexcept = default;

BaseRef* WeakBox::lock() noexcept {
    std::lock_guard<std::mutex> lk(mutex_);
    if (!target_) {
        return nullptr;
    }
    int32_t cur = target_->refCount();
    if (cur <= 0) {
        return nullptr;
    }
    target_->addRef();
    return target_;
}

void WeakBox::invalidate() noexcept {
    std::lock_guard<std::mutex> lk(mutex_);
    target_ = nullptr;
}

WeakPtr<BaseRef>::WeakPtr() noexcept : box_(nullptr) {}

WeakPtr<BaseRef>::WeakPtr(WeakBox* box) noexcept : box_(box) {
    if (box_) {
        box_->addRef();
    }
}

WeakPtr<BaseRef>::WeakPtr(const WeakPtr& other) noexcept : box_(other.box_) {
    if (box_) {
        box_->addRef();
    }
}

WeakPtr<BaseRef>::WeakPtr(WeakPtr&& other) noexcept : box_(other.box_) {
    other.box_ = nullptr;
}

WeakPtr<BaseRef>::~WeakPtr() noexcept {
    reset();
}

WeakPtr<BaseRef>& WeakPtr<BaseRef>::operator=(const WeakPtr& other) noexcept {
    if (this != &other) {
        if (other.box_) {
            other.box_->addRef();
        }
        if (box_) {
            box_->decRef();
        }
        box_ = other.box_;
    }
    return *this;
}

WeakPtr<BaseRef>& WeakPtr<BaseRef>::operator=(WeakPtr&& other) noexcept {
    if (this != &other) {
        if (box_) {
            box_->decRef();
        }
        box_ = other.box_;
        other.box_ = nullptr;
    }
    return *this;
}

void WeakPtr<BaseRef>::reset() noexcept {
    if (box_) {
        box_->decRef();
        box_ = nullptr;
    }
}

RefPtr<BaseRef> WeakPtr<BaseRef>::lock() const noexcept {
    if (!box_) {
        return RefPtr<BaseRef>();
    }
    BaseRef* raw = box_->lock();
    if (!raw) {
        return RefPtr<BaseRef>();
    }
    RefPtr<BaseRef> result(raw);
    raw->decRef(); // balance WeakBox::lock()'s addRef with RefPtr constructor's addRef
    return result;
}

WeakHolder<BaseRef>::WeakHolder(BaseRef* owner) : box_(new WeakBox(owner)) {
    box_->addRef();
}

WeakHolder<BaseRef>::~WeakHolder() noexcept {
    invalidate();
    if (box_) {
        box_->decRef();
        box_ = nullptr;
    }
}

void WeakHolder<BaseRef>::invalidate() noexcept {
    if (box_) {
        box_->invalidate();
    }
}

WeakPtr<BaseRef> WeakHolder<BaseRef>::getWeakPtr() const noexcept {
    return WeakPtr<BaseRef>(box_);
}

// ============================================================================
// 3. AutoWaitEvent (0x021a3c..0x021afc) & ManualWaitEvent (0x021afc..0x021da8)
// Verified layout:
//   +0x00: CondVar cond_
//   +0x30: Mutex   mutex_
//   +0x58: bool    is_signaled_ (strb w8, [x19, #0x58])
// Sự kiện đợi tự động xóa cờ (AutoWaitEvent) và xóa cờ thủ công (ManualWaitEvent).
// ============================================================================
AutoWaitEvent::AutoWaitEvent(bool initial_signaled) noexcept
    : is_signaled_(initial_signaled) {}

AutoWaitEvent::~AutoWaitEvent() noexcept = default;

void AutoWaitEvent::signal() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    is_signaled_ = true;
    cond_.notifyOne();
}

void AutoWaitEvent::wait() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    while (!is_signaled_) {
        cond_.wait(mutex_);
    }
    is_signaled_ = false;
}

bool AutoWaitEvent::waitTimeout(TimeDelta timeout) noexcept {
    ScopedLock<Mutex> lk(mutex_);
    if (!is_signaled_) {
        cond_.waitTimeout(mutex_, timeout);
    }
    if (is_signaled_) {
        is_signaled_ = false;
        return true;
    }
    return false;
}

ManualWaitEvent::ManualWaitEvent(bool initial_signaled) noexcept
    : is_signaled_(initial_signaled) {}

ManualWaitEvent::~ManualWaitEvent() noexcept = default;

void ManualWaitEvent::signal() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    is_signaled_ = true;
    cond_.notifyOne();
}

void ManualWaitEvent::signalAll() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    is_signaled_ = true;
    cond_.notifyAll();
}

bool ManualWaitEvent::isSignaled() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    return is_signaled_;
}

void ManualWaitEvent::wait() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    while (!is_signaled_) {
        cond_.wait(mutex_);
    }
}

bool ManualWaitEvent::waitTimeout(TimeDelta timeout) noexcept {
    ScopedLock<Mutex> lk(mutex_);
    if (!is_signaled_) {
        cond_.waitTimeout(mutex_, timeout);
    }
    return is_signaled_;
}

void ManualWaitEvent::reset() noexcept {
    ScopedLock<Mutex> lk(mutex_);
    is_signaled_ = false;
}

// ============================================================================
// 4. TimePoint<Clock::Steady / System / Fast1>::now() (0x027d98..0x027e10)
// Exact AArch64 disassembly:
//   0x027d98 <TimePoint<Clock::Steady>::now()>:
//     b std::chrono::steady_clock::now()
//   0x027d9c <TimePoint<Clock::System>::now()>:
//     bl std::chrono::system_clock::now()
//     mov w8, #0x3e8 ; mul x0, x0, x8 ; ret (converts microseconds to nanoseconds)
//   0x027db8 <TimePoint<Clock::Fast1>::now()>:
//     mov w0, #1 (CLOCK_MONOTONIC) ; add x1, sp, #0x10 ; bl clock_gettime
//     ldp x9, x8, [sp, #0x10] ; mov w10, #0xca00 ; movk w10, #0x3b9a, lsl #16
//     madd x0, x9, x10, x8 (tv_sec * 1,000,000,000 + tv_nsec)
// Các hàm lấy mốc thời gian độ phân giải nano-giây TimePoint::now().
// ============================================================================
template <>
int64_t TimePoint<Clock::Steady, void>::now() noexcept {
    auto tp = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(tp).count();
}

template <>
int64_t TimePoint<Clock::System, void>::now() noexcept {
    auto tp = std::chrono::system_clock::now().time_since_epoch();
    int64_t us = std::chrono::duration_cast<std::chrono::microseconds>(tp).count();
    return static_cast<int64_t>(static_cast<uint64_t>(us) * kMicrosecondsPerMilli);
}

template <>
int64_t TimePoint<Clock::Fast1, void>::now() noexcept {
#if defined(CLOCK_MONOTONIC)
    struct timespec ts {};
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
        return static_cast<int64_t>(
            static_cast<uint64_t>(ts.tv_sec) * kNanosecondsPerSecond +
            static_cast<uint64_t>(ts.tv_nsec));
    }
#endif
    return TimePoint<Clock::Steady, void>::now();
}

// ============================================================================
// 5. ThreadAttr Constructors (0x0223c8..0x02248f)
// Verified default thread name at .rodata 0x02c110: "vcb".
// Khởi tạo thuộc tính luồng ThreadAttr với tên mặc định "vcb".
// ============================================================================
ThreadAttr::ThreadAttr() noexcept : priority(0), name("vcb"), flags{0} {}

ThreadAttr::ThreadAttr(int prio, const char* thread_name)
    : priority(prio), name(thread_name ? thread_name : "vcb"), flags{0} {}

ThreadAttr::ThreadAttr(int prio, const char* thread_name, const ThreadFlags& f)
    : priority(prio), name(thread_name ? thread_name : "vcb"), flags(f) {}

// ============================================================================
// 6. com::ss::vcbkit::String — 24-Byte 3-Tier (Small / Medium / Large COW) String
// Verified from disassembly 0x028ad4..0x029154:
//   - Small (size <= 0x17 = 23):
//       sso_.bytes[0..size-1] = payload, sso_.bytes[size] = '\0',
//       sso_.bytes[0x17] = static_cast<uint8_t>(0x17 - size).
//   - Medium (24 <= size <= 0x3F = 63):
//       heap_.data = malloc(size + 1), heap_.size = size,
//       heap_.cap_and_cat = size | (0x80ULL << 56).
//   - Large (size > 0x3F = 63):
//       RefCounted block of size (8 + size + 1):
//       *(std::atomic<int64_t>*)raw = 1;
//       heap_.data = (char*)raw + 8;
//       heap_.size = size;
//       heap_.cap_and_cat = size | (0x40ULL << 56).
// Cài đặt chi tiết chuỗi 24-byte 3 tầng (SSO, Medium, Large COW).
// ============================================================================
namespace {

inline std::atomic<int64_t>* largeRefCountPtr(char* data_ptr) noexcept {
    return reinterpret_cast<std::atomic<int64_t>*>(data_ptr - 8);
}

constexpr uint64_t makeMediumCap(size_t cap) noexcept {
    return (static_cast<uint64_t>(cap) & kVcbStringCapacityMask) |
           (static_cast<uint64_t>(kVcbStringCategoryMed) << 56);
}

constexpr uint64_t makeLargeCap(size_t cap) noexcept {
    return (static_cast<uint64_t>(cap) & kVcbStringCapacityMask) |
           (static_cast<uint64_t>(kVcbStringCategoryLarge) << 56);
}

} // namespace

void String::initSmall(const char* src, size_t len, char fill_ch, bool use_fill) noexcept {
    std::memset(&sso_, 0, sizeof(sso_));
    if (len > 0) {
        if (use_fill) {
            std::memset(sso_.bytes, static_cast<unsigned char>(fill_ch), len);
        } else if (src) {
            std::memcpy(sso_.bytes, src, len);
        }
    }
    sso_.bytes[len] = 0;
    sso_.bytes[kVcbStringMaxSmallSize] = static_cast<uint8_t>(kVcbStringMaxSmallSize - len);
}

void String::initMedium(const char* src, size_t len, char fill_ch, bool use_fill) {
    char* buf = static_cast<char*>(std::malloc(len + 1));
    if (!buf) {
        initSmall(nullptr, 0, '\0', false);
        return;
    }
    if (use_fill) {
        std::memset(buf, static_cast<unsigned char>(fill_ch), len);
    } else if (src) {
        std::memcpy(buf, src, len);
    } else {
        std::memset(buf, 0, len);
    }
    buf[len] = '\0';
    heap_.data = buf;
    heap_.size = len;
    heap_.cap_and_cat = makeMediumCap(len);
}

void String::initLarge(const char* src, size_t len, char fill_ch, bool use_fill) {
    void* raw = std::malloc(8 + len + 1);
    if (!raw) {
        initSmall(nullptr, 0, '\0', false);
        return;
    }
    auto* rc = reinterpret_cast<std::atomic<int64_t>*>(raw);
    rc->store(1, std::memory_order_relaxed);
    char* buf = static_cast<char*>(raw) + 8;
    if (use_fill) {
        std::memset(buf, static_cast<unsigned char>(fill_ch), len);
    } else if (src) {
        std::memcpy(buf, src, len);
    } else {
        std::memset(buf, 0, len);
    }
    buf[len] = '\0';
    heap_.data = buf;
    heap_.size = len;
    heap_.cap_and_cat = makeLargeCap(len);
}

void String::releaseStorage() noexcept {
    uint8_t cat = categoryByte();
    if (cat == kVcbStringCategorySmall) {
        return;
    }
    if (cat == kVcbStringCategoryMed) {
        std::free(heap_.data);
        heap_.data = nullptr;
        return;
    }
    if (cat == kVcbStringCategoryLarge && heap_.data) {
        auto* rc = largeRefCountPtr(heap_.data);
        int64_t prev = rc->fetch_sub(1, std::memory_order_acq_rel);
        if (prev == 1) {
            std::free(heap_.data - 8);
        }
        heap_.data = nullptr;
    }
}

// 0x028ad4: mov w8, #0x17 ; stp xzr, xzr, [x0] ; str xzr, [x0, #0x10] ; strb w8, [x0, #0x17] ; ret
String::String() noexcept {
    initSmall(nullptr, 0, '\0', false);
}

// 0x028ae0: String(const char* cstr)
String::String(const char* cstr) {
    if (!cstr) {
        initSmall(nullptr, 0, '\0', false);
        return;
    }
    size_t len = std::strlen(cstr);
    if (len <= kVcbStringMaxSmallSize) {
        initSmall(cstr, len, '\0', false);
    } else if (len <= kVcbStringMaxMediumSize) {
        initMedium(cstr, len, '\0', false);
    } else {
        initLarge(cstr, len, '\0', false);
    }
}

// 0x028b1c: String(const char* data, size_t len)
String::String(const char* data, size_t len) {
    if (!data || len == 0) {
        initSmall(nullptr, 0, '\0', false);
        return;
    }
    if (len <= kVcbStringMaxSmallSize) {
        initSmall(data, len, '\0', false);
    } else if (len <= kVcbStringMaxMediumSize) {
        initMedium(data, len, '\0', false);
    } else {
        initLarge(data, len, '\0', false);
    }
}

// 0x028cd8: String(const std::string& std_str)
String::String(const std::string& std_str)
    : String(std_str.data(), std_str.size()) {}

// 0x028cf8: String(size_t count, char ch)
String::String(size_t count, char ch) {
    if (count <= kVcbStringMaxSmallSize) {
        initSmall(nullptr, count, ch, true);
    } else if (count <= kVcbStringMaxMediumSize) {
        initMedium(nullptr, count, ch, true);
    } else {
        initLarge(nullptr, count, ch, true);
    }
}

// 0x028df0: String(const String& other)
// Large strings increment the atomic refcount at (data_ - 8); Medium strings deep-copy; Small strings copy 24 bytes.
String::String(const String& other) {
    uint8_t cat = other.categoryByte();
    if (cat == kVcbStringCategorySmall) {
        sso_ = other.sso_;
    } else if (cat == kVcbStringCategoryMed) {
        initMedium(other.heap_.data, other.heap_.size, '\0', false);
    } else {
        heap_ = other.heap_;
        if (heap_.data) {
            largeRefCountPtr(heap_.data)->fetch_add(1, std::memory_order_acq_rel);
        }
    }
}

// 0x028ea0: String(String&& other) noexcept
String::String(String&& other) noexcept {
    sso_ = other.sso_;
    other.initSmall(nullptr, 0, '\0', false);
}

// 0x028eb4: ~String()
String::~String() noexcept {
    releaseStorage();
}

String& String::operator=(const String& other) {
    if (this != &other) {
        String tmp(other);
        std::swap(sso_, tmp.sso_);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        releaseStorage();
        sso_ = other.sso_;
        other.initSmall(nullptr, 0, '\0', false);
    }
    return *this;
}

// 0x028ef0:
//   ldrb w8, [x0, #0x17] ; ldr x9, [x0, #8] ; mov w10, #0x17
//   sub w10, w10, w8 ; cmp w8, #0x18 ; csel x0, x10, x9, lo ; ret
size_t String::size() const noexcept {
    uint8_t last_byte = sso_.bytes[kVcbStringMaxSmallSize];
    if (last_byte < 0x18U) {
        return static_cast<size_t>(kVcbStringMaxSmallSize - last_byte);
    }
    return static_cast<size_t>(heap_.size);
}

// 0x028f10:
//   ldrb w8, [x0, #0x17] ; and w8, w8, #0xc0 ; cmp w8, #0x40 ; b.ne false
//   ldr x8, [x0] ; sub x8, x8, #8 ; ldar x8, [x8] ; cmp x8, #2 ; cset w0, hs ; ret
bool String::isShared() const noexcept {
    if (categoryByte() != kVcbStringCategoryLarge || !heap_.data) {
        return false;
    }
    int64_t rc = largeRefCountPtr(heap_.data)->load(std::memory_order_acquire);
    return rc >= 2;
}

// 0x028f34:
//   ldrb w8, [x0, #0x17] ; tbz w8, #7, ... ; ldr x8, [x0, #0x10] ; and x0, x8, #0x3fffffffffffffff
size_t String::capacity() const noexcept {
    if (categoryByte() == kVcbStringCategorySmall) {
        return kVcbStringMaxSmallSize;
    }
    return static_cast<size_t>(heap_.cap_and_cat & kVcbStringCapacityMask);
}

// 0x028f64:
//   ldrb w8, [x0, #0x17] ; ldr x9, [x0] ; tst w8, #0xc0 ; csel x0, x0, x9, eq ; ret
const char* String::c_str() const noexcept {
    if (categoryByte() == kVcbStringCategorySmall) {
        return reinterpret_cast<const char*>(sso_.bytes);
    }
    return heap_.data;
}

// 0x028f78: String::view() const
StringView String::view() const noexcept {
    return StringView(c_str(), size());
}

// 0x028fa4: String::std() const
std::string String::std() const {
    return std::string(c_str(), size());
}

void String::unshareForWrite(size_t min_cap) {
    size_t cur_size = size();
    size_t target_cap = std::max(cur_size, min_cap);
    if (categoryByte() == kVcbStringCategoryLarge && isShared()) {
        String cloned;
        cloned.initLarge(heap_.data, cur_size, '\0', false);
        std::swap(sso_, cloned.sso_);
        return;
    }
    if (target_cap > capacity()) {
        const char* cur_ptr = c_str();
        String grown;
        if (target_cap <= kVcbStringMaxMediumSize) {
            grown.initMedium(cur_ptr, target_cap, '\0', false);
            grown.heap_.size = cur_size;
            grown.heap_.data[cur_size] = '\0';
        } else {
            grown.initLarge(cur_ptr, target_cap, '\0', false);
            grown.heap_.size = cur_size;
            grown.heap_.data[cur_size] = '\0';
        }
        std::swap(sso_, grown.sso_);
    }
}

// 0x028fe8: char& String::operator[](size_t idx)
char& String::operator[](size_t idx) {
    if (categoryByte() == kVcbStringCategorySmall) {
        return reinterpret_cast<char*>(sso_.bytes)[idx];
    }
    if (isShared()) {
        unshareForWrite(size());
    }
    return heap_.data[idx];
}

// 0x029094: const char& String::operator[](size_t idx) const
const char& String::operator[](size_t idx) const noexcept {
    return c_str()[idx];
}

// 0x0290ac: String& String::append(const String& other)
String& String::append(const String& other) {
    return append(other.c_str(), other.size());
}

String& String::append(const char* cstr, size_t len) {
    if (!cstr || len == 0) {
        return *this;
    }
    size_t old_len = size();
    size_t new_len = old_len + len;
    std::string combined;
    combined.reserve(new_len);
    combined.append(c_str(), old_len);
    combined.append(cstr, len);
    *this = String(combined.data(), combined.size());
    return *this;
}

// 0x029154: int String::compare(const String& other) const
int String::compare(const String& other) const noexcept {
    size_t lhs_len = size();
    size_t rhs_len = other.size();
    size_t min_len = std::min(lhs_len, rhs_len);
    int cmp = std::memcmp(c_str(), other.c_str(), min_len);
    if (cmp != 0) {
        return cmp;
    }
    if (lhs_len < rhs_len) return -1;
    if (lhs_len > rhs_len) return 1;
    return 0;
}

bool operator==(const String& lhs, const String& rhs) noexcept {
    return lhs.size() == rhs.size() && lhs.compare(rhs) == 0;
}

bool operator!=(const String& lhs, const String& rhs) noexcept {
    return !(lhs == rhs);
}

// ============================================================================
// 7. UnSafe Utilities (0x029758..0x029a80)
// Các hàm tiện ích UnSafe xử lý chuỗi và chuyển đổi số nguyên.
// ============================================================================
namespace UnSafe {

bool startWith(const char* str, const char* prefix) noexcept {
    if (!str || !prefix) return false;
    return startWith(str, prefix, std::strlen(prefix));
}

bool startWith(const char* str, const char* prefix, size_t len) noexcept {
    if (!str || !prefix) return false;
    return std::strncmp(str, prefix, len) == 0;
}

bool endWith(const char* str, const char* suffix) noexcept {
    if (!str || !suffix) return false;
    size_t str_len = std::strlen(str);
    size_t suf_len = std::strlen(suffix);
    if (suf_len > str_len) return false;
    return std::memcmp(str + (str_len - suf_len), suffix, suf_len) == 0;
}

int32_t toInt32(const char* str, int32_t default_val) noexcept {
    if (!str || *str == '\0') return default_val;
    char* endptr = nullptr;
    long val = std::strtol(str, &endptr, 10);
    if (endptr == str) return default_val;
    return static_cast<int32_t>(val);
}

int64_t toInt64(const char* str, int64_t default_val) noexcept {
    if (!str || *str == '\0') return default_val;
    char* endptr = nullptr;
    long long val = std::strtoll(str, &endptr, 10);
    if (endptr == str) return default_val;
    return static_cast<int64_t>(val);
}

std::string format(const char* fmt, ...) {
    if (!fmt) return {};
    char stack_buf[512];
    va_list args;
    va_start(args, fmt);
    va_list args_copy;
    va_copy(args_copy, args);
    int needed = std::vsnprintf(stack_buf, sizeof(stack_buf), fmt, args);
    va_end(args);
    if (needed < 0) {
        va_end(args_copy);
        return {};
    }
    if (static_cast<size_t>(needed) < sizeof(stack_buf)) {
        va_end(args_copy);
        return std::string(stack_buf, static_cast<size_t>(needed));
    }
    std::vector<char> heap_buf(static_cast<size_t>(needed) + 1);
    std::vsnprintf(heap_buf.data(), heap_buf.size(), fmt, args_copy);
    va_end(args_copy);
    return std::string(heap_buf.data(), static_cast<size_t>(needed));
}

std::string trim(const char* str) {
    if (!str) return {};
    const char* begin = str;
    while (*begin && std::isspace(static_cast<unsigned char>(*begin))) {
        ++begin;
    }
    const char* end = begin + std::strlen(begin);
    while (end > begin && std::isspace(static_cast<unsigned char>(*(end - 1)))) {
        --end;
    }
    return std::string(begin, static_cast<size_t>(end - begin));
}

} // namespace UnSafe

} // namespace vcbkit
} // namespace ss
} // namespace com
