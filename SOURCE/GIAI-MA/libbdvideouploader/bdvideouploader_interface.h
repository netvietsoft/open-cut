/**
 * @file bdvideouploader_interface.h
 * @brief ByteDance Video Uploader - Master Orchestration Interface & 7-Stage Test Suite.
 *        Giao diện điều phối cấp cao và bộ kiểm thử tự thân 7 giai đoạn của libbdvideouploader.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDVIDEOUPLOADER_INTERFACE_H
#define BDVIDEOUPLOADER_INTERFACE_H

#include "bdvideouploader_types.h"
#include "bdvideouploader_engine.h"
#include <string>

namespace com {
namespace ss {
namespace bduploader {

/**
 * @brief Self-test Execution Result Report
 *        Báo cáo kết quả kiểm thử tự thân
 */
struct BDUploaderSelfTestReport {
    bool passedAll;
    int stagesPassed;
    int totalStages;
    std::string detailLog;
};

/**
 * @brief Master Engine Coordinator for libbdvideouploader.so
 *        Bộ điều phối trung tâm toàn bộ phân hệ tải lên đa phương tiện ByteDance
 */
class ByteDanceVideoUploaderEngine {
public:
    static ByteDanceVideoUploaderEngine& getInstance();

    /**
     * @brief Comprehensive 7-stage closed-loop self-test suite
     *        Bộ tự kiểm thử toàn diện 7 giai đoạn xác minh độ chính xác 100%
     */
    BDUploaderSelfTestReport runSelfTest();

private:
    ByteDanceVideoUploaderEngine() = default;
    ~ByteDanceVideoUploaderEngine() = default;
};

} // namespace bduploader
} // namespace ss
} // namespace com

#endif // BDVIDEOUPLOADER_INTERFACE_H
