package com.nextai.opencut.presentation.profile;

import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.nextai.opencut.billing.SubscriptionManager;
import com.nextai.opencut.presentation.subscribe.SubscribeActivity;
import com.nextai.opencut.presentation.navigation.BottomNavComponent;

/**
 * User Profile Component / Màn Hình Hồ Sơ & Cài Đặt Người Dùng NextAI OpenCut
 * NextAI OpenCut Mobile Architecture Standard V2.1
 * 
 * Provides honest subscription status reporting, settings overview, and 5-tab bottom navigation integration.
 * Cung cấp báo cáo trạng thái gói đăng ký trung thực (chống fake VIP), tổng quan cài đặt và điều hướng 5 tab chuẩn.
 * 
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class ProfileComponent implements BottomNavComponent.OnTabSelectListener {

    public interface OnProfileActionListener {
        void onTabSelected(int tabIndex);
    }

    private final Context context;
    private final OnProfileActionListener listener;
    private LinearLayout profileView;
    private BottomNavComponent bottomNavComponent;

    public ProfileComponent(Context context, OnProfileActionListener listener) {
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
        // Always rebuild or refresh view to guarantee up-to-date subscription state
        // Luôn dựng lại hoặc làm mới giao diện để đảm bảo hiển thị đúng trạng thái VIP mới nhất
        buildView();
        return profileView;
    }

    private void buildView() {
        profileView = new LinearLayout(context);
        profileView.setOrientation(LinearLayout.VERTICAL);
        profileView.setBackgroundColor(Color.parseColor("#0D0E12"));
        profileView.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        TextView tvTitle = new TextView(context);
        tvTitle.setText("👤 HỒ SƠ CỦA TÔI (PROFILE)");
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(18);
        tvTitle.setTypeface(null, Typeface.BOLD);
        tvTitle.setPadding(32, 40, 32, 16);
        profileView.addView(tvTitle);

        // Honest Subscription State Reporting (Fixes D6 / Rule 14: Never invent project state)
        // Hiển thị trạng thái thuê bao trung thực từ SubscriptionManager, không hiển thị VIP giả mạo
        boolean isVip = SubscriptionManager.isVipActive(context);
        String tierName = SubscriptionManager.getTierDisplayName(context);

        View cardVip;
        if (isVip) {
            cardVip = createDraftCard(
                "👑 Gói Thuê Bao: " + tierName,
                "Đang Hoạt Động",
                "Google Play Billing 8.2.1 • Mở khóa 4K 60FPS • AI Copilot Không Giới Hạn",
                "#10B981"
            );
        } else {
            cardVip = createDraftCard(
                "⚡ Gói Dịch Vụ: " + tierName,
                "NÂNG CẤP VIP",
                "Chạm để nâng cấp VIP PRO: Xuất 4K 60FPS, xóa watermark & 100GB Cloud",
                "#3B82F6"
            );
            // Click to open Paywall / Chạm vào để mở giao diện nâng cấp Paywall
            cardVip.setOnClickListener(new VipUpgradeClickListener(context));
        }
        profileView.addView(cardVip);

        // Hardware Acceleration & FFmpeg Core Settings Card
        // Thẻ thông số phần cứng & Lõi xử lý video C++20
        profileView.addView(createDraftCard(
            "⚙️ Cấu Hình Lõi FFmpeg & Tăng Tốc Phần Cứng",
            "C++20",
            "Hardware Accel: HEVC MediaCodec • SIMD ARM Neon",
            "#10B981"
        ));

        View spacer = new View(context);
        profileView.addView(spacer, new LinearLayout.LayoutParams(0, 0, 1.0f));

        // Tab index 4 corresponds to "Tôi / Me" in 5-tab system (Fixes D1)
        // Tab index 4 tương ứng với tab "Tôi" trong hệ thống 5 tab chuẩn
        profileView.addView(bottomNavComponent.buildView(4));
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

    /**
     * Named static listener for VIP upgrade card clicks (Resolves D8 anonymous inner class bug)
     * Bộ lắng nghe tĩnh đặt tên cho sự kiện nhấn thẻ nâng cấp VIP (Khắc phục lỗi D8 biên dịch lớp vô danh)
     */
    private static class VipUpgradeClickListener implements View.OnClickListener {
        private final Context context;

        public VipUpgradeClickListener(Context context) {
            this.context = context;
        }

        @Override
        public void onClick(View v) {
            Intent intent = new Intent(context, SubscribeActivity.class);
            context.startActivity(intent);
        }
    }
}
