# Báo Cáo Nghiệm Thu Tái Cấu Trúc — `liblynx_markdown.so` (`TASK_SO_120_liblynx_markdown` / `TASK-125`)
# Reconstruction Acceptance Report — `liblynx_markdown.so`

- **Target Binary / Đích nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so` (`247,888 bytes`)
- **SHA-256**: `3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d`
- **Status / Trạng thái**: `RECONSTRUCTED_AND_VERIFIED` (`100%`)
- **Reconstructed C++17 Volume / Dung lượng C++17 tái dựng**: `263,879 bytes` (`9` C++17/H files + `README_ANALYSIS.md`, `0` stubs)

## Hạng mục hoàn thành / Completed Deliverables
1. **38 Exported JNI Entry Points (`0x00d300..0x018420`)**: Phục hồi đầy đủ 38 phương thức JNI của `com.bytedance.xelement.markdown.MarkdownDocument` (`nativeCreateInstance`, `nativeParse`, `nativeLayout`, `nativeDestroyInstance`, `nativeDraw`, `nativeDrawWithCursor`, `nativeGetCursorPosition`, `initial`, `nativeSetStyle`, `nativeMarkdownOffsetToChar`, `nativeGetRegionCount`, `nativeGetExtraContentCount`, `nativeInheritState`, v.v.).
2. **Embedded Discount (`MMIOT` magic `0x19600731`) + GFM Parser (`0x00e718..0x00feb4`)**: Phục hồi trình cắt UTF-8 codepoint (`0x00e9c0..0x00eaec`), cấu trúc `MMIOT` (`0x98` B, magic `0x19600731`), `Paragraph` (`0x78` B), bảng chữ số La Mã (`0x038668..0x038750`), và tìm kiếm nhị phân `MarkdownOffsetRange` 16-byte (`0x0142d4`).
3. **`ttoffice::tttext` Layout, Typewriter & `BufferCanvasHelper` (`0x0102a0..0x019d80`)**: Phục hồi `MarkdownDocument` (`0xe88` = `3,720 bytes`), `BufferCanvasHelper` (`vtable @ 0x038148`, `malloc(0x400)`), `BufferPaintHelper` (`0x58` B, `"pingfang"`, `14.0f`), và kiểm tra va chạm (hit-testing).
