/**
 * NextAI OpenCut Main Activity / Màn Hình Điều Hướng Chính
 * Implements 6 bottom navigation tabs: Edit, Templates, AI Lab, Toolbox, Inbox, Me.
 * Điều phối vòng đời và 6 tab điều hướng gốc từ cấu trúc decompile.
 */

package com.nextai.opencut.presentation

import android.content.Intent
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.nextai.opencut.presentation.compose.subscribe.ComposeSubscribeActivity
import com.nextai.opencut.presentation.editor.VideoEditActivity
import com.nextai.opencut.presentation.ailab.AiLabAgentChatActivity

class MainComposeActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MainScreen(
                onNewProjectClick = {
                    startActivity(Intent(this, VideoEditActivity::class.java))
                },
                onOpenPaywallClick = {
                    startActivity(Intent(this, ComposeSubscribeActivity::class.java))
                },
                onOpenAiChatClick = {
                    startActivity(Intent(this, AiLabAgentChatActivity::class.java))
                }
            )
        }
    }
}

@Composable
fun MainScreen(
    onNewProjectClick: () -> Unit,
    onOpenPaywallClick: () -> Unit,
    onOpenAiChatClick: () -> Unit
) {
    var selectedTab by remember { mutableStateOf(0) }
    val tabNames = listOf("Chỉnh sửa", "Mẫu", "AI Lab", "Công cụ", "Hộp thư", "Tôi")
    val tabIcons = listOf("✂️", "🎬", "🤖", "🧰", "📬", "👤")

    Scaffold(
        bottomBar = {
            NavigationBar(
                containerColor = Color(0xFF13151C),
                tonalElevation = 8.dp
            ) {
                tabNames.forEachIndexed { index, title ->
                    NavigationBarItem(
                        selected = selectedTab == index,
                        onClick = { selectedTab = index },
                        icon = { Text(tabIcons[index], fontSize = 20.sp) },
                        label = { Text(title, fontSize = 11.sp, color = if (selectedTab == index) Color(0xFF00E5FF) else Color(0xFF94A3B8)) }
                    )
                }
            }
        },
        containerColor = Color(0xFF0D0E12)
    ) { padding ->
        Column(
            modifier = Modifier
                .fillMaxSize()
                .padding(padding)
                .padding(16.dp)
        ) {
            // Header Top Bar with VIP Badge / Thanh trạng thái trên
            Row(
                modifier = Modifier.fillMaxWidth(),
                horizontalArrangement = Arrangement.SpaceBetween,
                verticalAlignment = Alignment.CenterVertically
            ) {
                Text(
                    text = "NextAI OpenCut",
                    fontSize = 22.sp,
                    color = Color.White,
                    fontWeight = androidx.compose.ui.text.font.FontWeight.Bold
                )

                Button(
                    onClick = onOpenPaywallClick,
                    colors = ButtonDefaults.buttonColors(containerColor = Color(0xFFFFB300)),
                    shape = RoundedCornerShape(16.dp),
                    contentPadding = PaddingValues(horizontal = 12.dp, vertical = 6.dp)
                ) {
                    Text("👑 NÂNG CẤP PRO", color = Color.Black, fontSize = 12.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                }
            }

            Spacer(modifier = Modifier.height(24.dp))

            // Main Tab Content Router / Nội dung theo từng tab
            when (selectedTab) {
                0 -> EditTabContent(onNewProjectClick, onOpenAiChatClick)
                1 -> TemplatesTabContent()
                2 -> AiLabTabContent(onOpenAiChatClick)
                3 -> ToolboxTabContent()
                4 -> InboxTabContent()
                5 -> ProfileTabContent(onOpenPaywallClick)
            }
        }
    }
}

@Composable
fun EditTabContent(onNewProjectClick: () -> Unit, onOpenAiChatClick: () -> Unit) {
    Column(modifier = Modifier.fillMaxSize()) {
        // Big "New Project" Center Button / Nút Dự Án Mới
        Button(
            onClick = onNewProjectClick,
            modifier = Modifier
                .fillMaxWidth()
                .height(110.dp),
            shape = RoundedCornerShape(16.dp),
            colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF1A1D27))
        ) {
            Column(horizontalAlignment = Alignment.CenterHorizontally) {
                Text("➕", fontSize = 32.sp)
                Spacer(modifier = Modifier.height(6.dp))
                Text("Dự Án Mới (New Project)", fontSize = 16.sp, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
            }
        }

        Spacer(modifier = Modifier.height(20.dp))

        // Quick Shortcuts / Lối tắt nhanh
        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween) {
            QuickActionItem("🤖 AI Copilot", onOpenAiChatClick)
            QuickActionItem("✂️ Xóa Phông", onNewProjectClick)
            QuickActionItem("💬 Phụ Đề Tự Động", onNewProjectClick)
            QuickActionItem("✨ Nét Ảnh AI", onNewProjectClick)
        }

        Spacer(modifier = Modifier.height(24.dp))
        Text("Dự Án Bản Nháp (Recent Projects)", fontSize = 16.sp, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Spacer(modifier = Modifier.height(12.dp))

        Card(
            modifier = Modifier.fillMaxWidth(),
            colors = CardDefaults.cardColors(containerColor = Color(0xFF1A1D27)),
            shape = RoundedCornerShape(12.dp)
        ) {
            Row(modifier = Modifier.padding(14.dp), verticalAlignment = Alignment.CenterVertically) {
                Box(
                    modifier = Modifier
                        .size(60.dp)
                        .background(Color(0xFF222634), RoundedCornerShape(8.dp)),
                    contentAlignment = Alignment.Center
                ) {
                    Text("🎬", fontSize = 24.sp)
                }
                Spacer(modifier = Modifier.width(14.dp))
                Column {
                    Text("Vlog Du Lịch Đà Lạt 4K", color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                    Text("Sửa đổi: Hôm nay • 15.4s • 1080p", color = Color(0xFF94A3B8), fontSize = 12.sp)
                }
            }
        }
    }
}

@Composable
fun QuickActionItem(title: String, onClick: () -> Unit) {
    Button(
        onClick = onClick,
        shape = RoundedCornerShape(10.dp),
        colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF1A1D27)),
        contentPadding = PaddingValues(8.dp)
    ) {
        Text(title, fontSize = 11.sp, color = Color(0xFF00E5FF))
    }
}

@Composable
fun TemplatesTabContent() {
    Column {
        Text("Mẫu Video Xu Hướng (CutSame)", fontSize = 18.sp, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Text("Chọn mẫu và thay thế ảnh/video chỉ với 1 chạm.", color = Color(0xFF94A3B8), fontSize = 13.sp)
    }
}

@Composable
fun AiLabTabContent(onOpenAiChatClick: () -> Unit) {
    Column {
        Text("AI Lab Hub — Sáng Tạo Không Giới Hạn", fontSize = 18.sp, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Spacer(modifier = Modifier.height(12.dp))
        Button(
            onClick = onOpenAiChatClick,
            modifier = Modifier.fillMaxWidth().height(60.dp),
            colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF7C4DFF)),
            shape = RoundedCornerShape(12.dp)
        ) {
            Text("💬 Trò chuyện với AI Video Copilot (MCP SSE)", color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        }
    }
}

@Composable
fun ToolboxTabContent() {
    Text("Hộp Công Cụ Biên Tập Đa Năng", fontSize = 18.sp, color = Color.White)
}

@Composable
fun InboxTabContent() {
    Text("Thông Báo & Hộp Thư Sáng Tạo", fontSize = 18.sp, color = Color.White)
}

@Composable
fun ProfileTabContent(onOpenPaywallClick: () -> Unit) {
    Column {
        Text("Hồ Sơ Cá Nhân & Cài Đặt", fontSize = 18.sp, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = onOpenPaywallClick, colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF00E5FF))) {
            Text("Quản lý gói Pro", color = Color.Black)
        }
    }
}
