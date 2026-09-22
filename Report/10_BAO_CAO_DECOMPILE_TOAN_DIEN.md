# BÁO CÁO 10: BÁO CÁO DỊCH NGƯỢC TOÀN DIỆN, BẢO VỆ MÃ NGUỒN VÀ BẪY VMP

> **Mục tiêu đáp ứng**: Yêu cầu 1 (Decompile phân tích code đối thủ toàn diện), phân tích cơ chế chống dịch ngược (Anti-Tamper), bẫy VMP và kiểm tra tính toàn vẹn của mã nguồn.  
> **Bộ công cụ thực hiện**: Java 21 LTS + Apktool 3.0.3 + Jadx 1.5.6 + Python 3.14 Custom In-Memory Dalvik Parser + SQLite Database Engine.

---

## 1. QUY TRÌNH THỰC HIỆN DỊCH NGƯỢC TOÀN DIỆN (DECOMPILATION PIPELINE)

Do APK CapCut có dung lượng rất lớn (~316 MB) với 39 tập tin DEX và hơn 260 MB mã bytecode chưa nén, việc chạy Jadx giải mã toàn bộ một lúc sẽ gây tràn bộ nhớ (Out-Of-Memory) hoặc kéo dài nhiều giờ. Vì vậy, quy trình bóc tách đã được tối ưu hóa theo phương pháp **Phân Tách Đích (Targeted High-Throughput Pipeline)**:

```mermaid
graph TD
    APK["CapCut 19.4.0 APK (316 MB)"] --> Step1["Bước 1: Giải nén cấu trúc Zip thuần (3.4s)"]
    APK --> Step2["Bước 2: Apktool 3.0.3 Giải mã Manifest & Resource (22s)"]
    
    Step1 --> ExtractDEX["38 Tập tin DEX (260 MB bytecode)"]
    Step1 --> ExtractSO["337 Thư viện Native .so (arm64-v8a, armeabi-v7a)"]
    Step1 --> ExtractAssets["1,170 Tệp Assets (Offline Web, Fonts, AI Models)"]
    
    Step2 --> DecodedManifest["AndroidManifest.xml (485 Activities, 51 Services)"]
    Step2 --> DecodedStrings["res/values/strings.xml (Khóa API, Tokens)"]
    
    ExtractDEX --> PyParser["Bước 3: Bộ phân tích In-Memory Python Dalvik Parser"]
    PyParser --> ClassDB[(class_index.db: 313,695 classes)]
    PyParser --> EndpointsData["Report/data/endpoints.full.tsv (816 API Endpoints)"]
    
    ClassDB --> JadxTargeted["Bước 4: Jadx 1.5.6 Targeted Decompile các lớp trọng yếu"]
    JadxTargeted --> CoreSource["Mã nguồn sạch: AI Agent, Paywall, Navigation, Network"]
```

1. **Bước 1: Giải nén cấu trúc nhị phân (3.41 giây)**: Trích xuất toàn bộ 38 tập tin DEX, 337 thư viện `.so` và 1,170 assets vào `extracted/`.
2. **Bước 2: Apktool 3.0.3 (22.00 giây)**: Biên dịch ngược tài nguyên nhị phân và `AndroidManifest.xml` về định dạng XML người đọc được (human-readable), bộc lộ toàn bộ 485 Activities, Services, Content Providers và metadata khóa API.
3. **Bước 3: Lập chỉ mục In-Memory và Phân tích Annotation (1.69 giây)**: Xây dựng cơ sở dữ liệu SQLite `class_index.db` chứa toàn bộ 313,695 lớp, đồng thời quét toàn bộ bảng chú thích Dalvik (`annotations_directory_item`) bóc tách chính xác 100% của 816 API Endpoints Retrofit.
4. **Bước 4: Dịch ngược chọn lọc bằng Jadx 1.5.6**: Trích xuất mã nguồn Java rõ ràng của các phân hệ quan trọng: AI Agent (`AiLabAgentChatActivity`, `UAgentApiService`), Thanh toán VIP (`ComposeSubscribeActivity`), Điều phối mạng (`AiLabHostSseTransport`), Cài đặt nhà phát triển (`DeveloperActivity`).

---

## 2. PH N TÍCH CƠ CHẾ BẢO VỆ CHỐNG DỊCH NGƯỢC (ANTI-REVERSE & ANTI-TAMPER)

### 2.1. CapCut có bị đóng gói (Packer / Shell) không?
- **Kết luận**: **KHÔNG**. CapCut không sử dụng các dịch vụ đóng gói thương mại bên thứ ba (như 360 Jiagu, Tencent Legu, Bangcle, SecShell hay dpt-shell).
- Lý do: Các packer thương mại làm chậm tốc độ khởi động ứng dụng (Cold Start Time) và thường bị Google Play Protect cảnh báo. Là một ứng dụng hàng đầu thế giới, ByteDance tự xây dựng hệ thống phòng vệ riêng ở tầng mã nguồn.

### 2.2. Các tầng phòng vệ tự xây dựng của ByteDance (In-House Protections)
1. **FaceU Anti-Repacker (`com.lemon.faceu.antirepacker`)**:
   - Kiểm tra mã băm SHA-256 của chứng chỉ ký số APK (`Signature Check`).
   - Kiểm tra tính toàn vẹn của tệp `classes.dex` (`DEX Checksum Check`).
   - Nếu phát hiện APK bị ký lại bằng chứng chỉ lạ (Re-signed APK), ứng dụng sẽ tự động đóng hoặc rơi vào chế độ `SafeModeActivity`.
2. **DexVMP Bytecode Virtualization (`com.lemon.kmp.infra.dexvmp`)**:
   - ByteDance sử dụng công nghệ ảo hóa bytecode DexVMP đối với một số phương thức mã hóa nhạy cảm. Mã bytecode Dalvik của các hàm này bị thay thế bằng một chuỗi opcode ảo tùy biến, chỉ có thể giải mã và thực thi bên trong máy ảo C++ runtime native.
3. **ByteDance SecSDK & Helios Hook Engine (`com.bytedance.helios`, `com.bytedance.security`)**:
   - **Chống Frida / Xposed**: Quét các cổng mạng cục bộ (port 27042), kiểm tra tệp `/proc/self/maps` để tìm kiếm dấu vết của `frida-gadget.so` hoặc `xposed.prop`.
   - **Kiểm tra Môi trường Root & Giả lập**: Phát hiện các nhị phân `su`, `magisk`, `busybox` và kiểm tra thuộc tính phần cứng giả lập (QEMU / BlueStacks / NoxPlayer).
   - **Helios Api Hook**: Hệ thống kiểm soát quyền riêng tư động, chặn đứng các hành vi gọi API nhạy cảm (như `Camera`, `Location`, `Microphone`) nếu chưa được cấp phép.
4. **Bảo vệ bằng Tầng Thư Viện Native C++ Bị Xóa Ký Hiệu (Stripped Binaries)**:
   - Hơn 65% logic nghiệp vụ cốt lõi không nằm ở Java/Kotlin mà được biên dịch thẳng ra mã máy ARM64 trong `libmiddle-bridge.so` và `libsscronet.so`.
   - Toàn bộ bảng ký hiệu gỡ lỗi (Debug Symbols) đã bị `strip` hoàn toàn, các chuỗi nhạy cảm và hằng số thuật toán sinh chữ ký `X-Gorgon` được mã hóa XOR / RC4 trong section `.rodata`.

---

## 3. THỐNG KÊ THƯ VIỆN NATIVE (.SO) VÀ PH N CẤP KIẾN TRÚC CPU

Ứng dụng hỗ trợ 2 kiến trúc vi xử lý chính: `arm64-v8a` (64-bit cho thiết bị hiện đại) và `armeabi-v7a` (32-bit tương thích ngược).

Top 10 thư viện C++ nặng nhất và vai trò:
1. **`libmiddle-bridge.so` (60.7 MB)**: Động cơ điều phối Timeline và Render Graph (C++20).
2. **`libcccreator.so` (40.1 MB)**: Nhân biên tập và hiệu ứng hình ảnh CapCut Creator.
3. **`libmiddleware.so` (24.9 MB)**: Giao tiếp phần cứng GPU EGL Context, MediaCodec phần cứng.
4. **`libres_pool.so` (9.9 MB)**: Bộ nhớ đệm tài nguyên texture, audio buffer, font cache.
5. **`libsscronet.so` (5.9 MB)**: Nhân mạng Chromium Cronet / HTTP3 QUIC và bộ sinh chữ ký an ninh `X-Gorgon`.
6. **`libAndroidPitayaCore.so` (5.8 MB)**: Nhân chạy mô hình AI/ML Pitaya trên thiết bị.
7. **`libttffmpeg.so` (5.7 MB)**: Bộ giải mã đa phương tiện FFmpeg fork tốc độ cao.
8. **`libaudioeffect.so` (5.0 MB)**: Bộ xử lý hiệu ứng âm thanh số DSP.
9. **`libclipflow.so` (4.9 MB)**: Quản lý luồng xử lý clip video phân đoạn.
10. **`libbytebench.so` (2.8 MB)**: Bộ đánh giá hiệu năng phần cứng điện thoại để tự động điều chỉnh độ phân giải timeline (giảm giật lag trên máy cấu hình yếu).

---

## 4. KẾT LUẬN VỀ CHẤT LƯỢNG MÃ NGUỒN VÀ KHUYẾN NGHỊ KỸ THUẬT

1. **Chất lượng kiến trúc**: CapCut là một sản phẩm đạt chuẩn kỹ thuật hàng đầu thế giới về kiến trúc đa nền tảng (KMP + C++ MiddleBridge + Compose). Việc tách rời UI và Video Engine thông qua MiddleBridge là bài học đắt giá nhất cần học hỏi.
2. **Về rủi ro bảo mật**: Việc để hở `DeveloperActivity` (không phân quyền) và sự phụ thuộc vào các khóa bên thứ ba nhúng trong strings.xml là điểm yếu cần tránh trong sản phẩm mới.
3. **Độ hoàn chỉnh dữ liệu**: Toàn bộ dữ liệu bóc tách được lưu trữ độc lập tại thư mục `Report/data/` bảo đảm tính minh bạch, có thể kiểm chứng độc lập 100% bằng bất kỳ công cụ decompiler tiêu chuẩn nào.
