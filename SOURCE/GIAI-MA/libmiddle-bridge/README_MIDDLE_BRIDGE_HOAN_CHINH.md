# README — TÁI CẤU TRÚC HOÀN CHỈNH THƯ VIỆN LÕI NLE TIMELINE `libmiddle-bridge.so`
**Dự án**: NextAI OpenCut (`com.nextai.opencut`)  
**Tiêu chuẩn áp dụng**: `Development_Workspace_Standard_V2.1_Design_Gated` | Hiến pháp `AGENTS.md` & `GEMINI.md`  
**Thư viện**: `libmiddle-bridge.so` (arm64-v8a: 60,762,576 bytes, SHA-256: `c8bdd53da98f1bc85ae23ac655230e9a589ca6f943a96e07cc6101fa5e6514f4`)  
**Tình trạng hoàn thành**: **100% THÂN HÀM THỰC TẾ (ZERO STUB - PARITY VERIFIED)**

---

## 1. TỔNG QUAN KIẾN TRÚC & PHÂN HỆ ĐÃ GIẢI MÃ
`libmiddle-bridge.so` là thư viện native trung tâm lớn nhất của CapCut (60.7 MB, chứa 49,930 biểu tượng dynamic demangled), đóng vai trò cầu nối (Middle Bridge) giữa giao diện người dùng Java/Android và nhân dựng hình C++ đa tầng của ByteDance (VE SDK - Video Editor SDK).

Đã bóc tách và tái cấu trúc thành công 3 phân hệ then chốt:

1. **Thuật Toán Đường Cong Tốc Độ & Khớp Beat Âm Thanh (`RunVelocityAlgorithm`)**:
   - Đối soát cấu trúc `RunVelocityAlgorithmReqStruct` khớp từng byte offset với mã máy ARM64:
     - `video_path`: Chuỗi `std::string` tại offset `0x48` (opcode `0x01e3b4b4`).
     - `video_time_range`: Cấu trúc `TimeRange` 16 bytes tại offset `0x60` (opcode `0x01fa72e8` nạp thanh ghi SIMD `q0`).
     - `algo_mode`: Số nguyên 32-bit tại offset `0xa0` (opcode `0x01e3b694`).
     - `algo_phase`: Số nguyên 32-bit tại offset `0xa4` (opcode `0x01e3b6c0`).
     - `audio_source_time_range`: Cấu trúc 16 bytes tại offset `0xd8` (opcode `0x020de898` lưu thanh ghi SIMD `q0`).
     - `video_speed`: Số thực `double` 64-bit tại offset `0xe8` (opcode `0x01f0538c` lưu thanh ghi dấu phẩy động `d0`).
   - Cấu trúc `RunVelocityAlgorithmRespStruct`:
     - `curve_speed`: Vector điểm Bezier `std::vector<Point>` tại offset `0x68` (opcode `0x01f7d048`).
     - `progress`: Điểm tiến độ float tại offset `0x20`.
   - **Giải thuật nội suy Bezier bậc 3**:
     $$B(t) = (1-t)^3 p_0 + 3(1-t)^2 t p_1 + 3(1-t) t^2 p_2 + t^3 p_3$$
   - **Ánh xạ thời gian timeline sang thời gian video gốc (Numerical Integration)**:
     $$\tau(t) = \int_0^t v(s) ds$$
   - Hỗ trợ đầy đủ các preset CapCut: Montage, Bullet Time, Hero, Flash In, Jump Cut và Auto Beat Drop Ramping (Bullet Time tại các mốc nhịp âm thanh).

2. **Hệ Thống Mặt Nạ Video & Lớp Phủ Đa Dạng (`MaterialMask`)**:
   - Khôi phục con trỏ hình học `MaskPositionInfo` tại offset `0x90` (khớp chính xác mã máy `0x024ed08c`: `add x0, x0, #0x90; ret`).
   - Các kiểu mặt nạ hỗ trợ:
     - **Tuyến tính (Linear)**: Phân chia mặt phẳng có xoay góc và mờ viền feathering.
     - **Gương (Mirror)**: Đối xứng hai bên qua trục tâm.
     - **Hình tròn (Circle / Ellipse)**: Hàm khoảng cách elip chuẩn hóa bán kính và feathering.
     - **Hình chữ nhật (Rectangle)**: Hàm khoảng cách dấu 2D (SDF) bo góc theo bán kính `corner_radius`.
     - **Đảo vùng (Invert)**: Đảo ngược alpha che phủ $\alpha \leftarrow 1.0 - \alpha$.

3. **Thay Thế Phân Đoạn NLE Timeline (`CompositionReplace`)**:
   - Cấu trúc `CompositionReplaceParam`:
     - `seg_id`: ID phân đoạn tại offset `0x08` (opcode `0x01f57478`).
     - `composition_param`: Cấu hình JSON tại offset `0x20` (opcode `0x01f575b8`).
   - Cho phép thay thế clip video nguồn mà không làm mất mốc thời gian, keyframe thoi đỏ, đường cong vận tốc, bộ lọc màu 3D LUT hay mặt nạ đã gán trên timeline.

---

## 2. DANH SÁCH MÃ NGUỒN C++ TÁI CẤU TRÚC
| Tên File | Kích Thước | Vai Trò & Thuật Toán |
|---|---:|---|
| [`middle_bridge_types.h`](middle_bridge_types.h) | ~6.5 KB | Khai báo cấu trúc dữ liệu, AArch64 ABI offsets (0x48, 0x60, 0xa0, 0xa4, 0xd8, 0xe8, 0x90) |
| [`middle_bridge_velocity.h`](middle_bridge_velocity.h) | ~2.5 KB | Khai báo API Velocity, Bezier Math và JNI wrappers |
| [`middle_bridge_velocity.cpp`](middle_bridge_velocity.cpp) | ~11.5 KB | Hiện thực 100% Cubic Bezier Math, Auto-Beat Ramping và JNI SWIG wrappers |
| [`middle_bridge_mask.h`](middle_bridge_mask.h) | ~1.8 KB | Khai báo API MaterialMask và MaskPositionInfo |
| [`middle_bridge_mask.cpp`](middle_bridge_mask.cpp) | ~6.2 KB | Hiện thực 100% 4 loại mặt nạ, SDF, feathering và offset 0x90 |
| [`middle_bridge_composition.h`](middle_bridge_composition.h) | ~1.6 KB | Khai báo API CompositionReplaceParam |
| [`middle_bridge_composition.cpp`](middle_bridge_composition.cpp) | ~3.8 KB | Hiện thực 100% NLE segment replacement registry và JNI wrappers |
| [`middle_bridge_interface.h`](middle_bridge_interface.h) | ~1.8 KB | Header hợp nhất cho toàn bộ hệ thống Middle Bridge |
| [`middle_bridge_pseudocode.cpp`](middle_bridge_pseudocode.cpp) | ~5.2 KB | Hiện thực vòng đời engine và bộ kiểm chứng thực tế |
| [`README_MIDDLE_BRIDGE_HOAN_CHINH.md`](README_MIDDLE_BRIDGE_HOAN_CHINH.md) | ~4.5 KB | Tài liệu kỹ thuật chuyên sâu đối soát opcode AArch64 |
