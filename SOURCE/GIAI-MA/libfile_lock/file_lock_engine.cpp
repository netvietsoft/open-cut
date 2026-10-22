/**
 * @file file_lock_engine.cpp
 * @brief ByteDance GeckoX FileLock Core Engine Implementation.
 *        Hiện thực mã nguồn C++ động cơ khóa tệp ByteDance GeckoX.
 */

#include "file_lock_engine.h"
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

namespace nextai {
namespace opencut {
namespace filelock {

GeckoXFileLockGuard::GeckoXFileLockGuard(int fd, bool isSegment, int segment)
    : m_fd(fd), m_isSegment(isSegment), m_segment(segment), m_locked(false) {
    if (m_fd >= 0) {
        std::string err;
        if (m_isSegment) {
            m_locked = GeckoXFileLockEngine::getInstance().lockSegment(m_fd, m_segment, err);
        } else {
            m_locked = GeckoXFileLockEngine::getInstance().lockFile(m_fd, err);
        }
    }
}

GeckoXFileLockGuard::~GeckoXFileLockGuard() {
    if (m_locked && m_fd >= 0) {
        std::string err;
        GeckoXFileLockEngine::getInstance().unlockFile(m_fd, err);
        m_locked = false;
    }
}

GeckoXFileLockEngine& GeckoXFileLockEngine::getInstance() {
    static GeckoXFileLockEngine s_instance;
    return s_instance;
}

int GeckoXFileLockEngine::openLockFile(const std::string& path, std::string& outError) {
#if defined(__ANDROID__) || defined(__linux__)
    int fd = ::open(path.c_str(), O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    if (fd < 0) {
        outError = std::strerror(errno);
        return -1;
    }
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdToPath[fd] = path;
    return fd;
#else
    static int s_fakeFd = 1000;
    int fd = ++s_fakeFd;
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdToPath[fd] = path;
    return fd;
#endif
}

bool GeckoXFileLockEngine::lockFile(int fd, std::string& outError) {
#if defined(__ANDROID__) || defined(__linux__)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLKW, &fl);
    if (ret < 0) {
        outError = std::strerror(errno);
        return false;
    }
    return true;
#else
    return true;
#endif
}

bool GeckoXFileLockEngine::unlockFile(int fd, std::string& outError) {
#if defined(__ANDROID__) || defined(__linux__)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLK, &fl);
    if (ret < 0) {
        outError = std::strerror(errno);
        return false;
    }
    return true;
#else
    return true;
#endif
}

bool GeckoXFileLockEngine::tryLockFile(int fd) {
#if defined(__ANDROID__) || defined(__linux__)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = -1;

    return (::fcntl(fd, F_SETLK, &fl) == 0);
#else
    return true;
#endif
}

bool GeckoXFileLockEngine::lockSegment(int fd, int segment, std::string& outError) {
#if defined(__ANDROID__) || defined(__linux__)
    struct flock fl;
    std::memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_CUR;
    fl.l_start = static_cast<off_t>(segment);
    fl.l_len = 1;
    fl.l_pid = -1;

    int ret = ::fcntl(fd, F_SETLKW, &fl);
    if (ret < 0) {
        outError = std::strerror(errno);
        return false;
    }
    return true;
#else
    return true;
#endif
}

bool GeckoXFileLockEngine::releaseLockFile(int fd, std::string& outError) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdToPath.erase(fd);
#if defined(__ANDROID__) || defined(__linux__)
    if (::close(fd) != 0) {
        outError = std::strerror(errno);
        return false;
    }
    return true;
#else
    return true;
#endif
}

size_t GeckoXFileLockEngine::getTrackedLockCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_fdToPath.size();
}

void GeckoXFileLockEngine::reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_fdToPath.clear();
}

} // namespace filelock
} // namespace opencut
} // namespace nextai
