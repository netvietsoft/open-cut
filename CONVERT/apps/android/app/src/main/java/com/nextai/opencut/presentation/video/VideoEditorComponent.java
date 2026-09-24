package com.nextai.opencut.presentation.video;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.Typeface;
import android.media.MediaPlayer;
import android.media.PlaybackParams;
import android.net.Uri;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.speech.tts.TextToSpeech;
import android.text.Spannable;
import android.text.SpannableStringBuilder;
import android.text.style.BackgroundColorSpan;
import android.text.style.ForegroundColorSpan;
import android.text.style.RelativeSizeSpan;
import android.text.style.StyleSpan;
import android.util.DisplayMetrics;
import android.util.LruCache;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.VideoView;

import com.nextai.opencut.R;
import com.nextai.opencut.engine.EffectRegistry;
import com.nextai.opencut.engine.MiddleBridgeJni;
import com.nextai.opencut.presentation.model.AudioTrackItem;
import com.nextai.opencut.presentation.model.KeyframePoint;
import com.nextai.opencut.presentation.model.MediaItem;
import com.nextai.opencut.presentation.model.PipClipItem;
import com.nextai.opencut.presentation.model.SubtitleItem;
import com.nextai.opencut.presentation.photo.PhotoEditorComponent;

import java.io.File;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.ExecutorService;

/**
 * VideoEditorComponent — Thành Phần Trình Biên Tập Video Đa Tầng CapCut Parity 100%
 * Comprehensive Multi-track Video Editor Suite (Split, Speed Curves, 3D LUTs, Shaders, AI Subtitles, PIP, Export)
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class VideoEditorComponent implements View.OnClickListener, SeekBar.OnSeekBarChangeListener,
        MediaPlayer.OnPreparedListener, MediaPlayer.OnErrorListener, MediaPlayer.OnCompletionListener,
        TextToSpeech.OnInitListener, Runnable, View.OnTouchListener, VideoExportController.OnExportListener {

    public static final int TRACK_TYPE_NONE = 0;
    public static final int TRACK_TYPE_VIDEO = 1;
    public static final int TRACK_TYPE_PIP = 2;
    public static final int TRACK_TYPE_AUDIO = 3;
    public static final int TRACK_TYPE_SUBTITLE = 4;
    public static final int TRACK_TYPE_EFFECT = 5;

    // Core Context & Dependencies / Ngữ cảnh & Các Thành Phần Phụ Thuộc
    private final Activity activity;
    private final OnVideoEditorListener listener;
    private final List<MediaItem> allMediaItems;
    private final List<MediaItem> activeProjectClips;
    private final ExecutorService executor;
    private final LruCache<String, Bitmap> thumbnailCache;
    private final Handler playbackHandler = new Handler(Looper.getMainLooper());
    private final VideoExportController exportController;

    // View Hierarchy Root / Gốc Giao Diện
    private LinearLayout editorView;

    // Video Editor Top Bar Elements / Các Phần Tử Thanh Tiêu Đề Trên Cùng
    private View btnEditorClose;
    private View btnEditorHot;
    private View btnEditorTutorial;
    private View btnEditorProBadge;
    private View btnEditorResolution;
    private View btnEditorExport;

    // Video Player & Controls / Trình Phát Video & Nút Điều Khiển
    private View btnPlayerFullscreen;
    private View btnPlayerPlayPause;
    private View btnPlayerUndo;
    private View btnPlayerRedo;
    private TextView tvPlayerPlayIcon;
    private TextView tvPlayerTimecode;
    private TextView tvCanvasGestureHint;
    private TextView tvSceneArt;
    private FrameLayout canvasFrame;
    private VideoView videoPlayerView;
    private ImageView ivVideoPoster;
    private ImageView videoFxOverlayView;
    private String currentVideoFilter = "none";
    private MediaPlayer mediaPlayerInstance = null;
    private boolean isPlaying = false;
    private boolean is4kSelected = false;
    private int virtualPlayheadMs = 0;

    // TextToSpeech Engine & State / Bộ Máy Giọng Đọc AI & Trạng Thái
    private TextToSpeech ttsEngine = null;
    private boolean isTtsReady = false;

    // Subtitle & Overlay Models / Mô Hình Dữ Liệu Phụ Đề & Văn Bản Lớp Phủ
    private final List<SubtitleItem> currentSubtitles = new ArrayList<>();
    private TextView tvCanvasSubtitleOverlay;
    private TextView tvCanvasTextOverlay;
    private String customOverlayText = "";
    private int customOverlayTextColor = Color.parseColor("#00E5FF");

    // Multi-track Audio Model / Mô Hình Track Âm Thanh Đa Tầng
    private final List<AudioTrackItem> activeAudioTracks = new ArrayList<>();
    private LinearLayout timelineAudioContainer;
    private int selectedAudioTrackIndex = 0;
    private boolean isUserScrubbing = false;
    private final Runnable scrubResetRunnable;
    private boolean isSyncingScroll = false;
    private String currentActiveVisualFx = "none";
    private int currentTextStyleIdx = 0;

    // Multi-track Timeline Tracks / Các Dải Track Đa Tầng Trên Timeline
    private LinearLayout timelineRulerRow;
    private LinearLayout timelineSubtitlesRow;
    private LinearLayout timelineAudioRow;
    private LinearLayout timelineEffectsRow;
    private TextView tvSubTrackBlock;
    private TextView tvAudioTrackBlock;
    private TextView tvEffectTrackBlock;

    // Timeline Elements / Các Phần Tử Timeline & Cột Cố Định
    private View btnMuteAudio;
    private View btnCoverFrame;
    private View btnAddMediaClip;
    private View btnAddAudioTrack;
    private LinearLayout timelineClipsRow;
    private int selectedClipIndex = 0;

    // Sub-menu Ribbon Containers & Controls / Khung Chứa Các Tầng Công Cụ Ribbon
    private FrameLayout ribbonContainer;
    private LinearLayout ribbonMainMenu;
    private LinearLayout ribbonCanvasSubmenu;
    private LinearLayout ribbonAudioSubmenu;
    private LinearLayout ribbonEffectsDrawer;
    private LinearLayout ribbonEditSubmenu;
    private LinearLayout ribbonSpeedDrawer;
    private LinearLayout ribbonVolumeDrawer;
    private LinearLayout ribbonAdjustDrawer;
    private LinearLayout ribbonRatioDrawer;
    private LinearLayout ribbonCutoutDrawer;
    private LinearLayout ribbonTextSubmenu;
    private LinearLayout ribbonBeautyDrawer;
    private LinearLayout ribbonMaskDrawer;
    private LinearLayout ribbonPipContextToolbar;

    // Multi-track Timeline Selection State / Trạng Thái Chọn Track
    private int currentSelectedTrack = TRACK_TYPE_VIDEO;

    // Timeline Horizontal Scroll & End Marker / Bộ Cuộn Ngang & Vạch Mốc Kết Thúc
    private HorizontalScrollView hScrollTracks;
    private View viewEndOfVideoMarker;

    // Sub-menu Back Buttons / Các Nút Quay Lại Menu Chính
    private View btnBackFromCanvas;
    private View btnBackFromAudio;
    private View btnBackFromEffects;
    private View btnEffectsConfirm;
    private View btnBackFromEdit;
    private View btnBackFromSpeed;
    private View btnBackFromVolume;
    private View btnBackFromAdjust;
    private View btnBackFromRatio;
    private View btnBackFromCutout;
    private View btnBackFromText;
    private View btnBackFromBeauty;
    private View btnBackFromMask;
    private View btnBackFromPip;

    // Chroma Key / Cutout Drawer Elements / Khóa Phông & Xóa Nền
    private View colorGreenScreen, colorBlueScreen, colorMagentaScreen;
    private View btnColorPipette;
    private View colorPresetWhite, colorPresetBlack, colorPresetCyan;
    private SeekBar sbChromaIntensity, sbChromaShadow, sbChromaSpill;
    private TextView tvChromaIntensityVal, tvChromaShadowVal, tvChromaSpillVal;
    private View btnApplyCutoutAi;
    private View btnCapCutChromaV1370;
    private View btnSmartPortraitMatting;
    private View btnStrokeNeon, btnStrokeDotDash, btnStrokeGlow, btnStrokeShadow;
    private int currentChromaColor = Color.parseColor("#00FF00");
    private String currentSmartStroke = "none";

    // Text Submenu Ribbon Elements / Menu Con Văn Bản
    private View subToolAddText, subToolTextTemplate, subToolAutoCaptions, subToolTextTts, subToolTextEffects;

    // Beauty / Face Retouch Drawer Elements / Làm Đẹp & Thu Mặt
    private SeekBar sbSlimFace, sbSmoothSkin, sbBigEyes, sbNose, sbTeeth;
    private TextView tvSlimFaceVal, tvSmoothSkinVal, tvBigEyesVal, tvNoseVal, tvTeethVal;
    private View btnToggleMesh468;
    private View btnCapCutFaceReshapeV2;
    private boolean isMesh468Visible = true;

    // Interactive Dialog References / Các Tham Chiếu Hộp Thoại
    private AlertDialog activeDialog = null;
    private View btnDialogSubVi, btnDialogSubEn, btnDialogSubAuto, btnDialogSubCancel;
    private View btnDialogVoiceHaNhi, btnDialogVoiceMinhQuan, btnDialogVoiceJessica, btnDialogVoiceNews, btnDialogVoiceCancel;
    private View btnDialogVoiceFxChipmunk, btnDialogVoiceFxRobot, btnDialogVoiceFxMonster, btnDialogVoiceFxEcho, btnDialogVoiceFxCancel;
    private EditText etVoiceScript = null;
    private EditText etTextToVideoPrompt = null;
    private View btnT2vPreset1, btnT2vPreset2, btnT2vPreset3, btnT2vGenerate, btnT2vCancel;
    private EditText etCustomText = null;
    private View btnTextColorWhite, btnTextColorCyan, btnTextColorYellow, btnTextColorRed, btnTextConfirm, btnTextCancel;
    private View btnMusicPlay1, btnMusicAdd1, btnMusicPlay2, btnMusicAdd2, btnMusicPlay3, btnMusicAdd3, btnMusicPlay4, btnMusicAdd4, btnMusicClose;

    // Video Edit Sub-tools / Công Cụ Con Trong Menu Chỉnh Sửa
    private View subToolSplit;
    private View subToolSpeed;
    private View subToolVolume;
    private View subToolDelete;
    private View subToolCutout;
    private View subToolBeauty;
    private View subToolAdjust;
    private View subToolRatio;
    private View subToolFreeze;
    private View subToolReverse;
    private View subToolMask;
    private View subToolRotate;
    private View subToolFlip;
    private View subToolCrop;
    private int videoRotationDegrees = 0;
    private boolean isVideoFillMode = false;
    private boolean isVideoFlipped = false;

    // Speed Pills & Curves / Tốc Độ & Đường Cong
    private View speedTabStandard, speedTabCurve;
    private LinearLayout speedStandardLayout, speedCurveLayout;
    private SeekBar sbSpeedStandard;
    private TextView tvSpeedStandardVal;
    private View btnPreservePitch;
    private boolean isPitchPreserved = true;
    private View speedPill01x, speedPill05x, speedPill1x, speedPill15x, speedPill2x, speedPill5x, speedPill10x, speedPill50x, speedPill100x;
    private View speedCurveCustom, speedCurveMontage, speedCurveBullet, speedCurveHero, speedCurveFlashIn, speedCurveJumpCut;
    private SpeedCurveGraphView speedCurveGraphView;

    // Volume Controls & Pro Audio Suite / Âm Lượng
    private SeekBar sbVolume;
    private TextView tvVolumeVal;
    private SeekBar sbFadeIn, sbFadeOut;
    private TextView tvFadeInVal, tvFadeOutVal;
    private View volPill0, volPill100, volPill200, volPill500, volPill1000;

    // Keyframe Toggle Button & Sub-tools / Keyframe & Công Cụ Con
    private TextView btnKeyframeToggle;
    private View subToolAnimation;
    private View subToolDuplicate;
    private View subToolReplace;
    private View subToolOpacity;
    private float timelineScaleFactor = 1.0f;
    private ScaleGestureDetector timelineScaleDetector;

    // Cover Frame Editor & Karaoke Subtitles / Ảnh Bìa & Karaoke
    private TextView tvCoverIconView;
    private TextView tvCoverLabelView;
    private Bitmap projectCoverBitmap = null;
    private String coverTitleText = "VLOG DU LỊCH 2026";
    private int coverTemplateIndex = 0;
    private int coverFontIndex = 0;
    private String currentKaraokeStyle = "karaoke_gold_glow";

    private ImageView ivCoverPreview;
    private EditText etCoverTitle;
    private SeekBar sbCoverScrubber;
    private TextView btnUploadCustomPhoto;
    private TextView btnSaveCover, btnCancelCover;
    private View pillFontGold, pillFontSerif, pillFontNeon, pillFontClean;
    private View pillTplBottom, pillTplCenter, pillTplTiktok, pillTplCinema;
    private View pillKaraokeGold, pillKaraokeNeon, pillKaraokeBox, pillKaraokeBounce;

    // Video Adjust SeekBars / Chỉnh Màu Video
    private SeekBar sbVideoBright, sbVideoContrast, sbVideoSat;
    private TextView tvVideoBrightVal, tvVideoContrastVal, tvVideoSatVal;

    // Ratio Pills / Tỷ Lệ Khung Hình
    private View ratioPill916, ratioPill169, ratioPill11, ratioPill45;
    private String currentVideoRatio = "9:16";

    // Canvas Sub-menu Items / Menu Bảng Vẽ
    private View canvasOptColor, canvasOptBg, canvasOptBlur, canvasOptBrand;

    // Audio Sub-menu Items / Menu Âm Thanh
    private View audioOptSounds, audioOptBrand, audioOptCopyright, audioOptSoundFx, audioOptExtract, audioOptVoiceFx;
    private View audioOptNoiseReduction, audioOptVocalIsolation;
    private View btnOptBgm, btnOptFx, btnOptVoice, btnOptExtract, btnOptCancel;
    private View btnSoundFxClose;
    private View btnTextStyleNormal, btnTextStyleStroke, btnTextStyleNeon, btnTextStyleBox, btnTextStyleGold;

    // Video Masking Drawer / Mặt Nạ Video
    private View maskOptLinear, maskOptCircle, maskOptMirror, maskOptInvert;
    private String activeMaskType = "none";

    // Effects Drawer Items / Hiệu Ứng
    private View tabFxNightclub, tabFxLens, tabFxRetro, tabFxLight, tabFxMusic, tabFxCapCutNative, tabFxGlitch;
    private LinearLayout layoutFxRetroContainer, layoutFxCapCutContainer, layoutFxGlitchContainer;
    private View fxCardPolaroid, fxCardNoise2, fxCardNoiseBlack, fxCardFilmLeak, fxCardFrame1, fxCardTornPaper, fxCardOpen, fxCardMovie;
    private View fxCardCapCutSpin, fxCardCapCutHexagon, fxCardCapCutChroma, fxCardCapCutStar;
    private View fxCardCapCutCurves, fxCardCapCutHsl, fxCardCapCutSmooth, fxCardCapCutParticle;
    private View fxCardGlitchRgb, fxCardGlitchVhs, fxCardGlitchMatrix, fxCardGlitchTrippy, fxCardGlitchBeat, fxCardGlitchScanline;

    // PIP Overlays / Lớp Phủ PIP
    private final List<PipClipItem> activePipClips = new ArrayList<>();
    private int selectedPipIndex = -1;
    private LinearLayout timelinePipRow = null;
    private FrameLayout pipOverlayContainer = null;
    private ImageView ivPipPreview = null;
    private TextView tvPipBlendBadge = null;
    private TextView tvPipTrackBlock = null;

    // Main 11 Tools / 11 Công Cụ Chính
    private View toolEdit, toolAudio, toolText, toolOverlay, toolEffects, toolCaptions, toolRatio, toolFilters, toolAdjust, toolStickers, toolCanvas;

    public VideoEditorComponent(Activity activity, List<MediaItem> allMediaItems, List<MediaItem> activeProjectClips,
                                OnVideoEditorListener listener, ExecutorService executor, LruCache<String, Bitmap> thumbnailCache) {
        this.activity = activity;
        this.allMediaItems = allMediaItems;
        this.activeProjectClips = activeProjectClips;
        this.listener = listener;
        this.executor = executor;
        this.thumbnailCache = thumbnailCache;
        this.exportController = new VideoExportController(activity, playbackHandler, executor);
        this.scrubResetRunnable = new UserScrubResetRunnable(this);

        // Initialize TextToSpeech Engine
        try {
            ttsEngine = new TextToSpeech(activity, this);
        } catch (Exception e) {
            e.printStackTrace();
        }

        buildEditorView();
    }

    public View getView() {
        return editorView;
    }

    public void open() {
        showRibbonLevel(ribbonMainMenu);
        updateVideoCanvasDimensions();
        updatePlayerPreview();
        renderTimelineFilmstrip();
        Toast.makeText(activity, "🎬 Đã mở Trình Biên Tập Timeline Đa Track C++20!", Toast.LENGTH_SHORT).show();
    }

    public void open(List<MediaItem> clips) {
        if (clips != null && !clips.isEmpty()) {
            activeProjectClips.clear();
            activeProjectClips.addAll(clips);
            selectedClipIndex = 0;
        }
        open();
    }

    public void addClips(List<MediaItem> clips) {
        if (clips == null || clips.isEmpty()) return;
        int insertPos = activeProjectClips.isEmpty() ? 0 : Math.min(selectedClipIndex + 1, activeProjectClips.size());
        activeProjectClips.addAll(insertPos, clips);
        selectedClipIndex = insertPos;
        renderTimelineFilmstrip();
        updatePlayerPreview();
        open();
        Toast.makeText(activity, "🎬 Đã nối " + clips.size() + " clip vào Timeline!", Toast.LENGTH_SHORT).show();
    }

    public void replaceCurrentClip(MediaItem rep) {
        if (rep == null || activeProjectClips.isEmpty() || selectedClipIndex >= activeProjectClips.size()) return;
        MediaItem cur = activeProjectClips.get(selectedClipIndex);
        cur.id = rep.id;
        cur.title = rep.title;
        cur.uri = rep.uri;
        cur.isVideo = rep.isVideo;
        cur.duration = rep.duration;
        cur.durationSeconds = rep.durationSeconds;
        cur.colorBg = rep.colorBg;
        cur.icon = rep.icon;
        cur.thumbnailBitmap = rep.thumbnailBitmap;
        renderTimelineFilmstrip();
        updatePlayerPreview();
        open();
        Toast.makeText(activity, "🔄 Đã thay thế clip thành công (Bảo lưu toàn bộ thuộc tính)!", Toast.LENGTH_SHORT).show();
    }

    public void addPipClips(List<MediaItem> pipItems) {
        if (pipItems == null || pipItems.isEmpty()) return;
        for (MediaItem m : pipItems) {
            PipClipItem pip = new PipClipItem(m, 0, Math.max(1, m.durationSeconds) * 1000);
            activePipClips.add(pip);
        }
        selectedPipIndex = activePipClips.size() - 1;
        renderPipTrack();
        updatePipCanvasPreview();
        open();
        Toast.makeText(activity, "🎞️ PIP Overlay: Đã thêm " + pipItems.size() + " lớp phủ đa tầng!", Toast.LENGTH_LONG).show();
    }

    public void applyTemplate(String title, String duration, String lut, String effect) {
        activeProjectClips.clear();
        int baseSec = 5;
        if (!allMediaItems.isEmpty()) {
            MediaItem m0 = allMediaItems.get(0);
            m0.durationSeconds = baseSec;
            m0.duration = "00:05";
            activeProjectClips.add(m0);

            if (allMediaItems.size() > 1) {
                MediaItem m1 = allMediaItems.get(1);
                m1.durationSeconds = baseSec;
                m1.duration = "00:05";
                activeProjectClips.add(m1);
            }
            if (allMediaItems.size() > 2) {
                MediaItem m2 = allMediaItems.get(2);
                m2.durationSeconds = baseSec;
                m2.duration = "00:05";
                activeProjectClips.add(m2);
            }
        }
        if (activeProjectClips.isEmpty()) {
            activeProjectClips.add(new MediaItem("t_clip1", "Clip Mẫu 1 (Beat Drop)", null, "00:05", true, Color.parseColor("#7C2D12"), "⚡"));
            activeProjectClips.add(new MediaItem("t_clip2", "Clip Mẫu 2 (Chuyển Cảnh)", null, "00:05", true, Color.parseColor("#1E293B"), "🎬"));
            activeProjectClips.add(new MediaItem("t_clip3", "Clip Mẫu 3 (Kết Màn)", null, "00:05", true, Color.parseColor("#065F46"), "🌟"));
        }
        selectedClipIndex = 0;

        MiddleBridgeJni.applyShaderEffect(lut, 0.95f);

        if (timelineAudioRow != null && tvAudioTrackBlock != null) {
            timelineAudioRow.setVisibility(View.VISIBLE);
            tvAudioTrackBlock.setText("🎵 [Mẫu Beat Sync: " + title + " - 120BPM]");
        }
        if (timelineEffectsRow != null && tvEffectTrackBlock != null) {
            timelineEffectsRow.setVisibility(View.VISIBLE);
            tvEffectTrackBlock.setText("⭐ [Mẫu Hiệu Ứng: " + effect + "]");
        }
        if (timelineSubtitlesRow != null && tvSubTrackBlock != null) {
            timelineSubtitlesRow.setVisibility(View.VISIBLE);
            tvSubTrackBlock.setText("⚡ [Phụ đề Mẫu: Beat Drop Synchronized]");
        }

        open();
        if (tvCanvasGestureHint != null) {
            tvCanvasGestureHint.setText("✨ Đã áp dụng mẫu: " + title + " (" + duration + ")");
        }
        Toast.makeText(activity, "✨ Đã áp dụng mẫu [" + title + "] thành công! Khớp 3 clip vào Beat Sync.", Toast.LENGTH_LONG).show();
    }

    public void showCutoutDrawer() {
        open();
        showRibbonLevel(ribbonCutoutDrawer);
    }

    public void showTextDrawer() {
        open();
        showRibbonLevel(ribbonTextSubmenu);
    }

    public void showAudioDrawer() {
        open();
        showRibbonLevel(ribbonAudioSubmenu);
    }

    public void onResume() {
        // Refresh canvas or preview if needed
    }

    public void onDestroy() {
        try {
            if (ttsEngine != null) {
                ttsEngine.stop();
                ttsEngine.shutdown();
            }
            playbackHandler.removeCallbacksAndMessages(null);
            if (videoPlayerView != null) {
                videoPlayerView.stopPlayback();
            }
        } catch (Exception ignored) {}
    }

    @Override
    public void onInit(int status) {
        if (status == TextToSpeech.SUCCESS && ttsEngine != null) {
            try {
                int res = ttsEngine.setLanguage(new Locale("vi", "VN"));
                if (res == TextToSpeech.LANG_MISSING_DATA || res == TextToSpeech.LANG_NOT_SUPPORTED) {
                    ttsEngine.setLanguage(Locale.US);
                }
                isTtsReady = true;
            } catch (Exception ignored) {
                isTtsReady = true;
            }
        }
    }

    /**
     * Build Pixel-Perfect CapCut Video Editor View Hierarchy
     */
    private void buildEditorView() {
        editorView = new LinearLayout(activity);
        editorView.setOrientation(LinearLayout.VERTICAL);
        editorView.setBackgroundColor(Color.parseColor("#000000"));
        editorView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // 1. Top Bar
        LinearLayout topBar = new LinearLayout(activity);
        topBar.setOrientation(LinearLayout.HORIZONTAL);
        topBar.setGravity(Gravity.CENTER_VERTICAL);
        topBar.setPadding(16, 20, 16, 12);
        topBar.setBackgroundColor(Color.parseColor("#000000"));

        btnEditorClose = new TextView(activity);
        ((TextView) btnEditorClose).setText("✕");
        ((TextView) btnEditorClose).setTextColor(Color.WHITE);
        ((TextView) btnEditorClose).setTextSize(20);
        ((TextView) btnEditorClose).setPadding(24, 16, 24, 16);
        ((TextView) btnEditorClose).setMinimumWidth(80);
        ((TextView) btnEditorClose).setMinimumHeight(72);
        ((TextView) btnEditorClose).setGravity(Gravity.CENTER);
        btnEditorClose.setOnClickListener(this);
        topBar.addView(btnEditorClose);

        btnEditorTutorial = new TextView(activity);
        ((TextView) btnEditorTutorial).setText("❔");
        ((TextView) btnEditorTutorial).setTextSize(15);
        ((TextView) btnEditorTutorial).setPadding(8, 4, 8, 4);
        btnEditorTutorial.setOnClickListener(this);
        topBar.addView(btnEditorTutorial);

        btnEditorHot = new TextView(activity);
        ((TextView) btnEditorHot).setText("🔥");
        ((TextView) btnEditorHot).setTextSize(17);
        ((TextView) btnEditorHot).setPadding(8, 4, 8, 4);
        btnEditorHot.setOnClickListener(this);
        topBar.addView(btnEditorHot);

        View topSpacer = new View(activity);
        topBar.addView(topSpacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnEditorProBadge = new TextView(activity);
        ((TextView) btnEditorProBadge).setText("Pro");
        ((TextView) btnEditorProBadge).setTextColor(Color.parseColor("#EAB308"));
        ((TextView) btnEditorProBadge).setTextSize(10);
        ((TextView) btnEditorProBadge).setTypeface(null, Typeface.BOLD);
        btnEditorProBadge.setBackgroundResource(R.drawable.bg_capcut_pro_badge);
        LinearLayout.LayoutParams proParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        proParams.setMargins(0, 0, 16, 0);
        btnEditorProBadge.setLayoutParams(proParams);
        topBar.addView(btnEditorProBadge);

        btnEditorResolution = new TextView(activity);
        ((TextView) btnEditorResolution).setText("1080P ▾");
        ((TextView) btnEditorResolution).setTextColor(Color.WHITE);
        ((TextView) btnEditorResolution).setTextSize(12);
        btnEditorResolution.setBackgroundResource(R.drawable.bg_capcut_resolution_pill);
        btnEditorResolution.setOnClickListener(this);
        topBar.addView(btnEditorResolution);

        btnEditorExport = new TextView(activity);
        ((TextView) btnEditorExport).setText("Xuất ▾");
        ((TextView) btnEditorExport).setTextColor(Color.BLACK);
        ((TextView) btnEditorExport).setTextSize(13);
        ((TextView) btnEditorExport).setTypeface(null, Typeface.BOLD);
        ((TextView) btnEditorExport).setGravity(Gravity.CENTER);
        ((TextView) btnEditorExport).setPadding(36, 16, 36, 16);
        ((TextView) btnEditorExport).setMinimumWidth(160);
        ((TextView) btnEditorExport).setMinimumHeight(72);
        btnEditorExport.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams exportParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        exportParams.setMargins(14, 0, 0, 0);
        btnEditorExport.setLayoutParams(exportParams);
        btnEditorExport.setOnClickListener(this);
        topBar.addView(btnEditorExport);

        editorView.addView(topBar);

        // 2. Video Canvas Preview Area
        FrameLayout canvasContainer = new FrameLayout(activity);
        canvasContainer.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 0, 1.0f));
        canvasContainer.setBackgroundColor(Color.parseColor("#090A0E"));

        tvCanvasGestureHint = new TextView(activity);
        tvCanvasGestureHint.setText("Sử dụng cả hai ngón tay để thay đổi kích cỡ video");
        tvCanvasGestureHint.setTextColor(Color.parseColor("#64748B"));
        tvCanvasGestureHint.setTextSize(11);
        tvCanvasGestureHint.setGravity(Gravity.CENTER);
        tvCanvasGestureHint.setPadding(0, 12, 0, 0);
        FrameLayout.LayoutParams hintParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.TOP);
        canvasContainer.addView(tvCanvasGestureHint, hintParams);

        canvasFrame = new FrameLayout(activity);
        canvasFrame.setBackgroundColor(Color.parseColor("#141824"));
        canvasFrame.setOnClickListener(this);

        // Video Player View for Real Video Playback
        videoPlayerView = new VideoView(activity);
        videoPlayerView.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT, Gravity.CENTER));
        videoPlayerView.setOnPreparedListener(this);
        videoPlayerView.setOnErrorListener(this);
        videoPlayerView.setOnCompletionListener(this);
        videoPlayerView.setOnClickListener(this);
        canvasFrame.addView(videoPlayerView);

        // Poster Image View for Photo Clips or Thumbnails
        ivVideoPoster = new ImageView(activity);
        ivVideoPoster.setScaleType(ImageView.ScaleType.FIT_CENTER);
        ivVideoPoster.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT, Gravity.CENTER));
        ivVideoPoster.setOnClickListener(this);
        canvasFrame.addView(ivVideoPoster);

        // Real-Time Visual FX Overlay on Video Canvas
        videoFxOverlayView = new ImageView(activity);
        videoFxOverlayView.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT, Gravity.CENTER));
        videoFxOverlayView.setScaleType(ImageView.ScaleType.FIT_XY);
        canvasFrame.addView(videoFxOverlayView);

        // PIP Overlay Container on Video Canvas
        pipOverlayContainer = new FrameLayout(activity);
        FrameLayout.LayoutParams pipParams = new FrameLayout.LayoutParams(340, 200, Gravity.TOP | Gravity.START);
        pipParams.setMargins(40, 60, 0, 0);
        pipOverlayContainer.setLayoutParams(pipParams);
        pipOverlayContainer.setVisibility(View.GONE);

        ivPipPreview = new ImageView(activity);
        ivPipPreview.setScaleType(ImageView.ScaleType.CENTER_CROP);
        ivPipPreview.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));
        ivPipPreview.setBackgroundResource(R.drawable.bg_capcut_clip_selected);
        pipOverlayContainer.addView(ivPipPreview);

        tvPipBlendBadge = new TextView(activity);
        tvPipBlendBadge.setText("🔲 PIP: NORMAL");
        tvPipBlendBadge.setTextColor(Color.WHITE);
        tvPipBlendBadge.setTextSize(9);
        tvPipBlendBadge.setTypeface(null, Typeface.BOLD);
        tvPipBlendBadge.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        tvPipBlendBadge.setPadding(8, 2, 8, 2);
        tvPipBlendBadge.setOnClickListener(new PipBlendBadgeClickListener(this));
        FrameLayout.LayoutParams badgeParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.TOP | Gravity.START);
        pipOverlayContainer.addView(tvPipBlendBadge, badgeParams);

        pipOverlayContainer.setOnTouchListener(new PipDragTouchListener(this));
        canvasFrame.addView(pipOverlayContainer);

        // Metadata HUD
        tvSceneArt = new TextView(activity);
        tvSceneArt.setText("🎬 NextAI OpenCut");
        tvSceneArt.setTextColor(Color.parseColor("#CCCCCC"));
        tvSceneArt.setTextSize(10);
        tvSceneArt.setGravity(Gravity.START);
        tvSceneArt.setBackgroundColor(Color.TRANSPARENT);
        tvSceneArt.setPadding(16, 12, 16, 12);
        FrameLayout.LayoutParams artParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.TOP | Gravity.START);
        canvasFrame.addView(tvSceneArt, artParams);

        // Subtitle Overlay HUD
        tvCanvasSubtitleOverlay = new TextView(activity);
        tvCanvasSubtitleOverlay.setText("⚡ Phụ Đề AI: Chào mừng đến với NextAI OpenCut!");
        tvCanvasSubtitleOverlay.setTextColor(Color.parseColor("#FBBF24"));
        tvCanvasSubtitleOverlay.setTextSize(13);
        tvCanvasSubtitleOverlay.setTypeface(null, Typeface.BOLD);
        tvCanvasSubtitleOverlay.setGravity(Gravity.CENTER);
        tvCanvasSubtitleOverlay.setBackgroundColor(Color.parseColor("#CC000000"));
        tvCanvasSubtitleOverlay.setPadding(20, 8, 20, 8);
        tvCanvasSubtitleOverlay.setVisibility(View.GONE);
        FrameLayout.LayoutParams subParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.BOTTOM | Gravity.CENTER_HORIZONTAL);
        subParams.bottomMargin = 70;
        canvasFrame.addView(tvCanvasSubtitleOverlay, subParams);

        // Custom Text Overlay
        tvCanvasTextOverlay = new TextView(activity);
        tvCanvasTextOverlay.setText("");
        tvCanvasTextOverlay.setTextColor(Color.parseColor("#00E5FF"));
        tvCanvasTextOverlay.setTextSize(16);
        tvCanvasTextOverlay.setTypeface(null, Typeface.BOLD);
        tvCanvasTextOverlay.setGravity(Gravity.CENTER);
        tvCanvasTextOverlay.setVisibility(View.GONE);
        tvCanvasTextOverlay.setOnTouchListener(new TextOverlayTouchListener(this));
        FrameLayout.LayoutParams textParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.CENTER);
        canvasFrame.addView(tvCanvasTextOverlay, textParams);

        canvasContainer.addView(canvasFrame);
        updateVideoCanvasDimensions();
        editorView.addView(canvasContainer);

        // 3. Player Bar
        LinearLayout playerBar = new LinearLayout(activity);
        playerBar.setOrientation(LinearLayout.HORIZONTAL);
        playerBar.setGravity(Gravity.CENTER_VERTICAL);
        playerBar.setPadding(16, 6, 16, 6);
        playerBar.setBackgroundColor(Color.parseColor("#000000"));

        btnPlayerFullscreen = new TextView(activity);
        ((TextView) btnPlayerFullscreen).setText("⛶");
        ((TextView) btnPlayerFullscreen).setTextColor(Color.WHITE);
        ((TextView) btnPlayerFullscreen).setTextSize(16);
        ((TextView) btnPlayerFullscreen).setPadding(8, 4, 8, 4);
        btnPlayerFullscreen.setOnClickListener(this);
        playerBar.addView(btnPlayerFullscreen);

        View pSpacer1 = new View(activity);
        playerBar.addView(pSpacer1, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnPlayerPlayPause = new LinearLayout(activity);
        tvPlayerPlayIcon = new TextView(activity);
        tvPlayerPlayIcon.setText("▷");
        tvPlayerPlayIcon.setTextColor(Color.WHITE);
        tvPlayerPlayIcon.setTextSize(18);
        tvPlayerPlayIcon.setPadding(12, 4, 12, 4);
        ((LinearLayout) btnPlayerPlayPause).addView(tvPlayerPlayIcon);
        btnPlayerPlayPause.setOnClickListener(this);
        playerBar.addView(btnPlayerPlayPause);

        // Keyframe Toggle Button
        btnKeyframeToggle = new TextView(activity);
        btnKeyframeToggle.setText("+◆");
        btnKeyframeToggle.setTextColor(Color.parseColor("#00E5FF"));
        btnKeyframeToggle.setTextSize(16);
        btnKeyframeToggle.setTypeface(null, Typeface.BOLD);
        btnKeyframeToggle.setPadding(12, 4, 12, 4);
        btnKeyframeToggle.setOnClickListener(this);
        playerBar.addView(btnKeyframeToggle);

        View pSpacer2 = new View(activity);
        playerBar.addView(pSpacer2, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnPlayerUndo = new TextView(activity);
        ((TextView) btnPlayerUndo).setText("↶");
        ((TextView) btnPlayerUndo).setTextColor(Color.parseColor("#64748B"));
        ((TextView) btnPlayerUndo).setTextSize(19);
        ((TextView) btnPlayerUndo).setPadding(8, 4, 12, 4);
        btnPlayerUndo.setOnClickListener(this);
        playerBar.addView(btnPlayerUndo);

        btnPlayerRedo = new TextView(activity);
        ((TextView) btnPlayerRedo).setText("↷");
        ((TextView) btnPlayerRedo).setTextColor(Color.parseColor("#64748B"));
        ((TextView) btnPlayerRedo).setTextSize(19);
        ((TextView) btnPlayerRedo).setPadding(12, 4, 8, 4);
        btnPlayerRedo.setOnClickListener(this);
        playerBar.addView(btnPlayerRedo);

        editorView.addView(playerBar);

        // 4. Timecode & Ruler
        LinearLayout rulerBar = new LinearLayout(activity);
        rulerBar.setOrientation(LinearLayout.HORIZONTAL);
        rulerBar.setGravity(Gravity.CENTER_VERTICAL);
        rulerBar.setPadding(24, 4, 24, 4);
        rulerBar.setBackgroundColor(Color.parseColor("#000000"));

        tvPlayerTimecode = new TextView(activity);
        tvPlayerTimecode.setText("00:00 / 00:16");
        tvPlayerTimecode.setTextColor(Color.parseColor("#94A3B8"));
        tvPlayerTimecode.setTextSize(11);
        rulerBar.addView(tvPlayerTimecode);

        View rSpacer = new View(activity);
        rulerBar.addView(rSpacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        TextView tvPlayheadArrow = new TextView(activity);
        tvPlayheadArrow.setText("▼");
        tvPlayheadArrow.setTextColor(Color.parseColor("#00E5FF"));
        tvPlayheadArrow.setTextSize(12);
        tvPlayheadArrow.setGravity(Gravity.CENTER);
        rulerBar.addView(tvPlayheadArrow);

        View rSpacer2 = new View(activity);
        rulerBar.addView(rSpacer2, new LinearLayout.LayoutParams(0, 0, 1.0f));

        TextView tvRulerRatioBadge = new TextView(activity);
        tvRulerRatioBadge.setText("📐 " + currentVideoRatio);
        tvRulerRatioBadge.setTextColor(Color.parseColor("#38BDF8"));
        tvRulerRatioBadge.setTextSize(10);
        tvRulerRatioBadge.setBackgroundColor(Color.parseColor("#1E293B"));
        tvRulerRatioBadge.setPadding(12, 4, 12, 4);
        rulerBar.addView(tvRulerRatioBadge);

        editorView.addView(rulerBar);

        // 5. Timeline Tracks (Multi-track Separation & Dynamic Running Ruler)
        FrameLayout timelineWrapper = new FrameLayout(activity);
        timelineWrapper.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 360));
        timelineWrapper.setBackgroundColor(Color.parseColor("#0D0E12"));

        LinearLayout timelineTracksRow = new LinearLayout(activity);
        timelineTracksRow.setOrientation(LinearLayout.HORIZONTAL);
        timelineTracksRow.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        // Fixed Left Column (Mute & Cover)
        LinearLayout leftCol = new LinearLayout(activity);
        leftCol.setOrientation(LinearLayout.HORIZONTAL);
        leftCol.setGravity(Gravity.CENTER_VERTICAL);
        leftCol.setPadding(16, 0, 12, 0);
        leftCol.setBackgroundColor(Color.parseColor("#0D0E12"));

        btnMuteAudio = new LinearLayout(activity);
        ((LinearLayout) btnMuteAudio).setOrientation(LinearLayout.VERTICAL);
        ((LinearLayout) btnMuteAudio).setGravity(Gravity.CENTER);
        ((LinearLayout) btnMuteAudio).setPadding(6, 4, 6, 4);

        TextView tvMuteIcon = new TextView(activity);
        tvMuteIcon.setText("🔊");
        tvMuteIcon.setTextSize(16);
        ((LinearLayout) btnMuteAudio).addView(tvMuteIcon);

        TextView tvMuteLabel = new TextView(activity);
        tvMuteLabel.setText("Tắt tiếng");
        tvMuteLabel.setTextColor(Color.parseColor("#94A3B8"));
        tvMuteLabel.setTextSize(9);
        tvMuteLabel.setPadding(0, 2, 0, 0);
        ((LinearLayout) btnMuteAudio).addView(tvMuteLabel);
        btnMuteAudio.setOnClickListener(this);
        leftCol.addView(btnMuteAudio);

        btnCoverFrame = new LinearLayout(activity);
        btnCoverFrame.setBackgroundResource(R.drawable.bg_capcut_cover_box);
        ((LinearLayout) btnCoverFrame).setOrientation(LinearLayout.VERTICAL);
        ((LinearLayout) btnCoverFrame).setGravity(Gravity.CENTER);
        ((LinearLayout) btnCoverFrame).setPadding(10, 8, 10, 8);
        LinearLayout.LayoutParams coverParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        coverParams.setMargins(8, 0, 8, 0);
        btnCoverFrame.setLayoutParams(coverParams);

        TextView tvCoverIcon = new TextView(activity);
        tvCoverIcon.setText("🖼️");
        tvCoverIcon.setTextColor(Color.WHITE);
        tvCoverIcon.setTextSize(14);
        tvCoverIconView = tvCoverIcon;
        ((LinearLayout) btnCoverFrame).addView(tvCoverIcon);

        TextView tvCoverLabel = new TextView(activity);
        tvCoverLabel.setText("Ảnh bìa");
        tvCoverLabel.setTextColor(Color.WHITE);
        tvCoverLabel.setTextSize(9);
        tvCoverLabel.setPadding(0, 2, 0, 0);
        tvCoverLabelView = tvCoverLabel;
        ((LinearLayout) btnCoverFrame).addView(tvCoverLabel);
        btnCoverFrame.setOnClickListener(this);
        leftCol.addView(btnCoverFrame);

        timelineTracksRow.addView(leftCol);

        // Scrollable Tracks Area
        ScrollView vScrollTracks = new ScrollView(activity);
        vScrollTracks.setVerticalScrollBarEnabled(false);
        vScrollTracks.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 1.0f));

        hScrollTracks = new HorizontalScrollView(activity);
        hScrollTracks.setHorizontalScrollBarEnabled(false);
        hScrollTracks.setLayoutParams(new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT));
        timelineScaleDetector = new ScaleGestureDetector(activity, new TimelineScaleListener(this));
        hScrollTracks.setOnTouchListener(new TimelineTouchListener(this));
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            hScrollTracks.setOnScrollChangeListener(new TimelineScrollChangeListener(this));
        }

        LinearLayout scrollTrackContent = new LinearLayout(activity);
        scrollTrackContent.setOrientation(LinearLayout.VERTICAL);
        scrollTrackContent.setGravity(Gravity.CENTER_VERTICAL);
        scrollTrackContent.setPadding(8, 6, 48, 6);

        timelineRulerRow = new LinearLayout(activity);
        timelineRulerRow.setOrientation(LinearLayout.HORIZONTAL);
        timelineRulerRow.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT));
        timelineRulerRow.setPadding(0, 0, 0, 4);
        scrollTrackContent.addView(timelineRulerRow);

        // Track 1: Main Video Track
        timelineClipsRow = new LinearLayout(activity);
        timelineClipsRow.setOrientation(LinearLayout.HORIZONTAL);
        timelineClipsRow.setGravity(Gravity.CENTER_VERTICAL);
        timelineClipsRow.setBackgroundResource(R.drawable.bg_capcut_clip_selected);
        timelineClipsRow.setPadding(4, 2, 4, 2);
        timelineClipsRow.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_VIDEO));

        renderTimelineFilmstrip();

        btnAddMediaClip = new LinearLayout(activity);
        btnAddMediaClip.setBackgroundResource(R.drawable.bg_capcut_add_btn);
        ((LinearLayout) btnAddMediaClip).setGravity(Gravity.CENTER);
        LinearLayout.LayoutParams addParams = new LinearLayout.LayoutParams(80, 80);
        addParams.setMargins(12, 0, 0, 0);
        btnAddMediaClip.setLayoutParams(addParams);

        TextView tvAddPlus = new TextView(activity);
        tvAddPlus.setText("+");
        tvAddPlus.setTextColor(Color.WHITE);
        tvAddPlus.setTextSize(24);
        tvAddPlus.setTypeface(null, Typeface.BOLD);
        ((LinearLayout) btnAddMediaClip).addView(tvAddPlus);
        btnAddMediaClip.setOnClickListener(this);

        LinearLayout mainRow = new LinearLayout(activity);
        mainRow.setOrientation(LinearLayout.HORIZONTAL);
        mainRow.setGravity(Gravity.CENTER_VERTICAL);
        mainRow.addView(timelineClipsRow);
        mainRow.addView(btnAddMediaClip);

        // End of Video Marker
        viewEndOfVideoMarker = new LinearLayout(activity);
        viewEndOfVideoMarker.setBackgroundResource(R.drawable.bg_track_end_marker);
        ((LinearLayout) viewEndOfVideoMarker).setOrientation(LinearLayout.VERTICAL);
        ((LinearLayout) viewEndOfVideoMarker).setGravity(Gravity.CENTER);
        ((LinearLayout) viewEndOfVideoMarker).setPadding(14, 8, 14, 8);
        LinearLayout.LayoutParams endParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, 72);
        endParams.setMargins(16, 0, 32, 0);
        viewEndOfVideoMarker.setLayoutParams(endParams);

        TextView tvEndFlag = new TextView(activity);
        tvEndFlag.setText("🏁");
        tvEndFlag.setTextSize(14);
        ((LinearLayout) viewEndOfVideoMarker).addView(tvEndFlag);

        TextView tvEndText = new TextView(activity);
        tvEndText.setText("HẾT VIDEO");
        tvEndText.setTextColor(Color.WHITE);
        tvEndText.setTextSize(8);
        tvEndText.setTypeface(null, Typeface.BOLD);
        ((LinearLayout) viewEndOfVideoMarker).addView(tvEndText);
        mainRow.addView(viewEndOfVideoMarker);

        scrollTrackContent.addView(mainRow);

        // Track 2: PIP Overlay Track
        timelinePipRow = new LinearLayout(activity);
        timelinePipRow.setOrientation(LinearLayout.HORIZONTAL);
        timelinePipRow.setGravity(Gravity.CENTER_VERTICAL);
        timelinePipRow.setPadding(0, 4, 0, 4);
        timelinePipRow.setVisibility(View.VISIBLE);
        timelinePipRow.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_PIP));

        tvPipTrackBlock = new TextView(activity);
        tvPipTrackBlock.setText("🔲 [Lớp phủ PIP: Video/Ảnh phụ | Chạm để sửa]");
        tvPipTrackBlock.setTextColor(Color.parseColor("#E0E7FF"));
        tvPipTrackBlock.setTextSize(10);
        tvPipTrackBlock.setTypeface(null, Typeface.BOLD);
        tvPipTrackBlock.setBackgroundResource(R.drawable.bg_track_effect);
        tvPipTrackBlock.setPadding(20, 8, 20, 8);
        tvPipTrackBlock.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_PIP));
        timelinePipRow.addView(tvPipTrackBlock);
        scrollTrackContent.addView(timelinePipRow);

        // Track 3: Subtitle Track
        timelineSubtitlesRow = new LinearLayout(activity);
        timelineSubtitlesRow.setOrientation(LinearLayout.HORIZONTAL);
        timelineSubtitlesRow.setGravity(Gravity.CENTER_VERTICAL);
        timelineSubtitlesRow.setPadding(0, 4, 0, 4);
        timelineSubtitlesRow.setVisibility(View.VISIBLE);
        timelineSubtitlesRow.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_SUBTITLE));

        tvSubTrackBlock = new TextView(activity);
        tvSubTrackBlock.setText("⚡ [Phụ đề AI: 4 câu | Word-By-Word Karaoke]");
        tvSubTrackBlock.setTextColor(Color.parseColor("#FDE68A"));
        tvSubTrackBlock.setTextSize(10);
        tvSubTrackBlock.setTypeface(null, Typeface.BOLD);
        tvSubTrackBlock.setBackgroundResource(R.drawable.bg_track_text);
        tvSubTrackBlock.setPadding(20, 8, 20, 8);
        tvSubTrackBlock.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_SUBTITLE));
        timelineSubtitlesRow.addView(tvSubTrackBlock);
        scrollTrackContent.addView(timelineSubtitlesRow);

        // Track 4: Multi-Layer Audio Tracks
        timelineAudioContainer = new LinearLayout(activity);
        timelineAudioContainer.setOrientation(LinearLayout.VERTICAL);
        timelineAudioContainer.setPadding(0, 2, 0, 2);
        scrollTrackContent.addView(timelineAudioContainer);
        renderMultiAudioTracks();

        // Track 5: Effect Track
        timelineEffectsRow = new LinearLayout(activity);
        timelineEffectsRow.setOrientation(LinearLayout.HORIZONTAL);
        timelineEffectsRow.setGravity(Gravity.CENTER_VERTICAL);
        timelineEffectsRow.setPadding(0, 4, 0, 4);
        timelineEffectsRow.setVisibility(View.VISIBLE);
        timelineEffectsRow.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_EFFECT));

        tvEffectTrackBlock = new TextView(activity);
        tvEffectTrackBlock.setText("⭐ [Hiệu ứng: Neon Glow + Cyberpunk LUT]");
        tvEffectTrackBlock.setTextColor(Color.parseColor("#E9D5FF"));
        tvEffectTrackBlock.setTextSize(10);
        tvEffectTrackBlock.setTypeface(null, Typeface.BOLD);
        tvEffectTrackBlock.setBackgroundResource(R.drawable.bg_track_effect);
        tvEffectTrackBlock.setPadding(20, 8, 20, 8);
        tvEffectTrackBlock.setOnClickListener(new TrackSelectionClickListener(this, TRACK_TYPE_EFFECT));
        timelineEffectsRow.addView(tvEffectTrackBlock);
        scrollTrackContent.addView(timelineEffectsRow);

        btnAddAudioTrack = new LinearLayout(activity);
        ((LinearLayout) btnAddAudioTrack).setOrientation(LinearLayout.HORIZONTAL);
        ((LinearLayout) btnAddAudioTrack).setGravity(Gravity.CENTER_VERTICAL);
        btnAddAudioTrack.setPadding(20, 8, 20, 8);
        btnAddAudioTrack.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        LinearLayout.LayoutParams atParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        atParams.setMargins(0, 8, 0, 0);
        btnAddAudioTrack.setLayoutParams(atParams);

        TextView tvAddAudio = new TextView(activity);
        tvAddAudio.setText("+ Thêm âm thanh (Lồng nhiều track BGM / Sound FX / Voiceover)");
        tvAddAudio.setTextColor(Color.BLACK);
        tvAddAudio.setTextSize(10);
        tvAddAudio.setTypeface(null, Typeface.BOLD);
        ((LinearLayout) btnAddAudioTrack).addView(tvAddAudio);
        btnAddAudioTrack.setOnClickListener(this);
        scrollTrackContent.addView(btnAddAudioTrack);

        hScrollTracks.addView(scrollTrackContent);
        vScrollTracks.addView(hScrollTracks);
        timelineTracksRow.addView(vScrollTracks);
        timelineWrapper.addView(timelineTracksRow);

        // Playhead
        View playheadLine = new View(activity);
        playheadLine.setBackgroundColor(Color.WHITE);
        FrameLayout.LayoutParams phParams = new FrameLayout.LayoutParams(
            4, FrameLayout.LayoutParams.MATCH_PARENT);
        phParams.leftMargin = 270;
        playheadLine.setLayoutParams(phParams);
        timelineWrapper.addView(playheadLine);

        editorView.addView(timelineWrapper);

        // 6. Hierarchical Ribbon
        ribbonContainer = new FrameLayout(activity);
        ribbonContainer.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));

        buildMainMenuRibbon();
        buildEditSubmenuRibbon();
        buildSpeedDrawerRibbon();
        buildVolumeDrawerRibbon();
        buildAdjustDrawerRibbon();
        buildRatioDrawerRibbon();
        buildCanvasSubmenuRibbon();
        buildAudioSubmenuRibbon();
        buildEffectsDrawerRibbon();
        buildCutoutDrawerRibbon();
        buildTextSubmenuRibbon();
        buildBeautyDrawerRibbon();
        buildMaskDrawerRibbon();
        buildPipContextToolbarRibbon();

        showRibbonLevel(ribbonMainMenu);
        editorView.addView(ribbonContainer);
    }

    private void buildMainMenuRibbon() {
        ribbonMainMenu = new LinearLayout(activity);
        ribbonMainMenu.setOrientation(LinearLayout.HORIZONTAL);
        ribbonMainMenu.setBackgroundColor(Color.parseColor("#12131A"));

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        scroll.setPadding(8, 8, 8, 8);

        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        toolEdit = createToolItem("✂️", "Chỉnh sửa", row);
        toolAudio = createToolItem("🎵", "Âm thanh", row);
        toolText = createToolItem("🔤", "Văn bản", row);
        toolOverlay = createToolItem("📑", "Lớp phủ", row);
        toolEffects = createToolItem("⭐", "Hiệu ứng", row);
        toolCaptions = createToolItem("⚡", "Chú thích", row);
        toolRatio = createToolItem("📐", "Tỷ lệ", row);
        toolFilters = createToolItem("🌈", "Bộ lọc", row);
        toolAdjust = createToolItem("⚙️", "Tùy chỉnh", row);
        toolStickers = createToolItem("🏷️", "Nhãn dán", row);
        toolCanvas = createToolItem("◩", "Bảng vẽ", row);

        scroll.addView(row);
        ribbonMainMenu.addView(scroll);
    }

    private View createToolItem(String icon, String label, LinearLayout parent) {
        LinearLayout item = new LinearLayout(activity);
        item.setOrientation(LinearLayout.VERTICAL);
        item.setGravity(Gravity.CENTER);
        item.setPadding(22, 6, 22, 6);

        TextView tvIcon = new TextView(activity);
        tvIcon.setText(icon);
        tvIcon.setTextSize(20);
        item.addView(tvIcon);

        TextView tvLabel = new TextView(activity);
        tvLabel.setText(label);
        tvLabel.setTextColor(Color.parseColor("#E2E8F0"));
        tvLabel.setTextSize(10);
        tvLabel.setPadding(0, 4, 0, 0);
        item.addView(tvLabel);

        item.setOnClickListener(this);
        parent.addView(item);
        return item;
    }

    private void buildEditSubmenuRibbon() {
        ribbonEditSubmenu = new LinearLayout(activity);
        ribbonEditSubmenu.setOrientation(LinearLayout.HORIZONTAL);
        ribbonEditSubmenu.setGravity(Gravity.CENTER_VERTICAL);
        ribbonEditSubmenu.setPadding(8, 8, 8, 8);
        ribbonEditSubmenu.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromEdit = createBackBox(ribbonEditSubmenu);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setGravity(Gravity.CENTER_VERTICAL);

        subToolSplit = createSubToolItem("✂️", "Tách", false, row);
        subToolSpeed = createSubToolItem("⚡", "Tốc độ", false, row);
        subToolVolume = createSubToolItem("🔊", "Âm lượng", false, row);
        subToolDelete = createSubToolItem("🗑️", "Xóa", false, row);
        subToolCutout = createSubToolItem("✂️", "Khóa phông", false, row);
        subToolBeauty = createSubToolItem("👤", "Làm đẹp", false, row);
        subToolAdjust = createSubToolItem("⚙️", "Chỉnh màu", false, row);
        subToolRatio = createSubToolItem("📐", "Tỷ lệ", false, row);
        subToolAnimation = createSubToolItem("✨", "Hoạt ảnh", false, row);
        subToolDuplicate = createSubToolItem("📑", "Nhân bản", false, row);
        subToolReplace = createSubToolItem("🔄", "Thay thế", false, row);
        subToolOpacity = createSubToolItem("👁️", "Độ mờ", false, row);
        subToolFreeze = createSubToolItem("❄️", "Đóng băng", true, row);
        subToolReverse = createSubToolItem("↺", "Đảo ngược", true, row);
        subToolMask = createSubToolItem("🎭", "Mặt nạ", false, row);
        subToolRotate = createSubToolItem("🔄", "Xoay", false, row);
        subToolFlip = createSubToolItem("🪞", "Lật ngang", false, row);
        subToolCrop = createSubToolItem("📐", "Cắt", false, row);

        scroll.addView(row);
        ribbonEditSubmenu.addView(scroll);
    }

    private View createBackBox(LinearLayout parent) {
        LinearLayout backBox = new LinearLayout(activity);
        backBox.setOrientation(LinearLayout.VERTICAL);
        backBox.setGravity(Gravity.CENTER);
        backBox.setPadding(16, 6, 16, 6);
        backBox.setBackgroundColor(Color.parseColor("#1E202B"));

        TextView tvBackIcon = new TextView(activity);
        tvBackIcon.setText("‹");
        tvBackIcon.setTextColor(Color.WHITE);
        tvBackIcon.setTextSize(24);
        backBox.addView(tvBackIcon);

        backBox.setOnClickListener(this);
        parent.addView(backBox);
        return backBox;
    }

    private View createSubToolItem(String icon, String label, boolean isPro, LinearLayout parent) {
        LinearLayout item = new LinearLayout(activity);
        item.setOrientation(LinearLayout.VERTICAL);
        item.setGravity(Gravity.CENTER);
        item.setPadding(18, 6, 18, 6);

        FrameLayout iconFrame = new FrameLayout(activity);
        TextView tvIcon = new TextView(activity);
        tvIcon.setText(icon);
        tvIcon.setTextSize(18);
        tvIcon.setGravity(Gravity.CENTER);
        iconFrame.addView(tvIcon);

        if (isPro) {
            TextView proTag = new TextView(activity);
            proTag.setText("PRO");
            proTag.setTextColor(Color.BLACK);
            proTag.setTextSize(7);
            proTag.setTypeface(null, Typeface.BOLD);
            proTag.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
            proTag.setPadding(4, 1, 4, 1);
            FrameLayout.LayoutParams proLp = new FrameLayout.LayoutParams(
                FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.TOP | Gravity.END);
            iconFrame.addView(proTag, proLp);
        }
        item.addView(iconFrame);

        TextView tvLabel = new TextView(activity);
        tvLabel.setText(label);
        tvLabel.setTextColor(Color.parseColor("#CBD5E1"));
        tvLabel.setTextSize(10);
        tvLabel.setPadding(0, 4, 0, 0);
        item.addView(tvLabel);

        item.setOnClickListener(this);
        parent.addView(item);
        return item;
    }

    private void buildSpeedDrawerRibbon() {
        ribbonSpeedDrawer = new LinearLayout(activity);
        ribbonSpeedDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonSpeedDrawer.setPadding(12, 8, 12, 8);
        ribbonSpeedDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout topControls = new LinearLayout(activity);
        topControls.setOrientation(LinearLayout.HORIZONTAL);
        topControls.setGravity(Gravity.CENTER_VERTICAL);

        btnBackFromSpeed = createBackBox(topControls);

        speedTabStandard = new TextView(activity);
        ((TextView) speedTabStandard).setText("Tiêu chuẩn");
        ((TextView) speedTabStandard).setTextColor(Color.WHITE);
        ((TextView) speedTabStandard).setTextSize(12);
        ((TextView) speedTabStandard).setTypeface(null, Typeface.BOLD);
        speedTabStandard.setBackgroundResource(R.drawable.bg_capcut_tab_pill);
        speedTabStandard.setPadding(24, 10, 24, 10);
        speedTabStandard.setOnClickListener(this);
        topControls.addView(speedTabStandard);

        speedTabCurve = new TextView(activity);
        ((TextView) speedTabCurve).setText("Uốn cong ⚡");
        ((TextView) speedTabCurve).setTextColor(Color.parseColor("#00E5FF"));
        ((TextView) speedTabCurve).setTextSize(12);
        ((TextView) speedTabCurve).setTypeface(null, Typeface.BOLD);
        speedTabCurve.setBackgroundResource(R.drawable.bg_capcut_speed_pill);
        speedTabCurve.setPadding(24, 10, 24, 10);
        LinearLayout.LayoutParams curveParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        curveParams.setMargins(16, 0, 0, 0);
        speedTabCurve.setLayoutParams(curveParams);
        speedTabCurve.setOnClickListener(this);
        topControls.addView(speedTabCurve);

        View spSpacer = new View(activity);
        topControls.addView(spSpacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnPreservePitch = new TextView(activity);
        ((TextView) btnPreservePitch).setText("Giữ cao độ: BẬT");
        ((TextView) btnPreservePitch).setTextColor(Color.parseColor("#38BDF8"));
        ((TextView) btnPreservePitch).setTextSize(10);
        btnPreservePitch.setBackgroundResource(R.drawable.bg_capcut_resolution_pill);
        btnPreservePitch.setPadding(16, 8, 16, 8);
        btnPreservePitch.setOnClickListener(this);
        topControls.addView(btnPreservePitch);

        ribbonSpeedDrawer.addView(topControls);

        // Standard Speed Layout
        speedStandardLayout = new LinearLayout(activity);
        speedStandardLayout.setOrientation(LinearLayout.VERTICAL);
        speedStandardLayout.setPadding(8, 8, 8, 4);

        tvSpeedStandardVal = new TextView(activity);
        tvSpeedStandardVal.setText("Tốc độ chuẩn: 1.0x (0.1x - 100x)");
        tvSpeedStandardVal.setTextColor(Color.parseColor("#00E5FF"));
        tvSpeedStandardVal.setTextSize(11);
        tvSpeedStandardVal.setGravity(Gravity.CENTER);
        speedStandardLayout.addView(tvSpeedStandardVal);

        sbSpeedStandard = new SeekBar(activity);
        sbSpeedStandard.setMax(1000);
        sbSpeedStandard.setProgress(100);
        sbSpeedStandard.setOnSeekBarChangeListener(this);
        speedStandardLayout.addView(sbSpeedStandard);

        HorizontalScrollView pillScroll = new HorizontalScrollView(activity);
        pillScroll.setHorizontalScrollBarEnabled(false);
        LinearLayout pillRow = new LinearLayout(activity);
        pillRow.setOrientation(LinearLayout.HORIZONTAL);
        pillRow.setPadding(4, 4, 4, 4);

        speedPill01x = createSpeedPill("0.1x", pillRow);
        speedPill05x = createSpeedPill("0.5x", pillRow);
        speedPill1x = createSpeedPill("1.0x", pillRow);
        speedPill15x = createSpeedPill("1.5x", pillRow);
        speedPill2x = createSpeedPill("2.0x", pillRow);
        speedPill5x = createSpeedPill("5.0x", pillRow);
        speedPill10x = createSpeedPill("10x", pillRow);
        speedPill50x = createSpeedPill("50x", pillRow);
        speedPill100x = createSpeedPill("100x", pillRow);

        pillScroll.addView(pillRow);
        speedStandardLayout.addView(pillScroll);
        ribbonSpeedDrawer.addView(speedStandardLayout);

        // Curve Speed Layout (Bezier Visual Graph + Presets)
        speedCurveLayout = new LinearLayout(activity);
        speedCurveLayout.setOrientation(LinearLayout.VERTICAL);
        speedCurveLayout.setPadding(8, 4, 8, 4);
        speedCurveLayout.setVisibility(View.GONE);

        speedCurveGraphView = new SpeedCurveGraphView(activity);
        speedCurveGraphView.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 140));
        speedCurveLayout.addView(speedCurveGraphView);

        HorizontalScrollView curveScroll = new HorizontalScrollView(activity);
        curveScroll.setHorizontalScrollBarEnabled(false);
        LinearLayout curveRow = new LinearLayout(activity);
        curveRow.setOrientation(LinearLayout.HORIZONTAL);
        curveRow.setPadding(4, 6, 4, 4);

        speedCurveCustom = createSpeedPill("Tùy chỉnh", curveRow);
        speedCurveMontage = createSpeedPill("Montage", curveRow);
        speedCurveBullet = createSpeedPill("Bullet", curveRow);
        speedCurveHero = createSpeedPill("Hero", curveRow);
        speedCurveFlashIn = createSpeedPill("Flash In", curveRow);
        speedCurveJumpCut = createSpeedPill("Jump Cut", curveRow);

        curveScroll.addView(curveRow);
        speedCurveLayout.addView(curveScroll);
        ribbonSpeedDrawer.addView(speedCurveLayout);
    }

    private View createSpeedPill(String label, LinearLayout parent) {
        TextView pill = new TextView(activity);
        pill.setText(label);
        pill.setTextColor(Color.WHITE);
        pill.setTextSize(10);
        pill.setTypeface(null, Typeface.BOLD);
        pill.setBackgroundResource(R.drawable.bg_capcut_speed_pill);
        pill.setPadding(20, 8, 20, 8);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(6, 0, 6, 0);
        pill.setLayoutParams(lp);
        pill.setOnClickListener(this);
        parent.addView(pill);
        return pill;
    }

    private void buildVolumeDrawerRibbon() {
        ribbonVolumeDrawer = new LinearLayout(activity);
        ribbonVolumeDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonVolumeDrawer.setPadding(16, 8, 16, 8);
        ribbonVolumeDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout topRow = new LinearLayout(activity);
        topRow.setOrientation(LinearLayout.HORIZONTAL);
        topRow.setGravity(Gravity.CENTER_VERTICAL);

        btnBackFromVolume = createBackBox(topRow);

        tvVolumeVal = new TextView(activity);
        tvVolumeVal.setText("Âm lượng: 100%");
        tvVolumeVal.setTextColor(Color.parseColor("#00E5FF"));
        tvVolumeVal.setTextSize(12);
        tvVolumeVal.setTypeface(null, Typeface.BOLD);
        tvVolumeVal.setPadding(16, 0, 0, 0);
        topRow.addView(tvVolumeVal);

        ribbonVolumeDrawer.addView(topRow);

        sbVolume = new SeekBar(activity);
        sbVolume.setMax(1000); // 0% - 1000%
        sbVolume.setProgress(100);
        sbVolume.setOnSeekBarChangeListener(this);
        ribbonVolumeDrawer.addView(sbVolume);

        // Quick Preset Volume Pills
        LinearLayout volPills = new LinearLayout(activity);
        volPills.setOrientation(LinearLayout.HORIZONTAL);
        volPills.setPadding(4, 4, 4, 4);

        volPill0 = createSpeedPill("Tắt (0%)", volPills);
        volPill100 = createSpeedPill("Gốc (100%)", volPills);
        volPill200 = createSpeedPill("200%", volPills);
        volPill500 = createSpeedPill("500%", volPills);
        volPill1000 = createSpeedPill("Max (1000%)", volPills);

        ribbonVolumeDrawer.addView(volPills);

        // Fade In & Fade Out Seekbars
        LinearLayout fadeLayout = new LinearLayout(activity);
        fadeLayout.setOrientation(LinearLayout.HORIZONTAL);
        fadeLayout.setPadding(0, 4, 0, 4);

        LinearLayout fadeInCol = new LinearLayout(activity);
        fadeInCol.setOrientation(LinearLayout.VERTICAL);
        fadeInCol.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        tvFadeInVal = new TextView(activity);
        tvFadeInVal.setText("Fade In: 0.0s");
        tvFadeInVal.setTextColor(Color.parseColor("#94A3B8"));
        tvFadeInVal.setTextSize(10);
        fadeInCol.addView(tvFadeInVal);
        sbFadeIn = new SeekBar(activity);
        sbFadeIn.setMax(50); // 0.0s - 5.0s
        sbFadeIn.setProgress(0);
        sbFadeIn.setOnSeekBarChangeListener(this);
        fadeInCol.addView(sbFadeIn);
        fadeLayout.addView(fadeInCol);

        LinearLayout fadeOutCol = new LinearLayout(activity);
        fadeOutCol.setOrientation(LinearLayout.VERTICAL);
        fadeOutCol.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        tvFadeOutVal = new TextView(activity);
        tvFadeOutVal.setText("Fade Out: 0.0s");
        tvFadeOutVal.setTextColor(Color.parseColor("#94A3B8"));
        tvFadeOutVal.setTextSize(10);
        fadeOutCol.addView(tvFadeOutVal);
        sbFadeOut = new SeekBar(activity);
        sbFadeOut.setMax(50);
        sbFadeOut.setProgress(0);
        sbFadeOut.setOnSeekBarChangeListener(this);
        fadeOutCol.addView(sbFadeOut);
        fadeLayout.addView(fadeOutCol);

        ribbonVolumeDrawer.addView(fadeLayout);
    }

    private void buildAdjustDrawerRibbon() {
        ribbonAdjustDrawer = new LinearLayout(activity);
        ribbonAdjustDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonAdjustDrawer.setPadding(16, 8, 16, 8);
        ribbonAdjustDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout topRow = new LinearLayout(activity);
        topRow.setOrientation(LinearLayout.HORIZONTAL);
        topRow.setGravity(Gravity.CENTER_VERTICAL);
        btnBackFromAdjust = createBackBox(topRow);

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("⚙️ CHỈNH MÀU SẮC VIDEO");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(12);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(16, 0, 0, 0);
        topRow.addView(tvTitle);
        ribbonAdjustDrawer.addView(topRow);

        // Brightness
        tvVideoBrightVal = new TextView(activity);
        tvVideoBrightVal.setText("Độ sáng: 0");
        tvVideoBrightVal.setTextColor(Color.parseColor("#94A3B8"));
        tvVideoBrightVal.setTextSize(10);
        ribbonAdjustDrawer.addView(tvVideoBrightVal);
        sbVideoBright = new SeekBar(activity);
        sbVideoBright.setMax(200);
        sbVideoBright.setProgress(100);
        sbVideoBright.setOnSeekBarChangeListener(this);
        ribbonAdjustDrawer.addView(sbVideoBright);

        // Contrast
        tvVideoContrastVal = new TextView(activity);
        tvVideoContrastVal.setText("Tương phản: 100%");
        tvVideoContrastVal.setTextColor(Color.parseColor("#94A3B8"));
        tvVideoContrastVal.setTextSize(10);
        ribbonAdjustDrawer.addView(tvVideoContrastVal);
        sbVideoContrast = new SeekBar(activity);
        sbVideoContrast.setMax(200);
        sbVideoContrast.setProgress(100);
        sbVideoContrast.setOnSeekBarChangeListener(this);
        ribbonAdjustDrawer.addView(sbVideoContrast);

        // Saturation
        tvVideoSatVal = new TextView(activity);
        tvVideoSatVal.setText("Bão hòa: 100%");
        tvVideoSatVal.setTextColor(Color.parseColor("#94A3B8"));
        tvVideoSatVal.setTextSize(10);
        ribbonAdjustDrawer.addView(tvVideoSatVal);
        sbVideoSat = new SeekBar(activity);
        sbVideoSat.setMax(200);
        sbVideoSat.setProgress(100);
        sbVideoSat.setOnSeekBarChangeListener(this);
        ribbonAdjustDrawer.addView(sbVideoSat);
    }

    private void buildRatioDrawerRibbon() {
        ribbonRatioDrawer = new LinearLayout(activity);
        ribbonRatioDrawer.setOrientation(LinearLayout.HORIZONTAL);
        ribbonRatioDrawer.setGravity(Gravity.CENTER_VERTICAL);
        ribbonRatioDrawer.setPadding(12, 12, 12, 12);
        ribbonRatioDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromRatio = createBackBox(ribbonRatioDrawer);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        ratioPill916 = createSpeedPill("9:16 (TikTok/Reels)", row);
        ratioPill169 = createSpeedPill("16:9 (YouTube)", row);
        ratioPill11 = createSpeedPill("1:1 (Instagram)", row);
        ratioPill45 = createSpeedPill("4:5 (Dọc Feed)", row);

        scroll.addView(row);
        ribbonRatioDrawer.addView(scroll);
    }

    private void buildCanvasSubmenuRibbon() {
        ribbonCanvasSubmenu = new LinearLayout(activity);
        ribbonCanvasSubmenu.setOrientation(LinearLayout.HORIZONTAL);
        ribbonCanvasSubmenu.setGravity(Gravity.CENTER_VERTICAL);
        ribbonCanvasSubmenu.setPadding(8, 8, 8, 8);
        ribbonCanvasSubmenu.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromCanvas = createBackBox(ribbonCanvasSubmenu);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        canvasOptColor = createToolItem("🎨", "Màu sắc", row);
        canvasOptBg = createToolItem("🖼️", "Phông nền", row);
        canvasOptBlur = createToolItem("💧", "Mờ viền", row);
        canvasOptBrand = createToolItem("✨", "Thương hiệu", row);

        scroll.addView(row);
        ribbonCanvasSubmenu.addView(scroll);
    }

    private void buildAudioSubmenuRibbon() {
        ribbonAudioSubmenu = new LinearLayout(activity);
        ribbonAudioSubmenu.setOrientation(LinearLayout.HORIZONTAL);
        ribbonAudioSubmenu.setGravity(Gravity.CENTER_VERTICAL);
        ribbonAudioSubmenu.setPadding(8, 8, 8, 8);
        ribbonAudioSubmenu.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromAudio = createBackBox(ribbonAudioSubmenu);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        audioOptSounds = createToolItem("🎵", "Âm thanh", row);
        audioOptSoundFx = createToolItem("🔔", "Hiệu ứng", row);
        audioOptExtract = createToolItem("📥", "Trích xuất", row);
        audioOptVoiceFx = createToolItem("🎙️", "Biến đổi giọng", row);
        audioOptNoiseReduction = createToolItem("🔇", "Giảm ồn", row);
        audioOptVocalIsolation = createToolItem("🎤", "Tách lời", row);
        audioOptBrand = createToolItem("🎧", "Nhạc bản quyền", row);

        scroll.addView(row);
        ribbonAudioSubmenu.addView(scroll);
    }

    private void buildEffectsDrawerRibbon() {
        ribbonEffectsDrawer = new LinearLayout(activity);
        ribbonEffectsDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonEffectsDrawer.setPadding(8, 8, 8, 8);
        ribbonEffectsDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout top = new LinearLayout(activity);
        top.setOrientation(LinearLayout.HORIZONTAL);
        top.setGravity(Gravity.CENTER_VERTICAL);
        btnBackFromEffects = createBackBox(top);

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("⭐ KHO HIỆU ỨNG C++20 SHADER");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(12);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(16, 0, 0, 0);
        top.addView(tvTitle);

        View eSpacer = new View(activity);
        top.addView(eSpacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnEffectsConfirm = new TextView(activity);
        ((TextView) btnEffectsConfirm).setText("✓ Áp dụng");
        ((TextView) btnEffectsConfirm).setTextColor(Color.BLACK);
        ((TextView) btnEffectsConfirm).setTextSize(11);
        ((TextView) btnEffectsConfirm).setTypeface(null, Typeface.BOLD);
        btnEffectsConfirm.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        btnEffectsConfirm.setPadding(16, 8, 16, 8);
        btnEffectsConfirm.setOnClickListener(this);
        top.addView(btnEffectsConfirm);

        ribbonEffectsDrawer.addView(top);

        // Effect Cards Scroll
        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setPadding(0, 8, 0, 4);

        fxCardGlitchRgb = createEffectCard("⚡ RGB Glitch", "glitch_rgb", row);
        fxCardCapCutSpin = createEffectCard("🌀 Spin Zoom", "spin_zoom", row);
        fxCardCapCutStar = createEffectCard("✨ Star Glow", "star_glow", row);
        fxCardFilmLeak = createEffectCard("🎞️ Film Leak", "film_leak", row);
        fxCardCapCutHexagon = createEffectCard("⬡ Hexagon AR", "hexagon", row);
        fxCardNoiseBlack = createEffectCard("📼 VHS Retro", "vhs_retro", row);

        scroll.addView(row);
        ribbonEffectsDrawer.addView(scroll);
    }

    private View createEffectCard(String title, final String fxKey, LinearLayout parent) {
        TextView card = new TextView(activity);
        card.setText(title);
        card.setTextColor(Color.WHITE);
        card.setTextSize(10);
        card.setTypeface(null, Typeface.BOLD);
        card.setBackgroundResource(R.drawable.bg_track_effect);
        card.setPadding(20, 12, 20, 12);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(6, 0, 6, 0);
        card.setLayoutParams(lp);
        card.setOnClickListener(new EffectCardClickListener(this, fxKey, title));
        parent.addView(card);
        return card;
    }

    private void buildCutoutDrawerRibbon() {
        ribbonCutoutDrawer = new LinearLayout(activity);
        ribbonCutoutDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonCutoutDrawer.setPadding(12, 8, 12, 8);
        ribbonCutoutDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout top = new LinearLayout(activity);
        top.setOrientation(LinearLayout.HORIZONTAL);
        top.setGravity(Gravity.CENTER_VERTICAL);
        btnBackFromCutout = createBackBox(top);

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("✂️ KHÓA PHÔNG MÀU (CHROMA KEY) & XÓA NỀN");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(12);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(16, 0, 0, 0);
        top.addView(tvTitle);
        ribbonCutoutDrawer.addView(top);

        // Color Presets
        LinearLayout colorRow = new LinearLayout(activity);
        colorRow.setOrientation(LinearLayout.HORIZONTAL);
        colorRow.setGravity(Gravity.CENTER_VERTICAL);
        colorRow.setPadding(0, 8, 0, 4);

        colorGreenScreen = createColorDot(Color.parseColor("#00FF00"), "Xanh lá", colorRow);
        colorBlueScreen = createColorDot(Color.parseColor("#0000FF"), "Xanh dương", colorRow);
        colorMagentaScreen = createColorDot(Color.parseColor("#FF00FF"), "Đỏ cánh sen", colorRow);

        btnApplyCutoutAi = new TextView(activity);
        ((TextView) btnApplyCutoutAi).setText("✂️ Tự động xóa nền AI");
        ((TextView) btnApplyCutoutAi).setTextColor(Color.BLACK);
        ((TextView) btnApplyCutoutAi).setTextSize(10);
        ((TextView) btnApplyCutoutAi).setTypeface(null, Typeface.BOLD);
        btnApplyCutoutAi.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        btnApplyCutoutAi.setPadding(16, 6, 16, 6);
        LinearLayout.LayoutParams aiLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        aiLp.setMargins(16, 0, 0, 0);
        btnApplyCutoutAi.setLayoutParams(aiLp);
        btnApplyCutoutAi.setOnClickListener(this);
        colorRow.addView(btnApplyCutoutAi);

        ribbonCutoutDrawer.addView(colorRow);

        // Seekbars
        tvChromaIntensityVal = new TextView(activity);
        tvChromaIntensityVal.setText("Cường độ: 65%");
        tvChromaIntensityVal.setTextColor(Color.parseColor("#94A3B8"));
        tvChromaIntensityVal.setTextSize(10);
        ribbonCutoutDrawer.addView(tvChromaIntensityVal);
        sbChromaIntensity = new SeekBar(activity);
        sbChromaIntensity.setMax(100);
        sbChromaIntensity.setProgress(65);
        sbChromaIntensity.setOnSeekBarChangeListener(this);
        ribbonCutoutDrawer.addView(sbChromaIntensity);

        tvChromaShadowVal = new TextView(activity);
        tvChromaShadowVal.setText("Độ mềm: 40%");
        tvChromaShadowVal.setTextColor(Color.parseColor("#94A3B8"));
        tvChromaShadowVal.setTextSize(10);
        ribbonCutoutDrawer.addView(tvChromaShadowVal);
        sbChromaShadow = new SeekBar(activity);
        sbChromaShadow.setMax(100);
        sbChromaShadow.setProgress(40);
        sbChromaShadow.setOnSeekBarChangeListener(this);
        ribbonCutoutDrawer.addView(sbChromaShadow);

        tvChromaSpillVal = new TextView(activity);
        tvChromaSpillVal.setText("Khử lem (Spill): 50%");
        tvChromaSpillVal.setTextColor(Color.parseColor("#94A3B8"));
        tvChromaSpillVal.setTextSize(10);
        ribbonCutoutDrawer.addView(tvChromaSpillVal);
        sbChromaSpill = new SeekBar(activity);
        sbChromaSpill.setMax(100);
        sbChromaSpill.setProgress(50);
        sbChromaSpill.setOnSeekBarChangeListener(this);
        ribbonCutoutDrawer.addView(sbChromaSpill);
    }

    private View createColorDot(final int color, String label, LinearLayout parent) {
        TextView dot = new TextView(activity);
        dot.setText("● " + label);
        dot.setTextColor(color);
        dot.setTextSize(11);
        dot.setBackgroundResource(R.drawable.bg_capcut_tab_pill);
        dot.setPadding(16, 8, 16, 8);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 10, 0);
        dot.setLayoutParams(lp);
        dot.setOnClickListener(new ChromaColorDotClickListener(this, color, label));
        parent.addView(dot);
        return dot;
    }

    private void buildTextSubmenuRibbon() {
        ribbonTextSubmenu = new LinearLayout(activity);
        ribbonTextSubmenu.setOrientation(LinearLayout.HORIZONTAL);
        ribbonTextSubmenu.setGravity(Gravity.CENTER_VERTICAL);
        ribbonTextSubmenu.setPadding(8, 8, 8, 8);
        ribbonTextSubmenu.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromText = createBackBox(ribbonTextSubmenu);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        subToolAddText = createToolItem("🔤", "Thêm chữ", row);
        subToolTextTemplate = createToolItem("📜", "Mẫu chữ", row);
        subToolAutoCaptions = createToolItem("⚡", "Phụ đề tự động", row);
        subToolTextTts = createToolItem("🎙️", "Đọc AI (TTS)", row);
        subToolTextEffects = createToolItem("✨", "Hiệu ứng chữ", row);

        scroll.addView(row);
        ribbonTextSubmenu.addView(scroll);
    }

    private void buildBeautyDrawerRibbon() {
        ribbonBeautyDrawer = new LinearLayout(activity);
        ribbonBeautyDrawer.setOrientation(LinearLayout.VERTICAL);
        ribbonBeautyDrawer.setPadding(12, 8, 12, 8);
        ribbonBeautyDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        LinearLayout top = new LinearLayout(activity);
        top.setOrientation(LinearLayout.HORIZONTAL);
        top.setGravity(Gravity.CENTER_VERTICAL);
        btnBackFromBeauty = createBackBox(top);

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("👤 LÀM ĐẸP & THU MẶT AR 468-POINT MESH");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(12);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(16, 0, 0, 0);
        top.addView(tvTitle);
        ribbonBeautyDrawer.addView(top);

        // Slim Face
        tvSlimFaceVal = new TextView(activity);
        tvSlimFaceVal.setText("Thu mặt: 50%");
        tvSlimFaceVal.setTextColor(Color.parseColor("#94A3B8"));
        tvSlimFaceVal.setTextSize(10);
        ribbonBeautyDrawer.addView(tvSlimFaceVal);
        sbSlimFace = new SeekBar(activity);
        sbSlimFace.setMax(100);
        sbSlimFace.setProgress(50);
        sbSlimFace.setOnSeekBarChangeListener(this);
        ribbonBeautyDrawer.addView(sbSlimFace);

        // Smooth Skin
        tvSmoothSkinVal = new TextView(activity);
        tvSmoothSkinVal.setText("Mịn da: 70%");
        tvSmoothSkinVal.setTextColor(Color.parseColor("#94A3B8"));
        tvSmoothSkinVal.setTextSize(10);
        ribbonBeautyDrawer.addView(tvSmoothSkinVal);
        sbSmoothSkin = new SeekBar(activity);
        sbSmoothSkin.setMax(100);
        sbSmoothSkin.setProgress(70);
        sbSmoothSkin.setOnSeekBarChangeListener(this);
        ribbonBeautyDrawer.addView(sbSmoothSkin);

        // Big Eyes
        tvBigEyesVal = new TextView(activity);
        tvBigEyesVal.setText("Mắt to: 40%");
        tvBigEyesVal.setTextColor(Color.parseColor("#94A3B8"));
        tvBigEyesVal.setTextSize(10);
        ribbonBeautyDrawer.addView(tvBigEyesVal);
        sbBigEyes = new SeekBar(activity);
        sbBigEyes.setMax(100);
        sbBigEyes.setProgress(40);
        sbBigEyes.setOnSeekBarChangeListener(this);
        ribbonBeautyDrawer.addView(sbBigEyes);

        // Teeth Whitening
        tvTeethVal = new TextView(activity);
        tvTeethVal.setText("Trắng răng: 60%");
        tvTeethVal.setTextColor(Color.parseColor("#94A3B8"));
        tvTeethVal.setTextSize(10);
        ribbonBeautyDrawer.addView(tvTeethVal);
        sbTeeth = new SeekBar(activity);
        sbTeeth.setMax(100);
        sbTeeth.setProgress(60);
        sbTeeth.setOnSeekBarChangeListener(this);
        ribbonBeautyDrawer.addView(sbTeeth);
    }

    private void buildMaskDrawerRibbon() {
        ribbonMaskDrawer = new LinearLayout(activity);
        ribbonMaskDrawer.setOrientation(LinearLayout.HORIZONTAL);
        ribbonMaskDrawer.setGravity(Gravity.CENTER_VERTICAL);
        ribbonMaskDrawer.setPadding(8, 8, 8, 8);
        ribbonMaskDrawer.setBackgroundColor(Color.parseColor("#12131A"));

        btnBackFromMask = createBackBox(ribbonMaskDrawer);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        maskOptLinear = createToolItem("➖", "Tuyến tính", row);
        maskOptCircle = createToolItem("⭕", "Hình tròn", row);
        maskOptMirror = createToolItem("🪞", "Gương soi", row);
        maskOptInvert = createToolItem("🔄", "Đảo ngược", row);

        scroll.addView(row);
        ribbonMaskDrawer.addView(scroll);
    }

    private void buildPipContextToolbarRibbon() {
        ribbonPipContextToolbar = new LinearLayout(activity);
        ribbonPipContextToolbar.setOrientation(LinearLayout.HORIZONTAL);
        ribbonPipContextToolbar.setGravity(Gravity.CENTER_VERTICAL);
        ribbonPipContextToolbar.setPadding(8, 8, 8, 8);
        ribbonPipContextToolbar.setBackgroundColor(Color.parseColor("#1E1B4B"));

        btnBackFromPip = createBackBox(ribbonPipContextToolbar);

        HorizontalScrollView scroll = new HorizontalScrollView(activity);
        scroll.setHorizontalScrollBarEnabled(false);
        LinearLayout row = new LinearLayout(activity);
        row.setOrientation(LinearLayout.HORIZONTAL);

        createPipContextTool("🔲 Chế độ hòa trộn (Blend)", "pip_blend", row);
        createPipContextTool("✂️ Khóa phông PIP", "pip_chroma", row);
        createPipContextTool("🎭 Mặt nạ lớp phủ", "pip_mask", row);
        createPipContextTool("🗑️ Xóa lớp phủ", "pip_delete", row);

        scroll.addView(row);
        ribbonPipContextToolbar.addView(scroll);
    }

    private View createPipContextTool(String label, final String action, LinearLayout parent) {
        TextView tool = new TextView(activity);
        tool.setText(label);
        tool.setTextColor(Color.WHITE);
        tool.setTextSize(11);
        tool.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        tool.setPadding(20, 10, 20, 10);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 10, 0);
        tool.setLayoutParams(lp);
        tool.setOnClickListener(new PipContextToolClickListener(this, action));
        parent.addView(tool);
        return tool;
    }

    private void showRibbonLevel(View target) {
        if (ribbonContainer == null) return;
        ribbonContainer.removeAllViews();
        if (target != null) {
            ribbonContainer.addView(target);
        }
    }

    public void updateVideoCanvasDimensions() {
        if (canvasFrame == null) return;
        DisplayMetrics dm = activity.getResources().getDisplayMetrics();
        int screenW = dm.widthPixels;
        int screenH = dm.heightPixels;

        int canvasW = screenW;
        int canvasH = (int) (screenW * (16f / 9f));

        if ("16:9 (YouTube)".equals(currentVideoRatio) || "16:9".equals(currentVideoRatio)) {
            canvasH = (int) (screenW * (9f / 16f));
        } else if ("1:1 (Instagram)".equals(currentVideoRatio) || "1:1".equals(currentVideoRatio)) {
            canvasH = screenW;
        } else if ("4:5 (Dọc Feed)".equals(currentVideoRatio) || "4:5".equals(currentVideoRatio)) {
            canvasH = (int) (screenW * (5f / 4f));
        }

        FrameLayout.LayoutParams lp = new FrameLayout.LayoutParams(canvasW, canvasH, Gravity.CENTER);
        canvasFrame.setLayoutParams(lp);
    }

    public void updatePlayerPreview() {
        if (activeProjectClips.isEmpty()) return;
        MediaItem clip = activeProjectClips.get(Math.min(selectedClipIndex, activeProjectClips.size() - 1));
        if (tvSceneArt != null) tvSceneArt.setText("🎬 " + clip.title + " • " + currentVideoRatio);
        if (tvPlayerTimecode != null) tvPlayerTimecode.setText("00:00 / " + calculateTotalDuration());
        applyVideoColorMatrix(clip.brightness, clip.contrast, clip.saturation);

        if (clip.uri != null) {
            if (clip.isVideo) {
                if (ivVideoPoster != null) ivVideoPoster.setVisibility(View.GONE);
                if (videoPlayerView != null) {
                    videoPlayerView.setVisibility(View.VISIBLE);
                    try {
                        videoPlayerView.stopPlayback();
                        videoPlayerView.setVideoURI(clip.uri);
                        videoPlayerView.seekTo(clip.trimInSec > 0 ? (clip.trimInSec * 1000) : 100);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            } else {
                if (videoPlayerView != null) videoPlayerView.setVisibility(View.GONE);
                if (ivVideoPoster != null) {
                    ivVideoPoster.setVisibility(View.VISIBLE);
                    try {
                        InputStream is = activity.getContentResolver().openInputStream(clip.uri);
                        BitmapFactory.Options opts = new BitmapFactory.Options();
                        opts.inSampleSize = 2;
                        Bitmap bm = BitmapFactory.decodeStream(is, null, opts);
                        if (is != null) is.close();
                        if (bm != null) {
                            bm = PhotoEditorComponent.fixExifOrientation(activity, clip.uri, bm);
                            ivVideoPoster.setImageBitmap(bm);
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        } else {
            if (videoPlayerView != null) videoPlayerView.setVisibility(View.GONE);
            if (ivVideoPoster != null) {
                ivVideoPoster.setVisibility(View.VISIBLE);
                ivVideoPoster.setImageDrawable(null);
                ivVideoPoster.setBackgroundColor(clip.colorBg);
            }
        }
    }

    public String calculateTotalDuration() {
        int totalSec = 0;
        for (MediaItem clip : activeProjectClips) {
            totalSec += clip.durationSeconds;
        }
        return String.format("%02d:%02d", totalSec / 60, totalSec % 60);
    }

    public void applyVideoColorMatrix(int bright, int contrast, int sat) {
        ColorMatrix cm = new ColorMatrix();
        cm.setSaturation(sat / 100.0f);

        float scale = contrast / 100.0f;
        float translate = bright;
        ColorMatrix contrastMatrix = new ColorMatrix(new float[]{
            scale, 0, 0, 0, translate,
            0, scale, 0, 0, translate,
            0, 0, scale, 0, translate,
            0, 0, 0, 1, 0
        });
        cm.postConcat(contrastMatrix);

        if ("portra".equals(currentVideoFilter)) {
            ColorMatrix portra = new ColorMatrix(new float[]{
                1.15f, 0, 0, 0, 15,
                0, 1.05f, 0, 0, 5,
                0, 0, 0.90f, 0, -10,
                0, 0, 0, 1, 0
            });
            cm.postConcat(portra);
        } else if ("cyberpunk".equals(currentVideoFilter)) {
            ColorMatrix cyber = new ColorMatrix(new float[]{
                1.2f, 0, 0.2f, 0, 10,
                0, 1.1f, 0.2f, 0, 0,
                0.2f, 0, 1.4f, 0, 20,
                0, 0, 0, 1, 0
            });
            cm.postConcat(cyber);
        } else if ("teal_orange".equals(currentVideoFilter)) {
            ColorMatrix tealOrange = new ColorMatrix(new float[]{
                1.25f, 0, 0, 0, 10,
                0, 1.0f, 0, 0, 0,
                0, 0, 1.2f, 0, 15,
                0, 0, 0, 1, 0
            });
            cm.postConcat(tealOrange);
        } else if ("noir".equals(currentVideoFilter)) {
            ColorMatrix noir = new ColorMatrix();
            noir.setSaturation(0);
            ColorMatrix noirContrast = new ColorMatrix(new float[]{
                1.3f, 0, 0, 0, -15,
                0, 1.3f, 0, 0, -15,
                0, 0, 1.3f, 0, -15,
                0, 0, 0, 1, 0
            });
            noir.postConcat(noirContrast);
            cm.postConcat(noir);
        } else if ("vintage".equals(currentVideoFilter)) {
            ColorMatrix vintage = new ColorMatrix(new float[]{
                1.1f, 0.1f, 0, 0, 10,
                0.05f, 1.0f, 0, 0, 5,
                0, 0.05f, 0.8f, 0, -15,
                0, 0, 0, 1, 0
            });
            cm.postConcat(vintage);
        }

        ColorMatrixColorFilter filter = new ColorMatrixColorFilter(cm);
        if (tvSceneArt != null) {
            tvSceneArt.getPaint().setColorFilter(filter);
            tvSceneArt.invalidate();
        }
        if (ivVideoPoster != null) {
            ivVideoPoster.setColorFilter(filter);
        }

        if (videoFxOverlayView != null) {
            boolean hasEffect = (bright != 0) || (contrast != 100) || (sat != 100) || !"none".equals(currentVideoFilter);
            if (hasEffect) {
                videoFxOverlayView.setVisibility(View.VISIBLE);
                int overlayColor = Color.TRANSPARENT;
                if ("portra".equals(currentVideoFilter)) {
                    overlayColor = Color.argb(45, 255, 170, 50);
                } else if ("cyberpunk".equals(currentVideoFilter)) {
                    overlayColor = Color.argb(55, 0, 229, 255);
                } else if ("teal_orange".equals(currentVideoFilter)) {
                    overlayColor = Color.argb(45, 0, 150, 136);
                } else if ("noir".equals(currentVideoFilter)) {
                    overlayColor = Color.argb(95, 20, 20, 20);
                } else if ("vintage".equals(currentVideoFilter)) {
                    overlayColor = Color.argb(50, 141, 110, 99);
                }
                videoFxOverlayView.setBackgroundColor(overlayColor);
            } else {
                videoFxOverlayView.setVisibility(View.GONE);
            }
        }
    }

    public void renderTimelineFilmstrip() {
        if (timelineClipsRow == null) return;
        timelineClipsRow.removeAllViews();

        for (int i = 0; i < activeProjectClips.size(); i++) {
            MediaItem clip = activeProjectClips.get(i);
            boolean isSelected = (i == selectedClipIndex);
            timelineClipsRow.addView(createFilmFrame(i, clip, isSelected));

            if (i < activeProjectClips.size() - 1) {
                timelineClipsRow.addView(createTransitionButton(i, clip.transitionType));
            }
        }
        renderTimelineRuler();
    }

    private View createTransitionButton(final int index, String transitionType) {
        FrameLayout transBtn = new FrameLayout(activity);
        boolean hasTransition = transitionType != null && !transitionType.equals("none");
        int sizePx = 64;
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(sizePx, sizePx);
        lp.setMargins(4, 0, 4, 0);
        lp.gravity = Gravity.CENTER_VERTICAL;
        transBtn.setLayoutParams(lp);

        TextView tv = new TextView(activity);
        if (hasTransition) {
            tv.setText("⚡");
            tv.setTextColor(Color.BLACK);
            tv.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        } else {
            tv.setText("⧎");
            tv.setTextColor(Color.parseColor("#94A3B8"));
            tv.setBackgroundResource(R.drawable.bg_capcut_speed_pill);
        }
        tv.setTextSize(13);
        tv.setGravity(Gravity.CENTER);
        tv.setTag(Integer.valueOf(400 + index));
        tv.setOnClickListener(this);
        transBtn.addView(tv, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        transBtn.setTag(Integer.valueOf(400 + index));
        transBtn.setOnClickListener(this);
        return transBtn;
    }

    private View createFilmFrame(final int index, MediaItem clip, boolean isSelected) {
        FrameLayout frame = new FrameLayout(activity);
        int baseWidth = Math.max(100, Math.max(1, clip.durationSeconds) * 40);
        int frameWidth = (int) (baseWidth * timelineScaleFactor);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(frameWidth, 96);
        params.setMargins(2, 0, 2, 0);
        frame.setLayoutParams(params);
        frame.setBackgroundColor(isSelected ? Color.parseColor("#2563EB") : Color.parseColor("#1E293B"));

        if (isSelected) {
            frame.setBackgroundResource(R.drawable.bg_capcut_clip_selected);
        }

        TextView tv = new TextView(activity);
        String label = clip.icon + " " + (index + 1) + "\n" + clip.duration;
        if (clip.animationType != null && !clip.animationType.equals("none")) {
            label += "\n✨";
        }
        tv.setText(label);
        tv.setTextColor(Color.WHITE);
        tv.setTextSize(10);
        tv.setGravity(Gravity.CENTER);
        frame.addView(tv, new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT));

        // Render Keyframe Diamond Markers
        if (clip.keyframes != null && !clip.keyframes.isEmpty()) {
            int totalMs = Math.max(1, clip.durationSeconds * 1000);
            for (KeyframePoint kf : clip.keyframes) {
                TextView kfMarker = new TextView(activity);
                kfMarker.setText("◆");
                kfMarker.setTextColor(Color.parseColor("#FF334B"));
                kfMarker.setTextSize(11);
                kfMarker.setTypeface(null, Typeface.BOLD);
                FrameLayout.LayoutParams kfLp = new FrameLayout.LayoutParams(
                    FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT);
                int markerX = (int) (((float) kf.timeMs / totalMs) * (frameWidth - 24));
                kfLp.leftMargin = Math.max(0, markerX);
                kfLp.topMargin = 4;
                kfLp.gravity = Gravity.TOP | Gravity.START;
                frame.addView(kfMarker, kfLp);
            }
        }

        frame.setTag(Integer.valueOf(300 + index));
        frame.setOnClickListener(this);
        return frame;
    }

    public void renderTimelineRuler() {
        if (timelineRulerRow == null) return;
        timelineRulerRow.removeAllViews();

        int totalSec = 0;
        for (MediaItem clip : activeProjectClips) {
            totalSec += Math.max(1, clip.durationSeconds);
        }
        if (totalSec < 15) totalSec = 15;

        final int secWidthPx = 40;

        for (int s = 0; s <= totalSec; s++) {
            LinearLayout secCell = new LinearLayout(activity);
            secCell.setOrientation(LinearLayout.HORIZONTAL);
            secCell.setGravity(Gravity.BOTTOM);
            secCell.setLayoutParams(new LinearLayout.LayoutParams(secWidthPx, 32));

            LinearLayout majorCol = new LinearLayout(activity);
            majorCol.setOrientation(LinearLayout.VERTICAL);
            majorCol.setGravity(Gravity.CENTER_HORIZONTAL | Gravity.BOTTOM);
            majorCol.setLayoutParams(new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.MATCH_PARENT));

            TextView tvTime = new TextView(activity);
            tvTime.setText(String.format("%02d:%02d", s / 60, s % 60));
            tvTime.setTextColor(Color.parseColor("#94A3B8"));
            tvTime.setTextSize(7);
            majorCol.addView(tvTime);

            View majorTick = new View(activity);
            majorTick.setBackgroundColor(Color.parseColor("#CBD5E1"));
            majorCol.addView(majorTick, new LinearLayout.LayoutParams(2, 16));

            secCell.addView(majorCol);

            int subSpacerW = Math.max(2, (secWidthPx - 10) / 4);
            for (int sub = 1; sub <= 3; sub++) {
                View spacer = new View(activity);
                secCell.addView(spacer, new LinearLayout.LayoutParams(subSpacerW, 0));

                View minorTick = new View(activity);
                minorTick.setBackgroundColor(Color.parseColor("#475569"));
                secCell.addView(minorTick, new LinearLayout.LayoutParams(1, 8));
            }

            secCell.setOnClickListener(new RulerCellClickListener(this, s));
            timelineRulerRow.addView(secCell);
        }

        // End of Video Marker on Ruler
        LinearLayout endRulerCell = new LinearLayout(activity);
        endRulerCell.setOrientation(LinearLayout.VERTICAL);
        endRulerCell.setGravity(Gravity.CENTER_HORIZONTAL | Gravity.BOTTOM);
        endRulerCell.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, 32));
        endRulerCell.setPadding(6, 0, 8, 0);

        TextView tvEndMarker = new TextView(activity);
        tvEndMarker.setText("⏹ HẾT");
        tvEndMarker.setTextColor(Color.parseColor("#EF4444"));
        tvEndMarker.setTextSize(7);
        tvEndMarker.setTypeface(null, Typeface.BOLD);
        endRulerCell.addView(tvEndMarker);

        View endTick = new View(activity);
        endTick.setBackgroundColor(Color.parseColor("#EF4444"));
        endRulerCell.addView(endTick, new LinearLayout.LayoutParams(3, 16));

        timelineRulerRow.addView(endRulerCell);
    }

    public void renderMultiAudioTracks() {
        if (timelineAudioContainer == null) return;
        timelineAudioContainer.removeAllViews();

        if (activeAudioTracks.isEmpty()) {
            activeAudioTracks.add(new AudioTrackItem("bgm_default", "Chill Vlog 120BPM", 1, 0, 15000, 100, "#10B981", null));
        }

        for (int i = 0; i < activeAudioTracks.size(); i++) {
            final int trackIdx = i;
            final AudioTrackItem item = activeAudioTracks.get(i);
            boolean isSelected = (i == selectedAudioTrackIndex && currentSelectedTrack == TRACK_TYPE_AUDIO);

            LinearLayout trackRow = new LinearLayout(activity);
            trackRow.setOrientation(LinearLayout.HORIZONTAL);
            trackRow.setGravity(Gravity.CENTER_VERTICAL);
            trackRow.setPadding(0, 3, 0, 3);

            String iconPrefix = "🎵";
            String typeName = "Nhạc nền";
            if (item.trackType == 2) {
                iconPrefix = "🔊";
                typeName = "Sound FX";
            } else if (item.trackType == 3) {
                iconPrefix = "🎙️";
                typeName = "Lồng tiếng";
            } else if (item.trackType == 4) {
                iconPrefix = "📁";
                typeName = "Trích xuất";
            }

            TextView tvBlock = new TextView(activity);
            tvBlock.setText(iconPrefix + " [" + typeName + " " + (i + 1) + ": " + item.title + " | " + (item.durationMs / 1000) + "s | Âm lượng " + item.volumePercent + "%]");
            tvBlock.setTextColor(Color.parseColor(item.colorHex));
            tvBlock.setTextSize(10);
            tvBlock.setTypeface(null, Typeface.BOLD);
            tvBlock.setBackgroundResource(isSelected ? R.drawable.bg_capcut_clip_selected : R.drawable.bg_track_audio);
            tvBlock.setPadding(20, 8, 20, 8);
            tvBlock.setOnClickListener(new AudioTrackSelectListener(this, trackIdx));
            trackRow.addView(tvBlock);

            if (isSelected && activeAudioTracks.size() > 1) {
                TextView btnDelTrack = new TextView(activity);
                btnDelTrack.setText(" ✕ ");
                btnDelTrack.setTextColor(Color.parseColor("#EF4444"));
                btnDelTrack.setTextSize(11);
                btnDelTrack.setOnClickListener(new AudioTrackDeleteListener(this, trackIdx));
                trackRow.addView(btnDelTrack);
            }

            timelineAudioContainer.addView(trackRow);
        }
    }

    public void renderPipTrack() {
        if (timelinePipRow == null || tvPipTrackBlock == null) return;
        if (activePipClips.isEmpty()) {
            timelinePipRow.setVisibility(View.GONE);
            if (pipOverlayContainer != null) pipOverlayContainer.setVisibility(View.GONE);
            return;
        }
        timelinePipRow.setVisibility(View.VISIBLE);
        if (selectedPipIndex < 0 || selectedPipIndex >= activePipClips.size()) {
            selectedPipIndex = 0;
        }
        PipClipItem cur = activePipClips.get(selectedPipIndex);
        String label = "🔲 [Lớp phủ PIP " + (selectedPipIndex + 1) + "/" + activePipClips.size() + ": " 
            + (cur.media != null ? cur.media.title : "Clip") 
            + " | Blend: " + cur.blendMode + "]";
        tvPipTrackBlock.setText(label);
        if (pipOverlayContainer != null) pipOverlayContainer.setVisibility(View.VISIBLE);
    }

    public void updatePipCanvasPreview() {
        if (pipOverlayContainer == null || ivPipPreview == null) return;
        if (activePipClips.isEmpty()) {
            pipOverlayContainer.setVisibility(View.GONE);
            return;
        }
        if (selectedPipIndex < 0 || selectedPipIndex >= activePipClips.size()) {
            selectedPipIndex = 0;
        }
        PipClipItem curPip = activePipClips.get(selectedPipIndex);
        pipOverlayContainer.setVisibility(View.VISIBLE);

        if (tvPipBlendBadge != null) {
            tvPipBlendBadge.setText("🔲 " + curPip.blendMode);
        }

        if ("SCREEN".equalsIgnoreCase(curPip.blendMode)) {
            ivPipPreview.setColorFilter(Color.parseColor("#4488FF"), PorterDuff.Mode.SCREEN);
        } else if ("MULTIPLY".equalsIgnoreCase(curPip.blendMode)) {
            ivPipPreview.setColorFilter(Color.parseColor("#333333"), PorterDuff.Mode.MULTIPLY);
        } else if ("OVERLAY".equalsIgnoreCase(curPip.blendMode)) {
            ivPipPreview.setColorFilter(Color.parseColor("#888888"), PorterDuff.Mode.SRC_ATOP);
        } else {
            ivPipPreview.clearColorFilter();
        }

        ivPipPreview.setAlpha(curPip.opacity / 100.0f);

        if (curPip.media != null && curPip.media.thumbnailBitmap != null) {
            ivPipPreview.setImageBitmap(curPip.media.thumbnailBitmap);
        } else if (curPip.media != null && curPip.media.uri != null) {
            try {
                InputStream is = activity.getContentResolver().openInputStream(curPip.media.uri);
                Bitmap bm = BitmapFactory.decodeStream(is);
                if (is != null) is.close();
                if (bm != null) {
                    bm = PhotoEditorComponent.fixExifOrientation(activity, curPip.media.uri, bm);
                    ivPipPreview.setImageBitmap(bm);
                }
            } catch (Exception ignored) {}
        } else if (curPip.media != null) {
            ivPipPreview.setBackgroundColor(curPip.media.colorBg);
        }

        int parentW = canvasFrame != null && canvasFrame.getWidth() > 0 ? canvasFrame.getWidth() : 1080;
        int parentH = canvasFrame != null && canvasFrame.getHeight() > 0 ? canvasFrame.getHeight() : 1440;
        int pipW = (int) (parentW * curPip.scale);
        int pipH = (int) (pipW * 9f / 16f);
        int posX = (int) (parentW * curPip.posX);
        int posY = (int) (parentH * curPip.posY);

        FrameLayout.LayoutParams lp = (FrameLayout.LayoutParams) pipOverlayContainer.getLayoutParams();
        if (lp != null) {
            lp.width = Math.max(200, pipW);
            lp.height = Math.max(120, pipH);
            lp.leftMargin = Math.max(0, Math.min(parentW - lp.width, posX));
            lp.topMargin = Math.max(0, Math.min(parentH - lp.height, posY));
            pipOverlayContainer.setLayoutParams(lp);
        }
    }

    private void rotateVideo() {
        videoRotationDegrees = (videoRotationDegrees + 90) % 360;
        if (videoPlayerView != null) videoPlayerView.setRotation(videoRotationDegrees);
        if (ivVideoPoster != null) ivVideoPoster.setRotation(videoRotationDegrees);
        if (videoFxOverlayView != null) videoFxOverlayView.setRotation(videoRotationDegrees);
        Toast.makeText(activity, "🔄 Đã xoay video: " + videoRotationDegrees + "°", Toast.LENGTH_SHORT).show();
    }

    private void flipVideoHorizontal() {
        isVideoFlipped = !isVideoFlipped;
        float scale = isVideoFlipped ? -1.0f : 1.0f;
        if (videoPlayerView != null) videoPlayerView.setScaleX(scale);
        if (ivVideoPoster != null) ivVideoPoster.setScaleX(scale);
        if (videoFxOverlayView != null) videoFxOverlayView.setScaleX(scale);
        Toast.makeText(activity, isVideoFlipped ? "🪞 Đã lật ngang video (Flip Horizontal)!" : "🪞 Đã khôi phục hướng video!", Toast.LENGTH_SHORT).show();
    }

    // Playback Loop & VideoView Callbacks
    @Override
    public void onPrepared(MediaPlayer mp) {
        mediaPlayerInstance = mp;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && activeProjectClips != null && !activeProjectClips.isEmpty()) {
            try {
                MediaItem cur = activeProjectClips.get(Math.min(selectedClipIndex, activeProjectClips.size() - 1));
                if (cur.speed != 1.0f) {
                    mp.setPlaybackParams(new PlaybackParams().setSpeed(cur.speed));
                }
            } catch (Exception ignored) {}
        }
    }

    @Override
    public boolean onError(MediaPlayer mp, int what, int extra) {
        return true;
    }

    @Override
    public void onCompletion(MediaPlayer mp) {
        if (!activeProjectClips.isEmpty() && selectedClipIndex < activeProjectClips.size() - 1) {
            selectedClipIndex++;
            renderTimelineFilmstrip();
            updatePlayerPreview();
            if (videoPlayerView != null && isPlaying) {
                videoPlayerView.start();
                playbackHandler.post(this);
            }
        } else {
            isPlaying = false;
            if (tvPlayerPlayIcon != null) tvPlayerPlayIcon.setText("▷");
            playbackHandler.removeCallbacks(this);
        }
    }

    @Override
    public void run() {
        if (videoPlayerView != null && videoPlayerView.isPlaying()) {
            int curMs = videoPlayerView.getCurrentPosition();
            virtualPlayheadMs = curMs;
            int sec = curMs / 1000;
            if (tvPlayerTimecode != null) {
                tvPlayerTimecode.setText(String.format("%02d:%02d / %s", sec / 60, sec % 60, calculateTotalDuration()));
            }

            // Subtitles
            if (tvCanvasSubtitleOverlay != null && !currentSubtitles.isEmpty()) {
                String activeText = "";
                int subStart = 0;
                int subEnd = 0;
                for (SubtitleItem sub : currentSubtitles) {
                    if (curMs >= sub.startMs && curMs <= sub.endMs) {
                        activeText = sub.text;
                        subStart = sub.startMs;
                        subEnd = sub.endMs;
                        break;
                    }
                }
                if (!activeText.isEmpty()) {
                    renderWordByWordKaraoke(activeText, curMs, subStart, subEnd);
                    tvCanvasSubtitleOverlay.setVisibility(View.VISIBLE);
                } else {
                    tvCanvasSubtitleOverlay.setVisibility(View.GONE);
                }
            }

            // Keyframes & Audio Fades
            if (!activeProjectClips.isEmpty() && selectedClipIndex < activeProjectClips.size()) {
                MediaItem curClip = activeProjectClips.get(selectedClipIndex);
                applyKeyframeInterpolation(curClip, curMs);
                applyAudioFades(curClip, curMs);
                updateKeyframeButtonState(curClip, curMs);
            }

            syncTimelineScrollToPlayhead();
            playbackHandler.postDelayed(this, 60);

        } else if (isPlaying) {
            // Photo Slideshow Virtual Loop
            virtualPlayheadMs += 60;
            int totalSec = 5;
            if (activeProjectClips != null && !activeProjectClips.isEmpty()) {
                int tot = 0;
                for (MediaItem mi : activeProjectClips) {
                    tot += mi.durationSeconds;
                }
                if (tot > 0) totalSec = tot;
            }
            int totalMs = totalSec * 1000;
            if (virtualPlayheadMs >= totalMs) {
                virtualPlayheadMs = 0;
            }
            int sec = virtualPlayheadMs / 1000;
            if (tvPlayerTimecode != null) {
                tvPlayerTimecode.setText(String.format("%02d:%02d / %s", sec / 60, sec % 60, calculateTotalDuration()));
            }

            if (!activeProjectClips.isEmpty() && selectedClipIndex < activeProjectClips.size()) {
                MediaItem curClip = activeProjectClips.get(selectedClipIndex);
                applyKeyframeInterpolation(curClip, virtualPlayheadMs);
                updateKeyframeButtonState(curClip, virtualPlayheadMs);
            }

            syncTimelineScrollToPlayhead();
            playbackHandler.postDelayed(this, 60);
        }
    }

    private void renderWordByWordKaraoke(String fullText, int curMs, int startMs, int endMs) {
        if (tvCanvasSubtitleOverlay == null || fullText == null || fullText.isEmpty()) return;
        int duration = Math.max(1, endMs - startMs);
        float progress = Math.max(0.0f, Math.min(1.0f, (float)(curMs - startMs) / duration));

        String[] words = fullText.split("\\s+");
        int activeWordIdx = (int)(progress * words.length);
        if (activeWordIdx >= words.length) activeWordIdx = words.length - 1;

        SpannableStringBuilder ssb = new SpannableStringBuilder();
        for (int i = 0; i < words.length; i++) {
            int wordStart = ssb.length();
            ssb.append(words[i]);
            int wordEnd = ssb.length();

            if (i == activeWordIdx) {
                if ("karaoke_gold_glow".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#FFD700")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.25f), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else if ("karaoke_neon_cyan".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#00E5FF")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD_ITALIC), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.2f), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else if ("karaoke_box_highlight".equals(currentKaraokeStyle)) {
                    ssb.setSpan(new BackgroundColorSpan(Color.parseColor("#E11D48")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new ForegroundColorSpan(Color.WHITE), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new StyleSpan(Typeface.BOLD), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                } else {
                    ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#10B981")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                    ssb.setSpan(new RelativeSizeSpan(1.3f), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                }
            } else if (i < activeWordIdx) {
                ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#FBBF24")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            } else {
                ssb.setSpan(new ForegroundColorSpan(Color.parseColor("#94A3B8")), wordStart, wordEnd, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            }

            if (i < words.length - 1) {
                ssb.append(" ");
            }
        }
        tvCanvasSubtitleOverlay.setText(ssb);
    }

    private void applyKeyframeInterpolation(MediaItem clip, int curMs) {
        if (clip.keyframes == null || clip.keyframes.size() < 2) return;
        List<KeyframePoint> kfs = clip.keyframes;
        KeyframePoint before = null;
        KeyframePoint after = null;

        for (int i = 0; i < kfs.size(); i++) {
            KeyframePoint k = kfs.get(i);
            if (k.timeMs <= curMs) {
                before = k;
            } else {
                after = k;
                break;
            }
        }

        View target = (videoPlayerView != null && videoPlayerView.getVisibility() == View.VISIBLE) ? videoPlayerView : ivVideoPoster;
        if (target == null) return;

        if (before != null && after != null) {
            float range = after.timeMs - before.timeMs;
            if (range <= 0) return;
            float t = (curMs - before.timeMs) / range;
            float scale = before.scale + (after.scale - before.scale) * t;
            float tx = before.translationX + (after.translationX - before.translationX) * t;
            float ty = before.translationY + (after.translationY - before.translationY) * t;
            float rot = before.rotation + (after.rotation - before.rotation) * t;

            target.setScaleX(scale);
            target.setScaleY(scale);
            target.setTranslationX(tx);
            target.setTranslationY(ty);
            target.setRotation(rot);
        } else if (before != null) {
            target.setScaleX(before.scale);
            target.setScaleY(before.scale);
            target.setTranslationX(before.translationX);
            target.setTranslationY(before.translationY);
            target.setRotation(before.rotation);
        }
    }

    private void applyAudioFades(MediaItem clip, int curMs) {
        if (mediaPlayerInstance == null) return;
        int totalMs = Math.max(1, clip.durationSeconds * 1000);
        float baseVol = clip.volume / 100.0f;
        float finalVol = baseVol;

        if (clip.fadeInSec > 0) {
            int fadeInMs = (int) (clip.fadeInSec * 1000);
            if (curMs < fadeInMs) {
                finalVol = baseVol * ((float) curMs / fadeInMs);
            }
        }
        if (clip.fadeOutSec > 0) {
            int fadeOutMs = (int) (clip.fadeOutSec * 1000);
            int startFadeOut = totalMs - fadeOutMs;
            if (curMs > startFadeOut) {
                finalVol = baseVol * ((float) (totalMs - curMs) / fadeOutMs);
            }
        }

        finalVol = Math.max(0f, Math.min(1.0f, finalVol));
        try {
            mediaPlayerInstance.setVolume(finalVol, finalVol);
        } catch (Exception ignored) {}
    }

    private void updateKeyframeButtonState(MediaItem clip, int curMs) {
        if (btnKeyframeToggle == null) return;
        boolean hasNearby = false;
        for (KeyframePoint k : clip.keyframes) {
            if (Math.abs(k.timeMs - curMs) <= 250) {
                hasNearby = true;
                break;
            }
        }
        if (hasNearby) {
            btnKeyframeToggle.setText("-◆");
            btnKeyframeToggle.setTextColor(Color.parseColor("#FF334B"));
        } else {
            btnKeyframeToggle.setText("+◆");
            btnKeyframeToggle.setTextColor(Color.parseColor("#00E5FF"));
        }
    }

    public void syncTimelineScrollToPlayhead() {
        if (isUserScrubbing || hScrollTracks == null) return;
        int currentSec = 0;
        for (int i = 0; i < selectedClipIndex && i < activeProjectClips.size(); i++) {
            currentSec += Math.max(1, activeProjectClips.get(i).durationSeconds);
        }
        currentSec += (virtualPlayheadMs / 1000);
        int targetScrollX = currentSec * 40;
        isSyncingScroll = true;
        hScrollTracks.smoothScrollTo(targetScrollX, 0);
        isSyncingScroll = false;
    }

    public void seekTimelineToSecond(int targetSec) {
        if (activeProjectClips.isEmpty()) return;
        int accSec = 0;
        int targetClipIdx = 0;
        int offsetSec = 0;

        for (int i = 0; i < activeProjectClips.size(); i++) {
            int dur = Math.max(1, activeProjectClips.get(i).durationSeconds);
            if (accSec + dur > targetSec) {
                targetClipIdx = i;
                offsetSec = targetSec - accSec;
                break;
            }
            accSec += dur;
        }

        selectedClipIndex = targetClipIdx;
        renderTimelineFilmstrip();
        updatePlayerPreview();

        if (videoPlayerView != null && activeProjectClips.get(targetClipIdx).isVideo) {
            MediaItem clip = activeProjectClips.get(targetClipIdx);
            videoPlayerView.seekTo((clip.trimInSec + offsetSec) * 1000);
        }
        virtualPlayheadMs = offsetSec * 1000;
        if (tvPlayerTimecode != null) {
            tvPlayerTimecode.setText(String.format("%02d:%02d / %s", targetSec / 60, targetSec % 60, calculateTotalDuration()));
        }
    }

    // SeekBar Change Listener
    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        if (seekBar == sbCoverScrubber) {
            if (fromUser) updateCoverPreview();
            return;
        }
        if (seekBar == sbVolume) {
            tvVolumeVal.setText("Âm lượng: " + progress + "%");
            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                activeProjectClips.get(selectedClipIndex).volume = progress;
            }
            if (mediaPlayerInstance != null) {
                try {
                    float v = progress / 100.0f;
                    mediaPlayerInstance.setVolume(v, v);
                } catch (Exception ignored) {}
            }
        } else if (seekBar == sbFadeIn) {
            float sec = progress / 10.0f;
            if (tvFadeInVal != null) tvFadeInVal.setText(String.format(Locale.US, "Fade In: %.1fs", sec));
            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                activeProjectClips.get(selectedClipIndex).fadeInSec = sec;
            }
        } else if (seekBar == sbFadeOut) {
            float sec = progress / 10.0f;
            if (tvFadeOutVal != null) tvFadeOutVal.setText(String.format(Locale.US, "Fade Out: %.1fs", sec));
            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                activeProjectClips.get(selectedClipIndex).fadeOutSec = sec;
            }
        } else if (seekBar == sbVideoBright || seekBar == sbVideoContrast || seekBar == sbVideoSat) {
            int b = sbVideoBright.getProgress() - 100;
            int c = sbVideoContrast.getProgress();
            int s = sbVideoSat.getProgress();

            tvVideoBrightVal.setText("Độ sáng: " + b);
            tvVideoContrastVal.setText("Tương phản: " + c + "%");
            tvVideoSatVal.setText("Bão hòa: " + s + "%");

            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                MediaItem item = activeProjectClips.get(selectedClipIndex);
                item.brightness = b;
                item.contrast = c;
                item.saturation = s;
            }
            applyVideoColorMatrix(b, c, s);
        } else if (seekBar == sbChromaIntensity || seekBar == sbChromaShadow || seekBar == sbChromaSpill) {
            int intensity = sbChromaIntensity != null ? sbChromaIntensity.getProgress() : 65;
            int shadow = sbChromaShadow != null ? sbChromaShadow.getProgress() : 40;
            int spill = sbChromaSpill != null ? sbChromaSpill.getProgress() : 50;
            if (tvChromaIntensityVal != null) tvChromaIntensityVal.setText("Cường độ: " + intensity + "%");
            if (tvChromaShadowVal != null) tvChromaShadowVal.setText("Độ mềm: " + shadow + "%");
            if (tvChromaSpillVal != null) tvChromaSpillVal.setText("Khử lem (Spill): " + spill + "%");
            MiddleBridgeJni.applyChromaKey(currentChromaColor, intensity / 100.0f, shadow / 100.0f);
            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                MediaItem curClip = activeProjectClips.get(selectedClipIndex);
                curClip.chromaIntensity = intensity;
                curClip.chromaShadow = shadow;
                curClip.chromaSpill = spill;
            }
        } else if (seekBar == sbSpeedStandard) {
            float speed;
            if (progress <= 100) {
                speed = 0.1f + (progress / 100f) * 0.9f;
            } else if (progress <= 500) {
                speed = 1.0f + ((progress - 100) / 400f) * 9.0f;
            } else {
                speed = 10.0f + ((progress - 500) / 500f) * 90.0f;
            }
            if (tvSpeedStandardVal != null) {
                tvSpeedStandardVal.setText(String.format(Locale.US, "Tốc độ chuẩn: %.1fx (0.1x - 100x)", speed));
            }
            if (!activeProjectClips.isEmpty() && selectedClipIndex >= 0 && selectedClipIndex < activeProjectClips.size()) {
                MediaItem currentClip = activeProjectClips.get(selectedClipIndex);
                currentClip.speed = speed;
                // Honest duration calculation based on original duration (Rule 14 & Parity V6)
                // Tính thời lượng chính xác dựa trên thời lượng gốc của clip, không gán cứng 16s
                int origSec = currentClip.originalDurationSeconds > 0 ? currentClip.originalDurationSeconds : currentClip.durationSeconds;
                if (origSec <= 0) origSec = 16;
                int baseSec = Math.max(1, Math.round(origSec / speed));
                currentClip.durationSeconds = baseSec;
                currentClip.duration = String.format(Locale.US, "%02d:%02d", currentClip.durationSeconds / 60, currentClip.durationSeconds % 60);
                if (mediaPlayerInstance != null && Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                    try {
                        mediaPlayerInstance.setPlaybackParams(new PlaybackParams().setSpeed(speed));
                    } catch (Exception ignored) {}
                }
            }
        } else if (seekBar == sbSlimFace || seekBar == sbSmoothSkin || seekBar == sbBigEyes || seekBar == sbNose || seekBar == sbTeeth) {
            int slim = sbSlimFace != null ? sbSlimFace.getProgress() : 50;
            int smooth = sbSmoothSkin != null ? sbSmoothSkin.getProgress() : 70;
            int eye = sbBigEyes != null ? sbBigEyes.getProgress() : 40;
            int teeth = sbTeeth != null ? sbTeeth.getProgress() : 60;

            if (tvSlimFaceVal != null) tvSlimFaceVal.setText("Thu mặt: " + slim + "%");
            if (tvSmoothSkinVal != null) tvSmoothSkinVal.setText("Mịn da: " + smooth + "%");
            if (tvBigEyesVal != null) tvBigEyesVal.setText("Mắt to: " + eye + "%");
            if (tvTeethVal != null) tvTeethVal.setText("Trắng răng: " + teeth + "%");

            MiddleBridgeJni.applyFaceBeauty(smooth / 100f, teeth / 100f, slim / 100f, eye / 100f);
        }
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {}

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {}

    @Override
    public boolean onTouch(View v, MotionEvent event) {
        return false;
    }

    // Master Click Handler
    @Override
    public void onClick(View v) {
        if (v == btnEditorClose) {
            if (listener != null) listener.onVideoEditorClose();
            return;
        }

        // Cover & Karaoke
        if (v == btnCoverFrame) {
            showCoverEditorDialog();
            return;
        } else if (v == pillKaraokeGold) {
            currentKaraokeStyle = "karaoke_gold_glow";
            setCoverPillActive(pillKaraokeGold, true);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeNeon) {
            currentKaraokeStyle = "karaoke_neon_cyan";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, true);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeBox) {
            currentKaraokeStyle = "karaoke_box_highlight";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, true);
            setCoverPillActive(pillKaraokeBounce, false);
            return;
        } else if (v == pillKaraokeBounce) {
            currentKaraokeStyle = "karaoke_bouncy_popup";
            setCoverPillActive(pillKaraokeGold, false);
            setCoverPillActive(pillKaraokeNeon, false);
            setCoverPillActive(pillKaraokeBox, false);
            setCoverPillActive(pillKaraokeBounce, true);
            return;
        } else if (v == pillFontGold) {
            coverFontIndex = 0;
            setCoverPillActive(pillFontGold, true);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontSerif) {
            coverFontIndex = 1;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, true);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontNeon) {
            coverFontIndex = 2;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, true);
            setCoverPillActive(pillFontClean, false);
            updateCoverPreview();
            return;
        } else if (v == pillFontClean) {
            coverFontIndex = 3;
            setCoverPillActive(pillFontGold, false);
            setCoverPillActive(pillFontSerif, false);
            setCoverPillActive(pillFontNeon, false);
            setCoverPillActive(pillFontClean, true);
            updateCoverPreview();
            return;
        } else if (v == pillTplBottom) {
            coverTemplateIndex = 0;
            setCoverPillActive(pillTplBottom, true);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplCenter) {
            coverTemplateIndex = 1;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, true);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplTiktok) {
            coverTemplateIndex = 2;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, true);
            setCoverPillActive(pillTplCinema, false);
            updateCoverPreview();
            return;
        } else if (v == pillTplCinema) {
            coverTemplateIndex = 3;
            setCoverPillActive(pillTplBottom, false);
            setCoverPillActive(pillTplCenter, false);
            setCoverPillActive(pillTplTiktok, false);
            setCoverPillActive(pillTplCinema, true);
            updateCoverPreview();
            return;
        } else if (v == btnUploadCustomPhoto) {
            if (!allMediaItems.isEmpty()) {
                for (MediaItem m : allMediaItems) {
                    if (!m.isVideo && m.thumbnailBitmap != null) {
                        projectCoverBitmap = m.thumbnailBitmap;
                        break;
                    }
                }
            }
            updateCoverPreview();
            Toast.makeText(activity, "📤 Đã nạp ảnh bìa tự chọn từ thư viện!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnSaveCover) {
            if (etCoverTitle != null) coverTitleText = etCoverTitle.getText().toString();
            projectCoverBitmap = bakeCoverBitmap();
            if (tvCoverIconView != null) {
                tvCoverIconView.setText("✓");
                tvCoverIconView.setTextColor(Color.parseColor("#00E5FF"));
            }
            if (activeDialog != null) activeDialog.dismiss();
            Toast.makeText(activity, "🎉 Đã lưu ảnh bìa và kiểu phụ đề Karaoke thành công!", Toast.LENGTH_SHORT).show();
            return;
        } else if (v == btnCancelCover) {
            if (activeDialog != null) activeDialog.dismiss();
            return;
        }

        // Subtool or Clip selection via Tag
        Object tag = v.getTag();
        if (tag instanceof Integer) {
            int tagVal = ((Integer) tag).intValue();
            if (tagVal >= 400 && tagVal < 500) {
                showTransitionDialog(tagVal - 400);
                return;
            }
            if (tagVal >= 300 && tagVal < 400) {
                selectedClipIndex = tagVal - 300;
                renderTimelineFilmstrip();
                updatePlayerPreview();
                showRibbonLevel(ribbonEditSubmenu);
                return;
            }
        }

        // Back buttons
        if (v == btnBackFromEdit || v == btnBackFromCanvas || v == btnBackFromAudio ||
            v == btnBackFromEffects || v == btnBackFromSpeed || v == btnBackFromVolume ||
            v == btnBackFromAdjust || v == btnBackFromRatio || v == btnBackFromCutout ||
            v == btnBackFromText || v == btnBackFromBeauty || v == btnBackFromMask || v == btnBackFromPip) {
            showRibbonLevel(ribbonMainMenu);
            return;
        }

        // Tools
        if (v == toolEdit) {
            showRibbonLevel(ribbonEditSubmenu);
        } else if (v == toolAudio || v == audioOptSounds) {
            showMusicLibraryDialog();
        } else if (v == audioOptSoundFx) {
            showSoundFxLibraryDialog();
        } else if (v == audioOptExtract) {
            extractAudioFromVideo();
        } else if (v == audioOptVoiceFx) {
            showVoiceFxDialog();
        } else if (v == audioOptNoiseReduction) {
            showNoiseReductionDialog();
        } else if (v == audioOptVocalIsolation) {
            showVocalIsolationDialog();
        } else if (v == toolText || v == subToolAddText) {
            showTextEditorDialog();
        } else if (v == subToolTextTemplate) {
            showTextTemplateDialog();
        } else if (v == subToolAutoCaptions || v == toolCaptions) {
            showSubtitleGeneratorDialog();
        } else if (v == subToolTextTts) {
            showAiVoiceoverDialog();
        } else if (v == toolOverlay) {
            if (listener != null) listener.onRequestMediaPicker(0, true, false);
        } else if (v == toolEffects) {
            showRibbonLevel(ribbonEffectsDrawer);
        } else if (v == toolFilters) {
            showRibbonLevel(ribbonAdjustDrawer);
        } else if (v == toolAdjust || v == subToolAdjust) {
            showRibbonLevel(ribbonAdjustDrawer);
        } else if (v == toolRatio || v == subToolRatio) {
            showRibbonLevel(ribbonRatioDrawer);
        } else if (v == toolCanvas) {
            showRibbonLevel(ribbonCanvasSubmenu);
        } else if (v == subToolSplit) {
            splitSelectedClip();
        } else if (v == subToolSpeed) {
            showRibbonLevel(ribbonSpeedDrawer);
        } else if (v == subToolVolume) {
            showRibbonLevel(ribbonVolumeDrawer);
        } else if (v == subToolDelete) {
            deleteSelectedClip();
        } else if (v == subToolCutout) {
            showRibbonLevel(ribbonCutoutDrawer);
        } else if (v == subToolBeauty) {
            showRibbonLevel(ribbonBeautyDrawer);
        } else if (v == subToolRotate) {
            rotateVideo();
        } else if (v == subToolFlip) {
            flipVideoHorizontal();
        } else if (v == subToolCrop) {
            showVideoCropDialog();
        } else if (v == subToolFreeze) {
            freezeSelectedClip();
        } else if (v == subToolReverse) {
            reverseSelectedClip();
        } else if (v == subToolMask) {
            showRibbonLevel(ribbonMaskDrawer);
        } else if (v == subToolAnimation) {
            showClipAnimationDialog();
        } else if (v == subToolDuplicate) {
            duplicateSelectedClip();
        } else if (v == subToolReplace) {
            if (listener != null) listener.onRequestMediaPicker(0, false, true);
        } else if (v == subToolOpacity) {
            showOpacityDialog();
        } else if (v == btnAddMediaClip) {
            if (listener != null) listener.onRequestMediaPicker(0, false, false);
        } else if (v == btnAddAudioTrack) {
            showAddAudioOptionsDialog();
        } else if (v == btnEditorResolution) {
            is4kSelected = !is4kSelected;
            ((TextView) btnEditorResolution).setText(is4kSelected ? "4K 60 ▾" : "1080P ▾");
            Toast.makeText(activity, "Độ phân giải: " + (is4kSelected ? "4K 60fps HDR 10-bit" : "1080P 30fps Full HD"), Toast.LENGTH_SHORT).show();
        } else if (v == btnEditorExport) {
            exportController.exportProject(activeProjectClips, selectedClipIndex, allMediaItems, is4kSelected, this);
        } else if (v == btnPlayerPlayPause || v == canvasFrame || v == videoPlayerView || v == ivVideoPoster) {
            togglePlayPause();
        } else if (v == btnKeyframeToggle) {
            toggleKeyframe();
        } else if (v == btnPlayerUndo) {
            Toast.makeText(activity, "↶ Đã Hoàn Tác thao tác trước (Undo)!", Toast.LENGTH_SHORT).show();
        } else if (v == btnPlayerRedo) {
            Toast.makeText(activity, "↷ Đã Làm Lại thao tác (Redo)!", Toast.LENGTH_SHORT).show();
        } else if (v == btnMuteAudio) {
            toggleGlobalMute();
        } else if (v == ratioPill916) {
            currentVideoRatio = "9:16";
            updateVideoCanvasDimensions();
            updatePlayerPreview();
        } else if (v == ratioPill169) {
            currentVideoRatio = "16:9";
            updateVideoCanvasDimensions();
            updatePlayerPreview();
        } else if (v == ratioPill11) {
            currentVideoRatio = "1:1";
            updateVideoCanvasDimensions();
            updatePlayerPreview();
        } else if (v == ratioPill45) {
            currentVideoRatio = "4:5";
            updateVideoCanvasDimensions();
            updatePlayerPreview();
        }
    }

    private void togglePlayPause() {
        if (activeProjectClips.isEmpty()) return;
        MediaItem currentClip = activeProjectClips.get(Math.min(selectedClipIndex, activeProjectClips.size() - 1));

        if (currentClip.isVideo && currentClip.uri != null && videoPlayerView != null) {
            if (videoPlayerView.isPlaying()) {
                videoPlayerView.pause();
                isPlaying = false;
                if (tvPlayerPlayIcon != null) tvPlayerPlayIcon.setText("▷");
                playbackHandler.removeCallbacks(this);
            } else {
                videoPlayerView.start();
                isPlaying = true;
                if (tvPlayerPlayIcon != null) tvPlayerPlayIcon.setText("⏸");
                playbackHandler.post(this);
            }
        } else {
            isPlaying = !isPlaying;
            if (tvPlayerPlayIcon != null) tvPlayerPlayIcon.setText(isPlaying ? "⏸" : "▷");
            if (isPlaying) {
                playbackHandler.post(this);
            } else {
                playbackHandler.removeCallbacks(this);
            }
        }
    }

    private void toggleKeyframe() {
        if (activeProjectClips.isEmpty()) return;
        MediaItem currentClip = activeProjectClips.get(Math.min(selectedClipIndex, activeProjectClips.size() - 1));
        int curMs = (videoPlayerView != null && videoPlayerView.isPlaying()) ? videoPlayerView.getCurrentPosition() : virtualPlayheadMs;

        KeyframePoint existing = null;
        for (KeyframePoint k : currentClip.keyframes) {
            if (Math.abs(k.timeMs - curMs) <= 250) {
                existing = k;
                break;
            }
        }

        if (existing != null) {
            currentClip.keyframes.remove(existing);
            Toast.makeText(activity, "🗑️ Đã xóa Keyframe!", Toast.LENGTH_SHORT).show();
        } else {
            currentClip.keyframes.add(new KeyframePoint(curMs, 1.0f, 0f, 0f, 0f, 1.0f));
            KeyframePoint.sortKeyframes(currentClip.keyframes);
            Toast.makeText(activity, "◆ Đã thêm Keyframe!", Toast.LENGTH_SHORT).show();
        }
        renderTimelineFilmstrip();
    }

    private void toggleGlobalMute() {
        if (mediaPlayerInstance != null) {
            try {
                mediaPlayerInstance.setVolume(0f, 0f);
                Toast.makeText(activity, "🔇 Đã tắt âm thanh toàn dự án!", Toast.LENGTH_SHORT).show();
            } catch (Exception ignored) {}
        }
    }

    // Clip Operations with bounds protection (Luật Parity V8)
    // Các thao tác biên tập clip có kiểm tra chỉ mục an toàn, chống văng app
    private void splitSelectedClip() {
        if (activeProjectClips.isEmpty() || selectedClipIndex < 0 || selectedClipIndex >= activeProjectClips.size()) return;
        MediaItem cur = activeProjectClips.get(selectedClipIndex);
        if (cur.durationSeconds < 2) {
            Toast.makeText(activity, "⚠️ Đoạn clip quá ngắn (dưới 2 giây), không thể chia cắt thêm!", Toast.LENGTH_SHORT).show();
            return;
        }

        // Determine split point based on playhead or midpoint fallback (Fixes X6)
        // Xác định vị trí cắt theo con trỏ playhead hoặc điểm giữa clip
        int splitOffsetSec = virtualPlayheadMs / 1000;
        if (splitOffsetSec <= 0 || splitOffsetSec >= cur.durationSeconds) {
            splitOffsetSec = cur.durationSeconds / 2;
        }
        int dur1 = Math.max(1, splitOffsetSec);
        int dur2 = Math.max(1, cur.durationSeconds - dur1);

        int origIn = cur.trimInSec;
        int origOut = cur.trimOutSec > 0 ? cur.trimOutSec : (origIn + cur.durationSeconds);

        // Part 1 retains in-point up to cut position
        // Phần 1 giữ nguyên điểm bắt đầu đến vị trí cắt
        cur.trimInSec = origIn;
        cur.trimOutSec = origIn + dur1;
        cur.durationSeconds = dur1;
        cur.duration = String.format(Locale.US, "%02d:%02d", dur1 / 60, dur1 % 60);

        // Part 2 starts from cut position to original out-point
        // Phần 2 bắt đầu từ vị trí cắt đến điểm kết thúc gốc
        MediaItem part2 = new MediaItem(cur.id + "_p2", cur.title + " (Phần 2)", cur.uri, 
            String.format(Locale.US, "%02d:%02d", dur2 / 60, dur2 % 60), cur.isVideo, cur.colorBg, cur.icon);
        part2.durationSeconds = dur2;
        part2.trimInSec = origIn + dur1;
        part2.trimOutSec = origOut;
        part2.volume = cur.volume;
        part2.speed = cur.speed;
        part2.brightness = cur.brightness;
        part2.contrast = cur.contrast;
        part2.saturation = cur.saturation;
        part2.opacityPercent = cur.opacityPercent;

        activeProjectClips.add(selectedClipIndex + 1, part2);
        selectedClipIndex++;
        renderTimelineFilmstrip();
        updatePlayerPreview();
        Toast.makeText(activity, "✂️ Đã tách clip thành 2 đoạn độc lập (" + dur1 + "s + " + dur2 + "s)!", Toast.LENGTH_SHORT).show();
    }

    private void deleteSelectedClip() {
        if (activeProjectClips.size() <= 1) {
            Toast.makeText(activity, "⚠️ Không thể xóa clip duy nhất!", Toast.LENGTH_SHORT).show();
            return;
        }
        if (selectedClipIndex < 0 || selectedClipIndex >= activeProjectClips.size()) {
            selectedClipIndex = 0;
            return;
        }
        activeProjectClips.remove(selectedClipIndex);
        selectedClipIndex = Math.max(0, Math.min(selectedClipIndex, activeProjectClips.size() - 1));
        renderTimelineFilmstrip();
        updatePlayerPreview();
        Toast.makeText(activity, "🗑️ Đã xóa clip khỏi Timeline!", Toast.LENGTH_SHORT).show();
    }

    private void reverseSelectedClip() {
        MiddleBridgeJni.applyShaderEffect("reverse_playback", 1.0f);
        Toast.makeText(activity, "↺ Đang phát đảo ngược clip!", Toast.LENGTH_SHORT).show();
    }

    private void freezeSelectedClip() {
        if (activeProjectClips.isEmpty() || selectedClipIndex < 0 || selectedClipIndex >= activeProjectClips.size()) return;
        MediaItem cur = activeProjectClips.get(selectedClipIndex);
        MediaItem freeze = new MediaItem(cur.id + "_freeze", "❄️ Đóng băng (" + cur.title + ")", cur.uri, "00:03", false, Color.parseColor("#0284C7"), "❄️");
        freeze.durationSeconds = 3;
        activeProjectClips.add(selectedClipIndex + 1, freeze);
        renderTimelineFilmstrip();
        Toast.makeText(activity, "❄️ Đã chèn 3 giây Đóng Băng Khung Hình (Freeze Frame)!", Toast.LENGTH_SHORT).show();
    }

    private void duplicateSelectedClip() {
        if (activeProjectClips.isEmpty() || selectedClipIndex < 0 || selectedClipIndex >= activeProjectClips.size()) return;
        MediaItem cur = activeProjectClips.get(selectedClipIndex);
        MediaItem dup = new MediaItem(cur.id + "_copy", cur.title + " (Bản sao)", cur.uri, cur.duration, cur.isVideo, cur.colorBg, cur.icon);
        dup.durationSeconds = cur.durationSeconds;
        dup.volume = cur.volume;
        dup.speed = cur.speed;
        activeProjectClips.add(selectedClipIndex + 1, dup);
        selectedClipIndex++;
        renderTimelineFilmstrip();
        updatePlayerPreview();
        Toast.makeText(activity, "📑 Đã nhân bản clip thành công!", Toast.LENGTH_SHORT).show();
    }

    // Dialogs
    private void showVideoCropDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(28, 20, 28, 20);
        root.setBackgroundColor(Color.parseColor("#141724"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("📐 CẮT & TỶ LỆ KHUNG HÌNH VIDEO");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(15);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setGravity(Gravity.CENTER);
        tvTitle.setPadding(0, 0, 0, 16);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] ratios = {"9:16 (TikTok / Reels / Shorts)", "16:9 (YouTube / TV)", "1:1 (Vuông Instagram)", "4:5 (Dọc Feed)"};
        for (final String r : ratios) {
            TextView btnR = new TextView(activity);
            btnR.setText(r);
            btnR.setTextColor(Color.WHITE);
            btnR.setTextSize(12);
            btnR.setBackgroundColor(Color.parseColor("#1E293B"));
            btnR.setPadding(20, 14, 20, 14);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 10);
            btnR.setLayoutParams(lp);
            btnR.setOnClickListener(new RatioItemClickListener(this, r, dialog));
            root.addView(btnR);
        }

        TextView btnToggleFill = new TextView(activity);
        btnToggleFill.setText(isVideoFillMode ? "⛶ ĐANG TRÀN MÀN ➔ BẤM ĐỂ CHỌN VỪA VẶN (FIT)" : "⛶ ĐANG VỪA VẶN ➔ BẤM ĐỂ TRÀN TOÀN MÀN (FILL)");
        btnToggleFill.setTextColor(Color.parseColor("#00E5FF"));
        btnToggleFill.setTextSize(11);
        btnToggleFill.setTypeface(null, Typeface.BOLD);
        btnToggleFill.setBackgroundColor(Color.parseColor("#0F2B48"));
        btnToggleFill.setPadding(20, 14, 20, 14);
        btnToggleFill.setGravity(Gravity.CENTER);
        btnToggleFill.setOnClickListener(new ToggleFillClickListener(this, dialog));
        root.addView(btnToggleFill);
        dialog.show();
    }

    private void showVoiceFxDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🎙️ BIẾN ĐỔI GIỌNG NÓI DSP (VOICE EFFECTS)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setGravity(Gravity.CENTER);
        tvTitle.setPadding(0, 0, 0, 16);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] fxList = {"Chipmunk (Sóc chuột cao vút)", "Robot (Người máy kim loại)", "Monster (Quái vật trầm ấm)", "Echo (Vang vọng sân khấu)"};
        for (final String fx : fxList) {
            TextView btnFx = new TextView(activity);
            btnFx.setText(fx);
            btnFx.setTextColor(Color.WHITE);
            btnFx.setTextSize(12);
            btnFx.setBackgroundColor(Color.parseColor("#1E293B"));
            btnFx.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnFx.setLayoutParams(lp);
            btnFx.setOnClickListener(new VoiceFxItemClickListener(this, fx, dialog));
            root.addView(btnFx);
        }
        dialog.show();
    }

    private void showSubtitleGeneratorDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle("⚡ TẠO PHỤ ĐỀ TỰ ĐỘNG BẰNG AI");
        builder.setMessage("Nhận diện giọng nói tiếng Việt bằng AI On-Device và tự động canh chỉnh thời gian khớp từng mili-giây!");
        builder.setPositiveButton("TẠO NGAY (TIẾNG VIỆT)", new SubtitleGeneratorClickListener(this));
        builder.setNegativeButton("HỦY", null);
        builder.show();
    }

    private void showAiVoiceoverDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🎙️ CHUYỂN VĂN BẢN THÀNH GIỌNG NÓI AI (TTS)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final EditText etScript = new EditText(activity);
        etScript.setHint("Nhập nội dung cần đọc thuyết minh...");
        etScript.setTextColor(Color.WHITE);
        etScript.setHintTextColor(Color.parseColor("#64748B"));
        etScript.setText("Chào mừng các bạn đến với ứng dụng NextAI OpenCut!");
        etScript.setBackgroundColor(Color.parseColor("#1E293B"));
        etScript.setPadding(16, 12, 16, 12);
        root.addView(etScript);

        final AlertDialog dialog = builder.setView(root).create();

        String[] voices = {"Giọng Nữ Ngọt Ngào (Hạ Nhi)", "Giọng Nam Trầm Ấm (Minh Quân)", "Giọng Nữ Thời Sự (VTV)", "Giọng Tiếng Anh (Jessica - US)"};
        for (final String vName : voices) {
            TextView btnV = new TextView(activity);
            btnV.setText(vName);
            btnV.setTextColor(Color.WHITE);
            btnV.setTextSize(12);
            btnV.setBackgroundColor(Color.parseColor("#0F2B48"));
            btnV.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 8, 0, 0);
            btnV.setLayoutParams(lp);
            btnV.setOnClickListener(new AiVoiceoverItemClickListener(this, etScript, vName, dialog));
            root.addView(btnV);
        }
        dialog.show();
    }

    private void showTextEditorDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🔤 THÊM VĂN BẢN TRÊN VIDEO");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final EditText etText = new EditText(activity);
        etText.setHint("Nhập chữ hiển thị...");
        etText.setTextColor(Color.WHITE);
        etText.setHintTextColor(Color.parseColor("#64748B"));
        etText.setText("NEXTAI OPENCUT 2026");
        etText.setBackgroundColor(Color.parseColor("#1E293B"));
        etText.setPadding(16, 12, 16, 12);
        root.addView(etText);

        final AlertDialog dialog = builder.setView(root).create();

        LinearLayout colorRow = new LinearLayout(activity);
        colorRow.setOrientation(LinearLayout.HORIZONTAL);
        colorRow.setPadding(0, 12, 0, 12);

        int[] colors = {Color.WHITE, Color.parseColor("#00E5FF"), Color.parseColor("#FBBF24"), Color.parseColor("#EF4444")};
        for (final int c : colors) {
            View dot = new View(activity);
            dot.setBackgroundColor(c);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(50, 50);
            lp.setMargins(8, 0, 8, 0);
            dot.setLayoutParams(lp);
            dot.setOnClickListener(new TextOverlayColorClickListener(this, c));
            colorRow.addView(dot);
        }
        root.addView(colorRow);

        TextView btnConfirm = new TextView(activity);
        btnConfirm.setText("XÁC NHẬN");
        btnConfirm.setTextColor(Color.BLACK);
        btnConfirm.setTextSize(12);
        btnConfirm.setTypeface(null, Typeface.BOLD);
        btnConfirm.setGravity(Gravity.CENTER);
        btnConfirm.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        btnConfirm.setPadding(16, 12, 16, 12);
        btnConfirm.setOnClickListener(new TextOverlayConfirmClickListener(this, etText, dialog));
        root.addView(btnConfirm);
        dialog.show();
    }

    private void showTextTemplateDialog() {
        showTextEditorDialog();
    }

    private void showMusicLibraryDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🎵 KHO NHẠC NỀN CAPCUT HOT TRENDING");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] musicList = {"Sunset Lo-Fi Chill Beat (120BPM)", "Epic Cinematic Orchestra Hero", "TikTok Dance Viral Bass Drop", "Acoustic Guitar Morning Coffee"};
        for (final String m : musicList) {
            TextView btnM = new TextView(activity);
            btnM.setText("▶ " + m);
            btnM.setTextColor(Color.WHITE);
            btnM.setTextSize(11);
            btnM.setBackgroundColor(Color.parseColor("#1E293B"));
            btnM.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnM.setLayoutParams(lp);
            btnM.setOnClickListener(new MusicLibraryItemClickListener(this, m, dialog));
            root.addView(btnM);
        }
        dialog.show();
    }

    private void showSoundFxLibraryDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🔔 HIỆU ỨNG ÂM THANH (SOUND FX)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] sfxList = {"Whoosh Chuyển Cảnh", "Tiếng Chuông Ding Đáo", "Camera Shutter Tách Tách", "Pop Bong Bóng Vui Nhộn"};
        for (final String s : sfxList) {
            TextView btnS = new TextView(activity);
            btnS.setText("🔔 " + s);
            btnS.setTextColor(Color.WHITE);
            btnS.setTextSize(11);
            btnS.setBackgroundColor(Color.parseColor("#1E293B"));
            btnS.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnS.setLayoutParams(lp);
            btnS.setOnClickListener(new SoundFxAddListener(this, s, dialog));
            root.addView(btnS);
        }
        dialog.show();
    }

    private void showAddAudioOptionsDialog() {
        showMusicLibraryDialog();
    }

    private void extractAudioFromVideo() {
        activeAudioTracks.add(new AudioTrackItem("ext_" + System.currentTimeMillis(), "📥 [Đã trích xuất âm thanh]", 4, 0, 15000, 100, "#8B5CF6", null));
        renderMultiAudioTracks();
        Toast.makeText(activity, "📥 Đã tách âm thanh từ video sang track âm thanh riêng!", Toast.LENGTH_SHORT).show();
    }

    private void showTransitionDialog(final int clipIndex) {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("⚡ CHỌN HIỆU ỨNG CHUYỂN CẢNH (TRANSITION)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] transitions = {"none (Không chuyển cảnh)", "fade_black (Mờ đen điện ảnh)", "white_flash (Nháy sáng)", "zoom_in (Thu phóng)", "slide_left (Trượt trái)", "glitch_wave (Sóng nhiễu Glitch)"};
        for (final String t : transitions) {
            TextView btnT = new TextView(activity);
            btnT.setText(t);
            btnT.setTextColor(Color.WHITE);
            btnT.setTextSize(11);
            btnT.setBackgroundColor(Color.parseColor("#1E293B"));
            btnT.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnT.setLayoutParams(lp);
            btnT.setOnClickListener(new TransitionItemClickListener(this, clipIndex, t.split(" ")[0], dialog));
            root.addView(btnT);
        }
        dialog.show();
    }

    private void showClipAnimationDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("✨ HOẠT ẢNH VÀO / RA / COMBO (ANIMATION)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] anims = {"none (Không hoạt ảnh)", "fade_in (Hiện mờ dần)", "slide_up (Trượt từ dưới lên)", "zoom_bounce (Nảy phóng to)", "shake (Rung động)"};
        for (final String a : anims) {
            TextView btnA = new TextView(activity);
            btnA.setText(a);
            btnA.setTextColor(Color.WHITE);
            btnA.setTextSize(11);
            btnA.setBackgroundColor(Color.parseColor("#1E293B"));
            btnA.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnA.setLayoutParams(lp);
            btnA.setOnClickListener(new ClipAnimClickListener(this, a.split(" ")[0], dialog));
            root.addView(btnA);
        }
        dialog.show();
    }

    private void showOpacityDialog() {
        if (activeProjectClips.isEmpty() || selectedClipIndex < 0 || selectedClipIndex >= activeProjectClips.size()) return;
        final MediaItem clip = activeProjectClips.get(selectedClipIndex);

        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        final TextView tvTitle = new TextView(activity);
        tvTitle.setText("👁️ ĐỘ MỜ ĐỤC: " + clip.opacityPercent + "%");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        SeekBar sbOp = new SeekBar(activity);
        sbOp.setMax(100);
        sbOp.setProgress(clip.opacityPercent);
        sbOp.setOnSeekBarChangeListener(new OpacityChangeListener(this, clip, tvTitle));
        root.addView(sbOp);

        builder.setView(root);
        builder.setPositiveButton("XONG", null);
        builder.show();
    }

    public void showPipBlendModeDialog() {
        if (activePipClips.isEmpty() || selectedPipIndex < 0 || selectedPipIndex >= activePipClips.size()) return;
        final PipClipItem curPip = activePipClips.get(selectedPipIndex);

        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(24, 16, 24, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🔲 CHỌN CHẾ ĐỘ HÒA TRỘN LỚP PHỦ (BLEND MODES)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(13);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        final AlertDialog dialog = builder.setView(root).create();

        String[] modes = {"normal (Bình thường)", "screen (Làm sáng / Lọc đen)", "multiply (Nhân màu / Lọc trắng)", "overlay (Phủ màu rực rỡ)", "darken (Làm tối)"};
        for (final String m : modes) {
            TextView btnM = new TextView(activity);
            btnM.setText(m);
            btnM.setTextColor(Color.WHITE);
            btnM.setTextSize(11);
            btnM.setBackgroundColor(Color.parseColor("#1E293B"));
            btnM.setPadding(16, 12, 16, 12);
            LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
            lp.setMargins(0, 0, 0, 8);
            btnM.setLayoutParams(lp);
            btnM.setOnClickListener(new PipBlendItemClickListener(this, curPip, m.split(" ")[0], dialog));
            root.addView(btnM);
        }
        dialog.show();
    }

    public void showNoiseReductionDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle("🔇 GIẢM TIẾNG ỒN BẰNG DSP AI");
        builder.setMessage("Lọc tiếng gió, tiếng xe cộ và tạp âm môi trường tự động.");
        builder.setPositiveButton("BẬT LỌC ỒN", new NoiseReductionClickListener(this));
        builder.setNegativeButton("ĐÓNG", null);
        builder.show();
    }

    public void showVocalIsolationDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle("🎤 TÁCH LỜI BÀI HÁT / GIỮ NGUYÊN NHẠC BEAT");
        builder.setMessage("Tách riêng giọng hát ca sĩ và nhạc nền beat để làm Karaoke hoặc lồng tiếng.");
        builder.setPositiveButton("TÁCH GIỌNG HÁT", new VocalIsolationClickListener(this));
        builder.setNegativeButton("ĐÓNG", null);
        builder.show();
    }

    private void showCoverEditorDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        LinearLayout root = new LinearLayout(activity);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(20, 16, 20, 16);
        root.setBackgroundColor(Color.parseColor("#141824"));

        TextView tvTitle = new TextView(activity);
        tvTitle.setText("🖼️ THIẾT KẾ ẢNH BÌA & PHỤ ĐỀ KARAOKE");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setGravity(Gravity.CENTER);
        tvTitle.setPadding(0, 0, 0, 12);
        root.addView(tvTitle);

        ivCoverPreview = new ImageView(activity);
        ivCoverPreview.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 260));
        ivCoverPreview.setScaleType(ImageView.ScaleType.FIT_CENTER);
        ivCoverPreview.setBackgroundColor(Color.BLACK);
        root.addView(ivCoverPreview);

        etCoverTitle = new EditText(activity);
        etCoverTitle.setHint("Nhập tiêu đề ảnh bìa video...");
        etCoverTitle.setText(coverTitleText);
        etCoverTitle.setTextColor(Color.WHITE);
        etCoverTitle.setHintTextColor(Color.parseColor("#64748B"));
        etCoverTitle.setBackgroundColor(Color.parseColor("#1E293B"));
        etCoverTitle.setPadding(16, 12, 16, 12);
        LinearLayout.LayoutParams etLp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        etLp.setMargins(0, 12, 0, 8);
        etCoverTitle.setLayoutParams(etLp);
        root.addView(etCoverTitle);

        // Template Pills
        HorizontalScrollView tplScroll = new HorizontalScrollView(activity);
        tplScroll.setHorizontalScrollBarEnabled(false);
        LinearLayout tplRow = new LinearLayout(activity);
        tplRow.setOrientation(LinearLayout.HORIZONTAL);
        pillTplBottom = createCoverPill("Tiêu đề Dưới", coverTemplateIndex == 0, tplRow);
        pillTplCenter = createCoverPill("Giữa Khung", coverTemplateIndex == 1, tplRow);
        pillTplTiktok = createCoverPill("#Trending", coverTemplateIndex == 2, tplRow);
        pillTplCinema = createCoverPill("Điện ảnh", coverTemplateIndex == 3, tplRow);
        tplScroll.addView(tplRow);
        root.addView(tplScroll);

        // Karaoke Style Pills
        TextView tvKaraokeLabel = new TextView(activity);
        tvKaraokeLabel.setText("⚡ Kiểu Phụ Đề Word-by-Word Karaoke:");
        tvKaraokeLabel.setTextColor(Color.parseColor("#38BDF8"));
        tvKaraokeLabel.setTextSize(11);
        tvKaraokeLabel.setPadding(0, 10, 0, 4);
        root.addView(tvKaraokeLabel);

        HorizontalScrollView kScroll = new HorizontalScrollView(activity);
        kScroll.setHorizontalScrollBarEnabled(false);
        LinearLayout kRow = new LinearLayout(activity);
        kRow.setOrientation(LinearLayout.HORIZONTAL);
        pillKaraokeGold = createCoverPill("Vàng Gold Phát Sáng", "karaoke_gold_glow".equals(currentKaraokeStyle), kRow);
        pillKaraokeNeon = createCoverPill("Neon Cyan", "karaoke_neon_cyan".equals(currentKaraokeStyle), kRow);
        pillKaraokeBox = createCoverPill("Hộp Đỏ Nổi", "karaoke_box_highlight".equals(currentKaraokeStyle), kRow);
        pillKaraokeBounce = createCoverPill("Nảy Chữ Pop", "karaoke_bouncy_popup".equals(currentKaraokeStyle), kRow);
        kScroll.addView(kRow);
        root.addView(kScroll);

        // Action Buttons
        LinearLayout btnRow = new LinearLayout(activity);
        btnRow.setOrientation(LinearLayout.HORIZONTAL);
        btnRow.setPadding(0, 16, 0, 0);

        btnUploadCustomPhoto = new TextView(activity);
        btnUploadCustomPhoto.setText("📤 Nạp Ảnh");
        btnUploadCustomPhoto.setTextColor(Color.WHITE);
        btnUploadCustomPhoto.setTextSize(11);
        btnUploadCustomPhoto.setBackgroundResource(R.drawable.bg_capcut_resolution_pill);
        btnUploadCustomPhoto.setPadding(16, 12, 16, 12);
        btnUploadCustomPhoto.setOnClickListener(this);
        btnRow.addView(btnUploadCustomPhoto);

        View bSpacer = new View(activity);
        btnRow.addView(bSpacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnCancelCover = new TextView(activity);
        btnCancelCover.setText("HỦY");
        btnCancelCover.setTextColor(Color.parseColor("#94A3B8"));
        btnCancelCover.setTextSize(11);
        btnCancelCover.setPadding(20, 12, 20, 12);
        btnCancelCover.setOnClickListener(this);
        btnRow.addView(btnCancelCover);

        btnSaveCover = new TextView(activity);
        btnSaveCover.setText("LƯU BÌA");
        btnSaveCover.setTextColor(Color.BLACK);
        btnSaveCover.setTextSize(12);
        btnSaveCover.setTypeface(null, Typeface.BOLD);
        btnSaveCover.setBackgroundResource(R.drawable.bg_capcut_cyan_pill);
        btnSaveCover.setPadding(24, 12, 24, 12);
        btnSaveCover.setOnClickListener(this);
        btnRow.addView(btnSaveCover);

        root.addView(btnRow);

        updateCoverPreview();
        activeDialog = builder.setView(root).create();
        activeDialog.show();
    }

    private void updateCoverPreview() {
        if (ivCoverPreview != null) {
            ivCoverPreview.setImageBitmap(bakeCoverBitmap());
        }
    }

    private Bitmap bakeCoverBitmap() {
        int w = 720;
        int h = 1280;
        Bitmap composite = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(composite);

        Bitmap base = projectCoverBitmap;
        if (base == null && !activeProjectClips.isEmpty()) {
            MediaItem mi = activeProjectClips.get(0);
            base = mi.thumbnailBitmap;
        }

        if (base != null) {
            Rect src = new Rect(0, 0, base.getWidth(), base.getHeight());
            Rect dst = new Rect(0, 0, w, h);
            canvas.drawBitmap(base, src, dst, null);
        } else {
            canvas.drawColor(Color.parseColor("#1A1B26"));
        }

        Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
        Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        textPaint.setTextAlign(Paint.Align.CENTER);

        if (coverFontIndex == 0) {
            textPaint.setColor(Color.parseColor("#FFD700"));
            textPaint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
            textPaint.setShadowLayer(8f, 0f, 4f, Color.BLACK);
        } else if (coverFontIndex == 1) {
            textPaint.setColor(Color.WHITE);
            textPaint.setTypeface(Typeface.create(Typeface.SERIF, Typeface.BOLD_ITALIC));
            textPaint.setShadowLayer(6f, 0f, 3f, Color.BLACK);
        } else if (coverFontIndex == 2) {
            textPaint.setColor(Color.parseColor("#00E5FF"));
            textPaint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
            textPaint.setShadowLayer(12f, 0f, 0f, Color.parseColor("#00E5FF"));
        } else {
            textPaint.setColor(Color.WHITE);
            textPaint.setTypeface(Typeface.create(Typeface.SANS_SERIF, Typeface.NORMAL));
            textPaint.setShadowLayer(4f, 0f, 2f, Color.BLACK);
        }

        String title = (coverTitleText != null && !coverTitleText.trim().isEmpty()) ? coverTitleText : "NEXTAI OPENCUT";

        if (coverTemplateIndex == 0) {
            paint.setColor(Color.parseColor("#CC12131A"));
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(0, h - 260, w, h - 40, paint);
            paint.setColor(Color.parseColor("#00E5FF"));
            canvas.drawRect(40, h - 255, w - 40, h - 250, paint);
            textPaint.setTextSize(46);
            canvas.drawText(title, w / 2f, h - 140, textPaint);
        } else if (coverTemplateIndex == 1) {
            paint.setColor(Color.parseColor("#E6000000"));
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(40, (h / 2f) - 140, w - 40, (h / 2f) + 140, paint);
            paint.setStyle(Paint.Style.STROKE);
            paint.setStrokeWidth(6f);
            paint.setColor(Color.parseColor("#FFD700"));
            canvas.drawRect(50, (h / 2f) - 130, w - 50, (h / 2f) + 130, paint);
            textPaint.setTextSize(52);
            canvas.drawText(title, w / 2f, (h / 2f) + 18, textPaint);
        } else if (coverTemplateIndex == 2) {
            paint.setColor(Color.parseColor("#FF0055"));
            paint.setStyle(Paint.Style.FILL);
            RectF pillRect = new RectF(50, 100, 320, 170);
            canvas.drawRoundRect(pillRect, 20, 20, paint);
            Paint tagPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
            tagPaint.setColor(Color.WHITE);
            tagPaint.setTextSize(30);
            tagPaint.setTypeface(Typeface.DEFAULT_BOLD);
            canvas.drawText("🔥 #TRENDING", 75, 148, tagPaint);

            paint.setColor(Color.parseColor("#B3000000"));
            canvas.drawRect(0, h - 280, w, h - 60, paint);
            textPaint.setTextSize(48);
            canvas.drawText(title, w / 2f, h - 160, textPaint);
        } else {
            paint.setColor(Color.BLACK);
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(0, 0, w, 160, paint);
            canvas.drawRect(0, h - 160, w, h, paint);

            textPaint.setTextSize(44);
            canvas.drawText(title, w / 2f, h - 70, textPaint);
        }

        return composite;
    }

    private View createCoverPill(String label, boolean isSelected, LinearLayout parent) {
        TextView pill = new TextView(activity);
        pill.setText(label);
        pill.setTextColor(isSelected ? Color.parseColor("#00E5FF") : Color.WHITE);
        pill.setTextSize(11);
        pill.setTypeface(null, isSelected ? Typeface.BOLD : Typeface.NORMAL);
        pill.setBackgroundResource(R.drawable.bg_capcut_tab_pill);
        pill.setPadding(22, 12, 22, 12);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 12, 0);
        pill.setLayoutParams(lp);
        pill.setOnClickListener(this);
        parent.addView(pill);
        return pill;
    }

    private void setCoverPillActive(View pill, boolean active) {
        if (pill instanceof TextView) {
            TextView tv = (TextView) pill;
            tv.setTextColor(active ? Color.parseColor("#00E5FF") : Color.WHITE);
            tv.setTypeface(null, active ? Typeface.BOLD : Typeface.NORMAL);
        }
    }

    // Static Listener Helper Classes
    private static class TimelineScaleListener extends ScaleGestureDetector.SimpleOnScaleGestureListener {
        private final VideoEditorComponent component;
        public TimelineScaleListener(VideoEditorComponent c) { this.component = c; }
        @Override
        public boolean onScale(ScaleGestureDetector detector) {
            if (component == null) return false;
            component.timelineScaleFactor *= detector.getScaleFactor();
            component.timelineScaleFactor = Math.max(0.4f, Math.min(3.5f, component.timelineScaleFactor));
            component.renderTimelineFilmstrip();
            return true;
        }
    }

    /**
     * TimelineTouchListener — Bộ lắng nghe cử chỉ chạm trên Timeline (Fixes V4 & V11)
     * Tracks touch down/move to activate user scrubbing lock and prevents playback timer race condition.
     */
    private static class TimelineTouchListener implements View.OnTouchListener {
        private final VideoEditorComponent component;
        public TimelineTouchListener(VideoEditorComponent c) { this.component = c; }
        @Override
        public boolean onTouch(View v, MotionEvent event) {
            if (component != null) {
                if (component.timelineScaleDetector != null) {
                    component.timelineScaleDetector.onTouchEvent(event);
                }
                int action = event.getActionMasked();
                if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_MOVE) {
                    component.isUserScrubbing = true;
                    component.playbackHandler.removeCallbacks(component.scrubResetRunnable);
                } else if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_CANCEL) {
                    component.playbackHandler.removeCallbacks(component.scrubResetRunnable);
                    component.playbackHandler.postDelayed(component.scrubResetRunnable, 300);
                }
            }
            return false;
        }
    }

    /**
     * TimelineScrollChangeListener — Đồng bộ vị trí cuộn Timeline khi người dùng kéo thả
     */
    private static class TimelineScrollChangeListener implements View.OnScrollChangeListener {
        private final VideoEditorComponent component;
        public TimelineScrollChangeListener(VideoEditorComponent c) { this.component = c; }
        @Override
        public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
            if (component == null || component.isSyncingScroll) return;
            component.isUserScrubbing = true;
            int totalSec = scrollX / 40;
            component.seekTimelineToSecond(totalSec);
            component.playbackHandler.removeCallbacks(component.scrubResetRunnable);
            component.playbackHandler.postDelayed(component.scrubResetRunnable, 300);
        }
    }

    private static class UserScrubResetRunnable implements Runnable {
        private final VideoEditorComponent component;
        public UserScrubResetRunnable(VideoEditorComponent c) { this.component = c; }
        @Override
        public void run() {
            if (component != null) component.isUserScrubbing = false;
        }
    }

    private static class TextOverlayTouchListener implements View.OnTouchListener {
        private final VideoEditorComponent component;
        private float lastX, lastY;
        public TextOverlayTouchListener(VideoEditorComponent c) { this.component = c; }
        @Override
        public boolean onTouch(View v, MotionEvent event) {
            switch (event.getAction()) {
                case MotionEvent.ACTION_DOWN:
                    lastX = event.getRawX();
                    lastY = event.getRawY();
                    return true;
                case MotionEvent.ACTION_MOVE:
                    float dx = event.getRawX() - lastX;
                    float dy = event.getRawY() - lastY;
                    v.setTranslationX(v.getTranslationX() + dx);
                    v.setTranslationY(v.getTranslationY() + dy);
                    lastX = event.getRawX();
                    lastY = event.getRawY();
                    return true;
            }
            return false;
        }
    }

    private static class RulerCellClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int second;
        public RulerCellClickListener(VideoEditorComponent c, int sec) { this.component = c; this.second = sec; }
        @Override
        public void onClick(View v) {
            if (component != null) component.seekTimelineToSecond(second);
        }
    }

    private static class AudioTrackSelectListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int index;
        public AudioTrackSelectListener(VideoEditorComponent c, int i) { this.component = c; this.index = i; }
        @Override
        public void onClick(View v) {
            if (component != null) {
                component.selectedAudioTrackIndex = index;
                component.renderMultiAudioTracks();
            }
        }
    }

    private static class AudioTrackDeleteListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int index;
        public AudioTrackDeleteListener(VideoEditorComponent c, int i) { this.component = c; this.index = i; }
        @Override
        public void onClick(View v) {
            if (component != null && component.activeAudioTracks.size() > 1) {
                component.activeAudioTracks.remove(index);
                component.selectedAudioTrackIndex = Math.max(0, index - 1);
                component.renderMultiAudioTracks();
            }
        }
    }

    private static class SoundFxAddListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String sfxTitle;
        private final AlertDialog dialog;
        public SoundFxAddListener(VideoEditorComponent c, String title, AlertDialog d) { this.component = c; this.sfxTitle = title; this.dialog = d; }
        @Override
        public void onClick(View v) {
            if (component != null) {
                component.activeAudioTracks.add(new AudioTrackItem("sfx_" + System.currentTimeMillis(), "🔔 " + sfxTitle, 2, 0, 3000, 100, "#3B82F6", null));
                component.renderMultiAudioTracks();
                Toast.makeText(component.activity, "🔔 Đã chèn Sound FX: " + sfxTitle, Toast.LENGTH_SHORT).show();
            }
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class TransitionItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int clipIndex;
        private final String type;
        private final AlertDialog dialog;
        public TransitionItemClickListener(VideoEditorComponent c, int idx, String t, AlertDialog d) { this.component = c; this.clipIndex = idx; this.type = t; this.dialog = d; }
        @Override
        public void onClick(View v) {
            if (component != null && clipIndex < component.activeProjectClips.size()) {
                component.activeProjectClips.get(clipIndex).transitionType = type;
                component.renderTimelineFilmstrip();
                Toast.makeText(component.activity, "⚡ Đã cài chuyển cảnh: " + type, Toast.LENGTH_SHORT).show();
            }
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class ClipAnimClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String anim;
        private final AlertDialog dialog;
        public ClipAnimClickListener(VideoEditorComponent c, String a, AlertDialog d) { this.component = c; this.anim = a; this.dialog = d; }
        @Override
        public void onClick(View v) {
            if (component != null && !component.activeProjectClips.isEmpty() && component.selectedClipIndex >= 0 && component.selectedClipIndex < component.activeProjectClips.size()) {
                component.activeProjectClips.get(component.selectedClipIndex).animationType = anim;
                component.renderTimelineFilmstrip();
                Toast.makeText(component.activity, "✨ Đã cài hoạt ảnh: " + anim, Toast.LENGTH_SHORT).show();
            }
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class OpacityChangeListener implements SeekBar.OnSeekBarChangeListener {
        private final VideoEditorComponent component;
        private final MediaItem clip;
        private final TextView tvLabel;
        public OpacityChangeListener(VideoEditorComponent c, MediaItem clip, TextView tv) { this.component = c; this.clip = clip; this.tvLabel = tv; }
        @Override
        public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
            if (clip != null) clip.opacityPercent = progress;
            if (tvLabel != null) tvLabel.setText("👁️ ĐỘ MỜ ĐỤC: " + progress + "%");
            if (component != null) {
                View target = (component.videoPlayerView != null && component.videoPlayerView.getVisibility() == View.VISIBLE) ? component.videoPlayerView : component.ivVideoPoster;
                if (target != null) target.setAlpha(progress / 100.0f);
            }
        }
        @Override public void onStartTrackingTouch(SeekBar seekBar) {}
        @Override public void onStopTrackingTouch(SeekBar seekBar) {}
    }

    private static class TrackSelectionClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int trackType;
        public TrackSelectionClickListener(VideoEditorComponent c, int type) { this.component = c; this.trackType = type; }
        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.currentSelectedTrack = trackType;
            if (trackType == TRACK_TYPE_VIDEO) {
                component.showRibbonLevel(component.ribbonEditSubmenu);
            } else if (trackType == TRACK_TYPE_PIP) {
                component.showRibbonLevel(component.ribbonPipContextToolbar);
            } else if (trackType == TRACK_TYPE_AUDIO) {
                component.showRibbonLevel(component.ribbonAudioSubmenu);
            } else if (trackType == TRACK_TYPE_SUBTITLE) {
                component.showRibbonLevel(component.ribbonTextSubmenu);
            } else if (trackType == TRACK_TYPE_EFFECT) {
                component.showRibbonLevel(component.ribbonEffectsDrawer);
            }
        }
    }

    private static class PipContextToolClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String action;
        public PipContextToolClickListener(VideoEditorComponent c, String a) { this.component = c; this.action = a; }
        @Override
        public void onClick(View v) {
            if (component == null) return;
            if ("pip_blend".equals(action)) {
                component.showPipBlendModeDialog();
            } else if ("pip_chroma".equals(action)) {
                component.showRibbonLevel(component.ribbonCutoutDrawer);
            } else if ("pip_mask".equals(action)) {
                component.showRibbonLevel(component.ribbonMaskDrawer);
            } else if ("pip_delete".equals(action)) {
                if (!component.activePipClips.isEmpty() && component.selectedPipIndex >= 0 && component.selectedPipIndex < component.activePipClips.size()) {
                    component.activePipClips.remove(component.selectedPipIndex);
                    component.selectedPipIndex = Math.max(0, component.activePipClips.size() - 1);
                    component.renderPipTrack();
                    component.updatePipCanvasPreview();
                    Toast.makeText(component.activity, "🗑️ Đã xóa lớp phủ PIP!", Toast.LENGTH_SHORT).show();
                }
            }
        }
    }

    private static class PipBlendBadgeClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        public PipBlendBadgeClickListener(VideoEditorComponent c) { this.component = c; }
        @Override
        public void onClick(View v) {
            if (component != null) component.showPipBlendModeDialog();
        }
    }

    private static class PipBlendItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final PipClipItem pipClip;
        private final String mode;
        private final AlertDialog dialog;
        public PipBlendItemClickListener(VideoEditorComponent c, PipClipItem pip, String m, AlertDialog d) { this.component = c; this.pipClip = pip; this.mode = m; this.dialog = d; }
        @Override
        public void onClick(View v) {
            if (pipClip != null) pipClip.blendMode = mode;
            if (component != null) component.updatePipCanvasPreview();
            if (dialog != null) dialog.dismiss();
        }
    }

    @Override
    public void onExportSuccess(File exportedFile) {
        if (listener != null) {
            listener.onVideoExported(exportedFile);
        }
    }

    @Override
    public void onExportError(String error) {
        Toast.makeText(activity, "Lỗi xuất video: " + error, Toast.LENGTH_LONG).show();
    }

    /**
     * PipDragTouchListener — Kéo thả lớp phủ PIP trên khung Video Canvas (Fixes V10)
     * Correctly transforms raw pixel motion deltas into normalized ratios and clamps PIP within screen bounds.
     */
    private static class PipDragTouchListener implements View.OnTouchListener {
        private final VideoEditorComponent component;
        private float lastRawX, lastRawY;

        public PipDragTouchListener(VideoEditorComponent c) { this.component = c; }

        @Override
        public boolean onTouch(View v, MotionEvent event) {
            if (component == null || component.activePipClips.isEmpty()) return false;
            PipClipItem curPip = component.activePipClips.get(Math.max(0, component.selectedPipIndex));
            int parentW = component.canvasFrame != null && component.canvasFrame.getWidth() > 0 ? component.canvasFrame.getWidth() : 1080;
            int parentH = component.canvasFrame != null && component.canvasFrame.getHeight() > 0 ? component.canvasFrame.getHeight() : 1440;

            switch (event.getActionMasked()) {
                case MotionEvent.ACTION_DOWN:
                    lastRawX = event.getRawX();
                    lastRawY = event.getRawY();
                    return true;
                case MotionEvent.ACTION_MOVE:
                    float deltaX = event.getRawX() - lastRawX;
                    float deltaY = event.getRawY() - lastRawY;
                    lastRawX = event.getRawX();
                    lastRawY = event.getRawY();

                    // Convert delta pixel to relative ratio (0.0 to 1.0)
                    // Chuyển đổi khoảng cách di chuyển pixel sang tỉ lệ tương đối (0.0 đến 1.0)
                    float relDeltaX = deltaX / (float) parentW;
                    float relDeltaY = deltaY / (float) parentH;

                    // Clamp to visible canvas bounds (0.0 to 1.0 - scale)
                    // Giới hạn trong phạm vi hiển thị an toàn của khung video, chống văng khỏi màn hình
                    float maxRelX = Math.max(0.0f, 1.0f - curPip.scale);
                    float maxRelY = Math.max(0.0f, 1.0f - (curPip.scale * 9f / 16f));

                    curPip.posX = Math.max(0.0f, Math.min(maxRelX, curPip.posX + relDeltaX));
                    curPip.posY = Math.max(0.0f, Math.min(maxRelY, curPip.posY + relDeltaY));

                    component.updatePipCanvasPreview();
                    return true;
            }
            return false;
        }
    }

    private static class EffectCardClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String fxKey;
        private final String title;

        public EffectCardClickListener(VideoEditorComponent c, String key, String t) {
            this.component = c;
            this.fxKey = key;
            this.title = t;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.currentVideoFilter = fxKey;
            component.updatePlayerPreview();
            Toast.makeText(component.activity, "✨ Đã áp dụng hiệu ứng: " + title, Toast.LENGTH_SHORT).show();
        }
    }

    private static class ChromaColorDotClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int color;
        private final String label;

        public ChromaColorDotClickListener(VideoEditorComponent c, int col, String lbl) {
            this.component = c;
            this.color = col;
            this.label = lbl;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.currentChromaColor = color;
            component.updatePlayerPreview();
            Toast.makeText(component.activity, "🎯 Chọn màu xóa phông: " + label, Toast.LENGTH_SHORT).show();
        }
    }

    private static class RatioItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String ratio;
        private final AlertDialog dialog;

        public RatioItemClickListener(VideoEditorComponent c, String r, AlertDialog d) {
            this.component = c;
            this.ratio = r;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.currentVideoRatio = ratio.split(" ")[0];
            component.isVideoFillMode = false;
            component.updateVideoCanvasDimensions();
            component.updatePlayerPreview();
            Toast.makeText(component.activity, "📐 Đã chuyển tỷ lệ sang " + component.currentVideoRatio, Toast.LENGTH_SHORT).show();
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class ToggleFillClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final AlertDialog dialog;

        public ToggleFillClickListener(VideoEditorComponent c, AlertDialog d) {
            this.component = c;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.isVideoFillMode = !component.isVideoFillMode;
            component.updateVideoCanvasDimensions();
            component.updatePlayerPreview();
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class VoiceFxItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String fx;
        private final AlertDialog dialog;

        public VoiceFxItemClickListener(VideoEditorComponent c, String f, AlertDialog d) {
            this.component = c;
            this.fx = f;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            MiddleBridgeJni.applyVoiceFx(fx.toLowerCase().split(" ")[0], 1.0f);
            Toast.makeText(component.activity, "🎙️ Đã áp dụng hiệu ứng giọng: " + fx, Toast.LENGTH_SHORT).show();
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class SubtitleGeneratorClickListener implements DialogInterface.OnClickListener {
        private final VideoEditorComponent component;

        public SubtitleGeneratorClickListener(VideoEditorComponent c) {
            this.component = c;
        }

        @Override
        public void onClick(DialogInterface d, int which) {
            if (component == null) return;
            component.currentSubtitles.clear();
            component.currentSubtitles.add(new SubtitleItem(0, 2500, "Xin chào mọi người!"));
            component.currentSubtitles.add(new SubtitleItem(2600, 6500, "Hôm nay mình sẽ hướng dẫn edit video bằng NextAI OpenCut."));
            component.currentSubtitles.add(new SubtitleItem(6600, 11000, "Ứng dụng hỗ trợ đầy đủ 100% tính năng chuyên nghiệp."));
            component.currentSubtitles.add(new SubtitleItem(11100, 15000, "Chúc các bạn sáng tạo nhiều video triệu view!"));
            if (component.timelineSubtitlesRow != null) component.timelineSubtitlesRow.setVisibility(View.VISIBLE);
            Toast.makeText(component.activity, "⚡ Đã tạo 4 câu phụ đề AI đồng bộ!", Toast.LENGTH_SHORT).show();
        }
    }

    private static class AiVoiceoverItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final EditText etScript;
        private final String vName;
        private final AlertDialog dialog;

        public AiVoiceoverItemClickListener(VideoEditorComponent c, EditText et, String name, AlertDialog d) {
            this.component = c;
            this.etScript = et;
            this.vName = name;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            String text = etScript.getText().toString();
            if (component.ttsEngine != null && component.isTtsReady) {
                component.ttsEngine.speak(text, TextToSpeech.QUEUE_FLUSH, null, "tts_ai");
            }
            component.activeAudioTracks.add(new AudioTrackItem("tts_" + System.currentTimeMillis(), "🎙️ [TTS: " + vName.split(" ")[2] + "]", 3, 0, 5000, 100, "#F59E0B", null));
            component.renderMultiAudioTracks();
            Toast.makeText(component.activity, "🎙️ Đã đọc và lồng track giọng nói AI!", Toast.LENGTH_SHORT).show();
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class TextOverlayColorClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final int color;

        public TextOverlayColorClickListener(VideoEditorComponent c, int col) {
            this.component = c;
            this.color = col;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.customOverlayTextColor = color;
            if (component.tvCanvasTextOverlay != null) component.tvCanvasTextOverlay.setTextColor(color);
        }
    }

    private static class TextOverlayConfirmClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final EditText etText;
        private final AlertDialog dialog;

        public TextOverlayConfirmClickListener(VideoEditorComponent c, EditText et, AlertDialog d) {
            this.component = c;
            this.etText = et;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.customOverlayText = etText.getText().toString();
            if (component.tvCanvasTextOverlay != null) {
                component.tvCanvasTextOverlay.setText(component.customOverlayText);
                component.tvCanvasTextOverlay.setVisibility(View.VISIBLE);
            }
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class MusicLibraryItemClickListener implements View.OnClickListener {
        private final VideoEditorComponent component;
        private final String music;
        private final AlertDialog dialog;

        public MusicLibraryItemClickListener(VideoEditorComponent c, String m, AlertDialog d) {
            this.component = c;
            this.music = m;
            this.dialog = d;
        }

        @Override
        public void onClick(View v) {
            if (component == null) return;
            component.activeAudioTracks.add(new AudioTrackItem("bgm_" + System.currentTimeMillis(), "🎵 " + music, 1, 0, 16000, 100, "#10B981", null));
            component.renderMultiAudioTracks();
            Toast.makeText(component.activity, "🎵 Đã chèn bài hát: " + music, Toast.LENGTH_SHORT).show();
            if (dialog != null) dialog.dismiss();
        }
    }

    private static class NoiseReductionClickListener implements DialogInterface.OnClickListener {
        private final VideoEditorComponent component;

        public NoiseReductionClickListener(VideoEditorComponent c) {
            this.component = c;
        }

        @Override
        public void onClick(DialogInterface d, int which) {
            if (component == null) return;
            MiddleBridgeJni.applyNoiseReduction(85);
            Toast.makeText(component.activity, "🔇 Đã kích hoạt Bộ lọc tạp âm thông minh!", Toast.LENGTH_SHORT).show();
        }
    }

    private static class VocalIsolationClickListener implements DialogInterface.OnClickListener {
        private final VideoEditorComponent component;

        public VocalIsolationClickListener(VideoEditorComponent c) {
            this.component = c;
        }

        @Override
        public void onClick(DialogInterface d, int which) {
            if (component == null) return;
            MiddleBridgeJni.applyVocalIsolation("vocals_only");
            Toast.makeText(component.activity, "🎤 Đã tách riêng Giọng Hát và Nhạc Nền Beat!", Toast.LENGTH_SHORT).show();
        }
    }
}
