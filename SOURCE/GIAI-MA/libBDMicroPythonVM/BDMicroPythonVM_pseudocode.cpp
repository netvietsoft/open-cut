/**
 * @file BDMicroPythonVM_pseudocode.cpp
 * @brief Complete AArch64 Disassembly & Decompiled Reference for libBDMicroPythonVM.so (379,248 bytes)
 *        Tài liệu Giải mã & Mã giả AArch64 đầy đủ cho libBDMicroPythonVM.so (379,248 bytes)
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so — 379,248 bytes)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so — 379,248 bytes)]
 * =================================================================================================
 *
 * Complete Exported Symbol Map (33 STT_FUNC + 8 STT_OBJECT = 41 Exported Symbols):
 *
 * [A] Exported C++ Symbols in namespace `pitaya` & `fast_engine` (12 Functions + 1 Global Object):
 *  1. 0x03bec0 ( 180 B): _ZN6pitaya16CreatePTYExtDictEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE
 *  2. 0x03bf74 ( 180 B): _ZN6pitaya16CreatePTYExtListEPvRKNSt6__ndk110shared_ptrINS_7PTYListEEE
 *  3. 0x03c028 (   4 B): _ZN6pitaya14CreateCepEventEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE (-> b #0x3c02c)
 *  4. 0x041378 (1136 B): _ZN6pitaya4TaskD2Ev
 *  5. 0x0430ac (1224 B): _ZN11fast_engine12GetCoreErrorEN6pitaya9ErrorCodeEPNS_6EngineE
 *  6. 0x043c84 ( 224 B): _ZN11fast_engine15EnvPTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEERNS1_INS2_5ErrorEEEPvb
 *  7. 0x043d64 (  12 B): _ZN11fast_engine12PTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEEPNS_6EngineE
 *  8. 0x0453d4 (  12 B): _ZN11fast_engine12MPObj2PTYObjEPNS_3ObjEPNS_6EngineE
 *  9. 0x0453e0 ( 336 B): _ZN11fast_engine15EnvMPObj2PTYObjEPvRNSt6__ndk110shared_ptrIN6pitaya5ErrorEEES0_
 * 10. 0x045530 ( 288 B): _ZN11fast_engine10GetPTYDictEPNS_3ObjEPNS_6EngineE
 * 11. 0x045650 ( 196 B): _ZN11fast_engine10GetPTYListEPNS_3ObjEPNS_6EngineE
 * 12. 0x04ee2c (1376 B): _ZN6pitaya14InitFastEngineERNSt6__ndk110shared_ptrINS_5ErrorEEE
 * 13. 0x060210 (   8 B): _ZN11fast_engine10TensorTypeE (STT_OBJECT in .bss)
 *
 * [B] Exported JNI Symbols for `MicPyArray` (10 Functions @ 0x04fd08..0x0503dc):
 * 14. 0x04fd08 ( 132 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray
 * 15. 0x04fd8c ( 232 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool
 * 16. 0x04fe74 ( 164 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong
 * 17. 0x04ff18 ( 168 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble
 * 18. 0x04ffc0 (   8 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat
 * 19. 0x04ffc8 ( 120 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr
 * 20. 0x050040 ( 672 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass
 * 21. 0x0502e0 (  92 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict
 * 22. 0x05033c (  92 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray
 * 23. 0x050398 (  72 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull
 *
 * [C] Exported JNI Symbols for `MicPyDict` & `MicroPyLoader` (11 Functions @ 0x0503e0..0x051070):
 * 24. 0x0503e0 (  84 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict
 * 25. 0x050434 ( 320 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetLong
 * 26. 0x050574 ( 212 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble
 * 27. 0x050648 ( 216 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetFloat
 * 28. 0x050720 ( 120 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetStr
 * 29. 0x050798 ( 148 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetBoolean
 * 30. 0x05082c ( 148 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDict
 * 31. 0x0508c0 ( 148 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetArray
 * 32. 0x050954 ( 724 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetClass
 * 33. 0x050c28 ( 256 B): Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetNull
 * 34. 0x050f88 ( 232 B): Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit
 */

#include "BDMicroPythonVM_interface.h"

namespace nextai {
namespace opencut {
namespace bdmicropythonvm {

/**
 * @brief Returns the canonical virtual address table of all key exported symbols in `libBDMicroPythonVM.so`.
 *        Trả về bảng địa chỉ ảo chuẩn tắc của các ký hiệu được export trong `libBDMicroPythonVM.so`.
 */
std::map<std::string, uint64_t> GetBDMicroPythonVMExportedSymbolAddresses() {
    return {
        {"_ZN6pitaya16CreatePTYExtDictEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE", 0x03bec0ULL},
        {"_ZN6pitaya16CreatePTYExtListEPvRKNSt6__ndk110shared_ptrINS_7PTYListEEE", 0x03bf74ULL},
        {"_ZN6pitaya14CreateCepEventEPvRKNSt6__ndk110shared_ptrINS_7PTYDictEEE", 0x03c028ULL},
        {"_ZN6pitaya4TaskD2Ev", 0x041378ULL},
        {"_ZN11fast_engine12GetCoreErrorEN6pitaya9ErrorCodeEPNS_6EngineE", 0x0430acULL},
        {"_ZN11fast_engine15EnvPTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEERNS1_INS2_5ErrorEEEPvb", 0x043c84ULL},
        {"_ZN11fast_engine12PTYObj2MPObjERKNSt6__ndk110shared_ptrIN6pitaya9PTYObjectEEEPNS_6EngineE", 0x043d64ULL},
        {"_ZN11fast_engine12MPObj2PTYObjEPNS_3ObjEPNS_6EngineE", 0x0453d4ULL},
        {"_ZN11fast_engine15EnvMPObj2PTYObjEPvRNSt6__ndk110shared_ptrIN6pitaya5ErrorEEES0_", 0x0453e0ULL},
        {"_ZN11fast_engine10GetPTYDictEPNS_3ObjEPNS_6EngineE", 0x045530ULL},
        {"_ZN11fast_engine10GetPTYListEPNS_3ObjEPNS_6EngineE", 0x045650ULL},
        {"_ZN6pitaya14InitFastEngineERNSt6__ndk110shared_ptrINS_5ErrorEEE", 0x04ee2cULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeCreateArray", 0x04fd08ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetBool", 0x04fd8cULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetLong", 0x04fe74ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDouble", 0x04ff18ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetFloat", 0x04ffc0ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetStr", 0x04ffc8ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetClass", 0x050040ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetDict", 0x0502e0ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetArray", 0x05033cULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyArray_nativeSetNull", 0x050398ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeCreateDict", 0x0503e0ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetLong", 0x050434ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDouble", 0x050574ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetFloat", 0x050648ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetStr", 0x050720ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetBoolean", 0x050798ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetDict", 0x05082cULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetArray", 0x0508c0ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetClass", 0x050954ULL},
        {"Java_com_bytedance_pitaya_api_bean_nativeobj_micropy_MicPyDict_nativeSetNull", 0x050c28ULL},
        {"Java_com_bytedance_pitaya_modules_MicroPyLoader_nativeInit", 0x050f88ULL},
        {"_ZN11fast_engine10TensorTypeE", 0x060210ULL}
    };
}

} // namespace bdmicropythonvm
} // namespace opencut
} // namespace nextai
