/**
 * KMP AI Agent Core — Conversation Domain Models
 * Shared 100% across Android, iOS, Web, and Desktop.
 * Chia sẻ 100% mã nguồn quản lý phiên hội thoại AI giữa các nền tảng.
 */

package com.nextai.opencut.kmp.agent.core

import kotlinx.serialization.Serializable

@Serializable
data class Conversation(
    val id: String,
    val userId: String,
    val scene: String = "ailab_agent_v1.1",
    val title: String,
    val createdAt: String,
    val updatedAt: String
)

@Serializable
data class ChatMessage(
    val id: String,
    val conversationId: String,
    val senderType: String, // "user", "assistant", "system", "tool"
    val content: String,
    val toolCalls: List<ToolCall>? = null,
    val timestamp: Long = System.currentTimeMillis()
)

@Serializable
data class ToolCall(
    val name: String,
    val args: Map<String, String>
)

/**
 * Conversation Repository Interface / Giao Diện Kho Lưu Trữ Phiên Hội Thoại
 */
interface ConversationRepository {
    suspend fun getConversation(id: String): Conversation?
    suspend fun saveConversation(conversation: Conversation)
    suspend fun getMessages(conversationId: String): List<ChatMessage>
    suspend fun appendMessage(message: ChatMessage)
}

/**
 * In-Memory Implementation for Fast Multiplatform Execution
 * Triển khai lưu trữ bộ nhớ nhanh tương thích đa nền tảng.
 */
class InMemoryConversationRepo : ConversationRepository {
    private val conversations = mutableMapOf<String, Conversation>()
    private val messages = mutableMapOf<String, MutableList<ChatMessage>>()

    override suspend fun getConversation(id: String): Conversation? = conversations[id]

    override suspend fun saveConversation(conversation: Conversation) {
        conversations[conversation.id] = conversation
    }

    override suspend fun getMessages(conversationId: String): List<ChatMessage> =
        messages[conversationId]?.toList() ?: emptyList()

    override suspend fun appendMessage(message: ChatMessage) {
        val list = messages.getOrPut(message.conversationId) { mutableListOf() }
        list.add(message)
    }
}
