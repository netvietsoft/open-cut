/**
 * @file avmdlbase_manager.h
 * @brief ByteDance Mobile Download Base - IO Manager & PlayTask Manager Implementation.
 *        Bộ quản lý tác vụ IO và điều phối PlayTask trong libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_MANAGER_H
#define AVMDLBASE_MANAGER_H

#include "avmdlbase_types.h"
#include "avmdlbase_ringbuffer.h"
#include <unordered_map>
#include <string>
#include <memory>
#include <mutex>

namespace com {
namespace ss {
namespace ttm {
namespace medialoader {

/**
 * @brief Concrete implementation of AVMDLIOTask
 *        Hiện thực lớp tác vụ tải media
 */
class AVMDLIOTaskConcrete : public AVMDLIOTask {
public:
    explicit AVMDLIOTaskConcrete(const AVMDLIOTaskInfo& info);
    ~AVMDLIOTaskConcrete() override = default;

    bool start() override;
    void cancel() override;
    void pause() override;
    void resume() override;
    AVMDLIOTaskInfo getInfo() const override;

    void updateProgress(int64_t downloaded);

private:
    AVMDLIOTaskInfo    mInfo;
    std::atomic<bool>  mIsRunning{false};
    std::atomic<bool>  mIsPaused{false};
    mutable std::mutex mTaskMutex;
};

/**
 * @brief Concrete implementation of AVMDLIOManager
 *        Hiện thực bộ điều phối Media Loader IO Manager (vtable 0x072b10).
 */
class AVMDLIOManagerImpl : public AVMDLIOManager {
public:
    static AVMDLIOManagerImpl& getInstance();

    AVMDLIOManagerImpl();
    ~AVMDLIOManagerImpl() override = default;

    void notifyTaskInfo(AVMDLIOManagerKey key,
                       AVMDLIOTask* task,
                       AVMDLIOTaskInfo& info,
                       std::map<std::string, std::string>* extraMap,
                       int64_t paramLong,
                       char* paramChar) override;

    std::string rewriteUri(const char* originUri, const char* fileKey) override;
    int32_t convertToIOTaskInfo(const char* jsonStr, AVMDLIOTaskInfo** outInfo) override;
    int32_t addTask(AVMDLIOTaskInfo& info, AVMDLIOTask* task) override;
    int32_t removeTask(AVMDLIOTask* task) override;
    AVMDLIOTask* getTask(AVMDLIOTaskInfo& info) override;
    AVMDLIOTask* getPostTask(AVMDLIOTaskInfo& info) override;
    int32_t releaseTask(AVMDLIOTask** task) override;
    int64_t getInt64Value(AVMDLIOManagerKey key, const char* strKey, int64_t defaultValue) override;
    int32_t getInfo(AVMDLIOManagerKey key, char* outBuf) override;
    void setInt64Value(AVMDLIOManagerKey key, char* strKey, int64_t value) override;
    void setStrategyCenter(AVMDLStrategyCenterListener* listener) override;
    int32_t createAndStarPreloadTask(AVMDLIOTaskInfo& info, AVMDLIOTaskListener* listener) override;
    int64_t getInt64ValueByStrStrInt(AVMDLIOManagerKey key, const char* k1, const char* k2, int64_t defVal) override;
    int32_t prepareForIOTask(AVMDLIOTaskInfo& info) override;

private:
    std::unordered_map<std::string, std::shared_ptr<AVMDLIOTask>> mTasks;
    std::unordered_map<int32_t, int64_t>                         mConfigInt64;
    AVMDLStrategyCenterListener*                                  mStrategyCenter = nullptr;
    std::mutex                                                    mManagerMutex;
};

} // namespace medialoader
} // namespace ttm

namespace ttmio {

/**
 * @brief PlayTask structure managed by MIOPlayTaskMgr
 *        Tác vụ phát video streaming được quản lý bởi MIOPlayTaskMgr
 */
struct MIOPlayTask {
    std::string fileHash;
    MIOCategory category;
    MIOPlayTaskProp prop;
    bool isPlaying = false;
    std::shared_ptr<MIORingBuffer> ringBuffer;
};

/**
 * @brief MIOPlayTaskMgr: Playback Task Manager matching binary offset 0x048200 & 0x04870c.
 *        Bộ quản lý tác vụ phát đa luồng trong libavmdlbase.so.
 */
class MIOPlayTaskMgr {
public:
    static MIOPlayTaskMgr& getInstance();

    /**
     * @brief Creates or retrieves active PlayTask for media streaming.
     *        Opcode 0x048200 (652 bytes).
     */
    std::shared_ptr<MIOPlayTask> getOrCreatePlayTask(MIOCategory category,
                                                    const std::string& fileHash,
                                                    const std::string& url,
                                                    const MIOPlayTaskProp* prop);

    /**
     * @brief Stops and releases active PlayTask.
     *        Opcode 0x04870c (592 bytes).
     */
    int32_t playStop(MIOCategory category,
                     const std::string& fileHash,
                     int32_t stopCode,
                     std::string& outDetail);

    size_t getActiveTaskCount() const noexcept;

private:
    MIOPlayTaskMgr() = default;
    ~MIOPlayTaskMgr() = default;

    std::unordered_map<std::string, std::shared_ptr<MIOPlayTask>> mActiveTasks;
    mutable std::mutex                                            mMgrMutex;
};

} // namespace ttmio
} // namespace ss
} // namespace com

#endif // AVMDLBASE_MANAGER_H
