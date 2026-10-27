// ============================================================================
// File: npth_unwind_maps_elf.h
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 declarations for unwindstack::Memory, unwindstack::Elf,
// unwindstack::MapInfo (0x028550..0x02aa3c), unwindstack::Maps, and the
// 23 exported Maps/Memory/Elf helper APIs (0x026ba0..0x0274ec).
//
// Mô tả (VI):
// Khai báo C++17 tái tạo sạch cho unwindstack::Memory, unwindstack::Elf,
// unwindstack::MapInfo (0x028550..0x02aa3c), unwindstack::Maps và 23 hàm API
// xuất khẩu nhóm Maps/Memory/Elf (0x026ba0..0x0274ec).
// ============================================================================

#pragma once

#include "npth_unwind_regs_dwarf.h"
#include "npth_unwind_types.h"

#include <unordered_map>

namespace unwindstack {

// ============================================================================
// 1. Memory Hierarchy (vtable dispatch verified at 0x0272a4..0x0272dc)
// Hệ thống lớp đọc bộ nhớ tiến trình và bộ nhớ ngoại tuyến (Offline Memory).
// ============================================================================
class Memory {
public:
    virtual ~Memory() = default;

    // vtable +0x18 (0x0272a8: ldr x4, [x8, #0x18] ; br x4)
    virtual bool ReadString(uint64_t addr, std::string* dst, size_t max_read);

    // vtable +0x20 (0x015c5c: ldr x1, [x8, #0x20] ; br x1)
    virtual void Clear() {}

    // vtable +0x30 (0x0272b4: ldr x4, [x8, #0x30] ; br x4)
    virtual size_t Read(uint64_t addr, void* dst, size_t size) = 0;

    bool ReadFully(uint64_t addr, void* dst, size_t size);
};

class MemoryOffline final : public Memory {
public:
    MemoryOffline(const uint8_t* data, uint64_t start, uint64_t end);
    ~MemoryOffline() override = default;

    size_t Read(uint64_t addr, void* dst, size_t size) override;
    uint64_t start() const noexcept { return start_; }
    uint64_t end() const noexcept { return end_; }

private:
    std::vector<uint8_t> data_;
    uint64_t start_ = 0;
    uint64_t end_ = 0;
};

class MemoryOfflineContainer final : public Memory {
public:
    MemoryOfflineContainer(uint64_t start, uint64_t end);
    ~MemoryOfflineContainer() override = default;

    size_t Read(uint64_t addr, void* dst, size_t size) override;

private:
    uint64_t start_ = 0;
    uint64_t end_ = 0;
    std::vector<uint8_t> stack_snapshot_;
};

// ============================================================================
// 2. Elf Representation (0x0237e8..0x0274b0)
// Lớp phân tích ảnh nhị phân ELF64/ELF32, symbol table và .gnu_debugdata.
// ============================================================================
class Elf {
public:
    explicit Elf(std::shared_ptr<Memory> memory, uint64_t load_bias = 0, bool valid = true);
    ~Elf() = default;

    bool valid() const noexcept { return valid_; }
    uint64_t GetLoadBias() const noexcept { return load_bias_; }
    void SetLoadBias(uint64_t bias) noexcept { load_bias_ = bias; }

    std::string GetSoname() const;                                                    // 0x0237e8 / 0x027384
    bool GetFunctionName(uint64_t addr, SharedString* name, uint64_t* func_offset);   // 0x02383c / 0x02730c
    bool GetGlobalVariable(const std::string& name, uint64_t* memory_address);        // 0x0238cc / 0x027310
    bool GetGlobalVariableOffset(const std::string& name, uint64_t* memory_offset);   // 0x027314

    void RegisterSymbol(const std::string& name, uint64_t vaddr, uint64_t size, bool is_object = false);
    void SetSoname(std::string soname) { soname_ = std::move(soname); }
    void SetGnuDebugdataInterface(std::shared_ptr<Elf> gnu_debugdata) { gnu_debugdata_ = std::move(gnu_debugdata); }

    static void SetCachingEnabled(bool enable); // 0x027390
    static bool CachingEnabled() noexcept;
    static void ClearCache();                   // 0x027450

private:
    struct SymbolRecord {
        std::string name;
        uint64_t vaddr = 0;
        uint64_t size = 0;
        bool is_object = false;
    };

    bool valid_ = false;                        // +0x00 (ldrb w8, [x0] at 0x027320)
    uint64_t load_bias_ = 0;                    // +0x08 (ldr x9, [x0, #8] at 0x0272e8)
    std::shared_ptr<Memory> memory_;            // +0x10
    std::shared_ptr<Elf> gnu_debugdata_;        // +0x50 (ldr x0, [x21, #0x50] at 0x027344)
    std::string soname_;
    std::vector<SymbolRecord> symbols_;
};

// ============================================================================
// 3. MapInfo (0x028550..0x02aa3c — 5 exported STT_FUNC methods)
// Mô tả vùng ánh xạ bộ nhớ (/proc/[pid]/maps) kèm siêu dữ liệu ELF & BuildID.
// ============================================================================
class MapInfo {
public:
    MapInfo(uint64_t start, uint64_t end, uint64_t offset, uint64_t flags, const std::string& name);
    ~MapInfo();

    MapInfo(const MapInfo&) = delete;
    MapInfo& operator=(const MapInfo&) = delete;

    uint64_t start() const noexcept { return start_; }
    uint64_t end() const noexcept { return end_; }
    uint64_t offset() const noexcept { return offset_; }
    uint16_t flags() const noexcept { return flags_; }
    const SharedString& name() const noexcept { return name_; }
    uint64_t elf_offset() const noexcept;
    uint64_t elf_start_offset() const noexcept;

    ElfFields& GetElfFields();                                                  // 0x028550 (136 B)
    Elf* GetElf(const std::shared_ptr<Memory>& process_memory, ArchEnum expected_arch = ARCH_ARM64); // 0x02895c (5,244 B)
    std::string GetFullName();                                                  // 0x029ec8 (444 B)
    SharedString GetBuildID();                                                  // 0x02a084 (2,176 B)
    std::string GetPrintableBuildID();                                          // 0x02a904 (312 B)

    void SetRawBuildId(std::string raw_build_id);

private:
    uint64_t start_ = 0;                        // +0x00 (ldr x8, [x2] at 0x0272e4)
    uint64_t end_ = 0;                          // +0x08
    uint64_t offset_ = 0;                       // +0x10
    uint16_t flags_ = 0;                        // +0x18
    SharedString name_;                         // +0x20 (ldr x8, [x22, #0x20] at 0x029f1c)
    std::atomic<ElfFields*> elf_fields_{nullptr}; // +0x30 (add x20, x0, #0x30; ldar x19, [x20] at 0x028558)
};

// ============================================================================
// 4. Maps Hierarchy (0x026ba0..0x026d90)
// Lớp quản lý danh sách vùng ánh xạ bộ nhớ (FileMaps, BufferMaps).
// ============================================================================
class Maps {
public:
    Maps() = default;
    virtual ~Maps();

    // vtable +0x10 (0x026d80: ldr x2, [x9, #0x10] ; br x2)
    virtual std::shared_ptr<MapInfo> Find(uint64_t pc);

    // vtable +0x18 (0x026d74: ldr x1, [x8, #0x18] ; br x1)
    virtual bool Parse();

    virtual const std::string GetMapsFile() const { return ""; }

    const std::vector<std::shared_ptr<MapInfo>>& GetMapList() const noexcept { return maps_; }
    void Add(uint64_t start, uint64_t end, uint64_t offset, uint64_t flags, const std::string& name);
    size_t Total() const noexcept { return maps_.size(); }

protected:
    std::vector<std::shared_ptr<MapInfo>> maps_; // +0x08..0x1F (add x0, x0, #8 at 0x026d88)
};

class FileMaps final : public Maps {
public:
    explicit FileMaps(const char* filename);
    ~FileMaps() override = default;
    const std::string GetMapsFile() const override { return filename_; }
    bool Parse() override;

private:
    std::string filename_; // +0x20
};

class BufferMaps final : public Maps {
public:
    explicit BufferMaps(const char* buffer);
    ~BufferMaps() override = default;
    bool Parse() override;

private:
    const char* buffer_ = nullptr; // +0x20 (str x19, [x0, #0x20] at 0x026d4c)
};

// ============================================================================
// 5. Exported C++/NPTH Helper Functions (0x026ba0..0x0274ec)
// 23 hàm xuất khẩu trong namespace unwindstack (0x026ba0..0x0274ec).
// ============================================================================
Maps* CreateFileMaps(const char* file);                                                 // 0x026ba0
Maps* CreateBufferMaps(void* buffer);                                                   // 0x026d30
void freeMaps(Maps* maps);                                                              // 0x026d5c
bool ParseMaps(Maps* maps);                                                             // 0x026d70
std::shared_ptr<MapInfo> FindInMaps(Maps* maps, uint64_t pc);                           // 0x026d7c
const std::vector<std::shared_ptr<MapInfo>>* GetMapInfoList(const Maps* maps) noexcept; // 0x026d88

std::shared_ptr<Memory> CreateOfflineMemory(const void* data, uint64_t start, uint64_t end); // 0x026d90
std::shared_ptr<Memory> CreateOfflineContainerMemory(uint64_t start, uint64_t end);          // 0x026df8
std::shared_ptr<Memory> CreateOfflineUnwindMemory(int tid, Registers* regs);                 // 0x026e6c

bool ReadStringFromMemory(Memory* memory, uint64_t addr, std::string* dst, size_t max_read); // 0x0272a4
size_t ReadFromMemory(Memory* memory, uint64_t addr, void* dst, size_t size);                // 0x0272b0
bool ReadFullyFromMemory(Memory* memory, uint64_t addr, void* dst, size_t size);             // 0x0272bc

uint64_t ElfGetRelPc(Elf* elf, uint64_t pc, MapInfo* map_info);                              // 0x0272e0
bool ElfGetFunctionName(Elf* elf, uint64_t addr, SharedString* name, uint64_t* func_offset); // 0x02730c
bool ElfGetGlobalVariable(Elf* elf, const std::string& name, uint64_t* memory_address);      // 0x027310
bool ElfGetVariableOffset(Elf* elf, const std::string& name, uint64_t* memory_offset);       // 0x027314
std::string ElfGetSoname(Elf* elf);                                                          // 0x027384
void ElfSetCachingEnabled(bool enable);                                                      // 0x027390
void ElfClearCache();                                                                        // 0x027450

uint64_t GetDexCachedSize() noexcept;                                                        // 0x0274b4
void SetDexCacheLimitSize(uint64_t limit_size) noexcept;                                     // 0x0274c4
void SetApiLevel(int api_level) noexcept;                                                    // 0x0274d0
int GetApiLevel() noexcept;
void SetGlobalMode(uint32_t mode) noexcept;                                                  // 0x0274e0
uint32_t GetGlobalMode() noexcept;

} // namespace unwindstack
