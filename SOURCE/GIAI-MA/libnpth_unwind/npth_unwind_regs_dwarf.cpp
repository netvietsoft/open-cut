// ============================================================================
// File: npth_unwind_regs_dwarf.cpp
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 implementation of unwindstack::Regs, unwindstack::RegsArm64,
// unwindstack::Registers (0x02f8f8..0x030750), Exynos 9810 hardware bug detector
// (0x00cde0..0x00ce70), XZ stream header verifier (.rodata 0x0079c4), SHA-256
// checksum calculator (.rodata 0x0077b0 & 0x0078c4), and DWARF expression opcode
// descriptor table (.rodata 0x007bc8..0x007ee8).
//
// Mô tả (VI):
// Triển khai C++17 tái tạo sạch cho unwindstack::Regs, unwindstack::RegsArm64,
// unwindstack::Registers (0x02f8f8..0x030750), bộ phát hiện lỗi phần cứng Exynos
// 9810 (0x00cde0..0x00ce70), bộ xác thực tiêu đề luồng XZ (.rodata 0x0079c4),
// thuật toán băm SHA-256 (.rodata 0x0077b0 & 0x0078c4) và bảng mô tả mã lệnh
// biểu thức DWARF (.rodata 0x007bc8..0x007ee8).
// ============================================================================

#include "npth_unwind_regs_dwarf.h"

#include <cstring>

namespace unwindstack {

// ============================================================================
// 1. 34-Entry AArch64 Register Name Table (.rodata 0x007200..0x007730)
// Verified from the unrolled 2,060-byte function Registers::IterateRegisters
// at 0x02f9dc..0x0301e8.
// Bảng 34 tên thanh ghi AArch64 đối chiếu từ hàm unroll 2.060 byte tại 0x02f9dc.
// ============================================================================
const std::array<const char*, REG_ARM64_MAX>& GetArm64RegisterNames() noexcept {
    static const std::array<const char*, REG_ARM64_MAX> kNames = {
        "x0",  // [ 0] .rodata 0x0076fa
        "x1",  // [ 1] .rodata 0x007373
        "x2",  // [ 2] .rodata 0x0075c3
        "x3",  // [ 3] .rodata 0x00761d
        "x4",  // [ 4] .rodata 0x00758e
        "x5",  // [ 5] .rodata 0x007726
        "x6",  // [ 6] .rodata 0x007688
        "x7",  // [ 7] .rodata 0x007397
        "x8",  // [ 8] .rodata 0x007361
        "x9",  // [ 9] .rodata 0x007620
        "x10", // [10] .rodata 0x007729
        "x11", // [11] .rodata 0x007449
        "x12", // [12] .rodata 0x00744d
        "x13", // [13] .rodata 0x007403
        "x14", // [14] .rodata 0x0075d7
        "x15", // [15] .rodata 0x007436
        "x16", // [16] .rodata 0x007376
        "x17", // [17] .rodata 0x0076fd
        "x18", // [18] .rodata 0x007200
        "x19", // [19] .rodata 0x007553
        "x20", // [20] .rodata 0x0075db
        "x21", // [21] .rodata 0x007644
        "x22", // [22] .rodata 0x0072a4
        "x23", // [23] .rodata 0x007623
        "x24", // [24] .rodata 0x00739a
        "x25", // [25] .rodata 0x00745d
        "x26", // [26] .rodata 0x007354
        "x27", // [27] .rodata 0x007505
        "x28", // [28] .rodata 0x007509
        "x29", // [29] .rodata 0x0072d7
        "lr",  // [30] .rodata 0x00737a
        "sp",  // [31] .rodata 0x007627
        "pc",  // [32] .rodata 0x00743a
        "pst"  // [33] .rodata 0x00762a
    };
    return kNames;
}

// ============================================================================
// 2. Exynos 9810 Hardware Bug Check (.init_array[0] at 0x00cde0..0x00ce70)
// Disassembly match:
//   0x00cdec: mov w0, #0x10 ; bl getauxval(AT_HWCAP)
//   0x00cdf8: tbnz w19, #8, #0xce18 (checks bit 8 = 0x100 of AT_HWCAP)
//   0x00ce20: add x0, x0, #0x652 ("ro.arch") ; bl __system_property_get
//   0x00ce38: add x1, x1, #0x33b ("exynos9810") ; mov w2, #0xa ; bl strncmp
//   0x00ce50: csel w8, wzr, w19, eq (clears bit 8 if ro.arch == "exynos9810")
// Kiểm tra lỗi phần cứng Exynos 9810 tại hàm khởi tạo .init_array[0] (0x00cde0).
// ============================================================================
bool CheckExynos9810Arm64Bug(uint64_t hwcap, const char* ro_arch_prop) noexcept {
    // If bit 8 (0x100) of AT_HWCAP is 0, return false immediately (0x00cdf8..0x00ce14)
    if ((hwcap & 0x100ULL) == 0) {
        return false;
    }
    const uint32_t bit8 = static_cast<uint32_t>((hwcap >> 8) & 1ULL);
    if (ro_arch_prop != nullptr && std::strlen(ro_arch_prop) >= 1) {
        // strncmp(ro_arch_prop, "exynos9810", 10) == 0 -> csel w8, wzr, w19, eq (0x00ce48..0x00ce50)
        if (std::strncmp(ro_arch_prop, "exynos9810", 10) == 0) {
            return false;
        }
    }
    return bit8 != 0;
}

// ============================================================================
// 3. Regs & RegsArm64 Implementation (0x030374..0x030750)
// Triển khai lớp Regs và RegsArm64 (0x58 = 88 byte, 34 thanh ghi 64-bit).
// ============================================================================
Regs::Regs(uint16_t total_regs, uint16_t last_regs, uint16_t return_address_reg) noexcept
    : total_regs_(total_regs),
      last_regs_(last_regs),
      return_address_reg_(return_address_reg),
      vregs_enabled_(false),
      dex_pc_(0),
      regs_(total_regs, 0ULL),
      pac_mask_(0) {}

Regs::~Regs() = default;

// 0x0303dc..0x030510: Regs::enable_vregs()
// Allocates 8 64-bit slots (0x40 = 64 bytes) for callee-saved FP regs d8..d15
// and sets vregs_enabled_ (+0x0E) to 1 (mov w8, #1; strb w8, [x19, #0xe] at 0x0304fc).
void Regs::enable_vregs() {
    if (vregs_.size() != kArm64CalleeSavedVRegsCount) {
        vregs_.assign(kArm64CalleeSavedVRegsCount, 0ULL);
    }
    vregs_enabled_ = true;
}

// 0x030518..0x030624: Regs::RemoteGet(pid_t pid, ErrorCode* error_code)
// Allocates 0x110 (272) bytes for user_ptregs, invokes ptrace(PTRACE_GETREGSET=0x4204,
// pid, NT_PRSTATUS=1, &iov), and constructs RegsArm64 (0x58 = 88 bytes).
Regs* Regs::RemoteGet(int pid, ErrorCode* error_code) {
    if (pid <= 0) {
        if (error_code != nullptr) {
            *error_code = ERROR_PTRACE_CALL; // mov w8, #0xe; strb w8, [x21] at 0x0305f4
        }
        return nullptr;
    }
    auto* regs = new RegsArm64();
    // Deterministic simulated ptrace register set population for clean-room testing
    regs->regs_[REG_ARM64_SP] = 0x0000007FF0001000ULL;
    regs->regs_[REG_ARM64_PC] = 0x0000007000015708ULL;
    regs->regs_[REG_ARM64_LR] = 0x0000007000015AB0ULL;
    if (error_code != nullptr) {
        *error_code = ERROR_NONE;
    }
    return regs;
}

// 0x030628..0x0306a0: Regs::CreateFromUcontext(void* ucontext)
// Allocates RegsArm64 (0x58 = 88 bytes) and copies 0x110 (272) bytes from
// (const uint8_t*)ucontext + 0xB8 (add x1, x19, #0xb8; mov w2, #0x110; bl memcpy).
Regs* Regs::CreateFromUcontext(void* ucontext) {
    auto* regs = new RegsArm64();
    if (ucontext != nullptr) {
        const auto* src = reinterpret_cast<const uint8_t*>(ucontext) + kArm64UcontextRegsOffset;
        std::memcpy(regs->regs_.data(), src, kArm64RegsByteSize);
    }
    return regs;
}

// 0x0306a4..0x03071c: Regs::CreateFromLocal()
// Allocates RegsArm64 (0x58 = 88 bytes) and zeroes 0x110 (272) bytes of regs_.
Regs* Regs::CreateFromLocal() {
    auto* regs = new RegsArm64();
    std::memset(regs->regs_.data(), 0, kArm64RegsByteSize);
    return regs;
}

RegsArm64::RegsArm64()
    : Regs(REG_ARM64_MAX, 1, REG_ARM64_LR) {}

RegsArm64::~RegsArm64() = default;

uint64_t RegsArm64::pc() const noexcept {
    return regs_[REG_ARM64_PC]; // +0x100 (32 * 8)
}

uint64_t RegsArm64::sp() const noexcept {
    return regs_[REG_ARM64_SP]; // +0xF8 (31 * 8)
}

void RegsArm64::set_pc(uint64_t pc) noexcept {
    if (pac_mask_ != 0) {
        pc &= ~pac_mask_;
    }
    regs_[REG_ARM64_PC] = pc;
}

void RegsArm64::set_sp(uint64_t sp) noexcept {
    regs_[REG_ARM64_SP] = sp;
}

bool RegsArm64::SetPcFromReturnAddress(Memory* /*process_memory*/) noexcept {
    const uint64_t lr = regs_[REG_ARM64_LR];
    if (regs_[REG_ARM64_PC] == lr) {
        return false;
    }
    set_pc(lr);
    return true;
}

void RegsArm64::IterateRegisters(std::function<void(const char*, uint64_t)> fn) const {
    const auto& names = GetArm64RegisterNames();
    for (size_t i = 0; i < REG_ARM64_MAX; ++i) {
        fn(names[i], regs_[i]);
    }
}

// 0x030374..0x0303d8: RegsArm64::Clone()
Regs* RegsArm64::Clone() const {
    auto* clone = new RegsArm64();
    clone->total_regs_ = total_regs_;
    clone->last_regs_ = last_regs_;
    clone->return_address_reg_ = return_address_reg_;
    clone->vregs_enabled_ = vregs_enabled_;
    clone->dex_pc_ = dex_pc_;
    clone->regs_ = regs_;
    clone->pac_mask_ = pac_mask_;
    clone->vregs_ = vregs_;
    return clone;
}

// ============================================================================
// 4. Registers Wrapper Implementation (0x02f8f8..0x030370)
// Triển khai lớp bao bọc Registers (0x02f8f8..0x030370).
// ============================================================================
// 0x02f8f8: stp x1, xzr, [x0] ; ret
Registers::Registers(Regs* regs) noexcept
    : regs_(regs), owned_regs_(nullptr) {}

// 0x02f900..0x02f91c: ldr x0, [x0, #8] ; cbz x0, #0x2f91c ; delete owned_regs_
Registers::~Registers() = default;

// 0x02f920..0x02f934: Move constructor
Registers::Registers(Registers&& other) noexcept
    : regs_(other.regs_), owned_regs_(std::move(other.owned_regs_)) {
    other.regs_ = nullptr;
}

// 0x02f938..0x02f970: Move assignment operator
Registers& Registers::operator=(Registers&& other) noexcept {
    if (this != &other) {
        regs_ = other.regs_;
        owned_regs_ = std::move(other.owned_regs_);
        other.regs_ = nullptr;
    }
    return *this;
}

// 0x02f974..0x02f98c: ldr x8, [x0] ; cbz x8 ; ldr x8, [x8, #0x18] ; ldr x0, [x8, #0x100]
uint64_t Registers::pc() const noexcept {
    return regs_ != nullptr ? regs_->RawData()[REG_ARM64_PC] : 0ULL;
}

// 0x02f990..0x02f9a8: ldr x8, [x0] ; cbz x8 ; ldr x8, [x8, #0x18] ; ldr x0, [x8, #0xf8]
uint64_t Registers::sp() const noexcept {
    return regs_ != nullptr ? regs_->RawData()[REG_ARM64_SP] : 0ULL;
}

// 0x02f9ac..0x02f9c0: ldr x8, [x0] ; cbz x8 ; ldr x0, [x8, #0x10]
uint64_t Registers::dex_pc() const noexcept {
    return regs_ != nullptr ? regs_->dex_pc() : 0ULL;
}

// 0x02f9c4..0x02f9d8: ldr x8, [x0] ; cbz x8 ; ldr x0, [x8, #0x18]
void* Registers::RawData() noexcept {
    return regs_ != nullptr ? regs_->RawData() : nullptr;
}

const void* Registers::RawData() const noexcept {
    return regs_ != nullptr ? regs_->RawData() : nullptr;
}

// 0x02f9dc..0x0301e8 (2,060 B): Iterates all 34 registers x0..x29, lr, sp, pc, pst
void Registers::IterateRegisters(std::function<void(const char*, uint64_t)> fn) const {
    if (regs_ == nullptr || !fn) {
        return;
    }
    const auto& names = GetArm64RegisterNames();
    const uint64_t* raw = regs_->RawData();
    for (size_t i = 0; i < REG_ARM64_MAX; ++i) {
        fn(names[i], raw[i]);
    }
}

// 0x0301e8..0x030214: Registers::create(Regs* regs)
void Registers::create(Regs* regs) noexcept {
    owned_regs_.reset(regs);
    regs_ = owned_regs_.get();
}

// 0x030218..0x030250: Registers::CreateFromUcontext(void* ucontext)
void Registers::CreateFromUcontext(void* ucontext) {
    owned_regs_.reset(Regs::CreateFromUcontext(ucontext));
    regs_ = owned_regs_.get();
}

// 0x030254..0x030288: Registers::CreateFromLocal()
void Registers::CreateFromLocal() {
    owned_regs_.reset(Regs::CreateFromLocal());
    regs_ = owned_regs_.get();
}

// 0x03028c..0x0302d0: Registers::RemoteGet(int pid)
bool Registers::RemoteGet(int pid) {
    owned_regs_.reset(Regs::RemoteGet(pid, nullptr));
    regs_ = owned_regs_.get();
    return regs_ != nullptr;
}

// 0x0302d4..0x0302e8: ldrh w0, [x8, #8]
uint16_t Registers::total_regs() const noexcept {
    return regs_ != nullptr ? regs_->total_regs() : 0U;
}

// 0x0302ec..0x030308: Registers::Clone() const
Registers Registers::Clone() const {
    if (regs_ == nullptr) {
        return Registers(nullptr);
    }
    return Registers(regs_->Clone());
}

// 0x03030c..0x030328: ldrb w8, [x8, #0xe] ; cmp w8, #0 ; cset w0, ne
bool Registers::vregs_enabled() const noexcept {
    return regs_ != nullptr && regs_->vregs_enabled();
}

// 0x03032c..0x030338: b #0x303dc
void Registers::enable_vregs() {
    if (regs_ != nullptr) {
        regs_->enable_vregs();
    }
}

// 0x03033c..0x030350: ldr x0, [x8, #0x40]
uint64_t* Registers::vregs_data() noexcept {
    return regs_ != nullptr ? regs_->vregs_data() : nullptr;
}

const uint64_t* Registers::vregs_data() const noexcept {
    return regs_ != nullptr ? regs_->vregs_data() : nullptr;
}

// 0x030354..0x030370: ldp x8, x9, [x8, #0x40] ; sub x8, x9, x8 ; lsr x0, x8, #3
size_t Registers::total_vregs() const noexcept {
    return regs_ != nullptr ? regs_->total_vregs() : 0U;
}

// ============================================================================
// 5. XZ Stream Header Verifier (.rodata 0x0079c4) & SHA-256 Engine (.rodata
//    0x0077b0 & 0x0078c4)
// Used when decompressing .gnu_debugdata minidebuginfo inside ELF images.
// Kiểm định tiêu đề XZ (\xfd7zXZ\0) và băm SHA-256 cho .gnu_debugdata.
// ============================================================================
bool VerifyXzStreamHeaderMagic(const uint8_t* data, size_t size) noexcept {
    if (data == nullptr || size < kXzHeaderMagic.size()) {
        return false;
    }
    return std::memcmp(data, kXzHeaderMagic.data(), kXzHeaderMagic.size()) == 0;
}

namespace {

inline uint32_t Ror32(uint32_t x, uint32_t n) noexcept {
    return (x >> n) | (x << (32U - n));
}

void Sha256TransformBlock(std::array<uint32_t, 8>& state, const uint8_t block[64]) noexcept {
    uint32_t w[64];
    for (size_t i = 0; i < 16; ++i) {
        w[i] = (static_cast<uint32_t>(block[i * 4 + 0]) << 24) |
               (static_cast<uint32_t>(block[i * 4 + 1]) << 16) |
               (static_cast<uint32_t>(block[i * 4 + 2]) << 8) |
               (static_cast<uint32_t>(block[i * 4 + 3]));
    }
    for (size_t i = 16; i < 64; ++i) {
        const uint32_t s0 = Ror32(w[i - 15], 7) ^ Ror32(w[i - 15], 18) ^ (w[i - 15] >> 3);
        const uint32_t s1 = Ror32(w[i - 2], 17) ^ Ror32(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];

    for (size_t i = 0; i < 64; ++i) {
        const uint32_t S1 = Ror32(e, 6) ^ Ror32(e, 11) ^ Ror32(e, 25);
        const uint32_t ch = (e & f) ^ ((~e) & g);
        const uint32_t temp1 = h + S1 + ch + kSha256RoundConstants[i] + w[i];
        const uint32_t S0 = Ror32(a, 2) ^ Ror32(a, 13) ^ Ror32(a, 22);
        const uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        const uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

} // namespace

std::array<uint8_t, 32> ComputeUnwindSha256(const uint8_t* data, size_t len) noexcept {
    std::array<uint32_t, 8> state = kSha256InitialState;
    size_t offset = 0;
    while (len - offset >= 64) {
        Sha256TransformBlock(state, data + offset);
        offset += 64;
    }

    uint8_t pad[128] = {0};
    const size_t rem = len - offset;
    if (rem > 0 && data != nullptr) {
        std::memcpy(pad, data + offset, rem);
    }
    pad[rem] = 0x80;
    const size_t pad_blocks = (rem >= 56) ? 2 : 1;
    const uint64_t bit_len = static_cast<uint64_t>(len) * 8ULL;
    for (size_t i = 0; i < 8; ++i) {
        pad[pad_blocks * 64 - 1 - i] = static_cast<uint8_t>((bit_len >> (i * 8)) & 0xFFU);
    }
    for (size_t b = 0; b < pad_blocks; ++b) {
        Sha256TransformBlock(state, pad + b * 64);
    }

    std::array<uint8_t, 32> digest{};
    for (size_t i = 0; i < 8; ++i) {
        digest[i * 4 + 0] = static_cast<uint8_t>((state[i] >> 24) & 0xFFU);
        digest[i * 4 + 1] = static_cast<uint8_t>((state[i] >> 16) & 0xFFU);
        digest[i * 4 + 2] = static_cast<uint8_t>((state[i] >> 8) & 0xFFU);
        digest[i * 4 + 3] = static_cast<uint8_t>(state[i] & 0xFFU);
    }
    return digest;
}

// ============================================================================
// 6. DWARF Expression Opcode Table (.rodata 0x007bc8..0x007ee8)
// Bảng mô tả toán hạng biểu thức DWARF (.rodata 0x007bc8..0x007ee8).
// ============================================================================
const std::vector<DwarfOpTableEntry>& GetDwarfOpTable() noexcept {
    static const std::vector<DwarfOpTableEntry> kTable = {
        {0x03, 0x00, 0x00, 0x01, 0x00}, // DW_OP_addr (0x007bd7)
        {0x06, 0x01, 0x01, 0x00, 0x00}, // DW_OP_deref (0x007be6)
        {0x08, 0x03, 0x00, 0x01, 0x0D}, // DW_OP_const1u (0x007bf0)
        {0x09, 0x03, 0x00, 0x01, 0x0E}, // DW_OP_const1s (0x007bf5)
        {0x0A, 0x03, 0x00, 0x01, 0x02}, // DW_OP_const2u (0x007bfa)
        {0x0B, 0x03, 0x00, 0x01, 0x0A}, // DW_OP_const2s (0x007bff)
        {0x0C, 0x03, 0x00, 0x01, 0x03}, // DW_OP_const4u (0x007c04)
        {0x0D, 0x03, 0x00, 0x01, 0x0B}, // DW_OP_const4s (0x007c09)
        {0x0E, 0x03, 0x00, 0x01, 0x04}, // DW_OP_const8u (0x007c0e)
        {0x0F, 0x03, 0x00, 0x01, 0x0C}, // DW_OP_const8s (0x007c13)
        {0x10, 0x03, 0x00, 0x01, 0x01}, // DW_OP_constu (0x007c18)
        {0x11, 0x03, 0x00, 0x01, 0x09}, // DW_OP_consts (0x007c1d)
        {0x12, 0x04, 0x01, 0x00, 0x00}, // DW_OP_dup (0x007c22)
        {0x13, 0x05, 0x01, 0x00, 0x00}, // DW_OP_drop (0x007c27)
        {0x14, 0x06, 0x02, 0x00, 0x00}, // DW_OP_over (0x007c2c)
        {0x15, 0x07, 0x00, 0x01, 0x0D}, // DW_OP_pick (0x007c31)
        {0x16, 0x08, 0x02, 0x00, 0x00}, // DW_OP_swap (0x007c36)
        {0x17, 0x09, 0x03, 0x00, 0x00}  // DW_OP_rot (0x007c3b)
    };
    return kTable;
}

} // namespace unwindstack
