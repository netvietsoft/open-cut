// ============================================================================
// File: npth_xasan_core.cpp
// Target: libnpth_xasan.so (40,480 bytes, SHA-256: 98ea19aaef712fed55b86c103322cb2b3a25c1b763bb99b152c73bf9086afd5a)
// Purpose: Clean-Room C++17 Implementation of ByteDance NPTH XASan / GWP-ASan
//          Guarded Pool Allocator, Bionic MallocDispatch Hook Engine, and
//          Complete 84-FDE AArch64 Disassembly Ledger (0x3c48..0x8bd8).
// Mục đích: Tái tạo sạch C++17 cho bộ phát hiện lỗi bộ nhớ NPTH XASan / GWP-ASan
//           kèm sổ cái giải mã đầy đủ 84 FDE (5,092 lệnh AArch64).
// ============================================================================

#include "npth_xasan.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace gwp_asan {

namespace {
volatile std::uintptr_t g_trapped_address_11760 = 0U;
volatile int g_trapped_error_11768 = 0;
} // namespace

// Export [84] 0x8730..0x8744 (20 bytes) — FDE[80]
// _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error
void GuardedPoolAllocator::trapOnAddress(std::uintptr_t addr, Error err) noexcept {
    // Observed at 0x8730..0x8740:
    //   stores crashing address and error enum into state, then triggers crash/dump
    g_trapped_address_11760 = addr;
    g_trapped_error_11768 = static_cast<int>(err);
}

} // namespace gwp_asan

namespace nextai::opencut::npth_xasan {

// ============================================================================
// 1. Complete 84-Entry .eh_frame_hdr FDE Descriptor Table (@ 0x2BC8)
//    Bảng 84 FDE trong phân đoạn .eh_frame_hdr tại địa chỉ 0x2BC8
// ============================================================================
const std::array<FdeDescriptor, kEhFrameFdeCount> kFdeTable = {{
    {  0U, 0x00003C48ULL, 0x00003C58ULL,   16U, 0x00002E8CULL, "__on_dlclose_3c48", "Bionic __cxa_finalize at-unload thunk (@ 0x3c48..0x3c58)" },
    {  1U, 0x00003C58ULL, 0x00003C60ULL,    8U, 0x00002EA0ULL, "XasanNoopRet_3c58", "BTI + ret no-op callback (@ 0x3c58..0x3c60)" },
    {  2U, 0x00003C60ULL, 0x00003C68ULL,    8U, 0x00002EB4ULL, "XasanNoopTail_3c60", "BTI + tail branch to 0x3c58 (@ 0x3c60..0x3c68)" },
    {  3U, 0x00003C68ULL, 0x00003C7CULL,   20U, 0x00002EC8ULL, "XasanIndirectCallIfNonNull_3c68", "Indirect callback dispatcher if x0 != nullptr (@ 0x3c68..0x3c7c)" },
    {  4U, 0x00003C7CULL, 0x00003C98ULL,   28U, 0x00002EDCULL, "__register_atfork_or_atexit_3c7c", "__cxa_atexit destructor registration (@ 0x3c7c..0x3c98)" },
    {  5U, 0x00003C98ULL, 0x00003D1CULL,  132U, 0x00002EF0ULL, "XasanCheckApiLevel_3c98", "Checks Android API level (cmp w0, #0x13 = API 19) (@ 0x3c98..0x3d1c)" },
    {  6U, 0x00003D1CULL, 0x000042DCULL, 1472U, 0x00002F24ULL, "XasanInitialize_3d1c", "Primary XASan initializer: parses config, maps GuardedPoolAllocator, installs SIGSEGV (@ 0x3d1c..0x42dc)" },
    {  7U, 0x000042DCULL, 0x000045BCULL,  736U, 0x00002F68ULL, "XasanInstallMallocDispatch_42dc", "Installs XASan allocator hooks into Bionic MallocDispatch (@ 0x42dc..0x45bc)" },
    {  8U, 0x000045BCULL, 0x000045DCULL,   32U, 0x00002F90ULL, "XasanRestoreReallocSlot_45bc", "Restores MallocDispatch->realloc (+0x18) from default dispatch (@ 0x45bc..0x45dc)" },
    {  9U, 0x000045DCULL, 0x000045F8ULL,   28U, 0x00002FA4ULL, "XasanRestoreFreeSlot_45dc", "Restores MallocDispatch->free (+0x08) from default dispatch (@ 0x45dc..0x45f8)" },
    { 10U, 0x000045F8ULL, 0x00004618ULL,   32U, 0x00002FB8ULL, "XasanRestoreMallocSlot_45f8", "Restores MallocDispatch->malloc (+0x00) from default dispatch (@ 0x45f8..0x4618)" },
    { 11U, 0x00004618ULL, 0x00004638ULL,   32U, 0x00002FCCULL, "XasanRestoreUsableSizeSlot_4618", "Restores MallocDispatch->malloc_usable_size (+0x38) from default dispatch (@ 0x4618..0x4638)" },
    { 12U, 0x00004638ULL, 0x00004658ULL,   32U, 0x00002FE0ULL, "XasanRestoreMemalignSlot_4638", "Restores MallocDispatch->memalign (+0x28) from default dispatch (@ 0x4638..0x4658)" },
    { 13U, 0x00004658ULL, 0x00004678ULL,   32U, 0x00002FF4ULL, "XasanRestoreCallocSlot_4658", "Restores MallocDispatch->calloc (+0x20) from default dispatch (@ 0x4658..0x4678)" },
    { 14U, 0x00004678ULL, 0x00004700ULL,  136U, 0x00003008ULL, "XasanResolveDefaultDispatch_4678", "Resolves __libc_globals and _ZL30__libc_malloc_default_dispatch (@ 0x4678..0x4700)" },
    { 15U, 0x00004700ULL, 0x0000480CULL,  268U, 0x00003020ULL, "XasanParseConfigFile_4700", "Parses xasan.config key=value parameters (@ 0x4700..0x480c)" },
    { 16U, 0x0000480CULL, 0x00004B88ULL,  892U, 0x00003058ULL, "XasanFde_480c", "XASan / GWP-ASan subroutine @ 0x480c..0x4b88" },
    { 17U, 0x00004B88ULL, 0x00004BFCULL,  116U, 0x000030A0ULL, "XasanFde_4b88", "XASan / GWP-ASan subroutine @ 0x4b88..0x4bfc" },
    { 18U, 0x00004BFCULL, 0x00004DBCULL,  448U, 0x000030CCULL, "XasanFde_4bfc", "XASan / GWP-ASan subroutine @ 0x4bfc..0x4dbc" },
    { 19U, 0x00004DBCULL, 0x00005014ULL,  600U, 0x0000310CULL, "XasanFde_4dbc", "XASan / GWP-ASan subroutine @ 0x4dbc..0x5014" },
    { 20U, 0x00005014ULL, 0x00005148ULL,  308U, 0x00003158ULL, "XasanInitTlsKey_5014", "Creates pthread TLS key (0x116e0) for allocator recursion protection (@ 0x5014..0x5148)" },
    { 21U, 0x00005148ULL, 0x00005240ULL,  248U, 0x00003188ULL, "XasanHookCalloc_5148", "Bionic calloc interceptor with GuardedPoolAllocator sampling (@ 0x5148..0x5240)" },
    { 22U, 0x00005240ULL, 0x00005318ULL,  216U, 0x000031D0ULL, "XasanHookMalloc_5240", "Bionic malloc interceptor with GuardedPoolAllocator sampling (@ 0x5240..0x5318)" },
    { 23U, 0x00005318ULL, 0x00005408ULL,  240U, 0x00003214ULL, "XasanHookRealloc_5318", "Bionic realloc interceptor with GuardedPoolAllocator check (@ 0x5318..0x5408)" },
    { 24U, 0x00005408ULL, 0x000054ACULL,  164U, 0x00003258ULL, "XasanHookFree_5408", "Bionic free interceptor with GuardedPoolAllocator deallocate (@ 0x5408..0x54ac)" },
    { 25U, 0x000054ACULL, 0x00005568ULL,  188U, 0x00003298ULL, "XasanHookUsableSize_54ac", "Bionic malloc_usable_size interceptor (@ 0x54ac..0x5568)" },
    { 26U, 0x00005568ULL, 0x00005600ULL,  152U, 0x000032E4ULL, "XasanFde_5568", "XASan / GWP-ASan subroutine @ 0x5568..0x5600" },
    { 27U, 0x00005600ULL, 0x000057E0ULL,  480U, 0x00003318ULL, "XasanFde_5600", "XASan / GWP-ASan subroutine @ 0x5600..0x57e0" },
    { 28U, 0x000057E0ULL, 0x00005904ULL,  292U, 0x00003364ULL, "XasanSetupSignalAltStack_57e0", "Maps 128 KB (0x20000) alternate signal stack ('XASan signal stack') (@ 0x57e0..0x5904)" },
    { 29U, 0x00005904ULL, 0x00005E90ULL, 1420U, 0x00003394ULL, "XasanSigsegvHandler_5904", "SIGSEGV fault handler inspecting faulting address against GuardedPagePool (@ 0x5904..0x5e90)" },
    { 30U, 0x00005E90ULL, 0x00005F08ULL,  120U, 0x000033E0ULL, "XasanFde_5e90", "XASan / GWP-ASan subroutine @ 0x5e90..0x5f08" },
    { 31U, 0x00005F08ULL, 0x00005FACULL,  164U, 0x00003408ULL, "XasanFde_5f08", "XASan / GWP-ASan subroutine @ 0x5f08..0x5fac" },
    { 32U, 0x00005FACULL, 0x000061B0ULL,  516U, 0x00003444ULL, "XasanFde_5fac", "XASan / GWP-ASan subroutine @ 0x5fac..0x61b0" },
    { 33U, 0x000061B0ULL, 0x00006228ULL,  120U, 0x0000348CULL, "XasanFde_61b0", "XASan / GWP-ASan subroutine @ 0x61b0..0x6228" },
    { 34U, 0x00006228ULL, 0x00006440ULL,  536U, 0x000034B4ULL, "XasanFde_6228", "XASan / GWP-ASan subroutine @ 0x6228..0x6440" },
    { 35U, 0x00006440ULL, 0x00006ABCULL, 1660U, 0x000034FCULL, "XasanDumpCrashReport_6440", "Forks child process & dumps GWP-ASan report to tombstone.txt / glog.txt (@ 0x6440..0x6abc)" },
    { 36U, 0x00006ABCULL, 0x00006BB8ULL,  252U, 0x00003588ULL, "XasanFde_6abc", "XASan / GWP-ASan subroutine @ 0x6abc..0x6bb8" },
    { 37U, 0x00006BB8ULL, 0x00006D00ULL,  328U, 0x000035C0ULL, "XasanFde_6bb8", "XASan / GWP-ASan subroutine @ 0x6bb8..0x6d00" },
    { 38U, 0x00006D00ULL, 0x00006D68ULL,  104U, 0x00003600ULL, "XasanFde_6d00", "XASan / GWP-ASan subroutine @ 0x6d00..0x6d68" },
    { 39U, 0x00006D68ULL, 0x000076E4ULL, 2428U, 0x00003628ULL, "XasanFormatCrashMetadata_6d68", "Formats allocation/deallocation backtraces & slot metadata (@ 0x6d68..0x76e4)" },
    { 40U, 0x000076E4ULL, 0x00007778ULL,  148U, 0x00003674ULL, "XasanFastItoa10_76e4", "Fast signed base-10 integer formatter using magic 0x66666667 (@ 0x76e4..0x7778)" },
    { 41U, 0x00007778ULL, 0x000078A4ULL,  300U, 0x00003688ULL, "XasanFde_7778", "XASan / GWP-ASan subroutine @ 0x7778..0x78a4" },
    { 42U, 0x000078A4ULL, 0x00007A94ULL,  496U, 0x000036C4ULL, "XasanFde_78a4", "XASan / GWP-ASan subroutine @ 0x78a4..0x7a94" },
    { 43U, 0x00007A94ULL, 0x00007B70ULL,  220U, 0x00003704ULL, "XasanFde_7a94", "XASan / GWP-ASan subroutine @ 0x7a94..0x7b70" },
    { 44U, 0x00007B70ULL, 0x00007BA4ULL,   52U, 0x00003734ULL, "XasanFde_7b70", "XASan / GWP-ASan subroutine @ 0x7b70..0x7ba4" },
    { 45U, 0x00007BA4ULL, 0x00007BE0ULL,   60U, 0x00003760ULL, "GwpAsanAddressIsMine_7ba4", "Checks if address lies within [GuardedPagePool, GuardedPagePoolEnd) (@ 0x7ba4..0x7be0)" },
    { 46U, 0x00007BE0ULL, 0x00007BE8ULL,    8U, 0x00003774ULL, "XasanFde_7be0", "XASan / GWP-ASan subroutine @ 0x7be0..0x7be8" },
    { 47U, 0x00007BE8ULL, 0x00007CD8ULL,  240U, 0x00003788ULL, "XasanFde_7be8", "XASan / GWP-ASan subroutine @ 0x7be8..0x7cd8" },
    { 48U, 0x00007CD8ULL, 0x00007D60ULL,  136U, 0x000037C0ULL, "XasanFde_7cd8", "XASan / GWP-ASan subroutine @ 0x7cd8..0x7d60" },
    { 49U, 0x00007D60ULL, 0x00007D68ULL,    8U, 0x000037ECULL, "XasanFde_7d60", "XASan / GWP-ASan subroutine @ 0x7d60..0x7d68" },
    { 50U, 0x00007D68ULL, 0x00007D70ULL,    8U, 0x00003800ULL, "XasanFde_7d68", "XASan / GWP-ASan subroutine @ 0x7d68..0x7d70" },
    { 51U, 0x00007D70ULL, 0x00007D78ULL,    8U, 0x00003814ULL, "XasanFde_7d70", "XASan / GWP-ASan subroutine @ 0x7d70..0x7d78" },
    { 52U, 0x00007D78ULL, 0x00007D94ULL,   28U, 0x00003828ULL, "XasanFde_7d78", "XASan / GWP-ASan subroutine @ 0x7d78..0x7d94" },
    { 53U, 0x00007D94ULL, 0x00007D9CULL,    8U, 0x0000383CULL, "XasanFde_7d94", "XASan / GWP-ASan subroutine @ 0x7d94..0x7d9c" },
    { 54U, 0x00007D9CULL, 0x00007DA4ULL,    8U, 0x00003850ULL, "XasanFde_7d9c", "XASan / GWP-ASan subroutine @ 0x7d9c..0x7da4" },
    { 55U, 0x00007DA4ULL, 0x00007DC0ULL,   28U, 0x00003864ULL, "XasanFde_7da4", "XASan / GWP-ASan subroutine @ 0x7da4..0x7dc0" },
    { 56U, 0x00007DC0ULL, 0x00007DE0ULL,   32U, 0x0000387CULL, "GwpAsanErrorToString_7dc0", "Maps Error enum (0..5) via offset table @ 0x2bb0 to string (@ 0x7dc0..0x7de0)" },
    { 57U, 0x00007DE0ULL, 0x00007E20ULL,   64U, 0x00003890ULL, "XasanFde_7de0", "XASan / GWP-ASan subroutine @ 0x7de0..0x7e20" },
    { 58U, 0x00007E20ULL, 0x00007E50ULL,   48U, 0x000038B8ULL, "XasanFde_7e20", "XASan / GWP-ASan subroutine @ 0x7e20..0x7e50" },
    { 59U, 0x00007E50ULL, 0x00007EA4ULL,   84U, 0x000038E0ULL, "XasanFde_7e50", "XASan / GWP-ASan subroutine @ 0x7e50..0x7ea4" },
    { 60U, 0x00007EA4ULL, 0x00007ECCULL,   40U, 0x00003910ULL, "XasanFde_7ea4", "XASan / GWP-ASan subroutine @ 0x7ea4..0x7ecc" },
    { 61U, 0x00007ECCULL, 0x00007ED4ULL,    8U, 0x00003924ULL, "XasanFde_7ecc", "XASan / GWP-ASan subroutine @ 0x7ecc..0x7ed4" },
    { 62U, 0x00007ED4ULL, 0x00007EECULL,   24U, 0x00003938ULL, "XasanFde_7ed4", "XASan / GWP-ASan subroutine @ 0x7ed4..0x7eec" },
    { 63U, 0x00007EECULL, 0x00007F08ULL,   28U, 0x0000394CULL, "XasanFde_7eec", "XASan / GWP-ASan subroutine @ 0x7eec..0x7f08" },
    { 64U, 0x00007F08ULL, 0x00007F84ULL,  124U, 0x00003960ULL, "XasanFde_7f08", "XASan / GWP-ASan subroutine @ 0x7f08..0x7f84" },
    { 65U, 0x00007F84ULL, 0x00007FB8ULL,   52U, 0x00003978ULL, "XasanFde_7f84", "XASan / GWP-ASan subroutine @ 0x7f84..0x7fb8" },
    { 66U, 0x00007FB8ULL, 0x00007FE4ULL,   44U, 0x000039A0ULL, "XasanFde_7fb8", "XASan / GWP-ASan subroutine @ 0x7fb8..0x7fe4" },
    { 67U, 0x00007FE4ULL, 0x00008068ULL,  132U, 0x000039CCULL, "XasanFde_7fe4", "XASan / GWP-ASan subroutine @ 0x7fe4..0x8068" },
    { 68U, 0x00008068ULL, 0x0000813CULL,  212U, 0x000039E0ULL, "XasanFde_8068", "XASan / GWP-ASan subroutine @ 0x8068..0x813c" },
    { 69U, 0x0000813CULL, 0x00008400ULL,  708U, 0x000039F8ULL, "XasanFde_813c", "XASan / GWP-ASan subroutine @ 0x813c..0x8400" },
    { 70U, 0x00008400ULL, 0x00008730ULL,  816U, 0x00003A34ULL, "XasanFde_8400", "XASan / GWP-ASan subroutine @ 0x8400..0x8730" },
    { 71U, 0x00008730ULL, 0x00008744ULL,   20U, 0x00003A78ULL, "XasanFde_8730", "XASan / GWP-ASan subroutine @ 0x8730..0x8744" },
    { 72U, 0x00008744ULL, 0x00008758ULL,   20U, 0x00003A8CULL, "XasanFde_8744", "XASan / GWP-ASan subroutine @ 0x8744..0x8758" },
    { 73U, 0x00008758ULL, 0x00008760ULL,    8U, 0x00003AA0ULL, "XasanFde_8758", "XASan / GWP-ASan subroutine @ 0x8758..0x8760" },
    { 74U, 0x00008760ULL, 0x00008954ULL,  500U, 0x00003AB4ULL, "XasanFde_8760", "XASan / GWP-ASan subroutine @ 0x8760..0x8954" },
    { 75U, 0x00008954ULL, 0x000089B4ULL,   96U, 0x00003AF4ULL, "XasanFde_8954", "XASan / GWP-ASan subroutine @ 0x8954..0x89b4" },
    { 76U, 0x000089B4ULL, 0x00008A2CULL,  120U, 0x00003B2CULL, "XasanFde_89b4", "XASan / GWP-ASan subroutine @ 0x89b4..0x8a2c" },
    { 77U, 0x00008A2CULL, 0x00008AACULL,  128U, 0x00003B5CULL, "XasanFde_8a2c", "XASan / GWP-ASan subroutine @ 0x8a2c..0x8aac" },
    { 78U, 0x00008AACULL, 0x00008B20ULL,  116U, 0x00003B8CULL, "XasanFde_8aac", "XASan / GWP-ASan subroutine @ 0x8aac..0x8b20" },
    { 79U, 0x00008B20ULL, 0x00008B24ULL,    4U, 0x00003BBCULL, "XasanFde_8b20", "XASan / GWP-ASan subroutine @ 0x8b20..0x8b24" },
    { 80U, 0x00008B24ULL, 0x00008B40ULL,   28U, 0x00003BD0ULL, "_ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error", "Exported: gwp_asan::GuardedPoolAllocator::trapOnAddress(unsigned long, Error) (@ 0x8730..0x8744)" },
    { 81U, 0x00008B40ULL, 0x00008B44ULL,    4U, 0x00003BF8ULL, "XasanFde_8b40", "XASan / GWP-ASan subroutine @ 0x8b40..0x8b44" },
    { 82U, 0x00008B44ULL, 0x00008B70ULL,   44U, 0x00003C10ULL, "XasanFde_8b44", "XASan / GWP-ASan subroutine @ 0x8b44..0x8b70" },
    { 83U, 0x00008B70ULL, 0x00008BD8ULL,  104U, 0x00003C2CULL, "XasanFde_8b70", "XASan / GWP-ASan subroutine @ 0x8b70..0x8bd8" },
}};

// ============================================================================
// 2. GWP-ASan Error String Mapper — FDE[56] (0x7dc0..0x7de0)
//    Ánh xạ mã lỗi GWP-ASan (0..5) sang chuỗi mô tả tại .rodata 0x2bb0
// ============================================================================
const char* GwpAsanErrorToString_7dc0(gwp_asan::Error err) noexcept {
    // Observed at 0x7dc0..0x7dd8:
    //   0x7dc0: cmp w0, #6
    //   0x7dc4: b.hs #0x7ddc (brk #1)
    //   0x7dcc: adr x8, #0x2bb0
    //   0x7dd0: ldrsw x9, [x8, w0, sxtw #2]
    //   0x7dd4: add x0, x8, x9
    switch (err) {
        case gwp_asan::Error::UNKNOWN:          return "Unknown";
        case gwp_asan::Error::USE_AFTER_FREE:   return "Use After Free";
        case gwp_asan::Error::DOUBLE_FREE:      return "Double Free";
        case gwp_asan::Error::INVALID_FREE:     return "Invalid Free";
        case gwp_asan::Error::BUFFER_OVERFLOW:  return "Buffer Overflow";
        case gwp_asan::Error::BUFFER_UNDERFLOW: return "Buffer Underflow";
        default:                                return "Unknown";
    }
}

// ============================================================================
// 3. Fast Signed Integer-to-Decimal — FDE[40] (0x76e4..0x7778)
//    Chuyển đổi số nguyên có dấu sang chuỗi thập phân dùng hằng số 0x66666667
// ============================================================================
char* XasanFastItoa10_76e4(std::int32_t value, char* out_buf) noexcept {
    // Observed at 0x76e4..0x7774:
    //   0x76ec: tbnz w8, #0x1f, #0x76f8 (if negative, emit '-' = 0x2d and negate)
    //   0x7708: mov w11, #0x6667; movk w11, #0x6666, lsl #16 (0x66666667)
    if (!out_buf) return nullptr;
    char* p = out_buf;
    std::uint32_t uval = 0U;
    if (value < 0) {
        *p++ = '-';
        uval = static_cast<std::uint32_t>(-static_cast<std::int64_t>(value));
    } else {
        uval = static_cast<std::uint32_t>(value);
    }
    char* digits_start = p;
    do {
        const std::uint64_t prod = static_cast<std::uint64_t>(uval) * kFastDiv10Magic;
        const std::uint32_t quot = static_cast<std::uint32_t>(prod >> 34U);
        const std::uint32_t rem  = uval - quot * 10U;
        *p++ = static_cast<char>('0' + rem);
        uval = quot;
    } while (uval != 0U);
    *p = '\0';
    std::reverse(digits_start, p);
    return out_buf;
}

// ============================================================================
// 4. GWP-ASan Pool Ownership Check — FDE[45] (0x7ba4..0x7be0)
//    Kiểm tra địa chỉ có thuộc phạm vi GuardedPagePool hay không
// ============================================================================
bool GwpAsanAddressIsMine_7ba4(const GwpAsanPoolState* state, std::uintptr_t addr) noexcept {
    // Observed at 0x7ba4..0x7bd4:
    //   if (state->has_crashed != 0 && state->crashing_address != 0) return true;
    //   return (addr < state->guarded_page_pool_end) && (addr >= state->guarded_page_pool);
    if (!state) return false;
    if (state->has_crashed != 0 && state->crashing_address != 0U) {
        return true;
    }
    return (addr < state->guarded_page_pool_end) && (addr >= state->guarded_page_pool);
}

extern "C" {

// Export [83] .data 0x11608 (8 bytes)
void* xasan_native_interface_func = nullptr;

} // extern "C"

// ============================================================================
// 5. Complete 84-FDE AArch64 Disassembly Reference (0x3c48..0x8bd8, 5,092 insns)
//    Sổ cái giải mã toàn bộ 5,092 lệnh AArch64 trên 84 FDE của libnpth_xasan.so
// ============================================================================
// ----------------------------------------------------------------------------
// FDE[00] __on_dlclose_3c48 (0x3c48..0x3c58, 16 bytes, 4 instructions)
// Summary / Tóm tắt: Bionic __cxa_finalize at-unload thunk (@ 0x3c48..0x3c58)
// ----------------------------------------------------------------------------
//   0x3c48: d503245f  bti        c
//   0x3c4c: d503201f  nop        
//   0x3c50: 1004a600  adr        x0, #0xd110
//   0x3c54: 140013eb  b          #0x8c00

// ----------------------------------------------------------------------------
// FDE[01] XasanNoopRet_3c58 (0x3c58..0x3c60, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + ret no-op callback (@ 0x3c58..0x3c60)
// ----------------------------------------------------------------------------
//   0x3c58: d503245f  bti        c
//   0x3c5c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[02] XasanNoopTail_3c60 (0x3c60..0x3c68, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + tail branch to 0x3c58 (@ 0x3c60..0x3c68)
// ----------------------------------------------------------------------------
//   0x3c60: d503245f  bti        c
//   0x3c64: 17fffffd  b          #0x3c58

// ----------------------------------------------------------------------------
// FDE[03] XasanIndirectCallIfNonNull_3c68 (0x3c68..0x3c7c, 20 bytes, 5 instructions)
// Summary / Tóm tắt: Indirect callback dispatcher if x0 != nullptr (@ 0x3c68..0x3c7c)
// ----------------------------------------------------------------------------
//   0x3c68: d503245f  bti        c
//   0x3c6c: b4000060  cbz        x0, #0x3c78
//   0x3c70: aa0003f0  mov        x16, x0
//   0x3c74: d61f0200  br         x16
//   0x3c78: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[04] __register_atfork_or_atexit_3c7c (0x3c7c..0x3c98, 28 bytes, 7 instructions)
// Summary / Tóm tắt: __cxa_atexit destructor registration (@ 0x3c7c..0x3c98)
// ----------------------------------------------------------------------------
//   0x3c7c: d503245f  bti        c
//   0x3c80: aa0003e1  mov        x1, x0
//   0x3c84: d503201f  nop        
//   0x3c88: 10ffff00  adr        x0, #0x3c68
//   0x3c8c: d503201f  nop        
//   0x3c90: 1004a402  adr        x2, #0xd110
//   0x3c94: 140013df  b          #0x8c10

// ----------------------------------------------------------------------------
// FDE[05] XasanCheckApiLevel_3c98 (0x3c98..0x3d1c, 132 bytes, 33 instructions)
// Summary / Tóm tắt: Checks Android API level (cmp w0, #0x13 = API 19) (@ 0x3c98..0x3d1c)
// ----------------------------------------------------------------------------
//   0x3c98: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x3c9c: 910003fd  mov        x29, sp
//   0x3ca0: 2a0003e8  mov        w8, w0
//   0x3ca4: 71004c1f  cmp        w0, #0x13
//   0x3ca8: 5400016c  b.gt       #0x3cd4
//   0x3cac: d503201f  nop        
//   0x3cb0: 50ff2361  adr        x1, #0x211e
//   0x3cb4: d0ffffe2  adrp       x2, #0x1000
//   0x3cb8: 913c2442  add        x2, x2, #0xf09
//   0x3cbc: 528000c0  mov        w0, #6
//   0x3cc0: 2a0803e3  mov        w3, w8
//   0x3cc4: 940013d7  bl         #0x8c20
//   0x3cc8: 12800000  mov        w0, #-1
//   0x3ccc: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x3cd0: d65f03c0  ret        
//   0x3cd4: d0000069  adrp       x9, #0x11000
//   0x3cd8: 3958a12a  ldrb       w10, [x9, #0x628]
//   0x3cdc: 7100055f  cmp        w10, #1
//   0x3ce0: 54000101  b.ne       #0x3d00
//   0x3ce4: d503201f  nop        
//   0x3ce8: 50ff21a1  adr        x1, #0x211e
//   0x3cec: d0ffffe2  adrp       x2, #0x1000
//   0x3cf0: 913c9c42  add        x2, x2, #0xf27
//   0x3cf4: 528000c0  mov        w0, #6
//   0x3cf8: 940013ca  bl         #0x8c20
//   0x3cfc: 14000005  b          #0x3d10
//   0x3d00: 5280002a  mov        w10, #1
//   0x3d04: 2a0803e0  mov        w0, w8
//   0x3d08: 3918a12a  strb       w10, [x9, #0x628]
//   0x3d0c: 9400027d  bl         #0x4700
//   0x3d10: 2a1f03e0  mov        w0, wzr
//   0x3d14: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x3d18: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[06] XasanInitialize_3d1c (0x3d1c..0x42dc, 1472 bytes, 368 instructions)
// Summary / Tóm tắt: Primary XASan initializer: parses config, maps GuardedPoolAllocator, installs SIGSEGV (@ 0x3d1c..0x42dc)
// ----------------------------------------------------------------------------
//   0x3d1c: d10183ff  sub        sp, sp, #0x60
//   0x3d20: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x3d24: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x3d28: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x3d2c: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x3d30: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x3d34: 910043fd  add        x29, sp, #0x10
//   0x3d38: d0000078  adrp       x24, #0x11000
//   0x3d3c: 39590309  ldrb       w9, [x24, #0x640]
//   0x3d40: 36000069  tbz        w9, #0, #0x3d4c
//   0x3d44: 128001b3  mov        w19, #-0xe
//   0x3d48: 140000bc  b          #0x4038
//   0x3d4c: 2a0003e8  mov        w8, w0
//   0x3d50: 51009009  sub        w9, w0, #0x24
//   0x3d54: 31003d3f  cmn        w9, #0xf
//   0x3d58: 54000062  b.hs       #0x3d64
//   0x3d5c: 12800013  mov        w19, #-1
//   0x3d60: 140000b6  b          #0x4038
//   0x3d64: d0000075  adrp       x21, #0x11000
//   0x3d68: d0000076  adrp       x22, #0x11000
//   0x3d6c: d0000077  adrp       x23, #0x11000
//   0x3d70: f9432ea0  ldr        x0, [x21, #0x658]
//   0x3d74: b9062ec8  str        w8, [x22, #0x62c]
//   0x3d78: b50000c0  cbnz       x0, #0x3d90
//   0x3d7c: f0ffffe0  adrp       x0, #0x2000
//   0x3d80: 91005c00  add        x0, x0, #0x17
//   0x3d84: 940013ab  bl         #0x8c30
//   0x3d88: f9032ea0  str        x0, [x21, #0x658]
//   0x3d8c: b4000740  cbz        x0, #0x3e74
//   0x3d90: f0ffffe1  adrp       x1, #0x2000
//   0x3d94: 91260421  add        x1, x1, #0x981
//   0x3d98: 910003e2  mov        x2, sp
//   0x3d9c: 940013a9  bl         #0x8c40
//   0x3da0: b4000760  cbz        x0, #0x3e8c
//   0x3da4: f94003e8  ldr        x8, [sp]
//   0x3da8: d0000079  adrp       x25, #0x11000
//   0x3dac: f9031ee0  str        x0, [x23, #0x638]
//   0x3db0: f9032b28  str        x8, [x25, #0x650]
//   0x3db4: 940013a7  bl         #0x8c50
//   0x3db8: b9462ec8  ldr        w8, [x22, #0x62c]
//   0x3dbc: 51005508  sub        w8, w8, #0x15
//   0x3dc0: 7100391f  cmp        w8, #0xe
//   0x3dc4: 54000768  b.hi       #0x3eb0
//   0x3dc8: d503201f  nop        
//   0x3dcc: 50ff642d  adr        x13, #0x2a52
//   0x3dd0: aa1f03fa  mov        x26, xzr
//   0x3dd4: 93407c13  sxtw       x19, w0
//   0x3dd8: 52800409  mov        w9, #0x20
//   0x3ddc: 5280060a  mov        w10, #0x30
//   0x3de0: 100000ce  adr        x14, #0x3df8
//   0x3de4: 386869af  ldrb       w15, [x13, x8]
//   0x3de8: 8b0f09ce  add        x14, x14, x15, lsl #2
//   0x3dec: 5280070c  mov        w12, #0x38
//   0x3df0: 5280072b  mov        w11, #0x39
//   0x3df4: d61f01c0  br         x14
//   0x3df8: f9432ea0  ldr        x0, [x21, #0x658]
//   0x3dfc: b50000c0  cbnz       x0, #0x3e14
//   0x3e00: f0ffffe0  adrp       x0, #0x2000
//   0x3e04: 91005c00  add        x0, x0, #0x17
//   0x3e08: 9400138a  bl         #0x8c30
//   0x3e0c: f9032ea0  str        x0, [x21, #0x658]
//   0x3e10: b4001bc0  cbz        x0, #0x4188
//   0x3e14: f0ffffe1  adrp       x1, #0x2000
//   0x3e18: 911d2421  add        x1, x1, #0x749
//   0x3e1c: aa1f03e2  mov        x2, xzr
//   0x3e20: 94001388  bl         #0x8c40
//   0x3e24: d0000068  adrp       x8, #0x11000
//   0x3e28: f9032500  str        x0, [x8, #0x648]
//   0x3e2c: b4001be0  cbz        x0, #0x41a8
//   0x3e30: aa1f03e0  mov        x0, xzr
//   0x3e34: aa1303e1  mov        x1, x19
//   0x3e38: 52800062  mov        w2, #3
//   0x3e3c: 52800443  mov        w3, #0x22
//   0x3e40: 12800004  mov        w4, #-1
//   0x3e44: aa1f03e5  mov        x5, xzr
//   0x3e48: 94001386  bl         #0x8c60
//   0x3e4c: b100041f  cmn        x0, #1
//   0x3e50: 54001441  b.ne       #0x40d8
//   0x3e54: d503201f  nop        
//   0x3e58: 50ff1621  adr        x1, #0x211e
//   0x3e5c: d0ffffe2  adrp       x2, #0x1000
//   0x3e60: 91318042  add        x2, x2, #0xc60
//   0x3e64: 528000c0  mov        w0, #6
//   0x3e68: 9400136e  bl         #0x8c20
//   0x3e6c: 128000b3  mov        w19, #-6
//   0x3e70: 1400003a  b          #0x3f58
//   0x3e74: d503201f  nop        
//   0x3e78: 50ff1521  adr        x1, #0x211e
//   0x3e7c: d0ffffe2  adrp       x2, #0x1000
//   0x3e80: 9134d842  add        x2, x2, #0xd36
//   0x3e84: 52800080  mov        w0, #4
//   0x3e88: 94001366  bl         #0x8c20
//   0x3e8c: d503201f  nop        
//   0x3e90: 50ff1461  adr        x1, #0x211e
//   0x3e94: f0ffffe2  adrp       x2, #0x2000
//   0x3e98: 91049042  add        x2, x2, #0x124
//   0x3e9c: 528000c0  mov        w0, #6
//   0x3ea0: 12800043  mov        w3, #-3
//   0x3ea4: 12800053  mov        w19, #-3
//   0x3ea8: 9400135e  bl         #0x8c20
//   0x3eac: 1400002b  b          #0x3f58
//   0x3eb0: 12800013  mov        w19, #-1
//   0x3eb4: 14000029  b          #0x3f58
//   0x3eb8: 5280076b  mov        w11, #0x3b
//   0x3ebc: aa0b03ec  mov        x12, x11
//   0x3ec0: aa0c03ea  mov        x10, x12
//   0x3ec4: aa0a03e9  mov        x9, x10
//   0x3ec8: aa0903fa  mov        x26, x9
//   0x3ecc: f9432ea0  ldr        x0, [x21, #0x658]
//   0x3ed0: b50000c0  cbnz       x0, #0x3ee8
//   0x3ed4: f0ffffe0  adrp       x0, #0x2000
//   0x3ed8: 91005c00  add        x0, x0, #0x17
//   0x3edc: 94001355  bl         #0x8c30
//   0x3ee0: f9032ea0  str        x0, [x21, #0x658]
//   0x3ee4: b40001c0  cbz        x0, #0x3f1c
//   0x3ee8: f0ffffe1  adrp       x1, #0x2000
//   0x3eec: 911b6021  add        x1, x1, #0x6d8
//   0x3ef0: aa1f03e2  mov        x2, xzr
//   0x3ef4: 94001353  bl         #0x8c40
//   0x3ef8: aa0003f4  mov        x20, x0
//   0x3efc: b40001e0  cbz        x0, #0x3f38
//   0x3f00: f2402e9f  tst        x20, #0xfff
//   0x3f04: 540001a1  b.ne       #0x3f38
//   0x3f08: b9462ec8  ldr        w8, [x22, #0x62c]
//   0x3f0c: 7100751f  cmp        w8, #0x1d
//   0x3f10: 54000a41  b.ne       #0x4058
//   0x3f14: 91012288  add        x8, x20, #0x48
//   0x3f18: 1400005a  b          #0x4080
//   0x3f1c: d503201f  nop        
//   0x3f20: 50ff0fe1  adr        x1, #0x211e
//   0x3f24: d0ffffe2  adrp       x2, #0x1000
//   0x3f28: 9134d842  add        x2, x2, #0xd36
//   0x3f2c: 52800080  mov        w0, #4
//   0x3f30: 9400133c  bl         #0x8c20
//   0x3f34: aa1f03f4  mov        x20, xzr
//   0x3f38: 92402e83  and        x3, x20, #0xfff
//   0x3f3c: d503201f  nop        
//   0x3f40: 50ff0ee1  adr        x1, #0x211e
//   0x3f44: f0ffffe2  adrp       x2, #0x2000
//   0x3f48: 91135042  add        x2, x2, #0x4d4
//   0x3f4c: 528000c0  mov        w0, #6
//   0x3f50: 94001334  bl         #0x8c20
//   0x3f54: 12800093  mov        w19, #-5
//   0x3f58: d503201f  nop        
//   0x3f5c: 50ff0e01  adr        x1, #0x211e
//   0x3f60: f0ffffe2  adrp       x2, #0x2000
//   0x3f64: 911afc42  add        x2, x2, #0x6bf
//   0x3f68: 528000c0  mov        w0, #6
//   0x3f6c: 2a1303e3  mov        w3, w19
//   0x3f70: 9400132c  bl         #0x8c20
//   0x3f74: f9431ee9  ldr        x9, [x23, #0x638]
//   0x3f78: b4000589  cbz        x9, #0x4028
//   0x3f7c: d0000068  adrp       x8, #0x11000
//   0x3f80: b9462eca  ldr        w10, [x22, #0x62c]
//   0x3f84: f9432508  ldr        x8, [x8, #0x648]
//   0x3f88: b40001e8  cbz        x8, #0x3fc4
//   0x3f8c: 5100554b  sub        w11, w10, #0x15
//   0x3f90: 7100097f  cmp        w11, #2
//   0x3f94: 54000208  b.hi       #0x3fd4
//   0x3f98: d0000074  adrp       x20, #0x11000
//   0x3f9c: f9000109  str        x9, [x8]
//   0x3fa0: f9431a80  ldr        x0, [x20, #0x630]
//   0x3fa4: b4000420  cbz        x0, #0x4028
//   0x3fa8: d0000068  adrp       x8, #0x11000
//   0x3fac: f9432901  ldr        x1, [x8, #0x650]
//   0x3fb0: 94001330  bl         #0x8c70
//   0x3fb4: f9031a9f  str        xzr, [x20, #0x630]
//   0x3fb8: f9432ea0  ldr        x0, [x21, #0x658]
//   0x3fbc: b50003a0  cbnz       x0, #0x4030
//   0x3fc0: 1400001e  b          #0x4038
//   0x3fc4: 51006148  sub        w8, w10, #0x18
//   0x3fc8: 71002d1f  cmp        w8, #0xb
//   0x3fcc: 540000c9  b.ls       #0x3fe4
//   0x3fd0: 14000016  b          #0x4028
//   0x3fd4: 51006149  sub        w9, w10, #0x18
//   0x3fd8: 71002d3f  cmp        w9, #0xb
//   0x3fdc: 54000268  b.hi       #0x4028
//   0x3fe0: f900011f  str        xzr, [x8]
//   0x3fe4: d0000068  adrp       x8, #0x11000
//   0x3fe8: f9432908  ldr        x8, [x8, #0x650]
//   0x3fec: 927df108  and        x8, x8, #0xfffffffffffffff8
//   0x3ff0: f100051f  cmp        x8, #1
//   0x3ff4: 540001ab  b.lt       #0x4028
//   0x3ff8: d0000069  adrp       x9, #0x11000
//   0x3ffc: 2a1f03e1  mov        w1, wzr
//   0x4000: f9431920  ldr        x0, [x9, #0x630]
//   0x4004: 8b000108  add        x8, x8, x0
//   0x4008: 91002009  add        x9, x0, #8
//   0x400c: eb09011f  cmp        x8, x9
//   0x4010: 9a898108  csel       x8, x8, x9, hi
//   0x4014: aa2003e9  mvn        x9, x0
//   0x4018: 8b090108  add        x8, x8, x9
//   0x401c: 927df108  and        x8, x8, #0xfffffffffffffff8
//   0x4020: 91002102  add        x2, x8, #8
//   0x4024: 94001317  bl         #0x8c80
//   0x4028: f9432ea0  ldr        x0, [x21, #0x658]
//   0x402c: b4000060  cbz        x0, #0x4038
//   0x4030: 94001318  bl         #0x8c90
//   0x4034: f9032ebf  str        xzr, [x21, #0x658]
//   0x4038: 2a1303e0  mov        w0, w19
//   0x403c: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x4040: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x4044: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x4048: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x404c: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x4050: 910183ff  add        sp, sp, #0x60
//   0x4054: d65f03c0  ret        
//   0x4058: 51007909  sub        w9, w8, #0x1e
//   0x405c: 71000d3f  cmp        w9, #3
//   0x4060: 54000068  b.hi       #0x406c
//   0x4064: 91014288  add        x8, x20, #0x50
//   0x4068: 14000006  b          #0x4080
//   0x406c: 71008d1f  cmp        w8, #0x23
//   0x4070: 54fff520  b.eq       #0x3f14
//   0x4074: 7100891f  cmp        w8, #0x22
//   0x4078: 54000081  b.ne       #0x4088
//   0x407c: 91016288  add        x8, x20, #0x58
//   0x4080: b0000069  adrp       x9, #0x11000
//   0x4084: f9032528  str        x8, [x9, #0x648]
//   0x4088: aa1403e0  mov        x0, x20
//   0x408c: aa1303e1  mov        x1, x19
//   0x4090: 52800062  mov        w2, #3
//   0x4094: 94001303  bl         #0x8ca0
//   0x4098: 34000120  cbz        w0, #0x40bc
//   0x409c: d503201f  nop        
//   0x40a0: 50ff03e1  adr        x1, #0x211e
//   0x40a4: d0ffffe2  adrp       x2, #0x2000
//   0x40a8: 910f9c42  add        x2, x2, #0x3e7
//   0x40ac: 528000c0  mov        w0, #6
//   0x40b0: 2a1f03e3  mov        w3, wzr
//   0x40b4: 940012db  bl         #0x8c20
//   0x40b8: 17ffffa7  b          #0x3f54
//   0x40bc: b9462ec8  ldr        w8, [x22, #0x62c]
//   0x40c0: d1004349  sub        x9, x26, #0x10
//   0x40c4: 71008d1f  cmp        w8, #0x23
//   0x40c8: 9a9a0128  csel       x8, x9, x26, eq
//   0x40cc: 91011d08  add        x8, x8, #0x47
//   0x40d0: 927be908  and        x8, x8, #0xffffffffffffffe0
//   0x40d4: 8b140100  add        x0, x8, x20
//   0x40d8: b0000074  adrp       x20, #0x11000
//   0x40dc: f9031a80  str        x0, [x20, #0x630]
//   0x40e0: 940012f4  bl         #0x8cb0
//   0x40e4: 37f802e0  tbnz       w0, #0x1f, #0x4140
//   0x40e8: 2a0003f3  mov        w19, w0
//   0x40ec: 34000f40  cbz        w0, #0x42d4
//   0x40f0: b81fc3bf  stur       wzr, [x29, #-4]
//   0x40f4: 52800022  mov        w2, #1
//   0x40f8: d10013a1  sub        x1, x29, #4
//   0x40fc: 2a1303e0  mov        w0, w19
//   0x4100: 72a80002  movk       w2, #0x4000, lsl #16
//   0x4104: 940012ef  bl         #0x8cc0
//   0x4108: 3100041f  cmn        w0, #1
//   0x410c: 540001e1  b.ne       #0x4148
//   0x4110: 940012f0  bl         #0x8cd0
//   0x4114: b9400003  ldr        w3, [x0]
//   0x4118: 7100107f  cmp        w3, #4
//   0x411c: 54fffec0  b.eq       #0x40f4
//   0x4120: d503201f  nop        
//   0x4124: 50feffc1  adr        x1, #0x211e
//   0x4128: b0ffffe2  adrp       x2, #0x1000
//   0x412c: 91369842  add        x2, x2, #0xda6
//   0x4130: 528000c0  mov        w0, #6
//   0x4134: 940012bb  bl         #0x8c20
//   0x4138: 12800113  mov        w19, #-9
//   0x413c: 1400005c  b          #0x42ac
//   0x4140: 128000d3  mov        w19, #-7
//   0x4144: 1400005a  b          #0x42ac
//   0x4148: b85fc3a3  ldur       w3, [x29, #-4]
//   0x414c: 529fefe8  mov        w8, #0xff7f
//   0x4150: 6a08007f  tst        w3, w8
//   0x4154: 540003a0  b.eq       #0x41c8
//   0x4158: 12001868  and        w8, w3, #0x7f
//   0x415c: 34000808  cbz        w8, #0x425c
//   0x4160: d503201f  nop        
//   0x4164: 50fefdc1  adr        x1, #0x211e
//   0x4168: 11000469  add        w9, w3, #1
//   0x416c: 721f153f  tst        w9, #0x7e
//   0x4170: 54000940  b.eq       #0x4298
//   0x4174: b0ffffe2  adrp       x2, #0x1000
//   0x4178: 9136f842  add        x2, x2, #0xdbe
//   0x417c: 528000c0  mov        w0, #6
//   0x4180: 2a0803e3  mov        w3, w8
//   0x4184: 14000048  b          #0x42a4
//   0x4188: d503201f  nop        
//   0x418c: 50fefc81  adr        x1, #0x211e
//   0x4190: b0ffffe2  adrp       x2, #0x1000
//   0x4194: 9134d842  add        x2, x2, #0xd36
//   0x4198: 52800080  mov        w0, #4
//   0x419c: 940012a1  bl         #0x8c20
//   0x41a0: b0000068  adrp       x8, #0x11000
//   0x41a4: f903251f  str        xzr, [x8, #0x648]
//   0x41a8: d503201f  nop        
//   0x41ac: 50fefb81  adr        x1, #0x211e
//   0x41b0: b0ffffe2  adrp       x2, #0x1000
//   0x41b4: 91391042  add        x2, x2, #0xe44
//   0x41b8: 528000c0  mov        w0, #6
//   0x41bc: 94001299  bl         #0x8c20
//   0x41c0: 12800073  mov        w19, #-4
//   0x41c4: 17ffff65  b          #0x3f58
//   0x41c8: f9431ee8  ldr        x8, [x23, #0x638]
//   0x41cc: b4000568  cbz        x8, #0x4278
//   0x41d0: f9431a89  ldr        x9, [x20, #0x630]
//   0x41d4: b4000529  cbz        x9, #0x4278
//   0x41d8: f9432b2a  ldr        x10, [x25, #0x650]
//   0x41dc: f100215f  cmp        x10, #8
//   0x41e0: 54000103  b.lo       #0x4200
//   0x41e4: d343fd4a  lsr        x10, x10, #3
//   0x41e8: f940010b  ldr        x11, [x8]
//   0x41ec: b40000ab  cbz        x11, #0x4200
//   0x41f0: 91002108  add        x8, x8, #8
//   0x41f4: f100054a  subs       x10, x10, #1
//   0x41f8: f800852b  str        x11, [x9], #8
//   0x41fc: 54ffff61  b.ne       #0x41e8
//   0x4200: b9462ec8  ldr        w8, [x22, #0x62c]
//   0x4204: 51005509  sub        w9, w8, #0x15
//   0x4208: 7100711f  cmp        w8, #0x1c
//   0x420c: 7a42d920  ccmp       w9, #2, #0, le
//   0x4210: 540000a8  b.hi       #0x4224
//   0x4214: b0000068  adrp       x8, #0x11000
//   0x4218: f9431a89  ldr        x9, [x20, #0x630]
//   0x421c: f9432508  ldr        x8, [x8, #0x648]
//   0x4220: f9000109  str        x9, [x8]
//   0x4224: d503201f  nop        
//   0x4228: 50fef7a1  adr        x1, #0x211e
//   0x422c: d0ffffe2  adrp       x2, #0x2000
//   0x4230: 910b6c42  add        x2, x2, #0x2db
//   0x4234: 528000c0  mov        w0, #6
//   0x4238: 9400127a  bl         #0x8c20
//   0x423c: 940004cb  bl         #0x5568
//   0x4240: 2a0003f3  mov        w19, w0
//   0x4244: 340003e0  cbz        w0, #0x42c0
//   0x4248: d503201f  nop        
//   0x424c: 50fef681  adr        x1, #0x211e
//   0x4250: d0ffffe2  adrp       x2, #0x2000
//   0x4254: 9114fc42  add        x2, x2, #0x53f
//   0x4258: 17ffff44  b          #0x3f68
//   0x425c: 53083c63  ubfx       w3, w3, #8, #8
//   0x4260: d503201f  nop        
//   0x4264: 50fef5c1  adr        x1, #0x211e
//   0x4268: d0ffffe2  adrp       x2, #0x2000
//   0x426c: 910be442  add        x2, x2, #0x2f9
//   0x4270: 528000c0  mov        w0, #6
//   0x4274: 1400000c  b          #0x42a4
//   0x4278: d503201f  nop        
//   0x427c: 50fef501  adr        x1, #0x211e
//   0x4280: d0ffffe2  adrp       x2, #0x2000
//   0x4284: 9111f842  add        x2, x2, #0x47e
//   0x4288: 528000c0  mov        w0, #6
//   0x428c: 12800003  mov        w3, #-1
//   0x4290: 12800013  mov        w19, #-1
//   0x4294: 17ffff37  b          #0x3f70
//   0x4298: d0ffffe2  adrp       x2, #0x2000
//   0x429c: 91236042  add        x2, x2, #0x8d8
//   0x42a0: 52800080  mov        w0, #4
//   0x42a4: 9400125f  bl         #0x8c20
//   0x42a8: 12800133  mov        w19, #-0xa
//   0x42ac: d503201f  nop        
//   0x42b0: 50fef361  adr        x1, #0x211e
//   0x42b4: d0ffffe2  adrp       x2, #0x2000
//   0x42b8: 9119e842  add        x2, x2, #0x67a
//   0x42bc: 17ffff2b  b          #0x3f68
//   0x42c0: 52800028  mov        w8, #1
//   0x42c4: 39190308  strb       w8, [x24, #0x640]
//   0x42c8: f9432ea0  ldr        x0, [x21, #0x658]
//   0x42cc: b5ffeb20  cbnz       x0, #0x4030
//   0x42d0: 17ffff5a  b          #0x4038
//   0x42d4: 94000002  bl         #0x42dc
//   0x42d8: 94001282  bl         #0x8ce0

// ----------------------------------------------------------------------------
// FDE[07] XasanInstallMallocDispatch_42dc (0x42dc..0x45bc, 736 bytes, 184 instructions)
// Summary / Tóm tắt: Installs XASan allocator hooks into Bionic MallocDispatch (@ 0x42dc..0x45bc)
// ----------------------------------------------------------------------------
//   0x42dc: d10083ff  sub        sp, sp, #0x20
//   0x42e0: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x42e4: 910043fd  add        x29, sp, #0x10
//   0x42e8: 940000e4  bl         #0x4678
//   0x42ec: 36f80140  tbz        w0, #0x1f, #0x4314
//   0x42f0: d503201f  nop        
//   0x42f4: 50fef141  adr        x1, #0x211e
//   0x42f8: d0ffffe2  adrp       x2, #0x2000
//   0x42fc: 91101042  add        x2, x2, #0x404
//   0x4300: 528000c0  mov        w0, #6
//   0x4304: 94001247  bl         #0x8c20
//   0x4308: 128000c8  mov        w8, #-7
//   0x430c: b81fc3a8  stur       w8, [x29, #-4]
//   0x4310: 140000a7  b          #0x45ac
//   0x4314: d503201f  nop        
//   0x4318: 100698c8  adr        x8, #0x11630
//   0x431c: f9400108  ldr        x8, [x8]
//   0x4320: d503201f  nop        
//   0x4324: 100014c9  adr        x9, #0x45bc
//   0x4328: f9000d09  str        x9, [x8, #0x18]
//   0x432c: d2800080  mov        x0, #4
//   0x4330: 94001270  bl         #0x8cf0
//   0x4334: d503201f  nop        
//   0x4338: 100697c8  adr        x8, #0x11630
//   0x433c: f9400108  ldr        x8, [x8]
//   0x4340: f9400d08  ldr        x8, [x8, #0x18]
//   0x4344: d503201f  nop        
//   0x4348: 10069789  adr        x9, #0x11638
//   0x434c: f9400129  ldr        x9, [x9]
//   0x4350: f9400d29  ldr        x9, [x9, #0x18]
//   0x4354: eb09011f  cmp        x8, x9
//   0x4358: 54000140  b.eq       #0x4380
//   0x435c: d503201f  nop        
//   0x4360: 50feede1  adr        x1, #0x211e
//   0x4364: d0ffffe2  adrp       x2, #0x2000
//   0x4368: 9113c442  add        x2, x2, #0x4f1
//   0x436c: 528000c0  mov        w0, #6
//   0x4370: 9400122c  bl         #0x8c20
//   0x4374: 12800008  mov        w8, #-1
//   0x4378: b81fc3a8  stur       w8, [x29, #-4]
//   0x437c: 1400008c  b          #0x45ac
//   0x4380: d503201f  nop        
//   0x4384: 10069568  adr        x8, #0x11630
//   0x4388: f9400108  ldr        x8, [x8]
//   0x438c: d503201f  nop        
//   0x4390: 10001269  adr        x9, #0x45dc
//   0x4394: f9000509  str        x9, [x8, #8]
//   0x4398: aa1f03e0  mov        x0, xzr
//   0x439c: 94001259  bl         #0x8d00
//   0x43a0: d503201f  nop        
//   0x43a4: 10069468  adr        x8, #0x11630
//   0x43a8: f9400108  ldr        x8, [x8]
//   0x43ac: f9400508  ldr        x8, [x8, #8]
//   0x43b0: d503201f  nop        
//   0x43b4: 10069429  adr        x9, #0x11638
//   0x43b8: f9400129  ldr        x9, [x9]
//   0x43bc: f9400529  ldr        x9, [x9, #8]
//   0x43c0: eb09011f  cmp        x8, x9
//   0x43c4: 54000140  b.eq       #0x43ec
//   0x43c8: d503201f  nop        
//   0x43cc: 50feea81  adr        x1, #0x211e
//   0x43d0: b0ffffe2  adrp       x2, #0x1000
//   0x43d4: 913ab042  add        x2, x2, #0xeac
//   0x43d8: 528000c0  mov        w0, #6
//   0x43dc: 94001211  bl         #0x8c20
//   0x43e0: 12800028  mov        w8, #-2
//   0x43e4: b81fc3a8  stur       w8, [x29, #-4]
//   0x43e8: 14000071  b          #0x45ac
//   0x43ec: d503201f  nop        
//   0x43f0: 10069208  adr        x8, #0x11630
//   0x43f4: f9400108  ldr        x8, [x8]
//   0x43f8: d503201f  nop        
//   0x43fc: 10000fe9  adr        x9, #0x45f8
//   0x4400: f9000109  str        x9, [x8]
//   0x4404: d2800020  mov        x0, #1
//   0x4408: d2800081  mov        x1, #4
//   0x440c: 94001241  bl         #0x8d10
//   0x4410: d503201f  nop        
//   0x4414: 100690e8  adr        x8, #0x11630
//   0x4418: f9400108  ldr        x8, [x8]
//   0x441c: f9400108  ldr        x8, [x8]
//   0x4420: d503201f  nop        
//   0x4424: 100690a9  adr        x9, #0x11638
//   0x4428: f9400129  ldr        x9, [x9]
//   0x442c: f9400129  ldr        x9, [x9]
//   0x4430: eb09011f  cmp        x8, x9
//   0x4434: 54000140  b.eq       #0x445c
//   0x4438: d503201f  nop        
//   0x443c: 50fee701  adr        x1, #0x211e
//   0x4440: b0ffffe2  adrp       x2, #0x1000
//   0x4444: 913d4442  add        x2, x2, #0xf51
//   0x4448: 528000c0  mov        w0, #6
//   0x444c: 940011f5  bl         #0x8c20
//   0x4450: 12800048  mov        w8, #-3
//   0x4454: b81fc3a8  stur       w8, [x29, #-4]
//   0x4458: 14000055  b          #0x45ac
//   0x445c: d503201f  nop        
//   0x4460: 10068e88  adr        x8, #0x11630
//   0x4464: f9400108  ldr        x8, [x8]
//   0x4468: d503201f  nop        
//   0x446c: 10000d69  adr        x9, #0x4618
//   0x4470: f9001d09  str        x9, [x8, #0x38]
//   0x4474: aa1f03e0  mov        x0, xzr
//   0x4478: d2800101  mov        x1, #8
//   0x447c: 94001229  bl         #0x8d20
//   0x4480: d503201f  nop        
//   0x4484: 10068d68  adr        x8, #0x11630
//   0x4488: f9400108  ldr        x8, [x8]
//   0x448c: f9401d08  ldr        x8, [x8, #0x38]
//   0x4490: d503201f  nop        
//   0x4494: 10068d29  adr        x9, #0x11638
//   0x4498: f9400129  ldr        x9, [x9]
//   0x449c: f9401d29  ldr        x9, [x9, #0x38]
//   0x44a0: eb09011f  cmp        x8, x9
//   0x44a4: 54000140  b.eq       #0x44cc
//   0x44a8: d503201f  nop        
//   0x44ac: 50fee381  adr        x1, #0x211e
//   0x44b0: d0ffffe2  adrp       x2, #0x2000
//   0x44b4: 911b9c42  add        x2, x2, #0x6e7
//   0x44b8: 528000c0  mov        w0, #6
//   0x44bc: 940011d9  bl         #0x8c20
//   0x44c0: 12800068  mov        w8, #-4
//   0x44c4: b81fc3a8  stur       w8, [x29, #-4]
//   0x44c8: 14000039  b          #0x45ac
//   0x44cc: d503201f  nop        
//   0x44d0: 10068b08  adr        x8, #0x11630
//   0x44d4: f9400108  ldr        x8, [x8]
//   0x44d8: d503201f  nop        
//   0x44dc: 10000ae9  adr        x9, #0x4638
//   0x44e0: f9001509  str        x9, [x8, #0x28]
//   0x44e4: d2800080  mov        x0, #4
//   0x44e8: d2800101  mov        x1, #8
//   0x44ec: 94001211  bl         #0x8d30
//   0x44f0: d503201f  nop        
//   0x44f4: 100689e8  adr        x8, #0x11630
//   0x44f8: f9400108  ldr        x8, [x8]
//   0x44fc: f9401508  ldr        x8, [x8, #0x28]
//   0x4500: d503201f  nop        
//   0x4504: 100689a9  adr        x9, #0x11638
//   0x4508: f9400129  ldr        x9, [x9]
//   0x450c: f9401529  ldr        x9, [x9, #0x28]
//   0x4510: eb09011f  cmp        x8, x9
//   0x4514: 54000140  b.eq       #0x453c
//   0x4518: d503201f  nop        
//   0x451c: 50fee001  adr        x1, #0x211e
//   0x4520: d0ffffe2  adrp       x2, #0x2000
//   0x4524: 91088842  add        x2, x2, #0x222
//   0x4528: 528000c0  mov        w0, #6
//   0x452c: 940011bd  bl         #0x8c20
//   0x4530: 12800088  mov        w8, #-5
//   0x4534: b81fc3a8  stur       w8, [x29, #-4]
//   0x4538: 1400001d  b          #0x45ac
//   0x453c: d503201f  nop        
//   0x4540: 10068788  adr        x8, #0x11630
//   0x4544: f9400108  ldr        x8, [x8]
//   0x4548: d503201f  nop        
//   0x454c: 10000869  adr        x9, #0x4658
//   0x4550: f9001109  str        x9, [x8, #0x20]
//   0x4554: aa1f03e0  mov        x0, xzr
//   0x4558: 940011fa  bl         #0x8d40
//   0x455c: d503201f  nop        
//   0x4560: 10068688  adr        x8, #0x11630
//   0x4564: f9400108  ldr        x8, [x8]
//   0x4568: f9401108  ldr        x8, [x8, #0x20]
//   0x456c: d503201f  nop        
//   0x4570: 10068649  adr        x9, #0x11638
//   0x4574: f9400129  ldr        x9, [x9]
//   0x4578: f9401129  ldr        x9, [x9, #0x20]
//   0x457c: eb09011f  cmp        x8, x9
//   0x4580: 54000140  b.eq       #0x45a8
//   0x4584: d503201f  nop        
//   0x4588: 50fedca1  adr        x1, #0x211e
//   0x458c: d0ffffe2  adrp       x2, #0x2000
//   0x4590: 9120fc42  add        x2, x2, #0x83f
//   0x4594: 528000c0  mov        w0, #6
//   0x4598: 940011a2  bl         #0x8c20
//   0x459c: 128000a8  mov        w8, #-6
//   0x45a0: b81fc3a8  stur       w8, [x29, #-4]
//   0x45a4: 14000002  b          #0x45ac
//   0x45a8: b81fc3bf  stur       wzr, [x29, #-4]
//   0x45ac: b85fc3a0  ldur       w0, [x29, #-4]
//   0x45b0: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x45b4: 910083ff  add        sp, sp, #0x20
//   0x45b8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[08] XasanRestoreReallocSlot_45bc (0x45bc..0x45dc, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->realloc (+0x18) from default dispatch (@ 0x45bc..0x45dc)
// ----------------------------------------------------------------------------
//   0x45bc: b0000068  adrp       x8, #0x11000
//   0x45c0: b0000069  adrp       x9, #0x11000
//   0x45c4: aa1f03e0  mov        x0, xzr
//   0x45c8: f9431d08  ldr        x8, [x8, #0x638]
//   0x45cc: f9431929  ldr        x9, [x9, #0x630]
//   0x45d0: f9400d08  ldr        x8, [x8, #0x18]
//   0x45d4: f9000d28  str        x8, [x9, #0x18]
//   0x45d8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[09] XasanRestoreFreeSlot_45dc (0x45dc..0x45f8, 28 bytes, 7 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->free (+0x08) from default dispatch (@ 0x45dc..0x45f8)
// ----------------------------------------------------------------------------
//   0x45dc: b0000068  adrp       x8, #0x11000
//   0x45e0: b0000069  adrp       x9, #0x11000
//   0x45e4: f9431d08  ldr        x8, [x8, #0x638]
//   0x45e8: f9431929  ldr        x9, [x9, #0x630]
//   0x45ec: f9400508  ldr        x8, [x8, #8]
//   0x45f0: f9000528  str        x8, [x9, #8]
//   0x45f4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[10] XasanRestoreMallocSlot_45f8 (0x45f8..0x4618, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->malloc (+0x00) from default dispatch (@ 0x45f8..0x4618)
// ----------------------------------------------------------------------------
//   0x45f8: b0000068  adrp       x8, #0x11000
//   0x45fc: b0000069  adrp       x9, #0x11000
//   0x4600: aa1f03e0  mov        x0, xzr
//   0x4604: f9431d08  ldr        x8, [x8, #0x638]
//   0x4608: f9431929  ldr        x9, [x9, #0x630]
//   0x460c: f9400108  ldr        x8, [x8]
//   0x4610: f9000128  str        x8, [x9]
//   0x4614: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[11] XasanRestoreUsableSizeSlot_4618 (0x4618..0x4638, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->malloc_usable_size (+0x38) from default dispatch (@ 0x4618..0x4638)
// ----------------------------------------------------------------------------
//   0x4618: b0000068  adrp       x8, #0x11000
//   0x461c: b0000069  adrp       x9, #0x11000
//   0x4620: aa1f03e0  mov        x0, xzr
//   0x4624: f9431d08  ldr        x8, [x8, #0x638]
//   0x4628: f9431929  ldr        x9, [x9, #0x630]
//   0x462c: f9401d08  ldr        x8, [x8, #0x38]
//   0x4630: f9001d28  str        x8, [x9, #0x38]
//   0x4634: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[12] XasanRestoreMemalignSlot_4638 (0x4638..0x4658, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->memalign (+0x28) from default dispatch (@ 0x4638..0x4658)
// ----------------------------------------------------------------------------
//   0x4638: b0000068  adrp       x8, #0x11000
//   0x463c: b0000069  adrp       x9, #0x11000
//   0x4640: aa1f03e0  mov        x0, xzr
//   0x4644: f9431d08  ldr        x8, [x8, #0x638]
//   0x4648: f9431929  ldr        x9, [x9, #0x630]
//   0x464c: f9401508  ldr        x8, [x8, #0x28]
//   0x4650: f9001528  str        x8, [x9, #0x28]
//   0x4654: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[13] XasanRestoreCallocSlot_4658 (0x4658..0x4678, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->calloc (+0x20) from default dispatch (@ 0x4658..0x4678)
// ----------------------------------------------------------------------------
//   0x4658: b0000068  adrp       x8, #0x11000
//   0x465c: b0000069  adrp       x9, #0x11000
//   0x4660: aa1f03e0  mov        x0, xzr
//   0x4664: f9431d08  ldr        x8, [x8, #0x638]
//   0x4668: f9431929  ldr        x9, [x9, #0x630]
//   0x466c: f9401108  ldr        x8, [x8, #0x20]
//   0x4670: f9001128  str        x8, [x9, #0x20]
//   0x4674: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[14] XasanResolveDefaultDispatch_4678 (0x4678..0x4700, 136 bytes, 34 instructions)
// Summary / Tóm tắt: Resolves __libc_globals and _ZL30__libc_malloc_default_dispatch (@ 0x4678..0x4700)
// ----------------------------------------------------------------------------
//   0x4678: b0000069  adrp       x9, #0x11000
//   0x467c: b0000068  adrp       x8, #0x11000
//   0x4680: f9431d29  ldr        x9, [x9, #0x638]
//   0x4684: f943190a  ldr        x10, [x8, #0x630]
//   0x4688: f100013f  cmp        x9, #0
//   0x468c: fa401944  ccmp       x10, #0, #4, ne
//   0x4690: 54000061  b.ne       #0x469c
//   0x4694: 12800000  mov        w0, #-1
//   0x4698: d65f03c0  ret        
//   0x469c: b000006b  adrp       x11, #0x11000
//   0x46a0: f943296b  ldr        x11, [x11, #0x650]
//   0x46a4: f100217f  cmp        x11, #8
//   0x46a8: 54000103  b.lo       #0x46c8
//   0x46ac: d343fd6b  lsr        x11, x11, #3
//   0x46b0: f940012c  ldr        x12, [x9]
//   0x46b4: b40000ac  cbz        x12, #0x46c8
//   0x46b8: 91002129  add        x9, x9, #8
//   0x46bc: f100056b  subs       x11, x11, #1
//   0x46c0: f800854c  str        x12, [x10], #8
//   0x46c4: 54ffff61  b.ne       #0x46b0
//   0x46c8: b0000069  adrp       x9, #0x11000
//   0x46cc: b9462d29  ldr        w9, [x9, #0x62c]
//   0x46d0: 5100552a  sub        w10, w9, #0x15
//   0x46d4: 71000d5f  cmp        w10, #3
//   0x46d8: 7a5d2920  ccmp       w9, #0x1d, #0, hs
//   0x46dc: 540000eb  b.lt       #0x46f8
//   0x46e0: b0000069  adrp       x9, #0x11000
//   0x46e4: f9431908  ldr        x8, [x8, #0x630]
//   0x46e8: 2a1f03e0  mov        w0, wzr
//   0x46ec: f9432529  ldr        x9, [x9, #0x648]
//   0x46f0: f9000128  str        x8, [x9]
//   0x46f4: d65f03c0  ret        
//   0x46f8: 2a1f03e0  mov        w0, wzr
//   0x46fc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[15] XasanParseConfigFile_4700 (0x4700..0x480c, 268 bytes, 67 instructions)
// Summary / Tóm tắt: Parses xasan.config key=value parameters (@ 0x4700..0x480c)
// ----------------------------------------------------------------------------
//   0x4700: d10203ff  sub        sp, sp, #0x80
//   0x4704: a9057bfd  stp        x29, x30, [sp, #0x50]
//   0x4708: a90657f6  stp        x22, x21, [sp, #0x60]
//   0x470c: a9074ff4  stp        x20, x19, [sp, #0x70]
//   0x4710: 910143fd  add        x29, sp, #0x50
//   0x4714: d53bd055  mrs        x21, tpidr_el0
//   0x4718: 2a0003e8  mov        w8, w0
//   0x471c: f94016a9  ldr        x9, [x21, #0x28]
//   0x4720: 12800060  mov        w0, #-4
//   0x4724: f81f83a9  stur       x9, [x29, #-8]
//   0x4728: b40005e2  cbz        x2, #0x47e4
//   0x472c: aa0303f3  mov        x19, x3
//   0x4730: b40005a3  cbz        x3, #0x47e4
//   0x4734: b0000069  adrp       x9, #0x11000
//   0x4738: aa0103e0  mov        x0, x1
//   0x473c: aa0203f4  mov        x20, x2
//   0x4740: b9066928  str        w8, [x9, #0x668]
//   0x4744: 94001183  bl         #0x8d50
//   0x4748: b0000076  adrp       x22, #0x11000
//   0x474c: f9033ac0  str        x0, [x22, #0x670]
//   0x4750: aa1403e0  mov        x0, x20
//   0x4754: 9400117f  bl         #0x8d50
//   0x4758: b0000074  adrp       x20, #0x11000
//   0x475c: f9033e80  str        x0, [x20, #0x678]
//   0x4760: aa1303e0  mov        x0, x19
//   0x4764: 9400117b  bl         #0x8d50
//   0x4768: b0000073  adrp       x19, #0x11000
//   0x476c: f9034260  str        x0, [x19, #0x680]
//   0x4770: 910043e0  add        x0, sp, #0x10
//   0x4774: 9400117b  bl         #0x8d60
//   0x4778: 910043e0  add        x0, sp, #0x10
//   0x477c: 52800021  mov        w1, #1
//   0x4780: 9400117c  bl         #0x8d70
//   0x4784: 910043e0  add        x0, sp, #0x10
//   0x4788: 52a00201  mov        w1, #0x100000
//   0x478c: 9400117d  bl         #0x8d80
//   0x4790: d503201f  nop        
//   0x4794: 100003c2  adr        x2, #0x480c
//   0x4798: 910023e0  add        x0, sp, #8
//   0x479c: 910043e1  add        x1, sp, #0x10
//   0x47a0: aa1f03e3  mov        x3, xzr
//   0x47a4: 9400117b  bl         #0x8d90
//   0x47a8: 34000180  cbz        w0, #0x47d8
//   0x47ac: f9433ac0  ldr        x0, [x22, #0x670]
//   0x47b0: b4000040  cbz        x0, #0x47b8
//   0x47b4: 94001153  bl         #0x8d00
//   0x47b8: f9433e80  ldr        x0, [x20, #0x678]
//   0x47bc: b4000040  cbz        x0, #0x47c4
//   0x47c0: 94001150  bl         #0x8d00
//   0x47c4: f9434260  ldr        x0, [x19, #0x680]
//   0x47c8: b4000040  cbz        x0, #0x47d0
//   0x47cc: 9400114d  bl         #0x8d00
//   0x47d0: 12800160  mov        w0, #-0xc
//   0x47d4: 14000004  b          #0x47e4
//   0x47d8: 910043e0  add        x0, sp, #0x10
//   0x47dc: 94001171  bl         #0x8da0
//   0x47e0: 2a1f03e0  mov        w0, wzr
//   0x47e4: f94016a8  ldr        x8, [x21, #0x28]
//   0x47e8: f85f83a9  ldur       x9, [x29, #-8]
//   0x47ec: eb09011f  cmp        x8, x9
//   0x47f0: 540000c1  b.ne       #0x4808
//   0x47f4: a9474ff4  ldp        x20, x19, [sp, #0x70]
//   0x47f8: a94657f6  ldp        x22, x21, [sp, #0x60]
//   0x47fc: a9457bfd  ldp        x29, x30, [sp, #0x50]
//   0x4800: 910203ff  add        sp, sp, #0x80
//   0x4804: d65f03c0  ret        
//   0x4808: 9400116a  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[16] XasanFde_480c (0x480c..0x4b88, 892 bytes, 223 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x480c..0x4b88
// ----------------------------------------------------------------------------
//   0x480c: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x4810: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x4814: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x4818: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x481c: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x4820: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x4824: 910003fd  mov        x29, sp
//   0x4828: d11303ff  sub        sp, sp, #0x4c0
//   0x482c: d53bd055  mrs        x21, tpidr_el0
//   0x4830: f94016a8  ldr        x8, [x21, #0x28]
//   0x4834: f81e83a8  stur       x8, [x29, #-0x18]
//   0x4838: 94001162  bl         #0x8dc0
//   0x483c: d503201f  nop        
//   0x4840: 30fef2c1  adr        x1, #0x2699
//   0x4844: 94001163  bl         #0x8dd0
//   0x4848: 52800020  mov        w0, #1
//   0x484c: 52800201  mov        w1, #0x10
//   0x4850: 94001130  bl         #0x8d10
//   0x4854: b0000077  adrp       x23, #0x11000
//   0x4858: f90332e0  str        x0, [x23, #0x660]
//   0x485c: b40011c0  cbz        x0, #0x4a94
//   0x4860: b0000076  adrp       x22, #0x11000
//   0x4864: f94342c4  ldr        x4, [x22, #0x680]
//   0x4868: b4001164  cbz        x4, #0x4a94
//   0x486c: d0ffffe5  adrp       x5, #0x2000
//   0x4870: 910808a5  add        x5, x5, #0x202
//   0x4874: 9102a3e0  add        x0, sp, #0xa8
//   0x4878: 940000c4  bl         #0x4b88
//   0x487c: 7100041f  cmp        w0, #1
//   0x4880: 540010ab  b.lt       #0x4a94
//   0x4884: d0ffffe1  adrp       x1, #0x2000
//   0x4888: 91126c21  add        x1, x1, #0x49b
//   0x488c: 9102a3e0  add        x0, sp, #0xa8
//   0x4890: 94001154  bl         #0x8de0
//   0x4894: b4001000  cbz        x0, #0x4a94
//   0x4898: aa0003f3  mov        x19, x0
//   0x489c: 9102a3e0  add        x0, sp, #0xa8
//   0x48a0: 52808001  mov        w1, #0x400
//   0x48a4: aa1303e2  mov        x2, x19
//   0x48a8: 94001152  bl         #0x8df0
//   0x48ac: b40009a0  cbz        x0, #0x49e0
//   0x48b0: 528cac98  mov        w24, #0x6564
//   0x48b4: 528dccba  mov        w26, #0x6e65
//   0x48b8: 528c2e7c  mov        w28, #0x6173
//   0x48bc: 72aeac58  movk       w24, #0x7562, lsl #16
//   0x48c0: 52800cf9  mov        w25, #0x67
//   0x48c4: 72ac4c3a  movk       w26, #0x6261, lsl #16
//   0x48c8: 528cad9b  mov        w27, #0x656c
//   0x48cc: 72ae0dbc  movk       w28, #0x706d, lsl #16
//   0x48d0: d0fffff4  adrp       x20, #0x2000
//   0x48d4: 911a9294  add        x20, x20, #0x6a4
//   0x48d8: 1400000a  b          #0x4900
//   0x48dc: 910003e0  mov        x0, sp
//   0x48e0: 94001148  bl         #0x8e00
//   0x48e4: f94332e8  ldr        x8, [x23, #0x660]
//   0x48e8: b9000100  str        w0, [x8]
//   0x48ec: 9102a3e0  add        x0, sp, #0xa8
//   0x48f0: 52808001  mov        w1, #0x400
//   0x48f4: aa1303e2  mov        x2, x19
//   0x48f8: 9400113e  bl         #0x8df0
//   0x48fc: b4000720  cbz        x0, #0x49e0
//   0x4900: 9102a3e0  add        x0, sp, #0xa8
//   0x4904: 910223e2  add        x2, sp, #0x88
//   0x4908: 910003e3  mov        x3, sp
//   0x490c: aa1403e1  mov        x1, x20
//   0x4910: 94001140  bl         #0x8e10
//   0x4914: 7100081f  cmp        w0, #2
//   0x4918: 54fffea1  b.ne       #0x48ec
//   0x491c: 394223e8  ldrb       w8, [sp, #0x88]
//   0x4920: 7101911f  cmp        w8, #0x64
//   0x4924: 54000161  b.ne       #0x4950
//   0x4928: b9408be8  ldr        w8, [sp, #0x88]
//   0x492c: 394233e9  ldrb       w9, [sp, #0x8c]
//   0x4930: 6b18011f  cmp        w8, w24
//   0x4934: 7a590120  ccmp       w9, w25, #0, eq
//   0x4938: 54fffda1  b.ne       #0x48ec
//   0x493c: 910003e0  mov        x0, sp
//   0x4940: 94001130  bl         #0x8e00
//   0x4944: f94332e8  ldr        x8, [x23, #0x660]
//   0x4948: b9000d00  str        w0, [x8, #0xc]
//   0x494c: 17ffffe8  b          #0x48ec
//   0x4950: b9408be8  ldr        w8, [sp, #0x88]
//   0x4954: 79411be9  ldrh       w9, [sp, #0x8c]
//   0x4958: 6b1a011f  cmp        w8, w26
//   0x495c: 7a5b0120  ccmp       w9, w27, #0, eq
//   0x4960: 54fffbe0  b.eq       #0x48dc
//   0x4964: b9408be8  ldr        w8, [sp, #0x88]
//   0x4968: 79411be9  ldrh       w9, [sp, #0x8c]
//   0x496c: 6b1c011f  cmp        w8, w28
//   0x4970: 7a5b0120  ccmp       w9, w27, #0, eq
//   0x4974: 540002c0  b.eq       #0x49cc
//   0x4978: a948a7e8  ldp        x8, x9, [sp, #0x88]
//   0x497c: d28c2daa  mov        x10, #0x616d
//   0x4980: f2aa6f0a  movk       x10, #0x5378, lsl #16
//   0x4984: f2cdad2a  movk       x10, #0x6d69, lsl #32
//   0x4988: f2ed8eaa  movk       x10, #0x6c75, lsl #48
//   0x498c: eb0a011f  cmp        x8, x10
//   0x4990: d28c2e8a  mov        x10, #0x6174
//   0x4994: f2acadca  movk       x10, #0x656e, lsl #16
//   0x4998: b9409be8  ldr        w8, [sp, #0x98]
//   0x499c: f2ceadea  movk       x10, #0x756f, lsl #32
//   0x49a0: f2e82e6a  movk       x10, #0x4173, lsl #48
//   0x49a4: fa4a0120  ccmp       x9, x10, #0, eq
//   0x49a8: 528d8d89  mov        w9, #0x6c6c
//   0x49ac: 72ac6de9  movk       w9, #0x636f, lsl #16
//   0x49b0: 7a490100  ccmp       w8, w9, #0, eq
//   0x49b4: 54fff9c1  b.ne       #0x48ec
//   0x49b8: 910003e0  mov        x0, sp
//   0x49bc: 94001111  bl         #0x8e00
//   0x49c0: f94332e8  ldr        x8, [x23, #0x660]
//   0x49c4: b9000900  str        w0, [x8, #8]
//   0x49c8: 17ffffc9  b          #0x48ec
//   0x49cc: 910003e0  mov        x0, sp
//   0x49d0: 9400110c  bl         #0x8e00
//   0x49d4: f94332e8  ldr        x8, [x23, #0x660]
//   0x49d8: b9000500  str        w0, [x8, #4]
//   0x49dc: 17ffffc4  b          #0x48ec
//   0x49e0: aa1303e0  mov        x0, x19
//   0x49e4: 9400110f  bl         #0x8e20
//   0x49e8: f94332e0  ldr        x0, [x23, #0x660]
//   0x49ec: b9400008  ldr        w8, [x0]
//   0x49f0: 340003a8  cbz        w8, #0x4a64
//   0x49f4: 52800028  mov        w8, #1
//   0x49f8: b9400c09  ldr        w9, [x0, #0xc]
//   0x49fc: b0000073  adrp       x19, #0x11000
//   0x4a00: b900b3e8  str        w8, [sp, #0xb0]
//   0x4a04: b900c7e9  str        w9, [sp, #0xc4]
//   0x4a08: 2940e008  ldp        w8, w24, [x0, #4]
//   0x4a0c: f9433e60  ldr        x0, [x19, #0x678]
//   0x4a10: 2917ffe8  stp        w8, wzr, [sp, #0xbc]
//   0x4a14: 940010cf  bl         #0x8d50
//   0x4a18: f94342c8  ldr        x8, [x22, #0x680]
//   0x4a1c: f9006be0  str        x0, [sp, #0xd0]
//   0x4a20: aa0803e0  mov        x0, x8
//   0x4a24: 940010cb  bl         #0x8d50
//   0x4a28: b0000074  adrp       x20, #0x11000
//   0x4a2c: f9006fe0  str        x0, [sp, #0xd8]
//   0x4a30: f9433a88  ldr        x8, [x20, #0x670]
//   0x4a34: aa0803e0  mov        x0, x8
//   0x4a38: 940010c6  bl         #0x8d50
//   0x4a3c: b0000068  adrp       x8, #0x11000
//   0x4a40: f90073e0  str        x0, [sp, #0xe0]
//   0x4a44: b9466919  ldr        w25, [x8, #0x668]
//   0x4a48: b900cbf9  str        w25, [sp, #0xc8]
//   0x4a4c: 94001081  bl         #0x8c50
//   0x4a50: 71007b3f  cmp        w25, #0x1e
//   0x4a54: 5400046b  b.lt       #0x4ae0
//   0x4a58: 0b000808  add        w8, w0, w0, lsl #2
//   0x4a5c: 531e7508  lsl        w8, w8, #2
//   0x4a60: 14000024  b          #0x4af0
//   0x4a64: 940010a7  bl         #0x8d00
//   0x4a68: b0000068  adrp       x8, #0x11000
//   0x4a6c: f9433900  ldr        x0, [x8, #0x670]
//   0x4a70: b4000040  cbz        x0, #0x4a78
//   0x4a74: 940010a3  bl         #0x8d00
//   0x4a78: b0000068  adrp       x8, #0x11000
//   0x4a7c: f9433d00  ldr        x0, [x8, #0x678]
//   0x4a80: b4000040  cbz        x0, #0x4a88
//   0x4a84: 9400109f  bl         #0x8d00
//   0x4a88: f94342c0  ldr        x0, [x22, #0x680]
//   0x4a8c: b4000040  cbz        x0, #0x4a94
//   0x4a90: 9400109c  bl         #0x8d00
//   0x4a94: b0ffffe2  adrp       x2, #0x1000
//   0x4a98: 9131dc42  add        x2, x2, #0xc77
//   0x4a9c: d0ffffe1  adrp       x1, #0x2000
//   0x4aa0: 91047821  add        x1, x1, #0x11e
//   0x4aa4: 528000c0  mov        w0, #6
//   0x4aa8: 9400105e  bl         #0x8c20
//   0x4aac: f94016a8  ldr        x8, [x21, #0x28]
//   0x4ab0: f85e83a9  ldur       x9, [x29, #-0x18]
//   0x4ab4: eb09011f  cmp        x8, x9
//   0x4ab8: 54000661  b.ne       #0x4b84
//   0x4abc: aa1f03e0  mov        x0, xzr
//   0x4ac0: 911303ff  add        sp, sp, #0x4c0
//   0x4ac4: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x4ac8: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x4acc: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x4ad0: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x4ad4: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x4ad8: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x4adc: d65f03c0  ret        
//   0x4ae0: 7100733f  cmp        w25, #0x1c
//   0x4ae4: 540000cb  b.lt       #0x4afc
//   0x4ae8: 0b000808  add        w8, w0, w0, lsl #2
//   0x4aec: 531f7908  lsl        w8, w8, #1
//   0x4af0: 6b08031f  cmp        w24, w8
//   0x4af4: 1a88b308  csel       w8, w24, w8, lt
//   0x4af8: 14000005  b          #0x4b0c
//   0x4afc: 6b00031f  cmp        w24, w0
//   0x4b00: 1a80b308  csel       w8, w24, w0, lt
//   0x4b04: 71004f3f  cmp        w25, #0x13
//   0x4b08: 1a80c108  csel       w8, w8, w0, gt
//   0x4b0c: f94332e0  ldr        x0, [x23, #0x660]
//   0x4b10: b900bbe8  str        w8, [sp, #0xb8]
//   0x4b14: b4000040  cbz        x0, #0x4b1c
//   0x4b18: 9400107a  bl         #0x8d00
//   0x4b1c: f9433a80  ldr        x0, [x20, #0x670]
//   0x4b20: b4000040  cbz        x0, #0x4b28
//   0x4b24: 94001077  bl         #0x8d00
//   0x4b28: f9433e60  ldr        x0, [x19, #0x678]
//   0x4b2c: b4000040  cbz        x0, #0x4b34
//   0x4b30: 94001074  bl         #0x8d00
//   0x4b34: f94342c0  ldr        x0, [x22, #0x680]
//   0x4b38: b4000040  cbz        x0, #0x4b40
//   0x4b3c: 94001071  bl         #0x8d00
//   0x4b40: 9102a3e0  add        x0, sp, #0xa8
//   0x4b44: 9400002e  bl         #0x4bfc
//   0x4b48: 37f80180  tbnz       w0, #0x1f, #0x4b78
//   0x4b4c: 9102a3e8  add        x8, sp, #0xa8
//   0x4b50: 910003e0  mov        x0, sp
//   0x4b54: ad400500  ldp        q0, q1, [x8]
//   0x4b58: ad410d02  ldp        q2, q3, [x8, #0x20]
//   0x4b5c: ad0007e0  stp        q0, q1, [sp]
//   0x4b60: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x4b64: 9400012c  bl         #0x5014
//   0x4b68: 36fffa20  tbz        w0, #0x1f, #0x4aac
//   0x4b6c: d0ffffe2  adrp       x2, #0x2000
//   0x4b70: 911be842  add        x2, x2, #0x6fa
//   0x4b74: 17ffffca  b          #0x4a9c
//   0x4b78: d0ffffe2  adrp       x2, #0x2000
//   0x4b7c: 9100b442  add        x2, x2, #0x2d
//   0x4b80: 17ffffc7  b          #0x4a9c
//   0x4b84: 9400108b  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[17] XasanFde_4b88 (0x4b88..0x4bfc, 116 bytes, 29 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x4b88..0x4bfc
// ----------------------------------------------------------------------------
//   0x4b88: d103c3ff  sub        sp, sp, #0xf0
//   0x4b8c: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x4b90: 910383fd  add        x29, sp, #0xe0
//   0x4b94: d10183a8  sub        x8, x29, #0x60
//   0x4b98: 928003ea  mov        x10, #-0x20
//   0x4b9c: 910003eb  mov        x11, sp
//   0x4ba0: 91008108  add        x8, x8, #0x20
//   0x4ba4: 910043a9  add        x9, x29, #0x10
//   0x4ba8: f2dff00a  movk       x10, #0xff80, lsl #32
//   0x4bac: 9102016b  add        x11, x11, #0x80
//   0x4bb0: ad0007e0  stp        q0, q1, [sp]
//   0x4bb4: d0ffffe2  adrp       x2, #0x2000
//   0x4bb8: 91053442  add        x2, x2, #0x14d
//   0x4bbc: a93e23a9  stp        x9, x8, [x29, #-0x20]
//   0x4bc0: d10103a3  sub        x3, x29, #0x40
//   0x4bc4: a93f2bab  stp        x11, x10, [x29, #-0x10]
//   0x4bc8: 52808001  mov        w1, #0x400
//   0x4bcc: ad7f07a0  ldp        q0, q1, [x29, #-0x20]
//   0x4bd0: a93a9ba5  stp        x5, x6, [x29, #-0x58]
//   0x4bd4: f81a03a4  stur       x4, [x29, #-0x60]
//   0x4bd8: f81b83a7  stur       x7, [x29, #-0x48]
//   0x4bdc: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x4be0: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x4be4: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x4be8: ad3e07a0  stp        q0, q1, [x29, #-0x40]
//   0x4bec: 94001091  bl         #0x8e30
//   0x4bf0: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x4bf4: 9103c3ff  add        sp, sp, #0xf0
//   0x4bf8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[18] XasanFde_4bfc (0x4bfc..0x4dbc, 448 bytes, 112 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x4bfc..0x4dbc
// ----------------------------------------------------------------------------
//   0x4bfc: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x4c00: f9000bfc  str        x28, [sp, #0x10]
//   0x4c04: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x4c08: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x4c0c: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x4c10: 910003fd  mov        x29, sp
//   0x4c14: d10883ff  sub        sp, sp, #0x220
//   0x4c18: d53bd056  mrs        x22, tpidr_el0
//   0x4c1c: b0000077  adrp       x23, #0x11000
//   0x4c20: f94016c8  ldr        x8, [x22, #0x28]
//   0x4c24: f81f83a8  stur       x8, [x29, #-8]
//   0x4c28: b94612e8  ldr        w8, [x23, #0x610]
//   0x4c2c: 36f80ae8  tbz        w8, #0x1f, #0x4d88
//   0x4c30: aa0003f3  mov        x19, x0
//   0x4c34: d503201f  nop        
//   0x4c38: 10065280  adr        x0, #0x11688
//   0x4c3c: 94001081  bl         #0x8e40
//   0x4c40: b94612e8  ldr        w8, [x23, #0x610]
//   0x4c44: 36f80948  tbz        w8, #0x1f, #0x4d6c
//   0x4c48: d503201f  nop        
//   0x4c4c: 70fec5a0  adr        x0, #0x2503
//   0x4c50: d0ffffe1  adrp       x1, #0x2000
//   0x4c54: 91157421  add        x1, x1, #0x55d
//   0x4c58: f9000bff  str        xzr, [sp, #0x10]
//   0x4c5c: 94001061  bl         #0x8de0
//   0x4c60: b4000720  cbz        x0, #0x4d44
//   0x4c64: aa0003f4  mov        x20, x0
//   0x4c68: 910063e0  add        x0, sp, #0x18
//   0x4c6c: 52804001  mov        w1, #0x200
//   0x4c70: aa1403e2  mov        x2, x20
//   0x4c74: 9400105f  bl         #0x8df0
//   0x4c78: b40001a0  cbz        x0, #0x4cac
//   0x4c7c: 910063e0  add        x0, sp, #0x18
//   0x4c80: 52800521  mov        w1, #0x29
//   0x4c84: 52804002  mov        w2, #0x200
//   0x4c88: 94001072  bl         #0x8e50
//   0x4c8c: 91000400  add        x0, x0, #1
//   0x4c90: d0ffffe1  adrp       x1, #0x2000
//   0x4c94: 9126f821  add        x1, x1, #0x9be
//   0x4c98: 910043e2  add        x2, sp, #0x10
//   0x4c9c: 9400105d  bl         #0x8e10
//   0x4ca0: 7100041f  cmp        w0, #1
//   0x4ca4: 54000040  b.eq       #0x4cac
//   0x4ca8: f9000bff  str        xzr, [sp, #0x10]
//   0x4cac: aa1403e0  mov        x0, x20
//   0x4cb0: 9400105c  bl         #0x8e20
//   0x4cb4: f9400be8  ldr        x8, [sp, #0x10]
//   0x4cb8: b4000468  cbz        x8, #0x4d44
//   0x4cbc: d0ffffe0  adrp       x0, #0x2000
//   0x4cc0: 91289c00  add        x0, x0, #0xa27
//   0x4cc4: d0ffffe1  adrp       x1, #0x2000
//   0x4cc8: 91126c21  add        x1, x1, #0x49b
//   0x4ccc: 94001045  bl         #0x8de0
//   0x4cd0: b40003a0  cbz        x0, #0x4d44
//   0x4cd4: aa0003f4  mov        x20, x0
//   0x4cd8: 910063e0  add        x0, sp, #0x18
//   0x4cdc: 52804001  mov        w1, #0x200
//   0x4ce0: aa1403e2  mov        x2, x20
//   0x4ce4: 94001043  bl         #0x8df0
//   0x4ce8: b4000320  cbz        x0, #0x4d4c
//   0x4cec: b0fffff5  adrp       x21, #0x1000
//   0x4cf0: 913af2b5  add        x21, x21, #0xebc
//   0x4cf4: 14000006  b          #0x4d0c
//   0x4cf8: 910063e0  add        x0, sp, #0x18
//   0x4cfc: 52804001  mov        w1, #0x200
//   0x4d00: aa1403e2  mov        x2, x20
//   0x4d04: 9400103b  bl         #0x8df0
//   0x4d08: b4000220  cbz        x0, #0x4d4c
//   0x4d0c: 910063e0  add        x0, sp, #0x18
//   0x4d10: 910023e2  add        x2, sp, #8
//   0x4d14: 910003e3  mov        x3, sp
//   0x4d18: aa1503e1  mov        x1, x21
//   0x4d1c: 9400103d  bl         #0x8e10
//   0x4d20: 7100081f  cmp        w0, #2
//   0x4d24: 54fffea1  b.ne       #0x4cf8
//   0x4d28: a940a3e9  ldp        x9, x8, [sp, #8]
//   0x4d2c: eb08013f  cmp        x9, x8
//   0x4d30: 54fffe48  b.hi       #0x4cf8
//   0x4d34: f94003f8  ldr        x24, [sp]
//   0x4d38: eb18011f  cmp        x8, x24
//   0x4d3c: 54fffde8  b.hi       #0x4cf8
//   0x4d40: 14000004  b          #0x4d50
//   0x4d44: aa1f03f8  mov        x24, xzr
//   0x4d48: 14000004  b          #0x4d58
//   0x4d4c: aa1f03f8  mov        x24, xzr
//   0x4d50: aa1403e0  mov        x0, x20
//   0x4d54: 94001033  bl         #0x8e20
//   0x4d58: f100031f  cmp        x24, #0
//   0x4d5c: b0000068  adrp       x8, #0x11000
//   0x4d60: 1a9f17e9  cset       w9, eq
//   0x4d64: f9035918  str        x24, [x8, #0x6b0]
//   0x4d68: b90612e9  str        w9, [x23, #0x610]
//   0x4d6c: d503201f  nop        
//   0x4d70: 10000268  adr        x8, #0x4dbc
//   0x4d74: d503201f  nop        
//   0x4d78: 10064880  adr        x0, #0x11688
//   0x4d7c: f9000268  str        x8, [x19]
//   0x4d80: 94001038  bl         #0x8e60
//   0x4d84: b94612e8  ldr        w8, [x23, #0x610]
//   0x4d88: f94016c9  ldr        x9, [x22, #0x28]
//   0x4d8c: f85f83aa  ldur       x10, [x29, #-8]
//   0x4d90: eb0a013f  cmp        x9, x10
//   0x4d94: 54000121  b.ne       #0x4db8
//   0x4d98: 2a0803e0  mov        w0, w8
//   0x4d9c: 910883ff  add        sp, sp, #0x220
//   0x4da0: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x4da4: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x4da8: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x4dac: f9400bfc  ldr        x28, [sp, #0x10]
//   0x4db0: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x4db4: d65f03c0  ret        
//   0x4db8: 94000ffe  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[19] XasanFde_4dbc (0x4dbc..0x5014, 600 bytes, 150 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x4dbc..0x5014
// ----------------------------------------------------------------------------
//   0x4dbc: d10383ff  sub        sp, sp, #0xe0
//   0x4dc0: a9087bfd  stp        x29, x30, [sp, #0x80]
//   0x4dc4: a9096ffc  stp        x28, x27, [sp, #0x90]
//   0x4dc8: a90a67fa  stp        x26, x25, [sp, #0xa0]
//   0x4dcc: a90b5ff8  stp        x24, x23, [sp, #0xb0]
//   0x4dd0: a90c57f6  stp        x22, x21, [sp, #0xc0]
//   0x4dd4: a90d4ff4  stp        x20, x19, [sp, #0xd0]
//   0x4dd8: 910203fd  add        x29, sp, #0x80
//   0x4ddc: d53bd048  mrs        x8, tpidr_el0
//   0x4de0: 52800209  mov        w9, #0x10
//   0x4de4: f90003e8  str        x8, [sp]
//   0x4de8: f100403f  cmp        x1, #0x10
//   0x4dec: aa0003f3  mov        x19, x0
//   0x4df0: f9401508  ldr        x8, [x8, #0x28]
//   0x4df4: 9a893037  csel       x23, x1, x9, lo
//   0x4df8: 910043e1  add        x1, sp, #0x10
//   0x4dfc: aa1f03e0  mov        x0, xzr
//   0x4e00: f81f83a8  stur       x8, [x29, #-8]
//   0x4e04: 9400101b  bl         #0x8e70
//   0x4e08: 35000060  cbnz       w0, #0x4e14
//   0x4e0c: 394063e8  ldrb       w8, [sp, #0x18]
//   0x4e10: 37000448  tbnz       w8, #0, #0x4e98
//   0x4e14: 2a1f03fa  mov        w26, wzr
//   0x4e18: aa1f03f8  mov        x24, xzr
//   0x4e1c: aa1f03f9  mov        x25, xzr
//   0x4e20: d503201f  nop        
//   0x4e24: 100644a0  adr        x0, #0x116b8
//   0x4e28: 94001006  bl         #0x8e40
//   0x4e2c: 94001015  bl         #0x8e80
//   0x4e30: 2a0003f4  mov        w20, w0
//   0x4e34: 94001017  bl         #0x8e90
//   0x4e38: 2a0003f5  mov        w21, w0
//   0x4e3c: 6b00029f  cmp        w20, w0
//   0x4e40: f90007ff  str        xzr, [sp, #8]
//   0x4e44: 540000c1  b.ne       #0x4e5c
//   0x4e48: b0000068  adrp       x8, #0x11000
//   0x4e4c: f943591b  ldr        x27, [x8, #0x6b0]
//   0x4e50: 360001fa  tbz        w26, #0, #0x4e8c
//   0x4e54: aa1f03fc  mov        x28, xzr
//   0x4e58: 14000025  b          #0x4eec
//   0x4e5c: 94000fd9  bl         #0x8dc0
//   0x4e60: 910103e1  add        x1, sp, #0x40
//   0x4e64: 9400100f  bl         #0x8ea0
//   0x4e68: 350000c0  cbnz       w0, #0x4e80
//   0x4e6c: 910103e0  add        x0, sp, #0x40
//   0x4e70: 9100e3e1  add        x1, sp, #0x38
//   0x4e74: 9100c3e2  add        x2, sp, #0x30
//   0x4e78: 9400100e  bl         #0x8eb0
//   0x4e7c: 34000180  cbz        w0, #0x4eac
//   0x4e80: aa1f03fc  mov        x28, xzr
//   0x4e84: aa1f03fb  mov        x27, xzr
//   0x4e88: 14000019  b          #0x4eec
//   0x4e8c: 910023fc  add        x28, sp, #8
//   0x4e90: f90007fc  str        x28, [sp, #8]
//   0x4e94: 14000016  b          #0x4eec
//   0x4e98: f9400bf8  ldr        x24, [sp, #0x10]
//   0x4e9c: 5280003a  mov        w26, #1
//   0x4ea0: f94013e8  ldr        x8, [sp, #0x20]
//   0x4ea4: 8b180119  add        x25, x8, x24
//   0x4ea8: 17ffffde  b          #0x4e20
//   0x4eac: a94323e9  ldp        x9, x8, [sp, #0x30]
//   0x4eb0: 910103e0  add        x0, sp, #0x40
//   0x4eb4: 9100a3e1  add        x1, sp, #0x28
//   0x4eb8: f90017ff  str        xzr, [sp, #0x28]
//   0x4ebc: 8b08013b  add        x27, x9, x8
//   0x4ec0: 94001000  bl         #0x8ec0
//   0x4ec4: 34000080  cbz        w0, #0x4ed4
//   0x4ec8: 52820008  mov        w8, #0x1000
//   0x4ecc: f90017e8  str        x8, [sp, #0x28]
//   0x4ed0: 14000002  b          #0x4ed8
//   0x4ed4: f94017e8  ldr        x8, [sp, #0x28]
//   0x4ed8: f9401fe9  ldr        x9, [sp, #0x38]
//   0x4edc: 910103e0  add        x0, sp, #0x40
//   0x4ee0: 8b08013c  add        x28, x9, x8
//   0x4ee4: f90007fc  str        x28, [sp, #8]
//   0x4ee8: 94000fae  bl         #0x8da0
//   0x4eec: 7100035f  cmp        w26, #0
//   0x4ef0: aa1f03ed  mov        x13, xzr
//   0x4ef4: aa1d03e8  mov        x8, x29
//   0x4ef8: 9a9c130b  csel       x11, x24, x28, ne
//   0x4efc: 9a9b132c  csel       x12, x25, x27, ne
//   0x4f00: b2585fe9  mov        x9, #-0x10000000000
//   0x4f04: b25863ea  mov        x10, #-0xffffffffff
//   0x4f08: aa0d03f6  mov        x22, x13
//   0x4f0c: eb1701bf  cmp        x13, x23
//   0x4f10: 540000c2  b.hs       #0x4f28
//   0x4f14: f1000adf  cmp        x22, #2
//   0x4f18: 54000083  b.lo       #0x4f28
//   0x4f1c: f940050d  ldr        x13, [x8, #8]
//   0x4f20: 8b160e6e  add        x14, x19, x22, lsl #3
//   0x4f24: f81f01cd  stur       x13, [x14, #-0x10]
//   0x4f28: 360000fa  tbz        w26, #0, #0x4f44
//   0x4f2c: 8b160e6d  add        x13, x19, x22, lsl #3
//   0x4f30: f85f01ad  ldur       x13, [x13, #-0x10]
//   0x4f34: eb1801bf  cmp        x13, x24
//   0x4f38: 54000303  b.lo       #0x4f98
//   0x4f3c: eb0d033f  cmp        x25, x13
//   0x4f40: 540002c9  b.ls       #0x4f98
//   0x4f44: 910006cd  add        x13, x22, #1
//   0x4f48: f10041bf  cmp        x13, #0x10
//   0x4f4c: 54000408  b.hi       #0x4fcc
//   0x4f50: f940010e  ldr        x14, [x8]
//   0x4f54: 8b0901cf  add        x15, x14, x9
//   0x4f58: eb0a01ff  cmp        x15, x10
//   0x4f5c: 54000383  b.lo       #0x4fcc
//   0x4f60: 926c4dcf  and        x15, x14, #0xfffff00000
//   0x4f64: b400034f  cbz        x15, #0x4fcc
//   0x4f68: ca1d01cf  eor        x15, x14, x29
//   0x4f6c: f2705dff  tst        x15, #0xffffff0000
//   0x4f70: 540002e1  b.ne       #0x4fcc
//   0x4f74: 91004108  add        x8, x8, #0x10
//   0x4f78: eb0801df  cmp        x14, x8
//   0x4f7c: 54000283  b.lo       #0x4fcc
//   0x4f80: 924009c8  and        x8, x14, #7
//   0x4f84: b5000248  cbnz       x8, #0x4fcc
//   0x4f88: aa0e03e8  mov        x8, x14
//   0x4f8c: eb0b011f  cmp        x8, x11
//   0x4f90: 540001a2  b.hs       #0x4fc4
//   0x4f94: 1400000e  b          #0x4fcc
//   0x4f98: 6b15029f  cmp        w20, w21
//   0x4f9c: 54000061  b.ne       #0x4fa8
//   0x4fa0: aa0d03fc  mov        x28, x13
//   0x4fa4: f90007ed  str        x13, [sp, #8]
//   0x4fa8: f9400108  ldr        x8, [x8]
//   0x4fac: 2a1f03fa  mov        w26, wzr
//   0x4fb0: 910006cd  add        x13, x22, #1
//   0x4fb4: aa1b03ec  mov        x12, x27
//   0x4fb8: aa1c03eb  mov        x11, x28
//   0x4fbc: eb0b011f  cmp        x8, x11
//   0x4fc0: 54000063  b.lo       #0x4fcc
//   0x4fc4: eb08019f  cmp        x12, x8
//   0x4fc8: 54fffa08  b.hi       #0x4f08
//   0x4fcc: d503201f  nop        
//   0x4fd0: 10063740  adr        x0, #0x116b8
//   0x4fd4: 94000fa3  bl         #0x8e60
//   0x4fd8: f94003e8  ldr        x8, [sp]
//   0x4fdc: f9401508  ldr        x8, [x8, #0x28]
//   0x4fe0: f85f83a9  ldur       x9, [x29, #-8]
//   0x4fe4: eb09011f  cmp        x8, x9
//   0x4fe8: 54000141  b.ne       #0x5010
//   0x4fec: d10006c0  sub        x0, x22, #1
//   0x4ff0: a94d4ff4  ldp        x20, x19, [sp, #0xd0]
//   0x4ff4: a94c57f6  ldp        x22, x21, [sp, #0xc0]
//   0x4ff8: a94b5ff8  ldp        x24, x23, [sp, #0xb0]
//   0x4ffc: a94a67fa  ldp        x26, x25, [sp, #0xa0]
//   0x5000: a9496ffc  ldp        x28, x27, [sp, #0x90]
//   0x5004: a9487bfd  ldp        x29, x30, [sp, #0x80]
//   0x5008: 910383ff  add        sp, sp, #0xe0
//   0x500c: d65f03c0  ret        
//   0x5010: 94000f68  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[20] XasanInitTlsKey_5014 (0x5014..0x5148, 308 bytes, 77 instructions)
// Summary / Tóm tắt: Creates pthread TLS key (0x116e0) for allocator recursion protection (@ 0x5014..0x5148)
// ----------------------------------------------------------------------------
//   0x5014: d10183ff  sub        sp, sp, #0x60
//   0x5018: a9047bfd  stp        x29, x30, [sp, #0x40]
//   0x501c: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x5020: 910103fd  add        x29, sp, #0x40
//   0x5024: aa0003f3  mov        x19, x0
//   0x5028: d503201f  nop        
//   0x502c: 100635a0  adr        x0, #0x116e0
//   0x5030: aa1f03e1  mov        x1, xzr
//   0x5034: 94000fa7  bl         #0x8ed0
//   0x5038: 34000140  cbz        w0, #0x5060
//   0x503c: 94000fa9  bl         #0x8ee0
//   0x5040: aa0003e3  mov        x3, x0
//   0x5044: d503201f  nop        
//   0x5048: 50fe86a1  adr        x1, #0x211e
//   0x504c: b0ffffe2  adrp       x2, #0x2000
//   0x5050: 91127442  add        x2, x2, #0x49d
//   0x5054: 528000c0  mov        w0, #6
//   0x5058: 94000ef2  bl         #0x8c20
//   0x505c: 14000005  b          #0x5070
//   0x5060: 90000068  adrp       x8, #0x11000
//   0x5064: aa1f03e1  mov        x1, xzr
//   0x5068: b946e100  ldr        w0, [x8, #0x6e0]
//   0x506c: 94000fa1  bl         #0x8ef0
//   0x5070: aa1f03e0  mov        x0, xzr
//   0x5074: 52801901  mov        w1, #0xc8
//   0x5078: 52800062  mov        w2, #3
//   0x507c: 52800443  mov        w3, #0x22
//   0x5080: 12800004  mov        w4, #-1
//   0x5084: aa1f03e5  mov        x5, xzr
//   0x5088: 94000ef6  bl         #0x8c60
//   0x508c: 90000074  adrp       x20, #0x11000
//   0x5090: f9037680  str        x0, [x20, #0x6e8]
//   0x5094: b40002c0  cbz        x0, #0x50ec
//   0x5098: aa1303e1  mov        x1, x19
//   0x509c: 94000c28  bl         #0x813c
//   0x50a0: 37f803a0  tbnz       w0, #0x1f, #0x5114
//   0x50a4: d503201f  nop        
//   0x50a8: 50fe83a1  adr        x1, #0x211e
//   0x50ac: b0ffffe2  adrp       x2, #0x2000
//   0x50b0: 9124cc42  add        x2, x2, #0x933
//   0x50b4: 528000c0  mov        w0, #6
//   0x50b8: 94000eda  bl         #0x8c20
//   0x50bc: ad400660  ldp        q0, q1, [x19]
//   0x50c0: 910003e1  mov        x1, sp
//   0x50c4: ad410e62  ldp        q2, q3, [x19, #0x20]
//   0x50c8: ad0007e0  stp        q0, q1, [sp]
//   0x50cc: f9437680  ldr        x0, [x20, #0x6e8]
//   0x50d0: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x50d4: 940001c3  bl         #0x57e0
//   0x50d8: b9402260  ldr        w0, [x19, #0x20]
//   0x50dc: 97fffb10  bl         #0x3d1c
//   0x50e0: 37f801e0  tbnz       w0, #0x1f, #0x511c
//   0x50e4: 2a1f03e0  mov        w0, wzr
//   0x50e8: 14000014  b          #0x5138
//   0x50ec: 94000ef9  bl         #0x8cd0
//   0x50f0: b9400003  ldr        w3, [x0]
//   0x50f4: d503201f  nop        
//   0x50f8: 50fe8121  adr        x1, #0x211e
//   0x50fc: b0ffffe2  adrp       x2, #0x2000
//   0x5100: 910c7842  add        x2, x2, #0x31e
//   0x5104: 528000c0  mov        w0, #6
//   0x5108: 94000ec6  bl         #0x8c20
//   0x510c: 12800020  mov        w0, #-2
//   0x5110: 1400000a  b          #0x5138
//   0x5114: 12800040  mov        w0, #-3
//   0x5118: 14000008  b          #0x5138
//   0x511c: d503201f  nop        
//   0x5120: 50fe7fe1  adr        x1, #0x211e
//   0x5124: 90ffffe2  adrp       x2, #0x1000
//   0x5128: 91322c42  add        x2, x2, #0xc8b
//   0x512c: 528000c0  mov        w0, #6
//   0x5130: 94000ebc  bl         #0x8c20
//   0x5134: 12800000  mov        w0, #-1
//   0x5138: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x513c: a9447bfd  ldp        x29, x30, [sp, #0x40]
//   0x5140: 910183ff  add        sp, sp, #0x60
//   0x5144: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[21] XasanHookCalloc_5148 (0x5148..0x5240, 248 bytes, 62 instructions)
// Summary / Tóm tắt: Bionic calloc interceptor with GuardedPoolAllocator sampling (@ 0x5148..0x5240)
// ----------------------------------------------------------------------------
//   0x5148: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x514c: f9000bf7  str        x23, [sp, #0x10]
//   0x5150: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x5154: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x5158: 910003fd  mov        x29, sp
//   0x515c: 90000076  adrp       x22, #0x11000
//   0x5160: aa0003f4  mov        x20, x0
//   0x5164: aa0103f3  mov        x19, x1
//   0x5168: b946e2c0  ldr        w0, [x22, #0x6e0]
//   0x516c: 94000f65  bl         #0x8f00
//   0x5170: b50001c0  cbnz       x0, #0x51a8
//   0x5174: b946e2c0  ldr        w0, [x22, #0x6e0]
//   0x5178: 52800021  mov        w1, #1
//   0x517c: 94000f5d  bl         #0x8ef0
//   0x5180: d503201f  nop        
//   0x5184: 10082f35  adr        x21, #0x15768
//   0x5188: b94002a8  ldr        w8, [x21]
//   0x518c: 34000248  cbz        w8, #0x51d4
//   0x5190: 71000508  subs       w8, w8, #1
//   0x5194: b90002a8  str        w8, [x21]
//   0x5198: 54000300  b.eq       #0x51f8
//   0x519c: b946e2c0  ldr        w0, [x22, #0x6e0]
//   0x51a0: aa1f03e1  mov        x1, xzr
//   0x51a4: 94000f53  bl         #0x8ef0
//   0x51a8: 90000048  adrp       x8, #0xd000
//   0x51ac: aa1403e0  mov        x0, x20
//   0x51b0: f9418508  ldr        x8, [x8, #0x308]
//   0x51b4: f9400108  ldr        x8, [x8]
//   0x51b8: f9400102  ldr        x2, [x8]
//   0x51bc: aa1303e1  mov        x1, x19
//   0x51c0: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x51c4: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x51c8: f9400bf7  ldr        x23, [sp, #0x10]
//   0x51cc: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x51d0: d61f0040  br         x2
//   0x51d4: 90000068  adrp       x8, #0x11000
//   0x51d8: f9437517  ldr        x23, [x8, #0x6e8]
//   0x51dc: 94000b77  bl         #0x7fb8
//   0x51e0: b940c2e8  ldr        w8, [x23, #0xc0]
//   0x51e4: 51000508  sub        w8, w8, #1
//   0x51e8: 1ac80809  udiv       w9, w0, w8
//   0x51ec: 1b088128  msub       w8, w9, w8, w0
//   0x51f0: 11000508  add        w8, w8, #1
//   0x51f4: 17ffffe7  b          #0x5190
//   0x51f8: 9bd37e88  umulh      x8, x20, x19
//   0x51fc: eb0803ff  cmp        xzr, x8
//   0x5200: 54fffce1  b.ne       #0x519c
//   0x5204: 90000068  adrp       x8, #0x11000
//   0x5208: 9b137e81  mul        x1, x20, x19
//   0x520c: f9437500  ldr        x0, [x8, #0x6e8]
//   0x5210: 94000c7c  bl         #0x8400
//   0x5214: b4fffc40  cbz        x0, #0x519c
//   0x5218: aa0003f5  mov        x21, x0
//   0x521c: b946e2c0  ldr        w0, [x22, #0x6e0]
//   0x5220: aa1f03e1  mov        x1, xzr
//   0x5224: 94000f33  bl         #0x8ef0
//   0x5228: aa1503e0  mov        x0, x21
//   0x522c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x5230: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x5234: f9400bf7  ldr        x23, [sp, #0x10]
//   0x5238: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x523c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[22] XasanHookMalloc_5240 (0x5240..0x5318, 216 bytes, 54 instructions)
// Summary / Tóm tắt: Bionic malloc interceptor with GuardedPoolAllocator sampling (@ 0x5240..0x5318)
// ----------------------------------------------------------------------------
//   0x5240: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x5244: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x5248: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x524c: 910003fd  mov        x29, sp
//   0x5250: 90000075  adrp       x21, #0x11000
//   0x5254: aa0003f3  mov        x19, x0
//   0x5258: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x525c: 94000f29  bl         #0x8f00
//   0x5260: b50001c0  cbnz       x0, #0x5298
//   0x5264: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x5268: 52800021  mov        w1, #1
//   0x526c: 94000f21  bl         #0x8ef0
//   0x5270: d503201f  nop        
//   0x5274: 100827b4  adr        x20, #0x15768
//   0x5278: b9400288  ldr        w8, [x20]
//   0x527c: 34000208  cbz        w8, #0x52bc
//   0x5280: 71000508  subs       w8, w8, #1
//   0x5284: b9000288  str        w8, [x20]
//   0x5288: 540002c0  b.eq       #0x52e0
//   0x528c: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x5290: aa1f03e1  mov        x1, xzr
//   0x5294: 94000f17  bl         #0x8ef0
//   0x5298: d503201f  nop        
//   0x529c: 10061ce8  adr        x8, #0x11638
//   0x52a0: f9400108  ldr        x8, [x8]
//   0x52a4: f9400d01  ldr        x1, [x8, #0x18]
//   0x52a8: aa1303e0  mov        x0, x19
//   0x52ac: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x52b0: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x52b4: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x52b8: d61f0020  br         x1
//   0x52bc: 90000068  adrp       x8, #0x11000
//   0x52c0: f9437516  ldr        x22, [x8, #0x6e8]
//   0x52c4: 94000b3d  bl         #0x7fb8
//   0x52c8: b940c2c8  ldr        w8, [x22, #0xc0]
//   0x52cc: 51000508  sub        w8, w8, #1
//   0x52d0: 1ac80809  udiv       w9, w0, w8
//   0x52d4: 1b088128  msub       w8, w9, w8, w0
//   0x52d8: 11000508  add        w8, w8, #1
//   0x52dc: 17ffffe9  b          #0x5280
//   0x52e0: 90000068  adrp       x8, #0x11000
//   0x52e4: aa1303e1  mov        x1, x19
//   0x52e8: f9437500  ldr        x0, [x8, #0x6e8]
//   0x52ec: 94000c45  bl         #0x8400
//   0x52f0: b4fffce0  cbz        x0, #0x528c
//   0x52f4: aa0003f4  mov        x20, x0
//   0x52f8: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x52fc: aa1f03e1  mov        x1, xzr
//   0x5300: 94000efc  bl         #0x8ef0
//   0x5304: aa1403e0  mov        x0, x20
//   0x5308: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x530c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x5310: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x5314: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[23] XasanHookRealloc_5318 (0x5318..0x5408, 240 bytes, 60 instructions)
// Summary / Tóm tắt: Bionic realloc interceptor with GuardedPoolAllocator check (@ 0x5318..0x5408)
// ----------------------------------------------------------------------------
//   0x5318: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x531c: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x5320: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x5324: 910003fd  mov        x29, sp
//   0x5328: 90000075  adrp       x21, #0x11000
//   0x532c: aa0003f3  mov        x19, x0
//   0x5330: aa0103f4  mov        x20, x1
//   0x5334: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x5338: 94000ef2  bl         #0x8f00
//   0x533c: b50001e0  cbnz       x0, #0x5378
//   0x5340: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x5344: 52800021  mov        w1, #1
//   0x5348: 94000eea  bl         #0x8ef0
//   0x534c: b4000113  cbz        x19, #0x536c
//   0x5350: 90000076  adrp       x22, #0x11000
//   0x5354: f94376c0  ldr        x0, [x22, #0x6e8]
//   0x5358: f9400008  ldr        x8, [x0]
//   0x535c: b4000088  cbz        x8, #0x536c
//   0x5360: aa1303e1  mov        x1, x19
//   0x5364: d63f0100  blr        x8
//   0x5368: 350001c0  cbnz       w0, #0x53a0
//   0x536c: b946e2a0  ldr        w0, [x21, #0x6e0]
//   0x5370: aa1f03e1  mov        x1, xzr
//   0x5374: 94000edf  bl         #0x8ef0
//   0x5378: 90000048  adrp       x8, #0xd000
//   0x537c: aa1303e0  mov        x0, x19
//   0x5380: f9418508  ldr        x8, [x8, #0x308]
//   0x5384: f9400108  ldr        x8, [x8]
//   0x5388: f9401d02  ldr        x2, [x8, #0x38]
//   0x538c: aa1403e1  mov        x1, x20
//   0x5390: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x5394: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x5398: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x539c: d61f0040  br         x2
//   0x53a0: f94376c0  ldr        x0, [x22, #0x6e8]
//   0x53a4: aa1303e1  mov        x1, x19
//   0x53a8: 94000d6b  bl         #0x8954
//   0x53ac: aa0003f6  mov        x22, x0
//   0x53b0: aa1403e0  mov        x0, x20
//   0x53b4: 97ffffa3  bl         #0x5240
//   0x53b8: aa0003f5  mov        x21, x0
//   0x53bc: b40000c0  cbz        x0, #0x53d4
//   0x53c0: eb1402df  cmp        x22, x20
//   0x53c4: aa1503e0  mov        x0, x21
//   0x53c8: 9a9432c2  csel       x2, x22, x20, lo
//   0x53cc: aa1303e1  mov        x1, x19
//   0x53d0: 94000ed0  bl         #0x8f10
//   0x53d4: 90000068  adrp       x8, #0x11000
//   0x53d8: aa1303e1  mov        x1, x19
//   0x53dc: f9437500  ldr        x0, [x8, #0x6e8]
//   0x53e0: 94000ce0  bl         #0x8760
//   0x53e4: 90000068  adrp       x8, #0x11000
//   0x53e8: aa1f03e1  mov        x1, xzr
//   0x53ec: b946e100  ldr        w0, [x8, #0x6e0]
//   0x53f0: 94000ec0  bl         #0x8ef0
//   0x53f4: aa1503e0  mov        x0, x21
//   0x53f8: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x53fc: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x5400: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x5404: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[24] XasanHookFree_5408 (0x5408..0x54ac, 164 bytes, 41 instructions)
// Summary / Tóm tắt: Bionic free interceptor with GuardedPoolAllocator deallocate (@ 0x5408..0x54ac)
// ----------------------------------------------------------------------------
//   0x5408: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x540c: f9000bf5  str        x21, [sp, #0x10]
//   0x5410: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x5414: 910003fd  mov        x29, sp
//   0x5418: 90000074  adrp       x20, #0x11000
//   0x541c: aa0003f3  mov        x19, x0
//   0x5420: b946e280  ldr        w0, [x20, #0x6e0]
//   0x5424: 94000eb7  bl         #0x8f00
//   0x5428: b50001e0  cbnz       x0, #0x5464
//   0x542c: b946e280  ldr        w0, [x20, #0x6e0]
//   0x5430: 52800021  mov        w1, #1
//   0x5434: 94000eaf  bl         #0x8ef0
//   0x5438: b4000113  cbz        x19, #0x5458
//   0x543c: 90000075  adrp       x21, #0x11000
//   0x5440: f94376a0  ldr        x0, [x21, #0x6e8]
//   0x5444: f9400008  ldr        x8, [x0]
//   0x5448: b4000088  cbz        x8, #0x5458
//   0x544c: aa1303e1  mov        x1, x19
//   0x5450: d63f0100  blr        x8
//   0x5454: 350001a0  cbnz       w0, #0x5488
//   0x5458: b946e280  ldr        w0, [x20, #0x6e0]
//   0x545c: aa1f03e1  mov        x1, xzr
//   0x5460: 94000ea4  bl         #0x8ef0
//   0x5464: d503201f  nop        
//   0x5468: 10060e88  adr        x8, #0x11638
//   0x546c: f9400108  ldr        x8, [x8]
//   0x5470: f9401101  ldr        x1, [x8, #0x20]
//   0x5474: aa1303e0  mov        x0, x19
//   0x5478: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x547c: f9400bf5  ldr        x21, [sp, #0x10]
//   0x5480: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x5484: d61f0020  br         x1
//   0x5488: b946e280  ldr        w0, [x20, #0x6e0]
//   0x548c: aa1f03e1  mov        x1, xzr
//   0x5490: 94000e98  bl         #0x8ef0
//   0x5494: f94376a0  ldr        x0, [x21, #0x6e8]
//   0x5498: aa1303e1  mov        x1, x19
//   0x549c: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x54a0: f9400bf5  ldr        x21, [sp, #0x10]
//   0x54a4: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x54a8: 14000d2b  b          #0x8954

// ----------------------------------------------------------------------------
// FDE[25] XasanHookUsableSize_54ac (0x54ac..0x5568, 188 bytes, 47 instructions)
// Summary / Tóm tắt: Bionic malloc_usable_size interceptor (@ 0x54ac..0x5568)
// ----------------------------------------------------------------------------
//   0x54ac: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x54b0: f9000bf5  str        x21, [sp, #0x10]
//   0x54b4: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x54b8: 910003fd  mov        x29, sp
//   0x54bc: 90000074  adrp       x20, #0x11000
//   0x54c0: aa0003f3  mov        x19, x0
//   0x54c4: b946e280  ldr        w0, [x20, #0x6e0]
//   0x54c8: 94000e8e  bl         #0x8f00
//   0x54cc: b4000160  cbz        x0, #0x54f8
//   0x54d0: b4000333  cbz        x19, #0x5534
//   0x54d4: d503201f  nop        
//   0x54d8: 10060b08  adr        x8, #0x11638
//   0x54dc: f9400108  ldr        x8, [x8]
//   0x54e0: f9400501  ldr        x1, [x8, #8]
//   0x54e4: aa1303e0  mov        x0, x19
//   0x54e8: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x54ec: f9400bf5  ldr        x21, [sp, #0x10]
//   0x54f0: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x54f4: d61f0020  br         x1
//   0x54f8: b946e280  ldr        w0, [x20, #0x6e0]
//   0x54fc: 52800021  mov        w1, #1
//   0x5500: 94000e7c  bl         #0x8ef0
//   0x5504: b4000113  cbz        x19, #0x5524
//   0x5508: 90000075  adrp       x21, #0x11000
//   0x550c: f94376a0  ldr        x0, [x21, #0x6e8]
//   0x5510: f9400008  ldr        x8, [x0]
//   0x5514: b4000088  cbz        x8, #0x5524
//   0x5518: aa1303e1  mov        x1, x19
//   0x551c: d63f0100  blr        x8
//   0x5520: 35000120  cbnz       w0, #0x5544
//   0x5524: b946e280  ldr        w0, [x20, #0x6e0]
//   0x5528: aa1f03e1  mov        x1, xzr
//   0x552c: 94000e71  bl         #0x8ef0
//   0x5530: b5fffd33  cbnz       x19, #0x54d4
//   0x5534: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x5538: f9400bf5  ldr        x21, [sp, #0x10]
//   0x553c: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x5540: d65f03c0  ret        
//   0x5544: f94376a0  ldr        x0, [x21, #0x6e8]
//   0x5548: aa1303e1  mov        x1, x19
//   0x554c: 94000c85  bl         #0x8760
//   0x5550: b946e280  ldr        w0, [x20, #0x6e0]
//   0x5554: aa1f03e1  mov        x1, xzr
//   0x5558: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x555c: f9400bf5  ldr        x21, [sp, #0x10]
//   0x5560: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x5564: 14000e63  b          #0x8ef0

// ----------------------------------------------------------------------------
// FDE[26] XasanFde_5568 (0x5568..0x5600, 152 bytes, 38 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x5568..0x5600
// ----------------------------------------------------------------------------
//   0x5568: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x556c: 910003fd  mov        x29, sp
//   0x5570: 90000048  adrp       x8, #0xd000
//   0x5574: 9000004a  adrp       x10, #0xd000
//   0x5578: f9418908  ldr        x8, [x8, #0x310]
//   0x557c: f941854a  ldr        x10, [x10, #0x308]
//   0x5580: f9400109  ldr        x9, [x8]
//   0x5584: f940014a  ldr        x10, [x10]
//   0x5588: f100013f  cmp        x9, #0
//   0x558c: fa401944  ccmp       x10, #0, #4, ne
//   0x5590: 54000141  b.ne       #0x55b8
//   0x5594: d503201f  nop        
//   0x5598: 50fe5c21  adr        x1, #0x211e
//   0x559c: b0ffffe2  adrp       x2, #0x2000
//   0x55a0: 911d9442  add        x2, x2, #0x765
//   0x55a4: 528000c0  mov        w0, #6
//   0x55a8: 94000d9e  bl         #0x8c20
//   0x55ac: 12800000  mov        w0, #-1
//   0x55b0: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x55b4: d65f03c0  ret        
//   0x55b8: d503201f  nop        
//   0x55bc: 10fff78a  adr        x10, #0x54ac
//   0x55c0: d503201f  nop        
//   0x55c4: 10ffdc2d  adr        x13, #0x5148
//   0x55c8: d503201f  nop        
//   0x55cc: 10ffea6b  adr        x11, #0x5318
//   0x55d0: d503201f  nop        
//   0x55d4: 10ffe36c  adr        x12, #0x5240
//   0x55d8: a900292d  stp        x13, x10, [x9]
//   0x55dc: 2a1f03e0  mov        w0, wzr
//   0x55e0: f9001d2b  str        x11, [x9, #0x38]
//   0x55e4: f9400108  ldr        x8, [x8]
//   0x55e8: f9000d2c  str        x12, [x9, #0x18]
//   0x55ec: d503201f  nop        
//   0x55f0: 10fff0c9  adr        x9, #0x5408
//   0x55f4: f9001109  str        x9, [x8, #0x20]
//   0x55f8: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x55fc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[27] XasanFde_5600 (0x5600..0x57e0, 480 bytes, 120 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x5600..0x57e0
// ----------------------------------------------------------------------------
//   0x5600: d10503ff  sub        sp, sp, #0x140
//   0x5604: a9117bfd  stp        x29, x30, [sp, #0x110]
//   0x5608: a91257fc  stp        x28, x21, [sp, #0x120]
//   0x560c: a9134ff4  stp        x20, x19, [sp, #0x130]
//   0x5610: 910443fd  add        x29, sp, #0x110
//   0x5614: d53bd053  mrs        x19, tpidr_el0
//   0x5618: 90000074  adrp       x20, #0x11000
//   0x561c: f9401668  ldr        x8, [x19, #0x28]
//   0x5620: 52803801  mov        w1, #0x1c0
//   0x5624: f81f83a8  stur       x8, [x29, #-8]
//   0x5628: f9439280  ldr        x0, [x20, #0x720]
//   0x562c: 94000e3d  bl         #0x8f20
//   0x5630: 340000a0  cbz        w0, #0x5644
//   0x5634: 94000da7  bl         #0x8cd0
//   0x5638: b9400008  ldr        w8, [x0]
//   0x563c: 7100451f  cmp        w8, #0x11
//   0x5640: 540007a1  b.ne       #0x5734
//   0x5644: f9439284  ldr        x4, [x20, #0x720]
//   0x5648: 90000075  adrp       x21, #0x11000
//   0x564c: b40001e4  cbz        x4, #0x5688
//   0x5650: b0ffffe3  adrp       x3, #0x2000
//   0x5654: 91053463  add        x3, x3, #0x14d
//   0x5658: 90ffffe5  adrp       x5, #0x1000
//   0x565c: 913d8ca5  add        x5, x5, #0xf63
//   0x5660: 910023e0  add        x0, sp, #8
//   0x5664: 52802001  mov        w1, #0x100
//   0x5668: 52802002  mov        w2, #0x100
//   0x566c: 94000209  bl         #0x5e90
//   0x5670: 910023e0  add        x0, sp, #8
//   0x5674: 52800841  mov        w1, #0x42
//   0x5678: 52803002  mov        w2, #0x180
//   0x567c: 94000e2d  bl         #0x8f30
//   0x5680: b90616a0  str        w0, [x21, #0x614]
//   0x5684: 36f80160  tbz        w0, #0x1f, #0x56b0
//   0x5688: 52800048  mov        w8, #2
//   0x568c: b90616a8  str        w8, [x21, #0x614]
//   0x5690: 94000d90  bl         #0x8cd0
//   0x5694: b9400003  ldr        w3, [x0]
//   0x5698: d503201f  nop        
//   0x569c: 50fe5401  adr        x1, #0x211e
//   0x56a0: b0ffffe2  adrp       x2, #0x2000
//   0x56a4: 91158042  add        x2, x2, #0x560
//   0x56a8: 528000c0  mov        w0, #6
//   0x56ac: 94000d5d  bl         #0x8c20
//   0x56b0: f9439284  ldr        x4, [x20, #0x720]
//   0x56b4: 90000075  adrp       x21, #0x11000
//   0x56b8: b40005c4  cbz        x4, #0x5770
//   0x56bc: b0ffffe3  adrp       x3, #0x2000
//   0x56c0: 91053463  add        x3, x3, #0x14d
//   0x56c4: b0ffffe5  adrp       x5, #0x2000
//   0x56c8: 91054ca5  add        x5, x5, #0x153
//   0x56cc: 910023e0  add        x0, sp, #8
//   0x56d0: 52802001  mov        w1, #0x100
//   0x56d4: 52802002  mov        w2, #0x100
//   0x56d8: 940001ee  bl         #0x5e90
//   0x56dc: 910023e0  add        x0, sp, #8
//   0x56e0: 52800841  mov        w1, #0x42
//   0x56e4: 52803002  mov        w2, #0x180
//   0x56e8: 94000e12  bl         #0x8f30
//   0x56ec: f9439284  ldr        x4, [x20, #0x720]
//   0x56f0: b9061aa0  str        w0, [x21, #0x618]
//   0x56f4: b4000464  cbz        x4, #0x5780
//   0x56f8: b0ffffe3  adrp       x3, #0x2000
//   0x56fc: 91053463  add        x3, x3, #0x14d
//   0x5700: b0ffffe5  adrp       x5, #0x2000
//   0x5704: 910cb4a5  add        x5, x5, #0x32d
//   0x5708: 910023e0  add        x0, sp, #8
//   0x570c: 52802001  mov        w1, #0x100
//   0x5710: 52802002  mov        w2, #0x100
//   0x5714: 940001df  bl         #0x5e90
//   0x5718: 910023e0  add        x0, sp, #8
//   0x571c: 52800841  mov        w1, #0x42
//   0x5720: 52803002  mov        w2, #0x180
//   0x5724: 94000e03  bl         #0x8f30
//   0x5728: 2a0003e8  mov        w8, w0
//   0x572c: b9461aa0  ldr        w0, [x21, #0x618]
//   0x5730: 14000015  b          #0x5784
//   0x5734: f9439283  ldr        x3, [x20, #0x720]
//   0x5738: f9401668  ldr        x8, [x19, #0x28]
//   0x573c: f85f83a9  ldur       x9, [x29, #-8]
//   0x5740: eb09011f  cmp        x8, x9
//   0x5744: 540004c1  b.ne       #0x57dc
//   0x5748: d503201f  nop        
//   0x574c: 50fe4e81  adr        x1, #0x211e
//   0x5750: 90ffffe2  adrp       x2, #0x1000
//   0x5754: 9133f042  add        x2, x2, #0xcfc
//   0x5758: 528000c0  mov        w0, #6
//   0x575c: a9534ff4  ldp        x20, x19, [sp, #0x130]
//   0x5760: a95257fc  ldp        x28, x21, [sp, #0x120]
//   0x5764: a9517bfd  ldp        x29, x30, [sp, #0x110]
//   0x5768: 910503ff  add        sp, sp, #0x140
//   0x576c: 14000d2d  b          #0x8c20
//   0x5770: 90000068  adrp       x8, #0x11000
//   0x5774: 12800009  mov        w9, #-1
//   0x5778: b9061d09  str        w9, [x8, #0x61c]
//   0x577c: 14000005  b          #0x5790
//   0x5780: 12800008  mov        w8, #-1
//   0x5784: 90000069  adrp       x9, #0x11000
//   0x5788: b9061d28  str        w8, [x9, #0x61c]
//   0x578c: 36f80160  tbz        w0, #0x1f, #0x57b8
//   0x5790: 52800048  mov        w8, #2
//   0x5794: b9061aa8  str        w8, [x21, #0x618]
//   0x5798: 94000d4e  bl         #0x8cd0
//   0x579c: b9400003  ldr        w3, [x0]
//   0x57a0: d503201f  nop        
//   0x57a4: 50fe4bc1  adr        x1, #0x211e
//   0x57a8: b0ffffe2  adrp       x2, #0x2000
//   0x57ac: 911e1042  add        x2, x2, #0x784
//   0x57b0: 528000c0  mov        w0, #6
//   0x57b4: 94000d1b  bl         #0x8c20
//   0x57b8: f9401668  ldr        x8, [x19, #0x28]
//   0x57bc: f85f83a9  ldur       x9, [x29, #-8]
//   0x57c0: eb09011f  cmp        x8, x9
//   0x57c4: 540000c1  b.ne       #0x57dc
//   0x57c8: a9534ff4  ldp        x20, x19, [sp, #0x130]
//   0x57cc: a95257fc  ldp        x28, x21, [sp, #0x120]
//   0x57d0: a9517bfd  ldp        x29, x30, [sp, #0x110]
//   0x57d4: 910503ff  add        sp, sp, #0x140
//   0x57d8: d65f03c0  ret        
//   0x57dc: 94000d75  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[28] XasanSetupSignalAltStack_57e0 (0x57e0..0x5904, 292 bytes, 73 instructions)
// Summary / Tóm tắt: Maps 128 KB (0x20000) alternate signal stack ('XASan signal stack') (@ 0x57e0..0x5904)
// ----------------------------------------------------------------------------
//   0x57e0: d10183ff  sub        sp, sp, #0x60
//   0x57e4: a9047bfd  stp        x29, x30, [sp, #0x40]
//   0x57e8: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x57ec: 910103fd  add        x29, sp, #0x40
//   0x57f0: 90000068  adrp       x8, #0x11000
//   0x57f4: 90000069  adrp       x9, #0x11000
//   0x57f8: a942a82c  ldp        x12, x10, [x1, #0x28]
//   0x57fc: 9000006b  adrp       x11, #0x11000
//   0x5800: 52a00041  mov        w1, #0x20000
//   0x5804: f9038d00  str        x0, [x8, #0x718]
//   0x5808: aa1f03e0  mov        x0, xzr
//   0x580c: 52800062  mov        w2, #3
//   0x5810: 52800443  mov        w3, #0x22
//   0x5814: 12800004  mov        w4, #-1
//   0x5818: aa1f03e5  mov        x5, xzr
//   0x581c: 52800094  mov        w20, #4
//   0x5820: f903952a  str        x10, [x9, #0x728]
//   0x5824: 72a10014  movk       w20, #0x800, lsl #16
//   0x5828: f903916c  str        x12, [x11, #0x720]
//   0x582c: 94000d0d  bl         #0x8c60
//   0x5830: b100041f  cmn        x0, #1
//   0x5834: 54000160  b.eq       #0x5860
//   0x5838: aa0003f3  mov        x19, x0
//   0x583c: 5289a820  mov        w0, #0x4d41
//   0x5840: b0ffffe4  adrp       x4, #0x2000
//   0x5844: 91058484  add        x4, x4, #0x161
//   0x5848: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x584c: 2a1f03e1  mov        w1, wzr
//   0x5850: aa1303e2  mov        x2, x19
//   0x5854: 52a00043  mov        w3, #0x20000
//   0x5858: 94000dba  bl         #0x8f40
//   0x585c: 14000008  b          #0x587c
//   0x5860: 52800020  mov        w0, #1
//   0x5864: 52a00041  mov        w1, #0x20000
//   0x5868: 94000d2a  bl         #0x8d10
//   0x586c: 52800088  mov        w8, #4
//   0x5870: f100001f  cmp        x0, #0
//   0x5874: aa0003f3  mov        x19, x0
//   0x5878: 1a940114  csel       w20, w8, w20, eq
//   0x587c: 52a00048  mov        w8, #0x20000
//   0x5880: f81e83b3  stur       x19, [x29, #-0x18]
//   0x5884: b81f03bf  stur       wzr, [x29, #-0x10]
//   0x5888: f81f83a8  stur       x8, [x29, #-8]
//   0x588c: b5000193  cbnz       x19, #0x58bc
//   0x5890: d10063a0  sub        x0, x29, #0x18
//   0x5894: aa1f03e1  mov        x1, xzr
//   0x5898: 94000d76  bl         #0x8e70
//   0x589c: 3100041f  cmn        w0, #1
//   0x58a0: 540000e1  b.ne       #0x58bc
//   0x58a4: d503201f  nop        
//   0x58a8: 50fe43a1  adr        x1, #0x211e
//   0x58ac: b0ffffe2  adrp       x2, #0x2000
//   0x58b0: 9105d042  add        x2, x2, #0x174
//   0x58b4: 528000c0  mov        w0, #6
//   0x58b8: 94000cda  bl         #0x8c20
//   0x58bc: 6f00e400  movi       v0.2d, #0000000000000000
//   0x58c0: d503201f  nop        
//   0x58c4: 10000208  adr        x8, #0x5904
//   0x58c8: d503201f  nop        
//   0x58cc: 1005f122  adr        x2, #0x116f0
//   0x58d0: 910003e1  mov        x1, sp
//   0x58d4: 52800160  mov        w0, #0xb
//   0x58d8: ad0003e0  stp        q0, q0, [sp]
//   0x58dc: f90007e8  str        x8, [sp, #8]
//   0x58e0: b90003f4  str        w20, [sp]
//   0x58e4: 94000d9b  bl         #0x8f50
//   0x58e8: 90000068  adrp       x8, #0x11000
//   0x58ec: 52800029  mov        w9, #1
//   0x58f0: 391c4109  strb       w9, [x8, #0x710]
//   0x58f4: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x58f8: a9447bfd  ldp        x29, x30, [sp, #0x40]
//   0x58fc: 910183ff  add        sp, sp, #0x60
//   0x5900: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[29] XasanSigsegvHandler_5904 (0x5904..0x5e90, 1420 bytes, 355 instructions)
// Summary / Tóm tắt: SIGSEGV fault handler inspecting faulting address against GuardedPagePool (@ 0x5904..0x5e90)
// ----------------------------------------------------------------------------
//   0x5904: d10703ff  sub        sp, sp, #0x1c0
//   0x5908: a9167bfd  stp        x29, x30, [sp, #0x160]
//   0x590c: a9176ffc  stp        x28, x27, [sp, #0x170]
//   0x5910: a91867fa  stp        x26, x25, [sp, #0x180]
//   0x5914: a9195ff8  stp        x24, x23, [sp, #0x190]
//   0x5918: a91a57f6  stp        x22, x21, [sp, #0x1a0]
//   0x591c: a91b4ff4  stp        x20, x19, [sp, #0x1b0]
//   0x5920: 910583fd  add        x29, sp, #0x160
//   0x5924: d53bd054  mrs        x20, tpidr_el0
//   0x5928: aa0203f7  mov        x23, x2
//   0x592c: f9401688  ldr        x8, [x20, #0x28]
//   0x5930: b9000fe0  str        w0, [sp, #0xc]
//   0x5934: d503201f  nop        
//   0x5938: 1005efc0  adr        x0, #0x11730
//   0x593c: aa0103f6  mov        x22, x1
//   0x5940: f81f03a8  stur       x8, [x29, #-0x10]
//   0x5944: 94000d3f  bl         #0x8e40
//   0x5948: 94000d52  bl         #0x8e90
//   0x594c: 2a0003f3  mov        w19, w0
//   0x5950: 2a1f03e0  mov        w0, wzr
//   0x5954: 2a1303e1  mov        w1, w19
//   0x5958: 94000d82  bl         #0x8f60
//   0x595c: 90000075  adrp       x21, #0x11000
//   0x5960: 2a0003f8  mov        w24, w0
//   0x5964: b94622a8  ldr        w8, [x21, #0x620]
//   0x5968: 3100051f  cmn        w8, #1
//   0x596c: 54000080  b.eq       #0x597c
//   0x5970: 2a0803e0  mov        w0, w8
//   0x5974: 94000d63  bl         #0x8f00
//   0x5978: 14000002  b          #0x5980
//   0x597c: aa1f03e0  mov        x0, xzr
//   0x5980: 9000007a  adrp       x26, #0x11000
//   0x5984: 90000079  adrp       x25, #0x11000
//   0x5988: 9000007c  adrp       x28, #0x11000
//   0x598c: 9000007b  adrp       x27, #0x11000
//   0x5990: eb16001f  cmp        x0, x22
//   0x5994: 54001f40  b.eq       #0x5d7c
//   0x5998: b94622a0  ldr        w0, [x21, #0x620]
//   0x599c: 3100041f  cmn        w0, #1
//   0x59a0: 54000121  b.ne       #0x59c4
//   0x59a4: 2a1803f5  mov        w21, w24
//   0x59a8: d503201f  nop        
//   0x59ac: 1005e3b8  adr        x24, #0x11620
//   0x59b0: aa1f03e1  mov        x1, xzr
//   0x59b4: aa1803e0  mov        x0, x24
//   0x59b8: 94000d46  bl         #0x8ed0
//   0x59bc: b9400300  ldr        w0, [x24]
//   0x59c0: 2a1503f8  mov        w24, w21
//   0x59c4: aa1603e1  mov        x1, x22
//   0x59c8: 94000d4a  bl         #0x8ef0
//   0x59cc: 90000075  adrp       x21, #0x11000
//   0x59d0: f9438ea8  ldr        x8, [x21, #0x718]
//   0x59d4: b4001808  cbz        x8, #0x5cd4
//   0x59d8: 97ffff0a  bl         #0x5600
//   0x59dc: f9438ea0  ldr        x0, [x21, #0x718]
//   0x59e0: f9400ac1  ldr        x1, [x22, #0x10]
//   0x59e4: 94000870  bl         #0x7ba4
//   0x59e8: 7100041f  cmp        w0, #1
//   0x59ec: 540006cb  b.lt       #0x5ac4
//   0x59f0: f9438ea0  ldr        x0, [x21, #0x718]
//   0x59f4: b9000bf8  str        w24, [sp, #8]
//   0x59f8: 94000b53  bl         #0x8744
//   0x59fc: 370000a0  tbnz       w0, #0, #0x5a10
//   0x5a00: b9461740  ldr        w0, [x26, #0x614]
//   0x5a04: b0ffffe1  adrp       x1, #0x2000
//   0x5a08: 911ebc21  add        x1, x1, #0x7af
//   0x5a0c: 940007a6  bl         #0x78a4
//   0x5a10: 2a1f03e0  mov        w0, wzr
//   0x5a14: 2a1303e1  mov        w1, w19
//   0x5a18: 12800262  mov        w2, #-0x14
//   0x5a1c: 94000d55  bl         #0x8f70
//   0x5a20: d503201f  nop        
//   0x5a24: 50fe37c1  adr        x1, #0x211e
//   0x5a28: 90ffffe2  adrp       x2, #0x1000
//   0x5a2c: 91328042  add        x2, x2, #0xca0
//   0x5a30: 528000c0  mov        w0, #6
//   0x5a34: 94000c7b  bl         #0x8c20
//   0x5a38: f9400ad5  ldr        x21, [x22, #0x10]
//   0x5a3c: 94000c85  bl         #0x8c50
//   0x5a40: 90000068  adrp       x8, #0x11000
//   0x5a44: aa1f03e9  mov        x9, xzr
//   0x5a48: cb20c129  sub        x9, x9, w0, sxtw
//   0x5a4c: 8a150138  and        x24, x9, x21
//   0x5a50: f9438d08  ldr        x8, [x8, #0x718]
//   0x5a54: aa0803e0  mov        x0, x8
//   0x5a58: 9400091d  bl         #0x7ecc
//   0x5a5c: aa0003f9  mov        x25, x0
//   0x5a60: b9461740  ldr        w0, [x26, #0x614]
//   0x5a64: f9400ac4  ldr        x4, [x22, #0x10]
//   0x5a68: 90ffffe1  adrp       x1, #0x1000
//   0x5a6c: 91399421  add        x1, x1, #0xe65
//   0x5a70: aa1803e2  mov        x2, x24
//   0x5a74: aa1903e3  mov        x3, x25
//   0x5a78: 9400078b  bl         #0x78a4
//   0x5a7c: aa1803e0  mov        x0, x24
//   0x5a80: aa1903e1  mov        x1, x25
//   0x5a84: 52800062  mov        w2, #3
//   0x5a88: 94000c86  bl         #0x8ca0
//   0x5a8c: 34000260  cbz        w0, #0x5ad8
//   0x5a90: 5289a820  mov        w0, #0x4d41
//   0x5a94: b0ffffe4  adrp       x4, #0x2000
//   0x5a98: 91185884  add        x4, x4, #0x616
//   0x5a9c: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x5aa0: 2a1f03e1  mov        w1, wzr
//   0x5aa4: aa1803e2  mov        x2, x24
//   0x5aa8: aa1903e3  mov        x3, x25
//   0x5aac: 94000d25  bl         #0x8f40
//   0x5ab0: b9461740  ldr        w0, [x26, #0x614]
//   0x5ab4: b0ffffe1  adrp       x1, #0x2000
//   0x5ab8: 9108d821  add        x1, x1, #0x236
//   0x5abc: 9400077a  bl         #0x78a4
//   0x5ac0: 14000030  b          #0x5b80
//   0x5ac4: b9461740  ldr        w0, [x26, #0x614]
//   0x5ac8: b0ffffe1  adrp       x1, #0x2000
//   0x5acc: 9118bc21  add        x1, x1, #0x62f
//   0x5ad0: 94000775  bl         #0x78a4
//   0x5ad4: 140000aa  b          #0x5d7c
//   0x5ad8: b946175b  ldr        w27, [x26, #0x614]
//   0x5adc: 94000c7d  bl         #0x8cd0
//   0x5ae0: b940001c  ldr        w28, [x0]
//   0x5ae4: aa0003f5  mov        x21, x0
//   0x5ae8: 2a1c03e0  mov        w0, w28
//   0x5aec: 94000cfd  bl         #0x8ee0
//   0x5af0: aa0003e3  mov        x3, x0
//   0x5af4: b0ffffe1  adrp       x1, #0x2000
//   0x5af8: 9103a021  add        x1, x1, #0xe8
//   0x5afc: 2a1b03e0  mov        w0, w27
//   0x5b00: 2a1c03e2  mov        w2, w28
//   0x5b04: 94000768  bl         #0x78a4
//   0x5b08: aa1803e0  mov        x0, x24
//   0x5b0c: aa1903e1  mov        x1, x25
//   0x5b10: 52800062  mov        w2, #3
//   0x5b14: 94000c63  bl         #0x8ca0
//   0x5b18: 34000140  cbz        w0, #0x5b40
//   0x5b1c: 5289a820  mov        w0, #0x4d41
//   0x5b20: b0ffffe4  adrp       x4, #0x2000
//   0x5b24: 91185884  add        x4, x4, #0x616
//   0x5b28: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x5b2c: 2a1f03e1  mov        w1, wzr
//   0x5b30: aa1803e2  mov        x2, x24
//   0x5b34: aa1903e3  mov        x3, x25
//   0x5b38: 94000d02  bl         #0x8f40
//   0x5b3c: 1400000f  b          #0x5b78
//   0x5b40: b94002b9  ldr        w25, [x21]
//   0x5b44: b9461758  ldr        w24, [x26, #0x614]
//   0x5b48: 2a1903e0  mov        w0, w25
//   0x5b4c: 94000ce5  bl         #0x8ee0
//   0x5b50: aa0003e3  mov        x3, x0
//   0x5b54: b0ffffe1  adrp       x1, #0x2000
//   0x5b58: 9103a021  add        x1, x1, #0xe8
//   0x5b5c: 2a1803e0  mov        w0, w24
//   0x5b60: 2a1903e2  mov        w2, w25
//   0x5b64: 94000750  bl         #0x78a4
//   0x5b68: b9461740  ldr        w0, [x26, #0x614]
//   0x5b6c: b0ffffe1  adrp       x1, #0x2000
//   0x5b70: 91083c21  add        x1, x1, #0x20f
//   0x5b74: 9400074c  bl         #0x78a4
//   0x5b78: 9000007b  adrp       x27, #0x11000
//   0x5b7c: 9000007c  adrp       x28, #0x11000
//   0x5b80: b9461740  ldr        w0, [x26, #0x614]
//   0x5b84: b0ffffe1  adrp       x1, #0x2000
//   0x5b88: 91090c21  add        x1, x1, #0x243
//   0x5b8c: 94000746  bl         #0x78a4
//   0x5b90: 90000075  adrp       x21, #0x11000
//   0x5b94: 90000068  adrp       x8, #0x11000
//   0x5b98: b9461741  ldr        w1, [x26, #0x614]
//   0x5b9c: aa1703e5  mov        x5, x23
//   0x5ba0: f9400ac2  ldr        x2, [x22, #0x10]
//   0x5ba4: f9438ea3  ldr        x3, [x21, #0x718]
//   0x5ba8: b9461900  ldr        w0, [x8, #0x618]
//   0x5bac: f9404c64  ldr        x4, [x3, #0x98]
//   0x5bb0: 94000224  bl         #0x6440
//   0x5bb4: b9461757  ldr        w23, [x26, #0x614]
//   0x5bb8: 94000cb2  bl         #0x8e80
//   0x5bbc: 90000068  adrp       x8, #0x11000
//   0x5bc0: 2a0003f8  mov        w24, w0
//   0x5bc4: f9439119  ldr        x25, [x8, #0x720]
//   0x5bc8: 94000c3a  bl         #0x8cb0
//   0x5bcc: 340014a0  cbz        w0, #0x5e60
//   0x5bd0: 37f80080  tbnz       w0, #0x1f, #0x5be0
//   0x5bd4: 910143e1  add        x1, sp, #0x50
//   0x5bd8: 52a80002  mov        w2, #0x40000000
//   0x5bdc: 94000c39  bl         #0x8cc0
//   0x5be0: 910043e0  add        x0, sp, #0x10
//   0x5be4: 94000ce7  bl         #0x8f80
//   0x5be8: b9461f88  ldr        w8, [x28, #0x61c]
//   0x5bec: 90000079  adrp       x25, #0x11000
//   0x5bf0: b9400bf8  ldr        w24, [sp, #8]
//   0x5bf4: 7100051f  cmp        w8, #1
//   0x5bf8: 540001ab  b.lt       #0x5c2c
//   0x5bfc: f9400be4  ldr        x4, [sp, #0x10]
//   0x5c00: 90ffffe3  adrp       x3, #0x1000
//   0x5c04: 913db063  add        x3, x3, #0xf6c
//   0x5c08: 910143e0  add        x0, sp, #0x50
//   0x5c0c: 52800801  mov        w1, #0x40
//   0x5c10: 52800802  mov        w2, #0x40
//   0x5c14: 9400009f  bl         #0x5e90
//   0x5c18: b9461f88  ldr        w8, [x28, #0x61c]
//   0x5c1c: 93407c02  sxtw       x2, w0
//   0x5c20: 910143e1  add        x1, sp, #0x50
//   0x5c24: 2a0803e0  mov        w0, w8
//   0x5c28: 94000cda  bl         #0x8f90
//   0x5c2c: b9461740  ldr        w0, [x26, #0x614]
//   0x5c30: b0ffffe1  adrp       x1, #0x2000
//   0x5c34: 91094821  add        x1, x1, #0x252
//   0x5c38: 9400071b  bl         #0x78a4
//   0x5c3c: f9438ea0  ldr        x0, [x21, #0x718]
//   0x5c40: 52800028  mov        w8, #1
//   0x5c44: b9005408  str        w8, [x0, #0x54]
//   0x5c48: 94000ac4  bl         #0x8758
//   0x5c4c: f9439764  ldr        x4, [x27, #0x728]
//   0x5c50: b40003a4  cbz        x4, #0x5cc4
//   0x5c54: 90ffffe3  adrp       x3, #0x1000
//   0x5c58: 91383463  add        x3, x3, #0xe0d
//   0x5c5c: 910143e0  add        x0, sp, #0x50
//   0x5c60: 52802001  mov        w1, #0x100
//   0x5c64: 52801fe2  mov        w2, #0xff
//   0x5c68: 9400008a  bl         #0x5e90
//   0x5c6c: 52800841  mov        w1, #0x42
//   0x5c70: 910143e0  add        x0, sp, #0x50
//   0x5c74: 72a00101  movk       w1, #8, lsl #16
//   0x5c78: 52803002  mov        w2, #0x180
//   0x5c7c: 94000cad  bl         #0x8f30
//   0x5c80: 7100041f  cmp        w0, #1
//   0x5c84: 5400020b  b.lt       #0x5cc4
//   0x5c88: 2a0003f7  mov        w23, w0
//   0x5c8c: 2a1f03e0  mov        w0, wzr
//   0x5c90: 940007b8  bl         #0x7b70
//   0x5c94: 910043e1  add        x1, sp, #0x10
//   0x5c98: 94000693  bl         #0x76e4
//   0x5c9c: aa0003f8  mov        x24, x0
//   0x5ca0: 94000cc0  bl         #0x8fa0
//   0x5ca4: aa0003e2  mov        x2, x0
//   0x5ca8: 2a1703e0  mov        w0, w23
//   0x5cac: aa1803e1  mov        x1, x24
//   0x5cb0: b9400bf8  ldr        w24, [sp, #8]
//   0x5cb4: 940006b1  bl         #0x7778
//   0x5cb8: 52800720  mov        w0, #0x39
//   0x5cbc: 2a1703e1  mov        w1, w23
//   0x5cc0: 94000cbc  bl         #0x8fb0
//   0x5cc4: b9461740  ldr        w0, [x26, #0x614]
//   0x5cc8: b0ffffe1  adrp       x1, #0x2000
//   0x5ccc: 91269421  add        x1, x1, #0x9a5
//   0x5cd0: 940006f5  bl         #0x78a4
//   0x5cd4: 90000068  adrp       x8, #0x11000
//   0x5cd8: 395bc108  ldrb       w8, [x8, #0x6f0]
//   0x5cdc: 37100508  tbnz       w8, #2, #0x5d7c
//   0x5ce0: aa1503e9  mov        x9, x21
//   0x5ce4: 90000075  adrp       x21, #0x11000
//   0x5ce8: f9437ea8  ldr        x8, [x21, #0x6f8]
//   0x5cec: f100051f  cmp        x8, #1
//   0x5cf0: 54000180  b.eq       #0x5d20
//   0x5cf4: b5000328  cbnz       x8, #0x5d58
//   0x5cf8: b9461740  ldr        w0, [x26, #0x614]
//   0x5cfc: b0ffffe1  adrp       x1, #0x2000
//   0x5d00: 91144c21  add        x1, x1, #0x513
//   0x5d04: 940006e8  bl         #0x78a4
//   0x5d08: 52800160  mov        w0, #0xb
//   0x5d0c: aa1f03e1  mov        x1, xzr
//   0x5d10: 94000cac  bl         #0x8fc0
//   0x5d14: 52800160  mov        w0, #0xb
//   0x5d18: 94000cae  bl         #0x8fd0
//   0x5d1c: 14000018  b          #0x5d7c
//   0x5d20: f9438d20  ldr        x0, [x9, #0x718]
//   0x5d24: f9400ac1  ldr        x1, [x22, #0x10]
//   0x5d28: 9400079f  bl         #0x7ba4
//   0x5d2c: 340000c0  cbz        w0, #0x5d44
//   0x5d30: 52800160  mov        w0, #0xb
//   0x5d34: aa1f03e1  mov        x1, xzr
//   0x5d38: 94000ca2  bl         #0x8fc0
//   0x5d3c: 52800160  mov        w0, #0xb
//   0x5d40: 94000ca4  bl         #0x8fd0
//   0x5d44: b9461740  ldr        w0, [x26, #0x614]
//   0x5d48: 90ffffe1  adrp       x1, #0x1000
//   0x5d4c: 91343021  add        x1, x1, #0xd0c
//   0x5d50: 940006d5  bl         #0x78a4
//   0x5d54: 1400000a  b          #0x5d7c
//   0x5d58: b9400ff6  ldr        w22, [sp, #0xc]
//   0x5d5c: b0ffffe1  adrp       x1, #0x2000
//   0x5d60: 91130021  add        x1, x1, #0x4c0
//   0x5d64: b9461740  ldr        w0, [x26, #0x614]
//   0x5d68: 2a1603e2  mov        w2, w22
//   0x5d6c: 940006ce  bl         #0x78a4
//   0x5d70: f9437ea8  ldr        x8, [x21, #0x6f8]
//   0x5d74: 2a1603e0  mov        w0, w22
//   0x5d78: d63f0100  blr        x8
//   0x5d7c: 90000076  adrp       x22, #0x11000
//   0x5d80: 395c42c8  ldrb       w8, [x22, #0x710]
//   0x5d84: 34000188  cbz        w8, #0x5db4
//   0x5d88: d503201f  nop        
//   0x5d8c: 1005cb21  adr        x1, #0x116f0
//   0x5d90: 52800160  mov        w0, #0xb
//   0x5d94: aa1f03e2  mov        x2, xzr
//   0x5d98: b9461755  ldr        w21, [x26, #0x614]
//   0x5d9c: 94000c6d  bl         #0x8f50
//   0x5da0: b0ffffe1  adrp       x1, #0x2000
//   0x5da4: 91252021  add        x1, x1, #0x948
//   0x5da8: 2a1503e0  mov        w0, w21
//   0x5dac: 391c42df  strb       wzr, [x22, #0x710]
//   0x5db0: 940006bd  bl         #0x78a4
//   0x5db4: 2a1f03e0  mov        w0, wzr
//   0x5db8: 2a1303e1  mov        w1, w19
//   0x5dbc: 2a1803e2  mov        w2, w24
//   0x5dc0: 94000c6c  bl         #0x8f70
//   0x5dc4: d503201f  nop        
//   0x5dc8: 1005cb40  adr        x0, #0x11730
//   0x5dcc: 94000c25  bl         #0x8e60
//   0x5dd0: d503201f  nop        
//   0x5dd4: 50fe1a41  adr        x1, #0x211e
//   0x5dd8: b0ffffe2  adrp       x2, #0x2000
//   0x5ddc: 91107042  add        x2, x2, #0x41c
//   0x5de0: 528000c0  mov        w0, #6
//   0x5de4: 94000b8f  bl         #0x8c20
//   0x5de8: b9461741  ldr        w1, [x26, #0x614]
//   0x5dec: 71000c3f  cmp        w1, #3
//   0x5df0: 5400006b  b.lt       #0x5dfc
//   0x5df4: 52800720  mov        w0, #0x39
//   0x5df8: 94000c6e  bl         #0x8fb0
//   0x5dfc: b9461b21  ldr        w1, [x25, #0x618]
//   0x5e00: 71000c3f  cmp        w1, #3
//   0x5e04: 5400006b  b.lt       #0x5e10
//   0x5e08: 52800720  mov        w0, #0x39
//   0x5e0c: 94000c69  bl         #0x8fb0
//   0x5e10: b9461f81  ldr        w1, [x28, #0x61c]
//   0x5e14: 71000c3f  cmp        w1, #3
//   0x5e18: 5400006b  b.lt       #0x5e24
//   0x5e1c: 52800720  mov        w0, #0x39
//   0x5e20: 94000c64  bl         #0x8fb0
//   0x5e24: f9439760  ldr        x0, [x27, #0x728]
//   0x5e28: b4000040  cbz        x0, #0x5e30
//   0x5e2c: 94000bb5  bl         #0x8d00
//   0x5e30: f9401688  ldr        x8, [x20, #0x28]
//   0x5e34: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x5e38: eb09011f  cmp        x8, x9
//   0x5e3c: 54000281  b.ne       #0x5e8c
//   0x5e40: a95b4ff4  ldp        x20, x19, [sp, #0x1b0]
//   0x5e44: a95a57f6  ldp        x22, x21, [sp, #0x1a0]
//   0x5e48: a9595ff8  ldp        x24, x23, [sp, #0x190]
//   0x5e4c: a95867fa  ldp        x26, x25, [sp, #0x180]
//   0x5e50: a9576ffc  ldp        x28, x27, [sp, #0x170]
//   0x5e54: a9567bfd  ldp        x29, x30, [sp, #0x160]
//   0x5e58: 910703ff  add        sp, sp, #0x1c0
//   0x5e5c: d65f03c0  ret        
//   0x5e60: 52800160  mov        w0, #0xb
//   0x5e64: aa1f03e1  mov        x1, xzr
//   0x5e68: 94000c56  bl         #0x8fc0
//   0x5e6c: 528003c0  mov        w0, #0x1e
//   0x5e70: 94000c5c  bl         #0x8fe0
//   0x5e74: 2a1703e0  mov        w0, w23
//   0x5e78: 2a1803e1  mov        w1, w24
//   0x5e7c: aa1903e2  mov        x2, x25
//   0x5e80: 94000022  bl         #0x5f08
//   0x5e84: 2a1f03e0  mov        w0, wzr
//   0x5e88: 94000b96  bl         #0x8ce0
//   0x5e8c: 94000bc9  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[30] XasanFde_5e90 (0x5e90..0x5f08, 120 bytes, 30 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x5e90..0x5f08
// ----------------------------------------------------------------------------
//   0x5e90: d103c3ff  sub        sp, sp, #0xf0
//   0x5e94: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x5e98: 910383fd  add        x29, sp, #0xe0
//   0x5e9c: 910003e9  mov        x9, sp
//   0x5ea0: 928003ea  mov        x10, #-0x20
//   0x5ea4: d10183ab  sub        x11, x29, #0x60
//   0x5ea8: f2dff00a  movk       x10, #0xff80, lsl #32
//   0x5eac: 91020129  add        x9, x9, #0x80
//   0x5eb0: 9100816b  add        x11, x11, #0x20
//   0x5eb4: 910043ac  add        x12, x29, #0x10
//   0x5eb8: ad0007e0  stp        q0, q1, [sp]
//   0x5ebc: aa0303e8  mov        x8, x3
//   0x5ec0: aa0103e3  mov        x3, x1
//   0x5ec4: a93f2ba9  stp        x9, x10, [x29, #-0x10]
//   0x5ec8: aa0203e1  mov        x1, x2
//   0x5ecc: a93e2fac  stp        x12, x11, [x29, #-0x20]
//   0x5ed0: 2a1f03e2  mov        w2, wzr
//   0x5ed4: ad7f03a1  ldp        q1, q0, [x29, #-0x20]
//   0x5ed8: a93a17a4  stp        x4, x5, [x29, #-0x60]
//   0x5edc: d10103a5  sub        x5, x29, #0x40
//   0x5ee0: aa0803e4  mov        x4, x8
//   0x5ee4: a93b1fa6  stp        x6, x7, [x29, #-0x50]
//   0x5ee8: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x5eec: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x5ef0: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x5ef4: ad3e03a1  stp        q1, q0, [x29, #-0x40]
//   0x5ef8: 94000c3e  bl         #0x8ff0
//   0x5efc: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x5f00: 9103c3ff  add        sp, sp, #0xf0
//   0x5f04: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[31] XasanFde_5f08 (0x5f08..0x5fac, 164 bytes, 41 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x5f08..0x5fac
// ----------------------------------------------------------------------------
//   0x5f08: d10703ff  sub        sp, sp, #0x1c0
//   0x5f0c: a9197bfd  stp        x29, x30, [sp, #0x190]
//   0x5f10: a91a57fc  stp        x28, x21, [sp, #0x1a0]
//   0x5f14: a91b4ff4  stp        x20, x19, [sp, #0x1b0]
//   0x5f18: 910643fd  add        x29, sp, #0x190
//   0x5f1c: d53bd055  mrs        x21, tpidr_el0
//   0x5f20: aa0203f3  mov        x19, x2
//   0x5f24: 2a0103e4  mov        w4, w1
//   0x5f28: f94016a8  ldr        x8, [x21, #0x28]
//   0x5f2c: 2a0003f4  mov        w20, w0
//   0x5f30: b0ffffe3  adrp       x3, #0x2000
//   0x5f34: 91007c63  add        x3, x3, #0x1f
//   0x5f38: d10223a0  sub        x0, x29, #0x88
//   0x5f3c: 52801001  mov        w1, #0x80
//   0x5f40: 52801002  mov        w2, #0x80
//   0x5f44: f81f83a8  stur       x8, [x29, #-8]
//   0x5f48: 97ffffd2  bl         #0x5e90
//   0x5f4c: b0ffffe3  adrp       x3, #0x2000
//   0x5f50: 9126c863  add        x3, x3, #0x9b2
//   0x5f54: 910023e0  add        x0, sp, #8
//   0x5f58: 52802001  mov        w1, #0x100
//   0x5f5c: 52802002  mov        w2, #0x100
//   0x5f60: aa1303e4  mov        x4, x19
//   0x5f64: 97ffffcb  bl         #0x5e90
//   0x5f68: d10223a0  sub        x0, x29, #0x88
//   0x5f6c: 910023e1  add        x1, sp, #8
//   0x5f70: 94000312  bl         #0x6bb8
//   0x5f74: 90ffffe1  adrp       x1, #0x1000
//   0x5f78: 91377c21  add        x1, x1, #0xddf
//   0x5f7c: 2a1403e0  mov        w0, w20
//   0x5f80: 94000649  bl         #0x78a4
//   0x5f84: f94016a8  ldr        x8, [x21, #0x28]
//   0x5f88: f85f83a9  ldur       x9, [x29, #-8]
//   0x5f8c: eb09011f  cmp        x8, x9
//   0x5f90: 540000c1  b.ne       #0x5fa8
//   0x5f94: a95b4ff4  ldp        x20, x19, [sp, #0x1b0]
//   0x5f98: a95a57fc  ldp        x28, x21, [sp, #0x1a0]
//   0x5f9c: a9597bfd  ldp        x29, x30, [sp, #0x190]
//   0x5fa0: 910703ff  add        sp, sp, #0x1c0
//   0x5fa4: d65f03c0  ret        
//   0x5fa8: 94000b82  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[32] XasanFde_5fac (0x5fac..0x61b0, 516 bytes, 129 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x5fac..0x61b0
// ----------------------------------------------------------------------------
//   0x5fac: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x5fb0: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x5fb4: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x5fb8: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x5fbc: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x5fc0: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x5fc4: 910003fd  mov        x29, sp
//   0x5fc8: d12103ff  sub        sp, sp, #0x840
//   0x5fcc: d53bd057  mrs        x23, tpidr_el0
//   0x5fd0: 2a0003f3  mov        w19, w0
//   0x5fd4: f94016e8  ldr        x8, [x23, #0x28]
//   0x5fd8: aa0203e0  mov        x0, x2
//   0x5fdc: aa0203f5  mov        x21, x2
//   0x5fe0: f81f03a8  stur       x8, [x29, #-0x10]
//   0x5fe4: 9400076e  bl         #0x7d9c
//   0x5fe8: aa0003f6  mov        x22, x0
//   0x5fec: 9100c3e1  add        x1, sp, #0x30
//   0x5ff0: aa1503e0  mov        x0, x21
//   0x5ff4: 52801002  mov        w2, #0x80
//   0x5ff8: 9400076b  bl         #0x7da4
//   0x5ffc: b4000180  cbz        x0, #0x602c
//   0x6000: aa0003f4  mov        x20, x0
//   0x6004: b10006df  cmn        x22, #1
//   0x6008: 54000160  b.eq       #0x6034
//   0x600c: a94116a4  ldp        x4, x5, [x21, #0x10]
//   0x6010: 90ffffe1  adrp       x1, #0x2000
//   0x6014: 91215821  add        x1, x1, #0x856
//   0x6018: 2a1303e0  mov        w0, w19
//   0x601c: aa1603e2  mov        x2, x22
//   0x6020: aa1503e3  mov        x3, x21
//   0x6024: 940005d5  bl         #0x7778
//   0x6028: 14000007  b          #0x6044
//   0x602c: 12800020  mov        w0, #-2
//   0x6030: 14000053  b          #0x617c
//   0x6034: d503201f  nop        
//   0x6038: 70fe1f61  adr        x1, #0x2427
//   0x603c: 2a1303e0  mov        w0, w19
//   0x6040: 940005ce  bl         #0x7778
//   0x6044: f9401be0  ldr        x0, [sp, #0x30]
//   0x6048: 910043e1  add        x1, sp, #0x10
//   0x604c: 94000bed  bl         #0x9000
//   0x6050: 34000840  cbz        w0, #0x6158
//   0x6054: 2a0003f8  mov        w24, w0
//   0x6058: f90007f7  str        x23, [sp, #8]
//   0x605c: aa1f03f5  mov        x21, xzr
//   0x6060: d100069b  sub        x27, x20, #1
//   0x6064: 9100c3fc  add        x28, sp, #0x30
//   0x6068: 52880016  mov        w22, #0x4000
//   0x606c: d503201f  nop        
//   0x6070: 1005b75a  adr        x26, #0x11758
//   0x6074: f0ffffd7  adrp       x23, #0x1000
//   0x6078: 913862f7  add        x23, x23, #0xe18
//   0x607c: f8757b88  ldr        x8, [x28, x21, lsl #3]
//   0x6080: a9419fe9  ldp        x9, x7, [sp, #0x18]
//   0x6084: f9400be6  ldr        x6, [sp, #0x10]
//   0x6088: cb090105  sub        x5, x8, x9
//   0x608c: b4000507  cbz        x7, #0x612c
//   0x6090: f94017e9  ldr        x9, [sp, #0x28]
//   0x6094: 9110c3e0  add        x0, sp, #0x430
//   0x6098: 52808001  mov        w1, #0x400
//   0x609c: 52807fe2  mov        w2, #0x3ff
//   0x60a0: aa1703e3  mov        x3, x23
//   0x60a4: aa1503e4  mov        x4, x21
//   0x60a8: cb090108  sub        x8, x8, x9
//   0x60ac: f90003e8  str        x8, [sp]
//   0x60b0: 94000040  bl         #0x61b0
//   0x60b4: 2a0003f9  mov        w25, w0
//   0x60b8: 71000b1f  cmp        w24, #2
//   0x60bc: 54000061  b.ne       #0x60c8
//   0x60c0: f94013e0  ldr        x0, [sp, #0x20]
//   0x60c4: 94000b0f  bl         #0x8d00
//   0x60c8: 7100073f  cmp        w25, #1
//   0x60cc: 540001cb  b.lt       #0x6104
//   0x60d0: f9400be0  ldr        x0, [sp, #0x10]
//   0x60d4: 94000bcf  bl         #0x9010
//   0x60d8: b8766b48  ldr        w8, [x26, x22]
//   0x60dc: 2a1903e2  mov        w2, w25
//   0x60e0: f9400bea  ldr        x10, [sp, #0x10]
//   0x60e4: 9110c3e1  add        x1, sp, #0x430
//   0x60e8: 8b080f49  add        x9, x26, x8, lsl #3
//   0x60ec: 11000508  add        w8, w8, #1
//   0x60f0: b8366b48  str        w8, [x26, x22]
//   0x60f4: f9000120  str        x0, [x9]
//   0x60f8: 2a1303e0  mov        w0, w19
//   0x60fc: f910012a  str        x10, [x9, #0x2000]
//   0x6100: 9400059e  bl         #0x7778
//   0x6104: eb15037f  cmp        x27, x21
//   0x6108: 540002c0  b.eq       #0x6160
//   0x610c: 8b150f88  add        x8, x28, x21, lsl #3
//   0x6110: 910043e1  add        x1, sp, #0x10
//   0x6114: f9400500  ldr        x0, [x8, #8]
//   0x6118: 94000bba  bl         #0x9000
//   0x611c: 2a0003f8  mov        w24, w0
//   0x6120: 910006b5  add        x21, x21, #1
//   0x6124: 35fffac0  cbnz       w0, #0x607c
//   0x6128: 14000011  b          #0x616c
//   0x612c: 9110c3e0  add        x0, sp, #0x430
//   0x6130: 52808001  mov        w1, #0x400
//   0x6134: 52807fe2  mov        w2, #0x3ff
//   0x6138: 90ffffe3  adrp       x3, #0x2000
//   0x613c: 91010063  add        x3, x3, #0x40
//   0x6140: aa1503e4  mov        x4, x21
//   0x6144: 9400001b  bl         #0x61b0
//   0x6148: 2a0003f9  mov        w25, w0
//   0x614c: 7100073f  cmp        w25, #1
//   0x6150: 54fffc0a  b.ge       #0x60d0
//   0x6154: 17ffffec  b          #0x6104
//   0x6158: 52800028  mov        w8, #1
//   0x615c: 14000007  b          #0x6178
//   0x6160: 910006a8  add        x8, x21, #1
//   0x6164: eb14011f  cmp        x8, x20
//   0x6168: 14000002  b          #0x6170
//   0x616c: eb1402bf  cmp        x21, x20
//   0x6170: 1a9f27e8  cset       w8, lo
//   0x6174: f94007f7  ldr        x23, [sp, #8]
//   0x6178: 13000100  sbfx       w0, w8, #0, #1
//   0x617c: f94016e8  ldr        x8, [x23, #0x28]
//   0x6180: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6184: eb09011f  cmp        x8, x9
//   0x6188: 54000121  b.ne       #0x61ac
//   0x618c: 912103ff  add        sp, sp, #0x840
//   0x6190: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x6194: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x6198: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x619c: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x61a0: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x61a4: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x61a8: d65f03c0  ret        
//   0x61ac: 94000b01  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[33] XasanFde_61b0 (0x61b0..0x6228, 120 bytes, 30 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x61b0..0x6228
// ----------------------------------------------------------------------------
//   0x61b0: d103c3ff  sub        sp, sp, #0xf0
//   0x61b4: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x61b8: 910383fd  add        x29, sp, #0xe0
//   0x61bc: 910003e9  mov        x9, sp
//   0x61c0: 928003ea  mov        x10, #-0x20
//   0x61c4: d10183ab  sub        x11, x29, #0x60
//   0x61c8: f2dff00a  movk       x10, #0xff80, lsl #32
//   0x61cc: 91020129  add        x9, x9, #0x80
//   0x61d0: 9100816b  add        x11, x11, #0x20
//   0x61d4: 910043ac  add        x12, x29, #0x10
//   0x61d8: ad0007e0  stp        q0, q1, [sp]
//   0x61dc: aa0303e8  mov        x8, x3
//   0x61e0: aa0103e3  mov        x3, x1
//   0x61e4: a93f2ba9  stp        x9, x10, [x29, #-0x10]
//   0x61e8: aa0203e1  mov        x1, x2
//   0x61ec: a93e2fac  stp        x12, x11, [x29, #-0x20]
//   0x61f0: 2a1f03e2  mov        w2, wzr
//   0x61f4: ad7f03a1  ldp        q1, q0, [x29, #-0x20]
//   0x61f8: a93a17a4  stp        x4, x5, [x29, #-0x60]
//   0x61fc: d10103a5  sub        x5, x29, #0x40
//   0x6200: aa0803e4  mov        x4, x8
//   0x6204: a93b1fa6  stp        x6, x7, [x29, #-0x50]
//   0x6208: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x620c: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x6210: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x6214: ad3e03a1  stp        q1, q0, [x29, #-0x40]
//   0x6218: 94000b76  bl         #0x8ff0
//   0x621c: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x6220: 9103c3ff  add        sp, sp, #0xf0
//   0x6224: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[34] XasanFde_6228 (0x6228..0x6440, 536 bytes, 134 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x6228..0x6440
// ----------------------------------------------------------------------------
//   0x6228: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x622c: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x6230: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x6234: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x6238: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x623c: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x6240: 910003fd  mov        x29, sp
//   0x6244: d12103ff  sub        sp, sp, #0x840
//   0x6248: d53bd059  mrs        x25, tpidr_el0
//   0x624c: 2a0003f3  mov        w19, w0
//   0x6250: f9401728  ldr        x8, [x25, #0x28]
//   0x6254: aa0203e0  mov        x0, x2
//   0x6258: aa0203f5  mov        x21, x2
//   0x625c: 2a0103f6  mov        w22, w1
//   0x6260: f81f03a8  stur       x8, [x29, #-0x10]
//   0x6264: 940006c3  bl         #0x7d70
//   0x6268: aa0003f7  mov        x23, x0
//   0x626c: 9100c3e1  add        x1, sp, #0x30
//   0x6270: aa1503e0  mov        x0, x21
//   0x6274: 52801002  mov        w2, #0x80
//   0x6278: 940006c0  bl         #0x7d78
//   0x627c: b4000180  cbz        x0, #0x62ac
//   0x6280: aa0003f4  mov        x20, x0
//   0x6284: b10006ff  cmn        x23, #1
//   0x6288: 540001e0  b.eq       #0x62c4
//   0x628c: a94116a4  ldp        x4, x5, [x21, #0x10]
//   0x6290: f0ffffc1  adrp       x1, #0x1000
//   0x6294: 9132d021  add        x1, x1, #0xcb4
//   0x6298: 2a1303e0  mov        w0, w19
//   0x629c: aa1703e2  mov        x2, x23
//   0x62a0: aa1503e3  mov        x3, x21
//   0x62a4: 94000535  bl         #0x7778
//   0x62a8: 1400000b  b          #0x62d4
//   0x62ac: 90ffffe1  adrp       x1, #0x2000
//   0x62b0: 911c3421  add        x1, x1, #0x70d
//   0x62b4: 2a1603e0  mov        w0, w22
//   0x62b8: 9400057b  bl         #0x78a4
//   0x62bc: 12800020  mov        w0, #-2
//   0x62c0: 14000053  b          #0x640c
//   0x62c4: 90ffffe1  adrp       x1, #0x2000
//   0x62c8: 91062c21  add        x1, x1, #0x18b
//   0x62cc: 2a1303e0  mov        w0, w19
//   0x62d0: 9400052a  bl         #0x7778
//   0x62d4: f9401be0  ldr        x0, [sp, #0x30]
//   0x62d8: 910043e1  add        x1, sp, #0x10
//   0x62dc: 94000b49  bl         #0x9000
//   0x62e0: 34000840  cbz        w0, #0x63e8
//   0x62e4: 2a0003f8  mov        w24, w0
//   0x62e8: f90007f9  str        x25, [sp, #8]
//   0x62ec: aa1f03f5  mov        x21, xzr
//   0x62f0: d100069b  sub        x27, x20, #1
//   0x62f4: 9100c3fc  add        x28, sp, #0x30
//   0x62f8: 52880016  mov        w22, #0x4000
//   0x62fc: d503201f  nop        
//   0x6300: 1005a2da  adr        x26, #0x11758
//   0x6304: f0ffffd7  adrp       x23, #0x1000
//   0x6308: 913862f7  add        x23, x23, #0xe18
//   0x630c: f8757b88  ldr        x8, [x28, x21, lsl #3]
//   0x6310: a9419fe9  ldp        x9, x7, [sp, #0x18]
//   0x6314: f9400be6  ldr        x6, [sp, #0x10]
//   0x6318: cb090105  sub        x5, x8, x9
//   0x631c: b4000507  cbz        x7, #0x63bc
//   0x6320: f94017e9  ldr        x9, [sp, #0x28]
//   0x6324: 9110c3e0  add        x0, sp, #0x430
//   0x6328: 52808001  mov        w1, #0x400
//   0x632c: 52807fe2  mov        w2, #0x3ff
//   0x6330: aa1703e3  mov        x3, x23
//   0x6334: aa1503e4  mov        x4, x21
//   0x6338: cb090108  sub        x8, x8, x9
//   0x633c: f90003e8  str        x8, [sp]
//   0x6340: 97ffff9c  bl         #0x61b0
//   0x6344: 2a0003f9  mov        w25, w0
//   0x6348: 71000b1f  cmp        w24, #2
//   0x634c: 54000061  b.ne       #0x6358
//   0x6350: f94013e0  ldr        x0, [sp, #0x20]
//   0x6354: 94000a6b  bl         #0x8d00
//   0x6358: 7100073f  cmp        w25, #1
//   0x635c: 540001cb  b.lt       #0x6394
//   0x6360: f9400be0  ldr        x0, [sp, #0x10]
//   0x6364: 94000b2b  bl         #0x9010
//   0x6368: b8766b48  ldr        w8, [x26, x22]
//   0x636c: 2a1903e2  mov        w2, w25
//   0x6370: f9400bea  ldr        x10, [sp, #0x10]
//   0x6374: 9110c3e1  add        x1, sp, #0x430
//   0x6378: 8b080f49  add        x9, x26, x8, lsl #3
//   0x637c: 11000508  add        w8, w8, #1
//   0x6380: b8366b48  str        w8, [x26, x22]
//   0x6384: f9000120  str        x0, [x9]
//   0x6388: 2a1303e0  mov        w0, w19
//   0x638c: f910012a  str        x10, [x9, #0x2000]
//   0x6390: 940004fa  bl         #0x7778
//   0x6394: eb15037f  cmp        x27, x21
//   0x6398: 540002c0  b.eq       #0x63f0
//   0x639c: 8b150f88  add        x8, x28, x21, lsl #3
//   0x63a0: 910043e1  add        x1, sp, #0x10
//   0x63a4: f9400500  ldr        x0, [x8, #8]
//   0x63a8: 94000b16  bl         #0x9000
//   0x63ac: 2a0003f8  mov        w24, w0
//   0x63b0: 910006b5  add        x21, x21, #1
//   0x63b4: 35fffac0  cbnz       w0, #0x630c
//   0x63b8: 14000011  b          #0x63fc
//   0x63bc: 9110c3e0  add        x0, sp, #0x430
//   0x63c0: 52808001  mov        w1, #0x400
//   0x63c4: 52807fe2  mov        w2, #0x3ff
//   0x63c8: 90ffffe3  adrp       x3, #0x2000
//   0x63cc: 91010063  add        x3, x3, #0x40
//   0x63d0: aa1503e4  mov        x4, x21
//   0x63d4: 97ffff77  bl         #0x61b0
//   0x63d8: 2a0003f9  mov        w25, w0
//   0x63dc: 7100073f  cmp        w25, #1
//   0x63e0: 54fffc0a  b.ge       #0x6360
//   0x63e4: 17ffffec  b          #0x6394
//   0x63e8: 52800028  mov        w8, #1
//   0x63ec: 14000007  b          #0x6408
//   0x63f0: 910006a8  add        x8, x21, #1
//   0x63f4: eb14011f  cmp        x8, x20
//   0x63f8: 14000002  b          #0x6400
//   0x63fc: eb1402bf  cmp        x21, x20
//   0x6400: 1a9f27e8  cset       w8, lo
//   0x6404: f94007f9  ldr        x25, [sp, #8]
//   0x6408: 13000100  sbfx       w0, w8, #0, #1
//   0x640c: f9401728  ldr        x8, [x25, #0x28]
//   0x6410: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6414: eb09011f  cmp        x8, x9
//   0x6418: 54000121  b.ne       #0x643c
//   0x641c: 912103ff  add        sp, sp, #0x840
//   0x6420: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x6424: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x6428: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x642c: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x6430: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x6434: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x6438: d65f03c0  ret        
//   0x643c: 94000a5d  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[35] XasanDumpCrashReport_6440 (0x6440..0x6abc, 1660 bytes, 415 instructions)
// Summary / Tóm tắt: Forks child process & dumps GWP-ASan report to tombstone.txt / glog.txt (@ 0x6440..0x6abc)
// ----------------------------------------------------------------------------
//   0x6440: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x6444: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x6448: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x644c: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x6450: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x6454: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x6458: 910003fd  mov        x29, sp
//   0x645c: d14007ff  sub        sp, sp, #1, lsl #12
//   0x6460: d110c3ff  sub        sp, sp, #0x430
//   0x6464: d53bd059  mrs        x25, tpidr_el0
//   0x6468: 2a0003f3  mov        w19, w0
//   0x646c: aa0303f4  mov        x20, x3
//   0x6470: aa0203f8  mov        x24, x2
//   0x6474: f9401728  ldr        x8, [x25, #0x28]
//   0x6478: f0000069  adrp       x9, #0x15000
//   0x647c: 2a0103f5  mov        w21, w1
//   0x6480: f81f03a8  stur       x8, [x29, #-0x10]
//   0x6484: b907593f  str        wzr, [x9, #0x758]
//   0x6488: 37f804c0  tbnz       w0, #0x1f, #0x6520
//   0x648c: aa1403e0  mov        x0, x20
//   0x6490: aa1803e1  mov        x1, x24
//   0x6494: aa0503fa  mov        x26, x5
//   0x6498: aa0403f7  mov        x23, x4
//   0x649c: 940005c2  bl         #0x7ba4
//   0x64a0: 34000400  cbz        w0, #0x6520
//   0x64a4: aa1403e0  mov        x0, x20
//   0x64a8: 940005ce  bl         #0x7be0
//   0x64ac: f100001f  cmp        x0, #0
//   0x64b0: aa1703e1  mov        x1, x23
//   0x64b4: 9a800318  csel       x24, x24, x0, eq
//   0x64b8: aa1403e0  mov        x0, x20
//   0x64bc: aa1803e2  mov        x2, x24
//   0x64c0: 940005ca  bl         #0x7be8
//   0x64c4: 34000580  cbz        w0, #0x6574
//   0x64c8: 2a0003f6  mov        w22, w0
//   0x64cc: aa1403e0  mov        x0, x20
//   0x64d0: aa1703e1  mov        x1, x23
//   0x64d4: aa1803e2  mov        x2, x24
//   0x64d8: 94000600  bl         #0x7cd8
//   0x64dc: b4000760  cbz        x0, #0x65c8
//   0x64e0: aa0003f7  mov        x23, x0
//   0x64e4: 94000a67  bl         #0x8e80
//   0x64e8: 2a0003fb  mov        w27, w0
//   0x64ec: 94000a69  bl         #0x8e90
//   0x64f0: 3100077f  cmn        w27, #1
//   0x64f4: b9001be0  str        w0, [sp, #0x18]
//   0x64f8: b9000ffb  str        w27, [sp, #0xc]
//   0x64fc: 54000860  b.eq       #0x6608
//   0x6500: f0ffffc3  adrp       x3, #0x1000
//   0x6504: 9133ac63  add        x3, x3, #0xceb
//   0x6508: 911083e0  add        x0, sp, #0x420
//   0x650c: 52802001  mov        w1, #0x100
//   0x6510: 52802002  mov        w2, #0x100
//   0x6514: 2a1b03e4  mov        w4, w27
//   0x6518: 97ffff26  bl         #0x61b0
//   0x651c: 14000042  b          #0x6624
//   0x6520: aa1403e0  mov        x0, x20
//   0x6524: aa1803e1  mov        x1, x24
//   0x6528: 9400059f  bl         #0x7ba4
//   0x652c: f9401728  ldr        x8, [x25, #0x28]
//   0x6530: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6534: eb09011f  cmp        x8, x9
//   0x6538: 54002c01  b.ne       #0x6ab8
//   0x653c: 2a0003e3  mov        w3, w0
//   0x6540: 90ffffe1  adrp       x1, #0x2000
//   0x6544: 91258821  add        x1, x1, #0x962
//   0x6548: 2a1503e0  mov        w0, w21
//   0x654c: 2a1303e2  mov        w2, w19
//   0x6550: 914007ff  add        sp, sp, #1, lsl #12
//   0x6554: 9110c3ff  add        sp, sp, #0x430
//   0x6558: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x655c: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x6560: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x6564: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x6568: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x656c: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x6570: 140004cd  b          #0x78a4
//   0x6574: 90ffffe1  adrp       x1, #0x2000
//   0x6578: 91223c21  add        x1, x1, #0x88f
//   0x657c: 2a1503e0  mov        w0, w21
//   0x6580: 940004c9  bl         #0x78a4
//   0x6584: f9400ae2  ldr        x2, [x23, #0x10]
//   0x6588: f9401728  ldr        x8, [x25, #0x28]
//   0x658c: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6590: eb09011f  cmp        x8, x9
//   0x6594: 54002921  b.ne       #0x6ab8
//   0x6598: 90ffffe1  adrp       x1, #0x2000
//   0x659c: 91112821  add        x1, x1, #0x44a
//   0x65a0: 2a1303e0  mov        w0, w19
//   0x65a4: 914007ff  add        sp, sp, #1, lsl #12
//   0x65a8: 9110c3ff  add        sp, sp, #0x430
//   0x65ac: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x65b0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x65b4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x65b8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x65bc: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x65c0: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x65c4: 1400046d  b          #0x7778
//   0x65c8: f9401728  ldr        x8, [x25, #0x28]
//   0x65cc: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x65d0: eb09011f  cmp        x8, x9
//   0x65d4: 54002721  b.ne       #0x6ab8
//   0x65d8: f0ffffc1  adrp       x1, #0x1000
//   0x65dc: 913a1021  add        x1, x1, #0xe84
//   0x65e0: 2a1503e0  mov        w0, w21
//   0x65e4: 914007ff  add        sp, sp, #1, lsl #12
//   0x65e8: 9110c3ff  add        sp, sp, #0x430
//   0x65ec: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x65f0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x65f4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x65f8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x65fc: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x6600: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x6604: 140004a8  b          #0x78a4
//   0x6608: 90ffffe1  adrp       x1, #0x2000
//   0x660c: 9103fc21  add        x1, x1, #0xff
//   0x6610: 911083e0  add        x0, sp, #0x420
//   0x6614: 52802002  mov        w2, #0x100
//   0x6618: 52802003  mov        w3, #0x100
//   0x661c: 52800264  mov        w4, #0x13
//   0x6620: 94000a80  bl         #0x9020
//   0x6624: 911083e0  add        x0, sp, #0x420
//   0x6628: 52a00101  mov        w1, #0x80000
//   0x662c: 94000a81  bl         #0x9030
//   0x6630: f9000bfa  str        x26, [sp, #0x10]
//   0x6634: 37f802e0  tbnz       w0, #0x1f, #0x6690
//   0x6638: 911083e1  add        x1, sp, #0x420
//   0x663c: 52802002  mov        w2, #0x100
//   0x6640: 2a0003fc  mov        w28, w0
//   0x6644: 94000a7f  bl         #0x9040
//   0x6648: aa0003fb  mov        x27, x0
//   0x664c: 2a1c03e0  mov        w0, w28
//   0x6650: 94000a80  bl         #0x9050
//   0x6654: f1000768  subs       x8, x27, #1
//   0x6658: 540001cb  b.lt       #0x6690
//   0x665c: f104037f  cmp        x27, #0x100
//   0x6660: 540000a0  b.eq       #0x6674
//   0x6664: 911083e9  add        x9, sp, #0x420
//   0x6668: 38686929  ldrb       w9, [x9, x8]
//   0x666c: 7100293f  cmp        w9, #0xa
//   0x6670: 54000041  b.ne       #0x6678
//   0x6674: aa0803fb  mov        x27, x8
//   0x6678: 911083e0  add        x0, sp, #0x420
//   0x667c: 911083e8  add        x8, sp, #0x420
//   0x6680: 383b691f  strb       wzr, [x8, x27]
//   0x6684: 940009b3  bl         #0x8d50
//   0x6688: aa0003fc  mov        x28, x0
//   0x668c: 14000002  b          #0x6694
//   0x6690: aa1f03fc  mov        x28, xzr
//   0x6694: 90ffffe3  adrp       x3, #0x2000
//   0x6698: 91016863  add        x3, x3, #0x5a
//   0x669c: 911083e0  add        x0, sp, #0x420
//   0x66a0: 52800801  mov        w1, #0x40
//   0x66a4: 52800802  mov        w2, #0x40
//   0x66a8: b9401be4  ldr        w4, [sp, #0x18]
//   0x66ac: 97fffec1  bl         #0x61b0
//   0x66b0: 911083e0  add        x0, sp, #0x420
//   0x66b4: 52a00101  mov        w1, #0x80000
//   0x66b8: 94000a5e  bl         #0x9030
//   0x66bc: 37f802e0  tbnz       w0, #0x1f, #0x6718
//   0x66c0: 911083e1  add        x1, sp, #0x420
//   0x66c4: 52800802  mov        w2, #0x40
//   0x66c8: 2a0003fa  mov        w26, w0
//   0x66cc: 94000a5d  bl         #0x9040
//   0x66d0: aa0003fb  mov        x27, x0
//   0x66d4: 2a1a03e0  mov        w0, w26
//   0x66d8: 94000a5e  bl         #0x9050
//   0x66dc: f1000768  subs       x8, x27, #1
//   0x66e0: 540001cb  b.lt       #0x6718
//   0x66e4: f101037f  cmp        x27, #0x40
//   0x66e8: 540000a0  b.eq       #0x66fc
//   0x66ec: 911083e9  add        x9, sp, #0x420
//   0x66f0: 38686929  ldrb       w9, [x9, x8]
//   0x66f4: 7100293f  cmp        w9, #0xa
//   0x66f8: 54000041  b.ne       #0x6700
//   0x66fc: aa0803fb  mov        x27, x8
//   0x6700: 911083e0  add        x0, sp, #0x420
//   0x6704: 911083e8  add        x8, sp, #0x420
//   0x6708: 383b691f  strb       wzr, [x8, x27]
//   0x670c: 94000991  bl         #0x8d50
//   0x6710: aa0003fb  mov        x27, x0
//   0x6714: 14000002  b          #0x671c
//   0x6718: aa1f03fb  mov        x27, xzr
//   0x671c: 90ffffe3  adrp       x3, #0x2000
//   0x6720: 910ce063  add        x3, x3, #0x338
//   0x6724: 911083e0  add        x0, sp, #0x420
//   0x6728: 52808001  mov        w1, #0x400
//   0x672c: 52807fe2  mov        w2, #0x3ff
//   0x6730: b9400fe4  ldr        w4, [sp, #0xc]
//   0x6734: b9401be5  ldr        w5, [sp, #0x18]
//   0x6738: aa1b03e6  mov        x6, x27
//   0x673c: aa1c03e7  mov        x7, x28
//   0x6740: f90003f8  str        x24, [sp]
//   0x6744: 97fffe9b  bl         #0x61b0
//   0x6748: 2a0003fa  mov        w26, w0
//   0x674c: b400007c  cbz        x28, #0x6758
//   0x6750: aa1c03e0  mov        x0, x28
//   0x6754: 9400096b  bl         #0x8d00
//   0x6758: b400007b  cbz        x27, #0x6764
//   0x675c: aa1b03e0  mov        x0, x27
//   0x6760: 94000968  bl         #0x8d00
//   0x6764: 7100075f  cmp        w26, #1
//   0x6768: 540000ab  b.lt       #0x677c
//   0x676c: 2a1a03e2  mov        w2, w26
//   0x6770: 911083e1  add        x1, sp, #0x420
//   0x6774: 2a1303e0  mov        w0, w19
//   0x6778: 94000400  bl         #0x7778
//   0x677c: 2a1603e0  mov        w0, w22
//   0x6780: 94000590  bl         #0x7dc0
//   0x6784: aa0003fa  mov        x26, x0
//   0x6788: aa1703e0  mov        x0, x23
//   0x678c: 94000575  bl         #0x7d60
//   0x6790: aa0003fb  mov        x27, x0
//   0x6794: aa1703e0  mov        x0, x23
//   0x6798: 94000574  bl         #0x7d68
//   0x679c: aa0003e6  mov        x6, x0
//   0x67a0: eb180363  subs       x3, x27, x24
//   0x67a4: 54000121  b.ne       #0x67c8
//   0x67a8: f0ffffc1  adrp       x1, #0x1000
//   0x67ac: 913b1421  add        x1, x1, #0xec5
//   0x67b0: 2a1303e0  mov        w0, w19
//   0x67b4: aa1a03e2  mov        x2, x26
//   0x67b8: aa0603e3  mov        x3, x6
//   0x67bc: aa1803e4  mov        x4, x24
//   0x67c0: 940003ee  bl         #0x7778
//   0x67c4: 1400001c  b          #0x6834
//   0x67c8: 54000089  b.ls       #0x67d8
//   0x67cc: 90ffffe5  adrp       x5, #0x2000
//   0x67d0: 910e50a5  add        x5, x5, #0x394
//   0x67d4: 1400000c  b          #0x6804
//   0x67d8: cb1b0303  sub        x3, x24, x27
//   0x67dc: eb06007f  cmp        x3, x6
//   0x67e0: 54000082  b.hs       #0x67f0
//   0x67e4: f0ffffc5  adrp       x5, #0x1000
//   0x67e8: 913a9ca5  add        x5, x5, #0xea7
//   0x67ec: 14000006  b          #0x6804
//   0x67f0: 710012df  cmp        w22, #4
//   0x67f4: f0ffffc5  adrp       x5, #0x1000
//   0x67f8: 9138eca5  add        x5, x5, #0xe3b
//   0x67fc: 9a9f00c8  csel       x8, x6, xzr, eq
//   0x6800: cb080063  sub        x3, x3, x8
//   0x6804: f0ffffc8  adrp       x8, #0x1000
//   0x6808: 91356108  add        x8, x8, #0xd58
//   0x680c: 90ffffe9  adrp       x9, #0x2000
//   0x6810: 91021129  add        x9, x9, #0x84
//   0x6814: f100047f  cmp        x3, #1
//   0x6818: 90ffffe1  adrp       x1, #0x2000
//   0x681c: 911f1c21  add        x1, x1, #0x7c7
//   0x6820: 9a880124  csel       x4, x9, x8, eq
//   0x6824: 2a1303e0  mov        w0, w19
//   0x6828: aa1a03e2  mov        x2, x26
//   0x682c: aa1b03e7  mov        x7, x27
//   0x6830: 940003d2  bl         #0x7778
//   0x6834: 90ffffe1  adrp       x1, #0x2000
//   0x6838: 9122e821  add        x1, x1, #0x8ba
//   0x683c: 2a1503e0  mov        w0, w21
//   0x6840: 94000419  bl         #0x78a4
//   0x6844: f0ffffc1  adrp       x1, #0x1000
//   0x6848: 913bf421  add        x1, x1, #0xefd
//   0x684c: 2a1303e0  mov        w0, w19
//   0x6850: 52800162  mov        w2, #0xb
//   0x6854: 940003c9  bl         #0x7778
//   0x6858: f9400be0  ldr        x0, [sp, #0x10]
//   0x685c: 52800021  mov        w1, #1
//   0x6860: 94000a00  bl         #0x9060
//   0x6864: f000007a  adrp       x26, #0x15000
//   0x6868: b4000120  cbz        x0, #0x688c
//   0x686c: aa0003f6  mov        x22, x0
//   0x6870: 940009cc  bl         #0x8fa0
//   0x6874: aa0003e2  mov        x2, x0
//   0x6878: 2a1303e0  mov        w0, w19
//   0x687c: aa1603e1  mov        x1, x22
//   0x6880: 940003be  bl         #0x7778
//   0x6884: aa1603e0  mov        x0, x22
//   0x6888: 9400091e  bl         #0x8d00
//   0x688c: 90ffffe1  adrp       x1, #0x2000
//   0x6890: 91161821  add        x1, x1, #0x586
//   0x6894: 2a1503e0  mov        w0, w21
//   0x6898: 94000403  bl         #0x78a4
//   0x689c: aa1703e0  mov        x0, x23
//   0x68a0: 9400053d  bl         #0x7d94
//   0x68a4: 34000080  cbz        w0, #0x68b4
//   0x68a8: 2a1303e0  mov        w0, w19
//   0x68ac: aa1703e2  mov        x2, x23
//   0x68b0: 97fffdbf  bl         #0x5fac
//   0x68b4: 2a1303e0  mov        w0, w19
//   0x68b8: 2a1503e1  mov        w1, w21
//   0x68bc: aa1703e2  mov        x2, x23
//   0x68c0: 97fffe5a  bl         #0x6228
//   0x68c4: 90ffffe1  adrp       x1, #0x2000
//   0x68c8: 91202c21  add        x1, x1, #0x80b
//   0x68cc: 2a1303e0  mov        w0, w19
//   0x68d0: 52800162  mov        w2, #0xb
//   0x68d4: 940003a9  bl         #0x7778
//   0x68d8: 911083e0  add        x0, sp, #0x420
//   0x68dc: 2a1f03e1  mov        w1, wzr
//   0x68e0: 52820002  mov        w2, #0x1000
//   0x68e4: 911083f8  add        x24, sp, #0x420
//   0x68e8: 940008e6  bl         #0x8c80
//   0x68ec: b9475b57  ldr        w23, [x26, #0x758]
//   0x68f0: 34000937  cbz        w23, #0x6a14
//   0x68f4: f9000ff9  str        x25, [sp, #0x18]
//   0x68f8: aa1f03e8  mov        x8, xzr
//   0x68fc: 2a1f03fa  mov        w26, wzr
//   0x6900: 52800039  mov        w25, #1
//   0x6904: d503201f  nop        
//   0x6908: 10057296  adr        x22, #0x11758
//   0x690c: 14000005  b          #0x6920
//   0x6910: 91000739  add        x25, x25, #1
//   0x6914: aa1c03e8  mov        x8, x28
//   0x6918: eb17039f  cmp        x28, x23
//   0x691c: 54000240  b.eq       #0x6964
//   0x6920: 9100051c  add        x28, x8, #1
//   0x6924: eb17039f  cmp        x28, x23
//   0x6928: 54ffff42  b.hs       #0x6910
//   0x692c: f8687ad5  ldr        x21, [x22, x8, lsl #3]
//   0x6930: aa1903fb  mov        x27, x25
//   0x6934: 14000004  b          #0x6944
//   0x6938: 9100077b  add        x27, x27, #1
//   0x693c: 6b1b02ff  cmp        w23, w27
//   0x6940: 54fffe80  b.eq       #0x6910
//   0x6944: f87b7ac1  ldr        x1, [x22, x27, lsl #3]
//   0x6948: aa1503e0  mov        x0, x21
//   0x694c: 940009c9  bl         #0x9070
//   0x6950: 35ffff40  cbnz       w0, #0x6938
//   0x6954: 11000748  add        w8, w26, #1
//   0x6958: b83adb1b  str        w27, [x24, w26, sxtw #2]
//   0x695c: 2a0803fa  mov        w26, w8
//   0x6960: 17fffff6  b          #0x6938
//   0x6964: 911083e8  add        x8, sp, #0x420
//   0x6968: aa1f03f8  mov        x24, xzr
//   0x696c: b94423fa  ldr        w26, [sp, #0x420]
//   0x6970: 9100111b  add        x27, x8, #4
//   0x6974: 5288001c  mov        w28, #0x4000
//   0x6978: 90fffff5  adrp       x21, #0x2000
//   0x697c: 910982b5  add        x21, x21, #0x260
//   0x6980: f9400ff9  ldr        x25, [sp, #0x18]
//   0x6984: 14000007  b          #0x69a0
//   0x6988: f8787ac0  ldr        x0, [x22, x24, lsl #3]
//   0x698c: 940008dd  bl         #0x8d00
//   0x6990: b87c6ad7  ldr        w23, [x22, x28]
//   0x6994: 91000718  add        x24, x24, #1
//   0x6998: eb17031f  cmp        x24, x23
//   0x699c: 540003c2  b.hs       #0x6a14
//   0x69a0: 710006ff  cmp        w23, #1
//   0x69a4: 540001ab  b.lt       #0x69d8
//   0x69a8: eb1a031f  cmp        x24, x26
//   0x69ac: 54fffee0  b.eq       #0x6988
//   0x69b0: aa1f03e8  mov        x8, xzr
//   0x69b4: d10006e9  sub        x9, x23, #1
//   0x69b8: eb08013f  cmp        x9, x8
//   0x69bc: 540000e0  b.eq       #0x69d8
//   0x69c0: b8687b6a  ldr        w10, [x27, x8, lsl #2]
//   0x69c4: 91000508  add        x8, x8, #1
//   0x69c8: eb0a031f  cmp        x24, x10
//   0x69cc: 54ffff61  b.ne       #0x69b8
//   0x69d0: eb17011f  cmp        x8, x23
//   0x69d4: 54fffda3  b.lo       #0x6988
//   0x69d8: 8b180ec8  add        x8, x22, x24, lsl #3
//   0x69dc: 910083e0  add        x0, sp, #0x20
//   0x69e0: 52808001  mov        w1, #0x400
//   0x69e4: 52807fe2  mov        w2, #0x3ff
//   0x69e8: aa1503e3  mov        x3, x21
//   0x69ec: f9500104  ldr        x4, [x8, #0x2000]
//   0x69f0: f9400105  ldr        x5, [x8]
//   0x69f4: 97fffdef  bl         #0x61b0
//   0x69f8: 7100041f  cmp        w0, #1
//   0x69fc: 54fffc6b  b.lt       #0x6988
//   0x6a00: 2a0003e2  mov        w2, w0
//   0x6a04: 910083e1  add        x1, sp, #0x20
//   0x6a08: 2a1303e0  mov        w0, w19
//   0x6a0c: 9400035b  bl         #0x7778
//   0x6a10: 17ffffde  b          #0x6988
//   0x6a14: b4000234  cbz        x20, #0x6a58
//   0x6a18: f9402e82  ldr        x2, [x20, #0x58]
//   0x6a1c: b40000e2  cbz        x2, #0x6a38
//   0x6a20: 90ffffe1  adrp       x1, #0x2000
//   0x6a24: 91205c21  add        x1, x1, #0x817
//   0x6a28: 2a1303e0  mov        w0, w19
//   0x6a2c: 94000353  bl         #0x7778
//   0x6a30: f9402e80  ldr        x0, [x20, #0x58]
//   0x6a34: 940008b3  bl         #0x8d00
//   0x6a38: f9403282  ldr        x2, [x20, #0x60]
//   0x6a3c: b40000e2  cbz        x2, #0x6a58
//   0x6a40: 90ffffe1  adrp       x1, #0x2000
//   0x6a44: 9101a021  add        x1, x1, #0x68
//   0x6a48: 2a1303e0  mov        w0, w19
//   0x6a4c: 9400034b  bl         #0x7778
//   0x6a50: f9403280  ldr        x0, [x20, #0x60]
//   0x6a54: 940008ab  bl         #0x8d00
//   0x6a58: 9400040f  bl         #0x7a94
//   0x6a5c: b40000c0  cbz        x0, #0x6a74
//   0x6a60: aa0003e2  mov        x2, x0
//   0x6a64: 90ffffe1  adrp       x1, #0x2000
//   0x6a68: 9109d821  add        x1, x1, #0x276
//   0x6a6c: 2a1303e0  mov        w0, w19
//   0x6a70: 94000342  bl         #0x7778
//   0x6a74: 7100067f  cmp        w19, #1
//   0x6a78: 5400006b  b.lt       #0x6a84
//   0x6a7c: 2a1303e0  mov        w0, w19
//   0x6a80: 94000974  bl         #0x9050
//   0x6a84: f9401728  ldr        x8, [x25, #0x28]
//   0x6a88: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6a8c: eb09011f  cmp        x8, x9
//   0x6a90: 54000141  b.ne       #0x6ab8
//   0x6a94: 914007ff  add        sp, sp, #1, lsl #12
//   0x6a98: 9110c3ff  add        sp, sp, #0x430
//   0x6a9c: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x6aa0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x6aa4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x6aa8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x6aac: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x6ab0: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x6ab4: d65f03c0  ret        
//   0x6ab8: 940008be  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[36] XasanFde_6abc (0x6abc..0x6bb8, 252 bytes, 63 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x6abc..0x6bb8
// ----------------------------------------------------------------------------
//   0x6abc: d10143ff  sub        sp, sp, #0x50
//   0x6ac0: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x6ac4: f90013f7  str        x23, [sp, #0x20]
//   0x6ac8: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x6acc: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x6ad0: 910043fd  add        x29, sp, #0x10
//   0x6ad4: 121a0028  and        w8, w1, #0x40
//   0x6ad8: 13061829  sbfx       w9, w1, #6, #1
//   0x6adc: aa0003f3  mov        x19, x0
//   0x6ae0: 12190534  and        w20, w9, #0x180
//   0x6ae4: 2a481428  orr        w8, w1, w8, lsr #5
//   0x6ae8: 320d0115  orr        w21, w8, #0x80000
//   0x6aec: 94000879  bl         #0x8cd0
//   0x6af0: aa0003f6  mov        x22, x0
//   0x6af4: aa1303e0  mov        x0, x19
//   0x6af8: 2a1503e1  mov        w1, w21
//   0x6afc: 2a1403e2  mov        w2, w20
//   0x6b00: b90002df  str        wzr, [x22]
//   0x6b04: 9400090b  bl         #0x8f30
//   0x6b08: 2a0003f7  mov        w23, w0
//   0x6b0c: 3100041f  cmn        w0, #1
//   0x6b10: 540000e1  b.ne       #0x6b2c
//   0x6b14: b94002c8  ldr        w8, [x22]
//   0x6b18: 7100111f  cmp        w8, #4
//   0x6b1c: 54fffec0  b.eq       #0x6af4
//   0x6b20: 7100611f  cmp        w8, #0x18
//   0x6b24: 540000c0  b.eq       #0x6b3c
//   0x6b28: 1400001d  b          #0x6b9c
//   0x6b2c: 36f80397  tbz        w23, #0x1f, #0x6b9c
//   0x6b30: b94002c8  ldr        w8, [x22]
//   0x6b34: 7100611f  cmp        w8, #0x18
//   0x6b38: 54000321  b.ne       #0x6b9c
//   0x6b3c: 910003e1  mov        x1, sp
//   0x6b40: 528000e0  mov        w0, #7
//   0x6b44: 9400094f  bl         #0x9080
//   0x6b48: 350002a0  cbnz       w0, #0x6b9c
//   0x6b4c: a94023e9  ldp        x9, x8, [sp]
//   0x6b50: eb08013f  cmp        x9, x8
//   0x6b54: 54000242  b.hs       #0x6b9c
//   0x6b58: 910003e1  mov        x1, sp
//   0x6b5c: 528000e0  mov        w0, #7
//   0x6b60: f90003e8  str        x8, [sp]
//   0x6b64: 9400094b  bl         #0x9090
//   0x6b68: aa1303e0  mov        x0, x19
//   0x6b6c: 2a1503e1  mov        w1, w21
//   0x6b70: 2a1403e2  mov        w2, w20
//   0x6b74: b90002df  str        wzr, [x22]
//   0x6b78: 940008ee  bl         #0x8f30
//   0x6b7c: 3100041f  cmn        w0, #1
//   0x6b80: 540000c1  b.ne       #0x6b98
//   0x6b84: b94002c8  ldr        w8, [x22]
//   0x6b88: 7100111f  cmp        w8, #4
//   0x6b8c: 54fffee0  b.eq       #0x6b68
//   0x6b90: 12800017  mov        w23, #-1
//   0x6b94: 14000002  b          #0x6b9c
//   0x6b98: 2a0003f7  mov        w23, w0
//   0x6b9c: 2a1703e0  mov        w0, w23
//   0x6ba0: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x6ba4: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x6ba8: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x6bac: f94013f7  ldr        x23, [sp, #0x20]
//   0x6bb0: 910143ff  add        sp, sp, #0x50
//   0x6bb4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[37] XasanFde_6bb8 (0x6bb8..0x6d00, 328 bytes, 82 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x6bb8..0x6d00
// ----------------------------------------------------------------------------
//   0x6bb8: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x6bbc: f9000bfc  str        x28, [sp, #0x10]
//   0x6bc0: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x6bc4: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x6bc8: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x6bcc: 910003fd  mov        x29, sp
//   0x6bd0: d11043ff  sub        sp, sp, #0x410
//   0x6bd4: d53bd058  mrs        x24, tpidr_el0
//   0x6bd8: 12800015  mov        w21, #-1
//   0x6bdc: f9401708  ldr        x8, [x24, #0x28]
//   0x6be0: f81f83a8  stur       x8, [x29, #-8]
//   0x6be4: b40006c0  cbz        x0, #0x6cbc
//   0x6be8: aa0103f4  mov        x20, x1
//   0x6bec: b4000681  cbz        x1, #0x6cbc
//   0x6bf0: 2a1f03e1  mov        w1, wzr
//   0x6bf4: 97ffffb2  bl         #0x6abc
//   0x6bf8: 2a0003f3  mov        w19, w0
//   0x6bfc: aa1403e0  mov        x0, x20
//   0x6c00: 52800801  mov        w1, #0x40
//   0x6c04: 97ffffae  bl         #0x6abc
//   0x6c08: 2a0003f4  mov        w20, w0
//   0x6c0c: 37f80480  tbnz       w0, #0x1f, #0x6c9c
//   0x6c10: 37f80473  tbnz       w19, #0x1f, #0x6c9c
//   0x6c14: 9400082f  bl         #0x8cd0
//   0x6c18: aa0003f5  mov        x21, x0
//   0x6c1c: 14000004  b          #0x6c2c
//   0x6c20: b94002a8  ldr        w8, [x21]
//   0x6c24: 7100111f  cmp        w8, #4
//   0x6c28: 54000621  b.ne       #0x6cec
//   0x6c2c: 910023e1  add        x1, sp, #8
//   0x6c30: 2a1303e0  mov        w0, w19
//   0x6c34: 52808002  mov        w2, #0x400
//   0x6c38: b90002bf  str        wzr, [x21]
//   0x6c3c: 94000901  bl         #0x9040
//   0x6c40: b100041f  cmn        x0, #1
//   0x6c44: 54fffee0  b.eq       #0x6c20
//   0x6c48: aa0003f6  mov        x22, x0
//   0x6c4c: f100041f  cmp        x0, #1
//   0x6c50: 540004eb  b.lt       #0x6cec
//   0x6c54: 910023f7  add        x23, sp, #8
//   0x6c58: 14000005  b          #0x6c6c
//   0x6c5c: aa1f03e0  mov        x0, xzr
//   0x6c60: eb0002d6  subs       x22, x22, x0
//   0x6c64: 8b0002f7  add        x23, x23, x0
//   0x6c68: 54fffe20  b.eq       #0x6c2c
//   0x6c6c: 2a1403e0  mov        w0, w20
//   0x6c70: aa1703e1  mov        x1, x23
//   0x6c74: aa1603e2  mov        x2, x22
//   0x6c78: b90002bf  str        wzr, [x21]
//   0x6c7c: 940008c5  bl         #0x8f90
//   0x6c80: f100001f  cmp        x0, #0
//   0x6c84: 54fffeec  b.gt       #0x6c60
//   0x6c88: b6f80080  tbz        x0, #0x3f, #0x6c98
//   0x6c8c: b94002a8  ldr        w8, [x21]
//   0x6c90: 7100111f  cmp        w8, #4
//   0x6c94: 54fffe40  b.eq       #0x6c5c
//   0x6c98: 12800015  mov        w21, #-1
//   0x6c9c: 7100067f  cmp        w19, #1
//   0x6ca0: 5400006b  b.lt       #0x6cac
//   0x6ca4: 2a1303e0  mov        w0, w19
//   0x6ca8: 940008ea  bl         #0x9050
//   0x6cac: 7100069f  cmp        w20, #1
//   0x6cb0: 5400006b  b.lt       #0x6cbc
//   0x6cb4: 2a1403e0  mov        w0, w20
//   0x6cb8: 940008e6  bl         #0x9050
//   0x6cbc: f9401708  ldr        x8, [x24, #0x28]
//   0x6cc0: f85f83a9  ldur       x9, [x29, #-8]
//   0x6cc4: eb09011f  cmp        x8, x9
//   0x6cc8: 540001a1  b.ne       #0x6cfc
//   0x6ccc: 2a1503e0  mov        w0, w21
//   0x6cd0: 911043ff  add        sp, sp, #0x410
//   0x6cd4: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x6cd8: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x6cdc: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x6ce0: f9400bfc  ldr        x28, [sp, #0x10]
//   0x6ce4: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x6ce8: d65f03c0  ret        
//   0x6cec: 2a1f03f5  mov        w21, wzr
//   0x6cf0: 7100067f  cmp        w19, #1
//   0x6cf4: 54fffd8a  b.ge       #0x6ca4
//   0x6cf8: 17ffffed  b          #0x6cac
//   0x6cfc: 9400082d  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[38] XasanFde_6d00 (0x6d00..0x6d68, 104 bytes, 26 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x6d00..0x6d68
// ----------------------------------------------------------------------------
//   0x6d00: d10403ff  sub        sp, sp, #0x100
//   0x6d04: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x6d08: 9103c3fd  add        x29, sp, #0xf0
//   0x6d0c: d101a3a8  sub        x8, x29, #0x68
//   0x6d10: 928004ea  mov        x10, #-0x28
//   0x6d14: 910003eb  mov        x11, sp
//   0x6d18: 9100a108  add        x8, x8, #0x28
//   0x6d1c: 910043a9  add        x9, x29, #0x10
//   0x6d20: f2dff00a  movk       x10, #0xff80, lsl #32
//   0x6d24: 9102016b  add        x11, x11, #0x80
//   0x6d28: a93993a3  stp        x3, x4, [x29, #-0x68]
//   0x6d2c: ad0007e0  stp        q0, q1, [sp]
//   0x6d30: d10103a3  sub        x3, x29, #0x40
//   0x6d34: a93e23a9  stp        x9, x8, [x29, #-0x20]
//   0x6d38: a93f2bab  stp        x11, x10, [x29, #-0x10]
//   0x6d3c: ad7f07a0  ldp        q0, q1, [x29, #-0x20]
//   0x6d40: a93a9ba5  stp        x5, x6, [x29, #-0x58]
//   0x6d44: f81b83a7  stur       x7, [x29, #-0x48]
//   0x6d48: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x6d4c: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x6d50: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x6d54: ad3e07a0  stp        q0, q1, [x29, #-0x40]
//   0x6d58: 94000004  bl         #0x6d68
//   0x6d5c: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x6d60: 910403ff  add        sp, sp, #0x100
//   0x6d64: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[39] XasanFormatCrashMetadata_6d68 (0x6d68..0x76e4, 2428 bytes, 607 instructions)
// Summary / Tóm tắt: Formats allocation/deallocation backtraces & slot metadata (@ 0x6d68..0x76e4)
// ----------------------------------------------------------------------------
//   0x6d68: d103c3ff  sub        sp, sp, #0xf0
//   0x6d6c: a9097bfd  stp        x29, x30, [sp, #0x90]
//   0x6d70: a90a6ffc  stp        x28, x27, [sp, #0xa0]
//   0x6d74: a90b67fa  stp        x26, x25, [sp, #0xb0]
//   0x6d78: a90c5ff8  stp        x24, x23, [sp, #0xc0]
//   0x6d7c: a90d57f6  stp        x22, x21, [sp, #0xd0]
//   0x6d80: a90e4ff4  stp        x20, x19, [sp, #0xe0]
//   0x6d84: 910243fd  add        x29, sp, #0x90
//   0x6d88: d53bd05b  mrs        x27, tpidr_el0
//   0x6d8c: aa0203f6  mov        x22, x2
//   0x6d90: aa0103f5  mov        x21, x1
//   0x6d94: f9401768  ldr        x8, [x27, #0x28]
//   0x6d98: aa0003f4  mov        x20, x0
//   0x6d9c: f81f83a8  stur       x8, [x29, #-8]
//   0x6da0: b4000041  cbz        x1, #0x6da8
//   0x6da4: 3900029f  strb       wzr, [x20]
//   0x6da8: f9400068  ldr        x8, [x3]
//   0x6dac: d100a3b8  sub        x24, x29, #0x28
//   0x6db0: b2400709  orr        x9, x24, #3
//   0x6db4: aa1f03f3  mov        x19, xzr
//   0x6db8: 2a1f03fa  mov        w26, wzr
//   0x6dbc: 910006dc  add        x28, x22, #1
//   0x6dc0: f81c03a8  stur       x8, [x29, #-0x40]
//   0x6dc4: f9400468  ldr        x8, [x3, #8]
//   0x6dc8: 5280014c  mov        w12, #0xa
//   0x6dcc: d2c0002d  mov        x13, #0x100000000
//   0x6dd0: f90017e8  str        x8, [sp, #0x28]
//   0x6dd4: b9401868  ldr        w8, [x3, #0x18]
//   0x6dd8: b81bc3a8  stur       w8, [x29, #-0x44]
//   0x6ddc: 92800048  mov        x8, #-3
//   0x6de0: 8a380108  bic        x8, x8, x24
//   0x6de4: f90013e8  str        x8, [sp, #0x20]
//   0x6de8: 91007f08  add        x8, x24, #0x1f
//   0x6dec: a900a7e8  stp        x8, x9, [sp, #8]
//   0x6df0: aa3803e8  mvn        x8, x24
//   0x6df4: f9000fe8  str        x8, [sp, #0x18]
//   0x6df8: 93407f4a  sxtw       x10, w26
//   0x6dfc: aa1f03e9  mov        x9, xzr
//   0x6e00: 2a1a03e8  mov        w8, w26
//   0x6e04: 8b0a02cb  add        x11, x22, x10
//   0x6e08: 38696979  ldrb       w25, [x11, x9]
//   0x6e0c: 340000d9  cbz        w25, #0x6e24
//   0x6e10: 7100973f  cmp        w25, #0x25
//   0x6e14: 54000080  b.eq       #0x6e24
//   0x6e18: 91000529  add        x9, x9, #1
//   0x6e1c: 38696979  ldrb       w25, [x11, x9]
//   0x6e20: 35ffff99  cbnz       w25, #0x6e10
//   0x6e24: 8b09011a  add        x26, x8, x9
//   0x6e28: 6b1a015f  cmp        w10, w26
//   0x6e2c: 540003ca  b.ge       #0x6ea4
//   0x6e30: 8b0a02d7  add        x23, x22, x10
//   0x6e34: 37f80049  tbnz       w9, #0x1f, #0x6e3c
//   0x6e38: 14000006  b          #0x6e50
//   0x6e3c: aa1703e0  mov        x0, x23
//   0x6e40: 94000858  bl         #0x8fa0
//   0x6e44: d2c0002d  mov        x13, #0x100000000
//   0x6e48: 5280014c  mov        w12, #0xa
//   0x6e4c: 2a0003e9  mov        w9, w0
//   0x6e50: 93407d28  sxtw       x8, w9
//   0x6e54: f10006bf  cmp        x21, #1
//   0x6e58: 8b080273  add        x19, x19, x8
//   0x6e5c: 54000068  b.hi       #0x6e68
//   0x6e60: 2a1a03e8  mov        w8, w26
//   0x6e64: 14000010  b          #0x6ea4
//   0x6e68: 510006a9  sub        w9, w21, #1
//   0x6e6c: eb0802bf  cmp        x21, x8
//   0x6e70: 1a898108  csel       w8, w8, w9, hi
//   0x6e74: aa1403e0  mov        x0, x20
//   0x6e78: 93407d18  sxtw       x24, w8
//   0x6e7c: aa1703e1  mov        x1, x23
//   0x6e80: aa1803e2  mov        x2, x24
//   0x6e84: 94000823  bl         #0x8f10
//   0x6e88: d2c0002d  mov        x13, #0x100000000
//   0x6e8c: 5280014c  mov        w12, #0xa
//   0x6e90: 8b180294  add        x20, x20, x24
//   0x6e94: cb1802b5  sub        x21, x21, x24
//   0x6e98: d100a3b8  sub        x24, x29, #0x28
//   0x6e9c: 2a1a03e8  mov        w8, w26
//   0x6ea0: 3900029f  strb       wzr, [x20]
//   0x6ea4: 34004019  cbz        w25, #0x76a4
//   0x6ea8: 2a1f03e0  mov        w0, wzr
//   0x6eac: 2a1f03ef  mov        w15, wzr
//   0x6eb0: 2a1f03f1  mov        w17, wzr
//   0x6eb4: 11000509  add        w9, w8, #1
//   0x6eb8: d503201f  nop        
//   0x6ebc: 50fddd2e  adr        x14, #0x2a62
//   0x6ec0: 14000002  b          #0x6ec8
//   0x6ec4: 5280002f  mov        w15, #1
//   0x6ec8: 93407d3a  sxtw       x26, w9
//   0x6ecc: 91000749  add        x9, x26, #1
//   0x6ed0: 387a6ac8  ldrb       w8, [x22, x26]
//   0x6ed4: 7100c11f  cmp        w8, #0x30
//   0x6ed8: 54000388  b.hi       #0x6f48
//   0x6edc: 10ffff4a  adr        x10, #0x6ec4
//   0x6ee0: 786879cb  ldrh       w11, [x14, x8, lsl #1]
//   0x6ee4: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x6ee8: d61f0140  br         x10
//   0x6eec: 387a6b88  ldrb       w8, [x28, x26]
//   0x6ef0: 9100075a  add        x26, x26, #1
//   0x6ef4: 7100c11f  cmp        w8, #0x30
//   0x6ef8: 54ffffa0  b.eq       #0x6eec
//   0x6efc: 7100a91f  cmp        w8, #0x2a
//   0x6f00: 540000ac  b.gt       #0x6f14
//   0x6f04: 34003c68  cbz        w8, #0x7690
//   0x6f08: 7100811f  cmp        w8, #0x20
//   0x6f0c: 54000120  b.eq       #0x6f30
//   0x6f10: 1400000c  b          #0x6f40
//   0x6f14: 7100ad1f  cmp        w8, #0x2b
//   0x6f18: 540000c0  b.eq       #0x6f30
//   0x6f1c: 7100b51f  cmp        w8, #0x2d
//   0x6f20: 54000101  b.ne       #0x6f40
//   0x6f24: 91000749  add        x9, x26, #1
//   0x6f28: 52800031  mov        w17, #1
//   0x6f2c: 17ffffe6  b          #0x6ec4
//   0x6f30: 91000749  add        x9, x26, #1
//   0x6f34: 52800031  mov        w17, #1
//   0x6f38: 2a0803e0  mov        w0, w8
//   0x6f3c: 17ffffe3  b          #0x6ec8
//   0x6f40: 91000749  add        x9, x26, #1
//   0x6f44: 52800031  mov        w17, #1
//   0x6f48: 5100c10a  sub        w10, w8, #0x30
//   0x6f4c: f9001ffc  str        x28, [sp, #0x38]
//   0x6f50: 7100255f  cmp        w10, #9
//   0x6f54: 54000248  b.hi       #0x6f9c
//   0x6f58: b2607fe8  mov        x8, #-0x100000000
//   0x6f5c: 2a1f03e9  mov        w9, wzr
//   0x6f60: 8b1a8108  add        x8, x8, x26, lsl #32
//   0x6f64: 387a6aca  ldrb       w10, [x22, x26]
//   0x6f68: 2a0903fc  mov        w28, w9
//   0x6f6c: 8b0d0108  add        x8, x8, x13
//   0x6f70: 9100075a  add        x26, x26, #1
//   0x6f74: 5100c14a  sub        w10, w10, #0x30
//   0x6f78: 1b0c2929  madd       w9, w9, w12, w10
//   0x6f7c: 7100295f  cmp        w10, #0xa
//   0x6f80: 54ffff23  b.lo       #0x6f64
//   0x6f84: 9360fd08  asr        x8, x8, #0x20
//   0x6f88: 38686ac8  ldrb       w8, [x22, x8]
//   0x6f8c: 7100b91f  cmp        w8, #0x2e
//   0x6f90: 540000e0  b.eq       #0x6fac
//   0x6f94: 12800019  mov        w25, #-1
//   0x6f98: 14000015  b          #0x6fec
//   0x6f9c: 1280001c  mov        w28, #-1
//   0x6fa0: 2a0903fa  mov        w26, w9
//   0x6fa4: 7100b91f  cmp        w8, #0x2e
//   0x6fa8: 54ffff61  b.ne       #0x6f94
//   0x6fac: 2a1a03e9  mov        w9, w26
//   0x6fb0: b2607feb  mov        x11, #-0x100000000
//   0x6fb4: 93407d2a  sxtw       x10, w9
//   0x6fb8: 2a1f03e8  mov        w8, wzr
//   0x6fbc: 8b0a02c9  add        x9, x22, x10
//   0x6fc0: 8b0a816a  add        x10, x11, x10, lsl #32
//   0x6fc4: 3840152b  ldrb       w11, [x9], #1
//   0x6fc8: 2a0803f9  mov        w25, w8
//   0x6fcc: 8b0d014a  add        x10, x10, x13
//   0x6fd0: 1100075a  add        w26, w26, #1
//   0x6fd4: 5100c16b  sub        w11, w11, #0x30
//   0x6fd8: 1b0c2d08  madd       w8, w8, w12, w11
//   0x6fdc: 7100297f  cmp        w11, #0xa
//   0x6fe0: 54ffff23  b.lo       #0x6fc4
//   0x6fe4: 9360fd48  asr        x8, x10, #0x20
//   0x6fe8: 38686ac8  ldrb       w8, [x22, x8]
//   0x6fec: 5101a109  sub        w9, w8, #0x68
//   0x6ff0: 1389050b  extr       w11, w8, w9, #1
//   0x6ff4: 52800089  mov        w9, #4
//   0x6ff8: 7100257f  cmp        w11, #9
//   0x6ffc: 540002c8  b.hi       #0x7054
//   0x7000: f0ffffce  adrp       x14, #0x2000
//   0x7004: 912b11ce  add        x14, x14, #0xac4
//   0x7008: 5280010a  mov        w10, #8
//   0x700c: 1000008c  adr        x12, #0x701c
//   0x7010: 386b69cd  ldrb       w13, [x14, x11]
//   0x7014: 8b0d098c  add        x12, x12, x13, lsl #2
//   0x7018: d61f0180  br         x12
//   0x701c: 387acac8  ldrb       w8, [x22, w26, sxtw]
//   0x7020: 7101a11f  cmp        w8, #0x68
//   0x7024: 52800028  mov        w8, #1
//   0x7028: 1a9a175a  cinc       w26, w26, eq
//   0x702c: 9a88050a  cinc       x10, x8, ne
//   0x7030: 14000005  b          #0x7044
//   0x7034: 387acac8  ldrb       w8, [x22, w26, sxtw]
//   0x7038: 5280010a  mov        w10, #8
//   0x703c: 7101b11f  cmp        w8, #0x6c
//   0x7040: 1a9a175a  cinc       w26, w26, eq
//   0x7044: 11000749  add        w9, w26, #1
//   0x7048: 387acac8  ldrb       w8, [x22, w26, sxtw]
//   0x704c: 2a0903fa  mov        w26, w9
//   0x7050: aa0a03e9  mov        x9, x10
//   0x7054: 5100950b  sub        w11, w8, #0x25
//   0x7058: 71014d7f  cmp        w11, #0x53
//   0x705c: 54003248  b.hi       #0x76a4
//   0x7060: f0ffffce  adrp       x14, #0x2000
//   0x7064: 912b39ce  add        x14, x14, #0xace
//   0x7068: 5280002a  mov        w10, #1
//   0x706c: 100000ec  adr        x12, #0x7088
//   0x7070: 786b79cd  ldrh       w13, [x14, x11, lsl #1]
//   0x7074: 8b0d098c  add        x12, x12, x13, lsl #2
//   0x7078: b9004bef  str        w15, [sp, #0x48]
//   0x707c: f81c83bb  stur       x27, [x29, #-0x38]
//   0x7080: b90047f1  str        w17, [sp, #0x44]
//   0x7084: d61f0180  br         x12
//   0x7088: 7101bd1f  cmp        w8, #0x6f
//   0x708c: 1a9f17ea  cset       w10, eq
//   0x7090: d100052b  sub        x11, x9, #1
//   0x7094: f1001d7f  cmp        x11, #7
//   0x7098: 54003068  b.hi       #0x76a4
//   0x709c: f0ffffce  adrp       x14, #0x2000
//   0x70a0: 912dd9ce  add        x14, x14, #0xb76
//   0x70a4: 1000008c  adr        x12, #0x70b4
//   0x70a8: 786b79cd  ldrh       w13, [x14, x11, lsl #1]
//   0x70ac: 8b0d098c  add        x12, x12, x13, lsl #2
//   0x70b0: d61f0180  br         x12
//   0x70b4: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x70b8: b85bc3ad  ldur       w13, [x29, #-0x44]
//   0x70bc: 37f804cd  tbnz       w13, #0x1f, #0x7154
//   0x70c0: 2a0d03ec  mov        w12, w13
//   0x70c4: 1400002d  b          #0x7178
//   0x70c8: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x70cc: b85bc3ad  ldur       w13, [x29, #-0x44]
//   0x70d0: 37f805ad  tbnz       w13, #0x1f, #0x7184
//   0x70d4: 2a0d03ec  mov        w12, w13
//   0x70d8: 14000034  b          #0x71a8
//   0x70dc: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x70e0: b85bc3ad  ldur       w13, [x29, #-0x44]
//   0x70e4: 37f8068d  tbnz       w13, #0x1f, #0x71b4
//   0x70e8: 2a0d03ec  mov        w12, w13
//   0x70ec: 1400003a  b          #0x71d4
//   0x70f0: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x70f4: b85bc3ad  ldur       w13, [x29, #-0x44]
//   0x70f8: 37f8074d  tbnz       w13, #0x1f, #0x71e0
//   0x70fc: 2a0d03ec  mov        w12, w13
//   0x7100: 14000040  b          #0x7200
//   0x7104: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x7108: b85bc3aa  ldur       w10, [x29, #-0x44]
//   0x710c: 37f8124a  tbnz       w10, #0x1f, #0x7354
//   0x7110: 2a0a03e8  mov        w8, w10
//   0x7114: 14000098  b          #0x7374
//   0x7118: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x711c: b85bc3aa  ldur       w10, [x29, #-0x44]
//   0x7120: 37f8160a  tbnz       w10, #0x1f, #0x73e0
//   0x7124: 2a0a03e8  mov        w8, w10
//   0x7128: 140000b7  b          #0x7404
//   0x712c: 2a0003fb  mov        w27, w0
//   0x7130: d100a3b7  sub        x23, x29, #0x28
//   0x7134: 528004a8  mov        w8, #0x25
//   0x7138: 781d83a8  sturh      w8, [x29, #-0x28]
//   0x713c: 140000eb  b          #0x74e8
//   0x7140: f85c03ab  ldur       x11, [x29, #-0x40]
//   0x7144: b85bc3aa  ldur       w10, [x29, #-0x44]
//   0x7148: 37f816ea  tbnz       w10, #0x1f, #0x7424
//   0x714c: 2a0a03e8  mov        w8, w10
//   0x7150: 140000be  b          #0x7448
//   0x7154: 110021ac  add        w12, w13, #8
//   0x7158: 310021bf  cmn        w13, #8
//   0x715c: 540000e8  b.hi       #0x7178
//   0x7160: 2a0d03ee  mov        w14, w13
//   0x7164: aa0b03ed  mov        x13, x11
//   0x7168: f94017eb  ldr        x11, [sp, #0x28]
//   0x716c: 8b2ec16b  add        x11, x11, w14, sxtw
//   0x7170: 3940016b  ldrb       w11, [x11]
//   0x7174: 14000025  b          #0x7208
//   0x7178: 9100216d  add        x13, x11, #8
//   0x717c: 3940016b  ldrb       w11, [x11]
//   0x7180: 14000022  b          #0x7208
//   0x7184: 110021ac  add        w12, w13, #8
//   0x7188: 310021bf  cmn        w13, #8
//   0x718c: 540000e8  b.hi       #0x71a8
//   0x7190: 2a0d03ee  mov        w14, w13
//   0x7194: aa0b03ed  mov        x13, x11
//   0x7198: f94017eb  ldr        x11, [sp, #0x28]
//   0x719c: 8b2ec16b  add        x11, x11, w14, sxtw
//   0x71a0: 7940016b  ldrh       w11, [x11]
//   0x71a4: 14000019  b          #0x7208
//   0x71a8: 9100216d  add        x13, x11, #8
//   0x71ac: 7940016b  ldrh       w11, [x11]
//   0x71b0: 14000016  b          #0x7208
//   0x71b4: 110021ac  add        w12, w13, #8
//   0x71b8: 310021bf  cmn        w13, #8
//   0x71bc: 540000c8  b.hi       #0x71d4
//   0x71c0: 2a0d03ee  mov        w14, w13
//   0x71c4: aa0b03ed  mov        x13, x11
//   0x71c8: f94017eb  ldr        x11, [sp, #0x28]
//   0x71cc: 8b2ec16b  add        x11, x11, w14, sxtw
//   0x71d0: 14000002  b          #0x71d8
//   0x71d4: 9100216d  add        x13, x11, #8
//   0x71d8: f940016b  ldr        x11, [x11]
//   0x71dc: 1400000b  b          #0x7208
//   0x71e0: 110021ac  add        w12, w13, #8
//   0x71e4: 310021bf  cmn        w13, #8
//   0x71e8: 540000c8  b.hi       #0x7200
//   0x71ec: 2a0d03ee  mov        w14, w13
//   0x71f0: aa0b03ed  mov        x13, x11
//   0x71f4: f94017eb  ldr        x11, [sp, #0x28]
//   0x71f8: 8b2ec16b  add        x11, x11, w14, sxtw
//   0x71fc: 14000002  b          #0x7204
//   0x7200: 9100216d  add        x13, x11, #8
//   0x7204: b940016b  ldr        w11, [x11]
//   0x7208: b81bc3ac  stur       w12, [x29, #-0x44]
//   0x720c: f81c03ad  stur       x13, [x29, #-0x40]
//   0x7210: 340000aa  cbz        w10, #0x7224
//   0x7214: 531d7129  lsl        w9, w9, #3
//   0x7218: 4b0903e9  neg        w9, w9
//   0x721c: 9ac9216a  lsl        x10, x11, x9
//   0x7220: 9ac9294b  asr        x11, x10, x9
//   0x7224: 5101910a  sub        w10, w8, #0x64
//   0x7228: 52800209  mov        w9, #0x10
//   0x722c: 7100315f  cmp        w10, #0xc
//   0x7230: 1a9f27ec  cset       w12, lo
//   0x7234: 7101611f  cmp        w8, #0x58
//   0x7238: 54000100  b.eq       #0x7258
//   0x723c: 7101e11f  cmp        w8, #0x78
//   0x7240: 540000c0  b.eq       #0x7258
//   0x7244: 7101bd1f  cmp        w8, #0x6f
//   0x7248: 54000061  b.ne       #0x7254
//   0x724c: 52800109  mov        w9, #8
//   0x7250: 14000002  b          #0x7258
//   0x7254: 52800149  mov        w9, #0xa
//   0x7258: 5281042d  mov        w13, #0x821
//   0x725c: f100017f  cmp        x11, #0
//   0x7260: 1aca25aa  lsr        w10, w13, w10
//   0x7264: 0a0a018a  and        w10, w12, w10
//   0x7268: 5200014a  eor        w10, w10, #1
//   0x726c: 1a9fb54a  csinc      w10, w10, wzr, lt
//   0x7270: 370000ea  tbnz       w10, #0, #0x728c
//   0x7274: 528005ad  mov        w13, #0x2d
//   0x7278: 5280002c  mov        w12, #1
//   0x727c: cb0b03eb  neg        x11, x11
//   0x7280: aa0c03ea  mov        x10, x12
//   0x7284: 381d83ad  sturb      w13, [x29, #-0x28]
//   0x7288: 14000004  b          #0x7298
//   0x728c: aa1f03ea  mov        x10, xzr
//   0x7290: b40005eb  cbz        x11, #0x734c
//   0x7294: aa0a03ec  mov        x12, x10
//   0x7298: 7101611f  cmp        w8, #0x58
//   0x729c: 52800ae8  mov        w8, #0x57
//   0x72a0: 528006ed  mov        w13, #0x37
//   0x72a4: 1a8801a8  csel       w8, w13, w8, eq
//   0x72a8: 14000004  b          #0x72b8
//   0x72ac: eb09017f  cmp        x11, x9
//   0x72b0: aa0d03eb  mov        x11, x13
//   0x72b4: 540001a3  b.lo       #0x72e8
//   0x72b8: 9ac9096d  udiv       x13, x11, x9
//   0x72bc: f1007d5f  cmp        x10, #0x1f
//   0x72c0: 54ffff60  b.eq       #0x72ac
//   0x72c4: 1b09adae  msub       w14, w13, w9, w11
//   0x72c8: 5280060f  mov        w15, #0x30
//   0x72cc: 91000550  add        x16, x10, #1
//   0x72d0: 710029df  cmp        w14, #0xa
//   0x72d4: 1a8831ef  csel       w15, w15, w8, lo
//   0x72d8: 0b0e01ee  add        w14, w15, w14
//   0x72dc: 382a6b0e  strb       w14, [x24, x10]
//   0x72e0: aa1003ea  mov        x10, x16
//   0x72e4: 17fffff2  b          #0x72ac
//   0x72e8: aa0c0308  orr        x8, x24, x12
//   0x72ec: 8b0a030b  add        x11, x24, x10
//   0x72f0: f1007d5f  cmp        x10, #0x1f
//   0x72f4: 540000c0  b.eq       #0x730c
//   0x72f8: eb08017f  cmp        x11, x8
//   0x72fc: 54000081  b.ne       #0x730c
//   0x7300: aa0803eb  mov        x11, x8
//   0x7304: 52800609  mov        w9, #0x30
//   0x7308: 38001569  strb       w9, [x11], #1
//   0x730c: aa2803e9  mvn        x9, x8
//   0x7310: 2a0003fb  mov        w27, w0
//   0x7314: ab090169  adds       x9, x11, x9
//   0x7318: 3900017f  strb       wzr, [x11]
//   0x731c: 54000140  b.eq       #0x7344
//   0x7320: aa1f03ea  mov        x10, xzr
//   0x7324: 3869690b  ldrb       w11, [x8, x9]
//   0x7328: 386a690c  ldrb       w12, [x8, x10]
//   0x732c: 382a690b  strb       w11, [x8, x10]
//   0x7330: 9100054a  add        x10, x10, #1
//   0x7334: 3829690c  strb       w12, [x8, x9]
//   0x7338: d1000529  sub        x9, x9, #1
//   0x733c: eb09015f  cmp        x10, x9
//   0x7340: 54ffff23  b.lo       #0x7324
//   0x7344: d100a3b7  sub        x23, x29, #0x28
//   0x7348: 14000068  b          #0x74e8
//   0x734c: d100a3a8  sub        x8, x29, #0x28
//   0x7350: 17ffffe7  b          #0x72ec
//   0x7354: 11002148  add        w8, w10, #8
//   0x7358: 3100215f  cmn        w10, #8
//   0x735c: 540000c8  b.hi       #0x7374
//   0x7360: f94017e9  ldr        x9, [sp, #0x28]
//   0x7364: 8b2ac12a  add        x10, x9, w10, sxtw
//   0x7368: aa0b03e9  mov        x9, x11
//   0x736c: aa0a03eb  mov        x11, x10
//   0x7370: 14000002  b          #0x7378
//   0x7374: 91002169  add        x9, x11, #8
//   0x7378: f940016a  ldr        x10, [x11]
//   0x737c: 528f060b  mov        w11, #0x7830
//   0x7380: 781d83ab  sturh      w11, [x29, #-0x28]
//   0x7384: b400078a  cbz        x10, #0x7474
//   0x7388: 5280004b  mov        w11, #2
//   0x738c: 1400000d  b          #0x73c0
//   0x7390: 12000d4e  and        w14, w10, #0xf
//   0x7394: 52800aed  mov        w13, #0x57
//   0x7398: 710029df  cmp        w14, #0xa
//   0x739c: 5280060f  mov        w15, #0x30
//   0x73a0: 1a8d31ef  csel       w15, w15, w13, lo
//   0x73a4: 9100056d  add        x13, x11, #1
//   0x73a8: 0b0e01ee  add        w14, w15, w14
//   0x73ac: f100415f  cmp        x10, #0x10
//   0x73b0: aa0c03ea  mov        x10, x12
//   0x73b4: 382b6b0e  strb       w14, [x24, x11]
//   0x73b8: aa0d03eb  mov        x11, x13
//   0x73bc: 54000583  b.lo       #0x746c
//   0x73c0: d344fd4c  lsr        x12, x10, #4
//   0x73c4: f1007d7f  cmp        x11, #0x1f
//   0x73c8: 54fffe41  b.ne       #0x7390
//   0x73cc: f100415f  cmp        x10, #0x10
//   0x73d0: aa0c03ea  mov        x10, x12
//   0x73d4: 54ffff62  b.hs       #0x73c0
//   0x73d8: f94007ea  ldr        x10, [sp, #8]
//   0x73dc: 1400002b  b          #0x7488
//   0x73e0: 11002148  add        w8, w10, #8
//   0x73e4: 3100215f  cmn        w10, #8
//   0x73e8: 540000e8  b.hi       #0x7404
//   0x73ec: f94017e9  ldr        x9, [sp, #0x28]
//   0x73f0: 2a0003fb  mov        w27, w0
//   0x73f4: 8b2ac12a  add        x10, x9, w10, sxtw
//   0x73f8: aa0b03e9  mov        x9, x11
//   0x73fc: aa0a03eb  mov        x11, x10
//   0x7400: 14000003  b          #0x740c
//   0x7404: 2a0003fb  mov        w27, w0
//   0x7408: 91002169  add        x9, x11, #8
//   0x740c: f940016a  ldr        x10, [x11]
//   0x7410: d503201f  nop        
//   0x7414: 30fd4f0b  adr        x11, #0x1df5
//   0x7418: f100015f  cmp        x10, #0
//   0x741c: 9a8a0177  csel       x23, x11, x10, eq
//   0x7420: 14000030  b          #0x74e0
//   0x7424: 11002148  add        w8, w10, #8
//   0x7428: 3100215f  cmn        w10, #8
//   0x742c: 540000e8  b.hi       #0x7448
//   0x7430: f94017e9  ldr        x9, [sp, #0x28]
//   0x7434: 2a0003fb  mov        w27, w0
//   0x7438: 8b2ac12a  add        x10, x9, w10, sxtw
//   0x743c: aa0b03e9  mov        x9, x11
//   0x7440: aa0a03eb  mov        x11, x10
//   0x7444: 14000003  b          #0x7450
//   0x7448: 2a0003fb  mov        w27, w0
//   0x744c: 91002169  add        x9, x11, #8
//   0x7450: b940016a  ldr        w10, [x11]
//   0x7454: d100a3b7  sub        x23, x29, #0x28
//   0x7458: b81bc3a8  stur       w8, [x29, #-0x44]
//   0x745c: f81c03a9  stur       x9, [x29, #-0x40]
//   0x7460: 381d83aa  sturb      w10, [x29, #-0x28]
//   0x7464: 381d93bf  sturb      wzr, [x29, #-0x27]
//   0x7468: 14000020  b          #0x74e8
//   0x746c: f10009bf  cmp        x13, #2
//   0x7470: 540000a1  b.ne       #0x7484
//   0x7474: f9400bea  ldr        x10, [sp, #0x10]
//   0x7478: 5280060b  mov        w11, #0x30
//   0x747c: 381da3ab  sturb      w11, [x29, #-0x26]
//   0x7480: 14000002  b          #0x7488
//   0x7484: 8b0d030a  add        x10, x24, x13
//   0x7488: f94013eb  ldr        x11, [sp, #0x20]
//   0x748c: 2a0003fb  mov        w27, w0
//   0x7490: 3900015f  strb       wzr, [x10]
//   0x7494: ab0b015f  cmn        x10, x11
//   0x7498: 54000220  b.eq       #0x74dc
//   0x749c: f9400feb  ldr        x11, [sp, #0x18]
//   0x74a0: 8b0a016b  add        x11, x11, x10
//   0x74a4: 5280004a  mov        w10, #2
//   0x74a8: d100a3b7  sub        x23, x29, #0x28
//   0x74ac: d100054e  sub        x14, x10, #1
//   0x74b0: 386b6aec  ldrb       w12, [x23, x11]
//   0x74b4: 386a6aed  ldrb       w13, [x23, x10]
//   0x74b8: 382a6aec  strb       w12, [x23, x10]
//   0x74bc: d100056c  sub        x12, x11, #1
//   0x74c0: 382b6aed  strb       w13, [x23, x11]
//   0x74c4: d1000d6d  sub        x13, x11, #3
//   0x74c8: 9100054a  add        x10, x10, #1
//   0x74cc: aa0c03eb  mov        x11, x12
//   0x74d0: eb0d01df  cmp        x14, x13
//   0x74d4: 54fffea3  b.lo       #0x74a8
//   0x74d8: 14000002  b          #0x74e0
//   0x74dc: d100a3b7  sub        x23, x29, #0x28
//   0x74e0: b81bc3a8  stur       w8, [x29, #-0x44]
//   0x74e4: f81c03a9  stur       x9, [x29, #-0x40]
//   0x74e8: aa1703e0  mov        x0, x23
//   0x74ec: 940006ad  bl         #0x8fa0
//   0x74f0: 72001f7f  tst        w27, #0xff
//   0x74f4: 54000f21  b.ne       #0x76d8
//   0x74f8: f85c83bb  ldur       x27, [x29, #-0x38]
//   0x74fc: 3100073f  cmn        w25, #1
//   0x7500: 54000d21  b.ne       #0x76a4
//   0x7504: aa0003f8  mov        x24, x0
//   0x7508: f9001bf6  str        x22, [sp, #0x30]
//   0x750c: 6b18039b  subs       w27, w28, w24
//   0x7510: 5400016d  b.le       #0x753c
//   0x7514: b9404be8  ldr        w8, [sp, #0x48]
//   0x7518: 35000128  cbnz       w8, #0x753c
//   0x751c: b94047e8  ldr        w8, [sp, #0x44]
//   0x7520: b203c3e9  mov        x9, #0x2020202020202020
//   0x7524: 7100011f  cmp        w8, #0
//   0x7528: b204c7e8  mov        x8, #0x3030303030303030
//   0x752c: 9a880128  csel       x8, x9, x8, eq
//   0x7530: 7100077f  cmp        w27, #1
//   0x7534: f81d03a8  stur       x8, [x29, #-0x30]
//   0x7538: 5400056a  b.ge       #0x75e4
//   0x753c: 2a1803e0  mov        w0, w24
//   0x7540: f85c83bb  ldur       x27, [x29, #-0x38]
//   0x7544: 36f80078  tbz        w24, #0x1f, #0x7550
//   0x7548: aa1703e0  mov        x0, x23
//   0x754c: 94000695  bl         #0x8fa0
//   0x7550: 93407c16  sxtw       x22, w0
//   0x7554: f1000abf  cmp        x21, #2
//   0x7558: 54000183  b.lo       #0x7588
//   0x755c: 510006a8  sub        w8, w21, #1
//   0x7560: eb1602bf  cmp        x21, x22
//   0x7564: 1a8882c8  csel       w8, w22, w8, hi
//   0x7568: aa1403e0  mov        x0, x20
//   0x756c: 93407d19  sxtw       x25, w8
//   0x7570: aa1703e1  mov        x1, x23
//   0x7574: aa1903e2  mov        x2, x25
//   0x7578: 94000666  bl         #0x8f10
//   0x757c: 8b190294  add        x20, x20, x25
//   0x7580: cb1902b5  sub        x21, x21, x25
//   0x7584: 3900029f  strb       wzr, [x20]
//   0x7588: 2948a3e9  ldp        w9, w8, [sp, #0x44]
//   0x758c: 5280014c  mov        w12, #0xa
//   0x7590: d2c0002d  mov        x13, #0x100000000
//   0x7594: 8b160273  add        x19, x19, x22
//   0x7598: 6b180398  subs       w24, w28, w24
//   0x759c: 5400074d  b.le       #0x7684
//   0x75a0: a94373f6  ldp        x22, x28, [sp, #0x30]
//   0x75a4: 34000148  cbz        w8, #0x75cc
//   0x75a8: 7100013f  cmp        w9, #0
//   0x75ac: b204c7e8  mov        x8, #0x3030303030303030
//   0x75b0: b203c3e9  mov        x9, #0x2020202020202020
//   0x75b4: aa1603f9  mov        x25, x22
//   0x75b8: 9a880128  csel       x8, x9, x8, eq
//   0x75bc: 7100071f  cmp        w24, #1
//   0x75c0: f81d03a8  stur       x8, [x29, #-0x30]
//   0x75c4: 540003aa  b.ge       #0x7638
//   0x75c8: aa1903f6  mov        x22, x25
//   0x75cc: d100a3b8  sub        x24, x29, #0x28
//   0x75d0: 17fffe0a  b          #0x6df8
//   0x75d4: 8b160273  add        x19, x19, x22
//   0x75d8: 4b16037b  sub        w27, w27, w22
//   0x75dc: 7100037f  cmp        w27, #0
//   0x75e0: 54fffaed  b.le       #0x753c
//   0x75e4: 7100237f  cmp        w27, #8
//   0x75e8: 52800108  mov        w8, #8
//   0x75ec: 1a88b376  csel       w22, w27, w8, lt
//   0x75f0: f1000abf  cmp        x21, #2
//   0x75f4: 54ffff03  b.lo       #0x75d4
//   0x75f8: 510006a8  sub        w8, w21, #1
//   0x75fc: eb1602bf  cmp        x21, x22
//   0x7600: 1a8882c8  csel       w8, w22, w8, hi
//   0x7604: d100c3a1  sub        x1, x29, #0x30
//   0x7608: 93407d19  sxtw       x25, w8
//   0x760c: aa1403e0  mov        x0, x20
//   0x7610: aa1903e2  mov        x2, x25
//   0x7614: 9400063f  bl         #0x8f10
//   0x7618: 8b190294  add        x20, x20, x25
//   0x761c: cb1902b5  sub        x21, x21, x25
//   0x7620: 3900029f  strb       wzr, [x20]
//   0x7624: 17ffffec  b          #0x75d4
//   0x7628: 8b160273  add        x19, x19, x22
//   0x762c: 4b160318  sub        w24, w24, w22
//   0x7630: 7100031f  cmp        w24, #0
//   0x7634: 54fffcad  b.le       #0x75c8
//   0x7638: 7100231f  cmp        w24, #8
//   0x763c: 52800108  mov        w8, #8
//   0x7640: 1a88b316  csel       w22, w24, w8, lt
//   0x7644: f1000abf  cmp        x21, #2
//   0x7648: 54ffff03  b.lo       #0x7628
//   0x764c: 510006a8  sub        w8, w21, #1
//   0x7650: eb1602bf  cmp        x21, x22
//   0x7654: 1a8882c8  csel       w8, w22, w8, hi
//   0x7658: d100c3a1  sub        x1, x29, #0x30
//   0x765c: 93407d17  sxtw       x23, w8
//   0x7660: aa1403e0  mov        x0, x20
//   0x7664: aa1703e2  mov        x2, x23
//   0x7668: 9400062a  bl         #0x8f10
//   0x766c: d2c0002d  mov        x13, #0x100000000
//   0x7670: 5280014c  mov        w12, #0xa
//   0x7674: 8b170294  add        x20, x20, x23
//   0x7678: cb1702b5  sub        x21, x21, x23
//   0x767c: 3900029f  strb       wzr, [x20]
//   0x7680: 17ffffea  b          #0x7628
//   0x7684: a94373f6  ldp        x22, x28, [sp, #0x30]
//   0x7688: d100a3b8  sub        x24, x29, #0x28
//   0x768c: 17fffddb  b          #0x6df8
//   0x7690: 91000673  add        x19, x19, #1
//   0x7694: f1000abf  cmp        x21, #2
//   0x7698: 54000063  b.lo       #0x76a4
//   0x769c: 528004a8  mov        w8, #0x25
//   0x76a0: 79000288  strh       w8, [x20]
//   0x76a4: f9401768  ldr        x8, [x27, #0x28]
//   0x76a8: f85f83a9  ldur       x9, [x29, #-8]
//   0x76ac: eb09011f  cmp        x8, x9
//   0x76b0: 54000181  b.ne       #0x76e0
//   0x76b4: aa1303e0  mov        x0, x19
//   0x76b8: a94e4ff4  ldp        x20, x19, [sp, #0xe0]
//   0x76bc: a94d57f6  ldp        x22, x21, [sp, #0xd0]
//   0x76c0: a94c5ff8  ldp        x24, x23, [sp, #0xc0]
//   0x76c4: a94b67fa  ldp        x26, x25, [sp, #0xb0]
//   0x76c8: a94a6ffc  ldp        x28, x27, [sp, #0xa0]
//   0x76cc: a9497bfd  ldp        x29, x30, [sp, #0x90]
//   0x76d0: 9103c3ff  add        sp, sp, #0xf0
//   0x76d4: d65f03c0  ret        
//   0x76d8: f85c83bb  ldur       x27, [x29, #-0x38]
//   0x76dc: 17fffff2  b          #0x76a4
//   0x76e0: 940005b4  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[40] XasanFastItoa10_76e4 (0x76e4..0x7778, 148 bytes, 37 instructions)
// Summary / Tóm tắt: Fast signed base-10 integer formatter using magic 0x66666667 (@ 0x76e4..0x7778)
// ----------------------------------------------------------------------------
//   0x76e4: 2a0003e8  mov        w8, w0
//   0x76e8: aa0103e0  mov        x0, x1
//   0x76ec: 37f80068  tbnz       w8, #0x1f, #0x76f8
//   0x76f0: aa0003ea  mov        x10, x0
//   0x76f4: 14000005  b          #0x7708
//   0x76f8: 528005a9  mov        w9, #0x2d
//   0x76fc: aa0003ea  mov        x10, x0
//   0x7700: 4b0803e8  neg        w8, w8
//   0x7704: 38001549  strb       w9, [x10], #1
//   0x7708: 528ccceb  mov        w11, #0x6667
//   0x770c: d1000549  sub        x9, x10, #1
//   0x7710: 72accccb  movk       w11, #0x6666, lsl #16
//   0x7714: 5280014c  mov        w12, #0xa
//   0x7718: 9b2b7d0d  smull      x13, w8, w11
//   0x771c: 1100250f  add        w15, w8, #9
//   0x7720: 710049ff  cmp        w15, #0x12
//   0x7724: d37ffdae  lsr        x14, x13, #0x3f
//   0x7728: 9362fdad  asr        x13, x13, #0x22
//   0x772c: 0b0e01ad  add        w13, w13, w14
//   0x7730: 1b0ca1ae  msub       w14, w13, w12, w8
//   0x7734: 2a0d03e8  mov        w8, w13
//   0x7738: 1100c1ce  add        w14, w14, #0x30
//   0x773c: 38001d2e  strb       w14, [x9, #1]!
//   0x7740: 54fffec8  b.hi       #0x7718
//   0x7744: eb09015f  cmp        x10, x9
//   0x7748: 3900053f  strb       wzr, [x9, #1]
//   0x774c: 54000142  b.hs       #0x7774
//   0x7750: 91000548  add        x8, x10, #1
//   0x7754: 3940012a  ldrb       w10, [x9]
//   0x7758: 9100050c  add        x12, x8, #1
//   0x775c: 385ff10b  ldurb      w11, [x8, #-1]
//   0x7760: 381ff10a  sturb      w10, [x8, #-1]
//   0x7764: 381ff52b  strb       w11, [x9], #0xffffffffffffffff
//   0x7768: eb09011f  cmp        x8, x9
//   0x776c: aa0c03e8  mov        x8, x12
//   0x7770: 54ffff23  b.lo       #0x7754
//   0x7774: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[41] XasanFde_7778 (0x7778..0x78a4, 300 bytes, 75 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7778..0x78a4
// ----------------------------------------------------------------------------
//   0x7778: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x777c: a9015ffc  stp        x28, x23, [sp, #0x10]
//   0x7780: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7784: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7788: 910003fd  mov        x29, sp
//   0x778c: d11403ff  sub        sp, sp, #0x500
//   0x7790: a9099be5  stp        x5, x6, [sp, #0x98]
//   0x7794: a90893e3  stp        x3, x4, [sp, #0x88]
//   0x7798: f90043e2  str        x2, [sp, #0x80]
//   0x779c: f90057e7  str        x7, [sp, #0xa8]
//   0x77a0: ad0007e0  stp        q0, q1, [sp]
//   0x77a4: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x77a8: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x77ac: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x77b0: d53bd057  mrs        x23, tpidr_el0
//   0x77b4: f94016e8  ldr        x8, [x23, #0x28]
//   0x77b8: f81f83a8  stur       x8, [x29, #-8]
//   0x77bc: 37f80580  tbnz       w0, #0x1f, #0x786c
//   0x77c0: 910203e9  add        x9, sp, #0x80
//   0x77c4: 928005eb  mov        x11, #-0x30
//   0x77c8: 910003ec  mov        x12, sp
//   0x77cc: 910103a8  add        x8, x29, #0x40
//   0x77d0: 9100c129  add        x9, x9, #0x30
//   0x77d4: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x77d8: 9102018c  add        x12, x12, #0x80
//   0x77dc: 910363ea  add        x10, sp, #0xd8
//   0x77e0: 2a0003f3  mov        w19, w0
//   0x77e4: aa0103e2  mov        x2, x1
//   0x77e8: a90da7e8  stp        x8, x9, [sp, #0xd8]
//   0x77ec: 9103e3e0  add        x0, sp, #0xf8
//   0x77f0: a90eafec  stp        x12, x11, [sp, #0xe8]
//   0x77f4: 9102c3e3  add        x3, sp, #0xb0
//   0x77f8: ad400540  ldp        q0, q1, [x10]
//   0x77fc: 52808001  mov        w1, #0x400
//   0x7800: ad0587e0  stp        q0, q1, [sp, #0xb0]
//   0x7804: 97fffd59  bl         #0x6d68
//   0x7808: f100041f  cmp        x0, #1
//   0x780c: 540002cb  b.lt       #0x7864
//   0x7810: aa0003f4  mov        x20, x0
//   0x7814: 9103e3f5  add        x21, sp, #0xf8
//   0x7818: 9400052e  bl         #0x8cd0
//   0x781c: aa0003f6  mov        x22, x0
//   0x7820: 14000004  b          #0x7830
//   0x7824: eb000294  subs       x20, x20, x0
//   0x7828: 8b0002b5  add        x21, x21, x0
//   0x782c: 540001c0  b.eq       #0x7864
//   0x7830: 2a1303e0  mov        w0, w19
//   0x7834: aa1503e1  mov        x1, x21
//   0x7838: aa1403e2  mov        x2, x20
//   0x783c: b90002df  str        wzr, [x22]
//   0x7840: 940005d4  bl         #0x8f90
//   0x7844: f100001f  cmp        x0, #0
//   0x7848: 54fffeec  b.gt       #0x7824
//   0x784c: b6f80140  tbz        x0, #0x3f, #0x7874
//   0x7850: b94002c8  ldr        w8, [x22]
//   0x7854: 7100111f  cmp        w8, #4
//   0x7858: 540000e1  b.ne       #0x7874
//   0x785c: aa1f03e0  mov        x0, xzr
//   0x7860: 17fffff1  b          #0x7824
//   0x7864: 2a1f03e0  mov        w0, wzr
//   0x7868: 14000004  b          #0x7878
//   0x786c: 52807d40  mov        w0, #0x3ea
//   0x7870: 14000002  b          #0x7878
//   0x7874: 52807d20  mov        w0, #0x3e9
//   0x7878: f94016e8  ldr        x8, [x23, #0x28]
//   0x787c: f85f83a9  ldur       x9, [x29, #-8]
//   0x7880: eb09011f  cmp        x8, x9
//   0x7884: 540000e1  b.ne       #0x78a0
//   0x7888: 911403ff  add        sp, sp, #0x500
//   0x788c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x7890: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x7894: a9415ffc  ldp        x28, x23, [sp, #0x10]
//   0x7898: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x789c: d65f03c0  ret        
//   0x78a0: 94000544  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[42] XasanFde_78a4 (0x78a4..0x7a94, 496 bytes, 124 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x78a4..0x7a94
// ----------------------------------------------------------------------------
//   0x78a4: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x78a8: f9000bfc  str        x28, [sp, #0x10]
//   0x78ac: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x78b0: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x78b4: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x78b8: 910003fd  mov        x29, sp
//   0x78bc: d11483ff  sub        sp, sp, #0x520
//   0x78c0: a90993e3  stp        x3, x4, [sp, #0x98]
//   0x78c4: 928005e9  mov        x9, #-0x30
//   0x78c8: f9004be2  str        x2, [sp, #0x90]
//   0x78cc: 910043ea  add        x10, sp, #0x10
//   0x78d0: a90a9be5  stp        x5, x6, [sp, #0xa8]
//   0x78d4: 910243eb  add        x11, sp, #0x90
//   0x78d8: f9005fe7  str        x7, [sp, #0xb8]
//   0x78dc: aa0103f4  mov        x20, x1
//   0x78e0: ad0087e0  stp        q0, q1, [sp, #0x10]
//   0x78e4: f2dff009  movk       x9, #0xff80, lsl #32
//   0x78e8: ad018fe2  stp        q2, q3, [sp, #0x30]
//   0x78ec: 9102014a  add        x10, x10, #0x80
//   0x78f0: ad0297e4  stp        q4, q5, [sp, #0x50]
//   0x78f4: ad039fe6  stp        q6, q7, [sp, #0x70]
//   0x78f8: d53bd057  mrs        x23, tpidr_el0
//   0x78fc: f94016e8  ldr        x8, [x23, #0x28]
//   0x7900: 7100041f  cmp        w0, #1
//   0x7904: f81f83a8  stur       x8, [x29, #-8]
//   0x7908: 9100c168  add        x8, x11, #0x30
//   0x790c: 910143ab  add        x11, x29, #0x50
//   0x7910: a90e27ea  stp        x10, x9, [sp, #0xe0]
//   0x7914: a90d23eb  stp        x11, x8, [sp, #0xd0]
//   0x7918: 5400096b  b.lt       #0x7a44
//   0x791c: 2a0003f3  mov        w19, w0
//   0x7920: 910303e0  add        x0, sp, #0xc0
//   0x7924: aa1f03e1  mov        x1, xzr
//   0x7928: 940005de  bl         #0x90a0
//   0x792c: a94c23f8  ldp        x24, x8, [sp, #0xc0]
//   0x7930: d29ef9e9  mov        x9, #0xf7cf
//   0x7934: f2bc6a69  movk       x9, #0xe353, lsl #16
//   0x7938: f2d374a9  movk       x9, #0x9ba5, lsl #32
//   0x793c: f2e41889  movk       x9, #0x20c4, lsl #48
//   0x7940: 9b497d08  smulh      x8, x8, x9
//   0x7944: 9347fd09  asr        x9, x8, #7
//   0x7948: 8b48fd35  add        x21, x9, x8, lsr #63
//   0x794c: 9400054d  bl         #0x8e80
//   0x7950: 2a0003f6  mov        w22, w0
//   0x7954: 9400054f  bl         #0x8e90
//   0x7958: b201e3e8  mov        x8, #-0x7777777777777778
//   0x795c: d28f80a9  mov        x9, #0x7c05
//   0x7960: f2911128  movk       x8, #0x8889
//   0x7964: f2ad5e69  movk       x9, #0x6af3, lsl #16
//   0x7968: f2cb3c49  movk       x9, #0x59e2, lsl #32
//   0x796c: b201f3eb  mov        x11, #-0x5555555555555556
//   0x7970: f2e91a29  movk       x9, #0x48d1, lsl #48
//   0x7974: 9b487f0a  smulh      x10, x24, x8
//   0x7978: f295556b  movk       x11, #0xaaab
//   0x797c: f0ffffc2  adrp       x2, #0x2000
//   0x7980: 91021442  add        x2, x2, #0x85
//   0x7984: 9b497f09  smulh      x9, x24, x9
//   0x7988: 8b18014a  add        x10, x10, x24
//   0x798c: f2e5554b  movk       x11, #0x2aaa, lsl #48
//   0x7990: 9345fd4d  asr        x13, x10, #5
//   0x7994: 934afd2c  asr        x12, x9, #0xa
//   0x7998: 8b4afdaa  add        x10, x13, x10, lsr #63
//   0x799c: 8b49fd89  add        x9, x12, x9, lsr #63
//   0x79a0: 5280078c  mov        w12, #0x3c
//   0x79a4: 52808001  mov        w1, #0x400
//   0x79a8: 9b487d48  smulh      x8, x10, x8
//   0x79ac: aa1503e6  mov        x6, x21
//   0x79b0: 9b4b7d2b  smulh      x11, x9, x11
//   0x79b4: 2a1603e7  mov        w7, w22
//   0x79b8: 8b0a0108  add        x8, x8, x10
//   0x79bc: 1b0ce145  msub       w5, w10, w12, w24
//   0x79c0: d37ffd6d  lsr        x13, x11, #0x3f
//   0x79c4: d342fd6b  lsr        x11, x11, #2
//   0x79c8: d37ffd0e  lsr        x14, x8, #0x3f
//   0x79cc: d345fd08  lsr        x8, x8, #5
//   0x79d0: 0b0d016b  add        w11, w11, w13
//   0x79d4: 0b0e0108  add        w8, w8, w14
//   0x79d8: 5280030d  mov        w13, #0x18
//   0x79dc: 910443f5  add        x21, sp, #0x110
//   0x79e0: 1b0ca904  msub       w4, w8, w12, w10
//   0x79e4: 2a0003e8  mov        w8, w0
//   0x79e8: 1b0da563  msub       w3, w11, w13, w9
//   0x79ec: 910443e0  add        x0, sp, #0x110
//   0x79f0: b90003e8  str        w8, [sp]
//   0x79f4: 97fffcc3  bl         #0x6d00
//   0x79f8: f100641f  cmp        x0, #0x19
//   0x79fc: 54000341  b.ne       #0x7a64
//   0x7a00: ad4687e0  ldp        q0, q1, [sp, #0xd0]
//   0x7a04: 910066a0  add        x0, x21, #0x19
//   0x7a08: 9103c3e3  add        x3, sp, #0xf0
//   0x7a0c: 52807ce1  mov        w1, #0x3e7
//   0x7a10: aa1403e2  mov        x2, x20
//   0x7a14: ad0787e0  stp        q0, q1, [sp, #0xf0]
//   0x7a18: 97fffcd4  bl         #0x6d68
//   0x7a1c: b4000240  cbz        x0, #0x7a64
//   0x7a20: 910443e8  add        x8, sp, #0x110
//   0x7a24: 52800149  mov        w9, #0xa
//   0x7a28: 8b080008  add        x8, x0, x8
//   0x7a2c: 91006802  add        x2, x0, #0x1a
//   0x7a30: 910443e1  add        x1, sp, #0x110
//   0x7a34: 2a1303e0  mov        w0, w19
//   0x7a38: 39006509  strb       w9, [x8, #0x19]
//   0x7a3c: 94000555  bl         #0x8f90
//   0x7a40: 14000009  b          #0x7a64
//   0x7a44: ad4687e0  ldp        q0, q1, [sp, #0xd0]
//   0x7a48: d0000028  adrp       x8, #0xd000
//   0x7a4c: 910443e2  add        x2, sp, #0x110
//   0x7a50: aa1403e1  mov        x1, x20
//   0x7a54: ad0887e0  stp        q0, q1, [sp, #0x110]
//   0x7a58: f9419108  ldr        x8, [x8, #0x320]
//   0x7a5c: 91026100  add        x0, x8, #0x98
//   0x7a60: 94000594  bl         #0x90b0
//   0x7a64: f94016e8  ldr        x8, [x23, #0x28]
//   0x7a68: f85f83a9  ldur       x9, [x29, #-8]
//   0x7a6c: eb09011f  cmp        x8, x9
//   0x7a70: 54000101  b.ne       #0x7a90
//   0x7a74: 911483ff  add        sp, sp, #0x520
//   0x7a78: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x7a7c: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x7a80: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x7a84: f9400bfc  ldr        x28, [sp, #0x10]
//   0x7a88: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x7a8c: d65f03c0  ret        
//   0x7a90: 940004c8  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[43] XasanFde_7a94 (0x7a94..0x7b70, 220 bytes, 55 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7a94..0x7b70
// ----------------------------------------------------------------------------
//   0x7a94: d10203ff  sub        sp, sp, #0x80
//   0x7a98: a9067bfd  stp        x29, x30, [sp, #0x60]
//   0x7a9c: f9003bf3  str        x19, [sp, #0x70]
//   0x7aa0: 910183fd  add        x29, sp, #0x60
//   0x7aa4: d53bd053  mrs        x19, tpidr_el0
//   0x7aa8: 910023e1  add        x1, sp, #8
//   0x7aac: f9401668  ldr        x8, [x19, #0x28]
//   0x7ab0: 2a1f03e0  mov        w0, wzr
//   0x7ab4: f81f83a8  stur       x8, [x29, #-8]
//   0x7ab8: 94000582  bl         #0x90c0
//   0x7abc: b9400bea  ldr        w10, [sp, #8]
//   0x7ac0: 910063e8  add        x8, sp, #0x18
//   0x7ac4: 36f800aa  tbz        w10, #0x1f, #0x7ad8
//   0x7ac8: 528005a9  mov        w9, #0x2d
//   0x7acc: b2400108  orr        x8, x8, #1
//   0x7ad0: 4b0a03ea  neg        w10, w10
//   0x7ad4: 390063e9  strb       w9, [sp, #0x18]
//   0x7ad8: 528ccceb  mov        w11, #0x6667
//   0x7adc: d1000509  sub        x9, x8, #1
//   0x7ae0: 72accccb  movk       w11, #0x6666, lsl #16
//   0x7ae4: 5280014c  mov        w12, #0xa
//   0x7ae8: 9b2b7d4d  smull      x13, w10, w11
//   0x7aec: 1100254f  add        w15, w10, #9
//   0x7af0: 710049ff  cmp        w15, #0x12
//   0x7af4: d37ffdae  lsr        x14, x13, #0x3f
//   0x7af8: 9362fdad  asr        x13, x13, #0x22
//   0x7afc: 0b0e01ad  add        w13, w13, w14
//   0x7b00: 1b0ca9ae  msub       w14, w13, w12, w10
//   0x7b04: 2a0d03ea  mov        w10, w13
//   0x7b08: 1100c1ce  add        w14, w14, #0x30
//   0x7b0c: 38001d2e  strb       w14, [x9, #1]!
//   0x7b10: 54fffec8  b.hi       #0x7ae8
//   0x7b14: eb09011f  cmp        x8, x9
//   0x7b18: 3900053f  strb       wzr, [x9, #1]
//   0x7b1c: 54000142  b.hs       #0x7b44
//   0x7b20: 91000508  add        x8, x8, #1
//   0x7b24: 3940012a  ldrb       w10, [x9]
//   0x7b28: 9100050c  add        x12, x8, #1
//   0x7b2c: 385ff10b  ldurb      w11, [x8, #-1]
//   0x7b30: 381ff10a  sturb      w10, [x8, #-1]
//   0x7b34: 381ff52b  strb       w11, [x9], #0xffffffffffffffff
//   0x7b38: eb09011f  cmp        x8, x9
//   0x7b3c: aa0c03e8  mov        x8, x12
//   0x7b40: 54ffff23  b.lo       #0x7b24
//   0x7b44: 910063e0  add        x0, sp, #0x18
//   0x7b48: 94000482  bl         #0x8d50
//   0x7b4c: f9401668  ldr        x8, [x19, #0x28]
//   0x7b50: f85f83a9  ldur       x9, [x29, #-8]
//   0x7b54: eb09011f  cmp        x8, x9
//   0x7b58: 540000a1  b.ne       #0x7b6c
//   0x7b5c: a9467bfd  ldp        x29, x30, [sp, #0x60]
//   0x7b60: f9403bf3  ldr        x19, [sp, #0x70]
//   0x7b64: 910203ff  add        sp, sp, #0x80
//   0x7b68: d65f03c0  ret        
//   0x7b6c: 94000491  bl         #0x8db0

// ----------------------------------------------------------------------------
// FDE[44] XasanFde_7b70 (0x7b70..0x7ba4, 52 bytes, 13 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7b70..0x7ba4
// ----------------------------------------------------------------------------
//   0x7b70: d10083ff  sub        sp, sp, #0x20
//   0x7b74: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x7b78: 910043fd  add        x29, sp, #0x10
//   0x7b7c: d503201f  nop        
//   0x7b80: 10fd8048  adr        x8, #0x2b88
//   0x7b84: 910003e1  mov        x1, sp
//   0x7b88: a9007fff  stp        xzr, xzr, [sp]
//   0x7b8c: b860d900  ldr        w0, [x8, w0, sxtw #2]
//   0x7b90: 9400054c  bl         #0x90c0
//   0x7b94: a94007e0  ldp        x0, x1, [sp]
//   0x7b98: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x7b9c: 910083ff  add        sp, sp, #0x20
//   0x7ba0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[45] GwpAsanAddressIsMine_7ba4 (0x7ba4..0x7be0, 60 bytes, 15 instructions)
// Summary / Tóm tắt: Checks if address lies within [GuardedPagePool, GuardedPagePoolEnd) (@ 0x7ba4..0x7be0)
// ----------------------------------------------------------------------------
//   0x7ba4: b9404008  ldr        w8, [x0, #0x40]
//   0x7ba8: 340000a8  cbz        w8, #0x7bbc
//   0x7bac: f9402408  ldr        x8, [x0, #0x48]
//   0x7bb0: b4000068  cbz        x8, #0x7bbc
//   0x7bb4: 52800020  mov        w0, #1
//   0x7bb8: d65f03c0  ret        
//   0x7bbc: f9401808  ldr        x8, [x0, #0x30]
//   0x7bc0: eb01011f  cmp        x8, x1
//   0x7bc4: 540000a9  b.ls       #0x7bd8
//   0x7bc8: f9401408  ldr        x8, [x0, #0x28]
//   0x7bcc: eb01011f  cmp        x8, x1
//   0x7bd0: 1a9f87e0  cset       w0, ls
//   0x7bd4: d65f03c0  ret        
//   0x7bd8: 2a1f03e0  mov        w0, wzr
//   0x7bdc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[46] XasanFde_7be0 (0x7be0..0x7be8, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7be0..0x7be8
// ----------------------------------------------------------------------------
//   0x7be0: f9402400  ldr        x0, [x0, #0x48]
//   0x7be4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[47] XasanFde_7be8 (0x7be8..0x7cd8, 240 bytes, 60 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7be8..0x7cd8
// ----------------------------------------------------------------------------
//   0x7be8: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x7bec: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x7bf0: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7bf4: 910003fd  mov        x29, sp
//   0x7bf8: aa0203f3  mov        x19, x2
//   0x7bfc: aa0003f5  mov        x21, x0
//   0x7c00: b9404008  ldr        w8, [x0, #0x40]
//   0x7c04: aa0103f4  mov        x20, x1
//   0x7c08: 340000a8  cbz        w8, #0x7c1c
//   0x7c0c: f94026a9  ldr        x9, [x21, #0x48]
//   0x7c10: b4000069  cbz        x9, #0x7c1c
//   0x7c14: 2a0803e0  mov        w0, w8
//   0x7c18: 14000026  b          #0x7cb0
//   0x7c1c: f9401aa9  ldr        x9, [x21, #0x30]
//   0x7c20: eb13013f  cmp        x9, x19
//   0x7c24: 54000449  b.ls       #0x7cac
//   0x7c28: f94016a9  ldr        x9, [x21, #0x28]
//   0x7c2c: eb13013f  cmp        x9, x19
//   0x7c30: 1a8883e0  csel       w0, wzr, w8, hi
//   0x7c34: 350003e8  cbnz       w8, #0x7cb0
//   0x7c38: eb13013f  cmp        x9, x19
//   0x7c3c: 540003a8  b.hi       #0x7cb0
//   0x7c40: f9400aa8  ldr        x8, [x21, #0x10]
//   0x7c44: aa1503e0  mov        x0, x21
//   0x7c48: aa1303e1  mov        x1, x19
//   0x7c4c: d63f0100  blr        x8
//   0x7c50: 2a0003f6  mov        w22, w0
//   0x7c54: f9400ea8  ldr        x8, [x21, #0x18]
//   0x7c58: aa1503e0  mov        x0, x21
//   0x7c5c: aa1303e1  mov        x1, x19
//   0x7c60: d63f0100  blr        x8
//   0x7c64: aa0003e1  mov        x1, x0
//   0x7c68: 340002d6  cbz        w22, #0x7cc0
//   0x7c6c: f94006a8  ldr        x8, [x21, #8]
//   0x7c70: aa1503e0  mov        x0, x21
//   0x7c74: d63f0100  blr        x8
//   0x7c78: aa0003e1  mov        x1, x0
//   0x7c7c: f9400ea8  ldr        x8, [x21, #0x18]
//   0x7c80: aa1503e0  mov        x0, x21
//   0x7c84: d63f0100  blr        x8
//   0x7c88: 52804b08  mov        w8, #0x258
//   0x7c8c: 52800089  mov        w9, #4
//   0x7c90: 9b085008  madd       x8, x0, x8, x20
//   0x7c94: f9400908  ldr        x8, [x8, #0x10]
//   0x7c98: eb13011f  cmp        x8, x19
//   0x7c9c: 1a893529  cinc       w9, w9, hs
//   0x7ca0: f100011f  cmp        x8, #0
//   0x7ca4: 1a8903e0  csel       w0, wzr, w9, eq
//   0x7ca8: 14000002  b          #0x7cb0
//   0x7cac: 2a1f03e0  mov        w0, wzr
//   0x7cb0: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x7cb4: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x7cb8: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7cbc: d65f03c0  ret        
//   0x7cc0: 52804b08  mov        w8, #0x258
//   0x7cc4: 9b085028  madd       x8, x1, x8, x20
//   0x7cc8: b9402108  ldr        w8, [x8, #0x20]
//   0x7ccc: 7100011f  cmp        w8, #0
//   0x7cd0: 1a9f07e0  cset       w0, ne
//   0x7cd4: 17fffff7  b          #0x7cb0

// ----------------------------------------------------------------------------
// FDE[48] XasanFde_7cd8 (0x7cd8..0x7d60, 136 bytes, 34 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7cd8..0x7d60
// ----------------------------------------------------------------------------
//   0x7cd8: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7cdc: f9000bf3  str        x19, [sp, #0x10]
//   0x7ce0: 910003fd  mov        x29, sp
//   0x7ce4: b9404008  ldr        w8, [x0, #0x40]
//   0x7ce8: aa0103f3  mov        x19, x1
//   0x7cec: 340000a8  cbz        w8, #0x7d00
//   0x7cf0: f9402408  ldr        x8, [x0, #0x48]
//   0x7cf4: b4000068  cbz        x8, #0x7d00
//   0x7cf8: f9401808  ldr        x8, [x0, #0x30]
//   0x7cfc: 14000007  b          #0x7d18
//   0x7d00: f9401808  ldr        x8, [x0, #0x30]
//   0x7d04: eb02011f  cmp        x8, x2
//   0x7d08: 54000129  b.ls       #0x7d2c
//   0x7d0c: f9401409  ldr        x9, [x0, #0x28]
//   0x7d10: eb02013f  cmp        x9, x2
//   0x7d14: 540000c8  b.hi       #0x7d2c
//   0x7d18: eb02011f  cmp        x8, x2
//   0x7d1c: 54000089  b.ls       #0x7d2c
//   0x7d20: f9401408  ldr        x8, [x0, #0x28]
//   0x7d24: eb02011f  cmp        x8, x2
//   0x7d28: 540000a9  b.ls       #0x7d3c
//   0x7d2c: aa1f03e0  mov        x0, xzr
//   0x7d30: f9400bf3  ldr        x19, [sp, #0x10]
//   0x7d34: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7d38: d65f03c0  ret        
//   0x7d3c: f9400c08  ldr        x8, [x0, #0x18]
//   0x7d40: aa0203e1  mov        x1, x2
//   0x7d44: d63f0100  blr        x8
//   0x7d48: 52804b08  mov        w8, #0x258
//   0x7d4c: 9b084c08  madd       x8, x0, x8, x19
//   0x7d50: f9400909  ldr        x9, [x8, #0x10]
//   0x7d54: f100013f  cmp        x9, #0
//   0x7d58: 9a8803e0  csel       x0, xzr, x8, eq
//   0x7d5c: 17fffff5  b          #0x7d30

// ----------------------------------------------------------------------------
// FDE[49] XasanFde_7d60 (0x7d60..0x7d68, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d60..0x7d68
// ----------------------------------------------------------------------------
//   0x7d60: f9400800  ldr        x0, [x0, #0x10]
//   0x7d64: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[50] XasanFde_7d68 (0x7d68..0x7d70, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d68..0x7d70
// ----------------------------------------------------------------------------
//   0x7d68: f9400c00  ldr        x0, [x0, #0x18]
//   0x7d6c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[51] XasanFde_7d70 (0x7d70..0x7d78, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d70..0x7d78
// ----------------------------------------------------------------------------
//   0x7d70: f9409800  ldr        x0, [x0, #0x130]
//   0x7d74: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[52] XasanFde_7d78 (0x7d78..0x7d94, 28 bytes, 7 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d78..0x7d94
// ----------------------------------------------------------------------------
//   0x7d78: f9409c09  ldr        x9, [x0, #0x138]
//   0x7d7c: 9100c008  add        x8, x0, #0x30
//   0x7d80: aa0203e3  mov        x3, x2
//   0x7d84: aa0103e2  mov        x2, x1
//   0x7d88: aa0803e0  mov        x0, x8
//   0x7d8c: aa0903e1  mov        x1, x9
//   0x7d90: 140000b6  b          #0x8068

// ----------------------------------------------------------------------------
// FDE[53] XasanFde_7d94 (0x7d94..0x7d9c, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d94..0x7d9c
// ----------------------------------------------------------------------------
//   0x7d94: b9402000  ldr        w0, [x0, #0x20]
//   0x7d98: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[54] XasanFde_7d9c (0x7d9c..0x7da4, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7d9c..0x7da4
// ----------------------------------------------------------------------------
//   0x7d9c: f9412400  ldr        x0, [x0, #0x248]
//   0x7da0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[55] XasanFde_7da4 (0x7da4..0x7dc0, 28 bytes, 7 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7da4..0x7dc0
// ----------------------------------------------------------------------------
//   0x7da4: f9412809  ldr        x9, [x0, #0x250]
//   0x7da8: 91052008  add        x8, x0, #0x148
//   0x7dac: aa0203e3  mov        x3, x2
//   0x7db0: aa0103e2  mov        x2, x1
//   0x7db4: aa0803e0  mov        x0, x8
//   0x7db8: aa0903e1  mov        x1, x9
//   0x7dbc: 140000ab  b          #0x8068

// ----------------------------------------------------------------------------
// FDE[56] GwpAsanErrorToString_7dc0 (0x7dc0..0x7de0, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Maps Error enum (0..5) via offset table @ 0x2bb0 to string (@ 0x7dc0..0x7de0)
// ----------------------------------------------------------------------------
//   0x7dc0: 7100181f  cmp        w0, #6
//   0x7dc4: 540000c2  b.hs       #0x7ddc
//   0x7dc8: d503201f  nop        
//   0x7dcc: 10fd6f28  adr        x8, #0x2bb0
//   0x7dd0: b8a0d909  ldrsw      x9, [x8, w0, sxtw #2]
//   0x7dd4: 8b090100  add        x0, x8, x9
//   0x7dd8: d65f03c0  ret        
//   0x7ddc: d4200020  brk        #1

// ----------------------------------------------------------------------------
// FDE[57] XasanFde_7de0 (0x7de0..0x7e20, 64 bytes, 16 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7de0..0x7e20
// ----------------------------------------------------------------------------
//   0x7de0: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7de4: f9000bf3  str        x19, [sp, #0x10]
//   0x7de8: 910003fd  mov        x29, sp
//   0x7dec: aa0003f3  mov        x19, x0
//   0x7df0: a9010801  stp        x1, x2, [x0, #0x10]
//   0x7df4: b900201f  str        wzr, [x0, #0x20]
//   0x7df8: 94000426  bl         #0x8e90
//   0x7dfc: f0ffffc8  adrp       x8, #0x2000
//   0x7e00: 93407c09  sxtw       x9, w0
//   0x7e04: 9109226a  add        x10, x19, #0x248
//   0x7e08: 3dc2e900  ldr        q0, [x8, #0xba0]
//   0x7e0c: f9009a69  str        x9, [x19, #0x130]
//   0x7e10: 3d800140  str        q0, [x10]
//   0x7e14: f9400bf3  ldr        x19, [sp, #0x10]
//   0x7e18: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7e1c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[58] XasanFde_7e20 (0x7e20..0x7e50, 48 bytes, 12 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7e20..0x7e50
// ----------------------------------------------------------------------------
//   0x7e20: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7e24: f9000bf3  str        x19, [sp, #0x10]
//   0x7e28: 910003fd  mov        x29, sp
//   0x7e2c: 52800028  mov        w8, #1
//   0x7e30: aa0003f3  mov        x19, x0
//   0x7e34: b9002008  str        w8, [x0, #0x20]
//   0x7e38: 94000416  bl         #0x8e90
//   0x7e3c: 93407c08  sxtw       x8, w0
//   0x7e40: f9012668  str        x8, [x19, #0x248]
//   0x7e44: f9400bf3  ldr        x19, [sp, #0x10]
//   0x7e48: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7e4c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[59] XasanFde_7e50 (0x7e50..0x7ea4, 84 bytes, 21 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7e50..0x7ea4
// ----------------------------------------------------------------------------
//   0x7e50: d10483ff  sub        sp, sp, #0x120
//   0x7e54: a9107bfd  stp        x29, x30, [sp, #0x100]
//   0x7e58: a9114ffc  stp        x28, x19, [sp, #0x110]
//   0x7e5c: 910403fd  add        x29, sp, #0x100
//   0x7e60: f900881f  str        xzr, [x0, #0x110]
//   0x7e64: b4000181  cbz        x1, #0x7e94
//   0x7e68: aa0103e8  mov        x8, x1
//   0x7e6c: aa0003f3  mov        x19, x0
//   0x7e70: 910003e0  mov        x0, sp
//   0x7e74: 52800401  mov        w1, #0x20
//   0x7e78: d63f0100  blr        x8
//   0x7e7c: aa0003e1  mov        x1, x0
//   0x7e80: 91002262  add        x2, x19, #8
//   0x7e84: 910003e0  mov        x0, sp
//   0x7e88: 52802003  mov        w3, #0x100
//   0x7e8c: 94000056  bl         #0x7fe4
//   0x7e90: f9008a60  str        x0, [x19, #0x110]
//   0x7e94: a9514ffc  ldp        x28, x19, [sp, #0x110]
//   0x7e98: a9507bfd  ldp        x29, x30, [sp, #0x100]
//   0x7e9c: 910483ff  add        sp, sp, #0x120
//   0x7ea0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[60] XasanFde_7ea4 (0x7ea4..0x7ecc, 40 bytes, 10 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7ea4..0x7ecc
// ----------------------------------------------------------------------------
//   0x7ea4: b40000e0  cbz        x0, #0x7ec0
//   0x7ea8: f9401808  ldr        x8, [x0, #0x30]
//   0x7eac: eb01011f  cmp        x8, x1
//   0x7eb0: 540000a9  b.ls       #0x7ec4
//   0x7eb4: f9401408  ldr        x8, [x0, #0x28]
//   0x7eb8: eb01011f  cmp        x8, x1
//   0x7ebc: 1a9f87e0  cset       w0, ls
//   0x7ec0: d65f03c0  ret        
//   0x7ec4: 2a1f03e0  mov        w0, wzr
//   0x7ec8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[61] XasanFde_7ecc (0x7ecc..0x7ed4, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7ecc..0x7ed4
// ----------------------------------------------------------------------------
//   0x7ecc: f9401c00  ldr        x0, [x0, #0x38]
//   0x7ed0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[62] XasanFde_7ed4 (0x7ed4..0x7eec, 24 bytes, 6 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7ed4..0x7eec
// ----------------------------------------------------------------------------
//   0x7ed4: 52800028  mov        w8, #1
//   0x7ed8: f9401409  ldr        x9, [x0, #0x28]
//   0x7edc: f9401c0a  ldr        x10, [x0, #0x38]
//   0x7ee0: aa010508  orr        x8, x8, x1, lsl #1
//   0x7ee4: 9b082540  madd       x0, x10, x8, x9
//   0x7ee8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[63] XasanFde_7eec (0x7eec..0x7f08, 28 bytes, 7 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7eec..0x7f08
// ----------------------------------------------------------------------------
//   0x7eec: f9401408  ldr        x8, [x0, #0x28]
//   0x7ef0: f9401c09  ldr        x9, [x0, #0x38]
//   0x7ef4: cb080028  sub        x8, x1, x8
//   0x7ef8: 9ac90908  udiv       x8, x8, x9
//   0x7efc: f240011f  tst        x8, #1
//   0x7f00: 1a9f17e0  cset       w0, eq
//   0x7f04: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[64] XasanFde_7f08 (0x7f08..0x7f84, 124 bytes, 31 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7f08..0x7f84
// ----------------------------------------------------------------------------
//   0x7f08: f940140a  ldr        x10, [x0, #0x28]
//   0x7f0c: f9401c08  ldr        x8, [x0, #0x38]
//   0x7f10: 8b0a0109  add        x9, x8, x10
//   0x7f14: eb01013f  cmp        x9, x1
//   0x7f18: 54000102  b.hs       #0x7f38
//   0x7f1c: f940180b  ldr        x11, [x0, #0x30]
//   0x7f20: cb08016b  sub        x11, x11, x8
//   0x7f24: eb01017f  cmp        x11, x1
//   0x7f28: 540000c2  b.hs       #0x7f40
//   0x7f2c: f9401008  ldr        x8, [x0, #0x20]
//   0x7f30: d1000500  sub        x0, x8, #1
//   0x7f34: d65f03c0  ret        
//   0x7f38: aa1f03e0  mov        x0, xzr
//   0x7f3c: d65f03c0  ret        
//   0x7f40: cb0a002a  sub        x10, x1, x10
//   0x7f44: 9ac8094b  udiv       x11, x10, x8
//   0x7f48: 3700012b  tbnz       w11, #0, #0x7f6c
//   0x7f4c: 9ac8082b  udiv       x11, x1, x8
//   0x7f50: 9b08856c  msub       x12, x11, x8, x1
//   0x7f54: d37ff90b  lsl        x11, x8, #1
//   0x7f58: eb48059f  cmp        x12, x8, lsr #1
//   0x7f5c: 540000e9  b.ls       #0x7f78
//   0x7f60: 8b080148  add        x8, x10, x8
//   0x7f64: 9acb0900  udiv       x0, x8, x11
//   0x7f68: d65f03c0  ret        
//   0x7f6c: d37ff908  lsl        x8, x8, #1
//   0x7f70: 9ac80940  udiv       x0, x10, x8
//   0x7f74: d65f03c0  ret        
//   0x7f78: cb090028  sub        x8, x1, x9
//   0x7f7c: 9acb0900  udiv       x0, x8, x11
//   0x7f80: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[65] XasanFde_7f84 (0x7f84..0x7fb8, 52 bytes, 13 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7f84..0x7fb8
// ----------------------------------------------------------------------------
//   0x7f84: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7f88: f9000bf3  str        x19, [sp, #0x10]
//   0x7f8c: 910003fd  mov        x29, sp
//   0x7f90: aa1f03e0  mov        x0, xzr
//   0x7f94: 940003fb  bl         #0x8f80
//   0x7f98: aa0003f3  mov        x19, x0
//   0x7f9c: 940003bd  bl         #0x8e90
//   0x7fa0: d0000048  adrp       x8, #0x11000
//   0x7fa4: 0b130009  add        w9, w0, w19
//   0x7fa8: b9062509  str        w9, [x8, #0x624]
//   0x7fac: f9400bf3  ldr        x19, [sp, #0x10]
//   0x7fb0: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7fb4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[66] XasanFde_7fb8 (0x7fb8..0x7fe4, 44 bytes, 11 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7fb8..0x7fe4
// ----------------------------------------------------------------------------
//   0x7fb8: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x7fbc: 910003fd  mov        x29, sp
//   0x7fc0: aa1f03e0  mov        x0, xzr
//   0x7fc4: 940003ef  bl         #0x8f80
//   0x7fc8: 4a003408  eor        w8, w0, w0, lsl #13
//   0x7fcc: 4a484508  eor        w8, w8, w8, lsr #17
//   0x7fd0: 4a081500  eor        w0, w8, w8, lsl #5
//   0x7fd4: d0000048  adrp       x8, #0x11000
//   0x7fd8: b9062500  str        w0, [x8, #0x624]
//   0x7fdc: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x7fe0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[67] XasanFde_7fe4 (0x7fe4..0x8068, 132 bytes, 33 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x7fe4..0x8068
// ----------------------------------------------------------------------------
//   0x7fe4: b40003e1  cbz        x1, #0x8060
//   0x7fe8: aa1f03e8  mov        x8, xzr
//   0x7fec: aa1f03e9  mov        x9, xzr
//   0x7ff0: f869780a  ldr        x10, [x0, x9, lsl #3]
//   0x7ff4: b4000089  cbz        x9, #0x8004
//   0x7ff8: 8b090c0b  add        x11, x0, x9, lsl #3
//   0x7ffc: f85f816b  ldur       x11, [x11, #-8]
//   0x8000: cb0b014a  sub        x10, x10, x11
//   0x8004: eb03011f  cmp        x8, x3
//   0x8008: 54000280  b.eq       #0x8058
//   0x800c: d37ff94b  lsl        x11, x10, #1
//   0x8010: ca8afd6b  eor        x11, x11, x10, asr #63
//   0x8014: aa0803ea  mov        x10, x8
//   0x8018: 1200196c  and        w12, w11, #0x7f
//   0x801c: f102017f  cmp        x11, #0x80
//   0x8020: 382a684c  strb       w12, [x2, x10]
//   0x8024: 54000103  b.lo       #0x8044
//   0x8028: 3219016c  orr        w12, w11, #0x80
//   0x802c: d347fd6b  lsr        x11, x11, #7
//   0x8030: 382a684c  strb       w12, [x2, x10]
//   0x8034: 9100054a  add        x10, x10, #1
//   0x8038: eb0a007f  cmp        x3, x10
//   0x803c: 54fffee1  b.ne       #0x8018
//   0x8040: 14000005  b          #0x8054
//   0x8044: 91000548  add        x8, x10, #1
//   0x8048: 91000529  add        x9, x9, #1
//   0x804c: eb01013f  cmp        x9, x1
//   0x8050: 54fffd01  b.ne       #0x7ff0
//   0x8054: aa0803e3  mov        x3, x8
//   0x8058: aa0303e0  mov        x0, x3
//   0x805c: d65f03c0  ret        
//   0x8060: aa1f03e0  mov        x0, xzr
//   0x8064: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[68] XasanFde_8068 (0x8068..0x813c, 212 bytes, 53 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8068..0x813c
// ----------------------------------------------------------------------------
//   0x8068: b40005a3  cbz        x3, #0x811c
//   0x806c: aa1f03ec  mov        x12, xzr
//   0x8070: aa1f03e8  mov        x8, xzr
//   0x8074: 5280012a  mov        w10, #9
//   0x8078: eb01019f  cmp        x12, x1
//   0x807c: 540005c0  b.eq       #0x8134
//   0x8080: aa0c03e9  mov        x9, x12
//   0x8084: aa1f03ec  mov        x12, xzr
//   0x8088: aa2903ee  mvn        x14, x9
//   0x808c: aa1f03eb  mov        x11, xzr
//   0x8090: 8b0101ce  add        x14, x14, x1
//   0x8094: 2a1f03ed  mov        w13, wzr
//   0x8098: f10025df  cmp        x14, #9
//   0x809c: 9a8a31cf  csel       x15, x14, x10, lo
//   0x80a0: 8b09000e  add        x14, x0, x9
//   0x80a4: 910005ef  add        x15, x15, #1
//   0x80a8: 386b69d0  ldrb       w16, [x14, x11]
//   0x80ac: 92401a11  and        x17, x16, #0x7f
//   0x80b0: 9acd2231  lsl        x17, x17, x13
//   0x80b4: aa0c022c  orr        x12, x17, x12
//   0x80b8: 363800f0  tbz        w16, #7, #0x80d4
//   0x80bc: 12001dad  and        w13, w13, #0xff
//   0x80c0: 9100056b  add        x11, x11, #1
//   0x80c4: 11001dad  add        w13, w13, #7
//   0x80c8: eb0b01ff  cmp        x15, x11
//   0x80cc: 54fffee1  b.ne       #0x80a8
//   0x80d0: 14000015  b          #0x8124
//   0x80d4: 9240018d  and        x13, x12, #1
//   0x80d8: cb0d03ed  neg        x13, x13
//   0x80dc: ca4c05ac  eor        x12, x13, x12, lsr #1
//   0x80e0: f828784c  str        x12, [x2, x8, lsl #3]
//   0x80e4: b40000a8  cbz        x8, #0x80f8
//   0x80e8: 8b080c4d  add        x13, x2, x8, lsl #3
//   0x80ec: f85f81ae  ldur       x14, [x13, #-8]
//   0x80f0: 8b0c01cc  add        x12, x14, x12
//   0x80f4: f90001ac  str        x12, [x13]
//   0x80f8: 8b0b012c  add        x12, x9, x11
//   0x80fc: 91000508  add        x8, x8, #1
//   0x8100: 9100058c  add        x12, x12, #1
//   0x8104: eb03011f  cmp        x8, x3
//   0x8108: 54fffb81  b.ne       #0x8078
//   0x810c: 8b0b0128  add        x8, x9, x11
//   0x8110: 91000509  add        x9, x8, #1
//   0x8114: aa0303e8  mov        x8, x3
//   0x8118: 14000003  b          #0x8124
//   0x811c: aa1f03e8  mov        x8, xzr
//   0x8120: aa1f03e9  mov        x9, xzr
//   0x8124: eb03011f  cmp        x8, x3
//   0x8128: fa411124  ccmp       x9, x1, #4, ne
//   0x812c: 9a9f0100  csel       x0, x8, xzr, eq
//   0x8130: d65f03c0  ret        
//   0x8134: aa0103e9  mov        x9, x1
//   0x8138: 17fffffb  b          #0x8124

// ----------------------------------------------------------------------------
// FDE[69] XasanFde_813c (0x813c..0x8400, 708 bytes, 177 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x813c..0x8400
// ----------------------------------------------------------------------------
//   0x813c: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x8140: f9000bf9  str        x25, [sp, #0x10]
//   0x8144: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x8148: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x814c: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x8150: 910003fd  mov        x29, sp
//   0x8154: b9400828  ldr        w8, [x1, #8]
//   0x8158: 34000c88  cbz        w8, #0x82e8
//   0x815c: aa0103f4  mov        x20, x1
//   0x8160: b9401428  ldr        w8, [x1, #0x14]
//   0x8164: 34000c28  cbz        w8, #0x82e8
//   0x8168: b9401289  ldr        w9, [x20, #0x10]
//   0x816c: 34000be9  cbz        w9, #0x82e8
//   0x8170: 2a2803e8  mvn        w8, w8
//   0x8174: aa0003f3  mov        x19, x0
//   0x8178: 531f7d00  lsr        w0, w8, #0x1f
//   0x817c: d0ffffc1  adrp       x1, #0x2000
//   0x8180: 910a1421  add        x1, x1, #0x285
//   0x8184: 94000270  bl         #0x8b44
//   0x8188: b0ffffc1  adrp       x1, #0x1000
//   0x818c: 91356821  add        x1, x1, #0xd5a
//   0x8190: 52800020  mov        w0, #1
//   0x8194: 52800039  mov        w25, #1
//   0x8198: 9400026b  bl         #0x8b44
//   0x819c: b9401288  ldr        w8, [x20, #0x10]
//   0x81a0: d0ffffc1  adrp       x1, #0x2000
//   0x81a4: 910aa021  add        x1, x1, #0x2a8
//   0x81a8: 2a2803e8  mvn        w8, w8
//   0x81ac: 531f7d00  lsr        w0, w8, #0x1f
//   0x81b0: 94000265  bl         #0x8b44
//   0x81b4: b0000068  adrp       x8, #0x15000
//   0x81b8: f9400289  ldr        x9, [x20]
//   0x81bc: b9401e8a  ldr        w10, [x20, #0x1c]
//   0x81c0: f9401e8b  ldr        x11, [x20, #0x38]
//   0x81c4: f903b113  str        x19, [x8, #0x760]
//   0x81c8: f9005e69  str        x9, [x19, #0xb8]
//   0x81cc: b900526a  str        w10, [x19, #0x50]
//   0x81d0: f9002e6b  str        x11, [x19, #0x58]
//   0x81d4: 97fffe30  bl         #0x7a94
//   0x81d8: b9801288  ldrsw      x8, [x20, #0x10]
//   0x81dc: f9003260  str        x0, [x19, #0x60]
//   0x81e0: 528004e0  mov        w0, #0x27
//   0x81e4: b900567f  str        wzr, [x19, #0x54]
//   0x81e8: f9001268  str        x8, [x19, #0x20]
//   0x81ec: 940003b9  bl         #0x90d0
//   0x81f0: b0000028  adrp       x8, #0xd000
//   0x81f4: b0000029  adrp       x9, #0xd000
//   0x81f8: f9401275  ldr        x21, [x19, #0x20]
//   0x81fc: b000002a  adrp       x10, #0xd000
//   0x8200: b000002b  adrp       x11, #0xd000
//   0x8204: f941a108  ldr        x8, [x8, #0x340]
//   0x8208: f941a529  ldr        x9, [x9, #0x348]
//   0x820c: d503201f  nop        
//   0x8210: 9b150016  madd       x22, x0, x21, x0
//   0x8214: f941a94a  ldr        x10, [x10, #0x350]
//   0x8218: f941ad6b  ldr        x11, [x11, #0x358]
//   0x821c: f9001e60  str        x0, [x19, #0x38]
//   0x8220: a9002668  stp        x8, x9, [x19]
//   0x8224: b9400e88  ldr        w8, [x20, #0xc]
//   0x8228: aa1303e0  mov        x0, x19
//   0x822c: f900267f  str        xzr, [x19, #0x48]
//   0x8230: a9012e6a  stp        x10, x11, [x19, #0x10]
//   0x8234: b900b268  str        w8, [x19, #0xb0]
//   0x8238: b900427f  str        wzr, [x19, #0x40]
//   0x823c: 97ffff24  bl         #0x7ecc
//   0x8240: 9b155815  madd       x21, x0, x21, x22
//   0x8244: b0ffffc2  adrp       x2, #0x1000
//   0x8248: 91360042  add        x2, x2, #0xd80
//   0x824c: aa1303e0  mov        x0, x19
//   0x8250: aa1503e1  mov        x1, x21
//   0x8254: 940001d8  bl         #0x89b4
//   0x8258: f9401268  ldr        x8, [x19, #0x20]
//   0x825c: 52804b09  mov        w9, #0x258
//   0x8260: d0ffffd8  adrp       x24, #0x2000
//   0x8264: 911ab718  add        x24, x24, #0x6ad
//   0x8268: aa0003f6  mov        x22, x0
//   0x826c: aa1303e0  mov        x0, x19
//   0x8270: 9b097d17  mul        x23, x8, x9
//   0x8274: aa1803e2  mov        x2, x24
//   0x8278: aa1703e1  mov        x1, x23
//   0x827c: 940001ce  bl         #0x89b4
//   0x8280: aa0003e1  mov        x1, x0
//   0x8284: f9004e60  str        x0, [x19, #0x98]
//   0x8288: aa1303e0  mov        x0, x19
//   0x828c: aa1703e2  mov        x2, x23
//   0x8290: aa1803e3  mov        x3, x24
//   0x8294: 940001e6  bl         #0x8a2c
//   0x8298: f9404e6c  ldr        x12, [x19, #0x98]
//   0x829c: b900219f  str        wzr, [x12, #0x20]
//   0x82a0: a9017d9f  stp        xzr, xzr, [x12, #0x10]
//   0x82a4: a9137d9f  stp        xzr, xzr, [x12, #0x130]
//   0x82a8: f901299f  str        xzr, [x12, #0x250]
//   0x82ac: f901259f  str        xzr, [x12, #0x248]
//   0x82b0: f9401268  ldr        x8, [x19, #0x20]
//   0x82b4: 7100051f  cmp        w8, #1
//   0x82b8: 5400058b  b.lt       #0x8368
//   0x82bc: b0000029  adrp       x9, #0xd000
//   0x82c0: b000002a  adrp       x10, #0xd000
//   0x82c4: b000002b  adrp       x11, #0xd000
//   0x82c8: 92407d0d  and        x13, x8, #0xffffffff
//   0x82cc: f10009bf  cmp        x13, #2
//   0x82d0: f9419529  ldr        x9, [x9, #0x328]
//   0x82d4: f941994a  ldr        x10, [x10, #0x330]
//   0x82d8: f9419d6b  ldr        x11, [x11, #0x338]
//   0x82dc: 54000162  b.hs       #0x8308
//   0x82e0: aa1f03ee  mov        x14, xzr
//   0x82e4: 14000018  b          #0x8344
//   0x82e8: d503201f  nop        
//   0x82ec: 50fcf181  adr        x1, #0x211e
//   0x82f0: d0ffffc2  adrp       x2, #0x2000
//   0x82f4: 91028842  add        x2, x2, #0xa2
//   0x82f8: 528000c0  mov        w0, #6
//   0x82fc: 94000249  bl         #0x8c20
//   0x8300: 12800000  mov        w0, #-1
//   0x8304: 14000039  b          #0x83e8
//   0x8308: 9240010f  and        x15, x8, #1
//   0x830c: aa0c03f0  mov        x16, x12
//   0x8310: cb0f01ae  sub        x14, x13, x15
//   0x8314: aa0e03f1  mov        x17, x14
//   0x8318: f9012e09  str        x9, [x16, #0x258]
//   0x831c: f1000a31  subs       x17, x17, #2
//   0x8320: a9002a09  stp        x9, x10, [x16]
//   0x8324: f901320a  str        x10, [x16, #0x260]
//   0x8328: f900160b  str        x11, [x16, #0x28]
//   0x832c: f901420b  str        x11, [x16, #0x280]
//   0x8330: f900a20b  str        x11, [x16, #0x140]
//   0x8334: f901ce0b  str        x11, [x16, #0x398]
//   0x8338: 9112c210  add        x16, x16, #0x4b0
//   0x833c: 54fffee1  b.ne       #0x8318
//   0x8340: b400014f  cbz        x15, #0x8368
//   0x8344: 52804b0f  mov        w15, #0x258
//   0x8348: cb0e01ad  sub        x13, x13, x14
//   0x834c: 9b0f31cc  madd       x12, x14, x15, x12
//   0x8350: a9002989  stp        x9, x10, [x12]
//   0x8354: f10005ad  subs       x13, x13, #1
//   0x8358: f900158b  str        x11, [x12, #0x28]
//   0x835c: f900a18b  str        x11, [x12, #0x140]
//   0x8360: 9109618c  add        x12, x12, #0x258
//   0x8364: 54ffff61  b.ne       #0x8350
//   0x8368: d37df117  lsl        x23, x8, #3
//   0x836c: d0ffffd8  adrp       x24, #0x2000
//   0x8370: 910e7318  add        x24, x24, #0x39c
//   0x8374: aa1303e0  mov        x0, x19
//   0x8378: aa1703e1  mov        x1, x23
//   0x837c: aa1803e2  mov        x2, x24
//   0x8380: 9400018d  bl         #0x89b4
//   0x8384: aa0003e1  mov        x1, x0
//   0x8388: f9005260  str        x0, [x19, #0xa0]
//   0x838c: aa1303e0  mov        x0, x19
//   0x8390: aa1703e2  mov        x2, x23
//   0x8394: aa1803e3  mov        x3, x24
//   0x8398: 940001a5  bl         #0x8a2c
//   0x839c: b9401688  ldr        w8, [x20, #0x14]
//   0x83a0: 2a080729  orr        w9, w25, w8, lsl #1
//   0x83a4: 7100051f  cmp        w8, #1
//   0x83a8: 52800048  mov        w8, #2
//   0x83ac: 1a890108  csel       w8, w8, w9, eq
//   0x83b0: b900c268  str        w8, [x19, #0xc0]
//   0x83b4: 97fffef4  bl         #0x7f84
//   0x83b8: 97ffff00  bl         #0x7fb8
//   0x83bc: b940c269  ldr        w9, [x19, #0xc0]
//   0x83c0: 2a0003e8  mov        w8, w0
//   0x83c4: 2a1f03e0  mov        w0, wzr
//   0x83c8: 51000529  sub        w9, w9, #1
//   0x83cc: 1ac9090a  udiv       w10, w8, w9
//   0x83d0: 1b09a148  msub       w8, w10, w9, w8
//   0x83d4: b0000069  adrp       x9, #0x15000
//   0x83d8: 8b1602aa  add        x10, x21, x22
//   0x83dc: 11000508  add        w8, w8, #1
//   0x83e0: a902aa76  stp        x22, x10, [x19, #0x28]
//   0x83e4: b9076928  str        w8, [x9, #0x768]
//   0x83e8: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x83ec: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x83f0: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x83f4: f9400bf9  ldr        x25, [sp, #0x10]
//   0x83f8: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x83fc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[70] XasanFde_8400 (0x8400..0x8730, 816 bytes, 204 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8400..0x8730
// ----------------------------------------------------------------------------
//   0x8400: d101c3ff  sub        sp, sp, #0x70
//   0x8404: a9027bfd  stp        x29, x30, [sp, #0x20]
//   0x8408: a90367fa  stp        x26, x25, [sp, #0x30]
//   0x840c: a9045ff8  stp        x24, x23, [sp, #0x40]
//   0x8410: a90557f6  stp        x22, x21, [sp, #0x50]
//   0x8414: a9064ff4  stp        x20, x19, [sp, #0x60]
//   0x8418: 910083fd  add        x29, sp, #0x20
//   0x841c: b9405408  ldr        w8, [x0, #0x54]
//   0x8420: aa0003f3  mov        x19, x0
//   0x8424: 7100051f  cmp        w8, #1
//   0x8428: 54000101  b.ne       #0x8448
//   0x842c: b9405268  ldr        w8, [x19, #0x50]
//   0x8430: 34000328  cbz        w8, #0x8494
//   0x8434: d503201f  nop        
//   0x8438: 50fce721  adr        x1, #0x211e
//   0x843c: d0ffffc2  adrp       x2, #0x2000
//   0x8440: 911cb042  add        x2, x2, #0x72c
//   0x8444: 14000012  b          #0x848c
//   0x8448: aa1303f7  mov        x23, x19
//   0x844c: f8430ee8  ldr        x8, [x23, #0x30]!
//   0x8450: b4000168  cbz        x8, #0x847c
//   0x8454: b0000079  adrp       x25, #0x15000
//   0x8458: 395db328  ldrb       w8, [x25, #0x76c]
//   0x845c: 340002e8  cbz        w8, #0x84b8
//   0x8460: b9405268  ldr        w8, [x19, #0x50]
//   0x8464: 34000188  cbz        w8, #0x8494
//   0x8468: d503201f  nop        
//   0x846c: 50fce581  adr        x1, #0x211e
//   0x8470: d0ffffc2  adrp       x2, #0x2000
//   0x8474: 9106b042  add        x2, x2, #0x1ac
//   0x8478: 14000005  b          #0x848c
//   0x847c: d503201f  nop        
//   0x8480: 50fce4e1  adr        x1, #0x211e
//   0x8484: d0ffffc2  adrp       x2, #0x2000
//   0x8488: 91032442  add        x2, x2, #0xc9
//   0x848c: 528000c0  mov        w0, #6
//   0x8490: 940001e4  bl         #0x8c20
//   0x8494: aa1f03f5  mov        x21, xzr
//   0x8498: aa1503e0  mov        x0, x21
//   0x849c: a9464ff4  ldp        x20, x19, [sp, #0x60]
//   0x84a0: a94557f6  ldp        x22, x21, [sp, #0x50]
//   0x84a4: a9445ff8  ldp        x24, x23, [sp, #0x40]
//   0x84a8: a94367fa  ldp        x26, x25, [sp, #0x30]
//   0x84ac: a9427bfd  ldp        x29, x30, [sp, #0x20]
//   0x84b0: 9101c3ff  add        sp, sp, #0x70
//   0x84b4: d65f03c0  ret        
//   0x84b8: aa0103f4  mov        x20, x1
//   0x84bc: 52800028  mov        w8, #1
//   0x84c0: 391db328  strb       w8, [x25, #0x76c]
//   0x84c4: b40000a1  cbz        x1, #0x84d8
//   0x84c8: aa1303e0  mov        x0, x19
//   0x84cc: 97fffe80  bl         #0x7ecc
//   0x84d0: eb14001f  cmp        x0, x20
//   0x84d4: 540001a2  b.hs       #0x8508
//   0x84d8: b9405268  ldr        w8, [x19, #0x50]
//   0x84dc: 34000108  cbz        w8, #0x84fc
//   0x84e0: d503201f  nop        
//   0x84e4: 50fce1c1  adr        x1, #0x211e
//   0x84e8: b0ffffc2  adrp       x2, #0x1000
//   0x84ec: 913dc042  add        x2, x2, #0xf70
//   0x84f0: 528000c0  mov        w0, #6
//   0x84f4: aa1403e3  mov        x3, x20
//   0x84f8: 940001ca  bl         #0x8c20
//   0x84fc: aa1f03f5  mov        x21, xzr
//   0x8500: 391db33f  strb       wzr, [x25, #0x76c]
//   0x8504: 17ffffe5  b          #0x8498
//   0x8508: 9101a275  add        x21, x19, #0x68
//   0x850c: aa1503e0  mov        x0, x21
//   0x8510: 94000184  bl         #0x8b20
//   0x8514: f9404a76  ldr        x22, [x19, #0x90]
//   0x8518: f9401268  ldr        x8, [x19, #0x20]
//   0x851c: eb0802df  cmp        x22, x8
//   0x8520: 540000c2  b.hs       #0x8538
//   0x8524: 910006c8  add        x8, x22, #1
//   0x8528: aa1503e0  mov        x0, x21
//   0x852c: f9004a68  str        x8, [x19, #0x90]
//   0x8530: 94000184  bl         #0x8b40
//   0x8534: 14000012  b          #0x857c
//   0x8538: f9405668  ldr        x8, [x19, #0xa8]
//   0x853c: b4000f48  cbz        x8, #0x8724
//   0x8540: 97fffe9e  bl         #0x7fb8
//   0x8544: a94a226a  ldp        x10, x8, [x19, #0xa0]
//   0x8548: 2a0003e9  mov        w9, w0
//   0x854c: aa1503e0  mov        x0, x21
//   0x8550: 9ac8092b  udiv       x11, x9, x8
//   0x8554: 9b08a569  msub       x9, x11, x8, x9
//   0x8558: d1000508  sub        x8, x8, #1
//   0x855c: d37df129  lsl        x9, x9, #3
//   0x8560: f8696956  ldr        x22, [x10, x9]
//   0x8564: f9005668  str        x8, [x19, #0xa8]
//   0x8568: f8687948  ldr        x8, [x10, x8, lsl #3]
//   0x856c: f8296948  str        x8, [x10, x9]
//   0x8570: 94000174  bl         #0x8b40
//   0x8574: b10006df  cmn        x22, #1
//   0x8578: 54fffc20  b.eq       #0x84fc
//   0x857c: f9400668  ldr        x8, [x19, #8]
//   0x8580: aa1303e0  mov        x0, x19
//   0x8584: aa1603e1  mov        x1, x22
//   0x8588: d63f0100  blr        x8
//   0x858c: aa0003f5  mov        x21, x0
//   0x8590: 97fffe8a  bl         #0x7fb8
//   0x8594: f2400abf  tst        x21, #7
//   0x8598: 54000521  b.ne       #0x863c
//   0x859c: 37000500  tbnz       w0, #0, #0x863c
//   0x85a0: aa1303e0  mov        x0, x19
//   0x85a4: 97fffe4a  bl         #0x7ecc
//   0x85a8: aa0003f8  mov        x24, x0
//   0x85ac: aa1403e0  mov        x0, x20
//   0x85b0: 52800041  mov        w1, #2
//   0x85b4: 9400016f  bl         #0x8b70
//   0x85b8: 8b1802a8  add        x8, x21, x24
//   0x85bc: cb000108  sub        x8, x8, x0
//   0x85c0: aa1303e0  mov        x0, x19
//   0x85c4: 91001d08  add        x8, x8, #7
//   0x85c8: 927df115  and        x21, x8, #0xfffffffffffffff8
//   0x85cc: 97fffe40  bl         #0x7ecc
//   0x85d0: cb0003e8  neg        x8, x0
//   0x85d4: aa1303e0  mov        x0, x19
//   0x85d8: 8a0802b8  and        x24, x21, x8
//   0x85dc: 97fffe3c  bl         #0x7ecc
//   0x85e0: 8b000308  add        x8, x24, x0
//   0x85e4: eb0802bf  cmp        x21, x8
//   0x85e8: 540002a9  b.ls       #0x863c
//   0x85ec: b9405268  ldr        w8, [x19, #0x50]
//   0x85f0: 340001a8  cbz        w8, #0x8624
//   0x85f4: 9100a266  add        x6, x19, #0x28
//   0x85f8: d503201f  nop        
//   0x85fc: 50fcd901  adr        x1, #0x211e
//   0x8600: b0ffffc2  adrp       x2, #0x1000
//   0x8604: 913e8042  add        x2, x2, #0xfa0
//   0x8608: 528000c0  mov        w0, #6
//   0x860c: aa1303e3  mov        x3, x19
//   0x8610: aa1803e4  mov        x4, x24
//   0x8614: aa1503e5  mov        x5, x21
//   0x8618: aa1703e7  mov        x7, x23
//   0x861c: a9005bf4  stp        x20, x22, [sp]
//   0x8620: 94000180  bl         #0x8c20
//   0x8624: a94a226a  ldp        x10, x8, [x19, #0xa0]
//   0x8628: aa1f03f5  mov        x21, xzr
//   0x862c: 91000509  add        x9, x8, #1
//   0x8630: f9005669  str        x9, [x19, #0xa8]
//   0x8634: f8287956  str        x22, [x10, x8, lsl #3]
//   0x8638: 17ffffb2  b          #0x8500
//   0x863c: f9400e68  ldr        x8, [x19, #0x18]
//   0x8640: aa1303e0  mov        x0, x19
//   0x8644: aa1503e1  mov        x1, x21
//   0x8648: f9404e7a  ldr        x26, [x19, #0x98]
//   0x864c: d63f0100  blr        x8
//   0x8650: f9401e68  ldr        x8, [x19, #0x38]
//   0x8654: aa0003f7  mov        x23, x0
//   0x8658: b0ffffc3  adrp       x3, #0x1000
//   0x865c: 9137f063  add        x3, x3, #0xdfc
//   0x8660: aa1303e0  mov        x0, x19
//   0x8664: aa1403e2  mov        x2, x20
//   0x8668: cb0803e8  neg        x8, x8
//   0x866c: 8a0802a1  and        x1, x21, x8
//   0x8670: 940000ef  bl         #0x8a2c
//   0x8674: 37f804a0  tbnz       w0, #0x1f, #0x8708
//   0x8678: 52804b08  mov        w8, #0x258
//   0x867c: b9405269  ldr        w9, [x19, #0x50]
//   0x8680: d503201f  nop        
//   0x8684: 9b086af8  madd       x24, x23, x8, x26
//   0x8688: 71000d3f  cmp        w9, #3
//   0x868c: 54000221  b.ne       #0x86d0
//   0x8690: aa1303e0  mov        x0, x19
//   0x8694: 97fffe0e  bl         #0x7ecc
//   0x8698: cb0003e8  neg        x8, x0
//   0x869c: d503201f  nop        
//   0x86a0: 50fcd3e1  adr        x1, #0x211e
//   0x86a4: 8a0802a5  and        x5, x21, x8
//   0x86a8: a942a267  ldp        x7, x8, [x19, #0x28]
//   0x86ac: d0ffffc2  adrp       x2, #0x2000
//   0x86b0: 91168842  add        x2, x2, #0x5a2
//   0x86b4: 528000c0  mov        w0, #6
//   0x86b8: aa1303e3  mov        x3, x19
//   0x86bc: aa1803e4  mov        x4, x24
//   0x86c0: aa1503e6  mov        x6, x21
//   0x86c4: a900dbf4  stp        x20, x22, [sp, #8]
//   0x86c8: f90003e8  str        x8, [sp]
//   0x86cc: 94000155  bl         #0x8c20
//   0x86d0: f9400308  ldr        x8, [x24]
//   0x86d4: aa1803e0  mov        x0, x24
//   0x86d8: aa1503e1  mov        x1, x21
//   0x86dc: aa1403e2  mov        x2, x20
//   0x86e0: d63f0100  blr        x8
//   0x86e4: b9405668  ldr        w8, [x19, #0x54]
//   0x86e8: 35fff0c8  cbnz       w8, #0x8500
//   0x86ec: 52804b08  mov        w8, #0x258
//   0x86f0: f9405e61  ldr        x1, [x19, #0xb8]
//   0x86f4: d503201f  nop        
//   0x86f8: 9b086ae0  madd       x0, x23, x8, x26
//   0x86fc: f8428c08  ldr        x8, [x0, #0x28]!
//   0x8700: d63f0100  blr        x8
//   0x8704: 17ffff7f  b          #0x8500
//   0x8708: d503201f  nop        
//   0x870c: 50fcd081  adr        x1, #0x211e
//   0x8710: d0ffffc2  adrp       x2, #0x2000
//   0x8714: 910eb042  add        x2, x2, #0x3ac
//   0x8718: 528000c0  mov        w0, #6
//   0x871c: 94000141  bl         #0x8c20
//   0x8720: 17ffff77  b          #0x84fc
//   0x8724: aa1503e0  mov        x0, x21
//   0x8728: 94000106  bl         #0x8b40
//   0x872c: 17ffff74  b          #0x84fc

// ----------------------------------------------------------------------------
// FDE[71] XasanFde_8730 (0x8730..0x8744, 20 bytes, 5 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8730..0x8744
// ----------------------------------------------------------------------------
//   0x8730: f9401408  ldr        x8, [x0, #0x28]
//   0x8734: b9004002  str        w2, [x0, #0x40]
//   0x8738: f9002401  str        x1, [x0, #0x48]
//   0x873c: 3900011f  strb       wzr, [x8]
//   0x8740: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[72] XasanFde_8744 (0x8744..0x8758, 20 bytes, 5 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8744..0x8758
// ----------------------------------------------------------------------------
//   0x8744: 9101a000  add        x0, x0, #0x68
//   0x8748: b0000068  adrp       x8, #0x15000
//   0x874c: 52800029  mov        w9, #1
//   0x8750: 391db109  strb       w9, [x8, #0x76c]
//   0x8754: 140000f4  b          #0x8b24

// ----------------------------------------------------------------------------
// FDE[73] XasanFde_8758 (0x8758..0x8760, 8 bytes, 2 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8758..0x8760
// ----------------------------------------------------------------------------
//   0x8758: 9101a000  add        x0, x0, #0x68
//   0x875c: 140000f9  b          #0x8b40

// ----------------------------------------------------------------------------
// FDE[74] XasanFde_8760 (0x8760..0x8954, 500 bytes, 125 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8760..0x8954
// ----------------------------------------------------------------------------
//   0x8760: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x8764: a90167fa  stp        x26, x25, [sp, #0x10]
//   0x8768: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x876c: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x8770: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x8774: 910003fd  mov        x29, sp
//   0x8778: f9400c08  ldr        x8, [x0, #0x18]
//   0x877c: aa0103f7  mov        x23, x1
//   0x8780: aa0003f3  mov        x19, x0
//   0x8784: d63f0100  blr        x8
//   0x8788: aa0003f4  mov        x20, x0
//   0x878c: f9400668  ldr        x8, [x19, #8]
//   0x8790: aa1303e0  mov        x0, x19
//   0x8794: aa1403e1  mov        x1, x20
//   0x8798: d63f0100  blr        x8
//   0x879c: b9405668  ldr        w8, [x19, #0x54]
//   0x87a0: aa0003f6  mov        x22, x0
//   0x87a4: 7100051f  cmp        w8, #1
//   0x87a8: 54000281  b.ne       #0x87f8
//   0x87ac: b9405268  ldr        w8, [x19, #0x50]
//   0x87b0: 34000108  cbz        w8, #0x87d0
//   0x87b4: d503201f  nop        
//   0x87b8: 50fccb21  adr        x1, #0x211e
//   0x87bc: d0ffffc2  adrp       x2, #0x2000
//   0x87c0: 91245442  add        x2, x2, #0x915
//   0x87c4: 528000c0  mov        w0, #6
//   0x87c8: aa1603e3  mov        x3, x22
//   0x87cc: 94000115  bl         #0x8c20
//   0x87d0: aa1303e0  mov        x0, x19
//   0x87d4: 97fffdbe  bl         #0x7ecc
//   0x87d8: aa0003e2  mov        x2, x0
//   0x87dc: d0ffffc3  adrp       x3, #0x2000
//   0x87e0: 9128fc63  add        x3, x3, #0xa3f
//   0x87e4: aa1303e0  mov        x0, x19
//   0x87e8: aa1603e1  mov        x1, x22
//   0x87ec: 94000090  bl         #0x8a2c
//   0x87f0: 9101a275  add        x21, x19, #0x68
//   0x87f4: 1400004b  b          #0x8920
//   0x87f8: f9400e68  ldr        x8, [x19, #0x18]
//   0x87fc: aa1303e0  mov        x0, x19
//   0x8800: aa1703e1  mov        x1, x23
//   0x8804: f9404e7a  ldr        x26, [x19, #0x98]
//   0x8808: d63f0100  blr        x8
//   0x880c: 52804b08  mov        w8, #0x258
//   0x8810: aa0003f8  mov        x24, x0
//   0x8814: 9b086819  madd       x25, x0, x8, x26
//   0x8818: f9400b28  ldr        x8, [x25, #0x10]
//   0x881c: eb17011f  cmp        x8, x23
//   0x8820: 540002a0  b.eq       #0x8874
//   0x8824: 9101a275  add        x21, x19, #0x68
//   0x8828: aa1503e0  mov        x0, x21
//   0x882c: 940000bd  bl         #0x8b20
//   0x8830: 52800068  mov        w8, #3
//   0x8834: f9401669  ldr        x9, [x19, #0x28]
//   0x8838: b000006a  adrp       x10, #0x15000
//   0x883c: f9002677  str        x23, [x19, #0x48]
//   0x8840: b9004268  str        w8, [x19, #0x40]
//   0x8844: 3900013f  strb       wzr, [x9]
//   0x8848: 395db148  ldrb       w8, [x10, #0x76c]
//   0x884c: 34000108  cbz        w8, #0x886c
//   0x8850: d503201f  nop        
//   0x8854: 50fcc641  adr        x1, #0x211e
//   0x8858: b0ffffc2  adrp       x2, #0x1000
//   0x885c: 91364442  add        x2, x2, #0xd91
//   0x8860: 528000c0  mov        w0, #6
//   0x8864: 940000ef  bl         #0x8c20
//   0x8868: 14000034  b          #0x8938
//   0x886c: aa1503e0  mov        x0, x21
//   0x8870: 940000b4  bl         #0x8b40
//   0x8874: 9101a275  add        x21, x19, #0x68
//   0x8878: aa1503e0  mov        x0, x21
//   0x887c: 940000a9  bl         #0x8b20
//   0x8880: 52804b08  mov        w8, #0x258
//   0x8884: 9b086b08  madd       x8, x24, x8, x26
//   0x8888: b9402108  ldr        w8, [x8, #0x20]
//   0x888c: 340000e8  cbz        w8, #0x88a8
//   0x8890: 52800048  mov        w8, #2
//   0x8894: f9401669  ldr        x9, [x19, #0x28]
//   0x8898: f9002677  str        x23, [x19, #0x48]
//   0x889c: b9004268  str        w8, [x19, #0x40]
//   0x88a0: 3900013f  strb       wzr, [x9]
//   0x88a4: 14000025  b          #0x8938
//   0x88a8: 52804b08  mov        w8, #0x258
//   0x88ac: aa1903e0  mov        x0, x25
//   0x88b0: 9b086b08  madd       x8, x24, x8, x26
//   0x88b4: f9400508  ldr        x8, [x8, #8]
//   0x88b8: d63f0100  blr        x8
//   0x88bc: b0000077  adrp       x23, #0x15000
//   0x88c0: 395db2e8  ldrb       w8, [x23, #0x76c]
//   0x88c4: 350001a8  cbnz       w8, #0x88f8
//   0x88c8: 52800028  mov        w8, #1
//   0x88cc: b9405669  ldr        w9, [x19, #0x54]
//   0x88d0: 391db2e8  strb       w8, [x23, #0x76c]
//   0x88d4: 35000109  cbnz       w9, #0x88f4
//   0x88d8: 52804b08  mov        w8, #0x258
//   0x88dc: f9405e61  ldr        x1, [x19, #0xb8]
//   0x88e0: d503201f  nop        
//   0x88e4: 9b086b08  madd       x8, x24, x8, x26
//   0x88e8: 91050100  add        x0, x8, #0x140
//   0x88ec: f940a109  ldr        x9, [x8, #0x140]
//   0x88f0: d63f0120  blr        x9
//   0x88f4: 391db2ff  strb       wzr, [x23, #0x76c]
//   0x88f8: aa1503e0  mov        x0, x21
//   0x88fc: 94000091  bl         #0x8b40
//   0x8900: aa1303e0  mov        x0, x19
//   0x8904: 97fffd72  bl         #0x7ecc
//   0x8908: aa0003e2  mov        x2, x0
//   0x890c: b0ffffc3  adrp       x3, #0x1000
//   0x8910: 91360063  add        x3, x3, #0xd80
//   0x8914: aa1303e0  mov        x0, x19
//   0x8918: aa1603e1  mov        x1, x22
//   0x891c: 94000064  bl         #0x8aac
//   0x8920: aa1503e0  mov        x0, x21
//   0x8924: 9400007f  bl         #0x8b20
//   0x8928: a94a226a  ldp        x10, x8, [x19, #0xa0]
//   0x892c: 91000509  add        x9, x8, #1
//   0x8930: f9005669  str        x9, [x19, #0xa8]
//   0x8934: f8287954  str        x20, [x10, x8, lsl #3]
//   0x8938: aa1503e0  mov        x0, x21
//   0x893c: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x8940: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x8944: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x8948: a94167fa  ldp        x26, x25, [sp, #0x10]
//   0x894c: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x8950: 1400007c  b          #0x8b40

// ----------------------------------------------------------------------------
// FDE[75] XasanFde_8954 (0x8954..0x89b4, 96 bytes, 24 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8954..0x89b4
// ----------------------------------------------------------------------------
//   0x8954: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x8958: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x895c: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x8960: 910003fd  mov        x29, sp
//   0x8964: 9101a015  add        x21, x0, #0x68
//   0x8968: aa0003f4  mov        x20, x0
//   0x896c: aa1503e0  mov        x0, x21
//   0x8970: aa0103f3  mov        x19, x1
//   0x8974: 9400006b  bl         #0x8b20
//   0x8978: f9400e88  ldr        x8, [x20, #0x18]
//   0x897c: aa1403e0  mov        x0, x20
//   0x8980: aa1303e1  mov        x1, x19
//   0x8984: f9404e96  ldr        x22, [x20, #0x98]
//   0x8988: d63f0100  blr        x8
//   0x898c: 52804b08  mov        w8, #0x258
//   0x8990: 9b085808  madd       x8, x0, x8, x22
//   0x8994: aa1503e0  mov        x0, x21
//   0x8998: f9400d13  ldr        x19, [x8, #0x18]
//   0x899c: 94000069  bl         #0x8b40
//   0x89a0: aa1303e0  mov        x0, x19
//   0x89a4: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x89a8: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x89ac: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x89b0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[76] XasanFde_89b4 (0x89b4..0x8a2c, 120 bytes, 30 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x89b4..0x8a2c
// ----------------------------------------------------------------------------
//   0x89b4: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x89b8: f9000bf5  str        x21, [sp, #0x10]
//   0x89bc: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x89c0: 910003fd  mov        x29, sp
//   0x89c4: aa0203f3  mov        x19, x2
//   0x89c8: aa1f03e0  mov        x0, xzr
//   0x89cc: 2a1f03e2  mov        w2, wzr
//   0x89d0: 52800443  mov        w3, #0x22
//   0x89d4: 12800004  mov        w4, #-1
//   0x89d8: aa1f03e5  mov        x5, xzr
//   0x89dc: aa0103f4  mov        x20, x1
//   0x89e0: 940000a0  bl         #0x8c60
//   0x89e4: b100041f  cmn        x0, #1
//   0x89e8: aa0003f5  mov        x21, x0
//   0x89ec: 1a9f07e0  cset       w0, ne
//   0x89f0: d503201f  nop        
//   0x89f4: 70fcce21  adr        x1, #0x23bb
//   0x89f8: 94000053  bl         #0x8b44
//   0x89fc: 5289a820  mov        w0, #0x4d41
//   0x8a00: 2a1f03e1  mov        w1, wzr
//   0x8a04: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x8a08: aa1503e2  mov        x2, x21
//   0x8a0c: aa1403e3  mov        x3, x20
//   0x8a10: aa1303e4  mov        x4, x19
//   0x8a14: 9400014b  bl         #0x8f40
//   0x8a18: aa1503e0  mov        x0, x21
//   0x8a1c: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x8a20: f9400bf5  ldr        x21, [sp, #0x10]
//   0x8a24: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x8a28: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[77] XasanFde_8a2c (0x8a2c..0x8aac, 128 bytes, 32 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8a2c..0x8aac
// ----------------------------------------------------------------------------
//   0x8a2c: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x8a30: f9000bf5  str        x21, [sp, #0x10]
//   0x8a34: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x8a38: 910003fd  mov        x29, sp
//   0x8a3c: aa0203f4  mov        x20, x2
//   0x8a40: aa0103f5  mov        x21, x1
//   0x8a44: aa0103e0  mov        x0, x1
//   0x8a48: aa0203e1  mov        x1, x2
//   0x8a4c: 52800062  mov        w2, #3
//   0x8a50: aa0303f3  mov        x19, x3
//   0x8a54: 94000093  bl         #0x8ca0
//   0x8a58: 34000120  cbz        w0, #0x8a7c
//   0x8a5c: d0ffffc1  adrp       x1, #0x2000
//   0x8a60: 91047821  add        x1, x1, #0x11e
//   0x8a64: d0ffffc2  adrp       x2, #0x2000
//   0x8a68: 91070442  add        x2, x2, #0x1c1
//   0x8a6c: 528000c0  mov        w0, #6
//   0x8a70: 9400006c  bl         #0x8c20
//   0x8a74: 12800000  mov        w0, #-1
//   0x8a78: 14000009  b          #0x8a9c
//   0x8a7c: 5289a820  mov        w0, #0x4d41
//   0x8a80: 2a1f03e1  mov        w1, wzr
//   0x8a84: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x8a88: aa1503e2  mov        x2, x21
//   0x8a8c: aa1403e3  mov        x3, x20
//   0x8a90: aa1303e4  mov        x4, x19
//   0x8a94: 9400012b  bl         #0x8f40
//   0x8a98: 2a1f03e0  mov        w0, wzr
//   0x8a9c: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x8aa0: f9400bf5  ldr        x21, [sp, #0x10]
//   0x8aa4: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x8aa8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[78] XasanFde_8aac (0x8aac..0x8b20, 116 bytes, 29 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8aac..0x8b20
// ----------------------------------------------------------------------------
//   0x8aac: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x8ab0: f9000bf5  str        x21, [sp, #0x10]
//   0x8ab4: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x8ab8: 910003fd  mov        x29, sp
//   0x8abc: aa0303f3  mov        x19, x3
//   0x8ac0: aa0203f4  mov        x20, x2
//   0x8ac4: aa0103f5  mov        x21, x1
//   0x8ac8: aa0103e0  mov        x0, x1
//   0x8acc: aa0203e1  mov        x1, x2
//   0x8ad0: 2a1f03e2  mov        w2, wzr
//   0x8ad4: 52800643  mov        w3, #0x32
//   0x8ad8: 12800004  mov        w4, #-1
//   0x8adc: aa1f03e5  mov        x5, xzr
//   0x8ae0: 94000060  bl         #0x8c60
//   0x8ae4: b100041f  cmn        x0, #1
//   0x8ae8: d0ffffc1  adrp       x1, #0x2000
//   0x8aec: 9118f421  add        x1, x1, #0x63d
//   0x8af0: 1a9f07e0  cset       w0, ne
//   0x8af4: 94000014  bl         #0x8b44
//   0x8af8: 5289a820  mov        w0, #0x4d41
//   0x8afc: 2a1f03e1  mov        w1, wzr
//   0x8b00: 72aa6ac0  movk       w0, #0x5356, lsl #16
//   0x8b04: aa1503e2  mov        x2, x21
//   0x8b08: aa1403e3  mov        x3, x20
//   0x8b0c: aa1303e4  mov        x4, x19
//   0x8b10: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x8b14: f9400bf5  ldr        x21, [sp, #0x10]
//   0x8b18: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x8b1c: 14000109  b          #0x8f40

// ----------------------------------------------------------------------------
// FDE[79] XasanFde_8b20 (0x8b20..0x8b24, 4 bytes, 1 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8b20..0x8b24
// ----------------------------------------------------------------------------
//   0x8b20: 140000c8  b          #0x8e40

// ----------------------------------------------------------------------------
// FDE[80] _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error (0x8b24..0x8b40, 28 bytes, 7 instructions)
// Summary / Tóm tắt: Exported: gwp_asan::GuardedPoolAllocator::trapOnAddress(unsigned long, Error) (@ 0x8730..0x8744)
// ----------------------------------------------------------------------------
//   0x8b24: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x8b28: 910003fd  mov        x29, sp
//   0x8b2c: 9400016d  bl         #0x90e0
//   0x8b30: 7100001f  cmp        w0, #0
//   0x8b34: 1a9f17e0  cset       w0, eq
//   0x8b38: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x8b3c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[81] XasanFde_8b40 (0x8b40..0x8b44, 4 bytes, 1 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8b40..0x8b44
// ----------------------------------------------------------------------------
//   0x8b40: 140000c8  b          #0x8e60

// ----------------------------------------------------------------------------
// FDE[82] XasanFde_8b44 (0x8b44..0x8b70, 44 bytes, 11 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8b44..0x8b70
// ----------------------------------------------------------------------------
//   0x8b44: 7100041f  cmp        w0, #1
//   0x8b48: 54000041  b.ne       #0x8b50
//   0x8b4c: d65f03c0  ret        
//   0x8b50: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x8b54: 910003fd  mov        x29, sp
//   0x8b58: b0000028  adrp       x8, #0xd000
//   0x8b5c: f941b108  ldr        x8, [x8, #0x360]
//   0x8b60: b4000068  cbz        x8, #0x8b6c
//   0x8b64: aa0103e0  mov        x0, x1
//   0x8b68: 94000162  bl         #0x90f0
//   0x8b6c: 94000165  bl         #0x9100

// ----------------------------------------------------------------------------
// FDE[83] XasanFde_8b70 (0x8b70..0x8bd8, 104 bytes, 26 instructions)
// Summary / Tóm tắt: XASan / GWP-ASan subroutine @ 0x8b70..0x8bd8
// ----------------------------------------------------------------------------
//   0x8b70: 7100003f  cmp        w1, #0
//   0x8b74: 52800048  mov        w8, #2
//   0x8b78: 1a810108  csel       w8, w8, w1, eq
//   0x8b7c: 7100051f  cmp        w8, #1
//   0x8b80: 540000c0  b.eq       #0x8b98
//   0x8b84: 71000d1f  cmp        w8, #3
//   0x8b88: 540000c0  b.eq       #0x8ba0
//   0x8b8c: 91001c08  add        x8, x0, #7
//   0x8b90: 927df100  and        x0, x8, #0xfffffffffffffff8
//   0x8b94: d65f03c0  ret        
//   0x8b98: f1000c1f  cmp        x0, #3
//   0x8b9c: 54000042  b.hs       #0x8ba4
//   0x8ba0: d65f03c0  ret        
//   0x8ba4: f100141f  cmp        x0, #5
//   0x8ba8: 54000062  b.hs       #0x8bb4
//   0x8bac: 52800080  mov        w0, #4
//   0x8bb0: d65f03c0  ret        
//   0x8bb4: f100241f  cmp        x0, #9
//   0x8bb8: 54000062  b.hs       #0x8bc4
//   0x8bbc: 52800100  mov        w0, #8
//   0x8bc0: d65f03c0  ret        
//   0x8bc4: f2400c1f  tst        x0, #0xf
//   0x8bc8: 54fffec0  b.eq       #0x8ba0
//   0x8bcc: 927cec08  and        x8, x0, #0xfffffffffffffff0
//   0x8bd0: 91004100  add        x0, x8, #0x10
//   0x8bd4: d65f03c0  ret        

} // namespace nextai::opencut::npth_xasan
