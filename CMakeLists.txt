cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Warhammer-Simulator)

add_compile_options("-###")
add_compile_options("-v")

set(PROJECT_SRC
    src/datasheet.hpp
    src/unit.hpp
    src/weapon.hpp
    src/dice.hpp
    src/simulate.hpp
    src/model.hpp
    src/main.cpp
    src/datasheet.cpp
    src/unit.cpp
    src/weapon.cpp
    src/dice.cpp
    src/simulate.cpp
    src/model.cpp
)

add_executable(Warhammer-Simulator ${PROJECT_SRC})