// ======================================================================
// NextAI OpenCut — libbytedt Comprehensive Implementation & Verification Harness
// Triển khai đối soát và kiểm chứng tính năng cho libbytedt
// ======================================================================

#include "bytedt_interface.h"
#include <iostream>
#include <cassert>
#include <vector>

namespace bytedt {

/**
 * @brief Self-test verification function demonstrating full decision tree lifecycle.
 * Hàm tự kiểm tra chứng minh toàn bộ vòng đời mô hình cây quyết định:
 * 1. Khởi tạo cây và nút phân nhánh.
 * 2. Đánh giá chia nhánh với giá trị số và IEEE-754 NaN fallback.
 * 3. Đánh giá phân loại GBDT với kích hoạt Sigmoid / Softmax.
 * 4. Mã hóa và giải mã tuần tự hóa Protobuf (ModelParser).
 * 5. Huấn luyện On-Device GBDT (ByteDTTrain::train).
 */
bool RunSelfTestVerification() {
    using namespace bytedt;

    // 1. Version test
    assert(get_version() == "2.1.6");

    // 2. Node & Split Evaluation test
    auto root = std::make_shared<NumericalNode>(0, 0, 5.0f, CompareOp::OP_LESS_EQUAL, true);
    auto leaf_left = std::make_shared<LeafNode>(1, -1.5f, 0);
    auto leaf_right = std::make_shared<LeafNode>(2, 2.5f, 1);
    root->set_children(leaf_left, leaf_right);

    Tree tree(0);
    tree.set_root(root);
    tree.set_num_leaves(2);
    tree.set_max_depth(1);

    // Test feature <= 5.0f -> left (-1.5f)
    float feat1[1] = { 3.0f };
    assert(tree.predict(feat1, 1) == -1.5f);
    assert(tree.predict_leaf(feat1, 1) == 0);

    // Test feature > 5.0f -> right (2.5f)
    float feat2[1] = { 8.0f };
    assert(tree.predict(feat2, 1) == 2.5f);
    assert(tree.predict_leaf(feat2, 1) == 1);

    // Test NaN fallback -> default_direction (true -> left)
    float feat_nan[1] = { std::numeric_limits<float>::quiet_NaN() };
    assert(tree.predict(feat_nan, 1) == -1.5f);

    // 3. Boosting Classifier Model with Sigmoid Activation
    auto clf = std::make_shared<BoostingClassifier>();
    clf->set_n_feature(1);
    clf->set_num_group(1);
    clf->set_base_score(0.0f);
    clf->add_tree(tree);

    std::vector<float> samples = { 3.0f, 8.0f };
    std::vector<float> probs = clf->predict(samples.data(), 2);
    assert(probs.size() == 2);
    // Prob 0: 1 / (1 + exp(-(-1.5))) = 1 / (1 + exp(1.5)) approx 0.1824
    assert(probs[0] > 0.18f && probs[0] < 0.19f);
    // Prob 1: 1 / (1 + exp(-(2.5))) = 1 / (1 + exp(-2.5)) approx 0.9241
    assert(probs[1] > 0.92f && probs[1] < 0.93f);

    // 4. Protobuf Serialization & Deserialization roundtrip
    std::vector<uint8_t> pb_bytes = protobuf::ModelParser::serialize_to_buffer(*clf);
    assert(!pb_bytes.empty());

    auto restored = protobuf::ModelParser::parse_from_buffer(pb_bytes.data(), pb_bytes.size());
    assert(restored != nullptr);
    assert(restored->get_n_feature() == 1);
    assert(restored->get_tree_count() == 1);

    std::vector<float> restored_probs = restored->predict(samples.data(), 2);
    assert(restored_probs.size() == 2);
    assert(std::abs(restored_probs[0] - probs[0]) < 1e-5f);
    assert(std::abs(restored_probs[1] - probs[1]) < 1e-5f);

    // 5. Engine Inference Validation
    auto engine = ByteDT::create_engine();
    engine->set_model(restored);

    ByteDTErrorCode err = ByteDTErrorCode::OK;
    RunInfo info;
    Input in_valid(samples.data(), samples.size() * sizeof(float), 1);
    std::vector<float> engine_out = engine->predict(in_valid, err, &info);
    assert(err == ByteDTErrorCode::OK);
    assert(engine_out.size() == 2);
    assert(info.trees_evaluated == 1);

    // Test dimension mismatch
    Input in_bad(samples.data(), 3, 1); // 3 bytes is not a multiple of 4 bytes
    engine->predict(in_bad, err);
    assert(err == ByteDTErrorCode::DIMENSION_MISMATCH);

    // 6. On-Device Training (ByteDTTrain)
    auto trainer = ByteDTTrain::create_engine();
    std::vector<float> train_x = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f };
    Input train_in(train_x.data(), train_x.size() * sizeof(float), 1);
    std::string train_cfg = "{\"n_feature\":1, \"n_iteration\":5}";
    std::string train_y = "10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0";

    bool train_ok = trainer->train(train_in, train_cfg, train_y, err, &info);
    assert(train_ok && err == ByteDTErrorCode::OK);
    assert(trainer->get_model() != nullptr);
    assert(trainer->get_model()->get_tree_count() == 5);

    std::string pb_trained = trainer->get_pb_model();
    assert(!pb_trained.empty());

    return true;
}

} // namespace bytedt
