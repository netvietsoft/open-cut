// ============================================================================
// File: orbuculum_bytecode_engine.h
// Target: liborbuculum.so (412,176 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for OrbuCodeEngine (init @ 0x0256fc,
//        destroy @ 0x0258c0, verifyCodeBlock @ 0x02598c, processRequest @ 0x025c58),
//        isNetworkInstruction (0x02527c), OrbuCodeCompare (0x02a664..0x02de80),
//        and FDEs 200..389.
//   [VN] Khai báo C++17 sạch cho bộ máy thực thi bytecode OrbuCodeEngine,
//        isNetworkInstruction (0x02527c), OrbuCodeCompare và FDE 200..389.
// ============================================================================

#pragma once

#include "orbuculum_types.h"

namespace ttp {
namespace orbuculum {
namespace engine {

bool IsNetworkInstructionExact(uint32_t opcode) noexcept;
uint32_t ComputeExecutedInstructionCountDiv24(int32_t byte_delta) noexcept;
bool VerifyOrbuCodeHeaderExact(const OrbuCodeStruct* header, uint32_t total_size) noexcept;

uint64_t DispatchBytecodeEngineFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace engine
} // namespace orbuculum
} // namespace ttp
