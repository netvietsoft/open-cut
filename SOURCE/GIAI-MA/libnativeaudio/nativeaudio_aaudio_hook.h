// ======================================================================
// RECONSTRUCTED C++ AAUDIO HOOK HEADER: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: AAudio Dynamic Loading & Stream Direction Interception
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
// EN: AAudioMonitor Class
// VN: Lớp AAudioMonitor (Nạp động libaaudio.so và đánh chặn hướng dòng stream)
// ======================================================================
class AAudioMonitor {
private:
    std::mutex m_mutex;
    bool m_is_hooked{false};
    void* m_aaudio_handle{nullptr};
    StreamEventCallback m_callback;
    ProcCommReader m_comm_reader;
    std::unordered_map<AAudioStream*, AudioStreamEventInfo> m_active_streams;
    int32_t m_next_stream_id{2000};

    // Dynamic symbol pointers matching offsets 0x10198, 0x101a0, 0x101a8
    AAudioStreamBuilder_openStream_fn m_fn_openStream{nullptr};
    AAudioStream_close_fn            m_fn_close{nullptr};
    AAudioStream_getDirection_fn     m_fn_getDirection{nullptr};

public:
    AAudioMonitor();
    ~AAudioMonitor();

    // EN: Set stream event callback
    // VN: Gán hàm lắng nghe sự kiện luồng AAudio
    void setEventCallback(StreamEventCallback cb);

    // Mangled: hook_aaudio at 0x3c64 (160 bytes)
    // EN: Dynamically load libaaudio.so, resolve symbols and install proxies
    // VN: Nạp động libaaudio.so, phân giải ký hiệu và cài đặt proxy
    bool installHook();

    // EN: Teardown proxies and unload libaaudio.so
    // VN: Hủy proxy và giải phóng thư viện libaaudio.so
    void uninstallHook();

    // Hook Proxy handler for AAudioStreamBuilder_openStream (Disassembly 0x3d38)
    aaudio_result_t onProxyOpenStream(AAudioStreamBuilder* builder, AAudioStream** stream);

    // Hook Proxy handler for AAudioStream_close (Disassembly 0x3ddc)
    aaudio_result_t onProxyClose(AAudioStream* stream);

    inline bool isHooked() const noexcept { return m_is_hooked; }
    inline size_t getActiveStreamCount() const noexcept { return m_active_streams.size(); }
};

} // namespace com::bytedance::helios::nativeaudio
