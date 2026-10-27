// ============================================================================
// File: tt_ugen_layout_yoga_core.h
// Target: libtt_ugen_layout.so (360,968 bytes)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Declarations for the Facebook Yoga Flexbox Layout Engine C/C++17 API
//     (0x025e10..0x033b48): math/float helpers, enum-to-string tables, YGConfig,
//     YGStyle, YGLayout, YGNode, YGRoundValueToPixelGrid, and Flexbox solver
//     (YGLayoutNodeInternal & YGNodeCalculateLayoutWithContext).
// VN: Khai báo cho C/C++17 API của Engine Bố cục Flexbox Facebook Yoga
//     (0x025e10..0x033b48): các hàm toán học/float, bảng chuyển enum sang chuỗi,
//     YGConfig, YGStyle, YGLayout, YGNode, YGRoundValueToPixelGrid và bộ giải Flexbox.
// ============================================================================

#pragma once

#include "tt_ugen_layout_types.h"
#include "tt_ugen_layout_rodata_tables.h"
#include <cstdint>
#include <cstddef>

// EN: C++ mangled Yoga math and comparison functions at 0x025e10..0x026018.
// VN: Các hàm toán học và so sánh Yoga mangled C++ tại 0x025e10..0x026018.
YGFlexDirection YGFlexDirectionCross(YGFlexDirection flexDirection, YGDirection direction) noexcept;
float           YGFloatMax(float a, float b) noexcept;
float           YGFloatMin(float a, float b) noexcept;
bool            YGValueEqual(const YGValue& a, const YGValue& b) noexcept;
bool            YGFloatsEqual(float a, float b) noexcept;
bool            YGDoubleEqual(double a, double b) noexcept;
float           YGFloatSanitize(float val) noexcept;
YGFloatOptional YGFloatOptionalMax(YGFloatOptional op1, YGFloatOptional op2) noexcept;

namespace facebook {
namespace yoga {
void throwLogicalErrorWithMessage(const char* message);
bool configUpdateInvalidatesLayout(YGConfig* oldConfig, YGConfig* newConfig) noexcept;
const char* LayoutPassReasonToString(LayoutPassReason reason) noexcept;
} // namespace yoga
} // namespace facebook

extern "C" {

// EN: 18 Enum-to-String functions at 0x026360..0x02664f.
// VN: 18 hàm chuyển đổi Enum sang chuỗi tại 0x026360..0x02664f.
const char* YGAlignToString(YGAlign value) noexcept;
const char* YGDimensionToString(YGDimension value) noexcept;
const char* YGDirectionToString(YGDirection value) noexcept;
const char* YGDisplayToString(YGDisplay value) noexcept;
const char* YGEdgeToString(YGEdge value) noexcept;
const char* YGErrataToString(YGErrata value) noexcept;
const char* YGExperimentalFeatureToString(YGExperimentalFeature value) noexcept;
const char* YGFlexDirectionToString(YGFlexDirection value) noexcept;
const char* YGGutterToString(YGGutter value) noexcept;
const char* YGJustifyToString(YGJustify value) noexcept;
const char* YGLogLevelToString(YGLogLevel value) noexcept;
const char* YGMeasureModeToString(YGMeasureMode value) noexcept;
const char* YGNodeTypeToString(YGNodeType value) noexcept;
const char* YGOverflowToString(YGOverflow value) noexcept;
const char* YGPositionTypeToString(YGPositionType value) noexcept;
const char* YGPrintOptionsToString(YGPrintOptions value) noexcept;
const char* YGUnitToString(YGUnit value) noexcept;
const char* YGWrapToString(YGWrap value) noexcept;

// EN: YGConfig lifecycle & property C API (0x02c150..0x02c720 & 0x032ebc..0x033b44).
// VN: C API vòng đời & thuộc tính của YGConfig (0x02c150..0x02c720 & 0x032ebc..0x033b44).
YGConfig* YGConfigGetDefault() noexcept;
YGConfig* YGConfigNew() noexcept;
void      YGConfigFree(YGConfig* config) noexcept;
void      YGConfigCopy(YGConfig* dest, YGConfig* src) noexcept;
int32_t   YGConfigGetInstanceCount() noexcept;
void      YGConfigSetPointScaleFactor(YGConfig* config, float pixelsInPoint) noexcept;
float     YGConfigGetPointScaleFactor(YGConfig* config) noexcept;
void      YGConfigSetUseWebDefaults(YGConfig* config, bool enabled) noexcept;
bool      YGConfigGetUseWebDefaults(YGConfig* config) noexcept;
void      YGConfigSetExperimentalFeatureEnabled(YGConfig* config, YGExperimentalFeature feature, bool enabled) noexcept;
bool      YGConfigIsExperimentalFeatureEnabled(YGConfig* config, YGExperimentalFeature feature) noexcept;
void      YGConfigSetErrata(YGConfig* config, YGErrata errata) noexcept;
YGErrata  YGConfigGetErrata(YGConfig* config) noexcept;
void      YGConfigSetContext(YGConfig* config, void* context) noexcept;
void*     YGConfigGetContext(YGConfig* config) noexcept;

// EN: YGNode lifecycle, tree hierarchy, style & layout C API (0x02c008..0x033ae8).
// VN: C API vòng đời, cây phân cấp, style & bố cục của YGNode (0x02c008..0x033ae8).
YGNode*  YGNodeNew() noexcept;
YGNode*  YGNodeNewWithConfig(YGConfig* config) noexcept;
YGNode*  YGNodeClone(YGNode* node) noexcept;
void     YGNodeFree(YGNode* node) noexcept;
void     YGNodeFreeRecursive(YGNode* root) noexcept;
void     YGNodeReset(YGNode* node) noexcept;
void     YGNodeInsertChild(YGNode* node, YGNode* child, uint32_t index) noexcept;
void     YGNodeRemoveChild(YGNode* node, YGNode* child) noexcept;
void     YGNodeRemoveAllChildren(YGNode* node) noexcept;
YGNode*  YGNodeGetChild(YGNode* node, uint32_t index) noexcept;
uint32_t YGNodeGetChildCount(YGNode* node) noexcept;
YGNode*  YGNodeGetOwner(YGNode* node) noexcept;
YGNode*  YGNodeGetParent(YGNode* node) noexcept;
void     YGNodeMarkDirty(YGNode* node) noexcept;
void     YGNodeMarkDirtyAndPropagateToDescendants(YGNode* node) noexcept;

void     YGNodeStyleSetWidth(YGNode* node, float width) noexcept;
void     YGNodeStyleSetWidthPercent(YGNode* node, float width) noexcept;
void     YGNodeStyleSetWidthAuto(YGNode* node) noexcept;
YGValue  YGNodeStyleGetWidth(YGNode* node) noexcept;
void     YGNodeStyleSetHeight(YGNode* node, float height) noexcept;
void     YGNodeStyleSetHeightPercent(YGNode* node, float height) noexcept;
void     YGNodeStyleSetHeightAuto(YGNode* node) noexcept;
YGValue  YGNodeStyleGetHeight(YGNode* node) noexcept;
void     YGNodeStyleSetFlexGrow(YGNode* node, float flexGrow) noexcept;
float    YGNodeStyleGetFlexGrow(YGNode* node) noexcept;
void     YGNodeStyleSetFlexShrink(YGNode* node, float flexShrink) noexcept;
float    YGNodeStyleGetFlexShrink(YGNode* node) noexcept;

float    YGNodeLayoutGetLeft(YGNode* node) noexcept;
float    YGNodeLayoutGetTop(YGNode* node) noexcept;
float    YGNodeLayoutGetRight(YGNode* node) noexcept;
float    YGNodeLayoutGetBottom(YGNode* node) noexcept;
float    YGNodeLayoutGetWidth(YGNode* node) noexcept;
float    YGNodeLayoutGetHeight(YGNode* node) noexcept;
YGDirection YGNodeLayoutGetDirection(YGNode* node) noexcept;
bool     YGNodeLayoutGetHadOverflow(YGNode* node) noexcept;

// EN: Pixel grid rounding (0x02e7c0) and Flexbox layout solver (0x032f2c & 0x033ae4).
// VN: Làm tròn lưới điểm ảnh (0x02e7c0) và bộ giải bố cục Flexbox (0x032f2c & 0x033ae4).
float    YGRoundValueToPixelGrid(double value, double pointScaleFactor, bool forceCeil, bool forceFloor) noexcept;
bool     YGNodeCanUseCachedMeasurement(
    YGMeasureMode widthMode, float availableWidth,
    YGMeasureMode heightMode, float availableHeight,
    YGMeasureMode lastWidthMode, float lastAvailableWidth,
    YGMeasureMode lastHeightMode, float lastAvailableHeight,
    float lastComputedWidth, float lastComputedHeight,
    float marginRow, float marginColumn, YGConfig* config) noexcept;
void     YGNodeCalculateLayoutWithContext(
    YGNode* node, float availableWidth, float availableHeight,
    YGDirection ownerDirection, void* layoutContext) noexcept;
void     YGNodeCalculateLayout(
    YGNode* node, float availableWidth, float availableHeight,
    YGDirection ownerDirection) noexcept;

} // extern "C"
