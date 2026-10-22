/**
 * @file file_lock_pgl_channel_pool.cpp
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock File Descriptor Channel Pool Implementation.
 *        Hiện thực bể kết nối quản lý và lưu đệm file descriptor khóa tệp Pangle GeckoX.
 */

#include "file_lock_pgl_channel_pool.h"
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

PglFileLockChannelPool::PglFileLockChannelPool()
    : m_maxChannels(64) {}

PglFileLockChannelPool::~PglFileLockChannelPool() {
    closeAll();
}

PglFileLockChannelPool& PglFileLockChannelPool::getInstance() {
    static PglFileLockChannelPool s_instance;
    return s_instance;
}

int PglFileLockChannelPool::acquireChannel(const std::string& path, std::string& outError) {
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = m_pathToFd.find(path);
    if (it != m_pathToFd.end()) {
        int fd = it->second;
        m_entries[fd].refCount++;
        m_entries[fd].lastUsed = std::chrono::system_clock::now();
        return fd;
    }

#if defined(__ANDROID__) || defined(__linux__)
    int fd = ::open(path.c_str(), O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    if (fd < 0) {
        outError = std::strerror(errno);
        return -1;
    }
#else
    static int s_poolFakeFd = 3000;
    int fd = ++s_poolFakeFd;
#endif

    m_pathToFd[path] = fd;
    PglChannelPoolEntry entry;
    entry.fd = fd;
    entry.path = path;
    entry.refCount = 1;
    entry.lastUsed = std::chrono::system_clock::now();
    entry.isLocked = false;
    m_entries[fd] = entry;

    return fd;
}

void PglFileLockChannelPool::releaseChannel(int fd) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(fd);
    if (it != m_entries.end()) {
        it->second.refCount--;
        if (it->second.refCount <= 0) {
            std::string path = it->second.path;
#if defined(__ANDROID__) || defined(__linux__)
            ::close(fd);
#endif
            m_pathToFd.erase(path);
            m_entries.erase(it);
        }
    }
}

bool PglFileLockChannelPool::isChannelOpen(int fd) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.find(fd) != m_entries.end();
}

size_t PglFileLockChannelPool::getPoolSize() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.size();
}

void PglFileLockChannelPool::closeAll() {
    std::lock_guard<std::mutex> lock(m_mutex);
#if defined(__ANDROID__) || defined(__linux__)
    for (const auto& pair : m_entries) {
        ::close(pair.first);
    }
#endif
    m_entries.clear();
    m_pathToFd.clear();
}

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai
