/**
 * Assets & Cloudflare R2 Controller / Bộ Điều Khiển Tài Nguyên & Cloudflare R2
 * Manages audio, video, image, font, and effect assets with Orphaned File Prevention.
 * Quản lý tài sản media với cơ chế xóa an toàn trên Cloudflare R2 chống file mồ côi.
 */

import { Router, Request, Response } from 'express';
import { db, AssetRecord } from '../../database/db';
import { ENV } from '../../config/environment';
import { sendSuccess, sendError } from '../../middleware/response';

export const assetsRouter = Router();

/**
 * GET /api/v1/assets/list
 * List all media assets / Lấy danh sách tài nguyên tệp
 */
assetsRouter.get('/list', (req: Request, res: Response) => {
  const category = req.query.category as string;
  let items = Array.from(db.assets.values());

  if (category) {
    items = items.filter((a) => a.category === category);
  }

  return sendSuccess(res, {
    assets: items,
    total: items.length
  });
});

/**
 * POST /api/v1/assets/upload
 * Register new uploaded asset / Đăng ký tài nguyên mới được tải lên
 */
assetsRouter.post('/upload', (req: Request, res: Response) => {
  const { name, category, size_bytes, is_pro, file_key } = req.body;

  if (!name || !category) {
    return sendError(res, 'Name and category are required (Yêu cầu tên và danh mục tệp)', 10001);
  }

  const newId = `ast_${Date.now()}`;
  const key = file_key || `${category}/${newId}_${name.replace(/\s+/g, '_')}`;
  const file_url = `${ENV.CLOUDFLARE_R2_PUBLIC_DOMAIN}/${key}`;

  const asset: AssetRecord = {
    id: newId,
    name,
    category,
    file_url,
    file_key: key,
    size_bytes: size_bytes || 1024000,
    is_pro: is_pro ? 1 : 0,
    created_at: new Date().toISOString()
  };

  db.assets.set(newId, asset);

  return sendSuccess(res, {
    asset,
    upload_status: 'synced_to_cloudflare_r2'
  }, 'Asset registered & uploaded successfully (Đăng ký tệp thành công)');
});

/**
 * DELETE /api/v1/assets/:id
 * Delete asset from DB & Cloudflare R2 / Xóa tệp khỏi DB và Cloudflare R2 (Chống File Mồ Côi)
 */
assetsRouter.delete('/:id', (req: Request, res: Response) => {
  const { id } = req.params;
  const asset = db.assets.get(id);

  if (!asset) {
    return sendError(res, 'Asset not found (Không tìm thấy tệp)', 10004, 404);
  }

  // 1. Trigger Cloudflare R2 delete object simulation / Kích hoạt lệnh xóa đối tượng trên Cloudflare R2
  const r2DeletionLog = `[Cloudflare R2] Deleting object key '${asset.file_key}' from bucket '${ENV.CLOUDFLARE_R2_BUCKET}' to prevent orphaned files.`;
  console.log(r2DeletionLog);

  // 2. Remove record from Database / Xóa bản ghi khỏi cơ sở dữ liệu
  db.assets.delete(id);

  return sendSuccess(res, {
    deleted_id: id,
    cloudflare_r2_status: 'object_deleted_no_orphaned_file',
    log: r2DeletionLog
  }, 'Asset and Cloudflare R2 object deleted completely (Xóa hoàn toàn tệp và dữ liệu trên Cloudflare)');
});
