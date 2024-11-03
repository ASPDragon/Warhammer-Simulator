cmake_minimum_required(VERSION 3.29.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Warhammer-Simulator)

# add_compile_options("-###")
add_compile_options("-v")

set(PROJECT_SRC
    src/datasheet.hpp
    src/unit.hpp
    src/weapon.hpp
    src/player.hpp
    src/dice.hpp
    src/battle_round.hpp
    src/model.hpp
    src/main.cpp
    src/datasheet.cpp
    src/unit.cpp
    src/weapon.cpp
    src/player.cpp
    src/dice.cpp
    src/battle_round.cpp
    src/model.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})