// ============================================================================
// Clean-Room C++17 Core Implementation for libkrypton.so (Target 115 / 169)
// Hiện thực C++17 sạch lõi cho libkrypton.so (DataHolder, LogMessage, ThreadAssert)
// ============================================================================
#include "krypton_core.h"
#include <cstdlib>
#include <cstring>

namespace lynx {
namespace canvas {

namespace {
// Reconstructed from 0x0a89fc (free release proc passed via adrp x8, #0xa8000; add x8, x8, #0x9fc)
// Tái dựng từ 0x0a89fc (hàm giải phóng bộ nhớ truyền qua adrp x8, #0xa8000; add x8, x8, #0x9fc)
void DefaultFreeReleaseProc(const void* data, void* context) noexcept {
    (void)context;
    std::free(const_cast<void*>(data));
}

thread_local ThreadAssertType g_tls_thread_type = ThreadAssertType::UI;
} // namespace

// 0x0a8824..0x0a8844: DataHolder::MakeWithoutCopy(const void*, size_t)
std::unique_ptr<DataHolder> DataHolder::MakeWithoutCopy(const void* data, size_t size) {
    return std::unique_ptr<DataHolder>(new DataHolder(data, size, nullptr, nullptr));
}

// 0x0a8844..0x0a88ec: DataHolder::MakeWithCopy(const void*, size_t)
std::unique_ptr<DataHolder> DataHolder::MakeWithCopy(const void* data, size_t size) {
    if (size == 0) {
        return std::unique_ptr<DataHolder>(new DataHolder(nullptr, 0, nullptr, nullptr));
    }
    void* buf = std::malloc(size);
    if (!buf || !data) {
        LogMessage(__FILE__, 0x1e, KryptonLogLevel::ERROR).stream() << "MakeWithCopy failed";
        if (buf) std::free(buf);
        return std::unique_ptr<DataHolder>(new DataHolder(nullptr, 0, nullptr, nullptr));
    }
    std::memcpy(buf, data, size);
    return std::unique_ptr<DataHolder>(new DataHolder(buf, size, nullptr, &DefaultFreeReleaseProc));
}

// 0x0a8db4..0x0a8e5c: DataHolder::MakeWithMalloc(size_t)
std::unique_ptr<DataHolder> DataHolder::MakeWithMalloc(size_t size) {
    if (size == 0) {
        return std::unique_ptr<DataHolder>(new DataHolder(nullptr, 0, nullptr, nullptr));
    }
    void* buf = std::malloc(size);
    if (!buf) {
        LogMessage(__FILE__, 0x33, KryptonLogLevel::ERROR).stream() << "MakeWithMalloc failed";
        return std::unique_ptr<DataHolder>(new DataHolder(nullptr, 0, nullptr, nullptr));
    }
    std::memset(buf, 0, size);
    return std::unique_ptr<DataHolder>(new DataHolder(buf, size, nullptr, &DefaultFreeReleaseProc));
}

// 0x0a8e5c..0x0a8ef8: DataHolder::CreateWithCopy(const void*, size_t)
DataHolder DataHolder::CreateWithCopy(const void* data, size_t size) {
    if (size == 0) {
        return DataHolder(nullptr, 0, nullptr, nullptr);
    }
    void* buf = std::malloc(size);
    if (!buf || !data) {
        LogMessage(__FILE__, 0x47, KryptonLogLevel::ERROR).stream() << "CreateWithCopy failed";
        if (buf) std::free(buf);
        return DataHolder(nullptr, 0, nullptr, nullptr);
    }
    std::memcpy(buf, data, size);
    return DataHolder(buf, size, nullptr, &DefaultFreeReleaseProc);
}

// 0x0a8ef8..0x0a8f20: DataHolder::MakeFromMalloc(const void*, size_t)
std::unique_ptr<DataHolder> DataHolder::MakeFromMalloc(const void* data, size_t size) {
    return std::unique_ptr<DataHolder>(new DataHolder(data, size, nullptr, &DefaultFreeReleaseProc));
}

// 0x0a8f20..0x0a8f5c: DataHolder::MakeWithProc(const void*, size_t, void*, ReleaseProc)
std::unique_ptr<DataHolder> DataHolder::MakeWithProc(const void* data, size_t size, void* ctx, ReleaseProc proc) {
    return std::unique_ptr<DataHolder>(new DataHolder(data, size, ctx, proc));
}

// DataHolder::CreateWithoutCopy
DataHolder DataHolder::CreateWithoutCopy(const void* data, size_t size) {
    return DataHolder(data, size, nullptr, nullptr);
}

// 0x0a8f60..0x0a8f68: stp x1, x2, [x0]; stp xzr, x3, [x0, #0x10]; ret
DataHolder::DataHolder(const void* data, size_t size, ReleaseProc proc) noexcept
    : data_(data), size_(size), release_ctx_(nullptr), release_proc_(proc) {}

// 0x0a8f6c..0x0a8f74: stp x1, x2, [x0]; stp x3, x4, [x0, #0x10]; ret
DataHolder::DataHolder(const void* data, size_t size, void* ctx, ReleaseProc proc) noexcept
    : data_(data), size_(size), release_ctx_(ctx), release_proc_(proc) {}

// 0x0a8f78..0x0a8f90: ldr x2, [x0, #0x18]; cbz x2, #0xa8f90; ldr x8, [x0]; ldr x1, [x0, #0x10]; mov x0, x8; br x2
DataHolder::~DataHolder() noexcept {
    if (release_proc_) {
        release_proc_(data_, release_ctx_);
    }
}

// 0x0a8f94..0x0a8fb4: Move constructor
DataHolder::DataHolder(DataHolder&& other) noexcept
    : data_(other.data_),
      size_(other.size_),
      release_ctx_(nullptr),
      release_proc_(other.release_proc_) {
    other.release_proc_ = nullptr;
    other.data_ = nullptr;
    other.size_ = 0;
}

DataHolder& DataHolder::operator=(DataHolder&& other) noexcept {
    if (this != &other) {
        if (release_proc_) {
            release_proc_(data_, release_ctx_);
        }
        data_ = other.data_;
        size_ = other.size_;
        release_ctx_ = other.release_ctx_;
        release_proc_ = other.release_proc_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.release_ctx_ = nullptr;
        other.release_proc_ = nullptr;
    }
    return *this;
}

// 0x0a8fb8..0x0a8fc4: ForsakeOwnerShip()
void* DataHolder::ForsakeOwnerShip() noexcept {
    void* ptr = const_cast<void*>(data_);
    data_ = nullptr;
    release_proc_ = nullptr;
    size_ = 0;
    return ptr;
}

// 0x0a8fc8..0x0a8fe8: ForsakeOwnerShip(ReleaseProc*, void**)
void* DataHolder::ForsakeOwnerShip(ReleaseProc* out_proc, void** out_ctx) noexcept {
    void* ptr = const_cast<void*>(data_);
    if (out_proc) *out_proc = release_proc_;
    if (out_ctx) *out_ctx = release_ctx_;
    data_ = nullptr;
    release_proc_ = nullptr;
    size_ = 0;
    return ptr;
}

// 0x0a8fec..0x0a90f8: LogMessage
LogMessage::LogMessage(const char* file, int32_t line, KryptonLogLevel level)
    : file_(file), line_(line), level_(level), stream_() {
    Init(file_, line_);
}

LogMessage::~LogMessage() = default;

void LogMessage::Init(const char* file, int32_t line) {
    stream_ << "[" << (file ? file : "krypton") << ":" << line << "] ";
}

// 0x0a9ddc..0x0a9ee0: ThreadAssert
void ThreadAssert::SetThreadType(ThreadAssertType type) noexcept {
    g_tls_thread_type = type;
}

ThreadAssertType ThreadAssert::GetThreadType() noexcept {
    return g_tls_thread_type;
}

void ThreadAssert::Assert(ThreadAssertType expected) {
    if (g_tls_thread_type != expected) {
        LogMessage("thread_assert.cc", 0x13, KryptonLogLevel::ERROR).stream()
            << "ThreadAssert mismatch";
    }
}

bool ThreadAssert::CheckException() {
    return true;
}

} // namespace canvas
} // namespace lynx
