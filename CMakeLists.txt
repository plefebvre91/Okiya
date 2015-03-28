project(Okiya)
cmake_minimum_required(VERSION 2.8)

set(SRC_FILES src/main.cpp src/Constraint.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Okiya ${SRC_FILES})                                              
