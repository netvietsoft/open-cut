// ============================================================================
// Clean-Room C++17 Core Interfaces for libfast_engine_RelWithDebInfo.so (Target 113 / 169)
// Giao diện lõi C++17 sạch cho libfast_engine_RelWithDebInfo.so (Mục tiêu 113 / 169)
// ============================================================================
#pragma once

#include "fast_engine_rel_types.h"

namespace fast_engine {

// 0x045cbc..0x045cd4 (24 bytes)
bool InitializeImpl();

// 0x045dfc..0x046100 (772 bytes)
void BuildConfigByProvider(FastEngineConfigProvider* provider, FastEngineConfig& out_config);

// FastEngine Singleton (0x120 = 288-byte layout @ .bss 0x143170, guard @ 0x143178)
// Singleton FastEngine (bố cục 0x120 = 288 byte tại .bss 0x143170, biến canh tại 0x143178)
class FastEngine {
public:
    // 0x045cd4..0x045d7c (168 bytes)
    static FastEngine* Instance();

    // 0x045d7c..0x045dfc (128 bytes)
    bool Initialize(const FastEngineConfig& config);

    // 0x046198..0x046220 (136 bytes)
    bool Initialize(FastEngineConfigProvider* provider);

    // 0x046220..0x046230 (16 bytes): add x8, x0, #0x11c; ldarb w8, [x8]; and w0, w8, #1
    bool Initialized() const noexcept;

    // 0x046230..0x04632c (252 bytes)
    void RegisterInitCallback(std::function<void(Engine*)> cb);

    // 0x04632c..0x046394 (104 bytes)
    bool HasFreeVM() const;

    // 0x046394..0x04653c (424 bytes)
    Engine* GetOrCreateVM();

    // 0x04653c..0x046584 (72 bytes)
    void ReleaseVMUsage(Engine* engine) const;

    // 0x046584..0x046660
    void _AddGlobal(const std::string& name, Obj* obj, Engine* engine);
    void AddGlobal(const std::string& name, Obj* obj);

    // 0x046660..0x04686c
    void _AddModule(ModuleObj* mod, Engine* engine, const std::string& name);
    void AddModule(ModuleObj* mod, const std::string& name);

    // 0x04686c..0x046a24
    void _AddCFuncs(const MethodDef* methods, Engine* engine);
    void AddCFuncs(const MethodDef* methods);

    // 0x046a24..0x046b54
    void _AddType(TypeObj* type_obj, Engine* engine, const std::string& name);
    void AddType(TypeObj* type_obj, const std::string& name);

    // 0x046b54..0x046db0 (604 bytes): Base-26 XOR-7 Module Name Encryption
    static std::string EncryptModuleName(const std::string& plain_name);

    // 0x046db0..0x0470dc (812 bytes): Base-26 XOR-7 Module Name Decryption (+0x25 folded offset)
    static std::string DecryptModuleName(std::string& encrypted_name);

    // 0x0470dc..0x0470e4 (8 bytes): ldr x0, [x0, #0x100]; ret
    int64_t GetBuiltinVersion() const noexcept;

private:
    FastEngine();

    mutable std::mutex vm_mutex_;                    // +0x30
    mutable std::condition_variable vm_cv_;          // +0x58
    mutable std::vector<Engine> vms_;                // +0x18..0x28
    std::vector<std::function<void(Engine*)>> init_callbacks_;
    int64_t builtin_version_{0};                     // +0x100
    std::once_flag init_once_flag_;                  // +0x108
    int32_t max_vm_count_{1};                        // +0x110..0x118 (mov w8, #1; str w8, [x0, #0x118] @ 0x045d20)
    int32_t created_vm_count_{0};                    // +0x114
    std::atomic<bool> initialized_{false};           // +0x11c (strb wzr, [x0, #0x11c] @ 0x045d4c)
};

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace fast_engine
