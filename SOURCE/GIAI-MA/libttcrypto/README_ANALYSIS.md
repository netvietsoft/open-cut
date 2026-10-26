# Phân Tích & Tái Cấu Trúc Hoàn Chỉnh: `libttcrypto.so`
# Complete Cleanroom Reconstruction: `libttcrypto.so`

## Danh Mục Tệp Mã Nguồn (Source File Inventory)

| Tệp tin (File) | Vai trò (Role) |
|---|---|
| `ttcrypto_types.h` | Định nghĩa cấu trúc ABI AArch64 (`SHA256_CTX`, `SHA512_CTX`, `HMAC_CTX`, `AES_KEY`, `GCM128_CONTEXT`, `poly1305_state`, `EVP_CIPHER_CTX`, `EVP_AEAD_CTX`, `CBS`, `CBB`) |
| `ttcrypto_hash_hmac.h` / `.cpp` | Hiện thực SHA-224/256 (`0x0be370`), SHA-384/512, HMAC RFC 2104 (`0x0b6f6c`) và HKDF RFC 5869 (`0x070ea8`, `0x070f34`) |
| `ttcrypto_aes_gcm.h` / `.cpp` | Hiện thực AES-128/192/256 (`0x0a48e0`, `0x0a4850`), CBC, CTR và GCM128 trên $\text{GF}(2^{128})$ (`0x0b8d7c`, `0x0b8e78`, `0x0b9610`) |
| `ttcrypto_chacha_poly1305.h` / `.cpp` | Hiện thực ChaCha20 (`0x058d88`), HChaCha20, Poly1305 trên $\mathbb{Z}/(2^{130}-5)\mathbb{Z}$ và AEAD-ChaCha20-Poly1305 |
| `ttcrypto_curve25519.h` / `.cpp` | Hiện thực toán học trường $\mathbb{F}_{2^{255}-19}$, X25519 (`0x06053c`, `0x060410`) và chữ ký số Ed25519 (`0x05eec4`, `0x05ff28`) |
| `ttcrypto_evp_x509.h` / `.cpp` | Hiện thực `CRYPTO_memcmp` (`0x0749cc`), `RAND_bytes` (`0x0ad674`), `EVP_Cipher*` (`0x0aec80`), `EVP_AEAD_CTX_*` (`0x0ae3c8`) và `CBS`/`CBB` ASN.1 DER |
| `ttcrypto_interface.h` / `.cpp` | Giao diện hợp nhất `OPENSSL_init_crypto` và bộ kiểm thử tự động KAT 6 phân hệ |
| `ttcrypto_pseudocode.cpp` | Các hàm đối soát độ lệch ABI (`offsetof`/`sizeof`) và điểm vào kiểm chứng toàn cục |
