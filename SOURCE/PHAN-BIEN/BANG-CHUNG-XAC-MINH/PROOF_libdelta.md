# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG: `libdelta.so` (Target 51 / 169)

- **Task ID**: `TASK-090-RECONSTRUCTION-LIBDELTA` (`TASK_SO_159`)
- **Binary mục tiêu**: `SOURCE/apktool-res/lib/arm64-v8a/libdelta.so` (`18,256 bytes`)
- **Trạng thái đối kháng**: `VERIFIED_AND_ACCEPTED`

## 1. Bằng Chứng Opcode AArch64 & Cấu Trúc Gói Tin 34 Byte (`0x22`)
1. **`getEncryptedLen` (`0x001f5c`) & `getDecryptedLen` (`0x002430`)**:
   - `0x001f5c: 40880011 add w0, w2, #0x22` ; `0x001f60: c0035fd6 ret`
   - `0x002430: 40880051 sub w0, w2, #0x22` ; `0x002434: c0035fd6 ret`
2. **`Java_net_bytedance_zdplib_Delta_encrypt` (`0x001c98..0x001f58`, 708 bytes)**:
   - `0x001df0: a8378052 mov w8, #0x1bd`
   - `0x001dfc: e8020079 strh w8, [x23]` (ghi 2 byte magic `[0xbd, 0x01]`)
   - `0x001df8..0x001e08: mov w1, #0x10; bl RAND_bytes (0x0018e0); ldur q0, [sp, #0x18]; stur q0, [x23, #2]` (ghi 16B IV tại `+0x02..+0x11`)
   - `0x001e34..0x001e44: mov w1, #9; mov w2, #0x10; bl EVP_CIPHER_CTX_ctrl (0x0019e0)` (`EVP_CTRL_GCM_SET_IVLEN = 9, iv_len = 16`)
   - `0x001eb0..0x001ec0: mov w1, #0x10; mov w2, #0x10; bl EVP_CIPHER_CTX_ctrl (0x0019e0)` (`EVP_CTRL_GCM_GET_TAG = 0x10, tag_len = 16`)
3. **`Java_net_bytedance_zdplib_Delta_decrypt` (`0x00217c..0x00242c`, 692 bytes)**:
   - `0x002234: 9b8b0071 subs w27, w28, #0x22`
   - `0x002248..0x00225c: ldrb w8, [x24]; cmp w8, #0xbd; ldrb w8, [x24, #1]; cmp w8, #1` (nếu sai trả về `-8` tại `0x002274`)
   - `0x002390..0x0023a4: sub w8, w28, #0x12; mov w1, #0x11; mov w2, #0x10; add x3, x9, w8, sxtw; bl EVP_CIPHER_CTX_ctrl` (`EVP_CTRL_GCM_SET_TAG = 0x11`)

## 2. Bằng Chứng 4 Hàm Nội Bộ `.text` & 19 Hàm Xuất JNI
- `0x002d0c`: `create_EC_KEY_from_private_key_bin` (`NID_X9_62_prime256v1 = 0x19f = 415`)
- `0x002f00`: `create_EC_KEY_from_public_key_bin` (`0x21 = 33B` hoặc `0x41 = 65B`, `.bss 0x008000` `EC_GROUP*`)
- `0x00307c`: `generate_keypair` (`EC_KEY_generate_key` + `BN_bn2bin_padded` 32B)
- `0x003154`: `sign` (`SHA256_Init/Update/Final` + `ECDSA_sign`)
- `0x002b34`: `Java_net_bytedance_zdplib_DeltaSignerVerifier_verify` (`57fbff17 b #0x1890` nhảy đuôi sang `Java_net_bytedance_zdplib_Delta_verify` tại `0x002654`).
