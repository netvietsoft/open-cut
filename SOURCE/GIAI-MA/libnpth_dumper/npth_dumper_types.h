/**
 * @file npth_dumper_types.h
 * @brief Exact ABI structures, ELF64 layout, signal tables, and constants for libnpth_dumper.so.
 *        Các cấu trúc ABI chuẩn xác, bố cục ELF64, bảng tín hiệu và hằng số của libnpth_dumper.so.
 *
 * Reconstructed from AArch64 binary libnpth_dumper.so (90,384 bytes, 28 ELF64 sections).
 * Tái cấu trúc từ mã nhị phân AArch64 libnpth_dumper.so (90.384 byte, 28 phân đoạn ELF64).
 */

#ifndef OPENCUT_NPTH_DUMPER_TYPES_H_
#define OPENCUT_NPTH_DUMPER_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace npth {
namespace dumper {

/**
 * @brief ELF64 binary metadata constants for libnpth_dumper.so (OBSERVED).
 *        Các hằng số siêu dữ liệu nhị phân ELF64 cho libnpth_dumper.so (QUAN SÁT ĐƯỢC).
 */
struct ElfBinaryMetadata {
    static constexpr uint64_t kBinaryFileSize        = 90384ULL;
    static constexpr uint32_t kSectionCount          = 28U;
    static constexpr uint32_t kDynSymCount           = 160U;
    static constexpr uint32_t kRelaDynCount          = 163U;
    static constexpr uint32_t kRelaPltCount          = 137U;
    static constexpr uint64_t kInterpAddr            = 0x000270ULL;
    static constexpr uint64_t kNoteBuildIdAddr       = 0x000288ULL;
    static constexpr uint64_t kRodataAddr            = 0x004b10ULL;
    static constexpr uint64_t kRodataSize            = 0x001608ULL;
    static constexpr uint64_t kTextAddr              = 0x007aa0ULL;
    static constexpr uint64_t kTextSize              = 0x00c690ULL;
    static constexpr uint64_t kPltAddr               = 0x014130ULL;
    static constexpr uint64_t kPltSize               = 0x0008b0ULL;
    static constexpr uint64_t kPreinitArrayVaddr     = 0x0189e0ULL;
    static constexpr uint64_t kInitArrayVaddr        = 0x0189f0ULL;
    static constexpr uint64_t kDataRelRoVaddr        = 0x018a28ULL;
    static constexpr uint64_t kDataVaddr             = 0x01d6f8ULL;
    static constexpr uint64_t kBssVaddr              = 0x01d838ULL;
};

/**
 * @brief Hardware & magic constants extracted from AArch64 disassembly (OBSERVED).
 *        Các hằng số phần cứng và magic trích xuất từ mã hợp ngữ AArch64 (QUAN SÁT ĐƯỢC).
 */
struct DumperConstants {
    /** @brief Crash payload size read from stdin fd=0 (`mov w1, #0x12b0` @ `0x0081d8`). */
    static constexpr size_t   kCrashPayloadBytes     = 0x12b0U; // 4,784 bytes
    /** @brief Self-protection watchdog timeout in seconds (`mov w0, #0x1e` @ `0x0081bc`). */
    static constexpr uint32_t kWatchdogAlarmSec      = 30U;
    /** @brief Self-crash sigaction flags (`SA_SIGINFO | SA_RESTART` = `0x10000004` @ `0x008140`). */
    static constexpr uint32_t kSelfSigActionFlags    = 0x10000004U;
    /** @brief AArch64 `fpsimd_context` magic (`0x46508001` @ `0x0084a8` & `0x011ea8`). */
    static constexpr uint32_t kFpSimdMagic           = 0x46508001U;
    /** @brief Signed 64-bit magic for division by 1000 (`0x20c49ba5e353f7cf` @ `0x008d48`). */
    static constexpr uint64_t kMagicDiv1000Signed    = 0x20c49ba5e353f7cfULL;
    /** @brief Unsigned 64-bit magic for division by 1,000,000 (`0x431bde82d7b634db` @ `0x00e914`). */
    static constexpr uint64_t kMagicDiv1000000Unsigned = 0x431bde82d7b634dbULL;
    /** @brief Multiplicative inverse for 80-byte (`0x50`) stride (`0xcccccccccccccccd` @ `0x00984c`). */
    static constexpr uint64_t kInverseFive64         = 0xcccccccccccccccdULL;
    /** @brief Multiplicative inverse for 48-byte (`0x30`) stride (`0xaaaaaaaaaaaaaaab` @ `0x00a0b4`). */
    static constexpr uint64_t kInverseThree64        = 0xaaaaaaaaaaaaaaabULL;
    /** @brief Tombstone version file header `"V001\n"` (`w10 = 0x31303056` @ `0x009d28`). */
    static constexpr uint32_t kTombstoneVerMagic     = 0x31303056U;
    /** @brief Protector history file header `"V002\n"` (`w10 = 0x32303056` @ `0x010760`). */
    static constexpr uint32_t kProtectorHistoryMagic = 0x32303056U;
    /** @brief Protector binary config magic `"PROT004\x02"` (`0x02343030544f5250` @ `0x00fb3c`). */
    static constexpr uint64_t kProtectorConfigMagic  = 0x02343030544f5250ULL;
    /** @brief Protector binary config sub-magic (`0x12345678` @ `0x00fb5c`). */
    static constexpr uint32_t kProtectorSubMagic     = 0x12345678U;
    /** @brief Breakpad Minidump signature `"MDMP"` (`0x504d444d` @ `.rodata` `0x005fc0`). */
    static constexpr uint32_t kMinidumpSignature     = 0x504d444dU;
    /** @brief Breakpad Minidump version (`0x0000a793` @ `.rodata` `0x005fc4`). */
    static constexpr uint32_t kMinidumpVersion       = 0x0000a793U;
    /** @brief Breakpad CodeView 7.0 signature `"LEBp"` (`0x4270454c` @ `0x012bf4`). */
    static constexpr uint32_t kCodeViewSignatureLEBp = 0x4270454cU;
    /** @brief Breakpad Linux custom stream base (`0x4767000a` @ `0x0133cc`). */
    static constexpr uint32_t kLinuxStreamDsoDebug   = 0x4767000aU;
    /** @brief Android `abort_msg_t` magic 1 (`0xb18e40886ac388f0` @ `0x00d5a8`). */
    static constexpr uint64_t kAbortMsgMagic1        = 0xb18e40886ac388f0ULL;
    /** @brief Android `abort_msg_t` magic 2 (`0xc6dfba755a1de0b5` @ `0x00d5ac`). */
    static constexpr uint64_t kAbortMsgMagic2        = 0xc6dfba755a1de0b5ULL;
};

/**
 * @brief 40-byte self-signal slot stored in `.data` at `0x01d6f8..0x01d837` (8 entries).
 *        Ô tín hiệu tự bảo vệ 40 byte lưu trong `.data` tại `0x01d6f8..0x01d837` (8 phần tử).
 *
 * Signals registered at `0x008140..0x008180`:
 *   [0] SIGABRT (6)  @ 0x01d6f8
 *   [1] SIGBUS  (7)  @ 0x01d720
 *   [2] SIGFPE  (8)  @ 0x01d748
 *   [3] SIGILL  (4)  @ 0x01d770
 *   [4] SIGSEGV (11) @ 0x01d798
 *   [5] SIGTRAP (5)  @ 0x01d7c0
 *   [6] SIGSYS  (31) @ 0x01d7e8
 *   [7] SIGSTKFLT(16)@ 0x01d810
 */
struct SelfSignalSlot {
    int32_t  signo;          // +0x00: Signal number / Số hiệu tín hiệu
    int32_t  padding;        // +0x04: Alignment padding / Đệm căn chỉnh
    uint64_t sa_flags_or_fn; // +0x08..+0x27: Old sigaction storage (32 bytes) / Lưu trữ sigaction cũ
    uint64_t sa_mask;
    uint64_t sa_restorer;
    uint64_t sa_handler_ext;
};
static_assert(sizeof(SelfSignalSlot) == 40, "SelfSignalSlot must be 40 bytes");

/**
 * @brief AArch64 `siginfo_t` subset (`128` bytes) inside the crash IPC packet (`0x0082ec`).
 *        Tập con `siginfo_t` AArch64 (`128` byte) bên trong gói IPC báo lỗi (`0x0082ec`).
 */
struct AArch64SigInfo {
    int32_t  si_signo;   // +0x00: Signal number (`[x19, #0x00]`)
    int32_t  si_errno;   // +0x04: Error number (`[x19, #0x04]`)
    int32_t  si_code;    // +0x08: Signal code (`[x19, #0x08]`)
    int32_t  pad0;       // +0x0c: Padding
    uint64_t si_addr;    // +0x10: Fault address or sender pid (`[x19, #0x10]`)
    int32_t  si_uid;     // +0x14 (overlaps union when kill/tkill): Sender UID (`[x19, #0x14]`)
    uint8_t  reserved[100];
};

/**
 * @brief AArch64 `ucontext_t` layout used by `libnpth_dumper.so` (`0x008458..0x0084e4`, `0x011ea8..0x011f24`).
 *        Bố cục `ucontext_t` AArch64 được sử dụng bởi `libnpth_dumper.so`.
 */
struct AArch64UContext {
    uint64_t uc_flags;           // +0x000
    uint64_t uc_link;            // +0x008
    uint64_t ss_sp;              // +0x010
    int32_t  ss_flags;           // +0x018
    int32_t  ss_pad;             // +0x01c
    uint64_t ss_size;            // +0x020
    uint8_t  uc_sigmask[128];    // +0x028..+0x0a7
    uint8_t  pad_mcontext[16];   // +0x0a8..+0x0b7
    uint64_t fault_address;      // +0x0b0 (relative to mcontext header) / +0x0b8: regs[0]..regs[30]
    uint64_t regs[31];           // +0x0b8..+0x1af: x0..x30 (`0x008488: add x9, x8, #0xb8`)
    uint64_t sp;                 // +0x1b0: Stack pointer (`[x8, #0x1b0]`)
    uint64_t pc;                 // +0x1b8: Program counter (`[x8, #0x1b8]`)
    uint64_t pstate;             // +0x1c0: Processor state (`[x8, #0x1c0]`)
    uint64_t pad_ext;            // +0x1c8: Alignment
    uint32_t fpsimd_magic;       // +0x1d0: `0x46508001` (`FPSIMD_MAGIC`)
    uint32_t fpsimd_size;        // +0x1d4: `0x210` (528 bytes)
    uint32_t fpsr;               // +0x1d8: Floating-point status register
    uint32_t fpcr;               // +0x1dc: Floating-point control register
    uint64_t vregs[64];          // +0x1e0..+0x3df: 32 x 128-bit NEON/SIMD registers (`q0..q31`)
};

/**
 * @brief Raw 4,784-byte (`0x12b0`) crash request read from `fd = 0` at `0x0081d4..0x008448`.
 *        Yêu cầu kết xuất lỗi thô 4.784 byte (`0x12b0`) đọc từ `fd = 0` tại `0x0081d4..0x008448`.
 *
 * Offsets verified from `0x008340..0x008450`:
 *   - `+0x0000`: `int32_t version` (`<= 2`)
 *   - `+0x0004`: `int32_t crash_pid`
 *   - `+0x0008`: `int32_t crash_tid`
 *   - `+0x000c`: `int32_t crash_uid`
 *   - `+0x0010`: `int32_t api_level` (`[sp, #0x1ef0]`)
 *   - `+0x0018`: `int64_t process_start_time`
 *   - `+0x0020`: `int64_t crash_time`
 *   - `+0x0028`: `uint64_t app_Shadow_ptr` (`[sp, #0x1f08]`, `PTRACE_PEEKTEXT`/`POKETEXT` target)
 *   - `+0x0030`: `uint64_t protector_state_ptr` (`[sp, #0x1f10]`, remote flag address)
 *   - `+0x0038`: `uint64_t app_version_code` (`[sp, #0x1f18]`)
 *   - `+0x0040`: `char process_name[64]` (`0x00836c`)
 *   - `+0x0080`: `char thread_name[64]` (`0x008378`)
 *   - `+0x00c0`: `char dump_dir[256]` (`0x008384`)
 *   - `+0x01c0`: `char config_dir[256]` (`0x0083a8`)
 *   - `+0x02c0`: `AArch64SigInfo siginfo` (`0x0082ec`)
 *   - `+0x0340`: `AArch64UContext ucontext` (`0x008458`)
 *   - `+0x1280`: `uint16_t dump_flags` (`[sp, #0x3160]`, bit 0..9 control tombstone/minidump/smaps/protector)
 */
struct CrashPipePayload {
    int32_t         version;              // +0x0000
    int32_t         crash_pid;            // +0x0004
    int32_t         crash_tid;            // +0x0008
    int32_t         crash_uid;            // +0x000c
    int32_t         api_level;            // +0x0010
    int32_t         reserved0;            // +0x0014
    int64_t         process_start_time;   // +0x0018
    int64_t         crash_time;           // +0x0020
    uint64_t        remote_ctx_addr;      // +0x0028
    uint64_t        remote_flag_addr;     // +0x0030
    uint64_t        app_version_code;     // +0x0038
    char            process_name[64];     // +0x0040
    char            thread_name[64];      // +0x0080
    char            dump_dir[256];        // +0x00c0
    char            config_dir[256];      // +0x01c0
    AArch64SigInfo  siginfo;              // +0x02c0 (128 bytes)
    AArch64UContext ucontext;             // +0x0340 (992 bytes)
    uint8_t         extra_reserved[3328]; // +0x0720..+0x127f
    uint16_t        dump_flags;           // +0x1280
    uint8_t         tail_padding[46];     // +0x1282..+0x12af
};
static_assert(sizeof(CrashPipePayload) == DumperConstants::kCrashPayloadBytes,
              "CrashPipePayload must be exactly 0x12b0 (4,784) bytes");

/**
 * @brief Parsed runtime context passed to `do_tombstone` (`0x009260`) and `do_minidump` (`0x01110c`).
 *        Ngữ cảnh thời gian chạy đã phân tích được truyền vào `do_tombstone` và `do_minidump`.
 */
struct ParsedCrashContext {
    int32_t          pid                = 0;     // +0x00 (`[sp, #0x60]`)
    int32_t          tid                = 0;     // +0x04 (`[sp, #0x64]`)
    int32_t          uid                = 0;     // +0x08 (`[sp, #0x68]`)
    int32_t          pad0               = 0;     // +0x0c
    AArch64UContext* ucontext_ptr       = nullptr; // +0x10 (`[sp, #0x70]`)
    AArch64SigInfo*  siginfo_ptr        = nullptr; // +0x18 (`[sp, #0x78]`)
    std::string      dump_dir;                   // +0x20 (`[sp, #0x80]`)
    std::string      thread_name;                // +0x38 (`[sp, #0x98]`)
    int32_t          api_level          = 0;     // +0x50 (`[sp, #0xb0]`)
    int64_t          process_start_us   = 0;     // +0x58 (`[sp, #0xb8]`)
    int64_t          crash_time_us      = 0;     // +0x60 (`[sp, #0xc0]`)
    uint64_t         remote_ctx_addr    = 0;     // +0x68 (`[sp, #0xc8]`)
    uint64_t         remote_flag_addr   = 0;     // +0x70 (`[sp, #0xd0]`)
    std::string      config_dir;                 // +0x78 (`[sp, #0xd8]`)
    uint64_t         app_version_code   = 0;     // +0x90 (`[sp, #0xf0]`)
    uint16_t         dump_flags         = 0;     // +0x98 (`[sp, #0xf8]`)
    std::string      process_name;               // +0xc0 (`[sp, #0x120]`)
};

/**
 * @brief Attached thread entry (`48` bytes = `0x30` stride) in `std::vector<AttachedThread>`.
 *        Phần tử luồng đã đính kèm (`48` byte = bước nhảy `0x30`) trong `std::vector<AttachedThread>`.
 */
struct AttachedThread {
    int32_t     pid   = 0;       // +0x00
    int32_t     tid   = 0;       // +0x04
    std::string name;            // +0x08..+0x1f (24-byte libc++ SSO string)
    void*       regs  = nullptr; // +0x20 (`std::shared_ptr<unwindstack::Registers>` ptr)
    void*       cntrl = nullptr; // +0x28 (`std::shared_ptr` control block)
};

/**
 * @brief Buffered file writer (`fd` + error state) used by `0x00e25c` and `0x00b5ac`.
 *        Bộ ghi file có đệm (`fd` + trạng thái lỗi) được sử dụng bởi `0x00e25c` và `0x00b5ac`.
 */
struct DumperFileWriter {
    int32_t fd        = -1; // +0x00: Output file descriptor / Mô tả file đầu ra
    uint8_t error_code = 0; // +0x04: 0 = ok, 6 = write failed (`mov w8, #6; strb w8, [x19, #4]` @ `0x00e2d8`)
};

} // namespace dumper
} // namespace npth

#endif // OPENCUT_NPTH_DUMPER_TYPES_H_
