// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Vector Geometry Primitives & Math
// File: skity_geometry.cpp
// Description: Implementation of Rect, RRect, and Quaternion methods matching
//              AArch64 disassembly and mathematical specs.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_geometry.h"

namespace skity {

// ==============================================================================
// Rect Implementation
// ==============================================================================

/**
 * @brief RoundOut: Expands rectangle bounds to integer coordinates.
 * EN: Matches AArch64 opcode 0xf07e8.
 *     Uses frintm (floor) for left/top and frintp (ceil) for right/bottom.
 * VN: Khớp opcode AArch64 0xf07e8.
 *     Làm tròn xuống (floor) cho cạnh trái/trên và làm tròn lên (ceil) cho cạnh phải/dưới.
 */
void Rect::RoundOut() {
    left = std::floor(left);
    top = std::floor(top);
    right = std::ceil(right);
    bottom = std::ceil(bottom);
}

/**
 * @brief Intersect: Computes intersection between two rectangles.
 * EN: Matches AArch64 opcode 0xf09b0.
 * VN: Khớp opcode AArch64 0xf09b0. Tính giao giữa hai hình chữ nhật.
 */
bool Rect::Intersect(const Rect& a, const Rect& b, Rect* out) {
    float l = std::max(a.left, b.left);
    float t = std::max(a.top, b.top);
    float r = std::min(a.right, b.right);
    float bot = std::min(a.bottom, b.bottom);

    if (l < r && t < bot) {
        if (out) {
            out->left = l;
            out->top = t;
            out->right = r;
            out->bottom = bot;
        }
        return true;
    }
    return false;
}

bool Rect::Intersect(const Rect& other) {
    return Intersect(*this, other, this);
}

/**
 * @brief MakeInset: Shrinks rectangle by horizontal and vertical offsets.
 * EN: Matches AArch64 opcode 0xf0864.
 * VN: Khớp opcode AArch64 0xf0864. Thu hẹp lề hình chữ nhật một khoảng dx, dy.
 */
Rect Rect::MakeInset(float dx, float dy) const {
    return Rect(left + dx, top + dy, right - dx, bottom - dy);
}

void Rect::Join(const Rect& other) {
    if (other.IsEmpty()) return;
    if (IsEmpty()) {
        *this = other;
        return;
    }
    left = std::min(left, other.left);
    top = std::min(top, other.top);
    right = std::max(right, other.right);
    bottom = std::max(bottom, other.bottom);
}

bool Rect::Contains(float px, float py) const {
    return px >= left && px < right && py >= top && py < bottom;
}

bool Rect::Contains(const Rect& r) const {
    return !IsEmpty() && !r.IsEmpty() &&
           left <= r.left && top <= r.top &&
           right >= r.right && bottom >= r.bottom;
}

// ==============================================================================
// RRect (Rounded Rectangle) Implementation
// ==============================================================================

RRect::RRect() : rect_(Rect::MakeEmpty()), type_(kEmpty) {
    for (auto& r : radii_) {
        r = Vec2(0.0f, 0.0f);
    }
}

/**
 * @brief AreRectAndRadiiValid: Validates radii against rect dimensions.
 * EN: Matches AArch64 opcode 0xf10d4.
 *     Verifies width, height >= 0 and non-negative corner radii.
 * VN: Khớp opcode AArch64 0xf10d4. Kiểm tra tính hợp lệ của kích thước và bán kính góc bo.
 */
bool RRect::AreRectAndRadiiValid(const Rect& rect, const std::array<Vec2, 4>& radii) {
    if (rect.Width() < 0.0f || rect.Height() < 0.0f) {
        return false;
    }
    for (const auto& r : radii) {
        if (r.x < 0.0f || r.y < 0.0f) {
            return false;
        }
    }
    return true;
}

/**
 * @brief SetRect: Sets simple rectangular boundary without rounded corners.
 * EN: Matches AArch64 opcode 0xf0a00.
 * VN: Khớp opcode AArch64 0xf0a00. Thiết lập khung hình chữ nhật chuẩn góc vuông.
 */
void RRect::SetRect(const Rect& rect) {
    rect_ = rect;
    for (auto& r : radii_) {
        r = Vec2(0.0f, 0.0f);
    }
    type_ = rect.IsEmpty() ? kEmpty : kRect;
}

/**
 * @brief SetOval: Sets ellipse boundary where radii equal half-dimensions.
 * EN: Matches AArch64 opcode 0xf131c.
 * VN: Khớp opcode AArch64 0xf131c. Thiết lập hình bầu dục bo tròn hoàn toàn.
 */
void RRect::SetOval(const Rect& oval) {
    if (oval.IsEmpty()) {
        MakeEmpty();
        return;
    }
    rect_ = oval;
    float rx = oval.Width() * 0.5f;
    float ry = oval.Height() * 0.5f;
    for (auto& r : radii_) {
        r = Vec2(rx, ry);
    }
    type_ = kOval;
}

/**
 * @brief SetRectRadii: Sets distinct corner radii with proportional scaling.
 * EN: Matches AArch64 opcode 0xf11b8.
 * VN: Khớp opcode AArch64 0xf11b8. Thiết lập 4 góc bo với tỷ lệ co giãn bảo toàn hình học.
 */
void RRect::SetRectRadii(const Rect& rect, const Vec2* radii) {
    if (rect.IsEmpty() || !radii) {
        MakeEmpty();
        return;
    }
    rect_ = rect;
    for (int i = 0; i < 4; ++i) {
        radii_[i] = radii[i];
    }
    ScaleRadiiIfNecessary();

    // Determine type
    bool all_zero = true;
    bool all_same = true;
    for (int i = 0; i < 4; ++i) {
        if (radii_[i].x > 0.0f || radii_[i].y > 0.0f) {
            all_zero = false;
        }
        if (radii_[i].x != radii_[0].x || radii_[i].y != radii_[0].y) {
            all_same = false;
        }
    }
    if (all_zero) {
        type_ = kRect;
    } else if (all_same) {
        float rx = rect_.Width() * 0.5f;
        float ry = rect_.Height() * 0.5f;
        if (radii_[0].x == rx && radii_[0].y == ry) {
            type_ = kOval;
        } else {
            type_ = kSimple;
        }
    } else {
        type_ = kComplex;
    }
}

/**
 * @brief ScaleRadiiIfNecessary: Proportional corner radius reduction (W3C CSS rule).
 * EN: Ensures top/bottom and left/right sum of radii do not exceed rect bounds.
 * VN: Đảm bảo tổng bán kính hai góc liền kề không vượt quá chiều rộng hoặc chiều cao.
 */
void RRect::ScaleRadiiIfNecessary() {
    float scale = 1.0f;
    float w = rect_.Width();
    float h = rect_.Height();

    float top_sum = radii_[kUpperLeft].x + radii_[kUpperRight].x;
    if (top_sum > w && top_sum > 0.0f) {
        scale = std::min(scale, w / top_sum);
    }
    float bot_sum = radii_[kLowerLeft].x + radii_[kLowerRight].x;
    if (bot_sum > w && bot_sum > 0.0f) {
        scale = std::min(scale, w / bot_sum);
    }
    float left_sum = radii_[kUpperLeft].y + radii_[kLowerLeft].y;
    if (left_sum > h && left_sum > 0.0f) {
        scale = std::min(scale, h / left_sum);
    }
    float right_sum = radii_[kUpperRight].y + radii_[kLowerRight].y;
    if (right_sum > h && right_sum > 0.0f) {
        scale = std::min(scale, h / right_sum);
    }

    if (scale < 1.0f) {
        for (auto& r : radii_) {
            r.x *= scale;
            r.y *= scale;
        }
    }
}

/**
 * @brief MakeEmpty: Resets RRect to empty state.
 * EN: Matches AArch64 opcode 0xf13c8.
 * VN: Khớp opcode AArch64 0xf13c8. Đưa RRect về trạng thái rỗng.
 */
void RRect::MakeEmpty() {
    rect_ = Rect::MakeEmpty();
    for (auto& r : radii_) {
        r = Vec2(0.0f, 0.0f);
    }
    type_ = kEmpty;
}

/**
 * @brief Contains: Checks whether inner point or rect is within rounded boundary.
 * EN: Matches AArch64 opcode 0xf156c.
 * VN: Khớp opcode AArch64 0xf156c. Kiểm tra điểm hoặc khung nằm trọn vẹn trong RRect.
 */
bool RRect::Contains(float px, float py) const {
    if (!rect_.Contains(px, py)) return false;
    if (type_ == kRect) return true;

    // Check 4 corner elliptic quadrants
    // Top-Left
    if (px < rect_.left + radii_[kUpperLeft].x && py < rect_.top + radii_[kUpperLeft].y) {
        float rx = radii_[kUpperLeft].x;
        float ry = radii_[kUpperLeft].y;
        if (rx <= 0.0f || ry <= 0.0f) return false;
        float dx = (px - (rect_.left + rx)) / rx;
        float dy = (py - (rect_.top + ry)) / ry;
        return (dx * dx + dy * dy) <= 1.0f;
    }
    // Top-Right
    if (px > rect_.right - radii_[kUpperRight].x && py < rect_.top + radii_[kUpperRight].y) {
        float rx = radii_[kUpperRight].x;
        float ry = radii_[kUpperRight].y;
        if (rx <= 0.0f || ry <= 0.0f) return false;
        float dx = (px - (rect_.right - rx)) / rx;
        float dy = (py - (rect_.top + ry)) / ry;
        return (dx * dx + dy * dy) <= 1.0f;
    }
    // Bottom-Right
    if (px > rect_.right - radii_[kLowerRight].x && py > rect_.bottom - radii_[kLowerRight].y) {
        float rx = radii_[kLowerRight].x;
        float ry = radii_[kLowerRight].y;
        if (rx <= 0.0f || ry <= 0.0f) return false;
        float dx = (px - (rect_.right - rx)) / rx;
        float dy = (py - (rect_.bottom - ry)) / ry;
        return (dx * dx + dy * dy) <= 1.0f;
    }
    // Bottom-Left
    if (px < rect_.left + radii_[kLowerLeft].x && py > rect_.bottom - radii_[kLowerLeft].y) {
        float rx = radii_[kLowerLeft].x;
        float ry = radii_[kLowerLeft].y;
        if (rx <= 0.0f || ry <= 0.0f) return false;
        float dx = (px - (rect_.left + rx)) / rx;
        float dy = (py - (rect_.bottom - ry)) / ry;
        return (dx * dx + dy * dy) <= 1.0f;
    }
    return true;
}

bool RRect::Contains(const Rect& r) const {
    return Contains(r.left, r.top) &&
           Contains(r.right, r.top) &&
           Contains(r.right, r.bottom) &&
           Contains(r.left, r.bottom);
}

// ==============================================================================
// Quaternion Implementation
// ==============================================================================

/**
 * @brief Dot: 4D vector dot product.
 * EN: Matches AArch64 opcode 0xf0224.
 *     Uses SIMD fmul and pairwise faddp.
 * VN: Khớp opcode AArch64 0xf0224. Tích vô hướng 4 chiều SIMD.
 */
float Quaternion::Dot(const Quaternion& o) const {
    return x * o.x + y * o.y + z * o.z + w * o.w;
}

/**
 * @brief Multiple: Hamilton quaternion multiplication.
 * EN: Matches AArch64 opcode 0xf024c.
 *     Formula:
 *       x' = w1*x2 + x1*w2 + y1*z2 - z1*y2
 *       y' = w1*y2 - x1*z2 + y1*w2 + z1*x2
 *       z' = w1*z2 + x1*y2 - y1*x2 + z1*w2
 *       w' = w1*w2 - x1*x2 - y1*y2 - z1*z2
 * VN: Khớp opcode AArch64 0xf024c. Tích quaternion Hamilton biểu diễn phép quay 3D kết hợp.
 */
Quaternion Quaternion::Multiple(const Quaternion& o) const {
    return Quaternion(
        w * o.x + x * o.w + y * o.z - z * o.y,
        w * o.y - x * o.z + y * o.w + z * o.x,
        w * o.z + x * o.y - y * o.x + z * o.w,
        w * o.w - x * o.x - y * o.y - z * o.z
    );
}

/**
 * @brief Slerp: Spherical Linear Interpolation between two unit quaternions.
 * EN: Matches AArch64 opcode 0xf02d0.
 *     Checks angle cos(theta) against threshold 0.9995.
 *     If parallel, falls back to lerp to prevent numerical instability.
 * VN: Khớp opcode AArch64 0xf02d0. Nội suy cầu tuyến tính mượt mà cho góc quay 3D.
 */
Quaternion Quaternion::Slerp(const Quaternion& o, float t) const {
    float cos_theta = Dot(o);
    Quaternion target = o;

    // Shortest path traversal
    if (cos_theta < 0.0f) {
        cos_theta = -cos_theta;
        target.x = -target.x;
        target.y = -target.y;
        target.z = -target.z;
        target.w = -target.w;
    }

    float k0, k1;
    // Check threshold 0.9995f (matching opcode table constant at 0x23800)
    if (cos_theta > 0.9995f) {
        k0 = 1.0f - t;
        k1 = t;
    } else {
        float sin_theta = std::sqrt(std::max(0.0f, 1.0f - cos_theta * cos_theta));
        float theta = std::atan2(sin_theta, cos_theta);
        float inv_sin_theta = 1.0f / sin_theta;
        k0 = std::sin((1.0f - t) * theta) * inv_sin_theta;
        k1 = std::sin(t * theta) * inv_sin_theta;
    }

    Quaternion res(
        x * k0 + target.x * k1,
        y * k0 + target.y * k1,
        z * k0 + target.z * k1,
        w * k0 + target.w * k1
    );

    // Normalize result
    float len = std::sqrt(res.Dot(res));
    if (len > 1e-7f) {
        float inv_len = 1.0f / len;
        res.x *= inv_len;
        res.y *= inv_len;
        res.z *= inv_len;
        res.w *= inv_len;
    }
    return res;
}

/**
 * @brief Reciprocal: Conjugate for unit quaternion (inversion).
 * EN: Matches AArch64 opcode 0xf0500.
 *     fneg s0, s0; fneg s1, s1; fneg s2, s2; returns [-x, -y, -z, w].
 * VN: Khớp opcode AArch64 0xf0500. Nghịch đảo liên hợp góc quay [-x, -y, -z, w].
 */
Quaternion Quaternion::Reciprocal() const {
    return Quaternion(-x, -y, -z, w);
}

/**
 * @brief FromEuler: Constructs quaternion from Euler angles (in radians).
 * EN: Matches AArch64 opcode 0xf00a4.
 * VN: Khớp opcode AArch64 0xf00a4. Chuyển đổi góc Euler (pitch, yaw, roll) sang quaternion.
 */
Quaternion Quaternion::FromEuler(float pitch, float yaw, float roll) {
    float cp = std::cos(pitch * 0.5f);
    float sp = std::sin(pitch * 0.5f);
    float cy = std::cos(yaw * 0.5f);
    float sy = std::sin(yaw * 0.5f);
    float cr = std::cos(roll * 0.5f);
    float sr = std::sin(roll * 0.5f);

    return Quaternion(
        sp * cy * cr - cp * sy * sr,
        cp * sy * cr + sp * cy * sr,
        cp * cy * sr - sp * sy * cr,
        cp * cy * cr + sp * sy * sr
    );
}

/**
 * @brief FromAxisAngle: Constructs quaternion from rotation axis and angle.
 * EN: Matches AArch64 opcode 0xf0148.
 * VN: Khớp opcode AArch64 0xf0148. Tạo quaternion từ trục xoay và góc quay radian.
 */
Quaternion Quaternion::FromAxisAngle(const Vec3& axis, float angle_rad) {
    Vec3 norm_axis = axis.Normalized();
    float half_angle = angle_rad * 0.5f;
    float s = std::sin(half_angle);
    float c = std::cos(half_angle);
    return Quaternion(norm_axis.x * s, norm_axis.y * s, norm_axis.z * s, c);
}

/**
 * @brief ToAxisAngle: Extracts rotation axis and angle from unit quaternion.
 * EN: Matches AArch64 opcode 0xf0498.
 * VN: Khớp opcode AArch64 0xf0498. Trích xuất trục xoay 3D và góc quay.
 */
void Quaternion::ToAxisAngle(Vec3* out_axis, float* out_angle) const {
    float clamped_w = std::max(-1.0f, std::min(1.0f, w));
    float angle = 2.0f * std::acos(clamped_w);
    float s = std::sqrt(std::max(0.0f, 1.0f - clamped_w * clamped_w));

    if (out_angle) *out_angle = angle;
    if (out_axis) {
        if (s > 1e-6f) {
            out_axis->x = x / s;
            out_axis->y = y / s;
            out_axis->z = z / s;
        } else {
            *out_axis = Vec3(1.0f, 0.0f, 0.0f);
        }
    }
}

/**
 * @brief EulerToMatrix: Converts Euler rotation into 4x4 matrix representation.
 * EN: Matches AArch64 opcode 0xeffbc.
 * VN: Khớp opcode AArch64 0xeffbc. Chuyển đổi góc quay Euler sang ma trận biến đổi 4x4.
 */
void Quaternion::EulerToMatrix(float pitch, float yaw, float roll, float* out_mat16) {
    if (!out_mat16) return;

    Quaternion q = FromEuler(pitch, yaw, roll);
    float x2 = q.x + q.x;
    float y2 = q.y + q.y;
    float z2 = q.z + q.z;

    float xx = q.x * x2;
    float xy = q.x * y2;
    float xz = q.x * z2;
    float yy = q.y * y2;
    float yz = q.y * z2;
    float zz = q.z * z2;
    float wx = q.w * x2;
    float wy = q.w * y2;
    float wz = q.w * z2;

    out_mat16[0] = 1.0f - (yy + zz);
    out_mat16[1] = xy + wz;
    out_mat16[2] = xz - wy;
    out_mat16[3] = 0.0f;

    out_mat16[4] = xy - wz;
    out_mat16[5] = 1.0f - (xx + zz);
    out_mat16[6] = yz + wx;
    out_mat16[7] = 0.0f;

    out_mat16[8] = xz + wy;
    out_mat16[9] = yz - wx;
    out_mat16[10] = 1.0f - (xx + yy);
    out_mat16[11] = 0.0f;

    out_mat16[12] = 0.0f;
    out_mat16[13] = 0.0f;
    out_mat16[14] = 0.0f;
    out_mat16[15] = 1.0f;
}

} // namespace skity
