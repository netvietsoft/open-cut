/**
 * @file file_lock_channel_pool.cpp
 * @brief ByteDance GeckoX FileLock File Descriptor Channel Pool & Cache Implementation.
 *        Hiện thực mã nguồn C++ bể kết nối file descriptor khóa tệp GeckoX.
 */

#include "file_lock_channel_pool.h"
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

namespace nextai {
namespace opencut {
namespace filelock {

FileLockChannelPool& FileLockChannelPool::getInstance() {
    static FileLockChannelPool s_instance;
    return s_instance;
}

FileLockChannelPool::FileLockChannelPool()
    : m_maxChannels(64) {}

FileLockChannelPool::~FileLockChannelPool() {
    closeAll();
}

int FileLockChannelPool::acquireChannel(const std::string& path, std::string& outError) {
    std::lock_guard<std::mutex> lock(m_mutex);

    // Check if already open
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
    static int s_virtualPoolFd = 2000;
    int fd = ++s_virtualPoolFd;
#endif

    ChannelPoolEntry entry;
    entry.fd = fd;
    entry.path = path;
    entry.refCount = 1;
    entry.lastUsed = std::chrono::system_clock::now();
    entry.isLocked = false;

    m_pathToFd[path] = fd;
    m_entries[fd] = entry;
    m_lruList.push_front(path);

    return fd;
}

void FileLockChannelPool::releaseChannel(int fd) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(fd);
    if (it == m_entries.end()) return;

    it->second.refCount--;
    if (it->second.refCount <= 0) {
        std::string p = it->second.path;
#if defined(__ANDROID__) || defined(__linux__)
        ::close(fd);
#endif
        m_pathToFd.erase(p);
        m_entries.erase(it);
        m_lruList.remove(p);
    }
}

bool FileLockChannelPool::isChannelOpen(int fd) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.find(fd) != m_entries.end();
}

size_t FileLockChannelPool::getPoolSize() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.size();
}

void FileLockChannelPool::closeAll() {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto& kv : m_entries) {
#if defined(__ANDROID__) || defined(__linux__)
        ::close(kv.first);
#endif
    }
    m_entries.clear();
    m_pathToFd.clear();
    m_lruList.clear();
}

} // namespace filelock
} // namespace opencut
} // namespace nextai
