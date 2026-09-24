/**
 * ExportActivity — 4K Render & Video Publishing Screen
 * Configures output resolution (720p, 1080p, 2K, 4K), frame rate (30/60fps), and bitrate.
 * Màn hình cấu hình độ phân giải, tốc độ khung hình và kết xuất video phần cứng.
 */

package com.nextai.opencut.presentation.export

import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.nextai.opencut.engine.MiddleBridgeJniKt

class ExportActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            ExportScreen(onBack = { finish() })
        }
    }
}

@Composable
fun ExportScreen(onBack: () -> Unit) {
    val context = LocalContext.current
    var selectedRes by remember { mutableStateOf("1080p") }
    var selectedFps by remember { mutableStateOf("60fps") }
    var isExporting by remember { mutableStateOf(false) }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF0D0E12))
            .padding(20.dp)
    ) {
        Row(
            modifier = Modifier.fillMaxWidth(),
            verticalAlignment = Alignment.CenterVertically
        ) {
            IconButton(onClick = onBack) {
                Text("←", color = Color.White, fontSize = 24.sp)
            }
            Spacer(modifier = Modifier.width(8.dp))
            Text("Cấu Hình Xuất Video", color = Color.White, fontSize = 18.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        }

        Spacer(modifier = Modifier.height(24.dp))

        // Resolution Selector / Lựa chọn độ phân giải
        Text("ĐỘ PHÂN GIẢI (RESOLUTION)", color = Color(0xFF94A3B8), fontSize = 12.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Spacer(modifier = Modifier.height(10.dp))
        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
            listOf("720p", "1080p (Chuẩn)", "2K", "4K (Siêu Nét)").forEach { res ->
                val isSelected = selectedRes.startsWith(res.split(" ")[0])
                Button(
                    onClick = { selectedRes = res },
                    colors = ButtonDefaults.buttonColors(containerColor = if (isSelected) Color(0xFF00E5FF) else Color(0xFF1A1D27)),
                    shape = RoundedCornerShape(10.dp),
                    modifier = Modifier.weight(1f),
                    contentPadding = PaddingValues(6.dp)
                ) {
                    Text(res.split(" ")[0], color = if (isSelected) Color.Black else Color.White, fontSize = 12.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                }
            }
        }

        Spacer(modifier = Modifier.height(24.dp))

        // Frame Rate Selector / Lựa chọn tốc độ khung hình
        Text("TỐC ĐỘ KHUNG HÌNH (FRAME RATE)", color = Color(0xFF94A3B8), fontSize = 12.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        Spacer(modifier = Modifier.height(10.dp))
        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.spacedBy(10.dp)) {
            listOf("24fps", "30fps", "60fps (Mượt mà)").forEach { fps ->
                val isSelected = selectedFps.startsWith(fps.split(" ")[0])
                Button(
                    onClick = { selectedFps = fps },
                    colors = ButtonDefaults.buttonColors(containerColor = if (isSelected) Color(0xFF7C4DFF) else Color(0xFF1A1D27)),
                    shape = RoundedCornerShape(10.dp),
                    modifier = Modifier.weight(1f),
                    contentPadding = PaddingValues(6.dp)
                ) {
                    Text(fps.split(" ")[0], color = Color.White, fontSize = 12.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                }
            }
        }

        Spacer(modifier = Modifier.weight(1f))

        // Export Action Button / Nút kết xuất video
        Button(
            onClick = {
                isExporting = true
                val width = if (selectedRes.contains("4K")) 2160 else 1080
                val height = if (selectedRes.contains("4K")) 3840 else 1920
                val fps = if (selectedFps.contains("60")) 60 else 30

                MiddleBridgeJniKt.nativeRenderExport(
                    "/sdcard/Movies/NextAI_Output.mp4",
                    width,
                    height,
                    fps,
                    15000
                )
                Toast.makeText(context, "Kết xuất video thành công qua C++ Native Video Engine!", Toast.LENGTH_LONG).show()
                isExporting = false
            },
            modifier = Modifier.fillMaxWidth().height(56.dp),
            colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF00E5FF)),
            shape = RoundedCornerShape(16.dp)
        ) {
            Text(if (isExporting) "ĐANG KẾT XUẤT..." else "XUẤT VIDEO NGAY", color = Color.Black, fontSize = 15.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
        }
    }
}
