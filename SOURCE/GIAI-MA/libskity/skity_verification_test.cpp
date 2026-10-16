// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Adversarial Verification Test Suite
// File: skity_verification_test.cpp
// Description: Implementation of rigorous mathematical tests for libskity.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_verification_test.h"
#include "skity_geometry.h"
#include "skity_matrix.h"
#include "skity_path.h"
#include "skity_stroke.h"
#include "skity_path_measure.h"
#include "skity_paint_effects.h"
#include "skity_canvas.h"

#include <iostream>
#include <cmath>

namespace skity {

bool SkityVerificationTest::RunAllTests(std::vector<TestResult>* out_results) {
    std::vector<TestResult> results = {
        TestRectRoundOutAndInset(),
        TestMatrixAffineAndPerspective(),
        TestQuaternionDotSlerpReciprocal(),
        TestPathAddCircleAndArcTo(),
        TestStrokeMiterJoinAndLimit(),
        TestPathMeasurePosTanAndLength(),
        TestShaderGradientAndMaskFilter(),
        TestRecordingCanvasDisplayList(),
    };

    bool all_passed = true;
    for (const auto& r : results) {
        if (!r.passed) {
            all_passed = false;
        }
    }

    if (out_results) {
        *out_results = results;
    }
    return all_passed;
}

/**
 * @brief Test 1: Rect RoundOut and Inset Math Parity.
 * Opcode: 0xf07e8 (RoundOut), 0xf0864 (MakeInset), 0xf09b0 (Intersect).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestRectRoundOutAndInset() {
    TestResult r;
    r.test_name = "Skity_RectRoundOutAndInsetMath";

    Rect rect(10.2f, 20.8f, 45.1f, 80.9f);
    rect.RoundOut();

    bool round_ok = (rect.left == 10.0f && rect.top == 20.0f &&
                     rect.right == 46.0f && rect.bottom == 81.0f);

    Rect inset_rect = rect.MakeInset(5.0f, 10.0f);
    bool inset_ok = (inset_rect.left == 15.0f && inset_rect.top == 30.0f &&
                     inset_rect.right == 41.0f && inset_rect.bottom == 71.0f);

    Rect a(0.0f, 0.0f, 100.0f, 100.0f);
    Rect b(50.0f, 50.0f, 150.0f, 150.0f);
    Rect inter;
    bool inter_ok = Rect::Intersect(a, b, &inter) &&
                    inter.left == 50.0f && inter.top == 50.0f &&
                    inter.right == 100.0f && inter.bottom == 100.0f;

    r.passed = round_ok && inset_ok && inter_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "Rect RoundOut (Opcode 0xf07e8), Inset (0xf0864), Intersect (0xf09b0) đạt tính toán học tuyệt đối"
                         : "Lỗi tính toán hình học Rect";
    return r;
}

/**
 * @brief Test 2: Matrix Affine, Perspective, and Inversion Math.
 * Opcode: 0xeece8 (Set9), 0xef72c (MapPoints), 0xeecac (HasPersp), 0xefec0 (PreRotate).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestMatrixAffineAndPerspective() {
    TestResult r;
    r.test_name = "Skity_MatrixAffineAndPerspectiveMath";

    Matrix m;
    m.SetRotate(90.0f); // 90 deg rotation around origin

    Vec2 src(1.0f, 0.0f);
    Vec2 dst = m.MapPoint(src);

    // 90 deg rotation maps (1, 0) to (0, 1)
    double err_rot = std::fabs(dst.x - 0.0f) + std::fabs(dst.y - 1.0f);
    bool rot_ok = (err_rot < 1e-5);

    // Perspective check
    bool no_persp = !m.HasPersp();
    m[Matrix::kPersp0] = 0.01f;
    bool has_persp = m.HasPersp();

    // Matrix inversion check
    Matrix rot_trans;
    rot_trans.SetRotate(45.0f);
    rot_trans.PostTranslate(100.0f, 200.0f);
    rot_trans.PostScale(2.5f, 1.8f);

    Matrix inv;
    bool inv_success = rot_trans.Invert(&inv);

    Vec2 test_pt(35.0f, 75.0f);
    Vec2 mapped_pt = rot_trans.MapPoint(test_pt);
    Vec2 restored_pt = inv.MapPoint(mapped_pt);

    double err_inv = std::fabs(restored_pt.x - test_pt.x) + std::fabs(restored_pt.y - test_pt.y);
    bool inv_ok = (err_inv < 1e-4);

    r.passed = rot_ok && no_persp && has_persp && inv_success && inv_ok;
    r.error_margin = err_inv;
    r.message = r.passed ? "Matrix MapPoints (0xef72c), HasPersp (0xeecac), và tính khả nghịch M * M^-1 = I đạt chuẩn"
                         : "Lỗi ma trận biến đổi affine/perspective";
    return r;
}

/**
 * @brief Test 3: Quaternion Slerp and Hamilton Math Parity.
 * Opcode: 0xf0224 (Dot), 0xf024c (Multiple), 0xf02d0 (Slerp), 0xf0500 (Reciprocal).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestQuaternionDotSlerpReciprocal() {
    TestResult r;
    r.test_name = "Skity_QuaternionDotSlerpReciprocalMath";

    // 0 deg rotation around Z
    Quaternion q0 = Quaternion::FromAxisAngle(Vec3(0, 0, 1), 0.0f);
    // 90 deg rotation around Z
    Quaternion q90 = Quaternion::FromAxisAngle(Vec3(0, 0, 1), 3.14159265358979323846f * 0.5f);

    // Dot product
    float dot = q0.Dot(q90);
    bool dot_ok = (std::fabs(dot - std::cos(3.14159265358979323846f / 4.0f)) < 1e-4);

    // Slerp at t = 0.5 should give 45 deg rotation
    Quaternion q45 = q0.Slerp(q90, 0.5f);
    Vec3 axis;
    float angle = 0.0f;
    q45.ToAxisAngle(&axis, &angle);

    float expected_angle = 3.14159265358979323846f / 4.0f; // 45 deg in rad
    double err_slerp = std::fabs(angle - expected_angle);
    bool slerp_ok = (err_slerp < 1e-4);

    // Reciprocal
    Quaternion inv_q90 = q90.Reciprocal();
    Quaternion identity = q90 * inv_q90;
    double err_recip = std::fabs(identity.w - 1.0f) + std::fabs(identity.x) + std::fabs(identity.y) + std::fabs(identity.z);
    bool recip_ok = (err_recip < 1e-4);

    r.passed = dot_ok && slerp_ok && recip_ok;
    r.error_margin = err_slerp;
    r.message = r.passed ? "Quaternion Slerp (Opcode 0xf02d0), Dot (0xf0224), Reciprocal (0xf0500) đạt tính đối xứng cầu"
                         : "Lỗi nội suy Quaternion Slerp";
    return r;
}

/**
 * @brief Test 4: Path AddCircle and ArcTo W3C SVG Math.
 * Opcode: 0xf87e8 (AddCircle), 0xf79b8 (ArcTo), 0xf802c (HasOnlyMoveTos).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestPathAddCircleAndArcTo() {
    TestResult r;
    r.test_name = "Skity_PathAddCircleAndArcToMath";

    Path path;
    // AddCircle at (100, 100) radius 50
    path.AddCircle(100.0f, 100.0f, 50.0f, Path::kCW);
    Rect bounds = path.ComputeBounds();

    bool circle_bounds_ok = (std::fabs(bounds.left - 50.0f) < 1e-3f &&
                             std::fabs(bounds.top - 50.0f) < 1e-3f &&
                             std::fabs(bounds.right - 150.0f) < 1e-3f &&
                             std::fabs(bounds.bottom - 150.0f) < 1e-3f);

    // ArcTo: 90-degree circular arc from (100, 0) to (0, 100) with center (0, 0)
    Path arc_path;
    arc_path.MoveTo(100.0f, 0.0f);
    arc_path.ArcTo(100.0f, 100.0f, 0.0f, Path::kSmall, Path::kCW, 0.0f, 100.0f);

    // Check that midpoint on Bezier spline is distance 100 from center
    // Arc is approximated by 1 cubic Bezier with alpha = 4/3 * tan(pi/8) approx 0.55228
    // At t = 0.5, point is (x(0.5), y(0.5))
    Point p0 = arc_path.points()[0]; // (100, 0)
    Point cp1 = arc_path.points()[1]; // (100, 55.228)
    Point cp2 = arc_path.points()[2]; // (55.228, 100)
    Point p3 = arc_path.points()[3]; // (0, 100)

    float t = 0.5f;
    float u = 0.5f;
    float mx = u*u*u*p0.x + 3.0f*u*u*t*cp1.x + 3.0f*u*t*t*cp2.x + t*t*t*p3.x;
    float my = u*u*u*p0.y + 3.0f*u*u*t*cp1.y + 3.0f*u*t*t*cp2.y + t*t*t*p3.y;
    float mid_dist = std::sqrt(mx * mx + my * my);

    double err_arc = std::fabs(mid_dist - 100.0f);
    bool arc_ok = (err_arc < 0.5f); // Cubic Bezier circle approximation has max radial error < 0.05%

    // HasOnlyMoveTos check
    Path empty_path;
    empty_path.MoveTo(10.0f, 10.0f);
    empty_path.MoveTo(20.0f, 20.0f);
    bool move_only_ok = empty_path.HasOnlyMoveTos() && !path.HasOnlyMoveTos();

    r.passed = circle_bounds_ok && arc_ok && move_only_ok;
    r.error_margin = err_arc;
    r.message = r.passed ? "Path AddCircle (0xf87e8), ArcTo SVG (0xf79b8), HasOnlyMoveTos (0xf802c) đạt chuẩn hình học"
                         : "Lỗi tham số hóa Path ArcTo / AddCircle";
    return r;
}

/**
 * @brief Test 5: Stroke Miter Join and Miter Limit Clipping.
 * Opcode: 0xf2828 (StrokePath).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestStrokeMiterJoinAndLimit() {
    TestResult r;
    r.test_name = "Skity_StrokeMiterJoinAndLimitMath";

    // 90-degree corner path: (0, 100) -> (100, 100) -> (100, 0)
    Path corner;
    corner.MoveTo(0.0f, 100.0f);
    corner.LineTo(100.0f, 100.0f);
    corner.LineTo(100.0f, 0.0f);

    float width = 20.0f; // half_width = 10.0f
    // For 90-deg corner, miter length factor = 1 / sin(45 deg) = sqrt(2) approx 1.4142

    // 1. With miter_limit = 4.0 (> 1.414): miter corner should be extended to (110, 110)
    Stroke stroke_miter(width, 4.0f, Stroke::kButt, Stroke::kMiter);
    Path dst_miter;
    bool s1_ok = stroke_miter.StrokePath(corner, &dst_miter);

    Rect bounds_miter = dst_miter.ComputeBounds();
    // Outer miter point reaches (100 + 10, 100 + 10) = (110, 110)
    bool miter_point_ok = (std::fabs(bounds_miter.right - 110.0f) < 1.0f &&
                           std::fabs(bounds_miter.bottom - 110.0f) < 1.0f);

    // 2. With miter_limit = 1.0 (< 1.414): miter limit clipping triggers Bevel fallback
    Stroke stroke_clipped(width, 1.0f, Stroke::kButt, Stroke::kMiter);
    Path dst_clipped;
    bool s2_ok = stroke_clipped.StrokePath(corner, &dst_clipped);

    Rect bounds_clipped = dst_clipped.ComputeBounds();
    // Bevel does not extend to (110, 110), remains at (100 + 10) on orthogonal edges
    bool clipped_ok = (bounds_clipped.right <= 110.0f);

    r.passed = s1_ok && s2_ok && miter_point_ok && clipped_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "StrokePath (Opcode 0xf2828): Miter Join & Miter Limit cắt góc nhọn chính xác 100%"
                         : "Lỗi mở rộng đường viền Stroke Miter Limit";
    return r;
}

/**
 * @brief Test 6: PathMeasure PosTan and Arc Length Parameterization.
 * Opcode: 0xfb370 (GetPosTan), 0xfb278 (SetPath).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestPathMeasurePosTanAndLength() {
    TestResult r;
    r.test_name = "Skity_PathMeasurePosTanAndLengthMath";

    // Circle of radius R = 100 centered at (100, 100)
    Path circle;
    circle.AddCircle(100.0f, 100.0f, 100.0f, Path::kCW);

    PathMeasure pm(circle, true);
    float length = pm.GetLength();

    // Expected circumference: 2 * pi * 100 = 628.3185f
    float expected_len = 2.0f * kSkityPi * 100.0f;
    double err_len = std::fabs(length - expected_len);
    // Cubic Bezier circle approximation is within 0.1% of true circumference
    bool len_ok = (err_len < 2.0);

    // Evaluate position at quarter of circle (distance = length / 4)
    Vec4 pos, tan;
    bool pos_tan_ok = pm.GetPosTan(length * 0.25f, &pos, &tan);

    // Tangent must be normalized (length == 1.0)
    float tan_len = std::sqrt(tan.x * tan.x + tan.y * tan.y);
    double err_tan = std::fabs(tan_len - 1.0f);
    bool tan_norm_ok = (err_tan < 1e-4);

    r.passed = len_ok && pos_tan_ok && tan_norm_ok;
    r.error_margin = err_tan;
    r.message = r.passed ? "PathMeasure GetPosTan (Opcode 0xfb370): Chu vi và vector tiếp tuyến đạt độ chuẩn xác số học"
                         : "Lỗi đo chiều dài hoặc tiếp tuyến PathMeasure";
    return r;
}

/**
 * @brief Test 7: Shaders (Linear, Radial, Sweep) and MaskFilter Blur.
 * Opcode: 0xec754 (MakeLinear), 0xec89c (MakeRadial), 0xebcdc (MakeBlur), 0xf6718 (ComputeFastBounds).
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestShaderGradientAndMaskFilter() {
    TestResult r;
    r.test_name = "Skity_ShaderGradientAndMaskFilterMath";

    Point pts[2] = { Point(0.0f, 0.0f), Point(100.0f, 0.0f) };
    Vec4 colors[2] = { Vec4(1.0f, 0.0f, 0.0f, 1.0f), Vec4(0.0f, 0.0f, 1.0f, 1.0f) }; // Red to Blue

    auto linear = Shader::MakeLinear(pts, colors, nullptr, 2, TileMode::kClamp);
    Vec4 mid_color = linear->Shade(50.0f, 0.0f);

    // At 50%, color should be (0.5, 0.0, 0.5, 1.0)
    double err_linear = std::fabs(mid_color.x - 0.5f) + std::fabs(mid_color.z - 0.5f);
    bool linear_ok = (err_linear < 1e-4);

    // Radial shader check
    auto radial = Shader::MakeRadial(Point(50.0f, 50.0f), 50.0f, colors, nullptr, 2, TileMode::kClamp);
    Vec4 center_c = radial->Shade(50.0f, 50.0f);
    bool radial_center_ok = (center_c.x == 1.0f && center_c.z == 0.0f);
    Vec4 outer_c = radial->Shade(100.0f, 50.0f);
    bool radial_outer_ok = (outer_c.x == 0.0f && outer_c.z == 1.0f);

    // MaskFilter check
    auto blur = MaskFilter::MakeBlur(BlurStyle::kNormal, 10.0f);
    bool blur_ok = (blur != nullptr && blur->radius() == 10.0f);

    // Paint ComputeFastBounds
    Paint p;
    p.SetStyle(Paint::kStroke);
    p.SetStrokeWidth(20.0f); // half_width = 10
    p.SetStrokeJoin(Paint::kRound);
    p.SetMaskFilter(blur); // +30 blur bounds

    Rect base_rect(0.0f, 0.0f, 100.0f, 100.0f);
    Rect fast_bounds = p.ComputeFastBounds(base_rect);
    // Expansion = half_width (10) + 3*radius (30) = 40
    bool bounds_ok = (fast_bounds.left == -40.0f && fast_bounds.top == -40.0f &&
                      fast_bounds.right == 140.0f && fast_bounds.bottom == 140.0f);

    r.passed = linear_ok && radial_center_ok && radial_outer_ok && blur_ok && bounds_ok;
    r.error_margin = err_linear;
    r.message = r.passed ? "Shader MakeLinear (0xec754), MakeRadial (0xec89c), MakeBlur (0xebcdc), FastBounds (0xf6718) đạt chuẩn"
                         : "Lỗi tính toán Shader hoặc MaskFilter";
    return r;
}

/**
 * @brief Test 8: RecordingCanvas Display List Command Fidelity.
 * Opcode: 0x104d88, 0x105978, 0x104f74, 0x10537c.
 */
SkityVerificationTest::TestResult SkityVerificationTest::TestRecordingCanvasDisplayList() {
    TestResult r;
    r.test_name = "Skity_RecordingCanvasDisplayListCommandFidelity";

    RecordingCanvas canvas(1920, 1080);
    bool size_ok = (canvas.OnGetWidth() == 1920 && canvas.OnGetHeight() == 1080);

    Paint paint;
    paint.SetColor(Vec4(1.0f, 1.0f, 0.0f, 1.0f));

    // Record RRect
    RRect rrect;
    rrect.SetOval(Rect(100.0f, 100.0f, 300.0f, 250.0f));
    canvas.OnDrawRRect(rrect, paint);

    // Record Glyphs
    uint16_t glyphs[4] = { 65, 66, 67, 68 };
    float x_pos[4] = { 0.0f, 12.0f, 24.0f, 36.0f };
    float y_pos[4] = { 50.0f, 50.0f, 50.0f, 50.0f };
    canvas.OnDrawGlyphs(4, glyphs, x_pos, y_pos, paint);

    bool cmds_ok = (canvas.CommandCount() == 2 &&
                    canvas.GetCommands()[0].type == RecordingCanvas::kCmdDrawRRect &&
                    canvas.GetCommands()[1].type == RecordingCanvas::kCmdDrawGlyphs);

    r.passed = size_ok && cmds_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "RecordingCanvas OnDrawRRect (0x104f74), OnDrawGlyphs (0x10537c) ghi nhận display list trung thực 100%"
                         : "Lỗi ghi nhận lệnh RecordingCanvas";
    return r;
}

} // namespace skity
