# Clean-Room C++17 Reconstruction: `libsysoptimizer.so` (ByteDance Android System Optimizer, xHook, ART/Jemalloc/HWUI/Mali/PerfLock/InputAnr Engine)
- **Target Number**: 102 / 169 (`TASK-141-RECONSTRUCTION-LIBSYSOPTIMIZER` / `TASK_SO_070_libsysoptimizer`)
- **Binary Size**: `412,248 bytes`
- **SHA-256**: `0f63dc8761da723206e36de507b0af1b06b647815ae2e0f80bca858d4c904a03`
- **FDE Count (`.eh_frame_hdr` @ `0x017f10`)**: `732`
- **Exported `.dynsym` Symbols**: `228` (`153` `Java_com_bytedance_sysoptimizer_*` JNI functions + `JNI_OnLoad` @ `0x02cd24` + `12` `xh_*` xHook functions + `28` `_Unwind_*` / `__register_frame*` + `4` `RELOCATION_GROUPED_BY_*_FLAG` constants)
- **Reconstructed C++17/H Volume**: `1,360,091 bytes` across 9 files (`0` stubs)

## Architectural & Mathematical Proof Highlights
1. **`RELOCATION_GROUPED_BY_*_FLAG` Constants (`.rodata 0x015790..0x0157a8`) & `.init_array[0..13]` (`0x0609b0..0x060a18`)**:
   - Exported Android APS2 packed relocation bitmasks at `.rodata 0x015790..0x0157a8`: `1ULL`, `2ULL`, `4ULL`, `8ULL`.
   - `14` `.init_array` constructors at `0x0609b0..0x060a18` relocated via `R_AARCH64_RELATIVE` in `.rela.dyn` to `0x02c6b0..0x02ca20`.
2. **`xh_elf_check_elfheader` (`0x02582c..0x02589c`) & `xh_util_flush_instruction_cache` (`0x026c64..0x026cac`)**:
   - Validates 64-bit little-endian AArch64 ELF header: `e_ident_magic == 0x464C457F` (`0x025830..0x025834`), `EI_CLASS == 2` (`0x025848`), `EI_DATA == 1` (`0x025854`), `(e_type & 0xFFFE) == 2` (`0x02586c..0x025870`), `e_machine == 0xB7` (`183 = EM_AARCH64` @ `0x025880`), returning `0` on match or `0x3EF` (`1007 = XH_ERRNO_FORMAT` @ `0x02587c`).
   - `xh_util_flush_instruction_cache` computes `begin = addr & -page_size` (`0x026c78..0x026c80`) and `end = ((addr + 7) & -page_size) + page_size` (`0x026c90..0x026ca0`).
3. **`JNI_OnLoad` (`0x02cd24..0x02cde8`), `ArtMProtectOpt_nStartPharse1` (`0x02d790..0x02d864`), and `HeapGCOptimizerV2_set_values` (`0x0535d8..0x0535ec`)**:
   - `JNI_OnLoad` caches `JavaVM*` at `.bss 0x065c18`, calls `RegisterNatives` (`mov w3, #2` @ `0x02cdd4`) with `.data.rel.ro 0x060008`, and returns `0x00010006`.
   - `ArtMProtectOpt_nStartPharse1` stores `(w2, w3)` at `.bss 0x064fd8`, executes `dmb ishst` (`0x02d7d4: d5033abf`), and hooks `mprotect` via ShadowHook.
   - `HeapGCOptimizerV2_set_values` stores `(x2, x3, x4)` at `.bss 0x065770` (`+0x00`, `+0x08`, `+0x18`) via `stp x2, x3, [x8]; str x4, [x8, #0x18]` (`0x0535e4..0x0535e8`).
