/**
 * ============================================================================
 * File: SOURCE/GIAI-MA/libart_sym/art_sym_interface.h
 * Library: libart_sym.so (124,720 bytes, SHA-256: cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8)
 * Target: 72 / 169 — Public Clean-Room C++17 Interface Header
 * ============================================================================
 *
 * [EN] Master interface header combining all 6 subsystems of `libart_sym.so`:
 * 1. Core ABI & Memory Probing (`art_sym_types.h`)
 * 2. ArtMethod, ArtMethodModifier, ArtFieldModifier, DisableHiddenApi, ArtClassLinker
 *    (`art_method_field_modifier.h`)
 * 3. ArtRuntime, Heap, ArtInstrumentation, Jit, JitCodeCache, ReaderWriterMutex, Locks
 *    (`art_runtime_heap_jit.h`)
 * 4. ArtThread, ThreadList, ScopedJitSuspend, ScopedSuspendAll, ScopedGCCriticalSection,
 *    ScopedPLTHook, bytesig_*, and `.init_array` (`art_thread_scoped_hook.h`)
 *
 * [VN] Tệp tiêu đề giao diện tổng hợp toàn bộ 6 phân hệ của `libart_sym.so`:
 * 1. Cấu trúc ABI cốt lõi & Thăm dò bộ nhớ (`art_sym_types.h`)
 * 2. ArtMethod, ArtMethodModifier, ArtFieldModifier, DisableHiddenApi, ArtClassLinker
 *    (`art_method_field_modifier.h`)
 * 3. ArtRuntime, Heap, ArtInstrumentation, Jit, JitCodeCache, ReaderWriterMutex, Locks
 *    (`art_runtime_heap_jit.h`)
 * 4. ArtThread, ThreadList, ScopedJitSuspend, ScopedSuspendAll, ScopedGCCriticalSection,
 *    ScopedPLTHook, bytesig_*, và `.init_array` (`art_thread_scoped_hook.h`)
 * ============================================================================
 */

#ifndef NEXTAI_OPENCUT_LIBART_SYM_INTERFACE_H_
#define NEXTAI_OPENCUT_LIBART_SYM_INTERFACE_H_

#include "art_sym_types.h"
#include "art_method_field_modifier.h"
#include "art_runtime_heap_jit.h"
#include "art_thread_scoped_hook.h"

#endif  // NEXTAI_OPENCUT_LIBART_SYM_INTERFACE_H_
