// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Decision Tree Architecture
// Kiến trúc Cây Quyết Định (Tree Structure & Traversal Algorithm)
//
// ABI Parity:
//   - sizeof(Tree) == 56 bytes
//   - In vector indexing: modular arithmetic inverse 0x6db6db6db6db6db7 (inv of 7)
//   - (size_bytes / 8) * inv(7) == count of 56-byte Tree instances!
// ======================================================================

#pragma once

#include "bytedt_node.h"
#include <vector>
#include <memory>
#include <cstdint>

namespace bytedt {

/**
 * @brief Individual Decision Tree in an ensemble.
 * Cấu trúc đại diện cho một cây quyết định đơn lẻ trong mô hình ensemble.
 *
 * ABI Memory Layout (Total = 56 bytes exactly):
 *   [0x00 - 0x0f] root_: std::shared_ptr<Node> (16 bytes)
 *   [0x10 - 0x13] num_leaves_: int32_t (4 bytes)
 *   [0x14 - 0x17] max_depth_: int32_t (4 bytes)
 *   [0x18 - 0x1b] tree_id_: int32_t (4 bytes)
 *   [0x1c - 0x1f] num_nodes_: int32_t (4 bytes)
 *   [0x20 - 0x37] leaf_indices_: std::vector<int32_t> (24 bytes: 3 pointers in libc++)
 *   Sum = 16 + 4 + 4 + 4 + 4 + 24 = 56 bytes.
 */
class Tree {
private:
    std::shared_ptr<Node> root_;
    int32_t num_leaves_;
    int32_t max_depth_;
    int32_t tree_id_;
    int32_t num_nodes_;
    std::vector<int32_t> leaf_indices_;

public:
    Tree(int32_t id = 0)
        : root_(nullptr), num_leaves_(0), max_depth_(0),
          tree_id_(id), num_nodes_(0) {}

    void set_root(std::shared_ptr<Node> root) {
        root_ = root;
    }

    std::shared_ptr<Node> get_root() const {
        return root_;
    }

    void set_num_leaves(int32_t count) { num_leaves_ = count; }
    int32_t get_num_leaves() const { return num_leaves_; }

    void set_max_depth(int32_t depth) { max_depth_ = depth; }
    int32_t get_max_depth() const { return max_depth_; }

    void set_tree_id(int32_t id) { tree_id_ = id; }
    int32_t get_tree_id() const { return tree_id_; }

    void set_num_nodes(int32_t count) { num_nodes_ = count; }
    int32_t get_num_nodes() const { return num_nodes_; }

    void add_leaf_index(int32_t idx) { leaf_indices_.push_back(idx); }
    const std::vector<int32_t>& get_leaf_indices() const { return leaf_indices_; }

    /**
     * @brief Tree traversal from root to leaf node.
     * Thuật toán duyệt cây quyết định từ nút gốc đến nút lá.
     * 
     * Traversal Logic:
     *   Bắt đầu từ nút gốc root_.
     *   Tại mỗi nút điều kiện (NonLeafNode), gọi evaluate(features, count).
     *   Nếu đúng: đi sang left_child_.
     *   Nếu sai: đi sang right_child_.
     *   Lặp lại cho đến khi gặp LeafNode.
     */
    const LeafNode* traverse(const float* features, size_t count) const {
        if (!root_) {
            return nullptr;
        }

        const Node* curr = root_.get();
        while (curr && !curr->is_leaf()) {
            const NonLeafNode* non_leaf = static_cast<const NonLeafNode*>(curr);
            bool take_left = non_leaf->evaluate(features, count);
            curr = take_left ? non_leaf->get_left().get() : non_leaf->get_right().get();
        }

        if (curr && curr->is_leaf()) {
            return static_cast<const LeafNode*>(curr);
        }
        return nullptr;
    }

    /**
     * @brief Evaluates tree and returns predictive leaf value.
     * Đánh giá cây và trả về giá trị dự đoán tại nút lá.
     */
    float predict(const float* features, size_t count) const {
        const LeafNode* leaf = traverse(features, count);
        return leaf ? leaf->get_leaf_value() : 0.0f;
    }

    /**
     * @brief Evaluates tree and returns leaf index.
     * Đánh giá cây và trả về chỉ số của nút lá (phục vụ trích xuất đặc trưng leaf index).
     */
    int32_t predict_leaf(const float* features, size_t count) const {
        const LeafNode* leaf = traverse(features, count);
        return leaf ? leaf->get_leaf_index() : -1;
    }
};

static_assert(sizeof(Tree) == 56, "ABI Validation: sizeof(Tree) must be exactly 56 bytes to match AArch64 modular multiplication!");

} // namespace bytedt
