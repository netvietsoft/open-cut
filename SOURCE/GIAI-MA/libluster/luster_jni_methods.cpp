/**
 * @file luster_jni_methods.cpp
 * @brief Clean-Room C++17 Implementation of All 93 Virtualized JNI Methods in libluster.so
 *        Hiện thực hóa C++17 toàn bộ 93 phương thức gốc JNI ảo hóa trong libluster.so (0x050a0..0x1459c)
 */

#include "luster_jni_methods.h"
#include "luster_rodata_tables.h"
#include "luster_vm_helpers.h"

#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace luster {

uint64_t InvokeLusterVirtualizedMethod(JNIEnv* env,
                                       jobject thiz_or_clazz,
                                       uint32_t method_index,
                                       const uint64_t* args,
                                       uint32_t arg_count) noexcept {
    if (method_index >= kLusterVirtualizedMethodCount) {
        return 0ULL;
    }

    const LusterMethodRegEntry& m_entry = kLusterVirtualizedMethods[method_index];

    // 1. OLLVM Number-Theoretic Opaque Predicate Guard (Mod-7 & Mod-19 non-residue check)
    //    Kiểm tra vị từ mờ số học OLLVM (thặng dư bậc hai Modulo 7 & Modulo 19)
    if (EvalOllvmMod7Divisible(0x114U + method_index) || !EvalOllvmMod19NonZero(0xa6U + method_index)) {
        return 0ULL;
    }

    // 2. Compute ASLR-invariant MBA pointer delta (-0x640958) from runtime PC
    //    Tính độ lệch giải mã con trỏ MBA bất biến với ASLR (-0x640958) từ địa chỉ hàm
    const uint64_t delta = ComputeLusterMbaDelta(m_entry.fn_vaddr);
    const LusterBytecodeUnitInfo& unit = kLusterBytecodeUnits[method_index % kLusterBytecodeUnitCount];
    const uint64_t decrypted_unit_vaddr = LusterMbaAddAndXor(unit.obfuscated_reloc, delta);
    if (decrypted_unit_vaddr != unit.real_rodata_vaddr) {
        return 0ULL;
    }

    // 3. Resolve owning jclass via getCacheClass / FindClass
    //    Phân giải lớp sở hữu qua getCacheClass / FindClass
    jclass target_class = getCacheClass(env, m_entry.class_name);

    // 4. Construct 48-byte (0x30) TerrainVMContext frame (stack or calloc(9, 9) for multi-arg methods)
    //    Thiết lập khung thực thi TerrainVMContext 48 byte (trên ngăn xếp hoặc calloc(9, 9) = 81 byte)
    uint64_t stack_regs[8]{};
    uint16_t stack_tags[8]{};
    uint8_t* heap_block = nullptr;
    uint64_t* reg_vals = stack_regs;
    uint16_t* reg_tags = stack_tags;

    if (arg_count > 2U) {
        heap_block = static_cast<uint8_t*>(std::calloc(9U, 9U));
        if (heap_block != nullptr) {
            reg_vals = reinterpret_cast<uint64_t*>(heap_block);
            reg_tags = reinterpret_cast<uint16_t*>(heap_block + 0x48U);
        }
    }

    reg_vals[0] = reinterpret_cast<uint64_t>(thiz_or_clazz);
    reg_tags[0] = 0x0100U;
    for (uint32_t i = 0; i < arg_count && i < 5U; ++i) {
        reg_vals[i + 1U] = (args != nullptr) ? args[i] : 0ULL;
        reg_tags[i + 1U] = 0x0001U;
    }

    TerrainVMContext vm_ctx{};
    vm_ctx.code_unit_ptr      = unit.header_bytes;
    vm_ctx.bytecode_meta_tag  = (static_cast<uint64_t>(method_index) << 8U) | 0x07ULL;
    vm_ctx.register_values    = reg_vals;
    vm_ctx.register_type_tags = reg_tags;
    vm_ctx.result_storage     = 0ULL;
    vm_ctx.frame_chain_link   = 0ULL;

    // 5. Invoke Terrain VM Interpreter (`bl vmInterpret` @ 0x034e0)
    //    Gọi trình thông dịch máy ảo Terrain (`bl vmInterpret` @ 0x034e0)
    const uint64_t ret_val = vmInterpret(env, &vm_ctx, &kLusterHelperTable, target_class);

    if (heap_block != nullptr) {
        std::free(heap_block);
    }
    return ret_val;
}


// ============================================================================
// Method [00] @ 0x050a0..0x05328 (648 bytes)
// Class     : com/bytedance/EnvGuard/Handler (Class [00], class_id=13)
// Method    : handleUpdate (name_str_idx=804)
// Signature : (J)V (sig_str_idx=1399)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_00_0x050a0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 0U, args, 4U);
}

// ============================================================================
// Method [01] @ 0x05328..0x055dc (692 bytes)
// Class     : com/lemon/editor/proxy/SubscribeImpl (Class [01], class_id=20)
// Method    : b (name_str_idx=647)
// Signature : (Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V (sig_str_idx=1770)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_01_0x05328(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 1U, args, 4U);
}

// ============================================================================
// Method [02] @ 0x055dc..0x058a8 (716 bytes)
// Class     : com/lemon/editor/proxy/SubscribeImpl (Class [01], class_id=20)
// Method    : f (name_str_idx=732)
// Signature : (ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1112)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_02_0x055dc(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 2U, args, 4U);
}

// ============================================================================
// Method [03] @ 0x058a8..0x05b20 (632 bytes)
// Class     : com/lemon/editor/proxy/SubscribeImpl (Class [01], class_id=20)
// Method    : h (name_str_idx=801)
// Signature : (Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1788)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_03_0x058a8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 3U, args, 4U);
}

// ============================================================================
// Method [04] @ 0x05b20..0x05d84 (612 bytes)
// Class     : com/lemon/editor/proxy/SubscribeImpl (Class [01], class_id=20)
// Method    : isVip (name_str_idx=843)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_04_0x05b20(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 4U, args, 4U);
}

// ============================================================================
// Method [05] @ 0x05d84..0x06020 (668 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1155)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_05_0x05d84(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 5U, args, 4U);
}

// ============================================================================
// Method [06] @ 0x06020..0x062e8 (712 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : c (name_str_idx=661)
// Signature : (JZLjava/util/List;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1641)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_06_0x06020(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 6U, args, 4U);
}

// ============================================================================
// Method [07] @ 0x062e8..0x065a0 (696 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : d (name_str_idx=696)
// Signature : (JLjava/lang/String;Ljava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1413)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_07_0x062e8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 7U, args, 4U);
}

// ============================================================================
// Method [08] @ 0x065a0..0x06880 (736 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : e (name_str_idx=708)
// Signature : (JLjava/lang/String;ILorg/json/JSONObject;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1053)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_08_0x065a0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 8U, args, 4U);
}

// ============================================================================
// Method [09] @ 0x06880..0x06b4c (716 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : g (name_str_idx=743)
// Signature : (JZLjava/lang/String;Ljava/lang/String;Lorg/json/JSONObject;Ljava/lang/String;Ljava/lang/String;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1600)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_09_0x06880(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 9U, args, 4U);
}

// ============================================================================
// Method [10] @ 0x06b4c..0x06d6c (544 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : i (name_str_idx=813)
// Signature : (JZLjava/lang/String;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1127)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_10_0x06b4c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 10U, args, 4U);
}

// ============================================================================
// Method [11] @ 0x06d6c..0x06fcc (608 bytes)
// Class     : com/vega/ad/credit/CreditRewardGlobalViewModel (Class [02], class_id=62)
// Method    : n (name_str_idx=876)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_11_0x06d6c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 11U, args, 4U);
}

// ============================================================================
// Method [12] @ 0x06fcc..0x0727c (688 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : a (name_str_idx=624)
// Signature : (Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1155)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_12_0x06fcc(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 12U, args, 4U);
}

// ============================================================================
// Method [13] @ 0x0727c..0x07510 (660 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1249)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_13_0x0727c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 13U, args, 4U);
}

// ============================================================================
// Method [14] @ 0x07510..0x07768 (600 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : c (name_str_idx=661)
// Signature : (Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1677)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_14_0x07510(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 14U, args, 4U);
}

// ============================================================================
// Method [15] @ 0x07768..0x079f4 (652 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : d (name_str_idx=696)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1296)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_15_0x07768(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 15U, args, 4U);
}

// ============================================================================
// Method [16] @ 0x079f4..0x07c3c (584 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : e (name_str_idx=708)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1300)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_16_0x079f4(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 16U, args, 4U);
}

// ============================================================================
// Method [17] @ 0x07c3c..0x07e6c (560 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : g (name_str_idx=743)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoActionReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1249)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_17_0x07c3c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 17U, args, 4U);
}

// ============================================================================
// Method [18] @ 0x07e6c..0x08130 (708 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : h (name_str_idx=801)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1296)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_18_0x07e6c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 18U, args, 4U);
}

// ============================================================================
// Method [19] @ 0x08130..0x083b0 (640 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : i (name_str_idx=813)
// Signature : (Ljava/lang/Long;Lcom/vega/adapi/data/credit/DoRewardCallBackReq;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1300)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_19_0x08130(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 19U, args, 4U);
}

// ============================================================================
// Method [20] @ 0x083b0..0x0863c (652 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : j (name_str_idx=848)
// Signature : (Ljava/lang/Long;Ljava/util/List;Lorg/json/JSONObject;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1677)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_20_0x083b0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 20U, args, 4U);
}

// ============================================================================
// Method [21] @ 0x0863c..0x088a8 (620 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : k (name_str_idx=850)
// Signature : (Ljava/util/List;Z)V (sig_str_idx=1095)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_21_0x0863c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 21U, args, 4U);
}

// ============================================================================
// Method [22] @ 0x088a8..0x08b50 (680 bytes)
// Class     : com/vega/ad/credit/data/CreditRewardRepository (Class [03], class_id=80)
// Method    : m (name_str_idx=868)
// Signature : (Lcom/vega/ad/credit/data/ApiSource;Lcom/vega/adapi/data/credit/UserInfo;Ljava/lang/String;)V (sig_str_idx=1327)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_22_0x088a8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 22U, args, 4U);
}

// ============================================================================
// Method [23] @ 0x08b50..0x08da8 (600 bytes)
// Class     : com/vega/ad/credit/task/CreditActiveRewardTask (Class [04], class_id=87)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1083)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_23_0x08b50(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 23U, args, 4U);
}

// ============================================================================
// Method [24] @ 0x08da8..0x08ff0 (584 bytes)
// Class     : com/vega/ad/credit/task/CreditLandingRewardTask (Class [05], class_id=92)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1083)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_24_0x08da8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 24U, args, 4U);
}

// ============================================================================
// Method [25] @ 0x08ff0..0x09290 (672 bytes)
// Class     : com/vega/ad/credit/task/CreditLandingRewardTask (Class [05], class_id=92)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/adapi/credit/CreditTaskResult;)Z (sig_str_idx=1601)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_25_0x08ff0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 25U, args, 4U);
}

// ============================================================================
// Method [26] @ 0x09290..0x094e4 (596 bytes)
// Class     : com/vega/ad/credit/task/CreditTemplateExportCheckTask (Class [06], class_id=99)
// Method    : i (name_str_idx=813)
// Signature : (Lcom/vega/adapi/data/credit/UserInfo;I)Lcom/vega/adapi/credit/CreditTaskResult; (sig_str_idx=1483)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_26_0x09290(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 26U, args, 4U);
}

// ============================================================================
// Method [27] @ 0x094e4..0x09700 (540 bytes)
// Class     : com/vega/ad/credit/task/CreditTemplateExportCheckTask (Class [06], class_id=99)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1083)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_27_0x094e4(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 27U, args, 4U);
}

// ============================================================================
// Method [28] @ 0x09700..0x09950 (592 bytes)
// Class     : com/vega/ad/credit/task/CreditTemplateExportCheckTask (Class [06], class_id=99)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/adapi/credit/CreditTaskResult;)Z (sig_str_idx=1601)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_28_0x09700(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 28U, args, 4U);
}

// ============================================================================
// Method [29] @ 0x09950..0x09c00 (688 bytes)
// Class     : com/vega/ad/credit/task/CreditWatchAdRewardTask (Class [07], class_id=101)
// Method    : b (name_str_idx=647)
// Signature : (Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1083)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_29_0x09950(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 29U, args, 4U);
}

// ============================================================================
// Method [30] @ 0x09c00..0x09e68 (616 bytes)
// Class     : com/vega/ad/credit/task/CreditWatchAdRewardTask (Class [07], class_id=101)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/adapi/credit/CreditTaskResult;)Z (sig_str_idx=1601)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_30_0x09c00(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 30U, args, 4U);
}

// ============================================================================
// Method [31] @ 0x09e68..0x0a090 (552 bytes)
// Class     : com/vega/ad/impl/adfree/AdFreeManager (Class [08], class_id=104)
// Method    : a (name_str_idx=624)
// Signature : (Lcom/vega/adapi/constant/AdSceneTag;)Z (sig_str_idx=1140)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_31_0x09e68(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 31U, args, 4U);
}

// ============================================================================
// Method [32] @ 0x0a090..0x0a2f0 (608 bytes)
// Class     : com/vega/ad/impl/multireward/MultiRewardAd (Class [09], class_id=105)
// Method    : k (name_str_idx=850)
// Signature : (Ljava/lang/String;)Z (sig_str_idx=1199)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_32_0x0a090(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 32U, args, 4U);
}

// ============================================================================
// Method [33] @ 0x0a2f0..0x0a53c (588 bytes)
// Class     : com/vega/ad/impl/multireward/MultiRewardAd (Class [09], class_id=105)
// Method    : s (name_str_idx=939)
// Signature : (Ljava/lang/String;)V (sig_str_idx=1640)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_33_0x0a2f0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 33U, args, 4U);
}

// ============================================================================
// Method [34] @ 0x0a53c..0x0a7c0 (644 bytes)
// Class     : com/vega/adapi/credit/BaseAdCreditTask (Class [10], class_id=114)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/adapi/credit/CreditTaskResult;)Z (sig_str_idx=1601)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_34_0x0a53c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 34U, args, 4U);
}

// ============================================================================
// Method [35] @ 0x0a7c0..0x0aa70 (688 bytes)
// Class     : com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook (Class [11], class_id=141)
// Method    : c (name_str_idx=661)
// Signature : (Lcom/vega/container/session/core/ISession;Lcom/vega/edit/figure/model/FigureGroup;Lcom/ss/android/ugc/effectmanager/effect/model/Effect;Ljava/lang/String;Ljava/lang/String;Lcom/vega/middlebridge/swig/LVVEMetaType;Ljava/lang/String;Ljava/lang/Integer;)V (sig_str_idx=1450)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_35_0x0a7c0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 35U, args, 4U);
}

// ============================================================================
// Method [36] @ 0x0aa70..0x0acec (636 bytes)
// Class     : com/vega/commonedit/dependencies/figure/LVFigureGlobalDependencyImpl$FigureOnItemApplyHook (Class [11], class_id=141)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/container/session/core/ISession;Ljava/util/Map;)V (sig_str_idx=1707)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_36_0x0aa70(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 36U, args, 4U);
}

// ============================================================================
// Method [37] @ 0x0acec..0x0af6c (640 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : getCompatUnlockProductInfo (name_str_idx=750)
// Signature : ()Lcom/vega/draft/data/template/ProductInfo; (sig_str_idx=1628)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_37_0x0acec(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 37U, args, 4U);
}

// ============================================================================
// Method [38] @ 0x0af6c..0x0b214 (680 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : getProductInfo (name_str_idx=775)
// Signature : (Ljava/lang/String;)Lcom/vega/draft/data/template/ProductInfo; (sig_str_idx=1078)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_38_0x0af6c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 38U, args, 4U);
}

// ============================================================================
// Method [39] @ 0x0b214..0x0b4d4 (704 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : hasBoughtProductInfo (name_str_idx=806)
// Signature : (Ljava/lang/String;)Z (sig_str_idx=1199)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_39_0x0b214(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 39U, args, 4U);
}

// ============================================================================
// Method [40] @ 0x0b4d4..0x0b780 (684 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : hasProductInfo (name_str_idx=809)
// Signature : (Ljava/lang/String;)Z (sig_str_idx=1199)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_40_0x0b4d4(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 40U, args, 4U);
}

// ============================================================================
// Method [41] @ 0x0b780..0x0ba1c (668 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isGeneralPaidExportTemplate (name_str_idx=831)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_41_0x0b780(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 41U, args, 4U);
}

// ============================================================================
// Method [42] @ 0x0ba1c..0x0bc08 (492 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isPaidBusinessTemplateOnlyExport (name_str_idx=837)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_42_0x0ba1c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 42U, args, 4U);
}

// ============================================================================
// Method [43] @ 0x0bc08..0x0be24 (540 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isPaidExportBusinessTemplate (name_str_idx=838)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_43_0x0bc08(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 43U, args, 4U);
}

// ============================================================================
// Method [44] @ 0x0be24..0x0c08c (616 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isPaidExportTemplate (name_str_idx=839)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_44_0x0be24(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 44U, args, 4U);
}

// ============================================================================
// Method [45] @ 0x0c08c..0x0c2e0 (596 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isPaidUnlockBusinessTemplate (name_str_idx=840)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_45_0x0c08c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 45U, args, 4U);
}

// ============================================================================
// Method [46] @ 0x0c2e0..0x0c500 (544 bytes)
// Class     : com/vega/draft/data/template/CommerceInfo (Class [12], class_id=162)
// Method    : isPaidUnlockTemplate (name_str_idx=841)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_46_0x0c2e0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 46U, args, 4U);
}

// ============================================================================
// Method [47] @ 0x0c500..0x0c720 (544 bytes)
// Class     : com/vega/edit/editpage/controller/EditExportController (Class [13], class_id=183)
// Method    : Z (name_str_idx=607)
// Signature : (Lkotlin/jvm/functions/Function0;)V (sig_str_idx=1436)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_47_0x0c500(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 47U, args, 4U);
}

// ============================================================================
// Method [48] @ 0x0c720..0x0c924 (516 bytes)
// Class     : com/vega/launcher/network/interceptors/CrackingInterceptor (Class [14], class_id=204)
// Method    : d (name_str_idx=696)
// Signature : (Ljava/lang/String;)V (sig_str_idx=1640)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_48_0x0c720(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 48U, args, 4U);
}

// ============================================================================
// Method [49] @ 0x0c924..0x0cb90 (620 bytes)
// Class     : com/vega/launcher/network/interceptors/CrackingInterceptor (Class [14], class_id=204)
// Method    : intercept (name_str_idx=821)
// Signature : (Lcom/bytedance/retrofit2/intercept/Interceptor$Chain;)Lcom/bytedance/retrofit2/SsResponse; (sig_str_idx=1394)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_49_0x0c924(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 49U, args, 4U);
}

// ============================================================================
// Method [50] @ 0x0cb90..0x0ce48 (696 bytes)
// Class     : com/vega/subscribe/SubscribeImpl (Class [15], class_id=221)
// Method    : b (name_str_idx=647)
// Signature : (Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V (sig_str_idx=1770)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_50_0x0cb90(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 50U, args, 4U);
}

// ============================================================================
// Method [51] @ 0x0ce48..0x0d0c0 (632 bytes)
// Class     : com/vega/subscribe/SubscribeImpl (Class [15], class_id=221)
// Method    : f (name_str_idx=732)
// Signature : (ZLjava/lang/String;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1112)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_51_0x0ce48(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 51U, args, 4U);
}

// ============================================================================
// Method [52] @ 0x0d0c0..0x0d2dc (540 bytes)
// Class     : com/vega/subscribe/SubscribeImpl (Class [15], class_id=221)
// Method    : h (name_str_idx=801)
// Signature : (Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1788)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_52_0x0d0c0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 52U, args, 4U);
}

// ============================================================================
// Method [53] @ 0x0d2dc..0x0d57c (672 bytes)
// Class     : com/vega/subscribe/SubscriptionUserInfoExtKt (Class [16], class_id=223)
// Method    : a (name_str_idx=624)
// Signature : (Lcom/vega/subscribe/api/SubscriptionUserInfo;)Lcom/vega/subscribe/VipSubscribeManager$VipStatus; (sig_str_idx=1614)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_53_0x0d2dc(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 53U, args, 4U);
}

// ============================================================================
// Method [54] @ 0x0d57c..0x0d85c (736 bytes)
// Class     : com/vega/subscribe/VipSubscribeManager (Class [17], class_id=225)
// Method    : b (name_str_idx=647)
// Signature : (Lcom/lemon/lv/clipmonetize/data/UserLiteInfo;Lkotlin/jvm/functions/Function1;Lkotlin/jvm/functions/Function0;)V (sig_str_idx=1770)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_54_0x0d57c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 54U, args, 4U);
}

// ============================================================================
// Method [55] @ 0x0d85c..0x0dae0 (644 bytes)
// Class     : com/vega/subscribe/VipSubscribeManager (Class [17], class_id=225)
// Method    : g (name_str_idx=743)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_55_0x0d85c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 55U, args, 4U);
}

// ============================================================================
// Method [56] @ 0x0dae0..0x0dd28 (584 bytes)
// Class     : com/vega/subscribe/api/SubscriptionUserInfo (Class [18], class_id=226)
// Method    : f (name_str_idx=732)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_56_0x0dae0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 56U, args, 4U);
}

// ============================================================================
// Method [57] @ 0x0dd28..0x0dfa8 (640 bytes)
// Class     : com/vega/subscription/biz/checker/BusinessTemplateExportChecker (Class [19], class_id=232)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_57_0x0dd28(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 57U, args, 4U);
}

// ============================================================================
// Method [58] @ 0x0dfa8..0x0e250 (680 bytes)
// Class     : com/vega/subscription/biz/checker/BusinessTemplateUnlockDraftChecker (Class [20], class_id=235)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_58_0x0dfa8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 58U, args, 4U);
}

// ============================================================================
// Method [59] @ 0x0e250..0x0e4c0 (624 bytes)
// Class     : com/vega/subscription/biz/checker/ExportTrialStrategyChecker (Class [21], class_id=239)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_59_0x0e250(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 59U, args, 4U);
}

// ============================================================================
// Method [60] @ 0x0e4c0..0x0e7ac (748 bytes)
// Class     : com/vega/subscription/biz/checker/GeneralUnlockDraftChecker (Class [22], class_id=244)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_60_0x0e4c0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 60U, args, 4U);
}

// ============================================================================
// Method [61] @ 0x0e7ac..0x0ea44 (664 bytes)
// Class     : com/vega/subscription/biz/checker/GeneralUnlockDraftChecker (Class [22], class_id=244)
// Method    : g (name_str_idx=743)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1217)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_61_0x0e7ac(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 61U, args, 4U);
}

// ============================================================================
// Method [62] @ 0x0ea44..0x0ec80 (572 bytes)
// Class     : com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker (Class [30], class_id=287)
// Method    : i (name_str_idx=813)
// Signature : (Lcom/vega/subscription/biz/checker/base/BaseGoodsAccessChecker;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1377)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_62_0x0ea44(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 62U, args, 4U);
}

// ============================================================================
// Method [63] @ 0x0ec80..0x0ef10 (656 bytes)
// Class     : com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker (Class [30], class_id=287)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1217)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_63_0x0ec80(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 63U, args, 4U);
}

// ============================================================================
// Method [64] @ 0x0ef10..0x0f15c (588 bytes)
// Class     : com/vega/subscription/biz/checker/base/BaseGoodsAccessChecker (Class [30], class_id=287)
// Method    : l (name_str_idx=852)
// Signature : (Lcom/lemon/lv/clipmonetize/wrapper/BenefitResource;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1593)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_64_0x0ef10(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 64U, args, 4U);
}

// ============================================================================
// Method [65] @ 0x0f15c..0x0f3a0 (580 bytes)
// Class     : com/vega/subscription/biz/checker/GoodsAccessChecker (Class [23], class_id=248)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_65_0x0f15c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 65U, args, 4U);
}

// ============================================================================
// Method [66] @ 0x0f3a0..0x0f610 (624 bytes)
// Class     : com/vega/subscription/biz/checker/TemplateBreakWhenExpiredChecker (Class [24], class_id=250)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_66_0x0f3a0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 66U, args, 4U);
}

// ============================================================================
// Method [67] @ 0x0f610..0x0f85c (588 bytes)
// Class     : com/vega/subscription/biz/checker/TemplateBreakWhenLaunchChecker (Class [25], class_id=252)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_67_0x0f610(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 67U, args, 4U);
}

// ============================================================================
// Method [68] @ 0x0f85c..0x0fac4 (616 bytes)
// Class     : com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker (Class [26], class_id=255)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_68_0x0f85c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 68U, args, 4U);
}

// ============================================================================
// Method [69] @ 0x0fac4..0x0fd70 (684 bytes)
// Class     : com/vega/subscription/biz/checker/TemplateBreakWhenNormalChecker (Class [26], class_id=255)
// Method    : k (name_str_idx=850)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/feedx/main/bean/FeedItem;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1183)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_69_0x0fac4(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 69U, args, 4U);
}

// ============================================================================
// Method [70] @ 0x0fd70..0x10044 (724 bytes)
// Class     : com/vega/subscription/biz/checker/VipExportChecker (Class [27], class_id=268)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_70_0x0fd70(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 70U, args, 4U);
}

// ============================================================================
// Method [71] @ 0x10044..0x102d0 (652 bytes)
// Class     : com/vega/subscription/biz/checker/VipExportChecker (Class [27], class_id=268)
// Method    : f (name_str_idx=732)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;Lcom/vega/subscription/core/checker/CheckResult;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1217)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_71_0x10044(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 71U, args, 4U);
}

// ============================================================================
// Method [72] @ 0x102d0..0x1053c (620 bytes)
// Class     : com/vega/subscription/biz/checker/VipFeaturePayChecker (Class [28], class_id=271)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_72_0x102d0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 72U, args, 4U);
}

// ============================================================================
// Method [73] @ 0x1053c..0x107fc (704 bytes)
// Class     : com/vega/subscription/biz/checker/VipFeatureUseChecker (Class [29], class_id=278)
// Method    : e (name_str_idx=708)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;ZLkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1515)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_73_0x1053c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 73U, args, 4U);
}

// ============================================================================
// Method [74] @ 0x107fc..0x10ab0 (692 bytes)
// Class     : com/vega/subscription/core/function/BaseBusinessFunction (Class [35], class_id=321)
// Method    : O3 (name_str_idx=564)
// Signature : (Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job; (sig_str_idx=1439)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_74_0x107fc(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 74U, args, 4U);
}

// ============================================================================
// Method [75] @ 0x10ab0..0x10d10 (608 bytes)
// Class     : com/vega/subscription/biz/function/base/BaseAIFeatureFunction (Class [31], class_id=297)
// Method    : m4 (name_str_idx=870)
// Signature : (Lcom/vega/subscriptionapi/biz/function/AIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job; (sig_str_idx=1448)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_75_0x10ab0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 75U, args, 4U);
}

// ============================================================================
// Method [76] @ 0x10d10..0x10f5c (588 bytes)
// Class     : com/vega/subscription/biz/function/base/BaseMultiAIFeatureFunction (Class [32], class_id=299)
// Method    : m4 (name_str_idx=870)
// Signature : (Lcom/vega/subscriptionapi/biz/function/MultiAIFeatureFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job; (sig_str_idx=1040)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_76_0x10d10(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 76U, args, 4U);
}

// ============================================================================
// Method [77] @ 0x10f5c..0x111cc (624 bytes)
// Class     : com/vega/subscription/core/checker/BusinessCheckerCollectionHelper (Class [33], class_id=306)
// Method    : a (name_str_idx=624)
// Signature : (Lcom/vega/subscription/core/checker/CheckerContext;Ljava/util/List;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1607)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_77_0x10f5c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 77U, args, 4U);
}

// ============================================================================
// Method [78] @ 0x111cc..0x1143c (624 bytes)
// Class     : com/vega/subscription/core/function/BaseBusinessCheckerFunction (Class [34], class_id=319)
// Method    : O3 (name_str_idx=564)
// Signature : (Lcom/vega/subscriptionapi/core/IBusinessFunctionParam;Lkotlin/jvm/functions/Function1;)Lkotlinx/coroutines/Job; (sig_str_idx=1439)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_78_0x111cc(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 78U, args, 4U);
}

// ============================================================================
// Method [79] @ 0x1143c..0x116b8 (636 bytes)
// Class     : com/vega/subscription/legacy/attachment/BaseNewBusinessImpl (Class [36], class_id=323)
// Method    : E (name_str_idx=50)
// Signature : ()Ljava/util/List; (sig_str_idx=1742)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_79_0x1143c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 79U, args, 4U);
}

// ============================================================================
// Method [80] @ 0x116b8..0x1194c (660 bytes)
// Class     : com/vega/subscription/legacy/attachment/BaseNewBusinessImpl (Class [36], class_id=323)
// Method    : p (name_str_idx=902)
// Signature : (Z)Ljava/util/List; (sig_str_idx=1569)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_80_0x116b8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 80U, args, 4U);
}

// ============================================================================
// Method [81] @ 0x1194c..0x11bd4 (648 bytes)
// Class     : com/vega/subscription/legacy/attachment/BaseNewBusinessImpl (Class [36], class_id=323)
// Method    : r (name_str_idx=917)
// Signature : (Lcom/vega/middlebridge/swig/AttachmentVipFeature;)V (sig_str_idx=1402)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_81_0x1194c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 81U, args, 4U);
}

// ============================================================================
// Method [82] @ 0x11bd4..0x11e0c (568 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : a (name_str_idx=624)
// Signature : (Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1754)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_82_0x11bd4(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 82U, args, 4U);
}

// ============================================================================
// Method [83] @ 0x11e0c..0x120c8 (700 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : b (name_str_idx=647)
// Signature : (Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1754)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_83_0x11e0c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 83U, args, 4U);
}

// ============================================================================
// Method [84] @ 0x120c8..0x1236c (676 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : c (name_str_idx=661)
// Signature : (Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1754)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_84_0x120c8(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 84U, args, 4U);
}

// ============================================================================
// Method [85] @ 0x1236c..0x1263c (720 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : d (name_str_idx=696)
// Signature : (Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1754)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_85_0x1236c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 85U, args, 4U);
}

// ============================================================================
// Method [86] @ 0x1263c..0x1289c (608 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : e (name_str_idx=708)
// Signature : (Lkotlin/jvm/functions/Function1;)V (sig_str_idx=1754)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_86_0x1263c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 86U, args, 4U);
}

// ============================================================================
// Method [87] @ 0x1289c..0x12b6c (720 bytes)
// Class     : com/vega/subscriptionapi/core/Result (Class [37], class_id=356)
// Method    : f (name_str_idx=732)
// Signature : (Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object; (sig_str_idx=1376)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_87_0x1289c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 87U, args, 4U);
}

// ============================================================================
// Method [88] @ 0x12b6c..0x12e04 (664 bytes)
// Class     : com/vega/subscriptionapi/legacy/data/ResourceData (Class [38], class_id=361)
// Method    : a (name_str_idx=624)
// Signature : ()Ljava/lang/String; (sig_str_idx=1403)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_88_0x12b6c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 88U, args, 4U);
}

// ============================================================================
// Method [89] @ 0x12e04..0x140a0 (4764 bytes)
// Class     : com/vega/subscriptionapi/legacy/data/TemplateCombineIdsResponse (Class [39], class_id=362)
// Method    : a (name_str_idx=624)
// Signature : ()Ljava/util/List; (sig_str_idx=1742)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_89_0x12e04(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 89U, args, 4U);
}

// ============================================================================
// Method [90] @ 0x140a0..0x1430c (620 bytes)
// Class     : com/vega/subscriptionapi/legacy/data/VipScene (Class [40], class_id=364)
// Method    : b (name_str_idx=647)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_90_0x140a0(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 90U, args, 4U);
}

// ============================================================================
// Method [91] @ 0x1430c..0x1459c (656 bytes)
// Class     : com/vega/subscriptionapi/legacy/data/VipScene (Class [40], class_id=364)
// Method    : c (name_str_idx=661)
// Signature : ()Z (sig_str_idx=1694)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_91_0x1430c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 91U, args, 4U);
}

// ============================================================================
// Method [92] @ 0x1459c..0x14838 (668 bytes)
// Class     : com/vega/util/WindowUtilsKt (Class [41], class_id=376)
// Method    : a (name_str_idx=624)
// Signature : (Landroid/view/Window;Z)V (sig_str_idx=1157)
// Opcodes   : 0xa9ba6ffc, 0xa90167fa, 0xa9025ff8, 0xa90357f6
// ============================================================================
uint64_t LusterJniMethod_92_0x1459c(JNIEnv* env, jobject obj, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) noexcept {
    const uint64_t args[4] = { a0, a1, a2, a3 };
    return InvokeLusterVirtualizedMethod(env, obj, 92U, args, 4U);
}

namespace {

using LusterGenericMethodFn = uint64_t (*)(JNIEnv*, jobject, uint64_t, uint64_t, uint64_t, uint64_t) noexcept;

const LusterGenericMethodFn kLusterMethodFnTable[kLusterVirtualizedMethodCount] = {

    &LusterJniMethod_00_0x050a0,
    &LusterJniMethod_01_0x05328,
    &LusterJniMethod_02_0x055dc,
    &LusterJniMethod_03_0x058a8,
    &LusterJniMethod_04_0x05b20,
    &LusterJniMethod_05_0x05d84,
    &LusterJniMethod_06_0x06020,
    &LusterJniMethod_07_0x062e8,
    &LusterJniMethod_08_0x065a0,
    &LusterJniMethod_09_0x06880,
    &LusterJniMethod_10_0x06b4c,
    &LusterJniMethod_11_0x06d6c,
    &LusterJniMethod_12_0x06fcc,
    &LusterJniMethod_13_0x0727c,
    &LusterJniMethod_14_0x07510,
    &LusterJniMethod_15_0x07768,
    &LusterJniMethod_16_0x079f4,
    &LusterJniMethod_17_0x07c3c,
    &LusterJniMethod_18_0x07e6c,
    &LusterJniMethod_19_0x08130,
    &LusterJniMethod_20_0x083b0,
    &LusterJniMethod_21_0x0863c,
    &LusterJniMethod_22_0x088a8,
    &LusterJniMethod_23_0x08b50,
    &LusterJniMethod_24_0x08da8,
    &LusterJniMethod_25_0x08ff0,
    &LusterJniMethod_26_0x09290,
    &LusterJniMethod_27_0x094e4,
    &LusterJniMethod_28_0x09700,
    &LusterJniMethod_29_0x09950,
    &LusterJniMethod_30_0x09c00,
    &LusterJniMethod_31_0x09e68,
    &LusterJniMethod_32_0x0a090,
    &LusterJniMethod_33_0x0a2f0,
    &LusterJniMethod_34_0x0a53c,
    &LusterJniMethod_35_0x0a7c0,
    &LusterJniMethod_36_0x0aa70,
    &LusterJniMethod_37_0x0acec,
    &LusterJniMethod_38_0x0af6c,
    &LusterJniMethod_39_0x0b214,
    &LusterJniMethod_40_0x0b4d4,
    &LusterJniMethod_41_0x0b780,
    &LusterJniMethod_42_0x0ba1c,
    &LusterJniMethod_43_0x0bc08,
    &LusterJniMethod_44_0x0be24,
    &LusterJniMethod_45_0x0c08c,
    &LusterJniMethod_46_0x0c2e0,
    &LusterJniMethod_47_0x0c500,
    &LusterJniMethod_48_0x0c720,
    &LusterJniMethod_49_0x0c924,
    &LusterJniMethod_50_0x0cb90,
    &LusterJniMethod_51_0x0ce48,
    &LusterJniMethod_52_0x0d0c0,
    &LusterJniMethod_53_0x0d2dc,
    &LusterJniMethod_54_0x0d57c,
    &LusterJniMethod_55_0x0d85c,
    &LusterJniMethod_56_0x0dae0,
    &LusterJniMethod_57_0x0dd28,
    &LusterJniMethod_58_0x0dfa8,
    &LusterJniMethod_59_0x0e250,
    &LusterJniMethod_60_0x0e4c0,
    &LusterJniMethod_61_0x0e7ac,
    &LusterJniMethod_62_0x0ea44,
    &LusterJniMethod_63_0x0ec80,
    &LusterJniMethod_64_0x0ef10,
    &LusterJniMethod_65_0x0f15c,
    &LusterJniMethod_66_0x0f3a0,
    &LusterJniMethod_67_0x0f610,
    &LusterJniMethod_68_0x0f85c,
    &LusterJniMethod_69_0x0fac4,
    &LusterJniMethod_70_0x0fd70,
    &LusterJniMethod_71_0x10044,
    &LusterJniMethod_72_0x102d0,
    &LusterJniMethod_73_0x1053c,
    &LusterJniMethod_74_0x107fc,
    &LusterJniMethod_75_0x10ab0,
    &LusterJniMethod_76_0x10d10,
    &LusterJniMethod_77_0x10f5c,
    &LusterJniMethod_78_0x111cc,
    &LusterJniMethod_79_0x1143c,
    &LusterJniMethod_80_0x116b8,
    &LusterJniMethod_81_0x1194c,
    &LusterJniMethod_82_0x11bd4,
    &LusterJniMethod_83_0x11e0c,
    &LusterJniMethod_84_0x120c8,
    &LusterJniMethod_85_0x1236c,
    &LusterJniMethod_86_0x1263c,
    &LusterJniMethod_87_0x1289c,
    &LusterJniMethod_88_0x12b6c,
    &LusterJniMethod_89_0x12e04,
    &LusterJniMethod_90_0x140a0,
    &LusterJniMethod_91_0x1430c,
    &LusterJniMethod_92_0x1459c,
};

} // namespace

void* GetLusterJniMethodFunctionPointer(uint32_t method_index) noexcept {
    if (method_index >= kLusterVirtualizedMethodCount) {
        return nullptr;
    }
    return reinterpret_cast<void*>(kLusterMethodFnTable[method_index]);
}

} // namespace luster
} // namespace opencut
} // namespace nextai
