/**
 * TemplateFeedActivity — Trending Video Templates & CutSame 1-Tap Screen
 * Displays trending templates, slot replacement counts, and instant preview.
 * Màn hình khám phá video mẫu thịnh hành và thay thế ảnh/video một chạm.
 */

package com.nextai.opencut.presentation.templates

import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

class TemplateFeedActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            TemplateFeedScreen(onBack = { finish() })
        }
    }
}

@Composable
fun TemplateFeedScreen(onBack: () -> Unit) {
    val context = LocalContext.current

    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF0D0E12))
            .padding(16.dp)
    ) {
        Row(
            modifier = Modifier.fillMaxWidth(),
            verticalAlignment = Alignment.CenterVertically
        ) {
            IconButton(onClick = onBack) {
                Text("←", color = Color.White, fontSize = 24.sp)
            }
            Spacer(modifier = Modifier.width(8.dp))
            Text("Mẫu Video Xu Hướng (CutSame)", color = Color.White, fontSize = 18.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        }

        Spacer(modifier = Modifier.height(16.dp))

        LazyColumn(verticalArrangement = Arrangement.spacedBy(16.dp)) {
            item {
                TemplateCard(
                    title = "Cinematic Travel Vlog 4K",
                    slots = 5,
                    usage = "142.5k",
                    isPro = false,
                    onUseClick = {
                        Toast.makeText(context, "Mở trình chọn 5 ảnh/video thay thế CutSame!", Toast.LENGTH_SHORT).show()
                    }
                )
            }
            item {
                TemplateCard(
                    title = "Neon Cyberpunk AI Avatar (VIP)",
                    slots = 3,
                    usage = "56.2k",
                    isPro = true,
                    onUseClick = {
                        Toast.makeText(context, "Mở CutSame Pro: Yêu cầu tài khoản VIP", Toast.LENGTH_SHORT).show()
                    }
                )
            }
        }
    }
}

@Composable
fun TemplateCard(title: String, slots: Int, usage: String, isPro: Boolean, onUseClick: () -> Unit) {
    Card(
        modifier = Modifier.fillMaxWidth(),
        shape = RoundedCornerShape(16.dp),
        colors = CardDefaults.cardColors(containerColor = Color(0xFF1A1D27))
    ) {
        Column(modifier = Modifier.padding(16.dp)) {
            Box(
                modifier = Modifier
                    .fillMaxWidth()
                    .height(180.dp)
                    .background(Color(0xFF222634), RoundedCornerShape(12.dp)),
                contentAlignment = Alignment.Center
            ) {
                Text("🎬 Preview Video 9:16", color = Color(0xFF94A3B8), fontSize = 14.sp)
            }

            Spacer(modifier = Modifier.height(12.dp))

            Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween, verticalAlignment = Alignment.CenterVertically) {
                Column {
                    Text(title, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold, fontSize = 15.sp)
                    Text("$slots clips • $usage lượt dùng", color = Color(0xFF94A3B8), fontSize = 12.sp)
                }

                Button(
                    onClick = onUseClick,
                    colors = ButtonDefaults.buttonColors(containerColor = if (isPro) Color(0xFFFFB300) else Color(0xFF00E5FF)),
                    shape = RoundedCornerShape(10.dp)
                ) {
                    Text(if (isPro) "👑 DÙNG MẪU PRO" else "SỬ DỤNG MẪU", color = Color.Black, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold, fontSize = 12.sp)
                }
            }
        }
    }
}
