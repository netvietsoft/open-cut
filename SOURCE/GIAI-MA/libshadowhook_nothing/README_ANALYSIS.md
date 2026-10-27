# Clean-Room Forensic Analysis & C++17 Reconstruction: `libshadowhook_nothing.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libshadowhook_nothing.so`

- **Task ID**: `TASK-162-RECONSTRUCTION-LIBSHADOWHOOK-NOTHING` (`TASK_SO_066_libshadowhook_nothing`) — Target 123 / 169
- **Binary Size / Kích thước nhị phân**: `1,112 bytes` (`0x0458` bytes)
- **SHA-256**: `f2cc6a6f94d7361be915daafff1d25b7b3af34972e7308ac540982cfd608bd32`
- **Reconstructed C++17 Volume / Dung lượng C++17 tái dựng**: `96,778 bytes` across 5 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **Vai trò kiến trúc trong ByteDance ShadowHook (`libshadowhook.so`)**:
   - `libshadowhook_nothing.so` là thư viện ELF64 rỗng tối giản (`1,112 bytes`, `.text` 0 byte) được `libshadowhook.so` nạp qua `dlopen("libshadowhook_nothing.so", RTLD_NOW)` để dò tìm động vị trí các trường ẩn (`phdr`, `dynamic`, `strtab`, `symtab`, `load_bias`) bên trong cấu trúc `soinfo` của Bionic `linker64` trên Android 8.0+ (API 26..35).
2. **Bố cục phân đoạn ELF64 chuẩn xác tới từng byte (`0x0000..0x0458`)**:
   - `0x0000..0x0040` (`64 B`): `Elf64_Ehdr` (`e_type = ET_DYN (3)`, `e_machine = EM_AARCH64 (0xB7 = 183)`, `e_phoff = 0x40`, `e_shoff = 0x298`, `e_phnum = 5`, `e_shnum = 7`, `e_shstrndx = 6`).
   - `0x0040..0x0158` (`280 B`): `5` mục `Elf64_Phdr` (`PT_PHDR`, `PT_LOAD` R, `PT_LOAD` RW, `PT_DYNAMIC` tại `vaddr = 0x41d8 / offset = 0x01d8`, `PT_GNU_STACK`).
   - `0x0190..0x01a8` (`24 B`): `.dynsym` (1 mục `STN_UNDEF` toàn 0).
   - `0x01a8..0x01b8` (`16 B`): `.hash` (`nbucket = 1`, `nchain = 1`, `bucket[0] = 0`, `chain[0] = 0`).
   - `0x01b8..0x01d2` (`26 B`): `.dynstr` (`"\x00libshadowhook_nothing.so\x00"`).
   - `0x01d8..0x0268` (`144 B`, `vaddr = 0x41d8`): `9` mục `Elf64_Dyn` (`DT_SONAME=1`, `DT_FLAGS=0x8`, `DT_FLAGS_1=0x1`, `DT_SYMTAB=0x190`, `DT_SYMENT=24`, `DT_STRTAB=0x1b8`, `DT_STRSZ=26`, `DT_HASH=0x1a8`, `DT_NULL=0`).
