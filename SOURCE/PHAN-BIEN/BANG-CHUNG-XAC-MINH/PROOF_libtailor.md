# Adversarial Verification Proof: `libtailor.so` (`TASK_SO_060_libtailor` / `TASK-107-RECONSTRUCTION-LIBTAILOR`)
# Bằng Chứng Xác Minh Đối Kháng: `libtailor.so` (`TASK_SO_060_libtailor` / `TASK-107-RECONSTRUCTION-LIBTAILOR`)

---

## 1. Binary & Reconstruction Summary (Tổng Quan Nhị Phân & Tái Tạo)

- **Binary Path**: `extracted/lib/arm64-v8a/libtailor.so` (`84,136 bytes`, `27` ELF64 sections, `175` `.dynsym` entries, `92` exported symbols `[083..174]`)
- **Reconstructed Codebase**: `SOURCE/GIAI-MA/libtailor/` (`9` C++17 & Header files, `126,367 bytes` = `126.37 KB`, `0 stubs`)
- **Verification Verdict**: `VERIFIED_AND_ACCEPTED`

---

## 2. Six-Criteria Adversarial Audit Proof (Bằng Chứng 6 Tiêu Chuẩn Đối Kháng)

1. **Criterion 1 — Genuine Code Volume $> 40\text{ KB}$ & Zero Stubs**:
   - `126,367 bytes` (`126.37 KB`) across 9 `.cpp`/`.h` files in `SOURCE/GIAI-MA/libtailor/`, `0 stubs`.
2. **Criterion 2 — AArch64 Opcode Verification (`16+` Verified Instruction Sequences)**:
   - `0x00e668`: `c2 00 80 52` (`mov w2, #6`), `0x00e674`: `22 00 a0 72` (`movk w2, #1, lsl #16` -> `JNI_VERSION_1_6 = 0x00010006`)
   - `0x00e730`: `a3 00 80 52` (`mov w3, #5` -> registers 5 `JNINativeMethod` entries on `"com/bytedance/tailor/Tailor"`)
   - `0x00d72c`: `08 00 41 91` (`add x8, x0, #0x40, lsl #12`) + `0x00d734`: `08 61 00 91` (`add x8, x8, #0x18` -> `&Writer::strm_` at offset `0x40018`)
   - `0x00aabc`: `88 00 a0 52` (`mov w8, #0x40000` -> `262,144` bytes initial `Stream` capacity)
   - `0x00ab94`: `20 21 00 aa` (`orr x0, x9, x0, lsl #8` -> big-endian integer assembly in `Stream::peek`)
   - `0x00b414`: `81 05 80 52` (`mov w1, #0x2c` -> `HPROF_TAG_HEAP_DUMP_END`)
   - `0x00aa30`: `28 7d 80 52` (`mov w8, #0x3e9` -> `1001` error return in `xh_util_set_addr_protect`)
   - `0x00e918`: `20 15 00 0b` (`add w0, w9, w0, lsl #5`) + `0x00e928`: `00 24 40 92` (`and x0, x0, #0x3ff` -> `hash` mod `1024`)
   - `0x00ea48`: `29 00 3b d5` (`mrs x9, ctr_el0`), `0x00ea70`: `2a 7b 0b d5` (`dc cvau, x10`), `0x00eaa8`: `29 75 0b d5` (`ic ivau, x9`)
3. **Criterion 3 — Mathematical Accuracy**:
   - Verified big-endian byte shift accumulation $V_k = (V_{k-1} \ll 8) \mid B[\text{offset}+k]$, `Stream` capacity growth $\text{capacity}_{n+1} = \text{capacity}_n + \max(65536, \text{count})$, Bernstein djb2 modulo-1024 hash $H(s) = (\sum s_i \cdot 33^{n-1-i}) \bmod 1024$, and `CTR_EL0` cache line step sizes.
4. **Criterion 4 — Struct ABI Layouts**:
   - Verified `Writer` (`0x40088 = 262,280 B`), `FileWriter` (`0x40018 = 262,168 B`), `Stream` (`0x20 = 32 B`), `Tailor` (`0x18 = 24 B`), `ClassDump` (`0x18 = 24 B`), `InstanceDump` (`0x20 = 32 B`), `Field` (`0x08 = 8 B`), and `SetNode` (`0x10 = 16 B`).
5. **Criterion 5 — Complete 92 Exported Symbols**:
   - All 92 exported symbols (`[083..174]`) in `.dynsym` mapped and verified 1:1.
6. **Criterion 6 — Independent Verification Test Suite**:
   - `verify_libtailor` in `SOURCE/scripts/verify_reconstruction_suite.py` (6 independent binary/opcode/RODATA/JNI table/reconstruction checks).
