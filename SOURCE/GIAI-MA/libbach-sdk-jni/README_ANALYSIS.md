# Giải Mã & Tái Dựng `libbach-sdk-jni.so` (Target 71 / 169)

## 1. Thông Số Nhị Phân Chuẩn Xác (`[OBSERVED]`)

| Thuộc tính | Giá trị quan sát từ nhị phân gốc (`libbach-sdk-jni.so`) |
|---|---|
| **Tên thư viện** | `libbach-sdk-jni.so` (`com.bytedance.byted_bach_sdk`) |
| **Kích thước** | `117,112 bytes` (`114.37 KB`) |
| **SHA-256** | `6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929` |
| **Kiến trúc** | `ELF64 AArch64 (ARM64-v8a)`, Little-Endian, 29 Sections |
| **Bảng `.dynsym`** | `VA = 0x0002c0, SZ = 2,712 bytes` (`113 symbols`: `92 imported [001..092]`, `17 exported JNI FUNC [093..112]`, `3 ABS`) |
| **Phân đoạn `.text`** | `VA = 0x003820..0x013fdf` (`67,520 bytes`, `VA == File Offset` 1:1) |
| **Phân đoạn `.rodata`** | `VA = 0x014f5c..0x015aec` (`2,961 bytes`, `VA == File Offset` 1:1) |
| **Phân đoạn `.data.rel.ro`** | `VA = 0x01f8a8..0x01fa2f` (`File Offset = 0x01b8a8`, `392 bytes`, 5 vtable C++) |
| **Phân đoạn `.init_array`** | `VA = 0x01fa40` (`[0x003820]` — `_GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp`) |
| **Phân đoạn `.fini_array`** | `VA = 0x01fa30` (`[0x00394c, 0x00393c]`) |
| **Phân đoạn `.bss`** | `VA = 0x020010..0x0202bf` (`688 bytes`: `.bss 0x020010` `std::unordered_set<int>`, `.bss 0x0202b0` `g_ClassLoader`, `.bss 0x0202b8` `g_JavaVM`) |

---

## 2. Danh Sách 17 Hàm JNI Xuất Khẩu Trong `.dynsym` (`[OBSERVED]`)

| STT | `.dynsym` | Địa chỉ VA | Kích thước | Tên hàm xuất khẩu |
|---|---|---|---|---|
| 1 | `[093]` | `0x003c8c` | `236 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetEnable` |
| 2 | `[094]` | `0x00f61c` | `144 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeCreate` |
| 3 | `[095]` | `0x0039c4` | `568 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeCreate` |
| 4 | `[096]` | `0x005c14` | `1528 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeGetResult` |
| 5 | `[097]` | `0x004b1c` | `1600 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetStringParams` |
| 6 | `[099]` | `0x00519c` | `2552 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeExec` |
| 7 | `[100]` | `0x00f224` | `8 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDestroy` (alias với `[102]`) |
| 8 | `[102]` | `0x00f224` | `8 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeDestroy` (alias với `[100]`) |
| 9 | `[103]` | `0x0102b0` | `136 B` | `JNI_OnLoad` |
| 10 | `[104]` | `0x00515c` | `64 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeDestroy` |
| 11 | `[105]` | `0x0044e4` | `1436 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetFloatParams` |
| 12 | `[106]` | `0x003d78` | `1432 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetIntParams` |
| 13 | `[108]` | `0x00edd0` | `956 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeCreate` |
| 14 | `[109]` | `0x003bfc` | `144 B` | `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeInitGraph` |
| 15 | `[110]` | `0x00eb38` | `508 B` | `Java_com_bytedance_byted_1bach_1sdk_buffer_BachBitmapHandle_nativeGet` |
| 16 | `[111]` | `0x00f22c` | `660 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDownloadModels` |
| 17 | `[112]` | `0x00f55c` | `192 B` | `Java_com_bytedance_byted_1bach_1sdk_finder_ModelDownloadListener_deleteNativeObject` |

---

## 3. Chứng Minh Toán Học & Opcode AArch64 (`[OBSERVED]`)

1. **Khởi tạo 39 mã loại kết quả trong `.init_array[0]` (`0x003820..0x0038f4`)**:
   - Đặt `max_load_factor = 1.0f` (`mov w8, #0x3f800000; str w8, [x19, #0x20]` @ `0x003848..0x003854`).
   - Vòng lặp nạp 39 số nguyên `int32_t` (`156 bytes = 0x9c`, `cmp x21, #0x9c` @ `0x0038a4`) từ `.rodata 0x014f98..0x015033` vào `.bss 0x020010` thông qua `__hash_table::__emplace_unique_key_args<int>` (`0x006560`).
2. **Định vị thùng băm bằng NEON Popcount (`0x005cc0..0x005cde` & `0x0062e0..0x0062fc`)**:
   - Sử dụng `fmov d0, x8; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w10, s0; cmp w10, #1` để kiểm tra xem `bucket_count` có phải lũy thừa của 2 hay không (`hash & (bucket_count - 1)` so với `udiv`/`msub` `hash % bucket_count`).
3. **Bảng nhảy 30 nhánh `convertBachObjectToJava` (`0x00702c..0x00a980`, `.rodata 0x014f5c..0x014f97`)**:
   - Tính địa chỉ nhảy: $\text{VA}_{\text{target}} = \text{0x007084} + \text{int16\_t}(\text{table}[\text{type} - 1]) \times 4$.
   - Ba hằng số nhân nghịch đảo chia số nguyên cho kích thước phần tử:
     - `Matrix3x3f` (`36 bytes = 4 * 9` @ `0x007ca8`): `0x38e38e38e38e38e3` ($9 \times \text{0x38e38e38e38e38e3} \equiv 1 \pmod{2^{65}}$).
     - `Vector3f` (`12 bytes = 4 * 3` @ `0x009904`): `0xaaaaaaaaaaaaaaaab` ($3 \times \text{0xaaaaaaaaaaaaaaaab} \equiv 1 \pmod{2^{65}}$).
     - `BachObject` (`136 bytes = 8 * 17` @ `0x00a46c`): `0xf0f0f0f0f0f0f0f1` ($17 \times \text{0xf0f0f0f0f0f0f0f1} \equiv 1 \pmod{2^{68}}$).
4. **6 vòng lặp mở rộng kiểu dữ liệu NEON SIMD (`0x00a994..0x00b80c`) & 4 bộ chuyển đổi Pixel NEON (`0x00ff4c..0x0102ac`)**:
   - Mở rộng `uint16 -> int64` (`0x00a994`), `int16 -> int64` (`0x00ac64`), `uint32 -> int64` (`0x00af34`), `int32 -> int64` (`0x00b1f0`), `float -> double` (`0x00b4ac`), và sao chép khối 32-byte (`0x00b768`).
   - Chuyển đổi `GRAY8 -> RGBA8888` (`0x00ff4c`), `RGB888 -> RGBA8888` (`0x01000c`), `BGR888 -> RGBA8888` (`0x0100dc`), và `BGRA8888 -> RGBA8888` (`0x0101c8`).
