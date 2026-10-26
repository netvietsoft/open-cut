// ============================================================================
// FILE: npth_unw_interface.cpp
// TARGET: libnpth_unw.so (29,336 bytes, ELF64 AArch64, 97 .dynsym entries)
// ROLE: Implementation of All 23 Exported C API Symbols ([074]..[096])
//       Triển khai toàn bộ 23 hàm C xuất khẩu ([074]..[096]) của libnpth_unw.so
// ============================================================================

#include "npth_unw_interface.h"
#include <cstdlib>

using NextAI::OpenCut::NpthUnw::NpthUnwContext;
using NextAI::OpenCut::NpthUnw::NpthUnwEngine;

extern "C" {

// [074] val=0x004ff8 size=232 : npth_unw_any_thread_option
char* npth_unw_any_thread_option(int32_t pid, int32_t tid, int option) {
    return NpthUnwEngine::UnwindAnyThreadOption(pid, tid, option);
}

// [075] val=0x005978 size=  8 : npth_unw_fast
char* npth_unw_fast(void) {
    return NpthUnwEngine::UnwindFast();
}

// [076] val=0x005a44 size=  8 : npth_unw_frames
size_t npth_unw_frames(uintptr_t* frames, size_t max_frames) {
    return NpthUnwEngine::UnwindFrames(frames, max_frames);
}

// [077] val=0x005b3c size=676 : npth_unw_format_option
char* npth_unw_format_option(const uintptr_t* pcs, size_t num_pcs, int option) {
    return NpthUnwEngine::FormatPcsOption(pcs, num_pcs, option);
}

// [078] val=0x005e2c size=  8 : npth_unw_format
char* npth_unw_format(const uintptr_t* pcs, size_t num_pcs) {
    return NpthUnwEngine::FormatPcs(pcs, num_pcs);
}

// [079] val=0x003e20 size=180 : npth_unw_current_option
char* npth_unw_current_option(int option) {
    return NpthUnwEngine::UnwindCurrentOption(option);
}

// [080] val=0x0058c4 size=180 : npth_unw_fast_option
char* npth_unw_fast_option(int option) {
    return NpthUnwEngine::UnwindFastOption(option);
}

// [081] val=0x005980 size=196 : npth_unw_frames_option
size_t npth_unw_frames_option(uintptr_t* frames, size_t max_frames, int option) {
    return NpthUnwEngine::UnwindFramesOption(frames, max_frames, option);
}

// [082] val=0x005abc size=128 : npth_unw_ucontext_frames_option
size_t npth_unw_ucontext_frames_option(void* ucontext, uintptr_t* frames, size_t max_frames, int option) {
    return NpthUnwEngine::UnwindUcontextFramesOption(ucontext, frames, max_frames, option);
}

// [083] val=0x005fb8 size= 20 : npth_unw_context_regs
void* npth_unw_context_regs(void* ctx) {
    return NpthUnwEngine::ContextRegs(static_cast<NpthUnwContext*>(ctx));
}

// [084] val=0x004e94 size=  8 : npth_unw_current
char* npth_unw_current(void) {
    return NpthUnwEngine::UnwindCurrent();
}

// [085] val=0x004ff0 size=  8 : npth_unw_thread
char* npth_unw_thread(int32_t tid) {
    return NpthUnwEngine::UnwindThread(tid);
}

// [086] val=0x005184 size=  8 : npth_unw_any_thread
char* npth_unw_any_thread(int32_t pid, int32_t tid) {
    return NpthUnwEngine::UnwindAnyThread(pid, tid);
}

// [087] val=0x0058c0 size=  4 : npth_unw_process_option
char* npth_unw_process_option(int32_t pid, int option) {
    return NpthUnwEngine::UnwindProcessOption(pid, option);
}

// [088] val=0x005a4c size=112 : npth_unw_ucontext_option
char* npth_unw_ucontext_option(void* ucontext, int option) {
    return NpthUnwEngine::UnwindUcontextOption(ucontext, option);
}

// [089] val=0x00603c size=132 : npth_unw_context_frames_option
size_t npth_unw_context_frames_option(void* ctx, uintptr_t* frames, size_t max_frames, int option) {
    return NpthUnwEngine::ContextFramesOption(static_cast<NpthUnwContext*>(ctx), frames, max_frames, option);
}

// [090] val=0x0058ac size= 12 : npth_unw_all_option
char* npth_unw_all_option(int option) {
    return NpthUnwEngine::UnwindAllOption(option);
}

// [091] val=0x0058b8 size=  8 : npth_unw_process
char* npth_unw_process(int32_t pid) {
    return NpthUnwEngine::UnwindProcess(pid);
}

// [092] val=0x004e9c size=340 : npth_unw_thread_option
char* npth_unw_thread_option(int32_t tid, int option) {
    return NpthUnwEngine::UnwindThreadOption(tid, option);
}

// [093] val=0x00518c size= 12 : npth_unw_all
char* npth_unw_all(void) {
    return NpthUnwEngine::UnwindAll();
}

// [094] val=0x005e34 size=296 : npth_unw_context_create
void* npth_unw_context_create(int32_t tid) {
    return NpthUnwEngine::ContextCreate(tid);
}

// [095] val=0x005f5c size= 92 : npth_unw_context_destroy
void npth_unw_context_destroy(void* ctx) {
    NpthUnwEngine::ContextDestroy(static_cast<NpthUnwContext*>(ctx));
}

// [096] val=0x005fcc size=112 : npth_unw_context_option
char* npth_unw_context_option(void* ctx, int option) {
    return NpthUnwEngine::ContextOption(static_cast<NpthUnwContext*>(ctx), option);
}

} // extern "C"

namespace NextAI {
namespace OpenCut {
namespace npth_unw {

Npth_unwEngine::Npth_unwEngine() {
    NpthUnwEngine::EnsureLocalUnwinderInitialized();
}

Npth_unwEngine::~Npth_unwEngine() = default;

std::string Npth_unwEngine::CaptureCurrentStackTrace(int option) const {
    char* raw = npth_unw_current_option(option);
    if (!raw) {
        return std::string();
    }
    std::string res(raw);
    std::free(raw);
    return res;
}

std::vector<uintptr_t> Npth_unwEngine::CaptureCurrentFrames(size_t max_frames, int option) const {
    if (max_frames == 0u) {
        return {};
    }
    std::vector<uintptr_t> pcs(max_frames, 0u);
    const size_t count = npth_unw_frames_option(pcs.data(), max_frames, option);
    pcs.resize(count);
    return pcs;
}

std::string Npth_unwEngine::FormatProgramCounters(const std::vector<uintptr_t>& pcs, int option) const {
    if (pcs.empty()) {
        return std::string();
    }
    char* raw = npth_unw_format_option(pcs.data(), pcs.size(), option);
    if (!raw) {
        return std::string();
    }
    std::string res(raw);
    std::free(raw);
    return res;
}

} // namespace npth_unw
} // namespace OpenCut
} // namespace NextAI
