// ============================================================================
// Clean-Room C++17 ABI & Data Structures for libfast_engine_RelWithDebInfo.so (Target 113 / 169)
// Cấu trúc dữ liệu & ABI C++17 sạch cho libfast_engine_RelWithDebInfo.so (Mục tiêu 113 / 169)
// Binary Size: 1,309,048 bytes | SHA-256: 937ec38b3511f7df50b82c02c87db88ec472d8756d7c21e7ecf792c86a7281f8
// .eh_frame_hdr: 2,082 FDEs @ 0x1127c8 | .dynsym: 1,691 Exported Symbols @ 0x006190
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>

namespace fast_engine {

// Constants verified from AArch64 opcodes
// Các hằng số xác minh trực tiếp từ mã máy AArch64
constexpr size_t kFastEngineSingletonBytes = 0x120;      // 288 bytes @ 0x045d14 (mov w0, #0x120)
constexpr size_t kEngineVmInstanceStrideBytes = 0x19450; // 103,504 bytes @ 0x046354 (mov w10, #0x9450; movk w10, #1, lsl #16)
constexpr uint32_t kModuleCipherXorKey = 0x07U;          // eor w13, w13, #7 @ 0x046c24
constexpr uint32_t kModuleCipherBase26 = 26U;            // mov w12, #0x1a @ 0x046c1c
constexpr uint32_t kModuleCipherRecip26 = 0x4EC4EC4FU;   // mov w11, #0xec4f; movk w11, #0x4ec4, lsl #16 @ 0x046c0c
constexpr uint32_t kModuleCipherFoldedAdd = 0x25U;       // add w12, w12, #0x25 @ 0x046f4c (1755 + 37 = 1792 = 7 * 256)

struct Obj {
    int64_t ref_count{1};
    uint32_t type_tag{0};
    uint32_t flags{0};
};

struct TypeObj : public Obj {
    std::string qualname;
};

struct ModuleObj : public Obj {
    std::string module_name;
    std::unordered_map<std::string, Obj*> globals;
};

struct MethodDef {
    const char* ml_name{nullptr};
    void* ml_meth{nullptr};
    int32_t ml_flags{0};
    const char* ml_doc{nullptr};
};

struct FastEngineConfig {
    int32_t max_vm_count{4};
    int64_t builtin_version{202610};
    bool enable_encrypted_modules{true};
    std::string stdlib_archive_path;
};

class FastEngineConfigProvider {
public:
    virtual ~FastEngineConfigProvider() = default;
    virtual int32_t GetMaxVMCount() const = 0;
    virtual int64_t GetBuiltinVersion() const = 0;
    virtual std::string GetStdlibArchivePath() const = 0;
};

// Engine VM Instance (stride 0x19450 = 103,504 bytes in binary vector<Engine>)
// Thực thể máy ảo Engine (bước nhảy 0x19450 = 103,504 bytes trong vector<Engine> nhị phân)
struct Engine {
    int32_t vm_id{0};              // +0x00
    bool is_free{true};            // +0x04 (ldrb w11, [x8, #4] @ 0x04635c; strb wzr, [x22, #4] @ 0x046484)
    uint8_t padding_05[3]{0, 0, 0};
    std::unordered_map<std::string, Obj*> global_objects;
    std::unordered_map<std::string, ModuleObj*> modules;
    std::unordered_map<std::string, TypeObj*> types;
    std::vector<const MethodDef*> c_functions;
};

} // namespace fast_engine
