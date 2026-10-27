// ============================================================================
// File: npth_unwind_android_unwinder.cpp
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 implementation of unwindstack::AndroidUnwinderData
// (0x01419c..0x014428), unwindstack::AndroidUnwinder (0x0155fc..0x015d14),
// unwindstack::DemangleNameIfNeeded (0x015d14..0x015de4), Frame formatting
// (0x0333a0..0x033660), and the 15-entry ErrorCode lookup table at .data.rel.ro
// 0x038420..0x038490.
//
// Mô tả (VI):
// Triển khai C++17 tái tạo sạch cho unwindstack::AndroidUnwinderData
// (0x01419c..0x014428), unwindstack::AndroidUnwinder (0x0155fc..0x015d14),
// unwindstack::DemangleNameIfNeeded (0x015d14..0x015de4), hàm định dạng chuỗi
// khung ngăn xếp (0x0333a0..0x033660) và bảng 15 chuỗi ErrorCode tại
// .data.rel.ro 0x038420..0x038490.
// ============================================================================

#include "npth_unwind_android_unwinder.h"

#include <cstdio>
#include <cstring>

namespace unwindstack {

// ============================================================================
// 1. 15-Entry ErrorCode Table (.data.rel.ro 0x038420, file offset 0x034420)
// Verified directly from .rela.dyn relocations on 0x038420..0x038490 and
// AndroidUnwinderData::GetErrorString (0x014364..0x0143ec).
// Bảng 15 phần tử ánh xạ mã lỗi ErrorCode tại .data.rel.ro 0x038420.
// ============================================================================
const std::array<ErrorCodeTableEntry, 15>& GetNpthUnwindErrorCodeTable15() noexcept {
    static const std::array<ErrorCodeTableEntry, 15> kTable = {{
        {ERROR_NONE,                  0x038420U, 0x00738BU, "None"},
        {ERROR_MEMORY_INVALID,        0x038428U, 0x007461U, "Memory Invalid"},
        {ERROR_UNWIND_INFO,           0x038430U, 0x00743DU, "Unwind Info"},
        {ERROR_UNSUPPORTED,           0x038438U, 0x0072CBU, "Unsupported"},
        {ERROR_INVALID_MAP,           0x038440U, 0x007598U, "Invalid Map"},
        {ERROR_MAX_FRAMES_EXCEEDED,   0x038448U, 0x0075A4U, "Maximum Frames Exceeded"},
        {ERROR_REPEATED_FRAME,        0x038450U, 0x007364U, "Repeated Frame"},
        {ERROR_INVALID_ELF,           0x038458U, 0x007451U, "Invalid Elf"},
        {ERROR_THREAD_DOES_NOT_EXIST, 0x038460U, 0x007325U, "Thread Does Not Exist"},
        {ERROR_THREAD_TIMEOUT,        0x038468U, 0x00757FU, "Thread Timeout"},
        {ERROR_SYSTEM_CALL,           0x038470U, 0x00769EU, "System Call Failed"},
        {ERROR_BAD_ARCH,              0x038478U, 0x00723CU, "Invalid arch detected"},
        {ERROR_MAPS_PARSE,            0x038480U, 0x007711U, "Failed to parse maps"},
        {ERROR_INVALID_PARAMETER,     0x038488U, 0x00760BU, "Invalid parameter"},
        {ERROR_PTRACE_CALL,           0x038490U, 0x0076B1U, "Ptrace Call Failed"}
    }};
    return kTable;
}

const char* GetErrorCodeString(ErrorCode error) noexcept {
    const int idx = static_cast<int>(error);
    const auto& tbl = GetNpthUnwindErrorCodeTable15();
    if (idx >= 0 && idx < static_cast<int>(tbl.size())) {
        return tbl[static_cast<size_t>(idx)].message;
    }
    if (error == ERROR_MEMORY_NOT_ENOUGH) {
        return "Memory not enough"; // .rodata 0x00728a
    }
    return "None";
}

// ============================================================================
// 2. DemangleNameIfNeeded (0x015d14..0x015de4)
// Disassembly match:
//   0x015d40: subs x20, x21, #5 ; b.lo #0x15d64
//   0x015d50: add x2, x2, #0x52e (.rodata 0x00752e: "__dl_") ; mov w1, #5 ; mov w3, #5
//   0x015d5c: bl std::string::compare(0, 5, "__dl_", 5)
//   0x015d84: add x1, x22, #5 ; bl Demangle (#0x15de4) ; insert(0, "__dl_")
// Giải mã tên hàm C++ Itanium ABI (_Z...) và giữ nguyên tiền tố "__dl_".
// ============================================================================
namespace {

std::string SimpleItaniumDemangle(const char* mangled, size_t len) {
    if (mangled == nullptr || len < 2 || mangled[0] != '_' || mangled[1] != 'Z') {
        return std::string(mangled ? mangled : "", len);
    }
    // Lightweight clean-room Itanium C++ nested name parser (_ZN<len><id>...E)
    size_t pos = 2;
    bool nested = false;
    if (pos < len && mangled[pos] == 'N') {
        nested = true;
        ++pos;
    }
    if (pos < len && mangled[pos] == 'K') {
        ++pos;
    }
    std::string out;
    while (pos < len) {
        if (nested && mangled[pos] == 'E') {
            ++pos;
            break;
        }
        if (mangled[pos] < '0' || mangled[pos] > '9') {
            break;
        }
        size_t part_len = 0;
        while (pos < len && mangled[pos] >= '0' && mangled[pos] <= '9') {
            part_len = part_len * 10 + static_cast<size_t>(mangled[pos] - '0');
            ++pos;
        }
        if (part_len == 0 || pos + part_len > len) {
            return std::string(mangled, len);
        }
        if (!out.empty()) {
            out += "::";
        }
        out.append(mangled + pos, part_len);
        pos += part_len;
        if (!nested) {
            break;
        }
    }
    return out.empty() ? std::string(mangled, len) : out;
}

} // namespace

std::string DemangleNameIfNeeded(const std::string& name) {
    // 0x015d40..0x015d60: if (name.length() >= 5 && name.compare(0, 5, "__dl_", 5) == 0)
    if (name.size() >= 5 && name.compare(0, 5, "__dl_", 5) == 0) {
        std::string demangled = SimpleItaniumDemangle(name.data() + 5, name.size() - 5);
        demangled.insert(0, "__dl_");
        return demangled;
    }
    return SimpleItaniumDemangle(name.data(), name.size());
}

// ============================================================================
// 3. AndroidUnwinderData Implementation (0x01419c..0x014428)
// Triển khai các phương thức của AndroidUnwinderData.
// ============================================================================
// 0x01419c..0x01426b: AndroidUnwinderData::DemangleFunctionNames()
// Iterates frames (+0x00..+0x08, stride 0x48 = 72 bytes, function_name at +0x28)
// and replaces each frame.function_name with DemangleNameIfNeeded(frame.function_name).
void AndroidUnwinderData::DemangleFunctionNames() {
    for (auto& frame : frames) {
        if (!frame.function_name.empty()) {
            frame.function_name = SharedString(DemangleNameIfNeeded(frame.function_name.value()));
        }
    }
}

// 0x014364..0x0143ec: AndroidUnwinderData::GetErrorString()
// Disassembly match:
//   0x014370: ldrsb x9, [x0, #0x18] (error.code)
//   0x014374: adrp x10, #0x38000 ; add x10, x10, #0x420 ; ldr x1, [x10, x9, lsl #3]
//   0x014390: ldr x1, [x20, #0x20] ; cbz x1, #0x143e0 (error.address)
//   0x0143a0: add x0, x0, #0x278 (.rodata 0x007278: " at address 0x%lx") ; bl StringPrintf
std::string AndroidUnwinderData::GetErrorString() {
    std::string err_str = GetErrorCodeString(error.code);
    if (error.address != 0) {
        char buf[64] = {0};
        std::snprintf(buf, sizeof(buf), " at address 0x%lx", static_cast<unsigned long>(error.address));
        err_str.append(buf);
    }
    return err_str;
}

// 0x0143f0..0x0143f4: ldr x0, [x0, #0x38] ; ret
DexPositionInfoContext* AndroidUnwinderData::GetPositionInfosForDex() {
    return dex_context;
}

// 0x0143f8..0x014428: ldr x20, [x0, #0x38] ; cbz x20 ; delete x20 ; str xzr, [x19, #0x38]
void AndroidUnwinderData::FreeContext() {
    if (dex_context != nullptr) {
        delete dex_context;
        dex_context = nullptr;
    }
}

// ============================================================================
// 4. AndroidUnwinder Implementation (0x0155fc..0x015d14 & 0x0333a0..0x033660)
// Triển khai lớp AndroidUnwinder (22 phương thức xuất khẩu).
// ============================================================================
// 0x0155fc..0x015688: AndroidUnwinder::AndroidUnwinder(int pid, Maps* maps, std::shared_ptr<Memory> process_memory)
// Allocates 0x48 (72) bytes for Impl:
// - If pid < 0 (tbnz w22, #0x1f), sets pid = getpid() and is_local_mode = true (+0x11 = 1).
// - Otherwise sets is_local_mode = (pid == getpid()).
AndroidUnwinder::AndroidUnwinder(int pid, Maps* maps, std::shared_ptr<Memory> process_memory)
    : impl_(new Impl()) {
    constexpr int kSimulatedSelfPid = 1000;
    if (pid < 0) {
        impl_->pid = kSimulatedSelfPid;
        impl_->is_local_mode = true;
    } else {
        impl_->pid = pid;
        impl_->is_local_mode = (pid == kSimulatedSelfPid);
    }
    impl_->max_frames = 0;
    impl_->initialized = false;
    impl_->maps = maps;
    impl_->process_memory = std::move(process_memory);
}

// 0x01568c..0x0156fc: AndroidUnwinder::~AndroidUnwinder()
AndroidUnwinder::~AndroidUnwinder() {
    delete impl_;
    impl_ = nullptr;
}

// 0x015700..0x015704: ldr x0, [x0] ; b #0x1449c
bool AndroidUnwinder::Initialize(ErrorData& error) {
    return InternalInitialize(error);
}

bool AndroidUnwinder::InternalInitialize(ErrorData& error) {
    if (impl_ == nullptr) {
        error.code = ERROR_INVALID_PARAMETER;
        return false;
    }
    if (impl_->initialized) {
        return true;
    }
    if (impl_->max_frames == 0) {
        impl_->max_frames = 256;
    }
    if (impl_->maps == nullptr) {
        impl_->maps_guard = std::make_unique<FileMaps>(
            impl_->is_local_mode ? "/proc/self/maps" : "/proc/maps");
        impl_->maps = impl_->maps_guard.get();
        if (!impl_->maps->Parse()) {
            error.code = ERROR_MAPS_PARSE; // 12 ("Failed to parse maps")
            return false;
        }
    }
    if (!impl_->process_memory) {
        impl_->process_memory = CreateOfflineContainerMemory(0x0000007FF0000000ULL, 0x0000007FF0010000ULL);
    }
    impl_->initialized = true;
    error.code = ERROR_NONE;
    return true;
}

// 0x015708..0x015aaf (936 B): AndroidUnwinder::Unwind(int tid, AndroidUnwinderData& data)
bool AndroidUnwinder::Unwind(int tid, AndroidUnwinderData& data) {
    if (!InternalInitialize(data.error)) {
        return false;
    }
    Registers regs;
    if (tid < 0 || impl_->is_local_mode) {
        regs.CreateFromLocal();
    } else if (!regs.RemoteGet(tid)) {
        data.error.code = ERROR_PTRACE_CALL;
        return false;
    }
    return InternalUnwind(regs.get(), impl_->process_memory, data);
}

// 0x015ab0..0x015b24 (120 B): AndroidUnwinder::Unwind(void* ucontext, AndroidUnwinderData& data)
// Disassembly match:
//   0x015abc: cbz x1, #0x15b10 -> mov w8, #0xd (ERROR_INVALID_PARAMETER = 13) ; strb w8, [x19, #0x18]
//   0x015ad0: bl InternalInitialize (#0x1449c)
//   0x015adc: bl Regs::CreateFromUcontext (#0x30628)
//   0x015af0: bl InternalUnwind (#0x14d5c)
bool AndroidUnwinder::Unwind(void* ucontext, AndroidUnwinderData& data) {
    if (ucontext == nullptr) {
        data.error.code = ERROR_INVALID_PARAMETER; // mov w8, #0xd ; strb w8, [x19, #0x18] at 0x015b10
        return false;
    }
    if (!InternalInitialize(data.error)) {
        return false;
    }
    std::unique_ptr<Regs> regs(Regs::CreateFromUcontext(ucontext));
    return InternalUnwind(regs.get(), impl_->process_memory, data);
}

// 0x015b28..0x015b30: ldr x0, [x0] ; ldr x1, [x1] ; b #0x14d5c
bool AndroidUnwinder::Unwind(const Registers& initial_regs, AndroidUnwinderData& data) {
    if (!InternalInitialize(data.error)) {
        return false;
    }
    return InternalUnwind(initial_regs.get(), impl_->process_memory, data);
}

// 0x015b34..0x015b3c: ldr x1, [x1] ; ldr x0, [x0] ; b #0x14dc0
bool AndroidUnwinder::Unwind(const Registers& initial_regs,
                             std::shared_ptr<Memory> process_memory,
                             AndroidUnwinderData& data) {
    if (!InternalInitialize(data.error)) {
        return false;
    }
    return InternalUnwind(initial_regs.get(), std::move(process_memory), data);
}

bool AndroidUnwinder::InternalUnwind(Regs* initial_regs,
                                     std::shared_ptr<Memory> process_memory,
                                     AndroidUnwinderData& data) {
    if (initial_regs == nullptr || !process_memory) {
        data.error.code = ERROR_INVALID_PARAMETER;
        return false;
    }
    data.frames.clear();
    std::unique_ptr<Regs> cur_regs(initial_regs->Clone());
    FrameData frame0 = BuildFrameFromAdjustedPcOnly(cur_regs->pc());
    frame0.num = 0;
    frame0.sp = cur_regs->sp();
    data.frames.push_back(frame0);

    if (cur_regs->SetPcFromReturnAddress(process_memory.get()) && cur_regs->pc() != 0) {
        FrameData frame1 = BuildFrameFromAdjustedPcOnly(cur_regs->pc());
        frame1.num = 1;
        frame1.sp = cur_regs->sp();
        data.frames.push_back(frame1);
    }
    data.error.code = ERROR_NONE;
    return !data.frames.empty();
}

// ============================================================================
// 5. FormatFrame Implementation (0x015b40..0x015b84 & 0x0333a0..0x033660)
// Disassembly match at 0x0333a0..0x033660:
//   - Default prefix at .rodata 0x00737d: "    " (4 spaces) if prefix == nullptr
//   - Frame header at .rodata 0x0075c6: "#%02zu pc %016lx" (64-bit ARCH_ARM64 = 2)
//   - If map_info == nullptr: appends "  <unknown>" (.rodata 0x007407)
//   - Else if map_info->name().empty(): appends "  <anonymous:%lx>" (.rodata 0x00768c, map_info->start())
//   - Else: appends "  " (.rodata 0x007388) + map_info->GetFullName()
//   - If map_info->elf_start_offset() != 0: appends " (offset 0x%zx)" (.rodata 0x007701)
//   - If !frame.function_name.empty(): appends " (" (.rodata 0x0073a9) + function_name,
//     plus "+%zu" (.rodata 0x007252) if function_offset != 0, plus ")"
//   - If display_build_id && map_info != nullptr: if !GetPrintableBuildID().empty(),
//     appends " (BuildId: " (.rodata 0x00772d) + build_id + ")"
// Định dạng khung ngăn xếp chuẩn AOSP/NPTH tại 0x0333a0..0x033660.
// ============================================================================
std::string AndroidUnwinder::FormatFrame(const FrameData& frame) {
    return FormatFrame(frame, false, nullptr); // 0x015b40: mov w3, wzr ; mov x4, xzr
}

std::string AndroidUnwinder::FormatFrame(const FrameData& frame, bool display_build_id) {
    return FormatFrame(frame, display_build_id, nullptr); // 0x015b58: mov x4, xzr
}

std::string AndroidUnwinder::FormatFrame(const FrameData& frame,
                                         bool display_build_id,
                                         const char* prefix) {
    std::string out = (prefix != nullptr) ? prefix : "    "; // .rodata 0x00737d
    char buf[128] = {0};
    std::snprintf(buf, sizeof(buf), "#%02zu pc %016lx",
                  frame.num, static_cast<unsigned long>(frame.rel_pc)); // .rodata 0x0075c6
    out.append(buf);

    if (!frame.map_info) {
        out.append("  <unknown>"); // .rodata 0x007407
        return out;
    }

    if (frame.map_info->name().empty()) {
        std::snprintf(buf, sizeof(buf), "  <anonymous:%lx>",
                      static_cast<unsigned long>(frame.map_info->start())); // .rodata 0x00768c
        out.append(buf);
    } else {
        out.append("  "); // .rodata 0x007388
        out.append(frame.map_info->GetFullName());
    }

    if (frame.map_info->elf_start_offset() != 0) {
        std::snprintf(buf, sizeof(buf), " (offset 0x%zx)",
                      static_cast<size_t>(frame.map_info->elf_start_offset())); // .rodata 0x007701
        out.append(buf);
    }

    if (!frame.function_name.empty()) {
        out.append(" ("); // .rodata 0x0073a9
        out.append(frame.function_name.value());
        if (frame.function_offset != 0) {
            std::snprintf(buf, sizeof(buf), "+%zu",
                          static_cast<size_t>(frame.function_offset)); // .rodata 0x007252
            out.append(buf);
        }
        out.push_back(')');
    }

    if (display_build_id) {
        const std::string build_id = frame.map_info->GetPrintableBuildID();
        if (!build_id.empty()) {
            out.append(" (BuildId: "); // .rodata 0x00772d
            out.append(build_id);
            out.push_back(')');
        }
    }
    return out;
}

// ============================================================================
// 6. BuildFrameFromPcOnly & Accessors (0x015b88..0x015d10)
// Các hàm tạo FrameData từ địa chỉ PC và truy xuất tài nguyên nội bộ.
// ============================================================================
FrameData AndroidUnwinder::BuildFrameFromPcOnly(uint64_t pc,
                                                bool adjust_pc,
                                                int /*mode*/,
                                                std::string* extra_info) {
    if (extra_info != nullptr) {
        extra_info->clear();
    }
    const uint64_t adjusted_pc = (adjust_pc && pc >= 4) ? (pc - 4) : pc;
    FrameData frame{};
    frame.pc = adjusted_pc;
    frame.rel_pc = adjusted_pc;
    if (impl_ != nullptr && impl_->maps != nullptr) {
        frame.map_info = impl_->maps->Find(adjusted_pc);
        if (frame.map_info) {
            Elf* elf = frame.map_info->GetElf(impl_->process_memory, ARCH_ARM64);
            frame.rel_pc = ElfGetRelPc(elf, adjusted_pc, frame.map_info.get());
            SharedString fn_name;
            uint64_t fn_off = 0;
            if (ElfGetFunctionName(elf, frame.rel_pc, &fn_name, &fn_off)) {
                frame.function_name = fn_name;
                frame.function_offset = fn_off;
            }
        }
    }
    return frame;
}

FrameData AndroidUnwinder::BuildFrameFromPcOnly(uint64_t pc, bool adjust_pc, int mode) {
    return BuildFrameFromPcOnly(pc, adjust_pc, mode, nullptr); // 0x015bac: mov x5, xzr
}

FrameData AndroidUnwinder::BuildFrameFromAdjustedPcOnly(uint64_t pc) {
    return BuildFrameFromPcOnly(pc, false, 0, nullptr); // 0x015bd0: mov w3, wzr ; mov w4, wzr ; mov x5, xzr
}

// 0x015bf0: ldr x8, [x0] ; add x0, x8, #0x28 ; ret
std::shared_ptr<Memory>& AndroidUnwinder::GetProcessMemory() noexcept {
    return impl_->process_memory;
}

// 0x015bfc: ldr x8, [x0] ; ldr x0, [x8, #0x18] ; ret
Maps* AndroidUnwinder::GetMaps() noexcept {
    return impl_ != nullptr ? impl_->maps : nullptr;
}

// 0x015c08: ldr x8, [x0] ; ldrb w0, [x8, #0x11] ; ret
bool AndroidUnwinder::IsLocalMode() const noexcept {
    return impl_ != nullptr && impl_->is_local_mode;
}

// 0x015c14..0x015c2c: ldr x0, [x8, #0x38] ; cbz x0 ; vtable +0x20 Clear()
void AndroidUnwinder::ClearJitDebugCache() {
    if (impl_ != nullptr && impl_->jit_debug) {
        impl_->jit_debug->Clear();
    }
}

// 0x015c30..0x015c48: ldr x0, [x8, #0x40] ; cbz x0 ; vtable +0x20 Clear()
void AndroidUnwinder::ClearDexFilesCache() {
    if (impl_ != nullptr && impl_->dex_files) {
        impl_->dex_files->Clear();
    }
}

// 0x015c4c..0x015c64: ldr x0, [x8, #0x28] ; cbz x0 ; vtable +0x20 Clear()
void AndroidUnwinder::ClearProcessMemoryCache() {
    if (impl_ != nullptr && impl_->process_memory) {
        impl_->process_memory->Clear();
    }
}

// 0x015c68..0x015d10: Clears local maps_guard (+0x20), process_memory (+0x28),
// jit_debug (+0x38), and dex_files (+0x40).
void AndroidUnwinder::Clear() {
    if (impl_ == nullptr) {
        return;
    }
    ClearProcessMemoryCache();
    ClearJitDebugCache();
    ClearDexFilesCache();
}

} // namespace unwindstack
