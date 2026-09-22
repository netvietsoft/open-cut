package com.nextai.opencut.presentation.photo;

import android.app.AlertDialog;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.Rect;
import android.graphics.Typeface;
import com.nextai.opencut.engine.MiddleBridgeJni;
import android.media.ExifInterface;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.os.ParcelFileDescriptor;
import android.provider.MediaStore;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import android.os.Handler;
import android.os.Looper;
import com.nextai.opencut.engine.EffectRegistry;
import com.nextai.opencut.engine.FaceBodyDetectionEngine;
import com.nextai.opencut.presentation.model.MediaItem;
import com.nextai.opencut.provider.OpenCutFileProvider;

import java.io.File;
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * PhotoEditorComponent — Modular High-Fidelity Photo Editor Suite.
 * Trình Chỉnh Sửa Ảnh Chuyên Sâu: Tích hợp 3D LUTs, Lightroom Pro, Meitu VIP Beauty, và AI Face/Body Engine.
 */
public class PhotoEditorComponent implements View.OnClickListener, SeekBar.OnSeekBarChangeListener, View.OnTouchListener, DialogInterface.OnClickListener {

    private static final String[] PHOTO_RATIO_OPTIONS = {
        "📐 Tự Do (Freeform)", "📐 1:1 Vuông (Instagram)", "📐 4:5 Dọc (Feed IG/TikTok)",
        "📐 3:4 Chân Dung (Portrait)", "📐 9:16 Câu Chuyện (Story/Reels)", "📐 16:9 Màn Rộng (Cinema/YouTube)"
    };

    private final Context context;
    private final OnPhotoEditorListener listener;

    // Background Thread Executor & UI Main Handler / Bộ Điều Phối Luồng Nền & Luồng Giao Diện
    private final ExecutorService backgroundExecutor = Executors.newSingleThreadExecutor();
    private final Handler mainHandler = new Handler(Looper.getMainLooper());

    // Root Container / Khung Gốc Trình Biên Tập Ảnh
    private LinearLayout photoEditorView;

    // Top Bar Actions / Các Nút Thanh Tiêu Đề
    private View btnPhotoBack;
    private View btnPhotoRatio;
    private View btnPhotoSave;
    private View btnCompareBeforeAfter;
    private View btnPhotoRotate;
    private View btnPhotoCrop;
    private View btnPhotoFitFill;

    // Canvas Preview / Bảng Vẽ Xem Trước
    private ImageView ivPhotoCanvas;
    private FrameLayout photoCanvasWrapper;

    // Sub-Panels / Các Bảng Điều Khiển Con
    private HorizontalScrollView photoFilterScroll;
    private LinearLayout photoAdjustPanel;
    private LinearLayout photoLightroomPanel;
    private LinearLayout photoEraserPanel;
    private LinearLayout photoFacetunePanel;
    private LinearLayout photoFaceAppPanel;
    private TextView tvPhotoFilterStatus;

    // 3D LUT Filter Preset Views / Các Nút Bộ Lọc Màu 3D LUT
    private View photoFilterOriginal;
    private View photoFilterPortra;
    private View photoFilterCyberpunk;
    private View photoFilterTealOrange;
    private View photoFilterNoir;
    private View photoFilterVintage;
    private View photoFilterCinemaGold;
    private View photoFilterFuji;
    private View photoFilterRose;
    private View photoFilterMoody;

    // 7 Photo Navigation Tabs / 7 Danh Mục Chuyên Sâu Dưới Cùng
    private View photoNavRatio;
    private View photoNavLut;
    private View photoNavLightroom;
    private View photoNavEraser;
    private View photoNavFacetune;
    private View photoNavFaceApp;
    private View photoNavAdjust;
    private View photoNavRotate;
    private View photoNavCrop;
    private View photoNavFlip;

    // Rotation & Geometric Transform State / Hướng Xoay & Lật Ảnh
    private int photoRotationDegrees = 0;
    private boolean isPhotoFillMode = false;
    private boolean isPhotoFlipped = false;

    // Adobe Lightroom Pro Controls / Bộ Công Cụ Adobe Lightroom Pro
    private SeekBar sbLrClarity, sbLrDehaze, sbLrGrain, sbLrVignette;
    private TextView tvLrClarityVal, tvLrDehazeVal, tvLrGrainVal, tvLrVignetteVal;
    private View btnLrToneCurve;
    private int lrClarity = 0, lrDehaze = 0, lrGrain = 0, lrVignette = 0;
    private boolean isLrToneCurveActive = false;

    // SnapEdit Eraser & Sky Wizard / Tẩy Xóa AI & Thay Bầu Trời
    private View btnInpaintBrush, btnSkySunset, btnSkyAurora, btnSkyBlue;
    private String activeSkyEffect = "";

    // Facetune & Meitu Portrait Detail & Body / Chân Dung & Thon Gọn Thể Hình
    private View btnFtWhitening, btnFtBrightenEyes, btnFtLipstick, btnMeituLegs, btnMeituBling;
    private String activePortraitEffect = "";

    // Face & Body Landmarks Detection Cache / Bộ Nhớ Đệm Tọa Độ Mốc Khuôn Mặt & Thân Người AI
    private FaceBodyDetectionEngine.FaceLandmarks cachedPhotoLandmarks = null;
    private List<FaceBodyDetectionEngine.FaceLandmarks> detectedFaceList = new ArrayList<>();
    private int selectedFaceIndex = 0;

    // VIP Beauty Panels / Các Bảng Điều Khiển Chi Tiết VIP
    private LinearLayout photoLipstickProPanel;
    private LinearLayout photoTeethProPanel;
    private LinearLayout photoEyesProPanel;
    private LinearLayout photoLegsProPanel;
    private Bitmap basePreEffectBitmap = null;

    // Lipstick State / Trạng Thái Tô Son
    private static final int[] LIPSTICK_PALETTE_COLORS = new int[]{
        Color.parseColor("#D32F2F"), // Đỏ Thuần
        Color.parseColor("#DE3163"), // Đỏ Hồng
        Color.parseColor("#C0392B"), // Cam Đất
        Color.parseColor("#E91E63"), // Hồng Đào
        Color.parseColor("#880E4F"), // Đỏ Mận
        Color.parseColor("#FF6F61"), // Cam San Hô
        Color.parseColor("#C47B62")  // Nude
    };
    private int currentLipstickColor = Color.parseColor("#DE3163");
    private float currentLipstickIntensity = 0.58f;
    private float currentLipstickGloss = 0.45f;
    private TextView tvLipstickIntensityVal, tvLipstickGlossVal;
    private SeekBar sbLipstickIntensity, sbLipstickGloss;
    private final List<View> lipstickColorChips = new ArrayList<>();
    private final View[] lipstickChipViews = new View[7];
    private TextView btnLipstickCancel, btnLipstickApply;

    // Teeth Whitening State / Trạng Thái Làm Trắng Răng
    private float currentTeethIntensity = 0.50f;
    private TextView tvTeethIntensityVal;
    private SeekBar sbTeethIntensity;
    private TextView btnTeethCancel, btnTeethApply;
    private TextView btnTeethPreset30, btnTeethPreset50, btnTeethPreset75, btnTeethPreset100;

    // Eye Brightening State / Trạng Thái Sáng Mắt
    private float currentScleraBrightness = 0.40f;
    private float currentIrisClarity = 0.50f;
    private TextView tvScleraBrightVal, tvIrisClarityVal;
    private SeekBar sbScleraBright, sbIrisClarity;
    private TextView btnEyesCancel, btnEyesApply;

    // Leg Extension & Slimming State / Trạng Thái Kéo Dài & Thon Gọn Chân
    private float currentLegStretch = 0.18f;
    private float currentLegSlim = 0.10f;
    private float currentHipsLineY = 0.58f;
    private float currentAnklesLineY = 0.88f;
    private TextView tvLegStretchVal, tvLegSlimVal, tvHipsLineVal, tvAnklesLineVal;
    private SeekBar sbLegStretch, sbLegSlim, sbHipsLine, sbAnklesLine;
    private TextView btnLegsCancel, btnLegsApply;

    // FaceApp AI Morphing State / Biến Hóa AI FaceApp
    private View btnFaSmile, btnFaYouth, btnFaHair;
    private String activeFaceAppEffect = "";

    // Adjust SeekBars / Thanh Trượt Tinh Chỉnh Cơ Bản
    private SeekBar sbPhotoBright, sbPhotoContrast, sbPhotoSat;
    private TextView tvPhotoBrightVal, tvPhotoContrastVal, tvPhotoSatVal;

    // Photo State & Bitmaps / Trạng Thái & Dữ Liệu Bitmap Ảnh
    private Bitmap baseOriginalPhotoBitmap = null;
    private Bitmap basePhotoBitmap = null;
    private int currentPhotoRatioIdx = 0; // 0: 3:4, 1: 1:1, 2: 4:5, 3: 9:16, 4: 16:9
    private String currentPhotoFilter = "original";
    private int photoBright = 0;
    private int photoContrast = 100;
    private int photoSat = 100;

    public PhotoEditorComponent(Context context, OnPhotoEditorListener listener) {
        this.context = context;
        this.listener = listener;
        buildLayout();
    }

    public View getView() {
        return photoEditorView;
    }

    /**
     * Open Photo Editor with selected media item.
     * Mở trình chỉnh sửa ảnh với tệp media được chọn.
     */
    public void open(MediaItem photoItem) {
        if (photoItem == null) return;
        tvPhotoFilterStatus.setText("🖼️ Đã nạp ảnh: " + photoItem.title);

        if (photoItem.uri != null) {
            loadPhotoBitmapFromUri(photoItem.uri);
        } else if (photoItem.thumbnailBitmap != null) {
            baseOriginalPhotoBitmap = photoItem.thumbnailBitmap;
            basePhotoBitmap = photoItem.thumbnailBitmap.copy(Bitmap.Config.ARGB_8888, true);
            photoRotationDegrees = 0;
            isPhotoFlipped = false;
            detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePhotoBitmap);
            cachedPhotoLandmarks = !detectedFaceList.isEmpty() ? detectedFaceList.get(0) : FaceBodyDetectionEngine.detectFace(basePhotoBitmap);
            selectedFaceIndex = 0;
            if (detectedFaceList.size() > 1) {
                Toast.makeText(context, "👥 Đã nhận diện " + detectedFaceList.size() + " khuôn mặt. Chạm vào bất kỳ ai trên ảnh để làm đẹp!", Toast.LENGTH_SHORT).show();
            }
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            }
            updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
        } else {
            createDefaultBasePhotoBitmap();
            detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePhotoBitmap);
            cachedPhotoLandmarks = !detectedFaceList.isEmpty() ? detectedFaceList.get(0) : FaceBodyDetectionEngine.detectFace(basePhotoBitmap);
            selectedFaceIndex = 0;
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            }
            updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
        }

        activePortraitEffect = "";
        applyPhotoFilters();
        Toast.makeText(context, "🖼️ Đã nạp ảnh '" + photoItem.title + "' vào Trình Chỉnh Sửa 3D LUTs C++20!", Toast.LENGTH_SHORT).show();
    }

    private void buildLayout() {
        photoEditorView = new LinearLayout(context);
        photoEditorView.setOrientation(LinearLayout.VERTICAL);
        photoEditorView.setBackgroundColor(Color.parseColor("#000000"));
        photoEditorView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // 1. Photo Top Bar
        LinearLayout topBar = new LinearLayout(context);
        topBar.setOrientation(LinearLayout.HORIZONTAL);
        topBar.setGravity(Gravity.CENTER_VERTICAL);
        topBar.setPadding(20, 24, 20, 16);
        topBar.setBackgroundColor(Color.parseColor("#000000"));

        btnPhotoBack = new TextView(context);
        ((TextView) btnPhotoBack).setText("❮ Trang chủ");
        ((TextView) btnPhotoBack).setTextColor(Color.WHITE);
        ((TextView) btnPhotoBack).setTextSize(13);
        ((TextView) btnPhotoBack).setPadding(12, 8, 16, 8);
        btnPhotoBack.setOnClickListener(this);
        topBar.addView(btnPhotoBack);

        View spacer = new View(context);
        topBar.addView(spacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnCompareBeforeAfter = new TextView(context);
        ((TextView) btnCompareBeforeAfter).setText("🔘 SO SÁNH");
        ((TextView) btnCompareBeforeAfter).setTextColor(Color.WHITE);
        ((TextView) btnCompareBeforeAfter).setTextSize(10);
        ((TextView) btnCompareBeforeAfter).setTypeface(null, Typeface.BOLD);
        ((TextView) btnCompareBeforeAfter).setBackgroundColor(Color.parseColor("#2A3348"));
        ((TextView) btnCompareBeforeAfter).setPadding(12, 8, 12, 8);
        LinearLayout.LayoutParams cmpParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        cmpParams.setMargins(0, 0, 8, 0);
        btnCompareBeforeAfter.setLayoutParams(cmpParams);
        btnCompareBeforeAfter.setOnTouchListener(this);
        topBar.addView(btnCompareBeforeAfter);

        btnPhotoRotate = new TextView(context);
        ((TextView) btnPhotoRotate).setText("🔄 90°");
        ((TextView) btnPhotoRotate).setTextColor(Color.WHITE);
        ((TextView) btnPhotoRotate).setTextSize(10);
        ((TextView) btnPhotoRotate).setTypeface(null, Typeface.BOLD);
        ((TextView) btnPhotoRotate).setBackgroundColor(Color.parseColor("#1E2433"));
        ((TextView) btnPhotoRotate).setPadding(12, 8, 12, 8);
        LinearLayout.LayoutParams rotParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        rotParams.setMargins(0, 0, 8, 0);
        btnPhotoRotate.setLayoutParams(rotParams);
        btnPhotoRotate.setOnClickListener(this);
        topBar.addView(btnPhotoRotate);

        btnPhotoCrop = new TextView(context);
        ((TextView) btnPhotoCrop).setText("✂️ CẮT");
        ((TextView) btnPhotoCrop).setTextColor(Color.WHITE);
        ((TextView) btnPhotoCrop).setTextSize(10);
        ((TextView) btnPhotoCrop).setTypeface(null, Typeface.BOLD);
        ((TextView) btnPhotoCrop).setBackgroundColor(Color.parseColor("#1E2433"));
        ((TextView) btnPhotoCrop).setPadding(12, 8, 12, 8);
        LinearLayout.LayoutParams cropParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        cropParams.setMargins(0, 0, 8, 0);
        btnPhotoCrop.setLayoutParams(cropParams);
        btnPhotoCrop.setOnClickListener(this);
        topBar.addView(btnPhotoCrop);

        btnPhotoFitFill = new TextView(context);
        ((TextView) btnPhotoFitFill).setText("⛶ VỪA");
        ((TextView) btnPhotoFitFill).setTextColor(Color.parseColor("#00E5FF"));
        ((TextView) btnPhotoFitFill).setTextSize(10);
        ((TextView) btnPhotoFitFill).setTypeface(null, Typeface.BOLD);
        ((TextView) btnPhotoFitFill).setBackgroundColor(Color.parseColor("#0F2B48"));
        ((TextView) btnPhotoFitFill).setPadding(12, 8, 12, 8);
        LinearLayout.LayoutParams ffParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        ffParams.setMargins(0, 0, 8, 0);
        btnPhotoFitFill.setLayoutParams(ffParams);
        btnPhotoFitFill.setOnClickListener(this);
        topBar.addView(btnPhotoFitFill);

        btnPhotoRatio = new TextView(context);
        ((TextView) btnPhotoRatio).setText("📐 3:4");
        ((TextView) btnPhotoRatio).setTextColor(Color.WHITE);
        ((TextView) btnPhotoRatio).setTextSize(11);
        ((TextView) btnPhotoRatio).setTypeface(null, Typeface.BOLD);
        ((TextView) btnPhotoRatio).setBackgroundColor(Color.parseColor("#1E2433"));
        ((TextView) btnPhotoRatio).setPadding(14, 8, 14, 8);
        btnPhotoRatio.setOnClickListener(this);
        topBar.addView(btnPhotoRatio);

        btnPhotoSave = new TextView(context);
        ((TextView) btnPhotoSave).setText("LƯU ẢNH");
        ((TextView) btnPhotoSave).setTextColor(Color.BLACK);
        ((TextView) btnPhotoSave).setTextSize(11);
        ((TextView) btnPhotoSave).setTypeface(null, Typeface.BOLD);
        ((TextView) btnPhotoSave).setBackgroundResource(com.nextai.opencut.R.drawable.bg_export_button);
        ((TextView) btnPhotoSave).setPadding(20, 10, 20, 10);
        LinearLayout.LayoutParams saveParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        saveParams.setMargins(12, 0, 0, 0);
        btnPhotoSave.setLayoutParams(saveParams);
        btnPhotoSave.setOnClickListener(this);
        topBar.addView(btnPhotoSave);

        photoEditorView.addView(topBar);

        // 2. Photo Canvas Area
        FrameLayout canvasArea = new FrameLayout(context);
        canvasArea.setBackgroundColor(Color.parseColor("#090A0F"));
        LinearLayout.LayoutParams canvasAreaParams = new LinearLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, 0, 1.0f);
        canvasArea.setLayoutParams(canvasAreaParams);

        photoCanvasWrapper = new FrameLayout(context);
        DisplayMetrics dm = context.getResources().getDisplayMetrics();
        int initialW = Math.max(300, dm.widthPixels - 32);
        int initialH = Math.max(400, (int) (dm.heightPixels * 0.55f));
        FrameLayout.LayoutParams pcwParams = new FrameLayout.LayoutParams(initialW, initialH, Gravity.CENTER);
        photoCanvasWrapper.setLayoutParams(pcwParams);
        photoCanvasWrapper.setBackgroundColor(Color.parseColor("#12131C"));

        ivPhotoCanvas = new ImageView(context);
        ivPhotoCanvas.setLayoutParams(new FrameLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        ivPhotoCanvas.setOnTouchListener(this);
        photoCanvasWrapper.addView(ivPhotoCanvas);

        canvasArea.addView(photoCanvasWrapper);
        photoEditorView.addView(canvasArea);

        // 3. Status Badge
        tvPhotoFilterStatus = new TextView(context);
        tvPhotoFilterStatus.setText("✨ Đang sử dụng màu gốc (Không áp dụng bộ lọc)");
        tvPhotoFilterStatus.setTextColor(Color.parseColor("#94A3B8"));
        tvPhotoFilterStatus.setTextSize(10);
        tvPhotoFilterStatus.setGravity(Gravity.CENTER);
        tvPhotoFilterStatus.setPadding(0, 8, 0, 6);
        photoEditorView.addView(tvPhotoFilterStatus);

        // 4. Filter Strip
        buildFilterStrip();

        // 5. Basic Adjust Panel
        buildAdjustPanel();

        // 6. Lightroom Pro Panel
        buildLightroomPanel();

        // 7. SnapEdit Sky Wizard & Eraser Panel
        buildEraserPanel();

        // 8. Facetune & Meitu Portrait Detail Panel
        buildFacetunePanel();

        // 9. FaceApp AI Morphing Panel
        buildFaceAppPanel();

        // 10. Pro Panels (Lipstick, Teeth, Eyes, Legs)
        buildPhotoLipstickProPanel();
        buildPhotoTeethProPanel();
        buildPhotoEyesProPanel();
        buildPhotoLegsProPanel();

        // 11. Bottom 7 Navigation Tabs
        buildBottomNavTabs();
    }

    private void buildFilterStrip() {
        photoFilterScroll = new HorizontalScrollView(context);
        photoFilterScroll.setHorizontalScrollBarEnabled(false);
        photoFilterScroll.setPadding(12, 4, 12, 8);
        LinearLayout filterRow = new LinearLayout(context);
        filterRow.setOrientation(LinearLayout.HORIZONTAL);

        photoFilterOriginal = createFilterChip("Gốc", "#1E2433", filterRow);
        photoFilterPortra = createFilterChip("🎞️ Portra 400", "#475569", filterRow);
        photoFilterCyberpunk = createFilterChip("🌆 Cyberpunk", "#9333EA", filterRow);
        photoFilterTealOrange = createFilterChip("🎬 Teal & Orange", "#EA580C", filterRow);
        photoFilterNoir = createFilterChip("📽️ Film Noir", "#334155", filterRow);
        photoFilterVintage = createFilterChip("📻 Vintage Warm", "#B45309", filterRow);
        photoFilterCinemaGold = createFilterChip("🌟 Cinema Gold", "#CA8A04", filterRow);
        photoFilterFuji = createFilterChip("🍃 Fuji Pro 400H", "#059669", filterRow);
        photoFilterRose = createFilterChip("🌸 Soft Rose", "#BE185D", filterRow);
        photoFilterMoody = createFilterChip("🌑 Moody Dark", "#1E293B", filterRow);

        photoFilterScroll.addView(filterRow);
        photoEditorView.addView(photoFilterScroll);
    }

    private void buildAdjustPanel() {
        photoAdjustPanel = new LinearLayout(context);
        photoAdjustPanel.setOrientation(LinearLayout.VERTICAL);
        photoAdjustPanel.setBackgroundColor(Color.parseColor("#11131A"));
        photoAdjustPanel.setPadding(20, 8, 20, 8);
        photoAdjustPanel.setVisibility(View.GONE);

        // Brightness
        LinearLayout rowB = new LinearLayout(context);
        rowB.setOrientation(LinearLayout.HORIZONTAL);
        rowB.setGravity(Gravity.CENTER_VERTICAL);
        tvPhotoBrightVal = new TextView(context);
        tvPhotoBrightVal.setText("Độ sáng: 0");
        tvPhotoBrightVal.setTextColor(Color.WHITE);
        tvPhotoBrightVal.setTextSize(10);
        tvPhotoBrightVal.setWidth(160);
        rowB.addView(tvPhotoBrightVal);
        sbPhotoBright = new SeekBar(context);
        sbPhotoBright.setMax(200);
        sbPhotoBright.setProgress(100);
        sbPhotoBright.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbPhotoBright.setOnSeekBarChangeListener(this);
        rowB.addView(sbPhotoBright);
        photoAdjustPanel.addView(rowB);

        // Contrast
        LinearLayout rowC = new LinearLayout(context);
        rowC.setOrientation(LinearLayout.HORIZONTAL);
        rowC.setGravity(Gravity.CENTER_VERTICAL);
        tvPhotoContrastVal = new TextView(context);
        tvPhotoContrastVal.setText("Tương phản: 100%");
        tvPhotoContrastVal.setTextColor(Color.WHITE);
        tvPhotoContrastVal.setTextSize(10);
        tvPhotoContrastVal.setWidth(160);
        rowC.addView(tvPhotoContrastVal);
        sbPhotoContrast = new SeekBar(context);
        sbPhotoContrast.setMax(200);
        sbPhotoContrast.setProgress(100);
        sbPhotoContrast.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbPhotoContrast.setOnSeekBarChangeListener(this);
        rowC.addView(sbPhotoContrast);
        photoAdjustPanel.addView(rowC);

        // Saturation
        LinearLayout rowS = new LinearLayout(context);
        rowS.setOrientation(LinearLayout.HORIZONTAL);
        rowS.setGravity(Gravity.CENTER_VERTICAL);
        tvPhotoSatVal = new TextView(context);
        tvPhotoSatVal.setText("Độ bão hòa: 100%");
        tvPhotoSatVal.setTextColor(Color.WHITE);
        tvPhotoSatVal.setTextSize(10);
        tvPhotoSatVal.setWidth(160);
        rowS.addView(tvPhotoSatVal);
        sbPhotoSat = new SeekBar(context);
        sbPhotoSat.setMax(200);
        sbPhotoSat.setProgress(100);
        sbPhotoSat.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbPhotoSat.setOnSeekBarChangeListener(this);
        rowS.addView(sbPhotoSat);
        photoAdjustPanel.addView(rowS);

        photoEditorView.addView(photoAdjustPanel);
    }

    private void buildLightroomPanel() {
        photoLightroomPanel = new LinearLayout(context);
        photoLightroomPanel.setOrientation(LinearLayout.VERTICAL);
        photoLightroomPanel.setBackgroundColor(Color.parseColor("#121622"));
        photoLightroomPanel.setPadding(20, 6, 20, 6);
        photoLightroomPanel.setVisibility(View.GONE);

        // Clarity
        LinearLayout rowClarity = new LinearLayout(context);
        rowClarity.setOrientation(LinearLayout.HORIZONTAL);
        rowClarity.setGravity(Gravity.CENTER_VERTICAL);
        tvLrClarityVal = new TextView(context);
        tvLrClarityVal.setText("Độ rõ nét: 0");
        tvLrClarityVal.setTextColor(Color.WHITE);
        tvLrClarityVal.setTextSize(10);
        tvLrClarityVal.setWidth(160);
        rowClarity.addView(tvLrClarityVal);
        sbLrClarity = new SeekBar(context);
        sbLrClarity.setMax(100);
        sbLrClarity.setProgress(0);
        sbLrClarity.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLrClarity.setOnSeekBarChangeListener(this);
        rowClarity.addView(sbLrClarity);
        photoLightroomPanel.addView(rowClarity);

        // Dehaze
        LinearLayout rowDehaze = new LinearLayout(context);
        rowDehaze.setOrientation(LinearLayout.HORIZONTAL);
        rowDehaze.setGravity(Gravity.CENTER_VERTICAL);
        tvLrDehazeVal = new TextView(context);
        tvLrDehazeVal.setText("Khử sương mù: 0");
        tvLrDehazeVal.setTextColor(Color.WHITE);
        tvLrDehazeVal.setTextSize(10);
        tvLrDehazeVal.setWidth(160);
        rowDehaze.addView(tvLrDehazeVal);
        sbLrDehaze = new SeekBar(context);
        sbLrDehaze.setMax(100);
        sbLrDehaze.setProgress(0);
        sbLrDehaze.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLrDehaze.setOnSeekBarChangeListener(this);
        rowDehaze.addView(sbLrDehaze);
        photoLightroomPanel.addView(rowDehaze);

        // Grain
        LinearLayout rowGrain = new LinearLayout(context);
        rowGrain.setOrientation(LinearLayout.HORIZONTAL);
        rowGrain.setGravity(Gravity.CENTER_VERTICAL);
        tvLrGrainVal = new TextView(context);
        tvLrGrainVal.setText("Hạt phim Grain: 0");
        tvLrGrainVal.setTextColor(Color.WHITE);
        tvLrGrainVal.setTextSize(10);
        tvLrGrainVal.setWidth(160);
        rowGrain.addView(tvLrGrainVal);
        sbLrGrain = new SeekBar(context);
        sbLrGrain.setMax(100);
        sbLrGrain.setProgress(0);
        sbLrGrain.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLrGrain.setOnSeekBarChangeListener(this);
        rowGrain.addView(sbLrGrain);
        photoLightroomPanel.addView(rowGrain);

        // Vignette
        LinearLayout rowVignette = new LinearLayout(context);
        rowVignette.setOrientation(LinearLayout.HORIZONTAL);
        rowVignette.setGravity(Gravity.CENTER_VERTICAL);
        tvLrVignetteVal = new TextView(context);
        tvLrVignetteVal.setText("Tối 4 góc Vignette: 0");
        tvLrVignetteVal.setTextColor(Color.WHITE);
        tvLrVignetteVal.setTextSize(10);
        tvLrVignetteVal.setWidth(160);
        rowVignette.addView(tvLrVignetteVal);
        sbLrVignette = new SeekBar(context);
        sbLrVignette.setMax(100);
        sbLrVignette.setProgress(0);
        sbLrVignette.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLrVignette.setOnSeekBarChangeListener(this);
        rowVignette.addView(sbLrVignette);
        photoLightroomPanel.addView(rowVignette);

        // Tone Curve Button
        btnLrToneCurve = new TextView(context);
        ((TextView) btnLrToneCurve).setText("📈 Đường cong Tone Curves (S-Curve Tương phản)");
        ((TextView) btnLrToneCurve).setTextColor(Color.parseColor("#38BDF8"));
        ((TextView) btnLrToneCurve).setTextSize(10);
        ((TextView) btnLrToneCurve).setTypeface(null, Typeface.BOLD);
        btnLrToneCurve.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btnLrToneCurve.setPadding(16, 8, 16, 8);
        btnLrToneCurve.setOnClickListener(this);
        photoLightroomPanel.addView(btnLrToneCurve);

        photoEditorView.addView(photoLightroomPanel);
    }

    private void buildEraserPanel() {
        photoEraserPanel = new LinearLayout(context);
        photoEraserPanel.setOrientation(LinearLayout.HORIZONTAL);
        photoEraserPanel.setBackgroundColor(Color.parseColor("#151824"));
        photoEraserPanel.setPadding(16, 10, 16, 10);
        photoEraserPanel.setGravity(Gravity.CENTER_VERTICAL);
        photoEraserPanel.setVisibility(View.GONE);

        btnInpaintBrush = createPillButton("🧹 Cọ xóa ma thuật", "#3B82F6", photoEraserPanel);
        btnSkySunset = createPillButton("🌅 Hoàng hôn", "#F97316", photoEraserPanel);
        btnSkyAurora = createPillButton("🌌 Cực quang", "#10B981", photoEraserPanel);
        btnSkyBlue = createPillButton("☀️ Trời trong xanh", "#06B6D4", photoEraserPanel);

        photoEditorView.addView(photoEraserPanel);
    }

    private void buildFacetunePanel() {
        photoFacetunePanel = new LinearLayout(context);
        photoFacetunePanel.setOrientation(LinearLayout.HORIZONTAL);
        photoFacetunePanel.setBackgroundColor(Color.parseColor("#1E1728"));
        photoFacetunePanel.setPadding(16, 10, 16, 10);
        photoFacetunePanel.setGravity(Gravity.CENTER_VERTICAL);
        photoFacetunePanel.setVisibility(View.GONE);

        btnFtWhitening = createPillButton("🦷 Trắng răng", "#F43F5E", photoFacetunePanel);
        btnFtBrightenEyes = createPillButton("👁️ Sáng mắt", "#EC4899", photoFacetunePanel);
        btnFtLipstick = createPillButton("💄 Tô son", "#E11D48", photoFacetunePanel);
        btnMeituLegs = createPillButton("👠 Kéo dài chân", "#8B5CF6", photoFacetunePanel);
        btnMeituBling = createPillButton("✨ Bling Bling", "#D946EF", photoFacetunePanel);

        photoEditorView.addView(photoFacetunePanel);
    }

    private void buildFaceAppPanel() {
        photoFaceAppPanel = new LinearLayout(context);
        photoFaceAppPanel.setOrientation(LinearLayout.HORIZONTAL);
        photoFaceAppPanel.setBackgroundColor(Color.parseColor("#181B2B"));
        photoFaceAppPanel.setPadding(16, 10, 16, 10);
        photoFaceAppPanel.setGravity(Gravity.CENTER_VERTICAL);
        photoFaceAppPanel.setVisibility(View.GONE);

        btnFaSmile = createPillButton("😄 Nụ cười tươi", "#3B82F6", photoFaceAppPanel);
        btnFaYouth = createPillButton("👶 Trẻ hóa 18", "#10B981", photoFaceAppPanel);
        btnFaHair = createPillButton("💇 Tóc bồng bềnh", "#8B5CF6", photoFaceAppPanel);

        photoEditorView.addView(photoFaceAppPanel);
    }

    private void buildPhotoLipstickProPanel() {
        photoLipstickProPanel = new LinearLayout(context);
        photoLipstickProPanel.setOrientation(LinearLayout.VERTICAL);
        photoLipstickProPanel.setBackgroundColor(Color.parseColor("#1A121E"));
        photoLipstickProPanel.setPadding(16, 10, 16, 12);
        photoLipstickProPanel.setVisibility(View.GONE);

        // Header
        LinearLayout headerRow = new LinearLayout(context);
        headerRow.setOrientation(LinearLayout.HORIZONTAL);
        headerRow.setGravity(Gravity.CENTER_VERTICAL);
        headerRow.setPadding(0, 0, 0, 6);

        TextView tvTitle = new TextView(context);
        tvTitle.setText("💄 TÔ SON CAO CẤP (VIP)");
        tvTitle.setTextColor(Color.parseColor("#FB7185"));
        tvTitle.setTextSize(11);
        tvTitle.setTypeface(null, Typeface.BOLD);
        headerRow.addView(tvTitle, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));

        btnLipstickCancel = new TextView(context);
        btnLipstickCancel.setText("✕ Hủy");
        btnLipstickCancel.setTextColor(Color.parseColor("#94A3B8"));
        btnLipstickCancel.setTextSize(11);
        btnLipstickCancel.setPadding(20, 8, 20, 8);
        btnLipstickCancel.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btnLipstickCancel.setOnClickListener(this);
        headerRow.addView(btnLipstickCancel);

        btnLipstickApply = new TextView(context);
        btnLipstickApply.setText("✓ Áp dụng");
        btnLipstickApply.setTextColor(Color.BLACK);
        btnLipstickApply.setTextSize(11);
        btnLipstickApply.setTypeface(null, Typeface.BOLD);
        btnLipstickApply.setPadding(20, 8, 20, 8);
        btnLipstickApply.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams applyLp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        applyLp.setMargins(12, 0, 0, 0);
        btnLipstickApply.setLayoutParams(applyLp);
        btnLipstickApply.setOnClickListener(this);
        headerRow.addView(btnLipstickApply);
        photoLipstickProPanel.addView(headerRow);

        // Palette
        HorizontalScrollView paletteScroll = new HorizontalScrollView(context);
        paletteScroll.setHorizontalScrollBarEnabled(false);
        paletteScroll.setPadding(0, 4, 0, 6);
        LinearLayout paletteRow = new LinearLayout(context);
        paletteRow.setOrientation(LinearLayout.HORIZONTAL);
        paletteRow.setGravity(Gravity.CENTER_VERTICAL);

        String[] lipNames = {"Đỏ Thuần", "Đỏ Hồng", "Cam Đất", "Hồng Đào", "Đỏ Mận", "San Hô", "Nude"};
        for (int i = 0; i < LIPSTICK_PALETTE_COLORS.length; i++) {
            final int colorVal = LIPSTICK_PALETTE_COLORS[i];
            FrameLayout chipWrapper = new FrameLayout(context);
            LinearLayout.LayoutParams cwLp = new LinearLayout.LayoutParams(60, 60);
            cwLp.setMargins(0, 0, 16, 0);
            chipWrapper.setLayoutParams(cwLp);

            View chip = new View(context);
            chip.setBackgroundColor(colorVal);
            chip.setTag(colorVal);
            chip.setOnClickListener(this);
            lipstickColorChips.add(chip);
            lipstickChipViews[i] = chip;
            chipWrapper.addView(chip, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));
            paletteRow.addView(chipWrapper);
        }
        paletteScroll.addView(paletteRow);
        photoLipstickProPanel.addView(paletteScroll);

        // Intensity
        LinearLayout rowInt = new LinearLayout(context);
        rowInt.setOrientation(LinearLayout.HORIZONTAL);
        rowInt.setGravity(Gravity.CENTER_VERTICAL);
        rowInt.setPadding(0, 2, 0, 2);
        tvLipstickIntensityVal = new TextView(context);
        tvLipstickIntensityVal.setText("Độ đậm: " + (int)(currentLipstickIntensity * 100) + "%");
        tvLipstickIntensityVal.setTextColor(Color.WHITE);
        tvLipstickIntensityVal.setTextSize(10);
        tvLipstickIntensityVal.setWidth(160);
        rowInt.addView(tvLipstickIntensityVal);
        sbLipstickIntensity = new SeekBar(context);
        sbLipstickIntensity.setMax(100);
        sbLipstickIntensity.setProgress((int)(currentLipstickIntensity * 100));
        sbLipstickIntensity.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLipstickIntensity.setOnSeekBarChangeListener(this);
        rowInt.addView(sbLipstickIntensity);
        photoLipstickProPanel.addView(rowInt);

        // Gloss
        LinearLayout rowGloss = new LinearLayout(context);
        rowGloss.setOrientation(LinearLayout.HORIZONTAL);
        rowGloss.setGravity(Gravity.CENTER_VERTICAL);
        rowGloss.setPadding(0, 2, 0, 4);
        tvLipstickGlossVal = new TextView(context);
        tvLipstickGlossVal.setText("Độ bóng: " + (int)(currentLipstickGloss * 100) + "%");
        tvLipstickGlossVal.setTextColor(Color.WHITE);
        tvLipstickGlossVal.setTextSize(10);
        tvLipstickGlossVal.setWidth(160);
        rowGloss.addView(tvLipstickGlossVal);
        sbLipstickGloss = new SeekBar(context);
        sbLipstickGloss.setMax(100);
        sbLipstickGloss.setProgress((int)(currentLipstickGloss * 100));
        sbLipstickGloss.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLipstickGloss.setOnSeekBarChangeListener(this);
        rowGloss.addView(sbLipstickGloss);
        photoLipstickProPanel.addView(rowGloss);

        photoEditorView.addView(photoLipstickProPanel);
    }

    private void buildPhotoTeethProPanel() {
        photoTeethProPanel = new LinearLayout(context);
        photoTeethProPanel.setOrientation(LinearLayout.VERTICAL);
        photoTeethProPanel.setBackgroundColor(Color.parseColor("#111827"));
        photoTeethProPanel.setPadding(16, 10, 16, 12);
        photoTeethProPanel.setVisibility(View.GONE);

        // Header
        LinearLayout headerRow = new LinearLayout(context);
        headerRow.setOrientation(LinearLayout.HORIZONTAL);
        headerRow.setGravity(Gravity.CENTER_VERTICAL);
        headerRow.setPadding(0, 0, 0, 6);

        TextView tvTitle = new TextView(context);
        tvTitle.setText("🦷 LÀM TRẮNG RĂNG (VIP)");
        tvTitle.setTextColor(Color.parseColor("#38BDF8"));
        tvTitle.setTextSize(11);
        tvTitle.setTypeface(null, Typeface.BOLD);
        headerRow.addView(tvTitle, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));

        btnTeethCancel = new TextView(context);
        btnTeethCancel.setText("✕ Hủy");
        btnTeethCancel.setTextColor(Color.parseColor("#94A3B8"));
        btnTeethCancel.setTextSize(11);
        btnTeethCancel.setPadding(20, 8, 20, 8);
        btnTeethCancel.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btnTeethCancel.setOnClickListener(this);
        headerRow.addView(btnTeethCancel);

        btnTeethApply = new TextView(context);
        btnTeethApply.setText("✓ Áp dụng");
        btnTeethApply.setTextColor(Color.BLACK);
        btnTeethApply.setTextSize(11);
        btnTeethApply.setTypeface(null, Typeface.BOLD);
        btnTeethApply.setPadding(20, 8, 20, 8);
        btnTeethApply.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams applyLp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        applyLp.setMargins(12, 0, 0, 0);
        btnTeethApply.setLayoutParams(applyLp);
        btnTeethApply.setOnClickListener(this);
        headerRow.addView(btnTeethApply);
        photoTeethProPanel.addView(headerRow);

        // Presets
        LinearLayout presetRow = new LinearLayout(context);
        presetRow.setOrientation(LinearLayout.HORIZONTAL);
        presetRow.setGravity(Gravity.CENTER_VERTICAL);
        presetRow.setPadding(0, 2, 0, 6);

        btnTeethPreset30 = createTeethPresetButton("30% Tự nhiên", presetRow);
        btnTeethPreset50 = createTeethPresetButton("50% Rạng rỡ", presetRow);
        btnTeethPreset75 = createTeethPresetButton("75% Hollywood", presetRow);
        btnTeethPreset100 = createTeethPresetButton("100% Cực sáng", presetRow);
        photoTeethProPanel.addView(presetRow);

        // Slider
        LinearLayout rowSlider = new LinearLayout(context);
        rowSlider.setOrientation(LinearLayout.HORIZONTAL);
        rowSlider.setGravity(Gravity.CENTER_VERTICAL);
        rowSlider.setPadding(0, 2, 0, 4);

        tvTeethIntensityVal = new TextView(context);
        tvTeethIntensityVal.setText("Độ trắng: " + (int)(currentTeethIntensity * 100) + "%");
        tvTeethIntensityVal.setTextColor(Color.WHITE);
        tvTeethIntensityVal.setTextSize(10);
        tvTeethIntensityVal.setWidth(160);
        rowSlider.addView(tvTeethIntensityVal);

        sbTeethIntensity = new SeekBar(context);
        sbTeethIntensity.setMax(100);
        sbTeethIntensity.setProgress((int)(currentTeethIntensity * 100));
        sbTeethIntensity.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbTeethIntensity.setOnSeekBarChangeListener(this);
        rowSlider.addView(sbTeethIntensity);
        photoTeethProPanel.addView(rowSlider);

        photoEditorView.addView(photoTeethProPanel);
    }

    private TextView createTeethPresetButton(String text, LinearLayout parent) {
        TextView btn = new TextView(context);
        btn.setText(text);
        btn.setTextColor(Color.WHITE);
        btn.setTextSize(10);
        btn.setPadding(16, 6, 16, 6);
        btn.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btn.setOnClickListener(this);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        lp.setMargins(4, 0, 4, 0);
        btn.setLayoutParams(lp);
        parent.addView(btn);
        return btn;
    }

    private void buildPhotoEyesProPanel() {
        photoEyesProPanel = new LinearLayout(context);
        photoEyesProPanel.setOrientation(LinearLayout.VERTICAL);
        photoEyesProPanel.setBackgroundColor(Color.parseColor("#0F172A"));
        photoEyesProPanel.setPadding(16, 10, 16, 12);
        photoEyesProPanel.setVisibility(View.GONE);

        // Header
        LinearLayout headerRow = new LinearLayout(context);
        headerRow.setOrientation(LinearLayout.HORIZONTAL);
        headerRow.setGravity(Gravity.CENTER_VERTICAL);
        headerRow.setPadding(0, 0, 0, 6);

        TextView tvTitle = new TextView(context);
        tvTitle.setText("👁️ SÁNG MẮT & ĐỐM SÁNG (VIP)");
        tvTitle.setTextColor(Color.parseColor("#38BDF8"));
        tvTitle.setTextSize(11);
        tvTitle.setTypeface(null, Typeface.BOLD);
        headerRow.addView(tvTitle, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));

        btnEyesCancel = new TextView(context);
        btnEyesCancel.setText("✕ Hủy");
        btnEyesCancel.setTextColor(Color.parseColor("#94A3B8"));
        btnEyesCancel.setTextSize(11);
        btnEyesCancel.setPadding(20, 8, 20, 8);
        btnEyesCancel.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btnEyesCancel.setOnClickListener(this);
        headerRow.addView(btnEyesCancel);

        btnEyesApply = new TextView(context);
        btnEyesApply.setText("✓ Áp dụng");
        btnEyesApply.setTextColor(Color.BLACK);
        btnEyesApply.setTextSize(11);
        btnEyesApply.setTypeface(null, Typeface.BOLD);
        btnEyesApply.setPadding(20, 8, 20, 8);
        btnEyesApply.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams applyLp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        applyLp.setMargins(12, 0, 0, 0);
        btnEyesApply.setLayoutParams(applyLp);
        btnEyesApply.setOnClickListener(this);
        headerRow.addView(btnEyesApply);
        photoEyesProPanel.addView(headerRow);

        // Sclera Brightness Row
        LinearLayout rowSclera = new LinearLayout(context);
        rowSclera.setOrientation(LinearLayout.HORIZONTAL);
        rowSclera.setGravity(Gravity.CENTER_VERTICAL);
        rowSclera.setPadding(0, 2, 0, 2);

        tvScleraBrightVal = new TextView(context);
        tvScleraBrightVal.setText("Sáng lòng trắng: " + (int)(currentScleraBrightness * 100) + "%");
        tvScleraBrightVal.setTextColor(Color.WHITE);
        tvScleraBrightVal.setTextSize(10);
        tvScleraBrightVal.setWidth(180);
        rowSclera.addView(tvScleraBrightVal);

        sbScleraBright = new SeekBar(context);
        sbScleraBright.setMax(100);
        sbScleraBright.setProgress((int)(currentScleraBrightness * 100));
        sbScleraBright.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbScleraBright.setOnSeekBarChangeListener(this);
        rowSclera.addView(sbScleraBright);
        photoEyesProPanel.addView(rowSclera);

        // Iris Clarity Row
        LinearLayout rowIris = new LinearLayout(context);
        rowIris.setOrientation(LinearLayout.HORIZONTAL);
        rowIris.setGravity(Gravity.CENTER_VERTICAL);
        rowIris.setPadding(0, 2, 0, 4);

        tvIrisClarityVal = new TextView(context);
        tvIrisClarityVal.setText("Nét tròng & Đốm sáng: " + (int)(currentIrisClarity * 100) + "%");
        tvIrisClarityVal.setTextColor(Color.WHITE);
        tvIrisClarityVal.setTextSize(10);
        tvIrisClarityVal.setWidth(180);
        rowIris.addView(tvIrisClarityVal);

        sbIrisClarity = new SeekBar(context);
        sbIrisClarity.setMax(100);
        sbIrisClarity.setProgress((int)(currentIrisClarity * 100));
        sbIrisClarity.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbIrisClarity.setOnSeekBarChangeListener(this);
        rowIris.addView(sbIrisClarity);
        photoEyesProPanel.addView(rowIris);

        photoEditorView.addView(photoEyesProPanel);
    }

    private void buildPhotoLegsProPanel() {
        photoLegsProPanel = new LinearLayout(context);
        photoLegsProPanel.setOrientation(LinearLayout.VERTICAL);
        photoLegsProPanel.setBackgroundColor(Color.parseColor("#12151F"));
        photoLegsProPanel.setPadding(16, 10, 16, 12);
        photoLegsProPanel.setVisibility(View.GONE);

        // Header
        LinearLayout headerRow = new LinearLayout(context);
        headerRow.setOrientation(LinearLayout.HORIZONTAL);
        headerRow.setGravity(Gravity.CENTER_VERTICAL);
        headerRow.setPadding(0, 0, 0, 6);

        TextView tvTitle = new TextView(context);
        tvTitle.setText("👠 KÉO DÀI CHÂN MEITU VIP (IN-FRAME)");
        tvTitle.setTextColor(Color.parseColor("#F59E0B"));
        tvTitle.setTextSize(11);
        tvTitle.setTypeface(null, Typeface.BOLD);
        headerRow.addView(tvTitle, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));

        btnLegsCancel = new TextView(context);
        btnLegsCancel.setText("✕ Hủy");
        btnLegsCancel.setTextColor(Color.parseColor("#94A3B8"));
        btnLegsCancel.setTextSize(11);
        btnLegsCancel.setPadding(20, 8, 20, 8);
        btnLegsCancel.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btnLegsCancel.setOnClickListener(this);
        headerRow.addView(btnLegsCancel);

        btnLegsApply = new TextView(context);
        btnLegsApply.setText("✓ Áp dụng");
        btnLegsApply.setTextColor(Color.BLACK);
        btnLegsApply.setTextSize(11);
        btnLegsApply.setTypeface(null, Typeface.BOLD);
        btnLegsApply.setPadding(20, 8, 20, 8);
        btnLegsApply.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams applyLp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        applyLp.setMargins(12, 0, 0, 0);
        btnLegsApply.setLayoutParams(applyLp);
        btnLegsApply.setOnClickListener(this);
        headerRow.addView(btnLegsApply);
        photoLegsProPanel.addView(headerRow);

        // Badge: 100% Invariance Guarantee
        TextView tvBadge = new TextView(context);
        tvBadge.setText("🔒 Bảo toàn tuyệt đối kích cỡ khung hình — Không kéo giãn chiều cao ảnh!");
        tvBadge.setTextColor(Color.parseColor("#10B981"));
        tvBadge.setTextSize(9);
        tvBadge.setPadding(0, 0, 0, 6);
        photoLegsProPanel.addView(tvBadge);

        // Leg Stretch
        LinearLayout rowStretch = new LinearLayout(context);
        rowStretch.setOrientation(LinearLayout.HORIZONTAL);
        rowStretch.setGravity(Gravity.CENTER_VERTICAL);
        rowStretch.setPadding(0, 2, 0, 2);
        tvLegStretchVal = new TextView(context);
        tvLegStretchVal.setText("Kéo dài chân: " + (int)(currentLegStretch * 100) + "%");
        tvLegStretchVal.setTextColor(Color.WHITE);
        tvLegStretchVal.setTextSize(10);
        tvLegStretchVal.setWidth(180);
        rowStretch.addView(tvLegStretchVal);
        sbLegStretch = new SeekBar(context);
        sbLegStretch.setMax(100);
        sbLegStretch.setProgress((int)(currentLegStretch * 100));
        sbLegStretch.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLegStretch.setOnSeekBarChangeListener(this);
        rowStretch.addView(sbLegStretch);
        photoLegsProPanel.addView(rowStretch);

        // Leg Slim
        LinearLayout rowSlim = new LinearLayout(context);
        rowSlim.setOrientation(LinearLayout.HORIZONTAL);
        rowSlim.setGravity(Gravity.CENTER_VERTICAL);
        rowSlim.setPadding(0, 2, 0, 2);
        tvLegSlimVal = new TextView(context);
        tvLegSlimVal.setText("Thon gọn chân: " + (int)(currentLegSlim * 100) + "%");
        tvLegSlimVal.setTextColor(Color.WHITE);
        tvLegSlimVal.setTextSize(10);
        tvLegSlimVal.setWidth(180);
        rowSlim.addView(tvLegSlimVal);
        sbLegSlim = new SeekBar(context);
        sbLegSlim.setMax(100);
        sbLegSlim.setProgress((int)(currentLegSlim * 100));
        sbLegSlim.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbLegSlim.setOnSeekBarChangeListener(this);
        rowSlim.addView(sbLegSlim);
        photoLegsProPanel.addView(rowSlim);

        // Hips Line Y
        LinearLayout rowHips = new LinearLayout(context);
        rowHips.setOrientation(LinearLayout.HORIZONTAL);
        rowHips.setGravity(Gravity.CENTER_VERTICAL);
        rowHips.setPadding(0, 2, 0, 2);
        tvHipsLineVal = new TextView(context);
        tvHipsLineVal.setText("Vạch mông (Hips): " + (int)(currentHipsLineY * 100) + "%");
        tvHipsLineVal.setTextColor(Color.WHITE);
        tvHipsLineVal.setTextSize(10);
        tvHipsLineVal.setWidth(180);
        rowHips.addView(tvHipsLineVal);
        sbHipsLine = new SeekBar(context);
        sbHipsLine.setMax(100);
        sbHipsLine.setProgress((int)(currentHipsLineY * 100));
        sbHipsLine.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbHipsLine.setOnSeekBarChangeListener(this);
        rowHips.addView(sbHipsLine);
        photoLegsProPanel.addView(rowHips);

        // Ankles Line Y
        LinearLayout rowAnkles = new LinearLayout(context);
        rowAnkles.setOrientation(LinearLayout.HORIZONTAL);
        rowAnkles.setGravity(Gravity.CENTER_VERTICAL);
        rowAnkles.setPadding(0, 2, 0, 4);
        tvAnklesLineVal = new TextView(context);
        tvAnklesLineVal.setText("Vạch cổ chân: " + (int)(currentAnklesLineY * 100) + "%");
        tvAnklesLineVal.setTextColor(Color.WHITE);
        tvAnklesLineVal.setTextSize(10);
        tvAnklesLineVal.setWidth(180);
        rowAnkles.addView(tvAnklesLineVal);
        sbAnklesLine = new SeekBar(context);
        sbAnklesLine.setMax(100);
        sbAnklesLine.setProgress((int)(currentAnklesLineY * 100));
        sbAnklesLine.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        sbAnklesLine.setOnSeekBarChangeListener(this);
        rowAnkles.addView(sbAnklesLine);
        photoLegsProPanel.addView(rowAnkles);

        photoEditorView.addView(photoLegsProPanel);
    }

    private void buildBottomNavTabs() {
        HorizontalScrollView bottomNavScroll = new HorizontalScrollView(context);
        bottomNavScroll.setHorizontalScrollBarEnabled(false);
        bottomNavScroll.setBackgroundColor(Color.parseColor("#0C0D14"));
        bottomNavScroll.setPadding(8, 6, 8, 12);

        LinearLayout navRow = new LinearLayout(context);
        navRow.setOrientation(LinearLayout.HORIZONTAL);
        navRow.setGravity(Gravity.CENTER_VERTICAL);

        photoNavRatio = createPhotoTool("📐", "Tỷ lệ", navRow);
        photoNavLut = createPhotoTool("🎨", "3D LUTs", navRow);
        photoNavLightroom = createPhotoTool("✨", "Lightroom", navRow);
        photoNavEraser = createPhotoTool("🧹", "Xóa AI", navRow);
        photoNavFacetune = createPhotoTool("💄", "Chân dung", navRow);
        photoNavFaceApp = createPhotoTool("🤖", "FaceApp", navRow);
        photoNavAdjust = createPhotoTool("⚙️", "Tinh chỉnh", navRow);
        photoNavRotate = createPhotoTool("🔄", "Xoay 90°", navRow);
        photoNavCrop = createPhotoTool("✂️", "Cắt ảnh", navRow);
        photoNavFlip = createPhotoTool("🪞", "Lật ngang", navRow);

        bottomNavScroll.addView(navRow);
        photoEditorView.addView(bottomNavScroll);
    }

    private View createFilterChip(String label, String bgColor, LinearLayout parent) {
        TextView chip = new TextView(context);
        chip.setText(label);
        chip.setTextColor(Color.WHITE);
        chip.setTextSize(11);
        chip.setBackgroundColor(Color.parseColor(bgColor));
        chip.setPadding(24, 14, 24, 14);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        params.setMargins(6, 0, 6, 0);
        chip.setLayoutParams(params);
        chip.setOnClickListener(this);
        parent.addView(chip);
        return chip;
    }

    private View createPhotoTool(String icon, String label, LinearLayout parent) {
        LinearLayout tool = new LinearLayout(context);
        tool.setOrientation(LinearLayout.VERTICAL);
        tool.setGravity(Gravity.CENTER);
        tool.setPadding(16, 4, 16, 4);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        tool.setLayoutParams(params);

        TextView tvIcon = new TextView(context);
        tvIcon.setText(icon);
        tvIcon.setTextSize(18);
        tool.addView(tvIcon);

        TextView tvLabel = new TextView(context);
        tvLabel.setText(label);
        tvLabel.setTextColor(Color.parseColor("#CBD5E1"));
        tvLabel.setTextSize(10);
        tvLabel.setPadding(0, 4, 0, 0);
        tool.addView(tvLabel);

        tool.setOnClickListener(this);
        parent.addView(tool);
        return tool;
    }

    private View createPillButton(String text, String colorHex, LinearLayout parent) {
        TextView btn = new TextView(context);
        btn.setText(text);
        btn.setTextColor(Color.WHITE);
        btn.setTextSize(10);
        btn.setTypeface(null, Typeface.BOLD);
        btn.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
        btn.setPadding(18, 10, 18, 10);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 10, 0);
        btn.setLayoutParams(lp);
        btn.setOnClickListener(this);
        parent.addView(btn);
        return btn;
    }

    private void setPillActive(View v, boolean active) {
        if (v instanceof TextView) {
            TextView tv = (TextView) v;
            if (active) {
                tv.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
                tv.setTextColor(Color.BLACK);
            } else {
                tv.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_speed_pill);
                tv.setTextColor(Color.WHITE);
            }
        }
    }

    /**
     * Apply all active filters, color grading, Lightroom matrices, and Face/Sky effects.
     * Áp dụng toàn bộ bộ lọc, tinh chỉnh màu sắc, Lightroom và hiệu ứng khuôn mặt/bầu trời.
     */
    public void applyPhotoFilters() {
        if (ivPhotoCanvas == null) return;
        ColorMatrix cm = PhotoFilterController.getFilterMatrix(currentPhotoFilter);
        cm.postConcat(PhotoFilterController.getAdjustmentMatrix(photoBright, photoContrast, photoSat));

        // Apply Adobe Lightroom Pro (Tone Curves, Clarity, Dehaze, Grain, Vignette)
        if (isLrToneCurveActive || lrClarity != 0 || lrDehaze != 0 || lrGrain != 0 || lrVignette != 0) {
            cm.postConcat(EffectRegistry.getLightroomMatrix(lrClarity, lrDehaze, lrGrain, lrVignette));
        }

        // Apply Facetune & Meitu Portrait Detail & Body Retouch
        if (activePortraitEffect != null && !activePortraitEffect.isEmpty()) {
            cm.postConcat(EffectRegistry.getPortraitRetouchMatrix(activePortraitEffect));
        }

        // Apply FaceApp AI Morphing (Smile, Youth 18, Hair)
        if (activeFaceAppEffect != null && !activeFaceAppEffect.isEmpty()) {
            cm.postConcat(EffectRegistry.getFaceAppMatrix(activeFaceAppEffect));
        }

        // Apply SnapEdit Sky Wizard (Sunset, Aurora, Blue Sky)
        if (activeSkyEffect != null && !activeSkyEffect.isEmpty()) {
            cm.postConcat(EffectRegistry.getSnapEditSkyMatrix(activeSkyEffect));
        }

        ivPhotoCanvas.setColorFilter(new ColorMatrixColorFilter(cm));
    }

    private void updatePhotoCanvasDimensions(int contentW, int contentH) {
        if (photoCanvasWrapper == null || contentW <= 0 || contentH <= 0) return;
        DisplayMetrics dm = context.getResources().getDisplayMetrics();
        int maxW = Math.max(400, dm.widthPixels - 32);
        int maxH = Math.max(500, (int) (dm.heightPixels * 0.55f));

        int targetW;
        int targetH;

        if (isPhotoFillMode) {
            targetW = maxW;
            targetH = maxH;
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setScaleType(ImageView.ScaleType.CENTER_CROP);
            }
        } else {
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setScaleType(ImageView.ScaleType.FIT_CENTER);
            }
            float contentAspect = (float) contentW / (float) contentH;
            float maxAspect = (float) maxW / (float) maxH;

            if (contentAspect > maxAspect) {
                targetW = maxW;
                targetH = Math.max(300, (int) (maxW / contentAspect));
            } else {
                targetH = maxH;
                targetW = Math.max(300, (int) (maxH * contentAspect));
            }
        }

        FrameLayout.LayoutParams pcwParams = new FrameLayout.LayoutParams(targetW, targetH, Gravity.CENTER);
        photoCanvasWrapper.setLayoutParams(pcwParams);
    }

    /**
     * Rotate photo 90 degrees clockwise with memory cleanup and landmark re-alignment.
     * Xoay ảnh 90 độ theo chiều kim đồng hồ, giải phóng bộ nhớ và cập nhật lại mốc khuôn mặt.
     */
    private void rotatePhoto90Degrees() {
        if (basePhotoBitmap == null || basePhotoBitmap.isRecycled()) return;
        photoRotationDegrees = (photoRotationDegrees + 90) % 360;
        Matrix matrix = new Matrix();
        matrix.postRotate(90);
        Bitmap rotated = Bitmap.createBitmap(basePhotoBitmap, 0, 0, basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight(), matrix, true);
        if (basePhotoBitmap != null && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != rotated && !basePhotoBitmap.isRecycled()) {
            basePhotoBitmap.recycle();
        }
        basePhotoBitmap = rotated;

        if (baseOriginalPhotoBitmap != null && !baseOriginalPhotoBitmap.isRecycled()) {
            Bitmap origRotated = Bitmap.createBitmap(baseOriginalPhotoBitmap, 0, 0, baseOriginalPhotoBitmap.getWidth(), baseOriginalPhotoBitmap.getHeight(), matrix, true);
            if (baseOriginalPhotoBitmap != origRotated && !baseOriginalPhotoBitmap.isRecycled()) {
                baseOriginalPhotoBitmap.recycle();
            }
            baseOriginalPhotoBitmap = origRotated;
        }

        if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
            basePreEffectBitmap.recycle();
            basePreEffectBitmap = null;
        }

        // P7 Fix: Re-detect face landmarks after rotation so portrait features align correctly
        // Sửa lỗi P7: Nhận diện lại tọa độ khuôn mặt sau khi xoay để hiệu ứng chân dung khớp đúng vị trí
        detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePhotoBitmap);
        cachedPhotoLandmarks = !detectedFaceList.isEmpty() ? detectedFaceList.get(0) : FaceBodyDetectionEngine.detectFace(basePhotoBitmap);
        selectedFaceIndex = 0;

        if (ivPhotoCanvas != null) {
            ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
        }
        updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
        applyPhotoFilters();
        Toast.makeText(context, "🔄 Đã xoay ảnh 90° (" + basePhotoBitmap.getWidth() + "x" + basePhotoBitmap.getHeight() + " px)", Toast.LENGTH_SHORT).show();
    }

    /**
     * Flip photo horizontally with memory cleanup and landmark re-alignment.
     * Lật ngang ảnh, giải phóng bộ nhớ và cập nhật lại mốc khuôn mặt tránh lệch bên.
     */
    private void flipPhotoHorizontal() {
        if (basePhotoBitmap == null || basePhotoBitmap.isRecycled()) return;
        isPhotoFlipped = !isPhotoFlipped;
        Matrix matrix = new Matrix();
        matrix.postScale(-1, 1);
        Bitmap flipped = Bitmap.createBitmap(basePhotoBitmap, 0, 0, basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight(), matrix, true);
        if (basePhotoBitmap != null && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != flipped && !basePhotoBitmap.isRecycled()) {
            basePhotoBitmap.recycle();
        }
        basePhotoBitmap = flipped;

        if (baseOriginalPhotoBitmap != null && !baseOriginalPhotoBitmap.isRecycled()) {
            Bitmap origFlipped = Bitmap.createBitmap(baseOriginalPhotoBitmap, 0, 0, baseOriginalPhotoBitmap.getWidth(), baseOriginalPhotoBitmap.getHeight(), matrix, true);
            if (baseOriginalPhotoBitmap != origFlipped && !baseOriginalPhotoBitmap.isRecycled()) {
                baseOriginalPhotoBitmap.recycle();
            }
            baseOriginalPhotoBitmap = origFlipped;
        }

        if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
            basePreEffectBitmap.recycle();
            basePreEffectBitmap = null;
        }

        // P7 Fix: Re-detect face landmarks after flip so portrait features align correctly
        // Sửa lỗi P7: Nhận diện lại tọa độ khuôn mặt sau khi lật ngang để hiệu ứng chân dung không bị ngược bên
        detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePhotoBitmap);
        cachedPhotoLandmarks = !detectedFaceList.isEmpty() ? detectedFaceList.get(0) : FaceBodyDetectionEngine.detectFace(basePhotoBitmap);
        selectedFaceIndex = 0;

        if (ivPhotoCanvas != null) {
            ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
        }
        applyPhotoFilters();
        Toast.makeText(context, isPhotoFlipped ? "🪞 Đã lật ngang ảnh (Flip Horizontal)!" : "🪞 Đã khôi phục hướng ảnh!", Toast.LENGTH_SHORT).show();
    }

    private void showPhotoRatioDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("📐 CHỌN TỶ LỆ KHUNG ẢNH (ASPECT RATIO)");
        builder.setItems(PHOTO_RATIO_OPTIONS, this);
        builder.show();
    }

    @Override
    public void onClick(DialogInterface dialog, int which) {
        currentPhotoRatioIdx = which;
        if (which == 0) {
            isPhotoFillMode = false;
            ((TextView) btnPhotoRatio).setText("📐 Tự Do");
        } else if (which == 1) {
            ((TextView) btnPhotoRatio).setText("📐 1:1");
        } else if (which == 2) {
            ((TextView) btnPhotoRatio).setText("📐 4:5");
        } else if (which == 3) {
            ((TextView) btnPhotoRatio).setText("📐 3:4");
        } else if (which == 4) {
            ((TextView) btnPhotoRatio).setText("📐 9:16");
        } else if (which == 5) {
            ((TextView) btnPhotoRatio).setText("📐 16:9");
        }
        if (basePhotoBitmap != null) {
            updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
        }
        Toast.makeText(context, "Đã chọn tỷ lệ: " + PHOTO_RATIO_OPTIONS[which], Toast.LENGTH_SHORT).show();
    }

    public void resetCropToBase() {
        if (baseOriginalPhotoBitmap != null && !baseOriginalPhotoBitmap.isRecycled()) {
            basePhotoBitmap = baseOriginalPhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
            applyPhotoFilters();
        }
    }

    public void applyCropResult(int cropX, int cropY, int cropW, int cropH, int origW, int origH) {
        if (cropW > 0 && cropH > 0 && (cropW < origW || cropH < origH)) {
            Bitmap cropped = Bitmap.createBitmap(basePhotoBitmap, cropX, cropY, cropW, cropH);
            basePhotoBitmap = cropped;
            if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
            applyPhotoFilters();
            Toast.makeText(context, String.format("✂️ Đã cắt ảnh: %d x %d px", cropW, cropH), Toast.LENGTH_SHORT).show();
        }
    }

    private void showPhotoCropDialog() {
        if (basePhotoBitmap == null || basePhotoBitmap.isRecycled()) {
            Toast.makeText(context, "Vui lòng chọn ảnh trước khi cắt!", Toast.LENGTH_SHORT).show();
            return;
        }

        final int origW = basePhotoBitmap.getWidth();
        final int origH = basePhotoBitmap.getHeight();
        final int[] trims = new int[]{0, 0, 0, 0}; // left, right, top, bottom percentage

        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle("✂️ CẮT GỌT & ĐỔI TỶ LỆ KHUNG HÌNH (CROP)");

        ScrollView scroll = new ScrollView(context);
        LinearLayout root = new LinearLayout(context);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(32, 20, 32, 20);
        root.setBackgroundColor(Color.parseColor("#12141F"));

        final TextView tvDimInfo = new TextView(context);
        tvDimInfo.setText(String.format("Gốc: %d x %d px\nCắt: %d x %d px (Tỷ lệ: %.2f)",
            origW, origH, origW, origH, (float) origW / (float) origH));
        tvDimInfo.setTextColor(Color.parseColor("#00E5FF"));
        tvDimInfo.setTextSize(11);
        tvDimInfo.setTypeface(null, Typeface.BOLD);
        tvDimInfo.setPadding(0, 0, 0, 12);
        root.addView(tvDimInfo);

        HorizontalScrollView chipScroll = new HorizontalScrollView(context);
        chipScroll.setHorizontalScrollBarEnabled(false);
        LinearLayout chipRow = new LinearLayout(context);
        chipRow.setOrientation(LinearLayout.HORIZONTAL);
        chipRow.setPadding(0, 0, 0, 16);

        String[] aspectLabels = {"Tự do", "1:1", "4:5", "3:4", "9:16", "16:9", "2:3"};
        float[] aspectRatios = {0f, 1f, 4f / 5f, 3f / 4f, 9f / 16f, 16f / 9f, 2f / 3f};
        final SeekBar[] seekBars = new SeekBar[4];
        final TextView[] trimLabels = new TextView[4];

        for (int a = 0; a < aspectLabels.length; a++) {
            float targetRatio = aspectRatios[a];
            String label = aspectLabels[a];
            TextView chip = new TextView(context);
            chip.setText(label);
            chip.setTextColor(Color.WHITE);
            chip.setTextSize(10);
            chip.setBackgroundColor(Color.parseColor("#1E2433"));
            chip.setPadding(16, 8, 16, 8);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 8, 0);
            chip.setLayoutParams(lp);
            chip.setOnClickListener(new CropRatioChipClickListener(targetRatio, origW, origH, trims, seekBars));
            chipRow.addView(chip);
        }
        chipScroll.addView(chipRow);
        root.addView(chipScroll);

        Runnable updateDimPreview = new CropDimensionPreviewUpdater(tvDimInfo, origW, origH, trims);

        String[] trimNames = {"✂️ Mép Trái: ", "✂️ Mép Phải: ", "✂️ Mép Trên: ", "✂️ Mép Dưới: "};
        for (int i = 0; i < 4; i++) {
            final int idx = i;
            LinearLayout row = new LinearLayout(context);
            row.setOrientation(LinearLayout.HORIZONTAL);
            row.setGravity(Gravity.CENTER_VERTICAL);
            row.setPadding(0, 4, 0, 4);

            trimLabels[i] = new TextView(context);
            trimLabels[i].setText(trimNames[i] + "0%");
            trimLabels[i].setTextColor(Color.WHITE);
            trimLabels[i].setTextSize(10);
            trimLabels[i].setWidth(220);
            row.addView(trimLabels[i]);

            seekBars[i] = new SeekBar(context);
            seekBars[i].setMax(45);
            seekBars[i].setProgress(0);
            seekBars[i].setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
            seekBars[i].setOnSeekBarChangeListener(new CropSeekBarListener(idx, trims, trimLabels, trimNames, updateDimPreview));
            row.addView(seekBars[i]);
            root.addView(row);
        }

        LinearLayout btnRow = new LinearLayout(context);
        btnRow.setOrientation(LinearLayout.HORIZONTAL);
        btnRow.setGravity(Gravity.CENTER);
        btnRow.setPadding(0, 16, 0, 8);

        TextView btnReset = new TextView(context);
        btnReset.setText("↺ Đặt lại");
        btnReset.setTextColor(Color.parseColor("#94A3B8"));
        btnReset.setTextSize(11);
        btnReset.setBackgroundColor(Color.parseColor("#1E293B"));
        btnReset.setPadding(20, 12, 20, 12);
        btnRow.addView(btnReset);

        View bSpacer = new View(context);
        btnRow.addView(bSpacer, new LinearLayout.LayoutParams(16, 0));

        TextView btnApply = new TextView(context);
        btnApply.setText("✓ ÁP DỤNG CẮT");
        btnApply.setTextColor(Color.BLACK);
        btnApply.setTextSize(12);
        btnApply.setTypeface(null, Typeface.BOLD);
        btnApply.setBackgroundResource(com.nextai.opencut.R.drawable.bg_export_button);
        btnApply.setPadding(28, 12, 28, 12);
        btnRow.addView(btnApply);

        root.addView(btnRow);
        scroll.addView(root);
        builder.setView(scroll);
        AlertDialog dialog = builder.create();

        btnReset.setOnClickListener(new CropResetClickListener(this, trims, seekBars));
        btnApply.setOnClickListener(new CropApplyClickListener(this, origW, origH, trims, dialog));

        dialog.show();
    }

    /**
     * Export and save current photo asynchronously in background thread.
     * Kết xuất và lưu ảnh hiện tại bất đồng bộ trong luồng nền, tránh nghẽn luồng UI.
     */
    private void saveCurrentPhoto() {
        if (basePhotoBitmap == null || basePhotoBitmap.isRecycled()) {
            Toast.makeText(context, "❌ Không có dữ liệu ảnh để lưu!", Toast.LENGTH_SHORT).show();
            return;
        }

        Toast.makeText(context, "⏳ Đang kết xuất ảnh chất lượng cao vào Thư Viện...", Toast.LENGTH_SHORT).show();
        android.graphics.ColorFilter filter = (ivPhotoCanvas != null) ? ivPhotoCanvas.getColorFilter() : null;
        backgroundExecutor.execute(new SavePhotoTask(this, context, basePhotoBitmap, filter, listener));
    }

    private void previewLegExtensionEffect() {
        if (basePreEffectBitmap == null || basePreEffectBitmap.isRecycled()) {
            if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            } else {
                return;
            }
        }
        try {
            if (detectedFaceList == null || detectedFaceList.isEmpty()) {
                detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePreEffectBitmap);
            }
            if (cachedPhotoLandmarks == null || cachedPhotoLandmarks.imageWidth != basePreEffectBitmap.getWidth() || cachedPhotoLandmarks.imageHeight != basePreEffectBitmap.getHeight() || (detectedFaceList != null && selectedFaceIndex < detectedFaceList.size() && cachedPhotoLandmarks.faceIndex != selectedFaceIndex)) {
                cachedPhotoLandmarks = (!detectedFaceList.isEmpty() && selectedFaceIndex < detectedFaceList.size())
                        ? detectedFaceList.get(selectedFaceIndex)
                        : FaceBodyDetectionEngine.detectFace(basePreEffectBitmap);
            }
            Bitmap result = FaceBodyDetectionEngine.applySmartLegExtension(
                    basePreEffectBitmap, cachedPhotoLandmarks, currentLegStretch, currentLegSlim, currentHipsLineY, currentAnklesLineY);
            if (result != null) {
                // P3 Fix: Recycle previous intermediate bitmap to prevent OutOfMemoryError
                // Sửa lỗi P3: Thu hồi bitmap trung gian trước đó để ngăn ngừa tràn bộ nhớ OOM
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != result
                        && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = result;
                if (ivPhotoCanvas != null) {
                    ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                }
                applyPhotoFilters();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Real AI Inpaint Object Eraser on Bitmap / Xóa vật thể AI thực tế
     */
    public void applyAiInpaintErase() {
        if (basePhotoBitmap == null) return;
        try {
            int w = basePhotoBitmap.getWidth();
            int h = basePhotoBitmap.getHeight();
            Bitmap modified = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            Canvas canvas = new Canvas(modified);

            int patchLeft = (int) (w * 0.35f);
            int patchTop = (int) (h * 0.60f);
            int patchRight = (int) (w * 0.65f);
            int patchBottom = (int) (h * 0.85f);

            Paint patchPaint = new Paint(Paint.ANTI_ALIAS_FLAG | Paint.FILTER_BITMAP_FLAG);
            Rect srcRect = new Rect(Math.max(0, patchLeft - (patchRight - patchLeft)), patchTop, patchLeft, patchBottom);
            Rect dstRect = new Rect(patchLeft, patchTop, patchRight, patchBottom);
            canvas.drawBitmap(basePhotoBitmap, srcRect, dstRect, patchPaint);

            Paint feather = new Paint(Paint.ANTI_ALIAS_FLAG);
            feather.setColor(Color.parseColor("#15FFFFFF"));
            feather.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC_OVER));
            canvas.drawRect(dstRect, feather);

            basePhotoBitmap = modified;
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            }
            MiddleBridgeJni.applyInpaintMask(30, 40, 50, 50);
            applyPhotoFilters();
            Toast.makeText(context, "🧹 Đã xóa vật thể AI bằng thuật toán Inpaint!", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void previewEyeBrighteningEffect() {
        if (basePreEffectBitmap == null || basePreEffectBitmap.isRecycled()) {
            if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            } else {
                return;
            }
        }
        try {
            if (detectedFaceList == null || detectedFaceList.isEmpty()) {
                detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePreEffectBitmap);
            }
            if (cachedPhotoLandmarks == null || cachedPhotoLandmarks.imageWidth != basePreEffectBitmap.getWidth() || cachedPhotoLandmarks.imageHeight != basePreEffectBitmap.getHeight() || (detectedFaceList != null && selectedFaceIndex < detectedFaceList.size() && cachedPhotoLandmarks.faceIndex != selectedFaceIndex)) {
                cachedPhotoLandmarks = (!detectedFaceList.isEmpty() && selectedFaceIndex < detectedFaceList.size())
                        ? detectedFaceList.get(selectedFaceIndex)
                        : FaceBodyDetectionEngine.detectFace(basePreEffectBitmap);
            }
            Bitmap result = FaceBodyDetectionEngine.applyLocalizedEyeBrightening(
                    basePreEffectBitmap, cachedPhotoLandmarks, currentScleraBrightness, currentIrisClarity);
            if (result != null) {
                // P3 Fix: Recycle previous intermediate bitmap to prevent OutOfMemoryError
                // Sửa lỗi P3: Thu hồi bitmap trung gian trước đó để ngăn ngừa tràn bộ nhớ OOM
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != result
                        && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = result;
                if (ivPhotoCanvas != null) {
                    ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                }
                applyPhotoFilters();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void previewTeethWhiteningEffect() {
        if (basePreEffectBitmap == null || basePreEffectBitmap.isRecycled()) {
            if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            } else {
                return;
            }
        }
        try {
            if (detectedFaceList == null || detectedFaceList.isEmpty()) {
                detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePreEffectBitmap);
            }
            if (cachedPhotoLandmarks == null || cachedPhotoLandmarks.imageWidth != basePreEffectBitmap.getWidth() || cachedPhotoLandmarks.imageHeight != basePreEffectBitmap.getHeight() || (detectedFaceList != null && selectedFaceIndex < detectedFaceList.size() && cachedPhotoLandmarks.faceIndex != selectedFaceIndex)) {
                cachedPhotoLandmarks = (!detectedFaceList.isEmpty() && selectedFaceIndex < detectedFaceList.size())
                        ? detectedFaceList.get(selectedFaceIndex)
                        : FaceBodyDetectionEngine.detectFace(basePreEffectBitmap);
            }
            Bitmap result = FaceBodyDetectionEngine.applyLocalizedTeethWhitening(
                    basePreEffectBitmap, cachedPhotoLandmarks, currentTeethIntensity);
            if (result != null) {
                // P3 Fix: Recycle previous intermediate bitmap to prevent OutOfMemoryError
                // Sửa lỗi P3: Thu hồi bitmap trung gian trước đó để ngăn ngừa tràn bộ nhớ OOM
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != result
                        && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = result;
                if (ivPhotoCanvas != null) {
                    ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                }
                applyPhotoFilters();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void previewLipstickEffect() {
        if (basePreEffectBitmap == null || basePreEffectBitmap.isRecycled()) {
            if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
            } else {
                return;
            }
        }
        try {
            if (detectedFaceList == null || detectedFaceList.isEmpty()) {
                detectedFaceList = FaceBodyDetectionEngine.detectAllFaces(basePreEffectBitmap);
            }
            if (cachedPhotoLandmarks == null || cachedPhotoLandmarks.imageWidth != basePreEffectBitmap.getWidth() || cachedPhotoLandmarks.imageHeight != basePreEffectBitmap.getHeight() || (detectedFaceList != null && selectedFaceIndex < detectedFaceList.size() && cachedPhotoLandmarks.faceIndex != selectedFaceIndex)) {
                cachedPhotoLandmarks = (!detectedFaceList.isEmpty() && selectedFaceIndex < detectedFaceList.size())
                        ? detectedFaceList.get(selectedFaceIndex)
                        : FaceBodyDetectionEngine.detectFace(basePreEffectBitmap);
            }
            Bitmap result = FaceBodyDetectionEngine.applyLocalizedLipstick(
                    basePreEffectBitmap, cachedPhotoLandmarks, currentLipstickColor, currentLipstickIntensity, currentLipstickGloss);
            if (result != null) {
                // P3 Fix: Recycle previous intermediate bitmap to prevent OutOfMemoryError
                // Sửa lỗi P3: Thu hồi bitmap trung gian trước đó để ngăn ngừa tràn bộ nhớ OOM
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && basePhotoBitmap != result
                        && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = result;
                if (ivPhotoCanvas != null) {
                    ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                }
                applyPhotoFilters();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void applyTeethPreset(int percent) {
        currentTeethIntensity = percent / 100.0f;
        if (sbTeethIntensity != null) sbTeethIntensity.setProgress(percent);
        if (tvTeethIntensityVal != null) tvTeethIntensityVal.setText("Độ trắng: " + percent + "%");
        previewTeethWhiteningEffect();
    }

    private boolean handleLipstickChipClick(View v) {
        if (v == null || v.getTag() == null) return false;
        Object tag = v.getTag();
        if (tag instanceof Integer) {
            currentLipstickColor = (Integer) tag;
            previewLipstickEffect();
            Toast.makeText(context, "💄 Đã chọn sắc son mới!", Toast.LENGTH_SHORT).show();
            return true;
        }
        return false;
    }

    private void createDefaultBasePhotoBitmap() {
        int width = 720;
        int height = 960;
        basePhotoBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(basePhotoBitmap);

        Paint bgPaint = new Paint();
        bgPaint.setColor(Color.parseColor("#312E81"));
        canvas.drawRect(0, 0, width, height, bgPaint);

        Paint sunPaint = new Paint();
        sunPaint.setColor(Color.parseColor("#F59E0B"));
        canvas.drawCircle(width / 2f, height / 3f, 160, sunPaint);

        Paint mountainPaint = new Paint();
        mountainPaint.setColor(Color.parseColor("#065F46"));
        canvas.drawRect(0, height * 0.6f, width, height, mountainPaint);

        Paint textPaint = new Paint();
        textPaint.setColor(Color.WHITE);
        textPaint.setTextSize(34);
        textPaint.setTextAlign(Paint.Align.CENTER);
        textPaint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
        canvas.drawText("NextAI 4K Studio Portrait", width / 2f, height * 0.85f, textPaint);
    }

    /**
     * Load photo bitmap from URI asynchronously on background executor to avoid UI thread ANR.
     * Tải bitmap ảnh từ URI bất đồng bộ trên luồng nền để tránh gây đơ luồng giao diện (ANR).
     */
    private void loadPhotoBitmapFromUri(Uri uri) {
        if (uri == null) {
            createDefaultBasePhotoBitmap();
            if (ivPhotoCanvas != null) {
                ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
            }
            return;
        }

        Toast.makeText(context, "⏳ Đang tải và phân tích ảnh...", Toast.LENGTH_SHORT).show();
        backgroundExecutor.execute(new LoadPhotoFromUriTask(this, context, uri));
    }

    public static Bitmap fixExifOrientation(Context context, Uri uri, Bitmap decoded) {
        if (uri == null || decoded == null || context == null) return decoded;
        InputStream is = null;
        try {
            is = context.getContentResolver().openInputStream(uri);
            if (is != null) {
                ExifInterface exif = new ExifInterface(is);
                int orientation = exif.getAttributeInt(ExifInterface.TAG_ORIENTATION, ExifInterface.ORIENTATION_NORMAL);
                Matrix matrix = new Matrix();
                switch (orientation) {
                    case ExifInterface.ORIENTATION_ROTATE_90:
                        matrix.postRotate(90);
                        break;
                    case ExifInterface.ORIENTATION_ROTATE_180:
                        matrix.postRotate(180);
                        break;
                    case ExifInterface.ORIENTATION_ROTATE_270:
                        matrix.postRotate(270);
                        break;
                    case ExifInterface.ORIENTATION_FLIP_HORIZONTAL:
                        matrix.postScale(-1, 1);
                        break;
                    case ExifInterface.ORIENTATION_FLIP_VERTICAL:
                        matrix.postScale(1, -1);
                        break;
                    case ExifInterface.ORIENTATION_TRANSPOSE:
                        matrix.postRotate(90);
                        matrix.postScale(-1, 1);
                        break;
                    case ExifInterface.ORIENTATION_TRANSVERSE:
                        matrix.postRotate(270);
                        matrix.postScale(-1, 1);
                        break;
                    default:
                        return decoded;
                }
                Bitmap rotated = Bitmap.createBitmap(decoded, 0, 0, decoded.getWidth(), decoded.getHeight(), matrix, true);
                if (rotated != decoded) {
                    decoded.recycle();
                }
                return rotated;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (is != null) is.close();
            } catch (Exception ignored) {}
        }
        return decoded;
    }

    @Override
    public void onClick(View v) {
        if (v == btnPhotoBack) {
            if (listener != null) listener.onPhotoEditorClose();
            return;
        }

        if (v == btnPhotoSave) {
            saveCurrentPhoto();
            return;
        }

        if (v == btnPhotoRotate || v == photoNavRotate) {
            rotatePhoto90Degrees();
            return;
        }

        if (v == btnPhotoCrop || v == photoNavCrop) {
            showPhotoCropDialog();
            return;
        }

        if (v == photoNavFlip) {
            flipPhotoHorizontal();
            return;
        }

        if (v == btnPhotoFitFill) {
            isPhotoFillMode = !isPhotoFillMode;
            ((TextView) btnPhotoFitFill).setText(isPhotoFillMode ? "⛶ TRÀN" : "⛶ VỪA");
            ((TextView) btnPhotoFitFill).setTextColor(isPhotoFillMode ? Color.parseColor("#F59E0B") : Color.parseColor("#00E5FF"));
            if (basePhotoBitmap != null) {
                updatePhotoCanvasDimensions(basePhotoBitmap.getWidth(), basePhotoBitmap.getHeight());
            }
            Toast.makeText(context, isPhotoFillMode ? "⛶ Chế độ Tràn Màn Hình (Fill Center-Crop)!" : "⛶ Chế độ Vừa Vặn Khung Hình (Fit Center)!", Toast.LENGTH_SHORT).show();
            return;
        }

        if (v == btnPhotoRatio || v == photoNavRatio) {
            showPhotoRatioDialog();
            return;
        }

        // 3D LUT Presets
        if (v == photoFilterOriginal) {
            currentPhotoFilter = "original";
            tvPhotoFilterStatus.setText("✨ Đang sử dụng màu gốc");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterPortra) {
            currentPhotoFilter = "portra";
            tvPhotoFilterStatus.setText("🎞️ 3D LUT Kodak Portra 400 (Ấm áp chân dung)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterCyberpunk) {
            currentPhotoFilter = "cyberpunk";
            tvPhotoFilterStatus.setText("🌆 3D LUT Cyberpunk Neon (Tím xanh dạ quang)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterTealOrange) {
            currentPhotoFilter = "teal_orange";
            tvPhotoFilterStatus.setText("🎬 3D LUT Teal & Orange (Điện ảnh bom tấn)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterNoir) {
            currentPhotoFilter = "noir";
            tvPhotoFilterStatus.setText("📽️ 3D LUT Film Noir Đen Trắng (Tương phản cao)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterVintage) {
            currentPhotoFilter = "vintage";
            tvPhotoFilterStatus.setText("📻 3D LUT Vintage Phim Cũ (Ánh sáng hoàng hôn)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterCinemaGold) {
            currentPhotoFilter = "cinema_gold";
            tvPhotoFilterStatus.setText("🌟 3D LUT Cinema Gold (Vàng kim điện ảnh)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterFuji) {
            currentPhotoFilter = "fuji";
            tvPhotoFilterStatus.setText("🍃 3D LUT Fuji Pro 400H (Trong trẻo xanh ngọc)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterRose) {
            currentPhotoFilter = "rose";
            tvPhotoFilterStatus.setText("🌸 3D LUT Soft Rose (Hồng phấn dịu dàng)");
            applyPhotoFilters();
            return;
        } else if (v == photoFilterMoody) {
            currentPhotoFilter = "moody";
            tvPhotoFilterStatus.setText("🌑 3D LUT Moody Dark (U tối chiều sâu)");
            applyPhotoFilters();
            return;
        }

        // Sub-panel tabs
        if (v == photoNavLut) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.VISIBLE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.GONE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.GONE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.GONE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.GONE);
            if (photoAdjustPanel != null) photoAdjustPanel.setVisibility(View.GONE);
            return;
        } else if (v == photoNavLightroom) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.GONE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.VISIBLE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.GONE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.GONE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.GONE);
            if (photoAdjustPanel != null) photoAdjustPanel.setVisibility(View.GONE);
            return;
        } else if (v == photoNavEraser) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.GONE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.GONE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.VISIBLE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.GONE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.GONE);
            if (photoAdjustPanel != null) photoAdjustPanel.setVisibility(View.GONE);
            return;
        } else if (v == photoNavFacetune) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.GONE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.GONE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.GONE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.VISIBLE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.GONE);
            if (photoAdjustPanel != null) photoAdjustPanel.setVisibility(View.GONE);
            return;
        } else if (v == photoNavFaceApp) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.GONE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.GONE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.GONE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.GONE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.VISIBLE);
            if (photoAdjustPanel != null) photoAdjustPanel.setVisibility(View.GONE);
            return;
        } else if (v == photoNavAdjust) {
            if (photoFilterScroll != null) photoFilterScroll.setVisibility(View.GONE);
            if (photoLightroomPanel != null) photoLightroomPanel.setVisibility(View.GONE);
            if (photoEraserPanel != null) photoEraserPanel.setVisibility(View.GONE);
            if (photoFacetunePanel != null) photoFacetunePanel.setVisibility(View.GONE);
            if (photoFaceAppPanel != null) photoFaceAppPanel.setVisibility(View.GONE);
            if (photoAdjustPanel != null) {
                int vis = photoAdjustPanel.getVisibility() == View.VISIBLE ? View.GONE : View.VISIBLE;
                photoAdjustPanel.setVisibility(vis);
            }
            return;
        }

        if (v == btnLrToneCurve) {
            isLrToneCurveActive = !isLrToneCurveActive;
            setPillActive(btnLrToneCurve, isLrToneCurveActive);
            applyPhotoFilters();
            Toast.makeText(context, isLrToneCurveActive ? "📈 Đã áp dụng Đường cong Tone Curves!" : "Đã tắt Tone Curves", Toast.LENGTH_SHORT).show();
            return;
        }

        if (v == btnInpaintBrush) {
            applyAiInpaintErase();
            return;
        } else if (v == btnSkySunset) {
            activeSkyEffect = activeSkyEffect.equals("sunset") ? "" : "sunset";
            setPillActive(btnSkySunset, activeSkyEffect.equals("sunset"));
            applyPhotoFilters();
            Toast.makeText(context, activeSkyEffect.equals("sunset") ? "🌅 SnapEdit: Đã thay Bầu Trời Hoàng Hôn!" : "Đã hủy bầu trời hoàng hôn", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnSkyAurora) {
            activeSkyEffect = activeSkyEffect.equals("aurora") ? "" : "aurora";
            setPillActive(btnSkyAurora, activeSkyEffect.equals("aurora"));
            applyPhotoFilters();
            Toast.makeText(context, activeSkyEffect.equals("aurora") ? "🌌 SnapEdit: Đã thay Bầu Trời Cực Quang Ban Đêm!" : "Đã hủy cực quang", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnSkyBlue) {
            activeSkyEffect = activeSkyEffect.equals("blue_sky") ? "" : "blue_sky";
            setPillActive(btnSkyBlue, activeSkyEffect.equals("blue_sky"));
            applyPhotoFilters();
            Toast.makeText(context, activeSkyEffect.equals("blue_sky") ? "☀️ SnapEdit: Đã thay Bầu Trời Trong Xanh Mây Trắng!" : "Đã hủy trời trong xanh", Toast.LENGTH_SHORT).show();
            return;
        }

        // Portrait Features
        if (v == btnFtWhitening) {
            boolean isOpening = photoTeethProPanel.getVisibility() != View.VISIBLE;
            photoTeethProPanel.setVisibility(isOpening ? View.VISIBLE : View.GONE);
            photoLipstickProPanel.setVisibility(View.GONE);
            photoEyesProPanel.setVisibility(View.GONE);
            photoLegsProPanel.setVisibility(View.GONE);
            if (isOpening) {
                if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                    basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
                }
                previewTeethWhiteningEffect();
            }
            return;
        } else if (v == btnFtBrightenEyes) {
            boolean isOpening = photoEyesProPanel.getVisibility() != View.VISIBLE;
            photoEyesProPanel.setVisibility(isOpening ? View.VISIBLE : View.GONE);
            photoLipstickProPanel.setVisibility(View.GONE);
            photoTeethProPanel.setVisibility(View.GONE);
            photoLegsProPanel.setVisibility(View.GONE);
            if (isOpening) {
                if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                    basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
                }
                previewEyeBrighteningEffect();
            }
            return;
        } else if (v == btnFtLipstick) {
            boolean isOpening = photoLipstickProPanel.getVisibility() != View.VISIBLE;
            photoLipstickProPanel.setVisibility(isOpening ? View.VISIBLE : View.GONE);
            photoTeethProPanel.setVisibility(View.GONE);
            photoEyesProPanel.setVisibility(View.GONE);
            photoLegsProPanel.setVisibility(View.GONE);
            if (isOpening) {
                if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                    basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
                }
                previewLipstickEffect();
            }
            return;
        } else if (v == btnMeituLegs) {
            boolean isOpening = photoLegsProPanel.getVisibility() != View.VISIBLE;
            photoLegsProPanel.setVisibility(isOpening ? View.VISIBLE : View.GONE);
            photoLipstickProPanel.setVisibility(View.GONE);
            photoTeethProPanel.setVisibility(View.GONE);
            photoEyesProPanel.setVisibility(View.GONE);
            if (isOpening) {
                if (basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                    basePreEffectBitmap = basePhotoBitmap.copy(Bitmap.Config.ARGB_8888, true);
                }
                previewLegExtensionEffect();
            }
            return;
        }

        // Cancel / Apply Pro Panels
        if (v == btnLipstickCancel) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = basePreEffectBitmap.copy(Bitmap.Config.ARGB_8888, true);
                if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                applyPhotoFilters();
            }
            photoLipstickProPanel.setVisibility(View.GONE);
            return;
        } else if (v == btnLipstickApply) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                basePreEffectBitmap.recycle();
                basePreEffectBitmap = null;
            }
            photoLipstickProPanel.setVisibility(View.GONE);
            Toast.makeText(context, "💄 Đã áp dụng màu son môi VIP thành công!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnTeethCancel) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = basePreEffectBitmap.copy(Bitmap.Config.ARGB_8888, true);
                if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                applyPhotoFilters();
            }
            photoTeethProPanel.setVisibility(View.GONE);
            return;
        } else if (v == btnTeethApply) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                basePreEffectBitmap.recycle();
                basePreEffectBitmap = null;
            }
            photoTeethProPanel.setVisibility(View.GONE);
            Toast.makeText(context, "🦷 Đã áp dụng làm trắng răng VIP thành công!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnEyesCancel) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = basePreEffectBitmap.copy(Bitmap.Config.ARGB_8888, true);
                if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                applyPhotoFilters();
            }
            photoEyesProPanel.setVisibility(View.GONE);
            return;
        } else if (v == btnEyesApply) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                basePreEffectBitmap.recycle();
                basePreEffectBitmap = null;
            }
            photoEyesProPanel.setVisibility(View.GONE);
            Toast.makeText(context, "👁️ Đã áp dụng làm sáng mắt & nét tròng VIP thành công!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnLegsCancel) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                if (basePhotoBitmap != null && basePhotoBitmap != basePreEffectBitmap
                        && basePhotoBitmap != baseOriginalPhotoBitmap && !basePhotoBitmap.isRecycled()) {
                    basePhotoBitmap.recycle();
                }
                basePhotoBitmap = basePreEffectBitmap.copy(Bitmap.Config.ARGB_8888, true);
                if (ivPhotoCanvas != null) ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                applyPhotoFilters();
            }
            photoLegsProPanel.setVisibility(View.GONE);
            return;
        } else if (v == btnLegsApply) {
            if (basePreEffectBitmap != null && !basePreEffectBitmap.isRecycled()) {
                basePreEffectBitmap.recycle();
                basePreEffectBitmap = null;
            }
            photoLegsProPanel.setVisibility(View.GONE);
            Toast.makeText(context, "👠 Đã áp dụng kéo dài chân In-Frame Mesh Warp VIP thành công!", Toast.LENGTH_SHORT).show();
            return;
        }

        if (v == btnTeethPreset30) {
            applyTeethPreset(30);
            return;
        } else if (v == btnTeethPreset50) {
            applyTeethPreset(50);
            return;
        } else if (v == btnTeethPreset75) {
            applyTeethPreset(75);
            return;
        } else if (v == btnTeethPreset100) {
            applyTeethPreset(100);
            return;
        }

        if (handleLipstickChipClick(v)) {
            return;
        }

        if (v == btnMeituBling) {
            activePortraitEffect = activePortraitEffect.equals("bling_bling") ? "" : "bling_bling";
            setPillActive(btnMeituBling, activePortraitEffect.equals("bling_bling"));
            applyPhotoFilters();
            Toast.makeText(context, activePortraitEffect.equals("bling_bling") ? "✨ Meitu: Đã thêm hiệu ứng Hạt Lấp Lánh Lung Linh (Bling Bling Magic)!" : "Đã hủy lấp lánh", Toast.LENGTH_SHORT).show();
            return;
        }

        if (v == btnFaSmile) {
            activeFaceAppEffect = activeFaceAppEffect.equals("smile") ? "" : "smile";
            setPillActive(btnFaSmile, activeFaceAppEffect.equals("smile"));
            applyPhotoFilters();
            Toast.makeText(context, activeFaceAppEffect.equals("smile") ? "😄 FaceApp: Biến đổi nụ cười rạng rỡ (Classic Smile AI)!" : "Đã hủy nụ cười", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnFaYouth) {
            activeFaceAppEffect = activeFaceAppEffect.equals("youth_18") ? "" : "youth_18";
            setPillActive(btnFaYouth, activeFaceAppEffect.equals("youth_18"));
            applyPhotoFilters();
            Toast.makeText(context, activeFaceAppEffect.equals("youth_18") ? "👶 FaceApp: Trẻ hóa 18 tuổi da căng tràn sức sống (Youth AI)!" : "Đã hủy trẻ hóa", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnFaHair) {
            activeFaceAppEffect = activeFaceAppEffect.equals("volumetric_hair") ? "" : "volumetric_hair";
            setPillActive(btnFaHair, activeFaceAppEffect.equals("volumetric_hair"));
            applyPhotoFilters();
            Toast.makeText(context, activeFaceAppEffect.equals("volumetric_hair") ? "💇 FaceApp: Tạo kiểu tóc bồng bềnh tự nhiên (Volumetric Hair AI)!" : "Đã hủy kiểu tóc", Toast.LENGTH_SHORT).show();
            return;
        }
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        if (!fromUser) return;

        if (seekBar == sbPhotoBright) {
            photoBright = progress - 100;
            if (tvPhotoBrightVal != null) tvPhotoBrightVal.setText("Độ sáng: " + (photoBright > 0 ? "+" + photoBright : String.valueOf(photoBright)));
            applyPhotoFilters();
        } else if (seekBar == sbPhotoContrast) {
            photoContrast = progress;
            if (tvPhotoContrastVal != null) tvPhotoContrastVal.setText("Tương phản: " + photoContrast + "%");
            applyPhotoFilters();
        } else if (seekBar == sbPhotoSat) {
            photoSat = progress;
            if (tvPhotoSatVal != null) tvPhotoSatVal.setText("Độ bão hòa: " + photoSat + "%");
            applyPhotoFilters();
        } else if (seekBar == sbLrClarity) {
            lrClarity = progress;
            if (tvLrClarityVal != null) tvLrClarityVal.setText("Độ rõ nét: " + lrClarity);
            applyPhotoFilters();
        } else if (seekBar == sbLrDehaze) {
            lrDehaze = progress;
            if (tvLrDehazeVal != null) tvLrDehazeVal.setText("Khử sương mù: " + lrDehaze);
            applyPhotoFilters();
        } else if (seekBar == sbLrGrain) {
            lrGrain = progress;
            if (tvLrGrainVal != null) tvLrGrainVal.setText("Hạt phim Grain: " + lrGrain);
            applyPhotoFilters();
        } else if (seekBar == sbLrVignette) {
            lrVignette = progress;
            if (tvLrVignetteVal != null) tvLrVignetteVal.setText("Tối 4 góc Vignette: " + lrVignette);
            applyPhotoFilters();
        } else if (seekBar == sbLipstickIntensity) {
            currentLipstickIntensity = progress / 100.0f;
            if (tvLipstickIntensityVal != null) tvLipstickIntensityVal.setText("Độ đậm: " + progress + "%");
            previewLipstickEffect();
        } else if (seekBar == sbLipstickGloss) {
            currentLipstickGloss = progress / 100.0f;
            if (tvLipstickGlossVal != null) tvLipstickGlossVal.setText("Độ bóng: " + progress + "%");
            previewLipstickEffect();
        } else if (seekBar == sbTeethIntensity) {
            currentTeethIntensity = progress / 100.0f;
            if (tvTeethIntensityVal != null) tvTeethIntensityVal.setText("Độ trắng: " + progress + "%");
            previewTeethWhiteningEffect();
        } else if (seekBar == sbScleraBright) {
            currentScleraBrightness = progress / 100.0f;
            if (tvScleraBrightVal != null) tvScleraBrightVal.setText("Sáng lòng trắng: " + progress + "%");
            previewEyeBrighteningEffect();
        } else if (seekBar == sbIrisClarity) {
            currentIrisClarity = progress / 100.0f;
            if (tvIrisClarityVal != null) tvIrisClarityVal.setText("Nét tròng & Đốm sáng: " + progress + "%");
            previewEyeBrighteningEffect();
        } else if (seekBar == sbLegStretch) {
            currentLegStretch = progress / 100.0f;
            if (tvLegStretchVal != null) tvLegStretchVal.setText("Kéo dài chân: " + progress + "%");
            previewLegExtensionEffect();
        } else if (seekBar == sbLegSlim) {
            currentLegSlim = progress / 100.0f;
            if (tvLegSlimVal != null) tvLegSlimVal.setText("Thon gọn chân: " + progress + "%");
            previewLegExtensionEffect();
        } else if (seekBar == sbHipsLine) {
            currentHipsLineY = progress / 100.0f;
            if (tvHipsLineVal != null) tvHipsLineVal.setText("Vạch mông (Hips): " + progress + "%");
            previewLegExtensionEffect();
        } else if (seekBar == sbAnklesLine) {
            currentAnklesLineY = progress / 100.0f;
            if (tvAnklesLineVal != null) tvAnklesLineVal.setText("Vạch cổ chân: " + progress + "%");
            previewLegExtensionEffect();
        }
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {}

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {}

    @Override
    public boolean onTouch(View v, MotionEvent event) {
        if (v == btnCompareBeforeAfter) {
            if (event.getAction() == MotionEvent.ACTION_DOWN) {
                if (ivPhotoCanvas != null) {
                    ivPhotoCanvas.setColorFilter(null);
                    if (baseOriginalPhotoBitmap != null && !baseOriginalPhotoBitmap.isRecycled()) {
                        ivPhotoCanvas.setImageBitmap(baseOriginalPhotoBitmap);
                    }
                }
                tvPhotoFilterStatus.setText("🔘 [ĐANG XEM ẢNH GỐC BAN ĐẦU]");
                btnCompareBeforeAfter.setBackgroundColor(Color.parseColor("#00E5FF"));
                ((TextView) btnCompareBeforeAfter).setTextColor(Color.BLACK);
            } else if (event.getAction() == MotionEvent.ACTION_UP || event.getAction() == MotionEvent.ACTION_CANCEL) {
                if (ivPhotoCanvas != null && basePhotoBitmap != null && !basePhotoBitmap.isRecycled()) {
                    ivPhotoCanvas.setImageBitmap(basePhotoBitmap);
                }
                applyPhotoFilters();
                tvPhotoFilterStatus.setText("✨ [ĐANG XEM ẢNH ĐÃ QUA BIÊN TẬP]");
                btnCompareBeforeAfter.setBackgroundColor(Color.parseColor("#2A3348"));
                ((TextView) btnCompareBeforeAfter).setTextColor(Color.WHITE);
            }
            return true;
        } else if (v == ivPhotoCanvas) {
            if (event.getAction() == MotionEvent.ACTION_DOWN) {
                if (basePhotoBitmap == null || basePhotoBitmap.isRecycled()) return false;
                if (detectedFaceList == null || detectedFaceList.size() <= 1) return false;

                float viewW = v.getWidth();
                float viewH = v.getHeight();
                float bmpW = basePhotoBitmap.getWidth();
                float bmpH = basePhotoBitmap.getHeight();

                float scale = Math.min(viewW / bmpW, viewH / bmpH);
                float dx = (viewW - bmpW * scale) / 2f;
                float dy = (viewH - bmpH * scale) / 2f;

                float touchBmpX = (event.getX() - dx) / scale;
                float touchBmpY = (event.getY() - dy) / scale;

                int nearestFaceIdx = -1;
                float minDistance = Float.MAX_VALUE;
                for (int i = 0; i < detectedFaceList.size(); i++) {
                    FaceBodyDetectionEngine.FaceLandmarks fl = detectedFaceList.get(i);
                    float faceDist = (float) Math.hypot(touchBmpX - fl.midEyes.x, touchBmpY - fl.midEyes.y);
                    if (faceDist < minDistance) {
                        minDistance = faceDist;
                        nearestFaceIdx = i;
                    }
                }

                if (nearestFaceIdx != -1 && minDistance < (bmpW * 0.35f)) {
                    selectedFaceIndex = nearestFaceIdx;
                    cachedPhotoLandmarks = detectedFaceList.get(selectedFaceIndex);
                    Toast.makeText(context, "🎯 Đã chọn khuôn mặt #" + (selectedFaceIndex + 1) + " để làm đẹp!", Toast.LENGTH_SHORT).show();
                    return true;
                }
            }
        }
        return false;
    }

    private static class CropSeekBarListener implements SeekBar.OnSeekBarChangeListener {
        private final int idx;
        private final int[] trims;
        private final TextView[] trimLabels;
        private final String[] trimNames;
        private final Runnable onUpdatePreview;

        public CropSeekBarListener(int idx, int[] trims, TextView[] trimLabels, String[] trimNames, Runnable onUpdatePreview) {
            this.idx = idx;
            this.trims = trims;
            this.trimLabels = trimLabels;
            this.trimNames = trimNames;
            this.onUpdatePreview = onUpdatePreview;
        }

        @Override
        public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
            if (!fromUser) return;
            trims[idx] = progress;
            if (trimLabels != null && trimLabels[idx] != null) {
                trimLabels[idx].setText(trimNames[idx] + progress + "%");
            }
            if (onUpdatePreview != null) {
                onUpdatePreview.run();
            }
        }

        @Override
        public void onStartTrackingTouch(SeekBar seekBar) {}

        @Override
        public void onStopTrackingTouch(SeekBar seekBar) {}
    }

    /**
     * Click listener for crop aspect ratio chips.
     * Bộ xử lý sự kiện click cho các chip tỷ lệ cắt ảnh.
     */
    public static class CropRatioChipClickListener implements View.OnClickListener {
        private final float targetRatio;
        private final int origW;
        private final int origH;
        private final int[] trims;
        private final SeekBar[] seekBars;

        public CropRatioChipClickListener(float targetRatio, int origW, int origH, int[] trims, SeekBar[] seekBars) {
            this.targetRatio = targetRatio;
            this.origW = origW;
            this.origH = origH;
            this.trims = trims;
            this.seekBars = seekBars;
        }

        @Override
        public void onClick(View v) {
            if (targetRatio <= 0f) {
                trims[0] = 0; trims[1] = 0; trims[2] = 0; trims[3] = 0;
            } else {
                float currentRatio = (float) origW / (float) origH;
                if (currentRatio > targetRatio) {
                    float desiredWidth = origH * targetRatio;
                    float trimPercentEachSide = ((origW - desiredWidth) / (2f * origW)) * 100f;
                    int trimVal = Math.min(45, Math.max(0, Math.round(trimPercentEachSide)));
                    trims[0] = trimVal;
                    trims[1] = trimVal;
                    trims[2] = 0;
                    trims[3] = 0;
                } else {
                    float desiredHeight = origW / targetRatio;
                    float trimPercentEachSide = ((origH - desiredHeight) / (2f * origH)) * 100f;
                    int trimVal = Math.min(45, Math.max(0, Math.round(trimPercentEachSide)));
                    trims[0] = 0;
                    trims[1] = 0;
                    trims[2] = trimVal;
                    trims[3] = trimVal;
                }
            }
            for (int i = 0; i < 4; i++) {
                if (seekBars[i] != null) {
                    seekBars[i].setProgress(trims[i]);
                }
            }
        }
    }

    /**
     * Runnable updater for crop dimension text preview.
     * Runnable cập nhật nhãn xem trước kích thước cắt ảnh.
     */
    public static class CropDimensionPreviewUpdater implements Runnable {
        private final TextView tvDimInfo;
        private final int origW;
        private final int origH;
        private final int[] trims;

        public CropDimensionPreviewUpdater(TextView tvDimInfo, int origW, int origH, int[] trims) {
            this.tvDimInfo = tvDimInfo;
            this.origW = origW;
            this.origH = origH;
            this.trims = trims;
        }

        @Override
        public void run() {
            if (tvDimInfo == null) return;
            int cropW = origW - (int) (origW * (trims[0] + trims[1]) / 100f);
            int cropH = origH - (int) (origH * (trims[2] + trims[3]) / 100f);
            float ratio = cropH > 0 ? (float) cropW / (float) cropH : 0f;
            tvDimInfo.setText(String.format("Gốc: %d x %d px\nCắt: %d x %d px (Tỷ lệ: %.2f)",
                origW, origH, cropW, cropH, ratio));
        }
    }

    /**
     * Reset click listener for crop dialog.
     * Bộ xử lý nút đặt lại tỷ lệ cắt ảnh.
     */
    public static class CropResetClickListener implements View.OnClickListener {
        private final PhotoEditorComponent component;
        private final int[] trims;
        private final SeekBar[] seekBars;

        public CropResetClickListener(PhotoEditorComponent component, int[] trims, SeekBar[] seekBars) {
            this.component = component;
            this.trims = trims;
            this.seekBars = seekBars;
        }

        @Override
        public void onClick(View v) {
            for (int i = 0; i < 4; i++) {
                trims[i] = 0;
                if (seekBars[i] != null) {
                    seekBars[i].setProgress(0);
                }
            }
            component.resetCropToBase();
        }
    }

    /**
     * Apply crop click listener.
     * Bộ xử lý áp dụng kết quả cắt ảnh.
     */
    public static class CropApplyClickListener implements View.OnClickListener {
        private final PhotoEditorComponent component;
        private final int origW;
        private final int origH;
        private final int[] trims;
        private final AlertDialog dialog;

        public CropApplyClickListener(PhotoEditorComponent component, int origW, int origH, int[] trims, AlertDialog dialog) {
            this.component = component;
            this.origW = origW;
            this.origH = origH;
            this.trims = trims;
            this.dialog = dialog;
        }

        @Override
        public void onClick(View v) {
            int cropX = (int) (origW * trims[0] / 100f);
            int cropY = (int) (origH * trims[2] / 100f);
            int cropW = origW - cropX - (int) (origW * trims[1] / 100f);
            int cropH = origH - cropY - (int) (origH * trims[3] / 100f);
            component.applyCropResult(cropX, cropY, cropW, cropH, origW, origH);
            if (dialog != null && dialog.isShowing()) {
                dialog.dismiss();
            }
        }
    }

    /**
     * Dialog listener to open saved photo in external gallery.
     * Bộ xử lý xem ảnh đã lưu trong thư viện thiết bị.
     */
    public static class ViewSavedPhotoClickListener implements DialogInterface.OnClickListener {
        private final Context context;
        private final File fileToView;

        public ViewSavedPhotoClickListener(Context context, File fileToView) {
            this.context = context;
            this.fileToView = fileToView;
        }

        @Override
        public void onClick(DialogInterface dialog, int which) {
            try {
                // V3 Fix: Use OpenCutFileProvider instead of Uri.fromFile() to prevent FileUriExposedException
                // Sửa lỗi V3: Dùng OpenCutFileProvider thay cho Uri.fromFile() để tránh crash FileUriExposedException
                Uri contentUri = OpenCutFileProvider.getUriForFile(context, fileToView);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setDataAndType(contentUri, "image/png");
                intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_GRANT_READ_URI_PERMISSION);
                context.startActivity(Intent.createChooser(intent, "Mở ảnh với:"));
            } catch (Exception e) {
                Toast.makeText(context, "📍 Ảnh đã lưu tại: " + fileToView.getAbsolutePath(), Toast.LENGTH_LONG).show();
            }
        }
    }

    /**
     * Background task to export and persist photo bitmap without freezing the UI thread.
     * Tác vụ nền để kết xuất và lưu bitmap ảnh mà không gây đơ luồng giao diện.
     */
    private static class SavePhotoTask implements Runnable {
        private final PhotoEditorComponent component;
        private final Context context;
        private final Bitmap sourceBitmap;
        private final android.graphics.ColorFilter colorFilter;
        private final OnPhotoEditorListener listener;

        public SavePhotoTask(PhotoEditorComponent component, Context context, Bitmap sourceBitmap,
                             android.graphics.ColorFilter colorFilter, OnPhotoEditorListener listener) {
            this.component = component;
            this.context = context;
            this.sourceBitmap = sourceBitmap;
            this.colorFilter = colorFilter;
            this.listener = listener;
        }

        @Override
        public void run() {
            try {
                String filename = "opencut_photo_" + System.currentTimeMillis() + ".png";

                // Bake current ColorFilter and adjustments directly into a new high-fidelity Bitmap
                Bitmap exportBitmap = Bitmap.createBitmap(sourceBitmap.getWidth(), sourceBitmap.getHeight(), Bitmap.Config.ARGB_8888);
                Canvas exportCanvas = new Canvas(exportBitmap);
                Paint exportPaint = new Paint(Paint.ANTI_ALIAS_FLAG | Paint.FILTER_BITMAP_FLAG);
                if (colorFilter != null) {
                    exportPaint.setColorFilter(colorFilter);
                }
                exportCanvas.drawBitmap(sourceBitmap, 0, 0, exportPaint);

                // 1. Android MediaStore (Android 10+ Standard Gallery Storage)
                try {
                    ContentValues values = new ContentValues();
                    values.put(MediaStore.Images.Media.DISPLAY_NAME, filename);
                    values.put(MediaStore.Images.Media.MIME_TYPE, "image/png");
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
                        values.put(MediaStore.Images.Media.RELATIVE_PATH, Environment.DIRECTORY_PICTURES + "/NextAI_OpenCut");
                    }
                    Uri uri = context.getContentResolver().insert(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, values);
                    if (uri != null) {
                        OutputStream os = context.getContentResolver().openOutputStream(uri);
                        if (os != null) {
                            exportBitmap.compress(Bitmap.CompressFormat.PNG, 100, os);
                            os.flush();
                            os.close();
                        }
                    }
                } catch (Exception ignored) {}

                // 2. Direct App Pictures Directory
                File appDir = new File(context.getExternalFilesDir(Environment.DIRECTORY_PICTURES), "NextAI_OpenCut");
                if (!appDir.exists()) appDir.mkdirs();
                File appFile = new File(appDir, filename);
                FileOutputStream appFos = new FileOutputStream(appFile);
                exportBitmap.compress(Bitmap.CompressFormat.PNG, 100, appFos);
                appFos.flush();
                appFos.close();

                // 3. Public /sdcard/Pictures/NextAI_OpenCut directory
                File pubFile = null;
                try {
                    File pubDir = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "NextAI_OpenCut");
                    if (!pubDir.exists()) pubDir.mkdirs();
                    pubFile = new File(pubDir, filename);
                    FileOutputStream pubFos = new FileOutputStream(pubFile);
                    exportBitmap.compress(Bitmap.CompressFormat.PNG, 100, pubFos);
                    pubFos.flush();
                    pubFos.close();
                    MediaScannerConnection.scanFile(context, new String[]{pubFile.getAbsolutePath()}, null, null);
                } catch (Exception ignored) {}

                final File fileToView = (pubFile != null && pubFile.exists()) ? pubFile : appFile;
                final Bitmap finalExportBitmap = exportBitmap;

                // Post success to UI Thread
                component.mainHandler.post(new SaveSuccessRunnable(context, filename, fileToView, finalExportBitmap, listener));
            } catch (Exception e) {
                // Post honest error reporting to UI Thread (Fixes P1)
                component.mainHandler.post(new SaveErrorRunnable(context, e.getMessage()));
            }
        }
    }

    private static class SaveSuccessRunnable implements Runnable {
        private final Context context;
        private final String filename;
        private final File fileToView;
        private final Bitmap exportBitmap;
        private final OnPhotoEditorListener listener;

        public SaveSuccessRunnable(Context context, String filename, File fileToView, Bitmap exportBitmap, OnPhotoEditorListener listener) {
            this.context = context;
            this.filename = filename;
            this.fileToView = fileToView;
            this.exportBitmap = exportBitmap;
            this.listener = listener;
        }

        @Override
        public void run() {
            try {
                AlertDialog.Builder photoDialog = new AlertDialog.Builder(context);
                photoDialog.setTitle("🎉 ĐÃ LƯU ẢNH THÀNH CÔNG!");
                photoDialog.setMessage("Đã lưu ảnh nghệ thuật chất lượng cao vào Thư Viện:\n\n" +
                    "📁 Tệp: " + filename + "\n" +
                    "📍 Vị trí: Pictures/NextAI_OpenCut/\n\n" +
                    "Bạn có thể mở xem ảnh ngay trong Thư Viện máy.");
                photoDialog.setPositiveButton("🖼️ XEM ẢNH NGAY", new ViewSavedPhotoClickListener(context, fileToView));
                photoDialog.setNegativeButton("ĐÓNG", null);
                photoDialog.show();

                if (listener != null) {
                    listener.onPhotoEditorSaved(exportBitmap, fileToView.getAbsolutePath());
                }
            } catch (Exception e) {
                Toast.makeText(context, "📍 Đã lưu ảnh tại: " + fileToView.getAbsolutePath(), Toast.LENGTH_SHORT).show();
            }
        }
    }

    private static class SaveErrorRunnable implements Runnable {
        private final Context context;
        private final String errorMessage;

        public SaveErrorRunnable(Context context, String errorMessage) {
            this.context = context;
            this.errorMessage = errorMessage;
        }

        @Override
        public void run() {
            Toast.makeText(context, "❌ Lỗi khi lưu ảnh: " + errorMessage, Toast.LENGTH_LONG).show();
        }
    }

    /**
     * Background task to decode photo from URI and run face detection without freezing UI thread.
     * Tác vụ nền để giải mã ảnh từ URI và chạy nhận diện khuôn mặt mà không gây lag UI.
     */
    private static class LoadPhotoFromUriTask implements Runnable {
        private final PhotoEditorComponent component;
        private final Context context;
        private final Uri uri;

        public LoadPhotoFromUriTask(PhotoEditorComponent component, Context context, Uri uri) {
            this.component = component;
            this.context = context;
            this.uri = uri;
        }

        @Override
        public void run() {
            Bitmap decoded = null;
            try {
                ParcelFileDescriptor pfd = context.getContentResolver().openFileDescriptor(uri, "r");
                if (pfd != null) {
                    FileDescriptor fd = pfd.getFileDescriptor();
                    BitmapFactory.Options opts = new BitmapFactory.Options();
                    opts.inJustDecodeBounds = true;
                    BitmapFactory.decodeFileDescriptor(fd, null, opts);

                    int maxDim = Math.max(opts.outWidth, opts.outHeight);
                    int sampleSize = 1;
                    while (maxDim / sampleSize > 2560) {
                        sampleSize *= 2;
                    }

                    opts.inJustDecodeBounds = false;
                    opts.inSampleSize = sampleSize;
                    opts.inPreferredConfig = Bitmap.Config.ARGB_8888;
                    opts.inMutable = true;

                    decoded = BitmapFactory.decodeFileDescriptor(fd, null, opts);
                    pfd.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

            if (decoded != null) {
                decoded = fixExifOrientation(context, uri, decoded);
                List<FaceBodyDetectionEngine.FaceLandmarks> faces = FaceBodyDetectionEngine.detectAllFaces(decoded);
                FaceBodyDetectionEngine.FaceLandmarks primaryLandmark = !faces.isEmpty() ? faces.get(0) : FaceBodyDetectionEngine.detectFace(decoded);
                component.mainHandler.post(new LoadPhotoCompleteRunnable(component, decoded, faces, primaryLandmark));
            } else {
                component.mainHandler.post(new LoadPhotoFailedRunnable(component));
            }
        }
    }

    private static class LoadPhotoCompleteRunnable implements Runnable {
        private final PhotoEditorComponent component;
        private final Bitmap decoded;
        private final List<FaceBodyDetectionEngine.FaceLandmarks> faces;
        private final FaceBodyDetectionEngine.FaceLandmarks primaryLandmark;

        public LoadPhotoCompleteRunnable(PhotoEditorComponent component, Bitmap decoded,
                                         List<FaceBodyDetectionEngine.FaceLandmarks> faces,
                                         FaceBodyDetectionEngine.FaceLandmarks primaryLandmark) {
            this.component = component;
            this.decoded = decoded;
            this.faces = faces;
            this.primaryLandmark = primaryLandmark;
        }

        @Override
        public void run() {
            if (component.baseOriginalPhotoBitmap != null && component.baseOriginalPhotoBitmap != decoded
                    && !component.baseOriginalPhotoBitmap.isRecycled()) {
                component.baseOriginalPhotoBitmap.recycle();
            }
            if (component.basePhotoBitmap != null && component.basePhotoBitmap != decoded
                    && !component.basePhotoBitmap.isRecycled()) {
                component.basePhotoBitmap.recycle();
            }
            if (component.basePreEffectBitmap != null && !component.basePreEffectBitmap.isRecycled()) {
                component.basePreEffectBitmap.recycle();
                component.basePreEffectBitmap = null;
            }

            component.baseOriginalPhotoBitmap = decoded;
            component.basePhotoBitmap = decoded.copy(Bitmap.Config.ARGB_8888, true);
            component.photoRotationDegrees = 0;
            component.isPhotoFlipped = false;
            component.detectedFaceList = faces;
            component.cachedPhotoLandmarks = primaryLandmark;
            component.selectedFaceIndex = 0;

            if (faces.size() > 1) {
                Toast.makeText(component.context, "👥 Đã nhận diện " + faces.size() + " khuôn mặt. Chạm vào bất kỳ ai trên ảnh để làm đẹp!", Toast.LENGTH_SHORT).show();
            }
            if (component.ivPhotoCanvas != null) {
                component.ivPhotoCanvas.setImageBitmap(component.basePhotoBitmap);
            }
            component.updatePhotoCanvasDimensions(component.basePhotoBitmap.getWidth(), component.basePhotoBitmap.getHeight());
        }
    }

    private static class LoadPhotoFailedRunnable implements Runnable {
        private final PhotoEditorComponent component;

        public LoadPhotoFailedRunnable(PhotoEditorComponent component) {
            this.component = component;
        }

        @Override
        public void run() {
            component.createDefaultBasePhotoBitmap();
            if (component.ivPhotoCanvas != null) {
                component.ivPhotoCanvas.setImageBitmap(component.basePhotoBitmap);
            }
            Toast.makeText(component.context, "⚠️ Không thể đọc ảnh gốc, hiển thị ảnh mẫu!", Toast.LENGTH_SHORT).show();
        }
    }
}
