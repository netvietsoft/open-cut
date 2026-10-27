# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libimagepipeline.so` (`TASK-128`)

## 1. Thông tin định danh nhị phân (Binary Identity — `OBSERVED`)
- **Thư viện đích**: `libimagepipeline.so` (Facebook Fresco ImagePipeline Native Engine + Statically Linked `libjpeg-turbo 1.5.3 build 20180808`)
- **Dung lượng chính xác**: `264,328 bytes` (`0x40888`)
- **SHA-256**: `38fed18184707429505cfabd7540d22f5560965d310b6501ae05a67a0f7d2266`
- **Tổng dung lượng C++17 tái dựng sạch**: `194,499 bytes` trên `9` file (`0 stub`, song ngữ Anh-Việt)
- **Số lượng lệnh AArch64 trích xuất đối chiếu**: `2517 lệnh` trên `20` vùng hàm cốt lõi (`.text 0x001ffc..0x037814`)

## 2. Đối chiếu `JNI_OnLoad` (`0x002060..0x00232c`) & 10 phương thức JNI (`.data 0x044000..0x0440f0`)
- `JNI_OnLoad` (`0x002060`) gọi `(*vm)->GetEnv(vm, &env, 0x00010006)`, lưu `GlobalRef` lớp `java/lang/RuntimeException` vào `.bss 0x044110`, nạp 4 `jmethodID` của `java/io/InputStream` (`read([B)I` @ `0x0440f0`, `skip(J)J` @ `0x0440f8`) và `java/io/OutputStream` (`write([B)V` @ `0x044100`, `write([BII)V` @ `0x044108`), sau đó đăng ký 4 lớp Java với 10 phương thức gốc:
  1. `com/facebook/imagepipeline/nativecode/NativeJpegTranscoder` (`.data 0x044000`, `registerJpegTranscoderMethods` @ `0x003530`):
     - `nativeTranscodeJpeg(Ljava/io/InputStream;Ljava/io/OutputStream;III)V` -> `0x0035b8`
     - `nativeTranscodeJpegWithExifOrientation(Ljava/io/InputStream;Ljava/io/OutputStream;III)V` -> `0x003664`
  2. `com/facebook/imagepipeline/nativecode/Bitmaps` (`.data 0x044030`, `registerBitmapsMethods` @ `0x03726c`):
     - `nativeCopyBitmap(Landroid/graphics/Bitmap;ILandroid/graphics/Bitmap;II)V` -> `0x0373b4`
  3. `com/facebook/imagepipeline/nativecode/DalvikPurgeableDecoder` (`.data 0x044048`, `registerDalvikPurgeableDecoderMethods` @ `0x037310`):
     - `nativePinBitmap(Landroid/graphics/Bitmap;)V` -> `0x037654`
  4. `com/facebook/imagepipeline/memory/NativeMemoryChunk` (`.data 0x044060`, `registerNativeMemoryChunkMethods` @ `0x0376c0`):
     - `nativeAllocate(I)J` -> `0x037764`
     - `nativeFree(J)V` -> `0x0377b0`
     - `nativeCopyToByteArray(J[BII)V` -> `0x0377b8`
     - `nativeCopyFromByteArray(J[BII)V` -> `0x0377d8`
     - `nativeMemcpy(JJI)V` -> `0x0377f8`
     - `nativeReadByte(J)B` -> `0x03780c`

## 3. Chứng minh toán học & Bố cục ABI (`OBSERVED`)
1. **Ánh xạ hướng EXIF & Nhóm nhị diện $D_4$ (`.rodata 0x037c00` & `.rodata 0x037b28`)**:
   - Bảng `.rodata 0x037c00`: `{0, 4, 2, 5, 6, 1, 7, 3}` ánh xạ thẻ EXIF `1..8` sang `FrescoRotationType`.
   - Bảng `.rodata 0x037b28`: `{5, 6, 7, 1, 2, 3, 4}` ánh xạ `FrescoRotationType 1..7` sang `JXFORM_CODE` (`JXFORM_ROT_90 = 5`, `JXFORM_ROT_180 = 6`, `JXFORM_ROT_270 = 7`, `JXFORM_FLIP_H = 1`, `JXFORM_FLIP_V = 2`, `JXFORM_TRANSPOSE = 3`, `JXFORM_TRANSVERSE = 4`).
2. **Biến đổi khối DCT $8\times 8$ không suy hao (`0x01984c..0x01ab28`)**:
   - Đảo chiều không gian $x \mapsto 7-x$ tương đương nhân hệ số tần số lẻ $v \in \{1,3,5,7\}$ với $-1$. Thỏa mãn $R_{90}^4 = I$, $R_{90}^2 = R_{180}$, $R_{90}^3 = R_{270}$ và $F_H^2 = F_V^2 = T^2 = V^2 = I$.
3. **Tỷ lệ lượng tử hóa IJG (`0x007ae4..0x007b20`) & Kích thước Struct ABI**:
   - $S(q) = \lfloor 5000 / q \rfloor$ với $q < 50$ và $S(q) = 200 - 2q$ với $q \ge 50$.
   - `sizeof(jpeg_compress_struct) == 0x248` (`584 B`, kiểm tra tại `0x00375c`), `sizeof(jpeg_decompress_struct) == 0x290` (`656 B`, kiểm tra tại `0x00b028`), `sizeof(jpeg_transform_info) == 0x60` (`96 B`, khởi tạo bằng 3 lệnh `stp q0, q0` tại `0x00287c..0x002884`).
