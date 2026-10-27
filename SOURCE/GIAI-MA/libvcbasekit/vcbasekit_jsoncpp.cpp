// ============================================================================
// File: vcbasekit_jsoncpp.cpp
// Target: libvcbasekit.so (231,568 bytes)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
//
// Description (EN):
// Clean-room C++17 implementation of the embedded JsonCpp subsystem in
// libvcbasekit.so (.text 0x00fb20..0x021720, .rodata 0x02b530..0x02bf3f,
// .data.rel.ro 0x03a3d8..0x03a48f).
//
// Mô tả (VI):
// Triển khai C++17 tái tạo sạch cho phân hệ JsonCpp nhúng trong libvcbasekit.so
// (.text 0x00fb20..0x021720, .rodata 0x02b530..0x02bf3f, .data.rel.ro
// 0x03a3d8..0x03a48f).
// ============================================================================

#include "vcbasekit_jsoncpp.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace Json {

// ============================================================================
// 1. Features Implementation
// Triển khai cấu hình phân tích cú pháp Json::Features.
// ============================================================================
Features Features::all() noexcept {
    return Features{};
}

Features Features::strictMode() noexcept {
    Features f;
    f.allowComments_ = false;
    f.strictRoot_ = true;
    f.allowDroppedNullPlaceholders_ = false;
    f.allowNumericKeys_ = false;
    return f;
}

// ============================================================================
// 2. Value::CZString & CommentInfo Implementation (0x014678..0x014a60)
// Triển khai lớp khóa chuỗi CZString và thông tin chú thích CommentInfo.
// ============================================================================
Value::CZString::CZString(ArrayIndex index) noexcept
    : cstr_(nullptr), index_(index) {}

Value::CZString::CZString(const char* str, unsigned length, DuplicationPolicy allocate)
    : cstr_(str) {
    storage_.policy_ = allocate & 0x3U;
    storage_.length_ = length & 0x3FFFFFFFU;
    if (allocate == duplicate && str != nullptr) {
        char* copy = static_cast<char*>(std::malloc(length + 1));
        if (copy != nullptr) {
            std::memcpy(copy, str, length);
            copy[length] = '\0';
            cstr_ = copy;
        }
    }
}

Value::CZString::CZString(const CZString& other) {
    if (other.cstr_ == nullptr) {
        cstr_ = nullptr;
        index_ = other.index_;
    } else {
        storage_.length_ = other.storage_.length_;
        const bool should_dup = (other.storage_.policy_ != noDuplication);
        storage_.policy_ = should_dup ? duplicate : noDuplication;
        if (should_dup) {
            char* copy = static_cast<char*>(std::malloc(storage_.length_ + 1));
            if (copy != nullptr) {
                std::memcpy(copy, other.cstr_, storage_.length_);
                copy[storage_.length_] = '\0';
            }
            cstr_ = copy;
        } else {
            cstr_ = other.cstr_;
        }
    }
}

Value::CZString::CZString(CZString&& other) noexcept
    : cstr_(other.cstr_), index_(other.index_) {
    other.cstr_ = nullptr;
}

Value::CZString::~CZString() {
    if (cstr_ != nullptr && storage_.policy_ == duplicate) {
        std::free(const_cast<char*>(cstr_));
    }
}

void Value::CZString::swap(CZString& other) noexcept {
    std::swap(cstr_, other.cstr_);
    std::swap(index_, other.index_);
}

Value::CZString& Value::CZString::operator=(const CZString& other) {
    if (this != &other) {
        CZString temp(other);
        swap(temp);
    }
    return *this;
}

// 0x0149ec..0x014a5c: CZString::operator<
bool Value::CZString::operator<(const CZString& other) const noexcept {
    if (cstr_ == nullptr || other.cstr_ == nullptr) {
        return index_ < other.index_;
    }
    const unsigned this_len = storage_.length_;
    const unsigned other_len = other.storage_.length_;
    const unsigned min_len = std::min(this_len, other_len);
    const int cmp = std::memcmp(cstr_, other.cstr_, min_len);
    if (cmp < 0) return true;
    if (cmp > 0) return false;
    return this_len < other_len;
}

bool Value::CZString::operator==(const CZString& other) const noexcept {
    if (cstr_ == nullptr || other.cstr_ == nullptr) {
        return index_ == other.index_;
    }
    if (storage_.length_ != other.storage_.length_) {
        return false;
    }
    return std::memcmp(cstr_, other.cstr_, storage_.length_) == 0;
}

Value::CommentInfo::CommentInfo() noexcept = default;

Value::CommentInfo::~CommentInfo() {
    if (comment_ != nullptr) {
        std::free(comment_);
    }
}

// 0x014690..0x01476c: Value::CommentInfo::setComment
void Value::CommentInfo::setComment(const char* text, size_t len) {
    if (comment_ != nullptr) {
        std::free(comment_);
        comment_ = nullptr;
    }
    if (text != nullptr && len > 0) {
        comment_ = static_cast<char*>(std::malloc(len + 1));
        if (comment_ != nullptr) {
            std::memcpy(comment_, text, len);
            comment_[len] = '\0';
        }
    }
}

// ============================================================================
// 3. Json::Value Implementation (0x010868..0x018c00)
// Triển khai lớp Json::Value.
// ============================================================================
// 0x014600..0x014674 (and .init_array[0] at 0x00f9b0): Value::nullSingleton()
const Value& Value::nullSingleton() {
    static const Value kNull(nullValue);
    return kNull;
}

Value::Value(ValueType type) : type_(type) {}
Value::Value(Int value) : type_(intValue), int_val_(value) {}
Value::Value(UInt value) : type_(uintValue), uint_val_(value) {}
Value::Value(Int64 value) : type_(intValue), int_val_(value) {}
Value::Value(UInt64 value) : type_(uintValue), uint_val_(value) {}
Value::Value(double value) : type_(realValue), real_val_(value) {}
Value::Value(const char* value) : type_(stringValue), str_val_(value ? value : "") {}
Value::Value(const char* begin, const char* end) : type_(stringValue), str_val_(begin, end) {}
Value::Value(const StaticString& value) : type_(stringValue), str_val_(value.c_str() ? value.c_str() : "") {}
Value::Value(const std::string& value) : type_(stringValue), str_val_(value) {}
Value::Value(bool value) : type_(booleanValue), bool_val_(value) {}

Value::Value(const Value& other)
    : type_(other.type_),
      allocated_(other.allocated_),
      int_val_(other.int_val_),
      uint_val_(other.uint_val_),
      real_val_(other.real_val_),
      bool_val_(other.bool_val_),
      str_val_(other.str_val_),
      array_(other.array_),
      map_(other.map_),
      start_(other.start_),
      limit_(other.limit_) {
    for (uint32_t i = 0; i < numberOfCommentPlacement; ++i) {
        if (other.comments_[i].comment_ != nullptr) {
            comments_[i].setComment(other.comments_[i].comment_, std::strlen(other.comments_[i].comment_));
        }
    }
}

Value::Value(Value&& other) noexcept {
    swap(other);
}

Value::~Value() = default;

Value& Value::operator=(Value other) {
    swap(other);
    return *this;
}

void Value::swap(Value& other) noexcept {
    swapPayload(other);
    for (uint32_t i = 0; i < numberOfCommentPlacement; ++i) {
        std::swap(comments_[i].comment_, other.comments_[i].comment_);
    }
    std::swap(start_, other.start_);
    std::swap(limit_, other.limit_);
}

// 0x011724..0x011770: Value::swapPayload
void Value::swapPayload(Value& other) noexcept {
    std::swap(type_, other.type_);
    std::swap(allocated_, other.allocated_);
    std::swap(int_val_, other.int_val_);
    std::swap(uint_val_, other.uint_val_);
    std::swap(real_val_, other.real_val_);
    std::swap(bool_val_, other.bool_val_);
    str_val_.swap(other.str_val_);
    array_.swap(other.array_);
    map_.swap(other.map_);
}

bool Value::isInt() const noexcept {
    if (type_ == intValue) return int_val_ >= minInt && int_val_ <= maxInt;
    if (type_ == uintValue) return uint_val_ <= static_cast<LargestUInt>(maxInt);
    return false;
}

bool Value::isUInt() const noexcept {
    if (type_ == intValue) return int_val_ >= 0 && static_cast<LargestUInt>(int_val_) <= maxUInt;
    if (type_ == uintValue) return uint_val_ <= maxUInt;
    return false;
}

bool Value::isInt64() const noexcept {
    if (type_ == intValue) return true;
    if (type_ == uintValue) return uint_val_ <= static_cast<LargestUInt>(maxInt64);
    return false;
}

bool Value::isUInt64() const noexcept {
    if (type_ == intValue) return int_val_ >= 0;
    if (type_ == uintValue) return true;
    return false;
}

bool Value::isIntegral() const noexcept {
    return type_ == intValue || type_ == uintValue || type_ == booleanValue;
}

// 0x012bf0..0x012c6c: Value::asCString() const
const char* Value::asCString() const {
    if (type_ != stringValue) {
        return "";
    }
    return str_val_.c_str();
}

std::string Value::asString() const {
    switch (type_) {
        case nullValue: return "";
        case stringValue: return str_val_;
        case booleanValue: return bool_val_ ? "true" : "false"; // .rodata 0x02b873 / 0x02b878
        case intValue: return std::to_string(int_val_);
        case uintValue: return std::to_string(uint_val_);
        case realValue: return std::to_string(real_val_);
        default: return "";
    }
}

Int Value::asInt() const {
    switch (type_) {
        case intValue: return static_cast<Int>(int_val_);
        case uintValue: return static_cast<Int>(uint_val_);
        case realValue: return static_cast<Int>(real_val_);
        case nullValue: return 0;
        case booleanValue: return bool_val_ ? 1 : 0;
        default: return 0;
    }
}

UInt Value::asUInt() const {
    switch (type_) {
        case intValue: return static_cast<UInt>(int_val_);
        case uintValue: return static_cast<UInt>(uint_val_);
        case realValue: return static_cast<UInt>(real_val_);
        case nullValue: return 0U;
        case booleanValue: return bool_val_ ? 1U : 0U;
        default: return 0U;
    }
}

Int64 Value::asInt64() const {
    switch (type_) {
        case intValue: return int_val_;
        case uintValue: return static_cast<Int64>(uint_val_);
        case realValue: return static_cast<Int64>(real_val_);
        case nullValue: return 0LL;
        case booleanValue: return bool_val_ ? 1LL : 0LL;
        default: return 0LL;
    }
}

UInt64 Value::asUInt64() const {
    switch (type_) {
        case intValue: return static_cast<UInt64>(int_val_);
        case uintValue: return uint_val_;
        case realValue: return static_cast<UInt64>(real_val_);
        case nullValue: return 0ULL;
        case booleanValue: return bool_val_ ? 1ULL : 0ULL;
        default: return 0ULL;
    }
}

LargestInt Value::asLargestInt() const { return asInt64(); }
LargestUInt Value::asLargestUInt() const { return asUInt64(); }
float Value::asFloat() const { return static_cast<float>(asDouble()); }

double Value::asDouble() const {
    switch (type_) {
        case intValue: return static_cast<double>(int_val_);
        case uintValue: return static_cast<double>(uint_val_);
        case realValue: return real_val_;
        case nullValue: return 0.0;
        case booleanValue: return bool_val_ ? 1.0 : 0.0;
        default: return 0.0;
    }
}

bool Value::asBool() const {
    switch (type_) {
        case booleanValue: return bool_val_;
        case nullValue: return false;
        case intValue: return int_val_ != 0;
        case uintValue: return uint_val_ != 0;
        case realValue: return real_val_ != 0.0;
        default: return !empty();
    }
}

ArrayIndex Value::size() const noexcept {
    if (type_ == arrayValue) return static_cast<ArrayIndex>(array_.size());
    if (type_ == objectValue) return static_cast<ArrayIndex>(map_.size());
    return 0;
}

bool Value::empty() const noexcept {
    if (isNull() || isArray() || isObject()) return size() == 0U;
    return false;
}

void Value::clear() {
    array_.clear();
    map_.clear();
}

void Value::resize(ArrayIndex new_size) {
    if (type_ == nullValue) type_ = arrayValue;
    array_.resize(new_size);
}

Value& Value::operator[](ArrayIndex index) {
    if (type_ == nullValue) type_ = arrayValue;
    if (index >= array_.size()) {
        array_.resize(index + 1);
    }
    return array_[index];
}

// 0x012cc8..0x012d2c: Value::operator[](int index)
Value& Value::operator[](int index) {
    return (*this)[static_cast<ArrayIndex>(index >= 0 ? index : 0)];
}

const Value& Value::operator[](ArrayIndex index) const {
    if (type_ == arrayValue && index < array_.size()) {
        return array_[index];
    }
    return nullSingleton();
}

const Value& Value::operator[](int index) const {
    return (*this)[static_cast<ArrayIndex>(index >= 0 ? index : 0)];
}

Value& Value::append(const Value& value) {
    return (*this)[size()] = value;
}

Value& Value::operator[](const char* key) {
    if (type_ == nullValue) type_ = objectValue;
    const unsigned len = key ? static_cast<unsigned>(std::strlen(key)) : 0U;
    CZString cz(key, len, CZString::duplicate);
    return map_[cz];
}

const Value& Value::operator[](const char* key) const {
    if (type_ != objectValue || key == nullptr) return nullSingleton();
    const unsigned len = static_cast<unsigned>(std::strlen(key));
    CZString cz(key, len, CZString::noDuplication);
    auto it = map_.find(cz);
    return (it != map_.end()) ? it->second : nullSingleton();
}

// 0x012ca8..0x012cc4: Value::operator[](const std::string& key)
Value& Value::operator[](const std::string& key) {
    return (*this)[key.c_str()];
}

const Value& Value::operator[](const std::string& key) const {
    return (*this)[key.c_str()];
}

bool Value::isMember(const std::string& key) const {
    if (type_ != objectValue) return false;
    CZString cz(key.c_str(), static_cast<unsigned>(key.size()), CZString::noDuplication);
    return map_.find(cz) != map_.end();
}

Value::Members Value::getMemberNames() const {
    Members names;
    if (type_ == objectValue) {
        names.reserve(map_.size());
        for (const auto& kv : map_) {
            if (kv.first.data() != nullptr) {
                names.emplace_back(kv.first.data(), kv.first.length());
            }
        }
    }
    return names;
}

// 0x010868..0x0108f0: Value::setComment
void Value::setComment(const std::string& comment, CommentPlacement placement) {
    if (placement < numberOfCommentPlacement && !comment.empty() && comment[0] == '/') {
        comments_[placement].setComment(comment.data(), comment.size());
    }
}

bool Value::hasComment(CommentPlacement placement) const noexcept {
    return placement < numberOfCommentPlacement && comments_[placement].comment_ != nullptr;
}

std::string Value::getComment(CommentPlacement placement) const {
    if (hasComment(placement)) {
        return comments_[placement].comment_;
    }
    return "";
}

// ============================================================================
// 4. Json::Reader Implementation (0x00fb20..0x014300)
// Triển khai bộ phân tích cú pháp Json::Reader.
// ============================================================================
Reader::Reader() : features_(Features::all()) {}

Reader::Reader(const Features& features) : features_(features) {}

// 0x00fb50..0x00fd0c: Reader::parse(const std::string&, Value&, bool)
bool Reader::parse(const std::string& document, Value& root, bool collectComments) {
    document_ = document;
    const char* begin = document_.c_str();
    const char* end = begin + document_.length();
    return parse(begin, end, root, collectComments);
}

// 0x00ffdc..0x01009c: Reader::parse(std::istream&, Value&, bool)
bool Reader::parse(std::istream& is, Value& root, bool collectComments) {
    std::ostringstream oss;
    oss << is.rdbuf();
    return parse(oss.str(), root, collectComments);
}

// 0x00fd10..0x00ffd8: Reader::parse(const char*, const char*, Value&, bool)
bool Reader::parse(const char* beginDoc, const char* endDoc, Value& root, bool collectComments) {
    if (!features_.allowComments_) {
        collectComments = false;
    }
    begin_ = beginDoc;
    end_ = endDoc;
    collectComments_ = collectComments;
    current_ = begin_;
    lastValueEnd_ = nullptr;
    lastValue_ = nullptr;
    commentsBefore_.clear();
    errors_.clear();
    nodes_.clear();
    nodes_.push_back(&root);

    bool successful = readValue();
    Token token;
    skipCommentTokens(token);
    if (collectComments_ && !commentsBefore_.empty() && lastValue_ != nullptr) {
        lastValue_->setComment(commentsBefore_, commentAfter);
    }
    if (features_.strictRoot_) {
        if (!root.isArray() && !root.isObject()) {
            Token err_tok{tokenError, beginDoc, endDoc};
            addError("Syntax error: value, object or array expected.", err_tok); // .rodata 0x02b554
            return false;
        }
    }
    return successful;
}

// 0x010bac..0x010bd0: Reader::currentValue()
Value& Reader::currentValue() {
    return *(nodes_.back());
}

// 0x011a14..0x011a34: Reader::getNextChar()
char Reader::getNextChar() {
    if (current_ == end_) return 0;
    return *current_++;
}

// 0x0119d0..0x011a10: Reader::skipSpaces()
void Reader::skipSpaces() {
    while (current_ != end_) {
        const char c = *current_;
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            ++current_;
        } else {
            break;
        }
    }
}

// 0x011d10..0x011d64: Reader::match(const char* pattern, int patternLength)
bool Reader::match(const char* pattern, int patternLength) {
    if (end_ - current_ < patternLength) {
        return false;
    }
    int index = patternLength;
    while (index--) {
        if (current_[index] != pattern[index]) {
            return false;
        }
    }
    current_ += patternLength;
    return true;
}

// 0x010814..0x010864: Reader::skipCommentTokens(Token& token)
void Reader::skipCommentTokens(Token& token) {
    if (features_.allowComments_) {
        do {
            readToken(token);
        } while (token.type_ == tokenComment);
    } else {
        readToken(token);
    }
}

// 0x011aa0..0x011c3c: Reader::readComment()
bool Reader::readComment() {
    const char* commentBegin = current_ - 1;
    const char c = getNextChar();
    bool successful = false;
    if (c == '*') {
        successful = readCStyleComment();
    } else if (c == '/') {
        successful = readCppStyleComment();
    }
    if (!successful) {
        return false;
    }
    if (collectComments_) {
        addComment(commentBegin, current_, commentBefore);
    }
    return true;
}

// 0x011d68..0x011ddc: Reader::readCStyleComment()
bool Reader::readCStyleComment() {
    while ((current_ + 1) < end_) {
        const char c = getNextChar();
        if (c == '*' && *current_ == '/') {
            break;
        }
    }
    return getNextChar() == '/';
}

// 0x011de0..0x011e2c: Reader::readCppStyleComment()
bool Reader::readCppStyleComment() {
    while (current_ != end_) {
        const char c = getNextChar();
        if (c == '\n') break;
        if (c == '\r') {
            if (current_ != end_ && *current_ == '\n') {
                getNextChar();
            }
            break;
        }
    }
    return true;
}

// 0x011e30..0x0120c4: Reader::addComment
void Reader::addComment(const char* begin, const char* end, CommentPlacement placement) {
    if (placement == commentAfterOnSameLine && lastValue_ != nullptr) {
        lastValue_->setComment(std::string(begin, end), placement);
    } else {
        if (!commentsBefore_.empty()) {
            commentsBefore_ += "\n";
        }
        commentsBefore_.append(begin, end);
    }
}

// 0x011a38..0x011a9c: Reader::readString()
bool Reader::readString() {
    char c = 0;
    while (current_ != end_) {
        c = getNextChar();
        if (c == '\\') {
            getNextChar();
        } else if (c == '"') {
            break;
        }
    }
    return c == '"';
}

// 0x011c40..0x011d0c: Reader::readNumber()
void Reader::readNumber() {
    const char* p = current_;
    char c = '0';
    while (p != end_ && ((c = *p) >= '0' && c <= '9')) ++p;
    if (p != end_ && *p == '.') {
        ++p;
        while (p != end_ && ((c = *p) >= '0' && c <= '9')) ++p;
    }
    if (p != end_ && (*p == 'e' || *p == 'E')) {
        ++p;
        if (p != end_ && (*p == '+' || *p == '-')) ++p;
        while (p != end_ && ((c = *p) >= '0' && c <= '9')) ++p;
    }
    current_ = p;
}

// 0x01177c..0x0119cc: Reader::readToken(Token& token)
bool Reader::readToken(Token& token) {
    skipSpaces();
    token.start_ = current_;
    const char c = getNextChar();
    bool ok = true;
    switch (c) {
        case '{': token.type_ = tokenObjectBegin; break;
        case '}': token.type_ = tokenObjectEnd; break;
        case '[': token.type_ = tokenArrayBegin; break;
        case ']': token.type_ = tokenArrayEnd; break;
        case '"':
            token.type_ = tokenString;
            ok = readString();
            break;
        case '/':
            token.type_ = tokenComment;
            ok = readComment();
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '-':
            token.type_ = tokenNumber;
            readNumber();
            break;
        case 't':
            token.type_ = tokenTrue;
            ok = match("rue", 3);
            break;
        case 'f':
            token.type_ = tokenFalse;
            ok = match("alse", 4);
            break;
        case 'n':
            token.type_ = tokenNull;
            ok = match("ull", 3);
            break;
        case ',': token.type_ = tokenArraySeparator; break;
        case ':': token.type_ = tokenMemberSeparator; break;
        case 0: token.type_ = tokenEndOfStream; break;
        default: ok = false; break;
    }
    if (!ok) {
        token.type_ = tokenError;
    }
    token.end_ = current_;
    return true;
}

// 0x010264..0x010810: Reader::readValue()
bool Reader::readValue() {
    if (nodes_.size() > 1000U) {
        Token tok{tokenError, current_, current_};
        return addError("Exceeded stackLimit in readValue().", tok); // .rodata 0x02b530
    }
    Token token;
    skipCommentTokens(token);
    bool successful = true;

    if (collectComments_ && !commentsBefore_.empty()) {
        currentValue().setComment(commentsBefore_, commentBefore);
        commentsBefore_.clear();
    }

    switch (token.type_) {
        case tokenObjectBegin:
            successful = readObject(token);
            currentValue().setOffsetLimit(current_ - begin_);
            break;
        case tokenArrayBegin:
            successful = readArray(token);
            currentValue().setOffsetLimit(current_ - begin_);
            break;
        case tokenNumber:
            successful = decodeNumber(token);
            break;
        case tokenString:
            successful = decodeString(token);
            break;
        case tokenTrue: {
            Value v(true);
            currentValue().swapPayload(v);
            currentValue().setOffsetStart(token.start_ - begin_);
            currentValue().setOffsetLimit(token.end_ - begin_);
            break;
        }
        case tokenFalse: {
            Value v(false);
            currentValue().swapPayload(v);
            currentValue().setOffsetStart(token.start_ - begin_);
            currentValue().setOffsetLimit(token.end_ - begin_);
            break;
        }
        case tokenNull: {
            Value v;
            currentValue().swapPayload(v);
            currentValue().setOffsetStart(token.start_ - begin_);
            currentValue().setOffsetLimit(token.end_ - begin_);
            break;
        }
        default:
            currentValue().setOffsetStart(token.start_ - begin_);
            currentValue().setOffsetLimit(token.end_ - begin_);
            return addError("Syntax error: value, object or array expected.", token); // .rodata 0x02b554
    }

    if (collectComments_) {
        lastValueEnd_ = current_;
        lastValue_ = &currentValue();
    }
    return successful;
}

// 0x010bd4..0x01117c: Reader::readObject(Token& token)
bool Reader::readObject(Token& tokenStart) {
    Token tokenName;
    std::string name;
    Value init(objectValue);
    currentValue().swapPayload(init);
    currentValue().setOffsetStart(tokenStart.start_ - begin_);
    while (readToken(tokenName)) {
        bool initialTokenOk = true;
        while (tokenName.type_ == tokenComment && initialTokenOk) {
            initialTokenOk = readToken(tokenName);
        }
        if (!initialTokenOk) break;
        if (tokenName.type_ == tokenObjectEnd && name.empty()) {
            return true;
        }
        name.clear();
        if (tokenName.type_ == tokenString) {
            if (!decodeString(tokenName, name)) {
                return recoverFromError(tokenObjectEnd);
            }
        } else {
            break;
        }
        Token colon;
        if (!readToken(colon) || colon.type_ != tokenMemberSeparator) {
            return addErrorAndRecover("Missing ':' after object member name", colon, tokenObjectEnd); // .rodata 0x02b583
        }
        Value& value = currentValue()[name];
        nodes_.push_back(&value);
        bool ok = readValue();
        nodes_.pop_back();
        if (!ok) {
            return recoverFromError(tokenObjectEnd);
        }
        Token comma;
        if (!readToken(comma) ||
            (comma.type_ != tokenObjectEnd && comma.type_ != tokenArraySeparator && comma.type_ != tokenComment)) {
            return addErrorAndRecover("Missing ',' or '}' in object declaration", comma, tokenObjectEnd); // .rodata 0x02b5a8
        }
        while (comma.type_ == tokenComment) {
            readToken(comma);
        }
        if (comma.type_ == tokenObjectEnd) {
            return true;
        }
    }
    return addErrorAndRecover("Missing '}' or object member name", tokenName, tokenObjectEnd); // .rodata 0x02b5d1
}

// 0x011188..0x011478: Reader::readArray(Token& token)
bool Reader::readArray(Token& tokenStart) {
    Value init(arrayValue);
    currentValue().swapPayload(init);
    currentValue().setOffsetStart(tokenStart.start_ - begin_);
    skipSpaces();
    if (current_ != end_ && *current_ == ']') {
        Token endArray;
        readToken(endArray);
        return true;
    }
    ArrayIndex index = 0;
    for (;;) {
        Value& value = currentValue()[index++];
        nodes_.push_back(&value);
        bool ok = readValue();
        nodes_.pop_back();
        if (!ok) {
            return recoverFromError(tokenArrayEnd);
        }
        Token currentToken;
        readToken(currentToken);
        while (currentToken.type_ == tokenComment) {
            readToken(currentToken);
        }
        if (currentToken.type_ == tokenArrayEnd) {
            break;
        }
        if (currentToken.type_ != tokenArraySeparator) {
            return addErrorAndRecover("Missing ',' or ']' in array declaration", currentToken, tokenArrayEnd); // .rodata 0x02b5f3
        }
    }
    return true;
}

// 0x01147c..0x0115c0: Reader::decodeNumber(Token& token)
bool Reader::decodeNumber(Token& token) {
    Value decoded;
    if (!decodeNumber(token, decoded)) {
        return false;
    }
    currentValue().swapPayload(decoded);
    currentValue().setOffsetStart(token.start_ - begin_);
    currentValue().setOffsetLimit(token.end_ - begin_);
    return true;
}

// 0x012a00..0x012bec: Reader::decodeNumber(Token& token, Value& decoded)
bool Reader::decodeNumber(Token& token, Value& decoded) {
    const char* current = token.start_;
    const bool isNegative = (*current == '-');
    if (isNegative) {
        ++current;
    }
    LargestUInt maxIntegerValue = isNegative ? (static_cast<LargestUInt>(Value::maxLargestInt) + 1ULL)
                                             : Value::maxLargestUInt;
    LargestUInt threshold = maxIntegerValue / 10ULL;
    LargestUInt value = 0;
    while (current < token.end_) {
        const char c = *current++;
        if (c < '0' || c > '9') {
            return decodeDouble(token, decoded);
        }
        const UInt digit = static_cast<UInt>(c - '0');
        if (value >= threshold) {
            if (value > threshold || current != token.end_ || digit > (maxIntegerValue % 10ULL)) {
                return decodeDouble(token, decoded);
            }
        }
        value = value * 10ULL + digit;
    }
    if (isNegative && value == maxIntegerValue) {
        decoded = Value::minLargestInt;
    } else if (isNegative) {
        decoded = -static_cast<LargestInt>(value);
    } else if (value <= static_cast<LargestUInt>(Value::maxInt)) {
        decoded = static_cast<LargestInt>(value);
    } else {
        decoded = value;
    }
    return true;
}

// 0x013200..0x013314: Reader::decodeDouble(Token& token)
bool Reader::decodeDouble(Token& token) {
    Value decoded;
    if (!decodeDouble(token, decoded)) {
        return false;
    }
    currentValue().swapPayload(decoded);
    currentValue().setOffsetStart(token.start_ - begin_);
    currentValue().setOffsetLimit(token.end_ - begin_);
    return true;
}

// 0x012d30..0x01318c: Reader::decodeDouble(Token& token, Value& decoded)
bool Reader::decodeDouble(Token& token, Value& decoded) {
    std::string buffer(token.start_, token.end_);
    char* end_ptr = nullptr;
    const double value = std::strtod(buffer.c_str(), &end_ptr);
    if (end_ptr != buffer.c_str() + buffer.size()) {
        return addError("'" + buffer + "' is not a number.", token); // .rodata 0x02b61d
    }
    decoded = value;
    return true;
}

// 0x0115c4..0x011720: Reader::decodeString(Token& token)
bool Reader::decodeString(Token& token) {
    std::string decoded_string;
    if (!decodeString(token, decoded_string)) {
        return false;
    }
    Value decoded(decoded_string);
    currentValue().swapPayload(decoded);
    currentValue().setOffsetStart(token.start_ - begin_);
    currentValue().setOffsetLimit(token.end_ - begin_);
    return true;
}

// 0x0120c8..0x01287c: Reader::decodeString(Token& token, std::string& decoded)
bool Reader::decodeString(Token& token, std::string& decoded) {
    decoded.reserve(static_cast<size_t>(token.end_ - token.start_ - 2));
    const char* current = token.start_ + 1;
    const char* end = token.end_ - 1;
    while (current < end) {
        char c = *current++;
        if (c == '"') {
            break;
        } else if (c == '\\') {
            if (current == end) {
                return addError("Empty escape sequence in string", token, current); // .rodata 0x02b630
            }
            const char escape = *current++;
            switch (escape) {
                case '"': decoded += '"'; break;
                case '/': decoded += '/'; break;
                case '\\': decoded += '\\'; break;
                case 'b': decoded += '\b'; break;
                case 'f': decoded += '\f'; break;
                case 'n': decoded += '\n'; break;
                case 'r': decoded += '\r'; break;
                case 't': decoded += '\t'; break;
                case 'u': {
                    unsigned int unicode = 0;
                    if (!decodeUnicodeCodePoint(token, current, end, unicode)) {
                        return false;
                    }
                    if (unicode <= 0x7FU) {
                        decoded += static_cast<char>(unicode);
                    } else if (unicode <= 0x7FFU) {
                        decoded += static_cast<char>(0xC0U | ((unicode >> 6) & 0x1FU));
                        decoded += static_cast<char>(0x80U | (unicode & 0x3FU));
                    } else if (unicode <= 0xFFFFU) {
                        decoded += static_cast<char>(0xE0U | ((unicode >> 12) & 0x0FU));
                        decoded += static_cast<char>(0x80U | ((unicode >> 6) & 0x3FU));
                        decoded += static_cast<char>(0x80U | (unicode & 0x3FU));
                    } else {
                        decoded += static_cast<char>(0xF0U | ((unicode >> 18) & 0x07U));
                        decoded += static_cast<char>(0x80U | ((unicode >> 12) & 0x3FU));
                        decoded += static_cast<char>(0x80U | ((unicode >> 6) & 0x3FU));
                        decoded += static_cast<char>(0x80U | (unicode & 0x3FU));
                    }
                    break;
                }
                default:
                    return addError("Bad escape sequence in string", token, current); // .rodata 0x02b650
            }
        } else {
            decoded += c;
        }
    }
    return true;
}

// 0x0134bc..0x013670: Reader::decodeUnicodeCodePoint
bool Reader::decodeUnicodeCodePoint(Token& token, const char*& current, const char* end, unsigned int& unicode) {
    if (!decodeUnicodeEscapeSequence(token, current, end, unicode)) {
        return false;
    }
    if (unicode >= 0xD800U && unicode <= 0xDBFFU) {
        if (end - current < 6) {
            return addError("additional six characters expected to parse unicode surrogate pair.", token, current);
        }
        if (current[0] == '\\' && current[1] == 'u') {
            current += 2;
            unsigned int surrogatePair = 0;
            if (decodeUnicodeEscapeSequence(token, current, end, surrogatePair)) {
                unicode = 0x10000U + ((unicode & 0x3FFU) << 10) + (surrogatePair & 0x3FFU);
            } else {
                return false;
            }
        } else {
            return addError("expecting another \\u token to begin the second half of a unicode surrogate pair", token, current);
        }
    }
    return true;
}

bool Reader::decodeUnicodeEscapeSequence(Token& token, const char*& current, const char* end, unsigned int& ret_unicode) {
    if (end - current < 4) {
        return addError("Bad unicode escape sequence in string: four digits expected.", token, current);
    }
    unsigned int unicode = 0;
    for (int index = 0; index < 4; ++index) {
        const char c = *current++;
        unicode <<= 4;
        if (c >= '0' && c <= '9') {
            unicode += static_cast<unsigned int>(c - '0');
        } else if (c >= 'a' && c <= 'f') {
            unicode += static_cast<unsigned int>(c - 'a' + 10);
        } else if (c >= 'A' && c <= 'F') {
            unicode += static_cast<unsigned int>(c - 'A' + 10);
        } else {
            return addError("Bad unicode escape sequence in string: hexadecimal digit expected.", token, current);
        }
    }
    ret_unicode = unicode;
    return true;
}

// 0x010914..0x010ba8: Reader::addError
bool Reader::addError(const std::string& message, Token& token, const char* /*extra*/) {
    StructuredError info;
    info.offset_start = token.start_ - begin_;
    info.offset_limit = token.end_ - begin_;
    info.message = message;
    errors_.push_back(std::move(info));
    return false;
}

// 0x012880..0x0129fc: Reader::recoverFromError
bool Reader::recoverFromError(TokenType skipUntilToken) {
    Token skip;
    for (;;) {
        readToken(skip);
        if (skip.type_ == skipUntilToken || skip.type_ == tokenEndOfStream) {
            break;
        }
    }
    return false;
}

// 0x012c70..0x012ca4: Reader::addErrorAndRecover
bool Reader::addErrorAndRecover(const std::string& message, Token& token, TokenType skipUntilToken) {
    addError(message, token);
    return recoverFromError(skipUntilToken);
}

void Reader::getLocationLineAndColumn(const char* location, int& line, int& column) const {
    const char* current = begin_;
    const char* lastLineStart = current;
    line = 0;
    while (current < location && current != end_) {
        const char c = *current++;
        if (c == '\r') {
            if (current != end_ && *current == '\n') {
                ++current;
            }
            lastLineStart = current;
            ++line;
        } else if (c == '\n') {
            lastLineStart = current;
            ++line;
        }
    }
    column = static_cast<int>(location - lastLineStart) + 1;
    ++line;
}

std::string Reader::getFormattedErrorMessages() const {
    std::string formatted;
    for (const auto& error : errors_) {
        int line = 0;
        int col = 0;
        getLocationLineAndColumn(begin_ + error.offset_start, line, col);
        char buf[64] = {0};
        std::snprintf(buf, sizeof(buf), "* Line %d, Column %d\n  ", line, col); // .rodata 0x02b782
        formatted += buf;
        formatted += error.message + "\n";
    }
    return formatted;
}

std::vector<Reader::StructuredError> Reader::getStructuredErrors() const {
    return errors_;
}

// ============================================================================
// 5. Json::Writer, FastWriter & StyledWriter Implementation
// Triển khai bộ tuần tự hóa JSON (Writer, FastWriter, StyledWriter).
// ============================================================================
Writer::~Writer() = default;

std::string FastWriter::write(const Value& root) {
    document_.clear();
    writeValue(root);
    if (!omitEndingLineFeed_) {
        document_ += "\n";
    }
    return document_;
}

void FastWriter::writeValue(const Value& value) {
    switch (value.type()) {
        case nullValue:
            if (!dropNullPlaceholders_) document_ += "null"; // .rodata 0x02bda6
            break;
        case intValue:
            document_ += std::to_string(value.asLargestInt());
            break;
        case uintValue:
            document_ += std::to_string(value.asLargestUInt());
            break;
        case realValue: {
            char buf[64] = {0};
            std::snprintf(buf, sizeof(buf), "%.16g", value.asDouble());
            document_ += buf;
            break;
        }
        case stringValue:
            document_ += "\"" + value.asString() + "\"";
            break;
        case booleanValue:
            document_ += value.asBool() ? "true" : "false";
            break;
        case arrayValue: {
            document_ += "[";
            const ArrayIndex n = value.size();
            for (ArrayIndex i = 0; i < n; ++i) {
                if (i > 0) document_ += ",";
                writeValue(value[i]);
            }
            document_ += "]";
            break;
        }
        case objectValue: {
            document_ += "{";
            const auto names = value.getMemberNames();
            for (size_t i = 0; i < names.size(); ++i) {
                if (i > 0) document_ += ",";
                document_ += "\"" + names[i] + "\":";
                if (yamlCompatibilityEnabled_) document_ += " ";
                writeValue(value[names[i]]);
            }
            document_ += "}";
            break;
        }
    }
}

std::string StyledWriter::write(const Value& root) {
    document_.clear();
    writeValue(root, 0);
    document_ += "\n";
    return document_;
}

void StyledWriter::writeValue(const Value& value, size_t indent_level) {
    FastWriter fw;
    fw.omitEndingLineFeed();
    (void)indent_level;
    document_ += fw.write(value);
}

} // namespace Json
