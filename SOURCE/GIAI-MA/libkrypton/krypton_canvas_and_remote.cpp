// ============================================================================
// Clean-Room C++17 CanvasApp, ResourceProvider & RemoteBridge for libkrypton.so
// Hiện thực C++17 sạch CanvasApp, ResourceProvider & RemoteBridge cho libkrypton.so
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

CanvasResourceProvider::CanvasResourceProvider(CanvasSize size, float density, bool anti_alias)
    : size_(size), density_(density), anti_alias_(anti_alias), frame_count_(0) {}

uint32_t CanvasResourceProvider::FlushFrame() {
    return ++frame_count_;
}

CanvasApp::CanvasApp() = default;
CanvasApp::~CanvasApp() = default;

// Reconstructed from 0x0ace64..0x0acfc8 (CanvasApp::OnRuntimeAttach)
// Tái dựng từ 0x0ace64..0x0acfc8 (CanvasApp::OnRuntimeAttach)
void CanvasApp::OnRuntimeAttach(void* js_runtime, bool enable_gpu_task_runner) {
    js_runtime_ = js_runtime;
    gpu_task_runner_enabled_ = enable_gpu_task_runner;
    attached_ = true;
}

void CanvasApp::OnRuntimeDetach() {
    attached_ = false;
    js_runtime_ = nullptr;
}

namespace remote {

bool RemoteBridge::DispatchCommand(uint32_t cmd_id, const DataHolder& payload) {
    (void)cmd_id;
    if (payload.Size() == 0 && payload.Data() == nullptr) {
        return false;
    }
    ++processed_count_;
    return true;
}

std::vector<std::string>& RemoteEnvImpl::GetRegisteredModules() {
    static std::vector<std::string> s_modules;
    return s_modules;
}

void RemoteEnvImpl::RegisterModule(const std::string& name) {
    GetRegisteredModules().push_back(name);
}

} // namespace remote

} // namespace canvas
} // namespace lynx
