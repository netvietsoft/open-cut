/**
 * @file undead_rodata_tables.h
 * @brief Exact `.rodata` (`0x0323f0..0x034f8d`, `11,165 bytes`) and `.dynsym` (`589 exports`) Tables for `libundead_native_ability_q.so`
 *        Bảng dữ liệu tĩnh `.rodata` (`0x0323f0..0x034f8d`) và bảng 589 biểu tượng xuất khẩu `.dynsym` của `libundead_native_ability_q.so`.
 */

#ifndef NEXTAI_OPENCUT_UNDEAD_RODATA_TABLES_H_
#define NEXTAI_OPENCUT_UNDEAD_RODATA_TABLES_H_

#include "undead_types.h"

namespace nextai {
namespace opencut {
namespace undead_q {

// ============================================================================
// 1. KEY `.rodata` STRINGS (`0x0323f0..0x03245c`)
//    CÁC CHUỖI `.rodata` TRỌNG YẾU TRONG ĐƯỜNG ỐNG BINDER INSTRUMENTATION
// ============================================================================

extern const char kSentinelOpenMode_0x0323f0[];            ///< 0x0323f0: "rw"
extern const char kActivityManagerDescriptor_0x0323f3[];   ///< 0x0323f3: "android.app.IActivityManager"
extern const char kBundleKeyInstrType_0x032410[];          ///< 0x032410: "instrumentation_type" (len 21 = 0x15 w/o NUL + 1)
extern const char kBundleValInstrTypeKa_0x032425[];        ///< 0x032425: "instrumentation_type_ka" (len 24 = 0x18)
extern const char kBundleKeySourceProcess_0x03243d[];      ///< 0x03243d: "source_process" (len 15 = 0x0f)
extern const char kBundleKeyUseNativeMode_0x03244c[];      ///< 0x03244c: "use_native_mode" (len 16 = 0x10)

// ============================================================================
// 2. FULL `.rodata` IMAGE (`0x0323f0..0x034f8d`, `11,165 bytes`)
//    TOÀN BỘ VÙNG NHỚ `.rodata` (`11,165 byte`)
// ============================================================================

constexpr uint32_t kUndeadRodataVaddr = 0x000323F0u;
constexpr uint32_t kUndeadRodataSize  = 11165u;
extern const uint8_t kUndeadRodataBytes_0x0323f0[11165];

// ============================================================================
// 3. FULL `.dynsym` EXPORT TABLE (`589` SYMBOLS)
//    BẢNG 589 BIỂU TƯỢNG XUẤT KHẨU `.dynsym`
// ============================================================================

constexpr size_t kUndeadExportedSymbolCount = 589u;
extern const UndeadExportedSymbol kUndeadExportedSymbols[589];

constexpr uint32_t kUndeadDataRelRoVaddr = 0x00040568u;
constexpr uint32_t kUndeadDataRelRoSize  = 12648u;
extern const uint8_t kUndeadDataRelRoBytes_0x040568[12648];

constexpr uint32_t kUndeadEhFrameHdrVaddr = 0x00034F90u;
constexpr uint32_t kUndeadEhFrameHdrSize  = 4852u;
extern const uint8_t kUndeadEhFrameHdrBytes_0x034f90[4852];

} // namespace undead_q
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_UNDEAD_RODATA_TABLES_H_
