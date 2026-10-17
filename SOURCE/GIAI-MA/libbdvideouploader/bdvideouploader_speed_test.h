/**
 * @file bdvideouploader_speed_test.h
 * @brief ByteDance Video Uploader - Network Speed Test & Host Optimization Subsystem.
 *        Phân hệ đo kiểm tốc độ mạng và tối ưu hóa máy chủ tiếp nhận tải lên.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_SPEED_TEST_H
#define BDVIDEOUPLOADER_SPEED_TEST_H

#include "bdvideouploader_types.h"
#include <string>
#include <vector>
#include <mutex>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Network Speed Probe & Host Ranker
 *        Bộ thăm dò tốc độ và xếp hạng máy chủ tiếp nhận tối ưu
 */
class BDNetworkSpeedTest {
public:
    BDNetworkSpeedTest();
    ~BDNetworkSpeedTest();

    void setTestHosts(const std::vector<std::string>& hosts);
    void setTestPayloadSize(size_t sizeBytes);
    void setTimeoutMs(int32_t timeoutMs);

    bool start();
    void stop();
    void close();

    /**
     * @brief Formats query parameters with best candidate host and weight
     *        Định dạng tham số URL gồm máy chủ tốt nhất và trọng số
     */
    std::string getBestHostQueryString() const;

    BDNetworkSpeedMetric getBestMetric() const;
    bool isExpired() const;

    void recordHostSpeed(const std::string& host, int64_t bytesTransferred, int64_t durationMs, int64_t rttMs);

private:
    std::vector<std::string> mCandidateHosts;
    size_t mTestPayloadSize;
    int32_t mTimeoutMs;
    bool mIsRunning;
    int64_t mCreateTimeMs;

    std::vector<BDNetworkSpeedMetric> mMetrics;
    mutable std::mutex mMutex;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_SPEED_TEST_H
