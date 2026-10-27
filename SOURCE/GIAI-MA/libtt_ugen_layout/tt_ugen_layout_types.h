// ============================================================================
// File: tt_ugen_layout_types.h
// Target: libtt_ugen_layout.so (360,968 bytes, SHA-256: 05ddb584447d49f6ac1707d00ab557acdc1ddcc6fddbb29628bda1320745e44e)
// Task ID: TASK-137-RECONSTRUCTION-LIBTT-UGEN-LAYOUT (TASK_SO_036_libtt_ugen_layout)
// EN: Clean-room C++17 ABI types, enums, and structs for ByteDance UGen Flexbox
//     Layout Engine (`facebook::yoga`, `YGNode`, `YGStyle`, `YGLayout`, `YGConfig`,
//     and `facebook::yoga::vanillajni` JNI bridge).
// VN: Các kiểu dữ liệu, enum và struct ABI C++17 clean-room cho Engine Bố cục
//     Flexbox UGen của ByteDance (`facebook::yoga`, `YGNode`, `YGStyle`, `YGLayout`,
//     `YGConfig`, và cầu nối JNI `facebook::yoga::vanillajni`).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <vector>

// EN: Standard Yoga C API enumerations verified from YG*ToString (0x026360..0x02664f).
// VN: Các enum C API chuẩn của Yoga được xác minh từ các hàm YG*ToString (0x026360..0x02664f).
enum YGAlign : int32_t {
    YGAlignAuto = 0,
    YGAlignFlexStart = 1,
    YGAlignCenter = 2,
    YGAlignFlexEnd = 3,
    YGAlignStretch = 4,
    YGAlignBaseline = 5,
    YGAlignSpaceBetween = 6,
    YGAlignSpaceAround = 7
};

enum YGDimension : int32_t {
    YGDimensionWidth = 0,
    YGDimensionHeight = 1
};

enum YGDirection : int32_t {
    YGDirectionInherit = 0,
    YGDirectionLTR = 1,
    YGDirectionRTL = 2
};

enum YGDisplay : int32_t {
    YGDisplayFlex = 0,
    YGDisplayNone = 1
};

enum YGEdge : int32_t {
    YGEdgeLeft = 0,
    YGEdgeTop = 1,
    YGEdgeRight = 2,
    YGEdgeBottom = 3,
    YGEdgeStart = 4,
    YGEdgeEnd = 5,
    YGEdgeHorizontal = 6,
    YGEdgeVertical = 7,
    YGEdgeAll = 8
};

enum YGErrata : uint32_t {
    YGErrataNone = 0,
    YGErrataStretchFlexBasis = 1,
    YGErrataStartingEndingEdgeFromFlexDirection = 2,
    YGErrataPositionStaticBehavesLikeRelative = 4,
    YGErrataAbsolutePositioningIncorrect = 8,
    YGErrataAll = 2147483647u,
    YGErrataClassic = 2147483646u
};

enum YGExperimentalFeature : int32_t {
    YGExperimentalFeatureWebFlexBasis = 0,
    YGExperimentalFeatureAbsolutePercentageAgainstPaddingEdge = 1,
    YGExperimentalFeatureFixJNILocalRefOverflows = 2
};

enum YGFlexDirection : int32_t {
    YGFlexDirectionColumn = 0,
    YGFlexDirectionColumnReverse = 1,
    YGFlexDirectionRow = 2,
    YGFlexDirectionRowReverse = 3
};

enum YGGutter : int32_t {
    YGGutterColumn = 0,
    YGGutterRow = 1,
    YGGutterAll = 2
};

enum YGJustify : int32_t {
    YGJustifyFlexStart = 0,
    YGJustifyCenter = 1,
    YGJustifyFlexEnd = 2,
    YGJustifySpaceBetween = 3,
    YGJustifySpaceAround = 4,
    YGJustifySpaceEvenly = 5
};

enum YGLogLevel : int32_t {
    YGLogLevelError = 0,
    YGLogLevelWarn = 1,
    YGLogLevelInfo = 2,
    YGLogLevelDebug = 3,
    YGLogLevelVerbose = 4,
    YGLogLevelFatal = 5
};

enum YGMeasureMode : int32_t {
    YGMeasureModeUndefined = 0,
    YGMeasureModeExactly = 1,
    YGMeasureModeAtMost = 2
};

enum YGNodeType : int32_t {
    YGNodeTypeDefault = 0,
    YGNodeTypeText = 1
};

enum YGOverflow : int32_t {
    YGOverflowVisible = 0,
    YGOverflowHidden = 1,
    YGOverflowScroll = 2
};

enum YGPositionType : int32_t {
    YGPositionTypeStatic = 0,
    YGPositionTypeRelative = 1,
    YGPositionTypeAbsolute = 2
};

enum YGPrintOptions : int32_t {
    YGPrintOptionsLayout = 1,
    YGPrintOptionsStyle = 2,
    YGPrintOptionsChildren = 4
};

enum YGUnit : int32_t {
    YGUnitUndefined = 0,
    YGUnitPoint = 1,
    YGUnitPercent = 2,
    YGUnitAuto = 3
};

enum YGWrap : int32_t {
    YGWrapNoWrap = 0,
    YGWrapWrap = 1,
    YGWrapWrapReverse = 2
};

// EN: 8-byte YGValue struct verified at .rodata 0x01ad94..0x01ada8 and 0x025e60.
// VN: Cấu trúc YGValue 8 byte được xác minh tại .rodata 0x01ad94..0x01ada8 và 0x025e60.
struct YGValue {
    float  value;
    YGUnit unit;
};
static_assert(sizeof(YGValue) == 8, "YGValue must be 8 bytes");

struct YGSize {
    float width;
    float height;
};
static_assert(sizeof(YGSize) == 8, "YGSize must be 8 bytes");

// EN: Optional float wrapper used in Yoga layout calculations (0x025f3c).
// VN: Lớp bao float tùy chọn được dùng trong tính toán bố cục Yoga (0x025f3c).
struct YGFloatOptional {
    float value_;
    constexpr YGFloatOptional() noexcept : value_(NAN) {}
    constexpr explicit YGFloatOptional(float v) noexcept : value_(v) {}
    bool isUndefined() const noexcept { return std::isnan(value_); }
    float unwrap() const noexcept { return value_; }
};

struct YGNode;
struct YGConfig;

namespace facebook {
namespace yoga {

enum class LayoutPassReason : int32_t {
    kInitial = 0,
    kAbsLayout = 1,
    kStretch = 2,
    kMultilineStretch = 3,
    kFlexLayout = 4,
    kMeasureChild = 5,
    kAbsMeasureChild = 6,
    kFlexMeasure = 7
};

namespace detail {

// EN: 32-bit compressed YGValue representation used in YGStyle (0x028988..0x028afc).
//     Verified from 0x028998: mov w8, #0x7fc00000 (kUndefined = 0x7FC00000).
// VN: Biểu diễn YGValue nén 32-bit dùng trong YGStyle (0x028988..0x028afc).
struct CompactValue {
    uint32_t repr_;

    static constexpr uint32_t kUndefinedRepr = 0x7FC00000u;
    static constexpr uint32_t kAutoRepr      = 0x7FC00003u;
    static constexpr uint32_t kZeroPointRepr = 0x00000001u;

    constexpr CompactValue() noexcept : repr_(kUndefinedRepr) {}
    constexpr explicit CompactValue(uint32_t r) noexcept : repr_(r) {}

    static CompactValue ofUndefined() noexcept { return CompactValue(kUndefinedRepr); }
    static CompactValue ofAuto() noexcept { return CompactValue(kAutoRepr); }

    static CompactValue of(float value, YGUnit unit) noexcept {
        if (std::isnan(value) || unit == YGUnitUndefined) {
            return ofUndefined();
        }
        if (unit == YGUnitAuto) {
            return ofAuto();
        }
        YGValue v{value, unit};
        uint32_t bits = 0;
        __builtin_memcpy(&bits, &v.value, sizeof(uint32_t));
        if (unit == YGUnitPercent) {
            bits |= 1u;
        } else {
            bits &= ~1u;
        }
        return CompactValue(bits);
    }

    YGValue toYGValue(YGUnit default_unit = YGUnitPoint) const noexcept {
        if (repr_ == kUndefinedRepr) {
            return YGValue{NAN, YGUnitUndefined};
        }
        if (repr_ == kAutoRepr) {
            return YGValue{NAN, YGUnitAuto};
        }
        YGUnit u = (repr_ & 1u) ? YGUnitPercent : default_unit;
        uint32_t clean = repr_ & ~1u;
        float val = 0.0f;
        __builtin_memcpy(&val, &clean, sizeof(float));
        return YGValue{val, u};
    }
};

template <size_t N>
struct Values {
    CompactValue slots_[N];
    CompactValue& operator[](size_t i) noexcept { return slots_[i]; }
    const CompactValue& operator[](size_t i) const noexcept { return slots_[i]; }
};

} // namespace detail

struct LayoutData {
    uint32_t layouts = 0;
    uint32_t measures = 0;
    uint32_t maxMeasureCache = 0;
    uint32_t cachedLayouts = 0;
    uint32_t cachedMeasures = 0;
    uint32_t measureCallbacks = 0;
    uint32_t measureCallbackReasonsCount[8] = {};
};

} // namespace yoga
} // namespace facebook

// EN: Exact 48-byte (0x30) YGConfig ABI layout verified from 0x02601c..0x026174 & 0x02c1f8.
// VN: Bố cục ABI YGConfig 48 byte (0x30) chính xác được xác minh từ 0x02601c..0x026174 & 0x02c1f8.
struct YGConfig {
    void*    cloneNodeCallback;   // +0x00
    void*    logger;              // +0x08
    uint8_t  flags;               // +0x10 (bit0: useWebDefaults, bit1: printTree, bit2: legacyStretch, bit3: loggerCtx)
    uint8_t  padding_11[7];       // +0x11..+0x17
    uint64_t enabledExperiments;  // +0x18 (bitset of YGExperimentalFeature 0..2)
    uint32_t errata;              // +0x20 (YGErrata bitmask)
    float    pointScaleFactor;    // +0x24 (default 1.0f == 0x3f800000 at 0x026044)
    void*    context;             // +0x28
};
static_assert(sizeof(YGConfig) == 48, "YGConfig must be exactly 48 bytes (0x30)");

// EN: YGStyle ABI structure verified at 0x028988..0x028afc.
// VN: Cấu trúc ABI YGStyle được xác minh tại 0x028988..0x028afc.
struct YGStyle {
    uint32_t packed_enums; // direction:2, flexDirection:2, justifyContent:3, alignContent:3, alignItems:3, alignSelf:3, positionType:2, flexWrap:2, overflow:2, display:1
    YGFloatOptional flex;
    YGFloatOptional flexGrow;
    YGFloatOptional flexShrink;
    facebook::yoga::detail::CompactValue flexBasis;
    facebook::yoga::detail::Values<9> margin;
    facebook::yoga::detail::Values<9> position;
    facebook::yoga::detail::Values<9> padding;
    facebook::yoga::detail::Values<9> border;
    facebook::yoga::detail::Values<3> gap;
    facebook::yoga::detail::Values<2> dimensions;
    facebook::yoga::detail::Values<2> minDimensions;
    facebook::yoga::detail::Values<2> maxDimensions;
    YGFloatOptional aspectRatio;

    YGStyle() noexcept;
};

// EN: YGLayout ABI structure storing computed Flexbox geometry (0x0283cc..0x028814).
// VN: Cấu trúc ABI YGLayout lưu trữ hình học Flexbox đã tính toán (0x0283cc..0x028814).
struct YGLayout {
    float position[4];          // Left, Top, Right, Bottom (+0x00..+0x0F)
    float dimensions[2];        // Width, Height (+0x10..+0x17)
    float margin[4];            // (+0x18..+0x27)
    float border[4];            // (+0x28..+0x37)
    float padding[4];           // (+0x38..+0x47)
    uint8_t flags;              // direction:2, didUseLegacyFlag:1, doesLegacyStretchFlagAffectsLayout:1, hadOverflow:1
    uint32_t computedFlexBasisGeneration;
    YGFloatOptional computedFlexBasis;
    uint32_t generationCount;
    YGDirection lastOwnerDirection;
    uint32_t nextCachedMeasurementsIndex;
    float measuredDimensions[2];
};

// EN: YGNode ABI structure reconstructed from 0x028818..0x02c998.
// VN: Cấu trúc ABI YGNode được tái tạo từ 0x028818..0x02c998.
struct YGNode {
    void*    context_;          // +0x00
    uint8_t  flags_;            // +0x08 (hasNewLayout:1, isRefBaseline:1, isDirty:1, nodeType:1, ...)
    void*    measure_;          // +0x10
    void*    baseline_;         // +0x18
    void*    print_;            // +0x20
    void*    dirtied_;          // +0x28
    YGStyle  style_;            // +0x30
    YGLayout layout_;           // +0xFC
    uint32_t lineIndex_;        // +0x260
    YGNode*  owner_;            // +0x268
    std::vector<YGNode*> children_; // +0x270
    YGConfig* config_;          // +0x288
    YGValue  resolvedDimensions_[2]; // +0x290

    explicit YGNode(YGConfig* config = nullptr) noexcept;
};

namespace nextai {
namespace opencut {
namespace tt_ugen_layout {

struct UgenJniMethodEntry {
    const char* name;
    const char* signature;
    uint32_t    name_rodata_va;
    uint32_t    sig_rodata_va;
    uint32_t    fn_text_va;
};

} // namespace tt_ugen_layout
} // namespace opencut
} // namespace nextai
