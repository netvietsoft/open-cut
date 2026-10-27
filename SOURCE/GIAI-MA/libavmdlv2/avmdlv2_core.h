// ============================================================================
// Clean-Room C++17 Core Interfaces for libavmdlv2.so (Target 114 / 169)
// Giao diện lõi C++17 sạch cho libavmdlv2.so (Mục tiêu 114 / 169)
// ============================================================================
#pragma once

#include "avmdlv2_types.h"

namespace com {
namespace ss {
namespace ttmio {

// Reconstructed from 0x05dacc..0x05e4cc (64 slots * 48B = 0xc00 + count_ @ +0xc00)
// Tái dựng từ 0x05dacc..0x05e4cc (64 khe * 48B = 0xc00 + biến đếm count_ tại +0xc00)
class MDLMessage {
public:
    MDLMessage();
    MDLMessage(const MDLMessage& other);
    MDLMessage& operator=(const MDLMessage& other);
    ~MDLMessage();

    bool findIntValue(const char* key, int32_t& out_val) const;
    bool findLongValue(const char* key, int64_t& out_val) const;
    bool findCStringValue(const char* key, char*& out_val) const;
    bool findPairValue(const char* key, MIOPairValue& out_val) const;
    bool findObjectValue(const char* key, MIOObject*& out_val) const;
    bool findUInt64Value(const char* key, uint64_t& out_val) const;

    void setInt32(const char* key, int32_t val);
    void setInt64(const char* key, int64_t val);
    void setString(const char* key, const char* val);
    void setPair(const char* key, MIOPairValue val);
    void setObject(const char* key, MIOObject* val);
    void setUInt64(const char* key, uint64_t val);
    bool isMember(const char* key) const;

private:
    MDLMessageSlot slots_[kMDLMessageMaxSlots];
    int32_t count_{0}; // +0xc00
};

class MIOVodNetAdapter {
public:
    explicit MIOVodNetAdapter(uint64_t session_id) : session_id_(session_id) {}
    virtual ~MIOVodNetAdapter() = default;
    virtual int32_t write(uint8_t* buf, int32_t len) { (void)buf; return len; }
    virtual bool isDataAvailable() { return true; }
    virtual int32_t read(uint8_t* buf, int32_t len, int64_t offset) { (void)buf; (void)offset; return len; }
private:
    uint64_t session_id_{0};
};

class MDLStrategyFactory {};
class MDLDownloaderFactory {
public:
    MDLDownloaderFactory() = default;
    virtual ~MDLDownloaderFactory() = default;
    void registerInnerDownloaders();
    bool hasRegistered(int32_t type) const;
};
class MDLTaskFactory {};
class MDLConfigCenter {
public:
    std::string getStrValue(int32_t key) const;
    int32_t file_mgr_v2_flag{1}; // +0x2ac
    int32_t file_mgr_ng_flag{1}; // +0x2a8
    int32_t max_event_queue{8};  // +0x56c
};
class MDLNetWorkManager {
public:
    bool isSwitchToCellularNet(const std::string& net_info) const;
};
class MDLFileManager {};
class MDLPlayInfoCache {};
class MDLThreadPool {};
class MDLRingBufferPool {};
class MDLLogManager {};
class MDLPreloadManager {};
class MDLSocketTrainingCenter {};
class MDLNetSpeedEngine {};
class MDLEventQueueFactory {};

// Reconstructed from 0x05e4cc..0x05ea18 (exact 0x78 = 120-byte layout @ .bss 0x15c1d8)
// Tái dựng từ 0x05e4cc..0x05ea18 (bố cục chuẩn 0x78 = 120 byte tại .bss 0x15c1d8)
class MDLSingletonsHolder {
public:
    MDLSingletonsHolder();
    ~MDLSingletonsHolder();

    // 0x05e848..0x05e8f0
    static MDLSingletonsHolder* getInstance();

    // 0x05e8f0..0x05e980
    void init();

    // 0x05e980..0x05ea18 (14 inline getters matching exact offsets +0x00 .. +0x70)
    MDLStrategyFactory* getStrategyFactory() const noexcept { return strategy_factory_; }       // +0x00
    MDLDownloaderFactory* getDownloaderFactory() const noexcept { return downloader_factory_; } // +0x08
    MDLTaskFactory* getTaskFactory() const noexcept { return task_factory_; }                   // +0x10
    MDLConfigCenter* getConfigCenter() const noexcept { return config_center_; }                // +0x18
    MDLNetWorkManager* getNetWorkManager() const noexcept { return network_manager_.get(); }    // +0x20
    std::shared_ptr<MDLNetWorkManager> getNetWorkManagerPtr() const noexcept { return network_manager_; } // +0x20..+0x28
    MDLFileManager* getFileManager() const noexcept { return file_manager_; }                   // +0x30
    MDLPlayInfoCache* getPlayInfoCache() const noexcept { return play_info_cache_; }            // +0x38
    MDLThreadPool* getThreadPool() const noexcept { return thread_pool_; }                      // +0x40
    MDLRingBufferPool* getBufferPool() const noexcept { return buffer_pool_; }                  // +0x48
    MDLLogManager* getLogManager() const noexcept { return log_manager_; }                      // +0x50
    MDLPreloadManager* getPreloadManager() const noexcept { return preload_manager_; }          // +0x58
    MDLSocketTrainingCenter* getSocketTrainingCenter() const noexcept { return socket_training_center_; } // +0x60
    MDLNetSpeedEngine* getNetSpeedEngine() const noexcept { return net_speed_engine_; }         // +0x68
    MDLEventQueueFactory* getEventQueueFactory() const noexcept { return event_queue_factory_; }// +0x70

private:
    MDLStrategyFactory* strategy_factory_{nullptr};           // +0x00
    MDLDownloaderFactory* downloader_factory_{nullptr};       // +0x08
    MDLTaskFactory* task_factory_{nullptr};                   // +0x10
    MDLConfigCenter* config_center_{nullptr};                 // +0x18
    std::shared_ptr<MDLNetWorkManager> network_manager_;      // +0x20..+0x28
    MDLFileManager* file_manager_{nullptr};                   // +0x30
    MDLPlayInfoCache* play_info_cache_{nullptr};              // +0x38
    MDLThreadPool* thread_pool_{nullptr};                     // +0x40
    MDLRingBufferPool* buffer_pool_{nullptr};                 // +0x48
    MDLLogManager* log_manager_{nullptr};                     // +0x50
    MDLPreloadManager* preload_manager_{nullptr};             // +0x58
    MDLSocketTrainingCenter* socket_training_center_{nullptr};// +0x60
    MDLNetSpeedEngine* net_speed_engine_{nullptr};            // +0x68
    MDLEventQueueFactory* event_queue_factory_{nullptr};      // +0x70
};

// Reconstructed from 0x0d5c60..0x0d69a4 (MDLQuicStateManager)
// Tái dựng từ 0x0d5c60..0x0d69a4 (MDLQuicStateManager)
class MDLQuicStateManager {
public:
    static MDLQuicStateManager* getInstance();
    MDLQuicStateManager() = default;
    ~MDLQuicStateManager() = default;

    bool isQuicBroken(const char* host) const;
    void resetQuicBrokenStatus();
    void markQuicBroken(const char* host);
    int64_t calAvgSpeed(const std::list<int64_t>& samples) const;

private:
    mutable std::mutex mutex_;
    std::map<std::string, bool> broken_hosts_;
    bool global_broken_{false};
};

int32_t ff_convertStatusCodeToMdlErr(int32_t http_status, bool is_https) noexcept;
bool needRedirect(int32_t http_status) noexcept;

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace ttmio
} // namespace ss
} // namespace com
