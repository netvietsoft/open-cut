// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_engine_interface.h
// Description: Abstract vtable interfaces and engine factories reconstructed from ABI
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_types.h"
#include <memory>
#include <string>

namespace LENS::FRAMEWORK {

// EN: Base algorithm interface reconstructed from vtable at binary offset 0x35c450
// VN: Giao diện cơ sở của thuật toán tái dựng từ bảng vtable tại offset 0x35c450
class ILensAlgorithmInterface {
public:
    virtual ~ILensAlgorithmInterface() = default;

    // EN: Initialize algorithm with parameters
    // VN: Khởi tạo giải thuật với các tham số
    virtual bool Init(const LensAlgorithmJsonInfo& config) = 0;

    // EN: Process an input frame and write result to output frame
    // VN: Xử lý khung hình đầu vào và ghi kết quả ra khung hình đầu ra
    virtual bool Process(const LensImageFrame& in_frame, LensImageFrame& out_frame) = 0;

    // EN: Reset internal states (e.g. temporal history buffers)
    // VN: Đặt lại trạng thái nội bộ (ví dụ bộ đệm lịch sử thời gian)
    virtual void Reset() = 0;

    // EN: Query algorithm type
    // VN: Truy vấn loại giải thuật
    virtual LensAlgorithmType GetType() const = 0;

    // EN: Get human-readable algorithm name
    // VN: Lấy tên định danh của giải thuật
    virtual const char* GetName() const = 0;
};

// EN: FlowGraph pipeline interface for multi-stage video filters
// VN: Giao diện đồ thị luồng xử lý đa tầng cho bộ lọc video
class ILensFlowGraphInterface {
public:
    virtual ~ILensFlowGraphInterface() = default;
    virtual bool BuildGraph(const std::vector<LensAlgorithmType>& pipeline) = 0;
    virtual bool Execute(const LensImageFrame& src, LensImageFrame& dst) = 0;
    virtual void Clear() = 0;
};

// EN: Central Engine Interface reconstructed from binary symbol 0xb3888
// VN: Giao diện Động cơ Trung tâm tái dựng từ biểu tượng nhị phân 0xb3888
class ILensEngineInterface {
public:
    virtual ~ILensEngineInterface() = default;

    virtual bool Initialize(const std::string& config_json) = 0;
    virtual bool SetAlgorithm(LensAlgorithmType type, const LensAlgorithmJsonInfo& info) = 0;
    virtual bool ProcessFrame(const LensImageFrame& in_frame, LensImageFrame& out_frame) = 0;
    virtual void Release() = 0;
    virtual std::string GetVersion() const = 0;
};

// ===================================================================================
// FACTORIES & UTILITIES (Disassembly Parity)
// ===================================================================================

// EN: Lens Engine Factory - Binary offset 0x2c6550 & 0x2c6574
// VN: Nhà máy tạo Engine Lens - Khớp opcode 0x2c6550 và 0x2c6574
class LensEngineFactory {
public:
    // ARM64 opcode 0x2c6550: Allocates LensEngineImpl instance
    static std::unique_ptr<ILensEngineInterface> CreateLensEngine();

    // ARM64 opcode 0x2c6574: Safely destroys LensEngine instance
    static void ReleaseLensEngine(ILensEngineInterface* engine);
};

// EN: Lens Algorithm Factory - Binary offset 0x2c6588 & 0x2c65dc
// VN: Nhà máy tạo giải thuật - Khớp opcode 0x2c6588 và 0x2c65dc
class LensAlgorithmFactory {
public:
    // ARM64 opcode 0x2c6588: Creates algorithm by type
    static std::unique_ptr<ILensAlgorithmInterface> CreateLensAlgorithm(LensAlgorithmType type);

    // ARM64 opcode 0x2c65dc: Safely destroys algorithm instance
    static void ReleaseLensAlgorithm(ILensAlgorithmInterface* algo);
};

// EN: Lens JSON Parser Utility - Binary offset 0x2c68c0 (GetInfoFromJson)
// VN: Tiện ích giải mã JSON - Khớp opcode 0x2c68c0
class LensAlgorithmUtils {
public:
    static bool GetInfoFromJson(const char* json_str, const char* key, LensAlgorithmJsonInfo* out_info);
};

// EN: Lens EGL/GLES Runtime Loader - Binary offset 0x2c68a8, 0x2c68ac, 0x2c68b8
// VN: Tiện ích nạp thư viện EGL/GLES - Khớp opcode 0x2c68a8, 0x2c68ac, 0x2c68b8
class LensUtils {
public:
    static bool LoadEGLLibrary(const char* lib_name);
    static void UnLoadEGLLibrary();
    static bool LoadEGL(void* (*proc_addr_func)(const char*));
};

} // namespace LENS::FRAMEWORK
