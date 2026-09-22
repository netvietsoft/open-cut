# ADR-005: MODULAR COMPONENT ARCHITECTURE FOR MAINACTIVITY DECOMPOSITION
# QUYẾT ĐỊNH KIẾN TRÚC: TÁI CẤU TRÚC PHÂN RÃ MAINACTIVITY THÀNH KIẾN TRÚC THÀNH PHẦN

- **Trạng thái**: `ACCEPTED` (Đã được Chủ tịch phê duyệt)
- **Ngày quyết định**: 2026-09-21
- **Người đề xuất**: Agent 0 (Orchestrator), Agent 1 (Architect)
- **Người phê duyệt**: Chủ tịch (President)
- **Phạm vi**: `apps/android/app/src/main/java/com/nextai/opencut/presentation/**`

---

## 1. BỐI CẢNH (CONTEXT)
`MainActivity.java` ban đầu được xây dựng để tích hợp nhanh chóng toàn bộ tính năng CapCut Parity 100% qua 22 Phase (từ TASK-001 đến TASK-034). Sau khi hoàn thiện toàn bộ các tính năng từ Video Timeline đa track đến Photo Editor VIP Beauty Suite, quy mô tệp `MainActivity.java` đã phình to lên tới **11,489 dòng code (566 KB)**.

Việc dồn toàn bộ logic vào một Activity duy nhất ("God Class") dẫn đến:
1. Độ phức tạp chu kỳ bảo trì rất cao.
2. Khó mở rộng, khó bảo vệ các module độc lập.
3. Không thể tái sử dụng các thành phần (như MediaPicker, PhotoCanvas, VideoTimeline) ở các Activity hay Fragment khác.

---

## 2. QUYẾT ĐỊNH KIẾN TRÚC (DECISION)
Chủ tịch chỉ đạo: *"anh thấy MainActivity.jav quá dài tới hàng chục nghìn dòng code. cần chuẩn hóa viết cấc component để dùng chung gọi vào"*.
Chúng tôi quyết định phân rã `MainActivity.java` thành mô hình **Component-Driven Modular Architecture**:

1. **Tách Lớp Data Models (`presentation/model/`)**:
   - `MediaItem.java`: Quản lý thông tin ảnh/video (Uri, Thumbnail, Title, Duration, Selection Index).
   - `ProjectClip.java`: Quản lý thông tin clip trên timeline (Duration, Trim, Speed, Volume, Keyframes).
   - `KeyframePoint.java`: Quản lý điểm mốc khung hình chính (Scale, TransX, TransY, Opacity, Rotation).

2. **Tách Phân Hệ Media Picker (`presentation/picker/`)**:
   - `MediaPickerComponent.java`: Quản lý quét MediaStore, hiển thị Tabs, đa chọn có số thứ tự, LruCache thumbnail.
   - `OnMediaPickerListener.java`: Interface giao tiếp giữa Picker và Activity.

3. **Tách Phân Hệ Trang Chủ (`presentation/home/`)**:
   - `HomeHubComponent.java`: Quản lý Header, VIP Badge, Hero Card `+`, 8 Quick Tools Grid, Drafts list, 6 Bottom Tabs.
   - `OnHomeActionListener.java`: Interface điều hướng hành động người dùng.

4. **Tách Phân Hệ Photo Editor Suite (`presentation/editor/photo/`)**:
   - `PhotoEditorComponent.java`: Khung điều khiển chính của Photo Editor.
   - `PhotoCanvasController.java`: Auto-fit dynamic dimensions, EXIF upright orientation, Crop & Resize dialog, Flip, Xoay 90°.
   - `PhotoFilterController.java`: 3D LUTs strip & Bitmap baking.
   - `PhotoLightroomController.java`: Adobe Lightroom Mobile Pro optics (RGB Tone curves, Clarity, Dehaze, Grain, Vignette).
   - `PhotoBeautyController.java`: Facetune & Meitu VIP Beauty suite (Son môi, Trắng răng, Sáng mắt, Kéo chân In-frame, Touch-to-Target).
   - `PhotoAiEffectsController.java`: SnapEdit AI Inpaint, Sky replacement, FaceApp morphing.
   - `PhotoExportController.java`: Xuất ảnh JPEG/PNG phân giải gốc & MediaStore scanner.

5. **Tách Phân Hệ Video Editor Suite (`presentation/editor/video/`)**:
   - `VideoEditorComponent.java`: Khung điều khiển chính của Video Editor.
   - `VideoTimelineController.java`: 5 tracks timeline, Timecode Ruler 60fps, playhead sync, scrubbing.
   - `VideoClipOperations.java`: Tách clip, xóa, nhân bản, tốc độ đường cong, keyframes `lerp`, chuyển cảnh `⚡`.
   - `VideoAudioController.java`: Gain boost 1000%, dynamic limiter, fade in/out, sound library, TTS.
   - `VideoEffectsController.java`: Real-time visual FX, shaders (CapCut original, GlitchCam, VHS 1998, Chroma key).
   - `VideoTextController.java`: Chữ kéo thả tự do, typography styles, phụ đề karaoke highlight.
   - `VideoExportController.java`: FFmpeg C++20 JNI pipeline & carrier fallback dialog.

6. **Slim Orchestrator Activity (`MainActivity.java`)**:
   - Thu gọn từ 11,489 dòng xuống còn ~400 dòng.
   - Chỉ giữ vai trò Coordinator: quản lý Lifecycle, Permissions, và gắn kết các Components thông qua Listeners.

---

## 3. HỆ QUẢ (CONSEQUENCES)
- **Tích cực**:
  - Mã nguồn trong sáng, sạch sẽ, đạt chuẩn Modular Component Architecture.
  - Từng component có thể được kiểm thử độc lập và tái sử dụng cho các màn hình khác.
  - Loại bỏ hoàn toàn "God Class", tuân thủ Single Responsibility Principle (SRP).
- **Yêu cầu kỹ thuật**:
  - Biên dịch sạch 0 lỗi với Java 8 bytecode và D8 (`scripts/build_apk_only.ps1`).
  - Bảo đảm Zero Regression: 100% tính năng hoạt động mượt mà không suy giảm.
  - 100% mã nguồn có chú thích song ngữ Tiếng Việt + Tiếng Anh theo Luật 12 AGENTS.md.
