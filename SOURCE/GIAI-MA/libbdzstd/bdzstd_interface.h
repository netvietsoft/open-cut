/**
 * @file bdzstd_interface.h
 * @brief ByteDance Zstandard Engine - Unified Master Engine Interface.
 *        Giao diện điều phối cấp cao và bộ kiểm thử tự thân 7 giai đoạn.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDZSTD_INTERFACE_H
#define BDZSTD_INTERFACE_H

#include "bdzstd_types.h"
#include "bdzstd_core.h"
#include "bdzstd_context.h"
#include "bdzstd_jni.h"
#include <string>
#include <vector>

namespace bytedance {
namespace compression {
namespace zstd {

/**
 * @brief Self-test execution result report
 *        Báo cáo kết quả thực thi tự kiểm tra
 */
struct ZstdSelfTestReport {
    bool passedAll;
    int stagesPassed;
    int totalStages;
    std::string detailLog;
};

/**
 * @brief Unified Master Engine for libbdzstd
 *        Bộ máy trung tâm điều phối nén và giải nén Zstandard của ByteDance
 */
class ByteDanceZstdEngine {
public:
    static ByteDanceZstdEngine& getInstance();

    /**
     * @brief High-level compression helper
     *        Hàm nén dữ liệu cấp cao
     */
    std::vector<uint8_t> compress(const uint8_t* data, size_t size, int level = 3, bool checksum = true);

    /**
     * @brief High-level decompression helper
     *        Hàm giải nén dữ liệu cấp cao
     */
    std::vector<uint8_t> decompress(const uint8_t* compressedData, size_t compressedSize);

    /**
     * @brief Comprehensive 7-stage self test suite
     *        Bộ tự kiểm thử toàn diện 7 giai đoạn xác minh độ chính xác 100%
     */
    ZstdSelfTestReport runSelfTest();

private:
    ByteDanceZstdEngine() = default;
    ~ByteDanceZstdEngine() = default;
};

} // namespace zstd
} // namespace compression
} // namespace bytedance

#endif // BDZSTD_INTERFACE_H
