cmake_minimum_required(VERSION 3.10)
project(MatrixFunctions)

add_library(matrix-functions-lib STATIC src/matrix.cpp)
target_include_directories(matrix-functions-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
