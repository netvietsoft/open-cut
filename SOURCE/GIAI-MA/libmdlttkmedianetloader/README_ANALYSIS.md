# Phân Tích & Tái Dựng Nhị Phân Hoàn Chỉnh — `libmdlttkmedianetloader.so`
# Complete Binary Analysis & Reconstruction — `libmdlttkmedianetloader.so`

---

## 1. Thông Tin Tổng Quan Nhị Phân (Binary Ground Truth Overview)

| Thuộc tính (Property) | Giá trị thực tế (Observed Binary Value) |
|---|---|
| **Tên thư viện (Library Name)** | `libmdlttkmedianetloader.so` |
| **Kích thước chuẩn (Exact Size)** | `83,560 bytes` (`0x14668` bytes) |
| **Kiến trúc (Architecture)** | ELF 64-bit LSB shared object, ARM aarch64 (`EM_AARCH64`) |
| **Số lượng phân đoạn (Section Count)** | `20` ELF64 sections |
| **Biểu tượng xuất (Exported Symbol)** | `1` hàm: `JNI_OnLoad` (`0x01008c`, kích thước `512 bytes`) |
| **Biểu tượng nhập (Imported Symbols)** | `121` biểu tượng trong `.dynsym` (`[003..123]`) + `111` mục `.rela.plt` |
| **Phụ thuộc thư viện (`DT_NEEDED`)** | `libavmdl_lite.so`, `libttkmediasdk.so`, `liblog.so`, `libm.so`, `libdl.so`, `libc.so` |

### Bố Cục Các Phân Đoạn ELF64 Chính (Primary ELF64 Sections)

| Section | Offset / VAddr | Kích thước (Size) | Ghi chú kỹ thuật (Technical Notes) |
|---|---|---|---|
| `.dynsym` | `0x000538` | `3,000 B` (`125` entries) | `121` imports (`avmdl_*`, `ttk::*`, `pthread_*`), `1` export (`JNI_OnLoad`) |
| `.rela.dyn` | `0x002690` | `8,448 B` (`352` entries) | Relocations cho 4 bảng VTable C++ và các hằng số hàm tạo/hủy |
| `.rela.plt` | `0x004790` | `2,664 B` (`111` entries) | Bảng nhảy PLT cho `libavmdl_lite.so`, `libttkmediasdk.so`, POSIX |
| `.plt` | `0x005200` | `1,808 B` | `0x005200..0x00590f` (`111` PLT stubs) |
| `.text` | `0x005910` | `43,440 B` | `0x005910..0x0102c0` — Toàn bộ mã máy AArch64 của 4 lớp C++ |
| `.rodata` | `0x0102c0` | `3,416 B` | `0x0102c0..0x011018` — Chuỗi log, khóa JSON, header HTTP, tên lớp RTTI |
| `.data.rel.ro` | `0x016dd0` | `2,920 B` | `0x016dd0..0x017938` — 4 bảng VTable (`_ZTV`) & cấu trúc `typeinfo` |
| `.got` | `0x017b78` | `1,160 B` | `0x017b78..0x018000` — Global Offset Table |
| `.bss` | `0x018000` | `136 B` | `0x018000..0x018088` — Các biến toàn cục Singleton & guard biến tĩnh |

---

## 2. Kiến Trúc 4 Lớp C++ Cốt Lõi & Bố Cục ABI (4 Core C++ Classes & ABI Layout)

Từ bảng `.data.rel.ro` (`0x016dd0..0x017938`) và các lệnh cấp phát `operator new` trong `.text`, thư viện triển khai 4 lớp C++ trong không gian tên `pandora::mdl`:

### 2.1. `pandora::mdl::MDLTTKMediaNetDetectDownloader` (`sizeof = 0x220 = 544 bytes`)
- **Cấp phát tại Factory**: `0x00db7c: mov w0, #0x220; bl operator new`
- **VTable tại `.data.rel.ro`**: `0x016dd0..0x016e68` (`15` khe ảo)
- **Chức năng**: Thực hiện dò tìm kết nối QUIC / TCP (`quicConnect` tại `0x005bec`) tới máy chủ CDN thông qua `ttk::QuicConnect::Create` và `StartQuicDetec`, tự động gán cổng mặc định `443` (`0x1bb`) nếu URL không chỉ định cổng, và xuất báo cáo JSON (`ip`, `port`, `rtt_ms`, `err_code`) qua `getStringValue`.

### 2.2. `pandora::mdl::MDLTTKMediaNetDownloader` (`sizeof = 0x22c8 = 8,904 bytes`)
- **Cấp phát tại Factory**: `0x00dac8: mov w0, #0x22c8; bl operator new`
- **VTable Đa kế thừa tại `.data.rel.ro`**: `0x016e90..0x017100`
  - **VTable Chính (`offset +0x00`)**: Kế thừa `pandora::mdl::MDLDownloader` (`24` khe ảo: `open`, `readData`, `close`, `cancel`, `getIntValue`, `getInt64Value`, `setIntValue`, `setInt64Value`, `getStringValue`, `setStringValue`, `setListener`, `setDataSource`, ...).
  - **VTable Phụ (`offset +0x2240`)**: Kế thừa `ttk::HttpDownloadCallback` (`12` khe ảo: `OnComplete`, `OnError`, `OnTimeout`, `OnCallToResponseHeader`, `OnDownloadProgress`, `OnCallToRedirect`, `OnSocketReuseInfo`, `OnSecurityVerify`, ...).
  - **Non-virtual thunks (`0x008074..0x00a2c0`)**: Dịch con trỏ `this` đi `-0x2240` bytes (`sub x0, x0, #2, lsl #12; sub x0, x0, #0x240`) để chuyển tiếp từ giao diện callback `ttk::HttpDownloadCallback` về đối tượng `MDLTTKMediaNetDownloader`.

### 2.3. `pandora::mdl::MDLTTKMediaNetLoaderFactory` (`sizeof = 0x28 = 40 bytes`)
- **Cấp phát Singleton (`0x00da2c`)**: `0x00da58: mov w0, #0x28; bl operator new`
- **VTable tại `.data.rel.ro`**: `0x017160..0x0171b0`
- **Chức năng**: Triển khai `pandora::mdl::MDLLoaderFactory`, đăng ký với `MDLDownloadManager` và khởi tạo các thể hiện của `MDLTTKMediaNetDownloader` (`0x22c8` B) và `MDLTTKMediaNetDetectDownloader` (`0x220` B).

### 2.4. `pandora::mdl::MDLTTKMediaNetLoaderStrategy` (`sizeof = 0x2b8 = 696 bytes`)
- **Cấp phát Singleton (`0x00de18`)**: `0x00de40: mov w0, #0x2b8; bl operator new`
- **VTable Đa kế thừa tại `.data.rel.ro`**: `0x0171d8..0x017300`
  - **VTable Chính (`offset +0x00`)**: Kế thừa `pandora::mdl::MDLLoaderStrategy`.
  - **VTable Phụ (`offset +0x220`)**: Kế thừa `ttk::QuicRaceCallback` (`OnQuicRaceResult` @ `0x00eca0`, thunk @ `0x00ef28` dịch `this - 0x220`).
- **Chức năng**: Quản lý khởi tạo lười (lazy init) của `ttk::MediaNetEngine`, phân tích cấu hình JSON từ tầng Java/KMP (`enable_quic_race`, `race_interval_min`, `max_concurrent`, `preconnect_num`, `enable_bbr`), điều phối đua kết nối QUIC/TCP (`startQuicRace` @ `0x00e950`), kết nối sớm (`preconnectUrl` @ `0x00e628`), và kiểm tra cửa sổ thời gian hết hạn đua QUIC (`0x00fcb8`).

---

## 3. Các Neo Opcode AArch64 & Công Thức Toán Học Cốt Lõi (Key Opcode & Mathematical Proofs)

1. **Dự phòng cổng mặc định HTTPS/QUIC (`443 = 0x1bb`) tại `0x005d50..0x005d5c` & `0x00e760..0x00e76c`**:
   - `0x005d50`: `1f050031` (`cmn w8, #1` — kiểm tra `port == -1`)
   - `0x005d54`: `61000054` (`b.ne #0x5d60`)
   - `0x005d58`: `68378052` (`mov w8, #0x1bb` — gán `443`)
   - `0x005d5c`: `e86700b9` (`str w8, [sp, #0x64]`)

2. **Kẹp không nhánh số byte tải xuống không âm (`max(0L, mCurrentOffset - mReqStartOffset)`) tại `0x007010..0x007014`**:
   - `0x007010`: `49010bcb` (`sub x9, x10, x11`)
   - `0x007014`: `21fda98a` (`bic x1, x9, x9, asr #63`)
   - Công thức toán học: $\max(0, \Delta) = \Delta \land \neg(\Delta \gg_{\text{arith}} 63)$.

3. **Kẹp kích thước đọc bộ đệm nảy 32 KB (`min(free_size, 0x8000)`) tại `0x0072ac..0x0072b4`**:
   - `0x0072ac`: `1f204071` (`cmp w0, #8, lsl #12` — so sánh với `32,768`)
   - `0x0072b0`: `09009052` (`mov w9, #0x8000`)
   - `0x0072b4`: `14b0891a` (`csel w20, w0, w9, lt`)

4. **Xác thực dải mã trạng thái HTTP 2xx (`status_code - 200 <= 99`) tại `0x007848..0x007854`**:
   - `0x007848`: `0a210351` (`sub w10, w8, #0xc8`)
   - `0x00784c`: `5f8d0171` (`cmp w10, #0x63`)
   - `0x007850`: `28a520b9` (`str w8, [x9, #0x20a4]`)
   - `0x007854`: `081e0054` (`b.hi #0x7c14`)

5. **Ánh xạ mã sự kiện Timeout (`timeout_code - 100009 <= 3`) tại `0x00858c..0x00859c`**:
   - `0x00858c`: `68ae8e52` (`mov w8, #0x7573`)
   - `0x008590`: `c8ffbf72` (`movk w8, #0xfffe, lsl #16` $\rightarrow -100009$)
   - `0x008594`: `2800080b` (`add w8, w1, w8`)
   - `0x008598`: `1f0d0071` (`cmp w8, #3`)

6. **Quy đổi Timeout từ giây sang mili-giây (`* 1000 = 0x3e8`) tại `0x009654..0x009668`**:
   - `0x009654`: `097d8052` (`mov w9, #0x3e8`)
   - `0x00965c`: `087d091b` (`mul w8, w8, w9`)

7. **Kiểm tra hết hạn cửa sổ đua QUIC (`(now_ms - last_race_ms) > mRaceIntervalMin * 60000`) tại `0x00fd2c..0x00fd38`**:
   - `0x00fd2c`: `0a4c9d52` (`mov w10, #0xea60` $\rightarrow 60,000\text{ ms/phút}$)
   - `0x00fd30`: `690214cb` (`sub x9, x19, x20`)
   - `0x00fd34`: `087d0a1b` (`mul w8, w8, w10`)
   - `0x00fd38`: `3fc128eb` (`cmp x9, w8, sxtw`)

---

## 4. Danh Mục Tệp Tái Dựng Trong `SOURCE/GIAI-MA/libmdlttkmedianetloader/`

| Tệp (File) | Vai trò (Role) |
|---|---|
| `mdlttkmedianetloader_types.h` | Định nghĩa hằng số khoá, mã lỗi, cấu trúc vòng đệm `AVMDLIOBuffer`, `ttk::HttpDownloadTask`, `ttk::QuicConnect`, `ttk::MediaNetEngine` |
| `mdlttkmedianetloader_detect_downloader.h` / `.cpp` | Lớp `MDLTTKMediaNetDetectDownloader` (`0x220` bytes) & dò tìm kết nối QUIC (`0x0059f0..0x0065c0`) |
| `mdlttkmedianetloader_downloader.h` / `.cpp` | Lớp `MDLTTKMediaNetDownloader` (`0x22c8` bytes), máy trạng thái tải HTTP/QUIC, bộ đệm nảy 32KB, xử lý header/redirect/timeout (`0x0065c8..0x00d9e0`) |
| `mdlttkmedianetloader_factory_strategy.h` / `.cpp` | Lớp `MDLTTKMediaNetLoaderFactory` (`0x28` B), `MDLTTKMediaNetLoaderStrategy` (`0x2b8` B), và `JNI_OnLoad` (`0x00da2c..0x01028c`) |
| `mdlttkmedianetloader_pseudocode.cpp` | Bộ tổng hợp tái dựng & kiểm thử tự động đầu-cuối (`runMdlTTKMediaNetLoaderSelfTest`) |
| `README_ANALYSIS.md` | Tài liệu phân tích kiến trúc, bảng VTable, neo opcode và ánh xạ hàm |
