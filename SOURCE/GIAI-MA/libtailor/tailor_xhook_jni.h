/**
 * @file tailor_xhook_jni.h
 * @brief Embedded xHook PLT/GOT Hooking Subsystem, Chained Hash Set (`Set`),
 *        POSIX `open`/`write` Proxy Interceptors, Crash Log Scanner, and JNI Bridge
 *        (`com/bytedance/tailor/Tailor`) for `libtailor.so`.
 *        Hệ thống con xHook PLT/GOT nhúng, Tập băm chuỗi (`Set`), Bộ chặn proxy POSIX
 *        `open`/`write`, Bộ quét nhật ký sự cố và Cầu nối JNI (`com/bytedance/tailor/Tailor`).
 *
 * Binary Ground Truth (libtailor.so - 84,136 bytes, AArch64):
 * - `xhook_register..xhook_enable_sigsegv_protection` (`0x007fd8..0x008024`)
 * - `xh_core_*` (`0x008074..0x008a98`), `xh_elf_*` (`0x0093f4..0x009ff0`), `xh_util_*` (`0x00a800..0x00aa4c`, `0x00ea30..0x00eac0`)
 * - `close_tailor` (`0x00d868..0x00d924`)
 * - `open_proxy` (`0x00d928..0x00dab0`), `write_proxy` (`0x00dab4..0x00db54`)
 * - `fill_Regex` (`0x00db58..0x00db94`), `try_to_hook` (`0x00db98..0x00dc18`)
 * - `open_tailor` (`0x00dc1c..0x00dc84`), `crop_hprof` (`0x00e0bc..0x00e0bf`)
 * - `getCrashLogFiles` (`0x00e0c0..0x00e54c`), `clearCrashLogFiles` (`0x00e550..0x00e64c`)
 * - `JNI_OnLoad` (`0x00e650..0x00e744`), `JNI_OnUnload` (`0x00e748..0x00e7a8`)
 * - `createSet` (`0x00e8e8..0x00e900`), `hash` (`0x00e904..0x00e92c`), `setContains` (`0x00e930..0x00e970`),
 *   `setInsert` (`0x00e974..0x00e9d8`), `clearSet` (`0x00e9dc..0x00ea2c`)
 */

#ifndef OPENCUT_TAILOR_XHOOK_JNI_H_
#define OPENCUT_TAILOR_XHOOK_JNI_H_

#include "tailor_types.h"
#include "tailor_hprof_engine.h"

#include <string>
#include <vector>

namespace opencut {
namespace tailor {

// ============================================================================
// Chained Hash Set (`Set` / `SetNode` at `0x00e8e8..0x00ea2c`)
// Tập hợp băm nối kết (`Set` / `SetNode` tại `0x00e8e8..0x00ea2c`)
// ============================================================================

/**
 * @brief Allocates a 1024-bucket `Set` (`calloc(0x400, 8)` at `0x00e8e8..0x00e900`).
 *        Cấp phát `Set` gồm 1024 bucket (`calloc(0x400, 8)` tại `0x00e8e8..0x00e900`).
 */
SetNode** createSet() noexcept;

/**
 * @brief Computes `h = h * 33 + c` mod 1024 (`0x00e904..0x00e92c`).
 *        Tính hàm băm `h = h * 33 + c` mod 1024 (`0x00e904..0x00e92c`).
 *
 * AArch64 Disassembly (`0x00e904..0x00e92c`):
 * - `0x00e918: 20 15 00 0b` (`add w0, w9, w0, lsl #5`) -> `w9 + (w0 << 5)` = `c + 33 * h`
 * - `0x00e928: 00 24 40 92` (`and x0, x0, #0x3ff`) -> `h & 0x3FF` (`0..1023`)
 */
uint32_t hash(const char* str) noexcept;

/**
 * @brief Checks if `str` exists in `set` (`0x00e930..0x00e970`).
 *        Kiểm tra xem `str` có tồn tại trong `set` hay không (`0x00e930..0x00e970`).
 */
bool setContains(SetNode** set, const char* str) noexcept;

/**
 * @brief Inserts `str` into `set` if not already present (`0x00e974..0x00e9d8`).
 *        Chèn `str` vào `set` nếu chưa tồn tại (`0x00e974..0x00e9d8`).
 */
void setInsert(SetNode** set, const char* str) noexcept;

/**
 * @brief Frees all nodes and the bucket array in `set` (`0x00e9dc..0x00ea2c`).
 *        Giải phóng toàn bộ các nút và mảng bucket trong `set` (`0x00e9dc..0x00ea2c`).
 */
void clearSet(SetNode** set) noexcept;

// ============================================================================
// xHook Core / ELF / Utility Functions (`0x007fd8..0x00aa4c`, `0x00ea30..0x00eac0`)
// Các hàm xHook Core / ELF / Utility (`0x007fd8..0x00aa4c`, `0x00ea30..0x00eac0`)
// ============================================================================

/**
 * @brief Checks the ELF64 header magic (`\x7fELF`), class (`ELFCLASS64 = 2`),
 *        endianness (`ELFDATA2LSB = 1`), and version (`0x009fb8..0x009ff0`).
 *        Kiểm tra tiêu đề ELF64 (`\x7fELF`, `ELFCLASS64 = 2`, `ELFDATA2LSB = 1`).
 */
int xh_elf_check_elfheader(uintptr_t base_addr) noexcept;

/**
 * @brief Sets memory protection for `[addr, addr + len)` (`0x00a9c0..0x00aa48`).
 *        Thiết lập quyền bảo vệ bộ nhớ cho vùng `[addr, addr + len)` (`0x00a9c0..0x00aa48`).
 *
 * Returns `0` on success; on failure returns `errno` if non-zero, or `1001` (`0x3e9`)
 * via `mov w8, #0x3e9` (`0x52807D28` at `0x00aa30`).
 */
int xh_util_set_addr_protect(uintptr_t addr, size_t len, int prot) noexcept;

/**
 * @brief Flushes the AArch64 data and instruction caches for `[begin, end)` (`0x00ea30..0x00eac0`).
 *        Làm mới bộ nhớ đệm dữ liệu và lệnh AArch64 cho vùng `[begin, end)`.
 *
 * AArch64 Disassembly (`0x00ea30..0x00eac0`):
 * - `0x00ea48: 29 00 3b d5` (`mrs x9, ctr_el0`)
 * - `0x00ea70: 2a 7b 0b d5` (`dc cvau, x10`)
 * - `0x00ea80: 9f 3b 03 d5` (`dsb ish`)
 * - `0x00eaa8: 29 75 0b d5` (`ic ivau, x9`)
 * - `0x00eabc: df 3f 03 d5` (`isb`)
 */
int xh_util_flush_instruction_cache(uintptr_t begin, uintptr_t end) noexcept;

int xh_core_register(const char* pathname_regex_str, const char* symbol,
                     void* new_func, void** old_func) noexcept;
int xh_core_ignore(const char* pathname_regex_str, const char* symbol) noexcept;
int xh_core_refresh(int async) noexcept;
void xh_core_clear() noexcept;
void xh_core_enable_debug(int flag) noexcept;
void xh_core_enable_sigsegv_protection(int flag) noexcept;

// ============================================================================
// Tailor POSIX HPROF Hook & JNI Functions (`0x00d868..0x00e7a8`)
// Các hàm Hook POSIX HPROF và JNI của Tailor (`0x00d868..0x00e7a8`)
// ============================================================================

/**
 * @brief Formats `/proc/<pid>/maps` or `".*\\.so$"` regex (`0x00db58..0x00db94`).
 *        Định dạng biểu thức chính quy cho thư viện cần hook (`0x00db58..0x00db94`).
 */
int fill_Regex(char* buf, const char* name) noexcept;

/**
 * @brief Registers xHook PLT/GOT hooks on `open` and `write` across ART / libc (`0x00db98..0x00dc18`).
 *        Đăng ký xHook PLT/GOT cho `open` và `write` trên các thư viện ART / libc (`0x00db98..0x00dc18`).
 */
int try_to_hook(bool hook_all) noexcept;

/**
 * @brief Proxy interceptor for POSIX `open(const char* pathname, int flags, ...)` (`0x00d928..0x00dab0`).
 *        Hàm chặn proxy cho POSIX `open(const char* pathname, int flags, ...)` (`0x00d928..0x00dab0`).
 */
int open_proxy(const char* pathname, int flags, int mode);

/**
 * @brief Proxy interceptor for POSIX `write(int fd, const void* buf, size_t count)` (`0x00dab4..0x00db54`).
 *        Hàm chặn proxy cho POSIX `write(int fd, const void* buf, size_t count)` (`0x00dab4..0x00db54`).
 */
ssize_t write_proxy(int fd, const void* buf, size_t count);

/**
 * @brief Opens Tailor interceptor for `target` HPROF path (`0x00dc1c..0x00dc84`).
 *        Mở bộ chặn Tailor cho đường dẫn HPROF `target` (`0x00dc1c..0x00dc84`).
 */
void open_tailor_native(const char* target_path, bool gzip);

/**
 * @brief Closes Tailor interceptor and flushes compressed output (`0x00d868..0x00d924`).
 *        Đóng bộ chặn Tailor và đẩy luồng dữ liệu nén ra tệp (`0x00d868..0x00d924`).
 */
void close_tailor_native();

/**
 * @brief Offline HPROF cropper (`_Z10crop_hprofP7_JNIEnvP7_jclassP8_jstringS4_` at `0x00e0bc..0x00e0bf`).
 *        Note: In `libtailor.so` at `0x00e0bc`, `_Z10crop_hprof...` is a single `ret` (`c0 03 5f d6`),
 *        while `crop_hprof_file` provides the full offline file-to-file cropping pipeline using `TailorImpl`.
 *        Hàm cắt gọt tệp HPROF ngoại tuyến.
 */
int crop_hprof_file(const char* source_path, const char* target_path, bool gzip);

/**
 * @brief Scans `/proc/self/fd` or crash directory for `.hprof` / crash log files (`0x00e0c0..0x00e54c`).
 *        Quét `/proc/self/fd` hoặc thư mục sự cố để lấy danh sách tệp nhật ký sự cố (`0x00e0c0..0x00e54c`).
 */
std::vector<std::string> scanCrashLogFiles(const char* dir_path = nullptr);

/**
 * @brief Returns the 5 JNI native method descriptors at `.data.rel.ro` (`0x0177f8..0x01786f`).
 *        Trả về bảng 5 phương thức JNI native tại `.data.rel.ro` (`0x0177f8..0x01786f`).
 */
const TailorJniMethodEntry* getTailorJniMethods(size_t* out_count) noexcept;

} // namespace tailor
} // namespace opencut

#endif // OPENCUT_TAILOR_XHOOK_JNI_H_
