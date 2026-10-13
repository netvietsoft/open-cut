// ===================================================================================
// AGFX_ComputerDevice.h — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Trình tính toán GPGPU Compute Shader (OpenGL ES 3.1 / Vulkan compute)
// ===================================================================================

#pragma once

#include "AGFX_Types.h"
#include <memory>
#include <string>
#include <vector>

namespace NextAI::OpenCut::AGFX {

class RendererDevice;

struct DeviceProperty {
    std::string propertyName;
    SymbolType type = SymbolType::Float;
    int size = 1;
    std::vector<uint8_t> rawData;
};

class ComputerDevice {
public:
    explicit ComputerDevice(std::shared_ptr<RendererDevice> renderer);
    virtual ~ComputerDevice();

    virtual bool init();
    virtual void deinit();
    virtual void bindMainContext();

    // Thiết lập Pipeline Compute Shader
    virtual bool createPipelineWithComputeShader(
        const std::string& shaderSource,
        const std::string& entryPoint = "main"
    );

    // Kích hoạt tính toán đa luồng GPU (GPGPU Dispatch)
    virtual void dispatch(
        handle_ComputeEntity_t* entity,
        uint32_t numGroupsX,
        uint32_t numGroupsY,
        uint32_t numGroupsZ,
        handle_DeviceSequence_t* sequence
    );

    // Nạp thuộc tính (SSBO / Uniform Buffer) vào Compute Entity
    virtual void apply(
        handle_ComputeEntity_t* entity,
        const DeviceProperty* properties,
        int propertyCount
    );

    // Kết thúc và đồng bộ chuỗi lệnh tính toán
    virtual void endCompute(handle_DeviceSequence_t* sequence);
    virtual void submit(handle_DeviceSequence_t* sequence, bool flush = false);

protected:
    std::shared_ptr<RendererDevice> m_renderer;
    uint32_t m_currentComputeProgram = 0;
};

} // namespace NextAI::OpenCut::AGFX
