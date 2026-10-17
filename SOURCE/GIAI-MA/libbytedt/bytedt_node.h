// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Node Architecture
// Kiến trúc Node cây quyết định (Leaf, Numerical, Categorical Nodes)
//
// Matches AArch64 Opcode Layout:
//   - Feature index at offset [x0, #0x34]
//   - Threshold at offset [x19, #0x38]
//   - Default direction (NaN fallback) at [x19, #0x30]
//   - Floating point compare: fcmp s0, s0 (NaN check) + fcmp s1, s0
//   - Condition flags: cset eq, gt, ge, mi, ls
// ======================================================================

#pragma once

#include "bytedt_types.h"
#include <stdexcept>
#include <unordered_set>

namespace bytedt {

class LeafNode;
class NonLeafNode;
class NumericalNode;
class CategoricalNode;

/**
 * @brief Base abstract node in a decision tree.
 * Lớp trừu tượng cơ sở cho nút trong cây quyết định.
 */
class Node {
protected:
    int32_t node_id_;

public:
    Node(int32_t id = 0) : node_id_(id) {}
    virtual ~Node() = default;

    int32_t get_node_id() const { return node_id_; }

    virtual bool is_leaf() const = 0;
    virtual bool evaluate(const float* features, size_t count) const = 0;
    virtual float get_leaf_value() const { return 0.0f; }
    virtual int32_t get_leaf_index() const { return -1; }

    virtual std::shared_ptr<Node> get_left() const { return nullptr; }
    virtual std::shared_ptr<Node> get_right() const { return nullptr; }

    // Safe dynamic cast assertion helpers matching internal library error strings
    // Các phương thức ép kiểu an toàn khớp chính xác chuỗi báo lỗi trong binary
    LeafNode* as_leaf();
    const LeafNode* as_leaf() const;
    NonLeafNode* as_non_leaf();
    const NonLeafNode* as_non_leaf() const;
    NumericalNode* as_numerical();
    const NumericalNode* as_numerical() const;
    CategoricalNode* as_categorical();
    const CategoricalNode* as_categorical() const;
};

/**
 * @brief Leaf node containing predictive weight/score and leaf index.
 * Nút lá chứa giá trị dự đoán (trọng số hồi quy/xác suất) và chỉ số lá.
 */
class LeafNode : public Node {
private:
    float leaf_value_;
    int32_t leaf_index_;

public:
    LeafNode(int32_t id, float value, int32_t leaf_idx = 0)
        : Node(id), leaf_value_(value), leaf_index_(leaf_idx) {}

    bool is_leaf() const override { return true; }
    float get_leaf_value() const override { return leaf_value_; }
    int32_t get_leaf_index() const override { return leaf_index_; }

    bool evaluate(const float* /*features*/, size_t /*count*/) const override {
        return true;
    }
};

/**
 * @brief Non-leaf split decision node.
 * Nút điều kiện phân nhánh trong cây (chứa nhánh trái, nhánh phải và đặc trưng).
 */
class NonLeafNode : public Node {
protected:
    std::shared_ptr<Node> left_child_;
    std::shared_ptr<Node> right_child_;
    int32_t feature_index_;     ///< Offset 0x34 in AArch64 ABI
    bool default_direction_;    ///< Offset 0x30 in AArch64 ABI (true = left, false = right)

public:
    NonLeafNode(int32_t id, int32_t feat_idx, bool default_dir = true)
        : Node(id), feature_index_(feat_idx), default_direction_(default_dir) {}

    bool is_leaf() const override { return false; }

    int32_t get_feature_index() const { return feature_index_; }
    bool get_default_direction() const { return default_direction_; }

    void set_children(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
        left_child_ = left;
        right_child_ = right;
    }

    std::shared_ptr<Node> get_left() const override { return left_child_; }
    std::shared_ptr<Node> get_right() const override { return right_child_; }

    /**
     * @brief Next child selector during tree traversal.
     * Chọn nhánh con tiếp theo khi duyệt cây theo kết quả điều kiện.
     */
    std::shared_ptr<Node> next(const float* features, size_t count) const {
        return evaluate(features, count) ? left_child_ : right_child_;
    }
};

/**
 * @brief Numerical split node with IEEE-754 NaN handling.
 * Nút phân nhánh giá trị số học kèm xử lý ngoại lệ NaN theo chuẩn IEEE-754.
 */
class NumericalNode : public NonLeafNode {
private:
    float threshold_;           ///< Offset 0x38 in AArch64 ABI
    CompareOp op_;              ///< Split operator enum

public:
    NumericalNode(int32_t id, int32_t feat_idx, float thresh, CompareOp op, bool default_dir = true)
        : NonLeafNode(id, feat_idx, default_dir), threshold_(thresh), op_(op) {}

    float get_threshold() const { return threshold_; }
    CompareOp get_operator() const { return op_; }

    /**
     * @brief Evaluates numerical split condition matching AArch64 disassembly.
     * Đánh giá điều kiện so sánh số học khớp các khối lệnh assembly AArch64 thực tế:
     * 
     * Opcode Sequence:
     *   0x0082f4: bl   #0x7f78       // Lấy giá trị đặc trưng feature_val
     *   0x0082f8: fmov s0, w0
     *   0x0082fc: fcmp s0, s0        // Kiểm tra NaN
     *   0x008300: b.vs #0x8314       // Nhảy sang xử lý default_direction_ nếu là NaN
     *   0x008304: ldr  s1, [x19, #0x38] // Nạp threshold_
     *   0x008308: fcmp s1, s0
     *   0x00830c: cset w0, ge / mi / eq / gt / ls
     */
    bool evaluate(const float* features, size_t count) const override {
        if (!features || static_cast<size_t>(feature_index_) >= count) {
            return default_direction_;
        }

        float val = features[feature_index_];

        // IEEE-754 NaN Check (fcmp s0, s0; b.vs)
        // Kiểm tra NaN: nếu thiếu dữ liệu, rẽ theo hướng mặc định (default_direction_)
        if (std::isnan(val)) {
            return default_direction_;
        }

        switch (op_) {
            case CompareOp::OP_EQUAL:
                return (val == threshold_);
            case CompareOp::OP_LESS_THAN:
                return (val < threshold_);
            case CompareOp::OP_LESS_EQUAL:
                return (val <= threshold_);
            case CompareOp::OP_GREATER_THAN:
                return (val > threshold_);
            case CompareOp::OP_GREATER_EQUAL:
                return (val >= threshold_);
            default:
                return (val <= threshold_);
        }
    }
};

/**
 * @brief Categorical split node.
 * Nút phân nhánh biến phân loại (tập danh mục/one-hot encoding).
 */
class CategoricalNode : public NonLeafNode {
private:
    std::unordered_set<int32_t> category_set_;

public:
    CategoricalNode(int32_t id, int32_t feat_idx, const std::vector<int32_t>& categories, bool default_dir = true)
        : NonLeafNode(id, feat_idx, default_dir),
          category_set_(categories.begin(), categories.end()) {}

    const std::unordered_set<int32_t>& get_categories() const { return category_set_; }

    bool evaluate(const float* features, size_t count) const override {
        if (!features || static_cast<size_t>(feature_index_) >= count) {
            return default_direction_;
        }

        float val = features[feature_index_];
        if (std::isnan(val)) {
            return default_direction_;
        }

        int32_t cat_int = static_cast<int32_t>(val);
        return category_set_.find(cat_int) != category_set_.end();
    }
};

// Implementation of type cast assertions
inline LeafNode* Node::as_leaf() {
    if (!is_leaf()) {
        throw std::runtime_error("Non-leaf node cannot be cast to Leaf node.");
    }
    return static_cast<LeafNode*>(this);
}

inline const LeafNode* Node::as_leaf() const {
    if (!is_leaf()) {
        throw std::runtime_error("Non-leaf node cannot be cast to Leaf node.");
    }
    return static_cast<const LeafNode*>(this);
}

inline NonLeafNode* Node::as_non_leaf() {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Non-Leaf node.");
    }
    return static_cast<NonLeafNode*>(this);
}

inline const NonLeafNode* Node::as_non_leaf() const {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Non-Leaf node.");
    }
    return static_cast<const NonLeafNode*>(this);
}

inline NumericalNode* Node::as_numerical() {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Numerical Node.");
    }
    auto num = dynamic_cast<NumericalNode*>(this);
    if (!num) {
        throw std::runtime_error("Node is not a Numerical Node.");
    }
    return num;
}

inline const NumericalNode* Node::as_numerical() const {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Numerical Node.");
    }
    auto num = dynamic_cast<const NumericalNode*>(this);
    if (!num) {
        throw std::runtime_error("Node is not a Numerical Node.");
    }
    return num;
}

inline CategoricalNode* Node::as_categorical() {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Categorical Node.");
    }
    auto cat = dynamic_cast<CategoricalNode*>(this);
    if (!cat) {
        throw std::runtime_error("Node is not a Categorical Node.");
    }
    return cat;
}

inline const CategoricalNode* Node::as_categorical() const {
    if (is_leaf()) {
        throw std::runtime_error("Leaf node cannot be cast to Categorical Node.");
    }
    auto cat = dynamic_cast<const CategoricalNode*>(this);
    if (!cat) {
        throw std::runtime_error("Node is not a Categorical Node.");
    }
    return cat;
}

} // namespace bytedt
