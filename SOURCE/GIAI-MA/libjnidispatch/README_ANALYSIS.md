# Clean-Room Binary Analysis & Reconstruction Report — `libjnidispatch.so` (JNA 7.0.4 + libffi AArch64)
# Báo Cáo Phân Tích Nhị Phân & Tái Tạo Sạch — `libjnidispatch.so` (JNA 7.0.4 + libffi AArch64)

## 1. Binary Identity & ELF Layout / Định Danh Nhị Phân & Cấu Trúc ELF (`[OBSERVED]`)

| Property / Thuộc tính | Observed Value / Giá trị quan sát được |
|---|---|
| **Binary Path** | `SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so` |
| **File Size** | `165,992 bytes` (`0x28868`) |
| **SHA-256** | `ddfc6c965bbe366615c000ec1f06552ddf0bb2b4f9d921d0bff8c75b3cb2ca4c` |
| **Architecture** | `EM_AARCH64` (64-bit Little-Endian ARMv8-A) |
| **JNA Native Version** | `"7.0.4"` (`.rodata 0x021738`, loaded at `0x009820..0x009830`) |
| **JNA API Checksum** | `"5fb98531302accd485c534c452dd952a"` (`.rodata 0x021740`, loaded at `0x009834..0x009844`) |
| **Exported `.dynsym` Symbols** | `153` (`66 Java_com_sun_jna_Native_*` + `JNI_OnLoad`/`JNI_OnUnload` + `16 ffi_type_*` + `69` JNA/libffi C functions) |
| **`.text`** | VMA `0x004000..0x020080` (`114,816 bytes`) |
| **`.rodata`** | VMA `0x020080..0x022a90` (`10,768 bytes`) |
| **`.data.rel.ro`** | VMA `0x02bb98..0x02bc70` (file offset `0x027b98`, `216 bytes`) |
| **`.data`** | VMA `0x02c000..0x02c244` (file offset `0x028000`, `580 bytes`) |
| **`.bss`** | VMA `0x02c248..0x02ca80` (`2,104 bytes`) |

---

## 2. Core Subsystems & AArch64 Opcode Anchors / Các Phân Hệ Cốt Lõi & Điểm Neo Opcode AArch64 (`[OBSERVED]`)

### 2.1. JNA Version, Checksum & `Native.sizeof(int type)` (`0x008a0c..0x008ad0`, `0x009820..0x009844`)
- `Java_com_sun_jna_Native_getNativeVersion` (`0x009820..0x009830`):
  - Loads `.rodata 0x021738` (`"7.0.4"`) and calls `NewStringUTF` (`ldr x8, [x0]; ldr x2, [x8, #0x538]; br x2`).
- `Java_com_sun_jna_Native_getAPIChecksum` (`0x009834..0x009844`):
  - Loads `.rodata 0x021740` (`"5fb98531302accd485c534c452dd952a"`) and calls `NewStringUTF`.
- `Java_com_sun_jna_Native_sizeof` (`0x008a0c..0x008ad0`):
  - Checks `cmp w2, #5; b.ls #0x8a6c` (`0x008a0c..0x008a10`).
  - Indexes the 6-byte signed jump table at `.rodata 0x0201c4`:
    `[0, 0, 10, 0, 5, 15]` (`0x00, 0x00, 0x0a, 0x00, 0x05, 0x0f`) via `ldrsb x9, [x9, w2, uxtw]; adr x10, #0x8a84; add x9, x10, x9, sxtb #2; br x9` (`0x008a74..0x008a80`):
    - `type = 0` (`VOID_PTR`), `1` (`LONG`), `3` (`SIZE_T`) $\rightarrow$ `mov w0, #8; ret` (`8 bytes`)
    - `type = 2` (`WCHAR_T`) $\rightarrow$ `mov w0, #4; ret` (`4 bytes`)
    - `type = 4` (`BOOL`) $\rightarrow$ `mov w0, #1; ret` (`1 byte`)
    - `type = 5` (`LONG_DOUBLE`) $\rightarrow$ `mov w0, #0x10; ret` (`16 bytes`)
    - `type > 5` $\rightarrow$ throws `java/lang/IllegalArgumentException("Invalid sizeof type %d")` and returns `-1`.

### 2.2. Direct Native Memory Accessors (`0x008814..0x00897c`)
- Indexed load/store instructions operating on `[x3, x4]` (`addr + offset`):
  - `getByte` (`0x008814`): `ldrb w0, [x3, x4]; ret` (`0x38646860`)
  - `getShort` (`0x00881c`): `ldrh w0, [x3, x4]; ret` (`0x78646860`)
  - `getInt` (`0x00882c`): `ldr w0, [x3, x4]; ret` (`0xb8646860`)
  - `getLong` (`0x008834`): `ldr x0, [x3, x4]; ret` (`0xf8646860`)
  - `getFloat` (`0x008954`): `ldr s0, [x3, x4]; ret` (`0xbc646860`)
  - `getDouble` (`0x008964`): `ldr d0, [x3, x4]; ret` (`0xfc646860`)
  - `setMemory` (`0x008974`): `add x0, x3, x4; uxtb w1, w6; mov x2, x5; b memset`

### 2.3. 16 Global 24-Byte `ffi_type_*` Descriptors (`.rodata 0x022858..0x022990` & `.data.rel.ro 0x02bb98..0x02bbe0`)
Each `ffi_type` is 24 bytes (`size_t size` at `+0x00`, `uint16_t alignment` at `+0x08`, `uint16_t type` at `+0x0a`, `ffi_type** elements` at `+0x10`):
- `.rodata 0x022858`: `ffi_type_longdouble` (`size=16, align=16, type=4`)
- `.rodata 0x022870`: `ffi_type_double` (`size=8, align=8, type=3`)
- `.rodata 0x022888`: `ffi_type_float` (`size=4, align=4, type=2`)
- `.rodata 0x0228a0`: `ffi_type_sint64` (`size=8, align=8, type=12`)
- `.rodata 0x0228b8`: `ffi_type_uint64` (`size=8, align=8, type=11`)
- `.rodata 0x0228d0`: `ffi_type_sint32` (`size=4, align=4, type=10`)
- `.rodata 0x0228e8`: `ffi_type_uint32` (`size=4, align=4, type=9`)
- `.rodata 0x022900`: `ffi_type_sint16` (`size=2, align=2, type=8`)
- `.rodata 0x022918`: `ffi_type_uint16` (`size=2, align=2, type=7`)
- `.rodata 0x022930`: `ffi_type_sint8` (`size=1, align=1, type=6`)
- `.rodata 0x022948`: `ffi_type_uint8` (`size=1, align=1, type=5`)
- `.rodata 0x022960`: `ffi_type_pointer` (`size=8, align=8, type=14`)
- `.rodata 0x022978`: `ffi_type_void` (`size=1, align=1, type=0`)
- `.data.rel.ro 0x02bb98`: `ffi_type_complex_longdouble` (`size=32, align=16, type=15`)
- `.data.rel.ro 0x02bbb0`: `ffi_type_complex_double` (`size=16, align=8, type=15`)
- `.data.rel.ro 0x02bbc8`: `ffi_type_complex_float` (`size=8, align=4, type=15`)

### 2.4. `ffi_prep_closure_loc` (`0x010e0c..0x010f0c`) & `__aarch64_sync_cache_range` (`0x020004..0x02007c`)
- `ffi_prep_closure_loc` checks `cif->abi` in `[1, 2]` (`sub w4, w4, #1; cmp w4, #1; b.ls #0x10e38` at `0x010e24..0x010e2c`), copies the 16-byte AArch64 trampoline from `.rodata 0x022a80`:
  - `0x58000090` (`ldr x16, #0x10`)
  - `0x10fffff1` (`adr x17, #-4`)
  - `0xd61f0200` (`br x16`)
  - `0x00000000`
- `__aarch64_sync_cache_range` (`0x020004..0x02007c`) reads `ctr_el0` (`mrs x3, ctr_el0`), computes `icache_lsize = 4 << (ctr_el0 & 0xF)` and `dcache_lsize = 4 << ((ctr_el0 >> 16) & 0xF)`, sweeps D-cache lines with `dc cvau` + `dsb ish`, and sweeps I-cache lines with `ic ivau` + `dsb ish` + `isb`.
