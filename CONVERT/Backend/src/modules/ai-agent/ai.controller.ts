/**
 * AI Agent Controller / Bộ Điều Khiển AI Agent & Luồng SSE Stream
 * Implements SSE stream and Model Context Protocol (MCP) tool calling.
 * Triển khai luồng Server-Sent Events (SSE) và điều phối công cụ chuẩn MCP.
 */

import { Router, Request, Response } from 'express';
import { db, AiConversationRecord, AiMessageRecord } from '../../database/db';
import { sendSuccess, sendError } from '../../middleware/response';

export const aiRouter = Router();

/**
 * MCP Tool Definitions / Danh sách công cụ chuẩn MCP
 */
export const MCP_TOOLS = [
  {
    name: 'cut_video',
    description: 'Cut and split video clip into segments / Cắt và phân tách đoạn video theo timestamp',
    parameters: {
      type: 'object',
      properties: {
        track_index: { type: 'number', description: 'Index of track' },
        start_ms: { type: 'number', description: 'Start time in milliseconds' },
        end_ms: { type: 'number', description: 'End time in milliseconds' }
      },
      required: ['start_ms', 'end_ms']
    }
  },
  {
    name: 'auto_captions',
    description: 'Generate speech-to-text subtitles / Tự động tạo phụ đề từ âm thanh giọng nói',
    parameters: {
      type: 'object',
      properties: {
        language: { type: 'string', description: 'Source audio language (vi, en, etc.)' },
        font_style: { type: 'string', description: 'Caption typography style' }
      },
      required: ['language']
    }
  },
  {
    name: 'apply_effect',
    description: 'Apply visual effect or transition to timeline / Thêm hiệu ứng hình ảnh hoặc chuyển cảnh',
    parameters: {
      type: 'object',
      properties: {
        effect_id: { type: 'string', description: 'Asset effect identifier' },
        intensity: { type: 'number', description: 'Effect intensity 0.0 to 1.0' }
      },
      required: ['effect_id']
    }
  },
  {
    name: 'generate_script',
    description: 'Generate AI creative storytelling script / Sinh kịch bản sáng tạo video bằng AI',
    parameters: {
      type: 'object',
      properties: {
        topic: { type: 'string', description: 'Topic or product description' },
        target_platform: { type: 'string', description: 'TikTok, YouTube Shorts, Reels' }
      },
      required: ['topic']
    }
  }
];

/**
 * POST /storyboard_agent/v1/ai_lab/send_msg
 * Server-Sent Events (SSE) Streaming Endpoint for AI Copilot Chat.
 * Endpoint phát luồng SSE thời gian thực cho trợ lý AI Copilot.
 */
aiRouter.post('/send_msg', (req: Request, res: Response) => {
  const { session_id, prompt, agent_scene } = req.body;

  if (!prompt) {
    return sendError(res, 'Prompt text is required (Yêu cầu nội dung câu lệnh)', 10001);
  }

  // Set SSE Headers / Thiết lập Header phát luồng sự kiện SSE
  res.setHeader('Content-Type', 'text/event-stream');
  res.setHeader('Cache-Control', 'no-cache');
  res.setHeader('Connection', 'keep-alive');
  res.setHeader('X-Accel-Buffering', 'no');
  res.flushHeaders();

  // Create or retrieve conversation / Tạo hoặc lấy phiên hội thoại
  const convId = session_id || `conv_${Date.now()}`;
  if (!db.aiConversations.has(convId)) {
    db.aiConversations.set(convId, {
      id: convId,
      user_id: 'usr_admin_001',
      scene: agent_scene || 'ailab_agent_v1.1',
      title: prompt.substring(0, 30),
      created_at: new Date().toISOString(),
      updated_at: new Date().toISOString()
    });
  }

  // Record User Message / Lưu tin nhắn của người dùng
  const userMsgId = `msg_u_${Date.now()}`;
  db.aiMessages.set(userMsgId, {
    id: userMsgId,
    conversation_id: convId,
    sender_type: 'user',
    content: prompt,
    tool_calls: null,
    media_attachments: null,
    tokens_used: prompt.length / 4,
    created_at: new Date().toISOString()
  });

  // Decide if prompt triggers an MCP Tool / Xác định gọi công cụ MCP
  let triggeredTool: any = null;
  const lowerPrompt = prompt.toLowerCase();
  if (lowerPrompt.includes('cắt') || lowerPrompt.includes('cut') || lowerPrompt.includes('split')) {
    triggeredTool = {
      name: 'cut_video',
      args: { track_index: 0, start_ms: 1000, end_ms: 4500 }
    };
  } else if (lowerPrompt.includes('phụ đề') || lowerPrompt.includes('caption') || lowerPrompt.includes('subtitle')) {
    triggeredTool = {
      name: 'auto_captions',
      args: { language: 'vi', font_style: 'neon_glow_yellow' }
    };
  } else if (lowerPrompt.includes('hiệu ứng') || lowerPrompt.includes('effect') || lowerPrompt.includes('filter')) {
    triggeredTool = {
      name: 'apply_effect',
      args: { effect_id: 'ast_effect_cinematic_luts', intensity: 0.85 }
    };
  }

  // Stream Token Chunks / Phát các gói tin phản hồi dạng luồng
  const tokens = [
    `Chào bạn! Tôi là NextAI Video Copilot. `,
    `Tôi đã nhận được yêu cầu: "${prompt}". `,
    triggeredTool
      ? `Đang kích hoạt công cụ MCP [${triggeredTool.name}] để xử lý video trên Timeline... `
      : `Đang lập kế hoạch kịch bản sáng tạo phù hợp cho định dạng 9:16... `,
    `Hoàn tất xử lý video với chất lượng tốt nhất!`
  ];

  let index = 0;
  const interval = setInterval(() => {
    if (index < tokens.length) {
      const chunkData = {
        event: 'message_chunk',
        session_id: convId,
        delta: tokens[index],
        tool_call: index === 2 && triggeredTool ? triggeredTool : null,
        timestamp: Date.now()
      };
      res.write(`data: ${JSON.stringify(chunkData)}\n\n`);
      index++;
    } else {
      // Send Complete Event / Gửi sự kiện hoàn tất
      const completeData = {
        event: 'done',
        session_id: convId,
        status: 'completed',
        tokens_total: 128
      };
      res.write(`data: ${JSON.stringify(completeData)}\n\n`);
      clearInterval(interval);
      res.end();

      // Record Assistant Message / Lưu tin nhắn trả lời vào DB
      const botMsgId = `msg_b_${Date.now()}`;
      db.aiMessages.set(botMsgId, {
        id: botMsgId,
        conversation_id: convId,
        sender_type: 'assistant',
        content: tokens.join(''),
        tool_calls: triggeredTool ? JSON.stringify([triggeredTool]) : null,
        media_attachments: null,
        tokens_used: 128,
        created_at: new Date().toISOString()
      });
    }
  }, 100);

  req.on('close', () => {
    clearInterval(interval);
  });
});

/**
 * POST /storyboard_agent/v1/ai_lab/get_remain_free_credit
 * Check daily remaining AI credits / Kiểm tra số lượt tạo video AI miễn phí còn lại
 */
aiRouter.post('/get_remain_free_credit', (req: Request, res: Response) => {
  return sendSuccess(res, {
    free_credits_today: 5,
    max_free_credits: 5,
    reset_in_seconds: 14400,
    is_vip: false,
    vip_benefits_text: 'Nâng cấp Pro để tạo video AI không giới hạn & mở khóa 4K render'
  });
});

/**
 * POST /storyboard_agent/v1/ai_lab/get_conversation_details
 * Fetch conversation history / Lấy lịch sử phiên chat AI
 */
aiRouter.post('/get_conversation_details', (req: Request, res: Response) => {
  const { session_id } = req.body;
  const messages = Array.from(db.aiMessages.values()).filter(
    (m) => m.conversation_id === session_id
  );
  return sendSuccess(res, {
    session_id,
    messages
  });
});

/**
 * POST /lv/v1/trend_agent/model_list
 * Get list of available AI models & tools / Lấy danh sách mô hình và công cụ AI hỗ trợ
 */
aiRouter.post('/model_list', (req: Request, res: Response) => {
  return sendSuccess(res, {
    models: [
      { id: 'deepseek-v3', name: 'DeepSeek-V3 Copilot', type: 'llm', speed: 'fast' },
      { id: 'wan-2.1', name: 'Wan2.1 Text-to-Video HD', type: 'video_gen', speed: 'gpu_render' },
      { id: 'whisper-large-v3', name: 'Whisper Subtitle ASR', type: 'asr', speed: 'realtime' }
    ],
    mcp_tools: MCP_TOOLS
  });
});
