// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: JNI Bridge & Method Registration Implementation (Opcode 0x1bdc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "file_recorder_jni.h"
#include <cstdio>
#include <iostream>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOG_TAG "FileRecorder_JNI"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

JniFileRecorderBridge& JniFileRecorderBridge::getInstance() {
    static JniFileRecorderBridge s_instance;
    return s_instance;
}

void JniFileRecorderBridge::initialize(std::shared_ptr<PathSafetyChecker> checker,
                                      std::shared_ptr<FileHookPipeline> pipeline,
                                      std::shared_ptr<StorageWorkerEngine> worker) {
    m_checker = std::move(checker);
    m_pipeline = std::move(pipeline);
    m_worker = std::move(worker);
    m_initialized = true;
    LOGI("[FileRecorder_JNI] Initialized JNI bridge components");
}

const std::vector<JNINativeMethod>& JniFileRecorderBridge::getRegisteredMethods() {
    // 10 JNINativeMethods matching libfile_recorder.so relocation table at 0x10000
    static const std::vector<JNINativeMethod> s_methods = {
        // [0] 0x80df -> nativeStartIllegalRemoveMonitor, (Lcom/bytedance/osfix/disk/jni/IHookCallback;)V, fn_ptr = 0x1c9c
        {"nativeStartIllegalRemoveMonitor", "(Lcom/bytedance/osfix/disk/jni/IHookCallback;)V", (void*)0x1c9c},
        // [1] 0x812f -> nativeIsFileInUse, (Ljava/lang/String;)Z, fn_ptr = 0x1d5c
        {"nativeIsFileInUse", "(Ljava/lang/String;)Z", (void*)0x1d5c},
        // [2] 0x8157 -> nativeModifyTime, (Ljava/lang/String;)V, fn_ptr = 0x1e1c
        {"nativeModifyTime", "(Ljava/lang/String;)V", (void*)0x1e1c},
        // [3] 0x817e -> nativeRootPath, (Ljava/util/List;)V, fn_ptr = 0x1ecc
        {"nativeRootPath", "(Ljava/util/List;)V", (void*)0x1ecc},
        // [4] 0x81a1 -> nativeRootLevel, (Ljava/util/List;)V, fn_ptr = 0x1f98
        {"nativeRootLevel", "(Ljava/util/List;)V", (void*)0x1f98},
        // [5] 0x81b1 -> nativeTimeForCount, (J)V, fn_ptr = 0x2064
        {"nativeTimeForCount", "(J)V", (void*)0x2064},
        // [6] 0x81c9 -> nativeIllegalRemovePath, (Ljava/util/List;)V, fn_ptr = 0x20c4
        {"nativeIllegalRemovePath", "(Ljava/util/List;)V", (void*)0x20c4},
        // [7] 0x81e1 -> nativeIllegalRemoveCallback, (Lcom/bytedance/osfix/disk/IIllegalRemoveFileCallback;)V, fn_ptr = 0x2190
        {"nativeIllegalRemoveCallback", "(Lcom/bytedance/osfix/disk/IIllegalRemoveFileCallback;)V", (void*)0x2190},
        // [8] 0x8236 -> nativeStartFileRecord, (Lcom/bytedance/osfix/disk/jni/IHookCallback;)V, fn_ptr = 0x2214
        {"nativeStartFileRecord", "(Lcom/bytedance/osfix/disk/jni/IHookCallback;)V", (void*)0x2214},
        // [9] 0x824c -> nativeUpdateFileCheckParams, (Ljava/lang/String;Ljava/lang/String;)V, fn_ptr = 0x24c8
        {"nativeUpdateFileCheckParams", "(Ljava/lang/String;Ljava/lang/String;)V", (void*)0x24c8}
    };
    return s_methods;
}

int32_t JniFileRecorderBridge::simulateJNIOnLoad() {
    // Opcode 0x001bdc - 0x001c94:
    // Finds class "com/bytedance/osfix/disk/jni/JniNative" (0x80b8)
    // Calls env->RegisterNatives(clazz, methods, 10)
    // Returns 0x10006 (JNI_VERSION_1_6)
    LOGI("[FileRecorder_JNI] JNI_OnLoad called for %s, registering %zu native methods",
         BinaryConstants::JNI_CLASS_NAME, getRegisteredMethods().size());
    return BinaryConstants::JNI_VERSION_1_6;
}

void JniFileRecorderBridge::nativeStartIllegalRemoveMonitor() {
    if (m_pipeline) {
        m_pipeline->startIllegalRemoveMonitor();
    }
}

bool JniFileRecorderBridge::nativeIsFileInUse(const std::string& path) {
    if (m_worker) {
        return m_worker->isFileInUse(path);
    }
    return false;
}

void JniFileRecorderBridge::nativeModifyTime(const std::string& path) {
    if (m_worker) {
        m_worker->modifyTime(path);
    }
}

void JniFileRecorderBridge::nativeRootPath(const std::vector<std::string>& paths) {
    if (m_worker) {
        m_worker->setRootPaths(paths);
    }
}

void JniFileRecorderBridge::nativeRootLevel(const std::vector<int32_t>& levels) {
    if (m_worker) {
        m_worker->setRootLevels(levels);
    }
}

void JniFileRecorderBridge::nativeTimeForCount(int64_t interval_ms) {
    if (m_worker) {
        m_worker->setTimeForCount(interval_ms);
    }
}

void JniFileRecorderBridge::nativeIllegalRemovePath(const std::vector<std::string>& paths) {
    if (m_pipeline) {
        for (const auto& p : paths) {
            m_pipeline->addIllegalRemovePath(p);
        }
    }
}

void JniFileRecorderBridge::nativeIllegalRemoveCallback() {
    LOGI("[FileRecorder_JNI] nativeIllegalRemoveCallback registered");
}

void JniFileRecorderBridge::nativeStartFileRecord() {
    if (m_pipeline) {
        m_pipeline->startFileRecord();
    }
    if (m_worker) {
        m_worker->start();
    }
}

void JniFileRecorderBridge::nativeUpdateFileCheckParams(const std::string& param1, const std::string& param2) {
    if (m_checker) {
        m_checker->updateCheckParams(param1, param2);
    }
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI
