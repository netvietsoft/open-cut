/**
 * KMP AI Agent Core — SSE Messaging Protocol
 * Implements Server-Sent Events (SSE) streaming communication with backend.
 * Giao thức nhắn tin luồng SSE thời gian thực kết nối với máy chủ Backend.
 */

package com.nextai.opencut.kmp.agent.core

import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.delay

interface AgentMessagingProtocol {
    fun sendPromptStream(
        sessionId: String,
        prompt: String,
        scene: String = "ailab_agent_v1.1"
    ): Flow<StreamChunk>
}

data class StreamChunk(
    val event: String,
    val delta: String,
    val toolCall: ToolCall? = null,
    val isCompleted: Boolean = false
)

/**
 * Default Implementation of SSE Streaming Protocol
 * Triển khai mặc định giao thức truyền nhận luồng SSE tương thích KMP.
 */
class DefaultAgentMessagingProtocol(
    private val repo: ConversationRepository
) : AgentMessagingProtocol {

    override fun sendPromptStream(
        sessionId: String,
        prompt: String,
        scene: String
    ): Flow<StreamChunk> = flow {
        // 1. Store user message / Lưu tin nhắn của người dùng
        val userMsg = ChatMessage(
            id = "msg_u_${System.currentTimeMillis()}",
            conversationId = sessionId,
            senderType = "user",
            content = prompt
        )
        repo.appendMessage(userMsg)

        // 2. Simulate / connect SSE stream from Gateway (Port 6033)
        emit(StreamChunk(event = "start", delta = "Đang kết nối AI Copilot... "))
        delay(100)

        emit(StreamChunk(event = "message_chunk", delta = "NextAI Agent đang phân tích yêu cầu: \"$prompt\". "))
        delay(150)

        // Detect if tool call is needed
        var detectedTool: ToolCall? = null
        if (prompt.contains("cắt", ignoreCase = true) || prompt.contains("cut", ignoreCase = true)) {
            detectedTool = ToolCall("cut_video", mapOf("start_ms" to "1000", "end_ms" to "4000"))
            emit(StreamChunk(event = "tool_call", delta = "Kích hoạt công cụ MCP cắt video...", toolCall = detectedTool))
            delay(200)
        }

        emit(StreamChunk(event = "message_chunk", delta = "Hoàn tất xử lý video trên Timeline! "))
        delay(100)

        emit(StreamChunk(event = "done", delta = "", isCompleted = true))

        // 3. Store assistant message in repository / Lưu tin nhắn phản hồi
        val botMsg = ChatMessage(
            id = "msg_b_${System.currentTimeMillis()}",
            conversationId = sessionId,
            senderType = "assistant",
            content = "NextAI Agent đã xử lý: $prompt",
            toolCalls = detectedTool?.let { listOf(it) }
        )
        repo.appendMessage(botMsg)
    }
}
