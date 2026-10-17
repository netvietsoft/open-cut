/**
 * @file buffer_pgl_engine.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX Native Buffer Manager Implementation.
 *        Hiện thực mã nguồn C++ bộ điều phối quản lý Pangle OpenVK GeckoX.
 */

#include "buffer_pgl_engine.h"

namespace nextai {
namespace opencut {
namespace buffer_pgl {

PglBufferManager& PglBufferManager::getInstance() {
    static PglBufferManager s_instance;
    return s_instance;
}

void PglBufferManager::registerBuffer(uintptr_t addr, size_t size, const std::string& path) {
    if (!addr) return;
    std::lock_guard<std::mutex> lock(m_mutex);
    PglActiveBufferRecord rec;
    rec.baseAddress = addr;
    rec.size = size;
    rec.path = path;
    rec.createdAt = std::chrono::system_clock::now();
    m_records[addr] = rec;
}

void PglBufferManager::unregisterBuffer(uintptr_t addr) {
    if (!addr) return;
    std::lock_guard<std::mutex> lock(m_mutex);
    m_records.erase(addr);
}

bool PglBufferManager::isBufferRegistered(uintptr_t addr) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_records.find(addr) != m_records.end();
}

size_t PglBufferManager::getRegisteredBufferSize(uintptr_t addr) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_records.find(addr);
    return (it != m_records.end()) ? it->second.size : 0;
}

size_t PglBufferManager::getTotalAllocatedBytes() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    size_t total = 0;
    for (const auto& kv : m_records) {
        total += kv.second.size;
    }
    return total;
}

size_t PglBufferManager::getActiveBufferCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_records.size();
}

void PglBufferManager::purgeAll() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_records.clear();
}

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai
