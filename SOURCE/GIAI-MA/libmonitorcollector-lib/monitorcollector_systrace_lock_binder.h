/**
 * @file monitorcollector_systrace_lock_binder.h
 * @brief Clean-Room C++17 Systrace/Atrace Engine, Lock Contention Detector & Binder Hook
 *        Bộ thu thập Systrace/Atrace, Phát hiện tranh chấp khóa & Hook Binder C++17 Clean-Room
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x012024..0x0120e8`: `InitALogWrapper`, `ALogWrite*`, `enable_log`
 * - `0x01214c..0x0125b4`: `setDebugMode`, `doEnableLock`, `isSystraceInstalled`, `doDisableLock`
 * - `0x0125b4..0x0129d4`: `log_systrace`, `should_log_systrace`, `write_hook`, `init_atrace_record`
 * - `0x012dd0..0x0143a0`: `recordTrace`, `lockinfo_chars`, `dumpAtraceRange`, `initSymbols`, `enableSystrace`, `startHyperAtrace`
 * - `0x0143a0..0x0147a4`: `transact_hook`, `hook_binder`, `unhook_binder`, `enableBinder`
 */

#pragma once

#include "monitorcollector_types.h"
#include "monitorcollector_rodata_tables.h"

namespace bytedance {
namespace monitor {
namespace collector {

void InitALogWrapperImpl(uint64_t alog_instance_ptr) noexcept;
void ALogWriteImpl(int level, const char* tag, const char* msg) noexcept;

void SetDebugModeImpl(bool debug) noexcept;
bool GetDebugModeImpl() noexcept;

void DoEnableLockImpl(int64_t min_stack_threshold_ms, bool lock_all_threads) noexcept;
void DoDisableLockImpl() noexcept;
bool IsSystraceInstalledImpl() noexcept;

bool ShouldLogSystraceImpl(int fd, size_t count) noexcept;
void LogSystraceImpl(const void* buf, size_t count) noexcept;
ssize_t WriteHookImpl(int fd, const void* buf, size_t count) noexcept;

void InitAtraceRecordImpl() noexcept;
void ResetAtraceEventImpl(AtraceEvent* ev) noexcept;
void RecordTraceImpl(const void* buf, size_t count) noexcept;
std::string FormatLockInfoCharsImpl(const LockEvent& ev) noexcept;
std::string DumpAtraceRangeImpl(int64_t start_ms, int64_t end_ms) noexcept;

bool IsSymbolReadyImpl() noexcept;
void InitSymbolsImpl() noexcept;
void EnableSystraceImpl(JavaVM* vm, int run_mode, int64_t flags) noexcept;
void RestoreSystraceImpl() noexcept;
void StartHyperAtraceImpl() noexcept;
void StopHyperAtraceImpl() noexcept;

int TransactHookImpl(void* ipc_thread_state, int32_t handle, uint32_t code,
                     const void* data_parcel, void* reply_parcel, uint32_t flags) noexcept;
int HookBinderImpl() noexcept;
int UnhookBinderImpl() noexcept;
bool EnableBinderImpl() noexcept;
void DisableBinderImpl() noexcept;
void SaveBinderInfoImpl(int64_t start_ms, int64_t end_ms, int64_t transaction_code) noexcept;

} // namespace collector
} // namespace monitor
} // namespace bytedance
