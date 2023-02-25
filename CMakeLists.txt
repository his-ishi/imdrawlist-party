
cmake_minimum_required(VERSION 2.11...3.25)
project(imdrawlist-party C CXX)

set(CMAKE_CXX_STANDARD 17)

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

#set_target_properties(${PROJECT_NAME} PROPERTIES
#    LINK_FLAGS /SUBSYSTEM:WINDOWS
#    )

target_link_options(${PROJECT_NAME}
    PUBLIC -static
    PUBLIC -mwindows
    )

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBRARIES}
    opengl32
    ${SDL2_LIBRARIES}
    )

