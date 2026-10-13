// ===================================================================================
// AGFX_ShaderPatcher.h — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Trình vá GLSL Shaders động thích ứng phần cứng di động (ShaderPatcherV2)
// ===================================================================================

#pragma once

#include "AGFX_Types.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace NextAI::OpenCut::AGFX {

class ShaderPatcher {
public:
    ShaderPatcher();
    ~ShaderPatcher();

    // Hàm vá shader cốt lõi: phân tích cú pháp, chèn macros, sửa mảng ma trận
    static std::string patch(
        AMGShaderType shaderType,
        const std::string& originalSource,
        const std::unordered_map<std::string, uint64_t>& activeKeywords,
        int maxVertexUniformVectors = 128
    );

    // Chèn định nghĩa Macro theo danh sách Keywords
    static std::string injectKeywordMacros(
        const std::string& source,
        const std::unordered_map<std::string, uint64_t>& keywords
    );

    // Cắt giảm mảng Uniform Matrix nếu GPU bị giới hạn số vector
    static std::string clampUniformMatrixArrays(
        const std::string& source,
        int maxUniformVectors = 128
    );

    // Chuẩn hóa phiên bản GLSL và độ chính xác (Precision Qualifiers)
    static std::string normalizePrecisionAndVersion(
        AMGShaderType shaderType,
        const std::string& source,
        bool isES3 = true
    );

    // Chuyển đổi sampler2D sang samplerExternalOES cho Camera
    static std::string convertToExternalOES(const std::string& fragmentSource);
};

} // namespace NextAI::OpenCut::AGFX
