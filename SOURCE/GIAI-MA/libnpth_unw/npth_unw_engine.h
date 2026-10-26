// ============================================================================
// FILE: npth_unw_engine.h
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64)
// ROLE: Core Unwinding Engine, LSE Atomics / CPU Feature Init & Ptrace Manager
//       Động cơ giải mã ngăn xếp, Khởi tạo CPU / LSE Atomics & Quản lý Ptrace
// ============================================================================
// [EN] Reconstructs the core unwinding engine functions in `.text`:
//      - `0x003200` (`AtomicFetchAddRelaxed` — `__aarch64_ldadd8_relax`)
//      - `0x003230` (`InitLseAtomics` — `.init_array[0]`, checks `AT_HWCAP=16` bit 8
//                    and `"ro.arch"` != `"exynos9810"`, writes `.bss 0x00eaa0`)
//      - `0x0032c8` (`InitCpuFeaturesResolver` — AArch64 `hwcap` / `hwcap2` & system
//                    register `id_aa64pfr0_el1`..`id_aa64isar1_el1` bitfield mapper,
//                    writes `.bss 0x00eaa8`)
//      - `0x003700` (`InitCpuFeatures` — `.init_array[1]`, queries `AT_HWCAP=16` &
//                    `AT_HWCAP2=26`, invokes `0x0032c8`)
//      - `0x0037a0` (`AtomicFetchAddAcqRel` — `__aarch64_ldadd8_acq_rel`)
//      - `0x0037d0` (`UnwindFramesInternal` — extracts raw PCs into `uintptr_t*`)
//      - `0x0038cc` (`ExecuteUnwindCore` — configures `AndroidUnwinderData`, pushes
//                    `"libnpth_unwind.so"` & `"libnpth_unw.so"` skip maps, invokes
//                    `AndroidUnwinder::Unwind`, logs error via `__android_log_print`)
//      - `0x003ed4` (`EnsureLocalUnwinderInitialized` — `std::call_once` at `.bss 0x00eab0`
//                    calling `0x004e28` `ElfSetCachingEnabled(true)` +
//                    `SetDexCacheLimitSize(0x10000000)`, and `__cxa_guard_acquire` at
//                    `.bss 0x00eac0` constructing `g_local_unwinder` at `.bss 0x00eab8`)
//      - `0x003f7c` (`UnwindAndFormatToHeapCString` — calls `0x004008` and `strdup`)
//      - `0x004008` (`UnwindAndFormatToStdString` — unwinds, demangles, gets DEX
//                    positions, formats frames via `0x004198`, appends BuildId summary)
//      - `0x0050e0` (`PtraceAttachAndWait` — `ptrace(PTRACE_ATTACH=0x10, tid)` +
//                    `waitpid(tid, nullptr, __WALL=0x40000000)` with `EINTR=4` retry)
//      - `0x005198` (`UnwindEntireProcess` — enumerates `/proc/%d/task`, attaches all
//                    threads, formats `/proc/%d/cmdline` & `/proc/%d/comm`, unwinds all)
// [VN] Phục dựng động cơ giải mã ngăn xếp cốt lõi của `libnpth_unw.so`.
// ============================================================================

#pragma once

#include "npth_unw_elf_tree.h"
#include "npth_unw_types.h"
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {

class NpthUnwEngine {
public:
    // ------------------------------------------------------------------------
    // 1. CPU Features & LSE Atomics Initialization (`.init_array` `0x003230` & `0x003700`)
    // ------------------------------------------------------------------------
    static void InitLseAtomics(uint64_t hwcap, const char* ro_arch_prop) noexcept;
    static uint64_t ResolveAArch64CpuFeatures(uint64_t hwcap, uint64_t hwcap2, const char* ro_arch_prop) noexcept;
    static bool HaveLseAtomics() noexcept;
    static uint64_t GetCpuFeaturesBitmask() noexcept;

    // ------------------------------------------------------------------------
    // 2. Global Unwinder & Cache Initialization (`0x003ed4` & `0x004e28`)
    // ------------------------------------------------------------------------
    static constexpr size_t kDexCacheLimitSizeBytes = 0x10000000ULL; // 256 MB (@ 0x004e34)
    static constexpr size_t kDefaultMaxFrames       = 0x200ULL;      // 512 (@ 0x0037f0, 0x00402c)
    static constexpr size_t kClampedMaxFrames       = 0x100ULL;      // 256 (@ 0x00382c..0x003834, 0x004064)

    static void EnsureLocalUnwinderInitialized();
    static bool IsElfCachingEnabled() noexcept;
    static size_t GetConfiguredDexCacheLimit() noexcept;

    // ------------------------------------------------------------------------
    // 3. Core Unwind & Formatting Pipelines (`0x0037d0`, `0x0038cc`, `0x003f7c`, `0x004008`)
    // ------------------------------------------------------------------------
    static bool ExecuteUnwindCore(
        std::vector<UnwindStackFrameDataAbi>& out_frames,
        std::vector<std::string>& out_skip_libs,
        uint32_t& inout_unwind_flags,
        size_t max_frames,
        int option,
        int32_t tid,
        const UnwindStackRegistersAbi* regs);

    static size_t UnwindFramesInternal(
        uintptr_t* frames,
        size_t max_frames,
        int option,
        int32_t tid,
        const UnwindStackRegistersAbi* regs);

    static void UnwindAndFormatToStdString(
        std::string& out_trace,
        int option,
        int32_t tid,
        const UnwindStackRegistersAbi* regs);

    static char* UnwindAndFormatToHeapCString(
        int option,
        int32_t tid,
        const UnwindStackRegistersAbi* regs);

    // ------------------------------------------------------------------------
    // 4. All 23 Exported C API Implementations (`0x003e20..0x0060bc`)
    // ------------------------------------------------------------------------
    static char* UnwindCurrentOption(int option);
    static char* UnwindCurrent();
    static char* UnwindThreadOption(int32_t tid, int option);
    static char* UnwindThread(int32_t tid);
    static char* UnwindAnyThreadOption(int32_t pid, int32_t tid, int option);
    static char* UnwindAnyThread(int32_t pid, int32_t tid);
    static char* UnwindProcessOption(int32_t pid, int option);
    static char* UnwindProcess(int32_t pid);
    static char* UnwindAllOption(int option);
    static char* UnwindAll();
    static char* UnwindFastOption(int option);
    static char* UnwindFast();
    static size_t UnwindFramesOption(uintptr_t* frames, size_t max_frames, int option);
    static size_t UnwindFrames(uintptr_t* frames, size_t max_frames);
    static char* UnwindUcontextOption(void* ucontext, int option);
    static size_t UnwindUcontextFramesOption(void* ucontext, uintptr_t* frames, size_t max_frames, int option);
    static char* FormatPcsOption(const uintptr_t* pcs, size_t num_pcs, int option);
    static char* FormatPcs(const uintptr_t* pcs, size_t num_pcs);

    // ------------------------------------------------------------------------
    // 5. Offline Unwind Context Lifecycle (`0x005e34..0x0060bc`)
    // ------------------------------------------------------------------------
    static NpthUnwContext* ContextCreate(int32_t tid);
    static void ContextDestroy(NpthUnwContext* ctx);
    static void* ContextRegs(NpthUnwContext* ctx);
    static char* ContextOption(NpthUnwContext* ctx, int option);
    static size_t ContextFramesOption(NpthUnwContext* ctx, uintptr_t* frames, size_t max_frames, int option);

    // ------------------------------------------------------------------------
    // 6. Ptrace Helper (`0x0050e0..0x005180`)
    // ------------------------------------------------------------------------
    static bool PtraceAttachAndWait(int32_t tid) noexcept;
    static void PtraceDetach(int32_t tid) noexcept;
};

} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
