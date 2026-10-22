/**
 * @file file_lock_pgl_monitor.h
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Real-time Telemetry & Lock Contention Monitor Header.
 *        Bộ giám sát và đo lường xung đột khóa tệp thời gian thực cho Pangle GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_PGL_MONITOR_H
#define GECKOX_FILE_LOCK_PGL_MONITOR_H

#include "file_lock_pgl_types.h"
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

/**
 * @brief Lock Contention Statistics Record for Pangle GeckoX
 *        Bản ghi thống kê xung đột và độ trễ chờ khóa Pangle GeckoX
 */
struct PglLockContentionStats {
    uint64_t totalAcquireAttempts;
    uint64_t successfulAcquires;
    uint64_t failedAcquires;
    uint64_t contentionEvents;
    double maxWaitDurationMs;
    double totalWaitDurationMs;
};

/**
 * @brief FileLock Performance & Health Monitor for Pangle GeckoX
 *        Bộ giám sát hiệu năng và trạng thái vận hành khóa tệp Pangle GeckoX
 */
class PglFileLockMonitor {
public:
    static PglFileLockMonitor& getInstance();

    void recordAcquireAttempt(int fd, const std::string& path);
    void recordAcquireSuccess(int fd, double waitMs);
    void recordAcquireFailure(int fd, const std::string& reason);
    void recordContention(int fd);

    PglLockContentionStats getStats(int fd) const;
    PglLockContentionStats getGlobalStats() const;
    void reset();

private:
    PglFileLockMonitor() = default;
    ~PglFileLockMonitor() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<int, PglLockContentionStats> m_fdStats;
    PglLockContentionStats m_globalStats{0, 0, 0, 0, 0.0, 0.0};
};

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_PGL_MONITOR_H
