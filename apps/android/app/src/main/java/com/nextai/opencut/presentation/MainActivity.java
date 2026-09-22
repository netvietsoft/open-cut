package com.nextai.opencut.presentation;

import android.Manifest;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentUris;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.LruCache;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.Toast;

import com.nextai.opencut.presentation.ailab.AiLabComponent;
import com.nextai.opencut.presentation.cloud.CloudComponent;
import com.nextai.opencut.presentation.home.HomeHubComponent;
import com.nextai.opencut.presentation.home.OnHomeActionListener;
import com.nextai.opencut.presentation.model.MediaItem;
import com.nextai.opencut.presentation.photo.OnPhotoEditorListener;
import com.nextai.opencut.presentation.photo.PhotoEditorComponent;
import com.nextai.opencut.presentation.picker.MediaPickerComponent;
import com.nextai.opencut.presentation.picker.OnMediaPickerListener;
import com.nextai.opencut.presentation.profile.ProfileComponent;
import com.nextai.opencut.presentation.templates.TemplateComponent;
import com.nextai.opencut.presentation.subscribe.SubscribeActivity;
import com.nextai.opencut.presentation.video.OnVideoEditorListener;
import com.nextai.opencut.presentation.video.VideoEditorComponent;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * MainActivity — Slim Lifecycle Orchestrator / Bộ Điều Phối Vòng Đời Tối Giản
 * 
 * Central controller coordinating all NextAI OpenCut modular components:
 * - HomeHubComponent: Hero banner, quick action tools, recent draft projects.
 * - MediaPickerComponent: Multi-tab media gallery picker (All/Video/Photo/SAF).
 * - PhotoEditorComponent: Full-featured Photoshop/Lightroom/Facetune photo studio.
 * - VideoEditorComponent: High-performance 5-track video editing timeline with C++20 engine.
 * - Secondary modules: TemplateComponent, AiLabComponent, CloudComponent, ProfileComponent.
 *
 * Tiêu chuẩn kiến trúc NextAI OpenCut V2.1: Bộ điều phối trung tâm không chứa UI nguyên khối,
 * ủy quyền toàn bộ cho các thành phần chuyên biệt (Zero Monolith, 100% Modularity).
 */
public class MainActivity extends Activity implements
        OnHomeActionListener,
        OnMediaPickerListener,
        OnPhotoEditorListener,
        OnVideoEditorListener,
        TemplateComponent.OnTemplateActionListener,
        AiLabComponent.OnAiLabActionListener,
        CloudComponent.OnCloudActionListener,
        ProfileComponent.OnProfileActionListener {

    private static final int PERMISSION_REQUEST_CODE = 1001;
    private static final int REQUEST_CODE_SYSTEM_PICKER = 2001;

    // Root container / Khung chứa giao diện chính
    private FrameLayout rootFrame;

    // Modular Components / Các thành phần giao diện chuẩn hóa
    private HomeHubComponent homeHubComponent;
    private MediaPickerComponent mediaPickerComponent;
    private PhotoEditorComponent photoEditorComponent;
    private VideoEditorComponent videoEditorComponent;
    private TemplateComponent templateComponent;
    private AiLabComponent aiLabComponent;
    private CloudComponent cloudComponent;
    private ProfileComponent profileComponent;

    // Shared State & Threading / Trạng thái chia sẻ & Xử lý đa luồng
    private final List<MediaItem> allMediaItems = new ArrayList<>();
    private final List<MediaItem> activeProjectClips = new ArrayList<>();
    private final List<MediaItem> selectedMediaItems = new ArrayList<>();
    private ExecutorService executor;
    private LruCache<String, Bitmap> thumbnailCache;

    // Navigation and Picker Flags / Cờ điều hướng và trạng thái chọn media
    private boolean isPickingForPhotoEditor = false;
    private boolean isAddingToTimeline = false;
    private boolean isReplacingClip = false;
    private boolean isAddingPip = false;

    // Navigation Screen Tracking (Fixes X5) / Theo dõi màn hình hiện tại để xử lý phím Back an toàn
    private static final int SCREEN_HOME = 0;
    private static final int SCREEN_MEDIA_PICKER = 1;
    private static final int SCREEN_PHOTO_EDITOR = 2;
    private static final int SCREEN_VIDEO_EDITOR = 3;
    private static final int SCREEN_TAB = 4;
    private int currentScreen = SCREEN_HOME;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // 1. Initialize Thread Pool & Cache / Khởi tạo luồng xử lý và bộ đệm ảnh
        executor = Executors.newFixedThreadPool(4);
        int maxMemory = (int) (Runtime.getRuntime().maxMemory() / 1024);
        int cacheSize = maxMemory / 8;
        thumbnailCache = new LruCache<String, Bitmap>(64);

        // 2. Initialize Root Container / Khởi tạo khung chứa gốc
        rootFrame = new FrameLayout(this);
        rootFrame.setBackgroundColor(Color.parseColor("#000000"));
        rootFrame.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // 3. Scan or Load Media / Quét media thực tế từ thiết bị
        initMediaRepository();

        // 4. Initialize Modular Components / Khởi tạo các thành phần giao diện
        homeHubComponent = new HomeHubComponent(this, this);
        mediaPickerComponent = new MediaPickerComponent(this, allMediaItems, this);
        photoEditorComponent = new PhotoEditorComponent(this, this);
        videoEditorComponent = new VideoEditorComponent(this, allMediaItems, activeProjectClips, this, executor, thumbnailCache);
        templateComponent = new TemplateComponent(this, this);
        aiLabComponent = new AiLabComponent(this, this);
        cloudComponent = new CloudComponent(this, this);
        profileComponent = new ProfileComponent(this, this);

        // 5. Check & Request Storage Permissions / Kiểm tra và yêu cầu quyền truy cập
        checkAndRequestStoragePermissions();

        // 6. Set Default View (HomeHub) / Hiển thị màn hình chính mặc định
        showHome();
        setContentView(rootFrame);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (videoEditorComponent != null) {
            videoEditorComponent.onResume();
        }
        if (hasStoragePermission()) {
            scanDeviceMedia();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        try {
            if (videoEditorComponent != null) {
                videoEditorComponent.onDestroy();
            }
            if (executor != null) {
                executor.shutdownNow();
            }
        } catch (Exception ignored) {}
    }

    // =========================================================================
    // NAVIGATION & VIEW SWITCHING / ĐIỀU HƯỚNG VÀ CHUYỂN ĐỔI GIAO DIỆN
    // =========================================================================

    /**
     * Display HomeHub / Hiển thị màn hình chính HomeHub
     */
    public void showHome() {
        currentScreen = SCREEN_HOME;
        rootFrame.removeAllViews();
        if (homeHubComponent != null) {
            rootFrame.addView(homeHubComponent.getView());
        }
    }

    /**
     * Open Media Picker with specific configuration / Mở bộ chọn media với cấu hình cụ thể
     */
    private void openMediaPicker(int pickerMode, boolean forPip, boolean forReplace, boolean forPhotoOnly) {
        currentScreen = SCREEN_MEDIA_PICKER;
        this.isPickingForPhotoEditor = forPhotoOnly;
        this.isAddingPip = forPip;
        this.isReplacingClip = forReplace;
        this.isAddingToTimeline = !forPip && !forReplace && !forPhotoOnly && !activeProjectClips.isEmpty();

        String title;
        if (forPhotoOnly) {
            title = "Chọn Ảnh Biên Tập ▾";
        } else if (forPip) {
            title = "Thêm Lớp Phủ PIP ▾";
        } else if (forReplace) {
            title = "Thay Thế Clip ▾";
        } else if (isAddingToTimeline) {
            title = "Thêm Clip Nối Tiếp ▾";
        } else {
            title = "Dự Án Mới ▾";
            // Ensure truly empty project for new project creation (Rule E2 & Rule 14)
            // Khởi tạo dự án mới hoàn toàn trống, không nhồi sẵn clip mẫu vào timeline
            activeProjectClips.clear();
        }

        if (mediaPickerComponent != null) {
            mediaPickerComponent.open(title, pickerMode);
            rootFrame.removeAllViews();
            rootFrame.addView(mediaPickerComponent.getView());
        }
    }

    /**
     * Open Photo Editor Suite / Mở Trình Biên Tập Ảnh Chuyên Nghiệp
     */
    private void openPhotoEditor(MediaItem photoItem) {
        currentScreen = SCREEN_PHOTO_EDITOR;
        rootFrame.removeAllViews();
        if (photoEditorComponent != null) {
            photoEditorComponent.open(photoItem);
            rootFrame.addView(photoEditorComponent.getView());
        }
    }

    /**
     * Open Video Editor Suite / Mở Trình Biên Tập Video Đa Track C++20
     */
    private void openVideoEditor() {
        currentScreen = SCREEN_VIDEO_EDITOR;
        rootFrame.removeAllViews();
        if (videoEditorComponent != null) {
            videoEditorComponent.open();
            rootFrame.addView(videoEditorComponent.getView());
        }
    }

    /**
     * Switch bottom navigation tab / Chuyển đổi tab điều hướng đáy
     */
    public void switchTab(int tabIndex) {
        currentScreen = (tabIndex == 0) ? SCREEN_HOME : SCREEN_TAB;
        rootFrame.removeAllViews();
        switch (tabIndex) {
            case 0:
                showHome();
                break;
            case 1:
                if (templateComponent != null) rootFrame.addView(templateComponent.getView());
                break;
            case 2:
                if (cloudComponent != null) rootFrame.addView(cloudComponent.getView());
                break;
            case 3:
                if (aiLabComponent != null) rootFrame.addView(aiLabComponent.getView());
                break;
            case 4:
                if (profileComponent != null) rootFrame.addView(profileComponent.getView());
                break;
            default:
                showHome();
                break;
        }
    }

    /**
     * Safe Back Press Handler with Project Exit Confirmation (Fixes X5)
     * Xử lý phím Back an toàn với hộp thoại xác nhận khi đang trong trình biên tập video/ảnh
     */
    /**
     * Safe Back Press Handler with Project Exit Confirmation (Fixes X5)
     * Xử lý phím Back an toàn với hộp thoại xác nhận khi đang trong trình biên tập video/ảnh
     */
    @Override
    public void onBackPressed() {
        if (currentScreen == SCREEN_VIDEO_EDITOR) {
            new AlertDialog.Builder(this)
                .setTitle("⚠️ RỜI KHỎI DỰ ÁN?")
                .setMessage("Bạn có chắc muốn quay về Trang chủ không? Tiến trình biên tập video hiện tại vẫn được bảo lưu.")
                .setPositiveButton("RỜI KHỎI", new ExitProjectClickListener(this))
                .setNegativeButton("TIẾP TỤC BIÊN TẬP", null)
                .show();
            return;
        } else if (currentScreen == SCREEN_PHOTO_EDITOR) {
            new AlertDialog.Builder(this)
                .setTitle("⚠️ THOÁT BIÊN TẬP ẢNH?")
                .setMessage("Bạn có chắc muốn đóng trình biên tập ảnh không?")
                .setPositiveButton("THOÁT", new ExitPhotoClickListener(this))
                .setNegativeButton("TIẾP TỤC", null)
                .show();
            return;
        } else if (currentScreen == SCREEN_MEDIA_PICKER) {
            if (!activeProjectClips.isEmpty() && (isAddingToTimeline || isAddingPip || isReplacingClip)) {
                openVideoEditor();
            } else {
                showHome();
            }
            return;
        } else if (currentScreen == SCREEN_TAB) {
            showHome();
            return;
        }
        super.onBackPressed();
    }

    private static class ExitProjectClickListener implements DialogInterface.OnClickListener {
        private final MainActivity activity;
        public ExitProjectClickListener(MainActivity act) { this.activity = act; }
        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) activity.showHome();
        }
    }

    private static class ExitPhotoClickListener implements DialogInterface.OnClickListener {
        private final MainActivity activity;
        public ExitPhotoClickListener(MainActivity act) { this.activity = act; }
        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) activity.showHome();
        }
    }

    // =========================================================================
    // LISTENER IMPLEMENTATIONS / THỰC THI GIAO DIỆN LẮNG NGHE SỰ KIỆN
    // =========================================================================

    // 1. OnHomeActionListener
    @Override
    public void onNewProject() {
        openMediaPicker(0, false, false, false);
    }

    @Override
    public void onQuickTool(String toolKey, String label) {
        if ("photoedit".equals(toolKey)) {
            openMediaPicker(2, false, false, true);
        } else {
            Toast.makeText(this, "⚡ " + label, Toast.LENGTH_SHORT).show();
            openMediaPicker(0, false, false, false);
        }
    }

    @Override
    public void onDraft(int draftIndex, String draftTitle) {
        openVideoEditor();
    }

    @Override
    public void onVipBadge() {
        // Open VIP Paywall & Detain Retainment Machine
        // Mở màn hình Paywall gói VIP với thuật toán giữ chân khách hàng
        Intent intent = new Intent(this, SubscribeActivity.class);
        startActivity(intent);
    }

    @Override
    public void onBottomNav(int tabIndex) {
        switchTab(tabIndex);
    }

    @Override
    public void onTabSelected(int tabIndex) {
        switchTab(tabIndex);
    }

    // 2. OnMediaPickerListener
    @Override
    public void onMediaPickerClose() {
        if (!activeProjectClips.isEmpty() && (isAddingToTimeline || isAddingPip || isReplacingClip)) {
            openVideoEditor();
        } else {
            showHome();
        }
    }

    @Override
    public void onMediaPickerImport(List<MediaItem> selected) {
        if (selected == null || selected.isEmpty()) return;

        if (isPickingForPhotoEditor) {
            openPhotoEditor(selected.get(0));
            return;
        }

        if (isReplacingClip) {
            if (videoEditorComponent != null) {
                videoEditorComponent.replaceCurrentClip(selected.get(0));
            }
            openVideoEditor();
            return;
        }

        if (isAddingPip) {
            if (videoEditorComponent != null) {
                videoEditorComponent.addPipClips(selected);
            }
            openVideoEditor();
            return;
        }

        if (isAddingToTimeline) {
            if (videoEditorComponent != null) {
                videoEditorComponent.addClips(selected);
            }
            openVideoEditor();
            return;
        }

        // New Project / Dự Án Mới
        if (videoEditorComponent != null) {
            videoEditorComponent.open(selected);
        }
        openVideoEditor();
    }

    @Override
    public void onMediaPickerOpenSystemGallery() {
        openSystemGalleryPicker();
    }

    // 3. OnPhotoEditorListener
    @Override
    public void onPhotoEditorClose() {
        showHome();
    }

    @Override
    public void onPhotoEditorSaved(Bitmap bitmap, String filePath) {
        scanDeviceMedia();
    }

    // 4. OnVideoEditorListener
    @Override
    public void onVideoEditorClose() {
        showHome();
    }

    @Override
    public void onRequestMediaPicker(int pickerMode, boolean forPip, boolean forReplace) {
        openMediaPicker(pickerMode, forPip, forReplace, false);
    }

    @Override
    public void onVideoExported(File exportedFile) {
        scanDeviceMedia();
        Toast.makeText(this, "🎉 Đã xuất video chất lượng cao thành công: " + (exportedFile != null ? exportedFile.getName() : ""), Toast.LENGTH_LONG).show();
    }

    @Override
    public void onOpenPhotoEditor(MediaItem item) {
        openPhotoEditor(item);
    }

    // 5. TemplateComponent.OnTemplateActionListener
    @Override
    public void onApplyTemplate(int index, String title, String duration, String lut, String effect) {
        if (videoEditorComponent != null) {
            videoEditorComponent.applyTemplate(title, duration, lut, effect);
        }
        openVideoEditor();
    }



    // =========================================================================
    // SYSTEM GALLERY & PERMISSION HANDLING / XỬ LÝ ALBUM HỆ THỐNG VÀ QUYỀN
    // =========================================================================

    private void openSystemGalleryPicker() {
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("*/*");
        intent.putExtra(Intent.EXTRA_MIME_TYPES, new String[]{"image/*", "video/*"});
        intent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true);
        startActivityForResult(Intent.createChooser(intent, "Chọn Ảnh / Video Cho Dự Án"), REQUEST_CODE_SYSTEM_PICKER);
    }

    private boolean isVideoUri(Uri uri) {
        try {
            String mime = getContentResolver().getType(uri);
            if (mime != null) {
                return mime.startsWith("video");
            }
        } catch (Exception ignored) {}
        String path = uri.toString().toLowerCase();
        return path.endsWith(".mp4") || path.endsWith(".mkv") || path.endsWith(".mov") || path.endsWith(".avi") || path.contains("video");
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == REQUEST_CODE_SYSTEM_PICKER && resultCode == RESULT_OK && data != null) {
            selectedMediaItems.clear();

            if (data.getClipData() != null) {
                int count = data.getClipData().getItemCount();
                for (int i = 0; i < count; i++) {
                    android.content.ClipData.Item clipItem = data.getClipData().getItemAt(i);
                    if (clipItem == null) continue;
                    Uri uri = clipItem.getUri();
                    if (uri == null) continue;
                    try {
                        getContentResolver().takePersistableUriPermission(uri, Intent.FLAG_GRANT_READ_URI_PERMISSION);
                    } catch (Exception ignored) {}

                    boolean isVid = !isPickingForPhotoEditor && isVideoUri(uri);
                    String title = (isVid ? "Video Hệ Thống " : "Ảnh Hệ Thống ") + (i + 1);
                    MediaItem item = new MediaItem("saf_" + System.currentTimeMillis() + "_" + i, title, uri, isVid ? "00:15" : "00:05", isVid, Color.parseColor("#1E3A8A"), isVid ? "🎬" : "🖼️");
                    item.isSelected = true;
                    item.selectionIndex = selectedMediaItems.size() + 1;
                    selectedMediaItems.add(item);
                    allMediaItems.add(0, item);
                }
            } else if (data.getData() != null) {
                Uri uri = data.getData();
                if (uri != null) {
                    try {
                        getContentResolver().takePersistableUriPermission(uri, Intent.FLAG_GRANT_READ_URI_PERMISSION);
                    } catch (Exception ignored) {}

                    boolean isVid = !isPickingForPhotoEditor && isVideoUri(uri);
                    String title = isVid ? "Video Từ Thiết Bị" : "Ảnh Từ Thiết Bị";
                    MediaItem item = new MediaItem("saf_single_" + System.currentTimeMillis(), title, uri, isVid ? "00:20" : "00:05", isVid, Color.parseColor("#065F46"), isVid ? "🎬" : "🖼️");
                    item.isSelected = true;
                    item.selectionIndex = 1;
                    selectedMediaItems.add(item);
                    allMediaItems.add(0, item);
                }
            }

            onMediaPickerImport(selectedMediaItems);
        }
    }

    private boolean hasStoragePermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            return checkSelfPermission(Manifest.permission.READ_MEDIA_IMAGES) == PackageManager.PERMISSION_GRANTED &&
                   checkSelfPermission(Manifest.permission.READ_MEDIA_VIDEO) == PackageManager.PERMISSION_GRANTED;
        } else {
            return checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED;
        }
    }

    private void checkAndRequestStoragePermissions() {
        if (!hasStoragePermission()) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
                requestPermissions(new String[]{
                    Manifest.permission.READ_MEDIA_IMAGES,
                    Manifest.permission.READ_MEDIA_VIDEO
                }, PERMISSION_REQUEST_CODE);
            } else {
                requestPermissions(new String[]{
                    Manifest.permission.READ_EXTERNAL_STORAGE
                }, PERMISSION_REQUEST_CODE);
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == PERMISSION_REQUEST_CODE) {
            boolean granted = false;
            for (int res : grantResults) {
                if (res == PackageManager.PERMISSION_GRANTED) {
                    granted = true;
                    break;
                }
            }
            if (granted) {
                scanDeviceMedia();
                if (mediaPickerComponent != null) {
                    mediaPickerComponent.renderMediaPickerGrid();
                }
                Toast.makeText(this, "📁 Đã tải thư viện media từ máy thành công!", Toast.LENGTH_SHORT).show();
            }
        }
    }

    private void initMediaRepository() {
        allMediaItems.clear();
        // Start with a clean, empty active project (Rule E2 & Rule 14)
        // Khởi tạo dự án mới hoàn toàn trống, không nhồi sẵn clip mẫu vào dự án người dùng
        activeProjectClips.clear();
        if (hasStoragePermission()) {
            scanDeviceMedia();
        } else {
            addSampleMediaItemsFallback();
        }
    }

    /**
     * Scan device media asynchronously in background thread to prevent Main UI Thread ANR (Fixes D2)
     * Quét đa phương tiện thiết bị bất đồng bộ trên luồng nền để chống treo đơ giao diện chính (ANR)
     */
    private void scanDeviceMedia() {
        if (executor == null || executor.isShutdown()) return;
        executor.execute(new ScanMediaTask(this));
    }

    private void loadDeviceMediaInternal() {
        try {
            final List<MediaItem> realItems = new ArrayList<>();

            // 1. Scan Real Videos using try-with-resources (Fixes D2 Cursor Leak)
            // Quét video từ MediaStore dùng try-with-resources đóng con trỏ tự động
            String[] vidProjection = {
                MediaStore.Video.Media._ID,
                MediaStore.Video.Media.DISPLAY_NAME,
                MediaStore.Video.Media.DURATION,
                MediaStore.Video.Media.DATE_ADDED
            };
            try (Cursor vidCursor = getContentResolver().query(
                MediaStore.Video.Media.EXTERNAL_CONTENT_URI,
                vidProjection, null, null, MediaStore.Video.Media.DATE_ADDED + " DESC"
            )) {
                if (vidCursor != null) {
                    int vidCount = 0;
                    while (vidCursor.moveToNext() && vidCount < 100) {
                        long id = vidCursor.getLong(vidCursor.getColumnIndexOrThrow(MediaStore.Video.Media._ID));
                        String name = vidCursor.getString(vidCursor.getColumnIndexOrThrow(MediaStore.Video.Media.DISPLAY_NAME));
                        int durIdx = vidCursor.getColumnIndex(MediaStore.Video.Media.DURATION);
                        long durMs = durIdx >= 0 ? vidCursor.getLong(durIdx) : 10000;
                        int sec = (int) (durMs / 1000);
                        if (sec <= 0) sec = 5;
                        String duration = String.format(Locale.US, "%02d:%02d", sec / 60, sec % 60);
                        Uri uri = ContentUris.withAppendedId(MediaStore.Video.Media.EXTERNAL_CONTENT_URI, id);
                        realItems.add(new MediaItem("dev_vid_" + id, name != null ? name : ("Video " + id), uri, duration, true, Color.parseColor("#111827"), "🎬"));
                        vidCount++;
                    }
                }
            }

            // 2. Scan Real Photos using try-with-resources (Fixes D2 Cursor Leak)
            // Quét ảnh từ MediaStore dùng try-with-resources đóng con trỏ tự động
            String[] imgProjection = {
                MediaStore.Images.Media._ID,
                MediaStore.Images.Media.DISPLAY_NAME,
                MediaStore.Images.Media.DATE_ADDED
            };
            try (Cursor imgCursor = getContentResolver().query(
                MediaStore.Images.Media.EXTERNAL_CONTENT_URI,
                imgProjection, null, null, MediaStore.Images.Media.DATE_ADDED + " DESC"
            )) {
                if (imgCursor != null) {
                    int imgCount = 0;
                    while (imgCursor.moveToNext() && imgCount < 100) {
                        long id = imgCursor.getLong(imgCursor.getColumnIndexOrThrow(MediaStore.Images.Media._ID));
                        String name = imgCursor.getString(imgCursor.getColumnIndexOrThrow(MediaStore.Images.Media.DISPLAY_NAME));
                        Uri uri = ContentUris.withAppendedId(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, id);
                        realItems.add(new MediaItem("dev_img_" + id, name != null ? name : ("Ảnh " + id), uri, "00:05", false, Color.parseColor("#1F2937"), "🖼️"));
                        imgCount++;
                    }
                }
            }

            // Update media repository on Main UI thread without touching activeProjectClips (Fixes X4)
            // Cập nhật kho media trên luồng chính, tuyệt đối không can thiệp hay xóa đè activeProjectClips của người dùng
            runOnUiThread(new MediaLoadedCallback(this, realItems));
        } catch (Exception e) {
            e.printStackTrace();
            runOnUiThread(new SampleFallbackCallback(this));
        }
    }

    private static class ScanMediaTask implements Runnable {
        private final MainActivity activity;
        public ScanMediaTask(MainActivity act) { this.activity = act; }
        @Override
        public void run() {
            if (activity != null) activity.loadDeviceMediaInternal();
        }
    }

    private static class MediaLoadedCallback implements Runnable {
        private final MainActivity activity;
        private final List<MediaItem> realItems;
        public MediaLoadedCallback(MainActivity act, List<MediaItem> items) {
            this.activity = act;
            this.realItems = items;
        }
        @Override
        public void run() {
            if (activity == null) return;
            if (realItems != null && !realItems.isEmpty()) {
                activity.allMediaItems.clear();
                activity.allMediaItems.addAll(realItems);
                activity.addSampleMediaItemsFallback();
            } else if (activity.allMediaItems.isEmpty()) {
                activity.addSampleMediaItemsFallback();
            }
            if (activity.mediaPickerComponent != null) {
                activity.mediaPickerComponent.renderMediaPickerGrid();
            }
        }
    }

    private static class SampleFallbackCallback implements Runnable {
        private final MainActivity activity;
        public SampleFallbackCallback(MainActivity act) { this.activity = act; }
        @Override
        public void run() {
            if (activity != null && activity.allMediaItems.isEmpty()) {
                activity.addSampleMediaItemsFallback();
            }
        }
    }

    private void addSampleMediaItemsFallback() {
        allMediaItems.add(new MediaItem("samp_1", "Hoàng Hôn Mây Hồng 4K.mp4", null, "00:16", true, Color.parseColor("#7C2D12"), "🌅"));
        allMediaItems.add(new MediaItem("samp_2", "Mưa Rơi Cửa Kính Retro.mp4", null, "00:06", true, Color.parseColor("#1E293B"), "🌧️"));
        allMediaItems.add(new MediaItem("samp_3", "Vlog Du Lịch Đà Lạt 60fps.mp4", null, "00:32", true, Color.parseColor("#065F46"), "🌲"));
        allMediaItems.add(new MediaItem("samp_4", "TikTok Dance Neon Body.mp4", null, "00:15", true, Color.parseColor("#831843"), "💃"));
        allMediaItems.add(new MediaItem("samp_5", "Chân Dung Nghệ Thuật Studio.jpg", null, "00:05", false, Color.parseColor("#312E81"), "🖼️"));
        allMediaItems.add(new MediaItem("samp_6", "Thành Phố Cyberpunk Đêm.jpg", null, "00:05", false, Color.parseColor("#1E1B4B"), "🌆"));
        allMediaItems.add(new MediaItem("samp_7", "Bình Minh Biển Nha Trang.mp4", null, "00:24", true, Color.parseColor("#0E7490"), "🌊"));
        allMediaItems.add(new MediaItem("samp_8", "Vintage Retro 90s Film.jpg", null, "00:05", false, Color.parseColor("#78350F"), "📷"));
    }
}
