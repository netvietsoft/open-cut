// ============================================================================
// File: tt_ugen_layout_rodata_tables.cpp
// Target: libtt_ugen_layout.so (360,968 bytes)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Definitions of exported .rodata constants (`YGValueZero`, `YGValueUndefined`,
//     `YGValueAuto`, `leading`, `trailing`) and the 95-entry `YogaNative` JNI table.
// VN: Định nghĩa các hằng số .rodata xuất (`YGValueZero`, `YGValueUndefined`,
//     `YGValueAuto`, `leading`, `trailing`) và bảng JNI `YogaNative` 95 mục.
// ============================================================================

#include "tt_ugen_layout_rodata_tables.h"
#include <cmath>

extern "C" {

// .rodata 0x01ad94: 00 00 00 00 01 00 00 00
const YGValue YGValueZero = { 0.0f, YGUnitPoint };

// .rodata 0x01ad9c: 00 00 C0 7F 00 00 00 00
const YGValue YGValueUndefined = { NAN, YGUnitUndefined };

// .rodata 0x01ada4: 00 00 C0 7F 03 00 00 00
const YGValue YGValueAuto = { NAN, YGUnitAuto };

// .rodata 0x01adbc: 01 00 00 00 03 00 00 00 00 00 00 00 02 00 00 00
const YGEdge leading[4] = { YGEdgeTop, YGEdgeBottom, YGEdgeLeft, YGEdgeRight };

// .rodata 0x01adcc: 03 00 00 00 01 00 00 00 02 00 00 00 00 00 00 00
const YGEdge trailing[4] = { YGEdgeBottom, YGEdgeTop, YGEdgeRight, YGEdgeLeft };

} // extern "C"

namespace nextai {
namespace opencut {
namespace tt_ugen_layout {

const char kYogaNativeClassName_01a2eb[] = "com/bytedance/adsdk/ugeno/yoga/YogaNative";

const UgenJniMethodEntry kYogaNativeJniMethods_05f018[95] = {
    /* [00] */ { "jni_YGConfigNewJNI", "()J", 0x019B5Fu, 0x019963u, 0x026668u },
    /* [01] */ { "jni_YGConfigFreeJNI", "(J)V", 0x01A7F5u, 0x019222u, 0x02666Cu },
    /* [02] */ { "jni_YGConfigSetExperimentalFeatureEnabledJNI", "(JIZ)V", 0x018BD7u, 0x01AB7Cu, 0x026708u },
    /* [03] */ { "jni_YGConfigSetUseWebDefaultsJNI", "(JZ)V", 0x01A540u, 0x01AAA8u, 0x026720u },
    /* [04] */ { "jni_YGConfigSetPrintTreeFlagJNI", "(JZ)V", 0x019459u, 0x01AAA8u, 0x026730u },
    /* [05] */ { "jni_YGConfigSetPointScaleFactorJNI", "(JF)V", 0x019C8Fu, 0x01A051u, 0x026740u },
    /* [06] */ { "jni_YGConfigSetUseLegacyStretchBehaviourJNI", "(JZ)V", 0x01A471u, 0x01AAA8u, 0x026748u },
    /* [07] */ { "jni_YGConfigSetErrataJNI", "(JI)V", 0x019B72u, 0x01AB83u, 0x026758u },
    /* [08] */ { "jni_YGConfigGetErrataJNI", "(J)I", 0x019967u, 0x019861u, 0x026764u },
    /* [09] */ { "jni_YGConfigSetLoggerJNI", "(JLcom/bytedance/adsdk/ugeno/yoga/YogaLogger;)V", 0x019B8Bu, 0x0190A8u, 0x02676Cu },
    /* [10] */ { "jni_YGNodeNewJNI", "()J", 0x018D39u, 0x019963u, 0x0268E4u },
    /* [11] */ { "jni_YGNodeNewWithConfigJNI", "(J)J", 0x019EF7u, 0x01AA10u, 0x026910u },
    /* [12] */ { "jni_YGNodeDeallocateJNI", "(J)V", 0x018FD7u, 0x019222u, 0x026940u },
    /* [13] */ { "jni_YGNodeResetJNI", "(J)V", 0x019F12u, 0x019222u, 0x026950u },
    /* [14] */ { "jni_YGNodeInsertChildJNI", "(JJI)V", 0x01A63Fu, 0x01A057u, 0x026988u },
    /* [15] */ { "jni_YGNodeSwapChildJNI", "(JJI)V", 0x01A922u, 0x01A057u, 0x026998u },
    /* [16] */ { "jni_YGNodeSetIsReferenceBaselineJNI", "(JZ)V", 0x018E71u, 0x01AAA8u, 0x0269A8u },
    /* [17] */ { "jni_YGNodeIsReferenceBaselineJNI", "(J)Z", 0x019D8Eu, 0x018CAEu, 0x0269B8u },
    /* [18] */ { "jni_YGNodeRemoveAllChildrenJNI", "(J)V", 0x0196A8u, 0x019222u, 0x0269D4u },
    /* [19] */ { "jni_YGNodeRemoveChildJNI", "(JJ)V", 0x0196C7u, 0x019CB2u, 0x0269DCu },
    /* [20] */ { "jni_YGNodeCalculateLayoutJNI", "(JFF[J[Lcom/bytedance/adsdk/ugeno/yoga/YogaNodeJNIBase;)V", 0x019227u, 0x019BA4u, 0x0269E8u },
    /* [21] */ { "jni_YGNodeMarkDirtyJNI", "(J)V", 0x01AAAEu, 0x019222u, 0x026CD4u },
    /* [22] */ { "jni_YGNodeMarkDirtyAndPropagateToDescendantsJNI", "(J)V", 0x019980u, 0x019222u, 0x026CDCu },
    /* [23] */ { "jni_YGNodeIsDirtyJNI", "(J)Z", 0x018CB3u, 0x018CAEu, 0x026CE4u },
    /* [24] */ { "jni_YGNodeCopyStyleJNI", "(JJ)V", 0x01A723u, 0x019CB2u, 0x026D00u },
    /* [25] */ { "jni_YGNodeStyleGetDirectionJNI", "(J)I", 0x019479u, 0x019861u, 0x026D0Cu },
    /* [26] */ { "jni_YGNodeStyleSetDirectionJNI", "(JI)V", 0x019244u, 0x01AB83u, 0x026D14u },
    /* [27] */ { "jni_YGNodeStyleGetFlexDirectionJNI", "(J)I", 0x0190D8u, 0x019861u, 0x026D20u },
    /* [28] */ { "jni_YGNodeStyleSetFlexDirectionJNI", "(JI)V", 0x0190FBu, 0x01AB83u, 0x026D28u },
    /* [29] */ { "jni_YGNodeStyleGetJustifyContentJNI", "(J)I", 0x019A9Eu, 0x019861u, 0x026D34u },
    /* [30] */ { "jni_YGNodeStyleSetJustifyContentJNI", "(JI)V", 0x01AA15u, 0x01AB83u, 0x026D3Cu },
    /* [31] */ { "jni_YGNodeStyleGetAlignItemsJNI", "(J)I", 0x018E95u, 0x019861u, 0x026D48u },
    /* [32] */ { "jni_YGNodeStyleSetAlignItemsJNI", "(JI)V", 0x01A05Eu, 0x01AB83u, 0x026D50u },
    /* [33] */ { "jni_YGNodeStyleGetAlignSelfJNI", "(J)I", 0x01A73Au, 0x019861u, 0x026D5Cu },
    /* [34] */ { "jni_YGNodeStyleSetAlignSelfJNI", "(JI)V", 0x019263u, 0x01AB83u, 0x026D64u },
    /* [35] */ { "jni_YGNodeStyleGetAlignContentJNI", "(J)I", 0x0195CEu, 0x019861u, 0x026D70u },
    /* [36] */ { "jni_YGNodeStyleSetAlignContentJNI", "(JI)V", 0x01A49Du, 0x01AB83u, 0x026D78u },
    /* [37] */ { "jni_YGNodeStyleGetPositionTypeJNI", "(J)I", 0x01A759u, 0x019861u, 0x026D84u },
    /* [38] */ { "jni_YGNodeStyleSetPositionTypeJNI", "(JI)V", 0x018D4Au, 0x01AB83u, 0x026D8Cu },
    /* [39] */ { "jni_YGNodeStyleGetFlexWrapJNI", "(J)I", 0x019DAFu, 0x019861u, 0x026D98u },
    /* [40] */ { "jni_YGNodeStyleSetFlexWrapJNI", "(JI)V", 0x01911Eu, 0x01AB83u, 0x026DA0u },
    /* [41] */ { "jni_YGNodeStyleGetOverflowJNI", "(J)I", 0x01A561u, 0x019861u, 0x026DACu },
    /* [42] */ { "jni_YGNodeStyleSetOverflowJNI", "(JI)V", 0x018D6Cu, 0x01AB83u, 0x026DB4u },
    /* [43] */ { "jni_YGNodeStyleGetDisplayJNI", "(J)I", 0x01A939u, 0x019861u, 0x026DC0u },
    /* [44] */ { "jni_YGNodeStyleSetDisplayJNI", "(JI)V", 0x01AA39u, 0x01AB83u, 0x026DC8u },
    /* [45] */ { "jni_YGNodeStyleGetFlexJNI", "(J)F", 0x01A658u, 0x01A07Eu, 0x026DD4u },
    /* [46] */ { "jni_YGNodeStyleSetFlexJNI", "(JF)V", 0x01A956u, 0x01A051u, 0x026DDCu },
    /* [47] */ { "jni_YGNodeStyleGetFlexGrowJNI", "(J)F", 0x0195F0u, 0x01A07Eu, 0x026DE4u },
    /* [48] */ { "jni_YGNodeStyleSetFlexGrowJNI", "(JF)V", 0x01A083u, 0x01A051u, 0x026DECu },
    /* [49] */ { "jni_YGNodeStyleGetFlexShrinkJNI", "(J)F", 0x01A0A1u, 0x01A07Eu, 0x026DF4u },
    /* [50] */ { "jni_YGNodeStyleSetFlexShrinkJNI", "(JF)V", 0x019DCDu, 0x01A051u, 0x026DFCu },
    /* [51] */ { "jni_YGNodeStyleGetFlexBasisJNI", "(J)J", 0x01AB89u, 0x01AA10u, 0x026E04u },
    /* [52] */ { "jni_YGNodeStyleSetFlexBasisJNI", "(JF)V", 0x01A315u, 0x01A051u, 0x026E0Cu },
    /* [53] */ { "jni_YGNodeStyleSetFlexBasisPercentJNI", "(JF)V", 0x01A970u, 0x01A051u, 0x026E14u },
    /* [54] */ { "jni_YGNodeStyleSetFlexBasisAutoJNI", "(J)V", 0x018CC8u, 0x019222u, 0x026E1Cu },
    /* [55] */ { "jni_YGNodeStyleGetMarginJNI", "(JI)J", 0x01913Cu, 0x019DEDu, 0x026E24u },
    /* [56] */ { "jni_YGNodeStyleSetMarginJNI", "(JIF)V", 0x018EB5u, 0x01A4BFu, 0x026E68u },
    /* [57] */ { "jni_YGNodeStyleSetMarginPercentJNI", "(JIF)V", 0x019CB8u, 0x01A4BFu, 0x026EB4u },
    /* [58] */ { "jni_YGNodeStyleSetMarginAutoJNI", "(JI)V", 0x019AC2u, 0x01AB83u, 0x026F00u },
    /* [59] */ { "jni_YGNodeStyleGetPaddingJNI", "(JI)J", 0x019359u, 0x019DEDu, 0x026F3Cu },
    /* [60] */ { "jni_YGNodeStyleSetPaddingJNI", "(JIF)V", 0x0196E0u, 0x01A4BFu, 0x026F80u },
    /* [61] */ { "jni_YGNodeStyleSetPaddingPercentJNI", "(JIF)V", 0x019866u, 0x01A4BFu, 0x026FCCu },
    /* [62] */ { "jni_YGNodeStyleGetBorderJNI", "(JI)F", 0x0196FDu, 0x019DF3u, 0x027018u },
    /* [63] */ { "jni_YGNodeStyleSetBorderJNI", "(JIF)V", 0x01A334u, 0x01A4BFu, 0x027060u },
    /* [64] */ { "jni_YGNodeStyleGetPositionJNI", "(JI)J", 0x01A0C1u, 0x019DEDu, 0x0270ACu },
    /* [65] */ { "jni_YGNodeStyleSetPositionJNI", "(JIF)V", 0x019376u, 0x01A4BFu, 0x0270B8u },
    /* [66] */ { "jni_YGNodeStyleSetPositionPercentJNI", "(JIF)V", 0x018ED1u, 0x01A4BFu, 0x0270C4u },
    /* [67] */ { "jni_YGNodeStyleGetWidthJNI", "(J)J", 0x019F25u, 0x01AA10u, 0x0270D0u },
    /* [68] */ { "jni_YGNodeStyleSetWidthJNI", "(JF)V", 0x018C04u, 0x01A051u, 0x0270D8u },
    /* [69] */ { "jni_YGNodeStyleSetWidthPercentJNI", "(JF)V", 0x018FEFu, 0x01A051u, 0x0270E0u },
    /* [70] */ { "jni_YGNodeStyleSetWidthAutoJNI", "(J)V", 0x018EF6u, 0x019222u, 0x0270E8u },
    /* [71] */ { "jni_YGNodeStyleGetHeightJNI", "(J)J", 0x019F40u, 0x01AA10u, 0x0270F0u },
    /* [72] */ { "jni_YGNodeStyleSetHeightJNI", "(JF)V", 0x01A0DFu, 0x01A051u, 0x0270F8u },
    /* [73] */ { "jni_YGNodeStyleSetHeightPercentJNI", "(JF)V", 0x019498u, 0x01A051u, 0x027100u },
    /* [74] */ { "jni_YGNodeStyleSetHeightAutoJNI", "(J)V", 0x01A996u, 0x019222u, 0x027108u },
    /* [75] */ { "jni_YGNodeStyleGetMinWidthJNI", "(J)J", 0x0194BBu, 0x01AA10u, 0x027110u },
    /* [76] */ { "jni_YGNodeStyleSetMinWidthJNI", "(JF)V", 0x01988Au, 0x01A051u, 0x027118u },
    /* [77] */ { "jni_YGNodeStyleSetMinWidthPercentJNI", "(JF)V", 0x0199B0u, 0x01A051u, 0x027120u },
    /* [78] */ { "jni_YGNodeStyleGetMinHeightJNI", "(J)J", 0x01AAC5u, 0x01AA10u, 0x027128u },
    /* [79] */ { "jni_YGNodeStyleSetMinHeightJNI", "(JF)V", 0x01ABA8u, 0x01A051u, 0x027130u },
    /* [80] */ { "jni_YGNodeStyleSetMinHeightPercentJNI", "(JF)V", 0x01A350u, 0x01A051u, 0x027138u },
    /* [81] */ { "jni_YGNodeStyleGetMaxWidthJNI", "(J)J", 0x019DF9u, 0x01AA10u, 0x027140u },
    /* [82] */ { "jni_YGNodeStyleSetMaxWidthJNI", "(JF)V", 0x01A4C6u, 0x01A051u, 0x027148u },
    /* [83] */ { "jni_YGNodeStyleSetMaxWidthPercentJNI", "(JF)V", 0x019282u, 0x01A051u, 0x027150u },
    /* [84] */ { "jni_YGNodeStyleGetMaxHeightJNI", "(J)J", 0x01A57Fu, 0x01AA10u, 0x027158u },
    /* [85] */ { "jni_YGNodeStyleSetMaxHeightJNI", "(JF)V", 0x019E17u, 0x01A051u, 0x027160u },
    /* [86] */ { "jni_YGNodeStyleSetMaxHeightPercentJNI", "(JF)V", 0x01A0FBu, 0x01A051u, 0x027168u },
    /* [87] */ { "jni_YGNodeStyleGetAspectRatioJNI", "(J)F", 0x0192A7u, 0x01A07Eu, 0x027170u },
    /* [88] */ { "jni_YGNodeStyleSetAspectRatioJNI", "(JF)V", 0x019394u, 0x01A051u, 0x027178u },
    /* [89] */ { "jni_YGNodeSetHasMeasureFuncJNI", "(JZ)V", 0x01A672u, 0x01AAA8u, 0x027180u },
    /* [90] */ { "jni_YGNodeStyleGetGapJNI", "(JI)F", 0x019F5Cu, 0x019DF3u, 0x027198u },
    /* [91] */ { "jni_YGNodeStyleSetGapJNI", "(JIF)V", 0x018C1Fu, 0x01A4BFu, 0x0271A4u },
    /* [92] */ { "jni_YGNodeSetHasBaselineFuncJNI", "(JZ)V", 0x018D8Au, 0x01AAA8u, 0x0271B0u },
    /* [93] */ { "jni_YGNodePrintJNI", "(J)V", 0x0192C8u, 0x019222u, 0x0271D4u },
    /* [94] */ { "jni_YGNodeCloneJNI", "(J)J", 0x018F15u, 0x01AA10u, 0x0271D8u },
};

} // namespace tt_ugen_layout
} // namespace opencut
} // namespace nextai
