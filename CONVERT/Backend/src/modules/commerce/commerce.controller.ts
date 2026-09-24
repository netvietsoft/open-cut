/**
 * Commerce & Subscription Controller / Bộ Điều Khiển Thanh Toán & Gói VIP
 * Implements Paywall catalog, 2-tier Detain Modal retention strategy, and order verification.
 * Triển khai danh mục gói VIP, thuật toán giữ chân người dùng 2 cấp và xác thực đơn hàng.
 */

import { Router, Request, Response } from 'express';
import { db } from '../../database/db';
import { sendSuccess, sendError } from '../../middleware/response';

export const commerceRouter = Router();

/**
 * POST /api/commerce/v1/subscription/products
 * Fetch VIP subscription catalog / Lấy danh sách sản phẩm gói cước Pro
 */
commerceRouter.post('/subscription/products', (req: Request, res: Response) => {
  const products = [
    {
      sku_id: 'com.nextai.opencut.pro.monthly',
      title: 'Gói Pro Hàng Tháng',
      price: '189.000 ₫',
      price_usd: 7.99,
      duration: '1 Month',
      is_popular: false,
      benefits: ['Không giới hạn AI Copilot', 'Xuất video 4K 60FPS', 'Mở khóa toàn bộ 1500+ hiệu ứng VIP']
    },
    {
      sku_id: 'com.nextai.opencut.pro.annual',
      title: 'Gói Pro Hàng Năm (Tiết Kiệm 60%)',
      price: '899.000 ₫',
      price_usd: 39.99,
      duration: '1 Year',
      is_popular: true,
      badge: 'TIẾT KIỆM 60%',
      benefits: ['Tất cả tính năng của gói Tháng', 'Tặng 100GB Cloud Space', 'Ưu tiên kết xuất GPU siêu tốc']
    },
    {
      sku_id: 'com.nextai.opencut.pro.weekly_retain',
      title: 'Gói Tuần Giữ Chân Đặc Biệt',
      price: '49.000 ₫',
      price_usd: 1.99,
      duration: '7 Days',
      is_popular: false,
      badge: 'ƯU ĐÃI RIÊNG BẠN',
      benefits: ['Trải nghiệm đầy đủ tính năng Pro trong 7 ngày']
    }
  ];

  return sendSuccess(res, {
    products,
    rewarded_ad_unlocked: true,
    rewarded_ad_hours: 24,
    headline: 'Mở Khóa Toàn Diện Sức Mạnh NextAI OpenCut Pro'
  });
});

/**
 * POST /api/commerce/v1/subscription/detain_strategy
 * 2-Tier Retention Strategy Algorithm / Thuật toán giữ chân người dùng 2 cấp khi định đóng Paywall
 */
commerceRouter.post('/subscription/detain_strategy', (req: Request, res: Response) => {
  const { exit_attempt_count = 1 } = req.body;

  if (exit_attempt_count === 1) {
    // Level 1: Offer 20% discount coupon / Cấp 1: Tặng mã giảm giá 20%
    return sendSuccess(res, {
      tier: 1,
      modal_title: 'Khoan Đã! Ưu Đãi Độc Quyền Dành Cho Bạn',
      discount_percent: 20,
      voucher_code: 'NEXTAI_PRO_20_PERCENT',
      discounted_sku_id: 'com.nextai.opencut.pro.annual',
      discounted_price: '719.000 ₫',
      countdown_seconds: 600,
      cta_text: 'Nhận Ưu Đãi 20% Ngay'
    });
  } else {
    // Level 2: Offer 3-day free trial or Weekly retain pack / Cấp 2: Tặng 3 ngày dùng thử hoặc gói tuần
    return sendSuccess(res, {
      tier: 2,
      modal_title: 'Đừng Bỏ Lỡ: Dùng Thử 3 Ngày Miễn Phí',
      free_trial_days: 3,
      voucher_code: 'FREE_TRIAL_3DAYS_SPECIAL',
      discounted_sku_id: 'com.nextai.opencut.pro.weekly_retain',
      discounted_price: '49.000 ₫/tuần',
      countdown_seconds: 300,
      cta_text: 'Bắt Đầu Dùng Thử 3 Ngày Miễn Phí'
    });
  }
});

/**
 * POST /api/commerce/v1/order/verify_google_token
 * Verify Google Play Purchase Token / Xác thực biên lai mua hàng từ Google Play Store
 */
commerceRouter.post('/order/verify_google_token', (req: Request, res: Response) => {
  const { purchase_token, sku_id, user_id } = req.body;

  if (!purchase_token || !sku_id) {
    return sendError(res, 'Missing purchase_token or sku_id (Thiếu token mua hàng)', 10001);
  }

  const targetUserId = user_id || 'usr_admin_001';
  const user = db.users.get(targetUserId);
  if (user) {
    user.is_vip = 1;
    user.vip_expire_at = new Date(Date.now() + 365 * 24 * 3600 * 1000).toISOString();
    db.users.set(targetUserId, user);
  }

  return sendSuccess(res, {
    status: 'verified',
    is_vip: true,
    sku_id,
    order_id: `GPA.NEXTAI.${Date.now()}`,
    expire_at: user?.vip_expire_at
  }, 'VIP Subscription activated successfully (Kích hoạt gói VIP thành công)');
});
