/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Graphics Engine
 * File: AGFX_KeywordProgramManager.h
 * Module: libAGFX.so (Amazing Engine / AUSL / KeywordProgramManager.cpp)
 * 
 * Description (EN):
 * Reconstructed ByteDance AUSL (Amazing Universal Shader Language) shader variant
 * system. Implements multi-word 64-bit dynamic bitsets (GlobalKeywordSet & LocalKeywordSet),
 * keyword namespaces (GlobalKeywordSpace & LocalKeywordSpace), shader variant permutation
 * caching, and pipeline instantiation for both GLES Render pipelines and GPGPU Compute pipelines.
 *
 * Mô tả (VI):
 * Tái cấu trúc hệ thống quản lý biến thể Shader AUSL (Amazing Universal Shader Language)
 * của ByteDance. Hiện thực hóa các tập bitmask 64-bit động (GlobalKeywordSet & LocalKeywordSet),
 * không gian từ khóa (GlobalKeywordSpace & LocalKeywordSpace), bộ nhớ đệm hoán vị biến thể shader,
 * và khởi tạo Pipeline kết xuất đồ họa (Render) cũng như tính toán (Compute) trên GLES.
 * ============================================================================
 */

#pragma once

#include "AGFX_Types.h"
#include "AGFX_RendererDevice.h"
#include "AGFX_ComputerDevice.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cstdint>

namespace AmazingEngine {

using GlobalKeyword = uint32_t;
using LocalKeyword  = uint32_t;

class LocalKeywordSpace;
class GlobalKeywordSpace;

/**
 * Dynamic 64-bit Bitset for Shader Variant Permutations
 * Tập hợp Bitmask 64-bit động biểu diễn các từ khóa bật/tắt của Shader
 */
class GlobalKeywordSet {
public:
    GlobalKeywordSet();
    GlobalKeywordSet(const GlobalKeywordSet& other);
    GlobalKeywordSet& operator=(const GlobalKeywordSet& other);

    void enable(GlobalKeyword kw);
    void disable(GlobalKeyword kw);
    bool isEnabled(GlobalKeyword kw) const;
    void clear();
    bool isEmpty() const;

    GlobalKeywordSet unionSet(const GlobalKeywordSet& other) const;
    GlobalKeywordSet intersectionSet(const GlobalKeywordSet& other) const;

    const std::vector<uint64_t>& getWords() const { return m_words; }
    size_t getBitCount() const { return m_bitCount; }

private:
    void ensureCapacity(GlobalKeyword kw);

private:
    std::vector<uint64_t> m_words; // Mảng các từ 64-bit
    size_t m_bitCount = 0;         // Tổng số bit đang theo dõi (Offset 0x18)
};

/**
 * Local Shader Keyword Bitset
 * Tập hợp Bitmask cục bộ của một Shader cụ thể
 */
class LocalKeywordSet {
public:
    LocalKeywordSet();
    LocalKeywordSet(const LocalKeywordSet& other);
    LocalKeywordSet& operator=(const LocalKeywordSet& other);
    bool operator==(const LocalKeywordSet& other) const;
    bool operator!=(const LocalKeywordSet& other) const;

    void enable(LocalKeyword kw);
    void disable(LocalKeyword kw);
    bool isEnabled(LocalKeyword kw) const;
    void clear();
    void reset();
    bool isEmpty() const;
    void expandToKeyword(LocalKeyword kw);
    bool validateSpace(const LocalKeywordSpace* space) const;

    LocalKeywordSet unionSet(const LocalKeywordSet& other) const;
    LocalKeywordSet intersectionSet(const LocalKeywordSet& other) const;

    const std::vector<uint64_t>& getWords() const { return m_words; }

private:
    void ensureCapacity(LocalKeyword kw);

private:
    std::vector<uint64_t> m_words;
    const LocalKeywordSpace* m_space = nullptr;
    size_t m_bitCount = 0;
};

/**
 * Global Keyword Namespace (Global Keyword Space)
 * Quản lý toàn bộ danh sách định danh từ khóa shader toàn cục
 */
class GlobalKeywordSpace {
public:
    static GlobalKeywordSpace& getInstance();

    GlobalKeyword addNewKeyword(const std::string& name);
    GlobalKeyword addNewKeyword(const std::string& name, GlobalKeywordSet& outSet);
    void add(const std::string& name);
    bool isValid(GlobalKeyword kw) const;
    bool set(const std::string& name, bool enabled, GlobalKeywordSet& set);
    void enable(GlobalKeyword kw, GlobalKeywordSet& set);
    void enable(const std::string& name, GlobalKeywordSet& set);
    void disable(GlobalKeyword kw, GlobalKeywordSet& set);
    std::vector<std::string> getKeywordStrList() const;

private:
    GlobalKeywordSpace() = default;

private:
    std::unordered_map<std::string, GlobalKeyword> m_nameToId;
    std::vector<std::string> m_idToName;
};

/**
 * Local Keyword Namespace per Shader Program
 * Quản lý danh sách từ khóa cục bộ gắn riêng với một Shader Program
 */
class LocalKeywordSpace {
public:
    LocalKeywordSpace() = default;

    LocalKeyword addNewKeyword(const std::string& name, bool isGlobal, LocalKeywordSet& set);
    LocalKeyword add(const std::string& name, bool isGlobal);
    LocalKeyword find(const std::string& name) const;
    bool isValid(LocalKeyword kw) const;
    void enable(const std::string& name, LocalKeywordSet& set) const;
    void enable(LocalKeyword kw, LocalKeywordSet& set) const;
    void disable(const std::string& name, LocalKeywordSet& set) const;
    void disable(LocalKeyword kw, LocalKeywordSet& set) const;
    void clear();

    void unionGlobalKeywordSet(const GlobalKeywordSet& globalSet, const LocalKeywordSet& localIn, LocalKeywordSet& localOut) const;

private:
    std::unordered_map<std::string, LocalKeyword> m_nameToId;
    std::vector<std::string> m_idToName;
    std::vector<bool> m_isGlobal;
};

/**
 * SubProgram Definition: A single compiled GLSL variant
 * Một biến thể Shader đã biên dịch (GLSL source hoặc Binary blob)
 */
struct SubProgramDesc {
    AMGShaderType shaderType = AMGShaderType::Vertex;
    std::string sourceCode;
    std::vector<uint8_t> binaryBytecode;
    uint32_t binaryFormat = 0;
};

class SubProgram {
public:
    SubProgram();
    virtual ~SubProgram();

    void setSource(const char* src, int length);
    void setNativeCode(const char* bytecode, int length);

    const std::string& getSource() const { return m_source; }
    const std::vector<uint8_t>& getBytecode() const { return m_bytecode; }

private:
    std::string m_source;
    std::vector<uint8_t> m_bytecode;
};

struct SubProgramPeekInfo {
    AMGShaderType type;
    uint32_t keywordHash;
    uint32_t binaryOffset;
    uint32_t binarySize;
};

/**
 * Shader Keyword Program Handle
 */
struct handle_ShaderKeywordProgram_t {
    std::string name;
    LocalKeywordSpace localSpace;
    std::vector<SubProgram*> subPrograms;
    std::unordered_map<uint64_t, handle_RenderPipeline_t*> renderPipelines;
    std::unordered_map<uint64_t, handle_ComputePipeline_t*> computePipelines;
};

/**
 * KeywordProgramManager
 * Bộ quản lý nạp và hoán vị biến thể Shader của toàn bộ Amazing Engine
 */
class KeywordProgramManager {
public:
    KeywordProgramManager();
    virtual ~KeywordProgramManager();

    void deinit();

    // Program creation & registration
    handle_ShaderKeywordProgram_t* createKeywordProgram(
        const std::string& name,
        std::function<char*(const std::string&, int&)> loaderCallback
    );

    void addSubProgram(
        handle_ShaderKeywordProgram_t* program,
        AMGShaderType shaderType,
        SubProgramDesc& desc,
        const LocalKeywordSet& keywordSet
    );

    void readSubProgramInfos(
        handle_ShaderKeywordProgram_t* program,
        const std::vector<SubProgramPeekInfo>& peekInfos
    );

    void readNativeSubProgramInfos(
        handle_ShaderKeywordProgram_t* program,
        const std::vector<SubProgramPeekInfo>& peekInfos
    );

    // Pipeline generation based on active keyword sets
    handle_RenderPipeline_t* createRenderPipeline(
        RendererDevice* renderer,
        handle_ShaderKeywordProgram_t* program,
        const VertexAttribMapWrap& attribWrap,
        const LocalKeywordSet& keywordSet
    );

    handle_ComputePipeline_t* createComputePipeline(
        ComputerDevice* computer,
        handle_ShaderKeywordProgram_t* program,
        const LocalKeywordSet& keywordSet
    );

    handle_ComputePipeline_t* createExplicitComputePipeline(
        ComputerDevice* computer,
        handle_ShaderKeywordProgram_t* program,
        const LocalKeywordSet& keywordSet
    );

    // Global keyword manipulation
    void enableGlobalKeyword(RendererType rType, const GlobalKeyword& kw);
    GlobalKeywordSet getGlobalKeywordSet(RendererType rType) const;
    GlobalKeywordSet getGlobalKeywordSet() const;

private:
    uint64_t hashKeywordSet(const LocalKeywordSet& set) const;

private:
    std::unordered_map<std::string, handle_ShaderKeywordProgram_t*> m_programs;
    GlobalKeywordSet m_globalKeywordSet;
};

} // namespace AmazingEngine
