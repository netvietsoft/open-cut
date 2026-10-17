// ======================================================================
// RECONSTRUCTED C++ MASTER INTERFACE: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Target Architecture: AArch64 / Android arm64-v8a
// Namespace: NextAI::OpenCut::nativeaudio & com::bytedance::helios::nativeaudio
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Public API & Engine Bridge
// ======================================================================

#pragma once

#include "nativeaudio_types.h"
#include "nativeaudio_proc_comm.h"
#include "nativeaudio_opensles_hook.h"
#include "nativeaudio_aaudio_hook.h"
#include "nativeaudio_jni_bridge.h"
#include <string>
#include <vector>
#include <memory>

namespace NextAI::OpenCut::nativeaudio {

using AudioBackendType = com::bytedance::helios::nativeaudio::AudioBackendType;
using AudioDirection = com::bytedance::helios::nativeaudio::AudioDirection;
using AudioStreamEventInfo = com::bytedance::helios::nativeaudio::AudioStreamEventInfo;
using OpenSLESMonitor = com::bytedance::helios::nativeaudio::OpenSLESMonitor;
using AAudioMonitor = com::bytedance::helios::nativeaudio::AAudioMonitor;
using ProcCommReader = com::bytedance::helios::nativeaudio::ProcCommReader;
using AudioMonitorJNI = com::bytedance::helios::nativeaudio::AudioMonitorJNI;

// ======================================================================
// EN: NativeAudioMonitorEngine Class
// VN: Lớp NativeAudioMonitorEngine (Động cơ giám sát âm thanh hệ thống cho NextAI OpenCut)
// ======================================================================
class NativeAudioMonitorEngine {
private:
    std::unique_ptr<OpenSLESMonitor> m_opensles_monitor;
    std::unique_ptr<AAudioMonitor> m_aaudio_monitor;
    std::unique_ptr<ProcCommReader> m_comm_reader;
    std::vector<AudioStreamEventInfo> m_history_log;
    std::mutex m_engine_mutex;
    bool m_is_running{false};
    bool m_record_only{true};

public:
    NativeAudioMonitorEngine();
    virtual ~NativeAudioMonitorEngine();

    // EN: Start monitoring OpenSL ES and AAudio subsystems
    // VN: Bắt đầu giám sát các phân hệ âm thanh OpenSL ES và AAudio
    bool startMonitoring(bool record_only = true, int32_t flags = 0);

    // EN: Stop monitoring and restore native hooks
    // VN: Dừng giám sát và khôi phục các hàm gốc
    void stopMonitoring();

    // EN: Query whether microphone/audio recording is currently active
    // VN: Kiểm tra xem micro / tiến trình thu âm hiện có đang hoạt động không
    bool isRecordingActive() const noexcept;

    // EN: Get count of active audio streams
    // VN: Lấy số lượng luồng âm thanh đang hoạt động
    size_t getActiveStreamCount() const noexcept;

    // EN: Retrieve audit history of audio stream events
    // VN: Lấy lịch sử kiểm toán các sự kiện luồng âm thanh
    std::vector<AudioStreamEventInfo> getEventHistory() const;

    // EN: Check if a thread name is authorized for audio access
    // VN: Kiểm tra xem tên tiến trình/thread có được phép truy cập âm thanh không
    bool isThreadAuthorized(const std::string& comm_name);

    // EN: Run self-test verification suite
    // VN: Chạy bộ kiểm thử tự kiểm tra nội bộ
    static bool runSelfTest();
};

} // namespace NextAI::OpenCut::nativeaudio
