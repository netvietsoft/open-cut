# Clean-Room Forensic Analysis & C++17 Reconstruction: `libtobEmbedPagEncrypt.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libtobEmbedPagEncrypt.so`

- **Task ID**: `TASK-166-RECONSTRUCTION-LIBTOBEMBEDPAGENCRYPT` (`TASK_SO_065_libtobEmbedPagEncrypt`) — Target 127 / 169
- **Binary Size / Kích thước nhị phân**: `8,304 bytes` (`0x2070` bytes)
- **SHA-256**: `d1a8cbbcd4982679b44c5e8cb5480526c8f50b484f744f4e18b49585792bc255`
- **Unwind FDEs**: `7` FDEs at `.eh_frame_hdr` (`0x000910..0x000954`)
- **Exported Symbols**: `8` (`sbox0` @ `0x9630`, `sbox1` @ `0x9730`, `ss_encrypted_size` @ `0x0ad0`, `initKey` @ `0x1018`, `ss_encrypt` @ `0x0b44`, `ss_decrypt` @ `0x0ea0`, `ttEncrypt` @ `0x1070`, `ttDecrypt` @ `0x11c8`)
- **Reconstructed C++17 Volume**: `279,520 bytes` across 5 files (`0` stubs)

## Key Binary Forensics & Mathematical Proofs (Bằng Chứng Nhị Phân & Toán Học)
1. **Song ánh S-Box 256 byte (`sbox0` @ `0x009630` & `sbox1` @ `0x009730`)**:
   - Đã kiểm chứng toàn bộ 256 phần tử: $\forall x \in [0, 255],\; \text{sbox1}[\text{sbox0}[x]] = x$.
2. **Mở rộng khóa 128-bit `sub_d0c` (`0x000d0c..0x000ea0`) & `initKey` (`0x001018..0x001070`)**:
   - `initKey()` ghép 16 byte `.rodata` tại `0x0900` (`"UK*@3oKpFlVVnads"`) với hằng số 32-bit `0x41646654` (`"Tfda"`) tạo thành khóa 20 byte `"UK*@3oKpFlVVnadsTfda"` tại `.bss` `0x009830`.
   - `sub_d0c` lấy 16 byte đầu của khóa, thế qua `sbox0`, và đảo thứ tự byte từng từ 32-bit qua lệnh `rev` (`ntohl`).
3. **Thuật toán mã hóa khối 16 byte (`ss_encrypt` @ `0x000b44` & `ss_decrypt` @ `0x000ea0`)**:
   - Header 6 byte: `[0..1] = 0x6374 ('t','c')`, `[2] = 0x03`, `[3] = pad_len = (-in_len) & 0x0F`, `[4..5] = 0x0100`.
   - Mỗi khối 16 byte `(W0, W1, W2, W3)` sau khi thế qua `sbox0` được biến đổi:
     $$W'_0 = \text{rev}(\text{rev}(W_0) \oplus k_0), \quad W'_1 = \text{rev}(k_1 \oplus \text{ror}(\text{rev}(W_1), 24))$$
     $$W'_2 = \text{rev}(k_2 \oplus \text{ror}(\text{rev}(W_2), 16)), \quad W'_3 = \text{rev}(k_3 \oplus \text{ror}(\text{rev}(W_3), 8))$$
