// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Path Safety Checker & Crash Interceptor Implementation (Opcode 0x31b0)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "file_recorder_checker.h"
#include <cstring>
#include <cstdio>
#include <iostream>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOG_TAG "FileRecorder_Checker"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

PathSafetyChecker::PathSafetyChecker() {
    reset();
}

void PathSafetyChecker::reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_check_param1.clear();
    m_check_param2.clear();
    m_last_crash_msg.clear();
    m_crash_count = 0;
}

void PathSafetyChecker::updateCheckParams(const std::string& param1, const std::string& param2) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_check_param1 = param1;
    m_check_param2 = param2;
    LOGI("[FileRecorder] Check params updated: param1='%s', param2='%s'", 
         m_check_param1.c_str(), m_check_param2.c_str());
}

StorageCategory PathSafetyChecker::classifyPath(const char* pathname) const {
    if (!pathname) return StorageCategory::UNKNOWN;

    // Check for standard ByteDance / Android storage locations
    if (strstr(pathname, BinaryConstants::PATTERN_SHARED_PREFS) != nullptr) {
        return StorageCategory::SHARED_PREFS;
    }
    if (strstr(pathname, BinaryConstants::PATTERN_KEVA) != nullptr) {
        return StorageCategory::KEVA_KV;
    }
    if (strstr(pathname, BinaryConstants::PATTERN_DATABASES) != nullptr) {
        return StorageCategory::DATABASES;
    }
    if (strstr(pathname, BinaryConstants::PATTERN_DB_LOCK) != nullptr) {
        return StorageCategory::DB_LOCK;
    }
    return StorageCategory::UNKNOWN;
}

bool PathSafetyChecker::checkFilePath(const char* pathname) {
    if (!pathname) return false;

    // Opcode 0x0031dc - 0x00321c: Whitelist pattern inspection via strstr
    // 1. Check "/shared_prefs/" (offset 0x8452)
    if (strstr(pathname, BinaryConstants::PATTERN_SHARED_PREFS) != nullptr) {
        return true; // Whitelisted, safe / Được miễn trừ an toàn
    }

    // 2. Check "/keva/" (offset 0x8461)
    if (strstr(pathname, BinaryConstants::PATTERN_KEVA) != nullptr) {
        return true; // Whitelisted, safe / Được miễn trừ an toàn
    }

    // 3. Check "/databases/" (offset 0x8468)
    if (strstr(pathname, BinaryConstants::PATTERN_DATABASES) != nullptr) {
        return true; // Whitelisted, safe / Được miễn trừ an toàn
    }

    // 4. Check ".db.lck" (offset 0x8474)
    if (strstr(pathname, BinaryConstants::PATTERN_DB_LOCK) != nullptr) {
        return true; // Whitelisted, safe / Được miễn trừ an toàn
    }

    // Opcode 0x003244 - 0x003274: Check against dynamic sensitive parameters
    std::string p1, p2;
    std::function<void(const std::string&)> custom_handler;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        p1 = m_check_param1;
        p2 = m_check_param2;
        custom_handler = m_crash_handler;
    }

    bool crash_triggered = false;
    if (!p1.empty() && strstr(pathname, p1.c_str()) != nullptr) {
        crash_triggered = true;
    } else if (!p2.empty() && strstr(pathname, p2.c_str()) != nullptr) {
        crash_triggered = true;
    }

    if (crash_triggered) {
        // Opcode 0x003278 - 0x0033c4: Crash reporting & alert emission
        char crash_buffer[1024];
        snprintf(crash_buffer, sizeof(crash_buffer),
                 BinaryConstants::CRASH_MSG_FORMAT, pathname);

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_last_crash_msg = crash_buffer;
            m_crash_count++;
        }

        // Emit diagnostic logs matching binary
        LOGE("%s: %s", BinaryConstants::CRASH_CHECK_PARAM1, p1.c_str());
        LOGE("%s: %s", BinaryConstants::CRASH_CHECK_PARAM2, p2.c_str());
        LOGE("%s", crash_buffer);

        // Opcode 0x00335c - 0x00338c: Loop 30 times (w22 = 0x1e) logging Fatal CRASH banner
        for (int i = 0; i < 30; ++i) {
            LOGE("%s", BinaryConstants::CRASH_BANNER_FATAL);
        }
        LOGE("Crash");

        // Invoke custom handler if configured (e.g., during tests), otherwise simulate abort
        if (custom_handler) {
            custom_handler(crash_buffer);
        }
        return false; // Intercepted
    }

    return true; // Safe to proceed
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI
