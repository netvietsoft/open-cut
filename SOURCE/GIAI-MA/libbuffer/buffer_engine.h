/**
 * @file buffer_engine.h
 * @brief ByteDance GeckoX Unified Native Buffer Manager & Cache Engine Header.
 *        Bộ điều phối quản lý và bộ nhớ đệm thống nhất ByteDance GeckoX.
 *
 * Target: libbuffer.so cleanroom architecture.
 */

#ifndef GECKOX_BUFFER_ENGINE_H
#define GECKOX_BUFFER_ENGINE_H

#include "buffer_types.h"
#include "buffer_mmap.h"
#include "buffer_mremap.h"
#include "buffer_memory.h"
#include <mutex>
#include <unordered_map>
#include <chrono>

namespace nextai {
namespace opencut {
namespace buffer {

/**
 * @brief Memory Advise Hints for OS Page Cache Optimization
 *        Chỉ thị tối ưu hóa bộ nhớ trang cho nhân Linux / Android (madvise)
 */
enum class MemoryAdvice : int {
    NORMAL     = 0,  ///< Default kernel behavior / Hành vi mặc định
    RANDOM     = 1,  ///< Random page access / Truy cập trang ngẫu nhiên
    SEQUENTIAL = 2,  ///< Sequential page access / Đọc tuần tự (tăng readahead)
    WILLNEED   = 3,  ///< Will need pages soon / Chuẩn bị sẵn vào RAM
    DONTNEED   = 4   ///< Pages can be freed / Giải phóng khỏi RAM
};

/**
 * @brief Active Native Buffer Tracking Record
 *        Bản ghi truy vết bộ đệm nguyên sinh đang hoạt động
 */
struct ActiveBufferRecord {
    uintptr_t baseAddress;
    size_t size;
    BufferType type;
    std::string path;
    std::chrono::system_clock::time_point createdAt;
    bool isPersistent;
};

/**
 * @brief GeckoX Unified Native Buffer Manager
 *        Bộ quản lý thống nhất bộ đệm nguyên sinh GeckoX
 */
class GeckoXBufferManager {
public:
    static GeckoXBufferManager& getInstance();

    // Lifecycle registration
    void registerBuffer(uintptr_t addr, size_t size, BufferType type, const std::string& path);
    void unregisterBuffer(uintptr_t addr);
    bool isBufferRegistered(uintptr_t addr) const;
    size_t getRegisteredBufferSize(uintptr_t addr) const;

    // Direct buffer operations
    bool copyData(uintptr_t srcAddr, size_t srcOffset, uintptr_t dstAddr, size_t dstOffset, size_t length);
    bool fillPattern(uintptr_t dstAddr, size_t offset, uint8_t pattern, size_t length);

    // Advisory and caching
    bool adviseBuffer(uintptr_t addr, size_t length, MemoryAdvice advice);

    // System statistics
    size_t getTotalAllocatedBytes() const;
    size_t getActiveBufferCount() const;
    std::vector<ActiveBufferRecord> snapshotRecords() const;

    // Reset and purge (for test cleanup)
    void purgeAll();

private:
    GeckoXBufferManager() = default;
    ~GeckoXBufferManager() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<uintptr_t, ActiveBufferRecord> m_records;
};

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_ENGINE_H
