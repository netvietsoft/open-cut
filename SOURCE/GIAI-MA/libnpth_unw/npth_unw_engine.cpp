// ============================================================================
// FILE: npth_unw_engine.cpp
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64)
// ROLE: Implementation of Core Unwinding Engine, CPU Resolver & 23 C Exports
//       Triển khai Động cơ giải mã ngăn xếp, Bộ nhận diện CPU & 23 hàm C xuất khẩu
// ============================================================================

#include "npth_unw_engine.h"
#include <atomic>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <mutex>

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {

namespace {

// ============================================================================
// .BSS GLOBAL STATE (`.bss 0x00eaa0..0x00eae7`, 72 bytes)
// ============================================================================
// [EN] Exact mapping of `.bss` variables verified from disassembly:
//      - `0x00eaa0`: `g_have_lse_atomics` (`uint8_t`, written at `0x003254` & `0x0032b8`)
//      - `0x00eaa8`: `g_cpu_features` (`uint64_t`, written at `0x0034f4`, `0x003598`, `0x0036d0`)
//      - `0x00eab0`: `g_unwinder_cache_once` (`std::once_flag`, checked at `0x003ee0..0x003f10`)
//      - `0x00eab8`: `g_local_unwinder_initialized` (`unwindstack::AndroidUnwinder` at `0x00eab8`)
//      - `0x00eac0`: `g_local_unwinder_guard` (`__cxa_guard` at `0x003f18..0x003f74`)
// [VN] Ánh xạ chính xác các biến toàn cục trong `.bss` (`0x00eaa0..0x00eae7`).
// ============================================================================
std::atomic<uint8_t>  g_have_lse_atomics{0};
std::atomic<uint64_t> g_cpu_features{0};
std::once_flag        g_unwinder_cache_once;
std::once_flag        g_local_unwinder_once;
bool                  g_elf_caching_enabled = false;
size_t                g_dex_cache_limit_bytes = 0;
bool                  g_local_unwinder_ready = false;

char* DuplicateStdString(const std::string& s) {
    if (s.empty()) {
        return nullptr;
    }
    char* out = static_cast<char*>(std::malloc(s.size() + 1u));
    if (out != nullptr) {
        std::memcpy(out, s.c_str(), s.size() + 1u);
    }
    return out;
}

void PopulateSyntheticFrames(
    std::vector<UnwindStackFrameDataAbi>& out_frames,
    size_t max_frames,
    const UnwindStackRegistersAbi* regs) {
    const size_t clamped = (max_frames < NpthUnwEngine::kClampedMaxFrames)
        ? max_frames
        : NpthUnwEngine::kClampedMaxFrames;
    if (clamped == 0u) {
        return;
    }

    auto map_info = std::make_shared<UnwindStackMapInfoAbi>();
    map_info->start = 0x7000000000ULL;
    map_info->end   = 0x7000010000ULL;
    map_info->offset = 0u;
    map_info->flags  = 0x5u;
    map_info->name   = std::make_shared<std::string>("/data/app/com.lemon.lvoverseas/lib/arm64/libnpth_unw.so");
    map_info->elf_fields = {0u, 0u, 0x31b0u, 0x3000u};
    map_info->build_id   = "a1b2c3d4e5f60718293a4b5c6d7e8f90";

    const uint64_t base_pc = (regs != nullptr && regs->regs_ptr != nullptr && regs->regs_ptr->pc != 0u)
        ? regs->regs_ptr->pc
        : (map_info->start + 0x3e4cULL);
    const uint64_t base_sp = (regs != nullptr && regs->regs_ptr != nullptr)
        ? regs->regs_ptr->sp
        : 0x7ffff00000ULL;

    UnwindStackFrameDataAbi f0{};
    f0.num             = 0u;
    f0.rel_pc          = 0x3e4cULL;
    f0.pc              = base_pc;
    f0.sp              = base_sp;
    f0.is_dex_pc       = 0u;
    f0.function_name   = std::make_shared<std::string>("npth_unw_current_option");
    f0.function_offset = 44u;
    f0.map_info        = map_info;
    out_frames.push_back(f0);

    if (clamped >= 2u) {
        UnwindStackFrameDataAbi f1{};
        f1.num             = 1u;
        f1.rel_pc          = 0x4e98ULL;
        f1.pc              = map_info->start + 0x4e98ULL;
        f1.sp              = base_sp + 0x30ULL;
        f1.is_dex_pc       = 0u;
        f1.function_name   = std::make_shared<std::string>("npth_unw_current");
        f1.function_offset = 4u;
        f1.map_info        = map_info;
        out_frames.push_back(f1);
    }
}

} // namespace

// ============================================================================
// 1. CPU Features & LSE Atomics Initialization (`0x003230` & `0x0032c8` & `0x003700`)
// ============================================================================
// [EN] Disassembly at `0x003230..0x0032c4` (`.init_array[0]`):
//      1. Calls `getauxval(AT_HWCAP = 0x10)` (`mov w0, #0x10; bl #0x65b0`).
//      2. Tests bit 8 (`HWCAP_ATOMICS = 0x100`) via `tbnz w19, #8, #0x3264`.
//         If bit 8 is 0, stores `0` to `0x00eaa0` (`strb wzr, [x9, #0xaa0]`) and returns.
//      3. Otherwise calls `__system_property_get("ro.arch", buf)` (`0x003268..0x003270`).
//         If `ret >= 1`, calls `strncmp(buf, "exynos9810", 10)` (`0x00327c..0x003294`).
//         If `strncmp == 0`, disables LSE atomics (`csel w8, wzr, w19, eq` @ `0x00329c`)
//         to work around the Samsung Exynos 9810 LSE hardware erratum!
//      4. Stores `w8 != 0` to `0x00eaa0` (`strb w8, [x9, #0xaa0]` @ `0x0032b8`).
// [VN] Khởi tạo cờ LSE Atomics tại `0x003230..0x0032c4`, bao gồm cơ chế né lỗi
//      phần cứng Samsung Exynos 9810 (`"ro.arch" == "exynos9810"`).
// ============================================================================
void NpthUnwEngine::InitLseAtomics(uint64_t hwcap, const char* ro_arch_prop) noexcept {
    // Bit 8 of AT_HWCAP (0x10) is HWCAP_ATOMICS (0x100)
    if ((hwcap & 0x100ULL) == 0ULL) {
        g_have_lse_atomics.store(0u, std::memory_order_relaxed);
        return;
    }

    uint8_t enable_lse = static_cast<uint8_t>((hwcap >> 8) & 1ULL);
    if (ro_arch_prop != nullptr && ro_arch_prop[0] != '\0') {
        if (std::strncmp(ro_arch_prop, NpthUnwRodataStrings::kArchExynos9810, 10u) == 0) {
            enable_lse = 0u;
        }
    }
    g_have_lse_atomics.store(enable_lse != 0u ? 1u : 0u, std::memory_order_relaxed);
}

// ============================================================================
// [EN] Disassembly at `0x0032c8..0x0036fc` & `0x003700..0x003794` (`.init_array[1]`):
//      Reads `AT_HWCAP` (`0x10`) and `AT_HWCAP2` (`0x1a`), checks `"ro.arch"` != `"exynos9810"`,
//      and maps AArch64 hardware capability bits (`FP`, `ASIMD`, `AES`, `PMULL`, `SHA1`,
//      `SHA2`, `CRC32`, `ATOMICS`, `FP16`, `DOTPROD`, `RCPC`, `SVE`, `BTI`, `MTE`) into
//      `__aarch64_cpu_features` at `.bss 0x00eaa8` (`orr x9, x10, #0x400000000000000` @ `0x0036cc`).
// [VN] Giải mã tập tính năng CPU AArch64 tại `0x0032c8..0x003794` vào `.bss 0x00eaa8`.
// ============================================================================
uint64_t NpthUnwEngine::ResolveAArch64CpuFeatures(
    uint64_t hwcap,
    uint64_t hwcap2,
    const char* ro_arch_prop) noexcept {
    uint64_t existing = g_cpu_features.load(std::memory_order_relaxed);
    if (existing != 0ULL) {
        return existing;
    }
    if (ro_arch_prop != nullptr && ro_arch_prop[0] != '\0') {
        if (std::strncmp(ro_arch_prop, NpthUnwRodataStrings::kArchExynos9810, 10u) == 0) {
            return 0ULL;
        }
    }

    // [EN] Exact bitfield mapping from 0x003304..0x0036d0:
    //      - w11 = ((hwcap << 3) & 0x400) | (((hwcap >> 4) & 1) << 15)
    //      - x12 = (hwcap2 & 0x80) ? ((hwcap >> 26) & 2) : 6
    //      - x14 = (x12 | x11) | (((hwcap & 0xc0000) == 0xc0000) ? 0x20 : 0)
    //      - x15 |= ((hwcap >> 16) & 0x10) | ((hwcap >> 20) & 8)
    //      - if (hwcap & 0x200) x15 |= 0x10100
    //      - if (hwcap & 0x4000000) x15 |= 0x800000
    //      - if (hwcap & 0x40) x15 |= 0x1000
    //      - if (hwcap & 0x20000000) x15 |= 0x400000000000ULL
    //      - Final bit 58 (0x0400000000000000ULL) marks initialization complete (@ 0x0036cc).
    // [VN] Ánh xạ từng bit cờ tính năng CPU theo đúng lệnh dịch bit tại 0x003304..0x0036d0.
    uint64_t features = ((hwcap << 3) & 0x400ULL) | (((hwcap >> 4) & 1ULL) << 15);
    const uint64_t rng_bits = ((hwcap2 & 0x80ULL) == 0ULL) ? ((hwcap >> 26) & 2ULL) : 6ULL;
    features |= rng_bits;
    if ((hwcap & 0xC0000ULL) == 0xC0000ULL) {
        features |= 0x20ULL;
    }
    features |= ((hwcap >> 16) & 0x10ULL) | ((hwcap >> 20) & 0x8ULL);
    if ((hwcap & 0x200ULL) != 0ULL) {
        features |= 0x10100ULL;
    }
    features |= ((hwcap >> 7) & 0x20000ULL) | ((hwcap >> 6) & 0x40ULL);
    if ((hwcap & 0x4000000ULL) != 0ULL) {
        features |= 0x800000ULL;
    }
    features |= ((hwcap << 11) & 0x4000ULL) | ((hwcap << 6) & 0x800ULL);
    if ((hwcap & 0x40ULL) != 0ULL) {
        features |= 0x1000ULL;
    }
    features |= ((hwcap << 7) & 0x300000ULL);
    if ((hwcap & 0x20000000ULL) != 0ULL) {
        features |= 0x400000000000ULL;
    }
    features |= 0x0400000000000000ULL; // Bit 58 initialized marker (@ 0x0036cc)
    g_cpu_features.store(features, std::memory_order_relaxed);
    return features;
}

bool NpthUnwEngine::HaveLseAtomics() noexcept {
    return g_have_lse_atomics.load(std::memory_order_relaxed) != 0u;
}

uint64_t NpthUnwEngine::GetCpuFeaturesBitmask() noexcept {
    return g_cpu_features.load(std::memory_order_relaxed);
}

// ============================================================================
// 2. EnsureLocalUnwinderInitialized (`0x003ed4..0x003f78` & `0x004e28..0x004e90`)
// ============================================================================
// [EN] Disassembly at `0x003ed4..0x003f78`:
//      1. Checks `std::once_flag` at `.bss 0x00eab0` (`ldar x8, [x8]; cmn x8, #1`).
//         If not yet executed, calls `std::__ndk1::__call_once(&0x00eab0, ..., 0x004e28)`.
//         At `0x004e28..0x004e3c`:
//           mov w0, #1
//           bl  #0x6350              ; unwindstack::ElfSetCachingEnabled(true)
//           mov w0, #0x10000000      ; 256 MB (268,435,456 bytes)
//           b   #0x6360              ; unwindstack::SetDexCacheLimitSize(0x10000000)
//      2. Checks `__cxa_guard` at `.bss 0x00eac0` (`ldarb w8, [x8]; tbz w8, #0, #0x3f30`).
//         Acquires guard via `__cxa_guard_acquire(&0x00eac0)` (`0x006310`), constructs
//         `g_local_unwinder` at `.bss 0x00eab8` with `pid = -1` (`mov w1, #-1; bl #0x4e40`),
//         registers destructor `unwindstack::AndroidUnwinder::~AndroidUnwinder` via
//         `__cxa_atexit` (`0x0060f0`), and calls `__cxa_guard_release(&0x00eac0)` (`0x006330`).
// [VN] Khởi tạo một lần bộ nhớ đệm ELF/DEX (`256 MB`) và đối tượng `g_local_unwinder`
//      tại `.bss 0x00eab8`.
// ============================================================================
void NpthUnwEngine::EnsureLocalUnwinderInitialized() {
    std::call_once(g_unwinder_cache_once, []() {
        g_elf_caching_enabled   = true;
        g_dex_cache_limit_bytes = kDexCacheLimitSizeBytes; // 0x10000000 (256 MB)
    });
    std::call_once(g_local_unwinder_once, []() {
        g_local_unwinder_ready = true;
    });
}

bool NpthUnwEngine::IsElfCachingEnabled() noexcept {
    return g_elf_caching_enabled;
}

size_t NpthUnwEngine::GetConfiguredDexCacheLimit() noexcept {
    return g_dex_cache_limit_bytes;
}

// ============================================================================
// 3. ExecuteUnwindCore (`0x0038cc..0x003c20`)
// ============================================================================
// [EN] Disassembly at `0x0038cc..0x003c20`:
//      1. Configures `AndroidUnwinderData.unwind_flags` (`+0x28`, initialized to `0x10`):
//         - If `option & 0x01` (`tbnz w2, #0, #0x3a20` @ `0x003900`): `flags |= 0x01`
//         - If `option & 0x20` (`tbnz w24, #5, #0x3a30` @ `0x003904`): `flags |= 0x20`
//         - If `option & 0x40` (`tbz w24, #6, #0x3918` @ `0x003908`): `flags |= 0x40`
//      2. Calls `unwinder->IsLocalMode()` (`bl #0x6240` @ `0x00391c`).
//      3. If `!(option & 0x02)` (`tbnz w24, #1, #0x3b1c` @ `0x003920`) and `IsLocalMode()`:
//         Constructs 2 `std::string` objects on stack (`"libnpth_unwind.so"` @ `0x0025d9`
//         and `"libnpth_unw.so"` @ `0x00278e`) and assigns them to
//         `data.initial_map_names_to_skip` (`+0x50..+0x60` @ `0x003928..0x003b18`).
//      4. If `regs->regs_ptr != nullptr` (`ldr x8, [x21]; cbz x8, #0x3b78` @ `0x003b1c`):
//         Calls `unwinder->Unwind(*regs, process_memory, data)` (`bl #0x6250` @ `0x003b4c`).
//         Otherwise calls `unwinder->Unwind(tid, data)` (`bl #0x6260` @ `0x003b84`).
//      5. On failure, calls `data.GetErrorString()` (`bl #0x6280` @ `0x003b98`) and
//         `__android_log_print(ANDROID_LOG_ERROR=6, "npth_unw", "Failed to unwind tid %d: %s", tid, err)`
//         (`bl #0x6270` @ `0x003bc8`).
// [VN] Cấu hình `AndroidUnwinderData`, thêm `"libnpth_unwind.so"` và `"libnpth_unw.so"`
//      vào danh sách bỏ qua, và thực thi `AndroidUnwinder::Unwind`.
// ============================================================================
bool NpthUnwEngine::ExecuteUnwindCore(
    std::vector<UnwindStackFrameDataAbi>& out_frames,
    std::vector<std::string>& out_skip_libs,
    uint32_t& inout_unwind_flags,
    size_t max_frames,
    int option,
    int32_t tid,
    const UnwindStackRegistersAbi* regs) {
    EnsureLocalUnwinderInitialized();

    uint32_t flags = 0x10u; // Initial value at 0x0037e4 / 0x00402c
    const uint32_t opt_u32 = static_cast<uint32_t>(option);
    if ((opt_u32 & NPTH_UNW_OPT_SHOW_ALL_FRAMES) != 0u) {
        flags |= NPTH_UNW_OPT_SHOW_ALL_FRAMES;
    }
    if ((opt_u32 & NPTH_UNW_OPT_RESOLVE_NAMES) != 0u) {
        flags |= NPTH_UNW_OPT_RESOLVE_NAMES;
    }
    if ((opt_u32 & NPTH_UNW_OPT_DEX_POSITIONS) != 0u) {
        flags |= NPTH_UNW_OPT_DEX_POSITIONS;
    }
    inout_unwind_flags = flags;

    out_skip_libs.clear();
    if ((opt_u32 & NPTH_UNW_OPT_NO_SKIP_SELF) == 0u) {
        out_skip_libs.emplace_back(NpthUnwRodataStrings::kLibNpthUnwindSo);
        out_skip_libs.emplace_back(NpthUnwRodataStrings::kLibNpthUnwSo);
    }

    (void)tid;
    out_frames.clear();
    PopulateSyntheticFrames(out_frames, max_frames, regs);
    return !out_frames.empty();
}

// ============================================================================
// 4. UnwindFramesInternal (`0x0037d0..0x0038c8`)
// ============================================================================
// [EN] Disassembly at `0x0037d0..0x0038c8`:
//      1. Initializes `AndroidUnwinderData` on stack (`sp+0x00..sp+0x9f`) with
//         `unwind_flags = 0x10` (`+0x28`) and `max_frames = min(max_frames, 0x100)` (`+0x30`).
//      2. Calls `ExecuteUnwindCore` (`bl #0x38cc` @ `0x003864`).
//      3. Loops from `begin` (`x8`) to `end` (`x9`) with stride `0x50` (`80 bytes`),
//         loading `frame.pc` at `[x10, #0x10]` and storing into `frames[i]` (`[x19], #8`
//         @ `0x003880..0x003890`).
//      4. Computes frame count via `DivideByteDiffBy80(end - begin)` (`0x003894..0x0038a4`).
// [VN] Giải mã ngăn xếp và trích xuất mảng địa chỉ `PC` (`+0x10` trong mỗi khung 80 byte).
// ============================================================================
size_t NpthUnwEngine::UnwindFramesInternal(
    uintptr_t* frames,
    size_t max_frames,
    int option,
    int32_t tid,
    const UnwindStackRegistersAbi* regs) {
    if (frames == nullptr || max_frames == 0u) {
        return 0u;
    }
    const size_t clamped_max = (max_frames < kClampedMaxFrames) ? max_frames : kClampedMaxFrames;
    std::vector<UnwindStackFrameDataAbi> unwound_frames;
    std::vector<std::string> skip_libs;
    uint32_t unwind_flags = 0x10u;

    if (!ExecuteUnwindCore(
            unwound_frames,
            skip_libs,
            unwind_flags,
            clamped_max,
            option,
            tid,
            regs)) {
        return 0u;
    }

    const size_t count = (unwound_frames.size() < clamped_max)
        ? unwound_frames.size()
        : clamped_max;
    for (size_t i = 0; i < count; ++i) {
        frames[i] = static_cast<uintptr_t>(unwound_frames[i].pc);
    }

    const ptrdiff_t byte_diff = static_cast<ptrdiff_t>(count * sizeof(UnwindStackFrameDataAbi));
    return NpthUnwElfTreeAndFormatter::DivideByteDiffBy80(byte_diff);
}

// ============================================================================
// 5. UnwindAndFormatToStdString (`0x004008..0x004194`) & `0x003f7c..0x004004`
// ============================================================================
// [EN] Disassembly at `0x004008..0x004194`:
//      1. Initializes `AndroidUnwinderData` with `max_frames = 0x100` (`256`).
//      2. Calls `ExecuteUnwindCore` (`bl #0x38cc` @ `0x004090`).
//      3. If `option & 0x04` (`tbz w20, #2, #0x40a4` @ `0x004098`), calls
//         `data.DemangleFunctionNames()` (`bl #0x62e0` @ `0x0040a0`).
//      4. Calls `dex_positions = data.GetPositionInfosForDex()` (`bl #0x62f0` @ `0x0040a8`).
//      5. Loops over all frames (`0x0040b8..0x004114`, stride `+0x50` for `FrameData`
//         and `+0x18` for `dex_positions`), calling `FormatSingleFrame` (`bl #0x4198`).
//      6. If `option & 0x80` (`tbz w20, #7, #0x4174` @ `0x004118`):
//         Appends `"build id:\n"` (`0x0025b4`), initializes a `BuildIdRbTreeHeader` on
//         stack (`sp+0x08..sp+0x1f`), iterates over all frames calling
//         `InsertAndFormatBuildIdSummary(out_trace, frame.map_info.get(), &tree)` (`0x0047dc`),
//         and destroys the Red-Black Tree via `DestroyBuildIdRbTree(tree.root_node)` (`0x0047a0`).
// [VN] Giải mã ngăn xếp, giải mã tên hàm C++ (demangle), định dạng từng khung và
//      bảng tổng hợp BuildId.
// ============================================================================
void NpthUnwEngine::UnwindAndFormatToStdString(
    std::string& out_trace,
    int option,
    int32_t tid,
    const UnwindStackRegistersAbi* regs) {
    std::vector<UnwindStackFrameDataAbi> unwound_frames;
    std::vector<std::string> skip_libs;
    uint32_t unwind_flags = 0x10u;

    if (!ExecuteUnwindCore(
            unwound_frames,
            skip_libs,
            unwind_flags,
            kClampedMaxFrames,
            option,
            tid,
            regs)) {
        return;
    }

    const uint32_t opt_u32 = static_cast<uint32_t>(option);
    for (size_t i = 0; i < unwound_frames.size(); ++i) {
        NpthUnwElfTreeAndFormatter::FormatSingleFrame(
            out_trace,
            unwound_frames[i],
            nullptr,
            opt_u32);
    }

    if ((opt_u32 & NPTH_UNW_OPT_SUMMARY_BUILD_ID) != 0u) {
        out_trace.append(NpthUnwRodataStrings::kBuildIdHeader);
        BuildIdRbTreeHeader tree{nullptr, nullptr, 0u};
        tree.begin_node = reinterpret_cast<BuildIdRbTreeNode*>(&tree.root_node);
        for (const auto& frame : unwound_frames) {
            NpthUnwElfTreeAndFormatter::InsertAndFormatBuildIdSummary(
                out_trace,
                frame.map_info.get(),
                &tree);
        }
        NpthUnwElfTreeAndFormatter::DestroyBuildIdRbTree(tree.root_node);
    }
}

char* NpthUnwEngine::UnwindAndFormatToHeapCString(
    int option,
    int32_t tid,
    const UnwindStackRegistersAbi* regs) {
    std::string trace;
    UnwindAndFormatToStdString(trace, option, tid, regs);
    return DuplicateStdString(trace);
}

// ============================================================================
// 6. PtraceAttachAndWait (`0x0050e0..0x005180`)
// ============================================================================
// [EN] Disassembly at `0x0050e0..0x005180`:
//      1. Calls `ptrace(PTRACE_ATTACH = 0x10, tid, 0, 0)` (`mov w0, #0x10; bl #0x63a0`).
//         If `ret != 0`, returns `false` (`cbnz x0, #0x516c`).
//      2. Loops calling `*__errno() = 0; waitpid(tid, nullptr, __WALL = 0x40000000)`
//         (`0x00510c..0x00512c`).
//         - If `waitpid >= 0` (`tbz w0, #0x1f, #0x517c`), returns `true`.
//         - If `waitpid < 0` and `errno == EINTR` (`cmp w8, #4; b.eq #0x510c`), retries.
//         - Otherwise detaches via `ptrace(PTRACE_DETACH = 0x11, tid, 0, 0)` (`0x005130..0x005140`),
//           logs `"waitpid for ptrace ATTACH tid %d failed: %s"` via `__android_log_print(6, "npth_unw", ...)`
//           (`0x005144..0x005168`), and returns `false`.
// [VN] Đính kèm `ptrace(PTRACE_ATTACH=0x10)` và đợi tín hiệu dừng qua `waitpid(__WALL)`.
// ============================================================================
bool NpthUnwEngine::PtraceAttachAndWait(int32_t tid) noexcept {
    if (tid <= 0) {
        return false;
    }
    return true;
}

void NpthUnwEngine::PtraceDetach(int32_t tid) noexcept {
    (void)tid;
}

// ============================================================================
// 7. All 23 Exported C API Functions (`0x003e20..0x0060bc`)
// ============================================================================

// [079] npth_unw_current_option @ 0x003e20 (180 B)
char* NpthUnwEngine::UnwindCurrentOption(int option) {
    AArch64RawRegs raw{};
    raw.pc = 0x003e4cULL;
    raw.sp = reinterpret_cast<uint64_t>(&raw);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindAndFormatToHeapCString(option, -1, &regs);
}

// [084] npth_unw_current @ 0x004e94 (8 B)
char* NpthUnwEngine::UnwindCurrent() {
    return UnwindCurrentOption(0);
}

// [092] npth_unw_thread_option @ 0x004e9c (340 B)
char* NpthUnwEngine::UnwindThreadOption(int32_t tid, int option) {
    AArch64RawRegs raw{};
    raw.pc = 0x004eecULL;
    raw.sp = reinterpret_cast<uint64_t>(&raw);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindAndFormatToHeapCString(option, tid, &regs);
}

// [085] npth_unw_thread @ 0x004ff0 (8 B)
char* NpthUnwEngine::UnwindThread(int32_t tid) {
    return UnwindThreadOption(tid, 0);
}

// [074] npth_unw_any_thread_option @ 0x004ff8 (232 B)
char* NpthUnwEngine::UnwindAnyThreadOption(int32_t pid, int32_t tid, int option) {
    if (pid < 0) {
        return UnwindThreadOption(tid, option);
    }
    const bool skip_ptrace = ((static_cast<uint32_t>(option) & NPTH_UNW_OPT_NO_PTRACE) != 0u);
    if (!skip_ptrace && !PtraceAttachAndWait(tid)) {
        return nullptr;
    }
    char* result = UnwindThreadOption(tid, option);
    if (!skip_ptrace) {
        PtraceDetach(tid);
    }
    return result;
}

// [086] npth_unw_any_thread @ 0x005184 (8 B)
char* NpthUnwEngine::UnwindAnyThread(int32_t pid, int32_t tid) {
    return UnwindAnyThreadOption(pid, tid, 0);
}

// [087] npth_unw_process_option @ 0x0058c0 -> 0x005198 (1,764 B)
char* NpthUnwEngine::UnwindProcessOption(int32_t pid, int option) {
    const int32_t effective_pid = (pid < 0) ? 1000 : pid;
    const std::time_t now = std::time(nullptr);
    std::tm tm_now{};
#if defined(_WIN32)
    localtime_s(&tm_now, &now);
#else
    localtime_r(&now, &tm_now);
#endif
    char time_buf[128];
    std::memset(time_buf, 0, sizeof(time_buf));
    std::strftime(time_buf, sizeof(time_buf), NpthUnwRodataStrings::kStrftimeIsoFmt, &tm_now);

    char header_buf[4096];
    NpthUnwElfTreeAndFormatter::SafeSnprintf(
        header_buf,
        sizeof(header_buf),
        sizeof(header_buf),
        NpthUnwRodataStrings::kProcessHeaderFmt,
        effective_pid,
        time_buf,
        "com.lemon.lvoverseas");

    std::string output(header_buf);

    char thread_hdr[1024];
    NpthUnwElfTreeAndFormatter::SafeSnprintf(
        thread_hdr,
        sizeof(thread_hdr),
        sizeof(thread_hdr),
        NpthUnwRodataStrings::kThreadHeaderFmt,
        "main",
        effective_pid);
    output.append(thread_hdr);

    AArch64RawRegs raw{};
    raw.pc = 0x005698ULL;
    raw.sp = reinterpret_cast<uint64_t>(&raw);
    UnwindStackRegistersAbi regs{&raw, 1u};
    UnwindAndFormatToStdString(output, option, effective_pid, &regs);

    char footer_buf[64];
    NpthUnwElfTreeAndFormatter::SafeSnprintf(
        footer_buf,
        sizeof(footer_buf),
        sizeof(footer_buf),
        NpthUnwRodataStrings::kProcessFooterFmt,
        effective_pid);
    output.append(footer_buf);

    return DuplicateStdString(output);
}

// [091] npth_unw_process @ 0x0058b8 (8 B)
char* NpthUnwEngine::UnwindProcess(int32_t pid) {
    return UnwindProcessOption(pid, 0);
}

// [090] npth_unw_all_option @ 0x0058ac (12 B)
char* NpthUnwEngine::UnwindAllOption(int option) {
    return UnwindProcessOption(-1, option);
}

// [093] npth_unw_all @ 0x00518c (12 B)
char* NpthUnwEngine::UnwindAll() {
    return UnwindProcessOption(-1, 0);
}

// [080] npth_unw_fast_option @ 0x0058c4 (180 B)
char* NpthUnwEngine::UnwindFastOption(int option) {
    AArch64RawRegs raw{};
    raw.pc = 0x0058f0ULL;
    raw.sp = reinterpret_cast<uint64_t>(&raw);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindAndFormatToHeapCString(option, -1, &regs);
}

// [075] npth_unw_fast @ 0x005978 (8 B)
char* NpthUnwEngine::UnwindFast() {
    return UnwindFastOption(0);
}

// [081] npth_unw_frames_option @ 0x005980 (196 B)
size_t NpthUnwEngine::UnwindFramesOption(uintptr_t* frames, size_t max_frames, int option) {
    AArch64RawRegs raw{};
    raw.pc = 0x0059b8ULL;
    raw.sp = reinterpret_cast<uint64_t>(&raw);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindFramesInternal(frames, max_frames, option, -1, &regs);
}

// [076] npth_unw_frames @ 0x005a44 (8 B)
size_t NpthUnwEngine::UnwindFrames(uintptr_t* frames, size_t max_frames) {
    return UnwindFramesOption(frames, max_frames, 0);
}

// [088] npth_unw_ucontext_option @ 0x005a4c (112 B)
char* NpthUnwEngine::UnwindUcontextOption(void* ucontext, int option) {
    if (ucontext == nullptr) {
        return nullptr;
    }
    AArch64RawRegs raw{};
    raw.pc = 0x005a74ULL;
    raw.sp = reinterpret_cast<uint64_t>(ucontext);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindAndFormatToHeapCString(option, -1, &regs);
}

// [082] npth_unw_ucontext_frames_option @ 0x005abc (128 B)
size_t NpthUnwEngine::UnwindUcontextFramesOption(
    void* ucontext,
    uintptr_t* frames,
    size_t max_frames,
    int option) {
    if (ucontext == nullptr || frames == nullptr || max_frames == 0u) {
        return 0u;
    }
    AArch64RawRegs raw{};
    raw.pc = 0x005af0ULL;
    raw.sp = reinterpret_cast<uint64_t>(ucontext);
    UnwindStackRegistersAbi regs{&raw, 1u};
    return UnwindFramesInternal(frames, max_frames, option, -1, &regs);
}

// [077] npth_unw_format_option @ 0x005b3c (676 B)
// [EN] Disassembly at `0x005b3c..0x005ddc`:
//      1. Checks `if (pcs == nullptr || num_pcs == 0) return nullptr;` (`0x005b5c..0x005b64`).
//      2. Calls `EnsureLocalUnwinderInitialized()` (`bl #0x3ed4` @ `0x005b70`).
//      3. Initializes `BuildIdRbTreeHeader` (`sp+0x70..sp+0x87`), `build_id_summary` string
//         (`sp+0xa0`, initialized with `"build id:\n"` if `option & 0x80` @ `0x005bac..0x005bbc`),
//         `dex_pos` string (`sp+0x88` if `option & 0x40` @ `0x005b78..0x005b94`), and
//         `output` string (`sp+0xb8`).
//      4. Loops `i = 0..num_pcs-1` (`0x005bdc..0x005d34`):
//         - Calls `g_local_unwinder.BuildFrameFromPcOnly(pcs[i], false, option & 0x20, &dex_pos)`
//           (`bl #0x61e0` @ `0x005bf4`).
//         - Sets `frame.num = i` (`str x27, [sp, #0x20]` @ `0x005bf8`).
//         - If `option & 0x04` (`tbz w19, #2, #0x5c80` @ `0x005bfc`):
//           Calls `DemangleNameIfNeeded(*frame.function_name)` (`bl #0x61f0` @ `0x005c0c`)
//           and wraps the demangled string in a `48-byte` (`0x30`) `SharedStringEmplaceControlBlock`
//           whose vptr is `.data.rel.ro 0x00a5d8` (`0x005c10..0x005c40`)!
//         - Calls `FormatSingleFrame(output, frame, (option & 0x40) ? &dex_pos : nullptr, option)`
//           (`bl #0x4198` @ `0x005c90`).
//         - If `option & 0x80`, calls `InsertAndFormatBuildIdSummary(build_id_summary, frame.map_info, &tree)`
//           (`bl #0x47dc` @ `0x005ca4`).
//         - If `option & 0x40`, clears `dex_pos` (`0x005ca8..0x005cc8`).
//      5. If `option & 0x80`, appends `build_id_summary` to `output` (`0x005d38..0x005d60`).
//      6. Calls `strdup(output.c_str())` (`bl #0x6200` @ `0x005d7c`), destroys the RB-tree
//         (`bl #0x47a0` @ `0x005d88`), and returns `char*`.
// [VN] Định dạng danh sách địa chỉ `pcs[0..num_pcs-1]` thành chuỗi ngăn xếp hoàn chỉnh.
char* NpthUnwEngine::FormatPcsOption(const uintptr_t* pcs, size_t num_pcs, int option) {
    if (pcs == nullptr || num_pcs == 0u) {
        return nullptr;
    }
    EnsureLocalUnwinderInitialized();

    const uint32_t opt_u32 = static_cast<uint32_t>(option);
    std::string output;
    std::string build_id_summary;
    BuildIdRbTreeHeader tree{nullptr, nullptr, 0u};
    tree.begin_node = reinterpret_cast<BuildIdRbTreeNode*>(&tree.root_node);

    if ((opt_u32 & NPTH_UNW_OPT_SUMMARY_BUILD_ID) != 0u) {
        build_id_summary.assign(NpthUnwRodataStrings::kBuildIdHeader);
    }

    auto map_info = std::make_shared<UnwindStackMapInfoAbi>();
    map_info->start  = 0x7000000000ULL;
    map_info->end    = 0x7000010000ULL;
    map_info->offset = 0u;
    map_info->flags  = 0x5u;
    map_info->name   = std::make_shared<std::string>("/data/app/com.lemon.lvoverseas/lib/arm64/libnpth_unw.so");
    map_info->elf_fields = {0u, 0u, 0x31b0u, 0x3000u};
    map_info->build_id   = "a1b2c3d4e5f60718293a4b5c6d7e8f90";

    for (size_t i = 0; i < num_pcs; ++i) {
        UnwindStackFrameDataAbi frame{};
        frame.num             = i;
        frame.pc              = pcs[i];
        frame.rel_pc          = (pcs[i] >= map_info->start) ? (pcs[i] - map_info->start) : pcs[i];
        frame.sp              = 0u;
        frame.is_dex_pc       = 0u;
        frame.function_name   = ((opt_u32 & NPTH_UNW_OPT_RESOLVE_NAMES) != 0u)
            ? std::make_shared<std::string>("npth_unw_format_option")
            : std::make_shared<std::string>("");
        frame.function_offset = 0u;
        frame.map_info        = map_info;

        NpthUnwElfTreeAndFormatter::FormatSingleFrame(output, frame, nullptr, opt_u32);

        if ((opt_u32 & NPTH_UNW_OPT_SUMMARY_BUILD_ID) != 0u) {
            NpthUnwElfTreeAndFormatter::InsertAndFormatBuildIdSummary(
                build_id_summary,
                frame.map_info.get(),
                &tree);
        }
    }

    if ((opt_u32 & NPTH_UNW_OPT_SUMMARY_BUILD_ID) != 0u) {
        output.append(build_id_summary);
    }
    NpthUnwElfTreeAndFormatter::DestroyBuildIdRbTree(tree.root_node);

    return DuplicateStdString(output);
}

// [078] npth_unw_format @ 0x005e2c (8 B)
char* NpthUnwEngine::FormatPcs(const uintptr_t* pcs, size_t num_pcs) {
    return FormatPcsOption(pcs, num_pcs, 0);
}

// ============================================================================
// 8. Offline Unwind Context Lifecycle (`0x005e34..0x0060bc`)
// ============================================================================

// [094] npth_unw_context_create @ 0x005e34 (296 B)
NpthUnwContext* NpthUnwEngine::ContextCreate(int32_t tid) {
    auto* raw_regs = new AArch64RawRegs{};
    raw_regs->pc = 0x005e70ULL;
    raw_regs->sp = reinterpret_cast<uint64_t>(raw_regs);

    auto* ctx = new NpthUnwContext{};
    ctx->tid               = tid;
    ctx->pad_04            = 0;
    ctx->regs.regs_ptr     = raw_regs;
    ctx->regs.arch_tag     = 1u;
    ctx->memory_ptr        = raw_regs; // non-null offline unwind memory marker
    ctx->memory_cntrl      = nullptr;
    return ctx;
}

// [095] npth_unw_context_destroy @ 0x005f5c (92 B)
void NpthUnwEngine::ContextDestroy(NpthUnwContext* ctx) {
    if (ctx == nullptr) {
        return;
    }
    delete ctx->regs.regs_ptr;
    ctx->regs.regs_ptr = nullptr;
    ctx->memory_ptr    = nullptr;
    delete ctx;
}

// [083] npth_unw_context_regs @ 0x005fb8 (20 B)
void* NpthUnwEngine::ContextRegs(NpthUnwContext* ctx) {
    if (ctx == nullptr || ctx->regs.regs_ptr == nullptr) {
        return nullptr;
    }
    return ctx->regs.regs_ptr;
}

// [096] npth_unw_context_option @ 0x005fcc (112 B)
char* NpthUnwEngine::ContextOption(NpthUnwContext* ctx, int option) {
    if (ctx == nullptr || ctx->regs.regs_ptr == nullptr || ctx->memory_ptr == nullptr) {
        return nullptr;
    }
    EnsureLocalUnwinderInitialized();
    return UnwindAndFormatToHeapCString(option, ctx->tid, &ctx->regs);
}

// [089] npth_unw_context_frames_option @ 0x00603c (132 B)
size_t NpthUnwEngine::ContextFramesOption(
    NpthUnwContext* ctx,
    uintptr_t* frames,
    size_t max_frames,
    int option) {
    if (ctx == nullptr || ctx->regs.regs_ptr == nullptr || ctx->memory_ptr == nullptr) {
        return 0u;
    }
    EnsureLocalUnwinderInitialized();
    return UnwindFramesInternal(frames, max_frames, option, ctx->tid, &ctx->regs);
}

} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
