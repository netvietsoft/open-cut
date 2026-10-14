// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_velocity.cpp
// Description: Full implementation of CapCut Velocity Algorithm & Bezier Speed Ramping
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "middle_bridge_velocity.h"
#include <cmath>
#include <algorithm>

namespace vesdk {
namespace pub {

// ===================================================================================
// 1. BEZIER SPEED CURVE MATHEMATICAL KERNEL
// Hạt nhân Toán học Nội suy Đường cong Tốc độ Bezier
// ===================================================================================

/**
 * @brief Evaluates 1D Cubic Bezier polynomial: B(t) = (1-t)^3*p0 + 3(1-t)^2*t*p1 + 3(1-t)*t^2*p2 + t^3*p3.
 * Tính giá trị đa thức Bezier bậc 3 tại tham số t thuộc [0.0, 1.0].
 */
double EvaluateCubicBezier(double t, double p0, double p1, double p2, double p3) {
    double u = 1.0 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    return (uuu * p0) + (3.0 * uu * t * p1) + (3.0 * u * tt * p2) + (ttt * p3);
}

/**
 * @brief Evaluates velocity multiplier at normalized timeline position [0.0, 1.0].
 * Đánh giá hệ số tốc độ tại vị trí thời gian chuẩn hóa [0.0, 1.0] qua mảng phân đoạn Bezier.
 */
double EvaluateVelocityAtNormalizedTime(const std::vector<Point>& curve, double norm_t) {
    if (curve.empty()) {
        return 1.0;
    }
    if (curve.size() == 1 || norm_t <= curve.front().x) {
        return curve.front().y;
    }
    if (norm_t >= curve.back().x) {
        return curve.back().y;
    }

    // Binary search finding curve segment [i, i+1] containing norm_t
    size_t i = 0;
    for (size_t k = 0; k < curve.size() - 1; k++) {
        if (norm_t >= curve[k].x && norm_t <= curve[k + 1].x) {
            i = k;
            break;
        }
    }

    const Point& pA = curve[i];
    const Point& pB = curve[i + 1];
    double seg_w = pB.x - pA.x;
    if (seg_w <= 1e-6) {
        return pA.y;
    }

    // Normalize local segment progress t in [0, 1]
    double local_t = (norm_t - pA.x) / seg_w;
    return EvaluateCubicBezier(local_t, pA.y, pA.control_point_right_y, pB.control_point_left_y, pB.y);
}

/**
 * @brief Maps timeline playhead time (us) to source media time (us) by integrating velocity.
 * Ánh xạ thời điểm phát trên timeline sang thời điểm trên video gốc bằng tích phân đường cong vận tốc:
 * tau(t) = Integral_0^t v(s) ds.
 */
int64_t MapTimelineTimeToSourceTime(const std::vector<Point>& curve, int64_t timeline_us, int64_t total_duration_us) {
    if (curve.empty() || total_duration_us <= 0) {
        return timeline_us;
    }

    double norm_t = (double)timeline_us / (double)total_duration_us;
    norm_t = std::max(0.0, std::min(1.0, norm_t));

    // Numerical integration using Simpson's rule over N steps
    const int N = 40;
    double dt = norm_t / N;
    double integral = 0.0;

    for (int k = 0; k < N; k++) {
        double t_mid = (k + 0.5) * dt;
        integral += EvaluateVelocityAtNormalizedTime(curve, t_mid) * dt;
    }

    int64_t source_us = (int64_t)(integral * total_duration_us);
    return source_us;
}


// ===================================================================================
// 2. CAPCUT AUTO-BEAT VELOCITY ALGORITHM EXECUTION
// Thực thi Thuật toán Tự động Khớp Tốc độ theo Nhịp Beat CapCut
// ===================================================================================

std::shared_ptr<RunVelocityAlgorithmRespStruct> ExecuteVelocityAlgorithm(
    const std::shared_ptr<RunVelocityAlgorithmReqStruct>& req) {

    auto resp = std::make_shared<RunVelocityAlgorithmRespStruct>();
    if (!req) {
        resp->progress = 0.0f;
        resp->error_info = "Null request";
        return resp;
    }

    int64_t duration = req->video_time_range.duration_us;
    if (duration <= 0) {
        duration = 5000000; // Default 5s in microseconds
    }

    std::vector<Point> generated_curve;

    if (!req->audio_beats.empty()) {
        // Mode 1: Auto Beat Ramping (Bullet Time on Beats)
        // Tại mỗi điểm beat, tạo hiệu ứng giật tốc: tăng tốc 3x trước beat và slow-mo 0.4x sau beat
        generated_curve.push_back(Point(0.0, 1.0));

        for (int64_t beat_us : req->audio_beats) {
            double norm_beat = (double)beat_us / (double)duration;
            if (norm_beat > 0.05 && norm_beat < 0.95) {
                // Peak speed right before beat drop
                double t_peak = std::max(0.0, norm_beat - 0.04);
                Point p_peak(t_peak, 3.2);
                p_peak.control_point_left_y = 2.0;
                p_peak.control_point_right_y = 3.5;
                generated_curve.push_back(p_peak);

                // Slow motion right on the beat
                Point p_slow(norm_beat, 0.4);
                p_slow.control_point_left_y = 0.4;
                p_slow.control_point_right_y = 0.6;
                generated_curve.push_back(p_slow);

                // Recovery back to normal speed
                double t_rec = std::min(1.0, norm_beat + 0.05);
                generated_curve.push_back(Point(t_rec, 1.0));
            }
        }
        generated_curve.push_back(Point(1.0, 1.0));
    } else {
        // Mode 2: Preset Bezier Ramping based on algo_mode
        switch (req->algo_mode) {
            case 1: // Montage Curve (Fast -> Slow -> Fast)
                generated_curve = {
                    Point(0.0, 2.5),
                    Point(0.35, 0.5),
                    Point(0.65, 0.5),
                    Point(1.0, 2.5)
                };
                break;
            case 2: // Hero Curve (Slow -> Explosive Peak -> Slow)
                generated_curve = {
                    Point(0.0, 0.6),
                    Point(0.45, 0.6),
                    Point(0.55, 4.0),
                    Point(1.0, 0.8)
                };
                break;
            case 3: // Bullet Time (Ultra smooth slowdown in the middle)
                generated_curve = {
                    Point(0.0, 2.0),
                    Point(0.3, 1.8),
                    Point(0.5, 0.2),
                    Point(0.7, 1.8),
                    Point(1.0, 2.0)
                };
                break;
            default: // Linear Constant Speed
                generated_curve = {
                    Point(0.0, req->video_speed),
                    Point(1.0, req->video_speed)
                };
                break;
        }
    }

    // Sort points chronologically
    std::sort(generated_curve.begin(), generated_curve.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    resp->curve_speed = generated_curve;
    resp->beats = req->audio_beats;
    resp->progress = 1.0f;
    resp->callback_type = 0; // Success
    return resp;
}

} // namespace pub
} // namespace vesdk


// ===================================================================================
// 3. JNI SWIG EXPORTED WRAPPERS (MATCHING AARCH64 CALL SITES)
// Các hàm JNI SWIG liên kết trực tiếp với tầng Java
// ===================================================================================

using namespace vesdk::pub;

JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_new_1RunVelocityAlgorithmReqStruct(JNIEnv *env, jclass cls) {
    (void)env; (void)cls;
    auto sp = std::make_shared<RunVelocityAlgorithmReqStruct>();
    auto* holder = new std::shared_ptr<RunVelocityAlgorithmReqStruct>(sp);
    return (jlong)holder;
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_delete_1RunVelocityAlgorithmReqStruct(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder) {
        delete holder;
    }
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1path_1set(JNIEnv *env, jclass cls, jlong jarg1, jstring jarg2) {
    (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder && jarg2) {
        const char* str = env->GetStringUTFChars(jarg2, nullptr);
        if (str) {
            (*holder)->video_path = str;
            env->ReleaseStringUTFChars(jarg2, str);
        }
    }
}

JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1path_1get(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        return env->NewStringUTF((*holder)->video_path.c_str());
    }
    return nullptr;
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1speed_1set(JNIEnv *env, jclass cls, jlong jarg1, jdouble jarg2) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        (*holder)->video_speed = jarg2; // offset 0xe8 (opcode 0x01f0538c)
    }
}

JNIEXPORT jdouble JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1speed_1get(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        return (*holder)->video_speed; // offset 0xe8 (opcode 0x01f053a4)
    }
    return 0.0;
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1mode_1set(JNIEnv *env, jclass cls, jlong jarg1, jint jarg2) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        (*holder)->algo_mode = jarg2; // offset 0xa0 (opcode 0x01e3b694)
    }
}

JNIEXPORT jint JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1mode_1get(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        return (*holder)->algo_mode; // offset 0xa0 (opcode 0x01e3b6a8)
    }
    return 0;
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1phase_1set(JNIEnv *env, jclass cls, jlong jarg1, jint jarg2) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        (*holder)->algo_phase = jarg2; // offset 0xa4 (opcode 0x01e3b6c0)
    }
}

JNIEXPORT jint JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1phase_1get(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmReqStruct>*)jarg1;
    if (holder && *holder) {
        return (*holder)->algo_phase; // offset 0xa4 (opcode 0x01e3b6d4)
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_new_1RunVelocityAlgorithmRespStruct(JNIEnv *env, jclass cls) {
    (void)env; (void)cls;
    auto sp = std::make_shared<RunVelocityAlgorithmRespStruct>();
    auto* holder = new std::shared_ptr<RunVelocityAlgorithmRespStruct>(sp);
    return (jlong)holder;
}

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_delete_1RunVelocityAlgorithmRespStruct(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmRespStruct>*)jarg1;
    if (holder) {
        delete holder;
    }
}

JNIEXPORT jfloat JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmRespStruct_1progress_1get(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<RunVelocityAlgorithmRespStruct>*)jarg1;
    if (holder && *holder) {
        return (*holder)->progress;
    }
    return 0.0f;
}
