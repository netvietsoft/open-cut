# Clean-Room Reconstruction Analysis — `libcybertron_base.so`
## Phân Tích Tái Tạo Phòng Sạch — `libcybertron_base.so`

- **Target Binary / Nhị phân mục tiêu**: `libcybertron_base.so` (`509,816 bytes`)
- **SHA-256**: `0d969c7e981d68f46d81986a0f16881d1ff9605afb9e6e352f1ae88a5695c7e6`
- **Task ID**: `TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE` / `TASK_SO_105_libcybertron_base`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x069c8c` = `1,201` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `1443`
- **Imported Symbols / Biểu tượng nhập**: `131`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,083,119 bytes` across 9 files (`0` stubs)

---

## 1. Binary Architecture & Section Layout / Kiến Trúc Nhị Phân & Bố Cục Phân Đoạn

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (Bytes) | Description (EN / VN) |
|---|---:|---:|---:|---|
| `.dynsym` | `0x005590` | `0x005590` | `37,848` | Dynamic symbol table (`1,574` entries: `1,443` exported, `131` imported) / Bảng ký hiệu động |
| `.text` | `0x03b220` | `0x03b220` | `174,220` | Executable AArch64 instructions (`0x03b220..0x065aac`) / Mã máy thực thi AArch64 |
| `.rodata` | `0x065ab0` | `0x065ab0` | `16,858` | Read-only strings, RTTI names, Pitaya API names, Feature schema JSON / Chuỗi hằng & cấu hình JSON |
| `.eh_frame_hdr` | `0x069c8c` | `0x069c8c` | `9,620` | DWARF unwind binary search table (`1,201` FDEs) / Bảng tra cứu FDE DWARF |
| `.data.rel.ro` | `0x07c1f8` | `0x0781f8` | `9,128` | Vtables (`_ZTVN10datacenter10DataCenterE` @ `0x07c880`) & typeinfo / Bảng phương thức ảo |
| `.bss` | `0x080000` | `0x07c000` | `1,168` | Singletons, `JavaVM*` (`0x080318`), and 43 `pty_*` function pointers (`0x080178..0x0802c8`) / Vùng nhớ tĩnh |

---

## 2. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`DCTimeIsLater` (`0x05d0dc..0x05d0e8`) & `DCTimeIsLaterOrEqual` (`0x05d1c0..0x05d1cc`)**:
   - `0x05d0dc`: `4B000028` (`sub w8, w1, w0`), `7100011F` (`cmp w8, #0`), `1A9FD7E0` (`cset w0, gt`), `D65F03C0` (`ret`).
   - `0x05d1c0`: `4B000028` (`sub w8, w1, w0`), `2A2803E8` (`mvn w8, w8`), `531F7D00` (`lsr w0, w8, #0x1f`), `D65F03C0` (`ret`).
2. **`DCNowTimeMillis` (`0x05d130..0x05d160`) & `DCNowTimeMicros` (`0x05d188..0x05d1bc`)**:
   - Uses unsigned 64-bit high-half multiplication (`umulh`) by `0x431BDE82D7B634DB` followed by `lsr #18` to divide nanoseconds (`ticks * 1000`) by $10^6$ (converting nanoseconds to milliseconds):
     $$\left\lceil \frac{2^{82}}{10^6} \right\rceil = 4835703278458516699 = \text{0x431BDE82D7B634DB}$$
   - `DCNowTimeMicros` (`0x05d188`) shifts `x8` right by `3` (`0x05d1a8: D343FD08`) and multiplies by `0x20C49BA5E353F7CF` followed by `lsr #4` (`0x05d1b4: D344FD00`) to divide by $10^3$.
3. **Pitaya Dynamic API Loader (`TryLoadAllApi` @ `0x05bb84..0x05bf8c`, `PitayaIsReady` @ `0x05bf90..0x05bf94`)**:
   - Opens `"libAndroidPitayaCore.so"` (`.rodata 0x067ca5`) via `npth_dlopen` (`0x39a60`) and resolves 31 `PTY*` symbols (`"PTYStartCall"` @ `0x067cbd` through `"PTYGetStringWithDefaultValue"` @ `0x067eac`) via `npth_dlsym` (`0x3ac50`).
   - `PitayaIsReady` (`0x05bf90`): `52800020` (`mov w0, #1`), `D65F03C0` (`ret`).
4. **JNI Lifecycle & `DataCenter` Virtual Dispatch (`0x05da68..0x061ae4`)**:
   - `JNI_OnLoad` (`0x05da68..0x05da80`) calls `datacenter::loadRelativeClasses(_JavaVM*)` (`0x05dafc`), which stores `JavaVM*` at `.bss 0x080318` and returns `0x00010006` (`JNI_VERSION_1_6`).
   - `Java_com_ttkmedia_datacenter_api_DataCenter__1setIntValue` (`0x060004`) dispatches `vtable + 0x10`; `_setLongValue` (`0x060040`) dispatches `vtable + 0x18`; `_setFloatValue` (`0x060024`) dispatches `vtable + 0x20`; `_getIntValue` (`0x0600ec`) dispatches `vtable + 0x30`; `_getLongValue` (`0x06012c`) dispatches `vtable + 0x38`; `_getFloatValue` (`0x060110`) dispatches `vtable + 0x48`.
