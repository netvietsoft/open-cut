// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Master Cleanroom Engine & 7-Stage Self-Test Implementation
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "file_recorder_interface.h"
#include <iostream>
#include <sstream>
#include <cassert>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

FileRecorderEngine::FileRecorderEngine() {
    initialize();
}

FileRecorderEngine::~FileRecorderEngine() {
    reset();
}

bool FileRecorderEngine::initialize() {
    if (m_initialized) return true;

    m_checker = std::make_shared<PathSafetyChecker>();
    m_pipeline = std::make_shared<FileHookPipeline>(m_checker);
    m_worker = std::make_shared<StorageWorkerEngine>();

    JniFileRecorderBridge::getInstance().initialize(m_checker, m_pipeline, m_worker);

    // Link hook open events to asynchronous worker queue
    m_pipeline->setOpenEventListener([this](const FileAccessEvent& ev) {
        if (m_worker && !ev.is_crash_trigger) {
            m_worker->enqueuePath(ev.pathname);
        }
    });

    m_initialized = true;
    return true;
}

void FileRecorderEngine::reset() {
    if (m_worker) m_worker->reset();
    if (m_pipeline) m_pipeline->reset();
    if (m_checker) m_checker->reset();
    m_initialized = false;
}

SelfTestResult FileRecorderEngine::runSelfTest() {
    SelfTestResult result;
    result.tests_run = 0;
    result.tests_passed = 0;

    auto record_stage = [&](const std::string& name, bool pass, const std::string& msg) {
        result.tests_run++;
        if (pass) result.tests_passed++;
        std::stringstream ss;
        ss << "[" << (pass ? "PASS" : "FAIL") << "] " << name << ": " << msg;
        result.stage_details.push_back(ss.str());
    };

    // --------------------------------------------------------------------------
    // Stage 1: JNI Table & Symbol Registration Verification (Opcode 0x1bdc)
    // --------------------------------------------------------------------------
    {
        int32_t jni_ver = JniFileRecorderBridge::getInstance().simulateJNIOnLoad();
        const auto& methods = JniFileRecorderBridge::getRegisteredMethods();

        bool pass = (jni_ver == BinaryConstants::JNI_VERSION_1_6) && (methods.size() == 10);
        pass = pass && (methods[0].name == std::string("nativeStartIllegalRemoveMonitor"));
        pass = pass && (methods[1].name == std::string("nativeIsFileInUse"));
        pass = pass && (methods[8].name == std::string("nativeStartFileRecord"));
        pass = pass && (methods[9].name == std::string("nativeUpdateFileCheckParams"));

        record_stage("Stage 1 - JNI Registry", pass,
                     "Verified JNI_VERSION_1_6 (0x10006) and 10 JNINativeMethods on " + 
                     std::string(BinaryConstants::JNI_CLASS_NAME));
    }

    // --------------------------------------------------------------------------
    // Stage 2: Storage Classification & Whitelist Check (Opcode 0x31b0)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        // Test whitelisted paths
        const char* p_prefs = "/data/user/0/com.lemon.lv/shared_prefs/user_config.xml";
        const char* p_keva = "/data/user/0/com.lemon.lv/keva/repo_kv.bin";
        const char* p_db = "/data/user/0/com.lemon.lv/databases/drafts.db";
        const char* p_lock = "/data/user/0/com.lemon.lv/databases/drafts.db.lck";

        pass = pass && (m_checker->classifyPath(p_prefs) == StorageCategory::SHARED_PREFS);
        pass = pass && (m_checker->classifyPath(p_keva) == StorageCategory::KEVA_KV);
        pass = pass && (m_checker->classifyPath(p_db) == StorageCategory::DATABASES);
        pass = pass && (m_checker->classifyPath(p_lock) == StorageCategory::DB_LOCK);

        // checkFilePath must return true (safe) for whitelisted paths
        pass = pass && m_checker->checkFilePath(p_prefs);
        pass = pass && m_checker->checkFilePath(p_keva);
        pass = pass && m_checker->checkFilePath(p_db);
        pass = pass && m_checker->checkFilePath(p_lock);

        record_stage("Stage 2 - Whitelist Filter", pass,
                     "Verified /shared_prefs/, /keva/, /databases/, and .db.lck exemptions");
    }

    // --------------------------------------------------------------------------
    // Stage 3: Crash Parameter Detection & Contact Message Formatting (Opcode 0x24c8, 0x3278)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        std::string captured_msg;
        m_checker->setCrashHandler([&](const std::string& msg) {
            captured_msg = msg;
        });

        // Set sensitive parameters
        m_checker->updateCheckParams("unauthorized_export", "leak_token_dir");

        // Normal path should pass
        pass = pass && m_checker->checkFilePath("/sdcard/Download/video_output.mp4");

        // Sensitive path 1 should trigger crash
        bool safe1 = m_checker->checkFilePath("/sdcard/unauthorized_export/clip.mov");
        pass = pass && !safe1;
        pass = pass && (captured_msg.find("@chenliguan") != std::string::npos);
        pass = pass && (m_checker->getCrashCount() == 1);

        // Sensitive path 2 should trigger crash
        captured_msg.clear();
        bool safe2 = m_checker->checkFilePath("/data/data/com.lemon.lv/leak_token_dir/key.pem");
        pass = pass && !safe2;
        pass = pass && (captured_msg.find("@chenliguan") != std::string::npos);
        pass = pass && (m_checker->getCrashCount() == 2);

        // Clear crash handler
        m_checker->setCrashHandler(nullptr);

        record_stage("Stage 3 - Crash Parameter Check", pass,
                     "Verified checkParamChar1/2 match, 30x fatal banner emission & @chenliguan format");
    }

    // --------------------------------------------------------------------------
    // Stage 4: ByteHook Open/Open64 Interception (Opcode 0x2214, 0x3048, 0x30fc)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        bool hook_cb_fired = false;
        m_pipeline->startFileRecord([&](bool success) {
            hook_cb_fired = success;
        });

        pass = pass && hook_cb_fired;
        pass = pass && (m_pipeline->getActiveHookCount() >= 8);

        // Dispatch simulated hooked open calls
        int32_t fd1 = m_pipeline->dispatchHookedOpen("/sdcard/DCIM/Camera/VID_001.mp4", 0, 0644);
        int32_t fd2 = m_pipeline->dispatchHookedOpen64("/sdcard/Movies/project_edit.opencut", 0, 0644);

        pass = pass && (fd1 > 0) && (fd2 > 0);

        record_stage("Stage 4 - Hooked Open/Open64", pass,
                     "Verified 8 ByteHook registrations across JVM/Core/NDK and event dispatch");
    }

    // --------------------------------------------------------------------------
    // Stage 5: Illegal Removal Protection on Protected Paths (Opcode 0x1c9c, 0x25ec)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        bool remove_hook_fired = false;
        m_pipeline->startIllegalRemoveMonitor([&](bool success) {
            remove_hook_fired = success;
        });

        // Add protected path
        const std::string protected_dir = "/data/user/0/com.lemon.lv/files/protect_core/";
        m_pipeline->addIllegalRemovePath(protected_dir);

        bool callback_notified = false;
        std::string attempted_path;
        m_pipeline->setIllegalRemoveCallback([&](const IllegalRemoveEvent& ev) {
            callback_notified = true;
            attempted_path = ev.pathname;
        });

        // Unlink on un-protected file should succeed (return 0)
        int32_t res_normal = m_pipeline->dispatchHookedUnlinkat(-100, "/tmp/temp_cache.tmp", 0);
        pass = pass && (res_normal == 0) && !callback_notified;

        // Unlink on protected file should be BLOCKED (return -1) and trigger callback
        std::string target_file = protected_dir + "master_license.key";
        int32_t res_blocked = m_pipeline->dispatchHookedUnlinkat(-100, target_file.c_str(), 0);
        pass = pass && (res_blocked == -1);
        pass = pass && callback_notified;
        pass = pass && (attempted_path == target_file);
        pass = pass && (m_pipeline->getIllegalRemoveInterceptCount() == 1);

        record_stage("Stage 5 - Illegal Remove Guard", pass,
                     "Verified unlinkat interception, protection prefix matching & callback emission");
    }

    // --------------------------------------------------------------------------
    // Stage 6: Thread-Safe Asynchronous Worker Queue & Sentinel (Opcode 0x3cfc, 0x3df8)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        m_worker->start();

        // Enqueue items
        for (int i = 0; i < 20; ++i) {
            m_worker->enqueuePath("/sdcard/DCIM/track_" + std::to_string(i) + ".mp4");
        }

        // Sleep briefly to let worker process
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        pass = pass && (m_worker->getProcessedCount() >= 10);

        // Stop via sentinel
        m_worker->stop();
        pass = pass && (m_worker->getQueueSize() == 0);

        record_stage("Stage 6 - Async Worker Queue", pass,
                     "Verified deque concurrency, condition_variable sync & sentinel termination");
    }

    // --------------------------------------------------------------------------
    // Stage 7: Mathematical Parity of Fixed-Point Time Division (Opcode 0x1e78 - 0x1e90)
    // --------------------------------------------------------------------------
    {
        bool pass = true;
        // Test values: 1 second = 1,000,000 us -> expected ~1
        int64_t one_sec_us = 1000000LL;
        int64_t res1 = StorageWorkerEngine::computeFixedPointTimeDivision(one_sec_us);
        pass = pass && (res1 == 1);

        // 123,456,789 us -> expected ~123
        int64_t val2 = 123456789LL;
        int64_t res2 = StorageWorkerEngine::computeFixedPointTimeDivision(val2);
        pass = pass && (res2 == 123);

        // Verify nativeModifyTime call executes cleanly
        pass = pass && m_worker->modifyTime("/sdcard/test_file.mp4");

        record_stage("Stage 7 - Math Constant 0x431bde82d7b634db", pass,
                     "Verified fixed-point 10^-6 division parity with AArch64 smulh + asr #18");
    }

    result.passed = (result.tests_passed == result.tests_run) && (result.tests_run == 7);
    std::stringstream sum;
    sum << "FileRecorderEngine Self-Test: " << result.tests_passed << "/" << result.tests_run << " PASSED";
    result.summary = sum.str();

    return result;
}

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI
