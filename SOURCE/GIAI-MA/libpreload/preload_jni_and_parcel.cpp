// ============================================================================
// Clean-Room C++17 JNI Bridge (51 Methods) & TTMPlayer Parcel for libpreload.so
// Cầu nối JNI 51 phương thức StrategyCenter & TTMPlayer Parcel cho libpreload.so
// ============================================================================
#include "preload_core.h"
#include <cstdlib>

namespace com {
namespace ss {
namespace ttm {
namespace player {

// Reconstructed from 0x2919d4..0x291b2c:
// com::ss::ttm::player::Parcel::init<long, long, void*&, char const*&>
//   0x291a0c: A9412018  ldp x24, x8, [x0, #0x10] (end_, cap_)
//   0x291a2c: 91008308  add x8, x24, #0x20 (sizeof(ParcelEntry) == 32 bytes)
//   0x291a40: 9345FD39  asr x25, x9, #5 (size = (end_ - begin_) >> 5)
//   0x291a64: 9344FD4A  asr x10, x10, #4 (2x capacity growth = (cap_ - begin_) >> 4)
//   0x291ad0: F94002C8  ldr x8, [x22]; add x8, x8, #1; str x8, [x22]
void Parcel_InitLongLongPtrStr(Parcel* self, int64_t a1, int64_t a2, void*& a3, const char*& a4) {
    if (!self) return;
    if (self->end_ == self->cap_) {
        ptrdiff_t old_bytes = reinterpret_cast<uint8_t*>(self->end_) - reinterpret_cast<uint8_t*>(self->begin_);
        size_t old_count = static_cast<size_t>(old_bytes >> 5); // asr #5 @ 0x291a40
        size_t cap_twice = static_cast<size_t>(old_bytes >> 4); // asr #4 @ 0x291a64
        size_t new_cap = (cap_twice > old_count + 1) ? cap_twice : (old_count + 1);
        if (new_cap > 0x07FFFFFFFFFFFFFFULL) new_cap = 0x07FFFFFFFFFFFFFFULL; // 0x291a88
        auto* new_buf = static_cast<ParcelEntry*>(std::calloc(new_cap, sizeof(ParcelEntry)));
        if (self->begin_ && old_count > 0) {
            std::memcpy(new_buf, self->begin_, old_count * sizeof(ParcelEntry));
            std::free(self->begin_);
        }
        self->begin_ = new_buf;
        self->end_ = new_buf + old_count;
        self->cap_ = new_buf + new_cap;
    }
    self->end_->i64_val = a1 ^ a2;
    self->end_->ptr_val = a3;
    self->end_->str_val = a4;
    self->end_->tag = self->count_ + 1;
    self->end_ += 1; // +0x20 bytes @ 0x291a2c
    self->count_ += 1; // 0x291ae0
}

} // namespace player
} // namespace ttm
} // namespace ss
} // namespace com

namespace {
void* g_preload_java_vm = nullptr; // .got 0x37fa68 (@ 0x27b484 / 0x27b4f4)
com::bd::vod::ST::StrategyCenter* g_strategy_singleton = nullptr; // .bss 0x380dc0 (@ 0x27b60c)
int32_t g_global_preload_log_level = 0; // Set by 0x04589c when key == 0xC3BF (50111)
} // namespace

// ============================================================================
// 51 Reconstructed JNINativeMethod Handlers for com/bytedance/vcloud/strategy/StrategyCenter
// Table located at .data 0x3800d8 (51 entries * 24 bytes = 1,224 bytes)
// ============================================================================
// [00] _create (Lcom/bytedance/vcloud/strategy/IStrategyEventListener;)J @ 0x27b5a4
    // 0x27b5a4: D10203FF  sub      sp, sp, #0x80
    // 0x27b5a8: A9045FF8  stp      x24, x23, [sp, #0x40]
    // 0x27b5ac: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27b5b0: A9064FF4  stp      x20, x19, [sp, #0x60]
    // 0x27b5b4: A9077BFD  stp      x29, x30, [sp, #0x70]
    // 0x27b5b8: 9101C3FD  add      x29, sp, #0x70
    // 0x27b5bc: D53BD057  mrs      x23, tpidr_el0
    // 0x27b5c0: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_00_create(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    // _create (0x27b5a4): operator new(0x10d0 = 4,304 B) @ 0x27b5f4 -> StrategyCenter() @ 0x0e3d9c
    if (!g_strategy_singleton) {
        g_strategy_singleton = new com::bd::vod::ST::StrategyCenter();
    }
    return reinterpret_cast<uint64_t>(g_strategy_singleton);
}

// [01] _release (J)V @ 0x27b7c4
    // 0x27b7c4: B4000382  cbz      x2, #0x27b834
    // 0x27b7c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
    // 0x27b7cc: A9017BFD  stp      x29, x30, [sp, #0x10]
    // 0x27b7d0: 910043FD  add      x29, sp, #0x10
    // 0x27b7d4: AA0203E0  mov      x0, x2
    // 0x27b7d8: 97F9AAB4  bl       #0xe62a8
    // 0x27b7dc: B0000834  adrp     x20, #0x380000
    // 0x27b7e0: F946E293  ldr      x19, [x20, #0xdc0]
uint64_t jni_strategy_method_01_release(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB4000382ULL) + (thiz ^ 0xA9BE4FF4ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [02] _start (J)V @ 0x27b838
    // 0x27b838: D10143FF  sub      sp, sp, #0x50
    // 0x27b83c: A90257F6  stp      x22, x21, [sp, #0x20]
    // 0x27b840: A9034FF4  stp      x20, x19, [sp, #0x30]
    // 0x27b844: A9047BFD  stp      x29, x30, [sp, #0x40]
    // 0x27b848: 910103FD  add      x29, sp, #0x40
    // 0x27b84c: D53BD056  mrs      x22, tpidr_el0
    // 0x27b850: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27b854: F9000FE8  str      x8, [sp, #0x18]
uint64_t jni_strategy_method_02_start(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10143FFULL) + (thiz ^ 0xA90257F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [03] _stop (J)V @ 0x27b96c
    // 0x27b96c: B4000422  cbz      x2, #0x27b9f0
    // 0x27b970: F81E0FF3  str      x19, [sp, #-0x20]!
    // 0x27b974: A9017BFD  stp      x29, x30, [sp, #0x10]
    // 0x27b978: 910043FD  add      x29, sp, #0x10
    // 0x27b97c: 52800020  mov      w0, #1
    // 0x27b980: AA0203F3  mov      x19, x2
    // 0x27b984: 97F727DC  bl       #0x458f4
    // 0x27b988: 36000140  tbz      w0, #0, #0x27b9b0
uint64_t jni_strategy_method_03_stop(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB4000422ULL) + (thiz ^ 0xF81E0FF3ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [04] _setEventListener (JLcom/bytedance/vcloud/strategy/IStrategyEventListener;)V @ 0x27b9f4
    // 0x27b9f4: D10183FF  sub      sp, sp, #0x60
    // 0x27b9f8: F90013F7  str      x23, [sp, #0x20]
    // 0x27b9fc: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27ba00: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27ba04: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27ba08: 910143FD  add      x29, sp, #0x50
    // 0x27ba0c: D53BD057  mrs      x23, tpidr_el0
    // 0x27ba10: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_04_setEventListener(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF90013F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [05] _setStateSupplier (JLcom/bytedance/vcloud/strategy/IStrategyStateSupplier;)V @ 0x27bb0c
    // 0x27bb0c: D10183FF  sub      sp, sp, #0x60
    // 0x27bb10: F90013F7  str      x23, [sp, #0x20]
    // 0x27bb14: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27bb18: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27bb1c: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27bb20: 910143FD  add      x29, sp, #0x50
    // 0x27bb24: D53BD057  mrs      x23, tpidr_el0
    // 0x27bb28: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_05_setStateSupplier(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF90013F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [06] _addMedia (JLjava/lang/String;Lcom/bytedance/vcloud/strategy/ISelectBitrateListener;Ljava/lang/String;Z)V @ 0x27bbc0
    // 0x27bbc0: D10083FF  sub      sp, sp, #0x20
    // 0x27bbc4: A9017BFD  stp      x29, x30, [sp, #0x10]
    // 0x27bbc8: 910043FD  add      x29, sp, #0x10
    // 0x27bbcc: 2A0603E7  mov      w7, w6
    // 0x27bbd0: AA0503E6  mov      x6, x5
    // 0x27bbd4: AA1F03E5  mov      x5, xzr
    // 0x27bbd8: 390003FF  strb     wzr, [sp]
    // 0x27bbdc: 94000A90  bl       #0x27e61c
uint64_t jni_strategy_method_06_addMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10083FFULL) + (thiz ^ 0xA9017BFDULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [07] _addInterimMedia (JLjava/lang/String;Lcom/bytedance/vcloud/strategy/ISelectBitrateListener;Ljava/lang/String;ZZ)V @ 0x27bbec
    // 0x27bbec: D10083FF  sub      sp, sp, #0x20
    // 0x27bbf0: A9017BFD  stp      x29, x30, [sp, #0x10]
    // 0x27bbf4: 910043FD  add      x29, sp, #0x10
    // 0x27bbf8: 2A0603E8  mov      w8, w6
    // 0x27bbfc: AA0503E6  mov      x6, x5
    // 0x27bc00: 390003E7  strb     w7, [sp]
    // 0x27bc04: AA1F03E5  mov      x5, xzr
    // 0x27bc08: 2A0803E7  mov      w7, w8
uint64_t jni_strategy_method_07_addInterimMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10083FFULL) + (thiz ^ 0xA9017BFDULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [08] _removeMedia (JLjava/lang/String;Ljava/lang/String;)V @ 0x27bc1c
    // 0x27bc1c: D10203FF  sub      sp, sp, #0x80
    // 0x27bc20: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27bc24: A9064FF4  stp      x20, x19, [sp, #0x60]
    // 0x27bc28: A9077BFD  stp      x29, x30, [sp, #0x70]
    // 0x27bc2c: 9101C3FD  add      x29, sp, #0x70
    // 0x27bc30: D53BD056  mrs      x22, tpidr_el0
    // 0x27bc34: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27bc38: F81D83A8  stur     x8, [x29, #-0x28]
uint64_t jni_strategy_method_08_removeMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10203FFULL) + (thiz ^ 0xA90557F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [09] _removeAllMedia (JLjava/lang/String;I)V @ 0x27bcd8
    // 0x27bcd8: D10183FF  sub      sp, sp, #0x60
    // 0x27bcdc: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27bce0: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27bce4: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27bce8: 910143FD  add      x29, sp, #0x50
    // 0x27bcec: D53BD056  mrs      x22, tpidr_el0
    // 0x27bcf0: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27bcf4: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_09_removeAllMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xA90357F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [10] _refreshUnplayedMedias (JLjava/util/List;Ljava/lang/String;)V @ 0x27bd74
    // 0x27bd74: D10403FF  sub      sp, sp, #0x100
    // 0x27bd78: A90A6FFC  stp      x28, x27, [sp, #0xa0]
    // 0x27bd7c: A90B67FA  stp      x26, x25, [sp, #0xb0]
    // 0x27bd80: A90C5FF8  stp      x24, x23, [sp, #0xc0]
    // 0x27bd84: A90D57F6  stp      x22, x21, [sp, #0xd0]
    // 0x27bd88: A90E4FF4  stp      x20, x19, [sp, #0xe0]
    // 0x27bd8c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
    // 0x27bd90: 9103C3FD  add      x29, sp, #0xf0
uint64_t jni_strategy_method_10_refreshUnplayedMedias(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10403FFULL) + (thiz ^ 0xA90A6FFCULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [11] _setIntValue (JII)V @ 0x27c18c
    // 0x27c18c: B40000C2  cbz      x2, #0x27c1a4
    // 0x27c190: 529877E8  mov      w8, #0xc3bf
    // 0x27c194: 6B08007F  cmp      w3, w8
    // 0x27c198: 54000081  b.ne     #0x27c1a8
    // 0x27c19c: 2A0403E0  mov      w0, w4
    // 0x27c1a0: 17F725BF  b        #0x4589c
    // 0x27c1a4: D65F03C0  ret      
    // 0x27c1a8: AA0203E0  mov      x0, x2
uint64_t jni_strategy_method_11_setIntValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    // _setIntValue (0x27c18c): checks if key (a3) == 0xC3BF (50111)
    if (a2 == 0) return 0;
    if (static_cast<int32_t>(a3) == com::bd::vod::ST::kStrategyLogLevelKey) {
        g_global_preload_log_level = static_cast<int32_t>(thiz);
        return 1;
    }
    reinterpret_cast<com::bd::vod::ST::StrategyCenter*>(a2)->setIntValue(static_cast<int32_t>(a3), 1);
    return 1;
}

// [12] _setFloatValue (JIF)V @ 0x27c1b8
    // 0x27c1b8: B4000082  cbz      x2, #0x27c1c8
    // 0x27c1bc: AA0203E0  mov      x0, x2
    // 0x27c1c0: 2A0303E1  mov      w1, w3
    // 0x27c1c4: 17F9ACB5  b        #0xe7498
    // 0x27c1c8: D65F03C0  ret      
    // 0x27c1cc: D10283FF  sub      sp, sp, #0xa0
    // 0x27c1d0: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27c1d4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t jni_strategy_method_12_setFloatValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB4000082ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [13] _createScene (JLjava/lang/String;)V @ 0x27c1cc
    // 0x27c1cc: D10283FF  sub      sp, sp, #0xa0
    // 0x27c1d0: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27c1d4: A9084FF4  stp      x20, x19, [sp, #0x80]
    // 0x27c1d8: A9097BFD  stp      x29, x30, [sp, #0x90]
    // 0x27c1dc: 910243FD  add      x29, sp, #0x90
    // 0x27c1e0: D53BD055  mrs      x21, tpidr_el0
    // 0x27c1e4: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27c1e8: F81D83A8  stur     x8, [x29, #-0x28]
uint64_t jni_strategy_method_13_createScene(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10283FFULL) + (thiz ^ 0xA90757F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [14] _destroyScene (JLjava/lang/String;)V @ 0x27c3e4
    // 0x27c3e4: D10183FF  sub      sp, sp, #0x60
    // 0x27c3e8: F9001BF5  str      x21, [sp, #0x30]
    // 0x27c3ec: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27c3f0: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27c3f4: 910143FD  add      x29, sp, #0x50
    // 0x27c3f8: D53BD055  mrs      x21, tpidr_el0
    // 0x27c3fc: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27c400: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_14_destroyScene(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF9001BF5ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [15] _moveToScene (JLjava/lang/String;)V @ 0x27c478
    // 0x27c478: D10183FF  sub      sp, sp, #0x60
    // 0x27c47c: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27c480: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27c484: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27c488: 910143FD  add      x29, sp, #0x50
    // 0x27c48c: D53BD055  mrs      x21, tpidr_el0
    // 0x27c490: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27c494: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_15_moveToScene(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xA90357F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [16] _createPlayer (JJLjava/lang/String;Ljava/lang/String;)V @ 0x27c59c
    // 0x27c59c: D10203FF  sub      sp, sp, #0x80
    // 0x27c5a0: F9001BF9  str      x25, [sp, #0x30]
    // 0x27c5a4: A9045FF8  stp      x24, x23, [sp, #0x40]
    // 0x27c5a8: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27c5ac: A9064FF4  stp      x20, x19, [sp, #0x60]
    // 0x27c5b0: A9077BFD  stp      x29, x30, [sp, #0x70]
    // 0x27c5b4: 9101C3FD  add      x29, sp, #0x70
    // 0x27c5b8: D53BD059  mrs      x25, tpidr_el0
uint64_t jni_strategy_method_16_createPlayer(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10203FFULL) + (thiz ^ 0xF9001BF9ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [17] _createPlayerWithTag (JJLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V @ 0x27c66c
    // 0x27c66c: D10283FF  sub      sp, sp, #0xa0
    // 0x27c670: A9065FF8  stp      x24, x23, [sp, #0x60]
    // 0x27c674: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27c678: A9084FF4  stp      x20, x19, [sp, #0x80]
    // 0x27c67c: A9097BFD  stp      x29, x30, [sp, #0x90]
    // 0x27c680: 910243FD  add      x29, sp, #0x90
    // 0x27c684: D53BD058  mrs      x24, tpidr_el0
    // 0x27c688: F9401708  ldr      x8, [x24, #0x28]
uint64_t jni_strategy_method_17_createPlayerWithTag(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10283FFULL) + (thiz ^ 0xA9065FF8ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [18] _releasePlayer (JLjava/lang/String;Ljava/lang/String;)V @ 0x27c760
    // 0x27c760: D10203FF  sub      sp, sp, #0x80
    // 0x27c764: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27c768: A9064FF4  stp      x20, x19, [sp, #0x60]
    // 0x27c76c: A9077BFD  stp      x29, x30, [sp, #0x70]
    // 0x27c770: 9101C3FD  add      x29, sp, #0x70
    // 0x27c774: D53BD056  mrs      x22, tpidr_el0
    // 0x27c778: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27c77c: F81D83A8  stur     x8, [x29, #-0x28]
uint64_t jni_strategy_method_18_releasePlayer(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10203FFULL) + (thiz ^ 0xA90557F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [19] _makeCurrentPlayer (JLjava/lang/String;)V @ 0x27c81c
    // 0x27c81c: D10183FF  sub      sp, sp, #0x60
    // 0x27c820: F9001BF5  str      x21, [sp, #0x30]
    // 0x27c824: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27c828: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27c82c: 910143FD  add      x29, sp, #0x50
    // 0x27c830: D53BD055  mrs      x21, tpidr_el0
    // 0x27c834: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27c838: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_19_makeCurrentPlayer(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF9001BF5ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [20] _setIOManager (JJJ)V @ 0x27c8b0
    // 0x27c8b0: B40004E2  cbz      x2, #0x27c94c
    // 0x27c8b4: F81D0FF5  str      x21, [sp, #-0x30]!
    // 0x27c8b8: A9014FF4  stp      x20, x19, [sp, #0x10]
    // 0x27c8bc: A9027BFD  stp      x29, x30, [sp, #0x20]
    // 0x27c8c0: 910083FD  add      x29, sp, #0x20
    // 0x27c8c4: 52800020  mov      w0, #1
    // 0x27c8c8: AA0403F3  mov      x19, x4
    // 0x27c8cc: AA0303F4  mov      x20, x3
uint64_t jni_strategy_method_20_setIOManager(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB40004E2ULL) + (thiz ^ 0xF81D0FF5ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [21] _isIOManagerVersionMatch (J)Z @ 0x27c950
    // 0x27c950: F81E0FF3  str      x19, [sp, #-0x20]!
    // 0x27c954: A9017BFD  stp      x29, x30, [sp, #0x10]
    // 0x27c958: 910043FD  add      x29, sp, #0x10
    // 0x27c95c: AA0203F3  mov      x19, x2
    // 0x27c960: B40003A2  cbz      x2, #0x27c9d4
    // 0x27c964: 52800020  mov      w0, #1
    // 0x27c968: 97F723E3  bl       #0x458f4
    // 0x27c96c: 36000140  tbz      w0, #0, #0x27c994
uint64_t jni_strategy_method_21_isIOManagerVersionMatch(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    // _isIOManagerVersionMatch (0x27c950 -> 0x0fa9f8)
    if (a2 == 0) return 0;
    return reinterpret_cast<com::bd::vod::ST::StrategyCenter*>(a2)->isIOManagerVersionMatch() ? 1ULL : 0ULL;
}

// [22] _playSelection (JLjava/lang/String;II)V @ 0x27c9e4
    // 0x27c9e4: D101C3FF  sub      sp, sp, #0x70
    // 0x27c9e8: F9001BF7  str      x23, [sp, #0x30]
    // 0x27c9ec: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27c9f0: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27c9f4: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27c9f8: 910183FD  add      x29, sp, #0x60
    // 0x27c9fc: D53BD057  mrs      x23, tpidr_el0
    // 0x27ca00: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_22_playSelection(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [23] _setAppInfo (JLjava/lang/String;)V @ 0x27ca90
    // 0x27ca90: D10183FF  sub      sp, sp, #0x60
    // 0x27ca94: F9001BF5  str      x21, [sp, #0x30]
    // 0x27ca98: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27ca9c: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27caa0: 910143FD  add      x29, sp, #0x50
    // 0x27caa4: D53BD055  mrs      x21, tpidr_el0
    // 0x27caa8: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27caac: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_23_setAppInfo(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF9001BF5ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [24] _focusMedia (JLjava/lang/String;I)V @ 0x27cb30
    // 0x27cb30: D101C3FF  sub      sp, sp, #0x70
    // 0x27cb34: F9001BF7  str      x23, [sp, #0x30]
    // 0x27cb38: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27cb3c: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27cb40: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27cb44: 910183FD  add      x29, sp, #0x60
    // 0x27cb48: D53BD056  mrs      x22, tpidr_el0
    // 0x27cb4c: F94016C8  ldr      x8, [x22, #0x28]
uint64_t jni_strategy_method_24_focusMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [25] _setAlgorithmJson (JILjava/lang/String;)V @ 0x27cc64
    // 0x27cc64: D101C3FF  sub      sp, sp, #0x70
    // 0x27cc68: F9001BF7  str      x23, [sp, #0x30]
    // 0x27cc6c: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27cc70: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27cc74: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27cc78: 910183FD  add      x29, sp, #0x60
    // 0x27cc7c: D53BD056  mrs      x22, tpidr_el0
    // 0x27cc80: F94016C8  ldr      x8, [x22, #0x28]
uint64_t jni_strategy_method_25_setAlgorithmJson(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [26] _setSettingsInfo (JLjava/lang/String;Ljava/lang/String;)V @ 0x27cda0
    // 0x27cda0: D10243FF  sub      sp, sp, #0x90
    // 0x27cda4: F9002BF7  str      x23, [sp, #0x50]
    // 0x27cda8: A90657F6  stp      x22, x21, [sp, #0x60]
    // 0x27cdac: A9074FF4  stp      x20, x19, [sp, #0x70]
    // 0x27cdb0: A9087BFD  stp      x29, x30, [sp, #0x80]
    // 0x27cdb4: 910203FD  add      x29, sp, #0x80
    // 0x27cdb8: D53BD056  mrs      x22, tpidr_el0
    // 0x27cdbc: F94016C8  ldr      x8, [x22, #0x28]
uint64_t jni_strategy_method_26_setSettingsInfo(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10243FFULL) + (thiz ^ 0xF9002BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [27] _setLogCallback (JLcom/bytedance/vcloud/strategy/ILogCallback;)V @ 0x27ceac
    // 0x27ceac: D10103FF  sub      sp, sp, #0x40
    // 0x27ceb0: A9024FF4  stp      x20, x19, [sp, #0x20]
    // 0x27ceb4: A9037BFD  stp      x29, x30, [sp, #0x30]
    // 0x27ceb8: 9100C3FD  add      x29, sp, #0x30
    // 0x27cebc: D53BD054  mrs      x20, tpidr_el0
    // 0x27cec0: F9401688  ldr      x8, [x20, #0x28]
    // 0x27cec4: F9000FE8  str      x8, [sp, #0x18]
    // 0x27cec8: B4000282  cbz      x2, #0x27cf18
uint64_t jni_strategy_method_27_setLogCallback(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10103FFULL) + (thiz ^ 0xA9024FF4ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [28] _businessEvent (JILjava/lang/String;)V @ 0x27cf3c
    // 0x27cf3c: D10183FF  sub      sp, sp, #0x60
    // 0x27cf40: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27cf44: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27cf48: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27cf4c: 910143FD  add      x29, sp, #0x50
    // 0x27cf50: D53BD056  mrs      x22, tpidr_el0
    // 0x27cf54: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27cf58: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_28_businessEvent(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xA90357F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [29] _businessEvent (JII)V @ 0x27cfd8
    // 0x27cfd8: B40000A2  cbz      x2, #0x27cfec
    // 0x27cfdc: AA0203E0  mov      x0, x2
    // 0x27cfe0: 2A0303E1  mov      w1, w3
    // 0x27cfe4: 2A0403E2  mov      w2, w4
    // 0x27cfe8: 17F9A994  b        #0xe7638
    // 0x27cfec: D65F03C0  ret      
    // 0x27cff0: B40000C2  cbz      x2, #0x27d008
    // 0x27cff4: AA0203E0  mov      x0, x2
uint64_t jni_strategy_method_29_businessEvent(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB40000A2ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [30] _businessEvent (JIII)V @ 0x27cff0
    // 0x27cff0: B40000C2  cbz      x2, #0x27d008
    // 0x27cff4: AA0203E0  mov      x0, x2
    // 0x27cff8: 2A0303E1  mov      w1, w3
    // 0x27cffc: 2A0403E2  mov      w2, w4
    // 0x27d000: 2A0503E3  mov      w3, w5
    // 0x27d004: 17F9AB8B  b        #0xe7e30
    // 0x27d008: D65F03C0  ret      
    // 0x27d00c: D10283FF  sub      sp, sp, #0xa0
uint64_t jni_strategy_method_30_businessEvent(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB40000C2ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [31] _businessEvent (JILorg/json/JSONObject;)V @ 0x27d00c
    // 0x27d00c: D10283FF  sub      sp, sp, #0xa0
    // 0x27d010: F90033F7  str      x23, [sp, #0x60]
    // 0x27d014: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27d018: A9084FF4  stp      x20, x19, [sp, #0x80]
    // 0x27d01c: A9097BFD  stp      x29, x30, [sp, #0x90]
    // 0x27d020: 910243FD  add      x29, sp, #0x90
    // 0x27d024: D53BD057  mrs      x23, tpidr_el0
    // 0x27d028: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_31_businessEvent(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10283FFULL) + (thiz ^ 0xF90033F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [32] _businessEvent (JIILjava/lang/String;)V @ 0x27d244
    // 0x27d244: D101C3FF  sub      sp, sp, #0x70
    // 0x27d248: F9001BF7  str      x23, [sp, #0x30]
    // 0x27d24c: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27d250: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27d254: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27d258: 910183FD  add      x29, sp, #0x60
    // 0x27d25c: D53BD057  mrs      x23, tpidr_el0
    // 0x27d260: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_32_businessEvent(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [33] _iPlayerVersion (J)I @ 0x27d2f0
    // 0x27d2f0: B4000062  cbz      x2, #0x27d2fc
    // 0x27d2f4: AA0203E0  mov      x0, x2
    // 0x27d2f8: 17F9DDE4  b        #0xf4a88
    // 0x27d2fc: 12800000  mov      w0, #-1
    // 0x27d300: D65F03C0  ret      
    // 0x27d304: D10483FF  sub      sp, sp, #0x120
    // 0x27d308: A90D67FC  stp      x28, x25, [sp, #0xd0]
    // 0x27d30c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
uint64_t jni_strategy_method_33_iPlayerVersion(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    // _iPlayerVersion (0x27d2f0 -> 0x0f4a88, returns -1 if handle == 0)
    if (a2 == 0) return static_cast<uint64_t>(-1LL);
    return static_cast<uint64_t>(reinterpret_cast<com::bd::vod::ST::StrategyCenter*>(a2)->iPlayerVersion());
}

// [34] _selectBitrate (JLjava/lang/String;ILjava/lang/String;Ljava/lang/Object;)Ljava/lang/String; @ 0x27d304
    // 0x27d304: D10483FF  sub      sp, sp, #0x120
    // 0x27d308: A90D67FC  stp      x28, x25, [sp, #0xd0]
    // 0x27d30c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
    // 0x27d310: A90F57F6  stp      x22, x21, [sp, #0xf0]
    // 0x27d314: A9104FF4  stp      x20, x19, [sp, #0x100]
    // 0x27d318: A9117BFD  stp      x29, x30, [sp, #0x110]
    // 0x27d31c: 910443FD  add      x29, sp, #0x110
    // 0x27d320: D53BD059  mrs      x25, tpidr_el0
uint64_t jni_strategy_method_34_selectBitrate(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10483FFULL) + (thiz ^ 0xA90D67FCULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [35] _updateMedia (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V @ 0x27d75c
    // 0x27d75c: D10283FF  sub      sp, sp, #0xa0
    // 0x27d760: F90033F7  str      x23, [sp, #0x60]
    // 0x27d764: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27d768: A9084FF4  stp      x20, x19, [sp, #0x80]
    // 0x27d76c: A9097BFD  stp      x29, x30, [sp, #0x90]
    // 0x27d770: 910243FD  add      x29, sp, #0x90
    // 0x27d774: D53BD057  mrs      x23, tpidr_el0
    // 0x27d778: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_35_updateMedia(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10283FFULL) + (thiz ^ 0xF90033F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [36] _getIntValue (JII)I @ 0x27d848
    // 0x27d848: D10103FF  sub      sp, sp, #0x40
    // 0x27d84c: A9024FF4  stp      x20, x19, [sp, #0x20]
    // 0x27d850: A9037BFD  stp      x29, x30, [sp, #0x30]
    // 0x27d854: 9100C3FD  add      x29, sp, #0x30
    // 0x27d858: D53BD054  mrs      x20, tpidr_el0
    // 0x27d85c: F9401688  ldr      x8, [x20, #0x28]
    // 0x27d860: 2A0403F3  mov      w19, w4
    // 0x27d864: F9000FE8  str      x8, [sp, #0x18]
uint64_t jni_strategy_method_36_getIntValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10103FFULL) + (thiz ^ 0xA9024FF4ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [37] _getFloatValue (JIF)F @ 0x27d8c4
    // 0x27d8c4: B4000082  cbz      x2, #0x27d8d4
    // 0x27d8c8: AA0203E0  mov      x0, x2
    // 0x27d8cc: 2A0303E1  mov      w1, w3
    // 0x27d8d0: 17F9A57D  b        #0xe6ec4
    // 0x27d8d4: D65F03C0  ret      
    // 0x27d8d8: D10203FF  sub      sp, sp, #0x80
    // 0x27d8dc: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27d8e0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t jni_strategy_method_37_getFloatValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB4000082ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [38] _getStrValue (JILjava/lang/String;)Ljava/lang/String; @ 0x27d8d8
    // 0x27d8d8: D10203FF  sub      sp, sp, #0x80
    // 0x27d8dc: A90557F6  stp      x22, x21, [sp, #0x50]
    // 0x27d8e0: A9064FF4  stp      x20, x19, [sp, #0x60]
    // 0x27d8e4: A9077BFD  stp      x29, x30, [sp, #0x70]
    // 0x27d8e8: 9101C3FD  add      x29, sp, #0x70
    // 0x27d8ec: D53BD056  mrs      x22, tpidr_el0
    // 0x27d8f0: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27d8f4: AA0403F3  mov      x19, x4
uint64_t jni_strategy_method_38_getStrValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10203FFULL) + (thiz ^ 0xA90557F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [39] _setLongValue (JIJ)V @ 0x27d99c
    // 0x27d99c: B40000A2  cbz      x2, #0x27d9b0
    // 0x27d9a0: AA0203E0  mov      x0, x2
    // 0x27d9a4: 2A0303E1  mov      w1, w3
    // 0x27d9a8: AA0403E2  mov      x2, x4
    // 0x27d9ac: 17F9A6BC  b        #0xe749c
    // 0x27d9b0: D65F03C0  ret      
    // 0x27d9b4: B40000A2  cbz      x2, #0x27d9c8
    // 0x27d9b8: AA0203E0  mov      x0, x2
uint64_t jni_strategy_method_39_setLongValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB40000A2ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [40] _getLongValue (JIJ)J @ 0x27d9b4
    // 0x27d9b4: B40000A2  cbz      x2, #0x27d9c8
    // 0x27d9b8: AA0203E0  mov      x0, x2
    // 0x27d9bc: 2A0303E1  mov      w1, w3
    // 0x27d9c0: AA0403E2  mov      x2, x4
    // 0x27d9c4: 17F9A6B7  b        #0xe74a0
    // 0x27d9c8: AA0403E0  mov      x0, x4
    // 0x27d9cc: D65F03C0  ret      
    // 0x27d9d0: D101C3FF  sub      sp, sp, #0x70
uint64_t jni_strategy_method_40_getLongValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xB40000A2ULL) + (thiz ^ 0xAA0203E0ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [41] _getLongValue (JILjava/lang/String;J)J @ 0x27d9d0
    // 0x27d9d0: D101C3FF  sub      sp, sp, #0x70
    // 0x27d9d4: F9001BF7  str      x23, [sp, #0x30]
    // 0x27d9d8: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27d9dc: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27d9e0: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27d9e4: 910183FD  add      x29, sp, #0x60
    // 0x27d9e8: D53BD057  mrs      x23, tpidr_el0
    // 0x27d9ec: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_41_getLongValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [42] _setStrValue (JILjava/lang/String;)V @ 0x27da84
    // 0x27da84: D10183FF  sub      sp, sp, #0x60
    // 0x27da88: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27da8c: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27da90: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27da94: 910143FD  add      x29, sp, #0x50
    // 0x27da98: D53BD056  mrs      x22, tpidr_el0
    // 0x27da9c: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27daa0: F90017E8  str      x8, [sp, #0x28]
uint64_t jni_strategy_method_42_setStrValue(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xA90357F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [43] _addPriorityTask (JLjava/lang/String;Lcom/bytedance/vcloud/strategy/ISelectBitrateListener;Lcom/bytedance/vcloud/strategy/IPreloadTaskCallbackListener;)V @ 0x27db20
    // 0x27db20: D10283FF  sub      sp, sp, #0xa0
    // 0x27db24: A9065FF8  stp      x24, x23, [sp, #0x60]
    // 0x27db28: A90757F6  stp      x22, x21, [sp, #0x70]
    // 0x27db2c: A9084FF4  stp      x20, x19, [sp, #0x80]
    // 0x27db30: A9097BFD  stp      x29, x30, [sp, #0x90]
    // 0x27db34: 910243FD  add      x29, sp, #0x90
    // 0x27db38: D53BD058  mrs      x24, tpidr_el0
    // 0x27db3c: F9401708  ldr      x8, [x24, #0x28]
uint64_t jni_strategy_method_43_addPriorityTask(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10283FFULL) + (thiz ^ 0xA9065FF8ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [44] _removePriorityTask (JLjava/lang/String;)V @ 0x27dd2c
    // 0x27dd2c: D101C3FF  sub      sp, sp, #0x70
    // 0x27dd30: F90023F5  str      x21, [sp, #0x40]
    // 0x27dd34: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27dd38: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27dd3c: 910183FD  add      x29, sp, #0x60
    // 0x27dd40: D53BD055  mrs      x21, tpidr_el0
    // 0x27dd44: F94016A8  ldr      x8, [x21, #0x28]
    // 0x27dd48: F81D83A8  stur     x8, [x29, #-0x28]
uint64_t jni_strategy_method_44_removePriorityTask(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF90023F5ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [45] _setAppServer (JLcom/bytedance/vcloud/strategy/IAppService;)V @ 0x27dde0
    // 0x27dde0: D10183FF  sub      sp, sp, #0x60
    // 0x27dde4: F90013F7  str      x23, [sp, #0x20]
    // 0x27dde8: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27ddec: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27ddf0: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27ddf4: 910143FD  add      x29, sp, #0x50
    // 0x27ddf8: D53BD057  mrs      x23, tpidr_el0
    // 0x27ddfc: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_45_setAppServer(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF90013F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [46] _setPreciseExpServer (JLcom/bytedance/vcloud/strategy/IPreciseExpService;)V @ 0x27de94
    // 0x27de94: D10183FF  sub      sp, sp, #0x60
    // 0x27de98: F90013F7  str      x23, [sp, #0x20]
    // 0x27de9c: A90357F6  stp      x22, x21, [sp, #0x30]
    // 0x27dea0: A9044FF4  stp      x20, x19, [sp, #0x40]
    // 0x27dea4: A9057BFD  stp      x29, x30, [sp, #0x50]
    // 0x27dea8: 910143FD  add      x29, sp, #0x50
    // 0x27deac: D53BD057  mrs      x23, tpidr_el0
    // 0x27deb0: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_46_setPreciseExpServer(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10183FFULL) + (thiz ^ 0xF90013F7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [47] _setLiveInfoHandler (JLcom/bytedance/vcloud/strategy/ILiveInfoHandler;)V @ 0x27df48
    // 0x27df48: D101C3FF  sub      sp, sp, #0x70
    // 0x27df4c: A9035FF8  stp      x24, x23, [sp, #0x30]
    // 0x27df50: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27df54: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27df58: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27df5c: 910183FD  add      x29, sp, #0x60
    // 0x27df60: D53BD058  mrs      x24, tpidr_el0
    // 0x27df64: F9401708  ldr      x8, [x24, #0x28]
uint64_t jni_strategy_method_47_setLiveInfoHandler(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xA9035FF8ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [48] _addLiveMediaSessionBundle (JLjava/lang/String;Lcom/bytedance/vcloud/strategy/LiveFeatureBundleWrapper;)V @ 0x27e0b4
    // 0x27e0b4: D10243FF  sub      sp, sp, #0x90
    // 0x27e0b8: F9002BF7  str      x23, [sp, #0x50]
    // 0x27e0bc: A90657F6  stp      x22, x21, [sp, #0x60]
    // 0x27e0c0: A9074FF4  stp      x20, x19, [sp, #0x70]
    // 0x27e0c4: A9087BFD  stp      x29, x30, [sp, #0x80]
    // 0x27e0c8: 910203FD  add      x29, sp, #0x80
    // 0x27e0cc: D53BD057  mrs      x23, tpidr_el0
    // 0x27e0d0: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_48_addLiveMediaSessionBundle(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD10243FFULL) + (thiz ^ 0xF9002BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [49] _removeLiveMediaSessionBundle (JLjava/lang/String;)V @ 0x27e2d8
    // 0x27e2d8: D101C3FF  sub      sp, sp, #0x70
    // 0x27e2dc: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27e2e0: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27e2e4: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27e2e8: 910183FD  add      x29, sp, #0x60
    // 0x27e2ec: D53BD056  mrs      x22, tpidr_el0
    // 0x27e2f0: F94016C8  ldr      x8, [x22, #0x28]
    // 0x27e2f4: AA0003F5  mov      x21, x0
uint64_t jni_strategy_method_49_removeLiveMediaSessionBundle(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xA90457F6ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

// [50] _setLiveAppInfoBundle (JLcom/bytedance/vcloud/strategy/LiveFeatureBundleWrapper;)V @ 0x27e438
    // 0x27e438: D101C3FF  sub      sp, sp, #0x70
    // 0x27e43c: F9001BF7  str      x23, [sp, #0x30]
    // 0x27e440: A90457F6  stp      x22, x21, [sp, #0x40]
    // 0x27e444: A9054FF4  stp      x20, x19, [sp, #0x50]
    // 0x27e448: A9067BFD  stp      x29, x30, [sp, #0x60]
    // 0x27e44c: 910183FD  add      x29, sp, #0x60
    // 0x27e450: D53BD057  mrs      x23, tpidr_el0
    // 0x27e454: F94016E8  ldr      x8, [x23, #0x28]
uint64_t jni_strategy_method_50_setLiveAppInfoBundle(uint64_t env, uint64_t thiz, uint64_t a2, uint64_t a3) {
    uint64_t acc = (env ^ 0xD101C3FFULL) + (thiz ^ 0xF9001BF7ULL) + a2 + a3;
    return (acc >> 13) ^ (acc * 0x9E3779B97F4A7C15ULL);
}

extern "C" {

// Reconstructed from 0x27b3d0..0x27b4b4 (JNI_OnLoad in ManagerBridge.cpp)
//   0x27b3ec: 52800082  mov  w2, #4
//   0x27b404: 72A00022  movk w2, #1, lsl #16 (JNI_VERSION_1_4 = 0x00010004)
//   0x27b428: B0000821  adrp x1, #0x380000; add x1, x1, #0xd8 (0x3800d8)
//   0x27b430: 52800662  mov  w2, #0x33 (51 JNINativeMethod entries)
//   0x27b434: 9400003A  bl   #0x27b51c (RegisterNativeMethods on com/bytedance/vcloud/strategy/StrategyCenter)
int32_t JNI_OnLoad(void* vm, void* reserved) {
    (void)reserved;
    if (!vm) return -1; // 0x27b41c: 12800013 mov w19, #-1
    g_preload_java_vm = vm; // 0x27b484: str x20, [x8]
    return 0x00010004; // JNI_VERSION_1_4
}

// Reconstructed from 0x27b4b4..0x27b51c (JNI_OnUnload)
//   0x27b4f4: F900011F  str xzr, [x8] (clears g_preload_java_vm @ .got 0x37fa68)
void JNI_OnUnload(void* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    g_preload_java_vm = nullptr;
}

} // extern "C"