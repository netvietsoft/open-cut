/**
 * Auth Controller / Bộ Điều Khiển Xác Thực & Định Danh
 * Handles registration, login, JWT issuance, and device tracking.
 * Xử lý đăng ký, đăng nhập, cấp phát JWT và liên kết thiết bị.
 */

import { Router, Request, Response } from 'express';
import jwt from 'jsonwebtoken';
import { db, UserRecord } from '../../database/db';
import { ENV } from '../../config/environment';
import { sendSuccess, sendError } from '../../middleware/response';

export const authRouter = Router();

/**
 * POST /api/v1/passport/login
 * User login or register via email/username / Đăng nhập hoặc đăng ký người dùng
 */
authRouter.post('/login', (req: Request, res: Response) => {
  const { username, email, device_id } = req.body;

  if (!username && !email) {
    return sendError(res, 'Username or email required (Yêu cầu tên đăng nhập hoặc email)', 10001);
  }

  let user = Array.from(db.users.values()).find(
    (u) => (username && u.username === username) || (email && u.email === email)
  );

  if (!user) {
    // Auto-create user for frictionless onboarding / Tự động tạo user
    const newId = `usr_${Date.now()}`;
    user = {
      id: newId,
      username: username || `User_${newId.slice(-4)}`,
      email: email || `${newId}@nextai.com`,
      avatar_url: 'https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?w=150',
      device_id: device_id || `dev_${Date.now()}`,
      is_vip: 0,
      vip_expire_at: null,
      free_credits_today: 5,
      created_at: new Date().toISOString()
    };
    db.users.set(user.id, user);
  }

  // Register or update device / Đăng ký hoặc cập nhật thiết bị
  if (device_id) {
    db.devices.set(device_id, {
      device_id,
      user_id: user.id,
      device_model: req.body.device_model || 'Android Mobile',
      os_version: req.body.os_version || 'Android 15',
      app_version: 'v2.1.0',
      ip_address: req.ip || '127.0.0.1',
      last_active_at: new Date().toISOString()
    });
  }

  // Issue tokens / Cấp phát token
  const token = jwt.sign(
    { id: user.id, username: user.username, is_vip: !!user.is_vip },
    ENV.JWT_SECRET,
    { expiresIn: '2h' }
  );

  return sendSuccess(res, {
    token,
    user_info: user,
    session_id: `sess_${user.id}_${Date.now()}`,
    refresh_token: `rf_${user.id}_${Date.now()}`
  }, 'Login successful (Đăng nhập thành công)');
});

/**
 * POST /api/v1/passport/user_info
 * Fetch current user profile / Lấy thông tin tài khoản hiện tại
 */
authRouter.post('/user_info', (req: Request, res: Response) => {
  const userId = req.body.user_id || 'usr_admin_001';
  const user = db.users.get(userId);

  if (!user) {
    return sendError(res, 'User not found (Không tìm thấy người dùng)', 10003, 404);
  }

  return sendSuccess(res, user);
});
