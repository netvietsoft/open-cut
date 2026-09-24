package com.nextai.opencut.presentation.templates;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.HorizontalScrollView;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import com.nextai.opencut.presentation.navigation.BottomNavComponent;

/**
 * CapCut-Style Template Component / Màn Hình Mẫu Hot Trending & CutSame CapCut
 * NextAI OpenCut Architecture Standard V2.1
 */
public class TemplateComponent implements View.OnClickListener, BottomNavComponent.OnTabSelectListener {

    public interface OnTemplateActionListener {
        void onApplyTemplate(int index, String title, String duration, String lut, String effect);
        void onTabSelected(int tabIndex);
    }

    private final Context context;
    private final OnTemplateActionListener listener;
    private LinearLayout templateView;
    private BottomNavComponent bottomNavComponent;

    public TemplateComponent(Context context, OnTemplateActionListener listener) {
        this.context = context;
        this.listener = listener;
        this.bottomNavComponent = new BottomNavComponent(context, this);
    }

    @Override
    public void onTabSelected(int tabIndex) {
        if (listener != null) {
            listener.onTabSelected(tabIndex);
        }
    }

    public View getView() {
        if (templateView == null) {
            buildView();
        }
        return templateView;
    }

    private void buildView() {
        templateView = new LinearLayout(context);
        templateView.setOrientation(LinearLayout.VERTICAL);
        templateView.setBackgroundColor(Color.parseColor("#0D0E12"));
        templateView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        // Header with Title & Search Bar / Tiêu đề và Thanh tìm kiếm mẫu
        LinearLayout header = new LinearLayout(context);
        header.setOrientation(LinearLayout.VERTICAL);
        header.setPadding(24, 28, 24, 12);

        TextView tvTitle = new TextView(context);
        tvTitle.setText("📐 MẪU HOT TRENDING (TEMPLATES)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(17);
        tvTitle.setTypeface(null, Typeface.BOLD);
        header.addView(tvTitle);

        TextView tvSearch = new TextView(context);
        tvSearch.setText("🔍 Tìm kiếm mẫu OpenCut, beat sync, giật giật...");
        tvSearch.setTextColor(Color.parseColor("#64748B"));
        tvSearch.setTextSize(11);
        tvSearch.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_search_bar);
        tvSearch.setPadding(20, 10, 20, 10);
        LinearLayout.LayoutParams sp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        sp.topMargin = 12;
        tvSearch.setLayoutParams(sp);
        header.addView(tvSearch);

        // Category Pills Row / Hàng nhãn danh mục mẫu
        HorizontalScrollView catScroll = new HorizontalScrollView(context);
        catScroll.setHorizontalScrollBarEnabled(false);
        catScroll.setPadding(0, 12, 0, 4);

        LinearLayout catRow = new LinearLayout(context);
        catRow.setOrientation(LinearLayout.HORIZONTAL);
        createCategoryPill("🔥 Thịnh hành", true, catRow);
        createCategoryPill("⚡ Giật giật Beat", false, catRow);
        createCategoryPill("🎬 Cinematic Vlog", false, catRow);
        createCategoryPill("✨ Tình cảm", false, catRow);
        createCategoryPill("💃 Nhạc nhảy Dance", false, catRow);
        catScroll.addView(catRow);
        header.addView(catScroll);

        templateView.addView(header);

        // Scrollable Template Cards Feed / Danh sách cuộn các thẻ mẫu
        ScrollView scroll = new ScrollView(context);
        scroll.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 0, 1.0f));

        LinearLayout cardList = new LinearLayout(context);
        cardList.setOrientation(LinearLayout.VERTICAL);
        cardList.setPadding(20, 4, 20, 20);

        createTemplateFeedCard("🔥 Beat Sync TikTok Drop 120BPM", "NextAI Pro Creator", "1.4M lượt dùng • 3 clips • Phách nhạc giật giật", "#7C2D12", 0, cardList);
        createTemplateFeedCard("🎬 Cinematic Vlog Chill Đà Lạt", "Studio Cinematic", "980K lượt dùng • 3 clips • 3D LUT Portra 400", "#1E293B", 1, cardList);
        createTemplateFeedCard("✨ Neon Glow Silhouette Cyberpunk", "VFX Master", "2.3M lượt dùng • 2 clips • Body Tracking AI", "#831843", 2, cardList);
        createTemplateFeedCard("🌸 Kỷ Niệm Mùa Hè Rực Rỡ", "Memory Lane", "750K lượt dùng • 4 clips • Vintage Film Leak", "#065F46", 3, cardList);

        scroll.addView(cardList);
        templateView.addView(scroll);

        // Bottom Navigation / Thanh điều hướng đáy
        templateView.addView(bottomNavComponent.buildView(1));
    }

    private View createCategoryPill(String title, boolean isSelected, LinearLayout parent) {
        TextView pill = new TextView(context);
        pill.setText(title);
        pill.setTextColor(isSelected ? Color.parseColor("#00E5FF") : Color.WHITE);
        pill.setTextSize(11);
        pill.setTypeface(null, isSelected ? Typeface.BOLD : Typeface.NORMAL);
        pill.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_tab_pill);
        pill.setPadding(24, 10, 24, 10);
        LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        lp.setMargins(0, 0, 12, 0);
        pill.setLayoutParams(lp);
        parent.addView(pill);
        return pill;
    }

    private void createTemplateFeedCard(String title, String author, String stats, String colorHex, int templateIdx, LinearLayout parent) {
        LinearLayout card = new LinearLayout(context);
        card.setOrientation(LinearLayout.VERTICAL);
        card.setBackgroundColor(Color.parseColor("#151620"));
        card.setPadding(20, 16, 20, 16);
        LinearLayout.LayoutParams clp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        clp.setMargins(0, 0, 0, 16);
        card.setLayoutParams(clp);

        // Thumbnail Box
        FrameLayout thumbBox = new FrameLayout(context);
        thumbBox.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, 260));
        thumbBox.setBackgroundColor(Color.parseColor(colorHex));

        TextView tvPlayIcon = new TextView(context);
        tvPlayIcon.setText("▶");
        tvPlayIcon.setTextColor(Color.WHITE);
        tvPlayIcon.setTextSize(28);
        thumbBox.addView(tvPlayIcon, new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.CENTER));

        TextView tvDurBadge = new TextView(context);
        tvDurBadge.setText("00:15");
        tvDurBadge.setTextColor(Color.WHITE);
        tvDurBadge.setTextSize(10);
        tvDurBadge.setBackgroundColor(Color.parseColor("#CC000000"));
        tvDurBadge.setPadding(12, 4, 12, 4);
        FrameLayout.LayoutParams dlp = new FrameLayout.LayoutParams(
            FrameLayout.LayoutParams.WRAP_CONTENT, FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.BOTTOM | Gravity.END);
        dlp.setMargins(0, 0, 12, 12);
        thumbBox.addView(tvDurBadge, dlp);
        card.addView(thumbBox);

        // Info
        TextView tvCardTitle = new TextView(context);
        tvCardTitle.setText(title);
        tvCardTitle.setTextColor(Color.WHITE);
        tvCardTitle.setTextSize(13);
        tvCardTitle.setTypeface(null, Typeface.BOLD);
        tvCardTitle.setPadding(0, 12, 0, 4);
        card.addView(tvCardTitle);

        TextView tvCardAuthor = new TextView(context);
        tvCardAuthor.setText("Tác giả: " + author + " • " + stats);
        tvCardAuthor.setTextColor(Color.parseColor("#94A3B8"));
        tvCardAuthor.setTextSize(10);
        tvCardAuthor.setPadding(0, 0, 0, 12);
        card.addView(tvCardAuthor);

        // CutSame Action Button
        TextView btnCutSame = new TextView(context);
        btnCutSame.setText("⚡ SỬ DỤNG MẪU (CUTSAME)");
        btnCutSame.setTextColor(Color.BLACK);
        btnCutSame.setTextSize(11);
        btnCutSame.setTypeface(null, Typeface.BOLD);
        btnCutSame.setGravity(Gravity.CENTER);
        btnCutSame.setBackgroundResource(com.nextai.opencut.R.drawable.bg_capcut_cyan_pill);
        btnCutSame.setPadding(20, 12, 20, 12);
        btnCutSame.setTag(Integer.valueOf(500 + templateIdx));
        btnCutSame.setOnClickListener(this);
        card.addView(btnCutSame);

        parent.addView(card);
    }

    @Override
    public void onClick(View v) {
        Object tag = v.getTag();
        if (tag instanceof Integer) {
            int code = ((Integer) tag).intValue();
            if (code >= 500 && code < 510) {
                int templateIdx = code - 500;
                applyTemplateByIndex(templateIdx);
            }
        }
    }

    private void applyTemplateByIndex(int index) {
        if (listener == null) return;
        switch (index) {
            case 0:
                listener.onApplyTemplate(0, "Beat Sync TikTok 120BPM", "00:15", "lut_cyberpunk_neon", "neon_silhouette");
                break;
            case 1:
                listener.onApplyTemplate(1, "Cinematic Vlog Đà Lạt", "00:25", "lut_teal_orange", "vintage_noise_v2");
                break;
            case 2:
                listener.onApplyTemplate(2, "Neon Glow Silhouette", "00:12", "lut_cyberpunk_neon", "neon_glow");
                break;
            default:
                listener.onApplyTemplate(3, "Kỷ Niệm Mùa Hè Rực Rỡ", "00:20", "lut_vintage_warm", "film_leak_orange");
                break;
        }
    }
}
