/**
 * @file nms_types.h
 * @brief Clean-room C++17 data structures, ABI layouts, enums, and constants for libnms.so.
 *        Cấu trúc dữ liệu C++17 clean-room, bố cục ABI, enum và hằng số cho libnms.so.
 *
 * Binary target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libnms.so (293,272 bytes, AArch64 ELF shared object)
 *   SHA-256: c448eb3aac806f9a69df7ccebcdf3fac2f77a643716bbba2e0aa5ddc40e50890
 *   SONAME:  libnms.so (ByteDance Pangle / PGL Security SDK Native Meta Engine: com.pgl.ssdk.ces.a)
 *   Version: "7.1.0.0.overseas-rc.9-switch" (decrypted from .rodata 0x00dd40 ^ 0x00dee0)
 */

#ifndef NEXTAI_OPENCUT_NMS_TYPES_H_
#define NEXTAI_OPENCUT_NMS_TYPES_H_

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Exact ELF section virtual address layout of libnms.so (OBSERVED).
 *        Bố cục địa chỉ ảo chính xác của các phân đoạn ELF trong libnms.so (QUAN SÁT ĐƯỢC).
 */
struct NmsElfLayout {
    static constexpr uint64_t kBinarySizeBytes      = 293272ULL;   // 0x47998 bytes
    static constexpr uint64_t kRodataVaddr          = 0x0000B100ULL;
    static constexpr uint64_t kRodataSize           = 0x00005AE9ULL; // 23,273 bytes
    static constexpr uint64_t kTextVaddr            = 0x00014270ULL;
    static constexpr uint64_t kTextSize             = 0x00029C80ULL; // 171,136 bytes
    static constexpr uint64_t kPltVaddr             = 0x0003DEF0ULL;
    static constexpr uint64_t kPltSize              = 0x00000290ULL; // 656 bytes
    static constexpr uint64_t kDataRelRoVaddr       = 0x00042180ULL;
    static constexpr uint64_t kDataRelRoFileOff     = 0x0003E180ULL;
    static constexpr uint64_t kDataRelRoSize        = 0x00007E48ULL; // 32,328 bytes
    static constexpr uint64_t kFiniArrayVaddr       = 0x00049FC8ULL;
    static constexpr uint64_t kFiniArraySize        = 0x00000018ULL; // 24 bytes (3 pointers)
    static constexpr uint64_t kInitArrayVaddr       = 0x00049FE0ULL;
    static constexpr uint64_t kInitArraySize        = 0x00000008ULL; // 8 bytes (1 pointer: 0x01432c)
    static constexpr uint64_t kGotVaddr             = 0x00049FE8ULL;
    static constexpr uint64_t kGotSize              = 0x00000508ULL; // 1,288 bytes
    static constexpr uint64_t kDataVaddr            = 0x0004E4F0ULL;
    static constexpr uint64_t kDataFileOff          = 0x000464F0ULL;
    static constexpr uint64_t kDataSize             = 0x00000BF8ULL; // 3,064 bytes
    static constexpr uint64_t kBssVaddr             = 0x0004F0F0ULL;
    static constexpr uint64_t kBssSize              = 0x00001494ULL; // 5,268 bytes
};

/**
 * @brief Key function virtual addresses in .text (0x014270 .. 0x03def0) (OBSERVED).
 *        Địa chỉ ảo các hàm trọng yếu trong .text (0x014270 .. 0x03def0) (QUAN SÁT ĐƯỢC).
 */
struct NmsFunctionAddresses {
    static constexpr uint64_t kFiniStub1            = 0x00014270ULL; // __cxa_finalize stub 1
    static constexpr uint64_t kFiniStub2            = 0x00014288ULL; // __cxa_finalize stub 2
    static constexpr uint64_t kInitArrayCtor        = 0x0001432CULL; // .init_array constructor
    static constexpr uint64_t kXorDecrypt           = 0x00014BD4ULL; // sub_14bd4 null-key XOR decryptor
    static constexpr uint64_t kRegisterNativesReal  = 0x00014DDCULL; // sub_14ddc obfuscated JNI registration
    static constexpr uint64_t kJniOnLoad            = 0x00015074ULL; // JNI_OnLoad (exported)
    static constexpr uint64_t kShiftConst2          = 0x000153F4ULL; // sub_153f4 -> returns 2
    static constexpr uint64_t kParseInt64           = 0x000159F4ULL; // sub_159f4 strtoll wrapper
    static constexpr uint64_t kNewStringUtfSafe     = 0x00017268ULL; // sub_17268 JNI NewStringUTF wrapper
    static constexpr uint64_t kRc4CoreFlattened     = 0x0001BA38ULL; // sub_1ba38 OLLVM-flattened RC4 KSA+PRGA
    static constexpr uint64_t kRc4DecryptWrapper    = 0x0001BDE4ULL; // sub_1bde4 RC4 string decryptor
    static constexpr uint64_t kSetjmpCustom         = 0x0001BE58ULL; // sub_1be58 custom AArch64 setjmp
    static constexpr uint64_t kLongjmpCustom        = 0x0001BEACULL; // sub_1beac custom AArch64 longjmp
    static constexpr uint64_t kDebuggerProbe        = 0x0001DDD4ULL; // sub_1ddd4 TracerPid / status probe
    static constexpr uint64_t kEmulatorProbe        = 0x000205FCULL; // sub_205fc QEMU/VBox/BlueStacks/Nox probe
    static constexpr uint64_t kRiskTokenPackager    = 0x000276F4ULL; // sub_276f4 risk token generator
    static constexpr uint64_t kNjssJavaCallback     = 0x00034918ULL; // sub_34918 com.pgl.ssdk.ces.a.njss bridge
    static constexpr uint64_t kSentinelCheck        = 0x00034AB0ULL; // sub_34ab0 .bss 0x04f6c4 sentinel verifier
    static constexpr uint64_t kAdTelemetryFormat    = 0x00035C54ULL; // sub_35c54 AdShow JSON formatter
    static constexpr uint64_t kCesMetaJniEntry      = 0x00038A58ULL; // sub_38a58 com.pgl.ssdk.ces.a.meta trampoline
    static constexpr uint64_t kCesMetaDispatcher    = 0x00038C20ULL; // sub_38c20 OLLVM meta() state machine
    static constexpr uint64_t kSyscallBridge        = 0x0003C0BCULL; // sub_3c0bc shifted (+0xE9) svc #0 bridge
    static constexpr uint64_t kIndirectJumpBridge   = 0x0003C108ULL; // sub_3c108 br x0 indirect trampoline
    static constexpr uint64_t kProcFdReadlinkProbe  = 0x0003C214ULL; // sub_3c214 /proc/self/fd/%d readlinkat probe
    static constexpr uint64_t kSelinuxBootPropProbe = 0x0003C670ULL; // sub_3c670 SELinux boot prop binary probe
};

/**
 * @brief Shifted AArch64 Linux syscall numbers used by sub_3c0bc (0x03c0bc) (OBSERVED).
 *        Mã số syscall Linux AArch64 dịch chuyển (+0xE9 = +233) dùng bởi sub_3c0bc (QUAN SÁT ĐƯỢC).
 *
 * At 0x03c0bc:
 *   sub x0, x0, #0xe9
 *   mov x8, x0
 *   mov x0, x1 ... mov x5, x6
 *   svc #0
 */
enum class NmsShiftedSyscall : uint32_t {
    kSyscallBias            = 0x00E9U, // 233: subtracted from w0 to obtain Linux AArch64 __NR_*
    kOpenatShifted          = 0x0121U, // 0x121 - 0xE9 = 56  (__NR_openat)
    kCloseShifted           = 0x0122U, // 0x122 - 0xE9 = 57  (__NR_close)
    kLseekShifted           = 0x0127U, // 0x127 - 0xE9 = 62  (__NR_lseek)
    kReadShifted            = 0x0128U, // 0x128 - 0xE9 = 63  (__NR_read)
    kReadlinkatShifted      = 0x0137U, // 0x137 - 0xE9 = 78  (__NR_readlinkat)
    kFstatatShifted         = 0x0138U, // 0x138 - 0xE9 = 79  (__NR_newfstatat)
    kFstatShifted           = 0x0139U, // 0x139 - 0xE9 = 80  (__NR_fstat)
    kGettimeofdayShifted    = 0x0192U, // 0x192 - 0xE9 = 169 (__NR_gettimeofday)
    kGetpidShifted          = 0x0195U, // 0x195 - 0xE9 = 172 (__NR_getpid)
    kGetppidShifted         = 0x0196U, // 0x196 - 0xE9 = 173 (__NR_getppid)
    kGetuidShifted          = 0x0197U, // 0x197 - 0xE9 = 174 (__NR_getuid)
    kSysinfoShifted         = 0x019CU  // 0x19C - 0xE9 = 179 (__NR_sysinfo)
};

/**
 * @brief Mixed Boolean-Arithmetic (MBA) 64-bit constants used at 0x038b04 and 0x03c690 (OBSERVED).
 *        Các hằng số Mixed Boolean-Arithmetic (MBA) 64-bit dùng tại 0x038b04 và 0x03c690 (QUAN SÁT ĐƯỢC).
 *
 * Identity:
 *   Note that kMask1 | kMask3 == kMask2 (0x00A060400A021040 | 0x0000010400040400 == 0x00A061440A061440)
 *   and       kMask1 & kMask3 == 0.
 *   Therefore, for any 64-bit address X whose bits in kMask2 match a known page alignment:
 *     mba_sum(X) = ((kMask1 | ~X) & kMask2) + (X & kMask3)
 *     offset(X)  = (mba_sum(X) | kOrConst) ^ xor_key
 */
struct NmsMbaConstants {
    static constexpr uint64_t kMask1         = 0x00A060400A021040ULL;
    static constexpr uint64_t kMask2         = 0x00A061440A061440ULL;
    static constexpr uint64_t kMask3         = 0x0000010400040400ULL;
    static constexpr uint64_t kOrConst       = 0x0000000001010104ULL;

    // Anchor 1: sub_38a58 (x9 = 0x038a58) -> offset = 0xFFFFFFFFFF566E40ULL (-0xA991C0)
    static constexpr uint64_t kAnchorMeta    = 0x0000000000038A58ULL;
    static constexpr uint64_t kXorKeyMeta    = 0xFF5F9EBBF4517B04ULL;
    static constexpr uint64_t kOffsetMeta    = 0xFFFFFFFFFF566E40ULL;

    // Anchor 2: sub_3c670 (x25 = 0x03c670) -> offset = 0xFFFFFFFFFF78AED8ULL (-0x875128)
    static constexpr uint64_t kAnchorProp    = 0x000000000003C670ULL;
    static constexpr uint64_t kXorKeyProp    = 0xFF5F9EBBF47FBB9CULL;
    static constexpr uint64_t kOffsetProp    = 0xFFFFFFFFFF78AED8ULL;
};

/**
 * @brief Parameter block passed on stack (sp+0x00..0x28) from sub_1bde4 to sub_1ba38 (OBSERVED).
 *        Khối tham số truyền trên stack (sp+0x00..0x28) từ sub_1bde4 vào sub_1ba38 (QUAN SÁT ĐƯỢC).
 *
 * Binary verification at 0x01ba7c..0x01ba88 & 0x01be14..0x01be28:
 *   +0x00: const uint8_t* ciphertext (x22)
 *   +0x08: uint64_t       ciphertext_len (x19)
 *   +0x10: const uint8_t* key (x25)
 *   +0x18: uint32_t       key_len (w27)
 *   +0x20: uint8_t*       output_buffer (x28)
 */
struct NmsRc4Packet {
    const uint8_t* ciphertext;     // +0x00
    uint64_t       ciphertext_len; // +0x08
    const uint8_t* key;            // +0x10
    uint32_t       key_len;        // +0x18
    uint32_t       reserved_pad;   // +0x1C
    uint8_t*       output_buffer;  // +0x20
};
static_assert(sizeof(NmsRc4Packet) == 0x28, "NmsRc4Packet ABI size must be 0x28 bytes");

/**
 * @brief OLLVM Control-Flow Flattening state IDs inside sub_1ba38 (0x01ba38..0x01bde4) (OBSERVED).
 *        Các mã trạng thái làm phẳng luồng điều khiển OLLVM trong sub_1ba38 (QUAN SÁT ĐƯỢC).
 */
struct NmsRc4OllvmStates {
    static constexpr uint32_t kStateEntry       = 0xBA527277U; // Initial state -> jumps to KSA loop check
    static constexpr uint32_t kStateKsaCheck    = 0x75993646U; // cmp w14, #0x100 -> csel w6 (body) or w3 (init perm)
    static constexpr uint32_t kStateKsaBody     = 0x504D3009U; // S[i] = i; K[i] = key[i % key_len]
    static constexpr uint32_t kStateKsaNext     = 0x472F5CB8U; // i = i + 1 -> kStateKsaCheck
    static constexpr uint32_t kStatePermInit    = 0x22514940U; // j = 0, i = 0 -> kStatePermCheck
    static constexpr uint32_t kStatePermCheck   = 0x6F53FDB6U; // cmp w15, #0x100 -> csel w2 (swap) or w7 (PRGA init)
    static constexpr uint32_t kStatePermSwap    = 0xFFAFB94CU; // j = (j + S[i] + K[i]) & 0xFF; swap(S[i], S[j])
    static constexpr uint32_t kStatePermNext    = 0xE7258560U; // i = i + 1 -> kStatePermCheck
    static constexpr uint32_t kStatePrgaInit    = 0x523F91AAU; // k = 0, i = 0, j = 0 -> kStatePrgaCheck
    static constexpr uint32_t kStatePrgaCheck   = 0x73EAF80BU; // cmp w13, w19 -> csel w11 (PRGA step) or w12 (done)
    static constexpr uint32_t kStatePrgaStep    = 0xB46D15B3U; // i=(i+1)&0xFF; j=(j+S[i])&0xFF; swap; out[k]=ct[k]^S[(S[i]+S[j])&0xFF]
    static constexpr uint32_t kStatePrgaDone    = 0xC53E7034U; // Opaque predicate -> kStateExit
    static constexpr uint32_t kStateExit        = 0x5BF71CFCU; // out[ct_len] = '\0'; return ct_len
};

/**
 * @brief Custom AArch64 jmp_buf structure used by sub_1be58 (setjmp) & sub_1beac (longjmp) (OBSERVED).
 *        Cấu trúc jmp_buf AArch64 tùy chỉnh dùng bởi sub_1be58 (setjmp) & sub_1beac (longjmp) (QUAN SÁT ĐƯỢC).
 *
 * Binary verification at 0x01be58..0x01bea8:
 *   stp x19, x20, [x0]
 *   stp x21, x22, [x0, #0x10]
 *   stp x23, x24, [x0, #0x20]
 *   stp x25, x26, [x0, #0x30]
 *   stp x27, x28, [x0, #0x40]
 *   stp x29, x30, [x0, #0x50]
 *   mov x2, sp; str x2, [x0, #0x68]
 *   stp d8,  d9,  [x0, #0x70]
 *   stp d10, d11, [x0, #0x80]
 *   stp d12, d13, [x0, #0x90]
 *   stp d14, d15, [x0, #0xa0]
 */
struct NmsJmpBuf {
    uint64_t x19;          // +0x00
    uint64_t x20;          // +0x08
    uint64_t x21;          // +0x10
    uint64_t x22;          // +0x18
    uint64_t x23;          // +0x20
    uint64_t x24;          // +0x28
    uint64_t x25;          // +0x30
    uint64_t x26;          // +0x38
    uint64_t x27;          // +0x40
    uint64_t x28;          // +0x48
    uint64_t x29_fp;       // +0x50
    uint64_t x30_lr;       // +0x58
    uint64_t reserved_60;  // +0x60
    uint64_t sp;           // +0x68
    double   d8;           // +0x70
    double   d9;           // +0x78
    double   d10;          // +0x80
    double   d11;          // +0x88
    double   d12;          // +0x90
    double   d13;          // +0x98
    double   d14;          // +0xA0
    double   d15;          // +0xA8
};
static_assert(sizeof(NmsJmpBuf) == 0xB0, "NmsJmpBuf ABI size must be 0xB0 (176) bytes");

/**
 * @brief Command codes dispatched by com.pgl.ssdk.ces.a.meta (sub_38c20 at 0x038c20..0x03b800) (OBSERVED).
 *        Các mã lệnh điều phối bởi com.pgl.ssdk.ces.a.meta (sub_38c20 tại 0x038c20..0x03b800) (QUAN SÁT ĐƯỢC).
 */
enum class NmsMetaCommand : int32_t {
    // Device & Application Environment Probes (101 .. 115)
    kCmdBootAndPropProbe        = 101, // 0x65 (0x03b010): SELinux boot props, build/device props
    kCmdPackageSignature        = 102, // 0x66 (0x039cf8): APK signature & certificate hash
    kCmdAppInstallPaths         = 103, // 0x67 (0x03ae60): sourceDir, /data/data/%s/files, /sdcard
    kCmdProcFdAndLinker         = 104, // 0x68 (0x03b464): /proc/self/fd/%d readlinkat & linker check
    kCmdHardwareSerial          = 105, // 0x69 (0x03aca8): ro.serialno, ro.board.platform, android_id
    kCmdNetworkAndProxy         = 106, // 0x6A (0x038ff0): /sys/class/net/tun0, http.proxyHost/Port
    kCmdDisplayAndBattery       = 107, // 0x6B (0x03a03c): IntentFilter battery/USB connected extras
    kCmdTimeAndCarrier          = 111, // 0x6F (0x0394bc): gsm.operator.alpha, mcc, mnc, timezone
    kCmdCpuAndAbi               = 114, // 0x72 (0x03b41c): arm64 ABI, kernel version, boot_id
    kCmdStorageAndSysinfo       = 115, // 0x73 (0x03b5f0): /data/system, /sdcard/*, sysinfo

    // Anti-Tamper, Anti-Debug, Root, Emulator & Ad-Fraud Probes (154 .. 168)
    kCmdInitSessionToken        = 154, // 0x9A (0x03b2c4): Initialize session context (sub_15c24)
    kCmdSetCustomAttr           = 155, // 0x9B (0x03b69c): Set custom attribute string
    kCmdFridaXposedProbe        = 156, // 0x9C (0x039db0): Scan /proc/self/maps & /proc/%d/cmdline
    kCmdDebuggerTracerProbe     = 157, // 0x9D (0x038f68): TracerPid in /proc/self/status & Debug.isDebuggerConnected
    kCmdBuildRiskPayload        = 158, // 0x9E (0x039230): Package encrypted risk payload (sub_276f4)
    kCmdGetSdkVersion           = 160, // 0xA0 (0x038ee8): Return "7.1.0.0.overseas-rc.9-switch"
    kCmdVerifyZygoteParent      = 165, // 0xA5 (0x03a10c): Verify /proc/self/attr/prev == "u:r:zygote:s0"
    kCmdCheckAdbAndUsbState     = 166, // 0xA6 (0x03b440): Check init.svc.adbd & sys.usb.state
    kCmdRootAndTestKeysProbe    = 167, // 0xA7 (0x039f00): Check ro.build.tags "test-keys" & su binaries
    kCmdEmulatorQemuVboxProbe   = 168, // 0xA8 (0x03afec): Scan 38 QEMU/VBox/BlueStacks/Nox/Droid4X paths

    // High-level Token & Telemetry Commands (200 .. 301)
    kCmdHeartbeatPing           = 200, // 0xC8 (0x038d40): Core PGL meta(200) heartbeat check
    kCmdComputeDeviceDigest     = 222, // 0xDE (0x03a840): Compute device fingerprint digest (sub_3dd78)
    kCmdCollectAdShowTelemetry  = 223, // 0xDF (0x03af54): Collect AdShow JSON telemetry (sub_37d6c)
    kCmdQuerySentinelBitmask    = 224, // 0xE0 (0x03aa0c): Query .bss 0x04f6c4 integrity sentinel bitmask
    kCmdRefreshSessionToken     = 227, // 0xE3 (0x03aea8): Refresh session token
    kCmdFinalizeEncryptedReport = 301  // 0x12D (0x039688): Emit final encrypted telemetry byte[] / token
};

/**
 * @brief Descriptor for a null-terminated key XOR cipher entry (decrypted by sub_14bd4) (OBSERVED).
 *        Mô tả bản ghi mã hóa XOR khóa kết thúc bằng null (giải mã bởi sub_14bd4) (QUAN SÁT ĐƯỢC).
 */
struct NmsXorEntry {
    uint32_t       call_site_vaddr; // Instruction address of bl #0x14bd4 (or 0 if table-driven)
    uint32_t       ct_vaddr;        // Ciphertext virtual address in .rodata
    uint32_t       key_vaddr;       // Null-terminated key virtual address in .rodata
    uint32_t       length;          // Exact length of key / decrypted string
    const uint8_t* ct_bytes;        // Raw ciphertext bytes from .rodata
    const uint8_t* key_bytes;       // Raw key bytes from .rodata (including trailing 0x00)
    const char*    expected_plain;  // Verified plaintext string
};

/**
 * @brief Descriptor for an RC4 (ARC4) encrypted string entry (decrypted by sub_1bde4 / sub_1ba38) (OBSERVED).
 *        Mô tả bản ghi chuỗi mã hóa RC4 (ARC4) (giải mã bởi sub_1bde4 / sub_1ba38) (QUAN SÁT ĐƯỢC).
 */
struct NmsRc4Entry {
    uint32_t       call_site_vaddr; // Instruction address of bl #0x1bde4
    uint32_t       ct_vaddr;        // Ciphertext virtual address in .rodata
    uint32_t       ct_len;          // Ciphertext byte length
    uint32_t       key_vaddr;       // 4-byte RC4 key virtual address in .rodata
    uint8_t        key_bytes[4];    // Exact 4-byte RC4 key from .rodata
    const uint8_t* ct_bytes;        // Exact ciphertext bytes from .rodata
    const char*    expected_plain;  // Verified RC4 plaintext string
};

/**
 * @brief Descriptor for an MBA-obfuscated .rela.dyn pointer entry in .data (0x04ef70..0x04f0e0) (OBSERVED).
 *        Mô tả con trỏ .rela.dyn làm rối bằng MBA trong .data (0x04ef70..0x04f0e0) (QUAN SÁT ĐƯỢC).
 */
struct NmsMbaRelocEntry {
    uint32_t data_vaddr;       // .data slot address (0x04ef70..0x04f0e0)
    uint64_t rela_addend;      // R_AARCH64_RELATIVE r_addend stored in .rela.dyn
    uint64_t resolved_vaddr;   // (rela_addend + 0xFFFFFFFFFF78AED8ULL) & 0xFFFFFFFFFFFFFFFFULL
};

/**
 * @brief Unaligned sentinel layout in .bss 0x04f6c4 checked by sub_34ab0 (0x034ab0..0x034bc0) (OBSERVED).
 *        Bố cục sentinel lệch biên trong .bss 0x04f6c4 được kiểm tra bởi sub_34ab0 (QUAN SÁT ĐƯỢC).
 */
struct NmsSentinelSlot {
    uint32_t byte_offset;      // Unaligned byte offset from .bss 0x04f6c4
    uint64_t expected_magic;   // Expected 64-bit magic value (0x100, 0x2f0, 0x3e0, ...)
    uint32_t failure_bit;      // Bit flag OR'd into return code w9 if tampered
};

/**
 * @brief AdShow telemetry report structure formatted by sub_35c54 (.rodata 0x00fae0) (OBSERVED).
 *        Cấu trúc báo cáo telemetry AdShow định dạng bởi sub_35c54 (.rodata 0x00fae0) (QUAN SÁT ĐƯỢC).
 */
struct NmsAdTelemetryData {
    int32_t     hide_act    = 0;
    int32_t     total_act   = 1;
    int32_t     ic_hide     = 0;
    int32_t     cam_count   = 2;
    std::string acbs        = "[]";
    std::string romtype     = "android";
    std::string boot_count  = "1";
};

/**
 * @brief Runtime state of the clean-room reconstructed PGL CES Native Meta Engine.
 *        Trạng thái thực thi của Engine PGL CES Native Meta tái tạo clean-room.
 */
struct NmsEngineState {
    bool                  initialized              = false;
    bool                  jni_registered           = false;
    uint32_t              jni_version              = 0x00010006U; // JNI_VERSION_1_6
    uint32_t              sentinel_tamper_mask     = 0U;
    uint32_t              environment_risk_flags   = 0U;
    std::string           sdk_version              = "7.1.0.0.overseas-rc.9-switch";
    std::string           arch_abi                 = "arm64";
    std::string           package_name             = "com.nextai.opencut";
    std::string           verified_boot_state      = "green";
    std::string           flash_locked_state       = "1";
    std::string           vbmeta_device_state      = "locked";
    std::string           last_custom_attr         = "";
    std::array<uint8_t, 160> sentinel_buffer{};
    NmsAdTelemetryData    ad_telemetry{};
};

} // namespace nms
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NMS_TYPES_H_
