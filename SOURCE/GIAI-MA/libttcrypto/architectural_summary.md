# Báo Cáo Kiến Trúc & Giải Mã Nhị Phân: `libttcrypto.so`
# Architectural Summary & Binary Reconstruction: `libttcrypto.so`

> **Thư viện / Library**: `libttcrypto.so` (1,231,952 bytes — 1.23 MB)
> **Kiến trúc / Architecture**: `arm64-v8a` (ELF 64-bit LSB shared object, AArch64)
> **Vai trò / Role**: Lõi Mật mã học BoringSSL Tùy biến của ByteDance (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
> **Số lượng hàm xuất khẩu / Exported Functions**: `2,353` hàm C API (`X509_*`, `EVP_*`, `ASN1_*`, `BN_*`, `BIO_*`, `EC_*`, `CRYPTO_*`, `CBS_*`, `CBB_*`, `HMAC_*`, `HKDF_*`, `X25519_*`, `ED25519_*`)

---

## 1. Bố Cục Phân Đoạn ELF (ELF Section Layout)

| Phân đoạn (Section) | Địa chỉ ảo (VMA) | Offset tệp | Kích thước (Bytes) | Mô tả chức năng (Description) |
|---|---|---|---|---|
| `.dynsym` | `0x0097b8` | `0x0097b8` | `60,408` (`0x00ebf8`) | Bảng 2,514 ký hiệu động (2,353 hàm xuất khẩu `STT_FUNC`) |
| `.text` | `0x049700` | `0x049700` | `539,036` (`0x08399c`) | Mã máy thực thi AArch64 + tập lệnh tăng tốc phần cứng ARMv8 Crypto/NEON |
| `.rodata` | `0x0cd100` | `0x0cd100` | `98,240` (`0x017fc0`) | Bảng hằng số SHA-256/512 (`0x0e1000`), Rijndael S-Box, OID ASN.1 và chuỗi lỗi |
| `.data` | `0x130000` | `0x12c000` | `1,096` (`0x000448`) | Bảng phương thức mặc định và con trỏ hàm toàn cục |
| `.bss` | `0x130450` | `0x12c448` | `22,936` (`0x005998`) | Ngữ cảnh DRBG (`0x0e2218`), khóa khởi tạo một lần `pthread_once` và cờ CPU `OPENSSL_armcap_P` |

---

## 2. 6 Phân Hệ Thuật Toán Cốt Lõi Đã Tái Cấu Trúc (6 Reconstructed Core Subsystems)

1. **Phân hệ Băm Mật mã & Dẫn xuất Khóa (`ttcrypto_hash_hmac.h` / `.cpp`)**:
   - Hiện thực hóa đầy đủ `SHA256_Init` (`0x0be370`), `SHA256_Transform` (`0x0be408` -> `0x0c9740`), `SHA256_Update`, `SHA256_Final` (`0x0be404`), `SHA512_Init`, `SHA512_Transform` (80 vòng 64-bit).
   - Hiện thực hóa `HMAC` (`0x0b6f6c`), `HMAC_Init_ex` (`0x0b7084`) theo chuẩn RFC 2104 (`ipad = 0x36`, `opad = 0x5c`) và `HKDF_extract` (`0x070ea8`), `HKDF_expand` (`0x070f34`) theo chuẩn RFC 5869 phục vụ TLS 1.3 & TTQUIC.

2. **Phân hệ Mã khối AES & Xác thực GCM128 trên $\text{GF}(2^{128})$ (`ttcrypto_aes_gcm.h` / `.cpp`)**:
   - Hiện thực hóa `AES_set_encrypt_key` (`0x0a48e0`) và `AES_encrypt` (`0x0a4850`) cho AES-128/192/256 (10/12/14 vòng), chế độ CBC và CTR.
   - Hiện thực hóa `CRYPTO_gcm128_init`, `CRYPTO_gcm128_setiv`, `CRYPTO_gcm128_aad` (`0x0b8d7c`), `CRYPTO_gcm128_encrypt` (`0x0b8e78`), `CRYPTO_gcm128_decrypt`, `CRYPTO_gcm128_finish`, `CRYPTO_gcm128_tag` (`0x0b9610`) sử dụng phép nhân đa thức $\text{GF}(2^{128})$ với đa thức tối giản $x^{128} + x^7 + x^2 + x + 1$ (`0xE100000000000000`).

3. **Phân hệ Mã dòng ChaCha20 & Xác thực Một lần Poly1305 (`ttcrypto_chacha_poly1305.h` / `.cpp`)**:
   - Hiện thực hóa `CRYPTO_chacha_20` (`0x058d88`) gồm 20 vòng lặp QuarterRound trên ma trận trạng thái $4 \times 4$ với hằng số `"expand 32-byte k"` (`0x61707865, 0x3320646e, 0x79622d32, 0x6b206574`) và `CRYPTO_hchacha20`.
   - Hiện thực hóa `CRYPTO_poly1305_init` / `update` / `finish` dùng số học 5-limb cơ số $2^{26}$ modulo $2^{130} - 5$ cùng mặt nạ kẹp khóa RFC 8439.

4. **Phân hệ Đường cong Elliptic Curve25519 — X25519 & Ed25519 (`ttcrypto_curve25519.h` / `.cpp`)**:
   - Hiện thực hóa số học trường hữu hạn $\mathbb{F}_{2^{255}-19}$ thời gian hằng (constant-time `gf_cswap`, `gf_mul`, `gf_inv` theo Định lý nhỏ Fermat $a^{2^{255}-21} \bmod (2^{255}-19)$).
   - Hiện thực hóa thang Montgomery `X25519` (`0x06053c`) với hằng số $a_{24} = 121665$ (`0x1db41`), `X25519_keypair` (`0x060410`), `ED25519_sign` (`0x05eec4`) và `ED25519_verify` (`0x05ff28`).

5. **Phân hệ Điều phối EVP Cipher/AEAD & Bộ phân tích ASN.1 DER CBS/CBB (`ttcrypto_evp_x509.h` / `.cpp`)**:
   - Hiện thực hóa `EVP_EncryptInit_ex` (`0x0aec80`), `EVP_CipherUpdate`, `EVP_CipherFinal_ex`, `EVP_AEAD_CTX_init` (`0x0ae3c8`), `EVP_AEAD_CTX_seal`, `EVP_AEAD_CTX_open`.
   - Hiện thực hóa bộ đọc/ghi ASN.1 DER không sao chép `CBS_*` và `CBB_*`, hàm so sánh thời gian hằng `CRYPTO_memcmp` (`0x0749cc`) và bộ sinh số ngẫu nhiên mật mã `RAND_bytes` (`0x0ad674`).
