package com.nextai.opencut.presentation.cloud;

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
 * Cloud Space Component / Màn Hình Không Gian Lưu Trữ Đám Mây NextAI OpenCut
 * NextAI OpenCut Mobile Architecture Standard V2.1
 */
public class CloudComponent implements BottomNavComponent.OnTabSelectListener {

    public interface OnCloudActionListener {
        void onTabSelected(int tabIndex);
    }

    private final Context context;
    private final OnCloudActionListener listener;
    private LinearLayout cloudView;
    private BottomNavComponent bottomNavComponent;

    public CloudComponent(Context context, OnCloudActionListener listener) {
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
        if (cloudView == null) {
            buildView();
        }
        return cloudView;
    }

    private void buildView() {
        cloudView = new LinearLayout(context);
        cloudView.setOrientation(LinearLayout.VERTICAL);
        cloudView.setBackgroundColor(Color.parseColor("#0D0E12"));
        cloudView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        TextView tvTitle = new TextView(context);
        tvTitle.setText("☁️ KHÔNG GIAN ĐÁM MÂY (CLOUD)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(18);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(32, 40, 32, 16);
        cloudView.addView(tvTitle);

        cloudView.addView(createDraftCard("📁 Đã Sử Dụng: 4.2 GB / 50 GB", "Cloud", "Đồng bộ hóa tức thì giữa Mobile và Web CMS", "#38BDF8"));
        cloudView.addView(createDraftCard("👥 Nhóm Làm Việc: NextAI Studio", "Team", "5 thành viên • Phân quyền vai trò chuẩn", "#6366F1"));

        View spacer = new View(context);
        cloudView.addView(spacer, new LinearLayout.LayoutParams(0, 0, 1.0f));
        cloudView.addView(bottomNavComponent.buildView(2));
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
