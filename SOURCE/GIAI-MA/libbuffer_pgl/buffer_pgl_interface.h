/**
 * @file buffer_pgl_interface.h
 * @brief ByteDance Pangle / OpenVK GeckoX Native Buffer Interface & Self-Test Suite Header.
 *        Giao diện tầng ngoài và bộ kiểm thử tự động toàn diện cho libbuffer_pgl.so.
 */

#ifndef GECKOX_BUFFER_PGL_INTERFACE_H
#define GECKOX_BUFFER_PGL_INTERFACE_H

#include "buffer_pgl_types.h"
#include <string>

namespace nextai {
namespace opencut {
namespace buffer_pgl {

struct PglSelfTestResult {
    bool success;
    int passedStages;
    int totalStages;
    std::string stageDetails[7];
    std::string errorMessage;
};

PglSelfTestResult runSelfTest();

} // namespace buffer_pgl
} // namespace opencut
} // namespace nextai

#endif // GECKOX_BUFFER_PGL_INTERFACE_H
