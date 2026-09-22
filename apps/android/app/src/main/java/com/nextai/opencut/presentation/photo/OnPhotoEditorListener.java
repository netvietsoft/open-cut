package com.nextai.opencut.presentation.photo;

import android.graphics.Bitmap;

/**
 * OnPhotoEditorListener — Callback interface for Photo Editor lifecycle and user actions.
 * Giao diện phản hồi sự kiện cho vòng đời và thao tác người dùng trong Trình Chỉnh Sửa Ảnh.
 */
public interface OnPhotoEditorListener {

    /**
     * Called when user requests to close Photo Editor and return to Home.
     * Được gọi khi người dùng yêu cầu đóng Trình Chỉnh Sửa Ảnh và quay lại Trang Chủ.
     */
    void onPhotoEditorClose();

    /**
     * Called when photo has been successfully saved to device storage.
     * Được gọi khi ảnh đã được lưu thành công vào bộ nhớ thiết bị.
     *
     * @param bitmap Exported high-fidelity bitmap / Bitmap chất lượng cao đã xuất
     * @param filePath Absolute path of saved photo / Đường dẫn tuyệt đối của ảnh đã lưu
     */
    void onPhotoEditorSaved(Bitmap bitmap, String filePath);
}
