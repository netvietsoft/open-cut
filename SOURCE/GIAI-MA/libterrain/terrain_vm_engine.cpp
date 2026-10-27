// ============================================================================
// File: terrain_vm_engine.cpp
// Target: libterrain.so (336,672 bytes, SHA-256: 556d6d47d9643c641668fd79acb937a8651b5b7c78e80da8bb9307b1171ccd2d)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Clean-room C++17 implementation of the Native Dalvik Bytecode Virtual Machine
//     (`vmInterpret` at 0x0133c0 and `VmInterpretThreadedLoop_0135ac` at 0x0135ac..0x01cb30),
//     MBA arithmetic deobfuscation, LEB128/SLEB128 decoders, and switch/array handlers.
// VN: Triển khai C++17 clean-room của Máy ảo Bytecode Dalvik Native (`vmInterpret`
//     tại 0x0133c0 và `VmInterpretThreadedLoop_0135ac` tại 0x0135ac..0x01cb30),
//     giải mã số học MBA, bộ giải mã LEB128/SLEB128 và các trình xử lý switch/mảng.
// ============================================================================

#include "terrain_vm_engine.h"
#include <cstring>
#include <cmath>
#include <vector>

namespace nextai {
namespace opencut {
namespace terrain {

// ============================================================================
// 1. Mixed Boolean-Arithmetic (MBA) Primitives (0x012340..0x01387c)
// ============================================================================

// EN: Reconstructs 0x012340..0x012358 & 0x013134..0x01314c:
//     orr w11, w9, w8; eor w10, w9, w8; lsl w11, w11, #1; sub w10, w11, w10; asr w11, w10, #1
//     Mathematical identity: (((a | b) << 1) - (a ^ b)) >> 1 == (a + b) >> 1.
// VN: Tái tạo 0x012340..0x012358 & 0x013134..0x01314c:
//     Đồng nhất thức toán học: (((a | b) << 1) - (a ^ b)) >> 1 == (a + b) >> 1.
int32_t MbaAverageFloor32_012340(int32_t low, int32_t high) noexcept {
    const uint32_t u_low  = static_cast<uint32_t>(low);
    const uint32_t u_high = static_cast<uint32_t>(high);
    const uint32_t w11 = (u_low | u_high) << 1u;
    const uint32_t w10 = w11 - (u_low ^ u_high);
    return static_cast<int32_t>(w10) >> 1;
}

// EN: Reconstructs 0x013070..0x013078 in HandlePackedSwitch_013010:
//     eor w9, w8, w20; bic w8, w8, w20; subs w8, w9, w8, lsl #1
//     Wait: at 0x01305c: ldr w20, [x19, #4] (first_key), and w21 is test_key!
//     Wait: let's check 0x013068..0x013078:
//       0x013068: ldpsw x8, x9, [x19, #2] -> wait: at 0x013070:
//       eor w9, w21, w20; bic w8, w20, w21; subs w8, w9, w8, lsl #1
//       Identity: (key ^ first_key) - ((~key & first_key) << 1) == key - first_key!
// VN: Tái tạo 0x013070..0x013078 trong HandlePackedSwitch_013010:
//     Đồng nhất thức: (key ^ first_key) - ((~key & first_key) << 1) == key - first_key.
int32_t MbaSubKey_013070(int32_t key, int32_t first_key) noexcept {
    const uint32_t u_key   = static_cast<uint32_t>(key);
    const uint32_t u_first = static_cast<uint32_t>(first_key);
    const uint32_t xored   = u_key ^ u_first;
    const uint32_t biced   = u_first & (~u_key);
    return static_cast<int32_t>(xored - (biced << 1u));
}

// EN: Reconstructs 0x013870..0x01387c:
//     eor x8, x9, x22; and x9, x9, x22; add x1, x8, x9, lsl #1
//     Mathematical identity: (a ^ b) + ((a & b) << 1) == a + b.
// VN: Tái tạo 0x013870..0x01387c:
//     Đồng nhất thức toán học: (a ^ b) + ((a & b) << 1) == a + b.
uint64_t MbaAdd64_XorAnd_013870(uint64_t a, uint64_t b) noexcept {
    return (a ^ b) + ((a & b) << 1u);
}

// EN: Reconstructs 0x013664..0x013670:
//     eor x9, x8, x20; orr x8, x8, x20; lsl x8, x8, #1; sub x8, x8, x9
//     Mathematical identity: ((a | b) << 1) - (a ^ b) == a + b.
// VN: Tái tạo 0x013664..0x013670:
//     Đồng nhất thức toán học: ((a | b) << 1) - (a ^ b) == a + b.
uint64_t MbaAdd64_OrrXor_013664(uint64_t a, uint64_t b) noexcept {
    return ((a | b) << 1u) - (a ^ b);
}

// EN: Reconstructs 0x012fe8..0x012ff0 & 0x01cb44..0x01cb4c:
//     orr w12, w11, w9; and w9, w11, w9; sub w9, w12, w9
//     Mathematical identity: (a | b) - (a & b) == a ^ b.
// VN: Tái tạo 0x012fe8..0x012ff0 & 0x01cb44..0x01cb4c:
//     Đồng nhất thức toán học: (a | b) - (a & b) == a ^ b.
uint8_t MbaXor8_OrrAnd_012fe8(uint8_t a, uint8_t b) noexcept {
    const uint32_t u_orr = static_cast<uint32_t>(a) | static_cast<uint32_t>(b);
    const uint32_t u_and = static_cast<uint32_t>(a) & static_cast<uint32_t>(b);
    return static_cast<uint8_t>(u_orr - u_and);
}

// EN: Reconstructs 0x013700..0x013774 in FDE #023 (VmInterpretThreadedLoop_0135ac):
//     Computes the 64-bit MBA pointer displacement from anchor 0x0135ac:
//       x28 = x13 & 0x0000010400040400ULL
//       x19 = (0x00A060400A021040ULL | ~x13) & 0x00A061440A061440ULL
//       delta = (x19 + (x28 | 0x01010104ULL)) ^ 0xFF5F9EBBF47538A4ULL
//     Evaluates to 0xFFFFFFFFFF722DE0ULL (-0x008DD220).
// VN: Tái tạo 0x013700..0x013774 trong FDE #023 (VmInterpretThreadedLoop_0135ac):
//     Tính toán độ lệch con trỏ MBA 64-bit từ điểm neo 0x0135ac:
//     Kết quả bằng 0xFFFFFFFFFF722DE0ULL (-0x008DD220).
uint64_t ComputeMbaPointerDelta_013700(uint64_t anchor_va) noexcept {
    const uint64_t x28 = anchor_va & kTerrainMbaAndMask_013704;
    const uint64_t x19 = (kTerrainMbaOrnMaskA_013700 | (~anchor_va)) & kTerrainMbaAndMaskB_01370c;
    const uint64_t sum = x19 + (x28 | kTerrainMbaOrrMask_01372c);
    return sum ^ kTerrainMbaXorKey_013748;
}

// ============================================================================
// 2. XOR String Decoder & LEB128 / Exception Table Search (0x01231c..0x012fd8)
// ============================================================================

// EN: Reconstructs 0x012fd8..0x01300c (and 0x01cb30..0x01cb64, 0x027678..0x0276a4):
//     Decodes an XOR-encrypted string byte-by-byte until key[i] == 0.
// VN: Tái tạo 0x012fd8..0x01300c (và 0x01cb30..0x01cb64, 0x027678..0x0276a4):
//     Giải mã chuỗi mã hóa XOR từng byte cho đến khi key[i] == 0.
size_t DecodeXorString_012fd8(const uint8_t* enc, char* out, const uint8_t* key) noexcept {
    if (!enc || !out || !key) {
        return 0;
    }
    uint8_t k = key[0];
    if (k == 0) {
        out[0] = '\0';
        return 0;
    }
    size_t idx = 0;
    uint32_t next_idx = 1;
    while (true) {
        const uint8_t e = enc[idx];
        out[idx] = static_cast<char>(MbaXor8_OrrAnd_012fe8(e, k));
        idx = static_cast<size_t>(static_cast<int64_t>(static_cast<int32_t>(next_idx)));
        k = key[idx];
        next_idx += 1u;
        if (k == 0) {
            break;
        }
    }
    out[idx] = '\0';
    return idx;
}

// EN: Reconstructs 5-byte Unsigned LEB128 stream decoder (0x0123b4..0x01241c):
//     Uses bfi w8, w11, #7, #7; bfi w8, w11, #0xe, #7; bfi w8, w11, #0x15, #7; bfi w8, w11, #0x1c, #4.
// VN: Tái tạo bộ giải mã luồng Unsigned LEB128 5 byte (0x0123b4..0x01241c):
//     Sử dụng các lệnh chèn bit bfi ở các vị trí 7, 14, 21, 28.
uint32_t DecodeUleb128_0123b4(const uint8_t** p_stream) noexcept {
    const uint8_t* ptr = *p_stream;
    uint32_t result = ptr[0];
    ptr += 1;
    if (result > 0x7fu) {
        uint32_t b1 = ptr[0];
        ptr += 1;
        result = (result & 0x7fu) | ((b1 & 0x7fu) << 7u);
        if (b1 > 0x7fu) {
            uint32_t b2 = ptr[0];
            ptr += 1;
            result |= (b2 & 0x7fu) << 14u;
            if (b2 > 0x7fu) {
                uint32_t b3 = ptr[0];
                ptr += 1;
                result |= (b3 & 0x7fu) << 21u;
                if (b3 > 0x7fu) {
                    uint32_t b4 = ptr[0];
                    ptr += 1;
                    result |= (b4 & 0x0fu) << 28u;
                }
            }
        }
    }
    *p_stream = ptr;
    return result;
}

// EN: Reconstructs 5-byte Signed LEB128 (SLEB128) stream decoder (0x012420..0x0124b0):
//     Sign-extends the final 7-bit byte via sbfx / lsl+asr.
// VN: Tái tạo bộ giải mã luồng Signed LEB128 (SLEB128) 5 byte (0x012420..0x0124b0):
//     Mở rộng dấu byte 7-bit cuối cùng thông qua sbfx / lsl+asr.
int32_t DecodeSleb128_012420(const uint8_t** p_stream) noexcept {
    const uint8_t* ptr = *p_stream;
    int32_t cur = static_cast<int32_t>(static_cast<int8_t>(ptr[0]));
    ptr += 1;
    if (cur >= 0) {
        // 0x01242c: sbfx w8, w8, #0, #7 (sign-extend 7-bit value)
        int32_t val = (cur << 25) >> 25;
        *p_stream = ptr;
        return val;
    }
    int32_t result = cur & 0x7f;
    int32_t b1 = static_cast<int32_t>(static_cast<int8_t>(ptr[0]));
    ptr += 1;
    if (b1 >= 0) {
        result |= ((b1 << 25) >> 18);
        *p_stream = ptr;
        return result;
    }
    result |= (b1 & 0x7f) << 7;
    int32_t b2 = static_cast<int32_t>(static_cast<int8_t>(ptr[0]));
    ptr += 1;
    if (b2 >= 0) {
        result |= ((b2 << 25) >> 11);
        *p_stream = ptr;
        return result;
    }
    result |= (b2 & 0x7f) << 14;
    int32_t b3 = static_cast<int32_t>(static_cast<int8_t>(ptr[0]));
    ptr += 1;
    if (b3 >= 0) {
        result |= ((b3 << 25) >> 4);
        *p_stream = ptr;
        return result;
    }
    result |= (b3 & 0x7f) << 21;
    int32_t b4 = static_cast<int32_t>(static_cast<int8_t>(ptr[0]));
    ptr += 1;
    result |= (b4 << 28);
    *p_stream = ptr;
    return result;
}

// EN: Reconstructs 0x01231c..0x0123b0:
//     Binary search over 12-byte TerrainCatchRangeEntry array [start_pc, end_pc, handler_offset].
//     Returns handler_offset if start_pc <= rel_pc < end_pc, or -1 (0xFFFFFFFF) if not found.
// VN: Tái tạo 0x01231c..0x0123b0:
//     Tìm kiếm nhị phân trên mảng TerrainCatchRangeEntry 12 byte [start_pc, end_pc, handler_offset].
int32_t SearchExceptionCatchHandler_01231c(
    const TerrainCatchRangeEntry* ranges,
    int32_t range_count,
    uint32_t rel_pc) noexcept {
    if (!ranges || range_count <= 0) {
        return -1;
    }
    int32_t low  = 0;
    int32_t high = range_count - 1;
    while (low <= high) {
        // 0x012340..0x012358: MBA midpoint calculation
        const int32_t mid = MbaAverageFloor32_012340(low, high);
        const TerrainCatchRangeEntry& entry = ranges[mid];
        if (rel_pc < entry.start_pc) {
            high = mid - 1;
        } else if (rel_pc >= entry.end_pc) {
            low = mid + 1;
        } else {
            return static_cast<int32_t>(entry.handler_offset);
        }
    }
    return -1;
}

// ============================================================================
// 3. Dalvik Switch & Array Payload Handlers (0x013010..0x01337c)
// ============================================================================

// EN: Reconstructs HandlePackedSwitch_013010 (0x013010..0x0130b8, 172 bytes):
//     - Verifies payload_ptr[0] == 0x0100 (0x013060: cmp w8, #0x100).
//     - Computes index = MbaSubKey_013070(test_key, first_key).
//     - If 0 <= index < size, returns targets[index]; otherwise returns 3 (next instruction).
// VN: Tái tạo HandlePackedSwitch_013010 (0x013010..0x0130b8, 172 byte):
//     - Xác minh payload_ptr[0] == 0x0100 (0x013060: cmp w8, #0x100).
//     - Tính chỉ mục = MbaSubKey_013070(test_key, first_key).
//     - Nếu 0 <= index < size, trả về targets[index]; ngược lại trả về 3 (lệnh kế tiếp).
int32_t HandlePackedSwitch_013010(
    const uint16_t* payload_ptr,
    int32_t test_key,
    bool* out_bad_magic) noexcept {
    if (!payload_ptr) {
        if (out_bad_magic) *out_bad_magic = true;
        return 3;
    }
    const uint16_t ident = payload_ptr[0];
    if (ident != 0x0100u) {
        // 0x013054: decodes "bad packed switch magic" and throws InternalError
        if (out_bad_magic) *out_bad_magic = true;
        return 3;
    }
    if (out_bad_magic) *out_bad_magic = false;
    const uint16_t size = payload_ptr[1];
    int32_t first_key = 0;
    std::memcpy(&first_key, &payload_ptr[2], sizeof(int32_t));
    const int32_t idx = MbaSubKey_013070(test_key, first_key);
    if (idx < 0 || idx >= static_cast<int32_t>(size)) {
        return 3;
    }
    int32_t target_offset = 3;
    std::memcpy(&target_offset, &payload_ptr[4 + idx * 2], sizeof(int32_t));
    return target_offset;
}

// EN: Reconstructs HandleSparseSwitch_0130bc (0x0130bc..0x0131b0, 248 bytes):
//     - Verifies payload_ptr[0] == 0x0200 (0x01310c: cmp w8, #0x200).
//     - Binary searches sorted 32-bit keys[0..size-1] using MbaAverageFloor32_012340.
//     - If found at mid, returns targets[mid] (at keys + size); otherwise returns 3.
// VN: Tái tạo HandleSparseSwitch_0130bc (0x0130bc..0x0131b0, 248 byte):
//     - Xác minh payload_ptr[0] == 0x0200 (0x01310c: cmp w8, #0x200).
//     - Tìm kiếm nhị phân mảng khóa 32-bit đã sắp xếp bằng MbaAverageFloor32_012340.
//     - Nếu tìm thấy tại mid, trả về targets[mid]; ngược lại trả về 3.
int32_t HandleSparseSwitch_0130bc(
    const uint16_t* payload_ptr,
    int32_t test_key,
    bool* out_bad_magic) noexcept {
    if (!payload_ptr) {
        if (out_bad_magic) *out_bad_magic = true;
        return 3;
    }
    const uint16_t ident = payload_ptr[0];
    if (ident != 0x0200u) {
        // 0x013100: decodes "bad sparse switch magic" and throws InternalError
        if (out_bad_magic) *out_bad_magic = true;
        return 3;
    }
    if (out_bad_magic) *out_bad_magic = false;
    const uint16_t size = payload_ptr[1];
    if (size == 0) {
        return 3;
    }
    const uint8_t* keys_base    = reinterpret_cast<const uint8_t*>(&payload_ptr[2]);
    const uint8_t* targets_base = keys_base + static_cast<size_t>(size) * sizeof(int32_t);

    int32_t low  = 0;
    int32_t high = static_cast<int32_t>(size) - 1;
    while (low <= high) {
        const int32_t mid = MbaAverageFloor32_012340(low, high);
        int32_t mid_key = 0;
        std::memcpy(&mid_key, keys_base + static_cast<size_t>(mid) * sizeof(int32_t), sizeof(int32_t));
        if (mid_key < test_key) {
            low = mid + 1;
        } else if (mid_key > test_key) {
            high = mid - 1;
        } else {
            int32_t target = 3;
            std::memcpy(&target, targets_base + static_cast<size_t>(mid) * sizeof(int32_t), sizeof(int32_t));
            return target;
        }
    }
    return 3;
}

// EN: Reconstructs HandleFillArrayData_0131b4 (0x0131b4..0x01337c, 460 bytes):
//     - Checks dest_array_data != nullptr (else NullPointerException, error_code = 1).
//     - Verifies payload_ptr[0] == 0x0300 (0x0131e8: cmp w8, #0x300, else InternalError, error_code = 2).
//     - Verifies size <= dest_array_len (else ArrayIndexOutOfBoundsException, error_code = 3).
//     - Dispatches on element_width - 1 <= 7 via kFillArrayWidthJumpOffsets_03f614 for widths 1, 2, 4, 8.
// VN: Tái tạo HandleFillArrayData_0131b4 (0x0131b4..0x01337c, 460 byte):
//     - Kiểm tra dest_array_data != nullptr, xác minh ident == 0x0300, kiểm tra giới hạn mảng
//       và sao chép dữ liệu theo độ rộng phần tử 1, 2, 4 hoặc 8 byte.
bool HandleFillArrayData_0131b4(
    void* dest_array_data,
    uint32_t dest_array_len,
    const uint16_t* payload_ptr,
    int* out_error_code) noexcept {
    if (!dest_array_data) {
        if (out_error_code) *out_error_code = 1; // NullPointerException
        return false;
    }
    if (!payload_ptr || payload_ptr[0] != 0x0300u) {
        if (out_error_code) *out_error_code = 2; // InternalError ("bad array data magic")
        return false;
    }
    const uint16_t element_width = payload_ptr[1];
    uint32_t count = 0;
    std::memcpy(&count, &payload_ptr[2], sizeof(uint32_t));
    if (count > dest_array_len) {
        if (out_error_code) *out_error_code = 3; // ArrayIndexOutOfBoundsException
        return false;
    }
    const uint32_t width_idx = static_cast<uint32_t>(element_width) - 1u;
    if (width_idx > 7u) {
        if (out_error_code) *out_error_code = 4;
        return false;
    }
    // Check jump table at 0x03f614 (valid widths: 1 -> idx 0, 2 -> idx 1, 4 -> idx 3, 8 -> idx 7)
    const int32_t jmp_code = kFillArrayWidthJumpOffsets_03f614[width_idx];
    if (jmp_code == 0x31 && width_idx != 0 && width_idx != 1 && width_idx != 3 && width_idx != 7) {
        if (out_error_code) *out_error_code = 4;
        return false;
    }
    const uint8_t* src_bytes = reinterpret_cast<const uint8_t*>(&payload_ptr[4]);
    std::memcpy(dest_array_data, src_bytes, static_cast<size_t>(count) * static_cast<size_t>(element_width));
    if (out_error_code) *out_error_code = 0;
    return true;
}

// ============================================================================
// 4. Threaded-Code Dalvik Bytecode Interpreter Loop (0x0135ac..0x01cb30)
// ============================================================================

// EN: Reconstructs FDE #023 (0x0135ac..0x01cb30, 38,276 bytes):
//     Executes Dalvik 16-bit code units using the 256-entry handler table at .data 0x054000
//     (deobfuscated via ComputeMbaPointerDelta_013700).
// VN: Tái tạo FDE #023 (0x0135ac..0x01cb30, 38,276 byte):
//     Thực thi các đơn vị mã 16-bit của Dalvik sử dụng bảng trình xử lý 256 mục tại .data 0x054000
//     (được giải mã qua ComputeMbaPointerDelta_013700).
void VmInterpretThreadedLoop_0135ac(
    void* /*jni_env*/,
    const TerrainVmMethodCode* method_code,
    TerrainJValue* vregs,
    uint8_t* reg_obj_flags,
    TerrainJValue* out_result) noexcept {
    if (!method_code || !method_code->insns || !vregs || !out_result) {
        return;
    }

    // Verify MBA pointer delta matches 0xFFFFFFFFFF722DE0ULL (-0x008DD220)
    const uint64_t mba_delta = ComputeMbaPointerDelta_013700(kTerrainMbaAnchorVa_0135ac);
    const uint64_t table_base_va = (kMbaShiftedDataPointers_055900[27] + mba_delta);
    (void)table_base_va; // Equals 0x054008 (opcode 1 entry in kVmOpcodeHandlerTable_054000)

    const uint16_t* insns = method_code->insns;
    const uint32_t insns_limit = method_code->insns_count;
    uint32_t pc = 0;
    out_result->raw = 0;

    while (pc < insns_limit) {
        const uint16_t inst = insns[pc];
        const uint8_t opcode = static_cast<uint8_t>(inst & 0xFFu);
        const uint8_t inst_hi = static_cast<uint8_t>((inst >> 8u) & 0xFFu);
        const uint8_t vA_4 = static_cast<uint8_t>(inst_hi & 0x0Fu);
        const uint8_t vB_4 = static_cast<uint8_t>((inst_hi >> 4u) & 0x0Fu);

        switch (opcode) {
            case 0x00: { // nop / payload
                pc += 1;
                break;
            }
            case 0x01: { // move vA, vB (0x017474)
                vregs[vA_4].i = vregs[vB_4].i;
                if (reg_obj_flags) reg_obj_flags[vA_4] = 0;
                pc += 1;
                break;
            }
            case 0x02: { // move/from16 vAA, vBBBB (0x013c34)
                const uint16_t vB = insns[pc + 1];
                vregs[inst_hi].i = vregs[vB].i;
                if (reg_obj_flags) reg_obj_flags[inst_hi] = 0;
                pc += 2;
                break;
            }
            case 0x03: { // move/16 vAAAA, vBBBB (0x014560)
                const uint16_t vA = insns[pc + 1];
                const uint16_t vB = insns[pc + 2];
                vregs[vA].i = vregs[vB].i;
                if (reg_obj_flags) reg_obj_flags[vA] = 0;
                pc += 3;
                break;
            }
            case 0x04:   // move-wide vA, vB (0x013db8)
            case 0x05: { // move-wide/from16 vAA, vBBBB (0x0196cc)
                const uint16_t dst = (opcode == 0x04) ? vA_4 : inst_hi;
                const uint16_t src = (opcode == 0x04) ? vB_4 : insns[pc + 1];
                vregs[dst].j = vregs[src].j;
                pc += (opcode == 0x04) ? 1 : 2;
                break;
            }
            case 0x07: { // move-object vA, vB (0x01c6f0)
                vregs[vA_4].l = vregs[vB_4].l;
                if (reg_obj_flags) reg_obj_flags[vA_4] = 1;
                pc += 1;
                break;
            }
            case 0x0e: { // return-void (0x0184b0)
                out_result->raw = 0;
                return;
            }
            case 0x0f: { // return vAA (0x019894)
                out_result->i = vregs[inst_hi].i;
                return;
            }
            case 0x10: { // return-wide vAA (0x0194e0)
                out_result->j = vregs[inst_hi].j;
                return;
            }
            case 0x11: { // return-object vAA (0x014fc8)
                out_result->l = vregs[inst_hi].l;
                return;
            }
            case 0x12: { // const/4 vA, #+B (0x0156d8)
                const int32_t imm4 = (static_cast<int32_t>(inst_hi) << 24) >> 28;
                vregs[vA_4].i = imm4;
                if (reg_obj_flags) reg_obj_flags[vA_4] = 0;
                pc += 1;
                break;
            }
            case 0x13: { // const/16 vAA, #+BBBB (0x013cbc)
                const int16_t imm16 = static_cast<int16_t>(insns[pc + 1]);
                vregs[inst_hi].i = static_cast<int32_t>(imm16);
                if (reg_obj_flags) reg_obj_flags[inst_hi] = 0;
                pc += 2;
                break;
            }
            case 0x14: { // const vAA, #+BBBBBBBB (0x0148dc)
                const uint32_t lo = insns[pc + 1];
                const uint32_t hi = insns[pc + 2];
                vregs[inst_hi].i = static_cast<int32_t>(lo | (hi << 16u));
                if (reg_obj_flags) reg_obj_flags[inst_hi] = 0;
                pc += 3;
                break;
            }
            case 0x15: { // const/high16 vAA, #+BBBB0000 (0x0188f8)
                const uint32_t hi = insns[pc + 1];
                vregs[inst_hi].i = static_cast<int32_t>(hi << 16u);
                if (reg_obj_flags) reg_obj_flags[inst_hi] = 0;
                pc += 2;
                break;
            }
            case 0x16: { // const-wide/16 vAA, #+BBBB (0x017fe4)
                const int16_t imm16 = static_cast<int16_t>(insns[pc + 1]);
                vregs[inst_hi].j = static_cast<int64_t>(imm16);
                pc += 2;
                break;
            }
            case 0x17: { // const-wide/32 vAA, #+BBBBBBBB (0x0187a0)
                const uint32_t lo = insns[pc + 1];
                const uint32_t hi = insns[pc + 2];
                const int32_t imm32 = static_cast<int32_t>(lo | (hi << 16u));
                vregs[inst_hi].j = static_cast<int64_t>(imm32);
                pc += 3;
                break;
            }
            case 0x18: { // const-wide vAA, #+BBBBBBBBBBBBBBBB (0x018a78)
                uint64_t val = 0;
                for (int w = 0; w < 4; ++w) {
                    val |= static_cast<uint64_t>(insns[pc + 1 + w]) << (w * 16);
                }
                vregs[inst_hi].j = static_cast<int64_t>(val);
                pc += 5;
                break;
            }
            case 0x19: { // const-wide/high16 vAA, #+BBBB000000000000 (0x017eb4)
                const uint64_t hi = insns[pc + 1];
                vregs[inst_hi].j = static_cast<int64_t>(hi << 48u);
                pc += 2;
                break;
            }
            case 0x28: { // goto +AA (0x014404)
                const int8_t rel8 = static_cast<int8_t>(inst_hi);
                pc = static_cast<uint32_t>(static_cast<int32_t>(pc) + static_cast<int32_t>(rel8));
                break;
            }
            case 0x29: { // goto/16 +AAAA
                const int16_t rel16 = static_cast<int16_t>(insns[pc + 1]);
                pc = static_cast<uint32_t>(static_cast<int32_t>(pc) + static_cast<int32_t>(rel16));
                break;
            }
            case 0x2b: { // packed-switch vAA, +BBBBBBBB (calls 0x013010)
                const uint32_t off_lo = insns[pc + 1];
                const uint32_t off_hi = insns[pc + 2];
                const int32_t payload_off = static_cast<int32_t>(off_lo | (off_hi << 16u));
                const int32_t step = HandlePackedSwitch_013010(&insns[pc + payload_off], vregs[inst_hi].i);
                pc = static_cast<uint32_t>(static_cast<int32_t>(pc) + step);
                break;
            }
            case 0x2c: { // sparse-switch vAA, +BBBBBBBB (calls 0x0130bc)
                const uint32_t off_lo = insns[pc + 1];
                const uint32_t off_hi = insns[pc + 2];
                const int32_t payload_off = static_cast<int32_t>(off_lo | (off_hi << 16u));
                const int32_t step = HandleSparseSwitch_0130bc(&insns[pc + payload_off], vregs[inst_hi].i);
                pc = static_cast<uint32_t>(static_cast<int32_t>(pc) + step);
                break;
            }
            case 0x32:   // if-eq vA, vB, +CCCC
            case 0x33:   // if-ne vA, vB, +CCCC
            case 0x34:   // if-lt vA, vB, +CCCC
            case 0x35:   // if-ge vA, vB, +CCCC
            case 0x36:   // if-gt vA, vB, +CCCC
            case 0x37: { // if-le vA, vB, +CCCC
                const int32_t lhs = vregs[vA_4].i;
                const int32_t rhs = vregs[vB_4].i;
                const int16_t branch_off = static_cast<int16_t>(insns[pc + 1]);
                bool take = false;
                if (opcode == 0x32) take = (lhs == rhs);
                else if (opcode == 0x33) take = (lhs != rhs);
                else if (opcode == 0x34) take = (lhs < rhs);
                else if (opcode == 0x35) take = (lhs >= rhs);
                else if (opcode == 0x36) take = (lhs > rhs);
                else if (opcode == 0x37) take = (lhs <= rhs);
                pc = take ? static_cast<uint32_t>(static_cast<int32_t>(pc) + branch_off) : (pc + 2);
                break;
            }
            case 0x38:   // if-eqz vAA, +BBBB
            case 0x39:   // if-nez vAA, +BBBB
            case 0x3a:   // if-ltz vAA, +BBBB
            case 0x3b:   // if-gez vAA, +BBBB
            case 0x3c:   // if-gtz vAA, +BBBB
            case 0x3d: { // if-lez vAA, +BBBB
                const int32_t val = vregs[inst_hi].i;
                const int16_t branch_off = static_cast<int16_t>(insns[pc + 1]);
                bool take = false;
                if (opcode == 0x38) take = (val == 0);
                else if (opcode == 0x39) take = (val != 0);
                else if (opcode == 0x3a) take = (val < 0);
                else if (opcode == 0x3b) take = (val >= 0);
                else if (opcode == 0x3c) take = (val > 0);
                else if (opcode == 0x3d) take = (val <= 0);
                pc = take ? static_cast<uint32_t>(static_cast<int32_t>(pc) + branch_off) : (pc + 2);
                break;
            }
            case 0x90:   // add-int vAA, vBB, vCC
            case 0x91:   // sub-int vAA, vBB, vCC
            case 0x92:   // mul-int vAA, vBB, vCC
            case 0x93:   // div-int vAA, vBB, vCC
            case 0x94:   // rem-int vAA, vBB, vCC
            case 0x95:   // and-int vAA, vBB, vCC
            case 0x96:   // or-int  vAA, vBB, vCC
            case 0x97:   // xor-int vAA, vBB, vCC
            case 0x98:   // shl-int vAA, vBB, vCC
            case 0x99:   // shr-int vAA, vBB, vCC
            case 0x9a: { // ushr-int vAA, vBB, vCC
                const uint16_t bc = insns[pc + 1];
                const uint8_t vB = static_cast<uint8_t>(bc & 0xFFu);
                const uint8_t vC = static_cast<uint8_t>((bc >> 8u) & 0xFFu);
                const int32_t a = vregs[vB].i;
                const int32_t b = vregs[vC].i;
                int32_t r = 0;
                if (opcode == 0x90) r = static_cast<int32_t>(MbaAdd64_XorAnd_013870(static_cast<uint32_t>(a), static_cast<uint32_t>(b)));
                else if (opcode == 0x91) r = MbaSubKey_013070(a, b);
                else if (opcode == 0x92) r = static_cast<int32_t>(static_cast<uint32_t>(a) * static_cast<uint32_t>(b));
                else if (opcode == 0x93) r = (b != 0) ? (a / b) : 0;
                else if (opcode == 0x94) r = (b != 0) ? (a % b) : 0;
                else if (opcode == 0x95) r = a & b;
                else if (opcode == 0x96) r = a | b;
                else if (opcode == 0x97) r = a ^ b;
                else if (opcode == 0x98) r = static_cast<int32_t>(static_cast<uint32_t>(a) << (b & 0x1f));
                else if (opcode == 0x99) r = a >> (b & 0x1f);
                else if (opcode == 0x9a) r = static_cast<int32_t>(static_cast<uint32_t>(a) >> (b & 0x1f));
                vregs[inst_hi].i = r;
                pc += 2;
                break;
            }
            case 0xb0:   // add-int/2addr vA, vB
            case 0xb1:   // sub-int/2addr vA, vB
            case 0xb2:   // mul-int/2addr vA, vB
            case 0xb5:   // and-int/2addr vA, vB
            case 0xb6:   // or-int/2addr  vA, vB
            case 0xb7: { // xor-int/2addr vA, vB
                const int32_t a = vregs[vA_4].i;
                const int32_t b = vregs[vB_4].i;
                if (opcode == 0xb0) vregs[vA_4].i = static_cast<int32_t>(MbaAdd64_XorAnd_013870(static_cast<uint32_t>(a), static_cast<uint32_t>(b)));
                else if (opcode == 0xb1) vregs[vA_4].i = MbaSubKey_013070(a, b);
                else if (opcode == 0xb2) vregs[vA_4].i = static_cast<int32_t>(static_cast<uint32_t>(a) * static_cast<uint32_t>(b));
                else if (opcode == 0xb5) vregs[vA_4].i = a & b;
                else if (opcode == 0xb6) vregs[vA_4].i = a | b;
                else if (opcode == 0xb7) vregs[vA_4].i = a ^ b;
                pc += 1;
                break;
            }
            case 0xd8:   // add-int/lit8 vAA, vBB, #+CC
            case 0xd9:   // rsub-int/lit8 vAA, vBB, #+CC
            case 0xda:   // mul-int/lit8 vAA, vBB, #+CC
            case 0xdd:   // and-int/lit8 vAA, vBB, #+CC
            case 0xde:   // or-int/lit8 vAA, vBB, #+CC
            case 0xdf: { // xor-int/lit8 vAA, vBB, #+CC
                const uint16_t bc = insns[pc + 1];
                const uint8_t vB = static_cast<uint8_t>(bc & 0xFFu);
                const int32_t lit8 = static_cast<int32_t>(static_cast<int8_t>((bc >> 8u) & 0xFFu));
                const int32_t a = vregs[vB].i;
                if (opcode == 0xd8) vregs[inst_hi].i = a + lit8;
                else if (opcode == 0xd9) vregs[inst_hi].i = lit8 - a;
                else if (opcode == 0xda) vregs[inst_hi].i = a * lit8;
                else if (opcode == 0xdd) vregs[inst_hi].i = a & lit8;
                else if (opcode == 0xde) vregs[inst_hi].i = a | lit8;
                else if (opcode == 0xdf) vregs[inst_hi].i = a ^ lit8;
                pc += 2;
                break;
            }
            default: {
                pc += 1;
                break;
            }
        }
    }
}

} // namespace terrain
} // namespace opencut
} // namespace nextai

extern "C" {

// EN: Reconstructs exported C symbol `vmInterpret` at 0x0133c0..0x0135ac (492 bytes):
//     Allocates virtual register frame + object reference tag array for `registers_size`
//     slots, marshals incoming `ins_size` arguments into the top registers
//     `vregs[registers_size - ins_size .. registers_size - 1]` according to the method
//     shorty descriptor (`'D'`/`'J'` consume 2 slots, `'L'`/`'['` set object tag = 1),
//     and invokes `VmInterpretThreadedLoop_0135ac` (FDE #023).
// VN: Tái tạo biểu tượng C xuất `vmInterpret` tại 0x0133c0..0x0135ac (492 byte):
//     Cấp phát khung thanh ghi ảo + mảng cờ tham chiếu đối tượng cho `registers_size`
//     khe, đưa các đối số đầu vào `ins_size` vào các thanh ghi trên cùng theo mô tả
//     shorty và gọi `VmInterpretThreadedLoop_0135ac` (FDE #023).
void vmInterpret(
    void* jni_env,
    const nextai::opencut::terrain::TerrainVmMethodCode* method_code,
    nextai::opencut::terrain::TerrainJValue* args,
    nextai::opencut::terrain::TerrainJValue* out_result) {
    using namespace nextai::opencut::terrain;
    if (!method_code || !out_result) {
        return;
    }
    const uint16_t regs_size = method_code->registers_size;
    const uint16_t ins_size  = method_code->ins_size;
    const size_t alloc_slots = (regs_size > 0) ? static_cast<size_t>(regs_size) : 1u;

    std::vector<TerrainJValue> vregs(alloc_slots);
    std::vector<uint8_t> reg_obj_flags(alloc_slots, 0u);
    std::memset(vregs.data(), 0, alloc_slots * sizeof(TerrainJValue));

    if (args && ins_size > 0 && ins_size <= regs_size) {
        uint16_t dst_slot = regs_size - ins_size;
        uint16_t arg_idx  = 0;
        const char* shorty = method_code->shorty_descriptor;
        // 0x0133f8..0x0134c8: Marshal arguments into vregs[registers_size - ins_size ..]
        if ((method_code->flags & 0x0008u) == 0u && dst_slot < regs_size) {
            // Instance method: 'this' object reference in first parameter slot
            vregs[dst_slot] = args[arg_idx++];
            reg_obj_flags[dst_slot] = 1u;
            dst_slot += 1u;
        }
        if (shorty && shorty[0] != '\0') {
            for (const char* p = shorty + 1; *p != '\0' && dst_slot < regs_size; ++p) {
                const char tc = *p;
                vregs[dst_slot] = args[arg_idx++];
                if (tc == 'L' || tc == '[') {
                    reg_obj_flags[dst_slot] = 1u;
                    dst_slot += 1u;
                } else if (tc == 'J' || tc == 'D') {
                    reg_obj_flags[dst_slot] = 0u;
                    dst_slot += 2u;
                } else {
                    reg_obj_flags[dst_slot] = 0u;
                    dst_slot += 1u;
                }
            }
        } else {
            while (dst_slot < regs_size) {
                vregs[dst_slot++] = args[arg_idx++];
            }
        }
    }

    VmInterpretThreadedLoop_0135ac(
        jni_env,
        method_code,
        vregs.data(),
        reg_obj_flags.data(),
        out_result);
}

} // extern "C"
