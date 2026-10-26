# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libbach-sdk-jni.so` (Target 71 / 169)

- **Thư viện**: `libbach-sdk-jni.so` (`117,112 bytes`)
- **SHA-256**: `6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929`
- **Task ID**: `TASK_SO_133_libbach_sdk_jni` / `TASK-110-RECONSTRUCTION-LIBBACH_SDK_JNI`
- **Trạng thái**: `VERIFIED_AND_ACCEPTED` (`0 stubs`, đầy đủ 17/17 hàm JNI xuất khẩu trong `.dynsym`)

---

## 1. Bằng Chứng Opcode Nhị Phân AArch64 (`[OBSERVED]`)

1. **`0x003880..0x0038b4` (`.init_array[0]` — `_GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp`)**:
   - Raw Hex @ `0x003880`: `08 f0 a7 52 f6 03 00 91 e2 03 00 ad 00 e4 00 6f e1 0b 80 3d 60 02 00 ad 68 22 00 b9`
   - Raw Hex @ `0x00389c`: `c1 02 15 8b e0 03 13 aa e2 03 01 aa 50 22 00 94 b5 12 00 91 bf 72 02 f1 41 ff ff 54`
   - Giải mã: Khởi tạo `std::unordered_set<int>` toàn cục tại `.bss 0x020010` (`max_load_factor = 1.0f = 0x3f800000` tại `+0x20`) và chèn 39 mã loại kết quả (`156 bytes = 0x9c`, `cmp x21, #0x9c`) từ `.rodata 0x014f98..0x015033`.
2. **`0x007060..0x00708c` & `.rodata 0x014f5c..0x014f97` (`convertBachObjectToJava` 30-Way Jump Table)**:
   - Raw Hex @ `0x007060`: `28 80 40 b9 08 05 00 51 1f 75 00 71 88 42 01 54 69 00 00 b0 29 71 3d 91 ca 00 00 10 2b 79 68 78 4a 09 0b 8b`
   - Raw Hex @ `0x014f5c`: `00 00 04 06 58 04 a8 05 bd 02 8f 07 5b 08 bd 05 5d 09 f5 02 5a 09 02 02 d5 02 3b 08 38 01 e8 04`
   - Giải mã: Đọc `type = [x1, #0x80]`, kiểm tra `uint32_t(type - 1) <= 29` (`0x1d`), tra bảng 30 phần tử `uint16_t` tại `.rodata 0x014f5c` và nhảy tới `0x007090 + offset * 4`.
3. **`0x006be0..0x007028` (`CityHash64` — `std::__ndk1::__murmur2_or_cityhash<uint64_t, 64>`)**:
   - Raw Hex @ `0x006f50`: `2b ad 85 d2 0b 67 bd f2 4a 01 0c aa 0b 41 dd f2 48 01 08 ca eb bb f3 f2` (`kMul = 0x9ddfea08eb382d69ULL`)
   - Raw Hex @ `0x006fd4`: `e0 09 88 d2 00 f2 a5 f2 60 47 cd f2 20 5c f3 f2 21 02 00 b4` (`k2 = 0x9ae16a3b2f90404fULL`)
4. **`0x00a994..0x00b80c` (6 Vòng Lặp Mở Rộng Vector NEON SIMD) & `0x00ff4c..0x0102ac` (4 Bộ Chuyển Đổi Pixel NEON)**:
   - Sử dụng `ushll`, `sshll`, `fcvtl`, `ldp q0, q1` / `stp q0, q1` và `ld3` / `ld4` / `st4` để chuyển đổi dữ liệu vector và điểm ảnh sang `RGBA8888`.
