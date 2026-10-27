# Clean-Room C++17 Reconstruction — `libwcdb.so` (`TASK-205-RECONSTRUCTION-LIBWCDB`)

## 1. Binary Identity & ELF64 Geometry (Định danh Nhị phân & Bố cục ELF64)
- **Target Binary**: `libwcdb.so` (`1,763,776 bytes`)
- **SHA-256**: `7fda5f83efad3f0f0a07ad0e13ad8a203a33e69d4cb2515dee0bb56c7dccf8e8`
- **Architecture**: `AArch64 (ARM64-v8a)`
- **Role**: WeChat Database (WCDB) + SQLite3 + SQLCipher + RepairKit (`sqliterk_*`) + `com/tencent/wcdb/CursorWindow` JNI Engine (`341` exported symbols, `2,938` FDEs)
- **Reconstructed C++17 Volume**: `6,802,524 bytes` across 3 files (`wcdb.hpp`, `wcdb_core.cpp`, `wcdb_elf_sections_and_image.cpp`), `0` stubs.

| Section | File Offset | Size (Bytes) | Details |
|---|---:|---:|---|
| `.plt` | `0x0248C0` | `2,304` | Procedure Linkage Table |
| `.text` | `0x0251C0` | `1,185,440` | `296,360` AArch64 32-bit instruction words |
| `.rodata` | `0x146860` | `164,136` | `WCDB.CursorWindow`, `com/tencent/wcdb/CursorWindow`, SQLite3/SQLCipher tables |
| `.eh_frame_hdr` | `0x16E988` | `23,516` | Header `01 1b 03 3b`, `2,938` FDE entries |
| `.eh_frame` | `0x174568` | `156,472` | DWARF CFI unwind records |
| `.data.rel.ro` | `0x19B900` | `60,976` | Relocated read-only tables (`vaddr=0x1AB900`) |
| `.data` | `0x1AC000` | `8,688` | Initialized mutable state (`vaddr=0x1BC000`) |
| `.bss` | `0x1AE1F0` | `73,928` | Zero-initialized runtime state (`vaddr=0x1BE1F0`) |
