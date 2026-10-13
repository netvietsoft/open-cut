/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Graphics Engine
 * File: AGFX_Utils.h
 * Module: libAGFX.so (Amazing Engine / Runtime / RenderLib / Utils.cpp)
 * 
 * Description (EN):
 * Texture manipulation, ASTC format decompression calculations, cross-context
 * texture sharing (Friend Textures between GLES Render and GPGPU Compute),
 * GPU Bitonic Sort, and EGL GLES context management.
 *
 * Mô tả (VI):
 * Xử lý kết cấu đồ họa (Texture), tính toán kích thước nén định dạng ASTC,
 * chia sẻ kết cấu đồ họa giữa ngữ cảnh Render và Compute (Friend Texture),
 * sắp xếp song song Bitonic Sort trên GPU, và quản lý ngữ cảnh EGL GLES.
 * ============================================================================
 */

#pragma once

#include "AGFX_Types.h"
#include "AGFX_RendererDevice.h"
#include "AGFX_ComputerDevice.h"
#include <string>

namespace AmazingEngine {

namespace Utils {

    // ASTC Texture compression verification and block dimension queries
    bool isASTCCompressionFormat(const AMGPixelFormat& format);
    void getASTCTexBlockDims(const AMGPixelFormat& format, int& blockWidth, int& blockHeight);
    int  getASTCTexSize(const AMGPixelFormat& format, const int& width, const int& height);
    int  getASTCTexBytesPerRow(const AMGPixelFormat& format, const int& width);
    int  getCompressedTexSize(const AMGPixelFormat& format, const int& width, const int& height);
    int  getCompressedTexBytesPerRow(const AMGPixelFormat& format, const int& width);

    // Cross-engine texture sharing (Zero-copy binding between Render and Compute)
    DeviceTexture getFriendTexture(ComputerDevice* computer, DeviceTexture renderTex);
    DeviceTexture getFriendTexture(RendererDevice* renderer, DeviceTexture computeTex);

    // GPU Compute Bitonic Sort (Runtime/RenderLib/GLES31/Computelib/BitonicSort.cpp)
    void bitonicSortU32(
        GPDevice* device,
        handle_DeviceBuffer_t* keys,
        unsigned int count,
        handle_DeviceBuffer_t* values,
        handle_DeviceBuffer_t* tempBuf,
        bool ascending,
        handle_DeviceSequence_t* seq
    );

    void bitonicSortF32(
        GPDevice* device,
        handle_DeviceBuffer_t* keys,
        unsigned int count,
        handle_DeviceBuffer_t* values,
        handle_DeviceBuffer_t* tempBuf,
        bool ascending,
        handle_DeviceSequence_t* seq
    );

    // Camera and Video YUV -> RGB conversion
    void convertYuvToRgb(
        GPDevice* device,
        DeviceTexture yTex,
        DeviceTexture uvTex,
        DeviceTexture dstRgbTex,
        const float matrix[4][4],
        handle_DeviceSequence_t* seq
    );

    // Synchronization
    void flushCommands(RendererDevice* renderer);
    void waitUntilCompleted(GPDevice* device, handle_DeviceSequence_t* seq);

} // namespace Utils

namespace AGFXUtils {

    /**
     * RAII GLES / EGL Context Guard
     * Quản lý ngữ cảnh OpenGL ES / EGL tự động lưu và phục hồi
     */
    class GLESContext {
    public:
        GLESContext();
        virtual ~GLESContext();

        bool bind();
        void unbind();

    private:
        void* m_savedDisplay = nullptr;
        void* m_savedDrawSurface = nullptr;
        void* m_savedReadSurface = nullptr;
        void* m_savedContext = nullptr;

        void* m_currentDisplay = nullptr;
        void* m_currentSurface = nullptr;
        void* m_currentContext = nullptr;
        bool m_isBound = false;
    };

} // namespace AGFXUtils

} // namespace AmazingEngine
