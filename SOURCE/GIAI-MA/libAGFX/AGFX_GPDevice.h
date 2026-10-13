// ===================================================================================
// AGFX_GPDevice.h — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Lớp thiết bị đồ họa nền tảng (Graphic Processing Device Manager)
// ===================================================================================

#pragma once

#include "AGFX_Types.h"
#include <memory>
#include <string>

namespace NextAI::OpenCut::AGFX {

class AGFXABConfig;
class RendererDevice;
class ComputerDevice;

struct PerfStats {
    float frameTimeMs = 0.0f;
    float gpuRenderTimeMs = 0.0f;
    uint32_t drawCallCount = 0;
    uint32_t triangleCount = 0;
    uint64_t allocatedVramBytes = 0;
};

class GPDevice {
public:
    GPDevice();
    virtual ~GPDevice();

    // Khởi tạo và tạo thiết bị đồ họa chính
    static std::shared_ptr<GPDevice> createDevice(
        RendererType rendererType,
        GPDevice* parentDevice = nullptr,
        AGFXABConfig* abConfig = nullptr,
        const char* debugName = "NextAI_AGFX_Device",
        uint32_t flags = 0
    );

    // Khởi tạo thư viện driver đồ họa động (EGL / GLES)
    static bool initGLESv2LibraryWithFunc(void* getProcAddressFunc);

    // Khởi tạo phiên bản GLES (2.0, 3.0, 3.1)
    virtual bool createGLESX(uint32_t glesVersion);

    // Điều khiển vòng đời (Lifecycle)
    virtual void resume();
    virtual void pause();

    // Thu thập thống kê hiệu năng thời gian thực (FPS, VRAM, DrawCalls)
    virtual PerfStats getBasicPerfStats() const;

    // Bắt đầu / Kết thúc thu thập đồ thị hiệu năng đồ họa
    virtual void beginGraphicsDataFrameCollection();
    virtual void endGraphicsDataFrameCollection();

    // Kiểm tra kiến trúc bộ nhớ GPU dùng chung (Unified Memory Architecture - UMA)
    virtual bool isGPUUnifiedMemoryModel() const;

    // Lấy trình vẽ render và trình tính toán GPGPU
    std::shared_ptr<RendererDevice> getRendererDevice() const { return m_rendererDevice; }
    std::shared_ptr<ComputerDevice> getComputerDevice() const { return m_computerDevice; }

    RendererType getRendererType() const { return m_rendererType; }

protected:
    RendererType m_rendererType = RendererType::GLES30;
    bool m_isPaused = false;
    bool m_isCollectingPerf = false;
    PerfStats m_currentStats;

    std::shared_ptr<RendererDevice> m_rendererDevice;
    std::shared_ptr<ComputerDevice> m_computerDevice;
    std::string m_deviceName;
};

} // namespace NextAI::OpenCut::AGFX
