// ============================================================================
// Clean-Room C++17 ABI & Data Structures for liblynx.so (Target 120 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho liblynx.so (Mục tiêu 120 / 169)
// Binary Size: 3,570,952 bytes | SHA-256: aef1876ef56f0de73666e3bf828a97d451e83de81274848c187174e8341ee16c
// .dynsym: 586 Exported Symbols @ 0x000330 | .eh_frame_hdr: 21,675 FDEs @ 0x08d1d0
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <atomic>
#include <mutex>

namespace lynx {

namespace fml {

// Intrusive RefCounted base with atomic ref_count_ at +0x08 (add x8, x8, #8; ldxr/stxr @ 0x14c070)
// Lớp cơ sở đếm tham chiếu nội tại với biến đếm nguyên tử tại +0x08 (add x8, x8, #8; ldxr/stxr @ 0x14c070)
class RefCountedThreadSafeBase {
public:
    virtual ~RefCountedThreadSafeBase() = default;

    void AddRef() const noexcept {
        ref_count_.fetch_add(1, std::memory_order_relaxed);
    }

    bool Release() const noexcept {
        if (ref_count_.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
            return true;
        }
        return false;
    }

    int32_t ref_count() const noexcept {
        return ref_count_.load(std::memory_order_relaxed);
    }

private:
    mutable std::atomic<int32_t> ref_count_{1}; // +0x08 after vptr
};

template <typename T>
class RefPtr {
public:
    RefPtr() noexcept : ptr_(nullptr) {}
    explicit RefPtr(T* p) noexcept : ptr_(p) {}
    RefPtr(const RefPtr& other) noexcept : ptr_(other.ptr_) {
        if (ptr_) ptr_->AddRef();
    }
    RefPtr(RefPtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    ~RefPtr() {
        if (ptr_) ptr_->Release();
    }
    T* get() const noexcept { return ptr_; }
    T* ReleaseOwnership() noexcept {
        T* tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }
private:
    T* ptr_{nullptr};
};

} // namespace fml

namespace lepus {

// Exact ValueType tag stored at [Value + 0x08] (0x14c03c..0x14c90c)
// Thẻ kiểu ValueType chuẩn lưu tại [Value + 0x08] (0x14c03c..0x14c90c)
enum ValueType : uint8_t {
    Value_Nil = 0,                  // strb wzr, [x19, #8] @ 0x14c24c
    Value_Undefined = 1,            // mov w8, #1; strb w8, [x0, #8] @ 0x14c03c
    Value_Double = 3,               // mov w8, #3; str d0, [x0]; strb w8, [x0, #8] @ 0x14c7e4
    Value_Int32 = 4,                // mov w8, #4; str w1, [x0]; strb w8, [x0, #8] @ 0x14c7f8
    Value_UInt32 = 5,               // mov w8, #5; str w1, [x0]; strb w8, [x0, #8] @ 0x14c80c
    Value_Int64 = 6,                // mov w8, #6; str x1, [x0]; strb w8, [x0, #8] @ 0x14c820
    Value_UInt64 = 7,               // mov w8, #7; str x1, [x0]; strb w8, [x0, #8] @ 0x14c834
    Value_Bool = 8,                 // mov w9, #8; strb w8, [x0]; strb w9, [x0, #8] @ 0x14c7d4
    Value_String = 9,               // sub w9, w8, #9; cmp w9, #4 @ 0x14c05c (first ref-counted type)
    Value_Array = 10,               // mov w9, #0xa; strb w9, [x0, #8] @ 0x14c8b0 (CArray)
    Value_Table = 11,               // mov w9, #0xb; strb w9, [x0, #8] @ 0x14c864 (Dictionary)
    Value_RefCounted = 12,          // RefPtr<RefCounted> @ 0x14c4f4
    Value_ByteArray = 13,           // RefPtr<ByteArray> @ 0x14c4a8
    Value_CFunction = 14,           // mov w8, #0xe @ 0x14c7a4
    Value_BuiltinFunctionTable = 15,// mov w8, #0xf @ 0x14c7b8
    Value_CPointer = 16,            // mov w8, #0x10 @ 0x14c790
    Value_PrimJSValue = 17          // mov w9, #0x11 @ 0x14c904 (external lynx_value)
};

struct CreateAsUndefinedTag {};

class ByteArray : public fml::RefCountedThreadSafeBase {
public:
    ByteArray(std::unique_ptr<uint8_t[]> data, size_t len)
        : data_(std::move(data)), len_(len) {}
    uint8_t* GetPtr() const noexcept { return data_.get(); }
    size_t GetLength() const noexcept { return len_; }
private:
    std::unique_ptr<uint8_t[]> data_;
    size_t len_{0};
};

class Dictionary : public fml::RefCountedThreadSafeBase {};
class CArray : public fml::RefCountedThreadSafeBase {};
class RefCounted : public fml::RefCountedThreadSafeBase {};
struct Context;
struct BuiltinFunctionTable;

} // namespace lepus
} // namespace lynx
