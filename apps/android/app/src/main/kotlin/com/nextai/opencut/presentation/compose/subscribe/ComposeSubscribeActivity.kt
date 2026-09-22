/**
 * ComposeSubscribeActivity — Jetpack Compose VIP Paywall & Retention Machine
 * Implements Paywall screen with 2-Tier Detain Modal retention state machine.
 * Giao diện Paywall VIP viết bằng Jetpack Compose với thuật toán giữ chân người dùng 2 cấp.
 */

package com.nextai.opencut.presentation.compose.subscribe

import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.compose.BackHandler
import androidx.compose.foundation.background
import androidx.compose.foundation.border
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.window.Dialog
import com.nextai.opencut.billing.SubscriptionManager

class ComposeSubscribeActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            SubscribePaywallScreen(onClose = { finish() })
        }
    }
}

enum class DetainModalState {
    NONE,
    FIRST_DETAIN_20_PERCENT,   // Cấp 1: Giảm giá 20%
    SECOND_DETAIN_3DAY_TRIAL   // Cấp 2: Dùng thử 3 ngày miễn phí
}

@Composable
fun SubscribePaywallScreen(onClose: () -> Unit) {
    val context = LocalContext.current
    var selectedPlanIndex by remember { mutableStateOf(1) } // Default Annual (Popular)
    var detainState by remember { mutableStateOf(DetainModalState.NONE) }
    var exitAttemptCount by remember { mutableStateOf(0) }

    // Intercept Back Press for Detain Machine / Bắt sự kiện quay lại để kích hoạt máy giữ chân
    BackHandler {
        exitAttemptCount++
        if (exitAttemptCount == 1) {
            detainState = DetainModalState.FIRST_DETAIN_20_PERCENT
        } else if (exitAttemptCount == 2) {
            detainState = DetainModalState.SECOND_DETAIN_3DAY_TRIAL
        } else {
            onClose()
        }
    }

    Box(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFF0D0E12))
            .padding(20.dp)
    ) {
        Column(modifier = Modifier.fillMaxSize()) {
            // Close Button / Nút Đóng
            Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.End) {
                IconButton(onClick = {
                    exitAttemptCount++
                    if (exitAttemptCount == 1) {
                        detainState = DetainModalState.FIRST_DETAIN_20_PERCENT
                    } else if (exitAttemptCount == 2) {
                        detainState = DetainModalState.SECOND_DETAIN_3DAY_TRIAL
                    } else {
                        onClose()
                    }
                }) {
                    Text("✕", color = Color.White, fontSize = 20.sp)
                }
            }

            Spacer(modifier = Modifier.height(10.dp))

            // VIP Crown & Title / Tiêu đề VIP
            Text("👑 NEXTAI OPENCUT PRO", fontSize = 24.sp, color = Color(0xFFFFB300), fontWeight = androidx.compose.ui.text.font.FontWeight.ExtraBold)
            Text("Mở Khóa Toàn Diện Sức Mạnh AI & Xuất 4K Siêu Nét", fontSize = 14.sp, color = Color(0xFF94A3B8))

            Spacer(modifier = Modifier.height(24.dp))

            // Benefit List / Danh sách quyền lợi VIP
            BenefitRow("✨ Không giới hạn tạo kịch bản & video bằng AI Copilot")
            BenefitRow("🎬 Xuất video 4K 60FPS không nén, không watermark")
            BenefitRow("☁️ 100GB Cloud Space sao lưu dự án bản nháp tự động")
            BenefitRow("🎨 1500+ bộ lọc màu điện ảnh 3D & hiệu ứng VIP độc quyền")

            Spacer(modifier = Modifier.height(30.dp))

            // Subscription Plan Cards / Các thẻ gói đăng ký
            PlanCard(
                title = "Gói Năm (Tiết kiệm 60%)",
                price = "899.000 ₫/năm (Chỉ 74k/tháng)",
                badge = "PHỔ BIẾN NHẤT",
                isSelected = selectedPlanIndex == 1,
                onClick = { selectedPlanIndex = 1 }
            )

            Spacer(modifier = Modifier.height(12.dp))

            PlanCard(
                title = "Gói Tháng",
                price = "189.000 ₫/tháng",
                badge = null,
                isSelected = selectedPlanIndex == 0,
                onClick = { selectedPlanIndex = 0 }
            )

            Spacer(modifier = Modifier.weight(1f))

            // Upgrade Button / Nút Đăng Ký Google Play Billing
            Button(
                onClick = {
                    val isAnnual = (selectedPlanIndex == 1)
                    val tier = if (isAnnual) SubscriptionManager.TIER_VIP_ANNUAL else SubscriptionManager.TIER_VIP_MONTHLY
                    val duration = if (isAnnual) 365L * 24 * 60 * 60 * 1000L else 30L * 24 * 60 * 60 * 1000L
                    SubscriptionManager.setVipActive(context, true, tier, duration)
                    Toast.makeText(context, "🎉 Đã kích hoạt thành công: ${SubscriptionManager.getTierDisplayName(context)}!", Toast.LENGTH_LONG).show()
                    onClose()
                },
                modifier = Modifier.fillMaxWidth().height(56.dp),
                shape = RoundedCornerShape(16.dp),
                colors = ButtonDefaults.buttonColors(containerColor = Color(0xFFFFB300))
            ) {
                Text("NÂNG CẤP NGAY (GOOGLE PLAY)", color = Color.Black, fontSize = 15.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
            }
        }

        // 1st Detain Modal (Giảm 20%)
        if (detainState == DetainModalState.FIRST_DETAIN_20_PERCENT) {
            Dialog(onDismissRequest = { detainState = DetainModalState.NONE }) {
                Card(
                    modifier = Modifier.fillMaxWidth(),
                    shape = RoundedCornerShape(20.dp),
                    colors = CardDefaults.cardColors(containerColor = Color(0xFF1A1D27))
                ) {
                    Column(modifier = Modifier.padding(24.dp), horizontalAlignment = Alignment.CenterHorizontally) {
                        Text("🎁 KHOAN ĐÃ!", fontSize = 22.sp, color = Color(0xFFFFB300), fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                        Spacer(modifier = Modifier.height(8.dp))
                        Text("Tặng bạn Voucher GIẢM GIÁ 20% cho gói Năm!", color = Color.White, textAlign = androidx.compose.ui.text.style.TextAlign.Center)
                        Text("Giá chỉ còn: 719.000 ₫/năm", color = Color(0xFF00E5FF), fontWeight = androidx.compose.ui.text.font.FontWeight.Bold, fontSize = 18.sp)
                        Spacer(modifier = Modifier.height(20.dp))
                        Button(
                            onClick = {
                                detainState = DetainModalState.NONE
                                SubscriptionManager.setVipActive(context, true, SubscriptionManager.TIER_VIP_DISCOUNT_20, 365L * 24 * 60 * 60 * 1000L)
                                Toast.makeText(context, "🎉 Đã áp dụng Voucher 20% & kích hoạt VIP PRO!", Toast.LENGTH_LONG).show()
                                onClose()
                            },
                            modifier = Modifier.fillMaxWidth(),
                            colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF00E5FF))
                        ) {
                            Text("NHẬN ƯU ĐÃI 20% NGAY", color = Color.Black, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                        }
                        TextButton(onClick = {
                            detainState = DetainModalState.SECOND_DETAIN_3DAY_TRIAL
                        }) {
                            Text("Bỏ qua ưu đãi", color = Color(0xFF94A3B8), fontSize = 12.sp)
                        }
                    }
                }
            }
        }

        // 2nd Detain Modal (3-Day Free Trial)
        if (detainState == DetainModalState.SECOND_DETAIN_3DAY_TRIAL) {
            Dialog(onDismissRequest = { detainState = DetainModalState.NONE }) {
                Card(
                    modifier = Modifier.fillMaxWidth(),
                    shape = RoundedCornerShape(20.dp),
                    colors = CardDefaults.cardColors(containerColor = Color(0xFF1A1D27))
                ) {
                    Column(modifier = Modifier.padding(24.dp), horizontalAlignment = Alignment.CenterHorizontally) {
                        Text("🔥 CƠ HỘI CUỐI CÙNG", fontSize = 20.sp, color = Color(0xFFEF4444), fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                        Spacer(modifier = Modifier.height(8.dp))
                        Text("Trải nghiệm toàn bộ tính năng VIP MIỄN PHÍ trong 3 ngày!", color = Color.White, textAlign = androidx.compose.ui.text.style.TextAlign.Center)
                        Spacer(modifier = Modifier.height(20.dp))
                        Button(
                            onClick = {
                                detainState = DetainModalState.NONE
                                SubscriptionManager.setVipActive(context, true, SubscriptionManager.TIER_VIP_TRIAL_3DAY, 3L * 24 * 60 * 60 * 1000L)
                                Toast.makeText(context, "🎉 Đã kích hoạt 3 ngày dùng thử VIP PRO miễn phí!", Toast.LENGTH_LONG).show()
                                onClose()
                            },
                            modifier = Modifier.fillMaxWidth(),
                            colors = ButtonDefaults.buttonColors(containerColor = Color(0xFF10B981))
                        ) {
                            Text("DÙNG THỬ 3 NGÀY MIỄN PHÍ", color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                        }
                        TextButton(onClick = {
                            detainState = DetainModalState.NONE
                            onClose()
                        }) {
                            Text("Đóng và thoát", color = Color(0xFF94A3B8), fontSize = 12.sp)
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun BenefitRow(text: String) {
    Row(modifier = Modifier.padding(vertical = 4.dp)) {
        Text(text, color = Color.White, fontSize = 13.sp)
    }
}

@Composable
fun PlanCard(title: String, price: String, badge: String?, isSelected: Boolean, onClick: () -> Unit) {
    Box(
        modifier = Modifier
            .fillMaxWidth()
            .clickable(onClick = onClick)
            .background(Color(0xFF1A1D27), RoundedCornerShape(14.dp))
            .border(
                width = if (isSelected) 2.dp else 1.dp,
                color = if (isSelected) Color(0xFFFFB300) else Color(0xFF222634),
                shape = RoundedCornerShape(14.dp)
            )
            .padding(16.dp)
    ) {
        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceBetween, verticalAlignment = Alignment.CenterVertically) {
            Column {
                if (badge != null) {
                    Text(badge, color = Color(0xFFFFB300), fontSize = 10.sp, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold)
                }
                Text(title, color = Color.White, fontWeight = androidx.compose.ui.text.font.FontWeight.Bold, fontSize = 15.sp)
                Text(price, color = Color(0xFF00E5FF), fontSize = 13.sp)
            }
            RadioButton(
                selected = isSelected,
                onClick = onClick,
                colors = RadioButtonDefaults.colors(selectedColor = Color(0xFFFFB300))
            )
        }
    }
}
