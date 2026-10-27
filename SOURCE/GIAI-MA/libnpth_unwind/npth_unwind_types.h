// ============================================================================
// File: npth_unwind_types.h
// Target: libnpth_unwind.so (222,368 bytes, SHA-256: c83bb94dbfc0aa4b2d306a0b57ba7bd83c489dc08379cbb7f362c02fd481cad8)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
// Classification: CORE_10_MONITORING (ByteDance NPTH Custom libunwindstack Engine)
//
// Description (EN):
// Exact AArch64 ABI data structures, error code enumerations, register indices,
// DWARF Call Frame Information (CFA) / Expression (OP) table descriptors,
// XZ minidebuginfo (.gnu_debugdata) stream constants, and SHA-256 constants
// reconstructed from libnpth_unwind.so (.rodata 0x007200..0x007ee8 and
// .data.rel.ro 0x038120..0x0396d0).
//
// Mô tả (VI):
// Cấu trúc dữ liệu chuẩn ABI AArch64, bảng mã lỗi, chỉ số thanh ghi ARM64,
// bảng tra DWARF CFA / OP, hằng số luồng giải nén XZ (.gnu_debugdata) và
// hằng số băm SHA-256 phục hồi chính xác từ libnpth_unwind.so (.rodata
// 0x007200..0x007ee8 và .data.rel.ro 0x038120..0x0396d0).
// ============================================================================

#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

namespace unwindstack {

// ============================================================================
// 1. ErrorCode & ErrorData
// Verified from AndroidUnwinderData::GetErrorString (0x014364..0x0143ec) and
// .data.rel.ro 0x038420..0x038498 (file offset 0x034420..0x034498, 15 entries).
// Bảng 15 mã lỗi chuẩn của bộ gỡ khung ngăn xếp (Unwinder) tại 0x038420.
// ============================================================================
enum ErrorCode : int8_t {
    ERROR_NONE                  = 0,  // .rodata 0x00738b: "None"
    ERROR_MEMORY_INVALID        = 1,  // .rodata 0x007461: "Memory Invalid"
    ERROR_UNWIND_INFO           = 2,  // .rodata 0x00743d: "Unwind Info"
    ERROR_UNSUPPORTED           = 3,  // .rodata 0x0072cb: "Unsupported"
    ERROR_INVALID_MAP           = 4,  // .rodata 0x007598: "Invalid Map"
    ERROR_MAX_FRAMES_EXCEEDED   = 5,  // .rodata 0x0075a4: "Maximum Frames Exceeded"
    ERROR_REPEATED_FRAME        = 6,  // .rodata 0x007364: "Repeated Frame"
    ERROR_INVALID_ELF           = 7,  // .rodata 0x007451: "Invalid Elf"
    ERROR_THREAD_DOES_NOT_EXIST = 8,  // .rodata 0x007325: "Thread Does Not Exist"
    ERROR_THREAD_TIMEOUT        = 9,  // .rodata 0x00757f: "Thread Timeout"
    ERROR_SYSTEM_CALL           = 10, // .rodata 0x00769e: "System Call Failed"
    ERROR_BAD_ARCH              = 11, // .rodata 0x00723c: "Invalid arch detected"
    ERROR_MAPS_PARSE            = 12, // .rodata 0x007711: "Failed to parse maps"
    ERROR_INVALID_PARAMETER     = 13, // .rodata 0x00760b: "Invalid parameter"
    ERROR_PTRACE_CALL           = 14, // .rodata 0x0076b1: "Ptrace Call Failed"
    ERROR_MEMORY_NOT_ENOUGH     = 15  // .rodata 0x00728a: "Memory not enough"
};

struct ErrorData {
    ErrorCode code = ERROR_NONE; // +0x00 (ldrsb x9, [x0, #0x18] in AndroidUnwinderData)
    uint8_t pad[7] = {0};        // +0x01..0x07 alignment padding
    uint64_t address = 0;        // +0x08 (ldr x1, [x20, #0x20] in AndroidUnwinderData)
};

// Descriptor for each entry in .data.rel.ro 0x038420..0x038490
// Bộ mô tả cho từng phần tử trong bảng .data.rel.ro 0x038420..0x038490
struct ErrorCodeTableEntry {
    ErrorCode code;
    uint32_t data_rel_ro_vaddr;
    uint32_t rodata_str_vaddr;
    const char* message;
};

// ============================================================================
// 2. ArchEnum & Arm64Reg (34 registers, 0x110 = 272 bytes total)
// Verified from RegsArm64::RemoteGet (0x030518), CreateFromUcontext (0x030628),
// CreateFromLocal (0x0306a4), and Registers::IterateRegisters (0x02f9dc..0x0301e8).
// Kiến trúc CPU và chỉ số 34 thanh ghi AArch64 (0x110 = 272 byte).
// ============================================================================
enum ArchEnum : uint8_t {
    ARCH_UNKNOWN = 0,
    ARCH_ARM     = 1,
    ARCH_ARM64   = 2, // mov w1, #2 in FormatFrame (0x015b48, 0x015b64, 0x015b80)
    ARCH_X86     = 3,
    ARCH_X86_64  = 4,
    ARCH_RISCV64 = 5
};

enum Arm64Reg : uint16_t {
    REG_ARM64_X0     = 0,
    REG_ARM64_X1     = 1,
    REG_ARM64_X2     = 2,
    REG_ARM64_X3     = 3,
    REG_ARM64_X4     = 4,
    REG_ARM64_X5     = 5,
    REG_ARM64_X6     = 6,
    REG_ARM64_X7     = 7,
    REG_ARM64_X8     = 8,
    REG_ARM64_X9     = 9,
    REG_ARM64_X10    = 10,
    REG_ARM64_X11    = 11,
    REG_ARM64_X12    = 12,
    REG_ARM64_X13    = 13,
    REG_ARM64_X14    = 14,
    REG_ARM64_X15    = 15,
    REG_ARM64_X16    = 16,
    REG_ARM64_X17    = 17,
    REG_ARM64_X18    = 18,
    REG_ARM64_X19    = 19,
    REG_ARM64_X20    = 20,
    REG_ARM64_X21    = 21,
    REG_ARM64_X22    = 22,
    REG_ARM64_X23    = 23,
    REG_ARM64_X24    = 24,
    REG_ARM64_X25    = 25,
    REG_ARM64_X26    = 26,
    REG_ARM64_X27    = 27,
    REG_ARM64_X28    = 28,
    REG_ARM64_X29    = 29,
    REG_ARM64_LR     = 30, // 0x1E (movk w9, #0x1e, lsl #16 at 0x03057c)
    REG_ARM64_SP     = 31, // offset 0xF8  (ldr x0, [x8, #0xf8] at 0x02f99c)
    REG_ARM64_PC     = 32, // offset 0x100 (ldr x0, [x8, #0x100] at 0x02f980)
    REG_ARM64_PSTATE = 33, // offset 0x108 (ldr x8, [x19, #0x108] at 0x0305d4)
    REG_ARM64_MAX    = 34  // 0x22 (mov w8, #0x22; strh w8, [x0, #8] at 0x030578)
};

// Callee-saved 64-bit FP registers d8..d15 (8 registers = 0x40 = 64 bytes)
// Thanh ghi dấu phẩy động bảo toàn qua lời gọi hàm d8..d15 (8 thanh ghi = 64 byte)
constexpr size_t kArm64CalleeSavedVRegsCount = 8;
constexpr size_t kArm64RegsByteSize          = 0x110; // 34 * 8 = 272 bytes
constexpr size_t kArm64UcontextRegsOffset    = 0xB8;  // add x1, x19, #0xb8 at 0x030668
constexpr uint32_t kPtraceGetRegsetRequest   = 0x4204; // PTRACE_GETREGSET at 0x030550
constexpr uint32_t kNtPrstatusNoteType       = 1;      // NT_PRSTATUS at 0x030558

// ============================================================================
// 3. SharedString & Forward Declarations
// Chuỗi chia sẻ (SharedString) và khai báo trước các lớp lõi.
// ============================================================================
class SharedString {
public:
    SharedString() = default;
    explicit SharedString(std::string s) : ptr_(std::make_shared<std::string>(std::move(s))) {}
    explicit SharedString(std::shared_ptr<std::string> p) : ptr_(std::move(p)) {}

    bool is_null() const noexcept { return ptr_ == nullptr; }
    bool empty() const noexcept { return !ptr_ || ptr_->empty(); }
    const std::string& value() const noexcept {
        static const std::string kEmpty;
        return ptr_ ? *ptr_ : kEmpty;
    }
    const char* c_str() const noexcept { return ptr_ ? ptr_->c_str() : ""; }
    operator const std::string&() const noexcept { return value(); }
    const std::shared_ptr<std::string>& shared_ptr() const noexcept { return ptr_; }
    void clear() noexcept { ptr_.reset(); }

private:
    std::shared_ptr<std::string> ptr_;
};

class Memory;
class Elf;
class Maps;
class MapInfo;
class Regs;
class Registers;

// ============================================================================
// 4. ElfFields (0x60 = 96 bytes, allocated in MapInfo::GetElfFields at 0x028564)
// Trường thông tin ELF khởi tạo lười (lazy-allocated) trong MapInfo (+0x30).
// ============================================================================
struct ElfFields {
    std::shared_ptr<Elf> elf;           // +0x00..0x0F (16 bytes)
    uint64_t elf_offset = 0;            // +0x10 (load offset within file/container)
    uint64_t elf_start_offset = 0;      // +0x18 (offset of ELF header in mapping)
    std::atomic<SharedString*> build_id{nullptr}; // +0x20 (initialized to -1 / 0 in 0x028570)
    uint64_t load_bias = static_cast<uint64_t>(-1); // +0x28
    bool memory_backed_elf = false;     // +0x30 (strb wzr, [x0, #0x30] at 0x028578)
    uint8_t pad_31[3] = {0};
    std::mutex elf_mutex;               // +0x34..0x5B (pthread_mutex_t = 40 bytes on ARM64)
};

// ============================================================================
// 5. FrameData (0x48 = 72 bytes, traversed in DemangleFunctionNames at 0x01419c
//    and FormatFrame at 0x0333a0)
// Khung ngăn xếp đơn lẻ (FrameData, kích thước 0x48 = 72 byte).
// ============================================================================
struct FrameData {
    size_t num = 0;                     // +0x00 (ldp x1, x2, [x23] at 0x0333d4)
    uint64_t rel_pc = 0;                // +0x08 (relative PC printed by #%02zu pc %016lx)
    uint64_t pc = 0;                    // +0x10 (absolute virtual PC)
    uint64_t sp = 0;                    // +0x18 (stack pointer at frame)
    SharedString function_name;         // +0x28 (add x19, x8, #0x28 at 0x0141bc)
    uint64_t function_offset = 0;       // +0x38 (ldr x1, [x23, #0x38] at 0x0335bc)
    std::shared_ptr<MapInfo> map_info;  // +0x40 (ldp x22, x19, [x23, #0x40] at 0x033420)
};

// ============================================================================
// 6. DexPositionInfo & DexPositionInfoContext
// Thông tin vị trí mã nguồn DEX đi kèm AndroidUnwinderData (+0x38).
// ============================================================================
struct DexPositionInfo {
    uint64_t pc = 0;
    std::string method_name;
    std::string source_file;
    uint32_t line_number = 0;
};

struct DexPositionInfoContext {
    std::vector<DexPositionInfo> positions;
};

// ============================================================================
// 7. DWARF Call Frame & Expression Table Entries & XZ/SHA-256 Constants
// Verified from .rodata 0x0077b0..0x007ee8.
// Cấu trúc bảng lệnh DWARF CFA/OP và hằng số XZ/SHA-256 tại .rodata.
// ============================================================================
struct DwarfCfaTableEntry {
    uint8_t supported_version;
    uint8_t num_operands;
    uint8_t operands[4];
};

struct DwarfOpTableEntry {
    uint8_t op_code;
    uint8_t supported_version;
    uint8_t num_required_stack_values;
    uint8_t num_operands;
    uint8_t operand_type;
};

// 6-byte XZ stream magic at .rodata 0x0079c4: fd 37 7a 58 5a 00 ("\xfd7zXZ\0")
constexpr std::array<uint8_t, 6> kXzHeaderMagic = {0xFD, 0x37, 0x7A, 0x58, 0x5A, 0x00};

// 8 SHA-256 initial state words at .rodata 0x0077b0..0x0077d0
constexpr std::array<uint32_t, 8> kSha256InitialState = {
    0x6A09E667U, 0xBB67AE85U, 0x3C6EF372U, 0xA54FF53AU,
    0x510E527FU, 0x9B05688CU, 0x1F83D9ABU, 0x5BE0CD19U
};

// 64 SHA-256 round constants K[0..63] at .rodata 0x0078c4..0x0079c4
constexpr std::array<uint32_t, 64> kSha256RoundConstants = {
    0x428A2F98U, 0x71374491U, 0xB5C0FBCFU, 0xE9B5DBA5U,
    0x3956C25BU, 0x59F111F1U, 0x923F82A4U, 0xAB1C5ED5U,
    0xD807AA98U, 0x12835B01U, 0x243185BEU, 0x550C7DC3U,
    0x72BE5D74U, 0x80DEB1FEU, 0x9BDC06A7U, 0xC19BF174U,
    0xE49B69C1U, 0xEFBE4786U, 0x0FC19DC6U, 0x240CA1CCU,
    0x2DE92C6FU, 0x4A7484AAU, 0x5CB0A9DCU, 0x76F988DAU,
    0x983E5152U, 0xA831C66DU, 0xB00327C8U, 0xBF597FC7U,
    0xC6E00BF3U, 0xD5A79147U, 0x06CA6351U, 0x14292967U,
    0x27B70A85U, 0x2E1B2138U, 0x4D2C6DFCU, 0x53380D13U,
    0x650A7354U, 0x766A0ABBU, 0x81C2C92EU, 0x92722C85U,
    0xA2BFE8A1U, 0xA81A664BU, 0xC24B8B70U, 0xC76C51A3U,
    0xD192E819U, 0xD6990624U, 0xF40E3585U, 0x106AA070U,
    0x19A4C116U, 0x1E376C08U, 0x2748774CU, 0x34B0BCB5U,
    0x391C0CB3U, 0x4ED8AA4AU, 0x5B9CCA4FU, 0x682E6FF3U,
    0x748F82EEU, 0x78A5636FU, 0x84C87814U, 0x8CC70208U,
    0x90BEFFFAU, 0xA4506CEBU, 0xBEF9A3F7U, 0xC67178F2U
};

} // namespace unwindstack
