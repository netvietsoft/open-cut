// ============================================================================
// FILE: npth_unw_types.h
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64, 97 .dynsym entries)
// ROLE: Exact ELF64 Section Map, .rodata Constants, ABI Structs & Vtable Layout
//       Bản đồ phân vùng ELF64, hằng số .rodata, cấu trúc ABI & bố cục Vtable
// ============================================================================
// [EN] Clean-room C++17 reconstruction of ByteDance's NPTH (Native Crash &
//      Performance Tracker) stack unwinding wrapper library `libnpth_unw.so`,
//      which bridges C crash/ANR handlers to `libnpth_unwind.so`
//      (`unwindstack::AndroidUnwinder`, `unwindstack::Registers`,
//      `unwindstack::AndroidUnwinderData`, `unwindstack::MapInfo`).
// [VN] Tái cấu trúc C++17 sạch của thư viện bọc giải mã ngăn xếp NPTH
//      `libnpth_unw.so` (ByteDance), kết nối các trình xử lý crash/ANR viết
//      bằng C tới `libnpth_unwind.so` (`unwindstack::AndroidUnwinder`,
//      `unwindstack::Registers`, `unwindstack::AndroidUnwinderData`, `MapInfo`).
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {

// ============================================================================
// 1. ELF64 BINARY GEOMETRY & SECTION LAYOUT (BỐ CỤC PHÂN VÙNG NHỊ PHÂN ELF64)
// ============================================================================
// [EN] Verified directly from `libnpth_unw.so` (29,336 bytes, 25 ELF64 sections).
// [VN] Xác minh trực tiếp từ `libnpth_unw.so` (29.336 byte, 25 phân vùng ELF64).
//
//   [01] .note.android.ident : vaddr=0x000238, off=0x000238, size=0x000098 (152 B)
//   [02] .note.gnu.build-id  : vaddr=0x0002d0, off=0x0002d0, size=0x000024 (36 B)
//   [03] .dynsym             : vaddr=0x0002f8, off=0x0002f8, size=0x000918 (2,328 B, 97 syms)
//   [04] .gnu.version        : vaddr=0x000c10, off=0x000c10, size=0x0000c2 (194 B)
//   [05] .gnu.version_r      : vaddr=0x000cd4, off=0x000cd4, size=0x000020 (32 B)
//   [06] .gnu.hash           : vaddr=0x000cf8, off=0x000cf8, size=0x0000c0 (192 B)
//   [07] .hash               : vaddr=0x000db8, off=0x000db8, size=0x000310 (784 B)
//   [08] .dynstr             : vaddr=0x0010c8, off=0x0010c8, size=0x000c68 (3,176 B)
//   [09] .rela.dyn           : vaddr=0x001d30, off=0x001d30, size=0x000108 (264 B, 11 relocs)
//   [10] .rela.plt           : vaddr=0x001e38, off=0x001e38, size=0x000750 (1,872 B, 78 relocs)
//   [11] .rodata             : vaddr=0x002588, off=0x002588, size=0x000228 (552 B)
//   [12] .eh_frame_hdr       : vaddr=0x0027b0, off=0x0027b0, size=0x0001dc (476 B)
//   [13] .eh_frame           : vaddr=0x002990, off=0x002990, size=0x000814 (2,068 B)
//   [14] .text               : vaddr=0x0031b0, off=0x0031b0, size=0x002f10 (12,048 B)
//   [15] .plt                : vaddr=0x0060c0, off=0x0060c0, size=0x000500 (1,280 B)
//   [16] .data.rel.ro        : vaddr=0x00a5c0, off=0x0065c0, size=0x000040 (64 B)
//   [17] .fini_array         : vaddr=0x00a600, off=0x006600, size=0x000010 (16 B)
//   [18] .init_array         : vaddr=0x00a610, off=0x006610, size=0x000010 (16 B)
//   [19] .dynamic            : vaddr=0x00a620, off=0x006620, size=0x0001f0 (496 B)
//   [20] .got                : vaddr=0x00a810, off=0x006810, size=0x000008 (8 B)
//   [21] .got.plt            : vaddr=0x00a818, off=0x006818, size=0x000288 (648 B)
//   [22] .bss                : vaddr=0x00eaa0, off=0x006aa0, size=0x000048 (72 B)
//   [23] .comment            : vaddr=0x000000, off=0x006aa0, size=0x0000cc (204 B)
//   [24] .shstrtab           : vaddr=0x000000, off=0x006b6c, size=0x0000ec (236 B)
// ============================================================================

struct NpthUnwElfGeometry {
    static constexpr uint32_t kBinarySizeBytes      = 29336u;
    static constexpr uint32_t kDynsymEntryCount     = 97u;
    static constexpr uint32_t kImportedSymbolCount  = 73u;  // [001]..[073]
    static constexpr uint32_t kExportedSymbolCount  = 23u;  // [074]..[096]
    static constexpr uint32_t kRelaDynCount         = 11u;
    static constexpr uint32_t kRelaPltCount         = 78u;
    static constexpr uint64_t kRodataVaddr          = 0x002588ULL;
    static constexpr uint32_t kRodataSizeBytes      = 552u;
    static constexpr uint64_t kTextVaddr            = 0x0031b0ULL;
    static constexpr uint32_t kTextSizeBytes        = 12048u;
    static constexpr uint64_t kPltVaddr             = 0x0060c0ULL;
    static constexpr uint32_t kPltSizeBytes         = 1280u;
    static constexpr uint64_t kDataRelRoVaddr       = 0x00a5c0ULL;
    static constexpr uint32_t kDataRelRoSizeBytes   = 64u;
    static constexpr uint64_t kFiniArrayVaddr       = 0x00a600ULL;
    static constexpr uint64_t kInitArrayVaddr       = 0x00a610ULL;
    static constexpr uint64_t kGotVaddr             = 0x00a810ULL;
    static constexpr uint64_t kGotPltVaddr          = 0x00a818ULL;
    static constexpr uint64_t kBssVaddr             = 0x00eaa0ULL;
    static constexpr uint32_t kBssSizeBytes         = 72u;
};

// ============================================================================
// 2. .RODATA STRING TABLE CONSTANTS (BẢNG HẰNG SỐ CHUỖI .RODATA 0x002588..0x0027AF)
// ============================================================================
// [EN] Every string literal below is mapped 1:1 to its exact virtual address in
//      `.rodata` (`0x002588..0x0027af`).
// [VN] Mọi hằng chuỗi dưới đây được ánh xạ 1:1 với địa chỉ ảo chính xác trong
//      `.rodata` (`0x002588..0x0027af`).
// ============================================================================

struct NpthUnwRodataStrings {
    static constexpr const char* kProcPidCmdlineFmt      = "/proc/%d/cmdline";                           // 0x002588
    static constexpr const char* kHexAngleFmt            = "<%lx>";                                      // 0x002599
    static constexpr const char* kElfOffsetFmt           = " (offset 0x%zx)";                            // 0x00259f
    static constexpr const char* kIndentFourSpaces       = "    ";                                       // 0x0025af
    static constexpr const char* kBuildIdHeader          = "build id:\n";                                // 0x0025b4
    static constexpr const char* kStrftimeIsoFmt         = "%F %T";                                      // 0x0025bf
    static constexpr const char* kFuncPlusOffsetFmt      = " (%s + %zu)";                                // 0x0025c5
    static constexpr const char* kSysPropRoArch          = "ro.arch";                                    // 0x0025d1
    static constexpr const char* kLibNpthUnwindSo        = "libnpth_unwind.so";                          // 0x0025d9
    static constexpr const char* kErrFailedToUnwindFmt   = "Failed to unwind tid %d: %s";                // 0x0025eb
    static constexpr const char* kProcTidCommFmt         = "/proc/%d/comm";                              // 0x002607
    static constexpr const char* kCompactBuildIdFmt      = "<BuildId:%s>";                               // 0x002616
    static constexpr const char* kErrOpendirFailedFmt    = "opendir %s failed: %s (errno=%d)";           // 0x002623
    static constexpr const char* kLogTagNpthUnw          = "npth_unw";                                   // 0x002644
    static constexpr const char* kCloseParenNewline      = " )\n";                                       // 0x00264d
    static constexpr const char* kHexPcFrameLineFmt      = "0x%016lx %s%s%s%s\n";                        // 0x002650
    static constexpr const char* kThreadHeaderFmt        = "\n\"%s\" sysTid=%d\n";                       // 0x002663
    static constexpr const char* kPositionAtFmt          = " (position at %s)";                          // 0x002674
    static constexpr const char* kAnonymousMapFmt        = "<anonymous:%lx>";                            // 0x002686
    static constexpr const char* kErrFailedToOpenFmt     = "Failed to open %s\n";                        // 0x002696
    static constexpr const char* kProcessFooterFmt       = "\n----- end %d -----\n";                     // 0x0026a8
    static constexpr const char* kUnknownSymbol          = "<unknown>";                                  // 0x0026bd
    static constexpr const char* kProcessHeaderFmt       = "\n\n----- pid %d at %s -----\nCmd line: %s\n"; // 0x0026c7
    static constexpr const char* kPositionAtPrefix       = " (position at ";                             // 0x0026f0
    static constexpr const char* kFopenModeRead          = "r";                                          // 0x0026ff
    static constexpr const char* kErrWaitpidPtraceFmt    = "waitpid for ptrace ATTACH tid %d failed: %s"; // 0x002701
    static constexpr const char* kBuildIdPrefix          = " (BuildId: ";                                // 0x00272d
    static constexpr const char* kExtVdex                = ".vdex";                                      // 0x002739
    static constexpr const char* kStrtokDelimCrLf        = "\r\n";                                       // 0x00273f
    static constexpr const char* kAngleStringFmt         = "<%s>";                                       // 0x002741
    static constexpr const char* kParenStringFmt         = " (%s)";                                      // 0x002746
    static constexpr const char* kArchExynos9810         = "exynos9810";                                 // 0x00274c
    static constexpr const char* kErrUnknownTidFmt       = "[err-unknown-tid-%d]";                       // 0x002757
    static constexpr const char* kCompactFrameLineFmt    = "    #%02zu %s%s%s\n";                        // 0x00276c
    static constexpr const char* kParenBuildIdFmt        = " (BuildId: %s)";                             // 0x00277f
    static constexpr const char* kLibNpthUnwSo           = "libnpth_unw.so";                             // 0x00278e
    static constexpr const char* kProcPidTaskFmt         = "/proc/%d/task";                              // 0x00279d
    static constexpr const char* kExtJar                 = ".jar";                                       // 0x0027ab
};

// ============================================================================
// 3. OPTION BITMASK FLAGS (CỜ TÙY CHỌN GIẢI MÃ & ĐỊNH DẠNG NGĂN XẾP)
// ============================================================================
// [EN] Bitfields decoded from AArch64 `tbz` / `tbnz` / `ubfx` / `and` instructions:
//      - Bit 0 (`0x00001`): `tbnz w2, #0, #0x3a20` @ `0x003900` -> sets bit 0 in
//        `AndroidUnwinderData.flags` (`+0x28`) (`show_all_frames`).
//      - Bit 1 (`0x00002`): `tbnz w24, #1, #0x3b1c` @ `0x003920` -> when 0, pushes
//        `"libnpth_unwind.so"` and `"libnpth_unw.so"` into `initial_map_names_to_skip`
//        vector (`+0x50..+0x60`); when 1, does NOT skip unwinder internal frames.
//      - Bit 2 (`0x00004`): `tbz w20, #2, #0x40a4` @ `0x004098` & `tbz w19, #2, #0x5c80`
//        @ `0x005bfc` -> calls `AndroidUnwinderData::DemangleFunctionNames()` /
//        `unwindstack::DemangleNameIfNeeded()`.
//      - Bit 3 (`0x00008`): `ubfx w1, w22, #3, #1` @ `0x0042e4` & `tbz w22, #3, #0x458c`
//        @ `0x00451c` & `0x004684` -> includes per-frame ELF BuildId (`MapInfo::GetPrintableBuildID()`).
//      - Bit 4 (`0x00010`): `tbnz w20, #4, #0x5050` @ `0x005040` & `ubfx w8, w8, #4, #1`
//        @ `0x005314` -> skips `ptrace(PTRACE_ATTACH)` / `PTRACE_DETACH` on remote threads.
//      - Bit 5 (`0x00020`): `tbnz w24, #5, #0x3a30` @ `0x003904` & `and w22, w19, #0x20`
//        @ `0x005b80` -> sets bit 5 (`0x20`) in `AndroidUnwinderData.flags` (`+0x28`)
//        (`resolve_names` / `unwind_for_frame` passed to `BuildFrameFromPcOnly`).
//      - Bit 6 (`0x00040`): `tbz w24, #6, #0x3918` @ `0x003908` & `tst w19, #0x40`
//        @ `0x005b78` -> sets bit 6 (`0x40`) in `AndroidUnwinderData.flags` (`+0x28`),
//        enabling DEX position info (`GetPositionInfosForDex()` / `" (position at %s)"`).
//      - Bit 7 (`0x00080`): `tbz w20, #7, #0x4174` @ `0x004118` & `tbz w19, #7, #0x5bc0`
//        @ `0x005bac` -> appends `"build id:\n"` summary section using the Red-Black Tree
//        at `0x0047dc` (filtering out `.vdex` and `.jar` mappings).
//      - Format Mode (`option & 0xF0000`, @ `0x0041c0..0x0041d0`):
//        * `0x00000` (Default): calls `AndroidUnwinder::FormatFrame(frame, show_build_id)`.
//        * `0x10000` (Compact `<...>`): formats `"    #%02zu %s%s%s\n"` with `<basename>`,
//          `(<func>)` or `<%lx>`, `<BuildId:%s>`, and `<%s>` DEX position.
//        * `0x20000` (Hex PC `0x%016lx`): formats `"0x%016lx %s%s%s%s\n"` with full map path,
//          `" (offset 0x%zx)"`, `" (%s + %zu)"` or `" (%s)"`, `" (BuildId: %s)"`, and
//          `" (position at %s)"`.
// [VN] Các cờ bit giải mã từ tập lệnh AArch64 `tbz` / `tbnz` / `ubfx` / `and`.
// ============================================================================

enum NpthUnwOptionFlags : uint32_t {
    NPTH_UNW_OPT_NONE             = 0x00000u,
    NPTH_UNW_OPT_SHOW_ALL_FRAMES  = 0x00001u,  // Bit 0: @ 0x003900
    NPTH_UNW_OPT_NO_SKIP_SELF     = 0x00002u,  // Bit 1: @ 0x003920
    NPTH_UNW_OPT_DEMANGLE         = 0x00004u,  // Bit 2: @ 0x004098, 0x005bfc
    NPTH_UNW_OPT_FRAME_BUILD_ID   = 0x00008u,  // Bit 3: @ 0x0042e4, 0x00451c, 0x004684
    NPTH_UNW_OPT_NO_PTRACE        = 0x00010u,  // Bit 4: @ 0x005040, 0x005314
    NPTH_UNW_OPT_RESOLVE_NAMES    = 0x00020u,  // Bit 5: @ 0x003904, 0x005b80
    NPTH_UNW_OPT_DEX_POSITIONS    = 0x00040u,  // Bit 6: @ 0x003908, 0x005b78
    NPTH_UNW_OPT_SUMMARY_BUILD_ID = 0x00080u,  // Bit 7: @ 0x004118, 0x005bac
    NPTH_UNW_OPT_FMT_MASK         = 0xF0000u,  // Mask:  @ 0x0041c0 (and w8, w3, #0xf0000)
    NPTH_UNW_OPT_FMT_COMPACT      = 0x10000u,  // Mode1: @ 0x0041cc (cmp w8, #0x10, lsl #12)
    NPTH_UNW_OPT_FMT_HEX_PC       = 0x20000u   // Mode2: @ 0x0041c4 (cmp w8, #0x20, lsl #12)
};

// ============================================================================
// 4. ABI STRUCT LAYOUTS VERIFIED FROM AARCH64 OPCODES (CẤU TRÚC BỘ NHỚ ABI)
// ============================================================================

// ----------------------------------------------------------------------------
// 4.1 AArch64 Raw Register Context (`264 bytes` = `33 * 8B`: `x0..x30`, `sp`, `pc`)
// [EN] Verified at `0x003e4c..0x003e94`, `0x004eec..0x004f34`, `0x005698..0x0056e0`,
//      `0x0058f0..0x005938`, `0x0059b8..0x005a00`, `0x005e70..0x005eb8`:
//        stp x0, x1, [x0]          ; +0x00..+0x0f
//        ...
//        stp x28, x29, [x0, #0xe0] ; +0xe0..+0xef
//        str x30, [x0, #0xf0]      ; +0xf0..+0xf7 (LR)
//        mov x12, sp
//        adr x13, #<capture_pc>
//        stp x12, x13, [x0, #0xf8] ; +0xf8 (SP), +0x100 (PC)
// [VN] Xác minh tại 6 vị trí chụp thanh ghi trực tiếp trong `.text`.
// ----------------------------------------------------------------------------
struct AArch64RawRegs {
    uint64_t gpr[31];  // +0x00..+0xf0 : x0..x30 (x29 = FP, x30 = LR)
    uint64_t sp;       // +0xf8        : Stack Pointer (sp)
    uint64_t pc;       // +0x100       : Program Counter (pc)
};
static_assert(sizeof(AArch64RawRegs) == 0x108, "AArch64RawRegs must be 264 bytes (0x108)");
static_assert(offsetof(AArch64RawRegs, sp) == 0xf8, "sp must be at +0xf8");
static_assert(offsetof(AArch64RawRegs, pc) == 0x100, "pc must be at +0x100");

// ----------------------------------------------------------------------------
// 4.2 `unwindstack::ElfFields` (`MapInfo::GetElfFields()` return pointer)
// [EN] Verified at `0x004460..0x004474`:
//        bl #0x6530                 ; _ZN11unwindstack7MapInfo12GetElfFieldsEv
//        ldr x8, [x0, #0x18]        ; elf_fields->elf_start_offset_ (+0x18)
// [VN] Xác minh tại `0x004460..0x004474`: `elf_start_offset_` nằm ở offset `+0x18`.
// ----------------------------------------------------------------------------
struct UnwindStackElfFieldsAbi {
    uint64_t reserved_00;       // +0x00
    uint64_t reserved_08;       // +0x08
    uint64_t elf_offset;        // +0x10
    uint64_t elf_start_offset;  // +0x18 (loaded via `ldr x8, [x0, #0x18]` @ 0x004464 & 0x004474)
};
static_assert(offsetof(UnwindStackElfFieldsAbi, elf_start_offset) == 0x18, "elf_start_offset must be +0x18");

// ----------------------------------------------------------------------------
// 4.3 `unwindstack::MapInfo` ABI Layout (`+0x00 start`, `+0x20 name`)
// [EN] Verified at `0x0041d4..0x004200`, `0x004280..0x0042b0`, `0x0043e0..0x0043f0`:
//        ldr x0, [x21, #0x40]       ; frame.map_info.get()
//        ldr x4, [x0]               ; map_info->start() at +0x00 (<anonymous:%lx>)
//        ldr x8, [x0, #0x20]        ; map_info->name() SharedString at +0x20
// [VN] Xác minh tại `0x0041d4..0x0043f0`: `+0x00` là `start`, `+0x20` là `name`.
// ----------------------------------------------------------------------------
struct UnwindStackMapInfoAbi {
    uint64_t start;                           // +0x00 : start address (`<anonymous:%lx>`)
    uint64_t end;                             // +0x08 : end address
    uint64_t offset;                          // +0x10 : file offset
    uint64_t flags;                           // +0x18 : protection flags
    std::shared_ptr<std::string> name;        // +0x20 : shared_ptr<string> name (+0x20 ptr, +0x28 ctrl)
    UnwindStackElfFieldsAbi      elf_fields;  // +0x30 : ElfFields
    std::string                  build_id;    // +0x50 : printable build ID
};
static_assert(offsetof(UnwindStackMapInfoAbi, start) == 0x00, "MapInfo::start must be +0x00");
static_assert(offsetof(UnwindStackMapInfoAbi, name) == 0x20, "MapInfo::name must be +0x20");

// ----------------------------------------------------------------------------
// 4.4 `unwindstack::FrameData` ABI Layout (`80 bytes` = `0x50`)
// [EN] Verified at:
//      - `0x003880..0x003888`: `ldr x11, [x10, #0x10]; add x10, x10, #0x50`
//        (`FrameData::pc` at `+0x10`, struct size = `0x50` = 80 bytes).
//      - `0x003894..0x0038a4` & `0x004104..0x00410c`:
//        `sub x8, x9, x8; asr x8, x8, #4; mov x9, #-0x3333333333333333; mul x20, x8, x9`
//        (Exact unsigned/signed division by `80 = 16 * 5` since `0xcccccccccccccccd * 5 == 1 mod 2^64`).
//      - `0x003cb4..0x003d20`: Destructor loop in `~AndroidUnwinderData()` (`0x003c24`)
//        steps backward by `0x50` (`sub x23, x22, #0x50` @ `0x003ce8`), releasing
//        `shared_ptr` control block at `[end - 0x08]` (`+0x48`, `map_info` control block)
//        and `[end - 0x20]` (`+0x30`, `function_name` control block).
//      - `0x0044a0..0x0044c8`: `ldr x8, [x21, #0x28]` (`function_name.get()`),
//        `ldr x5, [x21, #0x38]` (`function_offset`).
//      - `0x004520`: `ldr x0, [x21, #0x40]` (`map_info.get()`).
//      - `0x0045d8` & `0x004660`: `ldr x4, [x21, #0x08]` (`rel_pc`).
//      - `0x00473c`: `ldr x4, [x21, #0x00]` (`num`).
// [VN] Cấu trúc `unwindstack::FrameData` đúng `80 byte` (`0x50`), khớp tuyệt đối
//      từng offset lệnh `ldr`/`str` trong `.text`.
// ----------------------------------------------------------------------------
struct UnwindStackFrameDataAbi {
    uint64_t num;                                      // +0x00 : Frame index (#00, #01, ...)
    uint64_t rel_pc;                                   // +0x08 : Relative PC in ELF map
    uint64_t pc;                                       // +0x10 : Absolute Program Counter
    uint64_t sp;                                       // +0x18 : Stack Pointer
    uint64_t is_dex_pc;                                // +0x20 : Flags / dex_pc indicator
    std::shared_ptr<std::string> function_name;        // +0x28 : +0x28 string*, +0x30 ctrl_block*
    uint64_t function_offset;                          // +0x38 : Offset inside function
    std::shared_ptr<UnwindStackMapInfoAbi> map_info;   // +0x40 : +0x40 MapInfo*, +0x48 ctrl_block*
};
static_assert(sizeof(UnwindStackFrameDataAbi) == 0x50, "UnwindStackFrameDataAbi must be 80 bytes (0x50)");
static_assert(offsetof(UnwindStackFrameDataAbi, num) == 0x00, "num at +0x00");
static_assert(offsetof(UnwindStackFrameDataAbi, rel_pc) == 0x08, "rel_pc at +0x08");
static_assert(offsetof(UnwindStackFrameDataAbi, pc) == 0x10, "pc at +0x10");
static_assert(offsetof(UnwindStackFrameDataAbi, sp) == 0x18, "sp at +0x18");
static_assert(offsetof(UnwindStackFrameDataAbi, function_name) == 0x28, "function_name at +0x28");
static_assert(offsetof(UnwindStackFrameDataAbi, function_offset) == 0x38, "function_offset at +0x38");
static_assert(offsetof(UnwindStackFrameDataAbi, map_info) == 0x40, "map_info at +0x40");

// ----------------------------------------------------------------------------
// 4.5 `unwindstack::Registers` Wrapper (`16 bytes` = `0x10`)
// [EN] Verified at `0x005ef0..0x005f04` and `0x005fb8..0x005fc8` (`npth_unw_context_regs`):
//      `ldr x8, [x0, #8]!` -> `Registers` holds a `std::unique_ptr<unwindstack::Regs>`
//      at `+0x00` (`8 B`) plus `8 B` metadata/arch tag (`16 B` total on stack at
//      `sp+0x10..sp+0x1f` in `0x003e30`, `0x0058d4`, `0x00599c`, `0x005a60`, `0x005e54`).
// [VN] Cấu trúc `unwindstack::Registers` (`16 byte` = `0x10`).
// ----------------------------------------------------------------------------
struct UnwindStackRegistersAbi {
    AArch64RawRegs* regs_ptr;  // +0x00 : Pointer to Regs / raw register buffer
    uint64_t        arch_tag;  // +0x08 : Architecture tag / ownership flag
};
static_assert(sizeof(UnwindStackRegistersAbi) == 0x10, "UnwindStackRegistersAbi must be 16 bytes (0x10)");

// ----------------------------------------------------------------------------
// 4.6 `unwindstack::AndroidUnwinderData` (`160 bytes` = `0xA0`)
// [EN] Verified from constructor sequence at `0x0037e4..0x003860` & `0x00402c..0x00408c`
//      and destructor `~AndroidUnwinderData()` at `0x003c24..0x003d48`:
//      - `+0x00..+0x17`: `std::vector<FrameData> frames` (`+0x00 begin`, `+0x08 end`, `+0x10 cap`)
//      - `+0x18`       : `uint8_t error_valid` (initialized `strb wzr, [sp, #0x18]`)
//      - `+0x20`       : `uint64_t error_code` (initialized `str xzr, [sp, #0x20]`)
//      - `+0x28`       : `uint32_t unwind_flags` (initialized `mov w8, #0x10; str w8, [sp, #0x28]`)
//      - `+0x30`       : `size_t max_frames` (initialized to `0x200`, then clamped to `min(max, 0x100)`)
//      - `+0x38`       : `void* saved_context` (checked at `0x003c34`, freed via `FreeContext()`)
//      - `+0x40..+0x4f`: `unwindstack::Registers saved_regs` (constructed via `Registers(nullptr)`
//                        at `0x003804..0x003828`, destroyed at `0x003c94..0x003c98`)
//      - `+0x50..+0x67`: `std::vector<std::string> initial_map_names_to_skip`
//                        (populated with `"libnpth_unwind.so"` and `"libnpth_unw.so"` at `0x003928..0x003b18`)
//      - `+0x68`       : `uint64_t dex_positions_ptr` (returned by `GetPositionInfosForDex()` `0x0062f0`)
//      - `+0x70..+0x8f`: Inline SBO buffer for `std::function` (`32 B`)
//      - `+0x90`       : `void* function_vptr_or_heap` (checked against `this + 0x70` at `0x003c44..0x003c74`)
//      - `+0x98`       : `uint64_t reserved_98`
// [VN] Cấu trúc `unwindstack::AndroidUnwinderData` (`160 byte` = `0xA0`).
// ----------------------------------------------------------------------------
struct AndroidUnwinderDataAbi {
    UnwindStackFrameDataAbi* frames_begin;   // +0x00
    UnwindStackFrameDataAbi* frames_end;     // +0x08
    UnwindStackFrameDataAbi* frames_cap;     // +0x10
    uint8_t                  error_valid;    // +0x18
    uint8_t                  pad_19[7];      // +0x19..+0x1f
    uint64_t                 error_code;     // +0x20
    uint32_t                 unwind_flags;   // +0x28 (init 0x10, ORed with 0x01, 0x20, 0x40)
    uint32_t                 pad_2c;         // +0x2c
    uint64_t                 max_frames;     // +0x30 (init 0x200, set to min(max, 0x100))
    void*                    saved_context;  // +0x38 (freed by FreeContext() if non-null)
    UnwindStackRegistersAbi  saved_regs;     // +0x40..+0x4f (16 B)
    std::string*             skip_begin;     // +0x50
    std::string*             skip_end;       // +0x58
    std::string*             skip_cap;       // +0x60
    std::vector<std::string>* dex_positions; // +0x68
    uint8_t                  func_sbo[32];   // +0x70..+0x8f
    void*                    func_target;    // +0x90
    uint64_t                 reserved_98;    // +0x98
};
static_assert(sizeof(AndroidUnwinderDataAbi) == 0xA0, "AndroidUnwinderDataAbi must be 160 bytes (0xA0)");
static_assert(offsetof(AndroidUnwinderDataAbi, unwind_flags) == 0x28, "unwind_flags at +0x28");
static_assert(offsetof(AndroidUnwinderDataAbi, max_frames) == 0x30, "max_frames at +0x30");
static_assert(offsetof(AndroidUnwinderDataAbi, saved_context) == 0x38, "saved_context at +0x38");
static_assert(offsetof(AndroidUnwinderDataAbi, saved_regs) == 0x40, "saved_regs at +0x40");
static_assert(offsetof(AndroidUnwinderDataAbi, skip_begin) == 0x50, "skip_begin at +0x50");
static_assert(offsetof(AndroidUnwinderDataAbi, func_target) == 0x90, "func_target at +0x90");

// ----------------------------------------------------------------------------
// 4.7 `NpthUnwContext` (`40 bytes` = `0x28`)
// [EN] Allocated in `npth_unw_context_create` (`0x005e34..0x005f58`):
//        mov w0, #0x28              ; 40 bytes @ 0x005ee4
//        bl  #0x61b0                ; operator new(0x28) @ 0x005ee8
//        mov x20, x0
//        add x0, x0, #8             ; &ctx->regs (+0x08) @ 0x005ef0
//        str w19, [x20]             ; ctx->tid = tid (+0x00) @ 0x005ef8
//        bl  #0x6210                ; Registers::Registers(Registers&&) @ 0x005efc
//        ldr q0, [sp]               ; shared_ptr<Memory> (16 bytes) @ 0x005f00
//        stur q0, [x20, #0x18]      ; ctx->memory (+0x18..+0x27) @ 0x005f04
//      Destroyed in `npth_unw_context_destroy` (`0x005f5c..0x005fb4`):
//        ldr x20, [x0, #0x20]       ; ctx->memory.__cntrl_ (+0x20) @ 0x005f6c
//        ... atomic_fetch_add(-1) ...
//        add x0, x19, #8            ; &ctx->regs (+0x08) @ 0x005f9c
//        bl  #0x6160                ; Registers::~Registers() @ 0x005fa0
//        b   #0x6220                ; operator delete(ctx) @ 0x005fb0
// [VN] Cấu trúc `NpthUnwContext` (`40 byte` = `0x28`) cấp phát trong `npth_unw_context_create`.
// ----------------------------------------------------------------------------
struct NpthUnwContext {
    int32_t                  tid;             // +0x00 : Target thread ID
    int32_t                  pad_04;          // +0x04 : Alignment padding
    UnwindStackRegistersAbi  regs;            // +0x08 : Captured registers (16 B)
    void*                    memory_ptr;      // +0x18 : shared_ptr<unwindstack::Memory>::__ptr_
    void*                    memory_cntrl;    // +0x20 : shared_ptr<unwindstack::Memory>::__cntrl_
};
static_assert(sizeof(NpthUnwContext) == 0x28, "NpthUnwContext must be 40 bytes (0x28)");
static_assert(offsetof(NpthUnwContext, tid) == 0x00, "tid at +0x00");
static_assert(offsetof(NpthUnwContext, regs) == 0x08, "regs at +0x08");
static_assert(offsetof(NpthUnwContext, memory_ptr) == 0x18, "memory_ptr at +0x18");
static_assert(offsetof(NpthUnwContext, memory_cntrl) == 0x20, "memory_cntrl at +0x20");

// ----------------------------------------------------------------------------
// 4.8 `BuildIdRbTreeNode` (`56 bytes` = `0x38`) & `BuildIdRbTreeRoot` (`24 bytes`)
// [EN] Verified in `InsertBuildIdIntoRbTree` (`0x0047dc..0x004c78`) and
//      `DestroyBuildIdRbTree` (`0x0047a0..0x0047d8`):
//        mov w0, #0x38              ; 56 bytes @ 0x004a60
//        bl  #0x61b0                ; operator new(0x38) @ 0x004a64
//        stp xzr, xzr, [x0]         ; node->left = nullptr (+0x00), node->right = nullptr (+0x08) @ 0x004a78
//        str x21, [x0, #0x10]       ; node->parent = parent (+0x10) @ 0x004a84
//        strb w8, [x0, #0x18]       ; node->is_black = (node == root) (+0x18) @ 0x004aac
//        str q0, [x0, #0x20]        ; node->key_string (+0x20..+0x2f) @ 0x004a7c
//        str x8, [x0, #0x30]        ; node->key_string.data (+0x30) @ 0x004a80
// [VN] Nút Cây Đỏ-Đen `BuildIdRbTreeNode` (`56 byte` = `0x38`) lưu danh sách
//      ELF BuildId duy nhất (loại trừ `.vdex` và `.jar`).
// ----------------------------------------------------------------------------
struct LibcxxSsoStringAbi {
    uint64_t cap_and_is_long;  // +0x00 : bit 0 = is_long; if short, bits 1..7 = size
    uint64_t size;             // +0x08 : if long, string length
    char*    data;             // +0x10 : if long, heap pointer (freed via operator delete if bit 0 == 1)
};
static_assert(sizeof(LibcxxSsoStringAbi) == 0x18, "LibcxxSsoStringAbi must be 24 bytes (0x18)");

struct BuildIdRbTreeNode {
    BuildIdRbTreeNode* left;       // +0x00 : Left child
    BuildIdRbTreeNode* right;      // +0x08 : Right child
    BuildIdRbTreeNode* parent;     // +0x10 : Parent node
    uint8_t            is_black;   // +0x18 : 1 = Black, 0 = Red
    uint8_t            pad_19[7];  // +0x19..+0x1f
    std::string        key;        // +0x20..+0x37 : Full ELF map path key (24 B in Android NDK libc++)
};

struct BuildIdRbTreeHeader {
    BuildIdRbTreeNode* begin_node; // +0x00 : Leftmost node (`sp+0x08` in 0x004130, `sp+0x70` in 0x005b74)
    BuildIdRbTreeNode* root_node;  // +0x08 : Root pointer (`end_node` left child at `+0x08`)
    size_t             node_count; // +0x10 : Number of unique ELF maps inserted (`+0x10` incremented @ 0x004c3c)
};
static_assert(sizeof(BuildIdRbTreeHeader) == 0x18, "BuildIdRbTreeHeader must be 24 bytes (0x18)");

// ----------------------------------------------------------------------------
// 4.9 `SharedStringControlBlock` (`48 bytes` = `0x30`, vtable at `.data.rel.ro 0x00a5c8`)
// [EN] Verified at `0x005c10..0x005c40` and `0x005de0..0x005e28`:
//      - Allocated via `operator new(0x30)` (`mov w0, #0x30; bl #0x61b0` @ `0x005c10..0x005c14`)
//      - `+0x00`: `vptr = 0x00a5d8` (`.data.rel.ro + 0x18`)
//        * `[0] +0x00` (`0x00a5d8`): `0x005de0` (`~__shared_ptr_emplace() noexcept` base dtor)
//        * `[1] +0x08` (`0x00a5e0`): `0x005df0` (`~__shared_ptr_emplace() noexcept` deleting dtor)
//        * `[2] +0x10` (`0x00a5e8`): `0x005e14` (`__on_zero_shared()` — frees `std::string` at `+0x18`)
//        * `[3] +0x18` (`0x00a5f0`): `_ZNKSt6__ndk119__shared_weak_count13__get_deleterERKSt9type_info`
//        * `[4] +0x20` (`0x00a5f8`): `0x005e28` (`__on_zero_shared_weak()` — `operator delete(this)`)
//      - `+0x08`: `int64_t shared_owners` (initialized to 0 = 1 owner via `stp xzr, xzr, [x0, #8]`)
//      - `+0x10`: `int64_t shared_weak_owners` (initialized to 0)
//      - `+0x18..+0x2f`: `LibcxxSsoStringAbi embedded_string` (`24 B`, demangled function name)
// [VN] Khối điều khiển `std::shared_ptr<std::string>` (`48 byte` = `0x30`) với
//      bảng phương thức ảo tại `.data.rel.ro 0x00a5d8`.
// ----------------------------------------------------------------------------
struct SharedStringEmplaceControlBlock {
    const void*        vptr;                // +0x00 : Points to 0x00a5d8 (.data.rel.ro)
    int64_t            shared_owners;       // +0x08 : __shared_owners_ (0 = 1 active owner)
    int64_t            shared_weak_owners;  // +0x10 : __shared_weak_owners_
    LibcxxSsoStringAbi embedded_str;        // +0x18..+0x2f : In-place std::__ndk1::string (24 B)
};
static_assert(sizeof(SharedStringEmplaceControlBlock) == 0x30, "SharedStringEmplaceControlBlock must be 48 bytes (0x30)");
static_assert(offsetof(SharedStringEmplaceControlBlock, embedded_str) == 0x18, "embedded_str at +0x18");

} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
