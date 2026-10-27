// ============================================================================
// File: ttkmedianet_core.h
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Public C++17 declarations for TTKMediaNet::NetworkTask, TTKMediaNet::NetworkMgr,
//     CreateNetworkMgr, DestroyNetworkMgr, and QUIC/HTTP3 congestion control math.
// VI: Khai báo C++17 cho TTKMediaNet::NetworkTask, TTKMediaNet::NetworkMgr,
//     CreateNetworkMgr, DestroyNetworkMgr và toán học điều khiển tắc nghẽn QUIC/HTTP3.
// ============================================================================
#pragma once

#include "ttkmedianet_types.h"

namespace TTKMediaNet {

class NetworkTask : public TTKMediaNetTask {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
    };

    explicit NetworkTask(std::weak_ptr<Delegate> delegate) noexcept;
    ~NetworkTask() override;

    int32_t Open(RequestContext& req, StrategyContext& strat, TTKMediaNetTask::Delegate* ext_dlg) noexcept;
    int32_t Read(void* buf, int32_t len) noexcept;
    int32_t Write(void* buf, int32_t len) noexcept;
    int32_t Close() noexcept;
    int32_t Cancel() noexcept;

    int32_t SetStringValue(int32_t key, std::string value) noexcept;
    int32_t SetInt64Value(int32_t key, int64_t value) noexcept;
    int32_t GetStringValue(int32_t key, std::string& out_value) noexcept;
    int32_t GetInt64Value(int32_t key, int64_t& out_value) noexcept;

    void OnResponseStarted(ResponseContext& resp) noexcept;
    void OnReadCompleted(int32_t result) noexcept;
    void OnWriteCompleted(int32_t result) noexcept;
    void OnMessage(int32_t key, int64_t val, const std::string& msg) noexcept;

    int32_t TCSetStringValue(int32_t key, std::string value) noexcept;
    int32_t TCSetInt64Value(int32_t key, int64_t value) noexcept;
    int32_t TCCancel() noexcept;
    int32_t StartTask(RequestContext& req, StrategyContext& strat) noexcept;
    int32_t TCRead(void* buf, int32_t len) noexcept;
    int32_t TCWrite(void* buf, int32_t len) noexcept;
    void ResetDelegate() noexcept;
    int32_t TCClose() noexcept;
    void NotifySucceeded() noexcept;
    void NotifyFailed(int32_t error_code) noexcept;
    void NotifyMessage(int32_t key, int64_t val, const std::string& msg) noexcept;
    void NotifyCanceled() noexcept;
    void NotifyLog() noexcept;

    // Disassembly @ 0x0332b0..0x0332dc
    static int32_t InternalKeyConvertToExternalKey(int32_t internal_key) noexcept;

    const NetworkTaskAbiLayout& abi() const noexcept { return abi_; }

private:
    NetworkTaskAbiLayout abi_{};
    std::unordered_map<int32_t, std::string> str_params_;
    std::unordered_map<int32_t, int64_t> int_params_;
};

class NetworkMgr : public TTKMediaNetMgr {
public:
    NetworkMgr() noexcept;
    ~NetworkMgr() override;

    static NetworkMgr* GetNetworkMgr() noexcept;
    static TTKMediaNetMgr* Init() noexcept;
    static int32_t DelInit(TTKMediaNetMgr* mgr) noexcept;

    int32_t StartNetworkMgr(TTKMediaNetMgr::Delegate* delegate) noexcept;
    int32_t StopNetworkMgr() noexcept;
    int32_t TCStartNetworkMgr() noexcept;
    int32_t TCStopNetworkMgr() noexcept;

    TTKMediaNetTask* CreateTask() noexcept;
    int32_t DestroyTask(TTKMediaNetTask* task) noexcept;
    int32_t StartPreConnect(PreConnectContext& ctx) noexcept;
    bool IsHostConnected(std::string host, uint16_t port, int32_t proto) noexcept;
    int32_t SetAltSvcInfo(std::string origin_host, std::string alt_svc) noexcept;
    bool IsHostSupported(std::string host, int32_t proto) noexcept;

    int32_t SetStringValue(int32_t key, std::string value) noexcept;
    int32_t SetInt64Value(int32_t key, int64_t value) noexcept;
    int32_t GetStringValue(int32_t key, std::string& out_value) noexcept;
    int32_t GetInt64Value(int32_t key, int64_t& out_value) noexcept;

    void OnLog(int32_t level, const std::string& msg) noexcept;
    int32_t CertVerify(void* ssl_ctx, const char* host, int16_t port) noexcept;

    const NetworkMgrAbiLayout& abi() const noexcept { return abi_; }

private:
    NetworkMgrAbiLayout abi_{};
    std::unordered_map<int32_t, std::string> str_config_;
    std::unordered_map<int32_t, int64_t> int_config_;
    std::unordered_map<std::string, std::string> alt_svc_table_;
};

// EN: Exported C entry points at 0x0338e8 and 0x03ac80
// VI: Các điểm nhập C xuất ra tại 0x0338e8 và 0x03ac80
extern "C" TTKMediaNetMgr* CreateNetworkMgr() noexcept;
extern "C" int32_t DestroyNetworkMgr(TTKMediaNetMgr* mgr) noexcept;

// EN: QUIC / CUBIC / IACC Congestion Control & QPACK Header Table primitives
// VI: Các hàm toán học điều khiển tắc nghẽn QUIC / CUBIC / IACC & bảng QPACK
uint32_t ComputeCubicCwnd(uint32_t origin_cwnd, uint64_t elapsed_ms, uint32_t rtt_min_ms, uint32_t max_udp_payload) noexcept;
uint32_t ComputeIaccPacingRateBps(uint32_t cwnd_bytes, uint32_t srtt_us, uint32_t pacing_gain_percent, uint32_t smooth_iacc_percent) noexcept;
const char* LookupQpackStaticHeaderField(uint32_t index) noexcept;

// EN: Unified FDE router across all 1,643 AArch64 FDEs
// VI: Bộ định tuyến FDE hợp nhất trên toàn bộ 1.643 hàm AArch64 FDE
uint64_t ExecuteTtkMediaNetFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace TTKMediaNet
