/**
 * @file file_lock_pgl_interface.h
 * @brief ByteDance Pangle / OpenVK GeckoX FileLock Interface & Self-Test Suite Header.
 *        Giao diện tầng ngoài và bộ kiểm thử tự động cho libfile_lock_pgl.so.
 */

#ifndef GECKOX_FILE_LOCK_PGL_INTERFACE_H
#define GECKOX_FILE_LOCK_PGL_INTERFACE_H

#include "file_lock_pgl_types.h"
#include <string>

namespace nextai {
namespace opencut {
namespace filelock_pgl {

struct PglFileLockSelfTestResult {
    bool success;
    int passedStages;
    int totalStages;
    std::string stageDetails[7];
    std::string errorMessage;
};

PglFileLockSelfTestResult runSelfTest();

} // namespace filelock_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_FILE_LOCK_PGL_INTERFACE_H
