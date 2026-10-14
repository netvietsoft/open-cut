// ======================================================================
// RECONSTRUCTED HEADER: pitaya_kv_store.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Thread-safe multi-domain Key-Value store (PTYKVStore) with RWLock,
//   non-blocking try-lock for render loops, TTL expiration, and
//   atomic multi-key query/removal.
//
// Mô tả (Tiếng Việt):
//   Kho lưu trữ Key-Value đa phân vùng (PTYKVStore) an toàn đa luồng với
//   khóa RWLock, try-lock không chặn cho render loop, kiểm soát hạn dùng TTL
//   và truy vấn/xóa hàng loạt khóa nguyên tử.
// ======================================================================

#pragma once

#include "pitaya_types.h"
#include "pitaya_objects.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <shared_mutex>
#include <chrono>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// Bản ghi giá trị có TTL trong KV Store (KV Record with Timestamp & TTL)
// ----------------------------------------------------------------------
struct KVRecord {
    PTYObjectPtr value;
    int64_t created_at_ms{0};
    int64_t ttl_ms{0}; // 0 = vĩnh viễn (no expiration)

    bool IsExpired() const noexcept {
        if (ttl_ms <= 0) return false;
        auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        return (now_ms - created_at_ms) > ttl_ms;
    }
};

// ----------------------------------------------------------------------
// PTYKVStore: Kho Key-Value đa miền của ByteDance Pitaya
// Demangled: Java_com_bytedance_pitaya_feature_PTYKVStore_*
// ----------------------------------------------------------------------
class PTYKVStore {
public:
    static PTYKVStore& Instance();

    // 1. Kiểm tra tồn tại khóa trong miền (nativeContain)
    bool Contain(const std::string& key, const std::string& domain = "default");

    // 2. Gán dữ liệu khóa (nativeSetKVData)
    bool SetKVData(const std::string& key, const PTYObjectPtr& value, 
                   const std::string& domain = "default", int64_t ttl_ms = 0);

    // 3. Đọc dữ liệu khóa (nativeGetKVData)
    PTYObjectPtr GetKVData(const std::string& key, const std::string& domain = "default");

    // 4. Cộng dồn giá trị (nativeAppend)
    bool Append(const std::string& key, double delta, const std::string& domain = "default");
    bool AppendString(const std::string& key, const std::string& suffix, const std::string& domain = "default");

    // 5. Đọc danh sách khóa cùng lúc (nativeGetValueForKeys)
    PTYDictPtr GetValueForKeys(const std::vector<std::string>& keys, const std::string& domain = "default");

    // 6. Xóa danh sách khóa (nativeRemoveKeys)
    bool RemoveKeys(const std::vector<std::string>& keys, const std::string& domain = "default");

    // 7. Đọc thử không chặn bằng Try-Lock (nativeGetCacheWithTryLock)
    PTYObjectPtr GetCacheWithTryLock(const std::string& key, const std::string& domain = "default");

    // 8. Đọc tối ưu cho Request luồng AI (nativeTryGetValuesForReqeust)
    PTYDictPtr TryGetValuesForRequest(const std::vector<std::string>& keys, const std::string& domain = "default");

    // Dọn dẹp bản ghi hết hạn theo chiến lược
    size_t CleanExpired(const std::string& domain = "");
    void ClearDomain(const std::string& domain);
    void ClearAll();

private:
    PTYKVStore() = default;

    // Bảng lưu trữ: domain -> (key -> KVRecord)
    std::unordered_map<std::string, std::unordered_map<std::string, KVRecord>> domains_;
    mutable std::shared_mutex rw_lock_;
};

} // namespace NextAI::OpenCut::pitaya
