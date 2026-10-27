// ============================================================================
// Clean-Room C++17 Core Interfaces for libkrypton.so (Target 115 / 169)
// Giao diện lõi C++17 sạch cho libkrypton.so (Mục tiêu 115 / 169)
// ============================================================================
#pragma once

#include "krypton_types.h"

namespace lynx {
namespace canvas {

struct CanvasSize {
    int32_t width{0};
    int32_t height{0};
};

class CanvasResourceProvider {
public:
    CanvasResourceProvider(CanvasSize size, float density, bool anti_alias);
    virtual ~CanvasResourceProvider() = default;

    CanvasSize GetSize() const noexcept { return size_; }
    float GetDensity() const noexcept { return density_; }
    bool IsAntiAlias() const noexcept { return anti_alias_; }
    uint32_t FlushFrame();

private:
    CanvasSize size_{};
    float density_{1.0f};
    bool anti_alias_{true};
    uint32_t frame_count_{0};
};

class CanvasApp {
public:
    CanvasApp();
    ~CanvasApp();

    // Reconstructed from 0x0ace64..0x0acfc8
    void OnRuntimeAttach(void* js_runtime, bool enable_gpu_task_runner);
    void OnRuntimeDetach();
    bool IsAttached() const noexcept { return attached_; }

private:
    bool attached_{false};
    bool gpu_task_runner_enabled_{false};
    void* js_runtime_{nullptr};
};

namespace remote {

class RemoteBridge {
public:
    RemoteBridge() = default;
    ~RemoteBridge() = default;
    bool DispatchCommand(uint32_t cmd_id, const DataHolder& payload);
    uint64_t GetProcessedCount() const noexcept { return processed_count_; }

private:
    uint64_t processed_count_{0};
};

class RemoteEnvImpl {
public:
    static std::vector<std::string>& GetRegisteredModules();
    static void RegisterModule(const std::string& name);
};

} // namespace remote

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace canvas
} // namespace lynx
