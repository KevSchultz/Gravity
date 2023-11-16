cmake_minimum_required(VERSION 3.0.0)
project(gravity VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(gravity src/main.cpp src/glad.c src/stb_image.cpp)

target_link_libraries(gravity glfw OpenGL::GL)