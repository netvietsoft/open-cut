package com.nextai.opencut.presentation.subscribe;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import com.nextai.opencut.billing.SubscriptionManager;

/**
 * SubscribeActivity — Màn Hình Nâng Cấp VIP PRO & Máy Giữ Chân Khách Hàng (VIP Paywall & Retention Machine)
 * 
 * Provides native VIP subscription flow, supporting Google Play Billing 8.2.1 simulation,
 * plan selection (Annual / Monthly), and 2-tier detain modals on exit attempts.
 * 
 * Cung cấp giao diện nâng cấp gói thuê bao VIP chuẩn CapCut, hỗ trợ xử lý thanh toán Google Play,
 * lựa chọn gói cước (Gói Năm / Gói Tháng) và hộp thoại giữ chân khách hàng 2 cấp độ.
 * 
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class SubscribeActivity extends Activity implements View.OnClickListener {

    private int selectedPlanIndex = 1; // 0: Monthly, 1: Annual (Popular)
    private int exitAttemptCount = 0;

    private View btnClose;
    private LinearLayout cardAnnual;
    private LinearLayout cardMonthly;
    private TextView tvAnnualRadio;
    private TextView tvMonthlyRadio;
    private View btnUpgrade;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        buildLayout();
    }

    /**
     * Build VIP Paywall UI Layout
     * Dựng cấu trúc giao diện Paywall VIP PRO với phong cách Dark theme cao cấp
     */
    private void buildLayout() {
        FrameLayout root = new FrameLayout(this);
        root.setBackgroundColor(Color.parseColor("#0D0E12"));
        root.setLayoutParams(new ViewGroup.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        ScrollView scrollView = new ScrollView(this);
        scrollView.setLayoutParams(new FrameLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

        LinearLayout content = new LinearLayout(this);
        content.setOrientation(LinearLayout.VERTICAL);
        content.setPadding(32, 40, 32, 48);

        // 1. Close Button Header / Nút Đóng (X)
        LinearLayout header = new LinearLayout(this);
        header.setOrientation(LinearLayout.HORIZONTAL);
        header.setGravity(Gravity.END);

        btnClose = new TextView(this);
        ((TextView) btnClose).setText("✕");
        ((TextView) btnClose).setTextColor(Color.parseColor("#94A3B8"));
        ((TextView) btnClose).setTextSize(20);
        ((TextView) btnClose).setPadding(16, 8, 16, 8);
        btnClose.setOnClickListener(this);
        header.addView(btnClose);
        content.addView(header);

        // 2. VIP Title & Crown / Vương miện và Tiêu đề VIP
        TextView tvCrown = new TextView(this);
        tvCrown.setText("👑 NEXTAI OPENCUT PRO");
        tvCrown.setTextColor(Color.parseColor("#FFB300"));
        tvCrown.setTextSize(22);
        tvCrown.setTypeface(null, Typeface.BOLD);
        tvCrown.setPadding(0, 16, 0, 4);
        content.addView(tvCrown);

        TextView tvSub = new TextView(this);
        tvSub.setText("Mở khóa toàn diện sức mạnh AI & Xuất video 4K siêu nét");
        tvSub.setTextColor(Color.parseColor("#94A3B8"));
        tvSub.setTextSize(13);
        tvSub.setPadding(0, 0, 0, 24);
        content.addView(tvSub);

        // 3. 4 VIP Benefits / 4 Quyền lợi VIP độc quyền
        content.addView(createBenefitRow("✨ Không giới hạn kịch bản & AI Copilot"));
        content.addView(createBenefitRow("🎬 Xuất video 4K 60FPS không nén, không watermark"));
        content.addView(createBenefitRow("☁️ 100GB Cloud Space sao lưu dự án tự động"));
        content.addView(createBenefitRow("🎨 1500+ Bộ lọc màu điện ảnh 3D & Hiệu ứng độc quyền"));

        View spacer = new View(this);
        content.addView(spacer, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 32));

        // 4. Annual Plan Card / Gói Năm
        cardAnnual = createPlanCard(
            "Gói Năm (Tiết kiệm 60%)",
            "899.000 ₫/năm (Chỉ 74k/tháng)",
            "PHỔ BIẾN NHẤT",
            true
        );
        content.addView(cardAnnual);

        View cardSpacer = new View(this);
        content.addView(cardSpacer, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 16));

        // 5. Monthly Plan Card / Gói Tháng
        cardMonthly = createPlanCard(
            "Gói Tháng",
            "189.000 ₫/tháng",
            null,
            false
        );
        content.addView(cardMonthly);

        View btnSpacer = new View(this);
        content.addView(btnSpacer, new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 36));

        // 6. Upgrade Button / Nút Nâng Cấp
        btnUpgrade = new TextView(this);
        ((TextView) btnUpgrade).setText("NÂNG CẤP NGAY (GOOGLE PLAY)");
        ((TextView) btnUpgrade).setTextColor(Color.BLACK);
        ((TextView) btnUpgrade).setTextSize(15);
        ((TextView) btnUpgrade).setTypeface(null, Typeface.BOLD);
        ((TextView) btnUpgrade).setGravity(Gravity.CENTER);
        btnUpgrade.setBackgroundColor(Color.parseColor("#FFB300"));
        btnUpgrade.setPadding(0, 28, 0, 28);
        btnUpgrade.setOnClickListener(this);
        content.addView(btnUpgrade);

        scrollView.addView(content);
        root.addView(scrollView);
        setContentView(root);
    }

    private View createBenefitRow(String text) {
        TextView tv = new TextView(this);
        tv.setText(text);
        tv.setTextColor(Color.WHITE);
        tv.setTextSize(13);
        tv.setPadding(0, 6, 0, 6);
        return tv;
    }

    private LinearLayout createPlanCard(String title, String price, String badge, boolean isAnnual) {
        LinearLayout card = new LinearLayout(this);
        card.setOrientation(LinearLayout.HORIZONTAL);
        card.setGravity(Gravity.CENTER_VERTICAL);
        card.setPadding(24, 20, 24, 20);
        card.setBackgroundColor(Color.parseColor(isAnnual ? "#1F2333" : "#14161F"));
        card.setClickable(true);

        LinearLayout left = new LinearLayout(this);
        left.setOrientation(LinearLayout.VERTICAL);
        LinearLayout.LayoutParams leftParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1.0f);
        left.setLayoutParams(leftParams);

        if (badge != null) {
            TextView tvBadge = new TextView(this);
            tvBadge.setText(badge);
            tvBadge.setTextColor(Color.parseColor("#FFB300"));
            tvBadge.setTextSize(10);
            tvBadge.setTypeface(null, Typeface.BOLD);
            left.addView(tvBadge);
        }

        TextView tvTitle = new TextView(this);
        tvTitle.setText(title);
        tvTitle.setTextColor(Color.WHITE);
        tvTitle.setTextSize(14);
        tvTitle.setTypeface(null, Typeface.BOLD);
        left.addView(tvTitle);

        TextView tvPrice = new TextView(this);
        tvPrice.setText(price);
        tvPrice.setTextColor(Color.parseColor("#00E5FF"));
        tvPrice.setTextSize(12);
        tvPrice.setPadding(0, 4, 0, 0);
        left.addView(tvPrice);

        card.addView(left);

        TextView tvRadio = new TextView(this);
        tvRadio.setText(isAnnual ? "🔘" : "⚪");
        tvRadio.setTextSize(18);
        card.addView(tvRadio);

        if (isAnnual) {
            tvAnnualRadio = tvRadio;
        } else {
            tvMonthlyRadio = tvRadio;
        }

        card.setOnClickListener(new PlanCardClickListener(this, isAnnual ? 1 : 0));

        return card;
    }

    private void selectPlan(int planIndex) {
        this.selectedPlanIndex = planIndex;
        if (tvAnnualRadio != null) tvAnnualRadio.setText(planIndex == 1 ? "🔘" : "⚪");
        if (tvMonthlyRadio != null) tvMonthlyRadio.setText(planIndex == 0 ? "🔘" : "⚪");
        if (cardAnnual != null) cardAnnual.setBackgroundColor(Color.parseColor(planIndex == 1 ? "#1F2333" : "#14161F"));
        if (cardMonthly != null) cardMonthly.setBackgroundColor(Color.parseColor(planIndex == 0 ? "#1F2333" : "#14161F"));
    }

    @Override
    public void onClick(View v) {
        if (v == btnClose) {
            handleExitAttempt();
            return;
        }

        if (v == btnUpgrade) {
            executeUpgrade();
        }
    }

    /**
     * Execute Upgrade via SubscriptionManager & Google Play Billing
     * Kích hoạt gói VIP qua SubscriptionManager và thông báo thành công
     */
    private void executeUpgrade() {
        boolean isAnnual = (selectedPlanIndex == 1);
        String tier = isAnnual ? SubscriptionManager.TIER_VIP_ANNUAL : SubscriptionManager.TIER_VIP_MONTHLY;
        long duration = isAnnual ? (365L * 24 * 60 * 60 * 1000L) : (30L * 24 * 60 * 60 * 1000L);

        SubscriptionManager.setVipActive(this, true, tier, duration);
        Toast.makeText(this, "🎉 Đã kích hoạt thành công: " + SubscriptionManager.getTierDisplayName(this) + "!", Toast.LENGTH_LONG).show();
        finish();
    }

    /**
     * Handle Back Press or Close with 2-Tier Retention Detain Modals
     * Xử lý giữ chân người dùng 2 cấp độ khi nhấn phím Back hoặc nút Đóng
     */
    private void handleExitAttempt() {
        exitAttemptCount++;
        if (exitAttemptCount == 1) {
            showFirstDetainDialog();
        } else if (exitAttemptCount == 2) {
            showSecondDetainDialog();
        } else {
            finish();
        }
    }

    @Override
    public void onBackPressed() {
        handleExitAttempt();
    }

    /**
     * 1st Detain Modal: 20% Discount Voucher
     * Hộp thoại giữ chân cấp 1: Tặng voucher giảm giá 20% gói năm
     */
    private void showFirstDetainDialog() {
        new AlertDialog.Builder(this)
            .setTitle("🎁 KHOAN ĐÃ! ƯU ĐÃI ĐẶC BIỆT")
            .setMessage("Tặng bạn Voucher GIẢM GIÁ 20% cho gói Năm!\nGiá chỉ còn: 719.000 ₫/năm (tiết kiệm thêm 180k).")
            .setPositiveButton("NHẬN ƯU ĐÃI 20%", new Detain20ClickListener(this))
            .setNegativeButton("Bỏ qua", new DetainSkipClickListener(this))
            .show();
    }

    /**
     * 2nd Detain Modal: 3-Day Free Trial
     * Hộp thoại giữ chân cấp 2: Mời dùng thử 3 ngày miễn phí
     */
    private void showSecondDetainDialog() {
        new AlertDialog.Builder(this)
            .setTitle("🔥 CƠ HỘI CUỐI CÙNG")
            .setMessage("Trải nghiệm toàn bộ tính năng VIP PRO MIỄN PHÍ trong 3 ngày trước khi quyết định!")
            .setPositiveButton("DÙNG THỬ 3 NGÀY MIỄN PHÍ", new Detain3DayClickListener(this))
            .setNegativeButton("Đóng và thoát", new DetainCloseClickListener(this))
            .show();
    }

    // --- Named Static Inner Classes to guarantee D8 bytecode stability (Rule 12 & D8 Bug Workaround) ---

    private static class PlanCardClickListener implements View.OnClickListener {
        private final SubscribeActivity activity;
        private final int planIndex;

        public PlanCardClickListener(SubscribeActivity activity, int planIndex) {
            this.activity = activity;
            this.planIndex = planIndex;
        }

        @Override
        public void onClick(View v) {
            if (activity != null) {
                activity.selectPlan(planIndex);
            }
        }
    }

    private static class Detain20ClickListener implements DialogInterface.OnClickListener {
        private final SubscribeActivity activity;

        public Detain20ClickListener(SubscribeActivity activity) {
            this.activity = activity;
        }

        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) {
                SubscriptionManager.setVipActive(activity, true,
                    SubscriptionManager.TIER_VIP_DISCOUNT_20, 365L * 24 * 60 * 60 * 1000L);
                Toast.makeText(activity, "🎉 Đã áp dụng Voucher 20% & kích hoạt VIP PRO!", Toast.LENGTH_LONG).show();
                activity.finish();
            }
        }
    }

    private static class DetainSkipClickListener implements DialogInterface.OnClickListener {
        private final SubscribeActivity activity;

        public DetainSkipClickListener(SubscribeActivity activity) {
            this.activity = activity;
        }

        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) {
                activity.handleExitAttempt();
            }
        }
    }

    private static class Detain3DayClickListener implements DialogInterface.OnClickListener {
        private final SubscribeActivity activity;

        public Detain3DayClickListener(SubscribeActivity activity) {
            this.activity = activity;
        }

        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) {
                SubscriptionManager.setVipActive(activity, true,
                    SubscriptionManager.TIER_VIP_TRIAL_3DAY, 3L * 24 * 60 * 60 * 1000L);
                Toast.makeText(activity, "🎉 Đã kích hoạt 3 ngày dùng thử VIP PRO miễn phí!", Toast.LENGTH_LONG).show();
                activity.finish();
            }
        }
    }

    private static class DetainCloseClickListener implements DialogInterface.OnClickListener {
        private final SubscribeActivity activity;

        public DetainCloseClickListener(SubscribeActivity activity) {
            this.activity = activity;
        }

        @Override
        public void onClick(DialogInterface dialog, int which) {
            if (activity != null) {
                activity.finish();
            }
        }
    }
}
