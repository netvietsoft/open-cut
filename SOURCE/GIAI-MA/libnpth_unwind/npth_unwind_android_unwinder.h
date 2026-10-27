// ============================================================================
// File: npth_unwind_android_unwinder.h
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 declarations for unwindstack::AndroidUnwinderData
// (0x01419c..0x014428), unwindstack::AndroidUnwinder (0x0155fc..0x015d14),
// unwindstack::DemangleNameIfNeeded (0x015d14..0x015de4), and the 15-entry
// ErrorCode lookup table at .data.rel.ro 0x038420.
//
// Mô tả (VI):
// Khai báo C++17 tái tạo sạch cho unwindstack::AndroidUnwinderData
// (0x01419c..0x014428), unwindstack::AndroidUnwinder (0x0155fc..0x015d14),
// unwindstack::DemangleNameIfNeeded (0x015d14..0x015de4) và bảng 15 chuỗi
// mã lỗi ErrorCode tại .data.rel.ro 0x038420.
// ============================================================================

#pragma once

#include "npth_unwind_maps_elf.h"
#include "npth_unwind_regs_dwarf.h"
#include "npth_unwind_types.h"

namespace unwindstack {

// ============================================================================
// 1. 15-Entry ErrorCode Table (.data.rel.ro 0x038420, file offset 0x034420)
// Bảng 15 phần tử ánh xạ mã lỗi sang chuỗi .rodata tại .data.rel.ro 0x038420.
// ============================================================================
const std::array<ErrorCodeTableEntry, 15>& GetNpthUnwindErrorCodeTable15() noexcept;
const char* GetErrorCodeString(ErrorCode error) noexcept;

// ============================================================================
// 2. DemangleNameIfNeeded (0x015d14..0x015de4)
// Handles "__dl_" prefix (.rodata 0x00752e, length 5) and Itanium C++ "_Z"
// mangled symbol names.
// Giải mã tên hàm C++ Itanium ABI có hỗ trợ tiền tố "__dl_" của linker.
// ============================================================================
std::string DemangleNameIfNeeded(const std::string& name);

// ============================================================================
// 3. AndroidUnwinderData (0x40 = 64 bytes, 0x01419c..0x014428)
// Cấu trúc lưu kết quả gỡ ngăn xếp (danh sách frames, mã lỗi, ngữ cảnh DEX).
// ============================================================================
struct AndroidUnwinderData {
    std::vector<FrameData> frames;                          // +0x00..0x17 (ldp x8, x21, [x0] at 0x0141ac)
    ErrorData error;                                        // +0x18..0x27 (code at +0x18, address at +0x20)
    std::optional<std::unique_ptr<Regs>> saved_initial_regs;// +0x28..0x37
    DexPositionInfoContext* dex_context = nullptr;          // +0x38 (ldr x0, [x0, #0x38] at 0x0143f0)

    AndroidUnwinderData() = default;
    explicit AndroidUnwinderData(size_t max_frames) {
        frames.reserve(max_frames);
    }
    ~AndroidUnwinderData() {
        FreeContext();
    }

    void DemangleFunctionNames();                           // 0x01419c (208 B)
    std::string GetErrorString();                           // 0x014364 (140 B)
    DexPositionInfoContext* GetPositionInfosForDex();       // 0x0143f0 (8 B)
    void FreeContext();                                     // 0x0143f8 (52 B)
};

// ============================================================================
// 4. AndroidUnwinder (0x0155fc..0x015d14 — 22 exported STT_FUNC methods)
// Holds pointer to 0x48 (72-byte) Impl struct.
// Lớp điều phối gỡ ngăn xếp AndroidUnwinder (gồm 22 phương thức xuất khẩu).
// ============================================================================
class JitDebug {
public:
    virtual ~JitDebug() = default;
    virtual void Clear() {}
};

class DexFiles {
public:
    virtual ~DexFiles() = default;
    virtual void Clear() {}
};

class AndroidUnwinder {
public:
    struct Impl {
        int pid = -1;                                       // +0x00 (str w22, [x21] at 0x015634)
        uint64_t max_frames = 256;                          // +0x08 (str xzr, [x21, #8] at 0x015638)
        bool initialized = false;                           // +0x10 (strb wzr, [x21, #0x10] at 0x01563c)
        bool is_local_mode = false;                         // +0x11 (strb w8, [x21, #0x11] at 0x015664)
        uint8_t pad_12[6] = {0};
        Maps* maps = nullptr;                               // +0x18 (stp x20, xzr, [x21, #0x18] at 0x015668)
        std::unique_ptr<Maps> maps_guard;                   // +0x20
        std::shared_ptr<Memory> process_memory;             // +0x28..0x37 (stp x24, x25, [x21, #0x28] at 0x01566c)
        std::unique_ptr<JitDebug> jit_debug;                // +0x38 (stp xzr, xzr, [x21, #0x38] at 0x015670)
        std::unique_ptr<DexFiles> dex_files;                // +0x40
    };

    AndroidUnwinder(int pid, Maps* maps, std::shared_ptr<Memory> process_memory); // 0x0155fc
    ~AndroidUnwinder();                                                           // 0x01568c

    AndroidUnwinder(const AndroidUnwinder&) = delete;
    AndroidUnwinder& operator=(const AndroidUnwinder&) = delete;

    bool Initialize(ErrorData& error);                                            // 0x015700
    bool Unwind(int tid, AndroidUnwinderData& data);                              // 0x015708
    bool Unwind(void* ucontext, AndroidUnwinderData& data);                       // 0x015ab0
    bool Unwind(const Registers& initial_regs, AndroidUnwinderData& data);        // 0x015b28
    bool Unwind(const Registers& initial_regs,
                std::shared_ptr<Memory> process_memory,
                AndroidUnwinderData& data);                                       // 0x015b34

    std::string FormatFrame(const FrameData& frame);                              // 0x015b40
    std::string FormatFrame(const FrameData& frame, bool display_build_id);       // 0x015b58
    std::string FormatFrame(const FrameData& frame,
                            bool display_build_id,
                            const char* prefix);                                  // 0x015b70

    FrameData BuildFrameFromPcOnly(uint64_t pc,
                                   bool adjust_pc,
                                   int mode,
                                   std::string* extra_info);                      // 0x015b88
    FrameData BuildFrameFromPcOnly(uint64_t pc, bool adjust_pc, int mode);        // 0x015bac
    FrameData BuildFrameFromAdjustedPcOnly(uint64_t pc);                          // 0x015bd0

    std::shared_ptr<Memory>& GetProcessMemory() noexcept;                         // 0x015bf0
    Maps* GetMaps() noexcept;                                                     // 0x015bfc
    bool IsLocalMode() const noexcept;                                            // 0x015c08

    void ClearJitDebugCache();                                                    // 0x015c14
    void ClearDexFilesCache();                                                    // 0x015c30
    void ClearProcessMemoryCache();                                               // 0x015c4c
    void Clear();                                                                 // 0x015c68

    Impl* impl() const noexcept { return impl_; }

private:
    bool InternalInitialize(ErrorData& error);                                    // 0x01449c
    bool InternalUnwind(Regs* initial_regs,
                        std::shared_ptr<Memory> process_memory,
                        AndroidUnwinderData& data);                               // 0x014d5c / 0x014dc0

    Impl* impl_ = nullptr; // +0x00 (str x21, [x19] at 0x015674)
};

} // namespace unwindstack
