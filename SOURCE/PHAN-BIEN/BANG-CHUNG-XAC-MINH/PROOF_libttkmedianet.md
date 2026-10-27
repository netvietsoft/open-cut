# Clean-Room Reconstruction Analysis — `libttkmedianet.so`
## Phân Tích Tái Tạo Phòng Sạch — `libttkmedianet.so`

- **Target Binary / Nhị phân mục tiêu**: `libttkmedianet.so` (`632,064 bytes`)
- **SHA-256**: `f6826092b0e554652515dac78ffbeb99ee14434369d57c0e81697564b5e03860`
- **Task ID**: `TASK-145-RECONSTRUCTION-LIBTTKMEDIANET` / `TASK_SO_022_libttkmedianet`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x08419c` = `1,643` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `115`
- **Imported Symbols / Biểu tượng nhập**: `302`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,348,105 bytes` across 9 files (`0` stubs)

---

## 1. Binary Architecture & Section Layout / Kiến Trúc Nhị Phân & Bố Cục Phân Đoạn

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (Bytes) | Description (EN / VN) |
|---|---:|---:|---:|---|
| `.dynsym` | `0x000f50` | `0x000f50` | `10,080` | Dynamic symbol table (`420` entries: `115` exported, `302` imported) |
| `.text` | `0x00fd20` | `0x00fd20` | `445,024` | Executable AArch64 instructions (`0x00fd20..0x07c780`) |
| `.rodata` | `0x07c780` | `0x07c780` | `31,260` | QUIC draft-29/v1 parameters (`0x07c8b6..0x07cae2`), QPACK static table (`0x07cff7`) |
| `.eh_frame_hdr` | `0x08419c` | `0x08419c` | `13,156` | DWARF unwind binary search table (`1,643` FDEs) |
| `.data` | `0x09c000` | `0x098000` | `7,452` | Global configuration tables |
| `.bss` | `0x09dd20` | `0x099d1c` | `1,472` | Atomic task ID (`0x09dd20`), singleton guard (`0x09dd30`) & `NetworkMgr` (`0x09dd50`) |

---

## 2. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`NetworkTask::InternalKeyConvertToExternalKey` (`0x0332b0..0x0332dc`)**:
   - `0x0332b0`: `52888BA8` (`mov w8, #0x445d`)
   - `0x0332b4`: `72BFFE48` (`movk w8, #0xfff2, lsl #16` -> `-900003`)
   - `0x0332b8`: `0B080028` (`add w8, w1, w8`)
   - `0x0332bc`: `71000D1F` (`cmp w8, #3`)
   - `0x0332c4`: `5299DD48` (`mov w8, #0xceea`)
   - `0x0332c8`: `72BFFE68` (`movk w8, #0xfff3, lsl #16` -> `-798998`)
   - `0x0332d4`: `52915220` (`mov w0, #0x8a91`)
   - `0x0332d8`: `72A00020` (`movk w0, #1, lsl #16` -> `101009`)
   - Maps internal event keys $k \in [900003, 900006]$ to external keys $k - 798998 \in [101005, 101008]$, and all other keys to `101009` (`0x00018A91`).
2. **`NetworkTask::NetworkTask` (`0x02f54c..0x02f5cc`) & `TCSetInt64Value` (`0x033464..0x03349c`)**:
   - Atomically increments global 64-bit task counter at `.bss 0x09dd20` (`ldaxr/stlxr` @ `0x02f578..0x02f584`) and stores `task_id` at `+0x40`.
   - `TCSetInt64Value` (`0x033464`) checks `key == 0x00018A88` (`101000`) and sets `+0x49 = 1`.
3. **`NetworkMgr::NetworkMgr` (`0x03b0c0..0x03b16c`) & `GetNetworkMgr` (`0x03b058..0x03b0bc`)**:
   - `GetNetworkMgr` (`0x03b058`) checks acquire guard byte at `.bss 0x09dd30` (`ldarb w8, [x8]; tbz w8, #0, 0x3b088`) and returns singleton at `.bss 0x09dd50`.
   - `NetworkMgr` constructor (`0x03b0e8`) initializes `+0x50 = 0x3f800000` (`1.0f` max load factor).
