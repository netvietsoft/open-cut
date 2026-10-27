// ============================================================================
// File: bytebench_core.h
// Target 107 / 169: libbytebench.so (641,376 bytes)
// EN: Public C++17 declarations for bytebench::BXMonitor, CUtils, CTime,
//     BXFeatureProcessConfig, ByteBenchConfiguration, ByteBench, and BXFFReduce.
// VI: Khai báo C++17 cho bytebench::BXMonitor, CUtils, CTime,
//     BXFeatureProcessConfig, ByteBenchConfiguration, ByteBench và BXFFReduce.
// ============================================================================
#pragma once

#include "bytebench_types.h"

namespace bytebench {

class BXMonitor {
public:
    BXMonitor() noexcept;
    virtual ~BXMonitor();

    int32_t init() noexcept;
    float CPUProcessUsage() noexcept;
    float BatteryLevel() noexcept;
    float CPUFreq() noexcept;
    float BatteryTemp() noexcept;
    float AvailableMem() noexcept;
    float MemUsage() noexcept;
    float BatteryElectricCurrent() noexcept;
    float CPUSpeedAverage() noexcept;
    float ProcessVirtualMemorySize() noexcept;
    float getJavaHeapMaxMemory() noexcept;
    float getJavaHeapTotalMemory() noexcept;
    float getJavaHeapFreeMemory() noexcept;
    float getJavaHeapUsage() noexcept;
    float isLowPowerMode() noexcept;
    float GPUUsage() noexcept;
    int32_t getNetWorkLevel() noexcept;

    const BXMonitorAbiLayout& abi() const noexcept { return abi_; }

private:
    BXMonitorAbiLayout abi_{};
};

class CUtils {
public:
    static bool isBigEndian() noexcept;
    static uint16_t flip(uint16_t v) noexcept;
    static uint32_t flip(uint32_t v) noexcept;
    static double CalcFramePsnr(const uint8_t* p1, const uint8_t* p2, int32_t width, int32_t height) noexcept;
    static bool isSpecialSar(int32_t num, int32_t den) noexcept;
    static void NV12ToI420(uint8_t* src_y, uint8_t* src_uv, uint8_t* dst_y, uint8_t* dst_u, uint8_t* dst_v, int32_t width, int32_t height) noexcept;
};

class ByteBenchConfiguration {
public:
    ByteBenchConfiguration() noexcept;
    const ByteBenchConfigurationAbiLayout& abi() const noexcept { return abi_; }

    int32_t getStatus() const noexcept { return abi_.status; }
    int32_t getAid() const noexcept { return abi_.aid; }
    int32_t getBid() const noexcept { return abi_.bid; }
    int64_t getUpdateVersionCode() const noexcept { return abi_.update_version_code; }
    uint8_t getLogLevel() const noexcept { return abi_.log_level; }
    bool isIsOpenRuntimeDecision() const noexcept { return abi_.open_runtime_decision != 0; }
    bool isLowDiskMemory() const noexcept { return abi_.low_disk_memory != 0; }

private:
    ByteBenchConfigurationAbiLayout abi_{};
};

class ByteBench {
public:
    static int32_t init(std::shared_ptr<ByteBenchConfiguration> config) noexcept;
    static bool isInit() noexcept;
};

} // namespace bytebench

// Disassembly @ 0x06b084..0x06b244: Euclidean GCD rational reduction
int32_t BXFFReduce(bytebench::STERational& r) noexcept;

extern "C" {
void* ByteBench_getInstance() noexcept;
double ByteBench_getDeviceInfo(void* instance) noexcept;
double ByteBench_getDeviceFeature(void* instance, const char* feature_key) noexcept;
double ByteBench_obtainNumberStrategy(int32_t space_id, const char* key, double default_val, bool is_static) noexcept;
}

namespace bytebench {
uint64_t ExecuteByteBenchFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;
} // namespace bytebench
