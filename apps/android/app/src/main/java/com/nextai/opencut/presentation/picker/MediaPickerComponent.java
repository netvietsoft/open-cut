package com.nextai.opencut.presentation.picker;

import android.app.Activity;
import android.content.ContentResolver;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.LruCache;
import android.util.Size;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;

import com.nextai.opencut.presentation.model.MediaItem;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * MediaPickerComponent — Thành Phần Trình Chọn Video & Hình Ảnh Dùng Chung (Standard Reusable Media Picker Component)
 * Tách biệt hoàn toàn logic chọn media, phân trang, lọc theo định dạng (Tất cả / Video / Ảnh),
 * tải thumbnail bất đồng bộ qua hàng đợi luồng, và gắn nhãn số thứ tự nhiều mục chọn (Multi-select numbering).
 *
 * Fully modularized picker handling format filters, multi-select numbering, async thumbnail rendering,
 * and decoupling UI interactions via {@link OnMediaPickerListener}.
 *
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class MediaPickerComponent implements View.OnClickListener {

    private final Activity activity;
    private final OnMediaPickerListener listener;
    private final List<MediaItem> allMediaItems;
    private final List<MediaItem> selectedMediaItems = new ArrayList<>();

    // UI Root and Sub-views
    private LinearLayout mediaPickerView;
    private TextView tvPickerTitle;
    private TextView btnPickerClose;
    private TextView btnPickerSystemGallery;
    private TextView tvPickerTabAll;
    private TextView tvPickerTabVideo;
    private TextView tvPickerTabPhoto;
    private LinearLayout pickerGridContent;
    private TextView tvPickerSelectedCount;
    private TextView btnPickerImport;

    // Filter Mode: 0: All, 1: Video, 2: Photo
    private int currentPickerFilter = 0;

    // Cache & Background Thumbnail Threading
    private final LruCache<String, Bitmap> thumbnailCache;
    private final ExecutorService thumbnailExecutor = Executors.newFixedThreadPool(4);
    private final Handler mainHandler = new Handler(Looper.getMainLooper());

    public MediaPickerComponent(Activity activity, List<MediaItem> allMediaItems, OnMediaPickerListener listener) {
        this.activity = activity;
        this.allMediaItems = allMediaItems;
        this.listener = listener;

        this.thumbnailCache = new LruCache<String, Bitmap>(80);

        buildView();
    }

    /**
     * Get the root view of the MediaPickerComponent
     * Lấy View gốc của thành phần chọn media để gắn vào View hierarchy
     */
    public View getView() {
        return mediaPickerView;
    }

    /**
     * Open Picker with custom title and filter mode
     * Mở giao diện chọn media với tiêu đề tùy biến và chế độ lọc định dạng
     *
     * @param title      Tiêu đề hiển thị trên thanh header (e.g. "Dự án mới ▾", "Chọn Ảnh Biên Tập ▾")
     * @param filterMode 0: All (Tất cả), 1: Video Only, 2: Photos Only
     */
    public void open(String title, int filterMode) {
        selectedMediaItems.clear();
        for (MediaItem mi : allMediaItems) {
            mi.isSelected = false;
            mi.selectionIndex = 0;
        }

        this.currentPickerFilter = filterMode;
        if (tvPickerTitle != null) {
            tvPickerTitle.setText(title);
        }

        updatePickerTabStyles();
        updatePickerSelectedBottomBar();
        renderMediaPickerGrid();
    }

    /**
     * Build Media Picker View Layout
     * Xây dựng toàn bộ giao diện phân tầng của Trình Chọn Media CapCut
     */
    private void buildView() {
        mediaPickerView = new LinearLayout(activity);
        mediaPickerView.setOrientation(LinearLayout.VERTICAL);
        mediaPickerView.setBackgroundColor(Color.parseColor("#090A0F"));
        mediaPickerView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // 1. Top Bar
        LinearLayout topBar = new LinearLayout(activity);
        topBar.setOrientation(LinearLayout.HORIZONTAL);
        topBar.setGravity(Gravity.CENTER_VERTICAL);
        topBar.setPadding(20, 24, 20, 16);
        topBar.setBackgroundColor(Color.parseColor("#12131A"));

        btnPickerClose = new TextView(activity);
        btnPickerClose.setText("✕");
        btnPickerClose.setTextColor(Color.WHITE);
        btnPickerClose.setTextSize(20);
        btnPickerClose.setPadding(24, 16, 24, 16);
        btnPickerClose.setMinimumWidth(80);
        btnPickerClose.setMinimumHeight(72);
        btnPickerClose.setGravity(Gravity.CENTER);
        btnPickerClose.setOnClickListener(this);
        topBar.addView(btnPickerClose);

        tvPickerTitle = new TextView(activity);
        tvPickerTitle.setText("Gần đây ▾");
        tvPickerTitle.setTextColor(Color.WHITE);
        tvPickerTitle.setTextSize(16);
        tvPickerTitle.setTypeface(null, Typeface.BOLD);
        LinearLayout.LayoutParams titleParams = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        topBar.addView(tvPickerTitle, titleParams);

        btnPickerSystemGallery = new TextView(activity);
        btnPickerSystemGallery.setText("📁 Mở Album Máy");
        btnPickerSystemGallery.setTextColor(Color.parseColor("#00E5FF"));
        btnPickerSystemGallery.setTextSize(12);
        btnPickerSystemGallery.setTypeface(null, Typeface.BOLD);
        btnPickerSystemGallery.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_picker_tab);
        btnPickerSystemGallery.setPadding(20, 10, 20, 10);
        btnPickerSystemGallery.setOnClickListener(this);
        topBar.addView(btnPickerSystemGallery);

        mediaPickerView.addView(topBar);

        // 2. Filter Tabs (Tất cả, Video, Hình ảnh)
        LinearLayout tabsBar = new LinearLayout(activity);
        tabsBar.setOrientation(LinearLayout.HORIZONTAL);
        tabsBar.setPadding(24, 16, 24, 16);
        tabsBar.setBackgroundColor(Color.parseColor("#0D0E14"));

        tvPickerTabAll = createPickerTab("Tất cả (All)", 0, tabsBar);
        tvPickerTabVideo = createPickerTab("Video", 1, tabsBar);
        tvPickerTabPhoto = createPickerTab("Hình ảnh (Photos)", 2, tabsBar);

        mediaPickerView.addView(tabsBar);

        // 3. Scrollable Media Grid
        ScrollView gridScroll = new ScrollView(activity);
        gridScroll.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 0, 1.0f));

        pickerGridContent = new LinearLayout(activity);
        pickerGridContent.setOrientation(LinearLayout.VERTICAL);
        pickerGridContent.setPadding(12, 12, 12, 24);
        gridScroll.addView(pickerGridContent);

        mediaPickerView.addView(gridScroll);

        // 4. Bottom Action Bar
        LinearLayout bottomBar = new LinearLayout(activity);
        bottomBar.setOrientation(LinearLayout.HORIZONTAL);
        bottomBar.setGravity(Gravity.CENTER_VERTICAL);
        bottomBar.setPadding(24, 16, 24, 20);
        bottomBar.setBackgroundColor(Color.parseColor("#12131A"));

        tvPickerSelectedCount = new TextView(activity);
        tvPickerSelectedCount.setText("Đã chọn: 0 mục");
        tvPickerSelectedCount.setTextColor(Color.parseColor("#94A3B8"));
        tvPickerSelectedCount.setTextSize(13);
        LinearLayout.LayoutParams cntParams = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        bottomBar.addView(tvPickerSelectedCount, cntParams);

        btnPickerImport = new TextView(activity);
        btnPickerImport.setText("Thêm (0)");
        btnPickerImport.setTextColor(Color.BLACK);
        btnPickerImport.setTextSize(14);
        btnPickerImport.setTypeface(null, Typeface.BOLD);
        btnPickerImport.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_import_btn);
        btnPickerImport.setPadding(40, 14, 40, 14);
        btnPickerImport.setOnClickListener(this);
        bottomBar.addView(btnPickerImport);

        mediaPickerView.addView(bottomBar);
    }

    private TextView createPickerTab(String label, int filterIndex, LinearLayout parent) {
        TextView tab = new TextView(activity);
        tab.setText(label);
        tab.setTextSize(13);
        tab.setPadding(28, 12, 28, 12);
        boolean isActive = (filterIndex == currentPickerFilter);
        tab.setTextColor(isActive ? Color.parseColor("#00E5FF") : Color.parseColor("#94A3B8"));
        tab.setTypeface(null, isActive ? Typeface.BOLD : Typeface.NORMAL);
        tab.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_picker_tab);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        params.setMargins(0, 0, 16, 0);
        tab.setLayoutParams(params);
        tab.setTag(Integer.valueOf(100 + filterIndex));
        tab.setOnClickListener(this);
        parent.addView(tab);
        return tab;
    }

    private void updatePickerTabStyles() {
        tvPickerTabAll.setTextColor(currentPickerFilter == 0 ? Color.parseColor("#00E5FF") : Color.parseColor("#94A3B8"));
        tvPickerTabAll.setTypeface(null, currentPickerFilter == 0 ? Typeface.BOLD : Typeface.NORMAL);

        tvPickerTabVideo.setTextColor(currentPickerFilter == 1 ? Color.parseColor("#00E5FF") : Color.parseColor("#94A3B8"));
        tvPickerTabVideo.setTypeface(null, currentPickerFilter == 1 ? Typeface.BOLD : Typeface.NORMAL);

        tvPickerTabPhoto.setTextColor(currentPickerFilter == 2 ? Color.parseColor("#00E5FF") : Color.parseColor("#94A3B8"));
        tvPickerTabPhoto.setTypeface(null, currentPickerFilter == 2 ? Typeface.BOLD : Typeface.NORMAL);
    }

    /**
     * Render Media Grid with 3 columns
     * Dựng lưới danh sách Media 3 cột theo chuẩn giao diện CapCut
     */
    public void renderMediaPickerGrid() {
        pickerGridContent.removeAllViews();

        List<MediaItem> filtered = new ArrayList<>();
        for (MediaItem item : allMediaItems) {
            if (currentPickerFilter == 1 && !item.isVideo) continue;
            if (currentPickerFilter == 2 && item.isVideo) continue;
            filtered.add(item);
        }

        LinearLayout currentRow = null;
        for (int i = 0; i < filtered.size(); i++) {
            if (i % 3 == 0) {
                currentRow = new LinearLayout(activity);
                currentRow.setOrientation(LinearLayout.HORIZONTAL);
                currentRow.setPadding(0, 0, 0, 8);
                pickerGridContent.addView(currentRow);
            }

            MediaItem item = filtered.get(i);
            View tile = createMediaGridTile(item);
            currentRow.addView(tile);
        }

        if (currentRow != null && filtered.size() % 3 != 0) {
            int remaining = 3 - (filtered.size() % 3);
            for (int k = 0; k < remaining; k++) {
                View empty = new View(activity);
                LinearLayout.LayoutParams ep = new LinearLayout.LayoutParams(0, 200, 1.0f);
                ep.setMargins(4, 0, 4, 0);
                empty.setLayoutParams(ep);
                currentRow.addView(empty);
            }
        }

        updatePickerSelectedBottomBar();
    }

    private View createMediaGridTile(final MediaItem item) {
        FrameLayout tile = new FrameLayout(activity);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(0, 230, 1.0f);
        params.setMargins(4, 0, 4, 0);
        tile.setLayoutParams(params);
        tile.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_media_card);

        final ImageView ivThumb = new ImageView(activity);
        ivThumb.setScaleType(ImageView.ScaleType.CENTER_CROP);
        tile.addView(ivThumb, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        // Load Real Thumbnail Asynchronously / Nạp Thumbnail Thật Từ MediaStore Thiết Bị
        if (item.thumbnailBitmap != null) {
            ivThumb.setImageBitmap(item.thumbnailBitmap);
        } else if (item.uri != null) {
            Bitmap cached = thumbnailCache.get(item.id);
            if (cached != null) {
                item.thumbnailBitmap = cached;
                ivThumb.setImageBitmap(cached);
            } else {
                ivThumb.setBackgroundColor(item.colorBg);
                thumbnailExecutor.execute(new ThumbnailLoadTask(activity.getContentResolver(), thumbnailCache, mainHandler, item, ivThumb));
            }
        } else {
            ivThumb.setBackgroundColor(item.colorBg);
            TextView tvSampleIcon = new TextView(activity);
            tvSampleIcon.setText(item.icon);
            tvSampleIcon.setTextSize(26);
            tvSampleIcon.setGravity(Gravity.CENTER);
            tile.addView(tvSampleIcon, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));
        }

        // Dark gradient shadow at bottom for text readability
        View shadow = new View(activity);
        shadow.setBackgroundColor(Color.parseColor("#44000000"));
        tile.addView(shadow, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        // Media Title Label
        TextView tvTitle = new TextView(activity);
        tvTitle.setText(item.title);
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(9);
        tvTitle.setEllipsize(android.text.TextUtils.TruncateAt.END);
        tvTitle.setSingleLine(true);
        tvTitle.setPadding(8, 0, 8, 4);
        FrameLayout.LayoutParams titleParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.BOTTOM);
        titleParams.setMargins(0, 0, 0, 20);
        tile.addView(tvTitle, titleParams);

        // Duration / Type Badge
        TextView tvDur = new TextView(activity);
        tvDur.setText((item.isVideo ? "▶ " : "🖼️ ") + item.duration);
        tvDur.setTextColor(Color.WHITE);
        tvDur.setTextSize(8);
        tvDur.setBackgroundColor(Color.parseColor("#99000000"));
        tvDur.setPadding(8, 2, 8, 2);
        FrameLayout.LayoutParams durParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.BOTTOM | Gravity.END);
        durParams.setMargins(0, 0, 4, 4);
        tile.addView(tvDur, durParams);

        // Checkmark badge
        TextView tvCheck = new TextView(activity);
        FrameLayout.LayoutParams checkParams = new FrameLayout.LayoutParams(48, 48, Gravity.TOP | Gravity.END);
        checkParams.setMargins(0, 8, 8, 0);
        tvCheck.setLayoutParams(checkParams);
        tvCheck.setGravity(Gravity.CENTER);
        tvCheck.setTextSize(11);
        tvCheck.setTypeface(null, Typeface.BOLD);

        if (item.isSelected) {
            tvCheck.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_circle_check);
            tvCheck.setText(String.valueOf(item.selectionIndex));
            tvCheck.setTextColor(Color.BLACK);
        } else {
            tvCheck.setBackgroundColor(Color.parseColor("#44FFFFFF"));
            tvCheck.setText("");
        }
        tile.addView(tvCheck);

        tile.setTag(item);
        tile.setOnClickListener(this);
        return tile;
    }

    private void updatePickerSelectedBottomBar() {
        int count = selectedMediaItems.size();
        tvPickerSelectedCount.setText("Đã chọn: " + count + " mục");
        btnPickerImport.setText("Thêm (" + count + ")");
        btnPickerImport.setEnabled(count > 0);
        btnPickerImport.setAlpha(count > 0 ? 1.0f : 0.5f);
    }

    @Override
    public void onClick(View v) {
        if (v == btnPickerClose) {
            if (listener != null) {
                listener.onMediaPickerClose();
            }
            return;
        }

        if (v == btnPickerSystemGallery) {
            if (listener != null) {
                listener.onMediaPickerOpenSystemGallery();
            }
            return;
        }

        if (v == btnPickerImport) {
            if (listener != null) {
                listener.onMediaPickerImport(new ArrayList<>(selectedMediaItems));
            }
            return;
        }

        // Tab selection (Tags 100, 101, 102)
        Object tag = v.getTag();
        if (tag instanceof Integer) {
            int tagVal = (Integer) tag;
            if (tagVal >= 100 && tagVal <= 102) {
                currentPickerFilter = tagVal - 100;
                updatePickerTabStyles();
                renderMediaPickerGrid();
                return;
            }
        }

        // Grid Tile selection
        if (tag instanceof MediaItem) {
            MediaItem item = (MediaItem) tag;
            item.isSelected = !item.isSelected;
            if (item.isSelected) {
                selectedMediaItems.add(item);
                item.selectionIndex = selectedMediaItems.size();
            } else {
                selectedMediaItems.remove(item);
                item.selectionIndex = 0;
                for (int idx = 0; idx < selectedMediaItems.size(); idx++) {
                    selectedMediaItems.get(idx).selectionIndex = idx + 1;
                }
            }
            renderMediaPickerGrid();
        }
    }

    /**
     * Background Thumbnail Loader Task
     * Tác Vụ Tải Thumbnail Bất Đồng Bộ
     */
    private static class ThumbnailLoadTask implements Runnable {
        private final ContentResolver contentResolver;
        private final LruCache<String, Bitmap> cache;
        private final Handler handler;
        private final MediaItem item;
        private final ImageView ivThumb;

        public ThumbnailLoadTask(ContentResolver cr, LruCache<String, Bitmap> cache, Handler handler, MediaItem item, ImageView ivThumb) {
            this.contentResolver = cr;
            this.cache = cache;
            this.handler = handler;
            this.item = item;
            this.ivThumb = ivThumb;
        }

        @Override
        public void run() {
            if (item.uri == null) return;
            Bitmap loaded = null;
            try {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
                    loaded = contentResolver.loadThumbnail(item.uri, new Size(200, 200), null);
                } else {
                    InputStream is = contentResolver.openInputStream(item.uri);
                    BitmapFactory.Options opts = new BitmapFactory.Options();
                    opts.inSampleSize = 4;
                    loaded = BitmapFactory.decodeStream(is, null, opts);
                    if (is != null) is.close();
                }
            } catch (Throwable ignored) {}

            if (loaded != null) {
                final Bitmap finalBm = loaded;
                cache.put(item.id, finalBm);
                item.thumbnailBitmap = finalBm;
                handler.post(new ThumbnailApplyRunnable(ivThumb, finalBm));
            }
        }
    }

    private static class ThumbnailApplyRunnable implements Runnable {
        private final ImageView ivThumb;
        private final Bitmap bm;

        public ThumbnailApplyRunnable(ImageView ivThumb, Bitmap bm) {
            this.ivThumb = ivThumb;
            this.bm = bm;
        }

        @Override
        public void run() {
            ivThumb.setImageBitmap(bm);
        }
    }
}
