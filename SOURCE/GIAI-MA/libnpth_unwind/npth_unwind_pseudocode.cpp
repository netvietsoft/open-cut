// ============================================================================
// File: npth_unwind_pseudocode.cpp
// Target: libnpth_unwind.so (222,368 bytes, SHA-256: c83bb94dbfc0aa4b2d306a0b57ba7bd83c489dc08379cbb7f362c02fd481cad8)
// Task ID: TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND (Legacy: TASK_SO_073_libnpth_unwind)
//
// Description (EN):
// Master symbol table registry (all 79 exported STT_FUNC symbols in .dynsym
// from 0x01419c to 0x030354) and closed-loop mathematical & ABI verification
// engine for libnpth_unwind.so.
//
// Mô tả (VI):
// Bảng đăng ký 79 biểu tượng hàm STT_FUNC xuất khẩu trong .dynsym (0x01419c
// đến 0x030354) và bộ máy tự kiểm chứng toán học & ABI khép kín cho
// libnpth_unwind.so.
// ============================================================================

#include "npth_unwind_interface.h"

#include <cstring>

namespace unwindstack {

// ============================================================================
// 1. Complete 79-Entry .dynsym STT_FUNC Registry (0x01419c..0x030354)
// Danh mục đầy đủ 79 hàm xuất khẩu thực tế trong .dynsym của libnpth_unwind.so.
// ============================================================================
const std::array<ExportedSymbolDescriptor, 79>& GetNpthUnwindExportedSymbols79() noexcept {
    static const std::array<ExportedSymbolDescriptor, 79> kSymbols = {{
        {0x01419CU,  208U, "_ZN11unwindstack19AndroidUnwinderData21DemangleFunctionNamesEv", "unwindstack::AndroidUnwinderData::DemangleFunctionNames()"},
        {0x014364U,  140U, "_ZN11unwindstack19AndroidUnwinderData14GetErrorStringEv", "unwindstack::AndroidUnwinderData::GetErrorString()"},
        {0x0143F0U,    8U, "_ZN11unwindstack19AndroidUnwinderData22GetPositionInfosForDexEv", "unwindstack::AndroidUnwinderData::GetPositionInfosForDex()"},
        {0x0143F8U,   52U, "_ZN11unwindstack19AndroidUnwinderData11FreeContextEv", "unwindstack::AndroidUnwinderData::FreeContext()"},
        {0x0155FCU,  144U, "_ZN11unwindstack15AndroidUnwinderC1EiPNS_4MapsENSt6__ndk110shared_ptrINS_6MemoryEEE", "unwindstack::AndroidUnwinder::AndroidUnwinder(int, Maps*, std::shared_ptr<Memory>) [C1]"},
        {0x0155FCU,  144U, "_ZN11unwindstack15AndroidUnwinderC2EiPNS_4MapsENSt6__ndk110shared_ptrINS_6MemoryEEE", "unwindstack::AndroidUnwinder::AndroidUnwinder(int, Maps*, std::shared_ptr<Memory>) [C2]"},
        {0x01568CU,  116U, "_ZN11unwindstack15AndroidUnwinderD1Ev", "unwindstack::AndroidUnwinder::~AndroidUnwinder() [D1]"},
        {0x01568CU,  116U, "_ZN11unwindstack15AndroidUnwinderD2Ev", "unwindstack::AndroidUnwinder::~AndroidUnwinder() [D2]"},
        {0x015700U,    8U, "_ZN11unwindstack15AndroidUnwinder10InitializeERNS_9ErrorDataE", "unwindstack::AndroidUnwinder::Initialize(ErrorData&)"},
        {0x015708U,  936U, "_ZN11unwindstack15AndroidUnwinder6UnwindEiRNS_19AndroidUnwinderDataE", "unwindstack::AndroidUnwinder::Unwind(int, AndroidUnwinderData&)"},
        {0x015AB0U,  120U, "_ZN11unwindstack15AndroidUnwinder6UnwindEP8ucontextRNS_19AndroidUnwinderDataE", "unwindstack::AndroidUnwinder::Unwind(ucontext*, AndroidUnwinderData&)"},
        {0x015B28U,   12U, "_ZN11unwindstack15AndroidUnwinder6UnwindERKNS_9RegistersERNS_19AndroidUnwinderDataE", "unwindstack::AndroidUnwinder::Unwind(const Registers&, AndroidUnwinderData&)"},
        {0x015B34U,   12U, "_ZN11unwindstack15AndroidUnwinder6UnwindERKNS_9RegistersENSt6__ndk110shared_ptrINS_6MemoryEEERNS_19AndroidUnwinderDataE", "unwindstack::AndroidUnwinder::Unwind(const Registers&, std::shared_ptr<Memory>, AndroidUnwinderData&)"},
        {0x015B40U,   24U, "_ZN11unwindstack15AndroidUnwinder11FormatFrameERKNS_9FrameDataE", "unwindstack::AndroidUnwinder::FormatFrame(const FrameData&)"},
        {0x015B58U,   24U, "_ZN11unwindstack15AndroidUnwinder11FormatFrameERKNS_9FrameDataEb", "unwindstack::AndroidUnwinder::FormatFrame(const FrameData&, bool)"},
        {0x015B70U,   24U, "_ZN11unwindstack15AndroidUnwinder11FormatFrameERKNS_9FrameDataEbPKc", "unwindstack::AndroidUnwinder::FormatFrame(const FrameData&, bool, const char*)"},
        {0x015B88U,   36U, "_ZN11unwindstack15AndroidUnwinder20BuildFrameFromPcOnlyEmbiPNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE", "unwindstack::AndroidUnwinder::BuildFrameFromPcOnly(uint64_t, bool, int, std::string*)"},
        {0x015BACU,   36U, "_ZN11unwindstack15AndroidUnwinder20BuildFrameFromPcOnlyEmbi", "unwindstack::AndroidUnwinder::BuildFrameFromPcOnly(uint64_t, bool, int)"},
        {0x015BD0U,   32U, "_ZN11unwindstack15AndroidUnwinder28BuildFrameFromAdjustedPcOnlyEm", "unwindstack::AndroidUnwinder::BuildFrameFromAdjustedPcOnly(uint64_t)"},
        {0x015BF0U,   12U, "_ZN11unwindstack15AndroidUnwinder16GetProcessMemoryEv", "unwindstack::AndroidUnwinder::GetProcessMemory()"},
        {0x015BFCU,   12U, "_ZN11unwindstack15AndroidUnwinder7GetMapsEv", "unwindstack::AndroidUnwinder::GetMaps()"},
        {0x015C08U,   12U, "_ZNK11unwindstack15AndroidUnwinder11IsLocalModeEv", "unwindstack::AndroidUnwinder::IsLocalMode() const"},
        {0x015C14U,   28U, "_ZN11unwindstack15AndroidUnwinder18ClearJitDebugCacheEv", "unwindstack::AndroidUnwinder::ClearJitDebugCache()"},
        {0x015C30U,   28U, "_ZN11unwindstack15AndroidUnwinder18ClearDexFilesCacheEv", "unwindstack::AndroidUnwinder::ClearDexFilesCache()"},
        {0x015C4CU,   28U, "_ZN11unwindstack15AndroidUnwinder23ClearProcessMemoryCacheEv", "unwindstack::AndroidUnwinder::ClearProcessMemoryCache()"},
        {0x015C68U,  172U, "_ZN11unwindstack15AndroidUnwinder5ClearEv", "unwindstack::AndroidUnwinder::Clear()"},
        {0x015D14U,  208U, "_ZN11unwindstack20DemangleNameIfNeededERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE", "unwindstack::DemangleNameIfNeeded(const std::string&)"},
        {0x026BA0U,  104U, "_ZN11unwindstack14CreateFileMapsEPKc", "unwindstack::CreateFileMaps(const char*)"},
        {0x026D30U,   44U, "_ZN11unwindstack16CreateBufferMapsEPv", "unwindstack::CreateBufferMaps(void*)"},
        {0x026D5CU,   20U, "_ZN11unwindstack8freeMapsEPNS_4MapsE", "unwindstack::freeMaps(Maps*)"},
        {0x026D70U,   12U, "_ZN11unwindstack9ParseMapsEPNS_4MapsE", "unwindstack::ParseMaps(Maps*)"},
        {0x026D7CU,   12U, "_ZN11unwindstack10FindInMapsEPNS_4MapsEm", "unwindstack::FindInMaps(Maps*, uint64_t)"},
        {0x026D88U,    8U, "_ZN11unwindstack14GetMapInfoListEPKNS_4MapsE", "unwindstack::GetMapInfoList(const Maps*)"},
        {0x026D90U,  104U, "_ZN11unwindstack19CreateOfflineMemoryEPKvmm", "unwindstack::CreateOfflineMemory(const void*, uint64_t, uint64_t)"},
        {0x026DF8U,  116U, "_ZN11unwindstack28CreateOfflineContainerMemoryEmm", "unwindstack::CreateOfflineContainerMemory(uint64_t, uint64_t)"},
        {0x026E6CU,  888U, "_ZN11unwindstack25CreateOfflineUnwindMemoryEiPNS_9RegistersE", "unwindstack::CreateOfflineUnwindMemory(int, Registers*)"},
        {0x0272A4U,   12U, "_ZN11unwindstack20ReadStringFromMemoryEPNS_6MemoryEmPNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEm", "unwindstack::ReadStringFromMemory(Memory*, uint64_t, std::string*, size_t)"},
        {0x0272B0U,   12U, "_ZN11unwindstack14ReadFromMemoryEPNS_6MemoryEmPvm", "unwindstack::ReadFromMemory(Memory*, uint64_t, void*, size_t)"},
        {0x0272BCU,   36U, "_ZN11unwindstack19ReadFullyFromMemoryEPNS_6MemoryEmPvm", "unwindstack::ReadFullyFromMemory(Memory*, uint64_t, void*, size_t)"},
        {0x0272E0U,   44U, "_ZN11unwindstack11ElfGetRelPcEPNS_3ElfEmPNS_7MapInfoE", "unwindstack::ElfGetRelPc(Elf*, uint64_t, MapInfo*)"},
        {0x02730CU,    4U, "_ZN11unwindstack18ElfGetFunctionNameEPNS_3ElfEmPNS_12SharedStringEPm", "unwindstack::ElfGetFunctionName(Elf*, uint64_t, SharedString*, uint64_t*)"},
        {0x027310U,    4U, "_ZN11unwindstack20ElfGetGlobalVariableEPNS_3ElfERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPm", "unwindstack::ElfGetGlobalVariable(Elf*, const std::string&, uint64_t*)"},
        {0x027314U,  112U, "_ZN11unwindstack20ElfGetVariableOffsetEPNS_3ElfERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPm", "unwindstack::ElfGetVariableOffset(Elf*, const std::string&, uint64_t*)"},
        {0x027384U,   12U, "_ZN11unwindstack12ElfGetSonameEPNS_3ElfE", "unwindstack::ElfGetSoname(Elf*)"},
        {0x027390U,  192U, "_ZN11unwindstack20ElfSetCachingEnabledEb", "unwindstack::ElfSetCachingEnabled(bool)"},
        {0x027450U,  100U, "_ZN11unwindstack13ElfClearCacheEv", "unwindstack::ElfClearCache()"},
        {0x0274B4U,   16U, "_ZN11unwindstack16GetDexCachedSizeEv", "unwindstack::GetDexCachedSize()"},
        {0x0274C4U,   12U, "_ZN11unwindstack20SetDexCacheLimitSizeEm", "unwindstack::SetDexCacheLimitSize(uint64_t)"},
        {0x0274D0U,   16U, "_ZN11unwindstack11SetApiLevelEi", "unwindstack::SetApiLevel(int)"},
        {0x0274E0U,   12U, "_ZN11unwindstack13SetGlobalModeEj", "unwindstack::SetGlobalMode(uint32_t)"},
        {0x028550U,  136U, "_ZN11unwindstack7MapInfo12GetElfFieldsEv", "unwindstack::MapInfo::GetElfFields()"},
        {0x02895CU, 5244U, "_ZN11unwindstack7MapInfo6GetElfERKNSt6__ndk110shared_ptrINS_6MemoryEEE", "unwindstack::MapInfo::GetElf(const std::shared_ptr<Memory>&)"},
        {0x029EC8U,  444U, "_ZN11unwindstack7MapInfo11GetFullNameEv", "unwindstack::MapInfo::GetFullName()"},
        {0x02A084U, 2176U, "_ZN11unwindstack7MapInfo10GetBuildIDEv", "unwindstack::MapInfo::GetBuildID()"},
        {0x02A904U,  312U, "_ZN11unwindstack7MapInfo19GetPrintableBuildIDEv", "unwindstack::MapInfo::GetPrintableBuildID()"},
        {0x02F8F8U,    8U, "_ZN11unwindstack9RegistersC1EPNS_4RegsE", "unwindstack::Registers::Registers(Regs*) [C1]"},
        {0x02F8F8U,    8U, "_ZN11unwindstack9RegistersC2EPNS_4RegsE", "unwindstack::Registers::Registers(Regs*) [C2]"},
        {0x02F900U,   32U, "_ZN11unwindstack9RegistersD1Ev", "unwindstack::Registers::~Registers() [D1]"},
        {0x02F900U,   32U, "_ZN11unwindstack9RegistersD2Ev", "unwindstack::Registers::~Registers() [D2]"},
        {0x02F920U,   24U, "_ZN11unwindstack9RegistersC1EOS0_", "unwindstack::Registers::Registers(Registers&&) [C1]"},
        {0x02F920U,   24U, "_ZN11unwindstack9RegistersC2EOS0_", "unwindstack::Registers::Registers(Registers&&) [C2]"},
        {0x02F938U,   60U, "_ZN11unwindstack9RegistersaSEOS0_", "unwindstack::Registers::operator=(Registers&&)"},
        {0x02F974U,   28U, "_ZNK11unwindstack9Registers2pcEv", "unwindstack::Registers::pc() const"},
        {0x02F990U,   28U, "_ZNK11unwindstack9Registers2spEv", "unwindstack::Registers::sp() const"},
        {0x02F9ACU,   24U, "_ZNK11unwindstack9Registers6dex_pcEv", "unwindstack::Registers::dex_pc() const"},
        {0x02F9C4U,   24U, "_ZN11unwindstack9Registers7RawDataEv", "unwindstack::Registers::RawData()"},
        {0x02F9C4U,   24U, "_ZNK11unwindstack9Registers7RawDataEv", "unwindstack::Registers::RawData() const"},
        {0x02F9DCU, 2060U, "_ZNK11unwindstack9Registers16IterateRegistersENSt6__ndk18functionIFvPKcmEEE", "unwindstack::Registers::IterateRegisters(std::function<void(const char*, uint64_t)>) const"},
        {0x0301E8U,   48U, "_ZN11unwindstack9Registers6createEPNS_4RegsE", "unwindstack::Registers::create(Regs*)"},
        {0x030218U,   60U, "_ZN11unwindstack9Registers18CreateFromUcontextEPv", "unwindstack::Registers::CreateFromUcontext(void*)"},
        {0x030254U,   56U, "_ZN11unwindstack9Registers15CreateFromLocalEv", "unwindstack::Registers::CreateFromLocal()"},
        {0x03028CU,   72U, "_ZN11unwindstack9Registers9RemoteGetEi", "unwindstack::Registers::RemoteGet(int)"},
        {0x0302D4U,   24U, "_ZNK11unwindstack9Registers10total_regsEv", "unwindstack::Registers::total_regs() const"},
        {0x0302ECU,   32U, "_ZNK11unwindstack9Registers5CloneEv", "unwindstack::Registers::Clone() const"},
        {0x03030CU,   32U, "_ZNK11unwindstack9Registers13vregs_enabledEv", "unwindstack::Registers::vregs_enabled() const"},
        {0x03032CU,   16U, "_ZN11unwindstack9Registers12enable_vregsEv", "unwindstack::Registers::enable_vregs()"},
        {0x03033CU,   24U, "_ZN11unwindstack9Registers10vregs_dataEv", "unwindstack::Registers::vregs_data()"},
        {0x03033CU,   24U, "_ZNK11unwindstack9Registers10vregs_dataEv", "unwindstack::Registers::vregs_data() const"},
        {0x030354U,   32U, "_ZNK11unwindstack9Registers11total_vregsEv", "unwindstack::Registers::total_vregs() const"}
    }};
    return kSymbols;
}

// ============================================================================
// 2. Closed-Loop Parity Self-Tests
// Kiểm thử đối soát khép kín toàn diện cho libnpth_unwind.so.
// ============================================================================
bool VerifyNpthUnwindErrorCodeTableParity() noexcept {
    const auto& tbl = GetNpthUnwindErrorCodeTable15();
    if (tbl.size() != 15) {
        return false;
    }
    if (tbl[0].data_rel_ro_vaddr != 0x038420U || tbl[0].rodata_str_vaddr != 0x00738BU) {
        return false;
    }
    if (tbl[14].data_rel_ro_vaddr != 0x038490U || tbl[14].rodata_str_vaddr != 0x0076B1U) {
        return false;
    }
    AndroidUnwinderData data;
    data.error.code = ERROR_PTRACE_CALL;
    data.error.address = 0x7FF0001234ULL;
    return data.GetErrorString() == "Ptrace Call Failed at address 0x7ff0001234";
}

bool VerifyNpthUnwindElfRelPcAndTbiMask() noexcept {
    auto mem = CreateOfflineContainerMemory(0x1000, 0x5000);
    Elf elf(mem, 0x2000ULL, true);
    elf.RegisterSymbol("g_tagged_var", 0xB400007123456780ULL, 8, true);

    MapInfo map(0x7000000000ULL, 0x7000040000ULL, 0x4000ULL, 0x5U, "/data/app/libnpth_unwind.so");
    map.GetElfFields().elf_offset = 0x4000ULL;

    // ElfGetRelPc (0x0272e0): (pc - start) + load_bias + elf_offset
    const uint64_t rel_pc = ElfGetRelPc(&elf, 0x7000015708ULL, &map);
    if (rel_pc != (0x7000015708ULL - 0x7000000000ULL) + 0x2000ULL + 0x4000ULL) {
        return false;
    }

    // ElfGetVariableOffset (0x027314): masks top byte via & 0x00FFFFFFFFFFFFFFULL at 0x027364
    uint64_t var_off = 0;
    if (!ElfGetVariableOffset(&elf, "g_tagged_var", &var_off)) {
        return false;
    }
    return var_off == 0x0000007123456780ULL;
}

bool VerifyNpthUnwindRegsArm64AndUcontextParity() noexcept {
    uint8_t fake_ucontext[0xB8 + kArm64RegsByteSize] = {0};
    auto* raw_regs = reinterpret_cast<uint64_t*>(fake_ucontext + kArm64UcontextRegsOffset);
    raw_regs[REG_ARM64_SP] = 0x0000007FF0008000ULL;
    raw_regs[REG_ARM64_PC] = 0x000000700002F974ULL;
    raw_regs[REG_ARM64_LR] = 0x0000007000015AB0ULL;

    Registers regs;
    regs.CreateFromUcontext(fake_ucontext);
    if (regs.total_regs() != 0x22U || regs.sp() != 0x0000007FF0008000ULL || regs.pc() != 0x000000700002F974ULL) {
        return false;
    }
    if (regs.vregs_enabled() || regs.total_vregs() != 0) {
        return false;
    }
    regs.enable_vregs();
    return regs.vregs_enabled() && regs.total_vregs() == kArm64CalleeSavedVRegsCount;
}

bool VerifyNpthUnwindSha256AndXzHeaderParity() noexcept {
    const uint8_t xz_hdr[6] = {0xFD, 0x37, 0x7A, 0x58, 0x5A, 0x00};
    if (!VerifyXzStreamHeaderMagic(xz_hdr, sizeof(xz_hdr))) {
        return false;
    }
    const char* msg = "abc";
    const auto digest = ComputeUnwindSha256(reinterpret_cast<const uint8_t*>(msg), 3);
    // SHA-256("abc") starts with ba 78 16 bf
    return digest[0] == 0xBA && digest[1] == 0x78 && digest[2] == 0x16 && digest[3] == 0xBF;
}

bool VerifyNpthUnwindFormatFrameAndBuildIdParity() {
    auto map = std::make_shared<MapInfo>(0x7000000000ULL, 0x7000038000ULL, 0ULL, 0x5U, "/system/lib64/libnpth_unwind.so");
    map->SetRawBuildId(std::string("\xc8\x3b\xb9\x4d", 4));
    if (map->GetPrintableBuildID() != "c83bb94d") {
        return false;
    }

    FrameData frame{};
    frame.num = 2;
    frame.rel_pc = 0x0000000000015708ULL;
    frame.pc = 0x0000007000015708ULL;
    frame.function_name = SharedString("unwindstack::AndroidUnwinder::Unwind");
    frame.function_offset = 64;
    frame.map_info = map;

    AndroidUnwinder unwinder(-1, nullptr, nullptr);
    const std::string formatted = unwinder.FormatFrame(frame, true, "  ");
    return formatted == "  #02 pc 0000000000015708  /system/lib64/libnpth_unwind.so (unwindstack::AndroidUnwinder::Unwind+64) (BuildId: c83bb94d)";
}

bool RunAllNpthUnwindSelfTests() {
    return VerifyNpthUnwindErrorCodeTableParity() &&
           VerifyNpthUnwindElfRelPcAndTbiMask() &&
           VerifyNpthUnwindRegsArm64AndUcontextParity() &&
           VerifyNpthUnwindSha256AndXzHeaderParity() &&
           VerifyNpthUnwindFormatFrameAndBuildIdParity() &&
           !CheckExynos9810Arm64Bug(0x100ULL, "exynos9810") &&
           CheckExynos9810Arm64Bug(0x100ULL, "qcom");
}

} // namespace unwindstack
