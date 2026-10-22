/**
 * @file file_lock_channel_pool.h
 * @brief ByteDance GeckoX FileLock File Descriptor Channel Pool & Cache Header.
 *        Bể kết nối quản lý và lưu đệm file descriptor khóa tệp GeckoX.
 */

#ifndef GECKOX_FILE_LOCK_CHANNEL_POOL_H
#define GECKOX_FILE_LOCK_CHANNEL_POOL_H

#include "file_lock_types.h"
#include <string>
#include <unordered_map>
#include <mutex>
#include <list>

namespace nextai {
namespace opencut {
namespace filelock {

/**
 * @brief Channel Pool Entry Structure
 *        Cấu trúc bản ghi kênh khóa trong bể kết nối
 */
struct ChannelPoolEntry {
    int fd;
    std::string path;
    int refCount;
    std::chrono::system_clock::time_point lastUsed;
    bool isLocked;
};

/**
 * @brief LRU Channel Pool for Lock File Descriptors
 *        Bể kênh LRU quản lý file descriptor khóa tệp an toàn
 */
class FileLockChannelPool {
public:
    static FileLockChannelPool& getInstance();

    int acquireChannel(const std::string& path, std::string& outError);
    void releaseChannel(int fd);

    bool isChannelOpen(int fd) const;
    size_t getPoolSize() const;
    void closeAll();

private:
    FileLockChannelPool();
    ~FileLockChannelPool();

    mutable std::mutex m_mutex;
    size_t m_maxChannels;
    std::unordered_map<std::string, int> m_pathToFd;
    std::unordered_map<int, ChannelPoolEntry> m_entries;
    std::list<std::string> m_lruList;
};

} // namespace filelock
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_CHANNEL_POOL_H
