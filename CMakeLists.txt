cmake_minimum_required(VERSION 3.10)
project(LinearAlgebraFramework)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files for the library
set(SOURCES
    RowTransform.cpp
    matrix.cpp
    matrixui.cpp
)

# Specify the header files (optional, but good for IDEs)
set(HEADERS
    RowTransform.h
    matrix.h
    matrixui.h
)

# Create a library from the source files
add_library(LinearAlgebraFramework STATIC ${SOURCES} ${HEADERS})

# Optionally, you can also specify include directories if needed
target_include_directories(LinearAlgebraFramework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})