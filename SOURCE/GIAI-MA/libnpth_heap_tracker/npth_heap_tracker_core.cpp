// ============================================================================
// File: npth_heap_tracker_core.cpp
// Target: libnpth_heap_tracker.so (43,176 bytes, SHA-256: ec2e686f2d21c863ea039279b9251d87a1becac552bc860bec3a401f22b045f8)
// Purpose: Clean-Room C++17 Implementation of ByteDance NPTH Native Heap Leak
//          Tracker, Bionic MallocDispatch & C++ Operator New Interceptor,
//          Pagemap/Smaps Dumper, and Complete 81-FDE AArch64 Disassembly Ledger.
// Mục đích: Tái tạo sạch C++17 cho trình theo dõi rò rỉ bộ nhớ Heap của NPTH
//           kèm sổ cái giải mã toàn bộ 81 FDE (6,075 lệnh AArch64).
// ============================================================================

#include "npth_heap_tracker.hpp"

namespace nextai::opencut::npth_heap_tracker {

const std::array<FdeDescriptor, kEhFrameFdeCount> kFdeTable = {{
    {  0U, 0x000037E0ULL, 0x000037F0ULL,   16U, 0x000029BCULL, "__on_dlclose_37e0", "Bionic __cxa_finalize at-unload thunk (@ 0x37e0..0x37f0)" },
    {  1U, 0x000037F0ULL, 0x000037F8ULL,    8U, 0x000029D0ULL, "HeapTrackerNoopRet_37f0", "BTI + ret no-op callback (@ 0x37f0..0x37f8)" },
    {  2U, 0x000037F8ULL, 0x00003800ULL,    8U, 0x000029E4ULL, "HeapTrackerNoopTail_37f8", "BTI + tail branch to 0x37f0 (@ 0x37f8..0x3800)" },
    {  3U, 0x00003800ULL, 0x00003814ULL,   20U, 0x000029F8ULL, "HeapTrackerIndirectCallIfNonNull_3800", "Indirect callback dispatcher if x0 != nullptr (@ 0x3800..0x3814)" },
    {  4U, 0x00003814ULL, 0x00003830ULL,   28U, 0x00002A0CULL, "__register_atfork_or_atexit_3814", "__cxa_atexit destructor registration (@ 0x3814..0x3830)" },
    {  5U, 0x00003830ULL, 0x00004010ULL, 2016U, 0x00002A20ULL, "HeapTrackerInitialize_3830", "Initializes HeapTracker, reads /heap_track.config, checks exynos9810, resolves dispatch (@ 0x3830..0x4010)" },
    {  6U, 0x00004010ULL, 0x00004060ULL,   80U, 0x00002A68ULL, "HeapTrackerControlCmd_4010", "State machine command entry (cmd 0..6 -> 0x46a0) (@ 0x4010..0x4060)" },
    {  7U, 0x00004060ULL, 0x000040ACULL,   76U, 0x00002A9CULL, "HeapTrackerGetMallinfoUordblks_4060", "Calls mallinfo() and returns uordblks ([sp, #0x40]) (@ 0x4060..0x40ac)" },
    {  8U, 0x000040ACULL, 0x000040FCULL,   80U, 0x00002ACCULL, "HeapTrackerCheckHeapSizeMb_40ac", "Checks heap size against 0x29736e9 (~41.4 MB) and logs in MB (>>20) (@ 0x40ac..0x40fc)" },
    {  9U, 0x000040FCULL, 0x00004114ULL,   24U, 0x00002AF4ULL, "HeapTrackerSetConfigParamA0_40fc", "Sets config parameter at manager+0xa0 (@ 0x40fc..0x4114)" },
    { 10U, 0x00004114ULL, 0x0000412CULL,   24U, 0x00002B08ULL, "HeapTrackerSetConfigParamA8_4114", "Sets config parameter at manager+0xa8 (@ 0x4114..0x412c)" },
    { 11U, 0x0000412CULL, 0x00004148ULL,   28U, 0x00002B1CULL, "HeapTrackerSetConfigParamB0_412c", "Sets config parameter at manager+0xb0 (@ 0x412c..0x4148)" },
    { 12U, 0x00004148ULL, 0x00004168ULL,   32U, 0x00002B30ULL, "HeapTrackerTriggerWaitOrCheck_4148", "Validates non-negative arg and tails into 0x45f4 (@ 0x4148..0x4168)" },
    { 13U, 0x00004168ULL, 0x00004208ULL,  160U, 0x00002B44ULL, "HeapTrackerFde_4168", "HeapTracker subroutine @ 0x4168..0x4208" },
    { 14U, 0x00004208ULL, 0x00004290ULL,  136U, 0x00002B78ULL, "HeapTrackerResolveLibcDispatch_4208", "Resolves __libc_globals and _ZL30__libc_malloc_default_dispatch (@ 0x4208..0x4290)" },
    { 15U, 0x00004290ULL, 0x00004538ULL,  680U, 0x00002B8CULL, "HeapTrackerInstallMallocDispatch_4290", "Installs HeapTracker hooks into Bionic MallocDispatch (@ 0x4290..0x4538)" },
    { 16U, 0x00004538ULL, 0x00004558ULL,   32U, 0x00002BB8ULL, "HeapTrackerRestoreReallocSlot_4538", "Restores MallocDispatch->realloc (+0x18) from default dispatch (@ 0x4538..0x4558)" },
    { 17U, 0x00004558ULL, 0x00004574ULL,   28U, 0x00002BCCULL, "HeapTrackerRestoreFreeSlot_4558", "Restores MallocDispatch->free (+0x08) from default dispatch (@ 0x4558..0x4574)" },
    { 18U, 0x00004574ULL, 0x00004594ULL,   32U, 0x00002BE0ULL, "HeapTrackerRestoreMallocSlot_4574", "Restores MallocDispatch->malloc (+0x00) from default dispatch (@ 0x4574..0x4594)" },
    { 19U, 0x00004594ULL, 0x000045B4ULL,   32U, 0x00002BF4ULL, "HeapTrackerRestoreUsableSizeSlot_4594", "Restores MallocDispatch->malloc_usable_size (+0x38) from default dispatch (@ 0x4594..0x45b4)" },
    { 20U, 0x000045B4ULL, 0x000045D4ULL,   32U, 0x00002C08ULL, "HeapTrackerRestoreMemalignSlot_45b4", "Restores MallocDispatch->memalign (+0x28) from default dispatch (@ 0x45b4..0x45d4)" },
    { 21U, 0x000045D4ULL, 0x000045F4ULL,   32U, 0x00002C1CULL, "HeapTrackerRestorePosixMemalignSlot_45d4", "Restores MallocDispatch->posix_memalign (+0x30) from default dispatch (@ 0x45d4..0x45f4)" },
    { 22U, 0x000045F4ULL, 0x000046A0ULL,  172U, 0x00002C34ULL, "HeapTrackerCheckThreshold50MB_45f4", "Checks if heap size >= 0x3200001 (~50 MB) (@ 0x45f4..0x46a0)" },
    { 23U, 0x000046A0ULL, 0x0000495CULL,  700U, 0x00002C70ULL, "HeapTrackerExecuteCommand_46a0", "Executes LEAK INIT / LEAK START / LEAK WAIT / LEAK DUMP / LEAK EXIT state machine (@ 0x46a0..0x495c)" },
    { 24U, 0x0000495CULL, 0x00004970ULL,   20U, 0x00002CC8ULL, "HeapTrackerNeonAdd2x64_495c", "NEON vector 2x64-bit addition: add v0.2d, v1.2d, v0.2d (@ 0x495c..0x4970)" },
    { 25U, 0x00004970ULL, 0x00004AA8ULL,  312U, 0x00002CDCULL, "HeapTrackerFde_4970", "HeapTracker subroutine @ 0x4970..0x4aa8" },
    { 26U, 0x00004AA8ULL, 0x00004B4CULL,  164U, 0x00002D18ULL, "HeapTrackerFde_4aa8", "HeapTracker subroutine @ 0x4aa8..0x4b4c" },
    { 27U, 0x00004B4CULL, 0x00004C20ULL,  212U, 0x00002D4CULL, "HeapTrackerFde_4b4c", "HeapTracker subroutine @ 0x4b4c..0x4c20" },
    { 28U, 0x00004C20ULL, 0x00006270ULL, 5712U, 0x00002D80ULL, "HeapTrackerForkAndDump_4c20", "Forks child process, reads /proc/self/pagemap & smaps, dumps leak_heap.txt (@ 0x4c20..0x6270)" },
    { 29U, 0x00006270ULL, 0x000063B0ULL,  320U, 0x00002DCCULL, "HeapTrackerHookMalloc_6270", "Hooked malloc with xpaclri (0xd50320ff @ 0x6290) LR stripping (@ 0x6270..0x63b0)" },
    { 30U, 0x000063B0ULL, 0x00006500ULL,  336U, 0x00002E14ULL, "HeapTrackerHookCalloc_63b0", "Hooked calloc with xpaclri (0xd50320ff @ 0x63d4) LR stripping (@ 0x63b0..0x6500)" },
    { 31U, 0x00006500ULL, 0x00006644ULL,  324U, 0x00002E60ULL, "HeapTrackerHookRealloc_6500", "Hooked realloc with xpaclri (0xd50320ff @ 0x6524) LR stripping (@ 0x6500..0x6644)" },
    { 32U, 0x00006644ULL, 0x00006774ULL,  304U, 0x00002EA8ULL, "HeapTrackerHookMemalign_6644", "Hooked memalign with xpaclri (0xd50320ff @ 0x6668) LR stripping (@ 0x6644..0x6774)" },
    { 33U, 0x00006774ULL, 0x000068B0ULL,  316U, 0x00002EF0ULL, "HeapTrackerHookPosixMemalign_6774", "Hooked posix_memalign with xpaclri (0xd50320ff @ 0x679c) LR stripping (@ 0x6774..0x68b0)" },
    { 34U, 0x000068B0ULL, 0x000068D8ULL,   40U, 0x00002F3CULL, "HeapTrackerPauseTracking_68b0", "Sets state = 4 (PAUSED) at manager+0x1f0 (@ 0x68b0..0x68d8)" },
    { 35U, 0x000068D8ULL, 0x0000693CULL,  100U, 0x00002F50ULL, "HeapTrackerFde_68d8", "HeapTracker subroutine @ 0x68d8..0x693c" },
    { 36U, 0x0000693CULL, 0x00006964ULL,   40U, 0x00002F64ULL, "HeapTrackerStopTracking_693c", "Sets state = 5 (STOPPED) at manager+0x1f0 (@ 0x693c..0x6964)" },
    { 37U, 0x00006964ULL, 0x000069DCULL,  120U, 0x00002F78ULL, "HeapTrackerFde_6964", "HeapTracker subroutine @ 0x6964..0x69dc" },
    { 38U, 0x000069DCULL, 0x00006A30ULL,   84U, 0x00002F8CULL, "HeapTrackerHookFree_69dc", "Hooked free masking top byte TBI (and x19, x19, #0xffffffffffffff @ 0x6a04) (@ 0x69dc..0x6a30)" },
    { 39U, 0x00006A30ULL, 0x00006C98ULL,  616U, 0x00002FB8ULL, "HeapTrackerFde_6a30", "HeapTracker subroutine @ 0x6a30..0x6c98" },
    { 40U, 0x00006C98ULL, 0x00006FD4ULL,  828U, 0x00002FF0ULL, "HeapTrackerFde_6c98", "HeapTracker subroutine @ 0x6c98..0x6fd4" },
    { 41U, 0x00006FD4ULL, 0x00007058ULL,  132U, 0x0000303CULL, "HeapTrackerFde_6fd4", "HeapTracker subroutine @ 0x6fd4..0x7058" },
    { 42U, 0x00007058ULL, 0x00007128ULL,  208U, 0x0000306CULL, "HeapTrackerFde_7058", "HeapTracker subroutine @ 0x7058..0x7128" },
    { 43U, 0x00007128ULL, 0x000071C0ULL,  152U, 0x00003080ULL, "HeapTrackerFde_7128", "HeapTracker subroutine @ 0x7128..0x71c0" },
    { 44U, 0x000071C0ULL, 0x00007340ULL,  384U, 0x000030B8ULL, "HeapTrackerFde_71c0", "HeapTracker subroutine @ 0x71c0..0x7340" },
    { 45U, 0x00007340ULL, 0x000073DCULL,  156U, 0x000030FCULL, "HeapTrackerFde_7340", "HeapTracker subroutine @ 0x7340..0x73dc" },
    { 46U, 0x000073DCULL, 0x0000742CULL,   80U, 0x00003130ULL, "HeapTrackerFde_73dc", "HeapTracker subroutine @ 0x73dc..0x742c" },
    { 47U, 0x0000742CULL, 0x0000746CULL,   64U, 0x00003158ULL, "HeapTrackerFde_742c", "HeapTracker subroutine @ 0x742c..0x746c" },
    { 48U, 0x0000746CULL, 0x000074B0ULL,   68U, 0x00003180ULL, "HeapTrackerFde_746c", "HeapTracker subroutine @ 0x746c..0x74b0" },
    { 49U, 0x000074B0ULL, 0x000074F4ULL,   68U, 0x000031A8ULL, "HeapTrackerFde_74b0", "HeapTracker subroutine @ 0x74b0..0x74f4" },
    { 50U, 0x000074F4ULL, 0x00007538ULL,   68U, 0x000031D0ULL, "HeapTrackerFde_74f4", "HeapTracker subroutine @ 0x74f4..0x7538" },
    { 51U, 0x00007538ULL, 0x000075B0ULL,  120U, 0x000031F8ULL, "HeapTrackerFde_7538", "HeapTracker subroutine @ 0x7538..0x75b0" },
    { 52U, 0x000075B0ULL, 0x00007618ULL,  104U, 0x00003224ULL, "HeapTrackerFde_75b0", "HeapTracker subroutine @ 0x75b0..0x7618" },
    { 53U, 0x00007618ULL, 0x00007684ULL,  108U, 0x00003258ULL, "HeapTrackerFde_7618", "HeapTracker subroutine @ 0x7618..0x7684" },
    { 54U, 0x00007684ULL, 0x00007690ULL,   12U, 0x0000328CULL, "HeapTrackerFde_7684", "HeapTracker subroutine @ 0x7684..0x7690" },
    { 55U, 0x00007690ULL, 0x000076F4ULL,  100U, 0x000032A0ULL, "HeapTrackerFde_7690", "HeapTracker subroutine @ 0x7690..0x76f4" },
    { 56U, 0x000076F4ULL, 0x00007710ULL,   28U, 0x000032CCULL, "HeapTrackerFde_76f4", "HeapTracker subroutine @ 0x76f4..0x7710" },
    { 57U, 0x00007710ULL, 0x00007924ULL,  532U, 0x000032F8ULL, "HeapTrackerFde_7710", "HeapTracker subroutine @ 0x7710..0x7924" },
    { 58U, 0x00007924ULL, 0x00007A0CULL,  232U, 0x00003338ULL, "HeapTrackerFde_7924", "HeapTracker subroutine @ 0x7924..0x7a0c" },
    { 59U, 0x00007A0CULL, 0x00007ABCULL,  176U, 0x00003370ULL, "HeapTrackerFde_7a0c", "HeapTracker subroutine @ 0x7a0c..0x7abc" },
    { 60U, 0x00007ABCULL, 0x00007C8CULL,  464U, 0x000033ACULL, "HeapTrackerFde_7abc", "HeapTracker subroutine @ 0x7abc..0x7c8c" },
    { 61U, 0x00007C8CULL, 0x00007D30ULL,  164U, 0x000033F4ULL, "HeapTrackerFde_7c8c", "HeapTracker subroutine @ 0x7c8c..0x7d30" },
    { 62U, 0x00007D30ULL, 0x00007DA4ULL,  116U, 0x00003428ULL, "HeapTrackerFde_7d30", "HeapTracker subroutine @ 0x7d30..0x7da4" },
    { 63U, 0x00007DA4ULL, 0x00008140ULL,  924U, 0x0000345CULL, "HeapTrackerFde_7da4", "HeapTracker subroutine @ 0x7da4..0x8140" },
    { 64U, 0x00008140ULL, 0x0000824CULL,  268U, 0x000034A8ULL, "HeapTrackerFde_8140", "HeapTracker subroutine @ 0x8140..0x824c" },
    { 65U, 0x0000824CULL, 0x000083ACULL,  352U, 0x000034E0ULL, "HeapTrackerFde_824c", "HeapTracker subroutine @ 0x824c..0x83ac" },
    { 66U, 0x000083ACULL, 0x000083F4ULL,   72U, 0x00003514ULL, "HeapTrackerFde_83ac", "HeapTracker subroutine @ 0x83ac..0x83f4" },
    { 67U, 0x000083F4ULL, 0x00008420ULL,   44U, 0x00003528ULL, "HeapTrackerFde_83f4", "HeapTracker subroutine @ 0x83f4..0x8420" },
    { 68U, 0x00008420ULL, 0x000087E8ULL,  968U, 0x0000353CULL, "HeapTrackerFde_8420", "HeapTracker subroutine @ 0x8420..0x87e8" },
    { 69U, 0x000087E8ULL, 0x00008944ULL,  348U, 0x00003550ULL, "HeapTrackerFde_87e8", "HeapTracker subroutine @ 0x87e8..0x8944" },
    { 70U, 0x00008944ULL, 0x00008CD4ULL,  912U, 0x00003594ULL, "HeapTrackerFde_8944", "HeapTracker subroutine @ 0x8944..0x8cd4" },
    { 71U, 0x00008CD4ULL, 0x00008D78ULL,  164U, 0x000035DCULL, "HeapTrackerFde_8cd4", "HeapTracker subroutine @ 0x8cd4..0x8d78" },
    { 72U, 0x00008D78ULL, 0x00008E74ULL,  252U, 0x00003610ULL, "HeapTrackerFde_8d78", "HeapTracker subroutine @ 0x8d78..0x8e74" },
    { 73U, 0x00008E74ULL, 0x00008F5CULL,  232U, 0x00003648ULL, "HeapTrackerFde_8e74", "HeapTracker subroutine @ 0x8e74..0x8f5c" },
    { 74U, 0x00008F5CULL, 0x00009064ULL,  264U, 0x00003684ULL, "HeapTrackerFde_8f5c", "HeapTracker subroutine @ 0x8f5c..0x9064" },
    { 75U, 0x00009064ULL, 0x00009108ULL,  164U, 0x000036C8ULL, "HeapTrackerFde_9064", "HeapTracker subroutine @ 0x9064..0x9108" },
    { 76U, 0x00009108ULL, 0x00009130ULL,   40U, 0x000036F4ULL, "HeapTrackerFde_9108", "HeapTracker subroutine @ 0x9108..0x9130" },
    { 77U, 0x00009130ULL, 0x00009164ULL,   52U, 0x00003720ULL, "HeapTrackerFde_9130", "HeapTracker subroutine @ 0x9130..0x9164" },
    { 78U, 0x00009164ULL, 0x000091FCULL,  152U, 0x00003734ULL, "HeapTrackerFde_9164", "HeapTracker subroutine @ 0x9164..0x91fc" },
    { 79U, 0x000091FCULL, 0x00009634ULL, 1080U, 0x00003764ULL, "HeapTrackerFde_91fc", "HeapTracker subroutine @ 0x91fc..0x9634" },
    { 80U, 0x00009634ULL, 0x000096CCULL,  152U, 0x000037A8ULL, "HeapTrackerFde_9634", "HeapTracker subroutine @ 0x9634..0x96cc" },
}};

namespace {

struct HeapTrackerStateInternal {
    std::uint64_t param_a0 = 0U;
    std::uint64_t param_a8 = 0U;
    std::int64_t  param_b0 = 0;
    std::int32_t  state_1f0 = 0;
    std::size_t   tracked_bytes = 0U;
};

HeapTrackerStateInternal g_heap_state;

int HeapTrackerInitialize_3830(const char* /*config_dir*/) noexcept {
    g_heap_state.state_1f0 = 1; // LEAK INIT
    return 0;
}

int HeapTrackerControlCmd_4010(int cmd) noexcept {
    if (cmd < 0 || cmd > 6) return -1;
    g_heap_state.state_1f0 = cmd;
    return 0;
}

std::size_t HeapTrackerGetMallinfoUordblks_4060() noexcept {
    return g_heap_state.tracked_bytes;
}

void HeapTrackerCheckHeapSizeMb_40ac() noexcept {
    const std::size_t sz = HeapTrackerGetMallinfoUordblks_4060();
    if (sz >= kHeapWarnBytes) {
        volatile std::size_t mb = sz >> 20U;
        (void)mb;
    }
}

void HeapTrackerSetConfigParamA0_40fc(std::uint64_t val) noexcept {
    g_heap_state.param_a0 = val;
}

void HeapTrackerSetConfigParamA8_4114(std::uint64_t val) noexcept {
    g_heap_state.param_a8 = val;
}

void HeapTrackerSetConfigParamB0_412c(int val) noexcept {
    g_heap_state.param_b0 = static_cast<std::int64_t>(val);
}

int HeapTrackerTriggerWaitOrCheck_4148(int arg) noexcept {
    if (arg < 0) return -15; // 0x4160: mov w0, #-0xf
    const std::size_t sz = HeapTrackerGetMallinfoUordblks_4060();
    return (sz >= kHeapDumpThresholdBytes) ? 1 : 0;
}

} // namespace

// FDE[24] 0x495c..0x4970 (20 bytes) — NEON 2x64-bit Vector Addition
//   0x495c: 3dc00020  ldr q0, [x1]
//   0x4960: 3dc00001  ldr q1, [x0]
//   0x4964: 4ee08420  add v0.2d, v1.2d, v0.2d
//   0x4968: 3d800000  str q0, [x0]
//   0x496c: d65f03c0  ret
void HeapTrackerNeonAdd2x64_495c(std::uint64_t dst[2], const std::uint64_t src[2]) noexcept {
    if (!dst || !src) return;
    dst[0] += src[0];
    dst[1] += src[1];
}

// FDE[38] 0x69dc..0x6a30 — Top-Byte-Ignore (TBI) 56-bit Address Masking (@ 0x6a04)
//   0x6a04: 9240de73  and x19, x19, #0xffffffffffffff
std::uintptr_t StripTbiAndPac_69dc(std::uintptr_t ptr) noexcept {
    return static_cast<std::uintptr_t>(ptr & kTbiPointerMask56Bit);
}

extern "C" {

// Export [71] .data 0x12008 (64 bytes = 8 function pointers)
HeapTrackerNativeInterface heap_tracker_native_interface_func = {
    &HeapTrackerInitialize_3830,
    &HeapTrackerControlCmd_4010,
    &HeapTrackerGetMallinfoUordblks_4060,
    &HeapTrackerCheckHeapSizeMb_40ac,
    &HeapTrackerSetConfigParamA0_40fc,
    &HeapTrackerSetConfigParamA8_4114,
    &HeapTrackerSetConfigParamB0_412c,
    &HeapTrackerTriggerWaitOrCheck_4148,
};

} // extern "C"

// ============================================================================
// Complete 81-FDE AArch64 Disassembly Reference (0x37e0..0x96cc, 6,075 insns)
// Sổ cái giải mã toàn bộ 6,075 lệnh AArch64 trên 81 FDE của libnpth_heap_tracker.so
// ============================================================================
// ----------------------------------------------------------------------------
// FDE[00] __on_dlclose_37e0 (0x37e0..0x37f0, 16 bytes, 4 instructions)
// Summary / Tóm tắt: Bionic __cxa_finalize at-unload thunk (@ 0x37e0..0x37f0)
// ----------------------------------------------------------------------------
//   0x37e0: d503245f  bti        c
//   0x37e4: d503201f  nop        
//   0x37e8: 10051a40  adr        x0, #0xdb30
//   0x37ec: 140017c1  b          #0x96f0

// ----------------------------------------------------------------------------
// FDE[01] HeapTrackerNoopRet_37f0 (0x37f0..0x37f8, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + ret no-op callback (@ 0x37f0..0x37f8)
// ----------------------------------------------------------------------------
//   0x37f0: d503245f  bti        c
//   0x37f4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[02] HeapTrackerNoopTail_37f8 (0x37f8..0x3800, 8 bytes, 2 instructions)
// Summary / Tóm tắt: BTI + tail branch to 0x37f0 (@ 0x37f8..0x3800)
// ----------------------------------------------------------------------------
//   0x37f8: d503245f  bti        c
//   0x37fc: 17fffffd  b          #0x37f0

// ----------------------------------------------------------------------------
// FDE[03] HeapTrackerIndirectCallIfNonNull_3800 (0x3800..0x3814, 20 bytes, 5 instructions)
// Summary / Tóm tắt: Indirect callback dispatcher if x0 != nullptr (@ 0x3800..0x3814)
// ----------------------------------------------------------------------------
//   0x3800: d503245f  bti        c
//   0x3804: b4000060  cbz        x0, #0x3810
//   0x3808: aa0003f0  mov        x16, x0
//   0x380c: d61f0200  br         x16
//   0x3810: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[04] __register_atfork_or_atexit_3814 (0x3814..0x3830, 28 bytes, 7 instructions)
// Summary / Tóm tắt: __cxa_atexit destructor registration (@ 0x3814..0x3830)
// ----------------------------------------------------------------------------
//   0x3814: d503245f  bti        c
//   0x3818: aa0003e1  mov        x1, x0
//   0x381c: d503201f  nop        
//   0x3820: 10ffff00  adr        x0, #0x3800
//   0x3824: d503201f  nop        
//   0x3828: 10051842  adr        x2, #0xdb30
//   0x382c: 140017b5  b          #0x9700

// ----------------------------------------------------------------------------
// FDE[05] HeapTrackerInitialize_3830 (0x3830..0x4010, 2016 bytes, 504 instructions)
// Summary / Tóm tắt: Initializes HeapTracker, reads /heap_track.config, checks exynos9810, resolves dispatch (@ 0x3830..0x4010)
// ----------------------------------------------------------------------------
//   0x3830: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x3834: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x3838: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x383c: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x3840: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x3844: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x3848: 910003fd  mov        x29, sp
//   0x384c: d11303ff  sub        sp, sp, #0x4c0
//   0x3850: d53bd058  mrs        x24, tpidr_el0
//   0x3854: f0000079  adrp       x25, #0x12000
//   0x3858: f9401708  ldr        x8, [x24, #0x28]
//   0x385c: f81f03a8  stur       x8, [x29, #-0x10]
//   0x3860: 39420328  ldrb       w8, [x25, #0x80]
//   0x3864: 36000068  tbz        w8, #0, #0x3870
//   0x3868: 2a1f03f3  mov        w19, wzr
//   0x386c: 1400014e  b          #0x3da4
//   0x3870: 2a0003f4  mov        w20, w0
//   0x3874: 51009008  sub        w8, w0, #0x24
//   0x3878: 31003d1f  cmn        w8, #0xf
//   0x387c: 54000062  b.hs       #0x3888
//   0x3880: 12800013  mov        w19, #-1
//   0x3884: 14000148  b          #0x3da4
//   0x3888: aa0103f5  mov        x21, x1
//   0x388c: 52800020  mov        w0, #1
//   0x3890: 52800501  mov        w1, #0x28
//   0x3894: aa0303f6  mov        x22, x3
//   0x3898: aa0203f3  mov        x19, x2
//   0x389c: 9400179d  bl         #0x9710
//   0x38a0: d503201f  nop        
//   0x38a4: 1007403a  adr        x26, #0x120a8
//   0x38a8: f9000340  str        x0, [x26]
//   0x38ac: b4000360  cbz        x0, #0x3918
//   0x38b0: 52a00408  mov        w8, #0x200000
//   0x38b4: f9000c08  str        x8, [x0, #0x18]
//   0x38b8: b4000376  cbz        x22, #0x3924
//   0x38bc: f0ffffe5  adrp       x5, #0x2000
//   0x38c0: 9103a8a5  add        x5, x5, #0xea
//   0x38c4: 9102c3e0  add        x0, sp, #0xb0
//   0x38c8: aa1603e4  mov        x4, x22
//   0x38cc: 94000227  bl         #0x4168
//   0x38d0: 7100041f  cmp        w0, #1
//   0x38d4: 5400026b  b.lt       #0x3920
//   0x38d8: d0ffffe1  adrp       x1, #0x1000
//   0x38dc: 913e0c21  add        x1, x1, #0xf83
//   0x38e0: 9102c3e0  add        x0, sp, #0xb0
//   0x38e4: 9400178f  bl         #0x9720
//   0x38e8: b40001c0  cbz        x0, #0x3920
//   0x38ec: aa0003f6  mov        x22, x0
//   0x38f0: 9102c3e0  add        x0, sp, #0xb0
//   0x38f4: 52808001  mov        w1, #0x400
//   0x38f8: aa1603e2  mov        x2, x22
//   0x38fc: 9400178d  bl         #0x9730
//   0x3900: b4001600  cbz        x0, #0x3bc0
//   0x3904: 910243fb  add        x27, sp, #0x90
//   0x3908: 528e8c5c  mov        w28, #0x7462
//   0x390c: f0fffff7  adrp       x23, #0x2000
//   0x3910: 9106f6f7  add        x23, x23, #0x1bd
//   0x3914: 1400005c  b          #0x3a84
//   0x3918: 12800193  mov        w19, #-0xd
//   0x391c: 14000122  b          #0x3da4
//   0x3920: f9400340  ldr        x0, [x26]
//   0x3924: 0f000420  movi       v0.2s, #1
//   0x3928: fd000400  str        d0, [x0, #8]
//   0x392c: b40000b5  cbz        x21, #0x3940
//   0x3930: aa1503e0  mov        x0, x21
//   0x3934: 94001783  bl         #0x9740
//   0x3938: f9400348  ldr        x8, [x26]
//   0x393c: f9001100  str        x0, [x8, #0x20]
//   0x3940: f0000076  adrp       x22, #0x12000
//   0x3944: aa1303e0  mov        x0, x19
//   0x3948: b9006ad4  str        w20, [x22, #0x68]
//   0x394c: 94000f6a  bl         #0x76f4
//   0x3950: f0000075  adrp       x21, #0x12000
//   0x3954: f0000077  adrp       x23, #0x12000
//   0x3958: f9404ea0  ldr        x0, [x21, #0x98]
//   0x395c: b50000c0  cbnz       x0, #0x3974
//   0x3960: d0ffffe0  adrp       x0, #0x1000
//   0x3964: 912d0800  add        x0, x0, #0xb42
//   0x3968: 9400177a  bl         #0x9750
//   0x396c: f9004ea0  str        x0, [x21, #0x98]
//   0x3970: b4001300  cbz        x0, #0x3bd0
//   0x3974: f0ffffe1  adrp       x1, #0x2000
//   0x3978: 91150021  add        x1, x1, #0x540
//   0x397c: 9102c3e2  add        x2, sp, #0xb0
//   0x3980: 94001778  bl         #0x9760
//   0x3984: b40006a0  cbz        x0, #0x3a58
//   0x3988: f9405be8  ldr        x8, [sp, #0xb0]
//   0x398c: f000007a  adrp       x26, #0x12000
//   0x3990: f9003ee0  str        x0, [x23, #0x78]
//   0x3994: f9004b48  str        x8, [x26, #0x90]
//   0x3998: 94001776  bl         #0x9770
//   0x399c: b9406ac8  ldr        w8, [x22, #0x68]
//   0x39a0: 51005508  sub        w8, w8, #0x15
//   0x39a4: 7100391f  cmp        w8, #0xe
//   0x39a8: 54001248  b.hi       #0x3bf0
//   0x39ac: d503201f  nop        
//   0x39b0: 10ff010d  adr        x13, #0x19d0
//   0x39b4: aa1f03fb  mov        x27, xzr
//   0x39b8: 93407c13  sxtw       x19, w0
//   0x39bc: 52800409  mov        w9, #0x20
//   0x39c0: 5280060a  mov        w10, #0x30
//   0x39c4: 100000ce  adr        x14, #0x39dc
//   0x39c8: 386869af  ldrb       w15, [x13, x8]
//   0x39cc: 8b0f09ce  add        x14, x14, x15, lsl #2
//   0x39d0: 5280070c  mov        w12, #0x38
//   0x39d4: 5280072b  mov        w11, #0x39
//   0x39d8: d61f01c0  br         x14
//   0x39dc: f9404ea0  ldr        x0, [x21, #0x98]
//   0x39e0: b50000c0  cbnz       x0, #0x39f8
//   0x39e4: d0ffffe0  adrp       x0, #0x1000
//   0x39e8: 912d0800  add        x0, x0, #0xb42
//   0x39ec: 94001759  bl         #0x9750
//   0x39f0: f9004ea0  str        x0, [x21, #0x98]
//   0x39f4: b40027c0  cbz        x0, #0x3eec
//   0x39f8: f0ffffe1  adrp       x1, #0x2000
//   0x39fc: 910a3421  add        x1, x1, #0x28d
//   0x3a00: aa1f03e2  mov        x2, xzr
//   0x3a04: 94001757  bl         #0x9760
//   0x3a08: f0000068  adrp       x8, #0x12000
//   0x3a0c: f9004500  str        x0, [x8, #0x88]
//   0x3a10: b40027e0  cbz        x0, #0x3f0c
//   0x3a14: aa1f03e0  mov        x0, xzr
//   0x3a18: aa1303e1  mov        x1, x19
//   0x3a1c: 52800062  mov        w2, #3
//   0x3a20: 52800443  mov        w3, #0x22
//   0x3a24: 12800004  mov        w4, #-1
//   0x3a28: aa1f03e5  mov        x5, xzr
//   0x3a2c: 94001755  bl         #0x9780
//   0x3a30: b100041f  cmn        x0, #1
//   0x3a34: 54001f81  b.ne       #0x3e24
//   0x3a38: d503201f  nop        
//   0x3a3c: 10fefe01  adr        x1, #0x19fc
//   0x3a40: d0ffffe2  adrp       x2, #0x1000
//   0x3a44: 913ac842  add        x2, x2, #0xeb2
//   0x3a48: 528000c0  mov        w0, #6
//   0x3a4c: 94001751  bl         #0x9790
//   0x3a50: 128000b3  mov        w19, #-6
//   0x3a54: 14000096  b          #0x3cac
//   0x3a58: 12800053  mov        w19, #-3
//   0x3a5c: 1400009a  b          #0x3cc4
//   0x3a60: 910043e0  add        x0, sp, #0x10
//   0x3a64: 9400174f  bl         #0x97a0
//   0x3a68: f9400348  ldr        x8, [x26]
//   0x3a6c: b9000100  str        w0, [x8]
//   0x3a70: 9102c3e0  add        x0, sp, #0xb0
//   0x3a74: 52808001  mov        w1, #0x400
//   0x3a78: aa1603e2  mov        x2, x22
//   0x3a7c: 9400172d  bl         #0x9730
//   0x3a80: b4000a00  cbz        x0, #0x3bc0
//   0x3a84: 9102c3e0  add        x0, sp, #0xb0
//   0x3a88: 910243e2  add        x2, sp, #0x90
//   0x3a8c: 910043e3  add        x3, sp, #0x10
//   0x3a90: aa1703e1  mov        x1, x23
//   0x3a94: 94001747  bl         #0x97b0
//   0x3a98: 7100081f  cmp        w0, #2
//   0x3a9c: 54fffea1  b.ne       #0x3a70
//   0x3aa0: 394243e8  ldrb       w8, [sp, #0x90]
//   0x3aa4: 7101b51f  cmp        w8, #0x6d
//   0x3aa8: 54000280  b.eq       #0x3af8
//   0x3aac: 7101911f  cmp        w8, #0x64
//   0x3ab0: 54000461  b.ne       #0x3b3c
//   0x3ab4: b94093e8  ldr        w8, [sp, #0x90]
//   0x3ab8: 528cac8a  mov        w10, #0x6564
//   0x3abc: 394253e9  ldrb       w9, [sp, #0x94]
//   0x3ac0: 72aeac4a  movk       w10, #0x7562, lsl #16
//   0x3ac4: 6b0a011f  cmp        w8, w10
//   0x3ac8: 52800ce8  mov        w8, #0x67
//   0x3acc: 7a480120  ccmp       w9, w8, #0, eq
//   0x3ad0: 54fffd01  b.ne       #0x3a70
//   0x3ad4: b94013e8  ldr        w8, [sp, #0x10]
//   0x3ad8: 528e4e89  mov        w9, #0x7274
//   0x3adc: 72acaea9  movk       w9, #0x6575, lsl #16
//   0x3ae0: 6b09011f  cmp        w8, w9
//   0x3ae4: 54fffc61  b.ne       #0x3a70
//   0x3ae8: f9400348  ldr        x8, [x26]
//   0x3aec: 52800029  mov        w9, #1
//   0x3af0: b9000509  str        w9, [x8, #4]
//   0x3af4: 17ffffdf  b          #0x3a70
//   0x3af8: b8407368  ldur       w8, [x27, #7]
//   0x3afc: 528f2a89  mov        w9, #0x7954
//   0x3b00: 72acae09  movk       w9, #0x6570, lsl #16
//   0x3b04: 6b09011f  cmp        w8, w9
//   0x3b08: 54fffac0  b.eq       #0x3a60
//   0x3b0c: b8407368  ldur       w8, [x27, #7]
//   0x3b10: 528d2a69  mov        w9, #0x6953
//   0x3b14: 72acaf49  movk       w9, #0x657a, lsl #16
//   0x3b18: 6b09011f  cmp        w8, w9
//   0x3b1c: 54fffaa1  b.ne       #0x3a70
//   0x3b20: 910043e0  add        x0, sp, #0x10
//   0x3b24: 910023e1  add        x1, sp, #8
//   0x3b28: 52800142  mov        w2, #0xa
//   0x3b2c: 94001725  bl         #0x97c0
//   0x3b30: f9400348  ldr        x8, [x26]
//   0x3b34: f9000900  str        x0, [x8, #0x10]
//   0x3b38: 17ffffce  b          #0x3a70
//   0x3b3c: 794123e8  ldrh       w8, [sp, #0x90]
//   0x3b40: 6b1c011f  cmp        w8, w28
//   0x3b44: 54fff961  b.ne       #0x3a70
//   0x3b48: b8402368  ldur       w8, [x27, #2]
//   0x3b4c: 528d88c9  mov        w9, #0x6c46
//   0x3b50: 72acec29  movk       w9, #0x6761, lsl #16
//   0x3b54: 6b09011f  cmp        w8, w9
//   0x3b58: 54000220  b.eq       #0x3b9c
//   0x3b5c: b8402368  ldur       w8, [x27, #2]
//   0x3b60: 528d2a69  mov        w9, #0x6953
//   0x3b64: 72acaf49  movk       w9, #0x657a, lsl #16
//   0x3b68: 6b09011f  cmp        w8, w9
//   0x3b6c: 54fff821  b.ne       #0x3a70
//   0x3b70: 910043e0  add        x0, sp, #0x10
//   0x3b74: 910023e1  add        x1, sp, #8
//   0x3b78: 52800142  mov        w2, #0xa
//   0x3b7c: 94001711  bl         #0x97c0
//   0x3b80: d376d409  lsl        x9, x0, #0xa
//   0x3b84: 52a0010a  mov        w10, #0x80000
//   0x3b88: f142013f  cmp        x9, #0x80, lsl #12
//   0x3b8c: f9400348  ldr        x8, [x26]
//   0x3b90: 9a8a8129  csel       x9, x9, x10, hi
//   0x3b94: f9000d09  str        x9, [x8, #0x18]
//   0x3b98: 17ffffb6  b          #0x3a70
//   0x3b9c: 910043e0  add        x0, sp, #0x10
//   0x3ba0: 910023e1  add        x1, sp, #8
//   0x3ba4: 52800142  mov        w2, #0xa
//   0x3ba8: 94001706  bl         #0x97c0
//   0x3bac: f9400348  ldr        x8, [x26]
//   0x3bb0: 53010409  ubfx       w9, w0, #1, #1
//   0x3bb4: 1200000a  and        w10, w0, #1
//   0x3bb8: 2901250a  stp        w10, w9, [x8, #8]
//   0x3bbc: 17ffffad  b          #0x3a70
//   0x3bc0: aa1603e0  mov        x0, x22
//   0x3bc4: 94001703  bl         #0x97d0
//   0x3bc8: b5ffeb55  cbnz       x21, #0x3930
//   0x3bcc: 17ffff5d  b          #0x3940
//   0x3bd0: d503201f  nop        
//   0x3bd4: 10fef141  adr        x1, #0x19fc
//   0x3bd8: d0ffffe2  adrp       x2, #0x1000
//   0x3bdc: 912d2842  add        x2, x2, #0xb4a
//   0x3be0: 528000c0  mov        w0, #6
//   0x3be4: 940016eb  bl         #0x9790
//   0x3be8: 12800053  mov        w19, #-3
//   0x3bec: 14000036  b          #0x3cc4
//   0x3bf0: 12800013  mov        w19, #-1
//   0x3bf4: 1400002e  b          #0x3cac
//   0x3bf8: 5280076b  mov        w11, #0x3b
//   0x3bfc: aa0b03ec  mov        x12, x11
//   0x3c00: aa0c03ea  mov        x10, x12
//   0x3c04: aa0a03e9  mov        x9, x10
//   0x3c08: aa0903fb  mov        x27, x9
//   0x3c0c: f9404ea0  ldr        x0, [x21, #0x98]
//   0x3c10: b50000c0  cbnz       x0, #0x3c28
//   0x3c14: d0ffffe0  adrp       x0, #0x1000
//   0x3c18: 912d0800  add        x0, x0, #0xb42
//   0x3c1c: 940016cd  bl         #0x9750
//   0x3c20: f9004ea0  str        x0, [x21, #0x98]
//   0x3c24: b4000260  cbz        x0, #0x3c70
//   0x3c28: f0ffffe1  adrp       x1, #0x2000
//   0x3c2c: 91093021  add        x1, x1, #0x24c
//   0x3c30: aa1f03e2  mov        x2, xzr
//   0x3c34: 940016cb  bl         #0x9760
//   0x3c38: aa0003f4  mov        x20, x0
//   0x3c3c: b4000280  cbz        x0, #0x3c8c
//   0x3c40: f2402e9f  tst        x20, #0xfff
//   0x3c44: 54000241  b.ne       #0x3c8c
//   0x3c48: b9406ac9  ldr        w9, [x22, #0x68]
//   0x3c4c: 52800908  mov        w8, #0x48
//   0x3c50: 7100753f  cmp        w9, #0x1d
//   0x3c54: 54000ca0  b.eq       #0x3de8
//   0x3c58: 71008d3f  cmp        w9, #0x23
//   0x3c5c: 54000c60  b.eq       #0x3de8
//   0x3c60: 7100893f  cmp        w9, #0x22
//   0x3c64: 54000ba1  b.ne       #0x3dd8
//   0x3c68: 52800b08  mov        w8, #0x58
//   0x3c6c: 1400005f  b          #0x3de8
//   0x3c70: d503201f  nop        
//   0x3c74: 10feec41  adr        x1, #0x19fc
//   0x3c78: d0ffffe2  adrp       x2, #0x1000
//   0x3c7c: 912d2842  add        x2, x2, #0xb4a
//   0x3c80: 528000c0  mov        w0, #6
//   0x3c84: 940016c3  bl         #0x9790
//   0x3c88: aa1f03f4  mov        x20, xzr
//   0x3c8c: 92402e83  and        x3, x20, #0xfff
//   0x3c90: d503201f  nop        
//   0x3c94: 10feeb41  adr        x1, #0x19fc
//   0x3c98: f0ffffe2  adrp       x2, #0x2000
//   0x3c9c: 91146842  add        x2, x2, #0x51a
//   0x3ca0: 528000c0  mov        w0, #6
//   0x3ca4: 940016bb  bl         #0x9790
//   0x3ca8: 12800093  mov        w19, #-5
//   0x3cac: d503201f  nop        
//   0x3cb0: 10feea61  adr        x1, #0x19fc
//   0x3cb4: d0ffffe2  adrp       x2, #0x1000
//   0x3cb8: 912bd842  add        x2, x2, #0xaf6
//   0x3cbc: 528000c0  mov        w0, #6
//   0x3cc0: 940016b4  bl         #0x9790
//   0x3cc4: d503201f  nop        
//   0x3cc8: 10fee9a1  adr        x1, #0x19fc
//   0x3ccc: d0ffffe2  adrp       x2, #0x1000
//   0x3cd0: 91320042  add        x2, x2, #0xc80
//   0x3cd4: 528000c0  mov        w0, #6
//   0x3cd8: 2a1303e3  mov        w3, w19
//   0x3cdc: 940016ad  bl         #0x9790
//   0x3ce0: f9403ee9  ldr        x9, [x23, #0x78]
//   0x3ce4: b4000589  cbz        x9, #0x3d94
//   0x3ce8: f0000068  adrp       x8, #0x12000
//   0x3cec: b9406aca  ldr        w10, [x22, #0x68]
//   0x3cf0: f9404508  ldr        x8, [x8, #0x88]
//   0x3cf4: b40001e8  cbz        x8, #0x3d30
//   0x3cf8: 5100554b  sub        w11, w10, #0x15
//   0x3cfc: 7100097f  cmp        w11, #2
//   0x3d00: 54000208  b.hi       #0x3d40
//   0x3d04: f0000074  adrp       x20, #0x12000
//   0x3d08: f9000109  str        x9, [x8]
//   0x3d0c: f9403a80  ldr        x0, [x20, #0x70]
//   0x3d10: b4000420  cbz        x0, #0x3d94
//   0x3d14: f0000068  adrp       x8, #0x12000
//   0x3d18: f9404901  ldr        x1, [x8, #0x90]
//   0x3d1c: 940016b1  bl         #0x97e0
//   0x3d20: f9003a9f  str        xzr, [x20, #0x70]
//   0x3d24: f9404ea0  ldr        x0, [x21, #0x98]
//   0x3d28: b50003a0  cbnz       x0, #0x3d9c
//   0x3d2c: 1400001e  b          #0x3da4
//   0x3d30: 51006148  sub        w8, w10, #0x18
//   0x3d34: 7100251f  cmp        w8, #9
//   0x3d38: 540000c9  b.ls       #0x3d50
//   0x3d3c: 14000016  b          #0x3d94
//   0x3d40: 51006149  sub        w9, w10, #0x18
//   0x3d44: 7100253f  cmp        w9, #9
//   0x3d48: 54000268  b.hi       #0x3d94
//   0x3d4c: f900011f  str        xzr, [x8]
//   0x3d50: f0000068  adrp       x8, #0x12000
//   0x3d54: f9404908  ldr        x8, [x8, #0x90]
//   0x3d58: 927df108  and        x8, x8, #0xfffffffffffffff8
//   0x3d5c: f100051f  cmp        x8, #1
//   0x3d60: 540001ab  b.lt       #0x3d94
//   0x3d64: f0000069  adrp       x9, #0x12000
//   0x3d68: 2a1f03e1  mov        w1, wzr
//   0x3d6c: f9403920  ldr        x0, [x9, #0x70]
//   0x3d70: 8b000108  add        x8, x8, x0
//   0x3d74: 91002009  add        x9, x0, #8
//   0x3d78: eb09011f  cmp        x8, x9
//   0x3d7c: 9a898108  csel       x8, x8, x9, hi
//   0x3d80: aa2003e9  mvn        x9, x0
//   0x3d84: 8b090108  add        x8, x8, x9
//   0x3d88: 927df108  and        x8, x8, #0xfffffffffffffff8
//   0x3d8c: 91002102  add        x2, x8, #8
//   0x3d90: 94001698  bl         #0x97f0
//   0x3d94: f9404ea0  ldr        x0, [x21, #0x98]
//   0x3d98: b4000060  cbz        x0, #0x3da4
//   0x3d9c: 94001699  bl         #0x9800
//   0x3da0: f9004ebf  str        xzr, [x21, #0x98]
//   0x3da4: f9401708  ldr        x8, [x24, #0x28]
//   0x3da8: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x3dac: eb09011f  cmp        x8, x9
//   0x3db0: 540012e1  b.ne       #0x400c
//   0x3db4: 2a1303e0  mov        w0, w19
//   0x3db8: 911303ff  add        sp, sp, #0x4c0
//   0x3dbc: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x3dc0: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x3dc4: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x3dc8: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x3dcc: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x3dd0: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x3dd4: d65f03c0  ret        
//   0x3dd8: 51007928  sub        w8, w9, #0x1e
//   0x3ddc: 71000d1f  cmp        w8, #3
//   0x3de0: 540000a8  b.hi       #0x3df4
//   0x3de4: 52800a08  mov        w8, #0x50
//   0x3de8: 8b140108  add        x8, x8, x20
//   0x3dec: f0000069  adrp       x9, #0x12000
//   0x3df0: f9004528  str        x8, [x9, #0x88]
//   0x3df4: aa1403e0  mov        x0, x20
//   0x3df8: aa1303e1  mov        x1, x19
//   0x3dfc: 52800062  mov        w2, #3
//   0x3e00: 94001684  bl         #0x9810
//   0x3e04: 35fff520  cbnz       w0, #0x3ca8
//   0x3e08: b9406ac8  ldr        w8, [x22, #0x68]
//   0x3e0c: d1004369  sub        x9, x27, #0x10
//   0x3e10: 71008d1f  cmp        w8, #0x23
//   0x3e14: 9a9b0128  csel       x8, x9, x27, eq
//   0x3e18: 91011d08  add        x8, x8, #0x47
//   0x3e1c: 927be908  and        x8, x8, #0xffffffffffffffe0
//   0x3e20: 8b140100  add        x0, x8, x20
//   0x3e24: f0000074  adrp       x20, #0x12000
//   0x3e28: d503201f  nop        
//   0x3e2c: 10fede81  adr        x1, #0x19fc
//   0x3e30: d0ffffe2  adrp       x2, #0x1000
//   0x3e34: 912bd842  add        x2, x2, #0xaf6
//   0x3e38: f9003a80  str        x0, [x20, #0x70]
//   0x3e3c: 528000c0  mov        w0, #6
//   0x3e40: 94001654  bl         #0x9790
//   0x3e44: 94001677  bl         #0x9820
//   0x3e48: 37f802e0  tbnz       w0, #0x1f, #0x3ea4
//   0x3e4c: 2a0003f3  mov        w19, w0
//   0x3e50: 34000da0  cbz        w0, #0x4004
//   0x3e54: b900b3ff  str        wzr, [sp, #0xb0]
//   0x3e58: 52800022  mov        w2, #1
//   0x3e5c: 9102c3e1  add        x1, sp, #0xb0
//   0x3e60: 2a1303e0  mov        w0, w19
//   0x3e64: 72a80002  movk       w2, #0x4000, lsl #16
//   0x3e68: 94001672  bl         #0x9830
//   0x3e6c: 3100041f  cmn        w0, #1
//   0x3e70: 540001e1  b.ne       #0x3eac
//   0x3e74: 94001673  bl         #0x9840
//   0x3e78: b9400003  ldr        w3, [x0]
//   0x3e7c: 7100107f  cmp        w3, #4
//   0x3e80: 54fffec0  b.eq       #0x3e58
//   0x3e84: d503201f  nop        
//   0x3e88: 10fedba1  adr        x1, #0x19fc
//   0x3e8c: d0ffffe2  adrp       x2, #0x1000
//   0x3e90: 9139a842  add        x2, x2, #0xe6a
//   0x3e94: 528000c0  mov        w0, #6
//   0x3e98: 9400163e  bl         #0x9790
//   0x3e9c: 12800113  mov        w19, #-9
//   0x3ea0: 14000054  b          #0x3ff0
//   0x3ea4: 128000d3  mov        w19, #-7
//   0x3ea8: 14000052  b          #0x3ff0
//   0x3eac: b940b3e3  ldr        w3, [sp, #0xb0]
//   0x3eb0: 529fefe8  mov        w8, #0xff7f
//   0x3eb4: 6a08007f  tst        w3, w8
//   0x3eb8: 540003a0  b.eq       #0x3f2c
//   0x3ebc: 12001868  and        w8, w3, #0x7f
//   0x3ec0: 34000708  cbz        w8, #0x3fa0
//   0x3ec4: d503201f  nop        
//   0x3ec8: 10fed9a1  adr        x1, #0x19fc
//   0x3ecc: 11000469  add        w9, w3, #1
//   0x3ed0: 721f153f  tst        w9, #0x7e
//   0x3ed4: 54000840  b.eq       #0x3fdc
//   0x3ed8: f0ffffe2  adrp       x2, #0x2000
//   0x3edc: 9103f442  add        x2, x2, #0xfd
//   0x3ee0: 528000c0  mov        w0, #6
//   0x3ee4: 2a0803e3  mov        w3, w8
//   0x3ee8: 14000040  b          #0x3fe8
//   0x3eec: d503201f  nop        
//   0x3ef0: 10fed861  adr        x1, #0x19fc
//   0x3ef4: d0ffffe2  adrp       x2, #0x1000
//   0x3ef8: 912d2842  add        x2, x2, #0xb4a
//   0x3efc: 528000c0  mov        w0, #6
//   0x3f00: 94001624  bl         #0x9790
//   0x3f04: f0000068  adrp       x8, #0x12000
//   0x3f08: f900451f  str        xzr, [x8, #0x88]
//   0x3f0c: d503201f  nop        
//   0x3f10: 10fed761  adr        x1, #0x19fc
//   0x3f14: d0ffffe2  adrp       x2, #0x1000
//   0x3f18: 91280442  add        x2, x2, #0xa01
//   0x3f1c: 528000c0  mov        w0, #6
//   0x3f20: 9400161c  bl         #0x9790
//   0x3f24: 12800073  mov        w19, #-4
//   0x3f28: 17ffff61  b          #0x3cac
//   0x3f2c: f9403ee8  ldr        x8, [x23, #0x78]
//   0x3f30: b4000468  cbz        x8, #0x3fbc
//   0x3f34: f9403a89  ldr        x9, [x20, #0x70]
//   0x3f38: b4000429  cbz        x9, #0x3fbc
//   0x3f3c: f9404b4a  ldr        x10, [x26, #0x90]
//   0x3f40: f100215f  cmp        x10, #8
//   0x3f44: 54000103  b.lo       #0x3f64
//   0x3f48: d343fd4a  lsr        x10, x10, #3
//   0x3f4c: f940010b  ldr        x11, [x8]
//   0x3f50: b40000ab  cbz        x11, #0x3f64
//   0x3f54: 91002108  add        x8, x8, #8
//   0x3f58: f100054a  subs       x10, x10, #1
//   0x3f5c: f800852b  str        x11, [x9], #8
//   0x3f60: 54ffff61  b.ne       #0x3f4c
//   0x3f64: b9406ac8  ldr        w8, [x22, #0x68]
//   0x3f68: 51005509  sub        w9, w8, #0x15
//   0x3f6c: 7100711f  cmp        w8, #0x1c
//   0x3f70: 7a42d920  ccmp       w9, #2, #0, le
//   0x3f74: 540000a8  b.hi       #0x3f88
//   0x3f78: f0000068  adrp       x8, #0x12000
//   0x3f7c: f9403a89  ldr        x9, [x20, #0x70]
//   0x3f80: f9404508  ldr        x8, [x8, #0x88]
//   0x3f84: f9000109  str        x9, [x8]
//   0x3f88: 52800028  mov        w8, #1
//   0x3f8c: 2a1f03f3  mov        w19, wzr
//   0x3f90: 39020328  strb       w8, [x25, #0x80]
//   0x3f94: f9404ea0  ldr        x0, [x21, #0x98]
//   0x3f98: b5fff020  cbnz       x0, #0x3d9c
//   0x3f9c: 17ffff82  b          #0x3da4
//   0x3fa0: 53083c63  ubfx       w3, w3, #8, #8
//   0x3fa4: d503201f  nop        
//   0x3fa8: 10fed2a1  adr        x1, #0x19fc
//   0x3fac: f0ffffe2  adrp       x2, #0x2000
//   0x3fb0: 91024c42  add        x2, x2, #0x93
//   0x3fb4: 528000c0  mov        w0, #6
//   0x3fb8: 1400000c  b          #0x3fe8
//   0x3fbc: d503201f  nop        
//   0x3fc0: 10fed1e1  adr        x1, #0x19fc
//   0x3fc4: d0ffffe2  adrp       x2, #0x1000
//   0x3fc8: 913e1442  add        x2, x2, #0xf85
//   0x3fcc: 528000c0  mov        w0, #6
//   0x3fd0: 12800023  mov        w3, #-2
//   0x3fd4: 12800033  mov        w19, #-2
//   0x3fd8: 17ffff41  b          #0x3cdc
//   0x3fdc: d0ffffe2  adrp       x2, #0x1000
//   0x3fe0: 912fc042  add        x2, x2, #0xbf0
//   0x3fe4: 52800080  mov        w0, #4
//   0x3fe8: 940015ea  bl         #0x9790
//   0x3fec: 12800133  mov        w19, #-0xa
//   0x3ff0: d503201f  nop        
//   0x3ff4: 10fed041  adr        x1, #0x19fc
//   0x3ff8: f0ffffe2  adrp       x2, #0x2000
//   0x3ffc: 91071842  add        x2, x2, #0x1c6
//   0x4000: 17ffff35  b          #0x3cd4
//   0x4004: 940000a3  bl         #0x4290
//   0x4008: 94001612  bl         #0x9850
//   0x400c: 94001615  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[06] HeapTrackerControlCmd_4010 (0x4010..0x4060, 80 bytes, 20 instructions)
// Summary / Tóm tắt: State machine command entry (cmd 0..6 -> 0x46a0) (@ 0x4010..0x4060)
// ----------------------------------------------------------------------------
//   0x4010: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x4014: 910003fd  mov        x29, sp
//   0x4018: d0000068  adrp       x8, #0x12000
//   0x401c: 2a0003e3  mov        w3, w0
//   0x4020: 39420108  ldrb       w8, [x8, #0x80]
//   0x4024: 360000c8  tbz        w8, #0, #0x403c
//   0x4028: 7100187f  cmp        w3, #6
//   0x402c: 54000148  b.hi       #0x4054
//   0x4030: 2a0303e0  mov        w0, w3
//   0x4034: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x4038: 1400019a  b          #0x46a0
//   0x403c: d503201f  nop        
//   0x4040: 10fecde1  adr        x1, #0x19fc
//   0x4044: d0ffffe2  adrp       x2, #0x2000
//   0x4048: 9105a442  add        x2, x2, #0x169
//   0x404c: 528000c0  mov        w0, #6
//   0x4050: 940015d0  bl         #0x9790
//   0x4054: 12800000  mov        w0, #-1
//   0x4058: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x405c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[07] HeapTrackerGetMallinfoUordblks_4060 (0x4060..0x40ac, 76 bytes, 19 instructions)
// Summary / Tóm tắt: Calls mallinfo() and returns uordblks ([sp, #0x40]) (@ 0x4060..0x40ac)
// ----------------------------------------------------------------------------
//   0x4060: d10203ff  sub        sp, sp, #0x80
//   0x4064: a9067bfd  stp        x29, x30, [sp, #0x60]
//   0x4068: f9003bf3  str        x19, [sp, #0x70]
//   0x406c: 910183fd  add        x29, sp, #0x60
//   0x4070: d53bd053  mrs        x19, tpidr_el0
//   0x4074: f9401668  ldr        x8, [x19, #0x28]
//   0x4078: f81f83a8  stur       x8, [x29, #-8]
//   0x407c: 910023e8  add        x8, sp, #8
//   0x4080: 940015fc  bl         #0x9870
//   0x4084: f94023e0  ldr        x0, [sp, #0x40]
//   0x4088: f9401668  ldr        x8, [x19, #0x28]
//   0x408c: f85f83a9  ldur       x9, [x29, #-8]
//   0x4090: eb09011f  cmp        x8, x9
//   0x4094: 540000a1  b.ne       #0x40a8
//   0x4098: a9467bfd  ldp        x29, x30, [sp, #0x60]
//   0x409c: f9403bf3  ldr        x19, [sp, #0x70]
//   0x40a0: 910203ff  add        sp, sp, #0x80
//   0x40a4: d65f03c0  ret        
//   0x40a8: 940015ee  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[08] HeapTrackerCheckHeapSizeMb_40ac (0x40ac..0x40fc, 80 bytes, 20 instructions)
// Summary / Tóm tắt: Checks heap size against 0x29736e9 (~41.4 MB) and logs in MB (>>20) (@ 0x40ac..0x40fc)
// ----------------------------------------------------------------------------
//   0x40ac: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x40b0: f9000bf3  str        x19, [sp, #0x10]
//   0x40b4: 910003fd  mov        x29, sp
//   0x40b8: 940010cf  bl         #0x83f4
//   0x40bc: aa0003f3  mov        x19, x0
//   0x40c0: 5286dd28  mov        w8, #0x36e9
//   0x40c4: 72a052e8  movk       w8, #0x297, lsl #16
//   0x40c8: eb08001f  cmp        x0, x8
//   0x40cc: 54000103  b.lo       #0x40ec
//   0x40d0: d354fe63  lsr        x3, x19, #0x14
//   0x40d4: d503201f  nop        
//   0x40d8: 10fec921  adr        x1, #0x19fc
//   0x40dc: d0ffffe2  adrp       x2, #0x2000
//   0x40e0: 9108bc42  add        x2, x2, #0x22f
//   0x40e4: 528000c0  mov        w0, #6
//   0x40e8: 940015aa  bl         #0x9790
//   0x40ec: aa1303e0  mov        x0, x19
//   0x40f0: f9400bf3  ldr        x19, [sp, #0x10]
//   0x40f4: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x40f8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[09] HeapTrackerSetConfigParamA0_40fc (0x40fc..0x4114, 24 bytes, 6 instructions)
// Summary / Tóm tắt: Sets config parameter at manager+0xa0 (@ 0x40fc..0x4114)
// ----------------------------------------------------------------------------
//   0x40fc: d503201f  nop        
//   0x4100: 1006fd08  adr        x8, #0x120a0
//   0x4104: f9400108  ldr        x8, [x8]
//   0x4108: b4000048  cbz        x8, #0x4110
//   0x410c: f9005100  str        x0, [x8, #0xa0]
//   0x4110: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[10] HeapTrackerSetConfigParamA8_4114 (0x4114..0x412c, 24 bytes, 6 instructions)
// Summary / Tóm tắt: Sets config parameter at manager+0xa8 (@ 0x4114..0x412c)
// ----------------------------------------------------------------------------
//   0x4114: d503201f  nop        
//   0x4118: 1006fc48  adr        x8, #0x120a0
//   0x411c: f9400108  ldr        x8, [x8]
//   0x4120: b4000048  cbz        x8, #0x4128
//   0x4124: f9005500  str        x0, [x8, #0xa8]
//   0x4128: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[11] HeapTrackerSetConfigParamB0_412c (0x412c..0x4148, 28 bytes, 7 instructions)
// Summary / Tóm tắt: Sets config parameter at manager+0xb0 (@ 0x412c..0x4148)
// ----------------------------------------------------------------------------
//   0x412c: d503201f  nop        
//   0x4130: 1006fb88  adr        x8, #0x120a0
//   0x4134: f9400108  ldr        x8, [x8]
//   0x4138: b4000068  cbz        x8, #0x4144
//   0x413c: 93407c09  sxtw       x9, w0
//   0x4140: f9005909  str        x9, [x8, #0xb0]
//   0x4144: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[12] HeapTrackerTriggerWaitOrCheck_4148 (0x4148..0x4168, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Validates non-negative arg and tails into 0x45f4 (@ 0x4148..0x4168)
// ----------------------------------------------------------------------------
//   0x4148: 37f800c0  tbnz       w0, #0x1f, #0x4160
//   0x414c: d503201f  nop        
//   0x4150: 1006fa88  adr        x8, #0x120a0
//   0x4154: f9400108  ldr        x8, [x8]
//   0x4158: b4000048  cbz        x8, #0x4160
//   0x415c: 14000126  b          #0x45f4
//   0x4160: 128001c0  mov        w0, #-0xf
//   0x4164: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[13] HeapTrackerFde_4168 (0x4168..0x4208, 160 bytes, 40 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x4168..0x4208
// ----------------------------------------------------------------------------
//   0x4168: d10443ff  sub        sp, sp, #0x110
//   0x416c: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x4170: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x4174: 9103c3fd  add        x29, sp, #0xf0
//   0x4178: ad0007e0  stp        q0, q1, [sp]
//   0x417c: d101c3a9  sub        x9, x29, #0x70
//   0x4180: a9399ba5  stp        x5, x6, [x29, #-0x68]
//   0x4184: 928003eb  mov        x11, #-0x20
//   0x4188: f81903a4  stur       x4, [x29, #-0x70]
//   0x418c: 910003ec  mov        x12, sp
//   0x4190: f81a83a7  stur       x7, [x29, #-0x58]
//   0x4194: 91008129  add        x9, x9, #0x20
//   0x4198: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x419c: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x41a0: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x41a4: 9102018c  add        x12, x12, #0x80
//   0x41a8: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x41ac: d53bd053  mrs        x19, tpidr_el0
//   0x41b0: f9401668  ldr        x8, [x19, #0x28]
//   0x41b4: d100a3aa  sub        x10, x29, #0x28
//   0x41b8: b0ffffe2  adrp       x2, #0x1000
//   0x41bc: 91337c42  add        x2, x2, #0xcdf
//   0x41c0: d10143a3  sub        x3, x29, #0x50
//   0x41c4: 52808001  mov        w1, #0x400
//   0x41c8: f81f83a8  stur       x8, [x29, #-8]
//   0x41cc: 910083a8  add        x8, x29, #0x20
//   0x41d0: a93eafac  stp        x12, x11, [x29, #-0x18]
//   0x41d4: a93da7a8  stp        x8, x9, [x29, #-0x28]
//   0x41d8: ad400540  ldp        q0, q1, [x10]
//   0x41dc: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x41e0: 940015a8  bl         #0x9880
//   0x41e4: f9401668  ldr        x8, [x19, #0x28]
//   0x41e8: f85f83a9  ldur       x9, [x29, #-8]
//   0x41ec: eb09011f  cmp        x8, x9
//   0x41f0: 540000a1  b.ne       #0x4204
//   0x41f4: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x41f8: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x41fc: 910443ff  add        sp, sp, #0x110
//   0x4200: d65f03c0  ret        
//   0x4204: 94001597  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[14] HeapTrackerResolveLibcDispatch_4208 (0x4208..0x4290, 136 bytes, 34 instructions)
// Summary / Tóm tắt: Resolves __libc_globals and _ZL30__libc_malloc_default_dispatch (@ 0x4208..0x4290)
// ----------------------------------------------------------------------------
//   0x4208: d0000069  adrp       x9, #0x12000
//   0x420c: d0000068  adrp       x8, #0x12000
//   0x4210: f9403d29  ldr        x9, [x9, #0x78]
//   0x4214: f940390a  ldr        x10, [x8, #0x70]
//   0x4218: f100013f  cmp        x9, #0
//   0x421c: fa401944  ccmp       x10, #0, #4, ne
//   0x4220: 54000061  b.ne       #0x422c
//   0x4224: 12800020  mov        w0, #-2
//   0x4228: d65f03c0  ret        
//   0x422c: d000006b  adrp       x11, #0x12000
//   0x4230: f940496b  ldr        x11, [x11, #0x90]
//   0x4234: f100217f  cmp        x11, #8
//   0x4238: 54000103  b.lo       #0x4258
//   0x423c: d343fd6b  lsr        x11, x11, #3
//   0x4240: f940012c  ldr        x12, [x9]
//   0x4244: b40000ac  cbz        x12, #0x4258
//   0x4248: 91002129  add        x9, x9, #8
//   0x424c: f100056b  subs       x11, x11, #1
//   0x4250: f800854c  str        x12, [x10], #8
//   0x4254: 54ffff61  b.ne       #0x4240
//   0x4258: d0000069  adrp       x9, #0x12000
//   0x425c: b9406929  ldr        w9, [x9, #0x68]
//   0x4260: 5100552a  sub        w10, w9, #0x15
//   0x4264: 71000d5f  cmp        w10, #3
//   0x4268: 7a5d2920  ccmp       w9, #0x1d, #0, hs
//   0x426c: 540000eb  b.lt       #0x4288
//   0x4270: d0000069  adrp       x9, #0x12000
//   0x4274: f9403908  ldr        x8, [x8, #0x70]
//   0x4278: 2a1f03e0  mov        w0, wzr
//   0x427c: f9404529  ldr        x9, [x9, #0x88]
//   0x4280: f9000128  str        x8, [x9]
//   0x4284: d65f03c0  ret        
//   0x4288: 2a1f03e0  mov        w0, wzr
//   0x428c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[15] HeapTrackerInstallMallocDispatch_4290 (0x4290..0x4538, 680 bytes, 170 instructions)
// Summary / Tóm tắt: Installs HeapTracker hooks into Bionic MallocDispatch (@ 0x4290..0x4538)
// ----------------------------------------------------------------------------
//   0x4290: d100c3ff  sub        sp, sp, #0x30
//   0x4294: a9027bfd  stp        x29, x30, [sp, #0x20]
//   0x4298: 910083fd  add        x29, sp, #0x20
//   0x429c: d53bd048  mrs        x8, tpidr_el0
//   0x42a0: f9401508  ldr        x8, [x8, #0x28]
//   0x42a4: f81f83a8  stur       x8, [x29, #-8]
//   0x42a8: 97ffffd8  bl         #0x4208
//   0x42ac: 36f80080  tbz        w0, #0x1f, #0x42bc
//   0x42b0: 52807d08  mov        w8, #0x3e8
//   0x42b4: b9000fe8  str        w8, [sp, #0xc]
//   0x42b8: 14000096  b          #0x4510
//   0x42bc: d503201f  nop        
//   0x42c0: 1006ed88  adr        x8, #0x12070
//   0x42c4: f9400108  ldr        x8, [x8]
//   0x42c8: d503201f  nop        
//   0x42cc: 10001369  adr        x9, #0x4538
//   0x42d0: f9000d09  str        x9, [x8, #0x18]
//   0x42d4: d2800080  mov        x0, #4
//   0x42d8: 9400156e  bl         #0x9890
//   0x42dc: d503201f  nop        
//   0x42e0: 1006ec88  adr        x8, #0x12070
//   0x42e4: f9400108  ldr        x8, [x8]
//   0x42e8: f9400d08  ldr        x8, [x8, #0x18]
//   0x42ec: d503201f  nop        
//   0x42f0: 1006ec49  adr        x9, #0x12078
//   0x42f4: f9400129  ldr        x9, [x9]
//   0x42f8: f9400d29  ldr        x9, [x9, #0x18]
//   0x42fc: eb09011f  cmp        x8, x9
//   0x4300: 54000080  b.eq       #0x4310
//   0x4304: 12800008  mov        w8, #-1
//   0x4308: b9000fe8  str        w8, [sp, #0xc]
//   0x430c: 14000081  b          #0x4510
//   0x4310: d503201f  nop        
//   0x4314: 1006eae8  adr        x8, #0x12070
//   0x4318: f9400108  ldr        x8, [x8]
//   0x431c: d503201f  nop        
//   0x4320: 100011c9  adr        x9, #0x4558
//   0x4324: f9000509  str        x9, [x8, #8]
//   0x4328: aa1f03e0  mov        x0, xzr
//   0x432c: 9400155d  bl         #0x98a0
//   0x4330: d503201f  nop        
//   0x4334: 1006e9e8  adr        x8, #0x12070
//   0x4338: f9400108  ldr        x8, [x8]
//   0x433c: f9400508  ldr        x8, [x8, #8]
//   0x4340: d503201f  nop        
//   0x4344: 1006e9a9  adr        x9, #0x12078
//   0x4348: f9400129  ldr        x9, [x9]
//   0x434c: f9400529  ldr        x9, [x9, #8]
//   0x4350: eb09011f  cmp        x8, x9
//   0x4354: 54000080  b.eq       #0x4364
//   0x4358: 12800028  mov        w8, #-2
//   0x435c: b9000fe8  str        w8, [sp, #0xc]
//   0x4360: 1400006c  b          #0x4510
//   0x4364: d503201f  nop        
//   0x4368: 1006e848  adr        x8, #0x12070
//   0x436c: f9400108  ldr        x8, [x8]
//   0x4370: d503201f  nop        
//   0x4374: 10001009  adr        x9, #0x4574
//   0x4378: f9000109  str        x9, [x8]
//   0x437c: d2800020  mov        x0, #1
//   0x4380: d2800081  mov        x1, #4
//   0x4384: 940014e3  bl         #0x9710
//   0x4388: d503201f  nop        
//   0x438c: 1006e728  adr        x8, #0x12070
//   0x4390: f9400108  ldr        x8, [x8]
//   0x4394: f9400108  ldr        x8, [x8]
//   0x4398: d503201f  nop        
//   0x439c: 1006e6e9  adr        x9, #0x12078
//   0x43a0: f9400129  ldr        x9, [x9]
//   0x43a4: f9400129  ldr        x9, [x9]
//   0x43a8: eb09011f  cmp        x8, x9
//   0x43ac: 54000080  b.eq       #0x43bc
//   0x43b0: 12800048  mov        w8, #-3
//   0x43b4: b9000fe8  str        w8, [sp, #0xc]
//   0x43b8: 14000056  b          #0x4510
//   0x43bc: d503201f  nop        
//   0x43c0: 1006e588  adr        x8, #0x12070
//   0x43c4: f9400108  ldr        x8, [x8]
//   0x43c8: d503201f  nop        
//   0x43cc: 10000e49  adr        x9, #0x4594
//   0x43d0: f9001d09  str        x9, [x8, #0x38]
//   0x43d4: aa1f03e0  mov        x0, xzr
//   0x43d8: d2800101  mov        x1, #8
//   0x43dc: 94001535  bl         #0x98b0
//   0x43e0: d503201f  nop        
//   0x43e4: 1006e468  adr        x8, #0x12070
//   0x43e8: f9400108  ldr        x8, [x8]
//   0x43ec: f9401d08  ldr        x8, [x8, #0x38]
//   0x43f0: d503201f  nop        
//   0x43f4: 1006e429  adr        x9, #0x12078
//   0x43f8: f9400129  ldr        x9, [x9]
//   0x43fc: f9401d29  ldr        x9, [x9, #0x38]
//   0x4400: eb09011f  cmp        x8, x9
//   0x4404: 54000080  b.eq       #0x4414
//   0x4408: 12800068  mov        w8, #-4
//   0x440c: b9000fe8  str        w8, [sp, #0xc]
//   0x4410: 14000040  b          #0x4510
//   0x4414: d503201f  nop        
//   0x4418: 1006e2c8  adr        x8, #0x12070
//   0x441c: f9400108  ldr        x8, [x8]
//   0x4420: d503201f  nop        
//   0x4424: 10000c89  adr        x9, #0x45b4
//   0x4428: f9001509  str        x9, [x8, #0x28]
//   0x442c: d2800080  mov        x0, #4
//   0x4430: d2800101  mov        x1, #8
//   0x4434: 94001523  bl         #0x98c0
//   0x4438: d503201f  nop        
//   0x443c: 1006e1a8  adr        x8, #0x12070
//   0x4440: f9400108  ldr        x8, [x8]
//   0x4444: f9401508  ldr        x8, [x8, #0x28]
//   0x4448: d503201f  nop        
//   0x444c: 1006e169  adr        x9, #0x12078
//   0x4450: f9400129  ldr        x9, [x9]
//   0x4454: f9401529  ldr        x9, [x9, #0x28]
//   0x4458: eb09011f  cmp        x8, x9
//   0x445c: 54000080  b.eq       #0x446c
//   0x4460: 12800088  mov        w8, #-5
//   0x4464: b9000fe8  str        w8, [sp, #0xc]
//   0x4468: 1400002a  b          #0x4510
//   0x446c: b0000048  adrp       x8, #0xd000
//   0x4470: f946c108  ldr        x8, [x8, #0xd80]
//   0x4474: b40004c8  cbz        x8, #0x450c
//   0x4478: 14000001  b          #0x447c
//   0x447c: d503201f  nop        
//   0x4480: 1006df88  adr        x8, #0x12070
//   0x4484: f9400108  ldr        x8, [x8]
//   0x4488: d503201f  nop        
//   0x448c: 10000a49  adr        x9, #0x45d4
//   0x4490: f9001909  str        x9, [x8, #0x30]
//   0x4494: 910043e0  add        x0, sp, #0x10
//   0x4498: d2800081  mov        x1, #4
//   0x449c: d2800102  mov        x2, #8
//   0x44a0: 9400150c  bl         #0x98d0
//   0x44a4: b9000be0  str        w0, [sp, #8]
//   0x44a8: b9400be8  ldr        w8, [sp, #8]
//   0x44ac: 35000068  cbnz       w8, #0x44b8
//   0x44b0: f9400be0  ldr        x0, [sp, #0x10]
//   0x44b4: 940014fb  bl         #0x98a0
//   0x44b8: d503201f  nop        
//   0x44bc: 1006dda8  adr        x8, #0x12070
//   0x44c0: f9400108  ldr        x8, [x8]
//   0x44c4: f9401908  ldr        x8, [x8, #0x30]
//   0x44c8: d503201f  nop        
//   0x44cc: 1006dd69  adr        x9, #0x12078
//   0x44d0: f9400129  ldr        x9, [x9]
//   0x44d4: f9401929  ldr        x9, [x9, #0x30]
//   0x44d8: eb09011f  cmp        x8, x9
//   0x44dc: 540000c0  b.eq       #0x44f4
//   0x44e0: 128000a8  mov        w8, #-6
//   0x44e4: b9000fe8  str        w8, [sp, #0xc]
//   0x44e8: 52800028  mov        w8, #1
//   0x44ec: b90007e8  str        w8, [sp, #4]
//   0x44f0: 14000002  b          #0x44f8
//   0x44f4: b90007ff  str        wzr, [sp, #4]
//   0x44f8: b94007e8  ldr        w8, [sp, #4]
//   0x44fc: 34000068  cbz        w8, #0x4508
//   0x4500: 14000001  b          #0x4504
//   0x4504: 14000003  b          #0x4510
//   0x4508: 14000001  b          #0x450c
//   0x450c: b9000fff  str        wzr, [sp, #0xc]
//   0x4510: b9400fe0  ldr        w0, [sp, #0xc]
//   0x4514: d53bd048  mrs        x8, tpidr_el0
//   0x4518: f9401508  ldr        x8, [x8, #0x28]
//   0x451c: f85f83a9  ldur       x9, [x29, #-8]
//   0x4520: eb09011f  cmp        x8, x9
//   0x4524: 54000081  b.ne       #0x4534
//   0x4528: a9427bfd  ldp        x29, x30, [sp, #0x20]
//   0x452c: 9100c3ff  add        sp, sp, #0x30
//   0x4530: d65f03c0  ret        
//   0x4534: 940014cb  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[16] HeapTrackerRestoreReallocSlot_4538 (0x4538..0x4558, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->realloc (+0x18) from default dispatch (@ 0x4538..0x4558)
// ----------------------------------------------------------------------------
//   0x4538: d0000068  adrp       x8, #0x12000
//   0x453c: d0000069  adrp       x9, #0x12000
//   0x4540: aa1f03e0  mov        x0, xzr
//   0x4544: f9403d08  ldr        x8, [x8, #0x78]
//   0x4548: f9403929  ldr        x9, [x9, #0x70]
//   0x454c: f9400d08  ldr        x8, [x8, #0x18]
//   0x4550: f9000d28  str        x8, [x9, #0x18]
//   0x4554: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[17] HeapTrackerRestoreFreeSlot_4558 (0x4558..0x4574, 28 bytes, 7 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->free (+0x08) from default dispatch (@ 0x4558..0x4574)
// ----------------------------------------------------------------------------
//   0x4558: d0000068  adrp       x8, #0x12000
//   0x455c: d0000069  adrp       x9, #0x12000
//   0x4560: f9403d08  ldr        x8, [x8, #0x78]
//   0x4564: f9403929  ldr        x9, [x9, #0x70]
//   0x4568: f9400508  ldr        x8, [x8, #8]
//   0x456c: f9000528  str        x8, [x9, #8]
//   0x4570: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[18] HeapTrackerRestoreMallocSlot_4574 (0x4574..0x4594, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->malloc (+0x00) from default dispatch (@ 0x4574..0x4594)
// ----------------------------------------------------------------------------
//   0x4574: d0000068  adrp       x8, #0x12000
//   0x4578: d0000069  adrp       x9, #0x12000
//   0x457c: aa1f03e0  mov        x0, xzr
//   0x4580: f9403d08  ldr        x8, [x8, #0x78]
//   0x4584: f9403929  ldr        x9, [x9, #0x70]
//   0x4588: f9400108  ldr        x8, [x8]
//   0x458c: f9000128  str        x8, [x9]
//   0x4590: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[19] HeapTrackerRestoreUsableSizeSlot_4594 (0x4594..0x45b4, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->malloc_usable_size (+0x38) from default dispatch (@ 0x4594..0x45b4)
// ----------------------------------------------------------------------------
//   0x4594: d0000068  adrp       x8, #0x12000
//   0x4598: d0000069  adrp       x9, #0x12000
//   0x459c: aa1f03e0  mov        x0, xzr
//   0x45a0: f9403d08  ldr        x8, [x8, #0x78]
//   0x45a4: f9403929  ldr        x9, [x9, #0x70]
//   0x45a8: f9401d08  ldr        x8, [x8, #0x38]
//   0x45ac: f9001d28  str        x8, [x9, #0x38]
//   0x45b0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[20] HeapTrackerRestoreMemalignSlot_45b4 (0x45b4..0x45d4, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->memalign (+0x28) from default dispatch (@ 0x45b4..0x45d4)
// ----------------------------------------------------------------------------
//   0x45b4: d0000068  adrp       x8, #0x12000
//   0x45b8: d0000069  adrp       x9, #0x12000
//   0x45bc: aa1f03e0  mov        x0, xzr
//   0x45c0: f9403d08  ldr        x8, [x8, #0x78]
//   0x45c4: f9403929  ldr        x9, [x9, #0x70]
//   0x45c8: f9401508  ldr        x8, [x8, #0x28]
//   0x45cc: f9001528  str        x8, [x9, #0x28]
//   0x45d0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[21] HeapTrackerRestorePosixMemalignSlot_45d4 (0x45d4..0x45f4, 32 bytes, 8 instructions)
// Summary / Tóm tắt: Restores MallocDispatch->posix_memalign (+0x30) from default dispatch (@ 0x45d4..0x45f4)
// ----------------------------------------------------------------------------
//   0x45d4: d0000068  adrp       x8, #0x12000
//   0x45d8: d0000069  adrp       x9, #0x12000
//   0x45dc: 52800020  mov        w0, #1
//   0x45e0: f9403d08  ldr        x8, [x8, #0x78]
//   0x45e4: f9403929  ldr        x9, [x9, #0x70]
//   0x45e8: f9401908  ldr        x8, [x8, #0x30]
//   0x45ec: f9001928  str        x8, [x9, #0x30]
//   0x45f0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[22] HeapTrackerCheckThreshold50MB_45f4 (0x45f4..0x46a0, 172 bytes, 43 instructions)
// Summary / Tóm tắt: Checks if heap size >= 0x3200001 (~50 MB) (@ 0x45f4..0x46a0)
// ----------------------------------------------------------------------------
//   0x45f4: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x45f8: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x45fc: 910003fd  mov        x29, sp
//   0x4600: 2a0003f3  mov        w19, w0
//   0x4604: 97fffeaa  bl         #0x40ac
//   0x4608: 52800028  mov        w8, #1
//   0x460c: 72a06408  movk       w8, #0x320, lsl #16
//   0x4610: eb08001f  cmp        x0, x8
//   0x4614: 54000062  b.hs       #0x4620
//   0x4618: 2a1f03e0  mov        w0, wzr
//   0x461c: 1400001e  b          #0x4694
//   0x4620: d0000074  adrp       x20, #0x12000
//   0x4624: 2a1f03e0  mov        w0, wzr
//   0x4628: 52800021  mov        w1, #1
//   0x462c: f9405288  ldr        x8, [x20, #0xa0]
//   0x4630: 9107b102  add        x2, x8, #0x1ec
//   0x4634: 940012bf  bl         #0x9130
//   0x4638: 7100001f  cmp        w0, #0
//   0x463c: 540002a1  b.ne       #0x4690
//   0x4640: f9405288  ldr        x8, [x20, #0xa0]
//   0x4644: 91072100  add        x0, x8, #0x1c8
//   0x4648: b901e513  str        w19, [x8, #0x1e4]
//   0x464c: 940014a5  bl         #0x98e0
//   0x4650: 97fffe84  bl         #0x4060
//   0x4654: f9405288  ldr        x8, [x20, #0xa0]
//   0x4658: f900c500  str        x0, [x8, #0x188]
//   0x465c: 9400089f  bl         #0x68d8
//   0x4660: 52804842  mov        w2, #0x242
//   0x4664: d503201f  nop        
//   0x4668: 30feb3e1  adr        x1, #0x1ce5
//   0x466c: 2a1303e0  mov        w0, w19
//   0x4670: 72a00102  movk       w2, #8, lsl #16
//   0x4674: 52803003  mov        w3, #0x180
//   0x4678: 9400149e  bl         #0x98f0
//   0x467c: 2a0003e1  mov        w1, w0
//   0x4680: 2a1f03e0  mov        w0, wzr
//   0x4684: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x4688: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x468c: 14000165  b          #0x4c20
//   0x4690: 128001e0  mov        w0, #-0x10
//   0x4694: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x4698: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x469c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[23] HeapTrackerExecuteCommand_46a0 (0x46a0..0x495c, 700 bytes, 175 instructions)
// Summary / Tóm tắt: Executes LEAK INIT / LEAK START / LEAK WAIT / LEAK DUMP / LEAK EXIT state machine (@ 0x46a0..0x495c)
// ----------------------------------------------------------------------------
//   0x46a0: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x46a4: f9000bf5  str        x21, [sp, #0x10]
//   0x46a8: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x46ac: 910003fd  mov        x29, sp
//   0x46b0: d0000074  adrp       x20, #0x12000
//   0x46b4: f9405288  ldr        x8, [x20, #0xa0]
//   0x46b8: 34000080  cbz        w0, #0x46c8
//   0x46bc: b5000068  cbnz       x8, #0x46c8
//   0x46c0: 12800240  mov        w0, #-0x13
//   0x46c4: 14000080  b          #0x48c4
//   0x46c8: b4000128  cbz        x8, #0x46ec
//   0x46cc: 51001809  sub        w9, w0, #6
//   0x46d0: 31000d3f  cmn        w9, #3
//   0x46d4: 540000c8  b.hi       #0x46ec
//   0x46d8: b941ed09  ldr        w9, [x8, #0x1ec]
//   0x46dc: 7100053f  cmp        w9, #1
//   0x46e0: 54000061  b.ne       #0x46ec
//   0x46e4: 12800220  mov        w0, #-0x12
//   0x46e8: 14000077  b          #0x48c4
//   0x46ec: 7100141f  cmp        w0, #5
//   0x46f0: 54000228  b.hi       #0x4734
//   0x46f4: 2a0003e9  mov        w9, w0
//   0x46f8: d503201f  nop        
//   0x46fc: 10fefeaa  adr        x10, #0x26d0
//   0x4700: 1000008b  adr        x11, #0x4710
//   0x4704: 3869694c  ldrb       w12, [x10, x9]
//   0x4708: 8b0c096b  add        x11, x11, x12, lsl #2
//   0x470c: d61f0160  br         x11
//   0x4710: b50000e8  cbnz       x8, #0x472c
//   0x4714: 52804400  mov        w0, #0x220
//   0x4718: 9400145e  bl         #0x9890
//   0x471c: d0000075  adrp       x21, #0x12000
//   0x4720: f9005280  str        x0, [x20, #0xa0]
//   0x4724: 3942c2a8  ldrb       w8, [x21, #0xb0]
//   0x4728: 36000d68  tbz        w8, #0, #0x48d4
//   0x472c: 128001a0  mov        w0, #-0xe
//   0x4730: 14000065  b          #0x48c4
//   0x4734: b0ffffe1  adrp       x1, #0x1000
//   0x4738: 9127f021  add        x1, x1, #0x9fc
//   0x473c: d0ffffe2  adrp       x2, #0x2000
//   0x4740: 910aa442  add        x2, x2, #0x2a9
//   0x4744: 528000a0  mov        w0, #5
//   0x4748: 94001412  bl         #0x9790
//   0x474c: 12800260  mov        w0, #-0x14
//   0x4750: 1400005d  b          #0x48c4
//   0x4754: 9106e100  add        x0, x8, #0x1b8
//   0x4758: 94001462  bl         #0x98e0
//   0x475c: 97fffe41  bl         #0x4060
//   0x4760: f9405288  ldr        x8, [x20, #0xa0]
//   0x4764: f900c100  str        x0, [x8, #0x180]
//   0x4768: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x476c: f9400bf5  ldr        x21, [sp, #0x10]
//   0x4770: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x4774: 1400087c  b          #0x6964
//   0x4778: 91070100  add        x0, x8, #0x1c0
//   0x477c: 94001459  bl         #0x98e0
//   0x4780: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x4784: f9400bf5  ldr        x21, [sp, #0x10]
//   0x4788: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x478c: 14000849  b          #0x68b0
//   0x4790: 9107b102  add        x2, x8, #0x1ec
//   0x4794: 2a1f03e0  mov        w0, wzr
//   0x4798: 52800021  mov        w1, #1
//   0x479c: 94001265  bl         #0x9130
//   0x47a0: 7100001f  cmp        w0, #0
//   0x47a4: 540008e1  b.ne       #0x48c0
//   0x47a8: f9405288  ldr        x8, [x20, #0xa0]
//   0x47ac: 91072100  add        x0, x8, #0x1c8
//   0x47b0: 9400144c  bl         #0x98e0
//   0x47b4: 97fffe2b  bl         #0x4060
//   0x47b8: f9405288  ldr        x8, [x20, #0xa0]
//   0x47bc: f900c500  str        x0, [x8, #0x188]
//   0x47c0: 9400085f  bl         #0x693c
//   0x47c4: 94000bb3  bl         #0x7690
//   0x47c8: d503201f  nop        
//   0x47cc: 30fea8c0  adr        x0, #0x1ce5
//   0x47d0: 94000b92  bl         #0x7618
//   0x47d4: 2a0003f3  mov        w19, w0
//   0x47d8: b0ffffe0  adrp       x0, #0x1000
//   0x47dc: 9132f400  add        x0, x0, #0xcbd
//   0x47e0: 94000b8e  bl         #0x7618
//   0x47e4: f9405288  ldr        x8, [x20, #0xa0]
//   0x47e8: 2a1303e1  mov        w1, w19
//   0x47ec: b901e100  str        w0, [x8, #0x1e0]
//   0x47f0: 52800020  mov        w0, #1
//   0x47f4: 9400010b  bl         #0x4c20
//   0x47f8: 9400005e  bl         #0x4970
//   0x47fc: f9405288  ldr        x8, [x20, #0xa0]
//   0x4800: b0ffffe1  adrp       x1, #0x1000
//   0x4804: 9127f021  add        x1, x1, #0x9fc
//   0x4808: d0ffffe2  adrp       x2, #0x2000
//   0x480c: 91159042  add        x2, x2, #0x564
//   0x4810: 528000c0  mov        w0, #6
//   0x4814: f940c508  ldr        x8, [x8, #0x188]
//   0x4818: d354fd03  lsr        x3, x8, #0x14
//   0x481c: 940013dd  bl         #0x9790
//   0x4820: 2a1f03e0  mov        w0, wzr
//   0x4824: 14000028  b          #0x48c4
//   0x4828: b4fff4c8  cbz        x8, #0x46c0
//   0x482c: 91074100  add        x0, x8, #0x1d0
//   0x4830: 9400142c  bl         #0x98e0
//   0x4834: 940000c6  bl         #0x4b4c
//   0x4838: 9400081e  bl         #0x68b0
//   0x483c: 94000827  bl         #0x68d8
//   0x4840: 94000a3a  bl         #0x7128
//   0x4844: 94000e82  bl         #0x824c
//   0x4848: f9405280  ldr        x0, [x20, #0xa0]
//   0x484c: b941d808  ldr        w8, [x0, #0x1d8]
//   0x4850: 7100051f  cmp        w8, #1
//   0x4854: 540000ab  b.lt       #0x4868
//   0x4858: 2a0803e0  mov        w0, w8
//   0x485c: 94001429  bl         #0x9900
//   0x4860: f9405280  ldr        x0, [x20, #0xa0]
//   0x4864: b901d81f  str        wzr, [x0, #0x1d8]
//   0x4868: b941dc08  ldr        w8, [x0, #0x1dc]
//   0x486c: 7100051f  cmp        w8, #1
//   0x4870: 540000cb  b.lt       #0x4888
//   0x4874: 2a0803e0  mov        w0, w8
//   0x4878: 94001422  bl         #0x9900
//   0x487c: f9405280  ldr        x0, [x20, #0xa0]
//   0x4880: 12800008  mov        w8, #-1
//   0x4884: b901dc08  str        w8, [x0, #0x1dc]
//   0x4888: b941e008  ldr        w8, [x0, #0x1e0]
//   0x488c: 7100051f  cmp        w8, #1
//   0x4890: 540000cb  b.lt       #0x48a8
//   0x4894: 2a0803e0  mov        w0, w8
//   0x4898: 9400141a  bl         #0x9900
//   0x489c: f9405280  ldr        x0, [x20, #0xa0]
//   0x48a0: 12800008  mov        w8, #-1
//   0x48a4: b901e008  str        w8, [x0, #0x1e0]
//   0x48a8: 940013fe  bl         #0x98a0
//   0x48ac: 2a1f03e0  mov        w0, wzr
//   0x48b0: f900529f  str        xzr, [x20, #0xa0]
//   0x48b4: 14000004  b          #0x48c4
//   0x48b8: b941e900  ldr        w0, [x8, #0x1e8]
//   0x48bc: 14000002  b          #0x48c4
//   0x48c0: 128001e0  mov        w0, #-0x10
//   0x48c4: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x48c8: f9400bf5  ldr        x21, [sp, #0x10]
//   0x48cc: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x48d0: d65f03c0  ret        
//   0x48d4: aa0003f3  mov        x19, x0
//   0x48d8: b4000160  cbz        x0, #0x4904
//   0x48dc: aa1303e0  mov        x0, x19
//   0x48e0: 2a1f03e1  mov        w1, wzr
//   0x48e4: 52804402  mov        w2, #0x220
//   0x48e8: 940013c2  bl         #0x97f0
//   0x48ec: 91087260  add        x0, x19, #0x21c
//   0x48f0: aa1f03e1  mov        x1, xzr
//   0x48f4: 94001407  bl         #0x9910
//   0x48f8: 340000a0  cbz        w0, #0x490c
//   0x48fc: 12800200  mov        w0, #-0x11
//   0x4900: 17fffff1  b          #0x48c4
//   0x4904: 128000a0  mov        w0, #-6
//   0x4908: 17ffffef  b          #0x48c4
//   0x490c: f9405288  ldr        x8, [x20, #0xa0]
//   0x4910: aa1f03e1  mov        x1, xzr
//   0x4914: b9421d00  ldr        w0, [x8, #0x21c]
//   0x4918: 94001402  bl         #0x9920
//   0x491c: f9405288  ldr        x8, [x20, #0xa0]
//   0x4920: d0ffffe9  adrp       x9, #0x2000
//   0x4924: 6f07e7e0  movi       v0.2d, #0xffffffffffffffff
//   0x4928: 3dc1b121  ldr        q1, [x9, #0x6c0]
//   0x492c: 52800029  mov        w9, #1
//   0x4930: 9106c100  add        x0, x8, #0x1b0
//   0x4934: f900591f  str        xzr, [x8, #0xb0]
//   0x4938: fd00ed00  str        d0, [x8, #0x1d8]
//   0x493c: 3d802901  str        q1, [x8, #0xa0]
//   0x4940: 3902c2a9  strb       w9, [x21, #0xb0]
//   0x4944: 940013e7  bl         #0x98e0
//   0x4948: 94000e99  bl         #0x83ac
//   0x494c: 940008d3  bl         #0x6c98
//   0x4950: 94000c2f  bl         #0x7a0c
//   0x4954: 2a1f03e0  mov        w0, wzr
//   0x4958: 17ffffdb  b          #0x48c4

// ----------------------------------------------------------------------------
// FDE[24] HeapTrackerNeonAdd2x64_495c (0x495c..0x4970, 20 bytes, 5 instructions)
// Summary / Tóm tắt: NEON vector 2x64-bit addition: add v0.2d, v1.2d, v0.2d (@ 0x495c..0x4970)
// ----------------------------------------------------------------------------
//   0x495c: 3dc00020  ldr        q0, [x1]
//   0x4960: 3dc00001  ldr        q1, [x0]
//   0x4964: 4ee08420  add        v0.2d, v1.2d, v0.2d
//   0x4968: 3d800000  str        q0, [x0]
//   0x496c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[25] HeapTrackerFde_4970 (0x4970..0x4aa8, 312 bytes, 78 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x4970..0x4aa8
// ----------------------------------------------------------------------------
//   0x4970: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x4974: f9000bfc  str        x28, [sp, #0x10]
//   0x4978: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x497c: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x4980: 910003fd  mov        x29, sp
//   0x4984: d120c3ff  sub        sp, sp, #0x830
//   0x4988: d53bd056  mrs        x22, tpidr_el0
//   0x498c: f94016c8  ldr        x8, [x22, #0x28]
//   0x4990: f81f83a8  stur       x8, [x29, #-8]
//   0x4994: 94000b3c  bl         #0x7684
//   0x4998: b4000700  cbz        x0, #0x4a78
//   0x499c: aa0003e4  mov        x4, x0
//   0x49a0: d503201f  nop        
//   0x49a4: 50febf43  adr        x3, #0x218e
//   0x49a8: 910023e0  add        x0, sp, #8
//   0x49ac: 52808001  mov        w1, #0x400
//   0x49b0: 52808002  mov        w2, #0x400
//   0x49b4: 9400003d  bl         #0x4aa8
//   0x49b8: 940013de  bl         #0x9930
//   0x49bc: 2a0003e4  mov        w4, w0
//   0x49c0: 36f80060  tbz        w0, #0x1f, #0x49cc
//   0x49c4: 940013db  bl         #0x9930
//   0x49c8: 2a0003e4  mov        w4, w0
//   0x49cc: d0ffffe3  adrp       x3, #0x2000
//   0x49d0: 91031063  add        x3, x3, #0xc4
//   0x49d4: 911023e0  add        x0, sp, #0x408
//   0x49d8: 52800401  mov        w1, #0x20
//   0x49dc: 52800402  mov        w2, #0x20
//   0x49e0: 94000032  bl         #0x4aa8
//   0x49e4: 52800841  mov        w1, #0x42
//   0x49e8: 910023e0  add        x0, sp, #8
//   0x49ec: 72a00101  movk       w1, #8, lsl #16
//   0x49f0: 52803002  mov        w2, #0x180
//   0x49f4: 940013d3  bl         #0x9940
//   0x49f8: 37f803c0  tbnz       w0, #0x1f, #0x4a70
//   0x49fc: 2a0003f3  mov        w19, w0
//   0x4a00: 911023e0  add        x0, sp, #0x408
//   0x4a04: 52a00101  mov        w1, #0x80000
//   0x4a08: 940013d2  bl         #0x9950
//   0x4a0c: 37f802e0  tbnz       w0, #0x1f, #0x4a68
//   0x4a10: 9110a3e1  add        x1, sp, #0x428
//   0x4a14: 52808002  mov        w2, #0x400
//   0x4a18: 2a0003f4  mov        w20, w0
//   0x4a1c: 940013d1  bl         #0x9960
//   0x4a20: f100041f  cmp        x0, #1
//   0x4a24: 540001eb  b.lt       #0x4a60
//   0x4a28: aa0003f5  mov        x21, x0
//   0x4a2c: 9110a3e1  add        x1, sp, #0x428
//   0x4a30: 2a1303e0  mov        w0, w19
//   0x4a34: aa1503e2  mov        x2, x21
//   0x4a38: 940013ce  bl         #0x9970
//   0x4a3c: eb15001f  cmp        x0, x21
//   0x4a40: 54000101  b.ne       #0x4a60
//   0x4a44: 9110a3e1  add        x1, sp, #0x428
//   0x4a48: 2a1403e0  mov        w0, w20
//   0x4a4c: 52808002  mov        w2, #0x400
//   0x4a50: 940013c4  bl         #0x9960
//   0x4a54: aa0003f5  mov        x21, x0
//   0x4a58: f100041f  cmp        x0, #1
//   0x4a5c: 54fffe8a  b.ge       #0x4a2c
//   0x4a60: 2a1403e0  mov        w0, w20
//   0x4a64: 940013a7  bl         #0x9900
//   0x4a68: 2a1303e0  mov        w0, w19
//   0x4a6c: 940013a5  bl         #0x9900
//   0x4a70: 2a1f03e0  mov        w0, wzr
//   0x4a74: 14000002  b          #0x4a7c
//   0x4a78: 12800000  mov        w0, #-1
//   0x4a7c: f94016c8  ldr        x8, [x22, #0x28]
//   0x4a80: f85f83a9  ldur       x9, [x29, #-8]
//   0x4a84: eb09011f  cmp        x8, x9
//   0x4a88: 540000e1  b.ne       #0x4aa4
//   0x4a8c: 9120c3ff  add        sp, sp, #0x830
//   0x4a90: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x4a94: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x4a98: f9400bfc  ldr        x28, [sp, #0x10]
//   0x4a9c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x4aa0: d65f03c0  ret        
//   0x4aa4: 9400136f  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[26] HeapTrackerFde_4aa8 (0x4aa8..0x4b4c, 164 bytes, 41 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x4aa8..0x4b4c
// ----------------------------------------------------------------------------
//   0x4aa8: d10443ff  sub        sp, sp, #0x110
//   0x4aac: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x4ab0: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x4ab4: 9103c3fd  add        x29, sp, #0xf0
//   0x4ab8: a93917a4  stp        x4, x5, [x29, #-0x70]
//   0x4abc: d101c3aa  sub        x10, x29, #0x70
//   0x4ac0: a93a1fa6  stp        x6, x7, [x29, #-0x60]
//   0x4ac4: 928003ec  mov        x12, #-0x20
//   0x4ac8: ad0007e0  stp        q0, q1, [sp]
//   0x4acc: 910003ed  mov        x13, sp
//   0x4ad0: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x4ad4: 9100814a  add        x10, x10, #0x20
//   0x4ad8: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x4adc: f2dff00c  movk       x12, #0xff80, lsl #32
//   0x4ae0: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x4ae4: d53bd053  mrs        x19, tpidr_el0
//   0x4ae8: f9401669  ldr        x9, [x19, #0x28]
//   0x4aec: 910201ad  add        x13, x13, #0x80
//   0x4af0: d100a3ab  sub        x11, x29, #0x28
//   0x4af4: aa0303e8  mov        x8, x3
//   0x4af8: aa0103e3  mov        x3, x1
//   0x4afc: d10143a5  sub        x5, x29, #0x50
//   0x4b00: f81f83a9  stur       x9, [x29, #-8]
//   0x4b04: 910083a9  add        x9, x29, #0x20
//   0x4b08: a93eb3ad  stp        x13, x12, [x29, #-0x18]
//   0x4b0c: aa0203e1  mov        x1, x2
//   0x4b10: 2a1f03e2  mov        w2, wzr
//   0x4b14: aa0803e4  mov        x4, x8
//   0x4b18: a93daba9  stp        x9, x10, [x29, #-0x28]
//   0x4b1c: ad400560  ldp        q0, q1, [x11]
//   0x4b20: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x4b24: 94001397  bl         #0x9980
//   0x4b28: f9401668  ldr        x8, [x19, #0x28]
//   0x4b2c: f85f83a9  ldur       x9, [x29, #-8]
//   0x4b30: eb09011f  cmp        x8, x9
//   0x4b34: 540000a1  b.ne       #0x4b48
//   0x4b38: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x4b3c: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x4b40: 910443ff  add        sp, sp, #0x110
//   0x4b44: d65f03c0  ret        
//   0x4b48: 94001346  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[27] HeapTrackerFde_4b4c (0x4b4c..0x4c20, 212 bytes, 53 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x4b4c..0x4c20
// ----------------------------------------------------------------------------
//   0x4b4c: d10403ff  sub        sp, sp, #0x100
//   0x4b50: a90e7bfd  stp        x29, x30, [sp, #0xe0]
//   0x4b54: a90f4ff4  stp        x20, x19, [sp, #0xf0]
//   0x4b58: 910383fd  add        x29, sp, #0xe0
//   0x4b5c: b0000053  adrp       x19, #0xd000
//   0x4b60: d53bd054  mrs        x20, tpidr_el0
//   0x4b64: f9401688  ldr        x8, [x20, #0x28]
//   0x4b68: f946be73  ldr        x19, [x19, #0xd78]
//   0x4b6c: f81f83a8  stur       x8, [x29, #-8]
//   0x4b70: f9400268  ldr        x8, [x19]
//   0x4b74: b4000448  cbz        x8, #0x4bfc
//   0x4b78: b941d908  ldr        w8, [x8, #0x1d8]
//   0x4b7c: 37f80408  tbnz       w8, #0x1f, #0x4bfc
//   0x4b80: 910063e0  add        x0, sp, #0x18
//   0x4b84: 94001357  bl         #0x98e0
//   0x4b88: f9400268  ldr        x8, [x19]
//   0x4b8c: 910063e0  add        x0, sp, #0x18
//   0x4b90: 910083e1  add        x1, sp, #0x20
//   0x4b94: b941d913  ldr        w19, [x8, #0x1d8]
//   0x4b98: 9400137e  bl         #0x9990
//   0x4b9c: b4000300  cbz        x0, #0x4bfc
//   0x4ba0: 294623e9  ldp        w9, w8, [sp, #0x30]
//   0x4ba4: 29451fea  ldp        w10, w7, [sp, #0x28]
//   0x4ba8: d0ffffe3  adrp       x3, #0x2000
//   0x4bac: 91133863  add        x3, x3, #0x4ce
//   0x4bb0: d0ffffe4  adrp       x4, #0x2000
//   0x4bb4: 91096c84  add        x4, x4, #0x25b
//   0x4bb8: 111db105  add        w5, w8, #0x76c
//   0x4bbc: 11000526  add        w6, w9, #1
//   0x4bc0: 294423e9  ldp        w9, w8, [sp, #0x20]
//   0x4bc4: 910163e0  add        x0, sp, #0x58
//   0x4bc8: 52801001  mov        w1, #0x80
//   0x4bcc: 52801002  mov        w2, #0x80
//   0x4bd0: b90003ea  str        w10, [sp]
//   0x4bd4: b90013e9  str        w9, [sp, #0x10]
//   0x4bd8: b9000be8  str        w8, [sp, #8]
//   0x4bdc: 97ffffb3  bl         #0x4aa8
//   0x4be0: 51000408  sub        w8, w0, #1
//   0x4be4: 7101f91f  cmp        w8, #0x7e
//   0x4be8: 540000a8  b.hi       #0x4bfc
//   0x4bec: 2a0003e2  mov        w2, w0
//   0x4bf0: 910163e1  add        x1, sp, #0x58
//   0x4bf4: 2a1303e0  mov        w0, w19
//   0x4bf8: 9400135e  bl         #0x9970
//   0x4bfc: f9401688  ldr        x8, [x20, #0x28]
//   0x4c00: f85f83a9  ldur       x9, [x29, #-8]
//   0x4c04: eb09011f  cmp        x8, x9
//   0x4c08: 540000a1  b.ne       #0x4c1c
//   0x4c0c: a94f4ff4  ldp        x20, x19, [sp, #0xf0]
//   0x4c10: a94e7bfd  ldp        x29, x30, [sp, #0xe0]
//   0x4c14: 910403ff  add        sp, sp, #0x100
//   0x4c18: d65f03c0  ret        
//   0x4c1c: 94001311  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[28] HeapTrackerForkAndDump_4c20 (0x4c20..0x6270, 5712 bytes, 1428 instructions)
// Summary / Tóm tắt: Forks child process, reads /proc/self/pagemap & smaps, dumps leak_heap.txt (@ 0x4c20..0x6270)
// ----------------------------------------------------------------------------
//   0x4c20: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x4c24: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x4c28: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x4c2c: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x4c30: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x4c34: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x4c38: 910003fd  mov        x29, sp
//   0x4c3c: d11443ff  sub        sp, sp, #0x510
//   0x4c40: d53bd049  mrs        x9, tpidr_el0
//   0x4c44: f9401528  ldr        x8, [x9, #0x28]
//   0x4c48: f81f03a8  stur       x8, [x29, #-0x10]
//   0x4c4c: 37f87981  tbnz       w1, #0x1f, #0x5b7c
//   0x4c50: b0000053  adrp       x19, #0xd000
//   0x4c54: b90077e0  str        w0, [sp, #0x74]
//   0x4c58: f9003fe9  str        x9, [sp, #0x78]
//   0x4c5c: f946be73  ldr        x19, [x19, #0xd78]
//   0x4c60: f9400268  ldr        x8, [x19]
//   0x4c64: b901d901  str        w1, [x8, #0x1d8]
//   0x4c68: 94000b2f  bl         #0x7924
//   0x4c6c: 9102e3e8  add        x8, sp, #0xb8
//   0x4c70: f9400260  ldr        x0, [x19]
//   0x4c74: a90ba3e8  stp        x8, x8, [sp, #0xb8]
//   0x4c78: 9400134a  bl         #0x99a0
//   0x4c7c: 940010fa  bl         #0x9064
//   0x4c80: b900b3e0  str        w0, [sp, #0xb0]
//   0x4c84: f9400260  ldr        x0, [x19]
//   0x4c88: aa1f03e9  mov        x9, xzr
//   0x4c8c: 9100a00a  add        x10, x0, #0x28
//   0x4c90: aa0903e8  mov        x8, x9
//   0x4c94: f9400149  ldr        x9, [x10]
//   0x4c98: 9100412a  add        x10, x9, #0x10
//   0x4c9c: b5ffffa9  cbnz       x9, #0x4c90
//   0x4ca0: aa1f03fc  mov        x28, xzr
//   0x4ca4: aa1f03fb  mov        x27, xzr
//   0x4ca8: aa1f03f5  mov        x21, xzr
//   0x4cac: b4001c68  cbz        x8, #0x5038
//   0x4cb0: 52800029  mov        w9, #1
//   0x4cb4: 9102e3f4  add        x20, sp, #0xb8
//   0x4cb8: 4e080d20  dup        v0.2d, x9
//   0x4cbc: 3d802be0  str        q0, [sp, #0xa0]
//   0x4cc0: aa0803f6  mov        x22, x8
//   0x4cc4: f9405ff8  ldr        x24, [sp, #0xb8]
//   0x4cc8: f940251a  ldr        x26, [x8, #0x48]
//   0x4ccc: 14000002  b          #0x4cd4
//   0x4cd0: f9400318  ldr        x24, [x24]
//   0x4cd4: eb14031f  cmp        x24, x20
//   0x4cd8: 54000300  b.eq       #0x4d38
//   0x4cdc: aa1803e8  mov        x8, x24
//   0x4ce0: f8410d17  ldr        x23, [x8, #0x10]!
//   0x4ce4: eb0802ff  cmp        x23, x8
//   0x4ce8: 54ffff40  b.eq       #0x4cd0
//   0x4cec: f9401ec9  ldr        x9, [x22, #0x38]
//   0x4cf0: f9401aea  ldr        x10, [x23, #0x30]
//   0x4cf4: eb09015f  cmp        x10, x9
//   0x4cf8: 540000a0  b.eq       #0x4d0c
//   0x4cfc: f94002f7  ldr        x23, [x23]
//   0x4d00: eb0802ff  cmp        x23, x8
//   0x4d04: 54ffff61  b.ne       #0x4cf0
//   0x4d08: 17fffff2  b          #0x4cd0
//   0x4d0c: 910042f3  add        x19, x23, #0x10
//   0x4d10: aa1303f9  mov        x25, x19
//   0x4d14: f9400339  ldr        x25, [x25]
//   0x4d18: eb13033f  cmp        x25, x19
//   0x4d1c: 54000640  b.eq       #0x4de4
//   0x4d20: f9401b28  ldr        x8, [x25, #0x30]
//   0x4d24: f94022c9  ldr        x9, [x22, #0x40]
//   0x4d28: eb09011f  cmp        x8, x9
//   0x4d2c: 54ffff41  b.ne       #0x4d14
//   0x4d30: b50010d7  cbnz       x23, #0x4f48
//   0x4d34: 140000ab  b          #0x4fe0
//   0x4d38: b0000048  adrp       x8, #0xd000
//   0x4d3c: 52800c00  mov        w0, #0x60
//   0x4d40: f946b508  ldr        x8, [x8, #0xd68]
//   0x4d44: f9400108  ldr        x8, [x8]
//   0x4d48: f9400d08  ldr        x8, [x8, #0x18]
//   0x4d4c: d63f0100  blr        x8
//   0x4d50: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4d54: aa0003f3  mov        x19, x0
//   0x4d58: aa0003f7  mov        x23, x0
//   0x4d5c: 910403e1  add        x1, sp, #0x100
//   0x4d60: 3d800000  str        q0, [x0]
//   0x4d64: ad010000  stp        q0, q0, [x0, #0x20]
//   0x4d68: ad020000  stp        q0, q0, [x0, #0x40]
//   0x4d6c: 3c810e60  str        q0, [x19, #0x10]!
//   0x4d70: f9000273  str        x19, [x19]
//   0x4d74: f9000c13  str        x19, [x0, #0x18]
//   0x4d78: f9401ec0  ldr        x0, [x22, #0x38]
//   0x4d7c: f9001ae0  str        x0, [x23, #0x30]
//   0x4d80: b9406ac8  ldr        w8, [x22, #0x68]
//   0x4d84: b9005ae8  str        w8, [x23, #0x58]
//   0x4d88: 9400130a  bl         #0x99b0
//   0x4d8c: 34000320  cbz        w0, #0x4df0
//   0x4d90: 2a0003e8  mov        w8, w0
//   0x4d94: f9408be0  ldr        x0, [sp, #0x110]
//   0x4d98: b4000080  cbz        x0, #0x4da8
//   0x4d9c: 7100091f  cmp        w8, #2
//   0x4da0: 54000040  b.eq       #0x4da8
//   0x4da4: 94001267  bl         #0x9740
//   0x4da8: f9408fe9  ldr        x9, [sp, #0x118]
//   0x4dac: 9102e3f8  add        x24, sp, #0xb8
//   0x4db0: f94087e8  ldr        x8, [sp, #0x108]
//   0x4db4: f9401aea  ldr        x10, [x23, #0x30]
//   0x4db8: f100013f  cmp        x9, #0
//   0x4dbc: 9a890109  csel       x9, x8, x9, eq
//   0x4dc0: cb090149  sub        x9, x10, x9
//   0x4dc4: a903a6e0  stp        x0, x9, [x23, #0x38]
//   0x4dc8: f9400318  ldr        x24, [x24]
//   0x4dcc: eb14031f  cmp        x24, x20
//   0x4dd0: 540001e0  b.eq       #0x4e0c
//   0x4dd4: f9401b09  ldr        x9, [x24, #0x30]
//   0x4dd8: eb08013f  cmp        x9, x8
//   0x4ddc: 54ffff61  b.ne       #0x4dc8
//   0x4de0: 1400003b  b          #0x4ecc
//   0x4de4: b0000048  adrp       x8, #0xd000
//   0x4de8: f946b508  ldr        x8, [x8, #0xd68]
//   0x4dec: 14000041  b          #0x4ef0
//   0x4df0: 9102e3f8  add        x24, sp, #0xb8
//   0x4df4: f9400318  ldr        x24, [x24]
//   0x4df8: eb14031f  cmp        x24, x20
//   0x4dfc: 54000360  b.eq       #0x4e68
//   0x4e00: f9401b08  ldr        x8, [x24, #0x30]
//   0x4e04: b5ffff88  cbnz       x8, #0x4df4
//   0x4e08: 14000031  b          #0x4ecc
//   0x4e0c: b0000048  adrp       x8, #0xd000
//   0x4e10: 52800a00  mov        w0, #0x50
//   0x4e14: f946b508  ldr        x8, [x8, #0xd68]
//   0x4e18: f9400108  ldr        x8, [x8]
//   0x4e1c: f9400d08  ldr        x8, [x8, #0x18]
//   0x4e20: d63f0100  blr        x8
//   0x4e24: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4e28: aa0003e8  mov        x8, x0
//   0x4e2c: aa0003f8  mov        x24, x0
//   0x4e30: 3d800000  str        q0, [x0]
//   0x4e34: ad010000  stp        q0, q0, [x0, #0x20]
//   0x4e38: 3d801000  str        q0, [x0, #0x40]
//   0x4e3c: 3c810d00  str        q0, [x8, #0x10]!
//   0x4e40: a95027e0  ldp        x0, x9, [sp, #0x100]
//   0x4e44: f9000108  str        x8, [x8]
//   0x4e48: f9000f08  str        x8, [x24, #0x18]
//   0x4e4c: f9001b09  str        x9, [x24, #0x30]
//   0x4e50: b4000320  cbz        x0, #0x4eb4
//   0x4e54: 528005e1  mov        w1, #0x2f
//   0x4e58: 940012da  bl         #0x99c0
//   0x4e5c: b4000260  cbz        x0, #0x4ea8
//   0x4e60: 91000400  add        x0, x0, #1
//   0x4e64: 14000012  b          #0x4eac
//   0x4e68: b0000048  adrp       x8, #0xd000
//   0x4e6c: 52800a00  mov        w0, #0x50
//   0x4e70: f946b508  ldr        x8, [x8, #0xd68]
//   0x4e74: f9400108  ldr        x8, [x8]
//   0x4e78: f9400d08  ldr        x8, [x8, #0x18]
//   0x4e7c: d63f0100  blr        x8
//   0x4e80: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4e84: aa0003e8  mov        x8, x0
//   0x4e88: aa0003f8  mov        x24, x0
//   0x4e8c: 3d800000  str        q0, [x0]
//   0x4e90: ad010000  stp        q0, q0, [x0, #0x20]
//   0x4e94: 3d801000  str        q0, [x0, #0x40]
//   0x4e98: 3c810d00  str        q0, [x8, #0x10]!
//   0x4e9c: f9000108  str        x8, [x8]
//   0x4ea0: f9000c08  str        x8, [x0, #0x18]
//   0x4ea4: 14000004  b          #0x4eb4
//   0x4ea8: f94083e0  ldr        x0, [sp, #0x100]
//   0x4eac: 94001225  bl         #0x9740
//   0x4eb0: f9001f00  str        x0, [x24, #0x38]
//   0x4eb4: f9000314  str        x20, [x24]
//   0x4eb8: f94063e8  ldr        x8, [sp, #0xc0]
//   0x4ebc: f9000708  str        x8, [x24, #8]
//   0x4ec0: f94063e8  ldr        x8, [sp, #0xc0]
//   0x4ec4: f9000118  str        x24, [x8]
//   0x4ec8: f90063f8  str        x24, [sp, #0xc0]
//   0x4ecc: 91004308  add        x8, x24, #0x10
//   0x4ed0: f90002e8  str        x8, [x23]
//   0x4ed4: f9400f08  ldr        x8, [x24, #0x18]
//   0x4ed8: f90006e8  str        x8, [x23, #8]
//   0x4edc: f9400f08  ldr        x8, [x24, #0x18]
//   0x4ee0: f9000117  str        x23, [x8]
//   0x4ee4: b0000048  adrp       x8, #0xd000
//   0x4ee8: f946b508  ldr        x8, [x8, #0xd68]
//   0x4eec: f9000f17  str        x23, [x24, #0x18]
//   0x4ef0: f9400108  ldr        x8, [x8]
//   0x4ef4: f9400d08  ldr        x8, [x8, #0x18]
//   0x4ef8: 52800a00  mov        w0, #0x50
//   0x4efc: d63f0100  blr        x8
//   0x4f00: 6f00e400  movi       v0.2d, #0000000000000000
//   0x4f04: aa0003e8  mov        x8, x0
//   0x4f08: aa0003f9  mov        x25, x0
//   0x4f0c: ad018000  stp        q0, q0, [x0, #0x30]
//   0x4f10: 3d800800  str        q0, [x0, #0x20]
//   0x4f14: 3d800000  str        q0, [x0]
//   0x4f18: 3c810d00  str        q0, [x8, #0x10]!
//   0x4f1c: f9000108  str        x8, [x8]
//   0x4f20: f9000c08  str        x8, [x0, #0x18]
//   0x4f24: f94022c8  ldr        x8, [x22, #0x40]
//   0x4f28: f9000013  str        x19, [x0]
//   0x4f2c: f9001808  str        x8, [x0, #0x30]
//   0x4f30: f9400ee8  ldr        x8, [x23, #0x18]
//   0x4f34: f9000408  str        x8, [x0, #8]
//   0x4f38: f9400ee8  ldr        x8, [x23, #0x18]
//   0x4f3c: f9000100  str        x0, [x8]
//   0x4f40: f9000ee0  str        x0, [x23, #0x18]
//   0x4f44: b40004f7  cbz        x23, #0x4fe0
//   0x4f48: b40004d8  cbz        x24, #0x4fe0
//   0x4f4c: b940b3e0  ldr        w0, [sp, #0xb0]
//   0x4f50: aa1603e1  mov        x1, x22
//   0x4f54: 94001002  bl         #0x8f5c
//   0x4f58: 910122c8  add        x8, x22, #0x48
//   0x4f5c: 3dc02be0  ldr        q0, [sp, #0xa0]
//   0x4f60: 3dc00b21  ldr        q1, [x25, #0x20]
//   0x4f64: 0d408500  ld1        {v0.d}[0], [x8]
//   0x4f68: 91004328  add        x8, x25, #0x10
//   0x4f6c: 4ee08421  add        v1.2d, v1.2d, v0.2d
//   0x4f70: 3d800b21  str        q1, [x25, #0x20]
//   0x4f74: 3dc00ae1  ldr        q1, [x23, #0x20]
//   0x4f78: 4ee08421  add        v1.2d, v1.2d, v0.2d
//   0x4f7c: 3d800ae1  str        q1, [x23, #0x20]
//   0x4f80: 3dc00b01  ldr        q1, [x24, #0x20]
//   0x4f84: 4ee08420  add        v0.2d, v1.2d, v0.2d
//   0x4f88: 3d800b00  str        q0, [x24, #0x20]
//   0x4f8c: 3dc016c0  ldr        q0, [x22, #0x50]
//   0x4f90: 3dc01321  ldr        q1, [x25, #0x40]
//   0x4f94: 4ee08420  add        v0.2d, v1.2d, v0.2d
//   0x4f98: 3d801320  str        q0, [x25, #0x40]
//   0x4f9c: 3dc016c0  ldr        q0, [x22, #0x50]
//   0x4fa0: 3cc482e1  ldur       q1, [x23, #0x48]
//   0x4fa4: 4ee08420  add        v0.2d, v1.2d, v0.2d
//   0x4fa8: 3c8482e0  stur       q0, [x23, #0x48]
//   0x4fac: 3dc016c0  ldr        q0, [x22, #0x50]
//   0x4fb0: 3dc01301  ldr        q1, [x24, #0x40]
//   0x4fb4: 4ee08420  add        v0.2d, v1.2d, v0.2d
//   0x4fb8: 3d801300  str        q0, [x24, #0x40]
//   0x4fbc: f90002c8  str        x8, [x22]
//   0x4fc0: a9452ac9  ldp        x9, x10, [x22, #0x50]
//   0x4fc4: f9400f28  ldr        x8, [x25, #0x18]
//   0x4fc8: 8b1c013c  add        x28, x9, x28
//   0x4fcc: f90006c8  str        x8, [x22, #8]
//   0x4fd0: 8b1b015b  add        x27, x10, x27
//   0x4fd4: f9400f28  ldr        x8, [x25, #0x18]
//   0x4fd8: f9000116  str        x22, [x8]
//   0x4fdc: f9000f36  str        x22, [x25, #0x18]
//   0x4fe0: f9400ec9  ldr        x9, [x22, #0x18]
//   0x4fe4: 8b150355  add        x21, x26, x21
//   0x4fe8: b40000a9  cbz        x9, #0x4ffc
//   0x4fec: aa0903e8  mov        x8, x9
//   0x4ff0: f9400929  ldr        x9, [x9, #0x10]
//   0x4ff4: b5ffffc9  cbnz       x9, #0x4fec
//   0x4ff8: 17ffff32  b          #0x4cc0
//   0x4ffc: f94012c8  ldr        x8, [x22, #0x20]
//   0x5000: b4000088  cbz        x8, #0x5010
//   0x5004: f9400909  ldr        x9, [x8, #0x10]
//   0x5008: eb16013f  cmp        x9, x22
//   0x500c: 54ffe5a0  b.eq       #0x4cc0
//   0x5010: f94012c8  ldr        x8, [x22, #0x20]
//   0x5014: b40000c8  cbz        x8, #0x502c
//   0x5018: f9400d09  ldr        x9, [x8, #0x18]
//   0x501c: eb0902df  cmp        x22, x9
//   0x5020: aa0803f6  mov        x22, x8
//   0x5024: 54ffff60  b.eq       #0x5010
//   0x5028: 17ffff26  b          #0x4cc0
//   0x502c: 90000053  adrp       x19, #0xd000
//   0x5030: f946be73  ldr        x19, [x19, #0xd78]
//   0x5034: f9400260  ldr        x0, [x19]
//   0x5038: 94001266  bl         #0x99d0
//   0x503c: f9400268  ldr        x8, [x19]
//   0x5040: f940a909  ldr        x9, [x8, #0x150]
//   0x5044: a915ed1c  stp        x28, x27, [x8, #0x158]
//   0x5048: f940b50a  ldr        x10, [x8, #0x168]
//   0x504c: cb0a0124  sub        x4, x9, x10
//   0x5050: eb0402bf  cmp        x21, x4
//   0x5054: 54000100  b.eq       #0x5074
//   0x5058: 90ffffe1  adrp       x1, #0x1000
//   0x505c: 9127f021  add        x1, x1, #0x9fc
//   0x5060: 90ffffe2  adrp       x2, #0x1000
//   0x5064: 913e8842  add        x2, x2, #0xfa2
//   0x5068: 528000c0  mov        w0, #6
//   0x506c: aa1503e3  mov        x3, x21
//   0x5070: 940011c8  bl         #0x9790
//   0x5074: b940b3e0  ldr        w0, [sp, #0xb0]
//   0x5078: 94001024  bl         #0x9108
//   0x507c: f94063e8  ldr        x8, [sp, #0xc0]
//   0x5080: 9102e3e9  add        x9, sp, #0xb8
//   0x5084: eb09011f  cmp        x8, x9
//   0x5088: 540006a0  b.eq       #0x515c
//   0x508c: 910403ea  add        x10, sp, #0x100
//   0x5090: 14000005  b          #0x50a4
//   0x5094: f9400108  ldr        x8, [x8]
//   0x5098: f9400508  ldr        x8, [x8, #8]
//   0x509c: eb09011f  cmp        x8, x9
//   0x50a0: 540005e0  b.eq       #0x515c
//   0x50a4: f9405feb  ldr        x11, [sp, #0xb8]
//   0x50a8: eb09017f  cmp        x11, x9
//   0x50ac: fa481164  ccmp       x11, x8, #4, ne
//   0x50b0: 54ffff40  b.eq       #0x5098
//   0x50b4: 14000006  b          #0x50cc
//   0x50b8: aa0c03eb  mov        x11, x12
//   0x50bc: eb09017f  cmp        x11, x9
//   0x50c0: 54fffec0  b.eq       #0x5098
//   0x50c4: eb08017f  cmp        x11, x8
//   0x50c8: 54fffe80  b.eq       #0x5098
//   0x50cc: f940016c  ldr        x12, [x11]
//   0x50d0: f940116d  ldr        x13, [x11, #0x20]
//   0x50d4: f940118e  ldr        x14, [x12, #0x20]
//   0x50d8: eb0e01bf  cmp        x13, x14
//   0x50dc: 54fffee2  b.hs       #0x50b8
//   0x50e0: f940058d  ldr        x13, [x12, #8]
//   0x50e4: f900058a  str        x10, [x12, #8]
//   0x50e8: a91037ec  stp        x12, x13, [sp, #0x100]
//   0x50ec: f90001aa  str        x10, [x13]
//   0x50f0: f940018d  ldr        x13, [x12]
//   0x50f4: f90005aa  str        x10, [x13, #8]
//   0x50f8: f940058e  ldr        x14, [x12, #8]
//   0x50fc: f90001cd  str        x13, [x14]
//   0x5100: f940056d  ldr        x13, [x11, #8]
//   0x5104: f900056c  str        x12, [x11, #8]
//   0x5108: a900358b  stp        x11, x13, [x12]
//   0x510c: f90001ac  str        x12, [x13]
//   0x5110: a940316d  ldp        x13, x12, [x11]
//   0x5114: f90005ac  str        x12, [x13, #8]
//   0x5118: f940056c  ldr        x12, [x11, #8]
//   0x511c: f900018d  str        x13, [x12]
//   0x5120: f94087ec  ldr        x12, [sp, #0x108]
//   0x5124: f90087eb  str        x11, [sp, #0x108]
//   0x5128: a900316a  stp        x10, x12, [x11]
//   0x512c: f900018b  str        x11, [x12]
//   0x5130: f94083ec  ldr        x12, [sp, #0x100]
//   0x5134: f900058b  str        x11, [x12, #8]
//   0x5138: f94087ed  ldr        x13, [sp, #0x108]
//   0x513c: f90001ac  str        x12, [x13]
//   0x5140: f940056b  ldr        x11, [x11, #8]
//   0x5144: eb08017f  cmp        x11, x8
//   0x5148: 54fffa60  b.eq       #0x5094
//   0x514c: f940016b  ldr        x11, [x11]
//   0x5150: eb09017f  cmp        x11, x9
//   0x5154: 54fffb81  b.ne       #0x50c4
//   0x5158: 17ffffd0  b          #0x5098
//   0x515c: f9405fe8  ldr        x8, [sp, #0xb8]
//   0x5160: eb09011f  cmp        x8, x9
//   0x5164: 54001600  b.eq       #0x5424
//   0x5168: 9102e3e9  add        x9, sp, #0xb8
//   0x516c: 910403ea  add        x10, sp, #0x100
//   0x5170: 14000004  b          #0x5180
//   0x5174: f9400108  ldr        x8, [x8]
//   0x5178: eb09011f  cmp        x8, x9
//   0x517c: 54001540  b.eq       #0x5424
//   0x5180: f9400d0c  ldr        x12, [x8, #0x18]
//   0x5184: 9100410b  add        x11, x8, #0x10
//   0x5188: 14000003  b          #0x5194
//   0x518c: f940018c  ldr        x12, [x12]
//   0x5190: f940058c  ldr        x12, [x12, #8]
//   0x5194: eb0b019f  cmp        x12, x11
//   0x5198: 540005e0  b.eq       #0x5254
//   0x519c: f940016d  ldr        x13, [x11]
//   0x51a0: eb0b01bf  cmp        x13, x11
//   0x51a4: fa4c11a4  ccmp       x13, x12, #4, ne
//   0x51a8: 54ffff40  b.eq       #0x5190
//   0x51ac: 14000006  b          #0x51c4
//   0x51b0: aa0e03ed  mov        x13, x14
//   0x51b4: eb0b01bf  cmp        x13, x11
//   0x51b8: 54fffec0  b.eq       #0x5190
//   0x51bc: eb0c01bf  cmp        x13, x12
//   0x51c0: 54fffe80  b.eq       #0x5190
//   0x51c4: f94001ae  ldr        x14, [x13]
//   0x51c8: f94011af  ldr        x15, [x13, #0x20]
//   0x51cc: f94011d0  ldr        x16, [x14, #0x20]
//   0x51d0: eb1001ff  cmp        x15, x16
//   0x51d4: 54fffee2  b.hs       #0x51b0
//   0x51d8: f94005cf  ldr        x15, [x14, #8]
//   0x51dc: f90005ca  str        x10, [x14, #8]
//   0x51e0: a9103fee  stp        x14, x15, [sp, #0x100]
//   0x51e4: f90001ea  str        x10, [x15]
//   0x51e8: f94001cf  ldr        x15, [x14]
//   0x51ec: f90005ea  str        x10, [x15, #8]
//   0x51f0: f94005d0  ldr        x16, [x14, #8]
//   0x51f4: f900020f  str        x15, [x16]
//   0x51f8: f94005af  ldr        x15, [x13, #8]
//   0x51fc: f90005ae  str        x14, [x13, #8]
//   0x5200: a9003dcd  stp        x13, x15, [x14]
//   0x5204: f90001ee  str        x14, [x15]
//   0x5208: a94039af  ldp        x15, x14, [x13]
//   0x520c: f90005ee  str        x14, [x15, #8]
//   0x5210: f94005ae  ldr        x14, [x13, #8]
//   0x5214: f90001cf  str        x15, [x14]
//   0x5218: f94087ee  ldr        x14, [sp, #0x108]
//   0x521c: f90087ed  str        x13, [sp, #0x108]
//   0x5220: a90039aa  stp        x10, x14, [x13]
//   0x5224: f90001cd  str        x13, [x14]
//   0x5228: f94083ee  ldr        x14, [sp, #0x100]
//   0x522c: f90005cd  str        x13, [x14, #8]
//   0x5230: f94087ef  ldr        x15, [sp, #0x108]
//   0x5234: f90001ee  str        x14, [x15]
//   0x5238: f94005ad  ldr        x13, [x13, #8]
//   0x523c: eb0c01bf  cmp        x13, x12
//   0x5240: 54fffa60  b.eq       #0x518c
//   0x5244: f94001ad  ldr        x13, [x13]
//   0x5248: eb0b01bf  cmp        x13, x11
//   0x524c: 54fffb81  b.ne       #0x51bc
//   0x5250: 17ffffd0  b          #0x5190
//   0x5254: f940016c  ldr        x12, [x11]
//   0x5258: 14000002  b          #0x5260
//   0x525c: f940018c  ldr        x12, [x12]
//   0x5260: eb0b019f  cmp        x12, x11
//   0x5264: 54fff880  b.eq       #0x5174
//   0x5268: f9400d8e  ldr        x14, [x12, #0x18]
//   0x526c: 9100418d  add        x13, x12, #0x10
//   0x5270: 14000003  b          #0x527c
//   0x5274: f94001ce  ldr        x14, [x14]
//   0x5278: f94005ce  ldr        x14, [x14, #8]
//   0x527c: eb0d01df  cmp        x14, x13
//   0x5280: 540005e0  b.eq       #0x533c
//   0x5284: f94001af  ldr        x15, [x13]
//   0x5288: eb0d01ff  cmp        x15, x13
//   0x528c: fa4e11e4  ccmp       x15, x14, #4, ne
//   0x5290: 54ffff40  b.eq       #0x5278
//   0x5294: 14000006  b          #0x52ac
//   0x5298: aa1003ef  mov        x15, x16
//   0x529c: eb0d01ff  cmp        x15, x13
//   0x52a0: 54fffec0  b.eq       #0x5278
//   0x52a4: eb0e01ff  cmp        x15, x14
//   0x52a8: 54fffe80  b.eq       #0x5278
//   0x52ac: f94001f0  ldr        x16, [x15]
//   0x52b0: f94011f1  ldr        x17, [x15, #0x20]
//   0x52b4: f9401200  ldr        x0, [x16, #0x20]
//   0x52b8: eb00023f  cmp        x17, x0
//   0x52bc: 54fffee2  b.hs       #0x5298
//   0x52c0: f9400611  ldr        x17, [x16, #8]
//   0x52c4: f900060a  str        x10, [x16, #8]
//   0x52c8: a91047f0  stp        x16, x17, [sp, #0x100]
//   0x52cc: f900022a  str        x10, [x17]
//   0x52d0: f9400211  ldr        x17, [x16]
//   0x52d4: f900062a  str        x10, [x17, #8]
//   0x52d8: f9400600  ldr        x0, [x16, #8]
//   0x52dc: f9000011  str        x17, [x0]
//   0x52e0: f94005f1  ldr        x17, [x15, #8]
//   0x52e4: f90005f0  str        x16, [x15, #8]
//   0x52e8: a900460f  stp        x15, x17, [x16]
//   0x52ec: f9000230  str        x16, [x17]
//   0x52f0: a94041f1  ldp        x17, x16, [x15]
//   0x52f4: f9000630  str        x16, [x17, #8]
//   0x52f8: f94005f0  ldr        x16, [x15, #8]
//   0x52fc: f9000211  str        x17, [x16]
//   0x5300: f94087f0  ldr        x16, [sp, #0x108]
//   0x5304: f90087ef  str        x15, [sp, #0x108]
//   0x5308: a90041ea  stp        x10, x16, [x15]
//   0x530c: f900020f  str        x15, [x16]
//   0x5310: f94083f0  ldr        x16, [sp, #0x100]
//   0x5314: f900060f  str        x15, [x16, #8]
//   0x5318: f94087f1  ldr        x17, [sp, #0x108]
//   0x531c: f9000230  str        x16, [x17]
//   0x5320: f94005ef  ldr        x15, [x15, #8]
//   0x5324: eb0e01ff  cmp        x15, x14
//   0x5328: 54fffa60  b.eq       #0x5274
//   0x532c: f94001ef  ldr        x15, [x15]
//   0x5330: eb0d01ff  cmp        x15, x13
//   0x5334: 54fffb81  b.ne       #0x52a4
//   0x5338: 17ffffd0  b          #0x5278
//   0x533c: f94001ae  ldr        x14, [x13]
//   0x5340: 14000002  b          #0x5348
//   0x5344: f94001ce  ldr        x14, [x14]
//   0x5348: eb0d01df  cmp        x14, x13
//   0x534c: 54fff880  b.eq       #0x525c
//   0x5350: f9400dcf  ldr        x15, [x14, #0x18]
//   0x5354: 910041d0  add        x16, x14, #0x10
//   0x5358: 14000003  b          #0x5364
//   0x535c: f94001ef  ldr        x15, [x15]
//   0x5360: f94005ef  ldr        x15, [x15, #8]
//   0x5364: eb1001ff  cmp        x15, x16
//   0x5368: 54fffee0  b.eq       #0x5344
//   0x536c: f9400211  ldr        x17, [x16]
//   0x5370: eb10023f  cmp        x17, x16
//   0x5374: fa4f1224  ccmp       x17, x15, #4, ne
//   0x5378: 54ffff40  b.eq       #0x5360
//   0x537c: 14000006  b          #0x5394
//   0x5380: aa0003f1  mov        x17, x0
//   0x5384: eb10023f  cmp        x17, x16
//   0x5388: 54fffec0  b.eq       #0x5360
//   0x538c: eb0f023f  cmp        x17, x15
//   0x5390: 54fffe80  b.eq       #0x5360
//   0x5394: f9400220  ldr        x0, [x17]
//   0x5398: f9402621  ldr        x1, [x17, #0x48]
//   0x539c: f9402402  ldr        x2, [x0, #0x48]
//   0x53a0: eb02003f  cmp        x1, x2
//   0x53a4: 54fffee2  b.hs       #0x5380
//   0x53a8: f9400401  ldr        x1, [x0, #8]
//   0x53ac: f900040a  str        x10, [x0, #8]
//   0x53b0: a91007e0  stp        x0, x1, [sp, #0x100]
//   0x53b4: f900002a  str        x10, [x1]
//   0x53b8: f9400001  ldr        x1, [x0]
//   0x53bc: f900042a  str        x10, [x1, #8]
//   0x53c0: f9400402  ldr        x2, [x0, #8]
//   0x53c4: f9000041  str        x1, [x2]
//   0x53c8: f9400621  ldr        x1, [x17, #8]
//   0x53cc: f9000620  str        x0, [x17, #8]
//   0x53d0: a9000411  stp        x17, x1, [x0]
//   0x53d4: f9000020  str        x0, [x1]
//   0x53d8: a9400221  ldp        x1, x0, [x17]
//   0x53dc: f9000420  str        x0, [x1, #8]
//   0x53e0: f9400620  ldr        x0, [x17, #8]
//   0x53e4: f9000001  str        x1, [x0]
//   0x53e8: f94087e0  ldr        x0, [sp, #0x108]
//   0x53ec: f90087f1  str        x17, [sp, #0x108]
//   0x53f0: a900022a  stp        x10, x0, [x17]
//   0x53f4: f9000011  str        x17, [x0]
//   0x53f8: f94083e0  ldr        x0, [sp, #0x100]
//   0x53fc: f9000411  str        x17, [x0, #8]
//   0x5400: f94087e1  ldr        x1, [sp, #0x108]
//   0x5404: f9000020  str        x0, [x1]
//   0x5408: f9400631  ldr        x17, [x17, #8]
//   0x540c: eb0f023f  cmp        x17, x15
//   0x5410: 54fffa60  b.eq       #0x535c
//   0x5414: f9400231  ldr        x17, [x17]
//   0x5418: eb10023f  cmp        x17, x16
//   0x541c: 54fffb81  b.ne       #0x538c
//   0x5420: 17ffffd0  b          #0x5360
//   0x5424: 2a1f03e8  mov        w8, wzr
//   0x5428: 2a1f03e9  mov        w9, wzr
//   0x542c: 9102e3ea  add        x10, sp, #0xb8
//   0x5430: 9102e3eb  add        x11, sp, #0xb8
//   0x5434: 14000002  b          #0x543c
//   0x5438: 3500070f  cbnz       w15, #0x5518
//   0x543c: f940016b  ldr        x11, [x11]
//   0x5440: eb0a017f  cmp        x11, x10
//   0x5444: 540006a0  b.eq       #0x5518
//   0x5448: f940026c  ldr        x12, [x19]
//   0x544c: f940858d  ldr        x13, [x12, #0x108]
//   0x5450: b500010d  cbnz       x13, #0x5470
//   0x5454: f9401d6d  ldr        x13, [x11, #0x38]
//   0x5458: f900858d  str        x13, [x12, #0x108]
//   0x545c: f940116d  ldr        x13, [x11, #0x20]
//   0x5460: f900898d  str        x13, [x12, #0x110]
//   0x5464: 9104618c  add        x12, x12, #0x118
//   0x5468: 3dc01160  ldr        q0, [x11, #0x40]
//   0x546c: 3d800180  str        q0, [x12]
//   0x5470: 9100416d  add        x13, x11, #0x10
//   0x5474: 2a1f03ec  mov        w12, wzr
//   0x5478: aa0d03ee  mov        x14, x13
//   0x547c: 14000006  b          #0x5494
//   0x5480: 7100059f  cmp        w12, #1
//   0x5484: 5400040c  b.gt       #0x5504
//   0x5488: 2a1f03ef  mov        w15, wzr
//   0x548c: 1100058c  add        w12, w12, #1
//   0x5490: 3500036f  cbnz       w15, #0x54fc
//   0x5494: f94001ce  ldr        x14, [x14]
//   0x5498: eb0d01df  cmp        x14, x13
//   0x549c: 54000340  b.eq       #0x5504
//   0x54a0: 910041d1  add        x17, x14, #0x10
//   0x54a4: 2a1f03f0  mov        w16, wzr
//   0x54a8: 93407d29  sxtw       x9, w9
//   0x54ac: aa1103e0  mov        x0, x17
//   0x54b0: f9400000  ldr        x0, [x0]
//   0x54b4: eb11001f  cmp        x0, x17
//   0x54b8: 54fffe40  b.eq       #0x5480
//   0x54bc: f940026f  ldr        x15, [x19]
//   0x54c0: 7100061f  cmp        w16, #1
//   0x54c4: 1a9f97e2  cset       w2, hi
//   0x54c8: f9400803  ldr        x3, [x0, #0x10]
//   0x54cc: 531d7042  lsl        w2, w2, #3
//   0x54d0: 8b090de1  add        x1, x15, x9, lsl #3
//   0x54d4: 91000529  add        x9, x9, #1
//   0x54d8: 92407d2f  and        x15, x9, #0xffffffff
//   0x54dc: f10029ff  cmp        x15, #0xa
//   0x54e0: 1a9f144f  csinc      w15, w2, wzr, ne
//   0x54e4: 1a900610  cinc       w16, w16, ne
//   0x54e8: f9005c23  str        x3, [x1, #0xb8]
//   0x54ec: 34fffe2f  cbz        w15, #0x54b0
//   0x54f0: 710021ff  cmp        w15, #8
//   0x54f4: 54fffc60  b.eq       #0x5480
//   0x54f8: 17ffffe6  b          #0x5490
//   0x54fc: 710015ff  cmp        w15, #5
//   0x5500: 54fff9c1  b.ne       #0x5438
//   0x5504: 7100051f  cmp        w8, #1
//   0x5508: 5400008c  b.gt       #0x5518
//   0x550c: 2a1f03ef  mov        w15, wzr
//   0x5510: 11000508  add        w8, w8, #1
//   0x5514: 17ffffc9  b          #0x5438
//   0x5518: f9400268  ldr        x8, [x19]
//   0x551c: b0ffffe1  adrp       x1, #0x2000
//   0x5520: 910f1821  add        x1, x1, #0x3c6
//   0x5524: 528020e2  mov        w2, #0x107
//   0x5528: b941d914  ldr        w20, [x8, #0x1d8]
//   0x552c: b941e108  ldr        w8, [x8, #0x1e0]
//   0x5530: 2a1403e0  mov        w0, w20
//   0x5534: b90087e8  str        w8, [sp, #0x84]
//   0x5538: 9400110e  bl         #0x9970
//   0x553c: f9405fe8  ldr        x8, [sp, #0xb8]
//   0x5540: 9102e3e9  add        x9, sp, #0xb8
//   0x5544: eb09011f  cmp        x8, x9
//   0x5548: f9004fe8  str        x8, [sp, #0x98]
//   0x554c: 540018e0  b.eq       #0x5868
//   0x5550: 90000048  adrp       x8, #0xd000
//   0x5554: b0fffff6  adrp       x22, #0x2000
//   0x5558: 9104aad6  add        x22, x22, #0x12a
//   0x555c: f946bd08  ldr        x8, [x8, #0xd78]
//   0x5560: f9400108  ldr        x8, [x8]
//   0x5564: f940a909  ldr        x9, [x8, #0x150]
//   0x5568: f940b50a  ldr        x10, [x8, #0x168]
//   0x556c: a94a5519  ldp        x25, x21, [x8, #0xa0]
//   0x5570: cb0a0129  sub        x9, x9, x10
//   0x5574: 9ad50928  udiv       x8, x9, x21
//   0x5578: f90047e8  str        x8, [sp, #0x88]
//   0x557c: 52800028  mov        w8, #1
//   0x5580: 14000008  b          #0x55a0
//   0x5584: f9404fe8  ldr        x8, [sp, #0x98]
//   0x5588: 9102e3e9  add        x9, sp, #0xb8
//   0x558c: f9400108  ldr        x8, [x8]
//   0x5590: f9004fe8  str        x8, [sp, #0x98]
//   0x5594: eb09011f  cmp        x8, x9
//   0x5598: b94097e8  ldr        w8, [sp, #0x94]
//   0x559c: 54001660  b.eq       #0x5868
//   0x55a0: 35000fc8  cbnz       w8, #0x5798
//   0x55a4: f9404fe9  ldr        x9, [sp, #0x98]
//   0x55a8: b90097e8  str        w8, [sp, #0x94]
//   0x55ac: b900b3e8  str        w8, [sp, #0xb0]
//   0x55b0: f8410d3b  ldr        x27, [x9, #0x10]!
//   0x55b4: f90053e9  str        x9, [sp, #0xa0]
//   0x55b8: eb09037f  cmp        x27, x9
//   0x55bc: 540000c1  b.ne       #0x55d4
//   0x55c0: 17fffff1  b          #0x5584
//   0x55c4: f940037b  ldr        x27, [x27]
//   0x55c8: f94053e8  ldr        x8, [sp, #0xa0]
//   0x55cc: eb08037f  cmp        x27, x8
//   0x55d0: 54fffda0  b.eq       #0x5584
//   0x55d4: b940b3e8  ldr        w8, [sp, #0xb0]
//   0x55d8: 35000a48  cbnz       w8, #0x5720
//   0x55dc: b900b3ff  str        wzr, [sp, #0xb0]
//   0x55e0: aa1b03f8  mov        x24, x27
//   0x55e4: f8410f13  ldr        x19, [x24, #0x10]!
//   0x55e8: eb18027f  cmp        x19, x24
//   0x55ec: 54fffec0  b.eq       #0x55c4
//   0x55f0: b940b3fa  ldr        w26, [sp, #0xb0]
//   0x55f4: 14000004  b          #0x5604
//   0x55f8: f9400273  ldr        x19, [x19]
//   0x55fc: eb18027f  cmp        x19, x24
//   0x5600: 54fffe20  b.eq       #0x55c4
//   0x5604: 350005ba  cbnz       w26, #0x56b8
//   0x5608: a9428664  ldp        x4, x1, [x19, #0x28]
//   0x560c: 91010263  add        x3, x19, #0x40
//   0x5610: 2a1a03e0  mov        w0, w26
//   0x5614: f9401262  ldr        x2, [x19, #0x20]
//   0x5618: 94000929  bl         #0x7abc
//   0x561c: 90000048  adrp       x8, #0xd000
//   0x5620: f946bd08  ldr        x8, [x8, #0xd78]
//   0x5624: f9400108  ldr        x8, [x8]
//   0x5628: f9405908  ldr        x8, [x8, #0xb0]
//   0x562c: b4fffe68  cbz        x8, #0x55f8
//   0x5630: aa1303f7  mov        x23, x19
//   0x5634: f8410efc  ldr        x28, [x23, #0x10]!
//   0x5638: eb17039f  cmp        x28, x23
//   0x563c: 54fffde0  b.eq       #0x55f8
//   0x5640: 2a1a03e8  mov        w8, w26
//   0x5644: 14000005  b          #0x5658
//   0x5648: 52800028  mov        w8, #1
//   0x564c: f940039c  ldr        x28, [x28]
//   0x5650: eb17039f  cmp        x28, x23
//   0x5654: 54fffd20  b.eq       #0x55f8
//   0x5658: 34ffffa8  cbz        w8, #0x564c
//   0x565c: f9401268  ldr        x8, [x19, #0x20]
//   0x5660: f9402785  ldr        x5, [x28, #0x48]
//   0x5664: 9ad50908  udiv       x8, x8, x21
//   0x5668: eb0800bf  cmp        x5, x8
//   0x566c: fa5920a0  ccmp       x5, x25, #0, hs
//   0x5670: 54000062  b.hs       #0x567c
//   0x5674: 2a1f03e8  mov        w8, wzr
//   0x5678: 17fffff5  b          #0x564c
//   0x567c: a9451f86  ldp        x6, x7, [x28, #0x50]
//   0x5680: 910403e0  add        x0, sp, #0x100
//   0x5684: 52808001  mov        w1, #0x400
//   0x5688: f9401b84  ldr        x4, [x28, #0x30]
//   0x568c: 52808002  mov        w2, #0x400
//   0x5690: aa1603e3  mov        x3, x22
//   0x5694: 97fffd05  bl         #0x4aa8
//   0x5698: 51000408  sub        w8, w0, #1
//   0x569c: 710ff91f  cmp        w8, #0x3fe
//   0x56a0: 54fffd48  b.hi       #0x5648
//   0x56a4: 2a0003e2  mov        w2, w0
//   0x56a8: 910403e1  add        x1, sp, #0x100
//   0x56ac: 2a1403e0  mov        w0, w20
//   0x56b0: 940010b0  bl         #0x9970
//   0x56b4: 17ffffe5  b          #0x5648
//   0x56b8: f9401368  ldr        x8, [x27, #0x20]
//   0x56bc: f9401265  ldr        x5, [x19, #0x20]
//   0x56c0: 9ad50908  udiv       x8, x8, x21
//   0x56c4: eb0800bf  cmp        x5, x8
//   0x56c8: fa5920a0  ccmp       x5, x25, #0, hs
//   0x56cc: 54000062  b.hs       #0x56d8
//   0x56d0: 2a1f03fa  mov        w26, wzr
//   0x56d4: 17ffffcd  b          #0x5608
//   0x56d8: a9441e66  ldp        x6, x7, [x19, #0x40]
//   0x56dc: 910403e0  add        x0, sp, #0x100
//   0x56e0: 52808001  mov        w1, #0x400
//   0x56e4: a9429268  ldp        x8, x4, [x19, #0x28]
//   0x56e8: 52808002  mov        w2, #0x400
//   0x56ec: 90ffffe3  adrp       x3, #0x1000
//   0x56f0: 9133cc63  add        x3, x3, #0xcf3
//   0x56f4: f90003e8  str        x8, [sp]
//   0x56f8: 97fffcec  bl         #0x4aa8
//   0x56fc: 51000408  sub        w8, w0, #1
//   0x5700: 710ff91f  cmp        w8, #0x3fe
//   0x5704: 540000a8  b.hi       #0x5718
//   0x5708: 2a0003e2  mov        w2, w0
//   0x570c: 910403e1  add        x1, sp, #0x100
//   0x5710: 2a1403e0  mov        w0, w20
//   0x5714: 94001097  bl         #0x9970
//   0x5718: 5280003a  mov        w26, #1
//   0x571c: 17ffffbb  b          #0x5608
//   0x5720: f9404fe8  ldr        x8, [sp, #0x98]
//   0x5724: f9401365  ldr        x5, [x27, #0x20]
//   0x5728: f9401108  ldr        x8, [x8, #0x20]
//   0x572c: 9ad50908  udiv       x8, x8, x21
//   0x5730: eb0800bf  cmp        x5, x8
//   0x5734: fa5920a0  ccmp       x5, x25, #0, hs
//   0x5738: 54fff523  b.lo       #0x55dc
//   0x573c: a9449f66  ldp        x6, x7, [x27, #0x48]
//   0x5740: 910403e0  add        x0, sp, #0x100
//   0x5744: 52808001  mov        w1, #0x400
//   0x5748: a9429368  ldp        x8, x4, [x27, #0x28]
//   0x574c: 52808002  mov        w2, #0x400
//   0x5750: b0ffffe3  adrp       x3, #0x2000
//   0x5754: 9118e463  add        x3, x3, #0x639
//   0x5758: b9405b6b  ldr        w11, [x27, #0x58]
//   0x575c: a943ab69  ldp        x9, x10, [x27, #0x38]
//   0x5760: f90003e8  str        x8, [sp]
//   0x5764: b9001beb  str        w11, [sp, #0x18]
//   0x5768: a900abe9  stp        x9, x10, [sp, #8]
//   0x576c: 97fffccf  bl         #0x4aa8
//   0x5770: 51000408  sub        w8, w0, #1
//   0x5774: 710ff91f  cmp        w8, #0x3fe
//   0x5778: 540000a8  b.hi       #0x578c
//   0x577c: 2a0003e2  mov        w2, w0
//   0x5780: 910403e1  add        x1, sp, #0x100
//   0x5784: 2a1403e0  mov        w0, w20
//   0x5788: 9400107a  bl         #0x9970
//   0x578c: 52800028  mov        w8, #1
//   0x5790: b900b3e8  str        w8, [sp, #0xb0]
//   0x5794: 17ffff93  b          #0x55e0
//   0x5798: f9404fe8  ldr        x8, [sp, #0x98]
//   0x579c: 2a1f03e9  mov        w9, wzr
//   0x57a0: f9401105  ldr        x5, [x8, #0x20]
//   0x57a4: f94047e8  ldr        x8, [sp, #0x88]
//   0x57a8: eb0800bf  cmp        x5, x8
//   0x57ac: 540005a3  b.lo       #0x5860
//   0x57b0: 2a0903e8  mov        w8, w9
//   0x57b4: eb1900bf  cmp        x5, x25
//   0x57b8: 54ffef63  b.lo       #0x55a4
//   0x57bc: f9404fe9  ldr        x9, [sp, #0x98]
//   0x57c0: 910403e0  add        x0, sp, #0x100
//   0x57c4: 52808001  mov        w1, #0x400
//   0x57c8: 52808002  mov        w2, #0x400
//   0x57cc: b0ffffe3  adrp       x3, #0x2000
//   0x57d0: 91079463  add        x3, x3, #0x1e5
//   0x57d4: a9441d26  ldp        x6, x7, [x9, #0x40]
//   0x57d8: a9429128  ldp        x8, x4, [x9, #0x28]
//   0x57dc: f9401d29  ldr        x9, [x9, #0x38]
//   0x57e0: a90027e8  stp        x8, x9, [sp]
//   0x57e4: 97fffcb1  bl         #0x4aa8
//   0x57e8: 51000408  sub        w8, w0, #1
//   0x57ec: 710ff91f  cmp        w8, #0x3fe
//   0x57f0: 540000a8  b.hi       #0x5804
//   0x57f4: 2a0003e2  mov        w2, w0
//   0x57f8: 910403e1  add        x1, sp, #0x100
//   0x57fc: 2a1403e0  mov        w0, w20
//   0x5800: 9400105c  bl         #0x9970
//   0x5804: b94087e8  ldr        w8, [sp, #0x84]
//   0x5808: 7100051f  cmp        w8, #1
//   0x580c: 5400026b  b.lt       #0x5858
//   0x5810: f9404fe9  ldr        x9, [sp, #0x98]
//   0x5814: 910403e0  add        x0, sp, #0x100
//   0x5818: 52808001  mov        w1, #0x400
//   0x581c: 52808002  mov        w2, #0x400
//   0x5820: b0ffffe3  adrp       x3, #0x2000
//   0x5824: 91079463  add        x3, x3, #0x1e5
//   0x5828: a9441d26  ldp        x6, x7, [x9, #0x40]
//   0x582c: a9422125  ldp        x5, x8, [x9, #0x20]
//   0x5830: a9432524  ldp        x4, x9, [x9, #0x30]
//   0x5834: a90027e8  stp        x8, x9, [sp]
//   0x5838: 97fffc9c  bl         #0x4aa8
//   0x583c: 51000408  sub        w8, w0, #1
//   0x5840: 710ff91f  cmp        w8, #0x3fe
//   0x5844: 540000a8  b.hi       #0x5858
//   0x5848: 2a0003e2  mov        w2, w0
//   0x584c: 910403e1  add        x1, sp, #0x100
//   0x5850: b94087e0  ldr        w0, [sp, #0x84]
//   0x5854: 94001047  bl         #0x9970
//   0x5858: 52800028  mov        w8, #1
//   0x585c: 17ffff52  b          #0x55a4
//   0x5860: 2a0903e8  mov        w8, w9
//   0x5864: 17ffff50  b          #0x55a4
//   0x5868: 940007aa  bl         #0x7710
//   0x586c: 90000055  adrp       x21, #0xd000
//   0x5870: b0ffffe1  adrp       x1, #0x2000
//   0x5874: 910ae421  add        x1, x1, #0x2b9
//   0x5878: 52800582  mov        w2, #0x2c
//   0x587c: f946beb5  ldr        x21, [x21, #0xd78]
//   0x5880: f94002a8  ldr        x8, [x21]
//   0x5884: b941d914  ldr        w20, [x8, #0x1d8]
//   0x5888: 2a1403e0  mov        w0, w20
//   0x588c: 94001039  bl         #0x9970
//   0x5890: f94002a8  ldr        x8, [x21]
//   0x5894: 90ffffe3  adrp       x3, #0x1000
//   0x5898: 91327863  add        x3, x3, #0xc9e
//   0x589c: 910403e0  add        x0, sp, #0x100
//   0x58a0: 52800801  mov        w1, #0x40
//   0x58a4: 52800802  mov        w2, #0x40
//   0x58a8: f940a909  ldr        x9, [x8, #0x150]
//   0x58ac: f940b508  ldr        x8, [x8, #0x168]
//   0x58b0: cb080124  sub        x4, x9, x8
//   0x58b4: 97fffc7d  bl         #0x4aa8
//   0x58b8: 51000408  sub        w8, w0, #1
//   0x58bc: 7100f91f  cmp        w8, #0x3e
//   0x58c0: 540000a8  b.hi       #0x58d4
//   0x58c4: 2a0003e2  mov        w2, w0
//   0x58c8: 910403e1  add        x1, sp, #0x100
//   0x58cc: 2a1403e0  mov        w0, w20
//   0x58d0: 94001028  bl         #0x9970
//   0x58d4: f94002a8  ldr        x8, [x21]
//   0x58d8: 90ffffe3  adrp       x3, #0x1000
//   0x58dc: 912b0863  add        x3, x3, #0xac2
//   0x58e0: 910403e0  add        x0, sp, #0x100
//   0x58e4: 52800801  mov        w1, #0x40
//   0x58e8: 52800802  mov        w2, #0x40
//   0x58ec: f940ad04  ldr        x4, [x8, #0x158]
//   0x58f0: 97fffc6e  bl         #0x4aa8
//   0x58f4: 51000408  sub        w8, w0, #1
//   0x58f8: 7100f91f  cmp        w8, #0x3e
//   0x58fc: 540000a8  b.hi       #0x5910
//   0x5900: 2a0003e2  mov        w2, w0
//   0x5904: 910403e1  add        x1, sp, #0x100
//   0x5908: 2a1403e0  mov        w0, w20
//   0x590c: 94001019  bl         #0x9970
//   0x5910: f94002a8  ldr        x8, [x21]
//   0x5914: b0ffffe3  adrp       x3, #0x2000
//   0x5918: 91066c63  add        x3, x3, #0x19b
//   0x591c: 910403e0  add        x0, sp, #0x100
//   0x5920: 52800801  mov        w1, #0x40
//   0x5924: 52800802  mov        w2, #0x40
//   0x5928: f940b104  ldr        x4, [x8, #0x160]
//   0x592c: 97fffc5f  bl         #0x4aa8
//   0x5930: 51000408  sub        w8, w0, #1
//   0x5934: 7100f91f  cmp        w8, #0x3e
//   0x5938: 540000a8  b.hi       #0x594c
//   0x593c: 2a0003e2  mov        w2, w0
//   0x5940: 910403e1  add        x1, sp, #0x100
//   0x5944: 2a1403e0  mov        w0, w20
//   0x5948: 9400100a  bl         #0x9970
//   0x594c: f94002a8  ldr        x8, [x21]
//   0x5950: 90ffffe3  adrp       x3, #0x1000
//   0x5954: 913b2863  add        x3, x3, #0xeca
//   0x5958: 910403e0  add        x0, sp, #0x100
//   0x595c: 52800801  mov        w1, #0x40
//   0x5960: 52800802  mov        w2, #0x40
//   0x5964: a9572109  ldp        x9, x8, [x8, #0x170]
//   0x5968: cb080124  sub        x4, x9, x8
//   0x596c: 97fffc4f  bl         #0x4aa8
//   0x5970: 51000408  sub        w8, w0, #1
//   0x5974: 7100f91f  cmp        w8, #0x3e
//   0x5978: 540000a8  b.hi       #0x598c
//   0x597c: 2a0003e2  mov        w2, w0
//   0x5980: 910403e1  add        x1, sp, #0x100
//   0x5984: 2a1403e0  mov        w0, w20
//   0x5988: 94000ffa  bl         #0x9970
//   0x598c: f94002a8  ldr        x8, [x21]
//   0x5990: 90ffffe3  adrp       x3, #0x1000
//   0x5994: 9128a463  add        x3, x3, #0xa29
//   0x5998: 910403e0  add        x0, sp, #0x100
//   0x599c: 52800801  mov        w1, #0x40
//   0x59a0: 52800802  mov        w2, #0x40
//   0x59a4: f940a904  ldr        x4, [x8, #0x150]
//   0x59a8: 97fffc40  bl         #0x4aa8
//   0x59ac: 51000408  sub        w8, w0, #1
//   0x59b0: 7100f91f  cmp        w8, #0x3e
//   0x59b4: 540000a8  b.hi       #0x59c8
//   0x59b8: 2a0003e2  mov        w2, w0
//   0x59bc: 910403e1  add        x1, sp, #0x100
//   0x59c0: 2a1403e0  mov        w0, w20
//   0x59c4: 94000feb  bl         #0x9970
//   0x59c8: f94002a8  ldr        x8, [x21]
//   0x59cc: 90ffffe3  adrp       x3, #0x1000
//   0x59d0: 912c5c63  add        x3, x3, #0xb17
//   0x59d4: 910403e0  add        x0, sp, #0x100
//   0x59d8: 52800801  mov        w1, #0x40
//   0x59dc: 52800802  mov        w2, #0x40
//   0x59e0: f940b504  ldr        x4, [x8, #0x168]
//   0x59e4: 97fffc31  bl         #0x4aa8
//   0x59e8: 51000408  sub        w8, w0, #1
//   0x59ec: 7100f91f  cmp        w8, #0x3e
//   0x59f0: 540000a8  b.hi       #0x5a04
//   0x59f4: 2a0003e2  mov        w2, w0
//   0x59f8: 910403e1  add        x1, sp, #0x100
//   0x59fc: 2a1403e0  mov        w0, w20
//   0x5a00: 94000fdc  bl         #0x9970
//   0x5a04: f94002a8  ldr        x8, [x21]
//   0x5a08: 90ffffe3  adrp       x3, #0x1000
//   0x5a0c: 913ba463  add        x3, x3, #0xee9
//   0x5a10: 910403e0  add        x0, sp, #0x100
//   0x5a14: 52800801  mov        w1, #0x40
//   0x5a18: 52800802  mov        w2, #0x40
//   0x5a1c: f940b904  ldr        x4, [x8, #0x170]
//   0x5a20: 97fffc22  bl         #0x4aa8
//   0x5a24: 51000408  sub        w8, w0, #1
//   0x5a28: 7100f91f  cmp        w8, #0x3e
//   0x5a2c: 540000a8  b.hi       #0x5a40
//   0x5a30: 2a0003e2  mov        w2, w0
//   0x5a34: 910403e1  add        x1, sp, #0x100
//   0x5a38: 2a1403e0  mov        w0, w20
//   0x5a3c: 94000fcd  bl         #0x9970
//   0x5a40: f94002a8  ldr        x8, [x21]
//   0x5a44: 90ffffe3  adrp       x3, #0x1000
//   0x5a48: 912da463  add        x3, x3, #0xb69
//   0x5a4c: 910403e0  add        x0, sp, #0x100
//   0x5a50: 52800801  mov        w1, #0x40
//   0x5a54: 52800802  mov        w2, #0x40
//   0x5a58: f940bd04  ldr        x4, [x8, #0x178]
//   0x5a5c: 97fffc13  bl         #0x4aa8
//   0x5a60: 51000408  sub        w8, w0, #1
//   0x5a64: 7100f91f  cmp        w8, #0x3e
//   0x5a68: 540000a8  b.hi       #0x5a7c
//   0x5a6c: 2a0003e2  mov        w2, w0
//   0x5a70: 910403e1  add        x1, sp, #0x100
//   0x5a74: 2a1403e0  mov        w0, w20
//   0x5a78: 94000fbe  bl         #0x9970
//   0x5a7c: f94002a8  ldr        x8, [x21]
//   0x5a80: 90ffffe3  adrp       x3, #0x1000
//   0x5a84: 913cf863  add        x3, x3, #0xf3e
//   0x5a88: 910403e0  add        x0, sp, #0x100
//   0x5a8c: 52800801  mov        w1, #0x40
//   0x5a90: 52800802  mov        w2, #0x40
//   0x5a94: f940c104  ldr        x4, [x8, #0x180]
//   0x5a98: 97fffc04  bl         #0x4aa8
//   0x5a9c: 51000408  sub        w8, w0, #1
//   0x5aa0: 7100f91f  cmp        w8, #0x3e
//   0x5aa4: 540000a8  b.hi       #0x5ab8
//   0x5aa8: 2a0003e2  mov        w2, w0
//   0x5aac: 910403e1  add        x1, sp, #0x100
//   0x5ab0: 2a1403e0  mov        w0, w20
//   0x5ab4: 94000faf  bl         #0x9970
//   0x5ab8: f94002a8  ldr        x8, [x21]
//   0x5abc: b0ffffe3  adrp       x3, #0x2000
//   0x5ac0: 91162863  add        x3, x3, #0x58a
//   0x5ac4: 910403e0  add        x0, sp, #0x100
//   0x5ac8: 52800801  mov        w1, #0x40
//   0x5acc: 52800802  mov        w2, #0x40
//   0x5ad0: f940c504  ldr        x4, [x8, #0x188]
//   0x5ad4: 97fffbf5  bl         #0x4aa8
//   0x5ad8: 51000408  sub        w8, w0, #1
//   0x5adc: 7100f91f  cmp        w8, #0x3e
//   0x5ae0: 540000a8  b.hi       #0x5af4
//   0x5ae4: 2a0003e2  mov        w2, w0
//   0x5ae8: 910403e1  add        x1, sp, #0x100
//   0x5aec: 2a1403e0  mov        w0, w20
//   0x5af0: 94000fa0  bl         #0x9970
//   0x5af4: b94077e8  ldr        w8, [sp, #0x74]
//   0x5af8: 7100051f  cmp        w8, #1
//   0x5afc: 54000441  b.ne       #0x5b84
//   0x5b00: 940006e1  bl         #0x7684
//   0x5b04: b4001f00  cbz        x0, #0x5ee4
//   0x5b08: aa0003e4  mov        x4, x0
//   0x5b0c: b0ffffe3  adrp       x3, #0x2000
//   0x5b10: 91087863  add        x3, x3, #0x21e
//   0x5b14: 910403e0  add        x0, sp, #0x100
//   0x5b18: 52808001  mov        w1, #0x400
//   0x5b1c: 52808002  mov        w2, #0x400
//   0x5b20: 97fffbe2  bl         #0x4aa8
//   0x5b24: 52800841  mov        w1, #0x42
//   0x5b28: 910403e0  add        x0, sp, #0x100
//   0x5b2c: 72a00101  movk       w1, #8, lsl #16
//   0x5b30: 52803002  mov        w2, #0x180
//   0x5b34: 94000f83  bl         #0x9940
//   0x5b38: 37f81d60  tbnz       w0, #0x1f, #0x5ee4
//   0x5b3c: f94002a8  ldr        x8, [x21]
//   0x5b40: 2a0003f3  mov        w19, w0
//   0x5b44: b9412914  ldr        w20, [x8, #0x128]
//   0x5b48: b901dd00  str        w0, [x8, #0x1dc]
//   0x5b4c: 94000f79  bl         #0x9930
//   0x5b50: 2a0003f5  mov        w21, w0
//   0x5b54: 3100041f  cmn        w0, #1
//   0x5b58: 540005a0  b.eq       #0x5c0c
//   0x5b5c: 90ffffe3  adrp       x3, #0x1000
//   0x5b60: 91277c63  add        x3, x3, #0x9df
//   0x5b64: 910403e0  add        x0, sp, #0x100
//   0x5b68: 52802001  mov        w1, #0x100
//   0x5b6c: 52802002  mov        w2, #0x100
//   0x5b70: 2a1503e4  mov        w4, w21
//   0x5b74: 97fffbcd  bl         #0x4aa8
//   0x5b78: 1400002c  b          #0x5c28
//   0x5b7c: 12800160  mov        w0, #-0xc
//   0x5b80: 1400016f  b          #0x613c
//   0x5b84: f94002a8  ldr        x8, [x21]
//   0x5b88: 52800849  mov        w9, #0x42
//   0x5b8c: 72a00109  movk       w9, #8, lsl #16
//   0x5b90: 90ffffe1  adrp       x1, #0x1000
//   0x5b94: 91349421  add        x1, x1, #0xd25
//   0x5b98: 32170122  orr        w2, w9, #0x200
//   0x5b9c: b941e500  ldr        w0, [x8, #0x1e4]
//   0x5ba0: 52803003  mov        w3, #0x180
//   0x5ba4: 94000f53  bl         #0x98f0
//   0x5ba8: 37f81c40  tbnz       w0, #0x1f, #0x5f30
//   0x5bac: f94002a8  ldr        x8, [x21]
//   0x5bb0: 2a0003f3  mov        w19, w0
//   0x5bb4: 90ffffe3  adrp       x3, #0x1000
//   0x5bb8: 9134d863  add        x3, x3, #0xd36
//   0x5bbc: 910403e0  add        x0, sp, #0x100
//   0x5bc0: 52802001  mov        w1, #0x100
//   0x5bc4: a950a504  ldp        x4, x9, [x8, #0x108]
//   0x5bc8: 52802002  mov        w2, #0x100
//   0x5bcc: a951ad0a  ldp        x10, x11, [x8, #0x118]
//   0x5bd0: a954350c  ldp        x12, x13, [x8, #0x140]
//   0x5bd4: d354fd25  lsr        x5, x9, #0x14
//   0x5bd8: a9532107  ldp        x7, x8, [x8, #0x130]
//   0x5bdc: 8b0a016a  add        x10, x11, x10
//   0x5be0: d354fd46  lsr        x6, x10, #0x14
//   0x5be4: 8b0c01a9  add        x9, x13, x12
//   0x5be8: d354fd29  lsr        x9, x9, #0x14
//   0x5bec: d354fd08  lsr        x8, x8, #0x14
//   0x5bf0: a90027e8  stp        x8, x9, [sp]
//   0x5bf4: 97fffbad  bl         #0x4aa8
//   0x5bf8: 93407c02  sxtw       x2, w0
//   0x5bfc: 910403e1  add        x1, sp, #0x100
//   0x5c00: 2a1303e0  mov        w0, w19
//   0x5c04: 94000f5b  bl         #0x9970
//   0x5c08: 140000ca  b          #0x5f30
//   0x5c0c: 90ffffe1  adrp       x1, #0x1000
//   0x5c10: 91333021  add        x1, x1, #0xccc
//   0x5c14: 910403e0  add        x0, sp, #0x100
//   0x5c18: 52802002  mov        w2, #0x100
//   0x5c1c: 52802003  mov        w3, #0x100
//   0x5c20: 52800264  mov        w4, #0x13
//   0x5c24: 94000f6f  bl         #0x99e0
//   0x5c28: 910403e0  add        x0, sp, #0x100
//   0x5c2c: 52a00101  mov        w1, #0x80000
//   0x5c30: 94000f48  bl         #0x9950
//   0x5c34: 37f801c0  tbnz       w0, #0x1f, #0x5c6c
//   0x5c38: 910403e1  add        x1, sp, #0x100
//   0x5c3c: 52802002  mov        w2, #0x100
//   0x5c40: 2a0003f7  mov        w23, w0
//   0x5c44: 94000f47  bl         #0x9960
//   0x5c48: aa0003f6  mov        x22, x0
//   0x5c4c: 2a1703e0  mov        w0, w23
//   0x5c50: 94000f2c  bl         #0x9900
//   0x5c54: f10006c8  subs       x8, x22, #1
//   0x5c58: 540000ab  b.lt       #0x5c6c
//   0x5c5c: f10402df  cmp        x22, #0x100
//   0x5c60: 540000a1  b.ne       #0x5c74
//   0x5c64: 52801fe8  mov        w8, #0xff
//   0x5c68: 14000007  b          #0x5c84
//   0x5c6c: aa1f03f6  mov        x22, xzr
//   0x5c70: 1400000b  b          #0x5c9c
//   0x5c74: 910403e9  add        x9, sp, #0x100
//   0x5c78: 38686929  ldrb       w9, [x9, x8]
//   0x5c7c: 7100293f  cmp        w9, #0xa
//   0x5c80: 54000041  b.ne       #0x5c88
//   0x5c84: aa0803f6  mov        x22, x8
//   0x5c88: 910403e0  add        x0, sp, #0x100
//   0x5c8c: 910403e8  add        x8, sp, #0x100
//   0x5c90: 3836691f  strb       wzr, [x8, x22]
//   0x5c94: 94000eab  bl         #0x9740
//   0x5c98: aa0003f6  mov        x22, x0
//   0x5c9c: 90000048  adrp       x8, #0xd000
//   0x5ca0: 90ffffe3  adrp       x3, #0x1000
//   0x5ca4: 9129dc63  add        x3, x3, #0xa77
//   0x5ca8: 910403e0  add        x0, sp, #0x100
//   0x5cac: 52808001  mov        w1, #0x400
//   0x5cb0: 52807fe2  mov        w2, #0x3ff
//   0x5cb4: f946bd08  ldr        x8, [x8, #0xd78]
//   0x5cb8: 2a1503e4  mov        w4, w21
//   0x5cbc: 2a1403e5  mov        w5, w20
//   0x5cc0: aa1603e7  mov        x7, x22
//   0x5cc4: f9400108  ldr        x8, [x8]
//   0x5cc8: f9409906  ldr        x6, [x8, #0x130]
//   0x5ccc: 97fffb77  bl         #0x4aa8
//   0x5cd0: 2a0003f4  mov        w20, w0
//   0x5cd4: b4000076  cbz        x22, #0x5ce0
//   0x5cd8: aa1603e0  mov        x0, x22
//   0x5cdc: 94000ef1  bl         #0x98a0
//   0x5ce0: 7100069f  cmp        w20, #1
//   0x5ce4: 540000ab  b.lt       #0x5cf8
//   0x5ce8: 2a1403e2  mov        w2, w20
//   0x5cec: 910403e1  add        x1, sp, #0x100
//   0x5cf0: 2a1303e0  mov        w0, w19
//   0x5cf4: 94000f1f  bl         #0x9970
//   0x5cf8: 90000048  adrp       x8, #0xd000
//   0x5cfc: f946bd08  ldr        x8, [x8, #0xd78]
//   0x5d00: f9400109  ldr        x9, [x8]
//   0x5d04: a950a124  ldp        x4, x8, [x9, #0x108]
//   0x5d08: a951ad2a  ldp        x10, x11, [x9, #0x118]
//   0x5d0c: a953312d  ldp        x13, x12, [x9, #0x130]
//   0x5d10: d354fd15  lsr        x21, x8, #0x14
//   0x5d14: d354fd56  lsr        x22, x10, #0x14
//   0x5d18: b941293a  ldr        w26, [x9, #0x128]
//   0x5d1c: a9542928  ldp        x8, x10, [x9, #0x140]
//   0x5d20: d354fd77  lsr        x23, x11, #0x14
//   0x5d24: d354fd8b  lsr        x11, x12, #0x14
//   0x5d28: d354fd1b  lsr        x27, x8, #0x14
//   0x5d2c: f9405d28  ldr        x8, [x9, #0xb8]
//   0x5d30: d354fd5c  lsr        x28, x10, #0x14
//   0x5d34: b40004c8  cbz        x8, #0x5dcc
//   0x5d38: a945a518  ldp        x24, x9, [x8, #0x58]
//   0x5d3c: a944e514  ldp        x20, x25, [x8, #0x48]
//   0x5d40: b4000529  cbz        x9, #0x5de4
//   0x5d44: 91004120  add        x0, x9, #0x10
//   0x5d48: 910323e1  add        x1, sp, #0xc8
//   0x5d4c: a909b7eb  stp        x11, x13, [sp, #0x98]
//   0x5d50: f9005be4  str        x4, [sp, #0xb0]
//   0x5d54: 94000f0f  bl         #0x9990
//   0x5d58: b4000420  cbz        x0, #0x5ddc
//   0x5d5c: 295b23e9  ldp        w9, w8, [sp, #0xd8]
//   0x5d60: 295a2beb  ldp        w11, w10, [sp, #0xd0]
//   0x5d64: 295933ed  ldp        w13, w12, [sp, #0xc8]
//   0x5d68: f9405be4  ldr        x4, [sp, #0xb0]
//   0x5d6c: 90ffffe3  adrp       x3, #0x1000
//   0x5d70: 91376063  add        x3, x3, #0xdd8
//   0x5d74: 111db108  add        w8, w8, #0x76c
//   0x5d78: 11000529  add        w9, w9, #1
//   0x5d7c: b9005beb  str        w11, [sp, #0x58]
//   0x5d80: b9006bed  str        w13, [sp, #0x68]
//   0x5d84: 910403e0  add        x0, sp, #0x100
//   0x5d88: b90043e8  str        w8, [sp, #0x40]
//   0x5d8c: f9404fe8  ldr        x8, [sp, #0x98]
//   0x5d90: b90063ec  str        w12, [sp, #0x60]
//   0x5d94: 52808001  mov        w1, #0x400
//   0x5d98: b90053ea  str        w10, [sp, #0x50]
//   0x5d9c: 52807fe2  mov        w2, #0x3ff
//   0x5da0: a9016fe8  stp        x8, x27, [sp, #0x10]
//   0x5da4: f94053e8  ldr        x8, [sp, #0xa0]
//   0x5da8: b9004be9  str        w9, [sp, #0x48]
//   0x5dac: aa1503e5  mov        x5, x21
//   0x5db0: a90363f9  stp        x25, x24, [sp, #0x30]
//   0x5db4: aa1603e6  mov        x6, x22
//   0x5db8: a90253fc  stp        x28, x20, [sp, #0x20]
//   0x5dbc: aa1703e7  mov        x7, x23
//   0x5dc0: b9000bfa  str        w26, [sp, #8]
//   0x5dc4: f90003e8  str        x8, [sp]
//   0x5dc8: 14000014  b          #0x5e18
//   0x5dcc: aa1f03f8  mov        x24, xzr
//   0x5dd0: aa1f03f9  mov        x25, xzr
//   0x5dd4: aa1f03f4  mov        x20, xzr
//   0x5dd8: 14000003  b          #0x5de4
//   0x5ddc: a949b7eb  ldp        x11, x13, [sp, #0x98]
//   0x5de0: f9405be4  ldr        x4, [sp, #0xb0]
//   0x5de4: b0ffffe3  adrp       x3, #0x2000
//   0x5de8: 9116a463  add        x3, x3, #0x5a9
//   0x5dec: 910403e0  add        x0, sp, #0x100
//   0x5df0: 52808001  mov        w1, #0x400
//   0x5df4: 52807fe2  mov        w2, #0x3ff
//   0x5df8: aa1503e5  mov        x5, x21
//   0x5dfc: aa1603e6  mov        x6, x22
//   0x5e00: aa1703e7  mov        x7, x23
//   0x5e04: a90363f9  stp        x25, x24, [sp, #0x30]
//   0x5e08: a90253fc  stp        x28, x20, [sp, #0x20]
//   0x5e0c: a9016feb  stp        x11, x27, [sp, #0x10]
//   0x5e10: b9000bfa  str        w26, [sp, #8]
//   0x5e14: f90003ed  str        x13, [sp]
//   0x5e18: 97fffb24  bl         #0x4aa8
//   0x5e1c: 90000055  adrp       x21, #0xd000
//   0x5e20: 7100041f  cmp        w0, #1
//   0x5e24: f946beb5  ldr        x21, [x21, #0xd78]
//   0x5e28: 540000ab  b.lt       #0x5e3c
//   0x5e2c: 2a0003e2  mov        w2, w0
//   0x5e30: 910403e1  add        x1, sp, #0x100
//   0x5e34: 2a1303e0  mov        w0, w19
//   0x5e38: 94000ece  bl         #0x9970
//   0x5e3c: 90ffffe1  adrp       x1, #0x1000
//   0x5e40: 912b7c21  add        x1, x1, #0xadf
//   0x5e44: 2a1303e0  mov        w0, w19
//   0x5e48: 52800162  mov        w2, #0xb
//   0x5e4c: 94000ec9  bl         #0x9970
//   0x5e50: f94002a8  ldr        x8, [x21]
//   0x5e54: f9405d01  ldr        x1, [x8, #0xb8]
//   0x5e58: b4000461  cbz        x1, #0x5ee4
//   0x5e5c: f9403028  ldr        x8, [x1, #0x60]
//   0x5e60: b4000108  cbz        x8, #0x5e80
//   0x5e64: f9400508  ldr        x8, [x8, #8]
//   0x5e68: b40000c8  cbz        x8, #0x5e80
//   0x5e6c: 2a1303e0  mov        w0, w19
//   0x5e70: 2a1f03e2  mov        w2, wzr
//   0x5e74: 94000ab4  bl         #0x8944
//   0x5e78: f94002a8  ldr        x8, [x21]
//   0x5e7c: 14000007  b          #0x5e98
//   0x5e80: 2a1303e0  mov        w0, w19
//   0x5e84: 94000bbd  bl         #0x8d78
//   0x5e88: f94002a8  ldr        x8, [x21]
//   0x5e8c: b941e909  ldr        w9, [x8, #0x1e8]
//   0x5e90: 11000529  add        w9, w9, #1
//   0x5e94: b901e909  str        w9, [x8, #0x1e8]
//   0x5e98: 52801814  mov        w20, #0xc0
//   0x5e9c: 14000007  b          #0x5eb8
//   0x5ea0: b941e909  ldr        w9, [x8, #0x1e8]
//   0x5ea4: 11000529  add        w9, w9, #1
//   0x5ea8: b901e909  str        w9, [x8, #0x1e8]
//   0x5eac: 91002294  add        x20, x20, #8
//   0x5eb0: f104229f  cmp        x20, #0x108
//   0x5eb4: 54000180  b.eq       #0x5ee4
//   0x5eb8: f8746901  ldr        x1, [x8, x20]
//   0x5ebc: b4000141  cbz        x1, #0x5ee4
//   0x5ec0: f9403029  ldr        x9, [x1, #0x60]
//   0x5ec4: b4fffee9  cbz        x9, #0x5ea0
//   0x5ec8: f9400529  ldr        x9, [x9, #8]
//   0x5ecc: b4fffea9  cbz        x9, #0x5ea0
//   0x5ed0: 2a1303e0  mov        w0, w19
//   0x5ed4: 52800022  mov        w2, #1
//   0x5ed8: 94000a9b  bl         #0x8944
//   0x5edc: f94002a8  ldr        x8, [x21]
//   0x5ee0: 17fffff3  b          #0x5eac
//   0x5ee4: 910323e0  add        x0, sp, #0xc8
//   0x5ee8: 94000e7e  bl         #0x98e0
//   0x5eec: 940005b1  bl         #0x75b0
//   0x5ef0: 7100041f  cmp        w0, #1
//   0x5ef4: 540001eb  b.lt       #0x5f30
//   0x5ef8: 2a0003f3  mov        w19, w0
//   0x5efc: f94067e4  ldr        x4, [sp, #0xc8]
//   0x5f00: 90ffffe3  adrp       x3, #0x1000
//   0x5f04: 912cd863  add        x3, x3, #0xb36
//   0x5f08: 910403e0  add        x0, sp, #0x100
//   0x5f0c: 52800801  mov        w1, #0x40
//   0x5f10: 52800802  mov        w2, #0x40
//   0x5f14: 97fffae5  bl         #0x4aa8
//   0x5f18: 93407c02  sxtw       x2, w0
//   0x5f1c: 910403e1  add        x1, sp, #0x100
//   0x5f20: 2a1303e0  mov        w0, w19
//   0x5f24: 94000e93  bl         #0x9970
//   0x5f28: 2a1303e0  mov        w0, w19
//   0x5f2c: 94000e75  bl         #0x9900
//   0x5f30: f9405ff3  ldr        x19, [sp, #0xb8]
//   0x5f34: 9102e3f6  add        x22, sp, #0xb8
//   0x5f38: eb16027f  cmp        x19, x22
//   0x5f3c: 54001321  b.ne       #0x61a0
//   0x5f40: 9400077c  bl         #0x7d30
//   0x5f44: 9400049f  bl         #0x71c0
//   0x5f48: 90000054  adrp       x20, #0xd000
//   0x5f4c: f946be94  ldr        x20, [x20, #0xd78]
//   0x5f50: f9400288  ldr        x8, [x20]
//   0x5f54: b4000f08  cbz        x8, #0x6134
//   0x5f58: b941d913  ldr        w19, [x8, #0x1d8]
//   0x5f5c: 37f80ed3  tbnz       w19, #0x1f, #0x6134
//   0x5f60: 90ffffe1  adrp       x1, #0x1000
//   0x5f64: 912e2021  add        x1, x1, #0xb88
//   0x5f68: 2a1303e0  mov        w0, w19
//   0x5f6c: 52800542  mov        w2, #0x2a
//   0x5f70: 94000e80  bl         #0x9970
//   0x5f74: f9400288  ldr        x8, [x20]
//   0x5f78: 910323e1  add        x1, sp, #0xc8
//   0x5f7c: 9106c100  add        x0, x8, #0x1b0
//   0x5f80: 94000e84  bl         #0x9990
//   0x5f84: b4000300  cbz        x0, #0x5fe4
//   0x5f88: 295b23e9  ldp        w9, w8, [sp, #0xd8]
//   0x5f8c: 295a1fea  ldp        w10, w7, [sp, #0xd0]
//   0x5f90: b0ffffe3  adrp       x3, #0x2000
//   0x5f94: 91133863  add        x3, x3, #0x4ce
//   0x5f98: b0ffffe4  adrp       x4, #0x2000
//   0x5f9c: 91034c84  add        x4, x4, #0xd3
//   0x5fa0: 111db105  add        w5, w8, #0x76c
//   0x5fa4: 11000526  add        w6, w9, #1
//   0x5fa8: 295923e9  ldp        w9, w8, [sp, #0xc8]
//   0x5fac: 910403e0  add        x0, sp, #0x100
//   0x5fb0: 52801001  mov        w1, #0x80
//   0x5fb4: 52801002  mov        w2, #0x80
//   0x5fb8: b90003ea  str        w10, [sp]
//   0x5fbc: b90013e9  str        w9, [sp, #0x10]
//   0x5fc0: b9000be8  str        w8, [sp, #8]
//   0x5fc4: 97fffab9  bl         #0x4aa8
//   0x5fc8: 51000408  sub        w8, w0, #1
//   0x5fcc: 7101f91f  cmp        w8, #0x7e
//   0x5fd0: 540000a8  b.hi       #0x5fe4
//   0x5fd4: 2a0003e2  mov        w2, w0
//   0x5fd8: 910403e1  add        x1, sp, #0x100
//   0x5fdc: 2a1303e0  mov        w0, w19
//   0x5fe0: 94000e64  bl         #0x9970
//   0x5fe4: f9400288  ldr        x8, [x20]
//   0x5fe8: 910323e1  add        x1, sp, #0xc8
//   0x5fec: 9106e100  add        x0, x8, #0x1b8
//   0x5ff0: 94000e68  bl         #0x9990
//   0x5ff4: b4000300  cbz        x0, #0x6054
//   0x5ff8: 295b23e9  ldp        w9, w8, [sp, #0xd8]
//   0x5ffc: 295a1fea  ldp        w10, w7, [sp, #0xd0]
//   0x6000: 90ffffe3  adrp       x3, #0x2000
//   0x6004: 91133863  add        x3, x3, #0x4ce
//   0x6008: f0ffffc4  adrp       x4, #0x1000
//   0x600c: 91397484  add        x4, x4, #0xe5d
//   0x6010: 111db105  add        w5, w8, #0x76c
//   0x6014: 11000526  add        w6, w9, #1
//   0x6018: 295923e9  ldp        w9, w8, [sp, #0xc8]
//   0x601c: 910403e0  add        x0, sp, #0x100
//   0x6020: 52801001  mov        w1, #0x80
//   0x6024: 52801002  mov        w2, #0x80
//   0x6028: b90003ea  str        w10, [sp]
//   0x602c: b90013e9  str        w9, [sp, #0x10]
//   0x6030: b9000be8  str        w8, [sp, #8]
//   0x6034: 97fffa9d  bl         #0x4aa8
//   0x6038: 51000408  sub        w8, w0, #1
//   0x603c: 7101f91f  cmp        w8, #0x7e
//   0x6040: 540000a8  b.hi       #0x6054
//   0x6044: 2a0003e2  mov        w2, w0
//   0x6048: 910403e1  add        x1, sp, #0x100
//   0x604c: 2a1303e0  mov        w0, w19
//   0x6050: 94000e48  bl         #0x9970
//   0x6054: f9400288  ldr        x8, [x20]
//   0x6058: 910323e1  add        x1, sp, #0xc8
//   0x605c: 91070100  add        x0, x8, #0x1c0
//   0x6060: 94000e4c  bl         #0x9990
//   0x6064: b4000300  cbz        x0, #0x60c4
//   0x6068: 295b23e9  ldp        w9, w8, [sp, #0xd8]
//   0x606c: 295a1fea  ldp        w10, w7, [sp, #0xd0]
//   0x6070: 90ffffe3  adrp       x3, #0x2000
//   0x6074: 91133863  add        x3, x3, #0x4ce
//   0x6078: 90ffffe4  adrp       x4, #0x2000
//   0x607c: 910b9884  add        x4, x4, #0x2e6
//   0x6080: 111db105  add        w5, w8, #0x76c
//   0x6084: 11000526  add        w6, w9, #1
//   0x6088: 295923e9  ldp        w9, w8, [sp, #0xc8]
//   0x608c: 910403e0  add        x0, sp, #0x100
//   0x6090: 52801001  mov        w1, #0x80
//   0x6094: 52801002  mov        w2, #0x80
//   0x6098: b90003ea  str        w10, [sp]
//   0x609c: b90013e9  str        w9, [sp, #0x10]
//   0x60a0: b9000be8  str        w8, [sp, #8]
//   0x60a4: 97fffa81  bl         #0x4aa8
//   0x60a8: 51000408  sub        w8, w0, #1
//   0x60ac: 7101f91f  cmp        w8, #0x7e
//   0x60b0: 540000a8  b.hi       #0x60c4
//   0x60b4: 2a0003e2  mov        w2, w0
//   0x60b8: 910403e1  add        x1, sp, #0x100
//   0x60bc: 2a1303e0  mov        w0, w19
//   0x60c0: 94000e2c  bl         #0x9970
//   0x60c4: f9400288  ldr        x8, [x20]
//   0x60c8: 910323e1  add        x1, sp, #0xc8
//   0x60cc: 91072100  add        x0, x8, #0x1c8
//   0x60d0: 94000e30  bl         #0x9990
//   0x60d4: b4000300  cbz        x0, #0x6134
//   0x60d8: 295b23e9  ldp        w9, w8, [sp, #0xd8]
//   0x60dc: 295a1fea  ldp        w10, w7, [sp, #0xd0]
//   0x60e0: 90ffffe3  adrp       x3, #0x2000
//   0x60e4: 91133863  add        x3, x3, #0x4ce
//   0x60e8: f0ffffc4  adrp       x4, #0x1000
//   0x60ec: 913d7484  add        x4, x4, #0xf5d
//   0x60f0: 111db105  add        w5, w8, #0x76c
//   0x60f4: 11000526  add        w6, w9, #1
//   0x60f8: 295923e9  ldp        w9, w8, [sp, #0xc8]
//   0x60fc: 910403e0  add        x0, sp, #0x100
//   0x6100: 52801001  mov        w1, #0x80
//   0x6104: 52801002  mov        w2, #0x80
//   0x6108: b90003ea  str        w10, [sp]
//   0x610c: b90013e9  str        w9, [sp, #0x10]
//   0x6110: b9000be8  str        w8, [sp, #8]
//   0x6114: 97fffa65  bl         #0x4aa8
//   0x6118: 51000408  sub        w8, w0, #1
//   0x611c: 7101f91f  cmp        w8, #0x7e
//   0x6120: 540000a8  b.hi       #0x6134
//   0x6124: 2a0003e2  mov        w2, w0
//   0x6128: 910403e1  add        x1, sp, #0x100
//   0x612c: 2a1303e0  mov        w0, w19
//   0x6130: 94000e10  bl         #0x9970
//   0x6134: 2a1f03e0  mov        w0, wzr
//   0x6138: f9403fe9  ldr        x9, [sp, #0x78]
//   0x613c: f9401528  ldr        x8, [x9, #0x28]
//   0x6140: f85f03a9  ldur       x9, [x29, #-0x10]
//   0x6144: eb09011f  cmp        x8, x9
//   0x6148: 54000921  b.ne       #0x626c
//   0x614c: 911443ff  add        sp, sp, #0x510
//   0x6150: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x6154: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x6158: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x615c: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x6160: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x6164: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x6168: d65f03c0  ret        
//   0x616c: a9402269  ldp        x9, x8, [x19]
//   0x6170: aa1303e0  mov        x0, x19
//   0x6174: f9000528  str        x8, [x9, #8]
//   0x6178: f9400668  ldr        x8, [x19, #8]
//   0x617c: f9000109  str        x9, [x8]
//   0x6180: f0000028  adrp       x8, #0xd000
//   0x6184: f946b508  ldr        x8, [x8, #0xd68]
//   0x6188: f9400108  ldr        x8, [x8]
//   0x618c: f9400508  ldr        x8, [x8, #8]
//   0x6190: d63f0100  blr        x8
//   0x6194: aa1703f3  mov        x19, x23
//   0x6198: eb1602ff  cmp        x23, x22
//   0x619c: 54ffed20  b.eq       #0x5f40
//   0x61a0: aa1303f8  mov        x24, x19
//   0x61a4: f9400277  ldr        x23, [x19]
//   0x61a8: f8410f14  ldr        x20, [x24, #0x10]!
//   0x61ac: eb18029f  cmp        x20, x24
//   0x61b0: 54000241  b.ne       #0x61f8
//   0x61b4: f9401e60  ldr        x0, [x19, #0x38]
//   0x61b8: b4fffda0  cbz        x0, #0x616c
//   0x61bc: 94000db9  bl         #0x98a0
//   0x61c0: 17ffffeb  b          #0x616c
//   0x61c4: a9402289  ldp        x9, x8, [x20]
//   0x61c8: aa1403e0  mov        x0, x20
//   0x61cc: f9000528  str        x8, [x9, #8]
//   0x61d0: f9400688  ldr        x8, [x20, #8]
//   0x61d4: f9000109  str        x9, [x8]
//   0x61d8: f0000028  adrp       x8, #0xd000
//   0x61dc: f946b508  ldr        x8, [x8, #0xd68]
//   0x61e0: f9400108  ldr        x8, [x8]
//   0x61e4: f9400508  ldr        x8, [x8, #8]
//   0x61e8: d63f0100  blr        x8
//   0x61ec: aa1903f4  mov        x20, x25
//   0x61f0: eb18033f  cmp        x25, x24
//   0x61f4: 54fffe00  b.eq       #0x61b4
//   0x61f8: aa1403fa  mov        x26, x20
//   0x61fc: f9400299  ldr        x25, [x20]
//   0x6200: f8410f55  ldr        x21, [x26, #0x10]!
//   0x6204: eb1a02bf  cmp        x21, x26
//   0x6208: 54000241  b.ne       #0x6250
//   0x620c: f9401e80  ldr        x0, [x20, #0x38]
//   0x6210: b4fffda0  cbz        x0, #0x61c4
//   0x6214: 94000da3  bl         #0x98a0
//   0x6218: 17ffffeb  b          #0x61c4
//   0x621c: f94006a9  ldr        x9, [x21, #8]
//   0x6220: aa1503e0  mov        x0, x21
//   0x6224: f9000509  str        x9, [x8, #8]
//   0x6228: f94006a9  ldr        x9, [x21, #8]
//   0x622c: f9000128  str        x8, [x9]
//   0x6230: f0000028  adrp       x8, #0xd000
//   0x6234: f946b508  ldr        x8, [x8, #0xd68]
//   0x6238: f9400108  ldr        x8, [x8]
//   0x623c: f9400508  ldr        x8, [x8, #8]
//   0x6240: d63f0100  blr        x8
//   0x6244: aa1b03f5  mov        x21, x27
//   0x6248: eb1a037f  cmp        x27, x26
//   0x624c: 54fffe00  b.eq       #0x620c
//   0x6250: f94002bb  ldr        x27, [x21]
//   0x6254: f9401ea0  ldr        x0, [x21, #0x38]
//   0x6258: aa1b03e8  mov        x8, x27
//   0x625c: b4fffe00  cbz        x0, #0x621c
//   0x6260: 94000d90  bl         #0x98a0
//   0x6264: f94002a8  ldr        x8, [x21]
//   0x6268: 17ffffed  b          #0x621c
//   0x626c: 94000d7d  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[29] HeapTrackerHookMalloc_6270 (0x6270..0x63b0, 320 bytes, 80 instructions)
// Summary / Tóm tắt: Hooked malloc with xpaclri (0xd50320ff @ 0x6290) LR stripping (@ 0x6270..0x63b0)
// ----------------------------------------------------------------------------
//   0x6270: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6274: f9000bf7  str        x23, [sp, #0x10]
//   0x6278: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x627c: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6280: 910003fd  mov        x29, sp
//   0x6284: f0000036  adrp       x22, #0xd000
//   0x6288: aa0003f3  mov        x19, x0
//   0x628c: f946bed6  ldr        x22, [x22, #0xd78]
//   0x6290: d50320ff  xpaclri    
//   0x6294: f94002c8  ldr        x8, [x22]
//   0x6298: b941f108  ldr        w8, [x8, #0x1f0]
//   0x629c: 51000508  sub        w8, w8, #1
//   0x62a0: 7100111f  cmp        w8, #4
//   0x62a4: 54000188  b.hi       #0x62d4
//   0x62a8: d503201f  nop        
//   0x62ac: 50fe2149  adr        x9, #0x26d6
//   0x62b0: aa1e03f4  mov        x20, x30
//   0x62b4: 1000008a  adr        x10, #0x62c4
//   0x62b8: 3868692b  ldrb       w11, [x9, x8]
//   0x62bc: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x62c0: d61f0140  br         x10
//   0x62c4: aa1403e0  mov        x0, x20
//   0x62c8: aa1d03e1  mov        x1, x29
//   0x62cc: aa1303e2  mov        x2, x19
//   0x62d0: 940001d8  bl         #0x6a30
//   0x62d4: d503201f  nop        
//   0x62d8: 1005ed08  adr        x8, #0x12078
//   0x62dc: f9400108  ldr        x8, [x8]
//   0x62e0: f9400d01  ldr        x1, [x8, #0x18]
//   0x62e4: aa1303e0  mov        x0, x19
//   0x62e8: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x62ec: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x62f0: f9400bf7  ldr        x23, [sp, #0x10]
//   0x62f4: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x62f8: d61f0020  br         x1
//   0x62fc: f0000028  adrp       x8, #0xd000
//   0x6300: aa1303e0  mov        x0, x19
//   0x6304: 528acf17  mov        w23, #0x5678
//   0x6308: 72a24697  movk       w23, #0x1234, lsl #16
//   0x630c: f946b508  ldr        x8, [x8, #0xd68]
//   0x6310: f9400108  ldr        x8, [x8]
//   0x6314: f9400d08  ldr        x8, [x8, #0x18]
//   0x6318: d63f0100  blr        x8
//   0x631c: f94002c8  ldr        x8, [x22]
//   0x6320: aa0003f5  mov        x21, x0
//   0x6324: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6328: 94000db2  bl         #0x99f0
//   0x632c: eb17001f  cmp        x0, x23
//   0x6330: 540001e0  b.eq       #0x636c
//   0x6334: f94002c8  ldr        x8, [x22]
//   0x6338: 528acf01  mov        w1, #0x5678
//   0x633c: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6340: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6344: 94000d77  bl         #0x9920
//   0x6348: aa1503e0  mov        x0, x21
//   0x634c: aa1303e1  mov        x1, x19
//   0x6350: aa1403e2  mov        x2, x20
//   0x6354: aa1d03e3  mov        x3, x29
//   0x6358: 94000693  bl         #0x7da4
//   0x635c: f94002c8  ldr        x8, [x22]
//   0x6360: aa1f03e1  mov        x1, xzr
//   0x6364: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6368: 94000d6e  bl         #0x9920
//   0x636c: 9240dea0  and        x0, x21, #0xffffffffffffff
//   0x6370: 1400000b  b          #0x639c
//   0x6374: aa1403e0  mov        x0, x20
//   0x6378: aa1d03e1  mov        x1, x29
//   0x637c: 94000abe  bl         #0x8e74
//   0x6380: f0000028  adrp       x8, #0xd000
//   0x6384: aa1303e0  mov        x0, x19
//   0x6388: f946b508  ldr        x8, [x8, #0xd68]
//   0x638c: f9400108  ldr        x8, [x8]
//   0x6390: f9400d08  ldr        x8, [x8, #0x18]
//   0x6394: d63f0100  blr        x8
//   0x6398: 9240dc00  and        x0, x0, #0xffffffffffffff
//   0x639c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x63a0: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x63a4: f9400bf7  ldr        x23, [sp, #0x10]
//   0x63a8: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x63ac: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[30] HeapTrackerHookCalloc_63b0 (0x63b0..0x6500, 336 bytes, 84 instructions)
// Summary / Tóm tắt: Hooked calloc with xpaclri (0xd50320ff @ 0x63d4) LR stripping (@ 0x63b0..0x6500)
// ----------------------------------------------------------------------------
//   0x63b0: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x63b4: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x63b8: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x63bc: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x63c0: 910003fd  mov        x29, sp
//   0x63c4: f0000037  adrp       x23, #0xd000
//   0x63c8: aa0103f3  mov        x19, x1
//   0x63cc: aa0003f4  mov        x20, x0
//   0x63d0: f946bef7  ldr        x23, [x23, #0xd78]
//   0x63d4: d50320ff  xpaclri    
//   0x63d8: f94002e8  ldr        x8, [x23]
//   0x63dc: b941f108  ldr        w8, [x8, #0x1f0]
//   0x63e0: 51000508  sub        w8, w8, #1
//   0x63e4: 7100111f  cmp        w8, #4
//   0x63e8: 54000188  b.hi       #0x6418
//   0x63ec: d503201f  nop        
//   0x63f0: 70fe1749  adr        x9, #0x26db
//   0x63f4: aa1e03f5  mov        x21, x30
//   0x63f8: 1000008a  adr        x10, #0x6408
//   0x63fc: 3868692b  ldrb       w11, [x9, x8]
//   0x6400: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x6404: d61f0140  br         x10
//   0x6408: 9b147e62  mul        x2, x19, x20
//   0x640c: aa1503e0  mov        x0, x21
//   0x6410: aa1d03e1  mov        x1, x29
//   0x6414: 94000187  bl         #0x6a30
//   0x6418: f0000028  adrp       x8, #0xd000
//   0x641c: aa1403e0  mov        x0, x20
//   0x6420: f946b508  ldr        x8, [x8, #0xd68]
//   0x6424: f9400108  ldr        x8, [x8]
//   0x6428: f9400102  ldr        x2, [x8]
//   0x642c: aa1303e1  mov        x1, x19
//   0x6430: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6434: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6438: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x643c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6440: d61f0040  br         x2
//   0x6444: f0000028  adrp       x8, #0xd000
//   0x6448: aa1403e0  mov        x0, x20
//   0x644c: aa1303e1  mov        x1, x19
//   0x6450: 528acf18  mov        w24, #0x5678
//   0x6454: 72a24698  movk       w24, #0x1234, lsl #16
//   0x6458: f946b508  ldr        x8, [x8, #0xd68]
//   0x645c: f9400108  ldr        x8, [x8]
//   0x6460: f9400108  ldr        x8, [x8]
//   0x6464: d63f0100  blr        x8
//   0x6468: f94002e8  ldr        x8, [x23]
//   0x646c: aa0003f6  mov        x22, x0
//   0x6470: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6474: 94000d5f  bl         #0x99f0
//   0x6478: eb18001f  cmp        x0, x24
//   0x647c: 540001e0  b.eq       #0x64b8
//   0x6480: f94002e8  ldr        x8, [x23]
//   0x6484: 528acf01  mov        w1, #0x5678
//   0x6488: 72a24681  movk       w1, #0x1234, lsl #16
//   0x648c: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6490: 94000d24  bl         #0x9920
//   0x6494: 9b147e61  mul        x1, x19, x20
//   0x6498: aa1603e0  mov        x0, x22
//   0x649c: aa1503e2  mov        x2, x21
//   0x64a0: aa1d03e3  mov        x3, x29
//   0x64a4: 94000640  bl         #0x7da4
//   0x64a8: f94002e8  ldr        x8, [x23]
//   0x64ac: aa1f03e1  mov        x1, xzr
//   0x64b0: b9421d00  ldr        w0, [x8, #0x21c]
//   0x64b4: 94000d1b  bl         #0x9920
//   0x64b8: 9240dec0  and        x0, x22, #0xffffffffffffff
//   0x64bc: 1400000c  b          #0x64ec
//   0x64c0: aa1503e0  mov        x0, x21
//   0x64c4: aa1d03e1  mov        x1, x29
//   0x64c8: 94000a6b  bl         #0x8e74
//   0x64cc: f0000028  adrp       x8, #0xd000
//   0x64d0: aa1403e0  mov        x0, x20
//   0x64d4: aa1303e1  mov        x1, x19
//   0x64d8: f946b508  ldr        x8, [x8, #0xd68]
//   0x64dc: f9400108  ldr        x8, [x8]
//   0x64e0: f9400108  ldr        x8, [x8]
//   0x64e4: d63f0100  blr        x8
//   0x64e8: 9240dc00  and        x0, x0, #0xffffffffffffff
//   0x64ec: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x64f0: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x64f4: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x64f8: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x64fc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[31] HeapTrackerHookRealloc_6500 (0x6500..0x6644, 324 bytes, 81 instructions)
// Summary / Tóm tắt: Hooked realloc with xpaclri (0xd50320ff @ 0x6524) LR stripping (@ 0x6500..0x6644)
// ----------------------------------------------------------------------------
//   0x6500: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6504: f9000bf7  str        x23, [sp, #0x10]
//   0x6508: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x650c: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6510: 910003fd  mov        x29, sp
//   0x6514: f0000036  adrp       x22, #0xd000
//   0x6518: aa0103f3  mov        x19, x1
//   0x651c: aa0003f4  mov        x20, x0
//   0x6520: f946bed6  ldr        x22, [x22, #0xd78]
//   0x6524: d50320ff  xpaclri    
//   0x6528: f94002c8  ldr        x8, [x22]
//   0x652c: b941f108  ldr        w8, [x8, #0x1f0]
//   0x6530: 51000508  sub        w8, w8, #1
//   0x6534: 7100111f  cmp        w8, #4
//   0x6538: 54000708  b.hi       #0x6618
//   0x653c: d503201f  nop        
//   0x6540: 10fe0d09  adr        x9, #0x26e0
//   0x6544: aa1e03f5  mov        x21, x30
//   0x6548: 1000008a  adr        x10, #0x6558
//   0x654c: 3868692b  ldrb       w11, [x9, x8]
//   0x6550: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x6554: d61f0140  br         x10
//   0x6558: aa1503e0  mov        x0, x21
//   0x655c: aa1d03e1  mov        x1, x29
//   0x6560: aa1303e2  mov        x2, x19
//   0x6564: 94000133  bl         #0x6a30
//   0x6568: 1400002c  b          #0x6618
//   0x656c: aa1403e0  mov        x0, x20
//   0x6570: 528acf17  mov        w23, #0x5678
//   0x6574: 72a24697  movk       w23, #0x1234, lsl #16
//   0x6578: 940006f2  bl         #0x8140
//   0x657c: f0000028  adrp       x8, #0xd000
//   0x6580: aa1403e0  mov        x0, x20
//   0x6584: aa1303e1  mov        x1, x19
//   0x6588: f946b508  ldr        x8, [x8, #0xd68]
//   0x658c: f9400108  ldr        x8, [x8]
//   0x6590: f9401d08  ldr        x8, [x8, #0x38]
//   0x6594: d63f0100  blr        x8
//   0x6598: f94002c8  ldr        x8, [x22]
//   0x659c: aa0003f4  mov        x20, x0
//   0x65a0: b9421d00  ldr        w0, [x8, #0x21c]
//   0x65a4: 94000d13  bl         #0x99f0
//   0x65a8: eb17001f  cmp        x0, x23
//   0x65ac: 540001e0  b.eq       #0x65e8
//   0x65b0: f94002c8  ldr        x8, [x22]
//   0x65b4: 528acf01  mov        w1, #0x5678
//   0x65b8: 72a24681  movk       w1, #0x1234, lsl #16
//   0x65bc: b9421d00  ldr        w0, [x8, #0x21c]
//   0x65c0: 94000cd8  bl         #0x9920
//   0x65c4: aa1403e0  mov        x0, x20
//   0x65c8: aa1303e1  mov        x1, x19
//   0x65cc: aa1503e2  mov        x2, x21
//   0x65d0: aa1d03e3  mov        x3, x29
//   0x65d4: 940005f4  bl         #0x7da4
//   0x65d8: f94002c8  ldr        x8, [x22]
//   0x65dc: aa1f03e1  mov        x1, xzr
//   0x65e0: b9421d00  ldr        w0, [x8, #0x21c]
//   0x65e4: 94000ccf  bl         #0x9920
//   0x65e8: 9240de80  and        x0, x20, #0xffffffffffffff
//   0x65ec: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x65f0: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x65f4: f9400bf7  ldr        x23, [sp, #0x10]
//   0x65f8: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x65fc: d65f03c0  ret        
//   0x6600: aa1403e0  mov        x0, x20
//   0x6604: 940006cf  bl         #0x8140
//   0x6608: 14000004  b          #0x6618
//   0x660c: aa1503e0  mov        x0, x21
//   0x6610: aa1d03e1  mov        x1, x29
//   0x6614: 94000a18  bl         #0x8e74
//   0x6618: f0000028  adrp       x8, #0xd000
//   0x661c: aa1403e0  mov        x0, x20
//   0x6620: f946b508  ldr        x8, [x8, #0xd68]
//   0x6624: f9400108  ldr        x8, [x8]
//   0x6628: f9401d02  ldr        x2, [x8, #0x38]
//   0x662c: aa1303e1  mov        x1, x19
//   0x6630: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6634: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6638: f9400bf7  ldr        x23, [sp, #0x10]
//   0x663c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6640: d61f0040  br         x2

// ----------------------------------------------------------------------------
// FDE[32] HeapTrackerHookMemalign_6644 (0x6644..0x6774, 304 bytes, 76 instructions)
// Summary / Tóm tắt: Hooked memalign with xpaclri (0xd50320ff @ 0x6668) LR stripping (@ 0x6644..0x6774)
// ----------------------------------------------------------------------------
//   0x6644: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6648: f9000bf7  str        x23, [sp, #0x10]
//   0x664c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6650: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6654: 910003fd  mov        x29, sp
//   0x6658: f0000036  adrp       x22, #0xd000
//   0x665c: aa0103f3  mov        x19, x1
//   0x6660: aa0003f4  mov        x20, x0
//   0x6664: f946bed6  ldr        x22, [x22, #0xd78]
//   0x6668: d50320ff  xpaclri    
//   0x666c: f94002c8  ldr        x8, [x22]
//   0x6670: b941f108  ldr        w8, [x8, #0x1f0]
//   0x6674: 51000508  sub        w8, w8, #1
//   0x6678: 7100111f  cmp        w8, #4
//   0x667c: 54000668  b.hi       #0x6748
//   0x6680: d503201f  nop        
//   0x6684: 30fe0309  adr        x9, #0x26e5
//   0x6688: aa1e03f5  mov        x21, x30
//   0x668c: 1000008a  adr        x10, #0x669c
//   0x6690: 3868692b  ldrb       w11, [x9, x8]
//   0x6694: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x6698: d61f0140  br         x10
//   0x669c: aa1503e0  mov        x0, x21
//   0x66a0: aa1d03e1  mov        x1, x29
//   0x66a4: aa1303e2  mov        x2, x19
//   0x66a8: 940000e2  bl         #0x6a30
//   0x66ac: 14000027  b          #0x6748
//   0x66b0: f0000028  adrp       x8, #0xd000
//   0x66b4: aa1403e0  mov        x0, x20
//   0x66b8: aa1303e1  mov        x1, x19
//   0x66bc: 528acf17  mov        w23, #0x5678
//   0x66c0: 72a24697  movk       w23, #0x1234, lsl #16
//   0x66c4: f946b508  ldr        x8, [x8, #0xd68]
//   0x66c8: f9400108  ldr        x8, [x8]
//   0x66cc: f9401508  ldr        x8, [x8, #0x28]
//   0x66d0: d63f0100  blr        x8
//   0x66d4: f94002c8  ldr        x8, [x22]
//   0x66d8: aa0003f4  mov        x20, x0
//   0x66dc: b9421d00  ldr        w0, [x8, #0x21c]
//   0x66e0: 94000cc4  bl         #0x99f0
//   0x66e4: eb17001f  cmp        x0, x23
//   0x66e8: 540001e0  b.eq       #0x6724
//   0x66ec: f94002c8  ldr        x8, [x22]
//   0x66f0: 528acf01  mov        w1, #0x5678
//   0x66f4: 72a24681  movk       w1, #0x1234, lsl #16
//   0x66f8: b9421d00  ldr        w0, [x8, #0x21c]
//   0x66fc: 94000c89  bl         #0x9920
//   0x6700: aa1403e0  mov        x0, x20
//   0x6704: aa1303e1  mov        x1, x19
//   0x6708: aa1503e2  mov        x2, x21
//   0x670c: aa1d03e3  mov        x3, x29
//   0x6710: 940005a5  bl         #0x7da4
//   0x6714: f94002c8  ldr        x8, [x22]
//   0x6718: aa1f03e1  mov        x1, xzr
//   0x671c: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6720: 94000c80  bl         #0x9920
//   0x6724: 9240de80  and        x0, x20, #0xffffffffffffff
//   0x6728: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x672c: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6730: f9400bf7  ldr        x23, [sp, #0x10]
//   0x6734: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6738: d65f03c0  ret        
//   0x673c: aa1503e0  mov        x0, x21
//   0x6740: aa1d03e1  mov        x1, x29
//   0x6744: 940009cc  bl         #0x8e74
//   0x6748: f0000028  adrp       x8, #0xd000
//   0x674c: aa1403e0  mov        x0, x20
//   0x6750: f946b508  ldr        x8, [x8, #0xd68]
//   0x6754: f9400108  ldr        x8, [x8]
//   0x6758: f9401502  ldr        x2, [x8, #0x28]
//   0x675c: aa1303e1  mov        x1, x19
//   0x6760: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6764: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6768: f9400bf7  ldr        x23, [sp, #0x10]
//   0x676c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6770: d61f0040  br         x2

// ----------------------------------------------------------------------------
// FDE[33] HeapTrackerHookPosixMemalign_6774 (0x6774..0x68b0, 316 bytes, 79 instructions)
// Summary / Tóm tắt: Hooked posix_memalign with xpaclri (0xd50320ff @ 0x679c) LR stripping (@ 0x6774..0x68b0)
// ----------------------------------------------------------------------------
//   0x6774: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6778: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x677c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6780: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6784: 910003fd  mov        x29, sp
//   0x6788: f0000037  adrp       x23, #0xd000
//   0x678c: aa0203f3  mov        x19, x2
//   0x6790: aa0103f5  mov        x21, x1
//   0x6794: aa0003f4  mov        x20, x0
//   0x6798: f946bef7  ldr        x23, [x23, #0xd78]
//   0x679c: d50320ff  xpaclri    
//   0x67a0: f94002e8  ldr        x8, [x23]
//   0x67a4: b941f108  ldr        w8, [x8, #0x1f0]
//   0x67a8: 51000508  sub        w8, w8, #1
//   0x67ac: 7100111f  cmp        w8, #4
//   0x67b0: 54000688  b.hi       #0x6880
//   0x67b4: d503201f  nop        
//   0x67b8: 50fdf989  adr        x9, #0x26ea
//   0x67bc: aa1e03f6  mov        x22, x30
//   0x67c0: 1000008a  adr        x10, #0x67d0
//   0x67c4: 3868692b  ldrb       w11, [x9, x8]
//   0x67c8: 8b0b094a  add        x10, x10, x11, lsl #2
//   0x67cc: d61f0140  br         x10
//   0x67d0: aa1603e0  mov        x0, x22
//   0x67d4: aa1d03e1  mov        x1, x29
//   0x67d8: aa1303e2  mov        x2, x19
//   0x67dc: 94000095  bl         #0x6a30
//   0x67e0: 14000028  b          #0x6880
//   0x67e4: f0000028  adrp       x8, #0xd000
//   0x67e8: aa1403e0  mov        x0, x20
//   0x67ec: aa1503e1  mov        x1, x21
//   0x67f0: aa1303e2  mov        x2, x19
//   0x67f4: 528acf18  mov        w24, #0x5678
//   0x67f8: f946b508  ldr        x8, [x8, #0xd68]
//   0x67fc: 72a24698  movk       w24, #0x1234, lsl #16
//   0x6800: f9400108  ldr        x8, [x8]
//   0x6804: f9401908  ldr        x8, [x8, #0x30]
//   0x6808: d63f0100  blr        x8
//   0x680c: f94002e8  ldr        x8, [x23]
//   0x6810: 2a0003f5  mov        w21, w0
//   0x6814: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6818: 94000c76  bl         #0x99f0
//   0x681c: eb18001f  cmp        x0, x24
//   0x6820: 540001e0  b.eq       #0x685c
//   0x6824: f94002e8  ldr        x8, [x23]
//   0x6828: 528acf01  mov        w1, #0x5678
//   0x682c: 72a24681  movk       w1, #0x1234, lsl #16
//   0x6830: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6834: 94000c3b  bl         #0x9920
//   0x6838: f9400280  ldr        x0, [x20]
//   0x683c: aa1303e1  mov        x1, x19
//   0x6840: aa1603e2  mov        x2, x22
//   0x6844: aa1d03e3  mov        x3, x29
//   0x6848: 94000557  bl         #0x7da4
//   0x684c: f94002e8  ldr        x8, [x23]
//   0x6850: aa1f03e1  mov        x1, xzr
//   0x6854: b9421d00  ldr        w0, [x8, #0x21c]
//   0x6858: 94000c32  bl         #0x9920
//   0x685c: 2a1503e0  mov        w0, w21
//   0x6860: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6864: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6868: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x686c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6870: d65f03c0  ret        
//   0x6874: aa1603e0  mov        x0, x22
//   0x6878: aa1d03e1  mov        x1, x29
//   0x687c: 9400097e  bl         #0x8e74
//   0x6880: f0000028  adrp       x8, #0xd000
//   0x6884: aa1403e0  mov        x0, x20
//   0x6888: aa1503e1  mov        x1, x21
//   0x688c: f946b508  ldr        x8, [x8, #0xd68]
//   0x6890: f9400108  ldr        x8, [x8]
//   0x6894: f9401903  ldr        x3, [x8, #0x30]
//   0x6898: aa1303e2  mov        x2, x19
//   0x689c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x68a0: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x68a4: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x68a8: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x68ac: d61f0060  br         x3

// ----------------------------------------------------------------------------
// FDE[34] HeapTrackerPauseTracking_68b0 (0x68b0..0x68d8, 40 bytes, 10 instructions)
// Summary / Tóm tắt: Sets state = 4 (PAUSED) at manager+0x1f0 (@ 0x68b0..0x68d8)
// ----------------------------------------------------------------------------
//   0x68b0: d503201f  nop        
//   0x68b4: 1005bf68  adr        x8, #0x120a0
//   0x68b8: f9400108  ldr        x8, [x8]
//   0x68bc: b40000a8  cbz        x8, #0x68d0
//   0x68c0: 52800089  mov        w9, #4
//   0x68c4: 2a1f03e0  mov        w0, wzr
//   0x68c8: b901f109  str        w9, [x8, #0x1f0]
//   0x68cc: d65f03c0  ret        
//   0x68d0: 12800000  mov        w0, #-1
//   0x68d4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[35] HeapTrackerFde_68d8 (0x68d8..0x693c, 100 bytes, 25 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x68d8..0x693c
// ----------------------------------------------------------------------------
//   0x68d8: f0000028  adrp       x8, #0xd000
//   0x68dc: f000002a  adrp       x10, #0xd000
//   0x68e0: f946b908  ldr        x8, [x8, #0xd70]
//   0x68e4: f946b54a  ldr        x10, [x10, #0xd68]
//   0x68e8: f9400109  ldr        x9, [x8]
//   0x68ec: f940014b  ldr        x11, [x10]
//   0x68f0: f100013f  cmp        x9, #0
//   0x68f4: fa401964  ccmp       x11, #0, #4, ne
//   0x68f8: 54000061  b.ne       #0x6904
//   0x68fc: 12800000  mov        w0, #-1
//   0x6900: d65f03c0  ret        
//   0x6904: f940016c  ldr        x12, [x11]
//   0x6908: 2a1f03e0  mov        w0, wzr
//   0x690c: f9400d6b  ldr        x11, [x11, #0x18]
//   0x6910: f900012c  str        x12, [x9]
//   0x6914: f940014a  ldr        x10, [x10]
//   0x6918: f9000d2b  str        x11, [x9, #0x18]
//   0x691c: f9400108  ldr        x8, [x8]
//   0x6920: 3cc28140  ldur       q0, [x10, #0x28]
//   0x6924: 3c828100  stur       q0, [x8, #0x28]
//   0x6928: f9400549  ldr        x9, [x10, #8]
//   0x692c: f9401d4a  ldr        x10, [x10, #0x38]
//   0x6930: f9000509  str        x9, [x8, #8]
//   0x6934: f9001d0a  str        x10, [x8, #0x38]
//   0x6938: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[36] HeapTrackerStopTracking_693c (0x693c..0x6964, 40 bytes, 10 instructions)
// Summary / Tóm tắt: Sets state = 5 (STOPPED) at manager+0x1f0 (@ 0x693c..0x6964)
// ----------------------------------------------------------------------------
//   0x693c: d503201f  nop        
//   0x6940: 1005bb08  adr        x8, #0x120a0
//   0x6944: f9400108  ldr        x8, [x8]
//   0x6948: b40000a8  cbz        x8, #0x695c
//   0x694c: 528000a9  mov        w9, #5
//   0x6950: 2a1f03e0  mov        w0, wzr
//   0x6954: b901f109  str        w9, [x8, #0x1f0]
//   0x6958: d65f03c0  ret        
//   0x695c: 12800000  mov        w0, #-1
//   0x6960: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[37] HeapTrackerFde_6964 (0x6964..0x69dc, 120 bytes, 30 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x6964..0x69dc
// ----------------------------------------------------------------------------
//   0x6964: f0000028  adrp       x8, #0xd000
//   0x6968: f000002a  adrp       x10, #0xd000
//   0x696c: f946b908  ldr        x8, [x8, #0xd70]
//   0x6970: f946b54a  ldr        x10, [x10, #0xd68]
//   0x6974: f9400109  ldr        x9, [x8]
//   0x6978: f940014a  ldr        x10, [x10]
//   0x697c: f100013f  cmp        x9, #0
//   0x6980: fa401944  ccmp       x10, #0, #4, ne
//   0x6984: 54000061  b.ne       #0x6990
//   0x6988: 12800000  mov        w0, #-1
//   0x698c: d65f03c0  ret        
//   0x6990: d503201f  nop        
//   0x6994: 10ffdb6b  adr        x11, #0x6500
//   0x6998: d503201f  nop        
//   0x699c: 1000020a  adr        x10, #0x69dc
//   0x69a0: d503201f  nop        
//   0x69a4: 10ffd06c  adr        x12, #0x63b0
//   0x69a8: f9001d2b  str        x11, [x9, #0x38]
//   0x69ac: d503201f  nop        
//   0x69b0: 10ffc60b  adr        x11, #0x6270
//   0x69b4: 2a1f03e0  mov        w0, wzr
//   0x69b8: a900292c  stp        x12, x10, [x9]
//   0x69bc: d503201f  nop        
//   0x69c0: 10ffedaa  adr        x10, #0x6774
//   0x69c4: f9400108  ldr        x8, [x8]
//   0x69c8: f9000d2b  str        x11, [x9, #0x18]
//   0x69cc: d503201f  nop        
//   0x69d0: 10ffe3a9  adr        x9, #0x6644
//   0x69d4: a902a909  stp        x9, x10, [x8, #0x28]
//   0x69d8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[38] HeapTrackerHookFree_69dc (0x69dc..0x6a30, 84 bytes, 21 instructions)
// Summary / Tóm tắt: Hooked free masking top byte TBI (and x19, x19, #0xffffffffffffff @ 0x6a04) (@ 0x69dc..0x6a30)
// ----------------------------------------------------------------------------
//   0x69dc: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x69e0: f9000bf3  str        x19, [sp, #0x10]
//   0x69e4: 910003fd  mov        x29, sp
//   0x69e8: f0000028  adrp       x8, #0xd000
//   0x69ec: aa0003f3  mov        x19, x0
//   0x69f0: f946bd08  ldr        x8, [x8, #0xd78]
//   0x69f4: f9400108  ldr        x8, [x8]
//   0x69f8: b941f108  ldr        w8, [x8, #0x1f0]
//   0x69fc: 7100151f  cmp        w8, #5
//   0x6a00: 54000080  b.eq       #0x6a10
//   0x6a04: 9240de73  and        x19, x19, #0xffffffffffffff
//   0x6a08: aa1303e0  mov        x0, x19
//   0x6a0c: 940005cd  bl         #0x8140
//   0x6a10: d503201f  nop        
//   0x6a14: 1005b328  adr        x8, #0x12078
//   0x6a18: f9400108  ldr        x8, [x8]
//   0x6a1c: f9400501  ldr        x1, [x8, #8]
//   0x6a20: aa1303e0  mov        x0, x19
//   0x6a24: f9400bf3  ldr        x19, [sp, #0x10]
//   0x6a28: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x6a2c: d61f0020  br         x1

// ----------------------------------------------------------------------------
// FDE[39] HeapTrackerFde_6a30 (0x6a30..0x6c98, 616 bytes, 154 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x6a30..0x6c98
// ----------------------------------------------------------------------------
//   0x6a30: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x6a34: f9000bf7  str        x23, [sp, #0x10]
//   0x6a38: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x6a3c: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x6a40: 910003fd  mov        x29, sp
//   0x6a44: f0000028  adrp       x8, #0xd000
//   0x6a48: aa0203f5  mov        x21, x2
//   0x6a4c: aa0103f3  mov        x19, x1
//   0x6a50: aa0003f4  mov        x20, x0
//   0x6a54: f946bd08  ldr        x8, [x8, #0xd78]
//   0x6a58: f9400108  ldr        x8, [x8]
//   0x6a5c: b941f108  ldr        w8, [x8, #0x1f0]
//   0x6a60: 7100091f  cmp        w8, #2
//   0x6a64: 540005c0  b.eq       #0x6b1c
//   0x6a68: 7100051f  cmp        w8, #1
//   0x6a6c: 540010c1  b.ne       #0x6c84
//   0x6a70: f109cebf  cmp        x21, #0x273
//   0x6a74: 54000580  b.eq       #0x6b24
//   0x6a78: f10506bf  cmp        x21, #0x141
//   0x6a7c: 54001041  b.ne       #0x6c84
//   0x6a80: 90000068  adrp       x8, #0x12000
//   0x6a84: f9405d08  ldr        x8, [x8, #0xb8]
//   0x6a88: eb130116  subs       x22, x8, x19
//   0x6a8c: 54000fc9  b.ls       #0x6c84
//   0x6a90: 91400a69  add        x9, x19, #2, lsl #12
//   0x6a94: eb08013f  cmp        x9, x8
//   0x6a98: 54000f69  b.ls       #0x6c84
//   0x6a9c: 90000069  adrp       x9, #0x12000
//   0x6aa0: f9406129  ldr        x9, [x9, #0xc0]
//   0x6aa4: eb14013f  cmp        x9, x20
//   0x6aa8: 54000082  b.hs       #0x6ab8
//   0x6aac: 9102012a  add        x10, x9, #0x80
//   0x6ab0: eb14015f  cmp        x10, x20
//   0x6ab4: 54000e88  b.hi       #0x6c84
//   0x6ab8: 9104012a  add        x10, x9, #0x100
//   0x6abc: f940010b  ldr        x11, [x8]
//   0x6ac0: eb09017f  cmp        x11, x9
//   0x6ac4: fa4b8140  ccmp       x10, x11, #0, hi
//   0x6ac8: 540000c8  b.hi       #0x6ae0
//   0x6acc: d1002108  sub        x8, x8, #8
//   0x6ad0: d10022d6  sub        x22, x22, #8
//   0x6ad4: eb13011f  cmp        x8, x19
//   0x6ad8: 54ffff28  b.hi       #0x6abc
//   0x6adc: 14000010  b          #0x6b1c
//   0x6ae0: f0000028  adrp       x8, #0xd000
//   0x6ae4: 52800400  mov        w0, #0x20
//   0x6ae8: f946b508  ldr        x8, [x8, #0xd68]
//   0x6aec: f9400108  ldr        x8, [x8]
//   0x6af0: f9400d08  ldr        x8, [x8, #0x18]
//   0x6af4: d63f0100  blr        x8
//   0x6af8: d503201f  nop        
//   0x6afc: 1005aa69  adr        x9, #0x12048
//   0x6b00: 90000068  adrp       x8, #0x12000
//   0x6b04: a9015814  stp        x20, x22, [x0, #0x10]
//   0x6b08: f940012a  ldr        x10, [x9]
//   0x6b0c: a900240a  stp        x10, x9, [x0]
//   0x6b10: f940250a  ldr        x10, [x8, #0x48]
//   0x6b14: f9002500  str        x0, [x8, #0x48]
//   0x6b18: f9000540  str        x0, [x10, #8]
//   0x6b1c: f109cebf  cmp        x21, #0x273
//   0x6b20: 54000b21  b.ne       #0x6c84
//   0x6b24: 90000068  adrp       x8, #0x12000
//   0x6b28: f9406509  ldr        x9, [x8, #0xc8]
//   0x6b2c: eb13013f  cmp        x9, x19
//   0x6b30: 54000aa9  b.ls       #0x6c84
//   0x6b34: 91400a68  add        x8, x19, #2, lsl #12
//   0x6b38: eb09011f  cmp        x8, x9
//   0x6b3c: 54000a49  b.ls       #0x6c84
//   0x6b40: 9000006b  adrp       x11, #0x12000
//   0x6b44: f940696a  ldr        x10, [x11, #0xd0]
//   0x6b48: eb14015f  cmp        x10, x20
//   0x6b4c: 540009c0  b.eq       #0x6c84
//   0x6b50: f0000028  adrp       x8, #0xd000
//   0x6b54: f000002c  adrp       x12, #0xd000
//   0x6b58: f946b508  ldr        x8, [x8, #0xd68]
//   0x6b5c: f946b98c  ldr        x12, [x12, #0xd70]
//   0x6b60: f9400108  ldr        x8, [x8]
//   0x6b64: f940018c  ldr        x12, [x12]
//   0x6b68: f9400d0d  ldr        x13, [x8, #0x18]
//   0x6b6c: f940190e  ldr        x14, [x8, #0x30]
//   0x6b70: f9000d8d  str        x13, [x12, #0x18]
//   0x6b74: f900198e  str        x14, [x12, #0x30]
//   0x6b78: d503201f  nop        
//   0x6b7c: 1000430c  adr        x12, #0x73dc
//   0x6b80: 14000006  b          #0x6b98
//   0x6b84: eb0a01bf  cmp        x13, x10
//   0x6b88: 540001a0  b.eq       #0x6bbc
//   0x6b8c: d1002129  sub        x9, x9, #8
//   0x6b90: eb13013f  cmp        x9, x19
//   0x6b94: 54000149  b.ls       #0x6bbc
//   0x6b98: f940012d  ldr        x13, [x9]
//   0x6b9c: b5ffff4a  cbnz       x10, #0x6b84
//   0x6ba0: eb0c01bf  cmp        x13, x12
//   0x6ba4: 54ffff49  b.ls       #0x6b8c
//   0x6ba8: 9102018e  add        x14, x12, #0x80
//   0x6bac: eb0e01bf  cmp        x13, x14
//   0x6bb0: 54fffee2  b.hs       #0x6b8c
//   0x6bb4: aa0d03ea  mov        x10, x13
//   0x6bb8: f900696d  str        x13, [x11, #0xd0]
//   0x6bbc: eb130135  subs       x21, x9, x19
//   0x6bc0: 54000629  b.ls       #0x6c84
//   0x6bc4: eb14015f  cmp        x10, x20
//   0x6bc8: 540005e0  b.eq       #0x6c84
//   0x6bcc: d503201f  nop        
//   0x6bd0: 1005a3c9  adr        x9, #0x12048
//   0x6bd4: aa0903ea  mov        x10, x9
//   0x6bd8: f940014a  ldr        x10, [x10]
//   0x6bdc: eb09015f  cmp        x10, x9
//   0x6be0: 540000c0  b.eq       #0x6bf8
//   0x6be4: f940094b  ldr        x11, [x10, #0x10]
//   0x6be8: eb14017f  cmp        x11, x20
//   0x6bec: 54ffff61  b.ne       #0x6bd8
//   0x6bf0: f9400d49  ldr        x9, [x10, #0x18]
//   0x6bf4: f8736934  ldr        x20, [x9, x19]
//   0x6bf8: d503201f  nop        
//   0x6bfc: 1005a2f7  adr        x23, #0x12058
//   0x6c00: aa1703f6  mov        x22, x23
//   0x6c04: f94002d6  ldr        x22, [x22]
//   0x6c08: eb1702df  cmp        x22, x23
//   0x6c0c: 54000240  b.eq       #0x6c54
//   0x6c10: f94012c9  ldr        x9, [x22, #0x20]
//   0x6c14: eb14013f  cmp        x9, x20
//   0x6c18: 54ffff61  b.ne       #0x6c04
//   0x6c1c: f94016c9  ldr        x9, [x22, #0x28]
//   0x6c20: eb15013f  cmp        x9, x21
//   0x6c24: 54000302  b.hs       #0x6c84
//   0x6c28: f9400d08  ldr        x8, [x8, #0x18]
//   0x6c2c: 52800400  mov        w0, #0x20
//   0x6c30: d63f0100  blr        x8
//   0x6c34: f8410ec8  ldr        x8, [x22, #0x10]!
//   0x6c38: f9400ec9  ldr        x9, [x22, #0x18]
//   0x6c3c: f8736929  ldr        x9, [x9, x19]
//   0x6c40: a9005808  stp        x8, x22, [x0]
//   0x6c44: f94002c8  ldr        x8, [x22]
//   0x6c48: f90002c0  str        x0, [x22]
//   0x6c4c: a9015409  stp        x9, x21, [x0, #0x10]
//   0x6c50: 1400000c  b          #0x6c80
//   0x6c54: f9400d08  ldr        x8, [x8, #0x18]
//   0x6c58: 52800600  mov        w0, #0x30
//   0x6c5c: d63f0100  blr        x8
//   0x6c60: f94002e8  ldr        x8, [x23]
//   0x6c64: 90000069  adrp       x9, #0x12000
//   0x6c68: 9100400a  add        x10, x0, #0x10
//   0x6c6c: a9025414  stp        x20, x21, [x0, #0x20]
//   0x6c70: a9005c08  stp        x8, x23, [x0]
//   0x6c74: f9402d28  ldr        x8, [x9, #0x58]
//   0x6c78: a901280a  stp        x10, x10, [x0, #0x10]
//   0x6c7c: f9002d20  str        x0, [x9, #0x58]
//   0x6c80: f9000500  str        x0, [x8, #8]
//   0x6c84: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x6c88: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x6c8c: f9400bf7  ldr        x23, [sp, #0x10]
//   0x6c90: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x6c94: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[40] HeapTrackerFde_6c98 (0x6c98..0x6fd4, 828 bytes, 207 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x6c98..0x6fd4
// ----------------------------------------------------------------------------
//   0x6c98: d10243ff  sub        sp, sp, #0x90
//   0x6c9c: a9037bfd  stp        x29, x30, [sp, #0x30]
//   0x6ca0: a9046ffc  stp        x28, x27, [sp, #0x40]
//   0x6ca4: a90567fa  stp        x26, x25, [sp, #0x50]
//   0x6ca8: a9065ff8  stp        x24, x23, [sp, #0x60]
//   0x6cac: a90757f6  stp        x22, x21, [sp, #0x70]
//   0x6cb0: a9084ff4  stp        x20, x19, [sp, #0x80]
//   0x6cb4: 9100c3fd  add        x29, sp, #0x30
//   0x6cb8: f000003c  adrp       x28, #0xd000
//   0x6cbc: d53bd05b  mrs        x27, tpidr_el0
//   0x6cc0: f000002b  adrp       x11, #0xd000
//   0x6cc4: f000002a  adrp       x10, #0xd000
//   0x6cc8: f000002c  adrp       x12, #0xd000
//   0x6ccc: 90000077  adrp       x23, #0x12000
//   0x6cd0: f946bf9c  ldr        x28, [x28, #0xd78]
//   0x6cd4: f9401768  ldr        x8, [x27, #0x28]
//   0x6cd8: f946b96b  ldr        x11, [x11, #0xd70]
//   0x6cdc: f946b54a  ldr        x10, [x10, #0xd68]
//   0x6ce0: f81f83a8  stur       x8, [x29, #-8]
//   0x6ce4: 52800028  mov        w8, #1
//   0x6ce8: f9400389  ldr        x9, [x28]
//   0x6cec: f940014a  ldr        x10, [x10]
//   0x6cf0: f946cd8c  ldr        x12, [x12, #0xd98]
//   0x6cf4: b901f128  str        w8, [x9, #0x1f0]
//   0x6cf8: f9400173  ldr        x19, [x11]
//   0x6cfc: a9435959  ldp        x25, x22, [x10, #0x30]
//   0x6d00: d503201f  nop        
//   0x6d04: 10003948  adr        x8, #0x742c
//   0x6d08: f9400d54  ldr        x20, [x10, #0x18]
//   0x6d0c: f9400155  ldr        x21, [x10]
//   0x6d10: f9401558  ldr        x24, [x10, #0x28]
//   0x6d14: f9000e6c  str        x12, [x19, #0x18]
//   0x6d18: f90062e8  str        x8, [x23, #0xc0]
//   0x6d1c: 940001c4  bl         #0x742c
//   0x6d20: f0000028  adrp       x8, #0xd000
//   0x6d24: f9000e74  str        x20, [x19, #0x18]
//   0x6d28: 9000007a  adrp       x26, #0x12000
//   0x6d2c: d503201f  nop        
//   0x6d30: 100039e9  adr        x9, #0x746c
//   0x6d34: f946d108  ldr        x8, [x8, #0xda0]
//   0x6d38: f9005f5f  str        xzr, [x26, #0xb8]
//   0x6d3c: f9000268  str        x8, [x19]
//   0x6d40: f90062e9  str        x9, [x23, #0xc0]
//   0x6d44: 940001ca  bl         #0x746c
//   0x6d48: f0000028  adrp       x8, #0xd000
//   0x6d4c: f9005f5f  str        xzr, [x26, #0xb8]
//   0x6d50: d503201f  nop        
//   0x6d54: 10003ae9  adr        x9, #0x74b0
//   0x6d58: f946d908  ldr        x8, [x8, #0xdb0]
//   0x6d5c: f9000275  str        x21, [x19]
//   0x6d60: f90062e9  str        x9, [x23, #0xc0]
//   0x6d64: f9001668  str        x8, [x19, #0x28]
//   0x6d68: 940001d2  bl         #0x74b0
//   0x6d6c: f0000028  adrp       x8, #0xd000
//   0x6d70: f9005f5f  str        xzr, [x26, #0xb8]
//   0x6d74: d503201f  nop        
//   0x6d78: 10003be9  adr        x9, #0x74f4
//   0x6d7c: f946d508  ldr        x8, [x8, #0xda8]
//   0x6d80: f9001678  str        x24, [x19, #0x28]
//   0x6d84: f90062e9  str        x9, [x23, #0xc0]
//   0x6d88: f9001e68  str        x8, [x19, #0x38]
//   0x6d8c: 940001da  bl         #0x74f4
//   0x6d90: f0000029  adrp       x9, #0xd000
//   0x6d94: f9005f5f  str        xzr, [x26, #0xb8]
//   0x6d98: d503201f  nop        
//   0x6d9c: 10003ce8  adr        x8, #0x7538
//   0x6da0: f946dd29  ldr        x9, [x9, #0xdb8]
//   0x6da4: f90062e8  str        x8, [x23, #0xc0]
//   0x6da8: a9035a69  stp        x9, x22, [x19, #0x30]
//   0x6dac: 940001e3  bl         #0x7538
//   0x6db0: 910043f4  add        x20, sp, #0x10
//   0x6db4: d503201f  nop        
//   0x6db8: 100010e0  adr        x0, #0x6fd4
//   0x6dbc: 910043e1  add        x1, sp, #0x10
//   0x6dc0: f9005f5f  str        xzr, [x26, #0xb8]
//   0x6dc4: f9001a79  str        x25, [x19, #0x30]
//   0x6dc8: a90153f4  stp        x20, x20, [sp, #0x10]
//   0x6dcc: 94000b0d  bl         #0x9a00
//   0x6dd0: f9400bf3  ldr        x19, [sp, #0x10]
//   0x6dd4: 52800049  mov        w9, #2
//   0x6dd8: f9400388  ldr        x8, [x28]
//   0x6ddc: eb14027f  cmp        x19, x20
//   0x6de0: b901f109  str        w9, [x8, #0x1f0]
//   0x6de4: 54000da0  b.eq       #0x6f98
//   0x6de8: f90003fb  str        x27, [sp]
//   0x6dec: 528403fb  mov        w27, #0x201f
//   0x6df0: 72baa07b  movk       w27, #0xd503, lsl #16
//   0x6df4: d503201f  nop        
//   0x6df8: 10fdc7da  adr        x26, #0x26f0
//   0x6dfc: 1400000c  b          #0x6e2c
//   0x6e00: aa1503e0  mov        x0, x21
//   0x6e04: 94000a7f  bl         #0x9800
//   0x6e08: 910043f4  add        x20, sp, #0x10
//   0x6e0c: f94007f7  ldr        x23, [sp, #8]
//   0x6e10: f9400a60  ldr        x0, [x19, #0x10]
//   0x6e14: 94000aa3  bl         #0x98a0
//   0x6e18: aa1303e0  mov        x0, x19
//   0x6e1c: 94000aa1  bl         #0x98a0
//   0x6e20: aa1703f3  mov        x19, x23
//   0x6e24: eb1402ff  cmp        x23, x20
//   0x6e28: 54000b00  b.eq       #0x6f88
//   0x6e2c: a9402277  ldp        x23, x8, [x19]
//   0x6e30: f90006e8  str        x8, [x23, #8]
//   0x6e34: f9400668  ldr        x8, [x19, #8]
//   0x6e38: f9000117  str        x23, [x8]
//   0x6e3c: f9400a76  ldr        x22, [x19, #0x10]
//   0x6e40: b4fffed6  cbz        x22, #0x6e18
//   0x6e44: aa1603e0  mov        x0, x22
//   0x6e48: 94000a42  bl         #0x9750
//   0x6e4c: b4fffe20  cbz        x0, #0x6e10
//   0x6e50: aa0003f5  mov        x21, x0
//   0x6e54: aa1603e0  mov        x0, x22
//   0x6e58: 90ffffe1  adrp       x1, #0x2000
//   0x6e5c: 91182821  add        x1, x1, #0x60a
//   0x6e60: f90007f7  str        x23, [sp, #8]
//   0x6e64: 94000aeb  bl         #0x9a10
//   0x6e68: aa0003f6  mov        x22, x0
//   0x6e6c: aa1f03f4  mov        x20, xzr
//   0x6e70: 1400001b  b          #0x6edc
//   0x6e74: aa1803e0  mov        x0, x24
//   0x6e78: aa1903e1  mov        x1, x25
//   0x6e7c: 528000a2  mov        w2, #5
//   0x6e80: 94000a64  bl         #0x9810
//   0x6e84: f0000038  adrp       x24, #0xd000
//   0x6e88: f0000029  adrp       x9, #0xd000
//   0x6e8c: aa1703e0  mov        x0, x23
//   0x6e90: f946bb18  ldr        x24, [x24, #0xd70]
//   0x6e94: f9400308  ldr        x8, [x24]
//   0x6e98: f946cd29  ldr        x9, [x9, #0xd98]
//   0x6e9c: f9000d09  str        x9, [x8, #0x18]
//   0x6ea0: f0000029  adrp       x9, #0xd000
//   0x6ea4: f946dd29  ldr        x9, [x9, #0xdb8]
//   0x6ea8: f9001909  str        x9, [x8, #0x30]
//   0x6eac: 9400014c  bl         #0x73dc
//   0x6eb0: f0000028  adrp       x8, #0xd000
//   0x6eb4: f946b508  ldr        x8, [x8, #0xd68]
//   0x6eb8: f940030a  ldr        x10, [x24]
//   0x6ebc: f9400108  ldr        x8, [x8]
//   0x6ec0: f9400d09  ldr        x9, [x8, #0x18]
//   0x6ec4: f9000d49  str        x9, [x10, #0x18]
//   0x6ec8: f9401908  ldr        x8, [x8, #0x30]
//   0x6ecc: f9001948  str        x8, [x10, #0x30]
//   0x6ed0: 91000694  add        x20, x20, #1
//   0x6ed4: f100229f  cmp        x20, #8
//   0x6ed8: 54fff940  b.eq       #0x6e00
//   0x6edc: b8b47b48  ldrsw      x8, [x26, x20, lsl #2]
//   0x6ee0: d10043a2  sub        x2, x29, #0x10
//   0x6ee4: aa1503e0  mov        x0, x21
//   0x6ee8: 8b080341  add        x1, x26, x8
//   0x6eec: 94000acd  bl         #0x9a20
//   0x6ef0: b4ffff00  cbz        x0, #0x6ed0
//   0x6ef4: aa0003f7  mov        x23, x0
//   0x6ef8: b4fffc76  cbz        x22, #0x6e84
//   0x6efc: f85f03b8  ldur       x24, [x29, #-0x10]
//   0x6f00: 94000a1c  bl         #0x9770
//   0x6f04: 8b17031c  add        x28, x24, x23
//   0x6f08: 93407c08  sxtw       x8, w0
//   0x6f0c: cb0803e9  neg        x9, x8
//   0x6f10: 8b080388  add        x8, x28, x8
//   0x6f14: 8a170138  and        x24, x9, x23
//   0x6f18: 8a090108  and        x8, x8, x9
//   0x6f1c: cb180119  sub        x25, x8, x24
//   0x6f20: aa1803e0  mov        x0, x24
//   0x6f24: aa1903e1  mov        x1, x25
//   0x6f28: 528000e2  mov        w2, #7
//   0x6f2c: 94000a39  bl         #0x9810
//   0x6f30: 35fffaa0  cbnz       w0, #0x6e84
//   0x6f34: eb1c02ff  cmp        x23, x28
//   0x6f38: 54fff9e2  b.hs       #0x6e74
//   0x6f3c: b94002e8  ldr        w8, [x23]
//   0x6f40: 110c8369  add        w9, w27, #0x320
//   0x6f44: 6b09011f  cmp        w8, w9
//   0x6f48: 540000c0  b.eq       #0x6f60
//   0x6f4c: 17ffffca  b          #0x6e74
//   0x6f50: b900039b  str        w27, [x28]
//   0x6f54: d100139c  sub        x28, x28, #4
//   0x6f58: eb17039f  cmp        x28, x23
//   0x6f5c: 54fff8c9  b.ls       #0x6e74
//   0x6f60: b9400388  ldr        w8, [x28]
//   0x6f64: 110e8369  add        w9, w27, #0x3a0
//   0x6f68: 6b09011f  cmp        w8, w9
//   0x6f6c: 54ffff41  b.ne       #0x6f54
//   0x6f70: b94002e8  ldr        w8, [x23]
//   0x6f74: 110c8369  add        w9, w27, #0x320
//   0x6f78: 6b09011f  cmp        w8, w9
//   0x6f7c: 54fffea1  b.ne       #0x6f50
//   0x6f80: b90002fb  str        w27, [x23]
//   0x6f84: 17fffff3  b          #0x6f50
//   0x6f88: f0000028  adrp       x8, #0xd000
//   0x6f8c: f946bd08  ldr        x8, [x8, #0xd78]
//   0x6f90: f94003fb  ldr        x27, [sp]
//   0x6f94: f9400108  ldr        x8, [x8]
//   0x6f98: 52800069  mov        w9, #3
//   0x6f9c: b901f109  str        w9, [x8, #0x1f0]
//   0x6fa0: f9401768  ldr        x8, [x27, #0x28]
//   0x6fa4: f85f83a9  ldur       x9, [x29, #-8]
//   0x6fa8: eb09011f  cmp        x8, x9
//   0x6fac: 54000121  b.ne       #0x6fd0
//   0x6fb0: a9484ff4  ldp        x20, x19, [sp, #0x80]
//   0x6fb4: a94757f6  ldp        x22, x21, [sp, #0x70]
//   0x6fb8: a9465ff8  ldp        x24, x23, [sp, #0x60]
//   0x6fbc: a94567fa  ldp        x26, x25, [sp, #0x50]
//   0x6fc0: a9446ffc  ldp        x28, x27, [sp, #0x40]
//   0x6fc4: a9437bfd  ldp        x29, x30, [sp, #0x30]
//   0x6fc8: 910243ff  add        sp, sp, #0x90
//   0x6fcc: d65f03c0  ret        
//   0x6fd0: 94000a24  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[41] HeapTrackerFde_6fd4 (0x6fd4..0x7058, 132 bytes, 33 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x6fd4..0x7058
// ----------------------------------------------------------------------------
//   0x6fd4: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x6fd8: f9000bf5  str        x21, [sp, #0x10]
//   0x6fdc: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x6fe0: 910003fd  mov        x29, sp
//   0x6fe4: f9400414  ldr        x20, [x0, #8]
//   0x6fe8: b40002b4  cbz        x20, #0x703c
//   0x6fec: 90ffffe1  adrp       x1, #0x2000
//   0x6ff0: 9106e421  add        x1, x1, #0x1b9
//   0x6ff4: aa1403e0  mov        x0, x20
//   0x6ff8: aa0203f3  mov        x19, x2
//   0x6ffc: 94000a85  bl         #0x9a10
//   0x7000: b4000240  cbz        x0, #0x7048
//   0x7004: 52800300  mov        w0, #0x18
//   0x7008: 94000a22  bl         #0x9890
//   0x700c: b40001c0  cbz        x0, #0x7044
//   0x7010: aa0003f5  mov        x21, x0
//   0x7014: aa1403e0  mov        x0, x20
//   0x7018: 940009ca  bl         #0x9740
//   0x701c: aa0003e8  mov        x8, x0
//   0x7020: 2a1f03e0  mov        w0, wzr
//   0x7024: f9400669  ldr        x9, [x19, #8]
//   0x7028: f9000675  str        x21, [x19, #8]
//   0x702c: f9000aa8  str        x8, [x21, #0x10]
//   0x7030: a90026b3  stp        x19, x9, [x21]
//   0x7034: f9000135  str        x21, [x9]
//   0x7038: 14000004  b          #0x7048
//   0x703c: 2a1f03e0  mov        w0, wzr
//   0x7040: 14000002  b          #0x7048
//   0x7044: 52800020  mov        w0, #1
//   0x7048: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x704c: f9400bf5  ldr        x21, [sp, #0x10]
//   0x7050: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7054: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[42] HeapTrackerFde_7058 (0x7058..0x7128, 208 bytes, 52 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7058..0x7128
// ----------------------------------------------------------------------------
//   0x7058: d503201f  nop        
//   0x705c: 10057f68  adr        x8, #0x12048
//   0x7060: aa0803e9  mov        x9, x8
//   0x7064: f9400129  ldr        x9, [x9]
//   0x7068: eb08013f  cmp        x9, x8
//   0x706c: 54000140  b.eq       #0x7094
//   0x7070: f940092a  ldr        x10, [x9, #0x10]
//   0x7074: eb00015f  cmp        x10, x0
//   0x7078: 54ffff61  b.ne       #0x7064
//   0x707c: f9400d28  ldr        x8, [x9, #0x18]
//   0x7080: f8616900  ldr        x0, [x8, x1]
//   0x7084: b4000082  cbz        x2, #0x7094
//   0x7088: b9406848  ldr        w8, [x2, #0x68]
//   0x708c: 32000108  orr        w8, w8, #1
//   0x7090: b9006848  str        w8, [x2, #0x68]
//   0x7094: d503201f  nop        
//   0x7098: 10057e09  adr        x9, #0x12058
//   0x709c: aa0903ea  mov        x10, x9
//   0x70a0: 14000005  b          #0x70b4
//   0x70a4: f9400d88  ldr        x8, [x12, #0x18]
//   0x70a8: f8616908  ldr        x8, [x8, x1]
//   0x70ac: eb00017f  cmp        x11, x0
//   0x70b0: 54000380  b.eq       #0x7120
//   0x70b4: f940014a  ldr        x10, [x10]
//   0x70b8: eb09015f  cmp        x10, x9
//   0x70bc: 54000300  b.eq       #0x711c
//   0x70c0: f940114b  ldr        x11, [x10, #0x20]
//   0x70c4: eb00017f  cmp        x11, x0
//   0x70c8: 54ffff21  b.ne       #0x70ac
//   0x70cc: f9401548  ldr        x8, [x10, #0x28]
//   0x70d0: 9100414d  add        x13, x10, #0x10
//   0x70d4: aa0d03ec  mov        x12, x13
//   0x70d8: f8616908  ldr        x8, [x8, x1]
//   0x70dc: f940018c  ldr        x12, [x12]
//   0x70e0: eb0d019f  cmp        x12, x13
//   0x70e4: 54000120  b.eq       #0x7108
//   0x70e8: f940098e  ldr        x14, [x12, #0x10]
//   0x70ec: eb0e011f  cmp        x8, x14
//   0x70f0: 54ffff61  b.ne       #0x70dc
//   0x70f4: b4fffd82  cbz        x2, #0x70a4
//   0x70f8: b9406848  ldr        w8, [x2, #0x68]
//   0x70fc: 321e0108  orr        w8, w8, #4
//   0x7100: b9006848  str        w8, [x2, #0x68]
//   0x7104: 17ffffe8  b          #0x70a4
//   0x7108: b4fffd22  cbz        x2, #0x70ac
//   0x710c: b940684c  ldr        w12, [x2, #0x68]
//   0x7110: 321f018c  orr        w12, w12, #2
//   0x7114: b900684c  str        w12, [x2, #0x68]
//   0x7118: 17ffffe5  b          #0x70ac
//   0x711c: d65f03c0  ret        
//   0x7120: aa0803e0  mov        x0, x8
//   0x7124: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[43] HeapTrackerFde_7128 (0x7128..0x71c0, 152 bytes, 38 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7128..0x71c0
// ----------------------------------------------------------------------------
//   0x7128: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x712c: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x7130: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7134: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7138: 910003fd  mov        x29, sp
//   0x713c: d503201f  nop        
//   0x7140: 100578d4  adr        x20, #0x12058
//   0x7144: f9400293  ldr        x19, [x20]
//   0x7148: eb14027f  cmp        x19, x20
//   0x714c: 54000300  b.eq       #0x71ac
//   0x7150: d503201f  nop        
//   0x7154: 10057935  adr        x21, #0x12078
//   0x7158: 14000008  b          #0x7178
//   0x715c: f94002a8  ldr        x8, [x21]
//   0x7160: aa1303e0  mov        x0, x19
//   0x7164: f9400508  ldr        x8, [x8, #8]
//   0x7168: d63f0100  blr        x8
//   0x716c: aa1603f3  mov        x19, x22
//   0x7170: eb1402df  cmp        x22, x20
//   0x7174: 540001c0  b.eq       #0x71ac
//   0x7178: aa1303f7  mov        x23, x19
//   0x717c: f9400276  ldr        x22, [x19]
//   0x7180: f8410ee0  ldr        x0, [x23, #0x10]!
//   0x7184: eb17001f  cmp        x0, x23
//   0x7188: 54fffea0  b.eq       #0x715c
//   0x718c: f94002a8  ldr        x8, [x21]
//   0x7190: f9400018  ldr        x24, [x0]
//   0x7194: f9400508  ldr        x8, [x8, #8]
//   0x7198: d63f0100  blr        x8
//   0x719c: aa1803e0  mov        x0, x24
//   0x71a0: eb17031f  cmp        x24, x23
//   0x71a4: 54ffff41  b.ne       #0x718c
//   0x71a8: 17ffffed  b          #0x715c
//   0x71ac: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x71b0: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x71b4: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x71b8: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x71bc: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[44] HeapTrackerFde_71c0 (0x71c0..0x7340, 384 bytes, 96 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x71c0..0x7340
// ----------------------------------------------------------------------------
//   0x71c0: d10283ff  sub        sp, sp, #0xa0
//   0x71c4: a9057bfd  stp        x29, x30, [sp, #0x50]
//   0x71c8: a90667fa  stp        x26, x25, [sp, #0x60]
//   0x71cc: a9075ff8  stp        x24, x23, [sp, #0x70]
//   0x71d0: a90857f6  stp        x22, x21, [sp, #0x80]
//   0x71d4: a9094ff4  stp        x20, x19, [sp, #0x90]
//   0x71d8: 910143fd  add        x29, sp, #0x50
//   0x71dc: d0000029  adrp       x9, #0xd000
//   0x71e0: d53bd056  mrs        x22, tpidr_el0
//   0x71e4: f94016c8  ldr        x8, [x22, #0x28]
//   0x71e8: f946bd29  ldr        x9, [x9, #0xd78]
//   0x71ec: f81f83a8  stur       x8, [x29, #-8]
//   0x71f0: f9400128  ldr        x8, [x9]
//   0x71f4: b941d913  ldr        w19, [x8, #0x1d8]
//   0x71f8: 37f808d3  tbnz       w19, #0x1f, #0x7310
//   0x71fc: d503201f  nop        
//   0x7200: 10fd5d61  adr        x1, #0x1dac
//   0x7204: 2a1303e0  mov        w0, w19
//   0x7208: 52800562  mov        w2, #0x2b
//   0x720c: 940009d9  bl         #0x9970
//   0x7210: d503201f  nop        
//   0x7214: 100571b5  adr        x21, #0x12048
//   0x7218: f94002b7  ldr        x23, [x21]
//   0x721c: eb1502ff  cmp        x23, x21
//   0x7220: 54000260  b.eq       #0x726c
//   0x7224: d0ffffd4  adrp       x20, #0x1000
//   0x7228: 9130a694  add        x20, x20, #0xc29
//   0x722c: 14000004  b          #0x723c
//   0x7230: f94002f7  ldr        x23, [x23]
//   0x7234: eb1502ff  cmp        x23, x21
//   0x7238: 540001a0  b.eq       #0x726c
//   0x723c: a94116e4  ldp        x4, x5, [x23, #0x10]
//   0x7240: 910023e0  add        x0, sp, #8
//   0x7244: aa1403e3  mov        x3, x20
//   0x7248: 9400003e  bl         #0x7340
//   0x724c: 51000408  sub        w8, w0, #1
//   0x7250: 7100f91f  cmp        w8, #0x3e
//   0x7254: 54fffee8  b.hi       #0x7230
//   0x7258: 2a0003e2  mov        w2, w0
//   0x725c: 910023e1  add        x1, sp, #8
//   0x7260: 2a1303e0  mov        w0, w19
//   0x7264: 940009c3  bl         #0x9970
//   0x7268: 17fffff2  b          #0x7230
//   0x726c: d503201f  nop        
//   0x7270: 10056f57  adr        x23, #0x12058
//   0x7274: f94002f8  ldr        x24, [x23]
//   0x7278: eb17031f  cmp        x24, x23
//   0x727c: 540004a0  b.eq       #0x7310
//   0x7280: d0ffffd4  adrp       x20, #0x1000
//   0x7284: 913f3694  add        x20, x20, #0xfcd
//   0x7288: d0ffffd5  adrp       x21, #0x1000
//   0x728c: 912eceb5  add        x21, x21, #0xbb3
//   0x7290: 14000004  b          #0x72a0
//   0x7294: f9400318  ldr        x24, [x24]
//   0x7298: eb17031f  cmp        x24, x23
//   0x729c: 540003a0  b.eq       #0x7310
//   0x72a0: a9421704  ldp        x4, x5, [x24, #0x20]
//   0x72a4: 910023e0  add        x0, sp, #8
//   0x72a8: aa1403e3  mov        x3, x20
//   0x72ac: 94000025  bl         #0x7340
//   0x72b0: 51000408  sub        w8, w0, #1
//   0x72b4: 7100f91f  cmp        w8, #0x3e
//   0x72b8: 540000a8  b.hi       #0x72cc
//   0x72bc: 2a0003e2  mov        w2, w0
//   0x72c0: 910023e1  add        x1, sp, #8
//   0x72c4: 2a1303e0  mov        w0, w19
//   0x72c8: 940009aa  bl         #0x9970
//   0x72cc: aa1803f9  mov        x25, x24
//   0x72d0: f8410f3a  ldr        x26, [x25, #0x10]!
//   0x72d4: 14000002  b          #0x72dc
//   0x72d8: f940035a  ldr        x26, [x26]
//   0x72dc: eb19035f  cmp        x26, x25
//   0x72e0: 54fffda0  b.eq       #0x7294
//   0x72e4: a9411744  ldp        x4, x5, [x26, #0x10]
//   0x72e8: 910023e0  add        x0, sp, #8
//   0x72ec: aa1503e3  mov        x3, x21
//   0x72f0: 94000014  bl         #0x7340
//   0x72f4: 7100041f  cmp        w0, #1
//   0x72f8: 54ffff0b  b.lt       #0x72d8
//   0x72fc: 2a0003e2  mov        w2, w0
//   0x7300: 910023e1  add        x1, sp, #8
//   0x7304: 2a1303e0  mov        w0, w19
//   0x7308: 9400099a  bl         #0x9970
//   0x730c: 17fffff3  b          #0x72d8
//   0x7310: f94016c8  ldr        x8, [x22, #0x28]
//   0x7314: f85f83a9  ldur       x9, [x29, #-8]
//   0x7318: eb09011f  cmp        x8, x9
//   0x731c: 54000101  b.ne       #0x733c
//   0x7320: a9494ff4  ldp        x20, x19, [sp, #0x90]
//   0x7324: a94857f6  ldp        x22, x21, [sp, #0x80]
//   0x7328: a9475ff8  ldp        x24, x23, [sp, #0x70]
//   0x732c: a94667fa  ldp        x26, x25, [sp, #0x60]
//   0x7330: a9457bfd  ldp        x29, x30, [sp, #0x50]
//   0x7334: 910283ff  add        sp, sp, #0xa0
//   0x7338: d65f03c0  ret        
//   0x733c: 94000949  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[45] HeapTrackerFde_7340 (0x7340..0x73dc, 156 bytes, 39 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7340..0x73dc
// ----------------------------------------------------------------------------
//   0x7340: d10443ff  sub        sp, sp, #0x110
//   0x7344: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x7348: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x734c: 9103c3fd  add        x29, sp, #0xf0
//   0x7350: a9399ba5  stp        x5, x6, [x29, #-0x68]
//   0x7354: d101c3a9  sub        x9, x29, #0x70
//   0x7358: f81903a4  stur       x4, [x29, #-0x70]
//   0x735c: 928003eb  mov        x11, #-0x20
//   0x7360: f81a83a7  stur       x7, [x29, #-0x58]
//   0x7364: 910003ec  mov        x12, sp
//   0x7368: ad0007e0  stp        q0, q1, [sp]
//   0x736c: 91008129  add        x9, x9, #0x20
//   0x7370: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x7374: f2dff00b  movk       x11, #0xff80, lsl #32
//   0x7378: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x737c: 9102018c  add        x12, x12, #0x80
//   0x7380: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x7384: d53bd053  mrs        x19, tpidr_el0
//   0x7388: f9401668  ldr        x8, [x19, #0x28]
//   0x738c: d100a3aa  sub        x10, x29, #0x28
//   0x7390: aa0303e2  mov        x2, x3
//   0x7394: d10143a3  sub        x3, x29, #0x50
//   0x7398: 52800801  mov        w1, #0x40
//   0x739c: f81f83a8  stur       x8, [x29, #-8]
//   0x73a0: 910083a8  add        x8, x29, #0x20
//   0x73a4: a93eafac  stp        x12, x11, [x29, #-0x18]
//   0x73a8: a93da7a8  stp        x8, x9, [x29, #-0x28]
//   0x73ac: ad400540  ldp        q0, q1, [x10]
//   0x73b0: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x73b4: 94000933  bl         #0x9880
//   0x73b8: f9401668  ldr        x8, [x19, #0x28]
//   0x73bc: f85f83a9  ldur       x9, [x29, #-8]
//   0x73c0: eb09011f  cmp        x8, x9
//   0x73c4: 540000a1  b.ne       #0x73d8
//   0x73c8: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x73cc: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x73d0: 910443ff  add        sp, sp, #0x110
//   0x73d4: d65f03c0  ret        
//   0x73d8: 94000922  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[46] HeapTrackerFde_73dc (0x73dc..0x742c, 80 bytes, 20 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x73dc..0x742c
// ----------------------------------------------------------------------------
//   0x73dc: d10083ff  sub        sp, sp, #0x20
//   0x73e0: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x73e4: 910043fd  add        x29, sp, #0x10
//   0x73e8: f90007e0  str        x0, [sp, #8]
//   0x73ec: d503201f  nop        
//   0x73f0: 100566c8  adr        x8, #0x120c8
//   0x73f4: f900011d  str        x29, [x8]
//   0x73f8: f94007e8  ldr        x8, [sp, #8]
//   0x73fc: d2804e60  mov        x0, #0x273
//   0x7400: aa1f03e1  mov        x1, xzr
//   0x7404: aa1f03e2  mov        x2, xzr
//   0x7408: d63f0100  blr        x8
//   0x740c: f90003e0  str        x0, [sp]
//   0x7410: f94003e8  ldr        x8, [sp]
//   0x7414: b4000068  cbz        x8, #0x7420
//   0x7418: f94003e0  ldr        x0, [sp]
//   0x741c: 94000921  bl         #0x98a0
//   0x7420: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x7424: 910083ff  add        sp, sp, #0x20
//   0x7428: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[47] HeapTrackerFde_742c (0x742c..0x746c, 64 bytes, 16 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x742c..0x746c
// ----------------------------------------------------------------------------
//   0x742c: d10083ff  sub        sp, sp, #0x20
//   0x7430: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x7434: 910043fd  add        x29, sp, #0x10
//   0x7438: d503201f  nop        
//   0x743c: 100563e8  adr        x8, #0x120b8
//   0x7440: f900011d  str        x29, [x8]
//   0x7444: d2802820  mov        x0, #0x141
//   0x7448: 94000912  bl         #0x9890
//   0x744c: f90007e0  str        x0, [sp, #8]
//   0x7450: f94007e8  ldr        x8, [sp, #8]
//   0x7454: b4000068  cbz        x8, #0x7460
//   0x7458: f94007e0  ldr        x0, [sp, #8]
//   0x745c: 94000911  bl         #0x98a0
//   0x7460: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x7464: 910083ff  add        sp, sp, #0x20
//   0x7468: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[48] HeapTrackerFde_746c (0x746c..0x74b0, 68 bytes, 17 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x746c..0x74b0
// ----------------------------------------------------------------------------
//   0x746c: d10083ff  sub        sp, sp, #0x20
//   0x7470: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x7474: 910043fd  add        x29, sp, #0x10
//   0x7478: d503201f  nop        
//   0x747c: 100561e8  adr        x8, #0x120b8
//   0x7480: f900011d  str        x29, [x8]
//   0x7484: d2800020  mov        x0, #1
//   0x7488: d2802821  mov        x1, #0x141
//   0x748c: 940008a1  bl         #0x9710
//   0x7490: f90007e0  str        x0, [sp, #8]
//   0x7494: f94007e8  ldr        x8, [sp, #8]
//   0x7498: b4000068  cbz        x8, #0x74a4
//   0x749c: f94007e0  ldr        x0, [sp, #8]
//   0x74a0: 94000900  bl         #0x98a0
//   0x74a4: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x74a8: 910083ff  add        sp, sp, #0x20
//   0x74ac: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[49] HeapTrackerFde_74b0 (0x74b0..0x74f4, 68 bytes, 17 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x74b0..0x74f4
// ----------------------------------------------------------------------------
//   0x74b0: d10083ff  sub        sp, sp, #0x20
//   0x74b4: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x74b8: 910043fd  add        x29, sp, #0x10
//   0x74bc: d503201f  nop        
//   0x74c0: 10055fc8  adr        x8, #0x120b8
//   0x74c4: f900011d  str        x29, [x8]
//   0x74c8: d2800100  mov        x0, #8
//   0x74cc: d2802821  mov        x1, #0x141
//   0x74d0: 940008fc  bl         #0x98c0
//   0x74d4: f90007e0  str        x0, [sp, #8]
//   0x74d8: f94007e8  ldr        x8, [sp, #8]
//   0x74dc: b4000068  cbz        x8, #0x74e8
//   0x74e0: f94007e0  ldr        x0, [sp, #8]
//   0x74e4: 940008ef  bl         #0x98a0
//   0x74e8: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x74ec: 910083ff  add        sp, sp, #0x20
//   0x74f0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[50] HeapTrackerFde_74f4 (0x74f4..0x7538, 68 bytes, 17 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x74f4..0x7538
// ----------------------------------------------------------------------------
//   0x74f4: d10083ff  sub        sp, sp, #0x20
//   0x74f8: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x74fc: 910043fd  add        x29, sp, #0x10
//   0x7500: d503201f  nop        
//   0x7504: 10055da8  adr        x8, #0x120b8
//   0x7508: f900011d  str        x29, [x8]
//   0x750c: aa1f03e0  mov        x0, xzr
//   0x7510: d2802821  mov        x1, #0x141
//   0x7514: 940008e7  bl         #0x98b0
//   0x7518: f90007e0  str        x0, [sp, #8]
//   0x751c: f94007e8  ldr        x8, [sp, #8]
//   0x7520: b4000068  cbz        x8, #0x752c
//   0x7524: f94007e0  ldr        x0, [sp, #8]
//   0x7528: 940008de  bl         #0x98a0
//   0x752c: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x7530: 910083ff  add        sp, sp, #0x20
//   0x7534: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[51] HeapTrackerFde_7538 (0x7538..0x75b0, 120 bytes, 30 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7538..0x75b0
// ----------------------------------------------------------------------------
//   0x7538: d100c3ff  sub        sp, sp, #0x30
//   0x753c: a9027bfd  stp        x29, x30, [sp, #0x20]
//   0x7540: 910083fd  add        x29, sp, #0x20
//   0x7544: d53bd048  mrs        x8, tpidr_el0
//   0x7548: f9401508  ldr        x8, [x8, #0x28]
//   0x754c: f81f83a8  stur       x8, [x29, #-8]
//   0x7550: f0000048  adrp       x8, #0x12000
//   0x7554: f9005d1d  str        x29, [x8, #0xb8]
//   0x7558: d0000028  adrp       x8, #0xd000
//   0x755c: f946c108  ldr        x8, [x8, #0xd80]
//   0x7560: b4000168  cbz        x8, #0x758c
//   0x7564: 14000001  b          #0x7568
//   0x7568: 910043e0  add        x0, sp, #0x10
//   0x756c: d2800101  mov        x1, #8
//   0x7570: d2802822  mov        x2, #0x141
//   0x7574: 940008d7  bl         #0x98d0
//   0x7578: b9000fe0  str        w0, [sp, #0xc]
//   0x757c: b9400fe8  ldr        w8, [sp, #0xc]
//   0x7580: 35000068  cbnz       w8, #0x758c
//   0x7584: f9400be0  ldr        x0, [sp, #0x10]
//   0x7588: 940008c6  bl         #0x98a0
//   0x758c: d53bd048  mrs        x8, tpidr_el0
//   0x7590: f9401508  ldr        x8, [x8, #0x28]
//   0x7594: f85f83a9  ldur       x9, [x29, #-8]
//   0x7598: eb09011f  cmp        x8, x9
//   0x759c: 54000081  b.ne       #0x75ac
//   0x75a0: a9427bfd  ldp        x29, x30, [sp, #0x20]
//   0x75a4: 9100c3ff  add        sp, sp, #0x30
//   0x75a8: d65f03c0  ret        
//   0x75ac: 940008ad  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[52] HeapTrackerFde_75b0 (0x75b0..0x7618, 104 bytes, 26 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x75b0..0x7618
// ----------------------------------------------------------------------------
//   0x75b0: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x75b4: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x75b8: 910003fd  mov        x29, sp
//   0x75bc: f0000048  adrp       x8, #0x12000
//   0x75c0: f9406d00  ldr        x0, [x8, #0xd8]
//   0x75c4: b4000220  cbz        x0, #0x7608
//   0x75c8: 52880001  mov        w1, #0x4000
//   0x75cc: 72a00101  movk       w1, #8, lsl #16
//   0x75d0: 940008e0  bl         #0x9950
//   0x75d4: 37f801a0  tbnz       w0, #0x1f, #0x7608
//   0x75d8: 52804842  mov        w2, #0x242
//   0x75dc: d503201f  nop        
//   0x75e0: 10fd4941  adr        x1, #0x1f08
//   0x75e4: 72a00102  movk       w2, #8, lsl #16
//   0x75e8: 52803003  mov        w3, #0x180
//   0x75ec: 2a0003f3  mov        w19, w0
//   0x75f0: 940008c0  bl         #0x98f0
//   0x75f4: 2a0003f4  mov        w20, w0
//   0x75f8: 2a1303e0  mov        w0, w19
//   0x75fc: 940008c1  bl         #0x9900
//   0x7600: 2a1403e0  mov        w0, w20
//   0x7604: 14000002  b          #0x760c
//   0x7608: 12800000  mov        w0, #-1
//   0x760c: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x7610: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7614: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[53] HeapTrackerFde_7618 (0x7618..0x7684, 108 bytes, 27 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7618..0x7684
// ----------------------------------------------------------------------------
//   0x7618: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x761c: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x7620: 910003fd  mov        x29, sp
//   0x7624: f0000048  adrp       x8, #0x12000
//   0x7628: f9406d08  ldr        x8, [x8, #0xd8]
//   0x762c: b4000248  cbz        x8, #0x7674
//   0x7630: 52880001  mov        w1, #0x4000
//   0x7634: aa0003f3  mov        x19, x0
//   0x7638: aa0803e0  mov        x0, x8
//   0x763c: 72a00101  movk       w1, #8, lsl #16
//   0x7640: 940008c4  bl         #0x9950
//   0x7644: 37f80180  tbnz       w0, #0x1f, #0x7674
//   0x7648: 52804842  mov        w2, #0x242
//   0x764c: aa1303e1  mov        x1, x19
//   0x7650: 72a00102  movk       w2, #8, lsl #16
//   0x7654: 52803003  mov        w3, #0x180
//   0x7658: 2a0003f4  mov        w20, w0
//   0x765c: 940008a5  bl         #0x98f0
//   0x7660: 2a0003f3  mov        w19, w0
//   0x7664: 2a1403e0  mov        w0, w20
//   0x7668: 940008a6  bl         #0x9900
//   0x766c: 2a1303e0  mov        w0, w19
//   0x7670: 14000002  b          #0x7678
//   0x7674: 12800000  mov        w0, #-1
//   0x7678: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x767c: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7680: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[54] HeapTrackerFde_7684 (0x7684..0x7690, 12 bytes, 3 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7684..0x7690
// ----------------------------------------------------------------------------
//   0x7684: f0000048  adrp       x8, #0x12000
//   0x7688: f9406d00  ldr        x0, [x8, #0xd8]
//   0x768c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[55] HeapTrackerFde_7690 (0x7690..0x76f4, 100 bytes, 25 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7690..0x76f4
// ----------------------------------------------------------------------------
//   0x7690: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7694: f9000bf3  str        x19, [sp, #0x10]
//   0x7698: 910003fd  mov        x29, sp
//   0x769c: f0000053  adrp       x19, #0x12000
//   0x76a0: 52803801  mov        w1, #0x1c0
//   0x76a4: f9406e60  ldr        x0, [x19, #0xd8]
//   0x76a8: 940008e2  bl         #0x9a30
//   0x76ac: 340001e0  cbz        w0, #0x76e8
//   0x76b0: 94000864  bl         #0x9840
//   0x76b4: b9400008  ldr        w8, [x0]
//   0x76b8: 7100451f  cmp        w8, #0x11
//   0x76bc: 54000061  b.ne       #0x76c8
//   0x76c0: 2a1f03e0  mov        w0, wzr
//   0x76c4: 14000009  b          #0x76e8
//   0x76c8: f9406e63  ldr        x3, [x19, #0xd8]
//   0x76cc: d0ffffc1  adrp       x1, #0x1000
//   0x76d0: 9127f021  add        x1, x1, #0x9fc
//   0x76d4: f0ffffc2  adrp       x2, #0x2000
//   0x76d8: 91186042  add        x2, x2, #0x618
//   0x76dc: 528000c0  mov        w0, #6
//   0x76e0: 9400082c  bl         #0x9790
//   0x76e4: 12800000  mov        w0, #-1
//   0x76e8: f9400bf3  ldr        x19, [sp, #0x10]
//   0x76ec: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x76f0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[56] HeapTrackerFde_76f4 (0x76f4..0x7710, 28 bytes, 7 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x76f4..0x7710
// ----------------------------------------------------------------------------
//   0x76f4: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x76f8: 910003fd  mov        x29, sp
//   0x76fc: 94000811  bl         #0x9740
//   0x7700: f0000048  adrp       x8, #0x12000
//   0x7704: f9006d00  str        x0, [x8, #0xd8]
//   0x7708: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x770c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[57] HeapTrackerFde_7710 (0x7710..0x7924, 532 bytes, 133 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7710..0x7924
// ----------------------------------------------------------------------------
//   0x7710: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x7714: f9000bfc  str        x28, [sp, #0x10]
//   0x7718: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x771c: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x7720: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x7724: 910003fd  mov        x29, sp
//   0x7728: d11043ff  sub        sp, sp, #0x410
//   0x772c: d0000036  adrp       x22, #0xd000
//   0x7730: d53bd055  mrs        x21, tpidr_el0
//   0x7734: f94016a8  ldr        x8, [x21, #0x28]
//   0x7738: d503201f  nop        
//   0x773c: 70fd5da1  adr        x1, #0x22f3
//   0x7740: 528016a2  mov        w2, #0xb5
//   0x7744: f946bed6  ldr        x22, [x22, #0xd78]
//   0x7748: f81f83a8  stur       x8, [x29, #-8]
//   0x774c: f94002c8  ldr        x8, [x22]
//   0x7750: b941d913  ldr        w19, [x8, #0x1d8]
//   0x7754: 2a1303e0  mov        w0, w19
//   0x7758: 94000886  bl         #0x9970
//   0x775c: f94002ca  ldr        x10, [x22]
//   0x7760: f9403d48  ldr        x8, [x10, #0x78]
//   0x7764: 9101c149  add        x9, x10, #0x70
//   0x7768: eb09011f  cmp        x8, x9
//   0x776c: 540006c0  b.eq       #0x7844
//   0x7770: 910023ea  add        x10, sp, #8
//   0x7774: 14000005  b          #0x7788
//   0x7778: f9400108  ldr        x8, [x8]
//   0x777c: f9400508  ldr        x8, [x8, #8]
//   0x7780: eb09011f  cmp        x8, x9
//   0x7784: 540005e0  b.eq       #0x7840
//   0x7788: f940012b  ldr        x11, [x9]
//   0x778c: eb09017f  cmp        x11, x9
//   0x7790: fa481164  ccmp       x11, x8, #4, ne
//   0x7794: 54ffff40  b.eq       #0x777c
//   0x7798: f940016c  ldr        x12, [x11]
//   0x779c: f940116d  ldr        x13, [x11, #0x20]
//   0x77a0: f940118e  ldr        x14, [x12, #0x20]
//   0x77a4: eb0e01bf  cmp        x13, x14
//   0x77a8: 54000402  b.hs       #0x7828
//   0x77ac: f940058d  ldr        x13, [x12, #8]
//   0x77b0: f900058a  str        x10, [x12, #8]
//   0x77b4: a900b7ec  stp        x12, x13, [sp, #8]
//   0x77b8: f90001aa  str        x10, [x13]
//   0x77bc: f940018d  ldr        x13, [x12]
//   0x77c0: f90005aa  str        x10, [x13, #8]
//   0x77c4: f940058e  ldr        x14, [x12, #8]
//   0x77c8: f90001cd  str        x13, [x14]
//   0x77cc: f940056d  ldr        x13, [x11, #8]
//   0x77d0: f900056c  str        x12, [x11, #8]
//   0x77d4: a900358b  stp        x11, x13, [x12]
//   0x77d8: f90001ac  str        x12, [x13]
//   0x77dc: a940316d  ldp        x13, x12, [x11]
//   0x77e0: f90005ac  str        x12, [x13, #8]
//   0x77e4: f940056c  ldr        x12, [x11, #8]
//   0x77e8: f900018d  str        x13, [x12]
//   0x77ec: f9400bec  ldr        x12, [sp, #0x10]
//   0x77f0: f9000beb  str        x11, [sp, #0x10]
//   0x77f4: a900316a  stp        x10, x12, [x11]
//   0x77f8: f900018b  str        x11, [x12]
//   0x77fc: f94007ec  ldr        x12, [sp, #8]
//   0x7800: f900058b  str        x11, [x12, #8]
//   0x7804: f9400bed  ldr        x13, [sp, #0x10]
//   0x7808: f90001ac  str        x12, [x13]
//   0x780c: f940056b  ldr        x11, [x11, #8]
//   0x7810: eb08017f  cmp        x11, x8
//   0x7814: 54fffb20  b.eq       #0x7778
//   0x7818: f940016b  ldr        x11, [x11]
//   0x781c: eb09017f  cmp        x11, x9
//   0x7820: 540000a1  b.ne       #0x7834
//   0x7824: 17ffffd6  b          #0x777c
//   0x7828: aa0c03eb  mov        x11, x12
//   0x782c: eb09017f  cmp        x11, x9
//   0x7830: 54fffa60  b.eq       #0x777c
//   0x7834: eb08017f  cmp        x11, x8
//   0x7838: 54fffb01  b.ne       #0x7798
//   0x783c: 17ffffd0  b          #0x777c
//   0x7840: f94002ca  ldr        x10, [x22]
//   0x7844: aa0a03e8  mov        x8, x10
//   0x7848: f8470d17  ldr        x23, [x8, #0x70]!
//   0x784c: eb0802ff  cmp        x23, x8
//   0x7850: 54000520  b.eq       #0x78f4
//   0x7854: f9407109  ldr        x9, [x8, #0xe0]
//   0x7858: d0ffffd4  adrp       x20, #0x1000
//   0x785c: 912f4e94  add        x20, x20, #0xbd3
//   0x7860: f940850b  ldr        x11, [x8, #0x108]
//   0x7864: f9401d08  ldr        x8, [x8, #0x38]
//   0x7868: cb0b0129  sub        x9, x9, x11
//   0x786c: 9ac80938  udiv       x24, x9, x8
//   0x7870: 14000006  b          #0x7888
//   0x7874: f94002ca  ldr        x10, [x22]
//   0x7878: f94002f7  ldr        x23, [x23]
//   0x787c: 9101c148  add        x8, x10, #0x70
//   0x7880: eb0802ff  cmp        x23, x8
//   0x7884: 54000380  b.eq       #0x78f4
//   0x7888: f9409948  ldr        x8, [x10, #0x130]
//   0x788c: b5000128  cbnz       x8, #0x78b0
//   0x7890: f94022e8  ldr        x8, [x23, #0x40]
//   0x7894: f9009948  str        x8, [x10, #0x130]
//   0x7898: f94012e8  ldr        x8, [x23, #0x20]
//   0x789c: f9009d48  str        x8, [x10, #0x138]
//   0x78a0: b9404ae8  ldr        w8, [x23, #0x48]
//   0x78a4: b9012948  str        w8, [x10, #0x128]
//   0x78a8: 3cc282e0  ldur       q0, [x23, #0x28]
//   0x78ac: 3d805140  str        q0, [x10, #0x140]
//   0x78b0: f94012e4  ldr        x4, [x23, #0x20]
//   0x78b4: eb18009f  cmp        x4, x24
//   0x78b8: 540001e3  b.lo       #0x78f4
//   0x78bc: a9439ae5  ldp        x5, x6, [x23, #0x38]
//   0x78c0: 910023e0  add        x0, sp, #8
//   0x78c4: 52808001  mov        w1, #0x400
//   0x78c8: b9404ae7  ldr        w7, [x23, #0x48]
//   0x78cc: 52808002  mov        w2, #0x400
//   0x78d0: aa1403e3  mov        x3, x20
//   0x78d4: 940000ee  bl         #0x7c8c
//   0x78d8: 7100041f  cmp        w0, #1
//   0x78dc: 54fffccb  b.lt       #0x7874
//   0x78e0: 2a0003e2  mov        w2, w0
//   0x78e4: 910023e1  add        x1, sp, #8
//   0x78e8: 2a1303e0  mov        w0, w19
//   0x78ec: 94000821  bl         #0x9970
//   0x78f0: 17ffffe1  b          #0x7874
//   0x78f4: f94016a8  ldr        x8, [x21, #0x28]
//   0x78f8: f85f83a9  ldur       x9, [x29, #-8]
//   0x78fc: eb09011f  cmp        x8, x9
//   0x7900: 54000101  b.ne       #0x7920
//   0x7904: 911043ff  add        sp, sp, #0x410
//   0x7908: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x790c: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x7910: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x7914: f9400bfc  ldr        x28, [sp, #0x10]
//   0x7918: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x791c: d65f03c0  ret        
//   0x7920: 940007d0  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[58] HeapTrackerFde_7924 (0x7924..0x7a0c, 232 bytes, 58 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7924..0x7a0c
// ----------------------------------------------------------------------------
//   0x7924: d101c3ff  sub        sp, sp, #0x70
//   0x7928: a9047bfd  stp        x29, x30, [sp, #0x40]
//   0x792c: a90557f6  stp        x22, x21, [sp, #0x50]
//   0x7930: a9064ff4  stp        x20, x19, [sp, #0x60]
//   0x7934: 910103fd  add        x29, sp, #0x40
//   0x7938: d0000036  adrp       x22, #0xd000
//   0x793c: d53bd055  mrs        x21, tpidr_el0
//   0x7940: f94016a8  ldr        x8, [x21, #0x28]
//   0x7944: f946bed6  ldr        x22, [x22, #0xd78]
//   0x7948: f81f83a8  stur       x8, [x29, #-8]
//   0x794c: f94002c8  ldr        x8, [x22]
//   0x7950: f9403500  ldr        x0, [x8, #0x68]
//   0x7954: b4000480  cbz        x0, #0x79e4
//   0x7958: f9404109  ldr        x9, [x8, #0x80]
//   0x795c: b4000449  cbz        x9, #0x79e4
//   0x7960: f9404508  ldr        x8, [x8, #0x88]
//   0x7964: d63f0100  blr        x8
//   0x7968: 94000836  bl         #0x9a40
//   0x796c: aa0003f3  mov        x19, x0
//   0x7970: f9400400  ldr        x0, [x0, #8]
//   0x7974: b5ffffc0  cbnz       x0, #0x796c
//   0x7978: f94002c8  ldr        x8, [x22]
//   0x797c: f9404108  ldr        x8, [x8, #0x80]
//   0x7980: aa1303e0  mov        x0, x19
//   0x7984: d63f0100  blr        x8
//   0x7988: 2a0003f4  mov        w20, w0
//   0x798c: 910003e1  mov        x1, sp
//   0x7990: aa1303e0  mov        x0, x19
//   0x7994: 9400082f  bl         #0x9a50
//   0x7998: 52800020  mov        w0, #1
//   0x799c: 52800a01  mov        w1, #0x50
//   0x79a0: 9400075c  bl         #0x9710
//   0x79a4: a940abe9  ldp        x9, x10, [sp, #8]
//   0x79a8: b9004814  str        w20, [x0, #0x48]
//   0x79ac: f94002c8  ldr        x8, [x22]
//   0x79b0: 8b09014a  add        x10, x10, x9
//   0x79b4: aa0803eb  mov        x11, x8
//   0x79b8: a9012809  stp        x9, x10, [x0, #0x10]
//   0x79bc: f8470d69  ldr        x9, [x11, #0x70]!
//   0x79c0: a9002c09  stp        x9, x11, [x0]
//   0x79c4: f9400169  ldr        x9, [x11]
//   0x79c8: f9000520  str        x0, [x9, #8]
//   0x79cc: f9000160  str        x0, [x11]
//   0x79d0: f9400273  ldr        x19, [x19]
//   0x79d4: b5fffd53  cbnz       x19, #0x797c
//   0x79d8: f9404909  ldr        x9, [x8, #0x90]
//   0x79dc: f9403500  ldr        x0, [x8, #0x68]
//   0x79e0: d63f0120  blr        x9
//   0x79e4: f94016a8  ldr        x8, [x21, #0x28]
//   0x79e8: f85f83a9  ldur       x9, [x29, #-8]
//   0x79ec: eb09011f  cmp        x8, x9
//   0x79f0: 540000c1  b.ne       #0x7a08
//   0x79f4: a9464ff4  ldp        x20, x19, [sp, #0x60]
//   0x79f8: a94557f6  ldp        x22, x21, [sp, #0x50]
//   0x79fc: a9447bfd  ldp        x29, x30, [sp, #0x40]
//   0x7a00: 9101c3ff  add        sp, sp, #0x70
//   0x7a04: d65f03c0  ret        
//   0x7a08: 94000796  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[59] HeapTrackerFde_7a0c (0x7a0c..0x7abc, 176 bytes, 44 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7a0c..0x7abc
// ----------------------------------------------------------------------------
//   0x7a0c: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x7a10: a9014ff4  stp        x20, x19, [sp, #0x10]
//   0x7a14: 910003fd  mov        x29, sp
//   0x7a18: d0ffffc0  adrp       x0, #0x1000
//   0x7a1c: 912d0800  add        x0, x0, #0xb42
//   0x7a20: 9400074c  bl         #0x9750
//   0x7a24: b4000460  cbz        x0, #0x7ab0
//   0x7a28: d0ffffc1  adrp       x1, #0x1000
//   0x7a2c: 913c4c21  add        x1, x1, #0xf13
//   0x7a30: aa0003f3  mov        x19, x0
//   0x7a34: 9400080b  bl         #0x9a60
//   0x7a38: d0000034  adrp       x20, #0xd000
//   0x7a3c: f0ffffc1  adrp       x1, #0x2000
//   0x7a40: 910ea421  add        x1, x1, #0x3a9
//   0x7a44: f946be94  ldr        x20, [x20, #0xd78]
//   0x7a48: f9400288  ldr        x8, [x20]
//   0x7a4c: f9003500  str        x0, [x8, #0x68]
//   0x7a50: aa1303e0  mov        x0, x19
//   0x7a54: 94000807  bl         #0x9a70
//   0x7a58: d000002a  adrp       x10, #0xd000
//   0x7a5c: f9400289  ldr        x9, [x20]
//   0x7a60: d000002b  adrp       x11, #0xd000
//   0x7a64: d000002c  adrp       x12, #0xd000
//   0x7a68: d000002d  adrp       x13, #0xd000
//   0x7a6c: aa0003e8  mov        x8, x0
//   0x7a70: f946b14a  ldr        x10, [x10, #0xd60]
//   0x7a74: aa1303e0  mov        x0, x19
//   0x7a78: f946c96b  ldr        x11, [x11, #0xd90]
//   0x7a7c: b940014a  ldr        w10, [x10]
//   0x7a80: f946e18c  ldr        x12, [x12, #0xdc0]
//   0x7a84: f946c5ad  ldr        x13, [x13, #0xd88]
//   0x7a88: 7100655f  cmp        w10, #0x19
//   0x7a8c: d000002a  adrp       x10, #0xd000
//   0x7a90: 9a8bc18b  csel       x11, x12, x11, gt
//   0x7a94: f946e54a  ldr        x10, [x10, #0xdc8]
//   0x7a98: 9a8dc14a  csel       x10, x10, x13, gt
//   0x7a9c: a908ad2a  stp        x10, x11, [x9, #0x88]
//   0x7aa0: f9004128  str        x8, [x9, #0x80]
//   0x7aa4: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x7aa8: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7aac: 14000755  b          #0x9800
//   0x7ab0: a9414ff4  ldp        x20, x19, [sp, #0x10]
//   0x7ab4: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x7ab8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[60] HeapTrackerFde_7abc (0x7abc..0x7c8c, 464 bytes, 116 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7abc..0x7c8c
// ----------------------------------------------------------------------------
//   0x7abc: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x7ac0: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x7ac4: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x7ac8: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x7acc: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x7ad0: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x7ad4: 910003fd  mov        x29, sp
//   0x7ad8: d11043ff  sub        sp, sp, #0x410
//   0x7adc: d0000029  adrp       x9, #0xd000
//   0x7ae0: d53bd05a  mrs        x26, tpidr_el0
//   0x7ae4: f9401748  ldr        x8, [x26, #0x28]
//   0x7ae8: 2a0003f4  mov        w20, w0
//   0x7aec: f946bd29  ldr        x9, [x9, #0xd78]
//   0x7af0: f81f83a8  stur       x8, [x29, #-8]
//   0x7af4: f9400128  ldr        x8, [x9]
//   0x7af8: f8470d1b  ldr        x27, [x8, #0x70]!
//   0x7afc: b9416913  ldr        w19, [x8, #0x168]
//   0x7b00: eb08037f  cmp        x27, x8
//   0x7b04: 54000500  b.eq       #0x7ba4
//   0x7b08: aa0403f5  mov        x21, x4
//   0x7b0c: aa0303f6  mov        x22, x3
//   0x7b10: aa0203f7  mov        x23, x2
//   0x7b14: 14000004  b          #0x7b24
//   0x7b18: f940037b  ldr        x27, [x27]
//   0x7b1c: eb08037f  cmp        x27, x8
//   0x7b20: 54000420  b.eq       #0x7ba4
//   0x7b24: f9400b69  ldr        x9, [x27, #0x10]
//   0x7b28: eb01013f  cmp        x9, x1
//   0x7b2c: 54ffff62  b.hs       #0x7b18
//   0x7b30: f9400f69  ldr        x9, [x27, #0x18]
//   0x7b34: eb01013f  cmp        x9, x1
//   0x7b38: 54ffff09  b.ls       #0x7b18
//   0x7b3c: f9402368  ldr        x8, [x27, #0x40]
//   0x7b40: b5000508  cbnz       x8, #0x7be0
//   0x7b44: b9404b64  ldr        w4, [x27, #0x48]
//   0x7b48: d0ffffc3  adrp       x3, #0x1000
//   0x7b4c: 91316063  add        x3, x3, #0xc58
//   0x7b50: 910023e0  add        x0, sp, #8
//   0x7b54: 52800801  mov        w1, #0x40
//   0x7b58: 52800802  mov        w2, #0x40
//   0x7b5c: 9400004c  bl         #0x7c8c
//   0x7b60: 910023e0  add        x0, sp, #8
//   0x7b64: 52a00101  mov        w1, #0x80000
//   0x7b68: 9400077a  bl         #0x9950
//   0x7b6c: 37f80220  tbnz       w0, #0x1f, #0x7bb0
//   0x7b70: 910023e1  add        x1, sp, #8
//   0x7b74: 52800802  mov        w2, #0x40
//   0x7b78: 2a0003f9  mov        w25, w0
//   0x7b7c: 94000779  bl         #0x9960
//   0x7b80: aa0003f8  mov        x24, x0
//   0x7b84: 2a1903e0  mov        w0, w25
//   0x7b88: 9400075e  bl         #0x9900
//   0x7b8c: f1000708  subs       x8, x24, #1
//   0x7b90: 5400010b  b.lt       #0x7bb0
//   0x7b94: f101031f  cmp        x24, #0x40
//   0x7b98: 54000101  b.ne       #0x7bb8
//   0x7b9c: 528007e8  mov        w8, #0x3f
//   0x7ba0: 1400000a  b          #0x7bc8
//   0x7ba4: aa1f03fb  mov        x27, xzr
//   0x7ba8: 35000314  cbnz       w20, #0x7c08
//   0x7bac: 1400002b  b          #0x7c58
//   0x7bb0: aa1f03e0  mov        x0, xzr
//   0x7bb4: 1400000a  b          #0x7bdc
//   0x7bb8: 910023e9  add        x9, sp, #8
//   0x7bbc: 38686929  ldrb       w9, [x9, x8]
//   0x7bc0: 7100293f  cmp        w9, #0xa
//   0x7bc4: 54000041  b.ne       #0x7bcc
//   0x7bc8: aa0803f8  mov        x24, x8
//   0x7bcc: 910023e0  add        x0, sp, #8
//   0x7bd0: 910023e8  add        x8, sp, #8
//   0x7bd4: 3838691f  strb       wzr, [x8, x24]
//   0x7bd8: 940006da  bl         #0x9740
//   0x7bdc: f9002360  str        x0, [x27, #0x40]
//   0x7be0: f9401368  ldr        x8, [x27, #0x20]
//   0x7be4: 9100a360  add        x0, x27, #0x28
//   0x7be8: aa1603e1  mov        x1, x22
//   0x7bec: 8b170108  add        x8, x8, x23
//   0x7bf0: f9001368  str        x8, [x27, #0x20]
//   0x7bf4: 97fff35a  bl         #0x495c
//   0x7bf8: f9401f68  ldr        x8, [x27, #0x38]
//   0x7bfc: 8b150108  add        x8, x8, x21
//   0x7c00: f9001f68  str        x8, [x27, #0x38]
//   0x7c04: 340002b4  cbz        w20, #0x7c58
//   0x7c08: 37f80293  tbnz       w19, #0x1f, #0x7c58
//   0x7c0c: b400009b  cbz        x27, #0x7c1c
//   0x7c10: f9402364  ldr        x4, [x27, #0x40]
//   0x7c14: b9404b65  ldr        w5, [x27, #0x48]
//   0x7c18: 14000004  b          #0x7c28
//   0x7c1c: 2a1f03e5  mov        w5, wzr
//   0x7c20: d0ffffc4  adrp       x4, #0x1000
//   0x7c24: 91292084  add        x4, x4, #0xa48
//   0x7c28: d0ffffc3  adrp       x3, #0x1000
//   0x7c2c: 9127c063  add        x3, x3, #0x9f0
//   0x7c30: 910023e0  add        x0, sp, #8
//   0x7c34: 52808001  mov        w1, #0x400
//   0x7c38: 52808002  mov        w2, #0x400
//   0x7c3c: 94000014  bl         #0x7c8c
//   0x7c40: 7100041f  cmp        w0, #1
//   0x7c44: 540000ab  b.lt       #0x7c58
//   0x7c48: 2a0003e2  mov        w2, w0
//   0x7c4c: 910023e1  add        x1, sp, #8
//   0x7c50: 2a1303e0  mov        w0, w19
//   0x7c54: 94000747  bl         #0x9970
//   0x7c58: f9401748  ldr        x8, [x26, #0x28]
//   0x7c5c: f85f83a9  ldur       x9, [x29, #-8]
//   0x7c60: eb09011f  cmp        x8, x9
//   0x7c64: 54000121  b.ne       #0x7c88
//   0x7c68: 911043ff  add        sp, sp, #0x410
//   0x7c6c: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x7c70: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x7c74: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x7c78: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x7c7c: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x7c80: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x7c84: d65f03c0  ret        
//   0x7c88: 940006f6  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[61] HeapTrackerFde_7c8c (0x7c8c..0x7d30, 164 bytes, 41 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7c8c..0x7d30
// ----------------------------------------------------------------------------
//   0x7c8c: d10443ff  sub        sp, sp, #0x110
//   0x7c90: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x7c94: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x7c98: 9103c3fd  add        x29, sp, #0xf0
//   0x7c9c: a93917a4  stp        x4, x5, [x29, #-0x70]
//   0x7ca0: d101c3aa  sub        x10, x29, #0x70
//   0x7ca4: a93a1fa6  stp        x6, x7, [x29, #-0x60]
//   0x7ca8: 928003ec  mov        x12, #-0x20
//   0x7cac: ad0007e0  stp        q0, q1, [sp]
//   0x7cb0: 910003ed  mov        x13, sp
//   0x7cb4: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x7cb8: 9100814a  add        x10, x10, #0x20
//   0x7cbc: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x7cc0: f2dff00c  movk       x12, #0xff80, lsl #32
//   0x7cc4: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x7cc8: d53bd053  mrs        x19, tpidr_el0
//   0x7ccc: f9401669  ldr        x9, [x19, #0x28]
//   0x7cd0: 910201ad  add        x13, x13, #0x80
//   0x7cd4: d100a3ab  sub        x11, x29, #0x28
//   0x7cd8: aa0303e8  mov        x8, x3
//   0x7cdc: aa0103e3  mov        x3, x1
//   0x7ce0: d10143a5  sub        x5, x29, #0x50
//   0x7ce4: f81f83a9  stur       x9, [x29, #-8]
//   0x7ce8: 910083a9  add        x9, x29, #0x20
//   0x7cec: a93eb3ad  stp        x13, x12, [x29, #-0x18]
//   0x7cf0: aa0203e1  mov        x1, x2
//   0x7cf4: 2a1f03e2  mov        w2, wzr
//   0x7cf8: aa0803e4  mov        x4, x8
//   0x7cfc: a93daba9  stp        x9, x10, [x29, #-0x28]
//   0x7d00: ad400560  ldp        q0, q1, [x11]
//   0x7d04: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x7d08: 9400071e  bl         #0x9980
//   0x7d0c: f9401668  ldr        x8, [x19, #0x28]
//   0x7d10: f85f83a9  ldur       x9, [x29, #-8]
//   0x7d14: eb09011f  cmp        x8, x9
//   0x7d18: 540000a1  b.ne       #0x7d2c
//   0x7d1c: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x7d20: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x7d24: 910443ff  add        sp, sp, #0x110
//   0x7d28: d65f03c0  ret        
//   0x7d2c: 940006cd  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[62] HeapTrackerFde_7d30 (0x7d30..0x7da4, 116 bytes, 29 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7d30..0x7da4
// ----------------------------------------------------------------------------
//   0x7d30: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x7d34: f9000bf5  str        x21, [sp, #0x10]
//   0x7d38: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x7d3c: 910003fd  mov        x29, sp
//   0x7d40: d503201f  nop        
//   0x7d44: 10051af4  adr        x20, #0x120a0
//   0x7d48: f9400288  ldr        x8, [x20]
//   0x7d4c: f8470d13  ldr        x19, [x8, #0x70]!
//   0x7d50: eb08027f  cmp        x19, x8
//   0x7d54: 54000181  b.ne       #0x7d84
//   0x7d58: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x7d5c: f9400bf5  ldr        x21, [sp, #0x10]
//   0x7d60: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x7d64: d65f03c0  ret        
//   0x7d68: aa1303e0  mov        x0, x19
//   0x7d6c: 940006cd  bl         #0x98a0
//   0x7d70: f9400288  ldr        x8, [x20]
//   0x7d74: aa1503f3  mov        x19, x21
//   0x7d78: 9101c108  add        x8, x8, #0x70
//   0x7d7c: eb0802bf  cmp        x21, x8
//   0x7d80: 54fffec0  b.eq       #0x7d58
//   0x7d84: a9402275  ldp        x21, x8, [x19]
//   0x7d88: f9402260  ldr        x0, [x19, #0x40]
//   0x7d8c: f90006a8  str        x8, [x21, #8]
//   0x7d90: f9400668  ldr        x8, [x19, #8]
//   0x7d94: f9000115  str        x21, [x8]
//   0x7d98: b4fffe80  cbz        x0, #0x7d68
//   0x7d9c: 940006c1  bl         #0x98a0
//   0x7da0: 17fffff2  b          #0x7d68

// ----------------------------------------------------------------------------
// FDE[63] HeapTrackerFde_7da4 (0x7da4..0x8140, 924 bytes, 231 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x7da4..0x8140
// ----------------------------------------------------------------------------
//   0x7da4: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x7da8: a9015ff8  stp        x24, x23, [sp, #0x10]
//   0x7dac: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x7db0: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x7db4: 910003fd  mov        x29, sp
//   0x7db8: b4001900  cbz        x0, #0x80d8
//   0x7dbc: d0000038  adrp       x24, #0xd000
//   0x7dc0: aa0003f7  mov        x23, x0
//   0x7dc4: aa0303f5  mov        x21, x3
//   0x7dc8: aa0203f6  mov        x22, x2
//   0x7dcc: aa0103f4  mov        x20, x1
//   0x7dd0: f946bf18  ldr        x24, [x24, #0xd78]
//   0x7dd4: f9400308  ldr        x8, [x24]
//   0x7dd8: 9100c100  add        x0, x8, #0x30
//   0x7ddc: 940006f1  bl         #0x99a0
//   0x7de0: f9400308  ldr        x8, [x24]
//   0x7de4: f8458d13  ldr        x19, [x8, #0x58]!
//   0x7de8: eb13011f  cmp        x8, x19
//   0x7dec: 540000c0  b.eq       #0x7e04
//   0x7df0: a9402269  ldp        x9, x8, [x19]
//   0x7df4: f9000528  str        x8, [x9, #8]
//   0x7df8: f9400668  ldr        x8, [x19, #8]
//   0x7dfc: f9000109  str        x9, [x8]
//   0x7e00: 14000008  b          #0x7e20
//   0x7e04: d0000028  adrp       x8, #0xd000
//   0x7e08: 52800e00  mov        w0, #0x70
//   0x7e0c: f946b508  ldr        x8, [x8, #0xd68]
//   0x7e10: f9400108  ldr        x8, [x8]
//   0x7e14: f9400d08  ldr        x8, [x8, #0x18]
//   0x7e18: d63f0100  blr        x8
//   0x7e1c: aa0003f3  mov        x19, x0
//   0x7e20: f9400308  ldr        x8, [x24]
//   0x7e24: 9100c100  add        x0, x8, #0x30
//   0x7e28: 940006ea  bl         #0x99d0
//   0x7e2c: 6f00e400  movi       v0.2d, #0000000000000000
//   0x7e30: ad000260  stp        q0, q0, [x19]
//   0x7e34: ad010260  stp        q0, q0, [x19, #0x20]
//   0x7e38: ad020260  stp        q0, q0, [x19, #0x40]
//   0x7e3c: 3d801a60  str        q0, [x19, #0x60]
//   0x7e40: b40014d3  cbz        x19, #0x80d8
//   0x7e44: 9240deb5  and        x21, x21, #0xffffffffffffff
//   0x7e48: 9240dee8  and        x8, x23, #0xffffffffffffff
//   0x7e4c: 9240dec0  and        x0, x22, #0xffffffffffffff
//   0x7e50: aa1503e1  mov        x1, x21
//   0x7e54: aa1303e2  mov        x2, x19
//   0x7e58: f9002674  str        x20, [x19, #0x48]
//   0x7e5c: f9001a68  str        x8, [x19, #0x30]
//   0x7e60: 97fffc7e  bl         #0x7058
//   0x7e64: a903d660  stp        x0, x21, [x19, #0x38]
//   0x7e68: 94000706  bl         #0x9a80
//   0x7e6c: d0000028  adrp       x8, #0xd000
//   0x7e70: f9000273  str        x19, [x19]
//   0x7e74: f946ad08  ldr        x8, [x8, #0xd58]
//   0x7e78: b9006e60  str        w0, [x19, #0x6c]
//   0x7e7c: f9000673  str        x19, [x19, #8]
//   0x7e80: f9400108  ldr        x8, [x8]
//   0x7e84: f9400d08  ldr        x8, [x8, #0x18]
//   0x7e88: eb14011f  cmp        x8, x20
//   0x7e8c: 54000088  b.hi       #0x7e9c
//   0x7e90: aa1303e0  mov        x0, x19
//   0x7e94: 52800061  mov        w1, #3
//   0x7e98: 94000254  bl         #0x87e8
//   0x7e9c: f9400300  ldr        x0, [x24]
//   0x7ea0: 940006c0  bl         #0x99a0
//   0x7ea4: f9400300  ldr        x0, [x24]
//   0x7ea8: aa0003e8  mov        x8, x0
//   0x7eac: f8428d0a  ldr        x10, [x8, #0x28]!
//   0x7eb0: b400122a  cbz        x10, #0x80f4
//   0x7eb4: f9401a6b  ldr        x11, [x19, #0x30]
//   0x7eb8: 14000004  b          #0x7ec8
//   0x7ebc: 9100412a  add        x10, x9, #0x10
//   0x7ec0: f940014a  ldr        x10, [x10]
//   0x7ec4: b400012a  cbz        x10, #0x7ee8
//   0x7ec8: f940194c  ldr        x12, [x10, #0x30]
//   0x7ecc: aa0a03e9  mov        x9, x10
//   0x7ed0: eb0c017f  cmp        x11, x12
//   0x7ed4: 54ffff43  b.lo       #0x7ebc
//   0x7ed8: 540011c0  b.eq       #0x8110
//   0x7edc: 9100612a  add        x10, x9, #0x18
//   0x7ee0: f940014a  ldr        x10, [x10]
//   0x7ee4: b5ffff2a  cbnz       x10, #0x7ec8
//   0x7ee8: eb0c017f  cmp        x11, x12
//   0x7eec: 5280030b  mov        w11, #0x18
//   0x7ef0: 5280020c  mov        w12, #0x10
//   0x7ef4: 5280002a  mov        w10, #1
//   0x7ef8: 9a8b318b  csel       x11, x12, x11, lo
//   0x7efc: aa1303ec  mov        x12, x19
//   0x7f00: a901a67f  stp        xzr, x9, [x19, #0x18]
//   0x7f04: f9000a7f  str        xzr, [x19, #0x10]
//   0x7f08: b9002a6a  str        w10, [x19, #0x28]
//   0x7f0c: f82b6933  str        x19, [x9, x11]
//   0x7f10: 14000008  b          #0x7f30
//   0x7f14: b90029bf  str        wzr, [x13, #0x28]
//   0x7f18: b900293f  str        wzr, [x9, #0x28]
//   0x7f1c: aa0b03e9  mov        x9, x11
//   0x7f20: b900296a  str        w10, [x11, #0x28]
//   0x7f24: aa0903ec  mov        x12, x9
//   0x7f28: f9401129  ldr        x9, [x9, #0x20]
//   0x7f2c: b4000e09  cbz        x9, #0x80ec
//   0x7f30: b940292b  ldr        w11, [x9, #0x28]
//   0x7f34: 7100057f  cmp        w11, #1
//   0x7f38: 54000da1  b.ne       #0x80ec
//   0x7f3c: f940112b  ldr        x11, [x9, #0x20]
//   0x7f40: f940096d  ldr        x13, [x11, #0x10]
//   0x7f44: eb0d013f  cmp        x9, x13
//   0x7f48: 54000160  b.eq       #0x7f74
//   0x7f4c: b400008d  cbz        x13, #0x7f5c
//   0x7f50: b94029ae  ldr        w14, [x13, #0x28]
//   0x7f54: 710005df  cmp        w14, #1
//   0x7f58: 54fffde0  b.eq       #0x7f14
//   0x7f5c: f940092d  ldr        x13, [x9, #0x10]
//   0x7f60: eb0c01bf  cmp        x13, x12
//   0x7f64: 540001e0  b.eq       #0x7fa0
//   0x7f68: aa0903ed  mov        x13, x9
//   0x7f6c: aa0c03e9  mov        x9, x12
//   0x7f70: 14000028  b          #0x8010
//   0x7f74: f9400d6d  ldr        x13, [x11, #0x18]
//   0x7f78: b400008d  cbz        x13, #0x7f88
//   0x7f7c: b94029ae  ldr        w14, [x13, #0x28]
//   0x7f80: 710005df  cmp        w14, #1
//   0x7f84: 54fffc80  b.eq       #0x7f14
//   0x7f88: f9400d2d  ldr        x13, [x9, #0x18]
//   0x7f8c: eb0c01bf  cmp        x13, x12
//   0x7f90: 540001a0  b.eq       #0x7fc4
//   0x7f94: aa0903ed  mov        x13, x9
//   0x7f98: aa0c03e9  mov        x9, x12
//   0x7f9c: 1400003b  b          #0x8088
//   0x7fa0: f9400d8d  ldr        x13, [x12, #0x18]
//   0x7fa4: f900092d  str        x13, [x9, #0x10]
//   0x7fa8: b400020d  cbz        x13, #0x7fe8
//   0x7fac: f90011a9  str        x9, [x13, #0x20]
//   0x7fb0: aa0803ed  mov        x13, x8
//   0x7fb4: f940112e  ldr        x14, [x9, #0x20]
//   0x7fb8: f900118e  str        x14, [x12, #0x20]
//   0x7fbc: b500018e  cbnz       x14, #0x7fec
//   0x7fc0: 14000010  b          #0x8000
//   0x7fc4: f940098d  ldr        x13, [x12, #0x10]
//   0x7fc8: f9000d2d  str        x13, [x9, #0x18]
//   0x7fcc: b40004ad  cbz        x13, #0x8060
//   0x7fd0: f90011a9  str        x9, [x13, #0x20]
//   0x7fd4: aa0803ed  mov        x13, x8
//   0x7fd8: f940112e  ldr        x14, [x9, #0x20]
//   0x7fdc: f900118e  str        x14, [x12, #0x20]
//   0x7fe0: b500042e  cbnz       x14, #0x8064
//   0x7fe4: 14000025  b          #0x8078
//   0x7fe8: f900118b  str        x11, [x12, #0x20]
//   0x7fec: f940112d  ldr        x13, [x9, #0x20]
//   0x7ff0: f8410dae  ldr        x14, [x13, #0x10]!
//   0x7ff4: 910021af  add        x15, x13, #8
//   0x7ff8: eb0e013f  cmp        x9, x14
//   0x7ffc: 9a8f01ad  csel       x13, x13, x15, eq
//   0x8000: f90001ac  str        x12, [x13]
//   0x8004: aa0c03ed  mov        x13, x12
//   0x8008: f9000d89  str        x9, [x12, #0x18]
//   0x800c: f900112c  str        x12, [x9, #0x20]
//   0x8010: b90029bf  str        wzr, [x13, #0x28]
//   0x8014: f9400d6c  ldr        x12, [x11, #0x18]
//   0x8018: b900296a  str        w10, [x11, #0x28]
//   0x801c: f940098d  ldr        x13, [x12, #0x10]
//   0x8020: f9000d6d  str        x13, [x11, #0x18]
//   0x8024: b400004d  cbz        x13, #0x802c
//   0x8028: f90011ab  str        x11, [x13, #0x20]
//   0x802c: f940116e  ldr        x14, [x11, #0x20]
//   0x8030: aa0803ed  mov        x13, x8
//   0x8034: f900118e  str        x14, [x12, #0x20]
//   0x8038: b40000ce  cbz        x14, #0x8050
//   0x803c: f940116d  ldr        x13, [x11, #0x20]
//   0x8040: f8410dae  ldr        x14, [x13, #0x10]!
//   0x8044: 910021af  add        x15, x13, #8
//   0x8048: eb0e017f  cmp        x11, x14
//   0x804c: 9a8f01ad  csel       x13, x13, x15, eq
//   0x8050: f90001ac  str        x12, [x13]
//   0x8054: f900098b  str        x11, [x12, #0x10]
//   0x8058: f900116c  str        x12, [x11, #0x20]
//   0x805c: 17ffffb2  b          #0x7f24
//   0x8060: f900118b  str        x11, [x12, #0x20]
//   0x8064: f940112d  ldr        x13, [x9, #0x20]
//   0x8068: f8410dae  ldr        x14, [x13, #0x10]!
//   0x806c: 910021af  add        x15, x13, #8
//   0x8070: eb0e013f  cmp        x9, x14
//   0x8074: 9a8f01ad  csel       x13, x13, x15, eq
//   0x8078: f90001ac  str        x12, [x13]
//   0x807c: aa0c03ed  mov        x13, x12
//   0x8080: f9000989  str        x9, [x12, #0x10]
//   0x8084: f900112c  str        x12, [x9, #0x20]
//   0x8088: b90029bf  str        wzr, [x13, #0x28]
//   0x808c: f940096c  ldr        x12, [x11, #0x10]
//   0x8090: b900296a  str        w10, [x11, #0x28]
//   0x8094: f9400d8d  ldr        x13, [x12, #0x18]
//   0x8098: f900096d  str        x13, [x11, #0x10]
//   0x809c: b400004d  cbz        x13, #0x80a4
//   0x80a0: f90011ab  str        x11, [x13, #0x20]
//   0x80a4: f940116e  ldr        x14, [x11, #0x20]
//   0x80a8: aa0803ed  mov        x13, x8
//   0x80ac: f900118e  str        x14, [x12, #0x20]
//   0x80b0: b40000ce  cbz        x14, #0x80c8
//   0x80b4: f940116d  ldr        x13, [x11, #0x20]
//   0x80b8: f8410dae  ldr        x14, [x13, #0x10]!
//   0x80bc: 910021af  add        x15, x13, #8
//   0x80c0: eb0e017f  cmp        x11, x14
//   0x80c4: 9a8f01ad  csel       x13, x13, x15, eq
//   0x80c8: f90001ac  str        x12, [x13]
//   0x80cc: f9000d8b  str        x11, [x12, #0x18]
//   0x80d0: f900116c  str        x12, [x11, #0x20]
//   0x80d4: 17ffff94  b          #0x7f24
//   0x80d8: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x80dc: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x80e0: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x80e4: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x80e8: d65f03c0  ret        
//   0x80ec: f9400109  ldr        x9, [x8]
//   0x80f0: 14000007  b          #0x810c
//   0x80f4: 5280002a  mov        w10, #1
//   0x80f8: a901fe7f  stp        xzr, xzr, [x19, #0x18]
//   0x80fc: f9000a7f  str        xzr, [x19, #0x10]
//   0x8100: aa1303e9  mov        x9, x19
//   0x8104: b9002a6a  str        w10, [x19, #0x28]
//   0x8108: f9000113  str        x19, [x8]
//   0x810c: b900293f  str        wzr, [x9, #0x28]
//   0x8110: f9402668  ldr        x8, [x19, #0x48]
//   0x8114: f940a809  ldr        x9, [x0, #0x150]
//   0x8118: f940b80a  ldr        x10, [x0, #0x170]
//   0x811c: 8b080128  add        x8, x9, x8
//   0x8120: 91000549  add        x9, x10, #1
//   0x8124: f900a808  str        x8, [x0, #0x150]
//   0x8128: f900b809  str        x9, [x0, #0x170]
//   0x812c: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x8130: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x8134: a9415ff8  ldp        x24, x23, [sp, #0x10]
//   0x8138: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x813c: 14000625  b          #0x99d0

// ----------------------------------------------------------------------------
// FDE[64] HeapTrackerFde_8140 (0x8140..0x824c, 268 bytes, 67 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8140..0x824c
// ----------------------------------------------------------------------------
//   0x8140: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x8144: f9000bf5  str        x21, [sp, #0x10]
//   0x8148: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x814c: 910003fd  mov        x29, sp
//   0x8150: b0000035  adrp       x21, #0xd000
//   0x8154: aa0003f4  mov        x20, x0
//   0x8158: f946beb5  ldr        x21, [x21, #0xd78]
//   0x815c: f94002a0  ldr        x0, [x21]
//   0x8160: 94000610  bl         #0x99a0
//   0x8164: f94002a0  ldr        x0, [x21]
//   0x8168: aa0003e8  mov        x8, x0
//   0x816c: f8428d13  ldr        x19, [x8, #0x28]!
//   0x8170: b50000b3  cbnz       x19, #0x8184
//   0x8174: 1400000b  b          #0x81a0
//   0x8178: 91004269  add        x9, x19, #0x10
//   0x817c: f9400133  ldr        x19, [x9]
//   0x8180: b4000113  cbz        x19, #0x81a0
//   0x8184: f9401a69  ldr        x9, [x19, #0x30]
//   0x8188: eb14013f  cmp        x9, x20
//   0x818c: 54ffff68  b.hi       #0x8178
//   0x8190: 540000a0  b.eq       #0x81a4
//   0x8194: 91006269  add        x9, x19, #0x18
//   0x8198: f9400133  ldr        x19, [x9]
//   0x819c: b5ffff53  cbnz       x19, #0x8184
//   0x81a0: 14000027  b          #0x823c
//   0x81a4: aa0803e0  mov        x0, x8
//   0x81a8: aa1303e1  mov        x1, x19
//   0x81ac: 9400009d  bl         #0x8420
//   0x81b0: f94002a0  ldr        x0, [x21]
//   0x81b4: f9402668  ldr        x8, [x19, #0x48]
//   0x81b8: f940b409  ldr        x9, [x0, #0x168]
//   0x81bc: f940bc0a  ldr        x10, [x0, #0x178]
//   0x81c0: 8b080128  add        x8, x9, x8
//   0x81c4: 91000549  add        x9, x10, #1
//   0x81c8: f900b408  str        x8, [x0, #0x168]
//   0x81cc: f900bc09  str        x9, [x0, #0x178]
//   0x81d0: 94000600  bl         #0x99d0
//   0x81d4: f9403260  ldr        x0, [x19, #0x60]
//   0x81d8: b40001c0  cbz        x0, #0x8210
//   0x81dc: b0000034  adrp       x20, #0xd000
//   0x81e0: f9400008  ldr        x8, [x0]
//   0x81e4: f946b694  ldr        x20, [x20, #0xd68]
//   0x81e8: b40000c8  cbz        x8, #0x8200
//   0x81ec: f9400289  ldr        x9, [x20]
//   0x81f0: aa0803e0  mov        x0, x8
//   0x81f4: f9400529  ldr        x9, [x9, #8]
//   0x81f8: d63f0120  blr        x9
//   0x81fc: f9403260  ldr        x0, [x19, #0x60]
//   0x8200: f9400288  ldr        x8, [x20]
//   0x8204: f9400508  ldr        x8, [x8, #8]
//   0x8208: d63f0100  blr        x8
//   0x820c: f900327f  str        xzr, [x19, #0x60]
//   0x8210: f94002a8  ldr        x8, [x21]
//   0x8214: 9100c100  add        x0, x8, #0x30
//   0x8218: 940005e2  bl         #0x99a0
//   0x821c: f94002a8  ldr        x8, [x21]
//   0x8220: f8458d09  ldr        x9, [x8, #0x58]!
//   0x8224: a9002269  stp        x9, x8, [x19]
//   0x8228: f94002a9  ldr        x9, [x21]
//   0x822c: 9100c120  add        x0, x9, #0x30
//   0x8230: f9400109  ldr        x9, [x8]
//   0x8234: f9000533  str        x19, [x9, #8]
//   0x8238: f9000113  str        x19, [x8]
//   0x823c: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x8240: f9400bf5  ldr        x21, [sp, #0x10]
//   0x8244: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x8248: 140005e2  b          #0x99d0

// ----------------------------------------------------------------------------
// FDE[65] HeapTrackerFde_824c (0x824c..0x83ac, 352 bytes, 88 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x824c..0x83ac
// ----------------------------------------------------------------------------
//   0x824c: a9bd7bfd  stp        x29, x30, [sp, #-0x30]!
//   0x8250: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x8254: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x8258: 910003fd  mov        x29, sp
//   0x825c: d503201f  nop        
//   0x8260: 1004f214  adr        x20, #0x120a0
//   0x8264: f9400280  ldr        x0, [x20]
//   0x8268: 940005ce  bl         #0x99a0
//   0x826c: f9400280  ldr        x0, [x20]
//   0x8270: aa1f03e8  mov        x8, xzr
//   0x8274: 9100a009  add        x9, x0, #0x28
//   0x8278: aa0803f3  mov        x19, x8
//   0x827c: f9400128  ldr        x8, [x9]
//   0x8280: 91004109  add        x9, x8, #0x10
//   0x8284: b5ffffa8  cbnz       x8, #0x8278
//   0x8288: d503201f  nop        
//   0x828c: 1004ef75  adr        x21, #0x12078
//   0x8290: b5000193  cbnz       x19, #0x82c0
//   0x8294: 1400002c  b          #0x8344
//   0x8298: f94002a8  ldr        x8, [x21]
//   0x829c: f9400508  ldr        x8, [x8, #8]
//   0x82a0: d63f0100  blr        x8
//   0x82a4: f900327f  str        xzr, [x19, #0x60]
//   0x82a8: f94002a8  ldr        x8, [x21]
//   0x82ac: aa1303e0  mov        x0, x19
//   0x82b0: f9400508  ldr        x8, [x8, #8]
//   0x82b4: d63f0100  blr        x8
//   0x82b8: aa1603f3  mov        x19, x22
//   0x82bc: b4000436  cbz        x22, #0x8340
//   0x82c0: f9400e68  ldr        x8, [x19, #0x18]
//   0x82c4: b4000248  cbz        x8, #0x830c
//   0x82c8: aa0803f6  mov        x22, x8
//   0x82cc: f9400908  ldr        x8, [x8, #0x10]
//   0x82d0: b5ffffc8  cbnz       x8, #0x82c8
//   0x82d4: f9400288  ldr        x8, [x20]
//   0x82d8: aa1303e1  mov        x1, x19
//   0x82dc: 9100a100  add        x0, x8, #0x28
//   0x82e0: 94000050  bl         #0x8420
//   0x82e4: f9403260  ldr        x0, [x19, #0x60]
//   0x82e8: b4fffe00  cbz        x0, #0x82a8
//   0x82ec: f9400008  ldr        x8, [x0]
//   0x82f0: b4fffd48  cbz        x8, #0x8298
//   0x82f4: f94002a9  ldr        x9, [x21]
//   0x82f8: aa0803e0  mov        x0, x8
//   0x82fc: f9400529  ldr        x9, [x9, #8]
//   0x8300: d63f0120  blr        x9
//   0x8304: f9403260  ldr        x0, [x19, #0x60]
//   0x8308: 17ffffe4  b          #0x8298
//   0x830c: f9401276  ldr        x22, [x19, #0x20]
//   0x8310: b4000096  cbz        x22, #0x8320
//   0x8314: f9400ac8  ldr        x8, [x22, #0x10]
//   0x8318: eb13011f  cmp        x8, x19
//   0x831c: 54fffdc0  b.eq       #0x82d4
//   0x8320: aa1303e8  mov        x8, x19
//   0x8324: f9401116  ldr        x22, [x8, #0x20]
//   0x8328: b4fffd76  cbz        x22, #0x82d4
//   0x832c: f9400ec9  ldr        x9, [x22, #0x18]
//   0x8330: eb09011f  cmp        x8, x9
//   0x8334: aa1603e8  mov        x8, x22
//   0x8338: 54ffff60  b.eq       #0x8324
//   0x833c: 17ffffe6  b          #0x82d4
//   0x8340: f9400280  ldr        x0, [x20]
//   0x8344: 940005a3  bl         #0x99d0
//   0x8348: f9400288  ldr        x8, [x20]
//   0x834c: 9100c100  add        x0, x8, #0x30
//   0x8350: 94000594  bl         #0x99a0
//   0x8354: f9400288  ldr        x8, [x20]
//   0x8358: aa0803e9  mov        x9, x8
//   0x835c: f8458d20  ldr        x0, [x9, #0x58]!
//   0x8360: eb09001f  cmp        x0, x9
//   0x8364: 540001a0  b.eq       #0x8398
//   0x8368: a9402013  ldp        x19, x8, [x0]
//   0x836c: f9000668  str        x8, [x19, #8]
//   0x8370: f9400408  ldr        x8, [x0, #8]
//   0x8374: f9000113  str        x19, [x8]
//   0x8378: f94002a8  ldr        x8, [x21]
//   0x837c: f9400508  ldr        x8, [x8, #8]
//   0x8380: d63f0100  blr        x8
//   0x8384: f9400288  ldr        x8, [x20]
//   0x8388: aa1303e0  mov        x0, x19
//   0x838c: 91016109  add        x9, x8, #0x58
//   0x8390: eb09027f  cmp        x19, x9
//   0x8394: 54fffea1  b.ne       #0x8368
//   0x8398: 9100c100  add        x0, x8, #0x30
//   0x839c: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x83a0: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x83a4: a8c37bfd  ldp        x29, x30, [sp], #0x30
//   0x83a8: 1400058a  b          #0x99d0

// ----------------------------------------------------------------------------
// FDE[66] HeapTrackerFde_83ac (0x83ac..0x83f4, 72 bytes, 18 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x83ac..0x83f4
// ----------------------------------------------------------------------------
//   0x83ac: b0000028  adrp       x8, #0xd000
//   0x83b0: 6f00e400  movi       v0.2d, #0000000000000000
//   0x83b4: f946bd08  ldr        x8, [x8, #0xd78]
//   0x83b8: f9400109  ldr        x9, [x8]
//   0x83bc: f900113f  str        xzr, [x9, #0x20]
//   0x83c0: ad000120  stp        q0, q0, [x9]
//   0x83c4: f9400108  ldr        x8, [x8]
//   0x83c8: 9107d109  add        x9, x8, #0x1f4
//   0x83cc: 9101610a  add        x10, x8, #0x58
//   0x83d0: ad018100  stp        q0, q0, [x8, #0x30]
//   0x83d4: f900151f  str        xzr, [x8, #0x28]
//   0x83d8: ad000120  stp        q0, q0, [x9]
//   0x83dc: f900113f  str        xzr, [x9, #0x20]
//   0x83e0: 9101c109  add        x9, x8, #0x70
//   0x83e4: a905291f  stp        xzr, x10, [x8, #0x50]
//   0x83e8: f900310a  str        x10, [x8, #0x60]
//   0x83ec: a9072509  stp        x9, x9, [x8, #0x70]
//   0x83f0: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[67] HeapTrackerFde_83f4 (0x83f4..0x8420, 44 bytes, 11 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x83f4..0x8420
// ----------------------------------------------------------------------------
//   0x83f4: d503201f  nop        
//   0x83f8: 1004e548  adr        x8, #0x120a0
//   0x83fc: f9400108  ldr        x8, [x8]
//   0x8400: b40000c8  cbz        x8, #0x8418
//   0x8404: f940a909  ldr        x9, [x8, #0x150]
//   0x8408: f940b508  ldr        x8, [x8, #0x168]
//   0x840c: eb080128  subs       x8, x9, x8
//   0x8410: 9a8833e0  csel       x0, xzr, x8, lo
//   0x8414: d65f03c0  ret        
//   0x8418: aa1f03e0  mov        x0, xzr
//   0x841c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[68] HeapTrackerFde_8420 (0x8420..0x87e8, 968 bytes, 242 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8420..0x87e8
// ----------------------------------------------------------------------------
//   0x8420: aa0103eb  mov        x11, x1
//   0x8424: a9c12169  ldp        x9, x8, [x11, #0x10]!
//   0x8428: b40004c9  cbz        x9, #0x84c0
//   0x842c: b40005e8  cbz        x8, #0x84e8
//   0x8430: aa0803ea  mov        x10, x8
//   0x8434: f9400908  ldr        x8, [x8, #0x10]
//   0x8438: b5ffffc8  cbnz       x8, #0x8430
//   0x843c: a941b148  ldp        x8, x12, [x10, #0x18]
//   0x8440: b9402949  ldr        w9, [x10, #0x28]
//   0x8444: b4000048  cbz        x8, #0x844c
//   0x8448: f900110c  str        x12, [x8, #0x20]
//   0x844c: 9100414d  add        x13, x10, #0x10
//   0x8450: aa0003ee  mov        x14, x0
//   0x8454: b40000cc  cbz        x12, #0x846c
//   0x8458: aa0c03ee  mov        x14, x12
//   0x845c: f8410dcf  ldr        x15, [x14, #0x10]!
//   0x8460: 910021d0  add        x16, x14, #8
//   0x8464: eb0a01ff  cmp        x15, x10
//   0x8468: 9a9001ce  csel       x14, x14, x16, eq
//   0x846c: f90001c8  str        x8, [x14]
//   0x8470: ad400560  ldp        q0, q1, [x11]
//   0x8474: f940114b  ldr        x11, [x10, #0x20]
//   0x8478: ad0005a0  stp        q0, q1, [x13]
//   0x847c: f940102d  ldr        x13, [x1, #0x20]
//   0x8480: eb01017f  cmp        x11, x1
//   0x8484: 9a8c014b  csel       x11, x10, x12, eq
//   0x8488: aa0003ec  mov        x12, x0
//   0x848c: b40000ad  cbz        x13, #0x84a0
//   0x8490: f8410dac  ldr        x12, [x13, #0x10]!
//   0x8494: 910021ae  add        x14, x13, #8
//   0x8498: eb01019f  cmp        x12, x1
//   0x849c: 9a8e01ac  csel       x12, x13, x14, eq
//   0x84a0: f900018a  str        x10, [x12]
//   0x84a4: a941302d  ldp        x13, x12, [x1, #0x10]
//   0x84a8: f90011aa  str        x10, [x13, #0x20]
//   0x84ac: b400004c  cbz        x12, #0x84b4
//   0x84b0: f900118a  str        x10, [x12, #0x20]
//   0x84b4: 340002a9  cbz        w9, #0x8508
//   0x84b8: aa0103e0  mov        x0, x1
//   0x84bc: d65f03c0  ret        
//   0x84c0: f940102b  ldr        x11, [x1, #0x20]
//   0x84c4: b9402829  ldr        w9, [x1, #0x28]
//   0x84c8: b5000168  cbnz       x8, #0x84f4
//   0x84cc: b400018b  cbz        x11, #0x84fc
//   0x84d0: aa0b03ea  mov        x10, x11
//   0x84d4: f8410d4c  ldr        x12, [x10, #0x10]!
//   0x84d8: 9100214d  add        x13, x10, #8
//   0x84dc: eb01019f  cmp        x12, x1
//   0x84e0: 9a8d014a  csel       x10, x10, x13, eq
//   0x84e4: 14000007  b          #0x8500
//   0x84e8: f940102b  ldr        x11, [x1, #0x20]
//   0x84ec: aa0903e8  mov        x8, x9
//   0x84f0: b9402829  ldr        w9, [x1, #0x28]
//   0x84f4: f900110b  str        x11, [x8, #0x20]
//   0x84f8: b5fffecb  cbnz       x11, #0x84d0
//   0x84fc: aa0003ea  mov        x10, x0
//   0x8500: f9000148  str        x8, [x10]
//   0x8504: 35fffda9  cbnz       w9, #0x84b8
//   0x8508: 5280002a  mov        w10, #1
//   0x850c: 14000003  b          #0x8518
//   0x8510: b900292a  str        w10, [x9, #0x28]
//   0x8514: f940110b  ldr        x11, [x8, #0x20]
//   0x8518: aa0803ec  mov        x12, x8
//   0x851c: aa0b03e8  mov        x8, x11
//   0x8520: b400006c  cbz        x12, #0x852c
//   0x8524: b9402989  ldr        w9, [x12, #0x28]
//   0x8528: 350015a9  cbnz       w9, #0x87dc
//   0x852c: f9400009  ldr        x9, [x0]
//   0x8530: eb09019f  cmp        x12, x9
//   0x8534: 54001520  b.eq       #0x87d8
//   0x8538: f9400909  ldr        x9, [x8, #0x10]
//   0x853c: eb0c013f  cmp        x9, x12
//   0x8540: 54000280  b.eq       #0x8590
//   0x8544: b940292b  ldr        w11, [x9, #0x28]
//   0x8548: 7100057f  cmp        w11, #1
//   0x854c: 54000581  b.ne       #0x85fc
//   0x8550: b900293f  str        wzr, [x9, #0x28]
//   0x8554: f940090b  ldr        x11, [x8, #0x10]
//   0x8558: b900290a  str        w10, [x8, #0x28]
//   0x855c: f9400d69  ldr        x9, [x11, #0x18]
//   0x8560: f9000909  str        x9, [x8, #0x10]
//   0x8564: b4000049  cbz        x9, #0x856c
//   0x8568: f9001128  str        x8, [x9, #0x20]
//   0x856c: f940110c  ldr        x12, [x8, #0x20]
//   0x8570: f900116c  str        x12, [x11, #0x20]
//   0x8574: b400038c  cbz        x12, #0x85e4
//   0x8578: f940110c  ldr        x12, [x8, #0x20]
//   0x857c: f940098d  ldr        x13, [x12, #0x10]
//   0x8580: eb0d011f  cmp        x8, x13
//   0x8584: 54000340  b.eq       #0x85ec
//   0x8588: f9000d8b  str        x11, [x12, #0x18]
//   0x858c: 1400001a  b          #0x85f4
//   0x8590: f9400d09  ldr        x9, [x8, #0x18]
//   0x8594: b940292b  ldr        w11, [x9, #0x28]
//   0x8598: 7100057f  cmp        w11, #1
//   0x859c: 540004c1  b.ne       #0x8634
//   0x85a0: b900293f  str        wzr, [x9, #0x28]
//   0x85a4: f9400d0b  ldr        x11, [x8, #0x18]
//   0x85a8: b900290a  str        w10, [x8, #0x28]
//   0x85ac: f9400969  ldr        x9, [x11, #0x10]
//   0x85b0: f9000d09  str        x9, [x8, #0x18]
//   0x85b4: b4000049  cbz        x9, #0x85bc
//   0x85b8: f9001128  str        x8, [x9, #0x20]
//   0x85bc: f940110c  ldr        x12, [x8, #0x20]
//   0x85c0: f900116c  str        x12, [x11, #0x20]
//   0x85c4: b40002ec  cbz        x12, #0x8620
//   0x85c8: f940110c  ldr        x12, [x8, #0x20]
//   0x85cc: f940098d  ldr        x13, [x12, #0x10]
//   0x85d0: eb0d011f  cmp        x8, x13
//   0x85d4: 540002a0  b.eq       #0x8628
//   0x85d8: f9000d8b  str        x11, [x12, #0x18]
//   0x85dc: f9400d09  ldr        x9, [x8, #0x18]
//   0x85e0: 14000013  b          #0x862c
//   0x85e4: f900000b  str        x11, [x0]
//   0x85e8: 14000003  b          #0x85f4
//   0x85ec: f900098b  str        x11, [x12, #0x10]
//   0x85f0: f9400909  ldr        x9, [x8, #0x10]
//   0x85f4: f9000d68  str        x8, [x11, #0x18]
//   0x85f8: f900110b  str        x11, [x8, #0x20]
//   0x85fc: f940092b  ldr        x11, [x9, #0x10]
//   0x8600: b400006b  cbz        x11, #0x860c
//   0x8604: b940296c  ldr        w12, [x11, #0x28]
//   0x8608: 3500058c  cbnz       w12, #0x86b8
//   0x860c: f9400d2c  ldr        x12, [x9, #0x18]
//   0x8610: b4fff80c  cbz        x12, #0x8510
//   0x8614: b940298d  ldr        w13, [x12, #0x28]
//   0x8618: 34fff7cd  cbz        w13, #0x8510
//   0x861c: 1400000f  b          #0x8658
//   0x8620: f900000b  str        x11, [x0]
//   0x8624: 14000002  b          #0x862c
//   0x8628: f900098b  str        x11, [x12, #0x10]
//   0x862c: f9000968  str        x8, [x11, #0x10]
//   0x8630: f900110b  str        x11, [x8, #0x20]
//   0x8634: f940092b  ldr        x11, [x9, #0x10]
//   0x8638: b400006b  cbz        x11, #0x8644
//   0x863c: b940296c  ldr        w12, [x11, #0x28]
//   0x8640: 350006ac  cbnz       w12, #0x8714
//   0x8644: f9400d2b  ldr        x11, [x9, #0x18]
//   0x8648: b4fff64b  cbz        x11, #0x8510
//   0x864c: b940296b  ldr        w11, [x11, #0x28]
//   0x8650: 34fff60b  cbz        w11, #0x8510
//   0x8654: 14000049  b          #0x8778
//   0x8658: b400006b  cbz        x11, #0x8664
//   0x865c: b940296a  ldr        w10, [x11, #0x28]
//   0x8660: 350002ca  cbnz       w10, #0x86b8
//   0x8664: b900299f  str        wzr, [x12, #0x28]
//   0x8668: 5280002b  mov        w11, #1
//   0x866c: f9400d2a  ldr        x10, [x9, #0x18]
//   0x8670: b900292b  str        w11, [x9, #0x28]
//   0x8674: f940094b  ldr        x11, [x10, #0x10]
//   0x8678: f9000d2b  str        x11, [x9, #0x18]
//   0x867c: b400004b  cbz        x11, #0x8684
//   0x8680: f9001169  str        x9, [x11, #0x20]
//   0x8684: f940112c  ldr        x12, [x9, #0x20]
//   0x8688: aa0003eb  mov        x11, x0
//   0x868c: f900114c  str        x12, [x10, #0x20]
//   0x8690: b40000cc  cbz        x12, #0x86a8
//   0x8694: f940112b  ldr        x11, [x9, #0x20]
//   0x8698: f8410d6c  ldr        x12, [x11, #0x10]!
//   0x869c: 9100216d  add        x13, x11, #8
//   0x86a0: eb0c013f  cmp        x9, x12
//   0x86a4: 9a8d016b  csel       x11, x11, x13, eq
//   0x86a8: f900016a  str        x10, [x11]
//   0x86ac: f9000949  str        x9, [x10, #0x10]
//   0x86b0: f900112a  str        x10, [x9, #0x20]
//   0x86b4: f9400909  ldr        x9, [x8, #0x10]
//   0x86b8: b940290a  ldr        w10, [x8, #0x28]
//   0x86bc: b900292a  str        w10, [x9, #0x28]
//   0x86c0: b900291f  str        wzr, [x8, #0x28]
//   0x86c4: f9400929  ldr        x9, [x9, #0x10]
//   0x86c8: b4000049  cbz        x9, #0x86d0
//   0x86cc: b900293f  str        wzr, [x9, #0x28]
//   0x86d0: f9400909  ldr        x9, [x8, #0x10]
//   0x86d4: f9400d2a  ldr        x10, [x9, #0x18]
//   0x86d8: f900090a  str        x10, [x8, #0x10]
//   0x86dc: b400004a  cbz        x10, #0x86e4
//   0x86e0: f9001148  str        x8, [x10, #0x20]
//   0x86e4: f940110b  ldr        x11, [x8, #0x20]
//   0x86e8: aa0003ea  mov        x10, x0
//   0x86ec: f900112b  str        x11, [x9, #0x20]
//   0x86f0: b40000cb  cbz        x11, #0x8708
//   0x86f4: f940110a  ldr        x10, [x8, #0x20]
//   0x86f8: f8410d4b  ldr        x11, [x10, #0x10]!
//   0x86fc: 9100214c  add        x12, x10, #8
//   0x8700: eb0b011f  cmp        x8, x11
//   0x8704: 9a8c014a  csel       x10, x10, x12, eq
//   0x8708: f9000149  str        x9, [x10]
//   0x870c: f9000d28  str        x8, [x9, #0x18]
//   0x8710: 14000030  b          #0x87d0
//   0x8714: f9400d2a  ldr        x10, [x9, #0x18]
//   0x8718: b400006a  cbz        x10, #0x8724
//   0x871c: b940294a  ldr        w10, [x10, #0x28]
//   0x8720: 350002ca  cbnz       w10, #0x8778
//   0x8724: b900297f  str        wzr, [x11, #0x28]
//   0x8728: 5280002b  mov        w11, #1
//   0x872c: f940092a  ldr        x10, [x9, #0x10]
//   0x8730: b900292b  str        w11, [x9, #0x28]
//   0x8734: f9400d4b  ldr        x11, [x10, #0x18]
//   0x8738: f900092b  str        x11, [x9, #0x10]
//   0x873c: b400004b  cbz        x11, #0x8744
//   0x8740: f9001169  str        x9, [x11, #0x20]
//   0x8744: f940112c  ldr        x12, [x9, #0x20]
//   0x8748: aa0003eb  mov        x11, x0
//   0x874c: f900114c  str        x12, [x10, #0x20]
//   0x8750: b40000cc  cbz        x12, #0x8768
//   0x8754: f940112b  ldr        x11, [x9, #0x20]
//   0x8758: f8410d6c  ldr        x12, [x11, #0x10]!
//   0x875c: 9100216d  add        x13, x11, #8
//   0x8760: eb0c013f  cmp        x9, x12
//   0x8764: 9a8d016b  csel       x11, x11, x13, eq
//   0x8768: f900016a  str        x10, [x11]
//   0x876c: f9000d49  str        x9, [x10, #0x18]
//   0x8770: f900112a  str        x10, [x9, #0x20]
//   0x8774: f9400d09  ldr        x9, [x8, #0x18]
//   0x8778: b940290a  ldr        w10, [x8, #0x28]
//   0x877c: b900292a  str        w10, [x9, #0x28]
//   0x8780: b900291f  str        wzr, [x8, #0x28]
//   0x8784: f9400d29  ldr        x9, [x9, #0x18]
//   0x8788: b4000049  cbz        x9, #0x8790
//   0x878c: b900293f  str        wzr, [x9, #0x28]
//   0x8790: f9400d09  ldr        x9, [x8, #0x18]
//   0x8794: f940092a  ldr        x10, [x9, #0x10]
//   0x8798: f9000d0a  str        x10, [x8, #0x18]
//   0x879c: b400004a  cbz        x10, #0x87a4
//   0x87a0: f9001148  str        x8, [x10, #0x20]
//   0x87a4: f940110b  ldr        x11, [x8, #0x20]
//   0x87a8: aa0003ea  mov        x10, x0
//   0x87ac: f900112b  str        x11, [x9, #0x20]
//   0x87b0: b40000cb  cbz        x11, #0x87c8
//   0x87b4: f940110a  ldr        x10, [x8, #0x20]
//   0x87b8: f8410d4b  ldr        x11, [x10, #0x10]!
//   0x87bc: 9100214c  add        x12, x10, #8
//   0x87c0: eb0b011f  cmp        x8, x11
//   0x87c4: 9a8c014a  csel       x10, x10, x12, eq
//   0x87c8: f9000149  str        x9, [x10]
//   0x87cc: f9000928  str        x8, [x9, #0x10]
//   0x87d0: f940000c  ldr        x12, [x0]
//   0x87d4: f9001109  str        x9, [x8, #0x20]
//   0x87d8: b4ffe70c  cbz        x12, #0x84b8
//   0x87dc: b900299f  str        wzr, [x12, #0x28]
//   0x87e0: aa0103e0  mov        x0, x1
//   0x87e4: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[69] HeapTrackerFde_87e8 (0x87e8..0x8944, 348 bytes, 87 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x87e8..0x8944
// ----------------------------------------------------------------------------
//   0x87e8: a9bb7bfd  stp        x29, x30, [sp, #-0x50]!
//   0x87ec: a90167fc  stp        x28, x25, [sp, #0x10]
//   0x87f0: a9025ff8  stp        x24, x23, [sp, #0x20]
//   0x87f4: a90357f6  stp        x22, x21, [sp, #0x30]
//   0x87f8: a9044ff4  stp        x20, x19, [sp, #0x40]
//   0x87fc: 910003fd  mov        x29, sp
//   0x8800: d12043ff  sub        sp, sp, #0x810
//   0x8804: b0000035  adrp       x21, #0xd000
//   0x8808: d53bd056  mrs        x22, tpidr_el0
//   0x880c: f94016c8  ldr        x8, [x22, #0x28]
//   0x8810: aa0103f4  mov        x20, x1
//   0x8814: aa0003f3  mov        x19, x0
//   0x8818: f946aeb5  ldr        x21, [x21, #0xd58]
//   0x881c: f81f83a8  stur       x8, [x29, #-8]
//   0x8820: f94002a8  ldr        x8, [x21]
//   0x8824: b9400909  ldr        w9, [x8, #8]
//   0x8828: 35000069  cbnz       w9, #0x8834
//   0x882c: b9400d08  ldr        w8, [x8, #0xc]
//   0x8830: 34000728  cbz        w8, #0x8914
//   0x8834: 910003e0  mov        x0, sp
//   0x8838: 9400042a  bl         #0x98e0
//   0x883c: f94002a8  ldr        x8, [x21]
//   0x8840: 910023e0  add        x0, sp, #8
//   0x8844: 52802001  mov        w1, #0x100
//   0x8848: 52802015  mov        w21, #0x100
//   0x884c: b9400d08  ldr        w8, [x8, #0xc]
//   0x8850: 7100011f  cmp        w8, #0
//   0x8854: 1a9f07e2  cset       w2, ne
//   0x8858: 9400048e  bl         #0x9a90
//   0x885c: f104001f  cmp        x0, #0x100
//   0x8860: 9a953018  csel       x24, x0, x21, lo
//   0x8864: eb140317  subs       x23, x24, x20
//   0x8868: 54000569  b.ls       #0x8914
//   0x886c: b0000039  adrp       x25, #0xd000
//   0x8870: 52800300  mov        w0, #0x18
//   0x8874: f946b739  ldr        x25, [x25, #0xd68]
//   0x8878: f9400328  ldr        x8, [x25]
//   0x887c: f9400d08  ldr        x8, [x8, #0x18]
//   0x8880: d63f0100  blr        x8
//   0x8884: b4000480  cbz        x0, #0x8914
//   0x8888: f94003e8  ldr        x8, [sp]
//   0x888c: aa0003f5  mov        x21, x0
//   0x8890: f9400329  ldr        x9, [x25]
//   0x8894: f9000808  str        x8, [x0, #0x10]
//   0x8898: d37df2e0  lsl        x0, x23, #3
//   0x889c: f9400d28  ldr        x8, [x9, #0x18]
//   0x88a0: d63f0100  blr        x8
//   0x88a4: f90002a0  str        x0, [x21]
//   0x88a8: b40002e0  cbz        x0, #0x8904
//   0x88ac: eb14031f  cmp        x24, x20
//   0x88b0: f90006b7  str        x23, [x21, #8]
//   0x88b4: 54000240  b.eq       #0x88fc
//   0x88b8: f103fe9f  cmp        x20, #0xff
//   0x88bc: 54000208  b.hi       #0x88fc
//   0x88c0: 910023e8  add        x8, sp, #8
//   0x88c4: aa1f03e9  mov        x9, xzr
//   0x88c8: 8b140d08  add        x8, x8, x20, lsl #3
//   0x88cc: 9100068a  add        x10, x20, #1
//   0x88d0: d37df12c  lsl        x12, x9, #3
//   0x88d4: 9100052b  add        x11, x9, #1
//   0x88d8: f94002ae  ldr        x14, [x21]
//   0x88dc: eb17017f  cmp        x11, x23
//   0x88e0: f86c690d  ldr        x13, [x8, x12]
//   0x88e4: f82c69cd  str        x13, [x14, x12]
//   0x88e8: 540000a2  b.hs       #0x88fc
//   0x88ec: 8b09014c  add        x12, x10, x9
//   0x88f0: aa0b03e9  mov        x9, x11
//   0x88f4: f104019f  cmp        x12, #0x100
//   0x88f8: 54fffec3  b.lo       #0x88d0
//   0x88fc: f9003275  str        x21, [x19, #0x60]
//   0x8900: 14000005  b          #0x8914
//   0x8904: f9400328  ldr        x8, [x25]
//   0x8908: aa1503e0  mov        x0, x21
//   0x890c: f9400508  ldr        x8, [x8, #8]
//   0x8910: d63f0100  blr        x8
//   0x8914: f94016c8  ldr        x8, [x22, #0x28]
//   0x8918: f85f83a9  ldur       x9, [x29, #-8]
//   0x891c: eb09011f  cmp        x8, x9
//   0x8920: 54000101  b.ne       #0x8940
//   0x8924: 912043ff  add        sp, sp, #0x810
//   0x8928: a9444ff4  ldp        x20, x19, [sp, #0x40]
//   0x892c: a94357f6  ldp        x22, x21, [sp, #0x30]
//   0x8930: a9425ff8  ldp        x24, x23, [sp, #0x20]
//   0x8934: a94167fc  ldp        x28, x25, [sp, #0x10]
//   0x8938: a8c57bfd  ldp        x29, x30, [sp], #0x50
//   0x893c: d65f03c0  ret        
//   0x8940: 940003c8  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[70] HeapTrackerFde_8944 (0x8944..0x8cd4, 912 bytes, 228 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8944..0x8cd4
// ----------------------------------------------------------------------------
//   0x8944: a9ba7bfd  stp        x29, x30, [sp, #-0x60]!
//   0x8948: a9016ffc  stp        x28, x27, [sp, #0x10]
//   0x894c: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x8950: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x8954: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x8958: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x895c: 910003fd  mov        x29, sp
//   0x8960: d11283ff  sub        sp, sp, #0x4a0
//   0x8964: d53bd05a  mrs        x26, tpidr_el0
//   0x8968: aa0103f4  mov        x20, x1
//   0x896c: f9401748  ldr        x8, [x26, #0x28]
//   0x8970: 2a0003f3  mov        w19, w0
//   0x8974: f81f83a8  stur       x8, [x29, #-8]
//   0x8978: 34000a62  cbz        w2, #0x8ac4
//   0x897c: f9403288  ldr        x8, [x20, #0x60]
//   0x8980: b4000a28  cbz        x8, #0x8ac4
//   0x8984: 91004100  add        x0, x8, #0x10
//   0x8988: 910183e1  add        x1, sp, #0x60
//   0x898c: 94000401  bl         #0x9990
//   0x8990: b40009a0  cbz        x0, #0x8ac4
//   0x8994: 940003e7  bl         #0x9930
//   0x8998: b9406e96  ldr        w22, [x20, #0x6c]
//   0x899c: 2a0003f5  mov        w21, w0
//   0x89a0: b0ffffc3  adrp       x3, #0x1000
//   0x89a4: 91316063  add        x3, x3, #0xc58
//   0x89a8: 910263e0  add        x0, sp, #0x98
//   0x89ac: 52800801  mov        w1, #0x40
//   0x89b0: 52800802  mov        w2, #0x40
//   0x89b4: 2a1603e4  mov        w4, w22
//   0x89b8: 940000c7  bl         #0x8cd4
//   0x89bc: 910263e0  add        x0, sp, #0x98
//   0x89c0: 52a00101  mov        w1, #0x80000
//   0x89c4: 940003e3  bl         #0x9950
//   0x89c8: 37f801c0  tbnz       w0, #0x1f, #0x8a00
//   0x89cc: 910263e1  add        x1, sp, #0x98
//   0x89d0: 52800802  mov        w2, #0x40
//   0x89d4: 2a0003f8  mov        w24, w0
//   0x89d8: 940003e2  bl         #0x9960
//   0x89dc: aa0003f7  mov        x23, x0
//   0x89e0: 2a1803e0  mov        w0, w24
//   0x89e4: 940003c7  bl         #0x9900
//   0x89e8: f10006e8  subs       x8, x23, #1
//   0x89ec: 540000ab  b.lt       #0x8a00
//   0x89f0: f10102ff  cmp        x23, #0x40
//   0x89f4: 540000a1  b.ne       #0x8a08
//   0x89f8: 528007e8  mov        w8, #0x3f
//   0x89fc: 14000007  b          #0x8a18
//   0x8a00: aa1f03e6  mov        x6, xzr
//   0x8a04: 1400000b  b          #0x8a30
//   0x8a08: 910263e9  add        x9, sp, #0x98
//   0x8a0c: 38686929  ldrb       w9, [x9, x8]
//   0x8a10: 7100293f  cmp        w9, #0xa
//   0x8a14: 54000041  b.ne       #0x8a1c
//   0x8a18: aa0803f7  mov        x23, x8
//   0x8a1c: 910263e0  add        x0, sp, #0x98
//   0x8a20: 910263e8  add        x8, sp, #0x98
//   0x8a24: 3837691f  strb       wzr, [x8, x23]
//   0x8a28: 94000346  bl         #0x9740
//   0x8a2c: aa0003e6  mov        x6, x0
//   0x8a30: 294e27ea  ldp        w10, w9, [sp, #0x70]
//   0x8a34: a9441e88  ldp        x8, x7, [x20, #0x40]
//   0x8a38: d0ffffc3  adrp       x3, #0x2000
//   0x8a3c: 91004063  add        x3, x3, #0x10
//   0x8a40: 294d2fec  ldp        w12, w11, [sp, #0x68]
//   0x8a44: 294c37ee  ldp        w14, w13, [sp, #0x60]
//   0x8a48: 3dc01680  ldr        q0, [x20, #0x50]
//   0x8a4c: 111db129  add        w9, w9, #0x76c
//   0x8a50: 3dc00e81  ldr        q1, [x20, #0x30]
//   0x8a54: 1100054a  add        w10, w10, #1
//   0x8a58: 910263e0  add        x0, sp, #0x98
//   0x8a5c: 52808001  mov        w1, #0x400
//   0x8a60: 52807fe2  mov        w2, #0x3ff
//   0x8a64: 2a1503e4  mov        w4, w21
//   0x8a68: 2a1603e5  mov        w5, w22
//   0x8a6c: b90053ee  str        w14, [sp, #0x50]
//   0x8a70: b9004bed  str        w13, [sp, #0x48]
//   0x8a74: b90043ec  str        w12, [sp, #0x40]
//   0x8a78: b9003beb  str        w11, [sp, #0x38]
//   0x8a7c: b90033ea  str        w10, [sp, #0x30]
//   0x8a80: b9002be9  str        w9, [sp, #0x28]
//   0x8a84: f90013e8  str        x8, [sp, #0x20]
//   0x8a88: ad0007e0  stp        q0, q1, [sp]
//   0x8a8c: 94000092  bl         #0x8cd4
//   0x8a90: 2a0003f5  mov        w21, w0
//   0x8a94: d0ffffc1  adrp       x1, #0x2000
//   0x8a98: 9119f021  add        x1, x1, #0x67c
//   0x8a9c: 2a1303e0  mov        w0, w19
//   0x8aa0: 52800822  mov        w2, #0x41
//   0x8aa4: 940003b3  bl         #0x9970
//   0x8aa8: 510006a8  sub        w8, w21, #1
//   0x8aac: 710ff91f  cmp        w8, #0x3fe
//   0x8ab0: 540000a8  b.hi       #0x8ac4
//   0x8ab4: 2a1503e2  mov        w2, w21
//   0x8ab8: 910263e1  add        x1, sp, #0x98
//   0x8abc: 2a1303e0  mov        w0, w19
//   0x8ac0: 940003ac  bl         #0x9970
//   0x8ac4: f9403288  ldr        x8, [x20, #0x60]
//   0x8ac8: a9400500  ldp        x0, x1, [x8]
//   0x8acc: 940003f5  bl         #0x9aa0
//   0x8ad0: 910183fb  add        x27, sp, #0x60
//   0x8ad4: a9066ffb  stp        x27, x27, [sp, #0x60]
//   0x8ad8: b4000e20  cbz        x0, #0x8c9c
//   0x8adc: aa0003f4  mov        x20, x0
//   0x8ae0: aa0003f8  mov        x24, x0
//   0x8ae4: d503201f  nop        
//   0x8ae8: 50fcaff5  adr        x21, #0x20e6
//   0x8aec: b0ffffd6  adrp       x22, #0x1000
//   0x8af0: 9129ced6  add        x22, x22, #0xa73
//   0x8af4: aa1803e0  mov        x0, x24
//   0x8af8: 52800141  mov        w1, #0xa
//   0x8afc: 940003ed  bl         #0x9ab0
//   0x8b00: aa0003f7  mov        x23, x0
//   0x8b04: b4000040  cbz        x0, #0x8b0c
//   0x8b08: 390002ff  strb       wzr, [x23]
//   0x8b0c: 910263e0  add        x0, sp, #0x98
//   0x8b10: 52808001  mov        w1, #0x400
//   0x8b14: 52808002  mov        w2, #0x400
//   0x8b18: aa1503e3  mov        x3, x21
//   0x8b1c: aa1803e4  mov        x4, x24
//   0x8b20: 9400006d  bl         #0x8cd4
//   0x8b24: 7100041f  cmp        w0, #1
//   0x8b28: 540000ab  b.lt       #0x8b3c
//   0x8b2c: 2a0003e2  mov        w2, w0
//   0x8b30: 910263e1  add        x1, sp, #0x98
//   0x8b34: 2a1303e0  mov        w0, w19
//   0x8b38: 9400038e  bl         #0x9970
//   0x8b3c: aa1803e0  mov        x0, x24
//   0x8b40: 528005e1  mov        w1, #0x2f
//   0x8b44: 940003db  bl         #0x9ab0
//   0x8b48: b4000320  cbz        x0, #0x8bac
//   0x8b4c: aa1603e1  mov        x1, x22
//   0x8b50: aa0003f8  mov        x24, x0
//   0x8b54: 940003af  bl         #0x9a10
//   0x8b58: b40002a0  cbz        x0, #0x8bac
//   0x8b5c: 910183f9  add        x25, sp, #0x60
//   0x8b60: 39000c1f  strb       wzr, [x0, #3]
//   0x8b64: f9400339  ldr        x25, [x25]
//   0x8b68: eb1b033f  cmp        x25, x27
//   0x8b6c: 540000c0  b.eq       #0x8b84
//   0x8b70: f9400b20  ldr        x0, [x25, #0x10]
//   0x8b74: aa1803e1  mov        x1, x24
//   0x8b78: 940003d2  bl         #0x9ac0
//   0x8b7c: 35ffff40  cbnz       w0, #0x8b64
//   0x8b80: 1400000b  b          #0x8bac
//   0x8b84: 52800300  mov        w0, #0x18
//   0x8b88: 94000342  bl         #0x9890
//   0x8b8c: aa0003f9  mov        x25, x0
//   0x8b90: aa1803e0  mov        x0, x24
//   0x8b94: 940002eb  bl         #0x9740
//   0x8b98: f94033e8  ldr        x8, [sp, #0x60]
//   0x8b9c: a900833b  stp        x27, x0, [x25, #8]
//   0x8ba0: f90033f9  str        x25, [sp, #0x60]
//   0x8ba4: f9000328  str        x8, [x25]
//   0x8ba8: f9000519  str        x25, [x8, #8]
//   0x8bac: b4000097  cbz        x23, #0x8bbc
//   0x8bb0: 38401ee8  ldrb       w8, [x23, #1]!
//   0x8bb4: aa1703f8  mov        x24, x23
//   0x8bb8: 35fff9e8  cbnz       w8, #0x8af4
//   0x8bbc: d0ffffc1  adrp       x1, #0x2000
//   0x8bc0: 910a2c21  add        x1, x1, #0x28b
//   0x8bc4: 2a1303e0  mov        w0, w19
//   0x8bc8: 52800022  mov        w2, #1
//   0x8bcc: 94000369  bl         #0x9970
//   0x8bd0: aa1403e0  mov        x0, x20
//   0x8bd4: 94000333  bl         #0x98a0
//   0x8bd8: f94033e8  ldr        x8, [sp, #0x60]
//   0x8bdc: 910183f5  add        x21, sp, #0x60
//   0x8be0: eb0802bf  cmp        x21, x8
//   0x8be4: 540005c0  b.eq       #0x8c9c
//   0x8be8: b0ffffc1  adrp       x1, #0x1000
//   0x8bec: 912bac21  add        x1, x1, #0xaeb
//   0x8bf0: 2a1303e0  mov        w0, w19
//   0x8bf4: 52800142  mov        w2, #0xa
//   0x8bf8: 9400035e  bl         #0x9970
//   0x8bfc: f94033f4  ldr        x20, [sp, #0x60]
//   0x8c00: eb15029f  cmp        x20, x21
//   0x8c04: 540004c0  b.eq       #0x8c9c
//   0x8c08: 910183f7  add        x23, sp, #0x60
//   0x8c0c: b0ffffd5  adrp       x21, #0x1000
//   0x8c10: 913a3ab5  add        x21, x21, #0xe8e
//   0x8c14: 14000006  b          #0x8c2c
//   0x8c18: aa1403e0  mov        x0, x20
//   0x8c1c: 94000321  bl         #0x98a0
//   0x8c20: aa1803f4  mov        x20, x24
//   0x8c24: eb17031f  cmp        x24, x23
//   0x8c28: 540003a0  b.eq       #0x8c9c
//   0x8c2c: f9400a80  ldr        x0, [x20, #0x10]
//   0x8c30: f9400298  ldr        x24, [x20]
//   0x8c34: 940003a7  bl         #0x9ad0
//   0x8c38: b4000220  cbz        x0, #0x8c7c
//   0x8c3c: aa0003f6  mov        x22, x0
//   0x8c40: f9400a84  ldr        x4, [x20, #0x10]
//   0x8c44: 910263e0  add        x0, sp, #0x98
//   0x8c48: 52808001  mov        w1, #0x400
//   0x8c4c: 52808002  mov        w2, #0x400
//   0x8c50: aa1503e3  mov        x3, x21
//   0x8c54: aa1603e5  mov        x5, x22
//   0x8c58: 9400001f  bl         #0x8cd4
//   0x8c5c: 7100041f  cmp        w0, #1
//   0x8c60: 540000ab  b.lt       #0x8c74
//   0x8c64: 2a0003e2  mov        w2, w0
//   0x8c68: 910263e1  add        x1, sp, #0x98
//   0x8c6c: 2a1303e0  mov        w0, w19
//   0x8c70: 94000340  bl         #0x9970
//   0x8c74: aa1603e0  mov        x0, x22
//   0x8c78: 9400030a  bl         #0x98a0
//   0x8c7c: a9402289  ldp        x9, x8, [x20]
//   0x8c80: f9000528  str        x8, [x9, #8]
//   0x8c84: f9400688  ldr        x8, [x20, #8]
//   0x8c88: f9000109  str        x9, [x8]
//   0x8c8c: f9400a80  ldr        x0, [x20, #0x10]
//   0x8c90: b4fffc40  cbz        x0, #0x8c18
//   0x8c94: 94000303  bl         #0x98a0
//   0x8c98: 17ffffe0  b          #0x8c18
//   0x8c9c: f9401748  ldr        x8, [x26, #0x28]
//   0x8ca0: f85f83a9  ldur       x9, [x29, #-8]
//   0x8ca4: eb09011f  cmp        x8, x9
//   0x8ca8: 54000141  b.ne       #0x8cd0
//   0x8cac: 2a1f03e0  mov        w0, wzr
//   0x8cb0: 911283ff  add        sp, sp, #0x4a0
//   0x8cb4: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x8cb8: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x8cbc: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x8cc0: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x8cc4: a9416ffc  ldp        x28, x27, [sp, #0x10]
//   0x8cc8: a8c67bfd  ldp        x29, x30, [sp], #0x60
//   0x8ccc: d65f03c0  ret        
//   0x8cd0: 940002e4  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[71] HeapTrackerFde_8cd4 (0x8cd4..0x8d78, 164 bytes, 41 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8cd4..0x8d78
// ----------------------------------------------------------------------------
//   0x8cd4: d10443ff  sub        sp, sp, #0x110
//   0x8cd8: a90f7bfd  stp        x29, x30, [sp, #0xf0]
//   0x8cdc: a9104ffc  stp        x28, x19, [sp, #0x100]
//   0x8ce0: 9103c3fd  add        x29, sp, #0xf0
//   0x8ce4: a93917a4  stp        x4, x5, [x29, #-0x70]
//   0x8ce8: d101c3aa  sub        x10, x29, #0x70
//   0x8cec: a93a1fa6  stp        x6, x7, [x29, #-0x60]
//   0x8cf0: 928003ec  mov        x12, #-0x20
//   0x8cf4: ad0007e0  stp        q0, q1, [sp]
//   0x8cf8: 910003ed  mov        x13, sp
//   0x8cfc: ad010fe2  stp        q2, q3, [sp, #0x20]
//   0x8d00: 9100814a  add        x10, x10, #0x20
//   0x8d04: ad0217e4  stp        q4, q5, [sp, #0x40]
//   0x8d08: f2dff00c  movk       x12, #0xff80, lsl #32
//   0x8d0c: ad031fe6  stp        q6, q7, [sp, #0x60]
//   0x8d10: d53bd053  mrs        x19, tpidr_el0
//   0x8d14: f9401669  ldr        x9, [x19, #0x28]
//   0x8d18: 910201ad  add        x13, x13, #0x80
//   0x8d1c: d100a3ab  sub        x11, x29, #0x28
//   0x8d20: aa0303e8  mov        x8, x3
//   0x8d24: aa0103e3  mov        x3, x1
//   0x8d28: d10143a5  sub        x5, x29, #0x50
//   0x8d2c: f81f83a9  stur       x9, [x29, #-8]
//   0x8d30: 910083a9  add        x9, x29, #0x20
//   0x8d34: a93eb3ad  stp        x13, x12, [x29, #-0x18]
//   0x8d38: aa0203e1  mov        x1, x2
//   0x8d3c: 2a1f03e2  mov        w2, wzr
//   0x8d40: aa0803e4  mov        x4, x8
//   0x8d44: a93daba9  stp        x9, x10, [x29, #-0x28]
//   0x8d48: ad400560  ldp        q0, q1, [x11]
//   0x8d4c: ad3d87a0  stp        q0, q1, [x29, #-0x50]
//   0x8d50: 9400030c  bl         #0x9980
//   0x8d54: f9401668  ldr        x8, [x19, #0x28]
//   0x8d58: f85f83a9  ldur       x9, [x29, #-8]
//   0x8d5c: eb09011f  cmp        x8, x9
//   0x8d60: 540000a1  b.ne       #0x8d74
//   0x8d64: a9504ffc  ldp        x28, x19, [sp, #0x100]
//   0x8d68: a94f7bfd  ldp        x29, x30, [sp, #0xf0]
//   0x8d6c: 910443ff  add        sp, sp, #0x110
//   0x8d70: d65f03c0  ret        
//   0x8d74: 940002bb  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[72] HeapTrackerFde_8d78 (0x8d78..0x8e74, 252 bytes, 63 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8d78..0x8e74
// ----------------------------------------------------------------------------
//   0x8d78: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x8d7c: f9000bfc  str        x28, [sp, #0x10]
//   0x8d80: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x8d84: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x8d88: 910003fd  mov        x29, sp
//   0x8d8c: d110c3ff  sub        sp, sp, #0x430
//   0x8d90: d53bd056  mrs        x22, tpidr_el0
//   0x8d94: 2a0003f3  mov        w19, w0
//   0x8d98: f94016c8  ldr        x8, [x22, #0x28]
//   0x8d9c: f81f83a8  stur       x8, [x29, #-8]
//   0x8da0: f9401c35  ldr        x21, [x1, #0x38]
//   0x8da4: 910023e1  add        x1, sp, #8
//   0x8da8: aa1503e0  mov        x0, x21
//   0x8dac: 94000301  bl         #0x99b0
//   0x8db0: 34000360  cbz        w0, #0x8e1c
//   0x8db4: a9411fe8  ldp        x8, x7, [sp, #0x10]
//   0x8db8: f94007e6  ldr        x6, [sp, #8]
//   0x8dbc: cb0802a5  sub        x5, x21, x8
//   0x8dc0: b4000427  cbz        x7, #0x8e44
//   0x8dc4: f94013e8  ldr        x8, [sp, #0x20]
//   0x8dc8: 2a0003f4  mov        w20, w0
//   0x8dcc: b0ffffc3  adrp       x3, #0x1000
//   0x8dd0: 91294063  add        x3, x3, #0xa50
//   0x8dd4: 9100a3e0  add        x0, sp, #0x28
//   0x8dd8: 52808001  mov        w1, #0x400
//   0x8ddc: cb0802a8  sub        x8, x21, x8
//   0x8de0: 52807fe2  mov        w2, #0x3ff
//   0x8de4: aa1f03e4  mov        x4, xzr
//   0x8de8: f90003e8  str        x8, [sp]
//   0x8dec: 97ffffba  bl         #0x8cd4
//   0x8df0: 2a0003f5  mov        w21, w0
//   0x8df4: 71000a9f  cmp        w20, #2
//   0x8df8: 54000061  b.ne       #0x8e04
//   0x8dfc: f9400fe0  ldr        x0, [sp, #0x18]
//   0x8e00: 940002a8  bl         #0x98a0
//   0x8e04: 710006bf  cmp        w21, #1
//   0x8e08: 540000ab  b.lt       #0x8e1c
//   0x8e0c: 2a1503e2  mov        w2, w21
//   0x8e10: 9100a3e1  add        x1, sp, #0x28
//   0x8e14: 2a1303e0  mov        w0, w19
//   0x8e18: 940002d6  bl         #0x9970
//   0x8e1c: f94016c8  ldr        x8, [x22, #0x28]
//   0x8e20: f85f83a9  ldur       x9, [x29, #-8]
//   0x8e24: eb09011f  cmp        x8, x9
//   0x8e28: 54000241  b.ne       #0x8e70
//   0x8e2c: 9110c3ff  add        sp, sp, #0x430
//   0x8e30: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x8e34: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x8e38: f9400bfc  ldr        x28, [sp, #0x10]
//   0x8e3c: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x8e40: d65f03c0  ret        
//   0x8e44: b0ffffc3  adrp       x3, #0x1000
//   0x8e48: 91319863  add        x3, x3, #0xc66
//   0x8e4c: 9100a3e0  add        x0, sp, #0x28
//   0x8e50: 52808001  mov        w1, #0x400
//   0x8e54: 52807fe2  mov        w2, #0x3ff
//   0x8e58: aa1f03e4  mov        x4, xzr
//   0x8e5c: 97ffff9e  bl         #0x8cd4
//   0x8e60: 2a0003f5  mov        w21, w0
//   0x8e64: 710006bf  cmp        w21, #1
//   0x8e68: 54fffd2a  b.ge       #0x8e0c
//   0x8e6c: 17ffffec  b          #0x8e1c
//   0x8e70: 9400027c  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[73] HeapTrackerFde_8e74 (0x8e74..0x8f5c, 232 bytes, 58 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8e74..0x8f5c
// ----------------------------------------------------------------------------
//   0x8e74: a9bc7bfd  stp        x29, x30, [sp, #-0x40]!
//   0x8e78: f9000bf7  str        x23, [sp, #0x10]
//   0x8e7c: a90257f6  stp        x22, x21, [sp, #0x20]
//   0x8e80: a9034ff4  stp        x20, x19, [sp, #0x30]
//   0x8e84: 910003fd  mov        x29, sp
//   0x8e88: d503201f  nop        
//   0x8e8c: 100490b6  adr        x22, #0x120a0
//   0x8e90: f94002c8  ldr        x8, [x22]
//   0x8e94: b941e908  ldr        w8, [x8, #0x1e8]
//   0x8e98: 7100051f  cmp        w8, #1
//   0x8e9c: 5400056b  b.lt       #0x8f48
//   0x8ea0: aa1f03e2  mov        x2, xzr
//   0x8ea4: aa0103f3  mov        x19, x1
//   0x8ea8: 97fff86c  bl         #0x7058
//   0x8eac: aa0003f4  mov        x20, x0
//   0x8eb0: f94002c8  ldr        x8, [x22]
//   0x8eb4: 52801717  mov        w23, #0xb8
//   0x8eb8: 14000007  b          #0x8ed4
//   0x8ebc: f9401ea9  ldr        x9, [x21, #0x38]
//   0x8ec0: eb14013f  cmp        x9, x20
//   0x8ec4: 54000160  b.eq       #0x8ef0
//   0x8ec8: 910022f7  add        x23, x23, #8
//   0x8ecc: f10422ff  cmp        x23, #0x108
//   0x8ed0: 540003c0  b.eq       #0x8f48
//   0x8ed4: f8776915  ldr        x21, [x8, x23]
//   0x8ed8: b4000395  cbz        x21, #0x8f48
//   0x8edc: f94032a9  ldr        x9, [x21, #0x60]
//   0x8ee0: b4fffee9  cbz        x9, #0x8ebc
//   0x8ee4: f9400529  ldr        x9, [x9, #8]
//   0x8ee8: b5ffff09  cbnz       x9, #0x8ec8
//   0x8eec: 17fffff4  b          #0x8ebc
//   0x8ef0: f94022a9  ldr        x9, [x21, #0x40]
//   0x8ef4: eb13013f  cmp        x9, x19
//   0x8ef8: 54fffe81  b.ne       #0x8ec8
//   0x8efc: aa1503e0  mov        x0, x21
//   0x8f00: 52800061  mov        w1, #3
//   0x8f04: 97fffe39  bl         #0x87e8
//   0x8f08: f94002c8  ldr        x8, [x22]
//   0x8f0c: 9107d100  add        x0, x8, #0x1f4
//   0x8f10: 940002a4  bl         #0x99a0
//   0x8f14: f94002c8  ldr        x8, [x22]
//   0x8f18: aa1503e1  mov        x1, x21
//   0x8f1c: 52800022  mov        w2, #1
//   0x8f20: b941dd00  ldr        w0, [x8, #0x1dc]
//   0x8f24: 97fffe88  bl         #0x8944
//   0x8f28: f94002c8  ldr        x8, [x22]
//   0x8f2c: 9107d100  add        x0, x8, #0x1f4
//   0x8f30: 940002a8  bl         #0x99d0
//   0x8f34: f94002c8  ldr        x8, [x22]
//   0x8f38: b941e909  ldr        w9, [x8, #0x1e8]
//   0x8f3c: 51000529  sub        w9, w9, #1
//   0x8f40: b901e909  str        w9, [x8, #0x1e8]
//   0x8f44: 17ffffe1  b          #0x8ec8
//   0x8f48: a9434ff4  ldp        x20, x19, [sp, #0x30]
//   0x8f4c: a94257f6  ldp        x22, x21, [sp, #0x20]
//   0x8f50: f9400bf7  ldr        x23, [sp, #0x10]
//   0x8f54: a8c47bfd  ldp        x29, x30, [sp], #0x40
//   0x8f58: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[74] HeapTrackerFde_8f5c (0x8f5c..0x9064, 264 bytes, 66 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x8f5c..0x9064
// ----------------------------------------------------------------------------
//   0x8f5c: d10183ff  sub        sp, sp, #0x60
//   0x8f60: a9017bfd  stp        x29, x30, [sp, #0x10]
//   0x8f64: a90267fa  stp        x26, x25, [sp, #0x20]
//   0x8f68: a9035ff8  stp        x24, x23, [sp, #0x30]
//   0x8f6c: a90457f6  stp        x22, x21, [sp, #0x40]
//   0x8f70: a9054ff4  stp        x20, x19, [sp, #0x50]
//   0x8f74: 910043fd  add        x29, sp, #0x10
//   0x8f78: d53bd055  mrs        x21, tpidr_el0
//   0x8f7c: aa0103f3  mov        x19, x1
//   0x8f80: f94016a8  ldr        x8, [x21, #0x28]
//   0x8f84: 2a0003f4  mov        w20, w0
//   0x8f88: f90007e8  str        x8, [sp, #8]
//   0x8f8c: 940001f9  bl         #0x9770
//   0x8f90: 37f800b4  tbnz       w20, #0x1f, #0x8fa4
//   0x8f94: f9402668  ldr        x8, [x19, #0x48]
//   0x8f98: 93407c16  sxtw       x22, w0
//   0x8f9c: eb16051f  cmp        x8, x22, lsl #1
//   0x8fa0: 54000062  b.hs       #0x8fac
//   0x8fa4: 12800000  mov        w0, #-1
//   0x8fa8: 14000023  b          #0x9034
//   0x8fac: f9401a69  ldr        x9, [x19, #0x30]
//   0x8fb0: 8b0802c8  add        x8, x22, x8
//   0x8fb4: cb1603ea  neg        x10, x22
//   0x8fb8: aa1f03f8  mov        x24, xzr
//   0x8fbc: aa1f03f7  mov        x23, xzr
//   0x8fc0: 8b090108  add        x8, x8, x9
//   0x8fc4: 8a0a0139  and        x25, x9, x10
//   0x8fc8: d1000508  sub        x8, x8, #1
//   0x8fcc: 8a0a011a  and        x26, x8, x10
//   0x8fd0: eb1a033f  cmp        x25, x26
//   0x8fd4: 54000242  b.hs       #0x901c
//   0x8fd8: aa1f03f7  mov        x23, xzr
//   0x8fdc: aa1f03f8  mov        x24, xzr
//   0x8fe0: 9ad60b28  udiv       x8, x25, x22
//   0x8fe4: 910003e1  mov        x1, sp
//   0x8fe8: 2a1403e0  mov        w0, w20
//   0x8fec: 52800102  mov        w2, #8
//   0x8ff0: d37df103  lsl        x3, x8, #3
//   0x8ff4: 940002bb  bl         #0x9ae0
//   0x8ff8: f100201f  cmp        x0, #8
//   0x8ffc: 540001a1  b.ne       #0x9030
//   0x9000: f94003e8  ldr        x8, [sp]
//   0x9004: 8b160339  add        x25, x25, x22
//   0x9008: eb1a033f  cmp        x25, x26
//   0x900c: 8b48ff18  add        x24, x24, x8, lsr #63
//   0x9010: d37ef908  ubfx       x8, x8, #0x3e, #1
//   0x9014: 8b170117  add        x23, x8, x23
//   0x9018: 54fffe43  b.lo       #0x8fe0
//   0x901c: 9b167f08  mul        x8, x24, x22
//   0x9020: 2a1f03e0  mov        w0, wzr
//   0x9024: 9b167ee9  mul        x9, x23, x22
//   0x9028: a9052668  stp        x8, x9, [x19, #0x50]
//   0x902c: 14000002  b          #0x9034
//   0x9030: 12800020  mov        w0, #-2
//   0x9034: f94016a8  ldr        x8, [x21, #0x28]
//   0x9038: f94007e9  ldr        x9, [sp, #8]
//   0x903c: eb09011f  cmp        x8, x9
//   0x9040: 54000101  b.ne       #0x9060
//   0x9044: a9454ff4  ldp        x20, x19, [sp, #0x50]
//   0x9048: a94457f6  ldp        x22, x21, [sp, #0x40]
//   0x904c: a9435ff8  ldp        x24, x23, [sp, #0x30]
//   0x9050: a94267fa  ldp        x26, x25, [sp, #0x20]
//   0x9054: a9417bfd  ldp        x29, x30, [sp, #0x10]
//   0x9058: 910183ff  add        sp, sp, #0x60
//   0x905c: d65f03c0  ret        
//   0x9060: 94000200  bl         #0x9860

// ----------------------------------------------------------------------------
// FDE[75] HeapTrackerFde_9064 (0x9064..0x9108, 164 bytes, 41 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x9064..0x9108
// ----------------------------------------------------------------------------
//   0x9064: a9be7bfd  stp        x29, x30, [sp, #-0x20]!
//   0x9068: f9000bf3  str        x19, [sp, #0x10]
//   0x906c: 910003fd  mov        x29, sp
//   0x9070: 52800060  mov        w0, #3
//   0x9074: 9400029f  bl         #0x9af0
//   0x9078: b0000048  adrp       x8, #0x12000
//   0x907c: 52800021  mov        w1, #1
//   0x9080: b900e100  str        w0, [x8, #0xe0]
//   0x9084: 52800080  mov        w0, #4
//   0x9088: 9400029a  bl         #0x9af0
//   0x908c: 34000160  cbz        w0, #0x90b8
//   0x9090: d503201f  nop        
//   0x9094: 10fc4b41  adr        x1, #0x19fc
//   0x9098: 90ffffc2  adrp       x2, #0x1000
//   0x909c: 913a9042  add        x2, x2, #0xea4
//   0x90a0: b0ffffc3  adrp       x3, #0x2000
//   0x90a4: 91021863  add        x3, x3, #0x86
//   0x90a8: 528000c0  mov        w0, #6
//   0x90ac: 940001b9  bl         #0x9790
//   0x90b0: 12800013  mov        w19, #-1
//   0x90b4: 14000011  b          #0x90f8
//   0x90b8: 90ffffc0  adrp       x0, #0x1000
//   0x90bc: 913cac00  add        x0, x0, #0xf2b
//   0x90c0: 2a1f03e1  mov        w1, wzr
//   0x90c4: 94000223  bl         #0x9950
//   0x90c8: 2a0003f3  mov        w19, w0
//   0x90cc: 36f80160  tbz        w0, #0x1f, #0x90f8
//   0x90d0: 940001dc  bl         #0x9840
//   0x90d4: b9400004  ldr        w4, [x0]
//   0x90d8: d503201f  nop        
//   0x90dc: 10fc4901  adr        x1, #0x19fc
//   0x90e0: 90ffffc2  adrp       x2, #0x1000
//   0x90e4: 913da842  add        x2, x2, #0xf6a
//   0x90e8: b0ffffc3  adrp       x3, #0x2000
//   0x90ec: 91021863  add        x3, x3, #0x86
//   0x90f0: 528000c0  mov        w0, #6
//   0x90f4: 940001a7  bl         #0x9790
//   0x90f8: 2a1303e0  mov        w0, w19
//   0x90fc: f9400bf3  ldr        x19, [sp, #0x10]
//   0x9100: a8c27bfd  ldp        x29, x30, [sp], #0x20
//   0x9104: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[76] HeapTrackerFde_9108 (0x9108..0x9130, 40 bytes, 10 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x9108..0x9130
// ----------------------------------------------------------------------------
//   0x9108: 37f80120  tbnz       w0, #0x1f, #0x912c
//   0x910c: a9bf7bfd  stp        x29, x30, [sp, #-0x10]!
//   0x9110: 910003fd  mov        x29, sp
//   0x9114: 940001fb  bl         #0x9900
//   0x9118: b0000048  adrp       x8, #0x12000
//   0x911c: b940e101  ldr        w1, [x8, #0xe0]
//   0x9120: 52800080  mov        w0, #4
//   0x9124: a8c17bfd  ldp        x29, x30, [sp], #0x10
//   0x9128: 14000272  b          #0x9af0
//   0x912c: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[77] HeapTrackerFde_9130 (0x9130..0x9164, 52 bytes, 13 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x9130..0x9164
// ----------------------------------------------------------------------------
//   0x9130: d503245f  bti        c
//   0x9134: b0000050  adrp       x16, #0x12000
//   0x9138: 39439210  ldrb       w16, [x16, #0xe4]
//   0x913c: 34000070  cbz        w16, #0x9148
//   0x9140: 88e07c41  casa       w0, w1, [x2]
//   0x9144: d65f03c0  ret        
//   0x9148: 2a0003f0  mov        w16, w0
//   0x914c: 885ffc40  ldaxr      w0, [x2]
//   0x9150: 6b10001f  cmp        w0, w16
//   0x9154: 54000061  b.ne       #0x9160
//   0x9158: 88117c41  stxr       w17, w1, [x2]
//   0x915c: 35ffff91  cbnz       w17, #0x914c
//   0x9160: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[78] HeapTrackerFde_9164 (0x9164..0x91fc, 152 bytes, 38 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x9164..0x91fc
// ----------------------------------------------------------------------------
//   0x9164: d503233f  paciasp    
//   0x9168: d101c3ff  sub        sp, sp, #0x70
//   0x916c: a9064ffe  stp        x30, x19, [sp, #0x60]
//   0x9170: 52800200  mov        w0, #0x10
//   0x9174: 9400026b  bl         #0x9b20
//   0x9178: aa0003f3  mov        x19, x0
//   0x917c: 374000f3  tbnz       w19, #8, #0x9198
//   0x9180: a9464ffe  ldp        x30, x19, [sp, #0x60]
//   0x9184: b0000049  adrp       x9, #0x12000
//   0x9188: 3903913f  strb       wzr, [x9, #0xe4]
//   0x918c: 9101c3ff  add        sp, sp, #0x70
//   0x9190: d50323bf  autiasp    
//   0x9194: d65f03c0  ret        
//   0x9198: d503201f  nop        
//   0x919c: 50fc4ce0  adr        x0, #0x1b3a
//   0x91a0: 910013e1  add        x1, sp, #4
//   0x91a4: 9400025b  bl         #0x9b10
//   0x91a8: 7100041f  cmp        w0, #1
//   0x91ac: 5400016b  b.lt       #0x91d8
//   0x91b0: b0ffffc1  adrp       x1, #0x2000
//   0x91b4: 910eec21  add        x1, x1, #0x3bb
//   0x91b8: 910013e0  add        x0, sp, #4
//   0x91bc: 52800142  mov        w2, #0xa
//   0x91c0: 92780268  and        x8, x19, #0x100
//   0x91c4: d348fd13  lsr        x19, x8, #8
//   0x91c8: 9400024e  bl         #0x9b00
//   0x91cc: 7100001f  cmp        w0, #0
//   0x91d0: 1a9303e8  csel       w8, wzr, w19, eq
//   0x91d4: 14000002  b          #0x91dc
//   0x91d8: d3482268  ubfx       x8, x19, #8, #1
//   0x91dc: 7100011f  cmp        w8, #0
//   0x91e0: 1a9f07e8  cset       w8, ne
//   0x91e4: a9464ffe  ldp        x30, x19, [sp, #0x60]
//   0x91e8: b0000049  adrp       x9, #0x12000
//   0x91ec: 39039128  strb       w8, [x9, #0xe4]
//   0x91f0: 9101c3ff  add        sp, sp, #0x70
//   0x91f4: d50323bf  autiasp    
//   0x91f8: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[79] HeapTrackerFde_91fc (0x91fc..0x9634, 1080 bytes, 270 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x91fc..0x9634
// ----------------------------------------------------------------------------
//   0x91fc: d503245f  bti        c
//   0x9200: a9bd5ff8  stp        x24, x23, [sp, #-0x30]!
//   0x9204: a90157f6  stp        x22, x21, [sp, #0x10]
//   0x9208: a9024ff4  stp        x20, x19, [sp, #0x20]
//   0x920c: b0000048  adrp       x8, #0x12000
//   0x9210: f9407509  ldr        x9, [x8, #0xe8]
//   0x9214: b40000a9  cbz        x9, #0x9228
//   0x9218: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x921c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x9220: a8c35ff8  ldp        x24, x23, [sp], #0x30
//   0x9224: d65f03c0  ret        
//   0x9228: b7f00060  tbnz       x0, #0x3e, #0x9234
//   0x922c: aa1f03e9  mov        x9, xzr
//   0x9230: 14000002  b          #0x9238
//   0x9234: f9400829  ldr        x9, [x1, #0x10]
//   0x9238: d344fc0a  lsr        x10, x0, #4
//   0x923c: 531d700b  lsl        w11, w0, #3
//   0x9240: d35afc0c  lsr        x12, x0, #0x1a
//   0x9244: 9276016b  and        x11, x11, #0x400
//   0x9248: f279013f  tst        x9, #0x80
//   0x924c: 927f018c  and        x12, x12, #2
//   0x9250: 528000cd  mov        w13, #6
//   0x9254: b371014b  bfi        x11, x10, #0xf, #1
//   0x9258: 9a8d018c  csel       x12, x12, x13, eq
//   0x925c: d350fc0f  lsr        x15, x0, #0x10
//   0x9260: aa0b018e  orr        x14, x12, x11
//   0x9264: 926e040c  and        x12, x0, #0xc0000
//   0x9268: d354fc10  lsr        x16, x0, #0x14
//   0x926c: b27b01cd  orr        x13, x14, #0x20
//   0x9270: f143019f  cmp        x12, #0xc0, lsl #12
//   0x9274: 927c01ef  and        x15, x15, #0x10
//   0x9278: 927d0210  and        x16, x16, #8
//   0x927c: 9a8e01ae  csel       x14, x13, x14, eq
//   0x9280: aa0f020f  orr        x15, x16, x15
//   0x9284: d347fc10  lsr        x16, x0, #7
//   0x9288: aa0e01ef  orr        x15, x15, x14
//   0x928c: 5280200e  mov        w14, #0x100
//   0x9290: 72a0002e  movk       w14, #1, lsl #16
//   0x9294: d346fc11  lsr        x17, x0, #6
//   0x9298: aa0e01ee  orr        x14, x15, x14
//   0x929c: f277001f  tst        x0, #0x200
//   0x92a0: 926f0210  and        x16, x16, #0x20000
//   0x92a4: 927a0231  and        x17, x17, #0x40
//   0x92a8: 9a8e01ef  csel       x15, x15, x14, eq
//   0x92ac: aa100230  orr        x16, x17, x16
//   0x92b0: aa0f020f  orr        x15, x16, x15
//   0x92b4: d375d011  lsl        x17, x0, #0xb
//   0x92b8: 531a6401  lsl        w1, w0, #6
//   0x92bc: b26901f0  orr        x16, x15, #0x800000
//   0x92c0: f266001f  tst        x0, #0x4000000
//   0x92c4: 92720231  and        x17, x17, #0x4000
//   0x92c8: 92750021  and        x1, x1, #0x800
//   0x92cc: 9a9001ef  csel       x15, x15, x16, eq
//   0x92d0: aa110031  orr        x17, x1, x17
//   0x92d4: d379e001  lsl        x1, x0, #7
//   0x92d8: aa0f022f  orr        x15, x17, x15
//   0x92dc: f27a001f  tst        x0, #0x40
//   0x92e0: b27401f1  orr        x17, x15, #0x1000
//   0x92e4: 926c0022  and        x2, x1, #0x100000
//   0x92e8: 926b0021  and        x1, x1, #0x200000
//   0x92ec: 9a9101ef  csel       x15, x15, x17, eq
//   0x92f0: aa020021  orr        x1, x1, x2
//   0x92f4: f263001f  tst        x0, #0x20000000
//   0x92f8: aa0f002f  orr        x15, x1, x15
//   0x92fc: d36ba802  lsl        x2, x0, #0x15
//   0x9300: b25201e1  orr        x1, x15, #0x400000000000
//   0x9304: 924f0042  and        x2, x2, #0x2000000000000
//   0x9308: 9a8101ef  csel       x15, x15, x1, eq
//   0x930c: f26e013f  tst        x9, #0x40000
//   0x9310: aa0f004f  orr        x15, x2, x15
//   0x9314: d35d7127  lsl        x7, x9, #0x23
//   0x9318: b25505e2  orr        x2, x15, #0x180000000000
//   0x931c: 925b00e5  and        x5, x7, #0x2000000000
//   0x9320: 9a8201ef  csel       x15, x15, x2, eq
//   0x9324: f26a0122  ands       x2, x9, #0x400000
//   0x9328: b25509e3  orr        x3, x15, #0x380000000000
//   0x932c: d2c00c06  mov        x6, #0x6000000000
//   0x9330: 9a8301ef  csel       x15, x15, x3, eq
//   0x9334: f27d013f  tst        x9, #8
//   0x9338: 9a8600a5  csel       x5, x5, x6, eq
//   0x933c: 925900e6  and        x6, x7, #0x8000000000
//   0x9340: aa0500c5  orr        x5, x6, x5
//   0x9344: 52804a13  mov        w19, #0x250
//   0x9348: aa0f00af  orr        x15, x5, x15
//   0x934c: d344fd24  lsr        x4, x9, #4
//   0x9350: 72a48013  movk       w19, #0x2400, lsl #16
//   0x9354: f27b0125  ands       x5, x9, #0x20
//   0x9358: b25801e6  orr        x6, x15, #0x10000000000
//   0x935c: 53134937  lsl        w23, w9, #0xd
//   0x9360: 8a130016  and        x22, x0, x19
//   0x9364: 9a8601f3  csel       x19, x15, x6, eq
//   0x9368: 925700e7  and        x7, x7, #0x20000000000
//   0x936c: 9240012f  and        x15, x9, #1
//   0x9370: 926602f7  and        x23, x23, #0x4000000
//   0x9374: 92640084  and        x4, x4, #0x10000000
//   0x9378: aa1300e7  orr        x7, x7, x19
//   0x937c: d341fc13  lsr        x19, x0, #1
//   0x9380: aa170084  orr        x4, x4, x23
//   0x9384: d341fd37  lsr        x23, x9, #1
//   0x9388: aa0f4ce7  orr        x7, x7, x15, lsl #19
//   0x938c: 92790273  and        x19, x19, #0x80
//   0x9390: 926002f7  and        x23, x23, #0x100000000
//   0x9394: aa050054  orr        x20, x2, x5
//   0x9398: aa070275  orr        x21, x19, x7
//   0x939c: f2700127  ands       x7, x9, #0x10000
//   0x93a0: aa0402e4  orr        x4, x23, x4
//   0x93a4: 53165537  lsl        w23, w9, #0xa
//   0x93a8: b24002b3  orr        x19, x21, #1
//   0x93ac: aa070298  orr        x24, x20, x7
//   0x93b0: 926702f4  and        x20, x23, #0x2000000
//   0x93b4: 9a9302b5  csel       x21, x21, x19, eq
//   0x93b8: aa040284  orr        x4, x20, x4
//   0x93bc: f2780134  ands       x20, x9, #0x100
//   0x93c0: aa150084  orr        x4, x4, x21
//   0x93c4: aa140317  orr        x23, x24, x20
//   0x93c8: b2680095  orr        x21, x4, #0x1000000
//   0x93cc: aa1702d6  orr        x22, x22, x23
//   0x93d0: 9a950084  csel       x4, x4, x21, eq
//   0x93d4: b5000076  cbnz       x22, #0x93e0
//   0x93d8: f143019f  cmp        x12, #0xc0, lsl #12
//   0x93dc: 54000281  b.ne       #0x942c
//   0x93e0: f143019f  cmp        x12, #0xc0, lsl #12
//   0x93e4: 9a8b01ab  csel       x11, x13, x11, eq
//   0x93e8: f277001f  tst        x0, #0x200
//   0x93ec: 9a8e016b  csel       x11, x11, x14, eq
//   0x93f0: f266001f  tst        x0, #0x4000000
//   0x93f4: 9a90016b  csel       x11, x11, x16, eq
//   0x93f8: f27a001f  tst        x0, #0x40
//   0x93fc: 9a91016b  csel       x11, x11, x17, eq
//   0x9400: f263001f  tst        x0, #0x20000000
//   0x9404: 9a81016b  csel       x11, x11, x1, eq
//   0x9408: f100005f  cmp        x2, #0
//   0x940c: 9a83016b  csel       x11, x11, x3, eq
//   0x9410: f10000bf  cmp        x5, #0
//   0x9414: 9a86016b  csel       x11, x11, x6, eq
//   0x9418: f10000ff  cmp        x7, #0
//   0x941c: 9a93016b  csel       x11, x11, x19, eq
//   0x9420: f100029f  cmp        x20, #0
//   0x9424: 9a95016b  csel       x11, x11, x21, eq
//   0x9428: f900750b  str        x11, [x8, #0xe8]
//   0x942c: d3689d2b  lsl        x11, x9, #0x18
//   0x9430: 925f016c  and        x12, x11, #0x200000000
//   0x9434: 925e016d  and        x13, x11, #0x400000000
//   0x9438: aa0c01ac  orr        x12, x13, x12
//   0x943c: d35f792d  lsl        x13, x9, #0x21
//   0x9440: 925d016b  and        x11, x11, #0x800000000
//   0x9444: 924e01ad  and        x13, x13, #0x4000000000000
//   0x9448: aa0c016b  orr        x11, x11, x12
//   0x944c: 53185d2c  lsl        w12, w9, #8
//   0x9450: aa0b01ab  orr        x11, x13, x11
//   0x9454: 9263018c  and        x12, x12, #0x20000000
//   0x9458: aa0b018b  orr        x11, x12, x11
//   0x945c: d369a12c  lsl        x12, x9, #0x17
//   0x9460: 924a018c  and        x12, x12, #0x40000000000000
//   0x9464: d36db12d  lsl        x13, x9, #0x13
//   0x9468: aa0b018b  orr        x11, x12, x11
//   0x946c: 925601ac  and        x12, x13, #0x40000000000
//   0x9470: aa0b018b  orr        x11, x12, x11
//   0x9474: d3607d2c  lsl        x12, x9, #0x20
//   0x9478: 9248018c  and        x12, x12, #0x100000000000000
//   0x947c: d362852d  lsl        x13, x9, #0x1e
//   0x9480: aa0b018b  orr        x11, x12, x11
//   0x9484: 924901ac  and        x12, x13, #0x80000000000000
//   0x9488: aa0b018b  orr        x11, x12, x11
//   0x948c: aa04016b  orr        x11, x11, x4
//   0x9490: 375803e0  tbnz       w0, #0xb, #0x950c
//   0x9494: 5280402d  mov        w13, #0x201
//   0x9498: b278056c  orr        x12, x11, #0x300
//   0x949c: ea0d001f  tst        x0, x13
//   0x94a0: 9270000d  and        x13, x0, #0x10000
//   0x94a4: 9a8c016b  csel       x11, x11, x12, eq
//   0x94a8: aa0d01ec  orr        x12, x15, x13
//   0x94ac: b26e016d  orr        x13, x11, #0x40000
//   0x94b0: f100019f  cmp        x12, #0
//   0x94b4: 9a8d016b  csel       x11, x11, x13, eq
//   0x94b8: 5290000c  mov        w12, #0x8000
//   0x94bc: 72a0800c  movk       w12, #0x400, lsl #16
//   0x94c0: ea0c001f  tst        x0, x12
//   0x94c4: 54000060  b.eq       #0x94d0
//   0x94c8: b26a016b  orr        x11, x11, #0x400000
//   0x94cc: f900750b  str        x11, [x8, #0xe8]
//   0x94d0: d288000c  mov        x12, #0x4000
//   0x94d4: b265016d  orr        x13, x11, #0x8000000
//   0x94d8: f2c0002c  movk       x12, #1, lsl #32
//   0x94dc: 9273014a  and        x10, x10, #0x2000
//   0x94e0: ea0c013f  tst        x9, x12
//   0x94e4: 530d312c  lsl        w12, w9, #0x13
//   0x94e8: 9a8d016b  csel       x11, x11, x13, eq
//   0x94ec: f27f013f  tst        x9, #2
//   0x94f0: 926a0009  and        x9, x0, #0x400000
//   0x94f4: 9261018c  and        x12, x12, #0x80000000
//   0x94f8: fa401924  ccmp       x9, #0, #4, ne
//   0x94fc: aa0b0189  orr        x9, x12, x11
//   0x9500: b25c012b  orr        x11, x9, #0x1000000000
//   0x9504: 9a8b0129  csel       x9, x9, x11, eq
//   0x9508: 1400003d  b          #0x95fc
//   0x950c: d5380429  mrs        x9, id_aa64pfr1_el1
//   0x9510: f2780d3f  tst        x9, #0xf00
//   0x9514: 54000060  b.eq       #0x9520
//   0x9518: b255016b  orr        x11, x11, #0x80000000000
//   0x951c: f900750b  str        x11, [x8, #0xe8]
//   0x9520: 927c0d2a  and        x10, x9, #0xf0
//   0x9524: b250016c  orr        x12, x11, #0x1000000000000
//   0x9528: f100415f  cmp        x10, #0x10
//   0x952c: 92680d29  and        x9, x9, #0xf000000
//   0x9530: 9a8b018a  csel       x10, x12, x11, eq
//   0x9534: 52a0400b  mov        w11, #0x2000000
//   0x9538: b247014c  orr        x12, x10, #0x200000000000000
//   0x953c: eb0b013f  cmp        x9, x11
//   0x9540: d538040b  mrs        x11, id_aa64pfr0_el1
//   0x9544: 9a8a0189  csel       x9, x12, x10, eq
//   0x9548: 2a2b03ea  mvn        w10, w11
//   0x954c: b278052c  orr        x12, x9, #0x300
//   0x9550: f2700d5f  tst        x10, #0xf0000
//   0x9554: 9a8c0129  csel       x9, x9, x12, eq
//   0x9558: f2600d7f  tst        x11, #0xf00000000
//   0x955c: 54000180  b.eq       #0x958c
//   0x9560: d538048a  mrs        x10, id_aa64zfr0_el1
//   0x9564: 92400d4b  and        x11, x10, #0xf
//   0x9568: f100057f  cmp        x11, #1
//   0x956c: 54000080  b.eq       #0x957c
//   0x9570: b500008b  cbnz       x11, #0x9580
//   0x9574: b2620129  orr        x9, x9, #0x40000000
//   0x9578: 14000002  b          #0x9580
//   0x957c: b25c0129  orr        x9, x9, #0x1000000000
//   0x9580: b261012b  orr        x11, x9, #0x80000000
//   0x9584: f26c0d5f  tst        x10, #0xf00000
//   0x9588: 9a8b0129  csel       x9, x9, x11, eq
//   0x958c: d538060a  mrs        x10, id_aa64isar0_el1
//   0x9590: b273012b  orr        x11, x9, #0x2000
//   0x9594: f2600d5f  tst        x10, #0xf00000000
//   0x9598: 9a8b012a  csel       x10, x9, x11, eq
//   0x959c: d5380629  mrs        x9, id_aa64isar1_el1
//   0x95a0: b26e014b  orr        x11, x10, #0x40000
//   0x95a4: f2400d3f  tst        x9, #0xf
//   0x95a8: 9a8b014a  csel       x10, x10, x11, eq
//   0x95ac: f26c0d3f  tst        x9, #0xf00000
//   0x95b0: 54000060  b.eq       #0x95bc
//   0x95b4: b26a014a  orr        x10, x10, #0x400000
//   0x95b8: f900750a  str        x10, [x8, #0xe8]
//   0x95bc: 92580d2b  and        x11, x9, #0xf0000000000
//   0x95c0: d2c0400c  mov        x12, #0x20000000000
//   0x95c4: b251014d  orr        x13, x10, #0x800000000000
//   0x95c8: eb0c017f  cmp        x11, x12
//   0x95cc: 9a8a01aa  csel       x10, x13, x10, eq
//   0x95d0: f2540d3f  tst        x9, #0xf00000000000
//   0x95d4: b265014c  orr        x12, x10, #0x8000000
//   0x95d8: d37cfd2b  lsr        x11, x9, #0x3c
//   0x95dc: 9a8c014a  csel       x10, x10, x12, eq
//   0x95e0: b400010b  cbz        x11, #0x9600
//   0x95e4: d37dfd29  lsr        x9, x9, #0x3d
//   0x95e8: b4000189  cbz        x9, #0x9618
//   0x95ec: f100097f  cmp        x11, #2
//   0x95f0: d2e00309  mov        x9, #0x18000000000000
//   0x95f4: d2e0070b  mov        x11, #0x38000000000000
//   0x95f8: 9a898169  csel       x9, x11, x9, hi
//   0x95fc: aa09014a  orr        x10, x10, x9
//   0x9600: b2460149  orr        x9, x10, #0x400000000000000
//   0x9604: f9007509  str        x9, [x8, #0xe8]
//   0x9608: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x960c: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x9610: a8c35ff8  ldp        x24, x23, [sp], #0x30
//   0x9614: d65f03c0  ret        
//   0x9618: b24d014a  orr        x10, x10, #0x8000000000000
//   0x961c: b2460149  orr        x9, x10, #0x400000000000000
//   0x9620: f9007509  str        x9, [x8, #0xe8]
//   0x9624: a9424ff4  ldp        x20, x19, [sp, #0x20]
//   0x9628: a94157f6  ldp        x22, x21, [sp, #0x10]
//   0x962c: a8c35ff8  ldp        x24, x23, [sp], #0x30
//   0x9630: d65f03c0  ret        

// ----------------------------------------------------------------------------
// FDE[80] HeapTrackerFde_9634 (0x9634..0x96cc, 152 bytes, 38 instructions)
// Summary / Tóm tắt: HeapTracker subroutine @ 0x9634..0x96cc
// ----------------------------------------------------------------------------
//   0x9634: d503233f  paciasp    
//   0x9638: d10243ff  sub        sp, sp, #0x90
//   0x963c: a9084ffe  stp        x30, x19, [sp, #0x80]
//   0x9640: b0000048  adrp       x8, #0x12000
//   0x9644: f9407508  ldr        x8, [x8, #0xe8]
//   0x9648: b40000a8  cbz        x8, #0x965c
//   0x964c: a9484ffe  ldp        x30, x19, [sp, #0x80]
//   0x9650: 910243ff  add        sp, sp, #0x90
//   0x9654: d50323bf  autiasp    
//   0x9658: d65f03c0  ret        
//   0x965c: d503201f  nop        
//   0x9660: 50fc26c0  adr        x0, #0x1b3a
//   0x9664: 910093e1  add        x1, sp, #0x24
//   0x9668: 9400012a  bl         #0x9b10
//   0x966c: 7100041f  cmp        w0, #1
//   0x9670: 540000eb  b.lt       #0x968c
//   0x9674: b0ffffc1  adrp       x1, #0x2000
//   0x9678: 910eec21  add        x1, x1, #0x3bb
//   0x967c: 910093e0  add        x0, sp, #0x24
//   0x9680: 52800142  mov        w2, #0xa
//   0x9684: 9400011f  bl         #0x9b00
//   0x9688: 34fffe20  cbz        w0, #0x964c
//   0x968c: 52800200  mov        w0, #0x10
//   0x9690: 94000124  bl         #0x9b20
//   0x9694: aa0003f3  mov        x19, x0
//   0x9698: 52800340  mov        w0, #0x1a
//   0x969c: 94000121  bl         #0x9b20
//   0x96a0: b2420268  orr        x8, x19, #0x4000000000000000
//   0x96a4: 52800309  mov        w9, #0x18
//   0x96a8: f9000fe0  str        x0, [sp, #0x18]
//   0x96ac: 910023e1  add        x1, sp, #8
//   0x96b0: aa0803e0  mov        x0, x8
//   0x96b4: a900cfe9  stp        x9, x19, [sp, #8]
//   0x96b8: 97fffed1  bl         #0x91fc
//   0x96bc: a9484ffe  ldp        x30, x19, [sp, #0x80]
//   0x96c0: 910243ff  add        sp, sp, #0x90
//   0x96c4: d50323bf  autiasp    
//   0x96c8: d65f03c0  ret        

} // namespace nextai::opencut::npth_heap_tracker
