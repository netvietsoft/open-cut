// ============================================================================
// File: ttkmedianet_types.h
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// SHA-256: f6826092b0e554652515dac78ffbeb99ee14434369d57c0e81697564b5e03860
// EN: Exact AArch64 ABI layouts for TTKMediaNet::NetworkTask, TTKMediaNet::NetworkMgr,
//     RequestContext, ResponseContext, StrategyContext, PreConnectContext, and QUIC Config.
// VI: Bố cục ABI AArch64 chính xác cho TTKMediaNet::NetworkTask, TTKMediaNet::NetworkMgr,
//     RequestContext, ResponseContext, StrategyContext, PreConnectContext và cấu hình QUIC.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <memory>
#include <unordered_map>
#include <mutex>
#include <atomic>

namespace TTKMediaNet {

// EN: Key constants verified from NetworkTask::InternalKeyConvertToExternalKey (0x0332b0..0x0332dc)
//     and NetworkTask::TCSetInt64Value (0x033464..0x03349c)
// VI: Các hằng số khóa xác minh từ NetworkTask::InternalKeyConvertToExternalKey (0x0332b0..0x0332dc)
//     và NetworkTask::TCSetInt64Value (0x033464..0x03349c)
constexpr int32_t kTaskKeyEnableDirectCallback = 101000; // 0x00018A88 @ 0x033464
constexpr int32_t kInternalKeyBase             = 900003; // -0xFFF2445D @ 0x0332b0
constexpr int32_t kInternalToExternalDelta     = -798998; // 0xFFF3CEEA @ 0x0332c4 (maps 900003..900006 -> 101005..101008)
constexpr int32_t kExternalKeyDefault          = 101009; // 0x00018A91 @ 0x0332d4

struct RequestContext {
    std::string url;
    std::string host;
    std::string method{"GET"};
    std::unordered_map<std::string, std::string> headers;
    int64_t range_start{0};
    int64_t range_end{-1};
    int32_t connect_timeout_ms{5000};
    int32_t read_timeout_ms{10000};
    int32_t write_timeout_ms{10000};
    bool send_header_when_started{false};
};

struct ResponseContext {
    int32_t status_code{200};
    int64_t content_length{-1};
    std::string content_range;
    std::string server_ip;
    bool socket_reused{false};
    std::unordered_map<std::string, std::string> headers;
};

struct StrategyContext {
    bool quic_enabled{true};
    std::string quic_version{"draft-29"};
    std::string cc_type{"cubic"};
    uint32_t init_cwnd{32};
    bool pacing_on{true};
    bool ping_on{true};
    uint32_t so_sndbuf{1048576};
    uint32_t so_rcvbuf{1048576};
    uint32_t init_idle_time_out{30000};
    bool spurious_loss_detect_on{true};
    bool linger_on{false};
    uint32_t linger_timeout{0};
    std::string cipher_suites{"X25519:P-256:P-384:P-521"};
    bool enable_0rtt{true};
    bool enable_scfg_persist{true};
    uint32_t scfg_persist_interval{3600};
    uint32_t keyupdate_pkt_threshold{1000000};
    bool disable_init_win_thresh{false};
    uint32_t ctr_packets_used_max{10000};
    bool iacc_optimization{true};
    uint32_t oversent_percent{120};
    uint32_t pacing_gain_percent{125};
    uint32_t fully_reach_cnt{3};
    uint32_t smooth_iacc_percent{80};
    uint32_t steady_thresh{10};
    uint32_t max_packet_process_batch{64};
    uint32_t max_packet_process_timeout{20};
    uint32_t session_recv_win_size{6291456};
    uint32_t stream_recv_win_size{2097152};
    uint32_t max_udp_payload_size{1350};
};

struct PreConnectContext {
    std::string host;
    uint16_t port{443};
    int32_t protocol_version{29};
    bool enable_0rtt{true};
};

class TTKMediaNetTask {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void OnResponseStarted(const ResponseContext& resp) = 0;
        virtual void OnReadCompleted(int32_t bytes_read) = 0;
        virtual void OnWriteCompleted(int32_t bytes_written) = 0;
        virtual void OnMessage(int32_t key, int64_t code, const std::string& msg) = 0;
    };
    virtual ~TTKMediaNetTask() = default;
};

class TTKMediaNetMgr {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void OnLog(int32_t level, const std::string& log_msg) = 0;
        virtual int32_t OnCertVerify(void* ssl_ctx, const char* host, int16_t port) = 0;
    };
    virtual ~TTKMediaNetMgr() = default;
};

// EN: Exact ABI layout of NetworkTask verified from NetworkTask::NetworkTask (0x02f54c..0x02f5cc)
//     +0x00: vptr_primary   (0x09a2f0)
//     +0x08: vptr_secondary (0x09a378)
//     +0x10: mutex_state    (40 bytes)
//     +0x40: task_id        (uint64_t, atomically incremented from .bss 0x09dd20)
//     +0x48: state_flags    (uint8_t)
//     +0x49: direct_cb_flag (uint8_t, set to 1 in TCSetInt64Value @ 0x033478 when key == 0x00018A88)
//     +0x78: weak_dlg_ptr   (void*)
//     +0x80: weak_ctrl_blk  (void*)
//     +0x88: ext_delegate   (TTKMediaNetTask::Delegate*, cleared in ResetDelegate @ 0x033074)
//     +0x90: quic_req_ctx   (void*, dereferenced at +0x90 in TCSetInt64Value @ 0x03347c)
// VI: Bố cục ABI chính xác của NetworkTask xác minh từ NetworkTask::NetworkTask (0x02f54c..0x02f5cc)
struct NetworkTaskAbiLayout {
    void*     vptr_primary;      // +0x00
    void*     vptr_secondary;    // +0x08
    uint8_t   mutex_area[0x30];  // +0x10..0x3F
    uint64_t  task_id;           // +0x40
    uint8_t   state_flags;       // +0x48
    uint8_t   direct_cb_flag;    // +0x49
    uint8_t   reserved_pad[0x2E];// +0x4A..0x77
    void*     weak_dlg_ptr;      // +0x78
    void*     weak_ctrl_blk;     // +0x80
    TTKMediaNetTask::Delegate* ext_delegate; // +0x88
    void*     quic_req_ctx;      // +0x90
    void*     quic_req_ctrl;     // +0x98
};
static_assert(offsetof(NetworkTaskAbiLayout, task_id) == 0x40, "task_id must be at +0x40");
static_assert(offsetof(NetworkTaskAbiLayout, state_flags) == 0x48, "state_flags must be at +0x48");
static_assert(offsetof(NetworkTaskAbiLayout, direct_cb_flag) == 0x49, "direct_cb_flag must be at +0x49");
static_assert(offsetof(NetworkTaskAbiLayout, weak_dlg_ptr) == 0x78, "weak_dlg_ptr must be at +0x78");
static_assert(offsetof(NetworkTaskAbiLayout, ext_delegate) == 0x88, "ext_delegate must be at +0x88");
static_assert(offsetof(NetworkTaskAbiLayout, quic_req_ctx) == 0x90, "quic_req_ctx must be at +0x90");
static_assert(sizeof(NetworkTaskAbiLayout) == 0xA0, "NetworkTaskAbiLayout must be 0xA0 bytes");

// EN: Exact ABI layout of NetworkMgr verified from NetworkMgr::NetworkMgr (0x03b0c0..0x03b16c)
//     +0x00: vptr_primary      (0x09a620)
//     +0x08: vptr_secondary    (0x09a6a8)
//     +0x10: mgr_delegate      (TTKMediaNetMgr::Delegate*)
//     +0x18: worker_thread_ptr (void*)
//     +0x20: started_flag      (uint8_t)
//     +0x30: task_table_buckets(uint8_t[0x20])
//     +0x50: max_load_factor   (float = 1.0f / 0x3F800000 @ 0x03b0e8)
//     +0x58: quic_engine_ctx   (void*)
//     +0x60: config_map_area   (uint8_t[0x10])
// VI: Bố cục ABI chính xác của NetworkMgr xác minh từ NetworkMgr::NetworkMgr (0x03b0c0..0x03b16c)
struct NetworkMgrAbiLayout {
    void*     vptr_primary;      // +0x00
    void*     vptr_secondary;    // +0x08
    TTKMediaNetMgr::Delegate* mgr_delegate; // +0x10
    void*     worker_thread_ptr; // +0x18
    uint8_t   started_flag;      // +0x20
    uint8_t   pad_21[0x0F];      // +0x21..0x2F
    uint8_t   task_table[0x20];  // +0x30..0x4F
    float     max_load_factor;   // +0x50 (0x3F800000 = 1.0f)
    uint32_t  pad_54;            // +0x54
    void*     quic_engine_ctx;   // +0x58
    uint64_t  stat_total_tasks;  // +0x60
    uint64_t  stat_active_conns; // +0x68
};
static_assert(offsetof(NetworkMgrAbiLayout, max_load_factor) == 0x50, "max_load_factor must be at +0x50");
static_assert(offsetof(NetworkMgrAbiLayout, quic_engine_ctx) == 0x58, "quic_engine_ctx must be at +0x58");
static_assert(sizeof(NetworkMgrAbiLayout) == 0x70, "NetworkMgrAbiLayout must be 0x70 bytes");

} // namespace TTKMediaNet
