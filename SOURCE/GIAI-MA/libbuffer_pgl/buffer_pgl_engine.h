/**
 * @file buffer_pgl_engine.h
 * @brief ByteDance Pangle / OpenVK GeckoX Native Buffer Manager Header.
 *        Bộ điều phối quản lý bộ đệm nguyên sinh Pangle OpenVK GeckoX.
 */

#ifndef GECKOX_BUFFER_PGL_ENGINE_H
#define GECKOX_BUFFER_PGL_ENGINE_H

#include "buffer_pgl_types.h"
#include "buffer_pgl_mmap.h"
#include "buffer_pgl_mremap.h"
#include "buffer_pgl_memory.h"
#include <mutex>
#include <unordered_map>
#include <chrono>

namespace nextai {
namespace opencut {
namespace buffer_pgl {

struct PglActiveBufferRecord {
    uintptr_t baseAddress;
    size_t size;
    std::string path;
    std::chrono::system_clock::time_point createdAt;
};

class PglBufferManager {
public:
    static PglBufferManager& getInstance();

    void registerBuffer(uintptr_t addr, size_t size, const std::string& path);
    void unregisterBuffer(uintptr_t addr);
    bool isBufferRegistered(uintptr_t addr) const;
    size_t getRegisteredBufferSize(uintptr_t addr) const;

    size_t getTotalAllocatedBytes() const;
    size_t getActiveBufferCount() const;
    void purgeAll();

private:
    PglBufferManager() = default;
    ~PglBufferManager() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<uintptr_t, PglActiveBufferRecord> m_records;
};

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_ENGINE_H
