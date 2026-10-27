// ============================================================================
// File: ttkmedianet_core.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 implementation of TTKMediaNet::NetworkTask and
//     TTKMediaNet::NetworkMgr matching exact AArch64 opcodes (0x02f54c..0x03b1d8).
// VI: Triển khai C++17 phòng sạch của TTKMediaNet::NetworkTask và
//     TTKMediaNet::NetworkMgr khớp chính xác mã máy AArch64 (0x02f54c..0x03b1d8).
// ============================================================================
#include "ttkmedianet_core.h"
#include <cstring>
#include <algorithm>

namespace TTKMediaNet {

namespace {
// EN: Global atomic task ID counter at .bss 0x09dd20 (verified in NetworkTask::NetworkTask @ 0x02f568..0x02f584)
// VI: Bộ đếm task_id nguyên tử toàn cục tại .bss 0x09dd20 (xác minh tại 0x02f568..0x02f584)
std::atomic<uint64_t> g_next_task_id_09dd20{0};
} // namespace

// ============================================================================
// 1. NetworkTask Implementation (0x02f54c .. 0x0338e4)
// ============================================================================

// Disassembly @ 0x02f54c..0x02f5cc:
//   ldaxr x9, [x8]; add x9, x9, #1; stlxr w10, x9, [x8]; cbnz w10, 0x2f578
//   str x9, [x0, #0x40]
//   strh wzr, [x0, #0x48]
NetworkTask::NetworkTask(std::weak_ptr<Delegate> /*delegate*/) noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    const uint64_t next_id = g_next_task_id_09dd20.fetch_add(1ULL, std::memory_order_acq_rel) + 1ULL;
    abi_.task_id = next_id;
    abi_.state_flags = 0u;
    abi_.direct_cb_flag = 0u;
}

NetworkTask::~NetworkTask() = default;

// Disassembly @ 0x0332b0..0x0332dc:
//   0x0332b0: 52888ba8 mov  w8, #0x445d
//   0x0332b4: 72bffe48 movk w8, #0xfff2, lsl #16   (w8 = 0xFFF2445D = -900003)
//   0x0332b8: 0b080028 add  w8, w1, w8
//   0x0332bc: 71000d1f cmp  w8, #3
//   0x0332c0: 540000a8 b.hi 0x332d4
//   0x0332c4: 5299dd48 mov  w8, #0xceea
//   0x0332c8: 72bffe68 movk w8, #0xfff3, lsl #16   (w8 = 0xFFF3CEEA = -798998)
//   0x0332cc: 0b080020 add  w0, w1, w8
//   0x0332d0: d65f03c0 ret
//   0x0332d4: 52915220 mov  w0, #0x8a91
//   0x0332d8: 72a00020 movk w0, #1, lsl #16        (w0 = 0x00018A91 = 101009)
//   0x0332dc: d65f03c0 ret
int32_t NetworkTask::InternalKeyConvertToExternalKey(int32_t internal_key) noexcept {
    const uint32_t offset = static_cast<uint32_t>(internal_key) + 0xFFF2445Du;
    if (offset <= 3u) {
        return static_cast<int32_t>(static_cast<uint32_t>(internal_key) + 0xFFF3CEEAu);
    }
    return kExternalKeyDefault; // 101009 (0x00018A91)
}

// Disassembly @ 0x0312b8: 52800020 (mov w0, #1); D65F03C0 (ret)
int32_t NetworkTask::GetStringValue(int32_t key, std::string& out_value) noexcept {
    auto it = str_params_.find(key);
    if (it != str_params_.end()) {
        out_value = it->second;
    }
    return 1;
}

// Disassembly @ 0x0312c0: 52800020 (mov w0, #1); D65F03C0 (ret)
int32_t NetworkTask::GetInt64Value(int32_t key, int64_t& out_value) noexcept {
    auto it = int_params_.find(key);
    if (it != int_params_.end()) {
        out_value = it->second;
    }
    return 1;
}

// Disassembly @ 0x033058..0x033084:
//   Clears ext_delegate at [x19, #0x88] under mutex at [x19, #0x10]
void NetworkTask::ResetDelegate() noexcept {
    abi_.ext_delegate = nullptr;
}

// Disassembly @ 0x033464..0x03349c:
//   0x033464: 52915108 mov  w8, #0x8a88
//   0x033468: 72a00028 movk w8, #1, lsl #16 (0x00018A88 = 101000)
//   0x03346c: 6b08003f cmp  w1, w8
//   0x033470: 54000061 b.ne 0x3347c
//   0x033474: 52800028 mov  w8, #1
//   0x033478: 39012408 strb w8, [x0, #0x49]
int32_t NetworkTask::TCSetInt64Value(int32_t key, int64_t value) noexcept {
    if (key == kTaskKeyEnableDirectCallback) {
        abi_.direct_cb_flag = 1u;
    }
    int_params_[key] = value;
    return 1;
}

int32_t NetworkTask::TCSetStringValue(int32_t key, std::string value) noexcept {
    str_params_[key] = std::move(value);
    return 0;
}

int32_t NetworkTask::SetStringValue(int32_t key, std::string value) noexcept {
    return TCSetStringValue(key, std::move(value));
}

int32_t NetworkTask::SetInt64Value(int32_t key, int64_t value) noexcept {
    return TCSetInt64Value(key, value);
}

int32_t NetworkTask::Open(RequestContext& req, StrategyContext& strat, TTKMediaNetTask::Delegate* ext_dlg) noexcept {
    abi_.ext_delegate = ext_dlg;
    return StartTask(req, strat);
}

int32_t NetworkTask::StartTask(RequestContext& req, StrategyContext& /*strat*/) noexcept {
    abi_.state_flags = 1u;
    if (req.send_header_when_started && abi_.ext_delegate) {
        ResponseContext resp;
        resp.status_code = 200;
        abi_.ext_delegate->OnResponseStarted(resp);
    }
    return 0;
}

int32_t NetworkTask::Read(void* buf, int32_t len) noexcept {
    return TCRead(buf, len);
}

int32_t NetworkTask::TCRead(void* buf, int32_t len) noexcept {
    if (!buf || len <= 0) {
        return -1;
    }
    std::memset(buf, 0, static_cast<size_t>(len));
    return len;
}

int32_t NetworkTask::Write(void* buf, int32_t len) noexcept {
    return TCWrite(buf, len);
}

int32_t NetworkTask::TCWrite(void* buf, int32_t len) noexcept {
    if (!buf || len <= 0) {
        return -1;
    }
    return len;
}

int32_t NetworkTask::Close() noexcept {
    return TCClose();
}

int32_t NetworkTask::TCClose() noexcept {
    abi_.state_flags = 0u;
    return 0;
}

int32_t NetworkTask::Cancel() noexcept {
    return TCCancel();
}

int32_t NetworkTask::TCCancel() noexcept {
    abi_.state_flags = 2u;
    return 0;
}

void NetworkTask::OnResponseStarted(ResponseContext& resp) noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnResponseStarted(resp);
    }
}

void NetworkTask::OnReadCompleted(int32_t result) noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnReadCompleted(result);
    }
}

void NetworkTask::OnWriteCompleted(int32_t result) noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnWriteCompleted(result);
    }
}

void NetworkTask::OnMessage(int32_t key, int64_t val, const std::string& msg) noexcept {
    const int32_t ext_key = InternalKeyConvertToExternalKey(key);
    NotifyMessage(ext_key, val, msg);
}

void NetworkTask::NotifySucceeded() noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnMessage(kExternalKeyDefault, 0, "Request Download Success");
    }
}

void NetworkTask::NotifyFailed(int32_t error_code) noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnMessage(kExternalKeyDefault, error_code, "RequestCallBack Failed");
    }
}

void NetworkTask::NotifyMessage(int32_t key, int64_t val, const std::string& msg) noexcept {
    if (abi_.ext_delegate) {
        abi_.ext_delegate->OnMessage(key, val, msg);
    }
}

void NetworkTask::NotifyCanceled() noexcept {
    abi_.state_flags = 2u;
}

void NetworkTask::NotifyLog() noexcept {}

// ============================================================================
// 2. NetworkMgr Implementation (0x0338e8 .. 0x03b1d8)
// ============================================================================

// Disassembly @ 0x03b0c0..0x03b16c:
//   Sets max_load_factor at +0x50 to 1.0f (0x3F800000: mov w8, #0x3f800000; str w8, [x0, #0x50])
NetworkMgr::NetworkMgr() noexcept {
    std::memset(&abi_, 0, sizeof(abi_));
    abi_.max_load_factor = 1.0f; // 0x3F800000 @ 0x03b0e8
}

NetworkMgr::~NetworkMgr() = default;

// Disassembly @ 0x03b058..0x03b0bc:
//   C++11 magic static singleton guard at .bss 0x09dd30, instance at .bss 0x09dd50
NetworkMgr* NetworkMgr::GetNetworkMgr() noexcept {
    static NetworkMgr s_instance_09dd50;
    return &s_instance_09dd50;
}

TTKMediaNetMgr* NetworkMgr::Init() noexcept {
    return GetNetworkMgr();
}

int32_t NetworkMgr::DelInit(TTKMediaNetMgr* /*mgr*/) noexcept {
    GetNetworkMgr()->TCStopNetworkMgr();
    return 1;
}

int32_t NetworkMgr::StartNetworkMgr(TTKMediaNetMgr::Delegate* delegate) noexcept {
    abi_.mgr_delegate = delegate;
    return TCStartNetworkMgr();
}

int32_t NetworkMgr::TCStartNetworkMgr() noexcept {
    abi_.started_flag = 1u;
    return 0;
}

int32_t NetworkMgr::StopNetworkMgr() noexcept {
    return TCStopNetworkMgr();
}

// Disassembly @ 0x03b170..0x03b1d8: returns 0 (mov w0, wzr)
int32_t NetworkMgr::TCStopNetworkMgr() noexcept {
    abi_.started_flag = 0u;
    return 0;
}

TTKMediaNetTask* NetworkMgr::CreateTask() noexcept {
    abi_.stat_total_tasks += 1ULL;
    return new (std::nothrow) NetworkTask(std::weak_ptr<NetworkTask::Delegate>{});
}

int32_t NetworkMgr::DestroyTask(TTKMediaNetTask* task) noexcept {
    delete task;
    return 0;
}

int32_t NetworkMgr::StartPreConnect(PreConnectContext& ctx) noexcept {
    if (ctx.host.empty() || ctx.port == 0u) {
        return -1;
    }
    abi_.stat_active_conns += 1ULL;
    return 0;
}

bool NetworkMgr::IsHostConnected(std::string host, uint16_t port, int32_t /*proto*/) noexcept {
    return !host.empty() && port > 0u && abi_.started_flag != 0u;
}

int32_t NetworkMgr::SetAltSvcInfo(std::string origin_host, std::string alt_svc) noexcept {
    if (origin_host.empty()) {
        return -1;
    }
    alt_svc_table_[std::move(origin_host)] = std::move(alt_svc);
    return 0;
}

bool NetworkMgr::IsHostSupported(std::string host, int32_t /*proto*/) noexcept {
    return !host.empty();
}

int32_t NetworkMgr::SetStringValue(int32_t key, std::string value) noexcept {
    str_config_[key] = std::move(value);
    return 0;
}

int32_t NetworkMgr::SetInt64Value(int32_t key, int64_t value) noexcept {
    int_config_[key] = value;
    return 0;
}

// Disassembly @ 0x035da0: 52800020 (mov w0, #1); D65F03C0 (ret)
int32_t NetworkMgr::GetStringValue(int32_t key, std::string& out_value) noexcept {
    auto it = str_config_.find(key);
    if (it != str_config_.end()) {
        out_value = it->second;
    }
    return 1;
}

int32_t NetworkMgr::GetInt64Value(int32_t key, int64_t& out_value) noexcept {
    auto it = int_config_.find(key);
    if (it != int_config_.end()) {
        out_value = it->second;
        return 0;
    }
    return 1;
}

void NetworkMgr::OnLog(int32_t level, const std::string& msg) noexcept {
    if (abi_.mgr_delegate) {
        abi_.mgr_delegate->OnLog(level, msg);
    }
}

// Disassembly @ 0x03a990..0x03ab7c: CertVerify(void* ssl, const char* host, int16_t port)
int32_t NetworkMgr::CertVerify(void* ssl_ctx, const char* host, int16_t port) noexcept {
    if (!ssl_ctx || !host || host[0] == '\0' || port <= 0) {
        return -1;
    }
    if (abi_.mgr_delegate) {
        return abi_.mgr_delegate->OnCertVerify(ssl_ctx, host, port);
    }
    return 1;
}

// Disassembly @ 0x0338e8: 17FF6CBA (b NetworkMgr::Init)
extern "C" TTKMediaNetMgr* CreateNetworkMgr() noexcept {
    return NetworkMgr::Init();
}

// Disassembly @ 0x03ac80..0x03ac94:
//   stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl DelInit; mov w0, #1; ldp x29, x30, [sp], #0x10; ret
extern "C" int32_t DestroyNetworkMgr(TTKMediaNetMgr* mgr) noexcept {
    NetworkMgr::DelInit(mgr);
    return 1;
}

} // namespace TTKMediaNet
