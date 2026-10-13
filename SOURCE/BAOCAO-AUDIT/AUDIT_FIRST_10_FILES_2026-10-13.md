# Kiểm tra 10 file native và mã giả đầu tiên / Initial native and pseudocode audit

- Task: `TASK-AUDIT-NATIVE-010`
- Ngày / Date: 2026-10-13
- Git HEAD: `665c026a860f5799cee88f9fbb55710ad5effea9`
- Phạm vi: 5 file `.so` arm64 và 5 file pseudocode tương ứng. Các header, metadata và script sinh file được đọc làm bằng chứng hỗ trợ; đây không phải kiểm toán toàn bộ repository.
- Scope: five arm64 binaries and their five paired pseudocode files. Supporting headers, manifests and generator code were inspected for provenance, not as a full repository audit.

## Kết luận / Verdict

**Chưa thể coi phần giải mã là đúng và hoàn chỉnh.** Cả 5 file C++ chỉ có 13 dòng, gồm constructor và destructor rỗng; tổng cộng 0 thân hàm thuật toán được phục hồi trong mẫu. Bốn binary có cấu trúc ELF hợp lệ trong các kiểm tra tĩnh đã chạy. `libcapcut.so` mang đầu file `7F 4B 4F 4D` (`KOM`), không phải ELF trực tiếp; chưa xác minh được nội dung sau giải đóng gói.

**The recovered source is incomplete.** All five C++ files contain only empty constructor/destructor scaffolding. Four binaries pass the performed ELF structural checks; the KOM-wrapped file requires separate unpacking validation.

## Danh sách đúng 10 file / Ten primary targets

Binary ở `SOURCE/extracted/lib/arm64-v8a/`; mã giả ở `SOURCE/GIAI-MA/<tên thư viện>/`.

| # binary / # C++ | Thư viện | Kích thước binary | Kết quả binary | File C++ | Kết quả C++ |
|---|---|---:|---|---|---|
| 1 / 2 | `libcapcut.so` | 2,342,912 bytes | KOM; không thể xác nhận bằng ELF parser | `libcapcut/capcut_pseudocode.cpp` | 13 dòng; 2 hàm rỗng |
| 3 / 4 | `libmiddle-bridge.so` | 60,762,576 bytes | ELF64, little-endian, AArch64, ET_DYN; đạt kiểm tra cấu trúc | `libmiddle-bridge/middle_bridge_pseudocode.cpp` | 13 dòng; 2 hàm rỗng |
| 5 / 6 | `libttffmpeg.so` | 5,771,392 bytes | ELF64, little-endian, AArch64, ET_DYN; đạt kiểm tra cấu trúc | `libttffmpeg/ttffmpeg_pseudocode.cpp` | 13 dòng; 2 hàm rỗng |
| 7 / 8 | `libnative-filters.so` | 34,824 bytes | ELF64, little-endian, AArch64, ET_DYN; đạt kiểm tra cấu trúc | `libnative-filters/native_filters_pseudocode.cpp` | 13 dòng; 2 hàm rỗng |
| 9 / 10 | `libtexturerender_native.so` | 67,480 bytes | ELF64, little-endian, AArch64, ET_DYN; đạt kiểm tra cấu trúc | `libtexturerender_native/texturerender_native_pseudocode.cpp` | 13 dòng; 2 hàm rỗng |

## Phát hiện / Findings

### 1. P1 — Mã giả chưa chứa thuật toán / No recovered algorithm bodies

**OBSERVED:** Trong mỗi file C++, dòng 5 là constructor và dòng 9 là destructor; cả hai chỉ chứa comment. Không có logic video, FFmpeg, filter hay texture. Ví dụ: [middle_bridge_pseudocode.cpp](../GIAI-MA/libmiddle-bridge/middle_bridge_pseudocode.cpp) và [capcut_pseudocode.cpp](../GIAI-MA/libcapcut/capcut_pseudocode.cpp).

Generator [orchestrator_daemon.py](../scripts/orchestrator_daemon.py), dòng 383–426, chủ động sinh các khung này từ tên thư viện. Đây là scaffolding tổng hợp, không phải bằng chứng đã phục hồi thuật toán từ machine code. / These are generated scaffolds, not recovered function implementations.

### 2. P1 — Nhãn hoàn thành 100% không đo chất lượng giải mã / Completion score measures file presence

**OBSERVED:** `verify_decompiled_code()` tại `SOURCE/scripts/orchestrator_daemon.py:262–292` cộng điểm khi có file symbols, JNI, strings, header và C++; gắn `COMPLETED` khi điểm >= 80. Không kiểm tra thân hàm, chữ ký, độ bao phủ hay tương đương hành vi. `sync_project_state()` dòng 539–543 dùng số thư mục được gắn nhãn này để tính phần trăm hoàn thành.

`SOURCE/BAOCAO/REPORT_TASK_SO_002_libcapcut.json` vẫn ghi `COMPLETED`, `completion_percentage: 100`, `acceptance_criteria_passed: true`, dù báo cáo có 0 symbols và source chỉ có khung rỗng. Kết quả mẫu này không ủng hộ tuyên bố đã giải mã đầy đủ. / A file-presence score cannot establish decompilation completeness.

### 3. P1 — Header JNI texture bỏ sót tham số / Texture JNI declarations omit an argument

**OBSERVED:** `SOURCE/GIAI-MA/libtexturerender_native/texturerender_native_interface.h` dòng 18, 19, 27 khai báo `nativeSetSurface`, `nativeGetHeight`, `nativeGetWidth` chỉ với `JNIEnv *env, jobject thiz`.

Disassembly trực tiếp binary cho thấy `nativeSetSurface` tại `0x24cc` dùng `x2` đầu vào tại `0x24dc`; `nativeGetWidth` tại `0x2580` và `nativeGetHeight` tại `0x2590` cũng dùng `x2` đầu vào. **INFERRED theo AArch64 ABI:** các khai báo thiếu ít nhất tham số thứ ba. Chưa xác định kiểu Java chính xác hoặc toàn bộ chữ ký. Generator dòng 400–401 khai báo chung mọi JNI là `void(JNIEnv*, jobject)`, không khôi phục kiểu tham số thực tế.

Không dùng các header này như hợp đồng ABI đã xác thực. / These headers are not validated ABI contracts.

### 4. Chưa kết luận file KOM hỏng / KOM is not evidence of download corruption

**OBSERVED:** `libcapcut.so` không có magic ELF; README tương ứng đã mô tả `Custom Packed`. Bản tại `extracted` và bản tại `apktool-res` có cùng hash. **INFERRED:** cần phân tích cơ chế đóng gói trước khi có thể kiểm tra code bên trong. Không đủ bằng chứng để gọi file này là hỏng hoặc đã giải mã thành công.

## Kiểm chứng đã thực hiện / Verification performed

- Bốn ELF: kiểm tra class, endian, machine, type, biên bảng program/section headers và biên các đoạn/section có dữ liệu trong file; không phát hiện cắt cụt qua các phép kiểm này.
- Cả 5 binary có cùng SHA-256 với bản cùng tên ở `SOURCE/apktool-res/lib/arm64-v8a/`.
- Manifest `symbols_demangled.json` của cả 4 ELF khớp toàn bộ tên, địa chỉ và kích thước symbol: middle-bridge 49,930; ttffmpeg 1,516; native-filters 19; texturerender 79. Phần trích xuất symbol có bằng chứng đúng; điều này không chứng minh đã phục hồi thân hàm. / Symbol extraction matches the binaries; function-body recovery remains absent.
- `git diff HEAD --stat` cho các binary và thư mục mã giả mục tiêu không có khác biệt. Lỗi thiếu logic tồn tại trong dữ liệu đã lưu ở commit; không phải thay đổi do lần kiểm tra này.
- Đọc toàn bộ 5 file pseudocode: mỗi file 13 dòng, 2 thân hàm rỗng, 0 thân hàm thuật toán.
- Đối chiếu generator, báo cáo, manifest và disassembly một số JNI texture; không thực thi binary.

## Giới hạn và bước tiếp / Limits and next steps

- Không có APK/APKS/XAPK gốc được Git theo dõi trong repository; các hash trùng chỉ chứng minh hai bản sao nội bộ giống nhau, không xác nhận độc lập nguồn gốc APK.
- Chưa giải đóng gói KOM, chưa build hoặc chạy native code, chưa kiểm tra tương đương hành vi với ứng dụng gốc.
- Không suy rộng kết quả 10 file sang toàn bộ 169 thư viện.
- Việc cần làm tiếp: đánh dấu các mẫu là scaffold/partial; khôi phục chữ ký JNI từ DEX/JNI registration và binary; giải mã từng thân hàm kèm địa chỉ và bằng chứng; xác thực bằng test hành vi trước khi gọi là hoàn chỉnh. Đây là đề xuất, chưa sửa source trong lần audit này.

No production source or binary was modified. Only audit documentation and required task records were updated.

## SHA-256 của binary đã kiểm tra / Audited binary hashes

| Binary | SHA-256 |
|---|---|
| libcapcut.so | `74f79987612952d55256a07f95e36fbd4ddebe3b19f308065f655b68cf1e198b` |
| libmiddle-bridge.so | `c8bdd53da98f1bc85ae23ac655230e9a589ca6f943a96e07cc6101fa5e6514f4` |
| libttffmpeg.so | `755c8dcac05951c52c53a3d3e02f0fe1c597b6cae3191622d3d9b220c8ba7fd9` |
| libnative-filters.so | `ba82438827b0afd86a0e107a22b6cf76b3f5753c116f6615e853f475e9945765` |
| libtexturerender_native.so | `a59ea786d06f2b5f0b4651e391593c8b3e69b69d93557ae591b46de378b75e88` |
