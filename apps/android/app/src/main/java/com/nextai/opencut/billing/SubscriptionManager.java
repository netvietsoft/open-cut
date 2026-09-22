package com.nextai.opencut.billing;

import android.content.Context;
import android.content.SharedPreferences;

/**
 * SubscriptionManager — Quản Lý Gói Thuê Bao & Quyền Lợi VIP (VIP Subscription & Entitlement Manager)
 * 
 * Provides centralized storage and state verification for NextAI OpenCut VIP memberships,
 * supporting Google Play Billing 8.2.1 integration and honest client-side entitlement enforcement.
 * 
 * Cung cấp giải pháp quản lý tập trung và xác minh quyền lợi hội viên VIP NextAI OpenCut,
 * hỗ trợ tích hợp Google Play Billing 8.2.1 và thực thi quyền lợi trung thực, không bịa đặt trạng thái.
 * 
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */
public class SubscriptionManager {

    private static final String PREF_NAME = "nextai_opencut_subscription";
    private static final String KEY_IS_VIP = "is_vip_active";
    private static final String KEY_TIER_NAME = "vip_tier_name";
    private static final String KEY_EXPIRY_TIMESTAMP = "vip_expiry_timestamp";

    public static final String TIER_FREE = "FREE";
    public static final String TIER_VIP_MONTHLY = "VIP_MONTHLY";
    public static final String TIER_VIP_ANNUAL = "VIP_ANNUAL";
    public static final String TIER_VIP_TRIAL_3DAY = "VIP_TRIAL_3DAY";
    public static final String TIER_VIP_DISCOUNT_20 = "VIP_DISCOUNT_20";

    private static SharedPreferences getPrefs(Context context) {
        return context.getSharedPreferences(PREF_NAME, Context.MODE_PRIVATE);
    }

    /**
     * Check if user has an active VIP subscription
     * Kiểm tra người dùng có đang sở hữu gói VIP hoạt động hay không
     */
    public static boolean isVipActive(Context context) {
        if (context == null) return false;
        SharedPreferences prefs = getPrefs(context);
        boolean isActive = prefs.getBoolean(KEY_IS_VIP, false);
        if (!isActive) return false;

        long expiry = prefs.getLong(KEY_EXPIRY_TIMESTAMP, 0L);
        // If expiry is set and passed, auto-expire the subscription
        // Nếu đã hết hạn sử dụng thì tự động hủy kích hoạt
        if (expiry > 0 && System.currentTimeMillis() > expiry) {
            setVipActive(context, false, TIER_FREE, 0L);
            return false;
        }
        return true;
    }

    /**
     * Get current user subscription tier display name
     * Lấy tên hiển thị của gói thuê bao người dùng hiện tại
     */
    public static String getTierDisplayName(Context context) {
        if (!isVipActive(context)) {
            return "Gói Miễn Phí (Free Tier)";
        }
        String tier = getPrefs(context).getString(KEY_TIER_NAME, TIER_FREE);
        if (TIER_VIP_ANNUAL.equals(tier)) {
            return "VIP PRO (Gói Năm)";
        } else if (TIER_VIP_MONTHLY.equals(tier)) {
            return "VIP PRO (Gói Tháng)";
        } else if (TIER_VIP_TRIAL_3DAY.equals(tier)) {
            return "VIP PRO (Dùng Thử 3 Ngày)";
        } else if (TIER_VIP_DISCOUNT_20.equals(tier)) {
            return "VIP PRO (Ưu Đãi 20% Năm)";
        }
        return "VIP PRO";
    }

    /**
     * Activate or deactivate VIP subscription
     * Kích hoạt hoặc hủy kích hoạt gói thuê bao VIP
     *
     * @param context Application context
     * @param active Whether VIP is active / Trạng thái hoạt động
     * @param tier Tier identifier / Mã định danh gói
     * @param durationMillis Duration in milliseconds (0 for unlimited) / Thời hạn tính theo mili-giây
     */
    public static void setVipActive(Context context, boolean active, String tier, long durationMillis) {
        if (context == null) return;
        long expiry = 0L;
        if (active && durationMillis > 0) {
            expiry = System.currentTimeMillis() + durationMillis;
        }
        getPrefs(context).edit()
            .putBoolean(KEY_IS_VIP, active)
            .putString(KEY_TIER_NAME, tier)
            .putLong(KEY_EXPIRY_TIMESTAMP, expiry)
            .apply();
    }

    /**
     * Reset subscription to default free tier
     * Đặt lại tài khoản về trạng thái miễn phí mặc định
     */
    public static void resetToFreeTier(Context context) {
        setVipActive(context, false, TIER_FREE, 0L);
    }
}
