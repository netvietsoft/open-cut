/**
 * @file bdvideouploader_dns_resolver.h
 * @brief ByteDance Video Uploader - DNS Resolution & IP Dispatching Subsystem.
 *        Phân hệ phân giải tên miền DNS và điều phối địa chỉ IP máy chủ.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_DNS_RESOLVER_H
#define BDVIDEOUPLOADER_DNS_RESOLVER_H

#include "bdvideouploader_types.h"
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <chrono>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief DNS Record Entry with TTL & Quality Metrics
 *        Bản ghi DNS lưu bộ đệm kèm thời gian sống và chỉ số chất lượng
 */
struct BDDNSEntry {
    std::string hostname;
    std::vector<std::string> ipList;
    int64_t expireTimeEpochMs;
    int32_t rttMs;
    float   weight;
};

/**
 * @brief Intelligent DNS Resolver & IP Fallback Engine
 *        Bộ phân giải DNS thông minh và dự phòng địa chỉ mạng
 */
class BDDNSResolver {
public:
    static BDDNSResolver& getInstance();

    void setCustomServers(const std::vector<std::string>& servers);
    void setDefaultTimeoutMs(int32_t timeoutMs);

    /**
     * @brief Resolves hostname to list of sorted IPs
     *        Phân giải tên miền thành danh sách IP đã xếp hạng tốc độ
     */
    std::vector<std::string> resolve(const std::string& hostname);

    /**
     * @brief Inject parsed DNS result (called from Java or JNI notifyParserResult)
     *        Nạp kết quả phân giải DNS từ tầng Java qua JNI
     */
    void addCachedResult(const std::string& hostname, const std::string& ipListStr, int64_t ttlSeconds);

    /**
     * @brief Update latency metric for a specific IP
     *        Cập nhật độ trễ mạng thực tế của một IP
     */
    void updateIpLatency(const std::string& hostname, const std::string& ip, int32_t rttMs);

    void clearCache();

private:
    BDDNSResolver();
    ~BDDNSResolver() = default;

    std::vector<std::string> mCustomServers;
    int32_t mTimeoutMs;
    std::map<std::string, BDDNSEntry> mCache;
    mutable std::mutex mMutex;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_DNS_RESOLVER_H
