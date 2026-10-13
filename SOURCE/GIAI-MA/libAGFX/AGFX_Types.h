// ===================================================================================
// AGFX_Types.h — NextAI OpenCut / CapCut Reconstructed Core
// Thư viện gốc: libAGFX.so (ByteDance Amazing Graphics Effects Engine)
// Bản quyền phân tích: com.nextai.opencut (Reconstruction Edition)
// Mô tả: Định nghĩa toàn bộ kiểu dữ liệu, Enums, Handles, Vectors và cấu trúc bộ nhớ
// ===================================================================================

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace NextAI::OpenCut::AGFX {

// --- ENUM: LOẠI TRÌNH RENDER ĐỒ HỌA (RENDERER TYPE) ---
enum class RendererType : int32_t {
    GLES2    = 0, // OpenGL ES 2.0 (Thiết bị thấp cấp)
    GLES30   = 1, // OpenGL ES 3.0 (Thiết bị trung bình, hỗ trợ VAO, MRT)
    GLES31   = 2, // OpenGL ES 3.1 (Hỗ trợ Compute Shaders GPGPU, SSBO)
    Vulkan   = 3, // Vulkan 1.1+ (Hiệu năng cao trên Android mới)
    Metal    = 4, // Apple Metal (iOS / macOS)
    Angle    = 5  // Google Angle (Windows EGL translation)
};

// --- ENUM: ĐỊNH DẠNG PIXEL HỖ TRỢ (AMG PIXEL FORMAT) ---
enum class AMGPixelFormat : uint32_t {
    Unknown         = 0,
    RGBA8           = 1,
    RGB8            = 2,
    BGRA8           = 3,
    RGBA16F         = 4,
    RGBA32F         = 5,
    R8              = 6,
    RG8             = 7,
    Depth24Stencil8 = 8,
    Depth32F        = 9,
    // Dải định dạng nén texture ASTC (0xA4 đến 0xBF)
    ASTC_4x4_RGBA   = 0xA4, // 164
    ASTC_5x4_RGBA   = 0xA5,
    ASTC_5x5_RGBA   = 0xA6,
    ASTC_6x5_RGBA   = 0xA7,
    ASTC_6x6_RGBA   = 0xA8,
    ASTC_8x5_RGBA   = 0xA9,
    ASTC_8x6_RGBA   = 0xAA,
    ASTC_8x8_RGBA   = 0xAB,
    ASTC_10x5_RGBA  = 0xAC,
    ASTC_10x6_RGBA  = 0xAD,
    ASTC_10x8_RGBA  = 0xAE,
    ASTC_10x10_RGBA = 0xAF,
    ASTC_12x10_RGBA = 0xB0,
    ASTC_12x12_RGBA = 0xB1, // 177
    ASTC_4x4_sRGB   = 0xB2,
    ASTC_5x4_sRGB   = 0xB3,
    ASTC_5x5_sRGB   = 0xB4,
    ASTC_6x5_sRGB   = 0xB5,
    ASTC_6x6_sRGB   = 0xB6,
    ASTC_8x5_sRGB   = 0xB7,
    ASTC_8x6_sRGB   = 0xB8,
    ASTC_8x8_sRGB   = 0xB9,
    ASTC_10x5_sRGB  = 0xBA,
    ASTC_10x6_sRGB  = 0xBB,
    ASTC_10x8_sRGB  = 0xBC,
    ASTC_10x10_sRGB = 0xBD,
    ASTC_12x10_sRGB = 0xBE,
    ASTC_12x12_sRGB = 0xBF  // 191 (ASTC Range: 164 - 191)
};

// --- ENUM: CHẾ ĐỘ LỌC TEXTURE (FILTER & WRAP MODES) ---
enum class AMGFilterMode : int32_t {
    Nearest = 0,
    Linear  = 1
};

enum class AMGFilterMipmapMode : int32_t {
    None    = 0,
    Nearest = 1,
    Linear  = 2
};

enum class AMGWrapMode : int32_t {
    Repeat        = 0,
    ClampToEdge   = 1,
    MirroredRepeat = 2
};

enum class AMGShaderType : int32_t {
    VertexShader   = 0,
    FragmentShader = 1,
    ComputeShader  = 2
};

enum class ImageType : int32_t {
    Texture2D       = 0,
    TextureExternal = 1, // GL_TEXTURE_EXTERNAL_OES cho Camera & Video
    Texture3D       = 2, // 3D LUT Color Grading
    TextureCube     = 3  // Skybox / Môi trường phản xạ
};

enum class SymbolType : int32_t {
    Int       = 0,
    Float     = 1,
    Vector2   = 2,
    Vector3   = 3,
    Vector4   = 4,
    Matrix4x4 = 5,
    Texture   = 6
};

// --- CẤU TRÚC TOÁN HỌC VECTOR ---
struct Vector3f {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vector3f() = default;
    Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Vector4f {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    Vector4f() = default;
    Vector4f(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
};

// --- HANDLES NATIVE GPU RESOURCES ---
using DeviceTexture = uint64_t;

struct handle_DeviceSequence_t {
    uint32_t sequenceId = 0;
    bool isCompleted = false;
};

struct handle_DeviceFramebuffer_t {
    uint32_t fboId = 0;
    uint32_t width = 0;
    uint32_t height = 0;
};

struct handle_DeviceBuffer_t {
    uint32_t vboId = 0;
    uint32_t sizeBytes = 0;
    uint32_t usage = 0;
};

struct handle_RenderPipeline_t {
    uint32_t programId = 0;
    std::string pipelineName;
};

struct handle_RenderEntity_t {
    uint32_t entityId = 0;
    bool visible = true;
};

struct handle_ComputeEntity_t {
    uint32_t computeProgramId = 0;
    uint32_t workGroupSize[3] = {16, 16, 1};
};

struct handle_DeviceFence_t {
    void* syncObject = nullptr;
};

struct handle_ShaderKeywordProgram_t {
    uint32_t programVariantId = 0;
    uint64_t keywordBits = 0;
};

// --- CẤU TRÚC THÔNG SỐ KHỞI TẠO BỘ ĐỆM & TEXTURE ---
struct framebuffer_clear_info {
    bool clearColor = true;
    bool clearDepth = true;
    bool clearStencil = false;
    float color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float depth = 1.0f;
    int32_t stencil = 0;
};

struct tex_create_info {
    int32_t width = 0;
    int32_t height = 0;
    int32_t depth = 1;
    AMGPixelFormat format = AMGPixelFormat::RGBA8;
    AMGFilterMode minFilter = AMGFilterMode::Linear;
    AMGFilterMode magFilter = AMGFilterMode::Linear;
    AMGWrapMode wrapS = AMGWrapMode::ClampToEdge;
    AMGWrapMode wrapT = AMGWrapMode::ClampToEdge;
    float maxAnisotropy = 1.0f;
};

struct SubProgramPeekInfo {
    uint32_t subProgramId = 0;
    uint32_t byteCodeOffset = 0;
    uint32_t byteCodeSize = 0;
};

} // namespace NextAI::OpenCut::AGFX
