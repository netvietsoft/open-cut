// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libkrypton.so (Target 115 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libkrypton.so (Mục tiêu 115 / 169)
// Binary Size: 1,674,432 bytes | SHA-256: 98f116548e87179434692198a52cc6ddbf1bfddf89d271c8b09d53b3e2bace31
// .dynsym: 345 Exported Symbols @ 0x000330 | .eh_frame_hdr: 9,255 FDEs @ 0x057848
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <sstream>
#include <functional>

namespace lynx {
namespace canvas {

// Constants verified directly from AArch64 opcodes in libkrypton.so
// Các hằng số xác minh trực tiếp từ mã máy AArch64 trong libkrypton.so
constexpr size_t kDataHolderSizeBytes = 0x20;         // 32 bytes @ 0x0a8f30 (mov w0, #0x20)
constexpr size_t kDataHolderDataOffset = 0x00;        // stp x1, x2, [x0] @ 0x0a8f60
constexpr size_t kDataHolderSizeOffset = 0x08;        // stp x1, x2, [x0] @ 0x0a8f60
constexpr size_t kDataHolderCtxOffset = 0x10;         // stp x3, x4, [x0, #0x10] @ 0x0a8f70
constexpr size_t kDataHolderReleaseProcOffset = 0x18; // ldr x2, [x0, #0x18] @ 0x0a8f78
constexpr size_t kLogMessageStreamOffset = 0x10;      // add x0, x0, #0x10 @ 0x0a9000

enum class KryptonLogLevel : int32_t {
    VERBOSE = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
};

enum class ThreadAssertType : uint8_t {
    UI = 0,
    JS = 1,
    RASTER = 2,
    WORKER = 3
};

// Reconstructed from 0x0a8824..0x0a8fec (DataHolder exact 32-byte ABI layout)
// Tái dựng từ 0x0a8824..0x0a8fec (Bố cục ABI 32-byte chuẩn của DataHolder)
class DataHolder {
public:
    using ReleaseProc = void (*)(const void* data, void* context);

    static std::unique_ptr<DataHolder> MakeWithoutCopy(const void* data, size_t size);
    static std::unique_ptr<DataHolder> MakeWithCopy(const void* data, size_t size);
    static std::unique_ptr<DataHolder> MakeWithMalloc(size_t size);
    static DataHolder CreateWithCopy(const void* data, size_t size);
    static std::unique_ptr<DataHolder> MakeFromMalloc(const void* data, size_t size);
    static std::unique_ptr<DataHolder> MakeWithProc(const void* data, size_t size, void* ctx, ReleaseProc proc);
    static DataHolder CreateWithoutCopy(const void* data, size_t size);

    // 0x0a8f60..0x0a8f68
    DataHolder(const void* data, size_t size, ReleaseProc proc) noexcept;
    // 0x0a8f6c..0x0a8f74
    DataHolder(const void* data, size_t size, void* ctx, ReleaseProc proc) noexcept;
    // 0x0a8f78..0x0a8f90
    ~DataHolder() noexcept;
    // 0x0a8f94..0x0a8fb4
    DataHolder(DataHolder&& other) noexcept;
    DataHolder& operator=(DataHolder&& other) noexcept;

    DataHolder(const DataHolder&) = delete;
    DataHolder& operator=(const DataHolder&) = delete;

    // 0x0a8fb8..0x0a8fe8
    void* ForsakeOwnerShip() noexcept;
    void* ForsakeOwnerShip(ReleaseProc* out_proc, void** out_ctx) noexcept;

    const void* Data() const noexcept { return data_; }
    void* WritableData() noexcept { return const_cast<void*>(data_); }
    size_t Size() const noexcept { return size_; }

private:
    const void* data_{nullptr};        // +0x00
    size_t size_{0};                   // +0x08
    void* release_ctx_{nullptr};       // +0x10
    ReleaseProc release_proc_{nullptr};// +0x18
};

// Reconstructed from 0x0a8fec..0x0a93ac (LogMessage)
// Tái dựng từ 0x0a8fec..0x0a93ac (LogMessage)
class LogMessage {
public:
    LogMessage(const char* file, int32_t line, KryptonLogLevel level);
    ~LogMessage();

    void Init(const char* file, int32_t line);
    std::ostringstream& stream() noexcept { return stream_; }

private:
    const char* file_{nullptr};        // +0x00
    int32_t line_{0};                  // +0x08
    KryptonLogLevel level_{KryptonLogLevel::INFO}; // +0x0c
    std::ostringstream stream_;        // +0x10
};

// Reconstructed from 0x0a9ddc..0x0a9ee8 (ThreadAssert)
// Tái dựng từ 0x0a9ddc..0x0a9ee8 (ThreadAssert)
class ThreadAssert {
public:
    static void SetThreadType(ThreadAssertType type) noexcept;
    static ThreadAssertType GetThreadType() noexcept;
    static void Assert(ThreadAssertType expected);
    static bool CheckException();
};

} // namespace canvas
} // namespace lynx
