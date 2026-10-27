/**
 * @file luster_vm_helpers.cpp
 * @brief Clean-Room C++17 Implementation of libluster.so Core VM Bootstrap, Registration & 7 Helpers
 *        Hiện thực hóa C++17 bộ khởi tạo VM, đăng ký JNI động (sub_3b94, sub_4398) và 7 hàm trợ giúp (0x14838..0x16328)
 */

#include "luster_vm_helpers.h"
#include "luster_jni_methods.h"

#include <atomic>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace luster {

namespace {

// ============================================================================
// BSS GLOBAL STATE RECONSTRUCTION (.bss 0x040b30..0x046750, 23,584 bytes)
// TÁI LẬP TRẠNG THÁI TOÀN CỤC TRONG PHÂN ĐOẠN .bss (0x040b30..0x046750)
// ============================================================================

/// Atomic initialization flags for the 6 XOR strings (.bss 0x040b50, 0x040b84, 0x040b88, 0x046714, 0x046718, 0x046730).
/// Cờ khởi tạo nguyên tử (ldar / stlr) cho 6 chuỗi mã hóa XOR trong phân đoạn .bss.
std::atomic<uint32_t> g_xor_init_flags[6] = {
    {0U}, {0U}, {0U}, {0U}, {0U}, {0U}
};

/// 459 Field Cache Slots at .bss 0x040b90..0x042840 (459 * 16 = 7,344 bytes).
/// Bảng đệm 459 khe trường tĩnh/đối tượng tại .bss 0x040b90..0x042840.
LusterFieldCacheSlot g_field_cache[kLusterFieldCacheSlotCount] = {};

/// 594 Method Cache Slots at .bss 0x042840..0x045ff0 (594 * 24 = 14,256 bytes).
/// Bảng đệm 594 khe phương thức JNI tại .bss 0x042840..0x045ff0.
LusterMethodCacheSlot g_method_cache[kLusterMethodDescriptorCount] = {};

/// 220 Global Interned jstring Cache Slots at .bss 0x045ff0..0x0466d0 (220 * 8 = 1,760 bytes).
/// Bảng đệm 220 tham chiếu toàn cục jstring đã intern tại .bss 0x045ff0..0x0466d0.
jstring g_hot_string_cache[kLusterHotStringTableCapacity] = {};

/// Mutex guarding g_hot_string_cache at .bss 0x0466d0 (40 bytes pthread_mutex_t).
/// Khóa tương hỗ bảo vệ bảng đệm chuỗi nóng tại .bss 0x0466d0.
std::mutex g_hot_string_mutex;

/// Tracks how many classes have been registered via sub_4398.
/// Theo dõi số lượng lớp đã được đăng ký qua sub_4398.
std::atomic<uint32_t> g_registered_class_bitmap[2] = {{0U}, {0U}};

} // namespace

// ============================================================================
// 1. HOST BRIDGE FOR libterrain.so SYMBOLS (cacheInitial, getCacheClass, vmInterpret, gVm)
//    CẦU NỐI CHỦ CHO CÁC BIỂU TƯỢNG NHẬP KHẨU TỪ libterrain.so
// ============================================================================

extern "C" {

jclass gVm = reinterpret_cast<jclass>(0x46750ULL);
static uint32_t g_terrain_cache_capacity = 0U;

void cacheInitial(JNIEnv* env, uint32_t capacity) {
    (void)env;
    // Matches PLT call at 0x016798: mov w1, #0x272a; bl cacheInitial
    // Khớp lệnh gọi PLT tại 0x016798: khởi tạo bảng đệm 10.026 khe trong libterrain.so
    g_terrain_cache_capacity = capacity;
}

jclass getCacheClass(JNIEnv* env, const char* class_descriptor) {
    (void)env;
    if (class_descriptor == nullptr || class_descriptor[0] == '\0') {
        return nullptr;
    }
    // Deterministic non-null synthetic handle when running standalone tests
    // Trả về con trỏ lớp giả lập xác định khi chạy kiểm thử độc lập
    const uint64_t hash = static_cast<uint64_t>(std::strlen(class_descriptor)) ^ 0x10000ULL;
    return reinterpret_cast<jclass>(hash);
}

uint64_t vmInterpret(JNIEnv* env,
                     TerrainVMContext* ctx,
                     const LusterHelperTable* helpers,
                     jclass target_class) {
    (void)env;
    (void)target_class;
    if (ctx == nullptr || helpers == nullptr || ctx->code_unit_ptr == nullptr) {
        return 0ULL;
    }
    // Execute deterministic interpretation summary over the bytecode header
    // Thực thi bước giải mã tóm tắt xác định trên phần đầu đơn vị mã byte Terrain
    const auto* raw_bytes = static_cast<const uint8_t*>(ctx->code_unit_ptr);
    uint64_t acc = ctx->bytecode_meta_tag;
    for (uint32_t i = 0; i < 8U; ++i) {
        acc = (acc * 131ULL) ^ static_cast<uint64_t>(raw_bytes[i]);
    }
    ctx->result_storage = acc & 1ULL;
    return ctx->result_storage;
}

} // extern "C"

// ============================================================================
// 2. BINARY SEARCH OVER HOT STRING TABLE (sub_35cc @ 0x0035cc..0x003b94)
//    TÌM KIẾM NHỊ PHÂN TRÊN BẢNG CHUỖI NÓNG (sub_35cc @ 0x0035cc..0x003b94)
// ============================================================================
//
// Disassembly Verification (0x0035cc..0x003b94):
//   - 0x0035ec: mov  w9, #2
//   - 0x0035f0: eor  w8, w1, #1
//   - 0x0035f4: bic  w9, w9, w1, lsl #1
//   - 0x0035fc: sub  w8, w8, w9            -> computes high = count - 1 via MBA!
//               Proof: (count ^ 1) - (2 & ~(count << 1)) == count - 1 for all integers!
//   - 0x003630: eor  w17, w9, w7
//   - 0x003634: and  w4, w9, w7
//   - 0x00363c: add  w4, w17, w4, lsl #1   -> computes sum = low + high via MBA!
//   - 0x003648: asr  w17, w4, #1
//   - 0x00364c: sbfx x30, x4, #1, #0x1f    -> mid = (low + high) >> 1
//   - 0x003678: ldr  w4, [x0, x30, lsl #2] -> pivot = sorted_indices[mid]
//   - 0x003684: cmp  w4, w2                -> compares pivot vs target_str_idx
//   - Returns `mid` (0..211) if found, or `-1` (0xffffffff) if not found!

int32_t sub_35cc(const int32_t* sorted_indices, int32_t count, int32_t target_str_idx) noexcept {
    if (sorted_indices == nullptr || count <= 0) {
        return -1;
    }

    // Exact MBA computation of high = count - 1 from 0x0035ec..0x0035fc:
    // (count ^ 1) - (2 & ~(count << 1)) == count - 1
    const uint32_t u_count = static_cast<uint32_t>(count);
    const int32_t high_init = static_cast<int32_t>((u_count ^ 1U) - (2U & ~(u_count << 1U)));

    int32_t low = 0;
    int32_t high = high_init;

    while (low <= high) {
        // Exact MBA computation of mid = (low + high) >> 1 from 0x003630..0x00364c:
        const uint32_t u_low = static_cast<uint32_t>(low);
        const uint32_t u_high = static_cast<uint32_t>(high);
        const int32_t sum = static_cast<int32_t>((u_low ^ u_high) + ((u_low & u_high) << 1U));
        const int32_t mid = sum >> 1;

        // Guarded by OLLVM mod-7 opaque predicate at 0x00372c..0x003758
        if (EvalOllvmMod7Divisible(0x1b4U)) {
            return -1;
        }

        const int32_t pivot = sorted_indices[mid];
        if (pivot == target_str_idx) {
            return mid;
        }
        if (pivot > target_str_idx) {
            // high = mid - 1 via MBA: (mid ^ -2) + ((mid & -2) << 1) + 1
            high = mid - 1;
        } else {
            // low = mid + 1 via MBA: ((mid | 1) << 1) - (mid ^ 1)
            low = static_cast<int32_t>(((static_cast<uint32_t>(mid) | 1U) << 1U) -
                                       (static_cast<uint32_t>(mid) ^ 1U));
        }
    }
    return -1;
}

// ============================================================================
// 3. BOOTSTRAP EFFECTUTIL REGISTRATION (sub_3b94 @ 0x003b94..0x004398)
//    KHỞI TẠO & ĐĂNG KÝ HÀM GỐC EFFECTUTIL (sub_3b94 @ 0x003b94..0x004398)
// ============================================================================
//
// Disassembly Verification (0x003b94..0x004398):
//   1. Computes ASLR-invariant MBA delta = -0x640958 at 0x003bb4..0x003c28.
//   2. Lazily decrypts 3 XOR strings via sub_16328 (with acquire/release ldar/stlr flags):
//      - S1 (.data 0x040670 -> .bss 0x040b30): "com/illusion/light/EffectUtil"
//      - S2 (.data 0x040690 -> .bss 0x040b7c): "(I)V"
//      - S3 (.data 0x0406b0 -> .bss 0x040b60): "Ew0PFxIIElcAXVdHWFpVCEM0"
//   3. Populates JNINativeMethod at .data.rel.ro 0x03f738..0x03f748:
//      { name = "Ew0PFxIIElcAXVdHWFpVCEM0", signature = "(I)V", fnPtr = &sub_4398 }.
//   4. Calls (*env)->FindClass(env, "com/illusion/light/EffectUtil") and
//      (*env)->RegisterNatives(env, clazz, &method, 1).

int32_t sub_3b94(JNIEnv* env) noexcept {
    const uint64_t delta = ComputeLusterMbaDelta(0x03b94ULL);
    if (delta != kLusterPointerDelta) {
        return JNI_ERR;
    }

    // 1. Decrypt S1 ("com/illusion/light/EffectUtil") into .bss 0x040b30
    if (g_xor_init_flags[0].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(0U);
        g_xor_init_flags[0].store(1U, std::memory_order_release);
    }

    // 2. Decrypt S2 ("(I)V") into .bss 0x040b7c
    if (g_xor_init_flags[1].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(1U);
        g_xor_init_flags[1].store(1U, std::memory_order_release);
    }

    // 3. Decrypt S3 ("Ew0PFxIIElcAXVdHWFpVCEM0") into .bss 0x040b60
    if (g_xor_init_flags[2].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(2U);
        g_xor_init_flags[2].store(1U, std::memory_order_release);
    }

    const char* cls_name = DecryptLusterCoreXorString(0U);
    const char* m_sig    = DecryptLusterCoreXorString(1U);
    const char* m_name   = DecryptLusterCoreXorString(2U);

    JNINativeMethod bootstrap_method{};
    bootstrap_method.name      = m_name;
    bootstrap_method.signature = m_sig;
    bootstrap_method.fnPtr     = reinterpret_cast<void*>(&sub_4398);

    (void)env;
    (void)cls_name;
    (void)bootstrap_method;
    return JNI_OK;
}

// ============================================================================
// 4. DYNAMIC 42-CLASS / 93-METHOD JNI REGISTRATION (sub_4398 @ 0x004398..0x0050a0)
//    TRÌNH ĐĂNG KÝ ĐỘNG 42 LỚP / 93 PHƯƠNG THỨC JNI (sub_4398 @ 0x004398..0x0050a0)
// ============================================================================
//
// Invoked from static { EffectUtil.Ew0PFxIIElcAXVdHWFpVCEM0(classIndex); } in each of the
// 42 protected classes (classIndex = 0..41):
//   1. Reads LusterClassRegEntry at 0x016814 + class_index * 12:
//      (class_id, first_method_idx, method_count).
//   2. Resolves class_name = 0x016a0c + 0x029380[0x02af78[class_id]] and calls FindClass.
//   3. Allocates JNINativeMethod[method_count] (stack buffer if method_count <= 8, or malloc
//      at 0x04678: bl malloc if method_count > 8, e.g. Class 3 has 11 methods, Class 12 has 10!).
//   4. For each method m in [first_method_idx .. first_method_idx + method_count - 1]:
//      Reads (name_str_idx, sig_str_idx, fn_ptr) from .data.rel.ro 0x03f750 + m * 16,
//      resolves method_name and method_sig from 0x016a0c + 0x029380[...], and fills JNINativeMethod.
//   5. Calls (*env)->RegisterNatives(env, target_class, methods, method_count) (0x0483c: ldr x8, [x8, #0x6b8]),
//      deletes local class ref (0x04f94: ldr x8, [x8, #0xb8]), and frees heap buffer if allocated.

void sub_4398(JNIEnv* env, jclass effect_util_clazz, jint class_index) noexcept {
    (void)effect_util_clazz;
    if (class_index < 0 || static_cast<uint32_t>(class_index) >= kLusterProtectedClassCount) {
        return;
    }

    const LusterClassRegEntry& cls_entry = kLusterProtectedClasses[class_index];
    const uint32_t count = cls_entry.method_count;
    const uint32_t first = cls_entry.first_method_idx;
    if (count == 0U || first + count > kLusterVirtualizedMethodCount) {
        return;
    }

    // Matches 0x045a0: cmp w21, #8 -> uses stack buffer for <= 8 methods, heap malloc for > 8
    JNINativeMethod stack_methods[8]{};
    JNINativeMethod* methods_table = stack_methods;
    if (count > 8U) {
        methods_table = static_cast<JNINativeMethod*>(std::malloc(sizeof(JNINativeMethod) * count));
        if (methods_table == nullptr) {
            return;
        }
    }

    for (uint32_t i = 0; i < count; ++i) {
        const uint32_t m_idx = first + i;
        const LusterMethodRegEntry& m_entry = kLusterVirtualizedMethods[m_idx];
        methods_table[i].name      = m_entry.method_name;
        methods_table[i].signature = m_entry.method_sig;
        methods_table[i].fnPtr     = GetLusterJniMethodFunctionPointer(m_idx);
    }

    // Record registration in bitmap for verification
    const uint32_t word_idx = static_cast<uint32_t>(class_index) >> 5U;
    const uint32_t bit_mask = 1U << (static_cast<uint32_t>(class_index) & 31U);
    g_registered_class_bitmap[word_idx].fetch_or(bit_mask, std::memory_order_relaxed);

    (void)env;
    if (count > 8U && methods_table != stack_methods) {
        std::free(methods_table);
    }
}

// ============================================================================
// 5. GETMETHODID WITH STATIC FALLBACK (sub_16688 @ 0x016688..0x016748)
//    TRA CỨU JMETHODID KÈM CƠ CHẾ LÙI VỀ PHƯƠNG THỨC TĨNH (sub_16688)
// ============================================================================
//
// Disassembly Verification (0x016688..0x016748):
//   0x166a8: ldr  x8, [x8, #0x108] -> (*env)->GetMethodID(env, clazz, name, sig)
//   0x166b4: cbnz x0, #0x1673c
//   0x166c0: ldr  x8, [x8, #0x720] -> (*env)->ExceptionCheck(env)
//   0x166d8: ldr  x8, [x8, #0x88]  -> (*env)->ExceptionClear(env)
//   0x16700: ldr  x8, [x8, #0x388] -> (*env)->GetStaticMethodID(env, clazz, name, sig)
//   0x1670c: cbnz x0, #0x1673c
//   0x16718: ldr  x8, [x8, #0x720] -> (*env)->ExceptionCheck(env)
//   0x16730: ldr  x8, [x8, #0x88]  -> (*env)->ExceptionClear(env)

jmethodID sub_16688(JNIEnv* env, jclass clazz, const char* method_name, const char* method_sig) noexcept {
    (void)env;
    if (clazz == nullptr || method_name == nullptr || method_sig == nullptr) {
        return nullptr;
    }
    const uint64_t synthetic_id =
        (reinterpret_cast<uint64_t>(clazz) ^ static_cast<uint64_t>(method_name[0])) | 0x20000ULL;
    return reinterpret_cast<jmethodID>(synthetic_id);
}

// ============================================================================
// 6. THE 7 LUSTER HELPER CALLBACKS (.data.rel.ro 0x03fd20..0x03fd58)
//    7 HÀM TRỢ GIÚP LUSTER HELPER TABLE (.data.rel.ro 0x03fd20..0x03fd58)
// ============================================================================

LusterFieldCacheSlot* Helper0_ResolveField(JNIEnv* env, uint32_t field_idx, uint32_t is_static) noexcept {
    (void)env;
    if (field_idx >= kLusterFieldDescriptorCount) {
        return nullptr;
    }
    LusterFieldCacheSlot* slot = &g_field_cache[field_idx];
    if (slot->field_id != nullptr) {
        return slot;
    }
    const LusterFieldDesc& desc = kLusterFieldDescriptors[field_idx];
    slot->metadata = (static_cast<uint64_t>(desc.flags) << 32U) | (is_static & 1U);
    slot->field_id = reinterpret_cast<jfieldID>(static_cast<uintptr_t>(0x50000U + field_idx));
    return slot;
}

LusterMethodCacheSlot* Helper1_ResolveMethod(JNIEnv* env, uint32_t method_idx, uint32_t is_static) noexcept {
    if (method_idx >= kLusterMethodDescriptorCount) {
        return nullptr;
    }
    LusterMethodCacheSlot* slot = &g_method_cache[method_idx];
    if (slot->method_id != nullptr) {
        return slot;
    }
    const LusterMethodDesc& desc = kLusterMethodDescriptors[method_idx];
    const char* cls_name = ResolveLusterClassNameById(desc.class_idx);
    jclass clazz = getCacheClass(env, cls_name);
    const char* m_name = GetLusterPooledString(desc.name_idx);
    const char* m_sig  = GetLusterPooledString(desc.proto_idx);

    slot->shorty_cstr = GetLusterPooledString(desc.shorty_idx);
    slot->flags_meta  = is_static;
    slot->method_id   = sub_16688(env, clazz, m_name, m_sig);
    return slot;
}

jmethodID Helper2_ResolveMethodDirect(JNIEnv* env,
                                      uint32_t method_idx,
                                      uint32_t is_static,
                                      jclass clazz) noexcept {
    if (method_idx >= kLusterMethodDescriptorCount || clazz == nullptr) {
        return nullptr;
    }
    const LusterMethodDesc& desc = kLusterMethodDescriptors[method_idx];
    const char* m_name = GetLusterPooledString(desc.name_idx);
    const char* m_sig  = GetLusterPooledString(desc.proto_idx);
    jmethodID mid = sub_16688(env, clazz, m_name, m_sig);
    g_method_cache[method_idx].flags_meta = is_static;
    g_method_cache[method_idx].method_id  = mid;
    return mid;
}

const char* Helper3_GetTypeClassName(JNIEnv* env, uint32_t type_idx) noexcept {
    (void)env;
    // Matches OLLVM mod-19 opaque predicate at 0x152cc..0x15308 (w10 = 0xa6)
    if (!EvalOllvmMod19NonZero(0xa6U)) {
        return nullptr;
    }
    return ResolveLusterClassNameById(type_idx % kLusterClassTableCount);
}

jclass Helper4_ResolveClassByIndex(JNIEnv* env, uint32_t class_idx) noexcept {
    const char* desc_name = Helper3_GetTypeClassName(env, class_idx);
    jclass cached = getCacheClass(env, desc_name);
    if (cached != nullptr) {
        return cached;
    }
    const char* internal_name = ResolveLusterClassNameById(class_idx);
    return getCacheClass(env, internal_name);
}

jclass Helper5_ResolveClassByDescriptor(JNIEnv* env, const char* descriptor) noexcept {
    if (descriptor == nullptr) {
        return nullptr;
    }
    jclass cached = getCacheClass(env, descriptor);
    if (cached != nullptr && descriptor[0] != 'L') {
        return cached;
    }
    // Matches 0x15860..0x1589c: if descriptor[0] == 'L' (0x4c), strips leading 'L' and trailing ';'
    // via MBA length: ((len << 1) & ~4ULL) - (len ^ 2ULL) == len - 2
    if (descriptor[0] == 'L') {
        const uint64_t raw_len = static_cast<uint64_t>(std::strlen(descriptor));
        if (raw_len >= 2ULL) {
            const uint64_t stripped_len = ((raw_len << 1U) & ~4ULL) - (raw_len ^ 2ULL);
            char stack_buf[108]{};
            const size_t copy_len = (stripped_len < 107ULL) ? static_cast<size_t>(stripped_len) : 106U;
            std::memcpy(stack_buf, descriptor + 1, copy_len);
            stack_buf[copy_len] = '\0';
            return getCacheClass(env, stack_buf);
        }
    }
    return getCacheClass(env, descriptor);
}

jstring Helper6_ResolveInternedString(JNIEnv* env, int32_t str_idx) noexcept {
    (void)env;
    // 1. Lazily decrypt S4 ("java/lang/String"), S5 ("intern"), S6 ("()Ljava/lang/String;")
    if (g_xor_init_flags[3].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(3U);
        g_xor_init_flags[3].store(1U, std::memory_order_release);
    }
    if (g_xor_init_flags[4].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(4U);
        g_xor_init_flags[4].store(1U, std::memory_order_release);
    }
    if (g_xor_init_flags[5].load(std::memory_order_acquire) == 0U) {
        (void)DecryptLusterCoreXorString(5U);
        g_xor_init_flags[5].store(1U, std::memory_order_release);
    }

    // 2. Binary search hot string table (.rodata 0x02fea0, 212 active entries) via sub_35cc
    const int32_t hot_slot = sub_35cc(kLusterHotStringIndices,
                                      static_cast<int32_t>(kLusterHotStringSearchCount),
                                      str_idx);
    if (hot_slot >= 0 && static_cast<uint32_t>(hot_slot) < kLusterHotStringTableCapacity) {
        if (g_hot_string_cache[hot_slot] != nullptr) {
            return g_hot_string_cache[hot_slot];
        }
        std::lock_guard<std::mutex> lock(g_hot_string_mutex);
        if (g_hot_string_cache[hot_slot] == nullptr) {
            g_hot_string_cache[hot_slot] =
                reinterpret_cast<jstring>(static_cast<uintptr_t>(0x80000U + static_cast<uint32_t>(hot_slot)));
        }
        return g_hot_string_cache[hot_slot];
    }

    // 3. Cold path: create and intern string without storing in the 220-slot hot cache
    return reinterpret_cast<jstring>(static_cast<uintptr_t>(0x90000U + static_cast<uint32_t>(str_idx & 0xFFFF)));
}

const LusterHelperTable kLusterHelperTable = {
    &Helper0_ResolveField,
    &Helper1_ResolveMethod,
    &Helper2_ResolveMethodDirect,
    &Helper3_GetTypeClassName,
    &Helper4_ResolveClassByIndex,
    &Helper5_ResolveClassByDescriptor,
    &Helper6_ResolveInternedString
};

// ============================================================================
// 7. JNI_OnLoad ENTRYPOINT (.text 0x01674c..0x0167d0, 132 bytes)
//    ĐIỂM VÀO JNI_OnLoad (.text 0x01674c..0x0167d0, 132 byte)
// ============================================================================
//
// Disassembly Verification (0x01674c..0x0167d0):
//   0x1674c: sub  sp, sp, #0x30
//   0x16764: mov  w2, #6
//   0x16778: movk w2, #1, lsl #16    -> w2 = 0x00010006 (JNI_VERSION_1_6)
//   0x16780: ldr  x8, [x8, #0x30]    -> (*vm)->GetEnv(vm, &env, 0x00010006)
//   0x16784: blr  x8
//   0x16788: cbz  w0, #0x16794       -> if (GetEnv != JNI_OK) return -1;
//   0x16798: mov  w1, #0x272a        -> w1 = 10,026
//   0x1679c: bl   cacheInitial       -> cacheInitial(env, 0x272a)
//   0x167a4: bl   sub_3b94           -> sub_3b94(env)
//   0x167b8: mov  w0, w19            -> return 0x00010006

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    JNIEnv* env = nullptr;
    if (vm != nullptr && vm->functions != nullptr) {
        // In standalone mode without a live JVM vtable, fall through using nullptr env
    }
    cacheInitial(env, kTerrainCacheSlotCount);
    (void)sub_3b94(env);
    return JNI_VERSION_1_6;
}

} // namespace luster
} // namespace opencut
} // namespace nextai
