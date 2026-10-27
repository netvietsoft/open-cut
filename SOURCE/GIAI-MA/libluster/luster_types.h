/**
 * @file luster_types.h
 * @brief Clean-Room C++17 ABI Structures, Constants, and Mathematical Proofs for libluster.so
 *        Cấu trúc ABI C++17, Hằng số và Chứng minh Toán học cho libluster.so (ByteDance Cloak / Terrain VM Bridge)
 *
 * Binary Forensics / Thông số Nhị phân:
 *   - Library / Thư viện         : libluster.so (TASK_SO_118_libluster / TASK-127)
 *   - File Size / Dung lượng     : 250,720 bytes (0x3D360)
 *   - SHA-256                    : 18d0ecc52de2a8eb93a63bda59bbba1d179c92c7c56b342bfc01ed4866ab52d4
 *   - Architecture / Kiến trúc   : AArch64 (ARM64-v8a), Little-Endian, Android NDK r21d (6352462)
 *   - DT_NEEDED                  : libterrain.so, liblog.so, libm.so, libdl.so, libc.so
 *   - ELF Sections / Các phân đoạn:
 *       .text        : vaddr 0x003590, file 0x003590, size 0x13240 (78,400 bytes)
 *       .rodata      : vaddr 0x0167d0, file 0x0167d0, size 0x1feee (130,798 bytes)
 *       .data.rel.ro : vaddr 0x03f730, file 0x03b730, size 0x00628 (1,576 bytes)
 *       .data        : vaddr 0x040000, file 0x03c000, size 0x00b28 (2,856 bytes)
 *       .bss         : vaddr 0x040b30, file 0x03cb28, size 0x05c20 (23,584 bytes)
 */

#ifndef NEXTAI_OPENCUT_LUSTER_TYPES_H_
#define NEXTAI_OPENCUT_LUSTER_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <mutex>

// Minimal JNI type definitions when compiling outside Android NDK
// Định nghĩa kiểu JNI tối thiểu khi biên dịch độc lập ngoài Android NDK
#ifndef JNI_VERSION_1_6
#define JNI_VERSION_1_6 0x00010006
#define JNI_OK          0
#define JNI_ERR         (-1)
#define JNI_FALSE       0
#define JNI_TRUE        1
#endif

using jboolean = uint8_t;
using jbyte    = int8_t;
using jchar    = uint16_t;
using jshort   = int16_t;
using jint     = int32_t;
using jlong    = int64_t;
using jfloat   = float;
using jdouble  = double;
using jsize    = jint;

struct _jobject;
struct _jclass;
struct _jstring;
struct _jthrowable;
struct _jfieldID;
struct _jmethodID;

using jobject    = _jobject*;
using jclass     = _jclass*;
using jstring    = _jstring*;
using jthrowable = _jthrowable*;
using jfieldID   = _jfieldID*;
using jmethodID  = _jmethodID*;

union jvalue {
    jboolean z;
    jbyte    b;
    jchar    c;
    jshort   s;
    jint     i;
    jlong    j;
    jfloat   f;
    jdouble  d;
    jobject  l;
};

struct JNINativeMethod {
    const char* name;
    const char* signature;
    void*       fnPtr;
};

struct JNINativeInterface;
struct JNIEnv {
    const JNINativeInterface* functions;
};

struct JNIInvokeInterface;
struct JavaVM {
    const JNIInvokeInterface* functions;
};

namespace nextai {
namespace opencut {
namespace luster {

// ============================================================================
// 1. BINARY CONSTANTS & SECTION ADDRESSES
//    HẰNG SỐ NHỊ PHÂN & ĐỊA CHỈ PHÂN ĐOẠN ELF
// ============================================================================

/// Total binary size of libluster.so (250,720 bytes).
/// Tổng kích thước nhị phân của libluster.so (250.720 byte).
constexpr uint32_t kLusterBinarySize = 250720U;

/// Cache slot count passed to cacheInitial(env, 0x272a) at 0x016798.
/// Số lượng khe bộ nhớ đệm truyền vào cacheInitial(env, 0x272a = 10.026) tại 0x016798.
constexpr uint32_t kTerrainCacheSlotCount = 0x272AU; // 10,026

/// Number of protected Java/Kotlin classes registered via EffectUtil (42 classes).
/// Số lượng lớp Java/Kotlin được bảo vệ đăng ký qua EffectUtil (42 lớp tại 0x016814..0x016a0c).
constexpr uint32_t kLusterProtectedClassCount = 42U;

/// Number of virtualized JNI native methods across the 42 classes (93 methods, indices 0..92).
/// Số lượng phương thức gốc JNI được ảo hóa trên 42 lớp (93 phương thức tại 0x03f750..0x03fd18).
constexpr uint32_t kLusterVirtualizedMethodCount = 93U;

/// Number of strings in the .rodata string pool (1,790 strings at 0x016a0c..0x029380).
/// Số lượng chuỗi trong vùng nhớ chuỗi .rodata (1.790 chuỗi, bảng offset tại 0x029380..0x02af78).
constexpr uint32_t kLusterStringPoolCount = 1790U;

/// Number of class ID entries in 0x02af78 and 0x02cd80 (464 entries).
/// Số lượng mục ánh xạ ID lớp tại 0x02af78 và 0x02cd80 (464 mục).
constexpr uint32_t kLusterClassTableCount = 464U;

/// Number of field descriptors in .rodata 0x02b7fc..0x02cd80 (344 descriptors, 459 BSS slots).
/// Số lượng bộ mô tả trường tại .rodata 0x02b7fc..0x02cd80 (344 trường, 459 khe đệm BSS tại 0x040b90).
constexpr uint32_t kLusterFieldDescriptorCount = 344U;
constexpr uint32_t kLusterFieldCacheSlotCount  = 459U;

/// Number of method descriptors in .rodata 0x02d4c0..0x02f9e0 (594 descriptors, 594 BSS slots).
/// Số lượng bộ mô tả phương thức tại .rodata 0x02d4c0..0x02f9e0 (594 phương thức, 594 khe BSS 24B tại 0x042840).
constexpr uint32_t kLusterMethodDescriptorCount = 594U;

/// Number of prototype signature indices in .rodata 0x02f9e0..0x02fea0 (304 entries).
/// Số lượng chỉ mục chữ ký nguyên mẫu tại .rodata 0x02f9e0..0x02fea0 (304 mục).
constexpr uint32_t kLusterProtoSignatureCount = 304U;

/// Number of hot interned strings in .rodata 0x02fea0..0x030210 (220 entries, 212 active in binary search).
/// Số lượng chuỗi interned nóng tại .rodata 0x02fea0..0x030210 (220 khe, tìm kiếm nhị phân 212 mục đầu).
constexpr uint32_t kLusterHotStringTableCapacity = 220U;
constexpr uint32_t kLusterHotStringSearchCount   = 212U;

/// Number of Terrain VM bytecode units referenced in .data 0x040718..0x040a78 (109 units).
/// Số lượng đơn vị mã byte Terrain VM được tham chiếu tại .data 0x040718..0x040a78 (109 đơn vị).
constexpr uint32_t kLusterBytecodeUnitCount = 109U;

// ============================================================================
// 2. MATHEMATICAL PROOF OF ASLR-INVARIANT MBA POINTER DECRYPTION
//    CHỨNG MINH TOÁN HỌC ĐỒNG NHẤT THỨC MBA GIẢI MÃ CON TRỎ BẤT BIẾN VỚI ASLR
// ============================================================================
//
// Observed in sub_3b94 (0x03bb4..0x03c28), sub_4398 (0x043d8..0x04434),
// Method 0..92 (0x051c8..0x05238, 0x05c24..0x05c94), and Helpers 0..6:
//
// Given ANY 64-bit runtime code pointer `pc` (loaded via `adrp + add`):
//   kMaskA = 0x0000010400040400ULL  (x28)
//   kMaskB = 0x00a060400a021040ULL  (x24)
//   kMaskC = 0x00a061440a061440ULL  (x19)
//   kOrImm = 0x0000000001010104ULL  (w21)
//   kXorK  = 0xff5f9ebbf49ce3ecULL  (x26)
//
// Instructions:
//   t1 = (pc & kMaskA) | kOrImm
//   t2 = (kMaskB | ~pc) & kMaskC
//   sum = t2 + t1
//   delta = sum ^ kXorK
//
// Algebraic Proof of ASLR Invariance:
//   1. Notice that kMaskA & kMaskB == 0, and kMaskA | kMaskB == kMaskC!
//      (0x0000010400040400 | 0x00a060400a021040 == 0x00a061440a061440).
//   2. Therefore, by Boolean distributive law:
//      t2 = (kMaskB | ~pc) & (kMaskB | kMaskA)
//         = kMaskB | (~pc & kMaskA)
//         = kMaskB + (~pc & kMaskA)   (since kMaskB & kMaskA == 0).
//   3. Notice also that kMaskA & kOrImm == 0
//      (0x0000010400040400 & 0x0000000001010104 == 0).
//      Hence:
//      t1 = (pc & kMaskA) | kOrImm = (pc & kMaskA) + kOrImm.
//   4. Summing t2 and t1:
//      sum = kMaskB + (~pc & kMaskA) + (pc & kMaskA) + kOrImm
//          = kMaskB + kMaskA + kOrImm
//          = kMaskC + kOrImm
//          = 0x00a061440a061440 + 0x0000000001010104
//          = 0x00a061440b071544ULL   (100% independent of `pc`!).
//   5. XORing with kXorK:
//      delta = 0x00a061440b071544ULL ^ 0xff5f9ebbf49ce3ecULL
//            = 0xffffffffff9bf6a8ULL
//            = -0x640958LL (-6,555,992).
//
// Every R_AARCH64_RELATIVE pointer in .data (0x040000..0x040b20) was shifted
// by +0x640958 at build time. Adding `delta` (-0x640958) via MBA addition:
//   - `(ptr ^ delta) + ((ptr & delta) << 1) == ptr + delta`
//   - `((ptr | delta) << 1) - (ptr ^ delta) == ptr + delta`
// recovers the true virtual address inside .text, .rodata, .data.rel.ro, or .bss!

constexpr uint64_t kLusterMbaMaskA      = 0x0000010400040400ULL;
constexpr uint64_t kLusterMbaMaskB      = 0x00a060400a021040ULL;
constexpr uint64_t kLusterMbaMaskC      = 0x00a061440a061440ULL;
constexpr uint64_t kLusterMbaOrImm      = 0x0000000001010104ULL;
constexpr uint64_t kLusterMbaXorKey     = 0xff5f9ebbf49ce3ecULL;
constexpr uint64_t kLusterPointerDelta  = 0xffffffffff9bf6a8ULL; // -0x640958
constexpr uint64_t kLusterPointerAddend = 0x0000000000640958ULL; // +0x640958

/**
 * @brief Computes the ASLR-invariant MBA pointer delta from any runtime PC.
 *        Tính độ lệch giải mã con trỏ MBA bất biến với ASLR từ mọi địa chỉ PC lúc chạy.
 */
inline constexpr uint64_t ComputeLusterMbaDelta(uint64_t runtime_pc) noexcept {
    const uint64_t t1  = (runtime_pc & kLusterMbaMaskA) | kLusterMbaOrImm;
    const uint64_t t2  = (kLusterMbaMaskB | ~runtime_pc) & kLusterMbaMaskC;
    const uint64_t sum = t2 + t1;
    return sum ^ kLusterMbaXorKey;
}

/**
 * @brief MBA addition form 1: (a ^ b) + ((a & b) << 1) == a + b.
 *        Dạng cộng MBA 1: (a ^ b) + ((a & b) << 1) == a + b (0x03d64..0x03d6c).
 */
inline constexpr uint64_t LusterMbaAddAndXor(uint64_t a, uint64_t b) noexcept {
    return (a ^ b) + ((a & b) << 1U);
}

/**
 * @brief MBA addition form 2: ((a | b) << 1) - (a ^ b) == a + b.
 *        Dạng cộng MBA 2: ((a | b) << 1) - (a ^ b) == a + b (0x03d50..0x03d5c).
 */
inline constexpr uint64_t LusterMbaAddOrXor(uint64_t a, uint64_t b) noexcept {
    return ((a | b) << 1U) - (a ^ b);
}

/**
 * @brief Decrypts an obfuscated .data relocation value using the MBA delta.
 *        Giải mã giá trị relocation bị làm rối trong .data bằng độ lệch MBA (-0x640958).
 */
inline constexpr uint64_t DecryptLusterDataPointer(uint64_t obfuscated_vaddr,
                                                   uint64_t runtime_pc = 0x03b94ULL) noexcept {
    const uint64_t delta = ComputeLusterMbaDelta(runtime_pc);
    return LusterMbaAddAndXor(obfuscated_vaddr, delta);
}

// ============================================================================
// 3. OLLVM NUMBER-THEORETIC OPAQUE PREDICATES
//    VỊ TỪ MỜ SỐ HỌC OLLVM (THặng dư bậc hai Modulo 7 & Modulo 19)
// ============================================================================
//
// 1. Modulo-7 Quadratic Non-Residue Predicate:
//    - Multiplicative inverse of 7 mod 2^32: 0xb6db6db7 (since 7 * 0xb6db6db7 == 1 mod 2^32)
//    - Floor(2^32 / 7)                     : 0x24924924 (reciprocal magic 0x24924925)
//    - For any 32-bit integer x:
//      x^2 + 1 != 0 (mod 7) and 2*x^2 + 2 != 0 (mod 7) because -1 is a quadratic
//      non-residue modulo p = 7 (since 7 == 3 mod 4).
//    - Similarly, x^2 + 1 != 7 * y^2 (tested at 0x159f8..0x15a08: x^2 + 1 == 7 * y^2).
//
// 2. Modulo-19 Quadratic Non-Residue Predicate:
//    - Multiplicative inverse of 19 mod 2^32: 0xaf286bcb (19 * 0xaf286bcb == 1 mod 2^32)
//      and 4 * 0x286bca1b == 0xa1af286c, with threshold 0x0d79435e = Floor(2^32 / 19).
//    - Since 19 == 3 (mod 4), -1 is a quadratic non-residue mod 19, so x^2 + 1 != 0 (mod 19)
//      and 4*(x^2 + 1) != 0 (mod 19) for all integers x!

constexpr uint32_t kMod7Inverse32     = 0xb6db6db7U;
constexpr uint32_t kMod7Threshold32   = 0x24924924U;
constexpr uint32_t kMod7Reciprocal32  = 0x24924925U;

constexpr uint32_t kMod19Reciprocal32 = 0xaf286bcbU;
constexpr uint32_t kMod19StepMult32   = 0xa1af286cU;
constexpr uint32_t kMod19Threshold32  = 0x0d79435eU;

/**
 * @brief Evaluates the OLLVM mod-7 opaque predicate: checks if (x^2 + 1) is divisible by 7.
 *        Always returns false for every uint32_t x.
 *        Kiểm tra vị từ mờ mod-7: (x^2 + 1) chia hết cho 7 (luôn trả về false với mọi x).
 */
inline constexpr bool EvalOllvmMod7Divisible(uint32_t x) noexcept {
    const uint32_t val = x * x + 1U;
    const uint64_t prod = static_cast<uint64_t>(val) * static_cast<uint64_t>(kMod7Reciprocal32);
    const uint32_t hi = static_cast<uint32_t>(prod >> 32U);
    const uint32_t q = (hi + ((val - hi) >> 1U)) >> 2U;
    const uint32_t rem = val - (q * 7U);
    return rem == 0U;
}

/**
 * @brief Evaluates the OLLVM mod-19 opaque predicate at 0x152cc..0x152ec:
 *        Checks if (x^2 + 1) * 0xa1af286c > 0x0d79435e (always true!).
 *        Kiểm tra vị từ mờ mod-19 tại 0x152cc..0x152ec (luôn trả về true với mọi x).
 */
inline constexpr bool EvalOllvmMod19NonZero(uint32_t x) noexcept {
    const uint32_t lhs = (x * x) * kMod19StepMult32 + kMod19StepMult32;
    return lhs > kMod19Threshold32;
}

// ============================================================================
// 4. CORE ABI STRUCTURES (.rodata, .data.rel.ro, .bss, TerrainVMContext)
//    CẤU TRÚC ABI LÕI (.rodata, .data.rel.ro, .bss, TerrainVMContext)
// ============================================================================

/**
 * @brief 12-byte Class Registration Entry in .rodata 0x016814..0x016a0c (42 entries).
 *        Mục đăng ký lớp 12 byte tại .rodata 0x016814..0x016a0c (42 lớp).
 */
struct LusterClassRegEntry {
    uint32_t class_id;         ///< +0x00: Index into 0x02af78 class-to-string table / Chỉ mục vào bảng 0x02af78
    uint32_t first_method_idx; ///< +0x04: First method index in 0x03f750 / Chỉ mục phương thức đầu tiên
    uint32_t method_count;     ///< +0x08: Number of native methods to register / Số lượng phương thức cần đăng ký
    const char* resolved_class_name; ///< Resolved UTF-8 internal class name / Tên lớp nội bộ UTF-8 đã giải mã
};

/**
 * @brief 16-byte Native Method Registration Entry in .data.rel.ro 0x03f750..0x03fd18 (93 entries).
 *        Mục đăng ký phương thức gốc 16 byte tại .data.rel.ro 0x03f750..0x03fd18 (93 phương thức).
 */
struct LusterMethodRegEntry {
    uint32_t method_index;      ///< Logical index 0..92 / Chỉ mục logic 0..92
    uint32_t name_str_idx;      ///< +0x00: String index of method name in 0x029380 / Chỉ mục chuỗi tên hàm
    uint32_t sig_str_idx;       ///< +0x04: String index of JNI signature in 0x029380 / Chỉ mục chữ ký JNI
    uint64_t fn_vaddr;          ///< +0x08: Function virtual address in .text (0x050a0..0x1459c) / Địa chỉ hàm
    const char* class_name;     ///< Owning Java/Kotlin class internal name / Tên lớp sở hữu
    const char* method_name;    ///< Resolved method name / Tên phương thức đã giải mã
    const char* method_sig;     ///< Resolved JNI signature / Chữ ký JNI đã giải mã
};

/**
 * @brief 16-byte Field Descriptor in .rodata 0x02b7fc..0x02cd80 (344 entries).
 *        Bộ mô tả trường 16 byte tại .rodata 0x02b7fc..0x02cd80 (344 mục).
 */
struct LusterFieldDesc {
    uint32_t class_idx; ///< +0x00: Index into 0x02af78 / Chỉ mục lớp trong 0x02af78
    uint32_t type_idx;  ///< +0x04: Index into 0x02f9e0 / Chỉ mục kiểu trong 0x02f9e0
    uint32_t name_idx;  ///< +0x08: Index into 0x029380 / Chỉ mục tên trường trong 0x029380
    uint32_t flags;     ///< +0x0C: Access / static flags / Cờ truy cập
};
static_assert(sizeof(LusterFieldDesc) == 16, "LusterFieldDesc must be 16 bytes");

/**
 * @brief 16-byte Field Cache Slot in .bss 0x040b90..0x042840 (459 slots).
 *        Khe bộ nhớ đệm trường 16 byte tại .bss 0x040b90..0x042840 (459 khe).
 */
struct LusterFieldCacheSlot {
    uint64_t metadata;  ///< +0x00: Field metadata / type tag
    jfieldID field_id;  ///< +0x08: Cached JNI jfieldID (checked at 0x148ec: ldr x13, [x24, #8]!)
};
static_assert(sizeof(LusterFieldCacheSlot) == 16, "LusterFieldCacheSlot must be 16 bytes");

/**
 * @brief 16-byte Method Descriptor in .rodata 0x02d4c0..0x02f9e0 (594 entries).
 *        Bộ mô tả phương thức 16 byte tại .rodata 0x02d4c0..0x02f9e0 (594 mục).
 */
struct LusterMethodDesc {
    uint16_t class_idx;     ///< +0x00: Index into 0x02af78 (`ldrh w21, [x11]` @ 0x14e08)
    uint16_t reserved_pad;  ///< +0x02: Alignment padding
    uint32_t name_idx;      ///< +0x04: Index into 0x029380 (`ldr w9, [x9, #4]` @ 0x151f4)
    uint32_t shorty_idx;    ///< +0x08: Shorty descriptor string index (`ldp w12, w22, [x11, #4]` @ 0x14e30)
    uint32_t proto_idx;     ///< +0x0C: Index into 0x02f9e0 (`ldr w10, [x9, #0xc]` @ 0x151e8)
};
static_assert(sizeof(LusterMethodDesc) == 16, "LusterMethodDesc must be 16 bytes");

/**
 * @brief 24-byte Method Cache Slot in .bss 0x042840..0x045ff0 (594 slots).
 *        Khe bộ nhớ đệm phương thức 24 byte tại .bss 0x042840..0x045ff0 (594 khe).
 */
struct LusterMethodCacheSlot {
    const char* shorty_cstr; ///< +0x00: Pointer to resolved shorty string
    uint64_t    flags_meta;  ///< +0x08: Method flags / return type metadata
    jmethodID   method_id;   ///< +0x10: Cached JNI jmethodID (`ldr x13, [x24, #0x10]!` @ 0x14dd0)
};
static_assert(sizeof(LusterMethodCacheSlot) == 24, "LusterMethodCacheSlot must be 24 bytes");

/**
 * @brief 48-byte (0x30) Terrain VM Execution Frame passed as 2nd argument to vmInterpret.
 *        Khung thực thi máy ảo Terrain 48 byte (0x30) truyền làm đối số thứ 2 vào vmInterpret.
 *
 * Binary layout verified at 0x052b8..0x052d4 and 0x05d18..0x05d2c:
 *   +0x00: const void* code_unit_ptr      (`stur x28, [x20, #-0x30]`)
 *   +0x08: uint64_t    bytecode_meta_tag  (`stur w10, [x20, #-0x28]`, e.g. 0x9c or 0x07)
 *   +0x10: uint64_t*   register_values    (`stur x0,  [x20, #-0x20]`, stack or calloc(9,9))
 *   +0x18: uint16_t*   register_type_tags (`stp x8, xzr, [x20, #-0x18]`, 0x0100 = jobject)
 *   +0x20: uint64_t    result_or_reserved (`stur xzr, [x24, #-0x10]`)
 *   +0x28: uint64_t    frame_chain_link   (0)
 */
struct TerrainVMContext {
    const void* code_unit_ptr;      ///< +0x00: Pointer into .rodata 0x030246..0x036630
    uint64_t    bytecode_meta_tag;  ///< +0x08: Opcode stream descriptor tag / register count
    uint64_t*   register_values;    ///< +0x10: Pointer to 64-bit virtual register array
    uint16_t*   register_type_tags; ///< +0x18: Pointer to per-register type tag array (1 = ref)
    uint64_t    result_storage;     ///< +0x20: Return value slot written by vmInterpret
    uint64_t    frame_chain_link;   ///< +0x28: Reserved / parent frame pointer
};
static_assert(sizeof(TerrainVMContext) == 48, "TerrainVMContext must be 48 bytes (0x30)");

/**
 * @brief 7-Function Callback Table in .data.rel.ro 0x03fd20..0x03fd58 passed as 3rd argument to vmInterpret.
 *        Bảng 7 hàm trợ giúp tại .data.rel.ro 0x03fd20..0x03fd58 truyền làm đối số thứ 3 cho vmInterpret.
 */
struct LusterHelperTable {
    LusterFieldCacheSlot* (*resolve_field)(JNIEnv* env, uint32_t field_idx, uint32_t is_static);                 ///< +0x00: 0x014838
    LusterMethodCacheSlot* (*resolve_method)(JNIEnv* env, uint32_t method_idx, uint32_t is_static);              ///< +0x08: 0x014d20
    jmethodID (*resolve_method_direct)(JNIEnv* env, uint32_t method_idx, uint32_t is_static, jclass clazz);      ///< +0x10: 0x0151cc
    const char* (*get_type_class_name)(JNIEnv* env, uint32_t type_idx);                                          ///< +0x18: 0x0152a0
    jclass (*resolve_class_by_index)(JNIEnv* env, uint32_t class_idx);                                           ///< +0x20: 0x015400
    jclass (*resolve_class_by_descriptor)(JNIEnv* env, const char* descriptor);                                  ///< +0x28: 0x015808
    jstring (*resolve_interned_string)(JNIEnv* env, int32_t str_idx);                                            ///< +0x30: 0x015ab8
};
static_assert(sizeof(LusterHelperTable) == 56, "LusterHelperTable must be 56 bytes (0x38)");

/**
 * @brief XOR-encrypted string descriptor in .data (0x040670..0x0406c8 and 0x040ac0..0x040b18).
 *        Bộ mô tả chuỗi mã hóa XOR trong .data (giải mã qua sub_16328).
 */
struct LusterXorStringEntry {
    const char* name;
    uint32_t    cipher_vaddr;
    uint32_t    key_vaddr;
    uint32_t    bss_vaddr;
    uint32_t    flag_bss_vaddr;
    const char* expected_plaintext;
};

} // namespace luster
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LUSTER_TYPES_H_
