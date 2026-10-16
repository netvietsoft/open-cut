// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Mathematical Transforms, DCT, Affine, & Thresholding
// File: fastcv_math_transforms.h
// Description: FastCV numerical algorithms: threshold, absdiff, normalize,
//              bitwise_and, calcHist, getAffineTransform, dct, and idct.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_MATH_TRANSFORMS_H_
#define NEXTAI_OPENCUT_FASTCV_MATH_TRANSFORMS_H_

#include "fastcv_types.h"
#include "fastcv_mat.h"

namespace FASTCV {
namespace EXPORTS {

// Opcode 0x607d4: threshold
void threshold(const Mat& src, Mat& dst, double thresh, double maxval, int type);

// Opcode 0x5dd60: absdiff
void absdiff(const Mat& src1, const Mat& src2, Mat& dst, int flags = 0);

// Opcode 0x6052c: normalize (UMat overload)
void normalize(const UMat& src, UMat& dst, double alpha, double beta,
               int norm_type = NORM_L2, int dtype = -1);
void normalize(const Mat& src, Mat& dst, double alpha, double beta,
               int norm_type = NORM_L2, int dtype = -1);

// Opcode 0x5dfe0: bitwise_and
void bitwise_and(const Mat& src1, const Mat& src2, Mat& dst,
                 const Mat& mask = Mat(), int flags = 0);

// Opcode 0x603f4: calcHist
void calcHist(const UMat& src, UMat& hist, const UMat& mask);
void calcHist(const Mat& src, Mat& hist, const Mat& mask = Mat());

// Opcode 0x5c3f0: getAffineTransform
Mat getAffineTransform(const Point2f src[3], const Point2f dst[3]);

// Opcode 0x60acc: dct (Discrete Cosine Transform)
void dct(const Mat& src, Mat& dst, int flags = 0);

// Opcode 0x61220: idct (Inverse Discrete Cosine Transform)
void idct(const UMat& src, UMat& dst, int flags = 0);
void idct(const Mat& src, Mat& dst, int flags = 0);

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_MATH_TRANSFORMS_H_
