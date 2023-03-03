cmake_minimum_required(VERSION 3.0)

project(a1)
set(CMAKE_CXX_STANDARD 11)

find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

add_library(viewer src/hw.cpp src/viewer.cpp src/Vertex.cpp src/HalfEdge.cpp src/Face.cpp src/Mesh.cpp )
target_link_libraries(viewer GLEW::GLEW glm::glm OpenGL::GL SDL2::SDL2)

add_executable(example src/example.cpp)
target_link_libraries(example viewer)


add_executable(main src/main.cpp)
target_link_libraries(main viewer)
