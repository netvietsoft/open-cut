// ======================================================================
// RECONSTRUCTED C++ OPENSLES HOOK HEADER: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: OpenSL ES Interception, Audio Recording & Privacy Auditing
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Logic matching Disassembly
// ======================================================================

#pragma once

#include "nativeaudio_types.h"
#include "nativeaudio_proc_comm.h"
#include <mutex>
#include <functional>
#include <unordered_map>

namespace com::bytedance::helios::nativeaudio {

// Callback type for audio monitoring events
using StreamEventCallback = std::function<void(const AudioStreamEventInfo& event, bool is_opened)>;

// ======================================================================
// EN: OpenSLESMonitor Class
// VN: Lớp OpenSLESMonitor (Giám sát và bẫy gọi API OpenSL ES)
// ======================================================================
class OpenSLESMonitor {
private:
    std::mutex m_mutex;
    bool m_is_hooked{false};
    StreamEventCallback m_callback;
    ProcCommReader m_comm_reader;
    std::unordered_map<void*, AudioStreamEventInfo> m_active_streams;
    int32_t m_next_stream_id{1000};

    // Stored original function pointer
    void* m_original_slCreateEngine{nullptr};

public:
    OpenSLESMonitor();
    ~OpenSLESMonitor();

    // EN: Set stream event callback
    // VN: Đăng ký hàm lắng nghe sự kiện luồng âm thanh
    void setEventCallback(StreamEventCallback cb);

    // Mangled: hook_opensles at 0x3fcc (160 bytes)
    // EN: Hook slCreateEngine via ByteHook PLT/GOT interception
    // VN: Đặt hook vào slCreateEngine qua cơ chế can thiệp ByteHook
    bool installHook();

    // EN: Remove hook and restore original PLT entry
    // VN: Gỡ bỏ hook và khôi phục hàm gốc
    void uninstallHook();

    // Hook Proxy handler for slCreateEngine (Disassembly 0x3f68)
    SLresult onProxyCreateEngine(SLObjectItf* pEngine,
                                uint32_t numOptions,
                                const void* pEngineOptions,
                                uint32_t numInterfaces,
                                const SLInterfaceID* pInterfaceIDs,
                                const uint32_t* pInterfaceRequired);

    // Stream lifecycle notifications
    void notifyStreamOpened(void* handle, AudioDirection direction, int32_t sample_rate, int32_t channels);
    void notifyStreamClosed(void* handle);

    inline bool isHooked() const noexcept { return m_is_hooked; }
    inline size_t getActiveStreamCount() const noexcept { return m_active_streams.size(); }
};

} // namespace com::bytedance::helios::nativeaudio
