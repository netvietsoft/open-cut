/**
 * @file buffer_engine.cpp
 * @brief ByteDance GeckoX Unified Native Buffer Manager & Cache Engine Implementation.
 *        Hiện thực mã nguồn C++ cho bộ quản lý và đệm thống nhất ByteDance GeckoX.
 */

#include "buffer_engine.h"
#include <algorithm>
#include <numeric>

#if defined(__ANDROID__) || defined(__linux__)
#include <sys/mman.h>
#endif

namespace nextai {
namespace opencut {
namespace buffer {

GeckoXBufferManager& GeckoXBufferManager::getInstance() {
    static GeckoXBufferManager s_instance;
    return s_instance;
}

void GeckoXBufferManager::registerBuffer(uintptr_t addr, size_t size, BufferType type, const std::string& path) {
    if (!addr) return;
    std::lock_guard<std::mutex> lock(m_mutex);
    ActiveBufferRecord rec;
    rec.baseAddress = addr;
    rec.size = size;
    rec.type = type;
    rec.path = path;
    rec.createdAt = std::chrono::system_clock::now();
    rec.isPersistent = (type == BufferType::MMAP);
    m_records[addr] = rec;
}

void GeckoXBufferManager::unregisterBuffer(uintptr_t addr) {
    if (!addr) return;
    std::lock_guard<std::mutex> lock(m_mutex);
    m_records.erase(addr);
}

bool GeckoXBufferManager::isBufferRegistered(uintptr_t addr) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_records.find(addr) != m_records.end();
}

size_t GeckoXBufferManager::getRegisteredBufferSize(uintptr_t addr) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_records.find(addr);
    return (it != m_records.end()) ? it->second.size : 0;
}

bool GeckoXBufferManager::copyData(uintptr_t srcAddr, size_t srcOffset, uintptr_t dstAddr, size_t dstOffset, size_t length) {
    if (!srcAddr || !dstAddr || length == 0) {
        return false;
    }
    const uint8_t* srcPtr = reinterpret_cast<const uint8_t*>(srcAddr) + srcOffset;
    uint8_t* dstPtr = reinterpret_cast<uint8_t*>(dstAddr) + dstOffset;
    std::memmove(dstPtr, srcPtr, length);
    return true;
}

bool GeckoXBufferManager::fillPattern(uintptr_t dstAddr, size_t offset, uint8_t pattern, size_t length) {
    if (!dstAddr || length == 0) {
        return false;
    }
    uint8_t* dstPtr = reinterpret_cast<uint8_t*>(dstAddr) + offset;
    std::memset(dstPtr, pattern, length);
    return true;
}

bool GeckoXBufferManager::adviseBuffer(uintptr_t addr, size_t length, MemoryAdvice advice) {
    if (!addr || length == 0) {
        return false;
    }

#if defined(__ANDROID__) || defined(__linux__)
    int posixAdvice = MADV_NORMAL;
    switch (advice) {
        case MemoryAdvice::NORMAL:     posixAdvice = MADV_NORMAL; break;
        case MemoryAdvice::RANDOM:     posixAdvice = MADV_RANDOM; break;
        case MemoryAdvice::SEQUENTIAL: posixAdvice = MADV_SEQUENTIAL; break;
        case MemoryAdvice::WILLNEED:   posixAdvice = MADV_WILLNEED; break;
        case MemoryAdvice::DONTNEED:   posixAdvice = MADV_DONTNEED; break;
    }
    return ::madvise(reinterpret_cast<void*>(addr), length, posixAdvice) == 0;
#else
    return true;
#endif
}

size_t GeckoXBufferManager::getTotalAllocatedBytes() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    size_t total = 0;
    for (const auto& kv : m_records) {
        total += kv.second.size;
    }
    return total;
}

size_t GeckoXBufferManager::getActiveBufferCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_records.size();
}

std::vector<ActiveBufferRecord> GeckoXBufferManager::snapshotRecords() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<ActiveBufferRecord> list;
    list.reserve(m_records.size());
    for (const auto& kv : m_records) {
        list.push_back(kv.second);
    }
    return list;
}

void GeckoXBufferManager::purgeAll() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_records.clear();
}

} // namespace buffer
} // namespace opencut
} // namespace nextai
