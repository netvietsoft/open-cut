package com.nextai.opencut.presentation.ailab;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.nextai.opencut.presentation.navigation.BottomNavComponent;

/**
 * AI Lab Component / Màn Hình Phòng Thí Nghiệm AI NextAI OpenCut
 * NextAI OpenCut Mobile Architecture Standard V2.1
 */
public class AiLabComponent implements BottomNavComponent.OnTabSelectListener {

    public interface OnAiLabActionListener {
        void onTabSelected(int tabIndex);
    }

    private final Context context;
    private final OnAiLabActionListener listener;
    private LinearLayout aiLabView;
    private BottomNavComponent bottomNavComponent;

    public AiLabComponent(Context context, OnAiLabActionListener listener) {
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
        if (aiLabView == null) {
            buildView();
        }
        return aiLabView;
    }

    private void buildView() {
        aiLabView = new LinearLayout(context);
        aiLabView.setOrientation(LinearLayout.VERTICAL);
        aiLabView.setBackgroundColor(Color.parseColor("#0D0E12"));
        aiLabView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        TextView tvTitle = new TextView(context);
        tvTitle.setText("🤖 NEXTAI LAB AGENT");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(18);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(32, 40, 32, 16);
        aiLabView.addView(tvTitle);

        aiLabView.addView(createDraftCard("⚡ AI Storyboard to Video Generator", "AI", "Tạo video tự động từ văn bản & kịch bản", "#00E5FF"));
        aiLabView.addView(createDraftCard("🗣️ AI Auto-Dubbing Song Ngữ", "AI", "Chuyển đổi phụ đề & giọng đọc chuẩn", "#A855F7"));
        aiLabView.addView(createDraftCard("👤 AI Face Tracking 468 & AR Mesh", "AI", "Gắn sticker và trang điểm 3D thời gian thực", "#10B981"));

        View spacer = new View(context);
        aiLabView.addView(spacer, new LinearLayout.LayoutParams(0, 0, 1.0f));
        aiLabView.addView(bottomNavComponent.buildView(3));
    }

    private View createDraftCard(String title, String tag, String desc, String colorHex) {
        LinearLayout card = new LinearLayout(context);
        card.setOrientation(LinearLayout.VERTICAL);
        card.setBackgroundColor(Color.parseColor("#151620"));
        card.setPadding(24, 20, 24, 20);
        LinearLayout.LayoutParams clp = new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        clp.setMargins(24, 0, 24, 16);
        card.setLayoutParams(clp);

        LinearLayout top = new LinearLayout(context);
        top.setOrientation(LinearLayout.HORIZONTAL);
        top.setGravity(Gravity.CENTER_VERTICAL);

        TextView tvTag = new TextView(context);
        tvTag.setText(tag);
        tvTag.setTextColor(Color.BLACK);
        tvTag.setTextSize(10);
        tvTag.setTypeface(null, Typeface.BOLD);
        tvTag.setBackgroundColor(Color.parseColor(colorHex));
        tvTag.setPadding(12, 4, 12, 4);
        top.addView(tvTag);

        TextView tvT = new TextView(context);
        tvT.setText(" " + title);
        tvT.setTextColor(Color.WHITE);
        tvT.setTextSize(13);
        tvT.setTypeface(null, Typeface.BOLD);
        top.addView(tvT);
        card.addView(top);

        TextView tvD = new TextView(context);
        tvD.setText(desc);
        tvD.setTextColor(Color.parseColor("#94A3B8"));
        tvD.setTextSize(11);
        tvD.setPadding(0, 8, 0, 0);
        card.addView(tvD);

        return card;
    }
}
