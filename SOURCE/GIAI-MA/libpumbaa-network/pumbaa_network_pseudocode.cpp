/**
 * @file pumbaa_network_pseudocode.cpp
 * @brief Complete AArch64 instruction-level reconstruction, `.rela.dyn` (19 relocations),
 *        `.rela.plt` (39 relocations), `.rodata` string & jump tables (`0x006df0..0x007114`),
 *        and `RunLibPumbaaNetworkSelfTest()` for `libpumbaa-network.so` (`51,232 bytes`).
 *        Tái dựng toàn diện ở cấp độ lệnh AArch64, `.rela.dyn` (19 mục), `.rela.plt` (39 mục),
 *        bảng chuỗi & bảng nhảy `.rodata` (`0x006df0..0x007114`), và `RunLibPumbaaNetworkSelfTest()`
 *        cho `libpumbaa-network.so` (`51,232 byte`).
 */

#include "pumbaa_network_interface.h"
#include "pumbaa_network_rbtree_dwarf.h"
#include "pumbaa_network_sandbox_jni.h"
#include "pumbaa_network_types.h"

#include <array>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. Complete `.rela.dyn` Relocation Table (`0x001658..0x00181f`, 19 Entries)
//    Bảng Tái định vị Động `.rela.dyn` Hoàn chỉnh (`0x001658..0x00181f`, 19 Mục)
// ============================================================================

struct RelaDynDescriptor {
    uint32_t    index;
    uint32_t    r_offset;
    uint32_t    r_type;
    const char* symbol_name;
    uint32_t    r_addend;
    const char* role_en_vn;
};

constexpr std::array<RelaDynDescriptor, 19> kRelaDynTable = {{
    {0u,  0x00fc08u, 1027u, "", 0x001e70u, ".fini_array[0] -> 0x001e70 / Mục .fini_array[0]"},
    {1u,  0x00fc10u, 1027u, "", 0x001e60u, ".fini_array[1] -> 0x001e60 (__cxa_finalize) / Mục .fini_array[1]"},
    {2u,  0x00fc18u, 1027u, "", 0x00fc18u, "__dso_handle self-pointer @ 0x00fc18 / Tự tham chiếu __dso_handle"},
    {3u,  0x00ff88u, 1025u, "gMethodMonitorCost", 0u, "GOT slot for gMethodMonitorCost (0x010040) / Khe GOT của gMethodMonitorCost"},
    {4u,  0x00ff90u, 1025u, "gNetworkDomainRecognize", 0u, "GOT slot for gNetworkDomainRecognize (0x010018) / Khe GOT của gNetworkDomainRecognize"},
    {5u,  0x00ff98u, 1025u, "gMethodPut", 0u, "GOT slot for gMethodPut (0x010058) / Khe GOT của gMethodPut"},
    {6u,  0x00ffa0u, 1025u, "_ZNSt12length_errorD1Ev", 0u, "GOT slot for std::length_error::~length_error() / Khe GOT hàm hủy length_error"},
    {7u,  0x00ffa8u, 1025u, "gMethodHandleFromNativeSandbox", 0u, "GOT slot for gMethodHandleFromNativeSandbox (0x010020) / Khe GOT của gMethodHandleFromNativeSandbox"},
    {8u,  0x00ffb0u, 1025u, "gMethodDomainIdentityRecognize", 0u, "GOT slot for gMethodDomainIdentityRecognize (0x010030) / Khe GOT của gMethodDomainIdentityRecognize"},
    {9u,  0x00ffb8u, 1025u, "gJvm", 0u, "GOT slot for gJvm (0x010060) / Khe GOT của gJvm"},
    {10u, 0x00ffc0u, 1025u, "gMethodHandleFromNativeSandboxJson", 0u, "GOT slot for gMethodHandleFromNativeSandboxJson (0x010028) / Khe GOT của gMethodHandleFromNativeSandboxJson"},
    {11u, 0x00ffc8u, 1025u, "_ZTISt12length_error", 0u, "GOT slot for typeinfo of std::length_error / Khe GOT typeinfo length_error"},
    {12u, 0x00ffd0u, 1025u, "_ZTVSt12length_error", 0u, "GOT slot for vtable of std::length_error / Khe GOT vtable length_error"},
    {13u, 0x00ffd8u, 1025u, "pthread_create", 0u, "GOT slot for weak pthread_create check / Khe GOT kiểm tra pthread_create"},
    {14u, 0x00ffe0u, 1025u, "gMethodMatchAgSchema", 0u, "GOT slot for gMethodMatchAgSchema (0x010038) / Khe GOT của gMethodMatchAgSchema"},
    {15u, 0x00ffe8u, 1025u, "gClassNativeBridge", 0u, "GOT slot for gClassNativeBridge (0x010010) / Khe GOT của gClassNativeBridge"},
    {16u, 0x00fff0u, 1025u, "gClassHashMap", 0u, "GOT slot for gClassHashMap (0x010048) / Khe GOT của gClassHashMap"},
    {17u, 0x00fff8u, 1025u, "gMethodHashMapConstructor", 0u, "GOT slot for gMethodHashMapConstructor (0x010050) / Khe GOT của gMethodHashMapConstructor"},
    {18u, 0x010000u, 257u,  "__gxx_personality_v0", 0u, "Absolute pointer to __gxx_personality_v0 at .data 0x010000 / Con trỏ __gxx_personality_v0"},
}};

// ============================================================================
// 2. Complete `.rela.plt` Jump Slot Table (`0x001820..0x001bc7`, 39 Entries)
//    Bảng Khe Nhảy `.rela.plt` Hoàn chỉnh (`0x001820..0x001bc7`, 39 Mục)
// ============================================================================

struct PltEntryDescriptor {
    uint32_t    plt_index;
    uint32_t    plt_vaddr;
    uint32_t    got_vaddr;
    const char* symbol_name;
};

constexpr std::array<PltEntryDescriptor, 39> kPltDescriptorTable = {{
    {0u,  0x001bf0u, 0x00fe48u, "memcpy"},
    {1u,  0x001c00u, 0x00fe50u, "gettimeofday"},
    {2u,  0x001c10u, 0x00fe58u, "_ZdlPv"},
    {3u,  0x001c20u, 0x00fe60u, "_ZNSt11logic_errorC2EPKc"},
    {4u,  0x001c30u, 0x00fe68u, "jni_convertMap"},
    {5u,  0x001c40u, 0x00fe70u, "_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_"},
    {6u,  0x001c50u, 0x00fe78u, "__cxa_allocate_exception"},
    {7u,  0x001c60u, 0x00fe80u, "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE30__emplace_hint_unique_key_argsIS7_JRKNS_4pairIKS7_S7_EEEEENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEENS_21__tree_const_iteratorIS8_SP_lEERKT_DpOT0_"},
    {8u,  0x001c70u, 0x00fe88u, "free"},
    {9u,  0x001c80u, 0x00fe90u, "malloc"},
    {10u, 0x001c90u, 0x00fe98u, "pthread_once"},
    {11u, 0x001ca0u, 0x00fea0u, "strlen"},
    {12u, 0x001cb0u, 0x00fea8u, "_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz"},
    {13u, 0x001cc0u, 0x00feb0u, "_ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz"},
    {14u, 0x001cd0u, 0x00feb8u, "_ZNSt6__ndk127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_"},
    {15u, 0x001ce0u, 0x00fec0u, "__android_log_print"},
    {16u, 0x001cf0u, 0x00fec8u, "pthread_mutex_unlock"},
    {17u, 0x001d00u, 0x00fed0u, "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE7destroyEPNS_11__tree_nodeIS8_PvEE"},
    {18u, 0x001d10u, 0x00fed8u, "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISJ_EERKT_"},
    {19u, 0x001d20u, 0x00fee0u, "_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz"},
    {20u, 0x001d30u, 0x00fee8u, "_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz"},
    {21u, 0x001d40u, 0x00fef0u, "memset"},
    {22u, 0x001d50u, 0x00fef8u, "__gxx_personality_v0"},
    {23u, 0x001d60u, 0x00ff00u, "abort"},
    {24u, 0x001d70u, 0x00ff08u, "__cxa_throw"},
    {25u, 0x001d80u, 0x00ff10u, "__cxa_atexit"},
    {26u, 0x001d90u, 0x00ff18u, "_Z11monitorCostPKcx"},
    {27u, 0x001da0u, 0x00ff20u, "memcmp"},
    {28u, 0x001db0u, 0x00ff28u, "_ZNSt6__ndk16chrono12steady_clock3nowEv"},
    {29u, 0x001dc0u, 0x00ff30u, "pthread_mutex_lock"},
    {30u, 0x001dd0u, 0x00ff38u, "_Znwm"},
    {31u, 0x001de0u, 0x00ff40u, "__cxa_finalize"},
    {32u, 0x001df0u, 0x00ff48u, "_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz"},
    {33u, 0x001e00u, 0x00ff50u, "__stack_chk_fail"},
    {34u, 0x001e10u, 0x00ff58u, "_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz"},
    {35u, 0x001e20u, 0x00ff60u, "dl_iterate_phdr"},
    {36u, 0x001e30u, 0x00ff68u, "_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv"},
    {37u, 0x001e40u, 0x00ff70u, "__cxa_free_exception"},
    {38u, 0x001e50u, 0x00ff78u, "_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_"},
}};

// ============================================================================
// 3. Verified AArch64 Opcode Matrix (`0x001e60..0x0038ac`)
//    Ma trận Đối soát Mã máy AArch64 (`0x001e60..0x0038ac`)
// ============================================================================

struct AArch64OpcodeEntry {
    uint32_t    vaddr;
    uint32_t    opcode_le;
    const char* mnemonic;
    const char* description_en_vn;
};

constexpr std::array<AArch64OpcodeEntry, 48> kVerifiedOpcodes = {{
    {0x001e9cu, 0xd10143ffu, "sub sp, sp, #0x50", "JNI_OnLoad prologue (80B stack frame) / Mở đầu JNI_OnLoad (khung stack 80B)"},
    {0x001ebcu, 0x52800042u, "mov w2, #2", "Low 16 bits of JNI_VERSION_1_2 (0x00010002) / 16 bit thấp của JNI_VERSION_1_2"},
    {0x001ed0u, 0x72a00022u, "movk w2, #1, lsl #16", "High 16 bits of JNI_VERSION_1_2 (0x00010002) / 16 bit cao của JNI_VERSION_1_2"},
    {0x001edcu, 0xf9401908u, "ldr x8, [x8, #0x30]", "Load JavaVM::GetEnv (offset +0x30) / Đọc con trỏ hàm GetEnv"},
    {0x001f24u, 0x9137c021u, "add x1, x1, #0xdf0", "Load \"com/bytedance/helios/network/SandboxBridge\" (.rodata 0x006df0) / Nạp tên lớp SandboxBridge"},
    {0x001f44u, 0x91386c21u, "add x1, x1, #0xe1b", "Load \"com/bytedance/helios/network/pipeline/recognize/NetworkDomainRecognize\" (.rodata 0x006e1b)"},
    {0x001f74u, 0xf9405508u, "ldr x8, [x8, #0xa8]", "Load JNIEnv::NewGlobalRef (offset +0xa8) / Đọc NewGlobalRef"},
    {0x001fbcu, 0xf9405d29u, "ldr x9, [x9, #0xb8]", "Load JNIEnv::DeleteLocalRef (offset +0xb8) / Đọc DeleteLocalRef"},
    {0x001fe0u, 0xf941c508u, "ldr x8, [x8, #0x388]", "Load JNIEnv::GetStaticMethodID (offset +0x388) / Đọc GetStaticMethodID"},
    {0x002094u, 0x5a9f12c0u, "csinv w0, w22, wzr, ne", "Return 0x00010002 if gMethodMatchAgSchema != NULL else -1 / Trả về 0x00010002 hoặc -1"},
    {0x0020a0u, 0xa9bc5ff8u, "stp x24, x23, [sp, #-0x40]!", "jni_convertMap prologue / Mở đầu jni_convertMap"},
    {0x0020d4u, 0x913e8821u, "add x1, x1, #0xfa2", "Load \"java/util/HashMap\" (.rodata 0x006fa2) / Nạp tên lớp HashMap"},
    {0x002134u, 0xf9408508u, "ldr x8, [x8, #0x108]", "Load JNIEnv::GetMethodID (offset +0x108) / Đọc GetMethodID"},
    {0x00218cu, 0xb9401263u, "ldr w3, [x19, #0x10]", "Load std::map::size() at offset +0x10 / Đọc số phần tử map tại +0x10"},
    {0x0021c4u, 0x52800061u, "mov w1, #3", "Pass capacity 3 to JNIEnv::PushLocalFrame (offset +0x98) / Đẩy khung tham chiếu cục bộ 3"},
    {0x0021f8u, 0xf9429d08u, "ldr x8, [x8, #0x538]", "Load JNIEnv::NewStringUTF (offset +0x538) / Đọc NewStringUTF"},
    {0x002250u, 0xf9405108u, "ldr x8, [x8, #0xa0]", "Load JNIEnv::PopLocalFrame (offset +0xa0) / Đọc PopLocalFrame"},
    {0x0022f0u, 0x928004e8u, "mov x8, #-0x28", "Set AAPCS64 va_list __gr_offs = -40 / Đặt __gr_offs = -40"},
    {0x0022fcu, 0xf2dff008u, "movk x8, #0xff80, lsl #32", "Set AAPCS64 va_list __vr_offs = -128 / Đặt __vr_offs = -128"},
    {0x002328u, 0xf9407508u, "ldr x8, [x8, #0xe8]", "Load JNIEnv::NewObjectV (offset +0xe8) / Đọc NewObjectV"},
    {0x0023c4u, 0xf9408d08u, "ldr x8, [x8, #0x118]", "Load JNIEnv::CallObjectMethodV (offset +0x118) / Đọc CallObjectMethodV"},
    {0x0023f4u, 0xd10143ffu, "sub sp, sp, #0x50", "monitorCost(const char*, long long) prologue / Mở đầu monitorCost"},
    {0x0024f8u, 0x528000c0u, "mov w0, #6", "ANDROID_LOG_ERROR = 6 for __android_log_print(\"Pumbaa_Log\", \"env not init!\")"},
    {0x002598u, 0xf9423908u, "ldr x8, [x8, #0x470]", "Load JNIEnv::CallStaticVoidMethodV (offset +0x470) / Đọc CallStaticVoidMethodV"},
    {0x0025c8u, 0xd10103ffu, "sub sp, sp, #0x40", "domainIdentityRecognize prologue / Mở đầu domainIdentityRecognize"},
    {0x002680u, 0xf942a508u, "ldr x8, [x8, #0x548]", "Load JNIEnv::GetStringUTFChars (offset +0x548) / Đọc GetStringUTFChars"},
    {0x00278cu, 0xf941cd08u, "ldr x8, [x8, #0x398]", "Load JNIEnv::CallStaticObjectMethodV (offset +0x398) / Đọc CallStaticObjectMethodV"},
    {0x0027bcu, 0xd10383ffu, "sub sp, sp, #0xe0", "handleByPumbaaForSandbox prologue (224B stack frame) / Mở đầu handleByPumbaaForSandbox"},
    {0x0028b4u, 0xf9439508u, "ldr x8, [x8, #0x728]", "Load JNIEnv::NewDirectByteBuffer (offset +0x728) / Đọc NewDirectByteBuffer"},
    {0x002964u, 0x52800033u, "mov w19, #1", "Default fallback return value 1 when env is not initialized / Giá trị trả về mặc định 1"},
    {0x002b10u, 0xd29ef9eau, "mov x10, #0xf7cf", "Load magic multiplier +0x20c49ba5e353f7cf bits [15:0] / Nạp hằng số chia 1000"},
    {0x002b14u, 0xf2bc6a6au, "movk x10, #0xe353, lsl #16", "Load +0x20c49ba5e353f7cf bits [31:16]"},
    {0x002b18u, 0xf2d374aau, "movk x10, #0x9ba5, lsl #32", "Load +0x20c49ba5e353f7cf bits [47:32]"},
    {0x002b1cu, 0xf2e4188au, "movk x10, #0x20c4, lsl #48", "Load +0x20c49ba5e353f7cf bits [63:48]"},
    {0x002b20u, 0xd281062bu, "mov x11, #0x831", "Load negative magic multiplier 0xdf3b645a1cac0831 bits [15:0]"},
    {0x002b2cu, 0x9b4a7d08u, "smulh x8, x8, x10", "Signed high multiply tv_end.tv_usec * 0x20c49ba5e353f7cf"},
    {0x002b3cu, 0x9b4b7d8bu, "smulh x11, x12, x11", "Signed high multiply tv_start.tv_usec * (-0x20c49ba5e353f7cf)"},
    {0x002b54u, 0x52807d0au, "mov w10, #0x3e8", "Multiplier 1000 (0x3e8) for seconds-to-milliseconds / Hệ số 1000"},
    {0x002b60u, 0x9b0a2121u, "madd x1, x9, x10, x8", "cost_ms = (end_sec - start_sec) * 1000 + (end_usec/1000 - start_usec/1000)"},
    {0x002c18u, 0xf9420908u, "ldr x8, [x8, #0x410]", "Load JNIEnv::CallStaticIntMethodV (offset +0x410) / Đọc CallStaticIntMethodV"},
    {0x002c48u, 0xd10103ffu, "sub sp, sp, #0x40", "matchAgSchema prologue / Mở đầu matchAgSchema"},
    {0x002d18u, 0x72001c1fu, "tst w0, #0xff", "Test jboolean return value in matchAgSchema / Kiểm tra kết quả jboolean"},
    {0x002d6cu, 0xf941d908u, "ldr x8, [x8, #0x3b0]", "Load JNIEnv::CallStaticBooleanMethodV (offset +0x3b0) / Đọc CallStaticBooleanMethodV"},
    {0x002e44u, 0x52800a00u, "mov w0, #0x50", "Allocate 80-byte (0x50) RB-tree node in __emplace_hint_unique_key_args / Cấp phát nút 80B"},
    {0x003384u, 0xa9bd57f6u, "stp x22, x21, [sp, #-0x30]!", "std::string copy constructor prologue / Mở đầu hàm tạo sao chép std::string"},
    {0x003444u, 0xeb00003fu, "cmp x1, x0", "__tree_balance_after_insert root comparison / So sánh nút gốc khi cân bằng Cây Đỏ-Đen"},
    {0x003644u, 0xd2800002u, "mov x2, #0", "DecodeDwarfULEB128 entry / Điểm vào giải mã ULEB128"},
    {0x0037a0u, 0x52800100u, "mov w0, #8", "Initialize 8-byte register sizes in .bss 0x010070..0x0100d0 / Khởi tạo kích thước thanh ghi 8B"},
}};

// ============================================================================
// 4. End-to-End Runtime Self-Test (`RunLibPumbaaNetworkSelfTest`)
//    Hàm Tự Kiểm thử Thực thi Đầu-Cuối (`RunLibPumbaaNetworkSelfTest`)
// ============================================================================

bool RunLibPumbaaNetworkSelfTest() {
    ResetPumbaaNetworkBssState();

    // 1. Verify uninitialized fallback behavior (returns 1 in handleByPumbaaForSandbox, false in matchAgSchema)
    if (handleByPumbaaForSandbox("https://api.capcut.com/v1/test", "GET", nullptr, nullptr, 0, nullptr, nullptr) != 1 ||
        matchAgSchema("ag://open") != false ||
        domainIdentityRecognize("api.capcut.com") != nullptr) {
        return false;
    }

    // 2. Verify JNI_OnLoad (0x001e9c..0x00209f) returns JNI_VERSION_1_2 (0x00010002)
    //    and populates .bss 0x010010..0x010060 + DWARF register table at 0x010070..0x0100d0.
    if (JNI_OnLoad(nullptr, nullptr) != kJniVersion1_2) {
        return false;
    }
    const PumbaaNetworkBssSegment& bss = GetPumbaaNetworkBssState();
    if (bss.gClassNativeBridge == nullptr ||
        bss.gNetworkDomainRecognize == nullptr ||
        bss.gMethodHandleFromNativeSandbox == nullptr ||
        bss.gMethodHandleFromNativeSandboxJson == nullptr ||
        bss.gMethodDomainIdentityRecognize == nullptr ||
        bss.gMethodMatchAgSchema == nullptr ||
        bss.dwarf_reg_size_table[0] != 8u ||
        bss.dwarf_reg_size_table[31] != 8u ||
        bss.dwarf_reg_size_table[64] != 8u ||
        bss.dwarf_reg_size_table[96] != 8u) {
        return false;
    }

    // 3. Verify signed 64-bit reciprocal division-by-1000 math (0x002b10..0x002b60)
    if (MicrosToMillisMath::SignedDiv1000Positive(987654) != 987 ||
        MicrosToMillisMath::SignedDiv1000Negative(123456) != -123 ||
        MicrosToMillisMath::ComputeElapsedCostMs(10, 123456, 12, 987654) != 2864) {
        return false;
    }

    // 4. Verify RB-tree construction, handleByPumbaaForSandbox, domainIdentityRecognize, and matchAgSchema
    LibcxxMapStringAbi headers_tree{};
    headers_tree.begin_node = reinterpret_cast<RbTreeNodeStringPairAbi*>(&headers_tree.end_left);
    headers_tree.end_left   = nullptr;
    headers_tree.node_count = 0u;

    std::pair<LibcxxString24Abi, LibcxxString24Abi> kv{};
    LibcxxStringInitFromCStr(&kv.first, "User-Agent", 10u);
    LibcxxStringInitFromCStr(&kv.second, "NextAI-OpenCut-Engine-Benchmark-String-Long-Mode", 48u);
    RbTreeEmplaceHintUnique(&headers_tree, headers_tree.end_left, kv.first, kv);
    LibcxxStringDestroy(&kv.first);
    LibcxxStringDestroy(&kv.second);

    const int rc = handleByPumbaaForSandbox(
        "https://api.capcut.com/v1/feed", "POST", &headers_tree, nullptr, 128, nullptr, nullptr);
    RbTreeDestroy(&headers_tree, headers_tree.end_left);

    if (rc != 0 || !matchAgSchema("ag://route/video") || domainIdentityRecognize("api.capcut.com") == nullptr) {
        return false;
    }

    // 5. Verify DWARF ULEB128 & SLEB128 decoders (0x003644..0x0036a8)
    const uint8_t uleb_bytes[] = {0xE5u, 0x8Eu, 0x26u}; // 624485
    uint64_t uleb_val = 0u;
    DecodeDwarfULEB128(uleb_bytes, &uleb_val);

    const uint8_t sleb_bytes[] = {0xC0u, 0xBBu, 0x78u}; // -123456
    int64_t sleb_val = 0;
    DecodeDwarfSLEB128(sleb_bytes, &sleb_val);

    return uleb_val == 624485u &&
           sleb_val == -123456 &&
           kExportedDynSymTable.size() == 37u &&
           kRelaDynTable.size() == 19u &&
           kPltDescriptorTable.size() == 39u;
}

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai
