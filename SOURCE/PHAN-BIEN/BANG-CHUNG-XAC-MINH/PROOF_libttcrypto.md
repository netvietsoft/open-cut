# Bằng Chứng Xác Minh Đối Kháng: `libttcrypto.so`
# Adversarial Verification Proof: `libttcrypto.so`

- **Thư viện / Library**: `libttcrypto.so` (`1,231,952` bytes)
- **Dung lượng C++ tái cấu trúc / Reconstructed C++ Size**: `122,778` bytes trên 14 tệp `.cpp` và `.h` (`0` stub)
- **Số ký hiệu động / Exported Symbols**: `2,514` tổng ký hiệu (`2,353` hàm C xuất khẩu `STT_FUNC`)

---

## 1. Bằng Chứng Khớp Lệnh Máy AArch64 (AArch64 Opcode Parity)

1. **`SHA256_Init` (`0x0be370`)**:
   - Lệnh máy: `mov w2, #0x70; bl #0xc3d60` (xóa 112 bytes `SHA256_CTX`), `ldr q0, [x8, #0xc0]; ldr q1, [x9, #0xd0]` (nạp 8 hằng số $H_0 \dots H_7$ từ `.rodata` `0x0e10c0`), `mov w8, #0x20; str w8, [x19, #0x6c]` (ghi `md_len = 32` tại offset `+0x6c`).
2. **`AES_set_encrypt_key` (`0x0a48e0`) & `AES_encrypt` (`0x0a4850`)**:
   - Kiểm tra độ dài khóa `128`, `192` (`cmp w20, #0xc0`) và `256` (`cmp w20, #0x100`), mở rộng khóa vòng vào `AES_KEY` (`0xf4 = 244` bytes, `rounds` tại `+0xf0`).
3. **`CRYPTO_gcm128_aad` (`0x0b8d7c`), `CRYPTO_gcm128_encrypt` (`0x0b8e78`), `CRYPTO_gcm128_tag` (`0x0b9610`)**:
   - Truy cập `len.u[1]` tại `+0x38` (`ldr x8, [x0, #0x38]`), `len.u[0]` tại `+0x30` (`ldr x8, [x0, #0x30]`), kiểm tra giới hạn $2^{61}$ bytes (`mov x9, #0x2000000000000000`), đọc con trỏ `key` tại `+0x160` (`ldr x23, [x19, #0x160]`), `mres` tại `+0x184` (`ldr w9, [x19, #0x184]`), và giới hạn độ dài tag tối đa 16 bytes (`cmp x19, #0x10; csel x2, x19, x8, lo`).
4. **`CRYPTO_chacha_20` (`0x058d88`)**:
   - Thực thi 20 vòng lặp QuarterRound RFC 8439 trên ma trận trạng thái 16 từ 32-bit với hằng số `"expand 32-byte k"`.
5. **`X25519` (`0x06053c`), `X25519_keypair` (`0x060410`), `ED25519_sign` (`0x05eec4`), `ED25519_verify` (`0x05ff28`)**:
   - Thang Montgomery trên $\mathbb{F}_{2^{255}-19}$ với $a_{24} = 121665$ và kiểm tra tính chính tắc của $S$ tại byte thứ 63 (`ldrb w8, [x2, #0x3f]; cmp w8, #0x1f`).
6. **`CRYPTO_memcmp` (`0x0749cc`)**:
   - Vòng lặp thời gian hằng khớp 1:1 từng lệnh máy: `ldrb w9, [x0], #1; ldrb w10, [x1], #1; sub x2, x2, #1; eor w9, w10, w9; orr w8, w8, w9; cbnz x2, #0x749d4`.

---

## 2. Chứng Minh Toán Học & Kiểm Thử Đáp Án Chuẩn (Mathematical Proofs & KAT)

- **SHA-256 FIPS 180-4 KAT**: $\text{SHA256}(\text{"abc"}) = \text{ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad}$.
- **HKDF RFC 5869 Test Vector 1**: $\text{HKDF-Extract}(\text{salt}_{13}, \text{0x0b}^{22}) = \text{077709362c2e32df0ddc3f0dc47bba6390b6c73bb50f9c3122ec844ad7c2b3e5}$.
- **GF($2^{128}$) GHASH & GF($2^{130}-5$) Poly1305**: Kiểm chứng khép kín chu trình Seal/Open cho cả `EVP_aead_aes_256_gcm()` và `EVP_aead_chacha20_poly1305()`.
- **Curve25519 ECDH**: Kiểm chứng tính giao hoán $\text{X25519}(k_A, [k_B]9) == \text{X25519}(k_B, [k_A]9)$ trên trường $\mathbb{F}_{2^{255}-19}$.
