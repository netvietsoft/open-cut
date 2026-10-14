// ======================================================================
// IMPLEMENTATION: pitaya_kv_store.cpp
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Full implementation of PTYKVStore with shared_mutex RWLock,
//   non-blocking try-lock for real-time video rendering pipelines,
//   and domain partitioning.
//
// Mô tả (Tiếng Việt):
//   Triển khai đầy đủ cho PTYKVStore với khóa đọc ghi shared_mutex,
//   try-lock không chặn phục vụ đường ống dựng video thời gian thực
//   và phân vùng dữ liệu theo domain.
// ======================================================================

#include "pitaya_kv_store.h"
#include <mutex>

namespace NextAI::OpenCut::pitaya {

PTYKVStore& PTYKVStore::Instance() {
    static PTYKVStore instance;
    return instance;
}

static int64_t GetCurrentTimeMs() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
}

bool PTYKVStore::Contain(const std::string& key, const std::string& domain) {
    std::shared_lock<std::shared_mutex> lock(rw_lock_);
    auto dom_it = domains_.find(domain);
    if (dom_it == domains_.end()) return false;

    auto key_it = dom_it->second.find(key);
    if (key_it == dom_it->second.end()) return false;

    return !key_it->second.IsExpired();
}

bool PTYKVStore::SetKVData(const std::string& key, const PTYObjectPtr& value, 
                          const std::string& domain, int64_t ttl_ms) {
    if (!value) return false;
    std::unique_lock<std::shared_mutex> lock(rw_lock_);

    KVRecord rec;
    rec.value = value;
    rec.created_at_ms = GetCurrentTimeMs();
    rec.ttl_ms = ttl_ms;

    domains_[domain][key] = rec;
    return true;
}

PTYObjectPtr PTYKVStore::GetKVData(const std::string& key, const std::string& domain) {
    std::shared_lock<std::shared_mutex> lock(rw_lock_);
    auto dom_it = domains_.find(domain);
    if (dom_it == domains_.end()) return nullptr;

    auto key_it = dom_it->second.find(key);
    if (key_it == dom_it->second.end()) return nullptr;

    if (key_it->second.IsExpired()) {
        return nullptr;
    }
    return key_it->second.value;
}

bool PTYKVStore::Append(const std::string& key, double delta, const std::string& domain) {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    auto& table = domains_[domain];
    auto it = table.find(key);

    if (it != table.end() && !it->second.IsExpired() && it->second.value) {
        if (it->second.value->IsDouble()) {
            auto d = std::static_pointer_cast<PTYDouble>(it->second.value);
            d->SetValue(d->Value() + delta);
            return true;
        } else if (it->second.value->IsInt()) {
            auto i = std::static_pointer_cast<PTYInt>(it->second.value);
            i->SetValue(i->Value() + static_cast<int64_t>(delta));
            return true;
        } else if (it->second.value->IsFloat()) {
            auto f = std::static_pointer_cast<PTYFloat>(it->second.value);
            f->SetValue(f->Value() + static_cast<float>(delta));
            return true;
        }
    }

    // Nếu chưa tồn tại, khởi tạo giá trị mới
    KVRecord rec;
    rec.value = std::make_shared<PTYDouble>(delta);
    rec.created_at_ms = GetCurrentTimeMs();
    rec.ttl_ms = 0;
    table[key] = rec;
    return true;
}

bool PTYKVStore::AppendString(const std::string& key, const std::string& suffix, const std::string& domain) {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    auto& table = domains_[domain];
    auto it = table.find(key);

    if (it != table.end() && !it->second.IsExpired() && it->second.value && it->second.value->IsStr()) {
        auto s = std::static_pointer_cast<PTYStr>(it->second.value);
        s->SetValue(s->Value() + suffix);
        return true;
    }

    KVRecord rec;
    rec.value = std::make_shared<PTYStr>(suffix);
    rec.created_at_ms = GetCurrentTimeMs();
    rec.ttl_ms = 0;
    table[key] = rec;
    return true;
}

PTYDictPtr PTYKVStore::GetValueForKeys(const std::vector<std::string>& keys, const std::string& domain) {
    std::shared_lock<std::shared_mutex> lock(rw_lock_);
    auto dict = std::make_shared<PTYDict>();

    auto dom_it = domains_.find(domain);
    if (dom_it == domains_.end()) return dict;

    const auto& table = dom_it->second;
    for (const auto& k : keys) {
        auto it = table.find(k);
        if (it != table.end() && !it->second.IsExpired()) {
            dict->Set(k, it->second.value);
        }
    }
    return dict;
}

bool PTYKVStore::RemoveKeys(const std::vector<std::string>& keys, const std::string& domain) {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    auto dom_it = domains_.find(domain);
    if (dom_it == domains_.end()) return false;

    auto& table = dom_it->second;
    for (const auto& k : keys) {
        table.erase(k);
    }
    return true;
}

PTYObjectPtr PTYKVStore::GetCacheWithTryLock(const std::string& key, const std::string& domain) {
    // Non-blocking try-lock: tránh gây drop-frame trên render thread
    if (!rw_lock_.try_lock_shared()) {
        return nullptr;
    }

    PTYObjectPtr result = nullptr;
    auto dom_it = domains_.find(domain);
    if (dom_it != domains_.end()) {
        auto key_it = dom_it->second.find(key);
        if (key_it != dom_it->second.end() && !key_it->second.IsExpired()) {
            result = key_it->second.value;
        }
    }

    rw_lock_.unlock_shared();
    return result;
}

PTYDictPtr PTYKVStore::TryGetValuesForRequest(const std::vector<std::string>& keys, const std::string& domain) {
    if (!rw_lock_.try_lock_shared()) {
        return std::make_shared<PTYDict>();
    }

    auto dict = std::make_shared<PTYDict>();
    auto dom_it = domains_.find(domain);
    if (dom_it != domains_.end()) {
        const auto& table = dom_it->second;
        for (const auto& k : keys) {
            auto it = table.find(k);
            if (it != table.end() && !it->second.IsExpired()) {
                dict->Set(k, it->second.value);
            }
        }
    }

    rw_lock_.unlock_shared();
    return dict;
}

size_t PTYKVStore::CleanExpired(const std::string& domain) {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    size_t removed = 0;

    auto clean_table = [&](std::unordered_map<std::string, KVRecord>& table) {
        for (auto it = table.begin(); it != table.end(); ) {
            if (it->second.IsExpired()) {
                it = table.erase(it);
                removed++;
            } else {
                ++it;
            }
        }
    };

    if (domain.empty()) {
        for (auto& [d, table] : domains_) {
            clean_table(table);
        }
    } else {
        auto dom_it = domains_.find(domain);
        if (dom_it != domains_.end()) {
            clean_table(dom_it->second);
        }
    }
    return removed;
}

void PTYKVStore::ClearDomain(const std::string& domain) {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    domains_.erase(domain);
}

void PTYKVStore::ClearAll() {
    std::unique_lock<std::shared_mutex> lock(rw_lock_);
    domains_.clear();
}

} // namespace NextAI::OpenCut::pitaya
