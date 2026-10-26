// ============================================================================
// FILE: npth_unw_interface.h
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64, 97 .dynsym entries)
// ROLE: Public C ABI Exports ([074]..[096]) & High-Level C++17 Facade
//       Giao diện C ABI công khai ([074]..[096]) & Lớp bao bọc C++17 mức cao
// ============================================================================
// [EN] Declares all 23 `STB_GLOBAL STT_FUNC` symbols exported by `libnpth_unw.so`
//      in `.dynsym` (`[074]..[096]`) with exact virtual addresses and sizes in `.text`.
// [VN] Khai báo toàn bộ 23 biểu tượng hàm C xuất khẩu bởi `libnpth_unw.so`
//      trong `.dynsym` (`[074]..[096]`) kèm địa chỉ ảo và kích thước trong `.text`.
// ============================================================================

#pragma once

#include "npth_unw_engine.h"
#include <cstddef>
#include <cstdint>

extern "C" {

// ============================================================================
// 23 EXPORTED C API SYMBOLS (.dynsym [074]..[096])
// ============================================================================

// [074] val=0x004ff8 size=232 : npth_unw_any_thread_option
char* npth_unw_any_thread_option(int32_t pid, int32_t tid, int option);

// [075] val=0x005978 size=  8 : npth_unw_fast
char* npth_unw_fast(void);

// [076] val=0x005a44 size=  8 : npth_unw_frames
size_t npth_unw_frames(uintptr_t* frames, size_t max_frames);

// [077] val=0x005b3c size=676 : npth_unw_format_option
char* npth_unw_format_option(const uintptr_t* pcs, size_t num_pcs, int option);

// [078] val=0x005e2c size=  8 : npth_unw_format
char* npth_unw_format(const uintptr_t* pcs, size_t num_pcs);

// [079] val=0x003e20 size=180 : npth_unw_current_option
char* npth_unw_current_option(int option);

// [080] val=0x0058c4 size=180 : npth_unw_fast_option
char* npth_unw_fast_option(int option);

// [081] val=0x005980 size=196 : npth_unw_frames_option
size_t npth_unw_frames_option(uintptr_t* frames, size_t max_frames, int option);

// [082] val=0x005abc size=128 : npth_unw_ucontext_frames_option
size_t npth_unw_ucontext_frames_option(void* ucontext, uintptr_t* frames, size_t max_frames, int option);

// [083] val=0x005fb8 size= 20 : npth_unw_context_regs
void* npth_unw_context_regs(void* ctx);

// [084] val=0x004e94 size=  8 : npth_unw_current
char* npth_unw_current(void);

// [085] val=0x004ff0 size=  8 : npth_unw_thread
char* npth_unw_thread(int32_t tid);

// [086] val=0x005184 size=  8 : npth_unw_any_thread
char* npth_unw_any_thread(int32_t pid, int32_t tid);

// [087] val=0x0058c0 size=  4 : npth_unw_process_option
char* npth_unw_process_option(int32_t pid, int option);

// [088] val=0x005a4c size=112 : npth_unw_ucontext_option
char* npth_unw_ucontext_option(void* ucontext, int option);

// [089] val=0x00603c size=132 : npth_unw_context_frames_option
size_t npth_unw_context_frames_option(void* ctx, uintptr_t* frames, size_t max_frames, int option);

// [090] val=0x0058ac size= 12 : npth_unw_all_option
char* npth_unw_all_option(int option);

// [091] val=0x0058b8 size=  8 : npth_unw_process
char* npth_unw_process(int32_t pid);

// [092] val=0x004e9c size=340 : npth_unw_thread_option
char* npth_unw_thread_option(int32_t tid, int option);

// [093] val=0x00518c size= 12 : npth_unw_all
char* npth_unw_all(void);

// [094] val=0x005e34 size=296 : npth_unw_context_create
void* npth_unw_context_create(int32_t tid);

// [095] val=0x005f5c size= 92 : npth_unw_context_destroy
void npth_unw_context_destroy(void* ctx);

// [096] val=0x005fcc size=112 : npth_unw_context_option
char* npth_unw_context_option(void* ctx, int option);

} // extern "C"

namespace NextAI {
namespace OpenCut {
namespace npth_unw {

class Npth_unwEngine {
public:
    Npth_unwEngine();
    virtual ~Npth_unwEngine();

    std::string CaptureCurrentStackTrace(int option = 0) const;
    std::vector<uintptr_t> CaptureCurrentFrames(size_t max_frames = 64, int option = 0) const;
    std::string FormatProgramCounters(const std::vector<uintptr_t>& pcs, int option = 0) const;
};

} // namespace npth_unw
} // namespace OpenCut
} // namespace NextAI
