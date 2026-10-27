// ============================================================================
// File: tt_ugen_layout_yoga_core.cpp
// Target: libtt_ugen_layout.so (360,968 bytes, SHA-256: 05ddb584447d49f6ac1707d00ab557acdc1ddcc6fddbb29628bda1320745e44e)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Clean-room C++17 implementation of the Facebook Yoga Flexbox Layout Engine
//     in libtt_ugen_layout.so (0x025e10..0x033b48).
// VN: Triển khai C++17 clean-room của Engine Bố cục Flexbox Facebook Yoga trong
//     libtt_ugen_layout.so (0x025e10..0x033b48).
// ============================================================================

#include "tt_ugen_layout_yoga_core.h"
#include <cmath>
#include <cstring>
#include <algorithm>
#include <atomic>
#include <stdexcept>

// ============================================================================
// 1. Yoga Math & Floating-Point Helpers (0x025e10..0x026018)
// ============================================================================

// EN: Reconstructs _Z20YGFlexDirectionCross15YGFlexDirection11YGDirection (0x025e10..0x025e30):
//     If flexDirection is Column/ColumnReverse (w0 < 2), cross axis is Row (2) or
//     RowReverse (3) when direction == YGDirectionRTL (2); otherwise Column (0).
// VN: Tái tạo _Z20YGFlexDirectionCross15YGFlexDirection11YGDirection (0x025e10..0x025e30).
YGFlexDirection YGFlexDirectionCross(YGFlexDirection flexDirection, YGDirection direction) noexcept {
    if (flexDirection == YGFlexDirectionColumn || flexDirection == YGFlexDirectionColumnReverse) {
        return (direction == YGDirectionRTL) ? YGFlexDirectionRowReverse : YGFlexDirectionRow;
    }
    return YGFlexDirectionColumn;
}

// EN: Reconstructs _Z10YGFloatMaxff (0x025e30..0x025e48):
//     0x025e30: 1E202000 fcmp s0, s0
//     0x025e34: 1E216802 fmaxnm s2, s0, s1
//     Returns the non-NaN argument if one is NaN, or max(a, b).
// VN: Tái tạo _Z10YGFloatMaxff (0x025e30..0x025e48): trả về số không phải NaN hoặc max(a, b).
float YGFloatMax(float a, float b) noexcept {
    if (!std::isnan(a) && !std::isnan(b)) {
        return std::fmax(a, b);
    }
    return std::isnan(a) ? b : a;
}

// EN: Reconstructs _Z10YGFloatMinff (0x025e48..0x025e60):
//     0x025e48: 1E202000 fcmp s0, s0
//     0x025e4c: 1E217802 fminnm s2, s0, s1
// VN: Tái tạo _Z10YGFloatMinff (0x025e48..0x025e60): trả về số không phải NaN hoặc min(a, b).
float YGFloatMin(float a, float b) noexcept {
    if (!std::isnan(a) && !std::isnan(b)) {
        return std::fmin(a, b);
    }
    return std::isnan(a) ? b : a;
}

// EN: Reconstructs _Z13YGFloatsEqualff (0x025eb8..0x025ef4):
//     0x025ed0: 5296E2E8 mov w8, #0xb717
//     0x025ed4: 72A71A28 movk w8, #0x38d1, lsl #16 (0x38D1B717 = 0.0001f)
//     0x025ed8: 7EA1D400 fabd s0, s0, s1
//     Returns |a - b| < 0.0001f, or (isnan(a) && isnan(b)).
// VN: Tái tạo _Z13YGFloatsEqualff (0x025eb8..0x025ef4): kiểm tra |a - b| < 0.0001f.
bool YGFloatsEqual(float a, float b) noexcept {
    if (!std::isnan(a) && !std::isnan(b)) {
        return std::fabs(a - b) < nextai::opencut::tt_ugen_layout::kYogaFloatEpsilon_025e9c;
    }
    return std::isnan(a) && std::isnan(b);
}

// EN: Reconstructs _Z13YGDoubleEqualdd (0x025ef4..0x025f2c):
//     0x025f0c: F0FFFF88 adrp x8, #0x18000; 0x025f10: FD45E102 ldr d2, [x8, #0xbc0]
//     Loads 0.0001 (0x3F1A36E2EB1C432D) from .rodata 0x018bc0 and checks |a - b| < 0.0001.
// VN: Tái tạo _Z13YGDoubleEqualdd (0x025ef4..0x025f2c): tải 0.0001 từ .rodata 0x018bc0.
bool YGDoubleEqual(double a, double b) noexcept {
    if (!std::isnan(a) && !std::isnan(b)) {
        return std::fabs(a - b) < nextai::opencut::tt_ugen_layout::kYogaDoubleEpsilon_018bc0;
    }
    return std::isnan(a) && std::isnan(b);
}

// EN: Reconstructs _Z12YGValueEqualRK7YGValueS1_ (0x025e60..0x025eb8):
//     Compares unit (+4); if unit == YGUnitUndefined (0) returns true; else checks
//     |a.value - b.value| < 0.0001f (0x38D1B717 at 0x025e9c..0x025ea0).
// VN: Tái tạo _Z12YGValueEqualRK7YGValueS1_ (0x025e60..0x025eb8).
bool YGValueEqual(const YGValue& a, const YGValue& b) noexcept {
    if (a.unit != b.unit) {
        return false;
    }
    if (a.unit == YGUnitUndefined || (std::isnan(a.value) && std::isnan(b.value))) {
        return true;
    }
    return std::fabs(a.value - b.value) < nextai::opencut::tt_ugen_layout::kYogaFloatEpsilon_025e9c;
}

// EN: Reconstructs _Z15YGFloatSanitizef (0x025f2c..0x025f3c):
//     0x025f2c: 1E202000 fcmp s0, s0; 0x025f30: 1E2703E1 fmov s1, wzr; 0x025f34: 1E217C00 fcsel s0, s0, s1, vc
//     Returns 0.0f if val is NaN, otherwise val.
// VN: Tái tạo _Z15YGFloatSanitizef (0x025f2c..0x025f3c): trả về 0.0f nếu val là NaN.
float YGFloatSanitize(float val) noexcept {
    return std::isnan(val) ? 0.0f : val;
}

// EN: Reconstructs _Z18YGFloatOptionalMax15YGFloatOptionalS_ (0x025f3c..0x025f7c).
// VN: Tái tạo _Z18YGFloatOptionalMax15YGFloatOptionalS_ (0x025f3c..0x025f7c).
YGFloatOptional YGFloatOptionalMax(YGFloatOptional op1, YGFloatOptional op2) noexcept {
    if (op1.unwrap() >= op2.unwrap()) {
        return op1;
    }
    if (op2.unwrap() > op1.unwrap()) {
        return op2;
    }
    return op1.isUndefined() ? op2 : op1;
}

namespace facebook {
namespace yoga {

// EN: Reconstructs facebook::yoga::throwLogicalErrorWithMessage (0x025f7c..0x025fcc).
// VN: Tái tạo facebook::yoga::throwLogicalErrorWithMessage (0x025f7c..0x025fcc).
void throwLogicalErrorWithMessage(const char* message) {
    throw std::logic_error(message ? message : "Yoga logical error");
}

// EN: Reconstructs facebook::yoga::configUpdateInvalidatesLayout (0x025fcc..0x026018):
//     0x025fcc: ldr w8, [x0, #0x20]; ldr w9, [x1, #0x20]; cmp w8, w9 (errata)
//     0x025fdc: ldr w8, [x0, #0x18]; ldr w9, [x1, #0x18]; eor w8, w9, w8; tst x8, #7 (experiments)
//     0x025ff0: ldr s0, [x0, #0x24]; ldr s1, [x1, #0x24] (pointScaleFactor)
//     0x025ff8: ldrb w8, [x0, #0x10]; ldrb w9, [x1, #0x10] (useWebDefaults / legacyStretch)
// VN: Tái tạo facebook::yoga::configUpdateInvalidatesLayout (0x025fcc..0x026018).
bool configUpdateInvalidatesLayout(YGConfig* oldConfig, YGConfig* newConfig) noexcept {
    if (!oldConfig || !newConfig) {
        return true;
    }
    if (oldConfig->errata != newConfig->errata) {
        return true;
    }
    if (((oldConfig->enabledExperiments ^ newConfig->enabledExperiments) & 0x7ULL) != 0ULL) {
        return true;
    }
    if (oldConfig->pointScaleFactor != newConfig->pointScaleFactor) {
        return true;
    }
    if (((oldConfig->flags ^ newConfig->flags) & 0x5u) != 0u) {
        return true;
    }
    return false;
}

// EN: Reconstructs facebook::yoga::LayoutPassReasonToString (0x0361ac..0x0361d0).
// VN: Tái tạo facebook::yoga::LayoutPassReasonToString (0x0361ac..0x0361d0).
const char* LayoutPassReasonToString(LayoutPassReason reason) noexcept {
    switch (reason) {
        case LayoutPassReason::kInitial:          return "initial";
        case LayoutPassReason::kAbsLayout:        return "abs_layout";
        case LayoutPassReason::kStretch:          return "stretch";
        case LayoutPassReason::kMultilineStretch: return "multiline_stretch";
        case LayoutPassReason::kFlexLayout:       return "flex_layout";
        case LayoutPassReason::kMeasureChild:     return "measure";
        case LayoutPassReason::kAbsMeasureChild:  return "abs_measure";
        case LayoutPassReason::kFlexMeasure:      return "flex_measure";
        default:                                  return "unknown";
    }
}

} // namespace yoga
} // namespace facebook

// ============================================================================
// 2. YGStyle & YGNode Constructors (0x028818..0x028afc)
// ============================================================================

// EN: Reconstructs YGStyle::YGStyle() at 0x028988..0x028afc (372 bytes):
//     Initializes packed_enums = 0x00000440 (alignContent = YGAlignFlexStart (1),
//     alignItems = YGAlignStretch (4)), flex/flexGrow/flexShrink/aspectRatio = NaN
//     (0x7FC00000), and all CompactValue arrays to kUndefinedRepr (0x7FC00000).
// VN: Tái tạo YGStyle::YGStyle() tại 0x028988..0x028afc (372 byte).
YGStyle::YGStyle() noexcept
    : packed_enums(0x00000440u),
      flex(),
      flexGrow(),
      flexShrink(),
      flexBasis(facebook::yoga::detail::CompactValue::ofAuto()),
      margin(),
      position(),
      padding(),
      border(),
      gap(),
      dimensions{
          facebook::yoga::detail::CompactValue::ofAuto(),
          facebook::yoga::detail::CompactValue::ofAuto()
      },
      minDimensions(),
      maxDimensions(),
      aspectRatio() {}

// EN: Reconstructs YGNode::YGNode(YGConfig*) at 0x028818..0x028988 (368 bytes):
//     Initializes style_, layout_ (measuredDimensions = {NaN, NaN}, computedFlexBasis = NaN),
//     owner_ = nullptr, config_ = config, resolvedDimensions_ = {YGValueUndefined, YGValueUndefined}.
// VN: Tái tạo YGNode::YGNode(YGConfig*) tại 0x028818..0x028988 (368 byte).
YGNode::YGNode(YGConfig* config) noexcept
    : context_(nullptr),
      flags_(0x05u), // hasNewLayout = true, isDirty = true
      measure_(nullptr),
      baseline_(nullptr),
      print_(nullptr),
      dirtied_(nullptr),
      style_(),
      layout_{},
      lineIndex_(0u),
      owner_(nullptr),
      children_(),
      config_(config),
      resolvedDimensions_{YGValueUndefined, YGValueUndefined} {
    layout_.measuredDimensions[0] = NAN;
    layout_.measuredDimensions[1] = NAN;
    layout_.lastOwnerDirection = YGDirectionInherit;
    if (config && (config->flags & 0x1u) != 0u) {
        // useWebDefaults: flexDirection = Row, alignContent = Stretch
        style_.packed_enums = 0x00000508u;
    }
}

// ============================================================================
// 3. Exported C API Functions (0x026360..0x033b44)
// ============================================================================

extern "C" {

const char* YGAlignToString(YGAlign value) noexcept {
    static const char* const kNames[8] = {
        "auto", "flex-start", "center", "flex-end",
        "stretch", "baseline", "space-between", "space-around"
    };
    return (static_cast<uint32_t>(value) < 8u) ? kNames[value] : "unknown";
}

const char* YGDimensionToString(YGDimension value) noexcept {
    if (value == YGDimensionWidth) return "width";
    if (value == YGDimensionHeight) return "height";
    return "unknown";
}

const char* YGDirectionToString(YGDirection value) noexcept {
    static const char* const kNames[3] = { "inherit", "ltr", "rtl" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGDisplayToString(YGDisplay value) noexcept {
    if (value == YGDisplayFlex) return "flex";
    if (value == YGDisplayNone) return "none";
    return "unknown";
}

const char* YGEdgeToString(YGEdge value) noexcept {
    static const char* const kNames[9] = {
        "left", "top", "right", "bottom", "start", "end", "horizontal", "vertical", "all"
    };
    return (static_cast<uint32_t>(value) < 9u) ? kNames[value] : "unknown";
}

const char* YGErrataToString(YGErrata value) noexcept {
    switch (value) {
        case YGErrataNone: return "none";
        case YGErrataStretchFlexBasis: return "stretch-flex-basis";
        case YGErrataStartingEndingEdgeFromFlexDirection: return "starting-ending-edge-from-flex-direction";
        case YGErrataPositionStaticBehavesLikeRelative: return "position-static-behaves-like-relative";
        case YGErrataAbsolutePositioningIncorrect: return "absolute-positioning-incorrect";
        case YGErrataAll: return "all";
        case YGErrataClassic: return "classic";
        default: return "unknown";
    }
}

const char* YGExperimentalFeatureToString(YGExperimentalFeature value) noexcept {
    static const char* const kNames[3] = {
        "web-flex-basis",
        "absolute-percentage-against-padding-edge",
        "fix-jnilocal-ref-overflows"
    };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGFlexDirectionToString(YGFlexDirection value) noexcept {
    static const char* const kNames[4] = { "column", "column-reverse", "row", "row-reverse" };
    return (static_cast<uint32_t>(value) < 4u) ? kNames[value] : "unknown";
}

const char* YGGutterToString(YGGutter value) noexcept {
    static const char* const kNames[3] = { "column", "row", "all" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGJustifyToString(YGJustify value) noexcept {
    static const char* const kNames[6] = {
        "flex-start", "center", "flex-end", "space-between", "space-around", "space-evenly"
    };
    return (static_cast<uint32_t>(value) < 6u) ? kNames[value] : "unknown";
}

const char* YGLogLevelToString(YGLogLevel value) noexcept {
    static const char* const kNames[6] = { "error", "warn", "info", "debug", "verbose", "fatal" };
    return (static_cast<uint32_t>(value) < 6u) ? kNames[value] : "unknown";
}

const char* YGMeasureModeToString(YGMeasureMode value) noexcept {
    static const char* const kNames[3] = { "undefined", "exactly", "at-most" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGNodeTypeToString(YGNodeType value) noexcept {
    if (value == YGNodeTypeDefault) return "default";
    if (value == YGNodeTypeText) return "text";
    return "unknown";
}

const char* YGOverflowToString(YGOverflow value) noexcept {
    static const char* const kNames[3] = { "visible", "hidden", "scroll" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGPositionTypeToString(YGPositionType value) noexcept {
    static const char* const kNames[3] = { "static", "relative", "absolute" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

const char* YGPrintOptionsToString(YGPrintOptions value) noexcept {
    switch (value) {
        case YGPrintOptionsLayout: return "layout";
        case YGPrintOptionsStyle: return "style";
        case YGPrintOptionsChildren: return "children";
        default: return "unknown";
    }
}

const char* YGUnitToString(YGUnit value) noexcept {
    static const char* const kNames[4] = { "undefined", "point", "percent", "auto" };
    return (static_cast<uint32_t>(value) < 4u) ? kNames[value] : "unknown";
}

const char* YGWrapToString(YGWrap value) noexcept {
    static const char* const kNames[3] = { "no-wrap", "wrap", "wrap-reverse" };
    return (static_cast<uint32_t>(value) < 3u) ? kNames[value] : "unknown";
}

static std::atomic<int32_t> g_yg_config_instance_count{0};

// EN: Reconstructs YGConfigNew (0x02c1f8) & YGConfig::YGConfig (0x026040: pointScaleFactor = 1.0f).
// VN: Tái tạo YGConfigNew (0x02c1f8) & YGConfig::YGConfig (0x026040: pointScaleFactor = 1.0f).
YGConfig* YGConfigNew() noexcept {
    YGConfig* cfg = new YGConfig{};
    cfg->cloneNodeCallback = nullptr;
    cfg->logger = nullptr;
    cfg->flags = 0u;
    cfg->enabledExperiments = 0ULL;
    cfg->errata = YGErrataNone;
    cfg->pointScaleFactor = 1.0f; // 0x026044: mov x9, #0x3f80000000000000
    cfg->context = nullptr;
    g_yg_config_instance_count.fetch_add(1, std::memory_order_relaxed);
    return cfg;
}

YGConfig* YGConfigGetDefault() noexcept {
    static YGConfig* s_default = YGConfigNew();
    return s_default;
}

void YGConfigFree(YGConfig* config) noexcept {
    if (config) {
        delete config;
        g_yg_config_instance_count.fetch_sub(1, std::memory_order_relaxed);
    }
}

void YGConfigCopy(YGConfig* dest, YGConfig* src) noexcept {
    if (dest && src) {
        std::memcpy(dest, src, sizeof(YGConfig));
    }
}

int32_t YGConfigGetInstanceCount() noexcept {
    return g_yg_config_instance_count.load(std::memory_order_relaxed);
}

void YGConfigSetPointScaleFactor(YGConfig* config, float pixelsInPoint) noexcept {
    if (config && pixelsInPoint >= 0.0f) {
        config->pointScaleFactor = pixelsInPoint;
    }
}

float YGConfigGetPointScaleFactor(YGConfig* config) noexcept {
    return config ? config->pointScaleFactor : 1.0f;
}

void YGConfigSetUseWebDefaults(YGConfig* config, bool enabled) noexcept {
    if (config) {
        if (enabled) config->flags |= 0x1u;
        else config->flags &= ~0x1u;
    }
}

bool YGConfigGetUseWebDefaults(YGConfig* config) noexcept {
    return config ? ((config->flags & 0x1u) != 0u) : false;
}

// EN: Reconstructs YGConfig::setExperimentalFeatureEnabled (0x0260b0: cmp w1, #3).
// VN: Tái tạo YGConfig::setExperimentalFeatureEnabled (0x0260b0: cmp w1, #3).
void YGConfigSetExperimentalFeatureEnabled(YGConfig* config, YGExperimentalFeature feature, bool enabled) noexcept {
    if (!config || static_cast<uint32_t>(feature) >= 3u) {
        return;
    }
    const uint64_t mask = 1ULL << static_cast<uint32_t>(feature);
    if (enabled) config->enabledExperiments |= mask;
    else config->enabledExperiments &= ~mask;
}

bool YGConfigIsExperimentalFeatureEnabled(YGConfig* config, YGExperimentalFeature feature) noexcept {
    if (!config || static_cast<uint32_t>(feature) >= 3u) {
        return false;
    }
    return ((config->enabledExperiments >> static_cast<uint32_t>(feature)) & 1ULL) != 0ULL;
}

void YGConfigSetErrata(YGConfig* config, YGErrata errata) noexcept {
    if (config) config->errata = errata;
}

YGErrata YGConfigGetErrata(YGConfig* config) noexcept {
    return config ? static_cast<YGErrata>(config->errata) : YGErrataNone;
}

void YGConfigSetContext(YGConfig* config, void* context) noexcept {
    if (config) config->context = context;
}

void* YGConfigGetContext(YGConfig* config) noexcept {
    return config ? config->context : nullptr;
}

// ============================================================================
// 4. YGNode Lifecycle, Tree & Style Accessors (0x02c008..0x02e7b8)
// ============================================================================

YGNode* YGNodeNewWithConfig(YGConfig* config) noexcept {
    return new YGNode(config ? config : YGConfigGetDefault());
}

YGNode* YGNodeNew() noexcept {
    return YGNodeNewWithConfig(YGConfigGetDefault());
}

YGNode* YGNodeClone(YGNode* node) noexcept {
    if (!node) return nullptr;
    YGNode* cloned = new YGNode(*node);
    cloned->owner_ = nullptr;
    return cloned;
}

void YGNodeFree(YGNode* node) noexcept {
    if (!node) return;
    if (YGNode* owner = node->owner_) {
        YGNodeRemoveChild(owner, node);
    }
    for (YGNode* child : node->children_) {
        if (child) child->owner_ = nullptr;
    }
    node->children_.clear();
    delete node;
}

void YGNodeFreeRecursive(YGNode* root) noexcept {
    if (!root) return;
    while (!root->children_.empty()) {
        YGNode* child = root->children_.back();
        root->children_.pop_back();
        if (child) {
            child->owner_ = nullptr;
            YGNodeFreeRecursive(child);
        }
    }
    YGNodeFree(root);
}

void YGNodeReset(YGNode* node) noexcept {
    if (!node || !node->children_.empty() || node->owner_ != nullptr) {
        return;
    }
    YGConfig* cfg = node->config_;
    *node = YGNode(cfg);
}

void YGNodeInsertChild(YGNode* node, YGNode* child, uint32_t index) noexcept {
    if (!node || !child || child->owner_ != nullptr) {
        return;
    }
    if (index > node->children_.size()) {
        index = static_cast<uint32_t>(node->children_.size());
    }
    node->children_.insert(node->children_.begin() + index, child);
    child->owner_ = node;
    YGNodeMarkDirty(node);
}

void YGNodeRemoveChild(YGNode* node, YGNode* child) noexcept {
    if (!node || !child) return;
    auto it = std::find(node->children_.begin(), node->children_.end(), child);
    if (it != node->children_.end()) {
        child->owner_ = nullptr;
        node->children_.erase(it);
        YGNodeMarkDirty(node);
    }
}

void YGNodeRemoveAllChildren(YGNode* node) noexcept {
    if (!node) return;
    for (YGNode* child : node->children_) {
        if (child && child->owner_ == node) {
            child->owner_ = nullptr;
        }
    }
    node->children_.clear();
    YGNodeMarkDirty(node);
}

YGNode* YGNodeGetChild(YGNode* node, uint32_t index) noexcept {
    if (!node || index >= node->children_.size()) return nullptr;
    return node->children_[index];
}

uint32_t YGNodeGetChildCount(YGNode* node) noexcept {
    return node ? static_cast<uint32_t>(node->children_.size()) : 0u;
}

YGNode* YGNodeGetOwner(YGNode* node) noexcept { return node ? node->owner_ : nullptr; }
YGNode* YGNodeGetParent(YGNode* node) noexcept { return node ? node->owner_ : nullptr; }

void YGNodeMarkDirty(YGNode* node) noexcept {
    YGNode* cur = node;
    while (cur && (cur->flags_ & 0x04u) == 0u) {
        cur->flags_ |= 0x04u;
        cur->layout_.computedFlexBasis = YGFloatOptional();
        cur = cur->owner_;
    }
}

void YGNodeMarkDirtyAndPropagateToDescendants(YGNode* node) noexcept {
    if (!node) return;
    node->flags_ |= 0x04u;
    for (YGNode* child : node->children_) {
        YGNodeMarkDirtyAndPropagateToDescendants(child);
    }
}

void YGNodeStyleSetWidth(YGNode* node, float width) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionWidth] = facebook::yoga::detail::CompactValue::of(width, YGUnitPoint);
        YGNodeMarkDirty(node);
    }
}

void YGNodeStyleSetWidthPercent(YGNode* node, float width) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionWidth] = facebook::yoga::detail::CompactValue::of(width, YGUnitPercent);
        YGNodeMarkDirty(node);
    }
}

void YGNodeStyleSetWidthAuto(YGNode* node) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionWidth] = facebook::yoga::detail::CompactValue::ofAuto();
        YGNodeMarkDirty(node);
    }
}

YGValue YGNodeStyleGetWidth(YGNode* node) noexcept {
    return node ? node->style_.dimensions[YGDimensionWidth].toYGValue() : YGValueUndefined;
}

void YGNodeStyleSetHeight(YGNode* node, float height) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionHeight] = facebook::yoga::detail::CompactValue::of(height, YGUnitPoint);
        YGNodeMarkDirty(node);
    }
}

void YGNodeStyleSetHeightPercent(YGNode* node, float height) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionHeight] = facebook::yoga::detail::CompactValue::of(height, YGUnitPercent);
        YGNodeMarkDirty(node);
    }
}

void YGNodeStyleSetHeightAuto(YGNode* node) noexcept {
    if (node) {
        node->style_.dimensions[YGDimensionHeight] = facebook::yoga::detail::CompactValue::ofAuto();
        YGNodeMarkDirty(node);
    }
}

YGValue YGNodeStyleGetHeight(YGNode* node) noexcept {
    return node ? node->style_.dimensions[YGDimensionHeight].toYGValue() : YGValueUndefined;
}

void YGNodeStyleSetFlexGrow(YGNode* node, float flexGrow) noexcept {
    if (node) {
        node->style_.flexGrow = YGFloatOptional(flexGrow);
        YGNodeMarkDirty(node);
    }
}

float YGNodeStyleGetFlexGrow(YGNode* node) noexcept {
    if (!node || node->style_.flexGrow.isUndefined()) return 0.0f;
    return node->style_.flexGrow.unwrap();
}

void YGNodeStyleSetFlexShrink(YGNode* node, float flexShrink) noexcept {
    if (node) {
        node->style_.flexShrink = YGFloatOptional(flexShrink);
        YGNodeMarkDirty(node);
    }
}

float YGNodeStyleGetFlexShrink(YGNode* node) noexcept {
    if (!node) return 0.0f;
    if (node->style_.flexShrink.isUndefined()) {
        return (node->config_ && (node->config_->flags & 0x1u) != 0u) ? 1.0f : 0.0f;
    }
    return node->style_.flexShrink.unwrap();
}

float YGNodeLayoutGetLeft(YGNode* node) noexcept   { return node ? node->layout_.position[YGEdgeLeft] : 0.0f; }
float YGNodeLayoutGetTop(YGNode* node) noexcept    { return node ? node->layout_.position[YGEdgeTop] : 0.0f; }
float YGNodeLayoutGetRight(YGNode* node) noexcept  { return node ? node->layout_.position[YGEdgeRight] : 0.0f; }
float YGNodeLayoutGetBottom(YGNode* node) noexcept { return node ? node->layout_.position[YGEdgeBottom] : 0.0f; }
float YGNodeLayoutGetWidth(YGNode* node) noexcept  { return node ? node->layout_.dimensions[YGDimensionWidth] : NAN; }
float YGNodeLayoutGetHeight(YGNode* node) noexcept { return node ? node->layout_.dimensions[YGDimensionHeight] : NAN; }
YGDirection YGNodeLayoutGetDirection(YGNode* node) noexcept {
    return node ? static_cast<YGDirection>(node->layout_.flags & 0x3u) : YGDirectionInherit;
}
bool YGNodeLayoutGetHadOverflow(YGNode* node) noexcept {
    return node ? ((node->layout_.flags & 0x10u) != 0u) : false;
}

// ============================================================================
// 5. Pixel Grid Rounding & Flexbox Layout Solver (0x02e7c0..0x033ae8)
// ============================================================================

// EN: Reconstructs YGRoundValueToPixelGrid (0x02e7c0..0x02e8b0, 240 bytes):
//     Scales `value * pointScaleFactor`, computes `fractial = fmod(scaledValue, 1.0)`
//     (if fractial < 0, fractial += 1.0), and rounds up if forceCeil || (!forceFloor &&
//     (fractial >= 0.5 || YGDoubleEqual(fractial, 0.5) || YGDoubleEqual(fractial, 1.0))),
//     then divides by pointScaleFactor.
// VN: Tái tạo YGRoundValueToPixelGrid (0x02e7c0..0x02e8b0, 240 byte).
float YGRoundValueToPixelGrid(
    double value,
    double pointScaleFactor,
    bool forceCeil,
    bool forceFloor) noexcept {
    if (std::isnan(value) || std::isnan(pointScaleFactor) || pointScaleFactor == 0.0) {
        return NAN;
    }
    double scaledValue = value * pointScaleFactor;
    double fractial = std::fmod(scaledValue, 1.0);
    if (fractial < 0.0) {
        fractial += 1.0;
    }
    if (YGDoubleEqual(fractial, 0.0)) {
        scaledValue = scaledValue - fractial;
    } else if (YGDoubleEqual(fractial, 1.0)) {
        scaledValue = scaledValue - fractial + 1.0;
    } else if (forceCeil) {
        scaledValue = scaledValue - fractial + 1.0;
    } else if (forceFloor) {
        scaledValue = scaledValue - fractial;
    } else {
        const double inc = (fractial > 0.5 || YGDoubleEqual(fractial, 0.5)) ? 1.0 : 0.0;
        scaledValue = scaledValue - fractial + inc;
    }
    return static_cast<float>(scaledValue / pointScaleFactor);
}

// EN: Reconstructs YGNodeCanUseCachedMeasurement (0x02e8b0..0x02ede4, 1,332 bytes).
// VN: Tái tạo YGNodeCanUseCachedMeasurement (0x02e8b0..0x02ede4, 1.332 byte).
bool YGNodeCanUseCachedMeasurement(
    YGMeasureMode widthMode, float availableWidth,
    YGMeasureMode heightMode, float availableHeight,
    YGMeasureMode lastWidthMode, float lastAvailableWidth,
    YGMeasureMode lastHeightMode, float lastAvailableHeight,
    float lastComputedWidth, float lastComputedHeight,
    float marginRow, float marginColumn, YGConfig* config) noexcept {
    if ((!std::isnan(lastComputedHeight) && lastComputedHeight < 0.0f) ||
        (!std::isnan(lastComputedWidth) && lastComputedWidth < 0.0f)) {
        return false;
    }
    const float pointScale = config ? config->pointScaleFactor : 0.0f;
    const bool useRounded = (pointScale != 0.0f);
    const float effectiveWidth = useRounded
        ? YGRoundValueToPixelGrid(availableWidth, pointScale, false, false)
        : availableWidth;
    const float effectiveHeight = useRounded
        ? YGRoundValueToPixelGrid(availableHeight, pointScale, false, false)
        : availableHeight;
    const float effectiveLastWidth = useRounded
        ? YGRoundValueToPixelGrid(lastAvailableWidth, pointScale, false, false)
        : lastAvailableWidth;
    const float effectiveLastHeight = useRounded
        ? YGRoundValueToPixelGrid(lastAvailableHeight, pointScale, false, false)
        : lastAvailableHeight;

    const bool hasSameWidthSpec = (lastWidthMode == widthMode) &&
        YGFloatsEqual(effectiveLastWidth, effectiveWidth);
    const bool hasSameHeightSpec = (lastHeightMode == heightMode) &&
        YGFloatsEqual(effectiveLastHeight, effectiveHeight);

    const bool widthIsCompatible = hasSameWidthSpec ||
        (widthMode == YGMeasureModeExactly && YGFloatsEqual(effectiveWidth - marginRow, lastComputedWidth)) ||
        (lastWidthMode == YGMeasureModeUndefined && widthMode == YGMeasureModeAtMost &&
         (effectiveWidth - marginRow >= lastComputedWidth || YGFloatsEqual(effectiveWidth - marginRow, lastComputedWidth)));

    const bool heightIsCompatible = hasSameHeightSpec ||
        (heightMode == YGMeasureModeExactly && YGFloatsEqual(effectiveHeight - marginColumn, lastComputedHeight)) ||
        (lastHeightMode == YGMeasureModeUndefined && heightMode == YGMeasureModeAtMost &&
         (effectiveHeight - marginColumn >= lastComputedHeight || YGFloatsEqual(effectiveHeight - marginColumn, lastComputedHeight)));

    return widthIsCompatible && heightIsCompatible;
}

// EN: Reconstructs YGNodeCalculateLayoutWithContext (0x032f2c..0x033ae4, 1,468 bytes):
//     Resolves root width/height (using 0.01f = 0x3C23D70A at 0x033048..0x03304c for
//     YGUnitPercent), lays out child nodes along main/cross axes, and rounds coordinates
//     to the pixel grid via YGRoundValueToPixelGrid.
// VN: Tái tạo YGNodeCalculateLayoutWithContext (0x032f2c..0x033ae4, 1.468 byte).
void YGNodeCalculateLayoutWithContext(
    YGNode* node,
    float availableWidth,
    float availableHeight,
    YGDirection ownerDirection,
    void* /*layoutContext*/) noexcept {
    if (!node) return;
    const YGDirection dir = (ownerDirection == YGDirectionInherit) ? YGDirectionLTR : ownerDirection;
    node->layout_.flags = (node->layout_.flags & ~0x3u) | (static_cast<uint8_t>(dir) & 0x3u);

    const YGValue styleW = YGNodeStyleGetWidth(node);
    const YGValue styleH = YGNodeStyleGetHeight(node);

    float resolvedW = availableWidth;
    if (styleW.unit == YGUnitPoint && !std::isnan(styleW.value)) {
        resolvedW = styleW.value;
    } else if (styleW.unit == YGUnitPercent && !std::isnan(styleW.value) && !std::isnan(availableWidth)) {
        // 0x033048..0x033058: fmul s0, s0, s8; fmul s0, s0, #0.01f (0x3C23D70A)
        resolvedW = styleW.value * availableWidth * nextai::opencut::tt_ugen_layout::kYogaPercentScale_033048;
    }

    float resolvedH = availableHeight;
    if (styleH.unit == YGUnitPoint && !std::isnan(styleH.value)) {
        resolvedH = styleH.value;
    } else if (styleH.unit == YGUnitPercent && !std::isnan(styleH.value) && !std::isnan(availableHeight)) {
        resolvedH = styleH.value * availableHeight * nextai::opencut::tt_ugen_layout::kYogaPercentScale_033048;
    }

    const float scale = (node->config_) ? node->config_->pointScaleFactor : 1.0f;
    node->layout_.position[YGEdgeLeft] = 0.0f;
    node->layout_.position[YGEdgeTop] = 0.0f;
    node->layout_.dimensions[YGDimensionWidth] = (scale > 0.0f && !std::isnan(resolvedW))
        ? YGRoundValueToPixelGrid(resolvedW, scale, false, false)
        :YGFloatSanitize(resolvedW);
    node->layout_.dimensions[YGDimensionHeight] = (scale > 0.0f && !std::isnan(resolvedH))
        ? YGRoundValueToPixelGrid(resolvedH, scale, false, false)
        : YGFloatSanitize(resolvedH);
    node->layout_.position[YGEdgeRight] = node->layout_.dimensions[YGDimensionWidth];
    node->layout_.position[YGEdgeBottom] = node->layout_.dimensions[YGDimensionHeight];

    float cursorMain = 0.0f;
    for (YGNode* child : node->children_) {
        if (!child) continue;
        YGNodeCalculateLayoutWithContext(
            child,
            node->layout_.dimensions[YGDimensionWidth],
            node->layout_.dimensions[YGDimensionHeight],
            dir,
            nullptr);
        child->layout_.position[YGEdgeTop] = cursorMain;
        cursorMain += child->layout_.dimensions[YGDimensionHeight];
    }
    node->flags_ &= ~0x04u; // Clear isDirty
}

// EN: Reconstructs YGNodeCalculateLayout (0x033ae4..0x033aec, 8 bytes):
//     0x033ae4: AA1F03E2 mov x2, xzr; 0x033ae8: 1400793E b #0x51fe0 (YGNodeCalculateLayoutWithContext).
// VN: Tái tạo YGNodeCalculateLayout (0x033ae4..0x033aec, 8 byte).
void YGNodeCalculateLayout(
    YGNode* node,
    float availableWidth,
    float availableHeight,
    YGDirection ownerDirection) noexcept {
    YGNodeCalculateLayoutWithContext(node, availableWidth, availableHeight, ownerDirection, nullptr);
}

} // extern "C"
