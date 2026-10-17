// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Storage Security Engine
// Target Library: libfile_recorder.so (com.bytedance.osfix.disk.jni.JniNative)
// Component: Async Storage Worker & Math Engine (Opcode 0x3cfc, 0x1e1c, 0x1d5c)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FILE_RECORDER_WORKER_H
#define NEXTAI_OPENCUT_FILE_RECORDER_WORKER_H

#include "file_recorder_types.h"
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

namespace NextAI {
namespace OpenCut {
namespace FileRecorder {

/**
 * @brief Background Storage Worker & File Metrics Engine.
 * Luồng nền xử lý thống kê truy cập tệp và công cụ số học lưu trữ.
 * 
 * Reconstructed from:
 * - 0x004364: worker_thread_starter (pthread allocation)
 * - 0x0045e4: worker_thread_entry
 * - 0x003cfc: worker_thread_main_loop (deque queue, sentinel handling)
 * - 0x001e1c: nativeModifyTime (smulh with 0x431bde82d7b634db)
 * - 0x001d5c: nativeIsFileInUse (fcntl / exclusive lock check)
 * - 0x001ecc: nativeRootPath (monitored directory list)
 * - 0x001f98: nativeRootLevel (scan depth limit)
 * - 0x002064: nativeTimeForCount (reporting interval ms)
 */
class StorageWorkerEngine {
public:
    StorageWorkerEngine();
    ~StorageWorkerEngine();

    /**
     * @brief Start the asynchronous processing worker thread (opcode 0x004364).
     * Khởi động luồng công nhân xử lý bất đồng bộ.
     */
    void start();

    /**
     * @brief Post a file path to the processing queue.
     * Đưa một đường dẫn tệp vào hàng đợi xử lý.
     */
    void enqueuePath(const std::string& path);

    /**
     * @brief Stop worker thread using the binary's sentinel string (opcode 0x003df8).
     * Dừng luồng công nhân bằng chuỗi sentinel chuẩn xác của nhị phân (___terminate_thread_work___).
     */
    void stop();

    /**
     * @brief Test whether a file is currently in use/locked (opcode 0x001d5c).
     * Kiểm tra xem một tệp hiện có đang được mở/khóa hay không.
     */
    bool isFileInUse(const std::string& path);

    /**
     * @brief Set file modification time using fixed-point arithmetic (opcode 0x001e1c).
     * Cập nhật thời gian sửa đổi tệp sử dụng phép nhân số học điểm cố định.
     */
    bool modifyTime(const std::string& path);

    /**
     * @brief Configure root directories for scanning (opcode 0x001ecc).
     * Cấu hình danh sách thư mục gốc cần quét.
     */
    void setRootPaths(const std::vector<std::string>& paths);

    /**
     * @brief Configure maximum directory recursion level (opcode 0x001f98).
     * Cấu hình độ sâu đệ quy tối đa của thư mục.
     */
    void setRootLevels(const std::vector<int32_t>& levels);

    /**
     * @brief Set cycle interval timer in milliseconds (opcode 0x002064).
     * Thiết lập chu kỳ kiểm tra tính toán theo mili giây.
     */
    void setTimeForCount(int64_t interval_ms);

    /**
     * @brief Retrieve count of processed paths by background thread.
     * Lấy số lượng đường dẫn đã được xử lý bởi luồng nền.
     */
    size_t getProcessedCount() const { return m_processed_count; }

    /**
     * @brief Retrieve current pending queue size.
     * Lấy kích thước hàng đợi đang chờ xử lý.
     */
    size_t getQueueSize();

    /**
     * @brief Mathematical parity verification for time conversion:
     * Computes (val * 0x431bde82d7b634db) >> (64 + 18) simulating AArch64 smulh + asr #18.
     * Xác minh số học chuyển đổi thời gian: mô phỏng chính xác lệnh AArch64 smulh + asr #18.
     */
    static int64_t computeFixedPointTimeDivision(int64_t input_ns_or_us);

    /**
     * @brief Query tracked access counts per path.
     * Truy vấn số lần truy cập được theo dõi cho từng đường dẫn.
     */
    int32_t getPathAccessCount(const std::string& path);

    /**
     * @brief Reset all internal storage.
     * Đặt lại toàn bộ bộ nhớ trong.
     */
    void reset();

private:
    void workerLoop();

    std::mutex m_queue_mutex;
    std::condition_variable m_cv;
    std::deque<std::string> m_queue; ///< deque queue matching opcode 0x3d80
    std::thread m_worker_thread;
    std::atomic<bool> m_running{false};
    std::atomic<size_t> m_processed_count{0};

    std::mutex m_state_mutex;
    std::vector<std::string> m_root_paths;
    std::vector<int32_t> m_root_levels;
    int64_t m_time_for_count_ms{1000};
    std::unordered_map<std::string, int32_t> m_access_counts;
};

} // namespace FileRecorder
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_FILE_RECORDER_WORKER_H
