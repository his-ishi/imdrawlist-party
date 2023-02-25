
cmake_minimum_required(VERSION 2.8)
project(imdrawlist-party C CXX)

set(CMAKE_CXX_STANDARD 11)
#set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

# Dear ImGui
include_directories(imgui)

# Libraries
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${PROJECT_NAME}
    ${OpenCV_INCLUDES}
    ${OpenGL_INCLUDES}
    ${SDL2_INCLUDES}
    )

file(GLOB sources
    *.cpp
    imgui/*.cpp
    )

add_executable(${PROJECT_NAME}
    ${sources}
    )

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBRARIES}
    opengl32
    ${SDL2_LIBRARIES}
    )

