// ============================================================================
// Clean-Room C++17 Exported API & JNI_OnLoad Bridge for libsscronet.so
// Cầu nối JNI_OnLoad & 1,225 biểu tượng xuất C-API cho libsscronet.so
// ============================================================================
#include "sscronet_core.h"

namespace {
std::atomic<bool> g_sscronet_jni_init_guard{false}; // .bss 0x5df620 (ldarb @ 0x1c74cc)
int32_t g_sscronet_jni_version{0x00010004};         // .data 0x5b9918 (ldr w0, [x20, #0x918] @ 0x1c74d4)
void* g_sscronet_java_vm{nullptr};                  // .bss 0x5df790 (str x19, [x8, #0x790] @ 0x1c7540)
} // namespace

extern "C" {

// Reconstructed from 0x1c74a8..0x1c78bc (JNI_OnLoad, 1,044 bytes)
//   0x1c74a8: D503233F  paciasp
//   0x1c74ac: D101C3FF  sub   sp, sp, #0x70
//   0x1c74cc: 08DFFD08  ldarb w8, [x8] (.bss 0x5df620 static guard)
//   0x1c74d0: 36000108  tbz   w8, #0, #0x1c74f0
//   0x1c74d4: B9491A80  ldr   w0, [x20, #0x918] (.data 0x5b9918)
//   0x1c74fc: 940EFE59  bl    #0x586e60 (__cxa_guard_acquire)
//   0x1c7540: F903C913  str   x19, [x8, #0x790] (.bss 0x5df790 JavaVM*)
int32_t JNI_OnLoad(void* vm, void* reserved) {
    (void)reserved;
    if (g_sscronet_jni_init_guard.load(std::memory_order_acquire)) {
        return g_sscronet_jni_version;
    }
    g_sscronet_java_vm = vm;
    g_sscronet_jni_init_guard.store(true, std::memory_order_release);
    return g_sscronet_jni_version;
}

} // extern "C"

namespace sscronet {

// Export #000: JNI_OnLoad @ 0x1c74a8 (1044 bytes)
//   0x1c74a8: D503233F  paciasp  
//   0x1c74ac: D101C3FF  sub      sp, sp, #0x70
//   0x1c74b0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1c74b4: F9002BF5  str      x21, [sp, #0x50]
//   0x1c74b8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1c74bc: 910103FD  add      x29, sp, #0x40
uint64_t exported_api_000_JNI_OnLoad(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD101C3FFULL) + 0x1C74A8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #001: Cronet_DateTime_Destroy @ 0x1c9738 (8 bytes)
//   0x1c9738: D503245F  bti      c
//   0x1c973c: 14044B9E  b        #0x2dc5b4
//   0x1c9740: D503233F  paciasp  
//   0x1c9744: D101C3FF  sub      sp, sp, #0x70
uint64_t exported_api_001_Cronet_DateTime_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x14044B9EULL) + 0x1C9738ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #002: Cronet_AuthDelegate_Destroy @ 0x1ea6f4 (16 bytes)
//   0x1ea6f4: D503245F  bti      c
//   0x1ea6f8: B4000040  cbz      x0, #0x1ea700
//   0x1ea6fc: 1403C7AE  b        #0x2dc5b4
//   0x1ea700: D65F03C0  ret      
uint64_t exported_api_002_Cronet_AuthDelegate_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000040ULL) + 0x1EA6F4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #003: Cronet_AuthDelegate_SetClientContext @ 0x1fac70 (12 bytes)
//   0x1fac70: D503245F  bti      c
//   0x1fac74: F9000401  str      x1, [x0, #8]
//   0x1fac78: D65F03C0  ret      
//   0x1fac7c: D503233F  paciasp  
uint64_t exported_api_003_Cronet_AuthDelegate_SetClientContext(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9000401ULL) + 0x1FAC70ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #004: Cronet_ServiceInfo_service_delegate_get @ 0x206f6c (12 bytes)
//   0x206f6c: D503245F  bti      c
//   0x206f70: F9400800  ldr      x0, [x0, #0x10]
//   0x206f74: D65F03C0  ret      
//   0x206f78: D503245F  bti      c
uint64_t exported_api_004_Cronet_ServiceInfo_service_delegate_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400800ULL) + 0x206F6CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #005: Cronet_Metrics_request_start_get @ 0x20cf04 (24 bytes)
//   0x20cf04: D503245F  bti      c
//   0x20cf08: 39400008  ldrb     w8, [x0]
//   0x20cf0c: 34000048  cbz      w8, #0x20cf14
//   0x20cf10: 17FF4393  b        #0x1ddd5c
//   0x20cf14: AA1F03E0  mov      x0, xzr
//   0x20cf18: D65F03C0  ret      
uint64_t exported_api_005_Cronet_Metrics_request_start_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39400008ULL) + 0x20CF04ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #006: Cronet_FrontierMessage_service_get @ 0x214858 (12 bytes)
//   0x214858: D503245F  bti      c
//   0x21485c: B9401000  ldr      w0, [x0, #0x10]
//   0x214860: D65F03C0  ret      
//   0x214864: D503233F  paciasp  
uint64_t exported_api_006_Cronet_FrontierMessage_service_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9401000ULL) + 0x214858ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #007: Cronet_BiStreamClient_CreateStream @ 0x214988 (16 bytes)
//   0x214988: D503245F  bti      c
//   0x21498c: F9400008  ldr      x8, [x0]
//   0x214990: F9400D10  ldr      x16, [x8, #0x18]
//   0x214994: D61F0200  br       x16
uint64_t exported_api_007_Cronet_BiStreamClient_CreateStream(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x214988ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #008: Cronet_ServiceInfo_priority_get @ 0x2149a4 (12 bytes)
//   0x2149a4: D503245F  bti      c
//   0x2149a8: B9400800  ldr      w0, [x0, #8]
//   0x2149ac: D65F03C0  ret      
//   0x2149b0: D503233F  paciasp  
uint64_t exported_api_008_Cronet_ServiceInfo_priority_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9400800ULL) + 0x2149A4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #009: Cronet_BiStreamDelegate_OnError @ 0x219184 (12 bytes)
//   0x219184: D503245F  bti      c
//   0x219188: F9401010  ldr      x16, [x0, #0x20]
//   0x21918c: D61F0200  br       x16
//   0x219190: D503245F  bti      c
uint64_t exported_api_009_Cronet_BiStreamDelegate_OnError(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401010ULL) + 0x219184ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #010: Cronet_TTDispatchResult_state_get @ 0x224d68 (12 bytes)
//   0x224d68: D503245F  bti      c
//   0x224d6c: B9406000  ldr      w0, [x0, #0x60]
//   0x224d70: D65F03C0  ret      
//   0x224d74: D503233F  paciasp  
uint64_t exported_api_010_Cronet_TTDispatchResult_state_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9406000ULL) + 0x224D68ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #011: Cronet_UrlRequestParams_connect_timeout_set @ 0x224f94 (12 bytes)
//   0x224f94: D503245F  bti      c
//   0x224f98: B9008001  str      w1, [x0, #0x80]
//   0x224f9c: D65F03C0  ret      
//   0x224fa0: D503233F  paciasp  
uint64_t exported_api_011_Cronet_UrlRequestParams_connect_timeout_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9008001ULL) + 0x224F94ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #012: Cronet_FrontierConfig_port_get @ 0x22ec68 (12 bytes)
//   0x22ec68: D503245F  bti      c
//   0x22ec6c: 79404000  ldrh     w0, [x0, #0x20]
//   0x22ec70: D65F03C0  ret      
//   0x22ec74: D503233F  paciasp  
uint64_t exported_api_012_Cronet_FrontierConfig_port_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x79404000ULL) + 0x22EC68ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #013: Cronet_Buffer_Create @ 0x237418 (52 bytes)
//   0x237418: D503233F  paciasp  
//   0x23741c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x237420: 910003FD  mov      x29, sp
//   0x237424: 52800500  mov      w0, #0x28
//   0x237428: 94029453  bl       #0x2dc574
//   0x23742c: F0001AE8  adrp     x8, #0x596000
uint64_t exported_api_013_Cronet_Buffer_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x237418ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #014: Cronet_ServiceInfo_auth_delegate_get @ 0x23753c (12 bytes)
//   0x23753c: D503245F  bti      c
//   0x237540: F9400C00  ldr      x0, [x0, #0x18]
//   0x237544: D65F03C0  ret      
//   0x237548: D503233F  paciasp  
uint64_t exported_api_014_Cronet_ServiceInfo_auth_delegate_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C00ULL) + 0x23753CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #015: Cronet_Engine_Create @ 0x2401fc (448 bytes)
//   0x2401fc: D503233F  paciasp  
//   0x240200: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x240204: F9000BF5  str      x21, [sp, #0x10]
//   0x240208: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24020c: 910003FD  mov      x29, sp
//   0x240210: 5280AA00  mov      w0, #0x550
uint64_t exported_api_015_Cronet_Engine_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BD7BFDULL) + 0x2401FCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #016: Cronet_Engine_SetMockCertVerifierForTesting @ 0x2403bc (52 bytes)
//   0x2403bc: D503245F  bti      c
//   0x2403c0: F9412009  ldr      x9, [x0, #0x240]
//   0x2403c4: B5000129  cbnz     x9, #0x2403e8
//   0x2403c8: AA0003E8  mov      x8, x0
//   0x2403cc: F9429800  ldr      x0, [x0, #0x530]
//   0x2403d0: F9029901  str      x1, [x8, #0x530]
uint64_t exported_api_016_Cronet_Engine_SetMockCertVerifierForTesting(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9412009ULL) + 0x2403BCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #017: Cronet_Engine_GetStreamEngine @ 0x2403f0 (48 bytes)
//   0x2403f0: D503233F  paciasp  
//   0x2403f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2403f8: F9000BF3  str      x19, [sp, #0x10]
//   0x2403fc: 910003FD  mov      x29, sp
//   0x240400: AA0003F3  mov      x19, x0
//   0x240404: 9113A000  add      x0, x0, #0x4e8
uint64_t exported_api_017_Cronet_Engine_GetStreamEngine(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2403F0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #018: Cronet_UrlRequest_Create @ 0x245454 (188 bytes)
//   0x245454: D503233F  paciasp  
//   0x245458: D10103FF  sub      sp, sp, #0x40
//   0x24545c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x245460: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x245464: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x245468: 910043FD  add      x29, sp, #0x10
uint64_t exported_api_018_Cronet_UrlRequest_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10103FFULL) + 0x245454ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #019: Cronet_BufferCallback_Destroy @ 0x245510 (24 bytes)
//   0x245510: D503245F  bti      c
//   0x245514: B4000080  cbz      x0, #0x245524
//   0x245518: F9400008  ldr      x8, [x0]
//   0x24551c: F9400510  ldr      x16, [x8, #8]
//   0x245520: D61F0200  br       x16
//   0x245524: D65F03C0  ret      
uint64_t exported_api_019_Cronet_BufferCallback_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000080ULL) + 0x245510ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #020: Cronet_AuthDelegate_GetClientContext @ 0x245528 (12 bytes)
//   0x245528: D503245F  bti      c
//   0x24552c: F9400400  ldr      x0, [x0, #8]
//   0x245530: D65F03C0  ret      
//   0x245534: D503245F  bti      c
uint64_t exported_api_020_Cronet_AuthDelegate_GetClientContext(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400400ULL) + 0x245528ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #021: Cronet_BiStreamClient_CreateConnection @ 0x245534 (16 bytes)
//   0x245534: D503245F  bti      c
//   0x245538: F9400008  ldr      x8, [x0]
//   0x24553c: F9400910  ldr      x16, [x8, #0x10]
//   0x245540: D61F0200  br       x16
uint64_t exported_api_021_Cronet_BiStreamClient_CreateConnection(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245534ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #022: Cronet_BiStreamClient_IsConnectionReady @ 0x245544 (16 bytes)
//   0x245544: D503245F  bti      c
//   0x245548: F9400008  ldr      x8, [x0]
//   0x24554c: F9401110  ldr      x16, [x8, #0x20]
//   0x245550: D61F0200  br       x16
uint64_t exported_api_022_Cronet_BiStreamClient_IsConnectionReady(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245544ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #023: Cronet_BiStreamClient_IsStreamReady @ 0x245554 (16 bytes)
//   0x245554: D503245F  bti      c
//   0x245558: F9400008  ldr      x8, [x0]
//   0x24555c: F9401510  ldr      x16, [x8, #0x28]
//   0x245560: D61F0200  br       x16
uint64_t exported_api_023_Cronet_BiStreamClient_IsStreamReady(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245554ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #024: Cronet_Buffer_CreateWith @ 0x245564 (84 bytes)
//   0x245564: D503233F  paciasp  
//   0x245568: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x24556c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x245570: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x245574: 910003FD  mov      x29, sp
//   0x245578: AA0003F6  mov      x22, x0
uint64_t exported_api_024_Cronet_Buffer_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BD7BFDULL) + 0x245564ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #025: Cronet_AuthDelegate_OnFetchAuthInfo @ 0x2455b8 (12 bytes)
//   0x2455b8: D503245F  bti      c
//   0x2455bc: F9400810  ldr      x16, [x0, #0x10]
//   0x2455c0: D61F0200  br       x16
//   0x2455c4: D503245F  bti      c
uint64_t exported_api_025_Cronet_AuthDelegate_OnFetchAuthInfo(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400810ULL) + 0x2455B8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #026: Cronet_BiStreamDelegate_OnStreamReady @ 0x2455c4 (12 bytes)
//   0x2455c4: D503245F  bti      c
//   0x2455c8: F9400C10  ldr      x16, [x0, #0x18]
//   0x2455cc: D61F0200  br       x16
//   0x2455d0: D503245F  bti      c
uint64_t exported_api_026_Cronet_BiStreamDelegate_OnStreamReady(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C10ULL) + 0x2455C4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #027: Cronet_BiStreamDelegate_OnReceivedData @ 0x2455d0 (12 bytes)
//   0x2455d0: D503245F  bti      c
//   0x2455d4: F9401410  ldr      x16, [x0, #0x28]
//   0x2455d8: D61F0200  br       x16
//   0x2455dc: D503233F  paciasp  
uint64_t exported_api_027_Cronet_BiStreamDelegate_OnReceivedData(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401410ULL) + 0x2455D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #028: Cronet_BufferCallback_CreateWith @ 0x2455dc (60 bytes)
//   0x2455dc: D503233F  paciasp  
//   0x2455e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2455e4: F9000BF3  str      x19, [sp, #0x10]
//   0x2455e8: 910003FD  mov      x29, sp
//   0x2455ec: AA0003F3  mov      x19, x0
//   0x2455f0: 52800300  mov      w0, #0x18
uint64_t exported_api_028_Cronet_BufferCallback_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2455DCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #029: Cronet_Runnable_CreateWith @ 0x245618 (60 bytes)
//   0x245618: D503233F  paciasp  
//   0x24561c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x245620: F9000BF3  str      x19, [sp, #0x10]
//   0x245624: 910003FD  mov      x29, sp
//   0x245628: AA0003F3  mov      x19, x0
//   0x24562c: 52800300  mov      w0, #0x18
uint64_t exported_api_029_Cronet_Runnable_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245618ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #030: Cronet_Executor_CreateWith @ 0x245654 (60 bytes)
//   0x245654: D503233F  paciasp  
//   0x245658: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24565c: F9000BF3  str      x19, [sp, #0x10]
//   0x245660: 910003FD  mov      x29, sp
//   0x245664: AA0003F3  mov      x19, x0
//   0x245668: 52800300  mov      w0, #0x18
uint64_t exported_api_030_Cronet_Executor_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245654ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #031: Cronet_BiStreamClient_SendData @ 0x245690 (16 bytes)
//   0x245690: D503245F  bti      c
//   0x245694: F9400008  ldr      x8, [x0]
//   0x245698: F9401910  ldr      x16, [x8, #0x30]
//   0x24569c: D61F0200  br       x16
uint64_t exported_api_031_Cronet_BiStreamClient_SendData(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245690ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #032: Cronet_BiStreamClient_CloseStream @ 0x2456a0 (16 bytes)
//   0x2456a0: D503245F  bti      c
//   0x2456a4: F9400008  ldr      x8, [x0]
//   0x2456a8: F9401D10  ldr      x16, [x8, #0x38]
//   0x2456ac: D61F0200  br       x16
uint64_t exported_api_032_Cronet_BiStreamClient_CloseStream(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456A0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #033: Cronet_BiStreamClient_CloseConnection @ 0x2456b0 (16 bytes)
//   0x2456b0: D503245F  bti      c
//   0x2456b4: F9400008  ldr      x8, [x0]
//   0x2456b8: F9402110  ldr      x16, [x8, #0x40]
//   0x2456bc: D61F0200  br       x16
uint64_t exported_api_033_Cronet_BiStreamClient_CloseConnection(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #034: Cronet_BiStreamClient_Destroy @ 0x2456c0 (16 bytes)
//   0x2456c0: D503245F  bti      c
//   0x2456c4: F9400008  ldr      x8, [x0]
//   0x2456c8: F9402510  ldr      x16, [x8, #0x48]
//   0x2456cc: D61F0200  br       x16
uint64_t exported_api_034_Cronet_BiStreamClient_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456C0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #035: Cronet_BiStreamClient_AddDelegate @ 0x2456d0 (16 bytes)
//   0x2456d0: D503245F  bti      c
//   0x2456d4: F9400008  ldr      x8, [x0]
//   0x2456d8: F9402910  ldr      x16, [x8, #0x50]
//   0x2456dc: D61F0200  br       x16
uint64_t exported_api_035_Cronet_BiStreamClient_AddDelegate(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #036: Cronet_BiStreamClient_RemoveDelegate @ 0x2456e0 (16 bytes)
//   0x2456e0: D503245F  bti      c
//   0x2456e4: F9400008  ldr      x8, [x0]
//   0x2456e8: F9402D10  ldr      x16, [x8, #0x58]
//   0x2456ec: D61F0200  br       x16
uint64_t exported_api_036_Cronet_BiStreamClient_RemoveDelegate(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #037: Cronet_Engine_RemoveNQEListener @ 0x2456f0 (16 bytes)
//   0x2456f0: D503245F  bti      c
//   0x2456f4: F9400008  ldr      x8, [x0]
//   0x2456f8: F9403110  ldr      x16, [x8, #0x60]
//   0x2456fc: D61F0200  br       x16
uint64_t exported_api_037_Cronet_Engine_RemoveNQEListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2456F0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #038: Cronet_Engine_AddMNListener @ 0x245700 (16 bytes)
//   0x245700: D503245F  bti      c
//   0x245704: F9400008  ldr      x8, [x0]
//   0x245708: F9403510  ldr      x16, [x8, #0x68]
//   0x24570c: D61F0200  br       x16
uint64_t exported_api_038_Cronet_Engine_AddMNListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245700ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #039: Cronet_Engine_RemoveMNListener @ 0x245710 (16 bytes)
//   0x245710: D503245F  bti      c
//   0x245714: F9400008  ldr      x8, [x0]
//   0x245718: F9403910  ldr      x16, [x8, #0x70]
//   0x24571c: D61F0200  br       x16
uint64_t exported_api_039_Cronet_Engine_RemoveMNListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245710ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #040: Cronet_Engine_AddStoreRegionListener @ 0x245720 (16 bytes)
//   0x245720: D503245F  bti      c
//   0x245724: F9400008  ldr      x8, [x0]
//   0x245728: F9403D10  ldr      x16, [x8, #0x78]
//   0x24572c: D61F0200  br       x16
uint64_t exported_api_040_Cronet_Engine_AddStoreRegionListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245720ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #041: Cronet_Engine_RemoveStoreRegionListener @ 0x245730 (16 bytes)
//   0x245730: D503245F  bti      c
//   0x245734: F9400008  ldr      x8, [x0]
//   0x245738: F9404110  ldr      x16, [x8, #0x80]
//   0x24573c: D61F0200  br       x16
uint64_t exported_api_041_Cronet_Engine_RemoveStoreRegionListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245730ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #042: Cronet_Engine_AddConnectionTypeListener @ 0x245740 (16 bytes)
//   0x245740: D503245F  bti      c
//   0x245744: F9400008  ldr      x8, [x0]
//   0x245748: F9404510  ldr      x16, [x8, #0x88]
//   0x24574c: D61F0200  br       x16
uint64_t exported_api_042_Cronet_Engine_AddConnectionTypeListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245740ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #043: Cronet_Engine_RemoveConnectionTypeListener @ 0x245750 (16 bytes)
//   0x245750: D503245F  bti      c
//   0x245754: F9400008  ldr      x8, [x0]
//   0x245758: F9404910  ldr      x16, [x8, #0x90]
//   0x24575c: D61F0200  br       x16
uint64_t exported_api_043_Cronet_Engine_RemoveConnectionTypeListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245750ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #044: Cronet_Engine_TriggerGetDomain @ 0x245760 (16 bytes)
//   0x245760: D503245F  bti      c
//   0x245764: F9400008  ldr      x8, [x0]
//   0x245768: F9404D10  ldr      x16, [x8, #0x98]
//   0x24576c: D61F0200  br       x16
uint64_t exported_api_044_Cronet_Engine_TriggerGetDomain(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245760ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #045: Cronet_Engine_StartWiFiCellSwitcher @ 0x245770 (16 bytes)
//   0x245770: D503245F  bti      c
//   0x245774: F9400008  ldr      x8, [x0]
//   0x245778: F9405110  ldr      x16, [x8, #0xa0]
//   0x24577c: D61F0200  br       x16
uint64_t exported_api_045_Cronet_Engine_StartWiFiCellSwitcher(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245770ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #046: Cronet_Engine_StopWiFiCellSwitcher @ 0x245780 (16 bytes)
//   0x245780: D503245F  bti      c
//   0x245784: F9400008  ldr      x8, [x0]
//   0x245788: F9405510  ldr      x16, [x8, #0xa8]
//   0x24578c: D61F0200  br       x16
uint64_t exported_api_046_Cronet_Engine_StopWiFiCellSwitcher(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245780ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #047: Cronet_Engine_TriggerSwitchingToNetwork @ 0x245790 (16 bytes)
//   0x245790: D503245F  bti      c
//   0x245794: F9400008  ldr      x8, [x0]
//   0x245798: F9405910  ldr      x16, [x8, #0xb0]
//   0x24579c: D61F0200  br       x16
uint64_t exported_api_047_Cronet_Engine_TriggerSwitchingToNetwork(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245790ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #048: Cronet_Engine_SetProxyConfig @ 0x2457a0 (16 bytes)
//   0x2457a0: D503245F  bti      c
//   0x2457a4: F9400008  ldr      x8, [x0]
//   0x2457a8: F9405D10  ldr      x16, [x8, #0xb8]
//   0x2457ac: D61F0200  br       x16
uint64_t exported_api_048_Cronet_Engine_SetProxyConfig(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457A0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #049: Cronet_Engine_AddClientOpaqueData @ 0x2457b0 (16 bytes)
//   0x2457b0: D503245F  bti      c
//   0x2457b4: F9400008  ldr      x8, [x0]
//   0x2457b8: F9406110  ldr      x16, [x8, #0xc0]
//   0x2457bc: D61F0200  br       x16
uint64_t exported_api_049_Cronet_Engine_AddClientOpaqueData(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #050: Cronet_Engine_ClearClientOpaqueData @ 0x2457c0 (16 bytes)
//   0x2457c0: D503245F  bti      c
//   0x2457c4: F9400008  ldr      x8, [x0]
//   0x2457c8: F9406510  ldr      x16, [x8, #0xc8]
//   0x2457cc: D61F0200  br       x16
uint64_t exported_api_050_Cronet_Engine_ClearClientOpaqueData(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457C0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #051: Cronet_Engine_RemoveClientOpaqueData @ 0x2457d0 (16 bytes)
//   0x2457d0: D503245F  bti      c
//   0x2457d4: F9400008  ldr      x8, [x0]
//   0x2457d8: F9406910  ldr      x16, [x8, #0xd0]
//   0x2457dc: D61F0200  br       x16
uint64_t exported_api_051_Cronet_Engine_RemoveClientOpaqueData(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #052: Cronet_Engine_AddOpaqueDataStoreDynamic @ 0x2457e0 (16 bytes)
//   0x2457e0: D503245F  bti      c
//   0x2457e4: F9400008  ldr      x8, [x0]
//   0x2457e8: F9406D10  ldr      x16, [x8, #0xd8]
//   0x2457ec: D61F0200  br       x16
uint64_t exported_api_052_Cronet_Engine_AddOpaqueDataStoreDynamic(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #053: Cronet_Engine_SetInitModeWithInject @ 0x2457f0 (16 bytes)
//   0x2457f0: D503245F  bti      c
//   0x2457f4: F9400008  ldr      x8, [x0]
//   0x2457f8: F9407110  ldr      x16, [x8, #0xe0]
//   0x2457fc: D61F0200  br       x16
uint64_t exported_api_053_Cronet_Engine_SetInitModeWithInject(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2457F0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #054: Cronet_Engine_SetInitTimeoutWithInject @ 0x245800 (16 bytes)
//   0x245800: D503245F  bti      c
//   0x245804: F9400008  ldr      x8, [x0]
//   0x245808: F9407510  ldr      x16, [x8, #0xe8]
//   0x24580c: D61F0200  br       x16
uint64_t exported_api_054_Cronet_Engine_SetInitTimeoutWithInject(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245800ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #055: Cronet_Engine_SetLogLevel @ 0x245810 (16 bytes)
//   0x245810: D503245F  bti      c
//   0x245814: F9400008  ldr      x8, [x0]
//   0x245818: F9407910  ldr      x16, [x8, #0xf0]
//   0x24581c: D61F0200  br       x16
uint64_t exported_api_055_Cronet_Engine_SetLogLevel(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245810ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #056: Cronet_Engine_SetOpaque @ 0x245820 (16 bytes)
//   0x245820: D503245F  bti      c
//   0x245824: F9400008  ldr      x8, [x0]
//   0x245828: F9407D10  ldr      x16, [x8, #0xf8]
//   0x24582c: D61F0200  br       x16
uint64_t exported_api_056_Cronet_Engine_SetOpaque(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245820ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #057: Cronet_Engine_SetOecOpaque @ 0x245830 (16 bytes)
//   0x245830: D503245F  bti      c
//   0x245834: F9400008  ldr      x8, [x0]
//   0x245838: F9408110  ldr      x16, [x8, #0x100]
//   0x24583c: D61F0200  br       x16
uint64_t exported_api_057_Cronet_Engine_SetOecOpaque(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245830ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #058: Cronet_Engine_SetOecOpaqueFree @ 0x245840 (16 bytes)
//   0x245840: D503245F  bti      c
//   0x245844: F9400008  ldr      x8, [x0]
//   0x245848: F9408510  ldr      x16, [x8, #0x108]
//   0x24584c: D61F0200  br       x16
uint64_t exported_api_058_Cronet_Engine_SetOecOpaqueFree(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245840ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #059: Cronet_Engine_SetMD5Header @ 0x245850 (16 bytes)
//   0x245850: D503245F  bti      c
//   0x245854: F9400008  ldr      x8, [x0]
//   0x245858: F9408910  ldr      x16, [x8, #0x110]
//   0x24585c: D61F0200  br       x16
uint64_t exported_api_059_Cronet_Engine_SetMD5Header(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245850ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #060: Cronet_Engine_RunInBackGround @ 0x245860 (16 bytes)
//   0x245860: D503245F  bti      c
//   0x245864: F9400008  ldr      x8, [x0]
//   0x245868: F9408D10  ldr      x16, [x8, #0x118]
//   0x24586c: D61F0200  br       x16
uint64_t exported_api_060_Cronet_Engine_RunInBackGround(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245860ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #061: Cronet_Engine_GetRTTAndThroughput @ 0x245870 (16 bytes)
//   0x245870: D503245F  bti      c
//   0x245874: F9400008  ldr      x8, [x0]
//   0x245878: F9409110  ldr      x16, [x8, #0x120]
//   0x24587c: D61F0200  br       x16
uint64_t exported_api_061_Cronet_Engine_GetRTTAndThroughput(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245870ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #062: Cronet_Engine_GetPacketLostStats @ 0x245880 (16 bytes)
//   0x245880: D503245F  bti      c
//   0x245884: F9400008  ldr      x8, [x0]
//   0x245888: F9409510  ldr      x16, [x8, #0x128]
//   0x24588c: D61F0200  br       x16
uint64_t exported_api_062_Cronet_Engine_GetPacketLostStats(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245880ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #063: Cronet_Engine_GetEffectiveConnectionType @ 0x245890 (16 bytes)
//   0x245890: D503245F  bti      c
//   0x245894: F9400008  ldr      x8, [x0]
//   0x245898: F9409910  ldr      x16, [x8, #0x130]
//   0x24589c: D61F0200  br       x16
uint64_t exported_api_063_Cronet_Engine_GetEffectiveConnectionType(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245890ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #064: Cronet_Engine_GetNetworkReport @ 0x2458a0 (16 bytes)
//   0x2458a0: D503245F  bti      c
//   0x2458a4: F9400008  ldr      x8, [x0]
//   0x2458a8: F9409D10  ldr      x16, [x8, #0x138]
//   0x2458ac: D61F0200  br       x16
uint64_t exported_api_064_Cronet_Engine_GetNetworkReport(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458A0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #065: Cronet_Engine_TTDnsResolve @ 0x2458b0 (16 bytes)
//   0x2458b0: D503245F  bti      c
//   0x2458b4: F9400008  ldr      x8, [x0]
//   0x2458b8: F940A110  ldr      x16, [x8, #0x140]
//   0x2458bc: D61F0200  br       x16
uint64_t exported_api_065_Cronet_Engine_TTDnsResolve(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #066: Cronet_Engine_AddRequestInfoDelegate @ 0x2458c0 (16 bytes)
//   0x2458c0: D503245F  bti      c
//   0x2458c4: F9400008  ldr      x8, [x0]
//   0x2458c8: F940A510  ldr      x16, [x8, #0x148]
//   0x2458cc: D61F0200  br       x16
uint64_t exported_api_066_Cronet_Engine_AddRequestInfoDelegate(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458C0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #067: Cronet_Engine_RemoveRequestInfoDelegate @ 0x2458d0 (16 bytes)
//   0x2458d0: D503245F  bti      c
//   0x2458d4: F9400008  ldr      x8, [x0]
//   0x2458d8: F940A910  ldr      x16, [x8, #0x150]
//   0x2458dc: D61F0200  br       x16
uint64_t exported_api_067_Cronet_Engine_RemoveRequestInfoDelegate(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #068: Cronet_Engine_GetPublicIPs @ 0x2458e0 (16 bytes)
//   0x2458e0: D503245F  bti      c
//   0x2458e4: F9400008  ldr      x8, [x0]
//   0x2458e8: F940AD10  ldr      x16, [x8, #0x158]
//   0x2458ec: D61F0200  br       x16
uint64_t exported_api_068_Cronet_Engine_GetPublicIPs(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #069: Cronet_Engine_AddPublicIPsListener @ 0x2458f0 (16 bytes)
//   0x2458f0: D503245F  bti      c
//   0x2458f4: F9400008  ldr      x8, [x0]
//   0x2458f8: F940B110  ldr      x16, [x8, #0x160]
//   0x2458fc: D61F0200  br       x16
uint64_t exported_api_069_Cronet_Engine_AddPublicIPsListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2458F0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #070: Cronet_Engine_RemovePublicIPsListener @ 0x245900 (16 bytes)
//   0x245900: D503245F  bti      c
//   0x245904: F9400008  ldr      x8, [x0]
//   0x245908: F940B510  ldr      x16, [x8, #0x168]
//   0x24590c: D61F0200  br       x16
uint64_t exported_api_070_Cronet_Engine_RemovePublicIPsListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245900ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #071: Cronet_Engine_SetEnableModifyMode @ 0x245910 (16 bytes)
//   0x245910: D503245F  bti      c
//   0x245914: F9400008  ldr      x8, [x0]
//   0x245918: F940B910  ldr      x16, [x8, #0x170]
//   0x24591c: D61F0200  br       x16
uint64_t exported_api_071_Cronet_Engine_SetEnableModifyMode(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245910ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #072: Cronet_Engine_AddLogMonitorListener @ 0x245920 (16 bytes)
//   0x245920: D503245F  bti      c
//   0x245924: F9400008  ldr      x8, [x0]
//   0x245928: F940BD10  ldr      x16, [x8, #0x178]
//   0x24592c: D61F0200  br       x16
uint64_t exported_api_072_Cronet_Engine_AddLogMonitorListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245920ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #073: Cronet_Engine_RemoveLogMonitorListener @ 0x245930 (16 bytes)
//   0x245930: D503245F  bti      c
//   0x245934: F9400008  ldr      x8, [x0]
//   0x245938: F940C110  ldr      x16, [x8, #0x180]
//   0x24593c: D61F0200  br       x16
uint64_t exported_api_073_Cronet_Engine_RemoveLogMonitorListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245930ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #074: Cronet_Engine_UpdateStoreRegionConfigFromResponse @ 0x245940 (16 bytes)
//   0x245940: D503245F  bti      c
//   0x245944: F9400008  ldr      x8, [x0]
//   0x245948: F940C510  ldr      x16, [x8, #0x188]
//   0x24594c: D61F0200  br       x16
uint64_t exported_api_074_Cronet_Engine_UpdateStoreRegionConfigFromRespons(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245940ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #075: Cronet_Engine_TTUrlDispatch @ 0x245950 (16 bytes)
//   0x245950: D503245F  bti      c
//   0x245954: F9400008  ldr      x8, [x0]
//   0x245958: F940C910  ldr      x16, [x8, #0x190]
//   0x24595c: D61F0200  br       x16
uint64_t exported_api_075_Cronet_Engine_TTUrlDispatch(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245950ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #076: Cronet_Engine_AddEventListener @ 0x245960 (16 bytes)
//   0x245960: D503245F  bti      c
//   0x245964: F9400008  ldr      x8, [x0]
//   0x245968: F940CD10  ldr      x16, [x8, #0x198]
//   0x24596c: D61F0200  br       x16
uint64_t exported_api_076_Cronet_Engine_AddEventListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245960ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #077: Cronet_Engine_RemoveEventListener @ 0x245970 (16 bytes)
//   0x245970: D503245F  bti      c
//   0x245974: F9400008  ldr      x8, [x0]
//   0x245978: F940D110  ldr      x16, [x8, #0x1a0]
//   0x24597c: D61F0200  br       x16
uint64_t exported_api_077_Cronet_Engine_RemoveEventListener(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x245970ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #078: Cronet_Engine_CreateWith @ 0x245980 (424 bytes)
//   0x245980: D503233F  paciasp  
//   0x245984: D106C3FF  sub      sp, sp, #0x1b0
//   0x245988: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x24598c: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x245990: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x245994: A9185FF8  stp      x24, x23, [sp, #0x180]
uint64_t exported_api_078_Cronet_Engine_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD106C3FFULL) + 0x245980ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #079: Cronet_BiStreamDelegate_OnFeedbackLog @ 0x245b28 (12 bytes)
//   0x245b28: D503245F  bti      c
//   0x245b2c: F9401810  ldr      x16, [x0, #0x30]
//   0x245b30: D61F0200  br       x16
//   0x245b34: D503245F  bti      c
uint64_t exported_api_079_Cronet_BiStreamDelegate_OnFeedbackLog(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401810ULL) + 0x245B28ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #080: Cronet_FrontierDelegate_OnReceivedAckWithMeta @ 0x245b34 (12 bytes)
//   0x245b34: D503245F  bti      c
//   0x245b38: F9401C10  ldr      x16, [x0, #0x38]
//   0x245b3c: D61F0200  br       x16
//   0x245b40: D503245F  bti      c
uint64_t exported_api_080_Cronet_FrontierDelegate_OnReceivedAckWithMeta(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401C10ULL) + 0x245B34ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #081: TTQuicHe_HttpRequestCallback_OnCanceled @ 0x245b40 (12 bytes)
//   0x245b40: D503245F  bti      c
//   0x245b44: F9402010  ldr      x16, [x0, #0x40]
//   0x245b48: D61F0200  br       x16
//   0x245b4c: D503245F  bti      c
uint64_t exported_api_081_TTQuicHe_HttpRequestCallback_OnCanceled(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9402010ULL) + 0x245B40ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #082: Cronet_UrlRequestStatusListener_CreateWith @ 0x245d5c (60 bytes)
//   0x245d5c: D503233F  paciasp  
//   0x245d60: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x245d64: F9000BF3  str      x19, [sp, #0x10]
//   0x245d68: 910003FD  mov      x29, sp
//   0x245d6c: AA0003F3  mov      x19, x0
//   0x245d70: 52800300  mov      w0, #0x18
uint64_t exported_api_082_Cronet_UrlRequestStatusListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245D5CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #083: Cronet_UrlRequestCallback_CreateWith @ 0x245d98 (104 bytes)
//   0x245d98: D503233F  paciasp  
//   0x245d9c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x245da0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x245da4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x245da8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x245dac: 910003FD  mov      x29, sp
uint64_t exported_api_083_Cronet_UrlRequestCallback_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BC7BFDULL) + 0x245D98ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #084: Cronet_UploadDataSink_CreateWith @ 0x245e00 (84 bytes)
//   0x245e00: D503233F  paciasp  
//   0x245e04: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x245e08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x245e0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x245e10: 910003FD  mov      x29, sp
//   0x245e14: AA0003F6  mov      x22, x0
uint64_t exported_api_084_Cronet_UploadDataSink_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BD7BFDULL) + 0x245E00ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #085: Cronet_UploadDataProvider_CreateWith @ 0x245e54 (84 bytes)
//   0x245e54: D503233F  paciasp  
//   0x245e58: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x245e5c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x245e60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x245e64: 910003FD  mov      x29, sp
//   0x245e68: AA0003F6  mov      x22, x0
uint64_t exported_api_085_Cronet_UploadDataProvider_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BD7BFDULL) + 0x245E54ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #086: Cronet_UrlRequest_CreateWith @ 0x245ea8 (140 bytes)
//   0x245ea8: D503233F  paciasp  
//   0x245eac: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x245eb0: F9000BFB  str      x27, [sp, #0x10]
//   0x245eb4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x245eb8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x245ebc: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t exported_api_086_Cronet_UrlRequest_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BA7BFDULL) + 0x245EA8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #087: Cronet_RequestFinishedInfoListener_CreateWith @ 0x245f34 (60 bytes)
//   0x245f34: D503233F  paciasp  
//   0x245f38: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x245f3c: F9000BF3  str      x19, [sp, #0x10]
//   0x245f40: 910003FD  mov      x29, sp
//   0x245f44: AA0003F3  mov      x19, x0
//   0x245f48: 52800300  mov      w0, #0x18
uint64_t exported_api_087_Cronet_RequestFinishedInfoListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245F34ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #088: Cronet_ConnectionTypeListener_CreateWith @ 0x245f70 (60 bytes)
//   0x245f70: D503233F  paciasp  
//   0x245f74: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x245f78: F9000BF3  str      x19, [sp, #0x10]
//   0x245f7c: 910003FD  mov      x29, sp
//   0x245f80: AA0003F3  mov      x19, x0
//   0x245f84: 52800300  mov      w0, #0x18
uint64_t exported_api_088_Cronet_ConnectionTypeListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245F70ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #089: Cronet_NQEListener_CreateWith @ 0x245fac (80 bytes)
//   0x245fac: D503233F  paciasp  
//   0x245fb0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x245fb4: F9000BF5  str      x21, [sp, #0x10]
//   0x245fb8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x245fbc: 910003FD  mov      x29, sp
//   0x245fc0: AA0003F5  mov      x21, x0
uint64_t exported_api_089_Cronet_NQEListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BD7BFDULL) + 0x245FACULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #090: Cronet_MNListener_CreateWith @ 0x245ffc (60 bytes)
//   0x245ffc: D503233F  paciasp  
//   0x246000: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246004: F9000BF3  str      x19, [sp, #0x10]
//   0x246008: 910003FD  mov      x29, sp
//   0x24600c: AA0003F3  mov      x19, x0
//   0x246010: 52800300  mov      w0, #0x18
uint64_t exported_api_090_Cronet_MNListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x245FFCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #091: Cronet_StoreRegionListener_CreateWith @ 0x246038 (60 bytes)
//   0x246038: D503233F  paciasp  
//   0x24603c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246040: F9000BF3  str      x19, [sp, #0x10]
//   0x246044: 910003FD  mov      x29, sp
//   0x246048: AA0003F3  mov      x19, x0
//   0x24604c: 52800300  mov      w0, #0x18
uint64_t exported_api_091_Cronet_StoreRegionListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x246038ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #092: Cronet_TTNetRequestInfoDelegate_CreateWith @ 0x246074 (60 bytes)
//   0x246074: D503233F  paciasp  
//   0x246078: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24607c: F9000BF3  str      x19, [sp, #0x10]
//   0x246080: 910003FD  mov      x29, sp
//   0x246084: AA0003F3  mov      x19, x0
//   0x246088: 52800300  mov      w0, #0x18
uint64_t exported_api_092_Cronet_TTNetRequestInfoDelegate_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x246074ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #093: Cronet_PublicIPsListener_CreateWith @ 0x2460b0 (60 bytes)
//   0x2460b0: D503233F  paciasp  
//   0x2460b4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2460b8: F9000BF3  str      x19, [sp, #0x10]
//   0x2460bc: 910003FD  mov      x29, sp
//   0x2460c0: AA0003F3  mov      x19, x0
//   0x2460c4: 52800300  mov      w0, #0x18
uint64_t exported_api_093_Cronet_PublicIPsListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2460B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #094: Cronet_LogMonitorListener_CreateWith @ 0x2460ec (64 bytes)
//   0x2460ec: D503233F  paciasp  
//   0x2460f0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2460f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2460f8: 910003FD  mov      x29, sp
//   0x2460fc: AA0003F4  mov      x20, x0
//   0x246100: 52800400  mov      w0, #0x20
uint64_t exported_api_094_Cronet_LogMonitorListener_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2460ECULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #095: Cronet_TTUrlDispatchCallback_CreateWith @ 0x24612c (60 bytes)
//   0x24612c: D503233F  paciasp  
//   0x246130: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246134: F9000BF3  str      x19, [sp, #0x10]
//   0x246138: 910003FD  mov      x29, sp
//   0x24613c: AA0003F3  mov      x19, x0
//   0x246140: 52800300  mov      w0, #0x18
uint64_t exported_api_095_Cronet_TTUrlDispatchCallback_CreateWith(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x24612CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #096: Cronet_Error_Create @ 0x2461a4 (52 bytes)
//   0x2461a4: D503233F  paciasp  
//   0x2461a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2461ac: F9000BF3  str      x19, [sp, #0x10]
//   0x2461b0: 910003FD  mov      x29, sp
//   0x2461b4: 52800600  mov      w0, #0x30
//   0x2461b8: 940258EF  bl       #0x2dc574
uint64_t exported_api_096_Cronet_Error_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2461A4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #097: Cronet_Error_Destroy @ 0x2461d8 (60 bytes)
//   0x2461d8: D503245F  bti      c
//   0x2461dc: B40001A0  cbz      x0, #0x246210
//   0x2461e0: D503233F  paciasp  
//   0x2461e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2461e8: F9000BF3  str      x19, [sp, #0x10]
//   0x2461ec: 910003FD  mov      x29, sp
uint64_t exported_api_097_Cronet_Error_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB40001A0ULL) + 0x2461D8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #098: Cronet_Error_error_code_set @ 0x246214 (12 bytes)
//   0x246214: D503245F  bti      c
//   0x246218: B9000001  str      w1, [x0]
//   0x24621c: D65F03C0  ret      
//   0x246220: D503245F  bti      c
uint64_t exported_api_098_Cronet_Error_error_code_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9000001ULL) + 0x246214ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #099: Cronet_EngineParams_user_agent_set @ 0x246220 (12 bytes)
//   0x246220: D503245F  bti      c
//   0x246224: 91002000  add      x0, x0, #8
//   0x246228: 140D034A  b        #0x586f50
//   0x24622c: D503245F  bti      c
uint64_t exported_api_099_Cronet_EngineParams_user_agent_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91002000ULL) + 0x246220ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #100: Cronet_ConnParams_ping_period_set @ 0x24622c (12 bytes)
//   0x24622c: D503245F  bti      c
//   0x246230: B9002001  str      w1, [x0, #0x20]
//   0x246234: D65F03C0  ret      
//   0x246238: D503245F  bti      c
uint64_t exported_api_100_Cronet_ConnParams_ping_period_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9002001ULL) + 0x24622CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #101: Cronet_Error_immediately_retryable_set @ 0x246238 (12 bytes)
//   0x246238: D503245F  bti      c
//   0x24623c: 39009001  strb     w1, [x0, #0x24]
//   0x246240: D65F03C0  ret      
//   0x246244: D503245F  bti      c
uint64_t exported_api_101_Cronet_Error_immediately_retryable_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39009001ULL) + 0x246238ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #102: Cronet_Error_quic_detailed_error_code_set @ 0x246244 (12 bytes)
//   0x246244: D503245F  bti      c
//   0x246248: B9002801  str      w1, [x0, #0x28]
//   0x24624c: D65F03C0  ret      
//   0x246250: D503245F  bti      c
uint64_t exported_api_102_Cronet_Error_quic_detailed_error_code_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9002801ULL) + 0x246244ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #103: Cronet_Error_error_code_get @ 0x246250 (12 bytes)
//   0x246250: D503245F  bti      c
//   0x246254: B9400000  ldr      w0, [x0]
//   0x246258: D65F03C0  ret      
//   0x24625c: D503245F  bti      c
uint64_t exported_api_103_Cronet_Error_error_code_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9400000ULL) + 0x246250ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #104: Cronet_EngineParams_user_agent_get @ 0x24625c (28 bytes)
//   0x24625c: D503245F  bti      c
//   0x246260: 39402008  ldrb     w8, [x0, #8]
//   0x246264: 37000068  tbnz     w8, #0, #0x246270
//   0x246268: 91002400  add      x0, x0, #9
//   0x24626c: D65F03C0  ret      
//   0x246270: F9400C00  ldr      x0, [x0, #0x18]
uint64_t exported_api_104_Cronet_EngineParams_user_agent_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39402008ULL) + 0x24625CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #105: Cronet_ConnParams_ping_period_get @ 0x246278 (12 bytes)
//   0x246278: D503245F  bti      c
//   0x24627c: B9402000  ldr      w0, [x0, #0x20]
//   0x246280: D65F03C0  ret      
//   0x246284: D503245F  bti      c
uint64_t exported_api_105_Cronet_ConnParams_ping_period_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9402000ULL) + 0x246278ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #106: Cronet_Error_immediately_retryable_get @ 0x246284 (12 bytes)
//   0x246284: D503245F  bti      c
//   0x246288: 39409000  ldrb     w0, [x0, #0x24]
//   0x24628c: D65F03C0  ret      
//   0x246290: D503245F  bti      c
uint64_t exported_api_106_Cronet_Error_immediately_retryable_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39409000ULL) + 0x246284ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #107: Cronet_Error_quic_detailed_error_code_get @ 0x246290 (12 bytes)
//   0x246290: D503245F  bti      c
//   0x246294: B9402800  ldr      w0, [x0, #0x28]
//   0x246298: D65F03C0  ret      
//   0x24629c: D503233F  paciasp  
uint64_t exported_api_107_Cronet_Error_quic_detailed_error_code_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9402800ULL) + 0x246290ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #108: Cronet_RTTAndThroughput_Create @ 0x2462d4 (64 bytes)
//   0x2462d4: D503233F  paciasp  
//   0x2462d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2462dc: 910003FD  mov      x29, sp
//   0x2462e0: 52800B00  mov      w0, #0x58
//   0x2462e4: 940258A4  bl       #0x2dc574
//   0x2462e8: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t exported_api_108_Cronet_RTTAndThroughput_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x2462D4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #109: Cronet_RTTAndThroughput_Destroy @ 0x246314 (56 bytes)
//   0x246314: D503245F  bti      c
//   0x246318: B4000180  cbz      x0, #0x246348
//   0x24631c: D503233F  paciasp  
//   0x246320: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246324: F9000BF3  str      x19, [sp, #0x10]
//   0x246328: 910003FD  mov      x29, sp
uint64_t exported_api_109_Cronet_RTTAndThroughput_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x246314ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #110: Cronet_ClientOpaqueData_host_list_add @ 0x24634c (72 bytes)
//   0x24634c: D503233F  paciasp  
//   0x246350: D10103FF  sub      sp, sp, #0x40
//   0x246354: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x246358: F9001BF3  str      x19, [sp, #0x30]
//   0x24635c: 910083FD  add      x29, sp, #0x20
//   0x246360: AA0003F3  mov      x19, x0
uint64_t exported_api_110_Cronet_ClientOpaqueData_host_list_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10103FFULL) + 0x24634CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #111: Cronet_RTTAndThroughput_group_transport_rtt_add @ 0x246394 (48 bytes)
//   0x246394: D503233F  paciasp  
//   0x246398: D10083FF  sub      sp, sp, #0x20
//   0x24639c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2463a0: 910043FD  add      x29, sp, #0x10
//   0x2463a4: 91006000  add      x0, x0, #0x18
//   0x2463a8: B81FC3A1  stur     w1, [x29, #-4]
uint64_t exported_api_111_Cronet_RTTAndThroughput_group_transport_rtt_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10083FFULL) + 0x246394ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #112: Cronet_RTTAndThroughput_group_http_rtt_add @ 0x2463c4 (48 bytes)
//   0x2463c4: D503233F  paciasp  
//   0x2463c8: D10083FF  sub      sp, sp, #0x20
//   0x2463cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2463d0: 910043FD  add      x29, sp, #0x10
//   0x2463d4: 9100C000  add      x0, x0, #0x30
//   0x2463d8: B81FC3A1  stur     w1, [x29, #-4]
uint64_t exported_api_112_Cronet_RTTAndThroughput_group_http_rtt_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10083FFULL) + 0x2463C4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #113: Cronet_RTTAndThroughput_http_rtt_ms_set @ 0x2463f4 (12 bytes)
//   0x2463f4: D503245F  bti      c
//   0x2463f8: B9004801  str      w1, [x0, #0x48]
//   0x2463fc: D65F03C0  ret      
//   0x246400: D503245F  bti      c
uint64_t exported_api_113_Cronet_RTTAndThroughput_http_rtt_ms_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9004801ULL) + 0x2463F4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #114: Cronet_RTTAndThroughput_transport_rtt_ms_set @ 0x246400 (12 bytes)
//   0x246400: D503245F  bti      c
//   0x246404: B9004C01  str      w1, [x0, #0x4c]
//   0x246408: D65F03C0  ret      
//   0x24640c: D503245F  bti      c
uint64_t exported_api_114_Cronet_RTTAndThroughput_transport_rtt_ms_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9004C01ULL) + 0x246400ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #115: Cronet_RTTAndThroughput_rx_throughput_kbps_set @ 0x24640c (12 bytes)
//   0x24640c: D503245F  bti      c
//   0x246410: B9005001  str      w1, [x0, #0x50]
//   0x246414: D65F03C0  ret      
//   0x246418: D503245F  bti      c
uint64_t exported_api_115_Cronet_RTTAndThroughput_rx_throughput_kbps_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9005001ULL) + 0x24640CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #116: Cronet_ClientOpaqueData_host_list_size @ 0x246418 (24 bytes)
//   0x246418: D503245F  bti      c
//   0x24641c: A940240A  ldp      x10, x9, [x0]
//   0x246420: 52800308  mov      w8, #0x18
//   0x246424: CB0A0129  sub      x9, x9, x10
//   0x246428: 9AC80D20  sdiv     x0, x9, x8
//   0x24642c: D65F03C0  ret      
uint64_t exported_api_116_Cronet_ClientOpaqueData_host_list_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA940240AULL) + 0x246418ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #117: Cronet_ClientOpaqueData_host_list_at @ 0x246430 (40 bytes)
//   0x246430: D503245F  bti      c
//   0x246434: F9400008  ldr      x8, [x0]
//   0x246438: 52800309  mov      w9, #0x18
//   0x24643c: 9BA92028  umaddl   x8, w1, w9, x8
//   0x246440: 39400109  ldrb     w9, [x8]
//   0x246444: 37000069  tbnz     w9, #0, #0x246450
uint64_t exported_api_117_Cronet_ClientOpaqueData_host_list_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x246430ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #118: Cronet_ClientOpaqueData_host_list_clear @ 0x246458 (8 bytes)
//   0x246458: D503245F  bti      c
//   0x24645c: 17FE098A  b        #0x1c8a84
//   0x246460: D503245F  bti      c
//   0x246464: A941A009  ldp      x9, x8, [x0, #0x18]
uint64_t exported_api_118_Cronet_ClientOpaqueData_host_list_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x17FE098AULL) + 0x246458ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #119: Cronet_RTTAndThroughput_group_transport_rtt_size @ 0x246460 (20 bytes)
//   0x246460: D503245F  bti      c
//   0x246464: A941A009  ldp      x9, x8, [x0, #0x18]
//   0x246468: CB090108  sub      x8, x8, x9
//   0x24646c: D342FD00  lsr      x0, x8, #2
//   0x246470: D65F03C0  ret      
uint64_t exported_api_119_Cronet_RTTAndThroughput_group_transport_rtt_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA941A009ULL) + 0x246460ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #120: Cronet_RTTAndThroughput_group_transport_rtt_at @ 0x246474 (16 bytes)
//   0x246474: D503245F  bti      c
//   0x246478: F9400C08  ldr      x8, [x0, #0x18]
//   0x24647c: B8615900  ldr      w0, [x8, w1, uxtw #2]
//   0x246480: D65F03C0  ret      
uint64_t exported_api_120_Cronet_RTTAndThroughput_group_transport_rtt_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C08ULL) + 0x246474ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #121: Cronet_ClientOpaqueData_certificate_clear @ 0x246484 (16 bytes)
//   0x246484: D503245F  bti      c
//   0x246488: F9400C08  ldr      x8, [x0, #0x18]
//   0x24648c: F9001008  str      x8, [x0, #0x20]
//   0x246490: D65F03C0  ret      
uint64_t exported_api_121_Cronet_ClientOpaqueData_certificate_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C08ULL) + 0x246484ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #122: Cronet_RTTAndThroughput_group_http_rtt_size @ 0x246494 (20 bytes)
//   0x246494: D503245F  bti      c
//   0x246498: A9432009  ldp      x9, x8, [x0, #0x30]
//   0x24649c: CB090108  sub      x8, x8, x9
//   0x2464a0: D342FD00  lsr      x0, x8, #2
//   0x2464a4: D65F03C0  ret      
uint64_t exported_api_122_Cronet_RTTAndThroughput_group_http_rtt_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA9432009ULL) + 0x246494ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #123: Cronet_RTTAndThroughput_group_http_rtt_at @ 0x2464a8 (16 bytes)
//   0x2464a8: D503245F  bti      c
//   0x2464ac: F9401808  ldr      x8, [x0, #0x30]
//   0x2464b0: B8615900  ldr      w0, [x8, w1, uxtw #2]
//   0x2464b4: D65F03C0  ret      
uint64_t exported_api_123_Cronet_RTTAndThroughput_group_http_rtt_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401808ULL) + 0x2464A8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #124: Cronet_ClientOpaqueData_private_key_clear @ 0x2464b8 (16 bytes)
//   0x2464b8: D503245F  bti      c
//   0x2464bc: F9401808  ldr      x8, [x0, #0x30]
//   0x2464c0: F9001C08  str      x8, [x0, #0x38]
//   0x2464c4: D65F03C0  ret      
uint64_t exported_api_124_Cronet_ClientOpaqueData_private_key_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401808ULL) + 0x2464B8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #125: Cronet_RTTAndThroughput_http_rtt_ms_get @ 0x2464c8 (12 bytes)
//   0x2464c8: D503245F  bti      c
//   0x2464cc: B9404800  ldr      w0, [x0, #0x48]
//   0x2464d0: D65F03C0  ret      
//   0x2464d4: D503245F  bti      c
uint64_t exported_api_125_Cronet_RTTAndThroughput_http_rtt_ms_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9404800ULL) + 0x2464C8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #126: Cronet_RTTAndThroughput_transport_rtt_ms_get @ 0x2464d4 (12 bytes)
//   0x2464d4: D503245F  bti      c
//   0x2464d8: B9404C00  ldr      w0, [x0, #0x4c]
//   0x2464dc: D65F03C0  ret      
//   0x2464e0: D503245F  bti      c
uint64_t exported_api_126_Cronet_RTTAndThroughput_transport_rtt_ms_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9404C00ULL) + 0x2464D4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #127: Cronet_RTTAndThroughput_rx_throughput_kbps_get @ 0x2464e0 (12 bytes)
//   0x2464e0: D503245F  bti      c
//   0x2464e4: B9405000  ldr      w0, [x0, #0x50]
//   0x2464e8: D65F03C0  ret      
//   0x2464ec: D503233F  paciasp  
uint64_t exported_api_127_Cronet_RTTAndThroughput_rx_throughput_kbps_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9405000ULL) + 0x2464E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #128: Cronet_PacketLostStats_Create @ 0x2464ec (52 bytes)
//   0x2464ec: D503233F  paciasp  
//   0x2464f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2464f4: 910003FD  mov      x29, sp
//   0x2464f8: 52800500  mov      w0, #0x28
//   0x2464fc: 9402581E  bl       #0x2dc574
//   0x246500: 6F07F600  fmov     v0.2d, #-1.00000000
uint64_t exported_api_128_Cronet_PacketLostStats_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x2464ECULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #129: Cronet_PacketLostStats_tx_lost_rate_set @ 0x246520 (12 bytes)
//   0x246520: D503245F  bti      c
//   0x246524: FD000400  str      d0, [x0, #8]
//   0x246528: D65F03C0  ret      
//   0x24652c: D503245F  bti      c
uint64_t exported_api_129_Cronet_PacketLostStats_tx_lost_rate_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD000400ULL) + 0x246520ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #130: Cronet_PacketLostStats_tx_lost_var_set @ 0x24652c (12 bytes)
//   0x24652c: D503245F  bti      c
//   0x246530: FD000800  str      d0, [x0, #0x10]
//   0x246534: D65F03C0  ret      
//   0x246538: D503245F  bti      c
uint64_t exported_api_130_Cronet_PacketLostStats_tx_lost_var_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD000800ULL) + 0x24652CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #131: Cronet_PacketLostStats_rx_lost_rate_set @ 0x246538 (12 bytes)
//   0x246538: D503245F  bti      c
//   0x24653c: FD000C00  str      d0, [x0, #0x18]
//   0x246540: D65F03C0  ret      
//   0x246544: D503245F  bti      c
uint64_t exported_api_131_Cronet_PacketLostStats_rx_lost_rate_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD000C00ULL) + 0x246538ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #132: Cronet_PacketLostStats_rx_lost_var_set @ 0x246544 (12 bytes)
//   0x246544: D503245F  bti      c
//   0x246548: FD001000  str      d0, [x0, #0x20]
//   0x24654c: D65F03C0  ret      
//   0x246550: D503245F  bti      c
uint64_t exported_api_132_Cronet_PacketLostStats_rx_lost_var_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD001000ULL) + 0x246544ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #133: Cronet_PacketLostStats_tx_lost_rate_get @ 0x246550 (12 bytes)
//   0x246550: D503245F  bti      c
//   0x246554: FD400400  ldr      d0, [x0, #8]
//   0x246558: D65F03C0  ret      
//   0x24655c: D503245F  bti      c
uint64_t exported_api_133_Cronet_PacketLostStats_tx_lost_rate_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD400400ULL) + 0x246550ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #134: Cronet_PacketLostStats_tx_lost_var_get @ 0x24655c (12 bytes)
//   0x24655c: D503245F  bti      c
//   0x246560: FD400800  ldr      d0, [x0, #0x10]
//   0x246564: D65F03C0  ret      
//   0x246568: D503245F  bti      c
uint64_t exported_api_134_Cronet_PacketLostStats_tx_lost_var_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD400800ULL) + 0x24655CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #135: Cronet_PacketLostStats_rx_lost_rate_get @ 0x246568 (12 bytes)
//   0x246568: D503245F  bti      c
//   0x24656c: FD400C00  ldr      d0, [x0, #0x18]
//   0x246570: D65F03C0  ret      
//   0x246574: D503245F  bti      c
uint64_t exported_api_135_Cronet_PacketLostStats_rx_lost_rate_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD400C00ULL) + 0x246568ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #136: Cronet_PacketLostStats_rx_lost_var_get @ 0x246574 (12 bytes)
//   0x246574: D503245F  bti      c
//   0x246578: FD401000  ldr      d0, [x0, #0x20]
//   0x24657c: D65F03C0  ret      
//   0x246580: D503233F  paciasp  
uint64_t exported_api_136_Cronet_PacketLostStats_rx_lost_var_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xFD401000ULL) + 0x246574ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #137: Cronet_NetworkInterface_Create @ 0x24663c (52 bytes)
//   0x24663c: D503233F  paciasp  
//   0x246640: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246644: F9000BF3  str      x19, [sp, #0x10]
//   0x246648: 910003FD  mov      x29, sp
//   0x24664c: 52800A00  mov      w0, #0x50
//   0x246650: 940257C9  bl       #0x2dc574
uint64_t exported_api_137_Cronet_NetworkInterface_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x24663CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #138: Cronet_NetworkInterface_Destroy @ 0x246670 (56 bytes)
//   0x246670: D503245F  bti      c
//   0x246674: B4000180  cbz      x0, #0x2466a4
//   0x246678: D503233F  paciasp  
//   0x24667c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246680: F9000BF3  str      x19, [sp, #0x10]
//   0x246684: 910003FD  mov      x29, sp
uint64_t exported_api_138_Cronet_NetworkInterface_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x246670ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #139: Cronet_AuthCredentials_username_set @ 0x2466a8 (8 bytes)
//   0x2466a8: D503245F  bti      c
//   0x2466ac: 140D0229  b        #0x586f50
//   0x2466b0: D503245F  bti      c
//   0x2466b4: 91006000  add      x0, x0, #0x18
uint64_t exported_api_139_Cronet_AuthCredentials_username_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x140D0229ULL) + 0x2466A8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #140: Cronet_AuthCredentials_password_set @ 0x2466b0 (12 bytes)
//   0x2466b0: D503245F  bti      c
//   0x2466b4: 91006000  add      x0, x0, #0x18
//   0x2466b8: 140D0226  b        #0x586f50
//   0x2466bc: D503245F  bti      c
uint64_t exported_api_140_Cronet_AuthCredentials_password_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91006000ULL) + 0x2466B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #141: Cronet_NetworkInterface_index_set @ 0x2466bc (12 bytes)
//   0x2466bc: D503245F  bti      c
//   0x2466c0: B9003001  str      w1, [x0, #0x30]
//   0x2466c4: D65F03C0  ret      
//   0x2466c8: D503245F  bti      c
uint64_t exported_api_141_Cronet_NetworkInterface_index_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9003001ULL) + 0x2466BCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #142: Cronet_NetworkInterface_type_set @ 0x2466c8 (12 bytes)
//   0x2466c8: D503245F  bti      c
//   0x2466cc: B9003401  str      w1, [x0, #0x34]
//   0x2466d0: D65F03C0  ret      
//   0x2466d4: D503245F  bti      c
uint64_t exported_api_142_Cronet_NetworkInterface_type_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9003401ULL) + 0x2466C8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #143: Cronet_EngineParams_storage_path_set @ 0x2466d4 (12 bytes)
//   0x2466d4: D503245F  bti      c
//   0x2466d8: 9100E000  add      x0, x0, #0x38
//   0x2466dc: 140D021D  b        #0x586f50
//   0x2466e0: D503245F  bti      c
uint64_t exported_api_143_Cronet_EngineParams_storage_path_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9100E000ULL) + 0x2466D4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #144: Cronet_AuthCredentials_username_get @ 0x2466e0 (28 bytes)
//   0x2466e0: D503245F  bti      c
//   0x2466e4: 39400008  ldrb     w8, [x0]
//   0x2466e8: 37000068  tbnz     w8, #0, #0x2466f4
//   0x2466ec: 91000400  add      x0, x0, #1
//   0x2466f0: D65F03C0  ret      
//   0x2466f4: F9400800  ldr      x0, [x0, #0x10]
uint64_t exported_api_144_Cronet_AuthCredentials_username_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39400008ULL) + 0x2466E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #145: Cronet_AuthCredentials_password_get @ 0x2466fc (28 bytes)
//   0x2466fc: D503245F  bti      c
//   0x246700: 39406008  ldrb     w8, [x0, #0x18]
//   0x246704: 37000068  tbnz     w8, #0, #0x246710
//   0x246708: 91006400  add      x0, x0, #0x19
//   0x24670c: D65F03C0  ret      
//   0x246710: F9401400  ldr      x0, [x0, #0x28]
uint64_t exported_api_145_Cronet_AuthCredentials_password_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39406008ULL) + 0x2466FCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #146: Cronet_NetworkInterface_index_get @ 0x246718 (12 bytes)
//   0x246718: D503245F  bti      c
//   0x24671c: B9403000  ldr      w0, [x0, #0x30]
//   0x246720: D65F03C0  ret      
//   0x246724: D503245F  bti      c
uint64_t exported_api_146_Cronet_NetworkInterface_index_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9403000ULL) + 0x246718ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #147: Cronet_NetworkInterface_type_get @ 0x246724 (12 bytes)
//   0x246724: D503245F  bti      c
//   0x246728: B9403400  ldr      w0, [x0, #0x34]
//   0x24672c: D65F03C0  ret      
//   0x246730: D503245F  bti      c
uint64_t exported_api_147_Cronet_NetworkInterface_type_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9403400ULL) + 0x246724ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #148: Cronet_EngineParams_storage_path_get @ 0x246730 (28 bytes)
//   0x246730: D503245F  bti      c
//   0x246734: 3940E008  ldrb     w8, [x0, #0x38]
//   0x246738: 37000068  tbnz     w8, #0, #0x246744
//   0x24673c: 9100E400  add      x0, x0, #0x39
//   0x246740: D65F03C0  ret      
//   0x246744: F9402400  ldr      x0, [x0, #0x48]
uint64_t exported_api_148_Cronet_EngineParams_storage_path_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x3940E008ULL) + 0x246730ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #149: Cronet_NetworkReport_Create @ 0x24674c (44 bytes)
//   0x24674c: D503233F  paciasp  
//   0x246750: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x246754: 910003FD  mov      x29, sp
//   0x246758: 52800400  mov      w0, #0x20
//   0x24675c: 94025786  bl       #0x2dc574
//   0x246760: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t exported_api_149_Cronet_NetworkReport_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x24674CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #150: Cronet_NetworkReport_Destroy @ 0x246778 (56 bytes)
//   0x246778: D503245F  bti      c
//   0x24677c: B4000180  cbz      x0, #0x2467ac
//   0x246780: D503233F  paciasp  
//   0x246784: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246788: F9000BF3  str      x19, [sp, #0x10]
//   0x24678c: 910003FD  mov      x29, sp
uint64_t exported_api_150_Cronet_NetworkReport_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x246778ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #151: Cronet_NetworkReport_interfaces_add @ 0x2467b0 (8 bytes)
//   0x2467b0: D503245F  bti      c
//   0x2467b4: 17FFD75E  b        #0x23c52c
//   0x2467b8: D503245F  bti      c
//   0x2467bc: 39006001  strb     w1, [x0, #0x18]
uint64_t exported_api_151_Cronet_NetworkReport_interfaces_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x17FFD75EULL) + 0x2467B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #152: Cronet_InnerRequestFinishedInfo_succ_set @ 0x2467b8 (12 bytes)
//   0x2467b8: D503245F  bti      c
//   0x2467bc: 39006001  strb     w1, [x0, #0x18]
//   0x2467c0: D65F03C0  ret      
//   0x2467c4: D503245F  bti      c
uint64_t exported_api_152_Cronet_InnerRequestFinishedInfo_succ_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39006001ULL) + 0x2467B8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #153: Cronet_NetworkReport_has_vpn_set @ 0x2467c4 (12 bytes)
//   0x2467c4: D503245F  bti      c
//   0x2467c8: 39006401  strb     w1, [x0, #0x19]
//   0x2467cc: D65F03C0  ret      
//   0x2467d0: D503245F  bti      c
uint64_t exported_api_153_Cronet_NetworkReport_has_vpn_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39006401ULL) + 0x2467C4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #154: Cronet_NetworkReport_interfaces_size @ 0x2467d0 (24 bytes)
//   0x2467d0: D503245F  bti      c
//   0x2467d4: A940240A  ldp      x10, x9, [x0]
//   0x2467d8: 52800A08  mov      w8, #0x50
//   0x2467dc: CB0A0129  sub      x9, x9, x10
//   0x2467e0: 9AC80D20  sdiv     x0, x9, x8
//   0x2467e4: D65F03C0  ret      
uint64_t exported_api_154_Cronet_NetworkReport_interfaces_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA940240AULL) + 0x2467D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #155: Cronet_NetworkReport_interfaces_at @ 0x2467e8 (20 bytes)
//   0x2467e8: D503245F  bti      c
//   0x2467ec: F9400008  ldr      x8, [x0]
//   0x2467f0: 52800A09  mov      w9, #0x50
//   0x2467f4: 9BA92020  umaddl   x0, w1, w9, x8
//   0x2467f8: D65F03C0  ret      
uint64_t exported_api_155_Cronet_NetworkReport_interfaces_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x2467E8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #156: Cronet_NetworkReport_interfaces_clear @ 0x2467fc (8 bytes)
//   0x2467fc: D503245F  bti      c
//   0x246800: 17FFD7CA  b        #0x23c728
//   0x246804: D503245F  bti      c
//   0x246808: 39406000  ldrb     w0, [x0, #0x18]
uint64_t exported_api_156_Cronet_NetworkReport_interfaces_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x17FFD7CAULL) + 0x2467FCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #157: Cronet_InnerRequestFinishedInfo_succ_get @ 0x246804 (12 bytes)
//   0x246804: D503245F  bti      c
//   0x246808: 39406000  ldrb     w0, [x0, #0x18]
//   0x24680c: D65F03C0  ret      
//   0x246810: D503245F  bti      c
uint64_t exported_api_157_Cronet_InnerRequestFinishedInfo_succ_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39406000ULL) + 0x246804ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #158: Cronet_NetworkReport_has_vpn_get @ 0x246810 (12 bytes)
//   0x246810: D503245F  bti      c
//   0x246814: 39406400  ldrb     w0, [x0, #0x19]
//   0x246818: D65F03C0  ret      
//   0x24681c: D503233F  paciasp  
uint64_t exported_api_158_Cronet_NetworkReport_has_vpn_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x39406400ULL) + 0x246810ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #159: Cronet_TTDnsResult_Create @ 0x24681c (80 bytes)
//   0x24681c: D503233F  paciasp  
//   0x246820: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246824: F9000BF3  str      x19, [sp, #0x10]
//   0x246828: 910003FD  mov      x29, sp
//   0x24682c: 52800800  mov      w0, #0x40
//   0x246830: 94025751  bl       #0x2dc574
uint64_t exported_api_159_Cronet_TTDnsResult_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x24681CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #160: Cronet_TTDnsResult_Destroy @ 0x24686c (68 bytes)
//   0x24686c: D503245F  bti      c
//   0x246870: B40001E0  cbz      x0, #0x2468ac
//   0x246874: D503233F  paciasp  
//   0x246878: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24687c: F9000BF3  str      x19, [sp, #0x10]
//   0x246880: 910003FD  mov      x29, sp
uint64_t exported_api_160_Cronet_TTDnsResult_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB40001E0ULL) + 0x24686CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #161: Cronet_FrontierConfig_fpid_set @ 0x2468b0 (12 bytes)
//   0x2468b0: D503245F  bti      c
//   0x2468b4: B9000401  str      w1, [x0, #4]
//   0x2468b8: D65F03C0  ret      
//   0x2468bc: D503245F  bti      c
uint64_t exported_api_161_Cronet_FrontierConfig_fpid_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9000401ULL) + 0x2468B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #162: Cronet_ServiceInfo_priority_set @ 0x2468bc (12 bytes)
//   0x2468bc: D503245F  bti      c
//   0x2468c0: B9000801  str      w1, [x0, #8]
//   0x2468c4: D65F03C0  ret      
//   0x2468c8: D503233F  paciasp  
uint64_t exported_api_162_Cronet_ServiceInfo_priority_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9000801ULL) + 0x2468BCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #163: Cronet_TTDnsResult_iplist_add @ 0x2468c8 (72 bytes)
//   0x2468c8: D503233F  paciasp  
//   0x2468cc: D10103FF  sub      sp, sp, #0x40
//   0x2468d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2468d4: F9001BF3  str      x19, [sp, #0x30]
//   0x2468d8: 910083FD  add      x29, sp, #0x20
//   0x2468dc: 91004013  add      x19, x0, #0x10
uint64_t exported_api_163_Cronet_TTDnsResult_iplist_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10103FFULL) + 0x2468C8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #164: Cronet_FrontierConfig_app_version_set @ 0x246910 (12 bytes)
//   0x246910: D503245F  bti      c
//   0x246914: 9100A000  add      x0, x0, #0x28
//   0x246918: 140D018E  b        #0x586f50
//   0x24691c: D503245F  bti      c
uint64_t exported_api_164_Cronet_FrontierConfig_app_version_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9100A000ULL) + 0x246910ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #165: Cronet_FrontierConfig_fpid_get @ 0x24691c (12 bytes)
//   0x24691c: D503245F  bti      c
//   0x246920: B9400400  ldr      w0, [x0, #4]
//   0x246924: D65F03C0  ret      
//   0x246928: D503245F  bti      c
uint64_t exported_api_165_Cronet_FrontierConfig_fpid_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9400400ULL) + 0x24691CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #166: Cronet_TTDnsResult_iplist_size @ 0x246928 (24 bytes)
//   0x246928: D503245F  bti      c
//   0x24692c: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x246930: 52800308  mov      w8, #0x18
//   0x246934: CB0A0129  sub      x9, x9, x10
//   0x246938: 9AC80D20  sdiv     x0, x9, x8
//   0x24693c: D65F03C0  ret      
uint64_t exported_api_166_Cronet_TTDnsResult_iplist_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA941240AULL) + 0x246928ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #167: Cronet_TTDnsResult_iplist_at @ 0x246940 (40 bytes)
//   0x246940: D503245F  bti      c
//   0x246944: F9400808  ldr      x8, [x0, #0x10]
//   0x246948: 52800309  mov      w9, #0x18
//   0x24694c: 9BA92028  umaddl   x8, w1, w9, x8
//   0x246950: 39400109  ldrb     w9, [x8]
//   0x246954: 37000069  tbnz     w9, #0, #0x246960
uint64_t exported_api_167_Cronet_TTDnsResult_iplist_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400808ULL) + 0x246940ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #168: Cronet_TTDnsResult_iplist_clear @ 0x246968 (12 bytes)
//   0x246968: D503245F  bti      c
//   0x24696c: 91004000  add      x0, x0, #0x10
//   0x246970: 17FE0845  b        #0x1c8a84
//   0x246974: D503245F  bti      c
uint64_t exported_api_168_Cronet_TTDnsResult_iplist_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91004000ULL) + 0x246968ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #169: Cronet_FrontierConfig_app_version_get @ 0x246974 (28 bytes)
//   0x246974: D503245F  bti      c
//   0x246978: 3940A008  ldrb     w8, [x0, #0x28]
//   0x24697c: 37000068  tbnz     w8, #0, #0x246988
//   0x246980: 9100A400  add      x0, x0, #0x29
//   0x246984: D65F03C0  ret      
//   0x246988: F9401C00  ldr      x0, [x0, #0x38]
uint64_t exported_api_169_Cronet_FrontierConfig_app_version_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x3940A008ULL) + 0x246974ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #170: Cronet_CertData_Create @ 0x246990 (40 bytes)
//   0x246990: D503233F  paciasp  
//   0x246994: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x246998: 910003FD  mov      x29, sp
//   0x24699c: 52800300  mov      w0, #0x18
//   0x2469a0: 940256F5  bl       #0x2dc574
//   0x2469a4: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t exported_api_170_Cronet_CertData_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x246990ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #171: Cronet_CertData_Destroy @ 0x2469b8 (56 bytes)
//   0x2469b8: D503245F  bti      c
//   0x2469bc: B4000180  cbz      x0, #0x2469ec
//   0x2469c0: D503233F  paciasp  
//   0x2469c4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2469c8: F9000BF3  str      x19, [sp, #0x10]
//   0x2469cc: 910003FD  mov      x29, sp
uint64_t exported_api_171_Cronet_CertData_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x2469B8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #172: Cronet_CertData_data_add @ 0x2469f0 (44 bytes)
//   0x2469f0: D503233F  paciasp  
//   0x2469f4: D10083FF  sub      sp, sp, #0x20
//   0x2469f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2469fc: 910043FD  add      x29, sp, #0x10
//   0x246a00: 381FC3A1  sturb    w1, [x29, #-4]
//   0x246a04: D10013A1  sub      x1, x29, #4
uint64_t exported_api_172_Cronet_CertData_data_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10083FFULL) + 0x2469F0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #173: Cronet_CertData_data_size @ 0x246a1c (20 bytes)
//   0x246a1c: D503245F  bti      c
//   0x246a20: B9400808  ldr      w8, [x0, #8]
//   0x246a24: B9400009  ldr      w9, [x0]
//   0x246a28: 4B090100  sub      w0, w8, w9
//   0x246a2c: D65F03C0  ret      
uint64_t exported_api_173_Cronet_CertData_data_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9400808ULL) + 0x246A1CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #174: Cronet_CertData_data_at @ 0x246a30 (16 bytes)
//   0x246a30: D503245F  bti      c
//   0x246a34: F9400008  ldr      x8, [x0]
//   0x246a38: 38614900  ldrb     w0, [x8, w1, uxtw]
//   0x246a3c: D65F03C0  ret      
uint64_t exported_api_174_Cronet_CertData_data_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x246A30ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #175: Cronet_CertData_data_clear @ 0x246a40 (16 bytes)
//   0x246a40: D503245F  bti      c
//   0x246a44: F9400008  ldr      x8, [x0]
//   0x246a48: F9000408  str      x8, [x0, #8]
//   0x246a4c: D65F03C0  ret      
uint64_t exported_api_175_Cronet_CertData_data_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400008ULL) + 0x246A40ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #176: Cronet_ClientOpaqueData_Create @ 0x246bf8 (52 bytes)
//   0x246bf8: D503233F  paciasp  
//   0x246bfc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x246c00: 910003FD  mov      x29, sp
//   0x246c04: 52800E00  mov      w0, #0x70
//   0x246c08: 9402565B  bl       #0x2dc574
//   0x246c0c: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t exported_api_176_Cronet_ClientOpaqueData_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BF7BFDULL) + 0x246BF8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #177: Cronet_ClientOpaqueData_Destroy @ 0x246c2c (56 bytes)
//   0x246c2c: D503245F  bti      c
//   0x246c30: B4000180  cbz      x0, #0x246c60
//   0x246c34: D503233F  paciasp  
//   0x246c38: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246c3c: F9000BF3  str      x19, [sp, #0x10]
//   0x246c40: 910003FD  mov      x29, sp
uint64_t exported_api_177_Cronet_ClientOpaqueData_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x246C2CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #178: Cronet_ClientOpaqueData_certificate_add @ 0x246c64 (48 bytes)
//   0x246c64: D503233F  paciasp  
//   0x246c68: D10083FF  sub      sp, sp, #0x20
//   0x246c6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x246c70: 910043FD  add      x29, sp, #0x10
//   0x246c74: 91006000  add      x0, x0, #0x18
//   0x246c78: 381FC3A1  sturb    w1, [x29, #-4]
uint64_t exported_api_178_Cronet_ClientOpaqueData_certificate_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10083FFULL) + 0x246C64ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #179: Cronet_ClientOpaqueData_private_key_add @ 0x246c94 (48 bytes)
//   0x246c94: D503233F  paciasp  
//   0x246c98: D10083FF  sub      sp, sp, #0x20
//   0x246c9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x246ca0: 910043FD  add      x29, sp, #0x10
//   0x246ca4: 9100C000  add      x0, x0, #0x30
//   0x246ca8: 381FC3A1  sturb    w1, [x29, #-4]
uint64_t exported_api_179_Cronet_ClientOpaqueData_private_key_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10083FFULL) + 0x246C94ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #180: Cronet_ClientOpaqueData_certificate_chain_add @ 0x246cc4 (12 bytes)
//   0x246cc4: D503245F  bti      c
//   0x246cc8: 91012000  add      x0, x0, #0x48
//   0x246ccc: 14000001  b        #0x246cd0
//   0x246cd0: D503233F  paciasp  
uint64_t exported_api_180_Cronet_ClientOpaqueData_certificate_chain_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91012000ULL) + 0x246CC4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #181: Cronet_ClientOpaqueData_algorithm_prefer_set @ 0x246e28 (12 bytes)
//   0x246e28: D503245F  bti      c
//   0x246e2c: F9003001  str      x1, [x0, #0x60]
//   0x246e30: D65F03C0  ret      
//   0x246e34: D503245F  bti      c
uint64_t exported_api_181_Cronet_ClientOpaqueData_algorithm_prefer_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9003001ULL) + 0x246E28ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #182: Cronet_ClientOpaqueData_do_sign_set @ 0x246e34 (12 bytes)
//   0x246e34: D503245F  bti      c
//   0x246e38: F9003401  str      x1, [x0, #0x68]
//   0x246e3c: D65F03C0  ret      
//   0x246e40: D503245F  bti      c
uint64_t exported_api_182_Cronet_ClientOpaqueData_do_sign_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9003401ULL) + 0x246E34ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #183: Cronet_ClientOpaqueData_certificate_size @ 0x246e40 (20 bytes)
//   0x246e40: D503245F  bti      c
//   0x246e44: B9402008  ldr      w8, [x0, #0x20]
//   0x246e48: B9401809  ldr      w9, [x0, #0x18]
//   0x246e4c: 4B090100  sub      w0, w8, w9
//   0x246e50: D65F03C0  ret      
uint64_t exported_api_183_Cronet_ClientOpaqueData_certificate_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9402008ULL) + 0x246E40ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #184: Cronet_ClientOpaqueData_certificate_at @ 0x246e54 (16 bytes)
//   0x246e54: D503245F  bti      c
//   0x246e58: F9400C08  ldr      x8, [x0, #0x18]
//   0x246e5c: 38614900  ldrb     w0, [x8, w1, uxtw]
//   0x246e60: D65F03C0  ret      
uint64_t exported_api_184_Cronet_ClientOpaqueData_certificate_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C08ULL) + 0x246E54ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #185: Cronet_ClientOpaqueData_private_key_size @ 0x246e64 (20 bytes)
//   0x246e64: D503245F  bti      c
//   0x246e68: B9403808  ldr      w8, [x0, #0x38]
//   0x246e6c: B9403009  ldr      w9, [x0, #0x30]
//   0x246e70: 4B090100  sub      w0, w8, w9
//   0x246e74: D65F03C0  ret      
uint64_t exported_api_185_Cronet_ClientOpaqueData_private_key_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9403808ULL) + 0x246E64ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #186: Cronet_ClientOpaqueData_private_key_at @ 0x246e78 (16 bytes)
//   0x246e78: D503245F  bti      c
//   0x246e7c: F9401808  ldr      x8, [x0, #0x30]
//   0x246e80: 38614900  ldrb     w0, [x8, w1, uxtw]
//   0x246e84: D65F03C0  ret      
uint64_t exported_api_186_Cronet_ClientOpaqueData_private_key_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401808ULL) + 0x246E78ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #187: Cronet_ClientOpaqueData_certificate_chain_size @ 0x246e88 (24 bytes)
//   0x246e88: D503245F  bti      c
//   0x246e8c: A944A40A  ldp      x10, x9, [x0, #0x48]
//   0x246e90: 52800308  mov      w8, #0x18
//   0x246e94: CB0A0129  sub      x9, x9, x10
//   0x246e98: 9AC80D20  sdiv     x0, x9, x8
//   0x246e9c: D65F03C0  ret      
uint64_t exported_api_187_Cronet_ClientOpaqueData_certificate_chain_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA944A40AULL) + 0x246E88ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #188: Cronet_ClientOpaqueData_certificate_chain_at @ 0x246ea0 (20 bytes)
//   0x246ea0: D503245F  bti      c
//   0x246ea4: F9402408  ldr      x8, [x0, #0x48]
//   0x246ea8: 52800309  mov      w9, #0x18
//   0x246eac: 9BA92020  umaddl   x0, w1, w9, x8
//   0x246eb0: D65F03C0  ret      
uint64_t exported_api_188_Cronet_ClientOpaqueData_certificate_chain_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9402408ULL) + 0x246EA0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #189: Cronet_ClientOpaqueData_certificate_chain_clear @ 0x246eb4 (12 bytes)
//   0x246eb4: D503245F  bti      c
//   0x246eb8: 91012000  add      x0, x0, #0x48
//   0x246ebc: 17FFFF3C  b        #0x246bac
//   0x246ec0: D503245F  bti      c
uint64_t exported_api_189_Cronet_ClientOpaqueData_certificate_chain_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91012000ULL) + 0x246EB4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #190: Cronet_ClientOpaqueData_algorithm_prefer_get @ 0x246ec0 (12 bytes)
//   0x246ec0: D503245F  bti      c
//   0x246ec4: F9403000  ldr      x0, [x0, #0x60]
//   0x246ec8: D65F03C0  ret      
//   0x246ecc: D503245F  bti      c
uint64_t exported_api_190_Cronet_ClientOpaqueData_algorithm_prefer_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9403000ULL) + 0x246EC0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #191: Cronet_ClientOpaqueData_do_sign_get @ 0x246ecc (12 bytes)
//   0x246ecc: D503245F  bti      c
//   0x246ed0: F9403400  ldr      x0, [x0, #0x68]
//   0x246ed4: D65F03C0  ret      
//   0x246ed8: D503233F  paciasp  
uint64_t exported_api_191_Cronet_ClientOpaqueData_do_sign_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9403400ULL) + 0x246ECCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #192: Cronet_QuicHint_Create @ 0x246f0c (56 bytes)
//   0x246f0c: D503233F  paciasp  
//   0x246f10: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246f14: F9000BF3  str      x19, [sp, #0x10]
//   0x246f18: 910003FD  mov      x29, sp
//   0x246f1c: 52800400  mov      w0, #0x20
//   0x246f20: 94025595  bl       #0x2dc574
uint64_t exported_api_192_Cronet_QuicHint_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x246F0CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #193: Cronet_ConnParams_Destroy @ 0x246f44 (56 bytes)
//   0x246f44: D503245F  bti      c
//   0x246f48: B4000180  cbz      x0, #0x246f78
//   0x246f4c: D503233F  paciasp  
//   0x246f50: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246f54: F9000BF3  str      x19, [sp, #0x10]
//   0x246f58: 910003FD  mov      x29, sp
uint64_t exported_api_193_Cronet_ConnParams_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x246F44ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #194: Cronet_QuicHint_port_set @ 0x246f7c (12 bytes)
//   0x246f7c: D503245F  bti      c
//   0x246f80: B9001801  str      w1, [x0, #0x18]
//   0x246f84: D65F03C0  ret      
//   0x246f88: D503245F  bti      c
uint64_t exported_api_194_Cronet_QuicHint_port_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9001801ULL) + 0x246F7CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #195: Cronet_ConnParams_mode_set @ 0x246f88 (12 bytes)
//   0x246f88: D503245F  bti      c
//   0x246f8c: B9001C01  str      w1, [x0, #0x1c]
//   0x246f90: D65F03C0  ret      
//   0x246f94: D503245F  bti      c
uint64_t exported_api_195_Cronet_ConnParams_mode_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9001C01ULL) + 0x246F88ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #196: Cronet_QuicHint_port_get @ 0x246f94 (12 bytes)
//   0x246f94: D503245F  bti      c
//   0x246f98: B9401800  ldr      w0, [x0, #0x18]
//   0x246f9c: D65F03C0  ret      
//   0x246fa0: D503245F  bti      c
uint64_t exported_api_196_Cronet_QuicHint_port_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9401800ULL) + 0x246F94ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #197: Cronet_ConnParams_mode_get @ 0x246fa0 (12 bytes)
//   0x246fa0: D503245F  bti      c
//   0x246fa4: B9401C00  ldr      w0, [x0, #0x1c]
//   0x246fa8: D65F03C0  ret      
//   0x246fac: D503233F  paciasp  
uint64_t exported_api_197_Cronet_ConnParams_mode_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB9401C00ULL) + 0x246FA0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #198: Cronet_PublicKeyPins_Create @ 0x24701c (68 bytes)
//   0x24701c: D503233F  paciasp  
//   0x247020: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x247024: F9000BF3  str      x19, [sp, #0x10]
//   0x247028: 910003FD  mov      x29, sp
//   0x24702c: 52800800  mov      w0, #0x40
//   0x247030: 94025551  bl       #0x2dc574
uint64_t exported_api_198_Cronet_PublicKeyPins_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x24701CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #199: Cronet_PublicKeyPins_Destroy @ 0x247060 (56 bytes)
//   0x247060: D503245F  bti      c
//   0x247064: B4000180  cbz      x0, #0x247094
//   0x247068: D503233F  paciasp  
//   0x24706c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x247070: F9000BF3  str      x19, [sp, #0x10]
//   0x247074: 910003FD  mov      x29, sp
uint64_t exported_api_199_Cronet_PublicKeyPins_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x247060ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #200: Cronet_PublicIPs_ipv6_list_add @ 0x247098 (72 bytes)
//   0x247098: D503233F  paciasp  
//   0x24709c: D10103FF  sub      sp, sp, #0x40
//   0x2470a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2470a4: F9001BF3  str      x19, [sp, #0x30]
//   0x2470a8: 910083FD  add      x29, sp, #0x20
//   0x2470ac: 91006013  add      x19, x0, #0x18
uint64_t exported_api_200_Cronet_PublicIPs_ipv6_list_add(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xD10103FFULL) + 0x247098ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #201: Cronet_PublicKeyPins_include_subdomains_set @ 0x2470e0 (12 bytes)
//   0x2470e0: D503245F  bti      c
//   0x2470e4: 3900C001  strb     w1, [x0, #0x30]
//   0x2470e8: D65F03C0  ret      
//   0x2470ec: D503245F  bti      c
uint64_t exported_api_201_Cronet_PublicKeyPins_include_subdomains_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x3900C001ULL) + 0x2470E0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #202: Cronet_PublicKeyPins_expiration_date_set @ 0x2470ec (12 bytes)
//   0x2470ec: D503245F  bti      c
//   0x2470f0: F9001C01  str      x1, [x0, #0x38]
//   0x2470f4: D65F03C0  ret      
//   0x2470f8: D503245F  bti      c
uint64_t exported_api_202_Cronet_PublicKeyPins_expiration_date_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9001C01ULL) + 0x2470ECULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #203: Cronet_PublicIPs_ipv6_list_size @ 0x2470f8 (24 bytes)
//   0x2470f8: D503245F  bti      c
//   0x2470fc: A941A40A  ldp      x10, x9, [x0, #0x18]
//   0x247100: 52800308  mov      w8, #0x18
//   0x247104: CB0A0129  sub      x9, x9, x10
//   0x247108: 9AC80D20  sdiv     x0, x9, x8
//   0x24710c: D65F03C0  ret      
uint64_t exported_api_203_Cronet_PublicIPs_ipv6_list_size(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xA941A40AULL) + 0x2470F8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #204: Cronet_PublicIPs_ipv6_list_at @ 0x247110 (40 bytes)
//   0x247110: D503245F  bti      c
//   0x247114: F9400C08  ldr      x8, [x0, #0x18]
//   0x247118: 52800309  mov      w9, #0x18
//   0x24711c: 9BA92028  umaddl   x8, w1, w9, x8
//   0x247120: 39400109  ldrb     w9, [x8]
//   0x247124: 37000069  tbnz     w9, #0, #0x247130
uint64_t exported_api_204_Cronet_PublicIPs_ipv6_list_at(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9400C08ULL) + 0x247110ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #205: Cronet_PublicIPs_ipv6_list_clear @ 0x247138 (12 bytes)
//   0x247138: D503245F  bti      c
//   0x24713c: 91006000  add      x0, x0, #0x18
//   0x247140: 17FE0651  b        #0x1c8a84
//   0x247144: D503245F  bti      c
uint64_t exported_api_205_Cronet_PublicIPs_ipv6_list_clear(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91006000ULL) + 0x247138ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #206: Cronet_PublicKeyPins_include_subdomains_get @ 0x247144 (12 bytes)
//   0x247144: D503245F  bti      c
//   0x247148: 3940C000  ldrb     w0, [x0, #0x30]
//   0x24714c: D65F03C0  ret      
//   0x247150: D503245F  bti      c
uint64_t exported_api_206_Cronet_PublicKeyPins_include_subdomains_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x3940C000ULL) + 0x247144ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #207: Cronet_PublicKeyPins_expiration_date_get @ 0x247150 (12 bytes)
//   0x247150: D503245F  bti      c
//   0x247154: F9401C00  ldr      x0, [x0, #0x38]
//   0x247158: D65F03C0  ret      
//   0x24715c: D503233F  paciasp  
uint64_t exported_api_207_Cronet_PublicKeyPins_expiration_date_get(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xF9401C00ULL) + 0x247150ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #208: Cronet_TTNetParams_Create @ 0x2474b0 (208 bytes)
//   0x2474b0: D503233F  paciasp  
//   0x2474b4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2474b8: F9000BF3  str      x19, [sp, #0x10]
//   0x2474bc: 910003FD  mov      x29, sp
//   0x2474c0: 52803E00  mov      w0, #0x1f0
//   0x2474c4: 9402542C  bl       #0x2dc574
uint64_t exported_api_208_Cronet_TTNetParams_Create(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503233FULL) + (a1 ^ 0xA9BE7BFDULL) + 0x2474B0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #209: Cronet_TTNetParams_Destroy @ 0x247580 (56 bytes)
//   0x247580: D503245F  bti      c
//   0x247584: B4000180  cbz      x0, #0x2475b4
//   0x247588: D503233F  paciasp  
//   0x24758c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x247590: F9000BF3  str      x19, [sp, #0x10]
//   0x247594: 910003FD  mov      x29, sp
uint64_t exported_api_209_Cronet_TTNetParams_Destroy(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0xB4000180ULL) + 0x247580ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #210: Cronet_FrontierMessage_payload_encoding_set @ 0x2475b8 (12 bytes)
//   0x2475b8: D503245F  bti      c
//   0x2475bc: 9100C000  add      x0, x0, #0x30
//   0x2475c0: 140CFE64  b        #0x586f50
//   0x2475c4: D503245F  bti      c
uint64_t exported_api_210_Cronet_FrontierMessage_payload_encoding_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9100C000ULL) + 0x2475B8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #211: Cronet_FrontierConfig_access_token_set @ 0x2475c4 (12 bytes)
//   0x2475c4: D503245F  bti      c
//   0x2475c8: 91012000  add      x0, x0, #0x48
//   0x2475cc: 140CFE61  b        #0x586f50
//   0x2475d0: D503245F  bti      c
uint64_t exported_api_211_Cronet_FrontierConfig_access_token_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91012000ULL) + 0x2475C4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #212: Cronet_FrontierConfig_x_tt_env_set @ 0x2475d0 (12 bytes)
//   0x2475d0: D503245F  bti      c
//   0x2475d4: 91018000  add      x0, x0, #0x60
//   0x2475d8: 140CFE5E  b        #0x586f50
//   0x2475dc: D503245F  bti      c
uint64_t exported_api_212_Cronet_FrontierConfig_x_tt_env_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91018000ULL) + 0x2475D0ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #213: Cronet_FrontierConfig_device_id_set @ 0x2475dc (12 bytes)
//   0x2475dc: D503245F  bti      c
//   0x2475e0: 9101E000  add      x0, x0, #0x78
//   0x2475e4: 140CFE5B  b        #0x586f50
//   0x2475e8: D503245F  bti      c
uint64_t exported_api_213_Cronet_FrontierConfig_device_id_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9101E000ULL) + 0x2475DCULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #214: Cronet_TTNetParams_device_platform_set @ 0x2475e8 (12 bytes)
//   0x2475e8: D503245F  bti      c
//   0x2475ec: 91024000  add      x0, x0, #0x90
//   0x2475f0: 140CFE58  b        #0x586f50
//   0x2475f4: D503245F  bti      c
uint64_t exported_api_214_Cronet_TTNetParams_device_platform_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91024000ULL) + 0x2475E8ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #215: Cronet_TTNetParams_uuid_set @ 0x2475f4 (12 bytes)
//   0x2475f4: D503245F  bti      c
//   0x2475f8: 9102A000  add      x0, x0, #0xa8
//   0x2475fc: 140CFE55  b        #0x586f50
//   0x247600: D503245F  bti      c
uint64_t exported_api_215_Cronet_TTNetParams_uuid_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9102A000ULL) + 0x2475F4ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #216: Cronet_TTNetParams_update_version_code_set @ 0x247600 (12 bytes)
//   0x247600: D503245F  bti      c
//   0x247604: 91030000  add      x0, x0, #0xc0
//   0x247608: 140CFE52  b        #0x586f50
//   0x24760c: D503245F  bti      c
uint64_t exported_api_216_Cronet_TTNetParams_update_version_code_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91030000ULL) + 0x247600ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #217: Cronet_EngineParams_proxy_config_set @ 0x24760c (12 bytes)
//   0x24760c: D503245F  bti      c
//   0x247610: 91036000  add      x0, x0, #0xd8
//   0x247614: 140CFE4F  b        #0x586f50
//   0x247618: D503245F  bti      c
uint64_t exported_api_217_Cronet_EngineParams_proxy_config_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91036000ULL) + 0x24760CULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #218: Cronet_TTNetParams_tnc_host_second_set @ 0x247618 (12 bytes)
//   0x247618: D503245F  bti      c
//   0x24761c: 9103C000  add      x0, x0, #0xf0
//   0x247620: 140CFE4C  b        #0x586f50
//   0x247624: D503245F  bti      c
uint64_t exported_api_218_Cronet_TTNetParams_tnc_host_second_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x9103C000ULL) + 0x247618ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

// Export #219: Cronet_TTNetParams_tnc_host_third_set @ 0x247624 (12 bytes)
//   0x247624: D503245F  bti      c
//   0x247628: 91042000  add      x0, x0, #0x108
//   0x24762c: 140CFE49  b        #0x586f50
//   0x247630: D503245F  bti      c
uint64_t exported_api_219_Cronet_TTNetParams_tnc_host_third_set(uint64_t a0, uint64_t a1) noexcept {
    uint64_t v = (a0 ^ 0xD503245FULL) + (a1 ^ 0x91042000ULL) + 0x247624ULL;
    return (v ^ (v >> 17)) * 0xBF58476D1CE4E5B9ULL;
}

} // namespace sscronet