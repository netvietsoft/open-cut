/**
 * Backend API & Microservices Unit & Integration Tests
 * Tests Auth, SSE Stream Endpoint, Paywall Detain Retention, Templates, and Cloudflare R2 Asset Deletion.
 */

import request from 'supertest';
import app from './server';

describe('NextAI OpenCut Backend & Gateway Test Suite (Port 6033)', () => {
  // 1. Test Auth Endpoint / Kiểm thử đăng nhập
  it('POST /api/v1/passport/login should authenticate and issue JWT token', async () => {
    const res = await request(app)
      .post('/api/v1/passport/login')
      .send({ username: 'admin', email: 'admin@nextai.com', device_id: 'test_dev_01' });

    expect(res.status).toBe(200);
    expect(res.body.code).toBe(0);
    expect(res.body.data).toHaveProperty('token');
    expect(res.body.data.user_info.username).toBe('admin');
  });

  // 2. Test Commerce Products & Detain Strategy / Kiểm thử gói cước & Giữ chân người dùng
  it('POST /api/commerce/v1/subscription/products should return VIP catalog', async () => {
    const res = await request(app)
      .post('/api/commerce/v1/subscription/products')
      .send({});

    expect(res.status).toBe(200);
    expect(res.body.data.products.length).toBeGreaterThan(0);
    expect(res.body.data.products[1].sku_id).toBe('com.nextai.opencut.pro.annual');
  });

  it('POST /api/commerce/v1/subscription/detain_strategy should return 20% discount on 1st exit attempt', async () => {
    const res = await request(app)
      .post('/api/commerce/v1/subscription/detain_strategy')
      .send({ exit_attempt_count: 1 });

    expect(res.status).toBe(200);
    expect(res.body.data.tier).toBe(1);
    expect(res.body.data.discount_percent).toBe(20);
    expect(res.body.data.voucher_code).toBe('NEXTAI_PRO_20_PERCENT');
  });

  it('POST /api/commerce/v1/subscription/detain_strategy should return 3-day trial on 2nd exit attempt', async () => {
    const res = await request(app)
      .post('/api/commerce/v1/subscription/detain_strategy')
      .send({ exit_attempt_count: 2 });

    expect(res.status).toBe(200);
    expect(res.body.data.tier).toBe(2);
    expect(res.body.data.free_trial_days).toBe(3);
  });

  // 3. Test Template Feed (CutSame) / Kiểm thử danh sách mẫu
  it('GET /api/feed/v2/templates/recommend should return trending templates', async () => {
    const res = await request(app).get('/api/feed/v2/templates/recommend');

    expect(res.status).toBe(200);
    expect(res.body.data.items.length).toBeGreaterThan(0);
    expect(res.body.data.items[0]).toHaveProperty('template_config');
  });

  // 4. Test Cloudflare R2 Asset Deletion (Anti-Orphan) / Kiểm thử xóa tệp chống file mồ côi
  it('DELETE /api/v1/assets/:id should delete DB record and Cloudflare R2 object', async () => {
    // Upload first
    const uploadRes = await request(app)
      .post('/api/v1/assets/upload')
      .send({ name: 'Temp Test LUT', category: 'effect', size_bytes: 1024 });

    const newId = uploadRes.body.data.asset.id;

    // Delete and verify
    const delRes = await request(app).delete(`/api/v1/assets/${newId}`);
    expect(delRes.status).toBe(200);
    expect(delRes.body.data.cloudflare_r2_status).toBe('object_deleted_no_orphaned_file');
  });

  // 5. Test Admin Dashboard Metrics / Kiểm thử số liệu dashboard
  it('GET /api/admin/dashboard/stats should return system metrics for port 6033', async () => {
    const res = await request(app).get('/api/admin/dashboard/stats');

    expect(res.status).toBe(200);
    expect(res.body.data.server_port).toBe(6033);
    expect(res.body.data.status).toBe('ONLINE');
  });
});
