/**
 * Database Module / Module Cơ sở Dữ liệu
 * Sets up relational schema matching PostgreSQL 16 / SQLite for NextAI OpenCut.
 * Thiết lập lược đồ quan hệ tương thích 100% với PostgreSQL 16 / SQLite cho NextAI OpenCut.
 */

export interface UserRecord {
  id: string;
  username: string;
  email: string;
  avatar_url: string;
  device_id: string;
  is_vip: number;
  vip_expire_at: string | null;
  free_credits_today: number;
  created_at: string;
}

export interface SubscriptionRecord {
  id: string;
  user_id: string;
  sku_id: string;
  platform: string;
  purchase_token: string;
  order_id: string;
  status: string;
  auto_renew: number;
  current_period_end: string;
  created_at: string;
}

export interface ProjectRecord {
  id: string;
  user_id: string;
  title: string;
  cover_url: string;
  duration_ms: number;
  aspect_ratio: string;
  timeline_json: string;
  cloud_size_bytes: number;
  is_cloud_synced: number;
  updated_at: string;
}

export interface TemplateRecord {
  id: string;
  author_id: string;
  title: string;
  demo_video_url: string;
  music_id: string;
  slots_count: number;
  template_config: string;
  usage_count: number;
  likes_count: number;
  is_pro: number;
  created_at: string;
}

export interface AiConversationRecord {
  id: string;
  user_id: string;
  scene: string;
  title: string;
  created_at: string;
  updated_at: string;
}

export interface AiMessageRecord {
  id: string;
  conversation_id: string;
  sender_type: string;
  content: string;
  tool_calls: string | null;
  media_attachments: string | null;
  tokens_used: number;
  created_at: string;
}

export interface AssetRecord {
  id: string;
  name: string;
  category: 'audio' | 'video' | 'image' | 'font' | 'effect' | 'sticker';
  file_url: string;
  file_key: string;
  size_bytes: number;
  is_pro: number;
  created_at: string;
}

export interface DeviceRecord {
  device_id: string;
  user_id: string | null;
  device_model: string;
  os_version: string;
  app_version: string;
  ip_address: string;
  last_active_at: string;
}

/**
 * In-Memory & Relational Mock Storage Instance
 * Quản lý dữ liệu quan hệ trong bộ nhớ và hỗ trợ truy vấn nhanh.
 */
class DatabaseManager {
  public users: Map<string, UserRecord> = new Map();
  public subscriptions: Map<string, SubscriptionRecord> = new Map();
  public projects: Map<string, ProjectRecord> = new Map();
  public templates: Map<string, TemplateRecord> = new Map();
  public aiConversations: Map<string, AiConversationRecord> = new Map();
  public aiMessages: Map<string, AiMessageRecord> = new Map();
  public assets: Map<string, AssetRecord> = new Map();
  public devices: Map<string, DeviceRecord> = new Map();

  constructor() {
    this.seedInitialData();
  }

  /**
   * Seed Initial Sample Data / Nạp dữ liệu mẫu ban đầu
   */
  public seedInitialData() {
    // 1. Seed Users / Nạp người dùng mẫu
    const adminUser: UserRecord = {
      id: 'usr_admin_001',
      username: 'admin',
      email: 'admin@nextai.com',
      avatar_url: 'https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?w=150',
      device_id: 'dev_pixel8_pro_001',
      is_vip: 1,
      vip_expire_at: '2027-12-31T23:59:59Z',
      free_credits_today: 9999,
      created_at: new Date().toISOString()
    };
    const creatorUser: UserRecord = {
      id: 'usr_creator_002',
      username: 'AlexCreator',
      email: 'alex.creator@example.com',
      avatar_url: 'https://images.unsplash.com/photo-1570295999919-56ceb5ecca61?w=150',
      device_id: 'dev_galaxy_s24_002',
      is_vip: 1,
      vip_expire_at: '2026-10-15T00:00:00Z',
      free_credits_today: 50,
      created_at: new Date().toISOString()
    };
    const freeUser: UserRecord = {
      id: 'usr_free_003',
      username: 'SarahFree',
      email: 'sarah.vlog@example.com',
      avatar_url: 'https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=150',
      device_id: 'dev_xiaomi_14_003',
      is_vip: 0,
      vip_expire_at: null,
      free_credits_today: 5,
      created_at: new Date().toISOString()
    };

    this.users.set(adminUser.id, adminUser);
    this.users.set(creatorUser.id, creatorUser);
    this.users.set(freeUser.id, freeUser);

    // 2. Seed Subscriptions / Nạp gói đăng ký
    const subRecord: SubscriptionRecord = {
      id: 'sub_vip_annual_001',
      user_id: creatorUser.id,
      sku_id: 'com.nextai.opencut.pro.annual',
      platform: 'google_play',
      purchase_token: 'gplay_token_sample_8888_valid',
      order_id: 'GPA.3344-5566-7788-99000',
      status: 'active',
      auto_renew: 1,
      current_period_end: '2026-10-15T00:00:00Z',
      created_at: new Date().toISOString()
    };
    this.subscriptions.set(subRecord.id, subRecord);

    // 3. Seed Devices / Nạp danh sách thiết bị
    this.devices.set('dev_pixel8_pro_001', {
      device_id: 'dev_pixel8_pro_001',
      user_id: adminUser.id,
      device_model: 'Google Pixel 8 Pro',
      os_version: 'Android 15',
      app_version: 'v2.1.0',
      ip_address: '192.168.1.100',
      last_active_at: new Date().toISOString()
    });
    this.devices.set('dev_galaxy_s24_002', {
      device_id: 'dev_galaxy_s24_002',
      user_id: creatorUser.id,
      device_model: 'Samsung Galaxy S24 Ultra',
      os_version: 'Android 14 (OneUI 6.1)',
      app_version: 'v2.1.0',
      ip_address: '192.168.1.105',
      last_active_at: new Date().toISOString()
    });

    // 4. Seed Templates (CutSame) / Nạp mẫu video
    const tpl1: TemplateRecord = {
      id: 'tpl_cinematic_travel_01',
      author_id: creatorUser.id,
      title: 'Cinematic Travel Vlog 4K (Phách Nhạc Sôi Động)',
      demo_video_url: 'https://assets.nextai.com/demos/cinematic_travel.mp4',
      music_id: 'music_electronic_beat_01',
      slots_count: 5,
      template_config: JSON.stringify({
        duration_ms: 15000,
        cuts: [
          { start_ms: 0, end_ms: 3000, effect: 'zoom_in' },
          { start_ms: 3000, end_ms: 6000, effect: 'flash_black' },
          { start_ms: 6000, end_ms: 9000, effect: 'glitch_transition' },
          { start_ms: 9000, end_ms: 12000, effect: 'speed_ramp_fast' },
          { start_ms: 12000, end_ms: 15000, effect: 'fade_out' }
        ]
      }),
      usage_count: 142500,
      likes_count: 89300,
      is_pro: 0,
      created_at: new Date().toISOString()
    };
    const tpl2: TemplateRecord = {
      id: 'tpl_glow_cyberpunk_pro',
      author_id: creatorUser.id,
      title: 'Neon Cyberpunk AI Avatar (VIP Pro)',
      demo_video_url: 'https://assets.nextai.com/demos/cyberpunk_glow.mp4',
      music_id: 'music_synthwave_80s',
      slots_count: 3,
      template_config: JSON.stringify({
        duration_ms: 10000,
        cuts: [
          { start_ms: 0, end_ms: 3500, effect: 'neon_edge' },
          { start_ms: 3500, end_ms: 7000, effect: 'chromatic_aberration' },
          { start_ms: 7000, end_ms: 10000, effect: 'laser_glow' }
        ]
      }),
      usage_count: 56200,
      likes_count: 41800,
      is_pro: 1,
      created_at: new Date().toISOString()
    };
    this.templates.set(tpl1.id, tpl1);
    this.templates.set(tpl2.id, tpl2);

    // 5. Seed Media Assets / Nạp tài nguyên tệp
    this.assets.set('ast_font_bebas_neue', {
      id: 'ast_font_bebas_neue',
      name: 'Bebas Neue Bold Video Font',
      category: 'font',
      file_url: 'https://assets.nextai.com/fonts/BebasNeue-Bold.ttf',
      file_key: 'fonts/BebasNeue-Bold.ttf',
      size_bytes: 145200,
      is_pro: 0,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_effect_cinematic_luts', {
      id: 'ast_effect_cinematic_luts',
      name: 'Hollywood Teal & Orange LUT 3D',
      category: 'effect',
      file_url: 'https://assets.nextai.com/effects/teal_orange.cube',
      file_key: 'effects/teal_orange.cube',
      size_bytes: 524000,
      is_pro: 1,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_audio_synth_beat', {
      id: 'ast_audio_synth_beat',
      name: 'Trending Synthwave Beat 128BPM',
      category: 'audio',
      file_url: 'https://assets.nextai.com/audio/synthwave_beat.mp3',
      file_key: 'audio/synthwave_beat.mp3',
      size_bytes: 4194304,
      is_pro: 0,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_effect_3d_parallax', {
      id: 'ast_effect_3d_parallax',
      name: '3D Parallax Dolly Zoom Spatial Shader',
      category: 'effect',
      file_url: 'https://assets.nextai.com/effects/3d_parallax.glsl',
      file_key: 'effects/3d_parallax.glsl',
      size_bytes: 842000,
      is_pro: 1,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_ar_face_cyber_mask', {
      id: 'ast_ar_face_cyber_mask',
      name: '3D Cybernetic Face Mesh AR Mask (468 pts)',
      category: 'effect',
      file_url: 'https://assets.nextai.com/ar/face_cyber_mask.glb',
      file_key: 'ar/face_cyber_mask.glb',
      size_bytes: 1420000,
      is_pro: 1,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_body_neon_glow', {
      id: 'ast_body_neon_glow',
      name: 'Neon Body Contour & Ghost Trail (33 Pose)',
      category: 'effect',
      file_url: 'https://assets.nextai.com/effects/body_neon.glsl',
      file_key: 'effects/body_neon.glsl',
      size_bytes: 650000,
      is_pro: 0,
      created_at: new Date().toISOString()
    });
    this.assets.set('ast_stk_fire_3d', {
      id: 'ast_stk_fire_3d',
      name: '3D Fire Explosion Vector Sticker (Lottie)',
      category: 'sticker',
      file_url: 'https://assets.nextai.com/stickers/fire_3d.json',
      file_key: 'stickers/fire_3d.json',
      size_bytes: 230000,
      is_pro: 0,
      created_at: new Date().toISOString()
    });
  }
}

export const db = new DatabaseManager();
