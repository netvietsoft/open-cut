// ============================================================================
// File: npth_unwind_regs_dwarf.h
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 declarations for unwindstack::Regs, unwindstack::RegsArm64,
// unwindstack::Registers (0x02f8f8..0x030750), Exynos 9810 hardware bug check
// (0x00cde0..0x00ce70), DWARF CFA/OP table evaluators (.rodata 0x0079ca &
// 0x007bc8), and XZ/SHA-256 .gnu_debugdata stream verification (.rodata
// 0x0077b0..0x0079ca).
//
// Mô tả (VI):
// Khai báo C++17 tái tạo sạch cho unwindstack::Regs, unwindstack::RegsArm64,
// unwindstack::Registers (0x02f8f8..0x030750), kiểm tra lỗi phần cứng Exynos
// 9810 (0x00cde0..0x00ce70), bộ giải mã bảng DWARF CFA/OP (.rodata 0x0079ca &
// 0x007bc8) và bộ kiểm định luồng XZ/SHA-256 .gnu_debugdata (.rodata
// 0x0077b0..0x0079ca).
// ============================================================================

#pragma once

#include "npth_unwind_types.h"

namespace unwindstack {

// ============================================================================
// 1. Regs & RegsArm64 (0x58 = 88 bytes, vtable at .data.rel.ro 0x039510)
// Verified from 0x030374..0x030750.
// Lớp cơ sở thanh ghi và lớp thanh ghi AArch64 (0x58 = 88 byte).
// ============================================================================
class Regs {
public:
    Regs(uint16_t total_regs, uint16_t last_regs, uint16_t return_address_reg) noexcept;
    virtual ~Regs();

    virtual ArchEnum Arch() const noexcept = 0;
    virtual uint64_t pc() const noexcept = 0;
    virtual uint64_t sp() const noexcept = 0;
    virtual void set_pc(uint64_t pc) noexcept = 0;
    virtual void set_sp(uint64_t sp) noexcept = 0;
    virtual bool SetPcFromReturnAddress(Memory* process_memory) noexcept = 0;
    virtual void IterateRegisters(std::function<void(const char*, uint64_t)> fn) const = 0;
    virtual Regs* Clone() const = 0;

    uint16_t total_regs() const noexcept { return total_regs_; }
    uint16_t last_regs() const noexcept { return last_regs_; }
    uint16_t return_address_reg() const noexcept { return return_address_reg_; }

    uint64_t dex_pc() const noexcept { return dex_pc_; }
    void set_dex_pc(uint64_t dex_pc) noexcept { dex_pc_ = dex_pc; }

    uint64_t* RawData() noexcept { return regs_.data(); }
    const uint64_t* RawData() const noexcept { return regs_.data(); }

    uint64_t operator[](size_t reg) const noexcept {
        return (reg < regs_.size()) ? regs_[reg] : 0ULL;
    }
    uint64_t& operator[](size_t reg) noexcept {
        return regs_[reg];
    }

    bool vregs_enabled() const noexcept { return vregs_enabled_; }
    void enable_vregs(); // 0x0303dc..0x030510
    uint64_t* vregs_data() noexcept { return vregs_.empty() ? nullptr : vregs_.data(); }
    const uint64_t* vregs_data() const noexcept { return vregs_.empty() ? nullptr : vregs_.data(); }
    size_t total_vregs() const noexcept { return vregs_.size(); }

    void SetPacMask(uint64_t mask) noexcept { pac_mask_ = mask; }
    uint64_t pac_mask() const noexcept { return pac_mask_; }

    static Regs* RemoteGet(int pid, ErrorCode* error_code = nullptr); // 0x030518..0x030624
    static Regs* CreateFromUcontext(void* ucontext);                  // 0x030628..0x0306a0
    static Regs* CreateFromLocal();                                   // 0x0306a4..0x03071c

protected:
    uint16_t total_regs_ = REG_ARM64_MAX;          // +0x08 (0x22 = 34)
    uint16_t last_regs_ = 1;                       // +0x0A (0x0001)
    uint16_t return_address_reg_ = REG_ARM64_LR;   // +0x0C (0x001E = 30)
    bool vregs_enabled_ = false;                   // +0x0E (strb wzr, [x0, #0xe])
    uint8_t pad_0f_ = 0;                           // +0x0F
    uint64_t dex_pc_ = 0;                          // +0x10
    std::vector<uint64_t> regs_;                   // +0x18..0x2F (34 * 8 = 0x110 B)
    uint64_t pac_mask_ = 0;                        // +0x30
    uint64_t pad_38_ = 0;                          // +0x38
    std::vector<uint64_t> vregs_;                  // +0x40..0x57 (8 * 8 = 0x40 B when enabled)
};

class RegsArm64 final : public Regs {
public:
    RegsArm64();
    ~RegsArm64() override;

    ArchEnum Arch() const noexcept override { return ARCH_ARM64; }
    uint64_t pc() const noexcept override;
    uint64_t sp() const noexcept override;
    void set_pc(uint64_t pc) noexcept override;
    void set_sp(uint64_t sp) noexcept override;
    bool SetPcFromReturnAddress(Memory* process_memory) noexcept override;
    void IterateRegisters(std::function<void(const char*, uint64_t)> fn) const override;
    Regs* Clone() const override; // 0x030374..0x0303d8
};

// ============================================================================
// 2. Registers Wrapper Class (0x10 = 16 bytes)
// Verified from 0x02f8f8..0x030370 (23 exported STT_FUNC symbols in .dynsym).
// Lớp bao bọc Registers (0x10 = 16 byte, gồm 23 hàm xuất khẩu trong .dynsym).
// ============================================================================
class Registers {
public:
    explicit Registers(Regs* regs = nullptr) noexcept; // 0x02f8f8
    ~Registers();                                      // 0x02f900

    Registers(Registers&& other) noexcept;             // 0x02f920
    Registers& operator=(Registers&& other) noexcept;  // 0x02f938

    Registers(const Registers&) = delete;
    Registers& operator=(const Registers&) = delete;

    uint64_t pc() const noexcept;                      // 0x02f974 (ldr x0, [x8, #0x100])
    uint64_t sp() const noexcept;                      // 0x02f990 (ldr x0, [x8, #0xf8])
    uint64_t dex_pc() const noexcept;                  // 0x02f9ac (ldr x0, [x8, #0x10])
    void* RawData() noexcept;                          // 0x02f9c4 (ldr x0, [x8, #0x18])
    const void* RawData() const noexcept;              // 0x02f9c4
    void IterateRegisters(std::function<void(const char*, uint64_t)> fn) const; // 0x02f9dc (2,060 B)

    void create(Regs* regs) noexcept;                  // 0x0301e8
    void CreateFromUcontext(void* ucontext);           // 0x030218
    void CreateFromLocal();                            // 0x030254
    bool RemoteGet(int pid);                           // 0x03028c

    uint16_t total_regs() const noexcept;              // 0x0302d4 (ldrh w0, [x8, #8])
    Registers Clone() const;                           // 0x0302ec
    bool vregs_enabled() const noexcept;               // 0x03030c (ldrb w8, [x8, #0xe])
    void enable_vregs();                               // 0x03032c
    uint64_t* vregs_data() noexcept;                   // 0x03033c (ldr x0, [x8, #0x40])
    const uint64_t* vregs_data() const noexcept;       // 0x03033c
    size_t total_vregs() const noexcept;               // 0x030354 (sub/lsr #3)

    Regs* get() const noexcept { return regs_; }

private:
    Regs* regs_ = nullptr;                  // +0x00
    std::unique_ptr<Regs> owned_regs_;      // +0x08
};

// ============================================================================
// 3. Hardware Bug Detection, Register Name Table, DWARF & SHA-256 Helpers
// Các hàm phụ trợ kiểm tra lỗi phần cứng Exynos 9810, bảng tên thanh ghi và
// giải mã DWARF / SHA-256.
// ============================================================================
const std::array<const char*, REG_ARM64_MAX>& GetArm64RegisterNames() noexcept;
bool CheckExynos9810Arm64Bug(uint64_t hwcap, const char* ro_arch_prop) noexcept; // 0x00cde0..0x00ce70
bool VerifyXzStreamHeaderMagic(const uint8_t* data, size_t size) noexcept;       // 0x0079c4
std::array<uint8_t, 32> ComputeUnwindSha256(const uint8_t* data, size_t len) noexcept;
const std::vector<DwarfOpTableEntry>& GetDwarfOpTable() noexcept;                // 0x007bc8..0x007ee8

} // namespace unwindstack
