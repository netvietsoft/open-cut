/**
 * @file ttmplayer_types.h
 * @brief Cleanroom C++17 Type & AArch64 ABI Layout Definitions for libttmplayer.so
 *        Định nghĩa Kiểu dữ liệu & Bố cục ABI AArch64 Tái cấu trúc Sạch cho libttmplayer.so
 *
 * Binary Ground Truth / Tham chiếu Nhị phân Gốc:
 * - File: apktool-res/lib/arm64-v8a/libttmplayer.so (3,594,936 bytes, AArch64 ELF64)
 * - .text:        0x0967b0 .. 0x29a1dc (2,112,044 bytes)
 * - .rodata:      0x29a1e0 .. 0x2dbe26 (  269,382 bytes)
 * - .data.rel.ro: 0x3394e8 .. 0x36dd48 (  215,136 bytes)
 * - .data:        0x370000 .. 0x371288 (    4,744 bytes)
 * - .bss:         0x371288 .. 0x374190 (   12,040 bytes)
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_TYPES_H_
#define NEXTAI_OPENCUT_TTMPLAYER_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <map>
#include <mutex>
#include <string>
#include <vector>

namespace com {
namespace ss {
namespace ttm {
namespace player {

// ============================================================================
// 1. Value Type Enumeration (Matches Value::ctor @ 0x16b6c0 .. 0x16b784)
//    Liệt kê Kiểu dữ liệu của Value (Khớp Value::ctor tại 0x16b6c0 .. 0x16b784)
// ============================================================================
enum ValueType : int32_t {
    kValueTypeNone   = 0,  // Default constructor @ 0x16b6c0
    kValueTypeInt32  = 1,  // Value::ctor(int const&) @ 0x16b6cc (mov w8, #1; str w8, [x0, #0x18])
    kValueTypeInt64  = 2,  // Value::ctor(long const&) @ 0x16b6e4 (mov w8, #2; str w8, [x0, #0x18])
    kValueTypeFloat  = 3,  // Value::ctor(float const&) @ 0x16b6fc (mov w8, #3; str w8, [x0, #0x18])
    kValueTypeDouble = 4,  // Value::ctor(double const&) @ 0x16b714 (mov w8, #4; str w8, [x0, #0x18])
    kValueTypeString = 5,  // Value::ctor(std::string const&) @ 0x16b72c (mov w8, #5; str w8, [x0, #0x18])
    kValueTypePtr    = 6   // Value::ctor(void*) @ 0x16b774 (mov w8, #6; str w8, [x0, #0x18])
};

// ============================================================================
// 2. VString (24-byte SSO String Wrapper @ 0x16b464 .. 0x16b6a8)
//    Lớp Chuỗi VString 24-byte Tối ưu Chuỗi Ngắn SSO (0x16b464 .. 0x16b6a8)
// ============================================================================
// Disassembly of VString::c_str() @ 0x16b6a8:
//   0x16b6a8: ldrb w8, [x0]
//   0x16b6ac: tbnz w8, #0, #0x16b6b8
//   0x16b6b0: add  x0, x0, #1
//   0x16b6b4: ret
//   0x16b6b8: ldr  x0, [x0, #0x10]
//   0x16b6bc: ret
struct VString {
    union {
        struct {
            uint8_t tag;        // +0x00: bit 0 = 0 (SSO short), upper 7 bits = length << 1
            char sso_buf[23];   // +0x01: inline null-terminated characters (up to 22 chars + '\0')
        } short_rep;
        struct {
            uint64_t cap_flag;  // +0x00: bit 0 = 1 (heap long mode), capacity | 1ULL
            uint64_t size;      // +0x08: string byte length
            char* data;         // +0x10: heap-allocated null-terminated buffer
        } long_rep;
        uint64_t raw_words[3];  // 24 bytes total (+0x00, +0x08, +0x10)
    };

    VString() noexcept;
    explicit VString(const char* str);
    explicit VString(const std::string& str);
    explicit VString(std::string&& str) noexcept;
    VString(const VString& other);
    VString(VString&& other) noexcept;
    ~VString() noexcept;

    VString& operator=(const char* str);
    VString& operator=(const std::string& str);
    VString& operator=(std::string&& str) noexcept;
    VString& operator=(const VString& other);
    VString& operator=(VString&& other) noexcept;

    const char* c_str() const noexcept;
    std::string get() const;
    void reset() noexcept;
};

static_assert(sizeof(VString) == 24, "VString must be exactly 24 bytes (0x18) on AArch64");

// ============================================================================
// 3. Value (32-byte Polymorphic Variant @ 0x16b6c0 .. 0x16bc00)
//    Cấu trúc Biến Đa hình Value 32-byte (0x16b6c0 .. 0x16bc00)
// ============================================================================
// Disassembly of Parcel::isFull() @ 0x16be78 and Parcel::get() @ 0x16c990:
// - Element stride is 32 bytes (1 << 5, `asr #5` / `lsl #5`).
// - Value::Data occupies +0x00..+0x17 (24 bytes).
// - Value::type_ occupies +0x18..+0x1b (4 bytes), +0x1c..+0x1f padding.
struct Value {
    struct Data {
        union {
            int32_t i32_val;
            int64_t i64_val;
            float f32_val;
            double f64_val;
            void* ptr_val;
            uint64_t raw_words[3]; // Holds VString (24 bytes) when type_ == kValueTypeString
        };
        Data() noexcept;
        ~Data() noexcept;
    };

    Data data_;          // +0x00 (24 bytes)
    int32_t type_;       // +0x18 (ValueType enum)
    int32_t reserved_;   // +0x1c (alignment padding to 32 bytes)

    Value() noexcept;
    explicit Value(const int32_t& v) noexcept;
    explicit Value(const int64_t& v) noexcept;
    explicit Value(const float& v) noexcept;
    explicit Value(const double& v) noexcept;
    explicit Value(const char* v);
    explicit Value(const std::string& v);
    explicit Value(std::string&& v);
    explicit Value(void* v) noexcept;
    Value(const Value& other);
    Value(Value&& other) noexcept;
    ~Value() noexcept;

    Value& operator=(const int32_t& v) noexcept;
    Value& operator=(const int64_t& v) noexcept;
    Value& operator=(const float& v) noexcept;
    Value& operator=(const double& v) noexcept;
    Value& operator=(const char* v);
    Value& operator=(const std::string& v);
    Value& operator=(std::string&& v);
    Value& operator=(void* v) noexcept;
    Value& operator=(const Value& other);
    Value& operator=(Value&& other) noexcept;

    void clear() noexcept;
    void copyData(const Value& other);
    void moveData(Value&& other) noexcept;

    int32_t type() const noexcept { return type_; }
    int32_t getInt32() const noexcept;
    int64_t getInt64() const noexcept;
    float getFloat() const noexcept;
    double getDouble() const noexcept;
    std::string getString() const;
    void* getPtr() const noexcept;
};

static_assert(sizeof(Value) == 32, "Value must be exactly 32 bytes (0x20) on AArch64");

// ============================================================================
// 4. Parcel (32-byte Fixed-Capacity Value Vector @ 0x16bc04 .. 0x16c9ec)
//    Gói dữ liệu Parcel 32-byte (0x16bc04 .. 0x16c9ec)
// ============================================================================
// Disassembly of Parcel::ctor(ulong) @ 0x16bc04:
//   +0x00: uint64_t capacity_
//   +0x08: Value* begin_
//   +0x10: Value* end_
//   +0x18: Value* cap_end_
struct Parcel {
    uint64_t capacity_;  // +0x00
    Value* begin_;       // +0x08
    Value* end_;         // +0x10
    Value* cap_end_;     // +0x18

    Parcel() noexcept;
    explicit Parcel(uint64_t max_elements);
    Parcel(const Parcel& other);
    Parcel(Parcel&& other) noexcept;
    ~Parcel() noexcept;

    Parcel& operator=(const Parcel& other);
    Parcel& operator=(Parcel&& other) noexcept;

    void init() noexcept;
    bool isFull() const noexcept;
    uint64_t size() const noexcept { return capacity_; }
    uint64_t count() const noexcept {
        return (begin_ && end_ >= begin_) ? static_cast<uint64_t>(end_ - begin_) : 0ULL;
    }

    void put(const int32_t& v);
    void put(const int64_t& v);
    void put(const float& v);
    void put(const double& v);
    void put(const char* v);
    void put(const std::string& v);
    void put(std::string&& v);
    void put(void* v);
    void put(const Value& v);
    void put(Value&& v);

    Value get(uint64_t index) const;
};

static_assert(sizeof(Parcel) == 32, "Parcel must be exactly 32 bytes (0x20) on AArch64");

// ============================================================================
// 5. Strategy Center & Operator Protocols (0x1660b0 .. 0x16ce34)
//    Giao thức Trung tâm Chiến lược & Toán tử Điều khiển Tải (0x1660b0 .. 0x16ce34)
// ============================================================================
class AVStrategyCenterProtocol {
public:
    virtual ~AVStrategyCenterProtocol() = default;
    virtual int32_t onEvent(int32_t event_id, int64_t arg1, int64_t arg2) = 0;
    virtual std::string packStrategyLogInfo(int64_t handle) = 0;
};

// Matches AVDropFrameOperator @ 0x16cde8 (vtable @ 0x34b030, refcount_ @ +0x08)
class AVDropFrameOperator {
public:
    int32_t refcount_;           // +0x08 (str wzr, [x0, #8] @ 0x16cde8)
    int32_t max_drop_streak_;    // +0x0c
    int64_t drop_threshold_us_;  // +0x10

    AVDropFrameOperator() noexcept;
    virtual ~AVDropFrameOperator() noexcept;
    virtual bool shouldDropVideoFrame(int64_t video_pts_us,
                                      int64_t audio_pts_us,
                                      int32_t consecutive_drops,
                                      bool is_keyframe) noexcept;
};

// Secondary interface for AVLoadControlOperator (+0x10 offset thunk _ZThn16_ @ 0x16ce2c)
class AVLoadControlSecondaryInterface {
public:
    virtual ~AVLoadControlSecondaryInterface() noexcept = default;
    virtual int32_t onTrackSelected(int32_t track_type, int32_t bitrate_bps) noexcept = 0;
};

// Matches AVLoadControlOperator @ 0x16ce04 (vtable @ 0x34b058, refcount_=1 @ +0x08, secondary vptr @ +0x10)
class AVLoadControlOperator : public AVLoadControlSecondaryInterface {
public:
    int32_t refcount_;              // +0x08 (mov w8, #1; str w8, [x0, #8] @ 0x16ce0c)
    int32_t min_buffer_ms_;         // +0x0c
    int32_t max_buffer_ms_;         // +0x18
    int32_t playback_start_ms_;     // +0x1c
    int32_t rebuffer_start_ms_;     // +0x20

    AVLoadControlOperator() noexcept;
    ~AVLoadControlOperator() noexcept override;

    virtual bool shouldStartPlayback(int64_t buffered_duration_ms,
                                     float playback_speed,
                                     bool rebuffering) const noexcept;
    virtual bool shouldContinueLoading(int64_t buffered_duration_ms,
                                       int64_t target_bitrate_bps) const noexcept;
    int32_t onTrackSelected(int32_t track_type, int32_t bitrate_bps) noexcept override;
};

}  // namespace player
}  // namespace ttm
}  // namespace ss
}  // namespace com

// ============================================================================
// 6. AJMediaCodec Native Ring-Buffer & Format Layout (0x212b34 .. 0x21a9c8)
//    Bố cục Bộ đệm Vòng 64-khe AJMediaCodec & Định dạng Giải mã Phần cứng
// ============================================================================
// Disassembly of AJMediaCodec::onFilledBuffer @ 0x212b34:
//   - +0x478: atomic<int32_t> error_or_eos_flag
//   - +0x6f0: format_changed condition signal counter
//   - +0x700: filled_buffer condition signal counter
//   - +0x824: atomic<int32_t> write_index (masked with & 0x3f)
//   - +0x828: atomic<int32_t> filled_count (max 64, checked via cmp w8, #0x3f)
//   - +0x830: 64 x 32-byte AJMediaCodecBufferSlot (lsl #5)
struct AJMediaCodecBufferSlot {
    int32_t buffer_index;  // +0x00 (str w2, [x10, #0x830] @ 0x212b60)
    int32_t offset;        // +0x04 (str w3, [x10, #0x834] @ 0x212b64)
    int32_t size;          // +0x08 (str w4, [x10, #0x838] @ 0x212b68)
    int32_t reserved0;     // +0x0c
    int64_t pts_us;        // +0x10 (str x5, [x10, #0x840] @ 0x212b6c)
    int32_t flags;         // +0x18 (str w6, [x10, #0x848] @ 0x212b70)
    int32_t reserved1;     // +0x1c
};

static_assert(sizeof(AJMediaCodecBufferSlot) == 32, "AJMediaCodecBufferSlot must be 32 bytes (1 << 5)");

struct AJMediaCodecNative {
    uint8_t header_pad[0x478];                     // +0x000 .. +0x477
    std::atomic<int32_t> error_flag;               // +0x478 (stlr w9, [x8] @ 0x212bb8)
    int32_t width;                                 // +0x47c
    int32_t height;                                // +0x480
    int32_t color_format;                          // +0x484
    int32_t stride;                                // +0x488
    int32_t slice_height;                          // +0x48c
    int32_t crop_left;                             // +0x490
    int32_t crop_top;                              // +0x494
    int32_t crop_right;                            // +0x498
    int32_t crop_bottom;                           // +0x49c
    int32_t yuv420_frame_bytes;                    // +0x4a0: (slice_height * stride * 3) / 2
    int32_t surface_completed;                     // +0x4a4
    int32_t last_empty_buffer_index;               // +0x4a8
    uint8_t mid_pad[0x6f0 - 0x4ac];                // +0x4ac .. +0x6ef
    std::atomic<uint64_t> format_cond_signals;     // +0x6f0 (+0x6f0 signal in 0x212bc4)
    uint64_t pad_6f8;                              // +0x6f8
    std::atomic<uint64_t> buffer_cond_signals;     // +0x700 (+0x700 signal in 0x212b94)
    uint8_t cond_pad[0x824 - 0x708];               // +0x708 .. +0x823
    std::atomic<int32_t> write_index;              // +0x824 (ldaxr/stlxr @ 0x212b48, & 0x3f @ 0x212b88)
    std::atomic<int32_t> filled_count;             // +0x828 (ldar @ 0x212b38, cmp #0x3f)
    int32_t read_index;                            // +0x82c
    AJMediaCodecBufferSlot slots[64];              // +0x830 .. +0x102f (64 * 32 = 2048 bytes)

    AJMediaCodecNative() noexcept;
};

static_assert(offsetof(AJMediaCodecNative, error_flag) == 0x478, "error_flag must be at +0x478");
static_assert(offsetof(AJMediaCodecNative, format_cond_signals) == 0x6f0, "format_cond_signals must be at +0x6f0");
static_assert(offsetof(AJMediaCodecNative, buffer_cond_signals) == 0x700, "buffer_cond_signals must be at +0x700");
static_assert(offsetof(AJMediaCodecNative, write_index) == 0x824, "write_index must be at +0x824");
static_assert(offsetof(AJMediaCodecNative, filled_count) == 0x828, "filled_count must be at +0x828");
static_assert(offsetof(AJMediaCodecNative, slots) == 0x830, "slots must be at +0x830");

// ============================================================================
// 7. TTPlayer Native Playback State Machine Context (0x0e8600 .. 0x1a3c58)
//    Ngữ cảnh Máy trạng thái Phát Đa phương tiện TTPlayer (0x0e8600 .. 0x1a3c58)
// ============================================================================
enum TTPlayerState : int32_t {
    kTTPlayerStateIdle        = 0,
    kTTPlayerStateInitialized = 1,
    kTTPlayerStatePreparing   = 2,
    kTTPlayerStatePrepared    = 3,
    kTTPlayerStateStarted     = 4,
    kTTPlayerStatePaused      = 5,
    kTTPlayerStateStopped     = 6,
    kTTPlayerStateCompleted   = 7,
    kTTPlayerStateError       = 8,
    kTTPlayerStateReleased    = 9
};

struct TTPlayerNativeContext {
    uint64_t magic;                                // +0x00: 0x54544D504C595231ULL ("TTMPLYR1")
    int64_t handle_id;                             // +0x08
    std::atomic<int32_t> state;                    // +0x10 (ldar w8, [x0, #0x10] @ 0x0e8634 & 0x0e950c)
    int32_t player_type;                           // +0x14
    int32_t video_width;                           // +0x18
    int32_t video_height;                          // +0x1c
    int32_t current_position_ms;                   // +0x20
    int32_t duration_ms;                           // +0x24
    int32_t looping;                               // +0x28
    float left_volume;                             // +0x2c
    float right_volume;                            // +0x30
    float camera_yaw;                              // +0x34
    float camera_pitch;                            // +0x38
    int32_t active_audio_stream_id;                // +0x3c
    int32_t active_video_stream_id;                // +0x40
    int32_t active_subtitle_stream_id;             // +0x44
    int32_t data_source_fd;                        // +0x48
    int32_t media_codec_enabled;                   // +0x4c
    int32_t prepare_seq;                           // +0x50 (mirrors +0xce4 in binary)
    int32_t session_id;                            // +0x54 (mirrors +0xb38 in binary)
    int32_t last_seek_mode;                        // +0x58
    int32_t screenshot_count;                      // +0x5c
    int32_t mouse_last_x;                          // +0x60
    int32_t mouse_last_y;                          // +0x64
    int32_t mouse_last_action;                     // +0x68
    int32_t filter_type;                           // +0x6c
    int64_t config_handle;                         // +0x70
    int64_t native_mdl_handle;                     // +0x78
    void* surface_ptr;                             // +0x80
    void* load_control_obj;                        // +0x88
    void* mask_info_obj;                           // +0x90
    void* ai_barrage_info_obj;                     // +0x98
    void* sub_info_obj;                            // +0xa0
    void* media_transport_obj;                     // +0xa8
    void* audio_processor_obj;                     // +0xb0
    void* abr_strategy_obj;                        // +0xb8
    std::string data_source_url;
    std::string app_info_tag;
    mutable std::mutex mutex;
    std::map<int32_t, int32_t> int_options;
    std::map<int32_t, int64_t> long_options;
    std::map<int32_t, float> float_options;
    std::map<int32_t, double> double_options;
    std::map<int32_t, std::string> string_options;
    std::map<int32_t, void*> trait_objects;

    TTPlayerNativeContext() noexcept;
};

#endif  // NEXTAI_OPENCUT_TTMPLAYER_TYPES_H_
