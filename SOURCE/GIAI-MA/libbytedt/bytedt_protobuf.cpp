// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Protobuf Model Serializer (Implementation)
// Triển khai bộ giải mã và mã hóa Protobuf cho mô hình ByteDT
// ======================================================================

#include "bytedt_protobuf.h"
#include <map>
#include <iostream>

namespace bytedt {
namespace protobuf {

std::shared_ptr<BaseModel> ModelParser::parse_from_path(const char* filepath) {
    if (!filepath) {
        return nullptr;
    }
    std::ifstream file(filepath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        return nullptr;
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(static_cast<size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        return nullptr;
    }

    return parse_from_buffer(buffer.data(), buffer.size());
}

std::shared_ptr<BaseModel> ModelParser::parse_from_buffer(const void* data, size_t size) {
    if (!data || size == 0) {
        return nullptr;
    }

    CodedInputStream stream(data, size);

    ModelType model_type = ModelType::UNKNOWN;
    TreeRelation tree_relation = TreeRelation::UNKNOWN;
    int32_t n_feature = 0;
    float base_score = 0.0f;
    int32_t num_group = 1;
    int32_t num_class = 1;
    std::vector<Tree> parsed_trees;

    while (stream.has_more()) {
        uint32_t field_num = 0;
        WireType wire_type = VARINT;
        if (!stream.read_tag(&field_num, &wire_type)) break;

        switch (field_num) {
            case 1: { // model_type (varint)
                uint64_t val = 0;
                if (stream.read_varint64(&val)) {
                    model_type = static_cast<ModelType>(val);
                }
                break;
            }
            case 2: { // tree_relation (varint)
                uint64_t val = 0;
                if (stream.read_varint64(&val)) {
                    tree_relation = static_cast<TreeRelation>(val);
                }
                break;
            }
            case 3: { // n_feature (varint)
                uint64_t val = 0;
                if (stream.read_varint64(&val)) {
                    n_feature = static_cast<int32_t>(val);
                }
                break;
            }
            case 4: { // trees (repeated length-delimited Tree)
                uint64_t tree_len = 0;
                if (stream.read_varint64(&tree_len)) {
                    Tree t = parse_tree(stream, static_cast<size_t>(tree_len));
                    parsed_trees.push_back(std::move(t));
                }
                break;
            }
            case 5: { // base_score (float 32-bit fixed)
                stream.read_float(&base_score);
                break;
            }
            case 6: { // Config submessage (num_group / num_class)
                uint64_t cfg_len = 0;
                if (stream.read_varint64(&cfg_len)) {
                    size_t target_pos = stream.current_position() + static_cast<size_t>(cfg_len);
                    while (stream.current_position() < target_pos) {
                        uint32_t sub_tag = 0;
                        WireType sub_wire = VARINT;
                        if (!stream.read_tag(&sub_tag, &sub_wire)) break;
                        if (sub_tag == 1) { // num_group
                            uint64_t g = 0;
                            stream.read_varint64(&g);
                            num_group = static_cast<int32_t>(g);
                        } else if (sub_tag == 2) { // num_class
                            uint64_t c = 0;
                            stream.read_varint64(&c);
                            num_class = static_cast<int32_t>(c);
                        } else {
                            stream.skip_field(sub_wire);
                        }
                    }
                }
                break;
            }
            default:
                stream.skip_field(wire_type);
                break;
        }
    }

    // Factory creation based on ModelType
    // Tạo đối tượng mô hình tương ứng dựa trên ModelType đã giải mã
    std::shared_ptr<BaseModel> model;
    switch (model_type) {
        case ModelType::BOOSTING_CLASSIFICATION:
            model = std::make_shared<BoostingClassifier>();
            break;
        case ModelType::BOOSTING_REGRESSION:
            model = std::make_shared<BoostingRegressor>();
            break;
        case ModelType::VOTING_CLASSIFICATION:
            model = std::make_shared<VotingClassifier>();
            break;
        case ModelType::VOTING_REGRESSION:
            model = std::make_shared<VotingRegressor>();
            break;
        case ModelType::BOOSTING_MULTI_LABEL_CLASSIFICATION:
            model = std::make_shared<BoostingMultiLabelClassifier>();
            break;
        case ModelType::VOTING_MULTI_LABEL_CLASSIFICATION:
            model = std::make_shared<VotingMultiLabelClassifier>();
            break;
        default:
            // Fallback inferred from tree_relation
            if (tree_relation == TreeRelation::VOTING) {
                model = std::make_shared<VotingClassifier>();
            } else {
                model = std::make_shared<BoostingClassifier>();
            }
            break;
    }

    model->set_n_feature(n_feature);
    model->set_num_group(num_group);
    model->set_num_class(num_class);
    model->set_base_score(base_score);
    if (tree_relation != TreeRelation::UNKNOWN) {
        model->set_tree_relation(tree_relation);
    }

    for (auto& tree : parsed_trees) {
        model->add_tree(std::move(tree));
    }

    return model;
}

Tree ModelParser::parse_tree(CodedInputStream& stream, size_t tree_bytes) {
    size_t end_pos = stream.current_position() + tree_bytes;

    int32_t tree_id = 0;
    int32_t root_id = 0;
    int32_t num_leaves = 0;
    int32_t max_depth = 0;

    struct RawNodeInfo {
        std::shared_ptr<Node> node;
        int32_t left_id = -1;
        int32_t right_id = -1;
    };
    std::map<int32_t, RawNodeInfo> node_map;

    while (stream.current_position() < end_pos) {
        uint32_t tag = 0;
        WireType wire = VARINT;
        if (!stream.read_tag(&tag, &wire)) break;

        switch (tag) {
            case 1: { // tree_id
                uint64_t val = 0;
                stream.read_varint64(&val);
                tree_id = static_cast<int32_t>(val);
                break;
            }
            case 2: { // repeated Node
                uint64_t node_len = 0;
                if (stream.read_varint64(&node_len)) {
                    int32_t left_id = -1;
                    int32_t right_id = -1;
                    std::shared_ptr<Node> n = parse_node(stream, static_cast<size_t>(node_len), &left_id, &right_id);
                    if (n) {
                        int32_t id = n->get_node_id();
                        node_map[id] = {n, left_id, right_id};
                    }
                }
                break;
            }
            case 3: { // root_id
                uint64_t val = 0;
                stream.read_varint64(&val);
                root_id = static_cast<int32_t>(val);
                break;
            }
            case 4: { // num_leaves
                uint64_t val = 0;
                stream.read_varint64(&val);
                num_leaves = static_cast<int32_t>(val);
                break;
            }
            case 5: { // max_depth
                uint64_t val = 0;
                stream.read_varint64(&val);
                max_depth = static_cast<int32_t>(val);
                break;
            }
            default:
                stream.skip_field(wire);
                break;
        }
    }

    // Link AST child pointers
    // Kết nối các nút con trái/phải để hoàn thiện cây nhị phân AST
    for (auto& pair : node_map) {
        RawNodeInfo& info = pair.second;
        if (!info.node->is_leaf()) {
            NonLeafNode* non_leaf = static_cast<NonLeafNode*>(info.node.get());
            std::shared_ptr<Node> left_child = (info.left_id >= 0 && node_map.count(info.left_id)) ?
                                               node_map[info.left_id].node : nullptr;
            std::shared_ptr<Node> right_child = (info.right_id >= 0 && node_map.count(info.right_id)) ?
                                                node_map[info.right_id].node : nullptr;
            non_leaf->set_children(left_child, right_child);
        }
    }

    Tree tree(tree_id);
    if (node_map.count(root_id)) {
        tree.set_root(node_map[root_id].node);
    } else if (!node_map.empty()) {
        tree.set_root(node_map.begin()->second.node);
    }
    tree.set_num_leaves(num_leaves);
    tree.set_max_depth(max_depth);
    tree.set_num_nodes(static_cast<int32_t>(node_map.size()));

    return tree;
}

std::shared_ptr<Node> ModelParser::parse_node(CodedInputStream& stream, size_t node_bytes,
                                              int32_t* left_id, int32_t* right_id) {
    size_t end_pos = stream.current_position() + node_bytes;

    int32_t node_id = 0;
    bool is_leaf = false;
    float leaf_value = 0.0f;
    int32_t leaf_index = 0;
    int32_t feature_index = 0;
    float threshold = 0.0f;
    CompareOp op = CompareOp::OP_LESS_EQUAL;
    bool default_direction = true;
    std::vector<int32_t> categories;

    while (stream.current_position() < end_pos) {
        uint32_t tag = 0;
        WireType wire = VARINT;
        if (!stream.read_tag(&tag, &wire)) break;

        switch (tag) {
            case 1: { // node_id
                uint64_t val = 0;
                stream.read_varint64(&val);
                node_id = static_cast<int32_t>(val);
                break;
            }
            case 2: { // is_leaf
                uint64_t val = 0;
                stream.read_varint64(&val);
                is_leaf = (val != 0);
                break;
            }
            case 3: { // leaf_value
                stream.read_float(&leaf_value);
                break;
            }
            case 4: { // leaf_index
                uint64_t val = 0;
                stream.read_varint64(&val);
                leaf_index = static_cast<int32_t>(val);
                break;
            }
            case 5: { // feature_index
                uint64_t val = 0;
                stream.read_varint64(&val);
                feature_index = static_cast<int32_t>(val);
                break;
            }
            case 6: { // threshold
                stream.read_float(&threshold);
                break;
            }
            case 7: { // op
                uint64_t val = 0;
                stream.read_varint64(&val);
                op = static_cast<CompareOp>(val);
                break;
            }
            case 8: { // left_child_id
                uint64_t val = 0;
                stream.read_varint64(&val);
                *left_id = static_cast<int32_t>(val);
                break;
            }
            case 9: { // right_child_id
                uint64_t val = 0;
                stream.read_varint64(&val);
                *right_id = static_cast<int32_t>(val);
                break;
            }
            case 10: { // default_direction
                uint64_t val = 0;
                stream.read_varint64(&val);
                default_direction = (val != 0);
                break;
            }
            case 11: { // categories
                uint64_t cat_len = 0;
                if (stream.read_varint64(&cat_len)) {
                    size_t cat_end = stream.current_position() + static_cast<size_t>(cat_len);
                    while (stream.current_position() < cat_end) {
                        uint64_t cat_val = 0;
                        if (stream.read_varint64(&cat_val)) {
                            categories.push_back(static_cast<int32_t>(cat_val));
                        }
                    }
                }
                break;
            }
            default:
                stream.skip_field(wire);
                break;
        }
    }

    if (is_leaf) {
        return std::make_shared<LeafNode>(node_id, leaf_value, leaf_index);
    } else if (!categories.empty()) {
        return std::make_shared<CategoricalNode>(node_id, feature_index, categories, default_direction);
    } else {
        return std::make_shared<NumericalNode>(node_id, feature_index, threshold, op, default_direction);
    }
}

static void serialize_node_recursive(const Node* node, CodedOutputStream& stream,
                                     int32_t left_id, int32_t right_id) {
    if (!node) return;

    CodedOutputStream node_stream;
    // tag 1: node_id
    node_stream.write_tag(1, WireType::VARINT);
    node_stream.write_varint32(static_cast<uint32_t>(node->get_node_id()));

    // tag 2: is_leaf
    node_stream.write_tag(2, WireType::VARINT);
    node_stream.write_varint32(node->is_leaf() ? 1 : 0);

    if (node->is_leaf()) {
        const LeafNode* leaf = static_cast<const LeafNode*>(node);
        // tag 3: leaf_value
        node_stream.write_tag(3, WireType::FIXED32);
        node_stream.write_float(leaf->get_leaf_value());

        // tag 4: leaf_index
        node_stream.write_tag(4, WireType::VARINT);
        node_stream.write_varint32(static_cast<uint32_t>(leaf->get_leaf_index()));
    } else {
        const NonLeafNode* non_leaf = static_cast<const NonLeafNode*>(node);
        // tag 5: feature_index
        node_stream.write_tag(5, WireType::VARINT);
        node_stream.write_varint32(static_cast<uint32_t>(non_leaf->get_feature_index()));

        // tag 8: left_child_id
        if (left_id >= 0) {
            node_stream.write_tag(8, WireType::VARINT);
            node_stream.write_varint32(static_cast<uint32_t>(left_id));
        }

        // tag 9: right_child_id
        if (right_id >= 0) {
            node_stream.write_tag(9, WireType::VARINT);
            node_stream.write_varint32(static_cast<uint32_t>(right_id));
        }

        // tag 10: default_direction
        node_stream.write_tag(10, WireType::VARINT);
        node_stream.write_varint32(non_leaf->get_default_direction() ? 1 : 0);

        if (auto num = dynamic_cast<const NumericalNode*>(non_leaf)) {
            // tag 6: threshold
            node_stream.write_tag(6, WireType::FIXED32);
            node_stream.write_float(num->get_threshold());

            // tag 7: op
            node_stream.write_tag(7, WireType::VARINT);
            node_stream.write_varint32(static_cast<uint32_t>(num->get_operator()));
        }
    }

    const auto& node_bytes = node_stream.get_buffer();
    stream.write_tag(2, WireType::LENGTH_DELIMITED);
    stream.write_varint64(node_bytes.size());
    stream.write_raw_bytes(node_bytes.data(), node_bytes.size());
}

static void traverse_and_serialize_nodes(const Node* root, CodedOutputStream& tree_stream) {
    if (!root) return;

    std::vector<const Node*> queue;
    queue.push_back(root);
    size_t head = 0;

    while (head < queue.size()) {
        const Node* curr = queue[head++];
        int32_t left_id = -1;
        int32_t right_id = -1;
        if (!curr->is_leaf()) {
            if (curr->get_left()) {
                left_id = curr->get_left()->get_node_id();
                queue.push_back(curr->get_left().get());
            }
            if (curr->get_right()) {
                right_id = curr->get_right()->get_node_id();
                queue.push_back(curr->get_right().get());
            }
        }
        serialize_node_recursive(curr, tree_stream, left_id, right_id);
    }
}

std::vector<uint8_t> ModelParser::serialize_to_buffer(const BaseModel& model) {
    CodedOutputStream stream;

    // tag 1: model_type
    stream.write_tag(1, WireType::VARINT);
    stream.write_varint32(static_cast<uint32_t>(model.get_model_type()));

    // tag 2: tree_relation
    stream.write_tag(2, WireType::VARINT);
    stream.write_varint32(static_cast<uint32_t>(model.get_tree_relation()));

    // tag 3: n_feature
    stream.write_tag(3, WireType::VARINT);
    stream.write_varint32(static_cast<uint32_t>(model.get_n_feature()));

    // tag 4: trees
    for (const auto& tree : model.get_trees()) {
        CodedOutputStream tree_stream;
        tree_stream.write_tag(1, WireType::VARINT);
        tree_stream.write_varint32(static_cast<uint32_t>(tree.get_tree_id()));

        if (tree.get_root()) {
            tree_stream.write_tag(3, WireType::VARINT);
            tree_stream.write_varint32(static_cast<uint32_t>(tree.get_root()->get_node_id()));
            traverse_and_serialize_nodes(tree.get_root().get(), tree_stream);
        }

        tree_stream.write_tag(4, WireType::VARINT);
        tree_stream.write_varint32(static_cast<uint32_t>(tree.get_num_leaves()));

        tree_stream.write_tag(5, WireType::VARINT);
        tree_stream.write_varint32(static_cast<uint32_t>(tree.get_max_depth()));

        const auto& t_bytes = tree_stream.get_buffer();
        stream.write_tag(4, WireType::LENGTH_DELIMITED);
        stream.write_varint64(t_bytes.size());
        stream.write_raw_bytes(t_bytes.data(), t_bytes.size());
    }

    // tag 5: base_score
    stream.write_tag(5, WireType::FIXED32);
    stream.write_float(model.get_base_score());

    // tag 6: Config
    CodedOutputStream cfg_stream;
    cfg_stream.write_tag(1, WireType::VARINT);
    cfg_stream.write_varint32(static_cast<uint32_t>(model.get_num_group()));
    cfg_stream.write_tag(2, WireType::VARINT);
    cfg_stream.write_varint32(static_cast<uint32_t>(model.get_num_class()));

    const auto& c_bytes = cfg_stream.get_buffer();
    stream.write_tag(6, WireType::LENGTH_DELIMITED);
    stream.write_varint64(c_bytes.size());
    stream.write_raw_bytes(c_bytes.data(), c_bytes.size());

    return stream.get_buffer();
}

bool ModelParser::serialize_to_path(const BaseModel& model, const char* filepath) {
    if (!filepath) return false;
    std::vector<uint8_t> buf = serialize_to_buffer(model);
    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open()) return false;
    file.write(reinterpret_cast<const char*>(buf.data()), buf.size());
    return file.good();
}

} // namespace protobuf
} // namespace bytedt
