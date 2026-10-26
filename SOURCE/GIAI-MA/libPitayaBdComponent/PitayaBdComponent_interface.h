/**
 * @file PitayaBdComponent_interface.h
 * @brief Master C++17 Orchestration Interface & 7-Stage Closed-Loop Self-Test for libPitayaBdComponent.so (Target 46).
 *        Giao diện điều phối C++17 tổng thể & Tự kiểm thử khép kín 7 giai đoạn cho libPitayaBdComponent.so (Mục tiêu 46).
 */

#ifndef NEXTAI_OPENCUT_PITAYABDCOMPONENT_INTERFACE_H_
#define NEXTAI_OPENCUT_PITAYABDCOMPONENT_INTERFACE_H_

#include "pitayabdcomponent_types.h"
#include "pitayabdcomponent_npth_tombstone.h"
#include "pitayabdcomponent_regex_stream.h"
#include "pitayabdcomponent_alog_jni.h"

#include <string>

namespace NextAI {
namespace OpenCut {
namespace PitayaBdComponent {

/**
 * @class PitayaBdComponentEngine
 * @brief High-level facade coordinating PitayaNpthUtil crash tombstone generation, RegexStreamEngine,
 *        and ALogDynamicBridge JNI entry points for OpenCut AI runtime diagnostics.
 *        Lớp mặt tiền cấp cao điều phối sinh tombstone sự cố PitayaNpthUtil, RegexStreamEngine
 *        và các điểm vào JNI ALogDynamicBridge phục vụ chẩn đoán thời gian chạy AI OpenCut.
 */
class PitayaBdComponentEngine {
public:
    PitayaBdComponentEngine() = default;
    ~PitayaBdComponentEngine() = default;

    /**
     * Runs the 7-stage closed-loop self-test verifying all opcodes, regex extractors,
     * "pty-ord-t" priority ordering, 4th-token .so path extraction, and dlopen/npth_dlopen fallback.
     * Chạy bộ tự kiểm thử khép kín 7 giai đoạn xác minh toàn bộ opcode, bộ trích xuất regex,
     * thứ tự ưu tiên "pty-ord-t", trích xuất đường dẫn .so token thứ 4 và cơ chế dự phòng dlopen/npth_dlopen.
     */
    static bool RunSelfTest(std::string* out_report = nullptr);
};

}  // namespace PitayaBdComponent
}  // namespace OpenCut
}  // namespace NextAI

#endif  // NEXTAI_OPENCUT_PITAYABDCOMPONENT_INTERFACE_H_
