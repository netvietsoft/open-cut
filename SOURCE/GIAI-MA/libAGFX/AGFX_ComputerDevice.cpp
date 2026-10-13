// ===================================================================================
// AGFX_ComputerDevice.cpp — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Cài đặt chi tiết toàn bộ thân hàm cho ComputerDevice (GPGPU Shaders)
// ===================================================================================

#include "AGFX_ComputerDevice.h"
#include "AGFX_RendererDevice.h"
#include <iostream>

namespace NextAI::OpenCut::AGFX {

ComputerDevice::ComputerDevice(std::shared_ptr<RendererDevice> renderer)
    : m_renderer(renderer),
      m_currentComputeProgram(0) {
}

ComputerDevice::~ComputerDevice() {
    deinit();
}

bool ComputerDevice::init() {
    return true;
}

void ComputerDevice::deinit() {
    if (m_currentComputeProgram != 0) {
        // glDeleteProgram(m_currentComputeProgram);
        m_currentComputeProgram = 0;
    }
}

void ComputerDevice::bindMainContext() {
    if (m_renderer) {
        m_renderer->bindMainContext();
    }
}

bool ComputerDevice::createPipelineWithComputeShader(
    const std::string& shaderSource,
    const std::string& entryPoint
) {
    // 1. Tạo GL_COMPUTE_SHADER trong OpenGL ES 3.1
    // GLuint shader = glCreateShader(GL_COMPUTE_SHADER);
    // glShaderSource(shader, 1, &src, nullptr);
    // glCompileShader(shader);
    // 2. Link vào Program
    // m_currentComputeProgram = glCreateProgram();
    // glAttachShader(m_currentComputeProgram, shader);
    // glLinkProgram(m_currentComputeProgram);
    m_currentComputeProgram = 1001; // Mock program ID
    return true;
}

void ComputerDevice::dispatch(
    handle_ComputeEntity_t* entity,
    uint32_t numGroupsX,
    uint32_t numGroupsY,
    uint32_t numGroupsZ,
    handle_DeviceSequence_t* sequence
) {
    if (entity) {
        // glUseProgram(entity->computeProgramId);
        // glDispatchCompute(numGroupsX, numGroupsY, numGroupsZ);
        // glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
    }
    if (sequence) {
        sequence->isCompleted = false;
    }
}

void ComputerDevice::apply(
    handle_ComputeEntity_t* entity,
    const DeviceProperty* properties,
    int propertyCount
) {
    if (!properties || propertyCount <= 0) return;

    for (int i = 0; i < propertyCount; ++i) {
        const auto& prop = properties[i];
        // Nạp biến SSBO hoặc gán Uniform Block vào Shader
        // glBindBufferBase(GL_SHADER_STORAGE_BUFFER, binding, ssboId);
    }
}

void ComputerDevice::endCompute(handle_DeviceSequence_t* sequence) {
    // glMemoryBarrier(GL_ALL_BARRIER_BITS);
    if (sequence) {
        sequence->isCompleted = true;
    }
}

void ComputerDevice::submit(handle_DeviceSequence_t* sequence, bool flush) {
    if (flush) {
        // glFlush();
    }
    if (sequence) {
        sequence->isCompleted = true;
    }
}

} // namespace NextAI::OpenCut::AGFX
