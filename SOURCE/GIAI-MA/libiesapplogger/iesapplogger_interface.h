/**
 * @file iesapplogger_interface.h
 * @brief IESAppLogger::AppLogTracker & AppLogTracker::Impl Declarations for libiesapplogger.so
 *        Khai báo IESAppLogger::AppLogTracker & AppLogTracker::Impl cho libiesapplogger.so
 *
 * Reconstructed from .text addresses 0x005878..0x0083f0 (.dynsym [048..121]).
 * Tái dựng từ các địa chỉ .text 0x005878..0x0083f0 (.dynsym [048..121]).
 */

#ifndef NEXTAI_OPENCUT_IESAPPLOGGER_INTERFACE_H_
#define NEXTAI_OPENCUT_IESAPPLOGGER_INTERFACE_H_

#include "iesapplogger_reporter_jni.h"
#include "iesapplogger_rbtree_stl.h"
#include "iesapplogger_types.h"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace IESAppLogger {

/**
 * @brief Reconstructs `IESAppLogger::AppLogTracker` (8-byte pImpl wrapper) and
 *        `IESAppLogger::AppLogTracker::Impl` (80-byte = `0x50` implementation class).
 *        Tái dựng lớp `IESAppLogger::AppLogTracker` (lớp bọc pImpl 8 byte) và
 *        lớp nội bộ `IESAppLogger::AppLogTracker::Impl` (80 byte = `0x50`).
 */
class AppLogTracker {
public:
    class Impl {
    public:
        /**
         * @brief Reconstructs `Impl(const std::string& appId, const std::string& eventName, bool checkSample)`
         *        at 0x005878..0x0059ac (.dynsym [069, 077]).
         *        Allocates/initializes 80-byte (`0x50`) layout, reserves 512 bytes (`0x200`) for `json_buffer_`,
         *        initializes `json_buffer_` to `"{"` (`0x00c48b`), and checks `AppLogReporter::isSampled` if `checkSample`.
         *        Tái dựng hàm tạo `Impl(appId, eventName, checkSample)` tại 0x005878..0x0059ac (.dynsym [069, 077]).
         */
        Impl(const std::string& app_id, const std::string& event_name, bool check_sample);

        /**
         * @brief Reconstructs `Impl(const char* appId, const char* eventName, bool checkSample)`
         *        at 0x0059d0..0x005b2c (.dynsym [103, 121]).
         *        Tái dựng hàm tạo `Impl(const char*, const char*, bool)` tại 0x0059d0..0x005b2c (.dynsym [103, 121]).
         */
        Impl(const char* app_id, const char* event_name, bool check_sample);

        ~Impl();

        // Scalar putVal overloads (0x005da8..0x006fb8)
        // Các hàm nạp chồng putVal vô hướng (0x005da8..0x006fb8)
        void putVal(const std::string& key, int val);            // 0x005da8 (.dynsym [085])
        void putVal(const char* key, int val);                   // 0x005fd8 (.dynsym [111])
        void putVal(const std::string& key, long val);           // 0x006024 (.dynsym [074])
        void putVal(const char* key, long val);                  // 0x006254 (.dynsym [066])
        void putVal(const std::string& key, unsigned long val);  // 0x0062a0 (.dynsym [089])
        void putVal(const char* key, unsigned long val);         // 0x0064d0 (.dynsym [075])
        void putVal(const std::string& key, float val);          // 0x00651c (.dynsym [076])
        void putVal(const char* key, float val);                 // 0x00674c (.dynsym [064])
        void putVal(const std::string& key, double val);         // 0x006798 (.dynsym [104])
        void putVal(const char* key, double val);                // 0x0069c8 (.dynsym [071])
        void putVal(const std::string& key, const std::string& val); // 0x006a14 (.dynsym [106])
        void putVal(const char* key, const std::string& val);    // 0x006ce8 (.dynsym [072])
        void putVal(const std::string& key, const char* val);    // 0x006d34 (.dynsym [088])
        void putVal(const char* key, const char* val);           // 0x006fb8 (.dynsym [087])

        // Array / Vector putVals overloads (0x006ffc..0x008388)
        // Các hàm nạp chồng putVals mảng / vector (0x006ffc..0x008388)
        void putVals(const std::string& key, int count, int* vals);           // 0x006ffc (.dynsym [108])
        void putVals(const std::string& key, int count, long* vals);          // 0x0072e4 (.dynsym [078])
        void putVals(const std::string& key, int count, unsigned long* vals); // 0x00765c (.dynsym [063])
        void putVals(const std::string& key, int count, float* vals);         // 0x0079d4 (.dynsym [110])
        void putVals(const std::string& key, int count, double* vals);        // 0x007d4c (.dynsym [118])
        void putVals(const std::string& key, const std::vector<std::string>& vals); // 0x0080c4 (.dynsym [048])

        // Accessors to the 80-byte ABI struct
        // Các hàm truy cập cấu trúc ABI 80 byte
        iesapplogger::AppLogTrackerImplAbi* rawAbi() noexcept { return &abi_; }
        const iesapplogger::AppLogTrackerImplAbi* rawAbi() const noexcept { return &abi_; }

        std::string appIdString() const;
        std::string eventNameString() const;
        std::string jsonBufferString() const;

    private:
        void appendCommaIfNeeded();

        iesapplogger::AppLogTrackerImplAbi abi_;
    };

    // Constructors & Destructor (0x005b50..0x005da4)
    // Các hàm khởi tạo & hàm hủy (0x005b50..0x005da4)
    AppLogTracker(const std::string& app_id, const std::string& event_name, bool check_sample = false); // 0x005b50 (.dynsym [093, 098])
    AppLogTracker(const char* app_id, const char* event_name, bool check_sample = false);               // 0x005bc0 (.dynsym [082, 091])
    ~AppLogTracker();                                                                                   // 0x005c28 (.dynsym [079, 086])

    AppLogTracker(const AppLogTracker&) = delete;
    AppLogTracker& operator=(const AppLogTracker&) = delete;

    // Chained scalar putVal methods returning *this (0x005fd8..0x006ff8)
    // Các phương thức putVal vô hướng trả về *this (0x005fd8..0x006ff8)
    AppLogTracker& putVal(const std::string& key, int val);            // 0x005fd8 (.dynsym [111])
    AppLogTracker& putVal(const char* key, int val);                   // 0x006008 (.dynsym [105])
    AppLogTracker& putVal(const std::string& key, long val);           // 0x006254 (.dynsym [066])
    AppLogTracker& putVal(const char* key, long val);                  // 0x006284 (.dynsym [097])
    AppLogTracker& putVal(const std::string& key, unsigned long val);  // 0x0064d0 (.dynsym [075])
    AppLogTracker& putVal(const char* key, unsigned long val);         // 0x006500 (.dynsym [081])
    AppLogTracker& putVal(const std::string& key, float val);          // 0x00674c (.dynsym [064])
    AppLogTracker& putVal(const char* key, float val);                 // 0x00677c (.dynsym [070])
    AppLogTracker& putVal(const std::string& key, double val);         // 0x0069c8 (.dynsym [071])
    AppLogTracker& putVal(const char* key, double val);                // 0x0069f8 (.dynsym [096])
    AppLogTracker& putVal(const std::string& key, const std::string& val); // 0x006ce8 (.dynsym [072])
    AppLogTracker& putVal(const char* key, const std::string& val);    // 0x006d18 (.dynsym [094])
    AppLogTracker& putVal(const std::string& key, const char* val);    // 0x006fb8 (.dynsym [087])
    AppLogTracker& putVal(const char* key, const char* val);           // 0x006fe0 (.dynsym [113])

    // Chained array/vector putVals methods returning *this (0x0072b4..0x008388)
    // Các phương thức putVals mảng/vector trả về *this (0x0072b4..0x008388)
    AppLogTracker& putVals(const std::string& key, int count, int* vals);           // 0x0072b4 (.dynsym [080])
    AppLogTracker& putVals(const std::string& key, int count, long* vals);          // 0x00762c (.dynsym [100])
    AppLogTracker& putVals(const std::string& key, int count, unsigned long* vals); // 0x0079a4 (.dynsym [095])
    AppLogTracker& putVals(const std::string& key, int count, float* vals);         // 0x007d1c (.dynsym [067])
    AppLogTracker& putVals(const std::string& key, int count, double* vals);        // 0x008094 (.dynsym [120])
    AppLogTracker& putVals(const std::string& key, const std::vector<std::string>& vals); // 0x008388 (.dynsym [068])

    // Static & instance control methods (0x00838c..0x0083f0)
    // Các phương thức điều khiển tĩnh & thực thể (0x00838c..0x0083f0)
    static void enableAllReports();                                    // 0x00838c (.dynsym [119])
    static void disableAllReports();                                   // 0x0083a8 (.dynsym [084])
    void setReportToBusiness(bool to_business) noexcept;               // 0x0083c0 (.dynsym [117])
    static bool isSampled(const std::string& event_name);              // 0x0083d0 (.dynsym [101])

    Impl* impl() noexcept { return impl_; }
    const Impl* impl() const noexcept { return impl_; }

private:
    Impl* impl_;  // +0x00: 8-byte pImpl pointer (`ldr x0, [x0]` @ 0x005fe4, 0x0083c0)
};

}  // namespace IESAppLogger

#endif  // NEXTAI_OPENCUT_IESAPPLOGGER_INTERFACE_H_
