project(Okiya)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-Wextra -Wall -g --std=c++11")

set(SRC_FILES src/main.cpp src/Constraint.cpp src/Okiya.cpp src/Tile.cpp src/Board.cpp src/Point.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
#FIND_FILE(SFML_CMAKE_DIR "CMakeModules/FindSFML.cmake")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "CMakeModules/")

#if(SFML_CMAKE_DIR)
#  string(REPLACE "FindSFML.cmake" "" SFML_CMAKE_DIR ${SFML_CMAKE_DIR})
#  set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${SFML_CMAKE_DIR}")
#endif()
FIND_PACKAGE(SFML COMPONENTS system window graphics audio REQUIRED)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
LINK_LIBRARIES(${EXE_NAME} ${SFML_LIBRARIES})

add_executable(Okiya ${SRC_FILES})                                              
