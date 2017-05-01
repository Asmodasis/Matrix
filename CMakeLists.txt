cmake_minimum_required(VERSION 3.7)
project(Proj3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Matrix.cpp Matrix.h matrix_math.cpp.cpp)
add_executable(Proj3 ${SOURCE_FILES} Matrix.cpp Matrix.h matrix_math.cpp.cpp)