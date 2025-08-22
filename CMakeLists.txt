cmake_minimum_required(VERSION 3.29.0)

project(Warhammer-Simulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

# add_compile_options("-###")
add_compile_options("-v")

set(PROJECT_SRC
    src/tests/model_mock.hpp
    src/tests/unit_tests_unit.hpp
    src/tests/unit_tests_fight_phase.hpp
    src/battle_round.hpp
    src/vector.hpp
    src/datasheet.hpp
    src/dice.hpp
    src/fight_phase.hpp
    src/model.hpp
    src/player.hpp
    src/unit.hpp
    src/utils.hpp
    src/weapon.hpp
    src/main.cpp
    src/battle_round.cpp
    src/datasheet.cpp
    src/dice.cpp
    src/fight_phase.cpp
    src/model.cpp
    src/player.cpp
    src/unit.cpp
    src/utils.cpp
    src/weapon.cpp
    src/vector.cpp
    src/action.hpp
        src/game_state.hpp
        src/pile_in.cpp
        src/pile_in.hpp
        src/game_state.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_link_libraries(${PROJECT_NAME}
        GTest::gtest GTest::gtest_main
        )

enable_testing()