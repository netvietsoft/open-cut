# BÁO CÁO NGHIỆM THU TÁI DỰNG — `libbach-sdk-jni.so` (Target 71 / 169)

- **Mã báo cáo**: `REPORT_TASK_SO_133_libbach_sdk_jni` (`TASK-110-RECONSTRUCTION-LIBBACH_SDK_JNI`)
- **Thư viện mục tiêu**: `libbach-sdk-jni.so` (`117,112 bytes`, SHA-256: `6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929`)
- **Trạng thái nghiệm thu**: `VERIFIED_AND_ACCEPTED` (100% hoàn thành, `0 stubs`)

---

## 1. Tổng Quan Kiến Trúc & Phân Đoạn ELF64 (`[OBSERVED]`)

- **`.dynsym` (`0x0002c0, SZ=2712`)**: `113 symbols` (`92 imported [001..092]`, `17 exported JNI FUNC [093..112]`, `3 ABS`).
- **`.text` (`0x003820..0x013fdf, SZ=67520`)**: Toàn bộ thân hàm JNI của `BachAlgorithmSystem`, `BachBitmapHandle`, `DownloadableResourceFinder`, `EPResourceFinder`, `ModelDownloadListener`, `JNI_OnLoad`, `CityHash64`, `convertBachObjectToJava`, 6 vòng lặp mở rộng vector NEON và 4 hàm chuyển đổi định dạng pixel NEON.
- **`.rodata` (`0x014f5c..0x015aec, SZ=2961`)**: Bảng nhảy 30 nhánh `uint16_t` (`0x014f5c..0x014f97`), mảng 39 mã loại kết quả `int32_t` (`0x014f98..0x015033`), bảng nhảy 5 định dạng pixel (`0x015a01..0x015a05`), và toàn bộ chuỗi chữ ký JNI.
- **`.data.rel.ro` (`0x01f8a8..0x01fa2f, SZ=392`)**: 5 bảng phương thức ảo (`BachImageBuffer`, `BachMultiInput`, `BachBuffer`, `NativeListener`, `BachMap`).

---

## 2. Danh Sách Tệp Mã Nguồn C++17 Đã Tái Dựng (`SOURCE/GIAI-MA/libbach-sdk-jni/`)

1. `bach_sdk_jni_types.h`: Hình học ELF64, bảng hằng `.rodata`, kiểu toán học `AmazingEngine` (`RefBase`, `PrimitiveVector<T>`, `Vector2f..4f`, `Quaternionf`, `Matrix3x3f`, `Matrix4x4f`, `Rect`, `Color`), và các lớp lõi `Bach::BachObject` (`136 bytes`), `BachBuffer` (`56 bytes`), `BachMap` (`56 bytes`), `BachImageBuffer`, `BachMultiInput`, `BachAlgorithmOutput`, `BachAlgorithmSystem`.
2. `bach_object_converter.h` & `bach_object_converter.cpp`: Cài đặt `BachCityHash64` (`0x006be0..0x007028`), `ComputeLibcxxHashBucketIndex` (`0x005cc0..0x005cde`), `ConvertBachObjectToJava` (`0x00702c..0x00a980` với đầy đủ 30 nhánh), 6 vòng lặp mở rộng NEON (`0x00a994..0x00b80c`), 4 bộ chuyển đổi định dạng pixel NEON (`0x00ff4c..0x0102ac`) và `BachBitmapHandle_nativeGet` (`0x00eb38..0x00edcf`).
3. `bach_algorithm_system_jni.h` & `bach_algorithm_system_jni.cpp`: Cài đặt `.init_array[0]` (`0x003820..0x0038f4`), `BachAlgorithmSystemImpl`, `BachAlgorithmFactory`, `ToGeneralBuffer` và toàn bộ 9 hàm JNI của `BachAlgorithmSystem`.
4. `bach_resource_finder_jni.h` & `bach_resource_finder_jni.cpp`: Cài đặt `DownloadableResourceFinder`, `EPResourceFinder`, `NativeListener` (`32 bytes`), `JNI_OnLoad` (`0x0102b0`, trả về `0x00010006`) và các hàm chuyển đổi chuỗi UTF-8 (`0x010338..0x010504`).
5. `bach_sdk_jni_interface.h` & `bach_sdk_jni_pseudocode.cpp`: Giao diện tổng hợp 17 biểu tượng JNI xuất khẩu và bộ kiểm thử tất định toàn diện.
