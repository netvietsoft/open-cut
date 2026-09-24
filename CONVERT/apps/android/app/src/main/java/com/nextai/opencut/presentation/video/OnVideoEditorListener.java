package com.nextai.opencut.presentation.video;

import android.net.Uri;
import com.nextai.opencut.presentation.model.MediaItem;
import java.io.File;

/**
 * Listener interface for Video Editor events / Giao diện lắng nghe sự kiện của Trình Biên Tập Video
 * Standardized across NextAI OpenCut architecture.
 */
public interface OnVideoEditorListener {

    /**
     * Called when the user closes the video editor to return to Home
     * Gọi khi người dùng đóng trình biên tập để trở về màn hình chính
     */
    void onVideoEditorClose();

    /**
     * Request to open media picker for adding clips, PIP overlays, or replacing a clip
     * Yêu cầu mở trình chọn media để thêm clip, lớp phủ PIP, hoặc thay thế clip
     *
     * @param pickerMode 0: All, 1: Video only, 2: Photo only
     * @param forPip true if selecting for PIP track
     * @param forReplace true if replacing current selected clip
     */
    void onRequestMediaPicker(int pickerMode, boolean forPip, boolean forReplace);

    /**
     * Called when a project video has finished exporting successfully
     * Gọi khi xuất video dự án thành công hoàn tất
     *
     * @param exportedFile the exported MP4 file
     */
    void onVideoExported(File exportedFile);

    /**
     * Request to open photo editor with a specific image
     * Yêu cầu mở trình biên tập ảnh với một tấm ảnh chỉ định
     *
     * @param item MediaItem photo
     */
    void onOpenPhotoEditor(MediaItem item);
}
