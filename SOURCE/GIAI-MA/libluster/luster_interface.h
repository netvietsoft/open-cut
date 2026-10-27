/**
 * @file luster_interface.h
 * @brief Unified Public Clean-Room C++17 Interface for libluster.so (TASK_SO_118_libluster / TASK-127)
 *        Giao diện C++17 hợp nhất cho libluster.so (ByteDance Cloak / Terrain DEX-to-Native VM Bridge)
 */

#ifndef NEXTAI_OPENCUT_LUSTER_INTERFACE_H_
#define NEXTAI_OPENCUT_LUSTER_INTERFACE_H_

#include "luster_types.h"
#include "luster_rodata_tables.h"
#include "luster_vm_helpers.h"
#include "luster_jni_methods.h"

namespace nextai {
namespace opencut {
namespace luster {

/**
 * @brief Executes the full closed-loop self-test suite verifying:
 *        - ASLR-invariant MBA pointer decryption (-0x640958 = 0xffffffffff9bf6a8ULL)
 *        - OLLVM quadratic non-residue predicates mod 7 and mod 19
 *        - All 6 XOR-encrypted strings via sub_16328
 *        - Binary search sub_35cc over all 212 hot string indices
 *        - Registration of all 42 protected classes and 93 virtualized JNI methods via sub_4398
 *        - All 7 LusterHelperTable callbacks and JNI_OnLoad (0x00010006)
 *        Chạy kiểm thử tự động khép kín toàn diện cho libluster.so.
 */
bool RunLusterSelfVerificationSuite() noexcept;

} // namespace luster
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LUSTER_INTERFACE_H_
