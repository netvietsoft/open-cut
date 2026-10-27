# Clean-Room Reconstruction of `libttmverifylite.so` (Target 141 / 169)

## 1. Binary Overview / Tổng quan nhị phân
- **Library**: `libttmverifylite.so` (`34,672 bytes`)
- **SHA-256**: `672829f9be725b6867d86d6e0e2620361626c87539784cb7b300b71bedf3e5b5`
- **Architecture**: `AArch64` (`EM_AARCH64`, Little-Endian)
- **Source Unit**: `custom_verify/source/custom_verify_android.c` (Built `Jun 26 2025 12:29:14`)
- **Unwind Table**: `.eh_frame_hdr` at `0x4d1c` (`13` FDEs), `.eh_frame` at `0x4d90`
- **Code Section**: `.text` at `0x11f0..0x3cc8` (`10,968 bytes`, `2,742` AArch64 instructions)

## 2. Reconstructed C++17 Files / Các tệp C++17 phòng sạch
1. `ttmverifylite.hpp`: Constants, `.data`/`.bss` global structures (`gCustomVerify`, `g_jvm`, `g_verify_cls`, `hasInit`, `g_verify_method`, `lock`), and all 13 FDE function declarations.
2. `ttmverifylite_core.cpp`: Complete C++17 implementation of `av_cert_hostcheck`, `validate_hostname`, `CustomVerifyLog_319c`, `convertToVerifyRet`, `registerNativeMethods`, `init_clsz`, `ToJavaByteArray`, `ToJavaArrayOfByteArray`, `vcn_internal_custom_verify_android`, `JNI_OnLoad`, `JNI_OnUnload`, `pthread_once_thunk_3cb4`, and `_init_3cc0`, plus complete disassembly reference.
3. `ttmverifylite_elf_sections_and_image.cpp`: Complete 2,742-element `.text` instruction word table, 4,179-byte `.rodata` section array, and 34,672-byte ELF image array.
