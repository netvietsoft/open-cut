/**
 * @file bdmicropythonvm_pybridge_tensor.h
 * @brief PYBridge (52 Methods), TensorWrapper (.data 0x060000), BDByteDTBridge, BDByteNNBridge, BDTVMBridge, BDPNNBridge & BDPyBridge
 *        Cầu nối PYBridge (52 phương thức), TensorWrapper (.data 0x060000), BDByteDTBridge, BDByteNNBridge, BDTVMBridge, BDPNNBridge & BDPyBridge
 *
 * =================================================================================================
 * [EVIDENCE CLASSIFICATION: OBSERVED (100% Disassembled from libBDMicroPythonVM.so @ 0x00f0a0..0x03bebb)]
 * [PHÂN LOẠI BẰNG CHỨNG: OBSERVED (Giải mã 100% từ nhị phân thật libBDMicroPythonVM.so @ 0x00f0a0..0x03bebb)]
 * =================================================================================================
 *
 * Disassembled Subsystems / Các phân hệ giải mã:
 * 1. RegisterMicroPyNativeModules (@ 0x03b374..0x03bebc, branched from .init_array @ 0x00f0a0 & MicroPyLoader_nativeInit @ 0x050f88)
 * 2. PYBridge                     (@ 0x00f0e0..0x02cffc, .rodata 0x0517fa..0x0522db, 52 methods, SDK "2.14.0")
 * 3. TensorWrapperObj             (@ 0x031800..0x032ef0, .rodata 0x0523c1..0x0524f0, .data 0x060000..0x0600b0, TensorType @ 0x060210)
 * 4. BDByteDTBridge               (@ 0x032f00..0x034500, .rodata 0x052565..0x0526c6: load_model, predict, get_model_info)
 * 5. BDByteNNBridge               (@ 0x034500..0x03a800, .rodata 0x052797..0x052930: 17 ByteNN inference & training methods)
 * 6. BDTVMBridge & BDPNNBridge    (@ 0x02d000..0x0317ff, .rodata 0x0522ec & 0x0522f8)
 * 7. BDPyBridge                   (@ 0x03a800..0x03b370, .rodata 0x05293b..0x052ad0, SDK "3.14.0" / "3.1.0")
 */

#ifndef NEXTAI_OPENCUT_BDMICROPYTHONVM_PYBRIDGE_TENSOR_H_
#define NEXTAI_OPENCUT_BDMICROPYTHONVM_PYBRIDGE_TENSOR_H_

#include "bdmicropythonvm_types.h"

namespace fast_engine {

/**
 * @brief fast_engine::TensorWrapperObj (size 0x78 = 120 bytes, TypeObj* = TensorType @ 0x060210).
 *        Đối tượng bọc Tensor fast_engine::TensorWrapperObj (kích thước 0x78 = 120 bytes, TypeObj* = TensorType tại 0x060210).
 *
 * [OBSERVED @ 0x0326c4..0x032948 & .data 0x060000..0x0600b0]:
 * - Offset +0x40: int32_t data_type   (1=FLOAT32, 2=UINT8, 3=INT8, 4=UINT16, 5=INT16, 6=INT32, 7=INT64, 11=DOUBLE)
 * - Offset +0x44: int32_t data_format (0=NHWC, 1=NCHW, 2=NC4HW4)
 * - Offset +0x48: int32_t fraction    (quantization fraction)
 * - Offset +0x58: Obj* cached_dims_list (OBSERVED @ 0x0326f0: ldr x0, [x0, #0x58])
 * - Offset +0x60: Obj* cached_num_list
 * - Offset +0x68..+0x70: std::shared_ptr<pitaya::PTYTensor> inner_tensor_ (OBSERVED @ 0x032700: ldr x8, [x19, #0x70])
 */
class TensorWrapperObj : public Obj {
public:
    TensorWrapperObj(std::shared_ptr<pitaya::PTYTensor> tensor, Engine* eng);
    ~TensorWrapperObj() override;

    std::string Str() const override;

    const std::shared_ptr<pitaya::PTYTensor>& InnerTensor() const { return inner_tensor_; }

    // Attribute getters/setters matching .data 0x060000..0x0600b0
    static Obj* GetDataType(Obj* self, Engine* eng);      // @ 0x032274
    static int  SetDataType(Obj* self, Obj* val, Engine* eng); // @ 0x032350
    static Obj* GetDataFormat(Obj* self, Engine* eng);    // @ 0x03242c
    static int  SetDataFormat(Obj* self, Obj* val, Engine* eng); // @ 0x032508
    static Obj* GetDims(Obj* self, Engine* eng);          // @ 0x0326c4
    static int  SetDims(Obj* self, Obj* val, Engine* eng);// @ 0x032834
    static Obj* GetFraction(Obj* self, Engine* eng);      // @ 0x0325e8
    static int  SetFraction(Obj* self, Obj* val, Engine* eng); // @ 0x032a2c
    static Obj* GetNumList(Obj* self, Engine* eng);       // @ 0x032b08
    static int  SetNumList(Obj* self, Obj* val, Engine* eng);  // @ 0x032cd0

    static const AttrDef kTensorWrapperAttrs[6];

    int32_t data_type{1};                              // +0x40
    int32_t data_format{0};                            // +0x44
    int32_t fraction{0};                               // +0x48
    int32_t pad_4c_{0};                                // +0x4c
    uint64_t reserved_50_{0};                          // +0x50
    Obj* cached_dims_list{nullptr};                    // +0x58 (OBSERVED @ 0x0326f0: ldr x0, [x0, #0x58])
    Obj* cached_num_list{nullptr};                     // +0x60
    std::shared_ptr<pitaya::PTYTensor> inner_tensor_;  // +0x68..+0x70 (total size 0x78 = 120 bytes)
};

/**
 * @brief Parsed SQL WHERE timestamp filter clause matching `.rodata` regex at 0x0517fa:
 *        `(timestamp)[\s]*(>|>=|=|!=|<=|<)[\s]*(\d*[.]*\d*)`
 *        Cấu trúc bộ lọc mệnh đề WHERE timestamp khớp với biểu thức chính quy `.rodata` tại 0x0517fa.
 */
struct SqlTimestampCondition {
    bool valid{false};
    std::string op;
    double threshold{0.0};

    bool Evaluate(double row_timestamp) const;
};

/**
 * @brief Parses SQL timestamp condition using the exact pattern observed at 0x0517fa.
 *        Phân tích điều kiện timestamp SQL sử dụng mẫu biểu thức chính quy quan sát tại 0x0517fa.
 */
SqlTimestampCondition ParseSqlTimestampFilter(const std::string& sql_query);

/**
 * @brief CityHash64 implementation matching `_ZN6pitaya10CityHash64EPKcm` (PLT @ 0x00ded0, called by PYBridge `cityhash64` @ 0x051da8).
 *        Triển khai hàm băm CityHash64 khớp với `pitaya::CityHash64(const char*, size_t)` (PLT tại 0x00ded0).
 */
uint64_t ComputePitayaCityHash64(const char* buf, size_t len);

/**
 * @brief PYBridge native module (`"PYBridge"`, SDK version `"2.14.0"` @ 0x052131) with 52 registered methods (@ 0x0519a3..0x051e77).
 *        Module native PYBridge (`"PYBridge"`, phiên bản SDK `"2.14.0"` tại 0x052131) với 52 phương thức đăng ký (@ 0x0519a3..0x051e77).
 */
class PYBridgeModule {
public:
    static constexpr const char* kModuleName = "PYBridge";
    static constexpr const char* kSdkVersion = "2.14.0"; // OBSERVED @ 0x03b3a0 & 0x052131

    static const std::vector<std::string>& GetMethodNames();

    static Obj* InvokeMethod(const std::string& method_name,
                             const std::vector<Obj*>& args,
                             Engine* engine);

    // Storage for memory & database cache methods (set_memory_cache / get_memory_cache / get_database_cache)
    static void SetMemoryCache(const std::string& business, const std::string& key, const std::string& val);
    static std::string GetMemoryCache(const std::string& business, const std::string& key);
};

/**
 * @brief BDByteDTBridge native module (`"BDByteDTBridge"` @ 0x052565) wrapping `pitaya::ByteDTEngine`.
 *        Module native BDByteDTBridge (`"BDByteDTBridge"` tại 0x052565) bọc `pitaya::ByteDTEngine`.
 *
 * [OBSERVED @ .rodata 0x052565..0x0526c6]:
 * Methods:
 * 1. `load_model`     (@ 0x0525c2) -> `pitaya::ByteDTEngine::LoadByteDTModel`
 * 2. `predict`        (@ 0x0525cd) -> `pitaya::ByteDTEngine::Predict`
 * 3. `get_model_info` (@ 0x0525d5) -> returns tree depth / feature count dict
 */
class BDByteDTBridgeModule {
public:
    static constexpr const char* kModuleName = "BDByteDTBridge";

    struct ByteDTModelHandle {
        std::string model_path;
        int32_t num_trees{16};
        int32_t num_features{8};
        std::vector<double> feature_weights;
        bool loaded{false};
    };

    static int64_t LoadModel(const std::string& model_dir, Engine* engine);
    static Obj* Predict(int64_t model_handle, const std::vector<double>& features, Engine* engine);
    static Obj* GetModelInfo(int64_t model_handle, Engine* engine);
};

/**
 * @brief BDByteNNBridge native module (`"BDByteNNBridge"` @ 0x052797) wrapping `BYTENN::ByteNN_Pitaya::Net`.
 *        Module native BDByteNNBridge (`"BDByteNNBridge"` tại 0x052797) bọc `BYTENN::ByteNN_Pitaya::Net`.
 *
 * [OBSERVED @ .rodata 0x052797..0x052930]:
 * 17 Methods:
 * `set_config`, `get_input_config`, `set_input`, `inference`, `reinfer_shape_with_tensors`,
 * `reinfer_shape`, `release`, `set_optimizer`, `step`, `save_model`, `set_weights`,
 * `get_forward_type`, `get_weight`, `get_gradient`, `set_losslayers`, `set_labels`, `enable_data_wrapper`.
 */
class BDByteNNBridgeModule {
public:
    static constexpr const char* kModuleName = "BDByteNNBridge";

    struct ByteNNSession {
        int32_t forward_type{0}; // 0=CPU, 1=GPU_OPENCL, 2=NPU
        int32_t num_threads{2};
        bool data_wrapper_enabled{false};
        std::string optimizer_name{"sgd"};
        double learning_rate{0.001};
        std::vector<int64_t> input_dims{1, 3, 224, 224};
        std::unordered_map<std::string, std::shared_ptr<pitaya::PTYTensor>> inputs;
        std::unordered_map<std::string, std::vector<float>> weights;
        std::unordered_map<std::string, std::vector<float>> gradients;
        std::vector<std::string> loss_layers;
        std::vector<float> labels;
    };

    static const std::vector<std::string>& GetMethodNames();
    static int64_t CreateSession();
    static bool SetConfig(int64_t session_id, int32_t forward_type, int32_t num_threads);
    static std::shared_ptr<pitaya::PTYTensor> Inference(int64_t session_id, Engine* engine);
    static bool StepOptimizer(int64_t session_id);
    static void ReleaseSession(int64_t session_id);
};

/**
 * @brief Reconstructed `RegisterMicroPyNativeModules` (@ 0x03b374, called from `.init_array` @ 0x00f0a0 & `MicroPyLoader_nativeInit` @ 0x050f88).
 *        Tái dựng hàm `RegisterMicroPyNativeModules` (@ 0x03b374, gọi từ `.init_array` @ 0x00f0a0 & `MicroPyLoader_nativeInit` @ 0x050f88).
 */
void RegisterMicroPyNativeModules();

bool AreMicroPyNativeModulesRegistered();

} // namespace fast_engine

#endif // NEXTAI_OPENCUT_BDMICROPYTHONVM_PYBRIDGE_TENSOR_H_
