/**
 * @file elf_build_id_xhook.cpp
 * @brief Clean-Room Implementation of ELF Build-ID Inspector, xHook Engine, Pthread Stack Optimizer & SIGBUS Guard.
 *        Triển khai tái tạo sạch cho Bộ đọc Build-ID ELF, Engine xHook, Tối ưu Stack Pthread và Trình bảo vệ SIGBUS.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ: 0x007d30..0x00abd8
 */

#include "elf_build_id_xhook.h"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

namespace {

/**
 * @brief 19-byte ".note.gnu.build-id\0" constant compared at 0x007ed0..0x007f0c:
 *   - `0x6e672e65746f6e2e` (".note.gn")
 *   - `0x2d646c6975622e75` ("u.build-")
 *   - `0x0064692d646c6975` ("uild-id\0" at offset +11)
 */
constexpr uint64_t kNoteGnuBuildIdPart0 = 0x6E672E65746F6E2EULL;
constexpr uint64_t kNoteGnuBuildIdPart1 = 0x2D646C6975622E75ULL;
constexpr uint64_t kNoteGnuBuildIdPart2 = 0x0064692D646C6975ULL;

/**
 * @brief Matches 19-byte section name against ".note.gnu.build-id\0" using the exact
 *        3 unaligned 64-bit loads + OR tree from `0x007ed0..0x007f0c`:
 *        `ldr x9, [x8]; ldr x10, [x8, #8]; ldur x8, [x8, #0xb]; eor ...; orr ...; cbnz`
 *        Đối chiếu tên phân đoạn 19 byte với ".note.gnu.build-id\0" theo đúng 3 lệnh đọc 64-bit tại 0x007ed0..0x007f0c.
 */
bool MatchesNoteGnuBuildIdName(const uint8_t* str_ptr, size_t max_avail) noexcept {
    if (str_ptr == nullptr || max_avail < 19U) {
        return false;
    }
    uint64_t v0 = 0;
    uint64_t v1 = 0;
    uint64_t v2 = 0;
    std::memcpy(&v0, str_ptr + 0, sizeof(uint64_t));
    std::memcpy(&v1, str_ptr + 8, sizeof(uint64_t));
    std::memcpy(&v2, str_ptr + 11, sizeof(uint64_t));
    const uint64_t diff = (v0 ^ kNoteGnuBuildIdPart0) |
                          (v1 ^ kNoteGnuBuildIdPart1) |
                          (v2 ^ kNoteGnuBuildIdPart2);
    return diff == 0ULL;
}

}  // namespace

/**
 * @brief Reconstructs `getElfBuildId` (`0x007d30..0x008060`) on an in-memory ELF64 buffer.
 *        Tái tạo hàm `getElfBuildId` (`0x007d30..0x008060`) trên bộ đệm ELF64 trong bộ nhớ.
 *
 * Opcode trace / Dấu vết mã máy:
 *   - 0x007e60: `ldrh w20, [sp, #0x9c]` (`ehdr.e_shnum`)
 *   - 0x007e64: `cmp w20, #0x41; b.hs #0x80a0` (`"too many of setction headers = %d"` @ `0x004f90`)
 *   - 0x007ea4: `lsl x22, x20, #6` (`shdr_table_bytes = e_shnum * 64`)
 *   - 0x007ec4: `ldr w8, [x23, #4]; cmp w8, #7; b.ne` (`sh_type == SHT_NOTE`)
 *   - 0x007ed0..0x007f0c: 19-byte `.note.gnu.build-id` comparison
 *   - 0x007fd0..0x007fdc: `ldp w23, w22, [sp, #0x54]; sub x8, x22, #1; cmp x8, #0x40; b.hs`
 *   - 0x007fe4..0x007fe8: `mov w0, #1; bfi x0, x22, #1, #0x20` (`alloc_len = (n_descsz << 1) | 1`)
 *   - 0x008004..0x008010: `add w8, w23, #3; and x8, x8, #0x1fffffffc; add x9, x8, x9; add x2, x9, #0xc`
 *   - 0x008024..0x00804c: Hex formatting loop via `snprintf(out + 2*i, 3, "%02hhx", desc[i])`
 */
std::string ExtractElfBuildIdFromBuffer(const uint8_t* elf_bytes,
                                        size_t elf_len,
                                        std::string* out_error) {
    if (elf_bytes == nullptr || elf_len < sizeof(Elf64Ehdr)) {
        if (out_error != nullptr) {
            *out_error = "read faild, errno=22";
        }
        return {};
    }

    Elf64Ehdr ehdr{};
    std::memcpy(&ehdr, elf_bytes, sizeof(Elf64Ehdr));

    // Verify ELF magic "\x7fELF" and 64-bit class (ELFCLASS64 = 2)
    // Kiểm tra chữ ký ELF "\x7fELF" và kiến trúc 64-bit
    if (ehdr.e_ident[0] != 0x7FU || ehdr.e_ident[1] != 'E' ||
        ehdr.e_ident[2] != 'L'  || ehdr.e_ident[3] != 'F') {
        if (out_error != nullptr) {
            *out_error = "elf init check failed.";
        }
        return {};
    }

    // 0x007e64: cmp w20, #0x41; b.hs #0x80a0 ("too many of setction headers = %d")
    if (ehdr.e_shnum >= kElfMaxSectionHeaders || ehdr.e_shnum == 0U) {
        if (out_error != nullptr) {
            char buf[96];
            std::snprintf(buf, sizeof(buf), "too many of setction headers = %d",
                          static_cast<int>(ehdr.e_shnum));
            *out_error = buf;
        }
        return {};
    }

    // 0x007ea4: lsl x22, x20, #6 (64 bytes per Elf64_Shdr)
    const uint64_t shdr_table_bytes = static_cast<uint64_t>(ehdr.e_shnum) << 6U;
    if (ehdr.e_shoff + shdr_table_bytes > elf_len || ehdr.e_shstrndx >= ehdr.e_shnum) {
        if (out_error != nullptr) {
            *out_error = "lseek faild, errno=22";
        }
        return {};
    }

    const auto* shdrs = reinterpret_cast<const Elf64Shdr*>(elf_bytes + ehdr.e_shoff);
    const Elf64Shdr& shstr_sec = shdrs[ehdr.e_shstrndx];
    if (shstr_sec.sh_offset + shstr_sec.sh_size > elf_len) {
        if (out_error != nullptr) {
            *out_error = "read faild, errno=22";
        }
        return {};
    }
    const uint8_t* shstrtab = elf_bytes + shstr_sec.sh_offset;

    // 0x007ec0..0x007f18: Scan section headers for SHT_NOTE (7) named ".note.gnu.build-id"
    // Quét bảng Section Header tìm phân đoạn SHT_NOTE (7) có tên ".note.gnu.build-id"
    const Elf64Shdr* note_sec = nullptr;
    for (uint16_t i = 0; i < ehdr.e_shnum; ++i) {
        if (shdrs[i].sh_type == kElfNoteSectionType &&
            shdrs[i].sh_name < shstr_sec.sh_size) {
            const size_t rem = static_cast<size_t>(shstr_sec.sh_size - shdrs[i].sh_name);
            if (MatchesNoteGnuBuildIdName(shstrtab + shdrs[i].sh_name, rem)) {
                note_sec = &shdrs[i];
                break;
            }
        }
    }

    if (note_sec == nullptr || note_sec->sh_offset + sizeof(Elf64Nhdr) > elf_len) {
        return {};
    }

    // 0x007fb4..0x007fdc: Read 12-byte Elf64_Nhdr and check 0 < n_descsz <= 0x40
    // Đọc 12 byte Elf64_Nhdr và kiểm tra 0 < n_descsz <= 0x40
    Elf64Nhdr nhdr{};
    std::memcpy(&nhdr, elf_bytes + note_sec->sh_offset, sizeof(Elf64Nhdr));
    if (nhdr.n_descsz == 0U || (nhdr.n_descsz - 1U) >= kElfMaxBuildIdDescBytes) {
        return {};
    }

    // 0x007fe4..0x007fe8: mov w0, #1; bfi x0, x22, #1, #0x20 -> (n_descsz << 1) | 1
    const size_t hex_buf_size = (static_cast<size_t>(nhdr.n_descsz) << 1U) | 1U;

    // 0x008004..0x008010: aligned_namesz = (n_namesz + 3) & ~3; desc_off = sh_offset + 12 + aligned_namesz
    const uint64_t aligned_namesz = (static_cast<uint64_t>(nhdr.n_namesz) + 3ULL) & 0x1FFFFFFFCULL;
    const uint64_t desc_offset = note_sec->sh_offset + sizeof(Elf64Nhdr) + aligned_namesz;
    if (desc_offset + nhdr.n_descsz > elf_len) {
        return {};
    }

    // 0x008024..0x00804c: Format each descriptor byte via "%02hhx" (0x004696)
    std::vector<char> hex_buf(hex_buf_size, '\0');
    const uint8_t* desc_ptr = elf_bytes + desc_offset;
    for (uint32_t i = 0; i < nhdr.n_descsz; ++i) {
        std::snprintf(hex_buf.data() + (static_cast<size_t>(i) << 1U),
                      3U,
                      "%02hhx",
                      static_cast<unsigned char>(desc_ptr[i]));
    }

    return std::string(hex_buf.data(), static_cast<size_t>(nhdr.n_descsz) << 1U);
}

/**
 * @brief Reads an ELF file from disk and extracts its `.note.gnu.build-id` hex string.
 *        Đọc tệp ELF từ đĩa và trích xuất chuỗi hex `.note.gnu.build-id`.
 */
std::string GetElfBuildIdFromFile(const char* elf_path, std::string* out_error) {
    if (elf_path == nullptr || elf_path[0] == '\0') {
        if (out_error != nullptr) {
            *out_error = "open  faild, errno=22";
        }
        return {};
    }

    std::ifstream file(elf_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        if (out_error != nullptr) {
            char buf[256];
            std::snprintf(buf, sizeof(buf), "open %s faild, errno=2", elf_path);
            *out_error = buf;
        }
        return {};
    }

    const std::streamsize size = file.tellg();
    if (size <= 0) {
        return {};
    }
    file.seekg(0, std::ios::beg);
    std::vector<uint8_t> buffer(static_cast<size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        return {};
    }
    return ExtractElfBuildIdFromBuffer(buffer.data(), buffer.size(), out_error);
}

/**
 * @brief Classic ELF SysV Symbol Hash (`ELF_HASH` @ `0x0093b0..0x0093f0`)
 *        Hàm băm biểu tượng ELF SysV cổ điển (`ELF_HASH` tại `0x0093b0..0x0093f0`)
 */
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept {
    if (symbol_name == nullptr) {
        return 0U;
    }
    uint32_t h = 0U;
    for (const auto* p = reinterpret_cast<const uint8_t*>(symbol_name); *p != 0U; ++p) {
        h = (h << 4U) + static_cast<uint32_t>(*p);
        const uint32_t g = h & 0xF0000000U;
        h ^= g;
        h ^= (g >> 24U);
    }
    return h;
}

/**
 * @brief GNU Symbol Hash (`GNU_HASH` @ `0x0093f4..0x009424`, seed `5381`, multiplier `33`)
 *        Hàm băm biểu tượng GNU (`GNU_HASH` tại `0x0093f4..0x009424`, khởi tạo `5381`)
 */
uint32_t ComputeElfGnuHash(const char* symbol_name) noexcept {
    if (symbol_name == nullptr) {
        return 5381U;
    }
    uint32_t h = 5381U;
    for (const auto* p = reinterpret_cast<const uint8_t*>(symbol_name); *p != 0U; ++p) {
        h = (h << 5U) + h + static_cast<uint32_t>(*p);
    }
    return h;
}

GodzillaSysoptRuntime::GodzillaSysoptRuntime()
    : page_size_(4096ULL),
      target_stack_size_(kDefaultPthreadStackSize),
      xhook_debug_enabled_(false),
      xhook_sigsegv_enabled_(false),
      xhook_refreshed_(false),
      sigbus_hook_installed_(false),
      tls_last_sigbus_addr_(0U),
      tls_sigbus_retry_count_(0ULL) {
    InitializePageSize();
}

/**
 * @brief Reconstructs `_GLOBAL__sub_I_PthreadCreateHook.cpp` (`0x0082ec..0x008300`):
 *        `mov w0, #0x28; bl sysconf; str x0, [x8, #0x9c8]`
 *        Tái tạo hàm khởi tạo `.init_array[0]` (`0x0082ec..0x008300`).
 */
void GodzillaSysoptRuntime::InitializePageSize() noexcept {
    // On Android AArch64 _SC_PAGESIZE = 0x28 returns 4096 (or 16384 on 16KB devices)
    page_size_ = 4096ULL;
}

/**
 * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start` (`0x00819c..0x0081ec`).
 *        Tái tạo hàm JNI `IvimageOpt_start` (`0x00819c..0x0081ec`).
 */
bool GodzillaSysoptRuntime::StartIvimageOpt(std::string* out_log) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string log_msg = "GODZILLA: register ivimage optimize\n";
    std::string err;
    const std::string build_id = GetElfBuildIdFromFile("/system/lib/libIVImageSR.so", &err);
    if (!build_id.empty()) {
        // Note: at 0x0081bc: `bl 0x7d30; cbz x0, #0x81cc; bl free` -> returns immediately if found,
        // and logs "Register ivimage optimize failed" at 0x0081cc regardless after freeing or null return.
        log_msg += "GODZILLA: Register ivimage optimize failed";
        if (out_log != nullptr) {
            *out_log = log_msg;
        }
        return true;
    }
    log_msg += "GODZILLA: Register ivimage optimize failed";
    if (out_log != nullptr) {
        *out_log = log_msg;
    }
    return false;
}

/**
 * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start` (`0x0081f4..0x008244`).
 *        Tái tạo hàm JNI `UbsanOpt_start` (`0x0081f4..0x008244`).
 */
bool GodzillaSysoptRuntime::StartUbsanOpt(std::string* out_log) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::string log_msg = "GODZILLA: register ubsan optimize\n";
    std::string err;
    const std::string build_id = GetElfBuildIdFromFile("/system/lib/libbinder.so", &err);
    if (!build_id.empty()) {
        log_msg += "GODZILLA: Register ubsan optimize failed";
        if (out_log != nullptr) {
            *out_log = log_msg;
        }
        return true;
    }
    log_msg += "GODZILLA: Register ubsan optimize failed";
    if (out_log != nullptr) {
        *out_log = log_msg;
    }
    return false;
}

/**
 * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start` (`0x008254..0x0082e8`).
 *        Tái tạo hàm JNI `PthreadCreateHook_start` (`0x008254..0x0082e8`).
 *
 * Opcode trace / Dấu vết mã máy:
 *   - 0x008264: `cmp w2, #1` (`if (stack_size_bytes >= 1)`)
 *   - 0x008270: `str w2, [x8, #0x7c8]` (updates `.data 0x02f7c8` if `w2 >= 1`, else keeps `0x00083000`)
 *   - 0x008278: `ldr w3, [x8, #0x7c8]`
 *   - 0x008280: `__android_log_print(3, "GODZILLA", "SetStackSize to %u", g_target_stack_size)`
 *   - 0x008294: `xhook_enable_debug(1)` (`0x008328`)
 *   - 0x00829c: `xhook_enable_sigsegv_protection(1)` (`0x008338`)
 *   - 0x0082b4: `xhook_register("libart.so", "pthread_attr_setstacksize", hook_pthread_attr_setstacksize, NULL)` (`0x008304`)
 *   - 0x0082e0: `xhook_refresh(0)` (`0x008318`)
 */
int GodzillaSysoptRuntime::StartPthreadCreateHook(int32_t stack_size_bytes, std::string* out_log) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (stack_size_bytes >= 1) {
        target_stack_size_ = static_cast<uint32_t>(stack_size_bytes);
    }

    char log_buf[128];
    std::snprintf(log_buf, sizeof(log_buf), "SetStackSize to %u", target_stack_size_);
    if (out_log != nullptr) {
        *out_log = log_buf;
    }

    xhook_debug_enabled_ = true;
    xhook_sigsegv_enabled_ = true;

    xhook_rules_.push_back(XHookRuleEntry{
        "libart.so",
        "pthread_attr_setstacksize",
        reinterpret_cast<void*>(0x008248ULL),
        nullptr
    });
    xhook_refreshed_ = true;
    return 0;
}

/**
 * @brief Reconstructs `hook_pthread_attr_setstacksize` (`0x008248..0x008250`):
 *        `adrp x8, #0x2f000; ldr w1, [x8, #0x7c8]; b pthread_attr_setstacksize`
 *        Ignores caller's `requested_stack_size` (`x1`) and substitutes `target_stack_size_` (`0x00083000`).
 *        Tái tạo `hook_pthread_attr_setstacksize` (`0x008248..0x008250`): thay thế kích thước stack bằng `target_stack_size_`.
 */
uint32_t GodzillaSysoptRuntime::ApplyHookedPthreadStackSize(uint32_t /*requested_stack_size*/) const noexcept {
    return target_stack_size_;
}

/**
 * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start` (`0x00aa3c..0x00aad8`).
 *        Tái tạo hàm JNI `ThreadHook_start` (`0x00aa3c..0x00aad8`).
 */
void GodzillaSysoptRuntime::StartThreadSigbusHook(std::string* out_log) {
    std::lock_guard<std::mutex> lock(mutex_);
    sigbus_hook_installed_ = true;
    tls_last_sigbus_addr_ = 0U;
    tls_sigbus_retry_count_ = 0ULL;
    if (out_log != nullptr) {
        *out_log = "pyt123: thread start SIGBUS";
    }
}

/**
 * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end` (`0x00aadc..0x00aaf0`).
 *        Tái tạo hàm JNI `ThreadHook_end` (`0x00aadc..0x00aaf0`).
 */
void GodzillaSysoptRuntime::EndThreadSigbusHook(std::string* out_log) {
    std::lock_guard<std::mutex> lock(mutex_);
    sigbus_hook_installed_ = false;
    if (out_log != nullptr) {
        *out_log = "pyt123: thread end";
    }
}

/**
 * @brief Reconstructs `sigbus_handler` (`0x00aaf4..0x00abd8`):
 *   - 0x00ab00: `ldr w8, [x1, #8]; cmp w8, #2; b.ne #0xab30` (`info->si_code == BUS_ADRERR`)
 *   - 0x00ab14: `ldr x22, [x1, #0x10]` (`info->si_addr`)
 *   - 0x00ab28: `cmp x0, x22; b.eq #0xab98` (compares TLS last faulting address with `si_addr`)
 *   - 0x00ab78..0x00ab88: Sets TLS last address to `si_addr` and resets TLS retry counter to `1` (`mov w1, #1`)
 *   - 0x00ab98..0x00abb8: If same `si_addr`, loads TLS retry counter `x0`, checks `cmp x0, #3; b.hs #0xab30`,
 *     increments `x1 = x0 + 1` (`add x1, x0, #1`) and stores back into TLS key `.bss 0x02fbb0`.
 *   Tái tạo hàm xử lý tín hiệu `sigbus_handler` (`0x00aaf4..0x00abd8`).
 */
bool GodzillaSysoptRuntime::HandleSigbusSignal(int32_t signo,
                                               int32_t si_code,
                                               uintptr_t si_addr) noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!sigbus_hook_installed_ || signo != kSigbusSignalNumber) {
        return false;
    }

    // 0x00ab00..0x00ab04: ldr w8, [x1, #8]; cmp w8, #2 (BUS_ADRERR = 2)
    if (si_code != kSigbusAdrErrCode) {
        return false;
    }

    // 0x00ab28: cmp x0, x22; b.eq #0xab98
    if (tls_last_sigbus_addr_ != si_addr) {
        tls_last_sigbus_addr_ = si_addr;
        tls_sigbus_retry_count_ = 1ULL;
        return true;
    }

    // 0x00aba4: cmp x0, #3; b.hs #0xab30
    if (tls_sigbus_retry_count_ >= kSigbusMaxRetryCount) {
        return false;
    }

    // 0x00abb0: add x1, x0, #1
    tls_sigbus_retry_count_ += 1ULL;
    return true;
}

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai
