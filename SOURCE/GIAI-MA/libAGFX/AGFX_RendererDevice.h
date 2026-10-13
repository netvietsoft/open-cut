// ===================================================================================
// AGFX_RendererDevice.h — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Trình điều khiển đồ họa render chính (Texture, Shaders, FBO, Render State)
// ===================================================================================

#pragma once

#include "AGFX_Types.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace NextAI::OpenCut::AGFX {

class RendererDevice {
public:
    explicit RendererDevice(RendererType type = RendererType::GLES30);
    virtual ~RendererDevice();

    // Khởi tạo và liên kết ngữ cảnh EGL/OpenGL
    virtual bool init();
    virtual void bindMainContext();
    virtual void setContextSink(bool sink);
    virtual void setAgfxFixModeEnable(bool enable);

    // Quản lý khung hình vẽ (Frame rendering lifecycle)
    virtual void beginRender(
        handle_DeviceFramebuffer_t* fbo,
        const framebuffer_clear_info* clearInfo,
        handle_DeviceSequence_t* sequence
    );
    virtual void submit(handle_DeviceSequence_t* sequence, bool flushGpu = false);
    virtual void waitForSequence(handle_DeviceFence_t* fence, handle_DeviceSequence_t* sequence);
    virtual void clearDepthAttachment(float depthValue, handle_DeviceSequence_t* sequence);

    // Khởi tạo Texture 2D / 3D LUT / Video Frame ngoài
    virtual DeviceTexture createTexture2D(
        int width,
        int height,
        AMGFilterMipmapMode mipmapMode,
        int mipmapLevels,
        const void* const* data,
        AMGPixelFormat format,
        AMGFilterMode minFilter,
        AMGFilterMode magFilter,
        AMGWrapMode wrapS,
        AMGWrapMode wrapT,
        int* outTextureId = nullptr,
        const char* debugName = "Tex2D",
        bool isLinear = true,
        bool isRenderTarget = false
    );

    virtual DeviceTexture createTexture3D(
        int width,
        int height,
        int depth,
        const void* const* data,
        AMGPixelFormat format,
        AMGFilterMode minFilter,
        AMGFilterMode magFilter,
        AMGWrapMode wrapS,
        AMGWrapMode wrapT,
        int* outTextureId = nullptr,
        const char* debugName = "LUT3D",
        bool isLinear = true,
        bool isRenderTarget = false
    );

    // Tạo Texture từ OES External Texture (Khung hình Camera / Video Decoder)
    virtual DeviceTexture createTextureFromExternalTexture(
        uint64_t externalHandle,
        ImageType imgType,
        AMGPixelFormat format,
        int width,
        int height,
        bool useLinearFiltering = true,
        bool autoRelease = true
    );

    // Hủy texture và giải phóng bộ nhớ VRAM
    virtual void destroyTexture(DeviceTexture texture);
    virtual void setTextureMaxAnisotropy(DeviceTexture texture, const tex_create_info* info);

    // Thiết lập Uniforms cho Shaders
    virtual void SetVector(const std::string& uniformName, const Vector4f& value);
    virtual void SetFloat(int uniformLocation, float value);
    virtual int GetPropertyBlockInt();

    // Quản lý Buffer và VBO
    virtual void* mapBuffer(handle_DeviceBuffer_t* buffer);
    virtual void unmapBuffer(handle_DeviceBuffer_t* buffer);

    // Hủy đối tượng render và tài nguyên
    virtual void destroyEntity(handle_RenderEntity_t* entity);
    virtual void destroyContextUnshareableResources(bool forceAll);

    RendererType getRendererType() const { return m_rendererType; }

protected:
    RendererType m_rendererType;
    bool m_fixModeEnabled = false;
    uint32_t m_currentBoundFbo = 0;
    uint64_t m_nextTextureId = 1;

    // Bảng lưu trữ Texture trên VRAM
    std::unordered_map<DeviceTexture, tex_create_info> m_allocatedTextures;
    std::unordered_map<std::string, Vector4f> m_uniformVectors;
    std::unordered_map<int, float> m_uniformFloats;
};

} // namespace NextAI::OpenCut::AGFX
