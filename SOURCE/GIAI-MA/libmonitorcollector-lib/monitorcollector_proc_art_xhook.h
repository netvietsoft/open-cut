/**
 * @file monitorcollector_proc_art_xhook.h
 * @brief Clean-Room C++17 ProcFS Collector, GraphicsMonitor, ART Heap/Stack Monitor, A64 Disassembler & xHook Engine
 *        Bộ thu thập ProcFS, GraphicsMonitor, Giám sát ART Heap/Stack, Bộ giải mã lệnh A64 & xHook C++17 Clean-Room
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x014db0..0x01701c`: `monotonicTime`, `clockTime`, `get_device_api_level`, `CollectSchedValueFd`, `CollectStateValueFd`
 * - `0x01701c..0x017828`: `GraphicsMonitor_startHook`, `getStatisticOnceData`, `parseProcLineArray`, `doReadProcFile`
 * - `0x017eb4..0x01b71c`: `initSymbolAndOffset`, `setEnableAllocatedMonitor`, `MirrorObjectCache`, `ByteBuffer`
 * - `0x01b71c..0x01cfbc`: `find_offset_by_call_a64`, `a64_get_inst_type`, `a64_get_imm`, ARM32/Thumb decoders
 * - `0x01cfbc..0x01f568`: `xhook_*` & `xh_core_*` & `xh_elf_*` ELF PLT/GOT hook engine (`libxhook 1.1.12 (aarch64)`)
 */

#pragma once

#include "monitorcollector_types.h"
#include "monitorcollector_rodata_tables.h"

namespace bytedance {
namespace monitor {
namespace collector {

int64_t MonotonicTimeImpl() noexcept;
int64_t ClockTimeImpl() noexcept;
int32_t GetDeviceApiLevelImpl() noexcept;
int64_t CurrentTimeMillsImpl() noexcept;

bool CollectSchedValueFdImpl(int fd, ThreadStatInfoNative* out_info) noexcept;
bool CollectStateValueFdImpl(const char* stat_buf, size_t len, ThreadStatInfoNative* out_info) noexcept;

bool GraphicsMonitorStartHookImpl() noexcept;
void GraphicsMonitorOpenStatisticalImpl() noexcept;
void GraphicsMonitorCloseStatisticalImpl() noexcept;
double GraphicsMonitorGetStatisticOnceDataImpl() noexcept;

bool InitArtSymbolAndOffsetImpl() noexcept;

uint32_t A64GetInstTypeImpl(uint32_t insn) noexcept;
int32_t A64GetImmImpl(uint32_t inst_type, uint32_t insn) noexcept;
int32_t FindOffsetByCallA64Impl(const uint32_t* func_start, const uint32_t* target_callee,
                                bool (*validator)(int32_t), int32_t max_insns) noexcept;

const char* XhVersionStrImpl(bool full) noexcept;

} // namespace collector
} // namespace monitor
} // namespace bytedance
