/**
 * @file keva_interface.h
 * @brief ByteDance Keva Interface & Self-Test Suite Header.
 *        Giao diện tầng ngoài và bộ kiểm thử tự động cho libkeva.so.
 */

#ifndef GECKOX_KEVA_INTERFACE_H
#define GECKOX_KEVA_INTERFACE_H

#include "keva_types.h"
#include <string>

namespace nextai {
namespace opencut {
namespace keva {

struct KevaSelfTestResult {
    bool success;
    int passedStages;
    int totalStages;
    std::string stageDetails[7];
    std::string errorMessage;
};

KevaSelfTestResult runSelfTest();

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_INTERFACE_H
