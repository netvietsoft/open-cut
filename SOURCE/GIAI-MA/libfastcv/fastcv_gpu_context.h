// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — GPU Context, Hardware Buffer Sharing, & GLES Bridge
// File: fastcv_gpu_context.h
// Description: FastCV GPU acceleration context, OpenGLES / Vulkan interop,
//              and AOT Compute Graph dispatch pipeline.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_GPU_CONTEXT_H_
#define NEXTAI_OPENCUT_FASTCV_GPU_CONTEXT_H_

#include "fastcv_types.h"
#include <string>
#include <functional>

namespace FASTCV {
namespace EXPORTS {

struct AotArgument {
    int type;
    void* data;
    size_t size;
};

class GPUContext {
public:
    int id;
    int flags;
    void* native_device;
    void* native_handle; // offset 0x10
    FASTCVGPUBackend backend;

    GPUContext();
    explicit GPUContext(FASTCVGPUBackend in_backend);
    ~GPUContext() = default;
};

// Opcode 0x62730: getGPUContextStatus
// Returns 5 (INVALID_HANDLE) if ctx is null, or status code from native handle
int getGPUContextStatus(GPUContext* ctx);

// Opcode 0x627b4: loadGLES
bool loadGLES(void (*loader_func)(const char*));

// Opcode 0x627a8: loadGLESLibrary
bool loadGLESLibrary(const char* lib_path);

// Opcode 0x5c040: verifyGLMemShareAvailable
bool verifyGLMemShareAvailable(FASTCVGPUBackend backend);

// Opcode 0x627c4: verifyPixelBufferShareAvailable
bool verifyPixelBufferShareAvailable(FASTCVGPUBackend backend);

// Opcode 0x60164: createGpuMarkerEvent
void* createGpuMarkerEvent(const GPUContext* ctx);

// Opcode 0x6280c: loadAotModule
bool loadAotModule(GPUContext* ctx, const char* aot_path);

// Opcode 0x627c8: launchAotComputeGraph
bool launchAotComputeGraph(const char* graph_name, uint32_t arg_count,
                          const AotArgument* args, void* stream);

// Opcode 0x60f74: setLogCallBack
void setLogCallBack(std::function<void(int, const char*, const char*)> cb);

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_GPU_CONTEXT_H_
