# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libspeechepg.so`

- **Thư viện**: `libspeechepg.so` (`18,256 bytes`, 55 biểu tượng `.dynsym`: 34 imported + 18 exported)
- **Task ID**: `TASK-094-RECONSTRUCTION-LIBSPEECHEPG` (`TASK_SO_016`)
- **Trạng thái**: `VERIFIED_AND_ACCEPTED`

## 1. Đối chiếu 6 Cổng Kiểm Định (6 Verification Gates)
1. **Gate 1 (Dung lượng mã nguồn C++17 thực chất > 40KB)**: Đạt `> 100 KB` (8 tệp `.h`/`.cpp` trong `SOURCE/GIAI-MA/libspeechepg/`), `0` stub.
2. **Gate 2 (Khớp lệnh hợp ngữ AArch64)**: Đối chiếu toàn bộ `.text` (`0x001c80..0x003248`), `.plt` (`0x001a50..0x001c80`), `.data.rel.ro` (`0x007c10..0x007c40`) và `.bss` (`0x008000..0x008010`).
3. **Gate 3 (Chứng minh toán học)**:
   - Phép chia nguyên có dấu 2 byte/mẫu PCM16 tại `0x002f10..0x002f18` (`feedAudioToNative`) và `0x003000..0x00300c` (`processAudioToNative`): `cmp w22, #0; cinc w8, w22, lt; asr w2, w8, #1`.
   - Bộ lọc tiền nhấn âm (pre-emphasis $y[n] = x[n] - 0.97 x[n-1]$) và tính năng lượng RMS dBFS.
4. **Gate 4 (Bố cục ABI Struct)**:
   - `SpeechEngineHandler`: `24 bytes = 0x18` (`+0x00 Engine*`, `+0x08 SpeechPluginListener*`, `+0x10 Options*`).
   - `SpeechPluginListener`: `48 bytes = 0x30` (`+0x00 vptr = 0x007c28`, `+0x08 jclass`, `+0x10 jobject`, `+0x18 jmethodID`, `+0x20..+0x2f JniCallbackEnvironment`).
5. **Gate 5 (55 biểu tượng `.dynsym`)**: Phục hồi toàn bộ 34 hàm nhập `lab::speech::client::*` và 18 hàm xuất xưởng JNI (`[037]..[054]`).
6. **Gate 6 (Kiểm thử độc lập)**: `verify_libspeechepg` (6 bài kiểm thử tự động đạt 100% PASS).
