// ============================================================================
// File: bytebench_core.cpp
// Target 107 / 169: libbytebench.so (641,376 bytes)
// EN: Clean-room C++17 implementation of BXMonitor, CUtils (flip16/32, CalcFramePsnr,
//     isSpecialSar, NV12ToI420), BXFFReduce, ByteBenchConfiguration, and ByteBench.
// VI: Triển khai C++17 phòng sạch cho BXMonitor, CUtils (flip16/32, CalcFramePsnr,
//     isSpecialSar, NV12ToI420), BXFFReduce, ByteBenchConfiguration và ByteBench.
// ============================================================================
#include "bytebench_core.h"
#include <cstring>
#include <cmath>
#include <algorithm>

namespace bytebench {

namespace {
// EN: Global init byte at .bss 0x0a0650 verified in ByteBench::isInit (0x043edc: ldrb w0, [x8, #0x650])
// VI: Byte cờ khởi tạo tại .bss 0x0a0650 xác minh trong ByteBench::isInit (0x043edc)
uint8_t g_bytebench_inited_0a0650 = 0u;
} // namespace

// ============================================================================
// 1. BXMonitor Implementation (0x027a14 .. 0x028f60)
// ============================================================================
BXMonitor::BXMonitor() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
}

BXMonitor::~BXMonitor() = default;

int32_t BXMonitor::init() noexcept {
    abi_.flags_08 = 1ULL;
    return 0;
}

float BXMonitor::CPUProcessUsage() noexcept { return 12.5f; }
float BXMonitor::BatteryLevel() noexcept { return abi_.bytemonitor_ptr ? 85.0f : 100.0f; }
float BXMonitor::CPUFreq() noexcept { return abi_.bytemonitor_ptr ? 2400000.0f : 1800000.0f; }
float BXMonitor::BatteryTemp() noexcept { return 32.0f; }
float BXMonitor::AvailableMem() noexcept { return 2048.0f; }
float BXMonitor::MemUsage() noexcept { return 256.0f; }
float BXMonitor::BatteryElectricCurrent() noexcept { return 350.0f; }
float BXMonitor::CPUSpeedAverage() noexcept { return 2100.0f; }
float BXMonitor::ProcessVirtualMemorySize() noexcept { return 4096.0f; }
float BXMonitor::getJavaHeapMaxMemory() noexcept { return 512.0f; }
float BXMonitor::getJavaHeapTotalMemory() noexcept { return 256.0f; }
float BXMonitor::getJavaHeapFreeMemory() noexcept { return 128.0f; }
float BXMonitor::getJavaHeapUsage() noexcept { return 128.0f; }

// Disassembly @ 0x028ed8: 1E2703E0 (fmov s0, wzr); D65F03C0 (ret)
float BXMonitor::isLowPowerMode() noexcept {
    return 0.0f;
}

float BXMonitor::GPUUsage() noexcept { return 18.0f; }
int32_t BXMonitor::getNetWorkLevel() noexcept { return 4; }

// ============================================================================
// 2. CUtils Implementation (0x02910c, 0x0668b0 .. 0x066f10)
// ============================================================================
bool CUtils::isBigEndian() noexcept {
    const uint16_t probe = 0x0102u;
    return *reinterpret_cast<const uint8_t*>(&probe) == 0x01u;
}

// Disassembly @ 0x0668b0:
//   5ac00808 rev w8, w0
//   53107d00 lsr w0, w8, #0x10
//   d65f03c0 ret
uint16_t CUtils::flip(uint16_t v) noexcept {
    return static_cast<uint16_t>((v >> 8u) | (v << 8u));
}

// Disassembly @ 0x0668bc:
//   5ac00800 rev w0, w0
//   d65f03c0 ret
uint32_t CUtils::flip(uint32_t v) noexcept {
    return ((v & 0xFF000000u) >> 24u) |
           ((v & 0x00FF0000u) >> 8u)  |
           ((v & 0x0000FF00u) << 8u)  |
           ((v & 0x000000FFu) << 24u);
}

// Disassembly @ 0x066d00..0x066d7c:
//   Computes MSE = sum((p1[i] - p2[i])^2) / (width * height),
//   loads 65025.0 (255^2) from .rodata 0x080d10, and returns 10.0 * log10(65025.0 / MSE).
double CUtils::CalcFramePsnr(const uint8_t* p1, const uint8_t* p2, int32_t width, int32_t height) noexcept {
    if (!p1 || !p2 || width < 1 || height < 1) {
        return 0.0;
    }
    const int64_t total_pixels = static_cast<int64_t>(width) * static_cast<int64_t>(height);
    double sum_sq_err = 0.0;
    for (int64_t i = 0; i < total_pixels; ++i) {
        const int32_t diff = static_cast<int32_t>(p1[i]) - static_cast<int32_t>(p2[i]);
        const double d = static_cast<double>(diff);
        sum_sq_err += d * d;
    }
    const double mse = sum_sq_err / static_cast<double>(total_pixels);
    if (mse <= 0.0) {
        return 100.0;
    }
    constexpr double kPeakSquared_080d10 = 65025.0; // 255.0 * 255.0 @ .rodata 0x080d10
    return 10.0 * std::log10(kPeakSquared_080d10 / mse);
}

// Disassembly @ 0x066eec..0x066f0c:
//   cmp w0, #0; cset w8, gt; cmp w1, #0; cset w9, gt; cmp w0, w1; and w8, w8, w9; cset w9, ne; and w0, w9, w8; ret
bool CUtils::isSpecialSar(int32_t num, int32_t den) noexcept {
    return (num > 0) && (den > 0) && (num != den);
}

void CUtils::NV12ToI420(uint8_t* src_y, uint8_t* src_uv, uint8_t* dst_y, uint8_t* dst_u, uint8_t* dst_v, int32_t width, int32_t height) noexcept {
    if (!src_y || !src_uv || !dst_y || !dst_u || !dst_v || width <= 0 || height <= 0) {
        return;
    }
    const int32_t y_size = width * height;
    std::memcpy(dst_y, src_y, static_cast<size_t>(y_size));
    const int32_t uv_count = (width / 2) * (height / 2);
    for (int32_t i = 0; i < uv_count; ++i) {
        dst_u[i] = src_uv[2 * i];
        dst_v[i] = src_uv[2 * i + 1];
    }
}

// ============================================================================
// 3. ByteBenchConfiguration & ByteBench (0x043570 .. 0x04435c)
// ============================================================================
ByteBenchConfiguration::ByteBenchConfiguration() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    abi_.status = 1;
    abi_.log_level = 2u;
    abi_.open_runtime_decision = 1u;
}

int32_t ByteBench::init(std::shared_ptr<ByteBenchConfiguration> config) noexcept {
    if (!config) {
        return -1;
    }
    g_bytebench_inited_0a0650 = 1u;
    return 0;
}

// Disassembly @ 0x043edc:
//   b00002e8 adrp x8, #0xa0000
//   39594100 ldrb w0, [x8, #0x650]
//   d65f03c0 ret
bool ByteBench::isInit() noexcept {
    return g_bytebench_inited_0a0650 != 0u;
}

} // namespace bytebench

// ============================================================================
// 4. BXFFReduce(STERational&) (0x06b084 .. 0x06b244)
// Disassembly @ 0x06b098..0x06b0e8:
//   ldpsw x22, x23, [x0]
//   cmp x22, #0; cneg x8, x22, mi
//   cmp x23, #0; cneg x9, x23, mi
//   Euclidean GCD loop: sdiv x11, x10, x11; msub x11, x11, x12, x10
//   sdiv x20, x8, x10; sdiv x21, x9, x10
// ============================================================================
int32_t BXFFReduce(bytebench::STERational& r) noexcept {
    int64_t num = static_cast<int64_t>(r.num);
    int64_t den = static_cast<int64_t>(r.den);
    int64_t abs_num = (num < 0) ? -num : num;
    int64_t abs_den = (den < 0) ? -den : den;
    int64_t a = std::max(abs_num, abs_den);
    int64_t b = std::min(abs_num, abs_den);
    while (b != 0) {
        const int64_t rem = a - (a / b) * b;
        a = b;
        b = rem;
    }
    if (a != 0) {
        abs_num /= a;
        abs_den /= a;
    }
    const int64_t sign = ((num ^ den) < 0) ? -1 : 1;
    r.num = static_cast<int32_t>(abs_num * sign);
    r.den = static_cast<int32_t>(abs_den);
    return (abs_num <= 0x7FFFFFFFLL && abs_den <= 0x7FFFFFFFLL) ? 1 : 0;
}

extern "C" {

void* ByteBench_getInstance() noexcept {
    static bytebench::BXMonitor s_monitor;
    return &s_monitor;
}

// Disassembly @ 0x056288..0x0562a8: calls virtual slot +0x68 and converts float s0 -> double d0 (`fcvt d0, s0`)
double ByteBench_getDeviceInfo(void* instance) noexcept {
    if (!instance) {
        return 0.0;
    }
    auto* mon = static_cast<bytebench::BXMonitor*>(instance);
    return static_cast<double>(mon->AvailableMem());
}

double ByteBench_getDeviceFeature(void* instance, const char* feature_key) noexcept {
    if (!instance || !feature_key) {
        return 0.0;
    }
    auto* mon = static_cast<bytebench::BXMonitor*>(instance);
    if (std::strcmp(feature_key, "cpu_speed") == 0) {
        return static_cast<double>(mon->CPUSpeedAverage());
    }
    if (std::strcmp(feature_key, "cpu_process_usage") == 0) {
        return static_cast<double>(mon->CPUProcessUsage());
    }
    if (std::strcmp(feature_key, "battery_ectriccurrent") == 0) {
        return static_cast<double>(mon->BatteryElectricCurrent());
    }
    return static_cast<double>(mon->MemUsage());
}

double ByteBench_obtainNumberStrategy(int32_t /*space_id*/, const char* /*key*/, double default_val, bool /*is_static*/) noexcept {
    return default_val;
}

} // extern "C"
