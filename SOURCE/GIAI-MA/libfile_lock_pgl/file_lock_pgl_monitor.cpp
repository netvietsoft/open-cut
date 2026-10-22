/**
 * @file file_lock_pgl_monitor.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Real-time Telemetry Implementation.
 *        Hiện thực bộ giám sát và đo lường xung đột khóa tệp thời gian thực cho Pangle GeckoX.
 */

#include "file_lock_pgl_monitor.h"
#include <algorithm>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

PglFileLockMonitor& PglFileLockMonitor::getInstance() {
    static PglFileLockMonitor s_instance;
    return s_instance;
}

void PglFileLockMonitor::recordAcquireAttempt(int fd, const std::string& path) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].totalAcquireAttempts++;
    m_globalStats.totalAcquireAttempts++;
}

void PglFileLockMonitor::recordAcquireSuccess(int fd, double waitMs) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto& stats = m_fdStats[fd];
    stats.successfulAcquires++;
    stats.totalWaitDurationMs += waitMs;
    stats.maxWaitDurationMs = std::max(stats.maxWaitDurationMs, waitMs);

    m_globalStats.successfulAcquires++;
    m_globalStats.totalWaitDurationMs += waitMs;
    m_globalStats.maxWaitDurationMs = std::max(m_globalStats.maxWaitDurationMs, waitMs);
}

void PglFileLockMonitor::recordAcquireFailure(int fd, const std::string& reason) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].failedAcquires++;
    m_globalStats.failedAcquires++;
}

void PglFileLockMonitor::recordContention(int fd) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats[fd].contentionEvents++;
    m_globalStats.contentionEvents++;
}

PglLockContentionStats PglFileLockMonitor::getStats(int fd) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_fdStats.find(fd);
    if (it != m_fdStats.end()) {
        return it->second;
    }
    return PglLockContentionStats{0, 0, 0, 0, 0.0, 0.0};
}

PglLockContentionStats PglFileLockMonitor::getGlobalStats() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_globalStats;
}

void PglFileLockMonitor::reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdStats.clear();
    m_globalStats = PglLockContentionStats{0, 0, 0, 0, 0.0, 0.0};
}

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai
