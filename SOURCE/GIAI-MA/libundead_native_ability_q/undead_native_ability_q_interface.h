/**
 * @file undead_native_ability_q_interface.h
 * @brief Unified Clean-Room C++17 Public Interface for `libundead_native_ability_q.so` (`264,448 bytes`)
 *        Giao diện công khai hợp nhất C++17 tái dựng sạch cho `libundead_native_ability_q.so` (`264,448 byte`).
 *
 * Binary Telemetry / Thông số Nhị phân (`OBSERVED`):
 *   - Library Name  : `libundead_native_ability_q.so` (ByteDance Vega UG Push Alive "Undead" Keep-Alive Native Ability for Android Q)
 *   - Exact Size    : `264,448 bytes` (`0x40900`)
 *   - SHA-256       : `fbb084a422d41746a73918169874475da9170f3aae48b099f91d83635aab3d49`
 *   - `.text`       : `0x015b10 .. 0x0323ec` (`116,956 bytes`)
 *   - `.rodata`     : `0x0323f0 .. 0x034f8d` (`11,165 bytes`)
 *   - `.init_array` : `0x040550` (`8 bytes`, entry `0x015b10`)
 *   - `.fini_array` : `0x040558` (`16 bytes`, entries `0x015b98`, `0x015b88`)
 *   - `.data.rel.ro`: `0x040568 .. 0x0436d0` (`12,648 bytes`)
 *   - `.bss`        : `0x0440b0 .. 0x0448d0` (`2,080 bytes`, `kaAbility` @ `0x0440b8`, `40 bytes` / `0x28`)
 */

#ifndef NEXTAI_OPENCUT_UNDEAD_NATIVE_ABILITY_Q_INTERFACE_H_
#define NEXTAI_OPENCUT_UNDEAD_NATIVE_ABILITY_Q_INTERFACE_H_

#include "undead_types.h"
#include "undead_rodata_tables.h"
#include "undead_ka_engine.h"
#include "undead_ndk_binder_runtime.h"

namespace nextai {
namespace opencut {
namespace undead_q {

/**
 * @brief Static binary metadata descriptor for `libundead_native_ability_q.so` (`OBSERVED`).
 *        Bộ mô tả siêu dữ liệu tĩnh của file nhị phân `libundead_native_ability_q.so` (`OBSERVED`).
 */
struct UndeadBinaryDescriptor {
    const char* library_name;
    uint32_t    file_size_bytes;
    const char* sha256_hex;
    uint32_t    text_vaddr;
    uint32_t    text_size;
    uint32_t    rodata_vaddr;
    uint32_t    rodata_size;
    uint32_t    init_array_vaddr;
    uint32_t    data_rel_ro_vaddr;
    uint32_t    data_rel_ro_size;
    uint32_t    bss_vaddr;
    uint32_t    bss_size;
    uint32_t    ka_ability_vaddr;
    uint32_t    ka_ability_size;
    uint32_t    exported_symbol_count;
};

/**
 * @brief Returns the immutable binary metadata descriptor for `libundead_native_ability_q.so`.
 *        Trả về bộ mô tả siêu dữ liệu nhị phân bất biến của `libundead_native_ability_q.so`.
 */
const UndeadBinaryDescriptor& GetUndeadBinaryDescriptor() noexcept;

/**
 * @brief Runs the deterministic mathematical and ABI self-verification suite for `libundead_native_ability_q.so`.
 *        Chạy bộ kiểm thử tự xác minh toán học và ABI tất định cho `libundead_native_ability_q.so`:
 *          1. Validates `.rodata` string offsets (`0x0323f0..0x03244c`) and `sizeof(ka_ability) == 0x28` (`40 B`).
 *          2. Validates `_GLOBAL__sub_I_undead_ability_q` (`0x015b10`), `init_instr_q` (`0x016498`),
 *             `init_instr_internal` (`0x0161c8`), `BUNDLE_MAGIC = 0x4C444E42` (`'BNDL'`), and Bundle length backpatching.
 *          3. Validates `start_instr()` (`0x016450`) and `AIBinder_transact` invocation.
 *          4. Validates the 64-bit magic reciprocal division by 1000 (`0x20C49BA5E353F7CFULL` @ `0x01608c..0x0160b0`)
 *             across boundary `tv_usec` values (`0 .. 999,999`).
 *          5. Validates `ndk::ICInterface::ICInterfaceData` (`onCreate`, `onDump`, `onDestroy`) and `StdNdk1Align_0x016cd0`.
 *
 * @return `true` if all mathematical, ABI, and `.rodata`/`.bss` invariants pass 100%; `false` otherwise.
 */
bool RunUndeadNativeAbilityQSelfTest() noexcept;

} // namespace undead_q
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_UNDEAD_NATIVE_ABILITY_Q_INTERFACE_H_
