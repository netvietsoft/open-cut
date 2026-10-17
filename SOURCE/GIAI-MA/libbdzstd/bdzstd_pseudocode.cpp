/**
 * @file bdzstd_pseudocode.cpp
 * @brief ByteDance Zstandard Engine - Binary Decompilation Pseudocode & Standalone Verification Harness.
 *        Mã giả đối chiếu nhị phân và khung chạy kiểm thử độc lập của libbdzstd.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdzstd_interface.h"
#include <iostream>
#include <iomanip>

using namespace bytedance::compression::zstd;

/**
 * ============================================================================
 * BINARY OFFSET & AARCH64 OPCODE MAPPING TABLE / BẢNG ĐỐI CHIẾU MÃ MÁY
 * ============================================================================
 *
 * 1. ZSTD_isError (0x0040f8, size: 12 bytes):
 *    0x0040f8: 1fe001b1  cmn x0, #0x78      ; Phép cộng x0 + 120
 *    0x0040fc: e0979f1a  cset w0, hi        ; w0 = (unsigned)x0 > -120 ? 1 : 0
 *    0x004100: c0035fd6  ret
 *    -> Tái dựng C++: return code > (size_t)-120;
 *
 * 2. ZSTD_compressBound (0x006750, size: 32 bytes):
 *    0x006750: 4900a052  mov w9, #0x20000   ; w9 = 131072 (128 KB)
 *    0x006754: 290100cb  sub x9, x9, x0     ; x9 = 131072 - srcSize
 *    0x006758: 29fd4bd3  lsr x9, x9, #0xb   ; x9 = (131072 - srcSize) >> 11
 *    0x00675c: 1f8040f1  cmp x0, #0x20, lsl #12 ; cmp srcSize, 131072
 *    0x006760: 0820408b  add x8, x0, x0, lsr #8 ; x8 = srcSize + (srcSize >> 8)
 *    0x006764: 29319f9a  csel x9, x9, xzr, lo   ; if (srcSize < 131072) x9 else 0
 *    0x006768: 0001098b  add x0, x8, x9     ; x0 = x8 + x9
 *    0x00676c: c0035fd6  ret
 *    -> Tái dựng C++: return srcSize + (srcSize >> 8) + (srcSize < 131072 ? ((131072 - srcSize) >> 11) : 0);
 *
 * 3. Java_..._Zstd_getErrorCode (0x02fc60, size: 16 bytes):
 *    0x02fc60: e803024b  neg w8, w2         ; w8 = -w2
 *    0x02fc64: 5fdc01b1  cmn x2, #0x77      ; cmn x2, 119
 *    0x02fc68: e033889a  csel x0, xzr, x8, lo ; if (x2 < -119) -x2 else 0
 *    0x02fc6c: c0035fd6  ret
 *
 * 4. Java_..._ZstdCompress_defaultCompressionLevel (0x0303d0):
 *    0x0303d0: 60008052  mov w0, #3; ret    ; Trả về mức nén mặc định 3
 *
 * 5. Java_..._ZstdCompress_minCompressionLevel (0x0303d8):
 *    0x0303d8: c0ffbf52  mov w0, #-0x20000; ret ; Trả về mức nén tối thiểu -131072
 *
 * 6. Java_..._ZstdCompress_maxCompressionLevel (0x0303e0):
 *    0x0303e0: c0028052  mov w0, #0x16; ret ; Trả về mức nén tối đa 22
 *
 * 7. ZstdCompressCtx_init (0x0303e8, size: 216 bytes):
 *    0x030410: 00bf8152  mov w0, #0xdf8     ; Cấp phát 3576 bytes cho struct CCtx
 *    0x030414: bf49ff97  bl malloc
 *    0x030420: 02bf8152  mov w2, #0xdf8; memset
 *
 * 8. compressByteArray0 / decompressByteArray0 buffer safety (0x0308d8, 0x031634):
 *    0x030940: f6088092  mov x22, #-0x48    ; Trả về -72 (-0x48: ZSTD_error_dstSize_tooSmall)
 *
 * 9. Recommended Streaming Sizes:
 *    0x030aa0: recommendedCOutSize -> mov w0, #0x207; movk w0, #2, lsl #16 -> 131591 (128KB + 519)
 *    0x03186c: recommendedDInSize  -> mov w0, #3; movk w0, #2, lsl #16     -> 131075 (128KB + 3)
 *    0x031878: recommendedDOutSize -> mov w0, #0x20000                     -> 131072 (128KB)
 */

int main(int argc, char* argv[]) {
    std::cout << "========================================================\n";
    std::cout << " NextAI OpenCut: libbdzstd.so Standalone Self-Test Engine \n";
    std::cout << "========================================================\n";

    auto& engine = ByteDanceZstdEngine::getInstance();
    auto report = engine.runSelfTest();

    std::cout << report.detailLog << std::endl;

    if (report.passedAll) {
        std::cout << "[SUCCESS] 100% Tests Passed for libbdzstd.so!\n";
        return 0;
    } else {
        std::cerr << "[FAILURE] Self-test failed: only "
                  << report.stagesPassed << "/" << report.totalStages << " passed.\n";
        return 1;
    }
}
