/**
 * Environment Configuration / Cấu hình Môi trường
 * Loads and validates environment variables for NextAI OpenCut Backend.
 * Tải và kiểm tra tính hợp lệ của các biến môi trường cho Backend NextAI OpenCut.
 */

import dotenv from 'dotenv';
dotenv.config();

export const ENV = {
  // Server port (Default: 6033) / Cổng máy chủ (Mặc định: 6033)
  PORT: parseInt(process.env.PORT || '6033', 10),
  NODE_ENV: process.env.NODE_ENV || 'development',
  HOST: process.env.HOST || '0.0.0.0',

  // Authentication & Security / Xác thực và Bảo mật
  JWT_SECRET: process.env.JWT_SECRET || 'nextai_opencut_jwt_super_secret_key_2026',
  JWT_EXPIRES_IN: process.env.JWT_EXPIRES_IN || '7200s',

  // Database / Cơ sở dữ liệu
  DB_TYPE: process.env.DB_TYPE || 'sqlite',
  DB_SQLITE_PATH: process.env.DB_SQLITE_PATH || ':memory:',

  // Cloud Storage (Cloudflare R2 / S3) / Lưu trữ đám mây
  STORAGE_PROVIDER: process.env.STORAGE_PROVIDER || 'cloudflare_r2',
  CLOUDFLARE_ACCOUNT_ID: process.env.CLOUDFLARE_ACCOUNT_ID || 'mock_cf_acc_id',
  CLOUDFLARE_R2_ACCESS_KEY: process.env.CLOUDFLARE_R2_ACCESS_KEY || 'mock_r2_access_key',
  CLOUDFLARE_R2_SECRET_KEY: process.env.CLOUDFLARE_R2_SECRET_KEY || 'mock_r2_secret_key',
  CLOUDFLARE_R2_BUCKET: process.env.CLOUDFLARE_R2_BUCKET_NAME || 'nextai-opencut-assets',
  CLOUDFLARE_R2_PUBLIC_DOMAIN: process.env.CLOUDFLARE_R2_PUBLIC_DOMAIN || 'https://assets.nextai.com',

  // AI Service Provider / Nhà cung cấp dịch vụ AI
  AI_PROVIDER: process.env.AI_PROVIDER || 'deepseek',
  AI_API_KEY: process.env.AI_API_KEY || 'sk-mock-nextai-ai-agent-key-2026',
};
