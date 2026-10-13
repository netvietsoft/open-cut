// ===================================================================================
// AGFX_ShaderPatcher.cpp — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Mô tả: Cài đặt chi tiết toàn bộ thuật toán vá Shaders của ByteDance
// ===================================================================================

#include "AGFX_ShaderPatcher.h"
#include <sstream>
#include <regex>
#include <iostream>

namespace NextAI::OpenCut::AGFX {

ShaderPatcher::ShaderPatcher() = default;
ShaderPatcher::~ShaderPatcher() = default;

std::string ShaderPatcher::patch(
    AMGShaderType shaderType,
    const std::string& originalSource,
    const std::unordered_map<std::string, uint64_t>& activeKeywords,
    int maxVertexUniformVectors
) {
    if (originalSource.empty()) {
        return "";
    }

    std::string patched = originalSource;

    // Bước 1: Chuẩn hóa phiên bản GLSL và khai báo độ chính xác precision
    patched = normalizePrecisionAndVersion(shaderType, patched, true);

    // Bước 2: Chèn các định nghĩa tiền xử lý #define cho các Keywords đang bật
    patched = injectKeywordMacros(patched, activeKeywords);

    // Bước 3: Kiểm tra và cắt giảm mảng Uniform Matrix nếu GPU vượt ngưỡng giới hạn
    if (shaderType == AMGShaderType::VertexShader) {
        patched = clampUniformMatrixArrays(patched, maxVertexUniformVectors);
    }

    return patched;
}

std::string ShaderPatcher::injectKeywordMacros(
    const std::string& source,
    const std::unordered_map<std::string, uint64_t>& keywords
) {
    std::ostringstream macroStream;
    macroStream << "\n// --- INJECTED AGFX KEYWORDS MACROS ---\n";
    for (const auto& kv : keywords) {
        macroStream << "#define " << kv.first << " 1\n";
    }
    macroStream << "// -------------------------------------\n\n";

    // Chèn ngay sau dòng #version đầu tiên (nếu có)
    size_t versionPos = source.find("#version");
    if (versionPos != std::string::npos) {
        size_t lineEnd = source.find('\n', versionPos);
        if (lineEnd != std::string::npos) {
            std::string before = source.substr(0, lineEnd + 1);
            std::string after = source.substr(lineEnd + 1);
            return before + macroStream.str() + after;
        }
    }

    // Nếu không có #version, chèn lên đầu file
    return macroStream.str() + source;
}

std::string ShaderPatcher::clampUniformMatrixArrays(
    const std::string& source,
    int maxUniformVectors
) {
    // Tìm các khai báo ma trận: uniform mat4 u_Bones[100];
    // Regex tìm kiếm: uniform\s+mat4\s+(\w+)\s*\[\s*(\d+)\s*\];
    std::regex mat4Regex(R"(uniform\s+mat4\s+(\w+)\s*\[\s*(\d+)\s*\];)");
    std::string result = source;
    std::smatch match;

    std::string currentStr = source;
    std::ostringstream output;
    size_t lastIndex = 0;

    auto words_begin = std::sregex_iterator(source.begin(), source.end(), mat4Regex);
    auto words_end = std::sregex_iterator();

    bool modified = false;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch m = *i;
        std::string varName = m[1].str();
        int arraySize = std::stoi(m[2].str());

        // Mỗi mat4 chiếm 4 vectors uniform. Nếu arraySize * 4 vượt quá giới hạn GPU:
        if (arraySize * 4 > maxUniformVectors) {
            int newSize = 50; // Thu nhỏ mảng ma trận xương xương tối đa 50 theo log ByteDance
            if (newSize * 4 > maxUniformVectors) {
                newSize = maxUniformVectors / 4;
            }
            std::string replacement = "uniform mat4 " + varName + "[" + std::to_string(newSize) + "]; // [ShaderPatcherV2] Clamped from " + std::to_string(arraySize);
            
            output << source.substr(lastIndex, m.position() - lastIndex);
            output << replacement;
            lastIndex = m.position() + m.length();
            modified = true;
        }
    }

    if (modified) {
        output << source.substr(lastIndex);
        return output.str();
    }

    return source;
}

std::string ShaderPatcher::normalizePrecisionAndVersion(
    AMGShaderType shaderType,
    const std::string& source,
    bool isES3
) {
    std::ostringstream header;
    if (source.find("#version") == std::string::npos) {
        if (isES3) {
            header << "#version 300 es\n";
        } else {
            header << "#version 100\n";
        }
    }

    // Luôn đảm bảo có độ chính xác float trên fragment shader để tránh lỗi compile trên Adreno
    if (shaderType == AMGShaderType::FragmentShader && source.find("precision") == std::string::npos) {
        header << "#ifdef GL_ES\nprecision highp float;\nprecision mediump int;\n#endif\n";
    }

    return header.str() + source;
}

std::string ShaderPatcher::convertToExternalOES(const std::string& fragmentSource) {
    std::string res = fragmentSource;
    // Bổ sung extension mở rộng OES
    std::string extHeader = "#extension GL_OES_EGL_image_external : require\n#extension GL_OES_EGL_image_external_essl3 : enable\n";
    
    // Thay thế sampler2D u_CameraTexture -> samplerExternalOES u_CameraTexture
    res = std::regex_replace(res, std::regex(R"(uniform\s+sampler2D\s+)"), "uniform samplerExternalOES ");
    
    // Thay thế texture2D -> texture
    res = extHeader + res;
    return res;
}

} // namespace NextAI::OpenCut::AGFX
