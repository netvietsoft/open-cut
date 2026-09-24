/**
 * Admin CMS Controller / Bộ Điều Khiển Quản Trị Hệ Thống Web CMS
 * Provides administrative CRUD APIs for users, devices, templates, prompts, and paywall.
 * Cung cấp API quản trị thêm, sửa, xóa người dùng, thiết bị, mẫu, prompt AI và chiến dịch giá.
 */

import { Router, Request, Response } from 'express';
import { db, UserRecord, TemplateRecord } from '../../database/db';
import { sendSuccess, sendError } from '../../middleware/response';

export const adminRouter = Router();

/**
 * GET /api/admin/dashboard/stats
 * Overview dashboard metrics / Thống kê tổng quan hệ thống
 */
adminRouter.get('/dashboard/stats', (req: Request, res: Response) => {
  return sendSuccess(res, {
    total_users: db.users.size,
    vip_subscribers: Array.from(db.users.values()).filter((u) => u.is_vip === 1).length,
    active_devices: db.devices.size,
    total_templates: db.templates.size,
    total_assets: db.assets.size,
    server_port: 6033,
    status: 'ONLINE',
    uptime_seconds: process.uptime(),
    memory_usage_mb: (process.memoryUsage().rss / 1024 / 1024).toFixed(2)
  });
});

/**
 * GET /api/admin/users
 * List all users / Danh sách toàn bộ người dùng
 */
adminRouter.get('/users', (req: Request, res: Response) => {
  const users = Array.from(db.users.values());
  return sendSuccess(res, { users, count: users.length });
});

/**
 * POST /api/admin/users/create
 * Create new user / Thêm mới người dùng
 */
adminRouter.post('/users/create', (req: Request, res: Response) => {
  const { username, email, is_vip } = req.body;

  if (!username) {
    return sendError(res, 'Username is required (Yêu cầu tên người dùng)', 10001);
  }

  const newId = `usr_${Date.now()}`;
  const newUser: UserRecord = {
    id: newId,
    username,
    email: email || `${username.toLowerCase()}@nextai.com`,
    avatar_url: 'https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?w=150',
    device_id: `dev_${Date.now()}`,
    is_vip: is_vip ? 1 : 0,
    vip_expire_at: is_vip ? new Date(Date.now() + 365 * 24 * 3600 * 1000).toISOString() : null,
    free_credits_today: is_vip ? 100 : 5,
    created_at: new Date().toISOString()
  };

  db.users.set(newId, newUser);
  return sendSuccess(res, newUser, 'User created successfully (Tạo người dùng thành công)');
});

/**
 * PUT /api/admin/users/:id
 * Update user / Cập nhật thông tin người dùng
 */
adminRouter.put('/users/:id', (req: Request, res: Response) => {
  const { id } = req.params;
  const user = db.users.get(id);

  if (!user) {
    return sendError(res, 'User not found (Không tìm thấy người dùng)', 10004, 404);
  }

  const { username, email, is_vip, free_credits_today } = req.body;
  if (username !== undefined) user.username = username;
  if (email !== undefined) user.email = email;
  if (is_vip !== undefined) {
    user.is_vip = is_vip ? 1 : 0;
    user.vip_expire_at = is_vip ? new Date(Date.now() + 365 * 24 * 3600 * 1000).toISOString() : null;
  }
  if (free_credits_today !== undefined) user.free_credits_today = Number(free_credits_today);

  db.users.set(id, user);
  return sendSuccess(res, user, 'User updated successfully (Cập nhật thành công)');
});

/**
 * DELETE /api/admin/users/:id
 * Delete user / Xóa người dùng
 */
adminRouter.delete('/users/:id', (req: Request, res: Response) => {
  const { id } = req.params;
  if (!db.users.has(id)) {
    return sendError(res, 'User not found (Không tìm thấy người dùng)', 10004, 404);
  }
  db.users.delete(id);
  return sendSuccess(res, { deleted_id: id }, 'User deleted successfully (Xóa người dùng thành công)');
});

/**
 * GET /api/admin/devices
 * List registered devices / Danh sách thiết bị đăng ký
 */
adminRouter.get('/devices', (req: Request, res: Response) => {
  const devices = Array.from(db.devices.values());
  return sendSuccess(res, { devices, count: devices.length });
});

/**
 * POST /api/admin/templates/create
 * Create new template / Thêm mới video mẫu
 */
adminRouter.post('/templates/create', (req: Request, res: Response) => {
  const { title, demo_video_url, slots_count, is_pro } = req.body;

  if (!title) {
    return sendError(res, 'Template title is required (Yêu cầu tiêu đề mẫu)', 10001);
  }

  const newId = `tpl_${Date.now()}`;
  const newTpl: TemplateRecord = {
    id: newId,
    author_id: 'usr_admin_001',
    title,
    demo_video_url: demo_video_url || 'https://assets.nextai.com/demos/sample.mp4',
    music_id: 'music_sample_001',
    slots_count: Number(slots_count) || 3,
    template_config: JSON.stringify({
      duration_ms: 12000,
      cuts: [{ start_ms: 0, end_ms: 4000 }, { start_ms: 4000, end_ms: 8000 }, { start_ms: 8000, end_ms: 12000 }]
    }),
    usage_count: 0,
    likes_count: 0,
    is_pro: is_pro ? 1 : 0,
    created_at: new Date().toISOString()
  };

  db.templates.set(newId, newTpl);
  return sendSuccess(res, newTpl, 'Template created successfully (Tạo mẫu thành công)');
});
