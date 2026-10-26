// ============================================================================
// FILE: scudo_vma_string_opt.h
// TARGET: libgodzilla-memsponge.so (.text 0x07888c..0x078953, 0x07c290..0x07d8a3)
// PURPOSE: Scudo Secondary Allocator VMA Leak Mitigation (`scudo:secondary` ->
//          `scudo:secondary_unguard`) and `StringFactory.newStringFromString`
//          Zero-Copy ArtMethod Hook (`jni_hook`).
// MỤC ĐÍCH: Vá lỗi rò rỉ vùng nhớ ảo VMA của bộ cấp phát thứ cấp Scudo
//           (`scudo:secondary` -> `scudo:secondary_unguard`) và Hook ArtMethod
//           không sao chép cho `StringFactory.newStringFromString` (`jni_hook`).
// ============================================================================

#pragma once

#include "godzilla_memsponge_types.h"

namespace NextAI::OpenCut::godzilla_memsponge {

// ============================================================================
// 1. SCUDO VMA LEAK MITIGATION ENGINE (0x07c290..0x07d437)
// ============================================================================

/**
 * EN: Computes the Scudo secondary guard VMA size threshold:
 *     `threshold = (page_size << 1) + (0xA << 12)` (`lsl w8, w0, #1; add w8, w8, #0xa, lsl #12`
 *     @ `0x07c434..0x07c438`, `0x07c628..0x07c62c`, `0x07c8fc..0x07c900`, `0x07d160..0x07d164`).
 *     For standard `4,096`-byte pages: `8,192 + 40,960 = 49,152` (`0xC000`) bytes.
 * VN: Tính ngưỡng kích thước VMA bảo vệ thứ cấp của Scudo:
 *     `threshold = (page_size << 1) + (0xA << 12)`.
 *     Với trang 4.096 byte: `8.192 + 40.960 = 49.152` (`0xC000`) byte.
 */
size_t computeScudoSecondaryMaxBytes(int page_size);

/**
 * EN: Hooks Scudo standalone `_ZN5scudo3mapEPvmmPNS_13MapPlatformDataE` (`0x4fda8`) and
 *     `_ZN5scudo5unmapEPvmmPNS_13MapPlatformDataE` (`0x4edc0`) in `libc.so`.
 *     Binary address: `0x07c290` (`size = 188 B`).
 * VN: Hook cặp hàm `_ZN5scudo3mapE...` và `_ZN5scudo5unmapE...` trong `libc.so`.
 *     Địa chỉ nhị phân: `0x07c290` (`size = 188 B`).
 */
int init_scudo_map();

void* scudoMapProxy(void* addr, size_t size, const char* name, uint64_t flags, void* data);
void scudoUnmapProxy(void* addr, size_t size, uint64_t flags, void* data);

/**
 * EN: Hooks Android 12+ `scudo::MemMapLinux::mapImpl` (`0x51b1e`), `remapImpl` (`0x510a0`),
 *     `unmapImpl` (`0x510c8`), and PLT-hooks `mmap` (`0x510ec`) in `libc.so` via ByteHook.
 *     Binary address: `0x07c724` (`size = 332 B`).
 * VN: Hook các hàm `scudo::MemMapLinux::mapImpl`, `remapImpl`, `unmapImpl` và PLT `mmap`
 *     trong `libc.so` trên Android 12+.
 *     Địa chỉ nhị phân: `0x07c724` (`size = 332 B`).
 */
int init_scudo_linux_map();

bool scudoLinuxMapProxy(void* thiz, uintptr_t addr, size_t size, const char* name, uint64_t flags);
bool scudoLinuxRemapProxy(void* thiz, uintptr_t addr, size_t size, const char* name, uint64_t flags);
void scudoLinuxUnmapProxy(void* thiz, uintptr_t addr, size_t size);
void* scudoMmapProxy(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
void scudoByteHookCallback(void* task_stub, int status_code, const char* caller_path_name,
                           const char* sym_name, void* new_func, void* prev_func, void* arg);

/**
 * EN: Main entry point for Scudo VMA leak mitigation (`_Z18fix_scudo_vma_leakb` @ `0x07cee8`, `size = 560 B`).
 *     Checks `libc.so` for `scudo_mallopt` (`0x5022a`) and `_ZN5scudo11MemMapLinux7mapImplEmmPKcm`.
 *     - When `is_enforce == true`: uses ShadowHook on Scudo `map`/`unmap` (`init_scudo_map` / `init_scudo_linux_map`).
 *     - When `is_enforce == false`: uses ByteHook PLT hook on `prctl` (`scudoPrctlProxy` @ `0x07d118`).
 * VN: Điểm vào chính để vá lỗi rò rỉ VMA của Scudo (`_Z18fix_scudo_vma_leakb` @ `0x07cee8`, `560 B`).
 */
int fix_scudo_vma_leak(bool is_enforce);

/**
 * EN: Proxy for `prctl` (`0x07d118`, `size = 484 B`).
 *     Intercepts `prctl(PR_SET_VMA = 0x53564d41, PR_SET_VMA_ANON_NAME = 0, addr, size, "scudo:secondary")`
 *     when `size <= (getpagesize() << 1) + 0xa000`, remaps the left (`addr - page_size`) and right
 *     (`addr + size`) guard pages with `PROT_READ | PROT_WRITE (3)` and `MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS (0x32)`,
 *     and renames the combined `[addr - page_size, size + 2 * page_size)` VMA to `"scudo:secondary_unguard"`.
 * VN: Hàm Proxy cho `prctl` (`0x07d118`, `484 B`), gộp 2 trang bảo vệ trái/phải của `"scudo:secondary"`
 *     và đổi tên VMA thành `"scudo:secondary_unguard"`.
 */
int scudoPrctlProxy(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);

// ============================================================================
// 2. STRINGFACTORY ZERO-COPY JNI ART METHOD HOOK (0x07888c..0x078953, 0x07d5e4..0x07d8a3)
// ============================================================================

/**
 * EN: Replacement native implementation for `java.lang.StringFactory.newStringFromString(String)`
 *     (`0x0788fc`, `size = 68 B`).
 *     Directly returns the input `jstring` (`x2` -> `x0`) without allocating a duplicate `String` object!
 * VN: Hàm native thay thế cho `java.lang.StringFactory.newStringFromString(String)` (`0x0788fc`, `68 B`).
 *     Trả về trực tiếp chuỗi `jstring` đầu vào (`x2` -> `x0`) mà không cấp phát bản sao!
 */
jstring Replaced_StringFactory_newStringFromString(JNIEnv* env, jclass clazz, jstring src);

namespace jni_hook {

/**
 * EN: Resolves the internal `art::ArtMethod*` pointer for a Java method by calling `FindClass`,
 *     `GetStaticMethodID`/`GetMethodID`, `ToReflectedMethod`, and reading the `artMethod` (`long`) field
 *     on `java.lang.reflect.Executable`.
 *     Binary address: `0x07d5e4` (`size = 436 B`).
 * VN: Phân giải con trỏ `art::ArtMethod*` nội bộ của phương thức Java thông qua `ToReflectedMethod`
 *     và trường `artMethod` (`J`) của `java.lang.reflect.Executable`.
 *     Địa chỉ nhị phân: `0x07d5e4` (`size = 436 B`).
 */
void* get_art_method(JNIEnv* env, const char* class_name, const char* method_name, const char* sig, bool is_static);

/**
 * EN: Hooks `target_art_method` by discovering `entry_point_from_jni_` offset (`sArtMethodEntryPointOffset`
 *     @ `0x1063c8`) using a dummy JNI registration on `com/bytedance/platform/godzilla/memopt/StringOptHelper.debug(Z)V`
 *     with `dummy_jni_ stub` (`0x07d8a0`: `ret`), scanning `[0..0xc8)` in 4-byte steps (`0x07d85c..0x07d870`),
 *     and overwriting `*(void**)((char*)target_art_method + offset) = new_jni_func`.
 *     Binary address: `0x07d798` (`size = 264 B`).
 * VN: Hook `target_art_method` bằng cách dò độ lệch `entry_point_from_jni_` (`sArtMethodEntryPointOffset`
 *     @ `0x1063c8`) trong phạm vi `[0..0xc8)` với bước nhảy 4 byte, rồi ghi đè con trỏ hàm JNI mới.
 *     Địa chỉ nhị phân: `0x07d798` (`size = 264 B`).
 */
bool hook_art_method(JNIEnv* env, void* target_art_method, void* new_jni_func, void** orig_jni_func);

} // namespace jni_hook

} // namespace NextAI::OpenCut::godzilla_memsponge
