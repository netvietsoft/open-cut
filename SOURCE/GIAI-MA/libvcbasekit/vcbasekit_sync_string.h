// ============================================================================
// File: vcbasekit_sync_string.h
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit)
//
// Description (EN):
// Clean-room C++17 header for com::ss::vcbkit core primitives:
//   - BaseRef intrusive atomic reference counting (0x021728..0x0217b4)
//   - WeakBox / WeakPtr<BaseRef> / WeakHolder<BaseRef> (0x0221b8..0x0223c8)
//   - Mutex / CondVar / SharedMutex / ScopedLock / ScopedABLock
//   - AutoWaitEvent (0x021a3c..0x021afc) & ManualWaitEvent (0x021afc..0x021da8)
//   - TimePoint<Clock::Steady / System / Fast1>::now() (0x027d98..0x027e10)
//   - com::ss::vcbkit::String 24-byte 3-tier (Small/Medium/Large COW) string
//     (0x028ad4..0x029154)
//   - UnSafe raw C-string formatting & integer parsing (0x029758..0x029a80)
//
// Mô tả (VI):
// Header C++17 tái tạo sạch các nguyên hàm cốt lõi của com::ss::vcbkit:
//   - BaseRef đếm tham chiếu nguyên tử nội tại (0x021728..0x0217b4)
//   - WeakBox / WeakPtr<BaseRef> / WeakHolder<BaseRef> (0x0221b8..0x0223c8)
//   - Mutex / CondVar / SharedMutex / ScopedLock / ScopedABLock
//   - AutoWaitEvent (0x021a3c..0x021afc) & ManualWaitEvent (0x021afc..0x021da8)
//   - TimePoint<Clock::Steady / System / Fast1>::now() (0x027d98..0x027e10)
//   - Chuỗi 24-byte 3 tầng (Small/Medium/Large COW) com::ss::vcbkit::String
//     (0x028ad4..0x029154)
//   - UnSafe định dạng chuỗi C và phân tích số nguyên (0x029758..0x029a80)
// ============================================================================

#pragma once

#include "vcbasekit_types.h"
#include <condition_variable>
#include <cstring>

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// 1. BaseRef — Intrusive Atomic Reference Base Class (0x021728..0x0217b4)
// Verified layout:
//   +0x00: vtable*
//   +0x08: std::atomic<int32_t> ref_count_{0}
//          addRef (0x021740): ldaxr w8, [x8]; add w9, w8, #1; stlxr w10, w9, [x8]
//          decRef (0x021760): ldaxr w9, [x8]; sub w10, w9, #1; stlxr w11, w10, [x8]
//          if (prev == 1) { dmb ishld; this->~BaseRef(); }
// Lớp cơ sở đếm tham chiếu nguyên tử nội tại BaseRef (0x021728..0x0217b4).
// ============================================================================
class BaseRef {
public:
    BaseRef() noexcept;          // 0x021728
    virtual ~BaseRef() noexcept; // 0x0217a4 / deleting 0x0217a8

    void addRef() noexcept;      // 0x021740
    void decRef() noexcept;      // 0x021760
    int refCount() const noexcept; // 0x021794

private:
    std::atomic<int32_t> ref_count_{0}; // +0x08
};

// ============================================================================
// 2. WeakBox, WeakPtr<BaseRef> & WeakHolder<BaseRef> (0x0221b8..0x0223c8)
// Quản lý tham chiếu yếu an toàn đa luồng (WeakBox, WeakPtr, WeakHolder).
// ============================================================================
class WeakBox : public BaseRef {
public:
    explicit WeakBox(BaseRef* target) noexcept;
    ~WeakBox() noexcept override;

    BaseRef* lock() noexcept;
    void invalidate() noexcept;

private:
    mutable std::mutex mutex_;
    BaseRef* target_{nullptr};
};

template <typename T>
class RefPtr {
public:
    RefPtr() noexcept = default;
    explicit RefPtr(T* ptr) noexcept : ptr_(ptr) {
        if (ptr_) ptr_->addRef();
    }
    RefPtr(const RefPtr& other) noexcept : ptr_(other.ptr_) {
        if (ptr_) ptr_->addRef();
    }
    RefPtr(RefPtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    ~RefPtr() noexcept {
        reset();
    }

    RefPtr& operator=(const RefPtr& other) noexcept {
        if (this != &other) {
            if (other.ptr_) other.ptr_->addRef();
            if (ptr_) ptr_->decRef();
            ptr_ = other.ptr_;
        }
        return *this;
    }

    void reset(T* next = nullptr) noexcept {
        if (next) next->addRef();
        if (ptr_) ptr_->decRef();
        ptr_ = next;
    }

    T* get() const noexcept { return ptr_; }
    T* operator->() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

private:
    T* ptr_{nullptr};
};

template <typename T>
class WeakPtr;

template <>
class WeakPtr<BaseRef> {
public:
    WeakPtr() noexcept;                                // 0x0221b8
    explicit WeakPtr(WeakBox* box) noexcept;           // 0x0221c0
    WeakPtr(const WeakPtr& other) noexcept;            // 0x0221ec
    WeakPtr(WeakPtr&& other) noexcept;                 // 0x02221c
    ~WeakPtr() noexcept;                               // 0x022274

    WeakPtr& operator=(const WeakPtr& other) noexcept; // 0x022228
    WeakPtr& operator=(WeakPtr&& other) noexcept;      // 0x022250
    void reset() noexcept;                             // 0x022278
    RefPtr<BaseRef> lock() const noexcept;             // 0x02229c

private:
    WeakBox* box_{nullptr};
};

template <typename T>
class WeakHolder;

template <>
class WeakHolder<BaseRef> {
public:
    explicit WeakHolder(BaseRef* owner);               // 0x0222ec
    ~WeakHolder() noexcept;                            // 0x022344

    void invalidate() noexcept;                        // 0x022348
    WeakPtr<BaseRef> getWeakPtr() const noexcept;      // 0x022398

private:
    WeakBox* box_{nullptr};
};

// ============================================================================
// 3. Synchronization Primitives: Mutex, CondVar, SharedMutex, Locks & Events
//    - AutoWaitEvent (0x021a3c..0x021afc):
//        +0x00: CondVar (48 bytes = 0x30)
//        +0x30: Mutex   (40 bytes = 0x28)
//        +0x58: bool is_signaled_ (strb w8, [x19, #0x58])
//    - ManualWaitEvent (0x021afc..0x021da8):
//        signal (0x021b88), signalAll (0x021bc0), isSignaled (0x021bf8),
//        wait (0x021c2c), waitTimeout (0x021c74), reset (0x021d74)
// Các nguyên hàm đồng bộ hóa luồng: Mutex, CondVar, SharedMutex, WaitEvent.
// ============================================================================
class Mutex {
public:
    Mutex() noexcept = default;
    ~Mutex() noexcept = default;

    void lock() noexcept { mtx_.lock(); }
    bool tryLock() noexcept { return mtx_.try_lock(); }
    void unlock() noexcept { mtx_.unlock(); }
    std::mutex& native() noexcept { return mtx_; }

private:
    std::mutex mtx_;
};

class SharedMutex {
public:
    SharedMutex() noexcept = default;
    ~SharedMutex() noexcept = default;

    void lock() noexcept { smtx_.lock(); }
    void unlock() noexcept { smtx_.unlock(); }
    void lockShared() noexcept { smtx_.lock_shared(); }
    void unlockShared() noexcept { smtx_.unlock_shared(); }

private:
    std::shared_mutex smtx_;
};

template <typename MtxT>
class ScopedLock {
public:
    explicit ScopedLock(MtxT& m) noexcept : mtx_(m) { mtx_.lock(); }
    ~ScopedLock() noexcept { mtx_.unlock(); }
    ScopedLock(const ScopedLock&) = delete;
    ScopedLock& operator=(const ScopedLock&) = delete;

private:
    MtxT& mtx_;
};

class ScopedABLock {
public:
    ScopedABLock(Mutex& a, Mutex& b) noexcept : a_(a), b_(b) {
        if (&a_ < &b_) {
            a_.lock();
            b_.lock();
        } else if (&b_ < &a_) {
            b_.lock();
            a_.lock();
        } else {
            a_.lock();
        }
    }
    ~ScopedABLock() noexcept {
        b_.unlock();
        if (&a_ != &b_) {
            a_.unlock();
        }
    }

private:
    Mutex& a_;
    Mutex& b_;
};

class CondVar {
public:
    CondVar() noexcept = default;
    ~CondVar() noexcept = default;

    void notifyOne() noexcept { cv_.notify_one(); }
    void notifyAll() noexcept { cv_.notify_all(); }
    void wait(Mutex& m) noexcept {
        std::unique_lock<std::mutex> lk(m.native(), std::adopt_lock);
        cv_.wait(lk);
        lk.release();
    }
    bool waitTimeout(Mutex& m, TimeDelta timeout) noexcept {
        std::unique_lock<std::mutex> lk(m.native(), std::adopt_lock);
        auto st = cv_.wait_for(lk, std::chrono::nanoseconds(timeout.toNanoseconds()));
        lk.release();
        return st == std::cv_status::no_timeout;
    }

private:
    std::condition_variable cv_;
};

class AutoWaitEvent {
public:
    explicit AutoWaitEvent(bool initial_signaled = false) noexcept; // 0x021a3c
    ~AutoWaitEvent() noexcept;                                      // 0x021a88

    void signal() noexcept;                                         // 0x021ac4
    void wait() noexcept;                                           // 0x021b00
    bool waitTimeout(TimeDelta timeout) noexcept;                   // 0x021b40

private:
    CondVar cond_;              // +0x00 (48 B on AArch64 bionic)
    Mutex mutex_;               // +0x30 (40 B on AArch64 bionic)
    bool is_signaled_{false};   // +0x58
};

class ManualWaitEvent {
public:
    explicit ManualWaitEvent(bool initial_signaled = false) noexcept; // 0x021afc
    ~ManualWaitEvent() noexcept;                                      // 0x021b48

    void signal() noexcept;                         // 0x021b88
    void signalAll() noexcept;                      // 0x021bc0
    bool isSignaled() noexcept;                     // 0x021bf8
    void wait() noexcept;                           // 0x021c2c
    bool waitTimeout(TimeDelta timeout) noexcept;   // 0x021c74
    void reset() noexcept;                          // 0x021d74

private:
    CondVar cond_;              // +0x00
    Mutex mutex_;               // +0x30
    bool is_signaled_{false};   // +0x58
};

// ============================================================================
// 4. com::ss::vcbkit::String — 24-Byte 3-Tier (Small / Medium / Large COW) String
// Verified from disassembly 0x028ad4..0x029154:
//   - Total object size: 24 bytes (0x18):
//       +0x00: char*    data_
//       +0x08: uint64_t size_
//       +0x10: uint64_t capacity_and_category_ (byte +0x17 holds category & SSO slack)
//   - Small String (SSO, size <= 23 = 0x17):
//       In-place bytes[0..size-1], bytes[size] = '\0',
//       bytes[0x17] = static_cast<uint8_t>(0x17 - size) (category bits 0xC0 == 0x00).
//   - Medium String (24 <= size <= 63 = 0x3F):
//       Heap buffer allocated via malloc(size + 1), category bit 0x80 in byte +0x17.
//   - Large String (size >= 64 = 0x40):
//       Copy-on-Write (COW) heap buffer with 8-byte atomic reference count prefix
//       at (data_ - 8), category bit 0x40 in byte +0x17.
// Chuỗi 24-byte 3 tầng (SSO <= 23B, Medium 24..63B, Large >= 64B COW).
// ============================================================================
class String {
public:
    String() noexcept;                                        // 0x028ad4
    String(const char* cstr);                                 // 0x028ae0
    String(const char* data, size_t len);                     // 0x028b1c
    String(const std::string& std_str);                       // 0x028cd8
    String(size_t count, char ch);                            // 0x028cf8
    String(const String& other);                              // 0x028df0
    String(String&& other) noexcept;                          // 0x028ea0
    ~String() noexcept;                                       // 0x028eb4

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    size_t size() const noexcept;                             // 0x028ef0
    bool empty() const noexcept { return size() == 0; }
    bool isShared() const noexcept;                           // 0x028f10
    size_t capacity() const noexcept;                         // 0x028f34
    const char* c_str() const noexcept;                       // 0x028f64
    const char* data() const noexcept { return c_str(); }
    StringView view() const noexcept;                         // 0x028f78
    std::string std() const;                                  // 0x028fa4

    char& operator[](size_t idx);                             // 0x028fe8
    const char& operator[](size_t idx) const noexcept;        // 0x029094
    String& append(const String& other);                      // 0x0290ac
    String& append(const char* cstr, size_t len);
    int compare(const String& other) const noexcept;          // 0x029154

    uint8_t categoryByte() const noexcept { return sso_.bytes[kVcbStringMaxSmallSize] & kVcbStringCategoryMask; }

private:
    void initSmall(const char* src, size_t len, char fill_ch, bool use_fill) noexcept;
    void initMedium(const char* src, size_t len, char fill_ch, bool use_fill);
    void initLarge(const char* src, size_t len, char fill_ch, bool use_fill);
    void releaseStorage() noexcept;
    void unshareForWrite(size_t min_cap);

    struct HeapLayout {
        char* data;
        uint64_t size;
        uint64_t cap_and_cat;
    };
    struct SsoLayout {
        uint8_t bytes[24];
    };
    union {
        HeapLayout heap_;
        SsoLayout sso_;
    };
};

bool operator==(const String& lhs, const String& rhs) noexcept;
bool operator!=(const String& lhs, const String& rhs) noexcept;

// ============================================================================
// 5. UnSafe — Raw String & Number Utilities (0x029758..0x029a80)
// Các hàm tiện ích xử lý chuỗi C và số nguyên cấp thấp trong không gian tên UnSafe.
// ============================================================================
namespace UnSafe {

bool startWith(const char* str, const char* prefix) noexcept;             // 0x029758
bool startWith(const char* str, const char* prefix, size_t len) noexcept; // 0x0297a0
bool endWith(const char* str, const char* suffix) noexcept;               // 0x0297cc
int32_t toInt32(const char* str, int32_t default_val = 0) noexcept;       // 0x029830
int64_t toInt64(const char* str, int64_t default_val = 0) noexcept;       // 0x0298c4
std::string format(const char* fmt, ...);                                 // 0x029958
std::string trim(const char* str);                                        // 0x029a28

} // namespace UnSafe

} // namespace vcbkit
} // namespace ss
} // namespace com
