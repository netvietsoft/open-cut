// ============================================================================
// File: npth_unwind_interface.h
// Target: libnpth_unwind.so (222,368 bytes, SHA-256: c83bb94dbfc0aa4b2d306a0b57ba7bd83c489dc08379cbb7f362c02fd481cad8)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Master public header for libnpth_unwind.so aggregating all 79 exported
// unwindstack C++ symbols (0x01419c..0x030354), symbol descriptor registry,
// and closed-loop parity verification entrypoints.
//
// Mô tả (VI):
// Tiêu đề công khai tổng hợp cho libnpth_unwind.so kết nối toàn bộ 79 biểu
// tượng C++ xuất khẩu trong namespace unwindstack (0x01419c..0x030354), bảng
// danh mục symbol và các hàm tự kiểm chứng đối soát khép kín.
// ============================================================================

#pragma once

#include "npth_unwind_android_unwinder.h"
#include "npth_unwind_maps_elf.h"
#include "npth_unwind_regs_dwarf.h"
#include "npth_unwind_types.h"

namespace unwindstack {

struct ExportedSymbolDescriptor {
    uint32_t vaddr;
    uint32_t size;
    const char* mangled_name;
    const char* demangled_signature;
};

// Returns all 79 exported STT_FUNC symbols in .dynsym (0x01419c..0x030354)
// Trả về danh sách đầy đủ 79 hàm STT_FUNC xuất khẩu trong .dynsym (0x01419c..0x030354)
const std::array<ExportedSymbolDescriptor, 79>& GetNpthUnwindExportedSymbols79() noexcept;

// Closed-loop parity verification suite for libnpth_unwind.so
// Bộ hàm tự kiểm chứng khép kín cho libnpth_unwind.so
bool VerifyNpthUnwindErrorCodeTableParity() noexcept;
bool VerifyNpthUnwindElfRelPcAndTbiMask() noexcept;
bool VerifyNpthUnwindRegsArm64AndUcontextParity() noexcept;
bool VerifyNpthUnwindSha256AndXzHeaderParity() noexcept;
bool VerifyNpthUnwindFormatFrameAndBuildIdParity();
bool RunAllNpthUnwindSelfTests();

} // namespace unwindstack
