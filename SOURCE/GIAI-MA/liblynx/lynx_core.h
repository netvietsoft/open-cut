// ============================================================================
// Clean-Room C++17 Core Interfaces for liblynx.so (Target 120 / 169)
// Giao diện lõi C++17 sạch cho liblynx.so (Mục tiêu 120 / 169)
// ============================================================================
#pragma once

#include "lynx_types.h"

namespace lynx {
namespace lepus {

// Reconstructed from 0x14c03c..0x14d634 (exact 32-byte lynx::lepus::Value ABI)
// Tái dựng từ 0x14c03c..0x14d634 (bố cục ABI 32-byte chuẩn của lynx::lepus::Value)
class Value {
public:
    using CFunction = Value (*)(Context*);

    Value() noexcept = default;
    // 0x14c03c..0x14c044
    explicit Value(CreateAsUndefinedTag) noexcept;
    // 0x14c048..0x14c0c0
    Value(const Value& other) noexcept;
    // 0x14c228..0x14c278
    Value(Value&& other) noexcept;
    // 0x14c27c..0x14c364
    Value& operator=(const Value& other) noexcept;
    // 0x14c368..0x14c428
    Value& operator=(Value&& other) noexcept;
    ~Value() noexcept { FreeValue(); }

    // 0x14c1b4..0x14c224
    void FreeValue() noexcept;

    // Scalar & Pointer Constructors (0x14c594..0x14c8f4)
    explicit Value(bool val) noexcept;
    explicit Value(void* ptr) noexcept;
    explicit Value(CFunction func) noexcept;
    explicit Value(BuiltinFunctionTable* table) noexcept;
    Value(bool has_val, bool val) noexcept;
    explicit Value(double val) noexcept;
    explicit Value(int32_t val) noexcept;
    explicit Value(uint32_t val) noexcept;
    explicit Value(int64_t val) noexcept;
    explicit Value(uint64_t val) noexcept;
    explicit Value(uint8_t val) noexcept;
    explicit Value(const fml::RefPtr<Dictionary>& dict) noexcept;
    explicit Value(fml::RefPtr<Dictionary>&& dict) noexcept;
    explicit Value(const fml::RefPtr<CArray>& arr) noexcept;
    explicit Value(fml::RefPtr<CArray>&& arr) noexcept;

    ValueType Type() const noexcept { return type_; }
    bool IsReference() const noexcept {
        uint8_t d = static_cast<uint8_t>(type_ - Value_String);
        return d <= 4; // sub w9, w8, #9; cmp w9, #4 @ 0x14c05c
    }
    double Number() const noexcept;

private:
    union Payload {
        uint64_t u64{0};
        int64_t i64;
        double f64;
        int32_t i32;
        uint32_t u32;
        bool b;
        void* ptr;
        fml::RefCountedThreadSafeBase* ref;
    } payload_{};                // +0x00
    ValueType type_{Value_Nil};  // +0x08
    uint8_t pad_09[3]{0};        // +0x09..+0x0b
    int32_t flags_{0};           // +0x0c
    void* env_{nullptr};         // +0x10
    void* ext_ref_{nullptr};     // +0x18
};

} // namespace lepus

namespace shell {

class ListContainerDelegate {
public:
    virtual ~ListContainerDelegate() = default;
    virtual void ScrollByListContainer(int32_t sign, float dx, float dy, float orig_x, float orig_y) = 0; // vtable +0x00
    virtual void ScrollToPosition(int32_t sign, int32_t pos, float offset, int32_t align, bool smooth) = 0; // vtable +0x08
    virtual void ScrollStopped(int32_t sign) = 0;
};

// Reconstructed from 0x2e1bfc..0x2e1c40 (ListContainerProxy)
// Tái dựng từ 0x2e1bfc..0x2e1c40 (ListContainerProxy)
class ListContainerProxy {
public:
    explicit ListContainerProxy(ListContainerDelegate* delegate) noexcept : delegate_(delegate) {}
    void ScrollByListContainer(int32_t sign, float dx, float dy, float orig_x, float orig_y);
    void ScrollToPosition(int32_t sign, int32_t pos, float offset, int32_t align, bool smooth);
    void ScrollStopped(int32_t sign);
private:
    ListContainerDelegate* delegate_{nullptr}; // +0x00
};

// Reconstructed from 0x2ea954..0x2ee748 (LynxShell)
// Tái dựng từ 0x2ea954..0x2ee748 (LynxShell)
class LynxShell {
public:
    struct TasmMediator {
        uint8_t pad_00[0x10]{0};
        void* tasm_ptr{nullptr}; // +0x10
    };

    explicit LynxShell(TasmMediator* mediator) noexcept : mediator_(mediator) {}
    // 0x2ea954: ldr x8, [x0, #0x20]; ldr x8, [x8, #0x10]
    void* GetTasm() const noexcept;

private:
    uint8_t pad_00[0x20]{0};
    TasmMediator* mediator_{nullptr}; // +0x20
};

} // namespace shell

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1);
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1);

} // namespace lynx
