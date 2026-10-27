// ============================================================================
// Clean-Room C++17 Core Header for libnpth_bt.so (Target 126 / 169)
// Giao diện lõi C++17 sạch cho libnpth_bt.so (Mục tiêu 126 / 169)
// ============================================================================
#pragma once

#include "npth_bt_types.h"

namespace npth_bt {

// Checks whether an Android API level is supported by libnpth_bt.so (`sub w8, w0, #0x24; cmn w8, #0x11; b.hs`)
// Kiểm tra mức API Android có nằm trong đoạn hỗ trợ [19..35] hay không
bool IsSupportedAndroidApiLevel(int32_t api_level) noexcept;

// Resolves the 16-byte String8SymbolTable (`sub_ec8` @ 0x0ec8..0x0f84)
const String8SymbolTable16B* EnsureString8SymbolsLoaded() noexcept;

// Resolves the 40-byte CallStackSymbolTable (`0x0cfc..0x0ec0`)
const CallStackSymbolTable40B* EnsureCallStackSymbolsLoaded() noexcept;

// Resolves the 32-byte ProcessCallStackSymbolTable (`0x0fd0..0x1130`)
const ProcessCallStackSymbolTable32B* EnsureProcessCallStackSymbolsLoaded() noexcept;

// Executes any of the 358 AArch64 instructions in .text (0x0c60..0x11f8)
uint64_t ExecuteNpthBtTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept;

const uint8_t* GetNpthBtRodataBytes() noexcept;
const uint8_t* GetNpthBtEhFrameHdrBytes() noexcept;

} // namespace npth_bt

extern "C" {
// 5 Exported C Symbols in .dynsym (indices [13..17]):
// 5 biểu tượng C xuất khẩu trong bảng .dynsym ([13..17]):
char* npth_bt_thread(int32_t tid); // 0x000cb0 (536 B)
char* npth_bt_current();           // 0x000f84 (  8 B)
char* npth_bt_all();               // 0x000f8c (428 B)
void  npth_bt_free(char* bt_str);  // 0x001138 (100 B)
void  npth_bt_increase();          // 0x00119c (  4 B)
}
