/**
 * @file keva_repo.h
 * @brief ByteDance Keva Repository & MMAP Storage Engine Header.
 *        Kho lưu trữ và động cơ ánh xạ bộ nhớ mmap Keva.
 */

#ifndef GECKOX_KEVA_REPO_H
#define GECKOX_KEVA_REPO_H

#include "keva_types.h"
#include "keva_bitmap.h"
#include "keva_chunk.h"
#include "keva_process_mutex.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <mutex>

namespace nextai {
namespace opencut {
namespace keva {

/**
 * @brief KevaRepo encapsulates an isolated MMAP-backed key-value repository
 *        Kho lưu trữ Keva độc lập hỗ trợ lưu trữ mmap bền vững
 */
class KevaRepo {
public:
    KevaRepo(const std::string& name, const std::string& dirPath, int mode, bool multiProcess);
    ~KevaRepo();

    bool initialize();
    void close();

    int64_t storeInt(const std::string& key, int32_t val);
    int32_t fetchInt(const std::string& key, int32_t defaultVal);

    int64_t storeBoolean(const std::string& key, bool val);
    bool fetchBoolean(const std::string& key, bool defaultVal);

    int64_t storeLong(const std::string& key, int64_t val);
    int64_t fetchLong(const std::string& key, int64_t defaultVal);

    int64_t storeFloat(const std::string& key, float val);
    float fetchFloat(const std::string& key, float defaultVal);

    int64_t storeDouble(const std::string& key, double val);
    double fetchDouble(const std::string& key, double defaultVal);

    int64_t storeString(const std::string& key, const std::string& val);
    std::string fetchString(const std::string& key, const std::string& defaultVal);

    int64_t storeBytes(const std::string& key, const uint8_t* data, size_t len);
    std::vector<uint8_t> fetchBytes(const std::string& key, const uint8_t* defaultData, size_t defaultLen);

    int64_t storeStringArray(const std::string& key, const std::vector<std::string>& array);
    std::vector<std::string> fetchStringArray(const std::string& key, const std::vector<std::string>& defaultArray);

    void erase(const std::string& key);
    bool contains(const std::string& key);
    void clear();
    void dump();
    void rebuildValueMap();
    void eraseUnusedChunk();

    const std::string& getName() const { return m_name; }
    size_t getKeyCount() const;

private:
    void flushHeader();
    void* m_mmapAddr;
    size_t m_mmapSize;
    int m_fd;
    std::string m_name;
    std::string m_filePath;
    int m_mode;
    bool m_multiProcess;
    mutable std::mutex m_mutex;
    ProcessMutex m_processMutex;
    MarkBitmap m_bitmap;
    std::unordered_map<std::string, KevaEntry> m_entries;
};

/**
 * @brief KevaRepoManager tracks active Keva instances by handle
 *        Bộ quản lý danh sách các repository Keva đang mở
 */
class KevaRepoManager {
public:
    static KevaRepoManager& getInstance();

    jlong registerRepo(std::shared_ptr<KevaRepo> repo);
    std::shared_ptr<KevaRepo> getRepo(jlong handle);
    void unregisterRepo(jlong handle);
    void deleteRepo(const std::string& name);

private:
    KevaRepoManager() = default;
    ~KevaRepoManager() = default;

    std::mutex m_managerMutex;
    std::unordered_map<jlong, std::shared_ptr<KevaRepo>> m_repos;
    jlong m_nextHandle = 1000;
};

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_REPO_H
