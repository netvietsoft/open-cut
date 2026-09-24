/**
 * MiddleBridge JNI Connector / Lớp Cầu Nối JNI Tới C++ Native
 * Loads libmiddle_bridge.so and exposes native video timeline methods.
 * Nạp thư viện C++ và cung cấp các hàm điều khiển dòng thời gian cho Kotlin.
 */

package com.nextai.opencut.engine

object MiddleBridgeJniKt {
    init {
        try {
            System.loadLibrary("middle_bridge")
        } catch (e: UnsatisfiedLinkError) {
            println("[NextAI Engine] Native library loaded in mock/unit test mode: ${e.message}")
        }
    }

    /**
     * Get C++ Video Engine Version / Lấy phiên bản nhân C++
     */
    external fun getEngineVersion(): String

    /**
     * Split video segment at timestamp / Cắt tách đoạn video tại vị trí miligiây
     */
    external fun nativeSplitSegment(trackId: Int, splitTimeMs: Long): Boolean

    /**
     * Apply transition effect / Áp dụng hiệu ứng chuyển cảnh
     */
    external fun nativeApplyTransition(
        trackId: Int,
        positionMs: Long,
        transitionName: String,
        durationMs: Long
    ): Boolean

    /**
     * Render & Export video / Kết xuất và xuất file video
     */
    external fun nativeRenderExport(
        outputPath: String,
        width: Int,
        height: Int,
        fps: Int,
        bitrateKbps: Int
    ): Boolean
}
