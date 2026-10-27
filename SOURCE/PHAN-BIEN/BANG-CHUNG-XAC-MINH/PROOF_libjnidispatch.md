# Adversarial Verification Proof — `libjnidispatch.so` (JNA 7.0.4 + libffi AArch64)
# Bằng Chứng Xác Minh Đối Kháng — `libjnidispatch.so` (JNA 7.0.4 + libffi AArch64)

- **Proof ID**: `PROOF-LIBJNIDISPATCH-V1`
- **Target Library**: `libjnidispatch.so` (`165,992 bytes`, SHA-256: `ddfc6c965bbe366615c000ec1f06552ddf0bb2b4f9d921d0bff8c75b3cb2ca4c`)
- **Task ID**: `TASK_SO_126_libjnidispatch` / `TASK-117-RECONSTRUCTION-LIBJNIDISPATCH`
- **Reconstructed C++/H Volume**: `114,012 bytes` across 9 clean-room C++17/H files + `README_ANALYSIS.md` (`0` stubs)

## 1. Binary Disassembly & Data Table Verification / Kiểm Chứng Giải Mã Nhị Phân & Bảng Dữ Liệu

1. **JNA Version, API Checksum & `Native.sizeof(int type)` (`0x008a0c..0x008ad0`, `0x009820..0x009844`)**:
   - `.rodata 0x021738`: `"7.0.4"`.
   - `.rodata 0x021740`: `"5fb98531302accd485c534c452dd952a"`.
   - `.rodata 0x0201c4`: 6-byte signed jump table `[0, 0, 10, 0, 5, 15]` returning `8` (`0, 1, 3`), `4` (`2`), `1` (`4`), `16` (`5`), and `-1` for out-of-range types.
2. **16 Global 24-Byte `ffi_type_*` Descriptors (`.rodata 0x022858..0x022990` & `.data.rel.ro 0x02bb98..0x02bbe0`)**:
   - Verified exact 24-byte layout (`size`, `alignment`, `type`, `elements`) for all 13 scalar and 3 complex `ffi_type_*` exports.
3. **AArch64 Closure Trampoline & `ctr_el0` Cache Synchronization (`0x010e0c..0x010f0c`, `0x020004..0x02007c`)**:
   - `.rodata 0x022a80`: `0x58000090` (`ldr x16, #0x10`), `0x10fffff1` (`adr x17, #-4`), `0xd61f0200` (`br x16`), `0x00000000`.
   - `ffi_tramp_arch` (`0x0112ac`): writes `*tramp_size = 0x20` (`32`), `*map_size = 0x4000` (`16384`).
   - `__aarch64_sync_cache_range` (`0x020004..0x02007c`): decodes `icache_lsize = 4 << (ctr_el0 & 0xF)` and `dcache_lsize = 4 << ((ctr_el0 >> 16) & 0xF)` and executes `dc cvau` / `ic ivau` barriers.
