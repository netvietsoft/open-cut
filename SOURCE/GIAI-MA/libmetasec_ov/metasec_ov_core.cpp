// ============================================================================
// Clean-Room C++17 Core Implementation for libmetasec_ov.so (Target 117 / 169)
// Hiện thực C++17 sạch lõi cho libmetasec_ov.so (MetaSecOvEngine & AppID Whitelist)
// ============================================================================
#include "metasec_ov_core.h"
#include <algorithm>

namespace metasec {
namespace ov {

MetaSecOvEngine& MetaSecOvEngine::Instance() {
    static MetaSecOvEngine s_engine;
    return s_engine;
}

// Reconstructed from 0x02ea00..0x02ebc0:
//   0x02ea2c: B0000D68 adrp x8, #0x1db000
//   0x02ea30: 911EA108 add  x8, x8, #0x7a8
//   0x02ea34: 08DFFD08 ldarb w8, [x8]
//   0x02ea38: 37000C48 tbnz w8, #0, #0x2ebc0
//   0x02ea4c..0x02eb68: constructs 13 std::string entries from .rodata 0x16b790..0x16b7d5
void MetaSecOvEngine::EnsureAppIdsInitialized() {
    if (app_ids_initialized_.load(std::memory_order_acquire)) {
        return;
    }
    std::lock_guard<std::mutex> lock(mutex_);
    if (!app_ids_initialized_.load(std::memory_order_relaxed)) {
        allowed_app_ids_.clear();
        allowed_app_ids_.reserve(13);
        for (const char* id : kMetaSecAllowedAppIds) {
            allowed_app_ids_.emplace_back(id);
        }
        app_ids_initialized_.store(true, std::memory_order_release);
    }
}

const std::vector<std::string>& MetaSecOvEngine::GetAllowedAppIds() {
    EnsureAppIdsInitialized();
    return allowed_app_ids_;
}

bool MetaSecOvEngine::IsAppIdWhitelisted(const std::string& app_id) {
    EnsureAppIdsInitialized();
    return std::find(allowed_app_ids_.begin(), allowed_app_ids_.end(), app_id) != allowed_app_ids_.end();
}

void MetaSecOvEngine::RegisterTask(const std::string& task_name, int64_t interval_sec) {
    std::lock_guard<std::mutex> lock(mutex_);
    registered_tasks_[task_name] = interval_sec;
}

int64_t MetaSecOvEngine::GetTaskInterval(const std::string& task_name) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = registered_tasks_.find(task_name);
    return (it != registered_tasks_.end()) ? it->second : -1;
}

} // namespace ov
} // namespace metasec
