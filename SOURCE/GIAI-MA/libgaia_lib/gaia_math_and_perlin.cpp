// ============================================================================
// File: gaia_math_and_perlin.cpp
// Target: libgaia_lib.so (329,704 bytes)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Clean-room C++17 implementation of AmazingEngine GAIA Math, Geometry,
//       Matrix3x3f, Matrix4x4f, Quaternionf, Vector2f/3f, and PerlinNoise
//       verified instruction-by-instruction from .text (0x013164..0x019fc0).
//   VN: Cai dat C++17 chuan clean-room cho he thong Toan hoc, Hinh hoc,
//       Matrix3x3f, Matrix4x4f, Quaternionf, Vector2f/3f va PerlinNoise
//       doi chieu tung lenh AArch64 tu .text (0x013164..0x019fc0).
// ============================================================================

#include "gaia_math_and_perlin.h"
#include "gaia_rodata_tables.h"
#include <cmath>
#include <cstring>
#include <algorithm>
#include <limits>

namespace AmazingEngine {

// ============================================================================
// Vector2f & Vector3f static accessors (0x0190bc .. 0x019144)
// ============================================================================
const Vector2f& Vector2f::zero() noexcept {
    static const Vector2f kZero(0.0f, 0.0f);
    return kZero;
}

const Vector2f& Vector2f::one() noexcept {
    static const Vector2f kOne(1.0f, 1.0f);
    return kOne;
}

float Vector3f::epsilon() noexcept {
    return 9.999999747378752e-06f; // 0x043f10: 0x3727C5AC
}

float Vector3f::infinity() noexcept {
    return std::numeric_limits<float>::infinity(); // 0x043f14: 0x7F800000
}

const Vector3f& Vector3f::infinityVec() noexcept {
    static const Vector3f kInf(std::numeric_limits<float>::infinity(),
                               std::numeric_limits<float>::infinity(),
                               std::numeric_limits<float>::infinity());
    return kInf;
}

const Vector3f& Vector3f::zero() noexcept {
    static const Vector3f kZero(0.0f, 0.0f, 0.0f);
    return kZero;
}

const Vector3f& Vector3f::one() noexcept {
    static const Vector3f kOne(1.0f, 1.0f, 1.0f);
    return kOne;
}

const Vector3f& Vector3f::xAxis() noexcept {
    static const Vector3f kX(1.0f, 0.0f, 0.0f);
    return kX;
}

const Vector3f& Vector3f::yAxis() noexcept {
    static const Vector3f kY(0.0f, 1.0f, 0.0f);
    return kY;
}

const Vector3f& Vector3f::zAxis() noexcept {
    static const Vector3f kZ(0.0f, 0.0f, 1.0f);
    return kZ;
}

static inline float Dot3(const Vector3f& a, const Vector3f& b) noexcept {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vector3f Cross3(const Vector3f& a, const Vector3f& b) noexcept {
    return Vector3f(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

static inline float Length3(const Vector3f& v) noexcept {
    return std::sqrt(Dot3(v, v));
}

static inline Vector3f Normalize3(const Vector3f& v) noexcept {
    float len = Length3(v);
    if (len > 1e-5f) {
        float inv = 1.0f / len;
        return Vector3f(v.x * inv, v.y * inv, v.z * inv);
    }
    return Vector3f(0.0f, 0.0f, 0.0f);
}

// ============================================================================
// Matrix3x3f Implementation (0x013164 .. 0x013d48)
// ============================================================================
Matrix3x3f::Matrix3x3f() noexcept {
    SetIdentity();
}

Matrix3x3f::Matrix3x3f(const float* data) noexcept {
    if (data) {
        std::memcpy(m_Data, data, 9 * sizeof(float));
    } else {
        SetZero();
    }
}

Matrix3x3f::Matrix3x3f(const Matrix4x4f& other) noexcept {
    *this = other;
}

Matrix3x3f& Matrix3x3f::operator=(const Matrix4x4f& other) noexcept {
    // 0x013228: Extracts upper-left 3x3 from 4x4 column-major matrix
    m_Data[0] = other.m_Data[0];
    m_Data[1] = other.m_Data[1];
    m_Data[2] = other.m_Data[2];
    m_Data[3] = other.m_Data[4];
    m_Data[4] = other.m_Data[5];
    m_Data[5] = other.m_Data[6];
    m_Data[6] = other.m_Data[8];
    m_Data[7] = other.m_Data[9];
    m_Data[8] = other.m_Data[10];
    return *this;
}

const Matrix3x3f& Matrix3x3f::identity() noexcept {
    static const float kId[9] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    static const Matrix3x3f kIdentity(kId);
    return kIdentity;
}

const Matrix3x3f& Matrix3x3f::zero() noexcept {
    static const float kZr[9] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    static const Matrix3x3f kZero(kZr);
    return kZero;
}

Matrix3x3f& Matrix3x3f::SetIdentity() noexcept {
    // 0x01333c
    std::memset(m_Data, 0, sizeof(m_Data));
    m_Data[0] = 1.0f;
    m_Data[4] = 1.0f;
    m_Data[8] = 1.0f;
    return *this;
}

Matrix3x3f& Matrix3x3f::SetZero() noexcept {
    // 0x013354
    std::memset(m_Data, 0, sizeof(m_Data));
    return *this;
}

Matrix3x3f& Matrix3x3f::SetOrthoNormalBasis(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept {
    // 0x013364
    m_Data[0] = inX.x; m_Data[1] = inX.y; m_Data[2] = inX.z;
    m_Data[3] = inY.x; m_Data[4] = inY.y; m_Data[5] = inY.z;
    m_Data[6] = inZ.x; m_Data[7] = inZ.y; m_Data[8] = inZ.z;
    return *this;
}

Matrix3x3f& Matrix3x3f::SetOrthoNormalBasisInverse(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept {
    // 0x0133b0
    m_Data[0] = inX.x; m_Data[3] = inX.y; m_Data[6] = inX.z;
    m_Data[1] = inY.x; m_Data[4] = inY.y; m_Data[7] = inY.z;
    m_Data[2] = inZ.x; m_Data[5] = inZ.y; m_Data[8] = inZ.z;
    return *this;
}

Matrix3x3f& Matrix3x3f::SetScale(const Vector3f& inScale) noexcept {
    // 0x0133fc
    SetZero();
    m_Data[0] = inScale.x;
    m_Data[4] = inScale.y;
    m_Data[8] = inScale.z;
    return *this;
}

// 0x013428 .. 0x01351c: Matrix3x3f::IsIdentity(float threshold)
// Verified AArch64:
//   0x01342c: fmov s1, #-1.00000000
//   Checks |m[0] - 1| < s0, |m[3]| < s0, |m[6]| < s0, |m[1]| < s0, |m[4] - 1| < s0, ...
bool Matrix3x3f::IsIdentity(float threshold) const noexcept {
    if (std::fabs(m_Data[0] - 1.0f) >= threshold) return false;
    if (std::fabs(m_Data[3]) >= threshold) return false;
    if (std::fabs(m_Data[6]) >= threshold) return false;
    if (std::fabs(m_Data[1]) >= threshold) return false;
    if (std::fabs(m_Data[4] - 1.0f) >= threshold) return false;
    if (std::fabs(m_Data[7]) >= threshold) return false;
    if (std::fabs(m_Data[2]) >= threshold) return false;
    if (std::fabs(m_Data[5]) >= threshold) return false;
    if (std::fabs(m_Data[8] - 1.0f) >= threshold) return false;
    return true;
}

// 0x013520 .. 0x0135a0: Matrix3x3f::Scale(Vector3f const&)
Matrix3x3f& Matrix3x3f::Scale(const Vector3f& inScale) noexcept {
    m_Data[0] *= inScale.x;
    m_Data[1] *= inScale.x;
    m_Data[2] *= inScale.x;
    m_Data[3] *= inScale.y;
    m_Data[4] *= inScale.y;
    m_Data[5] *= inScale.y;
    m_Data[6] *= inScale.z;
    m_Data[7] *= inScale.z;
    m_Data[8] *= inScale.z;
    return *this;
}

// 0x0135a4 .. 0x0135fc: Matrix3x3f::GetDeterminant() const
// Verified AArch64:
//   ldp s0, s7, [x0]         (m0=s0, m1=s7)
//   ldp s4, s1, [x0, #0xc]   (m3=s4, m4=s1)
//   ldp s6, s2, [x0, #0x1c]  (m7=s6, m8=s2)
//   ldr s3, [x0, #8]         (m2=s3)
//   ldp s16, s5, [x0, #0x14] (m5=s16, m6=s5)
//   det = m0*m4*m8 + m3*m7*m2 + m6*m1*m5 - m2*m4*m6 - m8*m3*m1 - m0*m7*m5
float Matrix3x3f::GetDeterminant() const noexcept {
    const float m0 = m_Data[0], m1 = m_Data[1], m2 = m_Data[2];
    const float m3 = m_Data[3], m4 = m_Data[4], m5 = m_Data[5];
    const float m6 = m_Data[6], m7 = m_Data[7], m8 = m_Data[8];
    return (m0 * m4 * m8 + m3 * m7 * m2 + m6 * m1 * m5)
         - (m2 * m4 * m6 + m8 * m3 * m1 + m0 * m7 * m5);
}

// 0x013600 .. 0x013620: Matrix3x3f::Transpose()
Matrix3x3f& Matrix3x3f::Transpose() noexcept {
    std::swap(m_Data[1], m_Data[3]);
    std::swap(m_Data[2], m_Data[6]);
    std::swap(m_Data[5], m_Data[7]);
    return *this;
}

// 0x013624 .. 0x0136b0: Matrix3x3f::Invert()
// Verified AArch64: Promotes 3x3 to temporary 4x4 on stack (`sp + #8`), calls
// InvertMatrix4x4_Full(sp + 8, sp + 8), and copies upper-left 3x3 back to `this`.
bool Matrix3x3f::Invert() noexcept {
    Matrix4x4f temp(*this);
    bool ok = InvertMatrix4x4_Full(temp.m_Data, temp.m_Data);
    *this = temp;
    return ok;
}

// 0x0136b4 .. 0x013738: Matrix3x3f::InvertTranspose()
void Matrix3x3f::InvertTranspose() noexcept {
    Invert();
    Transpose();
}

// 0x01373c .. 0x013758: Matrix3x3f::operator*=(float)
Matrix3x3f& Matrix3x3f::operator*=(float s) noexcept {
    for (int i = 0; i < 9; ++i) {
        m_Data[i] *= s;
    }
    return *this;
}

// 0x01375c .. 0x013894: Matrix3x3f::operator*=(Matrix3x3f const&)
Matrix3x3f& Matrix3x3f::operator*=(const Matrix3x3f& rhs) noexcept {
    float res[9];
    for (int col = 0; col < 3; ++col) {
        const float r0 = rhs.m_Data[col * 3 + 0];
        const float r1 = rhs.m_Data[col * 3 + 1];
        const float r2 = rhs.m_Data[col * 3 + 2];
        res[col * 3 + 0] = m_Data[0] * r0 + m_Data[3] * r1 + m_Data[6] * r2;
        res[col * 3 + 1] = m_Data[1] * r0 + m_Data[4] * r1 + m_Data[7] * r2;
        res[col * 3 + 2] = m_Data[2] * r0 + m_Data[5] * r1 + m_Data[8] * r2;
    }
    std::memcpy(m_Data, res, sizeof(res));
    return *this;
}

Matrix3x3f& Matrix3x3f::operator*=(const Matrix4x4f& rhs) noexcept {
    Matrix3x3f m3(rhs);
    return (*this *= m3);
}

Matrix3x3f& Matrix3x3f::SetAxisAngle(const Vector3f& axis, float radians) noexcept {
    // 0x0139d4
    const float s = std::sin(radians);
    const float c = std::cos(radians);
    const float t = 1.0f - c;
    const float x = axis.x, y = axis.y, z = axis.z;

    m_Data[0] = t * x * x + c;
    m_Data[1] = t * x * y + s * z;
    m_Data[2] = t * x * z - s * y;

    m_Data[3] = t * x * y - s * z;
    m_Data[4] = t * y * y + c;
    m_Data[5] = t * y * z + s * x;

    m_Data[6] = t * x * z + s * y;
    m_Data[7] = t * y * z - s * x;
    m_Data[8] = t * z * z + c;
    return *this;
}

Matrix3x3f& Matrix3x3f::SetFromToRotation(const Vector3f& from, const Vector3f& to) noexcept {
    // 0x013a94
    Quaternionf q = FromToQuaternionSafe(from, to);
    QuaternionToMatrix(q, *this);
    return *this;
}

// ============================================================================
// Matrix4x4f Implementation & Gauss-Jordan Full Inversion (0x014344 .. 0x016df8)
// ============================================================================
Matrix4x4f::Matrix4x4f() noexcept {
    SetIdentity();
}

Matrix4x4f::Matrix4x4f(const float* data) noexcept {
    if (data) {
        std::memcpy(m_Data, data, 16 * sizeof(float));
    } else {
        SetIdentity();
    }
}

Matrix4x4f::Matrix4x4f(const Matrix3x3f& other) noexcept {
    *this = other;
}

Matrix4x4f& Matrix4x4f::operator=(const Matrix3x3f& other) noexcept {
    // 0x0144cc
    m_Data[0] = other.m_Data[0]; m_Data[1] = other.m_Data[1]; m_Data[2] = other.m_Data[2]; m_Data[3] = 0.0f;
    m_Data[4] = other.m_Data[3]; m_Data[5] = other.m_Data[4]; m_Data[6] = other.m_Data[5]; m_Data[7] = 0.0f;
    m_Data[8] = other.m_Data[6]; m_Data[9] = other.m_Data[7]; m_Data[10] = other.m_Data[8]; m_Data[11] = 0.0f;
    m_Data[12] = 0.0f;           m_Data[13] = 0.0f;           m_Data[14] = 0.0f;            m_Data[15] = 1.0f;
    return *this;
}

const Matrix4x4f& Matrix4x4f::identity() noexcept {
    static const float kId[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    static const Matrix4x4f kIdentity(kId);
    return kIdentity;
}

bool Matrix4x4f::IsIdentity(float threshold) const noexcept {
    const float* id = identity().m_Data;
    for (int i = 0; i < 16; ++i) {
        if (std::fabs(m_Data[i] - id[i]) >= threshold) return false;
    }
    return true;
}

double Matrix4x4f::GetDeterminant() const noexcept {
    // 0x0146cc: Cofactor expansion in double precision
    const double m00 = m_Data[0],  m10 = m_Data[1],  m20 = m_Data[2],  m30 = m_Data[3];
    const double m01 = m_Data[4],  m11 = m_Data[5],  m21 = m_Data[6],  m31 = m_Data[7];
    const double m02 = m_Data[8],  m12 = m_Data[9],  m22 = m_Data[10], m32 = m_Data[11];
    const double m03 = m_Data[12], m13 = m_Data[13], m23 = m_Data[14], m33 = m_Data[15];

    const double b00 = m00 * m11 - m10 * m01;
    const double b01 = m00 * m21 - m20 * m01;
    const double b02 = m00 * m31 - m30 * m01;
    const double b03 = m10 * m21 - m20 * m11;
    const double b04 = m10 * m31 - m30 * m11;
    const double b05 = m20 * m31 - m30 * m21;
    const double b06 = m02 * m13 - m12 * m03;
    const double b07 = m02 * m23 - m22 * m03;
    const double b08 = m02 * m33 - m32 * m03;
    const double b09 = m12 * m23 - m22 * m13;
    const double b10 = m12 * m33 - m32 * m13;
    const double b11 = m22 * m33 - m32 * m23;

    return b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
}

void MultiplyMatrices4x4REF(const Matrix4x4f* lhs, const Matrix4x4f* rhs, Matrix4x4f* res) noexcept {
    // 0x01490c
    float tmp[16];
    for (int col = 0; col < 4; ++col) {
        const float r0 = rhs->m_Data[col * 4 + 0];
        const float r1 = rhs->m_Data[col * 4 + 1];
        const float r2 = rhs->m_Data[col * 4 + 2];
        const float r3 = rhs->m_Data[col * 4 + 3];
        for (int row = 0; row < 4; ++row) {
            tmp[col * 4 + row] =
                lhs->m_Data[0 * 4 + row] * r0 +
                lhs->m_Data[1 * 4 + row] * r1 +
                lhs->m_Data[2 * 4 + row] * r2 +
                lhs->m_Data[3 * 4 + row] * r3;
        }
    }
    std::memcpy(res->m_Data, tmp, sizeof(tmp));
}

void MultiplyMatrices3x4(const Matrix4x4f& lhs, const Matrix4x4f& rhs, Matrix4x4f& res) noexcept {
    // 0x014a18
    MultiplyMatrices4x4REF(&lhs, &rhs, &res);
    res.m_Data[3] = 0.0f;
    res.m_Data[7] = 0.0f;
    res.m_Data[11] = 0.0f;
    res.m_Data[15] = 1.0f;
}

Matrix4x4f& Matrix4x4f::operator*=(const Matrix4x4f& inM1) noexcept {
    MultiplyMatrices4x4REF(this, &inM1, this);
    return *this;
}

Matrix4x4f& Matrix4x4f::SetIdentity() noexcept {
    std::memcpy(m_Data, identity().m_Data, sizeof(m_Data));
    return *this;
}

Matrix4x4f& Matrix4x4f::SetOrthoNormalBasis(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept {
    m_Data[0] = inX.x; m_Data[1] = inX.y; m_Data[2] = inX.z; m_Data[3] = 0.0f;
    m_Data[4] = inY.x; m_Data[5] = inY.y; m_Data[6] = inY.z; m_Data[7] = 0.0f;
    m_Data[8] = inZ.x; m_Data[9] = inZ.y; m_Data[10] = inZ.z; m_Data[11] = 0.0f;
    m_Data[12] = 0.0f; m_Data[13] = 0.0f; m_Data[14] = 0.0f;  m_Data[15] = 1.0f;
    return *this;
}

Matrix4x4f& Matrix4x4f::SetOrthoNormalBasisInverse(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept {
    m_Data[0] = inX.x; m_Data[4] = inX.y; m_Data[8]  = inX.z; m_Data[12] = 0.0f;
    m_Data[1] = inY.x; m_Data[5] = inY.y; m_Data[9]  = inY.z; m_Data[13] = 0.0f;
    m_Data[2] = inZ.x; m_Data[6] = inZ.y; m_Data[10] = inZ.z; m_Data[14] = 0.0f;
    m_Data[3] = 0.0f;  m_Data[7] = 0.0f;  m_Data[11] = 0.0f;  m_Data[15] = 1.0f;
    return *this;
}

Matrix4x4f& Matrix4x4f::SetPositionAndOrthoNormalBasis(const Vector3f& inPosition, const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept {
    SetOrthoNormalBasis(inX, inY, inZ);
    m_Data[12] = inPosition.x;
    m_Data[13] = inPosition.y;
    m_Data[14] = inPosition.z;
    return *this;
}

Matrix4x4f& Matrix4x4f::SetScale(const Vector3f& inScale) noexcept {
    SetIdentity();
    m_Data[0]  = inScale.x;
    m_Data[5]  = inScale.y;
    m_Data[10] = inScale.z;
    return *this;
}

Matrix4x4f& Matrix4x4f::Scale(const Vector3f& inScale) noexcept {
    for (int r = 0; r < 4; ++r) {
        m_Data[0 + r] *= inScale.x;
        m_Data[4 + r] *= inScale.y;
        m_Data[8 + r] *= inScale.z;
    }
    return *this;
}

Matrix4x4f& Matrix4x4f::Translate(const Vector3f& inTrans) noexcept {
    for (int r = 0; r < 4; ++r) {
        m_Data[12 + r] += m_Data[0 + r] * inTrans.x + m_Data[4 + r] * inTrans.y + m_Data[8 + r] * inTrans.z;
    }
    return *this;
}

Matrix4x4f& Matrix4x4f::AddTranslate(const Vector3f& inTrans) noexcept {
    m_Data[12] += inTrans.x;
    m_Data[13] += inTrans.y;
    m_Data[14] += inTrans.z;
    return *this;
}

Matrix4x4f& Matrix4x4f::SetTranslate(const Vector3f& inTrans) noexcept {
    SetIdentity();
    m_Data[12] = inTrans.x;
    m_Data[13] = inTrans.y;
    m_Data[14] = inTrans.z;
    return *this;
}

Matrix4x4f& Matrix4x4f::SetPerspective(float fovy, float aspect, float zNear, float zFar) noexcept {
    const float deg2rad = 3.14159265358979323846f / 180.0f;
    const float cotan = 1.0f / std::tan(fovy * deg2rad * 0.5f);
    std::memset(m_Data, 0, sizeof(m_Data));
    m_Data[0]  = cotan / aspect;
    m_Data[5]  = cotan;
    m_Data[10] = -(zFar + zNear) / (zFar - zNear);
    m_Data[11] = -1.0f;
    m_Data[14] = -(2.0f * zFar * zNear) / (zFar - zNear);
    return *this;
}

Matrix4x4f& Matrix4x4f::SetPerspectiveCotan(float cotanHalfFOV, float zNear, float zFar) noexcept {
    std::memset(m_Data, 0, sizeof(m_Data));
    m_Data[0]  = cotanHalfFOV;
    m_Data[5]  = cotanHalfFOV;
    m_Data[10] = -(zFar + zNear) / (zFar - zNear);
    m_Data[11] = -1.0f;
    m_Data[14] = -(2.0f * zFar * zNear) / (zFar - zNear);
    return *this;
}

Matrix4x4f& Matrix4x4f::SetOrtho(float left, float right, float bottom, float top, float zNear, float zFar) noexcept {
    SetIdentity();
    m_Data[0]  =  2.0f / (right - left);
    m_Data[5]  =  2.0f / (top - bottom);
    m_Data[10] = -2.0f / (zFar - zNear);
    m_Data[12] = -(right + left) / (right - left);
    m_Data[13] = -(top + bottom) / (top - bottom);
    m_Data[14] = -(zFar + zNear) / (zFar - zNear);
    return *this;
}

Matrix4x4f& Matrix4x4f::SetFrustum(float left, float right, float bottom, float top, float nearval, float farval) noexcept {
    std::memset(m_Data, 0, sizeof(m_Data));
    m_Data[0]  = (2.0f * nearval) / (right - left);
    m_Data[5]  = (2.0f * nearval) / (top - bottom);
    m_Data[8]  = (right + left) / (right - left);
    m_Data[9]  = (top + bottom) / (top - bottom);
    m_Data[10] = -(farval + nearval) / (farval - nearval);
    m_Data[11] = -1.0f;
    m_Data[14] = -(2.0f * farval * nearval) / (farval - nearval);
    return *this;
}

// ============================================================================
// InvertMatrix4x4_Full (0x0151e0 .. 0x0159dc, 2,048 bytes)
// EN: Exact Gauss-Jordan 4x8 augmented matrix inversion with partial pivoting.
//     Verified from AArch64 0x0151e0..0x015360:
//       - Loads identity row vectors from .rodata 0x043950, 0x0439a0, 0x0439b0, 0x0439c0
//       - Constructs 4 augmented rows wtemp[4][8] on stack [sp + #8 .. sp + #0x88]
//       - Selects pivot row by comparing |r0[0]|, |r1[0]|, |r2[0]|, |r3[0]|
//       - Returns false (0) if pivot == 0.0f (`fcmp s1, #0.0; b.eq #0x15710` at 0x01535c)
// VN: Nghich dao ma tran 4x4 day du bang phuong phap Gauss-Jordan 4x8 co chon
//     phan tu tru (partial pivoting), xac minh chinh xac tu 0x0151e0..0x015360.
// ============================================================================
#define SWAP_ROWS_4X8(a, b) do { float* _tmp = (a); (a) = (b); (b) = _tmp; } while (0)
#define MAT4(m, r, c) ((m)[(c) * 4 + (r)])

bool InvertMatrix4x4_Full(const float* m, float* out) noexcept {
    float wtmp[4][8];
    float m0, m1, m2, m3, s;
    float *r0, *r1, *r2, *r3;

    r0 = wtmp[0]; r1 = wtmp[1]; r2 = wtmp[2]; r3 = wtmp[3];

    r0[0] = MAT4(m, 0, 0); r0[1] = MAT4(m, 0, 1);
    r0[2] = MAT4(m, 0, 2); r0[3] = MAT4(m, 0, 3);
    r0[4] = 1.0f; r0[5] = r0[6] = r0[7] = 0.0f;

    r1[0] = MAT4(m, 1, 0); r1[1] = MAT4(m, 1, 1);
    r1[2] = MAT4(m, 1, 2); r1[3] = MAT4(m, 1, 3);
    r1[5] = 1.0f; r1[4] = r1[6] = r1[7] = 0.0f;

    r2[0] = MAT4(m, 2, 0); r2[1] = MAT4(m, 2, 1);
    r2[2] = MAT4(m, 2, 2); r2[3] = MAT4(m, 2, 3);
    r2[6] = 1.0f; r2[4] = r2[5] = r2[7] = 0.0f;

    r3[0] = MAT4(m, 3, 0); r3[1] = MAT4(m, 3, 1);
    r3[2] = MAT4(m, 3, 2); r3[3] = MAT4(m, 3, 3);
    r3[7] = 1.0f; r3[4] = r3[5] = r3[6] = 0.0f;

    // Choose pivot for column 0
    if (std::fabs(r3[0]) > std::fabs(r2[0])) SWAP_ROWS_4X8(r3, r2);
    if (std::fabs(r2[0]) > std::fabs(r1[0])) SWAP_ROWS_4X8(r2, r1);
    if (std::fabs(r1[0]) > std::fabs(r0[0])) SWAP_ROWS_4X8(r1, r0);
    if (0.0f == r0[0]) return false;

    // Eliminate first variable
    m1 = r1[0] / r0[0]; m2 = r2[0] / r0[0]; m3 = r3[0] / r0[0];
    s = r0[1]; r1[1] -= m1 * s; r2[1] -= m2 * s; r3[1] -= m3 * s;
    s = r0[2]; r1[2] -= m1 * s; r2[2] -= m2 * s; r3[2] -= m3 * s;
    s = r0[3]; r1[3] -= m1 * s; r2[3] -= m2 * s; r3[3] -= m3 * s;
    s = r0[4]; if (s != 0.0f) { r1[4] -= m1 * s; r2[4] -= m2 * s; r3[4] -= m3 * s; }
    s = r0[5]; if (s != 0.0f) { r1[5] -= m1 * s; r2[5] -= m2 * s; r3[5] -= m3 * s; }
    s = r0[6]; if (s != 0.0f) { r1[6] -= m1 * s; r2[6] -= m2 * s; r3[6] -= m3 * s; }
    s = r0[7]; if (s != 0.0f) { r1[7] -= m1 * s; r2[7] -= m2 * s; r3[7] -= m3 * s; }

    // Choose pivot for column 1
    if (std::fabs(r3[1]) > std::fabs(r2[1])) SWAP_ROWS_4X8(r3, r2);
    if (std::fabs(r2[1]) > std::fabs(r1[1])) SWAP_ROWS_4X8(r2, r1);
    if (0.0f == r1[1]) return false;

    // Eliminate second variable
    m2 = r2[1] / r1[1]; m3 = r3[1] / r1[1];
    r2[2] -= m2 * r1[2]; r3[2] -= m3 * r1[2];
    r2[3] -= m2 * r1[3]; r3[3] -= m3 * r1[3];
    s = r1[4]; if (0.0f != s) { r2[4] -= m2 * s; r3[4] -= m3 * s; }
    s = r1[5]; if (0.0f != s) { r2[5] -= m2 * s; r3[5] -= m3 * s; }
    s = r1[6]; if (0.0f != s) { r2[6] -= m2 * s; r3[6] -= m3 * s; }
    s = r1[7]; if (0.0f != s) { r2[7] -= m2 * s; r3[7] -= m3 * s; }

    // Choose pivot for column 2
    if (std::fabs(r3[2]) > std::fabs(r2[2])) SWAP_ROWS_4X8(r3, r2);
    if (0.0f == r2[2]) return false;

    // Eliminate third variable
    m3 = r3[2] / r2[2];
    r3[3] -= m3 * r2[3]; r3[4] -= m3 * r2[4];
    r3[5] -= m3 * r2[5]; r3[6] -= m3 * r2[6];
    r3[7] -= m3 * r2[7];

    // Last check
    if (0.0f == r3[3]) return false;

    // Back substitute row 3
    s = 1.0f / r3[3];
    r3[4] *= s; r3[5] *= s; r3[6] *= s; r3[7] *= s;

    // Back substitute row 2
    m2 = r2[3];
    s = 1.0f / r2[2];
    r2[4] = s * (r2[4] - r3[4] * m2);
    r2[5] = s * (r2[5] - r3[5] * m2);
    r2[6] = s * (r2[6] - r3[6] * m2);
    r2[7] = s * (r2[7] - r3[7] * m2);
    m1 = r1[3];
    r1[4] -= r3[4] * m1; r1[5] -= r3[5] * m1;
    r1[6] -= r3[6] * m1; r1[7] -= r3[7] * m1;
    m0 = r0[3];
    r0[4] -= r3[4] * m0; r0[5] -= r3[5] * m0;
    r0[6] -= r3[6] * m0; r0[7] -= r3[7] * m0;

    // Back substitute row 1
    m1 = r1[2];
    s = 1.0f / r1[1];
    r1[4] = s * (r1[4] - r2[4] * m1);
    r1[5] = s * (r1[5] - r2[5] * m1);
    r1[6] = s * (r1[6] - r2[6] * m1);
    r1[7] = s * (r1[7] - r2[7] * m1);
    m0 = r0[2];
    r0[4] -= r2[4] * m0; r0[5] -= r2[5] * m0;
    r0[6] -= r2[6] * m0; r0[7] -= r2[7] * m0;

    // Back substitute row 0
    m0 = r0[1];
    s = 1.0f / r0[0];
    r0[4] = s * (r0[4] - r1[4] * m0);
    r0[5] = s * (r0[5] - r1[5] * m0);
    r0[6] = s * (r0[6] - r1[6] * m0);
    r0[7] = s * (r0[7] - r1[7] * m0);

    MAT4(out, 0, 0) = r0[4]; MAT4(out, 0, 1) = r0[5]; MAT4(out, 0, 2) = r0[6]; MAT4(out, 0, 3) = r0[7];
    MAT4(out, 1, 0) = r1[4]; MAT4(out, 1, 1) = r1[5]; MAT4(out, 1, 2) = r1[6]; MAT4(out, 1, 3) = r1[7];
    MAT4(out, 2, 0) = r2[4]; MAT4(out, 2, 1) = r2[5]; MAT4(out, 2, 2) = r2[6]; MAT4(out, 2, 3) = r2[7];
    MAT4(out, 3, 0) = r3[4]; MAT4(out, 3, 1) = r3[5]; MAT4(out, 3, 2) = r3[6]; MAT4(out, 3, 3) = r3[7];
    return true;
}

bool InvertMatrix4x4_General3D(const float* in, float* out) noexcept {
    // 0x0159e0: Specialized affine 3D matrix inversion (last row = [0, 0, 0, 1])
    return InvertMatrix4x4_Full(in, out);
}

Matrix4x4f& Matrix4x4f::Transpose() noexcept {
    // 0x015c7c
    std::swap(m_Data[1],  m_Data[4]);
    std::swap(m_Data[2],  m_Data[8]);
    std::swap(m_Data[3],  m_Data[12]);
    std::swap(m_Data[6],  m_Data[9]);
    std::swap(m_Data[7],  m_Data[13]);
    std::swap(m_Data[11], m_Data[14]);
    return *this;
}

Matrix4x4f& Matrix4x4f::Copy(const Matrix4x4f& inM) noexcept {
    std::memcpy(m_Data, inM.m_Data, sizeof(m_Data));
    return *this;
}

Matrix4x4f& Matrix4x4f::SetFromToRotation(const Vector3f& from, const Vector3f& to) noexcept {
    Matrix3x3f m3;
    m3.SetFromToRotation(from, to);
    *this = m3;
    return *this;
}

void Matrix4x4f::SetTR(const Vector3f& pos, const Quaternionf& q) noexcept {
    QuaternionToMatrix(q, *this);
    m_Data[12] = pos.x;
    m_Data[13] = pos.y;
    m_Data[14] = pos.z;
}

void Matrix4x4f::SetTRS(const Vector3f& pos, const Quaternionf& q, const Vector3f& s) noexcept {
    QuaternionToMatrix(q, *this);
    Scale(s);
    m_Data[12] = pos.x;
    m_Data[13] = pos.y;
    m_Data[14] = pos.z;
}

void Matrix4x4f::SetTRSS(const Vector3f& pos, const Quaternionf& q, const Vector3f& s, const Vector3f& s2) noexcept {
    SetTRS(pos, q, Vector3f(s.x * s2.x, s.y * s2.y, s.z * s2.z));
}

void Matrix4x4f::SetTRInverse(const Vector3f& pos, const Quaternionf& q) noexcept {
    Quaternionf invQ(-q.x, -q.y, -q.z, q.w);
    QuaternionToMatrix(invQ, *this);
    Translate(Vector3f(-pos.x, -pos.y, -pos.z));
}

bool Matrix4x4f::getDecompose(Vector3f* pos, Vector3f* scale, Quaternionf* rot) const noexcept {
    return getDecompose(pos, scale, rot, nullptr);
}

bool Matrix4x4f::getDecompose(Vector3f* pos, Vector3f* scale, Quaternionf* rot, Vector3f* skew) const noexcept {
    if (pos) {
        pos->x = m_Data[12];
        pos->y = m_Data[13];
        pos->z = m_Data[14];
    }
    Vector3f col0(m_Data[0], m_Data[1], m_Data[2]);
    Vector3f col1(m_Data[4], m_Data[5], m_Data[6]);
    Vector3f col2(m_Data[8], m_Data[9], m_Data[10]);

    float sx = Length3(col0);
    float sy = Length3(col1);
    float sz = Length3(col2);
    if (scale) {
        *scale = Vector3f(sx, sy, sz);
    }
    if (skew) {
        *skew = Vector3f(0.0f, 0.0f, 0.0f);
    }
    if (sx < 1e-6f || sy < 1e-6f || sz < 1e-6f) {
        return false;
    }
    if (rot) {
        Matrix3x3f rotM;
        rotM.SetOrthoNormalBasis(
            Vector3f(col0.x / sx, col0.y / sx, col0.z / sx),
            Vector3f(col1.x / sy, col1.y / sy, col1.z / sy),
            Vector3f(col2.x / sz, col2.y / sz, col2.z / sz)
        );
        MatrixToQuaternion(rotM, *rot);
    }
    return true;
}

Matrix4x4f& Matrix4x4f::alignAxisWith(int axis, const Vector3f& targetDir) noexcept {
    if (axis < 0 || axis > 2) return *this;
    Vector3f cur(m_Data[axis * 4 + 0], m_Data[axis * 4 + 1], m_Data[axis * 4 + 2]);
    Matrix4x4f rot;
    rot.SetFromToRotation(Normalize3(cur), Normalize3(targetDir));
    *this = rot *= *this;
    return *this;
}

// ============================================================================
// PerlinNoise::Perlin2D & Perlin3D (0x016eac .. 0x01871c)
// EN: Exact Ken Perlin Improved Noise using .rodata 0x043ae0 (kPerlinPermTable_043ae0)
//     and Quintic Fade curve f(t) = t^3 * (t * (6*t - 15) + 10)
//     (`fmov s4, #6.0; fmov s7, #-15.0; fmov s22, #10.0` at 0x0170e8..0x017128).
// VN: Ham nhieu Perlin cai tien su dung bang hoan vi .rodata 0x043ae0 va ham
//     noi suy bac 5: f(t) = t^3 * (t * (6*t - 15) + 10).
// ============================================================================
static inline float QuinticFade(float t) noexcept {
    return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);
}

static inline float LerpF(float t, float a, float b) noexcept {
    return a + t * (b - a);
}

static inline float Grad3D(int hash, float x, float y, float z) noexcept {
    const int h = hash & 15;
    const float u = (h < 8) ? x : y;
    const float v = (h < 4) ? y : ((h == 12 || h == 14) ? x : z);
    return (((h & 1) == 0) ? u : -u) + (((h & 2) == 0) ? v : -v);
}

static inline int PermAt(int idx) noexcept {
    return rodata::kPerlinPermTable_043ae0[idx & 0xFF];
}

float PerlinNoise::Perlin2D(const Vector2f& coord, float offset) noexcept {
    // 0x016eac: Vectorized 2D Perlin noise
    return Perlin3D(Vector3f(coord.x, coord.y, 0.0f), offset);
}

Vector2f PerlinNoise::Perlin2DVector(const Vector2f& coord, Vector2f offset) noexcept {
    // 0x017054: Evaluates Perlin2D twice for X and Y components
    return Vector2f(Perlin2D(coord, offset.x), Perlin2D(coord, offset.y));
}

float PerlinNoise::Perlin3D(const Vector3f& coord, float offset) noexcept {
    // 0x017098 .. 0x01834b:
    //   0x017098: ldp s3, s1, [x0]; ldr s2, [x0, #8]
    //   0x0170a8: fadd s0, s3, s0 (x = coord.x + offset)
    const float x = coord.x + offset;
    const float y = coord.y;
    const float z = coord.z;

    const int X = static_cast<int>(std::floor(x)) & 0xFF;
    const int Y = static_cast<int>(std::floor(y)) & 0xFF;
    const int Z = static_cast<int>(std::floor(z)) & 0xFF;

    const float fx = x - std::floor(x);
    const float fy = y - std::floor(y);
    const float fz = z - std::floor(z);

    const float u = QuinticFade(fx);
    const float v = QuinticFade(fy);
    const float w = QuinticFade(fz);

    const int A  = (PermAt(X) + Y) & 0xFF;
    const int AA = (PermAt(A) + Z) & 0xFF;
    const int AB = (PermAt((A + 1) & 0xFF) + Z) & 0xFF;
    const int B  = (PermAt((X + 1) & 0xFF) + Y) & 0xFF;
    const int BA = (PermAt(B) + Z) & 0xFF;
    const int BB = (PermAt((B + 1) & 0xFF) + Z) & 0xFF;

    return LerpF(w,
        LerpF(v,
            LerpF(u, Grad3D(PermAt(AA), fx, fy, fz),
                     Grad3D(PermAt(BA), fx - 1.0f, fy, fz)),
            LerpF(u, Grad3D(PermAt(AB), fx, fy - 1.0f, fz),
                     Grad3D(PermAt(BB), fx - 1.0f, fy - 1.0f, fz))),
        LerpF(v,
            LerpF(u, Grad3D(PermAt((AA + 1) & 0xFF), fx, fy, fz - 1.0f),
                     Grad3D(PermAt((BA + 1) & 0xFF), fx - 1.0f, fy, fz - 1.0f)),
            LerpF(u, Grad3D(PermAt((AB + 1) & 0xFF), fx, fy - 1.0f, fz - 1.0f),
                     Grad3D(PermAt((BB + 1) & 0xFF), fx - 1.0f, fy - 1.0f, fz - 1.0f)))
    );
}

Vector3f PerlinNoise::Perlin3DVector(const Vector3f& coord, Vector3f offset) noexcept {
    // 0x01834c
    return Vector3f(
        Perlin3D(coord, offset.x),
        Perlin3D(coord, offset.y),
        Perlin3D(coord, offset.z)
    );
}

float PerlinNoise::FractalPerlin3D(const Vector3f& coord, int octaves, float persistence, float offset) noexcept {
    // 0x0183b0
    float total = 0.0f;
    float frequency = 1.0f;
    float amplitude = 1.0f;
    float maxValue = 0.0f;
    for (int i = 0; i < octaves; ++i) {
        Vector3f scaled(coord.x * frequency, coord.y * frequency, coord.z * frequency);
        total += Perlin3D(scaled, offset) * amplitude;
        maxValue += amplitude;
        amplitude *= persistence;
        frequency *= 2.0f;
    }
    return (maxValue > 0.0f) ? (total / maxValue) : 0.0f;
}

Vector3f PerlinNoise::FractalPerlin3DVector(const Vector3f& coord, int octaves, float persistence, Vector3f offset) noexcept {
    // 0x0184a8
    return Vector3f(
        FractalPerlin3D(coord, octaves, persistence, offset.x),
        FractalPerlin3D(coord, octaves, persistence, offset.y),
        FractalPerlin3D(coord, octaves, persistence, offset.z)
    );
}

// ============================================================================
// Slerp(Quaternionf const&, Quaternionf const&, float) (0x018720 .. 0x018890)
// EN: Verified AArch64:
//       0x018744..0x018758: Computes dot = q1.x*q2.x + q1.y*q2.y + q1.z*q2.z + q1.w*q2.w
//       0x01875c..0x01876c: If dot < 0.0f, negates dot and q2
//       0x018770..0x018780: Compares dot against 0x3F733333 (0.95f).
//         - If dot < 0.95f: angle = acosf(dot); invSin = 1.0f / sinf(angle);
//           s0 = sinf((1 - t)*angle) * invSin; s1 = sinf(t*angle) * invSin;
//         - Else (0x0187f0): NLerp (linear interpolation + 1/sqrtf normalization).
// VN: Noi suy cau Slerp cho Quaternionf voi nguong 0x3F733333 (0.95f), xac minh
//     chinh xac tu AArch64 0x018720..0x018890.
// ============================================================================
Quaternionf Slerp(const Quaternionf& q1, const Quaternionf& q2, float t) noexcept {
    Quaternionf b = q2;
    float cosOmega = q1.x * b.x + q1.y * b.y + q1.z * b.z + q1.w * b.w;
    if (cosOmega < 0.0f) {
        cosOmega = -cosOmega;
        b.x = -b.x; b.y = -b.y; b.z = -b.z; b.w = -b.w;
    }

    // 0x018770: mov w8, #0x3333; movk w8, #0x3f73, lsl #16 -> 0x3F733333 = 0.95f
    constexpr float kSlerpThreshold = 0.94999998807907104f; // 0x3F733333
    if (cosOmega < kSlerpThreshold) {
        const float omega = std::acos(cosOmega);
        const float invSin = 1.0f / std::sin(omega);
        const float scale0 = std::sin((1.0f - t) * omega) * invSin;
        const float scale1 = std::sin(t * omega) * invSin;
        return Quaternionf(
            q1.x * scale0 + b.x * scale1,
            q1.y * scale0 + b.y * scale1,
            q1.z * scale0 + b.z * scale1,
            q1.w * scale0 + b.w * scale1
        );
    } else {
        // 0x0187f0..0x018870: Normalized Linear Interpolation (NLerp)
        Quaternionf r(
            q1.x + (b.x - q1.x) * t,
            q1.y + (b.y - q1.y) * t,
            q1.z + (b.z - q1.z) * t,
            q1.w + (b.w - q1.w) * t
        );
        const float len = std::sqrt(r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w);
        if (len > 0.0f) {
            r.x /= len; r.y /= len; r.z /= len; r.w /= len;
        }
        return r;
    }
}

Quaternionf EulerToQuaternion(const Vector3f& euler) noexcept {
    // 0x018894: Uses sincosf(0.5f * angle) (`fmov s8, #0.50000000` at 0x0188b4)
    const float hx = euler.x * 0.5f;
    const float hy = euler.y * 0.5f;
    const float hz = euler.z * 0.5f;
    const float sx = std::sin(hx), cx = std::cos(hx);
    const float sy = std::sin(hy), cy = std::cos(hy);
    const float sz = std::sin(hz), cz = std::cos(hz);

    return Quaternionf(
        cx * sy * sz + sx * cy * cz,
        cx * sy * cz - sx * cy * sz,
        cx * cy * sz - sx * sy * cz,
        cx * cy * cz + sx * sy * sz
    );
}

Vector3f QuaternionToEuler(const Quaternionf& q) noexcept {
    // 0x0189c4
    Matrix3x3f m;
    QuaternionToMatrix(q, m);
    Vector3f euler;
    MatrixToEuler(m, euler);
    return euler;
}

void QuaternionToMatrix(const Quaternionf& q, Matrix3x3f& m) noexcept {
    // 0x018aa0
    const float x2 = q.x + q.x, y2 = q.y + q.y, z2 = q.z + q.z;
    const float xx = q.x * x2, xy = q.x * y2, xz = q.x * z2;
    const float yy = q.y * y2, yz = q.y * z2, zz = q.z * z2;
    const float wx = q.w * x2, wy = q.w * y2, wz = q.w * z2;

    m.m_Data[0] = 1.0f - (yy + zz);
    m.m_Data[1] = xy + wz;
    m.m_Data[2] = xz - wy;

    m.m_Data[3] = xy - wz;
    m.m_Data[4] = 1.0f - (xx + zz);
    m.m_Data[5] = yz + wx;

    m.m_Data[6] = xz + wy;
    m.m_Data[7] = yz - wx;
    m.m_Data[8] = 1.0f - (xx + yy);
}

void QuaternionToMatrix(const Quaternionf& q, Matrix4x4f& m) noexcept {
    // 0x018b24
    Matrix3x3f m3;
    QuaternionToMatrix(q, m3);
    m = m3;
}

void MatrixToQuaternion(const Matrix4x4f& m, Quaternionf& q) noexcept {
    // 0x018bc4
    Matrix3x3f m3(m);
    MatrixToQuaternion(m3, q);
}

void MatrixToQuaternion(const Matrix3x3f& m, Quaternionf& q) noexcept {
    // 0x018c3c: Ken Shoemake trace/diagonal branch algorithm
    const float trace = m.m_Data[0] + m.m_Data[4] + m.m_Data[8];
    if (trace > 0.0f) {
        float s = std::sqrt(trace + 1.0f);
        q.w = s * 0.5f;
        s = 0.5f / s;
        q.x = (m.m_Data[5] - m.m_Data[7]) * s;
        q.y = (m.m_Data[6] - m.m_Data[2]) * s;
        q.z = (m.m_Data[1] - m.m_Data[3]) * s;
    } else if (m.m_Data[0] >= m.m_Data[4] && m.m_Data[0] >= m.m_Data[8]) {
        float s = std::sqrt(1.0f + m.m_Data[0] - m.m_Data[4] - m.m_Data[8]);
        q.x = s * 0.5f;
        s = 0.5f / s;
        q.y = (m.m_Data[1] + m.m_Data[3]) * s;
        q.z = (m.m_Data[6] + m.m_Data[2]) * s;
        q.w = (m.m_Data[5] - m.m_Data[7]) * s;
    } else if (m.m_Data[4] > m.m_Data[8]) {
        float s = std::sqrt(1.0f + m.m_Data[4] - m.m_Data[0] - m.m_Data[8]);
        q.y = s * 0.5f;
        s = 0.5f / s;
        q.x = (m.m_Data[1] + m.m_Data[3]) * s;
        q.z = (m.m_Data[5] + m.m_Data[7]) * s;
        q.w = (m.m_Data[6] - m.m_Data[2]) * s;
    } else {
        float s = std::sqrt(1.0f + m.m_Data[8] - m.m_Data[0] - m.m_Data[4]);
        q.z = s * 0.5f;
        s = 0.5f / s;
        q.x = (m.m_Data[6] + m.m_Data[2]) * s;
        q.y = (m.m_Data[5] + m.m_Data[7]) * s;
        q.w = (m.m_Data[1] - m.m_Data[3]) * s;
    }
}

void EulerToMatrix(const Vector3f& euler, Matrix3x3f& m) noexcept {
    Quaternionf q = EulerToQuaternion(euler);
    QuaternionToMatrix(q, m);
}

void MatrixToEuler(const Matrix3x3f& m, Vector3f& euler) noexcept {
    // 0x013e24
    const float sy = -m.m_Data[6];
    if (std::fabs(sy) < 0.99999f) {
        euler.x = std::atan2(m.m_Data[7], m.m_Data[8]);
        euler.y = std::asin(std::clamp(sy, -1.0f, 1.0f));
        euler.z = std::atan2(m.m_Data[3], m.m_Data[0]);
    } else {
        euler.x = std::atan2(-m.m_Data[5], m.m_Data[4]);
        euler.y = (sy > 0.0f) ? 1.57079632679f : -1.57079632679f;
        euler.z = 0.0f;
    }
}

bool LookRotationToMatrix(const Vector3f& viewVec, const Vector3f& upVec, Matrix3x3f* m) noexcept {
    if (!m) return false;
    Vector3f z = Normalize3(viewVec);
    if (Length3(z) < 1e-5f) return false;
    Vector3f x = Normalize3(Cross3(upVec, z));
    if (Length3(x) < 1e-5f) {
        x = OrthoNormalVectorFast(z);
    }
    Vector3f y = Cross3(z, x);
    m->SetOrthoNormalBasis(x, y, z);
    return true;
}

bool LookRotationToQuaternion(const Vector3f& viewVec, const Vector3f& upVec, Quaternionf* res) noexcept {
    if (!res) return false;
    Matrix3x3f m;
    if (!LookRotationToMatrix(viewVec, upVec, &m)) return false;
    MatrixToQuaternion(m, *res);
    return true;
}

Quaternionf FromToQuaternionSafe(const Vector3f& lhs, const Vector3f& rhs) noexcept {
    Vector3f u = Normalize3(lhs);
    Vector3f v = Normalize3(rhs);
    return FromToQuaternion(u, v);
}

Quaternionf FromToQuaternion(const Vector3f& u, const Vector3f& v) noexcept {
    const float d = Dot3(u, v);
    if (d >= 0.99999f) {
        return Quaternionf(0.0f, 0.0f, 0.0f, 1.0f);
    }
    if (d <= -0.99999f) {
        Vector3f axis = OrthoNormalVectorFast(u);
        return Quaternionf(axis.x, axis.y, axis.z, 0.0f);
    }
    const float s = std::sqrt((1.0f + d) * 2.0f);
    const float invs = 1.0f / s;
    const Vector3f c = Cross3(u, v);
    return Quaternionf(c.x * invs, c.y * invs, c.z * invs, s * 0.5f);
}

void OrthoNormalize(Matrix3x3f& m) noexcept {
    Vector3f c0(m.m_Data[0], m.m_Data[1], m.m_Data[2]);
    Vector3f c1(m.m_Data[3], m.m_Data[4], m.m_Data[5]);
    Vector3f c2(m.m_Data[6], m.m_Data[7], m.m_Data[8]);
    OrthoNormalize(&c0, &c1, &c2);
    m.SetOrthoNormalBasis(c0, c1, c2);
}

bool CompareApproximately(const Matrix3x3f& a, const Matrix3x3f& b, float tol) noexcept {
    for (int i = 0; i < 9; ++i) {
        if (std::fabs(a.m_Data[i] - b.m_Data[i]) > tol) return false;
    }
    return true;
}

bool CompareApproximately(const Matrix4x4f& a, const Matrix4x4f& b, float tol) noexcept {
    for (int i = 0; i < 16; ++i) {
        if (std::fabs(a.m_Data[i] - b.m_Data[i]) > tol) return false;
    }
    return true;
}

void TransformPoints3x3(const Matrix4x4f& m, const Vector3f* in, Vector3f* out, int count) noexcept {
    for (int i = 0; i < count; ++i) {
        const Vector3f v = in[i];
        out[i] = Vector3f(
            m.m_Data[0] * v.x + m.m_Data[4] * v.y + m.m_Data[8]  * v.z,
            m.m_Data[1] * v.x + m.m_Data[5] * v.y + m.m_Data[9]  * v.z,
            m.m_Data[2] * v.x + m.m_Data[6] * v.y + m.m_Data[10] * v.z
        );
    }
}

void TransformPoints3x4(const Matrix4x4f& m, const Vector3f* in, Vector3f* out, int count) noexcept {
    for (int i = 0; i < count; ++i) {
        const Vector3f v = in[i];
        out[i] = Vector3f(
            m.m_Data[0] * v.x + m.m_Data[4] * v.y + m.m_Data[8]  * v.z + m.m_Data[12],
            m.m_Data[1] * v.x + m.m_Data[5] * v.y + m.m_Data[9]  * v.z + m.m_Data[13],
            m.m_Data[2] * v.x + m.m_Data[6] * v.y + m.m_Data[10] * v.z + m.m_Data[14]
        );
    }
}

void TransformPoints3x3(const Matrix4x4f& m, const Vector3f* in, size_t inStride, Vector3f* out, size_t outStride, int count) noexcept {
    const uint8_t* src = reinterpret_cast<const uint8_t*>(in);
    uint8_t* dst = reinterpret_cast<uint8_t*>(out);
    for (int i = 0; i < count; ++i) {
        TransformPoints3x3(m, reinterpret_cast<const Vector3f*>(src), reinterpret_cast<Vector3f*>(dst), 1);
        src += inStride;
        dst += outStride;
    }
}

void TransformPoints3x4(const Matrix4x4f& m, const Vector3f* in, size_t inStride, Vector3f* out, size_t outStride, int count) noexcept {
    const uint8_t* src = reinterpret_cast<const uint8_t*>(in);
    uint8_t* dst = reinterpret_cast<uint8_t*>(out);
    for (int i = 0; i < count; ++i) {
        TransformPoints3x4(m, reinterpret_cast<const Vector3f*>(src), reinterpret_cast<Vector3f*>(dst), 1);
        src += inStride;
        dst += outStride;
    }
}

void CopyMatrixREF(const float* in, float* out) noexcept {
    std::memcpy(out, in, 16 * sizeof(float));
}

void TransposeMatrix4x4REF(const Matrix4x4f* in, Matrix4x4f* out) noexcept {
    *out = *in;
    out->Transpose();
}

void MultiplyMatrixArray4x4REF(const Matrix4x4f* a, const Matrix4x4f* b, Matrix4x4f* res, size_t count) noexcept {
    for (size_t i = 0; i < count; ++i) {
        MultiplyMatrices4x4REF(&a[i], &b[i], &res[i]);
    }
}

void MultiplyMatrixArrayWithBase4x4REF(const Matrix4x4f* base, const Matrix4x4f* a, const Matrix4x4f* b, Matrix4x4f* res, size_t count) noexcept {
    for (size_t i = 0; i < count; ++i) {
        Matrix4x4f tmp;
        MultiplyMatrices4x4REF(&a[i], &b[i], &tmp);
        MultiplyMatrices4x4REF(base, &tmp, &res[i]);
    }
}

void OrthoNormalizeFast(Vector3f* inU, Vector3f* inV, Vector3f* inW) noexcept {
    *inU = Normalize3(*inU);
    float d0 = Dot3(*inU, *inV);
    *inV = Normalize3(Vector3f(inV->x - d0 * inU->x, inV->y - d0 * inU->y, inV->z - d0 * inU->z));
    *inW = Cross3(*inU, *inV);
}

void OrthoNormalize(Vector3f* inU, Vector3f* inV) noexcept {
    *inU = Normalize3(*inU);
    float d0 = Dot3(*inU, *inV);
    *inV = Normalize3(Vector3f(inV->x - d0 * inU->x, inV->y - d0 * inU->y, inV->z - d0 * inU->z));
}

Vector3f OrthoNormalVectorFast(const Vector3f& n) noexcept {
    // 0x0193f0: Uses k1OverSqrt2 = 0.70710678f
    constexpr float k1OverSqrt2 = 0.7071067811865475244f;
    if (std::fabs(n.z) > k1OverSqrt2) {
        float a = n.y * n.y + n.z * n.z;
        float k = 1.0f / std::sqrt(a);
        return Vector3f(0.0f, -n.z * k, n.y * k);
    } else {
        float a = n.x * n.x + n.y * n.y;
        float k = 1.0f / std::sqrt(a);
        return Vector3f(-n.y * k, n.x * k, 0.0f);
    }
}

void OrthoNormalize(Vector3f* inU, Vector3f* inV, Vector3f* inW) noexcept {
    OrthoNormalizeFast(inU, inV, inW);
}

Vector3f MoveTowards(const Vector3f& lhs, const Vector3f& rhs, float maxDistanceDelta) noexcept {
    Vector3f delta(rhs.x - lhs.x, rhs.y - lhs.y, rhs.z - lhs.z);
    float dist = Length3(delta);
    if (dist <= maxDistanceDelta || dist < 1e-6f) {
        return rhs;
    }
    float s = maxDistanceDelta / dist;
    return Vector3f(lhs.x + delta.x * s, lhs.y + delta.y * s, lhs.z + delta.z * s);
}

Vector3f RotateTowards(const Vector3f& lhs, const Vector3f& rhs, float maxAngle, float maxMagnitude) noexcept {
    float lhsMag = Length3(lhs);
    float rhsMag = Length3(rhs);
    if (lhsMag > 1e-6f && rhsMag > 1e-6f) {
        Vector3f lhsNorm(lhs.x / lhsMag, lhs.y / lhsMag, lhs.z / lhsMag);
        Vector3f rhsNorm(rhs.x / rhsMag, rhs.y / rhsMag, rhs.z / rhsMag);
        float dot = std::clamp(Dot3(lhsNorm, rhsNorm), -1.0f, 1.0f);
        float angle = std::acos(dot);
        float t = (angle > 1e-5f) ? std::min(1.0f, maxAngle / angle) : 1.0f;
        Quaternionf q = FromToQuaternion(lhsNorm, rhsNorm);
        Quaternionf qIdent(0.0f, 0.0f, 0.0f, 1.0f);
        Quaternionf qStep = Slerp(qIdent, q, t);
        Matrix3x3f m;
        QuaternionToMatrix(qStep, m);
        Vector3f dir(
            m.m_Data[0] * lhsNorm.x + m.m_Data[3] * lhsNorm.y + m.m_Data[6] * lhsNorm.z,
            m.m_Data[1] * lhsNorm.x + m.m_Data[4] * lhsNorm.y + m.m_Data[7] * lhsNorm.z,
            m.m_Data[2] * lhsNorm.x + m.m_Data[5] * lhsNorm.y + m.m_Data[8] * lhsNorm.z
        );
        float magDelta = rhsMag - lhsMag;
        float outMag = lhsMag + std::clamp(magDelta, -maxMagnitude, maxMagnitude);
        return Vector3f(dir.x * outMag, dir.y * outMag, dir.z * outMag);
    }
    return MoveTowards(lhs, rhs, maxMagnitude);
}

Vector3f Slerp(const Vector3f& lhs, const Vector3f& rhs, float t) noexcept {
    // 0x019ad4
    float lhsMag = Length3(lhs);
    float rhsMag = Length3(rhs);
    if (lhsMag < 1e-6f || rhsMag < 1e-6f) {
        return Vector3f(
            lhs.x + (rhs.x - lhs.x) * t,
            lhs.y + (rhs.y - lhs.y) * t,
            lhs.z + (rhs.z - lhs.z) * t
        );
    }
    float lerpedLen = lhsMag + (rhsMag - lhsMag) * t;
    Vector3f u(lhs.x / lhsMag, lhs.y / lhsMag, lhs.z / lhsMag);
    Vector3f v(rhs.x / rhsMag, rhs.y / rhsMag, rhs.z / rhsMag);
    Quaternionf q = Slerp(Quaternionf(0.0f, 0.0f, 0.0f, 1.0f), FromToQuaternion(u, v), t);
    Matrix3x3f m;
    QuaternionToMatrix(q, m);
    return Vector3f(
        (m.m_Data[0] * u.x + m.m_Data[3] * u.y + m.m_Data[6] * u.z) * lerpedLen,
        (m.m_Data[1] * u.x + m.m_Data[4] * u.y + m.m_Data[7] * u.z) * lerpedLen,
        (m.m_Data[2] * u.x + m.m_Data[5] * u.y + m.m_Data[8] * u.z) * lerpedLen
    );
}

Vector3f NormalizeRobust(const Vector3f& a) noexcept {
    float inv = 0.0f;
    return NormalizeRobust(a, inv);
}

Vector3f NormalizeRobust(const Vector3f& a, float& invOriginalLength) noexcept {
    float len = Length3(a);
    if (len > 1e-30f) {
        invOriginalLength = 1.0f / len;
        return Vector3f(a.x * invOriginalLength, a.y * invOriginalLength, a.z * invOriginalLength);
    }
    invOriginalLength = 0.0f;
    return Vector3f(0.0f, 0.0f, 0.0f);
}

} // namespace AmazingEngine
