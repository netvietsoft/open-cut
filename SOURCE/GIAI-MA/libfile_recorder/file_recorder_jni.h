// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: JNI Bridge & Method Registration (Opcode 0x1bdc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_JNI_H
#define NEXTAI_OPENCUT_FILE_RECORDER_JNI_H

#include "file_recorder_types.h"
#include "file_recorder_checker.h"
#include "file_recorder_hooks.h"
#include "file_recorder_worker.h"
#include <string>
#include <vector>
#include <memory>

#if defined(__ANDROID__) || defined(HAVE_JNI)
#include <jni.h>
#else
// Standalone JNI definitions for cleanroom compilation & test suites
typedef void* jobject;
typedef void* jclass;
typedef void* jstring;
typedef void* jlong;
typedef int32_t jint;
typedef uint8_t jboolean;

struct JNINativeMethod {
    const char* name;
    const char* signature;
    void* fnPtr;
};
#endif

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief JNI Bridge for ByteDance Storage & File Record Service.
 * Cầu nối JNI cho dịch vụ lưu trữ và ghi nhận truy cập tệp ByteDance.
 * 
 * Class: com.bytedance.osfix.disk.jni.JniNative (0x80b8)
 */
class JniFileRecorderBridge {
public:
    static JniFileRecorderBridge& getInstance();

    void initialize(std::shared_ptr<PathSafetyChecker> checker,
                    std::shared_ptr<FileHookPipeline> pipeline,
                    std::shared_ptr<StorageWorkerEngine> worker);

    /**
     * @brief Get the list of all 10 registered JNINativeMethod descriptors.
     * Lấy danh sách toàn bộ 10 mô tả phương thức JNINativeMethod đã đăng ký.
     */
    static const std::vector<JNINativeMethod>& getRegisteredMethods();

    // Native Method implementations matching AArch64 function pointers
    // 0: nativeStartIllegalRemoveMonitor (0x001c9c)
    void nativeStartIllegalRemoveMonitor();

    // 1: nativeIsFileInUse (0x001d5c)
    bool nativeIsFileInUse(const std::string& path);

    // 2: nativeModifyTime (0x001e1c)
    void nativeModifyTime(const std::string& path);

    // 3: nativeRootPath (0x001ecc)
    void nativeRootPath(const std::vector<std::string>& paths);

    // 4: nativeRootLevel (0x001f98)
    void nativeRootLevel(const std::vector<int32_t>& levels);

    // 5: nativeTimeForCount (0x002064)
    void nativeTimeForCount(int64_t interval_ms);

    // 6: nativeIllegalRemovePath (0x0020c4)
    void nativeIllegalRemovePath(const std::vector<std::string>& paths);

    // 7: nativeIllegalRemoveCallback (0x002190)
    void nativeIllegalRemoveCallback();

    // 8: nativeStartFileRecord (0x002214)
    void nativeStartFileRecord();

    // 9: nativeUpdateFileCheckParams (0x0024c8)
    void nativeUpdateFileCheckParams(const std::string& param1, const std::string& param2);

    /**
     * @brief Simulate JNI_OnLoad (opcode 0x001bdc).
     * Returns 0x10006 (JNI_VERSION_1_6).
     */
    int32_t simulateJNIOnLoad();

private:
    JniFileRecorderBridge() = default;

    std::shared_ptr<PathSafetyChecker> m_checker;
    std::shared_ptr<FileHookPipeline> m_pipeline;
    std::shared_ptr<StorageWorkerEngine> m_worker;
    bool m_initialized{false};
};

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_JNI_H
