/**
 * Templates & Feed Controller / Bộ Điều Khiển Mẫu Video & CutSame
 * Manages video template feeds, trending recommendation, and 1-tap replacement specs.
 * Quản lý nguồn cấp dữ liệu mẫu video, thuật toán xu hướng và cấu hình thay thế một chạm.
 */

import { Router, Request, Response } from 'express';
import { db } from '../../database/db';
import { sendSuccess, sendError } from '../../middleware/response';

export const templatesRouter = Router();

/**
 * GET /api/feed/v2/templates/recommend
 * Fetch trending templates feed / Lấy danh sách mẫu video thịnh hành
 */
templatesRouter.get('/recommend', (req: Request, res: Response) => {
  const templates = Array.from(db.templates.values()).map((tpl) => ({
    ...tpl,
    template_config: JSON.parse(tpl.template_config)
  }));

  return sendSuccess(res, {
    items: templates,
    has_more: false,
    cursor: 0,
    categories: ['Thịnh hành', 'Meme', 'Vlog Du Lịch', 'Nhịp Điệu', 'Cyberpunk AI']
  });
});

/**
 * GET /api/feed/v2/templates/detail
 * Fetch template detail by ID / Lấy chi tiết mẫu theo ID
 */
templatesRouter.get('/detail', (req: Request, res: Response) => {
  const templateId = req.query.template_id as string;
  const tpl = db.templates.get(templateId);

  if (!tpl) {
    return sendError(res, 'Template not found (Không tìm thấy mẫu)', 10004, 404);
  }

  return sendSuccess(res, {
    ...tpl,
    template_config: JSON.parse(tpl.template_config)
  });
});
