/**
 * @file sliver_interface.cpp
 * @brief Exported Entry Point Implementation for libsliver.so (JNI_OnLoad @ 0x0039ec).
 *        Triển khai điểm vào xuất công khai cho libsliver.so (JNI_OnLoad @ 0x0039ec).
 */

#include "sliver_interface.h"

namespace bytedance {
namespace sliver {
jint RegisterSliverJniOnLoad(JavaVM* vm);
} // namespace sliver
} // namespace bytedance

extern "C" {

/**
 * @brief Export [104]: JNI_OnLoad (0x0039ec..0x003ad3).
 *        Đăng ký 12 phương thức cho com/bytedance/sliver/Sliver và 8 phương thức cho
 *        com/bytedance/sliver/SliverAllThreadSupport, trả về JNI_VERSION_1_6 (0x00010006).
 *
 * Disassembly @ 0x0039ec..0x003ad3:
 *   stp  x22, x21, [sp, #-0x30]!
 *   stp  x20, x19, [sp, #0x10]
 *   stp  x29, x30, [sp, #0x20]
 *   mov  w2, #6
 *   movk w2, #1, lsl #16         // 0x00010006 = JNI_VERSION_1_6
 *   str  x19, [x8, #0xe8]        // g_saved_java_vm = vm (.bss 0x0180e8)
 *   ...
 *   mov  w3, #0xc                // 12 methods for com/bytedance/sliver/Sliver
 *   mov  w3, #8                  // 8 methods for com/bytedance/sliver/SliverAllThreadSupport
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    return bytedance::sliver::RegisterSliverJniOnLoad(vm);
}

} // extern "C"
