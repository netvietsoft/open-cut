// ======================================================================
// RECONSTRUCTED C++ TYPES & CORE DEFINITIONS: libttdemux.so
// Project: com.nextai.opencut (Cleanroom Re-engineering)
// Module: NextAI OpenCut TTPlayer Demuxer Engine
// ----------------------------------------------------------------------
// Language: C++17 / Native ABI AArch64
// Bilingual Annotations: English + Tiếng Việt (Rule 12 AGENTS.md)
// Zero-Stub Policy: 100% Concrete Types, Structs & ABI Definitions
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>

namespace com::ss::vcbkit {

// ======================================================================
// EN: Reference Counting Base Class (BaseRef)
// VN: Lớp cơ sở đếm tham chiếu (BaseRef) đồng bộ đa luồng
// ======================================================================
class BaseRef {
protected:
    mutable std::atomic<int32_t> m_ref_count{1};

public:
    BaseRef() = default;
    virtual ~BaseRef() = default;

    // EN: Increment reference counter atomically
    // VN: Tăng bộ đếm tham chiếu nguyên tử
    inline void incRef() const noexcept {
        m_ref_count.fetch_add(1, std::memory_order_relaxed);
    }

    // EN: Decrement reference counter, destruct when reaching 0
    // VN: Giảm bộ đếm tham chiếu, tự hủy khi đạt 0
    inline void decRef() const noexcept {
        if (m_ref_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }

    // EN: Query current reference count
    // VN: Truy vấn số lượng tham chiếu hiện tại
    inline int32_t getRefCount() const noexcept {
        return m_ref_count.load(std::memory_order_relaxed);
    }
};

// ======================================================================
// EN: Smart Pointer for BaseRef-derived classes (RefPtr)
// VN: Con trỏ thông minh cho các lớp kế thừa BaseRef (RefPtr)
// ======================================================================
template <typename T>
class RefPtr {
private:
    T* m_ptr{nullptr};

public:
    RefPtr() noexcept : m_ptr(nullptr) {}
    explicit RefPtr(T* ptr) noexcept : m_ptr(ptr) {
        if (m_ptr) m_ptr->incRef();
    }
    RefPtr(const RefPtr<T>& other) noexcept : m_ptr(other.m_ptr) {
        if (m_ptr) m_ptr->incRef();
    }
    RefPtr(RefPtr<T>&& other) noexcept : m_ptr(other.m_ptr) {
        other.m_ptr = nullptr;
    }
    ~RefPtr() {
        if (m_ptr) m_ptr->decRef();
    }

    RefPtr<T>& operator=(const RefPtr<T>& other) noexcept {
        if (this != &other) {
            if (other.m_ptr) other.m_ptr->incRef();
            if (m_ptr) m_ptr->decRef();
            m_ptr = other.m_ptr;
        }
        return *this;
    }

    RefPtr<T>& operator=(RefPtr<T>&& other) noexcept {
        if (this != &other) {
            if (m_ptr) m_ptr->decRef();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    inline T* get() const noexcept { return m_ptr; }
    inline T* operator->() const noexcept { return m_ptr; }
    inline T& operator*() const noexcept { return *m_ptr; }
    inline explicit operator bool() const noexcept { return m_ptr != nullptr; }

    inline void reset(T* ptr = nullptr) noexcept {
        if (ptr) ptr->incRef();
        if (m_ptr) m_ptr->decRef();
        m_ptr = ptr;
    }
};

// ======================================================================
// EN: Synchronization Primitives (Mutex, ScopedLock, CondVar)
// VN: Các nguyên ngữ đồng bộ hóa (Mutex, ScopedLock, CondVar)
// ======================================================================
class Mutex {
private:
    std::mutex m_mutex;
    friend class CondVar;
    friend class ScopedLock;

public:
    Mutex() = default;
    ~Mutex() = default;

    inline void lock() { m_mutex.lock(); }
    inline void unlock() { m_mutex.unlock(); }
    inline bool try_lock() { return m_mutex.try_lock(); }
};

class ScopedLock {
private:
    Mutex& m_ref_mutex;
    bool m_locked{true};

public:
    explicit ScopedLock(Mutex& mtx) : m_ref_mutex(mtx) {
        m_ref_mutex.lock();
    }
    ~ScopedLock() {
        if (m_locked) {
            m_ref_mutex.unlock();
            m_locked = false;
        }
    }
};

class CondVar {
private:
    std::condition_variable_any m_cv;

public:
    CondVar() = default;
    ~CondVar() = default;

    inline void wait(Mutex& mtx) {
        m_cv.wait(mtx.m_mutex);
    }
    inline void signal() {
        m_cv.notify_one();
    }
    inline void signalAll() {
        m_cv.notify_all();
    }
};

} // namespace com::ss::vcbkit

namespace com::ss::ttm::demuxer {

// ======================================================================
// EN: Demuxer Status & Event Enumerations
// VN: Các enum biểu diễn trạng thái và hành vi của bộ Demuxer
// ======================================================================
enum class DemuxStatus : int32_t {
    STATUS_UNKNOWN       = -1,
    STATUS_IDLE          = 0,
    STATUS_OPENING       = 1,
    STATUS_DEMUXING      = 2,
    STATUS_COMPLETED     = 3,
    STATUS_ERROR         = 4,
    STATUS_STOPPED       = 5
};

enum class DemuxAction : int32_t {
    ACTION_NONE          = 0,
    ACTION_OPEN_INPUT    = 1,
    ACTION_FIND_STREAM   = 2,
    ACTION_READ_PACKET   = 3,
    ACTION_SEEK          = 4,
    ACTION_CLOSE         = 5,
    ACTION_PREDEMUX_HIT  = 6
};

enum class PredemuxHitStatus : int32_t {
    PREDEMUX_TIMEOUT     = -1,
    PREDEMUX_NOT_USED    = 0,
    PREDEMUX_HIT         = 1,
    PREDEMUX_MISS        = 2
};

// ======================================================================
// EN: Seek Whence Flags (matching FFmpeg & Custom Demuxer Protocol)
// VN: Các cờ định hướng Seek (khớp FFmpeg và Protocol tùy biến)
// ======================================================================
enum SeekWhence : int32_t {
    TT_SEEK_SET          = 0,       // Standard SEEK_SET / Đặt vị trí tuyệt đối
    TT_SEEK_CUR          = 1,       // Standard SEEK_CUR / Vị trí hiện tại
    TT_SEEK_END          = 2,       // Standard SEEK_END / Cuối file
    TT_SEEK_CUSTOM_7000  = 0x7000,  // Opcode 0x6f24: 7 << 12 (Direct protocol seek)
    TT_SEEK_CUSTOM_7001  = 0x7001,  // Opcode 0x6f54: Query download byte offset
    TT_AVSEEK_SIZE       = 0x10000  // Opcode 0x6f60: 16 << 12 (FFmpeg AVSEEK_SIZE file length query)
};

// ======================================================================
// EN: Demuxer Metric Keys (Matching parseAndUpdateConnectionInfo at 0x7ac4)
// VN: Khóa chỉ số Demuxer (Khớp giải mã parseAndUpdateConnectionInfo ở 0x7ac4)
// ======================================================================
enum DemuxMetricKey : int32_t {
    METRIC_DNS_TIME              = 2,
    METRIC_CONNECT_TIME          = 3,
    METRIC_FIRST_PACKET_TIME     = 4,
    METRIC_DOWNLOAD_SPEED        = 5,
    METRIC_BYTES_RECEIVED        = 6,
    METRIC_RETRY_COUNT           = 7
};

// ======================================================================
// EN: Demuxer Option Keys (setIntValue, getIntValue, etc.)
// VN: Các khóa tùy chọn Demuxer
// ======================================================================
enum DemuxOptKey : int32_t {
    OPT_BUFFER_SIZE              = 1,
    OPT_MAX_RETRY_COUNT          = 2,
    OPT_SEEK_CACHE_ENABLED       = 3,
    OPT_PREDEMUX_ENABLED         = 4,
    OPT_AUTO_RANGE_CLOSE         = 5,
    OPT_TIMEOUT_MS               = 6,
    OPT_FILE_SIZE                = 7,
    OPT_CURRENT_OFFSET           = 8,
    OPT_LAST_ERROR_CODE          = 9
};

// ======================================================================
// EN: Minimal FFmpeg AVIO & AVFormat Cleanroom Types
// VN: Các kiểu dữ liệu tương thích FFmpeg AVIO & AVFormat Cleanroom
// ======================================================================
struct AVIOInterruptCB {
    int (*callback)(void*);
    void* opaque;
};

struct AVDictionaryEntry {
    char* key;
    char* value;
};

struct AVDictionary {
    int count;
    AVDictionaryEntry* elems;
};

struct AVInputFormat {
    const char* name;
    const char* long_name;
    int flags;
    const char* extensions;
    const char* mime_type;
};

// EN: Standard FFmpeg AVIOContext ABI layout with ByteDance extension
// VN: Bố cục ABI của AVIOContext chuẩn FFmpeg cùng phần mở rộng ByteDance (TTIOContext)
struct AVIOContext {
    unsigned char* buffer;          // +0x00: Buffer pointer / Con trỏ vùng đệm
    int buffer_size;                // +0x08: Buffer size (0x8000 = 32KB) / Kích thước đệm
    unsigned char* buf_ptr;         // +0x10: Current read/write ptr / Con trỏ đọc/ghi hiện tại
    unsigned char* buf_end;         // +0x18: End of buffer data / Cuối dữ liệu đệm
    void* opaque;                   // +0x20: Demuxer instance (AVSourceInput*) / Đối tượng input
    int (*read_packet)(void* opaque, uint8_t* buf, int buf_size); // +0x28: Read thunk (0x7978)
    int (*write_packet)(void* opaque, uint8_t* buf, int buf_size); // +0x30: Write thunk (null)
    int64_t (*seek)(void* opaque, int64_t offset, int whence);     // +0x38: Seek thunk (0x7988)
    int64_t pos;                    // +0x40: Position in stream / Vị trí luồng
    int must_flush;                 // +0x48: Flush flag / Cờ flush
    int eof_reached;                // +0x4c: EOF indicator / Cờ chạm EOF
    int write_flag;                 // +0x50: Write mode flag (0) / Cờ ghi (0 = readonly)
    int max_packet_size;            // +0x54: Max packet size / Kích thước gói tối đa
    unsigned long checksum;         // +0x58: Checksum accumulator / Bộ tích lũy checksum
    unsigned char* checksum_ptr;    // +0x60: Checksum pointer
    int (*update_checksum)(unsigned long checksum, const uint8_t* buf, unsigned int size);
    int error;                      // +0x70: Error code / Mã lỗi
    int (*read_pause)(void* opaque, int pause);
    int64_t (*read_seek)(void* opaque, int stream_index, int64_t timestamp, int flags);
    int seekable;                   // +0x88: Seekable flags (AVIO_SEEKABLE_NORMAL)
    int64_t maxsize;                // +0x8c: Max size
    int direct;                     // +0x94: Direct IO mode
    int64_t bytes_read;             // +0x98: Total bytes transferred
    int seek_count;                 // +0xa0: Seek counter
    int writeout_count;             // +0xa4: Writeout counter
    int orig_buffer_size;           // +0xa8: Initial buffer size
    int short_seek_threshold;       // +0xac: Short seek threshold
};

// EN: ByteDance TTIOContext extension allocated at 0x790c (size = 0x110 = 272 bytes)
// VN: Phần mở rộng TTIOContext của ByteDance phân bổ tại 0x790c (kích thước 0x110 = 272 bytes)
struct TTIOContext {
    AVIOContext avio;               // +0x000: Standard AVIOContext base
    int32_t is_streamed;            // +0x090: Streamed flag set to 1 at opcode 0x795c
    int32_t reserved_flags;         // +0x094: Reserved options
    void* tt_vtable;                // +0x098: Custom vtable hook
    int64_t download_offset;        // +0x0a0: Progressive download offset
    int64_t total_content_length;   // +0x0a8: Cached content length
    char url[104];                  // +0x0b0: Cached URI string
};

// EN: Forward declaration of AVFormatContext
struct AVFormatContext {
    const void* av_class;
    AVInputFormat* iformat;
    void* oformat;
    void* priv_data;
    AVIOContext* pb;                // +0x20: IO context pointer bound at 0x77ec
    int ctx_flags;
    unsigned int nb_streams;
    void** streams;
    char filename[1024];
    int64_t start_time;
    int64_t duration;
    int64_t bit_rate;
    unsigned int packet_size;
    int max_delay;
    int flags;                      // +0x468: Format flags (Bit 0x80: AVFMT_FLAG_CUSTOM_IO at 0x7834)
    int64_t probesize;
    int64_t max_analyze_duration;
    const uint8_t* key;
    int keylen;
    unsigned int nb_programs;
    void** programs;
    int video_codec_id;
    int audio_codec_id;
    int subtitle_codec_id;
    unsigned int max_index_entries;
    unsigned int max_picture_buffer;
    unsigned int nb_chapters;
    void** chapters;
    AVDictionary* metadata;
    int64_t start_time_realtime;
    int fps_probe_size;
    int error_recognition;
    AVIOInterruptCB interrupt_callback; // +0x5c8: Interrupt callback set at 0x7820
};

// ======================================================================
// EN: Context Holder Data Structures
// VN: Các cấu trúc dữ liệu của DemuxContextHolder
// ======================================================================
struct DemuxConfig {
    int32_t buffer_size{32768};             // 32KB default / Mặc định 32KB
    int32_t max_retry{3};                   // Max retry attempts / Số lần thử lại tối đa
    int32_t seek_cache{1};                  // Seek position caching / Bật cache vị trí seek
    int32_t predemux_enabled{1};            // Enable predemux / Bật tính năng predemux
    int32_t auto_range_close{0};            // Auto range close on EOF / Tự động đóng dải byte
    int64_t open_timeout_ms{15000};         // Open timeout / Thời gian chờ mở luồng
    int64_t read_timeout_ms{10000};         // Read packet timeout / Thời gian chờ đọc gói
};

struct DemuxMetrics {
    int64_t dns_time_ms{0};                 // DNS resolve duration / Thời gian phân giải DNS
    int64_t connect_time_ms{0};             // TCP/TLS connection time / Thời gian kết nối socket
    int64_t first_packet_time_ms{0};        // TTFB first byte latency / Độ trễ gói tin đầu tiên
    int64_t download_speed_kbps{0};         // Average download speed / Tốc độ tải trung bình
    int64_t total_bytes_received{0};        // Total payload read / Tổng số byte đã nhận
    int64_t retry_count{0};                 // Number of network retries / Số lần thử lại mạng
    int32_t last_error_code{0};             // Last encountered POSIX/FFmpeg error / Mã lỗi gần nhất

    // EN: Update metrics based on bitfield key: (action << 16) | metric_id
    // VN: Cập nhật chỉ số dựa trên khóa bitfield: (action << 16) | metric_id
    void setInt64Value(int32_t key, int64_t value) noexcept {
        int32_t metric_id = key & 0xffff;
        switch (metric_id) {
            case METRIC_DNS_TIME:
                dns_time_ms = value;
                break;
            case METRIC_CONNECT_TIME:
                connect_time_ms = value;
                break;
            case METRIC_FIRST_PACKET_TIME:
                first_packet_time_ms = value;
                break;
            case METRIC_DOWNLOAD_SPEED:
                download_speed_kbps = value;
                break;
            case METRIC_BYTES_RECEIVED:
                total_bytes_received = value;
                break;
            case METRIC_RETRY_COUNT:
                retry_count = value;
                break;
            default:
                break;
        }
    }
};

struct DemuxLogInfo {
    int32_t log_level{3};                   // Log level: 1=Error, 2=Warn, 3=Info, 4=Debug
    int32_t module_id{101};                 // Subsystem identifier / Định danh phân hệ
    std::string message;                    // Log payload / Nội dung thông điệp
};

// ======================================================================
// EN: DemuxContextHolder (BaseRef & Config Container)
// VN: DemuxContextHolder (Vỏ bọc cấu hình, metrics và log cho toàn bộ Demuxer)
// ======================================================================
class DemuxContextHolder : public com::ss::vcbkit::BaseRef {
public:
    DemuxConfig config;
    DemuxMetrics metrics;
    DemuxLogInfo log_info;
    com::ss::vcbkit::Mutex context_mutex;

public:
    DemuxContextHolder() = default;
    virtual ~DemuxContextHolder() override = default;

    // Mangled: _ZN3com2ss3ttm7demuxer18DemuxContextHolder9getIntOptEii (0x8730)
    int32_t getIntOpt(int32_t key, int32_t default_val) const noexcept {
        switch (key) {
            case OPT_BUFFER_SIZE:        return config.buffer_size;
            case OPT_MAX_RETRY_COUNT:    return config.max_retry;
            case OPT_SEEK_CACHE_ENABLED: return config.seek_cache;
            case OPT_PREDEMUX_ENABLED:   return config.predemux_enabled;
            case OPT_AUTO_RANGE_CLOSE:   return config.auto_range_close;
            default:                     return default_val;
        }
    }

    // Mangled: _ZN3com2ss3ttm7demuxer18DemuxContextHolder8setValueEiPKvi (0x8738)
    void setValue(int32_t key, const void* val, int32_t size) noexcept {
        if (!val || size <= 0) return;
        com::ss::vcbkit::ScopedLock lock(const_cast<com::ss::vcbkit::Mutex&>(context_mutex));
        if (key == OPT_BUFFER_SIZE && size >= (int)sizeof(int32_t)) {
            config.buffer_size = *reinterpret_cast<const int32_t*>(val);
        }
    }

    // Mangled: _ZN3com2ss3ttm7demuxer18DemuxContextHolder13setInt64ValueEil (0x8740)
    void setInt64Value(int32_t key, int64_t val) noexcept {
        com::ss::vcbkit::ScopedLock lock(context_mutex);
        metrics.setInt64Value(key, val);
    }

    // Mangled: _ZN3com2ss3ttm7demuxer18DemuxContextHolder9onLogInfoEiiPKc (0x8748)
    void onLogInfo(int32_t level, int32_t module, const char* msg) noexcept {
        com::ss::vcbkit::ScopedLock lock(context_mutex);
        log_info.log_level = level;
        log_info.module_id = module;
        if (msg) log_info.message = msg;
    }
};

} // namespace com::ss::ttm::demuxer
