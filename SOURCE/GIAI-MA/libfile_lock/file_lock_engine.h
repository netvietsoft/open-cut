/**
 * @file file_lock_engine.h
 * @brief ByteDance GeckoX FileLock Core Engine & Multi-Process Coordinator Header.
 *        Động cơ khóa tệp và điều phối đa tiến trình ByteDance GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_ENGINE_H
#define GECKOX_FILE_LOCK_ENGINE_H

#include "file_lock_types.h"
#include <mutex>
#include <unordered_map>
#include <chrono>

namespace nextai {
namespace opencut {
namespace filelock {

/**
 * @brief RAII File Lock Guard
 *        Lớp bọc RAII tự động mở và giải phóng khóa tệp tin
 */
class GeckoXFileLockGuard {
public:
    GeckoXFileLockGuard(int fd, bool isSegment = false, int segment = 0);
    ~GeckoXFileLockGuard();

    GeckoXFileLockGuard(const GeckoXFileLockGuard&) = delete;
    GeckoXFileLockGuard& operator=(const GeckoXFileLockGuard&) = delete;

    bool isLocked() const { return m_locked; }
    int getFd() const { return m_fd; }

private:
    int m_fd;
    bool m_isSegment;
    int m_segment;
    bool m_locked;
};

/**
 * @brief Multi-Process File Lock Coordinator
 *        Bộ điều phối khóa tệp đa tiến trình
 */
class GeckoXFileLockEngine {
public:
    static GeckoXFileLockEngine& getInstance();

    int openLockFile(const std::string& path, std::string& outError);
    bool lockFile(int fd, std::string& outError);
    bool unlockFile(int fd, std::string& outError);
    bool tryLockFile(int fd);
    bool lockSegment(int fd, int segment, std::string& outError);
    bool releaseLockFile(int fd, std::string& outError);

    size_t getTrackedLockCount() const;
    void reset();

private:
    GeckoXFileLockEngine() = default;
    ~GeckoXFileLockEngine() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<int, std::string> m_fdToPath;
};

} // namespace filelock
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_ENGINE_H
