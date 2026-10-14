// ======================================================================
// RECONSTRUCTED HEADER: pitaya_core.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Top-level PitayaCore singleton: lifecycle orchestration, Setup,
//   Boot, package management, on-device AI model packaging, and
//   safe resource cleanup.
//
// Mô tả (Tiếng Việt):
//   Singleton PitayaCore cấp cao nhất: điều phối vòng đời, Setup,
//   Boot, quản lý gói giải thuật AI on-device và giải phóng tài nguyên.
// ======================================================================

#pragma once

#include "pitaya_types.h"
#include "pitaya_objects.h"
#include "pitaya_kv_store.h"
#include "pitaya_feature_store.h"
#include "pitaya_task_executor.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <mutex>

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// PitayaCore Singleton
// Demangled: pitaya::PitayaCore (Instance at opcode 0xccbc4)
// ----------------------------------------------------------------------
class PitayaCore {
public:
    static PitayaCore& Instance();

    // 1. Kiểm tra trạng thái sẵn sàng (Opcode 0xccd34 & 0xcce20)
    bool IsReady() const noexcept { return is_ready_; }
    bool IsPreloadReady() const noexcept { return is_preload_ready_; }
    bool IsStop() const noexcept { return is_stopped_; }
    std::string GetAid() const { return setup_info_.aid; }

    // 2. Thiết lập khởi tạo cơ bản (Opcode 0xd566c)
    void Setup(const std::shared_ptr<SetupInfo>& setup_info, 
               TaskTracePtr& trace, 
               SetupCallback callback);

    // 3. Khởi động toàn bộ nền tảng Pitaya (Opcode 0xdb1ec)
    void Boot(const std::shared_ptr<SetupInfo>& setup_info, 
              TaskTracePtr& trace, 
              const std::shared_ptr<BootConfig>& boot_config, 
              SetupCallback callback);

    // 4. Thực thi tác vụ AI & Luật (Opcode 0xd9128)
    int32_t RunTask(const std::string& task_name, 
                    const TaskDataPtr& task_data, 
                    const TaskConfigPtr& task_config, 
                    TaskCallback callback, 
                    TaskCallback progress_callback = nullptr, 
                    const TaskTracePtr& trace = nullptr);

    // 5. Quản lý gói thuật toán (Package Management)
    void EnsurePackageReady(const std::string& package_name, double timeout_sec, bool force_update, PackageCallback callback);
    void PreDownloadAllPackage();
    void DownloadPackage(const std::string& package_name, PackageCallback callback);
    void QueryPackage(const std::string& package_name, PackageCallback callback);
    void StopAllDownloadTask();

    // 6. Dọn dẹp & Giải phóng (Opcode 0xd8820 & 0xd8ab0 & 0xdaac8)
    void CleanPitaya(CleanStrategy strategy, SetupCallback callback);
    void StopPitaya(SetupCallback callback);
    void ReleaseEngine(const std::string& engine_name);
    void ReleaseAllEngines();

    // 7. Cổng thông điệp & Socket Debug (Opcode 0xdaaa0 & 0xdaacc)
    void RegisterMessageHandler(const std::string& channel, std::function<PTYDictPtr(const PTYDictPtr&)> handler);
    void RemoveMessageHandler(const std::string& channel);
    void RegisterCustomTaskHandler(const std::string& task_type, TaskCallback handler);
    void RemoveCustomTaskHandler(const std::string& task_type);
    void ConnectSocket(const std::string& host_port, std::function<void(std::string, std::string)> log_cb);

private:
    PitayaCore();
    ~PitayaCore();

    SetupInfo setup_info_;
    BootConfig boot_config_;
    bool is_ready_{false};
    bool is_preload_ready_{false};
    bool is_stopped_{false};

    std::unordered_map<std::string, PackageInfoPtr> packages_;
    std::unordered_map<std::string, std::function<PTYDictPtr(const PTYDictPtr&)>> message_handlers_;
    std::unordered_map<std::string, TaskCallback> custom_task_handlers_;

    mutable std::mutex mutex_;
};

} // namespace NextAI::OpenCut::pitaya
