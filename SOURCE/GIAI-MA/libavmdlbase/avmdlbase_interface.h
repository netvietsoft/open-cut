/**
 * @file avmdlbase_interface.h
 * @brief ByteDance Mobile Download Base - Unified Master Interface & 7-Stage Test Suite.
 *        Giao diện điều phối cấp cao và bộ kiểm thử tự thân 7 giai đoạn của libavmdlbase.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef AVMDLBASE_INTERFACE_H
#define AVMDLBASE_INTERFACE_H

#include "avmdlbase_types.h"
#include "avmdlbase_url_helper.h"
#include "avmdlbase_http_helper.h"
#include "avmdlbase_ringbuffer.h"
#include "avmdlbase_manager.h"
#include "avmdlbase_tls_quic.h"
#include <string>

namespace com {
namespace ss {
namespace avmdlbase {

/**
 * @brief Self-test execution result report
 *        Báo cáo kết quả thực thi tự kiểm tra
 */
struct AVMDLSelfTestReport {
    bool passedAll;
    int stagesPassed;
    int totalStages;
    std::string detailLog;
};

/**
 * @brief Unified Master Engine for libavmdlbase
 *        Bộ máy trung tâm điều phối tải và nạp trước media của ByteDance
 */
class ByteDanceAVMDLBaseEngine {
public:
    static ByteDanceAVMDLBaseEngine& getInstance();

    /**
     * @brief Comprehensive 7-stage self test suite
     *        Bộ tự kiểm thử toàn diện 7 giai đoạn xác minh độ chính xác 100%
     */
    AVMDLSelfTestReport runSelfTest();

private:
    ByteDanceAVMDLBaseEngine() = default;
    ~ByteDanceAVMDLBaseEngine() = default;
};

} // namespace avmdlbase
} // namespace ss
} // namespace com

#endif // AVMDLBASE_INTERFACE_H
