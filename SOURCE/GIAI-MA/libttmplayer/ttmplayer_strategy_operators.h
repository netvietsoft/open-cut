/**
 * @file ttmplayer_strategy_operators.h
 * @brief Cleanroom C++17 Header for AVStrategyUtils, AVLoadControlOperator, AVDropFrameOperator & MDL Callback
 *        Header C++17 Tái cấu trúc Sạch cho AVStrategyUtils, AVLoadControlOperator, AVDropFrameOperator & MDL Callback
 *
 * Binary Ground Truth / Tham chiếu Nhị phân Gốc (libttmplayer.so):
 * - mdlInfoCallback                                                  @ 0x0c4af8 (208 bytes)
 * - com::ss::ttm::player::AVStrategyUtils::registerStrategyCenter    @ 0x1660b0 ( 28 bytes)
 * - com::ss::ttm::player::AVStrategyUtils::convertTTCodecIDToFF      @ 0x1660cc -> 0x261f20 (48 bytes)
 * - com::ss::ttm::player::AVStrategyUtils::setPlayerGlobalConfigIntValue @ 0x1660d0 (84 bytes)
 * - com::ss::ttm::player::AVStrategyUtils::getPlayerGlobalConfigIntValue @ 0x166124 (84 bytes)
 * - com::ss::ttm::player::AVDropFrameOperator::ctor()                @ 0x16cde8 ( 24 bytes)
 * - com::ss::ttm::player::AVLoadControlOperator::ctor()              @ 0x16ce04 ( 36 bytes)
 * - TTPlayerStrategyCenter::_init                                    @ 0x1ee348 ( 20 bytes)
 * - TTPlayerStrategyCenter::_notifyEvent                             @ 0x1ee35c ( 36 bytes)
 * - TTPlayerStrategyCenter::_setDataCenterHandle                     @ 0x1ee380 ( 36 bytes)
 * - TTPlayerStrategyCenter::_packStrategyLogInfo                     @ 0x1ee3a4 (212 bytes)
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_STRATEGY_OPERATORS_H_
#define NEXTAI_OPENCUT_TTMPLAYER_STRATEGY_OPERATORS_H_

#include "ttmplayer_types.h"

namespace com {
namespace ss {
namespace ttm {
namespace player {

class AVStrategyUtils {
public:
    /**
     * @brief Registers a singleton `AVStrategyCenterProtocol*` using acquire/release atomics (`ldar`/`stlr` @ 0x1660b8..0x1660c4).
     *        Đăng ký singleton `AVStrategyCenterProtocol*` bằng thao tác nguyên tử acquire/release (`ldar`/`stlr` @ 0x1660b8..0x1660c4).
     */
    static void registerStrategyCenter(AVStrategyCenterProtocol* center) noexcept;
    static AVStrategyCenterProtocol* getRegisteredStrategyCenter() noexcept;
    static void resetStrategyCenterForTesting() noexcept;

    /**
     * @brief Maps TTPlayer internal codec ID [0..49] to FFmpeg AVCodecID (`0x1660cc` -> `0x261f20`).
     *        Ánh xạ mã codec nội bộ TTPlayer [0..49] sang FFmpeg AVCodecID (`0x1660cc` -> `0x261f20`).
     *
     * Disassembly @ 0x261f20:
     *   cmp  w0, #0x31
     *   b.hi #0x261f3c
     *   mov  x8, #-0x800001
     *   movk x8, #0xf1ff, lsl #32
     *   movk x8, #3, lsl #48        ; x8 = 0x0003f1ffff7fffffULL
     *   lsr  x8, x8, x0
     *   tbnz w8, #0, #0x261f44
     *   mov  w0, w1
     *   ret
     *   adrp x8, #0x2cf000
     *   add  x8, x8, #0x40          ; .rodata table @ 0x2cf040
     *   ldr  w0, [x8, w0, sxtw #2]
     *   ret
     */
    static int32_t convertTTCodecIDToFF(int32_t tt_codec_id, int32_t default_ff_codec_id) noexcept;

    /**
     * @brief Sets global player config integer (`0x1660d0`): maps `0x519 -> 0x3a` (58) and `0x518 -> 0x3d` (61).
     *        Thiết lập số nguyên cấu hình toàn cục (`0x1660d0`): ánh xạ `0x519 -> 0x3a` (58) và `0x518 -> 0x3d` (61).
     */
    static int32_t setPlayerGlobalConfigIntValue(int32_t key, int32_t value) noexcept;

    /**
     * @brief Gets global player config integer (`0x166124`): maps `0x519 -> 0x3a` (58) and `0x518 -> 0x3d` (61).
     *        Truy vấn số nguyên cấu hình toàn cục (`0x166124`): ánh xạ `0x519 -> 0x3a` (58) và `0x518 -> 0x3d` (61).
     */
    static int32_t getPlayerGlobalConfigIntValue(int32_t key, int32_t default_value) noexcept;

    static void setDirectGlobalConfigSlot(int32_t internal_slot, int32_t value) noexcept;
    static int32_t getDirectGlobalConfigSlot(int32_t internal_slot, int32_t default_value) noexcept;
};

}  // namespace player
}  // namespace ttm
}  // namespace ss
}  // namespace com

extern "C" {

// Exported C symbol at 0x0c4af8 (208 bytes)
typedef int64_t (*TTMPlayerMdlFallbackCallback)(void* opaque,
                                                void* task_ctx,
                                                int32_t event_type,
                                                int64_t arg);

void ttmplayer_set_mdl_callback_state(int32_t enable_event0_forward,
                                      void* fallback_opaque,
                                      TTMPlayerMdlFallbackCallback fallback_cb) noexcept;

int64_t mdlInfoCallback(void* task_ctx, int32_t what, int64_t arg);

// TTPlayerStrategyCenter JNI methods (.data.rel.ro @ 0x358f60 .. 0x358fb8)
void ttmplayer_strategy_center_init(void* env, void* clazz);
void ttmplayer_strategy_center_notify_event(void* env, void* clazz, int32_t event_code);
void ttmplayer_strategy_center_set_data_center_handle(void* env, void* clazz, int64_t handle);
const char* ttmplayer_strategy_center_pack_log_info(int64_t handle, char* out_buf, size_t out_cap);

}  // extern "C"

#endif  // NEXTAI_OPENCUT_TTMPLAYER_STRATEGY_OPERATORS_H_
