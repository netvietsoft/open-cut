// ============================================================================
// File: bdhm_expr_clause_engine.h
// Module: libbdhm_native.so — Expression Tokenizer, Interpreter & Clause DSL
//         (Bộ Phân tích Từ vựng, Thông dịch Biểu thức Toán học & Mệnh đề DSL)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from bdhm_native/src/expr/tokenizer.rs,
//               bdhm_native/src/expr/interpreter.rs,
//               bdhm_native/src/api/interpreter.rs,
//               bdhm_native/src/api/clause.rs, and
//               bdhm_native/src/api/manifest.rs (.rodata 0x00d600..0x00de30)
// ============================================================================

#pragma once

#include "bdhm_types.h"
#include <functional>
#include <string>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

// ============================================================================
// [EN] 1. Token Types for bdhm_native/src/expr/tokenizer.rs (OBSERVED)
//      Reconstructed from .rodata 0x00dc58..0x00dc95 and 0x00d620..0x00d760.
// [VN] 1. Các loại Token của bdhm_native/src/expr/tokenizer.rs (QUAN SÁT)
// ============================================================================
enum class ExprTokenKind : uint8_t {
    kNumber     = 0,
    kString     = 1,
    kIdentifier = 2,
    kPlus       = 3,
    kMinus      = 4,
    kStar       = 5,
    kSlash      = 6,
    kLParen     = 7,
    kRParen     = 8,
    kComma      = 9,
    kEof        = 10
};

struct ExprToken {
    ExprTokenKind kind     = ExprTokenKind::kEof;
    std::string   lexeme;
    double        num_val  = 0.0;
    size_t        byte_pos = 0U;
};

// Context lookup functor: resolves a variable key in a context chain
using ContextVarResolver = std::function<bool(const std::string& key, PropValue* out_val)>;

// ============================================================================
// [EN] 2. Expression Tokenizer & Interpreter (bdhm_native::expr & api::interpreter)
//      Supports:
//        - Arithmetic operators: +, -, *, /, unary -, parentheses ()
//        - Built-in math functions: abs(x), factorial(n) (.rodata 0x00dc58, 0x00dc80)
//        - String interpolation & variable lookup via ContextVarResolver
//        - Exact error diagnostics matching .rodata 0x00d620..0x00d7b8
// [VN] 2. Bộ Tách Từ & Thông Dịch Biểu Thức (bdhm_native::expr & api::interpreter)
// ============================================================================
class BdhmExprEngine {
public:
    // [EN] Tokenize an expression string into a vector of ExprToken
    // [VN] Tách chuỗi biểu thức thành danh sách ExprToken
    static bool Tokenize(
        const std::string& expr_str,
        std::vector<ExprToken>* out_tokens,
        std::string* out_error
    );

    // [EN] Evaluate an expression (do_computeExpr at 0x043dd4 -> 0x04c6e4)
    // [VN] Tính giá trị biểu thức (do_computeExpr tại 0x043dd4 -> 0x04c6e4)
    static bool EvaluateExpression(
        const std::string& expr_str,
        const ContextVarResolver& resolver,
        PropValue* out_result,
        std::string* out_error
    );

    // [EN] Compute integer/floating factorial (0x00dc58: "factorial")
    // [VN] Tính giai thừa (0x00dc58: "factorial")
    static double ComputeFactorial(double n);
};

// ============================================================================
// [EN] 3. Conditional & Query Clause Evaluator (bdhm_native::api::clause)
//      Reconstructed from .rodata 0x00c980..0x00c9f0 and 0x00da00..0x00db60:
//        - Branching clauses: $if, $then, $else, $case, $when
//        - Comparison operators: $eq, $neq, $lt, $lte, $gt, $gte
//        - Set/Pattern operators: $in, $nin, $like, $not_like, $nil, $not_nil
//        - Logical combinators: $and, $or
// [VN] 3. Bộ Đánh giá Mệnh đề Điều kiện & Truy vấn (bdhm_native::api::clause)
// ============================================================================
class BdhmClauseEvaluator {
public:
    // [EN] Evaluate a condition clause (JSON or inline comparison) to boolean
    // [VN] Đánh giá mệnh đề điều kiện sang giá trị boolean
    static bool EvaluateCondition(
        const std::string& condition_expr,
        const ContextVarResolver& resolver,
        bool* out_matched,
        std::string* out_error
    );

    // [EN] Evaluate a property expression clause ($if/$then/$else or $case/$when)
    // [VN] Đánh giá mệnh đề biểu thức thuộc tính ($if/$then/$else hoặc $case/$when)
    static bool EvaluatePropertyClause(
        const std::string& clause_expr,
        const ContextVarResolver& resolver,
        PropValue* out_value,
        std::string* out_error
    );

    // [EN] Compare two PropValues with a specified operator ($eq, $neq, $lt, $lte, $gt, $gte, $like, $not_like)
    // [VN] So sánh hai PropValue theo toán tử chỉ định
    static bool CompareValues(
        const std::string& op,
        const PropValue& lhs,
        const PropValue& rhs
    );
};

// ============================================================================
// [EN] 4. Manifest & Event JSON Parser (bdhm_native::api::manifest)
//      Reconstructed from do_setManifest (0x0429a0 -> 0x048b14 -> 0x0488ec)
//      and do_compute (0x043f78 -> 0x048b14 -> 0x047ea0).
// [VN] 4. Bộ Phân tích JSON Manifest & Sự kiện (bdhm_native::api::manifest)
// ============================================================================
class BdhmManifestParser {
public:
    // [EN] Parse a full DeclaredManifest from JSON string
    // [VN] Phân tích toàn bộ DeclaredManifest từ chuỗi JSON
    static bool ParseManifestJson(
        const std::string& json_str,
        DeclaredManifest* out_manifest,
        std::string* out_error
    );

    // [EN] Serialize a DeclaredManifest back into canonical JSON for do_snapshot (0x04141c)
    // [VN] Tuần tự hóa DeclaredManifest sang JSON chuẩn cho do_snapshot (0x04141c)
    static std::string SerializeManifestToJson(const DeclaredManifest& manifest);

    // [EN] Parse a key-value JSON object into a map of PropValues (for do_setProperties 0x042df0)
    // [VN] Phân tích đối tượng JSON key-value thành bảng PropValue (cho do_setProperties 0x042df0)
    static bool ParsePropertiesJson(
        const std::string& json_str,
        std::unordered_map<std::string, PropValue>* out_props,
        std::string* out_error
    );
};

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
