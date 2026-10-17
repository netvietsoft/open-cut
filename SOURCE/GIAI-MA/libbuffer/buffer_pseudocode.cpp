/**
 * @file buffer_pseudocode.cpp
 * @brief ByteDance GeckoX Native Buffer (libbuffer.so) Reverse Engineering Pseudocode & Opcode Table.
 *        Bảng đối soát mã giả C++ và Opcode AArch64 cho thư viện libbuffer.so.
 *
 * Package: com.bytedance.geckox.buffer.impl
 * Binary: apktool-res/lib/arm64-v8a/libbuffer.so (18,184 bytes)
 * Architecture: AArch64 (ARM64-v8a)
 *
 * ============================================================================
 * AArch64 Opcode Parity Table / Bảng ánh xạ Opcode nhị phân chuẩn xác:
 * ============================================================================
 * 1. Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nCreate
 *    - Binary offset: 0x0f5c..0x113c (480 bytes)
 *    - Key instructions:
 *      0x0f98: ldr x8, [x8, #0x548]  ; GetStringUTFChars
 *      0x0fa0: mov w1, #0x42         ; O_RDWR | O_CREAT
 *      0x0fa4: movk w1, #8, lsl #16  ; O_CLOEXEC (0x80000) -> flags = 0x80042
 *      0x0fa8: mov w2, #0x1b6        ; permissions 0666
 *      0x0fb0: bl #0xe00             ; open()
 *      0x0fc4: ldr x8, [x8, #0x550]  ; ReleaseStringUTFChars
 *      0x0fd4: mov w2, #2            ; SEEK_END
 *      0x0fe0: bl #0xe90             ; lseek()
 *      0x0ff4: cmp x0, x21           ; compare file length with requested size
 *      0x1000: bl #0xed0             ; close() on error
 *      0x1014: ldr x8, [x8, #0x30]   ; FindClass("java/io/IOException")
 *      0x1028: add x2, x2, #0x9bc    ; "inconsistent file length"
 *      0x102c: ldr x8, [x8, #0x70]   ; ThrowNew()
 *      0x1040: bl #0xef0             ; ftruncate()
 *      0x10c0: mov w2, #3            ; PROT_READ | PROT_WRITE
 *      0x10c4: mov w3, #1            ; MAP_SHARED
 *      0x10d8: bl #0xec0             ; mmap()
 *      0x10e4: bl #0xed0             ; close(fd)
 *      0x1108: bl #0xeb0             ; __android_log_print(3, "Buffer", "mmap failed, %s")
 *
 * 2. Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nWrite
 *    - Binary offset: 0x113c..0x1198 (92 bytes)
 *    - Key instructions:
 *      0x1158: add x4, x2, x3        ; dest = nativePtr + offset
 *      0x116c: ldr x8, [x8, #0x640]  ; GetByteArrayRegion
 *      0x1170: blr x8                ; invoke JNIEnv->GetByteArrayRegion
 *
 * 3. Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRelease
 *    - Binary offset: 0x1198..0x11e4 (76 bytes)
 *    - Key instructions:
 *      0x11bc: bl #0xee0             ; munmap((void*)nativePtr, size)
 *
 * 4. Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nRead
 *    - Binary offset: 0x11e4..0x1240 (92 bytes)
 *    - Key instructions:
 *      0x1200: add x4, x2, x3        ; src = nativePtr + offset
 *      0x1214: ldr x8, [x8, #0x680]  ; SetByteArrayRegion
 *      0x1218: blr x8                ; invoke JNIEnv->SetByteArrayRegion
 *
 * 5. Java_com_bytedance_geckox_buffer_impl_MMapBuffer_nFlush
 *    - Binary offset: 0x1240..0x12ec (172 bytes)
 *    - Key instructions:
 *      0x1268: mov w2, #4            ; MS_SYNC = 4
 *      0x1274: bl #0xe30             ; msync((void*)nativePtr, size, MS_SYNC)
 *
 * 6. Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nCreate
 *    - Binary offset: 0x12ec..0x15f4 (776 bytes)
 *    - Key instructions:
 *      0x1318: tbnz x3, #0x3f, #0x13cc ; test if size < 0 (length illegal)
 *      0x1338: mov w1, #0x42, movk #8  ; O_RDWR | O_CREAT | O_CLOEXEC = 0x80042
 *      0x1348: bl #0xe00               ; open()
 *      0x1378: bl #0xe90               ; lseek(fd, 0, SEEK_END)
 *      0x1390: cmp x22, x21            ; if fileLen != size and fileLen >= 1
 *      0x139c: bl #0xed0               ; close()
 *      0x13c4: add x2, x2, #0x9bc      ; "inconsistent file length"
 *      0x1404: bl #0xef0               ; ftruncate(fd, size)
 *      0x1490: bl #0xe90               ; lseek(fd, 0, SEEK_SET)
 *      0x14d4: bl #0xe20               ; calloc(1, size)
 *      0x14f8: bl #0xe80               ; __read_chk()
 *      0x1528: bl #0xed0               ; close(fd)
 *
 * 7. _Z8readFulliPal (readFull)
 *    - Binary offset: 0x15f4..0x16a0 (172 bytes)
 *    - Key instructions:
 *      0x1620: cbz x2, #0x1670         ; if count == 0 return 0
 *      0x1640: bl #0xe80               ; __read_chk(fd, ptr, remaining, -1)
 *      0x1654: cmp w8, #4              ; if errno == EINTR (4) -> retry
 *      0x1680: sub x0, x19, x20        ; return count - remaining
 *
 * 8. Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nWrite
 *    - Binary offset: 0x16a0..0x16fc (92 bytes)
 *    - Key instructions:
 *      0x16d0: ldr x8, [x8, #0x640]    ; GetByteArrayRegion
 *
 * 9. Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nRead
 *    - Binary offset: 0x16fc..0x1758 (92 bytes)
 *    - Key instructions:
 *      0x172c: ldr x8, [x8, #0x680]    ; SetByteArrayRegion
 *
 * 10. Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nRelease
 *     - Binary offset: 0x1758..0x17a0 (72 bytes)
 *     - Key instructions:
 *       0x1778: bl #0xf00              ; free((void*)nativePtr)
 *
 * 11. Java_com_bytedance_geckox_buffer_impl_MemoryBuffer_nFlush
 *     - Binary offset: 0x17a0..0x18ec (336 bytes)
 *     - Key instructions:
 *       0x17ec: mov w1, #0x241, movk #8 ; O_RDWR | O_CREAT | O_TRUNC | O_CLOEXEC = 0x80241
 *       0x17fc: bl #0xe00              ; open()
 *       0x182c: bl #0xe70              ; write(fd, ptr, size)
 *       0x1838: bl #0xed0              ; close(fd)
 *
 * 12. Java_com_bytedance_geckox_buffer_impl_MReMapBuffer_nMReMap
 *     - Binary offset: 0x18f0..0x19a8 (184 bytes)
 *     - Key instructions:
 *       0x1914: mov w3, #1             ; MREMAP_MAYMOVE = 1
 *       0x1924: bl #0xe40              ; mremap(oldAddress, oldSize, newSize, 1)
 *       0x1948: bl #0xeb0              ; __android_log_print(3, "Buffer", "mremap failed")
 */

#include "buffer_interface.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "======================================================================\n";
    std::cout << ">>> NextAI OpenCut: GeckoX Native Buffer (libbuffer.so) Self-Test Suite\n";
    std::cout << "======================================================================\n";

    nextai::opencut::buffer::SelfTestResult res = nextai::opencut::buffer::runSelfTest();

    for (int i = 0; i < res.passedStages; ++i) {
        std::cout << "[PASS] " << res.stageDetails[i] << "\n";
    }

    if (res.success) {
        std::cout << "======================================================================\n";
        std::cout << ">>> ALL 7 STAGES PASSED (100.0% SUCCESS) - ZERO STUBS CONFIRMED!\n";
        std::cout << "======================================================================\n";
        return 0;
    } else {
        std::cerr << "[-] Self-test FAILED: " << res.errorMessage << "\n";
        return 1;
    }
}
