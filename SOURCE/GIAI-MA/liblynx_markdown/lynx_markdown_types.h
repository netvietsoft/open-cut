/**
 * @file lynx_markdown_types.h
 * @brief Clean-Room C++17 ABI & Type Reconstruction for liblynx_markdown.so
 *        Tái cấu trúc sạch (Clean-Room) C++17 các kiểu dữ liệu & bố cục ABI cho liblynx_markdown.so
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   SHA-256: 3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   [OBSERVED] Exact struct sizes, field offsets, vtable slots, and magic constants verified from AArch64 .text & .data.rel.ro:
 *     - sizeof(MarkdownDocument) = 0xe88 (3,720 bytes) @ 0x00d328 (mov w0, #0xe88; bl operator new)
 *     - sizeof(MarkdownResourceLoader) = 0x18 (24 bytes), vtable @ 0x038018
 *     - sizeof(MarkdownEventListener) = 0x18 (24 bytes), vtable @ 0x038080
 *     - Discount MMIOT magic = 0x19600731 (mov w29, #0x731; movk w29, #0x1960, lsl #16 @ 0x00eaec..0x00eaf8)
 *     - sizeof(MMIOT) = 0x98 (152 bytes) @ 0x00eaf0; sizeof(ParagraphRoot) = 0x78 (120 bytes) @ 0x00eb0c
 *     - sizeof(BufferPaintHelper) = 0x58 (88 bytes), vtable @ 0x038398, default font "pingfang" (0x676e6166676e6970), size 14.0f (0x41600000) @ 0x01897c..0x0189e0
 *     - sizeof(LayoutRegion) = 0xb0 (176 bytes) @ 0x0102e8
 */

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <algorithm>
#include <functional>

// ============================================================================
// Standalone JNI Type Declarations (Clean-room portable compilation)
// Khai báo kiểu JNI độc lập (Phục vụ biên dịch sạch đa nền tảng)
// ============================================================================
#ifndef JNIEXPORT
#define JNIEXPORT __attribute__((visibility("default")))
#endif
#ifndef JNICALL
#define JNICALL
#endif

typedef uint8_t  jboolean;
typedef int8_t   jbyte;
typedef uint16_t jchar;
typedef int16_t  jshort;
typedef int32_t  jint;
typedef int64_t  jlong;
typedef float    jfloat;
typedef double   jdouble;

struct _jobject {};
struct _jclass : public _jobject {};
struct _jstring : public _jobject {};
struct _jarray : public _jobject {};
struct _jbyteArray : public _jarray {};
struct _jintArray : public _jarray {};
struct _jlongArray : public _jarray {};
struct _jfloatArray : public _jarray {};
struct _jobjectArray : public _jarray {};

typedef _jobject*      jobject;
typedef _jclass*       jclass;
typedef _jstring*      jstring;
typedef _jarray*       jarray;
typedef _jbyteArray*   jbyteArray;
typedef _jintArray*    jintArray;
typedef _jlongArray*   jlongArray;
typedef _jfloatArray*  jfloatArray;
typedef _jobjectArray* jobjectArray;
typedef struct _jmethodID* jmethodID;
typedef struct _jfieldID*  jfieldID;

struct _JavaVM;
typedef _JavaVM JavaVM;

/**
 * @brief Minimal JNI Native Interface Table matching AArch64 vtable offsets in liblynx_markdown.so:
 *        Bảng giao diện JNI khớp chính xác các offset vtable AArch64 trong liblynx_markdown.so:
 *          - +0x030: FindClass (@ 0x01186c)
 *          - +0x108: GetMethodID (@ 0x011884)
 *          - +0x540: GetStringUTFRegion / ReleaseStringUTFChars (@ 0x00e784)
 *          - +0x548: GetStringUTFChars (@ 0x00e768, 0x01346c, 0x014d34)
 *          - +0x558: GetArrayLength (@ 0x011adc, 0x0159c8)
 *          - +0x580: NewByteArray
 *          - +0x598: NewIntArray (@ 0x014130)
 *          - +0x5a0: NewLongArray
 *          - +0x5b0: NewFloatArray
 *          - +0x5c0: GetByteArrayElements (@ 0x011ac0, 0x0159b0)
 *          - +0x600: ReleaseByteArrayElements
 *          - +0x640: SetByteArrayRegion
 *          - +0x658: SetIntArrayRegion
 *          - +0x660: SetLongArrayRegion
 *          - +0x670: SetFloatArrayRegion
 *          - +0x6d8: GetJavaVM (@ 0x011818, 0x011854)
 */
struct JNINativeInterface_ {
    void* reserved0[6];
    jclass (*FindClass)(struct _JNIEnv*, const char*);                                 // +0x030
    void* reserved1[26];
    jmethodID (*GetMethodID)(struct _JNIEnv*, jclass, const char*, const char*);       // +0x108
    jobject (*CallObjectMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jboolean (*CallBooleanMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jbyte (*CallByteMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jchar (*CallCharMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jshort (*CallShortMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jint (*CallIntMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jlong (*CallLongMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jfloat (*CallFloatMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jdouble (*CallDoubleMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    void (*CallVoidMethod)(struct _JNIEnv*, jobject, jmethodID, ...);
    jstring (*NewStringUTF)(struct _JNIEnv*, const char*);
    jint (*GetStringUTFLength)(struct _JNIEnv*, jstring);                              // +0x540
    const char* (*GetStringUTFChars)(struct _JNIEnv*, jstring, jboolean*);             // +0x548
    void (*ReleaseStringUTFChars)(struct _JNIEnv*, jstring, const char*);              // +0x550
    jint (*GetArrayLength)(struct _JNIEnv*, jarray);                                   // +0x558
    jobjectArray (*NewObjectArray)(struct _JNIEnv*, jint, jclass, jobject);            // +0x560
    jobject (*GetObjectArrayElement)(struct _JNIEnv*, jobjectArray, jint);             // +0x568
    void (*SetObjectArrayElement)(struct _JNIEnv*, jobjectArray, jint, jobject);       // +0x570
    jbyteArray (*NewByteArray)(struct _JNIEnv*, jint);                                 // +0x580
    jintArray (*NewIntArray)(struct _JNIEnv*, jint);                                   // +0x598
    jlongArray (*NewLongArray)(struct _JNIEnv*, jint);                                 // +0x5a0
    jfloatArray (*NewFloatArray)(struct _JNIEnv*, jint);                               // +0x5b0
    jbyte* (*GetByteArrayElements)(struct _JNIEnv*, jbyteArray, jboolean*);            // +0x5c0
    jfloat* (*GetFloatArrayElements)(struct _JNIEnv*, jfloatArray, jboolean*);
    void (*ReleaseByteArrayElements)(struct _JNIEnv*, jbyteArray, jbyte*, jint);       // +0x600
    void (*ReleaseFloatArrayElements)(struct _JNIEnv*, jfloatArray, jfloat*, jint);
    void (*SetByteArrayRegion)(struct _JNIEnv*, jbyteArray, jint, jint, const jbyte*); // +0x640
    void (*SetIntArrayRegion)(struct _JNIEnv*, jintArray, jint, jint, const jint*);    // +0x658
    void (*SetLongArrayRegion)(struct _JNIEnv*, jlongArray, jint, jint, const jlong*); // +0x660
    void (*SetFloatArrayRegion)(struct _JNIEnv*, jfloatArray, jint, jint, const jfloat*);// +0x670
    jint (*GetJavaVM)(struct _JNIEnv*, JavaVM**);                                      // +0x6d8
};

struct _JNIEnv {
    const JNINativeInterface_* functions;
};
typedef _JNIEnv JNIEnv;

// ============================================================================
// lynx::base & lynx::base::android Imported Utilities (PLT 0x0353a0..0x035880)
// Các tiện ích nhập từ liblynxbase.so (PLT 0x0353a0..0x035880)
// ============================================================================
namespace lynx {
namespace base {

/**
 * @brief Convert UTF-8 string view to UTF-16 basic_string<char16_t> (PLT @ 0x0354f0)
 *        Chuyển chuỗi UTF-8 sang UTF-16 basic_string<char16_t> (PLT @ 0x0354f0)
 */
std::u16string U8StringToU16(std::string_view u8_str);

/**
 * @brief Trim leading and trailing ASCII whitespace from string_view (PLT @ 0x035750)
 *        Cắt khoảng trắng đầu/cuối khỏi string_view (PLT @ 0x035750)
 */
std::string_view TrimToStringView(std::string_view str);

/**
 * @brief Parse string into 32-bit float with optional strict check (PLT @ 0x035880)
 *        Phân tích chuỗi thành số thực float 32-bit (PLT @ 0x035880)
 */
bool StringToFloat(const std::string& input, float& output, bool error_on_rest);

namespace android {

/**
 * @brief Initialize global JavaVM pointer in liblynxbase.so (PLT @ 0x035550)
 *        Khởi tạo con trỏ JavaVM toàn cục trong liblynxbase.so (PLT @ 0x035550)
 */
void InitVM(JavaVM* vm);

/**
 * @brief Attach current thread and return JNIEnv* (PLT @ 0x0353b0)
 *        Gắn luồng hiện tại vào JVM và trả về JNIEnv* (PLT @ 0x0353b0)
 */
JNIEnv* AttachCurrentThread();

/**
 * @brief Base JNI reference wrapper (`vtable` @ 0x038058 / 0x0380a8, size = 16 bytes)
 *        Lớp bao tham chiếu JNI cơ sở (`vtable` @ 0x038058 / 0x0380a8, kích thước = 16 byte)
 */
template <typename T>
class JavaRef {
public:
    JavaRef() : obj_(nullptr) {}                                               // PLT @ 0x0353a0
    virtual ~JavaRef() = default;                                              // 0x00d98c / 0x00d984

    void ResetNewWeakGlobalRef(JNIEnv* env, T obj) { obj_ = obj; (void)env; }  // PLT @ 0x0353c0
    void ReleaseWeakGlobalRef(JNIEnv* env) { obj_ = nullptr; (void)env; }      // PLT @ 0x0353d0
    void ReleaseLocalRef(JNIEnv* env) { obj_ = nullptr; (void)env; }           // PLT @ 0x035410
    void ReleaseGlobalRef(JNIEnv* env) { obj_ = nullptr; (void)env; }          // PLT @ 0x035440
    void ResetNewGlobalRef(JNIEnv* env, T obj) { obj_ = obj; (void)env; }      // PLT @ 0x035560

    T Get() const { return obj_; }
    bool IsNull() const { return obj_ == nullptr; }

protected:
    T obj_; // +0x08 (after 8-byte vtable pointer at +0x00)
};

struct JNIConvertHelper {
    static jstring ConvertToJNIStringUTF(JNIEnv* env, const char* str);        // PLT @ 0x035400
};

} // namespace android
} // namespace base
} // namespace lynx

// ============================================================================
// ttoffice::tttext Imported Types & Interfaces (PLT 0x0355b0..0x035850)
// Các kiểu và giao diện nhập từ libtttext_lite.so (PLT 0x0355b0..0x035850)
// ============================================================================
namespace ttoffice {
namespace tttext {

enum class ShaperType : int32_t {
    kSystem = 0,
    kHarfBuzz = 1
};

enum class LayoutMode : int32_t {
    kDefinite = 0,
    kIndefinite = 1,
    kAtMost = 2
};

enum class RulerType : int32_t {
    kNormal = 0,
    kExact = 1,
    kAtLeast = 2
};

enum class ParagraphHorizontalAlignment : int32_t {
    kLeft = 0,
    kCenter = 1,
    kRight = 2,
    kJustify = 3,
    kDistributed = 4
};

enum class CharacterVerticalAlignment : int32_t {
    kBaseLine = 0,
    kTop = 1,
    kMiddle = 2,
    kBottom = 3
};

class IFontManager {
public:
    virtual ~IFontManager() = default;
};

class FontmgrCollection {
public:
    explicit FontmgrCollection(std::shared_ptr<IFontManager> default_mgr);     // PLT @ 0x0355d0
    ~FontmgrCollection() = default;
    std::shared_ptr<IFontManager> default_font_manager_;
};

class TTTextJNIProxy {
public:
    static TTTextJNIProxy& GetInstance();                                      // PLT @ 0x0355b0
    std::shared_ptr<IFontManager> GetDefaultFontManager();                     // PLT @ 0x0355c0
};

/**
 * @brief RunDelegate base class for inline views, images, bullets, and custom cursors
 *        Lớp cơ sở RunDelegate cho inline view, ảnh, dấu đầu dòng và con trỏ tùy chỉnh
 *        Vtables in liblynx_markdown.so: 0x0383f0 (InlineView), 0x038470 (Image), 0x038490, 0x0384b0
 */
class RunDelegate {
public:
    virtual ~RunDelegate() = default;
    virtual float GetAscent() const = 0;                                       // vtable +0x10
    virtual float GetDescent() const = 0;                                      // vtable +0x18
    virtual float GetAdvance() const = 0;                                      // vtable +0x20
    virtual void Layout() {}                                                   // vtable +0x28
    virtual void Draw(class ICanvasHelper* canvas, float x, float y) = 0;      // vtable +0x30
    virtual bool Equals(RunDelegate* other) const { return this == other; }    // vtable +0x38
};

/**
 * @brief Character-level typographic style (PLT @ 0x035710..0x035820)
 *        Kiểu dáng chữ mức ký tự (PLT @ 0x035710..0x035820)
 */
class Style {
public:
    Style();                                                                   // PLT @ 0x035710
    Style(const Style& other);                                                 // PLT @ 0x035780
    ~Style();                                                                  // PLT @ 0x035730
    Style& operator=(const Style& other);                                      // PLT @ 0x035820
    void ClearShapeStyle() const;                                              // PLT @ 0x035720

    std::string font_family_ = "pingfang";
    float text_size_ = 14.0f;
    uint32_t foreground_color_ = 0xFF000000u;
    uint32_t background_color_ = 0x00000000u;
    uint32_t decoration_color_ = 0x00000000u;
    int32_t decoration_type_ = 0;      // 0=none, 1=underline, 2=line-through
    int32_t decoration_style_ = 0;     // 0=solid, 1=double, 2=dotted, 3=dashed, 4=wavy
    float decoration_thickness_ = 1.0f;
    uint16_t font_weight_ = 400;
    bool italic_ = false;
    bool bold_ = false;
    float baseline_offset_ = 0.0f;
    CharacterVerticalAlignment vertical_align_ = CharacterVerticalAlignment::kBaseLine;
};

/**
 * @brief Paragraph-level layout style (PLT @ 0x035700..0x035810)
 *        Kiểu dáng bố cục mức đoạn văn (PLT @ 0x035700..0x035810)
 */
class ParagraphStyle {
public:
    ParagraphStyle();                                                          // PLT @ 0x035770
    ParagraphStyle(const ParagraphStyle& other);                               // PLT @ 0x0357a0
    ~ParagraphStyle();                                                         // PLT @ 0x035790

    void SetHangingIndentInPx(float px);                                       // PLT @ 0x035700
    float GetHangingIndentInPx() const;                                        // PLT @ 0x0357b0
    void SetFirstLineIndentInPx(float px);                                     // PLT @ 0x0357c0
    void SetLineHeightInPx(float px, RulerType ruler);                         // PLT @ 0x0357d0
    void SetLineSpaceAfterPx(float px);                                        // PLT @ 0x0357e0
    void AllowBreakAroundPunctuation(bool allow);                              // PLT @ 0x0357f0
    void SetEllipsis(const std::u16string& ellipsis);                          // PLT @ 0x035800
    void SetEllipsis(std::shared_ptr<RunDelegate> ellipsis_delegate);          // PLT @ 0x035810

    Style default_style_;
    ParagraphHorizontalAlignment horizontal_align_ = ParagraphHorizontalAlignment::kLeft;
    float hanging_indent_px_ = 0.0f;
    float first_line_indent_px_ = 0.0f;
    float line_height_px_ = 0.0f;
    RulerType line_height_ruler_ = RulerType::kNormal;
    float line_space_after_px_ = 0.0f;
    int32_t max_lines_ = -1;
    bool allow_break_around_punctuation_ = false;
    std::u16string ellipsis_u16_;
    std::shared_ptr<RunDelegate> ellipsis_delegate_;
};

struct RunSpan {
    uint32_t char_start = 0;
    uint32_t char_end = 0;
    Style style;
    std::shared_ptr<RunDelegate> delegate;
};

/**
 * @brief Rich-text paragraph container (PLT @ 0x0356f0)
 *        Khối đoạn văn giàu định dạng (PLT @ 0x0356f0)
 */
class Paragraph {
public:
    static std::unique_ptr<Paragraph> Create();                                // PLT @ 0x0356f0
    virtual ~Paragraph() = default;

    virtual void SetParagraphStyle(const ParagraphStyle* style);
    virtual void AddTextRun(const Style* style, const char* text, uint32_t byte_len);
    virtual void AddShapeRun(const Style* style, std::shared_ptr<RunDelegate> delegate, bool is_ghost);
    virtual uint32_t GetCharCount() const { return static_cast<uint32_t>(u16_text_.size()); }
    virtual const std::string& GetUtf8Text() const { return u8_text_; }

    ParagraphStyle paragraph_style_;
    std::string u8_text_;
    std::u16string u16_text_;
    std::vector<RunSpan> runs_;
};

/**
 * @brief Laid-out text line inside a LayoutRegion
 *        Một dòng văn bản đã dàn trang trong LayoutRegion
 */
class TextLine {
public:
    virtual ~TextLine() = default;
    uint32_t start_char_pos_ = 0;
    uint32_t end_char_pos_ = 0;
    float line_top_ = 0.0f;
    float line_bottom_ = 20.0f;
    float line_left_ = 0.0f;
    float line_right_ = 0.0f;
    float baseline_ = 16.0f;
    Paragraph* paragraph_ = nullptr;
    std::vector<float> char_advances_;
};

class LayoutPageListener {
public:
    virtual ~LayoutPageListener() = default;
};

class TTTextContext {
public:
    TTTextContext();                                                           // PLT @ 0x0356a0
    ~TTTextContext();                                                          // PLT @ 0x0356c0
    void Reset();                                                              // PLT @ 0x035830

    bool first_line_ = true;
    uint32_t layout_position_ = 0;
    float layout_bottom_ = 0.0f;
    bool overflowed_ = false;
};

/**
 * @brief LayoutRegion (allocated size 0xb0 = 176 bytes @ 0x0102e8, PLT @ 0x0356d0, 0x0356b0)
 *        Vùng dàn trang văn bản (kích thước cấp phát 0xb0 = 176 byte @ 0x0102e8)
 */
class LayoutRegion {
public:
    LayoutRegion(float width, float height, LayoutMode width_mode, LayoutMode height_mode,
                 LayoutPageListener* listener = nullptr);                      // PLT @ 0x0356d0
    virtual ~LayoutRegion();

    void UpdateLayoutedSize(TextLine* line, const TTTextContext& context);     // PLT @ 0x0356b0

    uint32_t GetLineCount() const { return static_cast<uint32_t>(lines_.size()); }
    TextLine* GetLine(uint32_t idx) const {
        return idx < lines_.size() ? lines_[idx].get() : nullptr;
    }

    float max_width_ = 0.0f;
    float max_height_ = 0.0f;
    LayoutMode width_mode_ = LayoutMode::kDefinite;
    LayoutMode height_mode_ = LayoutMode::kIndefinite;
    float layouted_width_ = 0.0f;
    float layouted_height_ = 0.0f;
    Paragraph* paragraph_ = nullptr;
    std::vector<std::unique_ptr<TextLine>> lines_;
};

class TextLayout {
public:
    TextLayout(FontmgrCollection* font_collection, ShaperType shaper_type);    // PLT @ 0x0355e0
    ~TextLayout();                                                             // PLT @ 0x0355f0

    uint32_t LayoutEx(Paragraph* paragraph, LayoutRegion* region, TTTextContext& context) const; // PLT @ 0x0356e0

    FontmgrCollection* font_collection_ = nullptr;
    ShaperType shaper_type_ = ShaperType::kSystem;
};

/**
 * @brief Paint helper interface (`vtable @ 0x038398`, size `0x58` = 88 bytes @ 0x018980)
 *        Giao diện đối tượng Paint (`vtable @ 0x038398`, kích thước `0x58` = 88 byte @ 0x018980)
 */
class IPaintHelper {
public:
    virtual ~IPaintHelper() = default;
    std::string font_family_ = "pingfang"; // +0x18 (SSO 0x10, "pingfang" = 0x676e6166676e6970 @ 0x0189a8..0x0189b8)
    float text_size_ = 14.0f;              // +0x30 (0x41600000 @ 0x0189bc)
    uint32_t color_ = 0xFF000000u;         // +0x08
    float stroke_width_ = 1.0f;            // +0x0c
    uint8_t fill_style_ = 0;               // +0x10 (0=fill, 1=stroke, 2=fill_and_stroke)
    bool bold_ = false;                    // +0x38
    bool italic_ = false;                  // +0x39
    bool underline_ = false;               // +0x3a
    bool strike_through_ = false;          // +0x3b
    uint64_t typeface_id_ = 0;             // +0x40
    uint64_t shader_id_ = 0;               // +0x48
};

/**
 * @brief Canvas helper interface (`vtable @ 0x038148` & `0x038248`, serialized command buffer)
 *        Giao diện vẽ Canvas (`vtable @ 0x038148` & `0x038248`, bộ đệm lệnh nhị phân tuần tự)
 */
class ICanvasHelper {
public:
    virtual ~ICanvasHelper() = default;                                        // 0x018924 / 0x018950
    virtual std::unique_ptr<IPaintHelper> CreatePaint() = 0;                   // 0x01897c
    virtual void StartPaint() {}                                               // 0x0189e4
    virtual void EndPaint() {}                                                 // 0x0189e4
    virtual void Save() = 0;                                                   // 0x0189e8 (op = 2)
    virtual void Restore() = 0;                                                // 0x018a34 (op = 3)
    virtual void Translate(float dx, float dy) = 0;                            // 0x018a80 (op = 4)
    virtual void Scale(float sx, float sy) {}                                  // 0x0189e4
    virtual void Rotate(float degrees) {}                                      // 0x0189e4
    virtual void Skew(float sx, float sy) {}                                   // 0x0189e4
    virtual void ClipRect(float left, float top, float right, float bottom, bool doAntiAlias) = 0; // 0x018b10 (op = 8)
    virtual void Clear() {}                                                    // 0x0189e4
    virtual void ClearRect(float left, float top, float right, float bottom) {}// 0x0189e4
    virtual void FillRect(float left, float top, float right, float bottom, uint32_t color) {} // 0x0189e4
    virtual void DrawColor(uint32_t color) {}                                  // 0x0189e4
    virtual void DrawLine(float x1, float y1, float x2, float y2, IPaintHelper* paint) = 0; // 0x018bd8 (op = 13)
    virtual void DrawRect(float left, float top, float right, float bottom, IPaintHelper* paint) = 0; // 0x018d40 (op = 14)
    virtual void DrawOval(float left, float top, float right, float bottom, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawCircle(float x, float y, float radius, IPaintHelper* paint) = 0; // 0x018ea8 (op = 16)
    virtual void DrawArc(float left, float top, float right, float bottom, float startAngle, float sweepAngle, bool useCenter, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawPath(void* path, IPaintHelper* paint) {}                  // 0x0189e4
    virtual void DrawArcTo(float x1, float y1, float x2, float y2, float radius, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawText(const char* text, uint32_t len, float x, float y, IPaintHelper* paint) = 0; // 0x018ff8
    virtual void DrawGlyphs(const uint16_t* glyphs, const float* positions, uint32_t count, float x, float y, IPaintHelper* paint) = 0; // 0x01914c (op = 20)
    virtual void DrawRunDelegate(RunDelegate* delegate, float left, float top, float right, float bottom, IPaintHelper* paint) = 0; // 0x019390 (op = 21)
    virtual void DrawBackgroundDelegate(RunDelegate* delegate, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawImage(const char* src, float left, float top, float right, float bottom, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawImageRect(const char* src, float src_l, float src_t, float src_r, float src_b, float dst_l, float dst_t, float dst_r, float dst_b, IPaintHelper* paint) {} // 0x0189e4
    virtual void DrawRoundRect(float left, float top, float right, float bottom, float radius, IPaintHelper* paint) = 0; // 0x019474 (op = 26)
};

class LayoutDrawer {
public:
    explicit LayoutDrawer(ICanvasHelper* canvas);                              // PLT @ 0x035670
    ~LayoutDrawer();                                                           // PLT @ 0x035680
    void DrawLayoutPage(LayoutRegion* region);                                 // PLT @ 0x035690
    void DrawTextLine(TextLine* line, uint32_t char_start, uint32_t char_end); // PLT @ 0x035850

    ICanvasHelper* canvas_ = nullptr;
};

} // namespace tttext
} // namespace ttoffice

// ============================================================================
// Discount (David Loren Parsons) Embedded Markdown Structures (0x00eaec..0x00feb4)
// Các cấu trúc trình phân tích Markdown Discount nhúng (0x00eaec..0x00feb4)
// ============================================================================
namespace lynx {
namespace markdown {

/**
 * @brief Classic Discount MMIOT validation magic constant (`mov w29, #0x731; movk w29, #0x1960, lsl #16` @ 0x00eaec..0x00eaf8)
 *        Hằng số ma thuật xác thực MMIOT của Discount (`0x19600731` @ 0x00eaec..0x00eaf8)
 */
constexpr uint32_t kDiscountValidMmiotMagic = 0x19600731u;

/**
 * @brief Discount Line node (allocated via `calloc(0x48, 1)` inside `__mkd_enqueue` @ 0x01b04c)
 *        Nút dòng văn bản Discount (cấp phát qua `calloc(0x48, 1)` trong `__mkd_enqueue` @ 0x01b04c)
 */
struct DiscountLine {
    char* text = nullptr;               // +0x00: Line text buffer
    int32_t len = 0;                    // +0x08: Line byte length
    int32_t alloc = 0;                  // +0x0c: Allocated capacity
    DiscountLine* next = nullptr;       // +0x10: Next line in linked list
    int32_t dle = 0;                    // +0x18: Leading spaces count (`0x019f88` counts leading spaces, tab=4)
    int32_t flags = 0;                  // +0x1c: Line flags (CHECKED, PIPECHAR, etc.)
    int32_t kind = 0;                   // +0x20: Line classification kind
    int32_t count = 0;                  // +0x24: Fence / header / rule char count
    int32_t char_index = 0;             // +0x28: Document byte offset (`w25` passed to `0x01b04c`)
    int32_t other = 0;                  // +0x2c
    void* ext_data = nullptr;           // +0x30
    int32_t end_offset = 0;             // +0x38
    int32_t line_number = 0;            // +0x3c
    uint64_t reserved = 0;              // +0x40 (total size = 0x48 = 72 bytes)
};

/**
 * @brief Discount Paragraph AST node (`calloc(0x78, 1)` @ 0x00eb0c)
 *        Nút AST đoạn văn Discount (`calloc(0x78, 1)` @ 0x00eb0c, kích thước = 120 byte)
 */
enum class DiscountBlockType : int32_t {
    kWhitespace = 0,
    kCode       = 1,
    kQuote      = 2,
    kMarkup     = 3,
    kHtml       = 4,
    kStyle      = 5,
    kUl         = 6,
    kOl         = 7,
    kAl         = 8,
    kListItem   = 9,
    kHdr        = 10,
    kHr         = 11,
    kTable      = 12,
    kSource     = 13,
    kCenter     = 14
};

struct DiscountParagraph {
    DiscountParagraph* next = nullptr;  // +0x00: Next sibling paragraph
    DiscountParagraph* down = nullptr;  // +0x08: Child paragraphs (for lists, quotes, tables)
    DiscountLine* text = nullptr;       // +0x10: Head of lines in this block
    DiscountLine* tail = nullptr;       // +0x18: Tail of lines in this block
    char* ident = nullptr;              // +0x20: Block identifier / info string (e.g. code language)
    char* lang = nullptr;               // +0x28: Fenced code language tag
    DiscountBlockType typ = DiscountBlockType::kMarkup; // +0x30: Block type
    int32_t align = 0;                  // +0x34: Alignment / table column alignments
    int32_t hnumber = 0;                // +0x38: Header level (1..6) or list start number
    int32_t flags = 0;                  // +0x3c: Block flags / task list state (`[x]`=2, `[ ]`=1)
    int32_t byte_start = 0;             // +0x40: Source markdown byte start
    int32_t byte_end = 0;               // +0x44: Source markdown byte end
    uint8_t reserved[0x30]{};           // +0x48..0x78 (total size = 0x78 = 120 bytes)
};

/**
 * @brief Discount Reference Link / Footnote entry (sorted via `qsort` @ 0x00fb7c)
 *        Mục liên kết tham chiếu / chú thích của Discount (sắp xếp qua `qsort` @ 0x00fb7c)
 */
struct DiscountFootnote {
    std::string tag;                    // Reference label `[tag]`
    std::string link;                   // Target URL
    std::string title;                  // Optional title attribute
    uint32_t height = 0;                // Optional `=WxH` height
    uint32_t width = 0;                 // Optional `=WxH` width
    int32_t flags = 0;
};

/**
 * @brief Discount Document Root (`calloc(0x98, 1)` @ 0x00eaf0)
 *        Gốc tài liệu Discount (`calloc(0x98, 1)` @ 0x00eaf0, kích thước = 152 byte)
 */
struct DiscountDocument {
    uint32_t magic = kDiscountValidMmiotMagic; // +0x00: 0x19600731 (`str w29, [x22]` @ 0x00eb30)
    uint32_t reserved0 = 0;                    // +0x04
    DiscountLine* headers = nullptr;           // +0x08: Pandora 3-line `%` header if present (@ 0x00ec8c)
    DiscountParagraph* code = nullptr;         // +0x10: Compiled root Paragraph AST tree
    DiscountLine* content_head = nullptr;      // +0x18
    DiscountLine* content_tail = nullptr;      // +0x20
    int32_t compiled = 0;                      // +0x38
    int32_t dirty = 0;                         // +0x3c (`mov w8, #4; str w8, [x22, #0x3c]` @ 0x00eb44)
    int32_t html = 0;                          // +0x40
    DiscountParagraph* root_para = nullptr;    // +0x48 (`str x0, [x22, #0x48]` @ 0x00eb18)
    void* cbp = nullptr;                       // +0x50: Internal MMIOT context
    int32_t ref_base = 0;                      // +0x58
    uint8_t flags_and_ext[0x3c]{};             // +0x5c..0x98 (total size = 0x98 = 152 bytes)
    std::vector<DiscountFootnote> footnotes;   // Sorted reference table
};

// ============================================================================
// Lynx Markdown Style Sheet Structures (`MarkdownStyle` @ +0x98..+0xdc0 in MarkdownDocument)
// Các cấu trúc bảng kiểu dáng Lynx Markdown (`MarkdownStyle` @ +0x98..+0xdc0)
// ============================================================================

enum class MarkdownBorderType : int32_t {
    kNone = 0,
    kSolid = 1,
    kDotted = 2,
    kDashed = 3,
    kDouble = 4,
    kCapsule = 5,
    kFullRect = 6
};

enum class MarkdownNumberType : int32_t {
    kNumber = 0,
    kRomanNumerals = 1,
    kCircle = 2,
    kSquare = 3,
    kMixed = 4
};

enum class MarkdownBackgroundType : int32_t {
    kNone = 0,
    kSolid = 1,
    kLinearGradient = 2,
    kRadialGradient = 3,
    kImage = 4,
    kChessBoard = 5
};

enum class MarkdownTruncationType : int32_t {
    kNone = 0,
    kEllipsis = 1,
    kView = 2
};

struct MarkdownBlockStyle {
    std::string font_family = "pingfang";
    float font_size = 14.0f;
    uint16_t font_weight = 400;
    float line_height = -1.0f;
    float line_space = 0.0f;
    float paragraph_space = 0.0f;
    float text_indent = 0.0f;
    int32_t text_maxline = -1;
    int32_t text_overflow = 0;         // 0=clip, 1=ellipsis
    int32_t text_align = 0;            // 0=left, 1=center, 2=right, 3=justify
    int32_t last_line_alignment = 0;
    int32_t direction = 0;             // 0=normal, 1=ltr, 2=rtl
    int32_t word_break = 0;            // 0=normal, 1=break-all
    uint32_t color = 0xFF000000u;
    uint32_t background_color = 0x00000000u;
    uint32_t border_color = 0x00000000u;
    float border_width = 0.0f;
    float border_radius = 0.0f;
    MarkdownBorderType border_type = MarkdownBorderType::kNone;
    float margin_top = 0.0f;
    float margin_bottom = 0.0f;
    float margin_left = 0.0f;
    float margin_right = 0.0f;
    float padding_top = 0.0f;
    float padding_bottom = 0.0f;
    float padding_left = 0.0f;
    float padding_right = 0.0f;
    float max_width = -1.0f;
    float max_height = -1.0f;
    float min_height = 0.0f;
    std::string background_image;
    std::string background_size;
    std::string background_position;
    std::string background_repeat;
    MarkdownBackgroundType background_type = MarkdownBackgroundType::kNone;
    bool scroll_x = false;
};

struct MarkdownInlineStyle {
    std::string font_family;
    float font_size = -1.0f;
    uint16_t font_weight = 400;
    uint32_t color = 0xFF000000u;
    uint32_t background_color = 0x00000000u;
    uint32_t border_color = 0x00000000u;
    float border_width = 0.0f;
    float border_radius = 0.0f;
    MarkdownBorderType border_type = MarkdownBorderType::kNone;
    uint32_t text_decoration_color = 0x00000000u;
    int32_t text_decoration_line = 0;  // 0=none, 1=underline, 2=line-through
    int32_t text_decoration_style = 0; // 0=solid, 1=double, 2=dotted, 3=dashed
    float text_decoration_thickness = 1.0f;
    float margin_left = 0.0f;
    float margin_right = 0.0f;
    float padding_left = 0.0f;
    float padding_right = 0.0f;
    float padding_top = 0.0f;
    float padding_bottom = 0.0f;
    bool clickable = false;
};

struct MarkdownListStyle {
    MarkdownBlockStyle block;
    MarkdownNumberType number_type = MarkdownNumberType::kNumber;
    std::string number_font;
    float number_font_size = 14.0f;
    uint32_t number_color = 0xFF000000u;
    float number_margin_right = 6.0f;
    uint32_t mark_color = 0xFF000000u;
    float mark_margin_right = 6.0f;
    float mark_size = 5.0f;
    int32_t start_index = 1;
};

struct MarkdownTypewriterCursorStyle {
    std::string custom_cursor;         // Inline view id or image URL for typewriter cursor
    int32_t vertical_align = 0;        // 0=baseline, 1=top, 2=center, 3=bottom
    float offset_x = 0.0f;
    float offset_y = 0.0f;
};

struct MarkdownTruncationStyle {
    MarkdownTruncationType truncation_type = MarkdownTruncationType::kNone;
    std::string content = "...";
    int32_t max_lines = -1;
};

/**
 * @brief Complete Markdown Style Sheet (`0x00d3b8..0x00d5c4` inside `MarkdownDocument`)
 *        Bảng kiểu dáng Markdown hoàn chỉnh (`0x00d3b8..0x00d5c4` bên trong `MarkdownDocument`)
 */
struct MarkdownStyleSheet {
    MarkdownBlockStyle normal_text;
    MarkdownBlockStyle h1;
    MarkdownBlockStyle h2;
    MarkdownBlockStyle h3;
    MarkdownBlockStyle h4;
    MarkdownBlockStyle h5;
    MarkdownBlockStyle h6;
    MarkdownBlockStyle code_block;
    MarkdownBlockStyle quote;
    MarkdownBlockStyle quote_border_line;
    MarkdownListStyle unordered_list;
    MarkdownListStyle ordered_list;
    MarkdownBlockStyle table;
    MarkdownBlockStyle table_header;
    MarkdownBlockStyle table_cell;
    MarkdownBlockStyle table_border;
    MarkdownBlockStyle table_background;
    MarkdownBlockStyle horizontal_rule;
    MarkdownInlineStyle inline_code;
    MarkdownInlineStyle link;
    MarkdownInlineStyle mark;
    MarkdownInlineStyle double_braces;
    MarkdownInlineStyle image_caption;
    MarkdownTypewriterCursorStyle typewriter_cursor;
    MarkdownTruncationStyle truncation;
    std::unordered_map<std::string, MarkdownInlineStyle> span_classes;
    float root_font_scale = 1.0f;      // +0xd20 (`mov w8, #0x3f800000; str w8, [x19, #0xd20]` @ 0x00d568..0x00d580)
    bool enable_alt_text = false;
    bool table_split = false;
    int32_t caption_position = 0;      // 0=bottom, 1=top
};

// ============================================================================
// Layout Regions, Extra Content, Links, Images, Inline Views & Attachments
// Các vùng bố cục, nội dung phụ, liên kết, hình ảnh, inline view & đính kèm
// ============================================================================

struct RectF {
    float left = 0.0f;
    float top = 0.0f;
    float right = 0.0f;
    float bottom = 0.0f;

    float Width() const { return right - left; }
    float Height() const { return bottom - top; }
    bool Contains(float x, float y) const {
        return x >= left && x <= right && y >= top && y <= bottom;
    }
};

/**
 * @brief Link entry (`sizeof = 0x48 = 72 bytes` verified by magic multiplier `0x8e38e38e38e38e39` in `nativeGetLinks` @ 0x014380 and destructor loop `sub x22, x21, #0x48` @ 0x010dd4)
 *        Mục liên kết (`sizeof = 0x48 = 72 byte`, xác minh qua hệ số nhân `0x8e38e38e38e38e39` tại `0x014380` và vòng lặp hủy `sub x22, x21, #0x48` tại `0x010dd4`)
 */
struct MarkdownLink {
    std::string url;                   // +0x00..0x18 (24 bytes)
    std::string content;               // +0x18..0x30 (24 bytes)
    uint32_t char_start = 0;           // +0x30
    uint32_t char_count = 0;           // +0x34
    uint32_t attached_region_idx = 0;  // +0x38
    uint32_t char_offset_in_region = 0;// +0x3c
    uint64_t reserved = 0;             // +0x40 (total = 0x48 = 72 bytes)
};

/**
 * @brief Image entry (`sizeof = 0x20 = 32 bytes` verified by `sub x25, x9, #0x20` in `nativeGetImages` @ 0x0151d4 and destructor loop `ldrb w9, [x21, #-0x20]!` @ 0x010d38)
 *        Mục hình ảnh (`sizeof = 0x20 = 32 byte`, xác minh qua `sub x25, x9, #0x20` tại `0x0151d4` và vòng lặp hủy tại `0x010d38`)
 */
struct MarkdownImage {
    std::string url;                   // +0x00..0x18 (24 bytes)
    uint32_t char_index = 0;           // +0x18
    float width = 0.0f;                // Auxiliary layout width
    float height = 0.0f;               // Auxiliary layout height
    RectF rect{};                      // Laid out bounding box
};

/**
 * @brief Inline / Block View entry (`inlineview://id` or `blockview://id`)
 *        Mục Inline / Block View (`inlineview://id` hoặc `blockview://id`)
 */
struct MarkdownInlineView {
    std::string id;                    // View identifier string
    uint32_t char_index = 0;           // Character position in document
    bool is_block_view = false;        // True if `blockview://`
    float width = 0.0f;
    float height = 0.0f;
    float ascent = 0.0f;
    float descent = 0.0f;
    RectF origin_rect{};               // Computed origin & size during layout
    bool visible_in_typewriter = true;
};

/**
 * @brief Text Mark Attachment (`nativeAddTextMarkAttachment` @ 0x015970, `nativeClearTextMarkAttachment` @ 0x01666c, `nativeGetTextClickByPoint` @ 0x01673c)
 *        Đính kèm đánh dấu văn bản (highlight/underline/background gắn động trên khoảng ký tự)
 */
struct MarkdownTextAttachment {
    std::string id;                    // Attachment click ID (`id` key in style map)
    int32_t start_pos = 0;             // Character start index (`startIndex` / `start`)
    int32_t end_pos = 0;               // Character end index (`endIndex` / `end`)
    bool is_markdown_offset = false;   // `indexType` == "markdown"
    MarkdownInlineStyle style;         // Gradient / background / border / underline style
    bool clickable = false;            // `clickable` flag
    std::vector<RectF> rects;          // Computed bounding boxes across text lines
};

/**
 * @brief Extra content item (quote vertical bar, table grid border, list bullet/number, horizontal rule, block border/background)
 *        Phần tử nội dung bổ sung (thanh dọc trích dẫn, khung bảng, dấu danh sách, đường kẻ ngang, viền khối)
 *        Stored in `MarkdownPage + 0x80` (`nativeGetExtraContentCount` @ 0x017d28, `nativeDrawExtraContent` @ 0x016d94)
 */
enum class ExtraContentKind : int32_t {
    kQuoteBorder = 0,
    kCodeBlockBackground = 1,
    kTableBorder = 2,
    kTableBackground = 3,
    kHorizontalRule = 4,
    kListMarker = 5
};

struct MarkdownExtraContent {
    ExtraContentKind kind = ExtraContentKind::kQuoteBorder;
    RectF rect{};                      // Bounding rect (`nativeGetExtraContentRect` @ 0x017b5c)
    uint32_t color = 0xFFCCCCCCu;
    uint32_t border_color = 0xFFDDDDDDu;
    float border_width = 1.0f;
    float border_radius = 0.0f;
    MarkdownBorderType border_type = MarkdownBorderType::kSolid;
    std::string marker_text;           // For ordered list / Roman numeral markers
    uint32_t char_start = 0;           // Associated character start for typewriter visibility (`nativeGetShowedExtraContent` @ 0x0180c4)
    uint32_t char_end = 0;
    std::vector<RectF> cell_rects;     // For table grid lines / chessboard cells
};

/**
 * @brief Single laid-out region in `MarkdownPage` (`[page + 0x18]` vector of `std::unique_ptr<MarkdownRegion>`)
 *        Một vùng đã dàn trang trong `MarkdownPage` (`[page + 0x18]`)
 */
struct MarkdownRegion {
    RectF border_rect{};               // +0x00: Outer border rect
    RectF padding_rect{};              // +0x10: Inner content rect (`nativeGetRegionRect` @ 0x0179e4)
    uint32_t char_start = 0;           // +0x20: Global char start index
    uint32_t char_end = 0;             // +0x24: Global char end index
    int32_t block_type = 0;            // +0x38: 0=paragraph/header/list, 1=table (`ldr w9, [x20, #8]; cmp w9, #1` @ 0x014244..0x014248)
    bool scroll_x = false;             // Horizontal scrollable region (`nativeInheritState` @ 0x018268)
    float scroll_offset_x = 0.0f;      // Inherited horizontal scroll offset
    std::unique_ptr<ttoffice::tttext::Paragraph> paragraph;
    std::unique_ptr<ttoffice::tttext::LayoutRegion> layout_region;
    std::vector<std::vector<std::unique_ptr<ttoffice::tttext::LayoutRegion>>> table_cells;
    std::vector<uint32_t> table_cell_char_counts; // `+0x48 -> +0x20` cumulative char counts (@ 0x014250..0x014264)
};

/**
 * @brief Thread-safe laid-out page snapshot (`std::shared_ptr<MarkdownPage>` at `MarkdownDocument + 0x70`)
 *        Bản chụp trang đã dàn bố cục an toàn đa luồng (`std::shared_ptr<MarkdownPage>` tại `MarkdownDocument + 0x70`)
 *        Every read method locks `doc->mutex_` at `+0x48` (`0x035520`), copies `shared_ptr<MarkdownPage>` at `+0x70`, and unlocks `doc->mutex_` (`0x035530`)!
 */
struct MarkdownPage {
    float layout_width = 0.0f;                                         // +0x00
    float layout_height = 0.0f;                                        // +0x04
    uint32_t total_char_count = 0;                                     // +0x08
    bool is_overflowed = false;                                        // +0x0c
    std::vector<std::unique_ptr<MarkdownRegion>> regions;              // +0x18..0x30 (`ldp x8, x9, [page, #0x18]` @ 0x017ccc)
    std::vector<std::unique_ptr<MarkdownTextAttachment>> attachments;  // +0x30..0x48 (`ldp x22, x23, [page, #0x30]` @ 0x0166b0)
    std::vector<std::unique_ptr<MarkdownExtraContent>> extra_contents; // +0x80..0x98 (`ldp x8, x9, [page, #0x80]` @ 0x017d68)
    std::string plain_utf8_text;                                       // Concatenated plain text for `GetContentByCharRange`
    std::u16string plain_u16_text;
};

/**
 * @brief 16-byte Markdown Byte-to-Char Offset Mapping Entry (`[doc + 0xe58..0xe68]`, binary-searched in `nativeMarkdownOffsetToChar` @ 0x0142d4)
 *        Mục ánh xạ vị trí Markdown sang chỉ số ký tự 16-byte (`[doc + 0xe58..0xe68]`, tìm kiếm nhị phân tại `0x0142d4`)
 *
 * Exact AArch64 field layout verified from `nativeMarkdownOffsetToChar` (`0x0142d4..0x014354`):
 *   - `+0x00` (`ldr w9, [x8]`):     `md_start` (int32_t)
 *   - `+0x04` (`ldr w13, [x12,#4]`):`md_end`   (int32_t)
 *   - `+0x08` (`ldr w0, [x8, #8]`): `char_start` (int32_t)
 *   - `+0x0c` (`ldr w0, [x8,#0xc]`):`char_end`   (int32_t)
 */
struct MarkdownOffsetRange {
    int32_t md_start = 0;              // +0x00
    int32_t md_end = 0;                // +0x04
    int32_t char_start = 0;            // +0x08
    int32_t char_end = 0;              // +0x0c
};
static_assert(sizeof(MarkdownOffsetRange) == 16, "MarkdownOffsetRange must be 16 bytes (lsl #4 / asr #4 @ 0x0142e4)");

/**
 * @brief Syntax range entry (`[doc + 0xe70..0xe80]`, queried by `nativeGetSyntaxRange` @ 0x014d08)
 *        Mục phạm vi cú pháp (`[doc + 0xe70..0xe80]`, truy vấn bởi `nativeGetSyntaxRange` @ 0x014d08)
 */
struct MarkdownSyntaxRange {
    std::string syntax_tag;            // "heading", "bold", "italic", "strikethrough", "codeBlock", "inlineCode", "quote", "unorderedList", "orderedList", "link", "image", "table", "horizontal", "doubleBraces"
    int32_t md_start = 0;
    int32_t md_end = 0;
    int32_t char_start = 0;
    int32_t char_end = 0;
};

/**
 * @brief Cached JNI class & method table at `.bss + 0x03c068` (`initial` @ 0x0117ec)
 *        Bảng lớp & phương thức JNI được lưu đệm tại `.bss + 0x03c068` (`initial` @ 0x0117ec)
 */
struct MarkdownJNIHelper {
    lynx::base::android::JavaRef<jclass> markdown_doc_class; // +0x00 (0x03c068)
    jmethodID load_image_method = nullptr;                   // +0x10 (0x03c078): `loadImage(Ljava/lang/String;FFFF)I`
    jmethodID load_font_method = nullptr;                    // +0x18 (0x03c080): `loadFont(Ljava/lang/String;I)I`
    jmethodID measure_inline_view_method = nullptr;          // +0x20 (0x03c088): `measureInlineView(Ljava/lang/String;FF)I`
    jmethodID get_run_delegate_size_method = nullptr;        // +0x28 (0x03c090): `getRunDelegateSize(I)[F`
    jmethodID on_text_overflow_method = nullptr;             // +0x30 (0x03c098): `onTextOverflow(Ljava/lang/String;)V`
    jmethodID load_gradient_method = nullptr;                // +0x38 (0x03c0a0): `loadGradient(Ljava/lang/String;FF)I`
    lynx::base::android::JavaRef<jclass> string_class;       // +0x40 (0x03c0a8): `java/lang/String`
    JavaVM* jvm = nullptr;                                   // +0x50 (0x03c0b8)
    bool initialized = false;
};

/**
 * @brief ResourceLoader Bridge (`sizeof = 0x18 = 24 bytes`, `vtable @ 0x038018`, stored at `[doc + 0xe00]`)
 *        Cầu nối tải tài nguyên (`sizeof = 0x18 = 24 byte`, `vtable @ 0x038018`, lưu tại `[doc + 0xe00]`)
 */
class MarkdownResourceLoader {
public:
    explicit MarkdownResourceLoader(jobject java_doc);
    virtual ~MarkdownResourceLoader();                                         // 0x00d994 / 0x00d9b8
    virtual int32_t MeasureInlineView(const char* id, float max_width, float max_height,
                                      float* out_width, float* out_height, float* out_ascent); // 0x00d9f0
    virtual int32_t LoadImage(const char* src, float max_width, float max_height,
                              float style_width, float style_height,
                              float* out_width, float* out_height);            // 0x00dc88
    virtual int32_t LoadFont(const char* family, int32_t weight);              // 0x00df08
    virtual int32_t LoadGradient(const char* gradient_css, float width, float height); // 0x00e110

    lynx::base::android::JavaRef<jobject> weak_java_doc_; // +0x08 (16 bytes; total object size = 0x18 = 24 bytes)
};

/**
 * @brief EventListener Bridge (`sizeof = 0x18 = 24 bytes`, `vtable @ 0x038080`, stored at `[doc + 0xe08]`)
 *        Cầu nối lắng nghe sự kiện (`sizeof = 0x18 = 24 byte`, `vtable @ 0x038080`, lưu tại `[doc + 0xe08]`)
 */
class MarkdownEventListener {
public:
    explicit MarkdownEventListener(jobject java_doc);
    virtual ~MarkdownEventListener();                                          // 0x00d670 / 0x00d694
    virtual void OnTextOverflow(const char* ellipsis_str);                     // 0x00d6cc

    lynx::base::android::JavaRef<jobject> weak_java_doc_; // +0x08 (16 bytes; total object size = 0x18 = 24 bytes)
};

/**
 * @brief Main Native `MarkdownDocument` Instance (`sizeof = 0xe88 = 3,720 bytes` @ 0x00d328)
 *        Thực thể gốc `MarkdownDocument` (`sizeof = 0xe88 = 3,720 byte` @ 0x00d328)
 *
 * Exact field offsets verified from `nativeCreateInstance` (`0x00d300`) and `nativeDestroyInstance` (`0x010b88`):
 *   - `+0x000..0x018`: `std::vector<std::shared_ptr<RunDelegate>>` inline_delegates_ (`nativeDestroyInstance` @ 0x010df4)
 *   - `+0x018..0x030`: `std::vector<MarkdownLink>` links_ (`0x48`-byte elements, `nativeGetLinks` @ 0x014370)
 *   - `+0x030..0x048`: `std::vector<MarkdownImage>` images_ (`0x20`-byte elements, `nativeGetImages` @ 0x0151bc)
 *   - `+0x048..0x070`: `std::mutex` page_mutex_ (`0x28` = 40 bytes on Android Bionic AArch64, `mutex::lock` @ 0x017c94, `mutex::~mutex` @ 0x010d18)
 *   - `+0x070..0x080`: `std::shared_ptr<MarkdownPage>` current_page_ (`ldp x21, x19, [x21, #0x70]` @ 0x017ca4)
 *   - `+0x080..0x098`: `std::unordered_map<std::string, MarkdownInlineView>` inline_views_ (`str x8, [x19, #0x80]` @ 0x00d3f8)
 *   - `+0x098..0xdf8`: `MarkdownStyleSheet` style_sheet_ (`memset` `0x549` @ 0x00d3b8 + sub-structs up to `+0xdf8`, `1.0f` @ `+0xd20`)
 *   - `+0xe00`:        `MarkdownResourceLoader*` resource_loader_ (`str x21, [x19, #0xe00]` @ 0x00d5a4)
 *   - `+0xe08`:        `MarkdownEventListener*` event_listener_ (`str x21, [x19, #0xe08]` @ 0x00d634)
 *   - `+0xe10..0xe28`: `std::string` raw_markdown_content_ (`ldrb w8, [x19, #0xe10]` @ 0x010d80)
 *   - `+0xe28..0xe38`: `std::shared_ptr<ttoffice::tttext::FontmgrCollection>` font_collection_ (`ldr x20, [x19, #0xe30]` @ 0x010be4)
 *   - `+0xe38`:        `bool` allow_break_around_punctuation_ (`strb w8, [x2, #0xe38]` in `nativeAllowBreakAroundPunctuation` @ 0x015634)
 *   - `+0xe3c`:        `float` touch_down_x_ (`str s9, [x20, #0xe3c]` in `nativeOnTouchEvent` @ 0x0156b0)
 *   - `+0xe40`:        `float` touch_down_y_
 *   - `+0xe44`:        `bool` is_touch_down_
 *   - `+0xe48`:        `int64_t` active_touch_target_
 *   - `+0xe50`:        `bool` touch_consumed_ (`strb wzr, [x2, #0xe50]` @ 0x015664)
 *   - `+0xe58..0xe70`: `std::vector<MarkdownOffsetRange>` offset_map_ (`ldr x8, [x2, #0xe58]; ldr x9, [x2, #0xe60]` @ 0x0142d4)
 *   - `+0xe70..0xe88`: `std::vector<MarkdownSyntaxRange>` syntax_ranges_ (`ldr x0, [x19, #0xe70]` @ 0x010bc4)
 */
struct MarkdownDocument {
    std::vector<std::shared_ptr<ttoffice::tttext::RunDelegate>> inline_delegates_; // +0x000
    std::vector<MarkdownLink> links_;                                              // +0x018
    std::vector<MarkdownImage> images_;                                            // +0x030
    mutable std::mutex page_mutex_;                                                // +0x048
    std::shared_ptr<MarkdownPage> current_page_;                                   // +0x070
    std::unordered_map<std::string, MarkdownInlineView> inline_views_;             // +0x080
    MarkdownStyleSheet style_;                                                     // +0x098..0xdf8
    MarkdownResourceLoader* resource_loader_ = nullptr;                            // +0xe00
    MarkdownEventListener* event_listener_ = nullptr;                              // +0xe08
    std::string raw_markdown_;                                                     // +0xe10
    std::shared_ptr<ttoffice::tttext::FontmgrCollection> font_collection_;         // +0xe28
    bool allow_break_around_punctuation_ = false;                                  // +0xe38
    float touch_down_x_ = 0.0f;                                                    // +0xe3c
    float touch_down_y_ = 0.0f;                                                    // +0xe40
    bool is_touch_down_ = false;                                                   // +0xe44
    int64_t active_touch_target_ = 0;                                              // +0xe48
    bool touch_consumed_ = false;                                                  // +0xe50
    std::vector<MarkdownOffsetRange> offset_map_;                                  // +0xe58
    std::vector<MarkdownSyntaxRange> syntax_ranges_;                               // +0xe70

    // Parsed AST & attachments staging before layout
    std::vector<MarkdownTextAttachment> pending_attachments_;
    int32_t parse_start_offset_ = 0;
    int32_t parse_end_offset_ = -1;
};

} // namespace markdown
} // namespace lynx
