/**
 * @file keva_repo.cpp
 * @brief ByteDance Keva Repository & Storage Engine Implementation.
 *        Hiện thực mã nguồn kho lưu trữ mmap Keva.
 */

#include "keva_repo.h"
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <algorithm>

namespace nextai {
namespace opencut {
namespace keva {

KevaRepo::KevaRepo(const std::string& name, const std::string& dirPath, int mode, bool multiProcess)
    : m_name(name),
      m_mode(mode),
      m_multiProcess(multiProcess),
      m_mmapAddr(nullptr),
      m_mmapSize(0),
      m_fd(-1),
      m_bitmap(4096) {
    if (!dirPath.empty()) {
        m_filePath = dirPath + "/" + name + ".keva";
    } else {
        m_filePath = "/data/data/com.nextai.opencut/files/keva/" + name + ".keva";
    }
}

KevaRepo::~KevaRepo() {
    close();
}

bool KevaRepo::initialize() {
    std::lock_guard<std::mutex> lock(m_mutex);
#if defined(__ANDROID__) || defined(__linux__)
    m_fd = ::open(m_filePath.c_str(), O_RDWR | O_CREAT | O_CLOEXEC, 0666);
    if (m_fd >= 0) {
        struct stat st;
        if (::fstat(m_fd, &st) == 0) {
            if (st.st_size < static_cast<off_t>(KEVA_INITIAL_FILE_SIZE)) {
                if (::ftruncate(m_fd, KEVA_INITIAL_FILE_SIZE) == 0) {
                    m_mmapSize = KEVA_INITIAL_FILE_SIZE;
                }
            } else {
                m_mmapSize = st.st_size;
            }
        }
        if (m_mmapSize > 0) {
            m_mmapAddr = ::mmap(nullptr, m_mmapSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd, 0);
            if (m_mmapAddr == MAP_FAILED) {
                m_mmapAddr = nullptr;
            }
        }
    }
#endif
    return true;
}

void KevaRepo::close() {
    std::lock_guard<std::mutex> lock(m_mutex);
#if defined(__ANDROID__) || defined(__linux__)
    if (m_mmapAddr && m_mmapAddr != MAP_FAILED) {
        ::msync(m_mmapAddr, m_mmapSize, MS_SYNC);
        ::munmap(m_mmapAddr, m_mmapSize);
        m_mmapAddr = nullptr;
    }
    if (m_fd >= 0) {
        ::close(m_fd);
        m_fd = -1;
    }
#endif
    m_entries.clear();
}

int64_t KevaRepo::storeInt(const std::string& key, int32_t val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_INT;
    entry.intValue = val;
    entry.doubleValue = 0.0;
    m_entries[key] = entry;
    return 1;
}

int32_t KevaRepo::fetchInt(const std::string& key, int32_t defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_INT) {
        return static_cast<int32_t>(it->second.intValue);
    }
    return defaultVal;
}

int64_t KevaRepo::storeBoolean(const std::string& key, bool val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_BOOL;
    entry.intValue = val ? 1 : 0;
    m_entries[key] = entry;
    return 1;
}

bool KevaRepo::fetchBoolean(const std::string& key, bool defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_BOOL) {
        return it->second.intValue != 0;
    }
    return defaultVal;
}

int64_t KevaRepo::storeLong(const std::string& key, int64_t val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_LONG;
    entry.intValue = val;
    m_entries[key] = entry;
    return 1;
}

int64_t KevaRepo::fetchLong(const std::string& key, int64_t defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_LONG) {
        return it->second.intValue;
    }
    return defaultVal;
}

int64_t KevaRepo::storeFloat(const std::string& key, float val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_FLOAT;
    entry.doubleValue = val;
    m_entries[key] = entry;
    return 1;
}

float KevaRepo::fetchFloat(const std::string& key, float defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_FLOAT) {
        return static_cast<float>(it->second.doubleValue);
    }
    return defaultVal;
}

int64_t KevaRepo::storeDouble(const std::string& key, double val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_DOUBLE;
    entry.doubleValue = val;
    m_entries[key] = entry;
    return 1;
}

double KevaRepo::fetchDouble(const std::string& key, double defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_DOUBLE) {
        return it->second.doubleValue;
    }
    return defaultVal;
}

int64_t KevaRepo::storeString(const std::string& key, const std::string& val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_STRING;
    entry.stringValue = val;
    m_entries[key] = entry;
    return 1;
}

std::string KevaRepo::fetchString(const std::string& key, const std::string& defaultVal) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_STRING) {
        return it->second.stringValue;
    }
    return defaultVal;
}

int64_t KevaRepo::storeBytes(const std::string& key, const uint8_t* data, size_t len) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_BYTES;
    if (data && len > 0) {
        entry.bytesValue.assign(data, data + len);
    }
    m_entries[key] = entry;
    return 1;
}

std::vector<uint8_t> KevaRepo::fetchBytes(const std::string& key, const uint8_t* defaultData, size_t defaultLen) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_BYTES) {
        return it->second.bytesValue;
    }
    if (defaultData && defaultLen > 0) {
        return std::vector<uint8_t>(defaultData, defaultData + defaultLen);
    }
    return {};
}

int64_t KevaRepo::storeStringArray(const std::string& key, const std::vector<std::string>& array) {
    std::lock_guard<std::mutex> lock(m_mutex);
    KevaEntry entry;
    entry.key = key;
    entry.type = KEVA_TYPE_STRING_ARRAY;
    entry.stringArrayValue = array;
    m_entries[key] = entry;
    return 1;
}

std::vector<std::string> KevaRepo::fetchStringArray(const std::string& key, const std::vector<std::string>& defaultArray) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_entries.find(key);
    if (it != m_entries.end() && it->second.type == KEVA_TYPE_STRING_ARRAY) {
        return it->second.stringArrayValue;
    }
    return defaultArray;
}

void KevaRepo::erase(const std::string& key) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_entries.erase(key);
}

bool KevaRepo::contains(const std::string& key) {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.find(key) != m_entries.end();
}

void KevaRepo::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_entries.clear();
    m_bitmap.Clear();
}

void KevaRepo::dump() {
    // Dump state
}

void KevaRepo::rebuildValueMap() {
    // Rebuild index
}

void KevaRepo::eraseUnusedChunk() {
    // Garbage collection of orphaned chunks
}

size_t KevaRepo::getKeyCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_entries.size();
}

void KevaRepo::flushHeader() {
#if defined(__ANDROID__) || defined(__linux__)
    if (m_mmapAddr) {
        ::msync(m_mmapAddr, sizeof(KevaFileHeader), MS_ASYNC);
    }
#endif
}

// -----------------------------------------------------------------------------
// KevaRepoManager Implementation
// -----------------------------------------------------------------------------

KevaRepoManager& KevaRepoManager::getInstance() {
    static KevaRepoManager s_instance;
    return s_instance;
}

jlong KevaRepoManager::registerRepo(std::shared_ptr<KevaRepo> repo) {
    std::lock_guard<std::mutex> lock(m_managerMutex);
    jlong handle = ++m_nextHandle;
    m_repos[handle] = repo;
    return handle;
}

std::shared_ptr<KevaRepo> KevaRepoManager::getRepo(jlong handle) {
    std::lock_guard<std::mutex> lock(m_managerMutex);
    auto it = m_repos.find(handle);
    if (it != m_repos.end()) {
        return it->second;
    }
    return nullptr;
}

void KevaRepoManager::unregisterRepo(jlong handle) {
    std::lock_guard<std::mutex> lock(m_managerMutex);
    m_repos.erase(handle);
}

void KevaRepoManager::deleteRepo(const std::string& name) {
    std::lock_guard<std::mutex> lock(m_managerMutex);
    for (auto it = m_repos.begin(); it != m_repos.end();) {
        if (it->second && it->second->getName() == name) {
            it->second->close();
            it = m_repos.erase(it);
        } else {
            ++it;
        }
    }
}

} // namespace keva
} // namespace opencut
} // namespace nextai
