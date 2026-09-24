/**
 * NextAI OpenCut API Gateway & Web CMS Server
 * Máy chủ trung tâm khởi chạy trên cổng 6033 phục vụ API, Luồng SSE và Giao diện Web CMS.
 *
 * @author NextAI Technology Architecture Team
 * @license Proprietary
 */

import express from 'express';
import cors from 'cors';
import path from 'path';
import swaggerUi from 'swagger-ui-express';

import { ENV } from './config/environment';
import { swaggerSpec } from './swagger/swagger';
import { authRouter } from './modules/auth/auth.controller';
import { aiRouter } from './modules/ai-agent/ai.controller';
import { commerceRouter } from './modules/commerce/commerce.controller';
import { templatesRouter } from './modules/templates/templates.controller';
import { editorRouter } from './modules/editor/editor.controller';
import { assetsRouter } from './modules/assets/assets.controller';
import { adminRouter } from './modules/admin-cms/admin.controller';

const app = express();

// 1. Basic Middlewares / Các Middleware cơ bản
app.use(cors({ origin: '*', methods: ['GET', 'POST', 'PUT', 'DELETE', 'OPTIONS'] }));
app.use(express.json({ limit: '50mb' }));
app.use(express.urlencoded({ extended: true, limit: '50mb' }));

// 2. Request Logger / Ghi nhật ký yêu cầu
app.use((req, res, next) => {
  const start = Date.now();
  res.on('finish', () => {
    const duration = Date.now() - start;
    console.log(`[${new Date().toISOString()}] ${req.method} ${req.originalUrl} - ${res.statusCode} (${duration}ms)`);
  });
  next();
});

// 3. Serve Web Admin CMS Static Frontend / Phục vụ giao diện Web CMS tại root
const publicDir = path.join(__dirname, '../public');
app.use(express.static(publicDir));

// 4. Swagger OpenAPI UI / Giao diện tài liệu Swagger
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerSpec, {
  customCss: '.swagger-ui .topbar { background-color: #0D0E12; }',
  customSiteTitle: 'NextAI OpenCut API Documentation'
}));

// 5. Mount API Routes / Đăng ký các tuyến API
app.use('/api/v1/passport', authRouter);

// AI Lab & SSE Endpoints (Supports both prefix variants for 100% parity / Hỗ trợ cả 2 định dạng đường dẫn)
app.use('/api/storyboard_agent/v1/ai_lab', aiRouter);
app.use('/storyboard_agent/v1/ai_lab', aiRouter);
app.use('/lv/v1/trend_agent', aiRouter);

app.use('/api/commerce/v1', commerceRouter);
app.use('/api/feed/v2/templates', templatesRouter);
app.use('/api/editor/v1', editorRouter);
app.use('/api/v1/assets', assetsRouter);
app.use('/api/admin', adminRouter);

// 6. SPA Fallback for Web CMS / Điều hướng Single Page App cho CMS
app.get('*', (req, res, next) => {
  if (req.originalUrl.startsWith('/api') || req.originalUrl.startsWith('/storyboard_agent')) {
    return next();
  }
  return res.sendFile(path.join(publicDir, 'index.html'));
});

// 7. Start Server on Port 6033 / Khởi chạy máy chủ tại cổng 6033
export const server = app.listen(ENV.PORT, ENV.HOST, () => {
  console.log('================================================================');
  console.log(`🚀 NextAI OpenCut API Gateway & Web CMS is ONLINE`);
  console.log(`🌐 Server Port: ${ENV.PORT}`);
  console.log(`💻 Web Admin CMS: http://localhost:${ENV.PORT}/`);
  console.log(`📖 Swagger API Docs: http://localhost:${ENV.PORT}/api-docs`);
  console.log(`🤖 AI SSE Endpoint: http://localhost:${ENV.PORT}/api/storyboard_agent/v1/ai_lab/send_msg`);
  console.log('================================================================');
});

export default app;
