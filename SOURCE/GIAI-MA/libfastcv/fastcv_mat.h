// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Qualcomm FastCV Computer Vision SDK & GPU Image Processing
// File: fastcv_mat.h
// Description: FastCV Mat and UMat 2D pixel buffer container implementations
//              with exact AArch64 ABI struct offsets and member methods.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_MAT_H_
#define NEXTAI_OPENCUT_FASTCV_MAT_H_

#include "fastcv_types.h"

namespace FASTCV {
namespace EXPORTS {

class UMat; // Forward declaration

// ==============================================================================
// Mat: CPU/Host 2D Dense Matrix Buffer
// Exact AArch64 Layout:
//   offset 0x00: int flags
//   offset 0x04: int rows
//   offset 0x08: int cols
//   offset 0x0c: int type_
//   offset 0x10: MatStep step
//   offset 0x28: uint8_t* data
// ==============================================================================
class Mat {
public:
    int flags;
    int rows;
    int cols;
    int type_;
    MatStep step;
    uint8_t* data;
    int* refcount;
    uint8_t* datastart;
    uint8_t* dataend;

    Mat();
    // Opcode 0x64030: Mat(rows, cols, type, data)
    Mat(int in_rows, int in_cols, int in_type, void* in_data = nullptr);
    // Opcode 0x657fc: Mat(rows, cols, type, flags, data)
    Mat(int in_rows, int in_cols, int in_type, MatUsageFlags usage, void* in_data = nullptr);
    Mat(const Mat& other);
    // Opcode 0x64674: Move Assignment
    Mat& operator=(Mat&& other) noexcept;
    Mat& operator=(const Mat& other);
    // Opcode 0x64800: Destructor
    virtual ~Mat();

    // Opcode 0x64c50: channels (asr w8, w8, #3; add w0, w8, #1)
    int channels() const;

    // Opcode 0x64c74: empty
    bool empty() const;

    // Opcode 0x64cac: elemSize1 (byte size per channel depth)
    size_t elemSize1() const;
    size_t elemSize() const;
    size_t total() const { return static_cast<size_t>(rows) * cols; }

    uint8_t* ptr(int row = 0);
    const uint8_t* ptr(int row = 0) const;

    template<typename _Tp>
    _Tp& at(int row, int col) {
        return reinterpret_cast<_Tp*>(ptr(row))[col];
    }

    template<typename _Tp>
    const _Tp& at(int row, int col) const {
        return reinterpret_cast<const _Tp*>(ptr(row))[col];
    }

    Mat clone() const;
    void copyTo(Mat& dst) const;
    void setTo(const Scalar& value);

    void release();

private:
    void allocate();
};

// ==============================================================================
// UMat: Unified Memory Buffer (CPU / GPU / DSP Texture Shared Buffer)
// ==============================================================================
class UMat {
public:
    UMat();
    UMat(int in_rows, int in_cols, int in_type);
    UMat(const UMat& other);
    // Opcode 0x663e0: UMat(UMat, Rect)
    UMat(const UMat& other, const Rect& roi);
    UMat(UMat&& other) noexcept;
    UMat& operator=(UMat&& other) noexcept;
    UMat& operator=(const UMat& other);
    // Opcode 0x66fec: Destructor
    virtual ~UMat();

    // Opcode 0x6783c: type
    int type() const { return mat_.type_; }

    // Opcode 0x67888: elemSize1
    size_t elemSize1() const { return mat_.elemSize1(); }

    // Opcode 0x6787c: elemSize
    size_t elemSize() const { return mat_.elemSize(); }

    int rows() const { return mat_.rows; }
    int cols() const { return mat_.cols; }
    int channels() const { return mat_.channels(); }
    bool empty() const { return mat_.empty(); }

    // Opcode 0x674e8: getMat (CPU read-write mapping)
    Mat getMat(int access_flags = 0) const;
    void getMat(Mat& out_mat);

    // Opcode 0x662bc: AllocateLike
    void AllocateLike(const UMat& other);

    // Opcode 0x67a4c: syncToTexID
    bool syncToTexID(void* tex_id);

    // Opcode 0x67668: syncFromSharedMem
    void syncFromSharedMem();

    const void* getGPUContext() const { return gpu_context_; }

private:
    Mat mat_;
    void* gpu_context_;
    void* texture_id_;
    bool is_gpu_dirty_;
};

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_MAT_H_
