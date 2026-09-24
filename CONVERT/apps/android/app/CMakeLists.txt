cmake_minimum_required(VERSION 3.22.1)

project("nextai_opencut_engine")

# Set C++20 Standard / Thiết lập tiêu chuẩn C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include C++ Headers / Khai báo thư mục Header
include_directories(src/main/cpp/include)

# Add Native Engine Library / Thêm thư viện Native Engine C++
add_library(
    middle_bridge
    SHARED
    src/main/cpp/native-lib.cpp
    src/main/cpp/middle_bridge.cpp
    src/main/cpp/audio_dsp.cpp
    src/main/cpp/face_mesh_engine.cpp
    src/main/cpp/body_segmentation_engine.cpp
    src/main/cpp/shader_pack.cpp
    src/main/cpp/sticker_text_engine.cpp
    src/main/cpp/ffmpeg_render_pipeline.cpp
)

# Link Libraries / Liên kết thư viện hệ thống
find_library(log-lib log)
find_library(android-lib android)
find_library(jnigraphics-lib jnigraphics)

target_link_libraries(
    middle_bridge
    ${log-lib}
    ${android-lib}
    ${jnigraphics-lib}
)
