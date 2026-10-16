// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 3x3 Matrix Transformation Pipeline
// File: skity_matrix.h
// Description: Skity 3x3 affine and projective transformation matrix with
//              exact AArch64 opcode alignments (Set9, MapPoints, HasPersp).
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_MATRIX_H_
#define NEXTAI_OPENCUT_SKITY_MATRIX_H_

#include "skity_geometry.h"

namespace skity {

class Matrix {
public:
    enum MatrixIndex {
        kScaleX = 0,
        kSkewX  = 1,
        kTransX = 2,
        kSkewY  = 3,
        kScaleY = 4,
        kTransY = 5,
        kPersp0 = 6,
        kPersp1 = 7,
        kPersp2 = 8,
    };

    Matrix();
    ~Matrix() = default;

    // Opcode 0xeece8: Set9 (loads 9 float values into matrix)
    void Set9(const float* buffer);
    void Get9(float* buffer) const;

    // Reset to Identity matrix
    void SetIdentity();
    bool IsIdentity() const;

    // Translation, Scale, Rotation setup
    void SetTranslate(float dx, float dy);
    void SetScale(float sx, float sy);
    void SetScale(float sx, float sy, float px, float py);
    void SetRotate(float deg);
    void SetRotate(float deg, float px, float py);

    // Opcode 0xefec0: PreRotate (M' = M * R)
    void PreRotate(float deg);
    void PreRotate(float deg, float px, float py);
    void PreScale(float sx, float sy);
    void PreTranslate(float dx, float dy);
    void PreConcat(const Matrix& other);

    // Opcode 0xeff18: PostRotate (M' = R * M)
    void PostRotate(float deg);
    void PostRotate(float deg, float px, float py);
    void PostScale(float sx, float sy);
    void PostTranslate(float dx, float dy);
    void PostConcat(const Matrix& other);

    // Concat / Multiply (M = A * B)
    static void Concat(Matrix* out, const Matrix& a, const Matrix& b);

    // Opcode 0xeecac: HasPersp
    // Checks if persp0 != 0, persp1 != 0, or persp2 != 1
    bool HasPersp() const;

    // Matrix Inversion (det != 0)
    bool Invert(Matrix* inverse) const;

    // Opcode 0xef72c: MapPoints
    // Vectorized 2D point transformation with perspective divide
    void MapPoints(Vec2* dst, const Vec2* src, int count) const;
    Vec2 MapPoint(const Vec2& pt) const;

    // Map bounding rectangle
    Rect MapRect(const Rect& src) const;

    // Direct element access
    float operator[](int index) const { return mat_[index]; }
    float& operator[](int index) { return mat_[index]; }

private:
    float mat_[9];
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_MATRIX_H_
