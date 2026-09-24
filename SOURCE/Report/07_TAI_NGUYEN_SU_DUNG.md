# BÁO CÁO 07: TỔNG KÊ TÀI NGUYÊN TÁI SỬ DỤNG ĐƯỢC TỪ CAPCUT 19.4.0

> **Mục tiêu đáp ứng**: Yêu cầu 8 (Có những tài nguyên gì có thể sử dụng ?).  
> **Vị trí tài nguyên trích xuất**: Thư mục `extracted/assets/` và `apktool-res/res/`.  
> **Dung lượng tài nguyên bóc tách**: Hơn 1,170 tập tin assets (~40+ MB không nén) và 40,000+ tài nguyên hình ảnh, chuỗi giao diện.

---

## 1. BẢNG DANH MỤC TÀI NGUYÊN CÓ THỂ TÁI SỬ DỤNG TRỰC TIẾP

| Nhóm Tài Nguyên | Vị trí thư mục | Số lượng / Dung lượng | Định dạng tập tin | Khả năng tái sử dụng trong sản phẩm mới |
|---|---|---|---|---|
| **Bộ Gói Dịch Đa Ngôn Ngữ (Localization Strings)** | `extracted/assets/strings#lang_*`<br>`locales/` | 60+ ngôn ngữ | JSON UTF-8 | ✅ **Sử dụng 100% ngay lập tức**: Toàn bộ từ điển thuật ngữ biên tập video chuẩn quốc tế (Việt Nam `vi.json`, Anh, Tây Ban Nha, Pháp, Trung, Nhật, Hàn, Thái, v.v.). Hơn 2,000 cặp key-value mỗi ngôn ngữ chuẩn xác từ chuyên ngành video editor. |
| **Phông Chữ Nghệ Thuật & Ký Hiệu Toán Học (Fonts)** | `extracted/assets/fonts/`<br>`composeResources/.../font/` | 49 files (~1.1 MB) | `.ttf`, `.otf` | ✅ **Sử dụng ngay**: Bộ phông AlbertSans (ExtraBold, Medium, Regular), các phông hiển thị ký hiệu toán học LaTeX (`jlm_cmex10.ttf`, `jlm_cmmi10.ttf`) dùng cho tính năng chèn công thức toán vào video giáo dục. |
| **Gói Hiệu Ứng Chuyển Cảnh & Mẫu Động (Transitions)** | `extracted/assets/zip/`<br>`splitscreen/` | 58 zip packages (~1.4 MB) | `.zip` (chứa JSON config, shader, textures) | ✅ **Sử dụng trực tiếp**: Gói hiệu ứng chuyển cảnh tuyến tính AI (`AI_trans_linear.zip`), mẫu văn bản AIGC (`aigc_text_template.zip`), và các cấu hình chia màn hình 2 ô, 3 ô (`split_screen_2.zip`, `split_screen_3.zip`). |
| **Mô Hình Trí Tuệ Nhân Tạo Trên Thiết Bị (On-Device AI)** | `extracted/assets/model/`<br>`smart_crop/` | 5 files (~0.6 MB) | `.zip`, `.so-32`, `.so-64` (OFX Plugins) | ✅ **Tái sử dụng cho Engine C++**: Mô hình `SegmentJS.zip` (phân đoạn chủ thể tách nền), thư viện `smart_cut.ofx.so` (OpenFX plugin cho smart auto-crop tự động nhận diện khung hình đẹp nhất của video theo tỉ lệ 9:16 hoặc 16:9). |
| **Kịch Bản & Mẫu Prompt Viết Nội Dung AI (AI Templates)** | `extracted/assets/ai_writer_template/`<br>`ailab_tab/`, `ailab_tab_v2/` | 10+ files JSON/PNG | `.json`, `.png` | ✅ **Sử dụng cho Prompt Engineering**: Cấu trúc mẫu kịch bản quảng cáo, video bán hàng TikTok Shop, mẫu phân cảnh video vlog được dựng sẵn trong `ai_writer_template.json` và `data.json`. |
| **Cấu Hình Nhân Bản Giọng Nói (Voice Clone Configs)** | `extracted/assets/tone_clone/`<br>`tone_clone_legal_dialog/` | 12 files JSON/PNG | `.json`, `.jpg` | ✅ **Sử dụng cho UI/UX flow**: Cấu trúc câu lệnh thu âm mẫu giọng chuẩn 10 câu để huấn luyện model Voice Clone, điều khoản cam kết pháp lý chống Deepfake (`tone_clone_legal_dialog/custom_voice.json`). |
| **Hoạt Họa Vector Lottie (Animations & Spinners)** | `extracted/assets/ad_script_loading/`<br>`swipe_loading/`, `star_shining/` | 150+ files JSON/PNG | `.json`, `.png`, `.webp` | ✅ **Sử dụng cho UI**: Toàn bộ hiệu ứng loading, icon ngôi sao lấp lánh (AI Sparkle), bàn tay hướng dẫn thao tác vuốt (swipe tutorial), đồng hồ đếm ngược. |
| **Giao Diện Động Lynx H5 (Offline Web Bundles)** | `extracted/assets/offline/` | 476 files (~19.2 MB) | `.js`, `.json` | 🔍 **Phân tích tham khảo**: Toàn bộ mã nguồn giao diện tìm kiếm mẫu (`image_lynx_all_search/template.js`), hiển thị danh mục linh hoạt. |

---

## 2. HƯỚNG DẪN TÁI SỬ DỤNG TỪNG NHÓM TÀI NGUYÊN

### 2.1. Tái sử dụng Bộ ngôn ngữ bản địa hóa (Strings Localization)
- File `extracted/assets/strings#lang_vi/vi.json` chứa 94 KB chuỗi tiếng Việt đã được dịch chuẩn hóa tuyệt đối bởi đội ngũ ngôn ngữ của ByteDance.
- Các nhóm từ khóa giá trị cao:
  - Thuật ngữ Timeline: *"Cắt tách", "Tốc độ đường cong", "Khung hình chính (Keyframe)", "Lớp phủ (PIP)", "Mặt nạ", "Bắt dính phách nhạc"*.
  - Thuật ngữ Retouch: *"Mịn da", "Thon mặt", "Gọt cằm", "Trắng răng", "Xóa bọng mắt", "Làm sáng mắt"*.
  - Thuật ngữ m thanh: *"Tách giọng hát", "Giảm tiếng ồn", "Lồng tiếng", "m thanh bản quyền"*.
  - Thuật ngữ AI: *"Chuyển văn bản thành video", "Nhân bản giọng nói", "Người kỹ thuật số", "Tạo phụ đề tự động"*.
- **Cách tích hợp**: Nhúng trực tiếp file `vi.json` vào dự án Flutter / React Native / Android Compose mới để có ngay giao diện chuẩn 100% tiếng Việt mà không cần thuê dịch thuật.

### 2.2. Tái sử dụng Cấu trúc Hiệu ứng Chuyển cảnh (Transitions)
- Giải nén `extracted/assets/zip/AI_trans_linear.zip`:
  Bên trong chứa file `config.json` quy định ma trận biến đổi toạ độ (Affine Transform Matrix), hàm nội suy thời gian (Easing Bézier Curve: `cubic-bezier(0.25, 0.1, 0.25, 1.0)`), và thời lượng chuẩn (default duration = 0.5s).
- **Cách tích hợp**: Đọc các thông số Bézier Curve này đưa vào OpenGL ES Fragment Shader hoặc WebGL Pipeline để tái hiện hiệu ứng chuyển cảnh mượt mà y hệt CapCut gốc.

### 2.3. Tái sử dụng Cấu trúc Chia Khung Hình (Split Screen Presets)
- Các file trong `extracted/assets/splitscreen/`:
  Quy định tỷ lệ phân chia màn hình: 2 ô dọc, 2 ô ngang, 3 ô chia đều, 4 ô lưới hoặc 1 ô lớn 2 ô nhỏ.
  Chứa toạ độ chuẩn hóa `[x, y, width, height]` từ `0.0` đến `1.0` độc lập với độ phân giải màn hình.
- **Cách tích hợp**: Sử dụng trực tiếp các toạ độ này để làm bộ tính năng "Layout Video Ghép Khung".

---

## 3. LƯU Ý VỀ PHÁP LÝ VÀ BẢN QUYỀN SỞ HỮU TRÍ TUỆ (LEGAL CONSIDERATIONS)

1. **Chuỗi ngôn ngữ & Cấu hình JSON**: Có tính chất dữ liệu thuần túy (Data / Specifications), không có tính chất mã nguồn độc quyền, có thể tự do tham khảo và áp dụng lại.
2. **Phông chữ (.ttf)**: Cần kiểm tra giấy phép mở (OFL / Apache 2.0). Ví dụ AlbertSans là phông mã nguồn mở của Google Fonts, hoàn toàn được phép sử dụng thương mại miễn phí.
3. **Mô hình AI (.model / .so)**: Mang bản quyền kỹ thuật của ByteDance. Trong sản phẩm thương mại độc lập, nên thay thế bằng các mô hình mã nguồn mở tương đương:
   - Thay `SegmentJS` bằng **RVM (Robust Video Matting)** hoặc **MediaPipe Selfie Segmentation**.
   - Thay `libttffmpeg.so` bằng **FFmpeg 6.x / 7.x Official Release** với x264/x265.
   - Thay ASR Speech-to-Text bằng **OpenAI Whisper (Whisper.cpp)** hoặc **Vosk On-Device**.
