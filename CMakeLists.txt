cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Warhammer-Simulator)

set(PROJECT_SRC
    src/datasheet.hpp
    src/weapon.hpp
    src/dice.hpp
    src/simulate.hpp
    src/main.cpp
    src/datasheet.cpp
    src/weapon.cpp
    src/dice.cpp
    src/simulate.cpp
)

add_executable(Warhammer-Simulator ${PROJECT_SRC})