// ============================================================================
// File: gaia_math_and_perlin.h
// Target: libgaia_lib.so (329,704 bytes)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Description:
//   EN: Clean-room C++17 declarations for AmazingEngine GAIA Math, Geometry,
//       Matrix3x3f, Matrix4x4f, Quaternionf, Vector2f/3f, and PerlinNoise
//       (.text 0x013164 .. 0x019fc0).
//   VN: Khai bao C++17 chuan clean-room cho he thong Toan hoc, Hinh hoc,
//       Matrix3x3f, Matrix4x4f, Quaternionf, Vector2f/3f va PerlinNoise.
// ============================================================================

#pragma once

#include "gaia_types.h"

namespace AmazingEngine {

// Matrix3x3f & Euler/Rotation helpers (0x013d4c .. 0x014214)
void EulerToMatrix(const Vector3f& euler, Matrix3x3f& m) noexcept;                     // 0x013d4c
void MatrixToEuler(const Matrix3x3f& m, Vector3f& euler) noexcept;                     // 0x013e24
bool LookRotationToMatrix(const Vector3f& viewVec, const Vector3f& upVec, Matrix3x3f* m) noexcept; // 0x014060
void OrthoNormalize(Matrix3x3f& m) noexcept;                                           // 0x014208
bool CompareApproximately(const Matrix3x3f& a, const Matrix3x3f& b, float tol = 1e-5f) noexcept; // 0x014214

// Matrix4x4f inversion, multiplication & point transformation (0x01490c .. 0x016df8)
void MultiplyMatrices4x4REF(const Matrix4x4f* lhs, const Matrix4x4f* rhs, Matrix4x4f* res) noexcept; // 0x01490c
void MultiplyMatrices3x4(const Matrix4x4f& lhs, const Matrix4x4f& rhs, Matrix4x4f& res) noexcept;    // 0x014a18
bool InvertMatrix4x4_Full(const float* m, float* out) noexcept;                        // 0x0151e0
bool InvertMatrix4x4_General3D(const float* in, float* out) noexcept;                  // 0x0159e0
bool CompareApproximately(const Matrix4x4f& a, const Matrix4x4f& b, float tol = 1e-5f) noexcept;     // 0x015d98
void TransformPoints3x3(const Matrix4x4f& m, const Vector3f* in, Vector3f* out, int count) noexcept; // 0x0162dc
void TransformPoints3x4(const Matrix4x4f& m, const Vector3f* in, Vector3f* out, int count) noexcept; // 0x01647c
void TransformPoints3x3(const Matrix4x4f& m, const Vector3f* in, size_t inStride, Vector3f* out, size_t outStride, int count) noexcept; // 0x01660c
void TransformPoints3x4(const Matrix4x4f& m, const Vector3f* in, size_t inStride, Vector3f* out, size_t outStride, int count) noexcept; // 0x0166ec
void CopyMatrixREF(const float* in, float* out) noexcept;                              // 0x016d38
void TransposeMatrix4x4REF(const Matrix4x4f* in, Matrix4x4f* out) noexcept;            // 0x016d4c
void MultiplyMatrixArray4x4REF(const Matrix4x4f* a, const Matrix4x4f* b, Matrix4x4f* res, size_t count) noexcept; // 0x016da0
void MultiplyMatrixArrayWithBase4x4REF(const Matrix4x4f* base, const Matrix4x4f* a, const Matrix4x4f* b, Matrix4x4f* res, size_t count) noexcept; // 0x016df8

// Quaternionf Slerp & conversions (0x018720 .. 0x019034)
Quaternionf Slerp(const Quaternionf& q1, const Quaternionf& q2, float t) noexcept;     // 0x018720
Quaternionf EulerToQuaternion(const Vector3f& euler) noexcept;                         // 0x018894
Vector3f QuaternionToEuler(const Quaternionf& q) noexcept;                             // 0x0189c4
void QuaternionToMatrix(const Quaternionf& q, Matrix3x3f& m) noexcept;                 // 0x018aa0
void QuaternionToMatrix(const Quaternionf& q, Matrix4x4f& m) noexcept;                 // 0x018b24
void MatrixToQuaternion(const Matrix4x4f& m, Quaternionf& q) noexcept;                 // 0x018bc4
void MatrixToQuaternion(const Matrix3x3f& m, Quaternionf& q) noexcept;                 // 0x018c3c
bool LookRotationToQuaternion(const Vector3f& viewVec, const Vector3f& upVec, Quaternionf* res) noexcept; // 0x018e1c
Quaternionf FromToQuaternionSafe(const Vector3f& lhs, const Vector3f& rhs) noexcept;   // 0x018eac
Quaternionf FromToQuaternion(const Vector3f& lhs, const Vector3f& rhs) noexcept;       // 0x019034

// Vector3f OrthoNormalize, Slerp & Robust Normalization (0x019154 .. 0x019f98)
void OrthoNormalizeFast(Vector3f* inU, Vector3f* inV, Vector3f* inW) noexcept;         // 0x019154
void OrthoNormalize(Vector3f* inU, Vector3f* inV) noexcept;                            // 0x019280
Vector3f OrthoNormalVectorFast(const Vector3f& n) noexcept;                            // 0x0193f0
void OrthoNormalize(Vector3f* inU, Vector3f* inV, Vector3f* inW) noexcept;             // 0x01946c
Vector3f MoveTowards(const Vector3f& lhs, const Vector3f& rhs, float maxDistanceDelta) noexcept; // 0x0196c0
Vector3f RotateTowards(const Vector3f& lhs, const Vector3f& rhs, float maxAngle, float maxMagnitude) noexcept; // 0x019748
Vector3f Slerp(const Vector3f& lhs, const Vector3f& rhs, float t) noexcept;            // 0x019ad4
Vector3f NormalizeRobust(const Vector3f& a) noexcept;                                  // 0x019df4
Vector3f NormalizeRobust(const Vector3f& a, float& invOriginalLength) noexcept;        // 0x019f98

} // namespace AmazingEngine
