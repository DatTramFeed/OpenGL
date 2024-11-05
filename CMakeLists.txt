cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(OpenGL_Project main.cpp)

target_link_libraries(OpenGL_Project OpenGL::GL GLM::glm GLEW::GLEW glfw)
