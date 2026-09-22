# Proguard Rules for NextAI OpenCut / Quy tắc Proguard cho NextAI OpenCut
# Dual-language comments: Tiếng Việt (VN) / English (EN)

# Keep JNI Native methods and bridge classes / Giữ lại các phương thức Native JNI và lớp cầu nối
-keepclasseswithmembernames class * {
    native <methods>;
}

-keep class com.nextai.opencut.engine.** { *; }
-keep class com.nextai.opencut.presentation.model.** { *; }

# Keep AndroidX & Jetpack Compose runtime / Giữ lại thư viện giao diện AndroidX & Jetpack Compose
-keep class androidx.compose.** { *; }
-keep class androidx.lifecycle.** { *; }

# Keep Kotlinx serialization & Coroutines
-keepclassmembers class * {
    kotlinx.serialization.KSerializer serializer(...);
}

# Keep Google Play Billing / Giữ lại thư viện thanh toán Google Play
-keep class com.android.billingclient.api.** { *; }
