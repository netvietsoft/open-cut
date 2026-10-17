// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: ByteHook Interception Pipeline (open, open64, unlinkat)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_HOOKS_H
#define NEXTAI_OPENCUT_FILE_RECORDER_HOOKS_H

#include "file_recorder_types.h"
#include "file_recorder_checker.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <functional>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief ByteHook Interception Manager for File Operations.
 * Quản lý can thiệp ByteHook cho các thao tác tệp tin.
 * 
 * Reconstructed from:
 * - 0x002214: nativeStartFileRecord (registers 8 hooks for open/open64)
 * - 0x001c9c: nativeStartIllegalRemoveMonitor (registers unlinkat hook)
 * - 0x003048: hooked_open replacement
 * - 0x0030fc: hooked_open64 replacement
 * - 0x0025ec: hooked_unlinkat replacement
 * - 0x0020c4: nativeIllegalRemovePath (registers protected paths)
 */
class FileHookPipeline {
public:
    using OpenEventCallback = std::function<void(const FileAccessEvent&)>;
    using IllegalRemoveCallback = std::function<void(const IllegalRemoveEvent&)>;
    using HookStatusCallback = std::function<void(bool success)>;

    FileHookPipeline(std::shared_ptr<PathSafetyChecker> checker);
    ~FileHookPipeline();

    /**
     * @brief Start file recording hooks across open/open64 (opcode 0x002214).
     * Khởi động các hook ghi nhận truy cập tệp trên open và open64.
     * Hooks target libraries:
     * - libopenjdkjvm.so (0x8319)
     * - libjavacore.so (0x832a)
     * - libopenjdk.so (0x8339)
     * - libc.so (0x8290)
     */
    bool startFileRecord(HookStatusCallback status_cb = nullptr);

    /**
     * @brief Start illegal file removal monitor hook on unlinkat (opcode 0x001c9c).
     * Khởi động hook giám sát xóa tệp trái phép trên unlinkat.
     */
    bool startIllegalRemoveMonitor(HookStatusCallback status_cb = nullptr);

    /**
     * @brief Add a path prefix to illegal remove monitoring set (opcode 0x0020c4).
     * Thêm tiền tố đường dẫn vào tập bảo vệ chống xóa trái phép.
     */
    void addIllegalRemovePath(const std::string& path);

    /**
     * @brief Set the callback for illegal remove events (opcode 0x002190).
     * Thiết lập callback khi phát hiện hành vi xóa trái phép.
     */
    void setIllegalRemoveCallback(IllegalRemoveCallback cb);

    /**
     * @brief Set listener for file access open events.
     * Thiết lập listener nhận các sự kiện mở tệp.
     */
    void setOpenEventListener(OpenEventCallback cb);

    /**
     * @brief Simulated replacement for open() (opcode 0x003048).
     * Hàm thay thế mô phỏng cho open().
     */
    int32_t dispatchHookedOpen(const char* pathname, int32_t flags, int32_t mode);

    /**
     * @brief Simulated replacement for open64() (opcode 0x0030fc).
     * Hàm thay thế mô phỏng cho open64().
     */
    int32_t dispatchHookedOpen64(const char* pathname, int32_t flags, int32_t mode);

    /**
     * @brief Simulated replacement for unlinkat() (opcode 0x0025ec).
     * Hàm thay thế mô phỏng cho unlinkat().
     */
    int32_t dispatchHookedUnlinkat(int32_t dirfd, const char* pathname, int32_t flags);

    /**
     * @brief Check whether a path is protected against removal (opcode 0x004744).
     * Kiểm tra xem đường dẫn có được bảo vệ chống xóa hay không.
     */
    bool isIllegalRemovePath(const char* pathname) const;

    /**
     * @brief Query active hook count.
     * Lấy số lượng hook đang hoạt động.
     */
    size_t getActiveHookCount() const { return m_active_hooks; }

    /**
     * @brief Get intercepted illegal remove count.
     * Lấy số lần phát hiện xóa tệp trái phép.
     */
    size_t getIllegalRemoveInterceptCount() const { return m_illegal_remove_count; }

    /**
     * @brief Reset pipeline state.
     * Đặt lại trạng thái pipeline.
     */
    void reset();

private:
    std::shared_ptr<PathSafetyChecker> m_checker;
    mutable std::mutex m_mutex;
    std::vector<std::string> m_protected_paths;
    OpenEventCallback m_open_cb;
    IllegalRemoveCallback m_remove_cb;
    size_t m_active_hooks{0};
    size_t m_illegal_remove_count{0};
    bool m_record_active{false};
    bool m_remove_monitor_active{false};
};

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_HOOKS_H
