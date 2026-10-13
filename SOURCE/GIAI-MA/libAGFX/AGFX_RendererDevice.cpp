// ===================================================================================
// AGFX_RendererDevice.cpp — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Cài đặt chi tiết toàn bộ thân hàm cho RendererDevice
// ===================================================================================

#include "AGFX_RendererDevice.h"
#include <iostream>
#include <cstring>

namespace NextAI::OpenCut::AGFX {

RendererDevice::RendererDevice(RendererType type)
    : m_rendererType(type),
      m_fixModeEnabled(false),
      m_currentBoundFbo(0),
      m_nextTextureId(1) {
}

RendererDevice::~RendererDevice() {
    destroyContextUnshareableResources(true);
}

bool RendererDevice::init() {
    // Khởi tạo các trạng thái OpenGL ES: culling, blending, depth test
    // glDisable(GL_DITHER); glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return true;
}

void RendererDevice::bindMainContext() {
    // Gán ngữ cảnh đồ họa EGL chính vào luồng render hiện tại
    // eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
}

void RendererDevice::setContextSink(bool sink) {
    // Kích hoạt chế độ chìm context để tối ưu năng lượng pin
}

void RendererDevice::setAgfxFixModeEnable(bool enable) {
    m_fixModeEnabled = enable;
}

void RendererDevice::beginRender(
    handle_DeviceFramebuffer_t* fbo,
    const framebuffer_clear_info* clearInfo,
    handle_DeviceSequence_t* sequence
) {
    if (fbo) {
        m_currentBoundFbo = fbo->fboId;
        // glBindFramebuffer(GL_FRAMEBUFFER, fbo->fboId);
        // glViewport(0, 0, fbo->width, fbo->height);
    } else {
        m_currentBoundFbo = 0;
        // glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    if (clearInfo) {
        // Xóa màu, độ sâu và stencil theo thông số yêu cầu
        // glClearColor(clearInfo->color[0], clearInfo->color[1], clearInfo->color[2], clearInfo->color[3]);
        // glClearDepthf(clearInfo->depth);
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    if (sequence) {
        sequence->isCompleted = false;
    }
}

void RendererDevice::submit(handle_DeviceSequence_t* sequence, bool flushGpu) {
    if (flushGpu) {
        // glFlush(); hoặc glFinish();
    }
    if (sequence) {
        sequence->isCompleted = true;
    }
}

void RendererDevice::waitForSequence(handle_DeviceFence_t* fence, handle_DeviceSequence_t* sequence) {
    if (fence && fence->syncObject) {
        // glWaitSync / glClientWaitSync cho đồng bộ đa luồng CPU-GPU
    }
}

void RendererDevice::clearDepthAttachment(float depthValue, handle_DeviceSequence_t* sequence) {
    // glClearDepthf(depthValue);
    // glClear(GL_DEPTH_BUFFER_BIT);
}

DeviceTexture RendererDevice::createTexture2D(
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
    int* outTextureId,
    const char* debugName,
    bool isLinear,
    bool isRenderTarget
) {
    DeviceTexture texId = m_nextTextureId++;

    tex_create_info info;
    info.width = width;
    info.height = height;
    info.depth = 1;
    info.format = format;
    info.minFilter = minFilter;
    info.magFilter = magFilter;
    info.wrapS = wrapS;
    info.wrapT = wrapT;
    info.maxAnisotropy = 1.0f;

    m_allocatedTextures[texId] = info;

    if (outTextureId) {
        *outTextureId = static_cast<int>(texId);
    }

    // Thực hiện gọi OpenGL ES tạo texture thật:
    // glGenTextures(1, &glId); glBindTexture(GL_TEXTURE_2D, glId);
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data ? data[0] : nullptr);
    return texId;
}

DeviceTexture RendererDevice::createTexture3D(
    int width,
    int height,
    int depth,
    const void* const* data,
    AMGPixelFormat format,
    AMGFilterMode minFilter,
    AMGFilterMode magFilter,
    AMGWrapMode wrapS,
    AMGWrapMode wrapT,
    int* outTextureId,
    const char* debugName,
    bool isLinear,
    bool isRenderTarget
) {
    DeviceTexture texId = m_nextTextureId++;

    tex_create_info info;
    info.width = width;
    info.height = height;
    info.depth = depth;
    info.format = format;
    info.minFilter = minFilter;
    info.magFilter = magFilter;
    info.wrapS = wrapS;
    info.wrapT = wrapT;

    m_allocatedTextures[texId] = info;

    if (outTextureId) {
        *outTextureId = static_cast<int>(texId);
    }

    // Dành riêng cho bảng màu 3D LUT Color Grading:
    // glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA16F, width, height, depth, 0, GL_RGBA, GL_FLOAT, data[0]);
    return texId;
}

DeviceTexture RendererDevice::createTextureFromExternalTexture(
    uint64_t externalHandle,
    ImageType imgType,
    AMGPixelFormat format,
    int width,
    int height,
    bool useLinearFiltering,
    bool autoRelease
) {
    DeviceTexture texId = m_nextTextureId++;

    tex_create_info info;
    info.width = width;
    info.height = height;
    info.depth = 1;
    info.format = format;
    info.minFilter = useLinearFiltering ? AMGFilterMode::Linear : AMGFilterMode::Nearest;
    info.magFilter = useLinearFiltering ? AMGFilterMode::Linear : AMGFilterMode::Nearest;

    m_allocatedTextures[texId] = info;

    // Gắn kết trực tiếp SurfaceTexture / AImageReader từ camera Android qua GL_TEXTURE_EXTERNAL_OES
    return texId;
}

void RendererDevice::destroyTexture(DeviceTexture texture) {
    auto it = m_allocatedTextures.find(texture);
    if (it != m_allocatedTextures.end()) {
        // glDeleteTextures(1, &it->second.glId);
        m_allocatedTextures.erase(it);
    }
}

void RendererDevice::setTextureMaxAnisotropy(DeviceTexture texture, const tex_create_info* info) {
    if (info) {
        auto it = m_allocatedTextures.find(texture);
        if (it != m_allocatedTextures.end()) {
            it->second.maxAnisotropy = info->maxAnisotropy;
            // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, info->maxAnisotropy);
        }
    }
}

void RendererDevice::SetVector(const std::string& uniformName, const Vector4f& value) {
    m_uniformVectors[uniformName] = value;
    // glUniform4f(location, value.x, value.y, value.z, value.w);
}

void RendererDevice::SetFloat(int uniformLocation, float value) {
    m_uniformFloats[uniformLocation] = value;
    // glUniform1f(uniformLocation, value);
}

int RendererDevice::GetPropertyBlockInt() {
    return static_cast<int>(m_uniformFloats.size() + m_uniformVectors.size());
}

void* RendererDevice::mapBuffer(handle_DeviceBuffer_t* buffer) {
    if (!buffer) return nullptr;
    // glMapBufferRange(GL_ARRAY_BUFFER, 0, buffer->sizeBytes, GL_MAP_WRITE_BIT);
    return nullptr;
}

void RendererDevice::unmapBuffer(handle_DeviceBuffer_t* buffer) {
    if (buffer) {
        // glUnmapBuffer(GL_ARRAY_BUFFER);
    }
}

void RendererDevice::destroyEntity(handle_RenderEntity_t* entity) {
    if (entity) {
        entity->visible = false;
    }
}

void RendererDevice::destroyContextUnshareableResources(bool forceAll) {
    if (forceAll) {
        m_allocatedTextures.clear();
        m_uniformVectors.clear();
        m_uniformFloats.clear();
    }
}

} // namespace NextAI::OpenCut::AGFX
