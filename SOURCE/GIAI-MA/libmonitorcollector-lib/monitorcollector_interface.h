/**
 * @file monitorcollector_interface.h
 * @brief Clean-Room C++17 Public ABI & Exported Symbol Interface for libmonitorcollector-lib.so
 *        Giao diện ABI công khai & Ký hiệu xuất khẩu C++17 Clean-Room cho libmonitorcollector-lib.so
 *
 * Binary SHA-256: 739e2276dd31bc2805670367cfff2abc4a3d26e73e5b75635daff2a1f125e183
 * Binary Size:    313,744 bytes
 * Exported .dynsym Symbols: 350 (including JNI_OnLoad, 46 MonitorJni callbacks, 4 GraphicsMonitor
 *                           JNI exports, 4 xhook JNI exports, and 9 xhook C APIs)
 */

#pragma once

#include "monitorcollector_types.h"
#include "monitorcollector_rodata_tables.h"
#include "monitorcollector_systrace_lock_binder.h"
#include "monitorcollector_proc_art_xhook.h"

extern "C" {

jint JNI_OnLoad(JavaVM* vm, void* reserved);

// ALog Wrapper C Exports (`0x012024..0x0120e8`)
void InitALogWrapper(uint64_t alog_instance) noexcept;
void ALogWrite(int level, const char* tag, const char* msg) noexcept;
void ALogWriteV(const char* tag, const char* msg) noexcept;
void ALogWriteD(const char* tag, const char* msg) noexcept;
void ALogWriteI(const char* tag, const char* msg) noexcept;
void ALogWriteW(const char* tag, const char* msg) noexcept;
void ALogWriteE(const char* tag, const char* msg) noexcept;
int  enable_log() noexcept;

// Time & ProcFS C Exports (`0x014db0..0x01701c`)
int64_t monotonicTime() noexcept;
int64_t clockTime() noexcept;
int32_t get_device_api_level() noexcept;

// GraphicsMonitor JNI Exports (`0x01701c..0x017388`)
jboolean Java_com_bytedance_common_graphics_GraphicsMonitor_startHook(JNIEnv* env, jclass clazz) noexcept;
void Java_com_bytedance_common_graphics_GraphicsMonitor_openStatistical(JNIEnv* env, jclass clazz) noexcept;
void Java_com_bytedance_common_graphics_GraphicsMonitor_closeStatistical(JNIEnv* env, jclass clazz) noexcept;
jdouble Java_com_bytedance_common_graphics_GraphicsMonitor_getStatisticOnceData(JNIEnv* env, jclass clazz) noexcept;

// xHook JNI & C Exports (`0x01cfbc..0x01f568`)
int xhook_register(const char* pathname_regex_str, const char* symbol, void* new_func, void** old_func) noexcept;
int xhook_ignore(const char* pathname_regex_str, const char* symbol) noexcept;
int xhook_refresh(int async) noexcept;
void xhook_clear() noexcept;
void xhook_enable_debug(int flag) noexcept;
void xhook_enable_sigsegv_protection(int flag) noexcept;
jint Java_com_qiyi_xhook_NativeHandler_refresh(JNIEnv* env, jobject thiz, jboolean async) noexcept;
void Java_com_qiyi_xhook_NativeHandler_clear(JNIEnv* env, jobject thiz) noexcept;
void Java_com_qiyi_xhook_NativeHandler_enableDebug(JNIEnv* env, jobject thiz, jboolean flag) noexcept;
void Java_com_qiyi_xhook_NativeHandler_enableSigSegvProtection(JNIEnv* env, jobject thiz, jboolean flag) noexcept;

} // extern "C"
