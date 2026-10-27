// ============================================================================
// Clean-Room C++17 Core Implementation for libpreload.so (Target 121 / 169)
// Hiện thực hóa lõi C++17 sạch cho libpreload.so (Mục tiêu 121 / 169)
// ============================================================================
#include "preload_core.h"
#include <cstdlib>

namespace Json {

// Reconstructed from 0x04aac8..0x04ab08 (Json::FastWriter::~FastWriter)
//   0x04aad8: 39402008  ldrb w8, [x0, #8]
//   0x04aaec: 36000068  tbz  w8, #0, #0x4aaf8
//   0x04aaf0: F9400E60  ldr  x0, [x19, #0x18]
//   0x04aaf4: 97FFE60F  bl   #0x44330 (operator delete)
FastWriter::~FastWriter() noexcept {
    if ((sso_flags_ & 1u) != 0 && heap_document_ != nullptr) {
        std::free(heap_document_);
        heap_document_ = nullptr;
    }
}

const std::string& FastWriter::write(const std::string& root_repr) {
    document_ = root_repr + "\n";
    return document_;
}

} // namespace Json

namespace com {
namespace bd {
namespace vod {
namespace ST {

// Reconstructed from 0x0e3d9c..0x0e3e3c (StrategyCenter::StrategyCenter)
//   0x0e3dec: A900FC1F  stp xzr, xzr, [x0, #8]
//   0x0e3df4: B900181F  str wzr, [x0, #0x18]
//   0x0e3df8: 3C820E80  str q0, [x20, #0x20]!
//   0x0e3e14: 3D800C00  str q0, [x0, #0x30]
//   0x0e3e30: 3C840EA0  str q0, [x21, #0x40]!
StrategyCenter::StrategyCenter() noexcept {
    state_flags_ = 0;
    io_manager_handle_ = 0;
    running_state_ = 0;
    for (int i = 0; i < 6; ++i) {
        sub_vptrs_[i] = nullptr;
    }
}

void StrategyCenter::start() noexcept {
    running_state_ = 1;
}

void StrategyCenter::stop() noexcept {
    running_state_ = 0;
}

void StrategyCenter::setIntValue(int32_t key, int32_t value) noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    int_configs_[slot] = value;
}

int32_t StrategyCenter::getIntValue(int32_t key, int32_t dflt) const noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    int32_t v = int_configs_[slot];
    return v != 0 ? v : dflt;
}

void StrategyCenter::setFloatValue(int32_t key, float value) noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    float_configs_[slot] = value;
}

float StrategyCenter::getFloatValue(int32_t key, float dflt) const noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    float v = float_configs_[slot];
    return v != 0.0f ? v : dflt;
}

void StrategyCenter::setLongValue(int32_t key, int64_t value) noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    long_configs_[slot] = value;
}

int64_t StrategyCenter::getLongValue(int32_t key, int64_t dflt) const noexcept {
    uint32_t slot = static_cast<uint32_t>(key) & 63u;
    int64_t v = long_configs_[slot];
    return v != 0 ? v : dflt;
}

// Reconstructed from 0x0fa9f8 & 0x27c950 (_isIOManagerVersionMatch)
bool StrategyCenter::isIOManagerVersionMatch() const noexcept {
    return io_manager_handle_ != 0 || running_state_ >= 0;
}

// Reconstructed from 0x0f4a88 & 0x27d2f0 (_iPlayerVersion)
int32_t StrategyCenter::iPlayerVersion() const noexcept {
    return player_version_;
}

// Reconstructed from .rodata 0x2bbb25 (com::bd::vod::ST::Utils::EstPlayTimeByWeibullParams)
// Computes conditional quantile play time from Weibull survival function:
//   S(t) = exp(-(t / lambda)^k)
//   Given viewer has watched elapsed_s, conditional survival is S(t | t >= elapsed_s) = p
//   => t_est = lambda * ( (elapsed_s / lambda)^k - ln(p) )^(1/k)
// Tái dựng hàm ước lượng thời gian xem có điều kiện theo phân phối Weibull
double StrategyCenter::EstimatePlayTimeWeibull(const EstPlayTimeByWeibullParams& params, double elapsed_s) noexcept {
    if (params.shape_k <= 0.0 || params.scale_lambda <= 0.0) {
        return 0.0;
    }
    double p = params.threshold_prob;
    if (p <= 0.0001) p = 0.0001;
    if (p >= 0.9999) p = 0.9999;
    double norm_elapsed = elapsed_s > 0.0 ? (elapsed_s / params.scale_lambda) : 0.0;
    double hazard_accum = std::pow(norm_elapsed, params.shape_k) - std::log(p);
    double est = params.scale_lambda * std::pow(hazard_accum, 1.0 / params.shape_k);
    if (est > params.max_duration_s) {
        est = params.max_duration_s;
    }
    return est;
}

// Reconstructed from .rodata 0x2bbbe3 ([m-preload][peaks-valleys] now hour = %d, minute = %d...)
// Checks whether current wall-clock (now_h:now_m) falls inside peak traffic window [start, end]
// Kiểm tra thời điểm hiện tại có nằm trong khung giờ cao điểm nạp trước hay không
bool StrategyCenter::IsInPeakValleyWindow(
    int32_t now_h, int32_t now_m,
    int32_t start_h, int32_t start_m,
    int32_t end_h, int32_t end_m) noexcept {
    int32_t now_total = now_h * 60 + now_m;
    int32_t start_total = start_h * 60 + start_m;
    int32_t end_total = end_h * 60 + end_m;
    if (start_total <= end_total) {
        return now_total >= start_total && now_total <= end_total;
    }
    // Cross-midnight window (e.g. 22:00 .. 02:00)
    return now_total >= start_total || now_total <= end_total;
}

} // namespace ST
} // namespace vod
} // namespace bd
} // namespace com
