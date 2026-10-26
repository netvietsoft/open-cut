// ==============================================================================
// FILE: TTMachineCore_interface.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Unified Public C++17 Interface & Facade Engine for TTMachineCore VM
//          (Giao diện C++17 công khai hợp nhất & Engine Facade cho máy ảo TTMachineCore)
// EVIDENCE CLASSIFICATION: OBSERVED (ELF64 .dynsym + .rodata + .data.rel.ro + .data)
// ==============================================================================

#pragma once

#include "ttmachinecore_types.h"
#include "ttmachinecore_objects_hashmap.h"
#include "ttmachinecore_vm_bytecode.h"
#include "ttmachinecore_bdi_bridges.h"
#include "ttmachinecore_extdata_cjson_jni.h"

namespace NextAI::OpenCut::TTMachineCore {

/**
 * [EN] Unified facade orchestrating all four native subsystems of libTTMachineCore.so:
 *      1. 73-State Register-Based Bytecode Virtual Machine (`ttm_travel` @ `0x1bb64`,
 *         `pre_process_byte_code` @ `0x1a700`, `state_code_names` @ `0x6a268`)
 *      2. 8 Built-in `TTMTypeObject` Descriptors (`0x6c048..0x6c588`), Arena Allocator,
 *         and SipHash-2-4 / MurmurHash3 Open-Addressing Hashmap (`0x1aa34..0x25cf0`)
 *      3. Universal BDI Function Loaders (`TTMUniversalBdiFunLoader` @ `0x2869c`,
 *         `AnTTMUniversalBdiFunLoader` @ `0x44208`) and Keva KV (`ttm_core_repo`) Bridges
 *      4. External Data Interfaces (`ITTMExtDataBdi`, `TTMExtJsonDataBdi`, `TTMExtJavaDataBdi`,
 *         `TTMExtDataDelegate`), `cJSON` Engine, and 19 JNI Methods (`0x6a8f0` & `0x6a9e0`)
 *
 * [VN] Lớp Facade hợp nhất điều phối cả 4 phân hệ native của libTTMachineCore.so:
 *      1. Máy ảo thực thi Bytecode 73 trạng thái thanh ghi (`ttm_travel` @ `0x1bb64`,
 *         `pre_process_byte_code` @ `0x1a700`, `state_code_names` @ `0x6a268`)
 *      2. 8 Bộ mô tả kiểu `TTMTypeObject` (`0x6c048..0x6c588`), Bộ cấp phát Arena,
 *         và Bảng băm SipHash-2-4 / MurmurHash3 (`0x1aa34..0x25cf0`)
 *      3. Bộ nạp hàm BDI vạn năng (`TTMUniversalBdiFunLoader` @ `0x2869c`,
 *         `AnTTMUniversalBdiFunLoader` @ `0x44208`) và cầu nối Keva KV (`ttm_core_repo`)
 *      4. Giao diện dữ liệu mở rộng (`ITTMExtDataBdi`, `TTMExtJsonDataBdi`, `TTMExtJavaDataBdi`,
 *         `TTMExtDataDelegate`), bộ phân tích `cJSON`, và 19 hàm JNI (`0x6a8f0` & `0x6a9e0`)
 */
class TtmachinecoreEngine {
public:
    TtmachinecoreEngine();
    virtual ~TtmachinecoreEngine();

    bool Initialize();
    void Shutdown();

    std::int32_t ExecuteBytecode(
        const std::vector<std::uint8_t>& bytecode,
        TTMRegisterSlot& out_result);

    std::int32_t FormatBusinessErrorCode(std::int32_t base_code, std::int32_t sub_code) const noexcept;

private:
    bool initialized_{false};
};

} // namespace NextAI::OpenCut::TTMachineCore
