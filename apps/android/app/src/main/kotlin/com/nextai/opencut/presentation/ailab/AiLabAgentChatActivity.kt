/**
 * AiLabAgentChatActivity — AI Video Copilot Chat Screen
 * Live SSE streaming client with Model Context Protocol (MCP) tool visualization.
 * Giao diện tương tác AI Copilot kết nối luồng SSE và điều phối công cụ MCP.
 */

package com.nextai.opencut.presentation.ailab

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import kotlinx.coroutines.launch
import com.nextai.opencut.kmp.agent.core.*

class AiLabAgentChatActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            AiLabChatScreen(onBack = { finish() })
        }
    }
}

@Composable
fun AiLabChatScreen(onBack: () -> Unit) {
    val coroutineScope = rememberCoroutineScope()
    val repo = remember { InMemoryConversationRepo() }
    val protocol = remember { DefaultAgentMessagingProtocol(repo) }

    var inputText by remember { mutableStateOf("") }
    val messageList = remember { mutableStateListOf<ChatMessage>() }
    var isStreaming by remember { mutableStateOf(false) }

    LaunchedEffect(Unit) {
        // Initial greeting
        messageList.add(
            ChatMessage(
                id = "msg_init",
                conversationId = "sess_001",
                senderType = "assistant",
                content = "Xin chào! Tôi là NextAI Video Copilot. Hãy yêu cầu tôi: \"Cắt video từ 1s đến 4s\", \"Tạo phụ đề tự động\", hoặc \"Thêm hiệu ứng điện ảnh\"."
            )
        )
    }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF0D0E12))
    ) {
        // Header Bar
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .background(Color(0xFF13151C))
                .padding(16.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            IconButton(onClick = onBack) {
                Text("←", color = Color.White, fontSize = 22.sp)
            }
            Spacer(modifier = Modifier.width(8.dp))
            Column {
                Text("AI Video Copilot (MCP SSE)", color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold, fontSize = 16.sp)
                Text("Trực tuyến • Port 6033 • Model Context Protocol", color = Color(0xFF10B981), fontSize = 11.sp)
            }
        }

        // Messages List
        LazyColumn(
            modifier = Modifier
                .weight(1f)
                .fillMaxWidth()
                .padding(16.dp),
            verticalArrangement = Arrangement.spacedBy(12.dp)
        ) {
            items(messageList) { msg ->
                ChatBubble(msg)
            }
        }

        // Input Field Bar
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .background(Color(0xFF13151C))
                .padding(12.dp),
            verticalAlignment = Alignment.CenterVertically
        ) {
            TextField(
                value = inputText,
                onValueChange = { inputText = it },
                placeholder = { Text("Nhập yêu cầu AI (VD: Cắt video 1s đến 4s)...", fontSize = 13.sp, color = Color(0xFF94A3B8)) },
                modifier = Modifier.weight(1f),
                colors = TextFieldDefaults.colors(
                    focusedContainerColor = Color(0xFF1A1D27),
                    unfocusedContainerColor = Color(0xFF1A1D27),
                    focusedTextColor = Color.White,
                    unfocusedTextColor = Color.White
                ),
                shape = RoundedCornerShape(12.dp)
            )

            Spacer(modifier = Modifier.width(8.dp))

            Button(
                onClick = {
                    if (inputText.isNotBlank() && !isStreaming) {
                        val prompt = inputText
                        inputText = ""
                        messageList.add(
                            ChatMessage(
                                id = "u_${System.currentTimeMillis()}",
                                conversationId = "sess_001",
                                senderType = "user",
                                content = prompt
                            )
                        )

                        // Stream from Protocol
                        coroutineScope.launch {
                            isStreaming = true
                            var botResponse = ""
                            var botToolCalls: List<ToolCall>? = null

                            protocol.sendPromptStream("sess_001", prompt).collect { chunk ->
                                botResponse += chunk.delta
                                if (chunk.toolCall != null) {
                                    botToolCalls = listOf(chunk.toolCall)
                                }
                            }

                            messageList.add(
                                ChatMessage(
                                    id = "b_${System.currentTimeMillis()}",
                                    conversationId = "sess_001",
                                    senderType = "assistant",
                                    content = botResponse,
                                    toolCalls = botToolCalls
                                )
                            )
                            isStreaming = false
                        }
                    }
                },
                colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF00E5FF)),
                shape = RoundedCornerShape(12.dp)
            ) {
                Text("GỬI", color = Color.Black, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
            }
        }
    }
}

@Composable
fun ChatBubble(msg: ChatMessage) {
    val isUser = msg.senderType == "user"
    Row(
        modifier = Modifier.fillMaxWidth(),
        horizontalArrangement = if (isUser) Arrangement.End else Arrangement.Start
    ) {
        Box(
            modifier = Modifier
                .fillMaxWidth(0.85f)
                .background(
                    if (isUser) Color(0xFF0088CC) else Color(0xFF1A1D27),
                    RoundedCornerShape(14.dp)
                )
                .padding(14.dp)
        ) {
            Column {
                Text(
                    text = if (isUser) "Bạn" else "🤖 NextAI Agent",
                    color = if (isUser) Color(0xFFE0F2FE) else Color(0xFF00E5FF),
                    fontSize = 11.sp,
                    fontWeight = androidx.compose.ui.text.font.FontWeight.Bold
                )
                Spacer(modifier = Modifier.height(4.dp))
                Text(msg.content, color = Color.White, fontSize = 14.sp)

                if (msg.toolCalls != null) {
                    Spacer(modifier = Modifier.height(8.dp))
                    Box(
                        modifier = Modifier
                            .fillMaxWidth()
                            .background(Color(0xFF13151C), RoundedCornerShape(8.dp))
                            .padding(8.dp)
                    ) {
                        Text(
                            "⚡ Đã thực thi công cụ MCP: [${msg.toolCalls.first().name}]",
                            color = Color(0xFFFFB300),
                            fontSize = 11.sp,
                            fontWeight = androidx.compose.ui.text.font.FontWeight.Bold
                        )
                    }
                }
            }
        }
    }
}
