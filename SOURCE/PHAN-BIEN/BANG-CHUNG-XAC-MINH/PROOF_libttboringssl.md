# Adversarial Verification Proof — `libttboringssl.so` (Target 41)
# Bằng chứng Xác minh Đối kháng — `libttboringssl.so` (Mục tiêu 41)

## 1. Binary & Cleanroom Metrics / Chỉ số Nhị phân & Tái dựng
- **Binary**: `SOURCE/apktool-res/lib/arm64-v8a/libttboringssl.so` (`395,304 bytes`, 558 exported functions)
- **Cleanroom C++17 Source**: 12 `.h`/`.cpp` files in `SOURCE/GIAI-MA/libttboringssl/` (`> 98 KB`, `0 stubs`)
- **Task ID**: `TASK-080-RECONSTRUCTION-LIBTTBORINGSSL`

## 2. Direct AArch64 Disassembly & ABI Struct Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct ABI
1. **Cipher Suite NID & AEAD Mapping (`0x02fb70` & `0x02fb7c` & `0x02fbe8`)**:
   - `0x02fb70`: `ldr w8, [x0, #0x20]; ubfx w0, w8, #1, #1; ret` — extracts bit 1 (`SSL_AEAD = 0x02`) of `cipher->algorithm_mac` at `+0x20`.
   - `0x02fb7c`: `ldr w8, [x0, #0x1c]` — maps `cipher->algorithm_enc` at `+0x1c` to `NID_des_ede3_cbc (0x2c = 44)`, `NID_aes_128_cbc (0x1a3 = 419)`, `NID_aes_256_cbc (0x1ab = 427)`, `NID_aes_128_gcm (0x37f = 895)`, `NID_aes_256_gcm (0x385 = 901)`, `NID_chacha20_poly1305 (0x3b6 = 950)`.
   - `0x02fbe8`: `ldr w8, [x0, #0x20]; cmp w8, #1; cset w9, eq; lsl w9, w9, #6; cmp w8, #2; csel w0, wzr, w9, eq` — maps `SSL_SHA1 (1)` to `NID_sha1 (64)` and `SSL_AEAD (2)` to `NID_undef (0)`.
2. **DTLS Retransmission Timer Exponential Backoff (`0x0164fc` & `0x016504`)**:
   - `0x0164fc`: `str w1, [x0, #0x50]; ret` — stores `initial_timeout_duration_ms` at `ssl + 0x50`.
   - `0x01653c..0x01655c`: `ldr x8, [x19, #0x38]; ldr w9, [x8, #0x208]; lsl w10, w9, #1; ubfx w9, w9, #4, #0x1b; cmp w9, #0x753; mov w9, #0xea60; csel w9, w10, w9, lo; str w9, [x8, #0x208]` — doubles `d1->timeout_duration_ms` (`+0x208`) up to the 60,000 ms (`0xea60`) ceiling when `(w9 >> 4) >= 0x753` (`1875 * 16 = 30,000 ms`).
3. **TLS 1.3 Traffic Secret Schedule & Accessor (`0x03224c`)**:
   - `0x03226c..0x0322bc`: requires `version > 0x0303` (`TLS1_2_VERSION`) and bit 5 of `s3->flags_dc` (`+0xdc`), returning `read_traffic_secret` (`s3 + 0x150`, length at `s3 + 0x1b1`) and `write_traffic_secret` (`s3 + 0x120`, length at `s3 + 0x1b0`).
4. **QUIC Encryption Levels, Flight Limits & Transport Params (`0x032c98..0x0350f0`)**:
   - `SSL_quic_read_level` (`0x032d00`): `ldr x8, [x0, #0x30]; ldr w0, [x8, #0xc8]; ret`.
   - `SSL_quic_write_level` (`0x032d0c`): `ldr x8, [x0, #0x30]; ldr w0, [x8, #0xcc]; ret`.
   - `SSL_get_peer_quic_transport_params` (`0x0336c0`): loads `s3 + 0x240` (pointer) and `s3 + 0x248` (length).
5. **SSL_SESSION Serialization & `"NOT RESUMABLE"` Sentinel (`0x02c1c8`)**:
   - `0x02c1f0`: `ldrb w8, [x0, #0x1b0]; tbnz w8, #2, #0x2c230` — when bit 2 (`not_resumable`) at `session + 0x1b0` is set, returns the 14-byte `"NOT RESUMABLE\0"` buffer from `.rodata` (`0x04545e`).
