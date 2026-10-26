/**
 * @file sliver_interface.h
 * @brief Public C/JNI/xHook API Header for libsliver.so (Target 66)
 *        Header API C/JNI/xHook công khai cho libsliver.so (Mục tiêu 66)
 *
 * All 7 exported dynamic symbols (.dynsym [100..106]) and 20 JNI native methods
 * registered via RegisterNatives in JNI_OnLoad (0x0039ec..0x003ad4).
 * Tất cả 7 biểu tượng động xuất khẩu (.dynsym [100..106]) và 20 phương thức
 * JNI native đăng ký qua RegisterNatives trong JNI_OnLoad (0x0039ec..0x003ad4).
 */

#ifndef OPENCUT_SLIVER_INTERFACE_H_
#define OPENCUT_SLIVER_INTERFACE_H_

#include "sliver_types.h"
#include "sliver_art_unwinder.h"
#include "sliver_xhook_elf.h"
#include "sliver_sampler_jni.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// 7 EXPORTED DYNAMIC SYMBOLS (.dynsym [100..106])
// 7 BIỂU TƯỢNG ĐỘNG XUẤT KHẨU (.dynsym [100..106])
// ============================================================================

/**
 * [100] xhook_clear @ 0x00b9f0 (344 bytes)
 * Clears all registered hook and ignore rules and frees regex structures.
 * Xóa toàn bộ quy tắc hook và ignore đã đăng ký và giải phóng cấu trúc regex.
 */
void xhook_clear(void);

/**
 * [101] xhook_enable_sigsegv_protection @ 0x00bb64 (20 bytes)
 * Enables/disables SIGSEGV sigsetjmp recovery during ELF memory inspection.
 * Bật/tắt cơ chế phục hồi sigsetjmp SIGSEGV khi kiểm tra bộ nhớ ELF.
 */
void xhook_enable_sigsegv_protection(int flag);

/**
 * [102] xhook_refresh @ 0x00b844 (428 bytes)
 * Scans /proc/self/maps and applies registered PLT/GOT hooks synchronously or async.
 * Quét /proc/self/maps và áp dụng các PLT/GOT hook đã đăng ký đồng bộ hoặc bất đồng bộ.
 */
int xhook_refresh(int async);

/**
 * [103] xhook_register @ 0x00b61c (276 bytes)
 * Registers a PLT/GOT hook rule matching pathname_regex_str and symbol.
 * Đăng ký quy tắc hook PLT/GOT khớp với pathname_regex_str và symbol.
 */
int xhook_register(const char* pathname_regex_str,
                   const char* symbol,
                   void* new_func,
                   void** old_func);

/**
 * [104] JNI_OnLoad @ 0x0039ec (232 bytes)
 * Registers 12 methods on com/bytedance/sliver/Sliver and 8 methods on
 * com/bytedance/sliver/SliverAllThreadSupport; returns JNI_VERSION_1_6 (0x00010006).
 * Đăng ký 12 phương thức trên com/bytedance/sliver/Sliver và 8 phương thức trên
 * com/bytedance/sliver/SliverAllThreadSupport; trả về JNI_VERSION_1_6 (0x00010006).
 */
int32_t JNI_OnLoad(JavaVM* vm, void* reserved);

/**
 * [105] xhook_enable_debug @ 0x00bb48 (28 bytes)
 * Sets xHook minimum log priority: flag != 0 -> ANDROID_LOG_DEBUG (3), else WARN (5).
 * Đặt mức ưu tiên log tối thiểu cho xHook: flag != 0 -> DEBUG (3), ngược lại WARN (5).
 */
void xhook_enable_debug(int flag);

/**
 * [106] xhook_ignore @ 0x00b730 (276 bytes)
 * Registers an ignore rule for pathname_regex_str (and optional symbol).
 * Đăng ký quy tắc bỏ qua cho pathname_regex_str (và symbol tùy chọn).
 */
int xhook_ignore(const char* pathname_regex_str, const char* symbol);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // OPENCUT_SLIVER_INTERFACE_H_
