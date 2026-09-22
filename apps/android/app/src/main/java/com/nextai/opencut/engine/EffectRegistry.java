package com.nextai.opencut.engine;

import java.util.ArrayList;
import java.util.List;

/**
 * EffectRegistry — Danh Mục Phân Loại 100+ Hiệu Ứng Shader Pack, 3D, Face AR, Body Mesh & Sticker
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class EffectRegistry {

    public static class EffectItem {
        public String id;
        public String nameEn;
        public String nameVi;
        public String category; // "LUT", "3D", "Glitch", "Light", "FaceAR", "BodyMesh", "Sticker"
        public String iconEmoji;
        public boolean isVip;
        public String assetPath; // Path to authentic CapCut asset in assets/

        public EffectItem(String id, String nameEn, String nameVi, String category, String iconEmoji, boolean isVip) {
            this(id, nameEn, nameVi, category, iconEmoji, isVip, "");
        }

        public EffectItem(String id, String nameEn, String nameVi, String category, String iconEmoji, boolean isVip, String assetPath) {
            this.id = id;
            this.nameEn = nameEn;
            this.nameVi = nameVi;
            this.category = category;
            this.iconEmoji = iconEmoji;
            this.isVip = isVip;
            this.assetPath = assetPath;
        }
    }

    private static final List<EffectItem> ALL_EFFECTS = new ArrayList<>();

    static {
        // 1. Color LUT Grading Presets / Màu Điện Ảnh
        ALL_EFFECTS.add(new EffectItem("lut_teal_orange", "Teal & Orange Cine", "Điện Ảnh Xanh Cam", "LUT", "🎨", false));
        ALL_EFFECTS.add(new EffectItem("lut_cyberpunk_neon", "Cyberpunk Neon 2077", "Neon Tương Lai Cyberpunk", "LUT", "🔮", true));
        ALL_EFFECTS.add(new EffectItem("lut_kodak_35mm", "Kodak Portra 35mm", "Màu Phim Kodak 35mm", "LUT", "🎞️", false));
        ALL_EFFECTS.add(new EffectItem("lut_vintage_90s", "Retro Vintage 90s", "Cổ Điển Thập Niên 90", "LUT", "📼", false));
        ALL_EFFECTS.add(new EffectItem("lut_golden_hour", "Golden Sunset Glow", "Hoàng Hôn Nắng Vàng", "LUT", "🌅", false));
        ALL_EFFECTS.add(new EffectItem("lut_moody_cold", "Moody Cold Cinematic", "Tông Lạnh Bắc Âu", "LUT", "❄️", true));

        // 2. 3D Spatial & Parallax / Không Gian 3D
        ALL_EFFECTS.add(new EffectItem("3d_parallax_dolly", "3D Parallax Dolly Zoom", "Vertigo Không Gian 3D", "3D", "🚀", true));
        ALL_EFFECTS.add(new EffectItem("3d_perspective_tilt", "3D Perspective Tilt", "Góc Nghiêng 3D Chiều Sâu", "3D", "📐", false));
        ALL_EFFECTS.add(new EffectItem("3d_cube_spin", "3D Cube Multi-Spin", "Khối Lập Phương 3D Xoay", "3D", "🎲", true));
        ALL_EFFECTS.add(new EffectItem("3d_tiny_planet", "360 Tiny Planet Warp", "Hành Tinh Thu Nhỏ 360", "3D", "🪐", true));

        // 3. Glitch & Distortion / Nhiễu Sóng & Biến Dạng
        ALL_EFFECTS.add(new EffectItem("glitch_rgb_split", "RGB Chromatic Split", "Tách Lớp Màu RGB", "Glitch", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("glitch_vhs_tracking", "VHS Tape Retro Scanline", "Băng Từ VHS Cổ Điển", "Glitch", "📺", false));
        ALL_EFFECTS.add(new EffectItem("glitch_datamosh", "Datamosh Pixel Bloom", "Nhiễu Điểm Ảnh Datamosh", "Glitch", "👾", true));
        ALL_EFFECTS.add(new EffectItem("distort_fisheye", "Fisheye Lens 180°", "Ống Kính Mắt Cá 180°", "Glitch", "🐟", false));

        // 4. Atmospheric Light & Glow / Ánh Sáng & Hào Quang
        ALL_EFFECTS.add(new EffectItem("light_cinema_bloom", "Cinematic Bloom & Glow", "Hào Quang Tỏa Sáng", "Light", "✨", false));
        ALL_EFFECTS.add(new EffectItem("light_anamorphic_flare", "Anamorphic Blue Flare", "Vệt Sáng Anamorphic", "Light", "💫", true));
        ALL_EFFECTS.add(new EffectItem("light_golden_leaks", "Vintage Light Leaks", "Lọt Sáng Phim Nhựa", "Light", "☀️", false));
        ALL_EFFECTS.add(new EffectItem("light_film_halation", "Red Film Halation 35mm", "Quầng Sáng Đỏ Halation", "Light", "🔴", true));

        // 5. Face Mesh & AR Beauty / Làm Đẹp & AR Khuôn Mặt 468 Điểm
        ALL_EFFECTS.add(new EffectItem("face_smooth_ai", "AI Smooth Skin 4K", "Làm Mịn Da AI Tự Nhiên", "FaceAR", "💆", false));
        ALL_EFFECTS.add(new EffectItem("face_vline_slim", "V-Line Slim Face Morph", "Thon Gọn Mặt V-Line", "FaceAR", "💎", false));
        ALL_EFFECTS.add(new EffectItem("face_big_eyes", "Natural Big Eyes", "Phóng To Mắt Tự Nhiên", "FaceAR", "👀", false));
        ALL_EFFECTS.add(new EffectItem("ar_cyber_mask", "3D Cybernetic Face Mask", "Mặt Nạ Robot Cyberpunk 3D", "FaceAR", "🤖", true));
        ALL_EFFECTS.add(new EffectItem("ar_virtual_glasses", "Ray-Ban Virtual Glasses AR", "Kính Mắt AR Thời Trang", "FaceAR", "🕶️", false));

        // 6. Body Pose & Neon Glow / Dáng Người 33 Điểm & Tách Nền
        ALL_EFFECTS.add(new EffectItem("body_ai_matting", "AI Green-Screen-Free Matting", "Tách Nền Không Phông Xanh", "BodyMesh", "✂️", true));
        ALL_EFFECTS.add(new EffectItem("body_neon_contour", "Neon Body Contour Glow", "Viền Sáng Phát Quang Cơ Thể", "BodyMesh", "🕺", false));
        ALL_EFFECTS.add(new EffectItem("body_ghost_clone", "Ghost Clone Motion Trail", "Phân Thân Vệt Bóng Chuyển Động", "BodyMesh", "👥", true));
        ALL_EFFECTS.add(new EffectItem("body_energy_wings", "3D Neon Energy Wings", "Cánh Thiên Thần Neon 3D", "BodyMesh", "🪽", true));

        // 7. Stickers & Kinetic 3D Typography / Nhãn Dán & Chữ 3D
        ALL_EFFECTS.add(new EffectItem("stk_fire_3d", "3D Fire Explosion Emoji", "Nhãn Dán Ngọn Lửa 3D", "Sticker", "🔥", false));
        ALL_EFFECTS.add(new EffectItem("stk_neon_sub", "Neon Pulsating Subscribe", "Nút Đăng Ký Phát Sáng Neon", "Sticker", "🔔", false));
        ALL_EFFECTS.add(new EffectItem("txt_kinetic_typewriter", "Kinetic Typewriter Motion", "Chữ Đánh Máy Động Học", "Sticker", "⌨️", false));
        ALL_EFFECTS.add(new EffectItem("txt_3d_extrude_neon", "3D Extruded Glow Text", "Chữ Nổi 3D Phát Sáng Viền", "Sticker", "🔤", true));

        // 8. Authentic OpenCut Native Resource Effects / Kho Tài Nguyên Hiệu Ứng Gốc OpenCut (Engine & GLSL Shaders)
        ALL_EFFECTS.add(new EffectItem("opencut_spin", "OpenCut Spin Transition GLSL", "Xoay Chuyển Cảnh OpenCut Gốc", "OpenCutNative", "🌀", false, "capcut/shaders/spin_frag.glsl"));
        ALL_EFFECTS.add(new EffectItem("opencut_hexagon_zoom", "OpenCut Hexagon Zoom GLSL", "Thu Phóng Lục Giác OpenCut Gốc", "OpenCutNative", "⬡", false, "capcut/shaders/hexagon_zoom_frag.glsl"));
        ALL_EFFECTS.add(new EffectItem("opencut_chroma_v1370", "OpenCut Chroma V1370 Shader", "Khóa Phông Chroma V1370 Gốc", "OpenCutNative", "🟢", false, "capcut/shaders/chromakey.frag"));
        ALL_EFFECTS.add(new EffectItem("opencut_smooth_beauty", "OpenCut Smooth Beauty GLSL", "Làm Mịn Da Beauty Gốc OpenCut", "OpenCutNative", "💆", false, "capcut/shaders/beauty_smooth.frag"));
        ALL_EFFECTS.add(new EffectItem("opencut_face_reshape", "OpenCut FaceReshape V2 Distortion", "Biến Dạng Mặt FaceReshape V2", "OpenCutNative", "👤", true, "capcut/effects/FaceReshape_V2/distortion.json"));
        ALL_EFFECTS.add(new EffectItem("opencut_curves", "OpenCut Curves Color Grading", "Đường Cong Màu Curves OpenCut", "OpenCutNative", "📈", false, "capcut/effects/curves/content.json"));
        ALL_EFFECTS.add(new EffectItem("opencut_hsl", "OpenCut HSL Master Engine", "Bộ Màu HSL Chuyên Nghiệp OpenCut", "OpenCutNative", "🌈", true, "capcut/effects/hsl_v1/content.json"));
        ALL_EFFECTS.add(new EffectItem("opencut_star_shining", "OpenCut Star Shining FX", "Ngôi Sao Lấp Lánh Gốc OpenCut", "OpenCutNative", "✨", false, "capcut/lottie/star_shining.json"));
        ALL_EFFECTS.add(new EffectItem("opencut_particle_glow", "OpenCut Particle Glow VFX", "Hạt Phát Sáng Hào Quang OpenCut", "OpenCutNative", "💫", true, "capcut/effects/particle/content.json"));
        ALL_EFFECTS.add(new EffectItem("opencut_matting_koutu", "OpenCut Koutu Smart Matting", "Tách Nền Thông Minh Koutu Gốc", "OpenCutNative", "✂️", true, "capcut/lottie/koutu.json"));

        // 9. GlitchCam & YouCut Glitch Shaders / Hiệu Ứng Glitch & VHS Chuyên Nghiệp
        ALL_EFFECTS.add(new EffectItem("glitch_rgb_split", "RGB Chromatic Split 3D", "Tách Lớp Màu RGB Động", "GlitchVHS", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("glitch_vhs_1998", "Retro VHS 1998 Camcorder", "Băng Từ Cổ Điển VHS 1998", "GlitchVHS", "📼", false));
        ALL_EFFECTS.add(new EffectItem("glitch_matrix_cyber", "Cyber Matrix Rain Scan", "Ma Trận Mã Số Xanh Cyber", "GlitchVHS", "🟩", true));
        ALL_EFFECTS.add(new EffectItem("glitch_trippy_wave", "Psychedelic Acid Wave", "Sóng Biến Dạng Trippy", "GlitchVHS", "🌊", false));
        ALL_EFFECTS.add(new EffectItem("glitch_beat_shake", "Bass Drop Beat Shake", "Rung Lắc Giật Theo Bass", "GlitchVHS", "💥", true));
        ALL_EFFECTS.add(new EffectItem("glitch_neon_scanline", "Neon CRT Scanlines", "Vệt Quét Tia Neon CRT", "GlitchVHS", "📺", false));

        // 10. Adobe Lightroom Tone Curves & Detail Optics / Chỉnh Ảnh Điện Ảnh Lightroom Pro
        ALL_EFFECTS.add(new EffectItem("lr_tone_curve_rgb", "Lightroom Parametric RGB Curve", "Đường Cong Sắc Thái RGB", "LightroomPro", "📈", true));
        ALL_EFFECTS.add(new EffectItem("lr_clarity_boost", "Micro-Contrast Clarity Boost", "Độ Rõ Nét & Chi Tiết Vi Mô", "LightroomPro", "🔍", false));
        ALL_EFFECTS.add(new EffectItem("lr_dehaze_fog", "Atmospheric Dehaze Defogger", "Xóa Mù Sương Khí Quyển", "LightroomPro", "🌫️", false));
        ALL_EFFECTS.add(new EffectItem("lr_film_grain", "Vintage Analogue Film Grain", "Hạt Phim Cổ Điển 35mm", "LightroomPro", "🎞️", false));
        ALL_EFFECTS.add(new EffectItem("lr_vignette_lens", "Optical Lens Vignetting", "Tối Góc Ống Kính Quang Học", "LightroomPro", "🌑", false));

        // 11. AI Portrait, Retouch & Morphing (Facetune, Meitu, FaceApp, SnapEdit) / Chân Dung VIP & Biến Hóa AI
        ALL_EFFECTS.add(new EffectItem("ft_teeth_whitening", "Facetune 3D Teeth Whitening", "Làm Trắng Răng Facetune", "PortraitVIP", "🦷", false));
        ALL_EFFECTS.add(new EffectItem("ft_eye_brightening", "Facetune Eye Glow Brighten", "Làm Sáng Mắt Facetune", "PortraitVIP", "👁️", false));
        ALL_EFFECTS.add(new EffectItem("ft_lipstick_tint", "Facetune Satin Lipstick Tint", "Tô Son Môi Mịn Lì", "PortraitVIP", "💄", false));
        ALL_EFFECTS.add(new EffectItem("meitu_leg_lengthen", "Meitu AI Leg Lengthening", "Kéo Dài Chân Chuẩn Tỷ Lệ", "PortraitVIP", "👠", true));
        ALL_EFFECTS.add(new EffectItem("meitu_bling_glitter", "Meitu Sparkle Bling Glitter", "Kim Tuyến Lấp Lánh Meitu", "PortraitVIP", "✨", false));
        ALL_EFFECTS.add(new EffectItem("faceapp_smile_ai", "FaceApp Radiant Smile Generator", "Nụ Cười Rạng Rỡ AI", "MorphingAI", "😄", true));
        ALL_EFFECTS.add(new EffectItem("faceapp_youth_18", "FaceApp Youth 18 Age Filter", "Trẻ Hóa Tuổi 18 Tự Nhiên", "MorphingAI", "👶", true));
        ALL_EFFECTS.add(new EffectItem("faceapp_hairstyle_switch", "FaceApp Hairstyle Switcher", "Đổi Kiểu Tóc Thời Thượng", "MorphingAI", "💇", false));
        ALL_EFFECTS.add(new EffectItem("snapedit_inpaint_eraser", "SnapEdit AI Inpaint Eraser", "Cọ Xóa Vật Thể Thừa SnapEdit", "EraserAI", "🧹", true));
        ALL_EFFECTS.add(new EffectItem("snapedit_sky_sunset", "SnapEdit Sky Sunset Gold", "Thay Bầu Trời Hoàng Hôn", "EraserAI", "🌅", false));
        ALL_EFFECTS.add(new EffectItem("snapedit_sky_aurora", "SnapEdit Sky Aurora Borealis", "Thay Bầu Trời Cực Quang", "EraserAI", "🌌", true));

        // 12. Inter-Clip Transitions / Hiệu Ứng Chuyển Cảnh Chuẩn CapCut
        ALL_EFFECTS.add(new EffectItem("trans_dissolve", "Cross Dissolve", "Mờ Dần", "Transition", "🌫️", false));
        ALL_EFFECTS.add(new EffectItem("trans_fade_black", "Fade to Black", "Mờ Đen", "Transition", "⬛", false));
        ALL_EFFECTS.add(new EffectItem("trans_flash_white", "Flash White Strobe", "Chớp Sáng Trắng", "Transition", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("trans_slide_left", "Slide Left Wipe", "Trượt Sang Trái", "Transition", "⬅️", false));
        ALL_EFFECTS.add(new EffectItem("trans_slide_right", "Slide Right Wipe", "Trượt Sang Phải", "Transition", "➡️", false));
        ALL_EFFECTS.add(new EffectItem("trans_zoom_in", "Dynamic Zoom In", "Thu Phóng Đi Vào", "Transition", "🔍", false));
        ALL_EFFECTS.add(new EffectItem("trans_zoom_out", "Dynamic Zoom Out", "Thu Phóng Đi Ra", "Transition", "🔎", false));
        ALL_EFFECTS.add(new EffectItem("trans_film_leak", "35mm Film Light Leak", "Rò Rỉ Sáng Phim 35mm", "Transition", "🎞️", false));
        ALL_EFFECTS.add(new EffectItem("trans_glitch_rgb", "RGB Chromatic Split", "Xé Hình Glitch RGB", "Transition", "📺", false));
        ALL_EFFECTS.add(new EffectItem("trans_strobe", "Strobe Beat Flash", "Nhấp Nháy Nhịp Bass", "Transition", "💥", false));

        // 13. Clip Animations / Hoạt Ảnh Clip Vào, Ra và Kết Hợp
        ALL_EFFECTS.add(new EffectItem("anim_in_fade", "Fade In", "Mờ Dần Vào", "Animation", "🌅", false));
        ALL_EFFECTS.add(new EffectItem("anim_in_zoom", "Zoom In Elastic", "Phóng To Đàn Hồi", "Animation", "💥", false));
        ALL_EFFECTS.add(new EffectItem("anim_in_slide_right", "Slide In Right", "Trượt Vào Từ Phải", "Animation", "⏩", false));
        ALL_EFFECTS.add(new EffectItem("anim_in_flip_up", "3D Flip Up", "Lật Lên 3D", "Animation", "🔄", false));
        ALL_EFFECTS.add(new EffectItem("anim_in_shake", "Dynamic Beat Shake", "Rung Lắc Nhịp Phách", "Animation", "📳", false));
        ALL_EFFECTS.add(new EffectItem("anim_out_fade", "Fade Out", "Mờ Dần Ra", "Animation", "🌇", false));
        ALL_EFFECTS.add(new EffectItem("anim_out_zoom", "Zoom Out Fade", "Thu Nhỏ Biến Mất", "Animation", "📉", false));
        ALL_EFFECTS.add(new EffectItem("anim_out_slide_down", "Slide Down", "Trượt Rơi Xuống", "Animation", "🔽", false));
        ALL_EFFECTS.add(new EffectItem("anim_combo_3d_spin", "3D Spin Whirl", "Xoay Tròn 3D Đa Trục", "Animation", "🌀", false));
        ALL_EFFECTS.add(new EffectItem("anim_combo_pendulum", "Pendulum Harmonic Swing", "Con Lắc Đung Đưa", "Animation", "⏱️", false));

        // 14. Smart Cutout Strokes (AI Matting) / Viền Nét Tách Phông Thông Minh
        ALL_EFFECTS.add(new EffectItem("stroke_neon", "Neon Cyan Glow Stroke", "Viền Phát Sáng Neon", "SmartStroke", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("stroke_dot_dash", "Fashion Dot Dash Stroke", "Viền Nét Đứt Thời Trang", "SmartStroke", "••", false));
        ALL_EFFECTS.add(new EffectItem("stroke_glow", "Soft Radiant Glow Stroke", "Viền Hào Quang Mịn", "SmartStroke", "✨", false));
        ALL_EFFECTS.add(new EffectItem("stroke_shadow", "3D Depth Drop Shadow", "Bóng Đổ Chiều Sâu 3D", "SmartStroke", "👥", false));

        // 15. Audio DSP Suite / Bộ Xử Lý m Thanh & Tách Giọng DSP
        ALL_EFFECTS.add(new EffectItem("dsp_noise_reduction", "DSP Dynamic Noise Suppression", "Khử Ồn DSP Động", "AudioDSP", "🔇", false));
        ALL_EFFECTS.add(new EffectItem("dsp_vocal_isolation", "AI Neural Vocal Extractor", "Tách Giọng Nói AI", "AudioDSP", "🎤", true));
        ALL_EFFECTS.add(new EffectItem("dsp_karaoke_remover", "AI Instrumental Karaoke Maker", "Tách Nhạc Nền Karaoke", "AudioDSP", "🎼", true));

        // 16. Speed Curve Bezier Presets / Bộ Preset Tốc Độ Đường Cong Bezier
        ALL_EFFECTS.add(new EffectItem("curve_montage", "Montage Curve (Fast-Slow-Fast)", "Đường Cong Montage (Nhanh-Chậm-Nhanh)", "SpeedCurve", "🌀", false));
        ALL_EFFECTS.add(new EffectItem("curve_bullet", "Bullet Time Curve (0.1x Ultra Slow)", "Đường Cong Bullet Time (0.1x Cực Chậm)", "SpeedCurve", "🎯", false));
        ALL_EFFECTS.add(new EffectItem("curve_hero", "Hero Cinematic Curve", "Đường Cong Hero Điện Ảnh", "SpeedCurve", "🚀", false));
        ALL_EFFECTS.add(new EffectItem("curve_flash_in", "Flash In Acceleration Curve", "Đường Cong Flash In Tăng Tốc", "SpeedCurve", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("curve_jump_cut", "Jump Cut Rhythm Curve", "Đường Cong Nhịp Điệu Jump Cut", "SpeedCurve", "✂️", false));

        // 17. Cover Frame Templates / Mẫu Ảnh Bìa CapCut
        ALL_EFFECTS.add(new EffectItem("cover_minimalist_bottom", "Minimalist Bottom Bar", "Thanh Đáy Tối Giản", "CoverTemplate", "📑", false));
        ALL_EFFECTS.add(new EffectItem("cover_bold_center", "Bold Center Hero Frame", "Khung Giữa Nổi Bật", "CoverTemplate", "🔲", false));
        ALL_EFFECTS.add(new EffectItem("cover_tiktok_trending", "TikTok Trending Tag", "Nhãn TikTok Xu Hướng", "CoverTemplate", "🔥", false));
        ALL_EFFECTS.add(new EffectItem("cover_cinematic_card", "Cinematic Title Card", "Thẻ Tiêu Đề Điện Ảnh", "CoverTemplate", "🎬", false));

        // 18. Word-By-Word Karaoke Captions / Phụ Đề Nhảy Chữ Từng Từ Karaoke
        ALL_EFFECTS.add(new EffectItem("karaoke_gold_glow", "Gold Glow Word Highlight", "Karaoke Vàng Rực Hào Quang", "KaraokeStyle", "🌟", false));
        ALL_EFFECTS.add(new EffectItem("karaoke_neon_cyan", "TikTok Neon Cyan Pulse", "Nhịp Đập Xanh Neon TikTok", "KaraokeStyle", "⚡", false));
        ALL_EFFECTS.add(new EffectItem("karaoke_box_highlight", "Black Box White Text", "Hộp Đen Nền Chữ Trắng", "KaraokeStyle", "🔲", false));
        ALL_EFFECTS.add(new EffectItem("karaoke_bouncy_popup", "Dynamic Bouncy Scale", "Chữ Nảy Bật Phóng To", "KaraokeStyle", "💥", false));
    }

    public static List<EffectItem> getAllEffects() {
        return new ArrayList<>(ALL_EFFECTS);
    }

    public static List<EffectItem> getTransitions() {
        return getEffectsByCategory("Transition");
    }

    public static List<EffectItem> getClipAnimations() {
        return getEffectsByCategory("Animation");
    }

    public static List<EffectItem> getSmartStrokes() {
        return getEffectsByCategory("SmartStroke");
    }

    public static List<EffectItem> getAudioDspEffects() {
        return getEffectsByCategory("AudioDSP");
    }

    public static List<EffectItem> getSpeedCurves() {
        return getEffectsByCategory("SpeedCurve");
    }

    public static List<EffectItem> getCoverTemplates() {
        return getEffectsByCategory("CoverTemplate");
    }

    public static List<EffectItem> getKaraokeStyles() {
        return getEffectsByCategory("KaraokeStyle");
    }

    public static List<EffectItem> getEffectsByCategory(String category) {
        List<EffectItem> filtered = new ArrayList<>();
        for (EffectItem item : ALL_EFFECTS) {
            if (item.category.equalsIgnoreCase(category)) {
                filtered.add(item);
            }
        }
        return filtered;
    }

    /**
     * Read Authentic CapCut Asset / Đọc tài nguyên tệp gốc CapCut từ thư mục assets
     */
    public static String readAssetString(android.content.Context context, String assetPath) {
        if (context == null || assetPath == null || assetPath.isEmpty()) return "";
        try {
            java.io.InputStream is = context.getAssets().open(assetPath);
            int size = is.available();
            byte[] buffer = new byte[size];
            is.read(buffer);
            is.close();
            return new String(buffer, "UTF-8");
        } catch (Exception e) {
            return "";
        }
    }

    /**
     * Check if Asset exists in app bundle / Kiểm tra tài nguyên có tồn tại trong APK
     */
    public static boolean hasAsset(android.content.Context context, String assetPath) {
        if (context == null || assetPath == null || assetPath.isEmpty()) return false;
        try {
            java.io.InputStream is = context.getAssets().open(assetPath);
            is.close();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    /**
     * Lightroom Pro Tone Curves & Optics ColorMatrix
     * Tính toán ma trận màu cho Adobe Lightroom Mobile Pro (Clarity, Dehaze, Grain, Vignette)
     */
    public static android.graphics.ColorMatrix getLightroomMatrix(float clarity, float dehaze, float grain, float vignette) {
        android.graphics.ColorMatrix cm = new android.graphics.ColorMatrix();
        // Base contrast & clarity boost / Tăng cường tương phản vi mô
        float cScale = 1.0f + (clarity / 200.0f);
        float dScale = 1.0f + (dehaze / 250.0f);
        float totalScale = cScale * dScale;
        float offset = (1.0f - totalScale) * 128.0f;

        // Film grain warmth & tint / Hạt phim và ánh ấm
        float warmR = 1.0f + (grain / 500.0f);
        float coolB = 1.0f - (grain / 600.0f);

        // Vignette edge darkness factor / Tối góc quang học
        float vFactor = 1.0f - (vignette / 400.0f);

        float[] matrix = new float[] {
            totalScale * warmR * vFactor, 0, 0, 0, offset + (grain * 0.1f),
            0, totalScale * vFactor, 0, 0, offset,
            0, 0, totalScale * coolB * vFactor, 0, offset - (grain * 0.05f),
            0, 0, 0, 1.0f, 0
        };
        cm.set(matrix);
        return cm;
    }

    /**
     * Facetune & Meitu Portrait Retouch ColorMatrix
     * Tính toán ma trận làm sáng mắt, trắng răng, tô son, kim tuyến, kéo chân
     */
    public static android.graphics.ColorMatrix getPortraitRetouchMatrix(String feature) {
        android.graphics.ColorMatrix cm = new android.graphics.ColorMatrix();
        if (feature == null) return cm;

        if ("teeth_whitening".equalsIgnoreCase(feature) || "whitening".equalsIgnoreCase(feature)) {
            // Processed locally via FaceBodyDetectionEngine / Xử lý cục bộ qua FaceBodyDetectionEngine
            return cm;
        } else if ("eye_brightening".equalsIgnoreCase(feature) || "brighten_eyes".equalsIgnoreCase(feature)) {
            // Processed locally via FaceBodyDetectionEngine / Xử lý cục bộ qua FaceBodyDetectionEngine
            return cm;
        } else if ("lipstick_tint".equalsIgnoreCase(feature) || "lipstick".equalsIgnoreCase(feature)) {
            // Processed locally via FaceBodyDetectionEngine / Xử lý cục bộ qua FaceBodyDetectionEngine
            // Neutral matrix to avoid red tinting whole photo / Ma trận trung tính tránh nhuộm đỏ toàn bộ ảnh
            return cm;
        } else if ("meitu_bling".equalsIgnoreCase(feature) || "bling_bling".equalsIgnoreCase(feature)) {
            // Sparkle bling glow / Kim tuyến lấp lánh Meitu
            float[] m = new float[] {
                1.25f, 0, 0, 0, 30,
                0, 1.25f, 0, 0, 30,
                0, 0, 1.35f, 0, 40,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        } else if ("slim_legs".equalsIgnoreCase(feature) || "meitu_legs".equalsIgnoreCase(feature)) {
            // Silhouette & warm contouring / Tôn dáng thon gọn & tạo khối cơ thể
            float[] m = new float[] {
                1.10f, 0, 0, 0, 12,
                0, 1.08f, 0, 0, 8,
                0, 0, 1.02f, 0, 2,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        }
        return cm;
    }

    /**
     * FaceApp AI Morphing ColorMatrix (Smile, Youth 18, Hair)
     * Bộ lọc màu biến hóa khuôn mặt AI
     */
    public static android.graphics.ColorMatrix getFaceAppMatrix(String morphType) {
        android.graphics.ColorMatrix cm = new android.graphics.ColorMatrix();
        if (morphType == null) return cm;

        if ("smile".equalsIgnoreCase(morphType) || "classic_smile".equalsIgnoreCase(morphType)) {
            // Radiant warm glowing smile / Nụ cười rạng rỡ tỏa sáng
            float[] m = new float[] {
                1.12f, 0, 0, 0, 15,
                0, 1.08f, 0, 0, 10,
                0, 0, 1.0f, 0, 0,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        } else if ("youth".equalsIgnoreCase(morphType) || "youth_18".equalsIgnoreCase(morphType) || "young".equalsIgnoreCase(morphType)) {
            // Soft rosy skin youth 18 / Làn da hồng hào trẻ hóa tuổi 18
            float[] m = new float[] {
                1.15f, 0, 0, 0, 20,
                0, 1.10f, 0, 0, 15,
                0, 0, 1.18f, 0, 12,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        } else if ("hair".equalsIgnoreCase(morphType) || "volumetric_hair".equalsIgnoreCase(morphType) || "brunette".equalsIgnoreCase(morphType)) {
            // Rich deep brunette hair contrast / Tóc nâu socola thời thượng
            float[] m = new float[] {
                1.05f, 0, 0, 0, 5,
                0, 1.0f, 0, 0, 0,
                0, 0, 0.95f, 0, -8,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        }
        return cm;
    }

    /**
     * SnapEdit Sky Replacement ColorMatrix (Sunset, Aurora, BlueSky)
     * Ma trận ánh sáng môi trường khi thay bầu trời AI
     */
    public static android.graphics.ColorMatrix getSnapEditSkyMatrix(String skyType) {
        android.graphics.ColorMatrix cm = new android.graphics.ColorMatrix();
        if (skyType == null) return cm;

        if ("sunset".equalsIgnoreCase(skyType)) {
            // Sunset Golden & Magenta / Hoàng hôn vàng cam hồng
            float[] m = new float[] {
                1.35f, 0, 0, 0, 30,
                0, 1.05f, 0, 0, 10,
                0, 0, 0.85f, 0, -15,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        } else if ("aurora".equalsIgnoreCase(skyType)) {
            // Aurora Borealis Neon Green & Purple / Cực quang xanh ngọc và tím
            float[] m = new float[] {
                0.9f, 0, 0, 0, -5,
                0, 1.3f, 0, 0, 25,
                0, 0, 1.35f, 0, 30,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        } else if ("bluesky".equalsIgnoreCase(skyType) || "blue_sky".equalsIgnoreCase(skyType) || "clear_sky".equalsIgnoreCase(skyType)) {
            // Clear Azure Blue Sky / Bầu trời xanh biếc trong vắt
            float[] m = new float[] {
                0.95f, 0, 0, 0, 0,
                0, 1.1f, 0, 0, 12,
                0, 0, 1.4f, 0, 35,
                0, 0, 0, 1.0f, 0
            };
            cm.set(m);
        }
        return cm;
    }

    /**
     * GlitchCam & YouCut Shader Snippet
     * Trả về đoạn mã OpenGL ES Shader mô phỏng các hiệu ứng Glitch nổi tiếng
     */
    public static String getGlitchShaderSnippet(String glitchId) {
        if ("glitch_rgb_split".equalsIgnoreCase(glitchId)) {
            return "// GlitchCam RGB Split Shader\n" +
                   "vec2 offset = vec2(0.015 * sin(time * 12.0), 0.0);\n" +
                   "float r = texture2D(uTexture, vTexCoord + offset).r;\n" +
                   "float g = texture2D(uTexture, vTexCoord).g;\n" +
                   "float b = texture2D(uTexture, vTexCoord - offset).b;\n" +
                   "gl_FragColor = vec4(r, g, b, 1.0);";
        } else if ("glitch_vhs_1998".equalsIgnoreCase(glitchId)) {
            return "// GlitchCam VHS 1998 Scanline Shader\n" +
                   "float scanline = sin(vTexCoord.y * 600.0 + time * 10.0) * 0.08;\n" +
                   "vec4 color = texture2D(uTexture, vTexCoord);\n" +
                   "color.rgb -= scanline;\n" +
                   "color.r += 0.05;\n" +
                   "gl_FragColor = color;";
        } else if ("glitch_matrix_cyber".equalsIgnoreCase(glitchId)) {
            return "// GlitchCam Matrix Cyber Stream Shader\n" +
                   "vec4 color = texture2D(uTexture, vTexCoord);\n" +
                   "float greenStream = step(0.9, fract(sin(dot(vTexCoord.xy + time, vec2(12.9898,78.233))) * 43758.5453));\n" +
                   "color.g += greenStream * 0.4;\n" +
                   "gl_FragColor = color;";
        }
        return "// Default Passthrough\ngl_FragColor = texture2D(uTexture, vTexCoord);";
    }
}
