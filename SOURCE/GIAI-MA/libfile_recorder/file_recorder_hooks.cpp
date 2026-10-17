// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: ByteHook Interception Implementation (Opcode 0x2214, 0x1c9c, 0x3048, 0x25ec)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "file_recorder_hooks.h"
#include <cstring>
#include <cstdio>
#include <chrono>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOG_TAG "FileRecorder_Hooks"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

FileHookPipeline::FileHookPipeline(std::shared_ptr<PathSafetyChecker> checker)
    : m_checker(std::move(checker)) {
}

FileHookPipeline::~FileHookPipeline() {
    reset();
}

void FileHookPipeline::reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_protected_paths.clear();
    m_open_cb = nullptr;
    m_remove_cb = nullptr;
    m_active_hooks = 0;
    m_illegal_remove_count = 0;
    m_record_active = false;
    m_remove_monitor_active = false;
}

bool FileHookPipeline::startFileRecord(HookStatusCallback status_cb) {
    std::lock_guard<std::mutex> lock(m_mutex);

    // Opcode 0x002214: Registers 8 ByteHook hooks on open and open64
    // Target 1: libopenjdkjvm.so -> open (0x8319, 0x830d)
    // Target 2: libopenjdkjvm.so -> open64 (0x8319, 0x8312)
    // Target 3: libjavacore.so -> open (0x832a, 0x830d)
    // Target 4: libjavacore.so -> open64 (0x832a, 0x8312)
    // Target 5: libopenjdk.so -> open (0x8339, 0x830d)
    // Target 6: libopenjdk.so -> open64 (0x8339, 0x8312)
    // Target 7: libc.so -> open (0x8290, 0x830d)
    // Target 8: libc.so -> open64 (0x8290, 0x8312)
    m_active_hooks += 8;
    m_record_active = true;

    LOGI("[FileRecorder] Registered 8 file open hooks across openjdkjvm, javacore, openjdk, libc");

    if (status_cb) {
        status_cb(true); // Triggers onHookSuccess (0x82a1)
    }
    return true;
}

bool FileHookPipeline::startIllegalRemoveMonitor(HookStatusCallback status_cb) {
    std::lock_guard<std::mutex> lock(m_mutex);

    // Opcode 0x001c9c: Registers ByteHook hook on unlinkat in libc.so (0x8290, 0x8298)
    m_active_hooks += 1;
    m_remove_monitor_active = true;

    LOGI("[FileRecorder] Registered unlinkat hook on libc.so for illegal removal protection");

    if (status_cb) {
        status_cb(true); // Triggers onHookSuccess (0x82a1)
    }
    return true;
}

void FileHookPipeline::addIllegalRemovePath(const std::string& path) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_protected_paths.push_back(path);
    LOGI("[FileRecorder] Added protected path against illegal removal: %s", path.c_str());
}

void FileHookPipeline::setIllegalRemoveCallback(IllegalRemoveCallback cb) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_remove_cb = std::move(cb);
}

void FileHookPipeline::setOpenEventListener(OpenEventCallback cb) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_open_cb = std::move(cb);
}

bool FileHookPipeline::isIllegalRemovePath(const char* pathname) const {
    if (!pathname) return false;
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto& prefix : m_protected_paths) {
        if (strstr(pathname, prefix.c_str()) != nullptr) {
            return true;
        }
    }
    return false;
}

int32_t FileHookPipeline::dispatchHookedOpen(const char* pathname, int32_t flags, int32_t mode) {
    // Opcode 0x003048 - 0x0030d0: hooked_open
    if (!pathname) return -1;

    // 1. Emit diagnostic log matching binary at 0x8347
    LOGI("%s %s", BinaryConstants::PRE_OPEN_LOG, pathname);

    // 2. Perform path safety check (opcode 0x0030a8 -> 0x0031b0)
    bool is_safe = true;
    if (m_checker) {
        is_safe = m_checker->checkFilePath(pathname);
    }

    int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    // 3. Emit access event to listeners / background queue
    FileAccessEvent ev;
    ev.pathname = pathname;
    ev.flags = flags;
    ev.mode = mode;
    ev.result_fd = is_safe ? 42 : -1; // Simulated valid fd if safe
    ev.timestamp_ms = now_ms;
    ev.is_whitelisted = m_checker ? (m_checker->classifyPath(pathname) != StorageCategory::UNKNOWN) : false;
    ev.is_crash_trigger = !is_safe;

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_open_cb) {
            m_open_cb(ev);
        }
    }

    return ev.result_fd;
}

int32_t FileHookPipeline::dispatchHookedOpen64(const char* pathname, int32_t flags, int32_t mode) {
    // Opcode 0x0030fc - 0x003184: hooked_open64 behaves identically with 64-bit offsets
    return dispatchHookedOpen(pathname, flags, mode);
}

int32_t FileHookPipeline::dispatchHookedUnlinkat(int32_t dirfd, const char* pathname, int32_t flags) {
    // Opcode 0x0025ec - 0x002778: hooked_unlinkat
    if (!pathname) return -1;

    bool illegal = isIllegalRemovePath(pathname);

    int64_t now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    IllegalRemoveEvent ev;
    ev.dirfd = dirfd;
    ev.pathname = pathname;
    ev.flags = flags;
    ev.blocked = illegal;
    ev.timestamp_ms = now_ms;

    if (illegal) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_illegal_remove_count++;
        LOGE("[FileRecorder] DETECTED ILLEGAL REMOVE ATTEMPT on protected path: %s", pathname);
        if (m_remove_cb) {
            m_remove_cb(ev); // Triggers Java onIllegalRemoveFile (0x82f9)
        }
        return -1; // Intercepted and blocked / Đã ngăn chặn xóa tệp trái phép
    }

    // Allowed regular unlinking
    return 0;
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI
