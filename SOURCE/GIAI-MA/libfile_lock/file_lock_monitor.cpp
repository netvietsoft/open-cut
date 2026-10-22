/**
 * @file file_lock_monitor.cpp
 * @brief ByteDance GeckoX FileLock Real-time Telemetry & Lock Contention Monitor Implementation.
 *        Hiện thực mã nguồn C++ giám sát độ trễ và xung đột khóa tệp GeckoX.
 */

#include "file_lock_monitor.h"
#include <algorithm>

namespace nextai {
namespace opencut {
namespace filelock {

FileLockMonitor& FileLockMonitor::getInstance() {
    static FileLockMonitor s_instance;
    return s_instance;
}

void FileLockMonitor::recordAcquireAttempt(int fd, const std::string& path) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].totalAcquireAttempts++;
    m_globalStats.totalAcquireAttempts++;
}

void FileLockMonitor::recordAcquireSuccess(int fd, double waitMs) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto& s = m_fdStats[fd];
    s.successfulAcquires++;
    s.totalWaitDurationMs += waitMs;
    s.maxWaitDurationMs = std::max(s.maxWaitDurationMs, waitMs);

    m_globalStats.successfulAcquires++;
    m_globalStats.totalWaitDurationMs += waitMs;
    m_globalStats.maxWaitDurationMs = std::max(m_globalStats.maxWaitDurationMs, waitMs);
}

void FileLockMonitor::recordAcquireFailure(int fd, const std::string& reason) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].failedAcquires++;
    m_globalStats.failedAcquires++;
}

void FileLockMonitor::recordContention(int fd) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].contentionEvents++;
    m_globalStats.contentionEvents++;
}

LockContentionStats FileLockMonitor::getStats(int fd) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_fdStats.find(fd);
    return (it != m_fdStats.end()) ? it->second : LockContentionStats{0, 0, 0, 0, 0.0, 0.0};
}

LockContentionStats FileLockMonitor::getGlobalStats() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_globalStats;
}

void FileLockMonitor::reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats.clear();
    m_globalStats = LockContentionStats{0, 0, 0, 0, 0.0, 0.0};
}

} // namespace filelock
} // namespace opencut
} // namespace nextai
