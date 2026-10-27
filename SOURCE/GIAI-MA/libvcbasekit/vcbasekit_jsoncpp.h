// ============================================================================
// File: vcbasekit_jsoncpp.h
// Target: libvcbasekit.so (231,568 bytes)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
//
// Description (EN):
// Clean-room C++17 declarations for the embedded JsonCpp subsystem in
// libvcbasekit.so (.text 0x00fb20..0x021720, .rodata 0x02b530..0x02bf3f,
// .data.rel.ro 0x03a3d8..0x03a48f), including Json::Value, Json::CZString,
// Json::ValueIteratorBase / ValueConstIterator / ValueIterator, Json::Reader,
// Json::Writer / FastWriter / StyledWriter, and Json::Path / PathArgument.
//
// Mô tả (VI):
// Khai báo C++17 tái tạo sạch cho phân hệ JsonCpp nhúng trong libvcbasekit.so
// (.text 0x00fb20..0x021720, .rodata 0x02b530..0x02bf3f, .data.rel.ro
// 0x03a3d8..0x03a48f), bao gồm Json::Value, Json::CZString,
// Json::ValueIteratorBase / ValueConstIterator / ValueIterator, Json::Reader,
// Json::Writer / FastWriter / StyledWriter và Json::Path / PathArgument.
// ============================================================================

#pragma once

#include "vcbasekit_types.h"

#include <istream>
#include <map>
#include <string>
#include <vector>

namespace Json {

// ============================================================================
// 1. Features & StaticString
// Cấu hình tính năng phân tích cú pháp Json::Features và chuỗi tĩnh StaticString.
// ============================================================================
class Features {
public:
    static Features all() noexcept;
    static Features strictMode() noexcept;
    Features() noexcept = default;

    bool allowComments_ = true;
    bool strictRoot_ = false;
    bool allowDroppedNullPlaceholders_ = false;
    bool allowNumericKeys_ = false;
};

class StaticString {
public:
    constexpr explicit StaticString(const char* czstring) noexcept : c_str_(czstring) {}
    constexpr operator const char*() const noexcept { return c_str_; }
    constexpr const char* c_str() const noexcept { return c_str_; }

private:
    const char* c_str_;
};

// ============================================================================
// 2. Json::Value & CZString & CommentInfo (0x010868..0x018c00)
// Lớp biểu diễn giá trị JSON đa kiểu (Value, CZString, CommentInfo).
// ============================================================================
class Value {
public:
    class CZString {
    public:
        enum DuplicationPolicy : uint32_t {
            noDuplication   = 0,
            duplicate       = 1,
            duplicateOnCopy = 2
        };

        explicit CZString(ArrayIndex index) noexcept;                                // 0x014864
        CZString(const char* str, unsigned length, DuplicationPolicy allocate);      // 0x014870
        CZString(const CZString& other);                                             // 0x014880
        CZString(CZString&& other) noexcept;                                         // 0x014968
        ~CZString();                                                                 // 0x014980

        CZString& operator=(const CZString& other);                                  // 0x0149c8
        void swap(CZString& other) noexcept;                                         // 0x0149a4
        bool operator<(const CZString& other) const noexcept;                        // 0x0149ec
        bool operator==(const CZString& other) const noexcept;

        ArrayIndex index() const noexcept { return index_; }
        const char* data() const noexcept { return cstr_; }
        unsigned length() const noexcept { return storage_.length_; }
        bool isStaticString() const noexcept { return storage_.policy_ == noDuplication; }

    private:
        struct StringStorage {
            unsigned policy_ : 2;
            unsigned length_ : 30;
        };
        const char* cstr_ = nullptr;
        union {
            ArrayIndex index_;
            StringStorage storage_;
        };
    };

    struct CommentInfo {
        CommentInfo() noexcept;                                                      // 0x014678
        ~CommentInfo();                                                              // 0x014680
        void setComment(const char* text, size_t len);                               // 0x014690
        char* comment_ = nullptr;
    };

    using ObjectValues = std::map<CZString, Value>;
    using Members = std::vector<std::string>;

    static const Value& nullSingleton();                                             // 0x014600

    static constexpr LargestInt  maxLargestInt  = kJsonMaxLargestInt;                // 0x02bec8
    static constexpr LargestUInt maxLargestUInt = kJsonMaxLargestUInt;               // 0x02bed0
    static constexpr LargestInt  minLargestInt  = kJsonMinLargestInt;                // 0x02bed8
    static constexpr Int         maxInt         = kJsonMaxInt;                       // 0x02bee0
    static constexpr Int         minInt         = kJsonMinInt;                       // 0x02bee8
    static constexpr UInt        maxUInt        = kJsonMaxUInt;                      // 0x02beec
    static constexpr Int64       minInt64       = kJsonMinInt64;                     // 0x02bef0
    static constexpr Int64       maxInt64       = kJsonMaxInt64;                     // 0x02bef8
    static constexpr UInt64      maxUInt64      = kJsonMaxUInt64;                    // 0x02bf00

    Value(ValueType type = nullValue);
    Value(Int value);
    Value(UInt value);
    Value(Int64 value);
    Value(UInt64 value);
    Value(double value);
    Value(const char* value);
    Value(const char* begin, const char* end);
    Value(const StaticString& value);
    Value(const std::string& value);
    Value(bool value);
    Value(const Value& other);
    Value(Value&& other) noexcept;
    ~Value();

    Value& operator=(Value other);                                                   // 0x013190
    void swap(Value& other) noexcept;
    void swapPayload(Value& other) noexcept;                                         // 0x011724

    ValueType type() const noexcept { return type_; }
    bool isNull() const noexcept { return type_ == nullValue; }
    bool isBool() const noexcept { return type_ == booleanValue; }
    bool isInt() const noexcept;
    bool isInt64() const noexcept;
    bool isUInt() const noexcept;
    bool isUInt64() const noexcept;
    bool isIntegral() const noexcept;
    bool isDouble() const noexcept { return type_ == intValue || type_ == uintValue || type_ == realValue; }
    bool isNumeric() const noexcept { return isDouble(); }
    bool isString() const noexcept { return type_ == stringValue; }
    bool isArray() const noexcept { return type_ == arrayValue; }                    // 0x0108f4
    bool isObject() const noexcept { return type_ == objectValue; }                  // 0x010904

    const char* asCString() const;                                                   // 0x012bf0
    std::string asString() const;
    Int asInt() const;
    UInt asUInt() const;
    Int64 asInt64() const;
    UInt64 asUInt64() const;
    LargestInt asLargestInt() const;
    LargestUInt asLargestUInt() const;
    float asFloat() const;
    double asDouble() const;
    bool asBool() const;

    ArrayIndex size() const noexcept;
    bool empty() const noexcept;
    void clear();
    void resize(ArrayIndex new_size);

    Value& operator[](ArrayIndex index);
    Value& operator[](int index);                                                    // 0x012cc8
    const Value& operator[](ArrayIndex index) const;
    const Value& operator[](int index) const;
    Value& append(const Value& value);

    Value& operator[](const char* key);
    const Value& operator[](const char* key) const;
    Value& operator[](const std::string& key);                                       // 0x012ca8
    const Value& operator[](const std::string& key) const;
    bool isMember(const std::string& key) const;
    Members getMemberNames() const;

    void setComment(const std::string& comment, CommentPlacement placement);         // 0x010868
    bool hasComment(CommentPlacement placement) const noexcept;
    std::string getComment(CommentPlacement placement) const;

    void setOffsetStart(ptrdiff_t start) noexcept { start_ = start; }                // 0x011774
    void setOffsetLimit(ptrdiff_t limit) noexcept { limit_ = limit; }                // 0x011180
    ptrdiff_t getOffsetStart() const noexcept { return start_; }
    ptrdiff_t getOffsetLimit() const noexcept { return limit_; }

    const ObjectValues& objectMap() const noexcept { return map_; }

private:
    ValueType type_ = nullValue;
    bool allocated_ = false;
    LargestInt int_val_ = 0;
    LargestUInt uint_val_ = 0;
    double real_val_ = 0.0;
    bool bool_val_ = false;
    std::string str_val_;
    std::vector<Value> array_;
    ObjectValues map_;
    CommentInfo comments_[numberOfCommentPlacement];
    ptrdiff_t start_ = 0;                                                            // +0x10
    ptrdiff_t limit_ = 0;                                                            // +0x18
};

// ============================================================================
// 3. Json::Reader (0x00fb20..0x014300)
// Bộ phân tích cú pháp JSON đệ quy có kiểm tra stackLimit (<= 1000).
// ============================================================================
class Reader {
public:
    enum TokenType : uint32_t {
        tokenEndOfStream = 0,
        tokenObjectBegin,
        tokenObjectEnd,
        tokenArrayBegin,
        tokenArrayEnd,
        tokenString,
        tokenNumber,
        tokenTrue,
        tokenFalse,
        tokenNull,
        tokenArraySeparator,
        tokenMemberSeparator,
        tokenComment,
        tokenError
    };

    struct Token {
        TokenType type_ = tokenEndOfStream;
        const char* start_ = nullptr;
        const char* end_ = nullptr;
    };

    struct StructuredError {
        ptrdiff_t offset_start = 0;
        ptrdiff_t offset_limit = 0;
        std::string message;
    };

    Reader();                                                                        // 0x00fb20
    explicit Reader(const Features& features);

    bool parse(const std::string& document, Value& root, bool collectComments = true); // 0x00fb50
    bool parse(const char* beginDoc, const char* endDoc, Value& root, bool collectComments = true); // 0x00fd10
    bool parse(std::istream& is, Value& root, bool collectComments = true);          // 0x00ffdc

    std::string getFormattedErrorMessages() const;
    std::vector<StructuredError> getStructuredErrors() const;
    bool good() const noexcept { return errors_.empty(); }

private:
    bool readValue();                                                                // 0x010264
    void skipCommentTokens(Token& token);                                            // 0x010814
    bool readToken(Token& token);                                                    // 0x01177c
    void skipSpaces();                                                               // 0x0119d0
    bool match(const char* pattern, int patternLength);                              // 0x011d10
    bool readComment();                                                              // 0x011aa0
    bool readCStyleComment();                                                        // 0x011d68
    bool readCppStyleComment();                                                      // 0x011de0
    bool readString();                                                               // 0x011a38
    void readNumber();                                                               // 0x011c40
    bool readObject(Token& token);                                                   // 0x010bd4
    bool readArray(Token& token);                                                    // 0x011188
    bool decodeNumber(Token& token);                                                 // 0x01147c
    bool decodeNumber(Token& token, Value& decoded);                                 // 0x012a00
    bool decodeString(Token& token);                                                 // 0x0115c4
    bool decodeString(Token& token, std::string& decoded);                           // 0x0120c8
    bool decodeDouble(Token& token);                                                 // 0x013200
    bool decodeDouble(Token& token, Value& decoded);                                 // 0x012d30
    bool decodeUnicodeCodePoint(Token& token, const char*& current, const char* end, unsigned int& unicode); // 0x0134bc
    bool decodeUnicodeEscapeSequence(Token& token, const char*& current, const char* end, unsigned int& unicode);
    bool addError(const std::string& message, Token& token, const char* extra = nullptr); // 0x010914
    bool recoverFromError(TokenType skipUntilToken);                                 // 0x012880
    bool addErrorAndRecover(const std::string& message, Token& token, TokenType skipUntilToken); // 0x012c70
    Value& currentValue();                                                           // 0x010bac
    char getNextChar();                                                              // 0x011a14
    void getLocationLineAndColumn(const char* location, int& line, int& column) const;
    void addComment(const char* begin, const char* end, CommentPlacement placement); // 0x011e30

    std::vector<Value*> nodes_;
    std::vector<StructuredError> errors_;
    std::string document_;
    const char* begin_ = nullptr;
    const char* end_ = nullptr;
    const char* current_ = nullptr;
    const char* lastValueEnd_ = nullptr;
    Value* lastValue_ = nullptr;
    std::string commentsBefore_;
    Features features_;
    bool collectComments_ = false;
};

// ============================================================================
// 4. Json::Writer, FastWriter & StyledWriter (vtables at .data.rel.ro 0x03a3d8..0x03a488)
// Bộ tuần tự hóa JSON (Writer, FastWriter, StyledWriter).
// ============================================================================
class Writer {
public:
    virtual ~Writer();
    virtual std::string write(const Value& root) = 0;
};

class FastWriter : public Writer {
public:
    FastWriter() = default;
    ~FastWriter() override = default;

    void enableYAMLCompatibility() noexcept { yamlCompatibilityEnabled_ = true; }
    void dropNullPlaceholders() noexcept { dropNullPlaceholders_ = true; }
    void omitEndingLineFeed() noexcept { omitEndingLineFeed_ = true; }

    std::string write(const Value& root) override;

private:
    void writeValue(const Value& value);

    std::string document_;
    bool yamlCompatibilityEnabled_ = false;
    bool dropNullPlaceholders_ = false;
    bool omitEndingLineFeed_ = false;
};

class StyledWriter : public Writer {
public:
    StyledWriter() = default;
    ~StyledWriter() override = default;

    std::string write(const Value& root) override;

private:
    void writeValue(const Value& value, size_t indent_level);

    std::string document_;
    size_t indentSize_ = 3;
};

} // namespace Json
