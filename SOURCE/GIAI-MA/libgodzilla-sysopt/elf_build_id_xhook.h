/**
 * @file elf_build_id_xhook.h
 * @brief Clean-Room Header for ELF Build-ID Inspector, xHook Engine, Pthread Stack Optimizer & SIGBUS Handler.
 *        Header tái tạo sạch cho Bộ đọc Build-ID ELF, Engine xHook, Tối ưu Stack Pthread và Trình xử lý SIGBUS.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x007d30..0x008060 : getElfBuildId(const char* elf_path)
 *     - 0x00819c..0x0081f0 : Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start / end
 *     - 0x0081f4..0x008244 : Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start / end
 *     - 0x008248..0x0082e8 : hook_pthread_attr_setstacksize & PthreadCreateHook_start / end
 *     - 0x0082ec..0x008300 : _GLOBAL__sub_I_PthreadCreateHook.cpp (.init_array[0] sysconf(_SC_PAGESIZE))
 *     - 0x008304..0x00aa38 : xHook PLT/GOT Hooking Engine (ELF_HASH, GNU_HASH, RELA/REL/ANDROID_REL)
 *     - 0x00aa3c..0x00abd8 : ThreadHook_start / ThreadHook_end & sigbus_handler (SIGBUS BUS_ADRERR guard)
 */

#ifndef NEXTAI_OPENCUT_GODZILLA_SYSOPT_ELF_BUILD_ID_XHOOK_H_
#define NEXTAI_OPENCUT_GODZILLA_SYSOPT_ELF_BUILD_ID_XHOOK_H_

#include "godzilla_sysopt_types.h"

#include <cstddef>
#include <cstdint>
#include <mutex>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

/**
 * @brief Extracts the `.note.gnu.build-id` hex string from a 64-bit ELF shared library.
 *        Trích xuất chuỗi hex `.note.gnu.build-id` từ thư viện chia sẻ ELF 64-bit.
 *
 * Reconstructs `getElfBuildId` (`0x007d30..0x008060`):
 *   - Opens `elf_path` with `O_RDONLY | O_CLOEXEC` (`0x80000`).
 *   - Reads 64-byte `Elf64_Ehdr`, verifies `e_shnum < 0x41` (`cmp w20, #0x41` at `0x007e64`).
 *   - Reads `e_shnum * 64` bytes of `Elf64_Shdr` (`lsl x22, x20, #6` at `0x007ea4`).
 *   - Scans sections for `sh_type == 7` (`SHT_NOTE`) and 19-byte name `".note.gnu.build-id"`
 *     (`0x6e672e65746f6e2e`, `0x2d646c6975622e75`, `0x0064692d646c6975` at `0x007ed0..0x007f0c`).
 *   - Reads 12-byte `Elf64_Nhdr`, checks `0 < n_descsz <= 0x40` (`0x007fd8`),
 *     allocates `(n_descsz << 1) | 1` bytes (`bfi x0, x22, #1, #0x20` at `0x007fe8`),
 *     reads note descriptor at `sh_offset + 12 + ((n_namesz + 3) & ~3)`,
 *     and formats lowercase hex via `"%02hhx"` (`0x004696`).
 *
 * @param elf_bytes Raw bytes of the target ELF64 image (or read from `elf_path`).
 * @param out_error Optional error message matching `.rodata` format strings.
 * @return Lowercase hex Build-ID string, or empty string on failure.
 */
std::string ExtractElfBuildIdFromBuffer(const uint8_t* elf_bytes,
                                        size_t elf_len,
                                        std::string* out_error = nullptr);

std::string GetElfBuildIdFromFile(const char* elf_path, std::string* out_error = nullptr);

/**
 * @brief Classic ELF SysV Symbol Hash (`ELF_HASH`, `.rodata` `0x004160`) [OBSERVED at 0x0093b0..0x0093f0]
 *        Hàm băm biểu tượng ELF SysV cổ điển (`ELF_HASH`) [QUAN SÁT ĐƯỢC tại 0x0093b0..0x0093f0]
 */
uint32_t ComputeElfSysvHash(const char* symbol_name) noexcept;

/**
 * @brief GNU Hash (`GNU_HASH`, `.rodata` `0x00500f`) [OBSERVED at 0x0093f4..0x009424]
 *        Hàm băm biểu tượng GNU (`GNU_HASH`, khởi tạo `h = 5381`, `h = h * 33 + c`) [QUAN SÁT ĐƯỢC tại 0x0093f4..0x009424]
 */
uint32_t ComputeElfGnuHash(const char* symbol_name) noexcept;

/**
 * @brief Clean-Room Reconstruction of the xHook PLT/GOT Engine (`0x008304..0x00aa38`),
 *        Pthread Stack Optimizer (`0x008248..0x008300`), and SIGBUS Guard (`0x00aa3c..0x00abd8`).
 *        Tái tạo sạch Engine PLT/GOT xHook, Bộ tối ưu Stack Pthread và Trình bảo vệ SIGBUS.
 */
class GodzillaSysoptRuntime {
public:
    GodzillaSysoptRuntime();
    ~GodzillaSysoptRuntime() = default;

    /**
     * @brief Reconstructs `.init_array[0]` (`0x0082ec..0x008300`):
     *        Queries `sysconf(_SC_PAGESIZE = 0x28)` and stores page size at `.bss 0x02f9c8`.
     *        Tái tạo `.init_array[0]` (`0x0082ec..0x008300`): truy vấn `sysconf(0x28)` và lưu kích thước trang.
     */
    void InitializePageSize() noexcept;

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start` (`0x00819c`).
     *        Tái tạo hàm JNI `IvimageOpt_start` (`0x00819c`) kiểm tra `/system/lib/libIVImageSR.so`.
     */
    bool StartIvimageOpt(std::string* out_log = nullptr);

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end` (`0x0081f0`, `ret`).
     */
    void EndIvimageOpt() noexcept {}

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start` (`0x0081f4`).
     *        Tái tạo hàm JNI `UbsanOpt_start` (`0x0081f4`) kiểm tra `/system/lib/libbinder.so`.
     */
    bool StartUbsanOpt(std::string* out_log = nullptr);

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end` (`0x0081f0`, `ret`).
     */
    void EndUbsanOpt() noexcept {}

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start` (`0x008254`).
     *        Tái tạo hàm JNI `PthreadCreateHook_start` (`0x008254`) cài đặt PLT hook `pthread_attr_setstacksize`
     *        trên `libart.so` với kích thước stack mặc định `0x00083000` (536,576 bytes) hoặc giá trị tùy chỉnh.
     */
    int StartPthreadCreateHook(int32_t stack_size_bytes, std::string* out_log = nullptr);

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end` (`0x0081f0`, `ret`).
     */
    void EndPthreadCreateHook() noexcept {}

    /**
     * @brief Reconstructs `hook_pthread_attr_setstacksize` (`0x008248..0x008250`):
     *        Overrides the requested `stack_size` argument (`x1`) with `g_target_stack_size` (`.data 0x02f7c8`)
     *        before tail-calling Bionic `pthread_attr_setstacksize(attr, g_target_stack_size)`.
     *        Tái tạo hàm trung gian `hook_pthread_attr_setstacksize` (`0x008248`) ghi đè kích thước stack.
     */
    uint32_t ApplyHookedPthreadStackSize(uint32_t requested_stack_size) const noexcept;

    /**
     * @brief Reconstructs `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start` (`0x00aa3c`)
     *        and `ThreadHook_end` (`0x00aadc`).
     *        Tái tạo `ThreadHook_start` (`0x00aa3c`) cài đặt trình xử lý tín hiệu `SIGBUS` (`7`)
     *        với cờ `SA_SIGINFO | SA_ONSTACK | SA_RESTART` (`0x18000004`).
     */
    void StartThreadSigbusHook(std::string* out_log = nullptr);
    void EndThreadSigbusHook(std::string* out_log = nullptr);

    /**
     * @brief Reconstructs `sigbus_handler` (`0x00aaf4..0x00abd8`):
     *        Handles `SIGBUS` (`sig == 7`) when `si_code == BUS_ADRERR` (`2`), tracking the
     *        faulting address (`si_addr`) and per-thread retry count (`< 3`) in TLS keys
     *        (`.bss 0x02fbac` and `.bss 0x02fbb0`).
     *        Tái tạo hàm xử lý `sigbus_handler` (`0x00aaf4..0x00abd8`) đếm số lần thử lại `< 3` trên mỗi luồng.
     *
     * @return true if intercepted and suppressed (retry < 3), false if chained to previous handler.
     */
    bool HandleSigbusSignal(int32_t signo, int32_t si_code, uintptr_t si_addr) noexcept;

    // Accessors for verification / Các hàm truy xuất phục vụ kiểm thử
    uint64_t page_size() const noexcept { return page_size_; }
    uint32_t target_stack_size() const noexcept { return target_stack_size_; }
    bool xhook_debug_enabled() const noexcept { return xhook_debug_enabled_; }
    bool xhook_sigsegv_enabled() const noexcept { return xhook_sigsegv_enabled_; }
    bool sigbus_hook_installed() const noexcept { return sigbus_hook_installed_; }
    const std::vector<XHookRuleEntry>& xhook_rules() const noexcept { return xhook_rules_; }

private:
    mutable std::mutex mutex_;
    uint64_t page_size_;
    uint32_t target_stack_size_;
    bool xhook_debug_enabled_;
    bool xhook_sigsegv_enabled_;
    bool xhook_refreshed_;
    bool sigbus_hook_installed_;
    uintptr_t tls_last_sigbus_addr_;
    uint64_t tls_sigbus_retry_count_;
    std::vector<XHookRuleEntry> xhook_rules_;
};

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_GODZILLA_SYSOPT_ELF_BUILD_ID_XHOOK_H_
