// ============================================================================
// Clean-Room C++17 Core Interfaces for libmetasec_ov.so (Target 117 / 169)
// Giao diện lõi C++17 sạch cho libmetasec_ov.so (Mục tiêu 117 / 169)
// ============================================================================
#pragma once

#include "metasec_ov_types.h"

namespace metasec {
namespace ov {

// Number-theoretic OLLVM opaque predicates reconstructed from JNI_OnLoad (0x04bc00..0x04bd4c)
// Các vị từ mờ lý thuyết số OLLVM tái dựng từ JNI_OnLoad (0x04bc00..0x04bd4c)
class OllvmPredicateVerifier {
public:
    // 0x04bc40..0x04bc70 & 0x04bd18..0x04bd48: (4 * x^2 + 4) mod 19 != 0 for all x in Z
    // Uses reciprocal multiplication 0xAF286BCB: q = ((t - hi) >> 1 + hi) >> 4, r = t - 19 * q
    static uint32_t RemainderQuad4Mod19(uint32_t x) noexcept;

    // 0x04bc94..0x04bcac: x^2 + 1 != 7 * y^2 for all x, y in Z (-1 is QNR mod 7)
    static bool IsPellMod7Impossible(uint32_t x, uint32_t y) noexcept;

    // 0x04bcd0..0x04bcf0: (x^2 + x + 7) mod 81 via reciprocal multiplication 0xCA4587E7 >> 38
    static uint32_t RemainderPolyMod81(uint32_t x) noexcept;
};

// Reconstructed from 0x02ea00..0x02ebc0 & bridge dispatcher
// Tái dựng từ 0x02ea00..0x02ebc0 & bộ điều phối cầu nối MetaSec Overseas
class MetaSecOvEngine {
public:
    static MetaSecOvEngine& Instance();

    // 0x02ea00..0x02ebc0: Initializes 13 whitelisted AppIDs guarded by atomic byte at .bss 0x1db7a8
    const std::vector<std::string>& GetAllowedAppIds();
    bool IsAppIdWhitelisted(const std::string& app_id);

    void RegisterTask(const std::string& task_name, int64_t interval_sec);
    int64_t GetTaskInterval(const std::string& task_name) const;
    const MetaSecSettings& GetSettings() const noexcept { return settings_; }

private:
    MetaSecOvEngine() = default;
    void EnsureAppIdsInitialized();

    std::atomic<bool> app_ids_initialized_{false}; // .bss @ 0x1db7a8 (ldarb w8, [x8] @ 0x02ea34)
    mutable std::mutex mutex_;
    std::vector<std::string> allowed_app_ids_;
    std::map<std::string, int64_t> registered_tasks_;
    MetaSecSettings settings_{};
};

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace ov
} // namespace metasec
