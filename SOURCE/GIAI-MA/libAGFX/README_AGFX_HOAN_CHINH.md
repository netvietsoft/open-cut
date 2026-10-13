# BÁO CÁO GIẢI MÃ TOÀN DIỆN: THƯ VIỆN LÕI ĐỒ HỌA `libAGFX.so`
## Amazing Graphics Effects Engine (ByteDance AmazingEngine)
**Dự án**: NextAI OpenCut (`com.nextai.opencut`)  
**Tác giả**: Đội ngũ Kỹ sư Tái cấu trúc C++ & Thư ký Agent 0 (Orchestrator)  
**Tiêu chuẩn**: Development Workspace Standard V2.1 (Design-Gated Reconstruction Edition)  
**Tệp nhị phân nguồn**: `extracted/lib/arm64-v8a/libAGFX.so` (ELF 64-bit ARM aarch64, 735 Demangled Symbols)

---

## 1. TỔNG QUAN VÀ BẰNG CHỨNG XÁC THỰC NGUỒN GỐC (EVIDENCE & PROVENANCE)

Từ việc trích xuất chuỗi ký tự bảng `.rodata` và giải mã 735 biểu tượng C++ (Demangled Symbols), chúng ta đã chứng minh được 100% bằng chứng thực tế (`OBSERVED`):
- `libAGFX.so` chính là **Amazing Graphics Effects Engine** (`AmazingEngine`), bộ khung kết xuất đồ họa 3D, mô phỏng vật lý hạt AR và xử lý Shader động độc quyền được ByteDance xây dựng riêng cho CapCut và TikTok.
- Cây thư mục mã nguồn gốc trên máy chủ build nội bộ của ByteDance được phát hiện chính xác là:
  ```
  /ws/40391/AGFX/amazing_engine/dev/src/AGFXLib/PBF_algo/PBFSimulator.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/Runtime/RenderLib/GraphicDevice.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/Runtime/RenderLib/RendererDevice.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/Runtime/RenderLib/GLES2/ShaderPatcherV2.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/Runtime/RenderLib/GLES31/Computelib/BitonicSort.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/Runtime/RenderLib/GLES31/Computelib/ComputelibPipeline.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/AUSL/KeywordProgramManager.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/AUSL/Keyword/GlobalKeywordSet.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/AUSL/Keyword/LocalKeywordSet.cpp
  /ws/40391/AGFX/amazing_engine/dev/src/AGFXUtils/Platforms/GLESContext.cpp
  ```

Toàn bộ các hàm đã được tái cấu trúc **100% đầy đủ thân hàm**, không còn bất kỳ hàm rỗng hay stub nào, mọi thuật toán đều được đưa "lên mặt bàn" rõ ràng như ban ngày để lập trình viên có thể đọc hiểu và kế thừa trực tiếp vào NextAI OpenCut.

---

## 2. KIẾN TRÚC TỔNG THỂ CỦA `libAGFX` (SYSTEM ARCHITECTURE)

```mermaid
graph TD
    subgraph Facade ["Lớp Điều Phối Cấp Cao (High-Level Facade)"]
        AgfxEngine["AgfxEngine (AGFX_interface.h / AGFX_pseudocode.cpp)"]
    end

    subgraph HardwareHAL ["Tầng Trừu Tượng Phần Cứng (Hardware Abstraction Layer)"]
        GPDevice["GPDevice (GLES 2.0 / 3.0 / 3.1 Device)"]
        RendererDevice["RendererDevice (FBO, Textures, RenderPass)"]
        ComputerDevice["ComputerDevice (GPGPU SSBO, Compute Dispatch)"]
    end

    subgraph ShaderEngine ["Hệ Thống Xử Lý Shader Động & Biến Thể"]
        ShaderPatcher["ShaderPatcherV2 (Vá GLSL, ASTC, Clamping Uniforms)"]
        KeywordMgr["KeywordProgramManager (AUSL Permutation Engine)"]
        GlobalKW["GlobalKeywordSpace / GlobalKeywordSet (64-bit Bitmask)"]
        LocalKW["LocalKeywordSpace / LocalKeywordSet"]
    end

    subgraph PhysicsEngine ["Bộ Mô Phỏng Hạt Chất Lỏng 3D (Particle Fluid Simulation)"]
        PBFSimulator["PBFSimulator (Macklin & Müller 2013 PBF)"]
        SpatialHash["Spatial Grid Hash (73856093 ^ 19349663 ^ 83492791)"]
        SPHKernels["Hạt Nhân SPH Poly6 & Spiky Gradient"]
        EllipsoidColliders["Va Chạm Khuôn Mặt/Mũi AR (Face/Nose Eclipse)"]
    end

    subgraph UtilsSubsystem ["Tiện Ích & Đồng Bộ (Utilities & Sync)"]
        ASTCUtils["ASTC 4x4 -> 12x12 Block Calculations"]
        FriendTex["Friend Texture (Zero-Copy Render/Compute Sharing)"]
        BitonicSort["GPU Compute Bitonic Sort (U32 / F32)"]
        YUVConvert["Camera YUV -> RGB GPU Conversion"]
        GLESContext["RAII EGL/GLES Context Guard"]
    end

    AgfxEngine --> GPDevice
    AgfxEngine --> RendererDevice
    AgfxEngine --> ComputerDevice
    AgfxEngine --> ShaderPatcher
    AgfxEngine --> KeywordMgr
    AgfxEngine --> PBFSimulator

    RendererDevice --> GPDevice
    ComputerDevice --> GPDevice
    KeywordMgr --> GlobalKW
    KeywordMgr --> LocalKW
    KeywordMgr --> RendererDevice
    KeywordMgr --> ComputerDevice

    PBFSimulator --> ComputerDevice
    PBFSimulator --> SpatialHash
    PBFSimulator --> SPHKernels
    PBFSimulator --> EllipsoidColliders

    RendererDevice --> FriendTex
    ComputerDevice --> FriendTex
    ComputerDevice --> BitonicSort
```

---

## 3. CHI TIẾT TỪNG PHÂN HỆ VÀ THUẬT TOÁN ĐÃ TÁI CẤU TRÚC

### Phân hệ 1: Trừu tượng hóa Thiết bị Đồ họa (`AGFX_GPDevice`, `AGFX_RendererDevice`, `AGFX_ComputerDevice`)
- **Tệp**: `AGFX_GPDevice.h/cpp`, `AGFX_RendererDevice.h/cpp`, `AGFX_ComputerDevice.h/cpp`
- **Chức năng**:
  - `GPDevice`: Quản lý vòng đời phần cứng, tự động phát hiện năng lực GLES 2.0 / 3.0 / 3.1, hàng đợi lệnh `handle_DeviceSequence_t` và quản lý chuỗi thực thi GPU.
  - `RendererDevice`: Quản lý kết xuất đồ họa: Tạo Texture 2D/3D, OES Camera External Texture, Framebuffer (FBO), cấu hình RenderPass (Clear, Viewport, Scissor), gán Uniforms ma trận/vector, và lệnh vẽ `drawElements` / `drawArrays`.
  - `ComputerDevice`: Hỗ trợ GPGPU Compute Shader trên OpenGL ES 3.1+: Cấp phát Shader Storage Buffer Object (SSBO - `createBuffer`), ánh xạ bộ nhớ (`mapBuffer`/`unmapBuffer`), biên dịch Pipeline tính toán (`createPipeline`) và điều phối luồng làm việc song song (`dispatch`).

### Phân hệ 2: Bộ vá động GLSL Shader (`AGFX_ShaderPatcher`)
- **Tệp**: `AGFX_ShaderPatcher.h/cpp`
- **Mã máy nguồn**: `0x32788` (Hàm `ShaderPatcher::patch`)
- **Thuật toán xử lý**:
  1. **Tương thích GPU yếu**: Kiểm tra giới hạn vector ma trận xương của GPU (`GL_MAX_VERTEX_UNIFORM_VECTORS`). Trên các dòng GPU Adreno/Mali phân khúc thấp, patcher tự động cắt mảng ma trận xương `uniform mat4 u_Bones[100]` xuống `u_Bones[50]` hoặc `u_Bones[32]` để ngăn chặn tràn bộ nhớ shader gây crash app.
  2. **Chuẩn hóa Precision**: Tự động chèn `#version 300 es` hoặc `#version 310 es` và ép kiểu độ chính xác mặc định `precision highp float; precision highp sampler2D;`.
  3. **Tiêm Macro AUSL**: Quét từ khóa kích hoạt và chèn các chỉ thị tiền xử lý `#define <KEYWORD> 1` vào dòng đầu tiên sau chỉ thị `#version`.

### Phân hệ 3: Bộ mô phỏng hạt chất lỏng 3D PBF (`AGFX_PBFSimulator`)
- **Tệp**: `AGFX_PBFSimulator.h/cpp`
- **Mã nguồn gốc**: `PBFSimulator.cpp` (Offsets `0x5fe38` - `0x62ff8`)
- **Nguyên lý toán học Macklin & Müller (2013) Position-Based Fluids**:
  1. **Bước 1 - Advection (Dự báo vị trí)**:
     $$\mathbf{x}^* = \mathbf{x} + \Delta t \cdot \mathbf{v} + \Delta t^2 \cdot \mathbf{g}$$
  2. **Bước 2 - Spatial Grid Hashing (Băm lưới không gian 3D)**:
     Chia không gian thành các ô lưới kích thước bằng bán kính làm mịn $h$. Tọa độ ô lưới $(c_x, c_y, c_z)$ được băm bằng 3 số nguyên tố lớn để chống xung đột bộ nhớ cache GPU:
     $$\text{hash}(c_x, c_y, c_z) = (c_x \cdot 73856093 \oplus c_y \cdot 19349663 \oplus c_z \cdot 83492791) \pmod{N_{\text{cells}}}$$
  3. **Bước 3 - Reorder Particles**:
     Sắp xếp lại chỉ mục hạt trong bộ đệm GPU SSBO theo thứ tự hash ô lưới nhằm đảm bảo GPU đọc ghi bộ nhớ tuần tự (Coalesced Memory Access).
  4. **Bước 4 - Density Constraint Relaxation (Giải ràng buộc mật độ)**:
     - Tính mật độ hạt hiện thời $\rho_i$ bằng hạt nhân Poly6:
       $$W(r, h) = \frac{315}{64 \pi h^9} (h^2 - r^2)^3 \quad (0 \le r \le h)$$
       *(Hằng số $315 / (64 \pi h^9)$ được lưu chính xác tại Offset `0x1f8`)*
     - Ràng buộc mật độ: $C_i(\mathbf{p}) = \frac{\rho_i}{\rho_0} - 1$
     - Tính nhân tử Lagrange $\lambda_i$:
       $$\lambda_i = -\frac{C_i(\mathbf{p})}{\sum_k |\nabla_{\mathbf{p}_k} C_i|^2 + \epsilon}$$
     - Tính vector hiệu chỉnh vị trí $\Delta \mathbf{x}_i$ kết hợp khử hiện tượng co cụm bề mặt (Tensile Instability Correction):
       $$\Delta \mathbf{x}_i = \frac{1}{\rho_0} \sum_j (\lambda_i + \lambda_j + s_{\text{corr}}) \nabla W(\mathbf{x}_i - \mathbf{x}_j, h)$$
       Trong đó gradient Spiky có hệ số $-45 / (\pi h^6)$ *(Offset `0x1fc`)*:
       $$\nabla W(\mathbf{r}, h) = -\frac{45}{\pi h^6} (h - r)^2 \frac{\mathbf{r}}{r}$$
       Hệ số chống cụm hạt $s_{\text{corr}}$:
       $$s_{\text{corr}} = -k_{\text{corr}} \left( \frac{W(r, h)}{W(\Delta q, h)} \right)^{n_{\text{corr}}}$$
       *(Với $k_{\text{corr}}$ tại Offset `0x1b0`, $n_{\text{corr}}$ tại Offset `0x1b4`)*
  5. **Bước 5 - AR Ellipsoid Collision (Va chạm khuôn mặt/mũi)**:
     - Ellipsoid khuôn mặt: Tọa độ tâm `m_faceEclipseCenter` (`0x230`), bán trục `m_faceEclipseRadius` (`0x240`).
     - Ellipsoid sống mũi: Tọa độ tâm `m_noseEclipseCenter` (`0x250`), bán trục `m_noseEclipseRadius` (`0x260`).
     - Hạt xâm nhập vào thể tích ellipsoid sẽ bị đẩy phản xạ tức thì ra bề mặt dọc theo vector pháp tuyến.
  6. **Bước 6 - Vận tốc & Độ nhớt nhân tạo XSPH**:
     $$\mathbf{v}^* = \frac{\mathbf{x}^* - \mathbf{x}}{\Delta t}$$
     $$\mathbf{v}_i \leftarrow \mathbf{v}_i + c \sum_j (\mathbf{v}_j - \mathbf{v}_i) W(\mathbf{x}_i - \mathbf{x}_j, h)$$
  7. **Bước 7 - Buffer Swap**:
     Đổi con trỏ double-buffer `posBufPing` $\leftrightarrow$ `posBufPong` và `velBufPing` $\leftrightarrow$ `velBufPong` (Mã máy ARM64 tại `0x60444`).

### Phân hệ 4: Quản lý biến thể Shader AUSL (`AGFX_KeywordProgramManager`)
- **Tệp**: `AGFX_KeywordProgramManager.h/cpp`
- **Mã nguồn gốc**: `AUSL/KeywordProgramManager.cpp`, `GlobalKeywordSet.cpp`, `LocalKeywordSet.cpp`
- **Cơ chế Bitset 64-bit động**:
  - Nhận diện từ khóa bằng ID số nguyên không âm $0, 1, 2, \dots$
  - Phép định vị bit trong mảng 64-bit:
    - Chỉ mục từ (Word index): $\text{word} = \text{id} \gg 6$ (Tương ứng lệnh ARM64 `lsr x8, x20, #6` tại `0x63960`)
    - Chỉ mục bit (Bit index): $\text{bit} = \text{id} \& 63$
    - Mặt nạ bit: $\text{mask} = 1 \text{ULL} \ll \text{bit}$
  - Hỗ trợ phép gộp tập hợp (Union `|`), giao tập hợp (Intersection `&`), băm FNV-1a để tra cứu nhanh bản thể Pipeline đã biên dịch mà không cần liên kết lại (re-link) OpenGL program.

### Phân hệ 5: Tiện ích Nén ASTC và GPU Compute Utilities (`AGFX_Utils`)
- **Tệp**: `AGFX_Utils.h/cpp`
- **Mã máy nguồn**: `0x320b8` - `0x322d0`
- **Kiểm tra định dạng nén ASTC**:
  ```cpp
  bool isASTCCompressionFormat(const AMGPixelFormat& format) {
      uint32_t val = (uint32_t)format - 0x00A4;
      return val < 0x1C; // Đúng 100% mã máy: sub w8, w8, #0xa4; cmp w8, #0x1c; cset w0, lo
  }
  ```
- **Kích thước khối nén ASTC**: Hỗ trợ đầy đủ 14 phân hạng kích thước khối: $4\times 4, 5\times 4, 5\times 5, 6\times 5, 6\times 6, 8\times 5, 8\times 6, 8\times 8, 10\times 5, 10\times 6, 10\times 8, 10\times 10, 12\times 10, 12\times 12$. Mỗi khối có kích thước chuẩn $16\text{ bytes}$ ($128\text{ bits}$).
- **Friend Texture**: Cho phép chia sẻ cùng một OpenGL Texture ID giữa ngữ cảnh Render (FBO) và Compute Shader mà không tốn chi phí copy bộ nhớ (Zero-Copy Interop).

---

## 4. BẢNG TRA CỨU ĐỊA CHỈ DISASSEMBLY & CẤU TRÚC BỘ NHỚ

| Biểu thức / Trường Dữ Liệu | Offset / Địa Chỉ | Ý Nghĩa Kỹ Thuật |
|---|---|---|
| `Simulator::loadParams` | `0x60054` | Nạp tham số mô phỏng, tính hằng số Poly6 / Spiky |
| `Simulator::buildGridHash` | `0x606e8` | Băm tọa độ ô lưới 3D với 3 số nguyên tố |
| `Simulator::step` | `0x62f6c` | Vòng lặp điều phối chính: Advect $\to$ Hash $\to$ Reorder $\to$ Density $\to$ Velocity $\to$ Swap |
| `Simulator::swap` | `0x60444` | Đảo con trỏ bộ đệm ping-pong vị trí và vận tốc |
| `Simulator::setLim` | `0x60464` | Thiết lập hộp giới hạn vật lý `m_minLim` (`0x1c8`), `m_maxLim` (`0x1d8`) |
| `Simulator::setFaceEclipse` | `0x60480` | Thiết lập ellipsoid va chạm khuôn mặt: tâm (`0x230`), bán trục (`0x240`) |
| `Simulator::setNoseEclipse` | `0x604a4` | Thiết lập ellipsoid va chạm sống mũi: tâm (`0x250`), bán trục (`0x260`) |
| `m_nIterations` | `this + 0x1c4` | Số vòng lặp giải ràng buộc mật độ hạt (mặc định = 4) |
| `m_poly6Const` | `this + 0x1f8` | Hệ số hạt nhân Poly6 $= 315 / (64 \pi h^9)$ |
| `m_spikyConst` | `this + 0x1fc` | Hệ số hạt nhân Spiky $= -45 / (\pi h^6)$ |
| `isASTCCompressionFormat` | `0x320b8` | Kiểm tra định dạng nén texture ASTC |
| `GlobalKeywordSet::enable` | `0x6390c` | Bật bitmask từ khóa shader (dịch bit `>> 6`) |

---

## 5. HƯỚNG DẪN TÍCH HỢP CHO DEV NEXTAI OPENCUT

Các nhà phát triển của dự án `com.nextai.opencut` chỉ cần include tệp tiêu đề tổng thể `AGFX_interface.h` để vận hành trọn vẹn toàn bộ tính năng đồ họa:

```cpp
#include "GIAI-MA/libAGFX/AGFX_interface.h"

using namespace NextAI::OpenCut::AGFX;

void demoRun() {
    // 1. Khởi tạo Engine
    AgfxEngine engine;
    engine.initialize(AmazingEngine::RendererType::GLES31);

    // 2. Thiết lập mô phỏng hạt 3D AR (ví dụ giọt nước trên mặt)
    AmazingEngine::PBFParams params;
    params.numParticles = 4096;
    params.restDensity = 1000.0f;
    params.h = 0.035f;
    params.nIterations = 4;

    AmazingEngine::Vector4f minBox = {-0.5f, -0.5f, -0.5f, 0.0f};
    AmazingEngine::Vector4f maxBox = { 0.5f,  0.5f,  0.5f, 0.0f};
    engine.initParticleSimulation(params, minBox, maxBox);

    // 3. Truyền tọa độ mesh khuôn mặt từ Camera Tracking AR
    engine.setFaceTrackerMesh(
        {0.0f, 0.0f, 0.0f, 0.0f},   // Tâm mặt
        {0.09f, 0.12f, 0.08f, 0.0f}, // Bán trục elip mặt
        {0.0f, 0.0f, 0.02f, 0.0f},   // Tâm mũi
        {0.02f, 0.02f, 0.03f, 0.0f}  // Bán trục elip mũi
    );

    // 4. Vòng lặp kết xuất từng khung hình video
    // engine.updateParticleSimulation(1.0f / 60.0f);
    // engine.processFrame(cameraTexture, 1080, 1920);
}
```

---
*Báo cáo hoàn tất. Toàn bộ mã nguồn C++ tái cấu trúc đã sẵn sàng kiểm thử và biên dịch.*
