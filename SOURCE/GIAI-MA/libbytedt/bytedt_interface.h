// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Master C++ Interface
// Tệp giao diện chính tổng hợp cho toàn bộ thư viện libbytedt
//
// Target Project: com.nextai.opencut (Cleanroom Reconstruction Edition)
// Package: ByteDance Decision Tree Core & Training Engine
// ======================================================================

#pragma once

#include "bytedt_types.h"
#include "bytedt_node.h"
#include "bytedt_tree.h"
#include "bytedt_model.h"
#include "bytedt_models.h"
#include "bytedt_protobuf.h"
#include "bytedt_interpreter.h"
#include "bytedt_train.h"

namespace NextAI::OpenCut::bytedt {

// Aliases for unified NextAI OpenCut namespace
using ::bytedt::ByteDT;
using ::bytedt::ByteDTTrain;
using ::bytedt::ByteDTErrorCode;
using ::bytedt::ModelType;
using ::bytedt::TreeRelation;
using ::bytedt::CompareOp;
using ::bytedt::Input;
using ::bytedt::RunInfo;
using ::bytedt::SourceLocation;
using ::bytedt::WarningHandler;
using ::bytedt::Warning;
using ::bytedt::Node;
using ::bytedt::LeafNode;
using ::bytedt::NonLeafNode;
using ::bytedt::NumericalNode;
using ::bytedt::CategoricalNode;
using ::bytedt::Tree;
using ::bytedt::BaseModel;
using ::bytedt::BoostingClassifier;
using ::bytedt::BoostingRegressor;
using ::bytedt::BoostingMultiLabelClassifier;
using ::bytedt::VotingClassifier;
using ::bytedt::VotingRegressor;
using ::bytedt::VotingMultiLabelClassifier;
using ::bytedt::get_version;

} // namespace NextAI::OpenCut::bytedt
