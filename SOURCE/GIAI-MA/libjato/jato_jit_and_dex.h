// ============================================================================
// File: jato_jit_and_dex.h
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for .init_array/.fini_array lifecycle,
//        JIT Compiler, ProfileInfo, JitCodeCache, JitOptions, JitSuspend,
//        AnnotationResolvingOpt, DexCacheExpandOpt, DexTricks, FastNative,
//        InterpreterBridge, DebugOptimizer, and FDEs 0..599.
//   [VN] Khai báo C++17 sạch cho vòng đời .init_array/.fini_array, JIT Compiler,
//        ProfileInfo, JitCodeCache, JitOptions, JitSuspend, AnnotationResolvingOpt,
//        DexCacheExpandOpt, DexTricks, FastNative, InterpreterBridge, DebugOptimizer.
// ============================================================================

#pragma once

#include "jato_types.h"

namespace bytedance {
namespace jato {
namespace jit {

void RunInitArrayConstructors(int32_t simulated_page_size = 4096) noexcept;
void RunFiniArrayDestructors() noexcept;

bool CompileMethodInternal(JNIEnv* env, int32_t api_level, jobject method, const char* desc) noexcept;
bool HookProfileSaverBugInternal(int32_t api_level) noexcept;
bool ForceSaveProfileInternal(int32_t api_level) noexcept;

bool OptimizeAnnotationResolvingInternal(int32_t api_level) noexcept;
bool OpenInstrumentationCrashFixInternal(int32_t api_level, int32_t arch_bits) noexcept;
void CloseInstrumentationCrashFixInternal() noexcept;

void StartJitCodeCacheMProtectPhase1(int64_t start_addr, int64_t end_addr) noexcept;
bool StartJitCodeCacheMProtectPhase2() noexcept;

bool SetJitCompileThresholds(
    int32_t compile_threshold,
    int32_t warmup_threshold,
    int32_t osr_threshold,
    int32_t priority_thread_weight,
    int32_t invoke_transition_weight) noexcept;

uint64_t DispatchJitAndDexFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace jit
} // namespace jato
} // namespace bytedance
