// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Qualcomm FastCV Computer Vision SDK & GPU Image Processing
// File: fastcv_types.h
// Description: Core FastCV data types, templates (Size_, Point_, Rect_, Scalar_),
//              MatStep, MatUsageFlags, and depth/channel type definitions.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// Tuân thủ Hiến pháp AGENTS.md: Bố cục struct ABI, không stub, khớp opcode nhị phân.
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_TYPES_H_
#define NEXTAI_OPENCUT_FASTCV_TYPES_H_

#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <functional>
#include <string>

namespace FASTCV {
namespace EXPORTS {

// ==============================================================================
// 1. Data Type Depth & Channel Constants (OpenCV/FastCV ABI standard)
// ==============================================================================
#define FCV_CN_SHIFT 3
#define FCV_DEPTH_MASK 7
#define FCV_MAT_DEPTH(flags) ((flags) & FCV_DEPTH_MASK)

#define FCV_8U   0
#define FCV_8S   1
#define FCV_16U  2
#define FCV_16S  3
#define FCV_32S  4
#define FCV_32F  5
#define FCV_64F  6

#define FCV_MAKETYPE(depth, cn) (FCV_MAT_DEPTH(depth) + (((cn)-1) << FCV_CN_SHIFT))

#define FCV_8UC1 FCV_MAKETYPE(FCV_8U, 1)
#define FCV_8UC2 FCV_MAKETYPE(FCV_8U, 2)
#define FCV_8UC3 FCV_MAKETYPE(FCV_8U, 3)
#define FCV_8UC4 FCV_MAKETYPE(FCV_8U, 4)

#define FCV_32FC1 FCV_MAKETYPE(FCV_32F, 1)
#define FCV_32FC2 FCV_MAKETYPE(FCV_32F, 2)
#define FCV_32FC3 FCV_MAKETYPE(FCV_32F, 3)
#define FCV_32FC4 FCV_MAKETYPE(FCV_32F, 4)

// ==============================================================================
// 2. Color Conversion Codes (cvtColor)
// ==============================================================================
enum ColorConversionCodes {
    COLOR_BGR2BGRA     = 0,
    COLOR_RGB2RGBA     = COLOR_BGR2BGRA,
    COLOR_BGRA2BGR     = 1,
    COLOR_RGBA2RGB     = COLOR_BGRA2BGR,
    COLOR_BGR2RGBA     = 2,
    COLOR_RGBA2BGR     = COLOR_BGR2RGBA,
    COLOR_RGB2BGR      = 4,
    COLOR_BGR2RGB      = COLOR_RGB2BGR,
    COLOR_BGR2GRAY     = 6,
    COLOR_RGB2GRAY     = 7,
    COLOR_GRAY2BGR     = 8,
    COLOR_GRAY2RGB     = COLOR_GRAY2BGR,
    COLOR_BGR2YUV      = 11,
    COLOR_RGB2YUV      = 12,
    COLOR_YUV2BGR      = 13,
    COLOR_YUV2RGB      = 14,
    COLOR_YUV2BGR_NV12 = 90,
    COLOR_YUV2RGB_NV12 = 91,
    COLOR_YUV2BGR_NV21 = 92,
    COLOR_YUV2RGB_NV21 = 93,
    COLOR_RGBA2YUV_I420 = 127,
};

// ==============================================================================
// 3. Threshold Types
// ==============================================================================
enum ThresholdTypes {
    THRESH_BINARY     = 0,
    THRESH_BINARY_INV = 1,
    THRESH_TRUNC      = 2,
    THRESH_TOZERO     = 3,
    THRESH_TOZERO_INV = 4,
    THRESH_MASK       = 7,
    THRESH_OTSU       = 8,
};

// ==============================================================================
// 4. Normalization & Border Types
// ==============================================================================
enum NormTypes {
    NORM_INF    = 1,
    NORM_L1     = 2,
    NORM_L2     = 4,
    NORM_L2SQR  = 5,
    NORM_MINMAX = 32,
};

enum BorderTypes {
    BORDER_CONSTANT    = 0,
    BORDER_REPLICATE   = 1,
    BORDER_REFLECT     = 2,
    BORDER_WRAP        = 3,
    BORDER_REFLECT_101 = 4,
    BORDER_DEFAULT     = BORDER_REFLECT_101,
};

// ==============================================================================
// 5. Backend & Flags
// ==============================================================================
enum class FASTCVGPUBackend {
    kOpenCL = 0,
    kOpenGL = 1,
    kVulkan = 2,
    kHexagonDSP = 3,
};

enum class MatUsageFlags {
    kDefault = 0,
    kReadOptimization = 1,
    kWriteOptimization = 2,
    kGPUTextureShare = 4,
    kHardwareBufferShare = 8,
};

// ==============================================================================
// 6. Geometry Templates (Size_, Point_, Rect_, Scalar_)
// ==============================================================================
template<typename _Tp>
class Size_ {
public:
    _Tp width;
    _Tp height;

    constexpr Size_() : width(0), height(0) {}
    constexpr Size_(_Tp w, _Tp h) : width(w), height(h) {}

    _Tp area() const { return width * height; }
    bool empty() const { return width <= 0 || height <= 0; }
};

template<typename _Tp>
class Point_ {
public:
    _Tp x;
    _Tp y;

    constexpr Point_() : x(0), y(0) {}
    constexpr Point_(_Tp in_x, _Tp in_y) : x(in_x), y(in_y) {}

    Point_ operator+(const Point_& o) const { return Point_(x + o.x, y + o.y); }
    Point_ operator-(const Point_& o) const { return Point_(x - o.x, y - o.y); }
    Point_ operator*(_Tp s) const { return Point_(x * s, y * s); }
    _Tp dot(const Point_& o) const { return x * o.x + y * o.y; }
};

template<typename _Tp>
class Rect_ {
public:
    _Tp x;
    _Tp y;
    _Tp width;
    _Tp height;

    constexpr Rect_() : x(0), y(0), width(0), height(0) {}
    constexpr Rect_(_Tp in_x, _Tp in_y, _Tp w, _Tp h) : x(in_x), y(in_y), width(w), height(h) {}

    _Tp area() const { return width * height; }
    bool empty() const { return width <= 0 || height <= 0; }
    bool contains(const Point_<_Tp>& pt) const {
        return pt.x >= x && pt.x < x + width && pt.y >= y && pt.y < y + height;
    }
};

template<typename _Tp>
class Scalar_ {
public:
    _Tp val[4];

    constexpr Scalar_() : val{0, 0, 0, 0} {}
    constexpr Scalar_(_Tp v0) : val{v0, 0, 0, 0} {}
    constexpr Scalar_(_Tp v0, _Tp v1, _Tp v2, _Tp v3 = 0) : val{v0, v1, v2, v3} {}

    _Tp operator[](int i) const { return val[i]; }
    _Tp& operator[](int i) { return val[i]; }

    static Scalar_<_Tp> all(_Tp v) { return Scalar_<_Tp>(v, v, v, v); }
};

// ==============================================================================
// 7. MatStep Primitive (Row & Element Step Helper)
// Matches AArch64 opcode 0x63fb8 (ctor), 0x63ff8 (cast to ulong), 0x63fec (operator[])
// ==============================================================================
class MatStep {
public:
    size_t p[2];

    MatStep() { p[0] = 0; p[1] = 0; }
    explicit MatStep(size_t s) { p[0] = s; p[1] = 0; }

    size_t operator[](int i) const { return p[i]; }
    size_t& operator[](int i) { return p[i]; }

    operator size_t() const { return p[0]; }
};

using Size = Size_<int>;
using Point2i = Point_<int>;
using Point2f = Point_<float>;
using Rect = Rect_<int>;
using Scalar = Scalar_<double>;

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_TYPES_H_
