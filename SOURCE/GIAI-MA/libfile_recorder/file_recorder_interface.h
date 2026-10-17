// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Master Cleanroom Engine & Verification Interface
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_INTERFACE_H
#define NEXTAI_OPENCUT_FILE_RECORDER_INTERFACE_H

#include "file_recorder_types.h"
#include "file_recorder_checker.h"
#include "file_recorder_hooks.h"
#include "file_recorder_worker.h"
#include "file_recorder_jni.h"
#include <memory>
#include <string>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief Self-test execution result report.
 * Báo cáo kết quả thực thi chuỗi tự kiểm tra.
 */
struct SelfTestResult {
    bool passed{false};
    size_t tests_run{0};
    size_t tests_passed{0};
    std::string summary;
    std::vector<std::string> stage_details;
};

/**
 * @brief Master Cleanroom File Recorder Engine.
 * Động cơ lưu trữ & giám sát tệp tin sạch OpenCut.
 */
class FileRecorderEngine {
public:
    FileRecorderEngine();
    ~FileRecorderEngine();

    /**
     * @brief Initialize all subsystem components.
     * Khởi tạo toàn bộ các thành phần phân hệ con.
     */
    bool initialize();

    /**
     * @brief Access subsystem components.
     */
    std::shared_ptr<PathSafetyChecker> getChecker() const { return m_checker; }
    std::shared_ptr<FileHookPipeline> getPipeline() const { return m_pipeline; }
    std::shared_ptr<StorageWorkerEngine> getWorker() const { return m_worker; }

    /**
     * @brief Run 7-stage comprehensive self-test suite.
     * Chạy chuỗi tự kiểm thử toàn diện 7 giai đoạn.
     */
    SelfTestResult runSelfTest();

    /**
     * @brief Reset all subsystems.
     */
    void reset();

private:
    std::shared_ptr<PathSafetyChecker> m_checker;
    std::shared_ptr<FileHookPipeline> m_pipeline;
    std::shared_ptr<StorageWorkerEngine> m_worker;
    bool m_initialized{false};
};

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_INTERFACE_H
