# Clean-Room Reconstruction of `liblynx-imageloader.so` (Target 143 / 169)

## 1. Binary Overview / Tổng quan nhị phân
- **Library**: `liblynx-imageloader.so` (`35,168 bytes`)
- **SHA-256**: `ccac078dcc95156b659eee639c7de486506043f767f6a3ab4da873c95ed5d5e0`
- **Architecture**: `AArch64` (`EM_AARCH64`, Little-Endian)
- **Exported JNI Symbol**: `Java_com_bytedance_lynx_tasm_ui_imageloader_BitmapBlur_nativeBlur` (`0x403c..0x4bf0`, `2,996 bytes`)
- **Unwind Table**: `.eh_frame_hdr` at `0x06a8` (`2` FDEs), `.eh_frame` at `0x06c8`
- **Code Section**: `.text` at `0x4000..0x4bf8` (`3,064 bytes`, `766` AArch64 instructions)
