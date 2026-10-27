# Clean-Room Reconstruction of `libropaencrypt.so` (Target 142 / 169)

## 1. Binary Overview / Tổng quan nhị phân
- **Library**: `libropaencrypt.so` (`34,904 bytes`)
- **SHA-256**: `1906ed4f2bf0b3621e90a1b502fb1c562cb73a4068cc8f2f734f05992d0436b3`
- **Architecture**: `AArch64` (`EM_AARCH64`, Little-Endian)
- **JNI Classes**: `com/bytedance/ropa/encrypt/RopaEncrypt` (`8` native methods @ `.data 0xc000..0xc0c0`) & `com/bytedance/ropa/encrypt/EncryptResult`
- **Unwind Table**: `.eh_frame_hdr` at `0x5f68` (`36` FDEs), `.eh_frame` at `0x6098`
- **Code Section**: `.text` at `0x1260..0x5cf4` (`19,092 bytes`, `4,773` AArch64 instructions)

## 2. Reconstructed C++17 Files / Các tệp C++17 phòng sạch
1. `ropaencrypt.hpp`: Constants, error codes (`-101`, `-102`, `-104`, `-106`, `-201`), 8 `JNINativeMethod` descriptors, and all 36 FDE declarations.
2. `ropaencrypt_core.cpp`: Complete C++17 implementation of `RopaGenerateRandomInt_231c`, `RopaDerive16ByteHexKey_2378`, `RopaBase64Encode_23cc`, `RopaBase64Decode_2488`, `RopaComputeHash31_2548`, `RopaParseDecimalUint_3f3c`, `RopaEvpAesCipherCore_547c`, `RopaBuildEncryptSeqV1_3540`, `RopaBuildEncryptSeqV2_257c`, `RopaParseDecryptSeq_3f78`, and `JNI_OnLoad`.
3. `ropaencrypt_elf_sections_and_image.cpp`: Complete 4,773-element `.text` instruction word table, 628-byte `.rodata` array, and 34,904-byte ELF image array.
