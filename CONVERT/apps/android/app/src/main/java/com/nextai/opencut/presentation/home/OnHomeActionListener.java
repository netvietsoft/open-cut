package com.nextai.opencut.presentation.home;

/**
 * OnHomeActionListener — Giao Diện Lắng Nghe Sự Kiện Màn Hình Trang Chủ (Home Hub Action Listener)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public interface OnHomeActionListener {
    /**
     * User clicks "+ Dự án mới (New Project)" hero card
     * Người dùng bấm vào thẻ Hero "+ Dự án mới"
     */
    void onNewProject();

    /**
     * User clicks one of the 8 quick tool tiles
     * Người dùng bấm vào một trong 8 ô công cụ nhanh
     *
     * @param toolKey Định danh công cụ (e.g. "cutout", "captions", "photoedit", "facebody")
     * @param label   Nhãn hiển thị (e.g. "Xóa phông", "Phụ đề AI", "Chỉnh sửa ảnh")
     */
    void onQuickTool(String toolKey, String label);

    /**
     * User clicks a recent draft card
     * Người dùng bấm vào một bản nháp gần đây
     *
     * @param draftIndex Chỉ số bản nháp (0, 1, 2)
     * @param draftTitle Tiêu đề bản nháp
     */
    void onDraft(int draftIndex, String draftTitle);

    /**
     * User clicks PRO VIP Badge on header
     * Người dùng bấm vào huy hiệu PRO VIP trên thanh header
     */
    void onVipBadge();

    /**
     * User selects a tab from the 6-tab bottom navigation bar
     * Người dùng chọn chuyển tab ở thanh điều hướng đáy (Bottom Navigation)
     *
     * @param tabIndex 0: Biên tập (Home), 1: Mẫu, 2: Đám mây, 3: AI Lab, 4: VIP, 5: Tôi
     */
    void onBottomNav(int tabIndex);
}
