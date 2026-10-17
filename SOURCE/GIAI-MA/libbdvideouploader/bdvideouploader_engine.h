/**
 * @file bdvideouploader_engine.h
 * @brief ByteDance Video Uploader - Master Engines & Native Implementation Bridges.
 *        Bộ điều phối tải lên Video/Hình ảnh và các cổng kết nối Native của libbdvideouploader.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_ENGINE_H
#define BDVIDEOUPLOADER_ENGINE_H

#include "bdvideouploader_types.h"
#include "bdvideouploader_slice_reader.h"
#include "bdvideouploader_dns_resolver.h"
#include "bdvideouploader_auth_tos.h"
#include "bdvideouploader_retry_state.h"
#include "bdvideouploader_disk_resume.h"
#include "bdvideouploader_speed_test.h"

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <atomic>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Core Video Uploader Engine Instance (BDVideoUploader)
 *        Thực thể bộ máy tải lên video chính
 */
class BDVideoUploader {
public:
    BDVideoUploader();
    ~BDVideoUploader();

    void start();
    void stop();
    void close();

    void setFilePaths(const std::vector<std::string>& paths);
    void setStringValue(int32_t key, const std::string& val);
    std::string getStringValue(int32_t key) const;
    std::string getStrByKeyAndIndex(int32_t key, int32_t index) const;

    void setIntValue(int32_t key, int32_t val);
    void setInt64Value(int32_t key, int64_t val);
    int64_t getLongValue(int32_t key) const;

    void setPoster(float timestamp);
    void setContext(const std::string& ctx);
    void setSpecifiedContentType(const std::vector<std::string>& contentTypes);

    void mergeUpload();
    void cancelUpload();

    void setListener(std::shared_ptr<IBDUploadListener> listener);

    BDUploadState getState() const;
    int64_t getUploadedBytes() const;
    int64_t getTotalBytes() const;

private:
    void executeUploadWorkflow();

    std::vector<std::string> mFilePaths;
    std::vector<std::string> mContentTypes;
    std::map<int32_t, std::string> mStrParams;
    std::map<int32_t, int32_t> mIntParams;
    std::map<int32_t, int64_t> mInt64Params;
    std::string mContextStr;
    float mPosterTimestamp;

    std::atomic<BDUploadState> mState;
    std::shared_ptr<IBDUploadListener> mListener;
    std::unique_ptr<BDSliceManager> mSliceMgr;
    std::unique_ptr<IBDFileReader> mFileReader;
    BDRetryStateMachine mRetryMachine;
    BDDiskResume mDiskResume;

    int64_t mUploadedBytes;
    int64_t mTotalBytes;
    mutable std::mutex mMutex;
};

/**
 * @brief Core Image & ImageX Uploader Engine (BDImageUploader)
 *        Bộ máy tải lên hình ảnh đơn và hàng loạt
 */
class BDImageUploader {
public:
    BDImageUploader(int32_t processType = 0);
    ~BDImageUploader();

    void start();
    void stop();
    void close();

    void setFilePaths(const std::vector<std::string>& paths);
    void setFileData(int32_t index, const uint8_t* data, size_t size);
    void setFileName(const std::vector<std::string>& names);
    void setFileStoreKeys(const std::vector<std::string>& storeKeys);
    void setFileNum(int32_t num);
    void setSpecifiedContentType(const std::vector<std::string>& types);

    void setStringValue(int32_t key, const std::string& val);
    std::string getStringValue(int32_t key) const;
    std::string getStrByKeyAndIndex(int32_t key, int32_t index) const;

    void setIntValue(int32_t key, int32_t val);
    void setInt64Value(int32_t key, int64_t val);
    int64_t getLongValue(int32_t key) const;

    void allowContinueUpload();
    void mergeUpload();
    void cancelUpload();

private:
    int32_t mProcessType;
    int32_t mFileNum;
    std::vector<std::string> mFilePaths;
    std::vector<std::string> mFileNames;
    std::vector<std::string> mStoreKeys;
    std::vector<std::vector<uint8_t>> mMemoryBuffers;
    std::map<int32_t, std::string> mStrParams;
    std::map<int32_t, int32_t> mIntParams;
    std::map<int32_t, int64_t> mInt64Params;
    std::atomic<BDUploadState> mState;
    mutable std::mutex mMutex;
};

/**
 * @brief Network Router for Dynamic Host Dispatching (BDNetworkRouter)
 *        Bộ điều hướng mạng và phân bổ tên miền tải lên động
 */
class BDNetworkRouter {
public:
    BDNetworkRouter(int32_t routerType = 0);
    ~BDNetworkRouter();

    void start();
    void stop();
    void close();

    void setStringValue(int32_t key, const std::string& val);
    void setIntValue(int32_t key, int32_t val);

    std::string getRoutedHost() const;

private:
    int32_t mRouterType;
    std::string mPrimaryHost;
    std::string mFallbackHost;
    bool mEnableQuic;
    mutable std::mutex mMutex;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_ENGINE_H
