// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Path Safety Checker & Crash Interceptor (Opcode 0x31b0)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_CHECKER_H
#define NEXTAI_OPENCUT_FILE_RECORDER_CHECKER_H

#include "file_recorder_types.h"
#include <string>
#include <mutex>
#include <functional>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief Path Safety Checker & Crash Interceptor.
 * Bộ kiểm tra an toàn đường dẫn và đánh chặn sự cố tệp.
 * 
 * Reconstructed from libfile_recorder.so functions:
 * - 0x0031b0: check_file_path (whitelisting & crash detection)
 * - 0x0024c8: nativeUpdateFileCheckParams
 */
class PathSafetyChecker {
public:
    PathSafetyChecker();
    ~PathSafetyChecker() = default;

    /**
     * @brief Update dynamic sensitive check parameters (opcode 0x0024c8).
     * Cập nhật tham số kiểm tra nhạy cảm động.
     * 
     * @param param1 First sensitive substring pattern (stored at 0x10138)
     * @param param2 Second sensitive substring pattern (stored at 0x10140)
     */
    void updateCheckParams(const std::string& param1, const std::string& param2);

    /**
     * @brief Core path inspection algorithm (opcode 0x0031b0).
     * Thuật toán kiểm tra đường dẫn cốt lõi.
     * 
     * 1. Inspects if pathname contains whitelisted directories:
     *    - "/shared_prefs/" (offset 0x8452)
     *    - "/keva/" (offset 0x8461)
     *    - "/databases/" (offset 0x8468)
     *    - ".db.lck" (offset 0x8474)
     *    If whitelisted, returns true (safe to proceed).
     * 
     * 2. If not whitelisted, tests against check_param_char1 and check_param_char2.
     *    If matched, raises fatal crash alert:
     *    - Logs "Crash checkParamChar1: %s"
     *    - Logs "Crash checkParamChar2: %s"
     *    - Formats contact message: "------------Crash happened with pathname is %s,please contact @chenliguan---------"
     *    - Repeatedly logs "Fatal CRASH" banner 30 times
     * 
     * @param pathname File path to inspect
     * @return true if path is safe to proceed; false if intercepted or triggered crash
     */
    bool checkFilePath(const char* pathname);

    /**
     * @brief Check if a path matches any recognized storage categories.
     * Kiểm tra xem đường dẫn có khớp với danh mục lưu trữ nào không.
     */
    StorageCategory classifyPath(const char* pathname) const;

    /**
     * @brief Configure mock crash callback for non-destructive unit testing.
     * Cấu hình callback giả lập sự cố cho kiểm thử tự động không làm gián đoạn tiến trình.
     */
    void setCrashHandler(std::function<void(const std::string& msg)> handler) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_crash_handler = handler;
    }

    /**
     * @brief Retrieve crash count recorded during test session.
     * Lấy số lần phát hiện sự cố trong phiên kiểm thử.
     */
    size_t getCrashCount() const { return m_crash_count; }

    /**
     * @brief Retrieve last formatted crash message.
     * Lấy thông điệp sự cố được định dạng gần nhất.
     */
    std::string getLastCrashMessage() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_last_crash_msg;
    }

    /**
     * @brief Reset checker internal state.
     * Đặt lại trạng thái nội bộ của bộ kiểm tra.
     */
    void reset();

private:
    mutable std::mutex m_mutex;
    std::string m_check_param1; ///< checkParamChar1 (0x10138)
    std::string m_check_param2; ///< checkParamChar2 (0x10140)
    std::string m_last_crash_msg;
    size_t m_crash_count{0};
    std::function<void(const std::string&)> m_crash_handler;
};

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_CHECKER_H
