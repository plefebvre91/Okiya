project(Okiya)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-Wextra -Wall -O3 --std=c++11")

set(SRC_FILES src/main.cpp src/Constraint.cpp src/Okiya.cpp src/Tile.cpp src/Board.cpp src/Point.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Okiya ${SRC_FILES})                                              
