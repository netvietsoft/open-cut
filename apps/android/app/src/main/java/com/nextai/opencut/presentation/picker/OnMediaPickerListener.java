package com.nextai.opencut.presentation.picker;

import com.nextai.opencut.presentation.model.MediaItem;
import java.util.List;

/**
 * OnMediaPickerListener — Giao Diện Lắng Nghe Sự Kiện Chọn Media (Media Picker Event Listener Interface)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public interface OnMediaPickerListener {
    /**
     * Called when user presses the close button ('✕') on media picker
     * Kích hoạt khi người dùng bấm nút đóng ('✕') trên trình chọn media
     */
    void onMediaPickerClose();

    /**
     * Called when user confirms importing the selected items
     * Kích hoạt khi người dùng xác nhận nhập các mục đã chọn
     *
     * @param selected List of chosen MediaItems / Danh sách MediaItem đã chọn
     */
    void onMediaPickerImport(List<MediaItem> selected);

    /**
     * Called when user requests opening the Android system gallery / SAF picker
     * Kích hoạt khi người dùng yêu cầu mở album hệ thống Android (SAF picker)
     */
    void onMediaPickerOpenSystemGallery();
}
