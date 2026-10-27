/**
 * @file godzilla_sysopt_types.h
 * @brief Clean-Room ABI Structs, Constants, Opaque Predicates & Types for libgodzilla-sysopt.so.
 *        Các cấu trúc ABI, hằng số, vị từ mờ (opaque predicates) và kiểu dữ liệu cho libgodzilla-sysopt.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Size / Dung lượng: 164,440 bytes
 *   SHA-256: 28605f81e2c8d9d0fae96d52a70efc5192c90d93377ddadff09726874911d704
 *   Sections / Các phân đoạn ELF:
 *     - .rodata      : VMA 0x003ec0..0x0059a8 (6,888 bytes)
 *     - .text        : VMA 0x007ce0..0x026980 (126,112 bytes)
 *     - .data.rel.ro : VMA 0x02af20..0x02b290 (file offset 0x026f20, 880 bytes)
 *     - .init_array  : VMA 0x02b290..0x02b298 (file offset 0x027290, 8 bytes -> 0x0082ec)
 *     - .data        : VMA 0x02f7c8..0x02f9c8 (file offset 0x0277c8, 512 bytes)
 *     - .bss         : VMA 0x02f9c8..0x0304a0 (2,776 bytes)
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   [OBSERVED] Directly verified from AArch64 machine code & .rodata/.data bytes of libgodzilla-sysopt.so.
 *              Được kiểm chứng trực tiếp từ mã máy AArch64 và byte .rodata/.data của libgodzilla-sysopt.so.
 */

#ifndef NEXTAI_OPENCUT_GODZILLA_SYSOPT_TYPES_H_
#define NEXTAI_OPENCUT_GODZILLA_SYSOPT_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

/**
 * @brief Binary & Section Constants [OBSERVED]
 *        Các hằng số nhị phân và phân đoạn ELF [QUAN SÁT ĐƯỢC]
 */
constexpr uint32_t kBinarySizeBytes          = 164440U;
constexpr uint64_t kRodataVmaStart           = 0x003ec0ULL;
constexpr uint64_t kRodataVmaEnd             = 0x0059a8ULL;
constexpr uint64_t kTextVmaStart             = 0x007ce0ULL;
constexpr uint64_t kTextVmaEnd               = 0x026980ULL;
constexpr uint64_t kInitArrayVma             = 0x02b290ULL;
constexpr uint64_t kInitArrayEntryVma        = 0x0082ecULL;
constexpr uint64_t kDataVmaStart             = 0x02f7c8ULL;
constexpr uint64_t kDataFileOffset           = 0x0277c8ULL;
constexpr uint64_t kBssVmaStart              = 0x02f9c8ULL;
constexpr uint64_t kBssVmaEnd                = 0x0304a0ULL;

/**
 * @brief System Optimization & Hook Constants [OBSERVED]
 *        Các hằng số tối ưu hệ thống và hook [QUAN SÁT ĐƯỢC]
 *
 * - kDefaultPthreadStackSize: .data 0x02f7c8 (file offset 0x0277c8) = 0x00083000 (536,576 bytes = 524 KB).
 *   Loaded at 0x00824c (`ldr w1, [x8, #0x7c8]`) and 0x008278 (`ldr w3, [x8, #0x7c8]`).
 * - kSysconfPageSizeCode: `_SC_PAGESIZE` = 0x28 (40) on Android Bionic, passed to `sysconf(0x28)` at 0x0082f4.
 * - kElfMaxSectionHeaders: `cmp w20, #0x41` at 0x007e64 (maximum 64 section headers allowed).
 * - kElfNoteSectionType: `SHT_NOTE` = 7 (`cmp w8, #7` at 0x007ec4).
 * - kElfMaxBuildIdDescBytes: `cmp x8, #0x40` at 0x007fd8 (1..64 bytes of raw Build-ID digest).
 * - kSigbusSignalNumber: `SIGBUS` = 7 (`mov w0, #7` at 0x00aaa0).
 * - kSigbusActionFlags: `SA_SIGINFO | SA_ONSTACK | SA_RESTART` = 0x18000004 (`mov w8, #0x18000000; movk w8, #4` at 0x00aa88..0x00aa94).
 * - kSigbusAdrErrCode: `BUS_ADRERR` = 2 (`ldr w8, [x1, #8]; cmp w8, #2` at 0x00ab00..0x00ab04).
 * - kSigbusMaxRetryCount: 3 (`cmp x0, #3` at 0x00aba4).
 * - kVmaAbove39BitsMask: `0xffffff8000000000ULL` (`and x9, x9, #0xffffff8000000000; bfxil x9, x8, #0x27, #0x19` at 0x01a448..0x01a450).
 */
constexpr uint32_t kDefaultPthreadStackSize  = 0x00083000U;
constexpr int32_t  kSysconfPageSizeCode      = 0x28;
constexpr uint32_t kElfOpenCloexecFlags      = 0x00080000U;
constexpr uint32_t kElfMaxSectionHeaders     = 0x41U;
constexpr uint32_t kElfNoteSectionType       = 7U;
constexpr uint32_t kElfMaxBuildIdDescBytes   = 0x40U;
constexpr int32_t  kSigbusSignalNumber       = 7;
constexpr uint32_t kSigbusActionFlags        = 0x18000004U;
constexpr int32_t  kSigbusAdrErrCode         = 2;
constexpr uint64_t kSigbusMaxRetryCount      = 3ULL;
constexpr uint64_t kVmaAbove39BitsMask       = 0xFFFFFF8000000000ULL;

/**
 * @brief AArch64 Direct Linux Syscall Numbers [OBSERVED at 0x01579c..0x0178b0]
 *        Số hiệu syscall Linux AArch64 trực tiếp [QUAN SÁT ĐƯỢC tại 0x01579c..0x0178b0]
 *
 * Invoked via `rawSyscall4` (`0x017878`: `mov x8, x0; svc #0` at `0x01789c`):
 *   - `__NR_openat` = 56  (`0x38`, `mov w0, #0x38; mov w1, #-0x64` (`AT_FDCWD = -100`) at 0x015984..0x015988)
 *   - `__NR_close`  = 57  (`0x39`, `mov w0, #0x39` at 0x015df8, 0x016100)
 *   - `__NR_lseek`  = 62  (`0x3e`, `mov w0, #0x3e; mov w3, #2` (`SEEK_END = 2`) at 0x015ce0..0x015ce4)
 *   - `__NR_read`   = 63  (`0x3f`, `mov w0, #0x3f` at 0x016bf4)
 */
constexpr int64_t kSysNrOpenat               = 56;
constexpr int64_t kSysNrClose                = 57;
constexpr int64_t kSysNrLseek                = 62;
constexpr int64_t kSysNrRead                 = 63;
constexpr int64_t kAtFdcwd                   = -100;

/**
 * @brief ZIP / APK Archive & PKCS#7 ASN.1 Constants [OBSERVED at 0x00afcc..0x0189d8]
 *        Hằng số định dạng ZIP / APK và chữ ký PKCS#7 ASN.1 [QUAN SÁT ĐƯỢC tại 0x00afcc..0x0189d8]
 *
 * - kZipEocdSignature: `0x06054b50` (`PK\x05\x06`, checked at 0x00c1ec).
 * - kZipCdFileHeaderSig: `0x02014b50` (`PK\x01\x02`, checked at 0x00d9e0).
 * - kZipLocalFileHeaderSig: `0x04034b50` (`PK\x03\x04`, checked at 0x00f85c).
 * - kZipMaxTailReadSize: `0x10016` (65,558 bytes = 64 KB comment + 22-byte EOCD, checked at 0x00b6c0).
 * - kZipCompressionStored: `0` (uncompressed), `kZipCompressionDeflated`: `8` (zlib `inflateInit2_(-15)` with version `"1.2.8"` @ 0x00465a).
 */
constexpr uint32_t kZipEocdSignature         = 0x06054B50U;
constexpr uint32_t kZipCdFileHeaderSig       = 0x02014B50U;
constexpr uint32_t kZipLocalFileHeaderSig    = 0x04034B50U;
constexpr size_t   kZipEocdMinSize           = 22U;
constexpr size_t   kZipMaxTailReadSize       = 0x10016U;
constexpr uint16_t kZipCompressionStored     = 0U;
constexpr uint16_t kZipCompressionDeflated   = 8U;

/**
 * @brief OLLVM / Tigress Opaque Predicate Parameter Block [OBSERVED at .data 0x02f7cc..0x02f9b0]
 *        Khối tham số vị từ mờ OLLVM / Tigress [QUAN SÁT ĐƯỢC tại .data 0x02f7cc..0x02f9b0]
 *
 * Every function in the APK SHA-256 and Maps Hook Scanner modules references a 20-byte
 * parameter block in `.data` (e.g., `0x02f988` in `ApkSha256_checkMyShit`, `0x02f99c` in `scanMapsForHookFrameworks`):
 *   - `p0` (+0x00): `9`
 *   - `p1` (+0x04): `8`
 *   - `p2` (+0x08): `1`
 *   - `p3` (+0x0c): `7`
 *   - `p4` (+0x10): `3`
 *
 * Two mathematical invariants are evaluated throughout the binary:
 *   1. Integer quotient invariant:
 *      `q = ((p0 + 7) / p1) - p2 = ((9 + 7) / 8) - 1 = 2 - 1 = 1`
 *   2. Floating-point FMA invariant (`fmadd d0, d1, d2, d0` with `d2 = -2.0`):
 *      `f = (double(p4) * (-2.0) + double(p3)) * double(q) = (3.0 * (-2.0) + 7.0) * 1.0 = 1.0`
 */
struct OpaquePredicateBlock {
    uint32_t p0;  // +0x00: 9
    uint32_t p1;  // +0x04: 8
    uint32_t p2;  // +0x08: 1
    uint32_t p3;  // +0x0c: 7
    uint32_t p4;  // +0x10: 3

    /**
     * @brief Evaluates `((p0 + 7) / p1) - p2` (`add w8, w8, #7; udiv w8, w8, w9; sub w8, w8, w10`).
     *        Tính biểu thức nguyên `((p0 + 7) / p1) - p2` (luôn bằng 1).
     */
    constexpr int32_t EvaluateIntQuotientDelta() const noexcept {
        return (p1 != 0U) ? static_cast<int32_t>((p0 + 7U) / p1) - static_cast<int32_t>(p2) : 0;
    }

    /**
     * @brief Evaluates `(double(p4) * (-2.0) + double(p3)) * double(EvaluateIntQuotientDelta())`.
     *        Tính biểu thức dấu phẩy động FMA `(p4 * (-2.0) + p3) * q` (luôn bằng 1.0).
     */
    constexpr double EvaluateFmaScale() const noexcept {
        const double d0 = static_cast<double>(p3);
        const double d1 = static_cast<double>(p4);
        const double fma = (d1 * (-2.0)) + d0;
        return fma * static_cast<double>(EvaluateIntQuotientDelta());
    }
};

constexpr OpaquePredicateBlock kDefaultOpaquePredicateBlock = {9U, 8U, 1U, 7U, 3U};

/**
 * @brief Mixed Boolean-Arithmetic (MBA) Rolling XOR Deobfuscator [OBSERVED at 0x01b210..0x01b248]
 *        Bộ giải mã XOR trượt dùng đồng nhất thức MBA [QUAN SÁT ĐƯỢC tại 0x01b210..0x01b248]
 *
 * At 0x01b238..0x01b244:
 *   `and w2, w3, w2`           // w2 = key & enc_byte
 *   `add w0, w1, w0`           // w0 = enc_byte + key
 *   `sub w0, w0, w2, lsl #1`   // w0 = (enc_byte + key) - 2 * (enc_byte & key) == enc_byte ^ key
 *
 * Where `key = (base_key + index) & 0xFF` computed via floating-point FMA scale!
 */
inline constexpr uint8_t MbaXorByte(uint8_t enc_byte, uint8_t key_byte) noexcept {
    const uint32_t sum = static_cast<uint32_t>(enc_byte) + static_cast<uint32_t>(key_byte);
    const uint32_t band = static_cast<uint32_t>(enc_byte) & static_cast<uint32_t>(key_byte);
    return static_cast<uint8_t>((sum - (band << 1U)) & 0xFFU);
}

/**
 * @brief ELF64 Header & Section/Note Headers [OBSERVED at 0x007d30..0x008060]
 *        Cấu trúc ELF64 Header, Section Header và Note Header [QUAN SÁT ĐƯỢC tại 0x007d30..0x008060]
 */
#pragma pack(push, 1)
struct Elf64Ehdr {
    uint8_t  e_ident[16];     // +0x00: ELF magic "\x7fELF"
    uint16_t e_type;          // +0x10
    uint16_t e_machine;       // +0x12
    uint32_t e_version;       // +0x14
    uint64_t e_entry;         // +0x18
    uint64_t e_phoff;         // +0x20
    uint64_t e_shoff;         // +0x28: Loaded via `ldr x2, [sp, #0x88]` at 0x007e6c
    uint32_t e_flags;         // +0x30
    uint16_t e_ehsize;        // +0x34
    uint16_t e_phentsize;     // +0x36
    uint16_t e_phnum;         // +0x38
    uint16_t e_shentsize;     // +0x3a
    uint16_t e_shnum;         // +0x3c: Loaded via `ldrh w20, [sp, #0x9c]` at 0x007e60
    uint16_t e_shstrndx;      // +0x3e: Loaded via `ldrh w8, [sp, #0x9e]` at 0x007e8c
};
static_assert(sizeof(Elf64Ehdr) == 64, "Elf64Ehdr must be 64 bytes");

struct Elf64Shdr {
    uint32_t sh_name;         // +0x00: Offset into .shstrtab
    uint32_t sh_type;         // +0x04: SHT_NOTE == 7
    uint64_t sh_flags;        // +0x08
    uint64_t sh_addr;         // +0x10
    uint64_t sh_offset;       // +0x18: File offset of section
    uint64_t sh_size;         // +0x20: Section byte size
    uint32_t sh_link;         // +0x28
    uint32_t sh_info;         // +0x2c
    uint64_t sh_addralign;    // +0x30
    uint64_t sh_entsize;      // +0x38
};
static_assert(sizeof(Elf64Shdr) == 64, "Elf64Shdr must be 64 bytes");

struct Elf64Nhdr {
    uint32_t n_namesz;        // +0x00: Length of note name ("GNU\0" = 4)
    uint32_t n_descsz;        // +0x04: Length of build-id hash (1..64 bytes)
    uint32_t n_type;          // +0x08: NT_GNU_BUILD_ID (3)
};
static_assert(sizeof(Elf64Nhdr) == 12, "Elf64Nhdr must be 12 bytes");
#pragma pack(pop)

/**
 * @brief xHook Registration Rule Node [OBSERVED at 0x008344..0x008454]
 *        Nút quy tắc đăng ký PLT/GOT hook của xHook [QUAN SÁT ĐƯỢC tại 0x008344..0x008454]
 */
struct XHookRuleEntry {
    std::string pathname_regex_str;  // e.g. "libart.so" (0x004502)
    std::string symbol_name;         // e.g. "pthread_attr_setstacksize" (0x004ab7)
    void*       new_func;            // e.g. 0x008248 (hook_pthread_attr_setstacksize)
    void**      old_func;            // nullptr
};

/**
 * @brief Indirect Function Pointer Dispatch Table in `.data` [OBSERVED at 0x02f818..0x02f940]
 *        Bảng con trỏ hàm gián tiếp trong `.data` [QUAN SÁT ĐƯỢC tại 0x02f818..0x02f940]
 *
 * Used by `ApkSha256_checkMyShit`, `ApkSha256_checkHookFrameworks`, and `extractApkCertAndCalculateSha256`
 * to obfuscate direct call edges:
 *   - `.data 0x02f818` -> `0x00abdc` (`calculateSHA256FromCert`)
 *   - `.data 0x02f8a0` -> `0x0141ec` (`findApkPathFromMaps`)
 *   - `.data 0x02f900` -> `0x00afcc` (`extractApkCertAndCalculateSha256`)
 *   - `.data 0x02f940` -> `0x019fb4` (`scanMapsForHookFrameworks`)
 */
struct GodzillaSysoptDispatchTable {
    std::string (*calculate_sha256_from_cert)(const uint8_t* data, size_t len);
    std::string (*find_apk_path_from_maps)(const std::string& package_hint);
    std::string (*extract_apk_cert_and_sha256)(const char* apk_path);
    std::string (*scan_maps_for_hook_frameworks)();
};

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_GODZILLA_SYSOPT_TYPES_H_
