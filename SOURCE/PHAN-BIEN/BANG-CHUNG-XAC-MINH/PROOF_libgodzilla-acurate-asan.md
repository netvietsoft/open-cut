# Adversarial Verification Proof — `libgodzilla-acurate-asan.so`
# Hồ Sơ Bằng Chứng Xác Minh Đối Kháng — `libgodzilla-acurate-asan.so`

- **Proof ID**: `PROOF-LIBGODZILLA-ACURATE-ASAN-V1`
- **Target Library**: `libgodzilla-acurate-asan.so` (`160,168 bytes`, SHA-256: `0c89ab013365273e0d1b626303f8948a1dbf72bf1d77ce5f2ec36b181b769a0c`)
- **Task ID**: `TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN` (`TASK_SO_128_libgodzilla_acurate_asan`)
- **Challenge ID**: `CHALLENGE-LIBGODZILLA-ACURATE-ASAN`

---

## 1. AArch64 Opcode Evidence / Bằng Chứng Mã Máy AArch64

### 1.1 `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan` (`0x00dcc0..0x00e2e0`)
- **`0x00dcc0`**: `ff 83 05 d1` (`sub sp, sp, #0x160`), `0x00dcc4`: `fd 7b 10 a9` (`stp x29, x30, [sp, #0x100]`)
- **`0x00dd54`**: `9f 4c 00 71` (`cmp w4, #0x13`), `0x00dd58`: `a8 01 00 54` (`b.gt #0xdd8c`) — Rejects `api_level <= 19` (`Android 4.4`).
- **`0x00dfa8..0x00dfe4`**: Clamps `Options.MaxAllocationSize` (`[sp, #0x58]`) based on `api_level`:
  - `api_level > 29`: `20 * page_size`
  - `api_level in {28, 29}`: `10 * page_size`
  - `api_level in [20, 27]`: `1 * page_size`
- **`0x00dff4`**: `01 1d 80 52` (`mov w1, #0xe8`), `0x00e000`: `e0 5c 00 94` (`bl mmap`) — Maps `232-byte` (`0xe8`) `gwp_asan::GuardedPoolAllocator`.

### 1.2 `_ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error` (`0x011a0c..0x011a1c`)
- **`0x011a0c`**: `08 14 40 f9` (`ldr x8, [x0, #0x28]`) — Loads `State.CrashTriggerSortingPage`.
- **`0x011a10`**: `02 48 00 b9` (`str w2, [x0, #0x48]`) — Stores `Error` at `State.FailureType`.
- **`0x011a14`**: `01 28 00 f9` (`str x1, [x0, #0x50]`) — Stores `Address` at `State.FailureAddress`.
- **`0x011a18`**: `1f 01 00 39` (`strb wzr, [x8]`) — Writes `0` to `PROT_NONE` trap page to trigger `SIGSEGV`.
- **`0x011a1c`**: `c0 03 5f d6` (`ret`).

### 1.3 `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler` (`0x01ed68..0x01f074`)
- **`0x01ee50`**: `65 01 00 94` (`bl #0x1f3e4`) — Calls `isScudoMemoryAllocator()`, scanning `/proc/self/maps` for `"scudo"`.
- **`0x01eeb0`**: `01 c0 a5 12` (`mov w1, #-0x2be00000`), `0x01eeb8`: `01 78 80 72` (`movk w1, #0x3c0`) — Constructs `0xd65f03c0` (`ret`) in `w1` and calls `patchInstructionWithRet` (`0x01f4ac`).

### 1.4 `GodzillaRefDebug` (`0x01ff1c..0x020b4c`)
- **`0x01ff1c`**: `9d 00 00 14` (`b #0x20190`) — `nativeRefrecordInit` tail-branches to `RefDebugState` allocation (`24` B at `0x05ea58`) and ART JNI GlobalRef hooking (`0x01f810`).
- **`0x02097c`**: `6a 0a 02 53` (`lsr w10, w19, #2`), `0x020980`: `4b 09 c9 1a` (`udiv w11, w10, w9`), `0x020984`: `76 a9 09 1b` (`msub w22, w11, w9, w10`) — Computes `bucket_idx = (ref_val >> 2) % g_ref_bundle_size`.
