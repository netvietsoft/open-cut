/**
 * @file keva_process_mutex.cpp
 * @brief ByteDance Keva Inter-Process Mutex Implementation.
 *        Hiện thực mã nguồn khóa đồng bộ đa tiến trình Keva.
 */

#include "keva_process_mutex.h"
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>

namespace nextai {
namespace opencut {
namespace keva {

ProcessMutex::ProcessMutex(const std::string& lockFilePath)
    : m_path(lockFilePath), m_fd(-1), m_locked(false) {
#if defined(__ANDROID__) || defined(__linux__)
    if (!m_path.empty()) {
        m_fd = ::open(m_path.c_str(), O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    }
#endif
}

ProcessMutex::~ProcessMutex() {
    Unlock();
#if defined(__ANDROID__) || defined(__linux__)
    if (m_fd >= 0) {
        ::close(m_fd);
        m_fd = -1;
    }
#endif
}

bool ProcessMutex::Lock(bool shared) {
    m_localMutex.lock();
#if defined(__ANDROID__) || defined(__linux__)
    if (m_fd >= 0) {
        struct flock fl;
        std::memset(&fl, 0, sizeof(fl));
        fl.l_type = shared ? F_RDLCK : F_WRLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = -1;
        if (::fcntl(m_fd, F_SETLKW, &fl) == 0) {
            m_locked = true;
            return true;
        }
        m_localMutex.unlock();
        return false;
    }
#endif
    m_locked = true;
    return true;
}

void ProcessMutex::Unlock() {
    if (!m_locked) return;
#if defined(__ANDROID__) || defined(__linux__)
    if (m_fd >= 0) {
        struct flock fl;
        std::memset(&fl, 0, sizeof(fl));
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = -1;
        ::fcntl(m_fd, F_SETLK, &fl);
    }
#endif
    m_locked = false;
    m_localMutex.unlock();
}

bool ProcessMutex::TryLock(bool shared) {
    if (!m_localMutex.try_lock()) return false;
#if defined(__ANDROID__) || defined(__linux__)
    if (m_fd >= 0) {
        struct flock fl;
        std::memset(&fl, 0, sizeof(fl));
        fl.l_type = shared ? F_RDLCK : F_WRLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = -1;
        if (::fcntl(m_fd, F_SETLK, &fl) == 0) {
            m_locked = true;
            return true;
        }
        m_localMutex.unlock();
        return false;
    }
#endif
    m_locked = true;
    return true;
}

} // namespace keva
} // namespace opencut
} // namespace nextai
