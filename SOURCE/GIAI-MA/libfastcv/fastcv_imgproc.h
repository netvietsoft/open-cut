// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Qualcomm FastCV Computer Vision SDK & GPU Image Processing
// File: fastcv_imgproc.h
// Description: Image processing algorithms: cvtColor, alphaBlend, downScale,
//              copyMakeBorder, copyROI, and combineAndConvertTo.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_IMGPROC_H_
#define NEXTAI_OPENCUT_FASTCV_IMGPROC_H_

#include "fastcv_types.h"
#include "fastcv_mat.h"

namespace FASTCV {
namespace EXPORTS {

// Opcode 0x5e468: cvtColor (Color space conversion)
void cvtColor(const UMat& src, UMat& dst, int code, int dstCn = 0);
void cvtColor(const Mat& src, Mat& dst, int code, int dstCn = 0);

// Opcode 0x5f598: alphaBlend
void alphaBlend(const Mat& src1, const Mat& src2, const Mat& alpha, Mat& dst);

// Opcode 0x5f76c: combineAndConvertTo (Merge planes into interleaved buffer)
void combineAndConvertTo(const UMat& p0, const UMat& p1, const UMat& p2,
                         const UMat& p3, UMat& dst, int flags);

// Opcode 0x60880: downScale
void downScale(const UMat& src, UMat& dst, float fx, float fy);
void downScale(const Mat& src, Mat& dst, float fx, float fy);

// Opcode 0x5f18c: copyMakeBorder (UMat overload)
void copyMakeBorder(const UMat& src, UMat& dst, int top, int bottom,
                    int left, int right, int borderType, const Scalar& value = Scalar());
// Opcode 0x5f0f0: copyMakeBorder (Mat overload)
void copyMakeBorder(const Mat& src, Mat& dst, int top, int bottom,
                    int left, int right, int borderType, const Scalar& value = Scalar());

// Opcode 0x5fa48: copyROI
void copyROI(const Mat& src, Mat& dst, int x, int y, int width, int height);

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_IMGPROC_H_
