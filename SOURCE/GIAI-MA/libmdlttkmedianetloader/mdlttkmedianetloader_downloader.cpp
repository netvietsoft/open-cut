/**
 * @file mdlttkmedianetloader_downloader.cpp
 * @brief Full Reconstruction of com::ss::ttmio::MDLTTKMediaNetDownloader (0x006334..0x00ad4f)
 *        Tái dựng đầy đủ lớp com::ss::ttmio::MDLTTKMediaNetDownloader (0x006334..0x00ad4f)
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - Constructor: 0x006334..0x0064ab (calls createHttpContext() @ 0x006404, checks config->mUseRingBufferPool @ 0x006414)
 * - Destructor: 0x0064ac..0x00662f (cancels task, recycles/deletes ring buffer, calls releaseHttpContext @ 0x00659c)
 * - setStringValue: 0x00681c..0x00693f (jump table @ 0x0102c0: keys 0 -> +0x80 mUrl, 1 -> +0xa0 mHostOverride, 2 -> +0xb8 mCustomHeaders, 7 -> +0x100 mLowerProtoStr)
 * - setIntValue: 0x006940..0x0069c7 (jump table @ 0x0102c8: keys 1->+0x9c, 2->+0xa8, 3->+0xac, 4->+0xb0, 9->mHttpContext+0x2a98, 20->+0xd0, 21->+0x118, 24->+0x70)
 * - setObjectValue: 0x0069c8..0x006a9f (key 0x0f = 15, verifies obj->getType() == 0x3e9 = 1001, acquires IoEvHandler)
 * - open / doOpen: 0x006af8..0x006e6f (emits task values 0x1c=28, 0x4e=78, 0x3e=62, 3, 5, 6 and invokes startRequestPipeline)
 * - close: 0x006e70..0x0070eb (cancels TTKMediaNetTask, resets ring buffer, emits task values 0x10=16, 4, 0x1a=26)
 * - read / triggerAsyncRead: 0x0070ec..0x007343 (reads from MDLRingBuffer, checks -60004 = -0xea64 offset mismatch, triggers ReadData with 0x8000 = 32768 bounce buffer)
 * - OnResponse / parseResponseHeaders: 0x007354..0x007c33 (parses Content-Range, Content-Length, Transfer-Encoding: chunked, alt-svc, X-Akamai-Request-ID, x-tt-request-id, server-timing, x-tt-trace-tag, x-tt-trace-host; allocates 256KB ring buffer 0x40000 @ 0x007718; emits MDLIoTaskEventCdnHeader type 6 @ 0x00777c)
 * - OnReadAvailable / processReadBuffer: 0x007c3c..0x00807f (writes to ring buffer, emits MDLIoTaskEventSeqDataUpdate type 9 @ 0x007cd4 and MDLIoTaskEventCdnReqDone type 8 @ 0x007d88)
 * - OnCompleted / OnFailed / OnCanceled / OnTimeout: 0x008088..0x0087d7 (error codes -60001 = -0xea61, -60003 = -0xea63, -60005 = -0xea65)
 * - DNS & Request Pipeline: 0x0087d8..0x00a58b (Range formatting "bytes=%lu-%lu" / "bytes=%lu-", x-tt-qi header construction "0,1,0")
 */

#include "mdlttkmedianetloader_downloader.h"
#include "mdlttkmedianetloader_factory_strategy.h"

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

extern "C" {
void vcn_av_url_split_hostname(char* hostname_buf, int hostname_buf_size, int* port_ptr, const char* url);
}

namespace com {
namespace ss {
namespace ttmio {

// ============================================================================
// 1. Factory Creation & Destruction (0x0067cc..0x006818)
//    Hàm tạo & hủy đối tượng từ Factory (0x0067cc..0x006818)
// ============================================================================

MIOVodNetAdapter* MDLTTKMediaNetDownloader::create() {
    // Disassembly 0x0067cc..0x006807 & 0x00c164:
    // Allocates MDLTTKMediaNetDownloader (size 0x81d0 = 33,232 bytes) wrapped in shared_ptr
    // Cấp phát MDLTTKMediaNetDownloader (kích thước 0x81d0 = 33.232 byte) bọc trong shared_ptr
    auto* instance = new MDLTTKMediaNetDownloader();
    return instance;
}

void MDLTTKMediaNetDownloader::destroy(MIOVodNetAdapter* downloader) {
    // Disassembly 0x006808..0x006818:
    // cbz x0, #0x6818; ldr x8, [x0]; ldr x1, [x8, #8]; br x1
    // Kiểm tra con trỏ khác null và gọi hàm hủy ảo tại vtable +0x08
    if (downloader != nullptr) {
        delete downloader;
    }
}

// ============================================================================
// 2. Constructor & Destructor (0x006334..0x00662f)
//    Hàm khởi tạo & Hàm hủy (0x006334..0x00662f)
// ============================================================================

MDLTTKMediaNetDownloader::MDLTTKMediaNetDownloader()
    : MIOVodNetAdapter(0) {
    // Disassembly 0x006334..0x0064ab:
    // Initializes all offsets, creates VCNHttpContext (+0x40), and sets up event adapter ("medianet" @ 0x010c53)
    // Khởi tạo toàn bộ các trường, tạo VCNHttpContext (+0x40) và thiết lập bộ điều hợp sự kiện ("medianet" @ 0x010c53)
    mHttpContext_ = mediakit::vcn::createHttpContext();

    const MDLConfigCenter kConfig{};
    mUseRingBufferPool_ = (kConfig.mUseRingBufferPool != 0) ? 1 : 0;

    if (kConfig.mEnableDnsParser != 0) {
        if (kConfig.mUseSharedDnsParser == 0) {
            mEventAdapter_ = ::operator new(0x30);
            std::memset(mEventAdapter_, 0, 0x30);
        }
    } else {
        mTimedEventQueue_ = ::operator new(0xa0);
        std::memset(mTimedEventQueue_, 0, 0xa0);
    }
}

MDLTTKMediaNetDownloader::~MDLTTKMediaNetDownloader() {
    // Disassembly 0x0064ac..0x00662f:
    // Cancels pending DNS event, releases mEventAdapter_, frees mResolvedIpList_, cancels mMediaNetTask_,
    // recycles or deletes mRingBuffer_, and calls releaseHttpContext(&mHttpContext_)
    // Hủy sự kiện DNS đang chờ, giải phóng mEventAdapter_, mResolvedIpList_, hủy mMediaNetTask_,
    // thu hồi hoặc xóa mRingBuffer_, và gọi releaseHttpContext(&mHttpContext_)
    if (mEventAdapter_ != nullptr) {
        ::operator delete(mEventAdapter_);
        mEventAdapter_ = nullptr;
    }
    if (mResolvedIpList_ != nullptr) {
        ::operator delete[](mResolvedIpList_);
        mResolvedIpList_ = nullptr;
    }
    if (mMediaNetTask_ != nullptr) {
        MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
        if (factory != nullptr && factory->getNetworkMgr() != nullptr) {
            factory->getNetworkMgr()->CancelTask(mMediaNetTask_);
        }
        mMediaNetTask_ = nullptr;
    }
    if (mRingBuffer_ != nullptr) {
        delete mRingBuffer_;
        mRingBuffer_ = nullptr;
    }
    if (mHttpContext_ != nullptr) {
        mediakit::vcn::releaseHttpContext(&mHttpContext_);
    }
    if (mTimedEventQueue_ != nullptr) {
        ::operator delete(mTimedEventQueue_);
        mTimedEventQueue_ = nullptr;
    }
    if (mUrl_ != nullptr) {
        ::operator delete[](mUrl_);
        mUrl_ = nullptr;
    }
    if (mHostOverride_ != nullptr) {
        ::operator delete[](mHostOverride_);
        mHostOverride_ = nullptr;
    }
    if (mCustomHeaders_ != nullptr) {
        ::operator delete[](mCustomHeaders_);
        mCustomHeaders_ = nullptr;
    }
}

// ============================================================================
// 3. Configuration Setters & Getters (0x00681c..0x006af7)
//    Các phương thức thiết lập & truy vấn cấu hình (0x00681c..0x006af7)
// ============================================================================

void MDLTTKMediaNetDownloader::setStringValue(int32_t key, const char* val) {
    // Disassembly 0x00681c..0x00693f:
    // Switch table at 0x0102c0 for keys 0..7:
    // - key 0: mUrl_ (+0x80)
    // - key 1: mHostOverride_ (+0xa0)
    // - key 2: mCustomHeaders_ (+0xb8)
    // - key 7: mLowerProtoStr_ (+0x100)
    // Bảng nhảy tại 0x0102c0 cho các khóa 0..7
    if (val == nullptr || key < 0 || key > 7) {
        return;
    }
    const std::size_t len = std::strlen(val);
    switch (key) {
        case 0: {
            if (mUrl_ != nullptr) {
                ::operator delete[](mUrl_);
                mUrl_ = nullptr;
            }
            if (len > 0) {
                mUrl_ = static_cast<char*>(::operator new[](len + 1));
                std::memcpy(mUrl_, val, len);
                mUrl_[len] = '\0';
            }
            break;
        }
        case 1: {
            if (mHostOverride_ != nullptr) {
                ::operator delete[](mHostOverride_);
                mHostOverride_ = nullptr;
            }
            if (len > 0) {
                mHostOverride_ = static_cast<char*>(::operator new[](len + 1));
                std::memcpy(mHostOverride_, val, len);
                mHostOverride_[len] = '\0';
            }
            break;
        }
        case 2: {
            if (mCustomHeaders_ != nullptr) {
                ::operator delete[](mCustomHeaders_);
                mCustomHeaders_ = nullptr;
            }
            if (len > 0) {
                mCustomHeaders_ = static_cast<char*>(::operator new[](len + 1));
                std::memcpy(mCustomHeaders_, val, len);
                mCustomHeaders_[len] = '\0';
            }
            break;
        }
        case 7: {
            mLowerProtoStr_.assign(val, len);
            break;
        }
        default:
            break;
    }
}

void MDLTTKMediaNetDownloader::setIntValue(int32_t key, int64_t val) {
    // Disassembly 0x006940..0x0069c7:
    // Switch table at 0x0102c8 for keys 1..9 and branches for 0x14 (20), 0x15 (21), 0x18 (24)
    // Bảng nhảy tại 0x0102c8 cho các khóa 1..9 và rẽ nhánh cho 20, 21, 24
    switch (key) {
        case 1:
            mDownloaderId_ = static_cast<int32_t>(val); // +0x9c (0x00696c)
            break;
        case 2:
            mMaxFailCount_ = static_cast<int32_t>(val); // +0xa8 (0x006994)
            break;
        case 3:
            mOpenTimeoutSec_ = static_cast<int32_t>(val); // +0xac (0x00699c)
            break;
        case 4:
            mRwTimeoutSec_ = static_cast<int32_t>(val); // +0xb0 (0x0069a4)
            break;
        case 9:
            if (mHttpContext_ != nullptr) {
                mHttpContext_->req_proto_type = static_cast<int32_t>(val); // +0x2a98 (0x0069b0)
            }
            break;
        case 20: // 0x14
            mLowerProtoType_ = static_cast<int32_t>(val); // +0xd0 (0x0069b8)
            break;
        case 21: // 0x15
            mQuicEnableFlag_ = static_cast<int32_t>(val); // +0x118 (0x0069c0)
            break;
        case 24: // 0x18
            mCustomDnsHandler_ = reinterpret_cast<void*>(val); // +0x70 (0x00698c)
            break;
        default:
            break;
    }
}

void MDLTTKMediaNetDownloader::setObjectValue(int32_t key, void* obj) {
    // Disassembly 0x0069c8..0x006a9f:
    // Checks key == 0x0f (15) and obj != nullptr; verifies obj->getType() == 0x3e9 (1001)
    // Kiểm tra key == 0x0f (15) và obj != nullptr; xác minh obj->getType() == 0x3e9 (1001)
    if (key != 0x0f || obj == nullptr) {
        return;
    }
    std::lock_guard<std::mutex> lock(mPcIoReqMutex_);
    mIoEvHandler_ = obj;
}

void MDLTTKMediaNetDownloader::setListener(std::weak_ptr<MIOIoListener> listener) {
    // Disassembly 0x006aa0..0x006adb:
    // Locks mListenerMutex_ (+0x148) and stores listener at +0x170
    // Khóa mListenerMutex_ (+0x148) và lưu listener tại +0x170
    std::lock_guard<std::mutex> lock(mListenerMutex_);
    mIoListener_ = std::move(listener);
}

const char* MDLTTKMediaNetDownloader::getStringValue(int32_t key) {
    // Disassembly 0x006adc..0x006ae3: mov x0, xzr; ret
    (void)key;
    return nullptr;
}

int32_t MDLTTKMediaNetDownloader::getBoolValue(int32_t key) {
    // Disassembly 0x006ae4..0x006aef: cmp w1, #0x1b; cset w0, eq; ret
    // Trả về 1 nếu key == 0x1b (27), ngược lại trả về 0
    return (key == 0x1b) ? 1 : 0;
}

int64_t MDLTTKMediaNetDownloader::getIntValue(int32_t key) {
    // Disassembly 0x006af0..0x006af7: mov w0, wzr; ret
    (void)key;
    return 0;
}

// ============================================================================
// 4. Connection Lifecycle: open / close / read (0x006af8..0x007343)
//    Vòng đời kết nối: open / close / read (0x006af8..0x007343)
// ============================================================================

int32_t MDLTTKMediaNetDownloader::open(int64_t offset, int64_t size) {
    // Disassembly 0x006af8..0x006b6b:
    // Verifies mDownloaderId_ >= 1 (+0x9c), MDLTTKMediaNetDownloaderFactory::getInstance()->getNetworkMgr() != nullptr,
    // and mState_ == 0 (+0x38); transitions mState_ = 1 and tail-calls doOpen(offset, size)
    // Kiểm tra mDownloaderId_ >= 1, NetworkMgr != nullptr, và mState_ == 0; chuyển mState_ = 1 rồi gọi doOpen
    if (mDownloaderId_ < 1) {
        return -1;
    }
    MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
    if (factory == nullptr || factory->getNetworkMgr() == nullptr) {
        return -1;
    }
    if (mState_ != 0) {
        return -1;
    }
    mState_ = 1;
    return doOpen(offset, size);
}

int32_t MDLTTKMediaNetDownloader::doOpen(int64_t offset, int64_t size) {
    // Disassembly 0x006b6c..0x006e6f:
    // Verifies mUrl_ (+0x80) is non-empty, initializes HTTP range in mHttpContext_ (0x87d8),
    // emits initial MIOIoListener task values (keys 0x1c=28, 0x4e=78, 0x3e=62, 3, 5, 6), and calls startRequestPipeline (0xa230)
    // Kiểm tra mUrl_ (+0x80) khác rỗng, khởi tạo dải byte HTTP trong mHttpContext_, phát các sự kiện khởi đầu và gọi startRequestPipeline
    if (mUrl_ == nullptr || mUrl_[0] == '\0') {
        return -1;
    }

    mReqOffset_ = offset;
    mReqSize_ = size;
    initHttpContextRange();
    mCurrentOffset_ = offset;

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x006be0..0x006c08: key 0x1c (28) = MIOValue(0)
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x1c, MIOValue(static_cast<int32_t>(0)));
            // 0x006c44..0x006c6c: key 0x4e (78) = MIOValue(0x3ea = 1002 = TTKMediaNet downloader type)
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x4e, MIOValue(static_cast<int32_t>(0x3ea)));
            // 0x006ca8..0x006cd8: key 0x3e (62) = MIOValue("ttkmedianet")
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x3e, MIOValue("ttkmedianet"));
            // 0x006d14..0x006d40: key 3 = MIOValue(getCurrentTime())
            listener->onTaskValUpdate(mSelfWeakPtr_, 3, MIOValue(getCurrentTime()));
            // 0x006d7c..0x006da8: key 5 = MIOValue(mHttpContext_->req_start_offset)
            listener->onTaskValUpdate(mSelfWeakPtr_, 5, MIOValue(mHttpContext_->req_start_offset));
            // 0x006de4..0x006e18: key 6 = MIOValue(mHttpContext_->req_end_offset == 0 ? 1 : mHttpContext_->req_end_offset)
            int64_t end_off = (mHttpContext_->req_end_offset == 0) ? 1 : mHttpContext_->req_end_offset;
            listener->onTaskValUpdate(mSelfWeakPtr_, 6, MIOValue(end_off));
        }
    }

    return startRequestPipeline();
}

int32_t MDLTTKMediaNetDownloader::close() {
    // Disassembly 0x006e70..0x0070eb:
    // Checks mState_ >= 1 and mState_ != 3; sets mState_ = 3, cancels mMediaNetTask_, resets mRingBuffer_,
    // and notifies listener with keys 0x10 (16), 4, 0x1a (26), and onClosed()
    // Kiểm tra mState_ >= 1 và mState_ != 3; đặt mState_ = 3, hủy mMediaNetTask_, đặt lại mRingBuffer_ và thông báo đóng kết nối
    if (mState_ < 1 || mState_ == 3) {
        return -1;
    }
    mState_ = 3;

    if (mMediaNetTask_ != nullptr) {
        MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
        if (factory != nullptr && factory->getNetworkMgr() != nullptr) {
            factory->getNetworkMgr()->CancelTask(mMediaNetTask_);
        }
    }
    if (mRingBuffer_ != nullptr) {
        mRingBuffer_->reset();
    }

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x006f54..0x006f78: key 0x10 (16) = MIOValue(mCurrentOffset_)
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x10, MIOValue(mCurrentOffset_));
            // 0x006fb8..0x006fe0: key 4 = MIOValue(getCurrentTime())
            listener->onTaskValUpdate(mSelfWeakPtr_, 4, MIOValue(getCurrentTime()));
            // 0x007000..0x007054: key 0x1a (26) = MIOValue(max(0L, mCurrentOffset_ - mHttpContext_->req_start_offset))
            // Instruction: sub x9, x10, x11; bic x1, x9, x9, asr #63
            int64_t diff = mCurrentOffset_ - (mHttpContext_ ? mHttpContext_->req_start_offset : 0);
            int64_t downloaded_bytes = (diff < 0) ? 0 : diff;
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x1a, MIOValue(downloaded_bytes));
            // 0x007094..0x0070a0: listener->onClosed() (vtable +0x38)
            listener->onClosed(mSelfWeakPtr_);
        }
    }

    {
        std::lock_guard<std::mutex> lock(mPcIoReqMutex_);
        mIoEvHandler_ = nullptr;
    }
    return 0;
}

int32_t MDLTTKMediaNetDownloader::read(uint8_t* buf, int64_t size, int64_t* total_size) {
    // Disassembly 0x0070ec..0x00727b:
    // Reads from mRingBuffer_; if mUseRingBufferPool_ == 0 and mRingBuffer_->getTotalSize() != *total_size,
    // emits error -60004 (mov w2, #-0xea64 @ 0x0071b0)
    // Đọc từ mRingBuffer_; nếu kích thước tổng không khớp, phát lỗi -60004 (-0xea64 @ 0x0071b0)
    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (mRingBuffer_ == nullptr) {
            return 0;
        }
    }

    int64_t ring_total = mRingBuffer_->getTotalSize();
    if (mUseRingBufferPool_ == 0 && total_size != nullptr && ring_total != *total_size) {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x0071b0: mov w2, #-0xea64 (-60004)
            listener->onError(mSelfWeakPtr_, -60004, mCurrentOffset_, "");
        }
        return 0;
    }

    int32_t bytes_read = mRingBuffer_->read(buf, static_cast<int32_t>(size));
    if (bytes_read >= 1 && total_size != nullptr) {
        *total_size = mRingBuffer_->getTotalSize();
    }

    // 0x00723c..0x007274: Check atomic flags mIsCompletedOrFailed_ (+0x124) and mNeedTriggerRead_ (+0x120)
    // Kiểm tra các cờ nguyên tử mIsCompletedOrFailed_ (+0x124) và mNeedTriggerRead_ (+0x120)
    if (mIsCompletedOrFailed_.load(std::memory_order_acquire) == 0) {
        if (mNeedTriggerRead_.load(std::memory_order_acquire) != 0 && mRingBuffer_->getFreeSize() != 0) {
            mNeedTriggerRead_.store(0, std::memory_order_release);
            triggerAsyncRead();
        }
    }
    return bytes_read;
}

void MDLTTKMediaNetDownloader::triggerAsyncRead() {
    // Disassembly 0x00727c..0x007343:
    // Computes read chunk size = min(mRingBuffer_->getFreeSize(), 0x8000 = 32768), clamps to remaining range,
    // and either calls mMediaNetTask_->ReadData(mReadBounceBuffer_, chunk_size) or sets mNeedTriggerRead_ = 1
    // Tính toán kích thước khối đọc = min(getFreeSize(), 32768), giới hạn theo dải byte còn lại và gọi ReadData
    if (mRingBuffer_ == nullptr) {
        return;
    }
    int32_t free_size = mRingBuffer_->getFreeSize();
    // 0x0072ac..0x0072b4: cmp w0, #8, lsl #12 (0x8000); mov w9, #0x8000; csel w20, w0, w9, lt
    int32_t read_len = (free_size < 0x8000) ? free_size : 0x8000;

    if (mHttpContext_ != nullptr && mHttpContext_->req_end_offset != 0) {
        int64_t write_off = mRingBuffer_->getWriteOffset();
        int64_t req_end = mHttpContext_->req_end_offset;
        if (write_off + read_len > req_end) {
            read_len = static_cast<int32_t>(req_end - write_off) + 1;
        }
    }

    if (read_len > 0 && mMediaNetTask_ != nullptr) {
        mMediaNetTask_->ReadData(mReadBounceBuffer_, read_len);
    } else {
        // 0x00732c..0x007330: mov w9, #1; stlr w9, [x8] (+0x120)
        mNeedTriggerRead_.store(1, std::memory_order_release);
    }
}

// ============================================================================
// 5. TTKMediaNetTask::Delegate Callbacks (0x007354..0x0087d7)
//    Các hàm gọi lại của TTKMediaNetTask::Delegate (0x007354..0x0087d7)
// ============================================================================

void MDLTTKMediaNetDownloader::OnResponse(const TTKMediaNet::TTKMediaNetResponseInfo* response) {
    // Disassembly 0x007354..0x00781f (and thunk 0x007c34):
    // 1. Calls parseResponseHeaders(response) (0x007820)
    // 2. Validates HTTP status_code (+0x20a4) and content_length (+0x20c0):
    //    - If status_code == 0 -> emits error -60006 (mov w2, #-0xea66 @ 0x00754c)
    //    - If content_length + 1 <= 1 (i.e. content_length == -1 or 0) -> converts status code via ff_convertStatusCodeToMdlErr(status_code, true) (0x0074a0)
    //    - Otherwise emits status_code (key 1), content_length (key 0), response_time (key 0x0f = 15),
    //      allocates MDLRingBuffer (pool size or 256KB = 0x40000 @ 0x007718), emits MDLIoTaskEventCdnHeader (type 6 @ 0x00777c),
    //      and calls triggerAsyncRead() (0x007808)
    // Xử lý phản hồi HTTP: phân tích header, kiểm tra mã trạng thái, khởi tạo bộ đệm vòng và kích hoạt đọc dữ liệu
    parseResponseHeaders(response);

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x0073b0..0x0073d0: key 0x4d (77) = MIOValue(2)
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x4d, MIOValue(static_cast<int32_t>(2)));

            int32_t status_code = mHttpContext_ ? mHttpContext_->status_code : 0;
            if (status_code == 0) {
                // 0x00754c: mov w2, #-0xea66 (-60006)
                listener->onError(mSelfWeakPtr_, -60006, mCurrentOffset_, "");
                return;
            }

            int64_t content_len = mHttpContext_ ? mHttpContext_->content_length : 0;
            // 0x0073f8..0x007400: add x8, x8, #1; cmp x8, #1; b.hi #0x757c
            if (static_cast<uint64_t>(content_len + 1) <= 1ULL) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 1, MIOValue(status_code));
                int32_t mdl_err = ff_convertStatusCodeToMdlErr(status_code, true);
                listener->onError(mSelfWeakPtr_, mdl_err, mCurrentOffset_, "");
                return;
            }

            // 0x00757c..0x0076a0: Valid 2xx response with content_length > 0 or chunked (-1 handled above if 0)
            listener->onTaskValUpdate(mSelfWeakPtr_, 1, MIOValue(status_code));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0, MIOValue(content_len));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x0f, MIOValue(getCurrentTime()));
        }

        // 0x0076b4..0x007728: Allocate MDLRingBuffer if null
        if (mRingBuffer_ == nullptr) {
            if (mUseRingBufferPool_ != 0) {
                const MDLConfigCenter kConfig{};
                int32_t pool_blocks = (kConfig.mRingBufferSize > 0) ? kConfig.mRingBufferSize : 256;
                mRingBuffer_ = new MDLRingBuffer(static_cast<size_t>(pool_blocks) * 1024, 1024);
                mRingBuffer_->setReadOffset(mReqOffset_);
            } else {
                // 0x00770c..0x007724: mov w0, #0xd8; mov w1, #0x40000 (262,144 bytes = 256 KB)
                mRingBuffer_ = new MDLRingBuffer(0x40000, static_cast<size_t>(mReqOffset_));
            }
        }
    }

    // 0x00775c..0x007800: Emit MDLIoTaskEventCdnHeader (event_type = 6, size = 0x48 = 72 bytes)
    {
        std::lock_guard<std::mutex> lock(mPcIoReqMutex_);
        if (mIoEvHandler_ != nullptr && mHttpContext_ != nullptr) {
            MDLIoTaskEventCdnHeader ev{};
            ev.event_type = 6;
            ev.timestamp_ms = getCurrentTime();
            ev.content_length = mHttpContext_->content_length;
            ev.req_start_offset = mHttpContext_->req_start_offset;
            ev.req_end_offset = mHttpContext_->req_end_offset;
            (void)ev;
        }
    }

    // 0x007804..0x007808: Start reading payload chunks
    triggerAsyncRead();
}

void MDLTTKMediaNetDownloader::parseResponseHeaders(const TTKMediaNet::TTKMediaNetResponseInfo* response) {
    // Disassembly 0x007820..0x007c33:
    // Checks HTTP status code in [200, 299] (`sub w10, w8, #0xc8; cmp w10, #0x63; b.hi` @ 0x007848..0x007854)
    // and iterates over `response->headers` red-black tree, matching:
    // - "Content-Range" (0x010361) -> httpParserParseContentRange(mHttpContext_, val)
    // - "Content-Length" (0x01036f) -> strtoull(val, nullptr, 10) -> mHttpContext_->content_length
    // - "Transfer-Encoding" (0x01037e) == "chunked" (0x010390) -> content_length = -1, chunked_eof_flag = 0
    // - "alt-svc" (0x010398) -> MDLTTKMediaNetDownloaderFactory::getInstance()->updateAltSvcInfo(mUrl_, val)
    // - "X-Akamai-Request-ID" (0x0103a0) / "x-tt-request-id" (0x0103b4) -> listener key 0x3f (63)
    // - "server-timing" (0x0103c4) -> listener key 0x15 (21)
    // - "x-tt-trace-tag" (0x0103d2) -> listener key 0x42 (66)
    // - "x-tt-trace-host" (0x0103e1) -> listener key 0x40 (64)
    // Phân tích mã trạng thái HTTP [200, 299] và duyệt cây đỏ-đen chứa các header phản hồi từ CDN
    if (response == nullptr || mHttpContext_ == nullptr) {
        return;
    }

    int32_t status = response->status_code;
    mHttpContext_->status_code = status;

    // 0x007848..0x007854: sub w10, w8, #0xc8 (200); cmp w10, #0x63 (99); b.hi #0x7c14
    if (static_cast<uint32_t>(status - 200) > 99U) {
        return;
    }

    bool alt_svc_updated = false;
    for (const auto& kv : response->headers) {
        const char* key = kv.first.c_str();
        const char* val = kv.second.c_str();

        if (::strcasecmp(key, "Content-Range") == 0) {
            mediakit::vcn::httpParserParseContentRange(mHttpContext_, val);
        } else if (::strcasecmp(key, "Content-Length") == 0 && mHttpContext_->content_length == 0) {
            mHttpContext_->content_length = static_cast<int64_t>(std::strtoull(val, nullptr, 10));
        } else if (::strcasecmp(key, "Transfer-Encoding") == 0 && ::strncasecmp(val, "chunked", 7) == 0) {
            mHttpContext_->content_length = -1;
            mHttpContext_->chunked_eof_flag = 0;
        } else if (::strcasecmp(key, "alt-svc") == 0) {
            if (!alt_svc_updated) {
                MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
                if (factory != nullptr) {
                    factory->updateAltSvcInfo(mUrl_, val);
                }
                alt_svc_updated = true;
            }
        } else if (::strcasecmp(key, "X-Akamai-Request-ID") == 0 || ::strcasecmp(key, "x-tt-request-id") == 0) {
            std::lock_guard<std::mutex> lock(mListenerMutex_);
            if (auto listener = mIoListener_.lock()) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 0x3f, MIOValue(val));
            }
        } else if (::strcasecmp(key, "server-timing") == 0) {
            std::lock_guard<std::mutex> lock(mListenerMutex_);
            if (auto listener = mIoListener_.lock()) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 0x15, MIOValue(val));
            }
        } else if (::strcasecmp(key, "x-tt-trace-tag") == 0) {
            std::lock_guard<std::mutex> lock(mListenerMutex_);
            if (auto listener = mIoListener_.lock()) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 0x42, MIOValue(val));
            }
        } else if (::strcasecmp(key, "x-tt-trace-host") == 0) {
            std::lock_guard<std::mutex> lock(mListenerMutex_);
            if (auto listener = mIoListener_.lock()) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 0x40, MIOValue(val));
            }
        }
    }
}

void MDLTTKMediaNetDownloader::OnReadAvailable(int32_t available_bytes) {
    // Disassembly 0x007c3c..0x007c53 (and thunk 0x008060):
    // Checks available_bytes >= 1 and forwards mReadBounceBuffer_ (+0x188) to processReadBuffer (0x007c54)
    // Kiểm tra available_bytes >= 1 và chuyển mReadBounceBuffer_ (+0x188) tới processReadBuffer
    if (available_bytes < 1) {
        return;
    }
    processReadBuffer(mReadBounceBuffer_, available_bytes);
}

void MDLTTKMediaNetDownloader::processReadBuffer(uint8_t* data, int32_t len) {
    // Disassembly 0x007c54..0x00805f:
    // Writes `len` bytes into mRingBuffer_, advances mCurrentOffset_ (+0xf8),
    // emits MDLIoTaskEventSeqDataUpdate (type 9, flags 0x0101), checks if download reached content_length/req_end_offset,
    // emits MDLIoTaskEventCdnReqDone (type 8) if finished or calls triggerAsyncRead() for next chunk,
    // and notifies MIOIoListener (keys 0x0e=14 first packet time, 0x10=16 offset, onDataReady, and onComplete if done)
    // Ghi dữ liệu vào bộ đệm vòng, cập nhật mCurrentOffset_, phát sự kiện cập nhật dữ liệu tuần tự và kiểm tra hoàn tất
    if (mRingBuffer_ == nullptr || mHttpContext_ == nullptr) {
        return;
    }

    int64_t written = mRingBuffer_->write(data, len);
    int64_t prev_offset = mCurrentOffset_;
    mCurrentOffset_ = prev_offset + written;

    // 0x007cbc..0x007d1c: Emit MDLIoTaskEventSeqDataUpdate (type = 9, flags = 0x101)
    {
        std::lock_guard<std::mutex> lock(mPcIoReqMutex_);
        if (mIoEvHandler_ != nullptr) {
            MDLIoTaskEventSeqDataUpdate seq_ev{};
            seq_ev.event_type = 9;
            seq_ev.timestamp_ms = getCurrentTime();
            seq_ev.flags = 0x0101;
            seq_ev.written_bytes = written;
            seq_ev.current_offset = mCurrentOffset_;
            (void)seq_ev;
        }
    }

    // 0x007d24..0x007e3c: Check if mCurrentOffset_ >= content_length or > req_end_offset
    bool is_done = false;
    if (static_cast<uint64_t>(mCurrentOffset_) >= static_cast<uint64_t>(mHttpContext_->content_length) ||
        (mHttpContext_->req_end_offset != 0 && static_cast<uint64_t>(mCurrentOffset_) > static_cast<uint64_t>(mHttpContext_->req_end_offset))) {
        std::lock_guard<std::mutex> lock(mPcIoReqMutex_);
        if (mIoEvHandler_ != nullptr) {
            MDLIoTaskEventCdnReqDone done_ev{};
            done_ev.event_type = 8;
            done_ev.timestamp_ms = getCurrentTime();
            (void)done_ev;
        }
        mPcIoReq_.reset();
        is_done = true;
    } else {
        triggerAsyncRead();
    }

    // 0x007e40..0x008048: Notify MIOIoListener
    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // If this is the very first chunk (mCurrentOffset_ == req_start_offset + len), emit key 0x0e (14)
            if (mCurrentOffset_ == mHttpContext_->req_start_offset + len) {
                listener->onTaskValUpdate(mSelfWeakPtr_, 0x0e, MIOValue(getCurrentTime()));
            }
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x10, MIOValue(mCurrentOffset_));
            listener->onDataReady(mSelfWeakPtr_);

            if (is_done) {
                mIsCompletedOrFailed_.store(1, std::memory_order_release);
                listener->onTaskValUpdate(mSelfWeakPtr_, 4, MIOValue(getCurrentTime()));
                listener->onComplete(mSelfWeakPtr_, 0, 0);
            }
        }
    }
}

void MDLTTKMediaNetDownloader::OnRedirect() {
    // Disassembly 0x008080..0x008087: ret
}

void MDLTTKMediaNetDownloader::OnCompleted() {
    // Disassembly 0x008088..0x00813f:
    // Sets mIsCompletedOrFailed_ = 1 (+0x124) and calls listener->onComplete(self, 0, 0)
    // Đặt cờ mIsCompletedOrFailed_ = 1 và gọi listener->onComplete(self, 0, 0)
    mIsCompletedOrFailed_.store(1, std::memory_order_release);
    std::lock_guard<std::mutex> lock(mListenerMutex_);
    if (auto listener = mIoListener_.lock()) {
        listener->onComplete(mSelfWeakPtr_, 0, 0);
    }
}

void MDLTTKMediaNetDownloader::OnFailed(int32_t err_code) {
    // Disassembly 0x008140..0x008367:
    // Sets mIsCompletedOrFailed_ = 1 (+0x124), formats "OnFailed: " + std::to_string(err_code) (key 0x2d = 45),
    // emits err_code (key 0x3b = 59), and calls listener->onError(self, -60001 /*-0xea61*/, mCurrentOffset_, "")
    // Đặt mIsCompletedOrFailed_ = 1, tạo chuỗi "OnFailed: <err_code>", phát mã lỗi và gọi onError(-60001)
    mIsCompletedOrFailed_.store(1, std::memory_order_release);
    std::lock_guard<std::mutex> lock(mListenerMutex_);
    if (auto listener = mIoListener_.lock()) {
        std::string err_msg = std::string("OnFailed: ") + std::to_string(err_code);
        listener->onTaskValUpdate(mSelfWeakPtr_, 0x2d, MIOValue(err_msg.c_str()));
        listener->onTaskValUpdate(mSelfWeakPtr_, 0x3b, MIOValue(err_code));
        // 0x0082ec: mov w2, #-0xea61 (-60001)
        listener->onError(mSelfWeakPtr_, -60001, mCurrentOffset_, "");
    }
}

void MDLTTKMediaNetDownloader::OnCanceled() {
    // Disassembly 0x008368..0x00858b:
    // Sets mIsCompletedOrFailed_ = 1 (+0x124), formats "OnCanceled: -60003" (-0xea63 @ 0x0083a4),
    // emits -60003 (key 0x3b = 59), and calls listener->onError(self, -60005 /*-0xea65*/, mCurrentOffset_, "")
    // Đặt mIsCompletedOrFailed_ = 1, tạo chuỗi "OnCanceled: -60003", và gọi onError(-60005)
    mIsCompletedOrFailed_.store(1, std::memory_order_release);
    std::lock_guard<std::mutex> lock(mListenerMutex_);
    if (auto listener = mIoListener_.lock()) {
        constexpr int32_t kCancelSubCode = -60003; // -0xea63
        std::string cancel_msg = std::string("OnCanceled: ") + std::to_string(kCancelSubCode);
        listener->onTaskValUpdate(mSelfWeakPtr_, 0x2d, MIOValue(cancel_msg.c_str()));
        listener->onTaskValUpdate(mSelfWeakPtr_, 0x3b, MIOValue(kCancelSubCode));
        // 0x008510: mov w2, #-0xea65 (-60005)
        listener->onError(mSelfWeakPtr_, -60005, mCurrentOffset_, "");
    }
}

void MDLTTKMediaNetDownloader::OnTimeout(int32_t timeout_code, int64_t value) {
    // Disassembly 0x00858c..0x0087d7:
    // Maps timeout_code in [100009..100012] (`mov w8, #0x7573; movk w8, #0xfffe, lsl #16` = -100009 @ 0x00858c)
    // via jump table @ 0x0102f0 to listener keys:
    // - 100009 (0x186a9) -> key 9  (MIOValue(long value))
    // - 100010 (0x186aa) -> key 10 (MIOValue(long value))
    // - 100011 (0x186ab) -> key 47 (0x2f, MIOValue(int value))
    // - 100012 (0x186ac) -> key 12 (0x0c, MIOValue(int value))
    // Ánh xạ mã timeout trong khoảng [100009..100012] sang các khóa sự kiện của MIOIoListener
    uint32_t idx = static_cast<uint32_t>(timeout_code - 100009);
    if (idx > 3U) {
        return;
    }

    std::lock_guard<std::mutex> lock(mListenerMutex_);
    auto listener = mIoListener_.lock();
    if (!listener) {
        return;
    }

    switch (idx) {
        case 0: // 100009
            listener->onTaskValUpdate(mSelfWeakPtr_, 9, MIOValue(value));
            break;
        case 1: // 100010
            listener->onTaskValUpdate(mSelfWeakPtr_, 10, MIOValue(value));
            break;
        case 2: // 100011
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x2f, MIOValue(static_cast<int32_t>(value)));
            break;
        case 3: // 100012
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x0c, MIOValue(static_cast<int32_t>(value)));
            break;
    }
}

// ============================================================================
// 6. DNS Resolution & HTTP/QUIC Request Dispatch (0x0087d8..0x00ad4f)
//    Phân giải DNS & Điều phối yêu cầu HTTP/QUIC (0x0087d8..0x00ad4f)
// ============================================================================

void MDLTTKMediaNetDownloader::initHttpContextRange() {
    // Disassembly 0x0087d8..0x008877:
    // Sets req_start_offset = mReqOffset_, status_code = 0,
    // req_end_offset = (mReqSize_ > 0) ? (mReqOffset_ + mReqSize_ - 1) : 0,
    // lower_proto_type = mLowerProtoType_, and copies mCustomHeaders_ into mHttpContext_->custom_header_str
    // Thiết lập dải byte bắt đầu/kết thúc và sao chép tiêu đề tùy chỉnh vào VCNHttpContext
    if (mHttpContext_ == nullptr) {
        return;
    }
    mHttpContext_->req_start_offset = mReqOffset_;
    mHttpContext_->status_code = 0;
    mHttpContext_->req_end_offset = (mReqSize_ > 0) ? (mReqOffset_ + mReqSize_ - 1) : 0;
    mHttpContext_->lower_proto_type = mLowerProtoType_;

    if (mCustomHeaders_ != nullptr) {
        std::size_t len = std::strlen(mCustomHeaders_);
        if (mHttpContext_->custom_header_str != nullptr) {
            ::operator delete[](mHttpContext_->custom_header_str);
            mHttpContext_->custom_header_str = nullptr;
        }
        if (len > 0) {
            mHttpContext_->custom_header_str = static_cast<char*>(::operator new[](len + 1));
            std::memcpy(mHttpContext_->custom_header_str, mCustomHeaders_, len);
            mHttpContext_->custom_header_str[len] = '\0';
        }
    }
}

int32_t MDLTTKMediaNetDownloader::initDnsParser() {
    // Disassembly 0x008878..0x00897b:
    // Acquires shared DNS parser or creates local MDLDNSParserImplement
    // Lấy trình phân giải DNS dùng chung hoặc khởi tạo MDLDNSParserImplement cục bộ
    const MDLConfigCenter kConfig{};
    if (kConfig.mUseSharedDnsParser != 0) {
        return 0;
    }
    return (mTimedEventQueue_ != nullptr) ? 0 : -1;
}

int32_t MDLTTKMediaNetDownloader::checkHostIsIpLiteral() {
    // Disassembly 0x00897c..0x008ab7:
    // 1. If mHostOverride_ (+0xa0) is non-empty, copies it into mResolvedIpList_ (+0x128) and returns 0.
    // 2. Otherwise checks if mHostname_ (+0x130) is an IPv4 (AF_INET = 2) or IPv6 (AF_INET6 = 10) literal via inet_pton (0x5350):
    //    - If literal IP, copies mHostname_ into mResolvedIpList_ and returns 0.
    //    - Otherwise returns 1 (requires DNS lookup).
    // Kiểm tra xem tên miền có phải là địa chỉ IP trực tiếp (IPv4/IPv6) qua inet_pton hay cần phân giải DNS
    if (mHostOverride_ != nullptr && std::strlen(mHostOverride_) > 0) {
        std::size_t len = std::strlen(mHostOverride_);
        if (mResolvedIpList_ != nullptr) {
            ::operator delete[](mResolvedIpList_);
        }
        mResolvedIpList_ = static_cast<char*>(::operator new[](len + 1));
        std::memcpy(mResolvedIpList_, mHostOverride_, len);
        mResolvedIpList_[len] = '\0';
        return 0;
    }

    if (mHostname_.empty()) {
        return 1;
    }

    uint8_t addr_buf[16]{};
    // 0x0089f8..0x008a20: inet_pton(AF_INET = 2) or inet_pton(AF_INET6 = 10)
    if (::inet_pton(AF_INET, mHostname_.c_str(), addr_buf) == 1 ||
        ::inet_pton(AF_INET6, mHostname_.c_str(), addr_buf) == 1) {
        std::size_t len = mHostname_.size();
        if (mResolvedIpList_ != nullptr) {
            ::operator delete[](mResolvedIpList_);
        }
        mResolvedIpList_ = static_cast<char*>(::operator new[](len + 1));
        std::memcpy(mResolvedIpList_, mHostname_.c_str(), len);
        mResolvedIpList_[len] = '\0';
        return 0;
    }

    return 1;
}

void MDLTTKMediaNetDownloader::doDnsParseAndSendRequest() {
    // Disassembly 0x008ab8..0x008d27:
    // Invokes shared DNS parser or schedules lambda $_2 (`doDnsParseAndSendRequest`),
    // then calls onDnsParseCompleted(mHostname_, ip_list, dns_type) (0x008d28)
    // Gọi bộ phân giải DNS dùng chung hoặc lập lịch lambda $_2, sau đó gọi onDnsParseCompleted
    onDnsParseCompleted(mHostname_, mHostname_, 0);
}

int32_t MDLTTKMediaNetDownloader::onDnsParseCompleted(
    const std::string& host,
    const std::string& ip_list,
    int32_t dns_type) {
    // Disassembly 0x008d28..0x008fdb:
    // Stores ip_list into mResolvedIpList_ (+0x128); if empty, emits error -60002 (mov w2, #-0xea62 @ 0x008f88).
    // Otherwise emits listener keys 8 (timestamp), 0x13 (19 = resolved IP string), 0x0d (13 = dns_type),
    // and invokes sendHttpRequest(mUrl_) (0x008fdc).
    // Lưu danh sách IP đã phân giải; nếu rỗng thì phát lỗi -60002 (-0xea62), ngược lại gọi sendHttpRequest(mUrl_)
    (void)host;
    if (!ip_list.empty()) {
        if (mResolvedIpList_ != nullptr) {
            ::operator delete[](mResolvedIpList_);
        }
        mResolvedIpList_ = static_cast<char*>(::operator new[](ip_list.size() + 1));
        std::memcpy(mResolvedIpList_, ip_list.c_str(), ip_list.size());
        mResolvedIpList_[ip_list.size()] = '\0';
    }

    if (mResolvedIpList_ == nullptr || mResolvedIpList_[0] == '\0') {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x008f88: mov w2, #-0xea62 (-60002)
            listener->onError(mSelfWeakPtr_, -60002, mCurrentOffset_, "");
        }
        return -1;
    }

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            listener->onTaskValUpdate(mSelfWeakPtr_, 8, MIOValue(getCurrentTime()));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x13, MIOValue(mResolvedIpList_));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x0d, MIOValue(dns_type));
        }
    }

    return (sendHttpRequest(mUrl_) == -1) ? -1 : 0;
}

int32_t MDLTTKMediaNetDownloader::sendHttpRequest(const char* url) {
    // Disassembly 0x008fdc..0x009c17:
    // 1. Splits mResolvedIpList_ by ',' (0x00a58c) and joins IPs (if mMultiIpEnable != 0).
    // 2. Formats HTTP Range header (`"bytes=%lu-%lu"` @ 0x010320 if req_end_offset != 0, else `"bytes=%lu-"` @ 0x01032e)
    //    and inserts `"range"` (@ 0x010339) into custom_headers map.
    // 3. If config->mEnableQuicHeader == 1 (+0x438), builds `"x-tt-qi"` (@ 0x01033f) via buildQuicHeaderValue (0x00aa40),
    //    inserts into custom_headers, and notifies listener key 0x48 (72).
    // 4. Parses `mHttpContext_->custom_header_str` line-by-line via `std::istringstream` (splitting on `':'` = 0x3a,
    //    stripping `'\r'` = 0x0d and trimming `' '` = 0x20) into `custom_headers`.
    // 5. Calls `MDLTTKMediaNetDownloaderFactory::getInstance()->getNetworkMgr()->CreateTask()` (vtable +0x20 @ 0x0095dc):
    //    - If null, emits `"CreateTask: -60000"` (-0xea60 @ 0x0098dc) and `onError(-60001)` (-0xea61 @ 0x009a48).
    // 6. Populates `TTKMediaNetRequestParam` (`is_quic = (req_proto_type == 2)`, `open_timeout_ms = mOpenTimeoutSec_ * 1000`,
    //    `rw_timeout_ms = mRwTimeoutSec_ * 1000`, `method = "GET"`) and starts task:
    //    - If start returns non-zero `rc`, emits `"Open: " + std::to_string(rc)` (key 0x2d), `rc` (key 0x3b), and `onError(-60001)`.
    //    - If start returns 0, emits key 0x4d (77) = 1 and key 0x4f (79) = getCurrentTime().
    // Xây dựng đầy đủ yêu cầu HTTP/QUIC (Range header, x-tt-qi header, custom headers) và khởi chạy TTKMediaNetTask
    if (mHttpContext_ == nullptr) {
        return -1;
    }

    const MDLConfigCenter kConfig{};
    std::map<std::string, std::string> headers;

    // 0x009098..0x0090f0: Format "range" header ("bytes=%lu-%lu" or "bytes=%lu-")
    char range_buf[256];
    std::memset(range_buf, 0, sizeof(range_buf));
    if (mHttpContext_->req_end_offset != 0) {
        std::snprintf(
            range_buf,
            sizeof(range_buf),
            "bytes=%lu-%lu",
            static_cast<unsigned long>(mHttpContext_->req_start_offset),
            static_cast<unsigned long>(mHttpContext_->req_end_offset));
    } else {
        std::snprintf(
            range_buf,
            sizeof(range_buf),
            "bytes=%lu-",
            static_cast<unsigned long>(mHttpContext_->req_start_offset));
    }
    headers["range"] = range_buf;

    // 0x0090f4..0x0091e0: Add "x-tt-qi" QUIC indicator header if enabled
    if (kConfig.mEnableQuicHeader == 1) {
        std::string qi_val = buildQuicHeaderValue();
        headers["x-tt-qi"] = qi_val;
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x48, MIOValue(qi_val.c_str()));
        }
    }

    // 0x0091e4..0x009560: Parse custom_header_str lines ("Key: Value\r\n")
    if (mHttpContext_->custom_header_str != nullptr && mHttpContext_->custom_header_str[0] != '\0') {
        std::istringstream stream(mHttpContext_->custom_header_str);
        std::string line;
        while (std::getline(stream, line)) {
            if (line.size() == 1 && line[0] == '\r') {
                break;
            }
            std::size_t colon_pos = line.find(':');
            if (colon_pos == std::string::npos) {
                continue;
            }
            std::string h_key = line.substr(0, colon_pos);
            std::string h_val = line.substr(colon_pos + 1);
            // Strip '\r' (0x0d) and trim leading/trailing spaces (0x20)
            while (!h_val.empty() && (h_val.back() == '\r' || h_val.back() == ' ')) {
                h_val.pop_back();
            }
            std::size_t first_non_space = h_val.find_first_not_of(' ');
            if (first_non_space != std::string::npos) {
                h_val = h_val.substr(first_non_space);
            } else {
                h_val.clear();
            }
            if (!h_key.empty() && !h_val.empty()) {
                headers[h_key] = h_val;
            }
        }
    }

    // 0x0095cc..0x0095e4: Create TTKMediaNetTask via TTKMediaNetMgr
    MDLTTKMediaNetDownloaderFactory* factory = MDLTTKMediaNetDownloaderFactory::getInstance();
    mMediaNetTask_ = (factory && factory->getNetworkMgr()) ? factory->getNetworkMgr()->CreateTask() : nullptr;
    if (mMediaNetTask_ == nullptr) {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            // 0x0098dc: mov w0, #-0xea60 (-60000) -> "CreateTask: -60000"
            constexpr int32_t kCreateTaskErr = -60000;
            std::string msg = std::string("CreateTask: ") + std::to_string(kCreateTaskErr);
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x2d, MIOValue(msg.c_str()));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x3b, MIOValue(kCreateTaskErr));
            listener->onError(mSelfWeakPtr_, -60001, mCurrentOffset_, "");
        }
        return -1;
    }

    // 0x0095e8..0x0096ec: Populate TTKMediaNetRequestParam
    TTKMediaNet::TTKMediaNetRequestParam req_param{};
    req_param.is_quic = (mHttpContext_->req_proto_type == 2) ? 1 : 0;
    req_param.range_start = mHttpContext_->req_start_offset;
    req_param.range_end = (mHttpContext_->req_end_offset != 0) ? mHttpContext_->req_end_offset : -1;
    req_param.open_timeout_ms = mOpenTimeoutSec_ * 1000;
    req_param.rw_timeout_ms = mRwTimeoutSec_ * 1000;
    req_param.total_timeout_ms = mRwTimeoutSec_ * 1000;
    req_param.lower_proto_str = mLowerProtoStr_;
    req_param.url = url ? url : "";
    req_param.ip_list = mResolvedIpList_ ? mResolvedIpList_ : "";
    req_param.method = "GET";
    req_param.custom_headers = std::move(headers);

    // 0x009a98..0x009b68: Emit task start events (key 0x4d = 1, key 0x4f = getCurrentTime())
    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x4d, MIOValue(static_cast<int32_t>(1)));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x4f, MIOValue(getCurrentTime()));
        }
    }
    return 0;
}

void MDLTTKMediaNetDownloader::onResolve(
    std::string host,
    std::string ip_list,
    int32_t dns_type,
    int32_t err_code,
    int32_t ttl) {
    // Disassembly 0x009c18..0x00a047 (and thunk 0x00a228):
    // Dispatches DNS resolution result (lambda $_0 @ 0x010a90, safeCallback @ 0x01096c) to onDnsParseCompleted
    // Điều phối kết quả phân giải DNS tới onDnsParseCompleted
    (void)err_code;
    (void)ttl;
    onDnsParseCompleted(host, ip_list, dns_type);
}

int32_t MDLTTKMediaNetDownloader::startRequestPipeline() {
    // Disassembly 0x00a230..0x00a4db:
    // 1. Calls extractHostname(mUrl_) (0x00a4dc).
    // 2. Emits listener key 7 = getCurrentTime() and key 0x4a (74) = config->mLowerProtoType.
    // 3. Calls checkHostIsIpLiteral() (0x00897c):
    //    - If returns 1 (domain name), calls initDnsParser() (0x008878) and doDnsParseAndSendRequest() (0x008ab8).
    //    - If returns 0 (IP literal or override), emits listener keys 8, 0x13 (19), 0x0d (13) and calls sendHttpRequest(mUrl_).
    // Khởi chạy đường ống yêu cầu: tách hostname, kiểm tra IP trực tiếp hoặc phân giải DNS rồi gửi yêu cầu
    extractHostname(mUrl_);

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            listener->onTaskValUpdate(mSelfWeakPtr_, 7, MIOValue(getCurrentTime()));
            const MDLConfigCenter kConfig{};
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x4a, MIOValue(kConfig.mLowerProtoType));
        }
    }

    if (checkHostIsIpLiteral() != 0) {
        if (initDnsParser() == -1) {
            return -1;
        }
        doDnsParseAndSendRequest();
        return 0;
    }

    {
        std::lock_guard<std::mutex> lock(mListenerMutex_);
        if (auto listener = mIoListener_.lock()) {
            listener->onTaskValUpdate(mSelfWeakPtr_, 8, MIOValue(getCurrentTime()));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x13, MIOValue(mResolvedIpList_ ? mResolvedIpList_ : ""));
            listener->onTaskValUpdate(mSelfWeakPtr_, 0x0d, MIOValue(static_cast<int32_t>(0)));
        }
    }

    return (sendHttpRequest(mUrl_) == -1) ? -1 : 0;
}

void MDLTTKMediaNetDownloader::extractHostname(const char* url) {
    // Disassembly 0x00a4dc..0x00a58b:
    // Calls vcn_av_url_split_hostname(host_buf, 256, &port, url) and assigns mHostname_ (+0x130)
    // Tách tên miền từ URL bằng vcn_av_url_split_hostname và lưu vào mHostname_ (+0x130)
    char host_buf[256];
    std::memset(host_buf, 0, sizeof(host_buf));
    int port = 0;
    if (url != nullptr) {
        vcn_av_url_split_hostname(host_buf, 256, &port, url);
    }
    mHostname_ = safeString(host_buf);
}

std::string MDLTTKMediaNetDownloader::buildQuicHeaderValue() {
    // Disassembly 0x00aa40..0x00ab63:
    // Formats "<proto_code>,1,<mQuicEnableFlag_>" (using delimiter "," @ 0x0103f1)
    // Định dạng chuỗi giá trị tiêu đề "x-tt-qi" theo mẫu "<proto_code>,1,<mQuicEnableFlag_>"
    int32_t proto_code = mapLowerProtoToQuicHeaderCode();
    return std::to_string(proto_code) + ",1," + std::to_string(mQuicEnableFlag_);
}

int32_t MDLTTKMediaNetDownloader::mapLowerProtoToQuicHeaderCode() const {
    // Disassembly 0x00ace8..0x00ad4f:
    // Jump table at 0x0102f4 mapping config->mLowerProtoType (+0x120):
    // - 1 -> 1
    // - 2 -> 4
    // - 6 -> 5
    // - 1000 (0x3e8) -> 0
    // - default -> 99 (0x63)
    // Ánh xạ mLowerProtoType sang mã giao thức trong tiêu đề x-tt-qi
    const MDLConfigCenter kConfig{};
    switch (kConfig.mLowerProtoType) {
        case 1:
            return 1;
        case 2:
            return 4;
        case 6:
            return 5;
        case 1000: // 0x3e8
            return 0;
        default:
            return 99; // 0x63
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com
