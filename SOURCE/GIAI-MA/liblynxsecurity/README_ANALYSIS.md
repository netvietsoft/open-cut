# Clean-Room Reconstruction Analysis — `liblynxsecurity.so`

- **Task ID**: `TASK-188-RECONSTRUCTION-LIBLYNXSECURITY` (`TASK_SO_152_liblynxsecurity`)
- **Target Index**: 149 / 169
- **Binary Size**: `51,112 bytes`
- **SHA-256**: `2895aab91226bc7ece7795ff2d2aad3b2a947c346946347c454d32cfdabd8c15`
- **Architecture**: `EM_AARCH64` (64-bit ARMv8-A Little-Endian)
- **Unwind Table**: `106` FDEs in `.eh_frame_hdr` (`0x12c4..0x1620`)
- **Executable `.text` Section**: `0x4000..0x74cc` (`13,516 bytes` = `3,379` AArch64 instructions)
- **Exported Symbols**: `5` (`2` JNI methods on `com.bytedance.lynx.service.security.LynxSecurityService` + `3` linker symbols)

## Key Subsystems Reconstructed
1. **JNI Entrypoints (`0x63a8..0x7298`)**:
   - `Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeVerifySignBlock` (`0x63a8..0x6bc4`, `2,076 B`).
   - `Java_com_bytedance_lynx_service_security_LynxSecurityService_nativeUpdateRsaPublicKeys` (`0x6cf0..0x7298`, `1,448 B`).
2. **Lynx Template Signature Block Framing (`0x4c58..0x55e4`)**:
   - `ReadSignBlock` (`0x4c58`), `ReadU64`, `ReadU32` stream parsers validating Lynx template trailing signature blocks and reporting diagnostic strings (`"template file has not been signed."`, `"lynx signature verify failed."`, `"can not find public key!"`).
3. **BoringSSL EVP RSA-SHA256 Verification (`0x55e4..0x5974`)**:
   - Decodes Base64 DER public keys via `EVP_DecodeBlock` + `d2i_PUBKEY` and verifies template digests via `EVP_MD_CTX_new`, `EVP_DigestVerifyInit(..., EVP_sha256())`, `EVP_DigestVerifyUpdate`, and `EVP_DigestVerifyFinal`.
