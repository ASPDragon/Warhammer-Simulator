cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Warhammer-Simulator)

file(GLOB SOURCES "src/*.cpp" "src/*hpp")

add_executable(Warhammer-Simulator ${SOURCES})