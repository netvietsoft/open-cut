/**
 * @file lynx_markdown_jni.cpp
 * @brief Clean-Room C++17 Implementation of 38 Exported JNI Entry Points of com.bytedance.xelement.markdown.MarkdownDocument
 *        Triển khai C++17 Tái cấu trúc sạch 38 điểm vào JNI xuất khẩu của com.bytedance.xelement.markdown.MarkdownDocument
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   SHA-256: 3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d
 *   Exported JNI Symbols: 38 functions (0x00d300..0x018420)
 */

#include "lynx_markdown_jni.h"
#include <cstring>
#include <algorithm>

namespace {

using namespace lynx::markdown;

/**
 * @brief Global cached JNI method table at `.bss + 0x03c068` (guarded by `.bss + 0x03c060` in `initial` @ 0x0117ec)
 *        Bảng phương thức JNI lưu đệm toàn cục tại `.bss + 0x03c068` (`initial` @ 0x0117ec)
 */
MarkdownJNIHelper g_markdown_jni_helper;

inline MarkdownDocument* ToDoc(jlong ptr) {
    return reinterpret_cast<MarkdownDocument*>(static_cast<uintptr_t>(ptr));
}

jbyteArray MakeJByteArray(JNIEnv* env, const std::vector<uint8_t>& bytes) {
    if (!env || !env->functions || !env->functions->NewByteArray || bytes.empty()) {
        return nullptr;
    }
    jbyteArray arr = env->functions->NewByteArray(env, static_cast<jint>(bytes.size()));
    if (arr && env->functions->SetByteArrayRegion) {
        env->functions->SetByteArrayRegion(
            env, arr, 0, static_cast<jint>(bytes.size()),
            reinterpret_cast<const jbyte*>(bytes.data()));
    }
    return arr;
}

jfloatArray MakeJFloatArray(JNIEnv* env, const float* vals, size_t count) {
    if (!env || !env->functions || !env->functions->NewFloatArray || count == 0) {
        return nullptr;
    }
    jfloatArray arr = env->functions->NewFloatArray(env, static_cast<jint>(count));
    if (arr && env->functions->SetFloatArrayRegion) {
        env->functions->SetFloatArrayRegion(env, arr, 0, static_cast<jint>(count), vals);
    }
    return arr;
}

jintArray MakeJIntArray(JNIEnv* env, const int32_t* vals, size_t count) {
    if (!env || !env->functions || !env->functions->NewIntArray || count == 0) {
        return nullptr;
    }
    jintArray arr = env->functions->NewIntArray(env, static_cast<jint>(count));
    if (arr && env->functions->SetIntArrayRegion) {
        env->functions->SetIntArrayRegion(env, arr, 0, static_cast<jint>(count), vals);
    }
    return arr;
}

} // anonymous namespace

extern "C" {

/**
 * 1. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance` (@ 0x00d300, 880 B)
 *    - Allocates `MarkdownDocument` (`mov w0, #0xe88; bl _Znwm` @ 0x00d328..0x00d334)
 *    - Allocates `MarkdownResourceLoader` (`mov w0, #0x18; bl _Znwm`, vtable `0x38018` @ 0x00d33c..0x00d350)
 *      and stores at `[doc + 0xe00]` (`str x21, [x19, #0xe00]` @ 0x00d5a4)
 *    - Initializes `style_.root_font_scale = 1.0f` (`mov w8, #0x3f800000; str w8, [x19, #0xd20]` @ 0x00d568..0x00d580)
 *    - Allocates `MarkdownEventListener` (`mov w0, #0x18; bl _Znwm`, vtable `0x38080` @ 0x00d57c..0x00d5d8)
 *      and stores at `[doc + 0xe08]` (`str x21, [x19, #0xe08]` @ 0x00d634)
 */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance(
    JNIEnv* /*env*/, jobject thiz) {
    auto* doc = new MarkdownDocument();
    doc->style_.root_font_scale = 1.0f; // +0xd20 = 0x3f800000
    doc->resource_loader_ = new MarkdownResourceLoader(thiz); // +0xe00
    doc->event_listener_ = new MarkdownEventListener(thiz);   // +0xe08
    auto default_fm = ttoffice::tttext::TTTextJNIProxy::GetInstance().GetDefaultFontManager();
    doc->font_collection_ = std::make_shared<ttoffice::tttext::FontmgrCollection>(default_fm); // +0xe28
    return static_cast<jlong>(reinterpret_cast<uintptr_t>(doc));
}

/**
 * 2. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse` (@ 0x00e718, 6,044 B)
 *    - Calls `GetStringUTFChars` (`+0x548` @ 0x00e768) and `GetStringUTFLength` (`+0x540` @ 0x00e784)
 *    - Slices UTF-8 codepoint range `[char_start, char_end)` (`0x00e9c0..0x00eaec`)
 *    - Runs embedded Discount (`magic = 0x19600731`) + GFM parser (`0x00eaec..0x00feb4`)
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jstring content,
    jint char_start, jint char_end, jfloat font_scale) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !content) return;

    const char* utf8 = nullptr;
    size_t utf8_len = 0;
    if (env && env->functions && env->functions->GetStringUTFChars) {
        utf8 = env->functions->GetStringUTFChars(env, content, nullptr);
        if (env->functions->GetStringUTFLength) {
            utf8_len = static_cast<size_t>(env->functions->GetStringUTFLength(env, content));
        } else if (utf8) {
            utf8_len = std::strlen(utf8);
        }
    } else {
        utf8 = reinterpret_cast<const char*>(content);
        utf8_len = std::strlen(utf8);
    }

    std::vector<ParsedBlockNode> blocks;
    ParseMarkdownDocument(doc, utf8, utf8_len, char_start, char_end, font_scale, &blocks);

    if (env && env->functions && env->functions->ReleaseStringUTFChars && utf8) {
        env->functions->ReleaseStringUTFChars(env, content, utf8);
    }
}

/**
 * 3. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeLayout` (@ 0x0102a0, 2,280 B)
 *    - Allocates `LayoutRegion` (`0xb0` = 176 bytes @ 0x0102e8) and lays out paragraphs & tables
 *    - Returns packed `(int64_t(width_bits) << 32) | height_bits`
 */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeLayout(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr, jfloat max_width,
    jfloat max_height, jint typewriter_step) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return 0;
    return LayoutMarkdownDocument(doc, max_width, max_height, typewriter_step);
}

/**
 * 4. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDestroyInstance` (@ 0x010b88, 752 B)
 *    - Virtual destructor call on `doc->resource_loader_` (`[x2, #0xe00]` @ 0x010b94)
 *    - Virtual destructor call on `doc->event_listener_` (`[x19, #0xe08]` @ 0x010bac)
 *    - Releases `syntax_ranges_` (`+0xe70`), `offset_map_` (`+0xe58`), `font_collection_` (`+0xe30`),
 *      `current_page_` (`+0x78`), `page_mutex_` (`+0x48`), `images_` (`+0x30`), `links_` (`+0x18`),
 *      `inline_delegates_` (`+0x00`), and `delete doc` (`0x010e74`).
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDestroyInstance(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return;
    delete doc->resource_loader_;
    doc->resource_loader_ = nullptr;
    delete doc->event_listener_;
    doc->event_listener_ = nullptr;
    delete doc;
}

/**
 * 5. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDraw` (@ 0x011100, 404 B)
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDraw(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    std::vector<uint8_t> stream = DrawMarkdownPageToBuffer(doc);
    return MakeJByteArray(env, stream);
}

/**
 * 6. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawWithCursor` (@ 0x011294, 660 B)
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawWithCursor(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint char_count, jboolean show_cursor) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    std::vector<uint8_t> stream = DrawMarkdownPageWithCursorToBuffer(doc, char_count, show_cursor != 0);
    return MakeJByteArray(env, stream);
}

/**
 * 7. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCursorPosition` (@ 0x011528, 708 B)
 */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCursorPosition(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint char_count, jboolean is_custom_cursor) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    float xyh[3] = {0.0f, 0.0f, 0.0f};
    ComputeTypewriterCursorPosition(doc, char_count, is_custom_cursor != 0, xyh);
    return MakeJFloatArray(env, xyh, 3);
}

/**
 * 8. `Java_com_bytedance_xelement_markdown_MarkdownDocument_initial` (@ 0x0117ec, 664 B)
 *    - Calls `env->GetJavaVM(&vm)` (`+0x6d8` @ 0x011818) and `lynx::base::android::InitVM(vm)` (`0x035550`)
 *    - Resolves `com/bytedance/xelement/markdown/MarkdownDocument` (`0x005424`) and caches 6 methods:
 *      1) `loadImage` `(Ljava/lang/String;FFFF)I` -> `+0x10`
 *      2) `measureInlineView` `(Ljava/lang/String;FF)I` -> `+0x20`
 *      3) `loadFont` `(Ljava/lang/String;I)I` -> `+0x18`
 *      4) `getRunDelegateSize` `(I)[F` -> `+0x28`
 *      5) `onTextOverflow` `(Ljava/lang/String;)V` -> `+0x30`
 *      6) `loadGradient` `(Ljava/lang/String;FF)I` -> `+0x38`
 *    - Caches `java/lang/String` (`0x005751`) global ref at `+0x40`
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_initial(
    JNIEnv* env, jclass /*clazz*/) {
    JavaVM* vm = nullptr;
    if (env && env->functions && env->functions->GetJavaVM) {
        env->functions->GetJavaVM(env, &vm);
    }
    lynx::base::android::InitVM(vm);
    g_markdown_jni_helper.jvm = vm;

    if (env && env->functions && env->functions->FindClass && env->functions->GetMethodID) {
        jclass md_cls = env->functions->FindClass(
            env, "com/bytedance/xelement/markdown/MarkdownDocument");
        if (md_cls) {
            g_markdown_jni_helper.markdown_doc_class.ResetNewGlobalRef(env, md_cls);
            g_markdown_jni_helper.load_image_method = env->functions->GetMethodID(
                env, md_cls, "loadImage", "(Ljava/lang/String;FFFF)I");
            g_markdown_jni_helper.measure_inline_view_method = env->functions->GetMethodID(
                env, md_cls, "measureInlineView", "(Ljava/lang/String;FF)I");
            g_markdown_jni_helper.load_font_method = env->functions->GetMethodID(
                env, md_cls, "loadFont", "(Ljava/lang/String;I)I");
            g_markdown_jni_helper.get_run_delegate_size_method = env->functions->GetMethodID(
                env, md_cls, "getRunDelegateSize", "(I)[F");
            g_markdown_jni_helper.on_text_overflow_method = env->functions->GetMethodID(
                env, md_cls, "onTextOverflow", "(Ljava/lang/String;)V");
            g_markdown_jni_helper.load_gradient_method = env->functions->GetMethodID(
                env, md_cls, "loadGradient", "(Ljava/lang/String;FF)I");
        }
        jclass str_cls = env->functions->FindClass(env, "java/lang/String");
        if (str_cls) {
            g_markdown_jni_helper.string_class.ResetNewGlobalRef(env, str_cls);
        }
    }
    g_markdown_jni_helper.initialized = true;
}

/**
 * 9. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeSetStyle` (@ 0x011a84, 1,016 B)
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeSetStyle(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jbyteArray style_bytes) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !style_bytes) return;

    jbyte* elems = nullptr;
    jint len = 0;
    if (env && env->functions && env->functions->GetByteArrayElements && env->functions->GetArrayLength) {
        elems = env->functions->GetByteArrayElements(env, style_bytes, nullptr);
        len = env->functions->GetArrayLength(env, style_bytes);
    }
    if (elems && len > 0) {
        StyleValue root;
        if (DeserializeStyleBuffer(reinterpret_cast<const uint8_t*>(elems),
                                   static_cast<size_t>(len), &root)) {
            ApplyMarkdownStyleSheet(root, &doc->style_);
        }
    }
    if (env && env->functions && env->functions->ReleaseByteArrayElements && elems) {
        env->functions->ReleaseByteArrayElements(env, style_bytes, elems, 0);
    }
}

/**
 * 10. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkByPosition` (@ 0x013254, 472 B)
 */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkByPosition(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat touch_x, jfloat touch_y) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || doc->links_.empty()) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page) return nullptr;

    for (const auto& link : doc->links_) {
        auto rects = ComputeSelectionRectsByCharRange(
            page.get(),
            static_cast<int32_t>(link.char_start),
            static_cast<int32_t>(link.char_start + link.char_count));
        for (const auto& r : rects) {
            if (r.Contains(touch_x, touch_y)) {
                if (env && env->functions && env->functions->NewObjectArray) {
                    jobjectArray arr = env->functions->NewObjectArray(
                        env, 2, g_markdown_jni_helper.string_class.Get(), nullptr);
                    if (arr && env->functions->SetObjectArrayElement) {
                        jstring u = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, link.url.c_str());
                        jstring c = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, link.content.c_str());
                        env->functions->SetObjectArrayElement(env, arr, 0, u);
                        env->functions->SetObjectArrayElement(env, arr, 1, c);
                    }
                    return arr;
                }
                return nullptr;
            }
        }
    }
    return nullptr;
}

/**
 * 11. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetInlineViewOrigin` (@ 0x01342c, 1,328 B)
 */
JNIEXPORT jlong JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetInlineViewOrigin(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jstring view_id, jint char_count) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !view_id) return -1;

    const char* id_cstr = nullptr;
    if (env && env->functions && env->functions->GetStringUTFChars) {
        id_cstr = env->functions->GetStringUTFChars(env, view_id, nullptr);
    } else {
        id_cstr = reinterpret_cast<const char*>(view_id);
    }
    std::string key(id_cstr ? id_cstr : "");
    if (env && env->functions && env->functions->ReleaseStringUTFChars && id_cstr) {
        env->functions->ReleaseStringUTFChars(env, view_id, id_cstr);
    }

    auto it = doc->inline_views_.find(key);
    if (it == doc->inline_views_.end()) {
        return -1;
    }
    if (char_count >= 0 && static_cast<int32_t>(it->second.char_index) > char_count) {
        return -1;
    }
    uint32_t x_bits = 0;
    uint32_t y_bits = 0;
    std::memcpy(&x_bits, &it->second.origin_rect.left, sizeof(uint32_t));
    std::memcpy(&y_bits, &it->second.origin_rect.top, sizeof(uint32_t));
    return (static_cast<jlong>(x_bits) << 32) | static_cast<jlong>(y_bits);
}

/**
 * 12. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetContentByCharRange` (@ 0x01395c, 752 B)
 */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetContentByCharRange(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint char_start, jint char_end) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || page->plain_u16_text.empty() || char_start >= char_end) {
        return lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, "");
    }

    size_t s = static_cast<size_t>(std::max(0, char_start));
    size_t e = std::min(page->plain_u16_text.size(), static_cast<size_t>(std::max(0, char_end)));
    std::string out_u8;
    for (size_t i = s; i < e; ++i) {
        char16_t u = page->plain_u16_text[i];
        if (u < 0x80u) {
            out_u8.push_back(static_cast<char>(u));
        } else if (u < 0x800u) {
            out_u8.push_back(static_cast<char>(0xC0u | (u >> 6)));
            out_u8.push_back(static_cast<char>(0x80u | (u & 0x3Fu)));
        } else {
            out_u8.push_back(static_cast<char>(0xE0u | (u >> 12)));
            out_u8.push_back(static_cast<char>(0x80u | ((u >> 6) & 0x3Fu)));
            out_u8.push_back(static_cast<char>(0x80u | (u & 0x3Fu)));
        }
    }
    return lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, out_u8.c_str());
}

/**
 * 13. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSelectionRectByCharPos` (@ 0x013c4c, 1,136 B)
 */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSelectionRectByCharPos(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint char_start, jint char_end) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page) return nullptr;

    auto rects = ComputeSelectionRectsByCharRange(page.get(), char_start, char_end);
    std::vector<float> flat;
    flat.reserve(rects.size() * 4);
    for (const auto& r : rects) {
        flat.push_back(r.left);
        flat.push_back(r.top);
        flat.push_back(r.Width());
        flat.push_back(r.Height());
    }
    return MakeJFloatArray(env, flat.data(), flat.size());
}

/**
 * 14. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCharRangeByPoint` (@ 0x0140bc, 308 B)
 */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetCharRangeByPoint(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat touch_x, jfloat touch_y, jint split_type) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    int32_t range[2] = {-1, -1};
    if (page) {
        ComputeCharRangeByPoint(page.get(), touch_x, touch_y, split_type, range);
    }
    return MakeJIntArray(env, range, 2);
}

/**
 * 15. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetPageCharCount` (@ 0x0141f0, 228 B)
 *     - Locks `doc->page_mutex_` (`+0x48`), loads `page = doc->current_page_` (`+0x70`), unlocks.
 *     - Inspects `page->regions.back()`: if `block_type == 1` (Table @ 0x014248), returns last cell's cumulative char count (`table_cell_char_counts.back()`), else returns `region->char_end`.
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetPageCharCount(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return 0;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || page->regions.empty()) return 0;

    const auto& last_reg = page->regions.back();
    if (!last_reg) return 0;
    if (last_reg->block_type == 1 && !last_reg->table_cell_char_counts.empty()) {
        return static_cast<jint>(last_reg->table_cell_char_counts.back());
    }
    return static_cast<jint>(last_reg->char_end);
}

/**
 * 16. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeMarkdownOffsetToChar` (@ 0x0142d4, 132 B)
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeMarkdownOffsetToChar(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr, jint markdown_offset) {
    const MarkdownDocument* doc = ToDoc(instance_ptr);
    return static_cast<jint>(ConvertMarkdownOffsetToChar(doc, markdown_offset));
}

/**
 * 17. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinks` (@ 0x014358, 560 B)
 */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinks(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || doc->links_.empty() || !env || !env->functions || !env->functions->NewObjectArray) {
        return nullptr;
    }
    jint total = static_cast<jint>(doc->links_.size() * 2);
    jobjectArray arr = env->functions->NewObjectArray(
        env, total, g_markdown_jni_helper.string_class.Get(), nullptr);
    if (arr && env->functions->SetObjectArrayElement) {
        for (size_t i = 0; i < doc->links_.size(); ++i) {
            jstring u = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, doc->links_[i].url.c_str());
            jstring c = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, doc->links_[i].content.c_str());
            env->functions->SetObjectArrayElement(env, arr, static_cast<jint>(i * 2), u);
            env->functions->SetObjectArrayElement(env, arr, static_cast<jint>(i * 2 + 1), c);
        }
    }
    return arr;
}

/**
 * 18. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkRects` (@ 0x0146d4, 1,588 B)
 */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetLinkRects(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || doc->links_.empty()) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page) return nullptr;

    std::vector<float> flat;
    for (const auto& link : doc->links_) {
        auto rects = ComputeSelectionRectsByCharRange(
            page.get(),
            static_cast<int32_t>(link.char_start),
            static_cast<int32_t>(link.char_start + link.char_count));
        for (const auto& r : rects) {
            flat.push_back(r.left);
            flat.push_back(r.top);
            flat.push_back(r.right);
            flat.push_back(r.bottom);
        }
    }
    return MakeJFloatArray(env, flat.data(), flat.size());
}

/**
 * 19. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSyntaxRange` (@ 0x014d08, 1,176 B)
 */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetSyntaxRange(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jstring syntax_tag) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !syntax_tag) return nullptr;

    const char* tag_cstr = nullptr;
    if (env && env->functions && env->functions->GetStringUTFChars) {
        tag_cstr = env->functions->GetStringUTFChars(env, syntax_tag, nullptr);
    } else {
        tag_cstr = reinterpret_cast<const char*>(syntax_tag);
    }
    std::string tag(tag_cstr ? tag_cstr : "");
    if (env && env->functions && env->functions->ReleaseStringUTFChars && tag_cstr) {
        env->functions->ReleaseStringUTFChars(env, syntax_tag, tag_cstr);
    }

    std::vector<int32_t> flat;
    for (const auto& sr : doc->syntax_ranges_) {
        if (sr.syntax_tag == tag) {
            flat.push_back(sr.char_start);
            flat.push_back(sr.char_end);
        }
    }
    return MakeJIntArray(env, flat.data(), flat.size());
}

/**
 * 20. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImages` (@ 0x0151a0, 608 B)
 */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImages(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || doc->images_.empty() || !env || !env->functions || !env->functions->NewObjectArray) {
        return nullptr;
    }
    jobjectArray arr = env->functions->NewObjectArray(
        env, static_cast<jint>(doc->images_.size()),
        g_markdown_jni_helper.string_class.Get(), nullptr);
    if (arr && env->functions->SetObjectArrayElement) {
        for (size_t i = 0; i < doc->images_.size(); ++i) {
            jstring u = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, doc->images_[i].url.c_str());
            env->functions->SetObjectArrayElement(env, arr, static_cast<jint>(i), u);
        }
    }
    return arr;
}

/**
 * 21. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImageByTouchPosition` (@ 0x015400, 556 B)
 */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetImageByTouchPosition(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat touch_x, jfloat touch_y) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || doc->images_.empty()) return nullptr;

    for (const auto& img : doc->images_) {
        if (img.rect.Contains(touch_x, touch_y)) {
            return lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, img.url.c_str());
        }
    }
    return nullptr;
}

/**
 * 22. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAllowBreakAroundPunctuation` (@ 0x01562c, 16 B)
 *     Exact 4-instruction AArch64 function:
 *       `0x01562c: 72001c7f  tst  w3, #0xff`
 *       `0x015630: 1a9f07e8  cset w8, ne`
 *       `0x015634: 3938e048  strb w8, [x2, #0xe38]`
 *       `0x015638: d65f03c0  ret`
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAllowBreakAroundPunctuation(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr, jboolean allow) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return;
    doc->allow_break_around_punctuation_ = (allow != 0); // [doc + 0xe38]
}

/**
 * 23. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeOnTouchEvent` (@ 0x01563c, 820 B)
 */
JNIEXPORT jboolean JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeOnTouchEvent(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr,
    jfloat touch_x, jfloat touch_y, jint action) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return 0;

    doc->touch_consumed_ = false; // strb wzr, [x2, #0xe50] @ 0x015664
    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || page->regions.empty()) return 0;

    uint8_t act = static_cast<uint8_t>(action & 0xFF);
    if (act == 1) { // ACTION_DOWN (`cmp w10, #1` @ 0x0156a4)
        doc->touch_down_x_ = touch_x; // str s9, [x20, #0xe3c] @ 0x0156b0
        doc->touch_down_y_ = touch_y;
        doc->is_touch_down_ = false;
        doc->active_touch_target_ = -1;
        for (size_t i = 0; i < page->regions.size(); ++i) {
            const auto& r = page->regions[i];
            if (r && r->scroll_x && r->border_rect.Contains(touch_x, touch_y)) {
                doc->is_touch_down_ = true;
                doc->active_touch_target_ = static_cast<int64_t>(i);
                doc->touch_consumed_ = true;
                return 1;
            }
        }
    } else if (act == 2 && doc->is_touch_down_) { // ACTION_MOVE
        if (doc->active_touch_target_ >= 0 &&
            static_cast<size_t>(doc->active_touch_target_) < page->regions.size()) {
            auto& r = page->regions[static_cast<size_t>(doc->active_touch_target_)];
            if (r && r->scroll_x) {
                float dx = doc->touch_down_x_ - touch_x;
                r->scroll_offset_x = std::max(0.0f, r->scroll_offset_x + dx);
                doc->touch_down_x_ = touch_x;
                doc->touch_down_y_ = touch_y;
                doc->touch_consumed_ = true;
                return 1;
            }
        }
    } else { // ACTION_UP / ACTION_CANCEL
        doc->is_touch_down_ = false;
        doc->active_touch_target_ = -1;
    }
    return doc->touch_consumed_ ? 1 : 0;
}

/**
 * 24. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAddTextMarkAttachment` (@ 0x015970, 3,048 B)
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAddTextMarkAttachment(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jbyteArray attachment_bytes) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !attachment_bytes) return;

    jbyte* elems = nullptr;
    jint len = 0;
    if (env && env->functions && env->functions->GetByteArrayElements && env->functions->GetArrayLength) {
        elems = env->functions->GetByteArrayElements(env, attachment_bytes, nullptr);
        len = env->functions->GetArrayLength(env, attachment_bytes);
    }
    if (elems && len > 0) {
        MarkdownTextAttachment att;
        if (ParseTextMarkAttachment(reinterpret_cast<const uint8_t*>(elems),
                                    static_cast<size_t>(len), &att)) {
            doc->pending_attachments_.push_back(att);
            std::shared_ptr<MarkdownPage> page;
            {
                std::lock_guard<std::mutex> lock(doc->page_mutex_);
                page = doc->current_page_;
            }
            if (page) {
                auto live_att = std::make_unique<MarkdownTextAttachment>(att);
                int32_t c_start = live_att->is_markdown_offset
                                      ? ConvertMarkdownOffsetToChar(doc, live_att->start_pos)
                                      : live_att->start_pos;
                int32_t c_end = live_att->is_markdown_offset
                                    ? ConvertMarkdownOffsetToChar(doc, live_att->end_pos)
                                    : live_att->end_pos;
                live_att->rects = ComputeSelectionRectsByCharRange(page.get(), c_start, c_end);
                page->attachments.push_back(std::move(live_att));
            }
        }
    }
    if (env && env->functions && env->functions->ReleaseByteArrayElements && elems) {
        env->functions->ReleaseByteArrayElements(env, attachment_bytes, elems, 0);
    }
}

/**
 * 25. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeClearTextMarkAttachment` (@ 0x01666c, 208 B)
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeClearTextMarkAttachment(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return;
    doc->pending_attachments_.clear();
    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (page) {
        page->attachments.clear();
    }
}

/**
 * 26. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTextClickByPoint` (@ 0x01673c, 512 B)
 */
JNIEXPORT jstring JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTextClickByPoint(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat touch_x, jfloat touch_y) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || page->attachments.empty()) return nullptr;

    for (const auto& att : page->attachments) {
        if (!att || !att->clickable) continue;
        for (const auto& r : att->rects) {
            if (r.Contains(touch_x, touch_y)) {
                return lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, att->id.c_str());
            }
        }
    }
    return nullptr;
}

/**
 * 27. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawRegion` (@ 0x01693c, 424 B)
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawRegion(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint region_index) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    auto stream = DrawSingleRegionToBuffer(doc, region_index);
    return MakeJByteArray(env, stream);
}

/**
 * 28. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawTypewriterRegion` (@ 0x016ae4, 688 B)
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawTypewriterRegion(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint region_index,
    jint char_count, jboolean show_cursor) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    auto stream = DrawTypewriterRegionToBuffer(doc, region_index, char_count, show_cursor != 0);
    return MakeJByteArray(env, stream);
}

/**
 * 29. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawExtraContent` (@ 0x016d94, 484 B)
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDrawExtraContent(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint extra_index) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;
    auto stream = DrawSingleExtraContentToBuffer(doc, extra_index);
    return MakeJByteArray(env, stream);
}

/**
 * 30. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetVisibleViews` (@ 0x016f78, 1,924 B)
 */
JNIEXPORT jlongArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetVisibleViews(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint char_count, jboolean include_block_views) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !env || !env->functions || !env->functions->NewLongArray) return nullptr;

    std::vector<jlong> packed;
    for (const auto& kv : doc->inline_views_) {
        const auto& iv = kv.second;
        if (!include_block_views && iv.is_block_view) continue;
        if (char_count < 0 || static_cast<int32_t>(iv.char_index) <= char_count) {
            uint32_t x_bits = 0;
            uint32_t y_bits = 0;
            std::memcpy(&x_bits, &iv.origin_rect.left, sizeof(uint32_t));
            std::memcpy(&y_bits, &iv.origin_rect.top, sizeof(uint32_t));
            packed.push_back((static_cast<jlong>(x_bits) << 32) | static_cast<jlong>(y_bits));
        }
    }
    if (packed.empty()) return nullptr;
    jlongArray arr = env->functions->NewLongArray(env, static_cast<jint>(packed.size()));
    if (arr && env->functions->SetLongArrayRegion) {
        env->functions->SetLongArrayRegion(env, arr, 0, static_cast<jint>(packed.size()), packed.data());
    }
    return arr;
}

/**
 * 31. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTypewriterChangedViews` (@ 0x0176fc, 744 B)
 */
JNIEXPORT jobjectArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetTypewriterChangedViews(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint prev_char_count, jint cur_char_count) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || !env || !env->functions || !env->functions->NewObjectArray) return nullptr;

    int32_t lo = std::min(prev_char_count, cur_char_count);
    int32_t hi = std::max(prev_char_count, cur_char_count);
    std::vector<std::string> changed;
    for (const auto& kv : doc->inline_views_) {
        int32_t ci = static_cast<int32_t>(kv.second.char_index);
        if (ci > lo && ci <= hi) {
            changed.push_back(kv.first);
        }
    }
    if (changed.empty()) return nullptr;
    jobjectArray arr = env->functions->NewObjectArray(
        env, static_cast<jint>(changed.size()),
        g_markdown_jni_helper.string_class.Get(), nullptr);
    if (arr && env->functions->SetObjectArrayElement) {
        for (size_t i = 0; i < changed.size(); ++i) {
            jstring s = lynx::base::android::JNIConvertHelper::ConvertToJNIStringUTF(env, changed[i].c_str());
            env->functions->SetObjectArrayElement(env, arr, static_cast<jint>(i), s);
        }
    }
    return arr;
}

/**
 * 32. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionRect` (@ 0x0179e4, 376 B)
 */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionRect(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint region_index) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || region_index < 0) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    float rect[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    if (page && static_cast<size_t>(region_index) < page->regions.size()) {
        const auto& r = page->regions[static_cast<size_t>(region_index)];
        if (r) {
            rect[0] = r->padding_rect.left;
            rect[1] = r->padding_rect.top;
            rect[2] = r->padding_rect.Width();
            rect[3] = r->padding_rect.Height();
        }
    }
    return MakeJFloatArray(env, rect, 4);
}

/**
 * 33. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentRect` (@ 0x017b5c, 304 B)
 */
JNIEXPORT jfloatArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentRect(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jint extra_index) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc || extra_index < 0) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    float rect[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    if (page && static_cast<size_t>(extra_index) < page->extra_contents.size()) {
        const auto& ex = page->extra_contents[static_cast<size_t>(extra_index)];
        if (ex) {
            rect[0] = ex->rect.left;
            rect[1] = ex->rect.top;
            rect[2] = ex->rect.Width();
            rect[3] = ex->rect.Height();
        }
    }
    return MakeJFloatArray(env, rect, 4);
}

/**
 * 34. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionCount` (@ 0x017c8c, 156 B)
 *     - Locks `doc->page_mutex_` (`+0x48`), loads `page = doc->current_page_` (`+0x70`), unlocks.
 *     - Returns `(page->regions.end() - page->regions.begin())` (`ldp x8, x9, [x21, #0x18]; sub x8, x9, x8; lsr x20, x8, #3` @ 0x017ccc..0x017cd4).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionCount(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return 0;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    return page ? static_cast<jint>(page->regions.size()) : 0;
}

/**
 * 35. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentCount` (@ 0x017d28, 156 B)
 *     - Locks `doc->page_mutex_` (`+0x48`), loads `page = doc->current_page_` (`+0x70`), unlocks.
 *     - Returns `(page->extra_contents.end() - page->extra_contents.begin())` (`ldp x8, x9, [x21, #0x80]; sub x8, x9, x8; lsr x20, x8, #3` @ 0x017d68..0x017d70).
 */
JNIEXPORT jint JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentCount(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return 0;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    return page ? static_cast<jint>(page->extra_contents.size()) : 0;
}

/**
 * 36. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedRegion` (@ 0x017dc4, 768 B)
 */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedRegion(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat top_y, jfloat bottom_y) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    int32_t range[2] = {-1, -1};
    if (page) {
        ComputeShowedRegionRange(page.get(), top_y, bottom_y, range);
    }
    return MakeJIntArray(env, range, 2);
}

/**
 * 37. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedExtraContent` (@ 0x0180c4, 420 B)
 */
JNIEXPORT jintArray JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetShowedExtraContent(
    JNIEnv* env, jobject /*thiz*/, jlong instance_ptr, jfloat top_y, jfloat bottom_y) {
    MarkdownDocument* doc = ToDoc(instance_ptr);
    if (!doc) return nullptr;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    int32_t range[2] = {-1, -1};
    if (page) {
        ComputeShowedExtraContentRange(page.get(), top_y, bottom_y, range);
    }
    return MakeJIntArray(env, range, 2);
}

/**
 * 38. `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeInheritState` (@ 0x018268, 440 B)
 */
JNIEXPORT void JNICALL
Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeInheritState(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong instance_ptr, jlong old_instance_ptr) {
    MarkdownDocument* dst_doc = ToDoc(instance_ptr);
    const MarkdownDocument* src_doc = ToDoc(old_instance_ptr);
    InheritDocumentScrollState(dst_doc, src_doc);
}

} // extern "C"
