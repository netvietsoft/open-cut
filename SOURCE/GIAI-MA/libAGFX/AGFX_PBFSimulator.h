/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Graphics Engine
 * File: AGFX_PBFSimulator.h
 * Module: libAGFX.so (Amazing Engine / AGFXLib / PBF_algo / PBFSimulator.cpp)
 * 
 * Description (EN):
 * Complete reconstruction of ByteDance Amazing Engine 3D Position-Based Fluids (PBF)
 * particle simulator. Implements spatial grid hashing, Macklin & Müller (2013) density
 * constraint solver, tensile instability correction (s_corr), XSPH artificial viscosity,
 * and AR face/nose ellipse collision boundary constraints for mobile GPU effects.
 *
 * Mô tả (VI):
 * Tái cấu trúc hoàn chỉnh bộ mô phỏng hạt chất lỏng 3D PBF (Position-Based Fluids)
 * thuộc Amazing Engine của ByteDance. Hiện thực hóa thuật toán băm không gian (Spatial Grid Hash),
 * giải ràng buộc mật độ Macklin & Müller (2013), khử bất ổn định lực căng (s_corr),
 * độ nhớt nhân tạo XSPH, và va chạm vật lý với ellipsoid khuôn mặt/mũi AR trên GPU di động.
 * ============================================================================
 */

#pragma once

#include "AGFX_Types.h"
#include "AGFX_ComputerDevice.h"
#include <vector>
#include <string>
#include <cmath>

namespace AmazingEngine {

/**
 * PBF Simulation Parameters
 * Khởi tạo tham số vật lý mô phỏng hạt PBF
 */
struct PBFParams {
    int nIterations = 4;           // Số vòng lặp giải ràng buộc mật độ (Offset 0x0)
    float restDensity = 1000.0f;   // Mật độ nghỉ chuẩn của chất lỏng (kg/m3) (Offset 0x4)
    float particleRadius = 0.015f; // Bán kính tương tác hạt (Offset 0x8)
    float particleMass = 0.02f;    // Khối lượng mỗi hạt (Offset 0x10)
    float h = 0.035f;              // Bán kính làm mịn hạt nhân SPH (Offset 0x14)
    int numParticles = 0;          // Tổng số lượng hạt (Offset 0x18/0x1c)
    
    // Boundary and stabilization parameters (Offset 0x20)
    float kcorr = 0.001f;          // Hệ số chống cụm hạt (tensile instability k)
    float ncorr = 4.0f;            // Bậc lũy thừa chống cụm hạt (tensile instability n)
    float lambdaEps = 600.0f;      // Hệ số điều hòa mẫu số Lagrange (CFM parameter)
    float dt = 0.016f;             // Bước thời gian tích phân (thường là 1/60s)
    float viscosity = 0.01f;       // Hệ số độ nhớt nhân tạo XSPH
    
    Vector3f gravity = {0.0f, -9.8f, 0.0f}; // Trọng trường gia tốc
};

/**
 * PBF Runtime Context
 * Lưu trữ trạng thái bộ đệm GPU (SSBO buffers) cho Double-Buffering
 */
struct PBFContext {
    int numParticles = 0;          // [Offset 0x0] Số hạt hiện thời
    int numActiveParticles = 0;    // [Offset 0x4] Số hạt đang hoạt động
    int maxParticles = 0;          // [Offset 0x8] Sức chứa tối đa
    int flags = 0;                 // [Offset 0xc] Cờ trạng thái
    
    // Double-buffered Device Buffers (SSBO)
    handle_DeviceBuffer_t* posBufPing = nullptr;      // [Offset 0x10] Vị trí hạt ping (x, y, z, w)
    handle_DeviceBuffer_t* auxBuf = nullptr;          // [Offset 0x18] Bộ đệm phụ trợ
    handle_DeviceBuffer_t* posBufPong = nullptr;      // [Offset 0x20] Vị trí hạt pong
    handle_DeviceBuffer_t* velBufPing = nullptr;      // [Offset 0x28] Vận tốc hạt ping (vx, vy, vz, vw)
    handle_DeviceBuffer_t* velBufPong = nullptr;      // [Offset 0x30] Vận tốc hạt pong
    
    // Spatial grid hash buffers
    handle_DeviceBuffer_t* gridHashBuf = nullptr;     // [Offset 0x38] Lưu Hash của từng hạt
    handle_DeviceBuffer_t* gridCellBuf = nullptr;     // [Offset 0x40] Đầu/cuối chỉ mục từng ô lưới
    handle_DeviceBuffer_t* lambdaBuf = nullptr;       // [Offset 0x48] Nhân tử Lagrange lambda_i
    handle_DeviceBuffer_t* deltaPosBuf = nullptr;     // [Offset 0x50] Độ dịch chuyển hiệu chỉnh delta_x
};

/**
 * 3D SPH / PBF Particle Simulator Engine
 * Lớp chính thực thi chu trình mô phỏng hạt PBF
 */
class PBFSimulator {
public:
    PBFSimulator(ComputerDevice* computeDev, PBFParams& params, Vector4f minLim, Vector4f maxLim);
    virtual ~PBFSimulator();

    // Configuration methods (Cấu hình tham số mô phỏng)
    void loadParams(const PBFParams& params);
    void setLim(const Vector4f& minLim, const Vector4f& maxLim);
    void setGravity(const Vector3f& g);
    void setDt(float dt);
    void setViscosity(float viscosity);
    void setNIteration(int n);
    void setKcorr(float k);
    void setNcorr(float n);
    void setLambdaEps(float eps);
    void setOutput(handle_DeviceBuffer_t* outBuf);

    // AR Mesh & Face Collision Constraints (Ràng buộc va chạm khuôn mặt AR)
    void setFaceEclipse(Vector4f center, Vector4f radius);
    void setNoseEclipse(Vector4f center, Vector4f radius);
    void setModelPosition(const Vector3f& pos);
    void setModelRadius(const Vector3f& radius);
    void setRotation(Vector3f pitch, Vector3f yaw, Vector3f roll);
    void setTranslation(Vector3f t);

    // Pipeline & Simulation execution (Thực thi các bước mô phỏng)
    void step(PBFContext& ctx, handle_DeviceSequence_t* seq);
    void advect(PBFContext& ctx);
    void transformObject(PBFContext& ctx);
    void buildGridHash(PBFContext& ctx);
    void buildBoundaryGridHash(PBFContext& ctx);
    void buildGridHashCountSort(PBFContext& ctx);
    void reorderParticle(PBFContext& ctx);
    void correctDensity(PBFContext& ctx);
    void correctDensity2(PBFContext& ctx);
    void correctDensity3(PBFContext& ctx);
    void updateVelocity(PBFContext& ctx);
    void correctVelocity(PBFContext& ctx);
    void swap(PBFContext& ctx);
    void test(PBFContext& ctx);

    // Buffer helpers
    void bufferMemSet(handle_DeviceBuffer_t* buf, int val, unsigned char size);
    void bufferMemCopy(handle_DeviceBuffer_t* dst, handle_DeviceBuffer_t* src, unsigned int bytes);

private:
    void initPipelineEntity(handle_ComputePipeline_t*& pipeline, handle_ComputeEntity_t*& entity, const std::string& shaderName);
    float poly6Kernel(float r2, float h2) const;
    Vector3f spikyGradKernel(const Vector3f& r, float rLen, float h) const;

private:
    ComputerDevice* m_computeDevice = nullptr;
    handle_DeviceSequence_t* m_currentSeq = nullptr; // [Offset 0x278]

    // Physical bounds and parameters
    Vector4f m_minLim = {-1.0f, -1.0f, -1.0f, 0.0f}; // [Offset 0x1c8]
    Vector4f m_maxLim = { 1.0f,  1.0f,  1.0f, 0.0f}; // [Offset 0x1d8]
    Vector3f m_gravity = {0.0f, -9.8f, 0.0f};        // [Offset 0x1e8]
    
    // Grid parameters
    Vector3f m_gridDim = {64.0f, 64.0f, 64.0f};      // [Offset 0x1e8..0x1f0]
    float m_cellSize = 0.035f;                       // [Offset 0x19c]
    float m_poly6Const = 0.0f;                       // [Offset 0x1f8] = 315 / (64 * pi * h^9)
    float m_spikyConst = 0.0f;                       // [Offset 0x1fc] = 45 / (pi * h^6)

    // Solver settings
    int m_nIterations = 4;                           // [Offset 0x1c4]
    float m_kcorr = 0.001f;                          // [Offset 0x1b0]
    float m_ncorr = 4.0f;                            // [Offset 0x1b4]
    float m_lambdaEps = 600.0f;                      // [Offset 0x1b8]
    float m_dt = 0.016f;                             // [Offset 0x1bc]
    float m_viscosity = 0.01f;                       // [Offset 0x1c0]
    float m_particleRadius = 0.015f;                 // [Offset 0x198]
    float m_particleMass = 0.02f;                    // [Offset 0x190]
    float m_restDensity = 1000.0f;                   // [Offset 0x1a4]

    // AR Face / Nose Ellipsoid Colliders
    Vector4f m_faceEclipseCenter = {0.0f, 0.0f, 0.0f, 0.0f}; // [Offset 0x230]
    Vector4f m_faceEclipseRadius = {0.08f, 0.10f, 0.08f, 0.0f}; // [Offset 0x240]
    Vector4f m_noseEclipseCenter = {0.0f, 0.0f, 0.02f, 0.0f}; // [Offset 0x250]
    Vector4f m_noseEclipseRadius = {0.02f, 0.02f, 0.03f, 0.0f}; // [Offset 0x260]

    Vector3f m_modelPos = {0.0f, 0.0f, 0.0f};
    Vector3f m_modelRadius = {1.0f, 1.0f, 1.0f};
    Vector3f m_rotPitch = {1.0f, 0.0f, 0.0f};
    Vector3f m_rotYaw   = {0.0f, 1.0f, 0.0f};
    Vector3f m_rotRoll  = {0.0f, 0.0f, 1.0f};
    Vector3f m_translation = {0.0f, 0.0f, 0.0f};

    handle_DeviceBuffer_t* m_outputBuffer = nullptr;

    // Compute entities for pipeline stages
    handle_ComputePipeline_t* m_pipeAdvect = nullptr;
    handle_ComputeEntity_t*   m_entityAdvect = nullptr;

    handle_ComputePipeline_t* m_pipeGridHash = nullptr;
    handle_ComputeEntity_t*   m_entityGridHash = nullptr;

    handle_ComputePipeline_t* m_pipeReorder = nullptr;
    handle_ComputeEntity_t*   m_entityReorder = nullptr;

    handle_ComputePipeline_t* m_pipeDensity = nullptr;
    handle_ComputeEntity_t*   m_entityDensity = nullptr;

    handle_ComputePipeline_t* m_pipeVelocity = nullptr;
    handle_ComputeEntity_t*   m_entityVelocity = nullptr;

    handle_ComputePipeline_t* m_pipeXSPH = nullptr;
    handle_ComputeEntity_t*   m_entityXSPH = nullptr;
};

} // namespace AmazingEngine
