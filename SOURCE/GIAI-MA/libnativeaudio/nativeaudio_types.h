// ======================================================================
// RECONSTRUCTED C++ TYPES & CORE DEFINITIONS: libnativeaudio.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: Helios Native Audio Privacy & Performance Monitor
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete ABI, Structs & Enums
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <atomic>
#include <functional>
#include <jni.h>

namespace com::bytedance::helios::nativeaudio {

// ======================================================================
// EN: Audio Subsystem Backend Type
// VN: Loại phân hệ âm thanh nền tảng
// ======================================================================
enum class AudioBackendType : int32_t {
    BACKEND_UNKNOWN     = 0,
    BACKEND_OPENSLES    = 1,    // OpenSL ES (libOpenSLES.so)
    BACKEND_AAUDIO      = 2,    // AAudio (libaaudio.so)
    BACKEND_OBOE        = 3     // Google Oboe wrapper
};

// ======================================================================
// EN: Audio Stream Direction (matching AAudio & OpenSL ES)
// VN: Hướng dòng âm thanh (Khớp AAudio và OpenSL ES)
// ======================================================================
enum class AudioDirection : int32_t {
    DIRECTION_OUTPUT    = 0,    // Playback / Phát lại
    DIRECTION_INPUT     = 1     // Recording / Thu âm (Microphone)
};

// ======================================================================
// EN: Stream Lifecycle State
// VN: Trạng thái vòng đời luồng âm thanh
// ======================================================================
enum class StreamState : int32_t {
    STATE_UNINITIALIZED = 0,
    STATE_OPENED        = 1,
    STATE_STARTED       = 2,
    STATE_PAUSED        = 3,
    STATE_STOPPED       = 4,
    STATE_CLOSED        = 5
};

// ======================================================================
// EN: Audio Stream Event Info Structure
// VN: Cấu trúc thông tin sự kiện luồng âm thanh
// ======================================================================
struct AudioStreamEventInfo {
    int32_t stream_id{0};               // Unique stream handle / Định danh luồng duy nhất
    AudioBackendType backend{AudioBackendType::BACKEND_UNKNOWN};
    AudioDirection direction{AudioDirection::DIRECTION_INPUT};
    pid_t process_id{0};                // PID
    pid_t thread_id{0};                 // TID
    char thread_comm[64]{0};            // Comm read from /proc/%ld/task/%ld/comm
    int32_t sample_rate{44100};         // Hz
    int32_t channel_count{2};           // 1=Mono, 2=Stereo
    int32_t buffer_frames{512};         // Frame count per buffer
    int64_t open_timestamp_ms{0};       // Epoch ms
    int64_t close_timestamp_ms{0};      // Epoch ms
    bool is_recording{false};           // Privacy flag / Cờ giám sát quyền riêng tư
};

// ======================================================================
// EN: Minimal Cleanroom OpenSL ES ABI Declarations
// VN: Khai báo ABI OpenSL ES Cleanroom (Tương thích nhị phân libOpenSLES.so)
// ======================================================================
typedef uint32_t SLresult;
typedef void* SLObjectItf;
typedef void* SLEngineItf;
typedef void* SLRecordItf;
typedef void* SLPlayItf;

#define SL_RESULT_SUCCESS ((SLresult) 0x00000000)
#define SL_BOOLEAN_TRUE   ((uint32_t) 1)
#define SL_BOOLEAN_FALSE  ((uint32_t) 0)

// Standard OpenSL ES Interface UUID struct (16 bytes)
struct SLInterfaceID_ {
    uint32_t time_low;
    uint16_t time_mid;
    uint16_t time_hi_and_version;
    uint8_t  clock_seq_hi_and_reserved;
    uint8_t  clock_seq_low;
    uint8_t  node[6];
};
typedef const struct SLInterfaceID_* const SLInterfaceID;

// Mock UUIDs for OpenSL ES Record & Engine (matching ELF symbols)
extern const struct SLInterfaceID_ SL_IID_RECORD_VAL;
extern const struct SLInterfaceID_ SL_IID_ENGINE_VAL;

// OpenSL ES Object Interface vtable
struct SLObjectItf_ {
    SLresult (*Realize)(SLObjectItf self, uint32_t async);
    SLresult (*Resume)(SLObjectItf self, uint32_t async);
    SLresult (*GetState)(SLObjectItf self, uint32_t* pState);
    SLresult (*GetInterface)(SLObjectItf self, const SLInterfaceID iid, void* pInterface);
    SLresult (*RegisterCallback)(SLObjectItf self, void* callback, void* pContext);
    void (*AbortAsyncOperation)(SLObjectItf self);
    void (*Destroy)(SLObjectItf self);
    SLresult (*SetPriority)(SLObjectItf self, int32_t priority, uint32_t preemptable);
    SLresult (*GetPriority)(SLObjectItf self, int32_t* pPriority, uint32_t* pPreemptable);
    SLresult (*SetLossOfControlInterfaces)(SLObjectItf self, int16_t numInterfaces, SLInterfaceID* pInterfaceIDs, uint32_t enabled);
};

// ======================================================================
// EN: Minimal Cleanroom AAudio ABI Declarations
// VN: Khai báo ABI AAudio Cleanroom (Tương thích nhị phân libaaudio.so)
// ======================================================================
typedef struct AAudioStreamBuilderStruct AAudioStreamBuilder;
typedef struct AAudioStreamStruct AAudioStream;
typedef int32_t aaudio_result_t;
typedef int32_t aaudio_direction_t;

#define AAUDIO_OK 0
#define AAUDIO_DIRECTION_OUTPUT 0
#define AAUDIO_DIRECTION_INPUT  1

// Function pointer signatures for dlsym in libaaudio.so
using AAudioStreamBuilder_openStream_fn = aaudio_result_t (*)(AAudioStreamBuilder* builder, AAudioStream** stream);
using AAudioStream_close_fn            = aaudio_result_t (*)(AAudioStream* stream);
using AAudioStream_getDirection_fn     = aaudio_direction_t (*)(AAudioStream* stream);

// ======================================================================
// EN: ByteHook Dynamic PLT/GOT Hooking Types
// VN: Các kiểu dữ liệu hook động ByteHook PLT/GOT
// ======================================================================
typedef void* bytehook_stub_t;
typedef int (*bytehook_hook_callback_t)(bytehook_stub_t stub, int status, const char* caller_path, const char* sym_name, void* new_func, void* prev_func, void* arg);

} // namespace com::bytedance::helios::nativeaudio
