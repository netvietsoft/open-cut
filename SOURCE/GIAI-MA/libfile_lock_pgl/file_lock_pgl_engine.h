/**
 * @file file_lock_pgl_engine.h
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Core Engine & Multi-Process Coordinator Header.
 *        Động cơ khóa tệp và điều phối đa tiến trình Pangle OpenVK GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_PGL_ENGINE_H
#define GECKOX_FILE_LOCK_PGL_ENGINE_H

#include "file_lock_pgl_types.h"
#include <mutex>
#include <unordered_map>
#include <chrono>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

/**
 * @brief RAII File Lock Guard for Pangle GeckoX
 *        Lớp bọc RAII tự động mở và giải phóng khóa tệp tin Pangle GeckoX
 */
class PglFileLockGuard {
public:
    PglFileLockGuard(int fd, bool isSegment = false, int segment = 0);
    ~PglFileLockGuard();

    PglFileLockGuard(const PglFileLockGuard&) = delete;
    PglFileLockGuard& operator=(const PglFileLockGuard&) = delete;

    bool isLocked() const { return m_locked; }
    int getFd() const { return m_fd; }

private:
    int m_fd;
    bool m_isSegment;
    int m_segment;
    bool m_locked;
};

/**
 * @brief Multi-Process File Lock Coordinator for Pangle GeckoX
 *        Bộ điều phối khóa tệp đa tiến trình cho Pangle GeckoX
 */
class PglFileLockEngine {
public:
    static PglFileLockEngine& getInstance();

    int openLockFile(const std::string& path, std::string& outError);
    bool lockFile(int fd, std::string& outError);
    bool unlockFile(int fd, std::string& outError);
    bool tryLockFile(int fd);
    bool lockSegment(int fd, int segment, std::string& outError);
    bool releaseLockFile(int fd, std::string& outError);

    size_t getTrackedLockCount() const;
    void reset();

private:
    PglFileLockEngine() = default;
    ~PglFileLockEngine() = default;

    mutable std::mutex m_mutex;
    std::unordered_map<int, std::string> m_fdToPath;
};

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_PGL_ENGINE_H
