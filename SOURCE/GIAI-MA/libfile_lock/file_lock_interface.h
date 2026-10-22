/**
 * @file file_lock_interface.h
 * @brief ByteDance GeckoX FileLock Interface & Self-Test Suite Header.
 *        Giao diện tầng ngoài và bộ kiểm thử tự động cho libfile_lock.so.
 */

#ifndef GECKOX_FILE_LOCK_INTERFACE_H
#define GECKOX_FILE_LOCK_INTERFACE_H

#include "file_lock_types.h"
#include <string>

namespace nextai {
namespace opencut {
namespace filelock {

struct FileLockSelfTestResult {
    bool success;
    int passedStages;
    int totalStages;
    std::string stageDetails[7];
    std::string errorMessage;
};

FileLockSelfTestResult runSelfTest();

} // namespace filelock
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_INTERFACE_H
