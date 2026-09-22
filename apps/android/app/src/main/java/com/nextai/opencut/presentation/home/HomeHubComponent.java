package com.nextai.opencut.presentation.home;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;

/**
 * HomeHubComponent — Thành Phần Màn Hình Trang Chủ & Điều Hướng Trung Tâm (Home Hub & Central Navigation Component)
 * Bao gồm: Header logo, huy hiệu PRO VIP, thẻ Hero "+ Dự án mới", 8 ô công cụ nhanh (Quick Tools),
 * danh sách bản nháp gần đây (Recent Drafts), và thanh điều hướng đáy 6 Tab (Bottom Navigation).
 *
 * Encapsulates the home landing experience, draft management entry points, quick feature tiles,
 * and decoupling all user actions via {@link OnHomeActionListener}.
 *
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class HomeHubComponent implements View.OnClickListener {

    private final Activity activity;
    private final OnHomeActionListener listener;

    private LinearLayout homeView;
    private View btnVipBadge;
    private View btnHeroNewProject;

    // 8 Quick Tool Tiles
    private View tileCutout;
    private View tileCaptions;
    private View tileHd4k;
    private View tileAiVoice;
    private View tileTextToVideo;
    private View tilePhotoEdit;
    private View tileTrending;
    private View tileFaceBody;

    // Recent Draft Cards
    private View cardDraft1;
    private View cardDraft2;
    private View cardDraft3;

    public HomeHubComponent(Activity activity, OnHomeActionListener listener) {
        this.activity = activity;
        this.listener = listener;
        buildView();
    }

    /**
     * Get root view of the HomeHubComponent
     * Lấy View gốc của màn hình Home để gắn vào ViewGroup cha
     */
    public View getView() {
        return homeView;
    }

    /**
     * Build Home View Layout
     * Dựng toàn bộ cấu trúc giao diện Trang Chủ chuẩn CapCut
     */
    private void buildView() {
        homeView = new LinearLayout(activity);
        homeView.setOrientation(LinearLayout.VERTICAL);
        homeView.setBackgroundColor(Color.parseColor("#000000"));
        homeView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // 1. Top Header (Logo & PRO VIP Badge)
        LinearLayout topHeader = new LinearLayout(activity);
        topHeader.setOrientation(LinearLayout.HORIZONTAL);
        topHeader.setGravity(Gravity.CENTER_VERTICAL);
        topHeader.setPadding(24, 24, 24, 16);
        topHeader.setBackgroundColor(Color.parseColor("#000000"));

        TextView tvLogo = new TextView(activity);
        tvLogo.setText("NextAI OpenCut");
        tvLogo.setTextColor(Color.WHITE);
        tvLogo.setTextSize(18);
        tvLogo.setTypeface(null, Typeface.BOLD);
        topHeader.addView(tvLogo);

        View spacer = new View(activity);
        topHeader.addView(spacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        btnVipBadge = new TextView(activity);
        ((TextView) btnVipBadge).setText("👑 PRO VIP");
        ((TextView) btnVipBadge).setTextColor(Color.parseColor("#EAB308"));
        ((TextView) btnVipBadge).setTextSize(11);
        ((TextView) btnVipBadge).setTypeface(null, Typeface.BOLD);
        btnVipBadge.setBackgroundResource(com.nextai.opencut.R.drawable.bg_vip_badge);
        btnVipBadge.setPadding(20, 8, 20, 8);
        btnVipBadge.setOnClickListener(this);
        topHeader.addView(btnVipBadge);

        homeView.addView(topHeader);

        // 2. Body Scroll View
        ScrollView bodyScroll = new ScrollView(activity);
        bodyScroll.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 0, 1.0f));

        LinearLayout bodyContent = new LinearLayout(activity);
        bodyContent.setOrientation(LinearLayout.VERTICAL);
        bodyContent.setPadding(20, 8, 20, 24);

        // 3. Hero "+ Dự án mới (New Project)" Card
        btnHeroNewProject = new LinearLayout(activity);
        ((LinearLayout) btnHeroNewProject).setOrientation(LinearLayout.VERTICAL);
        ((LinearLayout) btnHeroNewProject).setGravity(Gravity.CENTER);
        btnHeroNewProject.setBackgroundResource(com.nextai.opencut.R.drawable.bg_hero_new_project);
        btnHeroNewProject.setPadding(0, 48, 0, 48);
        LinearLayout.LayoutParams heroParams = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        heroParams.setMargins(0, 8, 0, 24);
        btnHeroNewProject.setLayoutParams(heroParams);

        TextView tvPlus = new TextView(activity);
        tvPlus.setText("+");
        tvPlus.setTextColor(Color.WHITE);
        tvPlus.setTextSize(36);
        tvPlus.setTypeface(null, Typeface.BOLD);
        ((LinearLayout) btnHeroNewProject).addView(tvPlus);

        TextView tvHeroTitle = new TextView(activity);
        tvHeroTitle.setText("Dự án mới (New Project)");
        tvHeroTitle.setTextColor(Color.WHITE);
        tvHeroTitle.setTextSize(16);
        tvHeroTitle.setTypeface(null, Typeface.BOLD);
        tvHeroTitle.setPadding(0, 4, 0, 0);
        ((LinearLayout) btnHeroNewProject).addView(tvHeroTitle);

        btnHeroNewProject.setOnClickListener(this);
        bodyContent.addView(btnHeroNewProject);

        // 4. 8 Quick Tool Tiles (2 rows x 4 cols)
        LinearLayout quickGrid1 = new LinearLayout(activity);
        quickGrid1.setOrientation(LinearLayout.HORIZONTAL);
        quickGrid1.setPadding(0, 0, 0, 12);
        tileCutout = createQuickTile("✂️", "Xóa phông", quickGrid1);
        tileCaptions = createQuickTile("⚡", "Phụ đề AI", quickGrid1);
        tileHd4k = createQuickTile("🎨", "Chất lượng 4K", quickGrid1);
        tileAiVoice = createQuickTile("🎙️", "Giọng đọc AI", quickGrid1);
        bodyContent.addView(quickGrid1);

        LinearLayout quickGrid2 = new LinearLayout(activity);
        quickGrid2.setOrientation(LinearLayout.HORIZONTAL);
        quickGrid2.setPadding(0, 0, 0, 24);
        tileTextToVideo = createQuickTile("🤖", "Text-to-Video", quickGrid2);
        tilePhotoEdit = createQuickTile("🖼️", "Chỉnh sửa ảnh", quickGrid2);
        tileTrending = createQuickTile("🔥", "Mẫu Hot", quickGrid2);
        tileFaceBody = createQuickTile("👤", "Mặt & Thon gọn", quickGrid2);
        bodyContent.addView(quickGrid2);

        // 5. Recent Drafts Header
        TextView tvDraftsTitle = new TextView(activity);
        tvDraftsTitle.setText("BẢN NHÁP GẦN ĐÂY (RECENT DRAFTS)");
        tvDraftsTitle.setTextColor(Color.parseColor("#94A3B8"));
        tvDraftsTitle.setTextSize(11);
        tvDraftsTitle.setTypeface(null, Typeface.BOLD);
        tvDraftsTitle.setPadding(4, 0, 0, 12);
        bodyContent.addView(tvDraftsTitle);

        cardDraft1 = createDraftCard("🌅 Du Lịch Biển Phú Quốc 4K HDR", "00:32", "Đã sửa 10 phút trước • 1080p 60fps", "#0F766E");
        cardDraft2 = createDraftCard("🌲 Chill Acoustic Cà Phê Mưa", "01:15", "Đã sửa 2 giờ trước • 3D LUT Portra", "#1E293B");
        cardDraft3 = createDraftCard("💃 Dance TikTok Beat Sync 2026", "00:15", "Đã sửa hôm qua • Face Mesh 468", "#4C1D95");

        bodyContent.addView(cardDraft1);
        bodyContent.addView(cardDraft2);
        bodyContent.addView(cardDraft3);

        bodyScroll.addView(bodyContent);
        homeView.addView(bodyScroll);

        // 6. Bottom Navigation Bar (6 Tabs)
        homeView.addView(buildBottomNav(0));
    }

    private View createQuickTile(String icon, String label, LinearLayout parent) {
        LinearLayout tile = new LinearLayout(activity);
        tile.setOrientation(LinearLayout.VERTICAL);
        tile.setGravity(Gravity.CENTER);
        tile.setPadding(8, 14, 8, 14);
        tile.setBackgroundResource(com.nextai.opencut.R.drawable.bg_quick_tool_tile);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        params.setMargins(6, 0, 6, 0);
        tile.setLayoutParams(params);

        TextView tvIcon = new TextView(activity);
        tvIcon.setText(icon);
        tvIcon.setTextSize(20);
        tile.addView(tvIcon);

        TextView tvLabel = new TextView(activity);
        tvLabel.setText(label);
        tvLabel.setTextColor(Color.parseColor("#E2E8F0"));
        tvLabel.setTextSize(9);
        tvLabel.setGravity(Gravity.CENTER);
        tvLabel.setPadding(0, 6, 0, 0);
        tile.addView(tvLabel);

        tile.setOnClickListener(this);
        parent.addView(tile);
        return tile;
    }

    private View createDraftCard(String title, String duration, String desc, String colorHex) {
        LinearLayout card = new LinearLayout(activity);
        card.setOrientation(LinearLayout.HORIZONTAL);
        card.setGravity(Gravity.CENTER_VERTICAL);
        card.setPadding(14, 12, 14, 12);
        card.setBackgroundResource(com.nextai.opencut.R.drawable.bg_draft_card);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        params.setMargins(0, 0, 0, 10);
        card.setLayoutParams(params);

        FrameLayout thumb = new FrameLayout(activity);
        thumb.setLayoutParams(new LinearLayout.LayoutParams(110, 80));
        thumb.setBackgroundColor(Color.parseColor(colorHex));

        TextView tvDur = new TextView(activity);
        tvDur.setText(duration);
        tvDur.setTextColor(Color.WHITE);
        tvDur.setTextSize(8);
        tvDur.setBackgroundColor(Color.parseColor("#99000000"));
        tvDur.setPadding(6, 2, 6, 2);
        FrameLayout.LayoutParams durParams = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.BOTTOM | Gravity.END);
        durParams.setMargins(0, 0, 4, 4);
        thumb.addView(tvDur, durParams);
        card.addView(thumb);

        LinearLayout info = new LinearLayout(activity);
        info.setOrientation(LinearLayout.VERTICAL);
        info.setPadding(16, 0, 0, 0);
        LinearLayout.LayoutParams infoParams = new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f);
        info.setLayoutParams(infoParams);

        TextView tvT = new TextView(activity);
        tvT.setText(title);
        tvT.setTextColor(Color.WHITE);
        tvT.setTextSize(12);
        tvT.setTypeface(null, Typeface.BOLD);
        info.addView(tvT);

        TextView tvD = new TextView(activity);
        tvD.setText(desc);
        tvD.setTextColor(Color.parseColor("#94A3B8"));
        tvD.setTextSize(10);
        tvD.setPadding(0, 4, 0, 0);
        info.addView(tvD);
        card.addView(info);

        card.setOnClickListener(this);
        return card;
    }

    /**
     * Build Bottom Navigation Bar (Canonical 5-Tab System)
     * Dựng thanh chuyển 5 tab chức năng dưới đáy đồng bộ toàn hệ thống
     */
    public LinearLayout buildBottomNav(int activeIndex) {
        LinearLayout nav = new LinearLayout(activity);
        nav.setOrientation(LinearLayout.HORIZONTAL);
        nav.setBackgroundResource(com.nextai.opencut.R.drawable.bg_bottom_nav);
        nav.setPadding(8, 12, 8, 16);
        nav.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));

        createNavTab("✂️", "Chỉnh sửa", 0, activeIndex, nav);
        createNavTab("📐", "Mẫu", 1, activeIndex, nav);
        createNavTab("☁️", "Không gian", 2, activeIndex, nav);
        createNavTab("🤖", "AI Lab", 3, activeIndex, nav);
        createNavTab("👤", "Tôi", 4, activeIndex, nav);

        return nav;
    }

    private void createNavTab(String icon, String label, int tabIndex, int activeIndex, LinearLayout parent) {
        LinearLayout tab = new LinearLayout(activity);
        tab.setOrientation(LinearLayout.VERTICAL);
        tab.setGravity(Gravity.CENTER);
        tab.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        tab.setTag(Integer.valueOf(1000 + tabIndex));

        boolean isActive = (tabIndex == activeIndex);

        TextView tvIcon = new TextView(activity);
        tvIcon.setText(icon);
        tvIcon.setTextSize(16);
        tab.addView(tvIcon);

        TextView tvLabel = new TextView(activity);
        tvLabel.setText(label);
        tvLabel.setTextColor(isActive ? Color.parseColor("#00E5FF") : Color.parseColor("#64748B"));
        tvLabel.setTextSize(10);
        tvLabel.setTypeface(null, isActive ? Typeface.BOLD : Typeface.NORMAL);
        tvLabel.setPadding(0, 2, 0, 0);
        tab.addView(tvLabel);

        tab.setOnClickListener(this);
        parent.addView(tab);
    }

    @Override
    public void onClick(View v) {
        if (v == btnHeroNewProject) {
            if (listener != null) listener.onNewProject();
            return;
        }

        if (v == btnVipBadge) {
            if (listener != null) listener.onVipBadge();
            return;
        }

        // Quick tools
        if (v == tileCutout) {
            if (listener != null) listener.onQuickTool("cutout", "Xóa phông");
        } else if (v == tileCaptions) {
            if (listener != null) listener.onQuickTool("captions", "Phụ đề AI");
        } else if (v == tileHd4k) {
            if (listener != null) listener.onQuickTool("hd4k", "Chất lượng 4K");
        } else if (v == tileAiVoice) {
            if (listener != null) listener.onQuickTool("aivoice", "Giọng đọc AI");
        } else if (v == tileTextToVideo) {
            if (listener != null) listener.onQuickTool("text2video", "Text-to-Video");
        } else if (v == tilePhotoEdit) {
            if (listener != null) listener.onQuickTool("photoedit", "Chỉnh sửa ảnh");
        } else if (v == tileTrending) {
            if (listener != null) listener.onQuickTool("trending", "Mẫu Hot");
        } else if (v == tileFaceBody) {
            if (listener != null) listener.onQuickTool("facebody", "Mặt & Thon gọn");
        }

        // Drafts
        if (v == cardDraft1) {
            if (listener != null) listener.onDraft(0, "🌅 Du Lịch Biển Phú Quốc 4K HDR");
        } else if (v == cardDraft2) {
            if (listener != null) listener.onDraft(1, "🌲 Chill Acoustic Cà Phê Mưa");
        } else if (v == cardDraft3) {
            if (listener != null) listener.onDraft(2, "💃 Dance TikTok Beat Sync 2026");
        }

        // Bottom Nav Tabs (Tag 1000 - 1004)
        Object tag = v.getTag();
        if (tag instanceof Integer) {
            int tagVal = (Integer) tag;
            if (tagVal >= 1000 && tagVal <= 1004) {
                if (listener != null) {
                    listener.onBottomNav(tagVal - 1000);
                }
            }
        }
    }
}
