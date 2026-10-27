// ============================================================================
// Clean-Room C++17 Core Interfaces for libpreload.so (Target 121 / 169)
// Giao diện lõi C++17 sạch cho libpreload.so (Mục tiêu 121 / 169)
// ============================================================================
#pragma once

#include "preload_types.h"

namespace Json {

// Reconstructed from 0x04aac8..0x04ab08 (Json::FastWriter::~FastWriter)
// Tái dựng từ 0x04aac8..0x04ab08 (Hàm hủy FastWriter kiểm tra cờ SSO bit 0 tại +0x08)
class FastWriter {
public:
    FastWriter() noexcept = default;
    virtual ~FastWriter() noexcept; // 0x04aac8..0x04ab08

    const std::string& write(const std::string& root_repr);
private:
    uint8_t sso_flags_{0};       // +0x08 (ldrb w8, [x0, #8]; tbz w8, #0 @ 0x04aad8..0x04aaec)
    uint8_t pad_09[7]{0};
    size_t document_len_{0};     // +0x10
    char* heap_document_{nullptr}; // +0x18 (ldr x0, [x19, #0x18] @ 0x04aaf0)
    std::string document_;
};

} // namespace Json

namespace com {
namespace bd {
namespace vod {
namespace ST {

// Reconstructed from 0x0e3d9c..0x0fa9f8 (com::bd::vod::ST::StrategyCenter)
// Tái dựng từ 0x0e3d9c..0x0fa9f8 (Trung tâm chiến lược phát & nạp trước video 4,304-byte)
class StrategyCenter {
public:
    StrategyCenter() noexcept; // 0x0e3d9c
    ~StrategyCenter() noexcept = default;

    void start() noexcept;
    void stop() noexcept;
    void setIntValue(int32_t key, int32_t value) noexcept;     // 0x0e6dec
    int32_t getIntValue(int32_t key, int32_t dflt) const noexcept;
    void setFloatValue(int32_t key, float value) noexcept;     // 0x0e7498
    float getFloatValue(int32_t key, float dflt) const noexcept;
    void setLongValue(int32_t key, int64_t value) noexcept;
    int64_t getLongValue(int32_t key, int64_t dflt) const noexcept;
    bool isIOManagerVersionMatch() const noexcept;             // 0x0fa9f8
    int32_t iPlayerVersion() const noexcept;                   // 0x0f4a88

    // Weibull survival & expected play time mathematical model (.rodata 0x2bbb25)
    static double EstimatePlayTimeWeibull(const EstPlayTimeByWeibullParams& params, double elapsed_s) noexcept;

    // Peak-valley time window check (.rodata 0x2bbbe3: [m-preload][peaks-valleys])
    static bool IsInPeakValleyWindow(int32_t now_h, int32_t now_m, int32_t start_h, int32_t start_m, int32_t end_h, int32_t end_m) noexcept;

private:
    void* vptr_main_{nullptr};       // +0x00
    uint64_t state_flags_{0};        // +0x08
    uint64_t io_manager_handle_{0};  // +0x10
    int32_t running_state_{0};       // +0x18 (str wzr, [x0, #0x18] @ 0x0e3df4)
    int32_t player_version_{20250410}; // +0x1c
    void* sub_vptrs_[6]{nullptr};    // +0x20..+0x48 (initialized via str q0 @ 0x0e3df8..0x0e3e30)
    int32_t int_configs_[64]{0};
    float float_configs_[64]{0.0f};
    int64_t long_configs_[64]{0};
    uint8_t reserved_arena_[0x10D0 - 0x450]{0};
};

} // namespace ST
} // namespace vod
} // namespace bd
} // namespace com

extern "C" {
int32_t JNI_OnLoad(void* vm, void* reserved);
void JNI_OnUnload(void* vm, void* reserved);
}

namespace preload_reconstructed {
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);
} // namespace preload_reconstructed
