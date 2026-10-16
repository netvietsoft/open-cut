// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Vector Geometry Primitives & Math
// File: skity_geometry.h
// Description: Reconstructed Skity geometric primitives: Vec2, Vec3, Vec4, Rect,
//              RRect, and Quaternion with exact mathematical guarantees.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// Tuân thủ Hiến pháp AGENTS.md: Bố cục struct ABI, không stub, khớp opcode nhị phân.
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_GEOMETRY_H_
#define NEXTAI_OPENCUT_SKITY_GEOMETRY_H_

#include <cmath>
#include <cstdint>
#include <algorithm>
#include <array>

namespace skity {

// ==============================================================================
// 1. Vector Primitives (Vec2, Vec3, Vec4)
// ==============================================================================

struct Vec2 {
    float x;
    float y;

    constexpr Vec2() : x(0.0f), y(0.0f) {}
    constexpr Vec2(float in_x, float in_y) : x(in_x), y(in_y) {}

    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    Vec2 operator/(float s) const { return Vec2(x / s, y / s); }

    float Dot(const Vec2& o) const { return x * o.x + y * o.y; }
    float Cross(const Vec2& o) const { return x * o.y - y * o.x; }
    float LengthSq() const { return x * x + y * y; }
    float Length() const { return std::sqrt(LengthSq()); }

    Vec2 Normalized() const {
        float len = Length();
        return (len > 1e-7f) ? (*this / len) : Vec2(0.0f, 0.0f);
    }
};

struct Vec3 {
    float x;
    float y;
    float z;

    constexpr Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    constexpr Vec3(float in_x, float in_y, float in_z) : x(in_x), y(in_y), z(in_z) {}

    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }

    float Dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    Vec3 Cross(const Vec3& o) const {
        return Vec3(
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        );
    }
    float Length() const { return std::sqrt(Dot(*this)); }
    Vec3 Normalized() const {
        float l = Length();
        return (l > 1e-7f) ? (*this * (1.0f / l)) : Vec3(0.0f, 0.0f, 0.0f);
    }
};

struct Vec4 {
    float x;
    float y;
    float z;
    float w;

    constexpr Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    constexpr Vec4(float in_x, float in_y, float in_z, float in_w)
        : x(in_x), y(in_y), z(in_z), w(in_w) {}

    float Dot(const Vec4& o) const { return x * o.x + y * o.y + z * o.z + w * o.w; }
};

using Point = Vec2;

// ==============================================================================
// 2. Rect Primitive
// Layout: float left, top, right, bottom (16 bytes)
// Matching AArch64: ldp d0, d1, [x0]
// ==============================================================================
struct Rect {
    float left;
    float top;
    float right;
    float bottom;

    constexpr Rect() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
    constexpr Rect(float l, float t, float r, float b)
        : left(l), top(t), right(r), bottom(b) {}

    static constexpr Rect MakeEmpty() { return Rect(0.0f, 0.0f, 0.0f, 0.0f); }
    static constexpr Rect MakeLTRB(float l, float t, float r, float b) { return Rect(l, t, r, b); }
    static constexpr Rect MakeXYWH(float x, float y, float w, float h) { return Rect(x, y, x + w, y + h); }

    float Width() const { return right - left; }
    float Height() const { return bottom - top; }
    bool IsEmpty() const { return left >= right || top >= bottom; }

    // Opcode 0xf07e8: RoundOut (frintm v0.2s, frintp v1.2s)
    // Round left & top down (floor), right & bottom up (ceil)
    void RoundOut();

    // Opcode 0xf09b0: Intersect
    // Intersects this rect with another, returns true if non-empty
    static bool Intersect(const Rect& a, const Rect& b, Rect* out);
    bool Intersect(const Rect& other);

    // Opcode 0xf0864: MakeInset
    // Shrinks rect by dx and dy
    Rect MakeInset(float dx, float dy) const;

    // Fast bounds expansion
    void Join(const Rect& other);
    bool Contains(float px, float py) const;
    bool Contains(const Rect& r) const;
};

// ==============================================================================
// 3. RRect Primitive (Rounded Rectangle)
// Layout: Rect rect (16 bytes) + 4 radii Vec2 [tl, tr, br, bl] (32 bytes) = 48 bytes
// ==============================================================================
class RRect {
public:
    enum Corner {
        kUpperLeft = 0,
        kUpperRight = 1,
        kLowerRight = 2,
        kLowerLeft = 3,
    };

    enum Type {
        kEmpty = 0,
        kRect = 1,
        kOval = 2,
        kSimple = 3,
        kNinePatch = 4,
        kComplex = 5,
    };

    RRect();
    ~RRect() = default;

    // Opcode 0xf10d4: AreRectAndRadiiValid
    static bool AreRectAndRadiiValid(const Rect& rect, const std::array<Vec2, 4>& radii);

    // Opcode 0xf0a00: SetRect
    void SetRect(const Rect& rect);

    // Opcode 0xf131c: SetOval
    void SetOval(const Rect& oval);

    // Opcode 0xf11b8: SetRectRadii
    void SetRectRadii(const Rect& rect, const Vec2* radii);

    // Opcode 0xf13c8: MakeEmpty
    void MakeEmpty();

    // Opcode 0xf156c: Contains
    bool Contains(const Rect& rect) const;
    bool Contains(float x, float y) const;

    const Rect& rect() const { return rect_; }
    const std::array<Vec2, 4>& radii() const { return radii_; }
    Type type() const { return type_; }

private:
    void ScaleRadiiIfNecessary();

    Rect rect_;
    std::array<Vec2, 4> radii_;
    Type type_;
};

// ==============================================================================
// 4. Quaternion Primitive (4D Orientation & Rotation)
// Layout: float x, y, z, w (16 bytes)
// ==============================================================================
struct Matrix; // Forward declaration

class Quaternion {
public:
    float x;
    float y;
    float z;
    float w;

    constexpr Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    constexpr Quaternion(float in_x, float in_y, float in_z, float in_w)
        : x(in_x), y(in_y), z(in_z), w(in_w) {}

    // Opcode 0xf0224: Dot (AArch64 vector dot product)
    float Dot(const Quaternion& o) const;

    // Opcode 0xf024c: Multiple (Hamilton quaternion product)
    Quaternion Multiple(const Quaternion& o) const;
    Quaternion operator*(const Quaternion& o) const { return Multiple(o); }

    // Opcode 0xf02d0: Slerp (Spherical Linear Interpolation)
    Quaternion Slerp(const Quaternion& o, float t) const;

    // Opcode 0xf0500: Reciprocal / Conjugate
    Quaternion Reciprocal() const;

    // Opcode 0xf00a4: FromEuler (Yaw, Pitch, Roll in radians)
    static Quaternion FromEuler(float pitch, float yaw, float roll);

    // Opcode 0xf0148: FromAxisAngle
    static Quaternion FromAxisAngle(const Vec3& axis, float angle_rad);

    // Opcode 0xf0498: ToAxisAngle
    void ToAxisAngle(Vec3* out_axis, float* out_angle) const;

    // Opcode 0xeffbc: EulerToMatrix
    static void EulerToMatrix(float pitch, float yaw, float roll, float* out_mat16);
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_GEOMETRY_H_
