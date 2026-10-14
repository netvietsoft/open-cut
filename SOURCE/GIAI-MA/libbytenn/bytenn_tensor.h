// ======================================================================
// RECONSTRUCTED HEADER: bytenn_tensor.h
// Library: libbytenn.so (ByteDance ByteNN Inference Engine)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   High-performance n-dimensional Tensor representation with 64-byte
//   cacheline alignment, NCHW/NHWC layout conversion, int8/uint8
//   quantization, and exact AArch64 binary ABI parity.
//
// Mô tả (Tiếng Việt):
//   Cấu trúc biểu diễn Tensor đa chiều hiệu năng cao với căn chỉnh bộ nhớ
//   64-byte theo cacheline, chuyển đổi bố cục NCHW/NHWC, lượng tử hóa
//   int8/uint8 và tương thích hoàn toàn layout ABI ARM64.
// ======================================================================

#pragma once

#include "bytenn_types.h"
#include <vector>
#include <memory>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace NextAI::OpenCut::bytenn {

// ----------------------------------------------------------------------
// BYTENN::Tensor (Lớp Tensor cốt lõi của ByteNN)
// Binary offsets:
//   - GetDataCount: 0x3aae0 (n * c * h * w)
//   - GetByteSize: 0x3aaf8 (data_count * type_size[data_type])
// ----------------------------------------------------------------------
class Tensor {
public:
    Tensor();
    Tensor(int32_t n, int32_t c, int32_t h, int32_t w, 
           DataType dtype = DataType::FLOAT32, 
           DataFormat format = DataFormat::NCHW);
    Tensor(const std::vector<int32_t>& shape, 
           DataType dtype = DataType::FLOAT32, 
           DataFormat format = DataFormat::NCHW);
    Tensor(const Tensor& other);
    Tensor(Tensor&& other) noexcept;
    virtual ~Tensor();

    Tensor& operator=(const Tensor& other);
    Tensor& operator=(Tensor&& other) noexcept;

    // Kích thước và thông tin hình dạng (Dimensions & Shape)
    int32_t Batch() const noexcept { return shape_[0]; }
    int32_t Channel() const noexcept { return shape_[1]; }
    int32_t Height() const noexcept { return shape_[2]; }
    int32_t Width() const noexcept { return shape_[3]; }
    const std::vector<int32_t>& Shape() const noexcept { return shape_; }
    void Reshape(int32_t n, int32_t c, int32_t h, int32_t w);
    void Reshape(const std::vector<int32_t>& shape);

    // Tính toán số phần tử và dung lượng bytes theo đúng mã máy AArch64
    // GetDataCount() at opcode 0x3aae0:
    //   mul x8, x9, x8; mul x8, x8, x10; mul x0, x8, x11; ret
    size_t GetDataCount() const noexcept;

    // GetByteSize() at opcode 0x3aaf8:
    //   tra cứu kích thước phần tử từ bảng nhị phân 0x263b98 và nhân số phần tử
    size_t GetByteSize() const noexcept;

    // Kiểu dữ liệu và bố cục (Type & Layout)
    DataType GetDataType() const noexcept { return data_type_; }
    void SetDataType(DataType dtype);
    DataFormat GetDataFormat() const noexcept { return format_; }
    void SetDataFormat(DataFormat fmt) { format_ = fmt; }

    // Quản lý bộ nhớ đệm (Buffer Access)
    void* RawData() noexcept { return data_buffer_; }
    const void* RawData() const noexcept { return data_buffer_; }

    template <typename T>
    T* Data() noexcept {
        return reinterpret_cast<T*>(data_buffer_);
    }

    template <typename T>
    const T* Data() const noexcept {
        return reinterpret_cast<const T*>(data_buffer_);
    }

    // Cấp phát & Giải phóng bộ nhớ căn chỉnh 64 bytes (Cacheline aligned)
    void Allocate();
    void Deallocate() noexcept;

    // Gán dữ liệu từ con trỏ ngoài
    void CopyFrom(const void* src, size_t byte_count);
    void CopyTo(void* dst, size_t byte_count) const;
    void FillZeros();
    void FillConstant(float val);

    // Chuyển đổi bố cục NCHW <-> NHWC
    Tensor ToFormat(DataFormat target_format) const;
    void ConvertNCHWtoNHWC(const float* src, float* dst) const;
    void ConvertNHWCtoNCHW(const float* src, float* dst) const;

    // Lượng tử hóa & Giải lượng tử hóa (Quantization & Dequantization)
    QuantParams GetQuantParams() const noexcept { return quant_params_; }
    void SetQuantParams(const QuantParams& qp) noexcept { quant_params_ = qp; }

    Tensor Quantize(float scale, int32_t zero_point, DataType target_type = DataType::INT8) const;
    Tensor Dequantize() const;

    // Lấy phần tử theo chỉ mục đa chiều (Element accessor)
    float GetFloat(int32_t n, int32_t c, int32_t h, int32_t w) const;
    void SetFloat(int32_t n, int32_t c, int32_t h, int32_t w, float val);

    // Tên lớp / tên tensor (Layer/Tensor Name)
    const std::string& GetName() const noexcept { return name_; }
    void SetName(const std::string& name) { name_ = name; }

    // Bảng tra cứu kích thước phần tử tương thích 100% bảng 0x263b98
    static size_t GetTypeElementSize(DataType dtype) noexcept;

protected:
    std::string name_{""};
    std::vector<int32_t> shape_{1, 1, 1, 1}; // N, C, H, W
    DataType data_type_{DataType::FLOAT32};
    DataFormat format_{DataFormat::NCHW};
    void* data_buffer_{nullptr};
    size_t allocated_bytes_{0};
    bool owns_buffer_{true};
    QuantParams quant_params_;
};

// ----------------------------------------------------------------------
// BYTENN::TensorExt (Lớp mở rộng hỗ trợ GPU / Texture IO)
// Demangled: BYTENN::TensorExt (opcode 0x2f674)
// ----------------------------------------------------------------------
class TensorExt : public Tensor {
public:
    TensorExt();
    TensorExt(int32_t n, int32_t c, int32_t h, int32_t w, 
              DataType dtype = DataType::FLOAT32, 
              DataFormat format = DataFormat::NCHW);
    virtual ~TensorExt() override;

    // GPU Texture & HardwareBuffer bindings
    void SetTextureId(uint32_t tex_id) noexcept { texture_id_ = tex_id; }
    uint32_t GetTextureId() const noexcept { return texture_id_; }

    void SetDeviceBuffer(void* dev_buf) noexcept { device_buffer_ = dev_buf; }
    void* GetDeviceBuffer() const noexcept { return device_buffer_; }

    void SetHardwareBuffer(void* ahb) noexcept { ahardware_buffer_ = ahb; }
    void* GetHardwareBuffer() const noexcept { return ahardware_buffer_; }

    void SetTextureTarget(uint32_t target) noexcept { texture_target_ = target; } // GL_TEXTURE_2D
    uint32_t GetTextureTarget() const noexcept { return texture_target_; }

    DeviceIOType GetDeviceIOType() const noexcept { return io_type_; }
    void SetDeviceIOType(DeviceIOType t) noexcept { io_type_ = t; }

private:
    uint32_t texture_id_{0};
    uint32_t texture_target_{0x0DE1}; // GL_TEXTURE_2D
    void* device_buffer_{nullptr};
    void* ahardware_buffer_{nullptr};
    DeviceIOType io_type_{DeviceIOType::HOST_BUFFER};
};

} // namespace NextAI::OpenCut::bytenn
