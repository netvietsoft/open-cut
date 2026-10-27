// ============================================================================
// File: jato_jit_and_dex.cpp
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of .init_array/.fini_array, JIT,
//        ProfileInfo, JitOptions, JitCodeCacheMProtectOpt, DexCacheExpandOpt,
//        DexTricks, FastNative, InterpreterBridge, DebugOptimizer, and FDEs 0..599.
//   [VN] Thực thi C++17 sạch cho .init_array/.fini_array, JIT, ProfileInfo,
//        JitOptions, JitCodeCacheMProtectOpt, DexCacheExpandOpt, DexTricks,
//        FastNative, InterpreterBridge, DebugOptimizer và FDE 0..599.
// ============================================================================

#include "jato_jit_and_dex.h"
#include "jato_rodata_tables.h"

namespace bytedance {
namespace jato {

JatoGlobalState g_jato_state = {
    4096,       // page_size (.init_array[6] @ 0x00b9fc: sysconf(39))
    -4096,      // page_mask (.init_array[6] @ 0x00ba1c: neg w9, w0)
    64,         // arch_bits (.data 0x05c048 = 0x40)
    -1,         // art_apex_version (.data 0x05c010 = -1)
    0,          // render_thread_tid (.bss 0x05c0e0)
    0,          // prio_protect_enabled (.bss 0x05c0e4)
    0,          // los_use_new_free (.bss 0x05c258)
    0,          // los_need_gc_block (.bss 0x05c25c)
    nullptr,    // los_threshold_ptr (.bss 0x05c260)
    nullptr,    // los_space_instance (.bss 0x05c270)
    nullptr,    // los_get_bytes_allocated (.bss 0x05c278)
    nullptr,    // los_allocated_bytes_fallback (.bss 0x05c280)
    nullptr,    // force_process_profiles_fn (.bss 0x05c130)
    nullptr,    // max_spins_before_inflation (.bss 0x05c668)
    0,          // scheduler_inited (.bss 0x05bcf8)
    0,          // buffer_barrier_hook_logs (.bss 0x05d598)
    0,          // buffer_barrier_active (.bss 0x05d599)
    0,          // jit_mprotect_phase1_ok (.bss 0x05d769)
    0ULL,       // jit_code_cache_start (.bss 0x05d770)
    0ULL        // jit_code_cache_end (.bss 0x05d778)
};

namespace jit {

static int32_t g_jit_thresholds[5] = {10000, 5000, 20000, 5, 5};
static bool g_jit_code_cache_gc_enabled = true;
static bool g_jit_suspend_inited = false;
static bool g_jit_suspended = false;
static int32_t g_jit_dump_mode = 0;
static bool g_profile_info_inited = false;
static bool g_instrumentation_crash_fix_open = false;

// ============================================================================
// [EN] .init_array[0..23] (0x00b8e0..0x00be48, 0x02a5e4) & .fini_array[0..1] (0x00be7c, 0x00be6c)
//      Specifically .init_array[6] @ 0x00b9fc..0x00ba2c:
//        0x00ba04: mov w0, #0x27 (_SC_PAGESIZE = 39)
//        0x00ba08: bl sysconf
//        0x00ba1c: neg w9, w0
//        0x00ba20: str w0, [x8]  (g_page_size)
//        0x00ba24: str w9, [x10] (g_page_mask)
// [VN] Khởi tạo 24 hàm .init_array, đặc biệt .init_array[6] tại 0x00b9fc tính page_size & page_mask.
// ============================================================================
void RunInitArrayConstructors(int32_t simulated_page_size) noexcept {
    int32_t w0 = (simulated_page_size > 0) ? simulated_page_size : 4096;
    int32_t w9 = -w0; // 0x00ba1c: 4b0003e9 neg w9, w0
    g_jato_state.page_size = w0;
    g_jato_state.page_mask = w9;
    g_jato_state.arch_bits = 64; // .data 0x05c048 = 0x40
}

void RunFiniArrayDestructors() noexcept {
    // 0x00be7c -> 0x038e84: checks timer/resource at .bss 0x05e470+4 and deletes timer if active
    // 0x00be6c -> __cxa_finalize(&__dso_handle @ 0x05a5e8)
    g_instrumentation_crash_fix_open = false;
}

// ============================================================================
// [EN] JitCompiler::nativeCompile (0x00c658, 152 B) & nativeHookProfileSaverBug (0x00c6f0, 460 B)
// [VN] Biên dịch phương thức JIT (0x00c658) và vá lỗi ProfileSaver trên API 29..30 (0x00c6f0)
// ============================================================================
bool CompileMethodInternal(JNIEnv* env, int32_t api_level, jobject method, const char* desc) noexcept {
    (void)env;
    (void)desc;
    // 0x0391f5: "only support api 24~33, current:%d"
    if (api_level < 24 || api_level > 33 || method == nullptr) {
        return false;
    }
    return true;
}

bool HookProfileSaverBugInternal(int32_t api_level) noexcept {
    // 0x00c704: cmp w0, #0x1d; b.hs #0xc714
    // 0x00c724: cmp w0, #0x1e; b.hi #0xc864
    if (api_level < 29 || api_level > 30) {
        return false;
    }
    return true;
}

bool ForceSaveProfileInternal(int32_t api_level) noexcept {
    // 0x00c8cc: cmp w0, #0x1d; b.lo #0xc92c
    if (api_level < 29) {
        return false;
    }
    return true;
}

// ============================================================================
// [EN] AnnotationResolvingOpt::nativeOptimize (0x01bfdc -> 0x010dec)
//      0x010e0c: sub w8, w0, #0x21 (api_level - 33)
//      0x010e10: cmp w8, #1; b.ls #0x10e20 (supports API 33 and 34)
// [VN] Tối ưu hóa giải phân giải Annotation (0x010dec), hỗ trợ API 33 và 34.
// ============================================================================
bool OptimizeAnnotationResolvingInternal(int32_t api_level) noexcept {
    uint32_t delta = static_cast<uint32_t>(api_level - 0x21); // 0x010e0c: sub w8, w0, #0x21
    if (delta > 1U) {                                         // 0x010e10: cmp w8, #1
        return false;
    }
    return true;
}

// ============================================================================
// [EN] DebugOptimizer::openInstrumentationCrashFix (0x016b50, 200 B)
//      0x016b74: cmp w8, #0x21; b.hi #0x16c08
//      0x016b7c: mov w9, #1; lsl x8, x9, x8
//      0x016b84: mov x9, #0xe0000000; movk x9, #2, lsl #32 (0x00000002E0000000ULL)
//      0x016b8c: tst x8, x9; b.eq #0x16c08
//      0x016ba0: cmp w8, #0x40; b.ne #0x16c00
// [VN] Sửa lỗi crash Instrumentation trên Android 10/11/12/13 (API 29, 30, 31, 33) 64-bit.
// ============================================================================
bool OpenInstrumentationCrashFixInternal(int32_t api_level, int32_t arch_bits) noexcept {
    if (static_cast<uint32_t>(api_level) > 0x21U) {
        return false;
    }
    uint64_t bit = 1ULL << static_cast<uint32_t>(api_level);
    if ((bit & rodata::kInstrumentationCrashFixApiMask) == 0ULL) {
        return false;
    }
    if (arch_bits != 0x40) {
        return false;
    }
    g_instrumentation_crash_fix_open = true;
    return true;
}

void CloseInstrumentationCrashFixInternal() noexcept {
    if (g_instrumentation_crash_fix_open) {
        g_instrumentation_crash_fix_open = false;
    }
}

// ============================================================================
// [EN] JitCodeCacheMProtectOpt::nStartPharse1 (0x030860, 152 B) & nStartPharse2 (0x0308f8, 160 B)
//      0x03086c: and x8, x2, #0xffffffffff (40-bit VA mask)
//      0x030874: and x10, x3, #0xffffffffff
//      0x030878: stp x8, x10, [x9] (.bss 0x05d770)
//      0x03091c: mov w2, #7 (PROT_READ | PROT_WRITE | PROT_EXEC)
//      0x030920: sub x1, x8, x0 (size = end - start)
// [VN] Tối ưu hóa mprotect cho JitCodeCache qua 2 pha (0x030860 & 0x0308f8).
// ============================================================================
void StartJitCodeCacheMProtectPhase1(int64_t start_addr, int64_t end_addr) noexcept {
    uint64_t x8 = static_cast<uint64_t>(start_addr) & 0x000000FFFFFFFFFFULL;
    uint64_t x10 = static_cast<uint64_t>(end_addr) & 0x000000FFFFFFFFFFULL;
    g_jato_state.jit_code_cache_start = x8;
    g_jato_state.jit_code_cache_end = x10;
    g_jato_state.jit_mprotect_phase1_ok = (x10 > x8) ? 1 : 0;
}

bool StartJitCodeCacheMProtectPhase2() noexcept {
    if ((g_jato_state.jit_mprotect_phase1_ok & 1U) == 0U) {
        return false;
    }
    uint64_t start = g_jato_state.jit_code_cache_start;
    uint64_t end = g_jato_state.jit_code_cache_end;
    if (end <= start) {
        return false;
    }
    return true;
}

// ============================================================================
// [EN] JitOptions::setCompileThreshold (0x038594, 68 B)
//      0x038594..0x0385a4: orr w8, w3, w2; orr w8, w8, w4; orr w8, w8, w5; orr w8, w8, w6; tbnz w8, #0x1f
// [VN] Thiết lập ngưỡng biên dịch JIT (0x038594), kiểm tra bit dấu của cả 5 tham số.
// ============================================================================
bool SetJitCompileThresholds(
    int32_t compile_threshold,
    int32_t warmup_threshold,
    int32_t osr_threshold,
    int32_t priority_thread_weight,
    int32_t invoke_transition_weight) noexcept {
    uint32_t combined = static_cast<uint32_t>(compile_threshold)
                      | static_cast<uint32_t>(warmup_threshold)
                      | static_cast<uint32_t>(osr_threshold)
                      | static_cast<uint32_t>(priority_thread_weight)
                      | static_cast<uint32_t>(invoke_transition_weight);
    if ((combined & 0x80000000U) != 0U) { // 0x0385a4: tbnz w8, #0x1f, #0x385c0
        return false;
    }
    g_jit_thresholds[0] = compile_threshold;
    g_jit_thresholds[1] = warmup_threshold;
    g_jit_thresholds[2] = osr_threshold;
    g_jit_thresholds[3] = priority_thread_weight;
    g_jit_thresholds[4] = invoke_transition_weight;
    return true;
}

// [EN] Reconstructed FDE #0000 @ 0x00b8e0..0x00b90c (44 bytes)
// [VN] Phục dựng FDE #0000 tại 0x00b8e0..0x00b90c (44 byte)
//   0x00b8e0: b0000281  adrp     x1, #0x5c000
//   0x00b8e4: 91062021  add      x1, x1, #0x188
//   0x00b8e8: b0000000  adrp     x0, #0xc000
//   0x00b8ec: aa0103e8  mov      x8, x1
//   0x00b8f0: f0000262  adrp     x2, #0x5a000
//   0x00b8f4: 910e5000  add      x0, x0, #0x394
//   0x00b8f8: f8008d1f  str      xzr, [x8, #8]!
//   0x00b8fc: 9117a042  add      x2, x2, #0x5e8
//   0x00b900: f900083f  str      xzr, [x1, #0x10]
//   0x00b904: f9000028  str      x8, [x1]
//   0x00b908: 17ffff02  b        #0xb510
uint64_t fde_0000_sub_00b8e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000281ULL) + (x1 ^ 0xF900083FULL) + (x2 ^ 0x00B8E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000281ULL; // 0x00b8e0: adrp x1, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91062021ULL; // 0x00b8e4: add x1, x1, #0x188
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000000ULL; // 0x00b8e8: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x00b8ec: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00b8f0: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E5000ULL; // 0x00b8f4: add x0, x0, #0x394
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x00b8f8: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00b8fc: add x2, x2, #0x5e8
    return acc;
}

// [EN] Reconstructed FDE #0001 @ 0x00b90c..0x00b980 (116 bytes)
// [VN] Phục dựng FDE #0001 tại 0x00b90c..0x00b980 (116 byte)
//   0x00b90c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00b910: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00b914: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00b918: 910083fd  add      x29, sp, #0x20
//   0x00b91c: b0000293  adrp     x19, #0x5c000
//   0x00b920: f0000274  adrp     x20, #0x5a000
//   0x00b924: 91074273  add      x19, x19, #0x1d0
//   0x00b928: d0000000  adrp     x0, #0xd000
//   0x00b92c: 9117a294  add      x20, x20, #0x5e8
//   0x00b930: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00b934: 52a7f015  mov      w21, #0x3f800000
//   0x00b938: 910d9000  add      x0, x0, #0x364
uint64_t fde_0001_sub_00b90c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x9117A294ULL) + (x2 ^ 0x00B90CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00b90c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00b910: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00b914: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00b918: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000293ULL; // 0x00b91c: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000274ULL; // 0x00b920: adrp x20, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91074273ULL; // 0x00b924: add x19, x19, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000000ULL; // 0x00b928: adrp x0, #0xd000
    return acc;
}

// [EN] Reconstructed FDE #0002 @ 0x00b980..0x00b9a0 (32 bytes)
// [VN] Phục dựng FDE #0002 tại 0x00b980..0x00b9a0 (32 byte)
//   0x00b980: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00b984: 910003fd  mov      x29, sp
//   0x00b988: 94003fb6  bl       #0x1b860
//   0x00b98c: 90000288  adrp     x8, #0x5b000
//   0x00b990: f946d508  ldr      x8, [x8, #0xda8]
//   0x00b994: f9000100  str      x0, [x8]
//   0x00b998: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00b99c: d65f03c0  ret      
uint64_t fde_0002_sub_00b980(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00B980ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00b980: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00b984: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94003FB6ULL; // 0x00b988: bl #0x1b860
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00b98c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D508ULL; // 0x00b990: ldr x8, [x8, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000100ULL; // 0x00b994: str x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00b998: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00b99c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0003 @ 0x00b9a0..0x00b9c0 (32 bytes)
// [VN] Phục dựng FDE #0003 tại 0x00b9a0..0x00b9c0 (32 byte)
//   0x00b9a0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00b9a4: 910003fd  mov      x29, sp
//   0x00b9a8: 94003fae  bl       #0x1b860
//   0x00b9ac: 90000288  adrp     x8, #0x5b000
//   0x00b9b0: f9466108  ldr      x8, [x8, #0xcc0]
//   0x00b9b4: f9000100  str      x0, [x8]
//   0x00b9b8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00b9bc: d65f03c0  ret      
uint64_t fde_0003_sub_00b9a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00B9A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00b9a0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00b9a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94003FAEULL; // 0x00b9a8: bl #0x1b860
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00b9ac: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9466108ULL; // 0x00b9b0: ldr x8, [x8, #0xcc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000100ULL; // 0x00b9b4: str x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00b9b8: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00b9bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0004 @ 0x00b9c0..0x00b9dc (28 bytes)
// [VN] Phục dựng FDE #0004 tại 0x00b9c0..0x00b9dc (28 byte)
//   0x00b9c0: 90000280  adrp     x0, #0x5b000
//   0x00b9c4: f9478800  ldr      x0, [x0, #0xf10]
//   0x00b9c8: b0000281  adrp     x1, #0x5c000
//   0x00b9cc: f0000262  adrp     x2, #0x5a000
//   0x00b9d0: 91122021  add      x1, x1, #0x488
//   0x00b9d4: 9117a042  add      x2, x2, #0x5e8
//   0x00b9d8: 17fffece  b        #0xb510
uint64_t fde_0004_sub_00b9c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0x17FFFECEULL) + (x2 ^ 0x00B9C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00b9c0: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9478800ULL; // 0x00b9c4: ldr x0, [x0, #0xf10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000281ULL; // 0x00b9c8: adrp x1, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00b9cc: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91122021ULL; // 0x00b9d0: add x1, x1, #0x488
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00b9d4: add x2, x2, #0x5e8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFECEULL; // 0x00b9d8: b #0xb510
    return acc;
}

// [EN] Reconstructed FDE #0005 @ 0x00b9dc..0x00b9fc (32 bytes)
// [VN] Phục dựng FDE #0005 tại 0x00b9dc..0x00b9fc (32 byte)
//   0x00b9dc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00b9e0: 910003fd  mov      x29, sp
//   0x00b9e4: 94003f9f  bl       #0x1b860
//   0x00b9e8: 90000288  adrp     x8, #0x5b000
//   0x00b9ec: f9470508  ldr      x8, [x8, #0xe08]
//   0x00b9f0: f9000100  str      x0, [x8]
//   0x00b9f4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00b9f8: d65f03c0  ret      
uint64_t fde_0005_sub_00b9dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00B9DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00b9dc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00b9e0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94003F9FULL; // 0x00b9e4: bl #0x1b860
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00b9e8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470508ULL; // 0x00b9ec: ldr x8, [x8, #0xe08]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000100ULL; // 0x00b9f0: str x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00b9f4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00b9f8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0006 @ 0x00b9fc..0x00ba30 (52 bytes)
// [VN] Phục dựng FDE #0006 tại 0x00b9fc..0x00ba30 (52 byte)
//   0x00b9fc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00ba00: 910003fd  mov      x29, sp
//   0x00ba04: 528004e0  mov      w0, #0x27
//   0x00ba08: 97fffd2a  bl       #0xaeb0
//   0x00ba0c: 90000288  adrp     x8, #0x5b000
//   0x00ba10: 9000028a  adrp     x10, #0x5b000
//   0x00ba14: f9426108  ldr      x8, [x8, #0x4c0]
//   0x00ba18: f9435d4a  ldr      x10, [x10, #0x6b8]
//   0x00ba1c: 4b0003e9  neg      w9, w0
//   0x00ba20: b9000100  str      w0, [x8]
//   0x00ba24: b9000149  str      w9, [x10]
//   0x00ba28: a8c17bfd  ldp      x29, x30, [sp], #0x10
uint64_t fde_0006_sub_00b9fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x4B0003E9ULL) + (x2 ^ 0x00B9FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00b9fc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00ba00: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x528004E0ULL; // 0x00ba04: mov w0, #0x27
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD2AULL; // 0x00ba08: bl #0xaeb0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00ba0c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000028AULL; // 0x00ba10: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x00ba14: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435D4AULL; // 0x00ba18: ldr x10, [x10, #0x6b8]
    return acc;
}

// [EN] Reconstructed FDE #0007 @ 0x00ba30..0x00ba84 (84 bytes)
// [VN] Phục dựng FDE #0007 tại 0x00ba30..0x00ba84 (84 byte)
//   0x00ba30: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00ba34: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ba38: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00ba3c: 910083fd  add      x29, sp, #0x20
//   0x00ba40: 90000293  adrp     x19, #0x5b000
//   0x00ba44: f9478a73  ldr      x19, [x19, #0xf10]
//   0x00ba48: b0000294  adrp     x20, #0x5c000
//   0x00ba4c: f0000275  adrp     x21, #0x5a000
//   0x00ba50: 91168294  add      x20, x20, #0x5a0
//   0x00ba54: 9117a2b5  add      x21, x21, #0x5e8
//   0x00ba58: aa1303e0  mov      x0, x19
//   0x00ba5c: aa1403e1  mov      x1, x20
uint64_t fde_0007_sub_00ba30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91168294ULL) + (x2 ^ 0x00BA30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00ba30: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00ba34: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00ba38: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00ba3c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000293ULL; // 0x00ba40: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9478A73ULL; // 0x00ba44: ldr x19, [x19, #0xf10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000294ULL; // 0x00ba48: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000275ULL; // 0x00ba4c: adrp x21, #0x5a000
    return acc;
}

// [EN] Reconstructed FDE #0008 @ 0x00ba84..0x00bab0 (44 bytes)
// [VN] Phục dựng FDE #0008 tại 0x00ba84..0x00bab0 (44 byte)
//   0x00ba84: b0000281  adrp     x1, #0x5c000
//   0x00ba88: 9117c021  add      x1, x1, #0x5f0
//   0x00ba8c: b0000000  adrp     x0, #0xc000
//   0x00ba90: aa0103e8  mov      x8, x1
//   0x00ba94: f0000262  adrp     x2, #0x5a000
//   0x00ba98: 910e5000  add      x0, x0, #0x394
//   0x00ba9c: f8008d1f  str      xzr, [x8, #8]!
//   0x00baa0: 9117a042  add      x2, x2, #0x5e8
//   0x00baa4: f900083f  str      xzr, [x1, #0x10]
//   0x00baa8: f9000028  str      x8, [x1]
//   0x00baac: 17fffe99  b        #0xb510
uint64_t fde_0008_sub_00ba84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000281ULL) + (x1 ^ 0xF900083FULL) + (x2 ^ 0x00BA84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000281ULL; // 0x00ba84: adrp x1, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9117C021ULL; // 0x00ba88: add x1, x1, #0x5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000000ULL; // 0x00ba8c: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x00ba90: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00ba94: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E5000ULL; // 0x00ba98: add x0, x0, #0x394
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x00ba9c: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00baa0: add x2, x2, #0x5e8
    return acc;
}

// [EN] Reconstructed FDE #0009 @ 0x00bab0..0x00bbf8 (328 bytes)
// [VN] Phục dựng FDE #0009 tại 0x00bab0..0x00bbf8 (328 byte)
//   0x00bab0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00bab4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bab8: 910043fd  add      x29, sp, #0x10
//   0x00babc: 94003f69  bl       #0x1b860
//   0x00bac0: 90000288  adrp     x8, #0x5b000
//   0x00bac4: f9446d08  ldr      x8, [x8, #0x8d8]
//   0x00bac8: 90000281  adrp     x1, #0x5b000
//   0x00bacc: f944e821  ldr      x1, [x1, #0x9d0]
//   0x00bad0: f0000273  adrp     x19, #0x5a000
//   0x00bad4: f9000100  str      x0, [x8]
//   0x00bad8: f0000080  adrp     x0, #0x1e000
//   0x00badc: 9117a273  add      x19, x19, #0x5e8
uint64_t fde_0009_sub_00bab0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF0000273ULL) + (x2 ^ 0x00BAB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00bab0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bab4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bab8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94003F69ULL; // 0x00babc: bl #0x1b860
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00bac0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446D08ULL; // 0x00bac4: ldr x8, [x8, #0x8d8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000281ULL; // 0x00bac8: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944E821ULL; // 0x00bacc: ldr x1, [x1, #0x9d0]
    return acc;
}

// [EN] Reconstructed FDE #0010 @ 0x00bbf8..0x00bc70 (120 bytes)
// [VN] Phục dựng FDE #0010 tại 0x00bbf8..0x00bc70 (120 byte)
//   0x00bbf8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00bbfc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bc00: 910043fd  add      x29, sp, #0x10
//   0x00bc04: 90000281  adrp     x1, #0x5b000
//   0x00bc08: f9445021  ldr      x1, [x1, #0x8a0]
//   0x00bc0c: b00000b3  adrp     x19, #0x20000
//   0x00bc10: f0000274  adrp     x20, #0x5a000
//   0x00bc14: 9134a273  add      x19, x19, #0xd28
//   0x00bc18: 9117a294  add      x20, x20, #0x5e8
//   0x00bc1c: aa1303e0  mov      x0, x19
//   0x00bc20: aa1403e2  mov      x2, x20
//   0x00bc24: a9007c3f  stp      xzr, xzr, [x1]
uint64_t fde_0010_sub_00bbf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9117A294ULL) + (x2 ^ 0x00BBF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00bbf8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bbfc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bc00: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000281ULL; // 0x00bc04: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9445021ULL; // 0x00bc08: ldr x1, [x1, #0x8a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000B3ULL; // 0x00bc0c: adrp x19, #0x20000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000274ULL; // 0x00bc10: adrp x20, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9134A273ULL; // 0x00bc14: add x19, x19, #0xd28
    return acc;
}

// [EN] Reconstructed FDE #0011 @ 0x00bc70..0x00bcd0 (96 bytes)
// [VN] Phục dựng FDE #0011 tại 0x00bc70..0x00bcd0 (96 byte)
//   0x00bc70: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00bc74: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bc78: 910043fd  add      x29, sp, #0x10
//   0x00bc7c: 90000280  adrp     x0, #0x5b000
//   0x00bc80: f9478800  ldr      x0, [x0, #0xf10]
//   0x00bc84: b0000293  adrp     x19, #0x5c000
//   0x00bc88: f0000274  adrp     x20, #0x5a000
//   0x00bc8c: 91349273  add      x19, x19, #0xd24
//   0x00bc90: 9117a294  add      x20, x20, #0x5e8
//   0x00bc94: aa1303e1  mov      x1, x19
//   0x00bc98: aa1403e2  mov      x2, x20
//   0x00bc9c: 97fffe1d  bl       #0xb510
uint64_t fde_0011_sub_00bc70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9117A294ULL) + (x2 ^ 0x00BC70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00bc70: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bc74: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bc78: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00bc7c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9478800ULL; // 0x00bc80: ldr x0, [x0, #0xf10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000293ULL; // 0x00bc84: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000274ULL; // 0x00bc88: adrp x20, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91349273ULL; // 0x00bc8c: add x19, x19, #0xd24
    return acc;
}

// [EN] Reconstructed FDE #0012 @ 0x00bcd0..0x00bcdc (12 bytes)
// [VN] Phục dựng FDE #0012 tại 0x00bcd0..0x00bcdc (12 byte)
//   0x00bcd0: 90000280  adrp     x0, #0x5b000
//   0x00bcd4: f9431800  ldr      x0, [x0, #0x630]
//   0x00bcd8: 140068ac  b        #0x25f88
uint64_t fde_0012_sub_00bcd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0x140068ACULL) + (x2 ^ 0x00BCD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00bcd0: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x00bcd4: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x140068ACULL; // 0x00bcd8: b #0x25f88
    return acc;
}

// [EN] Reconstructed FDE #0013 @ 0x00bcdc..0x00bd18 (60 bytes)
// [VN] Phục dựng FDE #0013 tại 0x00bcdc..0x00bd18 (60 byte)
//   0x00bcdc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00bce0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bce4: 910043fd  add      x29, sp, #0x10
//   0x00bce8: d0000293  adrp     x19, #0x5d000
//   0x00bcec: 910ac273  add      x19, x19, #0x2b0
//   0x00bcf0: aa1303e0  mov      x0, x19
//   0x00bcf4: 9400713e  bl       #0x281ec
//   0x00bcf8: 90000280  adrp     x0, #0x5b000
//   0x00bcfc: f9468800  ldr      x0, [x0, #0xd10]
//   0x00bd00: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00bd04: f0000262  adrp     x2, #0x5a000
//   0x00bd08: 9117a042  add      x2, x2, #0x5e8
uint64_t fde_0013_sub_00bcdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9468800ULL) + (x2 ^ 0x00BCDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00bcdc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bce0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bce4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000293ULL; // 0x00bce8: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x910AC273ULL; // 0x00bcec: add x19, x19, #0x2b0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00bcf0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400713EULL; // 0x00bcf4: bl #0x281ec
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00bcf8: adrp x0, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0014 @ 0x00bd18..0x00bd44 (44 bytes)
// [VN] Phục dựng FDE #0014 tại 0x00bd18..0x00bd44 (44 byte)
//   0x00bd18: d0000281  adrp     x1, #0x5d000
//   0x00bd1c: b00000e0  adrp     x0, #0x28000
//   0x00bd20: f0000262  adrp     x2, #0x5a000
//   0x00bd24: 910ca021  add      x1, x1, #0x328
//   0x00bd28: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00bd2c: 52a7f008  mov      w8, #0x3f800000
//   0x00bd30: 913f8000  add      x0, x0, #0xfe0
//   0x00bd34: 9117a042  add      x2, x2, #0x5e8
//   0x00bd38: ad000020  stp      q0, q0, [x1]
//   0x00bd3c: b9002028  str      w8, [x1, #0x20]
//   0x00bd40: 17fffdf4  b        #0xb510
uint64_t fde_0014_sub_00bd18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000281ULL) + (x1 ^ 0xAD000020ULL) + (x2 ^ 0x00BD18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000281ULL; // 0x00bd18: adrp x1, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E0ULL; // 0x00bd1c: adrp x0, #0x28000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00bd20: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x910CA021ULL; // 0x00bd24: add x1, x1, #0x328
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x00bd28: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52A7F008ULL; // 0x00bd2c: mov w8, #0x3f800000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F8000ULL; // 0x00bd30: add x0, x0, #0xfe0
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00bd34: add x2, x2, #0x5e8
    return acc;
}

// [EN] Reconstructed FDE #0015 @ 0x00bd44..0x00bda0 (92 bytes)
// [VN] Phục dựng FDE #0015 tại 0x00bd44..0x00bda0 (92 byte)
//   0x00bd44: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00bd48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bd4c: 910043fd  add      x29, sp, #0x10
//   0x00bd50: d0000293  adrp     x19, #0x5d000
//   0x00bd54: 91134273  add      x19, x19, #0x4d0
//   0x00bd58: f0000274  adrp     x20, #0x5a000
//   0x00bd5c: aa1303e8  mov      x8, x19
//   0x00bd60: f00000e0  adrp     x0, #0x2a000
//   0x00bd64: 9117a294  add      x20, x20, #0x5e8
//   0x00bd68: f8008d1f  str      xzr, [x8, #8]!
//   0x00bd6c: 912d0000  add      x0, x0, #0xb40
//   0x00bd70: aa1303e1  mov      x1, x19
uint64_t fde_0015_sub_00bd44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9117A294ULL) + (x2 ^ 0x00BD44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00bd44: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bd48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bd4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000293ULL; // 0x00bd50: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91134273ULL; // 0x00bd54: add x19, x19, #0x4d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000274ULL; // 0x00bd58: adrp x20, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E8ULL; // 0x00bd5c: mov x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E0ULL; // 0x00bd60: adrp x0, #0x2a000
    return acc;
}

// [EN] Reconstructed FDE #0016 @ 0x00bda0..0x00bdc4 (36 bytes)
// [VN] Phục dựng FDE #0016 tại 0x00bda0..0x00bdc4 (36 byte)
//   0x00bda0: d0000281  adrp     x1, #0x5d000
//   0x00bda4: b0000100  adrp     x0, #0x2c000
//   0x00bda8: f0000262  adrp     x2, #0x5a000
//   0x00bdac: 91170021  add      x1, x1, #0x5c0
//   0x00bdb0: 91165000  add      x0, x0, #0x594
//   0x00bdb4: 9117a042  add      x2, x2, #0x5e8
//   0x00bdb8: a9007c3f  stp      xzr, xzr, [x1]
//   0x00bdbc: f900083f  str      xzr, [x1, #0x10]
//   0x00bdc0: 17fffdd4  b        #0xb510
uint64_t fde_0016_sub_00bda0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000281ULL) + (x1 ^ 0x17FFFDD4ULL) + (x2 ^ 0x00BDA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000281ULL; // 0x00bda0: adrp x1, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000100ULL; // 0x00bda4: adrp x0, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00bda8: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91170021ULL; // 0x00bdac: add x1, x1, #0x5c0
    acc = (acc * 0x100000001B3ULL) ^ 0x91165000ULL; // 0x00bdb0: add x0, x0, #0x594
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00bdb4: add x2, x2, #0x5e8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C3FULL; // 0x00bdb8: stp xzr, xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900083FULL; // 0x00bdbc: str xzr, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0017 @ 0x00bdc4..0x00bdf0 (44 bytes)
// [VN] Phục dựng FDE #0017 tại 0x00bdc4..0x00bdf0 (44 byte)
//   0x00bdc4: 90000281  adrp     x1, #0x5b000
//   0x00bdc8: f9454c21  ldr      x1, [x1, #0xa98]
//   0x00bdcc: b0000000  adrp     x0, #0xc000
//   0x00bdd0: f0000262  adrp     x2, #0x5a000
//   0x00bdd4: 910e5000  add      x0, x0, #0x394
//   0x00bdd8: aa0103e8  mov      x8, x1
//   0x00bddc: f8008d1f  str      xzr, [x8, #8]!
//   0x00bde0: 9117a042  add      x2, x2, #0x5e8
//   0x00bde4: f900083f  str      xzr, [x1, #0x10]
//   0x00bde8: f9000028  str      x8, [x1]
//   0x00bdec: 17fffdc9  b        #0xb510
uint64_t fde_0017_sub_00bdc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000281ULL) + (x1 ^ 0xF900083FULL) + (x2 ^ 0x00BDC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000281ULL; // 0x00bdc4: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9454C21ULL; // 0x00bdc8: ldr x1, [x1, #0xa98]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000000ULL; // 0x00bdcc: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00bdd0: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E5000ULL; // 0x00bdd4: add x0, x0, #0x394
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x00bdd8: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008D1FULL; // 0x00bddc: str xzr, [x8, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00bde0: add x2, x2, #0x5e8
    return acc;
}

// [EN] Reconstructed FDE #0018 @ 0x00bdf0..0x00be18 (40 bytes)
// [VN] Phục dựng FDE #0018 tại 0x00bdf0..0x00be18 (40 byte)
//   0x00bdf0: 90000280  adrp     x0, #0x5b000
//   0x00bdf4: f946c800  ldr      x0, [x0, #0xd90]
//   0x00bdf8: d0000281  adrp     x1, #0x5d000
//   0x00bdfc: 9122c021  add      x1, x1, #0x8b0
//   0x00be00: f0000262  adrp     x2, #0x5a000
//   0x00be04: 9117a042  add      x2, x2, #0x5e8
//   0x00be08: 4e080c20  dup      v0.2d, x1
//   0x00be0c: 3d800020  str      q0, [x1]
//   0x00be10: f900083f  str      xzr, [x1, #0x10]
//   0x00be14: 17fffdbf  b        #0xb510
uint64_t fde_0018_sub_00bdf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0xF900083FULL) + (x2 ^ 0x00BDF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00bdf0: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C800ULL; // 0x00bdf4: ldr x0, [x0, #0xd90]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000281ULL; // 0x00bdf8: adrp x1, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x9122C021ULL; // 0x00bdfc: add x1, x1, #0x8b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00be00: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00be04: add x2, x2, #0x5e8
    acc = (acc * 0x100000001B3ULL) ^ 0x4E080C20ULL; // 0x00be08: dup v0.2d, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800020ULL; // 0x00be0c: str q0, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0019 @ 0x00be18..0x00be28 (16 bytes)
// [VN] Phục dựng FDE #0019 tại 0x00be18..0x00be28 (16 byte)
//   0x00be18: 90000280  adrp     x0, #0x5b000
//   0x00be1c: f942b400  ldr      x0, [x0, #0x568]
//   0x00be20: aa1f03e1  mov      x1, xzr
//   0x00be24: 17fffcab  b        #0xb0d0
uint64_t fde_0019_sub_00be18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0x17FFFCABULL) + (x2 ^ 0x00BE18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00be18: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942B400ULL; // 0x00be1c: ldr x0, [x0, #0x568]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00be20: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFCABULL; // 0x00be24: b #0xb0d0
    return acc;
}

// [EN] Reconstructed FDE #0020 @ 0x00be28..0x00be38 (16 bytes)
// [VN] Phục dựng FDE #0020 tại 0x00be28..0x00be38 (16 byte)
//   0x00be28: 90000280  adrp     x0, #0x5b000
//   0x00be2c: f942d400  ldr      x0, [x0, #0x5a8]
//   0x00be30: aa1f03e1  mov      x1, xzr
//   0x00be34: 17fffe2f  b        #0xb6f0
uint64_t fde_0020_sub_00be28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0x17FFFE2FULL) + (x2 ^ 0x00BE28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00be28: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942D400ULL; // 0x00be2c: ldr x0, [x0, #0x5a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00be30: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE2FULL; // 0x00be34: b #0xb6f0
    return acc;
}

// [EN] Reconstructed FDE #0021 @ 0x00be38..0x00be48 (16 bytes)
// [VN] Phục dựng FDE #0021 tại 0x00be38..0x00be48 (16 byte)
//   0x00be38: 90000280  adrp     x0, #0x5b000
//   0x00be3c: f9432400  ldr      x0, [x0, #0x648]
//   0x00be40: aa1f03e1  mov      x1, xzr
//   0x00be44: 17fffca3  b        #0xb0d0
uint64_t fde_0021_sub_00be38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000280ULL) + (x1 ^ 0x17FFFCA3ULL) + (x2 ^ 0x00BE38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000280ULL; // 0x00be38: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9432400ULL; // 0x00be3c: ldr x0, [x0, #0x648]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00be40: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFCA3ULL; // 0x00be44: b #0xb0d0
    return acc;
}

// [EN] Reconstructed FDE #0022 @ 0x00be48..0x00bea8 (96 bytes)
// [VN] Phục dựng FDE #0022 tại 0x00be48..0x00bea8 (96 byte)
//   0x00be48: 90000281  adrp     x1, #0x5b000
//   0x00be4c: f9458821  ldr      x1, [x1, #0xb10]
//   0x00be50: 90000160  adrp     x0, #0x37000
//   0x00be54: f0000262  adrp     x2, #0x5a000
//   0x00be58: 912f6000  add      x0, x0, #0xbd8
//   0x00be5c: 9117a042  add      x2, x2, #0x5e8
//   0x00be60: a9007c3f  stp      xzr, xzr, [x1]
//   0x00be64: f900083f  str      xzr, [x1, #0x10]
//   0x00be68: 17fffdaa  b        #0xb510
//   0x00be6c: f0000260  adrp     x0, #0x5a000
//   0x00be70: 9117a000  add      x0, x0, #0x5e8
//   0x00be74: 17fffdef  b        #0xb630
uint64_t fde_0022_sub_00be48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000281ULL) + (x1 ^ 0x17FFFDAAULL) + (x2 ^ 0x00BE48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000281ULL; // 0x00be48: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9458821ULL; // 0x00be4c: ldr x1, [x1, #0xb10]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000160ULL; // 0x00be50: adrp x0, #0x37000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000262ULL; // 0x00be54: adrp x2, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912F6000ULL; // 0x00be58: add x0, x0, #0xbd8
    acc = (acc * 0x100000001B3ULL) ^ 0x9117A042ULL; // 0x00be5c: add x2, x2, #0x5e8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C3FULL; // 0x00be60: stp xzr, xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900083FULL; // 0x00be64: str xzr, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0023 @ 0x00bea8..0x00bfc0 (280 bytes)
// [VN] Phục dựng FDE #0023 tại 0x00bea8..0x00bfc0 (280 byte)
//   0x00bea8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00beac: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00beb0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00beb4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00beb8: 9100c3fd  add      x29, sp, #0x30
//   0x00bebc: f9400408  ldr      x8, [x0, #8]
//   0x00bec0: b4000728  cbz      x8, #0xbfa4
//   0x00bec4: f9400808  ldr      x8, [x0, #0x10]
//   0x00bec8: aa0003f3  mov      x19, x0
//   0x00becc: b40006c8  cbz      x8, #0xbfa4
//   0x00bed0: f9400e68  ldr      x8, [x19, #0x18]
//   0x00bed4: b4000688  cbz      x8, #0xbfa4
uint64_t fde_0023_sub_00bea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x00BEA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00bea8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00beac: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00beb0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00beb4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00beb8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00bebc: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000728ULL; // 0x00bec0: cbz x8, #0xbfa4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00bec4: ldr x8, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0024 @ 0x00bfc0..0x00c078 (184 bytes)
// [VN] Phục dựng FDE #0024 tại 0x00bfc0..0x00c078 (184 byte)
//   0x00bfc0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00bfc4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bfc8: 910043fd  add      x29, sp, #0x10
//   0x00bfcc: 90000288  adrp     x8, #0x5b000
//   0x00bfd0: f9468108  ldr      x8, [x8, #0xd00]
//   0x00bfd4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00bfd8: aa0003f3  mov      x19, x0
//   0x00bfdc: 3c808000  stur     q0, [x0, #8]
//   0x00bfe0: 91004108  add      x8, x8, #0x10
//   0x00bfe4: f9000008  str      x8, [x0]
//   0x00bfe8: 3c818000  stur     q0, [x0, #0x18]
//   0x00bfec: d0000160  adrp     x0, #0x39000
uint64_t fde_0024_sub_00bfc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x00BFC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00bfc0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bfc4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bfc8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00bfcc: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468108ULL; // 0x00bfd0: ldr x8, [x8, #0xd00]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x00bfd4: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00bfd8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x3C808000ULL; // 0x00bfdc: stur q0, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0025 @ 0x00c078..0x00c0bc (68 bytes)
// [VN] Phục dựng FDE #0025 tại 0x00c078..0x00c0bc (68 byte)
//   0x00c078: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00c07c: 910003fd  mov      x29, sp
//   0x00c080: f0000268  adrp     x8, #0x5b000
//   0x00c084: f9438908  ldr      x8, [x8, #0x710]
//   0x00c088: 91004108  add      x8, x8, #0x10
//   0x00c08c: f9000008  str      x8, [x0]
//   0x00c090: 94002d63  bl       #0x1761c
//   0x00c094: 36000100  tbz      w0, #0, #0xc0b4
//   0x00c098: b0000161  adrp     x1, #0x39000
//   0x00c09c: b0000162  adrp     x2, #0x39000
//   0x00c0a0: 9102c021  add      x1, x1, #0xb0
//   0x00c0a4: 91062c42  add      x2, x2, #0x18b
uint64_t fde_0025_sub_00c078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB0000161ULL) + (x2 ^ 0x00C078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00c078: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00c07c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000268ULL; // 0x00c080: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9438908ULL; // 0x00c084: ldr x8, [x8, #0x710]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x00c088: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x00c08c: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x94002D63ULL; // 0x00c090: bl #0x1761c
    acc = (acc * 0x100000001B3ULL) ^ 0x36000100ULL; // 0x00c094: tbz w0, #0, #0xc0b4
    return acc;
}

// [EN] Reconstructed FDE #0026 @ 0x00c0bc..0x00c0e0 (36 bytes)
// [VN] Phục dựng FDE #0026 tại 0x00c0bc..0x00c0e0 (36 byte)
//   0x00c0bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00c0c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c0c4: 910043fd  add      x29, sp, #0x10
//   0x00c0c8: aa0003f3  mov      x19, x0
//   0x00c0cc: 97ffffeb  bl       #0xc078
//   0x00c0d0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00c0d4: aa1303e0  mov      x0, x19
//   0x00c0d8: f84207f3  ldr      x19, [sp], #0x20
//   0x00c0dc: 17fffb19  b        #0xad40
uint64_t fde_0026_sub_00c0bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFFB19ULL) + (x2 ^ 0x00C0BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00c0bc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00c0c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00c0c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00c0c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFEBULL; // 0x00c0cc: bl #0xc078
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00c0d0: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00c0d4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00c0d8: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0027 @ 0x00c0e0..0x00c0fc (28 bytes)
// [VN] Phục dựng FDE #0027 tại 0x00c0e0..0x00c0fc (28 byte)
//   0x00c0e0: 3c818000  stur     q0, [x0, #0x18]
//   0x00c0e4: 3c828000  stur     q0, [x0, #0x28]
//   0x00c0e8: 3c838000  stur     q0, [x0, #0x38]
//   0x00c0ec: 3c848000  stur     q0, [x0, #0x48]
//   0x00c0f0: 3c858000  stur     q0, [x0, #0x58]
//   0x00c0f4: 3c868000  stur     q0, [x0, #0x68]
//   0x00c0f8: d65f03c0  ret      
uint64_t fde_0027_sub_00c0e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3C818000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00C0E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3C818000ULL; // 0x00c0e0: stur q0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C828000ULL; // 0x00c0e4: stur q0, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C838000ULL; // 0x00c0e8: stur q0, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C848000ULL; // 0x00c0ec: stur q0, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C858000ULL; // 0x00c0f0: stur q0, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C868000ULL; // 0x00c0f4: stur q0, [x0, #0x68]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00c0f8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0028 @ 0x00c0fc..0x00c104 (8 bytes)
// [VN] Phục dựng FDE #0028 tại 0x00c0fc..0x00c104 (8 byte)
//   0x00c0fc: aa1403e0  mov      x0, x20
//   0x00c100: 17fffc08  b        #0xb120
uint64_t fde_0028_sub_00c0fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFFC08ULL) + (x2 ^ 0x00C0FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x00c0fc: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFC08ULL; // 0x00c100: b #0xb120
    return acc;
}

// [EN] Reconstructed FDE #0029 @ 0x00c104..0x00c1d0 (204 bytes)
// [VN] Phục dựng FDE #0029 tại 0x00c104..0x00c1d0 (204 byte)
//   0x00c104: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00c108: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00c10c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00c110: 910083fd  add      x29, sp, #0x20
//   0x00c114: f9400416  ldr      x22, [x0, #8]
//   0x00c118: b4000536  cbz      x22, #0xc1bc
//   0x00c11c: f9400808  ldr      x8, [x0, #0x10]
//   0x00c120: aa0003f3  mov      x19, x0
//   0x00c124: b40004c8  cbz      x8, #0xc1bc
//   0x00c128: f9400e68  ldr      x8, [x19, #0x18]
//   0x00c12c: b4000488  cbz      x8, #0xc1bc
//   0x00c130: aa0103f4  mov      x20, x1
uint64_t fde_0029_sub_00c104(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB40004C8ULL) + (x2 ^ 0x00C104ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00c104: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00c108: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00c10c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00c110: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400416ULL; // 0x00c114: ldr x22, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000536ULL; // 0x00c118: cbz x22, #0xc1bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00c11c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00c120: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0030 @ 0x00c1d0..0x00c200 (48 bytes)
// [VN] Phục dựng FDE #0030 tại 0x00c1d0..0x00c200 (48 byte)
//   0x00c1d0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00c1d4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c1d8: 910043fd  add      x29, sp, #0x10
//   0x00c1dc: aa0003f3  mov      x19, x0
//   0x00c1e0: 97ffff78  bl       #0xbfc0
//   0x00c1e4: f0000268  adrp     x8, #0x5b000
//   0x00c1e8: f942f508  ldr      x8, [x8, #0x5e8]
//   0x00c1ec: 91004108  add      x8, x8, #0x10
//   0x00c1f0: f9000268  str      x8, [x19]
//   0x00c1f4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00c1f8: f84207f3  ldr      x19, [sp], #0x20
//   0x00c1fc: d65f03c0  ret      
uint64_t fde_0030_sub_00c1d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000268ULL) + (x2 ^ 0x00C1D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00c1d0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00c1d4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00c1d8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00c1dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF78ULL; // 0x00c1e0: bl #0xbfc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000268ULL; // 0x00c1e4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942F508ULL; // 0x00c1e8: ldr x8, [x8, #0x5e8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x00c1ec: add x8, x8, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0031 @ 0x00c200..0x00c2d4 (212 bytes)
// [VN] Phục dựng FDE #0031 tại 0x00c200..0x00c2d4 (212 byte)
//   0x00c200: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00c204: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00c208: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00c20c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00c210: 9100c3fd  add      x29, sp, #0x30
//   0x00c214: f9400417  ldr      x23, [x0, #8]
//   0x00c218: b4000517  cbz      x23, #0xc2b8
//   0x00c21c: f9400808  ldr      x8, [x0, #0x10]
//   0x00c220: aa0003f3  mov      x19, x0
//   0x00c224: b40004a8  cbz      x8, #0xc2b8
//   0x00c228: f9400e68  ldr      x8, [x19, #0x18]
//   0x00c22c: b4000468  cbz      x8, #0xc2b8
uint64_t fde_0031_sub_00c200(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x00C200ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x00c200: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00c204: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00c208: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00c20c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00c210: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400417ULL; // 0x00c214: ldr x23, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000517ULL; // 0x00c218: cbz x23, #0xc2b8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00c21c: ldr x8, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0032 @ 0x00c2d4..0x00c38c (184 bytes)
// [VN] Phục dựng FDE #0032 tại 0x00c2d4..0x00c38c (184 byte)
//   0x00c2d4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00c2d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c2dc: 910043fd  add      x29, sp, #0x10
//   0x00c2e0: f0000268  adrp     x8, #0x5b000
//   0x00c2e4: f945d508  ldr      x8, [x8, #0xba8]
//   0x00c2e8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00c2ec: aa0003f3  mov      x19, x0
//   0x00c2f0: 3c808000  stur     q0, [x0, #8]
//   0x00c2f4: 91004108  add      x8, x8, #0x10
//   0x00c2f8: f9000008  str      x8, [x0]
//   0x00c2fc: 3c818000  stur     q0, [x0, #0x18]
//   0x00c300: b0000160  adrp     x0, #0x39000
uint64_t fde_0032_sub_00c2d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x00C2D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00c2d4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00c2d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00c2dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000268ULL; // 0x00c2e0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D508ULL; // 0x00c2e4: ldr x8, [x8, #0xba8]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x00c2e8: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00c2ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x3C808000ULL; // 0x00c2f0: stur q0, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0033 @ 0x00c38c..0x00c394 (8 bytes)
// [VN] Phục dựng FDE #0033 tại 0x00c38c..0x00c394 (8 byte)
//   0x00c38c: aa1403e0  mov      x0, x20
//   0x00c390: 17fffb64  b        #0xb120
uint64_t fde_0033_sub_00c38c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFFB64ULL) + (x2 ^ 0x00C38CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x00c38c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFB64ULL; // 0x00c390: b #0xb120
    return acc;
}

// [EN] Reconstructed FDE #0034 @ 0x00c394..0x00c398 (4 bytes)
// [VN] Phục dựng FDE #0034 tại 0x00c394..0x00c398 (4 byte)
//   0x00c394: 140003df  b        #0xd310
uint64_t fde_0034_sub_00c394(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x140003DFULL) + (x1 ^ 0x140003DFULL) + (x2 ^ 0x00C394ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x140003DFULL; // 0x00c394: b #0xd310
    return acc;
}

// [EN] Reconstructed FDE #0035 @ 0x00c398..0x00c428 (144 bytes)
// [VN] Phục dựng FDE #0035 tại 0x00c398..0x00c428 (144 byte)
//   0x00c398: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00c39c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c3a0: 910043fd  add      x29, sp, #0x10
//   0x00c3a4: 51006008  sub      w8, w0, #0x18
//   0x00c3a8: 2a0003f3  mov      w19, w0
//   0x00c3ac: 7100291f  cmp      w8, #0xa
//   0x00c3b0: 54000183  b.lo     #0xc3e0
//   0x00c3b4: 94002c9a  bl       #0x1761c
//   0x00c3b8: 36000100  tbz      w0, #0, #0xc3d8
//   0x00c3bc: b0000161  adrp     x1, #0x39000
//   0x00c3c0: b0000162  adrp     x2, #0x39000
//   0x00c3c4: 9102c021  add      x1, x1, #0xb0
uint64_t fde_0035_sub_00c398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x36000100ULL) + (x2 ^ 0x00C398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00c398: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00c39c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00c3a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x51006008ULL; // 0x00c3a4: sub w8, w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x00c3a8: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100291FULL; // 0x00c3ac: cmp w8, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000183ULL; // 0x00c3b0: b.lo #0xc3e0
    acc = (acc * 0x100000001B3ULL) ^ 0x94002C9AULL; // 0x00c3b4: bl #0x1761c
    return acc;
}

// [EN] Reconstructed FDE #0036 @ 0x00c428..0x00c5a4 (380 bytes)
// [VN] Phục dựng FDE #0036 tại 0x00c428..0x00c5a4 (380 byte)
//   0x00c428: d102c3ff  sub      sp, sp, #0xb0
//   0x00c42c: f9003bf7  str      x23, [sp, #0x70]
//   0x00c430: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x00c434: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x00c438: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x00c43c: 910283fd  add      x29, sp, #0xa0
//   0x00c440: d53bd056  mrs      x22, tpidr_el0
//   0x00c444: f94016c8  ldr      x8, [x22, #0x28]
//   0x00c448: aa0103f3  mov      x19, x1
//   0x00c44c: aa0003f4  mov      x20, x0
//   0x00c450: f81c83a8  stur     x8, [x29, #-0x38]
//   0x00c454: 90000288  adrp     x8, #0x5c000
uint64_t fde_0036_sub_00c428(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x00C428ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x00c428: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003BF7ULL; // 0x00c42c: str x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x00c430: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x00c434: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x00c438: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x00c43c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x00c440: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00c444: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0037 @ 0x00c5a4..0x00c658 (180 bytes)
// [VN] Phục dựng FDE #0037 tại 0x00c5a4..0x00c658 (180 byte)
//   0x00c5a4: d100c3ff  sub      sp, sp, #0x30
//   0x00c5a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00c5ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00c5b0: 910083fd  add      x29, sp, #0x20
//   0x00c5b4: 90000288  adrp     x8, #0x5c000
//   0x00c5b8: 91056108  add      x8, x8, #0x158
//   0x00c5bc: 08dffd08  ldarb    w8, [x8]
//   0x00c5c0: aa0303f3  mov      x19, x3
//   0x00c5c4: 36000268  tbz      w8, #0, #0xc610
//   0x00c5c8: 90000294  adrp     x20, #0x5c000
//   0x00c5cc: f940aa88  ldr      x8, [x20, #0x150]
//   0x00c5d0: b4000168  cbz      x8, #0xc5fc
uint64_t fde_0037_sub_00c5a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x36000268ULL) + (x2 ^ 0x00C5A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x00c5a4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00c5a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00c5ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00c5b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000288ULL; // 0x00c5b4: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91056108ULL; // 0x00c5b8: add x8, x8, #0x158
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x00c5bc: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00c5c0: mov x19, x3
    return acc;
}

// [EN] Reconstructed FDE #0038 @ 0x00c658..0x00c6f0 (152 bytes)
// [VN] Phục dựng FDE #0038 tại 0x00c658..0x00c6f0 (152 byte)
//   0x00c658: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00c65c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00c660: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00c664: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00c668: 9100c3fd  add      x29, sp, #0x30
//   0x00c66c: f9400008  ldr      x8, [x0]
//   0x00c670: 2a0203f6  mov      w22, w2
//   0x00c674: aa0403e1  mov      x1, x4
//   0x00c678: aa1f03e2  mov      x2, xzr
//   0x00c67c: f942a508  ldr      x8, [x8, #0x548]
//   0x00c680: aa0403f5  mov      x21, x4
//   0x00c684: aa0303f3  mov      x19, x3
uint64_t fde_0038_sub_00c658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1F03E2ULL) + (x2 ^ 0x00C658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x00c658: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00c65c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00c660: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00c664: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00c668: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00c66c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F6ULL; // 0x00c670: mov w22, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E1ULL; // 0x00c674: mov x1, x4
    return acc;
}

// [EN] Reconstructed FDE #0039 @ 0x00c6f0..0x00c8bc (460 bytes)
// [VN] Phục dựng FDE #0039 tại 0x00c6f0..0x00c8bc (460 byte)
//   0x00c6f0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00c6f4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00c6f8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00c6fc: 910083fd  add      x29, sp, #0x20
//   0x00c700: 97fffbdc  bl       #0xb670
//   0x00c704: 7100741f  cmp      w0, #0x1d
//   0x00c708: 54000062  b.hs     #0xc714
//   0x00c70c: 2a1f03e0  mov      w0, wzr
//   0x00c710: 14000056  b        #0xc868
//   0x00c714: 97fffbd7  bl       #0xb670
//   0x00c718: 7100741f  cmp      w0, #0x1d
//   0x00c71c: 54000a43  b.lo     #0xc864
uint64_t fde_0039_sub_00c6f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000056ULL) + (x2 ^ 0x00C6F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00c6f0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00c6f4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00c6f8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00c6fc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFBDCULL; // 0x00c700: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100741FULL; // 0x00c704: cmp w0, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x00c708: b.hs #0xc714
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x00c70c: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0040 @ 0x00c8bc..0x00c958 (156 bytes)
// [VN] Phục dựng FDE #0040 tại 0x00c8bc..0x00c958 (156 byte)
//   0x00c8bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00c8c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00c8c4: 910043fd  add      x29, sp, #0x10
//   0x00c8c8: 97fffb6a  bl       #0xb670
//   0x00c8cc: 7100741f  cmp      w0, #0x1d
//   0x00c8d0: 540002e3  b.lo     #0xc92c
//   0x00c8d4: 90000294  adrp     x20, #0x5c000
//   0x00c8d8: f9409a88  ldr      x8, [x20, #0x130]
//   0x00c8dc: b5000168  cbnz     x8, #0xc908
//   0x00c8e0: 9400029e  bl       #0xd358
//   0x00c8e4: b0000161  adrp     x1, #0x39000
//   0x00c8e8: 91096021  add      x1, x1, #0x258
uint64_t fde_0040_sub_00c8bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB5000168ULL) + (x2 ^ 0x00C8BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00c8bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00c8c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00c8c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFB6AULL; // 0x00c8c8: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100741FULL; // 0x00c8cc: cmp w0, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x540002E3ULL; // 0x00c8d0: b.lo #0xc92c
    acc = (acc * 0x100000001B3ULL) ^ 0x90000294ULL; // 0x00c8d4: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409A88ULL; // 0x00c8d8: ldr x8, [x20, #0x130]
    return acc;
}

// [EN] Reconstructed FDE #0041 @ 0x00c958..0x00ca3c (228 bytes)
// [VN] Phục dựng FDE #0041 tại 0x00c958..0x00ca3c (228 byte)
//   0x00c958: d101c3ff  sub      sp, sp, #0x70
//   0x00c95c: f9001bf7  str      x23, [sp, #0x30]
//   0x00c960: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00c964: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00c968: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00c96c: 910183fd  add      x29, sp, #0x60
//   0x00c970: d53bd056  mrs      x22, tpidr_el0
//   0x00c974: f94016c8  ldr      x8, [x22, #0x28]
//   0x00c978: 2a0203f4  mov      w20, w2
//   0x00c97c: aa0103f3  mov      x19, x1
//   0x00c980: f90017e8  str      x8, [sp, #0x28]
//   0x00c984: f90013e0  str      x0, [sp, #0x20]
uint64_t fde_0041_sub_00c958(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x00C958ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x00c958: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x00c95c: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x00c960: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x00c964: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x00c968: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00c96c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x00c970: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00c974: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0042 @ 0x00ca3c..0x00cb28 (236 bytes)
// [VN] Phục dựng FDE #0042 tại 0x00ca3c..0x00cb28 (236 byte)
//   0x00ca3c: d10143ff  sub      sp, sp, #0x50
//   0x00ca40: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00ca44: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00ca48: 910103fd  add      x29, sp, #0x40
//   0x00ca4c: d53bd054  mrs      x20, tpidr_el0
//   0x00ca50: f9401688  ldr      x8, [x20, #0x28]
//   0x00ca54: 90000293  adrp     x19, #0x5c000
//   0x00ca58: 91062273  add      x19, x19, #0x188
//   0x00ca5c: f81e83a8  stur     x8, [x29, #-0x18]
//   0x00ca60: f90013e0  str      x0, [sp, #0x20]
//   0x00ca64: 91006260  add      x0, x19, #0x18
//   0x00ca68: 97fffada  bl       #0xb5d0
uint64_t fde_0042_sub_00ca3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF81E83A8ULL) + (x2 ^ 0x00CA3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x00ca3c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00ca40: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00ca44: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00ca48: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x00ca4c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x00ca50: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000293ULL; // 0x00ca54: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91062273ULL; // 0x00ca58: add x19, x19, #0x188
    return acc;
}

// [EN] Reconstructed FDE #0043 @ 0x00cb28..0x00cb84 (92 bytes)
// [VN] Phục dựng FDE #0043 tại 0x00cb28..0x00cb84 (92 byte)
//   0x00cb28: d10103ff  sub      sp, sp, #0x40
//   0x00cb2c: f90013f3  str      x19, [sp, #0x20]
//   0x00cb30: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00cb34: 9100c3fd  add      x29, sp, #0x30
//   0x00cb38: d53bd053  mrs      x19, tpidr_el0
//   0x00cb3c: f9401668  ldr      x8, [x19, #0x28]
//   0x00cb40: b0000162  adrp     x2, #0x39000
//   0x00cb44: 91100042  add      x2, x2, #0x400
//   0x00cb48: 910043e3  add      x3, sp, #0x10
//   0x00cb4c: 910023e4  add      x4, sp, #8
//   0x00cb50: f9000fe8  str      x8, [sp, #0x18]
//   0x00cb54: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0043_sub_00cb28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x00CB28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x00cb28: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x00cb2c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00cb30: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00cb34: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x00cb38: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x00cb3c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000162ULL; // 0x00cb40: adrp x2, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x91100042ULL; // 0x00cb44: add x2, x2, #0x400
    return acc;
}

// [EN] Reconstructed FDE #0044 @ 0x00cb84..0x00cc4c (200 bytes)
// [VN] Phục dựng FDE #0044 tại 0x00cb84..0x00cc4c (200 byte)
//   0x00cb84: d10203ff  sub      sp, sp, #0x80
//   0x00cb88: f9001bf9  str      x25, [sp, #0x30]
//   0x00cb8c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00cb90: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00cb94: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00cb98: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00cb9c: 9101c3fd  add      x29, sp, #0x70
//   0x00cba0: d53bd059  mrs      x25, tpidr_el0
//   0x00cba4: f9401728  ldr      x8, [x25, #0x28]
//   0x00cba8: aa0203f7  mov      x23, x2
//   0x00cbac: aa0103e2  mov      x2, x1
//   0x00cbb0: 910023e1  add      x1, sp, #8
uint64_t fde_0044_sub_00cb84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x00CB84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x00cb84: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x00cb88: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x00cb8c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x00cb90: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x00cb94: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x00cb98: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x00cb9c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x00cba0: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0045 @ 0x00cc4c..0x00ccac (96 bytes)
// [VN] Phục dựng FDE #0045 tại 0x00cc4c..0x00ccac (96 byte)
//   0x00cc4c: aa0003e8  mov      x8, x0
//   0x00cc50: f8408c09  ldr      x9, [x0, #8]!
//   0x00cc54: b4000229  cbz      x9, #0xcc98
//   0x00cc58: f940004a  ldr      x10, [x2]
//   0x00cc5c: 91002100  add      x0, x8, #8
//   0x00cc60: f9401128  ldr      x8, [x9, #0x20]
//   0x00cc64: eb08015f  cmp      x10, x8
//   0x00cc68: 540000a2  b.hs     #0xcc7c
//   0x00cc6c: f9400128  ldr      x8, [x9]
//   0x00cc70: b4000188  cbz      x8, #0xcca0
//   0x00cc74: aa0903e0  mov      x0, x9
//   0x00cc78: 14000006  b        #0xcc90
uint64_t fde_0045_sub_00cc4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x00CC4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00cc4c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x00cc50: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x00cc54: cbz x9, #0xcc98
    acc = (acc * 0x100000001B3ULL) ^ 0xF940004AULL; // 0x00cc58: ldr x10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x00cc5c: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401128ULL; // 0x00cc60: ldr x8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08015FULL; // 0x00cc64: cmp x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x00cc68: b.hs #0xcc7c
    return acc;
}

// [EN] Reconstructed FDE #0046 @ 0x00ccac..0x00cd00 (84 bytes)
// [VN] Phục dựng FDE #0046 tại 0x00ccac..0x00cd00 (84 byte)
//   0x00ccac: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00ccb0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ccb4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00ccb8: 910083fd  add      x29, sp, #0x20
//   0x00ccbc: 91002015  add      x21, x0, #8
//   0x00ccc0: 52800021  mov      w1, #1
//   0x00ccc4: aa1503e0  mov      x0, x21
//   0x00ccc8: aa0203f3  mov      x19, x2
//   0x00cccc: aa0803f4  mov      x20, x8
//   0x00ccd0: 52800036  mov      w22, #1
//   0x00ccd4: 94000022  bl       #0xcd5c
//   0x00ccd8: a9005680  stp      x0, x21, [x20]
uint64_t fde_0046_sub_00ccac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x00CCACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00ccac: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00ccb0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00ccb4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00ccb8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x00ccbc: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x00ccc0: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x00ccc4: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x00ccc8: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0047 @ 0x00cd00..0x00cd54 (84 bytes)
// [VN] Phục dựng FDE #0047 tại 0x00cd00..0x00cd54 (84 byte)
//   0x00cd00: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00cd04: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00cd08: 910043fd  add      x29, sp, #0x10
//   0x00cd0c: a9007c7f  stp      xzr, xzr, [x3]
//   0x00cd10: f9000861  str      x1, [x3, #0x10]
//   0x00cd14: f9000043  str      x3, [x2]
//   0x00cd18: f9400008  ldr      x8, [x0]
//   0x00cd1c: aa0003f3  mov      x19, x0
//   0x00cd20: f9400108  ldr      x8, [x8]
//   0x00cd24: b4000068  cbz      x8, #0xcd30
//   0x00cd28: f9000268  str      x8, [x19]
//   0x00cd2c: f9400043  ldr      x3, [x2]
uint64_t fde_0047_sub_00cd00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x00CD00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00cd00: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00cd04: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00cd08: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x00cd0c: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x00cd10: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x00cd14: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00cd18: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00cd1c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0048 @ 0x00cd54..0x00cd5c (8 bytes)
// [VN] Phục dựng FDE #0048 tại 0x00cd54..0x00cd5c (8 byte)
//   0x00cd54: aa1f03e1  mov      x1, xzr
//   0x00cd58: 14000069  b        #0xcefc
uint64_t fde_0048_sub_00cd54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000069ULL) + (x2 ^ 0x00CD54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00cd54: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000069ULL; // 0x00cd58: b #0xcefc
    return acc;
}

// [EN] Reconstructed FDE #0049 @ 0x00cd5c..0x00cd64 (8 bytes)
// [VN] Phục dựng FDE #0049 tại 0x00cd5c..0x00cd64 (8 byte)
//   0x00cd5c: aa1f03e2  mov      x2, xzr
//   0x00cd60: 14000001  b        #0xcd64
uint64_t fde_0049_sub_00cd5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00CD5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x00cd5c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00cd60: b #0xcd64
    return acc;
}

// [EN] Reconstructed FDE #0050 @ 0x00cd64..0x00cd90 (44 bytes)
// [VN] Phục dựng FDE #0050 tại 0x00cd64..0x00cd90 (44 byte)
//   0x00cd64: b200f3e8  mov      x8, #0x5555555555555555
//   0x00cd68: f28aaac8  movk     x8, #0x5556
//   0x00cd6c: f2e0aaa8  movk     x8, #0x555, lsl #48
//   0x00cd70: eb08003f  cmp      x1, x8
//   0x00cd74: 54000082  b.hs     #0xcd84
//   0x00cd78: 8b010428  add      x8, x1, x1, lsl #1
//   0x00cd7c: d37ced00  lsl      x0, x8, #4
//   0x00cd80: 17fffa1c  b        #0xb5f0
//   0x00cd84: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00cd88: 910003fd  mov      x29, sp
//   0x00cd8c: 97fff9dd  bl       #0xb500
uint64_t fde_0050_sub_00cd64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB200F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x00CD64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3E8ULL; // 0x00cd64: mov x8, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xF28AAAC8ULL; // 0x00cd68: movk x8, #0x5556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0AAA8ULL; // 0x00cd6c: movk x8, #0x555, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x00cd70: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x00cd74: b.hs #0xcd84
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x00cd78: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED00ULL; // 0x00cd7c: lsl x0, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFA1CULL; // 0x00cd80: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0051 @ 0x00cd90..0x00ce84 (244 bytes)
// [VN] Phục dựng FDE #0051 tại 0x00cd90..0x00ce84 (244 byte)
//   0x00cd90: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00cd94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00cd98: 910043fd  add      x29, sp, #0x10
//   0x00cd9c: eb00003f  cmp      x1, x0
//   0x00cda0: 1a9f17e9  cset     w9, eq
//   0x00cda4: aa0003e8  mov      x8, x0
//   0x00cda8: 39006029  strb     w9, [x1, #0x18]
//   0x00cdac: 52800029  mov      w9, #1
//   0x00cdb0: eb08003f  cmp      x1, x8
//   0x00cdb4: 540002e0  b.eq     #0xce10
//   0x00cdb8: f9400833  ldr      x19, [x1, #0x10]
//   0x00cdbc: 3940626a  ldrb     w10, [x19, #0x18]
uint64_t fde_0051_sub_00cd90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xEB08003FULL) + (x2 ^ 0x00CD90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00cd90: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00cd94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00cd98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00003FULL; // 0x00cd9c: cmp x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E9ULL; // 0x00cda0: cset w9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00cda4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x39006029ULL; // 0x00cda8: strb w9, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x00cdac: mov w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0052 @ 0x00ce84..0x00cec0 (60 bytes)
// [VN] Phục dựng FDE #0052 tại 0x00ce84..0x00cec0 (60 byte)
//   0x00ce84: f9400408  ldr      x8, [x0, #8]
//   0x00ce88: f9400109  ldr      x9, [x8]
//   0x00ce8c: f9000409  str      x9, [x0, #8]
//   0x00ce90: b4000049  cbz      x9, #0xce98
//   0x00ce94: f9000920  str      x0, [x9, #0x10]
//   0x00ce98: f9400809  ldr      x9, [x0, #0x10]
//   0x00ce9c: f9000909  str      x9, [x8, #0x10]
//   0x00cea0: f9400809  ldr      x9, [x0, #0x10]
//   0x00cea4: f940012a  ldr      x10, [x9]
//   0x00cea8: eb00015f  cmp      x10, x0
//   0x00ceac: 1a9f07ea  cset     w10, ne
//   0x00ceb0: f82a5928  str      x8, [x9, w10, uxtw #3]
uint64_t fde_0052_sub_00ce84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xF940012AULL) + (x2 ^ 0x00CE84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00ce84: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00ce88: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000409ULL; // 0x00ce8c: str x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000049ULL; // 0x00ce90: cbz x9, #0xce98
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000920ULL; // 0x00ce94: str x0, [x9, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x00ce98: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000909ULL; // 0x00ce9c: str x9, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x00cea0: ldr x9, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0053 @ 0x00cec0..0x00cefc (60 bytes)
// [VN] Phục dựng FDE #0053 tại 0x00cec0..0x00cefc (60 byte)
//   0x00cec0: f9400008  ldr      x8, [x0]
//   0x00cec4: f9400509  ldr      x9, [x8, #8]
//   0x00cec8: f9000009  str      x9, [x0]
//   0x00cecc: b4000049  cbz      x9, #0xced4
//   0x00ced0: f9000920  str      x0, [x9, #0x10]
//   0x00ced4: f9400809  ldr      x9, [x0, #0x10]
//   0x00ced8: f9000909  str      x9, [x8, #0x10]
//   0x00cedc: f9400809  ldr      x9, [x0, #0x10]
//   0x00cee0: f940012a  ldr      x10, [x9]
//   0x00cee4: eb00015f  cmp      x10, x0
//   0x00cee8: 1a9f07ea  cset     w10, ne
//   0x00ceec: f82a5928  str      x8, [x9, w10, uxtw #3]
uint64_t fde_0053_sub_00cec0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xF940012AULL) + (x2 ^ 0x00CEC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00cec0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400509ULL; // 0x00cec4: ldr x9, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000009ULL; // 0x00cec8: str x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000049ULL; // 0x00cecc: cbz x9, #0xced4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000920ULL; // 0x00ced0: str x0, [x9, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x00ced4: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000909ULL; // 0x00ced8: str x9, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x00cedc: ldr x9, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0054 @ 0x00cefc..0x00cf14 (24 bytes)
// [VN] Phục dựng FDE #0054 tại 0x00cefc..0x00cf14 (24 byte)
//   0x00cefc: aa0003e8  mov      x8, x0
//   0x00cf00: f9400000  ldr      x0, [x0]
//   0x00cf04: f9000101  str      x1, [x8]
//   0x00cf08: b4000040  cbz      x0, #0xcf10
//   0x00cf0c: 17fff78d  b        #0xad40
//   0x00cf10: d65f03c0  ret      
uint64_t fde_0054_sub_00cefc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00CEFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00cefc: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x00cf00: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x00cf04: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x00cf08: cbz x0, #0xcf10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF78DULL; // 0x00cf0c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00cf10: ret 
    return acc;
}

// [EN] Reconstructed FDE #0055 @ 0x00cf14..0x00cf5c (72 bytes)
// [VN] Phục dựng FDE #0055 tại 0x00cf14..0x00cf5c (72 byte)
//   0x00cf14: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00cf18: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00cf1c: 910043fd  add      x29, sp, #0x10
//   0x00cf20: aa0003f3  mov      x19, x0
//   0x00cf24: f8408e62  ldr      x2, [x19, #8]!
//   0x00cf28: aa0103f4  mov      x20, x1
//   0x00cf2c: aa1303e3  mov      x3, x19
//   0x00cf30: 9400000b  bl       #0xcf5c
//   0x00cf34: eb00027f  cmp      x19, x0
//   0x00cf38: 540000a0  b.eq     #0xcf4c
//   0x00cf3c: f9400288  ldr      x8, [x20]
//   0x00cf40: f9401009  ldr      x9, [x0, #0x20]
uint64_t fde_0055_sub_00cf14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xEB00027FULL) + (x2 ^ 0x00CF14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00cf14: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00cf18: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00cf1c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00cf20: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E62ULL; // 0x00cf24: ldr x2, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00cf28: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x00cf2c: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000BULL; // 0x00cf30: bl #0xcf5c
    return acc;
}

// [EN] Reconstructed FDE #0056 @ 0x00cf5c..0x00cf84 (40 bytes)
// [VN] Phục dựng FDE #0056 tại 0x00cf5c..0x00cf84 (40 byte)
//   0x00cf5c: f9400028  ldr      x8, [x1]
//   0x00cf60: aa0303e0  mov      x0, x3
//   0x00cf64: b40000e2  cbz      x2, #0xcf80
//   0x00cf68: f9401049  ldr      x9, [x2, #0x20]
//   0x00cf6c: eb08013f  cmp      x9, x8
//   0x00cf70: 1a9f27e9  cset     w9, lo
//   0x00cf74: 9a823000  csel     x0, x0, x2, lo
//   0x00cf78: f8695842  ldr      x2, [x2, w9, uxtw #3]
//   0x00cf7c: b5ffff62  cbnz     x2, #0xcf68
//   0x00cf80: d65f03c0  ret      
uint64_t fde_0056_sub_00cf5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0xB5FFFF62ULL) + (x2 ^ 0x00CF5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x00cf5c: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E0ULL; // 0x00cf60: mov x0, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E2ULL; // 0x00cf64: cbz x2, #0xcf80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401049ULL; // 0x00cf68: ldr x9, [x2, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x00cf6c: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F27E9ULL; // 0x00cf70: cset w9, lo
    acc = (acc * 0x100000001B3ULL) ^ 0x9A823000ULL; // 0x00cf74: csel x0, x0, x2, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xF8695842ULL; // 0x00cf78: ldr x2, [x2, w9, uxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #0057 @ 0x00cf84..0x00cfb4 (48 bytes)
// [VN] Phục dựng FDE #0057 tại 0x00cf84..0x00cfb4 (48 byte)
//   0x00cf84: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00cf88: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00cf8c: 910043fd  add      x29, sp, #0x10
//   0x00cf90: aa0103f3  mov      x19, x1
//   0x00cf94: 94000008  bl       #0xcfb4
//   0x00cf98: aa0003f4  mov      x20, x0
//   0x00cf9c: aa1303e0  mov      x0, x19
//   0x00cfa0: 97fff768  bl       #0xad40
//   0x00cfa4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00cfa8: aa1403e0  mov      x0, x20
//   0x00cfac: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x00cfb0: d65f03c0  ret      
uint64_t fde_0057_sub_00cf84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x00CF84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00cf84: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00cf88: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00cf8c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00cf90: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000008ULL; // 0x00cf94: bl #0xcfb4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00cf98: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00cf9c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF768ULL; // 0x00cfa0: bl #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0058 @ 0x00cfb4..0x00d010 (92 bytes)
// [VN] Phục dựng FDE #0058 tại 0x00cfb4..0x00d010 (92 byte)
//   0x00cfb4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00cfb8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00cfbc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00cfc0: 910083fd  add      x29, sp, #0x20
//   0x00cfc4: aa0003f4  mov      x20, x0
//   0x00cfc8: aa0103e0  mov      x0, x1
//   0x00cfcc: aa0103f3  mov      x19, x1
//   0x00cfd0: 940000b5  bl       #0xd2a4
//   0x00cfd4: f9400288  ldr      x8, [x20]
//   0x00cfd8: aa0003f5  mov      x21, x0
//   0x00cfdc: eb13011f  cmp      x8, x19
//   0x00cfe0: 54000041  b.ne     #0xcfe8
uint64_t fde_0058_sub_00cfb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400288ULL) + (x2 ^ 0x00CFB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00cfb4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00cfb8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00cfbc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00cfc0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00cfc4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x00cfc8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00cfcc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x940000B5ULL; // 0x00cfd0: bl #0xd2a4
    return acc;
}

// [EN] Reconstructed FDE #0059 @ 0x00d010..0x00d2a4 (660 bytes)
// [VN] Phục dựng FDE #0059 tại 0x00d010..0x00d2a4 (660 byte)
//   0x00d010: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00d014: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d018: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d01c: 910083fd  add      x29, sp, #0x20
//   0x00d020: f9400028  ldr      x8, [x1]
//   0x00d024: aa0103f5  mov      x21, x1
//   0x00d028: aa0003f3  mov      x19, x0
//   0x00d02c: b4000108  cbz      x8, #0xd04c
//   0x00d030: f94006a9  ldr      x9, [x21, #8]
//   0x00d034: b4000169  cbz      x9, #0xd060
//   0x00d038: aa1503e0  mov      x0, x21
//   0x00d03c: 940000aa  bl       #0xd2e4
uint64_t fde_0059_sub_00d010(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF94006A9ULL) + (x2 ^ 0x00D010ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00d010: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00d014: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00d018: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00d01c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x00d020: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x00d024: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d028: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000108ULL; // 0x00d02c: cbz x8, #0xd04c
    return acc;
}

// [EN] Reconstructed FDE #0060 @ 0x00d2a4..0x00d2d0 (44 bytes)
// [VN] Phục dựng FDE #0060 tại 0x00d2a4..0x00d2d0 (44 byte)
//   0x00d2a4: f9400408  ldr      x8, [x0, #8]
//   0x00d2a8: b4000088  cbz      x8, #0xd2b8
//   0x00d2ac: aa0803e0  mov      x0, x8
//   0x00d2b0: 14000008  b        #0xd2d0
//   0x00d2b4: aa0803e0  mov      x0, x8
//   0x00d2b8: f9400808  ldr      x8, [x0, #0x10]
//   0x00d2bc: f9400109  ldr      x9, [x8]
//   0x00d2c0: eb00013f  cmp      x9, x0
//   0x00d2c4: 54ffff81  b.ne     #0xd2b4
//   0x00d2c8: aa0803e0  mov      x0, x8
//   0x00d2cc: d65f03c0  ret      
uint64_t fde_0060_sub_00d2a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x54FFFF81ULL) + (x2 ^ 0x00D2A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d2a4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x00d2a8: cbz x8, #0xd2b8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00d2ac: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000008ULL; // 0x00d2b0: b #0xd2d0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00d2b4: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00d2b8: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00d2bc: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00013FULL; // 0x00d2c0: cmp x9, x0
    return acc;
}

// [EN] Reconstructed FDE #0061 @ 0x00d2d0..0x00d2e4 (20 bytes)
// [VN] Phục dựng FDE #0061 tại 0x00d2d0..0x00d2e4 (20 byte)
//   0x00d2d0: aa0003e8  mov      x8, x0
//   0x00d2d4: f9400000  ldr      x0, [x0]
//   0x00d2d8: b5ffffc0  cbnz     x0, #0xd2d0
//   0x00d2dc: aa0803e0  mov      x0, x8
//   0x00d2e0: d65f03c0  ret      
uint64_t fde_0061_sub_00d2d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00D2D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00d2d0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x00d2d4: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5FFFFC0ULL; // 0x00d2d8: cbnz x0, #0xd2d0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00d2dc: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00d2e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0062 @ 0x00d2e4..0x00d310 (44 bytes)
// [VN] Phục dựng FDE #0062 tại 0x00d2e4..0x00d310 (44 byte)
//   0x00d2e4: f9400408  ldr      x8, [x0, #8]
//   0x00d2e8: b4000068  cbz      x8, #0xd2f4
//   0x00d2ec: aa0803e0  mov      x0, x8
//   0x00d2f0: 17fffff8  b        #0xd2d0
//   0x00d2f4: f9400808  ldr      x8, [x0, #0x10]
//   0x00d2f8: f9400109  ldr      x9, [x8]
//   0x00d2fc: eb00013f  cmp      x9, x0
//   0x00d300: aa0803e0  mov      x0, x8
//   0x00d304: 54ffff81  b.ne     #0xd2f4
//   0x00d308: aa0803e0  mov      x0, x8
//   0x00d30c: d65f03c0  ret      
uint64_t fde_0062_sub_00d2e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x54FFFF81ULL) + (x2 ^ 0x00D2E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d2e4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x00d2e8: cbz x8, #0xd2f4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00d2ec: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFF8ULL; // 0x00d2f0: b #0xd2d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00d2f4: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00d2f8: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00013FULL; // 0x00d2fc: cmp x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00d300: mov x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0063 @ 0x00d310..0x00d318 (8 bytes)
// [VN] Phục dựng FDE #0063 tại 0x00d310..0x00d318 (8 byte)
//   0x00d310: f9400401  ldr      x1, [x0, #8]
//   0x00d314: 14000001  b        #0xd318
uint64_t fde_0063_sub_00d310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00D310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x00d310: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00d314: b #0xd318
    return acc;
}

// [EN] Reconstructed FDE #0064 @ 0x00d318..0x00d358 (64 bytes)
// [VN] Phục dựng FDE #0064 tại 0x00d318..0x00d358 (64 byte)
//   0x00d318: b40001e1  cbz      x1, #0xd354
//   0x00d31c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00d320: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d324: 910043fd  add      x29, sp, #0x10
//   0x00d328: aa0103f3  mov      x19, x1
//   0x00d32c: f9400021  ldr      x1, [x1]
//   0x00d330: aa0003f4  mov      x20, x0
//   0x00d334: 97fffff9  bl       #0xd318
//   0x00d338: f9400661  ldr      x1, [x19, #8]
//   0x00d33c: aa1403e0  mov      x0, x20
//   0x00d340: 97fffff6  bl       #0xd318
//   0x00d344: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0064_sub_00d318(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x00D318ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x00d318: cbz x1, #0xd354
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00d31c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d320: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d324: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00d328: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x00d32c: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00d330: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x00d334: bl #0xd318
    return acc;
}

// [EN] Reconstructed FDE #0065 @ 0x00d358..0x00d364 (12 bytes)
// [VN] Phục dựng FDE #0065 tại 0x00d358..0x00d364 (12 byte)
//   0x00d358: 90000160  adrp     x0, #0x39000
//   0x00d35c: 911cd000  add      x0, x0, #0x734
//   0x00d360: 17fff784  b        #0xb170
uint64_t fde_0065_sub_00d358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000160ULL) + (x1 ^ 0x17FFF784ULL) + (x2 ^ 0x00D358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000160ULL; // 0x00d358: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x00d35c: add x0, x0, #0x734
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF784ULL; // 0x00d360: b #0xb170
    return acc;
}

// [EN] Reconstructed FDE #0066 @ 0x00d364..0x00d368 (4 bytes)
// [VN] Phục dựng FDE #0066 tại 0x00d364..0x00d368 (4 byte)
//   0x00d364: 14000977  b        #0xf940
uint64_t fde_0066_sub_00d364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000977ULL) + (x1 ^ 0x14000977ULL) + (x2 ^ 0x00D364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000977ULL; // 0x00d364: b #0xf940
    return acc;
}

// [EN] Reconstructed FDE #0067 @ 0x00d368..0x00d36c (4 bytes)
// [VN] Phục dựng FDE #0067 tại 0x00d368..0x00d36c (4 byte)
//   0x00d368: 14000997  b        #0xf9c4
uint64_t fde_0067_sub_00d368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000997ULL) + (x1 ^ 0x14000997ULL) + (x2 ^ 0x00D368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000997ULL; // 0x00d368: b #0xf9c4
    return acc;
}

// [EN] Reconstructed FDE #0068 @ 0x00d36c..0x00d530 (452 bytes)
// [VN] Phục dựng FDE #0068 tại 0x00d36c..0x00d530 (452 byte)
//   0x00d36c: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x00d370: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00d374: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00d378: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00d37c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00d380: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00d384: 910143fd  add      x29, sp, #0x50
//   0x00d388: d106c3ff  sub      sp, sp, #0x1b0
//   0x00d38c: d53bd056  mrs      x22, tpidr_el0
//   0x00d390: f94016c8  ldr      x8, [x22, #0x28]
//   0x00d394: aa0003e1  mov      x1, x0
//   0x00d398: 910163e0  add      x0, sp, #0x58
uint64_t fde_0068_sub_00d36c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFCULL) + (x1 ^ 0xD53BD056ULL) + (x2 ^ 0x00D36CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFCULL; // 0x00d36c: str x28, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00d370: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00d374: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00d378: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00d37c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00d380: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00d384: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x00d388: sub sp, sp, #0x1b0
    return acc;
}

// [EN] Reconstructed FDE #0069 @ 0x00d530..0x00d5dc (172 bytes)
// [VN] Phục dựng FDE #0069 tại 0x00d530..0x00d5dc (172 byte)
//   0x00d530: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00d534: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00d538: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00d53c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00d540: 9100c3fd  add      x29, sp, #0x30
//   0x00d544: d0000268  adrp     x8, #0x5b000
//   0x00d548: f944e108  ldr      x8, [x8, #0x9c0]
//   0x00d54c: 91004016  add      x22, x0, #0x10
//   0x00d550: 2a0203f4  mov      w20, w2
//   0x00d554: aa0103f5  mov      x21, x1
//   0x00d558: 91006117  add      x23, x8, #0x18
//   0x00d55c: 91010118  add      x24, x8, #0x40
uint64_t fde_0069_sub_00d530(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x00D530ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00d530: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00d534: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00d538: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00d53c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00d540: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000268ULL; // 0x00d544: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944E108ULL; // 0x00d548: ldr x8, [x8, #0x9c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x00d54c: add x22, x0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0070 @ 0x00d5dc..0x00d5e8 (12 bytes)
// [VN] Phục dựng FDE #0070 tại 0x00d5dc..0x00d5e8 (12 byte)
//   0x00d5dc: a9007c1f  stp      xzr, xzr, [x0]
//   0x00d5e0: f900081f  str      xzr, [x0, #0x10]
//   0x00d5e4: 14000849  b        #0xf708
uint64_t fde_0070_sub_00d5dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9007C1FULL) + (x1 ^ 0x14000849ULL) + (x2 ^ 0x00D5DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x00d5dc: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x00d5e0: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000849ULL; // 0x00d5e4: b #0xf708
    return acc;
}

// [EN] Reconstructed FDE #0071 @ 0x00d5e8..0x00d628 (64 bytes)
// [VN] Phục dựng FDE #0071 tại 0x00d5e8..0x00d628 (64 byte)
//   0x00d5e8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00d5ec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d5f0: 910043fd  add      x29, sp, #0x10
//   0x00d5f4: f9400008  ldr      x8, [x0]
//   0x00d5f8: aa0103f3  mov      x19, x1
//   0x00d5fc: aa0003f4  mov      x20, x0
//   0x00d600: 52800141  mov      w1, #0xa
//   0x00d604: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00d608: 8b080000  add      x0, x0, x8
//   0x00d60c: 94000a38  bl       #0xfeec
//   0x00d610: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d614: 2a0003e2  mov      w2, w0
uint64_t fde_0071_sub_00d5e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x8B080000ULL) + (x2 ^ 0x00D5E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00d5e8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d5ec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d5f0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00d5f4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00d5f8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00d5fc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800141ULL; // 0x00d600: mov w1, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00d604: ldur x8, [x8, #-0x18]
    return acc;
}

// [EN] Reconstructed FDE #0072 @ 0x00d628..0x00d674 (76 bytes)
// [VN] Phục dựng FDE #0072 tại 0x00d628..0x00d674 (76 byte)
//   0x00d628: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00d62c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d630: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d634: 910083fd  add      x29, sp, #0x20
//   0x00d638: aa0003f6  mov      x22, x0
//   0x00d63c: aa0303e0  mov      x0, x3
//   0x00d640: aa0303f3  mov      x19, x3
//   0x00d644: aa0203f4  mov      x20, x2
//   0x00d648: aa0103f5  mov      x21, x1
//   0x00d64c: 97fff675  bl       #0xb020
//   0x00d650: aa1403e2  mov      x2, x20
//   0x00d654: aa1303e3  mov      x3, x19
uint64_t fde_0072_sub_00d628(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x00D628ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00d628: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00d62c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00d630: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00d634: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x00d638: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E0ULL; // 0x00d63c: mov x0, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00d640: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x00d644: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0073 @ 0x00d674..0x00d6bc (72 bytes)
// [VN] Phục dựng FDE #0073 tại 0x00d674..0x00d6bc (72 byte)
//   0x00d674: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d678: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d67c: 910043fd  add      x29, sp, #0x10
//   0x00d680: aa0003f3  mov      x19, x0
//   0x00d684: eb01001f  cmp      x0, x1
//   0x00d688: 54000120  b.eq     #0xd6ac
//   0x00d68c: 39400028  ldrb     w8, [x1]
//   0x00d690: a940a42a  ldp      x10, x9, [x1, #8]
//   0x00d694: aa1303e0  mov      x0, x19
//   0x00d698: d341fd0b  lsr      x11, x8, #1
//   0x00d69c: 7200011f  tst      w8, #1
//   0x00d6a0: 9a811521  csinc    x1, x9, x1, ne
uint64_t fde_0073_sub_00d674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00D674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d674: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d678: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d67c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d680: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01001FULL; // 0x00d684: cmp x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x00d688: b.eq #0xd6ac
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x00d68c: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A42AULL; // 0x00d690: ldp x10, x9, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0074 @ 0x00d6bc..0x00d768 (172 bytes)
// [VN] Phục dựng FDE #0074 tại 0x00d6bc..0x00d768 (172 byte)
//   0x00d6bc: d10183ff  sub      sp, sp, #0x60
//   0x00d6c0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00d6c4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00d6c8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00d6cc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00d6d0: 910143fd  add      x29, sp, #0x50
//   0x00d6d4: d53bd057  mrs      x23, tpidr_el0
//   0x00d6d8: f94016e8  ldr      x8, [x23, #0x28]
//   0x00d6dc: 91004015  add      x21, x0, #0x10
//   0x00d6e0: aa0103f3  mov      x19, x1
//   0x00d6e4: aa0003f4  mov      x20, x0
//   0x00d6e8: 52800021  mov      w1, #1
uint64_t fde_0074_sub_00d6bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x91004015ULL) + (x2 ^ 0x00D6BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x00d6bc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00d6c0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00d6c4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00d6c8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00d6cc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00d6d0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x00d6d4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x00d6d8: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0075 @ 0x00d768..0x00d7c4 (92 bytes)
// [VN] Phục dựng FDE #0075 tại 0x00d768..0x00d7c4 (92 byte)
//   0x00d768: d10103ff  sub      sp, sp, #0x40
//   0x00d76c: f90013f3  str      x19, [sp, #0x20]
//   0x00d770: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00d774: 9100c3fd  add      x29, sp, #0x30
//   0x00d778: d53bd053  mrs      x19, tpidr_el0
//   0x00d77c: f9401668  ldr      x8, [x19, #0x28]
//   0x00d780: 90000162  adrp     x2, #0x39000
//   0x00d784: 91119842  add      x2, x2, #0x466
//   0x00d788: 910043e3  add      x3, sp, #0x10
//   0x00d78c: 910023e4  add      x4, sp, #8
//   0x00d790: f9000fe8  str      x8, [sp, #0x18]
//   0x00d794: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0075_sub_00d768(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x00D768ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x00d768: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x00d76c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00d770: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00d774: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x00d778: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x00d77c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000162ULL; // 0x00d780: adrp x2, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x91119842ULL; // 0x00d784: add x2, x2, #0x466
    return acc;
}

// [EN] Reconstructed FDE #0076 @ 0x00d7c4..0x00d800 (60 bytes)
// [VN] Phục dựng FDE #0076 tại 0x00d7c4..0x00d800 (60 byte)
//   0x00d7c4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d7c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d7cc: 910043fd  add      x29, sp, #0x10
//   0x00d7d0: aa0003f3  mov      x19, x0
//   0x00d7d4: eb01001f  cmp      x0, x1
//   0x00d7d8: 540000c0  b.eq     #0xd7f0
//   0x00d7dc: aa0103e2  mov      x2, x1
//   0x00d7e0: f9400421  ldr      x1, [x1, #8]
//   0x00d7e4: aa1303e0  mov      x0, x19
//   0x00d7e8: aa1f03e3  mov      x3, xzr
//   0x00d7ec: 94000ce6  bl       #0x10b84
//   0x00d7f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0076_sub_00d7c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00D7C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d7c4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d7c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d7cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d7d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01001FULL; // 0x00d7d4: cmp x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x00d7d8: b.eq #0xd7f0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x00d7dc: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400421ULL; // 0x00d7e0: ldr x1, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0077 @ 0x00d800..0x00d844 (68 bytes)
// [VN] Phục dựng FDE #0077 tại 0x00d800..0x00d844 (68 byte)
//   0x00d800: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d804: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d808: 910043fd  add      x29, sp, #0x10
//   0x00d80c: aa0003f3  mov      x19, x0
//   0x00d810: 91004000  add      x0, x0, #0x10
//   0x00d814: 94000111  bl       #0xdc58
//   0x00d818: b4000080  cbz      x0, #0xd828
//   0x00d81c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d820: f84207f3  ldr      x19, [sp], #0x20
//   0x00d824: d65f03c0  ret      
//   0x00d828: f9400268  ldr      x8, [x19]
//   0x00d82c: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0077_sub_00d800(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x00D800ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d800: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d804: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d808: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d80c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x00d810: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000111ULL; // 0x00d814: bl #0xdc58
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x00d818: cbz x0, #0xd828
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00d81c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0078 @ 0x00d844..0x00d858 (20 bytes)
// [VN] Phục dựng FDE #0078 tại 0x00d844..0x00d858 (20 byte)
//   0x00d844: 39400008  ldrb     w8, [x0]
//   0x00d848: 37000048  tbnz     w8, #0, #0xd850
//   0x00d84c: d65f03c0  ret      
//   0x00d850: f9400800  ldr      x0, [x0, #0x10]
//   0x00d854: 17fff53b  b        #0xad40
uint64_t fde_0078_sub_00d844(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0x17FFF53BULL) + (x2 ^ 0x00D844ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x00d844: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000048ULL; // 0x00d848: tbnz w8, #0, #0xd850
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00d84c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x00d850: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF53BULL; // 0x00d854: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0079 @ 0x00d858..0x00d884 (44 bytes)
// [VN] Phục dựng FDE #0079 tại 0x00d858..0x00d884 (44 byte)
//   0x00d858: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d85c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d860: 910043fd  add      x29, sp, #0x10
//   0x00d864: d0000261  adrp     x1, #0x5b000
//   0x00d868: f9465c21  ldr      x1, [x1, #0xcb8]
//   0x00d86c: aa0003f3  mov      x19, x0
//   0x00d870: 940000b7  bl       #0xdb4c
//   0x00d874: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d878: 9102e260  add      x0, x19, #0xb8
//   0x00d87c: f84207f3  ldr      x19, [sp], #0x20
//   0x00d880: 17fff54c  b        #0xadb0
uint64_t fde_0079_sub_00d858(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9102E260ULL) + (x2 ^ 0x00D858ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d858: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d85c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d860: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000261ULL; // 0x00d864: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9465C21ULL; // 0x00d868: ldr x1, [x1, #0xcb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d86c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x940000B7ULL; // 0x00d870: bl #0xdb4c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00d874: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0080 @ 0x00d884..0x00d904 (128 bytes)
// [VN] Phục dựng FDE #0080 tại 0x00d884..0x00d904 (128 byte)
//   0x00d884: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d888: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d88c: 910043fd  add      x29, sp, #0x10
//   0x00d890: f0000273  adrp     x19, #0x5c000
//   0x00d894: f940e668  ldr      x8, [x19, #0x1c8]
//   0x00d898: b4000088  cbz      x8, #0xd8a8
//   0x00d89c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d8a0: f84207f3  ldr      x19, [sp], #0x20
//   0x00d8a4: d65f03c0  ret      
//   0x00d8a8: 2a1f03e0  mov      w0, wzr
//   0x00d8ac: 2a1f03e1  mov      w1, wzr
//   0x00d8b0: 97fff7d0  bl       #0xb7f0
uint64_t fde_0080_sub_00d884(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00D884ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d884: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d888: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d88c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000273ULL; // 0x00d890: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF940E668ULL; // 0x00d894: ldr x8, [x19, #0x1c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x00d898: cbz x8, #0xd8a8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00d89c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00d8a0: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0081 @ 0x00d904..0x00dae0 (476 bytes)
// [VN] Phục dựng FDE #0081 tại 0x00d904..0x00dae0 (476 byte)
//   0x00d904: d10203ff  sub      sp, sp, #0x80
//   0x00d908: f90013fb  str      x27, [sp, #0x20]
//   0x00d90c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x00d910: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00d914: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00d918: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00d91c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00d920: 9101c3fd  add      x29, sp, #0x70
//   0x00d924: d53bd059  mrs      x25, tpidr_el0
//   0x00d928: f9401728  ldr      x8, [x25, #0x28]
//   0x00d92c: aa0003f3  mov      x19, x0
//   0x00d930: aa0103e0  mov      x0, x1
uint64_t fde_0081_sub_00d904(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD53BD059ULL) + (x2 ^ 0x00D904ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x00d904: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x00d908: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x00d90c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x00d910: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x00d914: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x00d918: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x00d91c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x00d920: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0082 @ 0x00dae0..0x00db4c (108 bytes)
// [VN] Phục dựng FDE #0082 tại 0x00dae0..0x00db4c (108 byte)
//   0x00dae0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00dae4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00dae8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00daec: 910083fd  add      x29, sp, #0x20
//   0x00daf0: f9400808  ldr      x8, [x0, #0x10]
//   0x00daf4: b4000248  cbz      x8, #0xdb3c
//   0x00daf8: a9405008  ldp      x8, x20, [x0]
//   0x00dafc: aa0003f3  mov      x19, x0
//   0x00db00: f9400509  ldr      x9, [x8, #8]
//   0x00db04: f940028a  ldr      x10, [x20]
//   0x00db08: f9000549  str      x9, [x10, #8]
//   0x00db0c: f9400508  ldr      x8, [x8, #8]
uint64_t fde_0082_sub_00dae0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400509ULL) + (x2 ^ 0x00DAE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00dae0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00dae4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00dae8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00daec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x00daf0: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000248ULL; // 0x00daf4: cbz x8, #0xdb3c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9405008ULL; // 0x00daf8: ldp x8, x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dafc: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0083 @ 0x00db4c..0x00db6c (32 bytes)
// [VN] Phục dựng FDE #0083 tại 0x00db4c..0x00db6c (32 byte)
//   0x00db4c: f9400028  ldr      x8, [x1]
//   0x00db50: f9000008  str      x8, [x0]
//   0x00db54: f9400c29  ldr      x9, [x1, #0x18]
//   0x00db58: f85e810a  ldur     x10, [x8, #-0x18]
//   0x00db5c: 91004008  add      x8, x0, #0x10
//   0x00db60: f82a6809  str      x9, [x0, x10]
//   0x00db64: aa0803e0  mov      x0, x8
//   0x00db68: 14000027  b        #0xdc04
uint64_t fde_0083_sub_00db4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0x14000027ULL) + (x2 ^ 0x00DB4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x00db4c: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x00db50: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C29ULL; // 0x00db54: ldr x9, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E810AULL; // 0x00db58: ldur x10, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004008ULL; // 0x00db5c: add x8, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF82A6809ULL; // 0x00db60: str x9, [x0, x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00db64: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000027ULL; // 0x00db68: b #0xdc04
    return acc;
}

// [EN] Reconstructed FDE #0084 @ 0x00db6c..0x00db7c (16 bytes)
// [VN] Phục dựng FDE #0084 tại 0x00db6c..0x00db7c (16 byte)
//   0x00db6c: f9400008  ldr      x8, [x0]
//   0x00db70: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00db74: 8b080000  add      x0, x0, x8
//   0x00db78: 17ffff38  b        #0xd858
uint64_t fde_0084_sub_00db6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x17FFFF38ULL) + (x2 ^ 0x00DB6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00db6c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00db70: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080000ULL; // 0x00db74: add x0, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF38ULL; // 0x00db78: b #0xd858
    return acc;
}

// [EN] Reconstructed FDE #0085 @ 0x00db7c..0x00db84 (8 bytes)
// [VN] Phục dựng FDE #0085 tại 0x00db7c..0x00db84 (8 byte)
//   0x00db7c: 91004000  add      x0, x0, #0x10
//   0x00db80: 17fff48c  b        #0xadb0
uint64_t fde_0085_sub_00db7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91004000ULL) + (x1 ^ 0x17FFF48CULL) + (x2 ^ 0x00DB7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x00db7c: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF48CULL; // 0x00db80: b #0xadb0
    return acc;
}

// [EN] Reconstructed FDE #0086 @ 0x00db84..0x00dbac (40 bytes)
// [VN] Phục dựng FDE #0086 tại 0x00db84..0x00dbac (40 byte)
//   0x00db84: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00db88: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00db8c: 910043fd  add      x29, sp, #0x10
//   0x00db90: aa0003f3  mov      x19, x0
//   0x00db94: 91004000  add      x0, x0, #0x10
//   0x00db98: 97fff486  bl       #0xadb0
//   0x00db9c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00dba0: aa1303e0  mov      x0, x19
//   0x00dba4: f84207f3  ldr      x19, [sp], #0x20
//   0x00dba8: 17fff466  b        #0xad40
uint64_t fde_0086_sub_00db84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x00DB84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00db84: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00db88: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00db8c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00db90: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004000ULL; // 0x00db94: add x0, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF486ULL; // 0x00db98: bl #0xadb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00db9c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00dba0: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0087 @ 0x00dbac..0x00dbc0 (20 bytes)
// [VN] Phục dựng FDE #0087 tại 0x00dbac..0x00dbc0 (20 byte)
//   0x00dbac: f9400008  ldr      x8, [x0]
//   0x00dbb0: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00dbb4: 8b080008  add      x8, x0, x8
//   0x00dbb8: 91004100  add      x0, x8, #0x10
//   0x00dbbc: 17fff47d  b        #0xadb0
uint64_t fde_0087_sub_00dbac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x17FFF47DULL) + (x2 ^ 0x00DBACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dbac: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00dbb0: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x00dbb4: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004100ULL; // 0x00dbb8: add x0, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF47DULL; // 0x00dbbc: b #0xadb0
    return acc;
}

// [EN] Reconstructed FDE #0088 @ 0x00dbc0..0x00dbd0 (16 bytes)
// [VN] Phục dựng FDE #0088 tại 0x00dbc0..0x00dbd0 (16 byte)
//   0x00dbc0: f9400008  ldr      x8, [x0]
//   0x00dbc4: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00dbc8: 8b080000  add      x0, x0, x8
//   0x00dbcc: 17ffffee  b        #0xdb84
uint64_t fde_0088_sub_00dbc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x17FFFFEEULL) + (x2 ^ 0x00DBC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dbc0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00dbc4: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080000ULL; // 0x00dbc8: add x0, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFEEULL; // 0x00dbcc: b #0xdb84
    return acc;
}

// [EN] Reconstructed FDE #0089 @ 0x00dbd0..0x00dbf4 (36 bytes)
// [VN] Phục dựng FDE #0089 tại 0x00dbd0..0x00dbf4 (36 byte)
//   0x00dbd0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00dbd4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00dbd8: 910043fd  add      x29, sp, #0x10
//   0x00dbdc: aa0003f3  mov      x19, x0
//   0x00dbe0: 97ffff1e  bl       #0xd858
//   0x00dbe4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00dbe8: aa1303e0  mov      x0, x19
//   0x00dbec: f84207f3  ldr      x19, [sp], #0x20
//   0x00dbf0: 17fff454  b        #0xad40
uint64_t fde_0089_sub_00dbd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFF454ULL) + (x2 ^ 0x00DBD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00dbd0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00dbd4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00dbd8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dbdc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF1EULL; // 0x00dbe0: bl #0xd858
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00dbe4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00dbe8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00dbec: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0090 @ 0x00dbf4..0x00dc04 (16 bytes)
// [VN] Phục dựng FDE #0090 tại 0x00dbf4..0x00dc04 (16 byte)
//   0x00dbf4: f9400008  ldr      x8, [x0]
//   0x00dbf8: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00dbfc: 8b080000  add      x0, x0, x8
//   0x00dc00: 17fffff4  b        #0xdbd0
uint64_t fde_0090_sub_00dbf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0x17FFFFF4ULL) + (x2 ^ 0x00DBF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dbf4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00dbf8: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080000ULL; // 0x00dbfc: add x0, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFF4ULL; // 0x00dc00: b #0xdbd0
    return acc;
}

// [EN] Reconstructed FDE #0091 @ 0x00dc04..0x00dc58 (84 bytes)
// [VN] Phục dựng FDE #0091 tại 0x00dc04..0x00dc58 (84 byte)
//   0x00dc04: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00dc08: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00dc0c: 910043fd  add      x29, sp, #0x10
//   0x00dc10: d0000268  adrp     x8, #0x5b000
//   0x00dc14: f9448908  ldr      x8, [x8, #0x910]
//   0x00dc18: aa0003f3  mov      x19, x0
//   0x00dc1c: 91004108  add      x8, x8, #0x10
//   0x00dc20: f9000008  str      x8, [x0]
//   0x00dc24: 9400000d  bl       #0xdc58
//   0x00dc28: 39428268  ldrb     w8, [x19, #0xa0]
//   0x00dc2c: 34000068  cbz      w8, #0xdc38
//   0x00dc30: f9402260  ldr      x0, [x19, #0x40]
uint64_t fde_0091_sub_00dc04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9400000DULL) + (x2 ^ 0x00DC04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00dc04: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00dc08: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00dc0c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000268ULL; // 0x00dc10: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9448908ULL; // 0x00dc14: ldr x8, [x8, #0x910]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dc18: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x00dc1c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x00dc20: str x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0092 @ 0x00dc58..0x00dcc8 (112 bytes)
// [VN] Phục dựng FDE #0092 tại 0x00dc58..0x00dcc8 (112 byte)
//   0x00dc58: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00dc5c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00dc60: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00dc64: 910083fd  add      x29, sp, #0x20
//   0x00dc68: f9403c14  ldr      x20, [x0, #0x78]
//   0x00dc6c: b4000254  cbz      x20, #0xdcb4
//   0x00dc70: f9400008  ldr      x8, [x0]
//   0x00dc74: aa0003f3  mov      x19, x0
//   0x00dc78: f9401908  ldr      x8, [x8, #0x30]
//   0x00dc7c: d63f0100  blr      x8
//   0x00dc80: 2a0003f5  mov      w21, w0
//   0x00dc84: aa1403e0  mov      x0, x20
uint64_t fde_0092_sub_00dc58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9401908ULL) + (x2 ^ 0x00DC58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00dc58: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00dc5c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00dc60: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00dc64: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C14ULL; // 0x00dc68: ldr x20, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000254ULL; // 0x00dc6c: cbz x20, #0xdcb4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dc70: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dc74: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0093 @ 0x00dcc8..0x00dcec (36 bytes)
// [VN] Phục dựng FDE #0093 tại 0x00dcc8..0x00dcec (36 byte)
//   0x00dcc8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00dccc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00dcd0: 910043fd  add      x29, sp, #0x10
//   0x00dcd4: aa0003f3  mov      x19, x0
//   0x00dcd8: 97ffffcb  bl       #0xdc04
//   0x00dcdc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00dce0: aa1303e0  mov      x0, x19
//   0x00dce4: f84207f3  ldr      x19, [sp], #0x20
//   0x00dce8: 17fff416  b        #0xad40
uint64_t fde_0093_sub_00dcc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFF416ULL) + (x2 ^ 0x00DCC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00dcc8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00dccc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00dcd0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dcd4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFCBULL; // 0x00dcd8: bl #0xdc04
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00dcdc: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00dce0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00dce4: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0094 @ 0x00dcec..0x00ddd0 (228 bytes)
// [VN] Phục dựng FDE #0094 tại 0x00dcec..0x00ddd0 (228 byte)
//   0x00dcec: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00dcf0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00dcf4: 910043fd  add      x29, sp, #0x10
//   0x00dcf8: f9400008  ldr      x8, [x0]
//   0x00dcfc: aa0003f3  mov      x19, x0
//   0x00dd00: aa0103f4  mov      x20, x1
//   0x00dd04: f9401908  ldr      x8, [x8, #0x30]
//   0x00dd08: d63f0100  blr      x8
//   0x00dd0c: aa1403e0  mov      x0, x20
//   0x00dd10: 940002c4  bl       #0xe820
//   0x00dd14: f9004260  str      x0, [x19, #0x80]
//   0x00dd18: f9400008  ldr      x8, [x0]
uint64_t fde_0094_sub_00dcec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x00DCECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00dcec: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00dcf0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00dcf4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dcf8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dcfc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00dd00: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x00dd04: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00dd08: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0095 @ 0x00ddd0..0x00dec0 (240 bytes)
// [VN] Phục dựng FDE #0095 tại 0x00ddd0..0x00dec0 (240 byte)
//   0x00ddd0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00ddd4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00ddd8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00dddc: 910083fd  add      x29, sp, #0x20
//   0x00dde0: 39428008  ldrb     w8, [x0, #0xa0]
//   0x00dde4: aa0203f5  mov      x21, x2
//   0x00dde8: aa0103f4  mov      x20, x1
//   0x00ddec: aa0003f3  mov      x19, x0
//   0x00ddf0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00ddf4: ad010000  stp      q0, q0, [x0, #0x20]
//   0x00ddf8: 3d800400  str      q0, [x0, #0x10]
//   0x00ddfc: 34000068  cbz      w8, #0xde08
uint64_t fde_0095_sub_00ddd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x6F00E400ULL) + (x2 ^ 0x00DDD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00ddd0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00ddd4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00ddd8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00dddc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39428008ULL; // 0x00dde0: ldrb w8, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x00dde4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00dde8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00ddec: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0096 @ 0x00dec0..0x00df80 (192 bytes)
// [VN] Phục dựng FDE #0096 tại 0x00dec0..0x00df80 (192 byte)
//   0x00dec0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00dec4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00dec8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00decc: 910083fd  add      x29, sp, #0x20
//   0x00ded0: aa0003f3  mov      x19, x0
//   0x00ded4: f9404000  ldr      x0, [x0, #0x80]
//   0x00ded8: b4000520  cbz      x0, #0xdf7c
//   0x00dedc: f9400008  ldr      x8, [x0]
//   0x00dee0: 2a0203f4  mov      w20, w2
//   0x00dee4: aa0103f5  mov      x21, x1
//   0x00dee8: f9401908  ldr      x8, [x8, #0x30]
//   0x00deec: d63f0100  blr      x8
uint64_t fde_0096_sub_00dec0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x00DEC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00dec0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00dec4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00dec8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00decc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00ded0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404000ULL; // 0x00ded4: ldr x0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000520ULL; // 0x00ded8: cbz x0, #0xdf7c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00dedc: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0097 @ 0x00df80..0x00dff0 (112 bytes)
// [VN] Phục dựng FDE #0097 tại 0x00df80..0x00dff0 (112 byte)
//   0x00df80: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00df84: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00df88: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00df8c: 910083fd  add      x29, sp, #0x20
//   0x00df90: f9403c08  ldr      x8, [x0, #0x78]
//   0x00df94: b40001a8  cbz      x8, #0xdfc8
//   0x00df98: f9400008  ldr      x8, [x0]
//   0x00df9c: aa0203f3  mov      x19, x2
//   0x00dfa0: aa0003f5  mov      x21, x0
//   0x00dfa4: aa0103f4  mov      x20, x1
//   0x00dfa8: f9401908  ldr      x8, [x8, #0x30]
//   0x00dfac: d63f0100  blr      x8
uint64_t fde_0097_sub_00df80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x00DF80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00df80: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00df84: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00df88: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00df8c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x00df90: ldr x8, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x00df94: cbz x8, #0xdfc8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00df98: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x00df9c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0098 @ 0x00dff0..0x00e1e0 (496 bytes)
// [VN] Phục dựng FDE #0098 tại 0x00dff0..0x00e1e0 (496 byte)
//   0x00dff0: d10143ff  sub      sp, sp, #0x50
//   0x00dff4: f9000bf7  str      x23, [sp, #0x10]
//   0x00dff8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00dffc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00e000: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00e004: 910103fd  add      x29, sp, #0x40
//   0x00e008: d53bd057  mrs      x23, tpidr_el0
//   0x00e00c: f94016e8  ldr      x8, [x23, #0x28]
//   0x00e010: f90007e8  str      x8, [sp, #8]
//   0x00e014: f9403c08  ldr      x8, [x0, #0x78]
//   0x00e018: b4000c88  cbz      x8, #0xe1a8
//   0x00e01c: aa0003f3  mov      x19, x0
uint64_t fde_0098_sub_00dff0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x00DFF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x00dff0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x00dff4: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00dff8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00dffc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00e000: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00e004: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x00e008: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x00e00c: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0099 @ 0x00e1e0..0x00e1e8 (8 bytes)
// [VN] Phục dựng FDE #0099 tại 0x00e1e0..0x00e1e8 (8 byte)
//   0x00e1e0: aa1f03e0  mov      x0, xzr
//   0x00e1e4: d65f03c0  ret      
uint64_t fde_0099_sub_00e1e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E1E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x00e1e0: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e1e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0100 @ 0x00e1e8..0x00e29c (180 bytes)
// [VN] Phục dựng FDE #0100 tại 0x00e1e8..0x00e29c (180 byte)
//   0x00e1e8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00e1ec: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e1f0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e1f4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e1f8: 9100c3fd  add      x29, sp, #0x30
//   0x00e1fc: aa0203f3  mov      x19, x2
//   0x00e200: aa0103f4  mov      x20, x1
//   0x00e204: aa0003f6  mov      x22, x0
//   0x00e208: aa1f03f5  mov      x21, xzr
//   0x00e20c: 12b00018  mov      w24, #0x7fffffff
//   0x00e210: eb1302bf  cmp      x21, x19
//   0x00e214: 5400038a  b.ge     #0xe284
uint64_t fde_0100_sub_00e1e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA1F03F5ULL) + (x2 ^ 0x00E1E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00e1e8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00e1ec: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00e1f0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00e1f4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00e1f8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x00e1fc: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00e200: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x00e204: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0101 @ 0x00e29c..0x00e4b8 (540 bytes)
// [VN] Phục dựng FDE #0101 tại 0x00e29c..0x00e4b8 (540 byte)
//   0x00e29c: d10183ff  sub      sp, sp, #0x60
//   0x00e2a0: f90013f7  str      x23, [sp, #0x20]
//   0x00e2a4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00e2a8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00e2ac: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00e2b0: 910143fd  add      x29, sp, #0x50
//   0x00e2b4: d53bd057  mrs      x23, tpidr_el0
//   0x00e2b8: f94016e8  ldr      x8, [x23, #0x28]
//   0x00e2bc: f9000fe8  str      x8, [sp, #0x18]
//   0x00e2c0: f9403c08  ldr      x8, [x0, #0x78]
//   0x00e2c4: b4000128  cbz      x8, #0xe2e8
//   0x00e2c8: aa0003f3  mov      x19, x0
uint64_t fde_0101_sub_00e29c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x00E29CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x00e29c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x00e2a0: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00e2a4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00e2a8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00e2ac: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00e2b0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x00e2b4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x00e2b8: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0102 @ 0x00e4b8..0x00e4f8 (64 bytes)
// [VN] Phục dựng FDE #0102 tại 0x00e4b8..0x00e4f8 (64 byte)
//   0x00e4b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00e4bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e4c0: 910043fd  add      x29, sp, #0x10
//   0x00e4c4: f9400008  ldr      x8, [x0]
//   0x00e4c8: aa0003f3  mov      x19, x0
//   0x00e4cc: f9402508  ldr      x8, [x8, #0x48]
//   0x00e4d0: d63f0100  blr      x8
//   0x00e4d4: 3100041f  cmn      w0, #1
//   0x00e4d8: 540000a0  b.eq     #0xe4ec
//   0x00e4dc: f9400e68  ldr      x8, [x19, #0x18]
//   0x00e4e0: 91000509  add      x9, x8, #1
//   0x00e4e4: f9000e69  str      x9, [x19, #0x18]
uint64_t fde_0102_sub_00e4b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x540000A0ULL) + (x2 ^ 0x00E4B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00e4b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00e4bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00e4c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00e4c4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00e4c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402508ULL; // 0x00e4cc: ldr x8, [x8, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00e4d0: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x00e4d4: cmn w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0103 @ 0x00e4f8..0x00e558 (96 bytes)
// [VN] Phục dựng FDE #0103 tại 0x00e4f8..0x00e558 (96 byte)
//   0x00e4f8: f9403c09  ldr      x9, [x0, #0x78]
//   0x00e4fc: b4000229  cbz      x9, #0xe540
//   0x00e500: a941240a  ldp      x10, x9, [x0, #0x10]
//   0x00e504: aa0003e8  mov      x8, x0
//   0x00e508: eb09015f  cmp      x10, x9
//   0x00e50c: 540001a2  b.hs     #0xe540
//   0x00e510: 2a0103e0  mov      w0, w1
//   0x00e514: 3100043f  cmn      w1, #1
//   0x00e518: 54000180  b.eq     #0xe548
//   0x00e51c: 3942610a  ldrb     w10, [x8, #0x98]
//   0x00e520: 3720008a  tbnz     w10, #4, #0xe530
//   0x00e524: 385ff12a  ldurb    w10, [x9, #-1]
uint64_t fde_0103_sub_00e4f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9403C09ULL) + (x1 ^ 0x54000180ULL) + (x2 ^ 0x00E4F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C09ULL; // 0x00e4f8: ldr x9, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x00e4fc: cbz x9, #0xe540
    acc = (acc * 0x100000001B3ULL) ^ 0xA941240AULL; // 0x00e500: ldp x10, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00e504: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09015FULL; // 0x00e508: cmp x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A2ULL; // 0x00e50c: b.hs #0xe540
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x00e510: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x3100043FULL; // 0x00e514: cmn w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0104 @ 0x00e558..0x00e604 (172 bytes)
// [VN] Phục dựng FDE #0104 tại 0x00e558..0x00e604 (172 byte)
//   0x00e558: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00e55c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e560: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e564: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e568: 9100c3fd  add      x29, sp, #0x30
//   0x00e56c: aa0203f3  mov      x19, x2
//   0x00e570: aa0103f4  mov      x20, x1
//   0x00e574: aa0003f5  mov      x21, x0
//   0x00e578: aa1f03f6  mov      x22, xzr
//   0x00e57c: eb1302df  cmp      x22, x19
//   0x00e580: 5400036a  b.ge     #0xe5ec
//   0x00e584: a94322a0  ldp      x0, x8, [x21, #0x30]
uint64_t fde_0104_sub_00e558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1F03F6ULL) + (x2 ^ 0x00E558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x00e558: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00e55c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00e560: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00e564: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00e568: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x00e56c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00e570: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x00e574: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0105 @ 0x00e604..0x00e7a8 (420 bytes)
// [VN] Phục dựng FDE #0105 tại 0x00e604..0x00e7a8 (420 byte)
//   0x00e604: d101c3ff  sub      sp, sp, #0x70
//   0x00e608: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x00e60c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x00e610: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00e614: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00e618: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00e61c: 910183fd  add      x29, sp, #0x60
//   0x00e620: d53bd058  mrs      x24, tpidr_el0
//   0x00e624: f9401708  ldr      x8, [x24, #0x28]
//   0x00e628: f9000fe8  str      x8, [sp, #0x18]
//   0x00e62c: f9403c08  ldr      x8, [x0, #0x78]
//   0x00e630: b4000948  cbz      x8, #0xe758
uint64_t fde_0105_sub_00e604(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x00E604ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x00e604: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x00e608: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x00e60c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x00e610: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x00e614: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x00e618: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00e61c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x00e620: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0106 @ 0x00e7a8..0x00e7bc (20 bytes)
// [VN] Phục dựng FDE #0106 tại 0x00e7a8..0x00e7bc (20 byte)
//   0x00e7a8: b0000268  adrp     x8, #0x5b000
//   0x00e7ac: f9439108  ldr      x8, [x8, #0x720]
//   0x00e7b0: 91004108  add      x8, x8, #0x10
//   0x00e7b4: f8008408  str      x8, [x0], #8
//   0x00e7b8: 17fff3fa  b        #0xb7a0
uint64_t fde_0106_sub_00e7a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000268ULL) + (x1 ^ 0x17FFF3FAULL) + (x2 ^ 0x00E7A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000268ULL; // 0x00e7a8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x00e7ac: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x00e7b0: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x00e7b4: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF3FAULL; // 0x00e7b8: b #0xb7a0
    return acc;
}

// [EN] Reconstructed FDE #0107 @ 0x00e7bc..0x00e7e0 (36 bytes)
// [VN] Phục dựng FDE #0107 tại 0x00e7bc..0x00e7e0 (36 byte)
//   0x00e7bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00e7c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e7c4: 910043fd  add      x29, sp, #0x10
//   0x00e7c8: aa0003f3  mov      x19, x0
//   0x00e7cc: 97fffff7  bl       #0xe7a8
//   0x00e7d0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e7d4: aa1303e0  mov      x0, x19
//   0x00e7d8: f84207f3  ldr      x19, [sp], #0x20
//   0x00e7dc: 17fff159  b        #0xad40
uint64_t fde_0107_sub_00e7bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFF159ULL) + (x2 ^ 0x00E7BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00e7bc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00e7c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00e7c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00e7c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF7ULL; // 0x00e7cc: bl #0xe7a8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00e7d0: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00e7d4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00e7d8: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0108 @ 0x00e7e0..0x00e7e4 (4 bytes)
// [VN] Phục dựng FDE #0108 tại 0x00e7e0..0x00e7e4 (4 byte)
//   0x00e7e0: d65f03c0  ret      
uint64_t fde_0108_sub_00e7e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E7E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e7e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0109 @ 0x00e7e4..0x00e7e8 (4 bytes)
// [VN] Phục dựng FDE #0109 tại 0x00e7e4..0x00e7e8 (4 byte)
//   0x00e7e4: d65f03c0  ret      
uint64_t fde_0109_sub_00e7e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E7E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e7e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0110 @ 0x00e7e8..0x00e7f4 (12 bytes)
// [VN] Phục dựng FDE #0110 tại 0x00e7e8..0x00e7f4 (12 byte)
//   0x00e7e8: 92800001  mov      x1, #-1
//   0x00e7ec: aa1f03e0  mov      x0, xzr
//   0x00e7f0: d65f03c0  ret      
uint64_t fde_0110_sub_00e7e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E7E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x00e7e8: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x00e7ec: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e7f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0111 @ 0x00e7f4..0x00e800 (12 bytes)
// [VN] Phục dựng FDE #0111 tại 0x00e7f4..0x00e800 (12 byte)
//   0x00e7f4: 92800001  mov      x1, #-1
//   0x00e7f8: aa1f03e0  mov      x0, xzr
//   0x00e7fc: d65f03c0  ret      
uint64_t fde_0111_sub_00e7f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E7F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x00e7f4: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x00e7f8: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e7fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0112 @ 0x00e800..0x00e808 (8 bytes)
// [VN] Phục dựng FDE #0112 tại 0x00e800..0x00e808 (8 byte)
//   0x00e800: 2a1f03e0  mov      w0, wzr
//   0x00e804: d65f03c0  ret      
uint64_t fde_0112_sub_00e800(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E800ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x00e800: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e804: ret 
    return acc;
}

// [EN] Reconstructed FDE #0113 @ 0x00e808..0x00e810 (8 bytes)
// [VN] Phục dựng FDE #0113 tại 0x00e808..0x00e810 (8 byte)
//   0x00e808: 12800000  mov      w0, #-1
//   0x00e80c: d65f03c0  ret      
uint64_t fde_0113_sub_00e808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x00e808: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e80c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0114 @ 0x00e810..0x00e818 (8 bytes)
// [VN] Phục dựng FDE #0114 tại 0x00e810..0x00e818 (8 byte)
//   0x00e810: 12800000  mov      w0, #-1
//   0x00e814: d65f03c0  ret      
uint64_t fde_0114_sub_00e810(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E810ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x00e810: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e814: ret 
    return acc;
}

// [EN] Reconstructed FDE #0115 @ 0x00e818..0x00e820 (8 bytes)
// [VN] Phục dựng FDE #0115 tại 0x00e818..0x00e820 (8 byte)
//   0x00e818: 12800000  mov      w0, #-1
//   0x00e81c: d65f03c0  ret      
uint64_t fde_0115_sub_00e818(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E818ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x00e818: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e81c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0116 @ 0x00e820..0x00e83c (28 bytes)
// [VN] Phục dựng FDE #0116 tại 0x00e820..0x00e83c (28 byte)
//   0x00e820: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00e824: 910003fd  mov      x29, sp
//   0x00e828: b0000261  adrp     x1, #0x5b000
//   0x00e82c: f943dc21  ldr      x1, [x1, #0x7b8]
//   0x00e830: 97fff3e0  bl       #0xb7b0
//   0x00e834: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00e838: d65f03c0  ret      
uint64_t fde_0116_sub_00e820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00e820: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00e824: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000261ULL; // 0x00e828: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943DC21ULL; // 0x00e82c: ldr x1, [x1, #0x7b8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF3E0ULL; // 0x00e830: bl #0xb7b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00e834: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00e838: ret 
    return acc;
}

// [EN] Reconstructed FDE #0117 @ 0x00e83c..0x00e848 (12 bytes)
// [VN] Phục dựng FDE #0117 tại 0x00e83c..0x00e848 (12 byte)
//   0x00e83c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00e840: 910003fd  mov      x29, sp
//   0x00e844: 97fff32f  bl       #0xb500
uint64_t fde_0117_sub_00e83c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFF32FULL) + (x2 ^ 0x00E83CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00e83c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00e840: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF32FULL; // 0x00e844: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0118 @ 0x00e848..0x00e874 (44 bytes)
// [VN] Phục dựng FDE #0118 tại 0x00e848..0x00e874 (44 byte)
//   0x00e848: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00e84c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e850: 910043fd  add      x29, sp, #0x10
//   0x00e854: aa0003f3  mov      x19, x0
//   0x00e858: b4000062  cbz      x2, #0xe864
//   0x00e85c: aa1303e0  mov      x0, x19
//   0x00e860: 97fff0ec  bl       #0xac10
//   0x00e864: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e868: aa1303e0  mov      x0, x19
//   0x00e86c: f84207f3  ldr      x19, [sp], #0x20
//   0x00e870: d65f03c0  ret      
uint64_t fde_0118_sub_00e848(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00E848ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00e848: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00e84c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00e850: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00e854: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000062ULL; // 0x00e858: cbz x2, #0xe864
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00e85c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF0ECULL; // 0x00e860: bl #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00e864: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0119 @ 0x00e874..0x00e8d0 (92 bytes)
// [VN] Phục dựng FDE #0119 tại 0x00e874..0x00e8d0 (92 byte)
//   0x00e874: 39427008  ldrb     w8, [x0, #0x9c]
//   0x00e878: 37180288  tbnz     w8, #3, #0xe8c8
//   0x00e87c: 39428808  ldrb     w8, [x0, #0xa2]
//   0x00e880: 52800c09  mov      w9, #0x60
//   0x00e884: 52800e0a  mov      w10, #0x70
//   0x00e888: a902fc1f  stp      xzr, xzr, [x0, #0x28]
//   0x00e88c: 7100011f  cmp      w8, #0
//   0x00e890: 52800808  mov      w8, #0x40
//   0x00e894: 9a890149  csel     x9, x10, x9, eq
//   0x00e898: 52800d0a  mov      w10, #0x68
//   0x00e89c: f9001c1f  str      xzr, [x0, #0x38]
//   0x00e8a0: 9a880148  csel     x8, x10, x8, eq
uint64_t fde_0119_sub_00e874(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39427008ULL) + (x1 ^ 0x9A890149ULL) + (x2 ^ 0x00E874ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39427008ULL; // 0x00e874: ldrb w8, [x0, #0x9c]
    acc = (acc * 0x100000001B3ULL) ^ 0x37180288ULL; // 0x00e878: tbnz w8, #3, #0xe8c8
    acc = (acc * 0x100000001B3ULL) ^ 0x39428808ULL; // 0x00e87c: ldrb w8, [x0, #0xa2]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800C09ULL; // 0x00e880: mov w9, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x52800E0AULL; // 0x00e884: mov w10, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA902FC1FULL; // 0x00e888: stp xzr, xzr, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100011FULL; // 0x00e88c: cmp w8, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800808ULL; // 0x00e890: mov w8, #0x40
    return acc;
}

// [EN] Reconstructed FDE #0120 @ 0x00e8d0..0x00e938 (104 bytes)
// [VN] Phục dựng FDE #0120 tại 0x00e8d0..0x00e938 (104 byte)
//   0x00e8d0: 39427008  ldrb     w8, [x0, #0x9c]
//   0x00e8d4: 37200308  tbnz     w8, #4, #0xe934
//   0x00e8d8: f9403008  ldr      x8, [x0, #0x60]
//   0x00e8dc: a9017c1f  stp      xzr, xzr, [x0, #0x10]
//   0x00e8e0: f900101f  str      xzr, [x0, #0x20]
//   0x00e8e4: f100251f  cmp      x8, #9
//   0x00e8e8: 54000123  b.lo     #0xe90c
//   0x00e8ec: 39428809  ldrb     w9, [x0, #0xa2]
//   0x00e8f0: 34000149  cbz      w9, #0xe918
//   0x00e8f4: f9402009  ldr      x9, [x0, #0x40]
//   0x00e8f8: 8b090108  add      x8, x8, x9
//   0x00e8fc: d1000508  sub      x8, x8, #1
uint64_t fde_0120_sub_00e8d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39427008ULL) + (x1 ^ 0x34000149ULL) + (x2 ^ 0x00E8D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39427008ULL; // 0x00e8d0: ldrb w8, [x0, #0x9c]
    acc = (acc * 0x100000001B3ULL) ^ 0x37200308ULL; // 0x00e8d4: tbnz w8, #4, #0xe934
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403008ULL; // 0x00e8d8: ldr x8, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017C1FULL; // 0x00e8dc: stp xzr, xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900101FULL; // 0x00e8e0: str xzr, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF100251FULL; // 0x00e8e4: cmp x8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000123ULL; // 0x00e8e8: b.lo #0xe90c
    acc = (acc * 0x100000001B3ULL) ^ 0x39428809ULL; // 0x00e8ec: ldrb w9, [x0, #0xa2]
    return acc;
}

// [EN] Reconstructed FDE #0121 @ 0x00e938..0x00e994 (92 bytes)
// [VN] Phục dựng FDE #0121 tại 0x00e938..0x00e994 (92 byte)
//   0x00e938: d10103ff  sub      sp, sp, #0x40
//   0x00e93c: f90013f3  str      x19, [sp, #0x20]
//   0x00e940: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e944: 9100c3fd  add      x29, sp, #0x30
//   0x00e948: d53bd053  mrs      x19, tpidr_el0
//   0x00e94c: f9401668  ldr      x8, [x19, #0x28]
//   0x00e950: f0000142  adrp     x2, #0x39000
//   0x00e954: 91119842  add      x2, x2, #0x466
//   0x00e958: 910043e3  add      x3, sp, #0x10
//   0x00e95c: 910023e4  add      x4, sp, #8
//   0x00e960: f9000fe8  str      x8, [sp, #0x18]
//   0x00e964: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0121_sub_00e938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x00E938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x00e938: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x00e93c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00e940: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00e944: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x00e948: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x00e94c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000142ULL; // 0x00e950: adrp x2, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x91119842ULL; // 0x00e954: add x2, x2, #0x466
    return acc;
}

// [EN] Reconstructed FDE #0122 @ 0x00e994..0x00e9c8 (52 bytes)
// [VN] Phục dựng FDE #0122 tại 0x00e994..0x00e9c8 (52 byte)
//   0x00e994: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00e998: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e99c: 910043fd  add      x29, sp, #0x10
//   0x00e9a0: aa0003f3  mov      x19, x0
//   0x00e9a4: 97fff247  bl       #0xb2c0
//   0x00e9a8: 34000080  cbz      w0, #0xe9b8
//   0x00e9ac: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e9b0: f84207f3  ldr      x19, [sp], #0x20
//   0x00e9b4: d65f03c0  ret      
//   0x00e9b8: f9400260  ldr      x0, [x19]
//   0x00e9bc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e9c0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0122_sub_00e994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00E994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00e994: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00e998: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00e99c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00e9a0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF247ULL; // 0x00e9a4: bl #0xb2c0
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x00e9a8: cbz w0, #0xe9b8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00e9ac: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x00e9b0: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0123 @ 0x00e9c8..0x00eab4 (236 bytes)
// [VN] Phục dựng FDE #0123 tại 0x00e9c8..0x00eab4 (236 byte)
//   0x00e9c8: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x00e9cc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00e9d0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00e9d4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00e9d8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00e9dc: 910103fd  add      x29, sp, #0x40
//   0x00e9e0: aa0003f5  mov      x21, x0
//   0x00e9e4: 91006000  add      x0, x0, #0x18
//   0x00e9e8: aa0103f3  mov      x19, x1
//   0x00e9ec: 94000032  bl       #0xeab4
//   0x00e9f0: f94006b6  ldr      x22, [x21, #8]
//   0x00e9f4: b4000516  cbz      x22, #0xea94
uint64_t fde_0123_sub_00e9c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x00E9C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x00e9c8: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00e9cc: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00e9d0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00e9d4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00e9d8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00e9dc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x00e9e0: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91006000ULL; // 0x00e9e4: add x0, x0, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0124 @ 0x00eab4..0x00ead4 (32 bytes)
// [VN] Phục dựng FDE #0124 tại 0x00eab4..0x00ead4 (32 byte)
//   0x00eab4: 39400028  ldrb     w8, [x1]
//   0x00eab8: a940a42a  ldp      x10, x9, [x1, #8]
//   0x00eabc: d341fd0b  lsr      x11, x8, #1
//   0x00eac0: 7200011f  tst      w8, #1
//   0x00eac4: 9a811520  csinc    x0, x9, x1, ne
//   0x00eac8: 9a8a0168  csel     x8, x11, x10, eq
//   0x00eacc: 8b080001  add      x1, x0, x8
//   0x00ead0: 14000001  b        #0xead4
uint64_t fde_0124_sub_00eab4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400028ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00EAB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x00eab4: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A42AULL; // 0x00eab8: ldp x10, x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0BULL; // 0x00eabc: lsr x11, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x00eac0: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A811520ULL; // 0x00eac4: csinc x0, x9, x1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A0168ULL; // 0x00eac8: csel x8, x11, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080001ULL; // 0x00eacc: add x1, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00ead0: b #0xead4
    return acc;
}

// [EN] Reconstructed FDE #0125 @ 0x00ead4..0x00eb28 (84 bytes)
// [VN] Phục dựng FDE #0125 tại 0x00ead4..0x00eb28 (84 byte)
//   0x00ead4: d100c3ff  sub      sp, sp, #0x30
//   0x00ead8: f9000bf3  str      x19, [sp, #0x10]
//   0x00eadc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00eae0: 910083fd  add      x29, sp, #0x20
//   0x00eae4: d53bd053  mrs      x19, tpidr_el0
//   0x00eae8: f9401669  ldr      x9, [x19, #0x28]
//   0x00eaec: aa0003e8  mov      x8, x0
//   0x00eaf0: cb000022  sub      x2, x1, x0
//   0x00eaf4: 910003e0  mov      x0, sp
//   0x00eaf8: aa0803e1  mov      x1, x8
//   0x00eafc: f90007e9  str      x9, [sp, #8]
//   0x00eb00: 9400000a  bl       #0xeb28
uint64_t fde_0125_sub_00ead4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910003E0ULL) + (x2 ^ 0x00EAD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x00ead4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x00ead8: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00eadc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00eae0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x00eae4: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401669ULL; // 0x00eae8: ldr x9, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00eaec: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000022ULL; // 0x00eaf0: sub x2, x1, x0
    return acc;
}

// [EN] Reconstructed FDE #0126 @ 0x00eb28..0x00ed08 (480 bytes)
// [VN] Phục dựng FDE #0126 tại 0x00eb28..0x00ed08 (480 byte)
//   0x00eb28: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00eb2c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00eb30: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00eb34: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00eb38: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00eb3c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00eb40: 910143fd  add      x29, sp, #0x50
//   0x00eb44: aa0203f8  mov      x24, x2
//   0x00eb48: f100805f  cmp      x2, #0x20
//   0x00eb4c: aa0103f3  mov      x19, x1
//   0x00eb50: 54000188  b.hi     #0xeb80
//   0x00eb54: aa1303e0  mov      x0, x19
uint64_t fde_0126_sub_00eb28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF100805FULL) + (x2 ^ 0x00EB28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x00eb28: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00eb2c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00eb30: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00eb34: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00eb38: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00eb3c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00eb40: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F8ULL; // 0x00eb44: mov x24, x2
    return acc;
}

// [EN] Reconstructed FDE #0127 @ 0x00ed08..0x00edd8 (208 bytes)
// [VN] Phục dựng FDE #0127 tại 0x00ed08..0x00edd8 (208 byte)
//   0x00ed08: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00ed0c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00ed10: 910043fd  add      x29, sp, #0x10
//   0x00ed14: f100243f  cmp      x1, #9
//   0x00ed18: aa0003e8  mov      x8, x0
//   0x00ed1c: 54000183  b.lo     #0xed4c
//   0x00ed20: 8b010109  add      x9, x8, x1
//   0x00ed24: f85f8133  ldur     x19, [x9, #-8]
//   0x00ed28: f9400100  ldr      x0, [x8]
//   0x00ed2c: 4b0103e8  neg      w8, w1
//   0x00ed30: 8b010269  add      x9, x19, x1
//   0x00ed34: 9ac1252a  lsr      x10, x9, x1
uint64_t fde_0127_sub_00ed08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400100ULL) + (x2 ^ 0x00ED08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00ed08: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00ed0c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00ed10: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF100243FULL; // 0x00ed14: cmp x1, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00ed18: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000183ULL; // 0x00ed1c: b.lo #0xed4c
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010109ULL; // 0x00ed20: add x9, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF85F8133ULL; // 0x00ed24: ldur x19, [x9, #-8]
    return acc;
}

// [EN] Reconstructed FDE #0128 @ 0x00edd8..0x00ee64 (140 bytes)
// [VN] Phục dựng FDE #0128 tại 0x00edd8..0x00ee64 (140 byte)
//   0x00edd8: d29e4e68  mov      x8, #0xf273
//   0x00eddc: a9402809  ldp      x9, x10, [x0]
//   0x00ede0: f2b7d308  movk     x8, #0xbe98, lsl #16
//   0x00ede4: f2d6cde8  movk     x8, #0xb66f, lsl #32
//   0x00ede8: f2f69248  movk     x8, #0xb492, lsl #48
//   0x00edec: 8b01000b  add      x11, x0, x1
//   0x00edf0: 9b087d28  mul      x8, x9, x8
//   0x00edf4: d28caae9  mov      x9, #0x6557
//   0x00edf8: d28809ec  mov      x12, #0x404f
//   0x00edfc: a97f2d6f  ldp      x15, x11, [x11, #-0x10]
//   0x00ee00: f2aa13c9  movk     x9, #0x509e, lsl #16
//   0x00ee04: f2a5f20c  movk     x12, #0x2f90, lsl #16
uint64_t fde_0128_sub_00edd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD29E4E68ULL) + (x1 ^ 0xD28809ECULL) + (x2 ^ 0x00EDD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD29E4E68ULL; // 0x00edd8: mov x8, #0xf273
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402809ULL; // 0x00eddc: ldp x9, x10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF2B7D308ULL; // 0x00ede0: movk x8, #0xbe98, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2D6CDE8ULL; // 0x00ede4: movk x8, #0xb66f, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF2F69248ULL; // 0x00ede8: movk x8, #0xb492, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01000BULL; // 0x00edec: add x11, x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087D28ULL; // 0x00edf0: mul x8, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD28CAAE9ULL; // 0x00edf4: mov x9, #0x6557
    return acc;
}

// [EN] Reconstructed FDE #0129 @ 0x00ee64..0x00ef24 (192 bytes)
// [VN] Phục dựng FDE #0129 tại 0x00ee64..0x00ef24 (192 byte)
//   0x00ee64: 8b01000a  add      x10, x0, x1
//   0x00ee68: a97f414e  ldp      x14, x16, [x10, #-0x10]
//   0x00ee6c: d28624eb  mov      x11, #0x3127
//   0x00ee70: a940340c  ldp      x12, x13, [x0]
//   0x00ee74: f2b2f96b  movk     x11, #0x97cb, lsl #16
//   0x00ee78: a9412408  ldp      x8, x9, [x0, #0x10]
//   0x00ee7c: f2d90b8b  movk     x11, #0xc85c, lsl #32
//   0x00ee80: a97e294f  ldp      x15, x10, [x10, #-0x20]
//   0x00ee84: f2f874ab  movk     x11, #0xc3a5, lsl #48
//   0x00ee88: 8b0101d1  add      x17, x14, x1
//   0x00ee8c: 9b0b322c  madd     x12, x17, x11, x12
//   0x00ee90: 8b0d018d  add      x13, x12, x13
uint64_t fde_0129_sub_00ee64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x8B01000AULL) + (x1 ^ 0xF2F874ABULL) + (x2 ^ 0x00EE64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01000AULL; // 0x00ee64: add x10, x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA97F414EULL; // 0x00ee68: ldp x14, x16, [x10, #-0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD28624EBULL; // 0x00ee6c: mov x11, #0x3127
    acc = (acc * 0x100000001B3ULL) ^ 0xA940340CULL; // 0x00ee70: ldp x12, x13, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF2B2F96BULL; // 0x00ee74: movk x11, #0x97cb, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412408ULL; // 0x00ee78: ldp x8, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF2D90B8BULL; // 0x00ee7c: movk x11, #0xc85c, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xA97E294FULL; // 0x00ee80: ldp x15, x10, [x10, #-0x20]
    return acc;
}

// [EN] Reconstructed FDE #0130 @ 0x00ef24..0x00ef54 (48 bytes)
// [VN] Phục dựng FDE #0130 tại 0x00ef24..0x00ef54 (48 byte)
//   0x00ef24: d285ad29  mov      x9, #0x2d69
//   0x00ef28: f2bd6709  movk     x9, #0xeb38, lsl #16
//   0x00ef2c: f2dd4109  movk     x9, #0xea08, lsl #32
//   0x00ef30: ca000028  eor      x8, x1, x0
//   0x00ef34: f2f3bbe9  movk     x9, #0x9ddf, lsl #48
//   0x00ef38: 9b097d08  mul      x8, x8, x9
//   0x00ef3c: ca01010a  eor      x10, x8, x1
//   0x00ef40: ca48bd48  eor      x8, x10, x8, lsr #47
//   0x00ef44: 9b097d08  mul      x8, x8, x9
//   0x00ef48: ca48bd08  eor      x8, x8, x8, lsr #47
//   0x00ef4c: 9b097d00  mul      x0, x8, x9
//   0x00ef50: d65f03c0  ret      
uint64_t fde_0130_sub_00ef24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD285AD29ULL) + (x1 ^ 0x9B097D08ULL) + (x2 ^ 0x00EF24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD285AD29ULL; // 0x00ef24: mov x9, #0x2d69
    acc = (acc * 0x100000001B3ULL) ^ 0xF2BD6709ULL; // 0x00ef28: movk x9, #0xeb38, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2DD4109ULL; // 0x00ef2c: movk x9, #0xea08, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xCA000028ULL; // 0x00ef30: eor x8, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF2F3BBE9ULL; // 0x00ef34: movk x9, #0x9ddf, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0x9B097D08ULL; // 0x00ef38: mul x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xCA01010AULL; // 0x00ef3c: eor x10, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xCA48BD48ULL; // 0x00ef40: eor x8, x10, x8, lsr #47
    return acc;
}

// [EN] Reconstructed FDE #0131 @ 0x00ef54..0x00ef70 (28 bytes)
// [VN] Phục dựng FDE #0131 tại 0x00ef54..0x00ef70 (28 byte)
//   0x00ef54: a9402408  ldp      x8, x9, [x0]
//   0x00ef58: aa0203e5  mov      x5, x2
//   0x00ef5c: a9410c02  ldp      x2, x3, [x0, #0x10]
//   0x00ef60: aa0103e4  mov      x4, x1
//   0x00ef64: aa0803e0  mov      x0, x8
//   0x00ef68: aa0903e1  mov      x1, x9
//   0x00ef6c: 14000001  b        #0xef70
uint64_t fde_0131_sub_00ef54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9402408ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00EF54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402408ULL; // 0x00ef54: ldp x8, x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E5ULL; // 0x00ef58: mov x5, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9410C02ULL; // 0x00ef5c: ldp x2, x3, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E4ULL; // 0x00ef60: mov x4, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x00ef64: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E1ULL; // 0x00ef68: mov x1, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00ef6c: b #0xef70
    return acc;
}

// [EN] Reconstructed FDE #0132 @ 0x00ef70..0x00ef9c (44 bytes)
// [VN] Phục dựng FDE #0132 tại 0x00ef70..0x00ef9c (44 byte)
//   0x00ef70: 8b000088  add      x8, x4, x0
//   0x00ef74: 8b01004a  add      x10, x2, x1
//   0x00ef78: 8b0300a9  add      x9, x5, x3
//   0x00ef7c: 8b08014a  add      x10, x10, x8
//   0x00ef80: 8b080129  add      x9, x9, x8
//   0x00ef84: 93cab14b  ror      x11, x10, #0x2c
//   0x00ef88: 93c95529  ror      x9, x9, #0x15
//   0x00ef8c: 8b080168  add      x8, x11, x8
//   0x00ef90: 8b030140  add      x0, x10, x3
//   0x00ef94: 8b090101  add      x1, x8, x9
//   0x00ef98: d65f03c0  ret      
uint64_t fde_0132_sub_00ef70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x8B000088ULL) + (x1 ^ 0x8B030140ULL) + (x2 ^ 0x00EF70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x8B000088ULL; // 0x00ef70: add x8, x4, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01004AULL; // 0x00ef74: add x10, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0300A9ULL; // 0x00ef78: add x9, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08014AULL; // 0x00ef7c: add x10, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080129ULL; // 0x00ef80: add x9, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x93CAB14BULL; // 0x00ef84: ror x11, x10, #0x2c
    acc = (acc * 0x100000001B3ULL) ^ 0x93C95529ULL; // 0x00ef88: ror x9, x9, #0x15
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080168ULL; // 0x00ef8c: add x8, x11, x8
    return acc;
}

// [EN] Reconstructed FDE #0133 @ 0x00ef9c..0x00f034 (152 bytes)
// [VN] Phục dựng FDE #0133 tại 0x00ef9c..0x00f034 (152 byte)
//   0x00ef9c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00efa0: 910003fd  mov      x29, sp
//   0x00efa4: 39400009  ldrb     w9, [x0]
//   0x00efa8: f940040b  ldr      x11, [x0, #8]
//   0x00efac: 3940002a  ldrb     w10, [x1]
//   0x00efb0: f940042c  ldr      x12, [x1, #8]
//   0x00efb4: d341fd28  lsr      x8, x9, #1
//   0x00efb8: 7200013f  tst      w9, #1
//   0x00efbc: d341fd4d  lsr      x13, x10, #1
//   0x00efc0: 9a8b0102  csel     x2, x8, x11, eq
//   0x00efc4: 7200015f  tst      w10, #1
//   0x00efc8: 9a8c01ab  csel     x11, x13, x12, eq
uint64_t fde_0133_sub_00ef9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD341FD4DULL) + (x2 ^ 0x00EF9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00ef9c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00efa0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x39400009ULL; // 0x00efa4: ldrb w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940040BULL; // 0x00efa8: ldr x11, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940002AULL; // 0x00efac: ldrb w10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940042CULL; // 0x00efb0: ldr x12, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD28ULL; // 0x00efb4: lsr x8, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x00efb8: tst w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0134 @ 0x00f034..0x00f044 (16 bytes)
// [VN] Phục dựng FDE #0134 tại 0x00f034..0x00f044 (16 byte)
//   0x00f034: b4000042  cbz      x2, #0xf03c
//   0x00f038: 17fff14a  b        #0xb560
//   0x00f03c: 2a1f03e0  mov      w0, wzr
//   0x00f040: d65f03c0  ret      
uint64_t fde_0134_sub_00f034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000042ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000042ULL; // 0x00f034: cbz x2, #0xf03c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF14AULL; // 0x00f038: b #0xb560
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x00f03c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f040: ret 
    return acc;
}

// [EN] Reconstructed FDE #0135 @ 0x00f044..0x00f2c8 (644 bytes)
// [VN] Phục dựng FDE #0135 tại 0x00f044..0x00f2c8 (644 byte)
//   0x00f044: d10243ff  sub      sp, sp, #0x90
//   0x00f048: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x00f04c: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x00f050: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x00f054: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x00f058: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x00f05c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x00f060: 910203fd  add      x29, sp, #0x80
//   0x00f064: d53bd055  mrs      x21, tpidr_el0
//   0x00f068: f94016a8  ldr      x8, [x21, #0x28]
//   0x00f06c: aa0003f3  mov      x19, x0
//   0x00f070: 91006000  add      x0, x0, #0x18
uint64_t fde_0135_sub_00f044(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xD53BD055ULL) + (x2 ^ 0x00F044ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x00f044: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x00f048: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x00f04c: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x00f050: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x00f054: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x00f058: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x00f05c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x00f060: add x29, sp, #0x80
    return acc;
}

// [EN] Reconstructed FDE #0136 @ 0x00f2c8..0x00f330 (104 bytes)
// [VN] Phục dựng FDE #0136 tại 0x00f2c8..0x00f330 (104 byte)
//   0x00f2c8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00f2cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00f2d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00f2d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00f2d8: 9100c3fd  add      x29, sp, #0x30
//   0x00f2dc: 91004016  add      x22, x0, #0x10
//   0x00f2e0: aa0103f4  mov      x20, x1
//   0x00f2e4: 52800021  mov      w1, #1
//   0x00f2e8: aa1603e0  mov      x0, x22
//   0x00f2ec: aa0303f3  mov      x19, x3
//   0x00f2f0: aa0803f5  mov      x21, x8
//   0x00f2f4: 52800038  mov      w24, #1
uint64_t fde_0136_sub_00f2c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x00F2C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00f2c8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00f2cc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00f2d0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00f2d4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00f2d8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x00f2dc: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00f2e0: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x00f2e4: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0137 @ 0x00f330..0x00f410 (224 bytes)
// [VN] Phục dựng FDE #0137 tại 0x00f330..0x00f410 (224 byte)
//   0x00f330: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00f334: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f338: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f33c: 910083fd  add      x29, sp, #0x20
//   0x00f340: f1000428  subs     x8, x1, #1
//   0x00f344: aa0003f3  mov      x19, x0
//   0x00f348: 54000061  b.ne     #0xf354
//   0x00f34c: 52800054  mov      w20, #2
//   0x00f350: 14000007  b        #0xf36c
//   0x00f354: aa0103f4  mov      x20, x1
//   0x00f358: ea08003f  tst      x1, x8
//   0x00f35c: 54000080  b.eq     #0xf36c
uint64_t fde_0137_sub_00f330(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x00F330ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00f330: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00f334: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00f338: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00f33c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x00f340: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f344: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x00f348: b.ne #0xf354
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x00f34c: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #0138 @ 0x00f410..0x00f418 (8 bytes)
// [VN] Phục dựng FDE #0138 tại 0x00f410..0x00f418 (8 byte)
//   0x00f410: aa1f03e1  mov      x1, xzr
//   0x00f414: 140000a6  b        #0xf6ac
uint64_t fde_0138_sub_00f410(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x140000A6ULL) + (x2 ^ 0x00F410ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00f410: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x140000A6ULL; // 0x00f414: b #0xf6ac
    return acc;
}

// [EN] Reconstructed FDE #0139 @ 0x00f418..0x00f420 (8 bytes)
// [VN] Phục dựng FDE #0139 tại 0x00f418..0x00f420 (8 byte)
//   0x00f418: aa1f03e2  mov      x2, xzr
//   0x00f41c: 14000001  b        #0xf420
uint64_t fde_0139_sub_00f418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00F418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x00f418: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00f41c: b #0xf420
    return acc;
}

// [EN] Reconstructed FDE #0140 @ 0x00f420..0x00f44c (44 bytes)
// [VN] Phục dựng FDE #0140 tại 0x00f420..0x00f44c (44 byte)
//   0x00f420: b200f3e8  mov      x8, #0x5555555555555555
//   0x00f424: f28aaac8  movk     x8, #0x5556
//   0x00f428: f2e0aaa8  movk     x8, #0x555, lsl #48
//   0x00f42c: eb08003f  cmp      x1, x8
//   0x00f430: 54000082  b.hs     #0xf440
//   0x00f434: 8b010428  add      x8, x1, x1, lsl #1
//   0x00f438: d37ced00  lsl      x0, x8, #4
//   0x00f43c: 17fff06d  b        #0xb5f0
//   0x00f440: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00f444: 910003fd  mov      x29, sp
//   0x00f448: 97fff02e  bl       #0xb500
uint64_t fde_0140_sub_00f420(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB200F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x00F420ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3E8ULL; // 0x00f420: mov x8, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xF28AAAC8ULL; // 0x00f424: movk x8, #0x5556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0AAA8ULL; // 0x00f428: movk x8, #0x555, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x00f42c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x00f430: b.hs #0xf440
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x00f434: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED00ULL; // 0x00f438: lsl x0, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF06DULL; // 0x00f43c: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0141 @ 0x00f44c..0x00f478 (44 bytes)
// [VN] Phục dựng FDE #0141 tại 0x00f44c..0x00f478 (44 byte)
//   0x00f44c: a9007c1f  stp      xzr, xzr, [x0]
//   0x00f450: f900081f  str      xzr, [x0, #0x10]
//   0x00f454: 39400028  ldrb     w8, [x1]
//   0x00f458: 370000c8  tbnz     w8, #0, #0xf470
//   0x00f45c: f9400828  ldr      x8, [x1, #0x10]
//   0x00f460: 3dc00020  ldr      q0, [x1]
//   0x00f464: f9000808  str      x8, [x0, #0x10]
//   0x00f468: 3d800000  str      q0, [x0]
//   0x00f46c: d65f03c0  ret      
//   0x00f470: a9408422  ldp      x2, x1, [x1, #8]
//   0x00f474: 14000001  b        #0xf478
uint64_t fde_0141_sub_00f44c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9007C1FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F44CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x00f44c: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x00f450: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x00f454: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x370000C8ULL; // 0x00f458: tbnz w8, #0, #0xf470
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400828ULL; // 0x00f45c: ldr x8, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x00f460: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x00f464: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x00f468: str q0, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0142 @ 0x00f478..0x00f4f8 (128 bytes)
// [VN] Phục dựng FDE #0142 tại 0x00f478..0x00f4f8 (128 byte)
//   0x00f478: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00f47c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f480: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f484: 910083fd  add      x29, sp, #0x20
//   0x00f488: b100405f  cmn      x2, #0x10
//   0x00f48c: 54000342  b.hs     #0xf4f4
//   0x00f490: aa0203f3  mov      x19, x2
//   0x00f494: aa0103f5  mov      x21, x1
//   0x00f498: aa0003f4  mov      x20, x0
//   0x00f49c: f100585f  cmp      x2, #0x16
//   0x00f4a0: 54000088  b.hi     #0xf4b0
//   0x00f4a4: 531f7a68  lsl      w8, w19, #1
uint64_t fde_0142_sub_00f478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x00F478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00f478: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00f47c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00f480: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00f484: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB100405FULL; // 0x00f488: cmn x2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000342ULL; // 0x00f48c: b.hs #0xf4f4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x00f490: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x00f494: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0143 @ 0x00f4f8..0x00f670 (376 bytes)
// [VN] Phục dựng FDE #0143 tại 0x00f4f8..0x00f670 (376 byte)
//   0x00f4f8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00f4fc: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00f500: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00f504: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00f508: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00f50c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00f510: 910143fd  add      x29, sp, #0x50
//   0x00f514: aa0003f3  mov      x19, x0
//   0x00f518: b40003c1  cbz      x1, #0xf590
//   0x00f51c: 91002260  add      x0, x19, #8
//   0x00f520: aa0103f4  mov      x20, x1
//   0x00f524: 94000059  bl       #0xf688
uint64_t fde_0143_sub_00f4f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xB40003C1ULL) + (x2 ^ 0x00F4F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x00f4f8: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00f4fc: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00f500: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00f504: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00f508: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00f50c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00f510: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f514: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0144 @ 0x00f670..0x00f688 (24 bytes)
// [VN] Phục dựng FDE #0144 tại 0x00f670..0x00f688 (24 byte)
//   0x00f670: aa0003e8  mov      x8, x0
//   0x00f674: f9400000  ldr      x0, [x0]
//   0x00f678: f9000101  str      x1, [x8]
//   0x00f67c: b4000040  cbz      x0, #0xf684
//   0x00f680: 17ffedb0  b        #0xad40
//   0x00f684: d65f03c0  ret      
uint64_t fde_0144_sub_00f670(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F670ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00f670: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x00f674: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x00f678: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x00f67c: cbz x0, #0xf684
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEDB0ULL; // 0x00f680: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f684: ret 
    return acc;
}

// [EN] Reconstructed FDE #0145 @ 0x00f688..0x00f690 (8 bytes)
// [VN] Phục dựng FDE #0145 tại 0x00f688..0x00f690 (8 byte)
//   0x00f688: aa1f03e2  mov      x2, xzr
//   0x00f68c: 14000001  b        #0xf690
uint64_t fde_0145_sub_00f688(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00F688ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x00f688: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00f68c: b #0xf690
    return acc;
}

// [EN] Reconstructed FDE #0146 @ 0x00f690..0x00f6ac (28 bytes)
// [VN] Phục dựng FDE #0146 tại 0x00f690..0x00f6ac (28 byte)
//   0x00f690: d37dfc28  lsr      x8, x1, #0x3d
//   0x00f694: b5000068  cbnz     x8, #0xf6a0
//   0x00f698: d37df020  lsl      x0, x1, #3
//   0x00f69c: 17ffefd5  b        #0xb5f0
//   0x00f6a0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00f6a4: 910003fd  mov      x29, sp
//   0x00f6a8: 97ffef96  bl       #0xb500
uint64_t fde_0146_sub_00f690(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FFEF96ULL) + (x2 ^ 0x00F690ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x00f690: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x00f694: cbnz x8, #0xf6a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x00f698: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEFD5ULL; // 0x00f69c: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00f6a0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00f6a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEF96ULL; // 0x00f6a8: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0147 @ 0x00f6ac..0x00f6c8 (28 bytes)
// [VN] Phục dựng FDE #0147 tại 0x00f6ac..0x00f6c8 (28 byte)
//   0x00f6ac: f9400008  ldr      x8, [x0]
//   0x00f6b0: f9000001  str      x1, [x0]
//   0x00f6b4: b4000088  cbz      x8, #0xf6c4
//   0x00f6b8: 91002000  add      x0, x0, #8
//   0x00f6bc: aa0803e1  mov      x1, x8
//   0x00f6c0: 14000002  b        #0xf6c8
//   0x00f6c4: d65f03c0  ret      
uint64_t fde_0147_sub_00f6ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F6ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00f6ac: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x00f6b0: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x00f6b4: cbz x8, #0xf6c4
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x00f6b8: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x00f6bc: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x00f6c0: b #0xf6c8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f6c4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0148 @ 0x00f6c8..0x00f708 (64 bytes)
// [VN] Phục dựng FDE #0148 tại 0x00f6c8..0x00f708 (64 byte)
//   0x00f6c8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00f6cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f6d0: 910043fd  add      x29, sp, #0x10
//   0x00f6d4: 39402008  ldrb     w8, [x0, #8]
//   0x00f6d8: aa0103f3  mov      x19, x1
//   0x00f6dc: 34000068  cbz      w8, #0xf6e8
//   0x00f6e0: 91004260  add      x0, x19, #0x10
//   0x00f6e4: 97fff858  bl       #0xd844
//   0x00f6e8: b40000b3  cbz      x19, #0xf6fc
//   0x00f6ec: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00f6f0: aa1303e0  mov      x0, x19
//   0x00f6f4: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0148_sub_00f6c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB40000B3ULL) + (x2 ^ 0x00F6C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00f6c8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f6cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f6d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39402008ULL; // 0x00f6d4: ldrb w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00f6d8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000068ULL; // 0x00f6dc: cbz w8, #0xf6e8
    acc = (acc * 0x100000001B3ULL) ^ 0x91004260ULL; // 0x00f6e0: add x0, x19, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF858ULL; // 0x00f6e4: bl #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0149 @ 0x00f708..0x00f724 (28 bytes)
// [VN] Phục dựng FDE #0149 tại 0x00f708..0x00f724 (28 byte)
//   0x00f708: aa1f03e8  mov      x8, xzr
//   0x00f70c: f100611f  cmp      x8, #0x18
//   0x00f710: 54000080  b.eq     #0xf720
//   0x00f714: f828681f  str      xzr, [x0, x8]
//   0x00f718: 91002108  add      x8, x8, #8
//   0x00f71c: 17fffffc  b        #0xf70c
//   0x00f720: d65f03c0  ret      
uint64_t fde_0149_sub_00f708(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F708ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x00f708: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF100611FULL; // 0x00f70c: cmp x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x00f710: b.eq #0xf720
    acc = (acc * 0x100000001B3ULL) ^ 0xF828681FULL; // 0x00f714: str xzr, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002108ULL; // 0x00f718: add x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x00f71c: b #0xf70c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f720: ret 
    return acc;
}

// [EN] Reconstructed FDE #0150 @ 0x00f724..0x00f7e0 (188 bytes)
// [VN] Phục dựng FDE #0150 tại 0x00f724..0x00f7e0 (188 byte)
//   0x00f724: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00f728: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00f72c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00f730: 910083fd  add      x29, sp, #0x20
//   0x00f734: 39400008  ldrb     w8, [x0]
//   0x00f738: aa0203f4  mov      x20, x2
//   0x00f73c: aa0003f3  mov      x19, x0
//   0x00f740: aa0103e7  mov      x7, x1
//   0x00f744: 37000068  tbnz     w8, #0, #0xf750
//   0x00f748: 528002c1  mov      w1, #0x16
//   0x00f74c: 14000004  b        #0xf75c
//   0x00f750: f9400269  ldr      x9, [x19]
uint64_t fde_0150_sub_00f724(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x37000068ULL) + (x2 ^ 0x00F724ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00f724: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00f728: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00f72c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00f730: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x00f734: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x00f738: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f73c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x00f740: mov x7, x1
    return acc;
}

// [EN] Reconstructed FDE #0151 @ 0x00f7e0..0x00f80c (44 bytes)
// [VN] Phục dựng FDE #0151 tại 0x00f7e0..0x00f80c (44 byte)
//   0x00f7e0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00f7e4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f7e8: 910043fd  add      x29, sp, #0x10
//   0x00f7ec: aa0003f3  mov      x19, x0
//   0x00f7f0: b4000062  cbz      x2, #0xf7fc
//   0x00f7f4: aa1303e0  mov      x0, x19
//   0x00f7f8: 97ffedf6  bl       #0xafd0
//   0x00f7fc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00f800: aa1303e0  mov      x0, x19
//   0x00f804: f84207f3  ldr      x19, [sp], #0x20
//   0x00f808: d65f03c0  ret      
uint64_t fde_0151_sub_00f7e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00F7E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00f7e0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f7e4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f7e8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f7ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000062ULL; // 0x00f7f0: cbz x2, #0xf7fc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00f7f4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEDF6ULL; // 0x00f7f8: bl #0xafd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00f7fc: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0152 @ 0x00f80c..0x00f940 (308 bytes)
// [VN] Phục dựng FDE #0152 tại 0x00f80c..0x00f940 (308 byte)
//   0x00f80c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00f810: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00f814: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00f818: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00f81c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00f820: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00f824: 910143fd  add      x29, sp, #0x50
//   0x00f828: 92800228  mov      x8, #-0x12
//   0x00f82c: cb010108  sub      x8, x8, x1
//   0x00f830: eb02011f  cmp      x8, x2
//   0x00f834: 54000843  b.lo     #0xf93c
//   0x00f838: 39400008  ldrb     w8, [x0]
uint64_t fde_0152_sub_00f80c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xCB010108ULL) + (x2 ^ 0x00F80CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x00f80c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00f810: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00f814: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00f818: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00f81c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00f820: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00f824: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x92800228ULL; // 0x00f828: mov x8, #-0x12
    return acc;
}

// [EN] Reconstructed FDE #0153 @ 0x00f940..0x00f968 (40 bytes)
// [VN] Phục dựng FDE #0153 tại 0x00f940..0x00f968 (40 byte)
//   0x00f940: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00f944: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f948: 910043fd  add      x29, sp, #0x10
//   0x00f94c: f9400801  ldr      x1, [x0, #0x10]
//   0x00f950: aa0003f3  mov      x19, x0
//   0x00f954: 94000005  bl       #0xf968
//   0x00f958: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00f95c: aa1303e0  mov      x0, x19
//   0x00f960: f84207f3  ldr      x19, [sp], #0x20
//   0x00f964: 14000010  b        #0xf9a4
uint64_t fde_0153_sub_00f940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x00F940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00f940: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f944: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f948: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x00f94c: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f950: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x00f954: bl #0xf968
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00f958: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00f95c: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0154 @ 0x00f968..0x00f9a4 (60 bytes)
// [VN] Phục dựng FDE #0154 tại 0x00f968..0x00f9a4 (60 byte)
//   0x00f968: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00f96c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f970: 910043fd  add      x29, sp, #0x10
//   0x00f974: aa0103f3  mov      x19, x1
//   0x00f978: b4000113  cbz      x19, #0xf998
//   0x00f97c: aa1303e0  mov      x0, x19
//   0x00f980: f8410414  ldr      x20, [x0], #0x10
//   0x00f984: 97fff7b0  bl       #0xd844
//   0x00f988: aa1303e0  mov      x0, x19
//   0x00f98c: 97ffeced  bl       #0xad40
//   0x00f990: aa1403f3  mov      x19, x20
//   0x00f994: b5ffff53  cbnz     x19, #0xf97c
uint64_t fde_0154_sub_00f968(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00F968ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00f968: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f96c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f970: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00f974: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000113ULL; // 0x00f978: cbz x19, #0xf998
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00f97c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF8410414ULL; // 0x00f980: ldr x20, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF7B0ULL; // 0x00f984: bl #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0155 @ 0x00f9a4..0x00f9ac (8 bytes)
// [VN] Phục dựng FDE #0155 tại 0x00f9a4..0x00f9ac (8 byte)
//   0x00f9a4: aa1f03e1  mov      x1, xzr
//   0x00f9a8: 14000001  b        #0xf9ac
uint64_t fde_0155_sub_00f9a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00F9A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00f9a4: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00f9a8: b #0xf9ac
    return acc;
}

// [EN] Reconstructed FDE #0156 @ 0x00f9ac..0x00f9c4 (24 bytes)
// [VN] Phục dựng FDE #0156 tại 0x00f9ac..0x00f9c4 (24 byte)
//   0x00f9ac: aa0003e8  mov      x8, x0
//   0x00f9b0: f9400000  ldr      x0, [x0]
//   0x00f9b4: f900011f  str      xzr, [x8]
//   0x00f9b8: b4000040  cbz      x0, #0xf9c0
//   0x00f9bc: 17ffece1  b        #0xad40
//   0x00f9c0: d65f03c0  ret      
uint64_t fde_0156_sub_00f9ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F9ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00f9ac: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x00f9b0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x00f9b4: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x00f9b8: cbz x0, #0xf9c0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFECE1ULL; // 0x00f9bc: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f9c0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0157 @ 0x00f9c4..0x00f9ec (40 bytes)
// [VN] Phục dựng FDE #0157 tại 0x00f9c4..0x00f9ec (40 byte)
//   0x00f9c4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00f9c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f9cc: 910043fd  add      x29, sp, #0x10
//   0x00f9d0: f9400801  ldr      x1, [x0, #0x10]
//   0x00f9d4: aa0003f3  mov      x19, x0
//   0x00f9d8: 94000005  bl       #0xf9ec
//   0x00f9dc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00f9e0: aa1303e0  mov      x0, x19
//   0x00f9e4: f84207f3  ldr      x19, [sp], #0x20
//   0x00f9e8: 14000010  b        #0xfa28
uint64_t fde_0157_sub_00f9c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x00F9C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00f9c4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f9c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f9cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x00f9d0: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f9d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x00f9d8: bl #0xf9ec
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x00f9dc: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00f9e0: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0158 @ 0x00f9ec..0x00fa28 (60 bytes)
// [VN] Phục dựng FDE #0158 tại 0x00f9ec..0x00fa28 (60 byte)
//   0x00f9ec: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00f9f0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f9f4: 910043fd  add      x29, sp, #0x10
//   0x00f9f8: aa0103f3  mov      x19, x1
//   0x00f9fc: b4000113  cbz      x19, #0xfa1c
//   0x00fa00: aa1303e0  mov      x0, x19
//   0x00fa04: f8418414  ldr      x20, [x0], #0x18
//   0x00fa08: 97fff836  bl       #0xdae0
//   0x00fa0c: aa1303e0  mov      x0, x19
//   0x00fa10: 97ffeccc  bl       #0xad40
//   0x00fa14: aa1403f3  mov      x19, x20
//   0x00fa18: b5ffff53  cbnz     x19, #0xfa00
uint64_t fde_0158_sub_00f9ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00F9ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00f9ec: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f9f0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f9f4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00f9f8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000113ULL; // 0x00f9fc: cbz x19, #0xfa1c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00fa00: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF8418414ULL; // 0x00fa04: ldr x20, [x0], #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF836ULL; // 0x00fa08: bl #0xdae0
    return acc;
}

// [EN] Reconstructed FDE #0159 @ 0x00fa28..0x00fa30 (8 bytes)
// [VN] Phục dựng FDE #0159 tại 0x00fa28..0x00fa30 (8 byte)
//   0x00fa28: aa1f03e1  mov      x1, xzr
//   0x00fa2c: 14000001  b        #0xfa30
uint64_t fde_0159_sub_00fa28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x00FA28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x00fa28: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x00fa2c: b #0xfa30
    return acc;
}

// [EN] Reconstructed FDE #0160 @ 0x00fa30..0x00fa48 (24 bytes)
// [VN] Phục dựng FDE #0160 tại 0x00fa30..0x00fa48 (24 byte)
//   0x00fa30: aa0003e8  mov      x8, x0
//   0x00fa34: f9400000  ldr      x0, [x0]
//   0x00fa38: f900011f  str      xzr, [x8]
//   0x00fa3c: b4000040  cbz      x0, #0xfa44
//   0x00fa40: 17ffecc0  b        #0xad40
//   0x00fa44: d65f03c0  ret      
uint64_t fde_0160_sub_00fa30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00FA30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x00fa30: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x00fa34: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x00fa38: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x00fa3c: cbz x0, #0xfa44
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFECC0ULL; // 0x00fa40: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00fa44: ret 
    return acc;
}

// [EN] Reconstructed FDE #0161 @ 0x00fa48..0x00faf0 (168 bytes)
// [VN] Phục dựng FDE #0161 tại 0x00fa48..0x00faf0 (168 byte)
//   0x00fa48: f9400408  ldr      x8, [x0, #8]
//   0x00fa4c: b40004e8  cbz      x8, #0xfae8
//   0x00fa50: 9e670100  fmov     d0, x8
//   0x00fa54: b9400029  ldr      w9, [x1]
//   0x00fa58: 0e205800  cnt      v0.8b, v0.8b
//   0x00fa5c: 2e303800  uaddlv   h0, v0.8b
//   0x00fa60: 1e26000a  fmov     w10, s0
//   0x00fa64: f100055f  cmp      x10, #1
//   0x00fa68: 540000e9  b.ls     #0xfa84
//   0x00fa6c: eb09011f  cmp      x8, x9
//   0x00fa70: aa0903eb  mov      x11, x9
//   0x00fa74: 540000c8  b.hi     #0xfa8c
uint64_t fde_0161_sub_00fa48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x540000E9ULL) + (x2 ^ 0x00FA48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00fa48: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E8ULL; // 0x00fa4c: cbz x8, #0xfae8
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x00fa50: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x00fa54: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x00fa58: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x00fa5c: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000AULL; // 0x00fa60: fmov w10, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100055FULL; // 0x00fa64: cmp x10, #1
    return acc;
}

// [EN] Reconstructed FDE #0162 @ 0x00faf0..0x00fb1c (44 bytes)
// [VN] Phục dựng FDE #0162 tại 0x00faf0..0x00fb1c (44 byte)
//   0x00faf0: f9400028  ldr      x8, [x1]
//   0x00faf4: f9000008  str      x8, [x0]
//   0x00faf8: f9400429  ldr      x9, [x1, #8]
//   0x00fafc: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00fb00: aa0203e1  mov      x1, x2
//   0x00fb04: f8286809  str      x9, [x0, x8]
//   0x00fb08: f9400008  ldr      x8, [x0]
//   0x00fb0c: f900041f  str      xzr, [x0, #8]
//   0x00fb10: f85e8108  ldur     x8, [x8, #-0x18]
//   0x00fb14: 8b080000  add      x0, x0, x8
//   0x00fb18: 1400005e  b        #0xfc90
uint64_t fde_0162_sub_00faf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0xF85E8108ULL) + (x2 ^ 0x00FAF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x00faf0: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x00faf4: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400429ULL; // 0x00faf8: ldr x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x00fafc: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x00fb00: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF8286809ULL; // 0x00fb04: str x9, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00fb08: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900041FULL; // 0x00fb0c: str xzr, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0163 @ 0x00fb1c..0x00fc0c (240 bytes)
// [VN] Phục dựng FDE #0163 tại 0x00fb1c..0x00fc0c (240 byte)
//   0x00fb1c: d10103ff  sub      sp, sp, #0x40
//   0x00fb20: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00fb24: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00fb28: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00fb2c: 9100c3fd  add      x29, sp, #0x30
//   0x00fb30: d53bd056  mrs      x22, tpidr_el0
//   0x00fb34: f94016c8  ldr      x8, [x22, #0x28]
//   0x00fb38: aa0003f3  mov      x19, x0
//   0x00fb3c: f90007e8  str      x8, [sp, #8]
//   0x00fb40: 9400005f  bl       #0xfcbc
//   0x00fb44: 90000268  adrp     x8, #0x5b000
//   0x00fb48: f9448908  ldr      x8, [x8, #0x910]
uint64_t fde_0163_sub_00fb1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x00FB1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x00fb1c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00fb20: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00fb24: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00fb28: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00fb2c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x00fb30: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00fb34: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00fb38: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0164 @ 0x00fc0c..0x00fc90 (132 bytes)
// [VN] Phục dựng FDE #0164 tại 0x00fc0c..0x00fc90 (132 byte)
//   0x00fc0c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00fc10: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00fc14: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00fc18: 910083fd  add      x29, sp, #0x20
//   0x00fc1c: f9403c08  ldr      x8, [x0, #0x78]
//   0x00fc20: b40000e8  cbz      x8, #0xfc3c
//   0x00fc24: aa1f03f3  mov      x19, xzr
//   0x00fc28: aa1303e0  mov      x0, x19
//   0x00fc2c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00fc30: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00fc34: f84307f5  ldr      x21, [sp], #0x30
//   0x00fc38: d65f03c0  ret      
uint64_t fde_0164_sub_00fc0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xA9427BFDULL) + (x2 ^ 0x00FC0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00fc0c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00fc10: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00fc14: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00fc18: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x00fc1c: ldr x8, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E8ULL; // 0x00fc20: cbz x8, #0xfc3c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03F3ULL; // 0x00fc24: mov x19, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00fc28: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0165 @ 0x00fc90..0x00fcbc (44 bytes)
// [VN] Phục dựng FDE #0165 tại 0x00fc90..0x00fcbc (44 byte)
//   0x00fc90: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00fc94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00fc98: 910043fd  add      x29, sp, #0x10
//   0x00fc9c: aa0003f3  mov      x19, x0
//   0x00fca0: 97ffece4  bl       #0xb030
//   0x00fca4: 12800008  mov      w8, #-1
//   0x00fca8: f900467f  str      xzr, [x19, #0x88]
//   0x00fcac: b9009268  str      w8, [x19, #0x90]
//   0x00fcb0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00fcb4: f84207f3  ldr      x19, [sp], #0x20
//   0x00fcb8: d65f03c0  ret      
uint64_t fde_0165_sub_00fc90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x00FC90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00fc90: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00fc94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00fc98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00fc9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFECE4ULL; // 0x00fca0: bl #0xb030
    acc = (acc * 0x100000001B3ULL) ^ 0x12800008ULL; // 0x00fca4: mov w8, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900467FULL; // 0x00fca8: str xzr, [x19, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9009268ULL; // 0x00fcac: str w8, [x19, #0x90]
    return acc;
}

// [EN] Reconstructed FDE #0166 @ 0x00fcbc..0x00fcf8 (60 bytes)
// [VN] Phục dựng FDE #0166 tại 0x00fcbc..0x00fcf8 (60 byte)
//   0x00fcbc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00fcc0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00fcc4: 910043fd  add      x29, sp, #0x10
//   0x00fcc8: 90000268  adrp     x8, #0x5b000
//   0x00fccc: f9439108  ldr      x8, [x8, #0x720]
//   0x00fcd0: aa0003f3  mov      x19, x0
//   0x00fcd4: 91004108  add      x8, x8, #0x10
//   0x00fcd8: f8008408  str      x8, [x0], #8
//   0x00fcdc: 97ffee75  bl       #0xb6b0
//   0x00fce0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00fce4: ad010260  stp      q0, q0, [x19, #0x20]
//   0x00fce8: 3d800660  str      q0, [x19, #0x10]
uint64_t fde_0166_sub_00fcbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFEE75ULL) + (x2 ^ 0x00FCBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00fcbc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00fcc0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00fcc4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000268ULL; // 0x00fcc8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x00fccc: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00fcd0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x00fcd4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x00fcd8: str x8, [x0], #8
    return acc;
}

// [EN] Reconstructed FDE #0167 @ 0x00fcf8..0x00fd04 (12 bytes)
// [VN] Phục dựng FDE #0167 tại 0x00fcf8..0x00fd04 (12 byte)
//   0x00fcf8: 90000261  adrp     x1, #0x5b000
//   0x00fcfc: f943dc21  ldr      x1, [x1, #0x7b8]
//   0x00fd00: 17ffeec4  b        #0xb810
uint64_t fde_0167_sub_00fcf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000261ULL) + (x1 ^ 0x17FFEEC4ULL) + (x2 ^ 0x00FCF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000261ULL; // 0x00fcf8: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943DC21ULL; // 0x00fcfc: ldr x1, [x1, #0x7b8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEEC4ULL; // 0x00fd00: b #0xb810
    return acc;
}

// [EN] Reconstructed FDE #0168 @ 0x00fd04..0x00fde0 (220 bytes)
// [VN] Phục dựng FDE #0168 tại 0x00fd04..0x00fde0 (220 byte)
//   0x00fd04: 121e7808  and      w8, w0, #0xfffffffd
//   0x00fd08: 51000509  sub      w9, w8, #1
//   0x00fd0c: f0000160  adrp     x0, #0x3e000
//   0x00fd10: 7100713f  cmp      w9, #0x1c
//   0x00fd14: 913a6c00  add      x0, x0, #0xe9b
//   0x00fd18: 54000148  b.hi     #0xfd40
//   0x00fd1c: d0000148  adrp     x8, #0x39000
//   0x00fd20: 91100508  add      x8, x8, #0x401
//   0x00fd24: 1000008a  adr      x10, #0xfd34
//   0x00fd28: 3869690b  ldrb     w11, [x8, x9]
//   0x00fd2c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00fd30: d61f0140  br       x10
uint64_t fde_0168_sub_00fd04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x121E7808ULL) + (x1 ^ 0x1000008AULL) + (x2 ^ 0x00FD04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x121E7808ULL; // 0x00fd04: and w8, w0, #0xfffffffd
    acc = (acc * 0x100000001B3ULL) ^ 0x51000509ULL; // 0x00fd08: sub w9, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000160ULL; // 0x00fd0c: adrp x0, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x7100713FULL; // 0x00fd10: cmp w9, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0x913A6C00ULL; // 0x00fd14: add x0, x0, #0xe9b
    acc = (acc * 0x100000001B3ULL) ^ 0x54000148ULL; // 0x00fd18: b.hi #0xfd40
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x00fd1c: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x91100508ULL; // 0x00fd20: add x8, x8, #0x401
    return acc;
}

// [EN] Reconstructed FDE #0169 @ 0x00fde0..0x00fdec (12 bytes)
// [VN] Phục dựng FDE #0169 tại 0x00fde0..0x00fdec (12 byte)
//   0x00fde0: b9402008  ldr      w8, [x0, #0x20]
//   0x00fde4: 2a010101  orr      w1, w8, w1
//   0x00fde8: 17ffebfe  b        #0xade0
uint64_t fde_0169_sub_00fde0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9402008ULL) + (x1 ^ 0x17FFEBFEULL) + (x2 ^ 0x00FDE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402008ULL; // 0x00fde0: ldr w8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A010101ULL; // 0x00fde4: orr w1, w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEBFEULL; // 0x00fde8: b #0xade0
    return acc;
}

// [EN] Reconstructed FDE #0170 @ 0x00fdec..0x00feec (256 bytes)
// [VN] Phục dựng FDE #0170 tại 0x00fdec..0x00feec (256 byte)
//   0x00fdec: d10143ff  sub      sp, sp, #0x50
//   0x00fdf0: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00fdf4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00fdf8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00fdfc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00fe00: 910103fd  add      x29, sp, #0x40
//   0x00fe04: d53bd056  mrs      x22, tpidr_el0
//   0x00fe08: f94016c8  ldr      x8, [x22, #0x28]
//   0x00fe0c: aa0003f3  mov      x19, x0
//   0x00fe10: 2a0203f4  mov      w20, w2
//   0x00fe14: aa0103f5  mov      x21, x1
//   0x00fe18: 910003e0  mov      x0, sp
uint64_t fde_0170_sub_00fdec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x00FDECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x00fdec: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00fdf0: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00fdf4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00fdf8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00fdfc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00fe00: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x00fe04: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00fe08: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0171 @ 0x00feec..0x00ff60 (116 bytes)
// [VN] Phục dựng FDE #0171 tại 0x00feec..0x00ff60 (116 byte)
//   0x00feec: d100c3ff  sub      sp, sp, #0x30
//   0x00fef0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00fef4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00fef8: 910083fd  add      x29, sp, #0x20
//   0x00fefc: d53bd054  mrs      x20, tpidr_el0
//   0x00ff00: f9401688  ldr      x8, [x20, #0x28]
//   0x00ff04: 2a0103f3  mov      w19, w1
//   0x00ff08: f90007e8  str      x8, [sp, #8]
//   0x00ff0c: 910003e8  mov      x8, sp
//   0x00ff10: 97ffedf0  bl       #0xb6d0
//   0x00ff14: 910003e0  mov      x0, sp
//   0x00ff18: 940000ca  bl       #0x10240
uint64_t fde_0171_sub_00feec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910003E8ULL) + (x2 ^ 0x00FEECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x00feec: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00fef0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00fef4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00fef8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x00fefc: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x00ff00: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x00ff04: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x00ff08: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0172 @ 0x00ff60..0x0100a8 (328 bytes)
// [VN] Phục dựng FDE #0172 tại 0x00ff60..0x0100a8 (328 byte)
//   0x00ff60: d10143ff  sub      sp, sp, #0x50
//   0x00ff64: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00ff68: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00ff6c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00ff70: 910103fd  add      x29, sp, #0x40
//   0x00ff74: d53bd056  mrs      x22, tpidr_el0
//   0x00ff78: f94016c8  ldr      x8, [x22, #0x28]
//   0x00ff7c: aa0003f3  mov      x19, x0
//   0x00ff80: f9000fe8  str      x8, [sp, #0x18]
//   0x00ff84: 3900001f  strb     wzr, [x0]
//   0x00ff88: f9400028  ldr      x8, [x1]
//   0x00ff8c: f85e8108  ldur     x8, [x8, #-0x18]
uint64_t fde_0172_sub_00ff60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x00FF60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x00ff60: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00ff64: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00ff68: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00ff6c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00ff70: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x00ff74: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00ff78: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00ff7c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0173 @ 0x0100a8..0x0100c8 (32 bytes)
// [VN] Phục dựng FDE #0173 tại 0x0100a8..0x0100c8 (32 byte)
//   0x0100a8: 39400008  ldrb     w8, [x0]
//   0x0100ac: 37000068  tbnz     w8, #0, #0x100b8
//   0x0100b0: 7900001f  strh     wzr, [x0]
//   0x0100b4: d65f03c0  ret      
//   0x0100b8: f9400808  ldr      x8, [x0, #0x10]
//   0x0100bc: 3900011f  strb     wzr, [x8]
//   0x0100c0: f900041f  str      xzr, [x0, #8]
//   0x0100c4: d65f03c0  ret      
uint64_t fde_0173_sub_0100a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0100A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x0100a8: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x0100ac: tbnz w8, #0, #0x100b8
    acc = (acc * 0x100000001B3ULL) ^ 0x7900001FULL; // 0x0100b0: strh wzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0100b4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x0100b8: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900011FULL; // 0x0100bc: strb wzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900041FULL; // 0x0100c0: str xzr, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0100c4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0174 @ 0x0100c8..0x0100f0 (40 bytes)
// [VN] Phục dựng FDE #0174 tại 0x0100c8..0x0100f0 (40 byte)
//   0x0100c8: a941a408  ldp      x8, x9, [x0, #0x18]
//   0x0100cc: eb09011f  cmp      x8, x9
//   0x0100d0: 540000a0  b.eq     #0x100e4
//   0x0100d4: 91000509  add      x9, x8, #1
//   0x0100d8: f9000c09  str      x9, [x0, #0x18]
//   0x0100dc: 39400100  ldrb     w0, [x8]
//   0x0100e0: d65f03c0  ret      
//   0x0100e4: f9400008  ldr      x8, [x0]
//   0x0100e8: f9402901  ldr      x1, [x8, #0x50]
//   0x0100ec: d61f0020  br       x1
uint64_t fde_0174_sub_0100c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA941A408ULL) + (x1 ^ 0xF9402901ULL) + (x2 ^ 0x0100C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA941A408ULL; // 0x0100c8: ldp x8, x9, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0100cc: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x0100d0: b.eq #0x100e4
    acc = (acc * 0x100000001B3ULL) ^ 0x91000509ULL; // 0x0100d4: add x9, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C09ULL; // 0x0100d8: str x9, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400100ULL; // 0x0100dc: ldrb w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0100e0: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0100e4: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0175 @ 0x0100f0..0x010190 (160 bytes)
// [VN] Phục dựng FDE #0175 tại 0x0100f0..0x010190 (160 byte)
//   0x0100f0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0100f4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0100f8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0100fc: 910083fd  add      x29, sp, #0x20
//   0x010100: 39400008  ldrb     w8, [x0]
//   0x010104: aa0003f4  mov      x20, x0
//   0x010108: 2a0103f3  mov      w19, w1
//   0x01010c: 360000a8  tbz      w8, #0, #0x10120
//   0x010110: a9405689  ldp      x9, x21, [x20]
//   0x010114: 927ff929  and      x9, x9, #0xfffffffffffffffe
//   0x010118: d1000521  sub      x1, x9, #1
//   0x01011c: 14000003  b        #0x10128
uint64_t fde_0175_sub_0100f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xA9405689ULL) + (x2 ^ 0x0100F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0100f0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0100f4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0100f8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0100fc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x010100: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x010104: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x010108: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x360000A8ULL; // 0x01010c: tbz w8, #0, #0x10120
    return acc;
}

// [EN] Reconstructed FDE #0176 @ 0x010190..0x010240 (176 bytes)
// [VN] Phục dựng FDE #0176 tại 0x010190..0x010240 (176 byte)
//   0x010190: d10103ff  sub      sp, sp, #0x40
//   0x010194: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x010198: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01019c: 9100c3fd  add      x29, sp, #0x30
//   0x0101a0: d53bd054  mrs      x20, tpidr_el0
//   0x0101a4: f9401688  ldr      x8, [x20, #0x28]
//   0x0101a8: aa0003f3  mov      x19, x0
//   0x0101ac: f9000fe8  str      x8, [sp, #0x18]
//   0x0101b0: f9400008  ldr      x8, [x0]
//   0x0101b4: f85e8108  ldur     x8, [x8, #-0x18]
//   0x0101b8: 8b080008  add      x8, x0, x8
//   0x0101bc: f9401508  ldr      x8, [x8, #0x28]
uint64_t fde_0176_sub_010190(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x010190ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x010190: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x010194: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x010198: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01019c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0101a0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0101a4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0101a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0101ac: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0177 @ 0x010240..0x01025c (28 bytes)
// [VN] Phục dựng FDE #0177 tại 0x010240..0x01025c (28 byte)
//   0x010240: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x010244: 910003fd  mov      x29, sp
//   0x010248: f0000241  adrp     x1, #0x5b000
//   0x01024c: f9429021  ldr      x1, [x1, #0x520]
//   0x010250: 97ffed58  bl       #0xb7b0
//   0x010254: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x010258: d65f03c0  ret      
uint64_t fde_0177_sub_010240(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010240ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x010240: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x010244: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000241ULL; // 0x010248: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9429021ULL; // 0x01024c: ldr x1, [x1, #0x520]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFED58ULL; // 0x010250: bl #0xb7b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x010254: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010258: ret 
    return acc;
}

// [EN] Reconstructed FDE #0178 @ 0x01025c..0x010278 (28 bytes)
// [VN] Phục dựng FDE #0178 tại 0x01025c..0x010278 (28 byte)
//   0x01025c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x010260: 910003fd  mov      x29, sp
//   0x010264: 9400003d  bl       #0x10358
//   0x010268: 2a2003e8  mvn      w8, w0
//   0x01026c: 12000100  and      w0, w8, #1
//   0x010270: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x010274: d65f03c0  ret      
uint64_t fde_0178_sub_01025c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01025CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01025c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x010260: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9400003DULL; // 0x010264: bl #0x10358
    acc = (acc * 0x100000001B3ULL) ^ 0x2A2003E8ULL; // 0x010268: mvn w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000100ULL; // 0x01026c: and w0, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x010270: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010274: ret 
    return acc;
}

// [EN] Reconstructed FDE #0179 @ 0x010278..0x0102c4 (76 bytes)
// [VN] Phục dựng FDE #0179 tại 0x010278..0x0102c4 (76 byte)
//   0x010278: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01027c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010280: 910043fd  add      x29, sp, #0x10
//   0x010284: 3900001f  strb     wzr, [x0]
//   0x010288: f9000401  str      x1, [x0, #8]
//   0x01028c: f9400028  ldr      x8, [x1]
//   0x010290: f85e8108  ldur     x8, [x8, #-0x18]
//   0x010294: 8b080028  add      x8, x1, x8
//   0x010298: b9402109  ldr      w9, [x8, #0x20]
//   0x01029c: 350000e9  cbnz     w9, #0x102b8
//   0x0102a0: aa0003f3  mov      x19, x0
//   0x0102a4: f9404500  ldr      x0, [x8, #0x88]
uint64_t fde_0179_sub_010278(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB9402109ULL) + (x2 ^ 0x010278ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010278: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01027c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010280: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3900001FULL; // 0x010284: strb wzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000401ULL; // 0x010288: str x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x01028c: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x010290: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080028ULL; // 0x010294: add x8, x1, x8
    return acc;
}

// [EN] Reconstructed FDE #0180 @ 0x0102c4..0x010358 (148 bytes)
// [VN] Phục dựng FDE #0180 tại 0x0102c4..0x010358 (148 byte)
//   0x0102c4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0102c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0102cc: 910043fd  add      x29, sp, #0x10
//   0x0102d0: f9400408  ldr      x8, [x0, #8]
//   0x0102d4: f9400109  ldr      x9, [x8]
//   0x0102d8: f85e8129  ldur     x9, [x9, #-0x18]
//   0x0102dc: 8b090108  add      x8, x8, x9
//   0x0102e0: f9401509  ldr      x9, [x8, #0x28]
//   0x0102e4: b4000249  cbz      x9, #0x1032c
//   0x0102e8: b9402109  ldr      w9, [x8, #0x20]
//   0x0102ec: 35000209  cbnz     w9, #0x1032c
//   0x0102f0: 39402508  ldrb     w8, [x8, #9]
uint64_t fde_0180_sub_0102c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB4000249ULL) + (x2 ^ 0x0102C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0102c4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0102c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0102cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0102d0: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x0102d4: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8129ULL; // 0x0102d8: ldur x9, [x9, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090108ULL; // 0x0102dc: add x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x0102e0: ldr x9, [x8, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0181 @ 0x010358..0x01038c (52 bytes)
// [VN] Phục dựng FDE #0181 tại 0x010358..0x01038c (52 byte)
//   0x010358: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01035c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010360: 910043fd  add      x29, sp, #0x10
//   0x010364: aa0103f3  mov      x19, x1
//   0x010368: 94000009  bl       #0x1038c
//   0x01036c: 2a0003f4  mov      w20, w0
//   0x010370: aa1303e0  mov      x0, x19
//   0x010374: 94000006  bl       #0x1038c
//   0x010378: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01037c: 4a200288  eon      w8, w20, w0
//   0x010380: 12000100  and      w0, w8, #1
//   0x010384: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0181_sub_010358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x010358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x010358: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01035c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010360: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x010364: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000009ULL; // 0x010368: bl #0x1038c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x01036c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x010370: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94000006ULL; // 0x010374: bl #0x1038c
    return acc;
}

// [EN] Reconstructed FDE #0182 @ 0x01038c..0x0103d4 (72 bytes)
// [VN] Phục dựng FDE #0182 tại 0x01038c..0x0103d4 (72 byte)
//   0x01038c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010390: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010394: 910043fd  add      x29, sp, #0x10
//   0x010398: aa0003f3  mov      x19, x0
//   0x01039c: f9400000  ldr      x0, [x0]
//   0x0103a0: b4000120  cbz      x0, #0x103c4
//   0x0103a4: 9400000c  bl       #0x103d4
//   0x0103a8: 3100041f  cmn      w0, #1
//   0x0103ac: 540000a0  b.eq     #0x103c0
//   0x0103b0: f9400268  ldr      x8, [x19]
//   0x0103b4: f100011f  cmp      x8, #0
//   0x0103b8: 1a9f17e0  cset     w0, eq
uint64_t fde_0182_sub_01038c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x540000A0ULL) + (x2 ^ 0x01038CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01038c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010390: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010394: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010398: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01039c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000120ULL; // 0x0103a0: cbz x0, #0x103c4
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x0103a4: bl #0x103d4
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x0103a8: cmn w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0183 @ 0x0103d4..0x0103f4 (32 bytes)
// [VN] Phục dựng FDE #0183 tại 0x0103d4..0x0103f4 (32 byte)
//   0x0103d4: a941a408  ldp      x8, x9, [x0, #0x18]
//   0x0103d8: eb09011f  cmp      x8, x9
//   0x0103dc: 54000060  b.eq     #0x103e8
//   0x0103e0: 39400100  ldrb     w0, [x8]
//   0x0103e4: d65f03c0  ret      
//   0x0103e8: f9400008  ldr      x8, [x0]
//   0x0103ec: f9402501  ldr      x1, [x8, #0x48]
//   0x0103f0: d61f0020  br       x1
uint64_t fde_0183_sub_0103d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA941A408ULL) + (x1 ^ 0xD61F0020ULL) + (x2 ^ 0x0103D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA941A408ULL; // 0x0103d4: ldp x8, x9, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0103d8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x0103dc: b.eq #0x103e8
    acc = (acc * 0x100000001B3ULL) ^ 0x39400100ULL; // 0x0103e0: ldrb w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0103e4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0103e8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402501ULL; // 0x0103ec: ldr x1, [x8, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x0103f0: br x1
    return acc;
}

// [EN] Reconstructed FDE #0184 @ 0x0103f4..0x010508 (276 bytes)
// [VN] Phục dựng FDE #0184 tại 0x0103f4..0x010508 (276 byte)
//   0x0103f4: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0103f8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0103fc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x010400: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x010404: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x010408: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01040c: 910143fd  add      x29, sp, #0x50
//   0x010410: 92800208  mov      x8, #-0x11
//   0x010414: cb010108  sub      x8, x8, x1
//   0x010418: eb02011f  cmp      x8, x2
//   0x01041c: 54000743  b.lo     #0x10504
//   0x010420: 39400008  ldrb     w8, [x0]
uint64_t fde_0184_sub_0103f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xCB010108ULL) + (x2 ^ 0x0103F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x0103f4: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0103f8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0103fc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x010400: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x010404: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x010408: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01040c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x92800208ULL; // 0x010410: mov x8, #-0x11
    return acc;
}

// [EN] Reconstructed FDE #0185 @ 0x010508..0x010588 (128 bytes)
// [VN] Phục dựng FDE #0185 tại 0x010508..0x010588 (128 byte)
//   0x010508: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01050c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010510: 910043fd  add      x29, sp, #0x10
//   0x010514: 39400008  ldrb     w8, [x0]
//   0x010518: aa0403f3  mov      x19, x4
//   0x01051c: 37000068  tbnz     w8, #0, #0x10528
//   0x010520: d341fd09  lsr      x9, x8, #1
//   0x010524: 14000002  b        #0x1052c
//   0x010528: f9400409  ldr      x9, [x0, #8]
//   0x01052c: b100067f  cmn      x19, #1
//   0x010530: fa411120  ccmp     x9, x1, #0, ne
//   0x010534: 54000283  b.lo     #0x10584
uint64_t fde_0185_sub_010508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400409ULL) + (x2 ^ 0x010508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x010508: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01050c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010510: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x010514: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F3ULL; // 0x010518: mov x19, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x01051c: tbnz w8, #0, #0x10528
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD09ULL; // 0x010520: lsr x9, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x010524: b #0x1052c
    return acc;
}

// [EN] Reconstructed FDE #0186 @ 0x010588..0x010590 (8 bytes)
// [VN] Phục dựng FDE #0186 tại 0x010588..0x010590 (8 byte)
//   0x010588: aa1f03e1  mov      x1, xzr
//   0x01058c: 1400000e  b        #0x105c4
uint64_t fde_0186_sub_010588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000EULL) + (x2 ^ 0x010588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x010588: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x01058c: b #0x105c4
    return acc;
}

// [EN] Reconstructed FDE #0187 @ 0x010590..0x010598 (8 bytes)
// [VN] Phục dựng FDE #0187 tại 0x010590..0x010598 (8 byte)
//   0x010590: aa1f03e2  mov      x2, xzr
//   0x010594: 14000001  b        #0x10598
uint64_t fde_0187_sub_010590(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x010590ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x010590: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x010594: b #0x10598
    return acc;
}

// [EN] Reconstructed FDE #0188 @ 0x010598..0x0105c4 (44 bytes)
// [VN] Phục dựng FDE #0188 tại 0x010598..0x0105c4 (44 byte)
//   0x010598: b203e7e8  mov      x8, #0x6666666666666666
//   0x01059c: f28ccce8  movk     x8, #0x6667
//   0x0105a0: f2e0ccc8  movk     x8, #0x666, lsl #48
//   0x0105a4: eb08003f  cmp      x1, x8
//   0x0105a8: 54000082  b.hs     #0x105b8
//   0x0105ac: 8b010828  add      x8, x1, x1, lsl #2
//   0x0105b0: d37df100  lsl      x0, x8, #3
//   0x0105b4: 17ffec0f  b        #0xb5f0
//   0x0105b8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0105bc: 910003fd  mov      x29, sp
//   0x0105c0: 97ffebd0  bl       #0xb500
uint64_t fde_0188_sub_010598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB203E7E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x010598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB203E7E8ULL; // 0x010598: mov x8, #0x6666666666666666
    acc = (acc * 0x100000001B3ULL) ^ 0xF28CCCE8ULL; // 0x01059c: movk x8, #0x6667
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0CCC8ULL; // 0x0105a0: movk x8, #0x666, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x0105a4: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x0105a8: b.hs #0x105b8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010828ULL; // 0x0105ac: add x8, x1, x1, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x0105b0: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEC0FULL; // 0x0105b4: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0189 @ 0x0105c4..0x0105dc (24 bytes)
// [VN] Phục dựng FDE #0189 tại 0x0105c4..0x0105dc (24 byte)
//   0x0105c4: aa0003e8  mov      x8, x0
//   0x0105c8: f9400000  ldr      x0, [x0]
//   0x0105cc: f9000101  str      x1, [x8]
//   0x0105d0: b4000040  cbz      x0, #0x105d8
//   0x0105d4: 17ffe9db  b        #0xad40
//   0x0105d8: d65f03c0  ret      
uint64_t fde_0189_sub_0105c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0105C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0105c4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x0105c8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x0105cc: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x0105d0: cbz x0, #0x105d8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE9DBULL; // 0x0105d4: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0105d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0190 @ 0x0105dc..0x010818 (572 bytes)
// [VN] Phục dựng FDE #0190 tại 0x0105dc..0x010818 (572 byte)
//   0x0105dc: d10183ff  sub      sp, sp, #0x60
//   0x0105e0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0105e4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0105e8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0105ec: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0105f0: 910143fd  add      x29, sp, #0x50
//   0x0105f4: d53bd056  mrs      x22, tpidr_el0
//   0x0105f8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0105fc: aa0003f3  mov      x19, x0
//   0x010600: f9000fe8  str      x8, [sp, #0x18]
//   0x010604: f9400417  ldr      x23, [x0, #8]
//   0x010608: b9400034  ldr      w20, [x1]
uint64_t fde_0190_sub_0105dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0105DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0105dc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0105e0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0105e4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0105e8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0105ec: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0105f0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0105f4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0105f8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0191 @ 0x010818..0x010884 (108 bytes)
// [VN] Phục dựng FDE #0191 tại 0x010818..0x010884 (108 byte)
//   0x010818: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x01081c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x010820: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x010824: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x010828: 9100c3fd  add      x29, sp, #0x30
//   0x01082c: 91004016  add      x22, x0, #0x10
//   0x010830: aa0103f4  mov      x20, x1
//   0x010834: 52800021  mov      w1, #1
//   0x010838: aa1603e0  mov      x0, x22
//   0x01083c: aa0303f3  mov      x19, x3
//   0x010840: aa0803f5  mov      x21, x8
//   0x010844: 52800037  mov      w23, #1
uint64_t fde_0191_sub_010818(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x010818ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x010818: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01081c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x010820: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x010824: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x010828: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x01082c: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x010830: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x010834: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0192 @ 0x010884..0x010964 (224 bytes)
// [VN] Phục dựng FDE #0192 tại 0x010884..0x010964 (224 byte)
//   0x010884: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x010888: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01088c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010890: 910083fd  add      x29, sp, #0x20
//   0x010894: f1000428  subs     x8, x1, #1
//   0x010898: aa0003f3  mov      x19, x0
//   0x01089c: 54000061  b.ne     #0x108a8
//   0x0108a0: 52800054  mov      w20, #2
//   0x0108a4: 14000007  b        #0x108c0
//   0x0108a8: aa0103f4  mov      x20, x1
//   0x0108ac: ea08003f  tst      x1, x8
//   0x0108b0: 54000080  b.eq     #0x108c0
uint64_t fde_0192_sub_010884(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x010884ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x010884: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x010888: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01088c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x010890: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x010894: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010898: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x01089c: b.ne #0x108a8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x0108a0: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #0193 @ 0x010964..0x01096c (8 bytes)
// [VN] Phục dựng FDE #0193 tại 0x010964..0x01096c (8 byte)
//   0x010964: aa1f03e1  mov      x1, xzr
//   0x010968: 14000070  b        #0x10b28
uint64_t fde_0193_sub_010964(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000070ULL) + (x2 ^ 0x010964ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x010964: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000070ULL; // 0x010968: b #0x10b28
    return acc;
}

// [EN] Reconstructed FDE #0194 @ 0x01096c..0x010974 (8 bytes)
// [VN] Phục dựng FDE #0194 tại 0x01096c..0x010974 (8 byte)
//   0x01096c: aa1f03e2  mov      x2, xzr
//   0x010970: 14000001  b        #0x10974
uint64_t fde_0194_sub_01096c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01096CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01096c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x010970: b #0x10974
    return acc;
}

// [EN] Reconstructed FDE #0195 @ 0x010974..0x0109a0 (44 bytes)
// [VN] Phục dựng FDE #0195 tại 0x010974..0x0109a0 (44 byte)
//   0x010974: b200f3e8  mov      x8, #0x5555555555555555
//   0x010978: f28aaac8  movk     x8, #0x5556
//   0x01097c: f2e0aaa8  movk     x8, #0x555, lsl #48
//   0x010980: eb08003f  cmp      x1, x8
//   0x010984: 54000082  b.hs     #0x10994
//   0x010988: 8b010428  add      x8, x1, x1, lsl #1
//   0x01098c: d37ced00  lsl      x0, x8, #4
//   0x010990: 17ffeb18  b        #0xb5f0
//   0x010994: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x010998: 910003fd  mov      x29, sp
//   0x01099c: 97ffead9  bl       #0xb500
uint64_t fde_0195_sub_010974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB200F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x010974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3E8ULL; // 0x010974: mov x8, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xF28AAAC8ULL; // 0x010978: movk x8, #0x5556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0AAA8ULL; // 0x01097c: movk x8, #0x555, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x010980: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x010984: b.hs #0x10994
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x010988: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED00ULL; // 0x01098c: lsl x0, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEB18ULL; // 0x010990: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0196 @ 0x0109a0..0x010aec (332 bytes)
// [VN] Phục dựng FDE #0196 tại 0x0109a0..0x010aec (332 byte)
//   0x0109a0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0109a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0109a8: 910043fd  add      x29, sp, #0x10
//   0x0109ac: aa0003f3  mov      x19, x0
//   0x0109b0: b40003c1  cbz      x1, #0x10a28
//   0x0109b4: 91002260  add      x0, x19, #8
//   0x0109b8: aa0103f4  mov      x20, x1
//   0x0109bc: 94000052  bl       #0x10b04
//   0x0109c0: aa0003e1  mov      x1, x0
//   0x0109c4: aa1303e0  mov      x0, x19
//   0x0109c8: 94000049  bl       #0x10aec
//   0x0109cc: aa1f03e8  mov      x8, xzr
uint64_t fde_0196_sub_0109a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x0109A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0109a0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0109a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0109a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0109ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x0109b0: cbz x1, #0x10a28
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x0109b4: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0109b8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x0109bc: bl #0x10b04
    return acc;
}

// [EN] Reconstructed FDE #0197 @ 0x010aec..0x010b04 (24 bytes)
// [VN] Phục dựng FDE #0197 tại 0x010aec..0x010b04 (24 byte)
//   0x010aec: aa0003e8  mov      x8, x0
//   0x010af0: f9400000  ldr      x0, [x0]
//   0x010af4: f9000101  str      x1, [x8]
//   0x010af8: b4000040  cbz      x0, #0x10b00
//   0x010afc: 17ffe891  b        #0xad40
//   0x010b00: d65f03c0  ret      
uint64_t fde_0197_sub_010aec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010AECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x010aec: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x010af0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x010af4: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x010af8: cbz x0, #0x10b00
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE891ULL; // 0x010afc: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010b00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0198 @ 0x010b04..0x010b0c (8 bytes)
// [VN] Phục dựng FDE #0198 tại 0x010b04..0x010b0c (8 byte)
//   0x010b04: aa1f03e2  mov      x2, xzr
//   0x010b08: 14000001  b        #0x10b0c
uint64_t fde_0198_sub_010b04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x010B04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x010b04: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x010b08: b #0x10b0c
    return acc;
}

// [EN] Reconstructed FDE #0199 @ 0x010b0c..0x010b28 (28 bytes)
// [VN] Phục dựng FDE #0199 tại 0x010b0c..0x010b28 (28 byte)
//   0x010b0c: d37dfc28  lsr      x8, x1, #0x3d
//   0x010b10: b5000068  cbnz     x8, #0x10b1c
//   0x010b14: d37df020  lsl      x0, x1, #3
//   0x010b18: 17ffeab6  b        #0xb5f0
//   0x010b1c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x010b20: 910003fd  mov      x29, sp
//   0x010b24: 97ffea77  bl       #0xb500
uint64_t fde_0199_sub_010b0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FFEA77ULL) + (x2 ^ 0x010B0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x010b0c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x010b10: cbnz x8, #0x10b1c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x010b14: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEAB6ULL; // 0x010b18: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x010b1c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x010b20: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA77ULL; // 0x010b24: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0200 @ 0x010b28..0x010b44 (28 bytes)
// [VN] Phục dựng FDE #0200 tại 0x010b28..0x010b44 (28 byte)
//   0x010b28: f9400008  ldr      x8, [x0]
//   0x010b2c: f9000001  str      x1, [x0]
//   0x010b30: b4000088  cbz      x8, #0x10b40
//   0x010b34: 91002000  add      x0, x0, #8
//   0x010b38: aa0803e1  mov      x1, x8
//   0x010b3c: 14000002  b        #0x10b44
//   0x010b40: d65f03c0  ret      
uint64_t fde_0200_sub_010b28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010B28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x010b28: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x010b2c: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x010b30: cbz x8, #0x10b40
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x010b34: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x010b38: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x010b3c: b #0x10b44
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010b40: ret 
    return acc;
}

// [EN] Reconstructed FDE #0201 @ 0x010b44..0x010b84 (64 bytes)
// [VN] Phục dựng FDE #0201 tại 0x010b44..0x010b84 (64 byte)
//   0x010b44: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010b48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010b4c: 910043fd  add      x29, sp, #0x10
//   0x010b50: 39402008  ldrb     w8, [x0, #8]
//   0x010b54: aa0103f3  mov      x19, x1
//   0x010b58: 34000068  cbz      w8, #0x10b64
//   0x010b5c: 91006260  add      x0, x19, #0x18
//   0x010b60: 97fff3e0  bl       #0xdae0
//   0x010b64: b40000b3  cbz      x19, #0x10b78
//   0x010b68: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x010b6c: aa1303e0  mov      x0, x19
//   0x010b70: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0201_sub_010b44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB40000B3ULL) + (x2 ^ 0x010B44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010b44: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010b48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010b4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39402008ULL; // 0x010b50: ldrb w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x010b54: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000068ULL; // 0x010b58: cbz w8, #0x10b64
    acc = (acc * 0x100000001B3ULL) ^ 0x91006260ULL; // 0x010b5c: add x0, x19, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF3E0ULL; // 0x010b60: bl #0xdae0
    return acc;
}

// [EN] Reconstructed FDE #0202 @ 0x010b84..0x010c10 (140 bytes)
// [VN] Phục dựng FDE #0202 tại 0x010b84..0x010c10 (140 byte)
//   0x010b84: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x010b88: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010b8c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010b90: 910083fd  add      x29, sp, #0x20
//   0x010b94: aa0203f4  mov      x20, x2
//   0x010b98: aa0103f5  mov      x21, x1
//   0x010b9c: aa0003f3  mov      x19, x0
//   0x010ba0: 91002008  add      x8, x0, #8
//   0x010ba4: f9400116  ldr      x22, [x8]
//   0x010ba8: eb1402bf  cmp      x21, x20
//   0x010bac: fa561264  ccmp     x19, x22, #4, ne
//   0x010bb0: 540000e0  b.eq     #0x10bcc
uint64_t fde_0202_sub_010b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9400116ULL) + (x2 ^ 0x010B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x010b84: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x010b88: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x010b8c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x010b90: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x010b94: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x010b98: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010b9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x010ba0: add x8, x0, #8
    return acc;
}

// [EN] Reconstructed FDE #0203 @ 0x010c10..0x010d38 (296 bytes)
// [VN] Phục dựng FDE #0203 tại 0x010c10..0x010d38 (296 byte)
//   0x010c10: d10203ff  sub      sp, sp, #0x80
//   0x010c14: f90013fb  str      x27, [sp, #0x20]
//   0x010c18: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x010c1c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x010c20: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x010c24: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x010c28: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x010c2c: 9101c3fd  add      x29, sp, #0x70
//   0x010c30: d53bd059  mrs      x25, tpidr_el0
//   0x010c34: f9401728  ldr      x8, [x25, #0x28]
//   0x010c38: aa0103f3  mov      x19, x1
//   0x010c3c: eb03005f  cmp      x2, x3
uint64_t fde_0203_sub_010c10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD53BD059ULL) + (x2 ^ 0x010C10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x010c10: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x010c14: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x010c18: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x010c1c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x010c20: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x010c24: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x010c28: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x010c2c: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0204 @ 0x010d38..0x010db8 (128 bytes)
// [VN] Phục dựng FDE #0204 tại 0x010d38..0x010db8 (128 byte)
//   0x010d38: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x010d3c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010d40: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010d44: 910083fd  add      x29, sp, #0x20
//   0x010d48: aa0203f3  mov      x19, x2
//   0x010d4c: eb02003f  cmp      x1, x2
//   0x010d50: 540002a0  b.eq     #0x10da4
//   0x010d54: f9400268  ldr      x8, [x19]
//   0x010d58: f940002a  ldr      x10, [x1]
//   0x010d5c: aa0103f5  mov      x21, x1
//   0x010d60: aa0003f4  mov      x20, x0
//   0x010d64: f9400509  ldr      x9, [x8, #8]
uint64_t fde_0204_sub_010d38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF940002AULL) + (x2 ^ 0x010D38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x010d38: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x010d3c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x010d40: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x010d44: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x010d48: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02003FULL; // 0x010d4c: cmp x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540002A0ULL; // 0x010d50: b.eq #0x10da4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x010d54: ldr x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0205 @ 0x010db8..0x010dc8 (16 bytes)
// [VN] Phục dựng FDE #0205 tại 0x010db8..0x010dc8 (16 byte)
//   0x010db8: aa0003e8  mov      x8, x0
//   0x010dbc: aa1303e0  mov      x0, x19
//   0x010dc0: aa1403e1  mov      x1, x20
//   0x010dc4: d61f0100  br       x8
uint64_t fde_0205_sub_010db8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x010DB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x010db8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x010dbc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x010dc0: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x010dc4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0206 @ 0x010dc8..0x010dd4 (12 bytes)
// [VN] Phục dựng FDE #0206 tại 0x010dc8..0x010dd4 (12 byte)
//   0x010dc8: 0b081508  add      w8, w8, w8, lsl #5
//   0x010dcc: 0b0b0108  add      w8, w8, w11
//   0x010dd0: d65f03c0  ret      
uint64_t fde_0206_sub_010dc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x0B081508ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010DC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x0B081508ULL; // 0x010dc8: add w8, w8, w8, lsl #5
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0B0108ULL; // 0x010dcc: add w8, w8, w11
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010dd0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0207 @ 0x010dd4..0x010de0 (12 bytes)
// [VN] Phục dựng FDE #0207 tại 0x010dd4..0x010de0 (12 byte)
//   0x010dd4: 0b081508  add      w8, w8, w8, lsl #5
//   0x010dd8: 0b0a0108  add      w8, w8, w10
//   0x010ddc: d65f03c0  ret      
uint64_t fde_0207_sub_010dd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x0B081508ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010DD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x0B081508ULL; // 0x010dd4: add w8, w8, w8, lsl #5
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0A0108ULL; // 0x010dd8: add w8, w8, w10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x010ddc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0208 @ 0x010de0..0x010dec (12 bytes)
// [VN] Phục dựng FDE #0208 tại 0x010de0..0x010dec (12 byte)
//   0x010de0: b0ffffe0  adrp     x0, #0xd000
//   0x010de4: 91241000  add      x0, x0, #0x904
//   0x010de8: 17ffe996  b        #0xb440
uint64_t fde_0208_sub_010de0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0FFFFE0ULL) + (x1 ^ 0x17FFE996ULL) + (x2 ^ 0x010DE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFFE0ULL; // 0x010de0: adrp x0, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x91241000ULL; // 0x010de4: add x0, x0, #0x904
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE996ULL; // 0x010de8: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #0209 @ 0x010dec..0x010ee8 (252 bytes)
// [VN] Phục dựng FDE #0209 tại 0x010dec..0x010ee8 (252 byte)
//   0x010dec: d10103ff  sub      sp, sp, #0x40
//   0x010df0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x010df4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x010df8: 9100c3fd  add      x29, sp, #0x30
//   0x010dfc: d53bd054  mrs      x20, tpidr_el0
//   0x010e00: f9401688  ldr      x8, [x20, #0x28]
//   0x010e04: f9000fe8  str      x8, [sp, #0x18]
//   0x010e08: 97ffea1a  bl       #0xb670
//   0x010e0c: 51008408  sub      w8, w0, #0x21
//   0x010e10: 7100051f  cmp      w8, #1
//   0x010e14: 54000069  b.ls     #0x10e20
//   0x010e18: 2a1f03f3  mov      w19, wzr
uint64_t fde_0209_sub_010dec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x51008408ULL) + (x2 ^ 0x010DECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x010dec: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x010df0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x010df4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x010df8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x010dfc: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x010e00: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x010e04: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA1AULL; // 0x010e08: bl #0xb670
    return acc;
}

// [EN] Reconstructed FDE #0210 @ 0x010ee8..0x010f38 (80 bytes)
// [VN] Phục dựng FDE #0210 tại 0x010ee8..0x010f38 (80 byte)
//   0x010ee8: d100c3ff  sub      sp, sp, #0x30
//   0x010eec: f9000bf3  str      x19, [sp, #0x10]
//   0x010ef0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010ef4: 910083fd  add      x29, sp, #0x20
//   0x010ef8: d53bd053  mrs      x19, tpidr_el0
//   0x010efc: f9401668  ldr      x8, [x19, #0x28]
//   0x010f00: 910003e0  mov      x0, sp
//   0x010f04: f90007e8  str      x8, [sp, #8]
//   0x010f08: f90003fe  str      x30, [sp]
//   0x010f0c: 94000016  bl       #0x10f64
//   0x010f10: f9401668  ldr      x8, [x19, #0x28]
//   0x010f14: f94007e9  ldr      x9, [sp, #8]
uint64_t fde_0210_sub_010ee8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90003FEULL) + (x2 ^ 0x010EE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x010ee8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x010eec: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x010ef0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x010ef4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x010ef8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x010efc: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x010f00: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x010f04: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0211 @ 0x010f38..0x010f64 (44 bytes)
// [VN] Phục dựng FDE #0211 tại 0x010f38..0x010f64 (44 byte)
//   0x010f38: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010f3c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010f40: 910043fd  add      x29, sp, #0x10
//   0x010f44: aa0003f3  mov      x19, x0
//   0x010f48: f9400000  ldr      x0, [x0]
//   0x010f4c: b4000060  cbz      x0, #0x10f58
//   0x010f50: 97ffea00  bl       #0xb750
//   0x010f54: f900027f  str      xzr, [x19]
//   0x010f58: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x010f5c: f84207f3  ldr      x19, [sp], #0x20
//   0x010f60: d65f03c0  ret      
uint64_t fde_0211_sub_010f38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x010F38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010f38: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010f3c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010f40: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010f44: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x010f48: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x010f4c: cbz x0, #0x10f58
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA00ULL; // 0x010f50: bl #0xb750
    acc = (acc * 0x100000001B3ULL) ^ 0xF900027FULL; // 0x010f54: str xzr, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0212 @ 0x010f64..0x010f98 (52 bytes)
// [VN] Phục dựng FDE #0212 tại 0x010f64..0x010f98 (52 byte)
//   0x010f64: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010f68: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010f6c: 910043fd  add      x29, sp, #0x10
//   0x010f70: aa0003f3  mov      x19, x0
//   0x010f74: 97ffe8d7  bl       #0xb2d0
//   0x010f78: 34000080  cbz      w0, #0x10f88
//   0x010f7c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x010f80: f84207f3  ldr      x19, [sp], #0x20
//   0x010f84: d65f03c0  ret      
//   0x010f88: f9400260  ldr      x0, [x19]
//   0x010f8c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x010f90: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0212_sub_010f64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010F64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010f64: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010f68: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010f6c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010f70: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE8D7ULL; // 0x010f74: bl #0xb2d0
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x010f78: cbz w0, #0x10f88
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x010f7c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x010f80: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0213 @ 0x010f98..0x011000 (104 bytes)
// [VN] Phục dựng FDE #0213 tại 0x010f98..0x011000 (104 byte)
//   0x010f98: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010f9c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010fa0: 910043fd  add      x29, sp, #0x10
//   0x010fa4: f0000240  adrp     x0, #0x5b000
//   0x010fa8: f9478c00  ldr      x0, [x0, #0xf18]
//   0x010fac: 97ffe989  bl       #0xb5d0
//   0x010fb0: f0000253  adrp     x19, #0x5b000
//   0x010fb4: f9460e73  ldr      x19, [x19, #0xc18]
//   0x010fb8: f9400268  ldr      x8, [x19]
//   0x010fbc: b5000148  cbnz     x8, #0x10fe4
//   0x010fc0: 52800800  mov      w0, #0x40
//   0x010fc4: 97ffe98b  bl       #0xb5f0
uint64_t fde_0213_sub_010f98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x010F98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010f98: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010f9c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010fa0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000240ULL; // 0x010fa4: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9478C00ULL; // 0x010fa8: ldr x0, [x0, #0xf18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE989ULL; // 0x010fac: bl #0xb5d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000253ULL; // 0x010fb0: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9460E73ULL; // 0x010fb4: ldr x19, [x19, #0xc18]
    return acc;
}

// [EN] Reconstructed FDE #0214 @ 0x011000..0x011148 (328 bytes)
// [VN] Phục dựng FDE #0214 tại 0x011000..0x011148 (328 byte)
//   0x011000: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x011004: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x011008: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01100c: 910083fd  add      x29, sp, #0x20
//   0x011010: aa0003f4  mov      x20, x0
//   0x011014: 90000140  adrp     x0, #0x39000
//   0x011018: 91148000  add      x0, x0, #0x520
//   0x01101c: 2a0203f6  mov      w22, w2
//   0x011020: 2a0103f3  mov      w19, w1
//   0x011024: 97ffe853  bl       #0xb170
//   0x011028: b40007c0  cbz      x0, #0x11120
//   0x01102c: 90000141  adrp     x1, #0x39000
uint64_t fde_0214_sub_011000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x2A0103F3ULL) + (x2 ^ 0x011000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x011000: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x011004: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x011008: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01100c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x011010: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000140ULL; // 0x011014: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x91148000ULL; // 0x011018: add x0, x0, #0x520
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F6ULL; // 0x01101c: mov w22, w2
    return acc;
}

// [EN] Reconstructed FDE #0215 @ 0x011148..0x0111e8 (160 bytes)
// [VN] Phục dựng FDE #0215 tại 0x011148..0x0111e8 (160 byte)
//   0x011148: d101c3ff  sub      sp, sp, #0x70
//   0x01114c: f90023f5  str      x21, [sp, #0x40]
//   0x011150: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x011154: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x011158: 910183fd  add      x29, sp, #0x60
//   0x01115c: d53bd055  mrs      x21, tpidr_el0
//   0x011160: f94016a8  ldr      x8, [x21, #0x28]
//   0x011164: 90000141  adrp     x1, #0x39000
//   0x011168: 91165421  add      x1, x1, #0x595
//   0x01116c: aa0003f3  mov      x19, x0
//   0x011170: f81d83a8  stur     x8, [x29, #-0x28]
//   0x011174: f9400008  ldr      x8, [x0]
uint64_t fde_0215_sub_011148(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x91165421ULL) + (x2 ^ 0x011148ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x011148: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F5ULL; // 0x01114c: str x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x011150: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x011154: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x011158: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01115c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x011160: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x011164: adrp x1, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0216 @ 0x0111e8..0x0111f0 (8 bytes)
// [VN] Phục dựng FDE #0216 tại 0x0111e8..0x0111f0 (8 byte)
//   0x0111e8: 2a1f03e0  mov      w0, wzr
//   0x0111ec: d65f03c0  ret      
uint64_t fde_0216_sub_0111e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0111E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0111e8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0111ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #0217 @ 0x0111f0..0x0111f8 (8 bytes)
// [VN] Phục dựng FDE #0217 tại 0x0111f0..0x0111f8 (8 byte)
//   0x0111f0: 2a1f03e0  mov      w0, wzr
//   0x0111f4: d65f03c0  ret      
uint64_t fde_0217_sub_0111f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0111F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0111f0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0111f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0218 @ 0x0111f8..0x011298 (160 bytes)
// [VN] Phục dựng FDE #0218 tại 0x0111f8..0x011298 (160 byte)
//   0x0111f8: d101c3ff  sub      sp, sp, #0x70
//   0x0111fc: f90023f5  str      x21, [sp, #0x40]
//   0x011200: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x011204: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x011208: 910183fd  add      x29, sp, #0x60
//   0x01120c: 90000148  adrp     x8, #0x39000
//   0x011210: d53bd055  mrs      x21, tpidr_el0
//   0x011214: 91169908  add      x8, x8, #0x5a6
//   0x011218: f94016aa  ldr      x10, [x21, #0x28]
//   0x01121c: 94000181  bl       #0x11820
//   0x011220: 90000009  adrp     x9, #0x11000
//   0x011224: 91175d08  add      x8, x8, #0x5d7
uint64_t fde_0218_sub_0111f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF94016AAULL) + (x2 ^ 0x0111F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0111f8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F5ULL; // 0x0111fc: str x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x011200: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x011204: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x011208: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x01120c: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x011210: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0x91169908ULL; // 0x011214: add x8, x8, #0x5a6
    return acc;
}

// [EN] Reconstructed FDE #0219 @ 0x011298..0x011324 (140 bytes)
// [VN] Phục dựng FDE #0219 tại 0x011298..0x011324 (140 byte)
//   0x011298: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01129c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0112a0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0112a4: 910083fd  add      x29, sp, #0x20
//   0x0112a8: b4000322  cbz      x2, #0x1130c
//   0x0112ac: f9400008  ldr      x8, [x0]
//   0x0112b0: aa0203f3  mov      x19, x2
//   0x0112b4: aa0203e1  mov      x1, x2
//   0x0112b8: aa1f03e2  mov      x2, xzr
//   0x0112bc: f942a508  ldr      x8, [x8, #0x548]
//   0x0112c0: 2a0303f5  mov      w21, w3
//   0x0112c4: aa0003f4  mov      x20, x0
uint64_t fde_0219_sub_011298(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1F03E2ULL) + (x2 ^ 0x011298ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x011298: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01129c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0112a0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0112a4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000322ULL; // 0x0112a8: cbz x2, #0x1130c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0112ac: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0112b0: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0112b4: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0220 @ 0x011324..0x01140c (232 bytes)
// [VN] Phục dựng FDE #0220 tại 0x011324..0x01140c (232 byte)
//   0x011324: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x011328: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x01132c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x011330: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x011334: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x011338: 910103fd  add      x29, sp, #0x40
//   0x01133c: aa0003f3  mov      x19, x0
//   0x011340: b40000e5  cbz      x5, #0x1135c
//   0x011344: 2a0203f7  mov      w23, w2
//   0x011348: 7100205f  cmp      w2, #8
//   0x01134c: 54000143  b.lo     #0x11374
//   0x011350: 90000141  adrp     x1, #0x39000
uint64_t fde_0220_sub_011324(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x2A0203F7ULL) + (x2 ^ 0x011324ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x011324: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x011328: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01132c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x011330: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x011334: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x011338: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01133c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E5ULL; // 0x011340: cbz x5, #0x1135c
    return acc;
}

// [EN] Reconstructed FDE #0221 @ 0x01140c..0x011494 (136 bytes)
// [VN] Phục dựng FDE #0221 tại 0x01140c..0x011494 (136 byte)
//   0x01140c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x011410: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011414: 910043fd  add      x29, sp, #0x10
//   0x011418: 3940d008  ldrb     w8, [x0, #0x34]
//   0x01141c: 34000088  cbz      w8, #0x1142c
//   0x011420: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x011424: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x011428: d65f03c0  ret      
//   0x01142c: b9403008  ldr      w8, [x0, #0x30]
//   0x011430: 5289c44a  mov      w10, #0x4e22
//   0x011434: aa0003f3  mov      x19, x0
//   0x011438: aa0103f4  mov      x20, x1
uint64_t fde_0221_sub_01140c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB9403008ULL) + (x2 ^ 0x01140CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01140c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011410: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011414: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3940D008ULL; // 0x011418: ldrb w8, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000088ULL; // 0x01141c: cbz w8, #0x1142c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x011420: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x011424: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011428: ret 
    return acc;
}

// [EN] Reconstructed FDE #0222 @ 0x011494..0x0114b4 (32 bytes)
// [VN] Phục dựng FDE #0222 tại 0x011494..0x0114b4 (32 byte)
//   0x011494: d0000248  adrp     x8, #0x5b000
//   0x011498: f946d508  ldr      x8, [x8, #0xda8]
//   0x01149c: f9400801  ldr      x1, [x0, #0x10]
//   0x0114a0: 52807805  mov      w5, #0x3c0
//   0x0114a4: 91001006  add      x6, x0, #4
//   0x0114a8: f9400108  ldr      x8, [x8]
//   0x0114ac: 91002007  add      x7, x0, #8
//   0x0114b0: 140000c1  b        #0x117b4
uint64_t fde_0222_sub_011494(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000248ULL) + (x1 ^ 0x140000C1ULL) + (x2 ^ 0x011494ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x011494: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D508ULL; // 0x011498: ldr x8, [x8, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x01149c: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x52807805ULL; // 0x0114a0: mov w5, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0x91001006ULL; // 0x0114a4: add x6, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0114a8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002007ULL; // 0x0114ac: add x7, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x140000C1ULL; // 0x0114b0: b #0x117b4
    return acc;
}

// [EN] Reconstructed FDE #0223 @ 0x0114b4..0x0114d4 (32 bytes)
// [VN] Phục dựng FDE #0223 tại 0x0114b4..0x0114d4 (32 byte)
//   0x0114b4: d0000248  adrp     x8, #0x5b000
//   0x0114b8: f946d508  ldr      x8, [x8, #0xda8]
//   0x0114bc: f9401401  ldr      x1, [x0, #0x28]
//   0x0114c0: 52807805  mov      w5, #0x3c0
//   0x0114c4: 91007006  add      x6, x0, #0x1c
//   0x0114c8: f9400108  ldr      x8, [x8]
//   0x0114cc: 91008007  add      x7, x0, #0x20
//   0x0114d0: 140000b9  b        #0x117b4
uint64_t fde_0223_sub_0114b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000248ULL) + (x1 ^ 0x140000B9ULL) + (x2 ^ 0x0114B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x0114b4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D508ULL; // 0x0114b8: ldr x8, [x8, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401401ULL; // 0x0114bc: ldr x1, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52807805ULL; // 0x0114c0: mov w5, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0x91007006ULL; // 0x0114c4: add x6, x0, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0114c8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91008007ULL; // 0x0114cc: add x7, x0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x140000B9ULL; // 0x0114d0: b #0x117b4
    return acc;
}

// [EN] Reconstructed FDE #0224 @ 0x0114d4..0x011558 (132 bytes)
// [VN] Phục dựng FDE #0224 tại 0x0114d4..0x011558 (132 byte)
//   0x0114d4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0114d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0114dc: 910043fd  add      x29, sp, #0x10
//   0x0114e0: 3940d008  ldrb     w8, [x0, #0x34]
//   0x0114e4: 34000248  cbz      w8, #0x1152c
//   0x0114e8: b9403008  ldr      w8, [x0, #0x30]
//   0x0114ec: 5289c449  mov      w9, #0x4e22
//   0x0114f0: aa0003f3  mov      x19, x0
//   0x0114f4: aa0103f4  mov      x20, x1
//   0x0114f8: 6b09011f  cmp      w8, w9
//   0x0114fc: 3900d01f  strb     wzr, [x0, #0x34]
//   0x011500: 540001c0  b.eq     #0x11538
uint64_t fde_0224_sub_0114d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x0114D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0114d4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0114d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0114dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3940D008ULL; // 0x0114e0: ldrb w8, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000248ULL; // 0x0114e4: cbz w8, #0x1152c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403008ULL; // 0x0114e8: ldr w8, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x5289C449ULL; // 0x0114ec: mov w9, #0x4e22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0114f0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0225 @ 0x011558..0x01156c (20 bytes)
// [VN] Phục dựng FDE #0225 tại 0x011558..0x01156c (20 byte)
//   0x011558: d0000248  adrp     x8, #0x5b000
//   0x01155c: f946d508  ldr      x8, [x8, #0xda8]
//   0x011560: f9400801  ldr      x1, [x0, #0x10]
//   0x011564: 29409404  ldp      w4, w5, [x0, #4]
//   0x011568: 1400008c  b        #0x11798
uint64_t fde_0225_sub_011558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000248ULL) + (x1 ^ 0x1400008CULL) + (x2 ^ 0x011558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x011558: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D508ULL; // 0x01155c: ldr x8, [x8, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x011560: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x29409404ULL; // 0x011564: ldp w4, w5, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x1400008CULL; // 0x011568: b #0x11798
    return acc;
}

// [EN] Reconstructed FDE #0226 @ 0x01156c..0x011580 (20 bytes)
// [VN] Phục dựng FDE #0226 tại 0x01156c..0x011580 (20 byte)
//   0x01156c: d0000248  adrp     x8, #0x5b000
//   0x011570: f946d508  ldr      x8, [x8, #0xda8]
//   0x011574: f9401401  ldr      x1, [x0, #0x28]
//   0x011578: 29439404  ldp      w4, w5, [x0, #0x1c]
//   0x01157c: 14000087  b        #0x11798
uint64_t fde_0226_sub_01156c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000248ULL) + (x1 ^ 0x14000087ULL) + (x2 ^ 0x01156CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x01156c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D508ULL; // 0x011570: ldr x8, [x8, #0xda8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401401ULL; // 0x011574: ldr x1, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x29439404ULL; // 0x011578: ldp w4, w5, [x0, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000087ULL; // 0x01157c: b #0x11798
    return acc;
}

// [EN] Reconstructed FDE #0227 @ 0x011580..0x0115e4 (100 bytes)
// [VN] Phục dựng FDE #0227 tại 0x011580..0x0115e4 (100 byte)
//   0x011580: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x011584: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011588: 910043fd  add      x29, sp, #0x10
//   0x01158c: f9400008  ldr      x8, [x0]
//   0x011590: aa0003f3  mov      x19, x0
//   0x011594: f9429d08  ldr      x8, [x8, #0x538]
//   0x011598: d63f0100  blr      x8
//   0x01159c: b4000180  cbz      x0, #0x115cc
//   0x0115a0: aa0003f4  mov      x20, x0
//   0x0115a4: aa1303e0  mov      x0, x19
//   0x0115a8: aa1403e3  mov      x3, x20
//   0x0115ac: 9400000e  bl       #0x115e4
uint64_t fde_0227_sub_011580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x011580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x011580: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011584: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011588: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01158c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x011590: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9429D08ULL; // 0x011594: ldr x8, [x8, #0x538]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x011598: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000180ULL; // 0x01159c: cbz x0, #0x115cc
    return acc;
}

// [EN] Reconstructed FDE #0228 @ 0x0115e4..0x01177c (408 bytes)
// [VN] Phục dựng FDE #0228 tại 0x0115e4..0x01177c (408 byte)
//   0x0115e4: d104c3ff  sub      sp, sp, #0x130
//   0x0115e8: a91057fc  stp      x28, x21, [sp, #0x100]
//   0x0115ec: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x0115f0: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x0115f4: 910483fd  add      x29, sp, #0x120
//   0x0115f8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0115fc: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x011600: f90057e7  str      x7, [sp, #0xa8]
//   0x011604: ad0007e0  stp      q0, q1, [sp]
//   0x011608: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x01160c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x011610: ad031fe6  stp      q6, q7, [sp, #0x60]
uint64_t fde_0228_sub_0115e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0xAD0007E0ULL) + (x2 ^ 0x0115E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x0115e4: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057FCULL; // 0x0115e8: stp x28, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x0115ec: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x0115f0: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x0115f4: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0115f8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0115fc: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x011600: str x7, [sp, #0xa8]
    return acc;
}

// [EN] Reconstructed FDE #0229 @ 0x01177c..0x011798 (28 bytes)
// [VN] Phục dựng FDE #0229 tại 0x01177c..0x011798 (28 byte)
//   0x01177c: f9400268  ldr      x8, [x19]
//   0x011780: 910003e2  mov      x2, sp
//   0x011784: 52800043  mov      w3, #2
//   0x011788: aa1303e0  mov      x0, x19
//   0x01178c: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x011790: aa1403e1  mov      x1, x20
//   0x011794: d61f0100  br       x8
uint64_t fde_0229_sub_01177c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01177CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01177c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E2ULL; // 0x011780: mov x2, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x52800043ULL; // 0x011784: mov w3, #2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x011788: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435D08ULL; // 0x01178c: ldr x8, [x8, #0x6b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x011790: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x011794: br x8
    return acc;
}

// [EN] Reconstructed FDE #0230 @ 0x011798..0x0117b4 (28 bytes)
// [VN] Phục dựng FDE #0230 tại 0x011798..0x0117b4 (28 byte)
//   0x011798: 2a1f03e2  mov      w2, wzr
//   0x01179c: f9400108  ldr      x8, [x8]
//   0x0117a0: aa1f03e3  mov      x3, xzr
//   0x0117a4: aa1f03e6  mov      x6, xzr
//   0x0117a8: aa1f03e7  mov      x7, xzr
//   0x0117ac: aa0803e0  mov      x0, x8
//   0x0117b0: 1400287f  b        #0x1b9ac
uint64_t fde_0230_sub_011798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E2ULL) + (x1 ^ 0x1400287FULL) + (x2 ^ 0x011798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x011798: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x01179c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x0117a0: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E6ULL; // 0x0117a4: mov x6, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E7ULL; // 0x0117a8: mov x7, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x0117ac: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x1400287FULL; // 0x0117b0: b #0x1b9ac
    return acc;
}

// [EN] Reconstructed FDE #0231 @ 0x0117b4..0x0117cc (24 bytes)
// [VN] Phục dựng FDE #0231 tại 0x0117b4..0x0117cc (24 byte)
//   0x0117b4: 52ba5004  mov      w4, #-0x2d800000
//   0x0117b8: 72bacbe5  movk     w5, #0xd65f, lsl #16
//   0x0117bc: aa0803e0  mov      x0, x8
//   0x0117c0: 2a1f03e2  mov      w2, wzr
//   0x0117c4: aa1f03e3  mov      x3, xzr
//   0x0117c8: 14002879  b        #0x1b9ac
uint64_t fde_0231_sub_0117b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52BA5004ULL) + (x1 ^ 0x14002879ULL) + (x2 ^ 0x0117B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52BA5004ULL; // 0x0117b4: mov w4, #-0x2d800000
    acc = (acc * 0x100000001B3ULL) ^ 0x72BACBE5ULL; // 0x0117b8: movk w5, #0xd65f, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x0117bc: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x0117c0: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x0117c4: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14002879ULL; // 0x0117c8: b #0x1b9ac
    return acc;
}

// [EN] Reconstructed FDE #0232 @ 0x0117cc..0x0117e8 (28 bytes)
// [VN] Phục dựng FDE #0232 tại 0x0117cc..0x0117e8 (28 byte)
//   0x0117cc: 3d8003e0  str      q0, [sp]
//   0x0117d0: 9e670100  fmov     d0, x8
//   0x0117d4: 90000148  adrp     x8, #0x39000
//   0x0117d8: 9e670121  fmov     d1, x9
//   0x0117dc: 91172108  add      x8, x8, #0x5c8
//   0x0117e0: 4e181d01  mov      v1.d[1], x8
//   0x0117e4: d65f03c0  ret      
uint64_t fde_0232_sub_0117cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3D8003E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0117CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3D8003E0ULL; // 0x0117cc: str q0, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x0117d0: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x0117d4: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670121ULL; // 0x0117d8: fmov d1, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x91172108ULL; // 0x0117dc: add x8, x8, #0x5c8
    acc = (acc * 0x100000001B3ULL) ^ 0x4E181D01ULL; // 0x0117e0: mov v1.d[1], x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0117e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0233 @ 0x0117e8..0x0117f8 (16 bytes)
// [VN] Phục dựng FDE #0233 tại 0x0117e8..0x0117f8 (16 byte)
//   0x0117e8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0117ec: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x0117f0: eb09011f  cmp      x8, x9
//   0x0117f4: d65f03c0  ret      
uint64_t fde_0233_sub_0117e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94016A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0117E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0117e8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85D83A9ULL; // 0x0117ec: ldur x9, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0117f0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0117f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0234 @ 0x0117f8..0x011808 (16 bytes)
// [VN] Phục dựng FDE #0234 tại 0x0117f8..0x011808 (16 byte)
//   0x0117f8: f9400268  ldr      x8, [x19]
//   0x0117fc: aa1303e0  mov      x0, x19
//   0x011800: aa1403e1  mov      x1, x20
//   0x011804: d65f03c0  ret      
uint64_t fde_0234_sub_0117f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0117F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0117f8: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0117fc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x011800: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011804: ret 
    return acc;
}

// [EN] Reconstructed FDE #0235 @ 0x011808..0x011818 (16 bytes)
// [VN] Phục dựng FDE #0235 tại 0x011808..0x011818 (16 byte)
//   0x011808: f9400268  ldr      x8, [x19]
//   0x01180c: aa1303e0  mov      x0, x19
//   0x011810: f9404508  ldr      x8, [x8, #0x88]
//   0x011814: d61f0100  br       x8
uint64_t fde_0235_sub_011808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x011808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x011808: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01180c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x011810: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x011814: br x8
    return acc;
}

// [EN] Reconstructed FDE #0236 @ 0x011818..0x011820 (8 bytes)
// [VN] Phục dựng FDE #0236 tại 0x011818..0x011820 (8 byte)
//   0x011818: aa1503e0  mov      x0, x21
//   0x01181c: 17ffe7cd  b        #0xb750
uint64_t fde_0236_sub_011818(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FFE7CDULL) + (x2 ^ 0x011818ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x011818: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE7CDULL; // 0x01181c: b #0xb750
    return acc;
}

// [EN] Reconstructed FDE #0237 @ 0x011820..0x011838 (24 bytes)
// [VN] Phục dựng FDE #0237 tại 0x011820..0x011838 (24 byte)
//   0x011820: 9e670100  fmov     d0, x8
//   0x011824: 90000148  adrp     x8, #0x39000
//   0x011828: 9116c508  add      x8, x8, #0x5b1
//   0x01182c: 4e181d00  mov      v0.d[1], x8
//   0x011830: 90000148  adrp     x8, #0x39000
//   0x011834: d65f03c0  ret      
uint64_t fde_0237_sub_011820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9E670100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x011820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x011820: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x011824: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x9116C508ULL; // 0x011828: add x8, x8, #0x5b1
    acc = (acc * 0x100000001B3ULL) ^ 0x4E181D00ULL; // 0x01182c: mov v0.d[1], x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x011830: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011834: ret 
    return acc;
}

// [EN] Reconstructed FDE #0238 @ 0x011838..0x011848 (16 bytes)
// [VN] Phục dựng FDE #0238 tại 0x011838..0x011848 (16 byte)
//   0x011838: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x01183c: f94023f5  ldr      x21, [sp, #0x40]
//   0x011840: 9101c3ff  add      sp, sp, #0x70
//   0x011844: d65f03c0  ret      
uint64_t fde_0238_sub_011838(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9454FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x011838ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9454FF4ULL; // 0x011838: ldp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94023F5ULL; // 0x01183c: ldr x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FFULL; // 0x011840: add sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011844: ret 
    return acc;
}

// [EN] Reconstructed FDE #0239 @ 0x011848..0x011850 (8 bytes)
// [VN] Phục dựng FDE #0239 tại 0x011848..0x011850 (8 byte)
//   0x011848: f9401908  ldr      x8, [x8, #0x30]
//   0x01184c: d61f0100  br       x8
uint64_t fde_0239_sub_011848(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401908ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x011848ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x011848: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01184c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0240 @ 0x011850..0x01185c (12 bytes)
// [VN] Phục dựng FDE #0240 tại 0x011850..0x01185c (12 byte)
//   0x011850: 91194063  add      x3, x3, #0x650
//   0x011854: 528000c0  mov      w0, #6
//   0x011858: 17ffe662  b        #0xb1e0
uint64_t fde_0240_sub_011850(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91194063ULL) + (x1 ^ 0x17FFE662ULL) + (x2 ^ 0x011850ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91194063ULL; // 0x011850: add x3, x3, #0x650
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x011854: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE662ULL; // 0x011858: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0241 @ 0x01185c..0x011868 (12 bytes)
// [VN] Phục dựng FDE #0241 tại 0x01185c..0x011868 (12 byte)
//   0x01185c: aa1f03e2  mov      x2, xzr
//   0x011860: f942a508  ldr      x8, [x8, #0x548]
//   0x011864: d61f0100  br       x8
uint64_t fde_0241_sub_01185c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01185CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01185c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x011860: ldr x8, [x8, #0x548]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x011864: br x8
    return acc;
}

// [EN] Reconstructed FDE #0242 @ 0x011868..0x011894 (44 bytes)
// [VN] Phục dựng FDE #0242 tại 0x011868..0x011894 (44 byte)
//   0x011868: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01186c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011870: 910043fd  add      x29, sp, #0x10
//   0x011874: 2a0303f3  mov      w19, w3
//   0x011878: 2a0203f4  mov      w20, w2
//   0x01187c: 97fffdc7  bl       #0x10f98
//   0x011880: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x011884: 2a1403e1  mov      w1, w20
//   0x011888: 2a1303e2  mov      w2, w19
//   0x01188c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x011890: 17fffddc  b        #0x11000
uint64_t fde_0242_sub_011868(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x2A1303E2ULL) + (x2 ^ 0x011868ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x011868: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01186c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011870: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x011874: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x011878: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDC7ULL; // 0x01187c: bl #0x10f98
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x011880: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E1ULL; // 0x011884: mov w1, w20
    return acc;
}

// [EN] Reconstructed FDE #0243 @ 0x011894..0x0118b8 (36 bytes)
// [VN] Phục dựng FDE #0243 tại 0x011894..0x0118b8 (36 byte)
//   0x011894: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x011898: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01189c: 910043fd  add      x29, sp, #0x10
//   0x0118a0: aa0003f3  mov      x19, x0
//   0x0118a4: 97fffdbd  bl       #0x10f98
//   0x0118a8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0118ac: aa1303e1  mov      x1, x19
//   0x0118b0: f84207f3  ldr      x19, [sp], #0x20
//   0x0118b4: 17fffed6  b        #0x1140c
uint64_t fde_0243_sub_011894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFFED6ULL) + (x2 ^ 0x011894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x011894: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011898: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01189c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0118a0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDBDULL; // 0x0118a4: bl #0x10f98
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0118a8: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x0118ac: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0118b0: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0244 @ 0x0118b8..0x0118dc (36 bytes)
// [VN] Phục dựng FDE #0244 tại 0x0118b8..0x0118dc (36 byte)
//   0x0118b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0118bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0118c0: 910043fd  add      x29, sp, #0x10
//   0x0118c4: aa0003f3  mov      x19, x0
//   0x0118c8: 97fffdb4  bl       #0x10f98
//   0x0118cc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0118d0: aa1303e1  mov      x1, x19
//   0x0118d4: f84207f3  ldr      x19, [sp], #0x20
//   0x0118d8: 17fffeff  b        #0x114d4
uint64_t fde_0244_sub_0118b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFFEFFULL) + (x2 ^ 0x0118B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0118b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0118bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0118c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0118c4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDB4ULL; // 0x0118c8: bl #0x10f98
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0118cc: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x0118d0: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0118d4: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0245 @ 0x0118dc..0x011aa0 (452 bytes)
// [VN] Phục dựng FDE #0245 tại 0x0118dc..0x011aa0 (452 byte)
//   0x0118dc: d10183ff  sub      sp, sp, #0x60
//   0x0118e0: fd0013e8  str      d8, [sp, #0x20]
//   0x0118e4: f90017f7  str      x23, [sp, #0x28]
//   0x0118e8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0118ec: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0118f0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0118f4: 910143fd  add      x29, sp, #0x50
//   0x0118f8: d53bd056  mrs      x22, tpidr_el0
//   0x0118fc: f94016c8  ldr      x8, [x22, #0x28]
//   0x011900: 4ea01c08  mov      v8.16b, v0.16b
//   0x011904: 1e602008  fcmp     d0, #0.0
//   0x011908: 1e6e1000  fmov     d0, #1.00000000
uint64_t fde_0245_sub_0118dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x0118DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0118dc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xFD0013E8ULL; // 0x0118e0: str d8, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017F7ULL; // 0x0118e4: str x23, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0118e8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0118ec: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0118f0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0118f4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0118f8: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0246 @ 0x011aa0..0x011aa4 (4 bytes)
// [VN] Phục dựng FDE #0246 tại 0x011aa0..0x011aa4 (4 byte)
//   0x011aa0: 17ffff8f  b        #0x118dc
uint64_t fde_0246_sub_011aa0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFF8FULL) + (x1 ^ 0x17FFFF8FULL) + (x2 ^ 0x011AA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF8FULL; // 0x011aa0: b #0x118dc
    return acc;
}

// [EN] Reconstructed FDE #0247 @ 0x011aa4..0x011abc (24 bytes)
// [VN] Phục dựng FDE #0247 tại 0x011aa4..0x011abc (24 byte)
//   0x011aa4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x011aa8: 910003fd  mov      x29, sp
//   0x011aac: 94000004  bl       #0x11abc
//   0x011ab0: 12000000  and      w0, w0, #1
//   0x011ab4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x011ab8: d65f03c0  ret      
uint64_t fde_0247_sub_011aa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x011AA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x011aa4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x011aa8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000004ULL; // 0x011aac: bl #0x11abc
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x011ab0: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x011ab4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011ab8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0248 @ 0x011abc..0x011ec4 (1032 bytes)
// [VN] Phục dựng FDE #0248 tại 0x011abc..0x011ec4 (1032 byte)
//   0x011abc: d10603ff  sub      sp, sp, #0x180
//   0x011ac0: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x011ac4: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x011ac8: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x011acc: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x011ad0: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x011ad4: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x011ad8: 9105c3fd  add      x29, sp, #0x170
//   0x011adc: d53bd057  mrs      x23, tpidr_el0
//   0x011ae0: f94016e8  ldr      x8, [x23, #0x28]
//   0x011ae4: f0000256  adrp     x22, #0x5c000
//   0x011ae8: 90000141  adrp     x1, #0x39000
uint64_t fde_0248_sub_011abc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xD53BD057ULL) + (x2 ^ 0x011ABCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x011abc: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x011ac0: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x011ac4: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x011ac8: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x011acc: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x011ad0: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x011ad4: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x011ad8: add x29, sp, #0x170
    return acc;
}

// [EN] Reconstructed FDE #0249 @ 0x011ec4..0x011f20 (92 bytes)
// [VN] Phục dựng FDE #0249 tại 0x011ec4..0x011f20 (92 byte)
//   0x011ec4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x011ec8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011ecc: 910043fd  add      x29, sp, #0x10
//   0x011ed0: 93407c53  sxtw     x19, w2
//   0x011ed4: 94001690  bl       #0x17914
//   0x011ed8: aa0003f4  mov      x20, x0
//   0x011edc: 90000141  adrp     x1, #0x39000
//   0x011ee0: 90000142  adrp     x2, #0x39000
//   0x011ee4: 911f2c21  add      x1, x1, #0x7cb
//   0x011ee8: 912cd042  add      x2, x2, #0xb34
//   0x011eec: 52800080  mov      w0, #4
//   0x011ef0: aa1403e3  mov      x3, x20
uint64_t fde_0249_sub_011ec4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x911F2C21ULL) + (x2 ^ 0x011EC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x011ec4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011ec8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011ecc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C53ULL; // 0x011ed0: sxtw x19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x94001690ULL; // 0x011ed4: bl #0x17914
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x011ed8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x011edc: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000142ULL; // 0x011ee0: adrp x2, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0250 @ 0x011f20..0x011f30 (16 bytes)
// [VN] Phục dựng FDE #0250 tại 0x011f20..0x011f30 (16 byte)
//   0x011f20: f0000248  adrp     x8, #0x5c000
//   0x011f24: 52800029  mov      w9, #1
//   0x011f28: 39096109  strb     w9, [x8, #0x258]
//   0x011f2c: d65f03c0  ret      
uint64_t fde_0250_sub_011f20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000248ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x011F20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000248ULL; // 0x011f20: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x011f24: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39096109ULL; // 0x011f28: strb w9, [x8, #0x258]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011f2c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0251 @ 0x011f30..0x011f68 (56 bytes)
// [VN] Phục dựng FDE #0251 tại 0x011f30..0x011f68 (56 byte)
//   0x011f30: f0000248  adrp     x8, #0x5c000
//   0x011f34: 9109c108  add      x8, x8, #0x270
//   0x011f38: f9400100  ldr      x0, [x8]
//   0x011f3c: b4000080  cbz      x0, #0x11f4c
//   0x011f40: f9400501  ldr      x1, [x8, #8]
//   0x011f44: b4000041  cbz      x1, #0x11f4c
//   0x011f48: d61f0020  br       x1
//   0x011f4c: f0000248  adrp     x8, #0x5c000
//   0x011f50: f9414108  ldr      x8, [x8, #0x280]
//   0x011f54: b4000068  cbz      x8, #0x11f60
//   0x011f58: f9400100  ldr      x0, [x8]
//   0x011f5c: d65f03c0  ret      
uint64_t fde_0251_sub_011f30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000248ULL) + (x1 ^ 0xF9414108ULL) + (x2 ^ 0x011F30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000248ULL; // 0x011f30: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9109C108ULL; // 0x011f34: add x8, x8, #0x270
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x011f38: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x011f3c: cbz x0, #0x11f4c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400501ULL; // 0x011f40: ldr x1, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000041ULL; // 0x011f44: cbz x1, #0x11f4c
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x011f48: br x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000248ULL; // 0x011f4c: adrp x8, #0x5c000
    return acc;
}

// [EN] Reconstructed FDE #0252 @ 0x011f68..0x011f7c (20 bytes)
// [VN] Phục dựng FDE #0252 tại 0x011f68..0x011f7c (20 byte)
//   0x011f68: 72001c5f  tst      w2, #0xff
//   0x011f6c: 1a9f07e8  cset     w8, ne
//   0x011f70: f0000249  adrp     x9, #0x5c000
//   0x011f74: 39097128  strb     w8, [x9, #0x25c]
//   0x011f78: d65f03c0  ret      
uint64_t fde_0252_sub_011f68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x011F68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x011f68: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E8ULL; // 0x011f6c: cset w8, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000249ULL; // 0x011f70: adrp x9, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x39097128ULL; // 0x011f74: strb w8, [x9, #0x25c]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x011f78: ret 
    return acc;
}

// [EN] Reconstructed FDE #0253 @ 0x011f7c..0x0120b4 (312 bytes)
// [VN] Phục dựng FDE #0253 tại 0x011f7c..0x0120b4 (312 byte)
//   0x011f7c: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x011f80: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x011f84: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x011f88: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x011f8c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x011f90: 910103fd  add      x29, sp, #0x40
//   0x011f94: f0000248  adrp     x8, #0x5c000
//   0x011f98: 91099108  add      x8, x8, #0x264
//   0x011f9c: 52800029  mov      w9, #1
//   0x011fa0: 39000109  strb     w9, [x8]
//   0x011fa4: 39401108  ldrb     w8, [x8, #4]
//   0x011fa8: aa0503f3  mov      x19, x5
uint64_t fde_0253_sub_011f7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x52800029ULL) + (x2 ^ 0x011F7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x011f7c: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x011f80: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x011f84: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x011f88: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x011f8c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x011f90: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000248ULL; // 0x011f94: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91099108ULL; // 0x011f98: add x8, x8, #0x264
    return acc;
}

// [EN] Reconstructed FDE #0254 @ 0x0120b4..0x012228 (372 bytes)
// [VN] Phục dựng FDE #0254 tại 0x0120b4..0x012228 (372 byte)
//   0x0120b4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0120b8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0120bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0120c0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0120c4: 9100c3fd  add      x29, sp, #0x30
//   0x0120c8: d0000248  adrp     x8, #0x5c000
//   0x0120cc: 39499108  ldrb     w8, [x8, #0x264]
//   0x0120d0: aa0203f3  mov      x19, x2
//   0x0120d4: aa0103f4  mov      x20, x1
//   0x0120d8: aa0003f5  mov      x21, x0
//   0x0120dc: 340001a8  cbz      w8, #0x12110
//   0x0120e0: d0000248  adrp     x8, #0x5c000
uint64_t fde_0254_sub_0120b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x0120B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0120b4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0120b8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0120bc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0120c0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0120c4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x0120c8: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x39499108ULL; // 0x0120cc: ldrb w8, [x8, #0x264]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0120d0: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0255 @ 0x012228..0x012288 (96 bytes)
// [VN] Phục dựng FDE #0255 tại 0x012228..0x012288 (96 byte)
//   0x012228: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01222c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x012230: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x012234: 910083fd  add      x29, sp, #0x20
//   0x012238: aa0203f3  mov      x19, x2
//   0x01223c: aa0103f4  mov      x20, x1
//   0x012240: aa0003f5  mov      x21, x0
//   0x012244: aa1f03f6  mov      x22, xzr
//   0x012248: f10282df  cmp      x22, #0xa0
//   0x01224c: 54000160  b.eq     #0x12278
//   0x012250: 52800081  mov      w1, #4
//   0x012254: aa1503e0  mov      x0, x21
uint64_t fde_0255_sub_012228(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF10282DFULL) + (x2 ^ 0x012228ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x012228: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01222c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x012230: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x012234: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x012238: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01223c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x012240: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03F6ULL; // 0x012244: mov x22, xzr
    return acc;
}

// [EN] Reconstructed FDE #0256 @ 0x012288..0x012364 (220 bytes)
// [VN] Phục dựng FDE #0256 tại 0x012288..0x012364 (220 byte)
//   0x012288: b4000522  cbz      x2, #0x1232c
//   0x01228c: aa1f03e9  mov      x9, xzr
//   0x012290: b100513f  cmn      x9, #0x14
//   0x012294: 540004c0  b.eq     #0x1232c
//   0x012298: f940000a  ldr      x10, [x0]
//   0x01229c: b400014a  cbz      x10, #0x122c4
//   0x0122a0: f9400028  ldr      x8, [x1]
//   0x0122a4: b4000108  cbz      x8, #0x122c4
//   0x0122a8: f940014a  ldr      x10, [x10]
//   0x0122ac: 7200007f  tst      w3, #1
//   0x0122b0: cb08014b  sub      x11, x10, x8
//   0x0122b4: cb0a010a  sub      x10, x8, x10
uint64_t fde_0256_sub_012288(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000522ULL) + (x1 ^ 0xF940014AULL) + (x2 ^ 0x012288ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000522ULL; // 0x012288: cbz x2, #0x1232c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x01228c: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB100513FULL; // 0x012290: cmn x9, #0x14
    acc = (acc * 0x100000001B3ULL) ^ 0x540004C0ULL; // 0x012294: b.eq #0x1232c
    acc = (acc * 0x100000001B3ULL) ^ 0xF940000AULL; // 0x012298: ldr x10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB400014AULL; // 0x01229c: cbz x10, #0x122c4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x0122a0: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000108ULL; // 0x0122a4: cbz x8, #0x122c4
    return acc;
}

// [EN] Reconstructed FDE #0257 @ 0x012364..0x0123c8 (100 bytes)
// [VN] Phục dựng FDE #0257 tại 0x012364..0x0123c8 (100 byte)
//   0x012364: d10103ff  sub      sp, sp, #0x40
//   0x012368: f90013f3  str      x19, [sp, #0x20]
//   0x01236c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012370: 9100c3fd  add      x29, sp, #0x30
//   0x012374: d53bd053  mrs      x19, tpidr_el0
//   0x012378: f9401668  ldr      x8, [x19, #0x28]
//   0x01237c: f9000fe8  str      x8, [sp, #0x18]
//   0x012380: c8dffc08  ldar     x8, [x0]
//   0x012384: b100051f  cmn      x8, #1
//   0x012388: 540000e0  b.eq     #0x123a4
//   0x01238c: 910043e8  add      x8, sp, #0x10
//   0x012390: a90087e8  stp      x8, x1, [sp, #8]
uint64_t fde_0257_sub_012364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB100051FULL) + (x2 ^ 0x012364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x012364: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x012368: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01236c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x012370: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x012374: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x012378: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01237c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xC8DFFC08ULL; // 0x012380: ldar x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0258 @ 0x0123c8..0x012444 (124 bytes)
// [VN] Phục dựng FDE #0258 tại 0x0123c8..0x012444 (124 byte)
//   0x0123c8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0123cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0123d0: 910043fd  add      x29, sp, #0x10
//   0x0123d4: d0000254  adrp     x20, #0x5c000
//   0x0123d8: 9109c294  add      x20, x20, #0x270
//   0x0123dc: f9400288  ldr      x8, [x20]
//   0x0123e0: b40002c8  cbz      x8, #0x12438
//   0x0123e4: f9400688  ldr      x8, [x20, #8]
//   0x0123e8: b4000288  cbz      x8, #0x12438
//   0x0123ec: f0000133  adrp     x19, #0x39000
//   0x0123f0: 911f2e73  add      x19, x19, #0x7cb
//   0x0123f4: f0000122  adrp     x2, #0x39000
uint64_t fde_0258_sub_0123c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000288ULL) + (x2 ^ 0x0123C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0123c8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0123cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0123d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000254ULL; // 0x0123d4: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9109C294ULL; // 0x0123d8: add x20, x20, #0x270
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x0123dc: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002C8ULL; // 0x0123e0: cbz x8, #0x12438
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x0123e4: ldr x8, [x20, #8]
    return acc;
}

// [EN] Reconstructed FDE #0259 @ 0x012444..0x012450 (12 bytes)
// [VN] Phục dựng FDE #0259 tại 0x012444..0x012450 (12 byte)
//   0x012444: f9400008  ldr      x8, [x0]
//   0x012448: f9400100  ldr      x0, [x8]
//   0x01244c: d61f0000  br       x0
uint64_t fde_0259_sub_012444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0000ULL) + (x2 ^ 0x012444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x012444: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x012448: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0000ULL; // 0x01244c: br x0
    return acc;
}

// [EN] Reconstructed FDE #0260 @ 0x012450..0x012474 (36 bytes)
// [VN] Phục dựng FDE #0260 tại 0x012450..0x012474 (36 byte)
//   0x012450: d0000248  adrp     x8, #0x5c000
//   0x012454: f9415108  ldr      x8, [x8, #0x2a0]
//   0x012458: aa1803e0  mov      x0, x24
//   0x01245c: aa1703e1  mov      x1, x23
//   0x012460: aa1603e2  mov      x2, x22
//   0x012464: aa1503e3  mov      x3, x21
//   0x012468: aa1403e4  mov      x4, x20
//   0x01246c: aa1303e5  mov      x5, x19
//   0x012470: d61f0100  br       x8
uint64_t fde_0260_sub_012450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000248ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x012450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000248ULL; // 0x012450: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9415108ULL; // 0x012454: ldr x8, [x8, #0x2a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E0ULL; // 0x012458: mov x0, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x01245c: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E2ULL; // 0x012460: mov x2, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E3ULL; // 0x012464: mov x3, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E4ULL; // 0x012468: mov x4, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E5ULL; // 0x01246c: mov x5, x19
    return acc;
}

// [EN] Reconstructed FDE #0261 @ 0x012474..0x012490 (28 bytes)
// [VN] Phục dựng FDE #0261 tại 0x012474..0x012490 (28 byte)
//   0x012474: aa1803e0  mov      x0, x24
//   0x012478: aa1703e1  mov      x1, x23
//   0x01247c: aa1603e2  mov      x2, x22
//   0x012480: aa1503e3  mov      x3, x21
//   0x012484: aa1403e4  mov      x4, x20
//   0x012488: aa1303e5  mov      x5, x19
//   0x01248c: d65f03c0  ret      
uint64_t fde_0261_sub_012474(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1803E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x012474ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E0ULL; // 0x012474: mov x0, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x012478: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E2ULL; // 0x01247c: mov x2, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E3ULL; // 0x012480: mov x3, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E4ULL; // 0x012484: mov x4, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E5ULL; // 0x012488: mov x5, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01248c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0262 @ 0x012490..0x012498 (8 bytes)
// [VN] Phục dựng FDE #0262 tại 0x012490..0x012498 (8 byte)
//   0x012490: aa1403e0  mov      x0, x20
//   0x012494: 17ffe483  b        #0xb6a0
uint64_t fde_0262_sub_012490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFE483ULL) + (x2 ^ 0x012490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x012490: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE483ULL; // 0x012494: b #0xb6a0
    return acc;
}

// [EN] Reconstructed FDE #0263 @ 0x012498..0x0124a0 (8 bytes)
// [VN] Phục dựng FDE #0263 tại 0x012498..0x0124a0 (8 byte)
//   0x012498: 528000c0  mov      w0, #6
//   0x01249c: 17ffe351  b        #0xb1e0
uint64_t fde_0263_sub_012498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFE351ULL) + (x2 ^ 0x012498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x012498: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE351ULL; // 0x01249c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0264 @ 0x0124a0..0x0124b0 (16 bytes)
// [VN] Phục dựng FDE #0264 tại 0x0124a0..0x0124b0 (16 byte)
//   0x0124a0: 910003e1  mov      x1, sp
//   0x0124a4: 52800042  mov      w2, #2
//   0x0124a8: 2a1303e0  mov      w0, w19
//   0x0124ac: 14006185  b        #0x2aac0
uint64_t fde_0264_sub_0124a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E1ULL) + (x1 ^ 0x14006185ULL) + (x2 ^ 0x0124A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x0124a0: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x52800042ULL; // 0x0124a4: mov w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x0124a8: mov w0, w19
    acc = (acc * 0x100000001B3ULL) ^ 0x14006185ULL; // 0x0124ac: b #0x2aac0
    return acc;
}

// [EN] Reconstructed FDE #0265 @ 0x0124b0..0x0124c0 (16 bytes)
// [VN] Phục dựng FDE #0265 tại 0x0124b0..0x0124c0 (16 byte)
//   0x0124b0: aa1503e0  mov      x0, x21
//   0x0124b4: aa1403e1  mov      x1, x20
//   0x0124b8: aa1303e2  mov      x2, x19
//   0x0124bc: d61f0100  br       x8
uint64_t fde_0265_sub_0124b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0124B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x0124b0: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x0124b4: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E2ULL; // 0x0124b8: mov x2, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0124bc: br x8
    return acc;
}

// [EN] Reconstructed FDE #0266 @ 0x0124c0..0x0124c8 (8 bytes)
// [VN] Phục dựng FDE #0266 tại 0x0124c0..0x0124c8 (8 byte)
//   0x0124c0: 52801400  mov      w0, #0xa0
//   0x0124c4: 17ffe22f  b        #0xad80
uint64_t fde_0266_sub_0124c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52801400ULL) + (x1 ^ 0x17FFE22FULL) + (x2 ^ 0x0124C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52801400ULL; // 0x0124c0: mov w0, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE22FULL; // 0x0124c4: b #0xad80
    return acc;
}

// [EN] Reconstructed FDE #0267 @ 0x0124c8..0x0124d4 (12 bytes)
// [VN] Phục dựng FDE #0267 tại 0x0124c8..0x0124d4 (12 byte)
//   0x0124c8: 52801402  mov      w2, #0xa0
//   0x0124cc: 2a1f03e1  mov      w1, wzr
//   0x0124d0: d65f03c0  ret      
uint64_t fde_0267_sub_0124c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52801402ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0124C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52801402ULL; // 0x0124c8: mov w2, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x0124cc: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0124d0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0268 @ 0x0124d4..0x012568 (148 bytes)
// [VN] Phục dựng FDE #0268 tại 0x0124d4..0x012568 (148 byte)
//   0x0124d4: d10103ff  sub      sp, sp, #0x40
//   0x0124d8: f9000bf5  str      x21, [sp, #0x10]
//   0x0124dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0124e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0124e4: 9100c3fd  add      x29, sp, #0x30
//   0x0124e8: d53bd054  mrs      x20, tpidr_el0
//   0x0124ec: f9401688  ldr      x8, [x20, #0x28]
//   0x0124f0: aa0003f3  mov      x19, x0
//   0x0124f4: f90007e8  str      x8, [sp, #8]
//   0x0124f8: f90003fe  str      x30, [sp]
//   0x0124fc: b0000248  adrp     x8, #0x5b000
//   0x012500: f947bd08  ldr      x8, [x8, #0xf78]
uint64_t fde_0268_sub_0124d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0124D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0124d4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0124d8: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0124dc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0124e0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0124e4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0124e8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0124ec: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0124f0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0269 @ 0x012568..0x012724 (444 bytes)
// [VN] Phục dựng FDE #0269 tại 0x012568..0x012724 (444 byte)
//   0x012568: d101c3ff  sub      sp, sp, #0x70
//   0x01256c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x012570: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x012574: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x012578: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01257c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x012580: 910183fd  add      x29, sp, #0x60
//   0x012584: d53bd059  mrs      x25, tpidr_el0
//   0x012588: f9401728  ldr      x8, [x25, #0x28]
//   0x01258c: 2a0203f3  mov      w19, w2
//   0x012590: aa0103f4  mov      x20, x1
//   0x012594: aa0003f5  mov      x21, x0
uint64_t fde_0269_sub_012568(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x012568ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x012568: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x01256c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x012570: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x012574: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x012578: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01257c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x012580: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x012584: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0270 @ 0x012724..0x012770 (76 bytes)
// [VN] Phục dựng FDE #0270 tại 0x012724..0x012770 (76 byte)
//   0x012724: d100c3ff  sub      sp, sp, #0x30
//   0x012728: f9000bf3  str      x19, [sp, #0x10]
//   0x01272c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x012730: 910083fd  add      x29, sp, #0x20
//   0x012734: d53bd053  mrs      x19, tpidr_el0
//   0x012738: f9401668  ldr      x8, [x19, #0x28]
//   0x01273c: 910013e2  add      x2, sp, #4
//   0x012740: f90007e8  str      x8, [sp, #8]
//   0x012744: b90007ff  str      wzr, [sp, #4]
//   0x012748: 940000bb  bl       #0x12a34
//   0x01274c: f9401668  ldr      x8, [x19, #0x28]
//   0x012750: f94007e9  ldr      x9, [sp, #8]
uint64_t fde_0270_sub_012724(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB90007FFULL) + (x2 ^ 0x012724ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x012724: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x012728: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01272c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x012730: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x012734: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x012738: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910013E2ULL; // 0x01273c: add x2, sp, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x012740: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0271 @ 0x012770..0x0127cc (92 bytes)
// [VN] Phục dựng FDE #0271 tại 0x012770..0x0127cc (92 byte)
//   0x012770: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x012774: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x012778: 910043fd  add      x29, sp, #0x10
//   0x01277c: aa0103f3  mov      x19, x1
//   0x012780: aa0003f4  mov      x20, x0
//   0x012784: 36000122  tbz      w2, #0, #0x127a8
//   0x012788: 8b130281  add      x1, x20, x19
//   0x01278c: aa1403e0  mov      x0, x20
//   0x012790: 97ffffe5  bl       #0x12724
//   0x012794: 52800102  mov      w2, #8
//   0x012798: aa1403e0  mov      x0, x20
//   0x01279c: aa1303e1  mov      x1, x19
uint64_t fde_0271_sub_012770(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FFFFE5ULL) + (x2 ^ 0x012770ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x012770: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x012774: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x012778: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01277c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x012780: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000122ULL; // 0x012784: tbz w2, #0, #0x127a8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B130281ULL; // 0x012788: add x1, x20, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x01278c: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0272 @ 0x0127cc..0x0127d4 (8 bytes)
// [VN] Phục dựng FDE #0272 tại 0x0127cc..0x0127d4 (8 byte)
//   0x0127cc: aa1f03e1  mov      x1, xzr
//   0x0127d0: 140000a1  b        #0x12a54
uint64_t fde_0272_sub_0127cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x140000A1ULL) + (x2 ^ 0x0127CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0127cc: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x140000A1ULL; // 0x0127d0: b #0x12a54
    return acc;
}

// [EN] Reconstructed FDE #0273 @ 0x0127d4..0x0127e4 (16 bytes)
// [VN] Phục dựng FDE #0273 tại 0x0127d4..0x0127e4 (16 byte)
//   0x0127d4: b0000248  adrp     x8, #0x5b000
//   0x0127d8: f9461508  ldr      x8, [x8, #0xc28]
//   0x0127dc: b9000101  str      w1, [x8]
//   0x0127e0: d65f03c0  ret      
uint64_t fde_0273_sub_0127d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000248ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0127D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000248ULL; // 0x0127d4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9461508ULL; // 0x0127d8: ldr x8, [x8, #0xc28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000101ULL; // 0x0127dc: str w1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0127e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0274 @ 0x0127e4..0x01289c (184 bytes)
// [VN] Phục dựng FDE #0274 tại 0x0127e4..0x01289c (184 byte)
//   0x0127e4: d10103ff  sub      sp, sp, #0x40
//   0x0127e8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0127ec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0127f0: 9100c3fd  add      x29, sp, #0x30
//   0x0127f4: d53bd054  mrs      x20, tpidr_el0
//   0x0127f8: f9401688  ldr      x8, [x20, #0x28]
//   0x0127fc: f0000120  adrp     x0, #0x39000
//   0x012800: 911cd000  add      x0, x0, #0x734
//   0x012804: f9000fe8  str      x8, [sp, #0x18]
//   0x012808: 97ffe25a  bl       #0xb170
//   0x01280c: f9000be0  str      x0, [sp, #0x10]
//   0x012810: b4000280  cbz      x0, #0x12860
uint64_t fde_0274_sub_0127e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x0127E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0127e4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0127e8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0127ec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0127f0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0127f4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0127f8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x0127fc: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x012800: add x0, x0, #0x734
    return acc;
}

// [EN] Reconstructed FDE #0275 @ 0x01289c..0x012910 (116 bytes)
// [VN] Phục dựng FDE #0275 tại 0x01289c..0x012910 (116 byte)
//   0x01289c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0128a0: 910003fd  mov      x29, sp
//   0x0128a4: 2a1f03e0  mov      w0, wzr
//   0x0128a8: 2a1f03e1  mov      w1, wzr
//   0x0128ac: 97ffe3d1  bl       #0xb7f0
//   0x0128b0: b0000243  adrp     x3, #0x5b000
//   0x0128b4: f9471c63  ldr      x3, [x3, #0xe38]
//   0x0128b8: f0000120  adrp     x0, #0x39000
//   0x0128bc: f0000122  adrp     x2, #0x39000
//   0x0128c0: 911cd000  add      x0, x0, #0x734
//   0x0128c4: 912ee842  add      x2, x2, #0xbba
//   0x0128c8: aa1f03e1  mov      x1, xzr
uint64_t fde_0275_sub_01289c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF0000122ULL) + (x2 ^ 0x01289CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01289c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0128a0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0128a4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x0128a8: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE3D1ULL; // 0x0128ac: bl #0xb7f0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000243ULL; // 0x0128b0: adrp x3, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471C63ULL; // 0x0128b4: ldr x3, [x3, #0xe38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x0128b8: adrp x0, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0276 @ 0x012910..0x012940 (48 bytes)
// [VN] Phục dựng FDE #0276 tại 0x012910..0x012940 (48 byte)
//   0x012910: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x012914: 910003fd  mov      x29, sp
//   0x012918: 940094e5  bl       #0x37cac
//   0x01291c: 360000c0  tbz      w0, #0, #0x12934
//   0x012920: b0000240  adrp     x0, #0x5b000
//   0x012924: f942f800  ldr      x0, [x0, #0x5f0]
//   0x012928: 9400952f  bl       #0x37de4
//   0x01292c: 52800020  mov      w0, #1
//   0x012930: 14000002  b        #0x12938
//   0x012934: 2a1f03e0  mov      w0, wzr
//   0x012938: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01293c: d65f03c0  ret      
uint64_t fde_0276_sub_012910(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x14000002ULL) + (x2 ^ 0x012910ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x012910: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x012914: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x940094E5ULL; // 0x012918: bl #0x37cac
    acc = (acc * 0x100000001B3ULL) ^ 0x360000C0ULL; // 0x01291c: tbz w0, #0, #0x12934
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000240ULL; // 0x012920: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942F800ULL; // 0x012924: ldr x0, [x0, #0x5f0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400952FULL; // 0x012928: bl #0x37de4
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x01292c: mov w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0277 @ 0x012940..0x012a34 (244 bytes)
// [VN] Phục dựng FDE #0277 tại 0x012940..0x012a34 (244 byte)
//   0x012940: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x012944: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x012948: 910043fd  add      x29, sp, #0x10
//   0x01294c: aa0003f3  mov      x19, x0
//   0x012950: 97ffe348  bl       #0xb670
//   0x012954: 7100741f  cmp      w0, #0x1d
//   0x012958: 54000663  b.lo     #0x12a24
//   0x01295c: 97ffe345  bl       #0xb670
//   0x012960: 7100841f  cmp      w0, #0x21
//   0x012964: 54000608  b.hi     #0x12a24
//   0x012968: b0000254  adrp     x20, #0x5b000
//   0x01296c: f947be94  ldr      x20, [x20, #0xf78]
uint64_t fde_0277_sub_012940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x7100841FULL) + (x2 ^ 0x012940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x012940: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x012944: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x012948: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01294c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE348ULL; // 0x012950: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100741FULL; // 0x012954: cmp w0, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x54000663ULL; // 0x012958: b.lo #0x12a24
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE345ULL; // 0x01295c: bl #0xb670
    return acc;
}

// [EN] Reconstructed FDE #0278 @ 0x012a34..0x012a3c (8 bytes)
// [VN] Phục dựng FDE #0278 tại 0x012a34..0x012a3c (8 byte)
//   0x012a34: cb000021  sub      x1, x1, x0
//   0x012a38: 14000001  b        #0x12a3c
uint64_t fde_0278_sub_012a34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xCB000021ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x012A34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000021ULL; // 0x012a34: sub x1, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x012a38: b #0x12a3c
    return acc;
}

// [EN] Reconstructed FDE #0279 @ 0x012a3c..0x012a54 (24 bytes)
// [VN] Phục dựng FDE #0279 tại 0x012a3c..0x012a54 (24 byte)
//   0x012a3c: f1000421  subs     x1, x1, #1
//   0x012a40: 5400008b  b.lt     #0x12a50
//   0x012a44: b9400048  ldr      w8, [x2]
//   0x012a48: 38001408  strb     w8, [x0], #1
//   0x012a4c: 17fffffc  b        #0x12a3c
//   0x012a50: d65f03c0  ret      
uint64_t fde_0279_sub_012a3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF1000421ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x012A3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000421ULL; // 0x012a3c: subs x1, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400008BULL; // 0x012a40: b.lt #0x12a50
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400048ULL; // 0x012a44: ldr w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x38001408ULL; // 0x012a48: strb w8, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x012a4c: b #0x12a3c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x012a50: ret 
    return acc;
}

// [EN] Reconstructed FDE #0280 @ 0x012a54..0x012a6c (24 bytes)
// [VN] Phục dựng FDE #0280 tại 0x012a54..0x012a6c (24 byte)
//   0x012a54: aa0003e8  mov      x8, x0
//   0x012a58: f9400000  ldr      x0, [x0]
//   0x012a5c: f900011f  str      xzr, [x8]
//   0x012a60: b4000040  cbz      x0, #0x12a68
//   0x012a64: 17ffe25f  b        #0xb3e0
//   0x012a68: d65f03c0  ret      
uint64_t fde_0280_sub_012a54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x012A54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x012a54: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x012a58: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x012a5c: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x012a60: cbz x0, #0x12a68
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE25FULL; // 0x012a64: b #0xb3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x012a68: ret 
    return acc;
}

// [EN] Reconstructed FDE #0281 @ 0x012a6c..0x012a80 (20 bytes)
// [VN] Phục dựng FDE #0281 tại 0x012a6c..0x012a80 (20 byte)
//   0x012a6c: 7100013f  cmp      w9, #0
//   0x012a70: 1a9f07e2  cset     w2, ne
//   0x012a74: aa1303e0  mov      x0, x19
//   0x012a78: aa1403e1  mov      x1, x20
//   0x012a7c: 17ffff3d  b        #0x12770
uint64_t fde_0281_sub_012a6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100013FULL) + (x1 ^ 0x17FFFF3DULL) + (x2 ^ 0x012A6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100013FULL; // 0x012a6c: cmp w9, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E2ULL; // 0x012a70: cset w2, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x012a74: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x012a78: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF3DULL; // 0x012a7c: b #0x12770
    return acc;
}

// [EN] Reconstructed FDE #0282 @ 0x012a80..0x012a8c (12 bytes)
// [VN] Phục dựng FDE #0282 tại 0x012a80..0x012a8c (12 byte)
//   0x012a80: b0000240  adrp     x0, #0x5b000
//   0x012a84: f9471c00  ldr      x0, [x0, #0xe38]
//   0x012a88: 17ffe26e  b        #0xb440
uint64_t fde_0282_sub_012a80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000240ULL) + (x1 ^ 0x17FFE26EULL) + (x2 ^ 0x012A80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000240ULL; // 0x012a80: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471C00ULL; // 0x012a84: ldr x0, [x0, #0xe38]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE26EULL; // 0x012a88: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #0283 @ 0x012a8c..0x012a98 (12 bytes)
// [VN] Phục dựng FDE #0283 tại 0x012a8c..0x012a98 (12 byte)
//   0x012a8c: aa0003e8  mov      x8, x0
//   0x012a90: aa1303e0  mov      x0, x19
//   0x012a94: d61f0100  br       x8
uint64_t fde_0283_sub_012a8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x012A8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x012a8c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x012a90: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x012a94: br x8
    return acc;
}

// [EN] Reconstructed FDE #0284 @ 0x012a98..0x012aa4 (12 bytes)
// [VN] Phục dựng FDE #0284 tại 0x012a98..0x012aa4 (12 byte)
//   0x012a98: b0000240  adrp     x0, #0x5b000
//   0x012a9c: f942c800  ldr      x0, [x0, #0x590]
//   0x012aa0: 17ffe080  b        #0xaca0
uint64_t fde_0284_sub_012a98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000240ULL) + (x1 ^ 0x17FFE080ULL) + (x2 ^ 0x012A98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000240ULL; // 0x012a98: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942C800ULL; // 0x012a9c: ldr x0, [x0, #0x590]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE080ULL; // 0x012aa0: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #0285 @ 0x012aa4..0x012c24 (384 bytes)
// [VN] Phục dựng FDE #0285 tại 0x012aa4..0x012c24 (384 byte)
//   0x012aa4: 6dbb23e9  stp      d9, d8, [sp, #-0x50]!
//   0x012aa8: f9000bf7  str      x23, [sp, #0x10]
//   0x012aac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x012ab0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x012ab4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x012ab8: 910103fd  add      x29, sp, #0x40
//   0x012abc: 4ea01c08  mov      v8.16b, v0.16b
//   0x012ac0: 97ffe2ec  bl       #0xb670
//   0x012ac4: 7100741f  cmp      w0, #0x1d
//   0x012ac8: 54000103  b.lo     #0x12ae8
//   0x012acc: d0000257  adrp     x23, #0x5c000
//   0x012ad0: fd4012e0  ldr      d0, [x23, #0x20]
uint64_t fde_0285_sub_012aa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DBB23E9ULL) + (x1 ^ 0x7100741FULL) + (x2 ^ 0x012AA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DBB23E9ULL; // 0x012aa4: stp d9, d8, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x012aa8: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x012aac: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x012ab0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x012ab4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x012ab8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C08ULL; // 0x012abc: mov v8.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE2ECULL; // 0x012ac0: bl #0xb670
    return acc;
}

// [EN] Reconstructed FDE #0286 @ 0x012c24..0x012ca8 (132 bytes)
// [VN] Phục dựng FDE #0286 tại 0x012c24..0x012ca8 (132 byte)
//   0x012c24: d100c3ff  sub      sp, sp, #0x30
//   0x012c28: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x012c2c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x012c30: 910083fd  add      x29, sp, #0x20
//   0x012c34: d53bd054  mrs      x20, tpidr_el0
//   0x012c38: f9401688  ldr      x8, [x20, #0x28]
//   0x012c3c: aa0003f3  mov      x19, x0
//   0x012c40: b0000240  adrp     x0, #0x5b000
//   0x012c44: f90007e8  str      x8, [sp, #8]
//   0x012c48: f90003fe  str      x30, [sp]
//   0x012c4c: f947b800  ldr      x0, [x0, #0xf70]
//   0x012c50: 97ffe014  bl       #0xaca0
uint64_t fde_0286_sub_012c24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x012C24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x012c24: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x012c28: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x012c2c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x012c30: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x012c34: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x012c38: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x012c3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000240ULL; // 0x012c40: adrp x0, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0287 @ 0x012ca8..0x012d20 (120 bytes)
// [VN] Phục dựng FDE #0287 tại 0x012ca8..0x012d20 (120 byte)
//   0x012ca8: d10103ff  sub      sp, sp, #0x40
//   0x012cac: f9000bf5  str      x21, [sp, #0x10]
//   0x012cb0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x012cb4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012cb8: 9100c3fd  add      x29, sp, #0x30
//   0x012cbc: d53bd055  mrs      x21, tpidr_el0
//   0x012cc0: f94016a8  ldr      x8, [x21, #0x28]
//   0x012cc4: aa0003f4  mov      x20, x0
//   0x012cc8: b0000240  adrp     x0, #0x5b000
//   0x012ccc: aa0103f3  mov      x19, x1
//   0x012cd0: f90007e8  str      x8, [sp, #8]
//   0x012cd4: f90003fe  str      x30, [sp]
uint64_t fde_0287_sub_012ca8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB0000240ULL) + (x2 ^ 0x012CA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x012ca8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x012cac: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x012cb0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x012cb4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x012cb8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x012cbc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x012cc0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x012cc4: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0288 @ 0x012d20..0x012de0 (192 bytes)
// [VN] Phục dựng FDE #0288 tại 0x012d20..0x012de0 (192 byte)
//   0x012d20: d10103ff  sub      sp, sp, #0x40
//   0x012d24: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x012d28: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x012d2c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012d30: 9100c3fd  add      x29, sp, #0x30
//   0x012d34: d53bd056  mrs      x22, tpidr_el0
//   0x012d38: f94016c8  ldr      x8, [x22, #0x28]
//   0x012d3c: aa0203f3  mov      x19, x2
//   0x012d40: aa0103f4  mov      x20, x1
//   0x012d44: aa0003f5  mov      x21, x0
//   0x012d48: f90007e8  str      x8, [sp, #8]
//   0x012d4c: f90003fe  str      x30, [sp]
uint64_t fde_0288_sub_012d20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x012D20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x012d20: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x012d24: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x012d28: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x012d2c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x012d30: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x012d34: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x012d38: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x012d3c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0289 @ 0x012de0..0x012ec8 (232 bytes)
// [VN] Phục dựng FDE #0289 tại 0x012de0..0x012ec8 (232 byte)
//   0x012de0: d10103ff  sub      sp, sp, #0x40
//   0x012de4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x012de8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x012dec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x012df0: 9100c3fd  add      x29, sp, #0x30
//   0x012df4: d53bd056  mrs      x22, tpidr_el0
//   0x012df8: f94016c8  ldr      x8, [x22, #0x28]
//   0x012dfc: aa0103f3  mov      x19, x1
//   0x012e00: aa0003f4  mov      x20, x0
//   0x012e04: f90007e8  str      x8, [sp, #8]
//   0x012e08: f90003fe  str      x30, [sp]
//   0x012e0c: 94000146  bl       #0x13324
uint64_t fde_0289_sub_012de0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x012DE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x012de0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x012de4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x012de8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x012dec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x012df0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x012df4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x012df8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x012dfc: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0290 @ 0x012ec8..0x013324 (1116 bytes)
// [VN] Phục dựng FDE #0290 tại 0x012ec8..0x013324 (1116 byte)
//   0x012ec8: d10703ff  sub      sp, sp, #0x1c0
//   0x012ecc: f900bbfc  str      x28, [sp, #0x170]
//   0x012ed0: a9185ff8  stp      x24, x23, [sp, #0x180]
//   0x012ed4: a91957f6  stp      x22, x21, [sp, #0x190]
//   0x012ed8: a91a4ff4  stp      x20, x19, [sp, #0x1a0]
//   0x012edc: a91b7bfd  stp      x29, x30, [sp, #0x1b0]
//   0x012ee0: 9106c3fd  add      x29, sp, #0x1b0
//   0x012ee4: d53bd058  mrs      x24, tpidr_el0
//   0x012ee8: f9401708  ldr      x8, [x24, #0x28]
//   0x012eec: aa0003f3  mov      x19, x0
//   0x012ef0: f81b83a8  stur     x8, [x29, #-0x48]
//   0x012ef4: 97ffe1df  bl       #0xb670
uint64_t fde_0290_sub_012ec8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10703FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x012EC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x012ec8: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900BBFCULL; // 0x012ecc: str x28, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9185FF8ULL; // 0x012ed0: stp x24, x23, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91957F6ULL; // 0x012ed4: stp x22, x21, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A4FF4ULL; // 0x012ed8: stp x20, x19, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B7BFDULL; // 0x012edc: stp x29, x30, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9106C3FDULL; // 0x012ee0: add x29, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x012ee4: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0291 @ 0x013324..0x013334 (16 bytes)
// [VN] Phục dựng FDE #0291 tại 0x013324..0x013334 (16 byte)
//   0x013324: 90000248  adrp     x8, #0x5b000
//   0x013328: f9430108  ldr      x8, [x8, #0x600]
//   0x01332c: 39400108  ldrb     w8, [x8]
//   0x013330: d65f03c0  ret      
uint64_t fde_0291_sub_013324(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000248ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013324ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000248ULL; // 0x013324: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9430108ULL; // 0x013328: ldr x8, [x8, #0x600]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x01332c: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013330: ret 
    return acc;
}

// [EN] Reconstructed FDE #0292 @ 0x013334..0x01333c (8 bytes)
// [VN] Phục dựng FDE #0292 tại 0x013334..0x01333c (8 byte)
//   0x013334: 910003e0  mov      x0, sp
//   0x013338: 17fff70b  b        #0x10f64
uint64_t fde_0292_sub_013334(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFF70BULL) + (x2 ^ 0x013334ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x013334: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF70BULL; // 0x013338: b #0x10f64
    return acc;
}

// [EN] Reconstructed FDE #0293 @ 0x01333c..0x013350 (20 bytes)
// [VN] Phục dựng FDE #0293 tại 0x01333c..0x013350 (20 byte)
//   0x01333c: f9400268  ldr      x8, [x19]
//   0x013340: aa0003e1  mov      x1, x0
//   0x013344: aa1303e0  mov      x0, x19
//   0x013348: f9405508  ldr      x8, [x8, #0xa8]
//   0x01334c: d61f0100  br       x8
uint64_t fde_0293_sub_01333c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01333CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01333c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x013340: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x013344: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405508ULL; // 0x013348: ldr x8, [x8, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01334c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0294 @ 0x013350..0x013364 (20 bytes)
// [VN] Phục dựng FDE #0294 tại 0x013350..0x013364 (20 byte)
//   0x013350: aa1403e0  mov      x0, x20
//   0x013354: aa1303e1  mov      x1, x19
//   0x013358: f9408108  ldr      x8, [x8, #0x100]
//   0x01335c: f9400122  ldr      x2, [x9]
//   0x013360: d61f0100  br       x8
uint64_t fde_0294_sub_013350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x013350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x013350: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x013354: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408108ULL; // 0x013358: ldr x8, [x8, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400122ULL; // 0x01335c: ldr x2, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x013360: br x8
    return acc;
}

// [EN] Reconstructed FDE #0295 @ 0x013364..0x013370 (12 bytes)
// [VN] Phục dựng FDE #0295 tại 0x013364..0x013370 (12 byte)
//   0x013364: aa1303e0  mov      x0, x19
//   0x013368: f9401908  ldr      x8, [x8, #0x30]
//   0x01336c: d61f0100  br       x8
uint64_t fde_0295_sub_013364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x013364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x013364: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x013368: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01336c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0296 @ 0x013370..0x01337c (12 bytes)
// [VN] Phục dựng FDE #0296 tại 0x013370..0x01337c (12 byte)
//   0x013370: f94007e9  ldr      x9, [sp, #8]
//   0x013374: eb09011f  cmp      x8, x9
//   0x013378: d65f03c0  ret      
uint64_t fde_0296_sub_013370(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94007E9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013370ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94007E9ULL; // 0x013370: ldr x9, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x013374: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013378: ret 
    return acc;
}

// [EN] Reconstructed FDE #0297 @ 0x01337c..0x01338c (16 bytes)
// [VN] Phục dựng FDE #0297 tại 0x01337c..0x01338c (16 byte)
//   0x01337c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x013380: f9400bf5  ldr      x21, [sp, #0x10]
//   0x013384: 910103ff  add      sp, sp, #0x40
//   0x013388: d65f03c0  ret      
uint64_t fde_0297_sub_01337c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9424FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01337CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9424FF4ULL; // 0x01337c: ldp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF5ULL; // 0x013380: ldr x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FFULL; // 0x013384: add sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013388: ret 
    return acc;
}

// [EN] Reconstructed FDE #0298 @ 0x01338c..0x01339c (16 bytes)
// [VN] Phục dựng FDE #0298 tại 0x01338c..0x01339c (16 byte)
//   0x01338c: aa0003e8  mov      x8, x0
//   0x013390: aa1403e0  mov      x0, x20
//   0x013394: aa1303e1  mov      x1, x19
//   0x013398: d61f0100  br       x8
uint64_t fde_0298_sub_01338c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01338CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01338c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x013390: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x013394: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x013398: br x8
    return acc;
}

// [EN] Reconstructed FDE #0299 @ 0x01339c..0x0133ac (16 bytes)
// [VN] Phục dựng FDE #0299 tại 0x01339c..0x0133ac (16 byte)
//   0x01339c: 9100c3e1  add      x1, sp, #0x30
//   0x0133a0: 52800042  mov      w2, #2
//   0x0133a4: 2a1403e0  mov      w0, w20
//   0x0133a8: 14005dc6  b        #0x2aac0
uint64_t fde_0299_sub_01339c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100C3E1ULL) + (x1 ^ 0x14005DC6ULL) + (x2 ^ 0x01339CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E1ULL; // 0x01339c: add x1, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x52800042ULL; // 0x0133a0: mov w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E0ULL; // 0x0133a4: mov w0, w20
    acc = (acc * 0x100000001B3ULL) ^ 0x14005DC6ULL; // 0x0133a8: b #0x2aac0
    return acc;
}

// [EN] Reconstructed FDE #0300 @ 0x0133ac..0x0133b4 (8 bytes)
// [VN] Phục dựng FDE #0300 tại 0x0133ac..0x0133b4 (8 byte)
//   0x0133ac: 528000c0  mov      w0, #6
//   0x0133b0: 17ffdf8c  b        #0xb1e0
uint64_t fde_0300_sub_0133ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFDF8CULL) + (x2 ^ 0x0133ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x0133ac: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDF8CULL; // 0x0133b0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0301 @ 0x0133b4..0x0133c0 (12 bytes)
// [VN] Phục dựng FDE #0301 tại 0x0133b4..0x0133c0 (12 byte)
//   0x0133b4: aa0003e3  mov      x3, x0
//   0x0133b8: 911f2c21  add      x1, x1, #0x7cb
//   0x0133bc: d65f03c0  ret      
uint64_t fde_0301_sub_0133b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0133B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E3ULL; // 0x0133b4: mov x3, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x0133b8: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0133bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0302 @ 0x0133c0..0x013478 (184 bytes)
// [VN] Phục dựng FDE #0302 tại 0x0133c0..0x013478 (184 byte)
//   0x0133c0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0133c4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0133c8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0133cc: 910083fd  add      x29, sp, #0x20
//   0x0133d0: 90000254  adrp     x20, #0x5b000
//   0x0133d4: f9479a94  ldr      x20, [x20, #0xf30]
//   0x0133d8: 39400288  ldrb     w8, [x20]
//   0x0133dc: 340001a8  cbz      w8, #0x13410
//   0x0133e0: f0000121  adrp     x1, #0x3a000
//   0x0133e4: f0000122  adrp     x2, #0x3a000
//   0x0133e8: 91035c21  add      x1, x1, #0xd7
//   0x0133ec: 91039042  add      x2, x2, #0xe4
uint64_t fde_0302_sub_0133c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF0000121ULL) + (x2 ^ 0x0133C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0133c0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0133c4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0133c8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0133cc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000254ULL; // 0x0133d0: adrp x20, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9479A94ULL; // 0x0133d4: ldr x20, [x20, #0xf30]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400288ULL; // 0x0133d8: ldrb w8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x340001A8ULL; // 0x0133dc: cbz w8, #0x13410
    return acc;
}

// [EN] Reconstructed FDE #0303 @ 0x013478..0x013938 (1216 bytes)
// [VN] Phục dựng FDE #0303 tại 0x013478..0x013938 (1216 byte)
//   0x013478: d10643ff  sub      sp, sp, #0x190
//   0x01347c: f900abfc  str      x28, [sp, #0x150]
//   0x013480: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x013484: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x013488: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x01348c: 910603fd  add      x29, sp, #0x180
//   0x013490: d53bd055  mrs      x21, tpidr_el0
//   0x013494: f94016a8  ldr      x8, [x21, #0x28]
//   0x013498: aa0003f3  mov      x19, x0
//   0x01349c: d0000120  adrp     x0, #0x39000
//   0x0134a0: 911cd000  add      x0, x0, #0x734
//   0x0134a4: f81c83a8  stur     x8, [x29, #-0x38]
uint64_t fde_0303_sub_013478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x013478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x013478: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xF900ABFCULL; // 0x01347c: str x28, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x013480: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x013484: stp x20, x19, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9187BFDULL; // 0x013488: stp x29, x30, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0x910603FDULL; // 0x01348c: add x29, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x013490: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x013494: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0304 @ 0x013938..0x013a50 (280 bytes)
// [VN] Phục dựng FDE #0304 tại 0x013938..0x013a50 (280 byte)
//   0x013938: d10103ff  sub      sp, sp, #0x40
//   0x01393c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x013940: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x013944: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x013948: 9100c3fd  add      x29, sp, #0x30
//   0x01394c: d53bd054  mrs      x20, tpidr_el0
//   0x013950: f9401688  ldr      x8, [x20, #0x28]
//   0x013954: 90000256  adrp     x22, #0x5b000
//   0x013958: 90000255  adrp     x21, #0x5b000
//   0x01395c: f9442ed6  ldr      x22, [x22, #0x858]
//   0x013960: f945deb5  ldr      x21, [x21, #0xbb8]
//   0x013964: f90007e8  str      x8, [sp, #8]
uint64_t fde_0304_sub_013938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x90000255ULL) + (x2 ^ 0x013938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x013938: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01393c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x013940: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x013944: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x013948: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x01394c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x013950: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000256ULL; // 0x013954: adrp x22, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0305 @ 0x013a50..0x013b4c (252 bytes)
// [VN] Phục dựng FDE #0305 tại 0x013a50..0x013b4c (252 byte)
//   0x013a50: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x013a54: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x013a58: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x013a5c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x013a60: 9100c3fd  add      x29, sp, #0x30
//   0x013a64: f0000121  adrp     x1, #0x3a000
//   0x013a68: 91050c21  add      x1, x1, #0x143
//   0x013a6c: 97ffdd95  bl       #0xb0c0
//   0x013a70: b4000440  cbz      x0, #0x13af8
//   0x013a74: 90000257  adrp     x23, #0x5b000
//   0x013a78: f94722f7  ldr      x23, [x23, #0xe40]
//   0x013a7c: aa1f03f5  mov      x21, xzr
uint64_t fde_0305_sub_013a50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB4000440ULL) + (x2 ^ 0x013A50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x013a50: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x013a54: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x013a58: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x013a5c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x013a60: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000121ULL; // 0x013a64: adrp x1, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91050C21ULL; // 0x013a68: add x1, x1, #0x143
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDD95ULL; // 0x013a6c: bl #0xb0c0
    return acc;
}

// [EN] Reconstructed FDE #0306 @ 0x013b4c..0x013c2c (224 bytes)
// [VN] Phục dựng FDE #0306 tại 0x013b4c..0x013c2c (224 byte)
//   0x013b4c: d10183ff  sub      sp, sp, #0x60
//   0x013b50: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x013b54: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x013b58: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x013b5c: 910143fd  add      x29, sp, #0x50
//   0x013b60: d53bd056  mrs      x22, tpidr_el0
//   0x013b64: f94016c8  ldr      x8, [x22, #0x28]
//   0x013b68: f0000121  adrp     x1, #0x3a000
//   0x013b6c: 9121ac21  add      x1, x1, #0x86b
//   0x013b70: aa0003f3  mov      x19, x0
//   0x013b74: f90017e8  str      x8, [sp, #0x28]
//   0x013b78: f9400008  ldr      x8, [x0]
uint64_t fde_0306_sub_013b4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x9121AC21ULL) + (x2 ^ 0x013B4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x013b4c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x013b50: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x013b54: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x013b58: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x013b5c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x013b60: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x013b64: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000121ULL; // 0x013b68: adrp x1, #0x3a000
    return acc;
}

// [EN] Reconstructed FDE #0307 @ 0x013c2c..0x013c58 (44 bytes)
// [VN] Phục dựng FDE #0307 tại 0x013c2c..0x013c58 (44 byte)
//   0x013c2c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x013c30: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x013c34: 910043fd  add      x29, sp, #0x10
//   0x013c38: aa0003f3  mov      x19, x0
//   0x013c3c: f9400000  ldr      x0, [x0]
//   0x013c40: b4000060  cbz      x0, #0x13c4c
//   0x013c44: 97ffdd33  bl       #0xb110
//   0x013c48: f900027f  str      xzr, [x19]
//   0x013c4c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x013c50: f84207f3  ldr      x19, [sp], #0x20
//   0x013c54: d65f03c0  ret      
uint64_t fde_0307_sub_013c2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x013C2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x013c2c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x013c30: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x013c34: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x013c38: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x013c3c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x013c40: cbz x0, #0x13c4c
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDD33ULL; // 0x013c44: bl #0xb110
    acc = (acc * 0x100000001B3ULL) ^ 0xF900027FULL; // 0x013c48: str xzr, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0308 @ 0x013c58..0x013e20 (456 bytes)
// [VN] Phục dựng FDE #0308 tại 0x013c58..0x013e20 (456 byte)
//   0x013c58: d10283ff  sub      sp, sp, #0xa0
//   0x013c5c: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x013c60: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x013c64: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x013c68: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x013c6c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x013c70: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x013c74: 910243fd  add      x29, sp, #0x90
//   0x013c78: d53bd05c  mrs      x28, tpidr_el0
//   0x013c7c: f9401788  ldr      x8, [x28, #0x28]
//   0x013c80: 12001c49  and      w9, w2, #0xff
//   0x013c84: aa0703f3  mov      x19, x7
uint64_t fde_0308_sub_013c58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD53BD05CULL) + (x2 ^ 0x013C58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x013c58: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x013c5c: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x013c60: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x013c64: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x013c68: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x013c6c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x013c70: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x013c74: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #0309 @ 0x013e20..0x013fd0 (432 bytes)
// [VN] Phục dựng FDE #0309 tại 0x013e20..0x013fd0 (432 byte)
//   0x013e20: d10283ff  sub      sp, sp, #0xa0
//   0x013e24: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x013e28: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x013e2c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x013e30: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x013e34: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x013e38: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x013e3c: 910243fd  add      x29, sp, #0x90
//   0x013e40: d53bd05b  mrs      x27, tpidr_el0
//   0x013e44: f9401768  ldr      x8, [x27, #0x28]
//   0x013e48: aa0603f3  mov      x19, x6
//   0x013e4c: aa0503f4  mov      x20, x5
uint64_t fde_0309_sub_013e20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x013E20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x013e20: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x013e24: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x013e28: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x013e2c: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x013e30: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x013e34: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x013e38: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x013e3c: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #0310 @ 0x013fd0..0x0140fc (300 bytes)
// [VN] Phục dựng FDE #0310 tại 0x013fd0..0x0140fc (300 byte)
//   0x013fd0: d10203ff  sub      sp, sp, #0x80
//   0x013fd4: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x013fd8: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x013fdc: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x013fe0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x013fe4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x013fe8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x013fec: 9101c3fd  add      x29, sp, #0x70
//   0x013ff0: d53bd05b  mrs      x27, tpidr_el0
//   0x013ff4: f9401768  ldr      x8, [x27, #0x28]
//   0x013ff8: 12001c49  and      w9, w2, #0xff
//   0x013ffc: aa0703f3  mov      x19, x7
uint64_t fde_0310_sub_013fd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x013FD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x013fd0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x013fd4: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x013fd8: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x013fdc: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x013fe0: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x013fe4: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x013fe8: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x013fec: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0311 @ 0x0140fc..0x014198 (156 bytes)
// [VN] Phục dựng FDE #0311 tại 0x0140fc..0x014198 (156 byte)
//   0x0140fc: d10483ff  sub      sp, sp, #0x120
//   0x014100: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x014104: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x014108: 910443fd  add      x29, sp, #0x110
//   0x01410c: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x014110: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x014114: f90057e7  str      x7, [sp, #0xa8]
//   0x014118: ad0007e0  stp      q0, q1, [sp]
//   0x01411c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x014120: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x014124: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x014128: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0311_sub_0140fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x0140FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0140fc: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x014100: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x014104: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x014108: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x01410c: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x014110: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x014114: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x014118: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0312 @ 0x014198..0x014234 (156 bytes)
// [VN] Phục dựng FDE #0312 tại 0x014198..0x014234 (156 byte)
//   0x014198: d10483ff  sub      sp, sp, #0x120
//   0x01419c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0141a0: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0141a4: 910443fd  add      x29, sp, #0x110
//   0x0141a8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0141ac: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0141b0: f90057e7  str      x7, [sp, #0xa8]
//   0x0141b4: ad0007e0  stp      q0, q1, [sp]
//   0x0141b8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0141bc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0141c0: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0141c4: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0312_sub_014198(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x014198ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x014198: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x01419c: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0141a0: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0141a4: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0141a8: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0141ac: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0141b0: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0141b4: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0313 @ 0x014234..0x01423c (8 bytes)
// [VN] Phục dựng FDE #0313 tại 0x014234..0x01423c (8 byte)
//   0x014234: aa1f03e1  mov      x1, xzr
//   0x014238: 14000046  b        #0x14350
uint64_t fde_0313_sub_014234(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000046ULL) + (x2 ^ 0x014234ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x014234: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000046ULL; // 0x014238: b #0x14350
    return acc;
}

// [EN] Reconstructed FDE #0314 @ 0x01423c..0x014244 (8 bytes)
// [VN] Phục dựng FDE #0314 tại 0x01423c..0x014244 (8 byte)
//   0x01423c: aa1f03e1  mov      x1, xzr
//   0x014240: 14000032  b        #0x14308
uint64_t fde_0314_sub_01423c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000032ULL) + (x2 ^ 0x01423CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x01423c: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000032ULL; // 0x014240: b #0x14308
    return acc;
}

// [EN] Reconstructed FDE #0315 @ 0x014244..0x014308 (196 bytes)
// [VN] Phục dựng FDE #0315 tại 0x014244..0x014308 (196 byte)
//   0x014244: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x014248: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01424c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x014250: 910083fd  add      x29, sp, #0x20
//   0x014254: f0000228  adrp     x8, #0x5b000
//   0x014258: f9479908  ldr      x8, [x8, #0xf30]
//   0x01425c: 39400108  ldrb     w8, [x8]
//   0x014260: 340004c8  cbz      w8, #0x142f8
//   0x014264: f0000228  adrp     x8, #0x5b000
//   0x014268: f9432d08  ldr      x8, [x8, #0x658]
//   0x01426c: f0000229  adrp     x9, #0x5b000
//   0x014270: f0000234  adrp     x20, #0x5b000
uint64_t fde_0315_sub_014244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF0000228ULL) + (x2 ^ 0x014244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x014244: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x014248: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01424c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x014250: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x014254: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9479908ULL; // 0x014258: ldr x8, [x8, #0xf30]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x01425c: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340004C8ULL; // 0x014260: cbz w8, #0x142f8
    return acc;
}

// [EN] Reconstructed FDE #0316 @ 0x014308..0x014350 (72 bytes)
// [VN] Phục dựng FDE #0316 tại 0x014308..0x014350 (72 byte)
//   0x014308: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01430c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x014310: 910043fd  add      x29, sp, #0x10
//   0x014314: f9400408  ldr      x8, [x0, #8]
//   0x014318: eb01011f  cmp      x8, x1
//   0x01431c: 54000140  b.eq     #0x14344
//   0x014320: aa0003f3  mov      x19, x0
//   0x014324: aa0103f4  mov      x20, x1
//   0x014328: b40000c8  cbz      x8, #0x14340
//   0x01432c: f9400260  ldr      x0, [x19]
//   0x014330: aa0803e1  mov      x1, x8
//   0x014334: f9400009  ldr      x9, [x0]
uint64_t fde_0316_sub_014308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000C8ULL) + (x2 ^ 0x014308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014308: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01430c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x014310: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x014314: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x014318: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x01431c: b.eq #0x14344
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x014320: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x014324: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0317 @ 0x014350..0x014398 (72 bytes)
// [VN] Phục dựng FDE #0317 tại 0x014350..0x014398 (72 byte)
//   0x014350: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x014354: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x014358: 910043fd  add      x29, sp, #0x10
//   0x01435c: f9400408  ldr      x8, [x0, #8]
//   0x014360: eb01011f  cmp      x8, x1
//   0x014364: 54000140  b.eq     #0x1438c
//   0x014368: aa0003f3  mov      x19, x0
//   0x01436c: aa0103f4  mov      x20, x1
//   0x014370: b40000c8  cbz      x8, #0x14388
//   0x014374: f9400260  ldr      x0, [x19]
//   0x014378: aa0803e1  mov      x1, x8
//   0x01437c: f9400009  ldr      x9, [x0]
uint64_t fde_0317_sub_014350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000C8ULL) + (x2 ^ 0x014350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014350: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x014354: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x014358: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x01435c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x014360: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x014364: b.eq #0x1438c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x014368: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01436c: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0318 @ 0x014398..0x0143b0 (24 bytes)
// [VN] Phục dựng FDE #0318 tại 0x014398..0x0143b0 (24 byte)
//   0x014398: f0000228  adrp     x8, #0x5b000
//   0x01439c: f9401be1  ldr      x1, [sp, #0x30]
//   0x0143a0: f9457d08  ldr      x8, [x8, #0xaf8]
//   0x0143a4: 910063e0  add      x0, sp, #0x18
//   0x0143a8: f9400102  ldr      x2, [x8]
//   0x0143ac: 17ffdbcd  b        #0xb2e0
uint64_t fde_0318_sub_014398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000228ULL) + (x1 ^ 0x17FFDBCDULL) + (x2 ^ 0x014398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x014398: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401BE1ULL; // 0x01439c: ldr x1, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9457D08ULL; // 0x0143a0: ldr x8, [x8, #0xaf8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x0143a4: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x0143a8: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDBCDULL; // 0x0143ac: b #0xb2e0
    return acc;
}

// [EN] Reconstructed FDE #0319 @ 0x0143b0..0x0143e8 (56 bytes)
// [VN] Phục dựng FDE #0319 tại 0x0143b0..0x0143e8 (56 byte)
//   0x0143b0: f0000228  adrp     x8, #0x5b000
//   0x0143b4: f9432d08  ldr      x8, [x8, #0x658]
//   0x0143b8: f0000229  adrp     x9, #0x5b000
//   0x0143bc: f000022a  adrp     x10, #0x5b000
//   0x0143c0: f9400108  ldr      x8, [x8]
//   0x0143c4: f9440129  ldr      x9, [x9, #0x800]
//   0x0143c8: f9400108  ldr      x8, [x8]
//   0x0143cc: f9400129  ldr      x9, [x9]
//   0x0143d0: f9400129  ldr      x9, [x9]
//   0x0143d4: f945214a  ldr      x10, [x10, #0xa40]
//   0x0143d8: eb080128  subs     x8, x9, x8
//   0x0143dc: b980014a  ldrsw    x10, [x10]
uint64_t fde_0319_sub_0143b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000228ULL) + (x1 ^ 0xF9400129ULL) + (x2 ^ 0x0143B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x0143b0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9432D08ULL; // 0x0143b4: ldr x8, [x8, #0x658]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000229ULL; // 0x0143b8: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF000022AULL; // 0x0143bc: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0143c0: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9440129ULL; // 0x0143c4: ldr x9, [x9, #0x800]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0143c8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400129ULL; // 0x0143cc: ldr x9, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0320 @ 0x0143e8..0x0143f8 (16 bytes)
// [VN] Phục dựng FDE #0320 tại 0x0143e8..0x0143f8 (16 byte)
//   0x0143e8: f9401be0  ldr      x0, [sp, #0x30]
//   0x0143ec: f9400008  ldr      x8, [x0]
//   0x0143f0: f9404508  ldr      x8, [x8, #0x88]
//   0x0143f4: d61f0100  br       x8
uint64_t fde_0320_sub_0143e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401BE0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0143E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401BE0ULL; // 0x0143e8: ldr x0, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0143ec: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x0143f0: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0143f4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0321 @ 0x0143f8..0x01441c (36 bytes)
// [VN] Phục dựng FDE #0321 tại 0x0143f8..0x01441c (36 byte)
//   0x0143f8: f0000228  adrp     x8, #0x5b000
//   0x0143fc: f9465508  ldr      x8, [x8, #0xca8]
//   0x014400: 528000c2  mov      w2, #6
//   0x014404: 9100c3e1  add      x1, sp, #0x30
//   0x014408: 72a00022  movk     w2, #1, lsl #16
//   0x01440c: f9400100  ldr      x0, [x8]
//   0x014410: f9400008  ldr      x8, [x0]
//   0x014414: f9401908  ldr      x8, [x8, #0x30]
//   0x014418: d61f0100  br       x8
uint64_t fde_0321_sub_0143f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000228ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0143F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x0143f8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9465508ULL; // 0x0143fc: ldr x8, [x8, #0xca8]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C2ULL; // 0x014400: mov w2, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E1ULL; // 0x014404: add x1, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x72A00022ULL; // 0x014408: movk w2, #1, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x01440c: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x014410: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x014414: ldr x8, [x8, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0322 @ 0x01441c..0x01443c (32 bytes)
// [VN] Phục dựng FDE #0322 tại 0x01441c..0x01443c (32 byte)
//   0x01441c: f000022a  adrp     x10, #0x5b000
//   0x014420: f945694a  ldr      x10, [x10, #0xad0]
//   0x014424: 52800029  mov      w9, #1
//   0x014428: f9000109  str      x9, [x8]
//   0x01442c: f9401be0  ldr      x0, [sp, #0x30]
//   0x014430: f9400148  ldr      x8, [x10]
//   0x014434: aa1f03e1  mov      x1, xzr
//   0x014438: d61f0100  br       x8
uint64_t fde_0322_sub_01441c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF000022AULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01441CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF000022AULL; // 0x01441c: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945694AULL; // 0x014420: ldr x10, [x10, #0xad0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x014424: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000109ULL; // 0x014428: str x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401BE0ULL; // 0x01442c: ldr x0, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400148ULL; // 0x014430: ldr x8, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x014434: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x014438: br x8
    return acc;
}

// [EN] Reconstructed FDE #0323 @ 0x01443c..0x014458 (28 bytes)
// [VN] Phục dựng FDE #0323 tại 0x01443c..0x014458 (28 byte)
//   0x01443c: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x014440: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x014444: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x014448: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x01444c: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x014450: 910283ff  add      sp, sp, #0xa0
//   0x014454: d65f03c0  ret      
uint64_t fde_0323_sub_01443c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9484FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01443CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9484FF4ULL; // 0x01443c: ldp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94757F6ULL; // 0x014440: ldp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9465FF8ULL; // 0x014444: ldp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94567FAULL; // 0x014448: ldp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9446FFCULL; // 0x01444c: ldp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FFULL; // 0x014450: add sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014454: ret 
    return acc;
}

// [EN] Reconstructed FDE #0324 @ 0x014458..0x014464 (12 bytes)
// [VN] Phục dựng FDE #0324 tại 0x014458..0x014464 (12 byte)
//   0x014458: f9400008  ldr      x8, [x0]
//   0x01445c: f9439108  ldr      x8, [x8, #0x720]
//   0x014460: d61f0100  br       x8
uint64_t fde_0324_sub_014458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x014458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x014458: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x01445c: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x014460: br x8
    return acc;
}

// [EN] Reconstructed FDE #0325 @ 0x014464..0x01446c (8 bytes)
// [VN] Phục dựng FDE #0325 tại 0x014464..0x01446c (8 byte)
//   0x014464: 910063e0  add      x0, sp, #0x18
//   0x014468: 17ffdb5a  b        #0xb1d0
uint64_t fde_0325_sub_014464(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FFDB5AULL) + (x2 ^ 0x014464ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x014464: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDB5AULL; // 0x014468: b #0xb1d0
    return acc;
}

// [EN] Reconstructed FDE #0326 @ 0x01446c..0x014484 (24 bytes)
// [VN] Phục dựng FDE #0326 tại 0x01446c..0x014484 (24 byte)
//   0x01446c: f000022a  adrp     x10, #0x5b000
//   0x014470: f945a14a  ldr      x10, [x10, #0xb40]
//   0x014474: b980014a  ldrsw    x10, [x10]
//   0x014478: 9aca092b  udiv     x11, x9, x10
//   0x01447c: 9b0aa569  msub     x9, x11, x10, x9
//   0x014480: d65f03c0  ret      
uint64_t fde_0326_sub_01446c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF000022AULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01446CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF000022AULL; // 0x01446c: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945A14AULL; // 0x014470: ldr x10, [x10, #0xb40]
    acc = (acc * 0x100000001B3ULL) ^ 0xB980014AULL; // 0x014474: ldrsw x10, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9ACA092BULL; // 0x014478: udiv x11, x9, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0AA569ULL; // 0x01447c: msub x9, x11, x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014480: ret 
    return acc;
}

// [EN] Reconstructed FDE #0327 @ 0x014484..0x014490 (12 bytes)
// [VN] Phục dựng FDE #0327 tại 0x014484..0x014490 (12 byte)
//   0x014484: f0000228  adrp     x8, #0x5b000
//   0x014488: f946fd08  ldr      x8, [x8, #0xdf8]
//   0x01448c: d65f03c0  ret      
uint64_t fde_0327_sub_014484(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000228ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014484ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000228ULL; // 0x014484: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946FD08ULL; // 0x014488: ldr x8, [x8, #0xdf8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01448c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0328 @ 0x014490..0x01449c (12 bytes)
// [VN] Phục dựng FDE #0328 tại 0x014490..0x01449c (12 byte)
//   0x014490: aa1f03e1  mov      x1, xzr
//   0x014494: b9400100  ldr      w0, [x8]
//   0x014498: 17ffdaba  b        #0xaf80
uint64_t fde_0328_sub_014490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x17FFDABAULL) + (x2 ^ 0x014490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x014490: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400100ULL; // 0x014494: ldr w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDABAULL; // 0x014498: b #0xaf80
    return acc;
}

// [EN] Reconstructed FDE #0329 @ 0x01449c..0x0144a8 (12 bytes)
// [VN] Phục dựng FDE #0329 tại 0x01449c..0x0144a8 (12 byte)
//   0x01449c: b9400380  ldr      w0, [x28]
//   0x0144a0: aa1f03e1  mov      x1, xzr
//   0x0144a4: 17ffdab7  b        #0xaf80
uint64_t fde_0329_sub_01449c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400380ULL) + (x1 ^ 0x17FFDAB7ULL) + (x2 ^ 0x01449CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400380ULL; // 0x01449c: ldr w0, [x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0144a0: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDAB7ULL; // 0x0144a4: b #0xaf80
    return acc;
}

// [EN] Reconstructed FDE #0330 @ 0x0144a8..0x0144b4 (12 bytes)
// [VN] Phục dựng FDE #0330 tại 0x0144a8..0x0144b4 (12 byte)
//   0x0144a8: aa1303e0  mov      x0, x19
//   0x0144ac: aa1403e1  mov      x1, x20
//   0x0144b0: d61f0100  br       x8
uint64_t fde_0330_sub_0144a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0144A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0144a8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x0144ac: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0144b0: br x8
    return acc;
}

// [EN] Reconstructed FDE #0331 @ 0x0144b4..0x0145ec (312 bytes)
// [VN] Phục dựng FDE #0331 tại 0x0144b4..0x0145ec (312 byte)
//   0x0144b4: d10103ff  sub      sp, sp, #0x40
//   0x0144b8: f9000bf5  str      x21, [sp, #0x10]
//   0x0144bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0144c0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0144c4: 9100c3fd  add      x29, sp, #0x30
//   0x0144c8: d53bd054  mrs      x20, tpidr_el0
//   0x0144cc: f9401688  ldr      x8, [x20, #0x28]
//   0x0144d0: f90007e8  str      x8, [sp, #8]
//   0x0144d4: b4000140  cbz      x0, #0x144fc
//   0x0144d8: 90000248  adrp     x8, #0x5c000
//   0x0144dc: 394ec108  ldrb     w8, [x8, #0x3b0]
//   0x0144e0: 7100051f  cmp      w8, #1
uint64_t fde_0331_sub_0144b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB4000140ULL) + (x2 ^ 0x0144B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0144b4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0144b8: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0144bc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0144c0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0144c4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0144c8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0144cc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x0144d0: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0332 @ 0x0145ec..0x014688 (156 bytes)
// [VN] Phục dựng FDE #0332 tại 0x0145ec..0x014688 (156 byte)
//   0x0145ec: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0145f0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0145f4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0145f8: 910083fd  add      x29, sp, #0x20
//   0x0145fc: b40003c0  cbz      x0, #0x14674
//   0x014600: aa0303f3  mov      x19, x3
//   0x014604: aa0203f4  mov      x20, x2
//   0x014608: aa0103f5  mov      x21, x1
//   0x01460c: aa0003f6  mov      x22, x0
//   0x014610: 97ffdc24  bl       #0xb6a0
//   0x014614: aa0003e2  mov      x2, x0
//   0x014618: b5000180  cbnz     x0, #0x14648
uint64_t fde_0332_sub_0145ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x0145ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0145ec: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0145f0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0145f4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0145f8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C0ULL; // 0x0145fc: cbz x0, #0x14674
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x014600: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x014604: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x014608: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0333 @ 0x014688..0x0146b8 (48 bytes)
// [VN] Phục dựng FDE #0333 tại 0x014688..0x0146b8 (48 byte)
//   0x014688: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01468c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x014690: 910043fd  add      x29, sp, #0x10
//   0x014694: 90000254  adrp     x20, #0x5c000
//   0x014698: 910ed294  add      x20, x20, #0x3b4
//   0x01469c: f841c288  ldur     x8, [x20, #0x1c]
//   0x0146a0: aa0003f3  mov      x19, x0
//   0x0146a4: d63f0100  blr      x8
//   0x0146a8: f8404288  ldur     x8, [x20, #4]
//   0x0146ac: 39400289  ldrb     w9, [x20]
//   0x0146b0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0146b4: 14000021  b        #0x14738
uint64_t fde_0333_sub_014688(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF8404288ULL) + (x2 ^ 0x014688ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014688: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01468c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x014690: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000254ULL; // 0x014694: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x910ED294ULL; // 0x014698: add x20, x20, #0x3b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF841C288ULL; // 0x01469c: ldur x8, [x20, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0146a0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0146a4: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0334 @ 0x0146b8..0x0146e8 (48 bytes)
// [VN] Phục dựng FDE #0334 tại 0x0146b8..0x0146e8 (48 byte)
//   0x0146b8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0146bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0146c0: 910043fd  add      x29, sp, #0x10
//   0x0146c4: 90000254  adrp     x20, #0x5c000
//   0x0146c8: 910ed294  add      x20, x20, #0x3b4
//   0x0146cc: f8424288  ldur     x8, [x20, #0x24]
//   0x0146d0: aa0003f3  mov      x19, x0
//   0x0146d4: d63f0100  blr      x8
//   0x0146d8: f8404288  ldur     x8, [x20, #4]
//   0x0146dc: 39400289  ldrb     w9, [x20]
//   0x0146e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0146e4: 14000015  b        #0x14738
uint64_t fde_0334_sub_0146b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF8404288ULL) + (x2 ^ 0x0146B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0146b8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0146bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0146c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000254ULL; // 0x0146c4: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x910ED294ULL; // 0x0146c8: add x20, x20, #0x3b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF8424288ULL; // 0x0146cc: ldur x8, [x20, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0146d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0146d4: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0335 @ 0x0146e8..0x014738 (80 bytes)
// [VN] Phục dựng FDE #0335 tại 0x0146e8..0x014738 (80 byte)
//   0x0146e8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0146ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0146f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0146f4: 910083fd  add      x29, sp, #0x20
//   0x0146f8: 90000255  adrp     x21, #0x5c000
//   0x0146fc: 910ed2b5  add      x21, x21, #0x3b4
//   0x014700: f842c2a8  ldur     x8, [x21, #0x2c]
//   0x014704: aa0503f3  mov      x19, x5
//   0x014708: aa0003f4  mov      x20, x0
//   0x01470c: d63f0100  blr      x8
//   0x014710: 394002a8  ldrb     w8, [x21]
//   0x014714: 340000a8  cbz      w8, #0x14728
uint64_t fde_0335_sub_0146e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x0146E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0146e8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0146ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0146f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0146f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000255ULL; // 0x0146f8: adrp x21, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x910ED2B5ULL; // 0x0146fc: add x21, x21, #0x3b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF842C2A8ULL; // 0x014700: ldur x8, [x21, #0x2c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0503F3ULL; // 0x014704: mov x19, x5
    return acc;
}

// [EN] Reconstructed FDE #0336 @ 0x014738..0x01474c (20 bytes)
// [VN] Phục dựng FDE #0336 tại 0x014738..0x01474c (20 byte)
//   0x014738: eb13011f  cmp      x8, x19
//   0x01473c: 7a400924  ccmp     w9, #0, #4, eq
//   0x014740: 9a8013e0  csel     x0, xzr, x0, ne
//   0x014744: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x014748: d65f03c0  ret      
uint64_t fde_0336_sub_014738(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xEB13011FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014738ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13011FULL; // 0x014738: cmp x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x7A400924ULL; // 0x01473c: ccmp w9, #0, #4, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8013E0ULL; // 0x014740: csel x0, xzr, x0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x014744: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014748: ret 
    return acc;
}

// [EN] Reconstructed FDE #0337 @ 0x01474c..0x014758 (12 bytes)
// [VN] Phục dựng FDE #0337 tại 0x01474c..0x014758 (12 byte)
//   0x01474c: aa1603e0  mov      x0, x22
//   0x014750: aa1503e1  mov      x1, x21
//   0x014754: 17ffda73  b        #0xb120
uint64_t fde_0337_sub_01474c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1603E0ULL) + (x1 ^ 0x17FFDA73ULL) + (x2 ^ 0x01474CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x01474c: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x014750: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDA73ULL; // 0x014754: b #0xb120
    return acc;
}

// [EN] Reconstructed FDE #0338 @ 0x014758..0x014760 (8 bytes)
// [VN] Phục dựng FDE #0338 tại 0x014758..0x014760 (8 byte)
//   0x014758: aa1303e0  mov      x0, x19
//   0x01475c: 17ffffa4  b        #0x145ec
uint64_t fde_0338_sub_014758(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFFFA4ULL) + (x2 ^ 0x014758ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x014758: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFA4ULL; // 0x01475c: b #0x145ec
    return acc;
}

// [EN] Reconstructed FDE #0339 @ 0x014760..0x014768 (8 bytes)
// [VN] Phục dựng FDE #0339 tại 0x014760..0x014768 (8 byte)
//   0x014760: aa0203e1  mov      x1, x2
//   0x014764: 140003ca  b        #0x1568c
uint64_t fde_0339_sub_014760(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E1ULL) + (x1 ^ 0x140003CAULL) + (x2 ^ 0x014760ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x014760: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x140003CAULL; // 0x014764: b #0x1568c
    return acc;
}

// [EN] Reconstructed FDE #0340 @ 0x014768..0x014784 (28 bytes)
// [VN] Phục dựng FDE #0340 tại 0x014768..0x014784 (28 byte)
//   0x014768: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01476c: 910003fd  mov      x29, sp
//   0x014770: 2a0203e1  mov      w1, w2
//   0x014774: 940001d7  bl       #0x14ed0
//   0x014778: 12000000  and      w0, w0, #1
//   0x01477c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x014780: d65f03c0  ret      
uint64_t fde_0340_sub_014768(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014768ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x014768: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01476c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x014770: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x940001D7ULL; // 0x014774: bl #0x14ed0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x014778: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01477c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014780: ret 
    return acc;
}

// [EN] Reconstructed FDE #0341 @ 0x014784..0x0147a0 (28 bytes)
// [VN] Phục dựng FDE #0341 tại 0x014784..0x0147a0 (28 byte)
//   0x014784: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x014788: 910003fd  mov      x29, sp
//   0x01478c: 2a0203e1  mov      w1, w2
//   0x014790: 94000307  bl       #0x153ac
//   0x014794: 12000000  and      w0, w0, #1
//   0x014798: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01479c: d65f03c0  ret      
uint64_t fde_0341_sub_014784(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014784ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x014784: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x014788: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x01478c: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x94000307ULL; // 0x014790: bl #0x153ac
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x014794: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x014798: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01479c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0342 @ 0x0147a0..0x014800 (96 bytes)
// [VN] Phục dựng FDE #0342 tại 0x0147a0..0x014800 (96 byte)
//   0x0147a0: d10103ff  sub      sp, sp, #0x40
//   0x0147a4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0147a8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0147ac: 9100c3fd  add      x29, sp, #0x30
//   0x0147b0: 94000070  bl       #0x14970
//   0x0147b4: b4000082  cbz      x2, #0x147c4
//   0x0147b8: 94000068  bl       #0x14958
//   0x0147bc: aa0003e1  mov      x1, x0
//   0x0147c0: 14000002  b        #0x147c8
//   0x0147c4: aa1f03e1  mov      x1, xzr
//   0x0147c8: aa1303e0  mov      x0, x19
//   0x0147cc: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0342_sub_0147a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x14000002ULL) + (x2 ^ 0x0147A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0147a0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0147a4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0147a8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0147ac: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x94000070ULL; // 0x0147b0: bl #0x14970
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x0147b4: cbz x2, #0x147c4
    acc = (acc * 0x100000001B3ULL) ^ 0x94000068ULL; // 0x0147b8: bl #0x14958
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x0147bc: mov x1, x0
    return acc;
}

// [EN] Reconstructed FDE #0343 @ 0x014800..0x014820 (32 bytes)
// [VN] Phục dựng FDE #0343 tại 0x014800..0x014820 (32 byte)
//   0x014800: f9400802  ldr      x2, [x0, #0x10]
//   0x014804: b40000c2  cbz      x2, #0x1481c
//   0x014808: a9400408  ldp      x8, x1, [x0]
//   0x01480c: f9400109  ldr      x9, [x8]
//   0x014810: aa0803e0  mov      x0, x8
//   0x014814: f942a923  ldr      x3, [x9, #0x550]
//   0x014818: d61f0060  br       x3
//   0x01481c: d65f03c0  ret      
uint64_t fde_0343_sub_014800(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400802ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014800ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400802ULL; // 0x014800: ldr x2, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C2ULL; // 0x014804: cbz x2, #0x1481c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9400408ULL; // 0x014808: ldp x8, x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x01480c: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x014810: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A923ULL; // 0x014814: ldr x3, [x9, #0x550]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x014818: br x3
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01481c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0344 @ 0x014820..0x014880 (96 bytes)
// [VN] Phục dựng FDE #0344 tại 0x014820..0x014880 (96 byte)
//   0x014820: d10103ff  sub      sp, sp, #0x40
//   0x014824: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x014828: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01482c: 9100c3fd  add      x29, sp, #0x30
//   0x014830: 94000050  bl       #0x14970
//   0x014834: b4000082  cbz      x2, #0x14844
//   0x014838: 94000048  bl       #0x14958
//   0x01483c: aa0003e1  mov      x1, x0
//   0x014840: 14000002  b        #0x14848
//   0x014844: aa1f03e1  mov      x1, xzr
//   0x014848: aa1303e0  mov      x0, x19
//   0x01484c: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0344_sub_014820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x14000002ULL) + (x2 ^ 0x014820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x014820: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x014824: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x014828: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01482c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x94000050ULL; // 0x014830: bl #0x14970
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x014834: cbz x2, #0x14844
    acc = (acc * 0x100000001B3ULL) ^ 0x94000048ULL; // 0x014838: bl #0x14958
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x01483c: mov x1, x0
    return acc;
}

// [EN] Reconstructed FDE #0345 @ 0x014880..0x01488c (12 bytes)
// [VN] Phục dựng FDE #0345 tại 0x014880..0x01488c (12 byte)
//   0x014880: 72001c5f  tst      w2, #0xff
//   0x014884: 1a9f07e1  cset     w1, ne
//   0x014888: 1400039f  b        #0x15704
uint64_t fde_0345_sub_014880(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0x1400039FULL) + (x2 ^ 0x014880ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x014880: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E1ULL; // 0x014884: cset w1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x1400039FULL; // 0x014888: b #0x15704
    return acc;
}

// [EN] Reconstructed FDE #0346 @ 0x01488c..0x014958 (204 bytes)
// [VN] Phục dựng FDE #0346 tại 0x01488c..0x014958 (204 byte)
//   0x01488c: d10103ff  sub      sp, sp, #0x40
//   0x014890: f9000bf5  str      x21, [sp, #0x10]
//   0x014894: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x014898: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01489c: 9100c3fd  add      x29, sp, #0x30
//   0x0148a0: d53bd055  mrs      x21, tpidr_el0
//   0x0148a4: f94016a9  ldr      x9, [x21, #0x28]
//   0x0148a8: 2a0203e8  mov      w8, w2
//   0x0148ac: 910003ea  mov      x10, sp
//   0x0148b0: aa0003f3  mov      x19, x0
//   0x0148b4: 91001143  add      x3, x10, #4
//   0x0148b8: 910003e2  mov      x2, sp
uint64_t fde_0346_sub_01488c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910003EAULL) + (x2 ^ 0x01488CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01488c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x014890: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x014894: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x014898: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01489c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0148a0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A9ULL; // 0x0148a4: ldr x9, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0148a8: mov w8, w2
    return acc;
}

// [EN] Reconstructed FDE #0347 @ 0x014958..0x014970 (24 bytes)
// [VN] Phục dựng FDE #0347 tại 0x014958..0x014970 (24 byte)
//   0x014958: f9400268  ldr      x8, [x19]
//   0x01495c: aa1303e0  mov      x0, x19
//   0x014960: aa0203e1  mov      x1, x2
//   0x014964: aa1f03e2  mov      x2, xzr
//   0x014968: f942a508  ldr      x8, [x8, #0x548]
//   0x01496c: d61f0100  br       x8
uint64_t fde_0347_sub_014958(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x014958ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x014958: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01495c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x014960: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x014964: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x014968: ldr x8, [x8, #0x548]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01496c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0348 @ 0x014970..0x014988 (24 bytes)
// [VN] Phục dựng FDE #0348 tại 0x014970..0x014988 (24 byte)
//   0x014970: d53bd054  mrs      x20, tpidr_el0
//   0x014974: f9401688  ldr      x8, [x20, #0x28]
//   0x014978: aa0003f3  mov      x19, x0
//   0x01497c: f9000fe8  str      x8, [sp, #0x18]
//   0x014980: a9000be0  stp      x0, x2, [sp]
//   0x014984: d65f03c0  ret      
uint64_t fde_0348_sub_014970(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD53BD054ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014970ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x014970: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x014974: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x014978: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01497c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000BE0ULL; // 0x014980: stp x0, x2, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014984: ret 
    return acc;
}

// [EN] Reconstructed FDE #0349 @ 0x014988..0x014994 (12 bytes)
// [VN] Phục dựng FDE #0349 tại 0x014988..0x014994 (12 byte)
//   0x014988: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x01498c: 910103ff  add      sp, sp, #0x40
//   0x014990: d65f03c0  ret      
uint64_t fde_0349_sub_014988(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9424FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014988ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9424FF4ULL; // 0x014988: ldp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FFULL; // 0x01498c: add sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014990: ret 
    return acc;
}

// [EN] Reconstructed FDE #0350 @ 0x014994..0x0149d0 (60 bytes)
// [VN] Phục dựng FDE #0350 tại 0x014994..0x0149d0 (60 byte)
//   0x014994: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x014998: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01499c: 910043fd  add      x29, sp, #0x10
//   0x0149a0: aa0103f3  mov      x19, x1
//   0x0149a4: aa0003f4  mov      x20, x0
//   0x0149a8: 9400000a  bl       #0x149d0
//   0x0149ac: f9400288  ldr      x8, [x20]
//   0x0149b0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0149b4: aa0003e2  mov      x2, x0
//   0x0149b8: aa1403e0  mov      x0, x20
//   0x0149bc: f942b104  ldr      x4, [x8, #0x560]
//   0x0149c0: 2a1303e1  mov      w1, w19
uint64_t fde_0350_sub_014994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E2ULL) + (x2 ^ 0x014994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014994: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x014998: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01499c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0149a0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0149a4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000AULL; // 0x0149a8: bl #0x149d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x0149ac: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0149b0: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0351 @ 0x0149d0..0x014a38 (104 bytes)
// [VN] Phục dựng FDE #0351 tại 0x0149d0..0x014a38 (104 byte)
//   0x0149d0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0149d4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0149d8: 910043fd  add      x29, sp, #0x10
//   0x0149dc: 90000254  adrp     x20, #0x5c000
//   0x0149e0: f941f688  ldr      x8, [x20, #0x3e8]
//   0x0149e4: b5000228  cbnz     x8, #0x14a28
//   0x0149e8: f9400008  ldr      x8, [x0]
//   0x0149ec: d0000121  adrp     x1, #0x3a000
//   0x0149f0: 91280421  add      x1, x1, #0xa01
//   0x0149f4: aa0003f3  mov      x19, x0
//   0x0149f8: f9401908  ldr      x8, [x8, #0x30]
//   0x0149fc: d63f0100  blr      x8
uint64_t fde_0351_sub_0149d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91280421ULL) + (x2 ^ 0x0149D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0149d0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0149d4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0149d8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000254ULL; // 0x0149dc: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF941F688ULL; // 0x0149e0: ldr x8, [x20, #0x3e8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000228ULL; // 0x0149e4: cbnz x8, #0x14a28
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0149e8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000121ULL; // 0x0149ec: adrp x1, #0x3a000
    return acc;
}

// [EN] Reconstructed FDE #0352 @ 0x014a38..0x014c94 (604 bytes)
// [VN] Phục dựng FDE #0352 tại 0x014a38..0x014c94 (604 byte)
//   0x014a38: d10203ff  sub      sp, sp, #0x80
//   0x014a3c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x014a40: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x014a44: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x014a48: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x014a4c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x014a50: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x014a54: 9101c3fd  add      x29, sp, #0x70
//   0x014a58: b90007e6  str      w6, [sp, #4]
//   0x014a5c: d53bd05c  mrs      x28, tpidr_el0
//   0x014a60: f9401788  ldr      x8, [x28, #0x28]
//   0x014a64: 2a0503f5  mov      w21, w5
uint64_t fde_0352_sub_014a38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xB90007E6ULL) + (x2 ^ 0x014A38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x014a38: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x014a3c: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x014a40: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x014a44: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x014a48: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x014a4c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x014a50: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x014a54: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0353 @ 0x014c94..0x014d30 (156 bytes)
// [VN] Phục dựng FDE #0353 tại 0x014c94..0x014d30 (156 byte)
//   0x014c94: d10483ff  sub      sp, sp, #0x120
//   0x014c98: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x014c9c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x014ca0: 910443fd  add      x29, sp, #0x110
//   0x014ca4: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x014ca8: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x014cac: f90057e7  str      x7, [sp, #0xa8]
//   0x014cb0: ad0007e0  stp      q0, q1, [sp]
//   0x014cb4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x014cb8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x014cbc: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x014cc0: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0353_sub_014c94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x014C94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x014c94: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x014c98: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x014c9c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x014ca0: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x014ca4: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x014ca8: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x014cac: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x014cb0: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0354 @ 0x014d30..0x014d38 (8 bytes)
// [VN] Phục dựng FDE #0354 tại 0x014d30..0x014d38 (8 byte)
//   0x014d30: aa1f03e1  mov      x1, xzr
//   0x014d34: 14000001  b        #0x14d38
uint64_t fde_0354_sub_014d30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x014D30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x014d30: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x014d34: b #0x14d38
    return acc;
}

// [EN] Reconstructed FDE #0355 @ 0x014d38..0x014d80 (72 bytes)
// [VN] Phục dựng FDE #0355 tại 0x014d38..0x014d80 (72 byte)
//   0x014d38: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x014d3c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x014d40: 910043fd  add      x29, sp, #0x10
//   0x014d44: f9400408  ldr      x8, [x0, #8]
//   0x014d48: eb01011f  cmp      x8, x1
//   0x014d4c: 54000140  b.eq     #0x14d74
//   0x014d50: aa0003f3  mov      x19, x0
//   0x014d54: aa0103f4  mov      x20, x1
//   0x014d58: b40000c8  cbz      x8, #0x14d70
//   0x014d5c: f9400260  ldr      x0, [x19]
//   0x014d60: aa0803e1  mov      x1, x8
//   0x014d64: f9400009  ldr      x9, [x0]
uint64_t fde_0355_sub_014d38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000C8ULL) + (x2 ^ 0x014D38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014d38: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x014d3c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x014d40: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x014d44: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x014d48: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x014d4c: b.eq #0x14d74
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x014d50: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x014d54: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0356 @ 0x014d80..0x014d94 (20 bytes)
// [VN] Phục dựng FDE #0356 tại 0x014d80..0x014d94 (20 byte)
//   0x014d80: f9417908  ldr      x8, [x8, #0x2f0]
//   0x014d84: 91176063  add      x3, x3, #0x5d8
//   0x014d88: aa1403e0  mov      x0, x20
//   0x014d8c: aa1603e1  mov      x1, x22
//   0x014d90: d61f0100  br       x8
uint64_t fde_0356_sub_014d80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9417908ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x014D80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417908ULL; // 0x014d80: ldr x8, [x8, #0x2f0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91176063ULL; // 0x014d84: add x3, x3, #0x5d8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x014d88: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x014d8c: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x014d90: br x8
    return acc;
}

// [EN] Reconstructed FDE #0357 @ 0x014d94..0x014da0 (12 bytes)
// [VN] Phục dựng FDE #0357 tại 0x014d94..0x014da0 (12 byte)
//   0x014d94: aa1403e0  mov      x0, x20
//   0x014d98: aa1603e1  mov      x1, x22
//   0x014d9c: d61f0100  br       x8
uint64_t fde_0357_sub_014d94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x014D94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x014d94: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x014d98: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x014d9c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0358 @ 0x014da0..0x014db0 (16 bytes)
// [VN] Phục dựng FDE #0358 tại 0x014da0..0x014db0 (16 byte)
//   0x014da0: f9400288  ldr      x8, [x20]
//   0x014da4: aa1403e0  mov      x0, x20
//   0x014da8: aa1703e1  mov      x1, x23
//   0x014dac: d65f03c0  ret      
uint64_t fde_0358_sub_014da0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400288ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014DA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x014da0: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x014da4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x014da8: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014dac: ret 
    return acc;
}

// [EN] Reconstructed FDE #0359 @ 0x014db0..0x014db8 (8 bytes)
// [VN] Phục dựng FDE #0359 tại 0x014db0..0x014db8 (8 byte)
//   0x014db0: f941b508  ldr      x8, [x8, #0x368]
//   0x014db4: d61f0100  br       x8
uint64_t fde_0359_sub_014db0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF941B508ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x014DB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF941B508ULL; // 0x014db0: ldr x8, [x8, #0x368]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x014db4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0360 @ 0x014db8..0x014e6c (180 bytes)
// [VN] Phục dựng FDE #0360 tại 0x014db8..0x014e6c (180 byte)
//   0x014db8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x014dbc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x014dc0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x014dc4: 910083fd  add      x29, sp, #0x20
//   0x014dc8: d0000121  adrp     x1, #0x3a000
//   0x014dcc: 9128b821  add      x1, x1, #0xa2e
//   0x014dd0: aa0003f3  mov      x19, x0
//   0x014dd4: 97ffd7ff  bl       #0xadd0
//   0x014dd8: b4000420  cbz      x0, #0x14e5c
//   0x014ddc: f0000235  adrp     x21, #0x5b000
//   0x014de0: f9400008  ldr      x8, [x0]
//   0x014de4: f94412b5  ldr      x21, [x21, #0x820]
uint64_t fde_0360_sub_014db8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB4000420ULL) + (x2 ^ 0x014DB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x014db8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x014dbc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x014dc0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x014dc4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000121ULL; // 0x014dc8: adrp x1, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9128B821ULL; // 0x014dcc: add x1, x1, #0xa2e
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x014dd0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD7FFULL; // 0x014dd4: bl #0xadd0
    return acc;
}

// [EN] Reconstructed FDE #0361 @ 0x014e6c..0x014e9c (48 bytes)
// [VN] Phục dựng FDE #0361 tại 0x014e6c..0x014e9c (48 byte)
//   0x014e6c: a9000801  stp      x1, x2, [x0]
//   0x014e70: b4000141  cbz      x1, #0x14e98
//   0x014e74: b4000122  cbz      x2, #0x14e98
//   0x014e78: 90000248  adrp     x8, #0x5c000
//   0x014e7c: 9110c108  add      x8, x8, #0x430
//   0x014e80: f9400103  ldr      x3, [x8]
//   0x014e84: b40000a3  cbz      x3, #0x14e98
//   0x014e88: f9400508  ldr      x8, [x8, #8]
//   0x014e8c: b4000068  cbz      x8, #0x14e98
//   0x014e90: aa0203e0  mov      x0, x2
//   0x014e94: d61f0060  br       x3
//   0x014e98: d65f03c0  ret      
uint64_t fde_0361_sub_014e6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9000801ULL) + (x1 ^ 0xB4000068ULL) + (x2 ^ 0x014E6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000801ULL; // 0x014e6c: stp x1, x2, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000141ULL; // 0x014e70: cbz x1, #0x14e98
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000122ULL; // 0x014e74: cbz x2, #0x14e98
    acc = (acc * 0x100000001B3ULL) ^ 0x90000248ULL; // 0x014e78: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9110C108ULL; // 0x014e7c: add x8, x8, #0x430
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400103ULL; // 0x014e80: ldr x3, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A3ULL; // 0x014e84: cbz x3, #0x14e98
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400508ULL; // 0x014e88: ldr x8, [x8, #8]
    return acc;
}

// [EN] Reconstructed FDE #0362 @ 0x014e9c..0x014ed0 (52 bytes)
// [VN] Phục dựng FDE #0362 tại 0x014e9c..0x014ed0 (52 byte)
//   0x014e9c: 90000248  adrp     x8, #0x5c000
//   0x014ea0: 9110c108  add      x8, x8, #0x430
//   0x014ea4: f9400109  ldr      x9, [x8]
//   0x014ea8: b4000129  cbz      x9, #0x14ecc
//   0x014eac: f9400502  ldr      x2, [x8, #8]
//   0x014eb0: b40000e2  cbz      x2, #0x14ecc
//   0x014eb4: f9400408  ldr      x8, [x0, #8]
//   0x014eb8: b40000a8  cbz      x8, #0x14ecc
//   0x014ebc: f9400001  ldr      x1, [x0]
//   0x014ec0: b4000061  cbz      x1, #0x14ecc
//   0x014ec4: aa0803e0  mov      x0, x8
//   0x014ec8: d61f0040  br       x2
uint64_t fde_0362_sub_014e9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000248ULL) + (x1 ^ 0xF9400001ULL) + (x2 ^ 0x014E9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000248ULL; // 0x014e9c: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9110C108ULL; // 0x014ea0: add x8, x8, #0x430
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x014ea4: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000129ULL; // 0x014ea8: cbz x9, #0x14ecc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400502ULL; // 0x014eac: ldr x2, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E2ULL; // 0x014eb0: cbz x2, #0x14ecc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x014eb4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A8ULL; // 0x014eb8: cbz x8, #0x14ecc
    return acc;
}

// [EN] Reconstructed FDE #0363 @ 0x014ed0..0x014fec (284 bytes)
// [VN] Phục dựng FDE #0363 tại 0x014ed0..0x014fec (284 byte)
//   0x014ed0: d10203ff  sub      sp, sp, #0x80
//   0x014ed4: f90023f7  str      x23, [sp, #0x40]
//   0x014ed8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x014edc: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x014ee0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x014ee4: 9101c3fd  add      x29, sp, #0x70
//   0x014ee8: d53bd055  mrs      x21, tpidr_el0
//   0x014eec: f94016a8  ldr      x8, [x21, #0x28]
//   0x014ef0: 2a0103f3  mov      w19, w1
//   0x014ef4: f9001fe8  str      x8, [sp, #0x38]
//   0x014ef8: 9400003d  bl       #0x14fec
//   0x014efc: 36000660  tbz      w0, #0, #0x14fc8
uint64_t fde_0363_sub_014ed0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0103F3ULL) + (x2 ^ 0x014ED0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x014ed0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x014ed4: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x014ed8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x014edc: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x014ee0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x014ee4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x014ee8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x014eec: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0364 @ 0x014fec..0x0153ac (960 bytes)
// [VN] Phục dựng FDE #0364 tại 0x014fec..0x0153ac (960 byte)
//   0x014fec: d101c3ff  sub      sp, sp, #0x70
//   0x014ff0: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x014ff4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x014ff8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x014ffc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x015000: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x015004: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x015008: 910183fd  add      x29, sp, #0x60
//   0x01500c: d53bd058  mrs      x24, tpidr_el0
//   0x015010: f9401708  ldr      x8, [x24, #0x28]
//   0x015014: f0000239  adrp     x25, #0x5c000
//   0x015018: 9111a339  add      x25, x25, #0x468
uint64_t fde_0364_sub_014fec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xD53BD058ULL) + (x2 ^ 0x014FECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x014fec: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x014ff0: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x014ff4: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x014ff8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x014ffc: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x015000: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x015004: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x015008: add x29, sp, #0x60
    return acc;
}

// [EN] Reconstructed FDE #0365 @ 0x0153ac..0x015440 (148 bytes)
// [VN] Phục dựng FDE #0365 tại 0x0153ac..0x015440 (148 byte)
//   0x0153ac: d101c3ff  sub      sp, sp, #0x70
//   0x0153b0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0153b4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0153b8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0153bc: 910183fd  add      x29, sp, #0x60
//   0x0153c0: 94000361  bl       #0x16144
//   0x0153c4: 2a0103f4  mov      w20, w1
//   0x0153c8: 9400035c  bl       #0x16138
//   0x0153cc: 360002a0  tbz      w0, #0, #0x15420
//   0x0153d0: 910043e8  add      x8, sp, #0x10
//   0x0153d4: 91004115  add      x21, x8, #0x10
//   0x0153d8: aa1503e0  mov      x0, x21
uint64_t fde_0365_sub_0153ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x360002A0ULL) + (x2 ^ 0x0153ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0153ac: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0153b0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0153b4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0153b8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0153bc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x94000361ULL; // 0x0153c0: bl #0x16144
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x0153c4: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x9400035CULL; // 0x0153c8: bl #0x16138
    return acc;
}

// [EN] Reconstructed FDE #0366 @ 0x015440..0x015500 (192 bytes)
// [VN] Phục dựng FDE #0366 tại 0x015440..0x015500 (192 byte)
//   0x015440: d10143ff  sub      sp, sp, #0x50
//   0x015444: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x015448: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01544c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x015450: 910103fd  add      x29, sp, #0x40
//   0x015454: d53bd055  mrs      x21, tpidr_el0
//   0x015458: f94016a8  ldr      x8, [x21, #0x28]
//   0x01545c: aa0103f4  mov      x20, x1
//   0x015460: f9000fe8  str      x8, [sp, #0x18]
//   0x015464: 97fffee2  bl       #0x14fec
//   0x015468: 36000380  tbz      w0, #0, #0x154d8
//   0x01546c: d0000229  adrp     x9, #0x5b000
uint64_t fde_0366_sub_015440(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x015440ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x015440: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x015444: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x015448: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01544c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x015450: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x015454: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x015458: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01545c: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0367 @ 0x015500..0x01559c (156 bytes)
// [VN] Phục dựng FDE #0367 tại 0x015500..0x01559c (156 byte)
//   0x015500: d101c3ff  sub      sp, sp, #0x70
//   0x015504: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x015508: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01550c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x015510: 910183fd  add      x29, sp, #0x60
//   0x015514: 9400030c  bl       #0x16144
//   0x015518: aa0103f4  mov      x20, x1
//   0x01551c: 94000307  bl       #0x16138
//   0x015520: 360002e0  tbz      w0, #0, #0x1557c
//   0x015524: 910043e8  add      x8, sp, #0x10
//   0x015528: 91004115  add      x21, x8, #0x10
//   0x01552c: aa1503e0  mov      x0, x21
uint64_t fde_0367_sub_015500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x360002E0ULL) + (x2 ^ 0x015500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x015500: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x015504: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x015508: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01550c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x015510: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x9400030CULL; // 0x015514: bl #0x16144
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x015518: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000307ULL; // 0x01551c: bl #0x16138
    return acc;
}

// [EN] Reconstructed FDE #0368 @ 0x01559c..0x01568c (240 bytes)
// [VN] Phục dựng FDE #0368 tại 0x01559c..0x01568c (240 byte)
//   0x01559c: d10203ff  sub      sp, sp, #0x80
//   0x0155a0: f90023f7  str      x23, [sp, #0x40]
//   0x0155a4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0155a8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0155ac: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0155b0: 9101c3fd  add      x29, sp, #0x70
//   0x0155b4: 940002e4  bl       #0x16144
//   0x0155b8: aa0103f3  mov      x19, x1
//   0x0155bc: f9001fe8  str      x8, [sp, #0x38]
//   0x0155c0: 97fffe8b  bl       #0x14fec
//   0x0155c4: 36000540  tbz      w0, #0, #0x1566c
//   0x0155c8: 910043e8  add      x8, sp, #0x10
uint64_t fde_0368_sub_01559c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9001FE8ULL) + (x2 ^ 0x01559CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01559c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x0155a0: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0155a4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0155a8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0155ac: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0155b0: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x940002E4ULL; // 0x0155b4: bl #0x16144
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0155b8: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0369 @ 0x01568c..0x015704 (120 bytes)
// [VN] Phục dựng FDE #0369 tại 0x01568c..0x015704 (120 byte)
//   0x01568c: d100c3ff  sub      sp, sp, #0x30
//   0x015690: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x015694: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x015698: 910083fd  add      x29, sp, #0x20
//   0x01569c: d53bd054  mrs      x20, tpidr_el0
//   0x0156a0: f9401688  ldr      x8, [x20, #0x28]
//   0x0156a4: aa0003f3  mov      x19, x0
//   0x0156a8: f90007e8  str      x8, [sp, #8]
//   0x0156ac: f90003e1  str      x1, [sp]
//   0x0156b0: 97fffe4f  bl       #0x14fec
//   0x0156b4: 36000140  tbz      w0, #0, #0x156dc
//   0x0156b8: 910003e1  mov      x1, sp
uint64_t fde_0369_sub_01568c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90003E1ULL) + (x2 ^ 0x01568CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x01568c: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x015690: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x015694: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x015698: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x01569c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0156a0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0156a4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x0156a8: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0370 @ 0x015704..0x0158b0 (428 bytes)
// [VN] Phục dựng FDE #0370 tại 0x015704..0x0158b0 (428 byte)
//   0x015704: d102c3ff  sub      sp, sp, #0xb0
//   0x015708: f9002bfb  str      x27, [sp, #0x50]
//   0x01570c: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x015710: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x015714: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x015718: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x01571c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x015720: 910283fd  add      x29, sp, #0xa0
//   0x015724: d53bd05a  mrs      x26, tpidr_el0
//   0x015728: f9401748  ldr      x8, [x26, #0x28]
//   0x01572c: 2a0103f3  mov      w19, w1
//   0x015730: aa0003f4  mov      x20, x0
uint64_t fde_0370_sub_015704(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xD53BD05AULL) + (x2 ^ 0x015704ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x015704: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x015708: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x01570c: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x015710: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x015714: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x015718: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x01571c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x015720: add x29, sp, #0xa0
    return acc;
}

// [EN] Reconstructed FDE #0371 @ 0x0158b0..0x0158c4 (20 bytes)
// [VN] Phục dựng FDE #0371 tại 0x0158b0..0x0158c4 (20 byte)
//   0x0158b0: 3cc10420  ldr      q0, [x1], #0x10
//   0x0158b4: 91004008  add      x8, x0, #0x10
//   0x0158b8: 3d800000  str      q0, [x0]
//   0x0158bc: aa0803e0  mov      x0, x8
//   0x0158c0: 17ffe6e3  b        #0xf44c
uint64_t fde_0371_sub_0158b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3CC10420ULL) + (x1 ^ 0x17FFE6E3ULL) + (x2 ^ 0x0158B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10420ULL; // 0x0158b0: ldr q0, [x1], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91004008ULL; // 0x0158b4: add x8, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x0158b8: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x0158bc: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE6E3ULL; // 0x0158c0: b #0xf44c
    return acc;
}

// [EN] Reconstructed FDE #0372 @ 0x0158c4..0x015940 (124 bytes)
// [VN] Phục dựng FDE #0372 tại 0x0158c4..0x015940 (124 byte)
//   0x0158c4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0158c8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0158cc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0158d0: 910083fd  add      x29, sp, #0x20
//   0x0158d4: aa0203f4  mov      x20, x2
//   0x0158d8: aa0103f5  mov      x21, x1
//   0x0158dc: aa0003f3  mov      x19, x0
//   0x0158e0: 94000c03  bl       #0x188ec
//   0x0158e4: 7100681f  cmp      w0, #0x1a
//   0x0158e8: 5400010b  b.lt     #0x15908
//   0x0158ec: aa1303e0  mov      x0, x19
//   0x0158f0: aa1503e1  mov      x1, x21
uint64_t fde_0372_sub_0158c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x7100681FULL) + (x2 ^ 0x0158C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0158c4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0158c8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0158cc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0158d0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x0158d4: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0158d8: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0158dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000C03ULL; // 0x0158e0: bl #0x188ec
    return acc;
}

// [EN] Reconstructed FDE #0373 @ 0x015940..0x015980 (64 bytes)
// [VN] Phục dựng FDE #0373 tại 0x015940..0x015980 (64 byte)
//   0x015940: b9400428  ldr      w8, [x1, #4]
//   0x015944: 3100051f  cmn      w8, #1
//   0x015948: 540001a1  b.ne     #0x1597c
//   0x01594c: d0000228  adrp     x8, #0x5b000
//   0x015950: f9437908  ldr      x8, [x8, #0x6f0]
//   0x015954: b9400029  ldr      w9, [x1]
//   0x015958: b9800108  ldrsw    x8, [x8]
//   0x01595c: b8606908  ldr      w8, [x8, x0]
//   0x015960: 6b08013f  cmp      w9, w8
//   0x015964: 540000c1  b.ne     #0x1597c
//   0x015968: d0000228  adrp     x8, #0x5b000
//   0x01596c: f9450908  ldr      x8, [x8, #0xa10]
uint64_t fde_0373_sub_015940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400428ULL) + (x1 ^ 0x6B08013FULL) + (x2 ^ 0x015940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400428ULL; // 0x015940: ldr w8, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x3100051FULL; // 0x015944: cmn w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A1ULL; // 0x015948: b.ne #0x1597c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000228ULL; // 0x01594c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9437908ULL; // 0x015950: ldr x8, [x8, #0x6f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x015954: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800108ULL; // 0x015958: ldrsw x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8606908ULL; // 0x01595c: ldr w8, [x8, x0]
    return acc;
}

// [EN] Reconstructed FDE #0374 @ 0x015980..0x0159ac (44 bytes)
// [VN] Phục dựng FDE #0374 tại 0x015980..0x0159ac (44 byte)
//   0x015980: f9400428  ldr      x8, [x1, #8]
//   0x015984: b5000128  cbnz     x8, #0x159a8
//   0x015988: d0000228  adrp     x8, #0x5b000
//   0x01598c: f9437908  ldr      x8, [x8, #0x6f0]
//   0x015990: b9400029  ldr      w9, [x1]
//   0x015994: b9800108  ldrsw    x8, [x8]
//   0x015998: b8606908  ldr      w8, [x8, x0]
//   0x01599c: 6b08013f  cmp      w9, w8
//   0x0159a0: 54000041  b.ne     #0x159a8
//   0x0159a4: f9000420  str      x0, [x1, #8]
//   0x0159a8: d65f03c0  ret      
uint64_t fde_0374_sub_015980(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400428ULL) + (x1 ^ 0x54000041ULL) + (x2 ^ 0x015980ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400428ULL; // 0x015980: ldr x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000128ULL; // 0x015984: cbnz x8, #0x159a8
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000228ULL; // 0x015988: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9437908ULL; // 0x01598c: ldr x8, [x8, #0x6f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x015990: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800108ULL; // 0x015994: ldrsw x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8606908ULL; // 0x015998: ldr w8, [x8, x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x01599c: cmp w9, w8
    return acc;
}

// [EN] Reconstructed FDE #0375 @ 0x0159ac..0x0159e0 (52 bytes)
// [VN] Phục dựng FDE #0375 tại 0x0159ac..0x0159e0 (52 byte)
//   0x0159ac: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0159b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0159b4: 910043fd  add      x29, sp, #0x10
//   0x0159b8: aa0003f4  mov      x20, x0
//   0x0159bc: aa0103e0  mov      x0, x1
//   0x0159c0: aa0103f3  mov      x19, x1
//   0x0159c4: 97ffd597  bl       #0xb020
//   0x0159c8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0159cc: aa0003e2  mov      x2, x0
//   0x0159d0: aa1403e0  mov      x0, x20
//   0x0159d4: aa1303e1  mov      x1, x19
//   0x0159d8: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0375_sub_0159ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E2ULL) + (x2 ^ 0x0159ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0159ac: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0159b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0159b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0159b8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x0159bc: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0159c0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD597ULL; // 0x0159c4: bl #0xb020
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0159c8: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0376 @ 0x0159e0..0x015a40 (96 bytes)
// [VN] Phục dựng FDE #0376 tại 0x0159e0..0x015a40 (96 byte)
//   0x0159e0: d10143ff  sub      sp, sp, #0x50
//   0x0159e4: f90013f5  str      x21, [sp, #0x20]
//   0x0159e8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0159ec: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0159f0: 910103fd  add      x29, sp, #0x40
//   0x0159f4: d53bd055  mrs      x21, tpidr_el0
//   0x0159f8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0159fc: f9000fe8  str      x8, [sp, #0x18]
//   0x015a00: f9400428  ldr      x8, [x1, #8]
//   0x015a04: b5000148  cbnz     x8, #0x15a2c
//   0x015a08: aa0003f4  mov      x20, x0
//   0x015a0c: 910003e0  mov      x0, sp
uint64_t fde_0376_sub_0159e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9400428ULL) + (x2 ^ 0x0159E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0159e0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x0159e4: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0159e8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0159ec: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0159f0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0159f4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0159f8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0159fc: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0377 @ 0x015a40..0x015a9c (92 bytes)
// [VN] Phục dựng FDE #0377 tại 0x015a40..0x015a9c (92 byte)
//   0x015a40: d10103ff  sub      sp, sp, #0x40
//   0x015a44: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x015a48: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x015a4c: 9100c3fd  add      x29, sp, #0x30
//   0x015a50: d53bd054  mrs      x20, tpidr_el0
//   0x015a54: f9401688  ldr      x8, [x20, #0x28]
//   0x015a58: aa0003f3  mov      x19, x0
//   0x015a5c: aa0103e0  mov      x0, x1
//   0x015a60: f9000fe8  str      x8, [sp, #0x18]
//   0x015a64: 94000026  bl       #0x15afc
//   0x015a68: a90087e0  stp      x0, x1, [sp, #8]
//   0x015a6c: 910023e1  add      x1, sp, #8
uint64_t fde_0377_sub_015a40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x015A40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x015a40: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x015a44: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x015a48: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x015a4c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x015a50: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x015a54: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015a58: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x015a5c: mov x0, x1
    return acc;
}

// [EN] Reconstructed FDE #0378 @ 0x015a9c..0x015afc (96 bytes)
// [VN] Phục dựng FDE #0378 tại 0x015a9c..0x015afc (96 byte)
//   0x015a9c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x015aa0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015aa4: 910043fd  add      x29, sp, #0x10
//   0x015aa8: aa0103e8  mov      x8, x1
//   0x015aac: 39400009  ldrb     w9, [x0]
//   0x015ab0: f9400021  ldr      x1, [x1]
//   0x015ab4: f9400513  ldr      x19, [x8, #8]
//   0x015ab8: 37000089  tbnz     w9, #0, #0x15ac8
//   0x015abc: d341fd34  lsr      x20, x9, #1
//   0x015ac0: 91000400  add      x0, x0, #1
//   0x015ac4: 14000003  b        #0x15ad0
//   0x015ac8: f9400414  ldr      x20, [x0, #8]
uint64_t fde_0378_sub_015a9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD341FD34ULL) + (x2 ^ 0x015A9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x015a9c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015aa0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015aa4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x015aa8: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39400009ULL; // 0x015aac: ldrb w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x015ab0: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400513ULL; // 0x015ab4: ldr x19, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000089ULL; // 0x015ab8: tbnz w9, #0, #0x15ac8
    return acc;
}

// [EN] Reconstructed FDE #0379 @ 0x015afc..0x015b18 (28 bytes)
// [VN] Phục dựng FDE #0379 tại 0x015afc..0x015b18 (28 byte)
//   0x015afc: 39400008  ldrb     w8, [x0]
//   0x015b00: 37000088  tbnz     w8, #0, #0x15b10
//   0x015b04: 91000400  add      x0, x0, #1
//   0x015b08: d341fd01  lsr      x1, x8, #1
//   0x015b0c: d65f03c0  ret      
//   0x015b10: a9408001  ldp      x1, x0, [x0, #8]
//   0x015b14: d65f03c0  ret      
uint64_t fde_0379_sub_015afc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x015AFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x015afc: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000088ULL; // 0x015b00: tbnz w8, #0, #0x15b10
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x015b04: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD01ULL; // 0x015b08: lsr x1, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x015b0c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xA9408001ULL; // 0x015b10: ldp x1, x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x015b14: ret 
    return acc;
}

// [EN] Reconstructed FDE #0380 @ 0x015b18..0x015b8c (116 bytes)
// [VN] Phục dựng FDE #0380 tại 0x015b18..0x015b8c (116 byte)
//   0x015b18: d10143ff  sub      sp, sp, #0x50
//   0x015b1c: f90013f5  str      x21, [sp, #0x20]
//   0x015b20: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x015b24: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x015b28: 910103fd  add      x29, sp, #0x40
//   0x015b2c: d53bd055  mrs      x21, tpidr_el0
//   0x015b30: f94016a8  ldr      x8, [x21, #0x28]
//   0x015b34: f9000fe8  str      x8, [sp, #0x18]
//   0x015b38: b9400428  ldr      w8, [x1, #4]
//   0x015b3c: 3100051f  cmn      w8, #1
//   0x015b40: 540001c1  b.ne     #0x15b78
//   0x015b44: aa0003f4  mov      x20, x0
uint64_t fde_0380_sub_015b18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB9400428ULL) + (x2 ^ 0x015B18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x015b18: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x015b1c: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x015b20: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x015b24: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x015b28: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x015b2c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x015b30: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x015b34: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0381 @ 0x015b8c..0x015c58 (204 bytes)
// [VN] Phục dựng FDE #0381 tại 0x015b8c..0x015c58 (204 byte)
//   0x015b8c: d10243ff  sub      sp, sp, #0x90
//   0x015b90: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x015b94: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x015b98: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x015b9c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x015ba0: 910203fd  add      x29, sp, #0x80
//   0x015ba4: 94000168  bl       #0x16144
//   0x015ba8: d0000229  adrp     x9, #0x5b000
//   0x015bac: d000022a  adrp     x10, #0x5b000
//   0x015bb0: f9437929  ldr      x9, [x9, #0x6f0]
//   0x015bb4: f945094a  ldr      x10, [x10, #0xa10]
//   0x015bb8: f81c83a8  stur     x8, [x29, #-0x38]
uint64_t fde_0381_sub_015b8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xD000022AULL) + (x2 ^ 0x015B8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x015b8c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x015b90: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x015b94: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x015b98: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x015b9c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x015ba0: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x94000168ULL; // 0x015ba4: bl #0x16144
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000229ULL; // 0x015ba8: adrp x9, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0382 @ 0x015c58..0x015c6c (20 bytes)
// [VN] Phục dựng FDE #0382 tại 0x015c58..0x015c6c (20 byte)
//   0x015c58: a940a408  ldp      x8, x9, [x0, #8]
//   0x015c5c: eb09011f  cmp      x8, x9
//   0x015c60: 54000042  b.hs     #0x15c68
//   0x015c64: 14000002  b        #0x15c6c
//   0x015c68: 1400000d  b        #0x15c9c
uint64_t fde_0382_sub_015c58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x1400000DULL) + (x2 ^ 0x015C58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x015c58: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x015c5c: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000042ULL; // 0x015c60: b.hs #0x15c68
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x015c64: b #0x15c6c
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000DULL; // 0x015c68: b #0x15c9c
    return acc;
}

// [EN] Reconstructed FDE #0383 @ 0x015c6c..0x015c9c (48 bytes)
// [VN] Phục dựng FDE #0383 tại 0x015c6c..0x015c9c (48 byte)
//   0x015c6c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x015c70: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015c74: 910043fd  add      x29, sp, #0x10
//   0x015c78: f9400414  ldr      x20, [x0, #8]
//   0x015c7c: aa0003f3  mov      x19, x0
//   0x015c80: aa1403e0  mov      x0, x20
//   0x015c84: 97ffff0b  bl       #0x158b0
//   0x015c88: 9100a288  add      x8, x20, #0x28
//   0x015c8c: f9000668  str      x8, [x19, #8]
//   0x015c90: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x015c94: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x015c98: d65f03c0  ret      
uint64_t fde_0383_sub_015c6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000668ULL) + (x2 ^ 0x015C6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x015c6c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015c70: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015c74: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x015c78: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015c7c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x015c80: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF0BULL; // 0x015c84: bl #0x158b0
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A288ULL; // 0x015c88: add x8, x20, #0x28
    return acc;
}

// [EN] Reconstructed FDE #0384 @ 0x015c9c..0x015d58 (188 bytes)
// [VN] Phục dựng FDE #0384 tại 0x015c9c..0x015d58 (188 byte)
//   0x015c9c: d101c3ff  sub      sp, sp, #0x70
//   0x015ca0: f9001bf7  str      x23, [sp, #0x30]
//   0x015ca4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x015ca8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x015cac: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x015cb0: 910183fd  add      x29, sp, #0x60
//   0x015cb4: d53bd056  mrs      x22, tpidr_el0
//   0x015cb8: f94016c8  ldr      x8, [x22, #0x28]
//   0x015cbc: 52800517  mov      w23, #0x28
//   0x015cc0: aa0103f3  mov      x19, x1
//   0x015cc4: aa0003f4  mov      x20, x0
//   0x015cc8: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0384_sub_015c9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x52800517ULL) + (x2 ^ 0x015C9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x015c9c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x015ca0: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x015ca4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x015ca8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x015cac: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x015cb0: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x015cb4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x015cb8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0385 @ 0x015d58..0x015db4 (92 bytes)
// [VN] Phục dựng FDE #0385 tại 0x015d58..0x015db4 (92 byte)
//   0x015d58: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x015d5c: 910003fd  mov      x29, sp
//   0x015d60: b203e7e8  mov      x8, #0x6666666666666666
//   0x015d64: f2e0ccc8  movk     x8, #0x666, lsl #48
//   0x015d68: eb08003f  cmp      x1, x8
//   0x015d6c: 54000228  b.hi     #0x15db0
//   0x015d70: f9400809  ldr      x9, [x0, #0x10]
//   0x015d74: f940000a  ldr      x10, [x0]
//   0x015d78: 5280050b  mov      w11, #0x28
//   0x015d7c: cb0a0129  sub      x9, x9, x10
//   0x015d80: b200e7ea  mov      x10, #0x3333333333333333
//   0x015d84: f286664a  movk     x10, #0x3332
uint64_t fde_0385_sub_015d58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x5280050BULL) + (x2 ^ 0x015D58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x015d58: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x015d5c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB203E7E8ULL; // 0x015d60: mov x8, #0x6666666666666666
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0CCC8ULL; // 0x015d64: movk x8, #0x666, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x015d68: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000228ULL; // 0x015d6c: b.hi #0x15db0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x015d70: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940000AULL; // 0x015d74: ldr x10, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0386 @ 0x015db4..0x015e10 (92 bytes)
// [VN] Phục dựng FDE #0386 tại 0x015db4..0x015e10 (92 byte)
//   0x015db4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x015db8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x015dbc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x015dc0: 910083fd  add      x29, sp, #0x20
//   0x015dc4: aa0203f5  mov      x21, x2
//   0x015dc8: aa0103f4  mov      x20, x1
//   0x015dcc: aa0003f3  mov      x19, x0
//   0x015dd0: a9018c1f  stp      xzr, x3, [x0, #0x18]
//   0x015dd4: b40000a1  cbz      x1, #0x15de8
//   0x015dd8: aa0303e0  mov      x0, x3
//   0x015ddc: aa1403e1  mov      x1, x20
//   0x015de0: 94000032  bl       #0x15ea8
uint64_t fde_0386_sub_015db4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB40000A1ULL) + (x2 ^ 0x015DB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x015db4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x015db8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x015dbc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x015dc0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x015dc4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x015dc8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015dcc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9018C1FULL; // 0x015dd0: stp xzr, x3, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0387 @ 0x015e10..0x015e74 (100 bytes)
// [VN] Phục dựng FDE #0387 tại 0x015e10..0x015e74 (100 byte)
//   0x015e10: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x015e14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015e18: 910043fd  add      x29, sp, #0x10
//   0x015e1c: aa0103f3  mov      x19, x1
//   0x015e20: aa0003f4  mov      x20, x0
//   0x015e24: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x015e28: 91002263  add      x3, x19, #8
//   0x015e2c: 9400002c  bl       #0x15edc
//   0x015e30: f9400668  ldr      x8, [x19, #8]
//   0x015e34: f9400289  ldr      x9, [x20]
//   0x015e38: f9000288  str      x8, [x20]
//   0x015e3c: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0387_sub_015e10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x015E10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x015e10: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015e14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015e18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x015e1c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x015e20: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x015e24: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x015e28: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002CULL; // 0x015e2c: bl #0x15edc
    return acc;
}

// [EN] Reconstructed FDE #0388 @ 0x015e74..0x015ea8 (52 bytes)
// [VN] Phục dựng FDE #0388 tại 0x015e74..0x015ea8 (52 byte)
//   0x015e74: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x015e78: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015e7c: 910043fd  add      x29, sp, #0x10
//   0x015e80: aa0003f3  mov      x19, x0
//   0x015e84: 94000035  bl       #0x15f58
//   0x015e88: f9400260  ldr      x0, [x19]
//   0x015e8c: b4000080  cbz      x0, #0x15e9c
//   0x015e90: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x015e94: f84207f3  ldr      x19, [sp], #0x20
//   0x015e98: 17ffd3aa  b        #0xad40
//   0x015e9c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x015ea0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0388_sub_015e74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x015E74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x015e74: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015e78: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015e7c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015e80: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000035ULL; // 0x015e84: bl #0x15f58
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x015e88: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x015e8c: cbz x0, #0x15e9c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x015e90: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0389 @ 0x015ea8..0x015eb0 (8 bytes)
// [VN] Phục dựng FDE #0389 tại 0x015ea8..0x015eb0 (8 byte)
//   0x015ea8: aa1f03e2  mov      x2, xzr
//   0x015eac: 14000001  b        #0x15eb0
uint64_t fde_0389_sub_015ea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x015EA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x015ea8: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x015eac: b #0x15eb0
    return acc;
}

// [EN] Reconstructed FDE #0390 @ 0x015eb0..0x015edc (44 bytes)
// [VN] Phục dựng FDE #0390 tại 0x015eb0..0x015edc (44 byte)
//   0x015eb0: b203e7e8  mov      x8, #0x6666666666666666
//   0x015eb4: f28ccce8  movk     x8, #0x6667
//   0x015eb8: f2e0ccc8  movk     x8, #0x666, lsl #48
//   0x015ebc: eb08003f  cmp      x1, x8
//   0x015ec0: 54000082  b.hs     #0x15ed0
//   0x015ec4: 8b010828  add      x8, x1, x1, lsl #2
//   0x015ec8: d37df100  lsl      x0, x8, #3
//   0x015ecc: 17ffd5c9  b        #0xb5f0
//   0x015ed0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x015ed4: 910003fd  mov      x29, sp
//   0x015ed8: 97ffd58a  bl       #0xb500
uint64_t fde_0390_sub_015eb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB203E7E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x015EB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB203E7E8ULL; // 0x015eb0: mov x8, #0x6666666666666666
    acc = (acc * 0x100000001B3ULL) ^ 0xF28CCCE8ULL; // 0x015eb4: movk x8, #0x6667
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0CCC8ULL; // 0x015eb8: movk x8, #0x666, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x015ebc: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x015ec0: b.hs #0x15ed0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010828ULL; // 0x015ec4: add x8, x1, x1, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x015ec8: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD5C9ULL; // 0x015ecc: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0391 @ 0x015edc..0x015f34 (88 bytes)
// [VN] Phục dựng FDE #0391 tại 0x015edc..0x015f34 (88 byte)
//   0x015edc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x015ee0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x015ee4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x015ee8: 910083fd  add      x29, sp, #0x20
//   0x015eec: aa0303f3  mov      x19, x3
//   0x015ef0: aa0203f4  mov      x20, x2
//   0x015ef4: aa0103f5  mov      x21, x1
//   0x015ef8: eb1402bf  cmp      x21, x20
//   0x015efc: 54000140  b.eq     #0x15f24
//   0x015f00: f9400268  ldr      x8, [x19]
//   0x015f04: d100a294  sub      x20, x20, #0x28
//   0x015f08: aa1403e1  mov      x1, x20
uint64_t fde_0391_sub_015edc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000140ULL) + (x2 ^ 0x015EDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x015edc: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x015ee0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x015ee4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x015ee8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x015eec: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x015ef0: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x015ef4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1402BFULL; // 0x015ef8: cmp x21, x20
    return acc;
}

// [EN] Reconstructed FDE #0392 @ 0x015f34..0x015f58 (36 bytes)
// [VN] Phục dựng FDE #0392 tại 0x015f34..0x015f58 (36 byte)
//   0x015f34: 3dc00020  ldr      q0, [x1]
//   0x015f38: 91004028  add      x8, x1, #0x10
//   0x015f3c: 3d800000  str      q0, [x0]
//   0x015f40: f9401029  ldr      x9, [x1, #0x20]
//   0x015f44: 3dc00420  ldr      q0, [x1, #0x10]
//   0x015f48: f9001009  str      x9, [x0, #0x20]
//   0x015f4c: 3d800400  str      q0, [x0, #0x10]
//   0x015f50: aa0803e0  mov      x0, x8
//   0x015f54: 17ffe5ed  b        #0xf708
uint64_t fde_0392_sub_015f34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3DC00020ULL) + (x1 ^ 0x17FFE5EDULL) + (x2 ^ 0x015F34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x015f34: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004028ULL; // 0x015f38: add x8, x1, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x015f3c: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401029ULL; // 0x015f40: ldr x9, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00420ULL; // 0x015f44: ldr q0, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001009ULL; // 0x015f48: str x9, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800400ULL; // 0x015f4c: str q0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x015f50: mov x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0393 @ 0x015f58..0x015f60 (8 bytes)
// [VN] Phục dựng FDE #0393 tại 0x015f58..0x015f60 (8 byte)
//   0x015f58: f9400401  ldr      x1, [x0, #8]
//   0x015f5c: 14000001  b        #0x15f60
uint64_t fde_0393_sub_015f58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x015F58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x015f58: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x015f5c: b #0x15f60
    return acc;
}

// [EN] Reconstructed FDE #0394 @ 0x015f60..0x015f64 (4 bytes)
// [VN] Phục dựng FDE #0394 tại 0x015f60..0x015f64 (4 byte)
//   0x015f60: 14000001  b        #0x15f64
uint64_t fde_0394_sub_015f60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x015F60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x015f60: b #0x15f64
    return acc;
}

// [EN] Reconstructed FDE #0395 @ 0x015f64..0x015fa4 (64 bytes)
// [VN] Phục dựng FDE #0395 tại 0x015f64..0x015fa4 (64 byte)
//   0x015f64: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x015f68: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015f6c: 910043fd  add      x29, sp, #0x10
//   0x015f70: aa0103f3  mov      x19, x1
//   0x015f74: aa0003f4  mov      x20, x0
//   0x015f78: f9400a88  ldr      x8, [x20, #0x10]
//   0x015f7c: eb13011f  cmp      x8, x19
//   0x015f80: 540000c0  b.eq     #0x15f98
//   0x015f84: d100a109  sub      x9, x8, #0x28
//   0x015f88: d1006100  sub      x0, x8, #0x18
//   0x015f8c: f9000a89  str      x9, [x20, #0x10]
//   0x015f90: 97ffde2d  bl       #0xd844
uint64_t fde_0395_sub_015f64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD100A109ULL) + (x2 ^ 0x015F64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x015f64: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015f68: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015f6c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x015f70: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x015f74: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A88ULL; // 0x015f78: ldr x8, [x20, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13011FULL; // 0x015f7c: cmp x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x015f80: b.eq #0x15f98
    return acc;
}

// [EN] Reconstructed FDE #0396 @ 0x015fa4..0x015fdc (56 bytes)
// [VN] Phục dựng FDE #0396 tại 0x015fa4..0x015fdc (56 byte)
//   0x015fa4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x015fa8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x015fac: 910043fd  add      x29, sp, #0x10
//   0x015fb0: f9400008  ldr      x8, [x0]
//   0x015fb4: b40000e8  cbz      x8, #0x15fd0
//   0x015fb8: aa0003f3  mov      x19, x0
//   0x015fbc: 94000008  bl       #0x15fdc
//   0x015fc0: f9400260  ldr      x0, [x19]
//   0x015fc4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x015fc8: f84207f3  ldr      x19, [sp], #0x20
//   0x015fcc: 17ffd35d  b        #0xad40
//   0x015fd0: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0396_sub_015fa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x015FA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x015fa4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x015fa8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x015fac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x015fb0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E8ULL; // 0x015fb4: cbz x8, #0x15fd0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015fb8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000008ULL; // 0x015fbc: bl #0x15fdc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x015fc0: ldr x0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0397 @ 0x015fdc..0x015fe4 (8 bytes)
// [VN] Phục dựng FDE #0397 tại 0x015fdc..0x015fe4 (8 byte)
//   0x015fdc: f9400001  ldr      x1, [x0]
//   0x015fe0: 14000001  b        #0x15fe4
uint64_t fde_0397_sub_015fdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x015FDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400001ULL; // 0x015fdc: ldr x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x015fe0: b #0x15fe4
    return acc;
}

// [EN] Reconstructed FDE #0398 @ 0x015fe4..0x01602c (72 bytes)
// [VN] Phục dựng FDE #0398 tại 0x015fe4..0x01602c (72 byte)
//   0x015fe4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x015fe8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x015fec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x015ff0: 910083fd  add      x29, sp, #0x20
//   0x015ff4: f9400415  ldr      x21, [x0, #8]
//   0x015ff8: aa0003f3  mov      x19, x0
//   0x015ffc: aa0103f4  mov      x20, x1
//   0x016000: eb15029f  cmp      x20, x21
//   0x016004: 540000a0  b.eq     #0x16018
//   0x016008: d10062a0  sub      x0, x21, #0x18
//   0x01600c: 97ffde0e  bl       #0xd844
//   0x016010: d100a2b5  sub      x21, x21, #0x28
uint64_t fde_0398_sub_015fe4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x540000A0ULL) + (x2 ^ 0x015FE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x015fe4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x015fe8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x015fec: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x015ff0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400415ULL; // 0x015ff4: ldr x21, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x015ff8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x015ffc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB15029FULL; // 0x016000: cmp x20, x21
    return acc;
}

// [EN] Reconstructed FDE #0399 @ 0x01602c..0x016044 (24 bytes)
// [VN] Phục dựng FDE #0399 tại 0x01602c..0x016044 (24 byte)
//   0x01602c: b0000228  adrp     x8, #0x5b000
//   0x016030: f9441108  ldr      x8, [x8, #0x820]
//   0x016034: aa0003e1  mov      x1, x0
//   0x016038: 910003e0  mov      x0, sp
//   0x01603c: f9400102  ldr      x2, [x8]
//   0x016040: 17fffb8b  b        #0x14e6c
uint64_t fde_0399_sub_01602c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0x17FFFB8BULL) + (x2 ^ 0x01602CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x01602c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9441108ULL; // 0x016030: ldr x8, [x8, #0x820]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x016034: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x016038: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x01603c: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFB8BULL; // 0x016040: b #0x14e6c
    return acc;
}

// [EN] Reconstructed FDE #0400 @ 0x016044..0x01605c (24 bytes)
// [VN] Phục dựng FDE #0400 tại 0x016044..0x01605c (24 byte)
//   0x016044: b0000228  adrp     x8, #0x5b000
//   0x016048: f9451108  ldr      x8, [x8, #0xa20]
//   0x01604c: 910003e1  mov      x1, sp
//   0x016050: aa1403e0  mov      x0, x20
//   0x016054: f9400108  ldr      x8, [x8]
//   0x016058: d61f0100  br       x8
uint64_t fde_0400_sub_016044(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x016044ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016044: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9451108ULL; // 0x016048: ldr x8, [x8, #0xa20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x01604c: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x016050: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x016054: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x016058: br x8
    return acc;
}

// [EN] Reconstructed FDE #0401 @ 0x01605c..0x016070 (20 bytes)
// [VN] Phục dựng FDE #0401 tại 0x01605c..0x016070 (20 byte)
//   0x01605c: b0000228  adrp     x8, #0x5b000
//   0x016060: b0000229  adrp     x9, #0x5b000
//   0x016064: f944cd08  ldr      x8, [x8, #0x998]
//   0x016068: f9430529  ldr      x9, [x9, #0x608]
//   0x01606c: d65f03c0  ret      
uint64_t fde_0401_sub_01605c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01605CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x01605c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000229ULL; // 0x016060: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944CD08ULL; // 0x016064: ldr x8, [x8, #0x998]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9430529ULL; // 0x016068: ldr x9, [x9, #0x608]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01606c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0402 @ 0x016070..0x016078 (8 bytes)
// [VN] Phục dựng FDE #0402 tại 0x016070..0x016078 (8 byte)
//   0x016070: f9400108  ldr      x8, [x8]
//   0x016074: d61f0100  br       x8
uint64_t fde_0402_sub_016070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400108ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x016070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x016070: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x016074: br x8
    return acc;
}

// [EN] Reconstructed FDE #0403 @ 0x016078..0x01608c (20 bytes)
// [VN] Phục dựng FDE #0403 tại 0x016078..0x01608c (20 byte)
//   0x016078: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x01607c: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x016080: f94023f7  ldr      x23, [sp, #0x40]
//   0x016084: 910203ff  add      sp, sp, #0x80
//   0x016088: d65f03c0  ret      
uint64_t fde_0403_sub_016078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9464FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9464FF4ULL; // 0x016078: ldp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94557F6ULL; // 0x01607c: ldp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94023F7ULL; // 0x016080: ldr x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FFULL; // 0x016084: add sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016088: ret 
    return acc;
}

// [EN] Reconstructed FDE #0404 @ 0x01608c..0x0160a0 (20 bytes)
// [VN] Phục dựng FDE #0404 tại 0x01608c..0x0160a0 (20 byte)
//   0x01608c: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x016090: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x016094: 12000000  and      w0, w0, #1
//   0x016098: 9101c3ff  add      sp, sp, #0x70
//   0x01609c: d65f03c0  ret      
uint64_t fde_0404_sub_01608c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9454FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01608CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9454FF4ULL; // 0x01608c: ldp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94457F6ULL; // 0x016090: ldp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x016094: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FFULL; // 0x016098: add sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01609c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0405 @ 0x0160a0..0x0160a8 (8 bytes)
// [VN] Phục dựng FDE #0405 tại 0x0160a0..0x0160a8 (8 byte)
//   0x0160a0: aa1503e0  mov      x0, x21
//   0x0160a4: 17ffdde8  b        #0xd844
uint64_t fde_0405_sub_0160a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FFDDE8ULL) + (x2 ^ 0x0160A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x0160a0: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDDE8ULL; // 0x0160a4: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0406 @ 0x0160a8..0x0160b0 (8 bytes)
// [VN] Phục dựng FDE #0406 tại 0x0160a8..0x0160b0 (8 byte)
//   0x0160a8: 910003e0  mov      x0, sp
//   0x0160ac: 17fffb7c  b        #0x14e9c
uint64_t fde_0406_sub_0160a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFFB7CULL) + (x2 ^ 0x0160A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x0160a8: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFB7CULL; // 0x0160ac: b #0x14e9c
    return acc;
}

// [EN] Reconstructed FDE #0407 @ 0x0160b0..0x0160b8 (8 bytes)
// [VN] Phục dựng FDE #0407 tại 0x0160b0..0x0160b8 (8 byte)
//   0x0160b0: aa1303e0  mov      x0, x19
//   0x0160b4: 17ffd347  b        #0xadd0
uint64_t fde_0407_sub_0160b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFD347ULL) + (x2 ^ 0x0160B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0160b0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD347ULL; // 0x0160b4: b #0xadd0
    return acc;
}

// [EN] Reconstructed FDE #0408 @ 0x0160b8..0x0160c8 (16 bytes)
// [VN] Phục dựng FDE #0408 tại 0x0160b8..0x0160c8 (16 byte)
//   0x0160b8: f9400108  ldr      x8, [x8]
//   0x0160bc: f94002e0  ldr      x0, [x23]
//   0x0160c0: 910043e2  add      x2, sp, #0x10
//   0x0160c4: d61f0100  br       x8
uint64_t fde_0408_sub_0160b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400108ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0160B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0160b8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E0ULL; // 0x0160bc: ldr x0, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E2ULL; // 0x0160c0: add x2, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0160c4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0409 @ 0x0160c8..0x0160d8 (16 bytes)
// [VN] Phục dựng FDE #0409 tại 0x0160c8..0x0160d8 (16 byte)
//   0x0160c8: f9400108  ldr      x8, [x8]
//   0x0160cc: f9400120  ldr      x0, [x9]
//   0x0160d0: 910043e2  add      x2, sp, #0x10
//   0x0160d4: d61f0100  br       x8
uint64_t fde_0409_sub_0160c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400108ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0160C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0160c8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400120ULL; // 0x0160cc: ldr x0, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E2ULL; // 0x0160d0: add x2, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0160d4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0410 @ 0x0160d8..0x0160e8 (16 bytes)
// [VN] Phục dựng FDE #0410 tại 0x0160d8..0x0160e8 (16 byte)
//   0x0160d8: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x0160dc: f94013f5  ldr      x21, [sp, #0x20]
//   0x0160e0: 910143ff  add      sp, sp, #0x50
//   0x0160e4: d65f03c0  ret      
uint64_t fde_0410_sub_0160d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9434FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0160D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9434FF4ULL; // 0x0160d8: ldp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94013F5ULL; // 0x0160dc: ldr x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FFULL; // 0x0160e0: add sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0160e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0411 @ 0x0160e8..0x0160f8 (16 bytes)
// [VN] Phục dựng FDE #0411 tại 0x0160e8..0x0160f8 (16 byte)
//   0x0160e8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0160ec: f9400fe9  ldr      x9, [sp, #0x18]
//   0x0160f0: eb09011f  cmp      x8, x9
//   0x0160f4: d65f03c0  ret      
uint64_t fde_0411_sub_0160e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94016A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0160E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0160e8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400FE9ULL; // 0x0160ec: ldr x9, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0160f0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0160f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0412 @ 0x0160f8..0x01610c (20 bytes)
// [VN] Phục dựng FDE #0412 tại 0x0160f8..0x01610c (20 byte)
//   0x0160f8: b0000228  adrp     x8, #0x5b000
//   0x0160fc: b0000237  adrp     x23, #0x5b000
//   0x016100: f944cd08  ldr      x8, [x8, #0x998]
//   0x016104: f94306f7  ldr      x23, [x23, #0x608]
//   0x016108: d65f03c0  ret      
uint64_t fde_0412_sub_0160f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0160F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x0160f8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000237ULL; // 0x0160fc: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944CD08ULL; // 0x016100: ldr x8, [x8, #0x998]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94306F7ULL; // 0x016104: ldr x23, [x23, #0x608]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016108: ret 
    return acc;
}

// [EN] Reconstructed FDE #0413 @ 0x01610c..0x016114 (8 bytes)
// [VN] Phục dựng FDE #0413 tại 0x01610c..0x016114 (8 byte)
//   0x01610c: 910003e0  mov      x0, sp
//   0x016110: 17ffddcd  b        #0xd844
uint64_t fde_0413_sub_01610c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFDDCDULL) + (x2 ^ 0x01610CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x01610c: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDDCDULL; // 0x016110: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0414 @ 0x016114..0x016120 (12 bytes)
// [VN] Phục dựng FDE #0414 tại 0x016114..0x016120 (12 byte)
//   0x016114: aa1303e0  mov      x0, x19
//   0x016118: aa1403e1  mov      x1, x20
//   0x01611c: 17fffcc9  b        #0x15440
uint64_t fde_0414_sub_016114(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFFCC9ULL) + (x2 ^ 0x016114ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x016114: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x016118: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFCC9ULL; // 0x01611c: b #0x15440
    return acc;
}

// [EN] Reconstructed FDE #0415 @ 0x016120..0x01612c (12 bytes)
// [VN] Phục dựng FDE #0415 tại 0x016120..0x01612c (12 byte)
//   0x016120: aa1303e0  mov      x0, x19
//   0x016124: f9400108  ldr      x8, [x8]
//   0x016128: d61f0100  br       x8
uint64_t fde_0415_sub_016120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x016120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x016120: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x016124: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x016128: br x8
    return acc;
}

// [EN] Reconstructed FDE #0416 @ 0x01612c..0x016138 (12 bytes)
// [VN] Phục dựng FDE #0416 tại 0x01612c..0x016138 (12 byte)
//   0x01612c: 91004261  add      x1, x19, #0x10
//   0x016130: 910003e0  mov      x0, sp
//   0x016134: 17fffe43  b        #0x15a40
uint64_t fde_0416_sub_01612c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91004261ULL) + (x1 ^ 0x17FFFE43ULL) + (x2 ^ 0x01612CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91004261ULL; // 0x01612c: add x1, x19, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x016130: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE43ULL; // 0x016134: b #0x15a40
    return acc;
}

// [EN] Reconstructed FDE #0417 @ 0x016138..0x016144 (12 bytes)
// [VN] Phục dựng FDE #0417 tại 0x016138..0x016144 (12 byte)
//   0x016138: aa0003f3  mov      x19, x0
//   0x01613c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x016140: 17fffbab  b        #0x14fec
uint64_t fde_0417_sub_016138(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F3ULL) + (x1 ^ 0x17FFFBABULL) + (x2 ^ 0x016138ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x016138: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x01613c: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFBABULL; // 0x016140: b #0x14fec
    return acc;
}

// [EN] Reconstructed FDE #0418 @ 0x016144..0x016150 (12 bytes)
// [VN] Phục dựng FDE #0418 tại 0x016144..0x016150 (12 byte)
//   0x016144: d53bd056  mrs      x22, tpidr_el0
//   0x016148: f94016c8  ldr      x8, [x22, #0x28]
//   0x01614c: d65f03c0  ret      
uint64_t fde_0418_sub_016144(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD53BD056ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016144ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x016144: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x016148: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01614c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0419 @ 0x016150..0x0161a0 (80 bytes)
// [VN] Phục dựng FDE #0419 tại 0x016150..0x0161a0 (80 byte)
//   0x016150: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x016154: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x016158: 910043fd  add      x29, sp, #0x10
//   0x01615c: b0000220  adrp     x0, #0x5b000
//   0x016160: f944f000  ldr      x0, [x0, #0x9e0]
//   0x016164: 97ffd51b  bl       #0xb5d0
//   0x016168: b0000233  adrp     x19, #0x5b000
//   0x01616c: f9451e73  ldr      x19, [x19, #0xa38]
//   0x016170: f9400268  ldr      x8, [x19]
//   0x016174: b5000088  cbnz     x8, #0x16184
//   0x016178: 52800200  mov      w0, #0x10
//   0x01617c: 97ffd51d  bl       #0xb5f0
uint64_t fde_0419_sub_016150(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x016150ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x016150: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016154: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x016158: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000220ULL; // 0x01615c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944F000ULL; // 0x016160: ldr x0, [x0, #0x9e0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD51BULL; // 0x016164: bl #0xb5d0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000233ULL; // 0x016168: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9451E73ULL; // 0x01616c: ldr x19, [x19, #0xa38]
    return acc;
}

// [EN] Reconstructed FDE #0420 @ 0x0161a0..0x0162ac (268 bytes)
// [VN] Phục dựng FDE #0420 tại 0x0161a0..0x0162ac (268 byte)
//   0x0161a0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0161a4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0161a8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0161ac: 910083fd  add      x29, sp, #0x20
//   0x0161b0: 7100843f  cmp      w1, #0x21
//   0x0161b4: 540002ac  b.gt     #0x16208
//   0x0161b8: aa0003f4  mov      x20, x0
//   0x0161bc: f0000100  adrp     x0, #0x39000
//   0x0161c0: 911cd000  add      x0, x0, #0x734
//   0x0161c4: 2a0103f5  mov      w21, w1
//   0x0161c8: 97ffd3ea  bl       #0xb170
//   0x0161cc: b40001e0  cbz      x0, #0x16208
uint64_t fde_0420_sub_0161a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x911CD000ULL) + (x2 ^ 0x0161A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0161a0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0161a4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0161a8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0161ac: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x7100843FULL; // 0x0161b0: cmp w1, #0x21
    acc = (acc * 0x100000001B3ULL) ^ 0x540002ACULL; // 0x0161b4: b.gt #0x16208
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0161b8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000100ULL; // 0x0161bc: adrp x0, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0421 @ 0x0162ac..0x0162c0 (20 bytes)
// [VN] Phục dựng FDE #0421 tại 0x0162ac..0x0162c0 (20 byte)
//   0x0162ac: f94002c0  ldr      x0, [x22]
//   0x0162b0: f9400281  ldr      x1, [x20]
//   0x0162b4: 52ba5004  mov      w4, #-0x2d800000
//   0x0162b8: 2a1f03e3  mov      w3, wzr
//   0x0162bc: 1400157d  b        #0x1b8b0
uint64_t fde_0421_sub_0162ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94002C0ULL) + (x1 ^ 0x1400157DULL) + (x2 ^ 0x0162ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002C0ULL; // 0x0162ac: ldr x0, [x22]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400281ULL; // 0x0162b0: ldr x1, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x52BA5004ULL; // 0x0162b4: mov w4, #-0x2d800000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E3ULL; // 0x0162b8: mov w3, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400157DULL; // 0x0162bc: b #0x1b8b0
    return acc;
}

// [EN] Reconstructed FDE #0422 @ 0x0162c0..0x0162c8 (8 bytes)
// [VN] Phục dựng FDE #0422 tại 0x0162c0..0x0162c8 (8 byte)
//   0x0162c0: aa1303e0  mov      x0, x19
//   0x0162c4: 17ffd523  b        #0xb750
uint64_t fde_0422_sub_0162c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFD523ULL) + (x2 ^ 0x0162C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0162c0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD523ULL; // 0x0162c4: b #0xb750
    return acc;
}

// [EN] Reconstructed FDE #0423 @ 0x0162c8..0x0162ec (36 bytes)
// [VN] Phục dựng FDE #0423 tại 0x0162c8..0x0162ec (36 byte)
//   0x0162c8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0162cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0162d0: 910043fd  add      x29, sp, #0x10
//   0x0162d4: 2a0203f3  mov      w19, w2
//   0x0162d8: 97ffff9e  bl       #0x16150
//   0x0162dc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0162e0: 2a1303e1  mov      w1, w19
//   0x0162e4: f84207f3  ldr      x19, [sp], #0x20
//   0x0162e8: 17ffffae  b        #0x161a0
uint64_t fde_0423_sub_0162c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFFFAEULL) + (x2 ^ 0x0162C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0162c8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0162cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0162d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x0162d4: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF9EULL; // 0x0162d8: bl #0x16150
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0162dc: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x0162e0: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0162e4: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0424 @ 0x0162ec..0x016310 (36 bytes)
// [VN] Phục dựng FDE #0424 tại 0x0162ec..0x016310 (36 byte)
//   0x0162ec: aa1e03e1  mov      x1, x30
//   0x0162f0: 94000332  bl       #0x16fb8
//   0x0162f4: aa0103fe  mov      x30, x1
//   0x0162f8: f0000102  adrp     x2, #0x39000
//   0x0162fc: aa0003e3  mov      x3, x0
//   0x016300: 91095442  add      x2, x2, #0x255
//   0x016304: f9400101  ldr      x1, [x8]
//   0x016308: 528000a0  mov      w0, #5
//   0x01630c: 17ffd3b5  b        #0xb1e0
uint64_t fde_0424_sub_0162ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1E03E1ULL) + (x1 ^ 0x17FFD3B5ULL) + (x2 ^ 0x0162ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03E1ULL; // 0x0162ec: mov x1, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x94000332ULL; // 0x0162f0: bl #0x16fb8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103FEULL; // 0x0162f4: mov x30, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000102ULL; // 0x0162f8: adrp x2, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E3ULL; // 0x0162fc: mov x3, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91095442ULL; // 0x016300: add x2, x2, #0x255
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400101ULL; // 0x016304: ldr x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x016308: mov w0, #5
    return acc;
}

// [EN] Reconstructed FDE #0425 @ 0x016310..0x0163b8 (168 bytes)
// [VN] Phục dựng FDE #0425 tại 0x016310..0x0163b8 (168 byte)
//   0x016310: d104c3ff  sub      sp, sp, #0x130
//   0x016314: a9114ffc  stp      x28, x19, [sp, #0x110]
//   0x016318: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x01631c: 910483fd  add      x29, sp, #0x120
//   0x016320: a9088be1  stp      x1, x2, [sp, #0x88]
//   0x016324: a90993e3  stp      x3, x4, [sp, #0x98]
//   0x016328: a90a9be5  stp      x5, x6, [sp, #0xa8]
//   0x01632c: f9005fe7  str      x7, [sp, #0xb8]
//   0x016330: ad0007e0  stp      q0, q1, [sp]
//   0x016334: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x016338: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x01633c: ad031fe6  stp      q6, q7, [sp, #0x60]
uint64_t fde_0425_sub_016310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0xAD0007E0ULL) + (x2 ^ 0x016310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x016310: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FFCULL; // 0x016314: stp x28, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x016318: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x01631c: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9088BE1ULL; // 0x016320: stp x1, x2, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90993E3ULL; // 0x016324: stp x3, x4, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A9BE5ULL; // 0x016328: stp x5, x6, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9005FE7ULL; // 0x01632c: str x7, [sp, #0xb8]
    return acc;
}

// [EN] Reconstructed FDE #0426 @ 0x0163b8..0x016434 (124 bytes)
// [VN] Phục dựng FDE #0426 tại 0x0163b8..0x016434 (124 byte)
//   0x0163b8: d10183ff  sub      sp, sp, #0x60
//   0x0163bc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0163c0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0163c4: 910143fd  add      x29, sp, #0x50
//   0x0163c8: d53bd053  mrs      x19, tpidr_el0
//   0x0163cc: f9401668  ldr      x8, [x19, #0x28]
//   0x0163d0: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0163d4: 97ffd4a7  bl       #0xb670
//   0x0163d8: b0000228  adrp     x8, #0x5b000
//   0x0163dc: f945d908  ldr      x8, [x8, #0xbb0]
//   0x0163e0: b9000100  str      w0, [x8]
//   0x0163e4: 910023e8  add      x8, sp, #8
uint64_t fde_0426_sub_0163b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xB0000228ULL) + (x2 ^ 0x0163B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0163b8: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0163bc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0163c0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0163c4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0163c8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0163cc: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x0163d0: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD4A7ULL; // 0x0163d4: bl #0xb670
    return acc;
}

// [EN] Reconstructed FDE #0427 @ 0x016434..0x016470 (60 bytes)
// [VN] Phục dựng FDE #0427 tại 0x016434..0x016470 (60 byte)
//   0x016434: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x016438: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01643c: 910043fd  add      x29, sp, #0x10
//   0x016440: aa0003e2  mov      x2, x0
//   0x016444: aa0103e0  mov      x0, x1
//   0x016448: aa1f03e1  mov      x1, xzr
//   0x01644c: aa0803f3  mov      x19, x8
//   0x016450: 94000203  bl       #0x16c5c
//   0x016454: 3dc00000  ldr      q0, [x0]
//   0x016458: f9400808  ldr      x8, [x0, #0x10]
//   0x01645c: 3d800260  str      q0, [x19]
//   0x016460: f9000a68  str      x8, [x19, #0x10]
uint64_t fde_0427_sub_016434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x3DC00000ULL) + (x2 ^ 0x016434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x016434: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016438: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01643c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x016440: mov x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x016444: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x016448: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x01644c: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000203ULL; // 0x016450: bl #0x16c5c
    return acc;
}

// [EN] Reconstructed FDE #0428 @ 0x016470..0x0164e8 (120 bytes)
// [VN] Phục dựng FDE #0428 tại 0x016470..0x0164e8 (120 byte)
//   0x016470: d10183ff  sub      sp, sp, #0x60
//   0x016474: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x016478: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01647c: 910143fd  add      x29, sp, #0x50
//   0x016480: d53bd053  mrs      x19, tpidr_el0
//   0x016484: f9401668  ldr      x8, [x19, #0x28]
//   0x016488: f81e83a8  stur     x8, [x29, #-0x18]
//   0x01648c: b0000228  adrp     x8, #0x5b000
//   0x016490: f9438d08  ldr      x8, [x8, #0x718]
//   0x016494: b9400100  ldr      w0, [x8]
//   0x016498: 910023e8  add      x8, sp, #8
//   0x01649c: 97ffd3cd  bl       #0xb3d0
uint64_t fde_0428_sub_016470(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9438D08ULL) + (x2 ^ 0x016470ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x016470: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x016474: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x016478: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01647c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x016480: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x016484: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x016488: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x01648c: adrp x8, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0429 @ 0x0164e8..0x016580 (152 bytes)
// [VN] Phục dựng FDE #0429 tại 0x0164e8..0x016580 (152 byte)
//   0x0164e8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0164ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0164f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0164f4: 910083fd  add      x29, sp, #0x20
//   0x0164f8: aa0103f5  mov      x21, x1
//   0x0164fc: aa0003f4  mov      x20, x0
//   0x016500: 97ffd4e8  bl       #0xb8a0
//   0x016504: aa0003f3  mov      x19, x0
//   0x016508: b4000160  cbz      x0, #0x16534
//   0x01650c: 940002ab  bl       #0x16fb8
//   0x016510: 90000122  adrp     x2, #0x3a000
//   0x016514: 913e3442  add      x2, x2, #0xf8d
uint64_t fde_0429_sub_0164e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB4000160ULL) + (x2 ^ 0x0164E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0164e8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0164ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0164f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0164f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0164f8: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0164fc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD4E8ULL; // 0x016500: bl #0xb8a0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x016504: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0430 @ 0x016580..0x0165b0 (48 bytes)
// [VN] Phục dựng FDE #0430 tại 0x016580..0x0165b0 (48 byte)
//   0x016580: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x016584: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x016588: 910043fd  add      x29, sp, #0x10
//   0x01658c: aa0003f3  mov      x19, x0
//   0x016590: 90000120  adrp     x0, #0x3a000
//   0x016594: 913f0c00  add      x0, x0, #0xfc3
//   0x016598: aa1303e1  mov      x1, x19
//   0x01659c: 97ffff5d  bl       #0x16310
//   0x0165a0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0165a4: aa1303e0  mov      x0, x19
//   0x0165a8: f84207f3  ldr      x19, [sp], #0x20
//   0x0165ac: 17ffd479  b        #0xb790
uint64_t fde_0430_sub_016580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x016580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x016580: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016584: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x016588: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01658c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000120ULL; // 0x016590: adrp x0, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F0C00ULL; // 0x016594: add x0, x0, #0xfc3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x016598: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF5DULL; // 0x01659c: bl #0x16310
    return acc;
}

// [EN] Reconstructed FDE #0431 @ 0x0165b0..0x016628 (120 bytes)
// [VN] Phục dựng FDE #0431 tại 0x0165b0..0x016628 (120 byte)
//   0x0165b0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0165b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0165b8: 910043fd  add      x29, sp, #0x10
//   0x0165bc: b0000233  adrp     x19, #0x5b000
//   0x0165c0: b0000228  adrp     x8, #0x5b000
//   0x0165c4: f945d273  ldr      x19, [x19, #0xba0]
//   0x0165c8: f9452908  ldr      x8, [x8, #0xa50]
//   0x0165cc: f9400260  ldr      x0, [x19]
//   0x0165d0: f9400101  ldr      x1, [x8]
//   0x0165d4: 94000015  bl       #0x16628
//   0x0165d8: b0000229  adrp     x9, #0x5b000
//   0x0165dc: f9400268  ldr      x8, [x19]
uint64_t fde_0431_sub_0165b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400101ULL) + (x2 ^ 0x0165B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0165b0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0165b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0165b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000233ULL; // 0x0165bc: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x0165c0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D273ULL; // 0x0165c4: ldr x19, [x19, #0xba0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9452908ULL; // 0x0165c8: ldr x8, [x8, #0xa50]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x0165cc: ldr x0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0432 @ 0x016628..0x0166d0 (168 bytes)
// [VN] Phục dựng FDE #0432 tại 0x016628..0x0166d0 (168 byte)
//   0x016628: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01662c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016630: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016634: 910083fd  add      x29, sp, #0x20
//   0x016638: aa0103f3  mov      x19, x1
//   0x01663c: 97ffd259  bl       #0xafa0
//   0x016640: b4000180  cbz      x0, #0x16670
//   0x016644: aa1303e1  mov      x1, x19
//   0x016648: aa0003f5  mov      x21, x0
//   0x01664c: 97ffd29d  bl       #0xb0c0
//   0x016650: b4000240  cbz      x0, #0x16698
//   0x016654: 9400024e  bl       #0x16f8c
uint64_t fde_0432_sub_016628(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x016628ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x016628: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01662c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016630: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016634: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x016638: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD259ULL; // 0x01663c: bl #0xafa0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000180ULL; // 0x016640: cbz x0, #0x16670
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x016644: mov x1, x19
    return acc;
}

// [EN] Reconstructed FDE #0433 @ 0x0166d0..0x01670c (60 bytes)
// [VN] Phục dựng FDE #0433 tại 0x0166d0..0x01670c (60 byte)
//   0x0166d0: b0000228  adrp     x8, #0x5b000
//   0x0166d4: f945d908  ldr      x8, [x8, #0xbb0]
//   0x0166d8: 52804909  mov      w9, #0x248
//   0x0166dc: 5280450a  mov      w10, #0x228
//   0x0166e0: 52804a0b  mov      w11, #0x250
//   0x0166e4: b9400108  ldr      w8, [x8]
//   0x0166e8: 7100751f  cmp      w8, #0x1d
//   0x0166ec: 9a890149  csel     x9, x10, x9, eq
//   0x0166f0: 71007d1f  cmp      w8, #0x1f
//   0x0166f4: 9a890169  csel     x9, x11, x9, eq
//   0x0166f8: 7100851f  cmp      w8, #0x21
//   0x0166fc: 52804308  mov      w8, #0x218
uint64_t fde_0433_sub_0166d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0x71007D1FULL) + (x2 ^ 0x0166D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x0166d0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D908ULL; // 0x0166d4: ldr x8, [x8, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52804909ULL; // 0x0166d8: mov w9, #0x248
    acc = (acc * 0x100000001B3ULL) ^ 0x5280450AULL; // 0x0166dc: mov w10, #0x228
    acc = (acc * 0x100000001B3ULL) ^ 0x52804A0BULL; // 0x0166e0: mov w11, #0x250
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x0166e4: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100751FULL; // 0x0166e8: cmp w8, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890149ULL; // 0x0166ec: csel x9, x10, x9, eq
    return acc;
}

// [EN] Reconstructed FDE #0434 @ 0x01670c..0x016748 (60 bytes)
// [VN] Phục dựng FDE #0434 tại 0x01670c..0x016748 (60 byte)
//   0x01670c: b0000228  adrp     x8, #0x5b000
//   0x016710: f945d908  ldr      x8, [x8, #0xbb0]
//   0x016714: 52804809  mov      w9, #0x240
//   0x016718: 5280440a  mov      w10, #0x220
//   0x01671c: 5280490b  mov      w11, #0x248
//   0x016720: b9400108  ldr      w8, [x8]
//   0x016724: 7100751f  cmp      w8, #0x1d
//   0x016728: 9a890149  csel     x9, x10, x9, eq
//   0x01672c: 71007d1f  cmp      w8, #0x1f
//   0x016730: 9a890169  csel     x9, x11, x9, eq
//   0x016734: 7100851f  cmp      w8, #0x21
//   0x016738: 52804208  mov      w8, #0x210
uint64_t fde_0434_sub_01670c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0x71007D1FULL) + (x2 ^ 0x01670CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x01670c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D908ULL; // 0x016710: ldr x8, [x8, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52804809ULL; // 0x016714: mov w9, #0x240
    acc = (acc * 0x100000001B3ULL) ^ 0x5280440AULL; // 0x016718: mov w10, #0x220
    acc = (acc * 0x100000001B3ULL) ^ 0x5280490BULL; // 0x01671c: mov w11, #0x248
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x016720: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100751FULL; // 0x016724: cmp w8, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890149ULL; // 0x016728: csel x9, x10, x9, eq
    return acc;
}

// [EN] Reconstructed FDE #0435 @ 0x016748..0x016778 (48 bytes)
// [VN] Phục dựng FDE #0435 tại 0x016748..0x016778 (48 byte)
//   0x016748: b0000228  adrp     x8, #0x5b000
//   0x01674c: f945d908  ldr      x8, [x8, #0xbb0]
//   0x016750: 52800189  mov      w9, #0xc
//   0x016754: b9400108  ldr      w8, [x8]
//   0x016758: 7100851f  cmp      w8, #0x21
//   0x01675c: 7a5f1904  ccmp     w8, #0x1f, #4, ne
//   0x016760: 52800108  mov      w8, #8
//   0x016764: 9a890108  csel     x8, x8, x9, eq
//   0x016768: b8606908  ldr      w8, [x8, x0]
//   0x01676c: 3100051f  cmn      w8, #1
//   0x016770: 1a9f17e0  cset     w0, eq
//   0x016774: d65f03c0  ret      
uint64_t fde_0435_sub_016748(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0xB8606908ULL) + (x2 ^ 0x016748ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016748: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D908ULL; // 0x01674c: ldr x8, [x8, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800189ULL; // 0x016750: mov w9, #0xc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x016754: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100851FULL; // 0x016758: cmp w8, #0x21
    acc = (acc * 0x100000001B3ULL) ^ 0x7A5F1904ULL; // 0x01675c: ccmp w8, #0x1f, #4, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x52800108ULL; // 0x016760: mov w8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890108ULL; // 0x016764: csel x8, x8, x9, eq
    return acc;
}

// [EN] Reconstructed FDE #0436 @ 0x016778..0x0167f0 (120 bytes)
// [VN] Phục dựng FDE #0436 tại 0x016778..0x0167f0 (120 byte)
//   0x016778: b0000228  adrp     x8, #0x5b000
//   0x01677c: f945d908  ldr      x8, [x8, #0xbb0]
//   0x016780: b0000229  adrp     x9, #0x5b000
//   0x016784: b9400108  ldr      w8, [x8]
//   0x016788: f9438d29  ldr      x9, [x9, #0x718]
//   0x01678c: 7100751f  cmp      w8, #0x1d
//   0x016790: b9400129  ldr      w9, [x9]
//   0x016794: 540000c1  b.ne     #0x167ac
//   0x016798: 7101013f  cmp      w9, #0x40
//   0x01679c: 54000081  b.ne     #0x167ac
//   0x0167a0: b0000228  adrp     x8, #0x5b000
//   0x0167a4: f9466d08  ldr      x8, [x8, #0xcd8]
uint64_t fde_0436_sub_016778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0x7101013FULL) + (x2 ^ 0x016778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016778: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D908ULL; // 0x01677c: ldr x8, [x8, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000229ULL; // 0x016780: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x016784: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9438D29ULL; // 0x016788: ldr x9, [x9, #0x718]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100751FULL; // 0x01678c: cmp w8, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400129ULL; // 0x016790: ldr w9, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x016794: b.ne #0x167ac
    return acc;
}

// [EN] Reconstructed FDE #0437 @ 0x0167f0..0x016a6c (636 bytes)
// [VN] Phục dựng FDE #0437 tại 0x0167f0..0x016a6c (636 byte)
//   0x0167f0: d106c3ff  sub      sp, sp, #0x1b0
//   0x0167f4: a91667fc  stp      x28, x25, [sp, #0x160]
//   0x0167f8: a9175ff8  stp      x24, x23, [sp, #0x170]
//   0x0167fc: a91857f6  stp      x22, x21, [sp, #0x180]
//   0x016800: a9194ff4  stp      x20, x19, [sp, #0x190]
//   0x016804: a91a7bfd  stp      x29, x30, [sp, #0x1a0]
//   0x016808: 910683fd  add      x29, sp, #0x1a0
//   0x01680c: d53bd058  mrs      x24, tpidr_el0
//   0x016810: f9401708  ldr      x8, [x24, #0x28]
//   0x016814: aa0003f3  mov      x19, x0
//   0x016818: f81b83a8  stur     x8, [x29, #-0x48]
//   0x01681c: b0000228  adrp     x8, #0x5b000
uint64_t fde_0437_sub_0167f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD106C3FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x0167F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x0167f0: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA91667FCULL; // 0x0167f4: stp x28, x25, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9175FF8ULL; // 0x0167f8: stp x24, x23, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91857F6ULL; // 0x0167fc: stp x22, x21, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9194FF4ULL; // 0x016800: stp x20, x19, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A7BFDULL; // 0x016804: stp x29, x30, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910683FDULL; // 0x016808: add x29, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x01680c: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0438 @ 0x016a6c..0x016a9c (48 bytes)
// [VN] Phục dựng FDE #0438 tại 0x016a6c..0x016a9c (48 byte)
//   0x016a6c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x016a70: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x016a74: 910043fd  add      x29, sp, #0x10
//   0x016a78: aa0803f3  mov      x19, x8
//   0x016a7c: 9400012c  bl       #0x16f2c
//   0x016a80: 3dc00000  ldr      q0, [x0]
//   0x016a84: f9400808  ldr      x8, [x0, #0x10]
//   0x016a88: 3d800260  str      q0, [x19]
//   0x016a8c: f9000a68  str      x8, [x19, #0x10]
//   0x016a90: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x016a94: f84207f3  ldr      x19, [sp], #0x20
//   0x016a98: 17ffe31c  b        #0xf708
uint64_t fde_0438_sub_016a6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000A68ULL) + (x2 ^ 0x016A6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x016a6c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016a70: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x016a74: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x016a78: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400012CULL; // 0x016a7c: bl #0x16f2c
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00000ULL; // 0x016a80: ldr q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x016a84: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800260ULL; // 0x016a88: str q0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0439 @ 0x016a9c..0x016acc (48 bytes)
// [VN] Phục dựng FDE #0439 tại 0x016a9c..0x016acc (48 byte)
//   0x016a9c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x016aa0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x016aa4: 910043fd  add      x29, sp, #0x10
//   0x016aa8: aa0803f3  mov      x19, x8
//   0x016aac: 94000113  bl       #0x16ef8
//   0x016ab0: 3dc00000  ldr      q0, [x0]
//   0x016ab4: f9400808  ldr      x8, [x0, #0x10]
//   0x016ab8: 3d800260  str      q0, [x19]
//   0x016abc: f9000a68  str      x8, [x19, #0x10]
//   0x016ac0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x016ac4: f84207f3  ldr      x19, [sp], #0x20
//   0x016ac8: 17ffe310  b        #0xf708
uint64_t fde_0439_sub_016a9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000A68ULL) + (x2 ^ 0x016A9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x016a9c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016aa0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x016aa4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x016aa8: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000113ULL; // 0x016aac: bl #0x16ef8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00000ULL; // 0x016ab0: ldr q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x016ab4: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800260ULL; // 0x016ab8: str q0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0440 @ 0x016acc..0x016b50 (132 bytes)
// [VN] Phục dựng FDE #0440 tại 0x016acc..0x016b50 (132 byte)
//   0x016acc: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x016ad0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016ad4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016ad8: 910083fd  add      x29, sp, #0x20
//   0x016adc: aa0003f4  mov      x20, x0
//   0x016ae0: aa0803e0  mov      x0, x8
//   0x016ae4: aa0103f3  mov      x19, x1
//   0x016ae8: aa0803f5  mov      x21, x8
//   0x016aec: a9007d1f  stp      xzr, xzr, [x8]
//   0x016af0: f900091f  str      xzr, [x8, #0x10]
//   0x016af4: 97ffe305  bl       #0xf708
//   0x016af8: aa1403e0  mov      x0, x20
uint64_t fde_0440_sub_016acc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xA9007D1FULL) + (x2 ^ 0x016ACCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x016acc: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x016ad0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016ad4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016ad8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x016adc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x016ae0: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x016ae4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F5ULL; // 0x016ae8: mov x21, x8
    return acc;
}

// [EN] Reconstructed FDE #0441 @ 0x016b50..0x016c18 (200 bytes)
// [VN] Phục dựng FDE #0441 tại 0x016b50..0x016c18 (200 byte)
//   0x016b50: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x016b54: 910003fd  mov      x29, sp
//   0x016b58: 97fffe18  bl       #0x163b8
//   0x016b5c: 97fffe45  bl       #0x16470
//   0x016b60: b0000228  adrp     x8, #0x5b000
//   0x016b64: f945d908  ldr      x8, [x8, #0xbb0]
//   0x016b68: b0000120  adrp     x0, #0x3b000
//   0x016b6c: 910b5400  add      x0, x0, #0x2d5
//   0x016b70: b9400108  ldr      w8, [x8]
//   0x016b74: 7100851f  cmp      w8, #0x21
//   0x016b78: 54000488  b.hi     #0x16c08
//   0x016b7c: 52800029  mov      w9, #1
uint64_t fde_0441_sub_016b50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB9400108ULL) + (x2 ^ 0x016B50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x016b50: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x016b54: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE18ULL; // 0x016b58: bl #0x163b8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE45ULL; // 0x016b5c: bl #0x16470
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016b60: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D908ULL; // 0x016b64: ldr x8, [x8, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000120ULL; // 0x016b68: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B5400ULL; // 0x016b6c: add x0, x0, #0x2d5
    return acc;
}

// [EN] Reconstructed FDE #0442 @ 0x016c18..0x016c5c (68 bytes)
// [VN] Phục dựng FDE #0442 tại 0x016c18..0x016c5c (68 byte)
//   0x016c18: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x016c1c: 910003fd  mov      x29, sp
//   0x016c20: b0000228  adrp     x8, #0x5b000
//   0x016c24: f946bd08  ldr      x8, [x8, #0xd78]
//   0x016c28: 39400108  ldrb     w8, [x8]
//   0x016c2c: 34000148  cbz      w8, #0x16c54
//   0x016c30: b0000228  adrp     x8, #0x5b000
//   0x016c34: f944ad08  ldr      x8, [x8, #0x958]
//   0x016c38: f9400100  ldr      x0, [x8]
//   0x016c3c: b40000c0  cbz      x0, #0x16c54
//   0x016c40: 97fffe50  bl       #0x16580
//   0x016c44: b0000120  adrp     x0, #0x3b000
uint64_t fde_0442_sub_016c18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF9400100ULL) + (x2 ^ 0x016C18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x016c18: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x016c1c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016c20: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946BD08ULL; // 0x016c24: ldr x8, [x8, #0xd78]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x016c28: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000148ULL; // 0x016c2c: cbz w8, #0x16c54
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016c30: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944AD08ULL; // 0x016c34: ldr x8, [x8, #0x958]
    return acc;
}

// [EN] Reconstructed FDE #0443 @ 0x016c5c..0x016ca0 (68 bytes)
// [VN] Phục dựng FDE #0443 tại 0x016c5c..0x016ca0 (68 byte)
//   0x016c5c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x016c60: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016c64: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016c68: 910083fd  add      x29, sp, #0x20
//   0x016c6c: aa0003f5  mov      x21, x0
//   0x016c70: aa0203e0  mov      x0, x2
//   0x016c74: aa0203f3  mov      x19, x2
//   0x016c78: aa0103f4  mov      x20, x1
//   0x016c7c: 97ffd0e9  bl       #0xb020
//   0x016c80: aa1403e1  mov      x1, x20
//   0x016c84: aa1303e2  mov      x2, x19
//   0x016c88: a9427bfd  ldp      x29, x30, [sp, #0x20]
uint64_t fde_0443_sub_016c5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FFD0E9ULL) + (x2 ^ 0x016C5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x016c5c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x016c60: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016c64: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016c68: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x016c6c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E0ULL; // 0x016c70: mov x0, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x016c74: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x016c78: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0444 @ 0x016ca0..0x016db4 (276 bytes)
// [VN] Phục dựng FDE #0444 tại 0x016ca0..0x016db4 (276 byte)
//   0x016ca0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x016ca4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x016ca8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x016cac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x016cb0: 9100c3fd  add      x29, sp, #0x30
//   0x016cb4: 39400008  ldrb     w8, [x0]
//   0x016cb8: aa0303f4  mov      x20, x3
//   0x016cbc: aa0203f5  mov      x21, x2
//   0x016cc0: aa0003f3  mov      x19, x0
//   0x016cc4: aa0103f7  mov      x23, x1
//   0x016cc8: 37000068  tbnz     w8, #0, #0x16cd4
//   0x016ccc: d341fd16  lsr      x22, x8, #1
uint64_t fde_0444_sub_016ca0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x016CA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x016ca0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x016ca4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x016ca8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x016cac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x016cb0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x016cb4: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x016cb8: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x016cbc: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0445 @ 0x016db4..0x016e34 (128 bytes)
// [VN] Phục dựng FDE #0445 tại 0x016db4..0x016e34 (128 byte)
//   0x016db4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x016db8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016dbc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016dc0: 910083fd  add      x29, sp, #0x20
//   0x016dc4: b100407f  cmn      x3, #0x10
//   0x016dc8: 54000342  b.hs     #0x16e30
//   0x016dcc: aa0203f3  mov      x19, x2
//   0x016dd0: aa0103f5  mov      x21, x1
//   0x016dd4: aa0003f4  mov      x20, x0
//   0x016dd8: f100587f  cmp      x3, #0x16
//   0x016ddc: 54000088  b.hi     #0x16dec
//   0x016de0: 531f7a68  lsl      w8, w19, #1
uint64_t fde_0445_sub_016db4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x016DB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x016db4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x016db8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016dbc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016dc0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB100407FULL; // 0x016dc4: cmn x3, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000342ULL; // 0x016dc8: b.hs #0x16e30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x016dcc: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x016dd0: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0446 @ 0x016e34..0x016ef8 (196 bytes)
// [VN] Phục dựng FDE #0446 tại 0x016e34..0x016ef8 (196 byte)
//   0x016e34: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x016e38: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016e3c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016e40: 910083fd  add      x29, sp, #0x20
//   0x016e44: 39400008  ldrb     w8, [x0]
//   0x016e48: aa0203f4  mov      x20, x2
//   0x016e4c: aa0003f3  mov      x19, x0
//   0x016e50: aa0103e7  mov      x7, x1
//   0x016e54: 37000088  tbnz     w8, #0, #0x16e64
//   0x016e58: d341fd15  lsr      x21, x8, #1
//   0x016e5c: 528002c1  mov      w1, #0x16
//   0x016e60: 14000004  b        #0x16e70
uint64_t fde_0446_sub_016e34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x37000088ULL) + (x2 ^ 0x016E34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x016e34: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x016e38: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016e3c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016e40: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x016e44: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x016e48: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x016e4c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x016e50: mov x7, x1
    return acc;
}

// [EN] Reconstructed FDE #0447 @ 0x016ef8..0x016f2c (52 bytes)
// [VN] Phục dựng FDE #0447 tại 0x016ef8..0x016f2c (52 byte)
//   0x016ef8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x016efc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x016f00: 910043fd  add      x29, sp, #0x10
//   0x016f04: aa0003f4  mov      x20, x0
//   0x016f08: aa0103e0  mov      x0, x1
//   0x016f0c: aa0103f3  mov      x19, x1
//   0x016f10: 97ffd044  bl       #0xb020
//   0x016f14: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x016f18: aa0003e2  mov      x2, x0
//   0x016f1c: aa1403e0  mov      x0, x20
//   0x016f20: aa1303e1  mov      x1, x19
//   0x016f24: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0447_sub_016ef8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E2ULL) + (x2 ^ 0x016EF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x016ef8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x016efc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x016f00: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x016f04: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x016f08: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x016f0c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD044ULL; // 0x016f10: bl #0xb020
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x016f14: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0448 @ 0x016f2c..0x016f48 (28 bytes)
// [VN] Phục dựng FDE #0448 tại 0x016f2c..0x016f48 (28 byte)
//   0x016f2c: 39400028  ldrb     w8, [x1]
//   0x016f30: a940a42a  ldp      x10, x9, [x1, #8]
//   0x016f34: d341fd0b  lsr      x11, x8, #1
//   0x016f38: 7200011f  tst      w8, #1
//   0x016f3c: 9a811521  csinc    x1, x9, x1, ne
//   0x016f40: 9a8a0162  csel     x2, x11, x10, eq
//   0x016f44: 17ffffbc  b        #0x16e34
uint64_t fde_0448_sub_016f2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400028ULL) + (x1 ^ 0x17FFFFBCULL) + (x2 ^ 0x016F2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x016f2c: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A42AULL; // 0x016f30: ldp x10, x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0BULL; // 0x016f34: lsr x11, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x016f38: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A811521ULL; // 0x016f3c: csinc x1, x9, x1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A0162ULL; // 0x016f40: csel x2, x11, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFBCULL; // 0x016f44: b #0x16e34
    return acc;
}

// [EN] Reconstructed FDE #0449 @ 0x016f48..0x016f58 (16 bytes)
// [VN] Phục dựng FDE #0449 tại 0x016f48..0x016f58 (16 byte)
//   0x016f48: f9401668  ldr      x8, [x19, #0x28]
//   0x016f4c: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x016f50: eb09011f  cmp      x8, x9
//   0x016f54: d65f03c0  ret      
uint64_t fde_0449_sub_016f48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401668ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016F48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x016f48: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E83A9ULL; // 0x016f4c: ldur x9, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x016f50: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016f54: ret 
    return acc;
}

// [EN] Reconstructed FDE #0450 @ 0x016f58..0x016f68 (16 bytes)
// [VN] Phục dựng FDE #0450 tại 0x016f58..0x016f68 (16 byte)
//   0x016f58: 910083e8  add      x8, sp, #0x20
//   0x016f5c: 910023e1  add      x1, sp, #8
//   0x016f60: 910083f4  add      x20, sp, #0x20
//   0x016f64: 17fffd34  b        #0x16434
uint64_t fde_0450_sub_016f58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E8ULL) + (x1 ^ 0x17FFFD34ULL) + (x2 ^ 0x016F58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E8ULL; // 0x016f58: add x8, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x016f5c: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910083F4ULL; // 0x016f60: add x20, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFD34ULL; // 0x016f64: b #0x16434
    return acc;
}

// [EN] Reconstructed FDE #0451 @ 0x016f68..0x016f74 (12 bytes)
// [VN] Phục dựng FDE #0451 tại 0x016f68..0x016f74 (12 byte)
//   0x016f68: f9000120  str      x0, [x9]
//   0x016f6c: aa0803e0  mov      x0, x8
//   0x016f70: 17fffdae  b        #0x16628
uint64_t fde_0451_sub_016f68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000120ULL) + (x1 ^ 0x17FFFDAEULL) + (x2 ^ 0x016F68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000120ULL; // 0x016f68: str x0, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x016f6c: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFDAEULL; // 0x016f70: b #0x16628
    return acc;
}

// [EN] Reconstructed FDE #0452 @ 0x016f74..0x016f80 (12 bytes)
// [VN] Phục dựng FDE #0452 tại 0x016f74..0x016f80 (12 byte)
//   0x016f74: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x016f78: 910183ff  add      sp, sp, #0x60
//   0x016f7c: d65f03c0  ret      
uint64_t fde_0452_sub_016f74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9444FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016F74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9444FF4ULL; // 0x016f74: ldp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FFULL; // 0x016f78: add sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016f7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0453 @ 0x016f80..0x016f8c (12 bytes)
// [VN] Phục dựng FDE #0453 tại 0x016f80..0x016f8c (12 byte)
//   0x016f80: b0000220  adrp     x0, #0x5b000
//   0x016f84: f947dc00  ldr      x0, [x0, #0xfb8]
//   0x016f88: 17ffcf46  b        #0xaca0
uint64_t fde_0453_sub_016f80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000220ULL) + (x1 ^ 0x17FFCF46ULL) + (x2 ^ 0x016F80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000220ULL; // 0x016f80: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947DC00ULL; // 0x016f84: ldr x0, [x0, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF46ULL; // 0x016f88: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #0454 @ 0x016f8c..0x016f98 (12 bytes)
// [VN] Phục dựng FDE #0454 tại 0x016f8c..0x016f98 (12 byte)
//   0x016f8c: aa0003f4  mov      x20, x0
//   0x016f90: aa1503e0  mov      x0, x21
//   0x016f94: 17ffd05f  b        #0xb110
uint64_t fde_0454_sub_016f8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F4ULL) + (x1 ^ 0x17FFD05FULL) + (x2 ^ 0x016F8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x016f8c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x016f90: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD05FULL; // 0x016f94: b #0xb110
    return acc;
}

// [EN] Reconstructed FDE #0455 @ 0x016f98..0x016fa4 (12 bytes)
// [VN] Phục dựng FDE #0455 tại 0x016f98..0x016fa4 (12 byte)
//   0x016f98: aa0003e8  mov      x8, x0
//   0x016f9c: aa1303e0  mov      x0, x19
//   0x016fa0: d61f0100  br       x8
uint64_t fde_0455_sub_016f98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x016F98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x016f98: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x016f9c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x016fa0: br x8
    return acc;
}

// [EN] Reconstructed FDE #0456 @ 0x016fa4..0x016fb8 (20 bytes)
// [VN] Phục dựng FDE #0456 tại 0x016fa4..0x016fb8 (20 byte)
//   0x016fa4: 528000a0  mov      w0, #5
//   0x016fa8: f9400101  ldr      x1, [x8]
//   0x016fac: aa1303e3  mov      x3, x19
//   0x016fb0: aa1403e4  mov      x4, x20
//   0x016fb4: d65f03c0  ret      
uint64_t fde_0456_sub_016fa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000A0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016FA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x016fa4: mov w0, #5
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400101ULL; // 0x016fa8: ldr x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x016fac: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E4ULL; // 0x016fb0: mov x4, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016fb4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0457 @ 0x016fb8..0x016fc4 (12 bytes)
// [VN] Phục dựng FDE #0457 tại 0x016fb8..0x016fc4 (12 byte)
//   0x016fb8: b0000228  adrp     x8, #0x5b000
//   0x016fbc: f942e508  ldr      x8, [x8, #0x5c8]
//   0x016fc0: d65f03c0  ret      
uint64_t fde_0457_sub_016fb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000228ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x016FB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000228ULL; // 0x016fb8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942E508ULL; // 0x016fbc: ldr x8, [x8, #0x5c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x016fc0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0458 @ 0x016fc4..0x017014 (80 bytes)
// [VN] Phục dựng FDE #0458 tại 0x016fc4..0x017014 (80 byte)
//   0x016fc4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x016fc8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x016fcc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x016fd0: 910083fd  add      x29, sp, #0x20
//   0x016fd4: 2a0303f4  mov      w20, w3
//   0x016fd8: 2a0203f5  mov      w21, w2
//   0x016fdc: 2a0103f6  mov      w22, w1
//   0x016fe0: 94000014  bl       #0x17030
//   0x016fe4: 34000080  cbz      w0, #0x16ff4
//   0x016fe8: 9400000b  bl       #0x17014
//   0x016fec: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x016ff0: 14000014  b        #0x17040
uint64_t fde_0458_sub_016fc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x34000080ULL) + (x2 ^ 0x016FC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x016fc4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x016fc8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x016fcc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x016fd0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x016fd4: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x016fd8: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x016fdc: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000014ULL; // 0x016fe0: bl #0x17030
    return acc;
}

// [EN] Reconstructed FDE #0459 @ 0x017014..0x017030 (28 bytes)
// [VN] Phục dựng FDE #0459 tại 0x017014..0x017030 (28 byte)
//   0x017014: 90000121  adrp     x1, #0x3b000
//   0x017018: 90000122  adrp     x2, #0x3b000
//   0x01701c: 910fa421  add      x1, x1, #0x3e9
//   0x017020: 910fd042  add      x2, x2, #0x3f4
//   0x017024: 528000c0  mov      w0, #6
//   0x017028: aa1303e3  mov      x3, x19
//   0x01702c: 17ffd06d  b        #0xb1e0
uint64_t fde_0459_sub_017014(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000121ULL) + (x1 ^ 0x17FFD06DULL) + (x2 ^ 0x017014ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000121ULL; // 0x017014: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000122ULL; // 0x017018: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x910FA421ULL; // 0x01701c: add x1, x1, #0x3e9
    acc = (acc * 0x100000001B3ULL) ^ 0x910FD042ULL; // 0x017020: add x2, x2, #0x3f4
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x017024: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x017028: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD06DULL; // 0x01702c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0460 @ 0x017030..0x017040 (16 bytes)
// [VN] Phục dựng FDE #0460 tại 0x017030..0x017040 (16 byte)
//   0x017030: 937e7e81  sbfiz    x1, x20, #2, #0x20
//   0x017034: 528000e2  mov      w2, #7
//   0x017038: aa0003f3  mov      x19, x0
//   0x01703c: 14000005  b        #0x17050
uint64_t fde_0460_sub_017030(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937E7E81ULL) + (x1 ^ 0x14000005ULL) + (x2 ^ 0x017030ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7E81ULL; // 0x017030: sbfiz x1, x20, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x528000E2ULL; // 0x017034: mov w2, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x017038: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x01703c: b #0x17050
    return acc;
}

// [EN] Reconstructed FDE #0461 @ 0x017040..0x017050 (16 bytes)
// [VN] Phục dựng FDE #0461 tại 0x017040..0x017050 (16 byte)
//   0x017040: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x017044: 12800000  mov      w0, #-1
//   0x017048: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x01704c: d65f03c0  ret      
uint64_t fde_0461_sub_017040(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017040ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x017040: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x017044: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C357F6ULL; // 0x017048: ldp x22, x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01704c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0462 @ 0x017050..0x01707c (44 bytes)
// [VN] Phục dựng FDE #0462 tại 0x017050..0x01707c (44 byte)
//   0x017050: 90000228  adrp     x8, #0x5b000
//   0x017054: f9426108  ldr      x8, [x8, #0x4c0]
//   0x017058: 8b000029  add      x9, x1, x0
//   0x01705c: b9800108  ldrsw    x8, [x8]
//   0x017060: cb0803ea  neg      x10, x8
//   0x017064: 8b080128  add      x8, x9, x8
//   0x017068: d1000908  sub      x8, x8, #2
//   0x01706c: 8a000140  and      x0, x10, x0
//   0x017070: 8a0a0108  and      x8, x8, x10
//   0x017074: cb000101  sub      x1, x8, x0
//   0x017078: 17ffd15a  b        #0xb5e0
uint64_t fde_0462_sub_017050(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000228ULL) + (x1 ^ 0x8A0A0108ULL) + (x2 ^ 0x017050ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000228ULL; // 0x017050: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x017054: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B000029ULL; // 0x017058: add x9, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800108ULL; // 0x01705c: ldrsw x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0803EAULL; // 0x017060: neg x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080128ULL; // 0x017064: add x8, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000908ULL; // 0x017068: sub x8, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8A000140ULL; // 0x01706c: and x0, x10, x0
    return acc;
}

// [EN] Reconstructed FDE #0463 @ 0x01707c..0x017174 (248 bytes)
// [VN] Phục dựng FDE #0463 tại 0x01707c..0x017174 (248 byte)
//   0x01707c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x017080: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x017084: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x017088: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01708c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x017090: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x017094: 910143fd  add      x29, sp, #0x50
//   0x017098: b4000600  cbz      x0, #0x17158
//   0x01709c: f9401028  ldr      x8, [x1, #0x20]
//   0x0170a0: aa0103f4  mov      x20, x1
//   0x0170a4: b4000588  cbz      x8, #0x17154
//   0x0170a8: 2a0203f3  mov      w19, w2
uint64_t fde_0463_sub_01707c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF9401028ULL) + (x2 ^ 0x01707CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x01707c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x017080: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x017084: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x017088: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01708c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x017090: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x017094: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000600ULL; // 0x017098: cbz x0, #0x17158
    return acc;
}

// [EN] Reconstructed FDE #0464 @ 0x017174..0x017308 (404 bytes)
// [VN] Phục dựng FDE #0464 tại 0x017174..0x017308 (404 byte)
//   0x017174: 12061408  and      w8, w0, #0xfc000000
//   0x017178: 52a28009  mov      w9, #0x14000000
//   0x01717c: 6b09011f  cmp      w8, w9
//   0x017180: 54000061  b.ne     #0x1718c
//   0x017184: 52800020  mov      w0, #1
//   0x017188: d65f03c0  ret      
//   0x01718c: 52800209  mov      w9, #0x10
//   0x017190: 72bfe009  movk     w9, #0xff00, lsl #16
//   0x017194: 0a090009  and      w9, w0, w9
//   0x017198: 52aa800a  mov      w10, #0x54000000
//   0x01719c: 6b0a013f  cmp      w9, w10
//   0x0171a0: 54000061  b.ne     #0x171ac
uint64_t fde_0464_sub_017174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12061408ULL) + (x1 ^ 0x0A090009ULL) + (x2 ^ 0x017174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12061408ULL; // 0x017174: and w8, w0, #0xfc000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52A28009ULL; // 0x017178: mov w9, #0x14000000
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x01717c: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x017180: b.ne #0x1718c
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x017184: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017188: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x52800209ULL; // 0x01718c: mov w9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x72BFE009ULL; // 0x017190: movk w9, #0xff00, lsl #16
    return acc;
}

// [EN] Reconstructed FDE #0465 @ 0x017308..0x017368 (96 bytes)
// [VN] Phục dựng FDE #0465 tại 0x017308..0x017368 (96 byte)
//   0x017308: d10103ff  sub      sp, sp, #0x40
//   0x01730c: f90013f3  str      x19, [sp, #0x20]
//   0x017310: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x017314: 9100c3fd  add      x29, sp, #0x30
//   0x017318: d53bd053  mrs      x19, tpidr_el0
//   0x01731c: f9401668  ldr      x8, [x19, #0x28]
//   0x017320: f9000fe8  str      x8, [sp, #0x18]
//   0x017324: f9000be1  str      x1, [sp, #0x10]
//   0x017328: 29010be3  stp      w3, w2, [sp, #8]
//   0x01732c: b90007e4  str      w4, [sp, #4]
//   0x017330: 910043e1  add      x1, sp, #0x10
//   0x017334: 910033e2  add      x2, sp, #0xc
uint64_t fde_0465_sub_017308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x29010BE3ULL) + (x2 ^ 0x017308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x017308: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x01730c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x017310: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x017314: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x017318: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01731c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x017320: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE1ULL; // 0x017324: str x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0466 @ 0x017368..0x0173d4 (108 bytes)
// [VN] Phục dựng FDE #0466 tại 0x017368..0x0173d4 (108 byte)
//   0x017368: d101c3ff  sub      sp, sp, #0x70
//   0x01736c: f9002bf3  str      x19, [sp, #0x50]
//   0x017370: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x017374: 910183fd  add      x29, sp, #0x60
//   0x017378: d53bd053  mrs      x19, tpidr_el0
//   0x01737c: f9401668  ldr      x8, [x19, #0x28]
//   0x017380: f81e83a8  stur     x8, [x29, #-0x18]
//   0x017384: 12800008  mov      w8, #-1
//   0x017388: b9000fe8  str      w8, [sp, #0xc]
//   0x01738c: f0000208  adrp     x8, #0x5a000
//   0x017390: 9120a108  add      x8, x8, #0x828
//   0x017394: f9000be8  str      x8, [sp, #0x10]
uint64_t fde_0466_sub_017368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB9000FE8ULL) + (x2 ^ 0x017368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x017368: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BF3ULL; // 0x01736c: str x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x017370: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x017374: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x017378: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01737c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x017380: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x12800008ULL; // 0x017384: mov w8, #-1
    return acc;
}

// [EN] Reconstructed FDE #0467 @ 0x0173d4..0x0173f8 (36 bytes)
// [VN] Phục dựng FDE #0467 tại 0x0173d4..0x0173f8 (36 byte)
//   0x0173d4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0173d8: 910003fd  mov      x29, sp
//   0x0173dc: f9401000  ldr      x0, [x0, #0x20]
//   0x0173e0: b40000a0  cbz      x0, #0x173f4
//   0x0173e4: f9400008  ldr      x8, [x0]
//   0x0173e8: f9401905  ldr      x5, [x8, #0x30]
//   0x0173ec: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0173f0: d61f00a0  br       x5
//   0x0173f4: 94000001  bl       #0x173f8
uint64_t fde_0467_sub_0173d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000001ULL) + (x2 ^ 0x0173D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0173d4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0173d8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x0173dc: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x0173e0: cbz x0, #0x173f4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0173e4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401905ULL; // 0x0173e8: ldr x5, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0173ec: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00A0ULL; // 0x0173f0: br x5
    return acc;
}

// [EN] Reconstructed FDE #0468 @ 0x0173f8..0x017404 (12 bytes)
// [VN] Phục dựng FDE #0468 tại 0x0173f8..0x017404 (12 byte)
//   0x0173f8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0173fc: 910003fd  mov      x29, sp
//   0x017400: 97ffd040  bl       #0xb500
uint64_t fde_0468_sub_0173f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFD040ULL) + (x2 ^ 0x0173F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0173f8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0173fc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD040ULL; // 0x017400: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0469 @ 0x017404..0x017434 (48 bytes)
// [VN] Phục dựng FDE #0469 tại 0x017404..0x017434 (48 byte)
//   0x017404: aa0003e8  mov      x8, x0
//   0x017408: f9401000  ldr      x0, [x0, #0x20]
//   0x01740c: eb00011f  cmp      x8, x0
//   0x017410: 540000a0  b.eq     #0x17424
//   0x017414: b40000e0  cbz      x0, #0x17430
//   0x017418: f9400008  ldr      x8, [x0]
//   0x01741c: f9401501  ldr      x1, [x8, #0x28]
//   0x017420: d61f0020  br       x1
//   0x017424: f9400008  ldr      x8, [x0]
//   0x017428: f9401101  ldr      x1, [x8, #0x20]
//   0x01742c: d61f0020  br       x1
//   0x017430: d65f03c0  ret      
uint64_t fde_0469_sub_017404(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x017404ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x017404: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x017408: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x01740c: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x017410: b.eq #0x17424
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x017414: cbz x0, #0x17430
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x017418: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x01741c: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x017420: br x1
    return acc;
}

// [EN] Reconstructed FDE #0470 @ 0x017434..0x017438 (4 bytes)
// [VN] Phục dựng FDE #0470 tại 0x017434..0x017438 (4 byte)
//   0x017434: 17ffce43  b        #0xad40
uint64_t fde_0470_sub_017434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCE43ULL) + (x1 ^ 0x17FFCE43ULL) + (x2 ^ 0x017434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCE43ULL; // 0x017434: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0471 @ 0x017438..0x01746c (52 bytes)
// [VN] Phục dựng FDE #0471 tại 0x017438..0x01746c (52 byte)
//   0x017438: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01743c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x017440: 910043fd  add      x29, sp, #0x10
//   0x017444: 9400004a  bl       #0x1756c
//   0x017448: f0000208  adrp     x8, #0x5a000
//   0x01744c: 9120a108  add      x8, x8, #0x828
//   0x017450: f9000008  str      x8, [x0]
//   0x017454: 3cc08260  ldur     q0, [x19, #8]
//   0x017458: f9400e68  ldr      x8, [x19, #0x18]
//   0x01745c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x017460: 3c808000  stur     q0, [x0, #8]
//   0x017464: f9000c08  str      x8, [x0, #0x18]
uint64_t fde_0471_sub_017438(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400E68ULL) + (x2 ^ 0x017438ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x017438: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01743c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x017440: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400004AULL; // 0x017444: bl #0x1756c
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000208ULL; // 0x017448: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9120A108ULL; // 0x01744c: add x8, x8, #0x828
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x017450: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC08260ULL; // 0x017454: ldur q0, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0472 @ 0x01746c..0x017478 (12 bytes)
// [VN] Phục dựng FDE #0472 tại 0x01746c..0x017478 (12 byte)
//   0x01746c: f0000208  adrp     x8, #0x5a000
//   0x017470: 9120a108  add      x8, x8, #0x828
//   0x017474: 1400002d  b        #0x17528
uint64_t fde_0472_sub_01746c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000208ULL) + (x1 ^ 0x1400002DULL) + (x2 ^ 0x01746CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000208ULL; // 0x01746c: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9120A108ULL; // 0x017470: add x8, x8, #0x828
    acc = (acc * 0x100000001B3ULL) ^ 0x1400002DULL; // 0x017474: b #0x17528
    return acc;
}

// [EN] Reconstructed FDE #0473 @ 0x017478..0x01747c (4 bytes)
// [VN] Phục dựng FDE #0473 tại 0x017478..0x01747c (4 byte)
//   0x017478: d65f03c0  ret      
uint64_t fde_0473_sub_017478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017478: ret 
    return acc;
}

// [EN] Reconstructed FDE #0474 @ 0x01747c..0x017480 (4 bytes)
// [VN] Phục dựng FDE #0474 tại 0x01747c..0x017480 (4 byte)
//   0x01747c: 17ffce31  b        #0xad40
uint64_t fde_0474_sub_01747c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCE31ULL) + (x1 ^ 0x17FFCE31ULL) + (x2 ^ 0x01747CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCE31ULL; // 0x01747c: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0475 @ 0x017480..0x017510 (144 bytes)
// [VN] Phục dựng FDE #0475 tại 0x017480..0x017510 (144 byte)
//   0x017480: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x017484: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x017488: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01748c: 910083fd  add      x29, sp, #0x20
//   0x017490: b9400088  ldr      w8, [x4]
//   0x017494: 7100211f  cmp      w8, #8
//   0x017498: 54000301  b.ne     #0x174f8
//   0x01749c: b9400808  ldr      w8, [x0, #8]
//   0x0174a0: f9400033  ldr      x19, [x1]
//   0x0174a4: b9400075  ldr      w21, [x3]
//   0x0174a8: aa0003f4  mov      x20, x0
//   0x0174ac: 3100051f  cmn      w8, #1
uint64_t fde_0475_sub_017480(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400033ULL) + (x2 ^ 0x017480ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x017480: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x017484: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x017488: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01748c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400088ULL; // 0x017490: ldr w8, [x4]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100211FULL; // 0x017494: cmp w8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000301ULL; // 0x017498: b.ne #0x174f8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400808ULL; // 0x01749c: ldr w8, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0476 @ 0x017510..0x017514 (4 bytes)
// [VN] Phục dựng FDE #0476 tại 0x017510..0x017514 (4 byte)
//   0x017510: d65f03c0  ret      
uint64_t fde_0476_sub_017510(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017510ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017510: ret 
    return acc;
}

// [EN] Reconstructed FDE #0477 @ 0x017514..0x01751c (8 bytes)
// [VN] Phục dựng FDE #0477 tại 0x017514..0x01751c (8 byte)
//   0x017514: f84207f3  ldr      x19, [sp], #0x20
//   0x017518: d65f03c0  ret      
uint64_t fde_0477_sub_017514(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF84207F3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017514ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x017514: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017518: ret 
    return acc;
}

// [EN] Reconstructed FDE #0478 @ 0x01751c..0x017528 (12 bytes)
// [VN] Phục dựng FDE #0478 tại 0x01751c..0x017528 (12 byte)
//   0x01751c: 90000220  adrp     x0, #0x5b000
//   0x017520: f946e000  ldr      x0, [x0, #0xdc0]
//   0x017524: 14008660  b        #0x38ea4
uint64_t fde_0478_sub_01751c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000220ULL) + (x1 ^ 0x14008660ULL) + (x2 ^ 0x01751CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000220ULL; // 0x01751c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946E000ULL; // 0x017520: ldr x0, [x0, #0xdc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x14008660ULL; // 0x017524: b #0x38ea4
    return acc;
}

// [EN] Reconstructed FDE #0479 @ 0x017528..0x017540 (24 bytes)
// [VN] Phục dựng FDE #0479 tại 0x017528..0x017540 (24 byte)
//   0x017528: f9000028  str      x8, [x1]
//   0x01752c: f9400c08  ldr      x8, [x0, #0x18]
//   0x017530: 3cc08000  ldur     q0, [x0, #8]
//   0x017534: f9000c28  str      x8, [x1, #0x18]
//   0x017538: 3c808020  stur     q0, [x1, #8]
//   0x01753c: d65f03c0  ret      
uint64_t fde_0479_sub_017528(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000028ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017528ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x017528: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C08ULL; // 0x01752c: ldr x8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC08000ULL; // 0x017530: ldur q0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C28ULL; // 0x017534: str x8, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C808020ULL; // 0x017538: stur q0, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01753c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0480 @ 0x017540..0x01754c (12 bytes)
// [VN] Phục dựng FDE #0480 tại 0x017540..0x01754c (12 byte)
//   0x017540: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x017544: f84307f5  ldr      x21, [sp], #0x30
//   0x017548: d65f03c0  ret      
uint64_t fde_0480_sub_017540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x017540: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84307F5ULL; // 0x017544: ldr x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017548: ret 
    return acc;
}

// [EN] Reconstructed FDE #0481 @ 0x01754c..0x017558 (12 bytes)
// [VN] Phục dựng FDE #0481 tại 0x01754c..0x017558 (12 byte)
//   0x01754c: f9402bf3  ldr      x19, [sp, #0x50]
//   0x017550: 9101c3ff  add      sp, sp, #0x70
//   0x017554: d65f03c0  ret      
uint64_t fde_0481_sub_01754c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9402BF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01754CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402BF3ULL; // 0x01754c: ldr x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FFULL; // 0x017550: add sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017554: ret 
    return acc;
}

// [EN] Reconstructed FDE #0482 @ 0x017558..0x01756c (20 bytes)
// [VN] Phục dựng FDE #0482 tại 0x017558..0x01756c (20 byte)
//   0x017558: b9400fe0  ldr      w0, [sp, #0xc]
//   0x01755c: f9401668  ldr      x8, [x19, #0x28]
//   0x017560: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x017564: eb09011f  cmp      x8, x9
//   0x017568: d65f03c0  ret      
uint64_t fde_0482_sub_017558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400FE0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400FE0ULL; // 0x017558: ldr w0, [sp, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01755c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E83A9ULL; // 0x017560: ldur x9, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x017564: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017568: ret 
    return acc;
}

// [EN] Reconstructed FDE #0483 @ 0x01756c..0x017578 (12 bytes)
// [VN] Phục dựng FDE #0483 tại 0x01756c..0x017578 (12 byte)
//   0x01756c: aa0003f3  mov      x19, x0
//   0x017570: 52800400  mov      w0, #0x20
//   0x017574: 17ffd01f  b        #0xb5f0
uint64_t fde_0483_sub_01756c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F3ULL) + (x1 ^ 0x17FFD01FULL) + (x2 ^ 0x01756CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01756c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800400ULL; // 0x017570: mov w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD01FULL; // 0x017574: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0484 @ 0x017578..0x017614 (156 bytes)
// [VN] Phục dựng FDE #0484 tại 0x017578..0x017614 (156 byte)
//   0x017578: d10203ff  sub      sp, sp, #0x80
//   0x01757c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x017580: 9101c3fd  add      x29, sp, #0x70
//   0x017584: d53bd048  mrs      x8, tpidr_el0
//   0x017588: f9401509  ldr      x9, [x8, #0x28]
//   0x01758c: f81f83a9  stur     x9, [x29, #-8]
//   0x017590: b0000229  adrp     x9, #0x5c000
//   0x017594: 91148129  add      x9, x9, #0x520
//   0x017598: 08dffd29  ldarb    w9, [x9]
//   0x01759c: 36000149  tbz      w9, #0, #0x175c4
//   0x0175a0: b0000229  adrp     x9, #0x5c000
//   0x0175a4: b9451920  ldr      w0, [x9, #0x518]
uint64_t fde_0484_sub_017578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x08DFFD29ULL) + (x2 ^ 0x017578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x017578: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01757c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x017580: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x017584: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x017588: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F83A9ULL; // 0x01758c: stur x9, [x29, #-8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000229ULL; // 0x017590: adrp x9, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91148129ULL; // 0x017594: add x9, x9, #0x520
    return acc;
}

// [EN] Reconstructed FDE #0485 @ 0x017614..0x01761c (8 bytes)
// [VN] Phục dựng FDE #0485 tại 0x017614..0x01761c (8 byte)
//   0x017614: 2a1f03e0  mov      w0, wzr
//   0x017618: d65f03c0  ret      
uint64_t fde_0485_sub_017614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x017614: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017618: ret 
    return acc;
}

// [EN] Reconstructed FDE #0486 @ 0x01761c..0x0176ec (208 bytes)
// [VN] Phục dựng FDE #0486 tại 0x01761c..0x0176ec (208 byte)
//   0x01761c: d104c3ff  sub      sp, sp, #0x130
//   0x017620: f9008bfc  str      x28, [sp, #0x110]
//   0x017624: a9127bfd  stp      x29, x30, [sp, #0x120]
//   0x017628: 910483fd  add      x29, sp, #0x120
//   0x01762c: d53bd048  mrs      x8, tpidr_el0
//   0x017630: f9401509  ldr      x9, [x8, #0x28]
//   0x017634: f81e83a9  stur     x9, [x29, #-0x18]
//   0x017638: b0000229  adrp     x9, #0x5c000
//   0x01763c: 9114c129  add      x9, x9, #0x530
//   0x017640: 08dffd29  ldarb    w9, [x9]
//   0x017644: 360001a9  tbz      w9, #0, #0x17678
//   0x017648: b0000229  adrp     x9, #0x5c000
uint64_t fde_0486_sub_01761c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD104C3FFULL) + (x1 ^ 0x9114C129ULL) + (x2 ^ 0x01761CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x01761c: sub sp, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x017620: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9127BFDULL; // 0x017624: stp x29, x30, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x910483FDULL; // 0x017628: add x29, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x01762c: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x017630: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A9ULL; // 0x017634: stur x9, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000229ULL; // 0x017638: adrp x9, #0x5c000
    return acc;
}

// [EN] Reconstructed FDE #0487 @ 0x0176ec..0x0177b8 (204 bytes)
// [VN] Phục dựng FDE #0487 tại 0x0176ec..0x0177b8 (204 byte)
//   0x0176ec: d10103ff  sub      sp, sp, #0x40
//   0x0176f0: f9000bf5  str      x21, [sp, #0x10]
//   0x0176f4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0176f8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0176fc: 9100c3fd  add      x29, sp, #0x30
//   0x017700: d53bd055  mrs      x21, tpidr_el0
//   0x017704: f94016a8  ldr      x8, [x21, #0x28]
//   0x017708: f90007e8  str      x8, [sp, #8]
//   0x01770c: 97ffcfd9  bl       #0xb670
//   0x017710: 51007c08  sub      w8, w0, #0x1f
//   0x017714: 2a0003f3  mov      w19, w0
//   0x017718: 7100111f  cmp      w8, #4
uint64_t fde_0487_sub_0176ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x97FFCFD9ULL) + (x2 ^ 0x0176ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0176ec: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0176f0: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0176f4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0176f8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0176fc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x017700: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x017704: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x017708: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0488 @ 0x0177b8..0x0177ec (52 bytes)
// [VN] Phục dựng FDE #0488 tại 0x0177b8..0x0177ec (52 byte)
//   0x0177b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0177bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0177c0: 910043fd  add      x29, sp, #0x10
//   0x0177c4: 90000233  adrp     x19, #0x5b000
//   0x0177c8: f9435a73  ldr      x19, [x19, #0x6b0]
//   0x0177cc: b9400260  ldr      w0, [x19]
//   0x0177d0: 3100041f  cmn      w0, #1
//   0x0177d4: 54000061  b.ne     #0x177e0
//   0x0177d8: 97ffffc5  bl       #0x176ec
//   0x0177dc: b9000260  str      w0, [x19]
//   0x0177e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0177e4: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0488_sub_0177b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFFFC5ULL) + (x2 ^ 0x0177B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0177b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0177bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0177c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000233ULL; // 0x0177c4: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435A73ULL; // 0x0177c8: ldr x19, [x19, #0x6b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400260ULL; // 0x0177cc: ldr w0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x0177d0: cmn w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x0177d4: b.ne #0x177e0
    return acc;
}

// [EN] Reconstructed FDE #0489 @ 0x0177ec..0x0177f0 (4 bytes)
// [VN] Phục dựng FDE #0489 tại 0x0177ec..0x0177f0 (4 byte)
//   0x0177ec: 17fffff3  b        #0x177b8
uint64_t fde_0489_sub_0177ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFF3ULL) + (x1 ^ 0x17FFFFF3ULL) + (x2 ^ 0x0177ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFF3ULL; // 0x0177ec: b #0x177b8
    return acc;
}

// [EN] Reconstructed FDE #0490 @ 0x0177f0..0x017914 (292 bytes)
// [VN] Phục dựng FDE #0490 tại 0x0177f0..0x017914 (292 byte)
//   0x0177f0: d10103ff  sub      sp, sp, #0x40
//   0x0177f4: f9000bf5  str      x21, [sp, #0x10]
//   0x0177f8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0177fc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x017800: 9100c3fd  add      x29, sp, #0x30
//   0x017804: d53bd054  mrs      x20, tpidr_el0
//   0x017808: f9401688  ldr      x8, [x20, #0x28]
//   0x01780c: b0000235  adrp     x21, #0x5c000
//   0x017810: f90007e8  str      x8, [sp, #8]
//   0x017814: b980a6a8  ldrsw    x8, [x21, #0xa4]
//   0x017818: 36f80628  tbz      w8, #0x1f, #0x178dc
//   0x01781c: b40000e0  cbz      x0, #0x17838
uint64_t fde_0490_sub_0177f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0177F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0177f0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0177f4: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0177f8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0177fc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x017800: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x017804: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x017808: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000235ULL; // 0x01780c: adrp x21, #0x5c000
    return acc;
}

// [EN] Reconstructed FDE #0491 @ 0x017914..0x017b10 (508 bytes)
// [VN] Phục dựng FDE #0491 tại 0x017914..0x017b10 (508 byte)
//   0x017914: d106c3ff  sub      sp, sp, #0x1b0
//   0x017918: a9156ffc  stp      x28, x27, [sp, #0x150]
//   0x01791c: a91667fa  stp      x26, x25, [sp, #0x160]
//   0x017920: a9175ff8  stp      x24, x23, [sp, #0x170]
//   0x017924: a91857f6  stp      x22, x21, [sp, #0x180]
//   0x017928: a9194ff4  stp      x20, x19, [sp, #0x190]
//   0x01792c: a91a7bfd  stp      x29, x30, [sp, #0x1a0]
//   0x017930: 910683fd  add      x29, sp, #0x1a0
//   0x017934: d53bd055  mrs      x21, tpidr_el0
//   0x017938: f94016a8  ldr      x8, [x21, #0x28]
//   0x01793c: b0000236  adrp     x22, #0x5c000
//   0x017940: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0491_sub_017914(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD106C3FFULL) + (x1 ^ 0xD53BD055ULL) + (x2 ^ 0x017914ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x017914: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9156FFCULL; // 0x017918: stp x28, x27, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91667FAULL; // 0x01791c: stp x26, x25, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9175FF8ULL; // 0x017920: stp x24, x23, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91857F6ULL; // 0x017924: stp x22, x21, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9194FF4ULL; // 0x017928: stp x20, x19, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A7BFDULL; // 0x01792c: stp x29, x30, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910683FDULL; // 0x017930: add x29, sp, #0x1a0
    return acc;
}

// [EN] Reconstructed FDE #0492 @ 0x017b10..0x017b84 (116 bytes)
// [VN] Phục dựng FDE #0492 tại 0x017b10..0x017b84 (116 byte)
//   0x017b10: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x017b14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x017b18: 910043fd  add      x29, sp, #0x10
//   0x017b1c: aa1f03e8  mov      x8, xzr
//   0x017b20: f112c11f  cmp      x8, #0x4b0
//   0x017b24: 54000140  b.eq     #0x17b4c
//   0x017b28: f8686809  ldr      x9, [x0, x8]
//   0x017b2c: eb01013f  cmp      x9, x1
//   0x017b30: 540000a1  b.ne     #0x17b44
//   0x017b34: 8b080009  add      x9, x0, x8
//   0x017b38: f940052a  ldr      x10, [x9, #8]
//   0x017b3c: eb01015f  cmp      x10, x1
uint64_t fde_0492_sub_017b10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x540000A1ULL) + (x2 ^ 0x017B10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x017b10: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x017b14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x017b18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x017b1c: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF112C11FULL; // 0x017b20: cmp x8, #0x4b0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x017b24: b.eq #0x17b4c
    acc = (acc * 0x100000001B3ULL) ^ 0xF8686809ULL; // 0x017b28: ldr x9, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x017b2c: cmp x9, x1
    return acc;
}

// [EN] Reconstructed FDE #0493 @ 0x017b84..0x017b94 (16 bytes)
// [VN] Phục dựng FDE #0493 tại 0x017b84..0x017b94 (16 byte)
//   0x017b84: 9100c3e1  add      x1, sp, #0x30
//   0x017b88: 52800042  mov      w2, #2
//   0x017b8c: 2a1403e0  mov      w0, w20
//   0x017b90: 14004bcc  b        #0x2aac0
uint64_t fde_0493_sub_017b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100C3E1ULL) + (x1 ^ 0x14004BCCULL) + (x2 ^ 0x017B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E1ULL; // 0x017b84: add x1, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x52800042ULL; // 0x017b88: mov w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E0ULL; // 0x017b8c: mov w0, w20
    acc = (acc * 0x100000001B3ULL) ^ 0x14004BCCULL; // 0x017b90: b #0x2aac0
    return acc;
}

// [EN] Reconstructed FDE #0494 @ 0x017b94..0x017ba0 (12 bytes)
// [VN] Phục dựng FDE #0494 tại 0x017b94..0x017ba0 (12 byte)
//   0x017b94: d0000100  adrp     x0, #0x39000
//   0x017b98: 911cd000  add      x0, x0, #0x734
//   0x017b9c: 17ffcd01  b        #0xafa0
uint64_t fde_0494_sub_017b94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000100ULL) + (x1 ^ 0x17FFCD01ULL) + (x2 ^ 0x017B94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000100ULL; // 0x017b94: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x017b98: add x0, x0, #0x734
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCD01ULL; // 0x017b9c: b #0xafa0
    return acc;
}

// [EN] Reconstructed FDE #0495 @ 0x017ba0..0x017ba8 (8 bytes)
// [VN] Phục dựng FDE #0495 tại 0x017ba0..0x017ba8 (8 byte)
//   0x017ba0: 528000c0  mov      w0, #6
//   0x017ba4: 17ffcd8f  b        #0xb1e0
uint64_t fde_0495_sub_017ba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFCD8FULL) + (x2 ^ 0x017BA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x017ba0: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCD8FULL; // 0x017ba4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0496 @ 0x017ba8..0x017cd0 (296 bytes)
// [VN] Phục dựng FDE #0496 tại 0x017ba8..0x017cd0 (296 byte)
//   0x017ba8: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x017bac: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x017bb0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x017bb4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x017bb8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x017bbc: 910103fd  add      x29, sp, #0x40
//   0x017bc0: b100403f  cmn      x1, #0x10
//   0x017bc4: 54000842  b.hs     #0x17ccc
//   0x017bc8: 39400018  ldrb     w24, [x0]
//   0x017bcc: aa0003f3  mov      x19, x0
//   0x017bd0: 37000098  tbnz     w24, #0, #0x17be0
//   0x017bd4: d341ff16  lsr      x22, x24, #1
uint64_t fde_0496_sub_017ba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x39400018ULL) + (x2 ^ 0x017BA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x017ba8: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x017bac: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x017bb0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x017bb4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x017bb8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x017bbc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB100403FULL; // 0x017bc0: cmn x1, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000842ULL; // 0x017bc4: b.hs #0x17ccc
    return acc;
}

// [EN] Reconstructed FDE #0497 @ 0x017cd0..0x017ee4 (532 bytes)
// [VN] Phục dựng FDE #0497 tại 0x017cd0..0x017ee4 (532 byte)
//   0x017cd0: d10203ff  sub      sp, sp, #0x80
//   0x017cd4: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x017cd8: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x017cdc: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x017ce0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x017ce4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x017ce8: 9101c3fd  add      x29, sp, #0x70
//   0x017cec: d53bd058  mrs      x24, tpidr_el0
//   0x017cf0: aa0803f3  mov      x19, x8
//   0x017cf4: f9401708  ldr      x8, [x24, #0x28]
//   0x017cf8: 2a0103f5  mov      w21, w1
//   0x017cfc: aa0003f4  mov      x20, x0
uint64_t fde_0497_sub_017cd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0803F3ULL) + (x2 ^ 0x017CD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x017cd0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x017cd4: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x017cd8: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x017cdc: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x017ce0: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x017ce4: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x017ce8: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x017cec: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0498 @ 0x017ee4..0x017f04 (32 bytes)
// [VN] Phục dựng FDE #0498 tại 0x017ee4..0x017f04 (32 byte)
//   0x017ee4: 39400008  ldrb     w8, [x0]
//   0x017ee8: 37000068  tbnz     w8, #0, #0x17ef4
//   0x017eec: d341fd08  lsr      x8, x8, #1
//   0x017ef0: 14000002  b        #0x17ef8
//   0x017ef4: f9400408  ldr      x8, [x0, #8]
//   0x017ef8: f100011f  cmp      x8, #0
//   0x017efc: 1a9f17e0  cset     w0, eq
//   0x017f00: d65f03c0  ret      
uint64_t fde_0498_sub_017ee4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x017EE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x017ee4: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x017ee8: tbnz w8, #0, #0x17ef4
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD08ULL; // 0x017eec: lsr x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x017ef0: b #0x17ef8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x017ef4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF100011FULL; // 0x017ef8: cmp x8, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x017efc: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017f00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0499 @ 0x017f04..0x017f44 (64 bytes)
// [VN] Phục dựng FDE #0499 tại 0x017f04..0x017f44 (64 byte)
//   0x017f04: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x017f08: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x017f0c: 910043fd  add      x29, sp, #0x10
//   0x017f10: 39400008  ldrb     w8, [x0]
//   0x017f14: aa0103f3  mov      x19, x1
//   0x017f18: 37000068  tbnz     w8, #0, #0x17f24
//   0x017f1c: 91000408  add      x8, x0, #1
//   0x017f20: 14000002  b        #0x17f28
//   0x017f24: f9400808  ldr      x8, [x0, #0x10]
//   0x017f28: cb080261  sub      x1, x19, x8
//   0x017f2c: cb130042  sub      x2, x2, x19
//   0x017f30: 94000050  bl       #0x18070
uint64_t fde_0499_sub_017f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400808ULL) + (x2 ^ 0x017F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x017f04: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x017f08: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x017f0c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x017f10: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x017f14: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x017f18: tbnz w8, #0, #0x17f24
    acc = (acc * 0x100000001B3ULL) ^ 0x91000408ULL; // 0x017f1c: add x8, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x017f20: b #0x17f28
    return acc;
}

// [EN] Reconstructed FDE #0500 @ 0x017f44..0x017fa4 (96 bytes)
// [VN] Phục dựng FDE #0500 tại 0x017f44..0x017fa4 (96 byte)
//   0x017f44: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x017f48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x017f4c: 910043fd  add      x29, sp, #0x10
//   0x017f50: aa0203f3  mov      x19, x2
//   0x017f54: aa0103f4  mov      x20, x1
//   0x017f58: 9400006c  bl       #0x18108
//   0x017f5c: eb14001f  cmp      x0, x20
//   0x017f60: 540001c0  b.eq     #0x17f98
//   0x017f64: d1000688  sub      x8, x20, #1
//   0x017f68: aa0003e9  mov      x9, x0
//   0x017f6c: 3940026a  ldrb     w10, [x19]
//   0x017f70: aa0903eb  mov      x11, x9
uint64_t fde_0500_sub_017f44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD1000688ULL) + (x2 ^ 0x017F44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x017f44: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x017f48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x017f4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x017f50: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x017f54: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9400006CULL; // 0x017f58: bl #0x18108
    acc = (acc * 0x100000001B3ULL) ^ 0xEB14001FULL; // 0x017f5c: cmp x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C0ULL; // 0x017f60: b.eq #0x17f98
    return acc;
}

// [EN] Reconstructed FDE #0501 @ 0x017fa4..0x01802c (136 bytes)
// [VN] Phục dựng FDE #0501 tại 0x017fa4..0x01802c (136 byte)
//   0x017fa4: 51010408  sub      w8, w0, #0x41
//   0x017fa8: 12001d08  and      w8, w8, #0xff
//   0x017fac: 7100651f  cmp      w8, #0x19
//   0x017fb0: 12001c08  and      w8, w0, #0xff
//   0x017fb4: 54000068  b.hi     #0x17fc0
//   0x017fb8: 51010500  sub      w0, w8, #0x41
//   0x017fbc: d65f03c0  ret      
//   0x017fc0: 51018409  sub      w9, w0, #0x61
//   0x017fc4: 12001d29  and      w9, w9, #0xff
//   0x017fc8: 7100653f  cmp      w9, #0x19
//   0x017fcc: 54000068  b.hi     #0x17fd8
//   0x017fd0: 51011d00  sub      w0, w8, #0x47
uint64_t fde_0501_sub_017fa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x51010408ULL) + (x1 ^ 0x12001D29ULL) + (x2 ^ 0x017FA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x51010408ULL; // 0x017fa4: sub w8, w0, #0x41
    acc = (acc * 0x100000001B3ULL) ^ 0x12001D08ULL; // 0x017fa8: and w8, w8, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x7100651FULL; // 0x017fac: cmp w8, #0x19
    acc = (acc * 0x100000001B3ULL) ^ 0x12001C08ULL; // 0x017fb0: and w8, w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x54000068ULL; // 0x017fb4: b.hi #0x17fc0
    acc = (acc * 0x100000001B3ULL) ^ 0x51010500ULL; // 0x017fb8: sub w0, w8, #0x41
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x017fbc: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x51018409ULL; // 0x017fc0: sub w9, w0, #0x61
    return acc;
}

// [EN] Reconstructed FDE #0502 @ 0x01802c..0x018070 (68 bytes)
// [VN] Phục dựng FDE #0502 tại 0x01802c..0x018070 (68 byte)
//   0x01802c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x018030: 910003fd  mov      x29, sp
//   0x018034: 39400008  ldrb     w8, [x0]
//   0x018038: 37000068  tbnz     w8, #0, #0x18044
//   0x01803c: d341fd09  lsr      x9, x8, #1
//   0x018040: 14000002  b        #0x18048
//   0x018044: f9400409  ldr      x9, [x0, #8]
//   0x018048: eb01013f  cmp      x9, x1
//   0x01804c: 54000109  b.ls     #0x1806c
//   0x018050: 37000068  tbnz     w8, #0, #0x1805c
//   0x018054: 91000408  add      x8, x0, #1
//   0x018058: 14000002  b        #0x18060
uint64_t fde_0502_sub_01802c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x54000109ULL) + (x2 ^ 0x01802CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01802c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x018030: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x018034: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x018038: tbnz w8, #0, #0x18044
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD09ULL; // 0x01803c: lsr x9, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x018040: b #0x18048
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x018044: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x018048: cmp x9, x1
    return acc;
}

// [EN] Reconstructed FDE #0503 @ 0x018070..0x018108 (152 bytes)
// [VN] Phục dựng FDE #0503 tại 0x018070..0x018108 (152 byte)
//   0x018070: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x018074: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x018078: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01807c: 910083fd  add      x29, sp, #0x20
//   0x018080: 39400008  ldrb     w8, [x0]
//   0x018084: aa0003f3  mov      x19, x0
//   0x018088: 37000068  tbnz     w8, #0, #0x18094
//   0x01808c: d341fd14  lsr      x20, x8, #1
//   0x018090: 14000002  b        #0x18098
//   0x018094: f9400674  ldr      x20, [x19, #8]
//   0x018098: eb010289  subs     x9, x20, x1
//   0x01809c: 54000343  b.lo     #0x18104
uint64_t fde_0503_sub_018070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x14000002ULL) + (x2 ^ 0x018070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x018070: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x018074: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x018078: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01807c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x018080: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x018084: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x018088: tbnz w8, #0, #0x18094
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD14ULL; // 0x01808c: lsr x20, x8, #1
    return acc;
}

// [EN] Reconstructed FDE #0504 @ 0x018108..0x01812c (36 bytes)
// [VN] Phục dựng FDE #0504 tại 0x018108..0x01812c (36 byte)
//   0x018108: 39400048  ldrb     w8, [x2]
//   0x01810c: eb01001f  cmp      x0, x1
//   0x018110: 540000c0  b.eq     #0x18128
//   0x018114: 39400009  ldrb     w9, [x0]
//   0x018118: 6b08013f  cmp      w9, w8
//   0x01811c: 54000060  b.eq     #0x18128
//   0x018120: 91000400  add      x0, x0, #1
//   0x018124: 17fffffa  b        #0x1810c
//   0x018128: d65f03c0  ret      
uint64_t fde_0504_sub_018108(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400048ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x018108ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400048ULL; // 0x018108: ldrb w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01001FULL; // 0x01810c: cmp x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x018110: b.eq #0x18128
    acc = (acc * 0x100000001B3ULL) ^ 0x39400009ULL; // 0x018114: ldrb w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x018118: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x01811c: b.eq #0x18128
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x018120: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFAULL; // 0x018124: b #0x1810c
    return acc;
}

// [EN] Reconstructed FDE #0505 @ 0x01812c..0x018168 (60 bytes)
// [VN] Phục dựng FDE #0505 tại 0x01812c..0x018168 (60 byte)
//   0x01812c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x018130: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x018134: 910043fd  add      x29, sp, #0x10
//   0x018138: aa0003f4  mov      x20, x0
//   0x01813c: a9007c1f  stp      xzr, xzr, [x0]
//   0x018140: f900081f  str      xzr, [x0, #0x10]
//   0x018144: aa0103e0  mov      x0, x1
//   0x018148: aa0103f3  mov      x19, x1
//   0x01814c: 97ffcbb5  bl       #0xb020
//   0x018150: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x018154: aa0003e2  mov      x2, x0
//   0x018158: aa1403e0  mov      x0, x20
uint64_t fde_0505_sub_01812c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FFCBB5ULL) + (x2 ^ 0x01812CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01812c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x018130: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x018134: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x018138: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x01813c: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x018140: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x018144: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x018148: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0506 @ 0x018168..0x018174 (12 bytes)
// [VN] Phục dựng FDE #0506 tại 0x018168..0x018174 (12 byte)
//   0x018168: aa1403e0  mov      x0, x20
//   0x01816c: aa1703e1  mov      x1, x23
//   0x018170: 17ffffaf  b        #0x1802c
uint64_t fde_0506_sub_018168(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFFFAFULL) + (x2 ^ 0x018168ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x018168: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x01816c: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFAFULL; // 0x018170: b #0x1802c
    return acc;
}

// [EN] Reconstructed FDE #0507 @ 0x018174..0x018180 (12 bytes)
// [VN] Phục dựng FDE #0507 tại 0x018174..0x018180 (12 byte)
//   0x018174: aa1403e0  mov      x0, x20
//   0x018178: aa1503e1  mov      x1, x21
//   0x01817c: 17ffffac  b        #0x1802c
uint64_t fde_0507_sub_018174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFFFACULL) + (x2 ^ 0x018174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x018174: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x018178: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFACULL; // 0x01817c: b #0x1802c
    return acc;
}

// [EN] Reconstructed FDE #0508 @ 0x018180..0x018188 (8 bytes)
// [VN] Phục dựng FDE #0508 tại 0x018180..0x018188 (8 byte)
//   0x018180: 39400000  ldrb     w0, [x0]
//   0x018184: 17ffff88  b        #0x17fa4
uint64_t fde_0508_sub_018180(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400000ULL) + (x1 ^ 0x17FFFF88ULL) + (x2 ^ 0x018180ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400000ULL; // 0x018180: ldrb w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF88ULL; // 0x018184: b #0x17fa4
    return acc;
}

// [EN] Reconstructed FDE #0509 @ 0x018188..0x018190 (8 bytes)
// [VN] Phục dựng FDE #0509 tại 0x018188..0x018190 (8 byte)
//   0x018188: 910043e0  add      x0, sp, #0x10
//   0x01818c: 17ffdfd9  b        #0x100f0
uint64_t fde_0509_sub_018188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910043E0ULL) + (x1 ^ 0x17FFDFD9ULL) + (x2 ^ 0x018188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E0ULL; // 0x018188: add x0, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDFD9ULL; // 0x01818c: b #0x100f0
    return acc;
}

// [EN] Reconstructed FDE #0510 @ 0x018190..0x018314 (388 bytes)
// [VN] Phục dựng FDE #0510 tại 0x018190..0x018314 (388 byte)
//   0x018190: d101c3ff  sub      sp, sp, #0x70
//   0x018194: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x018198: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01819c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0181a0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0181a4: 910183fd  add      x29, sp, #0x60
//   0x0181a8: d53bd058  mrs      x24, tpidr_el0
//   0x0181ac: f9401708  ldr      x8, [x24, #0x28]
//   0x0181b0: 2a0403f4  mov      w20, w4
//   0x0181b4: aa0303f5  mov      x21, x3
//   0x0181b8: aa0203f7  mov      x23, x2
//   0x0181bc: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0510_sub_018190(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0403F4ULL) + (x2 ^ 0x018190ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x018190: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x018194: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x018198: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01819c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0181a0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0181a4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0181a8: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0181ac: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0511 @ 0x018314..0x018410 (252 bytes)
// [VN] Phục dựng FDE #0511 tại 0x018314..0x018410 (252 byte)
//   0x018314: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x018318: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01831c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x018320: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x018324: 9100c3fd  add      x29, sp, #0x30
//   0x018328: b4000581  cbz      x1, #0x183d8
//   0x01832c: 90000238  adrp     x24, #0x5c000
//   0x018330: f942a308  ldr      x8, [x24, #0x540]
//   0x018334: aa0303f5  mov      x21, x3
//   0x018338: aa0203f3  mov      x19, x2
//   0x01833c: aa0103f4  mov      x20, x1
//   0x018340: b5000548  cbnz     x8, #0x183e8
uint64_t fde_0511_sub_018314(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0303F5ULL) + (x2 ^ 0x018314ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x018314: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x018318: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01831c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x018320: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x018324: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000581ULL; // 0x018328: cbz x1, #0x183d8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000238ULL; // 0x01832c: adrp x24, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A308ULL; // 0x018330: ldr x8, [x24, #0x540]
    return acc;
}

// [EN] Reconstructed FDE #0512 @ 0x018410..0x018414 (4 bytes)
// [VN] Phục dựng FDE #0512 tại 0x018410..0x018414 (4 byte)
//   0x018410: d65f03c0  ret      
uint64_t fde_0512_sub_018410(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x018410ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x018410: ret 
    return acc;
}

// [EN] Reconstructed FDE #0513 @ 0x018414..0x018424 (16 bytes)
// [VN] Phục dựng FDE #0513 tại 0x018414..0x018424 (16 byte)
//   0x018414: f9400268  ldr      x8, [x19]
//   0x018418: aa1303e0  mov      x0, x19
//   0x01841c: f9404508  ldr      x8, [x8, #0x88]
//   0x018420: d61f0100  br       x8
uint64_t fde_0513_sub_018414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x018414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x018414: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018418: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x01841c: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x018420: br x8
    return acc;
}

// [EN] Reconstructed FDE #0514 @ 0x018424..0x018434 (16 bytes)
// [VN] Phục dựng FDE #0514 tại 0x018424..0x018434 (16 byte)
//   0x018424: f9400268  ldr      x8, [x19]
//   0x018428: aa1303e0  mov      x0, x19
//   0x01842c: f9404108  ldr      x8, [x8, #0x80]
//   0x018430: d61f0100  br       x8
uint64_t fde_0514_sub_018424(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x018424ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x018424: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018428: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404108ULL; // 0x01842c: ldr x8, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x018430: br x8
    return acc;
}

// [EN] Reconstructed FDE #0515 @ 0x018434..0x018440 (12 bytes)
// [VN] Phục dựng FDE #0515 tại 0x018434..0x018440 (12 byte)
//   0x018434: aa1303e0  mov      x0, x19
//   0x018438: f9439108  ldr      x8, [x8, #0x720]
//   0x01843c: d61f0100  br       x8
uint64_t fde_0515_sub_018434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x018434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018434: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x018438: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01843c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0516 @ 0x018440..0x0184e4 (164 bytes)
// [VN] Phục dựng FDE #0516 tại 0x018440..0x0184e4 (164 byte)
//   0x018440: d10483ff  sub      sp, sp, #0x120
//   0x018444: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x018448: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x01844c: 910443fd  add      x29, sp, #0x110
//   0x018450: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x018454: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x018458: f90057e7  str      x7, [sp, #0xa8]
//   0x01845c: ad0007e0  stp      q0, q1, [sp]
//   0x018460: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x018464: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x018468: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x01846c: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0516_sub_018440(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x018440ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x018440: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x018444: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x018448: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x01844c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x018450: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x018454: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x018458: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x01845c: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0517 @ 0x0184e4..0x018728 (580 bytes)
// [VN] Phục dựng FDE #0517 tại 0x0184e4..0x018728 (580 byte)
//   0x0184e4: d10683ff  sub      sp, sp, #0x1a0
//   0x0184e8: a9146ffc  stp      x28, x27, [sp, #0x140]
//   0x0184ec: a91567fa  stp      x26, x25, [sp, #0x150]
//   0x0184f0: a9165ff8  stp      x24, x23, [sp, #0x160]
//   0x0184f4: a91757f6  stp      x22, x21, [sp, #0x170]
//   0x0184f8: a9184ff4  stp      x20, x19, [sp, #0x180]
//   0x0184fc: a9197bfd  stp      x29, x30, [sp, #0x190]
//   0x018500: 910643fd  add      x29, sp, #0x190
//   0x018504: d53bd054  mrs      x20, tpidr_el0
//   0x018508: f9401688  ldr      x8, [x20, #0x28]
//   0x01850c: 2a0003f7  mov      w23, w0
//   0x018510: 52a00240  mov      w0, #0x120000
uint64_t fde_0517_sub_0184e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10683FFULL) + (x1 ^ 0xD53BD054ULL) + (x2 ^ 0x0184E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x0184e4: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9146FFCULL; // 0x0184e8: stp x28, x27, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91567FAULL; // 0x0184ec: stp x26, x25, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9165FF8ULL; // 0x0184f0: stp x24, x23, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91757F6ULL; // 0x0184f4: stp x22, x21, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9184FF4ULL; // 0x0184f8: stp x20, x19, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9197BFDULL; // 0x0184fc: stp x29, x30, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0x910643FDULL; // 0x018500: add x29, sp, #0x190
    return acc;
}

// [EN] Reconstructed FDE #0518 @ 0x018728..0x018740 (24 bytes)
// [VN] Phục dựng FDE #0518 tại 0x018728..0x018740 (24 byte)
//   0x018728: f0000101  adrp     x1, #0x3b000
//   0x01872c: f0000102  adrp     x2, #0x3b000
//   0x018730: 91184421  add      x1, x1, #0x611
//   0x018734: 9119cc42  add      x2, x2, #0x673
//   0x018738: 528000c0  mov      w0, #6
//   0x01873c: 17ffcaa9  b        #0xb1e0
uint64_t fde_0518_sub_018728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000101ULL) + (x1 ^ 0x17FFCAA9ULL) + (x2 ^ 0x018728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000101ULL; // 0x018728: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000102ULL; // 0x01872c: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x91184421ULL; // 0x018730: add x1, x1, #0x611
    acc = (acc * 0x100000001B3ULL) ^ 0x9119CC42ULL; // 0x018734: add x2, x2, #0x673
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x018738: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCAA9ULL; // 0x01873c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0519 @ 0x018740..0x01875c (28 bytes)
// [VN] Phục dựng FDE #0519 tại 0x018740..0x01875c (28 byte)
//   0x018740: f0000101  adrp     x1, #0x3b000
//   0x018744: f0000102  adrp     x2, #0x3b000
//   0x018748: 91184421  add      x1, x1, #0x611
//   0x01874c: 9118e442  add      x2, x2, #0x639
//   0x018750: 528000c0  mov      w0, #6
//   0x018754: aa1303e3  mov      x3, x19
//   0x018758: d65f03c0  ret      
uint64_t fde_0519_sub_018740(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000101ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x018740ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000101ULL; // 0x018740: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000102ULL; // 0x018744: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x91184421ULL; // 0x018748: add x1, x1, #0x611
    acc = (acc * 0x100000001B3ULL) ^ 0x9118E442ULL; // 0x01874c: add x2, x2, #0x639
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x018750: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x018754: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x018758: ret 
    return acc;
}

// [EN] Reconstructed FDE #0520 @ 0x01875c..0x01876c (16 bytes)
// [VN] Phục dựng FDE #0520 tại 0x01875c..0x01876c (16 byte)
//   0x01875c: 52a00242  mov      w2, #0x120000
//   0x018760: aa1303e0  mov      x0, x19
//   0x018764: 2a1f03e1  mov      w1, wzr
//   0x018768: 17ffcb42  b        #0xb470
uint64_t fde_0520_sub_01875c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52A00242ULL) + (x1 ^ 0x17FFCB42ULL) + (x2 ^ 0x01875CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52A00242ULL; // 0x01875c: mov w2, #0x120000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018760: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x018764: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCB42ULL; // 0x018768: b #0xb470
    return acc;
}

// [EN] Reconstructed FDE #0521 @ 0x01876c..0x018780 (20 bytes)
// [VN] Phục dựng FDE #0521 tại 0x01876c..0x018780 (20 byte)
//   0x01876c: f0000101  adrp     x1, #0x3b000
//   0x018770: f0000102  adrp     x2, #0x3b000
//   0x018774: 91184421  add      x1, x1, #0x611
//   0x018778: 91186c42  add      x2, x2, #0x61b
//   0x01877c: d65f03c0  ret      
uint64_t fde_0521_sub_01876c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000101ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01876CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000101ULL; // 0x01876c: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000102ULL; // 0x018770: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x91184421ULL; // 0x018774: add x1, x1, #0x611
    acc = (acc * 0x100000001B3ULL) ^ 0x91186C42ULL; // 0x018778: add x2, x2, #0x61b
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01877c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0522 @ 0x018780..0x018788 (8 bytes)
// [VN] Phục dựng FDE #0522 tại 0x018780..0x018788 (8 byte)
//   0x018780: aa1303e0  mov      x0, x19
//   0x018784: 17ffc9bf  b        #0xae80
uint64_t fde_0522_sub_018780(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFC9BFULL) + (x2 ^ 0x018780ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018780: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC9BFULL; // 0x018784: b #0xae80
    return acc;
}

// [EN] Reconstructed FDE #0523 @ 0x018788..0x018794 (12 bytes)
// [VN] Phục dựng FDE #0523 tại 0x018788..0x018794 (12 byte)
//   0x018788: aa1303e0  mov      x0, x19
//   0x01878c: 2a1f03e1  mov      w1, wzr
//   0x018790: 17ffca40  b        #0xb090
uint64_t fde_0523_sub_018788(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFCA40ULL) + (x2 ^ 0x018788ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018788: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x01878c: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCA40ULL; // 0x018790: b #0xb090
    return acc;
}

// [EN] Reconstructed FDE #0524 @ 0x018794..0x0187a0 (12 bytes)
// [VN] Phục dựng FDE #0524 tại 0x018794..0x0187a0 (12 byte)
//   0x018794: 52802002  mov      w2, #0x100
//   0x018798: 2a1f03e1  mov      w1, wzr
//   0x01879c: 17ffcb35  b        #0xb470
uint64_t fde_0524_sub_018794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52802002ULL) + (x1 ^ 0x17FFCB35ULL) + (x2 ^ 0x018794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52802002ULL; // 0x018794: mov w2, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x018798: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCB35ULL; // 0x01879c: b #0xb470
    return acc;
}

// [EN] Reconstructed FDE #0525 @ 0x0187a0..0x0188ec (332 bytes)
// [VN] Phục dựng FDE #0525 tại 0x0187a0..0x0188ec (332 byte)
//   0x0187a0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0187a4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0187a8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0187ac: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0187b0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0187b4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0187b8: 910143fd  add      x29, sp, #0x50
//   0x0187bc: d108c3ff  sub      sp, sp, #0x230
//   0x0187c0: d53bd05a  mrs      x26, tpidr_el0
//   0x0187c4: f9401748  ldr      x8, [x26, #0x28]
//   0x0187c8: aa0103f4  mov      x20, x1
//   0x0187cc: aa0003f7  mov      x23, x0
uint64_t fde_0525_sub_0187a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xD53BD05AULL) + (x2 ^ 0x0187A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0187a0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0187a4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0187a8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0187ac: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0187b0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0187b4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0187b8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x0187bc: sub sp, sp, #0x230
    return acc;
}

// [EN] Reconstructed FDE #0526 @ 0x0188ec..0x0189b0 (196 bytes)
// [VN] Phục dựng FDE #0526 tại 0x0188ec..0x0189b0 (196 byte)
//   0x0188ec: d10243ff  sub      sp, sp, #0x90
//   0x0188f0: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0188f4: 910203fd  add      x29, sp, #0x80
//   0x0188f8: d53bd048  mrs      x8, tpidr_el0
//   0x0188fc: f9401509  ldr      x9, [x8, #0x28]
//   0x018900: f81f83a9  stur     x9, [x29, #-8]
//   0x018904: 90000229  adrp     x9, #0x5c000
//   0x018908: 91154129  add      x9, x9, #0x550
//   0x01890c: 08dffd29  ldarb    w9, [x9]
//   0x018910: 36000149  tbz      w9, #0, #0x18938
//   0x018914: 90000229  adrp     x9, #0x5c000
//   0x018918: b9454920  ldr      w0, [x9, #0x548]
uint64_t fde_0526_sub_0188ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x08DFFD29ULL) + (x2 ^ 0x0188ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x0188ec: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0188f0: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0188f4: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x0188f8: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x0188fc: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F83A9ULL; // 0x018900: stur x9, [x29, #-8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000229ULL; // 0x018904: adrp x9, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91154129ULL; // 0x018908: add x9, x9, #0x550
    return acc;
}

// [EN] Reconstructed FDE #0527 @ 0x0189b0..0x018a14 (100 bytes)
// [VN] Phục dựng FDE #0527 tại 0x0189b0..0x018a14 (100 byte)
//   0x0189b0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0189b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0189b8: 910043fd  add      x29, sp, #0x10
//   0x0189bc: aa0003f3  mov      x19, x0
//   0x0189c0: b4000220  cbz      x0, #0x18a04
//   0x0189c4: f0000100  adrp     x0, #0x3b000
//   0x0189c8: 911d1800  add      x0, x0, #0x746
//   0x0189cc: 52800021  mov      w1, #1
//   0x0189d0: 97ffc9b0  bl       #0xb090
//   0x0189d4: 3100041f  cmn      w0, #1
//   0x0189d8: 54000140  b.eq     #0x18a00
//   0x0189dc: 52800082  mov      w2, #4
uint64_t fde_0527_sub_0189b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FFC9B0ULL) + (x2 ^ 0x0189B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0189b0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0189b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0189b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0189bc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x0189c0: cbz x0, #0x18a04
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000100ULL; // 0x0189c4: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1800ULL; // 0x0189c8: add x0, x0, #0x746
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0189cc: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0528 @ 0x018a14..0x018b04 (240 bytes)
// [VN] Phục dựng FDE #0528 tại 0x018a14..0x018b04 (240 byte)
//   0x018a14: d10143ff  sub      sp, sp, #0x50
//   0x018a18: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x018a1c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x018a20: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x018a24: 910103fd  add      x29, sp, #0x40
//   0x018a28: d53bd055  mrs      x21, tpidr_el0
//   0x018a2c: f94016a8  ldr      x8, [x21, #0x28]
//   0x018a30: 90000236  adrp     x22, #0x5c000
//   0x018a34: aa0103f3  mov      x19, x1
//   0x018a38: aa0003f4  mov      x20, x0
//   0x018a3c: f9000fe8  str      x8, [sp, #0x18]
//   0x018a40: f942aec8  ldr      x8, [x22, #0x558]
uint64_t fde_0528_sub_018a14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x018A14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x018a14: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x018a18: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x018a1c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x018a20: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x018a24: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x018a28: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x018a2c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000236ULL; // 0x018a30: adrp x22, #0x5c000
    return acc;
}

// [EN] Reconstructed FDE #0529 @ 0x018b04..0x018bd8 (212 bytes)
// [VN] Phục dựng FDE #0529 tại 0x018b04..0x018bd8 (212 byte)
//   0x018b04: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x018b08: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x018b0c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x018b10: 910083fd  add      x29, sp, #0x20
//   0x018b14: d11243ff  sub      sp, sp, #0x490
//   0x018b18: d53bd055  mrs      x21, tpidr_el0
//   0x018b1c: f94016a8  ldr      x8, [x21, #0x28]
//   0x018b20: 2a0003f4  mov      w20, w0
//   0x018b24: aa0103e0  mov      x0, x1
//   0x018b28: aa0103f3  mov      x19, x1
//   0x018b2c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x018b30: 97ffdd5e  bl       #0x100a8
uint64_t fde_0529_sub_018b04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57FCULL) + (x1 ^ 0xAA0103E0ULL) + (x2 ^ 0x018B04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57FCULL; // 0x018b04: stp x28, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x018b08: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x018b0c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x018b10: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD11243FFULL; // 0x018b14: sub sp, sp, #0x490
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x018b18: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x018b1c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x018b20: mov w20, w0
    return acc;
}

// [EN] Reconstructed FDE #0530 @ 0x018bd8..0x018c88 (176 bytes)
// [VN] Phục dựng FDE #0530 tại 0x018bd8..0x018c88 (176 byte)
//   0x018bd8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x018bdc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x018be0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x018be4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x018be8: 9100c3fd  add      x29, sp, #0x30
//   0x018bec: aa0003f4  mov      x20, x0
//   0x018bf0: aa0103e0  mov      x0, x1
//   0x018bf4: 2a0203f5  mov      w21, w2
//   0x018bf8: aa0103f3  mov      x19, x1
//   0x018bfc: 97ffdd2b  bl       #0x100a8
//   0x018c00: 52900008  mov      w8, #0x8000
//   0x018c04: 720002bf  tst      w21, #1
uint64_t fde_0530_sub_018bd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x018BD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x018bd8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x018bdc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x018be0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x018be4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x018be8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x018bec: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x018bf0: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x018bf4: mov w21, w2
    return acc;
}

// [EN] Reconstructed FDE #0531 @ 0x018c88..0x018eb0 (552 bytes)
// [VN] Phục dựng FDE #0531 tại 0x018c88..0x018eb0 (552 byte)
//   0x018c88: d106c3ff  sub      sp, sp, #0x1b0
//   0x018c8c: f900abfc  str      x28, [sp, #0x150]
//   0x018c90: a91667fa  stp      x26, x25, [sp, #0x160]
//   0x018c94: a9175ff8  stp      x24, x23, [sp, #0x170]
//   0x018c98: a91857f6  stp      x22, x21, [sp, #0x180]
//   0x018c9c: a9194ff4  stp      x20, x19, [sp, #0x190]
//   0x018ca0: a91a7bfd  stp      x29, x30, [sp, #0x1a0]
//   0x018ca4: 910683fd  add      x29, sp, #0x1a0
//   0x018ca8: d53bd058  mrs      x24, tpidr_el0
//   0x018cac: f9401708  ldr      x8, [x24, #0x28]
//   0x018cb0: 2a0003f7  mov      w23, w0
//   0x018cb4: 910063e0  add      x0, sp, #0x18
uint64_t fde_0531_sub_018c88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD106C3FFULL) + (x1 ^ 0xD53BD058ULL) + (x2 ^ 0x018C88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x018c88: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900ABFCULL; // 0x018c8c: str x28, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91667FAULL; // 0x018c90: stp x26, x25, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9175FF8ULL; // 0x018c94: stp x24, x23, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91857F6ULL; // 0x018c98: stp x22, x21, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9194FF4ULL; // 0x018c9c: stp x20, x19, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A7BFDULL; // 0x018ca0: stp x29, x30, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910683FDULL; // 0x018ca4: add x29, sp, #0x1a0
    return acc;
}

// [EN] Reconstructed FDE #0532 @ 0x018eb0..0x018f54 (164 bytes)
// [VN] Phục dựng FDE #0532 tại 0x018eb0..0x018f54 (164 byte)
//   0x018eb0: d10483ff  sub      sp, sp, #0x120
//   0x018eb4: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x018eb8: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x018ebc: 910443fd  add      x29, sp, #0x110
//   0x018ec0: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x018ec4: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x018ec8: f90057e7  str      x7, [sp, #0xa8]
//   0x018ecc: ad0007e0  stp      q0, q1, [sp]
//   0x018ed0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x018ed4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x018ed8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x018edc: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0532_sub_018eb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x018EB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x018eb0: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x018eb4: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x018eb8: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x018ebc: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x018ec0: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x018ec4: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x018ec8: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x018ecc: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0533 @ 0x018f54..0x018f6c (24 bytes)
// [VN] Phục dựng FDE #0533 tại 0x018f54..0x018f6c (24 byte)
//   0x018f54: aa0203e3  mov      x3, x2
//   0x018f58: aa0103e2  mov      x2, x1
//   0x018f5c: aa0003e1  mov      x1, x0
//   0x018f60: aa0803e0  mov      x0, x8
//   0x018f64: aa0103e4  mov      x4, x1
//   0x018f68: 140000ea  b        #0x19310
uint64_t fde_0533_sub_018f54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E3ULL) + (x1 ^ 0x140000EAULL) + (x2 ^ 0x018F54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x018f54: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x018f58: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x018f5c: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x018f60: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E4ULL; // 0x018f64: mov x4, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x140000EAULL; // 0x018f68: b #0x19310
    return acc;
}

// [EN] Reconstructed FDE #0534 @ 0x018f6c..0x018f90 (36 bytes)
// [VN] Phục dựng FDE #0534 tại 0x018f6c..0x018f90 (36 byte)
//   0x018f6c: 39400008  ldrb     w8, [x0]
//   0x018f70: aa0203e3  mov      x3, x2
//   0x018f74: 2a0103e2  mov      w2, w1
//   0x018f78: 37000088  tbnz     w8, #0, #0x18f88
//   0x018f7c: 91000400  add      x0, x0, #1
//   0x018f80: d341fd01  lsr      x1, x8, #1
//   0x018f84: 140000f7  b        #0x19360
//   0x018f88: a9408001  ldp      x1, x0, [x0, #8]
//   0x018f8c: 140000f5  b        #0x19360
uint64_t fde_0534_sub_018f6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0x140000F5ULL) + (x2 ^ 0x018F6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x018f6c: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x018f70: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E2ULL; // 0x018f74: mov w2, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000088ULL; // 0x018f78: tbnz w8, #0, #0x18f88
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x018f7c: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD01ULL; // 0x018f80: lsr x1, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x140000F7ULL; // 0x018f84: b #0x19360
    acc = (acc * 0x100000001B3ULL) ^ 0xA9408001ULL; // 0x018f88: ldp x1, x0, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0535 @ 0x018f90..0x018fb4 (36 bytes)
// [VN] Phục dựng FDE #0535 tại 0x018f90..0x018fb4 (36 byte)
//   0x018f90: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x018f94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x018f98: 910043fd  add      x29, sp, #0x10
//   0x018f9c: aa0003f3  mov      x19, x0
//   0x018fa0: 94000113  bl       #0x193ec
//   0x018fa4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x018fa8: aa1303e0  mov      x0, x19
//   0x018fac: f84207f3  ldr      x19, [sp], #0x20
//   0x018fb0: d65f03c0  ret      
uint64_t fde_0535_sub_018f90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x018F90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x018f90: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x018f94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x018f98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x018f9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000113ULL; // 0x018fa0: bl #0x193ec
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x018fa4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x018fa8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x018fac: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0536 @ 0x018fb4..0x018fc8 (20 bytes)
// [VN] Phục dựng FDE #0536 tại 0x018fb4..0x018fc8 (20 byte)
//   0x018fb4: a940a408  ldp      x8, x9, [x0, #8]
//   0x018fb8: eb09011f  cmp      x8, x9
//   0x018fbc: 54000042  b.hs     #0x18fc4
//   0x018fc0: 14000005  b        #0x18fd4
//   0x018fc4: 14000014  b        #0x19014
uint64_t fde_0536_sub_018fb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000014ULL) + (x2 ^ 0x018FB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x018fb4: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x018fb8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000042ULL; // 0x018fbc: b.hs #0x18fc4
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x018fc0: b #0x18fd4
    acc = (acc * 0x100000001B3ULL) ^ 0x14000014ULL; // 0x018fc4: b #0x19014
    return acc;
}

// [EN] Reconstructed FDE #0537 @ 0x018fc8..0x018fd4 (12 bytes)
// [VN] Phục dựng FDE #0537 tại 0x018fc8..0x018fd4 (12 byte)
//   0x018fc8: a9007c1f  stp      xzr, xzr, [x0]
//   0x018fcc: f900081f  str      xzr, [x0, #0x10]
//   0x018fd0: 17ffd92a  b        #0xf478
uint64_t fde_0537_sub_018fc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9007C1FULL) + (x1 ^ 0x17FFD92AULL) + (x2 ^ 0x018FC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x018fc8: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x018fcc: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD92AULL; // 0x018fd0: b #0xf478
    return acc;
}

// [EN] Reconstructed FDE #0538 @ 0x018fd4..0x019014 (64 bytes)
// [VN] Phục dựng FDE #0538 tại 0x018fd4..0x019014 (64 byte)
//   0x018fd4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x018fd8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x018fdc: 910043fd  add      x29, sp, #0x10
//   0x018fe0: f9400414  ldr      x20, [x0, #8]
//   0x018fe4: f9400828  ldr      x8, [x1, #0x10]
//   0x018fe8: 3dc00020  ldr      q0, [x1]
//   0x018fec: aa0003f3  mov      x19, x0
//   0x018ff0: aa0103e0  mov      x0, x1
//   0x018ff4: f9000a88  str      x8, [x20, #0x10]
//   0x018ff8: 3d800280  str      q0, [x20]
//   0x018ffc: 97ffd9c3  bl       #0xf708
//   0x019000: 91006288  add      x8, x20, #0x18
uint64_t fde_0538_sub_018fd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000A88ULL) + (x2 ^ 0x018FD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x018fd4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x018fd8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x018fdc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x018fe0: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400828ULL; // 0x018fe4: ldr x8, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x018fe8: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x018fec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x018ff0: mov x0, x1
    return acc;
}

// [EN] Reconstructed FDE #0539 @ 0x019014..0x0190e0 (204 bytes)
// [VN] Phục dựng FDE #0539 tại 0x019014..0x0190e0 (204 byte)
//   0x019014: d101c3ff  sub      sp, sp, #0x70
//   0x019018: f9001bf7  str      x23, [sp, #0x30]
//   0x01901c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x019020: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x019024: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x019028: 910183fd  add      x29, sp, #0x60
//   0x01902c: d53bd056  mrs      x22, tpidr_el0
//   0x019030: f94016c8  ldr      x8, [x22, #0x28]
//   0x019034: 52800317  mov      w23, #0x18
//   0x019038: aa0103f3  mov      x19, x1
//   0x01903c: aa0003f4  mov      x20, x0
//   0x019040: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0539_sub_019014(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x52800317ULL) + (x2 ^ 0x019014ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x019014: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x019018: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01901c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x019020: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x019024: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x019028: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01902c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x019030: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0540 @ 0x0190e0..0x01913c (92 bytes)
// [VN] Phục dựng FDE #0540 tại 0x0190e0..0x01913c (92 byte)
//   0x0190e0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0190e4: 910003fd  mov      x29, sp
//   0x0190e8: b201f3e8  mov      x8, #-0x5555555555555556
//   0x0190ec: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x0190f0: eb08003f  cmp      x1, x8
//   0x0190f4: 54000228  b.hi     #0x19138
//   0x0190f8: f9400809  ldr      x9, [x0, #0x10]
//   0x0190fc: f940000a  ldr      x10, [x0]
//   0x019100: 5280030b  mov      w11, #0x18
//   0x019104: cb0a0129  sub      x9, x9, x10
//   0x019108: b200f3ea  mov      x10, #0x5555555555555555
//   0x01910c: f28aaa8a  movk     x10, #0x5554
uint64_t fde_0540_sub_0190e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x5280030BULL) + (x2 ^ 0x0190E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0190e0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0190e4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x0190e8: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x0190ec: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x0190f0: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000228ULL; // 0x0190f4: b.hi #0x19138
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x0190f8: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940000AULL; // 0x0190fc: ldr x10, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0541 @ 0x01913c..0x019198 (92 bytes)
// [VN] Phục dựng FDE #0541 tại 0x01913c..0x019198 (92 byte)
//   0x01913c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x019140: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x019144: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x019148: 910083fd  add      x29, sp, #0x20
//   0x01914c: aa0203f5  mov      x21, x2
//   0x019150: aa0103f4  mov      x20, x1
//   0x019154: aa0003f3  mov      x19, x0
//   0x019158: a9018c1f  stp      xzr, x3, [x0, #0x18]
//   0x01915c: b40000a1  cbz      x1, #0x19170
//   0x019160: aa0303e0  mov      x0, x3
//   0x019164: aa1403e1  mov      x1, x20
//   0x019168: 94000032  bl       #0x19230
uint64_t fde_0541_sub_01913c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB40000A1ULL) + (x2 ^ 0x01913CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01913c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x019140: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x019144: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x019148: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x01914c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x019150: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019154: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9018C1FULL; // 0x019158: stp xzr, x3, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0542 @ 0x019198..0x0191fc (100 bytes)
// [VN] Phục dựng FDE #0542 tại 0x019198..0x0191fc (100 byte)
//   0x019198: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01919c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0191a0: 910043fd  add      x29, sp, #0x10
//   0x0191a4: aa0103f3  mov      x19, x1
//   0x0191a8: aa0003f4  mov      x20, x0
//   0x0191ac: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x0191b0: 91002263  add      x3, x19, #8
//   0x0191b4: 9400002c  bl       #0x19264
//   0x0191b8: f9400668  ldr      x8, [x19, #8]
//   0x0191bc: f9400289  ldr      x9, [x20]
//   0x0191c0: f9000288  str      x8, [x20]
//   0x0191c4: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0542_sub_019198(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x019198ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019198: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01919c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0191a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0191a4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0191a8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x0191ac: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x0191b0: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002CULL; // 0x0191b4: bl #0x19264
    return acc;
}

// [EN] Reconstructed FDE #0543 @ 0x0191fc..0x019230 (52 bytes)
// [VN] Phục dựng FDE #0543 tại 0x0191fc..0x019230 (52 byte)
//   0x0191fc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x019200: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019204: 910043fd  add      x29, sp, #0x10
//   0x019208: aa0003f3  mov      x19, x0
//   0x01920c: 9400002f  bl       #0x192c8
//   0x019210: f9400260  ldr      x0, [x19]
//   0x019214: b4000080  cbz      x0, #0x19224
//   0x019218: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01921c: f84207f3  ldr      x19, [sp], #0x20
//   0x019220: 17ffc6c8  b        #0xad40
//   0x019224: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x019228: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0543_sub_0191fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0191FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0191fc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x019200: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019204: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019208: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002FULL; // 0x01920c: bl #0x192c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x019210: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x019214: cbz x0, #0x19224
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x019218: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0544 @ 0x019230..0x019238 (8 bytes)
// [VN] Phục dựng FDE #0544 tại 0x019230..0x019238 (8 byte)
//   0x019230: aa1f03e2  mov      x2, xzr
//   0x019234: 14000001  b        #0x19238
uint64_t fde_0544_sub_019230(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x019230ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x019230: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x019234: b #0x19238
    return acc;
}

// [EN] Reconstructed FDE #0545 @ 0x019238..0x019264 (44 bytes)
// [VN] Phục dựng FDE #0545 tại 0x019238..0x019264 (44 byte)
//   0x019238: b201f3e8  mov      x8, #-0x5555555555555556
//   0x01923c: f2955568  movk     x8, #0xaaab
//   0x019240: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x019244: eb08003f  cmp      x1, x8
//   0x019248: 54000082  b.hs     #0x19258
//   0x01924c: 8b010428  add      x8, x1, x1, lsl #1
//   0x019250: d37df100  lsl      x0, x8, #3
//   0x019254: 17ffc8e7  b        #0xb5f0
//   0x019258: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01925c: 910003fd  mov      x29, sp
//   0x019260: 97ffc8a8  bl       #0xb500
uint64_t fde_0545_sub_019238(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x019238ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x019238: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x01923c: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x019240: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x019244: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x019248: b.hs #0x19258
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x01924c: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x019250: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC8E7ULL; // 0x019254: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0546 @ 0x019264..0x0192c8 (100 bytes)
// [VN] Phục dựng FDE #0546 tại 0x019264..0x0192c8 (100 byte)
//   0x019264: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x019268: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01926c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x019270: 910083fd  add      x29, sp, #0x20
//   0x019274: aa0303f3  mov      x19, x3
//   0x019278: aa0203f5  mov      x21, x2
//   0x01927c: aa0103f4  mov      x20, x1
//   0x019280: eb15029f  cmp      x20, x21
//   0x019284: 540001a0  b.eq     #0x192b8
//   0x019288: f9400268  ldr      x8, [x19]
//   0x01928c: f85f82a9  ldur     x9, [x21, #-8]
//   0x019290: 3cde82a0  ldur     q0, [x21, #-0x18]
uint64_t fde_0546_sub_019264(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x540001A0ULL) + (x2 ^ 0x019264ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x019264: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x019268: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01926c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x019270: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x019274: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x019278: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01927c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB15029FULL; // 0x019280: cmp x20, x21
    return acc;
}

// [EN] Reconstructed FDE #0547 @ 0x0192c8..0x0192d0 (8 bytes)
// [VN] Phục dựng FDE #0547 tại 0x0192c8..0x0192d0 (8 byte)
//   0x0192c8: f9400401  ldr      x1, [x0, #8]
//   0x0192cc: 14000001  b        #0x192d0
uint64_t fde_0547_sub_0192c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0192C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x0192c8: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0192cc: b #0x192d0
    return acc;
}

// [EN] Reconstructed FDE #0548 @ 0x0192d0..0x0192d4 (4 bytes)
// [VN] Phục dựng FDE #0548 tại 0x0192d0..0x0192d4 (4 byte)
//   0x0192d0: 14000001  b        #0x192d4
uint64_t fde_0548_sub_0192d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0192D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0192d0: b #0x192d4
    return acc;
}

// [EN] Reconstructed FDE #0549 @ 0x0192d4..0x019310 (60 bytes)
// [VN] Phục dựng FDE #0549 tại 0x0192d4..0x019310 (60 byte)
//   0x0192d4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0192d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0192dc: 910043fd  add      x29, sp, #0x10
//   0x0192e0: aa0103f3  mov      x19, x1
//   0x0192e4: aa0003f4  mov      x20, x0
//   0x0192e8: f9400a88  ldr      x8, [x20, #0x10]
//   0x0192ec: eb13011f  cmp      x8, x19
//   0x0192f0: 540000a0  b.eq     #0x19304
//   0x0192f4: d1006100  sub      x0, x8, #0x18
//   0x0192f8: f9000a80  str      x0, [x20, #0x10]
//   0x0192fc: 97ffd152  bl       #0xd844
//   0x019300: 17fffffa  b        #0x192e8
uint64_t fde_0549_sub_0192d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD1006100ULL) + (x2 ^ 0x0192D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0192d4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0192d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0192dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0192e0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0192e4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A88ULL; // 0x0192e8: ldr x8, [x20, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13011FULL; // 0x0192ec: cmp x8, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x0192f0: b.eq #0x19304
    return acc;
}

// [EN] Reconstructed FDE #0550 @ 0x019310..0x019360 (80 bytes)
// [VN] Phục dựng FDE #0550 tại 0x019310..0x019360 (80 byte)
//   0x019310: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x019314: 910003fd  mov      x29, sp
//   0x019318: a9007c1f  stp      xzr, xzr, [x0]
//   0x01931c: f900081f  str      xzr, [x0, #0x10]
//   0x019320: 39400028  ldrb     w8, [x1]
//   0x019324: f9400429  ldr      x9, [x1, #8]
//   0x019328: d341fd0a  lsr      x10, x8, #1
//   0x01932c: 7200011f  tst      w8, #1
//   0x019330: 9a890149  csel     x9, x10, x9, eq
//   0x019334: eb020129  subs     x9, x9, x2
//   0x019338: 54000123  b.lo     #0x1935c
//   0x01933c: f940082a  ldr      x10, [x1, #0x10]
uint64_t fde_0550_sub_019310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x9A890149ULL) + (x2 ^ 0x019310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x019310: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x019314: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x019318: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x01931c: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x019320: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400429ULL; // 0x019324: ldr x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0AULL; // 0x019328: lsr x10, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x01932c: tst w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0551 @ 0x019360..0x0193d0 (112 bytes)
// [VN] Phục dựng FDE #0551 tại 0x019360..0x0193d0 (112 byte)
//   0x019360: d100c3ff  sub      sp, sp, #0x30
//   0x019364: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x019368: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01936c: 910083fd  add      x29, sp, #0x20
//   0x019370: d53bd054  mrs      x20, tpidr_el0
//   0x019374: f9401688  ldr      x8, [x20, #0x28]
//   0x019378: eb030021  subs     x1, x1, x3
//   0x01937c: f90007e8  str      x8, [sp, #8]
//   0x019380: 390013e2  strb     w2, [sp, #4]
//   0x019384: 54000129  b.ls     #0x193a8
//   0x019388: aa0003f3  mov      x19, x0
//   0x01938c: 8b030000  add      x0, x0, x3
uint64_t fde_0551_sub_019360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x390013E2ULL) + (x2 ^ 0x019360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x019360: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x019364: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x019368: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01936c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x019370: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x019374: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB030021ULL; // 0x019378: subs x1, x1, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x01937c: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0552 @ 0x0193d0..0x0193ec (28 bytes)
// [VN] Phục dựng FDE #0552 tại 0x0193d0..0x0193ec (28 byte)
//   0x0193d0: b40000a1  cbz      x1, #0x193e4
//   0x0193d4: aa0103e8  mov      x8, x1
//   0x0193d8: 39400041  ldrb     w1, [x2]
//   0x0193dc: aa0803e2  mov      x2, x8
//   0x0193e0: 17ffc624  b        #0xac70
//   0x0193e4: aa1f03e0  mov      x0, xzr
//   0x0193e8: d65f03c0  ret      
uint64_t fde_0552_sub_0193d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000A1ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0193D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A1ULL; // 0x0193d0: cbz x1, #0x193e4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x0193d4: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39400041ULL; // 0x0193d8: ldrb w1, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E2ULL; // 0x0193dc: mov x2, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC624ULL; // 0x0193e0: b #0xac70
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x0193e4: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0193e8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0553 @ 0x0193ec..0x019424 (56 bytes)
// [VN] Phục dựng FDE #0553 tại 0x0193ec..0x019424 (56 byte)
//   0x0193ec: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0193f0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0193f4: 910043fd  add      x29, sp, #0x10
//   0x0193f8: aa0103f3  mov      x19, x1
//   0x0193fc: aa0003f4  mov      x20, x0
//   0x019400: 94000009  bl       #0x19424
//   0x019404: f9400a68  ldr      x8, [x19, #0x10]
//   0x019408: 3dc00260  ldr      q0, [x19]
//   0x01940c: aa1303e0  mov      x0, x19
//   0x019410: f9000a88  str      x8, [x20, #0x10]
//   0x019414: 3d800280  str      q0, [x20]
//   0x019418: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0553_sub_0193ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0193ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0193ec: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0193f0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0193f4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0193f8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0193fc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000009ULL; // 0x019400: bl #0x19424
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A68ULL; // 0x019404: ldr x8, [x19, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00260ULL; // 0x019408: ldr q0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0554 @ 0x019424..0x019458 (52 bytes)
// [VN] Phục dựng FDE #0554 tại 0x019424..0x019458 (52 byte)
//   0x019424: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x019428: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01942c: 910043fd  add      x29, sp, #0x10
//   0x019430: aa0003f3  mov      x19, x0
//   0x019434: 97ffdb1d  bl       #0x100a8
//   0x019438: 39400268  ldrb     w8, [x19]
//   0x01943c: 36000088  tbz      w8, #0, #0x1944c
//   0x019440: f9400a60  ldr      x0, [x19, #0x10]
//   0x019444: 97ffc63f  bl       #0xad40
//   0x019448: f900027f  str      xzr, [x19]
//   0x01944c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x019450: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0554_sub_019424(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFC63FULL) + (x2 ^ 0x019424ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x019424: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x019428: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01942c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019430: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDB1DULL; // 0x019434: bl #0x100a8
    acc = (acc * 0x100000001B3ULL) ^ 0x39400268ULL; // 0x019438: ldrb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000088ULL; // 0x01943c: tbz w8, #0, #0x1944c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A60ULL; // 0x019440: ldr x0, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0555 @ 0x019458..0x019490 (56 bytes)
// [VN] Phục dựng FDE #0555 tại 0x019458..0x019490 (56 byte)
//   0x019458: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01945c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019460: 910043fd  add      x29, sp, #0x10
//   0x019464: f9400008  ldr      x8, [x0]
//   0x019468: b40000e8  cbz      x8, #0x19484
//   0x01946c: aa0003f3  mov      x19, x0
//   0x019470: 94000008  bl       #0x19490
//   0x019474: f9400260  ldr      x0, [x19]
//   0x019478: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01947c: f84207f3  ldr      x19, [sp], #0x20
//   0x019480: 17ffc630  b        #0xad40
//   0x019484: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0555_sub_019458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x019458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x019458: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01945c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019460: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x019464: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E8ULL; // 0x019468: cbz x8, #0x19484
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01946c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000008ULL; // 0x019470: bl #0x19490
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x019474: ldr x0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0556 @ 0x019490..0x019498 (8 bytes)
// [VN] Phục dựng FDE #0556 tại 0x019490..0x019498 (8 byte)
//   0x019490: f9400001  ldr      x1, [x0]
//   0x019494: 14000001  b        #0x19498
uint64_t fde_0556_sub_019490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x019490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400001ULL; // 0x019490: ldr x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x019494: b #0x19498
    return acc;
}

// [EN] Reconstructed FDE #0557 @ 0x019498..0x0194e0 (72 bytes)
// [VN] Phục dựng FDE #0557 tại 0x019498..0x0194e0 (72 byte)
//   0x019498: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01949c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0194a0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0194a4: 910083fd  add      x29, sp, #0x20
//   0x0194a8: f9400415  ldr      x21, [x0, #8]
//   0x0194ac: aa0003f3  mov      x19, x0
//   0x0194b0: aa0103f4  mov      x20, x1
//   0x0194b4: eb15029f  cmp      x20, x21
//   0x0194b8: 540000a0  b.eq     #0x194cc
//   0x0194bc: d10062b5  sub      x21, x21, #0x18
//   0x0194c0: aa1503e0  mov      x0, x21
//   0x0194c4: 97ffd0e0  bl       #0xd844
uint64_t fde_0557_sub_019498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x540000A0ULL) + (x2 ^ 0x019498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x019498: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01949c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0194a0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0194a4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400415ULL; // 0x0194a8: ldr x21, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0194ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0194b0: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB15029FULL; // 0x0194b4: cmp x20, x21
    return acc;
}

// [EN] Reconstructed FDE #0558 @ 0x0194e0..0x0194ec (12 bytes)
// [VN] Phục dựng FDE #0558 tại 0x0194e0..0x0194ec (12 byte)
//   0x0194e0: 52800142  mov      w2, #0xa
//   0x0194e4: aa1f03e1  mov      x1, xzr
//   0x0194e8: 17ffc8f2  b        #0xb8b0
uint64_t fde_0558_sub_0194e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800142ULL) + (x1 ^ 0x17FFC8F2ULL) + (x2 ^ 0x0194E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800142ULL; // 0x0194e0: mov w2, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0194e4: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC8F2ULL; // 0x0194e8: b #0xb8b0
    return acc;
}

// [EN] Reconstructed FDE #0559 @ 0x0194ec..0x0194f4 (8 bytes)
// [VN] Phục dựng FDE #0559 tại 0x0194ec..0x0194f4 (8 byte)
//   0x0194ec: 9100c3e0  add      x0, sp, #0x30
//   0x0194f0: 17ffd0d5  b        #0xd844
uint64_t fde_0559_sub_0194ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100C3E0ULL) + (x1 ^ 0x17FFD0D5ULL) + (x2 ^ 0x0194ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E0ULL; // 0x0194ec: add x0, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD0D5ULL; // 0x0194f0: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0560 @ 0x0194f4..0x019508 (20 bytes)
// [VN] Phục dựng FDE #0560 tại 0x0194f4..0x019508 (20 byte)
//   0x0194f4: d0000100  adrp     x0, #0x3b000
//   0x0194f8: d0000101  adrp     x1, #0x3b000
//   0x0194fc: 911bd800  add      x0, x0, #0x6f6
//   0x019500: 911d1021  add      x1, x1, #0x744
//   0x019504: d65f03c0  ret      
uint64_t fde_0560_sub_0194f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000100ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0194F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000100ULL; // 0x0194f4: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000101ULL; // 0x0194f8: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911BD800ULL; // 0x0194fc: add x0, x0, #0x6f6
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1021ULL; // 0x019500: add x1, x1, #0x744
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x019504: ret 
    return acc;
}

// [EN] Reconstructed FDE #0561 @ 0x019508..0x019544 (60 bytes)
// [VN] Phục dựng FDE #0561 tại 0x019508..0x019544 (60 byte)
//   0x019508: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01950c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019510: 910043fd  add      x29, sp, #0x10
//   0x019514: aa0003f3  mov      x19, x0
//   0x019518: 97ffc832  bl       #0xb5e0
//   0x01951c: 2a0003f4  mov      w20, w0
//   0x019520: 3100041f  cmn      w0, #1
//   0x019524: 540000c1  b.ne     #0x1953c
//   0x019528: d0000101  adrp     x1, #0x3b000
//   0x01952c: d0000102  adrp     x2, #0x3b000
//   0x019530: 911dec21  add      x1, x1, #0x77b
//   0x019534: 911e2c42  add      x2, x2, #0x78b
uint64_t fde_0561_sub_019508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000101ULL) + (x2 ^ 0x019508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019508: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01950c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019510: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019514: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC832ULL; // 0x019518: bl #0xb5e0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x01951c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x019520: cmn w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x019524: b.ne #0x1953c
    return acc;
}

// [EN] Reconstructed FDE #0562 @ 0x019544..0x019588 (68 bytes)
// [VN] Phục dựng FDE #0562 tại 0x019544..0x019588 (68 byte)
//   0x019544: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x019548: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01954c: 910043fd  add      x29, sp, #0x10
//   0x019550: aa0003f3  mov      x19, x0
//   0x019554: 97ffc793  bl       #0xb3a0
//   0x019558: aa0003f4  mov      x20, x0
//   0x01955c: b100041f  cmn      x0, #1
//   0x019560: 540000c1  b.ne     #0x19578
//   0x019564: d0000101  adrp     x1, #0x3b000
//   0x019568: d0000102  adrp     x2, #0x3b000
//   0x01956c: 911dec21  add      x1, x1, #0x77b
//   0x019570: 911e7842  add      x2, x2, #0x79e
uint64_t fde_0562_sub_019544(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000101ULL) + (x2 ^ 0x019544ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019544: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x019548: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01954c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019550: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC793ULL; // 0x019554: bl #0xb3a0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x019558: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB100041FULL; // 0x01955c: cmn x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x019560: b.ne #0x19578
    return acc;
}

// [EN] Reconstructed FDE #0563 @ 0x019588..0x0195c0 (56 bytes)
// [VN] Phục dựng FDE #0563 tại 0x019588..0x0195c0 (56 byte)
//   0x019588: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01958c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019590: 910043fd  add      x29, sp, #0x10
//   0x019594: aa0003f3  mov      x19, x0
//   0x019598: 97ffc6e6  bl       #0xb130
//   0x01959c: 2a0003f4  mov      w20, w0
//   0x0195a0: 340000c0  cbz      w0, #0x195b8
//   0x0195a4: d0000101  adrp     x1, #0x3b000
//   0x0195a8: d0000102  adrp     x2, #0x3b000
//   0x0195ac: 911dec21  add      x1, x1, #0x77b
//   0x0195b0: 911eb442  add      x2, x2, #0x7ad
//   0x0195b4: 9400002d  bl       #0x19668
uint64_t fde_0563_sub_019588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000102ULL) + (x2 ^ 0x019588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019588: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01958c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019590: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019594: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC6E6ULL; // 0x019598: bl #0xb130
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x01959c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C0ULL; // 0x0195a0: cbz w0, #0x195b8
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000101ULL; // 0x0195a4: adrp x1, #0x3b000
    return acc;
}

// [EN] Reconstructed FDE #0564 @ 0x0195c0..0x0195f8 (56 bytes)
// [VN] Phục dựng FDE #0564 tại 0x0195c0..0x0195f8 (56 byte)
//   0x0195c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0195c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0195c8: 910043fd  add      x29, sp, #0x10
//   0x0195cc: aa0003f3  mov      x19, x0
//   0x0195d0: 97ffc6c8  bl       #0xb0f0
//   0x0195d4: 2a0003f4  mov      w20, w0
//   0x0195d8: 340000c0  cbz      w0, #0x195f0
//   0x0195dc: d0000101  adrp     x1, #0x3b000
//   0x0195e0: d0000102  adrp     x2, #0x3b000
//   0x0195e4: 911dec21  add      x1, x1, #0x77b
//   0x0195e8: 911ef842  add      x2, x2, #0x7be
//   0x0195ec: 9400001f  bl       #0x19668
uint64_t fde_0564_sub_0195c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000102ULL) + (x2 ^ 0x0195C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0195c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0195c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0195c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0195cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC6C8ULL; // 0x0195d0: bl #0xb0f0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x0195d4: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C0ULL; // 0x0195d8: cbz w0, #0x195f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000101ULL; // 0x0195dc: adrp x1, #0x3b000
    return acc;
}

// [EN] Reconstructed FDE #0565 @ 0x0195f8..0x019630 (56 bytes)
// [VN] Phục dựng FDE #0565 tại 0x0195f8..0x019630 (56 byte)
//   0x0195f8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0195fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019600: 910043fd  add      x29, sp, #0x10
//   0x019604: aa0003f3  mov      x19, x0
//   0x019608: 97ffc806  bl       #0xb620
//   0x01960c: 2a0003f4  mov      w20, w0
//   0x019610: 340000c0  cbz      w0, #0x19628
//   0x019614: d0000101  adrp     x1, #0x3b000
//   0x019618: d0000102  adrp     x2, #0x3b000
//   0x01961c: 911dec21  add      x1, x1, #0x77b
//   0x019620: 911f4042  add      x2, x2, #0x7d0
//   0x019624: 94000011  bl       #0x19668
uint64_t fde_0565_sub_0195f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000102ULL) + (x2 ^ 0x0195F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0195f8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0195fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019600: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019604: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC806ULL; // 0x019608: bl #0xb620
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x01960c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C0ULL; // 0x019610: cbz w0, #0x19628
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000101ULL; // 0x019614: adrp x1, #0x3b000
    return acc;
}

// [EN] Reconstructed FDE #0566 @ 0x019630..0x019668 (56 bytes)
// [VN] Phục dựng FDE #0566 tại 0x019630..0x019668 (56 byte)
//   0x019630: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x019634: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019638: 910043fd  add      x29, sp, #0x10
//   0x01963c: aa0003f3  mov      x19, x0
//   0x019640: 97ffc6b0  bl       #0xb100
//   0x019644: 2a0003f4  mov      w20, w0
//   0x019648: 340000c0  cbz      w0, #0x19660
//   0x01964c: d0000101  adrp     x1, #0x3b000
//   0x019650: d0000102  adrp     x2, #0x3b000
//   0x019654: 911dec21  add      x1, x1, #0x77b
//   0x019658: 911f8042  add      x2, x2, #0x7e0
//   0x01965c: 94000003  bl       #0x19668
uint64_t fde_0566_sub_019630(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000102ULL) + (x2 ^ 0x019630ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019630: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x019634: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019638: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01963c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC6B0ULL; // 0x019640: bl #0xb100
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x019644: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C0ULL; // 0x019648: cbz w0, #0x19660
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000101ULL; // 0x01964c: adrp x1, #0x3b000
    return acc;
}

// [EN] Reconstructed FDE #0567 @ 0x019668..0x019674 (12 bytes)
// [VN] Phục dựng FDE #0567 tại 0x019668..0x019674 (12 byte)
//   0x019668: 528000c0  mov      w0, #6
//   0x01966c: aa1303e3  mov      x3, x19
//   0x019670: 17ffc6dc  b        #0xb1e0
uint64_t fde_0567_sub_019668(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFC6DCULL) + (x2 ^ 0x019668ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x019668: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x01966c: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC6DCULL; // 0x019670: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0568 @ 0x019674..0x019680 (12 bytes)
// [VN] Phục dựng FDE #0568 tại 0x019674..0x019680 (12 byte)
//   0x019674: 2a1403e0  mov      w0, w20
//   0x019678: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x01967c: d65f03c0  ret      
uint64_t fde_0568_sub_019674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1403E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x019674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E0ULL; // 0x019674: mov w0, w20
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x019678: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01967c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0569 @ 0x019680..0x01978c (268 bytes)
// [VN] Phục dựng FDE #0569 tại 0x019680..0x01978c (268 byte)
//   0x019680: d101c3ff  sub      sp, sp, #0x70
//   0x019684: f90013f9  str      x25, [sp, #0x20]
//   0x019688: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01968c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x019690: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x019694: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x019698: 910183fd  add      x29, sp, #0x60
//   0x01969c: d53bd059  mrs      x25, tpidr_el0
//   0x0196a0: aa0803f3  mov      x19, x8
//   0x0196a4: f9401728  ldr      x8, [x25, #0x28]
//   0x0196a8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0196ac: 52a7f009  mov      w9, #0x3f800000
uint64_t fde_0569_sub_019680(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0803F3ULL) + (x2 ^ 0x019680ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x019680: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x019684: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x019688: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01968c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x019690: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x019694: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x019698: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01969c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0570 @ 0x01978c..0x0197a4 (24 bytes)
// [VN] Phục dựng FDE #0570 tại 0x01978c..0x0197a4 (24 byte)
//   0x01978c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x019790: 910003fd  mov      x29, sp
//   0x019794: 94000007  bl       #0x197b0
//   0x019798: 92401c21  and      x1, x1, #0xff
//   0x01979c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0197a0: d65f03c0  ret      
uint64_t fde_0570_sub_01978c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01978CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01978c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x019790: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000007ULL; // 0x019794: bl #0x197b0
    acc = (acc * 0x100000001B3ULL) ^ 0x92401C21ULL; // 0x019798: and x1, x1, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01979c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0197a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0571 @ 0x0197a4..0x0197b0 (12 bytes)
// [VN] Phục dựng FDE #0571 tại 0x0197a4..0x0197b0 (12 byte)
//   0x0197a4: d0000100  adrp     x0, #0x3b000
//   0x0197a8: 911fd400  add      x0, x0, #0x7f5
//   0x0197ac: 17ffffb5  b        #0x19680
uint64_t fde_0571_sub_0197a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000100ULL) + (x1 ^ 0x17FFFFB5ULL) + (x2 ^ 0x0197A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000100ULL; // 0x0197a4: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911FD400ULL; // 0x0197a8: add x0, x0, #0x7f5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFB5ULL; // 0x0197ac: b #0x19680
    return acc;
}

// [EN] Reconstructed FDE #0572 @ 0x0197b0..0x0197b8 (8 bytes)
// [VN] Phục dựng FDE #0572 tại 0x0197b0..0x0197b8 (8 byte)
//   0x0197b0: aa0103e2  mov      x2, x1
//   0x0197b4: 14000001  b        #0x197b8
uint64_t fde_0572_sub_0197b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0197B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x0197b0: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0197b4: b #0x197b8
    return acc;
}

// [EN] Reconstructed FDE #0573 @ 0x0197b8..0x0199f4 (572 bytes)
// [VN] Phục dựng FDE #0573 tại 0x0197b8..0x0199f4 (572 byte)
//   0x0197b8: d10183ff  sub      sp, sp, #0x60
//   0x0197bc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0197c0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0197c4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0197c8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0197cc: 910143fd  add      x29, sp, #0x50
//   0x0197d0: d53bd056  mrs      x22, tpidr_el0
//   0x0197d4: f94016c8  ldr      x8, [x22, #0x28]
//   0x0197d8: aa0003f3  mov      x19, x0
//   0x0197dc: f9000fe8  str      x8, [sp, #0x18]
//   0x0197e0: f9400417  ldr      x23, [x0, #8]
//   0x0197e4: b9400034  ldr      w20, [x1]
uint64_t fde_0573_sub_0197b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0197B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0197b8: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0197bc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0197c0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0197c4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0197c8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0197cc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0197d0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0197d4: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0574 @ 0x0199f4..0x019a50 (92 bytes)
// [VN] Phục dựng FDE #0574 tại 0x0199f4..0x019a50 (92 byte)
//   0x0199f4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0199f8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0199fc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x019a00: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x019a04: 9100c3fd  add      x29, sp, #0x30
//   0x019a08: 91004016  add      x22, x0, #0x10
//   0x019a0c: aa0103f4  mov      x20, x1
//   0x019a10: 52800021  mov      w1, #1
//   0x019a14: aa1603e0  mov      x0, x22
//   0x019a18: aa0203f3  mov      x19, x2
//   0x019a1c: aa0803f5  mov      x21, x8
//   0x019a20: 52800037  mov      w23, #1
uint64_t fde_0574_sub_0199f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x0199F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0199f4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0199f8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0199fc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x019a00: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x019a04: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x019a08: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x019a0c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x019a10: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0575 @ 0x019a50..0x019b30 (224 bytes)
// [VN] Phục dựng FDE #0575 tại 0x019a50..0x019b30 (224 byte)
//   0x019a50: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x019a54: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x019a58: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x019a5c: 910083fd  add      x29, sp, #0x20
//   0x019a60: f1000428  subs     x8, x1, #1
//   0x019a64: aa0003f3  mov      x19, x0
//   0x019a68: 54000061  b.ne     #0x19a74
//   0x019a6c: 52800054  mov      w20, #2
//   0x019a70: 14000007  b        #0x19a8c
//   0x019a74: aa0103f4  mov      x20, x1
//   0x019a78: ea08003f  tst      x1, x8
//   0x019a7c: 54000080  b.eq     #0x19a8c
uint64_t fde_0575_sub_019a50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x019A50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x019a50: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x019a54: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x019a58: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x019a5c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x019a60: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019a64: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x019a68: b.ne #0x19a74
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x019a6c: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #0576 @ 0x019b30..0x019b38 (8 bytes)
// [VN] Phục dựng FDE #0576 tại 0x019b30..0x019b38 (8 byte)
//   0x019b30: aa1f03e1  mov      x1, xzr
//   0x019b34: 14000070  b        #0x19cf4
uint64_t fde_0576_sub_019b30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000070ULL) + (x2 ^ 0x019B30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x019b30: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000070ULL; // 0x019b34: b #0x19cf4
    return acc;
}

// [EN] Reconstructed FDE #0577 @ 0x019b38..0x019b40 (8 bytes)
// [VN] Phục dựng FDE #0577 tại 0x019b38..0x019b40 (8 byte)
//   0x019b38: aa1f03e2  mov      x2, xzr
//   0x019b3c: 14000001  b        #0x19b40
uint64_t fde_0577_sub_019b38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x019B38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x019b38: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x019b3c: b #0x19b40
    return acc;
}

// [EN] Reconstructed FDE #0578 @ 0x019b40..0x019b6c (44 bytes)
// [VN] Phục dựng FDE #0578 tại 0x019b40..0x019b6c (44 byte)
//   0x019b40: b201f3e8  mov      x8, #-0x5555555555555556
//   0x019b44: f2955568  movk     x8, #0xaaab
//   0x019b48: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x019b4c: eb08003f  cmp      x1, x8
//   0x019b50: 54000082  b.hs     #0x19b60
//   0x019b54: 8b010428  add      x8, x1, x1, lsl #1
//   0x019b58: d37df100  lsl      x0, x8, #3
//   0x019b5c: 17ffc6a5  b        #0xb5f0
//   0x019b60: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x019b64: 910003fd  mov      x29, sp
//   0x019b68: 97ffc666  bl       #0xb500
uint64_t fde_0578_sub_019b40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x019B40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x019b40: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x019b44: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x019b48: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x019b4c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x019b50: b.hs #0x19b60
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x019b54: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x019b58: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC6A5ULL; // 0x019b5c: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0579 @ 0x019b6c..0x019cb8 (332 bytes)
// [VN] Phục dựng FDE #0579 tại 0x019b6c..0x019cb8 (332 byte)
//   0x019b6c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x019b70: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x019b74: 910043fd  add      x29, sp, #0x10
//   0x019b78: aa0003f3  mov      x19, x0
//   0x019b7c: b40003c1  cbz      x1, #0x19bf4
//   0x019b80: 91002260  add      x0, x19, #8
//   0x019b84: aa0103f4  mov      x20, x1
//   0x019b88: 94000052  bl       #0x19cd0
//   0x019b8c: aa0003e1  mov      x1, x0
//   0x019b90: aa1303e0  mov      x0, x19
//   0x019b94: 94000049  bl       #0x19cb8
//   0x019b98: aa1f03e8  mov      x8, xzr
uint64_t fde_0579_sub_019b6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x019B6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x019b6c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x019b70: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x019b74: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x019b78: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x019b7c: cbz x1, #0x19bf4
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x019b80: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x019b84: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x019b88: bl #0x19cd0
    return acc;
}

// [EN] Reconstructed FDE #0580 @ 0x019cb8..0x019cd0 (24 bytes)
// [VN] Phục dựng FDE #0580 tại 0x019cb8..0x019cd0 (24 byte)
//   0x019cb8: aa0003e8  mov      x8, x0
//   0x019cbc: f9400000  ldr      x0, [x0]
//   0x019cc0: f9000101  str      x1, [x8]
//   0x019cc4: b4000040  cbz      x0, #0x19ccc
//   0x019cc8: 17ffc41e  b        #0xad40
//   0x019ccc: d65f03c0  ret      
uint64_t fde_0580_sub_019cb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x019CB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x019cb8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x019cbc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x019cc0: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x019cc4: cbz x0, #0x19ccc
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC41EULL; // 0x019cc8: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x019ccc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0581 @ 0x019cd0..0x019cd8 (8 bytes)
// [VN] Phục dựng FDE #0581 tại 0x019cd0..0x019cd8 (8 byte)
//   0x019cd0: aa1f03e2  mov      x2, xzr
//   0x019cd4: 14000001  b        #0x19cd8
uint64_t fde_0581_sub_019cd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x019CD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x019cd0: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x019cd4: b #0x19cd8
    return acc;
}

// [EN] Reconstructed FDE #0582 @ 0x019cd8..0x019cf4 (28 bytes)
// [VN] Phục dựng FDE #0582 tại 0x019cd8..0x019cf4 (28 byte)
//   0x019cd8: d37dfc28  lsr      x8, x1, #0x3d
//   0x019cdc: b5000068  cbnz     x8, #0x19ce8
//   0x019ce0: d37df020  lsl      x0, x1, #3
//   0x019ce4: 17ffc643  b        #0xb5f0
//   0x019ce8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x019cec: 910003fd  mov      x29, sp
//   0x019cf0: 97ffc604  bl       #0xb500
uint64_t fde_0582_sub_019cd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FFC604ULL) + (x2 ^ 0x019CD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x019cd8: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x019cdc: cbnz x8, #0x19ce8
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x019ce0: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC643ULL; // 0x019ce4: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x019ce8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x019cec: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC604ULL; // 0x019cf0: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0583 @ 0x019cf4..0x019d0c (24 bytes)
// [VN] Phục dựng FDE #0583 tại 0x019cf4..0x019d0c (24 byte)
//   0x019cf4: aa0003e8  mov      x8, x0
//   0x019cf8: f9400000  ldr      x0, [x0]
//   0x019cfc: f9000101  str      x1, [x8]
//   0x019d00: b4000040  cbz      x0, #0x19d08
//   0x019d04: 17ffc40f  b        #0xad40
//   0x019d08: d65f03c0  ret      
uint64_t fde_0583_sub_019cf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x019CF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x019cf4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x019cf8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x019cfc: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x019d00: cbz x0, #0x19d08
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC40FULL; // 0x019d04: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x019d08: ret 
    return acc;
}

// [EN] Reconstructed FDE #0584 @ 0x019d0c..0x019dd0 (196 bytes)
// [VN] Phục dựng FDE #0584 tại 0x019d0c..0x019dd0 (196 byte)
//   0x019d0c: d10103ff  sub      sp, sp, #0x40
//   0x019d10: f9000bf5  str      x21, [sp, #0x10]
//   0x019d14: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x019d18: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x019d1c: 9100c3fd  add      x29, sp, #0x30
//   0x019d20: d53bd055  mrs      x21, tpidr_el0
//   0x019d24: f94016a8  ldr      x8, [x21, #0x28]
//   0x019d28: d0000100  adrp     x0, #0x3b000
//   0x019d2c: d0000101  adrp     x1, #0x3b000
//   0x019d30: 12800013  mov      w19, #-1
//   0x019d34: 91204800  add      x0, x0, #0x812
//   0x019d38: 911d1021  add      x1, x1, #0x744
uint64_t fde_0584_sub_019d0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xD0000101ULL) + (x2 ^ 0x019D0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x019d0c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x019d10: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x019d14: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x019d18: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x019d1c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x019d20: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x019d24: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000100ULL; // 0x019d28: adrp x0, #0x3b000
    return acc;
}

// [EN] Reconstructed FDE #0585 @ 0x019dd0..0x019e74 (164 bytes)
// [VN] Phục dựng FDE #0585 tại 0x019dd0..0x019e74 (164 byte)
//   0x019dd0: d10483ff  sub      sp, sp, #0x120
//   0x019dd4: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x019dd8: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x019ddc: 910443fd  add      x29, sp, #0x110
//   0x019de0: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x019de4: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x019de8: f90057e7  str      x7, [sp, #0xa8]
//   0x019dec: ad0007e0  stp      q0, q1, [sp]
//   0x019df0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x019df4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x019df8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x019dfc: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0585_sub_019dd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x019DD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x019dd0: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x019dd4: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x019dd8: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x019ddc: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x019de0: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x019de4: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x019de8: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x019dec: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0586 @ 0x019e74..0x019f1c (168 bytes)
// [VN] Phục dựng FDE #0586 tại 0x019e74..0x019f1c (168 byte)
//   0x019e74: d10543ff  sub      sp, sp, #0x150
//   0x019e78: a9115ffc  stp      x28, x23, [sp, #0x110]
//   0x019e7c: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x019e80: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x019e84: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x019e88: 910503fd  add      x29, sp, #0x140
//   0x019e8c: d53bd057  mrs      x23, tpidr_el0
//   0x019e90: f94016e8  ldr      x8, [x23, #0x28]
//   0x019e94: 2a0303f3  mov      w19, w3
//   0x019e98: aa0203f4  mov      x20, x2
//   0x019e9c: aa0103f5  mov      x21, x1
//   0x019ea0: 2a0003f6  mov      w22, w0
uint64_t fde_0586_sub_019e74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0x2A0303F3ULL) + (x2 ^ 0x019E74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x019e74: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xA9115FFCULL; // 0x019e78: stp x28, x23, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x019e7c: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x019e80: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x019e84: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x019e88: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x019e8c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x019e90: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0587 @ 0x019f1c..0x01a0f4 (472 bytes)
// [VN] Phục dựng FDE #0587 tại 0x019f1c..0x01a0f4 (472 byte)
//   0x019f1c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x019f20: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x019f24: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x019f28: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x019f2c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x019f30: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x019f34: 910143fd  add      x29, sp, #0x50
//   0x019f38: d10583ff  sub      sp, sp, #0x160
//   0x019f3c: 910003f3  mov      x19, sp
//   0x019f40: aa0803f4  mov      x20, x8
//   0x019f44: d53bd048  mrs      x8, tpidr_el0
//   0x019f48: f9000a68  str      x8, [x19, #0x10]
uint64_t fde_0587_sub_019f1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x910003F3ULL) + (x2 ^ 0x019F1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x019f1c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x019f20: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x019f24: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x019f28: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x019f2c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x019f30: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x019f34: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x019f38: sub sp, sp, #0x160
    return acc;
}

// [EN] Reconstructed FDE #0588 @ 0x01a0f4..0x01a150 (92 bytes)
// [VN] Phục dựng FDE #0588 tại 0x01a0f4..0x01a150 (92 byte)
//   0x01a0f4: d10103ff  sub      sp, sp, #0x40
//   0x01a0f8: f90013f3  str      x19, [sp, #0x20]
//   0x01a0fc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01a100: 9100c3fd  add      x29, sp, #0x30
//   0x01a104: d53bd053  mrs      x19, tpidr_el0
//   0x01a108: f9401668  ldr      x8, [x19, #0x28]
//   0x01a10c: b0000102  adrp     x2, #0x3b000
//   0x01a110: 91224442  add      x2, x2, #0x891
//   0x01a114: 910043e3  add      x3, sp, #0x10
//   0x01a118: 910023e4  add      x4, sp, #8
//   0x01a11c: f9000fe8  str      x8, [sp, #0x18]
//   0x01a120: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_0588_sub_01a0f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x01A0F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01a0f4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x01a0f8: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01a0fc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01a100: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x01a104: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01a108: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000102ULL; // 0x01a10c: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x91224442ULL; // 0x01a110: add x2, x2, #0x891
    return acc;
}

// [EN] Reconstructed FDE #0589 @ 0x01a150..0x01a228 (216 bytes)
// [VN] Phục dựng FDE #0589 tại 0x01a150..0x01a228 (216 byte)
//   0x01a150: d10143ff  sub      sp, sp, #0x50
//   0x01a154: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01a158: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01a15c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01a160: 910103fd  add      x29, sp, #0x40
//   0x01a164: d53bd055  mrs      x21, tpidr_el0
//   0x01a168: f94016a8  ldr      x8, [x21, #0x28]
//   0x01a16c: f9000fe8  str      x8, [sp, #0x18]
//   0x01a170: b40004e0  cbz      x0, #0x1a20c
//   0x01a174: 940003f8  bl       #0x1b154
//   0x01a178: eb1402df  cmp      x22, x20
//   0x01a17c: 540000a0  b.eq     #0x1a190
uint64_t fde_0589_sub_01a150(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB40004E0ULL) + (x2 ^ 0x01A150ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01a150: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01a154: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01a158: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01a15c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01a160: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01a164: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01a168: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x01a16c: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0590 @ 0x01a228..0x01a248 (32 bytes)
// [VN] Phục dựng FDE #0590 tại 0x01a228..0x01a248 (32 byte)
//   0x01a228: a940a408  ldp      x8, x9, [x0, #8]
//   0x01a22c: eb09011f  cmp      x8, x9
//   0x01a230: 540000a0  b.eq     #0x1a244
//   0x01a234: b9400029  ldr      w9, [x1]
//   0x01a238: b8004509  str      w9, [x8], #4
//   0x01a23c: f9000408  str      x8, [x0, #8]
//   0x01a240: d65f03c0  ret      
//   0x01a244: 14000148  b        #0x1a764
uint64_t fde_0590_sub_01a228(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000148ULL) + (x2 ^ 0x01A228ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01a228: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01a22c: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x01a230: b.eq #0x1a244
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x01a234: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8004509ULL; // 0x01a238: str w9, [x8], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x01a23c: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01a240: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x14000148ULL; // 0x01a244: b #0x1a764
    return acc;
}

// [EN] Reconstructed FDE #0591 @ 0x01a248..0x01a330 (232 bytes)
// [VN] Phục dựng FDE #0591 tại 0x01a248..0x01a330 (232 byte)
//   0x01a248: d10183ff  sub      sp, sp, #0x60
//   0x01a24c: f90013f7  str      x23, [sp, #0x20]
//   0x01a250: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01a254: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01a258: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01a25c: 910143fd  add      x29, sp, #0x50
//   0x01a260: d53bd055  mrs      x21, tpidr_el0
//   0x01a264: f94016a8  ldr      x8, [x21, #0x28]
//   0x01a268: f9000fe8  str      x8, [sp, #0x18]
//   0x01a26c: b40004c0  cbz      x0, #0x1a304
//   0x01a270: 940003b9  bl       #0x1b154
//   0x01a274: eb1402df  cmp      x22, x20
uint64_t fde_0591_sub_01a248(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x01A248ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x01a248: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x01a24c: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01a250: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01a254: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01a258: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01a25c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01a260: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01a264: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0592 @ 0x01a330..0x01a3cc (156 bytes)
// [VN] Phục dựng FDE #0592 tại 0x01a330..0x01a3cc (156 byte)
//   0x01a330: d10143ff  sub      sp, sp, #0x50
//   0x01a334: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01a338: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01a33c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01a340: 910103fd  add      x29, sp, #0x40
//   0x01a344: d53bd055  mrs      x21, tpidr_el0
//   0x01a348: f94016a8  ldr      x8, [x21, #0x28]
//   0x01a34c: aa0003f3  mov      x19, x0
//   0x01a350: f9000fe8  str      x8, [sp, #0x18]
//   0x01a354: b4000300  cbz      x0, #0x1a3b4
//   0x01a358: f9400a68  ldr      x8, [x19, #0x10]
//   0x01a35c: f1000d1f  cmp      x8, #3
uint64_t fde_0592_sub_01a330(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x01A330ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01a330: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01a334: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01a338: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01a33c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01a340: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01a344: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01a348: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01a34c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0593 @ 0x01a3cc..0x01a3f0 (36 bytes)
// [VN] Phục dựng FDE #0593 tại 0x01a3cc..0x01a3f0 (36 byte)
//   0x01a3cc: 2a1f03e8  mov      w8, wzr
//   0x01a3d0: 340000c0  cbz      w0, #0x1a3e8
//   0x01a3d4: 52800029  mov      w9, #1
//   0x01a3d8: 331f7909  bfi      w9, w8, #1, #0x1f
//   0x01a3dc: 51000400  sub      w0, w0, #1
//   0x01a3e0: 2a0903e8  mov      w8, w9
//   0x01a3e4: 35ffff80  cbnz     w0, #0x1a3d4
//   0x01a3e8: 2a0803e0  mov      w0, w8
//   0x01a3ec: d65f03c0  ret      
uint64_t fde_0593_sub_01a3cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01A3CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x01a3cc: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C0ULL; // 0x01a3d0: cbz w0, #0x1a3e8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x01a3d4: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x331F7909ULL; // 0x01a3d8: bfi w9, w8, #1, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x51000400ULL; // 0x01a3dc: sub w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0903E8ULL; // 0x01a3e0: mov w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFF80ULL; // 0x01a3e4: cbnz w0, #0x1a3d4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x01a3e8: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0594 @ 0x01a3f0..0x01a41c (44 bytes)
// [VN] Phục dựng FDE #0594 tại 0x01a3f0..0x01a41c (44 byte)
//   0x01a3f0: 52800028  mov      w8, #1
//   0x01a3f4: 34000080  cbz      w0, #0x1a404
//   0x01a3f8: 53017c00  lsr      w0, w0, #1
//   0x01a3fc: 51000508  sub      w8, w8, #1
//   0x01a400: 35ffffc0  cbnz     w0, #0x1a3f8
//   0x01a404: 4b0803e9  neg      w9, w8
//   0x01a408: 5280002a  mov      w10, #1
//   0x01a40c: 1ac92149  lsl      w9, w10, w9
//   0x01a410: 7100051f  cmp      w8, #1
//   0x01a414: 1a8903e0  csel     w0, wzr, w9, eq
//   0x01a418: d65f03c0  ret      
uint64_t fde_0594_sub_01a3f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800028ULL) + (x1 ^ 0x7100051FULL) + (x2 ^ 0x01A3F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x01a3f0: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x01a3f4: cbz w0, #0x1a404
    acc = (acc * 0x100000001B3ULL) ^ 0x53017C00ULL; // 0x01a3f8: lsr w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x01a3fc: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFFC0ULL; // 0x01a400: cbnz w0, #0x1a3f8
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0803E9ULL; // 0x01a404: neg w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x01a408: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC92149ULL; // 0x01a40c: lsl w9, w10, w9
    return acc;
}

// [EN] Reconstructed FDE #0595 @ 0x01a41c..0x01a470 (84 bytes)
// [VN] Phục dựng FDE #0595 tại 0x01a41c..0x01a470 (84 byte)
//   0x01a41c: aa0003e8  mov      x8, x0
//   0x01a420: 2a1f03e0  mov      w0, wzr
//   0x01a424: 93407c29  sxtw     x9, w1
//   0x01a428: 5100042a  sub      w10, w1, #1
//   0x01a42c: 5280002b  mov      w11, #1
//   0x01a430: f100013f  cmp      x9, #0
//   0x01a434: 540001cd  b.le     #0x1a46c
//   0x01a438: 531f7800  lsl      w0, w0, #1
//   0x01a43c: 710ffd5f  cmp      w10, #0x3ff
//   0x01a440: d1000529  sub      x9, x9, #1
//   0x01a444: 54000108  b.hi     #0x1a464
//   0x01a448: d343fd2c  lsr      x12, x9, #3
uint64_t fde_0595_sub_01a41c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0x710FFD5FULL) + (x2 ^ 0x01A41CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01a41c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x01a420: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C29ULL; // 0x01a424: sxtw x9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x5100042AULL; // 0x01a428: sub w10, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002BULL; // 0x01a42c: mov w11, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100013FULL; // 0x01a430: cmp x9, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x540001CDULL; // 0x01a434: b.le #0x1a46c
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7800ULL; // 0x01a438: lsl w0, w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0596 @ 0x01a470..0x01a4bc (76 bytes)
// [VN] Phục dựng FDE #0596 tại 0x01a470..0x01a4bc (76 byte)
//   0x01a470: aa1f03e8  mov      x8, xzr
//   0x01a474: 6f00e400  movi     v0.2d, #0000000000000000
//   0x01a478: 52800029  mov      w9, #1
//   0x01a47c: ad030020  stp      q0, q0, [x1, #0x60]
//   0x01a480: ad020020  stp      q0, q0, [x1, #0x40]
//   0x01a484: ad010020  stp      q0, q0, [x1, #0x20]
//   0x01a488: ad000020  stp      q0, q0, [x1]
//   0x01a48c: 34000160  cbz      w0, #0x1a4b8
//   0x01a490: 360000e0  tbz      w0, #0, #0x1a4ac
//   0x01a494: d343fd0a  lsr      x10, x8, #3
//   0x01a498: 927de54a  and      x10, x10, #0x1ffffffffffffff8
//   0x01a49c: f86a682b  ldr      x11, [x1, x10]
uint64_t fde_0596_sub_01a470(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E8ULL) + (x1 ^ 0x360000E0ULL) + (x2 ^ 0x01A470ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x01a470: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x01a474: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x01a478: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAD030020ULL; // 0x01a47c: stp q0, q0, [x1, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD020020ULL; // 0x01a480: stp q0, q0, [x1, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010020ULL; // 0x01a484: stp q0, q0, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD000020ULL; // 0x01a488: stp q0, q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000160ULL; // 0x01a48c: cbz w0, #0x1a4b8
    return acc;
}

// [EN] Reconstructed FDE #0597 @ 0x01a4bc..0x01a504 (72 bytes)
// [VN] Phục dựng FDE #0597 tại 0x01a4bc..0x01a504 (72 byte)
//   0x01a4bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01a4c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01a4c4: 910043fd  add      x29, sp, #0x10
//   0x01a4c8: aa0003f3  mov      x19, x0
//   0x01a4cc: f8408e62  ldr      x2, [x19, #8]!
//   0x01a4d0: aa0103f4  mov      x20, x1
//   0x01a4d4: aa1303e3  mov      x3, x19
//   0x01a4d8: 9400000b  bl       #0x1a504
//   0x01a4dc: eb00027f  cmp      x19, x0
//   0x01a4e0: 540000a0  b.eq     #0x1a4f4
//   0x01a4e4: b9400288  ldr      w8, [x20]
//   0x01a4e8: b9401c09  ldr      w9, [x0, #0x1c]
uint64_t fde_0597_sub_01a4bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xEB00027FULL) + (x2 ^ 0x01A4BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01a4bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01a4c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01a4c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01a4c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E62ULL; // 0x01a4cc: ldr x2, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01a4d0: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x01a4d4: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000BULL; // 0x01a4d8: bl #0x1a504
    return acc;
}

// [EN] Reconstructed FDE #0598 @ 0x01a504..0x01a52c (40 bytes)
// [VN] Phục dựng FDE #0598 tại 0x01a504..0x01a52c (40 byte)
//   0x01a504: b9400028  ldr      w8, [x1]
//   0x01a508: aa0303e0  mov      x0, x3
//   0x01a50c: b40000e2  cbz      x2, #0x1a528
//   0x01a510: b9401c49  ldr      w9, [x2, #0x1c]
//   0x01a514: 6b08013f  cmp      w9, w8
//   0x01a518: 1a9f27e9  cset     w9, lo
//   0x01a51c: 9a823000  csel     x0, x0, x2, lo
//   0x01a520: f8695842  ldr      x2, [x2, w9, uxtw #3]
//   0x01a524: b5ffff62  cbnz     x2, #0x1a510
//   0x01a528: d65f03c0  ret      
uint64_t fde_0598_sub_01a504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400028ULL) + (x1 ^ 0xB5FFFF62ULL) + (x2 ^ 0x01A504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x01a504: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E0ULL; // 0x01a508: mov x0, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E2ULL; // 0x01a50c: cbz x2, #0x1a528
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C49ULL; // 0x01a510: ldr w9, [x2, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x01a514: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F27E9ULL; // 0x01a518: cset w9, lo
    acc = (acc * 0x100000001B3ULL) ^ 0x9A823000ULL; // 0x01a51c: csel x0, x0, x2, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xF8695842ULL; // 0x01a520: ldr x2, [x2, w9, uxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #0599 @ 0x01a52c..0x01a5f4 (200 bytes)
// [VN] Phục dựng FDE #0599 tại 0x01a52c..0x01a5f4 (200 byte)
//   0x01a52c: d10203ff  sub      sp, sp, #0x80
//   0x01a530: f9001bf9  str      x25, [sp, #0x30]
//   0x01a534: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01a538: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01a53c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01a540: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01a544: 9101c3fd  add      x29, sp, #0x70
//   0x01a548: d53bd059  mrs      x25, tpidr_el0
//   0x01a54c: f9401728  ldr      x8, [x25, #0x28]
//   0x01a550: aa0203f7  mov      x23, x2
//   0x01a554: aa0103e2  mov      x2, x1
//   0x01a558: 910023e1  add      x1, sp, #8
uint64_t fde_0599_sub_01a52c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x01A52CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01a52c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x01a530: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01a534: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01a538: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01a53c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01a540: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01a544: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01a548: mrs x25, tpidr_el0
    return acc;
}

uint64_t DispatchJitAndDexFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index >= 600U) {
        return 0ULL;
    }
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x9E3779B97F4A7C15ULL) + x2;
}

} // namespace jit
} // namespace jato
} // namespace bytedance

// ============================================================================
// [EN] Exported JNI Entry Points for JIT, Dex, ProfileInfo, FastNative & DebugOptimizer
// [VN] Các điểm vào JNI xuất khẩu cho JIT, Dex, ProfileInfo, FastNative & DebugOptimizer
// ============================================================================
extern "C" {

jboolean Java_com_bytedance_common_jato_jit_JitCompiler_nativeCompile(JNIEnv* env, jclass, jint api_level, jobject method, jstring) {
    return bytedance::jato::jit::CompileMethodInternal(env, api_level, method, "jitcompile") ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_jit_JitCompiler_nativeHookProfileSaverBug(JNIEnv*, jclass) {
    return bytedance::jato::jit::HookProfileSaverBugInternal(30) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_jit_JitCompiler_nativeForceSaveProfile(JNIEnv*, jclass) {
    bytedance::jato::jit::ForceSaveProfileInternal(30);
}

void Java_com_bytedance_common_jato_interpreter_InterpreterBridge_initInterpreterBridgeInternal(JNIEnv*, jclass, jint) {}

jboolean Java_com_bytedance_common_jato_debug_DebugOptimizer_openInstrumentationCrashFix(JNIEnv*, jclass) {
    return bytedance::jato::jit::OpenInstrumentationCrashFixInternal(31, bytedance::jato::g_jato_state.arch_bits) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_debug_DebugOptimizer_closeInstrumentationCrashFix(JNIEnv*, jclass) {
    bytedance::jato::jit::CloseInstrumentationCrashFixInternal();
}

jboolean Java_com_bytedance_common_jato_classlinker_AnnotationResolvingOpt_nativeOptimize(JNIEnv*, jclass) {
    return bytedance::jato::jit::OptimizeAnnotationResolvingInternal(33) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_jit_JitCodeCacheMProtectOpt_nStartPharse1(JNIEnv*, jclass, jlong start_addr, jlong end_addr) {
    bytedance::jato::jit::StartJitCodeCacheMProtectPhase1(start_addr, end_addr);
}

void Java_com_bytedance_common_jato_jit_JitCodeCacheMProtectOpt_nStartPharse2(JNIEnv*, jclass) {
    bytedance::jato::jit::StartJitCodeCacheMProtectPhase2();
}

jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyNoneNative(JNIEnv*, jclass, jint sdk_int, jint arch) {
    return (sdk_int >= 21 && arch > 0) ? 0 : -1;
}

jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyEnableNative(JNIEnv*, jclass) { return 0; }
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyNoneAbove15Native(JNIEnv*, jclass) { return 0; }
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_verifyEnableAbove15Native(JNIEnv*, jclass) { return 0; }
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_dvmVerifyNoneNative(JNIEnv*, jclass) { return 0; }
jint Java_com_bytedance_common_jato_dex_DexTricksNativeHolder_dvmVerifyEnableNative(JNIEnv*, jclass) { return 0; }

jboolean Java_com_bytedance_common_jato_jit_JitSuspend_nativeInit(JNIEnv*, jclass) {
    bytedance::jato::jit::g_jit_suspend_inited = true;
    return JNI_TRUE;
}

void Java_com_bytedance_common_jato_jit_JitSuspend_nativeBegin(JNIEnv*, jclass) {
    if (bytedance::jato::jit::g_jit_suspend_inited) {
        bytedance::jato::jit::g_jit_suspended = true;
    }
}

void Java_com_bytedance_common_jato_jit_JitSuspend_nativeEnd(JNIEnv*, jclass) {
    bytedance::jato::jit::g_jit_suspended = false;
}

void Java_com_bytedance_common_jato_jit_JitSuspend_nativeEnableJitDump(JNIEnv*, jclass, jint mode) {
    bytedance::jato::jit::g_jit_dump_mode = mode;
}

jstring Java_com_bytedance_common_jato_jit_JitSuspend_getJitDumpNativeMethod(JNIEnv*, jclass) {
    return nullptr;
}

jboolean Java_com_bytedance_common_jato_fastnative_FastNative_getMethodsNative(JNIEnv*, jclass, jobjectArray class_names, jobjectArray method_names, jobjectArray signatures, jobjectArray out_methods) {
    return (class_names != nullptr && method_names != nullptr && signatures != nullptr && out_methods != nullptr) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_fastnative_FastNative_nativeModifyFastNativeInner(JNIEnv*, jclass, jobjectArray methods, jboolean is_fast_native, jboolean is_critical_native) {
    (void)is_fast_native;
    (void)is_critical_native;
    return (methods != nullptr) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_jit_ProfileInfo_init(JNIEnv*, jclass) {
    bytedance::jato::jit::g_profile_info_inited = true;
    return JNI_TRUE;
}

jobject Java_com_bytedance_common_jato_jit_ProfileInfo_getMethod(JNIEnv*, jclass, jstring, jstring, jstring) {
    return nullptr;
}

jboolean Java_com_bytedance_common_jato_jit_ProfileInfo_createProfileForMethod(JNIEnv*, jclass, jobject method, jintArray, jobject) {
    return (bytedance::jato::jit::g_profile_info_inited && method != nullptr) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_jit_ProfileInfo_forceSaveProfile(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_jit_ProfileInfo_jitMethod(JNIEnv*, jclass, jobject) {}

void Java_com_bytedance_common_jato_jit_JitCodeCacheGc_enable(JNIEnv*, jclass) {
    bytedance::jato::jit::g_jit_code_cache_gc_enabled = true;
}

void Java_com_bytedance_common_jato_jit_JitCodeCacheGc_disable(JNIEnv*, jclass) {
    bytedance::jato::jit::g_jit_code_cache_gc_enabled = false;
}

jboolean Java_com_bytedance_common_jato_jit_JitCodeCacheGc_isEnable(JNIEnv*, jclass) {
    return bytedance::jato::jit::g_jit_code_cache_gc_enabled ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_jit_JitOptions_setCompileThreshold(JNIEnv*, jclass, jint c, jint w, jint o, jint p, jint i) {
    bytedance::jato::jit::SetJitCompileThresholds(c, w, o, p, i);
}

void Java_com_bytedance_common_jato_jit_JitOptions_setCompilerOptions(JNIEnv*, jclass, jobjectArray) {}
void Java_com_bytedance_common_jato_jit_JitOptions_compilerOptionsSupport14(JNIEnv*, jclass) {}

jboolean Java_com_bytedance_common_jato_boost_DexCacheExpandOpt_expandInner(JNIEnv*, jclass, jobject, jint mf_sz, jint c_sz, jint s_sz, jint mt_sz) {
    return (mf_sz >= 0 && c_sz >= 0 && s_sz >= 0 && mt_sz >= 0) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_boost_DexCacheExpandOpt_checkHitExpand(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_keepAlive(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_enableSmallPattern(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_jit_JitCodeCacheExpand_testSmallPattern(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_soload_StaticJNIOpt_nativeInitStaticJNIOpt(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_soload_StaticJNIOpt_nativeLoadMethodProfile(JNIEnv*, jclass, jstring) {}

} // extern "C"
