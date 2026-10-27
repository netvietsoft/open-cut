// ============================================================================
// File: tt_ugen_layout_rodata_tables.h
// Target: libtt_ugen_layout.so (360,968 bytes)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Declarations for exported .rodata constants (`YGValueZero`, `YGValueUndefined`,
//     `YGValueAuto`, `leading`, `trailing`), floating-point comparison epsilons,
//     and the 95-entry JNINativeMethod registration table at .data 0x05f018.
// VN: Khai báo cho các hằng số .rodata xuất (`YGValueZero`, `YGValueUndefined`,
//     `YGValueAuto`, `leading`, `trailing`), epsilon so sánh dấu phẩy động,
//     và bảng đăng ký JNINativeMethod 95 mục tại .data 0x05f018.
// ============================================================================

#pragma once

#include "tt_ugen_layout_types.h"
#include <cstdint>
#include <cstddef>

extern "C" {
// EN: Exported STT_OBJECT symbols in .rodata (0x01ad94..0x01addc).
// VN: Các biểu tượng STT_OBJECT xuất trong .rodata (0x01ad94..0x01addc).
extern const YGValue YGValueZero;       // 0x01ad94 (8 B: {0.0f, YGUnitPoint})
extern const YGValue YGValueUndefined;  // 0x01ad9c (8 B: {NaN, YGUnitUndefined})
extern const YGValue YGValueAuto;       // 0x01ada4 (8 B: {NaN, YGUnitAuto})
extern const YGEdge  leading[4];        // 0x01adbc (16 B: {YGEdgeTop, YGEdgeBottom, YGEdgeLeft, YGEdgeRight})
extern const YGEdge  trailing[4];       // 0x01adcc (16 B: {YGEdgeBottom, YGEdgeTop, YGEdgeRight, YGEdgeLeft})
}

namespace nextai {
namespace opencut {
namespace tt_ugen_layout {

// EN: Exact IEEE-754 tolerances from .rodata 0x018bc0 and .text 0x025e9c:
//     - kYogaDoubleEpsilon_018bc0 = 0.0001 (0x3F1A36E2EB1C432DULL)
//     - kYogaFloatEpsilon_025e9c  = 0.0001f (0x38D1B717u)
//     - kYogaPercentScale_033048  = 0.01f (0x3C23D70Au)
// VN: Sai số IEEE-754 chính xác từ .rodata 0x018bc0 và .text 0x025e9c.
constexpr uint64_t kYogaDoubleEpsilonBits_018bc0 = 0x3F1A36E2EB1C432DULL;
constexpr double   kYogaDoubleEpsilon_018bc0     = 0.0001;
constexpr uint32_t kYogaFloatEpsilonBits_025e9c  = 0x38D1B717u;
constexpr float    kYogaFloatEpsilon_025e9c      = 0.0001f;
constexpr uint32_t kYogaPercentScaleBits_033048  = 0x3C23D70Au;
constexpr float    kYogaPercentScale_033048      = 0.01f;

// EN: JNI target class string at .rodata 0x01a2eb ("com/bytedance/adsdk/ugeno/yoga/YogaNative").
// VN: Chuỗi tên lớp đích JNI tại .rodata 0x01a2eb ("com/bytedance/adsdk/ugeno/yoga/YogaNative").
extern const char kYogaNativeClassName_01a2eb[];

// EN: 95 JNINativeMethod descriptors at .data 0x05f018..0x05f900 registered by
//     YGJNIVanilla::registerNatives (0x026650: mov w3, #0x5f).
// VN: 95 bộ mô tả JNINativeMethod tại .data 0x05f018..0x05f900 được đăng ký bởi
//     YGJNIVanilla::registerNatives (0x026650: mov w3, #0x5f).
extern const UgenJniMethodEntry kYogaNativeJniMethods_05f018[95];

} // namespace tt_ugen_layout
} // namespace opencut
} // namespace nextai
