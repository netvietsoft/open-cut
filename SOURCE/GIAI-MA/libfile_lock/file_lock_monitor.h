/**
 * @file file_lock_monitor.h
 * @brief ByteDance GeckoX FileLock Real-time Telemetry & Lock Contention Monitor Header.
 *        Bộ giám sát và đo lường xung đột khóa tệp thời gian thực cho GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_MONITOR_H
#define GECKOX_FILE_LOCK_MONITOR_H

#include "file_lock_types.h"
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace nextai {
namespace opencut {
namespace filelock {

/**
 * @brief Lock Contention Statistics Record
 *        Bản ghi thống kê xung đột và độ trễ chờ khóa
 */
struct LockContentionStats {
    uint64_t totalAcquireAttempts;
    uint64_t successfulAcquires;
    uint64_t failedAcquires;
    uint64_t contentionEvents;
    double maxWaitDurationMs;
    double totalWaitDurationMs;
};

/**
 * @brief FileLock Performance & Health Monitor
 *        Bộ giám sát hiệu năng và trạng thái vận hành khóa tệp
 */
class FileLockMonitor {
public:
    static FileLockMonitor& getInstance();

    void recordAcquireAttempt(int fd, const std::string& path);
    void recordAcquireSuccess(int fd, double waitMs);
    void recordAcquireFailure(int fd, const std::string& reason);
    void recordContention(int fd);

    LockContentionStats getStats(int fd) const;
    LockContentionStats getGlobalStats() const;
    void reset();

private:
    FileLockMonitor() = default;
    ~FileLockMonitor() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<int, LockContentionStats> m_fdStats;
    LockContentionStats m_globalStats{0, 0, 0, 0, 0.0, 0.0};
};

} // namespace filelock
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_MONITOR_H
