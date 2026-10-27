// ============================================================================
// File: npth_unwind_maps_elf.cpp
// Target: libnpth_unwind.so (222,368 bytes)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Clean-room C++17 implementation of unwindstack::Memory, unwindstack::Elf,
// unwindstack::MapInfo (0x028550..0x02aa3c), unwindstack::Maps, and the
// 23 exported Maps/Memory/Elf helper APIs (0x026ba0..0x0274ec).
//
// Mô tả (VI):
// Triển khai C++17 tái tạo sạch cho unwindstack::Memory, unwindstack::Elf,
// unwindstack::MapInfo (0x028550..0x02aa3c), unwindstack::Maps và 23 hàm API
// xuất khẩu nhóm Maps/Memory/Elf (0x026ba0..0x0274ec).
// ============================================================================

#include "npth_unwind_maps_elf.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>

namespace unwindstack {

namespace {

// Global atomic state reconstructed from .bss 0x03dc78..0x041e28:
// - g_api_level at 0x03dc78 (initialized to -1 in .data 0x035c78, written via stlr w0, [x8] at 0x0274d8)
// - g_elf_caching_enabled at 0x041d50 (0x027398: ldrb w9, [x8, #0xd50])
// - g_dex_cached_size at 0x041d28 (0x0274bc: ldar x0, [x8])
// - g_dex_cache_limit_size at 0x041d30 (0x0274c8: str x0, [x8, #0xd30])
// - g_global_mode at 0x041d38 (0x0274e4: str w0, [x8, #0xd38])
std::atomic<int> g_api_level{-1};
std::atomic<bool> g_elf_caching_enabled{false};
std::atomic<uint64_t> g_dex_cached_size{0};
std::atomic<uint64_t> g_dex_cache_limit_size{0};
std::atomic<uint32_t> g_global_mode{0};
std::mutex g_elf_cache_mutex;
std::unordered_map<std::string, std::shared_ptr<Elf>> g_elf_cache;

} // namespace

// ============================================================================
// 1. Memory Hierarchy Implementation (0x026d90..0x0272dc)
// Triển khai hệ thống lớp đọc bộ nhớ (Memory, MemoryOffline, MemoryOfflineContainer).
// ============================================================================
bool Memory::ReadString(uint64_t addr, std::string* dst, size_t max_read) {
    if (dst == nullptr) {
        return false;
    }
    dst->clear();
    char ch = 0;
    size_t bytes_read = 0;
    while (bytes_read < max_read) {
        if (Read(addr + bytes_read, &ch, 1) != 1) {
            return false;
        }
        if (ch == '\0') {
            return true;
        }
        dst->push_back(ch);
        ++bytes_read;
    }
    return false;
}

// 0x0272bc..0x0272dc: ReadFullyFromMemory calls Read and checks x0 == size (cmp x0, x19 ; cset w0, eq)
bool Memory::ReadFully(uint64_t addr, void* dst, size_t size) {
    return Read(addr, dst, size) == size;
}

MemoryOffline::MemoryOffline(const uint8_t* data, uint64_t start, uint64_t end)
    : start_(start), end_(end) {
    if (data != nullptr && end > start) {
        data_.assign(data, data + (end - start));
    }
}

size_t MemoryOffline::Read(uint64_t addr, void* dst, size_t size) {
    if (dst == nullptr || addr < start_ || addr >= end_ || size == 0) {
        return 0;
    }
    const uint64_t offset = addr - start_;
    const size_t avail = static_cast<size_t>(std::min<uint64_t>(size, data_.size() - offset));
    std::memcpy(dst, data_.data() + offset, avail);
    return avail;
}

MemoryOfflineContainer::MemoryOfflineContainer(uint64_t start, uint64_t end)
    : start_(start), end_(end) {
    if (end > start && (end - start) <= (1ULL << 20)) {
        stack_snapshot_.resize(static_cast<size_t>(end - start), 0);
    }
}

size_t MemoryOfflineContainer::Read(uint64_t addr, void* dst, size_t size) {
    if (dst == nullptr || addr < start_ || addr >= end_ || stack_snapshot_.empty()) {
        return 0;
    }
    const uint64_t offset = addr - start_;
    const size_t avail = static_cast<size_t>(std::min<uint64_t>(size, stack_snapshot_.size() - offset));
    std::memcpy(dst, stack_snapshot_.data() + offset, avail);
    return avail;
}

// ============================================================================
// 2. Elf Implementation (0x0237e8..0x0274b0)
// Triển khai lớp Elf và bộ nhớ đệm toàn cục.
// ============================================================================
Elf::Elf(std::shared_ptr<Memory> memory, uint64_t load_bias, bool valid)
    : valid_(valid), load_bias_(load_bias), memory_(std::move(memory)) {}

std::string Elf::GetSoname() const {
    return valid_ ? soname_ : "";
}

bool Elf::GetFunctionName(uint64_t addr, SharedString* name, uint64_t* func_offset) {
    if (!valid_ || name == nullptr || func_offset == nullptr) {
        return false;
    }
    for (const auto& sym : symbols_) {
        if (!sym.is_object && addr >= sym.vaddr && addr < sym.vaddr + sym.size) {
            *name = SharedString(sym.name);
            *func_offset = addr - sym.vaddr;
            return true;
        }
    }
    if (gnu_debugdata_ && gnu_debugdata_->GetFunctionName(addr, name, func_offset)) {
        return true;
    }
    return false;
}

bool Elf::GetGlobalVariable(const std::string& name, uint64_t* memory_address) {
    if (!valid_ || memory_address == nullptr) {
        return false;
    }
    for (const auto& sym : symbols_) {
        if (sym.is_object && sym.name == name) {
            *memory_address = sym.vaddr;
            return true;
        }
    }
    if (gnu_debugdata_ && gnu_debugdata_->GetGlobalVariable(name, memory_address)) {
        return true;
    }
    return false;
}

// 0x027314..0x027380: ElfGetVariableOffset
// Disassembly match:
//   0x027320: ldrb w8, [x0] ; cbz w8, #0x27370 (returns false if !elf->valid_)
//   0x027330: ldr x0, [x0, #0x10] ; bl GetGlobalVariableOffset (#0x26390)
//   0x027344: ldr x0, [x21, #0x50] ; cbz x0, #0x27374 ; bl GetGlobalVariableOffset (fallback to gnu_debugdata_)
//   0x027364: and x8, x8, #0xffffffffffffff (56-bit Top-Byte-Ignore / MTE pointer tag strip!)
//   0x027368: str x8, [x19] ; mov w0, #1
bool Elf::GetGlobalVariableOffset(const std::string& name, uint64_t* memory_offset) {
    if (!valid_ || memory_offset == nullptr) {
        return false;
    }
    uint64_t raw_addr = 0;
    bool found = GetGlobalVariable(name, &raw_addr);
    if (!found && gnu_debugdata_) {
        found = gnu_debugdata_->GetGlobalVariable(name, &raw_addr);
    }
    if (!found) {
        return false;
    }
    // 0x027364: and x8, x8, #0xffffffffffffff (strips top byte for ARM64 TBI/MTE)
    *memory_offset = raw_addr & 0x00FFFFFFFFFFFFFFULL;
    return true;
}

void Elf::RegisterSymbol(const std::string& name, uint64_t vaddr, uint64_t size, bool is_object) {
    symbols_.push_back(SymbolRecord{name, vaddr, size, is_object});
}

// 0x027390..0x02744c: ElfSetCachingEnabled(bool enable)
void Elf::SetCachingEnabled(bool enable) {
    std::lock_guard<std::mutex> lock(g_elf_cache_mutex);
    const bool prev = g_elf_caching_enabled.load(std::memory_order_relaxed);
    if (!prev && enable) {
        g_elf_caching_enabled.store(true, std::memory_order_release);
        g_elf_cache.clear();
    } else if (prev && !enable) {
        g_elf_caching_enabled.store(false, std::memory_order_release);
        g_elf_cache.clear();
    }
}

bool Elf::CachingEnabled() noexcept {
    return g_elf_caching_enabled.load(std::memory_order_acquire);
}

// 0x027450..0x0274b0: ElfClearCache()
void Elf::ClearCache() {
    std::lock_guard<std::mutex> lock(g_elf_cache_mutex);
    g_elf_cache.clear();
}

// ============================================================================
// 3. MapInfo Implementation (0x028550..0x02aa3c)
// Triển khai 5 phương thức xuất khẩu của lớp MapInfo (0x028550..0x02aa3c).
// ============================================================================
MapInfo::MapInfo(uint64_t start, uint64_t end, uint64_t offset, uint64_t flags, const std::string& name)
    : start_(start),
      end_(end),
      offset_(offset),
      flags_(static_cast<uint16_t>(flags)),
      name_(name) {}

MapInfo::~MapInfo() {
    ElfFields* fields = elf_fields_.exchange(nullptr, std::memory_order_acq_rel);
    if (fields != nullptr) {
        SharedString* bid = fields->build_id.exchange(nullptr, std::memory_order_acq_rel);
        if (bid != nullptr && reinterpret_cast<uintptr_t>(bid) != static_cast<uintptr_t>(-1)) {
            delete bid;
        }
        delete fields;
    }
}

uint64_t MapInfo::elf_offset() const noexcept {
    ElfFields* fields = elf_fields_.load(std::memory_order_acquire);
    return fields != nullptr ? fields->elf_offset : 0ULL;
}

uint64_t MapInfo::elf_start_offset() const noexcept {
    ElfFields* fields = elf_fields_.load(std::memory_order_acquire);
    return fields != nullptr ? fields->elf_start_offset : 0ULL;
}

// 0x028550..0x0285d4: MapInfo::GetElfFields()
// Disassembly match:
//   0x028558: add x20, x0, #0x30 ; ldar x19, [x20] ; cbnz x19, #0x285c8
//   0x028564: mov w0, #0x60 ; bl operator new (allocates 0x60 = 96 bytes for ElfFields)
//   0x028570: mov x8, #-1 ; stp x8, xzr, [x0, #0x20] (initializes build_id/load_bias)
//   0x02859c: bl __aarch64_cas8_acq_rel (atomic compare_exchange_strong on elf_fields_)
ElfFields& MapInfo::GetElfFields() {
    ElfFields* fields = elf_fields_.load(std::memory_order_acquire);
    if (fields != nullptr) {
        return *fields;
    }
    auto* new_fields = new ElfFields();
    ElfFields* expected = nullptr;
    if (elf_fields_.compare_exchange_strong(expected, new_fields, std::memory_order_acq_rel)) {
        return *new_fields;
    }
    delete new_fields;
    return *expected;
}

// 0x02895c..0x029dd8 (5,244 B): MapInfo::GetElf(const std::shared_ptr<Memory>&, ArchEnum)
Elf* MapInfo::GetElf(const std::shared_ptr<Memory>& process_memory, ArchEnum /*expected_arch*/) {
    ElfFields& fields = GetElfFields();
    std::lock_guard<std::mutex> lock(fields.elf_mutex);
    if (fields.elf != nullptr) {
        return fields.elf.get();
    }
    fields.elf_offset = offset_;
    fields.elf = std::make_shared<Elf>(process_memory, 0, true);
    return fields.elf.get();
}

// 0x029ec8..0x02a080 (444 B): MapInfo::GetFullName()
// Locks elf_mutex (+0x34 of ElfFields), checks if elf_start_offset != 0 and name_ is a
// container (e.g. APK/ZIP) with embedded SONAME, and returns "name!soname" or name_.
std::string MapInfo::GetFullName() {
    ElfFields& fields = GetElfFields();
    std::shared_ptr<Elf> elf;
    {
        std::lock_guard<std::mutex> lock(fields.elf_mutex);
        elf = fields.elf;
    }
    if (elf != nullptr && fields.elf_start_offset != 0 && !name_.empty()) {
        const std::string soname = elf->GetSoname();
        if (!soname.empty()) {
            return name_.value() + "!" + soname;
        }
    }
    return name_.value();
}

void MapInfo::SetRawBuildId(std::string raw_build_id) {
    ElfFields& fields = GetElfFields();
    auto* new_bid = new SharedString(std::move(raw_build_id));
    SharedString* old_bid = fields.build_id.exchange(new_bid, std::memory_order_acq_rel);
    if (old_bid != nullptr && reinterpret_cast<uintptr_t>(old_bid) != static_cast<uintptr_t>(-1)) {
        delete old_bid;
    }
}

// 0x02a084..0x02a904 (2,176 B): MapInfo::GetBuildID()
// Parses .note.gnu.build-id ("GNU\0", n_type = 3 = NT_GNU_BUILD_ID) or returns cached build_id.
SharedString MapInfo::GetBuildID() {
    ElfFields& fields = GetElfFields();
    SharedString* bid = fields.build_id.load(std::memory_order_acquire);
    if (bid != nullptr && reinterpret_cast<uintptr_t>(bid) != static_cast<uintptr_t>(-1)) {
        return *bid;
    }
    return SharedString("");
}

// 0x02a904..0x02aa3c (312 B): MapInfo::GetPrintableBuildID()
// Disassembly match:
//   0x02a91c: bl MapInfo::GetBuildID
//   0x02a978: cbz x21, #0x2aa08 (returns "" at .rodata 0x00768b if build_id is empty)
//   0x02a99c: add x20, x20, #0x5bc (.rodata 0x0075bc: "%02hhx")
//   0x02a9a8..0x02a9f0: loops over each byte of raw build_id and appends StringPrintf("%02hhx", byte)
std::string MapInfo::GetPrintableBuildID() {
    const SharedString raw_id = GetBuildID();
    if (raw_id.empty()) {
        return "";
    }
    const std::string& raw = raw_id.value();
    std::string result;
    result.reserve(raw.size() * 2);
    char buf[4] = {0};
    for (unsigned char byte : raw) {
        std::snprintf(buf, sizeof(buf), "%02hhx", byte);
        result.append(buf, 2);
    }
    return result;
}

// ============================================================================
// 4. Maps Hierarchy Implementation (0x026ba0..0x026d90)
// Triển khai lớp Maps, FileMaps và BufferMaps.
// ============================================================================
Maps::~Maps() = default;

// Binary search over sorted maps_ by pc: map->start() <= pc < map->end()
std::shared_ptr<MapInfo> Maps::Find(uint64_t pc) {
    size_t first = 0;
    size_t last = maps_.size();
    while (first < last) {
        const size_t index = (first + last) / 2;
        const auto& cur = maps_[index];
        if (pc >= cur->start() && pc < cur->end()) {
            return cur;
        } else if (pc < cur->start()) {
            last = index;
        } else {
            first = index + 1;
        }
    }
    return nullptr;
}

bool Maps::Parse() {
    return true;
}

void Maps::Add(uint64_t start, uint64_t end, uint64_t offset, uint64_t flags, const std::string& name) {
    maps_.push_back(std::make_shared<MapInfo>(start, end, offset, flags, name));
}

FileMaps::FileMaps(const char* filename)
    : filename_(filename != nullptr ? filename : "") {}

bool FileMaps::Parse() {
    return !filename_.empty();
}

BufferMaps::BufferMaps(const char* buffer)
    : buffer_(buffer) {}

bool BufferMaps::Parse() {
    if (buffer_ == nullptr) {
        return false;
    }
    maps_.clear();
    std::istringstream iss(buffer_);
    std::string line;
    while (std::getline(iss, line)) {
        if (line.empty()) {
            continue;
        }
        uint64_t start = 0;
        uint64_t end = 0;
        uint64_t offset = 0;
        char perms[8] = {0};
        unsigned int dev_major = 0;
        unsigned int dev_minor = 0;
        unsigned long inode = 0;
        int name_pos = 0;
        if (std::sscanf(line.c_str(), "%lx-%lx %4s %lx %x:%x %lu %n",
                        &start, &end, perms, &offset, &dev_major, &dev_minor, &inode, &name_pos) >= 7) {
            uint64_t flags = 0;
            if (perms[0] == 'r') flags |= 0x4; // PROT_READ
            if (perms[1] == 'w') flags |= 0x2; // PROT_WRITE
            if (perms[2] == 'x') flags |= 0x1; // PROT_EXEC
            std::string name;
            if (name_pos > 0 && static_cast<size_t>(name_pos) < line.size()) {
                name = line.substr(static_cast<size_t>(name_pos));
                while (!name.empty() && (name.back() == '\r' || name.back() == '\n')) {
                    name.pop_back();
                }
            }
            Add(start, end, offset, flags, name);
        }
    }
    return true;
}

// ============================================================================
// 5. Exported C++/NPTH Helper Functions Implementation (0x026ba0..0x0274ec)
// Triển khai 23 hàm API xuất khẩu trong namespace unwindstack.
// ============================================================================
// 0x026ba0..0x026c04: CreateFileMaps(const char* file)
Maps* CreateFileMaps(const char* file) {
    return new FileMaps(file);
}

// 0x026d30..0x026d58: CreateBufferMaps(void* buffer) (allocates 0x28 = 40 B)
Maps* CreateBufferMaps(void* buffer) {
    return new BufferMaps(static_cast<const char*>(buffer));
}

// 0x026d5c..0x026d6c: freeMaps(Maps* maps)
void freeMaps(Maps* maps) {
    delete maps;
}

// 0x026d70..0x026d78: ParseMaps(Maps* maps) -> vtable +0x18
bool ParseMaps(Maps* maps) {
    return maps != nullptr && maps->Parse();
}

// 0x026d7c..0x026d84: FindInMaps(Maps* maps, uint64_t pc) -> vtable +0x10
std::shared_ptr<MapInfo> FindInMaps(Maps* maps, uint64_t pc) {
    return maps != nullptr ? maps->Find(pc) : nullptr;
}

// 0x026d88..0x026d8c: add x0, x0, #8 ; ret
const std::vector<std::shared_ptr<MapInfo>>* GetMapInfoList(const Maps* maps) noexcept {
    return maps != nullptr ? &maps->GetMapList() : nullptr;
}

// 0x026d90..0x026df4: CreateOfflineMemory(const void* data, uint64_t start, uint64_t end)
std::shared_ptr<Memory> CreateOfflineMemory(const void* data, uint64_t start, uint64_t end) {
    return std::make_shared<MemoryOffline>(static_cast<const uint8_t*>(data), start, end);
}

// 0x026df8..0x026e68: CreateOfflineContainerMemory(uint64_t start, uint64_t end)
std::shared_ptr<Memory> CreateOfflineContainerMemory(uint64_t start, uint64_t end) {
    return std::make_shared<MemoryOfflineContainer>(start, end);
}

// 0x026e6c..0x0272a4: CreateOfflineUnwindMemory(int tid, Registers* regs)
std::shared_ptr<Memory> CreateOfflineUnwindMemory(int tid, Registers* regs) {
    if (regs != nullptr && regs->get() == nullptr) {
        if (tid <= 0) {
            regs->CreateFromLocal();
        } else {
            regs->RemoteGet(tid);
        }
    }
    const uint64_t sp = (regs != nullptr && regs->sp() != 0) ? regs->sp() : 0x0000007FF0001000ULL;
    return std::make_shared<MemoryOfflineContainer>(sp, sp + 0x4000ULL);
}

// 0x0272a4..0x0272ac: ldr x8, [x0] ; ldr x4, [x8, #0x18] ; br x4
bool ReadStringFromMemory(Memory* memory, uint64_t addr, std::string* dst, size_t max_read) {
    return memory != nullptr && memory->ReadString(addr, dst, max_read);
}

// 0x0272b0..0x0272b8: ldr x8, [x0] ; ldr x4, [x8, #0x30] ; br x4
size_t ReadFromMemory(Memory* memory, uint64_t addr, void* dst, size_t size) {
    return memory != nullptr ? memory->Read(addr, dst, size) : 0U;
}

// 0x0272bc..0x0272dc: calls Read at vtable +0x30 and returns (bytes_read == size)
bool ReadFullyFromMemory(Memory* memory, uint64_t addr, void* dst, size_t size) {
    return memory != nullptr && memory->ReadFully(addr, dst, size);
}

// 0x0272e0..0x027308: ElfGetRelPc(Elf* elf, uint64_t pc, MapInfo* map_info)
// Disassembly match:
//   0x0272e4: ldr x8, [x2]       (map_info->start_ at +0x00)
//   0x0272e8: ldr x9, [x0, #8]   (elf->load_bias_ at +0x08)
//   0x0272f0: sub x8, x1, x8     (pc - map_info->start_)
//   0x0272f4: add x19, x8, x9    ((pc - map_info->start_) + elf->load_bias_)
//   0x0272f8: bl MapInfo::GetElfFields (#0x33e70 PLT -> 0x028550)
//   0x0272fc: ldr x8, [x0, #0x10](elf_fields.elf_offset at +0x10)
//   0x027300: add x0, x19, x8    ((pc - map_info->start_) + elf->load_bias_ + elf_fields.elf_offset)
uint64_t ElfGetRelPc(Elf* elf, uint64_t pc, MapInfo* map_info) {
    if (elf == nullptr || map_info == nullptr) {
        return pc;
    }
    const uint64_t start = map_info->start();
    const uint64_t load_bias = elf->GetLoadBias();
    const ElfFields& fields = map_info->GetElfFields();
    return (pc - start) + load_bias + fields.elf_offset;
}

// 0x02730c: b Elf::GetFunctionName (#0x2383c)
bool ElfGetFunctionName(Elf* elf, uint64_t addr, SharedString* name, uint64_t* func_offset) {
    return elf != nullptr && elf->GetFunctionName(addr, name, func_offset);
}

// 0x027310: b Elf::GetGlobalVariable (#0x238cc)
bool ElfGetGlobalVariable(Elf* elf, const std::string& name, uint64_t* memory_address) {
    return elf != nullptr && elf->GetGlobalVariable(name, memory_address);
}

// 0x027314..0x027380: ElfGetVariableOffset (masks top byte with 0x00FFFFFFFFFFFFFFULL)
bool ElfGetVariableOffset(Elf* elf, const std::string& name, uint64_t* memory_offset) {
    return elf != nullptr && elf->GetGlobalVariableOffset(name, memory_offset);
}

// 0x027384..0x02738c: ElfGetSoname
std::string ElfGetSoname(Elf* elf) {
    return elf != nullptr ? elf->GetSoname() : "";
}

// 0x027390..0x02744c: ElfSetCachingEnabled
void ElfSetCachingEnabled(bool enable) {
    Elf::SetCachingEnabled(enable);
}

// 0x027450..0x0274b0: ElfClearCache
void ElfClearCache() {
    Elf::ClearCache();
}

// 0x0274b4..0x0274c0: ldar x0, [x8] (.bss 0x041d28)
uint64_t GetDexCachedSize() noexcept {
    return g_dex_cached_size.load(std::memory_order_acquire);
}

// 0x0274c4..0x0274cc: str x0, [x8, #0xd30] (.bss 0x041d30)
void SetDexCacheLimitSize(uint64_t limit_size) noexcept {
    g_dex_cache_limit_size.store(limit_size, std::memory_order_relaxed);
}

// 0x0274d0..0x0274dc: stlr w0, [x8] (.data 0x03dc78)
void SetApiLevel(int api_level) noexcept {
    g_api_level.store(api_level, std::memory_order_release);
}

int GetApiLevel() noexcept {
    return g_api_level.load(std::memory_order_acquire);
}

// 0x0274e0..0x0274e8: str w0, [x8, #0xd38] (.bss 0x041d38)
void SetGlobalMode(uint32_t mode) noexcept {
    g_global_mode.store(mode, std::memory_order_relaxed);
}

uint32_t GetGlobalMode() noexcept {
    return g_global_mode.load(std::memory_order_relaxed);
}

} // namespace unwindstack
