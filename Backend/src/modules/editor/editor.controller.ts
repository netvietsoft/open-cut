/**
 * Editor & Project Controller / Bộ Điều Khiển Dự Án Biên Tập & Dòng Thời Gian
 * Manages project drafts, timeline tracks, and speech recognition ASR.
 * Quản lý bản nháp dự án, cấu trúc track dòng thời gian và nhận diện giọng nói.
 */

import { Router, Request, Response } from 'express';
import { db, ProjectRecord } from '../../database/db';
import { sendSuccess, sendError } from '../../middleware/response';

export const editorRouter = Router();

/**
 * POST /api/editor/v1/projects/save
 * Save or update video project timeline / Lưu hoặc cập nhật bản nháp dự án
 */
editorRouter.post('/projects/save', (req: Request, res: Response) => {
  const { id, title, duration_ms, aspect_ratio, timeline_json, user_id } = req.body;
  const projId = id || `proj_${Date.now()}`;

  const project: ProjectRecord = {
    id: projId,
    user_id: user_id || 'usr_admin_001',
    title: title || 'Dự án mới chưa đặt tên',
    cover_url: req.body.cover_url || 'https://images.unsplash.com/photo-1574717024653-61fd2cf4d44d?w=300',
    duration_ms: duration_ms || 10000,
    aspect_ratio: aspect_ratio || '9:16',
    timeline_json: typeof timeline_json === 'string' ? timeline_json : JSON.stringify(timeline_json || {}),
    cloud_size_bytes: req.body.cloud_size_bytes || 1048576,
    is_cloud_synced: 1,
    updated_at: new Date().toISOString()
  };

  db.projects.set(projId, project);
  return sendSuccess(res, project, 'Project saved successfully (Lưu dự án thành công)');
});

/**
 * GET /api/editor/v1/projects/list
 * List user drafts / Lấy danh sách dự án bản nháp của người dùng
 */
editorRouter.get('/projects/list', (req: Request, res: Response) => {
  const list = Array.from(db.projects.values());
  return sendSuccess(res, {
    projects: list,
    total_count: list.length
  });
});

/**
 * POST /api/editor/v1/asr/speech_to_text
 * Mock ASR Engine for Subtitle Generation / Mô phỏng bộ chuyển giọng nói thành phụ đề
 */
editorRouter.post('/asr/speech_to_text', (req: Request, res: Response) => {
  const mockSubtitles = [
    { start_ms: 500, end_ms: 2200, text: 'Chào mừng các bạn đến với video mới nhất!' },
    { start_ms: 2500, end_ms: 4800, text: 'Hôm nay chúng ta sẽ cùng khám phá AI biên tập video.' },
    { start_ms: 5000, end_ms: 7200, text: 'NextAI OpenCut mang đến trải nghiệm biên tập cực mượt mà.' }
  ];

  return sendSuccess(res, {
    subtitles: mockSubtitles,
    language: 'vi',
    confidence: 0.985
  });
});
