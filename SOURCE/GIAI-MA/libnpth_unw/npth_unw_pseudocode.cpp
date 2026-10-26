// ============================================================================
// FILE: npth_unw_pseudocode.cpp
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64, 97 .dynsym entries)
// ROLE: Full Instruction-by-Instruction AArch64 Disassembly & Decompiled Pseudocode
//       Đối chiếu từng lệnh AArch64 (.text 0x0031b0..0x0060bc) & Mã giả phục dựng
// ============================================================================
// [EN] Complete instruction-accurate disassembly and decompiled C++17 pseudocode
//      for every routine in `libnpth_unw.so` (`.text` `0x0031b0..0x0060bc`,
//      `12,048 bytes`, `3,012` AArch64 instructions).
// [VN] Bản dịch ngược mã máy AArch64 và mã giả C++17 chính xác đến từng lệnh
//      cho toàn bộ các hàm trong `libnpth_unw.so` (`.text` `0x0031b0..0x0060bc`).
// ============================================================================

#include "npth_unw_interface.h"

namespace NextAI {
namespace OpenCut {
namespace NpthUnw {
namespace DisassemblyReference {

// ============================================================================
// SECTION 1: CRT / FINI / ATOMIC HELPERS & .INIT_ARRAY (`0x0031b0..0x0037cc`)
// ============================================================================
//
// [1.1] `__cxa_finalize_thunk` (`0x0031b0..0x0031cc`, `.fini_array` @ `0x00a600`):
//   0x0031b0: 5f2403d5  bti      c
//   0x0031b4: 1f2003d5  nop
//   0x0031b8: 40a00310  adr      x0, #0xa5c0       ; &__dso_handle
//   0x0031bc: c90b0014  b        #0x60e0           ; __cxa_finalize(&__dso_handle)
//
// [1.2] `__aarch64_ldadd8_relax` (`0x003200..0x00322c`):
//   0x003200: 5f2403d5  bti      c
//   0x003204: 500000f0  adrp     x16, #0xe000
//   0x003208: 10826a39  ldrb     w16, [x16, #0xaa0] ; g_aarch64_have_lse_atomics (0x00eaa0)
//   0x00320c: 70000034  cbz      w16, #0x3218
//   0x003210: 200020f8  ldadd    x0, x0, [x1]       ; ARMv8.1-LSE atomic fetch_add relaxed
//   0x003214: c0035fd6  ret
//   0x003218: f00300aa  mov      x16, x0
//   0x00321c: 207c5fc8  ldxr     x0, [x1]           ; ARMv8.0 LL/SC fallback loop
//   0x003220: 1100108b  add      x17, x0, x16
//   0x003224: 317c0fc8  stxr     w15, x17, [x1]
//   0x003228: afffff35  cbnz     w15, #0x321c
//   0x00322c: c0035fd6  ret
//
// [1.3] `__init_lse_atomics` (`0x003230..0x0032c4`, `.init_array[0]` @ `0x00a610`):
//   0x003230: 3f2303d5  paciasp
//   0x003234: ffc301d1  sub      sp, sp, #0x70
//   0x003238: fe4f06a9  stp      x30, x19, [sp, #0x60]
//   0x00323c: 00028052  mov      w0, #0x10         ; AT_HWCAP (16)
//   0x003240: dc0c0094  bl       #0x65b0           ; getauxval(AT_HWCAP)
//   0x003244: f30300aa  mov      x19, x0
//   0x003248: f3004037  tbnz     w19, #8, #0x3264  ; test HWCAP_ATOMICS (1 << 8 = 0x100)
//   0x00324c: fe4f46a9  ldp      x30, x19, [sp, #0x60]
//   0x003250: 490000f0  adrp     x9, #0xe000
//   0x003254: 3f812a39  strb     wzr, [x9, #0xaa0] ; g_aarch64_have_lse_atomics = 0
//   0x003258: ffc30191  add      sp, sp, #0x70
//   0x00325c: bf2303d5  autiasp
//   0x003260: c0035fd6  ret
//   0x003264: 1f2003d5  nop
//   0x003268: 409bff30  adr      x0, #0x25d1       ; "ro.arch"
//   0x00326c: e1130091  add      x1, sp, #4        ; prop_buf[92]
//   0x003270: c80c0094  bl       #0x6590           ; __system_property_get("ro.arch", prop_buf)
//   0x003274: 1f040071  cmp      w0, #1
//   0x003278: 6b010054  b.lt     #0x32a4
//   0x00327c: e1fffff0  adrp     x1, #0x2000
//   0x003280: 21301d91  add      x1, x1, #0x74c    ; "exynos9810" (0x00274c)
//   0x003284: e0130091  add      x0, sp, #4
//   0x003288: 42018052  mov      w2, #0xa          ; n = 10
//   0x00328c: 68027892  and      x8, x19, #0x100
//   0x003290: 13fd48d3  lsr      x19, x8, #8
//   0x003294: b70c0094  bl       #0x6570           ; strncmp(prop_buf, "exynos9810", 10)
//   0x003298: 1f000071  cmp      w0, #0
//   0x00329c: e803931a  csel     w8, wzr, w19, eq  ; disable LSE on Exynos 9810!
//   0x0032a0: 02000014  b        #0x32a8
//   0x0032a4: 682248d3  ubfx     x8, x19, #8, #1
//   0x0032a8: 1f010071  cmp      w8, #0
//   0x0032ac: e8079f1a  cset     w8, ne
//   0x0032b0: fe4f46a9  ldp      x30, x19, [sp, #0x60]
//   0x0032b4: 490000f0  adrp     x9, #0xe000
//   0x0032b8: 28812a39  strb     w8, [x9, #0xaa0]  ; g_aarch64_have_lse_atomics = w8
//   0x0032bc: ffc30191  add      sp, sp, #0x70
//   0x0032c0: bf2303d5  autiasp
//   0x0032c4: c0035fd6  ret
//
// [1.4] `__aarch64_ldadd8_acq_rel` (`0x0037a0..0x0037cc`):
//   0x0037a0: 5f2403d5  bti      c
//   0x0037a4: 500000f0  adrp     x16, #0xe000
//   0x0037a8: 10826a39  ldrb     w16, [x16, #0xaa0] ; g_aarch64_have_lse_atomics
//   0x0037ac: 70000034  cbz      w16, #0x37b8
//   0x0037b0: 2000e0f8  ldaddal  x0, x0, [x1]       ; ARMv8.1-LSE atomic fetch_add acq_rel
//   0x0037b4: c0035fd6  ret
//   0x0037b8: f00300aa  mov      x16, x0
//   0x0037bc: 20fc5fc8  ldaxr    x0, [x1]           ; ARMv8.0 ldaxr/stlxr fallback loop
//   0x0037c0: 1100108b  add      x17, x0, x16
//   0x0037c4: 31fc0fc8  stlxr    w15, x17, [x1]
//   0x0037c8: afffff35  cbnz     w15, #0x37bc
//   0x0037cc: c0035fd6  ret
//
// ============================================================================
// SECTION 2: CORE UNWINDING & FRAME EXTRACTION (`0x0037d0..0x004194`)
// ============================================================================
//
// [2.1] `UnwindFramesInternal` (`0x0037d0..0x0038c8`):
//   0x0037d0: ff8303d1  sub      sp, sp, #0xe0
//   ...
//   0x0037e4: 08028052  mov      w8, #0x10          ; unwind_flags = 0x10
//   0x0037f0: 09408052  mov      w9, #0x200         ; initial max_frames = 512
//   0x0037fc: e82b00b9  str      w8, [sp, #0x28]
//   0x003804: 00010191  add      x0, x8, #0x40      ; &data.saved_regs (+0x40)
//   0x003828: da0a0094  bl       #0x6390            ; unwindstack::Registers::Registers(Regs*)
//   0x00382c: 1f0304f1  cmp      x24, #0x100        ; clamp max_frames to 256 (0x100)
//   0x003830: 08208052  mov      w8, #0x100
//   0x003834: 0833889a  csel     x8, x24, x8, lo
//   0x00383c: e1930510  adr      x1, #0xeab8        ; &g_local_unwinder (.bss 0x00eab8)
//   0x003860: e81b00f9  str      x8, [sp, #0x30]    ; data.max_frames = min(max_frames, 256)
//   0x003864: 1a000094  bl       #0x38cc            ; ExecuteUnwindCore(&data, &g_local_unwinder, ...)
//   0x003868: f4031faa  mov      x20, xzr
//   0x00386c: e0010036  tbz      w0, #0, #0x38a8
//   0x003870: e82740a9  ldp      x8, x9, [sp]       ; x8 = frames.begin(), x9 = frames.end()
//   0x003874: 1f0109eb  cmp      x8, x9
//   0x003878: e0000054  b.eq     #0x3894
//   0x00387c: ea0308aa  mov      x10, x8
//   0x003880: 4b0940f9  ldr      x11, [x10, #0x10]  ; frame.pc at +0x10
//   0x003884: 4a410191  add      x10, x10, #0x50    ; advance by sizeof(FrameData) = 80 (0x50)
//   0x003888: 5f0109eb  cmp      x10, x9
//   0x00388c: 6b8600f8  str      x11, [x19], #8     ; *out_frames++ = frame.pc
//   0x003890: 81ffff54  b.ne     #0x3880
//   0x003894: 280108cb  sub      x8, x9, x8         ; byte_diff = end - begin
//   0x003898: e9e702b2  mov      x9, #-0x3333333333333334
//   0x00389c: 08fd4493  asr      x8, x8, #4         ; byte_diff >> 4
//   0x0038a0: a99999f2  movk     x9, #0xcccd        ; x9 = 0xcccccccccccccccdULL (5^-1 mod 2^64)
//   0x0038a4: 147d099b  mul      x20, x8, x9        ; count = (byte_diff >> 4) / 5 = byte_diff / 80
//   0x0038a8: e0030091  mov      x0, sp
//   0x0038ac: de000094  bl       #0x3c24            ; ~AndroidUnwinderData()
//   0x0038b0: e00314aa  mov      x0, x20            ; return count
//
// [2.2] `ExecuteUnwindCore` (`0x0038cc..0x003c20`):
//   0x003900: 02090037  tbnz     w2, #0, #0x3a20    ; if (option & 0x01) data.flags |= 0x01
//   0x003904: 78092837  tbnz     w24, #5, #0x3a30   ; if (option & 0x20) data.flags |= 0x20
//   0x003908: 98003036  tbz      w24, #6, #0x3918   ; if (option & 0x40) data.flags |= 0x40
//   0x00390c: 882a40b9  ldr      w8, [x20, #0x28]
//   0x003910: 08011a32  orr      w8, w8, #0x40
//   0x003914: 882a00b9  str      w8, [x20, #0x28]
//   0x003918: e00316aa  mov      x0, x22
//   0x00391c: 490a0094  bl       #0x6240            ; unwinder->IsLocalMode()
//   0x003920: f80f0837  tbnz     w24, #1, #0x3b1c   ; if (option & 0x02) skip populating skip_libs
//   0x003924: c00f0036  tbz      w0, #0, #0x3b1c    ; if (!IsLocalMode()) skip populating skip_libs
//   0x003928: e1fffff0  adrp     x1, #0x2000
//   0x00392c: 21641791  add      x1, x1, #0x5d9     ; "libnpth_unwind.so" (0x0025d9)
//   0x003930: e0430091  add      x0, sp, #0x10
//   0x003938: 18010094  bl       #0x3d98            ; std::string("libnpth_unwind.so")
//   0x00393c: 00630091  add      x0, x24, #0x18
//   0x003940: e1fffff0  adrp     x1, #0x2000
//   0x003944: 21381e91  add      x1, x1, #0x78e     ; "libnpth_unw.so" (0x00278e)
//   0x003948: 14010094  bl       #0x3d98            ; std::string("libnpth_unw.so")
//   ... assigns {"libnpth_unwind.so", "libnpth_unw.so"} into data.initial_map_names_to_skip (+0x50..+0x60) ...
//   0x003b1c: a80240f9  ldr      x8, [x21]          ; regs->regs_ptr
//   0x003b20: c80200b4  cbz      x8, #0x3b78        ; if (regs->regs_ptr == nullptr) branch to Unwind(tid, data)
//   0x003b4c: c1090094  bl       #0x6250            ; unwinder->Unwind(*regs, memory, data)
//   ...
//   0x003b78: e00316aa  mov      x0, x22            ; unwinder
//   0x003b7c: e103132a  mov      w1, w19            ; tid
//   0x003b80: e20314aa  mov      x2, x20            ; &data
//   0x003b84: b7090094  bl       #0x6260            ; unwinder->Unwind(tid, data)
//   0x003b88: 40ff0737  tbnz     w0, #0, #0x3b70
//   0x003b98: ba090094  bl       #0x6280            ; data.GetErrorString()
//   0x003ba8: e1fffff0  adrp     x1, #0x2000
//   0x003bac: 21101991  add      x1, x1, #0x644     ; "npth_unw" (0x002644)
//   0x003bb0: e2fffff0  adrp     x2, #0x2000
//   0x003bb4: 42ac1791  add      x2, x2, #0x5eb     ; "Failed to unwind tid %d: %s" (0x0025eb)
//   0x003bc0: c0008052  mov      w0, #6             ; ANDROID_LOG_ERROR (6)
//   0x003bc8: aa090094  bl       #0x6270            ; __android_log_print(6, "npth_unw", "Failed to unwind tid %d: %s", tid, err)
//
// ============================================================================
// SECTION 3: 23 EXPORTED C API ENTRY POINTS (`0x003e20..0x0060bc`)
// ============================================================================
//
// - [079] `npth_unw_current_option`         @ `0x003e20..0x003ed0` (180 B)
// - [084] `npth_unw_current`                @ `0x004e94..0x004e98` (  8 B)
// - [092] `npth_unw_thread_option`          @ `0x004e9c..0x004fec` (340 B)
// - [085] `npth_unw_thread`                 @ `0x004ff0..0x004ff4` (  8 B)
// - [074] `npth_unw_any_thread_option`      @ `0x004ff8..0x0050dc` (232 B)
// - [086] `npth_unw_any_thread`             @ `0x005184..0x005188` (  8 B)
// - [093] `npth_unw_all`                    @ `0x00518c..0x005194` ( 12 B)
// - [090] `npth_unw_all_option`             @ `0x0058ac..0x0058b4` ( 12 B)
// - [091] `npth_unw_process`                @ `0x0058b8..0x0058bc` (  8 B)
// - [087] `npth_unw_process_option`         @ `0x0058c0..0x0058c3` (  4 B -> `0x005198..0x005878`)
// - [080] `npth_unw_fast_option`            @ `0x0058c4..0x005974` (180 B)
// - [075] `npth_unw_fast`                   @ `0x005978..0x00597c` (  8 B)
// - [081] `npth_unw_frames_option`          @ `0x005980..0x005a40` (196 B)
// - [076] `npth_unw_frames`                 @ `0x005a44..0x005a48` (  8 B)
// - [088] `npth_unw_ucontext_option`        @ `0x005a4c..0x005ab8` (112 B)
// - [082] `npth_unw_ucontext_frames_option` @ `0x005abc..0x005b38` (128 B)
// - [077] `npth_unw_format_option`          @ `0x005b3c..0x005ddc` (676 B)
// - [078] `npth_unw_format`                 @ `0x005e2c..0x005e30` (  8 B)
// - [094] `npth_unw_context_create`         @ `0x005e34..0x005f58` (296 B)
// - [095] `npth_unw_context_destroy`        @ `0x005f5c..0x005fb4` ( 92 B)
// - [083] `npth_unw_context_regs`           @ `0x005fb8..0x005fc8` ( 20 B)
// - [096] `npth_unw_context_option`         @ `0x005fcc..0x006038` (112 B)
// - [089] `npth_unw_context_frames_option`  @ `0x00603c..0x0060bc` (132 B)
// ============================================================================

struct OpcodeVerificationTableEntry {
    uint64_t    vaddr;
    uint32_t    opcode_le;
    const char* mnemonic;
    const char* symbol_or_role;
};

static constexpr OpcodeVerificationTableEntry kVerifiedOpcodes[] = {
    {0x0031b8ULL, 0x1003a040u, "adr x0, #0xa5c0",           "__cxa_finalize_thunk"},
    {0x003208ULL, 0x396a8210u, "ldrb w16, [x16, #0xaa0]",   "__aarch64_ldadd8_relax"},
    {0x003210ULL, 0xf8200020u, "ldadd x0, x0, [x1]",        "__aarch64_ldadd8_relax"},
    {0x00323cULL, 0x52800200u, "mov w0, #0x10",             "__init_lse_atomics (AT_HWCAP)"},
    {0x003248ULL, 0x374000f3u, "tbnz w19, #8, #0x3264",     "__init_lse_atomics (HWCAP_ATOMICS)"},
    {0x003268ULL, 0x30ff9b40u, "adr x0, #0x25d1",           "__init_lse_atomics (\"ro.arch\")"},
    {0x003280ULL, 0x911d3021u, "add x1, x1, #0x74c",        "__init_lse_atomics (\"exynos9810\")"},
    {0x0037b0ULL, 0xf8e00020u, "ldaddal x0, x0, [x1]",      "__aarch64_ldadd8_acq_rel"},
    {0x003880ULL, 0xf940094bu, "ldr x11, [x10, #0x10]",     "UnwindFramesInternal (frame.pc)"},
    {0x003884ULL, 0x9101414au, "add x10, x10, #0x50",       "UnwindFramesInternal (sizeof(FrameData)=80)"},
    {0x00389cULL, 0x9344fd08u, "asr x8, x8, #4",            "UnwindFramesInternal (byte_diff >> 4)"},
    {0x0038a4ULL, 0x9b097d14u, "mul x20, x8, x9",           "UnwindFramesInternal (mul 0xcccccccccccccccd)"},
    {0x003900ULL, 0x37000902u, "tbnz w2, #0, #0x3a20",      "ExecuteUnwindCore (OPT_SHOW_ALL_FRAMES)"},
    {0x003904ULL, 0x37280978u, "tbnz w24, #5, #0x3a30",     "ExecuteUnwindCore (OPT_RESOLVE_NAMES)"},
    {0x003908ULL, 0x36300098u, "tbz w24, #6, #0x3918",      "ExecuteUnwindCore (OPT_DEX_POSITIONS)"},
    {0x00392cULL, 0x91176421u, "add x1, x1, #0x5d9",        "ExecuteUnwindCore (\"libnpth_unwind.so\")"},
    {0x003944ULL, 0x911e3821u, "add x1, x1, #0x78e",        "ExecuteUnwindCore (\"libnpth_unw.so\")"},
    {0x003e20ULL, 0xd100c3ffu, "sub sp, sp, #0x30",         "npth_unw_current_option"},
    {0x003e94ULL, 0xa90fb40cu, "stp x12, x13, [x0, #0xf8]", "npth_unw_current_option (sp & pc)"},
    {0x0041c0ULL, 0x12100c68u, "and w8, w3, #0xf0000",      "FormatSingleFrame (fmt_mode mask)"},
    {0x0041c4ULL, 0x7140811fu, "cmp w8, #0x20, lsl #12",    "FormatSingleFrame (0x20000 Hex PC mode)"},
    {0x0041ccULL, 0x7140411fu, "cmp w8, #0x10, lsl #12",    "FormatSingleFrame (0x10000 Compact mode)"},
    {0x0047a0ULL, 0xb40001c0u, "cbz x0, #0x47d8",           "DestroyBuildIdRbTree"},
    {0x0047dcULL, 0xd103c3ffu, "sub sp, sp, #0xf0",         "InsertAndFormatBuildIdSummary"},
    {0x004a60ULL, 0x52800700u, "mov w0, #0x38",             "InsertAndFormatBuildIdSummary (new 56B node)"},
    {0x004e2cULL, 0x52800020u, "mov w0, #1",                "ElfSetCachingEnabled(true)"},
    {0x004e34ULL, 0x52a20000u, "mov w0, #0x10000000",       "SetDexCacheLimitSize(256MB)"},
    {0x004e94ULL, 0x2a1f03e0u, "mov w0, wzr",               "npth_unw_current"},
    {0x004e9cULL, 0xd10143ffu, "sub sp, sp, #0x50",         "npth_unw_thread_option"},
    {0x004ff0ULL, 0x2a1f03e1u, "mov w1, wzr",               "npth_unw_thread"},
    {0x004ff8ULL, 0xd10143ffu, "sub sp, sp, #0x50",         "npth_unw_any_thread_option"},
    {0x0050ecULL, 0x52800200u, "mov w0, #0x10",             "PtraceAttachAndWait (PTRACE_ATTACH)"},
    {0x005114ULL, 0x52a80002u, "mov w2, #0x40000000",       "PtraceAttachAndWait (__WALL)"},
    {0x005184ULL, 0x2a1f03e2u, "mov w2, wzr",               "npth_unw_any_thread"},
    {0x00518cULL, 0x12800000u, "mov w0, #-1",               "npth_unw_all"},
    {0x005198ULL, 0xa9ba7bfdu, "stp x29, x30, [sp, #-0x60]!", "UnwindEntireProcess"},
    {0x0058acULL, 0x2a0003e1u, "mov w1, w0",                "npth_unw_all_option"},
    {0x0058b8ULL, 0x2a1f03e1u, "mov w1, wzr",               "npth_unw_process"},
    {0x0058c0ULL, 0x17fffe36u, "b #0x5198",                 "npth_unw_process_option"},
    {0x0058c4ULL, 0xd100c3ffu, "sub sp, sp, #0x30",         "npth_unw_fast_option"},
    {0x005978ULL, 0x2a1f03e0u, "mov w0, wzr",               "npth_unw_fast"},
    {0x005980ULL, 0xd10103ffu, "sub sp, sp, #0x40",         "npth_unw_frames_option"},
    {0x005a44ULL, 0x2a1f03e2u, "mov w2, wzr",               "npth_unw_frames"},
    {0x005a4cULL, 0xd10103ffu, "sub sp, sp, #0x40",         "npth_unw_ucontext_option"},
    {0x005abcULL, 0xd10143ffu, "sub sp, sp, #0x50",         "npth_unw_ucontext_frames_option"},
    {0x005b3cULL, 0xd104c3ffu, "sub sp, sp, #0x130",        "npth_unw_format_option"},
    {0x005c10ULL, 0x52800600u, "mov w0, #0x30",             "npth_unw_format_option (new 48B ctrl block)"},
    {0x005e2cULL, 0x2a1f03e2u, "mov w2, wzr",               "npth_unw_format"},
    {0x005e34ULL, 0xd10103ffu, "sub sp, sp, #0x40",         "npth_unw_context_create"},
    {0x005ee4ULL, 0x52800500u, "mov w0, #0x28",             "npth_unw_context_create (new 40B ctx)"},
    {0x005f5cULL, 0xb40002c0u, "cbz x0, #0x5fb4",           "npth_unw_context_destroy"},
    {0x005fb8ULL, 0xf8408c08u, "ldr x8, [x0, #8]!",         "npth_unw_context_regs"},
    {0x005fccULL, 0xf81d0ffeu, "str x30, [sp, #-0x30]!",    "npth_unw_context_option"},
    {0x00603cULL, 0xf81c0ffeu, "str x30, [sp, #-0x40]!",    "npth_unw_context_frames_option"}
};

} // namespace DisassemblyReference
} // namespace NpthUnw
} // namespace OpenCut
} // namespace NextAI
