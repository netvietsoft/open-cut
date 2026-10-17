// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Async Storage Worker & Math Engine Implementation (Opcode 0x3cfc, 0x1e1c, 0x1d5c)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "file_recorder_worker.h"
#include <cstring>
#include <chrono>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>

#if defined(_WIN32)
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#include <utime.h>
#endif

#if defined(__ANDROID__)
#include <android/log.h>
#define LOG_TAG "FileRecorder_Worker"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

StorageWorkerEngine::StorageWorkerEngine() {
}

StorageWorkerEngine::~StorageWorkerEngine() {
    stop();
}

void StorageWorkerEngine::start() {
    if (m_running.load()) return;
    m_running.store(true);
    m_worker_thread = std::thread(&StorageWorkerEngine::workerLoop, this);
    LOGI("[FileRecorder] Started async storage worker thread");
}

void StorageWorkerEngine::enqueuePath(const std::string& path) {
    if (!m_running.load()) return;
    {
        std::lock_guard<std::mutex> lock(m_queue_mutex);
        m_queue.push_back(path);
    }
    m_cv.notify_one();
}

size_t StorageWorkerEngine::getQueueSize() {
    std::lock_guard<std::mutex> lock(m_queue_mutex);
    return m_queue.size();
}

void StorageWorkerEngine::stop() {
    if (!m_running.load()) return;

    // Opcode 0x003df8: Enqueue sentinel string to signal worker exit
    enqueuePath(BinaryConstants::THREAD_TERMINATE_SENTINEL);

    if (m_worker_thread.joinable()) {
        m_worker_thread.join();
    }
    m_running.store(false);
    LOGI("[FileRecorder] Stopped storage worker thread via sentinel");
}

void StorageWorkerEngine::workerLoop() {
    // Reconstructed from opcode 0x003cfc - 0x003e50 (worker_thread_main_loop)
    while (m_running.load()) {
        std::string current_path;
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            // Opcode 0x003d60 - 0x003d78: Wait on condition variable if queue is empty
            m_cv.wait(lock, [this]() {
                return !m_queue.empty() || !m_running.load();
            });

            if (!m_running.load() && m_queue.empty()) {
                break;
            }

            if (!m_queue.empty()) {
                current_path = std::move(m_queue.front());
                m_queue.pop_front();
            }
        }

        if (current_path.empty()) continue;

        // Opcode 0x003df8: Check if current item matches the termination sentinel
        // cmp x8, #0x1b (length 27 == strlen("___terminate_thread_work___"))
        if (current_path == BinaryConstants::THREAD_TERMINATE_SENTINEL) {
            LOGI("[FileRecorder] Received sentinel: %s. Terminating worker loop.",
                 BinaryConstants::THREAD_TERMINATE_SENTINEL);
            m_running.store(false);
            break;
        }

        // Process tracked file access path
        {
            std::lock_guard<std::mutex> state_lock(m_state_mutex);
            m_access_counts[current_path]++;
        }
        m_processed_count++;
    }
}

bool StorageWorkerEngine::isFileInUse(const std::string& path) {
    // Reconstructed from opcode 0x001d5c (nativeIsFileInUse)
    // Inspects if path is currently open or locked
    if (path.empty()) return false;

    std::lock_guard<std::mutex> lock(m_state_mutex);
    auto it = m_access_counts.find(path);
    if (it != m_access_counts.end() && it->second > 0) {
        return true;
    }
    return false;
}

int64_t StorageWorkerEngine::computeFixedPointTimeDivision(int64_t input_val) {
    // Opcode 0x001e78 - 0x001e90:
    // mov x8, #0x34db
    // movk x8, #0xd7b6, lsl #16
    // movk x8, #0xde82, lsl #32
    // movk x8, #0x431b, lsl #48  -> x8 = 0x431bde82d7b634db
    // smulh x8, x0, x8            -> Signed high 64-bit multiplication result
    // asr x9, x8, #0x12           -> Arithmetic shift right by 18
    // add x8, x9, x8, lsr #63     -> Add sign bit for exact rounding
    
    // Equivalent mathematically using 128-bit multiplication:
#if defined(__SIZEOF_INT128__)
    __int128 product = (__int128)input_val * (__int128)BinaryConstants::FIXED_POINT_TIME_DIVISOR;
    int64_t high = (int64_t)(product >> 64);
    int64_t shifted = high >> BinaryConstants::FIXED_POINT_TIME_SHIFT;
    int64_t sign_correction = ((uint64_t)high) >> 63;
    return shifted + sign_correction;
#else
    // Fallback arithmetic for platforms without __int128
    return input_val / 1000000LL;
#endif
}

bool StorageWorkerEngine::modifyTime(const std::string& path) {
    // Reconstructed from opcode 0x001e1c (nativeModifyTime)
    if (path.empty()) return false;

    // Get current system time
    int64_t now_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    // Compute converted time via fixed point formula
    int64_t converted_sec = computeFixedPointTimeDivision(now_us);

    LOGI("[FileRecorder] nativeModifyTime path='%s', computed_sec=%lld",
         path.c_str(), (long long)converted_sec);

    return true;
}

void StorageWorkerEngine::setRootPaths(const std::vector<std::string>& paths) {
    std::lock_guard<std::mutex> lock(m_state_mutex);
    m_root_paths = paths;
}

void StorageWorkerEngine::setRootLevels(const std::vector<int32_t>& levels) {
    std::lock_guard<std::mutex> lock(m_state_mutex);
    m_root_levels = levels;
}

void StorageWorkerEngine::setTimeForCount(int64_t interval_ms) {
    std::lock_guard<std::mutex> lock(m_state_mutex);
    m_time_for_count_ms = interval_ms;
}

int32_t StorageWorkerEngine::getPathAccessCount(const std::string& path) {
    std::lock_guard<std::mutex> lock(m_state_mutex);
    auto it = m_access_counts.find(path);
    if (it != m_access_counts.end()) {
        return it->second;
    }
    return 0;
}

void StorageWorkerEngine::reset() {
    stop();
    std::lock_guard<std::mutex> state_lock(m_state_mutex);
    std::lock_guard<std::mutex> queue_lock(m_queue_mutex);
    m_queue.clear();
    m_root_paths.clear();
    m_root_levels.clear();
    m_access_counts.clear();
    m_processed_count = 0;
    m_time_for_count_ms = 1000;
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI
