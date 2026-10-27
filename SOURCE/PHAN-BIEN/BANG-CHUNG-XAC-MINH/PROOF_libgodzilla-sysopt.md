# Adversarial Verification Proof: `libgodzilla-sysopt.so`
# Bằng Chứng Xác Minh Đối Kháng: `libgodzilla-sysopt.so`

- **Proof ID**: `PROOF-LIBGODZILLA-SYSOPT-V1`
- **Target Library**: `libgodzilla-sysopt.so` (`164,440 bytes`, SHA-256 `28605f81e2c8d9d0fae96d52a70efc5192c90d93377ddadff09726874911d704`)
- **Task ID**: `TASK_SO_127_libgodzilla_sysopt` / `TASK-116-RECONSTRUCTION-LIBGODZILLA_SYSOPT`
- **Submitted By**: Agent 0 (Orchestrator) & Agent 3 (Android/Native)

## 1. Reconstructed Files (`97,912 bytes` C++17/H + Analysis Doc)
1. `SOURCE/GIAI-MA/libgodzilla-sysopt/godzilla_sysopt_types.h`
2. `SOURCE/GIAI-MA/libgodzilla-sysopt/elf_build_id_xhook.h`
3. `SOURCE/GIAI-MA/libgodzilla-sysopt/elf_build_id_xhook.cpp`
4. `SOURCE/GIAI-MA/libgodzilla-sysopt/apk_cert_sha256_engine.h`
5. `SOURCE/GIAI-MA/libgodzilla-sysopt/apk_cert_sha256_engine.cpp`
6. `SOURCE/GIAI-MA/libgodzilla-sysopt/maps_hook_scanner.h`
7. `SOURCE/GIAI-MA/libgodzilla-sysopt/maps_hook_scanner.cpp`
8. `SOURCE/GIAI-MA/libgodzilla-sysopt/godzilla_sysopt_interface.h`
9. `SOURCE/GIAI-MA/libgodzilla-sysopt/godzilla_sysopt_pseudocode.cpp`
10. `SOURCE/GIAI-MA/libgodzilla-sysopt/README_ANALYSIS.md`

## 2. Direct AArch64 Opcode Evidence (`[OBSERVED]`)
- **`getElfBuildId` (`0x007d30..0x008060`)**:
  - `0x007e60: f4 3b 41 79 (ldrh w20, [sp, #0x9c]); 0x007e64: 9f 06 01 71 (cmp w20, #0x41)`
  - `0x007ea4: 96 e6 7a d3 (lsl x22, x20, #6)`
  - `0x007fe4: 20 00 80 52 (mov w0, #1); 0x007fe8: c0 7e 7f b3 (bfi x0, x22, #1, #0x20)`
- **`hook_pthread_attr_setstacksize` & `PthreadCreateHook_start` (`0x008248..0x0082e8`)**:
  - `0x008248: c8 00 00 b0 (adrp x8, #0x2f000); 0x00824c: 01 c9 47 b9 (ldr w1, [x8, #0x7c8])` (`0x00083000 = 536,576 B`)
  - `0x0082f4: 00 05 80 52 (mov w0, #0x28)` (`sysconf(_SC_PAGESIZE = 0x28)` at `.init_array[0]` `0x0082ec`)
- **`ThreadHook_start` & `sigbus_handler` (`0x00aa3c..0x00abd8`)**:
  - `0x00aa88: 08 03 b3 52 (mov w8, #0x18000000); 0x00aa94: 88 00 80 72 (movk w8, #4); 0x00aaa0: e0 00 80 52 (mov w0, #7)` (`SIGBUS = 7`, `sa_flags = 0x18000004`)
  - `0x00ab00: 28 08 40 b9 (ldr w8, [x1, #8]); 0x00ab04: 1f 09 00 71 (cmp w8, #2)` (`BUS_ADRERR = 2`)
  - `0x00aba4: 1f 0c 00 f1 (cmp x0, #3)` (3-retry TLS limit)
- **`rawSyscall4` & SHA-256 (`0x017878..0x0195ec`)**:
  - `0x017878: e8 03 00 aa (mov x8, x0); 0x01789c: 01 00 00 d4 (svc #0)`
- **`scanMapsForHookFrameworks` (`0x019fb4..0x022684`)**:
  - `0x01a448: 29 61 59 92 (and x9, x9, #0xffffff8000000000); 0x01a450: 09 fd 67 b3 (bfxil x9, x8, #0x27, #0x19)`
  - `0x01b238: 62 00 02 0a (and w2, w3, w2); 0x01b23c: 20 00 00 0b (add w0, w1, w0); 0x01b244: 00 04 02 4b (sub w0, w0, w2, lsl #1)`
