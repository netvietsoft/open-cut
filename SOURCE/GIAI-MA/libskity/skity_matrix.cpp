// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 3x3 Matrix Transformation Pipeline
// File: skity_matrix.cpp
// Description: Implementation of 3x3 affine and projective transformation matrix.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_matrix.h"

namespace skity {

Matrix::Matrix() {
    SetIdentity();
}

/**
 * @brief Set9: Sets matrix from an array of 9 float values.
 * EN: Matches AArch64 opcode 0xeece8.
 * VN: Khớp opcode AArch64 0xeece8. Nạp 9 giá trị phần tử vào ma trận biến đổi.
 */
void Matrix::Set9(const float* buffer) {
    if (!buffer) return;
    for (int i = 0; i < 9; ++i) {
        mat_[i] = buffer[i];
    }
}

void Matrix::Get9(float* buffer) const {
    if (!buffer) return;
    for (int i = 0; i < 9; ++i) {
        buffer[i] = mat_[i];
    }
}

void Matrix::SetIdentity() {
    mat_[kScaleX] = 1.0f; mat_[kSkewX]  = 0.0f; mat_[kTransX] = 0.0f;
    mat_[kSkewY]  = 0.0f; mat_[kScaleY] = 1.0f; mat_[kTransY] = 0.0f;
    mat_[kPersp0] = 0.0f; mat_[kPersp1] = 0.0f; mat_[kPersp2] = 1.0f;
}

bool Matrix::IsIdentity() const {
    return mat_[kScaleX] == 1.0f && mat_[kSkewX]  == 0.0f && mat_[kTransX] == 0.0f &&
           mat_[kSkewY]  == 0.0f && mat_[kScaleY] == 1.0f && mat_[kTransY] == 0.0f &&
           mat_[kPersp0] == 0.0f && mat_[kPersp1] == 0.0f && mat_[kPersp2] == 1.0f;
}

void Matrix::SetTranslate(float dx, float dy) {
    mat_[kScaleX] = 1.0f; mat_[kSkewX]  = 0.0f; mat_[kTransX] = dx;
    mat_[kSkewY]  = 0.0f; mat_[kScaleY] = 1.0f; mat_[kTransY] = dy;
    mat_[kPersp0] = 0.0f; mat_[kPersp1] = 0.0f; mat_[kPersp2] = 1.0f;
}

void Matrix::SetScale(float sx, float sy) {
    mat_[kScaleX] = sx;   mat_[kSkewX]  = 0.0f; mat_[kTransX] = 0.0f;
    mat_[kSkewY]  = 0.0f; mat_[kScaleY] = sy;   mat_[kTransY] = 0.0f;
    mat_[kPersp0] = 0.0f; mat_[kPersp1] = 0.0f; mat_[kPersp2] = 1.0f;
}

void Matrix::SetScale(float sx, float sy, float px, float py) {
    mat_[kScaleX] = sx;   mat_[kSkewX]  = 0.0f; mat_[kTransX] = px - sx * px;
    mat_[kSkewY]  = 0.0f; mat_[kScaleY] = sy;   mat_[kTransY] = py - sy * py;
    mat_[kPersp0] = 0.0f; mat_[kPersp1] = 0.0f; mat_[kPersp2] = 1.0f;
}

void Matrix::SetRotate(float deg) {
    float rad = deg * (3.14159265358979323846f / 180.0f);
    float c = std::cos(rad);
    float s = std::sin(rad);
    mat_[kScaleX] = c;    mat_[kSkewX]  = -s;   mat_[kTransX] = 0.0f;
    mat_[kSkewY]  = s;    mat_[kScaleY] = c;    mat_[kTransY] = 0.0f;
    mat_[kPersp0] = 0.0f; mat_[kPersp1] = 0.0f; mat_[kPersp2] = 1.0f;
}

void Matrix::SetRotate(float deg, float px, float py) {
    float rad = deg * (3.14159265358979323846f / 180.0f);
    float c = std::cos(rad);
    float s = std::sin(rad);
    mat_[kScaleX] = c;
    mat_[kSkewX]  = -s;
    mat_[kTransX] = s * py + (1.0f - c) * px;
    mat_[kSkewY]  = s;
    mat_[kScaleY] = c;
    mat_[kTransY] = -s * px + (1.0f - c) * py;
    mat_[kPersp0] = 0.0f;
    mat_[kPersp1] = 0.0f;
    mat_[kPersp2] = 1.0f;
}

/**
 * @brief PreRotate: Multiplies matrix on the right by rotation (M' = M * R).
 * EN: Matches AArch64 opcode 0xefec0.
 * VN: Khớp opcode AArch64 0xefec0. Nhân phải ma trận với phép quay quanh gốc tọa độ.
 */
void Matrix::PreRotate(float deg) {
    Matrix r;
    r.SetRotate(deg);
    PreConcat(r);
}

void Matrix::PreRotate(float deg, float px, float py) {
    Matrix r;
    r.SetRotate(deg, px, py);
    PreConcat(r);
}

void Matrix::PreScale(float sx, float sy) {
    Matrix s;
    s.SetScale(sx, sy);
    PreConcat(s);
}

void Matrix::PreTranslate(float dx, float dy) {
    Matrix t;
    t.SetTranslate(dx, dy);
    PreConcat(t);
}

void Matrix::PreConcat(const Matrix& other) {
    Matrix res;
    Concat(&res, *this, other);
    *this = res;
}

/**
 * @brief PostRotate: Multiplies matrix on the left by rotation (M' = R * M).
 * EN: Matches AArch64 opcode 0xeff18.
 * VN: Khớp opcode AArch64 0xeff18. Nhân trái ma trận với phép quay quanh gốc tọa độ.
 */
void Matrix::PostRotate(float deg) {
    Matrix r;
    r.SetRotate(deg);
    PostConcat(r);
}

void Matrix::PostRotate(float deg, float px, float py) {
    Matrix r;
    r.SetRotate(deg, px, py);
    PostConcat(r);
}

void Matrix::PostScale(float sx, float sy) {
    Matrix s;
    s.SetScale(sx, sy);
    PostConcat(s);
}

void Matrix::PostTranslate(float dx, float dy) {
    Matrix t;
    t.SetTranslate(dx, dy);
    PostConcat(t);
}

void Matrix::PostConcat(const Matrix& other) {
    Matrix res;
    Concat(&res, other, *this);
    *this = res;
}

/**
 * @brief Concat: 3x3 Matrix Multiplication (out = a * b).
 * EN: Formula: out_ij = sum_k (a_ik * b_kj).
 * VN: Nhân hai ma trận 3x3 chuẩn hóa tích hợp yếu tố chiếu phối cảnh projective.
 */
void Matrix::Concat(Matrix* out, const Matrix& a, const Matrix& b) {
    if (!out) return;
    float r[9];

    r[0] = a.mat_[0] * b.mat_[0] + a.mat_[1] * b.mat_[3] + a.mat_[2] * b.mat_[6];
    r[1] = a.mat_[0] * b.mat_[1] + a.mat_[1] * b.mat_[4] + a.mat_[2] * b.mat_[7];
    r[2] = a.mat_[0] * b.mat_[2] + a.mat_[1] * b.mat_[5] + a.mat_[2] * b.mat_[8];

    r[3] = a.mat_[3] * b.mat_[0] + a.mat_[4] * b.mat_[3] + a.mat_[5] * b.mat_[6];
    r[4] = a.mat_[3] * b.mat_[1] + a.mat_[4] * b.mat_[4] + a.mat_[5] * b.mat_[7];
    r[5] = a.mat_[3] * b.mat_[2] + a.mat_[4] * b.mat_[5] + a.mat_[5] * b.mat_[8];

    r[6] = a.mat_[6] * b.mat_[0] + a.mat_[7] * b.mat_[3] + a.mat_[8] * b.mat_[6];
    r[7] = a.mat_[6] * b.mat_[1] + a.mat_[7] * b.mat_[4] + a.mat_[8] * b.mat_[7];
    r[8] = a.mat_[6] * b.mat_[2] + a.mat_[7] * b.mat_[5] + a.mat_[8] * b.mat_[8];

    for (int i = 0; i < 9; ++i) {
        out->mat_[i] = r[i];
    }
}

/**
 * @brief HasPersp: Detects non-trivial perspective distortion terms.
 * EN: Matches AArch64 opcode 0xeecac.
 *     Loads offsets 0xc, 0x1c, 0x2c and checks != 0.0f, or offset 0x3c != 1.0f.
 * VN: Khớp opcode AArch64 0xeecac. Kiểm tra sự hiện diện của thành phần phối cảnh.
 */
bool Matrix::HasPersp() const {
    return mat_[kPersp0] != 0.0f || mat_[kPersp1] != 0.0f || mat_[kPersp2] != 1.0f;
}

/**
 * @brief Invert: Calculates analytic 3x3 matrix inverse via classical adjoint.
 * EN: Returns false if determinant is numerically zero (singular matrix).
 * VN: Nghịch đảo ma trận 3x3 bằng định thức det và ma trận phụ hợp adjoint.
 */
bool Matrix::Invert(Matrix* inverse) const {
    // 2x2 subdeterminants
    float c00 = mat_[4] * mat_[8] - mat_[5] * mat_[7];
    float c01 = mat_[2] * mat_[7] - mat_[1] * mat_[8];
    float c02 = mat_[1] * mat_[5] - mat_[2] * mat_[4];

    float det = mat_[0] * c00 + mat_[3] * c01 + mat_[6] * c02;

    if (std::fabs(det) < 1e-12f) {
        return false;
    }

    if (!inverse) return true;

    float inv_det = 1.0f / det;

    float c10 = mat_[5] * mat_[6] - mat_[3] * mat_[8];
    float c11 = mat_[0] * mat_[8] - mat_[2] * mat_[6];
    float c12 = mat_[2] * mat_[3] - mat_[0] * mat_[5];

    float c20 = mat_[3] * mat_[7] - mat_[4] * mat_[6];
    float c21 = mat_[1] * mat_[6] - mat_[0] * mat_[7];
    float c22 = mat_[0] * mat_[4] - mat_[1] * mat_[3];

    inverse->mat_[0] = c00 * inv_det;
    inverse->mat_[1] = c01 * inv_det;
    inverse->mat_[2] = c02 * inv_det;

    inverse->mat_[3] = c10 * inv_det;
    inverse->mat_[4] = c11 * inv_det;
    inverse->mat_[5] = c12 * inv_det;

    inverse->mat_[6] = c20 * inv_det;
    inverse->mat_[7] = c21 * inv_det;
    inverse->mat_[8] = c22 * inv_det;

    return true;
}

/**
 * @brief MapPoints: Vectorized 2D point transformation with perspective divide.
 * EN: Matches AArch64 opcode 0xef72c.
 *     If perspective is present:
 *       x' = (m0*x + m1*y + m2) / w
 *       y' = (m3*x + m4*y + m5) / w
 *       where w = m6*x + m7*y + m8
 *     Else (standard affine):
 *       x' = m0*x + m1*y + m2
 *       y' = m3*x + m4*y + m5
 * VN: Khớp opcode AArch64 0xef72c. Ánh xạ mảng điểm 2D qua ma trận kèm chia phối cảnh w.
 */
void Matrix::MapPoints(Vec2* dst, const Vec2* src, int count) const {
    if (!dst || !src || count <= 0) return;

    if (HasPersp()) {
        for (int i = 0; i < count; ++i) {
            float sx = src[i].x;
            float sy = src[i].y;
            float w = mat_[6] * sx + mat_[7] * sy + mat_[8];
            float inv_w = (std::fabs(w) > 1e-7f) ? (1.0f / w) : 1.0f;

            dst[i].x = (mat_[0] * sx + mat_[1] * sy + mat_[2]) * inv_w;
            dst[i].y = (mat_[3] * sx + mat_[4] * sy + mat_[5]) * inv_w;
        }
    } else {
        for (int i = 0; i < count; ++i) {
            float sx = src[i].x;
            float sy = src[i].y;
            dst[i].x = mat_[0] * sx + mat_[1] * sy + mat_[2];
            dst[i].y = mat_[3] * sx + mat_[4] * sy + mat_[5];
        }
    }
}

Vec2 Matrix::MapPoint(const Vec2& pt) const {
    Vec2 res;
    MapPoints(&res, &pt, 1);
    return res;
}

Rect Matrix::MapRect(const Rect& src) const {
    if (src.IsEmpty()) return Rect::MakeEmpty();

    Vec2 pts[4] = {
        Vec2(src.left,  src.top),
        Vec2(src.right, src.top),
        Vec2(src.right, src.bottom),
        Vec2(src.left,  src.bottom)
    };
    Vec2 dst[4];
    MapPoints(dst, pts, 4);

    float l = dst[0].x, r = dst[0].x;
    float t = dst[0].y, b = dst[0].y;

    for (int i = 1; i < 4; ++i) {
        l = std::min(l, dst[i].x);
        r = std::max(r, dst[i].x);
        t = std::min(t, dst[i].y);
        b = std::max(b, dst[i].y);
    }
    return Rect(l, t, r, b);
}

} // namespace skity
