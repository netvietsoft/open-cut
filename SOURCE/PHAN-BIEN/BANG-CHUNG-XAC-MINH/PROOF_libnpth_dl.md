# Clean-Room Reconstruction of `libnpth_dl.so` (Target 137 / 169)
# Tái Cấu Trúc Sạch Thư Viện `libnpth_dl.so` (Mục tiêu 137 / 169)

## 1. Binary Metadata / Siêu dữ liệu Nhị phân
| Property / Thuộc tính | Value / Giá trị |
|---|---|
| **Library / Thư viện** | `libnpth_dl.so` (ByteDance Npth Crash SDK Dynamic Linker & `.symtab`/`.gnu_debugdata` Resolver) |
| **File Size / Dung lượng** | `27,352 bytes` |
| **SHA-256** | `6e8562b698541ea8c948e0cf3335b08d195a9bac2795279aeb7540f31480df63` |
| **Architecture / Kiến trúc** | `AArch64` (`ARM64-v8a`, BTI-enabled) |
| **`.rodata`** | `0x0014d0..0x001978` (`1,192 B`) |
| **`.eh_frame_hdr`** | `0x001978..0x001b8c` (`532 B`, `65` FDEs) |
| **`.text`** | `0x002600..0x005c14` (`13,844 B`, `3,461` AArch64 instructions) |
| **`.plt`** | `0x005c20..0x005f10` (`752 B`, `188` AArch64 instructions) |
| **Exported Symbols / Ký hiệu xuất** | `22` (`npth_dlopen`, `npth_dlsym`, `npth_dlsym_symtab`, `npth_dllzma_decompress`, `npth_dlbuildid`, ...) |

## 2. Key Technical Findings / Phát hiện Kỹ thuật Trọng tâm
1. **Dual Hash Table `.dynsym` Resolution (`0x4328..0x44b8`)**:
   - Implements both `.gnu.hash` (`DT_GNU_HASH = 0x6ffffef5`, DJB2 seed `0x1505` + 64-bit Bloom filter + bucket/chain walk) and SysV `.hash` (`DT_HASH = 4`).
   - Validates `.gnu.hash` `maskwords` power-of-two property using NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` (`0x45d0..0x45dc`).
   - Divides `DT_PLTRELSZ` and `DT_RELASZ` by `24` (`sizeof(Elf64_Rela)`) using magic multiplier `0xaaaaaaaaaaaaaaab` (`umulh x15, x15, x13; lsr x15, x15, #4` @ `0x4604..0x4608`).
2. **In-Memory `.gnu_debugdata` XZ Decompression (`0x490c..0x4da0`, `0x5858..0x5b54`)**:
   - When `.symtab` is stripped from an ELF binary, `LoadSymtabOrDebugdata` (`0x490c`) locates `.gnu_debugdata`, dynamically loads `liblzma.so`, initializes `CrcGenerateTable` and `Crc64GenerateTable`, and runs `XzUnpacker_Code` to decompress the embedded mini-debuginfo ELF image in memory.
3. **Android N+ Linker Namespace Bypass (`0x4e48..0x5678`)**:
   - `npth_dlopen_force` and `npth_dlsym_force` open `/system/bin/linker64` via `getauxval(AT_BASE = 7)` (`npth_dlopen((const char*)2)`), resolve `__dl__Z9do_dlopen...` / `__dl__Z8__dlopen...` / `__loader_dlopen`, and pass fake caller addresses inside `/libc.so`, `/libart.so`, `/vendor/lib64/`, or `/apex/com.android.vndk.v` discovered via `dl_iterate_phdr`.
