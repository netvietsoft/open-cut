# Docs/Design/DESIGN_SYSTEM.md — HỆ THỐNG THIẾT KẾ CANONICAL CHO NEXTAI OPENCUT

> **Phạm vi**: Đồng bộ nhận diện và trải nghiệm giữa Ứng dụng Android (Jetpack Compose) và Web Admin CMS.

---

## 1. MÀU SẮC CHỦ ĐẠO (COLOR TOKENS)

| Tên Token | Mã Hex (Dark Mode) | Mã Hex (Light Mode) | Mục Đích Sử Dụng |
|---|---|---|---|
| `--color-bg-primary` | `#0D0E12` (OLED Dark) | `#F8F9FA` | Nền chính của ứng dụng và CMS |
| `--color-bg-surface` | `#16181F` (Card Dark) | `#FFFFFF` | Nền thẻ (Card), Modal, Bottom Sheet |
| `--color-brand-primary` | `#00E5FF` (Neon Cyan) | `#0088CC` | Nút hành động chính, VIP badge, điểm nhấn |
| `--color-brand-accent` | `#7C4DFF` (Electric Purple)| `#6200EE` | Điểm nhấn AI Agent, Gradient hero |
| `--color-text-primary` | `#FFFFFF` | `#1E293B` | Tiêu đề, văn bản chính |
| `--color-text-secondary`| `#94A3B8` | `#64748B` | Mô tả phụ, nhãn phụ, timestamp |
| `--color-success` | `#10B981` | `#059669` | Trạng thái thành công, Active VIP |
| `--color-warning` | `#F59E0B` | `#D97706` | Cảnh báo, hạn mức dùng thử sắp hết |
| `--color-danger` | `#EF4444` | `#DC2626` | Lỗi, nút xóa dữ liệu, cảnh báo bảo mật |

---

## 2. QUY CHUẨN TYPOGRAPHY & SPACING
- **Font chữ chính**: `Inter`, `Roboto`, `Plus Jakarta Sans`, `system-ui`.
- **Thang khoảng cách (Spacing Scale)**:
  - `xs`: `4px` | `sm`: `8px` | `md`: `16px` | `lg`: `24px` | `xl`: `32px` | `2xl`: `48px`.
- **Bo góc (Border Radius)**:
  - `sm`: `6px` | `md`: `12px` | `lg`: `16px` | `pill`: `9999px`.

---

## 3. NGUYÊN TẮC THIẾT KẾ WEB CMS & RESPONSIVE
1. **Cấu trúc URL Chuẩn**: `domain.com/ParentMenu/SubMenu` (VD: `/admin/users`, `/admin/templates`, `/admin/ai-prompts`).
2. **Hiển thị Card-based khi nhiều dữ liệu**: Bảng dữ liệu người dùng, thiết bị, mẫu video hiển thị dưới dạng các thẻ (Cards) tinh tế trên Mobile/Tablet.
3. **Chuyển đổi Theme Sáng/Tối mượt mà**: Nút chuyển theme lưu trữ trạng thái vào `localStorage` và cập nhật biến CSS thời gian thực.
