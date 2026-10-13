/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Graphics Engine
 * File: AGFX_interface.h
 * Target Library: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
 * Package Name: com.nextai.opencut
 * 
 * Description (EN):
 * Master umbrella header and high-level C++ facade for libAGFX.
 * Provides unified access to all reconstructed subsystems:
 *   1. Hardware Device Abstraction (GPDevice, RendererDevice, ComputerDevice)
 *   2. Dynamic GLSL Shader Patcher (ShaderPatcherV2, ASTC, Uniform Clamping)
 *   3. 3D Particle Fluid Simulator (PBFSimulator, Spatial Grid Hashing)
 *   4. AUSL Shader Variant Permutation Manager (KeywordProgramManager)
 *   5. Texture Utilities, Bitonic Sort & Color Conversion (Utils, GLESContext)
 *
 * Mô tả (VI):
 * Tệp tiêu đề tổng thể (Umbrella Header) và lớp Facade cấp cao cho libAGFX.
 * Cung cấp quyền truy cập hợp nhất vào toàn bộ các phân hệ đã tái cấu trúc:
 *   1. Trừu tượng hóa thiết bị phần cứng (GPDevice, RendererDevice, ComputerDevice)
 *   2. Vá động mã Shader GLSL (ShaderPatcherV2, ASTC, Uniform Clamping)
 *   3. Bộ mô phỏng hạt chất lỏng 3D PBF (PBFSimulator, Spatial Grid Hashing)
 *   4. Quản lý biến thể Shader AUSL (KeywordProgramManager)
 *   5. Tiện ích Texture, Bitonic Sort & Chuyển đổi màu (Utils, GLESContext)
 * ============================================================================
 */

#pragma once

#include "AGFX_Types.h"
#include "AGFX_GPDevice.h"
#include "AGFX_RendererDevice.h"
#include "AGFX_ComputerDevice.h"
#include "AGFX_ShaderPatcher.h"
#include "AGFX_PBFSimulator.h"
#include "AGFX_KeywordProgramManager.h"
#include "AGFX_Utils.h"

#include <memory>
#include <string>
#include <vector>

namespace NextAI::OpenCut::AGFX {

/**
 * High-Level Amazing Graphics Engine Facade
 * Lớp điều phối cấp cao toàn bộ chu trình hiệu ứng đồ họa CapCut
 */
class AgfxEngine {
public:
    AgfxEngine();
    virtual ~AgfxEngine();

    // Engine Lifecycle & Device Initialization
    bool initialize(AmazingEngine::RendererType rType = AmazingEngine::RendererType::GLES31);
    void release();

    // Shader Patcher Subsystem
    std::string patchShader(
        AmazingEngine::AMGShaderType type,
        const std::string& glslSource,
        const std::vector<std::string>& activeKeywords
    );

    // 3D PBF Particle Simulation Subsystem
    bool initParticleSimulation(
        const AmazingEngine::PBFParams& params,
        AmazingEngine::Vector4f minBounds,
        AmazingEngine::Vector4f maxBounds
    );
    void updateParticleSimulation(float dt);
    void setFaceTrackerMesh(AmazingEngine::Vector4f faceCenter, AmazingEngine::Vector4f faceRadius,
                            AmazingEngine::Vector4f noseCenter, AmazingEngine::Vector4f noseRadius);

    // Render & Compute Pipeline Execution
    AmazingEngine::DeviceTexture processFrame(
        AmazingEngine::DeviceTexture inputCameraTexture,
        int outputWidth,
        int outputHeight
    );

    // Getters for lower-level subsystems
    AmazingEngine::RendererDevice* getRendererDevice() const { return m_rendererDevice.get(); }
    AmazingEngine::ComputerDevice* getComputerDevice() const { return m_computerDevice.get(); }
    AmazingEngine::PBFSimulator* getPBFSimulator() const { return m_pbfSimulator.get(); }
    AmazingEngine::KeywordProgramManager* getKeywordManager() const { return m_keywordManager.get(); }

private:
    bool m_isInitialized = false;

    // Subsystem instances
    std::unique_ptr<AmazingEngine::GPDevice>              m_gpDevice;
    std::unique_ptr<AmazingEngine::RendererDevice>        m_rendererDevice;
    std::unique_ptr<AmazingEngine::ComputerDevice>        m_computerDevice;
    std::unique_ptr<AmazingEngine::PBFSimulator>          m_pbfSimulator;
    std::unique_ptr<AmazingEngine::KeywordProgramManager> m_keywordManager;
    std::unique_ptr<AmazingEngine::ShaderPatcherV2>       m_shaderPatcher;

    // Context & Sequence Handles
    AmazingEngine::handle_DeviceSequence_t* m_activeSequence = nullptr;
    AmazingEngine::PBFContext m_pbfContext;
};

} // namespace NextAI::OpenCut::AGFX
