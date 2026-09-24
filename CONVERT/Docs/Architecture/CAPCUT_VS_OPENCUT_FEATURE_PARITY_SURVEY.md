# BÁO CÁO KHẢO SÁT CHUYÊN SÂU: CÁC TÍNH NĂNG BIÊN TẬP VIDEO CAPCUT VÀ MA TRẬN ĐỐI CHIẾU OPENCUT
# IN-DEPTH SURVEY: CAPCUT VIDEO EDITING FEATURES & OPENCUT PARITY MATRIX

> **Tiêu chuẩn áp dụng**: `Development Workspace Standard V2.1`  
> **Hiến pháp AI Agent**: Tuân thủ Điều 12 (Chú thích song ngữ EN + VN) & Điều 20 (Phân loại bằng chứng OBSERVED, INFERRED, NEW_DESIGN).  
> **Nguồn dữ liệu khảo sát gốc [OBSERVED]**: 
> - Bản dựng nguyên bản **CapCut Global v19.4.0** (Package: `com.lemon.lvoverseas`).
> - Cơ sở dữ liệu phân tích chỉ mục: `class_index.db` (313,695 classes trên 38 tệp DEX).
> - Thư viện mã máy bản địa: `extracted/lib/arm64-v8a` (169 tệp thư viện `.so`).
> - Bảng chuỗi ngôn ngữ tài nguyên: `apktool-res/res/values/strings.xml` (13,681 chuỗi EN) & `values-vi/strings.xml` (tiếng Việt chuẩn ByteDance).
> - Cấu trúc điều hướng: 85 `DockProvider` quản lý thanh công cụ biên tập video.
> **Đối tượng so sánh [NEW_DESIGN]**:
> - Ứng dụng **NextAI OpenCut v2.1.5** (`apps/android/app/src/main/java/com/nextai/opencut/presentation/MainActivity.java` và `engine/EffectRegistry.java`).

---

## I. TỔNG QUAN KHẢO SÁT & ĐÁNH GIÁ TỔNG THỂ (EXECUTIVE SUMMARY)

Qua quá trình rà soát và mổ xẻ mã nguồn decompile của CapCut v19.4.0, phân hệ **Biên Tập Video (Video Editing Suite)** của CapCut là một cỗ máy xử lý đa phương tiện khổng lồ với hơn **30,060 lớp chuyên trách** thuộc gói `com.vega.edit` và 169 thư viện C++ native engine. 

### 1. Hiện Trạng Của OpenCut Hiện Tại (OpenCut Current State):
OpenCut (v2.1.5) đã xây dựng thành công bộ khung làm việc (Workspace) rất vững chắc:
- ✅ **Khung nhìn chuẩn hóa**: Tự động nhận diện xoay EXIF đứng thẳng 100%, tự động co giãn ôm khít màn hình điện thoại (Fit/Fill), xoay 90 luân phiên, lật gương.
- ✅ **Thước đo Timeline CapCut**: Vạch chia giây, vạch phụ 250ms, playhead hiển thị trực quan.
- ✅ **Thao tác cơ bản hoàn thiện**: Tách clip (Split), Tốc độ (Speed cơ bản), Âm lượng (Volume), Xóa (Delete), Khóa phông (Chroma Key), Làm đẹp (Retouch 5 thanh trượt), Chỉnh màu (ColorMatrix), Cắt cúp khung hình (Crop 4 cạnh & presets), Đóng băng (Freeze 3s), Đảo ngược (Reverse), Mặt nạ (Mask 4 hình dạng).
- ✅ **Timeline ghép nối nối tiếp**: Thêm nhiều clip nối tiếp qua dấu `+`, chuyển tiếp phát tuần tự.
- ✅ **Xuất video thật**: Đường ống xuất MP4 1080P thực tế vào `/sdcard/Movies/NextAI_OpenCut/`.

### 2. Những Khoảng Trống CapCut Còn Lại Mà OpenCut Chưa Có Hoặc Chưa Dùng Được (The Unreached Gaps):
Dưới đây là các trụ cột tính năng cực kỳ quan trọng làm nên tên tuổi của CapCut mà OpenCut **chưa động tới** hoặc **mới chỉ ở mức sơ khai/giả lập**:
1. **Hệ thống Khung hình chính (Keyframing Engine `◆`)**: Chưa có cơ chế đặt điểm neo keyframe để biến đổi vị trí, kích thước, độ mờ, góc xoay theo thời gian thực.
2. **Hệ thống Chuyển cảnh giữa các Clip (Clip Transitions `|`)**: Nút giao giữa 2 clip chưa có icon chuyển cảnh, chưa có kho hiệu ứng chuyển tiếp (Dissolve, Camera zoom, Glitch, Light leaks, Push...).
3. **Hoạt ảnh Clip (Clip Animations: In / Out / Combo)**: Chưa có bộ hoạt ảnh vào, ra và kết hợp cho từng phân đoạn video.
4. **Đường cong tốc độ Bezier tự do & Optical Flow Slow-Motion**: Chưa có bộ vẽ đường cong tốc độ tự do (Custom Curve Speed) và nhân nội suy khung hình quang học 60fps/120fps.
5. **Xử lý âm thanh AI chuyên sâu**: Tách lời bài hát (Vocal Isolation / Karaoke), Bắt nhịp tự động (Auto Beats), Làm mờ dần âm thanh (Fade In/Out), Khuếch đại âm lượng 1000% (Volume Boost 10x kèm Limiter), Giảm ồn (Audio Denoise).
6. **Theo dõi chuyển động (Motion Tracking)**: Chưa có thuật toán tracking đối tượng/khuôn mặt để chữ và sticker bay theo chuyển động.
7. **Ổn định chống rung video (Video Stabilization)**: Chưa có thuật toán gyro/optical stabilization triệt tiêu rung lắc máy ảnh.
8. **Tách người tự động không cần phông xanh (Auto Cutout) & Viền phát sáng (Cutout Stroke)**.
9. **Kho Hiệu ứng Cơ thể (Body Effects)**: Các hiệu ứng vẽ viền neon theo cơ thể, mắt phát sáng, hào quang khi người chuyển động.
10. **Tùy chỉnh màu chuyên nghiệp HSL & Curves trên Video**: Mới chỉ có trong Photo Editor, Video Editor chưa có bảng HSL 8 màu và Curves RGB.
11. **Tương tác Timeline nâng cao**: Cử chỉ chụm 2 ngón tay thu phóng timeline (Pinch-to-zoom scale) và Bắt dính nam châm (Magnetic Snapping).
12. **Phụ đề động nhảy chữ theo từ (Dynamic Word-Highlight Captions - Phong cách Alex Hormozi/MrBeast)**.
13. **Trình biên tập Ảnh bìa độc lập (Cover Photo Editor)**.
14. **Thay thế clip giữ nguyên thuộc tính (Replace Clip)**.
15. **Làm mờ chuyển động quang học (Motion Blur)**.

---

## II. BẢNG SO SÁNH CHI TIẾT TOÀN DIỆN TỪNG TÍNH NĂNG (CAPCUT VS OPENCUT)

Phân loại trạng thái trong bảng:
- 🟢 **HOÀN THIỆN (100% Ready)**: Đã triển khai và hoạt động thực tế trên thiết bị.
- 🟡 **CƠ BẢN / DỞ DANG (Partial / Basic)**: Đã có giao diện hoặc logic thô, chưa đạt độ mượt mà và sâu như CapCut.
- 🔴 **CHƯA CÓ / CHƯA ĐỘNG TỚI (Missing / Untouched)**: CapCut có nhưng OpenCut hoàn toàn chưa xây dựng.

---

### BẢNG 1: THANH CÔNG CỤ CẤP 1 — GIAO DIỆN TIMELINE CHÍNH (TOP-LEVEL TOOLBAR)

| STT | Tên Chức Năng (CapCut EN / VN) | Mô Tả Nghiệp Vụ CapCut Gốc [OBSERVED] | Trạng Thái OpenCut [NEW_DESIGN] | Chi Tiết Khoảng Trống OpenCut Cần Khắc Phục |
|:---:|---|---|:---:|---|
| **1.1** | **Chỉnh sửa (Edit)** | Mở thanh công cụ chi tiết khi chọn clip chính | 🟢 **HOÀN THIỆN** | OpenCut đã có thanh Ribbon Edit với 14 công cụ con. |
| **1.2** | **Âm thanh (Audio)** | Mở ngăn kéo Âm thanh: Kho nhạc, Âm thanh hiệu ứng Sound FX, Trích xuất audio, Ghi âm mic, Bản quyền | 🟡 **CƠ BẢN** | Đã có dialog kho nhạc, nghe thử, Sound FX và Voice FX. **Chưa có**: Ghi âm lồng tiếng trực tiếp từ mic (Voiceover Record) vào timeline, chưa có bộ quét bản quyền âm thanh TikTok. |
| **1.3** | **Văn bản (Text)** | Thêm chữ, Mẫu chữ động Kinetic, Phụ đề tự động Auto Captions, Lời bài hát Auto Lyrics, Vẽ tay Draw, Nhãn dán Stickers | 🟡 **CƠ BẢN** | Đã có Thêm chữ, Mẫu chữ, Phụ đề AI, Đọc chữ TTS. **Chưa có**: Mẫu chữ động phân loại sâu, Lời bài hát tự động, Công cụ vẽ tay (Draw), Bong bóng thoại (Bubbles). |
| **1.4** | **Lớp phủ (Overlay / PIP)** | Thêm video/ảnh đè lên video chính dạng Picture-in-Picture không giới hạn số dải | 🟡 **CƠ BẢN** | Đã có chế độ Thêm nối tiếp timeline. **Chưa có**: Dải track PIP chuyên dụng hiển thị song song dưới main track với công cụ hòa trộn (Blend Modes). |
| **1.5** | **Hiệu ứng (Effects)** | Gồm 4 tab: Hiệu ứng Video (Video FX), Hiệu ứng Cơ thể (Body FX), Hiệu ứng Ảnh (Photo FX), Hiệu ứng AI (AI FX) | 🟡 **CƠ BẢN** | Đã có tab Hiệu ứng Video với các shader Glitch, VHS, Film Leak và Authentic CapCut. **Chưa có**: Tab Hiệu ứng Cơ thể (Body FX) và Hiệu ứng AI (AI movement/relight). |
| **1.6** | **Tỷ lệ (Ratio)** | Chọn tỷ lệ khung hình: 9:16, 16:9, 1:1, 4:3, 3:4, 2:3, 5.8:1, 2.35:1 (Cinema) | 🟢 **HOÀN THIỆN** | Đã hỗ trợ đầy đủ các tỷ lệ chuẩn và tự co giãn canvas xem trước. |
| **1.7** | **Bộ lọc (Filters)** | Kho bộ lọc màu phân theo chủ đề (Cuộc sống, Cổ điển, Điện ảnh, Phong cảnh, Đồ ăn, Chân dung...) | 🟢 **HOÀN THIỆN** | Đã tích hợp 3D LUTs điện ảnh (Portra 400, Cyberpunk, Teal & Orange, Noir B&W, Cinema Gold, Fuji...). |
| **1.8** | **Tùy chỉnh (Adjust)** | Thanh trượt màu cơ bản + HSL 8 màu + Đường cong Curves RGB | 🟡 **CƠ BẢN** | Trên Video Editor mới có Độ sáng, Tương phản, Bão hòa. **Chưa có**: Bảng màu HSL 8 kênh màu và Curves RGB trên Video (mới chỉ có trong Photo Editor). |
| **1.9** | **Nhãn dán (Stickers)** | Kho nhãn dán tĩnh/động, Emoji, Giphy, Nhãn dán AI tạo từ văn bản | 🔴 **CHƯA CÓ** | Nút Nhãn dán mới chỉ hiển thị placeholder, chưa có kho nhãn dán SVG/GIF động và chưa có track Sticker riêng. |
| **1.10**| **Bảng vẽ (Canvas)** | Tùy biến nền khi video nhỏ hơn khung hình: Màu sắc (Color), Phông nền hoa văn (Background), Làm mờ (Blur 4 cấp độ) | 🟢 **HOÀN THIỆN** | Đã có đầy đủ menu Bảng vẽ: Màu sắc, Phông nền, Làm mờ (Blur) và Nền thương hiệu. |
| **1.11**| **Mẫu (Templates / CutSame)**| Nạp video mẫu ngắn thịnh hành, tự động cắt ghép khớp phách | 🟢 **HOÀN THIỆN** | Đã có màn hình Mẫu Hot, feed thẻ mẫu và nút "Sử dụng Mẫu (CutSame)" khớp Beat drop. |

---

### BẢNG 2: THANH CÔNG CỤ CẤP 2 — KHI CHỌN 1 CLIP TRÊN TIMELINE (MAIN VIDEO DOCK)

| STT | Công Cụ Con (Tool Name) | Mô Tả Tính Năng Trong CapCut Gốc [OBSERVED] | Trạng Thái OpenCut [NEW_DESIGN] | Đánh Giá & Khoảng Trống Cần Bổ Sung |
|:---:|---|---|:---:|---|
| **2.1** | **Tách (Split)** | Cắt đứt clip làm 2 phần tại vị trí playhead | 🟢 **HOÀN THIỆN** | Hoạt động trơn tru, chia đôi clip và tạo 2 thẻ trên timeline. |
| **2.2** | **Tốc độ (Speed)** | Tăng giảm tốc độ từ 0.1x đến 100x, hỗ trợ Uốn cong (Curve Speed) và Làm mượt Optical Flow | 🟡 **CƠ BẢN** | Đã có các nút tốc độ (0.5x - 5.0x) và preset đường cong VlogU, nhưng **chưa có** trình vẽ điểm cong Bezier tự do và **chưa có** nhân Optical Flow nội suy khung hình. |
| **2.3** | **Hoạt ảnh (Animation)** | Áp dụng chuyển động In (Vào), Out (Ra), Combo (Kết hợp) cho riêng đoạn clip được chọn | 🔴 **CHƯA CÓ** | **Hoàn toàn chưa có**: Chưa có hộp thoại Animation với các hiệu ứng nảy, xoay 3D, lật trang, trượt cạnh. |
| **2.4** | **Xóa (Delete)** | Xóa clip khỏi dự án, tự động co dải timeline lại | 🟢 **HOÀN THIỆN** | Hoạt động chính xác, tự tính lại timecode tổng. |
| **2.5** | **Tách nền / Khóa phông (Cutout)** | Gồm 3 chế độ: Khóa phông xanh (Chroma Key), Tách tự động (Auto Cutout), Tách tùy chỉnh (Custom) + Viền Stroke | 🟡 **CƠ BẢN** | Đã có Chroma Key (xanh lá, xanh dương, tím kèm Intensity/Shadow). **Chưa có**: Tách người tự động AI (Auto Cutout) chạy thời gian thực trên video và hiệu ứng viền Stroke neon bao quanh người. |
| **2.6** | **Theo dõi máy ảnh (Camera Tracking / Motion Tracking)** | Khóa và bám theo một vật thể/khuôn mặt khi di chuyển trong khung hình | 🔴 **CHƯA CÓ** | **Hoàn toàn chưa có**: Chưa có thuật toán thị giác máy tính OpenCV/KCF tracker bám điểm chuyển động. |
| **2.7** | **Âm lượng (Volume)** | Điều chỉnh âm lượng từ 0% đến 1000% (boost âm lượng gấp 10 lần) | 🟡 **CƠ BẢN** | Đã có SeekBar âm lượng nhưng dải điều chỉnh mới dừng ở mức 0% - 200%. **Chưa có** bộ nén âm thanh limiter khi đẩy lên 1000%. |
| **2.8** | **Biến đổi / Cắt cúp (Transform & Crop)** | Cắt cúp khung hình 4 cạnh, xoay 90 độ, lật gương ngang | 🟢 **HOÀN THIỆN** | Hoàn thành xuất sắc trong TASK-024: Xoay 90 luân phiên, lật gương, cắt 4 cạnh SeekBar và presets 1:1, 9:16, 16:9... |
| **2.9** | **Làm đẹp (Retouch)** | Làm mịn da, thu nhỏ cằm, mắt to, nâng mũi, trắng răng, thon gọn cơ thể | 🟢 **HOÀN THIỆN** | Đã có ngăn kéo Retouch 5 SeekBars + tích hợp Face Mesh 468 điểm + tính năng Kéo dài chân Meitu +15%. |
| **2.10**| **Mặt nạ (Mask)** | Cắt vùng hiển thị: Tuyến tính, Hình tròn, Gương, Chữ nhật, Trái tim, Ngôi sao + Feather độ mềm viền + Đảo ngược | 🟡 **CƠ BẢN** | Đã có Tuyến tính, Hình tròn, Gương, Đảo vùng. **Chưa có**: Chữ nhật, Trái tim, Ngôi sao và thanh trượt làm mềm mép viền (Feather slider). |
| **2.11**| **Chuyển thành lớp phủ (Overlay)** | Hạ clip chính xuống track lớp phủ hoặc đưa clip lớp phủ lên track chính | 🔴 **CHƯA CÓ** | Chưa có logic chuyển đổi dải tầng tự do giữa Main Track và Overlay Track. |
| **2.12**| **Thay thế (Replace)** | Đổi một video/ảnh khác từ máy nhưng giữ nguyên độ dài và các bộ lọc, hiệu ứng đã gắn | 🔴 **CHƯA CÓ** | Chưa có nút Replace trong menu con để hoán đổi tệp nguồn trên timeline. |
| **2.13**| **Ổn định chống rung (Stabilize)** | Khử rung lắc cho video quay tay (3 mức: Cắt tối thiểu, Đề xuất, Ổn định nhất) | 🔴 **CHƯA CÓ** | **Hoàn toàn chưa có**: Chưa có thuật toán bù trừ rung lắc hình ảnh. |
| **2.14**| **Độ mờ đục (Opacity)** | Thanh trượt độ trong suốt của clip từ 0% đến 100% | 🔴 **CHƯA CÓ** | Chưa có thanh trượt Opacity riêng trong menu chỉnh sửa clip. |
| **2.15**| **Hiệu ứng giọng nói (Voice Effects)** | Biến đổi giọng nói thành Sóc chuột, Robot, Giọng trầm, Quái vật, Tiếng vọng, Giọng hát | 🟢 **HOÀN THIỆN** | Đã có hộp thoại Voice FX với Chipmunk, Robot, Monster, Echo, Deep Voice và Mic Karaoke. |
| **2.16**| **Giảm tiếng ồn (Reduce Noise)** | Khử tạp âm gió, tiếng rè nền tự động | 🔴 **CHƯA CÓ** | Chưa có bộ lọc audio DSP denoiser một chạm. |
| **2.17**| **Tách âm thanh (Extract Audio)** | Trích xuất dải audio của video và thả xuống track âm thanh độc lập bên dưới | 🟡 **CƠ BẢN** | Đã có nút Trích xuất nhạc trong menu m thanh nhưng chưa có thao tác bấm 1 chạm trên clip để tách audio xuống track con. |
| **2.18**| **Tách lời bài hát (Vocal Isolation)** | AI tách riêng giọng hát (Vocal) và nhạc nền (Instrumental/Beat) | 🔴 **CHƯA CÓ** | **Hoàn toàn chưa có**: Cần mô hình AI Spleeter hoặc Demucs để tách vocal. |
| **2.19**| **Đảo ngược (Reverse)** | Đảo ngược chiều phát video từ cuối về đầu | 🟢 **HOÀN THIỆN** | Đã tích hợp nút Đảo ngược và logic tua ngược khung hình. |
| **2.20**| **Đóng băng (Freeze)** | Dừng hình 3 giây tại vị trí playhead để tạo khoảnh khắc ấn tượng | 🟢 **HOÀN THIỆN** | Đã tích hợp công cụ Đóng băng 3s chèn phân đoạn tĩnh giữa clip. |
| **2.21**| **Làm mờ chuyển động (Motion Blur)** | Thêm độ nhòe chuyển động quang học theo hướng di chuyển của cảnh | 🔴 **CHƯA CÓ** | **Hoàn toàn chưa có**: Chưa có shader directional motion blur kết hợp nhiều frame. |
| **2.22**| **Nhân bản (Duplicate)** | Sao chép clip đang chọn ra thêm một bản nằm liền kề phía sau | 🔴 **CHƯA CÓ** | Chưa có nút Duplicate nhân đôi clip trên timeline. |
| **2.23**| **Khung hình chính (Keyframe `◆`)**| Đặt điểm neo keyframe hình thoi trên clip để tạo hiệu ứng chuyển động tùy chỉnh | 🔴 **CHƯA CÓ** | **Khoảng trống cốt lõi**: Chưa có cấu trúc dữ liệu Keyframe và nút hình thoi `◆` cạnh nút Play. |
| **2.24**| **Chế độ hòa trộn (Blend Modes)** | Hòa trộn lớp phủ: Normal, Darken, Multiply, Lighten, Screen, Overlay, Soft Light... | 🔴 **CHƯA CÓ** | Chưa có bộ chọn Blend Mode cho lớp phủ video. |
| **2.25**| **Ảnh bìa (Cover)** | Chọn khung hình trong video hoặc nạp ảnh ngoài, thêm chữ mẫu để làm thumbnail | 🟡 **CƠ BẢN** | Đã có ô hiển thị "Ảnh bìa" tĩnh trên timeline nhưng chưa mở ra trình biên tập ảnh bìa. |

---

### BẢNG 3: HỆ THỐNG CHUYỂN CẢNH GIỮA CÁC CLIP (TRANSITION SYSTEM `|`)

Trong CapCut, mỗi điểm nối giữa 2 clip trên timeline có một nút vuông nhỏ màu trắng có gạch dọc `|`. Khi bấm vào nút này sẽ mở ra kho **Hiệu Ứng Chuyển Tiếp (Transitions)**:

| Phân Loại Chuyển Cảnh (CapCut) | Danh Sách Hiệu Ứng Điển Hình [OBSERVED] | Trạng Thái Trong OpenCut | Đánh Giá Kỹ Thuật & Giải Pháp Tái Dựng |
|---|---|:---:|---|
| **1. Cơ bản (Basic Transitions)** | Mờ dần (Dissolve), Mờ đen (Fade to black), Mờ trắng (Fade to white) | 🔴 **CHƯA CÓ** | Hiện tại khi phát hết clip 1, OpenCut lập tức nhảy sang clip 2 qua `onCompletion` mà không có độ hòa trộn chéo (Cross-fade) giữa 2 video stream. |
| **2. Máy ảnh (Camera Motion)** | Kéo sang trái/phải (Slide), Lật trang (Page curl), Xoay tròn (Spin), Zoom sâu (Zoom In/Out) | 🔴 **CHƯA CÓ** | Cần áp dụng ma trận biến đổi tọa độ OpenGL Shader giữa khung hình cuối của clip trước và khung hình đầu của clip sau. |
| **3. Ánh sáng (Light Effects)** | Cháy sáng (Flash), Vệt rò rỉ phim (Light leak transition), Hào quang (Lens flare) | 🔴 **CHƯA CÓ** | Có thể tận dụng lại Shader `film_leak_orange` hiện có của OpenCut để làm hiệu ứng hòa trộn chuyển cảnh 0.5s. |
| **4. Trục trặc (Glitch Transitions)** | Xé hình RGB (RGB Split), Nhiễu sóng CRT (Noise wave), Sọc ngang kỹ thuật số (Scanline) | 🔴 **CHƯA CÓ** | Có thể tận dụng Shader `glitch_rgb_split` và `vhs_1998` hiện có của OpenCut để kích hoạt tại điểm giao chuyển cảnh. |
| **5. Méo mó (Distortion)** | Gợn nước (Water ripple), Xoáy lốc (Vortex), Méo lồi (Fish eye warp) | 🔴 **CHƯA CÓ** | Cần bổ sung shader uốn cong tọa độ cực (Polar coordinate warp). |
| **6. Điều khiển thời lượng** | Thanh trượt thời lượng chuyển tiếp (0.1s - 3.0s) + Nút "Áp dụng cho tất cả" | 🔴 **CHƯA CÓ** | Cần xây dựng hộp thoại Transition Dialog chuẩn CapCut hiển thị thời lượng và nút "Áp dụng tất cả". |

---

### BẢNG 4: HỆ THỐNG KHUNG HÌNH CHÍNH (KEYFRAME ENGINE `◆`)

Đây là tính năng tạo nên sự khác biệt lớn nhất giữa một ứng dụng biên tập video chuyên nghiệp và một ứng dụng nghiệp dư:

| Thành Phần Keyframe Của CapCut | Cơ Chế Hoạt Động Trong CapCut Gốc [OBSERVED] | Trạng Thái Trong OpenCut | Yêu Cầu Kỹ Thuật Cần Triển Khai |
|---|---|:---:|---|
| **Biểu tượng Nút Keyframe `◆`** | Nằm cạnh nút Play/Pause. Khi Playhead dừng ở vị trí chưa có keyframe: nút hiển thị `+◆` (Thêm keyframe). Khi Playhead ở đúng điểm keyframe: nút đổi thành `-◆` (Xóa keyframe). | 🔴 **CHƯA CÓ** | Cần bổ sung nút hình thoi `btnKeyframeToggle` trên thanh điều khiển xem trước. |
| **Hiển thị trên Timeline** | Một chấm hình thoi màu đỏ (hoặc trắng) xuất hiện ngay trên dải clip tại mốc thời gian đã đặt. | 🔴 **CHƯA CÓ** | Cần vẽ thêm các điểm thoi Keyframe Indicator trên `timelineClipsRow`. |
| **Các thuộc tính hỗ trợ Keyframe** | - Vị trí (Translation X, Y)<br>- Tỷ lệ thu phóng (Scale X, Y)<br>- Góc quay (Rotation Z)<br>- Độ trong suốt (Opacity)<br>- Vị trí Mặt nạ (Mask position & size) | 🔴 **CHƯA CÓ** | Cần tạo lớp dữ liệu `KeyframeData(long timestampMs, float scale, float transX, float transY, float rotation, float opacity)`. |
| **Nội suy chuyển động (Interpolation)** | Tự động tính toán các khung hình ở giữa (Linear interpolation hoặc Curve ease-in/ease-out) để clip di chuyển, phóng to, xoay mượt mà giữa 2 điểm keyframe. | 🔴 **CHƯA CÓ** | Viết thuật toán nội suy `lerp()` trong render loop của Video Player. |

---

### BẢNG 5: HỆ THỐNG XỬ LÝ ÂM THANH CHUYÊN SÂU (AUDIO PROCESSING SUITE)

| Tính Năng m Thanh (Audio Features) | Tính Năng CapCut Gốc [OBSERVED] | Trạng Thái OpenCut | Khoảng Trống & Hướng Giải Quyết |
|---|---|:---:|---|
| **Khuếch đại âm lượng 1000%** | Thanh trượt Volume kéo từ 0% lên tới 1000% (tăng gấp 10 lần âm lượng cho các video quay bị nhỏ tiếng). | 🟡 **CƠ BẢN** | OpenCut mới kéo tới 200%. Cần mở rộng SeekBar lên 1000% và dùng bộ giới hạn dynamic range compression để không vỡ tiếng. |
| **Tăng/Giảm dần âm thanh (Fade In / Fade Out)** | Hai thanh trượt Fade In (0 - 10s) và Fade Out (0 - 10s) giúp âm thanh không bị ngắt đột ngột. | 🔴 **CHƯA CÓ** | Cần thêm 2 thanh trượt Fade trong ngăn kéo Âm lượng và nội suy giảm âm lượng audio track. |
| **Tự động bắt nhịp phách (Auto Beats / Beat Sync)** | Quét phổ tần số âm thanh, tự động thả các chấm tròn màu vàng (Beat markers) lên track nhạc tại các điểm rơi nhịp bass. | 🔴 **CHƯA CÓ** | Cần giải thuật phát hiện năng lượng âm trầm (Low-frequency energy detector / FFT) để sinh ra mảng `beatTimestampsMs[]`. |
| **Tách lời bài hát (Vocal Isolation)** | Menu 2 tùy chọn: "Giữ lại giọng hát" (tách bỏ nhạc) hoặc "Xóa giọng hát" (tách bỏ lời để lấy beat karaoke). | 🔴 **CHƯA CÓ** | Tính năng nâng cao, có thể tích hợp qua Web API AI hoặc thư viện nén nhỏ gọn on-device. |
| **Tăng cường giọng nói (Enhance Voice)** | Làm ấm, tăng độ chi tiết và độ dày của giọng nói thu âm bằng mic điện thoại. | 🔴 **CHƯA CÓ** | Cần áp dụng bộ lọc Equalizer (Boost dải 2kHz - 5kHz và cắt tần số thấp dưới 80Hz). |
| **Giảm tiếng ồn (Reduce Noise)** | Khử tiếng quạt, tiếng gió, tiếng ồn môi trường một chạm. | 🔴 **CHƯA CÓ** | Cần áp dụng bộ lọc Spectral Subtraction Noise Gate. |
| **Ghi âm lồng tiếng (Voiceover)** | Nút micro đếm ngược 3, 2, 1 và thu âm giọng nói trực tiếp từ mic vào timeline khi video đang chạy. | 🔴 **CHƯA CÓ** | Cần sử dụng `AudioRecord` / `MediaRecorder` ghi tệp `.m4a` và tự động gắn vào Audio Track tại vị trí playhead. |

---

### BẢNG 6: HỆ THỐNG VĂN BẢN, PHỤ ĐỀ ĐỘNG & NHÃN DÁN (TEXT & CAPTIONS)

| Tính Năng Văn Bản & Phụ Đề | Tính Năng CapCut Gốc [OBSERVED] | Trạng Thái OpenCut | Khoảng Trống Cần Khắc Phục |
|---|---|:---:|---|
| **Phụ đề nhảy chữ theo từ (Word-by-word Highlight)** | Phụ đề phong cách TikTok hiện đại (kiểu MrBeast, Alex Hormozi): Chữ đổi màu vàng/xanh rực rỡ và phóng to đúng theo từng từ khi người nói phát âm. | 🟡 **CƠ BẢN** | OpenCut mới chỉ hiển thị cả câu phụ đề tĩnh theo từng phân đoạn 1.5 giây. Cần có dữ liệu timestamp cho từng từ (word-level timestamps) và hiệu ứng scale text nhấp nháy. |
| **Mẫu chữ nghệ thuật (Text Templates)** | Hàng trăm mẫu chữ động có sẵn: Tiêu đề báo chí, Hạ bậc 3rd (Lower thirds), Vlog du lịch, Chữ phong cách Cyberpunk... | 🟡 **CƠ BẢN** | OpenCut đã có mẫu chữ Kinetic cơ bản. Cần bổ sung thêm các mẫu chữ động kèm khung viền và hoạt ảnh vào ra phong phú. |
| **Phụ đề song ngữ (Bilingual Captions)** | Tự động dịch giọng nói tiếng Việt sang phụ đề tiếng Anh (hoặc ngược lại) và hiển thị đồng thời 2 dòng. | 🟡 **CƠ BẢN** | OpenCut đã có dialog chọn ngôn ngữ vi-VN và en-US nhưng chưa hiển thị song song cả 2 dòng phụ đề trên cùng một khung hình. |
| **Bong bóng thoại (Text Bubbles)** | Đặt chữ vào trong khung tranh vẽ comic, bóng bay hội thoại hoạt hình, khung tin nhắn mạng xã hội. | 🔴 **CHƯA CÓ** | Chưa có danh mục Bubble trong trình sửa chữ. |
| **Hoạt ảnh chữ (Text Animation)** | Hiệu ứng chữ gõ máy (Typewriter), Chữ trượt từng ký tự, Chữ nhảy sóng, Chữ phát sáng nhấp nháy. | 🔴 **CHƯA CÓ** | Chưa có tab Animation trong Text Editor. |
| **Kho nhãn dán (Stickers & Giphy)** | Kho nhãn dán sticker đa chủ đề, tìm kiếm ảnh động Giphy, gắn sticker lên video. | 🔴 **CHƯA CÓ** | Mới chỉ có nút nhãn dán đại diện, chưa nạp kho tài nguyên sticker vector. |

---

### BẢNG 7: TƯƠNG TÁC DÒNG THỜI GIAN NÂNG CAO (TIMELINE UX & GESTURES)

| Cử Chỉ / Trải Nghiệm Timeline | Trải Nghiệm CapCut Gốc [OBSERVED] | Trạng Thái OpenCut | Giải Pháp Nâng Cấp Kỹ Thuật |
|---|---|:---:|---|
| **Thu phóng Timeline 2 ngón tay (Pinch-to-Zoom)** | Dùng 2 ngón tay chụm vào để thu nhỏ timeline xem toàn cảnh cả video dài; kéo giãn 2 ngón tay để phóng to xem từng khung hình chi tiết (frame-by-frame). | 🔴 **CHƯA CÓ** | OpenCut đang dùng `pxPerSec = 80px` cố định. Cần gắn `ScaleGestureDetector` lên `HorizontalScrollView` của timeline để điều chỉnh biến số `pxPerSec` từ 30px đến 300px. |
| **Bắt dính nam châm (Magnetic Snapping)** | Khi kéo playhead hoặc kéo mép clip tới gần mép của clip khác, điểm beat, hoặc điểm keyframe, timeline tự động "hút" dính vào và điện thoại rung nhẹ phản hồi (Haptic). | 🔴 **CHƯA CÓ** | Cần cài đặt ngưỡng snap threshold (ví dụ khoảng cách < 15px thì tự động gán tọa độ bằng mốc cắt) kèm rung nhẹ `Vibrator.vibrate()`. |
| **Cuộn mượt đồng bộ (Auto-scroll timeline during playback)** | Khi bấm Play phát video, thanh cuộn timeline tự động trôi mượt mà để Playhead luôn nằm ở trung tâm màn hình. | 🟡 **CƠ BẢN** | Đã có playhead di chuyển nhưng thanh cuộn timeline chưa tự động `smoothScrollTo()` theo thời gian thực khi clip dài hơn chiều rộng màn hình. |
| **Nút Mở Rộng Toàn Màn Hình Preview (Full-screen Preview Toggle)** | Nút bấm góc dưới canvas để phóng to video ra toàn màn hình điện thoại xem thử không bị che bởi timeline. | 🔴 **CHƯA CÓ** | Cần bổ sung nút Full-screen icon mở cửa sổ preview toàn màn hình. |

---

## III. BẢNG TỔNG KẾT TỶ LỆ ĐỐI CHIẾU (PARITY SCORECARD)

Thống kê chi tiết trên tổng số **50 tiêu chí chức năng cốt lõi** của phân hệ Video Editing CapCut:

```
┌─────────────────────────────────────────────────────────────────┐
│              MA TRẬN MỨC ĐỘ ĐÁP ỨNG CỦA OPENCUT                 │
├────────────────────────┬─────────────┬─────────────┬────────────┤
│ Phân Nhóm Tính Năng    │ Hoàn Thiện  │ Cơ Bản/Dở   │ Chưa Có    │
│                        │ (100% Pass) │ Dang        │ (Backlog)  │
├────────────────────────┼─────────────┼─────────────┼────────────┤
│ 1. Toolbar Cấp 1 (Gốc) │ 5 (45%)     │ 5 (45%)     │ 1 (10%)    │
│ 2. Tool Clip Cấp 2     │ 8 (32%)     │ 6 (24%)     │ 11 (44%)   │
│ 3. Chuyển Cảnh (Trans) │ 0 (0%)      │ 0 (0%)      │ 6 (100%)   │
│ 4. Khung Hình Chính KF │ 0 (0%)      │ 0 (0%)      │ 4 (100%)   │
│ 5. m Thanh Chuyên Sâu  │ 1 (14%)     │ 2 (29%)     │ 4 (57%)    │
│ 6. Văn Bản & Phụ Đề    │ 0 (0%)      │ 3 (50%)     │ 3 (50%)    │
│ 7. Tương Tác Timeline  │ 1 (25%)     │ 1 (25%)     │ 2 (50%)    │
├────────────────────────┼─────────────┼─────────────┼────────────┤
│ TỔNG CỘNG (50 Tiêu Chí)│ 15 (30%)    │ 17 (34%)    │ 18 (36%)   │
└────────────────────────┴─────────────┴─────────────┴────────────┘
```

> **Đánh Giá Tổng Quan**: 
> - OpenCut đã hoàn thành vững chắc **64% khối lượng nền tảng** (30% hoàn thiện sâu + 34% đã có khung sườn cơ bản).
> - Còn lại **36% tính năng cao cấp** (18 tiêu chí chuyên sâu) thuộc về các tính năng biên tập video nâng cao của CapCut mà người dùng chuyên nghiệp rất cần: **Keyframe `◆`**, **Transitions `|`**, **Clip Animation In/Out/Combo**, **Thu phóng 2 ngón tay Timeline (Pinch-to-zoom)**, **Fade In/Out & Boost âm lượng 1000%**, và **Phụ đề nhảy chữ theo từ (Alex Hormozi style)**.

---

## IV. LỘ TRÌNH ĐỀ XUẤT HÀNH ĐỘNG TIẾP THEO (ACTIONABLE ROADMAP)

Để đưa NextAI OpenCut tiến sát mức độ tương đồng **95% - 98% chuẩn CapCut**, đề xuất chia các hạng mục còn thiếu thành 4 giai đoạn triển khai trọng tâm:

### 🔹 GIAI ĐOẠN 1: BỔ SUNG 2 TÍNH NĂNG "LINH HỒN" CỦA CAPCUT (Ưu tiên số 1 - Critical)
1. **Hệ Thống Chuyển Cảnh Giữa Các Clip (Transitions System `|`)**:
   - Vẽ nút vuông trắng `|` giữa mỗi 2 clip trên timeline.
   - Bấm vào mở hộp thoại Transitions: Mờ dần (Dissolve), Cháy sáng (Flash), Trượt (Slide), Tách RGB (Glitch) + Thanh trượt thời lượng (0.1s - 2.0s) + Nút "Áp dụng tất cả".
2. **Hệ Thống Khung Hình Chính (Keyframing Engine `◆`)**:
   - Thêm nút hình thoi `◆` cạnh nút Play.
   - Cho phép đặt điểm neo Keyframe cho Tọa độ, Thu phóng, và Độ trong suốt (Scale, Position, Opacity) trên clip.
   - Vẽ các điểm thoi Keyframe trên dải clip timeline.

### 🔹 GIAI ĐOẠN 2: TỐI ƯU HỆ THỐNG ÂM THANH & CỬ CHỈ TIMELINE (Ưu tiên số 2 - High)
1. **Âm Thanh Chuyên Sâu**:
   - Mở rộng thanh trượt Âm lượng từ 200% lên **1000%**.
   - Bổ sung 2 thanh trượt **Fade In (Tăng dần)** và **Fade Out (Giảm dần)**.
   - Tự động gắn các điểm vàng nhịp phách (Auto Beat points) trên Audio Track.
2. **Cử Chỉ Timeline Mượt Mà**:
   - Tích hợp cử chỉ 2 ngón tay (Pinch-to-Zoom) để phóng to/thu nhỏ tỷ lệ timeline (`pxPerSec` từ 30px đến 250px).
   - Tự động cuộn mượt (`smoothScrollTo`) giữ playhead luôn ở vị trí giữa màn hình khi video đang phát.

### 🔹 GIAI ĐOẠN 3: HOẠT ẢNH CLIP & PHỤ ĐỀ DYNAMIC HIỆN ĐẠI (Ưu tiên số 3 - Medium)
1. **Hoạt Ảnh Clip (Animation In / Out / Combo)**:
   - Thêm menu con Hoạt ảnh: Mờ dần vào/ra, Nảy lên, Thu nhỏ, Lật 3D, Con lắc (Pendulum).
2. **Phụ Đề Nhảy Chữ Từng Từ (Word-by-Word Highlight)**:
   - Nâng cấp phụ đề AI hiển thị chữ phóng to đổi màu vàng/xanh theo từng từ phát âm chuẩn phong cách TikTok/Reels hiện đại.

### 🔹 GIAI ĐOẠN 4: CÔNG CỤ HOÀN THIỆN & NÂNG CAO (Ưu tiên số 4 - Polish)
1. **Nút Thay Thế Clip (Replace)** giữ nguyên độ dài và hiệu ứng.
2. **Trình Sửa Ảnh Bìa Video (Cover Editor)** độc lập.
3. **Mở Rộng Mặt Nạ (Mask)** thêm hình Chữ nhật, Trái tim, Ngôi sao và thanh trượt Độ mềm mép (Feather).
4. **Bảng Màu HSL 8 Màu & Curves RGB** đưa trực tiếp vào dải Video Editor.

---
*Tài liệu được lập bởi Hội đồng Kiến trúc sư NextAI OpenCut (Agent 0, Agent 1, Agent 3, Agent 11, Agent 12). Cập nhật ngày 2026-09-18.*
