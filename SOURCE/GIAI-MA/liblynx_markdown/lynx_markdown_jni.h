/**
 * @file lynx_markdown_jni.h
 * @brief Clean-Room C++17 Header for 38 Exported JNI Entry Points of com.bytedance.xelement.markdown.MarkdownDocument
 *        Header C++17 Tái cấu trúc sạch 38 điểm vào JNI xuất khẩu của com.bytedance.xelement.markdown.MarkdownDocument
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   SHA-256: 3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d
 *   Exported JNI Symbols: 38 functions (0x00d300..0x018420)
 */

#pragma once

#include "lynx_markdown_types.h"
#include "lynx_markdown_parser.h"
#include "lynx_markdown_layout_draw.h"

extern "C" {

/** 1. @ 0x00d300 (880 B): Allocate 0xe88-byte MarkdownDocument, ResourceLoader, EventListener */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance(
    JNIEnv* env, jobject thiz);

/** 2. @ 0x00e718 (6,044 B): Parse Markdown string slice [char_start, char_end) with font_scale */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jstring content,
    jint char_start, jint char_end, jfloat font_scale);

/** 3. @ 0x0102a0 (2,280 B): Layout document within (max_width, max_height, typewriter_step) */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeLayout(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat max_width,
    jfloat max_height, jint typewriter_step);

/** 4. @ 0x010b88 (752 B): Destroy MarkdownDocument instance and release all resources */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDestroyInstance(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 5. @ 0x011100 (404 B): Serialize full page draw stream via BufferCanvasHelper */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDraw(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 6. @ 0x011294 (660 B): Serialize page draw stream clipped to typewriter char_count with optional cursor */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawWithCursor(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint char_count, jboolean show_cursor);

/** 7. @ 0x011528 (708 B): Return float[3] {x, y, height} of typewriter cursor */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCursorPosition(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint char_count, jboolean is_custom_cursor);

/** 8. @ 0x0117ec (664 B): Initialize JavaVM and cache 6 MarkdownDocument callback jmethodIDs */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_initial(
    JNIEnv* env, jclass clazz);

/** 9. @ 0x011a84 (1,016 B): Apply binary serialized style buffer onto MarkdownDocument */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeSetStyle(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jbyteArray style_bytes);

/** 10. @ 0x013254 (472 B): Hit-test link at (touch_x, touch_y) and return String[2] {url, content} */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkByPosition(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat touch_x, jfloat touch_y);

/** 11. @ 0x01342c (1,328 B): Return packed origin (x, y) or visibility for inline view ID */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetInlineViewOrigin(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jstring view_id, jint char_count);

/** 12. @ 0x01395c (752 B): Extract plain text substring in [char_start, char_end) */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetContentByCharRange(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint char_start, jint char_end);

/** 13. @ 0x013c4c (1,136 B): Compute float[4*N] selection bounding boxes for [char_start, char_end) */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSelectionRectByCharPos(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint char_start, jint char_end);

/** 14. @ 0x0140bc (308 B): Hit-test point (touch_x, touch_y) and return int[2] {start, end} by split_type */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCharRangeByPoint(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat touch_x, jfloat touch_y, jint split_type);

/** 15. @ 0x0141f0 (228 B): Return total laid-out character count of current page */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetPageCharCount(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 16. @ 0x0142d4 (132 B): Binary-search Markdown byte offset -> rendered character index */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeMarkdownOffsetToChar(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint markdown_offset);

/** 17. @ 0x014358 (560 B): Return String[2*N] array of all parsed links {url_0, text_0, ...} */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinks(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 18. @ 0x0146d4 (1,588 B): Return float[4*M] array of bounding rects for all links */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkRects(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 19. @ 0x014d08 (1,176 B): Return int[2*K] char ranges matching syntax tag ("bold", "codeBlock", etc.) */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSyntaxRange(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jstring syntax_tag);

/** 20. @ 0x0151a0 (608 B): Return String[N] array of all image URLs */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImages(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 21. @ 0x015400 (556 B): Hit-test image at (touch_x, touch_y) and return image URL */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImageByTouchPosition(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat touch_x, jfloat touch_y);

/** 22. @ 0x01562c (16 B): Set allow_break_around_punctuation flag at [doc + 0xe38] */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAllowBreakAroundPunctuation(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jboolean allow);

/** 23. @ 0x01563c (820 B): Handle touch down/move/up/cancel for horizontally scrollable regions */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeOnTouchEvent(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat touch_x, jfloat touch_y, jint action);

/** 24. @ 0x015970 (3,048 B): Add dynamic text mark attachment (highlight/underline/click range) */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAddTextMarkAttachment(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jbyteArray attachment_bytes);

/** 25. @ 0x01666c (208 B): Clear all dynamic text mark attachments */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeClearTextMarkAttachment(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 26. @ 0x01673c (512 B): Hit-test clickable text mark attachment at (touch_x, touch_y) */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTextClickByPoint(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat touch_x, jfloat touch_y);

/** 27. @ 0x01693c (424 B): Draw single region by index into BufferCanvasHelper byte array */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawRegion(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint region_index);

/** 28. @ 0x016ae4 (688 B): Draw single region clipped to typewriter step with optional cursor */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawTypewriterRegion(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint region_index,
    jint char_count, jboolean show_cursor);

/** 29. @ 0x016d94 (484 B): Draw single extra content element by index into BufferCanvasHelper byte array */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawExtraContent(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint extra_index);

/** 30. @ 0x016f78 (1,924 B): Return packed long[] of visible inline/block views up to typewriter step */
JNIEXPORT jlongArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetVisibleViews(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint char_count, jboolean include_block_views);

/** 31. @ 0x0176fc (744 B): Return String[] IDs of inline views whose visibility changed in [prev_step, cur_step] */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTypewriterChangedViews(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint prev_char_count, jint cur_char_count);

/** 32. @ 0x0179e4 (376 B): Return float[4] {left, top, width, height} of region_index */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionRect(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint region_index);

/** 33. @ 0x017b5c (304 B): Return float[4] {left, top, width, height} of extra_index */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentRect(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jint extra_index);

/** 34. @ 0x017c8c (156 B): Return number of regions in current page */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionCount(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 35. @ 0x017d28 (156 B): Return number of extra content items in current page */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentCount(
    JNIEnv* env, jobject thiz, jlong instance_ptr);

/** 36. @ 0x017dc4 (768 B): Return int[2] {first_idx, last_idx} of regions visible in [top_y, bottom_y] */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedRegion(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat top_y, jfloat bottom_y);

/** 37. @ 0x0180c4 (420 B): Return int[2] {first_idx, last_idx} of extra contents visible in [top_y, bottom_y] */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedExtraContent(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jfloat top_y, jfloat bottom_y);

/** 38. @ 0x018268 (440 B): Inherit horizontal scroll offsets from old_instance_ptr */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeInheritState(
    JNIEnv* env, jobject thiz, jlong instance_ptr, jlong old_instance_ptr);

} // extern "C"
