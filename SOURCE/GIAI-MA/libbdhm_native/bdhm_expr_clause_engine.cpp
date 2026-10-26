// ============================================================================
// File: bdhm_expr_clause_engine.cpp
// Module: libbdhm_native.so — Expression Tokenizer, Interpreter & Clause DSL
//         (Triển khai Bộ Tách Từ, Thông Dịch Toán Học & Đánh Giá Mệnh Đề DSL)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from bdhm_native/src/expr/tokenizer.rs,
//               bdhm_native/src/expr/interpreter.rs,
//               bdhm_native/src/api/interpreter.rs,
//               bdhm_native/src/api/clause.rs, and
//               bdhm_native/src/api/manifest.rs (.rodata 0x00d600..0x00de30)
// ============================================================================

#include "bdhm_expr_clause_engine.h"
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

namespace {

// ============================================================================
// [EN] Internal String & JSON Helper Utilities
// [VN] Tiện ích Nội bộ Xử lý Chuỗi & JSON
// ============================================================================
std::string TrimWhitespace(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }
    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        --end;
    }
    return s.substr(start, end - start);
}

std::string EscapeJsonString(const std::string& s) {
    std::ostringstream oss;
    for (char c : s) {
        switch (c) {
            case '"':  oss << "\\\""; break;
            case '\\': oss << "\\\\"; break;
            case '\b': oss << "\\b";  break;
            case '\f': oss << "\\f";  break;
            case '\n': oss << "\\n";  break;
            case '\r': oss << "\\r";  break;
            case '\t': oss << "\\t";  break;
            default:
                if (static_cast<unsigned char>(c) < 0x20) {
                    oss << "\\u" << std::hex << std::setw(4) << std::setfill('0')
                        << static_cast<int>(static_cast<unsigned char>(c)) << std::dec;
                } else {
                    oss << c;
                }
                break;
        }
    }
    return oss.str();
}

std::string FormatNumberClean(double val) {
    if (std::isnan(val) || std::isinf(val)) {
        return "0";
    }
    double int_part = 0.0;
    if (std::modf(val, &int_part) == 0.0 &&
        val >= -9007199254740992.0 && val <= 9007199254740992.0) {
        return std::to_string(static_cast<int64_t>(int_part));
    }
    std::ostringstream oss;
    oss << std::setprecision(12) << val;
    return oss.str();
}

bool StartsWith(const std::string& str, const std::string& prefix) {
    return str.size() >= prefix.size() &&
           str.compare(0, prefix.size(), prefix) == 0;
}

} // anonymous namespace

// ============================================================================
// [EN] 1. PropValue & SparkTracingPerfStat Serialization (OBSERVED 0x00be01)
//      Uses exact prefixes from .rodata 0x00be01:
//        "__st_string;", "__st_number;", "__st_bool;"
//      And error message from 0x00bf78:
//        "Unknown key type `<raw>` from db"
// [VN] 1. Tuần tự hóa PropValue & SparkTracingPerfStat (QUAN SÁT 0x00be01)
// ============================================================================
std::string PropValue::EncodeToDbString() const {
    switch (kind) {
        case PropValueKind::kString:
            return std::string(kPrefixStString) + str_val;
        case PropValueKind::kNumber:
            return std::string(kPrefixStNumber) + FormatNumberClean(num_val);
        case PropValueKind::kBool:
            return std::string(kPrefixStBool) + (bool_val ? "true" : "false");
        case PropValueKind::kNull:
        default:
            return std::string(kPrefixStString);
    }
}

bool PropValue::DecodeFromDbString(const std::string& raw, PropValue* out_val, std::string* out_err) {
    if (!out_val) {
        return false;
    }
    if (StartsWith(raw, kPrefixStString)) {
        *out_val = PropValue::MakeString(raw.substr(std::strlen(kPrefixStString)));
        return true;
    }
    if (StartsWith(raw, kPrefixStNumber)) {
        std::string num_txt = TrimWhitespace(raw.substr(std::strlen(kPrefixStNumber)));
        char* end_ptr = nullptr;
        double parsed = std::strtod(num_txt.c_str(), &end_ptr);
        if (end_ptr == num_txt.c_str()) {
            if (out_err) {
                *out_err = "InvalidNumber, at: " + num_txt;
            }
            return false;
        }
        *out_val = PropValue::MakeNumber(parsed);
        return true;
    }
    if (StartsWith(raw, kPrefixStBool)) {
        std::string b_txt = TrimWhitespace(raw.substr(std::strlen(kPrefixStBool)));
        bool b_val = (b_txt == "true" || b_txt == "1");
        *out_val = PropValue::MakeBool(b_val);
        return true;
    }
    if (out_err) {
        *out_err = "Unknown key type `" + raw + "` from db";
    }
    return false;
}

std::string PropValue::ToPlainString() const {
    switch (kind) {
        case PropValueKind::kString:
            return str_val;
        case PropValueKind::kNumber:
            return FormatNumberClean(num_val);
        case PropValueKind::kBool:
            return bool_val ? "true" : "false";
        case PropValueKind::kNull:
        default:
            return "null";
    }
}

std::string PropValue::ToJsonLiteral() const {
    switch (kind) {
        case PropValueKind::kString:
            return "\"" + EscapeJsonString(str_val) + "\"";
        case PropValueKind::kNumber:
            return FormatNumberClean(num_val);
        case PropValueKind::kBool:
            return bool_val ? "true" : "false";
        case PropValueKind::kNull:
        default:
            return "null";
    }
}

std::string SparkTracingPerfStat::ToJson() const {
    // [EN] Matches .rodata 0x00d895..0x00d915 ("spark_tracing_stat" telemetry fields)
    // [VN] Khớp .rodata 0x00d895..0x00d915 (các trường đo lường "spark_tracing_stat")
    std::ostringstream oss;
    oss << "{"
        << "\"version\":\"" << EscapeJsonString(version) << "\","
        << "\"elapse_ms\":" << elapse_ms << ","
        << "\"prop_total\":" << prop_total << ","
        << "\"prop_valid\":" << prop_valid << ","
        << "\"prop_required_total\":" << prop_required_total << ","
        << "\"prop_required_valid\":" << prop_required_valid << ","
        << "\"char_size\":" << char_size
        << "}";
    return oss.str();
}

// ============================================================================
// [EN] 2. Expression Tokenizer & Recursive-Descent Interpreter
//      Reconstructed from bdhm_native/src/expr/tokenizer.rs,
//      bdhm_native/src/expr/interpreter.rs, and
//      bdhm_native/src/api/interpreter.rs (.rodata 0x00d620..0x00dc95).
// [VN] 2. Bộ Tách Từ & Thông Dịch Đệ Quy Biểu Thức Toán Học
// ============================================================================
double BdhmExprEngine::ComputeFactorial(double n) {
    // [EN] Matches "factorial" function in bdhm_native/src/expr/interpreter.rs (0x00dc58)
    // [VN] Khớp hàm "factorial" trong bdhm_native/src/expr/interpreter.rs (0x00dc58)
    if (n <= 1.0) {
        return 1.0;
    }
    int64_t limit = static_cast<int64_t>(std::floor(n));
    if (limit > 170) {
        limit = 170; // Avoid IEEE-754 double overflow
    }
    double acc = 1.0;
    for (int64_t i = 2; i <= limit; ++i) {
        acc *= static_cast<double>(i);
    }
    return acc;
}

bool BdhmExprEngine::Tokenize(
    const std::string& expr_str,
    std::vector<ExprToken>* out_tokens,
    std::string* out_error
) {
    if (!out_tokens) {
        return false;
    }
    out_tokens->clear();

    std::string trimmed = TrimWhitespace(expr_str);
    if (trimmed.empty()) {
        if (out_error) {
            *out_error = "Empty Clause"; // .rodata 0x00d630
        }
        return false;
    }

    size_t i = 0;
    const size_t n = expr_str.size();
    while (i < n) {
        unsigned char ch = static_cast<unsigned char>(expr_str[i]);
        if (std::isspace(ch)) {
            ++i;
            continue;
        }

        // Single-character punctuation & arithmetic operators
        if (ch == '+') {
            out_tokens->push_back({ExprTokenKind::kPlus, "+", 0.0, i});
            ++i;
            continue;
        }
        if (ch == '-') {
            out_tokens->push_back({ExprTokenKind::kMinus, "-", 0.0, i});
            ++i;
            continue;
        }
        if (ch == '*') {
            out_tokens->push_back({ExprTokenKind::kStar, "*", 0.0, i});
            ++i;
            continue;
        }
        if (ch == '/') {
            out_tokens->push_back({ExprTokenKind::kSlash, "/", 0.0, i});
            ++i;
            continue;
        }
        if (ch == '(') {
            out_tokens->push_back({ExprTokenKind::kLParen, "(", 0.0, i});
            ++i;
            continue;
        }
        if (ch == ')') {
            out_tokens->push_back({ExprTokenKind::kRParen, ")", 0.0, i});
            ++i;
            continue;
        }
        if (ch == ',') {
            out_tokens->push_back({ExprTokenKind::kComma, ",", 0.0, i});
            ++i;
            continue;
        }

        // Quoted string literal ('...' or "...")
        if (ch == '\'' || ch == '"') {
            char quote = static_cast<char>(ch);
            size_t start_pos = i;
            ++i;
            std::string content;
            bool closed = false;
            while (i < n) {
                if (expr_str[i] == '\\' && i + 1 < n) {
                    content.push_back(expr_str[i + 1]);
                    i += 2;
                    continue;
                }
                if (expr_str[i] == quote) {
                    closed = true;
                    ++i;
                    break;
                }
                content.push_back(expr_str[i]);
                ++i;
            }
            if (!closed) {
                if (out_error) {
                    *out_error = "Parse error, UnexpectedEOF, at: " + std::to_string(start_pos);
                }
                return false;
            }
            out_tokens->push_back({ExprTokenKind::kString, content, 0.0, start_pos});
            continue;
        }

        // Numeric literal
        if (std::isdigit(ch) || (ch == '.' && i + 1 < n && std::isdigit(static_cast<unsigned char>(expr_str[i + 1])))) {
            size_t start_pos = i;
            bool seen_dot = false;
            while (i < n) {
                unsigned char c = static_cast<unsigned char>(expr_str[i]);
                if (std::isdigit(c)) {
                    ++i;
                } else if (c == '.' && !seen_dot) {
                    seen_dot = true;
                    ++i;
                } else {
                    break;
                }
            }
            std::string num_lex = expr_str.substr(start_pos, i - start_pos);
            char* end_ptr = nullptr;
            double val = std::strtod(num_lex.c_str(), &end_ptr);
            if (end_ptr != num_lex.c_str() + num_lex.size()) {
                if (out_error) {
                    *out_error = "InvalidNumber, at: " + std::to_string(start_pos); // .rodata 0x00d654
                }
                return false;
            }
            out_tokens->push_back({ExprTokenKind::kNumber, num_lex, val, start_pos});
            continue;
        }

        // Identifier or variable symbol ($foo, bar_baz, page.load_ms)
        if (std::isalpha(ch) || ch == '_' || ch == '$') {
            size_t start_pos = i;
            ++i;
            while (i < n) {
                unsigned char c = static_cast<unsigned char>(expr_str[i]);
                if (std::isalnum(c) || c == '_' || c == '.' || c == '$' || c == ':') {
                    ++i;
                } else {
                    break;
                }
            }
            std::string ident = expr_str.substr(start_pos, i - start_pos);
            out_tokens->push_back({ExprTokenKind::kIdentifier, ident, 0.0, start_pos});
            continue;
        }

        if (out_error) {
            *out_error = "UnrecognizedChar, at: " + std::to_string(i); // .rodata 0x00d63c
        }
        return false;
    }

    out_tokens->push_back({ExprTokenKind::kEof, "", 0.0, n});
    return true;
}

namespace {

// ============================================================================
// [EN] Recursive-Descent Parser State for BdhmExprEngine::EvaluateExpression
//      Grammar:
//        Expr   := Term (( '+' | '-' ) Term)*
//        Term   := Factor (( '*' | '/' ) Factor)*
//        Factor := ('+' | '-') Factor | Primary
//        Primary:= NUMBER | STRING | IDENT '(' ArgList ')' | IDENT | '(' Expr ')'
// [VN] Trạng thái Phân tích Cú pháp Đệ quy cho BdhmExprEngine::EvaluateExpression
// ============================================================================
class ExprParser {
public:
    ExprParser(const std::vector<ExprToken>& tokens, const ContextVarResolver& resolver)
        : tokens_(tokens), resolver_(resolver), pos_(0) {}

    bool ParseFull(PropValue* out_val, std::string* out_err) {
        if (!ParseExpr(out_val, out_err)) {
            return false;
        }
        if (Current().kind != ExprTokenKind::kEof) {
            if (out_err) {
                *out_err = "Parse error, UnexpectedToken, at: " + std::to_string(Current().byte_pos);
            }
            return false;
        }
        return true;
    }

private:
    const ExprToken& Current() const {
        return tokens_[pos_ < tokens_.size() ? pos_ : tokens_.size() - 1];
    }

    void Advance() {
        if (pos_ + 1 < tokens_.size()) {
            ++pos_;
        }
    }

    bool ParseExpr(PropValue* out_val, std::string* out_err) {
        if (!ParseTerm(out_val, out_err)) {
            return false;
        }
        while (Current().kind == ExprTokenKind::kPlus || Current().kind == ExprTokenKind::kMinus) {
            ExprTokenKind op = Current().kind;
            Advance();
            PropValue rhs;
            if (!ParseTerm(&rhs, out_err)) {
                return false;
            }
            if (op == ExprTokenKind::kPlus &&
                (out_val->kind == PropValueKind::kString || rhs.kind == PropValueKind::kString)) {
                *out_val = PropValue::MakeString(out_val->ToPlainString() + rhs.ToPlainString());
            } else {
                if (out_val->kind != PropValueKind::kNumber || rhs.kind != PropValueKind::kNumber) {
                    if (out_err) {
                        *out_err = "Var is not a number: " + out_val->ToPlainString();
                    }
                    return false;
                }
                double res = (op == ExprTokenKind::kPlus)
                    ? (out_val->num_val + rhs.num_val)
                    : (out_val->num_val - rhs.num_val);
                *out_val = PropValue::MakeNumber(res);
            }
        }
        return true;
    }

    bool ParseTerm(PropValue* out_val, std::string* out_err) {
        if (!ParseFactor(out_val, out_err)) {
            return false;
        }
        while (Current().kind == ExprTokenKind::kStar || Current().kind == ExprTokenKind::kSlash) {
            ExprTokenKind op = Current().kind;
            Advance();
            PropValue rhs;
            if (!ParseFactor(&rhs, out_err)) {
                return false;
            }
            if (out_val->kind != PropValueKind::kNumber || rhs.kind != PropValueKind::kNumber) {
                if (out_err) {
                    *out_err = "Var is not a number: " + out_val->ToPlainString();
                }
                return false;
            }
            if (op == ExprTokenKind::kSlash) {
                if (std::abs(rhs.num_val) < 1e-15) {
                    if (out_err) {
                        *out_err = "attempt to divide by zero"; // .rodata 0x00f150
                    }
                    return false;
                }
                *out_val = PropValue::MakeNumber(out_val->num_val / rhs.num_val);
            } else {
                *out_val = PropValue::MakeNumber(out_val->num_val * rhs.num_val);
            }
        }
        return true;
    }

    bool ParseFactor(PropValue* out_val, std::string* out_err) {
        if (Current().kind == ExprTokenKind::kPlus) {
            Advance();
            return ParseFactor(out_val, out_err);
        }
        if (Current().kind == ExprTokenKind::kMinus) {
            Advance();
            PropValue inner;
            if (!ParseFactor(&inner, out_err)) {
                return false;
            }
            if (inner.kind != PropValueKind::kNumber) {
                if (out_err) {
                    *out_err = "Var is not a number: " + inner.ToPlainString();
                }
                return false;
            }
            *out_val = PropValue::MakeNumber(-inner.num_val);
            return true;
        }
        return ParsePrimary(out_val, out_err);
    }

    bool ParsePrimary(PropValue* out_val, std::string* out_err) {
        const ExprToken tok = Current();
        if (tok.kind == ExprTokenKind::kNumber) {
            Advance();
            *out_val = PropValue::MakeNumber(tok.num_val);
            return true;
        }
        if (tok.kind == ExprTokenKind::kString) {
            Advance();
            *out_val = PropValue::MakeString(tok.lexeme);
            return true;
        }
        if (tok.kind == ExprTokenKind::kLParen) {
            Advance();
            if (!ParseExpr(out_val, out_err)) {
                return false;
            }
            if (Current().kind != ExprTokenKind::kRParen) {
                if (out_err) {
                    *out_err = "Parse error, ExpectedClosingParen, at: " + std::to_string(Current().byte_pos);
                }
                return false;
            }
            Advance();
            return true;
        }
        if (tok.kind == ExprTokenKind::kIdentifier) {
            Advance();
            std::string name = tok.lexeme;
            if (name == "true") {
                *out_val = PropValue::MakeBool(true);
                return true;
            }
            if (name == "false") {
                *out_val = PropValue::MakeBool(false);
                return true;
            }
            if (name == "null") {
                *out_val = PropValue::MakeNull();
                return true;
            }

            // Check if function call: IDENT '(' ... ')'
            if (Current().kind == ExprTokenKind::kLParen) {
                Advance();
                std::vector<PropValue> args;
                if (Current().kind != ExprTokenKind::kRParen) {
                    while (true) {
                        PropValue arg_val;
                        if (!ParseExpr(&arg_val, out_err)) {
                            return false;
                        }
                        args.push_back(arg_val);
                        if (Current().kind == ExprTokenKind::kComma) {
                            Advance();
                            continue;
                        }
                        break;
                    }
                }
                if (Current().kind != ExprTokenKind::kRParen) {
                    if (out_err) {
                        *out_err = "Parse error, ExpectedClosingParen, at: " + std::to_string(Current().byte_pos);
                    }
                    return false;
                }
                Advance();

                if (name == "abs" || name == "factorial") {
                    if (args.empty()) {
                        if (out_err) {
                            *out_err = "Interpret error: TooFewArgs: " + name; // .rodata 0x00d74a
                        }
                        return false;
                    }
                    if (args.size() > 1) {
                        if (out_err) {
                            *out_err = "Interpret error: TooManyArgs: " + name; // .rodata 0x00d72c
                        }
                        return false;
                    }
                    if (args[0].kind != PropValueKind::kNumber) {
                        if (out_err) {
                            *out_err = "Cannot get a var but is not a number: " + name;
                        }
                        return false;
                    }
                    double v = (name == "abs")
                        ? std::abs(args[0].num_val)
                        : BdhmExprEngine::ComputeFactorial(args[0].num_val);
                    *out_val = PropValue::MakeNumber(v);
                    return true;
                }

                if (out_err) {
                    *out_err = "Interpret error: VarIsNotFunction: " + name; // .rodata 0x00d6e4
                }
                return false;
            }

            // Variable lookup: ensure function names aren't used like bare variables
            if (name == "abs" || name == "factorial") {
                if (out_err) {
                    *out_err = "Interpret error: FunctionNameUsedLikeVar: " + name; // .rodata 0x00d6b8
                }
                return false;
            }

            // Strip optional leading '$' when querying context repository
            std::string clean_key = (!name.empty() && name[0] == '$') ? name.substr(1) : name;
            PropValue resolved;
            if (resolver_ && (resolver_(clean_key, &resolved) || resolver_(name, &resolved))) {
                *out_val = resolved;
                return true;
            }
            if (out_err) {
                *out_err = "Interpret error: VarDoesNotExist: " + clean_key; // .rodata 0x00d709
            }
            return false;
        }

        if (out_err) {
            *out_err = "Parse error, UnexpectedToken, at: " + std::to_string(tok.byte_pos);
        }
        return false;
    }

    const std::vector<ExprToken>& tokens_;
    const ContextVarResolver& resolver_;
    size_t pos_;
};

} // anonymous namespace

bool BdhmExprEngine::EvaluateExpression(
    const std::string& expr_str,
    const ContextVarResolver& resolver,
    PropValue* out_result,
    std::string* out_error
) {
    if (!out_result) {
        return false;
    }
    std::vector<ExprToken> tokens;
    if (!Tokenize(expr_str, &tokens, out_error)) {
        return false;
    }
    ExprParser parser(tokens, resolver);
    return parser.ParseFull(out_result, out_error);
}

// ============================================================================
// [EN] 3. Clause Evaluator Implementation (bdhm_native/src/api/clause.rs)
//      Reconstructed from .rodata 0x00c980..0x00c9f0 and 0x00da00..0x00db60:
//        Operators: $eq, $neq, $lt, $lte, $gt, $gte, $in, $nin, $like,
//                   $not_like, $nil, $not_nil, $and, $or, $if, $then, $else
// [VN] 3. Triển khai Bộ Đánh giá Mệnh đề (bdhm_native/src/api/clause.rs)
// ============================================================================
bool BdhmClauseEvaluator::CompareValues(
    const std::string& op,
    const PropValue& lhs,
    const PropValue& rhs
) {
    if (op == "$nil") {
        return lhs.kind == PropValueKind::kNull;
    }
    if (op == "$not_nil") {
        return lhs.kind != PropValueKind::kNull;
    }
    if (op == "$eq" || op == "==" || op == "=") {
        if (lhs.kind == PropValueKind::kNumber && rhs.kind == PropValueKind::kNumber) {
            return std::abs(lhs.num_val - rhs.num_val) < 1e-9;
        }
        return lhs.ToPlainString() == rhs.ToPlainString();
    }
    if (op == "$neq" || op == "!=") {
        return !CompareValues("$eq", lhs, rhs);
    }
    if (op == "$lt" || op == "<") {
        if (lhs.kind == PropValueKind::kNumber && rhs.kind == PropValueKind::kNumber) {
            return lhs.num_val < rhs.num_val;
        }
        return lhs.ToPlainString() < rhs.ToPlainString();
    }
    if (op == "$lte" || op == "<=") {
        if (lhs.kind == PropValueKind::kNumber && rhs.kind == PropValueKind::kNumber) {
            return lhs.num_val <= rhs.num_val;
        }
        return lhs.ToPlainString() <= rhs.ToPlainString();
    }
    if (op == "$gt" || op == ">") {
        if (lhs.kind == PropValueKind::kNumber && rhs.kind == PropValueKind::kNumber) {
            return lhs.num_val > rhs.num_val;
        }
        return lhs.ToPlainString() > rhs.ToPlainString();
    }
    if (op == "$gte" || op == ">=") {
        if (lhs.kind == PropValueKind::kNumber && rhs.kind == PropValueKind::kNumber) {
            return lhs.num_val >= rhs.num_val;
        }
        return lhs.ToPlainString() >= rhs.ToPlainString();
    }
    if (op == "$like") {
        std::string haystack = lhs.ToPlainString();
        std::string needle   = rhs.ToPlainString();
        return haystack.find(needle) != std::string::npos;
    }
    if (op == "$not_like") {
        return !CompareValues("$like", lhs, rhs);
    }
    if (op == "$in" || op == "$nin") {
        std::string target = lhs.ToPlainString();
        std::string list_str = rhs.ToPlainString();
        bool found = false;
        std::istringstream iss(list_str);
        std::string item;
        while (std::getline(iss, item, ',')) {
            std::string cleaned = TrimWhitespace(item);
            if (!cleaned.empty() && (cleaned.front() == '"' || cleaned.front() == '\'')) {
                cleaned = cleaned.substr(1, cleaned.size() >= 2 ? cleaned.size() - 2 : 0);
            }
            if (cleaned == target) {
                found = true;
                break;
            }
        }
        return (op == "$in") ? found : !found;
    }
    return false;
}

bool BdhmClauseEvaluator::EvaluateCondition(
    const std::string& condition_expr,
    const ContextVarResolver& resolver,
    bool* out_matched,
    std::string* out_error
) {
    if (!out_matched) {
        return false;
    }
    std::string cond = TrimWhitespace(condition_expr);
    if (cond.empty() || cond == "true" || cond == "1") {
        *out_matched = true;
        return true;
    }
    if (cond == "false" || cond == "0") {
        *out_matched = false;
        return true;
    }

    // Handle logical combinators: "&&" / "$and" and "||" / "$or"
    size_t and_pos = cond.find("&&");
    if (and_pos != std::string::npos) {
        bool left_ok = false, right_ok = false;
        if (!EvaluateCondition(cond.substr(0, and_pos), resolver, &left_ok, out_error)) {
            return false;
        }
        if (!left_ok) {
            *out_matched = false;
            return true;
        }
        if (!EvaluateCondition(cond.substr(and_pos + 2), resolver, &right_ok, out_error)) {
            return false;
        }
        *out_matched = right_ok;
        return true;
    }

    size_t or_pos = cond.find("||");
    if (or_pos != std::string::npos) {
        bool left_ok = false, right_ok = false;
        if (!EvaluateCondition(cond.substr(0, or_pos), resolver, &left_ok, out_error)) {
            return false;
        }
        if (left_ok) {
            *out_matched = true;
            return true;
        }
        if (!EvaluateCondition(cond.substr(or_pos + 2), resolver, &right_ok, out_error)) {
            return false;
        }
        *out_matched = right_ok;
        return true;
    }

    // Check binary relational operators: >=, <=, !=, ==, >, <, =, or $gte/$lte/$neq/$eq/$gt/$lt/$like/$not_like/$in/$nin/$nil/$not_nil
    const char* kOps[] = {
        "$not_like", "$not_nil", "$like", "$lte", "$gte", "$neq", "$nin",
        "$nil", "$eq", "$lt", "$gt", "$in", ">=", "<=", "!=", "==", ">", "<", "="
    };
    for (const char* op_str : kOps) {
        size_t pos = cond.find(op_str);
        if (pos != std::string::npos) {
            std::string lhs_txt = TrimWhitespace(cond.substr(0, pos));
            std::string rhs_txt = TrimWhitespace(cond.substr(pos + std::strlen(op_str)));

            PropValue lhs_val = PropValue::MakeNull();
            std::string dummy_err;
            if (!BdhmExprEngine::EvaluateExpression(lhs_txt, resolver, &lhs_val, &dummy_err)) {
                lhs_val = PropValue::MakeNull();
            }

            if (std::strcmp(op_str, "$nil") == 0 || std::strcmp(op_str, "$not_nil") == 0) {
                *out_matched = CompareValues(op_str, lhs_val, PropValue::MakeNull());
                return true;
            }

            PropValue rhs_val = PropValue::MakeNull();
            if (!rhs_txt.empty()) {
                if (!BdhmExprEngine::EvaluateExpression(rhs_txt, resolver, &rhs_val, &dummy_err)) {
                    rhs_val = PropValue::MakeString(rhs_txt);
                }
            }
            *out_matched = CompareValues(op_str, lhs_val, rhs_val);
            return true;
        }
    }

    // Fallback: evaluate as arithmetic/boolean expression
    PropValue val;
    if (!BdhmExprEngine::EvaluateExpression(cond, resolver, &val, out_error)) {
        return false;
    }
    if (val.kind == PropValueKind::kBool) {
        *out_matched = val.bool_val;
    } else if (val.kind == PropValueKind::kNumber) {
        *out_matched = (std::abs(val.num_val) > 1e-12);
    } else if (val.kind == PropValueKind::kString) {
        *out_matched = !val.str_val.empty() && val.str_val != "false" && val.str_val != "0";
    } else {
        *out_matched = false;
    }
    return true;
}

bool BdhmClauseEvaluator::EvaluatePropertyClause(
    const std::string& clause_expr,
    const ContextVarResolver& resolver,
    PropValue* out_value,
    std::string* out_error
) {
    if (!out_value) {
        return false;
    }
    std::string expr = TrimWhitespace(clause_expr);
    if (expr.empty()) {
        if (out_error) {
            *out_error = "Invalid PropertyExpr"; // .rodata 0x00dac5
        }
        return false;
    }

    // Check inline conditional syntax: "$if(<cond>)$then(<expr>)$else(<expr>)"
    if (StartsWith(expr, "$if(")) {
        size_t then_pos = expr.find(")$then(");
        if (then_pos == std::string::npos) {
            if (out_error) {
                *out_error = "Invalid $then Clause"; // .rodata 0x00da60
            }
            return false;
        }
        std::string cond_part = expr.substr(4, then_pos - 4);
        size_t else_pos = expr.find(")$else(", then_pos + 7);
        std::string then_part;
        std::string else_part;
        if (else_pos != std::string::npos && expr.back() == ')') {
            then_part = expr.substr(then_pos + 7, else_pos - (then_pos + 7));
            else_part = expr.substr(else_pos + 7, expr.size() - (else_pos + 7) - 1);
        } else if (expr.back() == ')') {
            then_part = expr.substr(then_pos + 7, expr.size() - (then_pos + 7) - 1);
        } else {
            if (out_error) {
                *out_error = "Invalid $then Clause";
            }
            return false;
        }

        bool cond_ok = false;
        if (!EvaluateCondition(cond_part, resolver, &cond_ok, out_error)) {
            return false;
        }
        if (cond_ok) {
            return BdhmExprEngine::EvaluateExpression(then_part, resolver, out_value, out_error);
        }
        if (!else_part.empty()) {
            return BdhmExprEngine::EvaluateExpression(else_part, resolver, out_value, out_error);
        }
        *out_value = PropValue::MakeNull();
        return true;
    }

    return BdhmExprEngine::EvaluateExpression(expr, resolver, out_value, out_error);
}

// ============================================================================
// [EN] 4. Manifest & Properties JSON Parser (bdhm_native::api::manifest)
//      Reconstructed from do_setManifest (0x0429a0), do_setProperties (0x042df0),
//      and do_snapshot (0x04141c).
// [VN] 4. Bộ Phân tích JSON Manifest & Thuộc tính (bdhm_native::api::manifest)
// ============================================================================
namespace {

bool ExtractJsonStringField(const std::string& src, const std::string& key, std::string* out_val) {
    std::string pattern = "\"" + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < src.size() && std::isspace(static_cast<unsigned char>(src[pos]))) {
        ++pos;
    }
    if (pos >= src.size() || src[pos] != '"') {
        return false;
    }
    ++pos;
    std::string res;
    while (pos < src.size()) {
        if (src[pos] == '\\' && pos + 1 < src.size()) {
            res.push_back(src[pos + 1]);
            pos += 2;
            continue;
        }
        if (src[pos] == '"') {
            *out_val = res;
            return true;
        }
        res.push_back(src[pos]);
        ++pos;
    }
    return false;
}

bool ExtractJsonBoolField(const std::string& src, const std::string& key, bool* out_val) {
    std::string pattern = "\"" + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < src.size() && std::isspace(static_cast<unsigned char>(src[pos]))) {
        ++pos;
    }
    if (src.compare(pos, 4, "true") == 0) {
        *out_val = true;
        return true;
    }
    if (src.compare(pos, 5, "false") == 0) {
        *out_val = false;
        return true;
    }
    return false;
}

bool ExtractJsonNumberField(const std::string& src, const std::string& key, double* out_val) {
    std::string pattern = "\"" + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find(':', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < src.size() && std::isspace(static_cast<unsigned char>(src[pos]))) {
        ++pos;
    }
    char* end_ptr = nullptr;
    double v = std::strtod(src.c_str() + pos, &end_ptr);
    if (end_ptr == src.c_str() + pos) {
        return false;
    }
    *out_val = v;
    return true;
}

bool ExtractSubObject(const std::string& src, const std::string& key, std::string* out_obj) {
    std::string pattern = "\"" + key + "\"";
    size_t pos = src.find(pattern);
    if (pos == std::string::npos) {
        return false;
    }
    pos = src.find('{', pos + pattern.size());
    if (pos == std::string::npos) {
        return false;
    }
    int depth = 0;
    bool in_str = false;
    for (size_t i = pos; i < src.size(); ++i) {
        if (src[i] == '\\' && in_str) {
            ++i;
            continue;
        }
        if (src[i] == '"') {
            in_str = !in_str;
            continue;
        }
        if (!in_str) {
            if (src[i] == '{') {
                ++depth;
            } else if (src[i] == '}') {
                --depth;
                if (depth == 0) {
                    *out_obj = src.substr(pos, i - pos + 1);
                    return true;
                }
            }
        }
    }
    return false;
}

} // anonymous namespace

bool BdhmManifestParser::ParsePropertiesJson(
    const std::string& json_str,
    std::unordered_map<std::string, PropValue>* out_props,
    std::string* out_error
) {
    if (!out_props) {
        return false;
    }
    out_props->clear();
    std::string trimmed = TrimWhitespace(json_str);
    if (trimmed.size() < 2 || trimmed.front() != '{' || trimmed.back() != '}') {
        if (out_error) {
            *out_error = "Parse error, ExpectedValue, at: 0";
        }
        return false;
    }

    size_t i = 1;
    const size_t n = trimmed.size() - 1;
    while (i < n) {
        while (i < n && (std::isspace(static_cast<unsigned char>(trimmed[i])) || trimmed[i] == ',')) {
            ++i;
        }
        if (i >= n) {
            break;
        }
        if (trimmed[i] != '"') {
            if (out_error) {
                *out_error = "Parse error, UnexpectedToken, at: " + std::to_string(i);
            }
            return false;
        }
        // Parse key
        ++i;
        std::string key;
        while (i < n && trimmed[i] != '"') {
            if (trimmed[i] == '\\' && i + 1 < n) {
                key.push_back(trimmed[i + 1]);
                i += 2;
            } else {
                key.push_back(trimmed[i]);
                ++i;
            }
        }
        if (i >= n || trimmed[i] != '"') {
            if (out_error) {
                *out_error = "Parse error, UnexpectedEOF, at: " + std::to_string(i);
            }
            return false;
        }
        ++i; // skip closing quote
        while (i < n && std::isspace(static_cast<unsigned char>(trimmed[i]))) {
            ++i;
        }
        if (i >= n || trimmed[i] != ':') {
            if (out_error) {
                *out_error = "Parse error, ExpectedValue, at: " + std::to_string(i);
            }
            return false;
        }
        ++i;
        while (i < n && std::isspace(static_cast<unsigned char>(trimmed[i]))) {
            ++i;
        }
        if (i >= n) {
            if (out_error) {
                *out_error = "Parse error, UnexpectedEOF, at: " + std::to_string(i);
            }
            return false;
        }

        // Parse value
        if (trimmed[i] == '"') {
            ++i;
            std::string sval;
            while (i < n && trimmed[i] != '"') {
                if (trimmed[i] == '\\' && i + 1 < n) {
                    sval.push_back(trimmed[i + 1]);
                    i += 2;
                } else {
                    sval.push_back(trimmed[i]);
                    ++i;
                }
            }
            if (i < n && trimmed[i] == '"') {
                ++i;
            }
            (*out_props)[key] = PropValue::MakeString(sval);
        } else if (trimmed.compare(i, 4, "true") == 0) {
            (*out_props)[key] = PropValue::MakeBool(true);
            i += 4;
        } else if (trimmed.compare(i, 5, "false") == 0) {
            (*out_props)[key] = PropValue::MakeBool(false);
            i += 5;
        } else if (trimmed.compare(i, 4, "null") == 0) {
            (*out_props)[key] = PropValue::MakeNull();
            i += 4;
        } else {
            char* end_ptr = nullptr;
            double dval = std::strtod(trimmed.c_str() + i, &end_ptr);
            if (end_ptr == trimmed.c_str() + i) {
                if (out_error) {
                    *out_error = "InvalidNumber, at: " + std::to_string(i);
                }
                return false;
            }
            (*out_props)[key] = PropValue::MakeNumber(dval);
            i = static_cast<size_t>(end_ptr - trimmed.c_str());
        }
    }
    return true;
}

bool BdhmManifestParser::ParseManifestJson(
    const std::string& json_str,
    DeclaredManifest* out_manifest,
    std::string* out_error
) {
    if (!out_manifest) {
        return false;
    }
    std::string trimmed = TrimWhitespace(json_str);
    if (trimmed.size() < 2 || trimmed.front() != '{' || trimmed.back() != '}') {
        if (out_error) {
            *out_error = "Failed to parse manifest: invalid JSON root"; // .rodata 0x00d97a
        }
        return false;
    }

    DeclaredManifest manifest;
    ExtractJsonStringField(trimmed, "version", &manifest.version);
    ExtractJsonBoolField(trimmed, "enabled", &manifest.enabled);

    // Extract extra_mappings if present
    std::string extra_obj;
    if (ExtractSubObject(trimmed, "extra_mappings", &extra_obj)) {
        std::unordered_map<std::string, PropValue> kv;
        if (ParsePropertiesJson(extra_obj, &kv, nullptr)) {
            for (const auto& pair : kv) {
                manifest.extra_mappings[pair.first] = pair.second.ToPlainString();
            }
        }
    }

    // Extract events map
    std::string events_obj;
    if (ExtractSubObject(trimmed, "events", &events_obj)) {
        size_t pos = 1;
        while (pos < events_obj.size()) {
            size_t q1 = events_obj.find('"', pos);
            if (q1 == std::string::npos) {
                break;
            }
            size_t q2 = events_obj.find('"', q1 + 1);
            if (q2 == std::string::npos) {
                break;
            }
            std::string ev_name = events_obj.substr(q1 + 1, q2 - q1 - 1);
            std::string ev_body;
            if (!ExtractSubObject(events_obj.substr(q1), ev_name, &ev_body)) {
                break;
            }

            DeclaredEvent decl_ev;
            decl_ev.name = ev_name;
            ExtractJsonStringField(ev_body, "target", &decl_ev.target);
            ExtractJsonBoolField(ev_body, "perf_stat", &decl_ev.perf_stat);
            ExtractJsonBoolField(ev_body, "ignore_null", &decl_ev.ignore_null);
            ExtractJsonNumberField(ev_body, "sampling", &decl_ev.sampling);

            std::string props_obj;
            if (ExtractSubObject(ev_body, "props", &props_obj)) {
                std::unordered_map<std::string, PropValue> p_kv;
                if (ParsePropertiesJson(props_obj, &p_kv, nullptr)) {
                    for (const auto& pair : p_kv) {
                        decl_ev.props_exprs[pair.first] = pair.second.ToPlainString();
                    }
                }
            }

            std::string def_obj;
            if (ExtractSubObject(ev_body, "default", &def_obj)) {
                std::unordered_map<std::string, PropValue> d_kv;
                if (ParsePropertiesJson(def_obj, &d_kv, nullptr)) {
                    for (const auto& pair : d_kv) {
                        decl_ev.default_props[pair.first] = pair.second.ToPlainString();
                    }
                }
            }

            std::string beh_obj;
            if (ExtractSubObject(ev_body, "behavior", &beh_obj)) {
                ExtractJsonStringField(beh_obj, "when", &decl_ev.behavior.when_clause);
                ExtractJsonStringField(beh_obj, "sequence", &decl_ev.behavior.sequence_clause);
                ExtractJsonNumberField(beh_obj, "sampling", &decl_ev.behavior.sampling_rate);
                ExtractJsonBoolField(beh_obj, "is_alive", &decl_ev.behavior.require_alive);
            }

            manifest.events[ev_name] = std::move(decl_ev);
            size_t sub_pos = events_obj.find(ev_body, q2);
            if (sub_pos == std::string::npos) {
                break;
            }
            pos = sub_pos + ev_body.size();
        }
    }

    *out_manifest = std::move(manifest);
    return true;
}

std::string BdhmManifestParser::SerializeManifestToJson(const DeclaredManifest& manifest) {
    std::ostringstream oss;
    oss << "{"
        << "\"version\":\"" << EscapeJsonString(manifest.version) << "\","
        << "\"enabled\":" << (manifest.enabled ? "true" : "false") << ","
        << "\"events\":{";

    bool first_ev = true;
    for (const auto& ev_pair : manifest.events) {
        if (!first_ev) {
            oss << ",";
        }
        first_ev = false;
        const DeclaredEvent& ev = ev_pair.second;
        oss << "\"" << EscapeJsonString(ev.name) << "\":{"
            << "\"target\":\"" << EscapeJsonString(ev.target) << "\","
            << "\"perf_stat\":" << (ev.perf_stat ? "true" : "false") << ","
            << "\"ignore_null\":" << (ev.ignore_null ? "true" : "false") << ","
            << "\"sampling\":" << FormatNumberClean(ev.sampling) << ","
            << "\"props\":{";
        bool first_p = true;
        for (const auto& p : ev.props_exprs) {
            if (!first_p) {
                oss << ",";
            }
            first_p = false;
            oss << "\"" << EscapeJsonString(p.first) << "\":\"" << EscapeJsonString(p.second) << "\"";
        }
        oss << "}}";
    }
    oss << "},\"extra_mappings\":{";
    bool first_m = true;
    for (const auto& m : manifest.extra_mappings) {
        if (!first_m) {
            oss << ",";
        }
        first_m = false;
        oss << "\"" << EscapeJsonString(m.first) << "\":\"" << EscapeJsonString(m.second) << "\"";
    }
    oss << "}}";
    return oss.str();
}

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
