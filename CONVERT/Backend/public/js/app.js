/**
 * NextAI OpenCut Web CMS Reactive Application Script
 * Single-Page Router, Live API Data Binding, CRUD Modals & Theme Switching.
 */

// Global State / Trạng thái toàn cục
const state = {
  currentRoute: 'dashboard',
  theme: localStorage.getItem('opencut_theme') || 'dark',
  stats: null,
  users: [],
  devices: [],
  templates: [],
  assets: []
};

// 1. Initialize Application / Khởi tạo ứng dụng
document.addEventListener('DOMContentLoaded', () => {
  initTheme();
  initRouter();
  initEventListeners();
});

// 2. Theme Switching Logic / Chuyển đổi giao diện Sáng - Tối
function initTheme() {
  document.documentElement.setAttribute('data-theme', state.theme);
  updateThemeButton();
}

function updateThemeButton() {
  const icon = document.getElementById('themeIcon');
  const label = document.getElementById('themeLabel');
  if (state.theme === 'dark') {
    icon.textContent = '☀️';
    label.textContent = 'Giao diện Sáng';
  } else {
    icon.textContent = '🌙';
    label.textContent = 'Giao diện Tối';
  }
}

function toggleTheme() {
  state.theme = state.theme === 'dark' ? 'light' : 'dark';
  localStorage.setItem('opencut_theme', state.theme);
  initTheme();
  showToast(`Đã chuyển sang ${state.theme === 'dark' ? 'Giao diện Tối' : 'Giao diện Sáng'}`);
}

// 3. Single-Page Routing Logic / Điều hướng trang đơn URL domain.com/ParentMenu/SubMenu
function initRouter() {
  window.addEventListener('hashchange', handleRoute);
  handleRoute();
}

function handleRoute() {
  const hash = window.location.hash || '#/dashboard/overview';
  const parts = hash.replace('#/', '').split('/');
  const parent = parts[0] || 'dashboard';
  const child = parts[1] || 'overview';

  state.currentRoute = parent;

  // Update Breadcrumbs
  const breadcrumbChild = document.getElementById('breadcrumbChild');
  if (breadcrumbChild) {
    breadcrumbChild.textContent = `${parent.toUpperCase()} / ${child.toUpperCase()}`;
  }

  // Update active sidebar menu item
  document.querySelectorAll('.menu-item').forEach((item) => {
    item.classList.toggle('active', item.getAttribute('data-route') === parent);
  });

  // Close mobile sidebar if open
  document.querySelector('.sidebar')?.classList.remove('open');

  // Render view
  renderView(parent, child);
}

// 4. View Renderers / Các hàm hiển thị giao diện
async function renderView(parent, child) {
  const container = document.getElementById('routeContent');
  container.innerHTML = '<div style="text-align:center; padding: 40px;">⏳ Đang tải dữ liệu thời gian thực từ Port 6033...</div>';

  switch (parent) {
    case 'dashboard':
      await renderDashboard(container);
      break;
    case 'users':
      await renderUsers(container);
      break;
    case 'devices':
      await renderDevices(container);
      break;
    case 'templates':
      await renderTemplates(container);
      break;
    case 'assets':
      await renderAssets(container);
      break;
    case 'ai-prompts':
      await renderAiPrompts(container);
      break;
    case 'commerce':
      await renderCommerce(container);
      break;
    default:
      await renderDashboard(container);
  }
}

// Dashboard View
async function renderDashboard(container) {
  try {
    const res = await fetch('/api/admin/dashboard/stats');
    const json = await res.json();
    const stats = json.data;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Tổng Quan Hoạt Động Hệ Thống (Port 6033)</h2>
        <button class="btn btn-primary" onclick="renderView('dashboard')">🔄 Làm Mới Dữ Liệu</button>
      </div>

      <div class="stats-grid">
        <div class="stat-card">
          <div class="stat-icon">👥</div>
          <div class="stat-info">
            <h3>${stats.total_users}</h3>
            <p>Tổng Người Dùng</p>
          </div>
        </div>
        <div class="stat-card">
          <div class="stat-icon">👑</div>
          <div class="stat-info">
            <h3>${stats.vip_subscribers}</h3>
            <p>Hội Viên VIP Pro</p>
          </div>
        </div>
        <div class="stat-card">
          <div class="stat-icon">📱</div>
          <div class="stat-info">
            <h3>${stats.active_devices}</h3>
            <p>Thiết Bị Đăng Ký</p>
          </div>
        </div>
        <div class="stat-card">
          <div class="stat-icon">🎬</div>
          <div class="stat-info">
            <h3>${stats.total_templates}</h3>
            <p>Mẫu Video (CutSame)</p>
          </div>
        </div>
        <div class="stat-card">
          <div class="stat-icon">☁️</div>
          <div class="stat-info">
            <h3>${stats.total_assets}</h3>
            <p>Tài Sản Media R2</p>
          </div>
        </div>
      </div>

      <div class="section-header" style="margin-top: 24px;">
        <h3 class="section-title" style="font-size: 18px;">Kiến Trúc Tái Dựng & Cổng Kết Nối</h3>
      </div>

      <div class="cards-grid">
        <div class="data-card">
          <div class="data-card-header">
            <span class="card-title">🤖 AI Agent SSE Gateway</span>
            <span class="card-badge badge-vip">ONLINE</span>
          </div>
          <div class="data-card-body">
            <div class="card-row"><span class="card-label">Endpoint:</span><span class="card-value">/storyboard_agent/v1/ai_lab/send_msg</span></div>
            <div class="card-row"><span class="card-label">Giao thức:</span><span class="card-value">Server-Sent Events (SSE)</span></div>
            <div class="card-row"><span class="card-label">MCP Tools:</span><span class="card-value">cut_video, auto_captions, apply_effect</span></div>
          </div>
        </div>

        <div class="data-card">
          <div class="data-card-header">
            <span class="card-title">💳 Paywall Detain Retention</span>
            <span class="card-badge badge-vip">ACTIVE</span>
          </div>
          <div class="data-card-body">
            <div class="card-row"><span class="card-label">Cấp 1:</span><span class="card-value">Giảm 20% gói Annual</span></div>
            <div class="card-row"><span class="card-label">Cấp 2:</span><span class="card-value">Dùng thử 3 ngày / Gói tuần 49k</span></div>
            <div class="card-row"><span class="card-label">Billing:</span><span class="card-value">Google Play Billing v8.2.1 RTDN</span></div>
          </div>
        </div>
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi kết nối máy chủ Port 6033: ${err.message}</div>`;
  }
}

// Users Management View (CRUD)
async function renderUsers(container) {
  try {
    const res = await fetch('/api/admin/users');
    const json = await res.json();
    const users = json.data.users;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Quản Lý Người Dùng Hệ Thống</h2>
        <button class="btn btn-primary" onclick="openCreateUserModal()">➕ Thêm Người Dùng Mới</button>
      </div>

      <div class="cards-grid" id="usersCardGrid">
        ${users.map((u) => `
          <div class="data-card" id="user-card-${u.id}">
            <div class="data-card-header">
              <span class="card-title">${u.username}</span>
              <span class="card-badge ${u.is_vip ? 'badge-vip' : 'badge-free'}">
                ${u.is_vip ? '★ VIP PRO' : 'FREE'}
              </span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">ID:</span><span class="card-value">${u.id}</span></div>
              <div class="card-row"><span class="card-label">Email:</span><span class="card-value">${u.email}</span></div>
              <div class="card-row"><span class="card-label">Free Credits:</span><span class="card-value">${u.free_credits_today}</span></div>
              <div class="card-row"><span class="card-label">Thiết Bị:</span><span class="card-value">${u.device_id}</span></div>
              <div class="card-row"><span class="card-label">Hạn VIP:</span><span class="card-value">${u.vip_expire_at ? u.vip_expire_at.substring(0, 10) : 'Chưa kích hoạt'}</span></div>
            </div>
            <div class="data-card-actions">
              <button class="btn btn-secondary" onclick="openEditUserModal('${u.id}', '${u.username}', '${u.email}', ${u.is_vip}, ${u.free_credits_today})">✏️ Sửa</button>
              <button class="btn btn-danger" onclick="deleteUser('${u.id}')">🗑️ Xóa</button>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải danh sách người dùng: ${err.message}</div>`;
  }
}

// Devices Inventory View
async function renderDevices(container) {
  try {
    const res = await fetch('/api/admin/devices');
    const json = await res.json();
    const devices = json.data.devices;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Danh Sách Thiết Bị Đã Đăng Ký</h2>
        <span class="card-badge badge-vip">${devices.length} Thiết Bị Đang Kết Nối</span>
      </div>

      <div class="cards-grid">
        ${devices.map((d) => `
          <div class="data-card">
            <div class="data-card-header">
              <span class="card-title">${d.device_model}</span>
              <span class="card-badge badge-vip">ACTIVE</span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">Device ID:</span><span class="card-value">${d.device_id}</span></div>
              <div class="card-row"><span class="card-label">Hệ Điều Hành:</span><span class="card-value">${d.os_version}</span></div>
              <div class="card-row"><span class="card-label">App Version:</span><span class="card-value">${d.app_version}</span></div>
              <div class="card-row"><span class="card-label">IP Address:</span><span class="card-value">${d.ip_address}</span></div>
              <div class="card-row"><span class="card-label">Hoạt Động Cuối:</span><span class="card-value">${new Date(d.last_active_at).toLocaleTimeString()}</span></div>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải danh sách thiết bị: ${err.message}</div>`;
  }
}

// Templates View
async function renderTemplates(container) {
  try {
    const res = await fetch('/api/feed/v2/templates/recommend');
    const json = await res.json();
    const templates = json.data.items;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Kho Mẫu Video Thịnh Hành (CutSame Feed)</h2>
        <button class="btn btn-primary" onclick="openCreateTemplateModal()">➕ Đăng Mẫu Mới</button>
      </div>

      <div class="cards-grid">
        ${templates.map((t) => `
          <div class="data-card">
            <div class="data-card-header">
              <span class="card-title">${t.title}</span>
              <span class="card-badge ${t.is_pro ? 'badge-vip' : 'badge-free'}">
                ${t.is_pro ? '★ VIP' : 'FREE'}
              </span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">Slot Thay Thế:</span><span class="card-value">${t.slots_count} slots</span></div>
              <div class="card-row"><span class="card-label">Lượt Dùng:</span><span class="card-value">${t.usage_count.toLocaleString()}</span></div>
              <div class="card-row"><span class="card-label">Lượt Thích:</span><span class="card-value">${t.likes_count.toLocaleString()}</span></div>
              <div class="card-row"><span class="card-label">Thời Lượng:</span><span class="card-value">${t.template_config.duration_ms / 1000}s</span></div>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải mẫu video: ${err.message}</div>`;
  }
}

// Cloudflare R2 Media Assets View (With Orphaned File Prevention)
async function renderAssets(container) {
  try {
    const res = await fetch('/api/v1/assets/list');
    const json = await res.json();
    const assets = json.data.assets;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Quản Lý Tệp Media (Cloudflare R2 Anti-Orphan)</h2>
        <button class="btn btn-primary" onclick="openUploadAssetModal()">☁️ Tải Lên Tệp R2</button>
      </div>

      <div class="cards-grid">
        ${assets.map((a) => `
          <div class="data-card" id="asset-card-${a.id}">
            <div class="data-card-header">
              <span class="card-title">${a.name}</span>
              <span class="card-badge ${a.is_pro ? 'badge-vip' : 'badge-free'}">${a.category.toUpperCase()}</span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">ID:</span><span class="card-value">${a.id}</span></div>
              <div class="card-row"><span class="card-label">R2 Key:</span><span class="card-value">${a.file_key}</span></div>
              <div class="card-row"><span class="card-label">Kích Thước:</span><span class="card-value">${(a.size_bytes / 1024 / 1024).toFixed(2)} MB</span></div>
              <div class="card-row"><span class="card-label">Đồng Bộ:</span><span class="card-value" style="color:var(--accent-success)">Cloudflare R2 OK</span></div>
            </div>
            <div class="data-card-actions">
              <button class="btn btn-danger" onclick="deleteAsset('${a.id}')">🗑️ Xóa Tệp (Xóa Cả Trên R2)</button>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải tài nguyên media: ${err.message}</div>`;
  }
}

// AI Prompts View
async function renderAiPrompts(container) {
  try {
    const res = await fetch('/lv/v1/trend_agent/model_list', { method: 'POST' });
    const json = await res.json();
    const { models, mcp_tools } = json.data;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Điều Phối Mô Hình AI & Công Cụ Chuẩn MCP</h2>
      </div>

      <h3 style="margin-bottom: 16px;">1. Các Mô Hình AI Đang Phục Vụ</h3>
      <div class="cards-grid" style="margin-bottom: 32px;">
        ${models.map((m) => `
          <div class="data-card">
            <div class="data-card-header">
              <span class="card-title">${m.name}</span>
              <span class="card-badge badge-vip">${m.type.toUpperCase()}</span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">Model ID:</span><span class="card-value">${m.id}</span></div>
              <div class="card-row"><span class="card-label">Tốc Độ Xử Lý:</span><span class="card-value">${m.speed}</span></div>
            </div>
          </div>
        `).join('')}
      </div>

      <h3 style="margin-bottom: 16px;">2. Danh Mục Công Cụ Chuẩn Model Context Protocol (MCP)</h3>
      <div class="cards-grid">
        ${mcp_tools.map((t) => `
          <div class="data-card">
            <div class="data-card-header">
              <span class="card-title">${t.name}</span>
              <span class="card-badge badge-vip">MCP TOOL</span>
            </div>
            <div class="data-card-body">
              <p>${t.description}</p>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải cấu hình AI: ${err.message}</div>`;
  }
}

// Commerce View
async function renderCommerce(container) {
  try {
    const res = await fetch('/api/commerce/v1/subscription/products', { method: 'POST' });
    const json = await res.json();
    const products = json.data.products;

    container.innerHTML = `
      <div class="section-header">
        <h2 class="section-title">Gói Cước VIP & Chiến Lược Giữ Chân (Detain Paywall)</h2>
      </div>

      <div class="cards-grid">
        ${products.map((p) => `
          <div class="data-card">
            <div class="data-card-header">
              <span class="card-title">${p.title}</span>
              <span class="card-badge ${p.is_popular ? 'badge-vip' : 'badge-free'}">${p.price}</span>
            </div>
            <div class="data-card-body">
              <div class="card-row"><span class="card-label">SKU ID:</span><span class="card-value">${p.sku_id}</span></div>
              <div class="card-row"><span class="card-label">Thời Hạn:</span><span class="card-value">${p.duration}</span></div>
              <ul style="padding-left: 18px; margin-top: 8px;">
                ${p.benefits.map((b) => `<li>${b}</li>`).join('')}
              </ul>
            </div>
          </div>
        `).join('')}
      </div>
    `;
  } catch (err) {
    container.innerHTML = `<div style="color:var(--accent-danger)">Lỗi tải gói giá: ${err.message}</div>`;
  }
}

// 5. CRUD Operations / Thao tác dữ liệu qua API
async function openCreateUserModal() {
  showModal('Thêm Người Dùng Mới', `
    <form id="createUserForm" onsubmit="handleCreateUser(event)">
      <div class="form-group">
        <label class="form-label">Tên Người Dùng (Username)</label>
        <input type="text" id="newUsername" class="form-input" required placeholder="VD: minhanh_vlog">
      </div>
      <div class="form-group">
        <label class="form-label">Email</label>
        <input type="email" id="newEmail" class="form-input" required placeholder="VD: minhanh@gmail.com">
      </div>
      <div class="form-group">
        <label class="form-label">Cấp Độ VIP</label>
        <select id="newIsVip" class="form-input">
          <option value="0">Tài Khoản Free (5 Credits)</option>
          <option value="1">Tài Khoản VIP Pro (100 Credits)</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="width:100%; margin-top:12px;">Xác Nhận Tạo Người Dùng</button>
    </form>
  `);
}

async function handleCreateUser(e) {
  e.preventDefault();
  const username = document.getElementById('newUsername').value;
  const email = document.getElementById('newEmail').value;
  const is_vip = parseInt(document.getElementById('newIsVip').value, 10);

  const res = await fetch('/api/admin/users/create', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ username, email, is_vip })
  });

  if (res.ok) {
    closeModal();
    showToast(`Đã tạo thành công người dùng: ${username}`);
    renderUsers(document.getElementById('routeContent'));
  }
}

async function openEditUserModal(id, username, email, is_vip, credits) {
  showModal('Cập Nhật Người Dùng', `
    <form id="editUserForm" onsubmit="handleEditUser(event, '${id}')">
      <div class="form-group">
        <label class="form-label">Tên Người Dùng</label>
        <input type="text" id="editUsername" class="form-input" value="${username}" required>
      </div>
      <div class="form-group">
        <label class="form-label">Email</label>
        <input type="email" id="editEmail" class="form-input" value="${email}" required>
      </div>
      <div class="form-group">
        <label class="form-label">Free Credits Hôm Nay</label>
        <input type="number" id="editCredits" class="form-input" value="${credits}" required>
      </div>
      <div class="form-group">
        <label class="form-label">Trạng Thái VIP</label>
        <select id="editIsVip" class="form-input">
          <option value="0" ${!is_vip ? 'selected' : ''}>Tài Khoản Free</option>
          <option value="1" ${is_vip ? 'selected' : ''}>Tài Khoản VIP Pro</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="width:100%; margin-top:12px;">Lưu Thay Đổi</button>
    </form>
  `);
}

async function handleEditUser(e, id) {
  e.preventDefault();
  const username = document.getElementById('editUsername').value;
  const email = document.getElementById('editEmail').value;
  const free_credits_today = document.getElementById('editCredits').value;
  const is_vip = parseInt(document.getElementById('editIsVip').value, 10);

  const res = await fetch(`/api/admin/users/${id}`, {
    method: 'PUT',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ username, email, is_vip, free_credits_today })
  });

  if (res.ok) {
    closeModal();
    showToast(`Đã cập nhật thông tin người dùng: ${username}`);
    renderUsers(document.getElementById('routeContent'));
  }
}

async function deleteUser(id) {
  if (confirm(`Bạn có chắc chắn muốn xóa người dùng ID: ${id}?`)) {
    const res = await fetch(`/api/admin/users/${id}`, { method: 'DELETE' });
    if (res.ok) {
      showToast('Đã xóa người dùng thành công');
      renderUsers(document.getElementById('routeContent'));
    }
  }
}

async function deleteAsset(id) {
  if (confirm(`Xóa tệp ${id}? Thao tác này sẽ xóa đồng thời tệp trên Cloudflare R2 chống file mồ côi.`)) {
    const res = await fetch(`/api/v1/assets/${id}`, { method: 'DELETE' });
    if (res.ok) {
      const json = await res.json();
      showToast(json.message);
      renderAssets(document.getElementById('routeContent'));
    }
  }
}

// 6. UI Helpers: Modal & Toast / Tiện ích giao diện
function showModal(title, contentHtml) {
  document.getElementById('modalTitle').textContent = title;
  document.getElementById('modalBody').innerHTML = contentHtml;
  document.getElementById('modalOverlay').classList.remove('hidden');
}

function closeModal() {
  document.getElementById('modalOverlay').classList.add('hidden');
}

function showToast(message) {
  const container = document.getElementById('toastContainer');
  const toast = document.createElement('div');
  toast.className = 'toast';
  toast.textContent = message;
  container.appendChild(toast);
  setTimeout(() => {
    toast.remove();
  }, 3500);
}

function initEventListeners() {
  document.getElementById('themeToggleBtn')?.addEventListener('click', toggleTheme);
  document.getElementById('modalCloseBtn')?.addEventListener('click', closeModal);
  document.getElementById('mobileMenuBtn')?.addEventListener('click', () => {
    document.querySelector('.sidebar')?.classList.toggle('open');
  });
}
