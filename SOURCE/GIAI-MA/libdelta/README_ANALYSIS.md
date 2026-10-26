# Phân Tích Kiến Trúc & Giải Mã Nhị Phân `libdelta.so` (Target 51 / 169)

- **Task ID**: `TASK-090-RECONSTRUCTION-LIBDELTA` (`TASK_SO_159`)
- **Đường dẫn binary**: `SOURCE/apktool-res/lib/arm64-v8a/libdelta.so` (`18,256 bytes`)
- **Package Java**: `net.bytedance.zdplib.Delta` & `net.bytedance.zdplib.DeltaSignerVerifier`
- **Tổng số ký hiệu động (`.dynsym`)**: `71` symbols (`19` exported `STT_FUNC` + `52` imported)
- **Dung lượng C++17 & Header tái dựng**: `~75 KB` trên 8 tệp (`0 stubs`)

## 1. Bố Cục Phân Đoạn ELF64 & Bộ Nhớ Toàn Cục
- `PT_LOAD 0 (R+X)`: `vaddr 0x000000..0x0038e8 -> file 0x000000..0x0038e8`
- `PT_LOAD 1 (R+W)`: `vaddr 0x007c60..0x008008 -> file 0x003c60..0x004000` (`file_offset = vaddr - 0x4000`)
- `.plt`: `0x001830..0x001b00` (`43` mục nhảy tới `.got 0x007ea0..0x007ff0`)
- `.text`: `0x001b00..0x00322c` (`5,932 bytes`)
- `.rodata`: `0x00322c..0x003423` (`503 bytes`)
- `.bss`: `0x008000..0x008008` (`8 bytes`, con trỏ đơn thể `EC_GROUP*` cho `NID_X9_62_prime256v1 = 0x19f = 415`)

## 2. Cấu Trúc Gói Tin Đường Truyền AES-256-GCM (Bù 34 Byte = `0x22`)
- `getEncryptedLen(plaintext_len)` (`0x001f5c`): `add w0, w2, #0x22` (`plaintext_len + 34`)
- `getDecryptedLen(encrypted_len)` (`0x002430`): `sub w0, w2, #0x22` (`encrypted_len - 34`)
- Bố cục gói tin (`encrypt` @ `0x001c98` & `decrypt` @ `0x00217c`):
  - `+0x00..+0x01` (`2B`): Magic Header `0x01bd` (little-endian: `[0xbd, 0x01]`, ghi bằng `mov w8, #0x1bd; strh w8, [x23]` tại `0x001df0..0x001dfc` và kiểm tra bằng `ldrb w8, [x24]; cmp w8, #0xbd; ldrb w8, [x24, #1]; cmp w8, #1` tại `0x002248..0x00225c`)
  - `+0x02..+0x11` (`16B`): Vector khởi tạo ngẫu nhiên `IV` (`RAND_bytes(sp+0x18, 0x10)`, cấu hình `EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN = 9, 16, NULL)` tại `0x001e34..0x001e44`)
  - `+0x12..+0x12+N-1` (`N B`): Bản mã AES-256-GCM (`EVP_EncryptUpdate` / `EVP_DecryptUpdate`)
  - `+0x12+N..+0x22+N-1` (`16B`): Thẻ xác thực GCM (`EVP_CTRL_GCM_GET_TAG = 0x10` / `EVP_CTRL_GCM_SET_TAG = 0x11`)

## 3. 4 Hàm Nội Bộ `.text` & 19 Hàm Xuất JNI
- `0x002d0c` (`500B`): `create_EC_KEY_from_private_key_bin` (`NID_X9_62_prime256v1 = 0x19f`, `BN_bin2bn`, `EC_POINT_mul`)
- `0x002f00` (`380B`): `create_EC_KEY_from_public_key_bin` (`0x21 = 33B` nén hoặc `0x41 = 65B` không nén, `EC_POINT_oct2point`)
- `0x00307c` (`216B`): `generate_keypair` (`EC_KEY_generate_key` + `BN_bn2bin_padded` 32B)
- `0x003154` (`216B`): `sign` (`SHA256_Init/Update/Final` + `ECDSA_sign`)
- `19` hàm JNI cho `net.bytedance.zdplib.Delta` (`12` hàm) và `net.bytedance.zdplib.DeltaSignerVerifier` (`7` hàm, trong đó `DeltaSignerVerifier_verify` tại `0x002b34` nhảy đuôi `b #0x1890` sang `Delta_verify` tại `0x002654`).
