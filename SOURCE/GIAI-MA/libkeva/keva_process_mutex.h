/**
 * @file keva_process_mutex.h
 * @brief ByteDance Keva Inter-Process Mutex & Concurrency Coordinator Header.
 *        Khóa đồng bộ đa tiến trình cho hệ thống lưu trữ Keva.
 */

#ifndef GECKOX_KEVA_PROCESS_MUTEX_H
#define GECKOX_KEVA_PROCESS_MUTEX_H

#include "keva_types.h"
#include <mutex>
#include <string>

namespace nextai {
namespace opencut {
namespace keva {

/**
 * @brief ProcessMutex handles cross-process and cross-thread concurrency
 *        Khóa tương hỗ đa tiến trình bảo vệ vùng nhớ mmap Keva
 */
class ProcessMutex {
public:
    ProcessMutex(const std::string& lockFilePath = "");
    ~ProcessMutex();

    bool Lock(bool shared = false);
    void Unlock();
    bool TryLock(bool shared = false);

private:
    std::string m_path;
    int m_fd;
    std::mutex m_localMutex;
    bool m_locked;
};

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_PROCESS_MUTEX_H
