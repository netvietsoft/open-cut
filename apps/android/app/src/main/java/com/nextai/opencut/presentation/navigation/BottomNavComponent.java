package com.nextai.opencut.presentation.navigation;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

/**
 * Reusable CapCut-style Bottom Navigation Bar / Thanh Điều Hướng Đáy Chuẩn CapCut
 * NextAI OpenCut Mobile Architecture
 */
public class BottomNavComponent implements View.OnClickListener {

    public interface OnTabSelectListener {
        void onTabSelected(int tabIndex);
    }

    private final Context context;
    private final OnTabSelectListener listener;
    private LinearLayout navContainer;
    private int currentActiveIndex = 0;

    public BottomNavComponent(Context context, OnTabSelectListener listener) {
        this.context = context;
        this.listener = listener;
    }

    /**
     * Build Bottom Nav View for given active tab index / Dựng thanh điều hướng với tab đang chọn
     */
    public View buildView(int activeIndex) {
        this.currentActiveIndex = activeIndex;
        navContainer = new LinearLayout(context);
        navContainer.setOrientation(LinearLayout.HORIZONTAL);
        navContainer.setBackgroundResource(com.nextai.opencut.R.drawable.bg_bottom_nav);
        navContainer.setPadding(8, 12, 8, 16);
        navContainer.setLayoutParams(new LinearLayout.LayoutParams(
            LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));

        // Canonical 5-tab layout matching NextAI OpenCut & CapCut mobile architecture
        // Cấu trúc 5 tab chuẩn đồng bộ với NextAI OpenCut và kiến trúc CapCut Mobile
        createNavTab("✂️", "Chỉnh sửa", 0, activeIndex, navContainer);
        createNavTab("📐", "Mẫu", 1, activeIndex, navContainer);
        createNavTab("☁️", "Không gian", 2, activeIndex, navContainer);
        createNavTab("🤖", "AI Lab", 3, activeIndex, navContainer);
        createNavTab("👤", "Tôi", 4, activeIndex, navContainer);

        return navContainer;
    }

    private void createNavTab(String icon, String label, int tabIndex, int activeIndex, LinearLayout parent) {
        LinearLayout tab = new LinearLayout(context);
        tab.setOrientation(LinearLayout.VERTICAL);
        tab.setGravity(Gravity.CENTER);
        tab.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.WRAP_CONTENT, 1.0f));
        tab.setTag(Integer.valueOf(tabIndex));

        boolean isActive = (tabIndex == activeIndex);

        TextView tvIcon = new TextView(context);
        tvIcon.setText(icon);
        tvIcon.setTextSize(16);
        tab.addView(tvIcon);

        TextView tvLabel = new TextView(context);
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
        Object tag = v.getTag();
        if (tag instanceof Integer && listener != null) {
            listener.onTabSelected(((Integer) tag).intValue());
        }
    }
}
