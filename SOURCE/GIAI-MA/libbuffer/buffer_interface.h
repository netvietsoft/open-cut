/**
 * @file buffer_interface.h
 * @brief ByteDance GeckoX Native Buffer Interface & Self-Test Suite Header.
 *        Giao diện tầng ngoài và bộ kiểm thử tự động toàn diện cho libbuffer.so.
 */

#ifndef GECKOX_BUFFER_INTERFACE_H
#define GECKOX_BUFFER_INTERFACE_H

#include "buffer_types.h"
#include <string>

namespace nextai {
namespace opencut {
namespace buffer {

/**
 * @brief Self-test execution result structure
 *        Cấu trúc kết quả thực thi kiểm thử tự động
 */
struct SelfTestResult {
    bool success;
    int passedStages;
    int totalStages;
    std::string stageDetails[7];
    std::string errorMessage;
};

/**
 * @brief Run full 7-stage self-test suite for GeckoX Native Buffer
 *        Chạy trọn gói 7 giai đoạn kiểm thử tự động khép kín cho bộ đệm GeckoX
 */
SelfTestResult runSelfTest();

} // namespace buffer
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_INTERFACE_H
