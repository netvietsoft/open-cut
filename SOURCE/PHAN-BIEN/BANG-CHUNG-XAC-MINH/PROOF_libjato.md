# Clean-Room C++17 Reconstruction: `libjato.so` (ByteDance Jato — Java Android Tuning Optimizer)
- **Target Number**: 99 / 169 (`TASK-138-RECONSTRUCTION-LIBJATO` / `TASK_SO_109_libjato`)
- **Binary Size**: `362,800 bytes`
- **SHA-256**: `0333b9ad7314644975997ba1a375bec370225ee72f7adf1123c83637e09fa3fc`
- **FDE Count (`.eh_frame_hdr` @ `0x0431c8`)**: `1,765`
- **Exported `.dynsym` Symbols**: `126` (`0` stubs)
- **Reconstructed C++17/H Volume**: `2,275,055 bytes` across 9 files

## Architectural & Mathematical Proof Highlights
1. **`.init_array[6]` (`0x00b9fc..0x00ba2c`) & `JNI_OnLoad` (`0x0381d8..0x038210`)**:
   - Calls `sysconf(_SC_PAGESIZE = 0x27)` (`mov w0, #0x27; bl #0xaeb0`), computes two's-complement page mask `neg w9, w0` (`0x00ba1c`), and stores `g_page_size` and `g_page_mask`.
   - `JNI_OnLoad` logs `"page size: %d"` (`.rodata 0x043160`) with tag `"jato"` (`.rodata 0x0397cb`) and returns `0x00010006` (`JNI_VERSION_1_6`).
2. **`MinFreeHeapOpt` (`0x011aa0` -> `0x0118dc`) & `HeapLargeObjectExclusion` (`0x011ec4`)**:
   - Validates `0.0 < percent < 1.0` (`fcmp d0, #0.0; fmov d0, #1.0; fccmp d8, d0, #0, pl`) and `api_level >= 31` (`cmp w0, #0x1f`), then scans `/apex/com.android.art/lib64/libart.so` (`0x039718`) for the default IEEE-754 double `0.01` (`0x3F847AE147AE147B` at `.rodata 0x039710`).
   - `nativeSetLargeObjectThreshold` (`0x011ec4`) converts page count to bytes via `lsl x8, x19, #0xc` (`threshold_pages << 12`).
3. **`DebugOptimizer::openInstrumentationCrashFix` (`0x016b50`) & `DecodeJObjectOpt` (`0x01c000`)**:
   - Tests Android API level bitmask `(1ULL << api_level) & 0x00000002E0000000ULL` (`0x016b84..0x016b8c`: Android 10/11/12/13 = API 29, 30, 31, 33) and `arch == 0x40` (`0x016ba0`).
   - `DecodeJObjectOpt` (`0x01c050..0x01c06c`) scans up to `0x54` bytes (21 AArch64 instructions) for `(insn & 0xB84003E0) == 0xB8400000` to locate `Thread::top_handle_scope_`.
4. **`PriorityManagerV2` (`0x028234`), `JitCodeCacheMProtectOpt` (`0x030860`), & `ThreadSuspendTimeout` (`0x03871c`)**:
   - `nativeSetPriority` (`0x028244..0x028268`) returns `-1` for `tid < 1` and `-2` when `(uint32_t)(prio + 20) > 39` (`add w8, w3, #0x14; cmp w8, #0x27`).
   - `nStartPharse1` (`0x03086c..0x030874`) masks 40-bit addresses (`and x8, x2, #0xffffffffff`) and `nStartPharse2` (`0x03091c`) calls `mprotect` with `PROT_READ | PROT_WRITE | PROT_EXEC = 7`.
   - `setSuspendTimeoutInSeconds` (`0x038744..0x03874c`) multiplies seconds by `0x3B9ACA00 = 1,000,000,000` (`10^9` ns/s).

## Verified AArch64 Opcode Evidence
- `0x00b9fc: a9bf7bfd stp x29, x30, [sp, #-0x10]! (.init_array[6] page size init)`
- `0x00ba04: 528004e0 mov w0, #0x27 (_SC_PAGESIZE = 39)`
- `0x00ba1c: 4b0003e9 neg w9, w0 (page_mask = -page_size)`
- `0x00c658: f81c0ff7 str x23, [sp, #-0x40]! (JitCompiler::nativeCompile)`
- `0x00c6f0: f81d0ff5 str x21, [sp, #-0x30]! (JitCompiler::nativeHookProfileSaverBug)`
- `0x010e0c: 51008408 sub w8, w0, #0x21 (AnnotationResolvingOpt API 33..34 check)`
- `0x011904: 1e602008 fcmp d0, #0.0 (MinFreeHeapOpt percent > 0.0 check)`
- `0x01195c: fd438940 ldr d0, [x10, #0x710] (.rodata 0x039710 = 0.01 double)`
- `0x011f00: d374ce68 lsl x8, x19, #0xc (HeapLargeObjectExclusion threshold << 12)`
- `0x016b84: d2bc0009 mov x9, #0xe0000000; 0x016b88: f2c00049 movk x9, #2, lsl #32 (DebugOptimizer API mask)`
- `0x018d0c: 52800521 mov w1, #0x29 (ThreadNative /proc/stat ')' delimiter)`
- `0x01be74: 37f806a2 tbnz w2, #0x1f, #0x1bf48 (LockMaxSpinsOpt negative check)`
- `0x01c050: 52b70815 mov w21, #-0x47c00000; 0x01c060: 110f82a8 add w8, w21, #0x3e0 (DecodeJObjectOpt LDR mask)`
- `0x0228c8: 710192df cmp w22, #0x64 (RSpaceLiveRatioOpt live_percent <= 100)`
- `0x02824c: 11005068 add w8, w3, #0x14; 0x028254: 71009d1f cmp w8, #0x27 (PriorityManagerV2 nice range [-20, 19])`
- `0x03086c: 92409c48 and x8, x2, #0xffffffffff (JitCodeCacheMProtectOpt 40-bit VA mask)`
- `0x0381d8: a9bf7bfd stp x29, x30, [sp, #-0x10]! (JNI_OnLoad -> 0x00010006)`
- `0x038744: 52994008 mov w8, #0xca00; 0x038748: 72a77348 movk w8, #0x3b9a, lsl #16 (10^9 ns/s)`
