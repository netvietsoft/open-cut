# Architectural Summary — `libttboringssl.so` (Target 41)
# Tóm tắt Kiến trúc — `libttboringssl.so` (Mục tiêu 41)

## 1. Binary Overview / Tổng quan Nhị phân (`OBSERVED`)
- **Binary Path**: `SOURCE/apktool-res/lib/arm64-v8a/libttboringssl.so` (395,304 bytes)
- **ELF Sections**:
  - `.dynsym`: `0x002bf0` (size `0x0057f0`, 558 defined functions, 370 imported symbols from `libttcrypto.so` & `libc.so`)
  - `.rela.dyn`: `0x00da88` (size `0x0026d0`)
  - `.text`: `0x014a20` (size `0x02fdc8` = 196,040 bytes of AArch64 machine code)
  - `.rodata`: `0x0447e8` (size `0x002add`, 306 ASCII strings)
  - `.data.rel.ro`: `0x061aa8` (size `0x001470`)

## 2. Reconstructed Subsystems / Các Phân hệ Đã Tái dựng
1. **[`ttboringssl_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libttboringssl/ttboringssl_types.h)**:
   - Exact ABI struct layouts verified via `static_assert(offsetof(...))`:
     - `SSL_CIPHER` (`algorithm_enc` at `+0x1c`, `algorithm_mac` at `+0x20`)
     - `SSL_SESSION` (`flags_1b0` at `+0x1b0`)
     - `DTLS1_STATE` (`next_timeout_tv_sec` at `+0x1f8`, `next_timeout_tv_usec` at `+0x200`, `timeout_duration_ms` at `+0x208`)
     - `SSL3_STATE` (`pending_app_data_ptr` at `+0x80`, `write_shutdown` at `+0xac`, `read_shutdown` at `+0xb0`, `rwstate` at `+0xc4`, `quic_read_level` at `+0xc8`, `quic_write_level` at `+0xcc`, `ech_status` at `+0xd8`, `flags_dc` at `+0xdc`, `hs` at `+0x118`, `write_traffic_secret` at `+0x120`, `read_traffic_secret` at `+0x150`, `write_traffic_secret_len` at `+0x1b0`, `read_traffic_secret_len` at `+0x1b1`)
     - `SSL_CONFIG` (`conf_min_version` at `+0x08`, `conf_max_version` at `+0x0a`, `alpn_client_proto_ptr` at `+0x78`, `quic_transport_params_ptr` at `+0xa0`, `flags_e8` at `+0xe8`, `ech_flags_e9` at `+0xe9`)
     - `ssl_ctx_st` (`conf_max_version` at `+0x48`, `conf_min_version` at `+0x4a`, `quic_method` at `+0x50`, `references` at `+0xb0`)
     - `ssl_st` (`config` at `+0x08`, `rbio` at `+0x18`, `wbio` at `+0x20`, `do_handshake` at `+0x28`, `s3` at `+0x30`, `d1` at `+0x38`, `initial_timeout_duration_ms` at `+0x50`, `max_cert_list` at `+0x88`, `hostname` at `+0x90`, `quic_method` at `+0x98`, `flags_a4` at `+0xa4`)
2. **[`ttboringssl_ciphers_transcript.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libttboringssl/ttboringssl_ciphers_transcript.cpp)**:
   - 23 BoringSSL Cipher Suites, `SSL_CIPHER_is_aead` (`0x02fb70`), `SSL_CIPHER_get_cipher_nid` (`0x02fb7c`), `SSL_CIPHER_get_digest_nid` (`0x02fbe8`), RFC 8446 HKDF-Expand-Label (`"tls13 "`), TLS 1.3 Key Schedule, TLS 1.2 PRF, and `bssl::SSL_get_traffic_secrets` (`0x03224c`).
3. **[`ttboringssl_handshake_tls13.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libttboringssl/ttboringssl_handshake_tls13.cpp)**:
   - TLS 1.2/1.3 Client & Server Handshake state machines (`0x032dc0`), Encrypted Client Hello (`0x017b20..0x019424`), and Split-Handshake Handoff/Handback (`0x01fe40..0x020ab8`).
4. **[`ttboringssl_quic_dtls_alpn.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libttboringssl/ttboringssl_quic_dtls_alpn.cpp)**:
   - QUIC encryption levels & flight limits (`0x032c98..0x0350f0`), DTLS retransmission timer doubling with 60,000 ms (`0xea60`) ceiling (`0x016504`), SRTP profiles (`0x016a28..0x016c1c`), and ALPN/SNI extensions (`0x034588..0x03493c`).
5. **[`ttboringssl_session_bio_api.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libttboringssl/ttboringssl_session_bio_api.cpp)**:
   - `SSL_SESSION_to_bytes` (`0x02c1c8`) with `"NOT RESUMABLE"` 14-byte sentinel, `SSL_SESSION_from_bytes` (`0x02c3c0`), `BIO_f_ssl` (`0x014a5c`), and `SSL_CTX`/`SSL` lifecycle & record I/O (`0x03249c..0x0341ac`).
